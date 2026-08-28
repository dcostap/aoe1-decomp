// PDB source module: C:\\msdev\\work\\age1_x1\\scenario.cpp.
// The definitions follow the original source order.

#include "../include/scenario.h"
#include "../include/Picture.h"
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
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
extern float g_version;

// 0048AB10 RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario*)
RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario* scenario) {
    this->error_code = 0;
    this->version = 2;
    this->checksum = time(0);

    int len;
    if (scenario->Get_description()) {
        char* d = scenario->Get_description();
        len = strlen(d) + 1;
        this->description = (char*)malloc(len);
    } else {
        this->description = 0;
    }

    if (this->description) {
        char* d2 = scenario->Get_description();
        strcpy(this->description, d2);
        this->description[len - 1] = 0;
    }
}

// 0048ABB0 RGE_Scenario_Header::RGE_Scenario_Header(int)
RGE_Scenario_Header::RGE_Scenario_Header(int fd) {
    int header_size;
    int desc_size;

    error_code = 0;
    version = 0;
    checksum = 0;
    description = 0;
    rge_read_uncompressed(fd, &header_size, 4);
    rge_read_uncompressed(fd, &version, 4);

    if (version >= 2) {
        rge_read_uncompressed(fd, &checksum, 4);
    }

    rge_read_uncompressed(fd, &desc_size, 4);
    if (desc_size > 0) {
        description = (char*)malloc(desc_size);
        if (description == 0) {
            error_code = 1;
            return;
        }
        rge_read_uncompressed(fd, description, desc_size);
    } else {
        description = 0;
    }
}

// 0048AC70 RGE_Scenario_Header::~RGE_Scenario_Header()
RGE_Scenario_Header::~RGE_Scenario_Header() {
    if (this->description != 0) {
        free(this->description);
        this->description = 0;
    }
}

// 0048ACA0 RGE_Scenario_Header::get_size()
long RGE_Scenario_Header::get_size() {
    unsigned int len;

    if (this->description != 0) {
        len = strlen(this->description) + 1;
    }
    else {
        len = 0;
    }
    return len + 0x0C;
}

// 0048ACC0 RGE_Scenario_Header::save(int)
void RGE_Scenario_Header::save(int fd) {
    int header_size;
    int desc_len;

    header_size = this->get_size();
    rge_write_uncompressed(fd, &header_size, 4);
    rge_write_uncompressed(fd, &this->version, 4);
    if (this->version >= 2) {
        rge_write_uncompressed(fd, &this->checksum, 4);
    }

    if (this->description != 0) {
        desc_len = strlen(this->description) + 1;
    } else {
        desc_len = 0;
    }
    rge_write_uncompressed(fd, &desc_len, 4);
    if (this->description != 0) {
        rge_write_uncompressed(fd, this->description, desc_len);
    }
}

// 0048AD60 RGE_Scenario::RGE_Scenario(RGE_Game_World*)
RGE_Scenario::RGE_Scenario(RGE_Game_World* game_world) {
    this->world = game_world;
    this->time_line = new RGE_Timeline(this->world);
    this->InitializeTextValues();
    this->mission_picture = 0;
    this->victory_conquest = 1;
    memset(this->player_name, 0, sizeof(this->player_name));
}

