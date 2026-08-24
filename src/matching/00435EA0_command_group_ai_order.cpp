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
// - New claim confirmed that a typed packet-plus-one surface is codegen-neutral
//   here.  Early player preservation plus delayed target-owner assignment
//   improved the diagnostic drift to 32 bytes and recovered the original log
//   register/stack topology, but conflicts with the PDB packet-store line
//   order; it is not retained as living source.  Other early-player and
//   late-issuer-local probes were worse or compiler duplicates.
// - Current canonical source is restored to the typed PDB-plausible packet
//   order (38-byte drift); remaining mismatch is the packet assignment
//   scheduling/register basin beginning at 00435F13.
// - Follow-up claim: allocating through the typed packet, restoring the fuller
//   same-TU command class surface, nesting the guards, and replacing typed
//   stores with raw scalar stores were codegen-neutral.  Moving the command
//   constant or recipient count earlier, and a 24-way issuer/priority/player/
//   owner order lab, all remained nonexact; the early-count form regressed to
//   62 bytes.  An explicit vptr/nonvirtual-destructor surface was also neutral.
//   The clean typed PDB-plausible source is restored; the unresolved hunk is
//   not justified by compiler-steering scaffolding.
// - New claim: early recipient-count/player order with delayed target-owner
//   regressed the packet hunk to 62 bytes.  The exact same-TU command_ai_order
//   field order improved block coverage but regressed to 58 bytes; both were
//   restored.  A 24-variant priority/count/owner/player permutation lab kept
//   size, frame, and calls exact but found no exact code; its best was 55 bytes.
//   The clean typed PDB-plausible source remains the best living reconstruction.
// - Follow-up probes in this claim tested player-first and player-plus-early-
//   count packet orders (58 and 55 bytes), a named log-player local, register
//   hints, signed packet-byte fields, and historical local-string context.
//   The local, register, and signed-field forms were compiler duplicates; the
//   string form changed only relocation encoding.  All were restored.
// - Final unchanged validation remains 315 bytes, frame 0x8, four ordered
//   direct calls, and 38 differing bytes from 00435F13.  The unresolved basin
//   is still packet-store scheduling; next evidence should be original source
//   or a new supported VC5 context donor, not opaque steering.
// - New claim found the natural declaration-order packet stores: command,
//   player, issuer, count, order type, priority, target, owner, coordinates,
//   range, and flags.  This typed source matches all 315 bytes with the
//   existing object lookup and logging dispatch; no steering artifacts remain.

#include <stdlib.h>

#define STR_SEND_CMD_GROUP_AI_ORDER \
    "      >SEND CMD GRP AI ORD (PLR=%d, TYP=%d, ISS=%d, CNT=%d, REC=%s, TAR=%s)"
#define STR_X "X"

#ifndef COMMAND_TU_CONTEXT
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
#endif

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
            packet->command = 0x11;
            packet->player_id = (unsigned char)player;
            packet->issuer = (unsigned char)issuer;
            packet->recipient_count = (unsigned char)list_num;
            packet->orderType = (short)order_type;
            packet->orderPriority = order_priority;
            packet->target = target;
            packet->targetOwner = (unsigned char)target_owner;
            packet->targetX = target_x;
            packet->targetY = target_y;
            packet->targetZ = target_z;
            packet->range = range;
            packet->immediate = immediate;
            packet->inFront = in_front;

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
