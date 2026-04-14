class RGE_Player {
public:
    char gap_0[0x11C];
    short field_11C;
    short field_11E;
    void set_map_loc(short a, short b);
};

void RGE_Player::set_map_loc(short a, short b) {
    this->field_11C = a;
    this->field_11E = b;
}
