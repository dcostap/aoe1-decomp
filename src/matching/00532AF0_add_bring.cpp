struct RGE_Static_Object {
    char gap_0[0x0C];
    int field_C;
};

struct RGE_Victory_Entry {
    char type;
    char gap_1[3];
    int field_4;
    int field_8;
    char gap_C[0x1C - 0xC];
    int field_1C;
    int field_20;
    int field_24;
    RGE_Static_Object* target_obj;
    char gap_2C[2];
    char field_2E;
    char gap_2F;
    void* next;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* add(unsigned char param_1, unsigned char param_2);
    unsigned char add_bring(unsigned char param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3);
};

unsigned char RGE_Victory_Conditions::add_bring(unsigned char param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry) {
        entry->type = 5;
        entry->field_24 = (int)param_2;
        entry->target_obj = param_3;
        entry->field_8 = param_3->field_C;
        return 1;
    }
    return 0;
}
