// VA: 004C2110 RGE_Static_Object::draw_front_frame(TDrawArea*, short, short)
// PDB source: stat_obj.cpp lines 858-881 (125 bytes, 42 asm lines)
// Default flags
//
// __thiscall: this in ecx, 3 stack params (TDrawArea*, short, short). ret 0Ch cleanup.
//
// ~91/125 edit-match bytes. Left in scratch due to stable VC5 heuristic differences:
//
// 1. Block ordering (game_mode check): Original puts `game_mode==1` path as fall-through
//    with `jne` to switch. VC5 always inverts: puts switch as fall-through with `je` to
//    game_mode==1 path. This is a compiler-version heuristic choice.
//
// 2. Jump table layout: Due to the block reordering, the jump table entries shift.
//    In the original, the jump table has 4 entries (case 0, 1, 2, 2/3) pointing to
//    004C2148, 004C215F, 004C2176, 004C2176. In VC5 rebuild, the game_mode==1 code
//    body lands between case 0 and case 1 handlers, shifting all jump targets.
//
// 3. Case 2/3 handler: Missing from output — the compiler merges case 2/3 with the
//    default return due to overlapping block addresses.
//
// Field layout confirmed:
//   rge_base_game = global @ [62C574h]
//   game_mode @ global+0x1B4 (int)
//   outline_type @ global+0x50 (byte)
//   vf20 at vtable+0x20 (slot 8)
//   draw_frame_3d_cube_front @ 004C31E0
//   draw_frame_3d_square_front @ 004C2B50

#include <stdlib.h>

extern void* rge_base_game;

struct RSO_Vf {
    virtual void vf00() {}
    virtual void vf04() {}
    virtual void vf08() {}
    virtual void vf0C() {}
    virtual void vf10() {}
    virtual void vf14() {}
    virtual void vf18() {}
    virtual void vf1C() {}
    virtual void vf20(void* a, short b, short c) {}
};

class RGE_Static_Object {
public:
    void draw_frame_3d_cube_front(void* a, short b, short c);
    void draw_frame_3d_square_front(void* a, short b, short c);
    void draw_front_frame(void* param_1, short param_2, short param_3);
};

void RGE_Static_Object::draw_front_frame(void* param_1, short param_2, short param_3) {
    int gm = *(int*)((int)rge_base_game + 0x1B4);
    if (gm != 1) goto Lswitch;
    this->draw_frame_3d_cube_front(param_1, param_2, param_3);
    return;
Lswitch:
    {
        unsigned int ot = (unsigned int)*(unsigned char*)((int)rge_base_game + 0x50);
        if (ot > 3) return;
        switch (ot) {
            case 0:
                ((RSO_Vf*)this)->vf20(param_1, param_2, param_3);
                break;
            case 1:
                this->draw_frame_3d_cube_front(param_1, param_2, param_3);
                break;
            case 2:
            case 3:
                this->draw_frame_3d_square_front(param_1, param_2, param_3);
                break;
        }
    }
}
