// VA: 00435AE0 RGE_Command::command_formation (207B)
// Command.cpp lines 1724-1767.
//
// Attempt log:
// - Replaced the stale placeholder with the period-plausible formation packet
//   builder supported by the original calloc, ID-copy, logging, and submit
//   sequence.
// - The natural typed ownership surface and default VC5 flags matched all 207
//   bytes; no codegen-only scaffolding was needed.

#include <stdlib.h>

#define STR_SEND_CMD_FORMATION "      >SEND CMD FORMATION (CNT=%d,OWN=%d,UNIT=%s)"
#define STR_X                  "X"

#ifndef COMMAND_TU_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[8];
    const char* name;
};

class RGE_Player {
public:
    virtual void v00();
    char gap_04[0x46];
    short id;
};

class RGE_Static_Object {
public:
    virtual void v00();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    void submit(void* buf, long size);
    void command_formation(RGE_Static_Object** list, int list_num,
                           int formation);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};
#endif

extern TDebuggingLog* L;

void RGE_Command::command_formation(RGE_Static_Object** list, int list_num,
                                    int formation)
{
    int size = list_num * 4 + 0x0C;

    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 0x0C);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            buf[0] = 6;
            *(int*)(buf + 4) = list_num & 0xFF;
            *(int*)(buf + 8) = formation;

            RGE_Static_Object* obj = list[0];
            const char* name;
            int owner;
            if (obj != 0) {
                name = obj->master_obj->name;
            } else {
                name = STR_X;
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log(STR_SEND_CMD_FORMATION, list_num, owner, name);
            this->submit(buf, size);
        }
    }
}
