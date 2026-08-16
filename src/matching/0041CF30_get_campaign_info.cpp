// VA: 0041CF30 RGE_Base_Game::get_campaign_info
// Exact under VC5 host with default /O2 /Oy flags.
// The +0x04 member is RGE_Game_Info::player_game_info. Keep the three
// direct getter calls and output stores in this order.

class RGE_Game_Info {
public:
    int get_current_campaign(void);
    int get_current_player(void);
    int get_current_scenario(void);
};

class RGE_Base_Game {
public:
    void get_campaign_info(int* campaign, int* player, int* num_campaigns);
    char gap_00[0x04];
    RGE_Game_Info* player_game_info;
};

void RGE_Base_Game::get_campaign_info(int* campaign, int* player, int* num_campaigns) {
    int c = this->player_game_info->get_current_campaign();
    *campaign = c;
    int p = this->player_game_info->get_current_player();
    *player = p;
    int n = this->player_game_info->get_current_scenario();
    *num_campaigns = n;
}
