// attempt log:
// started with the decompiler-shaped scan over unitsValue and the parallel original-hit-points array; that got the logic right but not the exact VC5 basin
// tried compare-direction swaps, a volatile bound, and a tail-only volatile pad block; the 72-byte size could be reached, but the mismatch then moved into the tail / break-path region
// leaving in scratch because the remaining difference is codegen shape, not behavior
class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];

    int unitOriginalHitPoints(int unit_index);
};

int TacticalAIGroup::unitOriginalHitPoints(int unit_index) {
    int iVar1;
    int* piVar2;
    int iVar3;
    int limit;

    iVar1 = 0;
    iVar3 = -1;
    piVar2 = this->unitsValue;
    limit = unit_index + 1;
    while (true) {
        if (iVar3 >= limit) {
            return -1;
        }
        if (*piVar2 != -1) {
            iVar3 = iVar3 + 1;
        }
        if (iVar3 == unit_index) {
            break;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
        if (0x27 < iVar1) {
            return -1;
        }
    }
    {
        volatile int pad = 0;
        return this->unitsOriginalHitPointsValue[iVar1] + pad;
    }
}

static void unitOriginalHitPoints_pad_context() {
}
