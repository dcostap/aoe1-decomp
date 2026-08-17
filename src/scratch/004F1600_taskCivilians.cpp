// VA: 004F1600 TribeTacticalAIModule::taskCivilians(unsigned long, unsigned long)
// PDB source: taitacmd.cpp lines 3313-3548
// __thiscall, int, ret 8
//
// Attempt log (dsb2-004F1600, 30 meaningful probes across sessions):
// - Fresh canonical reset: prior rejected source manually expanded five
//   ManagedArray grow blocks. This reconstruction uses the natural typed
//   ManagedArray<int> surface (inline operator[] grow, remove, out-of-line
//   resize) and the plain source-level algorithm: new-explorer creation,
//   gatherer->explorer conversion by needed-resource priority, excess-
//   explorer removal, gatherer creation, and the refresh loop that tasks
//   civilians one per tick (return j = count tasked).
// - probe 5 baseline: typed operator[]/remove/resize surface; first-mismatch
//   at +9 (< 1 guard); frame 0x14 achieved after probe 6.
// - probe 6: `<= 0` guard (test/jg encoding) + declaration-only resize so
//   VC5 emits real ManagedArray<int>::resize calls (call set then fully
//   aligned; target-count gap 0).
// - probe 7/9/10: resource-conversion loop shapes. The two object() calls
//   inside it pass the `tasked` variable (register pushes, not -1 literals);
//   the loop is `do { if (tasked != -1) goto append; ... } while (newExplorer
//   > -1)` under an early-exit check. VC5 still rotates the loop-top tasked
//   check to the loop bottom (proves tasked == -1 at the head) so the
//   original's separate B010 top-check block is not reproduced.
// - probe 8: operator[] copy loop as combined `&&` bound (max && index+1) per
//   004DC1B0 lesson; grow copy loops now match the original shape exactly.
// - probe 11: task_done dispatch written as `if (highLevelTaskGatherer(...)
//   == 0) { addGatherer path }` keeps the addGatherer path inline and
//   task_done as the skip target (original's jne layout); call sites 100%
//   aligned.
// - probe 12: operator[] grow uses a named `new_size = index + 1` local;
//   grow blocks byte-match the original (shape 84%).
// - probes 13-14 (explicit grow expansion using taskedCount/newExplorer and
//   indexing civilians[taskedCount-1]): both regressed; VC5 emits extra
//   frames/arith instead of the original's induction-locals codegen. Reverted.
// - probes 19-24: a scoped civilian pointer/reference or value before the
//   explorer scan exposed the refresh-loop operator[] grow at the original
//   top block and restored the 0x14 frame. The value form is the cleanest
//   source reconstruction (1563B diff, 90.50% shape); pointer/reference
//   forms added an unnecessary address alias. Split taskedCount initialization
//   was emitted identically to `i + 1`.
// - Worker session sa-9f7395fa-r1 ran 20 meaningful probes. The baseline was
//   1563B strict diff and 90.50% shape. Comma and reverse coordinate forms,
//   separate coordinate locals, local declaration order, direct member-call
//   arguments, and combined refresh IV expressions were duplicate or worse.
// - A top-tested resource loop plus a scoped civilianExplorers reference
//   restored the original redundant tasked check and improved the clean source
//   to 1260B diff, 96.59% shape, and 86.70% exact-block coverage. Explicit
//   excess-removal labels gave 1150B strict diff but poor resynchronization and
//   were rejected as a non-natural metric-only form. Timeout operand reversal
//   improved compare parity without changing size or strict diff.
// - The final unresolved candidate is 2083B versus 2062B, 39/39 ordered calls,
//   frame 0x14, and first mismatch +003C in coordinate/FPU scheduling. The
//   remaining evidence points to VC5 scheduling and refresh register homes.
// - Canonical ownership: md +0xF0, civilians +0xF4 (ManagedArray<int>),
//   civilianExplorers +0x104 (ManagedArray<int>), numberGatherersValue +0x9CC,
//   desiredNumberGatherersValue +0x9D0, neededResourceValue[4] +0xD88,
//   nextCivilianToTaskValue +0xF7C. taskCivilians returns j, the number of
//   civilians tasked this tick.
// - Call set (39): object x5, __ftol x6, idleCivilian x4, removeGatherer,
//   resize x2, operator_new/delete (inline grows), stopUnit, addGatherer x2,
//   highLevelTaskGatherer, highLevelTaskExplorer, updateGathererDistribution,
//   debug_timeGetTime x2.
// - ManagedArray audit: the local template remains the canonical utmarray.h
//   inline operator[]/remove surface, matching exact 004EA750/004F1390 donors;
//   resize stays declaration-only for the real 004147A0 out-of-line call.
// - Main-agent audit removed an impossible `tasked != -1` check nested directly
//   under `tasked == -1`; it was non-emitting experiment residue. Codegen and
//   all metrics remained unchanged.

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* block);
}

