#include <string.h>

#include "../include/tscenaro.h"

extern void rge_read_uncompressed(int file, void* data, int size);
extern void rge_write_uncompressed(int file, void* data, int size);
extern void rge_read(int file, void* data, int size);
extern "C" void __cdecl rge_write(int file, void* data, int size);

extern const float DAT_00577318;
extern const float DAT_0057731c;
extern const float DAT_00577320;
extern const float DAT_00577324;
extern const float DAT_00577328;
extern const float DAT_0057732c;

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* scenario)
    : RGE_Scenario_Header(scenario) {
    any_sp_victory = scenario->any_sp_victory();
    active_player_count = scenario->active_player_count();
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int file)
    : RGE_Scenario_Header(file) {
    any_sp_victory = 0;
    active_player_count = 0;
    if (error_code == 0) {
        rge_read_uncompressed(file, &any_sp_victory, 4);
        rge_read_uncompressed(file, &active_player_count, 4);
    }
}

long TRIBE_Scenario_Header::get_size() {
    return RGE_Scenario_Header::get_size() + 8;
}

void TRIBE_Scenario_Header::save(int file) {
    RGE_Scenario_Header::save(file);
    rge_write_uncompressed(file, &this->any_sp_victory, 4);
    rge_write_uncompressed(file, &this->active_player_count, 4);
}

