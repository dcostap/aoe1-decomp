class RGE_Master_Static_Object;

class RGE_Victory_Conditions {
public:
    unsigned char victory_achieved(void);
};

class RGE_Player {
public:
    virtual void vf00(void);
    virtual void set_game_status(unsigned char param_1);

    char gap_04[0x10];
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    char gap_21[0x03];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x0C];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x48];
    unsigned char game_status;

    unsigned char check_victory_conditions(void);
};

unsigned char RGE_Player::check_victory_conditions(void) {
    if (this->game_status != 2) {
        return this->victory_conditions->victory_achieved();
    }
    return 1;
}
