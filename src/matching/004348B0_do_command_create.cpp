#ifndef COMMAND_TU_CONTEXT
class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float location_x,
                                             float location_y, float location_z);
};

struct RGE_Player {
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
};

struct RGE_Game_World {
    char gap_00[0x40];
    RGE_Player** players;
};
#endif

#ifndef COMMAND_TU_CONTEXT
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
#endif

#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    void do_command_create(RGE_Command_Create* param_1);
};
#endif

void RGE_Command::do_command_create(RGE_Command_Create* param_1) {
    RGE_Player* player = this->world->players[param_1->player_id];
    RGE_Master_Static_Object* master = player->master_objects[param_1->obj_catagory];
    master->make_new_obj(player, param_1->location_x, param_1->location_y,
                         param_1->location_z);
}
