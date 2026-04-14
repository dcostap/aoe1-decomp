struct Inner_0041CFC0 {
    void set_campaign_win();
};

class RGE_Base_Game {
public:
    char gap_0[0x4];
    Inner_0041CFC0 *ptr_;
    void set_campaign_win();
};

void RGE_Base_Game::set_campaign_win() {
    this->ptr_->set_campaign_win();
}
