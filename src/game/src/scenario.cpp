#include "../include/RGE_Scenario.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Timeline.h"
#include "../include/TPicture.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <fcntl.h>
#include <io.h>
#include <new>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

namespace {
static void rge_get_none_and_random(char* none_out, int none_out_size, char* random_out, int random_out_size) {
    if (none_out != nullptr && none_out_size > 0) none_out[0] = '\0';
    if (random_out != nullptr && random_out_size > 0) random_out[0] = '\0';

    if (rge_base_game == nullptr) {
        return;
    }

    if (none_out != nullptr && none_out_size > 0) {
        rge_base_game->get_string(0x2775, none_out, none_out_size); // " <None> "
    }
    if (random_out != nullptr && random_out_size > 0) {
        rge_base_game->get_string(0x277b, random_out, random_out_size); // "Random"
    }
}

static void rge_copy_string_to_fixed(char* dst, const char* src, int dst_size) {
    if (dst == nullptr || dst_size < 1) {
        return;
    }
    if (src == nullptr) {
        dst[0] = '\0';
        return;
    }

    // Decomp does not clamp; keep behavior simple and assume callers pass safe strings.
    strcpy(dst, src);
}

static void rge_read_string16_into(int handle, char* dst, int dst_size) {
    short length = 0;
    rge_read(handle, &length, 2);

    int read_bytes = 0;
    if (length > 0) {
        int to_read = length;
        if (dst == nullptr) {
            to_read = 0;
        } else if (dst_size > 0 && to_read > dst_size - 1) {
            to_read = dst_size - 1;
        }

        if (to_read > 0) {
            rge_read(handle, dst, to_read);
            read_bytes = to_read;
        }
        if (to_read < length) {
            _lseek(handle, (long)(length - to_read), SEEK_CUR);
        }
    }

    if (dst != nullptr && dst_size > 0) {
        int null_pos = read_bytes;
        if (length >= 0 && length < dst_size) {
            null_pos = length;
        }
        if (null_pos < 0) {
            null_pos = 0;
        }
        if (null_pos >= dst_size) {
            null_pos = dst_size - 1;
        }
        dst[null_pos] = '\0';
    }
}

static char* rge_read_string16_alloc(int handle) {
    short length = 0;
    rge_read(handle, &length, 2);
    if (length < 1) {
        return nullptr;
    }

    char* text = (char*)calloc((size_t)length, 1);
    if (text == nullptr) {
        return nullptr;
    }

    rge_read(handle, text, (int)length);
    text[length - 1] = '\0';
    return text;
}

static int rge_write_temp_blob(const char* temp_dir, const char* name_fmt, int index, const unsigned char* data, int size,
                              char* out_path) {
    if (out_path == nullptr || name_fmt == nullptr || temp_dir == nullptr) {
        return -1;
    }

    sprintf(out_path, name_fmt, temp_dir, index);

    int fd = _open(out_path, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fd == -1) {
        return -1;
    }

    (void)_write(fd, data, (unsigned int)size);
    _close(fd);
    return fd;
}
} // namespace

RGE_Scenario::RGE_Scenario(RGE_Game_World* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048AD60
    this->world = param_1;

    RGE_Timeline* tl = new (std::nothrow) RGE_Timeline(this->world);
    this->time_line = tl;

    this->InitializeTextValues();
    this->mission_picture = nullptr;
    this->victory_conquest = 1;

    memset(this->player_name, 0, sizeof(this->player_name));
}