// 0048AE10 RGE_Scenario::RGE_Scenario(int, RGE_Game_World*)
RGE_Scenario::RGE_Scenario(int file, RGE_Game_World* world)
{
    short length;
    char text[0xE4];

    this->world = world;
    InitializeTextValues();

    rge_read(file, &this->Version, 4);

    if (this->Version > 1.13f) {
        for (int n1 = 0; n1 < 16; n1++)
            rge_read(file, this->player_name[n1], 0x100);
    }
    if (this->Version > 1.13) {
        for (int n2 = 0; n2 < 16; n2++) {
            rge_read(file, &this->PlActive[n2], 4);
            rge_read(file, &this->PlType[n2], 4);
            rge_read(file, &this->PlCivilization[n2], 4);
            rge_read(file, &this->PlayerPosture[n2], 4);
        }
    }

    if (this->Version >= 1.07) {
        rge_read(file, &this->victory_conquest, 1);
    } else {
        this->victory_conquest = 1;
    }

    this->time_line = new RGE_Timeline(file, this->world);

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->scenario_name, length);
    this->scenario_name[length] = 0;
    rge_read(file, &length, 2);
    if (length > 0) {
        this->description = (char*)calloc(length, 1);
        rge_read(file, this->description, length);
        this->description[length - 1] = 0;
    } else {
        this->description = 0;
    }

    if (this->Version >= 1.11) {
        rge_read(file, &length, 2);
        if (length > 0) {
            this->hints = (char*)calloc(length, 1);
            rge_read(file, this->hints, length);
            this->hints[length - 1] = 0;
        } else {
            this->hints = 0;
        }
        rge_read(file, &length, 2);
        if (length > 0) {
            this->win_message = (char*)calloc(length, 1);
            rge_read(file, this->win_message, length);
            this->win_message[length - 1] = 0;
        } else {
            this->win_message = 0;
        }
        rge_read(file, &length, 2);
        if (length > 0) {
            this->loss_message = (char*)calloc(length, 1);
            rge_read(file, this->loss_message, length);
            this->loss_message[length - 1] = 0;
        } else {
            this->loss_message = 0;
        }
        rge_read(file, &length, 2);
        if (length > 0) {
            this->historicle_notes = (char*)calloc(length, 1);
            rge_read(file, this->historicle_notes, length);
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
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, text + 4, length);
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, text + 4, length);
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, text + 4, length);
    }

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->Cine_PreGame, length);
    this->Cine_PreGame[length] = 0;

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->Cine_Victory, length);
    this->Cine_Victory[length] = 0;

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->Cine_Loss, length);
    this->Cine_Loss[length] = 0;

    if (this->Version >= 1.09) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, this->Mission_Bmp, length);
        this->Mission_Bmp[length] = 0;
    }

    if (this->Version >= 1.1) {
        this->mission_picture = new TPicture(file, 1);
    } else {
        this->mission_picture = 0;
    }

    for (int n3 = 0; n3 < 16; n3++) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, this->BuildList[n3], length);
        this->BuildList[n3][length] = 0;
    }
    for (int n4 = 0; n4 < 16; n4++) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, this->CityPlan[n4], length);
        this->CityPlan[n4][length] = 0;
    }
    if (this->Version >= 1.08) {
        for (int n5 = 0; n5 < 16; n5++) {
            rge_read(file, &length, 2);
            if (length > 0) rge_read(file, this->AiRules[n5], length);
            this->AiRules[n5][length] = 0;
        }
    }

    for (int n6 = 0; n6 < 16; n6++) {
        rge_read(file, &this->BuildListFileSize[n6], 4);
        rge_read(file, &this->CityPlanFileSize[n6], 4);
        if (this->Version >= 1.08)
            rge_read(file, &this->AiRulesFileSize[n6], 4);
        this->BuildListFile[n6] = 0;
        this->CityPlanFile[n6] = 0;
        this->AiRulesFile[n6] = 0;
        if (this->Version >= 1.15f) {
            if (this->BuildListFileSize[n6] > 0) {
                this->BuildListFile[n6] = (unsigned char*)calloc(this->BuildListFileSize[n6], 1);
                rge_read(file, this->BuildListFile[n6], this->BuildListFileSize[n6]);
            }
            if (this->CityPlanFileSize[n6] > 0) {
                this->CityPlanFile[n6] = (unsigned char*)calloc(this->CityPlanFileSize[n6], 1);
                rge_read(file, this->CityPlanFile[n6], this->CityPlanFileSize[n6]);
            }
            if (this->AiRulesFileSize[n6] > 0) {
                this->AiRulesFile[n6] = (unsigned char*)calloc(this->AiRulesFileSize[n6], 1);
                rge_read(file, this->AiRulesFile[n6], this->AiRulesFileSize[n6]);
            }
        }
    }

    *(int*)text = 0;
    if (this->Version > 1.02f)
        rge_read(file, text, 4);
}

