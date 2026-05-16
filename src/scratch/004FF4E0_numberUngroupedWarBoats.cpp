// VA: 004FF4E0 TribeTacticalAIModule::numberUngroupedWarBoats
// Attempt log:
// initial decompiler-style implementation with local rNum/i and explicit expandable int-array code: exact size, broad register/scheduling diff from prologue (no push ebp in rebuilt; compiler uses ebp as i+1 later).
// tried register int i to force register loop index; no codegen change.
// tried separate local_4 initialization/order (`i=local_4`, `local_4=i`) to encourage original stack home for i; no change.
// tried explicit local update at loop bottom (`local_4=i; ++local_4; i=local_4`); no change.
// tried typedef for unit id parameter and named groupUnitIsIn result local; no change, rolled back result local.
// compared nearby scratch numberIdleSoldiers pattern; same broad expandable-array idiom, not a known exact donor.
// left in scratch: behavior and calls understood, same 510-byte size, but not accepted_drift-safe because prologue/loop register basin differs from offset 3 and many regions are rescheduled.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
class TacticalAIGroup;
typedef int UnitId;

class TribeTacticalAIModule {
public:
    char gap_000[0x134];
    int* boats_value;          // +134
    int boats_number;          // +138
    char gap_13c[4];
    int boats_max;             // +140
    char gap_144[0xD48 - 0x144];
    int* working_value;        // +D48
    int working_number;        // +D4C
    char gap_d50[4];
    int working_max;           // +D54

    TacticalAIGroup* groupUnitIsIn(UnitId id);
    int numberUngroupedWarBoats();
};

int TribeTacticalAIModule::numberUngroupedWarBoats()
{
    int rNum;
    int i;
    int local_4;

    rNum = 0;
    i = 0;
    local_4 = i;
    this->working_number = 0;
    if (this->boats_number > 0) {
        do {
            if (i > this->boats_max - 1) {
                int newCount = i + 1;
                int* p = (int*)operator_new(newCount * 4);
                if (p != 0) {
                    int j = 0;
                    if (this->boats_max > 0) {
                        do {
                            if (j >= newCount) break;
                            p[j] = this->boats_value[j];
                            ++j;
                        } while (j < this->boats_max);
                    }
                    operator_delete(this->boats_value);
                    this->boats_value = p;
                    this->boats_max = newCount;
                }
            }
            if (this->groupUnitIsIn(this->boats_value[i]) == 0) {
                if (i > this->boats_max - 1) {
                    int newCount2 = i + 1;
                    int* p2 = (int*)operator_new(newCount2 * 4);
                    if (p2 != 0) {
                        int j2 = 0;
                        if (this->boats_max > 0) {
                            do {
                                if (j2 >= newCount2) break;
                                p2[j2] = this->boats_value[j2];
                                ++j2;
                            } while (j2 < this->boats_max);
                        }
                        operator_delete(this->boats_value);
                        this->boats_value = p2;
                        this->boats_max = newCount2;
                    }
                }
                local_4 = this->boats_value[i];
                int k = 0;
                int wn = this->working_number;
                if (wn > 0) {
                    do {
                        if (k >= this->working_max) break;
                        if (this->working_value[k] == local_4) goto counted;
                        ++k;
                    } while (k < wn);
                }
                if (wn > this->working_max - 1) {
                    int newWork = wn + 1;
                    int* wp = (int*)operator_new(newWork * 4);
                    if (wp != 0) {
                        int m = 0;
                        if (this->working_max > 0) {
                            do {
                                if (m >= newWork) break;
                                wp[m] = this->working_value[m];
                                ++m;
                            } while (m < this->working_max);
                        }
                        operator_delete(this->working_value);
                        this->working_value = wp;
                        this->working_max = newWork;
                    }
                }
                this->working_value[this->working_number] = local_4;
                this->working_number = this->working_number + 1;
counted:
                ++rNum;
            }
            local_4 = i;
            ++local_4;
            i = local_4;
        } while (i < this->boats_number);
    }
    return rNum;
}
