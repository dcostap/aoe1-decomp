int RGE_Base_Game::playerTeam(int player) {
    RGE_Game_Options* options = (RGE_Game_Options*)this->game_options;
    return options->playerTeamValue[player];
}
