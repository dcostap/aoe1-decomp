// VA: 004360D0 RGE_Command::command_add_waypoint
// PDB: Command.cpp lines 2077-2106 (124 bytes, 45 asm lines)
// Default flags. No inline asm/hacks.
// Retry 2026-05-18 (10 honest tries):
// - Revalidated baseline: exact-sized 124, relatively small but non-local mismatch (33.8710% positional / 22.5806% edit).
// - Tried naming temporaries for p3/player/p4/rec/p5 in original load order; VC5 optimized back to baseline.
// - Tried volatile byte temporaries to force p3/p4/p5 load order; worsened badly with stack spills and shifted body (76.6129% positional).
// - Tried delaying player/rec locals until after calloc and reusing id/player for object/log; no codegen change from baseline.
// - Reviewed object-name load form: original uses EDX=[obj+8]; EAX=[EDX+8], while rebuilt collapses to EAX=[EAX+8]; EAX=[EAX+8]. Source typing did not force the extra EDX temp.
// - Reviewed logging global order: original pushes name, then loads L into EAX before pushing player/fmt/log; rebuilt loads L into ECX before name push. Source arg order/locals did not fix.
// GIVEUP: remaining drift is source scheduling/register allocation around packet byte stores, object-name temp register, global L load, and final submit call displacement. Not an accepted_drift proposal because differences are spread across setup/logging/submit, not a single benign hunk.

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
