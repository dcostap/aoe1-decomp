// RGE_Command::do_command_ai_order
// VA: 00434D40

class RGE_Static_Object {
public:
    void removeAllFromPathingGroup();
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    void** players; // actually player pointer array at +0x40
    RGE_Static_Object* object(int id);
};

class PlayerLike {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30();
    virtual void ai_order(unsigned char issuer, int recipient, int orderType, int target,
                          unsigned char targetOwner, int targetX, int targetY, int targetZ,
                          int inFront, unsigned char immediate, unsigned char orderPriority,
                          unsigned char flags);
};

struct RGE_Command_AI_Order {
    unsigned char gap_00;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char gap_03;
    int recipient;
    short orderType;
    unsigned char flags;
    unsigned char gap_0B;
    int target;
    unsigned char targetOwner;
    unsigned char gap_11[3];
    int targetX;
    int targetY;
    int targetZ;
    int inFront;
    unsigned char immediate;
    unsigned char orderPriority;
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;

    void do_command_ai_order(RGE_Command_AI_Order* cmd);
};

void RGE_Command::do_command_ai_order(RGE_Command_AI_Order* cmd) {
    RGE_Static_Object* obj = this->world->object(cmd->recipient);
    if (obj != 0) {
        obj->removeAllFromPathingGroup();
        RGE_Game_World* world = this->world;
        unsigned int pid = cmd->player_id;
        void** players = world->players;
        PlayerLike* player = (PlayerLike*)players[pid];
        unsigned int flags = cmd->flags;
        player->ai_order(cmd->issuer, cmd->recipient, cmd->orderType, cmd->target,
                         cmd->targetOwner, cmd->targetX, cmd->targetY, cmd->targetZ,
                         cmd->inFront, cmd->immediate, cmd->orderPriority, flags);
    }
}
