#ifndef VICTORY_CONTEXT_H
struct VP_Entry {
    char gap_0[2];
    unsigned char id;
    unsigned char group;
    char gap_4[0x10 - 4];
    int curr_points;
    float float_field;
    VP_Entry* next;
};

class RGE_Victory_Conditions {
public:
    char gap_0[0x14];
    VP_Entry* field_14;

    long get_victory_points_group(unsigned char group);
};
#endif

long RGE_Victory_Conditions::get_victory_points_group(unsigned char group) {
    int total = 0;
    VP_Entry* entry = this->field_14;
    while (entry) {
        if (entry->group == group || group == 0xFF)
            total += entry->curr_points;
        entry = entry->next;
    }
    return total;
}
