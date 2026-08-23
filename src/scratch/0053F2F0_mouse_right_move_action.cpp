// 0053F2F0 mouse_right_move_action (vw_main.cpp:1117-1151)
// PDB source: vw_main.cpp (RGE_Main_View::mouse_right_move_action)
//
// long __thiscall RGE_Main_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4)
// ret 10h cleanup (4 params, thiscall)
// Returns: 0 or 1
//
// Attempt log:
// attempt 1: virtual helper struct (58 dummies + 3 real at slots 58-60),
//   __fastcall with dummy edx, member-function externs.
//   EXACT MATCH. 0% diff, 4 relocations masked.
// Key: 58 dummy VTD() macros create vtable padding to reach slots 0xE8/0xEC/0xF0.

#include <stdlib.h>

// Macro to generate a dummy virtual method with unique name
#define VTD(n) virtual void vt_##n() {}

struct RGE_Main_View_Vt {
    // 58 dummy virtual methods for slots 0-57
    VTD(0) VTD(1) VTD(2) VTD(3) VTD(4) VTD(5) VTD(6) VTD(7)
    VTD(8) VTD(9) VTD(10) VTD(11) VTD(12) VTD(13) VTD(14) VTD(15)
    VTD(16) VTD(17) VTD(18) VTD(19) VTD(20) VTD(21) VTD(22) VTD(23)
    VTD(24) VTD(25) VTD(26) VTD(27) VTD(28) VTD(29) VTD(30) VTD(31)
    VTD(32) VTD(33) VTD(34) VTD(35) VTD(36) VTD(37) VTD(38) VTD(39)
    VTD(40) VTD(41) VTD(42) VTD(43) VTD(44) VTD(45) VTD(46) VTD(47)
    VTD(48) VTD(49) VTD(50) VTD(51) VTD(52) VTD(53) VTD(54) VTD(55)
    VTD(56) VTD(57)

    // Real methods at slots 58, 59, 60
    // vt[58]=0xE8: start_scroll_view(uchar, long, long, int, int)
    virtual int start_scroll_view(unsigned char a, long b, long c, int d, int e);
    // vt[59]=0xEC: handle_scroll_view(long, long)
    virtual int handle_scroll_view(long a, long b);
    // vt[60]=0xF0: end_scroll_view()
    virtual void end_scroll_view();
};

// Helper structs for thiscall function calls
struct RGE_Base_Game_Helper {
    char _gap_00[0x1B0];
    int prog_mode;
    int get_paused();
};

struct TPanel_ReleaseHelper {
    char _gap_00[4];
    void release_mouse();
};

// Player layout
struct RGE_Player_Layout {
    char _gap_00[0x19C];
    short sel_count;
};

// RGE_Main_View layout (partial)
struct RGE_Main_View_Layout {
    char _gap_00[0xC4];
    long field_0C4;
    long field_0C8;
    char _gap_CC[0x34];
    RGE_Player_Layout* player;
    char _gap_104[0x64];
    unsigned char scroll_action;
};

extern RGE_Base_Game_Helper* rge_base_game;

long __fastcall mouse_right_move_action(RGE_Main_View_Layout* this_ptr, int,
    long param_1, long param_2, int param_3, int param_4)
{
    int mode = rge_base_game->prog_mode;
    if (mode != 4 && mode != 6 && mode != 7) {
        if (mode != 5)
            return 0;
    }

    int paused = rge_base_game->get_paused();

    // Cast this to the vtable-bearing type for virtual dispatch
    RGE_Main_View_Vt* vt_this = (RGE_Main_View_Vt*)this_ptr;

    if (paused) {
        if (this_ptr->scroll_action) {
            vt_this->end_scroll_view();
            return 0;
        } else {
            ((TPanel_ReleaseHelper*)this_ptr)->release_mouse();
            return 0;
        }
    } else {
        if (this_ptr->scroll_action) {
            vt_this->handle_scroll_view(param_1, param_2);
            return 1;
        } else {
            if (this_ptr->player->sel_count == 0) {
                ((TPanel_ReleaseHelper*)this_ptr)->release_mouse();
                vt_this->start_scroll_view(1, this_ptr->field_0C4, this_ptr->field_0C8, param_3, param_4);
                vt_this->handle_scroll_view(param_1, param_2);
                return 1;
            }
            return 0;
        }
    }
}