struct XYPoint { int x; int y; };

class RGE_Static_Object {
public:
    char gap_00[0x04];
    int id;                      // +0x04
    char gap_08[0x30];
    float world_x;               // +0x38
    float world_y;               // +0x3C
    char gap_40[0x04];
    float attribute_amount_held; // +0x44
};

template <class T>
class ManagedArray {
public:
    T* value;               // +0
    int numberValue;        // +4
    int desiredNumberValue; // +8
    int maximumSizeValue;   // +0xC

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                int i = 0;
                for (; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int remove(int v) {
        int i = 0;
        int max = this->maximumSizeValue;
        for (; i < max; ++i) {
            if (this->value[i] == v) break;
        }
        if (i >= max) return 0;
        --max;
        if (i < max) {
            do {
                this->value[i] = this->value[i + 1];
                ++i;
            } while (i < this->maximumSizeValue - 1);
        }
        int n = this->numberValue - 1;
        this->numberValue = n;
        if (n < 0) this->numberValue = 0;
        return 1;
    }

    // Real out-of-line ManagedArray<int>::resize call in the original (004147A0);
    // keep declaration-only so VC5 emits a call instead of inlining the template body.
    int resize(int new_size);
};

struct UnitData;

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id, int masterId, int group, int action, int action2,
                              int target, int targetType, int resource, int state, int amountHeld);
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;              // +0xF0
    ManagedArray<int> civilians;           // +0xF4
    ManagedArray<int> civilianExplorers;   // +0x104
    char gap_114[0x8B8];                   // +0x114
    int numberGatherersValue;              // +0x9CC
    int desiredNumberGatherersValue;       // +0x9D0
    char gap_9D4[0x3B4];                   // +0x9D4
    int neededResourceValue[4];            // +0xD88
    char gap_D98[0x1E4];                   // +0xD98
    int nextCivilianToTaskValue;           // +0xF7C

    int idleCivilian(int mode);
    int idleCivilian(int mode, XYPoint* pos, int flag);
    void removeGatherer(int id);
    UnitData* addGatherer(int id);
    int highLevelTaskGatherer(int id, unsigned long arg);
    int highLevelTaskExplorer(int id, int flag);
    void updateGathererDistribution();
    int stopUnit(int id, int param);

    int taskCivilians(unsigned long param_1, unsigned long param_2);
};

extern unsigned long debug_timeGetTime(const char* file, int line);

