// VA: 0049D610 TRIBE_Screen_Info::handle_idle
// scr_info.cpp lines 65-85

// attempt 1: natural C++ 

#include "../../include/scr_info_context.h"

long TRIBE_Screen_Info::handle_idle() {
    if (*(int*)((char*)rge_base_game + 0x1D8) == 0) {
        rge_base_game->enable_input();
    }
    if (auto_close != 0) {
        if (last_time == 0) {
            last_time = debug_timeGetTime("scr_info.cpp", 0x48);
            return TPanel::handle_idle();
        }
        unsigned long now = debug_timeGetTime("scr_info.cpp", 0x4B);
        unsigned int elapsed = now - last_time;
        if (elapsed > timer) {
            close_screen();
            return 0;
        }
    }
    return TPanel::handle_idle();
}
