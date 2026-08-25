class RGE_Master_Static_Object;
class RGE_Victory_Conditions;

#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    virtual void changeToHumanPlayer(void);
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

    void victory_if_game_on(void);
};
#endif

void RGE_Player::victory_if_game_on(void) {
    if (this->game_status == 0) {
        this->set_game_status(1);
    }
}
