
#include "../include/scenario.h"
#include "../include/Picture.h"
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"

#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

extern "C" {
int __cdecl sprintf(char* buffer, const char* format, ...);
int __cdecl _open(const char* filename, int oflag, ...);
int __cdecl _write(int fd, const void* buffer, unsigned int count);
int __cdecl _close(int fd);
int __cdecl lseek(int fd, long offset, int origin);
long __cdecl _tell(int fd);
int __cdecl read(int fd, void* buffer, unsigned int count);
int __cdecl close(int fd);
int __cdecl strcmp(const char* left, const char* right);
char* __cdecl strcpy(char* destination, const char* source);
}

void __cdecl rge_read_uncompressed(int fd, void* buffer, int count);
void __cdecl rge_write_uncompressed(int fd, void* buffer, int count);
void __cdecl rge_read(int fd, void* buffer, int count);
void __cdecl rge_write(int fd, void* buffer, int count);
void __cdecl getstring(char** destination, char* source);
void __cdecl addstring(char** destination, char* old_text, char* append);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* block);
RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario* scenario_info) {
    this->error_code = 0;
    this->version = 2;
    this->checksum = time(0);

    int desc_size;
    if (scenario_info->Get_description()) {
        char* description_text = scenario_info->Get_description();
        desc_size = strlen(description_text) + 1;
        this->description = (char*)malloc(desc_size);
    } else {
        this->description = 0;
    }

    if (this->description) {
        char* description_source = scenario_info->Get_description();
        strcpy(this->description, description_source);
        this->description[desc_size - 1] = 0;
    }
}

RGE_Scenario_Header::RGE_Scenario_Header(int infile) {
    int header_size;
    int desc_size;

    error_code = 0;
    version = 0;
    checksum = 0;
    description = 0;
    rge_read_uncompressed(infile, &header_size, 4);
    rge_read_uncompressed(infile, &version, 4);

    if (version >= 2) {
        rge_read_uncompressed(infile, &checksum, 4);
    }

    rge_read_uncompressed(infile, &desc_size, 4);
    if (desc_size > 0) {
        description = (char*)malloc(desc_size);
        if (description == 0) {
            error_code = 1;
            return;
        }
        rge_read_uncompressed(infile, description, desc_size);
    } else {
        description = 0;
    }
}

RGE_Scenario_Header::~RGE_Scenario_Header() {
    if (this->description != 0) {
        free(this->description);
        this->description = 0;
    }
}

long RGE_Scenario_Header::get_size() {
    unsigned int description_size;

    if (this->description != 0) {
        description_size = strlen(this->description) + 1;
    } else {
        description_size = 0;
    }
    return description_size + 0x0C;
}

void RGE_Scenario_Header::save(int outfile) {
    int header_size;
    int desc_size;

    header_size = this->get_size();
    rge_write_uncompressed(outfile, &header_size, 4);
    rge_write_uncompressed(outfile, &this->version, 4);
    if (this->version >= 2) {
        rge_write_uncompressed(outfile, &this->checksum, 4);
    }

    if (this->description != 0) {
        desc_size = strlen(this->description) + 1;
    } else {
        desc_size = 0;
    }
    rge_write_uncompressed(outfile, &desc_size, 4);
    if (this->description != 0) {
        rge_write_uncompressed(outfile, this->description, desc_size);
    }
}

RGE_Scenario::RGE_Scenario(RGE_Game_World* w) {
    this->world = w;
    this->time_line = new RGE_Timeline(this->world);
    this->InitializeTextValues();
    this->mission_picture = 0;
    this->victory_conquest = 1;
    memset(this->player_name, 0, sizeof(this->player_name));
}

