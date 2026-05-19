// VA: 004C2110 RGE_Static_Object::draw_front_frame
// PDB source: stat_obj.cpp lines 858-881 (125 bytes, 42 asm lines)
// Default flags. No inline asm/hacks.
// Retry 2026-05-18/19 (20 honest tries):
// - Revalidated old baseline: exact-sized 125, first 48 bytes match; remaining mismatch was case0 virtual-call cleanup/register allocation and case block layout.
// - Tried natural virtual declaration for slot +0x20: fixes case0 callee cleanup/register order but optimizer hoists switch before game_mode==1 cube draw and flips early `jne` to `je`; broad layout regression.
// - Tried explicit goto, reordered cases, volatile game-mode, locals around helper calls; either early branch inverted or extra stack slot/prologue appeared.
// - Tried /Ob0 briefly; no change, flag removed.
// - 2026-05-19 breakthrough: raw vtable call cast to `__stdcall` removes caller `add esp,0Ch` while preserving the first 57 bytes (game_mode branch and jump table) and exact function size.
// - Tried case0 function-pointer locals and arg temporaries to force original `edx` argument reload sequence; VC5 still loads vtable first and uses ECX for param_3/param_1.
// - Tried source case-order swaps and per-case param_1 locals to place cube before square; VC5 either keeps square-before-cube in block layout or inverts the early game_mode branch.
// 2026-05-19 later pass:
// - try 21: reversed source order of case1 vs case2/3; compiler inverted game_mode branch and emitted switch first, much worse.
// - try 22: removed per-case param_1 locals; no codegen change from best basin.
// - try 23: inlined case0 raw function-pointer expression instead of fn local; no codegen change.
// - try 24: declared real virtual slot +0x20 and called it only in case0; case0 became exact but branch inverted/switch hoisted, broad regression.
// BEST CURRENT: exact-sized 125, first 57 bytes match, 22.4000% positional / 47.2000% edit. Remaining drift is case0 arg-register scheduling (ECX vs EDX) and switch case1/case2 block order/table layout.
// GIVEUP: no accepted_drift proposal because drift spans switch table targets/block order and multiple call setup blocks, not a small localized equivalent instruction swap.
// Retry 2026-05-19 Boss pass: 10 additional variants (if-chain, case source-order swaps, case0 arg temps/reverse temps, raw thiscall probe which failed compile, real virtual slot, signed-char/direct/named game switch, break-vs-return). Several stayed in best 22.4000% basin; none fixed case0 EDX scheduling plus case block/table order.

extern void* rge_base_game;

class RGE_Static_Object {
public:
    void draw_frame_3d_cube_front(void* a, short b, short c);
    void draw_frame_3d_square_front(void* a, short b, short c);
    void draw_front_frame(void* param_1, short param_2, short param_3);
};

typedef void (__stdcall *DrawFn)(void*, short, short);

void RGE_Static_Object::draw_front_frame(void* param_1, short param_2, short param_3) {
    int gm = *(int*)((int)rge_base_game + 0x1B4);
    if (gm == 1) {
        this->draw_frame_3d_cube_front(param_1, param_2, param_3);
        return;
    }

    unsigned int ot = (unsigned int)*(unsigned char*)((int)rge_base_game + 0x50);
    if (ot > 3)
        return;

    switch (ot) {
        case 0: {
            DrawFn fn = (DrawFn)(((void***)this)[0][8]);
            fn(param_1, param_2, param_3);
            break;
        }
        case 1: {
            this->draw_frame_3d_cube_front(param_1, param_2, param_3);
            break;
        }
        case 2:
        case 3: {
            this->draw_frame_3d_square_front(param_1, param_2, param_3);
            break;
        }
    }
}
