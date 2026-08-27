#include "../include/aiuaimod.h"
#include "../include/game_globals.h"
#include "../include/rge_base_game_global.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- matching/00412F00_UnitAIModule.cpp ---
// VA: 00412F00 UnitAIModule ctor (356B)
// aiuaimod.cpp
// EH frame (/GX)

//
// Attempt log:
// - The first isolated typed candidate had the right four calls and layout but
//   no EH frame. Correcting setAdjustedIdleTimeout to its proven thiscall
//   member ABI removed the spurious caller push/cleanup.
// - Modeling the proven ManagedArray<int> member with its inline scalar-delete
//   destructor restored the original EH frame, 356-byte size, phase local,
//   delayed vptr position, call-site cleanup, and exact 34-instruction tail.
// - The current natural source uses the binary-proven novtable/delayed-vptr
//   surface, scalar initializer list, real managed-array destructor, and
//   standard new/member-call ABIs. Current best: 356/356 bytes, 4/4 ordered
//   calls, 95.83% shape, 88 positional differing bytes; the tail from
//   +0xF4 through +0x164 is exact.
// - Tried natural compiler-owned vptr, a declaration-only member destructor,
//   a local allocation result, register-qualified obj, and the template
//   spelling; none changed the remaining hunk. Original pushes EDI and loads
//   obj before MOV ESI,this, saves this only before the first allocation, and
//   keeps push 0x28 after the +0x38..+0x5C stores. VC5 currently moves MOV
//   ESI,this/EH-local save ahead of PUSH EDI and hoists that argument push.
// - Added the full UnitAIModule virtual ABI and typed OrderEvent/NotifyEvent
//   queue surfaces; the emitted constructor stayed identical.
// - Replaced proven waypoint padding with the typed Waypoint array and last
//   position aggregate, then typed both queue pointers; both probes stayed
//   identical. An empty ManagedArray default constructor also had no effect.
// - Split initializer-list prefixes, a natural zeroing member constructor,
//   new int[10], and the likely standard-header pair. The split lab found no
//   exact source; new int[10] and headers emitted the same 88-byte result.
// - Pausing with the best source: remaining drift is the constructor's first
//   block liveness/EH scheduling. Calls, layout, size, and tail are aligned.
//   No inline asm or compiler-only filler used.
// - Recovered the missing source shape: attackingUnitsValue is constructed
//   with capacity 10 in the initializer list. Its natural member constructor
//   zeroes the scalar fields and allocates the initial int storage. This
//   reproduces the original member-construction EH schedule and MATCHes all
//   356 bytes. The scalar delete is retained from the exact array destructor
//   donor, including the original allocation/deallocation mismatch.


void* __cdecl operator new(unsigned int size);

UnitAIModule::UnitAIModule(RGE_Static_Object* obj, int maxQueueSize)
    : objectValue(obj),
      moodValue(-1),
      objectCategoryValue(-1),
      orderQueueSizeValue(0),
      orderQueueMaxSizeValue(maxQueueSize),
      notifyQueueSizeValue(0),
      notifyQueueMaxSizeValue(maxQueueSize),
      currentOrderValue(-1),
      currentOrderPriorityValue(-1),
      currentActionValue(-1),
      currentTargetValue(-1),
      currentTargetTypeValue(-1),
      currentTargetXValue(-1.0f),
      currentTargetYValue(-1.0f),
      currentTargetZValue(-1.0f),
      desiredTargetDistanceValue(2.0f),
      defendTargetValue(-1),
      lastOrderValue(-1),
      lastActionValue(-1),
      lastTargetValue(-1),
      lastTargetTypeValue(-1),
      attackingUnitsValue(10) {

    waypointQueueSizeValue = 0;
    lastUpdateTimeValue = 0;
    idleTimerValue = 0;
    idleTimeoutValue = 3000;
    secondaryTimerValue = 0;
    lookAroundTimerValue = 0;
    lookAroundTimeoutValue = 1000;
    defenseBufferValue = 1.0f;
    importantObjects = 0;
    numberImportantObjects = 0;
    playStatus = 0;
    stopAfterTargetKilledValue = 0;

    *(void**)this = (void*)0x56EAD8;

    if (obj != 0) {
        objectCategoryValue = obj->master_obj->object_category;
        defenseBufferValue = obj->master_obj->defense_buffer;
    }

    orderQueueValue = (OrderEvent*)operator new(orderQueueMaxSizeValue * 0x24);
    notifyQueueValue = (NotifyEvent*)operator new(notifyQueueMaxSizeValue * 0x18);

    lastWorldPositionX = -1.0f;
    lastWorldPositionY = -1.0f;
    lastWorldPositionZ = -1.0f;

    setAdjustedIdleTimeout();
}

// --- matching/00413090_UnitAIModule.cpp ---
// VA: 00413090 ~UnitAIModule dtor (183B)
// aiuaimod.cpp
// EH frame (/GX)


UnitAIModule::~UnitAIModule() {
    // BINARY NOTE: the constructor uses delayed novtable publication. The
    // executable restores the base vptr before it reads the first owned queue.
    OrderEvent* queue;
    if ((*(void* volatile*)this = (void*)0x56EAD8,
         queue = *(OrderEvent* volatile*)&orderQueueValue)) {
        delete queue;
        orderQueueValue = 0;
    }
    if (notifyQueueValue) {
        delete notifyQueueValue;
        notifyQueueValue = 0;
    }
    if (importantObjects) {
        delete importantObjects;
        importantObjects = 0;
    }
    if (playStatus) {
        delete playStatus;
        playStatus = 0;
    }
}

// --- accepted_drift/00413150_save.cpp ---
// VA: 00413150 save (758B)
// aiuaimod.cpp
// ACCEPTED_DRIFT: 30-byte diff (3.96%) entirely benign register allocation
// in the attackingUnits grow-array loop (EBP vs EBX register choice).
// Logic, call set, stack cleanup, and memory effects are identical.
// 536-byte identical prefix before the first diff at offset 536.
// Function size matches exactly (758 bytes).


void __cdecl rge_write(int fd, const void* data, int size);

void UnitAIModule::save(int fd) {
    int i;
    int temp;
    int num;
    int* ptr;
    int cnt;
    int* newArr;
    int j;

    rge_write(fd, &moodValue, 4);
    rge_write(fd, &currentOrderValue, 4);
    rge_write(fd, &currentOrderPriorityValue, 4);
    rge_write(fd, &currentActionValue, 4);
    rge_write(fd, &currentTargetValue, 4);
    rge_write(fd, &currentTargetTypeValue, 4);
    rge_write(fd, &currentTargetXValue, 4);
    rge_write(fd, &currentTargetYValue, 4);
    rge_write(fd, &currentTargetZValue, 4);
    rge_write(fd, &desiredTargetDistanceValue, 4);
    rge_write(fd, &lastActionValue, 4);
    rge_write(fd, &lastOrderValue, 4);
    rge_write(fd, &lastTargetValue, 4);
    rge_write(fd, &lastTargetTypeValue, 4);
    rge_write(fd, &lastUpdateTimeValue, 4);
    rge_write(fd, &idleTimerValue, 4);
    rge_write(fd, &idleTimeoutValue, 4);
    rge_write(fd, &adjustedIdleTimeoutValue, 4);
    rge_write(fd, &secondaryTimerValue, 4);
    rge_write(fd, &lookAroundTimerValue, 4);
    rge_write(fd, &lookAroundTimeoutValue, 4);
    rge_write(fd, &defendTargetValue, 4);
    rge_write(fd, &defenseBufferValue, 4);
    rge_write(fd, &lastWorldPositionX, 16);

    rge_write(fd, &orderQueueSizeValue, 4);
    for (i = 0; i < orderQueueSizeValue; i++) {
        rge_write(fd, (char*)orderQueueValue + i * 0x24, 0x24);
    }

    rge_write(fd, &notifyQueueSizeValue, 4);
    for (i = 0; i < notifyQueueSizeValue; i++) {
        rge_write(fd, (char*)notifyQueueValue + i * 0x18, 0x18);
    }

    temp = attackingUnitsValue.numberValue;
    rge_write(fd, &temp, 4);
    {
        int i_attack;
        for (i_attack = 0; i_attack < attackingUnitsValue.numberValue; i_attack++) {
            if (attackingUnitsValue.maximumSizeValue - 1 < i_attack) {
                int* newArr = (int*)::operator new(i_attack * 4 + 4);
                if (newArr) {
                    int j;
                    for (j = 0; j < attackingUnitsValue.maximumSizeValue; j++) {
                        if (i_attack + 1 <= j) break;
                        newArr[j] = attackingUnitsValue.value[j];
                    }
                    ::operator delete(attackingUnitsValue.value);
                    attackingUnitsValue.value = newArr;
                    attackingUnitsValue.maximumSizeValue = i_attack + 1;
                }
            }
            temp = attackingUnitsValue.value[i_attack];
            rge_write(fd, &temp, 4);
        }
    }

    if (playStatus == 0) {
        temp = 0;
        rge_write(fd, &temp, 4);
    } else {
        temp = 1;
        rge_write(fd, &temp, 4);
        playStatus->save(fd);
    }

    rge_write(fd, (char*)this + 0x130, 1);
}

// --- matching/00413450_load.cpp ---
// VA: 00413450 load (949B)
// aiuaimod.cpp
// EH frame (/GX) — same as ctor/dtor: VC5 only generates with full TU context
// Also has AIPlayStatus new/construct/load and dual version checks (6.93, 7.02)
// These require full TU context to match exactly.
// Attempt log:
// - Baseline: natural typed field/queue reconstruction was 59 bytes short,
//   frame 0x2C versus 0x3C, and missed the AIPlayStatus constructor call.
// - Added the binary-proven AIPlayStatus size/constructor surface and restored
//   the unconditional load after the new-expression; checking this as the
//   first structural hypothesis.
// - Separate serialized count locals, the recipient-offset event overlay, the
//   positive 6.93 version gate, and an indexed attacking-unit scan recovered
//   the original call order and block layout.
// - The local NotifyEvent payload gap is intentional: the 0x24-byte order
//   read starts at recipient and proves the larger stack window (frame 0x3C).
// - The equality edge is a binary-proven shared skip-add path. A direct
//   source label preserves that edge; replacing it with a found flag moved
//   the compiler into a broader, less faithful basin.
// - Best current check: 953 rebuilt bytes versus 949, exact frame 0x3C,
//   39/39 ordered calls, 97.29% exact-block coverage, and 44 edit cost.
//   Remaining drift starts in the inline attacking-array copy guard: VC5 emits
//   `test ebp/jle` for the current natural do/while shape while the oracle has
//   `cmp eax,ebp/jge`; the late suffix is otherwise an exact aligned island.
// - Pausing in scratch after the bounded 10 meaningful hypotheses; next lead
//   is a natural two-bound copy-loop spelling, not frame padding or volatility.
// - Replaced the grow-copy do/while with the same-TU matched ManagedArray
//   for-loop: a separate capacity guard and new-size guard reproduce the
//   binary's `cmp eax,ebp/jge` block and exact 949-byte function.
// - Exact candidate: frame, 39 ordered calls, CFG, boundary, and all 949 bytes
//   match under the existing /GX response file.


extern float save_game_version;

void __cdecl rge_read(int fd, void* data, int size);

struct LoadNotifyEvent : NotifyEvent {
    char loadPayloadGap[0x10];
};

void UnitAIModule::load(int fd) {
    int numberNotifies;
    int i;
    int iVar5;
    int numberUnits;
    int tempInt_ffffffc0;
    int local_3c;
    int tempInt;
    int j;
    LoadNotifyEvent tempNotify;

    rge_read(fd, &moodValue, 4);
    rge_read(fd, &currentOrderValue, 4);
    rge_read(fd, &currentOrderPriorityValue, 4);
    rge_read(fd, &currentActionValue, 4);
    rge_read(fd, &currentTargetValue, 4);
    rge_read(fd, &currentTargetTypeValue, 4);
    rge_read(fd, &currentTargetXValue, 4);
    rge_read(fd, &currentTargetYValue, 4);
    rge_read(fd, &currentTargetZValue, 4);
    rge_read(fd, &desiredTargetDistanceValue, 4);
    rge_read(fd, &lastActionValue, 4);
    rge_read(fd, &lastOrderValue, 4);
    rge_read(fd, &lastTargetValue, 4);
    rge_read(fd, &lastTargetTypeValue, 4);
    rge_read(fd, &lastUpdateTimeValue, 4);
    rge_read(fd, &idleTimerValue, 4);
    rge_read(fd, &idleTimeoutValue, 4);
    rge_read(fd, &adjustedIdleTimeoutValue, 4);
    rge_read(fd, &secondaryTimerValue, 4);

    if (save_game_version >= 6.93f) {
        rge_read(fd, &lookAroundTimerValue, 4);
        rge_read(fd, &lookAroundTimeoutValue, 4);
    } else {
        lookAroundTimerValue = 0;
        lookAroundTimeoutValue = 1000;
    }

    rge_read(fd, &defendTargetValue, 4);
    rge_read(fd, &defenseBufferValue, 4);
    rge_read(fd, &lastWorldPositionX, 16);

    // Read order queue
    rge_read(fd, &numberNotifies, 4);
    iVar5 = 0;
    if (numberNotifies > 0) {
        do {
            rge_read(fd, &tempNotify.recipient, 0x24);
            addToOrderQueue((OrderEvent*)&tempNotify.recipient, 0);
            ++iVar5;
        } while (iVar5 < numberNotifies);
    }

    // Read notify queue
    rge_read(fd, &i, 4);
    iVar5 = 0;
    if (i > 0) {
        do {
            rge_read(fd, &tempNotify.recipient, 0x18);
            addToNotifyQueue((NotifyEvent*)&tempNotify.recipient);
            ++iVar5;
        } while (iVar5 < i);
    }

    // Read attacking units
    rge_read(fd, &tempInt_ffffffc0, 4);
    numberUnits = 0;
    if (tempInt_ffffffc0 > 0) {
        do {
            rge_read(fd, &local_3c, 4);
            tempInt = local_3c;
            for (j = 0; j < attackingUnitsValue.numberValue; j++) {
                if (j >= attackingUnitsValue.maximumSizeValue) break;
                if (attackingUnitsValue.value[j] == local_3c)
                    goto attacking_unit_already_present;
            }

            if (attackingUnitsValue.numberValue > attackingUnitsValue.maximumSizeValue - 1) {
                int newSize = attackingUnitsValue.numberValue + 1;
                int* newArr = (int*)::operator new(newSize * 4);
                if (newArr != 0) {
                    j = 0;
                    for (j = 0; j < attackingUnitsValue.maximumSizeValue; j++) {
                        if (j >= newSize) break;
                        newArr[j] = attackingUnitsValue.value[j];
                    }
                    ::operator delete(attackingUnitsValue.value);
                    attackingUnitsValue.value = newArr;
                    attackingUnitsValue.maximumSizeValue = newSize;
                }
            }
            attackingUnitsValue.value[attackingUnitsValue.numberValue] = tempInt;
            attackingUnitsValue.numberValue = attackingUnitsValue.numberValue + 1;

attacking_unit_already_present:
            numberUnits = numberUnits + 1;
        } while (numberUnits < tempInt_ffffffc0);
    }

    // Read playStatus
    rge_read(fd, &tempNotify, 4);
    if (tempNotify.caller == 1) {
        playStatus = new AIPlayStatus();
        playStatus->load(fd);
    }

    // stopAfterTargetKilled added in version 7.02
    if (save_game_version >= 7.02f) {
        rge_read(fd, &stopAfterTargetKilledValue, 1);
    }
}

// --- matching/00413810_owner.cpp ---

RGE_Player* UnitAIModule::owner() const {
    return this->objectValue->owner;
}

// --- matching/00413820_object.cpp ---

RGE_Static_Object* UnitAIModule::object() const {
    return this->objectValue;
}

// --- matching/00413830_objectID.cpp ---

int UnitAIModule::objectID() const {
    return this->objectValue->id;
}

// --- matching/00413840_objectCategory.cpp ---

int UnitAIModule::objectCategory() const {
    return this->objectCategoryValue;
}

// --- matching/00413850_mood.cpp ---

int UnitAIModule::mood() const {
    return this->moodValue;
}

// --- matching/00413860_lastUpdateTime.cpp ---

unsigned long UnitAIModule::lastUpdateTime() const {
    return this->lastUpdateTimeValue;
}

// --- matching/00413870_idleTimer.cpp ---

unsigned long UnitAIModule::idleTimer() const {
    return this->idleTimerValue;
}

// --- matching/00413880_idleTimeout.cpp ---

unsigned long UnitAIModule::idleTimeout() const {
    return this->idleTimeoutValue;
}

// --- matching/00413890_secondaryTimer.cpp ---

unsigned long UnitAIModule::secondaryTimer() const {
    return this->secondaryTimerValue;
}

// --- matching/004138a0_defenseBuffer.cpp ---

float UnitAIModule::defenseBuffer() const {
    return this->defenseBufferValue;
}

// --- matching/004138c0_setDefenseBuffer.cpp ---

void UnitAIModule::setDefenseBuffer(float value) {
    this->defenseBufferValue = value;
}

// --- matching/004138d0_orderQueueSize.cpp ---

int UnitAIModule::orderQueueSize() const {
    return this->orderQueueSizeValue;
}

// --- matching/004138E0_orderQueueElement.cpp ---

OrderEvent* UnitAIModule::orderQueueElement(int index) const {
    if (index >= 0 && index < this->orderQueueSizeValue &&
        this->orderQueueValue != 0) {
        return this->orderQueueValue + index;
    }
    return 0;
}

// --- matching/00413910_purgeOrderQueue.cpp ---

void UnitAIModule::purgeOrderQueue() {
    this->orderQueueSizeValue = 0;
}

// --- matching/00413920_currentOrder.cpp ---

int UnitAIModule::currentOrder() const {
    return this->currentOrderValue;
}

// --- matching/00413930_setCurrentOrder.cpp ---

void UnitAIModule::setCurrentOrder(int value) {
    this->lastOrderValue = this->currentOrderValue;
    this->currentOrderValue = value;
}

// --- matching/00413940_currentOrderPriority.cpp ---

int UnitAIModule::currentOrderPriority() const {
    return this->currentOrderPriorityValue;
}

// --- matching/00413950_setCurrentOrderPriority.cpp ---

void UnitAIModule::setCurrentOrderPriority(int value) {
    this->currentOrderPriorityValue = value;
}

// --- matching/00413960_currentAction.cpp ---

int UnitAIModule::currentAction() const {
    return this->currentActionValue;
}

// --- matching/00413970_setCurrentAction.cpp ---

void UnitAIModule::setCurrentAction(int value) {
    this->lastActionValue = this->currentActionValue;
    this->currentActionValue = value;
}

// --- matching/00413980_currentTarget.cpp ---

int UnitAIModule::currentTarget() const {
    return this->currentTargetValue;
}

// --- matching/00413990_currentTargetType.cpp ---

int UnitAIModule::currentTargetType() const {
    return this->currentTargetTypeValue;
}

// --- matching/004139a0_currentTargetX.cpp ---

float UnitAIModule::currentTargetX() const {
    return this->currentTargetXValue;
}

// --- matching/004139b0_currentTargetY.cpp ---

float UnitAIModule::currentTargetY() const {
    return this->currentTargetYValue;
}

// --- matching/004139c0_currentTargetZ.cpp ---

float UnitAIModule::currentTargetZ() const {
    return this->currentTargetZValue;
}

// --- matching/004139d0_lastAction.cpp ---

int UnitAIModule::lastAction() const {
    return this->lastActionValue;
}

// --- matching/004139e0_lastOrder.cpp ---

int UnitAIModule::lastOrder() const {
    return this->lastOrderValue;
}

// --- matching/004139f0_lastTarget.cpp ---

int UnitAIModule::lastTarget() const {
    return this->lastTargetValue;
}

// --- matching/00413a00_lastTargetType.cpp ---

int UnitAIModule::lastTargetType() const {
    return this->lastTargetTypeValue;
}

// --- matching/00413a10_desiredTargetDistance.cpp ---

float UnitAIModule::desiredTargetDistance() const {
    return this->desiredTargetDistanceValue;
}

// --- matching/00413A20_attackingUnitID.cpp ---
// VA: 00413A20 UnitAIModule::attackingUnitID