RGE_Scenario::RGE_Scenario(int infile, RGE_Game_World* w) {
    short length;
    char text[0xE4];

    this->world = w;
    InitializeTextValues();

    rge_read(infile, &this->Version, 4);

    if (this->Version > 1.13f) {
        for (int player_index = 0; player_index < 16; player_index++)
            rge_read(infile, this->player_name[player_index], 0x100);
    }
    if (this->Version > 1.13) {
        for (int player_index = 0; player_index < 16; player_index++) {
            rge_read(infile, &this->PlActive[player_index], 4);
            rge_read(infile, &this->PlType[player_index], 4);
            rge_read(infile, &this->PlCivilization[player_index], 4);
            rge_read(infile, &this->PlayerPosture[player_index], 4);
        }
    }

    if (this->Version >= 1.07) {
        rge_read(infile, &this->victory_conquest, 1);
    } else {
        this->victory_conquest = 1;
    }

    this->time_line = new RGE_Timeline(infile, this->world);

    rge_read(infile, &length, 2);
    if (length > 0) rge_read(infile, this->scenario_name, length);
    this->scenario_name[length] = 0;
    rge_read(infile, &length, 2);
    if (length > 0) {
        this->description = (char*)calloc(length, 1);
        rge_read(infile, this->description, length);
        this->description[length - 1] = 0;
    } else {
        this->description = 0;
    }

    if (this->Version >= 1.11) {
        rge_read(infile, &length, 2);
        if (length > 0) {
            this->hints = (char*)calloc(length, 1);
            rge_read(infile, this->hints, length);
            this->hints[length - 1] = 0;
        } else {
            this->hints = 0;
        }
        rge_read(infile, &length, 2);
        if (length > 0) {
            this->win_message = (char*)calloc(length, 1);
            rge_read(infile, this->win_message, length);
            this->win_message[length - 1] = 0;
        } else {
            this->win_message = 0;
        }
        rge_read(infile, &length, 2);
        if (length > 0) {
            this->loss_message = (char*)calloc(length, 1);
            rge_read(infile, this->loss_message, length);
            this->loss_message[length - 1] = 0;
        } else {
            this->loss_message = 0;
        }
        rge_read(infile, &length, 2);
        if (length > 0) {
            this->historicle_notes = (char*)calloc(length, 1);
            rge_read(infile, this->historicle_notes, length);
        } else {
            this->historicle_notes = 0;
        }
    } else {
        this->hints = 0;
        this->win_message = 0;
        this->loss_message = 0;
        this->historicle_notes = 0;
    }

    if (this->Version < 1.03f) {
        rge_read(infile, &length, 2);
        if (length > 0) rge_read(infile, text + 4, length);
        rge_read(infile, &length, 2);
        if (length > 0) rge_read(infile, text + 4, length);
        rge_read(infile, &length, 2);
        if (length > 0) rge_read(infile, text + 4, length);
    }

    rge_read(infile, &length, 2);
    if (length > 0) rge_read(infile, this->Cine_PreGame, length);
    this->Cine_PreGame[length] = 0;

    rge_read(infile, &length, 2);
    if (length > 0) rge_read(infile, this->Cine_Victory, length);
    this->Cine_Victory[length] = 0;

    rge_read(infile, &length, 2);
    if (length > 0) rge_read(infile, this->Cine_Loss, length);
    this->Cine_Loss[length] = 0;

    if (this->Version >= 1.09) {
        rge_read(infile, &length, 2);
        if (length > 0) rge_read(infile, this->Mission_Bmp, length);
        this->Mission_Bmp[length] = 0;
    }

    if (this->Version >= 1.1) {
        this->mission_picture = new TPicture(infile, 1);
    } else {
        this->mission_picture = 0;
    }

    for (int player_index = 0; player_index < 16; player_index++) {
        rge_read(infile, &length, 2);
        if (length > 0) rge_read(infile, this->BuildList[player_index], length);
        this->BuildList[player_index][length] = 0;
    }
    for (int player_index = 0; player_index < 16; player_index++) {
        rge_read(infile, &length, 2);
        if (length > 0) rge_read(infile, this->CityPlan[player_index], length);
        this->CityPlan[player_index][length] = 0;
    }
    if (this->Version >= 1.08) {
        for (int player_index = 0; player_index < 16; player_index++) {
            rge_read(infile, &length, 2);
            if (length > 0) rge_read(infile, this->AiRules[player_index], length);
            this->AiRules[player_index][length] = 0;
        }
    }

    for (int player_index = 0; player_index < 16; player_index++) {
        rge_read(infile, &this->BuildListFileSize[player_index], 4);
        rge_read(infile, &this->CityPlanFileSize[player_index], 4);
        if (this->Version >= 1.08)
            rge_read(infile, &this->AiRulesFileSize[player_index], 4);
        this->BuildListFile[player_index] = 0;
        this->CityPlanFile[player_index] = 0;
        this->AiRulesFile[player_index] = 0;
        if (this->Version >= 1.15f) {
            if (this->BuildListFileSize[player_index] > 0) {
                this->BuildListFile[player_index] = (unsigned char*)calloc(this->BuildListFileSize[player_index], 1);
                rge_read(infile, this->BuildListFile[player_index], this->BuildListFileSize[player_index]);
            }
            if (this->CityPlanFileSize[player_index] > 0) {
                this->CityPlanFile[player_index] = (unsigned char*)calloc(this->CityPlanFileSize[player_index], 1);
                rge_read(infile, this->CityPlanFile[player_index], this->CityPlanFileSize[player_index]);
            }
            if (this->AiRulesFileSize[player_index] > 0) {
                this->AiRulesFile[player_index] = (unsigned char*)calloc(this->AiRulesFileSize[player_index], 1);
                rge_read(infile, this->AiRulesFile[player_index], this->AiRulesFileSize[player_index]);
            }
        }
    }

    *(int*)text = 0;
    if (this->Version > 1.02f)
        rge_read(infile, text, 4);
}

