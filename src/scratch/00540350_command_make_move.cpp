// 00540350 command_make_move
// RGE_Main_View::command_make_move(long param_1, long param_2)
// Source: vw_main.cpp lines 1818-1846
// Size: 197 bytes
//
// Status: PARKED - VC5 frame layout / register allocation drift
//
// Attempt log:
// Probe 1: type stubs, got 197 bytes, 79.7% positional diff
//   Issues: sub esp 0x18 vs 0x1C, extra push ebx, wrong player offset
// Probe 2: fixed player offset (pad[0xFC] + vptr), pick1 param order
//   Same sub/ebx issues, fld from type-pun
// Probe 3: restructured (no goto), long x/y, memcpy for scr_combined
//   Got 197 bytes without ebx! rge_base_game call correct.
//   Fixes: no push ebx, proper command_action push order, no FPU
//   Remaining: sub esp 0x18 vs 0x1C (~79% positional, all offsets shifted)
//
// Remaining diff (~79% positional):
//   sub esp 0x18 (24) vs 0x1C (28): frame size difference of 4 bytes
//   cascades through ALL stack offsets throughout the function
//   Shared fail block (original uses je near to fail at end) vs
//   inline early return (jne short + inline cleanup)
//   Different register allocation in command_action section
//
// All behavior, call targets, field offsets (player at +0x100),
// pick1 param order, command_action args, and stack cleanup are correct.
// Frame layout is VC5 TU-context dependent.

#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct RGE_Pick_Info {
    long x;
    long y;
    short scr_x;
    short scr_y;
    void* object;
    void* tile;
};

extern int allow_user_commands;

struct RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

struct RGE_Base_Game {
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void update(unsigned long a, unsigned long b);
};

class RGE_Player {
public:
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void vt_pad_04();
    virtual void vt_pad_05();
    virtual void vt_pad_06();
    virtual void vt_pad_07();
    virtual void vt_pad_08();
    virtual void vt_pad_09();
    virtual void vt_pad_10();
    virtual void vt_pad_11();
    virtual void vt_pad_12();
    virtual void vt_pad_13();
    virtual void vt_pad_14();
    virtual void vt_pad_15();
    virtual void vt_pad_16();
    virtual void vt_pad_17();
    virtual void vt_pad_18();
    virtual void vt_pad_19();
    virtual void vt_pad_20();
    virtual void vt_pad_21();
    virtual void vt_pad_22();
    virtual void vt_pad_23();
    virtual void vt_pad_24();
    virtual void vt_pad_25();
    virtual void vt_pad_26();
    virtual void vt_pad_27();
    virtual void vt_pad_28();
    virtual void vt_pad_29();
    virtual void vt_pad_30();
    virtual void vt_pad_31();
    virtual void vt_pad_32();
    virtual void vt_pad_33();
    virtual void vt_pad_34();
    virtual void vt_pad_35();
    virtual void vt_pad_36();
    virtual void vt_pad_37();
    virtual void vt_pad_38();
    virtual void vt_pad_39();
    virtual long command_action(long a, long b, long c);

    unsigned char get_selected_objects_to_command(
        void*** pick_info_out, short* list_num_out,
        int a, int b, int c, int d);
};

class RGE_Main_View {
public:
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void vt_pad_04();
    virtual void vt_pad_05();
    virtual void vt_pad_06();
    virtual void vt_pad_07();
    virtual void set_redraw(int mode);

    char pad_004[0xFC];
    RGE_Player* player;

    unsigned char pick1(int a1, int a2, void* a3, long a4, long a5, int a6, int a7);
    void fixup_pick_info(RGE_Pick_Info* info);

    int command_make_move(long param_1, long param_2);
};

int RGE_Main_View::command_make_move(long param_1, long param_2)
{
    if (!allow_user_commands) return 0;

    RGE_Pick_Info pick_info;
    void* list;

    if (!this->player->get_selected_objects_to_command(
            (void***)&pick_info,
            (short*)((char*)&list + 2),
            -1, -1, -1, -1))
    {
        return 0;
    }

    free((void*)pick_info.x);

    int result = 0;
    if (this->pick1(1, 0, (void*)((char*)&pick_info + 4),
                    param_2, param_1, 1, 0x2A) != 0x32)
    {
        this->fixup_pick_info((RGE_Pick_Info*)((char*)&pick_info + 4));

        long scr_combined;
        memcpy(&scr_combined, &pick_info.scr_x, 4);
        result = this->player->command_action(
            scr_combined, pick_info.y, (long)pick_info.tile);

        result = (unsigned char)result;
        this->set_redraw(1);
    }

    rge_base_game->update(0, 0);
    return result;
}