int UnitAIModule::attackingUnitID(int index) {
    if (index < 0 || index >= this->attackingUnitsValue.numberValue) {
        return -1;
    }
    if (index > this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = index + 1;
        int* newValues = (int*)operator_new(newMax * 4);
        if (newValues != 0) {
            int oldMax = this->attackingUnitsValue.maximumSizeValue;
            int i = 0;
            if (oldMax > 0) {
                do {
                    if (i < newMax) {
                        i++;
                        int value = this->attackingUnitsValue.value[i - 1];
                        newValues[i - 1] = value;
                        oldMax = this->attackingUnitsValue.maximumSizeValue;
                    } else {
                        break;
                    }
                } while (i < oldMax);
            }
            operator_delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newValues;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    return this->attackingUnitsValue.value[index];
}

// --- matching/00413aa0_numberAttackingUnits.cpp ---

int UnitAIModule::numberAttackingUnits() const {
    return this->attackingUnitsValue.numberValue;
}

// --- scratch/00413AB0_update.cpp ---
// VA: 00413AB0 UnitAIModule::update (1372 bytes)
// aiuaimod.cpp:612-1069
// Typed period-plausible reconstruction of the main AI update tick.
//
// Attempt log:
// - Replaced the old raw-offset placeholder with the observed UnitAIModule,
//   RGE_Static_Object, action-list, and ManagedArray ownership surfaces.
// - Baseline follows the oracle's target cleanup, attacking-unit validation,
//   notify/order queue passes, idle timeout, and look-around tail.
// - Reordered the overloaded moveTo declarations so the four-float target
//   retry reaches vslot +0x90; inlined the object range expression and fixed
//   the priority formula to 100.0f / distance, capped at 99.
// - Modeled the two ManagedArray growth/removal paths and the out-of-line
//   notify error purge. Ten bounded hypotheses are now exhausted; the typed
//   reconstruction has the oracle's 37 behavior-backed call operations (the
//   two queue callbacks are still classified as extra virtual slots after
//   hoisting), 1473 bytes vs the oracle's 1372, and 1325 positional diff bytes.
// Main-agent source audit: named the observed Static_Object virtual methods
// (weaponRange, underAttack, setUnderAttack, setWaitingToMove, and
// waitingToMove) and replaced the remaining numeric slot labels through the
// proven +0x130 surface. Current post-audit check is 1469 bytes, 39 calls,
// and 76.66% shape; the queue-callback topology remains unresolved.
// Shard B pass: direct purge-and-return on notify result 4 is the natural
// oracle-supported form and improved the best diff from 1325 to 1314 bytes.
// Pointer-to-virtual-member callbacks emitted direct thunks and four extra
// calls, so they were rolled back. A raw vtable callback kept the same call
// map but changed cleanup and worsened the shape, so it was also rolled back.
// Shard B narrow control probe: processNotify and processOrder are unconditional
// callback loops whose bounds test supplies the empty-queue behavior. Removing
// the two source preconditions aligned all 37 ordered calls and raised shape
// similarity to 84.85%; the remaining drift is not a call-order gap.
//
// Follow-up probes:
// - The reviewed extern FILE* actionFile declaration reduced the natural source
//   to the exact 1372-byte boundary. Positive objectValue guards and one shared
//   target log/stop tail remain binary-supported in this basin.
// - Reversing the final look-around comparison to timer > timeout recovered the
//   original load order and raised shape to 90.89%; the source still has 458
//   instructions versus 461 and 1173 strict diff bytes.
// - A for-loop scan improved raw diff to 1114 bytes but moved the operator[]
//   growth block to a cold suffix. It was rolled back because the oracle keeps
//   that block before the lookup path. Volatility, register hints, explicit
//   labels, and alternate remove forms were also tested and discarded.
// - Direct currentOrder reloads removed an artificial live temporary and
//   reduced the strict diff to 1038 bytes. Binary evidence then fixed
//   weaponRange(1), the 100.0f data symbol, and a named distance float.
// - Two direct action-log calls tail-merge to the oracle's immediate 0x335 and
//   0x356 pushes. The invalid-attacker remove path breaks to the timer tail;
//   it does not retest the attacking-unit loop.
// - Current reduced check: 1372 bytes, 37 calls, 463 versus 461 instructions,
//   97.62% shape, 88.29% exact-block coverage, and 256 strict diff bytes.
// - Captain repair: the target-killed retry calls moveTo with force flag 1.
//   This matches the original push at +0142 and reduces the grouped diff to
//   226 bytes with 95.23% exact-block coverage.
//   BINARY NOTE: the first remaining block is +03A2. The oracle adds the
//   secondary and look-around timers, tests notify size, then stores all three
//   timers. The current source stores idle first and clears the offset register
//   before that test. Do not retain a metric-only scheduling workaround.
// - Accepted-drift audit: do not promote. The executable reads notifyQueueSize
//   before publishing the updated idle timer. The rebuild publishes idle first.
//   The executable also writes currentOrderPriority to a stack home before later
//   helper calls; the rebuild omits that helper-visible stack publication.
// - Specialist audit: moving offset initialization into the positive notify
//   guard changed the CFG and grew the body to 1417 bytes. Expanded timer
//   assignments, an idle-timer local, split order-loop declarations, and an
//   unused current-order local either duplicated the clean output or were
//   optimized away. Retain the clean natural source while this blocker remains.
// - Authentic-context pass: the complete PDB prefix through this owner now
//   compiles from canonical owner includes. Every exact anchor stays exact.
//   The accepted save drift and this owner's bytes also stay unchanged.
//   The prefix uses /O2 /Oy /GX, as required by three exact early owners.
//   Thus, missing prefix context does not cause the timer publication drift.
//   Extending the prefix through 00414800 also leaves this body unchanged.
// - The canonical declaration also restores the PDB-qualified nonvirtual
//   `?update@UnitAIModule@@QAEHK@Z` owner. The prior virtual declaration had
//   the same code bytes but the wrong owning symbol.
// - The later five-argument moveTo owner proves the canonical virtual ABI.
//   This call uses a binary-proven four-argument beta view at the same slot.
// - Typed notify and order indexing is required. VC5 derives the 0x18 and 0x24
//   byte induction variables after each initial bound test. This recovers the
//   executable's timer publication order and both queue-loop stack lifetimes.
// - Current reduced check: 1372 bytes, 37 aligned calls, 463 instructions,
//   98.27% shape, 95.23% exact-block coverage, and 226 strict diff bytes.
//   BLOCKER: the executable publishes currentOrder to the incoming parameter
//   home before the post-queue state guard. Natural tail locals and parameter
//   assignments are removed by VC5. The rebuild therefore stays seven bytes
//   short at +0467 and speculates one later currentAction read.



#define taskedThisUpdate (*(int*)0x592A48)
#define searchedThisUpdate (*(int*)0x592A4C)
#define numberVisibleObjects (*(int*)0x592A50)
#define numberDifferentPlayerObjectsVisible (*(int*)0x592A54)
extern FILE* actionFile;
extern float DAT_0056ebc0;
#define actionFormat ((const char*)0x57F964)
#define actionSource ((const char*)0x57F980)

int UnitAIModule::update(unsigned long param_1)
{
    RGE_Static_Object* target;
    int i;
    int haveGameAction;

    if (2 < this->objectValue->object_state) {
        return 1;
    }

    taskedThisUpdate = 0;
    searchedThisUpdate = 0;
    numberVisibleObjects = 0;
    numberDifferentPlayerObjectsVisible = 0;

    haveGameAction = this->objectValue->actions->have_action();
    if (haveGameAction == 0 && this->objectValue->waitingToMove() == 1) {
        this->objectValue->setWaitingToMove(0);
    }

    i = -1;
    if (this->currentTargetValue != i) {
        target = this->lookupObject(this->currentTargetValue);
        if (target == 0) {
            this->currentTargetValue = i;
            if (this->currentActionValue == 600) {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = i;
                    }
                    fprintf(actionFile, actionFormat, objectID,
                            actionSource, 0x306);
                }
                this->stopObject(1);
                this->idleTimerValue = this->idleTimeoutValue;
            }
        } else {
            long targetLogObjectID;
            if (this->objectValue->object_state == 2 && target->object_state > 2) {
                if (this->actionRequiresLiveTarget(this->currentActionValue) == 1) {
                    this->stopAfterTargetKilledValue = 0;
                    if (this->currentActionValue == 600) {
                        int idleResult = this->processIdle(0);
                        if (idleResult == 5) {
                            if (this->currentOrderValue != 0x2D5) {
                                if (this->moveTo(this->currentTargetXValue,
                                                 this->currentTargetYValue,
                                                 this->currentTargetZValue,
                                                 this->objectValue->weaponRange(),
                                                 1) == 0) {
                                    this->removeCurrentTarget();
                                    if (actionFile != 0) {
                                        if (this->objectValue != 0) {
                                            targetLogObjectID = this->objectValue->id;
                                        } else {
                                            targetLogObjectID = i;
                                        }
                                        fprintf(actionFile, actionFormat,
                                                targetLogObjectID,
                                                actionSource, 0x335);
                                    }
                                    this->stopObject(1);
                                } else {
                                    this->lastOrderValue = this->currentOrderValue;
                                    this->currentOrderValue = i;
                                    this->currentOrderPriorityValue = i;
                                }
                            }
                        } else if (this->currentOrderValue != 0x2D5) {
                            this->lastOrderValue = this->currentOrderValue;
                            this->currentOrderValue = i;
                            this->currentOrderPriorityValue = i;
                        }
                    } else {
                        this->removeCurrentTarget();
                        if (actionFile != 0) {
                            if (this->objectValue != 0) {
                                targetLogObjectID = this->objectValue->id;
                            } else {
                                targetLogObjectID = i;
                            }
                            fprintf(actionFile, actionFormat, targetLogObjectID,
                                    actionSource, 0x356);
                        }
                        this->stopObject(1);
                    }
                }
            }
            if (this->objectValue->owner->computerPlayer() == 1 &&
                this->currentOrderPriorityValue != i &&
                this->currentOrderPriorityValue < 100) {
                float distanceValue =
                    this->objectValue->distance_to_object(target);
                int distance = (int)(DAT_0056ebc0 / distanceValue);
                if (distance > 99) {
                    distance = 99;
                }
                this->currentOrderPriorityValue = distance;
            }
        }
    }

    if (this->attackingUnitsValue.numberValue == 0 &&
        this->objectValue->underAttack() != 0) {
        this->objectValue->setUnderAttack(0);
    } else {
        i = 0;
        if (this->attackingUnitsValue.numberValue > 0) {
            do {
                RGE_Static_Object* attacker =
                    this->lookupObject(this->attackingUnitsValue[i]);
                if (attacker != 0 && attacker->unitAI() != 0 &&
                    attacker->object_state <= 2 &&
                    attacker->unitAI()->currentTarget() == this->objectValue->id) {
                    ++i;
                    continue;
                }

                this->attackingUnitsValue.remove(
                    this->attackingUnitsValue[i]);
                break;
            } while (i < this->attackingUnitsValue.numberValue);
        }
    }

    this->lastWorldPositionX = this->objectValue->world_x;
    this->lastWorldPositionY = this->objectValue->world_y;
    this->lastWorldPositionZ = this->objectValue->world_z;
    this->idleTimerValue += param_1;
    this->secondaryTimerValue += param_1;
    this->lookAroundTimerValue += param_1;

    {
        int i = 0;
        while (i < this->notifyQueueSizeValue) {
            int result = this->processNotify(
                &this->notifyQueueValue[i], param_1);
            if (result == 4) {
                this->purgeNotifyQueue(param_1);
                return 0;
            }
            if (result == 3) {
                break;
            }
            ++i;
        }
    }

    this->purgeNotifyQueue(param_1);

    if (haveGameAction == 0) {
        switch (this->currentActionValue) {
        case 600:
        case 0x261:
        case 0x262:
        case 0x265:
        case 0x26B:
        case 0x26C:
            this->currentActionValue = -1;
            break;
        default:
            break;
        }
    }

    if (2 < this->objectValue->object_state) {
        return 0;
    }

    if (this->objectValue->groupCommanderValue == this->objectValue->id) {
        this->updateGroup(param_1);
    }

    if (this->currentActionValue == -1) {
        int i = 0;
        while (i < this->orderQueueSizeValue) {
            int result = this->processOrder(
                &this->orderQueueValue[i], i);
            if (result == 1) {
                break;
            }
            ++i;
        }
    }

    this->processMisc();

    if (this->idleTimerValue > this->adjustedIdleTimeoutValue) {
        if (this->currentActionValue == -1) {
            if (this->currentTargetValue == -1) {
                this->idleTimerValue = 0;
                this->processIdle(1);
                goto update_tail;
            }
        }
    } else if (this->currentActionValue == -1 &&
               this->currentTargetValue == -1) {
        goto update_tail;
    }

    this->idleTimerValue = 0;

update_tail:
    if (this->objectValue->owner->computerPlayer() == 1 &&
        this->lookAroundTimerValue > this->lookAroundTimeoutValue) {
        this->lookAround();
    }

    return 1;
}

#undef taskedThisUpdate
#undef searchedThisUpdate
#undef numberVisibleObjects
#undef numberDifferentPlayerObjectsVisible
#undef actionFormat
#undef actionSource

// --- scratch/00414040_updateGroup.cpp ---
// VA: 00414040 UnitAIModule::updateGroup (1831B)
// aiuaimod.cpp
// Attempt log:
// - Replaced the unrelated placeholder with a typed reconstruction from the
//   play-status, group-member, and phase-trigger ownership in the binary.
// - Baseline follows the original three trigger checks, group rebuild path,
//   and phase-255 group fill path. Exact codegen remains under investigation.
// - Corrected object virtual slots (+1B8, +1BC, +1C8), target coordinates,
//   world_time at +04, and the groupList+1 member array from the assembly.
// - Separated the dead-group count from its eight-byte grouping scan offset.
// - Eight probes reached exact call-set parity, but the remaining gap is a
//   broad VC5 frame and block-layout difference. No productive codegen lead
//   remains in this assignment.
// - Tried the period ManagedArray<int>::operator[] donor at both the first
//   comparison and the later lookup. The repeated operator[] added one growth
//   call pair and was rolled back.
// - Kept operator[] only for the first comparison and phase-255 member read;
//   direct value access remains after the separate resize call. This improved
//   the structural check to 1714 differing bytes with exact call parity.
// - Tried initializing the typed groupList sentinel before the phase-255 fill;
//   the original zero store supports this group-layout hypothesis.
// - Rolled back the sentinel initialization: it worsened the positional diff
//   from 1714 to 1767 bytes and increased the rebuilt size by four bytes.
// - This claim tested the combined outer play guard, array-pointer and loop-index
//   spellings, and a repeated phase-command temporary. The best emitted code
//   stayed at 1714 differing bytes and 42 aligned calls.
// - Reversing the equivalent distance threshold improved resync similarity but
//   worsened positional equality to 1762 bytes; restored the clean source.
// - This claim tested 24 distinct structural, lifetime, ABI, and layout probes.
// - Directly rereading currentPhaseValue removed its stack byte and reduced the
//   diff to 1646 bytes. Branch-local member results in trigger types 8 and 9
//   reduced it to 1611 bytes and kept the source natural.
// - Removing dead play initialization and testing a 52-entry groupList reached
//   the best provisional metric: 1601 bytes, exact 0xFC frame, 42 calls.
//   The 52-entry array is not retained because the binary does not prove it.
// - The clean 50-entry array now gives 1602 bytes, frame 0xF4, and 42 calls.
// - Positive guard forms, integer target-ID typing, local declaration scopes,
//   loop-form changes, address aliases, a volatile diagnostic, and threshold
//   variants either duplicated output or worsened the result.
// - Restored the PDB-listed gatherDistance as the distance result local. The
//   reversed distance > threshold form recovers the original fcompp/test 41h
//   x87 predicate shape and reduced the clean diff to 1600 bytes.
// - Restored the PDB-listed newTarget, groupCount, and a locals. A dedicated i
//   counter for the three-trigger phase loop moved the frame to 0xF8 and the
//   diff to 1598 bytes. A typed int* group-list cursor raises shape similarity
//   to 75.25% with 27.38% exact-block coverage.
// - BINARY NOTE: the phase-255 path zeros all five totalHitPoints entries.
//   It indexes that typed array by group and publishes totalHitPoints[i].
//   The group-list cursor starts at groupList + 1 and advances after each
//   member. These forms preserve the observed typed array addresses.
// - Open blocker: the executable frame is 0xFC and this natural source frame
//   is 0xF8. The first mismatch remains the prologue. Direct calls and their
//   order match, but broad control-flow drift remains.
// MANAGEDARRAY AUDIT: group-member growth guards, copies, publication, resize,
// value reads, and field offsets follow the expected template behavior. No
// shared template change is required.
// BLOCKER: The executable frame is 0xFC and the natural source frame is 0xF8.
// A 52-entry group list fixes only the frame and adds unsupported local storage.
// Broad CFG drift also remains despite all 42 calls aligning.
// Canonical-context pass: this owner uses the PDB aiuaimod.cpp surfaces and
// the real bestUnitToAttack slot at vtable +0x30. The source has 42 direct
// calls in the oracle order. The full prefix through 00414800 keeps this body
// in the same code-generation basin. Do not change 00413AB0 queue indexing
// or its timer and current-order publication while testing this owner.
// - Captain probe: a separate initial-target local was codegen-identical and
//   was restored. The grouped result remains 1520 differing bytes, 0xF8 frame.


