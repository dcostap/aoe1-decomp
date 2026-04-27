// scr_game.cpp:5698-5711, 101 bytes
// attempt 1: inline asm forbidden, rewrite
extern void* rge_base_game;
extern int __fastcall get_paused(void* game);
extern void* __fastcall get_player(void* game);
extern void __fastcall set_view_loc(void* player, float x, float y);
extern void __fastcall set_map_loc(void* player, short x, short y);
extern int __ftol(void);

class TRIBE_Screen_Game {
public:
    void command_view_selected();
};

void TRIBE_Screen_Game::command_view_selected() {
    if (get_paused(rge_base_game)) return;
    void* player = get_player(rge_base_game);
    void* selected = *(void**)((char*)player + 0x130);
    if (selected == 0) return;
    float y = *(float*)((char*)selected + 0x3C);
    float x = *(float*)((char*)selected + 0x38);
    set_view_loc(get_player(rge_base_game), x, y);
    int iy = (int)y;
    int ix = (int)x;
    set_map_loc(get_player(rge_base_game), ix, iy);
}
