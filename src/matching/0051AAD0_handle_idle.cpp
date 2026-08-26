// TRIBE_Panel_Inven::handle_idle
// Checks game mode, timer, and whether saved values changed.
// If changed, calls save_info and triggers redraw (vf20).

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl color_log(unsigned char a, unsigned char b, unsigned char c);

#include "../../include/tpnl_inv_context.h"

long TRIBE_Panel_Inven::handle_idle() {
    this->TPanel::handle_idle();

    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xAD);
        if (now - this->idle_time >= (unsigned long)this->idle_interval) {
            color_log(0xBA, 0xBA, 5);

            int changed = 0;
            short i;
            i = (short)changed;
            if (0 < this->save_attr_num) {
                short* saved = this->save_attr;
                float* values = this->player->float_values;
                for (;;) {
                    if (i >= this->save_attr_num)
                        break;
                    if ((short)(int)values[i] != saved[i]) {
                        changed = 1;
                        break;
                    }
                    i++;
                }
            }

            if (changed) {
                color_log(0xBA, 0x16, 5);
                save_info();
                this->set_redraw(1);
            }

            this->idle_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xC2);
            color_log(0xBA, 0x5F, 5);
        }
    }
    return 0;
}
