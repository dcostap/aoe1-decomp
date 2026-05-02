// Attempt 15: Cast BOTH sides to unsigned short - same type for both cmp operands
// Trying to tip register allocator by making comparison operands match in type width

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
    if (obj == 0)
        return;
    if ((unsigned short)obj->owner->id != (unsigned short)param_1->player_id)
        return;
    obj->commanderCreateGroup(param_1->unitsToGroup, param_1->numberUnitsToGroup, param_1->groupCommander, param_1->groupRange);
}
