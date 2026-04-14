struct Inner_00422FD0 {
    void reload_scenarios_info();
};

class RGE_Base_Game {
public:
    char gap_0[0x8];
    Inner_00422FD0 *ptr_;
    void reload_scenarios_info();
};

void RGE_Base_Game::reload_scenarios_info() {
    this->ptr_->reload_scenarios_info();
}
