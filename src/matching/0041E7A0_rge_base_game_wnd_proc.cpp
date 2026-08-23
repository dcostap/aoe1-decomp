#ifndef BASEGAME_GROUPED_TU
struct RGE_Base_Game {
    void** vftable;
};
#endif

typedef unsigned long (__stdcall *RGE_Base_Game_WndProc)(RGE_Base_Game*, unsigned int, unsigned int, unsigned int, unsigned int);

extern RGE_Base_Game* rge_base_game;

unsigned long __stdcall rge_base_game_wnd_proc(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    RGE_Base_Game* game = rge_base_game;

    if (game != 0) {
#ifdef BASEGAME_GROUPED_TU
        return ((RGE_Base_Game_WndProc)(*(void***)game)[2])(game, a, b, c, d);
#else
        return ((RGE_Base_Game_WndProc)game->vftable[2])(game, a, b, c, d);
#endif
    }
    return 0;
}