int TribeTacticalAIModule::taskCivilians(unsigned long param_1, unsigned long param_2) {
    int newExplorer;
    int taskedCount;
    int j;
    XYPoint tcPosition;
    int i;
    int k;
    int tasked;
    RGE_Static_Object* obj;
    int civilian;

    if (this->civilians.numberValue <= 0) {
        this->nextCivilianToTaskValue = -1;
        return 0;
    }

    j = 0;
    if (this->nextCivilianToTaskValue == -1) {
        // Create new civilian explorers up to the desired number.
        if (this->civilianExplorers.numberValue < this->civilianExplorers.desiredNumberValue) {
            do {
                obj = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
                if (obj != 0) {
                    tcPosition.x = (int)obj->world_x;
                    tcPosition.y = (int)obj->world_y;
                    tasked = this->idleCivilian(-1, &tcPosition, 0);
                } else {
                    tasked = this->idleCivilian(-1);
                }
                taskedCount = tasked;
                if (tasked != -1) goto append_explorer;
                // Too many gatherers: convert the one carrying the highest-priority
                // needed resource into an explorer instead.
                if (this->desiredNumberGatherersValue < this->numberGatherersValue) {
                    newExplorer = 3;
                    while (newExplorer > -1) {
                        if (tasked != -1) goto append_explorer;
                            obj = this->md->object(tasked, tasked, tasked, 0x261, 0x25D,
                                                   tasked, tasked,
                                                   this->neededResourceValue[newExplorer],
                                                   tasked, 0);
                            if (obj == 0) {
                                obj = this->md->object(tasked, tasked, tasked, 0x265, 0x25D,
                                                       tasked, tasked,
                                                       this->neededResourceValue[newExplorer],
                                                       tasked, 0);
                            }
                            if (obj != 0 && obj->attribute_amount_held == 0.0f) {
                                int id = obj->id;
                                for (i = 0; i < this->civilianExplorers.numberValue &&
                                             i < this->civilianExplorers.maximumSizeValue; i++) {
                                    if (this->civilianExplorers.value[i] == id) goto next_resource;
                                }
                                tasked = id;
                                taskedCount = id;
                                this->removeGatherer(id);
                            }
next_resource:
                        newExplorer = newExplorer - 1;
                    }
                }
                if (tasked == -1) goto skip_append;
append_explorer:
                // Append the tasked civilian to the explorer list (if not already there).
                {
                    ManagedArray<int>& explorers = this->civilianExplorers;
                    for (i = 0; i < explorers.numberValue &&
                                 i < explorers.maximumSizeValue; i++) {
                        if (explorers.value[i] == tasked) goto skip_append;
                    }
                    if (explorers.numberValue > explorers.maximumSizeValue - 1) {
                        explorers.resize(explorers.numberValue + 1);
                    }
                    explorers.value[explorers.numberValue] = tasked;
                    explorers.numberValue = explorers.numberValue + 1;
                }
            } while (this->civilianExplorers.numberValue <
                     this->civilianExplorers.desiredNumberValue);
        }
skip_append:
        // Remove excess explorers (the oldest first).
        if (this->civilianExplorers.numberValue > this->civilianExplorers.desiredNumberValue) {
            do {
                if (this->civilianExplorers.numberValue <= 0) break;
                int id = this->civilianExplorers[0];
                this->civilianExplorers.remove(id);
                this->stopUnit(id, 100);
            } while (this->civilianExplorers.numberValue >
                     this->civilianExplorers.desiredNumberValue);
        }
        // Create gatherers up to the desired number.
        if (this->numberGatherersValue < this->desiredNumberGatherersValue) {
            do {
                obj = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
                if (obj != 0) {
                    tcPosition.x = (int)obj->world_x;
                    tcPosition.y = (int)obj->world_y;
                    tasked = this->idleCivilian(-1, &tcPosition, 0);
                } else {
                    tasked = this->idleCivilian(-1);
                }
            } while (tasked != -1 && this->addGatherer(tasked) != 0 &&
                     this->numberGatherersValue < this->desiredNumberGatherersValue);
        }
        if (this->civilians.maximumSizeValue - 1 < 0) {
            this->civilians.resize(1);
        }
        this->nextCivilianToTaskValue = this->civilians.value[0];
        if (debug_timeGetTime((const char*)0x005880C0, 0x0D8A) - param_1 >= param_2) {
            return 0;
        }
    }

    // Refresh phase: find the civilian to task this tick and task the rest.
    for (i = 0; i < this->civilians.numberValue; i++) {
        if (this->civilians[i] == this->nextCivilianToTaskValue) break;
    }
    if (i >= this->civilians.numberValue) goto no_more;

    taskedCount = i;
    taskedCount = taskedCount + 1;
    newExplorer = taskedCount * 4;
    do {
        j = j + 1;
        civilian = this->civilians[i];
        // Already an explorer?
        for (k = 0; k < this->civilianExplorers.numberValue &&
                     k < this->civilianExplorers.maximumSizeValue; k++) {
            if (this->civilianExplorers.value[k] == civilian) goto is_explorer;
        }
        if (this->highLevelTaskGatherer(this->civilians[i], param_1) == 0) {
            this->addGatherer(this->civilians[i]);
            i = i + 1;
            taskedCount = taskedCount + 1;
            newExplorer = newExplorer + 4;
            goto loop_cond;
        }
task_done:
        this->updateGathererDistribution();
        i = i + 1;
        taskedCount = taskedCount + 1;
        newExplorer = newExplorer + 4;
        if (i >= this->civilians.numberValue) goto no_more;
        this->nextCivilianToTaskValue = this->civilians[i];
        if (debug_timeGetTime((const char*)0x005880C0, 0x0DC6) - param_1 >= param_2) {
            if (i > 0) {
                // Binary-proven capacity touch: ensure room for civilians[i-1]
                // before returning, matching the inline operator[] grow.
                if (i > this->civilians.maximumSizeValue - 1) {
                    this->civilians[i - 1];
                }
            }
            goto done;
        }
loop_cond:
        ;
    } while (i < this->civilians.numberValue);
    goto no_more;

no_more:
    this->nextCivilianToTaskValue = -1;
done:
    return j;

is_explorer:
    this->highLevelTaskExplorer(this->civilians[i], 1);
    goto task_done;
}