RGE_Scenario::RGE_Scenario(int param_1, RGE_Game_World* param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048AE10
    this->world = param_2;
    this->InitializeTextValues();

    rge_read(param_1, &this->Version, 4);

    if (this->Version > 1.13f) {
        for (int i = 0; i < 16; ++i) {
            rge_read(param_1, this->player_name[i], 0x100);
        }
    }

    if (this->Version > 1.13f) {
        for (int i = 0; i < 16; ++i) {
            rge_read(param_1, &this->PlActive[i], 4);
            rge_read(param_1, &this->PlType[i], 4);
            rge_read(param_1, &this->PlCivilization[i], 4);
            rge_read(param_1, &this->PlayerPosture[i], 4);
        }
    }

    if (this->Version < 1.07f) {
        this->victory_conquest = 1;
    } else {
        rge_read(param_1, &this->victory_conquest, 1);
    }

    this->time_line = new (std::nothrow) RGE_Timeline(param_1, this->world);

    rge_read_string16_into(param_1, this->scenario_name, 0xE0);

    this->description = rge_read_string16_alloc(param_1);

    if (this->Version < 1.11f) {
        this->hints = nullptr;
        this->win_message = nullptr;
        this->loss_message = nullptr;
        this->historicle_notes = nullptr;
    } else {
        this->hints = rge_read_string16_alloc(param_1);
        this->win_message = rge_read_string16_alloc(param_1);
        this->loss_message = rge_read_string16_alloc(param_1);
        this->historicle_notes = rge_read_string16_alloc(param_1);
    }

    if (this->Version < 1.03f) {
        // Older versions had extra strings here that are ignored.
        char ignored[0xE0];
        rge_read_string16_into(param_1, ignored, (int)sizeof(ignored));
        rge_read_string16_into(param_1, ignored, (int)sizeof(ignored));
        rge_read_string16_into(param_1, ignored, (int)sizeof(ignored));
    }

    rge_read_string16_into(param_1, this->Cine_PreGame, 0xE0);
    rge_read_string16_into(param_1, this->Cine_Victory, 0xE0);
    rge_read_string16_into(param_1, this->Cine_Loss, 0xE0);

    if (this->Version >= 1.09f) {
        rge_read_string16_into(param_1, this->Mission_Bmp, 0xE0);
    }

    if (this->Version < 1.10f) {
        this->mission_picture = nullptr;
    } else {
        this->mission_picture = new (std::nothrow) TPicture(param_1, 1);
    }

    for (int i = 0; i < 16; ++i) {
        rge_read_string16_into(param_1, this->BuildList[i], 0xE0);
    }

    for (int i = 0; i < 16; ++i) {
        rge_read_string16_into(param_1, this->CityPlan[i], 0xE0);
    }

    if (this->Version >= 1.08f) {
        for (int i = 0; i < 16; ++i) {
            rge_read_string16_into(param_1, this->AiRules[i], 0xE0);
        }
    }

    for (int i = 0; i < 16; ++i) {
        rge_read(param_1, &this->BuildListFileSize[i], 4);
        rge_read(param_1, &this->CityPlanFileSize[i], 4);
        if (this->Version >= 1.08f) {
            rge_read(param_1, &this->AiRulesFileSize[i], 4);
        }

        this->BuildListFile[i] = nullptr;
        this->CityPlanFile[i] = nullptr;
        this->AiRulesFile[i] = nullptr;

        if (this->Version >= 1.15f) {
            if (this->BuildListFileSize[i] > 0) {
                this->BuildListFile[i] = (unsigned char*)calloc((size_t)this->BuildListFileSize[i], 1);
                if (this->BuildListFile[i] != nullptr) {
                    rge_read(param_1, this->BuildListFile[i], this->BuildListFileSize[i]);
                }
            }
            if (this->CityPlanFileSize[i] > 0) {
                this->CityPlanFile[i] = (unsigned char*)calloc((size_t)this->CityPlanFileSize[i], 1);
                if (this->CityPlanFile[i] != nullptr) {
                    rge_read(param_1, this->CityPlanFile[i], this->CityPlanFileSize[i]);
                }
            }
            if (this->AiRulesFileSize[i] > 0) {
                this->AiRulesFile[i] = (unsigned char*)calloc((size_t)this->AiRulesFileSize[i], 1);
                if (this->AiRulesFile[i] != nullptr) {
                    rge_read(param_1, this->AiRulesFile[i], this->AiRulesFileSize[i]);
                }
            }
        }
    }

    if (this->Version > 1.02f) {
        int checksum = 0;
        rge_read(param_1, &checksum, 4);
    }
}

