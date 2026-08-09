// VA: 00435320 RGE_Command::command_order (256B)
// PDB: Command.cpp lines 1203-1267
// Attempt log:
// - Replaced the placeholder with the natural Command.cpp packet builder,
//   using the exact neighboring command_move surface for object IDs, owner
//   and master-object names.

#include <stdlib.h>

#define STR_SEND_CMD_ORDER ((const char*)0x00583B3C)
#define STR_X              ((const char*)0x00583B74)

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
    void command_order(RGE_Static_Object** list, short list_num,
                       RGE_Static_Object* target, float x, float y);
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void RGE_Command::command_order(RGE_Static_Object** list, short list_num,
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
            buf[0] = 0;
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

            L->Log(STR_SEND_CMD_ORDER, list_num, owner, name, target_name);
            this->submit(buf, size);
        }
    }
}
