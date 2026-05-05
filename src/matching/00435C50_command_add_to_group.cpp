// 00435C50 RGE_Command::command_add_to_group (Command.cpp:1807-1831, 113B)
// Exact match: non-virtual RGE_Command destructor avoids VC5 vtordisp shifting world from +4.

#include <stdlib.h>

class TDebuggingLog;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, const char* msg, int plr, const char* name);

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    void* object(int id);
};

struct RGE_Static_Object {
    void* vftable;
    int id;
    void* master_obj;
};

struct MasterObject {
    void* vftable;
    char pad_04[4];
    const char* name;
};

class RGE_Command {
public:
    void* vftable;          // +0x00
    RGE_Game_World* world;  // +0x04

    ~RGE_Command();
    void command_add_to_group(int plr, int rec, int target, int angle);
    void submit(void* buf, int size);
};

void RGE_Command::command_add_to_group(int plr, int rec, int target, int angle) {
    char* buf = (char*)calloc(1, 0x10);

    *(int*)(buf + 4) = rec;
    *buf = 0x0E;
    *(buf + 1) = (char)plr;
    *(int*)(buf + 0x0C) = target;
    *(int*)(buf + 0x08) = angle;

    void* obj = this->world->object(target);
    const char* name;
    if (obj != 0) {
        RGE_Static_Object* sobj = (RGE_Static_Object*)obj;
        MasterObject* mobj = (MasterObject*)sobj->master_obj;
        name = mobj->name;
    } else {
        name = (const char*)0x583B74;
    }

    TDebuggingLog_Log(*(TDebuggingLog**)0x62C4FC, (const char*)0x583DA8, plr, name);

    this->submit(buf, 0x10);
}
