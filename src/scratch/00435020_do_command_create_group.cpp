// Attempt 14: unsigned short pid local only. With commanderCreateGroup taking int for 
// numberUnitsToGroup, the implicit promotion should produce xor ecx,ecx naturally.
// Trying to tip register allocation by loading pid into a specific register first.

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Command_Create_Group;

class RGE_Command {
public:
    void* vtable_ptr;
    RGE_Game_World* world;
    void do_command_create_group(RGE_Command_Create_Group* param_1);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    int commanderCreateGroup(int* unitsToGroup, int numberUnitsToGroup, int groupCommander, float groupRange);
};

class RGE_Command_Create_Group {
public:
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    unsigned char numberUnitsToGroup;
};

void RGE_Command::do_command_create_group(RGE_Command_Create_Group* param_1) {
    RGE_Static_Object* obj = this->world->object(param_1->groupCommander);
    unsigned short pid = (unsigned short)param_1->player_id;
    if (obj == 0)
        return;
    if (obj->owner->id != pid)
        return;
    obj->commanderCreateGroup(param_1->unitsToGroup, param_1->numberUnitsToGroup, param_1->groupCommander, param_1->groupRange);
}
