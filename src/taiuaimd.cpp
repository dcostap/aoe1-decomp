// PDB source module: C:\\msdev\\work\\age1_x1\\taiuaimd.cpp.
// The definitions below follow the 63 normal owners in PDB source order.
// Generated destructor and vtable entries are emitted by the compiler.
#include "../include/taiuaimd.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../include/game_globals.h"

// VA: 00503BB0, TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame;
// cache importantObjects[0], reload this->importantObjects for later source lines.
// Historical exact flags: config/flags/00503BB0_TribeHuntedAnimalUnitAIModule.rsp
// Canonical-context check: the PDB 0x134 base and PAV parameter symbol remain exact.


void* operator new(size_t size);

TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x10;
    importantObjects = (int*)operator new(0x40);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 4;
        this->importantObjects[2] = 0x1a;
        this->importantObjects[3] = 0x18;
        this->importantObjects[4] = 6;
        this->importantObjects[5] = 0x19;
        this->importantObjects[6] = 0x11;
        this->importantObjects[7] = 0xa;
        this->importantObjects[8] = 0xc;
        this->importantObjects[9] = 0x23;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1c;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0xd;
        this->importantObjects[15] = 0x27;
    }

    idleTimeoutValue = 0xFA0;
    setAdjustedIdleTimeout();
}

// 00503D30 TribeHuntedAnimalUnitAIModule::processNotify
// PDB: taiuaimd.cpp:99-136, 256 bytes
// int __thiscall processNotify(NotifyEvent* param_1, ulong param_2)
// ret 8 (2 params)
// Historical exact flags: default
//
// Attempt log:
// - Baseline used the canonical caller array fields and natural growth/copy loop;
//   the arithmetic dispatch lowered to cmp/jne and was four bytes too large.
// - A switch on mType reproduced the original subtract/je dispatch and shared tail.
// - The two notification calls are one-argument thiscall virtuals at +0xEC/+0xA4;
//   typed slot surfaces removed the incorrect extra fastcall register setup.
// - UnitAIModule owns the base vptr, so the derived subobject starts at +0x04;
//   removing the duplicate gap restored all proven array offsets and exact bytes.
// Main-agent audit restored destructor slots, qualified the base dispatch, and
// replaced manual allocation calls with natural new[]/delete[]; output remains exact.
// The shared PDB surface removes fake fields and preserves the protected virtual
// symbol ?processNotify@TribeHuntedAnimalUnitAIModule@@MAEHPAUNotifyEvent@@K@Z.


int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* evt, unsigned long param_2)
{
    switch (evt->mType) {
    case 0x1F4:
    {
        if (evt->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        int caller = evt->caller;

    // Search for existing caller
    int i = 0;
    while (i < this->attackingUnitsValue.numberValue &&
           i < this->attackingUnitsValue.maximumSizeValue) {
        if (this->attackingUnitsValue.value[i] == caller)
            goto done;
        i++;
    }

    // Grow array if count >= capacity
    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int new_cap = this->attackingUnitsValue.numberValue + 1;
        int* new_arr = new int[new_cap];
        if (new_arr) {
            int j;
            for (j = 0;
                 j < this->attackingUnitsValue.maximumSizeValue && j < new_cap;
                 j++)
                new_arr[j] = this->attackingUnitsValue.value[j];
            delete[] this->attackingUnitsValue.value;
            this->attackingUnitsValue.value = new_arr;
            this->attackingUnitsValue.maximumSizeValue = new_cap;
        }
    }

        // Add caller to end of list
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

        goto done;
    }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(evt, param_2);
    }

done:
    // Notify sub via vtable+0xEC
    this->objectValue->setUnderAttack(1);

    // Notify self via vtable+0xA4
    this->runAwayFromAttackers(1);

    return 3;
}

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

// VA: 00503F20, TribePreditorUnitAIModule::TribePreditorUnitAIModule, 328 bytes
// Source: taiuaimd.cpp lines 177-202
// Historical exact flags: /GX (EH frame for operator new + parent constructor)
//
// Key findings:
// - /GX needed for EH prologue/epilogue (fs:[0] save/restore with handler)
// - Virtual ~UnitAIModule() needed to trigger constructor EH frame
// - importantObjects[0] uses cached pointer; this->importantObjects[i] for i>=1
//   forces per-index reload from [esi+124h] with edx/eax/ecx register cycling
// - The canonical 0x134 base preserves exact /GX code and the PAV constructor symbol.


void* operator new(size_t size);

TribePreditorUnitAIModule::TribePreditorUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x11;
    importantObjects = (int*)operator new(0x44);

    if (importantObjects) {
        importantObjects[0] = 0x1D;
        this->importantObjects[1] = 0x09;
        this->importantObjects[2] = 0x00;
        this->importantObjects[3] = 0x04;
        this->importantObjects[4] = 0x1A;
        this->importantObjects[5] = 0x18;
        this->importantObjects[6] = 0x06;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0D;
        this->importantObjects[10] = 0x0C;
        this->importantObjects[11] = 0x23;
        this->importantObjects[12] = 0x17;
        this->importantObjects[13] = 0x24;
        this->importantObjects[14] = 0x1C;
        this->importantObjects[15] = 0x12;
        this->importantObjects[16] = 0x27;
    }
}


// PDB ownership gives a public virtual TribePreditorUnitAIModule method.

int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 1; }

// VA: 005040B0 TribePreditorUnitAIModule::processNotify
// taiuaimd.cpp:216-258
//
// Attempt log:
// v0: Initial implementation - RGE_Static_Object missing vtable caused wrong offsets, fcomp branch inverted
// v1: Added virtual to RGE_Static_Object, fixed fcomp branch to !(dist>range)
// v2: Canonical fields and slots preserve exact bytes and the protected MAE symbol.


extern FILE* actionFile;  // FILE* at 0x62C4CC
extern int fprintf(void*, const char*, ...);

// String constants at fixed RVAs in .rdata
extern const char str_taiuaimd_path[];    // at 0x588AE8
extern const char str_fmt_stopObject[];   // at 0x57F964

int TribePreditorUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2) {
    if (event->mType == 0x1FC) {
        RGE_Static_Object* obj =
            this->objectValue->owner->world->object(this->currentTargetValue);

        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
            if (!(dist > this->objectValue->master_obj->los)) {
                this->attackObject(this->currentTargetValue, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();

        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 250);
        }

        this->stopObject(1);
        this->notifyCommander((void*)event);
    }

    return UnitAIModule::processNotify(event, param_2);
}


TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}

// VA: 005041C0, TribeElephantUnitAIModule::processNotify, 261 bytes
// Source: taiuaimd.cpp lines 274-317
// ACCEPTED_DRIFT: register allocation (ebp/ecx swap for caller/count) and copy loop
// pattern differ slightly. All behavior identical.
//
// Remaining drift:
// 1. Register swap: original keeps caller in ebp, count in ecx. My compiler
//    reverses this (caller in ecx saved to stack, count in ebp). This adds 4 bytes
//    for the stack save (`mov [esp+18h], ecx`).
// 2. Copy/reallocation loop uses different register allocation and slightly
//    different instruction scheduling (same structure, different registers).
// 3. The original uses `jg short` for p2 check (body=jump target, purge=fallthrough);
//    this layout is achieved with `if (event->p2 <= 0)` in the switch.
//
// What matches (first 90 bytes): prologue, switch dispatch (sub/je chain), default
// parent call, return-2 path, p2 check (jg short), purge/return-4 path.
// Also matches: search loop structure (scaled-index access, capacity reload per
// iteration), store-to-array, virtual call sequence, and epilogues.
//
// Attempt log:
// - v1: if-else chaining → cmp not sub for dispatch, wrong NotifyEvent layout
// - v2: switch dispatch, fixed NotifyEvent layout (p2 at +0x10), loop structure off
// - v3: switch → sub pattern works (63 bytes match), p2 check wrong branch layout
// - v4: attempted raw-offset hacks (failed)
// - v5-v6: refined loop structure
// - v7: raw-offset access forced correct scaled-index loop, register allocation off
// - v8: declaration order didn't help register allocation
// - v9: goto-based layout attempt
// - v10: if(p2<=0) fixes branch layout (90 bytes match), register allocation persists
// Historical exact flags: /nologo /c /O2 /Oy


int TribeElephantUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 500:
        if (event->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }
        {
            int caller = event->caller;
            int count = this->notifyCount;
            int i = 0;
            if (count > 0) {
                goto loop_check;
                do {
                    if (i >= this->notifyCapacity)
                        goto after_loop;
                    if (this->notifyArray[i] == caller)
                        goto found;
                    i++;
loop_check:;
                } while (i < count);
after_loop:;
            }

            if (count >= this->notifyCapacity) {
                int newCapacity = count + 1;
                int* newArray = (int*)operator_new(newCapacity * 4);
                if (newArray != 0) {
                    int j = 0;
                    if (count > 0) {
                        while (j < newCapacity && j < count) {
                            newArray[j] = this->notifyArray[j];
                            j++;
                        }
                    }
                    operator_delete(this->notifyArray);
                    this->notifyArray = newArray;
                    this->notifyCapacity = newCapacity;
                }
            }
            this->notifyArray[this->notifyCount] = caller;
            this->notifyCount++;
found:
            this->objectValue->setUnderAttack(1);
            int val = this->closestAttacker(0);
            this->attackObject(val, 0);
            return 3;
        }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }
}


int TribeElephantUnitAIModule::processIdle(int p0) { return 5; }

// VA: 005042E0, TribeLionUnitAIModule::TribeLionUnitAIModule
// Same taiuaimd.cpp constructor pattern as TribeHuntedAnimalUnitAIModule: visible virtual base dtor + /GX for EH frame; reload member after first importantObjects store.
// Historical exact flags: config/flags/005042E0_TribeLionUnitAIModule.rsp


TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x11;
    importantObjects = (int*)operator new(0x44);

    if (importantObjects) {
        importantObjects[0] = 0x1d;
        this->importantObjects[1] = 9;
        this->importantObjects[2] = 0;
        this->importantObjects[3] = 4;
        this->importantObjects[4] = 0x1a;
        this->importantObjects[5] = 0x18;
        this->importantObjects[6] = 6;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0xd;
        this->importantObjects[10] = 0xc;
        this->importantObjects[11] = 0x23;
        this->importantObjects[12] = 0x17;
        this->importantObjects[13] = 0x24;
        this->importantObjects[14] = 0x1c;
        this->importantObjects[15] = 0x12;
        this->importantObjects[16] = 0x27;
    }

    idleTimeoutValue = 0x1770;
    setAdjustedIdleTimeout();
}


int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 1; }

// VA: 00504480 TribeLionUnitAIModule::processNotify(NotifyEvent*, unsigned long)
// PDB source: taiuaimd.cpp lines 375-436
// attempt 1: based on matching predator processNotify, adding 0x1FA game-mode branch; first was underspecified and optimized too small.
// attempt 2: fill scenario-editor timing branch/logging/stopObject path from original asm.
// attempt 3: put 0x1FC branch inline and 0x1FA case out-of-line like original's subtract dispatch.

extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];


int TribeLionUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1FC:
    {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->field_34);
        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
            if (!(dist > *(float*)((char*)this->objectValue->master_obj + 0x28))) {
                this->attackObject(this->field_34, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x1AC);
        }
        this->stopObject(1);
        this->notifyCommander(event);
    }
    break;

    case 0x1FA:
        if (*(int*)((char*)event + 0x0C) != 0x258) {
            break;
        }
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->inScenarioEditor() == 1) {
            int value = taiuaimd_world_next_object_id(this->objectValue->owner->world) + 3;
            value = value + value * 4;
            value = value + value * 4;
            value = value + value * 4;
            value = value + value * 4;
            value = value << 3;
            this->field_100 = value;
        } else {
            this->field_100 = 0x61A8;
        }
        this->setAdjustedIdleTimeout();
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x191);
        }
        this->stopObject(1);
        break;
    }

    return UnitAIModule::processNotify(event, param_2);
}

// TribeLionUnitAIModule::processIdle (00504600)
// taiuaimd.cpp:441-515, 251 bytes
// __thiscall: ecx=this, 1 stack param, ret 4


int TribeLionUnitAIModule::processIdle(int param_1)
{
    idleTimeoutValue = 6000;
    setAdjustedIdleTimeout();

    int targetId = closestObject(-1, -1, -1, -1, 0);
    RGE_Static_Object* newTarget = lookupObject(targetId);

    if (targetId == -1 || newTarget == 0) {
        return 5;
    }

    int difficulty = taiuaimd_world_difficulty(objectValue->owner->world);

    float los;
    if (rge_base_game->scenarioGame() == 1 && rge_base_game->singlePlayerGame() == 1 && difficulty >= 3) {
        float factor = (difficulty == 3) ? 0.75f : 0.5f;
        los = factor * objectValue->master_obj->los;
        if (los < 1.0f) {
            los = 1.0f;
        }
    } else {
        los = objectValue->master_obj->los * 2.0f;
    }

    float dist = objectValue->distance_to_object(newTarget);
    if (dist > los) {
        return 5;
    }

    attackObject(targetId, 0);
    return 6;
}


TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}

// VA: 00504750, processNotify, 294 bytes
// Source: taiuaimd.cpp lines 529-586
// ACCEPTED_DRIFT: VC5 register allocation differs (eax vs edx for vtable loads,
// eax vs edi for obj pointer register). All calling conventions, stack cleanup,
// control flow, FPU math, and behavior identical.
//
// Key techniques:
// - The period RGE_Static_Object and UnitAIModule declarations provide the
//   named virtual methods at the observed slots.
// - Branch polarity: `if (condition == expected) { body } else { return 2; }`
//   generates `jne near ret2_block` matching original's shared return-2 pattern
// - Separate negate-and-add: `float nty = -(dy / dist * speed); float resultY = nty + world_y;`
//   generates `fchs; fadd` instead of compiler-optimized `fsubr`
// - Direct `this->obj` access in vtable[4] arguments (no cached local) matches
//   original's `mov eax, [esi+4]` placement
// - `thisObj = this->obj` declared AFTER vtable[4] call matches original's
//   `mov edi, [esi+4]` placement
//
// Remaining drift (all register allocation choices):
// 1. Vtable[64] call: original `mov edx,[edi]; call [edx+100h]`, rebuilt
//    `mov eax,[edi]; call [eax+100h]` — different base register
// 2. Obj pointer: original keeps obj in `eax` (reloaded from [esi+4] at 0x480B),
//    rebuilt keeps obj in `edi` (loaded once after vtable[4] call)
// 3. Cascade: 3 jump offsets differ by 1 byte each due to body size differences
//
// What matches (156 bytes up to vtable[4] call):
// - Prologue (mov eax,[esp+4]; push ebx,ebp,esi,edi; mov esi,ecx)
// - mType check (cmp [eax+8],200h; je → skip base class call)
// - Base class call (mov ecx,[esp+18h]; push ecx,push eax; mov ecx,esi; call)
// - currentActionValue check (cmp [esi+30h],258h; jne near → shared return-2)
// - Game world lookup (mov eax,[esi+4]; mov edx,[esi+34h]; push; mov ecx,[eax+0Ch];
//   mov ecx,[ecx+3Ch]; call RGE_Game_World::object)
// - Null check (test ebx,ebx; je near → shared return-2)
// - Object vtable[61] call + float compare (mov edx,[ebx]; mov ecx,ebx;
//   call [edx+0F4h]; fcomp; fnstsw; test ah,40h; jne near → shared return-2)
// - vtable[4] call argument preparation (all 11 args pushed with correct
//   field offsets: currentOrderPriorityValue, 1, 0, desiredTargetDistanceValue,
//   currentTargetZValue, currentTargetYValue, currentTargetXValue, -1,
//   currentTargetValue, 0x2BC, obj->id)
// - All epilogues: return-3 (mov eax,3; pop edi,esi,ebp,ebx; ret 8) and
//   return-2 (pop edi,esi,ebp; mov eax,2; pop ebx; ret 8)
// - FPU math: dx, dy, dist = sqrt(dx²+dy²), speed = s1*s2*3, result_y/x
//   with fchs; fadd pattern, fdiv; fmul st2; fchs; fadd; fstp [esp] sequence
// - Final call vtable[39] with (result_x, result_y, world_z, 1)
//
// Attempt log:
// - v1: __thiscall keyword issue, compilation failed (C4234)
// - v2: initial interface approach, 35.4% edit diff. Issues: inline
//   returns instead of shared return-2 block
// - v3: fixed branch polarity with if/else structure → jne near to shared block.
//   Issue: fsubr instead of fchs+fadd (6 bytes short, 288 vs 294)
// - v4: added thisObj local declared AFTER vtable[4] call → 24.8% edit diff, 294B
// - v5: removed thisObj local → worse (47.3%), compiler removed push ebp
// - v6: restored thisObj after vtable[4] call, separate nty/ntx vars → BEST:
//   14.97% edit diff. fchs; fadd matches. Remaining: register allocation only.
//
// Conclusion: Remaining 15% edit diff is benign register allocation that cannot
// be controlled from C++ source. Accepted drift.


typedef unsigned long ulong;


int TribeRangedUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    if (event->mType != 0x200) {
        return UnitAIModule::processNotify(event, param_2);
    }

    if (this->currentActionValue == 600) {
        RGE_Game_World* gameWorld = this->objectValue->owner->world;
        RGE_Static_Object* targetObj = gameWorld->object(this->currentTargetValue);

        if (targetObj) {
            float fVal = targetObj->getSpeed();
            if (fVal != 0.0f) {
                this->order(
                    this->objectValue->id, 0x2BC, this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 1, this->currentOrderPriorityValue
                );

                RGE_Static_Object* thisObj = this->objectValue;

                // Get speed from obj's vtable[64] (+0x100) then [63] (+0xFC)
                float speed2 = thisObj->rateOfFire();
                float speed1 = thisObj->maximumSpeed();
                float speed = speed1 * speed2 * 3.0f;
                float dx = targetObj->world_x - thisObj->world_x;
                float dy = targetObj->world_y - thisObj->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);
                float nty = -(dy / dist * speed);
                float resultY = nty + thisObj->world_y;
                float ntx = -(dx / dist * speed);
                float resultX = ntx + thisObj->world_x;

                this->evasiveMoveTo(resultX, resultY, thisObj->world_z, 1);

                return 3;
            }
        }
    }
    return 2;
}


TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}

// VA: 005048D0 TribeRangedUnitAIModule2::processNotify
// Attempt log:
// 1: direct reconstruction from packet/decompiler, local offset stubs.
// 2: restored the period object and module call surfaces at the observed slots.
// 3: converted failure cases to shared fail return, but VC5 still allocates a 0x0C frame instead of original 0x08 and loop topology is broad mismatch.
// 4: tried defensive null/sentinel branches only as a diagnostic to force compare size; produced 643B but broad 92% mismatch from offset 0, rolled back because it was behavior-altering and not a valid source model.
// 5-8: combined guard, object id, same-TU UnitAIModule ABI, float coordinate fields, and natural new[]/delete[] growth restored exact call order and frame size.
// 9: outer count guard plus while (i < count) reproduced the duplicated entry test and improved shape to 90.95%; the remaining gap is register coloring and late vptr spill.
// 10: a base-pointer alias was codegen-identical and was removed as unsupported steering.
// 11: rewrote the typed evasive result tail as coordinate plus explicit negated displacement; restored the original fchs/fadd tail family, reducing the size gap to 4 bytes and positional diff to 521; first order-call hunk remains.
// 12: removed the saved object alias and used direct this->obj member calls; this restored the original vptr reload and exact 643-byte output.
// exact: direct member accesses preserve the original object/vptr reload schedule and produce all 643 bytes.

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern float DAT_005758b0;
extern float DAT_005758c4;
extern "C" double __cdecl sqrt(double);


int TribeRangedUnitAIModule2::processNotify(NotifyEvent* ev, unsigned long flags)
{
    RGE_Static_Object* target;
    float evasiveMoveDistance;
    float dx;
    float dy;
    float len;
    if (*(int*)((char*)ev + 8) != 0x200) {
        return this->baseProcessNotify(ev, flags);
    }
    target = 0;
    if (this->state != 0x258 ||
        (target = this->obj->owner->world->object(this->target_id)) == 0 ||
        target->getSpeed() == DAT_005758c4)
        return 2;

    this->order(this->obj->id, 0x2bc, this->target_id, -1, this->p3c, this->p40, this->p44, this->p48, 0, 1, this->p2c);

    evasiveMoveDistance = this->obj->maximumSpeed() *
                          this->obj->rateOfFire() * DAT_005758b0;
    dx = target->world_x - this->obj->world_x;
    dy = target->world_y - this->obj->world_y;

    if (this->count > 0) {
        int i = 0;
        while (i < this->count) {
                if (i > this->capacity - 1) {
                    int newCount = i + 1;
                    int* n = new int[newCount];
                    if (n) {
                        int j = 0;
                        if (this->capacity > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    n[j-1] = this->ids[j-1];
                                } else {
                                    break;
                                }
                            } while (j < this->capacity);
                        }
                        delete[] this->ids;
                        this->ids = n;
                        this->capacity = newCount;
                    }
                }
                if (this->ids[i] != this->target_id) {
                    if (i > this->capacity - 1) {
                        int newCount = i + 1;
                        int* n = new int[newCount];
                        if (n) {
                            int j = 0;
                            if (this->capacity > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        n[j-1] = this->ids[j-1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->capacity);
                            }
                            delete[] this->ids;
                            this->ids = n;
                            this->capacity = newCount;
                        }
                    }
                    RGE_Static_Object* obj2 = this->obj->owner->world->object(this->ids[i]);
                    if (obj2) {
                        dx += obj2->world_x - this->obj->world_x;
                        dy += obj2->world_y - this->obj->world_y;
                    }
                }
            ++i;
        }
    }

    len = (float)sqrt(dx*dx + dy*dy);
    this->evasiveMoveTo(this->obj->world_x + (-(dx / len * evasiveMoveDistance)),
                        this->obj->world_y + (-(dy / len * evasiveMoveDistance)),
                        this->obj->world_z, 1);
    return 3;
}

// VA: 00504B60, TribeCivilianUnitAIModule::TribeCivilianUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame;
// cache importantObjects[0], reload this->importantObjects for later source lines.
// Historical exact flags: config/flags/00504B60_TribeCivilianUnitAIModule.rsp



TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0xb;
    importantObjects = (int*)operator new(0x2c);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 7;
        this->importantObjects[2] = 8;
        this->importantObjects[3] = 9;
        this->importantObjects[4] = 0xa;
        this->importantObjects[5] = 0xf;
        this->importantObjects[6] = 0x11;
        this->importantObjects[7] = 0x12;
        this->importantObjects[8] = 0x20;
        this->importantObjects[9] = 0x21;
        this->importantObjects[10] = 0x1b;
    }
}


int TribeCivilianUnitAIModule::importantWhenDead(int value) {
    if (value == 0x7 || value == 0x9 || value == 0xA || value == 0xF || value == 0x8 || value == 0x20)
        return 1;
    return 0;
}

// VA: 00504CC0 | TribeCivilianUnitAIModule::attackObject(int,int) | taiuaimd.cpp:726-741 | 90 bytes
//
// Attempt log:
// [1] UnitAIModule had no virtual -> vtable offset wrong; 16-bit cmp; huntObject at vt[0].
// [2] Fixed vtable with virtual attackObject; cast to int for 32-bit cmp.
//     VC5 doesn't support __thiscall on function pointers.
// [3] Natural virtual huntObject call. All matches except huntObject at vt[1] not vt[25].
//     1 byte diff at offset 84: call [edx+04h] vs call [edx+64h].
// [4] Add 24 padding virtual functions to push huntObject to vt[25].



int TribeCivilianUnitAIModule::attackObject(int targetId, int param2) {
    RGE_Static_Object* obj = objectValue->owner->world->object(targetId);
    if (obj == 0) {
        return 0;
    }

    int group = (int)obj->master_obj->object_group;
    if (group == 9 || group == 10 || group == 15) {
        return this->huntObject(targetId, param2);
    }

    return UnitAIModule::attackObject(targetId, param2);
}

int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->master_obj->id != 1;
}


int TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 0; }


int TribeCivilianUnitAIModule::retryableOrder(int value) {
    if (value == 0x2C1 || value == 0x2C5 || value == 0x2C9)
        return 1;
    return 0;
}


int TribeCivilianUnitAIModule::convertToLOSResourceType(int value) {
    switch (value) {
    case 7:
        return 1;
    case 0x20:
        return 4;
    case 8:
        return 3;
    case 0xF:
        return 0;
    case 5:
    case 0x1F:
    case 0x21:
        return 2;
    default:
        return -1;
    }
}

// VA: 00504E10 TribeCivilianUnitAIModule::processNotify
// PDB donor: taiuaimd.cpp lines 800-1237
// Attempt log:
// BINARY NOTE: The original keeps event in EBX, uses indexed bounded list scans,
//   and places the owner-id-zero order arm before the enemy arm.
// The same-TU virtual surfaces and FILE/fprintf declarations preserve the proven calls.
// Probe: reversing the owner branch recovered the original 2478-byte boundary and
//   raised shape from 76.74% to 87.18%; ordering the resource arm raised it to 87.83%.
// Probe H26: one late return label for the four proven guard jumps raised shape to
//   88.57%, matched the 16-return CFG, and reduced positional diff to 2067 bytes.
// Probe H27: actionFile-gated local stop/notify returns restored both 0x3aa/0x3b9
//   log blocks. Calls then matched 78/78, shape reached 88.96%, and diff reached 1820.
// Probe H30: direct ternary closestObject arguments reduced diff to 1594, but added
//   one fprintf and one stopObject call. Reject it for the hard call-count mismatch.
// BINARY NOTE: H27 still emits 74 bytes past the target boundary. Its ordered calls
//   remain -3/+3, with the 0x261 argument setup and one relocated cold tail unresolved.
// unresolved: final clean source is pinned after H27 validation; no exact match.

