void RGE_Base_Game::setPlayerTeam(int i, unsigned char v) {
    RGE_Game_Options* options = (RGE_Game_Options*)this->game_options;
    options->playerTeamValue[i] = v;
}
