#ifndef COMMAND_TU_CONTEXT
struct RGE_Command_Destroy_Group {
    char gap_00[1];
    unsigned char player_id;
    char gap_02[2];
    int groupCommander;
};

class RGE_Game_World {
public:
    void* object(int id);
};

class RGE_Static_Object_Owner {
public:
    char gap_00[0x4A];
    unsigned short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Static_Object_Owner* owner;

    int commanderDestroyGroup(void);
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;

    void do_command_destroy_group(RGE_Command_Destroy_Group* cmd);
};
#endif

void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group* cmd) {
    RGE_Static_Object* obj = (RGE_Static_Object*)this->world->object(cmd->groupCommander);
    // The nested guard preserves the original register and branch order.
    if (obj != 0) {
        if (obj->owner->id == (unsigned short)cmd->player_id)
            obj->commanderDestroyGroup();
    }
}
