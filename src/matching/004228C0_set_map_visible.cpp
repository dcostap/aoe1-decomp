struct Inner_004228C0 {
    void target(int param);
};

class RGE_Base_Game {
public:
    char gap_0[0x3F4];
    Inner_004228C0 *inner_;
    void set_map_visible(int param);
};

void RGE_Base_Game::set_map_visible(int param) {
    if (this->inner_)
        this->inner_->target(param);
}
