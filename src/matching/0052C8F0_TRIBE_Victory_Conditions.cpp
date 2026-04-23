class RGE_Player;

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    RGE_Victory_Conditions(RGE_Player* player, int value, long* data, unsigned char flag);
};

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    TRIBE_Victory_Conditions(RGE_Player* player, int value, long* data, unsigned char flag);
};

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* player, int value, long* data, unsigned char flag)
    : RGE_Victory_Conditions(player, value, data, flag) {
}
