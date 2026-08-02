// 00503E30 TribeHuntedAnimalUnitAIModule::processIdle(int param_1)
// Source: taiuaimd.cpp lines 141-169
// Size: 229 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift
//
// Attempt log:
// Probe 1: __cdecl virtual calls — 89.1% positional diff, __cdecl cleanup added
// Probe 2: better register usage — 82.1% positional diff, still __cdecl cleanup
// Probe 3: __stdcall virtual calls — 77.3% positional diff, first 26 bytes exact
// Probe 4: if/else structure — 77.3% positional diff (same as Probe 3)
//
// Session findings (2026-08):
// - Nested-if (if (targetID != -1) { ...; return 6; } return 5;) reproduces the
//   original control flow EXACTLY: je near to a shared return-5 tail, return-6
//   epilogue with mov eax,6 first (135 diff, shape 84.5%) — BUT VC5 then scrambles
//   the FPU schedule (stores `speed` to [esp+14] early, computes SPEED_3 late,
//   faddp st2, no mov ecx,esi; verified codegen-neutral vs parked negation).
// - This parked if/else + result-local form instead produces a byte-perfect FPU
//   block (only fsubr vs fchs+fadd at the tail differs) but jne-inline control
//   flow (190 diff). So control-flow structure changes VC5's whole-function FPU
//   register scheduling; the FPU scramble is NOT fixable by negation spelling or
//   virtual-shim dispatch (both tested: virtuals force ecx=this at maximumSpeed
//   call, matching original, but still scramble FPU and add bytes).
// - Next lead: sweep FPU local shapes (hoisted s3/len locals, inline-vs-named
//   nx/ny, statement order) under the nested-if structure via variant lab
//   template build/temp/00503E30_processIdle_lab.tpl.cpp.
//
// Key findings (struct layout correct):
// - prologue: sub esp, 8; push ebx; push esi; push edi; mov esi, ecx
// - vtable[0x40] closestObject: 5 params (all 0xFFFFFFFF except last = 0), ecx = this
// - vtable[0xFC] maximumSpeed: objectValue->vtable, ecx = objectValue, 0 params, returns float
// - vtable[0x9C] evasiveMoveTo: 4 params (new_x, new_y, world_z, 1), ecx = this
// - RGE_Game_World::object via objectValue->owner->world
// - +0x4: objectValue (RGE_Static_Object*)
// - +0x38: objectValue->world_x; +0x3C: world_y; +0x40: world_z
// - Constant [5758B0h] = 3.0f
// - Returns 6 (fled) or 5 (idle) — ret 4 (one stack param, unused)
//
// Remaining drift:
// - Control flow: original uses `je near shared_exit`, rebuilt uses `jne short; inline return`
// - FPU temp store ordering differs (extra fst by VC5)
// - fchs+fadd vs fsubr encoding difference
// - Epilogue truncated by ~12 bytes due to FPU code size differences

#include <math.h>

extern const float SPEED_3; // 3.0f at [5758B0h]

struct RGE_Game_World;
struct RGE_Static_Object;
struct RGE_Player;

struct RGE_Game_World {
    RGE_Static_Object* object(int objectID);
};

struct RGE_Static_Object {
    void* vtable;                 // +0x0
    int id;                       // +0x4
    void* master_obj;             // +0x8
    RGE_Player* owner;            // +0x0C
    char pad_10[0x28];
    float world_x;                // +0x38
    float world_y;                // +0x3C
    float world_z;                // +0x40
};

struct RGE_Player {
    char pad_00[0x3C];
    RGE_Game_World* world;       // +0x3C
};

struct TribeHuntedAnimalUnitAIModule {
    void* vtable;                   // +0x0
    RGE_Static_Object* objectValue; // +0x4

    int processIdle(int param_1);
};

int TribeHuntedAnimalUnitAIModule::processIdle(int param_1)
{
    int targetID;
    RGE_Static_Object* target;
    float speed, dx, dy, nx, ny;
    void* vt;
    int result;

    vt = vtable;
    targetID = ((int (__stdcall*)(int, int, int, int, int))((void**)vt)[0x10])(
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0
    );

    if (targetID == -1) {
        result = 5;
    } else {
        target = objectValue->owner->world->object(targetID);
        if (target == 0) {
            result = 5;
        } else {
            speed = ((float (__stdcall*)())((void**)objectValue->vtable)[0x3F])();
            dx = target->world_x - objectValue->world_x;
            dy = target->world_y - objectValue->world_y;
            nx = objectValue->world_x - (dx / (float)sqrt(dx * dx + dy * dy)) * (speed * SPEED_3);
            ny = objectValue->world_y - (dy / (float)sqrt(dx * dx + dy * dy)) * (speed * SPEED_3);
            ((void (__stdcall*)(float, float, int, int))((void**)vt)[0x27])(
                nx, ny, *(int*)&objectValue->world_z, 1
            );
            result = 6;
        }
    }
    return result;
}
