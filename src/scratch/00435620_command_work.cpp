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

#include <stdlib.h>

#define STR_SEND_CMD_WORK ((const char*)0x00583BF0)
#define STR_X             ((const char*)0x00583B74)

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
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            if (target != 0) {
                *(int*)(buf + 4) = target->id;
            } else {
                *(int*)(buf + 4) = -1;
            }
            buf[0] = 2;
            buf[8] = (unsigned char)list_num;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;

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
                owner = obj->owner->id;
            } else {
                unit_name = STR_X;
                owner = -1;
            }

            L->Log(STR_SEND_CMD_WORK, list_num, owner, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}
