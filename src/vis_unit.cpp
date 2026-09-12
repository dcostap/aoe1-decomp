
#include "../include/vis_unit.h"
#include "../include/map.h"
#include "../include/world.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/com_obj.h"
#include "../include/visible.h"
#include "../include/game_globals.h"
#include <stdlib.h>
#include <string.h>

extern float DAT_005776c8;
extern double DAT_005776d0;
extern double DAT_005776d8;
extern void rge_read(int handle, void* buffer, int size);
extern void rge_write(int handle, void* buffer, int size);

Visible_Unit_Manager::Visible_Unit_Manager(int player_count, int category_count)
{
    int i;

    this->Player_Count = player_count;
    this->Category_Count = category_count + 1;
    this->distanceTable = 0;
    this->PlayerDataPtrs =
        (VISIBLE_UNIT_PTR**)calloc(player_count, 4);

    for (i = 0; i < this->Player_Count; i++) {
        this->PlayerDataPtrs[i] =
            (VISIBLE_UNIT_PTR*)calloc(this->Category_Count, 8);
        VISIBLE_UNIT_PTR* row = this->PlayerDataPtrs[i];
        for (int j = 0; j < this->Category_Count; j++) {
            row[j].list_size = 0x20;
            row[j].used = 0;
            row[j].unit_list =
                (VISIBLE_UNIT_REC*)calloc(0x20, 8);
        }
    }

    for (i = 0; i < 5; i++) {
        this->Return_Buffer[i] =
            (VISIBLE_UNIT_REC*)malloc(0x800);
        VisibleUnitList[i] = this->Return_Buffer[i];
        VisibleUnitList_Size[i] = 0;
    }

    this->Build_Distance_Table();
    VisibleUnitManager = this;
}

Visible_Unit_Manager::~Visible_Unit_Manager()
{
    int i;

    if (this->PlayerDataPtrs != 0) {
        for (i = 0; i < this->Player_Count; i++) {
            VISIBLE_UNIT_PTR* player_data = this->PlayerDataPtrs[i];
            if (player_data != 0) {
                for (int j = 0; j < this->Category_Count; j++) {
                    if (player_data[j].unit_list != 0) {
                        free(player_data[j].unit_list);
                    }
                }
                free(player_data);
            }
        }
        free(this->PlayerDataPtrs);
    }

    for (i = 0; i < 5; i++) {
        if (this->Return_Buffer[i] != 0) {
            free(this->Return_Buffer[i]);
        }
        VisibleUnitList[i] = 0;
        VisibleUnitList_Size[i] = 0;
    }

    if (this->distanceTable != 0) {
        free(this->distanceTable);
    }
    VisibleUnitManager = 0;
}

void Visible_Unit_Manager::Build_Distance_Table()
{
    if (this->distanceTable != 0) {
        free(this->distanceTable);
    }

    unsigned char* table = (unsigned char*)malloc(0x100);
    this->distanceTable = table;
    for (int i = 0; i < 0x100; i++) {
        table[i] = 0xff;
    }

    int distance = 0;
    LOSTBL** offsets = NormalLOS;
    do {
        LOSTBL* entry = *offsets;
        int row = entry->y;
        while (row != 999) {
            int first = entry->x1;
            int last = entry->x2;
            if (row >= 0 && row <= 15) {
                if (first < 0) {
                    first = 0;
                }
                if (last > 15) {
                    last = 15;
                }
                int index = (row << 4) + first;
                if (first <= last) {
                    int count = last - first + 1;
                    do {
                        unsigned char* current_table = this->distanceTable;
                        if (current_table[index] == 0xff) {
                            current_table[index] = (unsigned char)distance;
                        }
                        index++;
                        count--;
                    } while (count);
                }
            }
            ++entry;
            row = entry->y;
        }
        offsets++;
        distance++;
    } while (offsets <= &NormalLOS[16]);
}