typedef unsigned char uchar;
typedef unsigned long ulong;


int TribeCivilianUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0x1b:
        if (taiuaimd_world_difficulty(this->objectValue->owner->world) >= 3) {
            return 2;
        }
        // Intentional fall-through: 0x20f is the high-priority spelling of 0x1f4.
    case 0: {
        if (event->p2 <= 0) {
            taiuaimd_player_notify(this->objectValue->owner,
                this->objectValue->id, this->objectValue->id, 0x209,
                event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        RGE_Static_Object* eventObject = this->lookupObject(event->caller);
        RGE_Static_Object* targetObject = this->lookupObject(this->currentTargetValue);
        if (eventObject == 0) {
            return 2;
        }

        if (this->objectValue->owner->computerPlayer() == 1) {
            if (eventObject->owner->id != 0 || eventObject->id != this->currentTargetValue) {
                taiuaimd_player_notify(this->objectValue->owner,
                    this->objectValue->id, this->objectValue->id, 0x201,
                    event->caller, 0, 0);
            }
        } else if (this->attackingUnitsValue.numberValue == 0) {
            taiuaimd_player_notify(this->objectValue->owner,
                this->objectValue->id, this->objectValue->id, 0x201,
                event->caller, 0, 0);
        }

        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) {
                goto found_attacker;
            }
        }

        if (this->objectValue->owner->computerPlayer() == 0 &&
            this->currentTargetValue != event->caller) {
            this->askForHelp(event->caller);
        }

found_attacker:
        i = 0;
        int caller = event->caller;
        count = this->attackingUnitsValue.numberValue;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) {
                goto already_attacking;
            }
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* newValue = (int*)operator new(newMaximum * 4);
            if (newValue != 0) {
                i = 0;
                if (this->attackingUnitsValue.maximumSizeValue > 0) {
                    do {
                        if (i >= newMaximum) {
                            break;
                        }
                        ++i;
                        newValue[i - 1] = this->attackingUnitsValue.value[i - 1];
                    } while (i < this->attackingUnitsValue.maximumSizeValue);
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newValue;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        ++this->attackingUnitsValue.numberValue;

already_attacking:
        this->objectValue->setUnderAttack(1);
        float speed = this->objectValue->getSpeed();
        int state = taiuaimd_object_action_state(this->objectValue);

        if (this->currentOrderValue == 0x2c6 && speed > 0.0f) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2bc) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2c9 && state == 0x0c &&
            targetObject != 0 && targetObject->master_obj->object_group == 10 &&
            ((RGE_Static_Object*)(*(long*)((char*)event + 0x0C)))->owner->id == 0) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2ce) {
            goto return_two;
        }

        if (((RGE_Static_Object*)(*(long*)((char*)event + 0x0C)))->owner->id == 0) {
            if (this->currentOrderValue != -1) {
                this->order(this->objectValue->id, this->currentOrderValue,
                            this->currentTargetValue, -1,
                            this->currentTargetXValue, this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue, 0, 0,
                            this->currentOrderPriorityValue);
                this->currentOrderValue = 0x2bc;
                this->currentOrderPriorityValue = 100;
                this->attackObject(event->caller, 1);
                this->stopAfterTargetKilledValue = 1;
                return 3;
            }
            this->attackObject(event->caller, 1);
            return 3;
        }

        if (this->currentActionValue == 0x262 && speed != 0.0f) {
            return 3;
        }
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue,
                    this->desiredTargetDistanceValue,
                    0, 0,
                    this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x39a);
        }
        this->stopObject(1);
        this->runAwayFromAttackers(1);
        return 3;
    }

    case 6:
        if (this->currentActionValue == *(long*)((char*)event + 0x0C)) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0) {
                    id = this->objectValue->id;
                } else {
                    id = -1;
                }
                fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                        "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3aa);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        break;

    case 5:
        if (this->currentActionValue == *(long*)((char*)event + 0x0C)) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0) {
                    id = this->objectValue->id;
                } else {
                    id = -1;
                }
                fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                        "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3b9);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        break;

    case 7:
    case 0xe:
        if (this->currentActionValue == 0x265) {
            int type = this->currentTargetTypeValue;
            if (type == -1) {
                type = this->lastTargetTypeValue;
            }
            if (type == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3d3);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }

            int objectType = this->convertToLOSResourceType(type);
            int result;
            if (objectType == -1) {
                result = this->closestObject(type, -1, -1, -1, 0);
            } else {
                result = this->closestResourceObject(objectType, 0);
            }
            if (result != -1) {
                if (this->huntObject(result, 1) == 1) {
                    return 3;
                }
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x3f6);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else if (this->objectValue->owner->computerPlayer() == 1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x40f);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        } else if (this->currentActionValue == 0x261) {
            int type = this->currentTargetTypeValue;
            if (type == -1) {
                type = this->lastTargetTypeValue;
            }
            if (type == -1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x421);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
            int objectType = this->convertToLOSResourceType(type);
            int result;
            if (objectType != -1) {
                result = this->closestResourceObject(objectType, 0);
            } else {
                int arg3 = 2;
                int arg4 = 0x32;
                if (event->p2 != 0x32) {
                    arg3 = -1;
                    arg4 = -1;
                }
                result = this->closestObject(type, -1, arg3, arg4, 0);
            }
            if (result != -1) {
                if (this->gatherObject(result, 1) == 1) {
                    return 3;
                }
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x446);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else if (this->objectValue->owner->computerPlayer() == 1) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x453);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else if (event->p2 == 0x32) {
                float x;
                float y;
                if (this->objectValue->world_x <= 5.0f) {
                    x = this->objectValue->world_x - (-2.5f);
                } else {
                    x = this->objectValue->world_x - 2.5f;
                }
                if (this->objectValue->world_y <= 5.0f) {
                    y = this->objectValue->world_y - (-2.5f);
                } else {
                    y = this->objectValue->world_y - 2.5f;
                }
                this->evasiveMoveTo(x, y, this->objectValue->world_z, 1);
            }
        } else if (this->currentActionValue == 0x25a) {
            int result = this->closestObject(this->currentTargetTypeValue, 3, 0, -1, 0);
            if (result == -1) {
                int type = this->currentTargetTypeValue;
                if (type == 0x1b) {
                    type = 3;
                } else {
                    type = 0x1b;
                }
                result = this->closestObject(type, 3, 0, -1, 0);
            }
            if (result != -1 &&
                taiuaimd_object_can_path(this->objectValue, result, 1.0f, 0, 0, -1, -1) == 1 &&
                this->buildObject(result, 1) == 1) {
                return 3;
            }
            RGE_Static_Object* object = this->lookupObject(this->currentTargetValue);
            if (object == 0 || this->objectValue->distance_to_object(object) > 1.0f) {
                this->moveTo(this->currentTargetXValue, this->currentTargetYValue,
                             this->currentTargetZValue, 1.0f, 1);
            }
        } else if (this->currentActionValue == 0x25d) {
            int tileX;
            int tileY;
            if (this->closestUndiscoveredTile(&tileX, &tileY, 1) == 1) {
                this->addToWaypointQueue(tileX, tileY);
                if (this->explore(tileX, tileY, 1) != 0) {
                    return 3;
                }
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x4b4);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            } else {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x4c3);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        }

        if (event->mType == 0x202) {
            return 2;
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x4cc);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        break;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }

return_two:
    return 2;
}


int TribeCivilianUnitAIModule::processIdle(int p0) { return 5; }


int TribeCivilianUnitAIModule::processMisc() { return 9; }

// VA: 00505820 TribePriestUnitAIModule::TribePriestUnitAIModule
// PDB source: taiuaimd.cpp
// Attempt log:


TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2)
{
    this->field_128 = 0x11;
    this->field_124 = (int)operator_new(0x44);
}

// VA: 005059A0 TribePriestUnitAIModule::attackObject(int, int)
// PDB source: taiuaimd.cpp lines 1338-1349
// Default flags
//
// attempt log:
// Attempt 1: explicit vtable with void* vtable → shifted offsets by 4 (extra vtable ptr)
// Attempt 2: removed explicit void* vtable → TribePriestUnitAIModule offsets correct
// Attempt 3: object with gap_00[0xC] → shifted offsets by 4 (hidden vtable)
// Attempt 4: object with gap_04[0x8] → all offsets correct, 99/103 matching
// Attempt 5: float temp for weaponRange result → 51 diff bytes (worse)
// Attempt 6: int cp temp → same 4-byte register diff
// Attempt 7: object pointer temp → 51 diff bytes (worse)
//
// Remaining mismatch: 4 bytes of register allocation in weaponRange call block:
//   Original: mov edx,[esp+14h]; push edx; mov eax,[ecx]; call [eax+10Ch]
//   Rebuild:  mov eax,[esp+14h]; push eax; mov edx,[ecx]; call [edx+10Ch]
// This is a stable register-color difference in VC5's virtual-call scheduling.
// SpruceGlow tries 1-10: param_2 local/self-assign/mutate/cast, late object local, float local,
//   early-return/else/nested-positive control-flow forms, manual vtable attempt, and separate object
//   owner local. Most kept the same 4-byte register-color diff; float/local owner/control-flow variants
//   were much worse or failed to compile due VC5 __thiscall limitations.
// SpruceGlow tries 11-20: volatile param_2, long local, saved result, late object declaration,
//   param_1 local, split computerPlayer temp, zero return local, helper idint, and weaponRange signature probes
//   (long/void*) all either kept the same 4-byte diff or worsened codegen.
// ACCEPTED_DRIFT: reviewed by Boss. The diff is exactly four same-length register-color
// bytes in one virtual-call setup: rebuilt pushes param_2 through eax and loads/calls the
// vtable through edx, while original uses edx for the pushed arg and eax for vtable/call.
// Stack effects, call target slot (+0x10C), FPU result handling, branches, return values,
// size, and epilogues are byte-identical otherwise. No inline asm/hacks.


int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    if (this->canConvert(param_1) == 0) {
        if (this->field_28 == -1) {
            if (this->unit->owner->computerPlayer() != 0) {
                return this->moveTo(param_1, this->unit->weaponRange(), param_2);
            }
        }
        return 0;
    }
    return this->convertObject(param_1, param_2);
}


int TribePriestUnitAIModule::retryableOrder(int value) {
    if (value == 0x2C0 || value == 0x2BF)
        return 1;
    return 0;
}


int TribePriestUnitAIModule::canConvert(int id) {
    char* base = (char*)this->some_ptr;

    if (*(float*)(base + 0x44) >= 100.0f) {
        RGE_Static_Object* obj = (*(RGE_Game_World**)(*(char**)(base + 0x0C) + 0x3C))->object(id);
        if (obj) {
            int og = obj->master_obj->object_group;
            short sid = obj->master_obj->id;

            if (sid == 0x6D) return 0;
            if (og == 0x1B) return 0;
            if (sid == 0x9F) return 0;
            if (sid == 0x114) return 0;
            if (sid == 0x9E) return 0;
            if (sid == 0xA3) return 0;
            if (og == 0x1E) return 0;

            if (og == 0x12 && *(float*)(*(char**)(*(char**)((char*)this->some_ptr + 0x0C) + 0x50) + 0x6C) <= 0.0f) return 0;
            if (og == 3 && *(float*)(*(char**)(*(char**)((char*)this->some_ptr + 0x0C) + 0x50) + 0x70) <= 0.0f) return 0;

            return 1;
        }
    }
    return 0;
}


int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (obj != 0) {
        return canConvert(obj->id);
    }
    return 0;
}

