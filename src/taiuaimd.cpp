// Generated destructor and vtable entries are emitted by the compiler.
#include "../include/taiuaimd.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../include/game_globals.h"

// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// cache importantObjects[0], reload this->importantObjects for later source lines.


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

// int __thiscall processNotify(NotifyEvent* param_1, ulong param_2)
// ret 8 (2 params)
//
//   the arithmetic dispatch lowered to cmp/jne and was four bytes too large.
// - A switch on mType reproduced the original subtract/je dispatch and shared tail.
// - The two notification calls are one-argument thiscall virtuals at +0xEC/+0xA4;
//   typed slot surfaces removed the incorrect extra fastcall register setup.
// - UnitAIModule owns the base vptr, so the derived subobject starts at +0x04;
//   removing the duplicate gap restored all proven array offsets and exact bytes.
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

// Size: 229 bytes
// NC: no custom flags (default /O2 /Oy)
//
//
// VC5 emits the binary's fchs/fadd tails instead of fsubr.
//
// - Nested-if (if (targetID != -1) { ...; return 6; } return 5;) reproduces the
//   original control flow EXACTLY: je near to a shared return-5 tail, return-6
//   epilogue with mov eax,6 first (135 diff, shape 84.5%) — BUT VC5 then scrambles
//   the FPU schedule (stores `speed` to [esp+14] early, computes SPEED_3 late,
// - This parked if/else + result-local form instead produces a byte-perfect FPU
//   block (only fsubr vs fchs+fadd at the tail differs) but jne-inline control
//   flow (190 diff). So control-flow structure changes VC5's whole-function FPU
//   register scheduling; the FPU scramble is NOT fixable by negation spelling or
//   call, matching original, but still scramble FPU and add bytes).
// - Next lead: sweep FPU local shapes (hoisted s3/len locals, inline-vs-named
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
// - Recovered the natural typed virtual surfaces: closestObject at slot 0x10,
//   evasiveMoveTo at 0x27, and RGE_Static_Object::maximumSpeed at 0x3F. The
//   maximumSpeed call then uses the original ecx/edx register topology.
// - The canonical evasiveMoveTo world-z argument is float. Its ABI passes the
//   same raw dword bits observed at the call site without conversion; restoring
// - Binding the scale to the return (`speed = objectValue->maximumSpeed() *
//   SPEED_3`) reproduces the original 229-byte size and the whole FPU block
//   through the two normalized multiplications (best: 52-byte strict diff,
// - Separate offset/negation locals emitted an extra stack store (62-byte
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

//
// Key findings:
// - Virtual ~UnitAIModule() needed to trigger constructor EH frame
// - importantObjects[0] uses cached pointer; this->importantObjects[i] for i>=1
//   forces per-index reload from [esi+124h] with edx/eax/ecx register cycling


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



int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 1; }

//


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
        this->notifyCommander(event);
    }

    return UnitAIModule::processNotify(event, param_2);
}


TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}

// pattern differ slightly. All behavior identical.
//
// 1. Register swap: original keeps caller in ebp, count in ecx. My compiler
//    reverses this (caller in ecx saved to stack, count in ebp). This adds 4 bytes
//    for the stack save (`mov [esp+18h], ecx`).
//    different instruction scheduling (same structure, different registers).
// 3. The original uses `jg short` for p2 check (body=jump target, purge=fallthrough);
//    this layout is achieved with `if (event->p2 <= 0)` in the switch.
//
// What matches (first 90 bytes): prologue, switch dispatch (sub/je chain), default
// parent call, return-2 path, p2 check (jg short), purge/return-4 path.
// Also matches: search loop structure (scaled-index access, capacity reload per
// iteration), store-to-array, virtual call sequence, and epilogues.
//
// - v1: if-else chaining → cmp not sub for dispatch, wrong NotifyEvent layout
// - v2: switch dispatch, fixed NotifyEvent layout (p2 at +0x10), loop structure off
// - v4: attempted raw-offset hacks (failed)
// - v5-v6: refined loop structure
// - v9: goto-based layout attempt


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
            int count = this->attackingUnitsValue.numberValue;
            int i = 0;
            if (count > 0) {
                goto loop_check;
                do {
                    if (i >= this->attackingUnitsValue.maximumSizeValue)
                        goto after_loop;
                    if (this->attackingUnitsValue.value[i] == caller)
                        goto found;
                    i++;
loop_check:;
                } while (i < count);
after_loop:;
            }

            if (count >= this->attackingUnitsValue.maximumSizeValue) {
                int newCapacity = count + 1;
                int* newArray = (int*)operator_new(newCapacity * 4);
                if (newArray != 0) {
                    int j = 0;
                    if (count > 0) {
                        while (j < newCapacity && j < count) {
                            newArray[j] = this->attackingUnitsValue.value[j];
                            j++;
                        }
                    }
                    operator_delete(this->attackingUnitsValue.value);
                    this->attackingUnitsValue.value = newArray;
                    this->attackingUnitsValue.maximumSizeValue = newCapacity;
                }
            }
            this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
            this->attackingUnitsValue.numberValue++;
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


extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];


int TribeLionUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1FC:
    {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->currentTargetValue);
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
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x1AC);
        }
        this->stopObject(1);
        this->notifyCommander(event);
    }
    break;

    case 0x1FA:
        if (event->p1 != 0x258) {
            break;
        }
        if (rge_base_game->scenarioGame() == 1) {
            if (rge_base_game->singlePlayerGame() == 1) {
                this->idleTimeoutValue =
                    (this->objectValue->owner->world->difficultyLevel() + 3) * 5000;
            } else {
                this->idleTimeoutValue = 25000;
            }
        } else {
            this->idleTimeoutValue = 25000;
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

    int difficulty = objectValue->owner->world->difficultyLevel();

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
// - Direct `this->objectValue` access in vtable[4] arguments (no cached local) matches
//   original's `mov eax, [esi+4]` placement
// - `thisObj = this->objectValue` declared AFTER vtable[4] call matches original's
//   `mov edi, [esi+4]` placement
//
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
//
// - v1: __thiscall keyword issue, compilation failed (C4234)
//   returns instead of shared return-2 block
// - v3: fixed branch polarity with if/else structure → jne near to shared block.
//   Issue: fsubr instead of fchs+fadd (6 bytes short, 288 vs 294)
// - v5: removed thisObj local → worse (47.3%), compiler removed push ebp
// - v6: restored thisObj after vtable[4] call, separate nty/ntx vars → BEST:
//


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

// 5-8: combined guard, object id, same-TU UnitAIModule ABI, float coordinate fields, and natural new[]/delete[] growth restored exact call order and frame size.
// exact: direct member accesses preserve the original object/vptr reload schedule and produce all 643 bytes.

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
    if (ev->mType != 0x200) {
        return UnitAIModule::processNotify(ev, flags);
    }
    target = 0;
    if (this->currentActionValue != 0x258 ||
        (target = this->objectValue->owner->world->object(this->currentTargetValue)) == 0 ||
        target->getSpeed() == DAT_005758c4)
        return 2;

    this->order(this->objectValue->id, 0x2bc, this->currentTargetValue, -1,
                this->currentTargetXValue, this->currentTargetYValue,
                this->currentTargetZValue, this->desiredTargetDistanceValue,
                0, 1, this->currentOrderPriorityValue);

    evasiveMoveDistance = this->objectValue->maximumSpeed() *
                          this->objectValue->rateOfFire() * DAT_005758b0;
    dx = target->world_x - this->objectValue->world_x;
    dy = target->world_y - this->objectValue->world_y;

    if (this->attackingUnitsValue.numberValue > 0) {
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue) {
                if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                    int newCount = i + 1;
                    int* n = new int[newCount];
                    if (n) {
                        int j = 0;
                        if (this->attackingUnitsValue.maximumSizeValue > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    n[j-1] = this->attackingUnitsValue.value[j-1];
                                } else {
                                    break;
                                }
                            } while (j < this->attackingUnitsValue.maximumSizeValue);
                        }
                        delete[] this->attackingUnitsValue.value;
                        this->attackingUnitsValue.value = n;
                        this->attackingUnitsValue.maximumSizeValue = newCount;
                    }
                }
                if (this->attackingUnitsValue.value[i] != this->currentTargetValue) {
                    if (i > this->attackingUnitsValue.maximumSizeValue - 1) {
                        int newCount = i + 1;
                        int* n = new int[newCount];
                        if (n) {
                            int j = 0;
                            if (this->attackingUnitsValue.maximumSizeValue > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        n[j-1] = this->attackingUnitsValue.value[j-1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->attackingUnitsValue.maximumSizeValue);
                            }
                            delete[] this->attackingUnitsValue.value;
                            this->attackingUnitsValue.value = n;
                            this->attackingUnitsValue.maximumSizeValue = newCount;
                        }
                    }
                    RGE_Static_Object* obj2 = this->objectValue->owner->world->object(
                        this->attackingUnitsValue.value[i]);
                    if (obj2) {
                        dx += obj2->world_x - this->objectValue->world_x;
                        dy += obj2->world_y - this->objectValue->world_y;
                    }
                }
            ++i;
        }
    }

    len = (float)sqrt(dx*dx + dy*dy);
    this->evasiveMoveTo(this->objectValue->world_x + (-(dx / len * evasiveMoveDistance)),
                        this->objectValue->world_y + (-(dy / len * evasiveMoveDistance)),
                        this->objectValue->world_z, 1);
    return 3;
}

// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:
// cache importantObjects[0], reload this->importantObjects for later source lines.



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

//
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
    return obj->master_obj->object_group != 1;
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

// The original keeps event in EBX, uses indexed bounded list scans,
//   and places the owner-id-zero order arm before the enemy arm.
// The same-TU virtual surfaces and FILE/fprintf declarations preserve the proven calls.
//   raised shape from 76.74% to 87.18%; ordering the resource arm raised it to 87.83%.
// H27 still emits 74 bytes past the target boundary. Its ordered calls
//   remain -3/+3, with the 0x261 argument setup and one relocated cold tail unresolved.

typedef unsigned char uchar;
typedef unsigned long ulong;


int TribeCivilianUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0x1b:
        if (this->objectValue->owner->world->difficultyLevel() >= 3) {
            return 2;
        }
        // Intentional fall-through: 0x20f is the high-priority spelling of 0x1f4.
    case 0: {
        if (event->p2 <= 0) {
            this->objectValue->owner->notify(
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
                this->objectValue->owner->notify(
                    this->objectValue->id, this->objectValue->id, 0x201,
                    event->caller, 0, 0);
            }
        } else if (this->attackingUnitsValue.numberValue == 0) {
            this->objectValue->owner->notify(
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
        int state = this->objectValue->actionState();

        if (this->currentOrderValue == 0x2c6 && speed > 0.0f) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2bc) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2c9 && state == 0x0c &&
            targetObject != 0 && targetObject->master_obj->object_group == 10 &&
            eventObject->owner->id == 0) {
            goto return_two;
        }
        if (this->currentOrderValue == 0x2ce) {
            goto return_two;
        }

        if (eventObject->owner->id == 0) {
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
        if (this->currentActionValue == event->p1) {
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
        if (this->currentActionValue == event->p1) {
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
                this->objectValue->canPath(result, 1.0f, 0, 0, -1, -1) == 1 &&
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



TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2)
    : UnitAIModule(param_1, param_2)
{
    this->numberImportantObjects = 0x11;
    this->importantObjects = (int*)operator new(0x44);

    if (this->importantObjects) {
        importantObjects[0] = 3;
        this->importantObjects[1] = 0;
        this->importantObjects[2] = 4;
        this->importantObjects[3] = 0x1A;
        this->importantObjects[4] = 0x18;
        this->importantObjects[5] = 6;
        this->importantObjects[6] = 0x19;
        this->importantObjects[7] = 0x11;
        this->importantObjects[8] = 0x0A;
        this->importantObjects[9] = 0x0C;
        this->importantObjects[10] = 0x23;
        this->importantObjects[11] = 0x17;
        this->importantObjects[12] = 0x24;
        this->importantObjects[13] = 0x1C;
        this->importantObjects[14] = 0x12;
        this->importantObjects[15] = 0x0D;
        this->importantObjects[16] = 0x27;
    }
}

// Default flags
//
//
//   Original: mov edx,[esp+14h]; push edx; mov eax,[ecx]; call [eax+10Ch]
//   Rebuild:  mov eax,[esp+14h]; push eax; mov edx,[ecx]; call [edx+10Ch]
// This is a stable register-color difference in VC5's virtual-call scheduling.
// SpruceGlow tries 1-10: param_2 local/self-assign/mutate/cast, late object local, float local,
//   early-return/else/nested-positive control-flow forms, manual vtable attempt, and separate object
//   were much worse or failed to compile due VC5 __thiscall limitations.
// SpruceGlow tries 11-20: volatile param_2, long local, saved result, late object declaration,
// bytes in one virtual-call setup: rebuilt pushes param_2 through eax and loads/calls the
// vtable through edx, while original uses edx for the pushed arg and eax for vtable/call.
// Stack effects, call target slot (+0x10C), FPU result handling, branches, return values,
// size, and epilogues are byte-identical otherwise. No inline asm/hacks.


int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    if (this->canConvert(param_1) == 0) {
        if (this->currentOrderValue == -1) {
            if (this->objectValue->owner->computerPlayer() != 0) {
                return this->moveTo(param_1, this->objectValue->weaponRange(), param_2);
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
    if (this->objectValue->attribute_amount_held >= 100.0f) {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(id);
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

            if (og == 0x12 && this->objectValue->owner->attributes[0x1B] <= 0.0f) return 0;
            if (og == 3 && this->objectValue->owner->attributes[0x1C] <= 0.0f) return 0;

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

// 1: Natural nested loops over four ally buckets: compiles 432 vs 445, wrong prologue/self in EBX and wrong canSee vtable surface.
// 2: Switch canSee to +0x194 virtual and bucket offset loop: exact size but 91% diff; self in ESI, 0x28 frame, bad global/list shape.
// 3: Use pointer-to-current bucket globals: frame 0x20 but self still ESI and broad diff.
//    removing cached master/priority/offset locals; 445-byte output, 375 differing bytes.
// 11: Caching the current record-list pointer reached an exact 0x1c frame but
// 12: Reloading the record-list value per iteration also shortened the body;
// 13: Typed HealUnitRecord indexing and char* bucket offset were source-cleanup
//     small edit-distance gain; retained as canonical ownership.
// 15: Removed the unit_id temporary and reread the typed record ID at lookup and
//     canSee calls, matching the oracle reload order. Diff fell to 347 bytes and
// 19-28: Scalar-global overlays, parallel pointers, a typed aggregate, category
//     loop forms, direct table expressions, and wider object-pointer scope did
//     not recover the oracle's hidden table-base slot or register colors. The
//     or farther from the oracle. Restored the natural typed table source.
//     but kept the 0x18 frame and violated the no-byte-cursor source policy;
// 30: A cached typed record pointer shortened the body to 390 bytes and moved
//     the frame to 0x14; restored the pinned source.
//     order, do/while and for-header forms, and function-scope pointer aliases.
// 40: Replayed the prior 344-byte checkpoint. It had a 0x14 frame and only
//     126 instructions, so its smaller diff was not a natural improvement.
// 52: Volatile offset storage recovered the 0x1c frame but added six bytes and
//     32 changed spans. Restored the natural typed source.
//     differing bytes.
//     diagnostic diff to 344 bytes, but shortened the natural body to 429 bytes
//     and lost block shape; restored.
// 58-62: Full tactical member declarations and canonical object vtable names
// 63-67: Typed table-slot, count-slot, char-offset, and declaration-order
//     ownership; restored.
// 68-70: A live list-slot induction pointer recovered the 0x1c frame and more
// 71-72: A contiguous count/list table overlay shortened the body to 421 bytes
//     and changed global ownership; restored.
//     guard, nested do loop, early found-ID return, and final -1 return.
//     offset still stayed in a saved register and the frame stayed 0x18.
// 76-77: Added the binary-proven scalar table bases and byte-offset cursor.
//     duplicates; they did not recover the slot home or saved-register colors.
// 78-80: An index-derived slot pointer recovered the 0x1c frame and 91.85%
// most inner blocks, but VC5 keeps the table offset in EDI and object in ESI.
// The oracle keeps the table slot in ESI, object in EDI, and one extra frame slot.


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
        if (VisibleUnitList_Size[a - 1] > 0) {
            VISIBLE_UNIT_REC** listPtr = &VisibleUnitList[a - 1];
            do {
                if ((*listPtr)[i].object_id != this->objectValue->id) {
                    RGE_Static_Object* unit =
                        this->lookupObject((*listPtr)[i].object_id);
                    if (unit != 0) {
                        if (unit->master_obj->object_group != 3) {
                            if ((float)(int)unit->master_obj->hp > unit->hp) {
                                if (unit->object_state < 3) {
                                    if (param_1 != 0 ||
                                        (*listPtr)[i].distance <= 4) {
                                        if (this->objectValue->owner->id != 0 ||
                                            (*listPtr)[i].distance <= 2) {
                                            if (this->objectValue->canPath(
                                                    (*listPtr)[i].object_id,
                                                    1.0f, 0, 0, -1, -1)) {
                                                float need = (float)(int)unit->master_obj->hp -
                                                    unit->hp / (float)(int)(*listPtr)[i].distance;
                                                if (allyToHealID == -1 || need < allyNeed) {
                                                    allyNeed = need;
                                                    allyToHealID = unit->id;
                                                    if (param_2 != 0) {
                                                        *param_2 = (float)(int)(*listPtr)[i].distance;
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
            } while (i < VisibleUnitList_Size[a - 1]);
        }
        if (allyToHealID != -1) {
            break;
        }
    }

    return allyToHealID;
}

//
// int __thiscall TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
// - ret 4 cleanup (1 stack param + this in ecx)
//
// Returns: best unit ID (int), or -1 if none found
// param_1: optional output for priority value (can be NULL)
//
// 1: C-style function pointer virtual calls; RGE_Player class with virtual
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
// 5: Declared targetValue before the loop index, matching the original


typedef unsigned char uchar;


int TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
{
    this->search();

    int best_id = -1;
    float targetValue = 0.0f;
    int i = 0;

    if (VisibleUnitList_Size[3] > 0) {
        do {
            if (this->objectValue->owner->isEnemy(
                    (int)VisibleUnitList[3][i].player) != 0) {
                RGE_Static_Object* found = this->lookupObject(
                    VisibleUnitList[3][i].object_id);

                if (found != 0 && found->object_state < 3) {
                    if (this->canConvert(found->id) != 0) {
                        float priority =
                            (float)VisibleUnitList[3][i].distance;
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
        } while (i < VisibleUnitList_Size[3]);
    }

    return best_id;
}

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
        if (this->objectValue->owner->computerPlayer() == 0 && this->currentActionValue == 0x25c) {
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
        if (this->currentActionValue == 0x25c) {
            int id = this->bestUnitToConvert(0);
            if (id != -1 && this->convertObject(id, 1) == 1) {
                return 3;
            }
        } else if (this->currentActionValue == 0x25b) {
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
        RGE_Static_Object* obj = this->lookupObject(this->currentTargetValue);
        if (obj != 0) {
            if (this->visibleStatus(this->objectValue->owner->visible,
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

// 2: remove explicit object vtable field and wrap body in positive computerPlayer guard: shortened to 352 without local output.
// 3: restore 4-byte local output buffer: still 352.
// 4: return to early-return structure with corrected object offsets: exact object offsets but still sub esp,10; early fail inline.
// 6: positive computerPlayer/target guards shortened to 352.
// 7: explicit goto shared ret5 with top declarations shortened to 336, wrong family.
// 8: corrected the object slot +0x10C surface (the period method is weaponRange);
//    returned to best attempt-5 source family.
// 9: status local with `if (status != 6) { body } return 6` to try inline ret6 layout.
// 10: restored full same-TU UnitAIModule/RGE_Static_Object virtual surfaces,
//     335 differing bytes, with calls and frame aligned.
// 11: put the success/failure flow back into the original positive outer guard;
//     153 differing bytes and exact central block islands.
//     toward the original, 62 differing bytes.
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

    int range = VisibleUnitList_Size[3];
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

//



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

// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:



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

//   RGE_Player surfaces from exact taiuaimd.cpp siblings.  The notification
//   list and growth path follows the matching fishing/transport implementations;
//   trade retry uses the proven closestObject/tradeWithObject and
//   closestUndiscoveredTile/explore virtual slots.  The +0x1c callback in the
//   retry cleanup is UnitAIModule::notifyCommander(NotifyEvent*), not a
//   recursive processNotify call.
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
        obj->owner->notify(obj->id, obj->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x201, event->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == event->caller) {
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
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) {
            goto after_add;
        }
    }

    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = this->attackingUnitsValue.numberValue + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i) {
                newList[i] = this->attackingUnitsValue.value[i];
            }
            operator delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newList;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
    this->attackingUnitsValue.numberValue++;

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

//
// obtains the ship speed, and moves back toward the ship by seven speed
// units.  The object/player/world fields and the virtual calls are modeled at
// by the original x87 stack topology.
//
// - Typed virtual surfaces and nested success guards matched the frame, calls,
//   and all non-math control-flow structure.
// - Binding the seven-times-speed scale to the getter result reproduced the
// - The explicit float cast around each negated movement product is deliberate:
//   without it VC5 folds the operation into FPU FSUBR; with it the original
// object, and AI surfaces; emitted code remains exact.



int TribeTradeShipUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        int targetId = this->closestObject(-1, -1, -1, -1, 0);
        if (targetId != -1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            if (target != 0) {
                float speed = this->objectValue->maximumSpeed() * 7.0f;
                float xDiff = target->world_x - this->objectValue->world_x;
                float yDiff = target->world_y - this->objectValue->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                this->evasiveMoveTo(
                    (float)(-(xDiff / distance * speed)) + this->objectValue->world_x,
                    (float)(-(yDiff / distance * speed)) + this->objectValue->world_y,
                    this->objectValue->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}

// Reworked with the exact taiuaimd.cpp UnitAIModule constructor pattern:



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

// - v1: natural decompiler-shaped implementation with local structs/vtable pads.
// - v2: fixed notify caller offset to +0, p2 to +0x10 and base call signature with ulong.
// - v3/v4: changed mType dispatch to subtract chain; v4 uses `t != 0 && t != 0x1b`.
// - v6: modeled RGE_Static_Object::action_list as pointer at +0x184, fixing final have_action/get_action surface.
// - v7: switch for mType dispatch emits original sub/sub chain exactly.
// - v8: introduced count locals for scan loops to try to get count in ecx and max in edx like original.
// - v9: swapped count/i declaration order; no register change.
//   ebx=list, ebp/edi=caller; rebuilt uses edx=count, ebp=max and pointer-walk/add forms, cascading into
//   allocation-copy registers (newMax/newList/caller) despite matching call set, stack cleanup, and final action-list surface.
// - v11: restored the exact same-TU UnitAIModule, RGE_Player, RGE_Static_Object,
//   and action-list virtual/direct surfaces; indexed scan and copy topology were
//   structurally aligned, but redundant bound guards remained.
// - v13: removed the outer positive count wrappers; size reached 444 and the
// - v14: expressed both scans as natural combined `i < count && i < helpMax`


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
        RGE_Static_Object* o = this->objectValue;
        o->owner->notify(o->id, o->id, 0x209, event->caller, 0, 0);
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 ||
        this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* o = this->objectValue;
        o->owner->notify(o->id, o->id, 0x201, event->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == event->caller) goto found_for_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != event->caller) {
        this->askForHelp(event->caller);
    }

found_for_help:
    i = 0;
    int caller = event->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) goto already_in_list;
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

already_in_list:
    this->objectValue->setUnderAttack(1);
    if (this->currentOrderValue != -1) {
        return 2;
    }

    RGE_Action_Object* obj2 = (RGE_Action_Object*)this->objectValue;
    if (!obj2->actions->have_action() || obj2->actions->get_action()->state == 2) {
        this->runAwayFromAttackers(1);
    }
    return 3;
}

// int __thiscall processIdle(int param_1)
//
// The final explicit float cast preserves the original VC5 fchs/fadd movement lowering.
//
// Attempts:
// 1. __fastcall vtable shims and early returns produced an extra edx setup and wrong tails.
// 3. Materializing getSpeed()*7 before dx/dy fixed the original FPU evaluation order.
// 4-7. Equivalent movement spellings either emitted fsubr or spilled intermediates.
// slots throughout the world/object/AI surface; emitted code remains exact.



int TribeTransportShipUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        int targetId = closestObject(-1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);

            if (target != 0) {
                float speed = this->objectValue->maximumSpeed() * 7.0f;

                float dx = target->world_x - this->objectValue->world_x;
                float dy = target->world_y - this->objectValue->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);

                float move_x = (float)(-((dx / dist) * speed)) + this->objectValue->world_x;
                float move_y = (float)(-((dy / dist) * speed)) + this->objectValue->world_y;

                evasiveMoveTo(move_x, move_y, this->objectValue->world_z, 1);

                return 6;
            }
        }
    }

    return 5;
}

// Size: 207 bytes
//
//
// Key findings:
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

// 2: add register event alias and use it throughout to try EDI allocation; no register change.
// 6: remove event alias and use parameter directly to test whether alias caused EBP cache; no change.
// 8: reviewed late stopObject/vf58/vfA4 surface: current manual vtbl field is behaviorally suspect for ECX=this scheduling, but changing to full virtual class would require reworking all field offsets.



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
        obj->owner->notify(obj->id, obj->id, 0x209, ev->caller, 0, 0);
        this->purgeNotifyQueue(flags);
        return 4;
    }

    if (this->attackingUnitsValue.numberValue == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
        obj->owner->notify(obj->id, obj->id, 0x201, ev->caller, 0, 0);
    }

    int count = this->attackingUnitsValue.numberValue;
    int i = 0;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == ev->caller) goto skip_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != ev->caller) {
        this->askForHelp(ev->caller);
    }

skip_help:
    i = 0;
    int caller = ev->caller;
    count = this->attackingUnitsValue.numberValue;
    for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
        if (this->attackingUnitsValue.value[i] == caller) goto after_add;
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

// __thiscall: ecx=this, one stack parameter, ret 4
//
// The parked predecessor used raw function-pointer calls and got cdecl/fastcall
// stack plumbing instead of the observed virtual thiscall calls.  This candidate
// restores the natural UnitAIModule and RGE_Static_Object virtual surfaces, named
// coordinate locals, and the direct period-style movement expression.
// structure aligned.
// Separate speed/factor locals moved the x87 schedule and widened the function;
// the scaled return local is retained.
// Binary-required arithmetic spelling: `0.0f - offset` preserves the original
// fchs/fadd tail, while unary minus or direct subtraction lowers to fsubr.  The
// simple zero-minus form is retained because it is the only exact natural form
// found and matches the observed arithmetic topology.
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

                evasiveMoveTo((0.0f - ((xDiff / distance) * speed)) + objectValue->world_x,
                              (0.0f - ((yDiff / distance) * speed)) + objectValue->world_y,
                              objectValue->world_z, 1);
                return 6;
            }
        }
    }

    return 5;
}



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



int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->master_obj->object_group != 1;
}



int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2 || value == 0x14)
        return 0;
    return 1;
}

// 2: Modeled NotifyEvent type split for 0x20F evasive-move and 0x200 chase/retreat paths, with base processNotify fallback.
// 4: Added debug_rand jitter and FPU-ish random coordinate adjustment logic for both X/Y evasive targets.
// 5: Added rangeLeft/distance_to_object check, target vector accumulation, dynamic id-list growth/copy/delete pattern, and normalized retreat move.
// 12: Rebuilt the canonical taiuaimd class surfaces: switched to the original 0x200/0x20F dispatch order, typed owner/master/world access, UnitAIModule::order/intelligentEvasiveMoveTo, weaponRange, and the inline ManagedArray indexer.
// 14: Scoping jitter locals, splitting modulo into a temporary, adding stdio context, and reusing the jitter local for the range delta did not improve emitted code; reverted.
// 22: Swapped the switch arm order; emitted code was identical to the clean 855-byte candidate; reverted.
// result is 1078 bytes, 0x8 frame, 93.75% shape, and 639 strict-diff bytes.
// Parenthesized random-coordinate arithmetic and the inverted >10 branch recover
// block: the rebuilt guards use short branches to an early call site.
// Compiler-neutral goto and local-order reductions were removed from the pinned source.
// Canonical taiuaimd context restores the protected virtual MAE owner symbol.
//
// - The exact transition uses positive ordered guards for the 0x200 path.
// - Shared return_two and return_base labels keep the cold paths late.
// - The negative 0x200 guard form kept size and calls but changed four bytes
//   in the private return block. Keep the positive guard form.
//
// fallback rereads both message arguments at the late call.
// the 0x20F success path publishes taskedThisUpdate only after
// intelligentEvasiveMoveTo succeeds. Keep this order and these fault boundaries.


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
        taskedThisUpdate = 1;
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

//
// object/master surface and omitted the maximum-speed result in the final
// movement calculation.  The current candidate restores the period
// UnitAIModule/RGE object surfaces and the duplicated strategic-number gate
//
// Prior evidence retained from the parked attempt:
// - the target is normal corpus work and uses the default VC5 /O2 /Oy flags;
// - all 16 calls, shared return-5 tail, and the +0xFC/+0x9C virtual slots are
//   binary-proven;
// - the final movement uses object maximumSpeed() multiplied by [5758B0h]
//   (3.0f), then normalized x/y deltas and evasiveMoveTo(..., world_z, 1).
// function is used.
//
// - The real object, player, master, and UnitAIModule surfaces are required.
// - Collapsing the duplicated strategic-number gate removed 3 calls and 56
//   bytes. It also changed the first direct call, so the shipped gate stays.
// - Removing the explicit sqrt float cast kept the exact result. The reduced
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
        if (this->currentOrderValue != 0x2D5 ||
            (this->objectValue->master_obj->id != 0x23 &&
             this->objectValue->master_obj->id != 0x24 &&
             this->objectValue->master_obj->id != 0xFA)) {
            int targetID = this->bestUnitToAttack(1, 0, 0);
            if (targetID != -1 && this->attackObject(targetID, 1) == 1) {
                return 6;
            }

            if (this->objectValue->owner->computerPlayer() != 0 &&
                this->objectValue->inGroup() != 1) {
                this->objectValue->owner->world->difficultyLevel();

                if ((rge_base_game->scenarioGame() == 1 &&
                     rge_base_game->singlePlayerGame() == 1 &&
                     this->objectValue->owner->strategicNumber(0x8F) == 0) ||
                    (rge_base_game->singlePlayerGame() == 1 &&
                     this->objectValue->owner->strategicNumber(0x8F) == 0)) {
                    return 5;
                }

                if (this->currentOrderValue != 0x2BD &&
                    this->currentOrderValue != 0x2D5) {
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


extern FILE* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
int TribeArtifactUnitAIModule::processNotify(NotifyEvent* event, unsigned long flags)
{

    switch (event->mType) {
    case 0x1fc: {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->currentTargetValue);
        if (obj != 0) {
            if (this->objectValue->owner->visible->get_visible(
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
        if (this->currentOrderValue != -1) {
            if (this->currentActionValue + 0x64 == this->currentOrderValue) {
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
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != event->p1) return 2;
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
        if (this->currentOrderValue != -1) {
            if (this->currentActionValue + 0x64 == this->currentOrderValue) {
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
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != event->p1) return 2;
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
        if (this->currentOrderValue != -1) {
            if (this->currentActionValue + 0x64 == this->currentOrderValue) {
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
        if (this->currentOrderValue != -1) return 2;
        if (this->currentActionValue != event->p1) return 2;
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
        int id = event->caller;
        int i = 0;
        while (i < this->attackingUnitsValue.numberValue &&
               i < this->attackingUnitsValue.maximumSizeValue) {
            if (this->attackingUnitsValue.value[i] == id) goto already;
            ++i;
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newCount = this->attackingUnitsValue.numberValue + 1;
            int* p = (int*)operator new(newCount * 4);
            if (p != 0) {
                for (int j = 0; j < this->attackingUnitsValue.maximumSizeValue && j < newCount; ++j)
                    p[j] = this->attackingUnitsValue.value[j];
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = p;
                this->attackingUnitsValue.maximumSizeValue = newCount;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = id;
        ++this->attackingUnitsValue.numberValue;
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

// protected: virtual int __thiscall TribeArtifactUnitAIModule::processMisc(void)
//


extern FILE* actionFile;


int TribeArtifactUnitAIModule::processMisc()
{
    if (this->processIdle(1) == 6) {
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int value;
            if (this->objectValue != 0) {
                value = this->objectValue->id;
            } else {
                value = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", value, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0xB60);
        }
        this->stopObject(1);
        this->idleTimerValue = 0;
        return 10;
    }
    return 9;
}




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
    if (target->master_obj->object_group == 1)
        return 0;
    if (this->objectValue->object_state < 2)
        return 0;
    return 1;
}


int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2)
        return 0;
    return 1;
}




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

// surfaces from 005068B0 and modeled the three binary dispatch cases (0x1f4, 0x258, 0x2bb).
// growth calls and no real resize call.
// 607 bytes and restored the direct resize relocation.
// compressed lookup table and all 11 ordered calls, but the local table remained after the
// original boundary until the body is byte-sized.
// the second removal search plus the lookup-table boundary.
// operands; best emitted result was 317 changed bytes / 64.71% shape / all calls aligned.
// VC5 still reused the prior max register and kept the pointer-first removal CFG.
// kept the max/list locals with that do/while shape; event-pointer allocation returned to the
// with the expected max-first tail shape but case-0 LEA scheduling changed.
// the original case-0 LEA/index order without changing calls or the 600-byte boundary.
// with all 11 ordered calls and the original 0x2bb register/pointer-walk topology.

// This function uses the period UnitAIModule layout and the same-TU virtual surfaces as

int TribeBuildingUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0:
    {
        if (event->p2 <= 0) {
            RGE_Static_Object* obj = this->objectValue;
            obj->owner->notify(obj->id, obj->id, 0x209, event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->objectValue->owner->computerPlayer() == 1) {
            RGE_Static_Object* obj = this->objectValue;
            obj->owner->notify(obj->id, obj->id, 0x201, event->caller, 0, 0);
        }

        ManagedArray<int>* array = &this->attackingUnitsValue;
        int count = array->numberValue;
        int i = 0;
        for (; i < count && i < array->maximumSizeValue; ++i) {
            if (array->value[i] == event->caller) goto found_for_help;
        }
        if (this->objectValue->owner->computerPlayer() == 0 &&
            this->currentTargetValue != event->caller) {
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
        this->objectValue->setUnderAttack(1);
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
        this->objectValue->setUnderAttack(1);
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
        ManagedArray<int>* array = &this->attackingUnitsValue;
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
