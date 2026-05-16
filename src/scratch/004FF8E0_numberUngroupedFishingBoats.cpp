// VA: 004FF8E0 TribeTacticalAIModule::numberUngroupedFishingBoats
// Attempt log:
// 1: adapted known numberUngroupedSoldiers source to fishingBoats offsets: correct size 510 but broad 90.4% positional diff; compiler omitted push ebp and used ebp as newMax.
// 2: switched to decompiler-shaped local_4/i/local_c source based on numberUngroupedArtifacts scratch to force stack locals: 510 B, first mismatch at stack slot init, 79.6% diff.
// 3: removed volatile from i; worse first mismatch at frame immediate/slot allocation, rolled back.
// 4: tested local declaration reordering with volatile i; no slot/order change.
// 5: changed growth predicates to `local_4 > max-1` / `iVar2 > max-1` to match original cmp polarity; fixed first growth compare polarity but broad copy-loop/register drift remains.
// 6: tried local order local_c/i/local_4 and local_c/local_4/i with volatile offset temp; stack slot order unchanged.
// 7: tried /GX; unchanged.
// 8: tried /O2 without /Oy; unchanged.
// 9: tried /Od narrow flag; unchanged under this build harness/output family.
// 10: current best remains same-size 510 B but broad ~79% positional diff from stack-slot ordering and array-growth copy-loop shape; behavior/call set appears right, but not accepted_drift-safe.

extern void* operator new(unsigned int sz);
extern void operator delete(void* p);
class TacticalAIGroup;

class TribeTacticalAIModule {
public:
    char gap_000[0x154];
    int* fishing_value;
    int fishing_number;
    char gap_15C[4];
    int fishing_max;
    char gap_164[0xD48 - 0x164];
    int* working_value;
    int working_number;
    char gap_D50[4];
    int working_max;

    TacticalAIGroup* groupUnitIsIn(int id);
    int numberUngroupedFishingBoats();
};

int TribeTacticalAIModule::numberUngroupedFishingBoats()
{
    int local_c;
    int local_4;
    volatile int i;
    int* piVar1;
    int iVar2;
    int iVar4;
    int iVar6;
    int boat;

    local_c = 0;
    local_4 = 0;
    this->working_number = 0;
    if (0 < this->fishing_number) {
        do {
            if (local_4 > this->fishing_max - 1) {
                piVar1 = (int*)operator new(local_4 * 4 + 4);
                if (piVar1 != 0) {
                    iVar4 = 0;
                    if (0 < this->fishing_max) {
                        do {
                            if (local_4 + 1 <= iVar4) break;
                            iVar2 = iVar4 + 1;
                            piVar1[iVar4] = this->fishing_value[iVar4];
                            iVar4 = iVar2;
                        } while (iVar2 < this->fishing_max);
                    }
                    operator delete(this->fishing_value);
                    this->fishing_value = piVar1;
                    this->fishing_max = local_4 + 1;
                }
            }
            i = local_4 * 4;
            if (this->groupUnitIsIn(*(int*)((char*)this->fishing_value + i)) == 0) {
                if (local_4 > this->fishing_max - 1) {
                    i = i + 4;
                    piVar1 = (int*)operator new(i);
                    if (piVar1 != 0) {
                        iVar4 = 0;
                        if (0 < this->fishing_max) {
                            do {
                                if (local_4 + 1 <= iVar4) break;
                                iVar2 = iVar4 + 1;
                                piVar1[iVar4] = this->fishing_value[iVar4];
                                iVar4 = iVar2;
                            } while (iVar2 < this->fishing_max);
                        }
                        operator delete(this->fishing_value);
                        this->fishing_value = piVar1;
                        this->fishing_max = local_4 + 1;
                    }
                    i = local_4 * 4;
                }
                boat = *(int*)((char*)this->fishing_value + i);
                iVar4 = 0;
                iVar2 = this->working_number;
                if (0 < iVar2) {
                    do {
                        if (this->working_max <= iVar4) break;
                        if (this->working_value[iVar4] == boat) goto LAB_counted;
                        iVar4 = iVar4 + 1;
                    } while (iVar4 < iVar2);
                }
                if (iVar2 > this->working_max - 1) {
                    iVar2 = iVar2 + 1;
                    piVar1 = (int*)operator new(iVar2 * 4);
                    if (piVar1 != 0) {
                        iVar4 = 0;
                        if (0 < this->working_max) {
                            do {
                                if (iVar2 <= iVar4) break;
                                iVar6 = iVar4 + 1;
                                piVar1[iVar4] = this->working_value[iVar4];
                                iVar4 = iVar6;
                            } while (iVar6 < this->working_max);
                        }
                        operator delete(this->working_value);
                        this->working_value = piVar1;
                        this->working_max = iVar2;
                    }
                }
                this->working_value[this->working_number] = boat;
                this->working_number = this->working_number + 1;
LAB_counted:
                local_c = local_c + 1;
            }
            local_4 = local_4 + 1;
        } while (local_4 < this->fishing_number);
    }
    return local_c;
}
