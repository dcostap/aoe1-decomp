// 0053F2F0 mouse_right_move_action (vw_main.cpp:1117-1151)
// PDB source: vw_main.cpp (RGE_Main_View::mouse_right_move_action)
//
// long __thiscall RGE_Main_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4)
// ret 10h cleanup (4 params, thiscall)
// Returns: 0 or 1
//
#include "../../include/vw_main_tu_context.h"

extern RGE_Base_Game* rge_base_game;

long __fastcall mouse_right_move_action(RGE_Main_View* this_ptr, int,
    long param_1, long param_2, int param_3, int param_4)
{
    int mode = rge_base_game->prog_mode;
    if (mode != 4 && mode != 6 && mode != 7) {
        if (mode != 5)
            return 0;
    }

    int paused = rge_base_game->get_paused();

    if (paused) {
        if (this_ptr->scroll_action) {
            this_ptr->end_scroll_view();
            return 0;
        } else {
            this_ptr->release_mouse();
            return 0;
        }
    } else {
        if (this_ptr->scroll_action) {
            this_ptr->handle_scroll_view(param_1, param_2);
            return 1;
        } else {
            if (this_ptr->player->sel_count == 0) {
                this_ptr->release_mouse();
                this_ptr->start_scroll_view(1, this_ptr->mouse_down_x,
                                            this_ptr->mouse_down_y, param_3,
                                            param_4);
                this_ptr->handle_scroll_view(param_1, param_2);
                return 1;
            }
            return 0;
        }
    }
}
