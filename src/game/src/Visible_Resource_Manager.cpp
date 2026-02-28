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
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

static int vis_unit_ftol(double value) {
    return (int)(long)value;
}

Visible_Resource_Manager::Visible_Resource_Manager(RGE_Player* param_1, int param_2) {
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BB30
    this->num_visible_resource_lists = param_2;
    if (param_2 < 1) {
        this->VR_List = nullptr;
        this->VR_ListSize = nullptr;
        this->VR_ListUsed = nullptr;
    } else {
        this->VR_List = (VISIBLE_RESOURCE_REC**)calloc(param_2, 4);
        this->VR_ListSize = (int*)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListUsed = (int*)calloc(this->num_visible_resource_lists, 4);
        for (int i = 0; i < this->num_visible_resource_lists; ++i) {
            this->VR_List[i] = (VISIBLE_RESOURCE_REC*)malloc(0x100);
            this->VR_ListSize[i] = 0x20;
            this->VR_ListUsed[i] = 0;
        }
    }
    this->owner = param_1;
}

Visible_Resource_Manager::Visible_Resource_Manager(int param_1, RGE_Player* param_2) {
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BBE0
    if (save_game_version < 7.11f) {
        this->num_visible_resource_lists = 5;
    } else {
        rge_read(param_1, &this->num_visible_resource_lists, 4);
    }

    if (this->num_visible_resource_lists < 1) {
        this->VR_List = nullptr;
        this->VR_ListSize = nullptr;
        this->VR_ListUsed = nullptr;
    } else {
        this->VR_List = (VISIBLE_RESOURCE_REC**)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListSize = (int*)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListUsed = (int*)calloc(this->num_visible_resource_lists, 4);

        for (int i = 0; i < this->num_visible_resource_lists; ++i) {
            rge_read(param_1, this->VR_ListSize + i, 4);
            rge_read(param_1, this->VR_ListUsed + i, 4);
            this->VR_List[i] = (VISIBLE_RESOURCE_REC*)malloc(this->VR_ListSize[i] << 3);
        }

        for (int i = 0; i < this->num_visible_resource_lists; ++i) {
            if (this->VR_ListUsed[i] > 0) {
                rge_read(param_1, this->VR_List[i], this->VR_ListUsed[i] * 8);
            }
        }
    }

    this->owner = param_2;
}

Visible_Resource_Manager::~Visible_Resource_Manager() {
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BD10
    for (int i = 0; i < this->num_visible_resource_lists; ++i) {
        if (this->VR_List[i] != nullptr) {
            free(this->VR_List[i]);
        }
    }
    if (this->VR_List != nullptr) {
        free(this->VR_List);
    }
    if (this->VR_ListSize != nullptr) {
        free(this->VR_ListSize);
    }
    if (this->VR_ListUsed != nullptr) {
        free(this->VR_ListUsed);
    }
}

void Visible_Resource_Manager::save(int param_1) {
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BD70
    rge_write(param_1, &this->num_visible_resource_lists, 4);
    for (int i = 0; i < this->num_visible_resource_lists; ++i) {
        rge_write(param_1, this->VR_ListSize + i, 4);
        rge_write(param_1, this->VR_ListUsed + i, 4);
    }
    for (int i = 0; i < this->num_visible_resource_lists; ++i) {
        if (this->VR_ListUsed[i] > 0) {
            rge_write(param_1, this->VR_List[i], this->VR_ListUsed[i] << 3);
        }
    }
}

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
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BED0
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
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053BFD0
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

VISIBLE_RESOURCE_REC* Visible_Resource_Manager::Get_Closest_Resource(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6) {
    // Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053C050
    // TODO: Confirm DAT_005776d0 / DAT_005776d8 exact constants from ASM-backed data section.
    (void)param_3;
    if (param_4 < 0 || this->num_visible_resource_lists == 0 || param_4 >= this->num_visible_resource_lists) {
        return nullptr;
    }

    int count = this->VR_ListUsed[param_4];
    if (count <= 0) {
        return nullptr;
    }

    VISIBLE_RESOURCE_REC* records = this->VR_List[param_4];
    int best_score = 9999;
    VISIBLE_RESOURCE_REC* best = nullptr;
    for (int i = 0; i < count; ++i) {
        VISIBLE_RESOURCE_REC* rec = &records[i];
        int xd = (int)rec->pos_x;
        int yd = (int)rec->pos_y;

        int dx = xd - param_1;
        if (dx < 0) {
            dx = -dx;
        }
        int dy = yd - param_2;
        if (dy < 0) {
            dy = -dy;
        }

        int score = dy;
        if (dx > dy) {
            score = (dx - vis_unit_ftol(0.85 - ((double)dy * 0.66))) - dy;
        } else {
            score = (dy - vis_unit_ftol(0.85 - ((double)dx * 0.66))) - dx;
        }

        if (score < best_score) {
            int rejected = 0;
            if (param_6 != 0 && param_5 != nullptr) {
                for (int j = 0; j < param_6; ++j) {
                    if (rec->object_id == param_5[j]) {
                        rejected = 1;
                        break;
                    }
                }
            }
            if (rejected == 0) {
                best_score = score;
                best = rec;
            }
        }
    }

    if (best_score > 0xFF) {
        best_score = 0xFF;
    }
    if (best != nullptr) {
        best->distance = (uchar)best_score;
    }
    return best;
}