RGE_Scenario::~RGE_Scenario() {
    if (this->time_line != 0) {
        delete this->time_line;
        this->time_line = 0;
    }

    if (this->description != 0) free(this->description);
    if (this->hints != 0) free(this->hints);
    if (this->win_message != 0) free(this->win_message);
    if (this->loss_message != 0) free(this->loss_message);
    if (this->historicle_notes != 0) free(this->historicle_notes);

    operator delete(this->scenario_name);

    TPicture* picture = this->mission_picture;
    if (picture != 0) {
        picture->~TPicture();
        operator delete(picture);
        this->mission_picture = 0;
    }

    char** slot = (char**)((char*)this + 0x1308);
    int remaining = 16;
    do {
        operator delete(slot[-16]);
        operator delete(slot[0]);
        operator delete(slot[16]);
        if (slot[32] != 0) free(slot[32]);
        if (slot[48] != 0) free(slot[48]);
        if (slot[64] != 0) free(slot[64]);
        slot++;
    } while (--remaining != 0);
}

void RGE_Scenario::InitializeTextValues() {
    char none_string[30];
    char pad1[2];
    char default_string[30];
    char pad2[2];

    rge_base_game->get_string(IDS_FILE_NONE, none_string, 30);
    rge_base_game->get_string(IDS_AI_FILE_RANDOM, default_string, 30);

    this->description = 0;
    this->hints = 0;
    this->win_message = 0;
    this->loss_message = 0;
    this->historicle_notes = 0;

    this->scenario_name = (char*)operator new(0xE0);
    memset(this->scenario_name, 0, 0xE0);

    strcpy(this->Cine_PreGame, none_string);
    strcpy(this->Cine_Victory, none_string);
    strcpy(this->Cine_Loss, none_string);
    strcpy(this->Mission_Bmp, none_string);

    int count = 16;
    for (int player_index = 0; player_index < 16; player_index++) {
        this->PlayerPosture[player_index] = 0;
        this->PlType[player_index] = 0;
        this->PlCivilization[player_index] = 0;
        this->PlActive[player_index] = 0;
        this->player_name[player_index][0] = 0;

        this->BuildList[player_index] = (char*)operator new(0xE0);
        memset(this->BuildList[player_index], 0, 0xE0);
        strcpy(this->BuildList[player_index], default_string);

        this->CityPlan[player_index] = (char*)operator new(0xE0);
        memset(this->CityPlan[player_index], 0, 0xE0);
        strcpy(this->CityPlan[player_index], none_string);

        this->AiRules[player_index] = (char*)operator new(0xE0);
        memset(this->AiRules[player_index], 0, 0xE0);
        strcpy(this->AiRules[player_index], default_string);

        this->BuildListFile[player_index] = 0;
        this->CityPlanFile[player_index] = 0;
        this->AiRulesFile[player_index] = 0;
        this->BuildListFileSize[player_index] = 0;
        this->CityPlanFileSize[player_index] = 0;
        this->AiRulesFileSize[player_index] = 0;
        count--;
    }
}

void RGE_Scenario::Set_scenario_name(char* str) {
    if (str != 0) {
        strcpy(this->scenario_name, str);
        return;
    }

    this->scenario_name[0] = 0;
}

void RGE_Scenario::Set_description(char* str) { this->Set_message(str, 0); }

void RGE_Scenario::Set_Cine_PreGame(char* str) {
    if (str != 0) {
        strcpy(this->Cine_PreGame, str);
    } else {
        this->Cine_PreGame[0] = 0;
    }
}