void RGE_Scenario::InitializeTextValues() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048B6C0
    char none_str[30];
    char random_str[30];
    rge_get_none_and_random(none_str, (int)sizeof(none_str), random_str, (int)sizeof(random_str));

    this->description = nullptr;
    this->hints = nullptr;
    this->win_message = nullptr;
    this->loss_message = nullptr;
    this->historicle_notes = nullptr;

    this->scenario_name = (char*)operator new(0xE0, std::nothrow);
    if (this->scenario_name != nullptr) {
        memset(this->scenario_name, 0, 0xE0);
    }

    rge_copy_string_to_fixed(this->Cine_PreGame, none_str, (int)sizeof(this->Cine_PreGame));
    rge_copy_string_to_fixed(this->Cine_Victory, none_str, (int)sizeof(this->Cine_Victory));
    rge_copy_string_to_fixed(this->Cine_Loss, none_str, (int)sizeof(this->Cine_Loss));
    rge_copy_string_to_fixed(this->Mission_Bmp, none_str, (int)sizeof(this->Mission_Bmp));

    for (int i = 0; i < 16; ++i) {
        this->PlayerPosture[i] = 0;
        this->PlType[i] = 0;
        this->PlCivilization[i] = 0;
        this->PlActive[i] = 0;
        this->player_name[i][0] = '\0';

        this->BuildList[i] = (char*)operator new(0xE0, std::nothrow);
        if (this->BuildList[i] != nullptr) {
            memset(this->BuildList[i], 0, 0xE0);
            rge_copy_string_to_fixed(this->BuildList[i], random_str, 0xE0);
        }

        this->CityPlan[i] = (char*)operator new(0xE0, std::nothrow);
        if (this->CityPlan[i] != nullptr) {
            memset(this->CityPlan[i], 0, 0xE0);
            rge_copy_string_to_fixed(this->CityPlan[i], none_str, 0xE0);
        }

        this->AiRules[i] = (char*)operator new(0xE0, std::nothrow);
        if (this->AiRules[i] != nullptr) {
            memset(this->AiRules[i], 0, 0xE0);
            rge_copy_string_to_fixed(this->AiRules[i], random_str, 0xE0);
        }

        this->BuildListFile[i] = nullptr;
        this->CityPlanFile[i] = nullptr;
        this->AiRulesFile[i] = nullptr;
        this->BuildListFileSize[i] = 0;
        this->CityPlanFileSize[i] = 0;
        this->AiRulesFileSize[i] = 0;
    }
}

void RGE_Scenario::Set_scenario_name(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048B910
    if (this->scenario_name == nullptr) {
        return;
    }
    if (param_1 == nullptr) {
        this->scenario_name[0] = '\0';
        return;
    }
    strcpy(this->scenario_name, param_1);
}

void RGE_Scenario::Set_description(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048B950
    this->Set_message(param_1, 0);
}

void RGE_Scenario::Set_Cine_PreGame(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048B960
    rge_copy_string_to_fixed(this->Cine_PreGame, param_1, (int)sizeof(this->Cine_PreGame));
}

void RGE_Scenario::Set_Cine_Victory(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048B9A0
    rge_copy_string_to_fixed(this->Cine_Victory, param_1, (int)sizeof(this->Cine_Victory));
}

void RGE_Scenario::Set_Cine_Loss(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048B9E0
    rge_copy_string_to_fixed(this->Cine_Loss, param_1, (int)sizeof(this->Cine_Loss));
}

void RGE_Scenario::Set_Mission_Bmp(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BA20
    rge_copy_string_to_fixed(this->Mission_Bmp, param_1, (int)sizeof(this->Mission_Bmp));
}

void RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BA60
    if (param_1 < 0 || param_1 >= 16) {
        return;
    }

    if (param_2 == nullptr) {
        if (this->BuildList[param_1] != nullptr) {
            this->BuildList[param_1][0] = '\0';
        }
    } else if (this->BuildList[param_1] != nullptr) {
        strcpy(this->BuildList[param_1], param_2);
    }

    if (param_3 == 1 && this->BuildList[param_1] != nullptr) {
        size_t len = strlen(this->BuildList[param_1]);
        if (len >= 4) {
            this->BuildList[param_1][len - 4] = '\0';
        }
    }
}

void RGE_Scenario::Set_CityPlan(int param_1, char* param_2, int param_3) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BAD0
    if (param_1 < 0 || param_1 >= 16) {
        return;
    }

    if (param_2 == nullptr) {
        if (this->CityPlan[param_1] != nullptr) {
            this->CityPlan[param_1][0] = '\0';
        }
    } else if (this->CityPlan[param_1] != nullptr) {
        strcpy(this->CityPlan[param_1], param_2);
    }

    if (param_3 == 1 && this->CityPlan[param_1] != nullptr) {
        size_t len = strlen(this->CityPlan[param_1]);
        if (len >= 4) {
            this->CityPlan[param_1][len - 4] = '\0';
        }
    }
}

void RGE_Scenario::Set_player_AI(int param_1, char* param_2, int param_3) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BB40
    if (param_1 < 0 || param_1 >= 16) {
        return;
    }

    if (param_2 == nullptr) {
        if (this->AiRules[param_1] != nullptr) {
            this->AiRules[param_1][0] = '\0';
        }
    } else if (this->AiRules[param_1] != nullptr) {
        strcpy(this->AiRules[param_1], param_2);
    }

    if (param_3 == 1 && this->AiRules[param_1] != nullptr) {
        size_t len = strlen(this->AiRules[param_1]);
        if (len >= 4) {
            this->AiRules[param_1][len - 4] = '\0';
        }
    }
}

