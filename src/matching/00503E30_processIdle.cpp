// 00503E30 TribeHuntedAnimalUnitAIModule::processIdle(int param_1)
// Source: taiuaimd.cpp lines 141-169
// Size: 229 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: EXACT — validated VC5 codegen match
//
// Attempt log:
// Probe 1: __cdecl virtual calls — 89.1% positional diff, __cdecl cleanup added
// Probe 2: better register usage — 82.1% positional diff, still __cdecl cleanup
// Probe 3: __stdcall virtual calls — 77.3% positional diff, first 26 bytes exact
// Probe 4: if/else structure — 77.3% positional diff (same as Probe 3)
// Probe 5: same-TU polymorphic donor surfaces — codegen-neutral; retained the
// canonical destructor/vtable context from exact taiuaimd.cpp idle donors.
// Probe 6: explicit float casts around the negated movement products — exact;
// VC5 emits the binary's fchs/fadd tails instead of fsubr.
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
// Exactness note:
// - The nested positive guards, scaled-speed initialization, typed virtual
//   surfaces, and explicit float casts reproduce the complete 229-byte body.
//
// Current session findings (2026-08-09):
// - A named distance alone and a separate speed3 local were codegen-neutral.
// - Recovered the natural typed virtual surfaces: closestObject at slot 0x10,
//   evasiveMoveTo at 0x27, and RGE_Static_Object::maximumSpeed at 0x3F. The
//   maximumSpeed call then uses the original ecx/edx register topology.
// - The canonical evasiveMoveTo world-z argument is float. Its ABI passes the
//   same raw dword bits observed at the call site without conversion; restoring
//   that typed surface is codegen-neutral.
// - The shared PDB surface preserves the protected virtual symbol and exact body.
// - Binding the scale to the return (`speed = objectValue->maximumSpeed() *
//   SPEED_3`) reproduces the original 229-byte size and the whole FPU block
//   through the two normalized multiplications (best: 52-byte strict diff,
//   93.02% shape, 96.51% resync). Explicit unary negation is codegen-neutral.
// - Separate offset/negation locals emitted an extra stack store (62-byte
//   diff); rolled back. Remaining bytes are the two near-branch displacements
//   plus VC5's fsubr versus the original fchs/fadd tail.

#include <math.h>
#include "../../include/taiuaimd_context.h"

extern const float SPEED_3; // 3.0f at [5758B0h]

int TribeHuntedAnimalUnitAIModule::processIdle(int param_1)
{
    int targetID;
    RGE_Static_Object* target;
    float speed, dx, dy, distance, nx, ny;
    targetID = closestObject(
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0
    );

    if (targetID != -1) {
        target = objectValue->owner->world->object(targetID);
        if (target != 0) {
            speed = objectValue->maximumSpeed() * SPEED_3;
            dx = target->world_x - objectValue->world_x;
            dy = target->world_y - objectValue->world_y;
            distance = (float)sqrt(dx * dx + dy * dy);
            nx = (float)(-((dx / distance) * speed)) + objectValue->world_x;
            ny = (float)(-((dy / distance) * speed)) + objectValue->world_y;
            evasiveMoveTo(nx, ny, objectValue->world_z, 1);
            return 6;
        }
    }
    return 5;
}
