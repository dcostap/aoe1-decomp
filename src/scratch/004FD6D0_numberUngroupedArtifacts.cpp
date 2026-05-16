// VA: 004FD6D0 TribeTacticalAIModule::numberUngroupedArtifacts
// Source: taitacmd.cpp lines 10206-10220
// Attempt log:
// 1: natural reconstruction from packet/decompiler, preserving explicit array growth loops: broad mismatch, compiler used EAX/EBP differently and omitted early push ebp.
// 2: closer decompiler-shaped source with local_c/local_4 names and direct indexed array accesses: much closer prologue but only 8-byte frame.
// 3: make i volatile to force the third stack local slot seen in original; got 0x0c frame but stack slots are permuted.
// 4: reorder local declarations to try local_c at +8, i at +0c, local_4 at +10; no stack-slot improvement.
// 5: invert first capacity condition source to try cmp ebp,eax / jle skip shape; fixed first branch polarity but copy loops still wrong.
// 6: tried separate volatile frame_pad with nonvolatile i; frame collapsed back to 8 bytes and worsened, rolled back.
// 7: keep volatile i as best frame/prologue family; remaining drift is stack-slot permutation and copy-loop register topology.
// 8: swap initial local assignment order to probe stack slot store order; swapped first two stores but still no +8 rNum slot and broad loop drift.
// 9: tried narrow /O1 flag as code-size/control-flow probe; produced EBP frame and worse, flag removed.
// 10: left in scratch: behavior/call surface understood, but remaining mismatch is broad VC5 stack-slot allocation and dynamic-array copy-loop register topology. Best /O2 family has correct 0x0c frame, push ebp/esi, branch polarity for first grow check, but rNum/local_4/i stack slots are permuted and copy loops use ECX/shl instead of original EAX inc/index form; not accepted-drift-safe.

extern void* operator new(unsigned int sz);
extern void operator delete(void* p);

class TribeTacticalAIModule {
public:
    char gap_000[0x184];
    int* artifacts_value;
    int artifacts_number;
    char gap_18C[4];
    int artifacts_max;
    char gap_194[0xD48 - 0x194];
    int* working_value;
    int working_number;
    char gap_D50[4];
    int working_max;

    void* groupUnitIsIn(int id);
    int numberUngroupedArtifacts();
};

int TribeTacticalAIModule::numberUngroupedArtifacts()
{
    int local_4;
    volatile int i;
    int local_c;
    int* piVar1;
    int iVar2;
    int iVar4;
    int iVar6;
    int artifact;

    local_4 = 0;
    local_c = 0;
    this->working_number = 0;
    if (0 < this->artifacts_number) {
        do {
            if (local_4 <= this->artifacts_max - 1) {
            } else {
                piVar1 = (int*)operator new(local_4 * 4 + 4);
                if (piVar1 != 0) {
                    iVar4 = 0;
                    if (0 < this->artifacts_max) {
                        do {
                            if (local_4 + 1 <= iVar4) break;
                            iVar2 = iVar4 + 1;
                            piVar1[iVar4] = this->artifacts_value[iVar4];
                            iVar4 = iVar2;
                        } while (iVar2 < this->artifacts_max);
                    }
                    operator delete(this->artifacts_value);
                    this->artifacts_value = piVar1;
                    this->artifacts_max = local_4 + 1;
                }
            }
            i = local_4 * 4;
            if (this->groupUnitIsIn(*(int*)((char*)this->artifacts_value + i)) == 0) {
                if (this->artifacts_max - 1 < local_4) {
                    i = i + 4;
                    piVar1 = (int*)operator new(i);
                    if (piVar1 != 0) {
                        iVar4 = 0;
                        if (0 < this->artifacts_max) {
                            do {
                                if (local_4 + 1 <= iVar4) break;
                                iVar2 = iVar4 + 1;
                                piVar1[iVar4] = this->artifacts_value[iVar4];
                                iVar4 = iVar2;
                            } while (iVar2 < this->artifacts_max);
                        }
                        operator delete(this->artifacts_value);
                        this->artifacts_value = piVar1;
                        this->artifacts_max = local_4 + 1;
                    }
                    i = local_4 * 4;
                }
                artifact = *(int*)((char*)this->artifacts_value + i);
                iVar4 = 0;
                iVar2 = this->working_number;
                if (0 < iVar2) {
                    do {
                        if (this->working_max <= iVar4) break;
                        if (this->working_value[iVar4] == artifact) goto LAB_counted;
                        iVar4 = iVar4 + 1;
                    } while (iVar4 < iVar2);
                }
                if (this->working_max - 1 < iVar2) {
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
                this->working_value[this->working_number] = artifact;
                this->working_number = this->working_number + 1;
LAB_counted:
                local_c = local_c + 1;
            }
            local_4 = local_4 + 1;
        } while (local_4 < this->artifacts_number);
    }
    return local_c;
}
