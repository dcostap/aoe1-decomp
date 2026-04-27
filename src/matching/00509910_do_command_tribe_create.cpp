#include <windows.h>

class RGE_Static_Object;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Game_World;

class RGE_Command {
public:
    virtual void vfunc0() = 0;
    virtual ~RGE_Command() {}
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual void vfunc0() = 0;
    virtual void vfunc4() = 0;
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;
    virtual void vfunc10() = 0;
    virtual void vfunc14() = 0;
    virtual RGE_Static_Object* create_obj(RGE_Player* player, float x, float y, float z) = 0;
    unsigned char type;
    char gap_05[0x68 - 0x05];
    unsigned char flag_68;
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    void build(float amount);
};

struct RGE_Command_Create {
    char gap_00[2];
    short obj_category;
    unsigned char player_id;
    char gap_05[3];
    float location_x;
    float location_y;
    float location_z;
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_tribe_create(RGE_Command_Create* cmd);
};

void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* cmd)
{
    int player_offset = (unsigned int)cmd->player_id * 4;
    int category_offset = (int)cmd->obj_category * 4;

    if (this->world->players[cmd->player_id]->master_objects[cmd->obj_category]->flag_68 == 1) {
        cmd->location_z = 4.0f;
    }

    RGE_Static_Object* obj = this->world->players[cmd->player_id]->master_objects[cmd->obj_category]->create_obj(
        this->world->players[cmd->player_id],
        cmd->location_x,
        cmd->location_y,
        cmd->location_z);

    if (obj->master_obj->type == 0x50) {
        ((TRIBE_Building_Object*)obj)->build(10000.0f);
    }
}
