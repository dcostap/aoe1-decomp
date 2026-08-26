// VA: 0041CF30 RGE_Base_Game::get_campaign_info
// Exact under VC5 host with default /O2 /Oy flags.
// The +0x04 member is RGE_Game_Info::player_game_info. Keep the three
// direct getter calls and output stores in this order.


void RGE_Base_Game::get_campaign_info(long& campaign, long& player, long& num_campaigns) {
    int c = this->player_game_info->get_current_campaign();
    campaign = c;
    int p = this->player_game_info->get_current_player();
    player = p;
    int n = this->player_game_info->get_current_scenario();
    num_campaigns = n;
}