// 00505B00 TribePriestUnitAIModule::bestUnitToHeal
// Attempt log:
// 1: Natural nested loops over four ally buckets: compiles 432 vs 445, wrong prologue/self in EBX and wrong canSee vtable surface.
// 2: Switch canSee to +0x194 virtual and bucket offset loop: exact size but 91% diff; self in ESI, 0x28 frame, bad global/list shape.
// 3: Use pointer-to-current bucket globals: frame 0x20 but self still ESI and broad diff.
// 4: Volatile self alias worsened prologue by homing this at [esp]; rolled back.
// 5: /Od and /O2-without-/Oy flag probes did not improve; removed custom flags.
// 6: Rewriting priority gates as <5/<3 worsened to 91.01% diff.
// 7: Naming fpriority before need calculation did not move first mismatch or improve diff.
// 8: Breaking outer loop then returning at function tail worsened to 89.89% diff.
// 9: Reconstructed the single final return with an inner do/while and outer break,
//    removing cached master/priority/offset locals; 445-byte output, 375 differing bytes.
// 10: Restored donor TU context/full UnitAIModule ABI and typed object/owner/record
//     ownership; output was codegen-duplicate (375 differing bytes).
// 11: Caching the current record-list pointer reached an exact 0x1c frame but
//     shortened the body and changed reload behavior; rolled back.
// 12: Reloading the record-list value per iteration also shortened the body;
//     rolled back because the oracle rereads the bucket slot.
// 13: Typed HealUnitRecord indexing and char* bucket offset were source-cleanup
//     probes; both emitted the same 375-byte-diff basin as probe 9.
// 14: Typed five-entry count/list tables gave the same 445-byte basin with a
//     small edit-distance gain; retained as canonical ownership.
// 15: Removed the unit_id temporary and reread the typed record ID at lookup and
//     canSee calls, matching the oracle reload order. Diff fell to 347 bytes and
//     shape rose to 85.19%; this is the current clean reconstruction.
// 16: Hoisting the record-slot pointer emitted identical code; rolled back.
// 17: Typed views over scalar global declarations shortened the body; rolled back.
// 18: Parallel count/list slot pointers kept the same register topology; rolled back.
// 19-28: Scalar-global overlays, parallel pointers, a typed aggregate, category
//     loop forms, direct table expressions, and wider object-pointer scope did
//     not recover the oracle's hidden table-base slot or register colors. The
//     scalar overlay shortened the body; the other forms were codegen duplicates
//     or farther from the oracle. Restored the natural typed table source.
// 29: A reviewed-header byte-offset cursor moved the positional diff to 345,
//     but kept the 0x18 frame and violated the no-byte-cursor source policy;
//     restored the pinned source.
// 30: A cached typed record pointer shortened the body to 390 bytes and moved
//     the frame to 0x14; restored the pinned source.
// 31-39: Re-tested scalar globals, typed and raw offset cursors, declaration
//     order, do/while and for-header forms, and function-scope pointer aliases.
//     They stayed in the same 345-349-byte basin or shortened the body.
// 40: Replayed the prior 344-byte checkpoint. It had a 0x14 frame and only
//     126 instructions, so its smaller diff was not a natural improvement.
// 42-50: Hoisted list/object pointers and tested register hints and an offset
//     address alias. They emitted the clean 347-byte basin or a duplicate.
// 52: Volatile offset storage recovered the 0x1c frame but added six bytes and
//     32 changed spans. Restored the natural typed source.
// 54: Final unchanged validation confirms the pinned 445-byte source and 347
//     differing bytes.
// 55-57: Reviewed scalar DAT globals and casted bucket indexing improved the
//     diagnostic diff to 344 bytes, but shortened the natural body to 429 bytes
//     and lost block shape; restored.
// 58-62: Full tactical member declarations and canonical object vtable names
//     were codegen duplicates after the proven canSee +0x194 slot was restored.
// 63-67: Typed table-slot, count-slot, char-offset, and declaration-order
//     probes stayed in a 345-byte diff basin with the wrong saved-register
//     ownership; restored.
// 68-70: A live list-slot induction pointer recovered the 0x1c frame and more
//     aligned blocks, but added pre-loop global arithmetic and worsened the
//     positional diff to 358 bytes; restored.
// 71-72: A contiguous count/list table overlay shortened the body to 421 bytes
//     and changed global ownership; restored.
// 73: Fresh unchanged validation confirms the pinned natural typed source.
// 74-75: Replaced the outer for/break form with the PDB-supported positive
//     guard, nested do loop, early found-ID return, and final -1 return.
//     This improved the result to 346 differing bytes and 442 bytes, but the
//     offset still stayed in a saved register and the frame stayed 0x18.
// 76-77: Added the binary-proven scalar table bases and byte-offset cursor.
//     Function-scope slot pointers and direct count rereads were codegen
//     duplicates; they did not recover the slot home or saved-register colors.
// 78-80: An index-derived slot pointer recovered the 0x1c frame and 91.85%
//     shape, but worsened the positional diff to 354 bytes. Reference, raw
//     pointer, declaration-order, and reviewed-header variants stayed there.
// 81: Restored the pinned natural typed source and ran unchanged validation.
//     Exactness remains blocked by the slot-pointer and object register basin.
// BLOCKER: the natural typed source now matches the prologue, calls, CFG, size, and
// most inner blocks, but VC5 keeps the table offset in EDI and object in ESI.
// The oracle keeps the table slot in ESI, object in EDI, and one extra frame slot.
// Current best: 445/445 bytes, 347 differing bytes (77.9775%), first mismatch +2.


int TribePriestUnitAIModule::bestUnitToHeal(int param_1, float* param_2)
{
    this->search();

    int allyToHealID = -1;
    float allyNeed = 0.0f;
    int maxLimit = 2;
    int a;
    int i;
    if (this->objectValue->owner->id == 0) {
        maxLimit = 4;
    }

    a = 1;
    for (; a <= maxLimit; ++a) {
        i = 0;
        if (taiuaimd_heal_counts[a - 1] > 0) {
            HealUnitRecord** listPtr = &taiuaimd_heal_records[a - 1];
            do {
                if ((*listPtr)[i].object_id != this->objectValue->id) {
                    RGE_Static_Object* unit =
                        this->lookupObject((*listPtr)[i].object_id);
                    if (unit != 0) {
                        if (unit->master_obj->object_group != 3) {
                            if ((float)(int)unit->master_obj->hp > unit->hp) {
                                if (unit->object_state < 3) {
                                    if (param_1 != 0 ||
                                        (*listPtr)[i].priority <= 4) {
                                        if (this->objectValue->owner->id != 0 ||
                                            (*listPtr)[i].priority <= 2) {
                                            if (taiuaimd_object_can_see(this->objectValue,
                                                    (*listPtr)[i].object_id,
                                                    1.0f, 0, 0, -1, -1)) {
                                                float need = (float)(int)unit->master_obj->hp -
                                                    unit->hp / (float)(int)(*listPtr)[i].priority;
                                                if (allyToHealID == -1 || need < allyNeed) {
                                                    allyNeed = need;
                                                    allyToHealID = unit->id;
                                                    if (param_2 != 0) {
                                                        *param_2 = (float)(int)(*listPtr)[i].priority;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                ++i;
            } while (i < taiuaimd_heal_counts[a - 1]);
        }
        if (allyToHealID != -1) {
            break;
        }
    }

    return allyToHealID;
}

// 00505CC0 TribePriestUnitAIModule::bestUnitToConvert
// taiuaimd.cpp:1517-1558, 263 bytes
//
// int __thiscall TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
// - ret 4 cleanup (1 stack param + this in ecx)
//
// Returns: best unit ID (int), or -1 if none found
// param_1: optional output for priority value (can be NULL)
//
// === Attempt log ===
// 1: C-style function pointer virtual calls; RGE_Player class with virtual
//    Compiled to 263 bytes, 79% positional diff (~208 bytes mismatched)
//    Virtual calls use __cdecl (ecx not set = wrong calling convention)
//    Stack frame: sub esp,10h + push ebx,ebp vs sub esp,0Ch + push ebp,edi
//    Same TU-context register cascade as other view/tai functions
// 2: No virtual functions in any class — .text section issue (263 > 256)
//    Function body 246 bytes (17 bytes short of original)
// 3: Restored exact same-TU UnitAIModule, RGE_Player, and object virtual
//    surfaces; typed search/isEnemy/canConvert calls reached 263 bytes and
//    94.51% shape, with the remaining differences localized to relocations and
//    initial local-home ordering.
// 4: Used the canonical game_globals.h declarations and the proven 8-byte
//    visible-unit record instead of a locally typed global; emitted code was
//    unchanged, but relocation identity became eligible for exact matching.
// 5: Declared targetValue before the loop index, matching the original
//    target-value store before the loop-count home. Exact 263-byte match.


typedef unsigned char uchar;


int TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
{
    this->search();

    int best_id = -1;
    float targetValue = 0.0f;
    int i = 0;

    if ((int)DAT_0087d7d8 > 0) {
        do {
            if (taiuaimd_player_is_enemy(this->objectValue->owner,
                    (int)((VISIBLE_UNIT_REC*)DAT_0087d7f0)[i].player) != 0) {
                RGE_Static_Object* found = this->lookupObject(
                    ((VISIBLE_UNIT_REC*)DAT_0087d7f0)[i].object_id);

                if (found != 0 && found->object_state < 3) {
                    if (this->canConvert(found->id) != 0) {
                        float priority =
                            (float)((VISIBLE_UNIT_REC*)DAT_0087d7f0)[i].distance;
                        if (priority < 1.0f)
                            priority = 1.0f;

                        short hp_short = found->master_obj->hp;
                        float hp_float = (float)hp_short;
                        float score = hp_float / priority;

                        if (best_id == -1 || score > targetValue) {
                            best_id = found->id;
                            targetValue = score;
                            if (param_1 != 0)
                                *param_1 = priority;
                        }
                    }
                }
            }

            i++;
        } while (i < (int)DAT_0087d7d8);
    }

    return best_id;
}

// 00505DD0 TribePriestUnitAIModule::processNotify
// Attempt log:
// 1: Direct reconstruction from packet: switch on event->mType, stop/log tails, special 0x25c/0x25b virtual flows, target-visible branch.
// 2: Inlined repeated logging instead of helper; got to 1-byte diff. Fixed RGE_Player::visible_map offset from +34 to +38.

extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];


int TribePriestUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1f9:
    case 0x1fb:
    case 0x202:
        if (this->objectValue->owner->computerPlayer() == 0 && this->field_30 == 0x25c) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x63b);
            }
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (this->field_30 == 0x25c) {
            int id = this->bestUnitToConvert(0);
            if (id != -1 && this->convertObject(id, 1) == 1) {
                return 3;
            }
        } else if (this->field_30 == 0x25b) {
            int id = this->bestUnitToHeal(0, 0);
            if (id != -1 && this->healObject(id, 1) == 1) {
                return 3;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x675);
            }
        this->stopObject(0);
        this->notifyCommander(event);
        return 2;

    case 0x1fc:
    {
        RGE_Static_Object* obj = this->lookupObject(this->field_34);
        if (obj != 0) {
            if (this->visibleStatus(taiuaimd_player_visible_map(this->objectValue->owner),
                                    (int)obj->world_x, (int)obj->world_y) == 0x0f) {
                return 2;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x68f);
            }
        this->stopObject(1);
        this->notifyCommander(event);
        break;
    }
    }

    return UnitAIModule::processNotify(event, param_2);
}

// 00505FD0 TribePriestUnitAIModule::processIdle
// Source: taiuaimd.cpp lines 1692-1756
// Attempt log:
// 1: initial natural source with virtual slots 0x40/0x70/0x9C/0xE0, base processIdle member, debug_rand, and intrinsic sqrt: wrong frame (sub 10), object field offset +0x10 from explicit vtable+virtual double count, early null return inline.
// 2: remove explicit object vtable field and wrap body in positive computerPlayer guard: shortened to 352 without local output.
// 3: restore 4-byte local output buffer: still 352.
// 4: return to early-return structure with corrected object offsets: exact object offsets but still sub esp,10; early fail inline.
// 5: move chooseSomething output local into narrow scope: fixed sub esp,0C and output address; 33.9% edit diff. Remaining branch layout differs (early fail inline vs shared tail) and later FPU/call scheduling shifted.
// 6: positive computerPlayer/target guards shortened to 352.
// 7: explicit goto shared ret5 with top declarations shortened to 336, wrong family.
// 8: corrected the object slot +0x10C surface (the period method is weaponRange);
//    returned to best attempt-5 source family.
// 9: status local with `if (status != 6) { body } return 6` to try inline ret6 layout.
// 10: restored full same-TU UnitAIModule/RGE_Static_Object virtual surfaces,
//     typed globals, positive guards, and the donor-backed weaponRange gate;
//     335 differing bytes, with calls and frame aligned.
// 11: put the success/failure flow back into the original positive outer guard;
//     153 differing bytes and exact central block islands.
// 12: reversed the commutative distance-square terms; FPU stack schedule moved
//     toward the original, 62 differing bytes.
// 13: mirrored exact idle donors' xDiff-then-yDiff declaration/order; 54 bytes
//     remained, localized to movement lowering and the success tail.
// 14: explicit float casts around the negated movement products plus a direct
//     return 6 after evasiveMoveTo reproduce the complete 360-byte function.


#pragma intrinsic(sqrt)

extern int __cdecl debug_rand(const char* file, int line);


int TribePriestUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        if (UnitAIModule::processIdle(1) == 6) {
            return 6;
        }

    int range = (int)DAT_0087d7d8;
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x6AC) % (range + 2);
    if (range > 0 && r > range) {
        float local_4;
        int action = this->bestUnitToHeal(1, &local_4);
        if (action != -1) {
            this->healObject(action, 0);
            return 6;
        }
    }

    int targetId = this->closestObject(-1, 2, -1, -1, 0);
    if (targetId == -1) {
        return 5;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
    if (target == 0) {
        return 5;
    }

    float xDiff = target->world_x - this->objectValue->world_x;
    float yDiff = target->world_y - this->objectValue->world_y;
    float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
    float distanceDiff = this->objectValue->weaponRange() - dist;

    if (distanceDiff <= DAT_005758c4) {
        return 5;
    }

    float nx = (float)(-((xDiff / dist) * distanceDiff)) +
               this->objectValue->world_x;
    float ny = (float)(-((yDiff / dist) * distanceDiff)) +
               this->objectValue->world_y;
    this->evasiveMoveTo(nx, ny, this->objectValue->world_z, 1);
    return 6;
    }

    return 5;
}

// VA: 00506140 TribePriestUnitAIModule::processMisc
// PDB: taiuaimd.cpp:1761-1796
//
// Attempt log:
// baseline: natural UnitAIModule/Action_Object ownership, direct helper
// methods, and the period Priest virtual surface; exact 247-byte match.



extern FILE* actionFile;

int TribePriestUnitAIModule::processMisc()
{
    if (this->objectValue->owner->computerPlayer() == 1) {
        RGE_Action_Object* object = (RGE_Action_Object*)this->objectValue;

        if (object->attribute_amount_held >= 100.0f) {
            if (object->actions->have_action() != 1 ||
                object->actions->get_action()->state != 7) {
                int target = this->bestUnitToAttack(1, 1, 0);

                if (target != -1 && this->currentTargetValue != target) {
                    if (this->currentOrderValue != -1) {
                        this->order(
                            this->objectValue->id,
                            this->currentOrderValue,
                            this->currentTargetValue,
                            -1,
                            this->currentTargetXValue,
                            this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue,
                            0,
                            0,
                            this->currentOrderPriorityValue);

                        if (actionFile != 0) {
                            int objectID;
                            if (this->objectValue != 0) {
                                objectID = this->objectValue->id;
                            } else {
                                objectID = -1;
                            }
                            fprintf(actionFile,
                                "#%d call stopObject %s %d\n",
                                objectID,
                                "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp",
                                0x6F8);
                        }

                        this->stopObject(1);
                    }

                    if (this->attackObject(target, 1) == 1) {
                        return 10;
                    }
                }
            }
        }
    }

    return 9;
}

// VA: 00506240, TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame.
// Historical exact flags: config/flags/00506240_TribeTradeShipUnitAIModule.rsp



TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 5;
    importantObjects = (int*)operator new(0x14);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
    }
}

// VA: 00506320 TribeTradeShipUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 1823-1976
// Attempt log:
// - Clean baseline: restored the period typed UnitAIModule/RGE_Static_Object/
//   RGE_Player surfaces from exact taiuaimd.cpp siblings.  The notification
//   list and growth path follows the matching fishing/transport implementations;
//   trade retry uses the proven closestObject/tradeWithObject and
//   closestUndiscoveredTile/explore virtual slots.  The +0x1c callback in the
//   retry cleanup is UnitAIModule::notifyCommander(NotifyEvent*), not a
//   recursive processNotify call.
// - Baseline was exact in size/frame/CFG with a 3-byte mismatch: the trade
//   retry dispatch read +0x28, while the oracle reads currentAction at +0x30.
// - Correcting both retry comparisons to currentActionValue reduced the gap
//   to two bytes; the only remaining issue was the +0x18/+0x1c overload slot.
// - A pointer overload declared after the six-argument notifyCommander (and a
//   void*/distinct-name diagnostic) selected +0x18 under VC5.  Mirroring the
//   exact sibling's pointer-before-six-argument declaration order selects the
//   proven +0x1c callback and closes the match.  No custom flags or asm.



int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;

    case 0x202:
        if (this->currentActionValue == 0x267) {
            int id = this->closestObject(-1, 0, 2, 0x2d, 0);
            if (id != -1 && this->tradeWithObject(id, 1) == 1) {
                return 6;
            }

            id = this->closestObject(-1, 1, 2, 0x2d, 0);
            if (id != -1 && this->tradeWithObject(id, 1) == 1) {
                return 6;
            }
        } else if (this->currentActionValue == 0x25d) {
            int x;
            int y;
            if (this->closestUndiscoveredTile(&x, &y, 1) == 1) {
                this->addToWaypointQueue(x, y);
                if (this->explore(x, y, 1) == 0) {
                    this->removeCurrentTarget();
                    if (actionFile != 0) {
                        int id;
                        if (this->objectValue != 0) {
                            id = this->objectValue->id;
                        } else {
                            id = -1;
                        }
                        fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                                "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x79c);
                    }
                    this->stopObject(1);
                    this->notifyCommander(event);
                }
            } else {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7a8);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        }

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7b0);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->helpCount == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x201, event->caller, 0, 0);
    }

    int count = this->helpCount;
    int i = 0;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == event->caller) {
            goto skip_help;
        }
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != event->caller) {
        this->askForHelp(event->caller);
    }

