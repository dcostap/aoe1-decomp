#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif
void TRIBE_Screen_Game::command_tool_box() {
    if (rge_base_game->multiplayerGame() == 0) {
        RGE_Panel_Tool_Box* tb = this->tool_box;
        if (tb->field_6C != 0) tb->set_active(0); else tb->set_active(1);
        this->handle_size(this->field_14, this->field_18);
        rge_base_game->set_game_mode(0, 0);
        this->set_redraw(1);
    }
}
