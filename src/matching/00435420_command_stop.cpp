// VA: 00435420 RGE_Command::command_stop (200B)
// Baseline: natural command-packet construction from the Command.cpp call and
// field evidence.  Keep the proven RGE_Static_Object ownership surface local.
// Attempt log:
// - Hoisted the packet-size calculation before the input guard; this restored the
//   original 8-byte frame and early short-count load.
// - Spelled the count guard as >= 1; this restored cmp ax,1 / jl.
// - Kept name and owner selection as sibling null-tested blocks; exact match.
#include <stdlib.h>

#define STR_SEND_CMD_STOP ((const char*)0x00583B78)
#define STR_X             ((const char*)0x00583B74)

class RGE_Master_Static_Object {
public:
    char gap_00[8];
    const char* name;
};

class RGE_Player {
public:
    virtual void p00();
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
    void command_stop(RGE_Static_Object** list, short list_num);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void RGE_Command::command_stop(RGE_Static_Object** list, short list_num)
{
    int size = list_num * 4 + 2;
    if (list != 0 && list_num >= 1) {
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 2);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) dst[i] = list[i]->id;
                else dst[i] = -1;
            }
            buf[0] = 1;
            buf[1] = (char)list_num;
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
            L->Log(STR_SEND_CMD_STOP, list_num, owner, name);
            this->submit(buf, size);
        }
    }
}