void UnitAIModule::updateGroup(unsigned long param_1)
{
    RGE_Static_Object* target;
    int newTarget;
    AIPlay* play;
    AIPlayPhase* phase;
    int totalHitPoints[5];
    int groupList[50];
    int triggerSatisfied;
    AIPlayPhaseTrigger* trigger;
    float gatherDistance;
    int deadCount;
    int a;
    int groupCount;

    if (this->playStatus &&
        (play = this->objectValue->owner->world->playbook->play(
             this->playStatus->playNumberValue)) != 0) {
        target = this->lookupObject(this->playStatus->targetValue);
        if (!target) {
            newTarget = this->bestUnitToAttack(1, 0, (float*)0);
            RGE_Static_Object* object = this->objectValue;
            int memberIndex = 0;
            if (object->groupMembers.numberValue > 0) {
                do {
                    if (newTarget != -1) {
                        goto foundTrigger;
                    }

                    object = this->objectValue;
                    if (object->groupMembers[memberIndex] != object->id) {
                        if (object->groupMembers.maximumSizeValue - 1 < memberIndex) {
                            object->groupMembers.resize(memberIndex + 1);
                        }
                        object = this->lookupObject(
                            object->groupMembers.value[memberIndex]);
                        if (object != 0 && object->unitAI() != 0) {
                            UnitAIModule* memberAI = object->unitAI();
                            newTarget = memberAI->bestUnitToAttack(1, 0, (float*)0);
                        }
                    }

                    object = this->objectValue;
                    ++memberIndex;
                } while (memberIndex < object->groupMembers.numberValue);
            }

            if (newTarget == -1) {
                operator delete(this->playStatus);
                this->playStatus = 0;
                return;
            }

foundTrigger:
            this->playStatus->targetValue = newTarget;
            this->selectNewPlayPhase(
                (unsigned int)this->playStatus->currentPhaseValue, 0);
            target = this->lookupObject(newTarget);
        }

        if (this->playStatus->currentPhaseValue == 0xFD) {
            totalHitPoints[0] = 0;
            totalHitPoints[1] = 0;
            totalHitPoints[2] = 0;
            totalHitPoints[3] = 0;
            totalHitPoints[4] = 0;
            groupCount = 0;
            deadCount = 0;
            if (this->objectValue->groupMembers.numberValue > 0) {
                int* groupListCursor = groupList + 1;
                do {
                    RGE_Static_Object* member = this->lookupObject(
                        this->objectValue->groupMembers[deadCount]);
                    if (member != 0) {
                        *groupListCursor = member->id;
                        ++groupCount;
                        ++groupListCursor;
                        int commandIndex = 0;
                        int commandCount = this->objectValue->groupUnitCount();
                        if (commandCount > 0) {
                            do {
                                int commandValue = this->objectValue->groupUnitCommand(
                                    commandIndex, 1);
                                member->groupUnitCallback(commandValue);
                                ++commandIndex;
                                commandCount = this->objectValue->groupUnitCount();
                            } while (commandIndex < commandCount);
                        }
                    }

                    ++deadCount;
                } while (deadCount < this->objectValue->groupMembers.numberValue);
            }

            this->playStatus->lastPhaseChangeTimeValue =
                this->objectValue->owner->world->world_time;
            play->fillGroups(this->playStatus, groupList + 1, groupCount,
                             this->objectValue->owner->world);
            if (groupCount > 0) {
                int* group = groupList + 1;
                int remaining = groupCount;
                do {
                    RGE_Static_Object* member = this->lookupObject(*group);
                    totalHitPoints[this->playStatus->group(*group)] +=
                        (int)member->hitPoints;
                    --remaining;
                    ++group;
                } while (remaining != 0);
            }

            int i = 0;
            do {
                this->playStatus->setOriginalHitPoints(
                    i, totalHitPoints[i]);
                ++i;
            } while (i < 5);
            this->selectNewPlayPhase(0, 0);
            return;
        }

        phase = play->phase((unsigned int)this->playStatus->currentPhaseValue);
        if (phase) {
            int i = 0;
            do {
                trigger = phase->trigger(i);
                if (trigger != 0 && trigger->typeValue != 0) {
                    switch (trigger->typeValue) {
                    case 1: {
                        triggerSatisfied = 1;
                        a = 0;
                        while (triggerSatisfied != 0) {
                            int command = play->groupGivenCommandOnPhase(
                                a, 1, this->playStatus->currentPhaseValue);
                            if (command != -1) {
                                AIPlayPhaseCommand* phaseCommand =
                                    phase->command(command);
                                int groupingOffset = 0;
                                while (triggerSatisfied != 0 &&
                                       groupingOffset < 400) {
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus +
                                                          groupingOffset);
                                    if (grouping->groupValue == a) {
                                        RGE_Static_Object* member =
                                            this->lookupObject(grouping->id);
                                        if (member != 0) {
                                            gatherDistance =
                                                member->distance_to_position(
                                                    (float)phaseCommand->value1Value +
                                                        target->world_x,
                                                    (float)phaseCommand->value2Value +
                                                        target->world_y,
                                                    (float)phaseCommand->value2Value +
                                                        target->world_z);
                                            if (gatherDistance >
                                                (float)trigger->value1Value) {
                                                triggerSatisfied = 0;
                                            }
                                        }
                                    }
                                    groupingOffset += 8;
                                }
                            }
                            ++a;
                            if (a >= 5) {
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        int matchingGroups = 0;
                        int deadGroups = 0;
                        int groupingOffset = 0;
                        do {
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->groupValue ==
                                (unsigned int)trigger->value1Value) {
                                ++matchingGroups;
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member == 0 || member->object_state > 2) {
                                    ++deadGroups;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        if (matchingGroups != 0 &&
                            trigger->value2Value <= (deadGroups * 100) /
                                matchingGroups) {
                            triggerSatisfied = 1;
                        }
                        break;
                    }
                    case 3: {
                        int lostHitPoints = 0;
                        int groupingOffset = 0;
                        do {
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->typeValue ==
                                (unsigned int)trigger->value1Value) {
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member != 0) {
                                    lostHitPoints += (int)member->hitPoints;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        int original = this->playStatus->originalHitPoints(
                            trigger->value1Value);
                        if (trigger->value2Value <=
                            ((original - lostHitPoints) * 100) /
                                this->playStatus->originalHitPoints(
                                    trigger->value1Value)) {
                            triggerSatisfied = 1;
                        }
                        break;
                    }
                    case 8: {
                        triggerSatisfied = 1;
                        int groupingOffset = 0;
                        do {
                            if (triggerSatisfied == 0) {
                                break;
                            }
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->groupValue ==
                                    (unsigned int)trigger->value1Value) {
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member != 0 && member->object_state == 2) {
                                    triggerSatisfied = 0;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        break;
                    }
                    case 9: {
                        triggerSatisfied = 1;
                        int groupingOffset = 0;
                        do {
                            if (triggerSatisfied == 0) {
                                break;
                            }
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->typeValue ==
                                    (unsigned int)trigger->value1Value) {
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member != 0 &&
                                    (int)member->hitPoints <
                                        member->master_obj->maximumHitPoints) {
                                    triggerSatisfied = 0;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        break;
                    }
                    case 10:
                        triggerSatisfied = 1;
                        break;
                    case 11:
                        if (trigger->value1Value <
                            (this->objectValue->owner->world->world_time -
                             this->playStatus->lastPhaseChangeTimeValue) /
                                1000) {
                            triggerSatisfied = 1;
                        }
                        break;
                    default:
                        break;
                    }

                    if (triggerSatisfied &&
                        this->selectNewPlayPhase(trigger->nextPhaseValue, 0) == 1) {
                        return;
                    }
                }
                ++i;
            } while (i < 3);
            this->selectNewPlayPhase(
                this->playStatus->currentPhaseValue, 1);
        }
    }
}

// --- scratch/00414800_selectNewPlayPhase.cpp ---
// VA: 00414800 UnitAIModule::selectNewPlayPhase (1298B)
// aiuaimod.cpp
// Period-plausible reconstruction of play-phase command selection.
//
// Attempt log:
// - Replaced the raw-pointer placeholder with typed playbook, phase-command,
//   group-member, and UnitAIModule ownership.
// - The source keeps all 25 ordered calls and the original direct-call ABI set.
// - Binary tests covered branch shape, loop form, local scope, point layout,
//   coordinate load order, vtable context, and case-5 result lifetime.
// - The case-5 scan uses groupValue at grouping offset +4. The original loads
//   this byte before lookup. It reuses param_1 for the found object id.
// - The case-5 scan increments its 8-byte cursor after the body and compares
//   it with 0x190.
// - The member filter uses a nested guard and reuses param_1 for the group
//   byte. The original writes that value before group() and compares it after.
// - The play number is read before the object/world/playbook receiver.
// - The case-1 phase byte is a narrow local. The case-3 value is loaded before
//   unitAI(). Cases 4 and 8 load their integer fields before unitAI().
// - The case-5 scan uses a while loop. This emits the original jl backedge.
// - Case 5 reads found->hitPoints and master_obj->maximumHitPoints. These are
//   the object and master fields proven by the corrected canonical ABI.
// - The current natural source is 1216 rebuilt bytes versus 1298 original
//   bytes, with a 0x2C frame and 934 strict differing bytes.
// - Direct order calls improved shape but added one virtual call. They were
//   not retained because the original has 25 ordered calls.
//
// Current status: structural reconstruction remains incomplete. Keep this
// readable common-tail source as the best behavior-backed candidate.
// MANAGEDARRAY AUDIT: group-member capacity checks, resize calls, value reads,
// and field offsets follow the expected template behavior. No shared template
// change is required.
// BLOCKER: The rebuild is 82 bytes short, with a 0x2C frame versus 0x44 and 34
// fewer instructions. Broad register and local-lifetime recovery remains
// incomplete despite all 25 calls aligning.
// Canonical-context pass: this owner now uses the PDB aiuaimod.cpp surfaces.
// Its 1216-byte body, 0x2C frame, 25 calls, and 934-byte diff stay unchanged.
// The corrected object and master hit-point fields follow updateGroup.


int UnitAIModule::selectNewPlayPhase(int param_1, int param_2)
{
    int phase = 0;
    AIPlayPhase* phaseObject;
    RGE_Static_Object* target;
    AIPlay* play;

    if (this->playStatus == 0) {
        return 0;
    }

    int playNumber = this->playStatus->playNumberValue;
    play = this->objectValue->owner->world->playbook->play(playNumber);
    if (play == 0) {
        return 0;
    }

    if (param_1 == 0xFE) {
        operator delete(this->playStatus);
        this->playStatus = 0;
        return 1;
    }

    phaseObject = play->phase(param_1);
    if (phaseObject == 0) {
        return 0;
    }

    target = this->lookupObject(this->playStatus->targetValue);
    if (target == 0) {
        return 0;
    }

    this->playStatus->currentPhaseValue = (unsigned char)param_1;

    phase = 0;
    do {
        AIPlayPhaseCommand* command = phaseObject->command(phase);
        if (command != 0 && command->typeValue != 0) {
            if ((command->typeValue == 6 || command->typeValue == 7) &&
                param_2 == 0) {
                switch (command->typeValue) {
                case 6:
                    this->playStatus->resetHitPoints(
                        command->groupValue, this->objectValue->owner->world);
                    break;
                case 7:
                    this->playStatus->removeDeadUnits(
                        command->groupValue, this->objectValue->owner->world);
                    break;
                }
            } else {
                int i = 0;
                RGE_Static_Object* member = this->objectValue;
                if (member->groupMembers.numberValue > 0) {
                    do {
                        if (i > member->groupMembers.maximumSizeValue - 1) {
                            member->groupMembers.resize(i + 1);
                        }

                        member = this->lookupObject(
                            member->groupMembers.value[i]);
                        if (member != 0 && member->unitAI() != 0) {
                            param_1 = command->groupValue;
                            if (this->playStatus->group(member->id) !=
                                (unsigned char)param_1) {
                                goto next_member;
                            }
                            if (param_2 == 1 &&
                                member->unitAI()->currentAction() != -1) {
                                goto next_member;
                            }
                            int orderAction;
                            int orderTargetOwner;
                            float orderX;
                            float orderY;
                            float orderZ;
                            UnitAIModule* memberAI;

                            switch (command->typeValue) {
                            case 1: {
                                int distance = (int)member->distance_to_position(
                                    (float)command->value1Value + target->world_x,
                                    (float)command->value2Value + target->world_y,
                                    (float)command->value3Value + target->world_z);
                                unsigned char currentPhase =
                                    this->playStatus->currentPhaseValue;
                                if (distance > play->gatherTolerance(
                                        command->groupValue,
                                        currentPhase)) {
                                    memberAI = member->unitAI();
                                    orderAction = 0x2C6;
                                    param_1 = -1;
                                    orderTargetOwner = -1;
                                    orderX = (float)command->value1Value + target->world_x;
                                    orderY = (float)command->value2Value + target->world_y;
                                    orderZ = (float)command->value3Value + target->world_z;
                                    break;
                                }
                                goto next_member;
                            }
                            case 2: {
                                memberAI = member->unitAI();
                                int targetOwnerId = target->owner->id;
                                int targetId = target->id;
                                orderAction = 0x2BC;
                                orderTargetOwner = targetOwnerId;
                                param_1 = targetId;
                                orderX = -1.0f;
                                orderY = -1.0f;
                                orderZ = -1.0f;
                                break;
                            }
                            case 3:
                                param_1 = this->playStatus->savedAttackerValue;
                                memberAI = member->unitAI();
                                orderAction = 0x2BC;
                                orderTargetOwner = -1;
                                orderX = -1.0f;
                                orderY = -1.0f;
                                orderZ = -1.0f;
                                break;
                            case 4: {
                                int pointX = this->playStatus->originalPointX;
                                int pointY = this->playStatus->originalPointY;
                                int pointZ = this->playStatus->originalPointZ;
                                orderAction = 0x2C6;
                                param_1 = -1;
                                orderTargetOwner = -1;
                                memberAI = member->unitAI();
                                orderX = (float)pointX;
                                orderY = (float)pointY;
                                orderZ = (float)pointZ;
                                break;
                            }
                            case 5: {
                                param_1 = -1;
                                int groupingOffset = 0;
                                while (groupingOffset < 0x190) {
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus + groupingOffset);
                                    if (grouping->groupValue == command->value1Value) {
                                        RGE_Static_Object* found =
                                            this->lookupObject(grouping->id);
                                        if (found != 0 &&
                                            (int)found->hitPoints + 1 <
                                                found->master_obj->maximumHitPoints) {
                                            param_1 = found->id;
                                            break;
                                        }
                                    }
                                    groupingOffset += 8;
                                }
                                if (param_1 == -1) {
                                    goto next_member;
                                }
                                memberAI = member->unitAI();
                                orderAction = 0x2BF;
                                orderTargetOwner = -1;
                                orderX = -1.0f;
                                orderY = -1.0f;
                                orderZ = -1.0f;
                                break;
                            }
                            case 8: {
                                int commandX = command->value1Value;
                                int commandY = command->value2Value;
                                int commandZ = command->value3Value;
                                memberAI = member->unitAI();
                                orderAction = 0x2D8;
                                param_1 = -1;
                                orderTargetOwner = -1;
                                orderX = (float)commandX + target->world_x;
                                orderY = (float)commandY + target->world_y;
                                orderZ = (float)commandZ + target->world_z;
                                break;
                            }
                            default:
                                goto next_member;
                            }

                            memberAI->order(
                                this->objectValue->id, orderAction, param_1,
                                orderTargetOwner, orderX, orderY, orderZ,
                                1.0f, 1, 0, 100);
                        }

                    next_member:
                        ++i;
                        member = this->objectValue;
                    } while (i < this->objectValue->groupMembers.numberValue);
                }
            }
        }

        ++phase;
    } while (phase < 5);

    return 1;
}

// --- accepted_drift/00414D40_order.cpp ---
// VA: 00414D40 UnitAIModule::order(int,int,int,int,float,float,float,float,int,int,int)
// aiuaimod.cpp
// Attempt log:
// - Baseline: typed direct-call reconstruction; exact size/call set, but VC5 saves
//   EDI at entry while the original delays it until the nonzero-p9 path.
// - Tried p2 directly, a block-local orderType, early-return versus explicit-else
//   layout, positive state guard, <3 versus <=2, corrected virtual return types,
//   and stdio context. These emitted the same best nonexact code (except <3,
//   which changed the compare immediate); no source-shape lead remains in this
//   isolated TU.
// - Follow-up session probes: a branch-local p2 copy, an address-taken p2 alias,
//   register/const p2 qualifiers, and /GX all emitted the same code. A natural
//   switch(p9) worsened size/call alignment and was rolled back. The remaining
//   structural gap is the original's delayed push edi after the p9 test versus
//   VC5's entry push edi; no ABI/layout or ordered-call discrepancy was found.
// - Fresh normal-414D40-r1 pass: baseline reconfirmed the 306-byte, 8-call
//   canonical source. Separate branch-local copies, a top-level guard-bound
//   copy, a single-iteration loop, a common done label, and positive-guard
//   if/else layout were all codegen duplicates. The delayed EDI save remains
//   the only actionable gap; the clean direct-parameter source is restored.
// - Added the full proven UnitAIModule virtual surface and typed 0x24-byte
//   OrderEvent; corrected the same-TU owner return surface. No bytes changed.
// - Expanded the local class to the proven UnitAIModule field layout. All
//   eight ordered calls and the 277-byte mismatch stayed unchanged.
// - Fresh shardE baseline reconfirmed the same 306-byte source and 8-call
//   surface. A volatile state byte, an inline identity helper around p2, and
//   a branch-local p10 copy all emitted the same code. A size-optimization
//   pragma changed the basin to 297 bytes and was rolled back.
// - Restored the canonical source. The remaining evidence-backed blocker is
//   VC5's entry push edi versus the oracle's branch-local push edi; ABI,
//   layout, ordered calls, and all later blocks remain aligned.
// - Best canonical source retained: positive state guard, direct p2 use, typed
//   object/member ownership, real virtual calls, and standard FILE/fprintf ABI.
// - Managed pass probes: split p2 into branch-local orderType copies, move the
//   nonzero-path copy after the p10 call, and add windows.h context. All were
//   codegen duplicates. Restored the canonical source; delayed EDI remains
//   unresolved and requires a compiler/TU-context lead, not a semantic change.
// - Revisit probes added stdlib.h, then string.h with stdio.h, and split the
//   late orderType declaration from its assignment. All stayed at 306 bytes,
//   eight ordered calls, and the same 277-byte mismatch. The natural typed
//   dispatch remains the clean source.
// - Final revisit validation: the restored source still has the exact 306-byte
//   boundary and eight ordered calls. The only structural gap is VC5's entry
//   push edi versus the original branch-local push edi; no policy-valid source
//   lead was found.
// ACCEPTED DRIFT: the original saves EDI only on the nonzero-p9 path. The
// rebuild saves it at entry. This shifts parameter displacements but each of
// the three addToOrderQueue calls receives the same typed arguments. The only
// other instruction difference replaces a dead p10 register load with a direct
// stack compare. All eight calls, predicates, queue effects, logging, virtual
// dispatches, return values, register restoration, and fault order match.
// Size and CFG match. Each path balances its own saved registers and arguments.
// This function has no SEH.
// A fresh early-invalid-state return probe reproduced the same allocation.
// Canonical-context pass: this owner now uses the shared aiuaimod.cpp surface.
// Its 306-byte boundary, eight calls, symbol, and 277-byte drift stay unchanged.
// Adding this owner changes updateGroup scheduling but not its recorded metrics.



extern FILE* actionFile;
extern const char str_fmt_stopObject[];
extern const char str_aiuaimod_path[];

int UnitAIModule::order(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10, int p11)
{
    if (this->objectValue->object_state <= 2) {
        if (p9 == 0) {
            this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, p10, p11);
            return 1;
        }

        if (p10 == 1) {
            this->addToOrderQueue(this->objectValue->id,
                                  this->currentOrderValue,
                                  this->currentTargetValue,
                                  -1,
                                  this->currentTargetXValue,
                                  this->currentTargetYValue,
                                  this->currentTargetZValue,
                                  this->desiredTargetDistanceValue,
                                  1,
                                  this->currentOrderPriorityValue);
        }

        this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, 1, p11);

        if (p2 != 0x2D9) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0)
                    id = this->objectValue->id;
                else
                    id = -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x6F3);
            }
            this->stopObject(1);
        }

        this->purgeNotifyQueue(0);
        this->processOrder(this->orderQueueValue, 0);
    }
    return 1;
}

// --- matching/00414E80_notify.cpp ---
// VA: 00414E80 notify (177B)
// aiuaimod.cpp
// 2026-05-24 Boss pass: replaced placeholder with full behavior from packet. Baseline decompiler-shaped source reached exact size but 67.2316% positional, first mismatch +25 due parameter/register coloring and list-scan topology. Tried msg/target locals in both orders, register locals, direct parameter expressions, original if/else shape, several loop forms (while/do/continue), positive 1FB guard, currentAction local, direct addToNotifyQueue args, explicit max/array locals, volatile/raw-offset variants, goto-fail/shared tail, no-else/break form, and delayed target load. Best kept source (explicit msg/target plus max/arr locals and do loop) improves to 18.6441% positional / 28.8136% edit, first mismatch +25. Remaining drift is register-coloring (msg/target/max/array in different registers), list-scan block shape, and equivalent final addToNotifyQueue argument registers; not accepted_drift-quality because differences are broad control-flow/register topology, not localized benign drift.
// 2026-05-26 Boss pass: matched on try 3. Negative probes: target-before-msg local order
// moved first diff but still wrong final arg registers; hoisting n/max/arr locals failed/regressed.
// Winning shape preserves msg then target locals, but rewrites the 0x2BB scan as an explicit
// `while(1)` with `if(i>=max) goto fail2; ... if(i<n) continue; return 0;` and a separate
// `fail2: return 0;`. This recovers the original loop block order/register coloring and final
// addToNotifyQueue pushes. MATCH.
// PDB FPO and vtable evidence prove the public virtual UAE owner. The prior
// isolated declaration emitted exact body bytes under the wrong QAE symbol.


int UnitAIModule::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6)
{
    if (objectValue->object_state != 2)
        return 0;

    int msg = param_3;
    int target = param_1;

    if (msg == 0x2BB) {
        int n = attackingUnitsValue.numberValue;
        int i = 0;
        if (n <= 0)
            goto fail2;
        int max = attackingUnitsValue.maximumSizeValue;
        while (1) {
            if (i >= max)
                goto fail2;
            if (attackingUnitsValue.value[i] == target)
                goto found;
            ++i;
            if (i < n)
                continue;
            return 0;
        }
    } else {
found:
        if ((msg != 0x1FB) || (param_4 == currentActionValue)) {
            if ((msg == 0x1FA) && (param_4 == 0x262) &&
                (currentActionValue != 0x262) && (currentActionValue != 0x268))
                return 1;
            return addToNotifyQueue(param_1, param_2, param_3, param_4, param_5, param_6);
        }
    }
fail2:
    return 0;
}

// --- matching/00414F40_notifyCommander.cpp ---

int UnitAIModule::notifyCommander(NotifyEvent* event) {
    return this->notifyCommander(
        event->caller,
        event->recipient,
        event->mType,
        event->p1,
        event->p2,
        event->p3
    );
}

// --- matching/00414F70_notifyCommander.cpp ---
// VA: 00414F70 UnitAIModule::notifyCommander(int,int,int,long,long,long)
// aiuaimod.cpp
// attempt 1: packet-grounded natural UnitAIModule/RGE_Static_Object surfaces, padded virtual slots for NotifyEvent (+0xD0) and owner notify (+0xE8).
// Canonical-context audit: +0xD0 is processGroupNotify. The RGE_Player +0xE8
// call is notify. These PDB-backed names preserve the exact seven-call body.


int UnitAIModule::notifyCommander(int a1, int a2, int a3, long a4, long a5, long a6)
{
    NotifyEvent nEvent;

    if (this->objectValue->inGroup() == 1) {
        nEvent.caller = a1;
        nEvent.recipient = a2;
        nEvent.mType = a3;
        nEvent.p1 = a4;
        nEvent.p2 = a5;
        nEvent.p3 = a6;

        RGE_Static_Object* obj = this->objectValue;
        int commander = obj->groupCommanderValue;
        if (obj->id == commander) {
            this->processGroupNotify(&nEvent);
        } else {
            RGE_Static_Object* commanderObj = this->lookupObject(commander);
            if (commanderObj != 0) {
                if (commanderObj->unitAI() != 0) {
                    commanderObj->unitAI()->processGroupNotify(&nEvent);
                }
            }
        }
    }

    this->objectValue->owner->notify(a1, a2, a3, a4, a5, a6);
    return 1;
}

// --- matching/00415040_search.cpp ---
// VA: 00415040 UnitAIModule::search()
// aiuaimod.cpp
// attempt 2: direct branch-local GetVisibleUnits calls to avoid stack locals; rely on VC5 right-to-left argument setup/tail merging.

#define searchedThisUpdate (*(int*)0x592A4C)
#define numberVisibleObjects (*(int*)0x592A50)


#define VisibleUnitManager (*(Visible_Unit_Manager**)0x87D800)

void UnitAIModule::search()
{
    RGE_Static_Object* obj;
    RGE_Master_Static_Object* master;
    int range;

    if (searchedThisUpdate == 1)
        return;

    searchedThisUpdate = 1;
    if (this->importantObjects == 0)
        return;

    if (this->currentOrderValue == 0x2BD && this->defendTargetValue != -1) {
        obj = this->lookupObject(this->defendTargetValue);
        if (obj != 0) {
            if (obj->unitAI() != 0) {
                numberVisibleObjects = VisibleUnitManager->GetVisibleUnits(
                    (int)obj->world_x,
                    (int)obj->world_y,
                    (int)obj->master_obj->range,
                    obj->owner->id,
                    this->importantObjects,
                    this->numberImportantObjects,
                    this->objectValue->owner->unitDiplomacy);
                return;
            }
        }
    }

    obj = this->objectValue;
    master = obj->master_obj;
    range = (int)master->range;
    if (master->id == 0x76)
        range += range;

    numberVisibleObjects = VisibleUnitManager->GetVisibleUnits(
        (int)obj->world_x,
        (int)obj->world_y,
        range,
        obj->owner->id,
        this->importantObjects,
        this->numberImportantObjects,
        obj->owner->unitDiplomacy);
}

// --- matching/00415120_importantWhenDead.cpp ---

int UnitAIModule::importantWhenDead(int value) {
    if (value == 0x7 || value == 0x9 || value == 0xA || value == 0xF || value == 0x8 || value == 0x20)
        return 1;
    return 0;
}

// --- matching/00415150_retryableOrder.cpp ---

int UnitAIModule::retryableOrder(int) {
    return 0;
}

// --- matching/00415160_actionRequiresLiveTarget.cpp ---
// first pass: direct byte flag check, then whitelist the live-target action ids
// if this misses, the remaining mismatch is likely only the early return layout or the byte-field placement


int UnitAIModule::actionRequiresLiveTarget(int actionId) {
    if (this->stopAfterTargetKilledValue != 1) {
        if (actionId != 0x258 && actionId != 0x259 && actionId != 0x25B && actionId != 0x25C && actionId != 0x26A && actionId != 0x264) {
            return 0;
        }
    }

    return 1;
}

// --- scratch/004151B0_bestUnitToAttack.cpp ---
// VA: 004151B0 UnitAIModule::bestUnitToAttack (2136B)
// aiuaimod.cpp
// PDB OWNER: ?bestUnitToAttack@UnitAIModule@@UAEHHHPAM@Z
// PDB MODULE: aiuaimod.cpp, lines 2014-2462; body 004151B0-00415A07.
// `UnitAIModule::update` is a separate owner at 00413AB0-0041400B.
// Attempt log:
// - Reconstructed the visible-unit scan, current-target retention, and score
//   passes from the executable. The current source is not exact.
// - BINARY NOTE: slot +10C is called without pushes for range tests.
// - BINARY NOTE: three later slot +10C calls push four path arguments.
//   The source uses a narrow casted surface for those calls.
// - BINARY NOTE: the +3C counter uses dword inc, so it is an int.
// - BINARY NOTE: the final group value is sign-extended to an int.
// - BINARY NOTE: the threat gate uses test and jle, which proves <= 0.
// - BINARY NOTE: the second scan stores the selected ID and building flag
//   into separate locals.
// - Tested 21 distinct hypotheses. Calls now align 49/49 and the frame is
//   0x38, but strict drift remains 1748 bytes (81.8352%).
// - Main remaining leads are table-symbol ownership, local-home coloring,
//   and the final x87 score-compare form.
// - Acceptance blocker: during score division by target hit points, the
//   executable keeps the numerator in x87 extended precision across the
//   hit-point test and uses FXCH/FDIV. The rebuild spills the numerator to a
//   32-bit float home before division. Boundary scores can select a different
//   target. The rebuild still differs in the related x87 spill and branch
//   topology.
// - BINARY NOTE: the current-target distance score is divided only when the
//   float distance is positive. This restores the +15665 guard and its two
//   denominator paths; the second scan uses distance only for range filtering.
// - Canonical prefix through this owner emits the same bytes as its standalone
//   build. The authentic score and x87 context does not change this function.
//   PDB FPO proves the public virtual UAE owner.
// - PDB and the 49 ordered calls prove this owner is bestUnitToAttack, not update.
// - Inclusive outer bounds and the candidate hit-point local improved structure.
//   Other x87, local-reuse, and ABI probes were restored when they moved bytes
//   farther from the executable.

