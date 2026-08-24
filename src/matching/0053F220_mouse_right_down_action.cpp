// 0053F220 RGE_Main_View::mouse_right_down_action(long,long,int,int)
// vw_main.cpp:1082-1111
// Attempt 6: nested if structure to force shared epilogue

#include "../../include/vw_main_tu_context.h"

extern "C" void __cdecl color_log(unsigned char a, unsigned char b, int c);

long RGE_Main_View::mouse_right_down_action(long param_1, long param_2,
                                            int param_3, int param_4)
{
    if (!rge_base_game->get_paused()) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            color_log(0x4C, 0x24, 1);

            if (rge_base_game->game_mode != 0x13) {
                this->capture_mouse();
            } else {
                if (this->player->selected_obj) {
                    this->player->unselect_object();
                    this->set_redraw(1);
                }
                rge_base_game->set_game_mode(0x13, 1);
                this->start_scroll_view(9, param_1, param_2, param_3, param_4);
            }

            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }
    return 0;
}
