#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Player.h"

#include <stdlib.h>

static void rge_doppleganger_expand_allocations(RGE_Doppleganger_Creator* creator, int grow_by) {
    // Source of truth: dpl_obj.cpp.decomp @ 0x00442540
    int new_allocated_size = creator->allocated_size + grow_by;
    creator->allocated_size = new_allocated_size;

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

    for (int index = 0; index < creator->active_size; index++) {
        new_objects[index] = creator->Objects[index];
        new_map_addresses[index] = creator->Map_Addresses[index];
        new_last_map_values[index] = creator->Last_Map_Value[index];
        new_object_ids[index] = creator->Object_ids[index];
    }

    free(creator->Objects);
    free(creator->Map_Addresses);
    free(creator->Last_Map_Value);
    free(creator->Object_ids);

    creator->Objects = new_objects;
    creator->Map_Addresses = new_map_addresses;
    creator->Last_Map_Value = new_last_map_values;
    creator->Object_ids = new_object_ids;
}

int RGE_Doppleganger_Creator::add_doppleganger_check(RGE_Static_Object* param_1, ulong* param_2) {
    // Source of truth: dpl_obj.cpp.decomp @ 0x004421F0
    if (this->allocated_size <= this->active_size) {
        rge_doppleganger_expand_allocations(this, 0x1E);
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