extern int DAT_0087d7c8[5];
extern VisibleUnitEntry* DAT_0087d7e0[5];

int UnitAIModule::bestUnitToAttack(int param_1, int param_2, float* param_3)
{
    float numberMovingTargets;
    int numberDamagingUnits;
    int largestThreatIsBuilding;
    int currentTargetIsBuilding;
    int i;
    int j;
    RGE_Game_World* world;
    int difficulty;
    int maxReactDistance;
    int modifier;
    int numberNonCurrentTargets;
    int currentTargetIsWall;
    int numberObjectsInRange;
    int closestEnemyDistance;
    float enemyDistance;
    float distance;
    int currentTarget;

    this->search();
    difficulty = this->objectValue->owner->world->difficultyLevel();

    if (((rge_base_game->scenarioGame() == 1) &&
         (rge_base_game->singlePlayerGame() == 1) &&
         (difficulty >= 3) && (this->objectValue->owner->id != 1)) ||
        ((rge_base_game->singlePlayerGame() == 1) &&
         (difficulty >= 3) && (this->objectValue->owner->type == 3) &&
         ((this->objectValue->owner->strategicNumber(0xDB) != 100) ||
          (this->objectValue->owner->strategicNumber(0xDA) != 100)))) {
        if (this->objectValue->owner->id > 1) {
            if (difficulty == 3) {
                maxReactDistance = this->objectValue->owner->strategicNumber(0xDB);
            } else {
                maxReactDistance = this->objectValue->owner->strategicNumber(0xDA);
            }
        } else {
            maxReactDistance = difficulty == 3 ? 75 : 50;
        }
        modifier = (int)((float)maxReactDistance *
                         this->objectValue->master_obj->field_28 * DAT_0056ebc4);
        if (modifier < 1) {
            modifier = 1;
        }
    } else {
        modifier = ((int)this->objectValue->master_obj->field_28) * 2;
    }

    numberNonCurrentTargets = -1;
    world = this->objectValue->owner->world;
    numberMovingTargets = 0;
    currentTargetIsBuilding = 0;
    numberObjectsInRange = 0;

    if (this->currentTargetValue != -1) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target != 0 && target->master_obj->object_group == 0x1B) {
            numberObjectsInRange = 1;
        }
    }

    numberDamagingUnits = 0;
    largestThreatIsBuilding = 0;
    currentTargetIsWall = 0;
    enemyDistance = 100000.0f;
    closestEnemyDistance = 0;
    currentTarget = -1;

    for (i = 4; i >= 2; --i) {
        j = 0;
        if (DAT_0087d7c8[i] > 0) {
            do {
                RGE_Static_Object* target =
                    world->object(DAT_0087d7e0[i][j].object_id);
                if (target != 0 && target->object_state <= 2 &&
                    this->objectValue->owner->isAlly(target->owner->id) != 1 &&
                    target->inside_obj == 0 &&
                    ((param_1 != 0 && numberObjectsInRange != 0) ||
                     target->master_obj->object_group != 0x1B) &&
                    ((target->master_obj->object_group != 3 ||
                      target->hitPoints > 1.0f ||
                      (this->objectValue->master_obj->id != 0x23 &&
                       this->objectValue->master_obj->id != 0x24))) &&
                    this->canAttackUnit(target) != 0 &&
                    (i != 3 ||
                     this->canAttackUnitAtNeutrality(
                         target->master_obj->object_group) != 0)) {
                    distance = this->objectValue->distance_to_object(target);
                    if (this->objectValue->minimumWeaponRange() <= distance &&
                        modifier >= DAT_0087d7e0[i][j].distance) {
                        if (target->id != this->currentTargetValue) {
                            ++currentTargetIsWall;
                        }
                        if (target->master_obj->object_group != 3) {
                            ++numberDamagingUnits;
                        }
                        if (target->damageCapability() > DAT_0056ebc8) {
                            ++largestThreatIsBuilding;
                        }
                        if (target->master_obj->object_group != 3) {
                            if (distance <
                                this->objectValue->weaponRange() - DAT_0056ebd4) {
                                ++closestEnemyDistance;
                            }
                            if (distance < enemyDistance) {
                                currentTarget = target->id;
                                enemyDistance = distance;
                            }
                        }
                    }
                }
                ++j;
            } while (j < DAT_0087d7c8[i]);
        }
    }

    if (this->currentTargetValue != -1 && param_2 == 0 &&
        this->currentActionValue == 600) {
        RGE_Static_Object* target =
            this->lookupObject(this->currentTargetValue);
        if (target != 0) {
            int x = (int)target->world_x;
            int y = (int)target->world_y;
            unsigned char visible = this->visibleStatus(
                this->objectValue->owner->visible, y, x);
            if (currentTargetIsWall != 0) {
                if (visible != 0x0F) {
                    goto skipCurrentTarget;
                }
                if (this->objectValue->inAttackRange(target) != 1 &&
                    this->objectValue->canPath(
                    this->currentTargetValue,
                        this->objectValue->weaponRange(), 0, 0, -1, -1) != 1) {
                    goto skipCurrentTarget;
                }
            }
            target = world->object(this->currentTargetValue);
            if (target != 0 && target->object_state == 2 &&
                this->objectValue->owner->isAlly(target->owner->id) == 0) {
                if (target->master_obj->id == 0x114) {
                    return target->id;
                }
                numberNonCurrentTargets = this->currentTargetValue;
                numberMovingTargets = target->damageCapability() * DAT_0056ebd8;
                numberObjectsInRange =
                    target->master_obj->calc_base_damage_ability(
                        (RGE_Master_Combat_Object*)this->objectValue->master_obj);
                numberMovingTargets =
                    (float)numberObjectsInRange * DAT_0056ebc0 + numberMovingTargets;
                if (target->hitPoints > DAT_0056ebc8) {
                    numberMovingTargets /= target->hitPoints;
                }
                distance = target->distance_to_object(this->objectValue);
                if (distance > DAT_0056ebc8) {
                    if (numberDamagingUnits < 2) {
                        numberMovingTargets /= distance;
                    } else {
                        numberMovingTargets /=
                            (float)numberDamagingUnits * distance * DAT_0056ebdc;
                    }
                }
                if (target->master_obj->object_group != 3) {
                    ++numberDamagingUnits;
                    currentTargetIsBuilding = 0;
                } else {
                    currentTargetIsBuilding = 1;
                }
                if (target->damageCapability() > DAT_0056ebc8) {
                    ++largestThreatIsBuilding;
                }
            }
        }
    }

skipCurrentTarget:
    if (numberDamagingUnits > 1) {
        RGE_Static_Object* target = world->object(currentTarget);
        if (target != 0) {
            if (this->objectValue->inAttackRange(target) == 1) {
                return currentTarget;
            }
            if (this->objectValue->canPath(
                    currentTarget,
                        this->objectValue->weaponRange(), 0, 0, -1, -1) == 1) {
                return currentTarget;
            }
        }
    }

    for (i = 4; i >= 2; --i) {
        j = 0;
        if (DAT_0087d7c8[i] > 0) {
            do {
                RGE_Static_Object* target =
                    world->object(DAT_0087d7e0[i][j].object_id);
                if (target != 0 && target->object_state <= 2 &&
                    this->objectValue->owner->isAlly(target->owner->id) != 1 &&
                    target->inside_obj == 0 &&
                    ((param_1 != 0 && numberObjectsInRange != 0) ||
                     target->master_obj->object_group != 0x1B) &&
                    ((target->master_obj->object_group != 3 ||
                      target->hitPoints > 1.0f ||
                      (this->objectValue->master_obj->id != 0x23 &&
                       this->objectValue->master_obj->id != 0x24))) &&
                    this->canAttackUnit(target) != 0 &&
                    (i != 3 ||
                     this->canAttackUnitAtNeutrality(
                         target->master_obj->object_group) != 0)) {
                    float distance = this->objectValue->distance_to_object(target);
                    if (this->objectValue->minimumWeaponRange() <= distance &&
                        modifier >= DAT_0087d7e0[i][j].distance &&
                        (param_2 != 1 || this->objectValue->inAttackRange(target) != 0)) {
                        if (param_2 == 0 && this->objectValue->inAttackRange(target) == 0 &&
                            this->objectValue->canPath(
                                DAT_0087d7e0[i][j].object_id,
                                    this->objectValue->weaponRange(), 0, 0, -1, -1) == 0) {
                            goto skipTarget;
                        }
                        float threat = target->damageCapability() * DAT_0056ebd8;
                        if (largestThreatIsBuilding <= 0 || threat != DAT_0056ebc8) {
                            float score =
                                (float)target->master_obj->calc_base_damage_ability(
                                    (RGE_Master_Combat_Object*)this->objectValue->master_obj) * DAT_0056ebc0 +
                                threat;
                            float hitPoints = target->hitPoints;
                            if (hitPoints > DAT_0056ebc8) {
                                score /= hitPoints;
                            }
                            if (DAT_0087d7e0[i][j].distance != 0) {
                                score /= (float)DAT_0087d7e0[i][j].distance;
                            }
                            if (numberDamagingUnits > 1) {
                                int distanceValue =
                                    DAT_0087d7e0[i][j].distance;
                                score /= (float)(distanceValue * distanceValue *
                                                  distanceValue);
                            }
                            int group = target->master_obj->object_group;
                            if (numberNonCurrentTargets == -1 ||
                                ((currentTargetIsBuilding != 0 || group != 3) &&
                                 (numberNonCurrentTargets == -1 ||
                                  ((currentTargetIsBuilding == 1 && group != 3) ||
                                   (float)score >
                                       (float)numberMovingTargets)))) {
                                numberNonCurrentTargets =
                                    DAT_0087d7e0[i][j].object_id;
                                currentTargetIsBuilding = (group == 3);
                                numberMovingTargets = score;
                            }
                        }
                    }
                }

skipTarget:
                ++j;
            } while (j < DAT_0087d7c8[i]);
        }
    }

    return numberNonCurrentTargets;
}

// --- matching/00415A10_mostDangerousEnemy.cpp ---
// VA: 00415A10 UnitAIModule::mostDangerousEnemy
// aiuaimod.cpp
// Retry 2026-05-26: rebuilt full behavior with lookupObject, objectValue virtual threat calls, FPU compare, and outThreat store.
// Best result: exact size 188B, MISMATCH 73 positional / 20 edit bytes, first mismatch +40.
// Tried 10 variants: nested virtual call vs temp float, explicit actionObj local, owner local, master local order, threat2 short vs int,
// direct global id expression vs id temp, idx temp for best update, objectValue direct reload vs saved local, and loop/source order changes.
// Left in scratch: remaining drift is localized codegen/register coloring and one-byte branch-distance shifts in the per-object threat block:
// rebuilt keeps master in EDI and vtable in EBX while original keeps master in EBX and vtable in EDI; update block loads global/index in
// opposite order. Behavior/calls/stack cleanup/FPU compare look equivalent, but not proposing accepted_drift because drift spans register
// allocation throughout the central virtual-call block rather than a tiny isolated encoding difference.
// Luna415A10 pass: baseline rebuilt to 189B under the stricter boundary/call checker; old 188B cache
// had truncated the final ret operand. Direct loop-index ID spelling was codegen-duplicate.
// Unified objectValue/target as the proven polymorphic RGE_Static_Object surface and typed owner as
// RGE_Player*; both were codegen-duplicate. A focused central lab showed direct master/owner member
// access is the clean best source: 68 positional / 13 edit bytes, 98.53% shape, 189B.
// Update-order lab found pointer-local and volatile-index forms alter the prologue; the volatile-index
// probe regressed to 84 bytes. Restored the direct nonvolatile ID expression; remaining drift is the
// two independent update-block loads (original index-before-global, rebuilt global-before-index).
// Main-agent audit replaced literal absolute dereferences with the established shared globals and
// modeled the 8-byte lookup entry. That natural declaration context recovered exact load order,
// register allocation, branch distances, and 188/188-byte equality.


struct UnitAIObjectEntry {
    int object_id;
    int unknown;
};

int UnitAIModule::mostDangerousEnemy(float* outThreat) {
    search();

    int best = -1;
    float bestThreat = 0.0f;
    int i = 0;
    if ((int)DAT_0087d7d8 > 0) {
        do {
            RGE_Static_Object* obj = lookupObject(((UnitAIObjectEntry*)DAT_0087d7f0)[i].object_id);
            if (obj) {
                float f = objectValue->calculateDamage(
                    ((RGE_Master_Combat_Object*)obj->master_obj)->weapon_num,
                    ((RGE_Master_Combat_Object*)obj->master_obj)->weapon,
                    objectValue->calc_attack_modifier(obj, obj->owner, obj));
                if (best == -1 || f > bestThreat) {
                    bestThreat = f;
                    best = ((UnitAIObjectEntry*)DAT_0087d7f0)[i].object_id;
                }
            }
            i++;
        } while (i < (int)DAT_0087d7d8);
    }

    if (outThreat) {
        *outThreat = bestThreat;
    }
    return best;
}

// --- matching/00415AD0_weakestEnemy.cpp ---
// VA: 00415AD0 UnitAIModule::weakestEnemy
// MATCHED: declare/init bestHp before the loop index. With `float bestHp = 0.0f; int i = 0;`
// VC5 emits `xor esi,esi; mov dword [esp+0Ch],0; test eax,eax`; declaring i first makes it
// reuse ESI for the zero store after the count test and shifts the loop by 4 bytes.
// Previous scratch state had behavior/calls/FPU compare modeled but drifted from that store order.


int UnitAIModule::weakestEnemy(float* outHp) {
    this->search();
    int bestId = -1;
    float bestHp = 0.0f;
    int i = 0;
    if ((int)DAT_0087d7d8 > 0) {
        do {
            int id = *(int*)((char*)DAT_0087d7f0 + i * 8);
            RGE_Static_Object* obj = this->lookupObject(id);
            if (obj != 0) {
                if (bestId == -1 || obj->hitPoints < bestHp) {
                    bestHp = obj->hitPoints;
                    bestId = *(int*)((char*)DAT_0087d7f0 + i * 8);
                }
            }
            i++;
        } while (i < (int)DAT_0087d7d8);
    }
    if (outHp != 0) {
        *outHp = bestHp;
    }
    return bestId;
}

// --- matching/00415B50_closestAttacker.cpp ---
// VA: 00415B50 UnitAIModule::closestAttacker (328B)
// aiuaimod.cpp:2579-2600
//
// Attempt log:
// - Replaced the former placeholder with the binary-supported attacking-units
//   ManagedArray<int> surface, owner/world object lookup, distance comparison,
//   selected-ID tracking, and optional float output.
// - Baseline: period utmarray.h inline operator[] growth body and a positive-
//   count do/while scan; exact call set, but the distance local was optimized
//   into the x87 stack and the frame was four bytes short.
// - Promoted distance to a function-scope local and reversed selected-ID versus
//   threshold assignment order. This restored the separate FPU spill, frame,
//   CFG, call-site relocations, and all late blocks.
// - A volatile-distance diagnostic confirmed the spill cause but was removed.
//   Declaration/init permutations and a focused six-case init-order lab did not
//   produce the oracle's store order.
// - Reordered the local declarations to selected ID, threshold, loop index,
//   distance, matching the same-TU weakestEnemy donor's declaration style. This
//   preserved the natural source and emitted the oracle's sentinel-before-zero
//   stores exactly: MATCH (328/328 bytes, 6/6 calls, default flags).