void RGE_Scenario::Set_Cine_Victory(char* str) {
    if (str != 0) {
        strcpy(this->Cine_Victory, str);
        return;
    }

    this->Cine_Victory[0] = 0;
}

void RGE_Scenario::Set_Cine_Loss(char* str) {
    if (str != 0) {
        strcpy(this->Cine_Loss, str);
    } else {
        this->Cine_Loss[0] = 0;
    }
}

void RGE_Scenario::Set_Mission_Bmp(char* str) {
    if (str != 0) {
        strcpy(this->Mission_Bmp, str);
        return;
    }

    this->Mission_Bmp[0] = 0;
}

void RGE_Scenario::Set_BuildList(int which_player, char* str, int WithExtension) {
    char** slot;

    if (str) {
        slot = &this->BuildList[which_player];
        strcpy(*slot, str);
    } else {
        slot = &this->BuildList[which_player];
        (*slot)[0] = 0;
    }

    if (WithExtension == 1) {
        (*slot)[strlen(str) - 4] = 0;
    }
}

void RGE_Scenario::Set_CityPlan(int which_player, char* str, int WithExtension) {
    if (str != 0) {
        strcpy(CityPlan[which_player], str);
    } else {
        *CityPlan[which_player] = '\0';
    }

    if (WithExtension == 1) {
        int length = strlen(str);
        CityPlan[which_player][length - 4] = '\0';
    }
}

void RGE_Scenario::Set_player_AI(int which_player, char* str, int WithExtension) {
    if (str != 0) {
        strcpy(AiRules[which_player], str);
    } else {
        *AiRules[which_player] = '\0';
    }

    if (WithExtension == 1) {
        int length = strlen(str);
        AiRules[which_player][length - 4] = '\0';
    }
}

void RGE_Scenario::Set_Version(float ver) { this->Version = ver; }

void RGE_Scenario::Set_player_Type(int which, int t) {
    if (which < 0 || which >= 16) return;
    this->PlType[which] = t;
}

void RGE_Scenario::Set_player_Civ(int which, int c) {
    if (which < 0 || which >= 16) return;
    this->PlCivilization[which] = c;
}

void RGE_Scenario::Set_player_Active(int which, int val) {
    if (which < 0 || which >= 16) return;
    this->PlActive[which] = val;
}

void RGE_Scenario::SetPlayerName(int which, char* Name) {
    memcpy(this->player_name[which], Name, strlen(Name) + 1);
}

char* RGE_Scenario::Get_scenario_name() { return this->scenario_name; }

char* RGE_Scenario::Get_description() { return this->description; }

char* RGE_Scenario::Get_Cine_PreGame() { return this->Cine_PreGame; }

char* RGE_Scenario::Get_Cine_Victory() { return this->Cine_Victory; }

char* RGE_Scenario::Get_Cine_Loss() { return this->Cine_Loss; }

char* RGE_Scenario::Get_Mission_Bmp() { return this->Mission_Bmp; }

