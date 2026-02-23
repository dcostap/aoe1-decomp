#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Player.h"

#include <stdlib.h>

RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(RGE_Player* param_1, int param_2) {
    // Source of truth: dpl_obj.cpp.decomp @ 0x00442100
    this->Objects = (RGE_Static_Object**)calloc((size_t)param_2, 4);
    this->Map_Addresses = (ulong**)calloc((size_t)param_2, 4);
    this->Last_Map_Value = (ulong*)calloc((size_t)param_2, 4);
    this->Object_ids = (int*)calloc((size_t)param_2, 4);
    this->allocated_size = param_2;
    this->active_size = 0;
    this->owner = param_1;
}

RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator() {
    // Source of truth: dpl_obj.cpp.decomp @ 0x00442180
    if (this->Objects != nullptr) {
        free(this->Objects);
        this->Objects = nullptr;
    }
    if (this->Map_Addresses != nullptr) {
        free(this->Map_Addresses);
        this->Map_Addresses = nullptr;
    }
    if (this->Last_Map_Value != nullptr) {
        free(this->Last_Map_Value);
        this->Last_Map_Value = nullptr;
    }
    if (this->Object_ids != nullptr) {
        free(this->Object_ids);
        this->Object_ids = nullptr;
    }
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00442540
void RGE_Doppleganger_Creator::expand_allocations(int param_1) {
    int new_allocated_size = this->allocated_size + param_1;
    this->allocated_size = new_allocated_size;

    RGE_Static_Object** new_objects = (RGE_Static_Object**)calloc((size_t)new_allocated_size, 4);
    ulong** new_map_addresses = (ulong**)calloc((size_t)new_allocated_size, 4);
    ulong* new_last_map_values = (ulong*)calloc((size_t)new_allocated_size, 4);
    int* new_object_ids = (int*)calloc((size_t)new_allocated_size, 4);

    if (new_objects == nullptr || new_map_addresses == nullptr || new_last_map_values == nullptr || new_object_ids == nullptr) {
        free(new_objects);
        free(new_map_addresses);
        free(new_last_map_values);
        free(new_object_ids);
        return;
    }

    for (int index = 0; index < this->active_size; index++) {
        new_objects[index] = this->Objects[index];
        new_map_addresses[index] = this->Map_Addresses[index];
        new_last_map_values[index] = this->Last_Map_Value[index];
        new_object_ids[index] = this->Object_ids[index];
    }

    free(this->Objects);
    free(this->Map_Addresses);
    free(this->Last_Map_Value);
    free(this->Object_ids);

    this->Objects = new_objects;
    this->Map_Addresses = new_map_addresses;
    this->Last_Map_Value = new_last_map_values;
    this->Object_ids = new_object_ids;
}

int RGE_Doppleganger_Creator::add_doppleganger_check(RGE_Static_Object* param_1, ulong* param_2) {
    // Source of truth: dpl_obj.cpp.decomp @ 0x004421F0
    if (this->allocated_size <= this->active_size) {
        this->expand_allocations(0x1E);
        if (this->allocated_size <= this->active_size) {
            return 0;
        }
    }

    if (param_1->owner->id != this->owner->id) {
        return 0;
    }

    int active_count = this->active_size;
    if (active_count > 0) {
        for (int index = 0; index < active_count; index++) {
            if (this->Objects[index] == param_1) {
                return 0;
            }
        }
    }

    this->Objects[active_count] = param_1;
    this->Map_Addresses[this->active_size] = param_2;
    this->Last_Map_Value[this->active_size] = *param_2;
    this->Object_ids[this->active_size] = param_1->id;
    this->active_size = this->active_size + 1;

    return 1;
}

int RGE_Doppleganger_Creator::remove_doppleganger_check(RGE_Static_Object* param_1) {
    // Source of truth: dpl_obj.cpp.decomp @ 0x004422B0
    int active_count = this->active_size;
    if (active_count > 0) {
        for (int index = 0; index < active_count; index++) {
            if (this->Objects[index] == param_1) {
                int last_index = active_count - 1;
                this->active_size = last_index;

                if (index < last_index) {
                    this->Objects[index] = this->Objects[last_index];
                    this->Map_Addresses[index] = this->Map_Addresses[this->active_size];
                    this->Last_Map_Value[index] = this->Last_Map_Value[this->active_size];
                    this->Object_ids[index] = this->Object_ids[this->active_size];
                }

                this->Objects[this->active_size] = nullptr;
                this->Map_Addresses[this->active_size] = nullptr;
                this->Last_Map_Value[this->active_size] = 0;
                this->Object_ids[this->active_size] = 0;

                return 1;
            }
        }

        return 0;
    }

    return 0;
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00442390
void RGE_Doppleganger_Creator::perform_doppleganger_checks() {
    RGE_Static_Object* remove_me = nullptr;

    if (this->active_size > 0) {
        for (int index = 0; index < this->active_size; index++) {
            unsigned long map_value = *this->Map_Addresses[index];
            if (map_value != this->Last_Map_Value[index]) {
                RGE_Static_Object* checked_obj = this->Objects[index];
                if (checked_obj == nullptr ||
                    this->owner->world->object(this->Object_ids[index]) != checked_obj) {
                    remove_me = checked_obj;
                } else {
                    int player_index = 1;
                    unsigned long bitmask = ((map_value ^ this->Last_Map_Value[index]) & this->Last_Map_Value[index]) >> 1 & 0x7FFF;
                    while (bitmask != 0) {
                        if ((bitmask & 1) != 0) {
                            int owner_id = (int)this->owner->id;
                            if (player_index != owner_id) {
                                RGE_Player* target_player = this->owner->world->players[player_index];
                                RGE_Static_Object* source_obj = this->Objects[index];
                                ((RGE_Master_Doppleganger_Object*)target_player->master_objects[0xF3])->make_new_obj(
                                    target_player, source_obj->world_x, source_obj->world_y, source_obj->world_z, source_obj);
                            }
                        }
                        player_index = player_index + 1;
                        bitmask = bitmask >> 1;
                    }
                }
                this->Last_Map_Value[index] = map_value;
            }
        }
        if (remove_me != nullptr) {
            this->remove_doppleganger_check(remove_me);
        }
    }
}
