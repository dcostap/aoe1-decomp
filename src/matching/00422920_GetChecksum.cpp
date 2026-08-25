



long RGE_Base_Game::GetChecksum(long param_1) {
    RGE_Game_World* world = this->world;
    if (world != 0) {
        if (param_1 < 0) {
            return world->players[world->curr_player]->get_checksum();
        }
        if (param_1 < world->player_num) {
            return world->players[param_1]->get_checksum();
        }
    }
    return 0;
}
