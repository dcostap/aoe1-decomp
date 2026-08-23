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

#include <stdio.h>

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* block);
extern FILE* actionFile;
inline void* __cdecl operator new(unsigned int, void* ptr) { return ptr; }

#include "../../include/aiuaimod_context.h"

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
