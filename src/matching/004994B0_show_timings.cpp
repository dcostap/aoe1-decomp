// 004994B0 TRIBE_Screen_Game::show_timings
// Attempt log:
// 1. Existing decompiler-style byte-pair compare has right behavior but wrong register/prolog basin (keeps this in EBP, extra compare state spills).
// 2. Natural strcmp spelling emitted the exact inline strcmp kernel; initial virtual surface had wrong +0x120 notify offset.
// 3. Use a real virtual method at vtable slot 58 (+0xE8).

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::show_timings(char* param_1, char* param_2) {
    char* current = this->fps_panel->get_text();
    if (current == 0 || strcmp(current, param_2) != 0) {
        this->fps_panel->set_text(param_2);
    }
}
