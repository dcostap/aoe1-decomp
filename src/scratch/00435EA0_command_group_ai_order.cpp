// VA: 00435EA0 RGE_Command::command_group_ai_order (315B)
// PDB: Command.cpp lines 1942-1997
// Attempt log:
// - Reconstructed the group AI-order packet from the proven 0x24-byte header,
//   selected-object ID array, world object lookup, and logging call.
// - Baseline uses the exact Command.cpp sibling surfaces for command/world/
//   object/master declarations and the ABI proven by command_stand_ground.
// - Typed packet fields emitted the same 62-byte drift as the raw known-offset
//   stores.  Count/priority and nearby source-order probes either duplicated
//   that basin or changed the frame; the clean typed record remains canonical.
// - Moving recipient_count into the late packet-tail assignment group reached
//   a 36-byte diagnostic best while preserving size, frame, calls, and packet
//   behavior.  A 24-variant store-order lab found no exact candidate (best
//   invariant-eligible group was still nonexact), so no generated variant is
//   retained as living source.
// - Original log stack evidence shows the third integer is issuer, not
//   target_owner.  The final source keeps issuer for behavioral fidelity; its
//   current codegen is 38 bytes different and remains in scratch after the
//   bounded 10-probe assignment.

#include <stdlib.h>

#define STR_SEND_CMD_GROUP_AI_ORDER ((const char*)0x00583E78)
#define STR_X                       ((const char*)0x00583B74)

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int id;
    const char* name;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

struct RGE_Command_Group_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char recipient_count;
    short orderType;
    unsigned char orderPriority;
    unsigned char gap_07;
    int target;
    unsigned char targetOwner;
    unsigned char gap_0D[3];
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
    unsigned char gap_22[2];
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    RGE_Game_World* world;
    void submit(void* buf, long size);
    void command_group_ai_order(int player, int issuer,
                                RGE_Static_Object** list, short list_num,
                                int order_type, int target, int target_owner,
                                float target_x, float target_y, float target_z,
                                float range, unsigned char immediate,
                                unsigned char in_front,
                                unsigned char order_priority);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void RGE_Command::command_group_ai_order(
    int player, int issuer, RGE_Static_Object** list, short list_num,
    int order_type, int target, int target_owner, float target_x,
    float target_y, float target_z, float range, unsigned char immediate,
    unsigned char in_front, unsigned char order_priority)
{
    if (list != 0 && list_num >= 1) {
        int size = list_num * 4 + 0x24;
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 0x24);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            RGE_Command_Group_AI_Order* packet =
                (RGE_Command_Group_AI_Order*)buf;
            packet->issuer = (unsigned char)issuer;
            packet->orderPriority = order_priority;
            packet->targetOwner = (unsigned char)target_owner;
            packet->targetX = target_x;
            packet->targetY = target_y;
            packet->target = target;
            packet->targetZ = target_z;
            packet->range = range;
            packet->command = 0x11;
            packet->player_id = (unsigned char)player;
            packet->orderType = (short)order_type;
            packet->immediate = immediate;
            packet->inFront = in_front;
            packet->recipient_count = (unsigned char)list_num;

            RGE_Static_Object* target_obj = this->world->object(target);
            const char* target_name;
            if (target_obj != 0) {
                target_name = target_obj->master_obj->name;
            } else {
                target_name = STR_X;
            }

            RGE_Static_Object* obj = list[0];
            const char* unit_name;
            if (obj != 0) {
                unit_name = obj->master_obj->name;
            } else {
                unit_name = STR_X;
            }

            L->Log(STR_SEND_CMD_GROUP_AI_ORDER, player, order_type,
                   issuer, list_num, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}
