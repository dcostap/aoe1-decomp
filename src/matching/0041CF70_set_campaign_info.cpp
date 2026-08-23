#ifndef BASEGAME_GROUPED_TU
class RGE_Game_Info {
public:
    unsigned char set_current_campaign(long campaign);
    unsigned char set_current_person(long person);
    unsigned char set_current_scenario(long scenario);
};

class RGE_Base_Game {
public:
    char gap_00[0x4];
    RGE_Game_Info* player_game_info;

    unsigned char set_campaign_info(long campaign, long person, long scenario);
};
#endif

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
