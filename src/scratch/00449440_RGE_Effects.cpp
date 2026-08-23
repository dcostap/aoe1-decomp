// VA: 00449440 RGE_Effects::~RGE_Effects
// effects.cpp lines 134-149
// 99 bytes

// attempt 3: correct non-virtual class layout, short loop counter

extern void free(void* p);

struct RGE_Effect_Command {
    unsigned char command;    // +0x00
    unsigned char _pad_0;     // +0x01
    short change_num1;        // +0x02
    short change_num2;        // +0x04
    short change_num3;        // +0x06
    float change_amount;      // +0x08
};

struct RGE_Effect {
    short id;                 // +0x00
    char name[31];            // +0x02
    unsigned char _pad_0;     // +0x21
    short string_table_id;    // +0x22
    short effect_list_num;    // +0x24
    unsigned char _pad_1[2];  // +0x26
    RGE_Effect_Command* effect_list; // +0x28
};

struct RGE_Effects {
    void* vtable_ptr;         // +0x00
    RGE_Effect* effects;       // +0x04
    int effect_num;            // +0x08

    void destroy();
};

void RGE_Effects::destroy() {
    vtable_ptr = (void*)0x570430;
    for (short i = 0; i < effect_num; i++) {
        if (effects[i].effect_list != 0) {
            free(effects[i].effect_list);
        }
        effects[i].effect_list = 0;
    }
    if (effects != 0) {
        free(effects);
        effects = 0;
    }
    effect_num = 0;
}
