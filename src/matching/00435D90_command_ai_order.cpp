// VA: 00435D90 command_ai_order (271B)
// Command.cpp lines 1896-1934.
// Attempt log:
// - Reconstructed the natural AI-order packet builder from the proven 0x28-byte
//   packet layout, object-name lookups, logging format, and submit call.
// - Main-agent audit restored canonical master/object/world polymorphism;
//   emitted code remains exact.

#include <stdlib.h>

#define STR_SEND_CMD_AI_ORDER ((const char*)0x00583E24)
#define STR_X                 ((const char*)0x00583B74)

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[4];
    const char* name;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

struct RGE_Command_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char gap_03;
    int recipient;
    short orderType;
    unsigned char orderPriority;
    unsigned char gap_0B;
    int target;
    unsigned char targetOwner;
    unsigned char gap_11[3];
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
    unsigned char gap_26[2];
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    RGE_Game_World* world;

    void command_ai_order(int player, int issuer, int recipient, int order_type,
                          int target, int target_owner, float target_x,
                          float target_y, float target_z, float range,
                          unsigned char immediate, unsigned char in_front,
                          unsigned char order_priority);
    void submit(void* buf, long size);
};

void RGE_Command::command_ai_order(int player, int issuer, int recipient,
                                   int order_type, int target, int target_owner,
                                   float target_x, float target_y, float target_z,
                                   float range, unsigned char immediate,
                                   unsigned char in_front,
                                   unsigned char order_priority)
{
    RGE_Command_AI_Order* cmd =
        (RGE_Command_AI_Order*)calloc(1, sizeof(RGE_Command_AI_Order));

    cmd->player_id = (unsigned char)player;
    cmd->issuer = (unsigned char)issuer;
    cmd->orderType = (short)order_type;
    cmd->orderPriority = order_priority;
    cmd->targetOwner = (unsigned char)target_owner;
    cmd->targetX = target_x;
    cmd->targetY = target_y;
    cmd->targetZ = target_z;
    cmd->command = 10;
    cmd->recipient = recipient;
    cmd->target = target;
    cmd->range = range;
    cmd->immediate = immediate;
    cmd->inFront = in_front;

    RGE_Static_Object* recipient_obj = this->world->object(recipient);
    RGE_Static_Object* target_obj = this->world->object(target);

    const char* target_name;
    if (target_obj != 0)
        target_name = target_obj->master_obj->name;
    else
        target_name = STR_X;

    const char* recipient_name;
    if (recipient_obj != 0)
        recipient_name = recipient_obj->master_obj->name;
    else
        recipient_name = STR_X;

    L->Log(STR_SEND_CMD_AI_ORDER, player, order_type, issuer, recipient,
           recipient_name, target, target_name, (long)target_x, (long)target_y);
    this->submit(cmd, 0x28);
}
