// VA: 004360D0 RGE_Command::command_add_waypoint
// PDB: Command.cpp lines 2077-2106 (124 bytes)
// Default flags. No inline asm/hacks.
// Prior scratch tries (10): baseline exact size but 33.8710% positional / 22.5806% edit; naming p3/player/p4/rec/p5 locals optimized back; volatile byte temps caused stack spills; delaying player/rec locals no change; object-name/log argument order not fixed.
// try 11: explicit pre-store locals in original asm load order (p3, player, p4, rec); no codegen change.
// try 12: volatile master_obj field to force EDX=[obj+8]; EAX=[EDX+8]; no change.
// try 13: /O1 made .text 122B (too short); /Ob0 no change; flags removed.
// try 14: typed WayPacket field stores instead of raw byte pointer; no change.
// try 15: local byte aliases a/b/c before calloc; optimized back, no codegen change.
// try 16: raw unsigned char* packet stores instead of WayPacket fields; no codegen change.
// try 17: TDebuggingLog as thiscall member improved positional to 31.45% but broke original cdecl stack cleanup/tail scheduling; rolled back.
// GIVEUP: current best remains exact-size 124B but MISMATCH (42 positional bytes / 33.8710%, 28 edit bytes / 22.5806%). Drift is spread across parameter byte-load scheduling/registers (original CL=p3, DL=p4, reload CL=p5; rebuilt EBX/player first, CL=p4, DL=p5, AL=p3), object-name temp register (original EDX then EAX, rebuilt EAX/EAX), global L load/push order, and shifted final submit. Not proposing accepted_drift.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
class RGE_Static_Object_Type { public: char gap_00[8]; char* name; };
class RGE_Static_Object { public: char gap_00[8]; RGE_Static_Object_Type* master_obj; };
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class TDebuggingLog;
extern TDebuggingLog* L;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, const char* fmt, int player, char* name);
struct WayPacket { unsigned char cmd; unsigned char player; char pad2[2]; int rec; unsigned char one; unsigned char p3; unsigned char p4; unsigned char p5; char rest[12]; };
class RGE_Command { public: char gap_00[4]; RGE_Game_World* world; void submit(void* buf, int size); void command_add_waypoint(int player, int rec, unsigned char p3, unsigned char p4, unsigned char p5); };

void RGE_Command::command_add_waypoint(int player, int rec, unsigned char p3, unsigned char p4, unsigned char p5) {
    WayPacket* buf = (WayPacket*)calloc(1, 0x18);
    buf->p3 = p3;
    buf->cmd = 0x0C;
    buf->player = (unsigned char)player;
    buf->rec = rec;
    buf->one = 1;
    buf->p4 = p4;
    buf->p5 = p5;
    RGE_Static_Object* obj = this->world->object(rec);
    char* name;
    if (obj != 0) name = obj->master_obj->name; else name = (char*)0x583B74;
    TDebuggingLog_Log(L, (const char*)0x583F14, player, name);
    this->submit(buf, 0x18);
}
