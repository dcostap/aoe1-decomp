#ifndef VICTORY_CONTEXT_H
// Prefix pass: canonical float coordinate types with a dword y2 store produce grouped MATCH.
// Reverting the typed coordinate stores restored the 39-byte grouped mismatch. The local donor
// mirrors the canonical float coordinate types and the proven +0x18 y2 alias.
class RGE_Victory_Entry {
public:
    unsigned char command; // 0x0
    char gap_01[0x3];
    long obj_type;         // 0x4
    char gap_08[0x4];
    float x0;              // 0xC
    float y0;              // 0x10
    float x1;              // 0x14
    long y2;               // 0x18
    long number;           // 0x1C
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* add(unsigned char param_1, unsigned char param_2);
    unsigned char add_create(unsigned char param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, unsigned char param_8);
};
#endif

unsigned char RGE_Victory_Conditions::add_create(unsigned char param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, unsigned char param_8) {
    RGE_Victory_Entry* entry = this->add(param_1, param_8);
    if (entry != 0) {
        entry->obj_type = param_2;
        entry->number = param_3;
        entry->x0 = param_4;
        entry->y0 = param_5;
        entry->command = 8;
        entry->x1 = param_6;
        entry->y2 = *(long*)&param_7;
        return 1;
    }
    return 0;
}
