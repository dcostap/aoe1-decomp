// 004FAAA0 TribeTacticalAIModule::taskExplorer (taitacmd.cpp:8897-8913)
// Attempt log:
// 1: Natural implementation with static add_unique helper emitted helper out-of-line; function only 336B.
// 2: Inline both array-add sequences and pad MapThing vtable: size matches, but search loops use pointer-walk/test max; 81.60% positional, 30.47% edit.
// 3: While with max locals improves edit to 21.68 but adds duplicate count tests and function too long.
// 4: Copy loop do/while spelling produced no source change/no codegen change.
// 5: For-loop search spelling no codegen change.
// 6: int task player parameter + cast improved tail (edit 20.04%).
// 7: while(1) copy loops improved edit to 14.31 and copy loops match; function still +3/duplicate search tests.
// 8: Goto-shaped search loops worsened to 23.72 edit; rolled back to for-loop search.
// 9: Removed the decompiler-only positive-count guards from all bounded scans;
//    exact same-TU donors then recovered the target size and first scan blocks.
// 10: Reconstructed both lists as ManagedIntArray members at +104 and +d58;
//     output stayed unchanged and the layout is now canonical.
// 11: Fresh typed baseline retained the known 224-byte second-scan drift.
// 12: Explicitly assigned civilian.numberValue before both scans; no code change.
// 13: Guarded do-while repeated scan reduced the byte diff but changed block shape;
//     restored the natural indexed for-loop.
// 14: Separate firstCount and secondCount locals did not change emitted code.
// 15: A canonical civilians ManagedIntArray alias on the repeated scan produced MATCH.
// 16: Scoped that reference to the civilian scan and growth block; MATCH remained.
// Final: exact default-flags output, with canonical list ownership and typed dispatch.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class MapThing {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void task(int player, int unit, int action, int a, int b, float x, float y, float f1, float f2, int c, int d, int e);
    char pad04[0x4a - 4];
    short player_id;
};
class MdHolder { public: char pad[0xf0]; MapThing* map; };

class TribeTacticalAIModule {
public:
    char pad000[0xf0];
    MdHolder* md;               // +f0
    char pad0f4[0x104 - 0x0f4];
    ManagedIntArray civilians;  // +104
    char pad114[0xd58 - 0x114];
    ManagedIntArray tasked;     // +d58

    int taskExplorer(int unit, float x, float y, int flag);
    int removeGatherer(int unit);
};

int TribeTacticalAIModule::taskExplorer(int unit, float x, float y, int flag)
{
    int i = 0;
    int count = this->tasked.numberValue;
    for (; i < count; i++) {
        if (i >= this->tasked.maximumSize) break;
        if (this->tasked.value[i] == unit) goto tasked_done;
    }
    if (count > this->tasked.maximumSize - 1) {
        int newMax = count + 1;
        int* nv = (int*)operator_new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->tasked.maximumSize > 0) {
                while (1) {
                    if (i >= newMax) break;
                    nv[i] = this->tasked.value[i];
                    i++;
                    if (i >= this->tasked.maximumSize) break;
                }
            }
            operator_delete(this->tasked.value);
            this->tasked.value = nv;
            this->tasked.maximumSize = newMax;
        }
    }
    this->tasked.value[this->tasked.numberValue] = unit;
    this->tasked.numberValue++;

tasked_done:
    if (flag == 1) {
        i = 0;
        for (; i < this->civilians.numberValue; i++) {
            if (i >= this->civilians.maximumSize) break;
            if (this->civilians.value[i] == unit) goto haveExplorer;
        }
        {
            ManagedIntArray& civiliansArray = this->civilians;
            i = 0;
            count = civiliansArray.numberValue;
            for (; i < count; i++) {
                if (i >= civiliansArray.maximumSize) break;
                if (civiliansArray.value[i] == unit) goto haveExplorer;
            }
            if (count > civiliansArray.maximumSize - 1) {
                int newMax = count + 1;
                int* nv = (int*)operator_new(newMax * 4);
                if (nv != 0) {
                    i = 0;
                    if (civiliansArray.maximumSize > 0) {
                        while (1) {
                            if (i >= newMax) break;
                            nv[i] = civiliansArray.value[i];
                            i++;
                            if (i >= civiliansArray.maximumSize) break;
                        }
                    }
                    operator_delete(civiliansArray.value);
                    civiliansArray.value = nv;
                    civiliansArray.maximumSize = newMax;
                }
            }
            civiliansArray.value[civiliansArray.numberValue] = unit;
            civiliansArray.numberValue++;
        }
haveExplorer:
        this->removeGatherer(unit);
    }
    MapThing* m = this->md->map;
    m->task((int)m->player_id, unit, 0x2c1, -1, -1, x, y, -1.0f, 1.0f, 1, 0, 1);
    return 1;
}
