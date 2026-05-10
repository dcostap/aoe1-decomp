// RGE_Command::do_command_ai_order
// VA: 00434D40
//
// Attempt log:
// - Initial scratch used byte-width virtual ai_order parameters and a flags local. Behavior was close but codegen
//   either produced a 112-byte text with register-pressure/scheduling drift or saved EBX and failed to zero-extend
//   several byte arguments in the original push sequence.
// - SpruceGlow tries 1-13: no-local forms, removing flags local, signed/short order casts, raw vcall typedef,
//   null-return shape, recipient local, argument-local variants, and __stdcall virtual declaration were worse or
//   wrong-size. Raw vcall avoided some member-call issues but changed vtable/register shape.
// - SpruceGlow try 14 MATCH: declare the virtual ai_order byte-like parameters as unsigned int in the visible
//   callee surface. This makes VC5 naturally emit the original `xor eax,eax; mov al,[esi+off]; push eax` for each
//   narrow field while preserving the virtual member call through [edx+34h].
// Result: MATCH locally with `python tools/check_function.py --va 00434D40`.

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
    virtual void ai_order(unsigned int issuer, int recipient, int orderType, int target,
                          unsigned int targetOwner, int targetX, int targetY, int targetZ,
                          int inFront, unsigned int immediate, unsigned int orderPriority,
                          unsigned int flags);
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
        PlayerLike* player = (PlayerLike*)world->players[cmd->player_id];
        player->ai_order(cmd->issuer, cmd->recipient, cmd->orderType, cmd->target,
                         cmd->targetOwner, cmd->targetX, cmd->targetY, cmd->targetZ,
                         cmd->inFront, cmd->immediate, cmd->orderPriority, cmd->flags);
    }
}
