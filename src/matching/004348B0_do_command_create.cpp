class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void create(RGE_Player* player, float location_x, float location_y, float location_z);
};

struct RGE_Player {
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
};

struct RGE_Game_World {
    char gap_00[0x40];
    RGE_Player** players;
};

struct RGE_Command_Create {
    unsigned char command;
    unsigned char _pad_0[0x1];
    short obj_catagory;
    unsigned char player_id;
    unsigned char _pad_1[0x3];
    float location_x;
    float location_y;
    float location_z;
};

class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    void do_command_create(RGE_Command_Create* param_1);
};

void RGE_Command::do_command_create(RGE_Command_Create* param_1) {
    RGE_Player* player = this->world->players[param_1->player_id];
    RGE_Master_Static_Object* master = player->master_objects[param_1->obj_catagory];
    master->create(player, param_1->location_x, param_1->location_y, param_1->location_z);
}
