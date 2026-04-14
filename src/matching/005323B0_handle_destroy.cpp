struct SomeObj {
    char gap_0[0x48];
    char state;
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
    SomeObj* target_obj;
    char gap_2C[2];
    char field_2E;
    char gap_2F;
    void* next;
};

class RGE_Victory_Conditions {
public:
    void handle_destroy(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_destroy(RGE_Victory_Entry* entry) {
    if (entry->target_obj && entry->target_obj->state == 7) {
        entry->field_2E = 2;
        entry->target_obj = 0;
    }
}