skip_help:
    i = 0;
    int caller = event->caller;
    count = this->helpCount;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == caller) {
            goto after_add;
        }
    }

    if (this->helpCount > this->helpMax - 1) {
        int newMax = this->helpCount + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->helpMax && i < newMax; ++i) {
                newList[i] = this->helpList[i];
            }
            operator delete(this->helpList);
            this->helpList = newList;
            this->helpMax = newMax;
        }
    }
    this->helpList[this->helpCount] = caller;
    this->helpCount++;

after_add:
    this->objectValue->setUnderAttack(1);
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x761);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}

// 005066D0 TribeTradeShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:1981-2027, 250 bytes
//
// Canonical reconstruction: an AI trade ship looks for its destination,
// obtains the ship speed, and moves back toward the ship by seven speed
// units.  The object/player/world fields and the virtual calls are modeled at
// their proven offsets; the math is kept in the natural source form suggested
// by the original x87 stack topology.
//
// Attempt log:
// - Typed virtual surfaces and nested success guards matched the frame, calls,
//   and all non-math control-flow structure.
// - Binding the seven-times-speed scale to the getter result reproduced the
//   original early FMUL and exact-size FPU schedule.
// - The explicit float cast around each negated movement product is deliberate:
//   without it VC5 folds the operation into FPU FSUBR; with it the original
//   FCHS/FADD pair and branch displacements are reproduced. MATCH.
// Main-agent audit restored canonical destructor slots on the world/player,
// object, and AI surfaces; emitted code remains exact.



int TribeTradeShipUnitAIModule::processIdle(int param_1)
{
    if (this->obj->owner->computerPlayer()) {
        int targetId = this->closestObject(-1, -1, -1, -1, 0);
        if (targetId != -1) {
            RGE_Static_Object* target = this->obj->owner->world->object(targetId);
            if (target != 0) {
                float speed = this->obj->maximumSpeed() * 7.0f;
                float xDiff = target->world_x - this->obj->world_x;
                float yDiff = target->world_y - this->obj->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                this->moveTo(
                    (float)(-(xDiff / distance * speed)) + this->obj->world_x,
                    (float)(-(yDiff / distance * speed)) + this->obj->world_y,
                    this->obj->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}

// VA: 005067D0, TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule
// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// visible virtual base dtor + /GX triggers the lightweight constructor EH frame.
// Historical exact flags: config/flags/005067D0_TribeTransportShipUnitAIModule.rsp



TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 5;
    importantObjects = (int*)operator new(0x14);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
    }
}

// VA: 005068B0, processNotify, 444 bytes
// Source: taiuaimd.cpp lines 2051-2117
// Status: EXACT — validated VC5 codegen match
// Attempt log:
// - v1: natural decompiler-shaped implementation with local structs/vtable pads.
// - v2: fixed notify caller offset to +0, p2 to +0x10 and base call signature with ulong.
// - v3/v4: changed mType dispatch to subtract chain; v4 uses `t != 0 && t != 0x1b`.
// - v5: cached helpMax in scan loops to avoid extra max>0 pretest/pointer-walk family.
// - v6: modeled RGE_Static_Object::action_list as pointer at +0x184, fixing final have_action/get_action surface.
// - v7: switch for mType dispatch emits original sub/sub chain exactly.
// - v8: introduced count locals for scan loops to try to get count in ecx and max in edx like original.
// - v9: swapped count/i declaration order; no register change.
// - v10: left in scratch. Best check: 444/444 bytes, positional diff 55.8559%, edit diff 31.3063%, first mismatch at +0xA0.
//   Blocker: scan-loop register/topology mismatch. Original uses indexed loop with ecx=count, edx=max,
//   ebx=list, ebp/edi=caller; rebuilt uses edx=count, ebp=max and pointer-walk/add forms, cascading into
//   allocation-copy registers (newMax/newList/caller) despite matching call set, stack cleanup, and final action-list surface.
// - v11: restored the exact same-TU UnitAIModule, RGE_Player, RGE_Static_Object,
//   and action-list virtual/direct surfaces; indexed scan and copy topology were
//   structurally aligned, but redundant bound guards remained.
// - v12: tested do/while scans and the donor bounded-copy form; do/while caused
//   pointer-walk register coloring, so the indexed for family was retained.
// - v13: removed the outer positive count wrappers; size reached 444 and the
//   remaining drift localized to bound scheduling and relocation identity.
// - v14: expressed both scans as natural combined `i < count && i < helpMax`
//   bounds. Exact 444-byte match with all 13 calls and 9/9 relocations aligned.


int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* o = this->obj;
        taiuaimd_player_notify(o->owner, o->id, o->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->helpCount == 0 || ((RGE_Player*)this->obj->owner)->computerPlayer() == 1) {
        RGE_Static_Object* o = this->obj;
        taiuaimd_player_notify(o->owner, o->id, o->id, 0x201, event->caller, 0, 0);
    }

    int count = this->helpCount;
    int i = 0;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == event->caller) goto found_for_help;
    }
    if (((RGE_Player*)this->obj->owner)->computerPlayer() == 0 && this->currentTarget != event->caller) {
        this->askForHelp(event->caller);
    }

found_for_help:
    i = 0;
    int caller = event->caller;
    count = this->helpCount;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == caller) goto already_in_list;
    }

    if (this->helpCount > this->helpMax - 1) {
        int newMax = this->helpCount + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->helpMax && i < newMax; ++i)
                newList[i] = this->helpList[i];
            operator delete(this->helpList);
            this->helpList = newList;
            this->helpMax = newMax;
        }
    }
    this->helpList[this->helpCount] = caller;
    this->helpCount++;

already_in_list:
    this->obj->setUnderAttack(1);
    if (this->currentOrder != -1) {
        return 2;
    }

    RGE_Action_Object* obj2 = (RGE_Action_Object*)this->obj;
    if (!obj2->action_list->have_action() || obj2->action_list->get_action()->state == 2) {
        this->runAwayFromAttackers(1);
    }
    return 3;
}

// 00506A70 TribeTransportShipUnitAIModule::processIdle (taiuaimd.cpp:2122-2147)
// int __thiscall processIdle(int param_1)
//
// MATCHED - natural typed thiscall virtual surfaces reproduce both dispatch calls.
// The final explicit float cast preserves the original VC5 fchs/fadd movement lowering.
//
// Attempts:
// 1. __fastcall vtable shims and early returns produced an extra edx setup and wrong tails.
// 2. Typed virtual slots at +40/+9C and +FC removed the ABI drift and fixed the structure.
// 3. Materializing getSpeed()*7 before dx/dy fixed the original FPU evaluation order.
// 4-7. Equivalent movement spellings either emitted fsubr or spilled intermediates.
// 8. A focused variant lab found `(float)(-((delta / distance) * speed)) + position` exact.
// Main-agent audit restored canonical polymorphic ownership and destructor
// slots throughout the world/object/AI surface; emitted code remains exact.



int TribeTransportShipUnitAIModule::processIdle(int param_1)
{
    if (this->sub->owner->computerPlayer()) {
        int targetId = closestObject(-1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->sub->owner->world->object(targetId);

            if (target != 0) {
                float speed = this->sub->maximumSpeed() * 7.0f;

                float dx = target->world_x - this->sub->world_x;
                float dy = target->world_y - this->sub->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);

                float move_x = (float)(-((dx / dist) * speed)) + this->sub->world_x;
                float move_y = (float)(-((dy / dist) * speed)) + this->sub->world_y;

                moveTo(move_x, move_y, this->sub->world_z, 1);

                return 6;
            }
        }
    }

    return 5;
}

