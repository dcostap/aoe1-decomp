// VA: 004360D0 RGE_Command::command_add_waypoint
// PDB: Command.cpp lines 2077-2106 (124 bytes, 45 asm lines)
// Default flags. No inline asm/hacks.

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

    buf[9] = p3;
    buf[0] = 0x0C;
    buf[1] = (unsigned char)player;
    *(int*)(buf + 4) = rec;
    buf[8] = 1;
    buf[10] = p4;
    buf[11] = p5;

    RGE_Static_Object* obj = this->world->object(rec);
    char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = (char*)0x583B74;
    }
    TDebuggingLog_Log(L, (const char*)0x583F14, player, name);
    this->submit(buf, 0x18);
}
