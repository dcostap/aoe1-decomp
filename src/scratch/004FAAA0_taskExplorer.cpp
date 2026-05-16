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
// Left in scratch: best source (before this rollback note) has matching size under check_function but actual object is a few bytes longer; main remaining drift is search-loop entry shape (rebuilt inserts redundant `test ecx,ecx` after loading max) and slight branch displacement drift. Copy-growth loops and final virtual call are close after while(1) copy and int/movsx task parameter.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

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
    int* civilian_value;        // +104
    int civilian_number;        // +108
    int civilian_pad;           // +10c
    int civilian_max;           // +110
    char pad114[0xd58 - 0x114];
    int* tasked_value;          // +d58
    int tasked_number;          // +d5c
    int tasked_pad;             // +d60
    int tasked_max;             // +d64

    int taskExplorer(int unit, float x, float y, int flag);
    int removeGatherer(int unit);
};

int TribeTacticalAIModule::taskExplorer(int unit, float x, float y, int flag)
{
    int i = 0;
    int count = this->tasked_number;
    if (count > 0) {
        int max = this->tasked_max;
        for (; i < count && i < max; i++) {
            if (this->tasked_value[i] == unit) goto tasked_done;
        }
    }
    if (count > this->tasked_max - 1) {
        int newMax = count + 1;
        int* nv = (int*)operator_new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->tasked_max > 0) {
                while (1) {
                    if (i >= newMax) break;
                    nv[i] = this->tasked_value[i];
                    i++;
                    if (i >= this->tasked_max) break;
                }
            }
            operator_delete(this->tasked_value);
            this->tasked_value = nv;
            this->tasked_max = newMax;
        }
    }
    this->tasked_value[this->tasked_number] = unit;
    this->tasked_number++;

tasked_done:
    if (flag == 1) {
        i = 0;
        count = this->civilian_number;
        if (count > 0) {
            int max = this->civilian_max;
            for (; i < count && i < max; i++) {
                if (this->civilian_value[i] == unit) goto haveExplorer;
            }
        }
        i = 0;
        count = this->civilian_number;
        if (count > 0) {
            int max = this->civilian_max;
            for (; i < count && i < max; i++) {
                if (this->civilian_value[i] == unit) goto haveExplorer;
            }
        }
        if (count > this->civilian_max - 1) {
            int newMax = count + 1;
            int* nv = (int*)operator_new(newMax * 4);
            if (nv != 0) {
                i = 0;
                if (this->civilian_max > 0) {
                    while (1) {
                        if (i >= newMax) break;
                        nv[i] = this->civilian_value[i];
                        i++;
                        if (i >= this->civilian_max) break;
                    }
                }
                operator_delete(this->civilian_value);
                this->civilian_value = nv;
                this->civilian_max = newMax;
            }
        }
        this->civilian_value[this->civilian_number] = unit;
        this->civilian_number++;
haveExplorer:
        this->removeGatherer(unit);
    }
    MapThing* m = this->md->map;
    m->task((int)m->player_id, unit, 0x2c1, -1, -1, x, y, -1.0f, 1.0f, 1, 0, 1);
    return 1;
}
