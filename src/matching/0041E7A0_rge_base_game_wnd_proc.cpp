extern RGE_Base_Game* rge_base_game;

unsigned long __stdcall rge_base_game_wnd_proc(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    RGE_Base_Game* game = rge_base_game;
    if (game != 0)
        return (unsigned long)game->wnd_proc((void*)a, b, c, (long)d);
    return 0;
}