void Visible_Unit_Manager::Update_Unit_Info(
    int object_id, int player, int x, int y, int category,
    unsigned long old_mask, unsigned long new_mask,
    VISIBLE_UNIT_REC** refs)
{
    unsigned long mask = (new_mask ^ old_mask) & 0xffff;

    if (category < this->Category_Count) {
        int r = 0;
        if (this->Player_Count > 0) {
            int i = 0x194 - (int)refs;

            do {
                if (mask == 0) {
                    return;
                }

                if ((mask & 1) == 1) {
                    VISIBLE_UNIT_PTR* list =
                        this->PlayerDataPtrs[r] + category;

                    if ((new_mask & 1) == 1) {
                        if (list->used == list->list_size) {
                            short list_size = list->list_size;
                            VISIBLE_UNIT_REC* new_list =
                                (VISIBLE_UNIT_REC*)calloc(list_size * 2, 8);
                            memcpy(new_list, list->unit_list,
                                   list_size * 8);
                            free(list->unit_list);
                            list->unit_list = new_list;
                            list->list_size = list_size * 2;

                            VISIBLE_UNIT_REC* record = new_list;
                            int j = 0;
                            while (j < list->used) {
                                RGE_Static_Object* object =
                                    VIS_UNIT_objectsValue[record->object_id];
                                if (object != 0) {
                                    *(VISIBLE_UNIT_REC **)(
                                        (int)object + i + (int)refs) = record;
                                }
                                ++j;
                                ++record;
                            }
                        }

                        int index = (int)list->used;
                        VISIBLE_UNIT_REC* record =
                            list->unit_list + index;
                        record->distance = 0;
                        record->object_id = object_id;
                        record->player = (unsigned char)player;
                        record->pos_x = (unsigned char)x;
                        record->pos_y = (unsigned char)y;
                        list->used++;
                        *refs = record;
                    } else {
                        VISIBLE_UNIT_REC* record = *refs;
                        VISIBLE_UNIT_REC* last_record =
                            list->unit_list + list->used - 1;

                        if (last_record != record) {
                            *record = *last_record;

                            RGE_Static_Object* object =
                                VIS_UNIT_objectsValue[record->object_id];
                            if (object != 0) {
                                *(VISIBLE_UNIT_REC **)(
                                    (int)object + i + (int)refs) = record;
                            }
                        }

                        *refs = 0;
                        list->used--;
                    }
                }

                ++refs;
                new_mask >>= 1;
                mask >>= 1;
                ++r;
            } while (r < this->Player_Count);
        }
    }
}

int Visible_Unit_Manager::GetVisibleUnits(
    int x, int y, int distance, int player,
    int* categories, int category_count, int* player_map)
{
    int found = 0;

    if (category_count <= 0 || player >= this->Player_Count) {
        return 0;
    }
    if (distance > 15) {
        distance = 15;
    }

    VISIBLE_UNIT_PTR* player_data = this->PlayerDataPtrs[player];
    unsigned char* distance_table = this->distanceTable;

    VisibleUnitList_Size[0] = 0;
    VisibleUnitList_Size[1] = 0;
    VisibleUnitList_Size[2] = 0;
    VisibleUnitList_Size[3] = 0;
    VisibleUnitList_Size[4] = 0;

    int min_x = x - distance;
    int max_x = x + distance;
    int min_y = y - distance;
    int max_y = y + distance;

    do {
        VISIBLE_UNIT_PTR* bucket = &player_data[*categories++];
        VISIBLE_UNIT_REC* record = bucket->unit_list;
        int count = *(int*)&bucket->used & 0xffff;

        for (; count != 0; record++, count--) {
            int record_x = record->pos_x;
            if (record_x > max_x) {
                continue;
            }

            int dx;
            if (record_x < x) {
                if (record_x < min_x) {
                    continue;
                }
                dx = x - record_x;
            } else {
                dx = record_x - x;
            }

            int record_y = record->pos_y;
            if (record_y > max_y) {
                continue;
            }

            int dy;
            if (record_y < y) {
                if (record_y < min_y) {
                    continue;
                }
                dy = y - record_y;
            } else {
                dy = record_y - y;
            }

            int unit_distance =
                distance_table[(dy & 15) * 16 + (dx & 15)];
            if (unit_distance > distance) {
                continue;
            }

            int list = player_map[record->player];
            int list_size = VisibleUnitList_Size[list];
            if (list_size >= 0x100) {
                continue;
            }

            VISIBLE_UNIT_REC* result =
                &VisibleUnitList[list][list_size];
            VisibleUnitList_Size[list] = list_size + 1;
            VISIBLE_UNIT_REC saved = *record;
            saved.distance = (unsigned char)unit_distance;
            found++;
            *result = saved;
        }
        category_count--;
    } while (category_count != 0);

    return found;
}
Visible_Resource_Manager::Visible_Resource_Manager(
    RGE_Player* owner, int count)
{
    this->num_visible_resource_lists = count;
    if (count > 0) {
        this->VR_List =
            (VISIBLE_RESOURCE_REC**)calloc(count, 4);
        this->VR_ListSize =
            (int*)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListUsed =
            (int*)calloc(this->num_visible_resource_lists, 4);
        int i = 0;
        if (this->num_visible_resource_lists > 0) {
            do {
                this->VR_List[i] =
                    (VISIBLE_RESOURCE_REC*)malloc(0x100);
                this->VR_ListSize[i] = 0x20;
                this->VR_ListUsed[i] = 0;
                i++;
            } while (i < this->num_visible_resource_lists);
        }
    } else {
        this->VR_List = 0;
        this->VR_ListSize = 0;
        this->VR_ListUsed = 0;
    }
    this->owner = owner;
}

