struct Inner_00420560 {
    void target(int param);
};

class RGE_Base_Game {
public:
    char gap_0[0x1C0];
    Inner_00420560 *ptr_;
    void set_mouse_facet(int param);
};

void RGE_Base_Game::set_mouse_facet(int param) {
    this->ptr_->target(param);
}
