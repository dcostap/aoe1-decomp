struct Inner_1BF0 {
    void setVisible(int val);
};

class RGE_Game_World {
public:
    char gap_0[0x38];
    Inner_1BF0 *ptr;
    void set_map_visible();
};

void RGE_Game_World::set_map_visible() {
    this->ptr->setVisible(1);
}
