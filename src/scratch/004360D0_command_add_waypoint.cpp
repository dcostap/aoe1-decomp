// RGE_Command::command_add_waypoint(int,int,unsigned char,unsigned char,unsigned char)
// VA: 004360D0
// Attempt log:
// - Previous scratch omitted debug logging and modeled this as a free __fastcall helper; rebuilt was 96 bytes vs original 124.
// - 2026-05-10 StarryZephyr pass: rewrote as a real thiscall member with calloc, packet stores, world->object lookup,
//   logging, and submit call. This recovers the 124-byte size and broad behavior/call surface, but register and
//   stack scheduling still differ: p3/p4/p5 are loaded in the wrong byte registers/order around `add esp,8`, the log
//   call loads L before pushing the object name, and the function tail is shifted enough that the compared window shows
//   a truncated `ret 14h`. Tried explicit param temporaries; no codegen change. Left in scratch; no accepted_drift.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Static_Object_Type {
public:
    char gap_00[8];
    char* name;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Static_Object_Type* master_obj;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class TDebuggingLog;
extern TDebuggingLog* L;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, const char* fmt, int player, char* name);

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;

    void submit(void* buf, int size);
    void command_add_waypoint(int player, int rec, unsigned char p3, unsigned char p4, unsigned char p5);
};

void RGE_Command::command_add_waypoint(int player, int rec, unsigned char p3, unsigned char p4, unsigned char p5) {
    unsigned char* buf = (unsigned char*)calloc(1, 0x18);
    unsigned char a = p3;
    int pl = player;
    unsigned char b = p4;
    int r = rec;
    buf[9] = a;
    buf[0] = 0x0C;
    buf[1] = (unsigned char)pl;
    *(int*)(buf + 4) = r;
    buf[8] = 1;
    buf[10] = b;
    buf[11] = p5;

    RGE_Static_Object* obj = this->world->object(r);
    char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = (char*)0x583B74;
    }
    TDebuggingLog_Log(L, (const char*)0x583F14, player, name);
    this->submit(buf, 0x18);
}
