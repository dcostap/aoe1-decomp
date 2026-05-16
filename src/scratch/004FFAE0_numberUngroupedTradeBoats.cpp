// Attempt log for 004FFAE0 TribeTacticalAIModule::numberUngroupedTradeBoats
// try 1: natural decompiler-shaped reconstruction with ManagedArray fields; exact size but 90.20% positional, compiler made 1-based loop and omitted EBP save.
// try 2: write closer to decompiler/original using local_4 index and allocation size local_4*4+4 directly; first mismatch moved to offset 16, exact size.
// try 3: reorder local declarations and store workingNumber from local_4 to probe stack slot/scheduling; no change.
// try 4: add middle dummy zero local to force local_4 to [esp+10]; dummy optimized away/no change.
// try 5: initialize rNum to zero before local_4 to occupy middle stack slot; no change.
// try 6: use <= skip form for first grow test to match cmp local_4,max; jle skip; small improvement.
// try 7: use <= skip form for second trade grow test too; no further change.
// try 8: adopt sibling numberUngroupedFishingBoats volatile i/copy-temp style; edit diff improved to 45.69%, first mismatch offset 17.
// try 9: /GX flag probe; unchanged, rolled back.
// try 10: /O1 flag probe; object too small (472B), rolled back.
// try 11: /Oy- flag probe; worse from offset 0, rolled back.
// BLOCKER: exact 510B size and behavior/call set look plausible, but broad stack-slot/copy-loop/register drift remains (best default check ~74.9% positional / 45.7% edit diff). Not accepted_drift-safe.

typedef unsigned int uint;
void* operator new(uint size);
void operator delete(void* ptr);
class TacticalAIGroup;

class TribeTacticalAIModule {
public:
    char gap_000[0x164];
    int* tradeValue;
    int tradeNumber;
    char gap_16c[4];
    int tradeMax;
    char gap_174[0xd48 - 0x174];
    int* workingValue;
    int workingNumber;
    char gap_d50[4];
    int workingMax;
    TacticalAIGroup* groupUnitIsIn(int unitId);
    int numberUngroupedTradeBoats();
};

int TribeTacticalAIModule::numberUngroupedTradeBoats()
{
    int local_c;
    int dummy;
    int local_4;
    volatile int i;
    int rNum;

    local_c = 0;
    rNum = 0;
    local_4 = 0;
    this->workingNumber = local_4;
    if (0 < this->tradeNumber) {
        do {
            if (local_4 <= this->tradeMax - 1) goto skip_grow1;
            {
                int* piVar1 = (int*)operator new(local_4 * 4 + 4);
                if (piVar1 != 0) {
                    int iVar4 = 0;
                    if (0 < this->tradeMax) {
                        do {
                            if (local_4 + 1 <= iVar4) break;
                            int iVar2 = iVar4 + 1;
                            piVar1[iVar4] = this->tradeValue[iVar4];
                            iVar4 = iVar2;
                        } while (iVar4 < this->tradeMax);
                    }
                    operator delete(this->tradeValue);
                    this->tradeValue = piVar1;
                    this->tradeMax = local_4 + 1;
                }
            }
skip_grow1:
            i = local_4 * 4;
            if (this->groupUnitIsIn(*(int*)((char*)this->tradeValue + i)) == 0) {
                if (local_4 <= this->tradeMax - 1) goto skip_grow2;
                {
                    int* piVar2 = (int*)operator new(local_4 * 4 + 4);
                    if (piVar2 != 0) {
                        int iVar5 = 0;
                        if (0 < this->tradeMax) {
                            do {
                                if (local_4 + 1 <= iVar5) break;
                                int iVar2b = iVar5 + 1;
                                piVar2[iVar5] = this->tradeValue[iVar5];
                                iVar5 = iVar2b;
                            } while (iVar5 < this->tradeMax);
                        }
                        operator delete(this->tradeValue);
                        this->tradeValue = piVar2;
                        this->tradeMax = local_4 + 1;
                    }
                }
skip_grow2:
                int unitId = *(int*)((char*)this->tradeValue + i);
                int n = this->workingNumber;
                rNum = 0;
                if (0 < n) {
                    do {
                        if (this->workingMax <= rNum) break;
                        if (this->workingValue[rNum] == unitId) goto LAB_counted;
                        rNum++;
                    } while (rNum < n);
                }
                if (this->workingMax - 1 < n) {
                    n++;
                    int* piVar3 = (int*)operator new(n * 4);
                    if (piVar3 != 0) {
                        rNum = 0;
                        if (0 < this->workingMax) {
                            do {
                                if (n <= rNum) break;
                                int iVar6 = rNum + 1;
                                piVar3[rNum] = this->workingValue[rNum];
                                rNum = iVar6;
                            } while (rNum < this->workingMax);
                        }
                        operator delete(this->workingValue);
                        this->workingValue = piVar3;
                        this->workingMax = n;
                    }
                }
                this->workingValue[this->workingNumber] = unitId;
                this->workingNumber = this->workingNumber + 1;
LAB_counted:
                local_c = local_c + 1;
            }
            local_4 = local_4 + 1;
        } while (local_4 < this->tradeNumber);
    }
    return local_c;
}
