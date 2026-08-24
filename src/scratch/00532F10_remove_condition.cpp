#ifndef VICTORY_CONTEXT_H
struct RGE_Victory_Entry {
    char type;
    char gap_1[3];
    int field_4;
    int field_8;
    char gap_C[0x1C - 0xC];
    int field_1C;
    int field_20;
    int field_24;
    void* target_obj;
    char gap_2C[2];
    char field_2E;
    char gap_2F;
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    char gap_0[4];
    RGE_Victory_Entry* field_4;

    void remove_entry(RGE_Victory_Entry* entry);
    unsigned char remove_condition(int index);
};
#endif

unsigned char RGE_Victory_Conditions::remove_condition(int index) {
    int i = 0;
    RGE_Victory_Entry* entry = this->field_4;
    while (entry) {
        if (i == index) {
            this->remove_entry(entry);
            return 1;
        }
        i++;
        entry = entry->next;
    }
    return 0;
}
