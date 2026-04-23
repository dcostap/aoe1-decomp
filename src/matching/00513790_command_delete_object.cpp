class TRIBE_Command {
public:
    void command_cancel_build(void* object);
};

struct PlayerCommandHolder {
    char gap_00[0x58];
    TRIBE_Command* command;
};

struct StaticMaster {
    char gap_00[0x04];
    unsigned char master_type;
};

class TRIBE_Player;

class RGE_Static_Object {
public:
    char gap_00[0x08];
    StaticMaster* master_obj;
    TRIBE_Player* owner;
};

class TRIBE_Player {
public:
    char gap_00[0x3C];
    PlayerCommandHolder* holder;

    unsigned char command_delete_object(RGE_Static_Object* object);
};

unsigned char TRIBE_Player::command_delete_object(RGE_Static_Object* object) {
    unsigned char type;

    if ((object != 0) && (object->owner == this)) {
        type = object->master_obj->master_type;
        if ((type == 'P') || (type == 'F')) {
            this->holder->command->command_cancel_build(object);
            return 1;
        }
    }
    return 0;
}
