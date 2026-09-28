#include <string.h>
#include "../include/program_mode.h"

#include "../include/tscenaro.h"
#include "../include/basegame.h"
#include "../include/effects.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/tech.h"
#include "../include/tplayer.h"
#include "../include/tvictory.h"
#include "../include/world.h"

extern void rge_read_uncompressed(int file, void* data, int size);
extern void rge_write_uncompressed(int file, void* data, int size);
#include "../include/rge_fio.h"

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* scenario_info)
    : RGE_Scenario_Header(scenario_info) {
    any_sp_victory = scenario_info->any_sp_victory();
    active_player_count = scenario_info->active_player_count();
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int infile)
    : RGE_Scenario_Header(infile) {
    any_sp_victory = 0;
    active_player_count = 0;
    if (error_code == 0) {
        rge_read_uncompressed(infile, &any_sp_victory, 4);
        rge_read_uncompressed(infile, &active_player_count, 4);
    }
}

long TRIBE_Scenario_Header::get_size() {
    return RGE_Scenario_Header::get_size() + 8;
}

void TRIBE_Scenario_Header::save(int outfile) {
    RGE_Scenario_Header::save(outfile);
    rge_write_uncompressed(outfile, &this->any_sp_victory, 4);
    rge_write_uncompressed(outfile, &this->active_player_count, 4);
}

T_Scenario::T_Scenario(RGE_Game_World* w)
    : RGE_Scenario(w) {
    InitializePlayerValues();
    InitializeVictoryValues();
    InitializeFriendlinessValues();
    mp_victory_type = 0;
    victory_score = 900;
    victory_time = 9000;
    victory_all_flag = 0;
    which_player = 0;
    for (int i = 0; i < 3; i++) {
        ScenarioOptions[i] = 0;
    }
    ClearDisabledTechnologies();
}

T_Scenario::T_Scenario(int infile, RGE_Game_World* w) : RGE_Scenario(infile, w) {
    int checksum = 0;
    InitializeVictoryValues();
    InitializeFriendlinessValues();
    ClearDisabledTechnologies();

    int old_version;
    if (Version <= g_scenario_file_version_1_13) {
        mp_victory_type = 0;
        victory_score = 900;
        victory_time = 9000;
        victory_all_flag = 0;
        which_player = 0;
        old_version = 1;
    } else {
        mp_victory_type = 0;
        victory_score = 900;
        victory_time = 9000;
        victory_all_flag = 0;
        which_player = 0;
        old_version = 0;
    }

    if (old_version) {
        int i;
        for (i = 0; i < 16; ++i) rge_read(infile, player_name[i], 256);
    }

    if (Version > g_scenario_file_version_1_13) {
        int i;
        for (i = 0; i < 16; ++i) rge_read(infile, &player_info[i], 16);
    } else {
        int i;
        for (i = 0; i < 16; ++i) {
            rge_read(infile, &PlActive[i], 4);
            rge_read(infile, &player_info[i], 16);
            rge_read(infile, &PlType[i], 4);
            rge_read(infile, &PlCivilization[i], 4);
            rge_read(infile, &PlayerPosture[i], 4);
        }
    }

    if (Version > g_scenario_file_version_1_02) {
        rge_read(infile, &checksum, 4);
    }

    rge_read(infile, &victory, 24);
    rge_read(infile, &victory_all_flag, 4);

    if (Version >= g_scenario_file_version_1_13) {
        rge_read(infile, &mp_victory_type, 4);
        rge_read(infile, &victory_score, 4);
        rge_read(infile, &victory_time, 4);
    } else {
        mp_victory_type = 4;
        victory_score = 900;
        victory_time = 9000;
    }

    rge_read(infile, Opponent, 1024);
    for (int p = 0; p < 16; ++p) rge_read(infile, sp_victory[p], sizeof(sp_victory[p]));

    if (Version > g_scenario_file_version_1_02) rge_read(infile, &checksum, 4);

    if (Version == 1.01f) {
        for (int j = 0; j < 16; ++j) rge_read(infile, AlliedVictory, 64);
    }
    if (Version >= g_scenario_file_version_1_02) rge_read(infile, AlliedVictory, 64);
    if (Version > g_scenario_file_version_1_03) rge_read(infile, DisabledTechnology, 1280);

    if (Version > g_scenario_file_version_1_04) {
        if (Version < g_scenario_file_version_1_12) {
            rge_read(infile, ScenarioOptions, 4);
            ScenarioOptions[1] = 0;
            ScenarioOptions[2] = 0;
        } else {
            rge_read(infile, ScenarioOptions, 12);
        }
    }
    if (Version > g_scenario_file_version_1_05) rge_read(infile, PlayerAge, 64);
    if (Version > g_scenario_file_version_1_02) rge_read(infile, &checksum, 4);

    victory.MP_Conquest = victory_conquest;
}

