#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    char gap_0[0x11C];
    short field_11C;
    short field_11E;
    void set_map_loc(short a, short b);
};
#endif

void RGE_Player::set_map_loc(short a, short b) {
    this->map_x = a;
    this->map_y = b;
}
