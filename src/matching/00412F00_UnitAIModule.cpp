// VA: 00412F00 UnitAIModule ctor (356B)
// aiuaimod.cpp
// EH frame (/GX)

#include <stdlib.h>
#include <string.h>
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

#include "../../include/aiuaimod_context.h"

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
