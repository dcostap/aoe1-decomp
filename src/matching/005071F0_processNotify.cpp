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

#include <math.h>
#include "../../include/taiuaimd_context.h"

extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

extern "C" int debug_rand(char*, int);
#define taskedThisUpdate (*(int*)0x592A48)
extern const float DAT_005758bc;
extern const float DAT_005758c0;
extern const float DAT_005758dc;
extern const float DAT_005758e0;
extern const float DAT_005758e4;

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