T_Scenario::T_Scenario(RGE_Game_World* world)
    : RGE_Scenario(world) {
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

T_Scenario::T_Scenario(int file, RGE_Game_World* world) : RGE_Scenario(file, world) {
    int dummy = 0;
    InitializeVictoryValues();
    InitializeFriendlinessValues();
    ClearDisabledTechnologies();

    int old_version;
    if (version <= DAT_00577318) {
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
        for (i = 0; i < 16; ++i) rge_read(file, player_name[i], 0x100);
    }

    if (version > DAT_00577318) {
        int i;
        for (i = 0; i < 16; ++i) rge_read(file, &player_info[i], 0x10);
    } else {
        int i;
        for (i = 0; i < 16; ++i) {
            rge_read(file, &pl_active[i], 4);
            rge_read(file, &player_info[i], 0x10);
            rge_read(file, &pl_type[i], 4);
            rge_read(file, &pl_civilization[i], 4);
            rge_read(file, &player_posture[i], 4);
        }
    }

    if (version > DAT_0057731c) {
        rge_read(file, &dummy, 4);
    }

    rge_read(file, &victory, 0x18);
    rge_read(file, &victory_all_flag, 4);

    if (version >= DAT_00577318) {
        rge_read(file, &mp_victory_type, 4);
        rge_read(file, &victory_score, 4);
        rge_read(file, &victory_time, 4);
    } else {
        mp_victory_type = 4;
        victory_score = 900;
        victory_time = 9000;
    }

    rge_read(file, Opponent, 0x400);
    for (int p = 0; p < 16; ++p) rge_read(file, player_data[p], 0x2d0);

    if (version > DAT_0057731c) rge_read(file, &dummy, 4);

    if (*(int*)&version == 0x3f8147ae) {
        for (int j = 0; j < 16; ++j) rge_read(file, AlliedVictory, 0x40);
    }
    if (version >= DAT_0057731c) rge_read(file, AlliedVictory, 0x40);
    if (version > DAT_00577320) rge_read(file, DisabledTechnology, 0x500);

    if (version > DAT_00577324) {
        if (version < DAT_00577328) {
            rge_read(file, ScenarioOptions, 4);
            ScenarioOptions[1] = 0;
            ScenarioOptions[2] = 0;
        } else {
            rge_read(file, ScenarioOptions, 0x0c);
        }
    }
    if (version > DAT_0057732c) rge_read(file, PlayerAge, 0x40);
    if (version > DAT_0057731c) rge_read(file, &dummy, 4);

    victory.MP_Conquest = victory_conquest;
}

void T_Scenario::save(int file) {
    int checksum;
    char* p;
    int i;

    checksum = -99;
    WriteDisabledTechnologiesToMainSystem();
    RGE_Scenario::save(file);

    p = (char*)this + 0x1990;
    for (i = 0x10; i != 0; --i) {
        rge_write(file, p, 0x10);
        p += 0x10;
    }

    rge_write(file, &checksum, 4);
    rge_write(file, (char*)this + 0x1A90, 0x18);
    rge_write(file, (char*)this + 0x4BE8, 4);
    rge_write(file, (char*)this + 0x5140, 4);
    rge_write(file, (char*)this + 0x5144, 4);
    rge_write(file, (char*)this + 0x5148, 4);
    rge_write(file, (char*)this + 0x47A8, 0x400);

    p = (char*)this + 0x1AA8;
    for (i = 0x10; i != 0; --i) {
        rge_write(file, p, 0x2D0);
        p += 0x2D0;
    }

    rge_write(file, &checksum, 4);
    rge_write(file, (char*)this + 0x4BA8, 0x40);
    rge_write(file, (char*)this + 0x4BF4, 0x500);
    rge_write(file, (char*)this + 0x50F4, 0x0C);
    rge_write(file, (char*)this + 0x5100, 0x40);
    rge_write(file, &checksum, 4);
}

void T_Scenario::InitializePlayerValues()
{
    for (int i = 0; i < 16; ++i) {
        Player_Start_Info* info = &this->player_info[i];
        memset(info, 0, sizeof(*info));

        this->pl_active[i] = 0;
        info->Gold = 0;
        info->Wood = 200;
        info->Food = 200;
        info->Stone = 150;

        this->pl_type[i] = 0;
        this->pl_civilization[i] = i + 1;
        this->player_posture[i] = 4;
        this->AlliedVictory[i] = 0;
        this->PlayerAge[i] = 0;
    }

    this->pl_type[0] = 1;
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

void T_Scenario::Set_victory_all_flag(int v) {
    if (v < 0) v = 0;
    if (v > 1) v = 1;
    this->victory_all_flag = v;
}

int T_Scenario::Get_victory_all_flag() {
    return this->victory_all_flag;
}

void T_Scenario::SetMPVictory(int v) {
    this->mp_victory_type = v;
    if (v != 4) this->victory_conquest = 1;
}

int T_Scenario::GetMPVictory() {
    return this->mp_victory_type;
}

void T_Scenario::SetVictoryScore(int v) {
    this->victory_score = v;
}

int T_Scenario::GetVictoryScore() {
    return this->victory_score;
}

void T_Scenario::SetVictoryTime(int v) {
    this->victory_time = v;
}

int T_Scenario::GetVictoryTime() {
    return this->victory_time;
}

void T_Scenario::SetSPWhich(int v) {
    if (v < 0) v = 0;
    if (v > 16) v = 15;
    this->which_player = v;
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
    for (i = 0; i < 0xB40; i++) {
        victory_values[i] = 0;
    }
}

void T_Scenario::ClearSPVictoryCondition(int sp_index) {
    memset(&this->sp_victory[this->which_player][sp_index], 0, sizeof(SP_Victory_Info));
}

void T_Scenario::InitializeFriendlinessValues() {
    for (int i = 0; i < 256; i++) this->Opponent[0].Attitude[i] = 3;
}

void T_Scenario::Set_player_attitude(int player, int target, int attitude) {
    if (((attitude == 1) || (attitude == 3) || (attitude == 0)) &&
        ((player >= 0) && (player < 0x10) && (target >= 0) && (target < 0x10))) {
        this->Opponent[player].Attitude[target] = attitude;
    }
}

int T_Scenario::Get_player_attitude(int param_1, int param_2) {
    if (param_1 < 0 || param_1 >= 16)
        return -1;
    if (param_2 < 0 || param_2 >= 16)
        return -1;
    return this->Opponent[param_1].Attitude[param_2];
}

void T_Scenario::Set_player_Gold(int param_1, int param_2) {
    if (param_1 < 0 || param_1 >= 16)
        return;
    this->player_info[param_1].Gold = param_2;
}

void T_Scenario::Set_player_Wood(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->player_info[index].Wood = val;
}

void T_Scenario::Set_player_Food(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->player_info[index].Food = val;
}

void T_Scenario::Set_player_Stone(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->player_info[index].Stone = val;
}

void T_Scenario::Set_player_Info(int player, Player_Start_Info* info) {
    if ((player >= 0) && (player < 16)) {
        this->player_info[player] = *info;
    }
}

void T_Scenario::Set_Multi_Conquest(int param) {
    if (param) {
        this->victory.MP_Conquest = 1;
        this->Set_conquest_victory(1);
    } else {
        this->victory.MP_Conquest = 0;
        this->Set_conquest_victory(0);
    }
}

void T_Scenario::Set_Multi_Ruins(int v) {
    this->victory.MP_Ruins = v;
}

void T_Scenario::Set_Multi_Artifacts(int v) {
    this->victory.MP_Artifacts = v;
}

void T_Scenario::Set_Multi_Discoveries(int v) {
    this->victory.MP_Discoveries = v;
}

void T_Scenario::Set_Multi_Exploration(int v) {
    this->victory.MP_Exploration = v;
}

void T_Scenario::Set_Multi_Gold(int v) {
    this->victory.MP_Gold = v;
}

void T_Scenario::SetSPRectangle(int sp_index, float x1, float y1, float x2, float y2) {
    this->sp_victory[this->which_player][sp_index].x1 = x1;
    this->sp_victory[this->which_player][sp_index].y1 = y1;
    this->sp_victory[this->which_player][sp_index].x2 = x2;
    this->sp_victory[this->which_player][sp_index].y2 = y2;
}

void T_Scenario::SetSPObjectType(int sp_index, int value) {
    this->sp_victory[this->which_player][sp_index].ObjType = value;
}

void T_Scenario::SetSPPlayerID(int sp_index, int value) {
    this->sp_victory[this->which_player][sp_index].PlayerID = value;
}

void T_Scenario::SetSPAllFlag(int sp_index, int value) {
    this->sp_victory[this->which_player][sp_index].AllFlag = value;
}

void T_Scenario::SetSPAttribType(int sp_index, int value) {
    this->sp_victory[this->which_player][sp_index].AttribType = value;
}

void T_Scenario::SetSPVictoryType(int sp_index, int value) {
    this->sp_victory[this->which_player][sp_index].VictoryType = value;
}

// Accepted drift: VC5 schedules the same independent updates in a different order.
void T_Scenario::SetSPObject(int index, RGE_Static_Object* object) {
    if (object != 0) {
        int object_id = this->get_object_ID(object);
        int result;
        int which_player = this->which_player;
        result = object_id;
        result = result + 1;
        int temp = which_player + which_player * 2;
        int offset = index + temp * 4;
        offset = offset + offset * 2;
        offset = offset + offset * 4;
        this->raw_objects.sp_victory_obj_id[offset] = result;
    }
}

// Accepted drift: VC5 folds the increment into a LEA in the reduced source.
void T_Scenario::SetSPDestObjectID(int index, RGE_Static_Object* object) {
    if (object != 0) {
        int object_id = this->get_object_ID(object);
        int which_player = this->which_player;

        int offset;
        offset = index + (which_player + which_player * 2) * 4;
        offset = offset + offset * 2;
        offset = offset + offset * 4;
        this->raw_dest_objects.sp_victory_dest_obj_id[offset] = object_id + 1;
    }
}

void T_Scenario::SetSPAmount(int sp_index, int value) {
    this->sp_victory[this->which_player][sp_index].Amount = value;
}

void T_Scenario::SetPlayerAlliedVictory(int i, int v) {
    this->AlliedVictory[i] = v;
}

void T_Scenario::SetDisabledTechnology(int param1, int param2, int param3) {
    DisabledTechnology[param1][param2] = param3;
}

void T_Scenario::SetScenarioOption(int i, int v) {
    this->ScenarioOptions[i] = v;
}

void T_Scenario::SetPlayerAge(int i, int v) {
    this->PlayerAge[i] = v;
}

int T_Scenario::Get_player_Gold(int param_1) {
    if (param_1 < 0 || param_1 >= 16)
        return 0;
    return this->player_info[param_1].Gold;
}

int T_Scenario::Get_player_Wood(int param_1) {
    if (param_1 < 0 || param_1 >= 16)
        return 0;
    return this->player_info[param_1].Wood;
}

int T_Scenario::Get_player_Food(int param_1) {
    if (param_1 < 0 || param_1 >= 16)
        return 0;
    return this->player_info[param_1].Food;
}

int T_Scenario::Get_player_Stone(int param_1) {
    if (param_1 < 0 || param_1 >= 16)
        return 0;
    return this->player_info[param_1].Stone;
}

Player_Start_Info* T_Scenario::Get_player_Info(int param_1) {
    if (param_1 < 0 || param_1 >= 16)
        return 0;
    return &this->player_info[param_1];
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

void T_Scenario::GetSPRectangle(int sp_index, float* x1, float* y1, float* x2, float* y2) {
    *x1 = this->sp_victory[this->which_player][sp_index].x1;
    *y1 = this->sp_victory[this->which_player][sp_index].y1;
    *x2 = this->sp_victory[this->which_player][sp_index].x2;
    *y2 = this->sp_victory[this->which_player][sp_index].y2;
}

int T_Scenario::GetSPObjectType(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].ObjType;
}

int T_Scenario::GetSPPlayerID(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].PlayerID;
}

int T_Scenario::GetSPAllFlag(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].AllFlag;
}