void T_Scenario::save(int outfile) {
    int checksum;
    Player_Start_Info* player;
    SP_Victory_Info (*sp_player)[12];
    int i;

    checksum = -99;
    WriteDisabledTechnologiesToMainSystem();
    RGE_Scenario::save(outfile);

    player = player_info;
    for (i = 0x10; i != 0; --i) {
        rge_write(outfile, player, 16);
        ++player;
    }

    rge_write(outfile, &checksum, 4);
    rge_write(outfile, &victory, 24);
    rge_write(outfile, &victory_all_flag, 4);
    rge_write(outfile, &mp_victory_type, 4);
    rge_write(outfile, &victory_score, 4);
    rge_write(outfile, &victory_time, 4);
    rge_write(outfile, Opponent, 1024);

    sp_player = sp_victory;
    for (i = 0x10; i != 0; --i) {
        rge_write(outfile, sp_player, 720);
        ++sp_player;
    }

    rge_write(outfile, &checksum, 4);
    rge_write(outfile, AlliedVictory, 64);
    rge_write(outfile, DisabledTechnology, 1280);
    rge_write(outfile, ScenarioOptions, 12);
    rge_write(outfile, PlayerAge, 64);
    rge_write(outfile, &checksum, 4);
}

void T_Scenario::InitializePlayerValues() {
    for (int i = 0; i < 16; ++i) {
        Player_Start_Info* info = &this->player_info[i];
        memset(info, 0, sizeof(*info));

        this->PlActive[i] = 0;
        info->Gold = 0;
        info->Wood = 200;
        info->Food = 200;
        info->Stone = 150;

        this->PlType[i] = 0;
        this->PlCivilization[i] = i + 1;
        this->PlayerPosture[i] = 4;
        this->AlliedVictory[i] = 0;
        this->PlayerAge[i] = 0;
    }

    this->PlType[0] = 1;
}

void T_Scenario::ClearDisabledTechnologies() {
    for (int i = 0; i < 320; i++) this->DisabledTechnology[0][i] = 1;
}

void T_Scenario::InitializeAIInformation() {
    int player;

    player = 0;
    do {
        this->world->players[player]->loadAIInformation(this->Get_BuildList(player, 1), this->Get_CityPlan(player, 1), this->Get_player_AI(player, 1), 4, -1);
        player++;
    } while (player < 16);
}

void T_Scenario::Set_victory_all_flag(int i) {
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    this->victory_all_flag = i;
}

int T_Scenario::Get_victory_all_flag() {
    return this->victory_all_flag;
}

void T_Scenario::SetMPVictory(int i) {
    this->mp_victory_type = i;
    if (i != 4) this->victory_conquest = 1;
}

int T_Scenario::GetMPVictory() {
    return this->mp_victory_type;
}

void T_Scenario::SetVictoryScore(int i) {
    this->victory_score = i;
}

int T_Scenario::GetVictoryScore() {
    return this->victory_score;
}

void T_Scenario::SetVictoryTime(int i) {
    this->victory_time = i;
}

int T_Scenario::GetVictoryTime() {
    return this->victory_time;
}

void T_Scenario::SetSPWhich(int i) {
    if (i < 0) i = 0;
    if (i > 16) i = 15;
    this->which_player = i;
}

int T_Scenario::GetSPWhich() {
    return this->which_player;
}

