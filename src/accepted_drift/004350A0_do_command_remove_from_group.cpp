// ACCEPTED_DRIFT: small volatile-register/compare-order drift; only ZF feeds jne, so the same equality predicate controls the same remove call.
struct RGE_Command_Remove_From_Group {
    char gap_00[1];
    unsigned char player_id;
    char gap_02[2];
    int groupCommander;
    int unit;
};

class RGE_Game_World;
class RGE_Static_Object;

struct ObjectOwner {
    char gap_00[0x4A];
    unsigned short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    ObjectOwner* owner;

    int commanderRemoveFromGroup(int unit);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;

    void do_command_remove_from_group(RGE_Command_Remove_From_Group* command);
};

void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group* command) {
    RGE_Static_Object* object = this->world->object(command->groupCommander);
    if ((object != 0) && ((unsigned short)command->player_id == object->owner->id)) {
        object->commanderRemoveFromGroup(command->unit);
    }
}