char* RGE_Scenario::Get_BuildList(int which_player, int WithExtension) {
    char random_str[50];
    char pad1[2];
    char none_str[50];
    char pad2[2];
    char temp_path[MAX_PATH];
    int fd = -1;

    rge_base_game->get_string(IDS_AI_FILE_RANDOM, random_str, 50);
    rge_base_game->get_string(IDS_FILE_NONE, none_str, 50);
    if (GetTempPathA(MAX_PATH, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (WithExtension == 1 && this->BuildListFileSize[which_player] > 0 && this->BuildListFile[which_player] != 0) {
        sprintf(this->TempText1, "%stemp_buildlist%d.tmp", temp_path, which_player);
        fd = _open((char*)this->TempText1, _O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY, _S_IREAD | _S_IWRITE);
    }

    if (fd != -1) {
        _write(fd, this->BuildListFile[which_player], this->BuildListFileSize[which_player]);
        _close(fd);
        return (char*)this->TempText1;
    }

    if (WithExtension == 1) {
        char* name = this->BuildList[which_player];
        if (strcmp(name, none_str) != 0) {
            if (strcmp(name, random_str) != 0) {
                sprintf(this->TempText1, "%s%s.ai", rge_base_game->prog_info->ai_dir, name);
                return this->TempText1;
            }
        }
    }

    sprintf(this->TempText1, "%s", this->BuildList[which_player]);
    return this->TempText1;
}

char* RGE_Scenario::Get_CityPlan(int which_player, int WithExtension) {
    char random_str[50];
    char pad1[2];
    char none_str[50];
    char pad2[2];
    char temp_path[MAX_PATH];
    int fd = -1;

    rge_base_game->get_string(IDS_AI_FILE_RANDOM, random_str, 50);
    rge_base_game->get_string(IDS_FILE_NONE, none_str, 50);
    if (GetTempPathA(MAX_PATH, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (WithExtension == 1 && this->CityPlanFileSize[which_player] > 0 && this->CityPlanFile[which_player] != 0) {
        sprintf(this->TempText2, "%stemp_CityPlan%d.tmp", temp_path, which_player);
        fd = _open((char*)this->TempText2, _O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY, _S_IREAD | _S_IWRITE);
    }

    if (fd != -1) {
        _write(fd, this->CityPlanFile[which_player], this->CityPlanFileSize[which_player]);
        _close(fd);
        return (char*)this->TempText2;
    }

    if (WithExtension == 1) {
        char* name = this->BuildList[which_player];
        if (strcmp(name, none_str) != 0) {
            if (strcmp(name, random_str) != 0) {
                sprintf(this->TempText2, "%s%s.cty", rge_base_game->prog_info->ai_dir, this->CityPlan[which_player]);
                return this->TempText2;
            }
        }
    }

    sprintf(this->TempText2, "%s", this->CityPlan[which_player]);
    return this->TempText2;
}

float RGE_Scenario::Get_Version() {
    return DAT_00572178;
}

char* RGE_Scenario::Get_player_AI(int which_player, int WithExtension) {
    char random_str[0x32];
    char none_str[0x32];
    char temp_path[MAX_PATH];
    int fd;

    fd = -1;
    rge_base_game->get_string(IDS_AI_FILE_RANDOM, random_str, 0x32);
    rge_base_game->get_string(IDS_FILE_NONE, none_str, 0x32);

    if (GetTempPathA(MAX_PATH, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (WithExtension == 1 && this->AiRulesFileSize[which_player] > 0 && this->AiRulesFile[which_player] != 0) {
        sprintf(this->TempText3, "%stemp_AiRules%d.tmp", temp_path, which_player);
        fd = _open(this->TempText3, _O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY, _S_IREAD | _S_IWRITE);
    }

    if (fd != -1) {
        _write(fd, this->AiRulesFile[which_player], this->AiRulesFileSize[which_player]);
        _close(fd);
        return this->TempText3;
    }

    if (WithExtension == 1) {
        if (strcmp(this->BuildList[which_player], none_str) != 0 &&
            strcmp(this->BuildList[which_player], random_str) != 0) {
            sprintf(this->TempText3, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[which_player]);
            return this->TempText3;
        }
    }

    sprintf(this->TempText3, "%s", this->AiRules[which_player]);
    return this->TempText3;
}

int RGE_Scenario::GetPlayerPosture(int which) {
    if (which < 0) {
        return 0;
    }
    if (which >= 9) {
        return 0;
    }

    switch (this->PlayerPosture[which]) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    }

    return 0;
}

char *RGE_Scenario::GetPlayerName(int which) {
    return &this->player_name[which][0];
}

int RGE_Scenario::Get_player_Type(int which) {
    if (which < 0 || which >= 16) return 0;
    return this->PlType[which];
}

int RGE_Scenario::Get_player_Civ(int which) {
    if (which < 0 || which >= 16) return 0;
    return this->PlCivilization[which];
}

int RGE_Scenario::Get_player_Active(int which) {
    if (which < 0 || which >= 16) return 0;
    return this->PlActive[which];
}

void RGE_Scenario::update() {
    if (this->time_line)
        this->time_line->update();
}

void RGE_Scenario::save(int outfile) {
    float* version;
    char temp_file_name[224];
    char file_name[224];
    short length;
    int fd;
    TPicture* new_picture;
    TPicture* old_picture;
    int end_marker;

    version = &this->Version;

    this->Version = this->Get_Version();
    rge_write(outfile, version, 4);

    for (int player_index = 0; player_index < 16; player_index++)
        rge_write(outfile, this->player_name[player_index], 0x100);

    for (int player_index = 0; player_index < 16; player_index++) {
        rge_write(outfile, &this->PlActive[player_index], 4);
        rge_write(outfile, &this->PlType[player_index], 4);
        rge_write(outfile, &this->PlCivilization[player_index], 4);
        rge_write(outfile, &this->PlayerPosture[player_index], 4);
    }

    rge_write(outfile, &this->victory_conquest, 1);

    if (this->time_line != 0)
        this->time_line->save(outfile);

    if (this->scenario_name != 0)
        length = (short)strlen(this->scenario_name);
    else
        length = 0;
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->scenario_name, length);

    if (this->description != 0)
        length = (short)(strlen(this->description) + 1);
    else
        length = 0;
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->description, length);

    if (this->hints != 0)
        length = (short)(strlen(this->hints) + 1);
    else
        length = 0;
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->hints, length);

    if (this->win_message != 0)
        length = (short)(strlen(this->win_message) + 1);
    else
        length = 0;
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->win_message, length);

    if (this->loss_message != 0)
        length = (short)(strlen(this->loss_message) + 1);
    else
        length = 0;
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->loss_message, length);

    if (this->historicle_notes != 0)
        length = (short)(strlen(this->historicle_notes) + 1);
    else
        length = 0;
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->historicle_notes, length);

    length = (short)strlen(this->Cine_PreGame);
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->Cine_PreGame, length);

    length = (short)strlen(this->Cine_Victory);
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->Cine_Victory, length);

    length = (short)strlen(this->Cine_Loss);
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->Cine_Loss, length);

    length = (short)strlen(this->Mission_Bmp);
    rge_write(outfile, &length, 2);
    if (length > 0)
        rge_write(outfile, this->Mission_Bmp, length);

    sprintf(file_name, "%s.bmp", this->Mission_Bmp);

    new_picture = new TPicture(file_name, -1, 0, 0, 0);
    old_picture = this->mission_picture;
    if (old_picture != 0) {
        if (new_picture->Dib == 0) {
            if (new_picture != 0) {
                delete new_picture;
            }
            goto skip_store;
        }
    }
    if (old_picture != 0) {
        delete old_picture;
    }
    this->mission_picture = new_picture;