int T_Scenario::GetSPAttribType(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].AttribType;
}

int T_Scenario::GetSPAmount(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].Amount;
}

int T_Scenario::GetSPVictoryType(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].VictoryType;
}

RGE_Static_Object* T_Scenario::GetSPDestObjectID(int sp_index) {
    return this->get_object_pointer(this->sp_victory[this->which_player][sp_index].dest_obj_ID);
}

RGE_Static_Object* T_Scenario::GetSPObject(int sp_index) {
    return this->get_object_pointer(this->sp_victory[this->which_player][sp_index].obj_ID);
}

int T_Scenario::GetPlayerAlliedVictory(int idx) {
    return this->AlliedVictory[idx];
}

int T_Scenario::GetDisabledTechnology(int player, int index) {
    return this->DisabledTechnology[player][index];
}

int T_Scenario::GetScenarioOption(int idx) {
    return this->ScenarioOptions[idx];
}

int T_Scenario::GetPlayerAge(int idx) {
    return this->PlayerAge[idx];
}

void T_Scenario::update() {
    this->time_line->update();
}

void T_Scenario::SaveAttributesIntoPlayers() {
    int player = 1;
    int other;
    if (player < this->world->player_num) {
        do {
            this->world->players[player]->new_attribute_num(
                0, (float)this->Get_player_Food(player - 1));
            this->world->players[player]->new_attribute_num(
                2, (float)this->Get_player_Stone(player - 1));
            this->world->players[player]->new_attribute_num(
                3, (float)this->Get_player_Gold(player - 1));
            this->world->players[player]->new_attribute_num(
                1, (float)this->Get_player_Wood(player - 1));

            other = 1;
            if (other < this->world->player_num) {
                do {
                    if (other != player) {
                        this->world->players[player]->set_relation(
                            other,
                            (unsigned char)this->Opponent[player - 1].Attitude[other - 1]);
                    }
                    ++other;
                } while (other < this->world->player_num);
            }

            this->world->players[player]->set_allied_victory(
                (unsigned char)this->AlliedVictory[player - 1]);
            ++player;
        } while (player < this->world->player_num);
    }
}

