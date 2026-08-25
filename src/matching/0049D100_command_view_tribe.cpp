#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_view_tribe()
{
    if (rge_base_game->get_paused() == 0) {
        TRIBE_Player* player = rge_base_game->get_player(0x6d, 0);
        RGE_Static_Object* obj = player->find_obj();
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc((short)(int)obj->world_x, (short)(int)obj->world_y);
            main_view->set_redraw(1);
        }
    }
}