// 0048B5A0 RGE_Scenario::~RGE_Scenario()
RGE_Scenario::~RGE_Scenario()
{
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

    TPicture* pic = this->mission_picture;
    if (pic != 0) {
        pic->~TPicture();
        operator delete(pic);
        this->mission_picture = 0;
    }

    char** cp = (char**)((char*)this + 0x1308);
    int count = 16;
    do {
        operator delete(cp[-16]);
        operator delete(cp[0]);
        operator delete(cp[16]);
        if (cp[32] != 0) free(cp[32]);
        if (cp[48] != 0) free(cp[48]);
        if (cp[64] != 0) free(cp[64]);
        cp++;
    } while (--count != 0);
}

// 0048B6C0 RGE_Scenario::InitializeTextValues()
void RGE_Scenario::InitializeTextValues()
{
    char none_string[30];
    char pad1[2];
    char default_string[30];
    char pad2[2];

    rge_base_game->get_string(0x2775, none_string, 30);
    rge_base_game->get_string(0x277B, default_string, 30);

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
    for (int i = 0; i < 16; i++) {
        this->PlayerPosture[i] = 0;
        this->PlType[i] = 0;
        this->PlCivilization[i] = 0;
        this->PlActive[i] = 0;
        this->player_name[i][0] = 0;

        this->BuildList[i] = (char*)operator new(0xE0);
        memset(this->BuildList[i], 0, 0xE0);
        strcpy(this->BuildList[i], default_string);

        this->CityPlan[i] = (char*)operator new(0xE0);
        memset(this->CityPlan[i], 0, 0xE0);
        strcpy(this->CityPlan[i], none_string);

        this->AiRules[i] = (char*)operator new(0xE0);
        memset(this->AiRules[i], 0, 0xE0);
        strcpy(this->AiRules[i], default_string);

        this->BuildListFile[i] = 0;
        this->CityPlanFile[i] = 0;
        this->AiRulesFile[i] = 0;
        this->BuildListFileSize[i] = 0;
        this->CityPlanFileSize[i] = 0;
        this->AiRulesFileSize[i] = 0;
        count--;
    }
}

// 0048B910 RGE_Scenario::Set_scenario_name(char*)
void RGE_Scenario::Set_scenario_name(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->scenario_name, param_1);
        return;
    }

    this->scenario_name[0] = 0;
}

// 0048B950 RGE_Scenario::Set_description(char*)
void RGE_Scenario::Set_description(char* text) { this->Set_message(text, 0); }

// 0048B960 RGE_Scenario::Set_Cine_PreGame(char*)
void RGE_Scenario::Set_Cine_PreGame(char* text) {
    if (text != 0) {
        strcpy(this->Cine_PreGame, text);
    } else {
        this->Cine_PreGame[0] = 0;
    }
}

// 0048B9A0 RGE_Scenario::Set_Cine_Victory(char*)
void RGE_Scenario::Set_Cine_Victory(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->Cine_Victory, param_1);
        return;
    }

    this->Cine_Victory[0] = 0;
}

// 0048B9E0 RGE_Scenario::Set_Cine_Loss(char*)
void RGE_Scenario::Set_Cine_Loss(char* text) {
    if (text != 0) {
        strcpy(this->Cine_Loss, text);
    } else {
        this->Cine_Loss[0] = 0;
    }
}

// 0048BA20 RGE_Scenario::Set_Mission_Bmp(char*)
void RGE_Scenario::Set_Mission_Bmp(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->Mission_Bmp, param_1);
        return;
    }

    this->Mission_Bmp[0] = 0;
}

// 0048BA60 RGE_Scenario::Set_BuildList(int, char*, int)
void RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3) {
    char** slot;

    if (param_2) {
        slot = &this->BuildList[param_1];
        strcpy(*slot, param_2);
    } else {
        slot = &this->BuildList[param_1];
        (*slot)[0] = 0;
    }

    if (param_3 == 1) {
        (*slot)[strlen(param_2) - 4] = 0;
    }
}

