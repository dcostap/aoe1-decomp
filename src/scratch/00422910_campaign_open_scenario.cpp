struct Inner_00422910 {
    void campaign_open_scenario();
};

class RGE_Base_Game {
public:
    char gap_0[0x4];
    Inner_00422910 *ptr_;
    void campaign_open_scenario();
};

void RGE_Base_Game::campaign_open_scenario() {
    this->ptr_->campaign_open_scenario();
}