void T_Scenario::InitializeVictoryValues() {
    int* victory_values;
    int i;

    this->victory.MP_Conquest = 1;
    this->victory.MP_Ruins = 0;
    this->victory.MP_Artifacts = 0;
    this->victory.MP_Discoveries = 0;
    this->victory.MP_Exploration = 0;
    this->victory.MP_Gold = 0;

    victory_values = &this->sp_victory[0][0].ObjType;
    for (i = 0; i < 0xB40; ++i) {
        victory_values[i] = 0;
    }
}

void T_Scenario::ClearSPVictoryCondition(int which) {
    memset(&this->sp_victory[this->which_player][which], 0, sizeof(SP_Victory_Info));
}

void T_Scenario::InitializeFriendlinessValues() {
    for (int player = 0; player < 16; ++player) {
        for (int target = 0; target < 16; ++target) {
            this->Opponent[player].Attitude[target] = 3;
        }
    }
}

void T_Scenario::Set_player_attitude(int which, int opponent, int attitude) {
    if (((attitude == 1) || (attitude == 3) || (attitude == 0)) &&
        ((which >= 0) && (which < 0x10) && (opponent >= 0) && (opponent < 0x10))) {
        this->Opponent[which].Attitude[opponent] = attitude;
    }
}

int T_Scenario::Get_player_attitude(int which, int opponent) {
    if (which < 0 || which >= 16)
        return -1;
    if (opponent < 0 || opponent >= 16)
        return -1;
    return this->Opponent[which].Attitude[opponent];
}

void T_Scenario::Set_player_Gold(int which, int g) {
    if (which < 0 || which >= 16)
        return;
    this->player_info[which].Gold = g;
}

void T_Scenario::Set_player_Wood(int which, int w) {
    if (which < 0 || which >= 16) return;
    this->player_info[which].Wood = w;
}

void T_Scenario::Set_player_Food(int which, int f) {
    if (which < 0 || which >= 16) return;
    this->player_info[which].Food = f;
}

void T_Scenario::Set_player_Stone(int which, int s) {
    if (which < 0 || which >= 16) return;
    this->player_info[which].Stone = s;
}

void T_Scenario::Set_player_Info(int which, Player_Start_Info* i) {
    if ((which >= 0) && (which < 16)) {
        this->player_info[which] = *i;
    }
}

void T_Scenario::Set_Multi_Conquest(int c) {
    if (c) {
        this->victory.MP_Conquest = 1;
        this->Set_conquest_victory(1);
    } else {
        this->victory.MP_Conquest = 0;
        this->Set_conquest_victory(0);
    }
}

void T_Scenario::Set_Multi_Ruins(int r) {
    this->victory.MP_Ruins = r;
}

void T_Scenario::Set_Multi_Artifacts(int a) {
    this->victory.MP_Artifacts = a;
}

void T_Scenario::Set_Multi_Discoveries(int d) {
    this->victory.MP_Discoveries = d;
}

void T_Scenario::Set_Multi_Exploration(int e) {
    this->victory.MP_Exploration = e;
}

void T_Scenario::Set_Multi_Gold(int g) {
    this->victory.MP_Gold = g;
}

void T_Scenario::SetSPRectangle(int VicID, float x1, float y1, float x2, float y2) {
    this->sp_victory[this->which_player][VicID].x1 = x1;
    this->sp_victory[this->which_player][VicID].y1 = y1;
    this->sp_victory[this->which_player][VicID].x2 = x2;
    this->sp_victory[this->which_player][VicID].y2 = y2;
}

void T_Scenario::SetSPObjectType(int VicID, int ObjType) {
    this->sp_victory[this->which_player][VicID].ObjType = ObjType;
}

void T_Scenario::SetSPPlayerID(int VicID, int PlayerID) {
    this->sp_victory[this->which_player][VicID].PlayerID = PlayerID;
}

void T_Scenario::SetSPAllFlag(int VicID, int AllFlag) {
    this->sp_victory[this->which_player][VicID].AllFlag = AllFlag;
}

void T_Scenario::SetSPAttribType(int VicID, int AttribType) {
    this->sp_victory[this->which_player][VicID].AttribType = AttribType;
}

void T_Scenario::SetSPVictoryType(int VicID, int VictoryType) {
    this->sp_victory[this->which_player][VicID].VictoryType = VictoryType;
}