// 0048BAD0 RGE_Scenario::Set_CityPlan(int, char*, int)
void RGE_Scenario::Set_CityPlan(int index, char* str, int flag) {
    if (str != 0) {
        strcpy(CityPlan[index], str);
    } else {
        *CityPlan[index] = '\0';
    }

    if (flag == 1) {
        int len = strlen(str);
        CityPlan[index][len - 4] = '\0';
    }
}

// 0048BB40 RGE_Scenario::Set_player_AI(int, char*, int)
void RGE_Scenario::Set_player_AI(int index, char* str, int flag) {
    if (str != 0) {
        strcpy(AiRules[index], str);
    } else {
        *AiRules[index] = '\0';
    }

    if (flag == 1) {
        int len = strlen(str);
        AiRules[index][len - 4] = '\0';
    }
}

// 0048BBB0 RGE_Scenario::Set_Version(float)
void RGE_Scenario::Set_Version(float v) { this->Version = v; }

// 0048BBC0 RGE_Scenario::Set_player_Type(int, int)
void RGE_Scenario::Set_player_Type(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->PlType[index] = val;
}

// 0048BBE0 RGE_Scenario::Set_player_Civ(int, int)
void RGE_Scenario::Set_player_Civ(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->PlCivilization[index] = val;
}

// 0048BC00 RGE_Scenario::Set_player_Active(int, int)
void RGE_Scenario::Set_player_Active(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->PlActive[index] = val;
}

// 0048BC20 RGE_Scenario::SetPlayerName(int, char*)
void RGE_Scenario::SetPlayerName(int index, char* name) {
    memcpy(this->player_name[index], name, strlen(name) + 1);
}

// 0048BC60 RGE_Scenario::Get_scenario_name()
char* RGE_Scenario::Get_scenario_name() { return this->scenario_name; }

// 0048BC70 RGE_Scenario::Get_description()
char* RGE_Scenario::Get_description() { return this->description; }

// 0048BC80 RGE_Scenario::Get_Cine_PreGame()
char* RGE_Scenario::Get_Cine_PreGame() { return this->Cine_PreGame; }

// 0048BC90 RGE_Scenario::Get_Cine_Victory()
char* RGE_Scenario::Get_Cine_Victory() { return this->Cine_Victory; }

// 0048BCA0 RGE_Scenario::Get_Cine_Loss()
char* RGE_Scenario::Get_Cine_Loss() { return this->Cine_Loss; }

// 0048BCB0 RGE_Scenario::Get_Mission_Bmp()
char* RGE_Scenario::Get_Mission_Bmp() { return this->Mission_Bmp; }

// 0048BCC0 RGE_Scenario::Get_BuildList(int, int)
char* RGE_Scenario::Get_BuildList(int player, int use_file)
{
    char random_str[50];
    char pad1[2];
    char none_str[50];
    char pad2[2];
    char temp_path[260];
    int fd = -1;

    rge_base_game->get_string(0x277b, random_str, 50);
    rge_base_game->get_string(0x2775, none_str, 50);
    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, (char*)0x00585800);
    }

    if (use_file == 1 && this->BuildListFileSize[player] > 0 && this->BuildListFile[player] != 0) {
        sprintf((char*)this->TempText1, (char*)0x00585FE8, temp_path, player);
        fd = _open((char*)this->TempText1, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->BuildListFile[player], this->BuildListFileSize[player]);
        _close(fd);
        return (char*)this->TempText1;
    }

    if (use_file == 1) {
        char* name = this->BuildList[player];
        if (strcmp(name, none_str) != 0) {
            if (strcmp(name, random_str) != 0) {
                sprintf((char*)this + 0x1028, (char*)0x00585FE0, rge_base_game->prog_info->ai_dir, name);
                return (char*)this + 0x1028;
            }
        }
    }

    sprintf((char*)this + 0x1028, (char*)0x0057F324, this->BuildList[player]);
    return (char*)this + 0x1028;
}

