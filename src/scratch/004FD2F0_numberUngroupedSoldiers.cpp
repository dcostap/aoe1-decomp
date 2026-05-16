// VA: 004FD2F0 TribeTacticalAIModule::numberUngroupedSoldiers
// Attempt log:
// try 1: factored ensure helpers compiled out-of-line, text too small.
// try 2: inlined repeated growth logic but compiler chose ebp for newMax and very different loop topology.
// try 3: closer decompiler-style locals/local_4/i/rNum and direct indexed access.
// try 4: volatile i forced 0x0c stack frame but shifted rNum/local_4 slots to +0x10/+0x0c instead of original +0x08/+0x10.
// try 5: reordered locals; no stack-slot improvement.
// try 6: compare spelling local_4 > max-1 restored first jle polarity but loop copy body still uses ecx index/shift instead of original eax increment + [base+eax*4-4].
// try 7: first natural inline version had correct function size but no EBP loop index and broad register/topology drift.
// left in scratch: behavior modeled, but VC5 register/stack-local allocation for inlined dynamic-array growth is still wrong; not accepted-drift-safe.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);
class TacticalAIGroup;

class TribeTacticalAIModule {
public:
    char gap_000[0x114];
    int* soldierValue;
    int soldierNumber;
    char gap_11C[4];
    int soldierMaximum;
    char gap_124[0xD48 - 0x124];
    int* workingValue;
    int workingNumber;
    char gap_D50[4];
    int workingMaximum;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedSoldiers();
};

int TribeTacticalAIModule::numberUngroupedSoldiers()
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
    if (0 < this->soldierNumber) {
        do {
            if (local_4 > this->soldierMaximum + -1) {
                piVar1 = (int*)operator new(local_4 * 4 + 4);
                if (piVar1 != 0) {
                    iVar4 = 0;
                    if (0 < this->soldierMaximum) {
                        do {
                            if (local_4 + 1 <= iVar4) break;
                            iVar2 = iVar4 + 1;
                            piVar1[iVar4] = this->soldierValue[iVar4];
                            iVar4 = iVar2;
                        } while (iVar2 < this->soldierMaximum);
                    }
                    operator delete(this->soldierValue);
                    this->soldierValue = piVar1;
                    this->soldierMaximum = local_4 + 1;
                }
            }
            i = local_4 * 4;
            if (this->groupUnitIsIn(*(int*)((char*)this->soldierValue + i)) == 0) {
                if (local_4 > this->soldierMaximum + -1) {
                    i = i + 4;
                    piVar1 = (int*)operator new(i);
                    if (piVar1 != 0) {
                        iVar4 = 0;
                        if (0 < this->soldierMaximum) {
                            do {
                                if (local_4 + 1 <= iVar4) break;
                                iVar2 = iVar4 + 1;
                                piVar1[iVar4] = this->soldierValue[iVar4];
                                iVar4 = iVar2;
                            } while (iVar2 < this->soldierMaximum);
                        }
                        operator delete(this->soldierValue);
                        this->soldierValue = piVar1;
                        this->soldierMaximum = local_4 + 1;
                    }
                    i = local_4 * 4;
                }
                iVar5 = 0;
                iVar2 = *(int*)((char*)this->soldierValue + i);
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
        } while (local_4 < this->soldierNumber);
    }
    return rNum;
}