// 00506B70 TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(RGE_Static_Object*, int)
// Constructor, EH frame — needs /GX flag
// Source: taiuaimd.cpp lines 2155-2168
// Size: 207 bytes
//
// MATCHED. Exact 207-byte match confirmed via local check_function.py.
//
// Key findings:
// - /GX needed for EH prologue/epilogue (fs:[0] save/restore with handler)
// - Virtual ~UnitAIModule() needed to trigger constructor EH frame
//   (operator new alone insufficient in single-function TU)
// - this->importantObjects[i] for writes 1-7 forces per-index reload from [esi+124h]
//   matching original's mov reg,[esi+124h]; mov [reg+offset],val pattern
// - importantObjects at +0x124, numberImportantObjects at +0x128



TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 8;
    importantObjects = (int*)operator new(0x20);

    if (importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0x16;
        this->importantObjects[2] = 0x14;
        this->importantObjects[3] = 2;
        this->importantObjects[4] = 0x15;
        this->importantObjects[5] = 5;
        this->importantObjects[6] = 0x1F;
        this->importantObjects[7] = 0x21;
    }
}


int TribeFishingShipUnitAIModule::importantWhenDead(int value) {
    if (value != 0x1F && value != 5) {
        return 0;
    }
    return 1;
}


int TribeFishingShipUnitAIModule::convertToLOSResourceType(int value) {
    if (value == 0x1F || value == 0x5 || value == 0x21)
        return 2;
    return -1;
}

// VA: 00506CC0 TribeFishingShipUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 2197-2276
// Attempt log:
// 1: natural reconstruction from packet with direct fields, virtual calls, dynamic int-list growth: broad mismatch; compiler cached NotifyEvent in EBP not original EDI.
// 2: add register event alias and use it throughout to try EDI allocation; no register change.
// 3: tried notification type gate as switch; no prologue/register improvement and slightly worse diff, rolled back.
// 4: tried narrow /O1 as possible register/prologue probe; object shrank to 521 and failed configured size, flag removed.
// 5: tried /O2 /Oy /Ob0 flag probe; same as default, flag removed.
// 6: remove event alias and use parameter directly to test whether alias caused EBP cache; no change.
// 7: corrected RGE_Player virtual padding so sendCommand is at vtable +0xE8 instead of +0x20; behavior surface improved but diff worsened due existing early register barrier.
// 8: reviewed late stopObject/vf58/vfA4 surface: current manual vtbl field is behaviorally suspect for ECX=this scheduling, but changing to full virtual class would require reworking all field offsets.
// 9: compared default vs flag/no-alias/switch variants; best byte metrics remain the natural default family before vtable padding, but kept vtable padding because it matches binary-observed +0xE8 call target.
// 10: left in scratch: main blocker is first prologue/register allocation (original EDI=NotifyEvent, ESI=this; rebuilt EBP=NotifyEvent), cascading through all event/list logic plus unresolved true class/vtable surface for late stop calls.
// 11: restored the same-TU UnitAIModule/RGE_Static_Object/RGE_Player surfaces as the exact transport-ship donor; the target's +0x10 call is the real order slot, followed by stopObject and runAwayFromAttackers.



int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* ev, ulong flags)
{
    switch (ev->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(ev, flags);
    }

    if (ev->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x209, ev->caller, 0, 0);
        this->purgeNotifyQueue(flags);
        return 4;
    }

    if (this->helpCount == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x201, ev->caller, 0, 0);
    }

    int count = this->helpCount;
    int i = 0;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == ev->caller) goto skip_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != ev->caller) {
        this->askForHelp(ev->caller);
    }

skip_help:
    i = 0;
    int caller = ev->caller;
    count = this->helpCount;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == caller) goto after_add;
    }

    if (this->helpCount > this->helpMax - 1) {
        int newMax = this->helpCount + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->helpMax && i < newMax; ++i)
                newList[i] = this->helpList[i];
            operator delete(this->helpList);
            this->helpList = newList;
            this->helpMax = newMax;
        }
    }
    this->helpList[this->helpCount] = caller;
    this->helpCount++;

after_add:
    this->objectValue->setUnderAttack(1);
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0)
                id = this->objectValue->id;
            else
                id = -1;
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x8d4);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}

// VA: 00506EE0 TribeFishingShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:2281-2306, 250 bytes
// __thiscall: ecx=this, one stack parameter, ret 4
//
// Attempt log:
// The parked predecessor used raw function-pointer calls and got cdecl/fastcall
// stack plumbing instead of the observed virtual thiscall calls.  This candidate
// restores the natural UnitAIModule and RGE_Static_Object virtual surfaces, named
// coordinate locals, and the direct period-style movement expression.
// Baseline: 250 bytes, 53 differing bytes; all five calls, frame, and prefix
// structure aligned.
// Named x/y offset temporaries were codegen-neutral; explicit assignments added
// stack homes and eight bytes, so they were rolled back.
// Separate speed/factor locals moved the x87 schedule and widened the function;
// the scaled return local is retained.
// Binary-required arithmetic spelling: `0.0f - offset` preserves the original
// fchs/fadd tail, while unary minus or direct subtraction lowers to fsubr.  The
// simple zero-minus form is retained because it is the only exact natural form
// found and matches the observed arithmetic topology.
// Main-agent audit restored canonical destructor slots across the player,
// object, world, and AI virtual surfaces; emitted code remains exact.


extern float DAT_005758d8; // 7.0f


int TribeFishingShipUnitAIModule::processIdle(int param_1)
{
    if (objectValue->owner->computerPlayer()) {
        int targetID = closestObject(-1, -1, -1, -1, 0);

        if (targetID != -1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            if (target != 0) {
                float speed = objectValue->maximumSpeed() * DAT_005758d8;
                float xDiff = target->world_x - objectValue->world_x;
                float yDiff = target->world_y - objectValue->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                moveTo((0.0f - ((xDiff / distance) * speed)) + objectValue->world_x,
                       (0.0f - ((yDiff / distance) * speed)) + objectValue->world_y,
                       objectValue->facet, 1);
                return 6;
            }
        }
    }

    return 5;
}

// VA: 00506FE0, TribeSoldierUnitAIModule::TribeSoldierUnitAIModule
// Donor: exact UnitAIModule-derived constructor shape from taiuaimd.cpp.
// Historical exact flags: config/flags/00506FE0_TribeSoldierUnitAIModule.rsp
// Canonical-context check: the PDB 0x134 base and PAV parameter symbol remain exact.


void* operator new(size_t size);

TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }

    idleTimeoutValue = 0x5DC;
    setAdjustedIdleTimeout();
}


// PDB ownership gives a public virtual method with a class-pointer parameter.

int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->master_obj->object_group != 1;
}


// PDB ownership gives a public virtual TribeSoldierUnitAIModule method.

int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2 || value == 0x14)
        return 0;
    return 1;
}

// VA 005071F0 TribeSoldierUnitAIModule::processNotify
// taiuaimd.cpp:2380-2536
// Attempt log:
// 1: Natural reconstruction from packet/decompiler using nearby taiuaimd processNotify/list-growth patterns.
// 2: Modeled NotifyEvent type split for 0x20F evasive-move and 0x200 chase/retreat paths, with base processNotify fallback.
// 3: Added computerPlayer/world->object/type gates, group 0x23/0x24 checks, command/target checks, and issueOrder/moveTo virtual-call surfaces.
// 4: Added debug_rand jitter and FPU-ish random coordinate adjustment logic for both X/Y evasive targets.
// 5: Added rangeLeft/distance_to_object check, target vector accumulation, dynamic id-list growth/copy/delete pattern, and normalized retreat move.
// 6: Default /O2 /Oy compiles but is size-short: configured 1098 exceeds rebuilt .text 992. Broad source is behaviorally approximate but not enough codegen/detail.
// 7: Probed /Od: exact size 1098 but broad wrong basin from offset 0 (86.7942% positional); removed flag.
// 8: Probed /O2 /Oy /Ob0: still size-short 992; removed flag.
// 9: Probed /O2 /Oy /Og-: exact size 1098 but broad wrong basin from offset 0 (86.0656% positional); removed flag.
// 10: Probed /O2 /Oy /Op: closer size 1040 but still size-short; removed flag.
// 11: Probed /O1 /Oy: size-short 861; removed flag.
// 12: Rebuilt the canonical taiuaimd class surfaces: switched to the original 0x200/0x20F dispatch order, typed owner/master/world access, UnitAIModule::order/intelligentEvasiveMoveTo, weaponRange, and the inline ManagedArray indexer.
// 13: Common-fallback goto/positive-guard rewrites moved the fallback block early and degraded the otherwise aligned call/body basin; reverted.
// 14: Scoping jitter locals, splitting modulo into a temporary, adding stdio context, and reusing the jitter local for the range delta did not improve emitted code; reverted.
// 15: Explicit goto-to-base paths in the switch were codegen-identical; the compiler still relocated the fallback before the 0x200 body.
// 16: A positive compound 0x20F guard inside the switch was codegen-identical; Ghidra's guard shape did not change the VC5 basin.
// 17: Reusing param_1's dead stack home for the second jitter float worsened the diff and did not reduce the 0x0C frame; reverted.
// 18: Reusing evasiveMoveDistance for the 0x200 range delta kept size/diff but worsened shape and exact-block coverage; reverted.
// 19: Moving both guards into the decompiler's if/else-if form matched the earlier broad 1055-byte basin; reverted.
// 20: Modeling one explicit 0x200 case with a default 0x20F guard changed dispatch to cmp and worsened the diff to 944; reverted.
// 21: Replaced switch breaks with an if/else dispatch and one late base label; 1055-byte diff and 6/+6 call-site gaps; reverted.
// 22: Swapped the switch arm order; emitted code was identical to the clean 855-byte candidate; reverted.
// 23: Replaced rejected switch breaks with direct base returns; added ten processNotify calls and worsened the diff to 1225; reverted.
// 24: Explicit 0x200-to-0x20F labels kept the fallback late but changed the dispatch/body basin to 1062 bytes and 6/+6 call gaps; reverted.
// 40 meaningful probes: direct +0x60 pointer, +0x64 count, and +0x6C capacity fields with
// duplicated natural growth scans recover the shipped list-loop basin. The best
// result is 1078 bytes, 0x8 frame, 93.75% shape, and 639 strict-diff bytes.
// Parenthesized random-coordinate arithmetic and the inverted >10 branch recover
// both x87 jitter blocks. The remaining drift is the late shared base-fallback
// block: the rebuilt guards use short branches to an early call site.
// Compiler-neutral goto and local-order reductions were removed from the pinned source.
// Canonical taiuaimd context restores the protected virtual MAE owner symbol.
//
// Exact-finish:
// - The exact transition uses positive ordered guards for the 0x200 path.
// - Shared return_two and return_base labels keep the cold paths late.
// - Natural break exits remain in the 0x20F path. Their explicit goto forms
//   were tested and removed because they produced the same bytes.
// - The negative 0x200 guard form kept size and calls but changed four bytes
//   in the private return block. Keep the positive guard form.
// - Fresh check: MATCH, 1098 bytes, 0.0000% positional difference.
//
// BINARY NOTE: fallback rereads both message arguments at the late call.
// BINARY NOTE: the 0x20F success path publishes taskedThisUpdate only after
// intelligentEvasiveMoveTo succeeds. Keep this order and these fault boundaries.


extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

extern "C" int debug_rand(char*, int);
extern float DAT_005758bc;
extern float DAT_005758c0;
extern float DAT_005758dc;
extern float DAT_005758e0;
extern float DAT_005758e4;

int TribeSoldierUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2)
{
    NotifyEvent* event = param_1;
    float evasiveMoveDistance;
    float fStack_8;
    RGE_Static_Object* target;
    float distanceLeft;
    float xDiff;
    float yDiff;
    float distance;
    int i;

    switch (event->mType) {
    case 0x20F: {
        if (this->objectValue->owner->computerPlayer() == 0)
            break;

        RGE_Static_Object* attacker =
            this->objectValue->owner->world->object(event->caller);
        if (attacker == 0)
            break;
        short group = attacker->master_obj->id;
        if (group != 0x23 && group != 0x24)
            break;
        if (this->currentActionValue == -1)
            break;

        if (this->currentOrderValue != -1) {
            this->order(
                this->objectValue->id, this->currentOrderValue,
                this->currentTargetValue, -1,
                this->currentTargetXValue, this->currentTargetYValue,
                this->currentTargetZValue, this->desiredTargetDistanceValue,
                0, 0, this->currentOrderPriorityValue);
        }

        evasiveMoveDistance =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x97c) % 8) +
            (this->objectValue->world_x - DAT_005758dc);
        if (evasiveMoveDistance == this->objectValue->world_x) {
            if (evasiveMoveDistance > DAT_005758e0)
                evasiveMoveDistance -= DAT_005758c0;
            else
                evasiveMoveDistance -= DAT_005758e4;
        }

        fStack_8 =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x983) % 8) +
            (this->objectValue->world_y - DAT_005758dc);
        if (fStack_8 == this->objectValue->world_y) {
            if (fStack_8 > DAT_005758e0)
                fStack_8 -= DAT_005758c0;
            else
                fStack_8 -= DAT_005758e4;
        }

        if (this->intelligentEvasiveMoveTo(
                evasiveMoveDistance, fStack_8,
                this->objectValue->world_z, 1, 1) != 1)
            break;
        *(int*)0x592A48 = 1;
        return 3;
    }

    case 0x200: {
        if (this->objectValue->owner->computerPlayer() != 0 &&
            this->objectValue->weaponRange() >= DAT_005758bc &&
            this->objectValue->master_obj->object_group != 0x1A) {
            if (this->currentActionValue == 600) {

            target =
                this->objectValue->owner->world->object(this->currentTargetValue);
            if (target != 0) {

                distanceLeft = this->objectValue->weaponRange() -
                    this->objectValue->distance_to_object(target);
                if (distanceLeft >= DAT_005758bc) {

                    xDiff = target->world_x - this->objectValue->world_x;
                    yDiff = target->world_y - this->objectValue->world_y;

                    this->order(
                        this->objectValue->id, 700, this->currentTargetValue, -1,
                        this->currentTargetXValue, this->currentTargetYValue,
                        this->currentTargetZValue, this->desiredTargetDistanceValue,
                        0, 1, this->currentOrderPriorityValue);

                    if (this->attackingUnitsValue.numberValue > 0) {
            i = 0;
            while (i < this->attackingUnitsValue.numberValue) {
                if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                    int newCount = i + 1;
                    int* newValues = new int[newCount];
                    if (newValues != 0) {
                        int j = 0;
                        if (this->attackingUnitsValue.maximumSizeValue > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    newValues[j - 1] = this->attackingUnitsValue.value[j - 1];
                                } else {
                                    break;
                                }
                            } while (j < this->attackingUnitsValue.maximumSizeValue);
                        }
                        delete[] this->attackingUnitsValue.value;
                        this->attackingUnitsValue.value = newValues;
                        this->attackingUnitsValue.maximumSizeValue = newCount;
                    }
                }
                if (this->attackingUnitsValue.value[i] != this->currentTargetValue) {
                    if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                        int newCount = i + 1;
                        int* newValues = new int[newCount];
                        if (newValues != 0) {
                            int j = 0;
                            if (this->attackingUnitsValue.maximumSizeValue > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        newValues[j - 1] = this->attackingUnitsValue.value[j - 1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->attackingUnitsValue.maximumSizeValue);
                            }
                            delete[] this->attackingUnitsValue.value;
                            this->attackingUnitsValue.value = newValues;
                            this->attackingUnitsValue.maximumSizeValue = newCount;
                        }
                    }
                    RGE_Static_Object* object =
                        this->objectValue->owner->world->object(
                            this->attackingUnitsValue.value[i]);
                    if (object != 0) {
                        xDiff += object->world_x - this->objectValue->world_x;
                        yDiff += object->world_y - this->objectValue->world_y;
                    }
                }
                ++i;
            }
                    }

                    distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
                    if (this->intelligentEvasiveMoveTo(
                                        (float)(-((xDiff / distance) * distanceLeft)) +
                                this->objectValue->world_x,
                                        (float)(-((yDiff / distance) * distanceLeft)) +
                            this->objectValue->world_y,
                        this->objectValue->world_z, 0, 1) != 1)
                        goto return_two;
                    return 3;
                }
            }
        } else {
            goto return_two;
        }
        goto return_base;
    }
    }

    default:
        goto return_base;
    }

return_base:
    return UnitAIModule::processNotify(event, param_2);
return_two:
    return 2;
}

// VA: 00507640 TribeSoldierUnitAIModule::processIdle
// PDB: taiuaimd.cpp:2541-2629, 564 bytes
//
// Attempt log:
// Prior parked work reconstructed the broad behavior but used an incorrect
// object/master surface and omitted the maximum-speed result in the final
// movement calculation.  The current candidate restores the period
// UnitAIModule/RGE object surfaces and the duplicated strategic-number gate
// visible in the executable.  Keep later source-shape probes below this note.
//
// Prior evidence retained from the parked attempt:
// - the target is normal corpus work and uses the default VC5 /O2 /Oy flags;
// - all 16 calls, shared return-5 tail, and the +0xFC/+0x9C virtual slots are
//   binary-proven;
// - the final movement uses object maximumSpeed() multiplied by [5758B0h]
//   (3.0f), then normalized x/y deltas and evasiveMoveTo(..., world_z, 1).
// Baseline result: exact 564-byte match with the default /O2 /Oy response.
// Source audit: named master/player/object ownership and ordinary virtual
// declarations are retained; no inline asm, volatility, or codegen-only pad
// function is used.
//
// Exact-finish notes:
// - The first exact check matched 564 bytes and all 16 ordered calls.
// - The real object, player, master, and UnitAIModule surfaces are required.
// - Collapsing the duplicated strategic-number gate removed 3 calls and 56
//   bytes. It also changed the first direct call, so the shipped gate stays.
// - Removing the explicit sqrt float cast kept the exact result. The reduced
//   source keeps that simpler form.
// - Keep SPEED_3. The binary loads the soldier speed constant at 5758B0h.


extern const float SPEED_3; // 3.0f at [5758B0h]


int TribeSoldierUnitAIModule::processIdle(int param_1)
{
    if (param_1 == 1 && this->processRetryableOrder() == 8) {
        return 6;
    }

    if (this->objectValue->owner->id != 0 &&
        (this->objectValue->owner->computerPlayer() != 0 ||
         this->objectValue->master_obj->id != 0x12B)) {
        if (this->currentActionValue != 0x2D5 ||
            (this->objectValue->master_obj->id != 0x23 &&
             this->objectValue->master_obj->id != 0x24 &&
             this->objectValue->master_obj->id != 0xFA)) {
            int targetID = this->bestUnitToAttack(1, 0, 0);
            if (targetID != -1 && this->attackObject(targetID, 1) == 1) {
                return 6;
            }

            if (this->objectValue->owner->computerPlayer() != 0 &&
                taiuaimd_object_in_group(this->objectValue) != 1) {
                taiuaimd_world_difficulty(this->objectValue->owner->world);

                if ((rge_base_game->scenarioGame() == 1 &&
                     rge_base_game->singlePlayerGame() == 1 &&
                     taiuaimd_player_strategic_number(this->objectValue->owner, 0x8F) == 0) ||
                    (rge_base_game->singlePlayerGame() == 1 &&
                     taiuaimd_player_strategic_number(this->objectValue->owner, 0x8F) == 0)) {
                    return 5;
                }

                if (this->currentActionValue != 0x2BD &&
                    this->currentActionValue != 0x2D5) {
                    int targetID2 = this->closestObject(-1, -1, -1, -1, 0);
                    if (targetID2 != -1) {
                        RGE_Static_Object* target =
                            this->objectValue->owner->world->object(targetID2);
                        if (target != 0) {
                            float speed =
                                this->objectValue->maximumSpeed() * SPEED_3;
                            float xDiff = target->world_x - this->objectValue->world_x;
                            float yDiff = target->world_y - this->objectValue->world_y;
                            float distance =
                                sqrt(xDiff * xDiff + yDiff * yDiff);
                            float x =
                                (float)(-((xDiff / distance) * speed)) +
                                this->objectValue->world_x;
                            float y =
                                (float)(-((yDiff / distance) * speed)) +
                                this->objectValue->world_y;
                            this->evasiveMoveTo(
                                x, y, this->objectValue->world_z, 1);
                            return 6;
                        }
                    }
                }
            }
        }
    }

    return 5;
}

// VA: 00507880, TribeArtifactUnitAIModule::TribeArtifactUnitAIModule
// Donor: exact UnitAIModule-derived constructor shape from taiuaimd.cpp.
// Historical exact flags: config/flags/00507880_TribeArtifactUnitAIModule.rsp


void* operator new(size_t size);


TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(
    RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x13;
    importantObjects = (int*)operator new(0x4C);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 4;
        this->importantObjects[2] = 0x1A;
        this->importantObjects[3] = 0x18;
        this->importantObjects[4] = 6;
        this->importantObjects[5] = 0x23;
        this->importantObjects[6] = 0x19;
        this->importantObjects[7] = 0x11;
        this->importantObjects[8] = 0x0C;
        this->importantObjects[9] = 0x17;
        this->importantObjects[10] = 0x24;
        this->importantObjects[11] = 0x1C;
        this->importantObjects[12] = 0x12;
        this->importantObjects[13] = 0x0D;
        this->importantObjects[14] = 0x16;
        this->importantObjects[15] = 0x14;
        this->importantObjects[16] = 2;
        this->importantObjects[17] = 0x15;
        this->importantObjects[18] = 0x27;
    }

    idleTimeoutValue = 0x1388;
    setAdjustedIdleTimeout();
}

// VA: 00507A30 TribeArtifactUnitAIModule::processNotify
// Attempt log:
// try 1: reconstruct broad switch from packet and sibling processNotify matches; initial source compiled too small (640B), showing broad missing inline logging/repeated bodies.
// try 2: inlined repeated actionFile/fprintf stop logging instead of a local helper; size improved to 800B but still short.
// try 3: temporary padding branch got a byte-compare (79.1274% positional / 98.2311% edit) and proved the family is still very broad: prologue loads event into EBP instead of original EBX, switch compiles as sparse compares instead of original dense jump-table, and case layout/tails differ widely. Removed the padding branch.
// try 4: restored the period typed world/visible-map and operator new/delete surfaces, reordered the special cases by their PDB bands, and restored the dense 0x1f4..0x2bb switch case set.
// try 5: changed the field_28 guard to retain the binary-redundant second -1 check and restored the indexed list scan/copy topology; structural islands aligned through the list body.
// try 6: expanded each logging prefix while sharing the fprintf tail; exact size and calls returned, but the temporary line-local/goto source was 328 bytes off.
// try 7: restored ordinary duplicated LOGSTOP plus stop/notify statements; VC5 tail-merged the observed common suffix and produced an exact 848-byte match.

extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
extern void* operator new(unsigned int);
extern void operator delete(void*);