// 0048BEC0 RGE_Scenario::Get_CityPlan(int, int)
char* RGE_Scenario::Get_CityPlan(int player, int use_file)
{
    char random_str[50];
    char pad1[2];
    char none_str[50];
    char pad2[2];
    char temp_path[260];
    int fd = -1;

    rge_base_game->get_string(0x277b, random_str, 50);
    rge_base_game->get_string(0x2775, none_str, 50);
    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, (char*)0x00585800);
    }

    if (use_file == 1 && this->CityPlanFileSize[player] > 0 && this->CityPlanFile[player] != 0) {
        sprintf((char*)this->TempText2, (char*)0x0058600C, temp_path, player);
        fd = _open((char*)this->TempText2, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->CityPlanFile[player], this->CityPlanFileSize[player]);
        _close(fd);
        return (char*)this->TempText2;
    }

    if (use_file == 1) {
        char* name = this->BuildList[player];
        if (strcmp(name, none_str) != 0) {
            if (strcmp(name, random_str) != 0) {
                sprintf((char*)this + 0x1108, (char*)0x00586000, rge_base_game->prog_info->ai_dir, this->CityPlan[player]);
                return (char*)this + 0x1108;
            }
        }
    }

    sprintf((char*)this + 0x1108, (char*)0x0057F324, this->CityPlan[player]);
    return (char*)this + 0x1108;
}

// 0048C0D0 RGE_Scenario::Get_Version()
float RGE_Scenario::Get_Version() {
    return g_version;
}

// 0048C0E0 RGE_Scenario::Get_player_AI(int, int)
char* RGE_Scenario::Get_player_AI(int player, int use_temp_file)
{
    char random_str[0x32];
    char none_str[0x32];
    char temp_path[0x104];
    int fd;

    fd = -1;
    rge_base_game->get_string(0x277b, random_str, 0x32);
    rge_base_game->get_string(0x2775, none_str, 0x32);

    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (use_temp_file == 1 && this->AiRulesFileSize[player] > 0 && this->AiRulesFile[player] != 0) {
        sprintf(this->TempText3, "%stemp_AiRules%d.tmp", temp_path, player);
        fd = _open(this->TempText3, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->AiRulesFile[player], this->AiRulesFileSize[player]);
        _close(fd);
        return this->TempText3;
    }

    if (use_temp_file == 1) {
        if (strcmp(this->BuildList[player], none_str) != 0 &&
            strcmp(this->BuildList[player], random_str) != 0) {
            sprintf(this->TempText3, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[player]);
            return this->TempText3;
        }
    }

    sprintf(this->TempText3, "%s", this->AiRules[player]);
    return this->TempText3;
}

