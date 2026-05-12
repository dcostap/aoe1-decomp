// 004C60A0 RGE_Static_Object::box_hit_test(short, short, short, short, short, short)
// PDB: stat_obj.cpp:3761-3801, 402 bytes
// __thiscall, unsigned char, ret 18h
// FLAGS: default
//
// Attempt log (7+ attempts):
// v0: Skeleton — compiled 352 vs 402, bounds logic incomplete
// v1: Better bounds logic — 85% diff, register allocation off
// v2-v6: Various comparison patterns — VC5 generates different short/compare patterns
//
// Remaining issues:
// 1. get_frame call: 4 short* pointers pushed to stack in specific order.
//    VC5 generates correct call but register setup differs.
// 2. Short computation: original computes 4 derived values from min_x/max_y/screen_offset.
//    VC5 generates correct arithmetic but with different register choices.
// 3. Comparison blocks: 6 blocks each checking bounds against params.
//    Each has 4 short comparisons (cmp di,dx; cmp di,[esp+34h]; cmp bx,si; cmp bx,[esp+38h]).
//    The specific jl/jg/jge/jle pattern depends on exact comparison structure.
// 4. Early-return epilogue: each return 1 has the same 6-instruction cleanup.
//    VC5 generates these but with branch targets shifted.
// 5. Frame: original uses sub esp,10h + 4 pushes (ebx, ebp, esi, edi).
//    VC5 matches this but local variable layout differs.

#include <stdlib.h>

struct RGE_VTable {
    virtual void dtor();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28(void* a, unsigned char b);
};

struct RGE_Active_Sprite_List {
    RGE_VTable* vt;
};

struct RGE_Static_Object {
    char gap_00[0x10];
    void* sprite;
    char gap_14[0x04];
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x0C];
    short screen_x_offset;    // +0x28
    short screen_y_offset;    // +0x2A
    char gap_2C[0x09];
    unsigned char facet;      // +0x35

    int get_frame(short* min_x, short* min_y, short* max_x, short* max_y);
    unsigned char box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6);
};

unsigned char RGE_Static_Object::box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6) {
    if (this->sprite == 0) return 0;
    if (this->sprite_list == 0) return 0;

    this->sprite_list->vt->_v28(this->sprite, this->facet);

    short min_x, min_y, max_x, max_y;
    if (this->get_frame(&min_x, &min_y, &max_x, &max_y) == 0) return 0;

    short sx = this->screen_x_offset;
    short sy = this->screen_y_offset;

    short v1 = min_x + max_y + sx;
    short v2 = min_y + max_x + sy;
    short v3 = max_y + sx;
    short v4 = max_x + sy;

    if (v1 >= param_4 && v1 <= param_6 && v2 >= param_3 && v2 <= param_5) return 1;
    if (v3 >= param_4 && v3 <= param_6 && v4 >= param_3 && v4 <= param_5) return 1;
    if (v1 >= param_4 && param_4 >= v3 && v2 >= param_3 && param_3 >= v4) return 1;
    if (v1 >= param_6 && param_6 >= v3 && v2 >= param_5 && param_5 >= v4) return 1;
    if (param_4 < v1 && v3 < param_6) {
        if (v2 < param_3 && param_3 < v4) return 1;
        if (v2 < param_5 && param_5 < v4) return 1;
    }
    if (param_3 < v2 && v4 < param_5) {
        if (v1 < param_4 && param_4 < v3) return 1;
        if (v1 < param_6 && param_6 < v3) return 1;
    }

    return 0;
}
