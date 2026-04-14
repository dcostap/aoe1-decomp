class RGE_Flic_Player {
public:
    virtual ~RGE_Flic_Player();
    char gap_0[0x14];
    int field_18;
    int time_delay();
};

int RGE_Flic_Player::time_delay() { return this->field_18; }
