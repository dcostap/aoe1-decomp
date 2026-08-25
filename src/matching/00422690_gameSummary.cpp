static char game_summary_buf;


char* RGE_Base_Game::gameSummary() {
    game_summary_buf = 0;
    return &game_summary_buf;
}