skip_store:
    this->mission_picture->Save(outfile);

    for (int player_index = 0; player_index < 16; player_index++) {
        length = (short)strlen(this->BuildList[player_index]);
        rge_write(outfile, &length, 2);
        if (length > 0)
            rge_write(outfile, this->BuildList[player_index], length);
    }

    for (int player_index = 0; player_index < 16; player_index++) {
        length = (short)strlen(this->CityPlan[player_index]);
        rge_write(outfile, &length, 2);
        if (length > 0)
            rge_write(outfile, this->CityPlan[player_index], length);
    }

    if (*version >= 1.08) {
        for (int player_index = 0; player_index < 16; player_index++) {
            length = (short)strlen(this->AiRules[player_index]);
            rge_write(outfile, &length, 2);
            if (length > 0)
                rge_write(outfile, this->AiRules[player_index], length);
        }
    }

    for (int player_index = 0; player_index < 16; player_index++) {
        if (this->BuildList[player_index] != 0) {
            sprintf(temp_file_name, "%s%s.ai", rge_base_game->prog_info->ai_dir, this->BuildList[player_index]);
            fd = _open(temp_file_name, _O_BINARY);
            if (fd > -1) {
                lseek(fd, 0, SEEK_END);
                this->BuildListFileSize[player_index] = _tell(fd);
                if (this->BuildListFile[player_index] != 0) free(this->BuildListFile[player_index]);
                this->BuildListFile[player_index] = (unsigned char*)calloc(this->BuildListFileSize[player_index], 1);
                lseek(fd, 0, SEEK_SET);
                read(fd, this->BuildListFile[player_index], this->BuildListFileSize[player_index]);
                close(fd);
            }
        }
        if (this->CityPlan[player_index] != 0) {
            sprintf(temp_file_name, "%s%s.cty", rge_base_game->prog_info->ai_dir, this->CityPlan[player_index]);
            fd = _open(temp_file_name, _O_BINARY);
            if (fd > -1) {
                lseek(fd, 0, SEEK_END);
                this->CityPlanFileSize[player_index] = _tell(fd);
                if (this->CityPlanFile[player_index] != 0) free(this->CityPlanFile[player_index]);
                this->CityPlanFile[player_index] = (unsigned char*)calloc(this->CityPlanFileSize[player_index], 1);
                lseek(fd, 0, SEEK_SET);
                read(fd, this->CityPlanFile[player_index], this->CityPlanFileSize[player_index]);
                close(fd);
            }
        }
        if (this->AiRules[player_index] != 0) {
            sprintf(temp_file_name, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[player_index]);
            fd = _open(temp_file_name, _O_BINARY);
            if (fd > -1) {
                lseek(fd, 0, SEEK_END);
                this->AiRulesFileSize[player_index] = _tell(fd);
                if (this->AiRulesFile[player_index] != 0) free(this->AiRulesFile[player_index]);
                this->AiRulesFile[player_index] = (unsigned char*)calloc(this->AiRulesFileSize[player_index], 1);
                lseek(fd, 0, SEEK_SET);
                read(fd, this->AiRulesFile[player_index], this->AiRulesFileSize[player_index]);
                close(fd);
            }
        }

        rge_write(outfile, &this->BuildListFileSize[player_index], 4);
        rge_write(outfile, &this->CityPlanFileSize[player_index], 4);
        if (*version >= 1.08)
            rge_write(outfile, &this->AiRulesFileSize[player_index], 4);
        if (this->BuildListFile[player_index] != 0)
            rge_write(outfile, this->BuildListFile[player_index], this->BuildListFileSize[player_index]);
        if (this->CityPlanFile[player_index] != 0)
            rge_write(outfile, this->CityPlanFile[player_index], this->CityPlanFileSize[player_index]);
        if (this->AiRulesFile[player_index] != 0)
            rge_write(outfile, this->AiRulesFile[player_index], this->AiRulesFileSize[player_index]);
    }

    end_marker = -99;
    rge_write(outfile, &end_marker, 4);
}

