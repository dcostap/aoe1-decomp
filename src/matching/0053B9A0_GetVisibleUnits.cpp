// vis_unit.cpp target: Visible_Unit_Manager::GetVisibleUnits
//
// BINARY NOTE: The source lines show one category scan followed by one record
// scan. The output record is eight bytes: an object id and four byte fields.
// This source keeps those layouts as typed records and uses the observed
// bounds and distance-table tests.

#if !defined(VIS_UNIT_TU_CONTEXT)
struct VisibleUnitRec {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

struct VisibleUnitPtr {
    VisibleUnitRec* unit_list;
    short list_size;
    unsigned short used;
};

extern VisibleUnitRec* VisibleUnitList[5];
extern int VisibleUnitList_Size[5];

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    VisibleUnitRec* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    unsigned char* distanceTable;

    int GetVisibleUnits(int x, int y, int distance, int player, int* categories, int category_count, int* player_map);
};
#endif

int Visible_Unit_Manager::GetVisibleUnits(int x, int y, int distance, int player,
                                           int* categories, int category_count,
                                           int* player_map) {
    int found = 0;
    if (category_count < 1) {
        return 0;
    }
    if (this->Player_Count <= player) {
        return 0;
    }
    if (distance > 15) {
        distance = 15;
    }

    for (int i = 0; i < 5; i++) {
        VisibleUnitList_Size[i] = 0;
    }

    VisibleUnitPtr* lists = this->PlayerDataPtrs[player];
    unsigned char* table = this->distanceTable;
    for (int category_index = 0; category_index < category_count;
         category_index++, categories++) {
        VisibleUnitPtr* list_info = &lists[*categories];
        VisibleUnitRec* record = list_info->unit_list;
        int count = list_info->used & 0xffff;
        while (count != 0) {
            int record_x = record->pos_x;
            if (record_x <= x + distance) {
                int dx;
                if (record_x < x) {
                    if (record_x < x - distance) {
                        record++;
                        count--;
                        continue;
                    }
                    dx = x - record_x;
                } else {
                    dx = record_x - x;
                }

                int record_y = record->pos_y;
                if (record_y <= y + distance) {
                    int dy;
                    if (record_y < y) {
                        if (record_y < y - distance) {
                            record++;
                            count--;
                            continue;
                        }
                        dy = y - record_y;
                    } else {
                        dy = record_y - y;
                    }

                    unsigned char record_distance =
                        table[(dx & 15) + ((dy & 15) << 4)];
                    if (record_distance <= distance) {
                        int output = player_map[record->player];
                        if (VisibleUnitList_Size[output] < 0x100) {
                            VisibleUnitRec* output_record =
                                VisibleUnitList[output] +
                                VisibleUnitList_Size[output];
                            VisibleUnitList_Size[output]++;
                            output_record->object_id = record->object_id;
                            output_record->distance = record_distance;
                            output_record->player = record->player;
                            output_record->pos_x = record->pos_x;
                            output_record->pos_y = record->pos_y;
                            found++;
                        }
                    }
                }
            }
            record++;
            count--;
        }
    }
    return found;
}
