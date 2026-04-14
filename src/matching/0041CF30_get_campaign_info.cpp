// get_campaign_info (0041CF30) - basegame.cpp
// Fetches campaign info from game_info member

class RGE_Campaign_Info {
public:
    int get_current_campaign(void);
    int get_current_player(void);
    int get_number_campaigns(void);
};

class RGE_Base_Game_campaign {
public:
    void get_campaign_info(int* campaign, int* player, int* num_campaigns);

    char gap_00[0x04];
    RGE_Campaign_Info* game_info;  // +0x04
};

void RGE_Base_Game_campaign::get_campaign_info(int* campaign, int* player, int* num_campaigns) {
    int c = this->game_info->get_current_campaign();
    *campaign = c;
    int p = this->game_info->get_current_player();
    *player = p;
    int n = this->game_info->get_number_campaigns();
    *num_campaigns = n;
}