Visible_Resource_Manager::Visible_Resource_Manager(
    int handle, RGE_Player* owner)
{
    if (save_game_version >= DAT_005776c8) {
        rge_read(handle, &this->num_visible_resource_lists, 4);
    } else {
        this->num_visible_resource_lists = 5;
    }

    if (this->num_visible_resource_lists > 0) {
        this->VR_List =
            (VISIBLE_RESOURCE_REC**)calloc(
                this->num_visible_resource_lists, 4);
        this->VR_ListSize =
            (int*)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListUsed =
            (int*)calloc(this->num_visible_resource_lists, 4);
        int i = 0;
        if (this->num_visible_resource_lists > 0) {
            do {
                rge_read(handle, this->VR_ListSize + i, 4);
                rge_read(handle, this->VR_ListUsed + i, 4);
                this->VR_List[i] =
                    (VISIBLE_RESOURCE_REC*)malloc(
                        this->VR_ListSize[i] << 3);
                i++;
            } while (i < this->num_visible_resource_lists);
        }

        int saved_handle = handle;
        i = 0;
        if (this->num_visible_resource_lists > 0) {
            do {
                if (this->VR_ListUsed[i] > 0) {
                    rge_read(saved_handle, this->VR_List[i],
                             this->VR_ListUsed[i] * 8);
                }
                i++;
            } while (i < this->num_visible_resource_lists);
        }
    } else {
        this->VR_List = 0;
        this->VR_ListSize = 0;
        this->VR_ListUsed = 0;
    }
    this->owner = owner;
}

Visible_Resource_Manager::~Visible_Resource_Manager()
{
    int i;

    for (i = 0; i < this->num_visible_resource_lists; i++) {
        VISIBLE_RESOURCE_REC* list = this->VR_List[i];
        if (list) {
            free(list);
        }
    }
    if (this->VR_List) {
        free(this->VR_List);
    }
    if (this->VR_ListSize) {
        free(this->VR_ListSize);
    }
    if (this->VR_ListUsed) {
        free(this->VR_ListUsed);
    }
}

void Visible_Resource_Manager::save(int handle)
{
    rge_write(handle, &this->num_visible_resource_lists, 4);
    int i = 0;
    if (this->num_visible_resource_lists > 0) {
        do {
            rge_write(handle, this->VR_ListSize + i, 4);
            rge_write(handle, this->VR_ListUsed + i, 4);
            i++;
        } while (i < this->num_visible_resource_lists);
    }

    i = 0;
    if (this->num_visible_resource_lists > 0) {
        do {
            if (this->VR_ListUsed[i] > 0) {
                rge_write(handle, this->VR_List[i],
                          this->VR_ListUsed[i] << 3);
            }
            i++;
        } while (i < this->num_visible_resource_lists);
    }
}

