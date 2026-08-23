#ifndef BASEGAME_GROUPED_TU
class RGE_Game_Info {
public:
    void notify_of_scenario_complete();
};
class RGE_Base_Game {
public:
    char gap_0[0x4];
    RGE_Game_Info* player_game_info;
    void set_campaign_win();
};
#endif

void RGE_Base_Game::set_campaign_win() {
    this->player_game_info->notify_of_scenario_complete();
}
