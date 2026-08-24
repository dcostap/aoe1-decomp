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
    void* next;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* add(unsigned char param_1, unsigned char param_2);
    unsigned char add_attributes(unsigned char param_1, long param_2, long param_3, unsigned char param_4);
};
#endif

unsigned char RGE_Victory_Conditions::add_attributes(unsigned char param_1, long param_2, long param_3, unsigned char param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, param_4);
    if (entry) {
        entry->type = 6;
        entry->field_1C = param_2;
        entry->field_20 = param_3;
        return 1;
    }
    return 0;
}
