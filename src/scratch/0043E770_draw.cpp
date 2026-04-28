// TribeDiplomacyDialog::draw (0043E770)
// PDB source: dlg_dip.cpp:880-903
// Size: 195 bytes
// Calling convention: __thiscall
//
// PARKED: Remaining mismatch is pure VC5 register allocation / TU-context drift.
// The function structure (sub esp, 8 pattern, vtable save/restore,
// push-0 before draw_setup, reload-player_num-in-loop) is structurally correct.
// Source variants tried:
//
// Probe 1: Class with virtual draw_setup/finish + TEasy_Panel::draw call.
//   VC5 resolved draw_setup/finish as direct calls (not vtable) — wrong.
// Probe 2: Member function pointers to force vtable dispatch. Layout off
//   (backgroundPics at +0x610 instead of +0x60C, sizeof(TEasy_Panel) mismatch).
// Probe 3: Flat struct + extern __thiscall function pointer. VC5 rejects __thiscall on fns.
// Probe 4: Abstract DipVTable interface (10 dummies + draw_setup/finish). Vtable dispatch
//   works, but sub esp = 0x0C (4 extra bytes), wrong register order.
// Probe 5: Removed rge_game_world extern, used rge_base_game->world directly.
//   Same layout issues.
// Probe 6: Removed DipVTable* v local, removed yOff, used i*0x1E for y-offset.
//   sub esp = 8 matches! But register allocation completely different.
// Probe 7: Explicit count/yOff/playerIdx variables. sub esp = 0x0C again.
// Probe 8: Cached numPlayersMinus1. Function undersized (192 bytes).
// Probe 9-12: Variant lab (2x2 = 4 variants: decl_order x loop_form).
//   Best: G0000 (wfirst + countLoop) — sub esp=8, push ebp vs push esi is only entry diff.
//   All have wrong register allocation for vtable/zero/world/loop-vars.
//
// Summary: vtable dispatch verified correct via DipVTable abstract interface.
// TEasy_Panel/TDialogPanel class layout uses sizeof(TEasy_Panel) fix via
// unsigned char _pad[0x60C-4] (that's 0x60C bytes including vtable).
// TShape::shape_draw is __thiscall with 6 stack params. _ASMSet_Color_Xform is __cdecl.
// Loop reloads player_num from world each iteration (not cached).
//
// Remaining drift: VC5 register allocation (which registers for vtable/world/zero/counter)
// is TU-context dependent. Compiling alone vs with Com_hand.cpp changes the allocation.
// All 12 probes produced the same codegen family with different register colors.

extern "C" int __cdecl _ASMSet_Color_Xform(int param_1);

class TShape {
public:
    unsigned char shape_draw(void* param1, void* param2, void* param3, int param4, int param5, unsigned char* param6);
};

struct RGE_Game_World {
    unsigned char gap_00[0x3C];
    short player_num;
    unsigned char gap_3E[2];
    void** players;
};

struct RGE_Base_Game {
    unsigned char gap_00[0x3F4];
    RGE_Game_World* world;
};

extern RGE_Base_Game* rge_base_game;

struct DipVTable {
    virtual void dd00() = 0; virtual void dd01() = 0;
    virtual void dd02() = 0; virtual void dd03() = 0;
    virtual void dd04() = 0; virtual void dd05() = 0;
    virtual void dd06() = 0; virtual void dd07() = 0;
    virtual void dd08() = 0; virtual void dd09() = 0;
    virtual void draw_setup(int) = 0;   // vt[10] = 0x28
    virtual void draw_finish() = 0;      // vt[11] = 0x2C
};

class TEasy_Panel {
public:
    virtual void draw();
    unsigned char _pad[0x60C - 4];
};

class TribeDiplomacyDialog : public TEasy_Panel {
public:
    TShape* backgroundPics;
    void draw();
};

void TribeDiplomacyDialog::draw()
{
    TEasy_Panel::draw();
    if (backgroundPics != 0)
    {
        ((DipVTable*)this)->draw_setup(0);
        RGE_Game_World* w = rge_base_game->world;
        if (w->player_num > 1)
        {
            int yOff = 0;
            for (int i = 1; i < w->player_num; i++)
            {
                void* f = *(void**)((char*)w->players[i] + 0x108);
                if (f != 0)
                {
                    _ASMSet_Color_Xform((*(short*)((char*)f + 0x26) + 1) * 16);
                    backgroundPics->shape_draw(
                        (char*)this + 0x20,
                        (char*)this + 0x0C + 0x0A,
                        (char*)this + 0x10 + yOff + 0x50,
                        0,
                        1,
                        (unsigned char*)((char*)f + 0x28)
                    );
                }
                yOff += 0x1E;
            }
        }
        ((DipVTable*)this)->draw_finish();
    }
}
