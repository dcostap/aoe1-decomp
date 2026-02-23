#include "../include/T_Scenario.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Effects.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Player_Tech.h"
#include "../include/globals.h"

#include <new>
#include <string.h>

T_Scenario::T_Scenario(RGE_Game_World* param_1)
    : RGE_Scenario(param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052AAC0
    this->InitializePlayerValues();
    this->InitializeVictoryValues();
    this->InitializeFriendlinessValues();

    this->mp_victory_type = 0;
    this->victory_score = 900;
    this->victory_time = 9000;
    this->victory_all_flag = 0;
    this->which_player = 0;
    this->ScenarioOptions[0] = 0;
    this->ScenarioOptions[1] = 0;
    this->ScenarioOptions[2] = 0;
    this->ClearDisabledTechnologies();
}

T_Scenario::T_Scenario(int param_1, RGE_Game_World* param_2)
    : RGE_Scenario(param_1, param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052AB90
    this->InitializeVictoryValues();
    this->InitializeFriendlinessValues();
    this->ClearDisabledTechnologies();

    this->mp_victory_type = 0;
    this->victory_score = 900;
    this->victory_time = 9000;
    this->victory_all_flag = 0;
    this->which_player = 0;
    memset(this->AlliedVictory, 0, sizeof(this->AlliedVictory));
    memset(this->ScenarioOptions, 0, sizeof(this->ScenarioOptions));
    memset(this->PlayerAge, 0, sizeof(this->PlayerAge));

    // Older scenario versions (< 1.13) store player name/type/civ/active/posture in the tribe section.
    if (this->Version <= 1.13f) {
        for (int i = 0; i < 16; ++i) {
            rge_read(param_1, this->player_name[i], 0x100);
        }
        for (int i = 0; i < 16; ++i) {
            rge_read(param_1, &this->PlActive[i], 4);
            rge_read(param_1, &this->player_info[i], 0x10);
            rge_read(param_1, &this->PlType[i], 4);
            rge_read(param_1, &this->PlCivilization[i], 4);
            rge_read(param_1, &this->PlayerPosture[i], 4);
        }
    } else {
        for (int i = 0; i < 16; ++i) {
            rge_read(param_1, &this->player_info[i], 0x10);
        }
    }

    if (this->Version > 1.02f) {
        int checksum = 0;
        rge_read(param_1, &checksum, 4);
    }

    rge_read(param_1, &this->victory, 0x18);
    rge_read(param_1, &this->victory_all_flag, 4);

    if (this->Version < 1.13f) {
        this->mp_victory_type = 4;
        this->victory_score = 900;
        this->victory_time = 9000;
    } else {
        rge_read(param_1, &this->mp_victory_type, 4);
        rge_read(param_1, &this->victory_score, 4);
        rge_read(param_1, &this->victory_time, 4);
    }

    rge_read(param_1, this->Opponent, 0x400);

    for (int i = 0; i < 16; ++i) {
        rge_read(param_1, this->sp_victory[i], 0x2d0);
    }

    if (this->Version > 1.02f) {
        int checksum = 0;
        rge_read(param_1, &checksum, 4);
    }

    if (this->Version >= 1.02f) {
        rge_read(param_1, this->AlliedVictory, 0x40);
    }

    if (this->Version > 1.03f) {
        rge_read(param_1, this->DisabledTechnology, 0x500);
    }

    if (this->Version > 1.04f) {
        if (this->Version >= 1.12f) {
            rge_read(param_1, this->ScenarioOptions, 0xC);
        } else {
            rge_read(param_1, this->ScenarioOptions, 4);
            this->ScenarioOptions[1] = 0;
            this->ScenarioOptions[2] = 0;
        }
    }

    if (this->Version > 1.05f) {
        rge_read(param_1, this->PlayerAge, 0x40);
    }

    if (this->Version > 1.02f) {
        int checksum = 0;
        rge_read(param_1, &checksum, 4);
    }
}

void T_Scenario::InitializePlayerValues() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B080
    for (int i = 0; i < 16; ++i) {
        this->player_info[i].Gold = 0;
        this->player_info[i].Wood = 200;
        this->player_info[i].Food = 200;
        this->player_info[i].Stone = 150;

        this->PlActive[i] = 0;
        this->PlType[i] = 0;
        this->PlCivilization[i] = i + 1;
        this->PlayerPosture[i] = 4;

        this->AlliedVictory[i] = 0;
        this->PlayerAge[i] = 0;
    }

    this->victory_conquest = 1;
}

void T_Scenario::ClearDisabledTechnologies() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B100
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 20; ++j) {
            this->DisabledTechnology[i][j] = 1;
        }
    }
}

