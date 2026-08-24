#ifndef VICTORY_CONTEXT_H
struct VP_Entry {
    char gap_0[2];
    unsigned char id;
    unsigned char group;
    char gap_4[0x10 - 4];
    int points;
    float float_field;
    VP_Entry* next;
};

class RGE_Victory_Conditions {
public:
    char gap_0[0x14];
    VP_Entry* field_14;

    int get_victory_points_id(unsigned char id);
};
#endif

int RGE_Victory_Conditions::get_victory_points_id(unsigned char id) {
    int result = 0;
    VP_Entry* entry = this->field_14;
    while (entry) {
        if (entry->id == id)
            result = entry->points;
        entry = entry->next;
    }
    return result;
}
