// 004EA280 TribeStrategyAIModule::setVictoryCondition
// Attempt log:
// 1: reconstructed unrolled required-goal additions and optional victory-condition processing from packet.
// 2: exact 1231-byte size with straightforward source; first mismatch is prologue/register allocation (rebuilt keeps this in ESI and array in EDI, original keeps this in EBX and array in ESI with EDI=0).
// 3: tried explicit self/arr locals to force EBX/ESI topology; got closer prologue but compiler added push-ecx local home and shrank text to 1216, wrong stack-param slot offsets.
// 4: tried assigning into parameter slot for contains(&param)-style source; VC5 homed it to a new local, unlike original which reuses incoming param stack slot.
// 5: restored best exact-size source. Remaining mismatch is broad from register/local topology and loop tail shape; not accepted_drift-safe.

template<class T>
class ManagedArray {
public:
    T* data;
    int count;
    int unk08;
    int capacity;
    int contains(T* v);
    int resize(int n);
    void add(T v);
    T* operator[](int i);
};

class GoalList {
public:
    char pad[0x10];
    int find(int a, int b);
    int add(int a, int b, int c);
    void add(int a);
};

class TribeStrategyAIModule {
public:
    char pad0[0xF0];
    void* world;       // +F0
    int victory;       // +F4
    char padF8[0x238-0xF8];
    ManagedArray<int> requiredGoals; // +238
    int requiredGoalCount;           // +23c overlaps? layout raw uses +238 array and +23c count in packet actually array.count
    GoalList goodGoals;  // +248
    GoalList badGoals;   // +258
    GoalList goalFinder; // +268
    void setVictoryCondition(int v);
};

#define ARR (*(ManagedArray<int>*)((char*)this + 0x238))
#define COUNT (*(int*)((char*)this + 0x23C))
#define WORLD (*(char**)((char*)this + 0xF0))
#define VICT (*(int*)((char*)this + 0xF4))
#define FINDER (*(GoalList*)((char*)this + 0x268))
#define GOOD (*(GoalList*)((char*)this + 0x248))
#define BAD (*(GoalList*)((char*)this + 0x258))

#define ADD_UNIQUE(v) do { int temp=(v); if (ARR.contains(&temp) != 1) { if (ARR.count > ARR.capacity - 1) ARR.resize(ARR.count + 1); ARR.data[ARR.count] = temp; ARR.count++; } } while(0)

void TribeStrategyAIModule::setVictoryCondition(int v)
{
    VICT = v;
    COUNT = 0;
    ADD_UNIQUE(1);
    ADD_UNIQUE(2);
    ADD_UNIQUE(0x0c);
    ADD_UNIQUE(0x0d);
    ADD_UNIQUE(0x0e);
    ADD_UNIQUE(0x10);
    ADD_UNIQUE(0x11);
    ADD_UNIQUE(0x12);
    ADD_UNIQUE(0x15);
    ADD_UNIQUE(0x16);
    ADD_UNIQUE(0x17);
    ADD_UNIQUE(0x18);
    ADD_UNIQUE(0x19);

    ARR.add(0x1a); ARR.add(0x1b); ARR.add(0x1c); ARR.add(0x1d);
    ARR.add(0x1e); ARR.add(0x1f); ARR.add(0x20); ARR.add(0x21);
    ARR.add(0x22); ARR.add(0x23); ARR.add(0x24); ARR.add(0x25);
    ARR.add(0x26); ARR.add(0x27); ARR.add(0x28); ARR.add(0x29);
    ARR.add(0x2a); ARR.add(0x2b); ARR.add(0x2c); ARR.add(0x2d);
    ARR.add(0x2e); ARR.add(0x2f); ARR.add(0x30); ARR.add(0x31);

    for (int i=0; i<COUNT; i++) {
        int goal = *ARR[i];
        if (FINDER.find(*(int*)(WORLD + 0x1256c), goal) == -2) {
            if (FINDER.add(*(int*)(WORLD + 0x1256c), VICT, goal) == 1) {
                GOOD.add(goal);
            } else {
                BAD.add(goal);
            }
        }
    }
}
