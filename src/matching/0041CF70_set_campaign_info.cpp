unsigned char RGE_Base_Game::set_campaign_info(long campaign, long person, long scenario) {
    unsigned char ok;

    ok = this->player_game_info->set_current_campaign(campaign);
    if (ok != 0) {
        ok = this->player_game_info->set_current_person(person);
        if (ok != 0) {
            ok = this->player_game_info->set_current_scenario(scenario);
            if (ok != 0) {
                return 1;
            }
        }
    }
    return 0;
}