void T_Scenario::Save_victory_conditions_into_players(int save_attrs) {
    if (save_attrs != 0) {
        this->SaveAttributesIntoPlayers();
    }

    RGE_Game_World* world = this->world;
    int one = 1;
    for (int player = one; player < (int)world->player_num; ++player) {
        world->players[player]->victory->destroy_all();
        world = this->world;
    }

    if (this->mp_victory_type == 4) {
        if (this->victory_all_flag != 0) {
            world = this->world;
            for (int player = one; player < (int)world->player_num; ++player) {
                RGE_Victory_Conditions* conditions = world->players[player]->victory;
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
                RGE_Victory_Conditions* conditions = world->players[player]->victory;
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

    int row = 0;
    world = this->world;
    if ((int)world->player_num - 1 <= 0) {
        return;
    }

    save_attrs = 0x72;
    do {
        RGE_Victory_Conditions* conditions =
            this->world->players[row + 1]->victory;
        int condition_index = 0;
        do {
            SP_Victory_Info* condition = &this->sp_victory[row][condition_index];
            // BINARY NOTE: the shipped dispatch reads the type at -8 from
            // AttribType. Keep this proven packed-record view.
            int type = (&condition->AttribType)[-2];
            if (type != 0) {
                if (type == 4) {
                    int* attribute_field = &condition->AttribType;
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
                    int* attribute_field = &condition->AttribType;
                    conditions->add_attributes(1, *attribute_field,
                                               attribute_field[-1], 0);
                } else if (type == 5) {
                    conditions->add_capture(1,
                                            this->get_object_pointer(condition->obj_ID), 1);
                } else if (type == 3) {
                    if (this->get_object_pointer(condition->dest_obj_ID) != 0) {
                        conditions->add_bring(
                            1,
                            this->get_object_pointer(condition->obj_ID),
                            this->get_object_pointer(condition->dest_obj_ID));
                    } else {
                        conditions->add_bring(
                            1,
                            this->get_object_pointer(condition->obj_ID),
                            this->sp_victory[row][condition_index].x1,
                            condition->y1, condition->x2, condition->y2);
                    }
                } else if (type == 2) {
                    if (condition->x2 > DAT_00577330) {
                        conditions->add_create(
                            1, condition->ObjType, condition->Amount,
                            this->sp_victory[row][condition_index].x1,
                            condition->y1, condition->x2, condition->y2, 0);
                    } else {
                        conditions->add_create(1, condition->ObjType,
                                                condition->Amount, 0);
                    }
                } else if (type == 7) {
                    conditions->add_tech(1, condition->AttribType);
                } else if (type == 1) {
                    int object_type = condition->ObjType;
                    if (object_type != 0 && condition->AllFlag != 0) {
                        conditions->add_destroy(1, object_type,
                                                (RGE_Player*)0);
                    } else {
                        int player_id = condition->PlayerID;
                        if (player_id != 0 && object_type != 0) {
                            conditions->add_destroy(
                                1, object_type, condition->Amount,
                                this->world->players[player_id]);
                        } else if (player_id != 0) {
                            conditions->add_destroy(1,
                                                    this->world->players[player_id]);
                        } else if (this->get_object_pointer(condition->obj_ID) != 0) {
                            conditions->add_destroy(
                                1, this->get_object_pointer(condition->obj_ID));
                        }
                    }
                }
            }
            ++condition_index;
        } while (condition_index < 12);

        save_attrs += 12;
        ++row;
        world = this->world;
    } while (row < (int)world->player_num - 1);
}

void T_Scenario::rehook() {
}

RGE_Static_Object* T_Scenario::get_object_pointer(int index) {
    RGE_Static_Object* result = 0;
    if (index > 0) {
        result = this->world->object(index - 1);
    }
    return result;
}

int T_Scenario::get_object_ID(RGE_Static_Object* obj) {
    return obj->id;
}

// Accepted drift: one independent loop increment is scheduled differently.
void T_Scenario::WriteDisabledTechnologiesToMainSystem()
{
    RGE_Game_World* _w = this->world;
    if (_w == 0)
        return;

    if (_w->player_num <= 1)
        return;

    int i = 1;
    uchar* flags = (uchar*)&this->DisabledTechnology[0][1];
    do {
        TRIBE_Player* player = (TRIBE_Player*)_w->players[i];

        if (this->ScenarioOptions[0] != 0) {
            _w->field_4C->do_effect(100, (RGE_Player*)player);
        }

        player->tech_abling(0x58, flags[-4]);
        player->tech_abling(0x59, flags[0]);
        player->tech_abling(0x5A, flags[4]);
        player->tech_abling(0x5B, flags[8]);
        player->tech_abling(0x5E, flags[0x0C]);
        player->tech_abling(0x5F, flags[0x10]);
        player->tech_abling(0x61, flags[0x14]);
        player->tech_abling(0x62, flags[0x18]);
        player->tech_abling(0x5D, flags[0x1C]);
        player->tech_abling(0x60, flags[0x20]);
        player->tech_abling(0x5C, flags[0x24]);
        player->tech_abling(0x65, flags[0x28]);
        player->tech_abling(0x66, flags[0x2C]);
        player->tech_abling(0x67, flags[0x30]);
        player->tech_abling(0x73, flags[0x34]);
        player->tech_abling(0x74, flags[0x38]);

        flags += 0x50;
        i++;
        _w = this->world;
    } while (i < (int)_w->player_num);
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

void T_Scenario::set_player_tech(TRIBE_Player* player)
{
    int i = player->player_number;
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
        this->world->field_4C->do_effect(100, (RGE_Player*)player);
    }

    if (rge_base_game->prog_mode != 7) {
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
        *(int*)((char*)player->object_50 + 0xC0) = 0x3F800000;
    }
}