int RGE_Scenario::active_player_count() {
    int count;
    int player_index;

    count = 0;
    player_index = 0;
    do {
        if (Get_player_Active(player_index) != 0) {
            count = count + 1;
        }
        player_index = player_index + 1;
    } while (player_index < 0x10);
    return count;
}

int RGE_Scenario::any_player_count(void) {
    int count = 0;
    int player_index = 0;

    do {
        if (this->Get_player_Active(player_index) != 0) {
            if (this->Get_player_Type(player_index) == 1) {
                count++;
            }
        }
        player_index++;
    } while (player_index < 0x10);
    return count;
}

int RGE_Scenario::computer_player_count(void) {
    int count = 0;
    int player_index = 0;

    do {
        if (this->Get_player_Active(player_index) != 0) {
            if (this->Get_player_Type(player_index) == 0) {
                count++;
            }
        }
        player_index++;
    } while (player_index < 0x10);
    return count;
}

void RGE_Scenario::Set_conquest_victory(unsigned char flag) { this->victory_conquest = flag; }

unsigned char RGE_Scenario::Get_conquest_victory() { return this->victory_conquest; }

void RGE_Scenario::add_description(char* new_text) {
    if (this->description == 0) {
        getstring(&this->description, new_text);
        return;
    }
    addstring(&this->description, this->description, new_text);
}

void RGE_Scenario::Set_message(char* str, long message) {
    long length;
    char* message_copy;

    if (str == 0) {
        length = 0;
    } else {
        length = strlen(str) + 1;
    }

    if (length > 0) {
        message_copy = (char*)calloc(length, 1);
    } else {
        message_copy = 0;
    }

    memcpy(message_copy, str, length);

    switch (message) {
    case 0:
        if (description != 0) {
            free(description);
        }
        description = message_copy;
        break;
    case 1:
        if (hints != 0) {
            free(hints);
        }
        hints = message_copy;
        break;
    case 2:
        //! @bug When win_message is non-null, replacement leaks the old allocation because the original condition frees only null.
        if (win_message == 0) {
            //! Preserve the original free(0) no-op call.
            free(0);
        }
        win_message = message_copy;
        break;
    case 3:
        if (loss_message != 0) {
            free(loss_message);
        }
        loss_message = message_copy;
        break;
    case 4:
        if (historicle_notes != 0) {
            free(historicle_notes);
        }
        historicle_notes = message_copy;
        break;
    default:
        if (message_copy != 0) {
            free(message_copy);
        }
        break;
    }
}

char* RGE_Scenario::Get_message(long message) {
    switch (message) {
    case 0:
        return this->description;
    case 1:
        return this->hints;
    case 2:
        return this->win_message;
    case 3:
        return this->loss_message;
    case 4:
        return this->historicle_notes;
    default:
        return 0;
    }
}
