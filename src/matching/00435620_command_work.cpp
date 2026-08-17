// VA: 00435620 RGE_Command::command_work (256B)
// PDB: Command.cpp lines 1405-1468
// Attempt log:
// - Replaced the placeholder with the natural selected-unit work packet builder.
// - The packet uses the proven +0x14 variable ID array, target ID, count, and
//   coordinate fields; logging follows the original target-name then unit-name
//   and owner evaluation order.
// - The best reconstruction is 256 bytes with the original three direct calls,
//   exact size/frame, and 86.96% instruction-shape similarity (180 positional
//   bytes remain). Count/pointer aliases and source-order variants were
//   codegen duplicates or introduced an 8-byte frame; the remaining mismatch
//   is the early VC5 prologue/list-pointer coloring and later logging topology.
// - Probe 14 (new claim) removed the unused world member while comparing the
//   local command surface with the exact command_order sibling; emitted code
//   was unchanged, so the actual world field remains in the canonical stub.
// - Probe 15 split first-unit name selection and owner-id selection into two
//   ordinary if statements, matching the exact sibling's source topology.
//   This changed the compiler basin to an exact 256-byte match, including the
//   original list-pointer prologue and logging sequence.
// - Main-agent audit replaced the remaining header byte-offset stores with the
//   canonical typed work-packet fields; emitted code remains exact.

#include <stdlib.h>

#define STR_SEND_CMD_WORK "      >SEND CMD WORK (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)"
#define STR_X             "X"

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int id;
    const char* name;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

struct RGE_Command_Work {
    unsigned char command;
    unsigned char gap_01[3];
    int target;
    unsigned char recipient_count;
    unsigned char gap_09[3];
    float target_x;
    float target_y;
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    void* world;
    void submit(void* buf, long size);
    void command_work(RGE_Static_Object** list, short list_num,
                      RGE_Static_Object* target, float x, float y);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void RGE_Command::command_work(RGE_Static_Object** list, short list_num,
                               RGE_Static_Object* target, float x, float y)
{
    int size = list_num * 4 + 0x14;

    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        RGE_Command_Work* packet = (RGE_Command_Work*)buf;
        int* dst = (int*)(packet + 1);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            if (target != 0) {
                packet->target = target->id;
            } else {
                packet->target = -1;
            }
            packet->command = 2;
            packet->recipient_count = (unsigned char)list_num;
            packet->target_x = x;
            packet->target_y = y;

            const char* target_name;
            if (target != 0) {
                target_name = target->master_obj->name;
            } else {
                target_name = STR_X;
            }

            RGE_Static_Object* obj = list[0];
            const char* unit_name;
            int owner;
            if (obj != 0) {
                unit_name = obj->master_obj->name;
            } else {
                unit_name = STR_X;
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log(STR_SEND_CMD_WORK, list_num, owner, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}
