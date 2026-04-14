class RGE_Flic_Player {
public:
    virtual ~RGE_Flic_Player();
    char gap_0[0xA];
    short field_E;
    short frames();
};

short RGE_Flic_Player::frames() { return this->field_E; }