void T_Scenario::SetSPObject(int VicID, RGE_Static_Object* obj) {
    if (obj != 0) {
        this->sp_victory[this->which_player][VicID].obj_ID =
            this->get_object_ID(obj) + 1;
    }
}

void T_Scenario::SetSPDestObjectID(int VicID, RGE_Static_Object* dest_obj) {
    if (dest_obj != 0) {
        this->sp_victory[this->which_player][VicID].dest_obj_ID =
            this->get_object_ID(dest_obj) + 1;
    }
}

void T_Scenario::SetSPAmount(int VicID, int Amount) {
    this->sp_victory[this->which_player][VicID].Amount = Amount;
}

void T_Scenario::SetPlayerAlliedVictory(int which, int OnOff) {
    this->AlliedVictory[which] = OnOff;
}

void T_Scenario::SetDisabledTechnology(int PlayerId, int which, int tf) {
    DisabledTechnology[PlayerId][which] = tf;
}

void T_Scenario::SetScenarioOption(int option, int value) {
    this->ScenarioOptions[option] = value;
}

void T_Scenario::SetPlayerAge(int which, int val) {
    this->PlayerAge[which] = val;
}

int T_Scenario::Get_player_Gold(int which) {
    if (which < 0 || which >= 16)
        return 0;
    return this->player_info[which].Gold;
}

int T_Scenario::Get_player_Wood(int which) {
    if (which < 0 || which >= 16)
        return 0;
    return this->player_info[which].Wood;
}

int T_Scenario::Get_player_Food(int which) {
    if (which < 0 || which >= 16)
        return 0;
    return this->player_info[which].Food;
}

int T_Scenario::Get_player_Stone(int which) {
    if (which < 0 || which >= 16)
        return 0;
    return this->player_info[which].Stone;
}

Player_Start_Info* T_Scenario::Get_player_Info(int which) {
    if (which < 0 || which >= 16)
        return 0;
    return &this->player_info[which];
}

int T_Scenario::Get_Multi_Conquest() {
    return this->victory.MP_Conquest;
}

int T_Scenario::Get_Multi_Ruins() {
    return this->victory.MP_Ruins;
}

int T_Scenario::Get_Multi_Artifacts() {
    return this->victory.MP_Artifacts;
}

int T_Scenario::Get_Multi_Discoveries() {
    return this->victory.MP_Discoveries;
}

int T_Scenario::Get_Multi_Exploration() {
    return this->victory.MP_Exploration;
}

int T_Scenario::Get_Multi_Gold() {
    return this->victory.MP_Gold;
}

void T_Scenario::GetSPRectangle(int VicID, float* x1, float* y1, float* x2, float* y2) {
    *x1 = this->sp_victory[this->which_player][VicID].x1;
    *y1 = this->sp_victory[this->which_player][VicID].y1;
    *x2 = this->sp_victory[this->which_player][VicID].x2;
    *y2 = this->sp_victory[this->which_player][VicID].y2;
}

int T_Scenario::GetSPObjectType(int VicID) {
    return this->sp_victory[this->which_player][VicID].ObjType;
}

int T_Scenario::GetSPPlayerID(int VicID) {
    return this->sp_victory[this->which_player][VicID].PlayerID;
}

int T_Scenario::GetSPAllFlag(int VicID) {
    return this->sp_victory[this->which_player][VicID].AllFlag;
}

int T_Scenario::GetSPAttribType(int VicID) {
    return this->sp_victory[this->which_player][VicID].AttribType;
}

int T_Scenario::GetSPAmount(int VicID) {
    return this->sp_victory[this->which_player][VicID].Amount;
}

int T_Scenario::GetSPVictoryType(int VicID) {
    return this->sp_victory[this->which_player][VicID].VictoryType;
}

RGE_Static_Object* T_Scenario::GetSPDestObjectID(int VicID) {
    return this->get_object_pointer(this->sp_victory[this->which_player][VicID].dest_obj_ID);
}

RGE_Static_Object* T_Scenario::GetSPObject(int VicID) {
    return this->get_object_pointer(this->sp_victory[this->which_player][VicID].obj_ID);
}

