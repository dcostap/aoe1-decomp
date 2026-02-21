#include "../include/Visible_Resource_Manager.h"

#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Tile_List.h"
#include "../include/RGE_Tile_List_Node.h"

#include <stdlib.h>
#include <string.h>

void Visible_Resource_Manager::Process_New_Tiles(RGE_Tile_List* param_1) {
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BE00
    if (param_1 == nullptr) {
        return;
    }

    RGE_Tile_List_Node* tile_offsets = nullptr;
    int size = 0;
    param_1->get_list_info(&tile_offsets, &size);
    if (size <= 0 || this->num_visible_resource_lists == 0) {
        return;
    }
    if (this->owner == nullptr || this->owner->world == nullptr || this->owner->world->map == nullptr ||
        this->owner->world->map->map_row_offset == nullptr) {
        return;
    }

    RGE_Tile** rows = this->owner->world->map->map_row_offset;
    for (int i = 0; i < size; ++i) {
        int row = tile_offsets[i].row;
        int col = tile_offsets[i].col;
        if (row < 0 || col < 0 || row >= this->owner->world->map->map_height || col >= this->owner->world->map->map_width) {
            continue;
        }

        RGE_Tile* tile = &rows[row][col];
        int remaining = (int)tile->objects.number_of_objects;
        RGE_Object_Node* node = tile->objects.list;
        while (node != nullptr && remaining > 0) {
            RGE_Static_Object* obj = node->node;
            if (obj != nullptr && obj->master_obj != nullptr && obj->master_obj->track_as_resource != '\0') {
                this->AddResource((int)obj->id, (int)obj->master_obj->resource_group);
            }
            node = node->next;
            remaining = remaining - 1;
        }
    }
}

void Visible_Resource_Manager::AddResource(int param_1, int param_2) {
    // Source of truth: vis_unit.cpp.decomp @ 0x0053BED0
    if (this->num_visible_resource_lists == 0) {
        return;
    }
    if (param_2 < 0 || param_2 >= this->num_visible_resource_lists) {
        return;
    }
    if (this->owner == nullptr || this->owner->world == nullptr) {
        return;
    }

    RGE_Static_Object* obj = this->owner->world->object(param_1);
    if (obj == nullptr) {
        return;
    }

    int size = this->VR_ListSize[param_2];
    int used = this->VR_ListUsed[param_2];
    if (used == size) {
        int new_size = size * 2;
        if (new_size <= 0) {
            new_size = 1;
        }

        VISIBLE_RESOURCE_REC* new_list = (VISIBLE_RESOURCE_REC*)malloc((size_t)new_size * sizeof(VISIBLE_RESOURCE_REC));
        if (new_list == nullptr) {
            return;
        }
        if (this->VR_List[param_2] != nullptr && size > 0) {
            memcpy(new_list, this->VR_List[param_2], (size_t)size * sizeof(VISIBLE_RESOURCE_REC));
        }
        free(this->VR_List[param_2]);
        this->VR_List[param_2] = new_list;
        this->VR_ListSize[param_2] = new_size;
    }

    VISIBLE_RESOURCE_REC* rec = &this->VR_List[param_2][this->VR_ListUsed[param_2]];
    rec->object_id = param_1;
    rec->distance = 0;
    rec->zone = 0;
    rec->pos_x = (uchar)obj->world_x;
    rec->pos_y = (uchar)obj->world_y;
    this->VR_ListUsed[param_2] = this->VR_ListUsed[param_2] + 1;
}

int Visible_Resource_Manager::Remove_Resource(int param_1, int param_2) {
    // Source of truth: vis_unit.cpp.decomp @ 0x0053BFD0
    if (this->num_visible_resource_lists != 0) {
        if (this->VR_ListUsed[param_2] != 0) {
            int last_index = this->VR_ListUsed[param_2] - 1;
            VISIBLE_RESOURCE_REC* records = this->VR_List[param_2];
            int index = 0;
            VISIBLE_RESOURCE_REC* current = records;
            if (last_index >= 0) {
                do {
                    if (current->object_id == param_1) {
                        if (index < last_index) {
                            records[index].object_id = records[last_index].object_id;
                            VISIBLE_RESOURCE_REC* tail = records + last_index;
                            records[index].distance = tail->distance;
                            records[index].zone = tail->zone;
                            records[index].pos_x = tail->pos_x;
                            records[index].pos_y = tail->pos_y;
                        }
                        this->VR_ListUsed[param_2] = this->VR_ListUsed[param_2] - 1;
                        return 1;
                    }
                    index = index + 1;
                    current = current + 1;
                } while (index <= last_index);
                return 0;
            }
        }
    }

    return 0;
}
