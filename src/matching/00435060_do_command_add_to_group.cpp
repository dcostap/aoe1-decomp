// ACCEPTED_DRIFT: small volatile-register allocation drift in the player/type compare; same equality predicate, calls, argument pushes, and stack cleanup.
// Exact translation-unit finish: the ordered Command.cpp subset beginning at
// 004348F0 selects DX for player_id and ECX for owner. All 54 bytes match.
#ifndef COMMAND_CONTEXT_H
struct RGE_Command_Add_To_Group {
    char gap_00[1];
    unsigned char player_id;
    char gap_02[2];
    int groupCommander;
    int groupRange;
    int newUnit;
};

class OwnerStub {
public:
    char gap_00[0x4A];
    unsigned short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    OwnerStub* owner;

    int commanderAddToGroup(int newUnit, int groupRange);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;

    void do_command_add_to_group(RGE_Command_Add_To_Group* command);
};
#endif

void RGE_Command::do_command_add_to_group(RGE_Command_Add_To_Group* command) {
    RGE_Static_Object* object = this->world->object(command->groupCommander);
    if ((object != 0) && (object->owner->id == (unsigned short)command->player_id)) {
        int newUnit = command->newUnit;
        int groupRange = command->groupRange;
        object->commanderAddToGroup(newUnit, groupRange);
    }
}
