// VA: 004FFCE0 TribeTacticalAIModule::numberUngroupedTransportBoats
// Attempt log:
// try 1: cloned decompiler-style dynamic-array logic from analogous soldiers function, changing source array offsets to transportBoats (+0x174/+0x178/+0x180).
// try 2: used volatile i to force 0x0c frame; it preserves frame size but shifts rNum/local_4 stack slots versus original.
// try 3: reordered local declarations; no improvement in stack slot allocation.
// try 4: compare spelling `local_4 > maximum-1` restored early jle polarity but copy-loop topology remains wrong.
// try 5: factored helper style was considered from analogous function; compiles too small/out-of-line and loses original inlined growth shape.
// try 6: fully natural indexed source uses no EBP loop index and broad register drift.
// try 7: decompiler-style locals get EBP loop index and exact size but VC5 emits ecx index/shift copy loops instead of original eax increment + [base+eax*4-4].
// try 8: non-volatile i kept exact size but did not improve topology (79.2% positional, 105.5% edit).
// try 9: original less-than compare spelling regressed slightly (79.6% positional, 109.8% edit).
// try 10: rNum-first local declaration did not move stack slots or copy-loop family.
// try 11: while(1)+break outer loop was neutral versus do/while for the major mismatch.
// left in scratch: behavior modeled, but dynamic-array growth/copy codegen and stack local slots remain broad mismatch; not accepted-drift-safe.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);
class TacticalAIGroup;

class TribeTacticalAIModule {
public:
    char gap_000[0x174];
    int* transportValue;
    int transportNumber;
    char gap_17C[4];
    int transportMaximum;
    char gap_184[0xD48 - 0x184];
    int* workingValue;
    int workingNumber;
    char gap_D50[4];
    int workingMaximum;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedTransportBoats();
};

int TribeTacticalAIModule::numberUngroupedTransportBoats()
{
    volatile int i;
    int rNum;
    int local_4;
    int* piVar1;
    int iVar2;
    int iVar4;
    int iVar5;
    int iVar6;

    rNum = 0;
    local_4 = 0;
    this->workingNumber = 0;
    if (0 < this->transportNumber) {
        do {
            if (local_4 > this->transportMaximum + -1) {
                piVar1 = (int*)operator new(local_4 * 4 + 4);
                if (piVar1 != 0) {
                    iVar4 = 0;
                    if (0 < this->transportMaximum) {
                        do {
                            if (local_4 + 1 <= iVar4) break;
                            iVar2 = iVar4 + 1;
                            piVar1[iVar4] = this->transportValue[iVar4];
                            iVar4 = iVar2;
                        } while (iVar2 < this->transportMaximum);
                    }
                    operator delete(this->transportValue);
                    this->transportValue = piVar1;
                    this->transportMaximum = local_4 + 1;
                }
            }
            i = local_4 * 4;
            if (this->groupUnitIsIn(*(int*)((char*)this->transportValue + i)) == 0) {
                if (local_4 > this->transportMaximum + -1) {
                    i = i + 4;
                    piVar1 = (int*)operator new(i);
                    if (piVar1 != 0) {
                        iVar4 = 0;
                        if (0 < this->transportMaximum) {
                            do {
                                if (local_4 + 1 <= iVar4) break;
                                iVar2 = iVar4 + 1;
                                piVar1[iVar4] = this->transportValue[iVar4];
                                iVar4 = iVar2;
                            } while (iVar2 < this->transportMaximum);
                        }
                        operator delete(this->transportValue);
                        this->transportValue = piVar1;
                        this->transportMaximum = local_4 + 1;
                    }
                    i = local_4 * 4;
                }
                iVar5 = 0;
                iVar2 = *(int*)((char*)this->transportValue + i);
                iVar4 = this->workingNumber;
                if (0 < iVar4) {
                    do {
                        if (this->workingMaximum <= iVar5) break;
                        if (this->workingValue[iVar5] == iVar2) goto LAB_counted;
                        iVar5 = iVar5 + 1;
                    } while (iVar5 < iVar4);
                }
                if (iVar4 > this->workingMaximum + -1) {
                    iVar4 = iVar4 + 1;
                    piVar1 = (int*)operator new(iVar4 * 4);
                    if (piVar1 != 0) {
                        iVar5 = 0;
                        if (0 < this->workingMaximum) {
                            do {
                                if (iVar4 <= iVar5) break;
                                iVar6 = iVar5 + 1;
                                piVar1[iVar5] = this->workingValue[iVar5];
                                iVar5 = iVar6;
                            } while (iVar6 < this->workingMaximum);
                        }
                        operator delete(this->workingValue);
                        this->workingValue = piVar1;
                        this->workingMaximum = iVar4;
                    }
                }
                this->workingValue[this->workingNumber] = iVar2;
                this->workingNumber = this->workingNumber + 1;
LAB_counted:
                rNum = rNum + 1;
            }
            local_4 = local_4 + 1;
        } while (local_4 < this->transportNumber);
    }
    return rNum;
}
