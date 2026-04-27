// VA: 00435CD0
// RGE_Command::command_remove_from_group(int, int, int)
// Source: Command.cpp lines 1838-1861

// attempt 1: extern string pointers -> 16% diff (mov eax,[sym] vs mov eax,offset)
// attempt 2: inline string literals -> EXACT MATCH (107/107, 0.0000%)
// default flags

#include <stdlib.h>

class RGE_Command;
class RGE_Game_World;
class RGE_Master_Static_Object;

extern void* __cdecl calloc(size_t count, size_t size);

class RGE_Master_Static_Object {
public:
    char gap_00[0x08];
    char* name;           // +0x08
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;  // +0x08
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(long id);
};

class RGE_Command {
public:
    char gap_00[0x04];
    RGE_Game_World* world;   // +0x04

    void submit(unsigned char* order, long size);
    void command_remove_from_group(int param_1, int param_2, int param_3);
};

class TDebuggingLog;
extern TDebuggingLog* L;
extern void Log(TDebuggingLog* log, const char* fmt, int a, const char* b);

void RGE_Command::command_remove_from_group(int param_1, int param_2, int param_3) {
    unsigned char* cmd = (unsigned char*)calloc(1, 0xC);
    cmd[0] = 0x0F;
    cmd[1] = (unsigned char)param_1;
    *(int*)(cmd + 4) = param_2;
    *(int*)(cmd + 8) = param_3;

    RGE_Static_Object* obj = this->world->object(param_3);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }

    Log(L, "      >SEND CMD REM GROUP (PLR=%d,UNIT=%s)", param_1, name);
    this->submit(cmd, 0xC);
}
