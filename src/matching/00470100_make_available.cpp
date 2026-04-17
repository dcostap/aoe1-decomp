class RGE_Master_Static_Object {
public:
    void make_available(unsigned char param_1);
};

class RGE_Victory_Conditions;

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

    void make_available(short param_1, unsigned char param_2);
};

void RGE_Player::make_available(short param_1, unsigned char param_2) {
    RGE_Master_Static_Object* master_object;

    master_object = this->master_objects[param_1];
    if (master_object != 0) {
        master_object->make_available(param_2);
    }
}