// 0048C2F0 RGE_Scenario::GetPlayerPosture(int)
int RGE_Scenario::GetPlayerPosture(int player) {
    if (player < 0) {
        return 0;
    }
    if (player >= 9) {
        return 0;
    }

    switch (this->PlayerPosture[player]) {
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

// 0048C360 RGE_Scenario::GetPlayerName(int)
char *RGE_Scenario::GetPlayerName(int index) {
    return &this->player_name[index][0];
}

// 0048C370 RGE_Scenario::Get_player_Type(int)
int RGE_Scenario::Get_player_Type(int index) {
    if (index < 0 || index >= 16) return 0;
    return this->PlType[index];
}

// 0048C390 RGE_Scenario::Get_player_Civ(int)
int RGE_Scenario::Get_player_Civ(int index) {
    if (index < 0 || index >= 16) return 0;
    return this->PlCivilization[index];
}

// 0048C3B0 RGE_Scenario::Get_player_Active(int)
int RGE_Scenario::Get_player_Active(int index) {
    if (index < 0 || index >= 16) return 0;
    return this->PlActive[index];
}

// 0048C3D0 RGE_Scenario::update()
void RGE_Scenario::update() {
    if (this->time_line)
        this->time_line->update();
}

// 0048C3E0 RGE_Scenario::save(int)
void RGE_Scenario::save(int file)
{
    float* version;
    char temp_file_name[224];
    char file_name[224];
    short length;
    int fd;
    TPicture* np;
    TPicture* old;
    int end_marker;

    version = &this->Version;

    this->Version = this->Get_Version();
    rge_write(file, version, 4);

    for (int a = 0; a < 16; a++)
        rge_write(file, this->player_name[a], 0x100);

    for (int b = 0; b < 16; b++) {
        rge_write(file, &this->PlActive[b], 4);
        rge_write(file, &this->PlType[b], 4);
        rge_write(file, &this->PlCivilization[b], 4);
        rge_write(file, &this->PlayerPosture[b], 4);
    }

    rge_write(file, &this->victory_conquest, 1);

    if (this->time_line != 0)
        this->time_line->save(file);

    if (this->scenario_name != 0)
        length = (short)strlen(this->scenario_name);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->scenario_name, length);

    if (this->description != 0)
        length = (short)(strlen(this->description) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->description, length);

    if (this->hints != 0)
        length = (short)(strlen(this->hints) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->hints, length);

    if (this->win_message != 0)
        length = (short)(strlen(this->win_message) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->win_message, length);

    if (this->loss_message != 0)
        length = (short)(strlen(this->loss_message) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->loss_message, length);

    if (this->historicle_notes != 0)
        length = (short)(strlen(this->historicle_notes) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->historicle_notes, length);

    length = (short)strlen(this->Cine_PreGame);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Cine_PreGame, length);

    length = (short)strlen(this->Cine_Victory);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Cine_Victory, length);

    length = (short)strlen(this->Cine_Loss);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Cine_Loss, length);

    length = (short)strlen(this->Mission_Bmp);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Mission_Bmp, length);

    sprintf(file_name, "%s.bmp", this->Mission_Bmp);

    np = new TPicture(file_name, -1, 0, 0, 0);
    old = this->mission_picture;
    if (old != 0) {
        if (np->Dib == 0) {
            if (np != 0) {
                delete np;
            }
            goto skip_store;
        }
    }
    if (old != 0) {
        delete old;
    }
    this->mission_picture = np;
skip_store:
    this->mission_picture->Save(file);

    for (int c = 0; c < 16; c++) {
        length = (short)strlen(this->BuildList[c]);
        rge_write(file, &length, 2);
        if (length > 0)
            rge_write(file, this->BuildList[c], length);
    }

    for (int d = 0; d < 16; d++) {
        length = (short)strlen(this->CityPlan[d]);
        rge_write(file, &length, 2);
        if (length > 0)
            rge_write(file, this->CityPlan[d], length);
    }

    if (*version >= 1.08) {
        for (int e = 0; e < 16; e++) {
            length = (short)strlen(this->AiRules[e]);
            rge_write(file, &length, 2);
            if (length > 0)
                rge_write(file, this->AiRules[e], length);
        }
    }

    for (int f = 0; f < 16; f++) {
        if (this->BuildList[f] != 0) {
            sprintf(temp_file_name, "%s%s.ai", rge_base_game->prog_info->ai_dir, this->BuildList[f]);
            fd = _open(temp_file_name, 0x8000);
            if (fd > -1) {
                lseek(fd, 0, 2);
                this->BuildListFileSize[f] = _tell(fd);
                if (this->BuildListFile[f] != 0) free(this->BuildListFile[f]);
                this->BuildListFile[f] = (unsigned char*)calloc(this->BuildListFileSize[f], 1);
                lseek(fd, 0, 0);
                read(fd, this->BuildListFile[f], this->BuildListFileSize[f]);
                close(fd);
            }
        }
        if (this->CityPlan[f] != 0) {
            sprintf(temp_file_name, "%s%s.cty", rge_base_game->prog_info->ai_dir, this->CityPlan[f]);
            fd = _open(temp_file_name, 0x8000);
            if (fd > -1) {
                lseek(fd, 0, 2);
                this->CityPlanFileSize[f] = _tell(fd);
                if (this->CityPlanFile[f] != 0) free(this->CityPlanFile[f]);
                this->CityPlanFile[f] = (unsigned char*)calloc(this->CityPlanFileSize[f], 1);
                lseek(fd, 0, 0);
                read(fd, this->CityPlanFile[f], this->CityPlanFileSize[f]);
                close(fd);
            }
        }
        if (this->AiRules[f] != 0) {
            sprintf(temp_file_name, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[f]);
            fd = _open(temp_file_name, 0x8000);
            if (fd > -1) {
                lseek(fd, 0, 2);
                this->AiRulesFileSize[f] = _tell(fd);
                if (this->AiRulesFile[f] != 0) free(this->AiRulesFile[f]);
                this->AiRulesFile[f] = (unsigned char*)calloc(this->AiRulesFileSize[f], 1);
                lseek(fd, 0, 0);
                read(fd, this->AiRulesFile[f], this->AiRulesFileSize[f]);
                close(fd);
            }
        }

        rge_write(file, &this->BuildListFileSize[f], 4);
        rge_write(file, &this->CityPlanFileSize[f], 4);
        if (*version >= 1.08)
            rge_write(file, &this->AiRulesFileSize[f], 4);
        if (this->BuildListFile[f] != 0)
            rge_write(file, this->BuildListFile[f], this->BuildListFileSize[f]);
        if (this->CityPlanFile[f] != 0)
            rge_write(file, this->CityPlanFile[f], this->CityPlanFileSize[f]);
        if (this->AiRulesFile[f] != 0)
            rge_write(file, this->AiRulesFile[f], this->AiRulesFileSize[f]);
    }

    end_marker = -99;
    rge_write(file, &end_marker, 4);
}