int UnitAIModule::closestAttacker(float* attackDistance) {
    int attackObject;
    float largestThreat;
    int i;
    float distance;

    attackObject = -1;
    largestThreat = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (object != 0) {
                distance = this->objectValue->distance_to_object(object);
                if (attackObject == -1 || distance < largestThreat) {
                    attackObject = this->attackingUnitsValue[i];
                    largestThreat = distance;
                }
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    if (attackDistance != 0)
        *attackDistance = largestThreat;
    return attackObject;
}

// --- matching/00415CA0_closestObject.cpp ---
// VA: 00415CA0 UnitAIModule::closestObject (420B)
// aiuaimod.cpp:2606-2741
//
// Attempt log:
// - Replaced the placeholder with the binary-supported visible-unit bucket
//   scan, per-player marker array, owner/object/type filters, closest-distance
//   selection, global visibility count, and optional output conversion.
// - Baseline uses named typed visible-unit records and the period UnitAIModule
//   search/evasive virtual surfaces; retain later probe notes after compiling.
// - Reusing objectsOfPlayer[0] as a saved-this alias reproduced the oracle's
//   0x30 frame, but main-agent audit rejected that parameter-home compiler
//   steering. The living source keeps direct this access and canonical player
//   marker ownership even though VC5 uses a less favorable frame basin.
// - Reversed closest-ID/distance assignment order, reused loop indices, and
//   tested typed DAT_0087d7c8/DAT_0087d7e0 table declarations; none changed the
//   remaining schedule. Absolute-address table macros and cached self/object
//   temporaries worsened the frame or block shape and were rolled back.
// - Main-agent normalization to a nine-entry, directly indexed player-marker
//   array unexpectedly recovered the final scheduling hunk: exact 420-byte
//   MATCH with the complete 3/3 ordered call sequence.


extern int DAT_0087d7c8[5];
extern VisibleUnitEntry* DAT_0087d7e0[5];
extern int numberDifferentPlayerObjectsVisible;

int UnitAIModule::closestObject(int param_1, int param_2, int param_3,
                                int param_4, int* param_5) {
    int objectsOfPlayer[9];
    this->search();

    int i;
    for (i = 0; i < 9; ++i)
        objectsOfPlayer[i] = 0;

    int closestObjectID = -1;
    float closestDistance = -1.0f;

    int category;
    for (category = 0; category <= 4; ++category) {
        i = 0;
        if (DAT_0087d7c8[category] > 0) {
            do {
                objectsOfPlayer[DAT_0087d7e0[category][i].owner] = 1;
                if (this->objectValue->id !=
                    DAT_0087d7e0[category][i].object_id) {
                    RGE_Static_Object* object =
                        this->objectValue->owner->world->object(
                            DAT_0087d7e0[category][i].object_id);
                    if (object != 0 && object->object_state < 7) {
                        if ((param_2 != 0 || category == 2 || category == 1) &&
                            (param_2 != 2 || category == 4) &&
                            (param_2 != 3 || category == 1) &&
                            (param_2 != 1 || category == 3) &&
                            (param_1 == -1 ||
                             object->master_obj->object_group == param_1) &&
                            (param_4 == -1 || object->master_obj->id == param_4) &&
                            (param_3 == -1 || object->object_state == param_3)) {
                            if (closestObjectID == -1 ||
                                (float)DAT_0087d7e0[category][i].distance < closestDistance) {
                                closestObjectID = DAT_0087d7e0[category][i].object_id;
                                closestDistance = (float)DAT_0087d7e0[category][i].distance;
                            }
                        }
                    }
                }
                ++i;
            } while (i < DAT_0087d7c8[category]);
        }
    }

    numberDifferentPlayerObjectsVisible = 0;
    for (i = 1; i < 9; ++i) {
        if (objectsOfPlayer[i] == 1)
            ++numberDifferentPlayerObjectsVisible;
    }

    if (param_5 != 0)
        *param_5 = (int)closestDistance;
    return closestObjectID;
}

// --- matching/00415E50_closestResourceObject.cpp ---
// VA: 00415E50 UnitAIModule::closestResourceObject (235B)
// aiuaimod.cpp
//
// Canonical reconstruction: query the owning player's visible-resource list,
// rejecting already-tested resources until the object's path test succeeds.
// The 100-entry list is initialized to the historical 0x80000000 sentinel;
// the resource distance is returned through the optional integer output.
//
// Attempt log:
// - Replaced the stale placeholder with the binary-supported visible-resource
//   query, object path gate, distance check, and reject-list behavior.
// - A do/infinite-loop spelling caused VC5 to peel the first query; the
//   bounded while form restored one shared call site and the original CFG.
// - Naming the append cursor and incrementing the reject count before storing
//   the rejected ID reproduced the original EBP/EDI update order. MATCH.

extern float DAT_0056ebe0;


int UnitAIModule::closestResourceObject(int resourceType, int* distance) {
    int excludeList[100];
    int* nextExclude = excludeList;
    for (int i = 0; i < 100; ++i) {
        excludeList[i] = 0x80000000;
    }

    int excludeCount = 0;
    VISIBLE_RESOURCE_REC* resource;
    while (excludeCount < 100) {
        resource = this->objectValue->owner->VR_List->Get_Closest_Resource(
            (int)this->objectValue->world_x,
            (int)this->objectValue->world_y,
            this->objectValue->currentZone(),
            resourceType,
            excludeList,
            excludeCount);
        if (resource == 0) {
            return -1;
        }

        if ((float)resource->distance >
            this->objectValue->master_obj->los - DAT_0056ebe0) {
            return -1;
        }

        if (this->objectValue->canPath(resource->object_id, 1.0f, 0, 0, -1,
                                       -1) == 1) {
            break;
        }

        ++excludeCount;
        *nextExclude++ = resource->object_id;
    }

    if (distance != 0) {
        *distance = resource->distance;
    }
    return resource->object_id;
}

// --- matching/00415F40_closestUndiscoveredTile.cpp ---

extern int __cdecl debug_rand(char* param_1, int param_2);

int UnitAIModule::closestUndiscoveredTile(int* param_1, int* param_2, int param_3) {
    RGE_Static_Object* object;
    RGE_Visible_Map* visible;
    RGE_Map* map;
    unsigned char currentZone;
    int bestDistance;
    int currX;
    int currY;
    int searchRadius;
    int lowX;
    int highX;
    int highY;
    int lowY;
    int x;
    int y;
    int distance;

    if (this->currentOrderValue == 0x2C1) {
        if (this->currentTargetXValue != -1.0f) {
            if (this->currentTargetYValue != -1.0f) {
                return 0;
            }
        }
    }

    object = this->objectValue;
    bestDistance = -1;
    currX = (int)object->world_x;
    currY = (int)object->world_y;
    searchRadius = (int)object->master_obj->los + 3;
    lowX = (int)(object->world_x - (float)searchRadius);
    highX = (int)(object->world_x + (float)searchRadius);
    lowY = (int)(object->world_y - (float)searchRadius);
    highY = (int)(object->world_y + (float)searchRadius);
    map = object->owner->world->map;
    visible = object->owner->visible;

    if (lowX < 0) {
        lowX = 0;
    }
    if (highX > map->map_width - 1) {
        highX = map->map_width - 1;
    }
    if (lowY < 0) {
        lowY = 0;
    }
    if (highY > map->map_height - 1) {
        highY = map->map_height - 1;
    }

    const int randSelect = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\aiuaimod.c", 0xB2E) % 3;
    currentZone = this->objectValue->currentZone();

    for (y = lowY; y <= highY; ++y) {
        for (x = lowX; x <= highX; ++x) {
            if (this->visibleStatus(visible, x, y) == 0) {
                if (currentZone == this->objectValue->lookupZone(x, y)) {
                    if (this->objectValue->passableTile((float)x, (float)y, 0) != 0) {
                        if ((param_3 == 0) || (this->inWaypointQueue(x, y) == 0)) {
                            distance = (x - currX) * (x - currX) + (y - currY) * (y - currY);
                            if (this->currentTargetXValue != -1.0f) {
                                distance =
                                    (x - (int)this->currentTargetXValue) * (x - (int)this->currentTargetXValue) +
                                    distance +
                                    (y - (int)this->currentTargetYValue) * (y - (int)this->currentTargetYValue);
                            }
                            if ((bestDistance == -1) || (bestDistance + randSelect > distance)) {
                                bestDistance = distance;
                                *param_1 = x;
                                *param_2 = y;
                            }
                        }
                    }
                }
            }
        }
    }
    if (bestDistance != -1) {
        XYZPoint point;

        object = this->objectValue;
        point.x = *param_1;
        point.y = *param_2;
        point.z = (int)object->world_z;
        return object->canPathPoint(point, object->master_obj->los - 1.0f,
                                    -1, (float*)&param_1, 0, -1, -1);
    }

    return 0;
}

// --- matching/004161d0_waypoint.cpp ---

Waypoint* UnitAIModule::waypoint(int) const {
    return 0;
}

// --- matching/004161e0_waypointQueueSize.cpp ---

int UnitAIModule::waypointQueueSize() const {
    return this->waypointQueueSizeValue;
}

// --- matching/004161F0_addToWaypointQueue.cpp ---

int UnitAIModule::addToWaypointQueue(int param_1, int param_2) {
    if (this->waypointQueueSizeValue >= 8) {
        this->waypointQueueSizeValue = 0;
    }
    this->waypointQueue[this->waypointQueueSizeValue].x = (float)param_1;
    this->waypointQueue[this->waypointQueueSizeValue].y = (float)param_2;
    this->waypointQueueSizeValue = this->waypointQueueSizeValue + 1;
    return 1;
}

// --- matching/00416240_inWaypointQueue.cpp ---
// VA: 00416240 UnitAIModule::inWaypointQueue(int, int) const
// PDB source: aiuaimod.cpp lines 2971-2977 (80 bytes, 31 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (int x, int y). ret 8 cleanup.
// Exact with default flags after reshaping the loop tail.
// Key source shape: positive outer guard + `while (1)` loop with bottom
// `if (i < waypointQueueSize) continue; return 0;`, and y-match routed through
// `goto found;` so VC5 keeps the original `jl loop` backedge and places the
// loop-fail return before the success return while the early-empty return stays last.
// Tried first: natural do-while remained at 70/80 bytes equal with `jge exit; jmp loop` drift;
// direct `return 1` in the while/continue shape kept that same drift. The goto-found tail matched.
// Waypoint struct: 0x10 bytes (float x,y,z + 1 byte), array at this+0x70, size at this+0xF0.


int UnitAIModule::inWaypointQueue(int x, int y) const {
    int i = 0;
    if (waypointQueueSizeValue > 0) {
        float fx = (float)x;
        while (1) {
            if (waypointQueue[i].x == fx) {
                if ((float)y == waypointQueue[i].y) goto found;
            }
            i++;
            if (i < waypointQueueSizeValue) continue;
            return 0;
        }
found:
        return 1;
    }
    return 0;
}

// --- matching/00416290_clearWaypointQueue.cpp ---

void UnitAIModule::clearWaypointQueue() {
    this->waypointQueueSizeValue = 0;
}

// --- matching/004162a0_canAttackUnit.cpp ---

int UnitAIModule::canAttackUnit(RGE_Static_Object*) {
    return 1;
}

// --- matching/004162b0_canAttackUnitAtNeutrality.cpp ---

int UnitAIModule::canAttackUnitAtNeutrality(int) {
    return 1;
}

// --- matching/004162C0_stopObject.cpp ---
// VA: 004162C0 stopObject (118B)
// aiuaimod.cpp
//
// Attempt log:
// - Existing scratch was a near match (2 bytes diff): saving currentOrderValue into an `order` local before
//   storing currentOrderValue=-1 made VC5 use eax for the copied value, while original reloads through ecx in
//   the reset block.
// - SpruceGlow try 1 MATCH: assign `lastOrderValue = currentOrderValue;` directly before `currentOrderValue = -1`.
//   This lets VC5 use ecx for the member reload/store pair exactly as original.
// Result: MATCH locally with `python tools/check_function.py --va 004162C0`.


extern FILE* actionFile;


int UnitAIModule::stopObject(int param) {
    if (actionFile != 0) {
        fprintf(actionFile, "t%ld, U#%d sO, cOAA=%d.\n",
            objectValue->owner->world->world_time,
            objectValue->id,
            param);
    }

    lastActionValue = currentActionValue;
    if (param == 0 || currentActionValue + 100 == currentOrderValue) {
        lastOrderValue = currentOrderValue;
        currentOrderValue = -1;
        currentOrderPriorityValue = -1;
    }

    objectValue->stopAction();
    currentActionValue = -1;
    return 1;
}

// --- matching/00416340_attackObject.cpp ---
// 00416340 UnitAIModule::attackObject

int UnitAIModule::attackObject(int targetId, int flag) {
    if (flag != 0 || this->currentActionValue == -1) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->objectValue->attack(targetId, flag) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetId, target->world_x,
                                           target->world_y, target->world_z);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// --- matching/004163C0_attackRoundupObject.cpp ---
// VA: 004163C0 UnitAIModule::attackRoundupObject
// aiuaimod.cpp

int UnitAIModule::attackRoundupObject(int targetId) {
    if (this->currentTargetValue != targetId) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->currentActionValue != -1) {
                    if (!this->objectValue->canPath(
                            targetId, this->objectValue->weaponRange(), 0, 0,
                            -1, -1)) {
                        return 0;
                    }
                }
                if (this->objectValue->attack(targetId, 1) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetId, target->world_x,
                                           target->world_y, target->world_z);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// --- matching/00416470_huntObject.cpp ---
// VA: 00416470 huntObject (211B)
// aiuaimod.cpp:3134-3160
//
// Binary-supported source reconstruction:
// - objectValue is at +04 and currentActionValue at +30.
// - UnitAIModule::stopObject is virtual slot +58.
// - objectValue's can-hunt operation is virtual slot +164.
// - A successful lookup supplies target group and world coordinates to the
//   five-argument setCurrentTarget helper; a null lookup uses -1 and zeros.
//
// Attempt log:
// - Baseline: natural typed reconstruction reached the exact size/frame/call
//   surface; only the logging null-test block was laid out with the opposite
//   branch polarity.
// - Inverted the logging test to keep the non-null ID load in the fallthrough
//   block and the null -1 assignment in the late JE target. MATCH.


extern FILE* actionFile;


int UnitAIModule::huntObject(int param_1, int param_2) {
    if (param_2 != 0 || this->currentActionValue != 0x265) {
        if (actionFile != 0) {
            long object_id;
            if (this->objectValue != 0) {
                object_id = this->objectValue->id;
            } else {
                object_id = -1;
            }
            fprintf(actionFile,
                    "#%d call stopObject %s %d\n",
                    object_id,
                    "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp",
                    0xC48);
        }

        this->stopObject(1);
        if (this->objectValue->hunt(param_1, param_2) == 1) {
            RGE_Static_Object* target =
                this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x265);

            if (target == 0) {
                this->setCurrentTarget(param_1, -1, 0, 0, 0);
            } else {
                this->setCurrentTarget(param_1,
                                       (int)target->master_obj->object_group,
                                       target->world_x,
                                       target->world_y,
                                       target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

// --- matching/00416550_convertObject.cpp ---
// VA: 00416550 convertObject (148B)
// Based on matched gatherObject/buildObject siblings.
// Sibling pattern: inverted condition, nested success, shared return-0 tail.


int UnitAIModule::convertObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x25C) {
        int result = objectValue->convert(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x25C);

            if (target == 0) {
                setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetId, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

// --- matching/004165F0_healObject.cpp ---
// UnitAIModule::healObject — action wrapper
// VA: 004165F0


int UnitAIModule::healObject(int targetId, int flag)
{
    if (flag || this->currentActionValue != 0x25B) {
        RGE_Static_Object* unit = this->objectValue;
        if (unit->heal(targetId, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x25B);
            if (target == 0) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416690_gatherObject.cpp ---
// VA: 00416690 gatherObject (148B)
// Fully typed approach


int UnitAIModule::gatherObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x261) {
        int result = objectValue->gather(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x261);

            if (target == 0) {
                setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetId, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

// --- matching/00416730_repairObject.cpp ---
// UnitAIModule::healObject — action wrapper
// VA: 00416730


int UnitAIModule::repairObject(int targetId, int flag)
{
    if (flag || this->currentActionValue != 0x26A) {
        RGE_Static_Object* unit = this->objectValue;
        if (unit->repair(targetId, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x26A);
            if (target == 0) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// --- matching/004167D0_buildObject.cpp ---
// VA: 004167D0 buildObject (148B)
// Based on matched gatherObject sibling; action 0x25A and vcall +0x174.
// Attempt log:
// try 1: replaced raw helper shim with typed/nested-success form from matched gatherObject.


int UnitAIModule::buildObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x25A) {
        int result = objectValue->build(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x25A);

            if (target == 0) {
                setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetId, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

// --- matching/00416870_tradeWithObject.cpp ---
// 00416870 UnitAIModule::tradeWithObject(int, int)
// PDB: aiuaimod.cpp lines 3285-3304 (148 B, 62 asm)
// FLAGS: default
// MATCH: 0.0000% (148/148 bytes exact)
//
// Key insights:
// - tradeWithObject IS virtual (UAEH mangling), giving class a vtable pointer at +0x00
// - canTrade at vtable+0x178 = slot 94: need 94 filler virtual slots via __declspec(novtable)
// - Inverted condition: if(flag || action != 267) { if(canTrade==1) { ... } else return0; } else return0;
//   This forces VC5 to use shared return-0 epilogue instead of inline


int UnitAIModule::tradeWithObject(int targetId, int flag)
{
    if (flag != 0 || this->currentActionValue != 0x267) {
        int r = this->objectValue->trade(targetId, flag);
        if (r == 1) {
            RGE_Static_Object* target =
                this->objectValue->owner->world->object(targetId);

            this->setCurrentAction(0x267);

            if (!target) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                int grp = target->master_obj->object_group;
                this->setCurrentTarget(targetId, grp, target->world_x,
                                       target->world_y, target->world_z);
            }

            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// --- matching/00416910_explore.cpp ---
// VA: 00416910 UnitAIModule::explore (101 B)
// PDB source: aiuaimod.cpp lines 3309-3322


int UnitAIModule::explore(int param_1, int param_2, int param_3)
{
    if (param_3 != 0 || this->currentActionValue == -1) {
        if (this->objectValue->explore(param_1, param_2, param_3) == 1) {
            this->setCurrentAction(0x25D);
            this->setCurrentTarget(-1, (float)param_1, (float)param_2, 1.0f);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416980_enterObject.cpp ---

int UnitAIModule::enterObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->enter(param_1, param_2) == 1) {
            this->setCurrentAction(0x269);
            this->setCurrentTarget(param_1, -1.0f, -1.0f, -1.0f);
            return 1;
        }
    }
    return 0;
}

// --- matching/004169E0_transportObject.cpp ---

int UnitAIModule::transportObject(float param_1, float param_2, float param_3, int param_4) {
    if ((param_4 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->transport(param_1, param_2, param_3, param_4) == 1) {
            this->setCurrentAction(0x266);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416A50_unload.cpp ---
// 00416A50 UnitAIModule::unload
// aiuaimod.cpp lines 3364-3381


int UnitAIModule::unload(int id, float x, float y)
{
    if (id || this->currentActionValue == -1) {
        RGE_Static_Object* obj = this->objectValue;
        if (obj->unload(id, x, y, obj->world_z) == 1) {
            RGE_Static_Object* target = this->objectValue;
            this->setCurrentAction(0x26D);
            if (target == 0) {
                this->setCurrentTarget(this->objectValue->id, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(this->objectValue->id, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416AF0_moveTo.cpp ---
// VA: 00416AF0 UnitAIModule::moveTo
// aiuaimod.cpp lines 3386-3404
//
// Attempt log:
// - Initial scratch was a free-function/raw-call implementation and not in the right thiscall/member-call surface.
// - Natural member-call source nearly matched immediately, but the first local layout had objectValue/currentActionValue
//   shifted by +4. Correcting UnitAIModule so objectValue is at +0x04 and currentActionValue at +0x30 produced exact code.
// Result: MATCH locally with `python tools/check_function.py --va 00416AF0`.


int UnitAIModule::moveTo(int targetId, int flag) {
    if (flag || this->currentActionValue == -1) {
        if (this->objectValue->moveTo(targetId, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x262);
            if (target == 0) {
                this->setCurrentTarget(targetId, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416B80_moveTo.cpp ---
// VA: 00416B80 UnitAIModule::moveTo(int,float,int)
// aiuaimod.cpp lines 3410-3428
// Retry 2026-05-19: replace raw __fastcall/free-function body with natural member-call surface
// copied from matched 00416AF0 shape and adjusted for 3-arg virtual canMoveTo.


int UnitAIModule::moveTo(int targetId, float range, int flag) {
    if (flag || this->currentActionValue == -1) {
        if (this->objectValue->moveTo(targetId, range, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x262);
            if (target == 0) {
                this->setCurrentTarget(targetId, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416C10_moveTo.cpp ---

int UnitAIModule::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    int result;

    if (param_5 != 0 || this->currentActionValue == -1) {
        result = this->objectValue->moveTo(param_1, param_2, param_3, param_4, param_5);
        if (result == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}

// --- matching/00416C80_evasiveMoveTo.cpp ---
// VA: 00416C80 UnitAIModule::evasiveMoveTo (674 bytes)
// aiuaimod.cpp lines 3453-3514.
//
// Attempt log:
// - The old scratch was a decompiler-shaped raw-vtable version. It passed the
//   receiver explicitly, used the wrong unsigned absolute-value arithmetic for
//   the jitter, and introduced a second slot-114 call at the rotated loop tail.
// - Current reconstruction restores the period typed object surface, signed
//   power-of-two remainder expressions, direct map ownership, and positive
//   guard/ordinary top-tested retry structure. The two incoming float homes are
//   intentionally mutated because the oracle writes them at +4/+8.
// - Typed player/world/map ownership plus shared DAT_0056ebc8/DAT_0056ebd0
//   constants reproduce the direct FPU memory operands; immediate 0.0f stores
//   remain separate. Final check: MATCH, 674/674 bytes, default flags.


extern "C" int __cdecl debug_rand(const char* file, int line);

int UnitAIModule::evasiveMoveTo(float x, float y, float z, int flag)
{
    if (flag != 0 || this->currentActionValue == -1) {
        if (x < DAT_0056ebc8) {
            x = 0.0f;
        } else {
            if (x >= (float)this->objectValue->owner->world->map->map_width) {
                x = (float)this->objectValue->owner->world->map->map_width - DAT_0056ebd0;
            }
        }

        if (y < DAT_0056ebc8) {
            y = 0.0f;
        } else {
            if (y >= (float)this->objectValue->owner->world->map->map_height) {
                y = (float)this->objectValue->owner->world->map->map_height - DAT_0056ebd0;
            }
        }

        int i = 0;
        while (i < 5) {
            if (this->objectValue->passableTile(x, y, 0) == 1) {
                break;
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xD9F) % 2) {
                x += (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA0) % 4);
            } else {
                x -= (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA2) % 4);
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA3) % 2) {
                y += (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA4) % 4);
            } else {
                y -= (float)(debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA6) % 4);
            }

            if (x < DAT_0056ebc8) {
                x = 0.0f;
            } else {
                if (x >= (float)this->objectValue->owner->world->map->map_width) {
                    x = (float)this->objectValue->owner->world->map->map_width - DAT_0056ebd0;
                }
            }

            if (y < DAT_0056ebc8) {
                y = 0.0f;
            } else {
                if (y >= (float)this->objectValue->owner->world->map->map_height) {
                    y = (float)this->objectValue->owner->world->map->map_height - DAT_0056ebd0;
                }
            }
            ++i;
        }

        if (this->objectValue->moveTo(x, y, z, 0.0f, flag) == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, x, y, z);
            return 1;
        }
    }
    return 0;
}

// --- scratch/00416F30_intelligentEvasiveMoveTo.cpp ---
// VA: 00416F30 UnitAIModule::intelligentEvasiveMoveTo (666 bytes)
// aiuaimod.cpp:3520-3629
//
// BINARY NOTE: The target is the UnitAIModule owner in the aiuaimod.cpp
// sequence. Its point probe, path retry, publication, and failure exits stay
// in this source. The unusual x87 order follows the executable.
//
// BINARY NOTE: This owner follows 004151B0 in the PDB order. The shared
// UnitAIModule declaration keeps the qualified owner and the 00413AB0 update
// owner canonical. Do not replace it with a local vtable scaffold.
//
// BINARY NOTE: The target has a 0x14 frame, four saved registers, 220
// instructions, and ten ordered calls. The current clean source keeps these
// properties, but the checker still reports a 445-byte positional mismatch.
//
// Attempt log:
// - Positive and early-return guard forms emitted the same code.
// - Declaration scope and order, pointZ scope, register forceFlag, and typed
//   self/object aliases did not change the 445-byte codegen basin or lost the
//   canonical virtual calls.
// - A final point.z reread reduced the frame and worsened the CFG. The source
//   keeps pointZ because the original has a separate point-z home.
// - The canonical shared context changed no bytes, but it restored the real
//   UnitAIModule owner. No inline assembly, volatility, config, or shared-file
//   edits were used.


int UnitAIModule::intelligentEvasiveMoveTo(float x, float y, float z,
                                            int targetId, int forceFlag)
{
    float baseDistance;
    int facet;
    XYZPoint point;
    int pointZ;

    if (forceFlag == 0 && this->currentActionValue != -1) {
        return 0;
    }

    if (x < DAT_0056ebc8) {
        x = 0.0f;
    } else {
        if (x >= (float)this->objectValue->owner->world->map->map_width) {
            x = (float)this->objectValue->owner->world->map->map_width - DAT_0056ebd0;
        }
    }

    if (y < DAT_0056ebc8) {
        y = 0.0f;
    } else {
        if (y >= (float)this->objectValue->owner->world->map->map_height) {
            y = (float)this->objectValue->owner->world->map->map_height - DAT_0056ebd0;
        }
    }

    point.x = (int)x;
    point.y = (int)y;
    pointZ = (int)this->objectValue->world_z;
    point.z = pointZ;

    if (this->objectValue->canPathPoint(point, 1.0f, -1, 0, 0, -1, -1) == 0) {
        facet = -1;
        baseDistance = this->objectValue->distance_to_position(
            x, y, this->objectValue->world_z);

        while (1) {
            ++facet;

            switch (facet) {
            case 0:
                point.x -= 2;
                point.y -= 2;
                break;
            case 1:
            case 2:
                point.x += 2;
                break;
            case 3:
            case 4:
                point.y += 2;
                break;
            case 5:
            case 6:
                point.x -= 2;
                break;
            case 7:
                point.y -= 2;
                break;
            default:
                return 0;
            }

            if (point.x < 0) {
                point.x = 0;
            } else {
                int width = this->objectValue->owner->world->map->map_width;
                if (point.x >= width) {
                    point.x = width - 1;
                }
            }

            if (point.y < 0) {
                point.y = 0;
            } else {
                int height = this->objectValue->owner->world->map->map_height;
                if (point.y >= height) {
                    point.y = height - 1;
                }
            }

            if (targetId == 0 &&
                this->objectValue->distance_to_position(
                    (float)point.x - DAT_0056ebe4,
                    (float)point.y - DAT_0056ebe4,
                    this->objectValue->world_z) < baseDistance) {
                ++facet;
                continue;
            }

            if (this->objectValue->canPathPoint(point, 1.0f, -1, 0, 0, -1, -1) == 1) {
                break;
            }
        }
    }

    if (this->objectValue->moveTo(
            (float)point.x - DAT_0056ebe4,
            (float)point.y - DAT_0056ebe4,
            z, 0.5f, pointZ) == 1) {
        this->setCurrentAction(0x262);
        this->setCurrentTarget(-1, x, y, z);
        return 1;
    }

    return 0;
}

// --- matching/004171F0_runAwayFromAttackers.cpp ---
// VA: 004171F0 UnitAIModule::runAwayFromAttackers (357B)
// aiuaimod.cpp:3634-3678
//
// Attempt log:
// - Replaced the placeholder with the binary-supported early guard, attacking-
//   units ManagedArray<int> scan, world-object lookup, accumulated coordinate
//   deltas, float range getter, normalized retreat point, and evasiveMoveTo call.
// - Baseline below follows the exact same-TU typed surfaces and utmarray.h
//   inline growth body; initial body was 2 bytes over size and spilled the
//   range factor after the x87 sum.
// - Initializing xDiff/yDiff before the loop index restored the oracle's
//   immediate zero stores. Binding `range * 4.0f` at the maximumSpeed call kept
//   the scaled getter live through sqrt and reproduced the complete FPU tail.
//   MATCH (357/357 bytes, 5/5 calls, default flags).


#pragma intrinsic(sqrt)

int UnitAIModule::runAwayFromAttackers(int param_1) {
    if (param_1 == 0 && this->currentActionValue != -1)
        return 0;

    int i;
    float xDiff;
    float yDiff;

    xDiff = 0.0f;
    yDiff = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* attacker =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (attacker != 0) {
                xDiff += attacker->world_x - this->objectValue->world_x;
                yDiff += attacker->world_y - this->objectValue->world_y;
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    float range = this->objectValue->maximumSpeed() * 4.0f;
    float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

    return this->evasiveMoveTo(
        (float)(-((xDiff / distance) * range)) + this->objectValue->world_x,
        (float)(-((yDiff / distance) * range)) + this->objectValue->world_y,
        this->objectValue->world_z,
        1);
}

// --- matching/00417360_followObject.cpp ---
// VA: 00417360
// UnitAIModule::followObject(int param_1, float param_2, int param_3)
// Size: 108 bytes
// Source: aiuaimod.cpp lines 3684-3702

// Local stubs for types used by this function

int UnitAIModule::followObject(int param_1, float param_2, int param_3) {
    if (param_3 == 0 && this->currentActionValue != -1) {
        return 0;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x264);
    this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
    this->desiredTargetDistanceValue = param_2;
    return 1;
}

// --- matching/004173D0_defendObject.cpp ---
// target: VA 004173D0 UnitAIModule::defendObject(int,float,int)
// sibling of followObject; keep the early currentAction gate, world lookup, action/target calls, and final field stores


int UnitAIModule::defendObject(int id, float distance, int allow_when_busy) {
    RGE_Static_Object* target;

    if (allow_when_busy == 0 && this->currentActionValue != -1) {
        return 0;
    }

    target = this->objectValue->owner->world->object(id);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x259);
    this->setCurrentTarget(id, target->world_x, target->world_y, target->world_z);
    this->defendTargetValue = id;
    this->desiredTargetDistanceValue = distance;
    return 1;
}

// --- matching/00417440_defendPosition.cpp ---
// defendPosition: aiuaimod.cpp lines 3733-3747
// __thiscall, virtual (but we don't rely on virtual here)
// Direct transcription of original asm.
// Attempt 1: straightforward implementation with minimal stubs.


int UnitAIModule::defendPosition(float x, float y, float distance, int flag) {
    // Guard: if (flag == 0 && currentActionValue != -1) return 0;
    if (flag == 0 && this->currentActionValue != -1) {
        return 0;
    }

    // setCurrentAction(0x259)
    this->setCurrentAction(0x259);

    // setCurrentTarget(-1, x, y, this->objectValue->world_z)
    this->setCurrentTarget(-1, x, y, this->objectValue->world_z);

    // this->defendTargetValue = -1;
    this->defendTargetValue = -1;

    // this->desiredTargetDistanceValue = distance;
    this->desiredTargetDistanceValue = distance;

    return 1;
}

// --- matching/004174A0_seekAndDestroy.cpp ---

int UnitAIModule::seekAndDestroy(int param_1, int param_2, int param_3, int param_4) {
    if ((param_4 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->attack(param_1, param_4) == 1) {
            this->setCurrentAction(0x26E);
            this->setCurrentTarget(param_1, (float)param_2, (float)param_3, 1.0f);
            return 1;
        }
    }
    return 0;
}

// --- matching/00417510_exploreAndDestroy.cpp ---
// VA: 00417510 UnitAIModule::exploreAndDestroy(int, int, int)
// PDB source: aiuaimod.cpp lines 3772-3785
// Match: 101/101 bytes, 0.0000%


int UnitAIModule::exploreAndDestroy(int param_1, int param_2, int param_3) {
    if ((param_3 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->explore(param_1, param_2, param_3) == 1) {
            this->setCurrentAction(0x26F);
            this->setCurrentTarget(-1, (float)param_1, (float)param_2, 1.0f);
            return 1;
        }
    }
    return 0;
}

// --- matching/00417580_removeCurrentTarget.cpp ---

void UnitAIModule::removeCurrentTarget() {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    this->currentTargetXValue = -1.0f;
    this->currentTargetYValue = -1.0f;
    this->currentTargetZValue = -1.0f;
}

// --- matching/004175B0_setCurrentTarget.cpp ---

void UnitAIModule::setCurrentTarget(int id, float x, float y, float z) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = id;
    this->currentTargetXValue = x;
    this->currentTargetYValue = y;
    this->currentTargetZValue = z;

    RGE_Static_Object* object = this->objectValue->owner->world->object(id);
    if (object != 0) {
        this->currentTargetTypeValue = object->master_obj->object_group;
    }
}

// --- matching/00417600_setCurrentTarget.cpp ---

void UnitAIModule::setCurrentTarget(int id, int type, float x, float y, float z) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = id;
    this->currentTargetTypeValue = type;
    this->currentTargetXValue = x;
    this->currentTargetYValue = y;
    this->currentTargetZValue = z;
}

// --- matching/00417640_importantObject.cpp ---

int UnitAIModule::importantObject(int obj) {
    int i = 0;
    int count = this->numberImportantObjects;

    if (count <= 0) {
        return 0;
    }

    while (i < count) {
        if (this->importantObjects[i] == obj) {
            return 1;
        }
        i++;
    }

    return 0;
}

// --- matching/00417680_isEnemyOwner.cpp ---

int UnitAIModule::isEnemyOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 0;
    }
    return owner->relations[player_id] == 3;
}

// --- matching/004176B0_isAllyOwner.cpp ---
// compact ally-owner check first
// expected basin: resolve the unit owner, compare ids, then test the symmetric relation bytes


int UnitAIModule::isAllyOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 1;
    }
    if (owner->relations[player_id] == 0 && owner->world->players[player_id]->relations[owner->id] == 0) {
        return 1;
    }
    return 0;
}

// --- matching/00417700_isNeutralOwner.cpp ---

int UnitAIModule::isNeutralOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 0;
    }
    return owner->relations[player_id] == 1;
}

// --- matching/00417730_visibleStatus.cpp ---
// VA: 00417730 UnitAIModule::visibleStatus (60B)
// PDB source: aiuaimod.cpp lines 3900-3910
// __thiscall with 3 params: RGE_Visible_Map* param_1, int param_2 (x), int param_3 (y)
// ret 0Ch = 3 params cleaned.
// Similar to get_visible but accessed via this->objectValue->owner instead of direct player.
// Use #define for absolute address, load-order matching, branch-free explored path.

#define unified_map_offsets ((unsigned long**)0x886808)


unsigned char UnitAIModule::visibleStatus(class RGE_Visible_Map* param_1, int param_2, int param_3) {
    unsigned long cell = unified_map_offsets[param_3][param_2];
    RGE_Player* owner = this->objectValue->owner;
    if ((owner->mutualVisibleMask & cell) != 0) return 0x0F;
    if ((cell & owner->mutualExploredMask) != 0) return 0x80;
    return 0;
}

// --- matching/00417770_setAdjustedIdleTimeout.cpp ---
int debug_rand(char* file, int line);


void UnitAIModule::setAdjustedIdleTimeout(void) {
    unsigned int idleTimeout = this->idleTimeoutValue;
    unsigned int value = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xF4C);

    this->adjustedIdleTimeoutValue = value % (idleTimeout >> 1) + ((idleTimeout * 3) >> 2);
}

// --- matching/004177B0_setTaskedByPlayer.cpp ---

void UnitAIModule::setTaskedByPlayer() {
    this->purgeNotifyQueue(0);
}

// --- matching/004177c0_convertToLOSResourceType.cpp ---

int UnitAIModule::convertToLOSResourceType(int) {
    return -1;
}

// --- matching/004177D0_setPlayStatus.cpp ---
// UnitAIModule::setPlayStatus
// VA: 004177D0 (131 bytes, EH-framed)
// Attempt log:
// - Previous fake-dtor/raw-call source forced an EH frame but used wrong prologue order, extra EDI, indirect call wrappers,
//   and broad stack drift.
// - 2026-05-10 StarryZephyr pass: rewrote as natural typed AIPlayStatus new/copy under /GX. This recovers the original
//   prologue family, no extra EDI, new-expression shape, direct ctor/copy calls, and exact byte count. Remaining mismatch
//   is still broad tail scheduling around common join/new result store.

void* __cdecl operator new(unsigned int sz);


void UnitAIModule::setPlayStatus(AIPlayStatus* status) {
    if (playStatus == 0) {
        playStatus = new AIPlayStatus();
    }
    if (playStatus != 0 && status != 0) {
        playStatus->copy(status);
    }
}

// --- matching/00417860_lookAround.cpp ---
// VA: 00417860 UnitAIModule::lookAround
// PDB: aiuaimod.cpp lines 3949-3987
// Attempt: canonical visible-unit bucket scan; tuning against VC5 codegen.
// Exact: the terminal count/list globals are the last elements of the five-bucket
// VisibleUnitList_Size/VisibleUnitList arrays established by GetVisibleUnits; this
// method scans the two terminal buckets with the binary-proven byte offsets.


int __cdecl debug_rand(char* file, int line);

void UnitAIModule::lookAround()
{
    RGE_Game_World* world;
    int ownerID;

    this->search();

    int obj_id = this->objectValue->id;
    RGE_Player* owner = this->objectValue->owner;
    ownerID = owner->id;
    world = owner->world;

    for (int off = 0; off > -8; off -= 4) {
        for (int j = 0; j < *(int*)((char*)&DAT_0087d7d8 + off); ++j) {
            VisibleUnitEntry* entries = *(VisibleUnitEntry**)((char*)&DAT_0087d7f0 + off);
            RGE_Static_Object* obj = world->object(entries[j].object_id);
            if (obj != 0 && obj->object_state <= 2) {
                this->objectValue->owner->notify(obj_id, ownerID, 0x20D,
                                                 obj->id, 0, 0);
            }
        }
    }

    this->lookAroundTimerValue = 0;
    this->lookAroundTimeoutValue =
        debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xF92) % 1000 + 4000;
}

// --- matching/00417920_hasOrderOnQueue.cpp ---
// 00417920 hasOrderOnQueue (53B, aiuaimod.cpp)
// Searches an array of OrderEvent structs (stride 0x24) for a matching order type.
// Returns 1 if found, 0 if not.
//
// Attempt log:
// - Best version: while(1) + if(i < count) continue; return 0;
// - Prologue/loads/cmp first 0x17 bytes match perfectly
// - Remaining: bottom-of-loop uses jge+jmp instead of jl (VC5 loop inversion)
// - Same codegen pattern as inGroup (0040A420)


int UnitAIModule::hasOrderOnQueue(int param_1) {
    int count = this->orderQueueSizeValue;
    int index = 0;
    if (count <= 0) return 0;

    while (index < count) {
        if ((this->orderQueueValue + index)->orderType == param_1) return 1;
        index++;
    }
    return 0;
}

// --- matching/00417960_askForHelp.cpp ---
// VA: 00417960 UnitAIModule::askForHelp(int) (493B)
// aiuaimod.cpp:4005-4113
//
// Attempt log:
// - Replaced the placeholder with the binary-supported visible-unit bucket
//   scan.  The caller object is looked up first, then the five populated
//   visible-unit buckets are searched for nearby idle allied units.
// - The natural typed array form with repeated entry expressions reproduces
//   the 493-byte frame/size and all 15 ordered calls; a saved object-id local
//   collapsed the pointer/index schedule and was rolled back.
// - Binary evidence fixes the state guard at <= 2 and this routine's outer
//   scan at the two populated buckets (the emitted byte-offset loop compares
//   its cursor with 4).  The late scan and final dispatch blocks now align.
// - Fresh TU pass: declaring targetAI before the caller Y local reproduces the
//   unitAI call, Y load, and final push schedule. The mismatch falls to two
//   stack-displacement bytes at 00417AEA and 00417AFF.
// - An explicit cdecl slot-10c method ABI was tested because the original
//   post-call homes are 12 bytes higher. It worsened the structural match and
//   was rolled back. Keep the natural typed thiscall surface.
// - Direct callerObject->world_y arguments and a top-level uninitialized Y
//   local both duplicate the two-byte result. Keep direct typed member reads.
// - Main-agent audit corrected slot +0x10C to weaponRange() and moved the three
//   pending stack arguments into the complete eleven-argument order ABI.
// - Binary stack order confirms those pending values are 1, 0, and 0x32;
//   keeping weaponRange() argument-free and the complete order ABI matches.


extern float DAT_0056ebec;

void UnitAIModule::askForHelp(int caller)
{
    RGE_Static_Object* callerObject = this->lookupObject(caller);
    if (callerObject != 0) {
        this->search();

        int category = 0;
        do {
            int i = 0;
            if (((int*)&DAT_0087d7cc)[category] > 0) {
                do {
                    if (this->objectValue->id !=
                        ((VisibleUnitEntry**)&DAT_0087d7e4)[category][i].object_id) {
                        RGE_Static_Object* object =
                            this->lookupObject(
                                ((VisibleUnitEntry**)&DAT_0087d7e4)[category][i].object_id);
                        if (object != 0 && object->unitAI() != 0) {
                            RGE_Player* owner = object->owner;
                            if (owner != 0 && object->object_state <= 2) {
                                short group = object->master_obj->object_group;
                                if (group != 1 && group != 3 && group != 4 &&
                                    group != 0x15 && group != 0x12 &&
                                    group != 0x14 && group != 0x1b) {
                                    short ownerId = this->objectValue->owner->id;
                                    if (owner->id == ownerId || owner->isAlly(ownerId)) {
                                        if (this->objectValue->distance_to_object(object) <= 3.0f) {
                                            if (object->unitAI()->currentAction() == -1) {
                                                if (object->unitAI()->currentOrder() == -1) {
                                                    if (object->unitAI()->orderQueueSize() <= 0) {
                                                        UnitAIModule* targetAI = object->unitAI();
                                                        targetAI->order(
                                                            object->owner->id,
                                                            0x2bc,
                                                            caller,
                                                            callerObject->owner->id,
                                                            callerObject->world_x,
                                                            callerObject->world_y,
                                                            callerObject->world_y,
                                                            object->weaponRange(),
                                                            1,
                                                            0,
                                                            0x32);
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
                } while (i < ((int*)&DAT_0087d7cc)[category]);
            }
            ++category;
        } while (category <= 1);
    }
}

// --- scratch/00417B50_processOrder.cpp ---
// VA: 00417B50 processOrder (1269B)
// aiuaimod.cpp
// Period-plausible reconstruction of the UnitAIModule order dispatcher.
//
// Attempt log:
// - Replaced the stale placeholder with the typed OrderEvent dispatcher,
//   AI-play setup, order-result bookkeeping, and queue compaction supported by
//   the original call set and field offsets.
// - Reversed the overloaded moveTo declarations so VC5 emits the observed
//   virtual +0x90 call; the original source vtable order is a TU-sensitive fact.
// - Replaced aggregate queue assignment with the eight binary-observed dword
//   copies; the range dword at +0x20 is intentionally not shifted by the oracle.
// - Direct playStatus construction plus branch-local z/y/x conversion locals
//   reproduced the saved-register/prologue family and the six coordinate ftol
//   calls. Best checkpoint: 839 positional differing bytes, 90.46% resync
//   similarity, 42/42 calls, exact size, frame, and CFG counts still differ in
//   the EH handler relocation and localized result/coordinate scheduling.
// - Placement-new and direct-coordinate-store variants were rolled back; they
//   worsened EH/size or merged one binary-observed ftol path.
// - Left in scratch: remaining drift is switch-tail placement, the branch-local
//   +0x2C6 range scheduling, and localized register/load order.
// Main-agent source audit: replaced raw vtable/gap-only object, player, world,
// and master surfaces with donor-backed virtual destructors while preserving
// every proven field offset. Revalidation is codegen-unchanged; the function
// remains scratch because dispatch/tail topology and byte scheduling remain
// unresolved.
// - Preserved the 0x2C6 range as a branch-local float value; this
//   keeps the original's separate +0x90 call site from collapsing into +0x2D4.
//   The rebuilt call map is now 42/42, with 832 differing bytes.
// - Probe: removed the branch-local float range; this merged the +0x2C6 call
//   with +0x2D4 and lost one required virtual call, so restore the clean form.
// - Probe: inlined the playbook result test; VC5 now emits the original test
//   eax,eax and improves the best positional diff from 832 to 830 bytes.
// - Pointer-range, forced-tail-goto, and logged-branch-break variants were
//   rolled back; they lost the call map or expanded the function.
//
// Current matching pass:
// - Baseline check: 1269 bytes, 42/42 ordered calls, exact size and CFG counts,
//   96.63% shape similarity, 80.43% exact-block coverage, and 830 differing
//   bytes. The first mismatch is the switch-table relocation at +0x31.
// - Tested 20 meaningful hypotheses. Direct range use merges the two +0x90
//   calls. A local range keeps both calls but emits fld/fstp. Pointer, alias,
//   bit-cast, receiver, and volatile forms did not improve this basin.
// - Tested stop-tail gotos, duplicated stop calls, scoped log receivers,
//   header context, overload order, queue induction forms, coordinate scopes,
//   and truth-test spelling. None improved the clean checkpoint.
// - A mutating param_2 loop made one queue block exact but worsened registers
//   and total bytes. A preguarded do/while emitted the same bytes as the clean
//   for loop. The variant lab found no exact candidate.
// - Current pass: the queue index is declared before its pre-loop bound and
//   shifted in a guarded do/while. This matches the original mov edx,param_2
//   before the first bound compare, improving shape to 96.88% and exact-block
//   coverage to 81.88% at the same 830 differing bytes. This is now pinned.
// - Current pass tested short-lived play-status aliases, canonical point
//   aggregates, donor string externs, priority locals, range pointers, and
//   explicit stop-tail forms. They either duplicated an existing basin or
//   worsened size, control flow, or call count. Remaining leads are the
//   original action-log tail source shape, compiler context, and relocations.
// - Fresh probe: a source goto for the shared false-actionFile stop tail
//   preserved the observed call count but grew the function by 123 bytes.
//   Restore the natural local-tail source.
// - Fresh probe: long coordinate temporaries are codegen-identical to int
//   temporaries. Keep int because the canonical fields and ABI are int.
// BLOCKER: order 0x2C6 passes range by a raw dword copy in the executable. The
// rebuild loads and stores range through x87 before the virtual call. A
// signaling NaN can raise, become quiet, or change payload bits. FP exception,
// argument-bit, and fault timing can differ. Keep this dispatcher in scratch.
// Canonical-context pass: the protected PDB declaration emits the required
// MAE owner. The complete prefix preserves all 1269 bytes and 42 calls.


void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* block);
extern FILE* actionFile;
inline void* __cdecl operator new(unsigned int, void* ptr) { return ptr; }


int UnitAIModule::processOrder(OrderEvent* param_1, int param_2) {
    OrderEvent* order = param_1;
    int result = 0;

    switch (order->orderType) {
    case 0x2D6: {
        result = 1;
        if (this->objectValue->owner->world->playbook->play(
                order->targetOwner) == 0) {
            result = 0;
        } else {
            if (this->playStatus != 0) {
                operator delete(this->playStatus);
            }

            this->playStatus = new AIPlayStatus();
            if (this->playStatus == 0) {
                result = 0;
            } else {
                this->playStatus->playNumberValue = order->targetOwner;
                this->playStatus->targetValue = order->target;
                if (order->targetX != -1.0f) {
                    int z = (int)order->targetZ;
                    int y = (int)order->targetY;
                    int x = (int)order->targetX;
                    AIPlayStatus* status = this->playStatus;
                    status->originalPointX = x;
                    status->originalPointY = y;
                    status->originalPointZ = z;
                } else {
                    int z = (int)this->objectValue->world_z;
                    int y = (int)this->objectValue->world_y;
                    int x = (int)this->objectValue->world_x;
                    AIPlayStatus* status = this->playStatus;
                    status->originalPointX = x;
                    status->originalPointY = y;
                    status->originalPointZ = z;
                }
            }
        }
        break;
    }
    case 0x2D7:
        if (this->playStatus != 0) {
            operator delete(this->playStatus);
            this->playStatus = 0;
        }
        result = 1;
        break;
    case 0x2C2:
        this->removeCurrentTarget();
        if (actionFile != 0) {
            long object_id;
            if (this->objectValue != 0) {
                object_id = this->objectValue->id;
            } else {
                object_id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", object_id,
                    "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0x105D);
        }
        this->stopObject(1);
        result = 1;
        break;
    case 0x2C6:
        {
            // BINARY NOTE: A local range keeps this distinct +0x90 call site.
            const float range = param_1->range;
            result = this->moveTo(param_1->targetX, param_1->targetY,
                                  param_1->targetZ, range, 1);
        }
        break;
    case 0x2BC:
        result = this->attackObject(order->target, 1);
        break;
    case 0x2D9:
        result = this->attackRoundupObject(order->target);
        break;
    case 0x2BD:
        if (order->target != -1) {
            result = this->defendObject(order->target, order->range, 1);
        } else {
            result = this->defendPosition(order->targetX, order->targetY,
                                          order->range, 1);
        }
        break;
    case 0x2CE:
        result = this->repairObject(order->target, 1);
        break;
    case 0x2D1:
        result = this->unload(1, order->targetX, order->targetY);
        break;
    case 0x2D2:
        result = this->seekAndDestroy(order->target,
                                      (int)order->targetX,
                                      (int)order->targetY, 1);
        break;
    case 0x2D3:
        result = this->exploreAndDestroy((int)order->targetX,
                                         (int)order->targetY, 1);
        break;
    case 0x2C1:
        result = this->explore((int)order->targetX,
                               (int)order->targetY, 1);
        break;
    case 0x2BE:
        result = this->buildObject(order->target, 1);
        break;
    case 0x2D4:
        result = this->moveTo(order->targetX, order->targetY,
                              order->targetZ, order->range, 1);
        break;
    case 0x2C8:
        result = this->followObject(order->target, order->range, 1);
        break;
    case 0x2CD:
        result = this->enterObject(order->target, 1);
        break;
    case 0x2CA:
        result = this->transportObject(order->targetX, order->targetY,
                                       order->targetZ, 1);
        break;
    case 0x2D5:
        this->removeCurrentTarget();
        if (actionFile != 0) {
            long object_id;
            if (this->objectValue != 0) {
                object_id = this->objectValue->id;
            } else {
                object_id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", object_id,
                    "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0x10E9);
        }
        this->stopObject(1);
        result = 1;
        break;
    case 0x2BF:
        result = this->healObject(order->target, 1);
        break;
    case 0x2C0:
        result = this->convertObject(order->target, 1);
        break;
    case 0x2D8:
        result = 1;
        this->currentActionValue = 0x274;
        this->currentOrderValue = 0x2D8;
        break;
    case 0x2C5:
        result = this->gatherObject(order->target, 1);
        break;
    case 0x2C9:
        result = this->huntObject(order->target, 1);
        break;
    default:
        break;
    }

    if (result == 1) {
        int orderType = order->orderType;
        if (orderType == 0x2C2) {
            orderType = -1;
            this->currentOrderValue = -1;
        } else {
            if (orderType == 0x2D9) {
                this->currentOrderValue = 700;
            } else if (orderType == 700 &&
                       this->objectValue->master_obj->id == 0x7D) {
                this->currentOrderValue = -1;
                this->currentTargetValue = -1;
            } else {
                this->currentOrderValue = orderType;
            }
            orderType = order->priority;
        }
        this->currentOrderPriorityValue = orderType;
    }

    if (param_2 >= 0 && param_2 < this->orderQueueSizeValue &&
        this->orderQueueValue != 0) {
        int i = param_2;
        if (i < this->orderQueueSizeValue - 1) {
            do {
                this->orderQueueValue[i].issuer =
                    this->orderQueueValue[i + 1].issuer;
                this->orderQueueValue[i].orderType =
                    this->orderQueueValue[i + 1].orderType;
                this->orderQueueValue[i].priority =
                    this->orderQueueValue[i + 1].priority;
                this->orderQueueValue[i].target =
                    this->orderQueueValue[i + 1].target;
                this->orderQueueValue[i].targetOwner =
                    this->orderQueueValue[i + 1].targetOwner;
                this->orderQueueValue[i].targetX =
                    this->orderQueueValue[i + 1].targetX;
                this->orderQueueValue[i].targetY =
                    this->orderQueueValue[i + 1].targetY;
                // ORIGINAL BUG: The shipped shift omits the range dword at +0x20.
                this->orderQueueValue[i].targetZ =
                    this->orderQueueValue[i + 1].targetZ;
                ++i;
            } while (i < this->orderQueueSizeValue - 1);
        }
        --this->orderQueueSizeValue;
    }

    return result == 1;
}

// --- scratch/004180C0_processNotify.cpp ---
// VA: 004180C0 UnitAIModule::processNotify (4916 bytes)
// PDB owner: aiuaimod.cpp, lines 4423-5186.
//
// Recovery notes:
// - The PDB gives one body at 004180C0-004193F3.
// - The authentic UnitAIModule type is 0x134 bytes.
// - Exact donor 00506320 proves both attacking-unit scans and array growth.
// - Source case order is 508, 506, 505, 507, 514, 523, 510, 600, 699.
// - Four nested weaponRange and canPath ladders restore all 148 calls.
// - BINARY NOTE: every attack and path call rereads event->caller.
// - This differs from attacker->id when the event or object graph changes.
// - BINARY NOTE: zero target damage stores zero currentTargetDC.
// - Nonzero target damage calls objectValue->damageCapability(target).
// - The 505 and 507 arms share one chained order-publication tail.
// - The 506 arm keeps a distinct direct order-publication tail.
// - Direct cleanup tails preserve all stop and commander notifications.
// - PDB locals name currentTargetDC, both kill times, three target coordinates,
//   tileY, and tileX. Their proven homes overlap parameters and scoped locals.
// - The authentic context removes five register-only byte differences.
// - Current best has exact size, frame, CFG, 148 calls, and 12 byte differences.
// - Residual drift is one move argument register map and two publication stores.
// - Tested aliases, accessors, literal forms, condition forms, and local scopes.
// - Those forms duplicated this basin or changed valid behavior and layout.
// - Needed evidence is the original 4757 call spelling or fuller header context.
// - Captain probe: direct currentOrder rereads in case 506 were codegen-identical
//   to the saved local form. The natural local remains authoritative.

typedef unsigned long ulong;
extern FILE* actionFile;
extern float DAT_0056ebc8;
extern float DAT_0056ebf4;


#define LOG_STOP(lineNumber) \
    do { \
        if (actionFile != 0) { \
            long objectID; \
            if (this->objectValue != 0) { \
                objectID = this->objectValue->id; \
            } else { \
                objectID = -1; \
            } \
            fprintf(actionFile, "#%d call stopObject %s %d\n", objectID, \
                    "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", (lineNumber)); \
        } \
    } while (0)

int UnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    float targetX;

    switch (event->mType) {
    case 500:
    case 527: {
        this->notifyCommander(event);

        if (event->p2 <= 0) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x209,
                                  event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->objectValue->owner->computerPlayer() == 1) {
            RGE_Static_Object* object = this->objectValue;
            object->owner->notify(object->id, object->id, 0x201,
                                  event->caller, 0, 0);
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
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* newValue = (int*)operator new(newMaximum * 4);
            if (newValue != 0) {
                for (i = 0;
                     i < this->attackingUnitsValue.maximumSizeValue &&
                     i < newMaximum;
                     ++i) {
                    newValue[i] = this->attackingUnitsValue.value[i];
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newValue;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[
            this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

    after_add:
        this->objectValue->setUnderAttack(1);
        if (this->currentOrderValue != 0x2D5 &&
            this->currentOrderValue != -1 &&
            this->objectValue->owner->computerPlayer() == 0) {
            return 2;
        }
        if (this->currentOrderValue == 0x2D5) {
            return 2;
        }

        RGE_Static_Object* attacker = this->lookupObject(event->caller);
        if (attacker == 0) {
            return 2;
        }
        if (attacker->owner->id == this->objectValue->owner->id) {
            return 2;
        }
        if (this->currentActionValue == 0x25B &&
            this->runAwayFromAttackers(1) == 1) {
            return 3;
        }

        RGE_Static_Object* target = 0;
        if (this->currentTargetValue != -1) {
            target = this->lookupObject(this->currentTargetValue);
        }

        if (target == 0) {
            if (this->canAttackUnit(attacker) == 1) {
                if (this->objectValue->inAttackRange(attacker) != 1) {
                    if (this->objectValue->canPath(
                            event->caller,
                            this->objectValue->weaponRange(),
                            0, 0, -1, -1) != 1) {
                        goto no_target_failed;
                    }
                }
                if (this->attackObject(event->caller, 1) == 1 &&
                    this->currentOrderValue != 0x2BC) {
                    this->currentOrderValue = -1;
                    return 3;
                }
            } else {
            no_target_failed:
                if (this->currentActionValue != 0x262) {
                    this->runAwayFromAttackers(1);
                    return 3;
                }
            }
            return 3;
        }

        short objectGroup = target->master_obj->object_group;
        if ((objectGroup == 3 || objectGroup == 0x1B) &&
            target->master_obj->id != 0x4F &&
            target->master_obj->id != 199 &&
            target->master_obj->id != 0x45 &&
            this->objectValue->owner->computerPlayer() == 0) {
            if (this->canAttackUnit(attacker) == 1) {
                if (this->objectValue->inAttackRange(attacker) == 1 ||
                    this->objectValue->canPath(
                        event->caller, this->objectValue->weaponRange(),
                        0, 0, -1, -1) == 1) {
                    this->attackObject(event->caller, 1);
                    return 3;
                }
            }
            this->runAwayFromAttackers(1);
            return 3;
        }

        if (this->objectValue->owner->computerPlayer() != 1) {
            return 2;
        }
        if (target->master_obj->id == 0x114) {
            return 2;
        }

        float targetDamage = target->damageCapability();
        float objectDamage;
        if (targetDamage == DAT_0056ebc8) {
            objectDamage = 0.0f;
        } else {
            objectDamage = this->objectValue->damageCapability(target);
        }

        if (this->canAttackUnit(attacker) == 1 &&
            objectDamage == DAT_0056ebc8) {
            if (this->objectValue->inAttackRange(attacker) != 1) {
                if (this->objectValue->canPath(
                        event->caller,
                        this->objectValue->weaponRange(),
                        0, 0, -1, -1) != 1) {
                    goto compare_capability;
                }
            }
            this->attackObject(event->caller, 1);
        }

    compare_capability:
        float targetCapability = target->damageCapability(this->objectValue);
        float targetRatio;
        if (targetCapability > DAT_0056ebc8) {
            targetRatio = target->hitPoints / targetCapability;
        } else {
            targetRatio = 25000.0f;
        }

        float attackerCapability = attacker->damageCapability(this->objectValue);
        float attackerRatio;
        if (attackerCapability > DAT_0056ebc8) {
            attackerRatio = attacker->hitPoints / attackerCapability;
        } else {
            attackerRatio = 25000.0f;
        }

        if (this->canAttackUnit(attacker) != 1 ||
            attackerRatio >= targetRatio) {
            return 2;
        }
        if (this->objectValue->inAttackRange(attacker) != 1) {
            if (this->objectValue->canPath(
                    event->caller,
                    this->objectValue->weaponRange(),
                    0, 0, -1, -1) != 1) {
                return 2;
            }
        }
        this->attackObject(event->caller, 1);
        return 2;
    }

    case 508: {
        RGE_Static_Object* target = this->lookupObject(this->currentTargetValue);
        if (target != 0) {
            uchar visible = this->visibleStatus(
                this->objectValue->owner->visible,
                (int)target->world_x, (int)target->world_y);
            if (target->owner->id == 0) {
                return 2;
            }
            if (visible == 0x0F) {
                return 2;
            }

            targetX = this->currentTargetXValue;
            float targetY = this->currentTargetYValue;
            float targetZ = this->currentTargetZValue;
            int candidate = this->bestUnitToAttack(1, 0, 0);
            if (candidate != -1 &&
                candidate != this->currentTargetValue &&
                this->attackObject(candidate, 1) == 1) {
                this->currentOrderValue = -1;
                return 3;
            }
            if (this->objectValue->owner->computerPlayer() == 0 &&
                this->moveTo(targetX, targetY, targetZ, 0, 1) == 1) {
                int oldOrder = this->currentOrderValue;
                this->currentOrderValue = -1;
                this->lastOrderValue = oldOrder;
                this->currentOrderPriorityValue = -1;
                return 3;
            }
        }
        this->removeCurrentTarget();
        LOG_STOP(0x1269);
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }

    case 506: {
        int order = this->currentOrderValue;
        if (order == 700 && event->p1 == 600) {
            if (this->processIdle(0) != 5) {
                return 2;
            }
            if (this->currentOrderValue == 0x2D5 ||
                this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x128B);
                this->stopObject(0);
                return 2;
            }
            if (this->moveTo(this->currentTargetXValue,
                             this->currentTargetYValue,
                             this->currentTargetZValue,
                             this->desiredTargetDistanceValue - DAT_0056ebf4,
                             1) == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x129B);
                this->stopObject(0);
                return 2;
            }
            this->lastOrderValue = this->currentOrderValue;
            this->currentOrderValue = -1;
            this->currentOrderPriorityValue = -1;
            return 2;
        }
        if (order != -1 && this->currentActionValue + 100 == order) {
            this->removeCurrentTarget();
            LOG_STOP(0x12AF);
            this->stopObject(1);
            return 2;
        }
        if (order == -1 && this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            LOG_STOP(0x12B7);
            this->stopObject(1);
            return 2;
        }
        if (order == 0x2D4 && event->p1 == 0x262) {
            this->removeCurrentTarget();
            LOG_STOP(0x12C0);
            this->stopObject(0);
            return 2;
        }
        if (order == 0x2BD && event->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (order != 0x2D5 || event->p1 != 600) {
            return 2;
        }
        this->removeCurrentTarget();
        LOG_STOP(0x12CD);
        this->stopObject(1);
        return 2;
    }

    case 505: {
        int order = this->currentOrderValue;
        if (order == 700 && event->p1 == 600) {
            if (this->processIdle(0) != 5) {
                return 2;
            }
            if (this->currentOrderValue == 0x2D5 ||
                this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x12E9);
                this->stopObject(1);
                return 2;
            }
            if (this->moveTo(this->currentTargetXValue,
                             this->currentTargetYValue,
                             this->currentTargetZValue,
                             this->desiredTargetDistanceValue - DAT_0056ebf4,
                             1) == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x12F3);
                this->stopObject(1);
                return 2;
            }
            this->lastOrderValue = this->currentOrderValue;
            this->currentOrderValue = this->currentOrderPriorityValue = -1;
            return 2;
        }
        if (order != -1 && this->currentActionValue + 100 == order) {
            this->removeCurrentTarget();
            LOG_STOP(0x1304);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == -1 && this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            LOG_STOP(0x130D);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2D4 && event->p1 == 0x262) {
            this->removeCurrentTarget();
            LOG_STOP(0x1317);
            this->stopObject(0);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2BD && event->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (order != 0x2D5 || event->p1 != 600) {
            return 2;
        }
        this->removeCurrentTarget();
        LOG_STOP(0x1325);
        this->stopObject(1);
        return 2;
    }

    case 507: {
        int order = this->currentOrderValue;
        if (order == 700 && event->p1 == 600) {
            if (this->processIdle(0) != 5) {
                return 2;
            }
            if (this->currentOrderValue == 0x2D5 ||
                this->objectValue->owner->computerPlayer() == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x1341);
                this->stopObject(1);
                return 2;
            }
            if (this->moveTo(this->currentTargetXValue,
                             this->currentTargetYValue,
                             this->currentTargetZValue,
                             this->desiredTargetDistanceValue - DAT_0056ebf4,
                             1) == 0) {
                this->removeCurrentTarget();
                LOG_STOP(0x134B);
                this->stopObject(1);
                return 2;
            }
            this->lastOrderValue = this->currentOrderValue;
            this->currentOrderValue = this->currentOrderPriorityValue = -1;
            return 2;
        }
        if (order != -1 && this->currentActionValue + 100 == order) {
            this->removeCurrentTarget();
            LOG_STOP(0x135C);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == -1 && this->currentActionValue == event->p1) {
            this->removeCurrentTarget();
            LOG_STOP(0x1365);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2D4 && event->p1 == 0x262) {
            this->removeCurrentTarget();
            LOG_STOP(0x136F);
            this->stopObject(0);
            this->notifyCommander(event);
            return 2;
        }
        if (order == 0x2BD && event->p1 == 0x262) {
            this->setCurrentAction(-1);
            return 2;
        }
        if (order != 0x2D5 || event->p1 != 600) {
            return 2;
        }
        this->removeCurrentTarget();
        LOG_STOP(0x137D);
        this->stopObject(1);
        return 2;
    }

    case 514: {
        int action = this->currentActionValue;
        if (action == 0x25D || action == 0x26F) {
            int x;
            int y;
            if (this->closestUndiscoveredTile(&x, &y, 1) == 1) {
                this->addToWaypointQueue(x, y);
                if (this->explore(x, y, 1) == 0) {
                    this->removeCurrentTarget();
                    LOG_STOP(0x1396);
                    this->stopObject(1);
                    this->notifyCommander(event);
                }
                this->currentActionValue = action;
                return 3;
            }
            this->removeCurrentTarget();
            LOG_STOP(0x13A6);
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        } else {
            if (action != 0x261) {
                return 2;
            }
            int resourceType = this->currentTargetTypeValue;
            if (resourceType == -1) {
                resourceType = this->lastTargetTypeValue;
            }
            int losType = this->convertToLOSResourceType(resourceType);
            int targetID;
            if (losType != -1) {
                targetID = this->closestResourceObject(losType, 0);
            } else {
                targetID = this->closestObject(resourceType, -1, -1, -1, 0);
            }
            if (targetID != -1) {
                if (this->gatherObject(targetID, 1) == 1) {
                    return 3;
                }
                this->removeCurrentTarget();
                LOG_STOP(0x13CE);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            } else {
                this->removeCurrentTarget();
                LOG_STOP(0x13DA);
                this->stopObject(1);
                this->notifyCommander(event);
                return 2;
            }
        }
    }

    case 523: {
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        LOG_STOP(0x13E7);
        this->stopObject(1);
        this->purgeNotifyQueue(param_2);
        this->orderQueueSizeValue = 0;
        RGE_Static_Object* commander =
            this->lookupObject(this->objectValue->groupCommanderValue);
        if (commander != 0) {
            commander->commanderRemoveFromGroup(this->objectValue->id);
        }
        return 2;
    }

    case 510:
        this->objectValue->stopAction();
        this->removeCurrentTarget();
        LOG_STOP(0x13F9);
        this->stopObject(1);
        return 2;

    case 600: {
        int count = this->attackingUnitsValue.numberValue;
        int caller = event->caller;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) {
                goto attacker_added;
            }
        }
        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMaximum = this->attackingUnitsValue.numberValue + 1;
            int* newValue = (int*)operator new(newMaximum * 4);
            if (newValue != 0) {
                for (i = 0;
                     i < this->attackingUnitsValue.maximumSizeValue &&
                     i < newMaximum;
                     ++i) {
                    newValue[i] = this->attackingUnitsValue.value[i];
                }
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newValue;
                this->attackingUnitsValue.maximumSizeValue = newMaximum;
            }
        }
        this->attackingUnitsValue.value[
            this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

    attacker_added:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 699: {
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) {
                this->attackingUnitsValue.remove(event->caller);
                return 2;
            }
        }
        return 2;
    }

    default:
        this->removeCurrentTarget();
        LOG_STOP(0x1439);
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;
    }
}

#undef LOG_STOP

// --- matching/00419510_processGroupNotify.cpp ---
// VA: 00419510 UnitAIModule::processGroupNotify
// aiuaimod.cpp lines 5191-5250
// PDB owner and access: protected UnitAIModule::processGroupNotify.
// Body boundary: 00419510-004195E0; padding starts at 004195E1.
// This is the first normal aiuaimod.cpp sibling after processNotify, which ends at 004193F3.
// Attempt log:
// - Reconstructed the play-status/playbook/phase/trigger ownership from the original
//   offsets and direct-call set; replacing the stale unrelated placeholder.
// - Hoisted the natural play/phase locals and used the packet's do-while trigger scan;
//   those spellings alone stayed in the same 199-byte basin.
// - Materializing trigger->value1Value before the AIPlayStatus::group call preserved
//   its live EDI compare value, triggered the original delayed callee-save layout,
//   and produced an exact 209-byte match under the default flags.


void UnitAIModule::processGroupNotify(NotifyEvent* param_1)
{
    AIPlay* play;
    AIPlayPhase* phase;

    if (this->playStatus != 0 &&
        (play = this->objectValue->owner->world->playbook->play(
            this->playStatus->playNumberValue)) != 0 &&
        (phase = play->phase(this->playStatus->currentPhaseValue)) != 0 &&
        param_1->mType == 500) {
        this->playStatus->savedAttackerValue = param_1->caller;
        int i = 0;
        do {
            AIPlayPhaseTrigger* trigger = phase->trigger(i);
            if (trigger != 0 && trigger->typeValue != 0) {
                if (trigger->typeValue == 5) {
                    this->selectNewPlayPhase(trigger->nextPhaseValue, 0);
                } else if (trigger->typeValue == 4) {
                    int value1 = trigger->value1Value;
                    if (value1 == this->playStatus->group(param_1->recipient)) {
                        this->selectNewPlayPhase(trigger->nextPhaseValue, 0);
                    }
                }
            }
            ++i;
        } while (i < 3);
    }
}

// --- matching/004195F0_processIdle.cpp ---
// VA: 004195F0 UnitAIModule::processIdle
// aiuaimod.cpp lines 5255-5282; protected virtual owner (PDB symbol MAEHH).
// Body boundary: 004195F0-00419642; processGroupNotify ends at 004195E0.
// BLOCKER: The isolated view below emits the three original virtual calls.
// In the complete wrapper, the canonical class supplies get_type, find_unit,
// and do_stuff as direct helpers. A shared ABI repair is required before this
// owner can match in the complete TU.


int UnitAIModule::processIdle(int param) {
    if (param == 1 && get_type() == 8)
        return 6;

    int idx = find_unit(1, 0, 0);
    if (idx != -1) {
        if (do_stuff(idx, 1) == 1)
            return 6;
    }

    return 5;
}

// --- matching/00419650_processMisc.cpp ---
// VA: 00419650 UnitAIModule::processMisc (1383 bytes)
// PDB owner/access: protected virtual UnitAIModule::processMisc
// (?processMisc@UnitAIModule@@MAEHXZ), aiuaimod.cpp:5287-5689.
// Body boundary: 00419650-00419BB7 (ret at 00419BB6); next sibling starts at
// 00419BC0. The 00419BB7-00419BBF gap is padding.
// Typed reconstruction of the order-specific miscellaneous update pass.
//
// Exact-finish notes:
// - DECISIVE: use target-first movement, the defend target field, and a direct
//   desired-distance push. These choices restore the original block order.
// - REQUIRED: literal -1.0f preserves the original VC5 fld/fsub sequence.
//   The equivalent named global emits fsubr and is not byte exact.
// - INCIDENTAL: split threshold declaration, inline accessors, extra aliases,
//   and a move-distance local were tested and removed or walked back.
// - INSEPARABLE: the 0x2BD branch shape and defendTargetValue source are kept
//   together; each controls the nearby canPath call and block layout.
// - ABI: the PDB-qualified protected access is required; public access emits
//   the wrong decorated owner even though the function bytes stay unchanged.
// BINARY NOTE: the 0x2BD canPath guard reads [this+0x4C], not [this+0x34].
// BINARY NOTE: the targetless +0x90 call receives desired distance as an int
//   push, not through an x87 store.
// LIKELY INTENT: retain the shipped target and action fallbacks without adding
//   defensive checks that are absent from the executable.
// Reusable lesson candidate: a pooled float literal can select a different VC5
//   x87 operand order than an equivalent absolute global expression.


// BINARY NOTE: shared headers do not provide the called RGE_* vtable surfaces.
// Keep these local ABI surfaces. Their fields and called slots are proven here.

extern int taskedThisUpdate;                     // 00592A48
extern FILE* actionFile;                         // 0062C4CC
extern const char str_fmt_stopObject[];         // 0057F964
extern const char str_aiuaimod_path[];          // 0057F980

int UnitAIModule::processMisc()
{
    int invalidValue = -1;
    int order;

    if (this->currentOrderValue != invalidValue) {
        order = this->currentOrderValue;
    } else {
        if (this->currentActionValue != invalidValue) {
            order = this->currentActionValue;
            order += 100;
        } else {
            order = invalidValue;
        }
    }

    switch (order) {
    case 700: {
        if (taskedThisUpdate != 1 &&
            this->objectValue->owner->computerPlayer() != 0 &&
            this->objectValue->can_attack() != 0) {
            RGE_Static_Object* oldTarget =
                this->lookupObject(this->currentTargetValue);
            if (oldTarget == 0 || oldTarget->master_obj->id != 0x114) {
                int candidateID = this->bestUnitToAttack(0, 0, 0);
                RGE_Static_Object* candidate = this->lookupObject(candidateID);
                if (candidateID != invalidValue && candidate != 0 &&
                    candidateID != this->currentTargetValue) {
                    short group = candidate->master_obj->object_group;
                    if (group == 3 || group == 0x1B) {
                        if (candidate->master_obj->id == 0x114) {
                            this->order(
                                this->objectValue->id, 700, candidateID,
                                candidate->owner->id,
                                candidate->world_x, candidate->world_y,
                                candidate->world_z,
                                this->objectValue->weaponRange(),
                                1, 0, this->currentOrderPriorityValue);
                        }
                    } else if (oldTarget == 0 ||
                               oldTarget->master_obj->object_group == 3 ||
                               oldTarget->master_obj->object_group == 0x1B) {
                        this->order(
                            this->objectValue->id, 700, candidateID,
                            candidate->owner->id,
                            candidate->world_x, candidate->world_y,
                            candidate->world_z,
                            this->objectValue->weaponRange(),
                            1, 0, this->currentOrderPriorityValue);
                        return 9;
                    }
                }
            }
        }
        break;
    }

    case 0x2BD: {
        RGE_Static_Object* target = 0;

        if (this->defendTargetValue != invalidValue) {
            target = this->lookupObject(this->defendTargetValue);
            if (target == 0) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID,
                            str_aiuaimod_path, 0x15C0);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }

            if (this->currentTargetXValue == -1.0f) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
            }

            if (target->object_state > 2 && target->owner->id != 0) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID,
                            str_aiuaimod_path, 0x15D9);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }
        }

        if (this->currentActionValue != 600 &&
            (this->currentActionValue != 0x262 ||
             this->objectValue->currentTargetID() != this->defendTargetValue)) {
            float distance;
            if (this->defendTargetValue != invalidValue) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
                this->currentTargetZValue = target->world_z;
                distance = this->objectValue->distance_to_object(target);
            } else {
                distance = this->objectValue->distance_to_position(
                    this->currentTargetXValue,
                    this->currentTargetYValue,
                    this->objectValue->world_z);
            }

            if (distance > this->desiredTargetDistanceValue - (-1.0f)) {
                if (this->defendTargetValue != invalidValue) {
                    if (this->objectValue->canPath(
                            this->defendTargetValue,
                            this->desiredTargetDistanceValue,
                            0, 0, invalidValue, invalidValue) == 1) {
                        this->moveTo(
                            this->defendTargetValue,
                            this->desiredTargetDistanceValue, 1);
                        return 10;
                    }
                } else {
                    int x = (int)this->currentTargetXValue;
                    int y = (int)this->currentTargetYValue;
                    XYZPoint point = { x, y, invalidValue };
                    if (this->objectValue->canPathPoint(
                            point, this->desiredTargetDistanceValue,
                            invalidValue, 0, 0,
                            invalidValue, invalidValue) == 1) {
                        this->moveTo(
                            this->currentTargetXValue,
                            this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue, 1);
                        return 10;
                    }
                }
                return 10;
            }

            if (target != 0 && target->unitAI() != 0) {
                UnitAIModule* targetAI = target->unitAI();
                int attacker = targetAI->closestAttacker(0);
                if (attacker != invalidValue) {
                    this->attackObject(attacker, 1);
                    return 10;
                }
                if (this->processIdle(0) == 6) {
                    return 10;
                }
            }
        }
        break;
    }

    case 0x2C8: {
        RGE_Static_Object* target = 0;
        if (this->currentTargetValue != invalidValue) {
            target = this->lookupObject(this->currentTargetValue);
            if (target == 0 || target->object_state > 2) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID,
                            str_aiuaimod_path, 0x1582);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }
        }

        float xDiff;
        float yDiff;
        if (target != 0) {
            xDiff = target->world_x - this->currentTargetXValue;
        } else {
            xDiff = -10.0f;
        }
        if (target != 0) {
            yDiff = target->world_y - this->currentTargetYValue;
        } else {
            yDiff = -10.0f;
        }

        if (xDiff < DAT_0056ec00 || xDiff > DAT_0056ec08 ||
            yDiff < DAT_0056ec00 || yDiff > DAT_0056ec08) {
            float distance;
            if (this->currentTargetValue != invalidValue) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
                this->currentTargetZValue = target->world_z;
                distance = this->objectValue->distance_to_object(target);
            } else {
                distance = this->objectValue->distance_to_position(
                    this->currentTargetXValue,
                    this->currentTargetYValue,
                    this->objectValue->world_z);
            }

            if (distance > this->desiredTargetDistanceValue) {
                if (this->currentTargetValue != invalidValue) {
                    this->moveTo(this->currentTargetValue,
                                 this->desiredTargetDistanceValue, 1);
                    return 10;
                } else {
                    this->moveTo(
                        this->currentTargetXValue,
                        this->currentTargetYValue,
                        this->currentTargetZValue,
                        this->desiredTargetDistanceValue, 1);
                    return 10;
                }
            }
        }
        break;
    }

    default:
        break;
    }

    return 9;
}

// --- matching/00419BC0_processRetryableOrder.cpp ---
// VA: 00419BC0 UnitAIModule::processRetryableOrder
// PDB owner/access: protected virtual UnitAIModule::processRetryableOrder
// (?processRetryableOrder@UnitAIModule@@MAEHXZ), aiuaimod.cpp:5694-5746.
// Body boundary: 00419BC0-00419C26; 00419C30 is the next sibling.
// EXACT MATCH: switch generates subtract-chain matching original
//
// Exact-finish notes:
// - REQUIRED: the protected virtual declaration restores the PDB-qualified ABI
//   without changing the exact body bytes.
// - WALKBACK: public nonvirtual spelling also emitted exact bytes, but its
//   decorated owner was QAEH rather than the PDB's MAEH protected virtual.
// - BINARY NOTE: lastOrderValue is read before call28 and reread after call40.
//   Do not cache it across either virtual call.
// - BINARY NOTE: the four virtual calls use slots +0x28, +0x40, +0x64, +0x68,
//   with no stores, publication, or cleanup side effects in this body.
// - BINARY NOTE: the fallback return is reached after failed calls or unknown
//   orders; the two recognized orders return 8 only when the final call returns
//   1, and return 7 otherwise.


int UnitAIModule::processRetryableOrder() {
    int result;

    result = this->retryableOrder(this->lastOrderValue);
    if (result == 1) {
        result = this->closestObject(this->lastTargetTypeValue, -1, -1, -1, 0);
        if (result != -1) {
            switch (this->lastOrderValue) {
            case 0x2C5:
                result = this->gatherObject(result, 0);
                return (result == 1) ? 8 : 7;
            case 0x2C9:
                result = this->huntObject(result, 0);
                return (result == 1) ? 8 : 7;
            default:
                return 7;
            }
        }
    }
    return 7;
}

// --- matching/00419C30_addToOrderQueue.cpp ---
// VA: 00419C30 UnitAIModule::addToOrderQueue
// PDB owner/access: protected nonvirtual UnitAIModule::addToOrderQueue
// (?addToOrderQueue@UnitAIModule@@IAEHPAUOrderEvent@@H@Z), aiuaimod.cpp:5751-5755.
// Body boundary: 00419C30-00419C63; 00419C70 is the next sibling.
// EXACT MATCH: forwards the OrderEvent fields and param2 to the ten-parameter overload.
//
// Exact-finish notes:
// - REQUIRED: protected access restores the PDB-qualified IAEH owner ABI.
// - WALKBACK: public access emitted identical body bytes but the wrong QAEH owner.
// - REQUIRED: the sibling ABI is four ints, four floats, then two ints; an
//   all-int donor declaration created a synthetic direct target.
// - BINARY NOTE: param2 is reread from its incoming home after the first push.
// - BINARY NOTE: the call is direct to 00419C70 and ret 8 cleans both parameters.


int UnitAIModule::addToOrderQueue(OrderEvent* order, int param2) {
    return this->addToOrderQueue(order->issuer, order->orderType,
                                 order->target, order->targetOwner,
                                 order->targetX, order->targetY,
                                 order->targetZ, order->range,
                                 param2, order->priority);
}

// --- matching/00419C70_addToOrderQueue.cpp ---
// VA: 00419C70 addToOrderQueue (607B)
// PDB owner/access: protected nonvirtual UnitAIModule::addToOrderQueue
// (?addToOrderQueue@UnitAIModule@@IAEHHHHHMMMMHH@Z), aiuaimod.cpp:5762-5826.
// Body boundary: 00419C70-00419ECE; 00419ED0 is the next PDB sibling.
// aiuaimod.cpp
// Attempt log:
// - Reconstructed the canonical OrderEvent queue. The queue has nine 4-byte
//   fields, a 0x24-byte stride, and UnitAIModule fields at +0x10, +0x14, and
//   +0x18. The p9 path shifts existing records toward the next slot.
// - PDB/Ghidra proves this overload is protected and nonvirtual. The previous
//   public declaration emitted identical bytes but the wrong QAEH owner symbol.
// - The protected declaration now emits the PDB-qualified IAEH owner while
//   preserving the exact boundary, direct allocation calls, ret 28h cleanup,
//   queue rereads, publication order, and null-fault order.


int UnitAIModule::addToOrderQueue(int p1, int p2, int p3, int p4,
                                  float p5, float p6, float p7, float p8,
                                  int p9, int p10)
{
    if (this->orderQueueMaxSizeValue == this->orderQueueSizeValue) {
        OrderEvent* newQueue =
            (OrderEvent*)operator new(this->orderQueueMaxSizeValue * 0x48);
        if (newQueue == 0) {
            return 0;
        }

        int i = 0;
        if (this->orderQueueSizeValue > 0) {
            do {
                newQueue[i].issuer = this->orderQueueValue[i].issuer;
                newQueue[i].orderType = this->orderQueueValue[i].orderType;
                newQueue[i].priority = this->orderQueueValue[i].priority;
                newQueue[i].target = this->orderQueueValue[i].target;
                newQueue[i].targetOwner = this->orderQueueValue[i].targetOwner;
                newQueue[i].targetX = this->orderQueueValue[i].targetX;
                newQueue[i].targetY = this->orderQueueValue[i].targetY;
                newQueue[i].targetZ = this->orderQueueValue[i].targetZ;
                newQueue[i].range = this->orderQueueValue[i].range;
                ++i;
            } while (i < this->orderQueueSizeValue);
        }

        if (this->orderQueueValue != 0) {
            operator delete(this->orderQueueValue);
        }
        this->orderQueueValue = newQueue;
        this->orderQueueMaxSizeValue = this->orderQueueMaxSizeValue * 2;
    }

    if ((p9 != 0) && (this->orderQueueSizeValue != 0)) {
        int i = 0;
        if (this->orderQueueSizeValue > 0) {
            do {
                this->orderQueueValue[i + 1].issuer =
                    this->orderQueueValue[i].issuer;
                this->orderQueueValue[i + 1].orderType =
                    this->orderQueueValue[i].orderType;
                this->orderQueueValue[i + 1].priority =
                    this->orderQueueValue[i].priority;
                this->orderQueueValue[i + 1].target =
                    this->orderQueueValue[i].target;
                this->orderQueueValue[i + 1].targetOwner =
                    this->orderQueueValue[i].targetOwner;
                this->orderQueueValue[i + 1].targetX =
                    this->orderQueueValue[i].targetX;
                this->orderQueueValue[i + 1].targetY =
                    this->orderQueueValue[i].targetY;
                this->orderQueueValue[i + 1].targetZ =
                    this->orderQueueValue[i].targetZ;
                this->orderQueueValue[i + 1].range =
                    this->orderQueueValue[i].range;
                ++i;
            } while (i < this->orderQueueSizeValue);
        }

        this->orderQueueValue->issuer = p1;
        this->orderQueueValue->orderType = p2;
        this->orderQueueValue->priority = p10;
        this->orderQueueValue->target = p3;
        this->orderQueueValue->targetOwner = p4;
        this->orderQueueValue->targetX = p5;
        this->orderQueueValue->targetY = p6;
        this->orderQueueValue->targetZ = p7;
        this->orderQueueValue->range = p8;
        this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
        return 1;
    }

    this->orderQueueValue[this->orderQueueSizeValue].issuer = p1;
    this->orderQueueValue[this->orderQueueSizeValue].orderType = p2;
    this->orderQueueValue[this->orderQueueSizeValue].priority = p10;
    this->orderQueueValue[this->orderQueueSizeValue].target = p3;
    this->orderQueueValue[this->orderQueueSizeValue].targetOwner = p4;
    this->orderQueueValue[this->orderQueueSizeValue].targetX = p5;
    this->orderQueueValue[this->orderQueueSizeValue].targetY = p6;
    this->orderQueueValue[this->orderQueueSizeValue].targetZ = p7;
    this->orderQueueValue[this->orderQueueSizeValue].range = p8;
    this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
    return 1;
}

// --- matching/00419ED0_addToNotifyQueue.cpp ---
// VA: 00419ED0 UnitAIModule::addToNotifyQueue
// PDB owner/access: protected nonvirtual UnitAIModule::addToNotifyQueue
// (?addToNotifyQueue@UnitAIModule@@IAEHPAUNotifyEvent@@@Z), aiuaimod.cpp:5831-5834.
// Body boundary: 00419ED0-00419EF2; 00419F00 is the next PDB sibling.
// BINARY NOTE: the wrapper reads all six event fields before its direct call.
// Direct target: protected ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z at 00419F00.
// The callee uses ret 18h, while this wrapper uses ret 4 for its event pointer.


int UnitAIModule::addToNotifyQueue(NotifyEvent* event) {
    return this->addToNotifyQueue(
        event->caller,
        event->recipient,
        event->mType,
        event->p1,
        event->p2,
        event->p3
    );
}

// --- matching/00419F00_addToNotifyQueue.cpp ---
// VA: 00419F00 addToNotifyQueue (279B)
// aiuaimod.cpp
// PDB owner/access: protected nonvirtual UnitAIModule::addToNotifyQueue(int, int,
// int, long, long, long), aiuaimod.cpp:5840-5868.
// Symbol: ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z.
// Body boundary: 00419F00-0041A016; 00419ED0 is the preceding sibling.
// Attempt log:
// - Replaced the stale placeholder with the proven notify-queue ownership:
//   size at +0x1c, capacity at +0x20, and NotifyEvent array at +0x24.
// - The typed field-copy/indexed append baseline matched through the append
//   block; direct/compound shift spellings left a localized register drift.
// - A focused natural source-shape lab showed that spelling capacity growth as
//   multiplication by two reproduces the original VC5 register/block layout.
// - Main-agent audit confirmed canonical UnitAIModule/NotifyEvent ownership;
//   emitted code remains exact.
// - A fresh public-ABI check also matched bytes, but emitted QAE rather than
//   the PDB-qualified protected IAE owner. Keep the protected declaration.


int UnitAIModule::addToNotifyQueue(int caller, int recipient, int mType,
                                   long p1, long p2, long p3)
{
    if (this->notifyQueueMaxSizeValue == this->notifyQueueSizeValue) {
        NotifyEvent* newQueue =
            (NotifyEvent*)operator new(this->notifyQueueMaxSizeValue * 0x30);
        if (newQueue == 0) {
            return 0;
        }

        int i = 0;
        if (this->notifyQueueSizeValue > 0) {
            do {
                newQueue[i].caller = this->notifyQueueValue[i].caller;
                newQueue[i].recipient = this->notifyQueueValue[i].recipient;
                newQueue[i].mType = this->notifyQueueValue[i].mType;
                newQueue[i].p1 = this->notifyQueueValue[i].p1;
                newQueue[i].p2 = this->notifyQueueValue[i].p2;
                newQueue[i].p3 = this->notifyQueueValue[i].p3;
                ++i;
            } while (i < this->notifyQueueSizeValue);
        }

        if (this->notifyQueueValue != 0) {
            operator delete(this->notifyQueueValue);
        }
        this->notifyQueueValue = newQueue;
        this->notifyQueueMaxSizeValue = this->notifyQueueMaxSizeValue * 2;
    }

    this->notifyQueueValue[this->notifyQueueSizeValue].caller = caller;
    this->notifyQueueValue[this->notifyQueueSizeValue].recipient = recipient;
    this->notifyQueueValue[this->notifyQueueSizeValue].mType = mType;
    this->notifyQueueValue[this->notifyQueueSizeValue].p1 = p1;
    this->notifyQueueValue[this->notifyQueueSizeValue].p2 = p2;
    this->notifyQueueValue[this->notifyQueueSizeValue].p3 = p3;
    this->notifyQueueSizeValue = this->notifyQueueSizeValue + 1;
    return 1;
}

// --- accepted_drift/0041A020_purgeNotifyQueue.cpp ---
// VA: 0041A020 purgeNotifyQueue (166B)
// PDB owner/access: public UnitAIModule::purgeNotifyQueue(unsigned long),
// aiuaimod.cpp:5873-5916.
// Symbol: ?purgeNotifyQueue@UnitAIModule@@QAEXK@Z.
// Body boundary: 0041A020-0041A0C5; padding starts at 0041A0C6.
// The preceding 00419F00 helper is protected and has symbol
// ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z. Do not merge these ABIs.
// Fresh 2026-05-19: implement packet-derived notify queue purge logic.
// try 1: natural NotifyEntry pointer: exact size, 6/166 positional; pointer setup used EAX+LEA and loop used jge/jmp.
// try 2: model loop cursor as int* p=&entry->action: fixed pointer setup exactly; remaining 3/166 branch topology at loop end.
// try 3: explicit goto loop/done: no branch-topology change.
// try 4: for(;;) with break on count: no branch-topology change.
// try 5: while(i<count): worsened badly (80% positional/prologue/loop basin), rolled back.
// Remaining drift: only loop-tail branch inversion after `cmp edi,ebx`: original `jl top; jmp done`, rebuilt `jge done; jmp top`.
// Same flags, same targets, same loop state, same calls/logging/virtual stopObject, and all other bytes exact.



void UnitAIModule::purgeNotifyQueue(unsigned long time)
{
    int i = 0;
    int count = this->notifyQueueSizeValue;
    if (count > 0) {
        int* p = (int*)&this->notifyQueueValue->p1;
        for (;;) {
            if (p[-1] == 0x1FA) {
                int action = *p;
                if (action != 0x262 || this->currentActionValue == action || this->currentActionValue == 0x268) {
                    if (this->currentOrderValue == -1 && this->currentActionValue == action) {
                        this->removeCurrentTarget();
                        FILE* f = *(FILE**)0x62C4CC;
                        if (f != 0) {
                            int id;
                            if (this->objectValue != 0) {
                                id = this->objectValue->id;
                            } else {
                                id = -1;
                            }
                            fprintf(f, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0x170E);
                        }
                        this->stopObject(1);
                        break;
                    }
                }
            }
            i++;
            p += 6;
            if (i >= count) break;
        }
    }
    this->notifyQueueSizeValue = 0;
    this->lastUpdateTimeValue = time;
}

// --- matching/0041A0D0_lookupObject.cpp ---

RGE_Static_Object* UnitAIModule::lookupObject(int objectId) {
    if (this->objectValue && this->objectValue->owner &&
        this->objectValue->owner->world) {
        return this->objectValue->owner->world->object(objectId);
    }
    return 0;
}

// --- matching/0041A100_logDebug.cpp ---
extern "C" int __cdecl vsprintf(char* dest, const char* fmt, char* args);

// BINARY NOTE: 0041A100 is UnitAIModule::logDebug, public virtual varargs,
// at aiuaimod.cpp lines 5932-5942. Its body ends at 0041A14E; the next bytes
// are padding. Keep the preceding 0041A020 purgeNotifyQueue owner separate.
// compact debug logger first
// tried va_start/va_end and a direct stack-address cast for the varargs pack; mismatch stayed on the vsprintf arg-list stack slot
// tried changing textOut+4 to textOut (both vsprintf dest and virtual call arg); original uses plain textOut, not textOut+4
// MATCHED: changed textOut+4 to textOut in both vsprintf dest and virtual call arg — original uses plain textOut

void UnitAIModule::logDebug(char* param_1, ...) {
    char textOut[1024];
    if (this->objectValue != 0) {
        // BINARY NOTE: The variadic receiver uses caller cleanup. Keep the
        // original parameter-home address and the object null-check order.
        vsprintf(textOut, param_1, (char*)&param_1 + 4);
        this->objectValue->logDebug(textOut);
    }
}