void RGE_Scenario::Set_Version(float param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BBB0
    this->Version = param_1;
}

void RGE_Scenario::Set_player_Type(int param_1, int param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BBC0
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->PlType[param_1] = param_2;
    }
}

void RGE_Scenario::Set_player_Civ(int param_1, int param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BBE0
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->PlCivilization[param_1] = param_2;
    }
}

void RGE_Scenario::Set_player_Active(int param_1, int param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BC00
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->PlActive[param_1] = param_2;
    }
}

void RGE_Scenario::SetPlayerName(int param_1, char* param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BC20
    if (param_2 == nullptr) {
        this->player_name[param_1][0] = '\0';
        return;
    }
    strcpy(this->player_name[param_1], param_2);
}

char* RGE_Scenario::Get_scenario_name() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BC60
    return this->scenario_name;
}

char* RGE_Scenario::Get_description() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BC70
    return this->description;
}

char* RGE_Scenario::Get_Cine_PreGame() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BC80
    return this->Cine_PreGame;
}

char* RGE_Scenario::Get_Cine_Victory() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BC90
    return this->Cine_Victory;
}

char* RGE_Scenario::Get_Cine_Loss() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BCA0
    return this->Cine_Loss;
}

char* RGE_Scenario::Get_Mission_Bmp() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BCB0
    return this->Mission_Bmp;
}

char* RGE_Scenario::Get_BuildList(int param_1, int param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BCC0
    char random_str[50];
    char none_str[50];
    rge_get_none_and_random(none_str, (int)sizeof(none_str), random_str, (int)sizeof(random_str));

    char temp_dir[260];
    if (GetTempPathA((DWORD)sizeof(temp_dir), temp_dir) == 0) {
        temp_dir[0] = '\0';
    }

    if (param_2 == 1 && this->BuildListFileSize[param_1] > 0 && this->BuildListFile[param_1] != nullptr) {
        if (rge_write_temp_blob(temp_dir, "%stemp_buildlist_%d.tmp", param_1, this->BuildListFile[param_1],
                                this->BuildListFileSize[param_1], this->TempText1) != -1) {
            return this->TempText1;
        }
    }

    if (param_2 == 1) {
        const char* name = this->BuildList[param_1];
        if (name != nullptr && name[0] != '\0' && strcmp(name, random_str) != 0 && strcmp(name, none_str) != 0 &&
            rge_base_game != nullptr && rge_base_game->prog_info != nullptr) {
            sprintf(this->TempText1, "%s%s.ai", rge_base_game->prog_info->ai_dir, name);
            return this->TempText1;
        }
    }

    sprintf(this->TempText1, "%s", (this->BuildList[param_1] != nullptr) ? this->BuildList[param_1] : "");
    return this->TempText1;
}

char* RGE_Scenario::Get_CityPlan(int param_1, int param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048BEC0
    char random_str[50];
    char none_str[50];
    rge_get_none_and_random(none_str, (int)sizeof(none_str), random_str, (int)sizeof(random_str));

    char temp_dir[260];
    if (GetTempPathA((DWORD)sizeof(temp_dir), temp_dir) == 0) {
        temp_dir[0] = '\0';
    }

    if (param_2 == 1 && this->CityPlanFileSize[param_1] > 0 && this->CityPlanFile[param_1] != nullptr) {
        if (rge_write_temp_blob(temp_dir, "%stemp_CityPlan_%d.tmp", param_1, this->CityPlanFile[param_1],
                                this->CityPlanFileSize[param_1], this->TempText2) != -1) {
            return this->TempText2;
        }
    }

    if (param_2 == 1) {
        const char* name = this->CityPlan[param_1];
        if (name != nullptr && name[0] != '\0' && strcmp(name, random_str) != 0 && strcmp(name, none_str) != 0 &&
            rge_base_game != nullptr && rge_base_game->prog_info != nullptr) {
            sprintf(this->TempText2, "%s%s.cty", rge_base_game->prog_info->ai_dir, name);
            return this->TempText2;
        }
    }

    sprintf(this->TempText2, "%s", (this->CityPlan[param_1] != nullptr) ? this->CityPlan[param_1] : "");
    return this->TempText2;
}