// 0048CC20 RGE_Scenario::active_player_count()
int RGE_Scenario::active_player_count() {
    int count;
    int player;

    count = 0;
    player = 0;
    do {
        if (Get_player_Active(player) != 0) {
            count = count + 1;
        }
        player = player + 1;
    } while (player < 0x10);
    return count;
}

// 0048CC50 RGE_Scenario::any_player_count()
int RGE_Scenario::any_player_count(void) {
    int count = 0;
    int i = 0;

    do {
        if (this->Get_player_Active(i) != 0) {
            if (this->Get_player_Type(i) == 1) {
                count++;
            }
        }
        i++;
    } while (i < 0x10);
    return count;
}

// 0048CC80 RGE_Scenario::computer_player_count()
int RGE_Scenario::computer_player_count(void) {
    int count = 0;
    int i = 0;

    do {
        if (this->Get_player_Active(i) != 0) {
            if (this->Get_player_Type(i) == 0) {
                count++;
            }
        }
        i++;
    } while (i < 0x10);
    return count;
}

// 0048CCB0 RGE_Scenario::Set_conquest_victory(unsigned char)
void RGE_Scenario::Set_conquest_victory(unsigned char v) { this->victory_conquest = v; }

// 0048CCC0 RGE_Scenario::Get_conquest_victory()
unsigned char RGE_Scenario::Get_conquest_victory() { return this->victory_conquest; }

// 0048CCD0 RGE_Scenario::add_description(char*)
void RGE_Scenario::add_description(char* text) {
    if (this->description == 0) {
        getstring(&this->description, text);
        return;
    }
    addstring(&this->description, this->description, text);
}

// 0048CD10 RGE_Scenario::Set_message(char*, long)
void RGE_Scenario::Set_message(char* text, long field_index) {
    long len;
    char* buf;

    if (text == 0) {
        len = 0;
    } else {
        len = strlen(text) + 1;
    }

    if (len > 0) {
        buf = (char*)calloc(len, 1);
    } else {
        buf = 0;
    }

    memcpy(buf, text, len);

    switch (field_index) {
    case 0:
        if (description != 0) {
            free(description);
        }
        description = buf;
        break;
    case 1:
        if (hints != 0) {
            free(hints);
        }
        hints = buf;
        break;
    case 2:
        if (win_message == 0) {
            free(0);
        }
        win_message = buf;
        break;
    case 3:
        if (loss_message != 0) {
            free(loss_message);
        }
        loss_message = buf;
        break;
    case 4:
        if (historicle_notes != 0) {
            free(historicle_notes);
        }
        historicle_notes = buf;
        break;
    default:
        if (buf != 0) {
            free(buf);
        }
        break;
    }
}

// 0048CE40 RGE_Scenario::Get_message(long)
char* RGE_Scenario::Get_message(long which) {
    switch (which) {
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
