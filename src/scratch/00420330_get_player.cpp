RGE_Player* RGE_Base_Game::get_player(void) {
    RGE_Game_World* w = this->world;
    if (!w) return 0;
    if (!w->player_num) return 0;
    if (w->curr_player >= w->player_num) return 0;
    return w->players[(int)(short)w->curr_player];
}
