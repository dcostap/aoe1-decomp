// 0045BE80 TMousePointer::set_game_facet
//
// BLOCKER: best source has exact registers, size, and all body bytes except a
// four-byte scheduling shift around the first ESI save/shape_info load. Original:
//   mov eax,[ecx+58h]; mov [ecx+8Ch],edx; shl edx,5; mov eax,[eax+1Ch]; push esi; add eax,edx
// Rebuilt best:
//   mov eax,[ecx+58h]; push esi; mov eax,[eax+1Ch]; mov [ecx+8Ch],edx; shl edx,5; add eax,edx
// The rest of the stores/subtractions/epilogue match exactly.
//
// Attempt log:
// 1. Prior typed/local f source exact size/body mostly matches, but uses EAX for facet and saves ESI early.
// 2. Direct raw pointer expression using facet parameter: got EDX facet, but saved EDI/ESI early.
// 3. Direct facet with game_facet store before info calculation: optimized back to EAX facet.
// 4. Offset temp + shape temp: same EAX facet/early ESI.
// 5. Mutating incoming facet parameter after store: same EAX facet.
// 6. Shape_Info base local, then store, then add scaled facet: best; EDX facet correct, only push/load shape_info four bytes early.
// 7. Uninitialized info + shape local: regressed to EAX facet.
// 8. Explicit hotspot_y local and commuted bottom expression: no change from best.
// 9. variant_lab over combined/nested guards, five info/store/order shapes, direct/local/commuted bottom, and vc5-small flags: no exact. Only five asm families; best remains base-before shape with edit diff 8.

class Shape_Info {
public:
    char pad_00[0x10];
    int width;
    int height;
    int hotspot_x;
    int hotspot_y;
};

class TShape {
public:
    char pad_00[0x1C];
    Shape_Info* shape_info;
};

class TMousePointer {
public:
    char gap_00[0x10];
    int Num_Cursors;
    char gap_14[0x58 - 0x14];
    TShape* Cursor_Shape;
    char gap_5C[0x70 - 0x5C];
    int gWidth;
    int gHeight;
    char gap_78[0x8C - 0x78];
    int game_facet;
    char gap_90[0xA8 - 0x90];
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;

    void set_game_facet(int facet);
};

void TMousePointer::set_game_facet(int facet) {
    if (facet >= 0 && facet < this->Num_Cursors) {
        Shape_Info* info = this->Cursor_Shape->shape_info;
        this->game_facet = facet;
        info = (Shape_Info*)((char*)info + (facet << 5));
        this->gWidth = info->width;
        this->gHeight = info->height;
        this->g_top = info->hotspot_y;
        this->g_left = info->hotspot_x;
        this->g_right = this->gWidth - info->hotspot_x;
        this->g_bottom = this->gHeight - info->hotspot_y;
    }
}
