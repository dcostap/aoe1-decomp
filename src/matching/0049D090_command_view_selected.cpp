// VA: 0049D090 TRIBE_Screen_Game::command_view_selected
// Source: scr_game.cpp:5698-5711
// EXACT MATCH: 3x inline get_player() instead of cached local forces reloads

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    int get_paused();
    void* get_player();
};

class RGE_Game_State {
public:
    void set_view_loc(float x, float y);
};

class RGE_PlayerExt : public RGE_Game_State {
public:
    void set_map_loc(short x, short y);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_view_selected();
};
#endif

void TRIBE_Screen_Game::command_view_selected() {
    if (rge_base_game->get_paused()) return;

    void* sel = *(void**)((char*)rge_base_game->get_player() + 0x130);
    if (sel == 0) return;

    ((RGE_PlayerExt*)rge_base_game->get_player())->set_view_loc(
        *(float*)((char*)sel + 0x38), *(float*)((char*)sel + 0x3C));

    ((RGE_PlayerExt*)rge_base_game->get_player())->set_map_loc(
        (short)(int)*(float*)((char*)sel + 0x38),
        (short)(int)*(float*)((char*)sel + 0x3C));
}
