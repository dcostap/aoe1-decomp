// first pass: straight object lookup + owner-id gate + commanderCreateGroup call
// tried nested ifs and early returns; still off in the owner-id compare/register shape
// tried byte and short player_id locals; VC5 kept choosing cx/CL-style compare shapes instead of the original dx path
// if this misses, the remaining gap is probably argument shape / exact class layout around owner->id
class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    void commanderCreateGroup(int* unitsToGroup, unsigned char numberUnitsToGroup, int groupCommander, float groupRange);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Static_Object* object(int id);
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

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;
    void do_command_create_group(RGE_Command_Create_Group* param_1);
};

void RGE_Command::do_command_create_group(RGE_Command_Create_Group* param_1) {
    RGE_Static_Object* this_00 = this->world->object(param_1->groupCommander);
    unsigned char player_id = param_1->player_id;
    if (this_00 == 0)
        return;
    if (this_00->owner->id != player_id)
        return;
    this_00->commanderCreateGroup(param_1->unitsToGroup, param_1->numberUnitsToGroup, param_1->groupCommander, param_1->groupRange);
}
