// VA: 00430680 RGE_Combat_Object::update
// Source: com_obj.cpp lines 589-711
// Attempt log:
// 1: natural reconstruction from packet and nearby enter_obj/destructor patterns; initial layout had an extra world field and shifted post-owner offsets by 4.
// 2: model owner/player as field +0x0C with world at owner+0x3C; codegen within 2 bytes but player pointer was preserved instead of index offset.
// 3: use `> 0` mask test and reload world->players[local_4] at ownership change.

typedef unsigned long ulong;

#define unified_map_offsets ((unsigned long**)0x00886808)

class RGE_Player;
class RGE_Static_Object;
class UnitAIModule;
class Visible_Unit_Manager;

extern "C" Visible_Unit_Manager* VisibleUnitManager;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_update.h"
#endif

unsigned char RGE_Combat_Object::update(void)
{
    long local_4 = -1;

    if (this->attack_timer > 0.0f) {
        this->attack_timer = this->attack_timer - this->owner->world->frame_delta;
        if (this->attack_timer < 0.0f) {
            this->attack_timer = 0.0f;
        }
    }

    unsigned char result = RGE_Action_Object::update();

    int object_id = this->id;
    if (object_id >= 0 && this->inside_obj == 0) {
        int x = (int)this->world_x;
        int y = (int)this->world_y;
        unsigned long new_value = unified_map_offsets[y][x];
        unsigned long old_value = this->Unified_Map_Value;
        this->Unified_Map_Value = new_value;
        if (new_value != old_value) {
            VisibleUnitManager->Update_Unit_Info(object_id,
                                                 (int)this->owner->id,
                                                 x,
                                                 y,
                                                 (int)this->master_obj->object_group,
                                                 old_value,
                                                 new_value,
                                                 this->VUR_Ptrs);
            if (this->capture_flag) {
                RGE_Game_World* world = this->owner->world;
                int player = 1;
                int player_num = world->player_num;
                if (player_num > 1) {
                    int owner_id = this->owner->id;
                    do {
                        if (player != owner_id) {
                            unsigned long mask = 1 << player;
                            if ((new_value & mask) > 0) {
                                local_4 = player;
                                break;
                            }
                        }
                        ++player;
                    } while (player < player_num);
                }
                if (local_4 >= 0) {
                    if (world->players[local_4]->computerPlayer() == 0) {
                        this->change_ownership(this->owner->world->players[local_4]);
                        if (this->capture_flag == 1) {
                            this->capture_flag = 0;
                        }
                    }
                }
            }
        }
    }

    if (this->aiModule != 0) {
        if (this->owner->world->is_player_turn((int)this->owner->id)) {
            this->aiModule->update(this->owner->world->get_accum_time_delta((int)this->owner->id));
        }
    }

    return result;
}