void T_Scenario::InitializeAIInformation() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B120
    if (this->world == nullptr || this->world->players == nullptr) {
        return;
    }

    for (int i = 0; i < 16; ++i) {
        int player_slot = i + 1;
        if (player_slot >= this->world->player_num) {
            break;
        }

        TRIBE_Player* player = (TRIBE_Player*)this->world->players[player_slot];
        if (player == nullptr) {
            continue;
        }

        char* ai_per = this->Get_player_AI(i, 1);
        char* ai_cty = this->Get_CityPlan(i, 1);
        char* ai_bld = this->Get_BuildList(i, 1);
        player->loadAIInformation(ai_bld, ai_cty, ai_per, 4, -1);
    }
}

void T_Scenario::ClearSPVictoryCondition(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B280
    memset(&this->sp_victory[this->which_player][param_1], 0, sizeof(SP_Victory_Info));
}

void T_Scenario::InitializeFriendlinessValues() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B2B0
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            this->Opponent[i].Attitude[j] = 3;
        }
    }
}

void T_Scenario::Set_player_attitude(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B2D0
    if ((param_3 == 1) || (param_3 == 3) || (param_3 == 0)) {
        if ((param_1 >= 0) && (param_1 < 16) && (param_2 >= 0) && (param_2 < 16)) {
            this->Opponent[param_1].Attitude[param_2] = param_3;
        }
    }
}

int T_Scenario::Get_player_attitude(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B310
    if ((param_1 >= 0) && (param_1 < 16) && (param_2 >= 0) && (param_2 < 16)) {
        return this->Opponent[param_1].Attitude[param_2];
    }
    return -1;
}

void T_Scenario::Set_player_Gold(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B340
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->player_info[param_1].Gold = param_2;
    }
}

void T_Scenario::Set_player_Wood(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B360
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->player_info[param_1].Wood = param_2;
    }
}

void T_Scenario::Set_player_Food(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B380
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->player_info[param_1].Food = param_2;
    }
}

void T_Scenario::Set_player_Stone(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B3A0
    if ((param_1 >= 0) && (param_1 < 16)) {
        this->player_info[param_1].Stone = param_2;
    }
}

void T_Scenario::Set_player_Info(int param_1, Player_Start_Info* param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B3C0
    if ((param_1 >= 0) && (param_1 < 16) && param_2 != nullptr) {
        this->player_info[param_1] = *param_2;
    }
}

void T_Scenario::SetSPWhich(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B210
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_1 > 0xF) {
        param_1 = 0xF;
    }
    this->which_player = param_1;
}

int T_Scenario::GetSPWhich() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B230
    return this->which_player;
}

void T_Scenario::SetSPRectangle(int param_1, float param_2, float param_3, float param_4, float param_5) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B480
    this->sp_victory[this->which_player][param_1].x1 = param_2;
    this->sp_victory[this->which_player][param_1].y1 = param_3;
    this->sp_victory[this->which_player][param_1].x2 = param_4;
    this->sp_victory[this->which_player][param_1].y2 = param_5;
}

void T_Scenario::SetSPObjectType(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B500
    this->sp_victory[this->which_player][param_1].ObjType = param_2;
}

void T_Scenario::SetSPPlayerID(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B530
    this->sp_victory[this->which_player][param_1].PlayerID = param_2;
}

void T_Scenario::SetSPAllFlag(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B560
    this->sp_victory[this->which_player][param_1].AllFlag = param_2;
}

void T_Scenario::SetSPAttribType(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B590
    this->sp_victory[this->which_player][param_1].AttribType = param_2;
}

void T_Scenario::SetSPVictoryType(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B5C0
    this->sp_victory[this->which_player][param_1].VictoryType = param_2;
}

int T_Scenario::get_object_ID(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052C0A0
    return (param_1 != nullptr) ? (int)param_1->id : -1;
}

void T_Scenario::SetSPObject(int param_1, RGE_Static_Object* param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B5F0
    if (param_2 != nullptr) {
        int id = this->get_object_ID(param_2);
        this->sp_victory[this->which_player][param_1].obj_ID = id + 1;
    }
}

void T_Scenario::SetSPDestObjectID(int param_1, RGE_Static_Object* param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B630
    if (param_2 != nullptr) {
        int id = this->get_object_ID(param_2);
        this->sp_victory[this->which_player][param_1].dest_obj_ID = id + 1;
    }
}

void T_Scenario::SetSPAmount(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B670
    this->sp_victory[this->which_player][param_1].Amount = param_2;
}

void T_Scenario::SetPlayerAlliedVictory(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B6A0
    this->AlliedVictory[param_1] = param_2;
}

void T_Scenario::SetDisabledTechnology(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B6C0
    this->DisabledTechnology[param_1][param_2] = param_3;
}

void T_Scenario::SetPlayerAge(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B700
    this->PlayerAge[param_1] = param_2;
}

int T_Scenario::Get_player_Gold(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B720
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->player_info[param_1].Gold;
    }
    return 0;
}

int T_Scenario::Get_player_Wood(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B740
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->player_info[param_1].Wood;
    }
    return 0;
}

int T_Scenario::Get_player_Food(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B760
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->player_info[param_1].Food;
    }
    return 0;
}

int T_Scenario::Get_player_Stone(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B780
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->player_info[param_1].Stone;
    }
    return 0;
}

