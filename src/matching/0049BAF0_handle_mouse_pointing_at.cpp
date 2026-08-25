// VA: 0049BAF0 handle_mouse_pointing_at (358B)
// scr_game.cpp:4717-4840
// Natural same-TU reconstruction of the foreground/focus/modal gate, mouse
// position tracking, map pick, and button tooltip scan.
// Attempt log (sa-66340ab1-handle_mouse_pointing_at):
// - baseline typed source had exact frame/call/CFG but a -6-byte base-layout
//   shift and a broad loop mismatch.
// - restored the canonical 0xF4 TPanel/0x478 TScreenPanel sizes; this aligned
//   all screen fields and isolated the button scan.
// - reloaded *slot for the enabled/get_id/virtual-action checks, preserving the
//   binary's slot-address liveness and inline help-text ownership.
// - changed the ordinary do/while to a natural while(i < 17) header; VC5 then
//   emitted the original jl backedge/jmp-over-found-arm and all 358 bytes match.
// - Main-agent audit restored canonical base-game destructor ownership and
//   retained the typed panel/button scan; exact bytes were revalidated.

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::handle_mouse_pointing_at() {
    void* window = rge_base_game->prog_window;
    if (GetForegroundWindow() != window) {
        return;
    }
    if (this->main_view->get_focus() == 0) {
        return;
    }
    if (panel_system.modalPanel() != 0) {
        return;
    }

    tagPOINT point;
    rge_base_game->get_mouse_pos(point);
    if (point.x == this->last_mouse_x && point.y == this->last_mouse_y) {
        return;
    }

    this->last_mouse_x = point.x;
    this->last_mouse_y = point.y;

    if (this->main_view->message_active == 0) {
        this->text_line_panel->remove_message();
    }

    if (point.x < 0 || point.x >= this->pnl_wid ||
        point.y < 0 || point.y > this->pnl_hgt) {
        return;
    }

    short row;
    short col;
    RGE_Tile* tile;
    if (this->map_view->pick_tile(point.x, point.y, &row, &col, &tile) != 0) {
        return;
    }

    short found = -1;
    short i = 0;
    while (i < 0x11) {
        TRIBE_Panel_Button** slot = &this->button_panel[i];
        if ((*slot)->enabled != 0 && (*slot)->get_id() != -1 &&
            (*slot)->button_action(point.x, point.y) != 0) {
            found = i;
            break;
        }
        ++i;
    }

    if (found != -1) {
        this->text_line_panel->show_message(
            0, this->button_panel[found]->help_text, 0xFF, 0, 0, 0, 0);
    }
}