int T_Scenario::GetPlayerAlliedVictory(int which) {
    return this->AlliedVictory[which];
}

int T_Scenario::GetDisabledTechnology(int PlayerId, int which) {
    return this->DisabledTechnology[PlayerId][which];
}

int T_Scenario::GetScenarioOption(int option) {
    return this->ScenarioOptions[option];
}

int T_Scenario::GetPlayerAge(int which) {
    return this->PlayerAge[which];
}

void T_Scenario::update() {
    this->time_line->update();
}

void T_Scenario::SaveAttributesIntoPlayers() {
    int player = 1;
    int other;
    if (player < this->world->player_num) {
        do {
            this->world->players[player]->new_attribute_num(0, (float)this->Get_player_Food(player - 1));
            this->world->players[player]->new_attribute_num(2, (float)this->Get_player_Stone(player - 1));
            this->world->players[player]->new_attribute_num(3, (float)this->Get_player_Gold(player - 1));
            this->world->players[player]->new_attribute_num(1, (float)this->Get_player_Wood(player - 1));

            other = 1;
            if (other < this->world->player_num) {
                do {
                    if (other != player) {
                        this->world->players[player]->set_relation(other,
                                                                   (unsigned char)this->Opponent[player - 1].Attitude[other - 1]);
                    }
                    ++other;
                } while (other < this->world->player_num);
            }

            this->world->players[player]->set_allied_victory((unsigned char)this->AlliedVictory[player - 1]);
            ++player;
        } while (player < this->world->player_num);
    }
}