char* RGE_Scenario::Get_player_AI(int param_1, int param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C0E0
    char random_str[50];
    char none_str[50];
    rge_get_none_and_random(none_str, (int)sizeof(none_str), random_str, (int)sizeof(random_str));

    char temp_dir[260];
    if (GetTempPathA((DWORD)sizeof(temp_dir), temp_dir) == 0) {
        temp_dir[0] = '\0';
    }

    if (param_2 == 1 && this->AiRulesFileSize[param_1] > 0 && this->AiRulesFile[param_1] != nullptr) {
        if (rge_write_temp_blob(temp_dir, "%stemp_AiRules_%d.tmp", param_1, this->AiRulesFile[param_1],
                                this->AiRulesFileSize[param_1], this->TempText3) != -1) {
            return this->TempText3;
        }
    }

    if (param_2 == 1) {
        const char* name = this->AiRules[param_1];
        if (name != nullptr && name[0] != '\0' && strcmp(name, random_str) != 0 && strcmp(name, none_str) != 0 &&
            rge_base_game != nullptr && rge_base_game->prog_info != nullptr) {
            sprintf(this->TempText3, "%s%s.per", rge_base_game->prog_info->ai_dir, name);
            return this->TempText3;
        }
    }

    sprintf(this->TempText3, "%s", (this->AiRules[param_1] != nullptr) ? this->AiRules[param_1] : "");
    return this->TempText3;
}

int RGE_Scenario::GetPlayerPosture(int param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C2F0
    if ((param_1 >= 0) && (param_1 < 9)) {
        switch (this->PlayerPosture[param_1]) {
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
    }
    return 0;
}

char* RGE_Scenario::GetPlayerName(int param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C360
    return this->player_name[param_1];
}

int RGE_Scenario::Get_player_Type(int param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C370
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->PlType[param_1];
    }
    return 0;
}

int RGE_Scenario::Get_player_Civ(int param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C390
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->PlCivilization[param_1];
    }
    return 0;
}

int RGE_Scenario::Get_player_Active(int param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C3B0
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->PlActive[param_1];
    }
    return 0;
}

int RGE_Scenario::active_player_count() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CC20
    int count = 0;
    for (int i = 0; i < 16; ++i) {
        if (this->Get_player_Active(i) != 0) {
            count = count + 1;
        }
    }
    return count;
}

int RGE_Scenario::any_player_count() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CC50
    int count = 0;
    for (int i = 0; i < 16; ++i) {
        if (this->Get_player_Active(i) != 0) {
            if (this->Get_player_Type(i) == 1) {
                count = count + 1;
            }
        }
    }
    return count;
}

int RGE_Scenario::computer_player_count() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CC80
    int count = 0;
    for (int i = 0; i < 16; ++i) {
        if (this->Get_player_Active(i) != 0) {
            if (this->Get_player_Type(i) == 0) {
                count = count + 1;
            }
        }
    }
    return count;
}

void RGE_Scenario::Set_conquest_victory(uchar param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CCB0
    this->victory_conquest = param_1;
}

void RGE_Scenario::add_description(char* param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CCD0
    if (this->description == nullptr) {
        getstring(&this->description, param_1);
        return;
    }
    addstring(&this->description, this->description, param_1);
}

void RGE_Scenario::Set_message(char* param_1, long param_2) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CD10
    char* new_text = nullptr;
    if (param_1 != nullptr) {
        size_t len = strlen(param_1) + 1;
        if ((int)len > 0) {
            new_text = (char*)calloc(len, 1);
            if (new_text != nullptr) {
                memcpy(new_text, param_1, len);
            }
        }
    }

    switch (param_2) {
        case 0:
            if (this->description != nullptr) {
                free(this->description);
            }
            this->description = new_text;
            return;
        case 1:
            if (this->hints != nullptr) {
                free(this->hints);
            }
            this->hints = new_text;
            return;
        case 2:
            if (this->win_message != nullptr) {
                free(this->win_message);
            }
            this->win_message = new_text;
            return;
        case 3:
            if (this->loss_message != nullptr) {
                free(this->loss_message);
            }
            this->loss_message = new_text;
            return;
        case 4:
            if (this->historicle_notes != nullptr) {
                free(this->historicle_notes);
            }
            this->historicle_notes = new_text;
            return;
        default:
            if (new_text != nullptr) {
                free(new_text);
            }
            return;
    }
}

char* RGE_Scenario::Get_message(long param_1) {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048CE40
    switch (param_1) {
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
            return nullptr;
    }
}