Player_Start_Info* T_Scenario::Get_player_Info(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B7A0
    if ((param_1 >= 0) && (param_1 < 16)) {
        return this->player_info + param_1;
    }
    return nullptr;
}

int T_Scenario::Get_Multi_Conquest() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B7C0
    return this->victory.MP_Conquest;
}

void T_Scenario::GetSPRectangle(int param_1, float* param_2, float* param_3, float* param_4, float* param_5) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B820
    if (param_2 != nullptr) *param_2 = this->sp_victory[this->which_player][param_1].x1;
    if (param_3 != nullptr) *param_3 = this->sp_victory[this->which_player][param_1].y1;
    if (param_4 != nullptr) *param_4 = this->sp_victory[this->which_player][param_1].x2;
    if (param_5 != nullptr) *param_5 = this->sp_victory[this->which_player][param_1].y2;
}

int T_Scenario::GetSPObjectType(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B8B0
    return this->sp_victory[this->which_player][param_1].ObjType;
}

int T_Scenario::GetSPPlayerID(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B8E0
    return this->sp_victory[this->which_player][param_1].PlayerID;
}

int T_Scenario::GetSPAllFlag(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B910
    return this->sp_victory[this->which_player][param_1].AllFlag;
}

int T_Scenario::GetSPAttribType(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B940
    return this->sp_victory[this->which_player][param_1].AttribType;
}

int T_Scenario::GetSPAmount(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B970
    return this->sp_victory[this->which_player][param_1].Amount;
}

int T_Scenario::GetSPVictoryType(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B9A0
    return this->sp_victory[this->which_player][param_1].VictoryType;
}

RGE_Static_Object* T_Scenario::GetSPDestObjectID(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052B9D0
    return this->get_object_pointer(this->sp_victory[this->which_player][param_1].dest_obj_ID);
}

RGE_Static_Object* T_Scenario::GetSPObject(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052BA00
    return this->get_object_pointer(this->sp_victory[this->which_player][param_1].obj_ID);
}

int T_Scenario::GetPlayerAlliedVictory(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052BA30
    return this->AlliedVictory[param_1];
}

int T_Scenario::GetDisabledTechnology(int param_1, int param_2) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052BA40
    return this->DisabledTechnology[param_1][param_2];
}

int T_Scenario::GetPlayerAge(int param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052BA70
    return this->PlayerAge[param_1];
}

void T_Scenario::update() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052BA80
    RGE_Scenario::update();
}

int T_Scenario::any_sp_victory() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052C1E0
    for (int player = 0; player < 16; ++player) {
        if (this->Get_player_Active(player) != 0) {
            this->SetSPWhich(player);
            for (int slot = 0; slot < 12; ++slot) {
                if (this->GetSPVictoryType(slot) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void T_Scenario::set_player_tech(TRIBE_Player* param_1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052C230
    if (param_1 == nullptr) {
        return;
    }

    int player_index = (int)param_1->id - 1;
    if (player_index < 0 || player_index >= 16) {
        return;
    }

    int* disabled = this->DisabledTechnology[player_index];

    if (this->ScenarioOptions[0] != 0 && this->world != nullptr && this->world->effects != nullptr) {
        this->world->effects->do_effect(100, param_1);
    }

    param_1->tech_abling(0x58, (uchar)disabled[0]);
    param_1->tech_abling(0x59, (uchar)disabled[1]);
    param_1->tech_abling(0x5A, (uchar)disabled[2]);
    param_1->tech_abling(0x5B, (uchar)disabled[3]);
    param_1->tech_abling(0x5E, (uchar)disabled[4]);
    param_1->tech_abling(0x5F, (uchar)disabled[5]);
    param_1->tech_abling(0x61, (uchar)disabled[6]);
    param_1->tech_abling(0x62, (uchar)disabled[7]);
    param_1->tech_abling(0x5D, (uchar)disabled[8]);
    param_1->tech_abling(0x60, (uchar)disabled[9]);
    param_1->tech_abling(0x5C, (uchar)disabled[10]);
    param_1->tech_abling(0x65, (uchar)disabled[11]);
    param_1->tech_abling(0x66, (uchar)disabled[12]);
    param_1->tech_abling(0x67, (uchar)disabled[13]);
    param_1->tech_abling(0x73, (uchar)disabled[14]);
    param_1->tech_abling(0x74, (uchar)disabled[15]);

    if (param_1->tech_tree != nullptr) {
        param_1->tech_tree->check_for_new_tech();
    }

    if (rge_base_game != nullptr && rge_base_game->prog_mode != 7) {
        long tech = 0;
        switch (this->PlayerAge[player_index]) {
            case 1:
                tech = 0x19;
                break;
            case 2:
                tech = 0x17;
                break;
            case 3:
                tech = 0x18;
                break;
            case 4:
                tech = 1;
                break;
            default:
                tech = 0;
                break;
        }
        if (tech != 0) {
            param_1->rev_tech(tech);
        }
    }
}

