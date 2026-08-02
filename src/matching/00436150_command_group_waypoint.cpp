// VA: 00436150 RGE_Command::command_group_waypoint (204B)
// Command.cpp lines 2112-2158.
//
// Attempt log:
// - Replaced the stale placeholder with the period-plausible packet builder
//   supported by the original list-copy, object-name, owner-id, log, and submit
//   call sequence.  The command packet is four header bytes followed by one
//   dword per selected object.

#include <stdlib.h>

#define STR_X ((const char*)0x00583B74)

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
    void command_group_waypoint(RGE_Static_Object** list, short list_num,
                                unsigned char x, unsigned char y);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void RGE_Command::command_group_waypoint(RGE_Static_Object** list,
                                         short list_num,
                                         unsigned char x,
                                         unsigned char y)
{
    int size = list_num * 4 + 4;

    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 4);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            buf[0] = 0x10;
            buf[1] = (unsigned char)list_num;
            buf[2] = x;
            buf[3] = y;

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

            L->Log("      >SEND CMD GRP WAY (PLR=%d,UNIT=%s)", owner, name);
            this->submit(buf, size);
        }
    }
}
