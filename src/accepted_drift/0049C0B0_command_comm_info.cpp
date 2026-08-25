// VA: 0049C0B0 command_comm_info (165B)
// scr_game.cpp
// Fresh 2026-05-19: implement real command_comm_info panel toggle logic.
// try 1: natural panel/global logic: exact size, only broad diffs from set_visible vslot at +0x10 and final global reload register choices.
// try 2: add the canonical set_active surface: reduced to 30/165 positional.
// try 3: force final else-branch global reloads through a local `game`: reduced to 4/165 positional.
// try 4: first-call temp local; no change.
// try 5: second-call temp local; no change.
// try 6: int-return virtual surface; no change, rolled back.
// Remaining drift is only vtable scratch register selection for two adjacent calls: rebuilt uses EDX then EAX;
// original uses EAX then EDX. Same ECX this pointers, pushed args (0/1), vslot +0x14, calls, and all later bytes exact.

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_comm_info() {
    rge_base_game->do_show_timings = 0;
    this->fps_panel->set_visible(0);
    this->inven_panel->set_visible(1);
    this->message_panel1->remove_message();
    this->message_panel2->remove_message();
    this->message_panel3->remove_message();
    this->message_panel4->remove_message();
    this->message_panel5->remove_message();
    this->message_panel6->remove_message();
    if (rge_base_game->do_show_comm != 0) {
        rge_base_game->do_show_comm = 0;
    }
    else {
        RGE_Base_Game* game;
        rge_base_game->do_show_timings = 0;
        game = rge_base_game;
        game->do_show_ai = 0;
        game = rge_base_game;
        game->do_show_comm = 1;
    }
}