void T_Scenario::Save_victory_conditions_into_players(int SaveAttributes) {
    if (SaveAttributes != 0) {
        this->SaveAttributesIntoPlayers();
    }

    RGE_Game_World* world = this->world;
    int one = 1;
    for (int player = one; player < (int)world->player_num; ++player) {
        world->players[player]->victory_conditions->destroy_all();
        world = this->world;
    }

    if (this->mp_victory_type == 4) {
        if (this->victory_all_flag != 0) {
            world = this->world;
            for (int player = one; player < (int)world->player_num; ++player) {
                TRIBE_Victory_Conditions* conditions =
                    static_cast<TRIBE_Victory_Conditions*>(world->players[player]->victory_conditions);
                if (this->victory.MP_Exploration != 0) {
                    conditions->add_explore(8, this->victory.MP_Exploration, one);
                }
                if (this->victory.MP_Ruins != 0) {
                    conditions->add_attributes(8, 14, this->victory.MP_Ruins, one);
                }
                if (this->victory.MP_Artifacts != 0) {
                    conditions->add_attributes(8, 7, this->victory.MP_Artifacts, one);
                }
                if (this->victory.MP_Discoveries != 0) {
                    conditions->add_attributes(8, 13, this->victory.MP_Discoveries, 0);
                }
                if (this->victory.MP_Gold != 0) {
                    conditions->add_attributes(8, 3, this->victory.MP_Gold, one);
                }
                world = this->world;
            }
        }

        if (this->victory_all_flag == 0) {
            world = this->world;
            for (int player = one; player < (int)world->player_num; ++player) {
                TRIBE_Victory_Conditions* conditions =
                    static_cast<TRIBE_Victory_Conditions*>(world->players[player]->victory_conditions);
                if (this->victory.MP_Exploration != 0) {
                    conditions->add_explore(8, this->victory.MP_Exploration, one);
                }
                if (this->victory.MP_Ruins != 0) {
                    conditions->add_attributes(9, 14, this->victory.MP_Ruins, one);
                }
                if (this->victory.MP_Artifacts != 0) {
                    conditions->add_attributes(10, 7, this->victory.MP_Artifacts, one);
                }
                if (this->victory.MP_Discoveries != 0) {
                    conditions->add_attributes(11, 13, this->victory.MP_Discoveries, 0);
                }
                if (this->victory.MP_Gold != 0) {
                    conditions->add_attributes(12, 3, this->victory.MP_Gold, one);
                }
                world = this->world;
            }
        }
    }

    int j = 0;
    world = this->world;
    if ((int)world->player_num - 1 <= 0) {
        return;
    }

    SaveAttributes = 0x72;
    do {
        TRIBE_Victory_Conditions* conditions =
            static_cast<TRIBE_Victory_Conditions*>(this->world->players[j + 1]->victory_conditions);
        int i = 0;
        do {
            SP_Victory_Info* condition = &this->sp_victory[j][i];
            // The shipped record walk is anchored at AttribType.
            int* attribute_field = &condition->AttribType;
            int type = attribute_field[-2];
            if (type != 0) {
                if (type == 4) {
                    int attribute = *attribute_field;
                    if (attribute == 6) {
                        conditions->add_explore(1, attribute_field[-1], 1);
                    } else if (attribute == 4) {
                        conditions->add_attributes(1, 11, attribute_field[-1], 0);
                    } else if (attribute == 3) {
                        conditions->add_attributes(1, 0, attribute_field[-1], 0);
                    } else if (attribute == 2) {
                        conditions->add_attributes(1, 2, attribute_field[-1], 0);
                    } else if (attribute == 1) {
                        conditions->add_attributes(1, 1, attribute_field[-1], 0);
                    } else if (attribute == 0) {
                        conditions->add_attributes(1, 3, attribute_field[-1], 0);
                    } else if (attribute == 5) {
                        conditions->add_attributes(1, 6, attribute_field[-1], 0);
                    }
                } else if (type == 6) {
                    conditions->add_attributes(1, *attribute_field, attribute_field[-1], 0);
                } else if (type == 5) {
                    conditions->add_capture(1, this->get_object_pointer(condition->obj_ID), 1);
                } else if (type == 3) {
                    if (this->get_object_pointer(condition->dest_obj_ID) != 0) {
                        conditions->add_bring(1, this->get_object_pointer(condition->obj_ID),
                                              this->get_object_pointer(condition->dest_obj_ID));
                    } else {
                        conditions->add_bring(1, this->get_object_pointer(condition->obj_ID), this->sp_victory[j][i].x1,
                                              condition->y1, condition->x2, condition->y2);
                    }
                } else if (type == 2) {
                    if (condition->x2 > g_scenario_victory_zero_coordinate) {
                        conditions->add_create(1, condition->ObjType, condition->Amount, this->sp_victory[j][i].x1,
                                               condition->y1, condition->x2, condition->y2, 0);
                    } else {
                        conditions->add_create(1, condition->ObjType, condition->Amount, 0);
                    }
                } else if (type == 7) {
                    conditions->add_tech(1, condition->AttribType);
                } else if (type == 1) {
                    int object_type = condition->ObjType;
                    if (object_type != 0 && condition->AllFlag != 0) {
                        conditions->add_destroy(1, object_type, (RGE_Player*)0);
                    } else {
                        int player_id = condition->PlayerID;
                        if (player_id != 0 && object_type != 0) {
                            conditions->add_destroy(1, object_type, condition->Amount, this->world->players[player_id]);
                        } else if (player_id != 0) {
                            conditions->add_destroy(1, this->world->players[player_id]);
                        } else if (this->get_object_pointer(condition->obj_ID) != 0) {
                            conditions->add_destroy(1, this->get_object_pointer(condition->obj_ID));
                        }
                    }
                }
            }
            ++i;
        } while (i < 12);

        SaveAttributes += 12;
        ++j;
        world = this->world;
    } while (j < (int)world->player_num - 1);
}

void T_Scenario::rehook() {
}

RGE_Static_Object* T_Scenario::get_object_pointer(int obj_ID) {
    RGE_Static_Object* result = 0;
    if (obj_ID > 0) {
        result = this->world->object(obj_ID - 1);
    }
    return result;
}

int T_Scenario::get_object_ID(RGE_Static_Object* obj) {
    return obj->id;
}