void Visible_Resource_Manager::Process_New_Tiles(RGE_Tile_List* list)
{
    int size;
    RGE_Tile_List_Node* tile_list;

    list->get_list_info(tile_list, size);
    if (size > 0 && this->num_visible_resource_lists != 0) {
        RGE_Tile** rows = this->owner->world->map->map_row_offset;
        for (int i = 0; i < size; i++, tile_list++) {
            RGE_Tile_List_Node* current_tile = tile_list;
            RGE_Tile* tile =
                &rows[current_tile->row][current_tile->col];
            int count = tile->objects.number_of_objects;
            if (count > 0) {
                RGE_Object_Node* node = tile->objects.list;
                while (node != 0 && count > 0) {
                    RGE_Static_Object* object = node->node;
                    if (object != 0) {
                        RGE_Master_Static_Object* master =
                            object->master_obj;
                        if (master->track_as_resource) {
                            int id = object->id;
                            this->AddResource(id, master->resource_group);
                        }
                    }
                    node = node->next;
                    count--;
                }
            }
        }
    }
}

void Visible_Resource_Manager::AddResource(int object_id, int type)
{
    RGE_Static_Object* object;
    int n;

    if (this->num_visible_resource_lists != 0) {
        object = VIS_UNIT_objectsValue[object_id];
        if (object != 0) {
            n = this->VR_ListSize[type];
            if (this->VR_ListUsed[type] == n) {
                n = n + n;
                VISIBLE_RESOURCE_REC* new_list =
                    (VISIBLE_RESOURCE_REC*)malloc(n * 8);
                memcpy(new_list, this->VR_List[type],
                       this->VR_ListSize[type] << 3);
                free(this->VR_List[type]);
                this->VR_List[type] = new_list;
                this->VR_ListSize[type] = n;
            }

            VISIBLE_RESOURCE_REC* record =
                this->VR_List[type] + this->VR_ListUsed[type];
            int x = object->world_x;
            int y = object->world_y;
            record->object_id = object_id;
            record->distance = 0;
            record->zone = 0;
            record->pos_x = (unsigned char)x;
            record->pos_y = (unsigned char)y;
            this->VR_ListUsed[type]++;
        }
    }
}

int Visible_Resource_Manager::Remove_Resource(int object_id, int type)
{
    if (this->num_visible_resource_lists == 0) {
        return 0;
    }

    int last = this->VR_ListUsed[type];
    if (last == 0) {
        return 0;
    }

    --last;
    VISIBLE_RESOURCE_REC* list = this->VR_List[type];

    for (int i = 0; i <= last; i++) {
        if (list[i].object_id == object_id) {
            if (i < last) {
                list[i] = list[last];
            }
            this->VR_ListUsed[type]--;
            return 1;
        }
    }

    return 0;
}

VISIBLE_RESOURCE_REC* Visible_Resource_Manager::Get_Closest_Resource(
    int Xpos, int Ypos, int Zone, int ResType, int* excList, int elSize)
{
    if (ResType >= 0 && this->num_visible_resource_lists != 0 &&
        ResType < this->num_visible_resource_lists) {
        int count = this->VR_ListUsed[ResType];
        if (count != 0) {
            int bestdist = 9999;
            VISIBLE_RESOURCE_REC* c = 0;
            VISIBLE_RESOURCE_REC* record = this->VR_List[ResType];
            while (count > 0) {
                int dx;
                int dy;
                int Reject = 0;
                int record_x = record->pos_x;
                int record_y = record->pos_y;
                if (record_x > Xpos) {
                    dx = record_x - Xpos;
                } else {
                    dx = Xpos - record_x;
                }
                if (record_y > Ypos) {
                    dy = record_y - Ypos;
                } else {
                    dy = Ypos - record_y;
                }

                int distance;
                if (dx > dy) {
                    distance =
                        (dx - (int)(DAT_005776d8 -
                                    dy * DAT_005776d0)) - dy;
                } else {
                    distance =
                        (dy - (int)(DAT_005776d8 -
                                    dx * DAT_005776d0)) - dx;
                }

                if (distance < bestdist) {
                    if (elSize && excList) {
                        int i = 0;
                        while (i < elSize) {
                            if (record->object_id == excList[i]) {
                                Reject = 1;
                                break;
                            }
                            i++;
                        }
                    }
                    if (!Reject) {
                        c = record;
                        bestdist = distance;
                    }
                }
                record++;
                count--;
            }
            if (bestdist > 0xff) {
                bestdist = 0xff;
            }
            if (c != 0) {
                c->distance = (unsigned char)bestdist;
            }
            return c;
        }
    }
    return 0;
}
