#include "../include/Visible_Unit_Manager.h"

#include "../include/RGE_Static_Object.h"
#include "../include/LOSTBL.h"
#include "../include/VISIBLE_UNIT_PTR.h"
#include "../include/VISIBLE_UNIT_REC.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

#include <stdlib.h>
#include <string.h>

extern LOSTBL* NormalLOS[17];
extern LOSTBL* SquareLOS[17];

// TODO: PARITY - vis_unit.cpp.decomp includes Visible_Resource_Manager functions (0x0053BB30..0x0053C050)
// that are not present in this TU; keep split implementation parity aligned across both files.
// [decomp: vis_unit.cpp.decomp @ 0x0053BB30]

// Fully verified. Marker reconciliation coverage.
static void vis_unit_set_backptr(int object_id, int player_index, VISIBLE_UNIT_REC* rec) {
    if (VIS_UNIT_objectsValue == nullptr) {
        return;
    }
    RGE_Static_Object* obj = VIS_UNIT_objectsValue[object_id];
    if (obj == nullptr) {
        return;
    }
    *(VISIBLE_UNIT_REC**)((char*)obj + 0x194 + player_index * 4) = rec;
}

// Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053B5A0
Visible_Unit_Manager::Visible_Unit_Manager(int param_1, int param_2) {
    CUSTOM_DEBUG_LOG_FMT("Visible_Unit_Manager::ctor enter this=%p players=%d categories_in=%d", this, param_1, param_2);
    this->Player_Count = param_1;
    this->Category_Count = param_2 + 1;
    this->distanceTable = nullptr;
    this->PlayerDataPtrs = (VISIBLE_UNIT_PTR**)calloc(param_1, 4);

    for (int i = 0; i < this->Player_Count; ++i) {
        VISIBLE_UNIT_PTR* category_lists = (VISIBLE_UNIT_PTR*)calloc(this->Category_Count, 8);
        this->PlayerDataPtrs[i] = category_lists;
        for (int j = 0; j < this->Category_Count; ++j) {
            category_lists[j].list_size = 0x20;
            category_lists[j].used = 0;
            category_lists[j].unit_list = (VISIBLE_UNIT_REC*)calloc(0x20, 8);
        }
    }

    for (int i = 0; i < 5; ++i) {
        VISIBLE_UNIT_REC* buf = (VISIBLE_UNIT_REC*)malloc(0x800);
        this->Return_Buffer[i] = buf;
        VisibleUnitList[i] = buf;
        VisibleUnitList_Size[i] = 0;
    }

    CUSTOM_DEBUG_LOG_FMT("Visible_Unit_Manager::ctor before Build_Distance_Table this=%p", this);
    Build_Distance_Table();
    CUSTOM_DEBUG_LOG_FMT("Visible_Unit_Manager::ctor after Build_Distance_Table this=%p distanceTable=%p", this, this->distanceTable);
    VisibleUnitManager = this;
    CUSTOM_DEBUG_LOG_FMT("Visible_Unit_Manager::ctor exit this=%p", this);
}

// Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053B670
Visible_Unit_Manager::~Visible_Unit_Manager() {
    if (this->PlayerDataPtrs != nullptr) {
        for (int i = 0; i < this->Player_Count; ++i) {
            VISIBLE_UNIT_PTR* lists = this->PlayerDataPtrs[i];
            if (lists != nullptr) {
                for (int j = 0; j < this->Category_Count; ++j) {
                    if (lists[j].unit_list != nullptr) {
                        free(lists[j].unit_list);
                    }
                }
                free(lists);
            }
        }
        free(this->PlayerDataPtrs);
    }

    for (int i = 0; i < 5; ++i) {
        if (this->Return_Buffer[i] != nullptr) {
            free(this->Return_Buffer[i]);
        }
        VisibleUnitList[i] = nullptr;
        VisibleUnitList_Size[i] = 0;
    }

    if (this->distanceTable != nullptr) {
        free(this->distanceTable);
    }
    VisibleUnitManager = nullptr;
}

// Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053B730
void Visible_Unit_Manager::Build_Distance_Table() {
    CUSTOM_DEBUG_LOG_FMT("Visible_Unit_Manager::Build_Distance_Table enter this=%p NormalLOS0=%p SquareLOS0=%p", this, NormalLOS[0], SquareLOS[0]);
    if (this->distanceTable != nullptr) {
        free(this->distanceTable);
    }

    this->distanceTable = (uchar*)malloc(0x100);
    memset(this->distanceTable, 0xFF, 0x100);

    uchar distance_value = 0;
    for (int group = 0; group < 2; ++group) {
        LOSTBL** los_tables = (group == 0) ? &NormalLOS[0] : &SquareLOS[0];
        for (int table_index = 0; table_index < 17; ++table_index) {
            LOSTBL* offsets = los_tables[table_index];
            if (offsets == nullptr) {
                CUSTOM_DEBUG_LOG_FMT(
                    "Visible_Unit_Manager::Build_Distance_Table null LOS table group=%d idx=%d",
                    group,
                    table_index);
                ++distance_value;
                continue;
            }

            int row = offsets->y_delta;
            while (row != 999) {
                int left = offsets->x_left;
                int right = offsets->x_right;
                if ((-1 < row) && (row < 0x10)) {
                    if (left < 0) {
                        left = 0;
                    }
                    if (0x0F < right) {
                        right = 0x0F;
                    }
                    int index = row * 0x10 + left;
                    if (left <= right) {
                        int count = (right - left) + 1;
                        while (count != 0) {
                            if (this->distanceTable[index] == 0xFF) {
                                this->distanceTable[index] = distance_value;
                            }
                            ++index;
                            --count;
                        }
                    }
                }
                offsets = offsets + 1;
                row = offsets->y_delta;
            }
            ++distance_value;
        }
    }
}

// Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053B7E0
void Visible_Unit_Manager::Update_Unit_Info(int param_1, int param_2, int param_3, int param_4, int param_5, ulong param_6, ulong param_7, VISIBLE_UNIT_REC** param_8) {
    const uint changed_mask = (param_7 ^ param_6) & 0xffff;
    if (param_5 >= this->Category_Count || this->Player_Count <= 0) {
        return;
    }

    uint diff = changed_mask;
    uint new_bits = (uint)param_7;
    for (int player_index = 0; player_index < this->Player_Count; ++player_index) {
        if (diff == 0) {
            return;
        }

        if ((diff & 1U) != 0U) {
            VISIBLE_UNIT_PTR* list = this->PlayerDataPtrs[player_index] + param_5;
            if ((new_bits & 1U) != 0U) {
                if (list->used == list->list_size) {
                    const short old_size = list->list_size;
                    VISIBLE_UNIT_REC* new_list = (VISIBLE_UNIT_REC*)calloc(old_size * 2, 8);
                    memcpy(new_list, list->unit_list, old_size * 8);
                    free(list->unit_list);
                    list->unit_list = new_list;
                    list->list_size = old_size * 2;

                    for (int i = 0; i < list->used; ++i) {
                        if (VIS_UNIT_objectsValue[list->unit_list[i].object_id] != nullptr) {
                            vis_unit_set_backptr(list->unit_list[i].object_id, player_index, &list->unit_list[i]);
                        }
                    }
                }

                VISIBLE_UNIT_REC* rec = &list->unit_list[list->used];
                rec->distance = 0;
                rec->object_id = param_1;
                rec->player = (uchar)param_2;
                rec->pos_x = (uchar)param_3;
                rec->pos_y = (uchar)param_4;
                list->used = list->used + 1;
                *param_8 = rec;
            } else {
                VISIBLE_UNIT_REC* rec = *param_8;
                VISIBLE_UNIT_REC* tail = &list->unit_list[list->used - 1];
                if (tail != rec) {
                    *rec = *tail;
                    if (VIS_UNIT_objectsValue[rec->object_id] != nullptr) {
                        vis_unit_set_backptr(rec->object_id, player_index, rec);
                    }
                }
                *param_8 = nullptr;
                list->used = list->used - 1;
            }
        }

        ++param_8;
        new_bits >>= 1;
        diff >>= 1;
    }
}

// Fully verified. Source of truth: vis_unit.cpp.decomp @ 0x0053B9A0
int Visible_Unit_Manager::GetVisibleUnits(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6, int* param_7) {
    int found = 0;
    if (param_6 < 1 || this->Player_Count <= param_4) {
        return 0;
    }

    if (0x0f < param_3) {
        param_3 = 0x0f;
    }

    for (int i = 0; i < 5; ++i) {
        VisibleUnitList_Size[i] = 0;
    }
    DAT_0087d7cc = 0;
    DAT_0087d7d0 = 0;
    DAT_0087d7d4 = 0;
    DAT_0087d7d8 = 0;

    VISIBLE_UNIT_PTR* player_data = this->PlayerDataPtrs[param_4];
    while (true) {
        const int category_id = *param_5;
        ++param_5;

        VISIBLE_UNIT_REC* rec = player_data[category_id].unit_list;
        for (uint i = (uint)player_data[category_id].used & 0xffff; i != 0; --i) {
            uint dx = (uint)rec->pos_x;
            if ((int)dx <= param_1 + param_3) {
                if ((int)dx < param_1) {
                    if ((int)dx < param_1 - param_3) {
                        ++rec;
                        continue;
                    }
                    dx = param_1 - dx;
                } else {
                    dx = dx - param_1;
                }

                uint dy = (uint)rec->pos_y;
                if ((int)dy <= param_2 + param_3) {
                    if ((int)dy < param_2) {
                        if ((int)dy < param_2 - param_3) {
                            ++rec;
                            continue;
                        }
                        dy = param_2 - dy;
                    } else {
                        dy = dy - param_2;
                    }

                    const uchar dist = this->distanceTable[(dx & 0xf) + (dy & 0xf) * 0x10];
                    if ((int)(uint)dist <= param_3) {
                        const int list_index = param_7[rec->player];
                        int size = VisibleUnitList_Size[list_index];
                        if (size < 0x100) {
                            uintptr_t* out = (uintptr_t*)VisibleUnitList[list_index];
                            VisibleUnitList_Size[list_index] = size + 1;
                            const uint packed =
                                ((uint)dist) |
                                ((uint)rec->player << 8) |
                                ((uint)rec->pos_x << 16) |
                                ((uint)rec->pos_y << 24);
                            out[size * 2] = (uintptr_t)rec->object_id;
                            out[size * 2 + 1] = (uintptr_t)packed;
                            found = found + 1;
                            DAT_0087d7cc = VisibleUnitList_Size[1];
                            DAT_0087d7d0 = VisibleUnitList_Size[2];
                            DAT_0087d7d4 = VisibleUnitList_Size[3];
                            DAT_0087d7d8 = VisibleUnitList_Size[4];
                        }
                    }
                }
            }
            ++rec;
        }

        --param_6;
        if (param_6 == 0) {
            return found;
        }
    }
}
