#include <stdlib.h>

struct RGE_Victory_Point_Entry {
    unsigned char command;
    unsigned char pad1;
    unsigned char group;
    unsigned char id;
    long attribute;
    long amount;
    long points;
    long curr_points;
    char gap_14[4];
    struct RGE_Victory_Point_Entry* next;
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x14];
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;

    RGE_Victory_Point_Entry* add_point(unsigned char p1, unsigned char p2);
};

RGE_Victory_Point_Entry* RGE_Victory_Conditions::add_point(unsigned char p1, unsigned char p2) {
    RGE_Victory_Point_Entry* entry = (RGE_Victory_Point_Entry*)calloc(1, 0x1c);
    if (entry != 0) {
        entry->pad1 = 0;
        entry->attribute = -1;
        entry->amount = 0;
        entry->command = 0xff;
        entry->points = 0;
        entry->curr_points = 0;
        entry->next = this->victory_point_list;
        entry->group = p1;
        entry->id = p2;
        this->victory_point_list = entry;
        this->point_list_num++;
    }
    return entry;
}