void T_Scenario::WriteDisabledTechnologiesToMainSystem() {
    RGE_Game_World* world = this->world;
    if (world == 0)
        return;

    if (world->player_num <= 1)
        return;

    int player_index = 1;
    // The shipped loop reads the low byte of each typed field.
    int* disabled = &this->DisabledTechnology[0][1];
    do {
        TRIBE_Player* player =
            static_cast<TRIBE_Player*>(world->players[player_index]);

        if (this->ScenarioOptions[0] != 0) {
            world->effects->do_effect(100, player);
        }

        player->tech_abling(0x58, (uchar)disabled[-1]);
        player->tech_abling(0x59, (uchar)disabled[0]);
        player->tech_abling(0x5A, (uchar)disabled[1]);
        player->tech_abling(0x5B, (uchar)disabled[2]);
        player->tech_abling(0x5E, (uchar)disabled[3]);
        player->tech_abling(0x5F, (uchar)disabled[4]);
        player->tech_abling(0x61, (uchar)disabled[5]);
        player->tech_abling(0x62, (uchar)disabled[6]);
        player->tech_abling(0x5D, (uchar)disabled[7]);
        player->tech_abling(0x60, (uchar)disabled[8]);
        player->tech_abling(0x5C, (uchar)disabled[9]);
        player->tech_abling(0x65, (uchar)disabled[10]);
        player->tech_abling(0x66, (uchar)disabled[11]);
        player->tech_abling(0x67, (uchar)disabled[12]);
        player->tech_abling(0x73, (uchar)disabled[13]);
        player->tech_abling(0x74, (uchar)disabled[14]);

        ++player_index;
        world = this->world;
        disabled += 20;
    } while (player_index < (int)world->player_num);
}

int T_Scenario::any_sp_victory() {
    int player;
    int sp_index;

    for (player = 0; player < 16; player++) {
        if (this->Get_player_Active(player)) {
            this->SetSPWhich(player);
            for (sp_index = 0; sp_index < 12; sp_index++) {
                if (this->GetSPVictoryType(sp_index)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void T_Scenario::set_player_tech(TRIBE_Player* player) {
    int i = player->id;
    i--;
    if (i < 0) {
        return;
    }

    player->tech_abling(0x58, (uchar)this->DisabledTechnology[i][0]);
    player->tech_abling(0x59, (uchar)this->DisabledTechnology[i][1]);
    player->tech_abling(0x5A, (uchar)this->DisabledTechnology[i][2]);
    player->tech_abling(0x5B, (uchar)this->DisabledTechnology[i][3]);
    player->tech_abling(0x5E, (uchar)this->DisabledTechnology[i][4]);
    player->tech_abling(0x5F, (uchar)this->DisabledTechnology[i][5]);
    player->tech_abling(0x61, (uchar)this->DisabledTechnology[i][6]);
    player->tech_abling(0x62, (uchar)this->DisabledTechnology[i][7]);
    player->tech_abling(0x5D, (uchar)this->DisabledTechnology[i][8]);
    player->tech_abling(0x60, (uchar)this->DisabledTechnology[i][9]);
    player->tech_abling(0x5C, (uchar)this->DisabledTechnology[i][10]);
    player->tech_abling(0x65, (uchar)this->DisabledTechnology[i][11]);
    player->tech_abling(0x66, (uchar)this->DisabledTechnology[i][12]);
    player->tech_abling(0x67, (uchar)this->DisabledTechnology[i][13]);
    player->tech_abling(0x73, (uchar)this->DisabledTechnology[i][14]);
    player->tech_abling(0x74, (uchar)this->DisabledTechnology[i][15]);

    player->tech_tree->check_for_new_tech();

    if (this->ScenarioOptions[0] != 0) {
        this->world->effects->do_effect(100, player);
    }

    if (rge_base_game->prog_mode != ProgModeScenarioEditor) {
        //! @bug Iron and post-iron starts run every research here, before civ stat bonuses exist.
        //! Unit upgrades copy source stats now, so upgraded units never receive the civ bonus.
        //! The cascade also completes researches the civ can never use (yamato armored elephants).
        switch (this->PlayerAge[i]) {
        case 1:
            player->rev_tech(0x19);
            break;
        case 2:
            player->rev_tech(0x17);
            break;
        case 3:
            player->rev_tech(0x18);
            break;
        case 4:
            player->rev_tech(1);
            break;
        }
    }

    if ((float)this->DisabledTechnology[i][14] == 0.0f) {
        player->attributes[48] = 1.0f;
    }
}