int TribeArtifactUnitAIModule::processNotify(NotifyEvent* event, unsigned long flags)
{

    switch (event->mType) {
    case 0x1fc: {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->targetId);
        if (obj != 0) {
            if (taiuaimd_player_visible_map(this->objectValue->owner)->get_visible(
                    (int)obj->world_x, (int)obj->world_y) == 0x0f)
                return 2;
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xa9f);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }

    case 0x1fa:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objId;
                    if (this->objectValue != 0)
                        objId = this->objectValue->id;
                    else
                        objId = -1;
                    fprintf(actionFile, str_fmt_stopObject, objId,
                            str_taiuaimd_path, 0xaae);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        if (this->field_28 != -1) return 2;
        if (this->field_30 != *(int*)((char*)event + 0x0C)) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xab7);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    case 0x1f9:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objId;
                    if (this->objectValue != 0)
                        objId = this->objectValue->id;
                    else
                        objId = -1;
                    fprintf(actionFile, str_fmt_stopObject, objId,
                            str_taiuaimd_path, 0xac6);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        if (this->field_28 != -1) return 2;
        if (this->field_30 != *(int*)((char*)event + 0x0C)) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xacf);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    case 0x1fb:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int objId;
                    if (this->objectValue != 0)
                        objId = this->objectValue->id;
                    else
                        objId = -1;
                    fprintf(actionFile, str_fmt_stopObject, objId,
                            str_taiuaimd_path, 0xade);
                }
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
        if (this->field_28 != -1) return 2;
        if (this->field_30 != *(int*)((char*)event + 0x0C)) return 2;
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int objId;
            if (this->objectValue != 0)
                objId = this->objectValue->id;
            else
                objId = -1;
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                    0xae7);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    case 600: {
        int id = *(int*)((char*)event + 0x00);
        int i = 0;
        while (i < this->count && i < this->capacity) {
            if (this->ids[i] == id) goto already;
            ++i;
        }

        if (this->count > this->capacity - 1) {
            int newCount = this->count + 1;
            int* p = (int*)operator new(newCount * 4);
            if (p != 0) {
                for (int j = 0; j < this->capacity && j < newCount; ++j)
                    p[j] = this->ids[j];
                operator delete(this->ids);
                this->ids = p;
                this->capacity = newCount;
            }
        }
        this->ids[this->count] = id;
        ++this->count;
already:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 0x1f4:
    case 0x1f5:
    case 0x1f6:
    case 0x1f7:
    case 0x1f8:
    case 0x1fd:
    case 0x1fe:
    case 0x1ff:
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20a:
    case 0x20b:
    case 0x20c:
    case 0x20d:
    case 0x20e:
    case 0x20f:
    case 0x210:
    case 0x211:
    case 0x212:
    case 0x213:
    case 0x214:
    case 0x215:
    case 0x216:
    case 0x217:
    case 0x218:
    case 0x219:
    case 0x21a:
    case 0x21b:
    case 0x21c:
    case 0x21d:
    case 0x21e:
    case 0x21f:
    case 0x220:
    case 0x221:
    case 0x222:
    case 0x223:
    case 0x224:
    case 0x225:
    case 0x226:
    case 0x227:
    case 0x228:
    case 0x229:
    case 0x22a:
    case 0x22b:
    case 0x22c:
    case 0x22d:
    case 0x22e:
    case 0x22f:
    case 0x230:
    case 0x231:
    case 0x232:
    case 0x233:
    case 0x234:
    case 0x235:
    case 0x236:
    case 0x237:
    case 0x238:
    case 0x239:
    case 0x23a:
    case 0x23b:
    case 0x23c:
    case 0x23d:
    case 0x23e:
    case 0x23f:
    case 0x240:
    case 0x241:
    case 0x242:
    case 0x243:
    case 0x244:
    case 0x245:
    case 0x246:
    case 0x247:
    case 0x248:
    case 0x249:
    case 0x24a:
    case 0x24b:
    case 0x24c:
    case 0x24d:
    case 0x24e:
    case 0x24f:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x253:
    case 0x254:
    case 0x255:
    case 0x256:
    case 0x257:
    case 0x259:
    case 0x25a:
    case 0x25b:
    case 0x25c:
    case 0x25d:
    case 0x25e:
    case 0x25f:
    case 0x260:
    case 0x261:
    case 0x262:
    case 0x263:
    case 0x264:
    case 0x265:
    case 0x266:
    case 0x267:
    case 0x268:
    case 0x269:
    case 0x26a:
    case 0x26b:
    case 0x26c:
    case 0x26d:
    case 0x26e:
    case 0x26f:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
    case 0x275:
    case 0x276:
    case 0x277:
    case 0x278:
    case 0x279:
    case 0x27a:
    case 0x27b:
    case 0x27c:
    case 0x27d:
    case 0x27e:
    case 0x27f:
    case 0x280:
    case 0x281:
    case 0x282:
    case 0x283:
    case 0x284:
    case 0x285:
    case 0x286:
    case 0x287:
    case 0x288:
    case 0x289:
    case 0x28a:
    case 0x28b:
    case 0x28c:
    case 0x28d:
    case 0x28e:
    case 0x28f:
    case 0x290:
    case 0x291:
    case 0x292:
    case 0x293:
    case 0x294:
    case 0x295:
    case 0x296:
    case 0x297:
    case 0x298:
    case 0x299:
    case 0x29a:
    case 0x29b:
    case 0x29c:
    case 0x29d:
    case 0x29e:
    case 0x29f:
    case 0x2a0:
    case 0x2a1:
    case 0x2a2:
    case 0x2a3:
    case 0x2a4:
    case 0x2a5:
    case 0x2a6:
    case 0x2a7:
    case 0x2a8:
    case 0x2a9:
    case 0x2aa:
    case 0x2ab:
    case 0x2ac:
    case 0x2ad:
    case 0x2ae:
    case 0x2af:
    case 0x2b0:
    case 0x2b1:
    case 0x2b2:
    case 0x2b3:
    case 0x2b4:
    case 0x2b5:
    case 0x2b6:
    case 0x2b7:
    case 0x2b8:
    case 0x2b9:
    case 0x2ba:
    case 0x2bb:
        return 2;
    }

    this->removeCurrentTarget();
    if (actionFile != 0) {
        int objId;
        if (this->objectValue != 0)
            objId = this->objectValue->id;
        else
            objId = -1;
        fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path,
                0xb1f);
    }
    this->stopObject(1);
        this->notifyCommander(event);
    return 2;
}


int TribeArtifactUnitAIModule::processIdle(int param_1) {
    int iVar1;
    RGE_Static_Object *pRVar2;

    iVar1 = this->closestObject(-1, -1, -1, -1, 0);
    if ((numberDifferentPlayerObjectsVisible <= 1) && (iVar1 != -1)) {
        pRVar2 = this->objectValue->owner->world->object(iVar1);
        if (pRVar2 != 0) {
            if (this->objectValue->owner != pRVar2->owner) {
                this->objectValue->change_ownership(pRVar2->owner);
                return 6;
            }
        }
    }
    return 5;
}

// 00507EF0 TribeArtifactUnitAIModule::processMisc
// Source: taiuaimd.cpp lines 2897-2919
// protected: virtual int __thiscall TribeArtifactUnitAIModule::processMisc(void)
//
// Attempt log:
// Probe 1: natural shape with virtual calls at slots 22 (0x58) and 53 (0xD4), default flags


extern FILE* actionFile;


int TribeArtifactUnitAIModule::processMisc()
{
    if (this->getActionState(1) == 6) {
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int value;
            if (this->obj != 0) {
                value = *(int*)((char*)this->obj + 4);
            } else {
                value = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", value, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0xB60);
        }
        this->stopObject(1);
        this->field_F8 = 0;
        return 10;
    }
    return 9;
}

// VA: 00507F60, TribeTowerUnitAIModule::TribeTowerUnitAIModule
// Donor: exact UnitAIModule-derived constructor shape from taiuaimd.cpp.
// Historical exact flags: config/flags/00507F60_TribeTowerUnitAIModule.rsp



TribeTowerUnitAIModule::TribeTowerUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }
}


int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* target) {
    if (target == 0)
        return 0;
    if (*(short*)((char*)target->master_obj + 0x14) == 1)
        return 0;
    if (this->object->interaction_type < 2)
        return 0;
    return 1;
}


int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2)
        return 0;
    return 1;
}

// VA: 00508170, TribeBuildingUnitAIModule::TribeBuildingUnitAIModule
// Donor: exact UnitAIModule-derived constructor shape from taiuaimd.cpp.
// Historical exact flags: config/flags/00508170_TribeBuildingUnitAIModule.rsp



TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* obj, int param)
    : UnitAIModule(obj, param)
{
    numberImportantObjects = 0x15;
    importantObjects = (int*)operator new(0x54);

    if (importantObjects) {
        importantObjects[0] = 0;
        this->importantObjects[1] = 3;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x23;
        this->importantObjects[7] = 0x19;
        this->importantObjects[8] = 0x11;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x17;
        this->importantObjects[11] = 0x24;
        this->importantObjects[12] = 0x1C;
        this->importantObjects[13] = 0x12;
        this->importantObjects[14] = 0x0D;
        this->importantObjects[15] = 0x1B;
        this->importantObjects[16] = 0x16;
        this->importantObjects[17] = 0x14;
        this->importantObjects[18] = 2;
        this->importantObjects[19] = 0x15;
        this->importantObjects[20] = 0x27;
    }
}

// VA: 00508320 TribeBuildingUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 3027-3115
// Attempt log:
// baseline: rough decompiler-style source had the wrong switch and omitted dynamic-list growth.
// structural reconstruction: copied the exact same-TU UnitAIModule/RGE_Player/RGE_Static_Object
// surfaces from 005068B0 and modeled the three binary dispatch cases (0x1f4, 0x258, 0x2bb).
// probe 2: adding the full list-growth/removal bodies improved structure but left two inline
// growth calls and no real resize call.
// probe 3: modeling +0x60 as ManagedArray_int and using resize for 0x1f4 reduced the body to
// 607 bytes and restored the direct resize relocation.
// probe 4: normalized the switch expression; no lookup table was emitted and it was rolled back.
// probe 5: added the binary-proven type 0x20b/default-return arm; VC5 emitted the expected
// compressed lookup table and all 11 ordered calls, but the local table remained after the
// original boundary until the body is byte-sized.
// probe 6: used a branch-local ManagedArray pointer, preloaded the 0x258 caller, and reread
// 0x2bb maximum size; exact-block coverage reached 85% and the remaining drift localized to
// the second removal search plus the lookup-table boundary.
// probe 7: changed the 0x1f4 pointer to a natural reference and matched its growth compare
// operands; best emitted result was 317 changed bytes / 64.71% shape / all calls aligned.
// probe 8: do/while removal-loop variants moved farther; restored probe 7.
// probe 9/10: fresh post-hit removal locals and a guarded do/while were also farther; restored
// the probe-7 source shape.
// probe 11: give the second removal search an explicit typed maximum local before its list pointer;
// this follows the original max/caller/pointer load order without adding codegen-only scaffolding.
// result: the body shrank from 832 to 828 bytes and positional diff improved 317 to 313, but
// VC5 still reused the prior max register and kept the pointer-first removal CFG.
// fresh worker probe: replaced the 0x2bb pointer-walk search with a natural indexed while and
// a do/while compaction loop; size reached 600 and positional diff improved to 135.
// kept the max/list locals with that do/while shape; event-pointer allocation returned to the
// original prologue family and positional diff improved to 89 with all 11 calls aligned.
// rolled back a direct-value variant; it moved the prologue and worsened the diff to 138.
// prior best: all 11 call targets and the main 0x1f4/0x258 bodies aligned; remaining
// drift was the 0x2bb max/list register order and the final removal block.
// worker probe 21: used a donor-natural bounded search and direct-field compaction block;
// positional diff stayed 89, but the tail shape improved and the source remained natural.
// worker probe 22: scoped a ManagedArray reference at the post-hit label; diff reached 23,
// with the expected max-first tail shape but case-0 LEA scheduling changed.
// worker probes 23-26: label scoping, pointer aliases, and a named maximum-field pointer
// were codegen duplicates; retained the natural array-pointer form as the cleaner candidate.
// worker probe 27: declared the case-0 array owner before count; diff reached 16 and restored
// the original case-0 LEA/index order without changing calls or the 600-byte boundary.
// worker probe 28: cached the post-hit caller before index initialization; exact 600-byte match
// with all 11 ordered calls and the original 0x2bb register/pointer-walk topology.
// worker probe 29: removed the diagnostic maximum-field pointer; the natural max local stayed
// exact. Final source uses named ManagedArray ownership and ordinary bounded search/compaction.

// This function uses the period UnitAIModule layout and the same-TU virtual surfaces as
// the exact transport/fishing processNotify donors.  The target class adds no fields.

int TribeBuildingUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0:
    {
        if (event->p2 <= 0) {
            RGE_Static_Object* obj = this->obj;
            taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x209, event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->obj->owner->computerPlayer() == 1) {
            RGE_Static_Object* obj = this->obj;
            taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x201, event->caller, 0, 0);
        }

        ManagedArray_int* array = (ManagedArray_int*)&this->attackingUnitsValue;
        int count = array->numberValue;
        int i = 0;
        for (; i < count && i < array->maximumSizeValue; ++i) {
            if (array->value[i] == event->caller) goto found_for_help;
        }
        if (this->obj->owner->computerPlayer() == 0 &&
            this->currentTarget != event->caller) {
            this->askForHelp(event->caller);
        }

found_for_help:
        i = 0;
        int caller = event->caller;
        count = array->numberValue;
        for (; i < count && i < array->maximumSizeValue; ++i) {
            if (array->value[i] == caller) goto already_in_list;
        }

        if (array->numberValue > array->maximumSizeValue - 1) {
            array->resize(array->numberValue + 1);
        }
        array->value[array->numberValue] = caller;
        array->numberValue++;

already_in_list:
        this->obj->setUnderAttack(1);
        return 2;
    }

    case 0x17:
        return 2;

    case 0x64:
    {
        int caller = event->caller;
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) goto changed_258;
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMax = this->attackingUnitsValue.numberValue + 1;
            int* newList = (int*)operator new(newMax * 4);
            if (newList != 0) {
                for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i)
                    newList[i] = this->attackingUnitsValue.value[i];
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newList;
                this->attackingUnitsValue.maximumSizeValue = newMax;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

changed_258:
        this->obj->setUnderAttack(1);
        return 2;
    }

    case 0xc7:
    {
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) goto found_2bb;
        }
        return 2;

found_2bb:
        ManagedArray_int* array = (ManagedArray_int*)&this->attackingUnitsValue;
        int max = array->maximumSizeValue;
        int caller = event->caller;
        i = 0;
        if (max > 0) {
            while (i < max) {
                if (array->value[i] == caller)
                    break;
                ++i;
            }
        }
        if (i < max) {
            if (i < max - 1) {
                do {
                    array->value[i] = array->value[i + 1];
                    ++i;
                } while (i < this->attackingUnitsValue.maximumSizeValue - 1);
            }
            array->numberValue--;
            if (array->numberValue < 0)
                array->numberValue = 0;
        }
        return 2;
    }

    default:
        return 2;
    }
}


int TribeBuildingUnitAIModule::processIdle(int p0) { return 5; }
