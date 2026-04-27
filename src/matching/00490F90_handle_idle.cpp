// attempt 1: direct decompiler-shaped if chain, member-call base idle
// result: first mismatch was the class layout; campaignList landed 4 bytes late
// next try: keep the same block shape, but trim the local stub padding to account for the vptr

class TPanel {
public:
    virtual long handle_idle();
    void set_curr_child(TPanel* child);
};

class TScreenPanel : public TPanel {
public:
    virtual long handle_idle();
};

class RGE_Base_Game {
public:
    char gap_0[0x1D8];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Campaign_Selection : public TScreenPanel {
public:
    char gap_0[0x48C];
    TPanel* campaignList; // +0x490
    char gap_1[0x34];
    int campaignsLoaded; // +0x4C8

    void fillCampaigns();
    void fillScenarios();
    long handle_idle();
};

long TRIBE_Screen_Campaign_Selection::handle_idle() {
    if (this->campaignsLoaded == 0) {
        this->fillCampaigns();
        this->fillScenarios();
        this->set_curr_child(this->campaignList);
        this->campaignsLoaded = 1;
    }

    if (this->campaignsLoaded != 0) {
        if (rge_base_game->input_enabled == 0) {
            rge_base_game->enable_input();
        }
    }

    return TPanel::handle_idle();
}
