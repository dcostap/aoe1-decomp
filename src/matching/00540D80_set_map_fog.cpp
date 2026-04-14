struct Inner_00540D80 {
    void target(int param);
};

class RGE_Game_World {
public:
    char gap_0[0x28];
    Inner_00540D80 *inner_;
    void set_map_fog(int param);
};

void RGE_Game_World::set_map_fog(int param) {
    if (this->inner_)
        this->inner_->target(param);
}
