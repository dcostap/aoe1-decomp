// PDB source module: C:\\msdev\\work\\age1_x1\\vis_unit.cpp.
// Definitions follow the original source order.

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
extern double DAT_005776D0;
extern double DAT_005776D8;
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
    VISIBLE_UNIT_REC** current_refs = refs;

    if (category < this->Category_Count) {
        int p = 0;
        if (this->Player_Count > 0) {
            while (p < this->Player_Count) {
                if (mask == 0) {
                    return;
                }
                if ((mask & 1) == 1) {
                    VISIBLE_UNIT_PTR* bucket =
                        &this->PlayerDataPtrs[p][category];
                    if ((new_mask & 1) == 1) {
                        short size = bucket->list_size;
                        if (bucket->used == size) {
                            VISIBLE_UNIT_REC* new_list =
                                (VISIBLE_UNIT_REC*)calloc(size + size, 8);
                            memcpy(new_list, bucket->unit_list, size * 8);
                            free(bucket->unit_list);
                            bucket->unit_list = new_list;
                            bucket->list_size = (short)(size + size);

                            int i = 0;
                            if (bucket->used > 0) {
                                VISIBLE_UNIT_REC* record = new_list;
                                do {
                                    RGE_Combat_Object* object =
                                        (RGE_Combat_Object*)
                                            VIS_UNIT_objectsValue[
                                                record->object_id];
                                    if (object != 0) {
                                        object->VUR_Ptrs[p] = record;
                                    }
                                    i++;
                                    record++;
                                } while (i < bucket->used);
                            }
                        }

                        int used = bucket->used;
                        VISIBLE_UNIT_REC* record =
                            bucket->unit_list + used;
                        record->distance = 0;
                        record->object_id = object_id;
                        record->player = (unsigned char)player;
                        record->pos_x = (unsigned char)x;
                        record->pos_y = (unsigned char)y;
                        bucket->used++;
                        *current_refs = record;
                    } else {
                        VISIBLE_UNIT_REC* record = *current_refs;
                        VISIBLE_UNIT_REC* last =
                            bucket->unit_list + bucket->used - 1;
                        if (last != record) {
                            *record = *last;
                            RGE_Combat_Object* object =
                                (RGE_Combat_Object*)
                                    VIS_UNIT_objectsValue[record->object_id];
                            if (object != 0) {
                                object->VUR_Ptrs[p] = record;
                            }
                        }
                        *current_refs = 0;
                        bucket->used--;
                    }
                }
                current_refs++;
                new_mask >>= 1;
                mask >>= 1;
                p++;
            }
        }
    }
}

int Visible_Unit_Manager::GetVisibleUnits(
    int x, int y, int distance, int player, int* categories,
    int category_count, int* player_map)
{
    int found = 0;
    unsigned char* distTable;
    VISIBLE_UNIT_PTR* PDP;
    VISIBLE_UNIT_REC* rec;

    if (category_count <= 0) {
        return 0;
    }
    if (player >= this->Player_Count) {
        return 0;
    }
    distance = distance > 0x0f ? 0x0f : distance;

    distTable = this->distanceTable;
    PDP = this->PlayerDataPtrs[player];
    VisibleUnitList_Size[0] = 0;
    VisibleUnitList_Size[1] = 0;
    VisibleUnitList_Size[2] = 0;
    VisibleUnitList_Size[3] = 0;
    VisibleUnitList_Size[4] = 0;

    int x2 = x + distance;
    int x1 = x - distance;
    int y1 = y - distance;
    int y2 = y + distance;

    do {
        int category = *categories;
        categories++;
        VISIBLE_UNIT_PTR* bucket = &PDP[category];
        rec = bucket->unit_list;
        unsigned int count = *(unsigned int*)&bucket->used & 0xffff;
        while (count != 0) {
            int dx;
            int dy;
            if (rec->pos_x <= x2) {
                if (rec->pos_x < x) {
                    if (rec->pos_x < x1) goto next_entry;
                    dx = x - rec->pos_x;
                } else {
                    dx = rec->pos_x - x;
                }
                if (rec->pos_y <= y2) {
                    if (rec->pos_y < y) {
                        if (rec->pos_y < y1) goto next_entry;
                        dy = y - rec->pos_y;
                    } else {
                        dy = rec->pos_y - y;
                    }
                    int d = distTable[(dx & 0x0f) +
                                      ((dy & 0x0f) << 4)];
                    if (d <= distance) {
                        int mapped = player_map[rec->player];
                        int size = VisibleUnitList_Size[mapped];
                        if (size < 0x100) {
                            VISIBLE_UNIT_REC* out =
                                VisibleUnitList[mapped] + size;
                            VisibleUnitList_Size[mapped] = size + 1;
                            *out = *rec;
                            out->distance = d;
                            found++;
                        }
                    }
                }
            }
next_entry:
            rec++;
            count--;
        }
    } while (--category_count != 0);
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
    int x, int y, int param3, int type, int* reject_list, int reject_count)
{
    if (type >= 0 && this->num_visible_resource_lists != 0 &&
        type < this->num_visible_resource_lists) {
        VISIBLE_RESOURCE_REC** resource_lists = this->VR_List;
        int* used_lists = this->VR_ListUsed;
        int count = used_lists[type];
        VISIBLE_RESOURCE_REC* best;
        if (count != 0) {
            VISIBLE_RESOURCE_REC* record = resource_lists[type];
            int best_distance = 9999;
            best = 0;
            while (count > 0) {
                int dx;
                int dy;
                int rejected = 0;
                int record_x = record->pos_x;
                int record_y = record->pos_y;
                if (record_x > x) {
                    dx = record_x - x;
                } else {
                    dx = x - record_x;
                }
                if (record_y > y) {
                    dy = record_y - y;
                } else {
                    dy = y - record_y;
                }

                int distance;
                if (dx > dy) {
                    distance =
                        (dx - (int)(DAT_005776D8 -
                                    dy * DAT_005776D0)) - dy;
                } else {
                    distance =
                        (dy - (int)(DAT_005776D8 -
                                    dx * DAT_005776D0)) - dx;
                }

                if (distance < best_distance) {
                    if (reject_count && reject_list) {
                        int i = 0;
                        while (i < reject_count) {
                            if (record->object_id == reject_list[i]) {
                                rejected = 1;
                                break;
                            }
                            i++;
                        }
                    }
                    if (!rejected) {
                        best = record;
                        best_distance = distance;
                    }
                }
                record++;
                count--;
            }
            if (best_distance > 0xff) {
                best_distance = 0xff;
            }
            if (best != 0) {
                best->distance = (unsigned char)best_distance;
            }
            return best;
        }
    }
    return 0;
}
