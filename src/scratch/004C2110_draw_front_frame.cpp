// VA: 004C2110 RGE_Static_Object::draw_front_frame
// PDB source: stat_obj.cpp lines 858-881 (125 bytes, 42 asm lines)
//
// Status: STUCK — switch/jump-table layout and virtual-call register allocation.
//
// First 48 bytes match (game_mode check, game_mode==1 call+return, outline_type
// load+compare, jump table dispatch). Then VC5 generates different register
// allocation for the case 0 virtual call (ecx reused for param loads instead of
// edx) and uses `add esp, N; ret` instead of `ret 0Ch` for callee cleanup.
// These are VC5 internal codegen heuristics not controllable from source.
//
// Best: 48 bytes exact, 46.40% positional, 52.80% edit diff.
// Key breakthrough: `if (gm == 1) { ... return; }` instead of `if (gm != 1) goto`
// produces the correct `jne` branch order matching the original.
//
// Retry 2026-05-18 (10 honest tries):
// - Revalidated baseline: exact-sized 125, first 48 bytes match; remaining mismatch is case 0 virtual-call cleanup/register allocation and case block layout.
// - Tried natural virtual declaration for slot +0x20 so call uses thiscall cleanup and removes add esp; case0 body improves, but optimizer merges game_mode==1 cube draw with switch case 1 and flips the early branch (`je`), worsening first mismatch to offset 12.
// - Tried /Ob0 briefly; no change from baseline, flag removed.
// - Reviewed switch/source ordering: baseline keeps correct game_mode==1 early call/ret and jump-table dispatch, but raw function-pointer case0 necessarily emits caller cleanup (`add esp,0Ch`).
// - Reviewed typed virtual surface: fixes cleanup but changes whole block placement, padding/table region, and early branch, so not viable.
// GIVEUP: exact requires contradictory source surfaces: raw/manual case0 for early layout vs typed virtual case0 for callee cleanup/register allocation. No accepted_drift proposal because mismatch spans switch branch distance, case0 cleanup, case ordering/padding, and helper-call layout.

#include <stdlib.h>

extern void* rge_base_game;

class RGE_Static_Object {
public:
    void draw_frame_3d_cube_front(void* a, short b, short c);
    void draw_frame_3d_square_front(void* a, short b, short c);
    void draw_front_frame(void* param_1, short param_2, short param_3);
};

void RGE_Static_Object::draw_front_frame(void* param_1, short param_2, short param_3) {
    int gm = *(int*)((int)rge_base_game + 0x1B4);
    if (gm == 1) {
        this->draw_frame_3d_cube_front(param_1, param_2, param_3);
        return;
    }
    unsigned int ot = (unsigned int)*(unsigned char*)((int)rge_base_game + 0x50);
    if (ot > 3) return;
    switch (ot) {
        case 0:
            ((void (*)(void*, short, short))(((void***)this)[0][8]))(param_1, param_2, param_3);
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
