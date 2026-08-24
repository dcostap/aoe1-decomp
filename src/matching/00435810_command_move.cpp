// VA: 00435810 RGE_Command::command_move (239B)
// PDB: Command.cpp lines 1522-1580
// Attempt log:
// - Replaced the generated placeholder with the natural selected-unit move
//   packet builder, using the neighboring exact Command.cpp packet builders
//   for the object, owner, logging, and submit surfaces.

#include <stdlib.h>

#define STR_SEND_CMD_MOVE "      >SEND CMD MOVE (CNT=%d,OWN=%d,UNIT=%s)"
#define STR_X             "X"

#ifndef COMMAND_TU_CONTEXT
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
    void submit(void* buf, long size);
    void command_move(RGE_Static_Object** list, short list_num,
                      RGE_Static_Object* target, float x, float y);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};
#endif

extern TDebuggingLog* L;

void RGE_Command::command_move(RGE_Static_Object** list, short list_num,
                               RGE_Static_Object* target, float x, float y)
{
    if (list != 0 && list_num >= 1) {
        int size = list_num * 4 + 0x14;
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
            buf[0] = 3;
            buf[8] = (unsigned char)list_num;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;

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

            L->Log(STR_SEND_CMD_MOVE, list_num, owner, name);
            this->submit(buf, size);
        }
    }
}
