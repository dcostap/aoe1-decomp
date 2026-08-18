// Attempt log for 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// Prior worker notes: a raw-offset scaffold rebuilt 736B vs 740B but used the
// wrong array ownership, object/finder shims, and manual removal/growth shape.
// The current reconstruction restores the same-TU typed ManagedArray surface,
// soldiers at +0x114, ungroupedSoldiers at +0x124, and informationAI at +0xCEC.
//
// Original CodeView symbols prove these stack locals: i at -0x1C, soldierObj
// at -0x14, centerPoint at -0x10, and gatherPoint at -0x08. The two final
// integer loads are gatherPoint.x and gatherPoint.y. They are not an
// uninitialized local.
//
// Claim sa-209e8cdc (21 meaningful hypotheses):
// - Probe 1 established a 760B raw-cast baseline with all 15 calls.
// - Probes 2-4 restored typed soldier objects and XYPoint references. They
//   reached the best 754B basin: 493 strict-diff bytes, 86.36% shape, 1C frame.
// - Probe 5 changed the soldiers alias to a pointer. It reached 757B and was
//   worse. Probe 6 used direct soldiers.value access and lost two allocations.
// - Probe 7 used a concrete ManagedArray_int. It stayed at the 757B basin.
// - Probe 8 used direct this->soldiers access. It reached 776B and drifted.
// - Probes 9-10 tested standard XYPoint fields and local object scope. They
//   stayed at the 757B basin. Probe 11 moved soldier loading before the scan.
//   It reached 751B but lost the original control-flow shape.
// - Probes 12-13 tested direct world_time spelling and an ungrouped reference.
//   Both were codegen duplicates of the best basin.
// - Probe 14 changed both scans to while loops. It reached 744B but changed
//   the frame to 20h and lost exact block islands.
// - Probe 15 repeated the soldier lifetime test with a function-scope local.
//   It stayed at the 751B basin. Probe 16 replaced one known class surface
//   with an explicit vptr. It was a codegen duplicate and was rejected by
//   policy. Probe 17 added math.h. It was a duplicate.
// - Probe 18 used operator[] for every soldier read. It reached 1229B and
//   added five allocation pairs. The observed resize call set requires the
//   explicit capacity touches in this source.
// - Probes 19-20 tested XYPoint declaration order and soldier declaration
//   order. They were duplicates or returned to the 751B basin.
// - Probe 21 used the then-assumed uninitialized local. Later CodeView evidence
//   disproved that interpretation.
//
// Main-agent pass, 2026-08-18:
// - Translation-unit tests with zero through twelve dummy predecessors and
//   exact idle/play/active predecessors emitted identical target bytes.
// - Replacing only the first ungrouped membership do-loop with the exact-donor
//   for-loop recovered the original EBX outer index and delayed EDI save. It
//   reduced the strict diff from 493 to 230 bytes.
// - Index-left capacity predicates recovered five original cmp/branch forms.
//   The best natural source is now 747/740 bytes, 15/15 ordered calls, exact
//   0x1C frame, 93.49% shape, 77.91% exact blocks, and 222 differing bytes.
// - At that point, the remaining seven-byte region was the second membership
//   scan. VC5 turned
//   its natural cached-count do-loop into a pointer induction with one extra
//   conditional block. For/while, explicit-break, scope, pointer, and source
//   order variants either duplicate this basin or damage the frame and early
//   register allocation. Point/local declaration permutations are duplicates.
//
// CodeView and ManagedArray pass, 2026-08-18:
// - Restoring normal centerPoint and gatherPoint ownership made every block
//   outside the second membership scan exact in the 747-byte basin.
// - Exact donor 004DE980 proves the second indexed scan as an inlined
//   ManagedArray::contains operation. The source then calls resize and appends
//   explicitly. Exact add donor 004DE9D0 allocates directly, so add is not the
//   source owner of this block.
// - The exact contains body and explicit append emit the same 343-byte
//   frontier as the earlier add model. Size, frame, saved registers, and calls
//   are exact.
// - Using the exact contains body for the first scan recovers that local CFG,
//   but changes the frame to 0x20 and the function-wide register assignment.
//   Dummy and real predecessor context emits identical target code.
// - Out-of-class template definitions, exact donor temporaries, timestamp and
//   object lifetimes, outer for/continue forms, and positive guard nesting do
//   not resolve that allocation tradeoff. They are duplicates or regressions.
//   A same-template contains predecessor also leaves target code unchanged.
// BLOCKER: preserve the PDB-proven point homes and second contains/append
// model. Recover the first scan without changing the register allocation.

#include <stdlib.h>

struct XYPoint {
    int x;
    int y;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = new T[new_size];
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                delete[] this->value;
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int contains(const T& item) const {
        int i;
        T wanted;
        T current;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            wanted = item;
            if (current == wanted)
                return 1;
        }
        return 0;
    }

    int remove(T valueToRemove) {
        int i = 0;
        int max = this->maximumSizeValue;
        for (; i < max; ++i) {
            if (this->value[i] == valueToRemove)
                break;
        }
        if (i >= max)
            return 0;

        --max;
        if (i < max) {
            do {
                this->value[i] = this->value[i + 1];
                ++i;
            } while (i < this->maximumSizeValue - 1);
        }

        int n = this->numberValue - 1;
        this->numberValue = n;
        if (n < 0)
            this->numberValue = 0;
        return 1;
    }

    int resize(int new_size);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int findGatherPosition(XYPoint& center, int desiredUnits, int flag,
                           int sn16, int sn48, RGE_Static_Object* object,
                           XYPoint& gather);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;

    RGE_Static_Object* object(int objectID);
    RGE_Static_Object* object(int objectID, int type, int objectClass,
                              int action, int hasOrderFilter,
                              int resourceClass, int resourceSubclass,
                              int state, int minHitPoints,
                              int civilization);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TacticalAIGroup;

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[226];
    char gap_51C[0xFA8 - 0x51C];
    unsigned long lastUngroupedSoldierTaskTime;

    TacticalAIGroup* groupUnitIsIn(int unit);
    void moveUnit(int unit, float x, float y, int priority);
    void taskUngroupedSoldiers();
};

void TribeTacticalAIModule::taskUngroupedSoldiers()
{
    int i;
    XYPoint centerPoint;
    RGE_Static_Object* soldierObj;
    XYPoint gatherPoint;

    unsigned long currentTime = this->md->player->world->world_time;
    if ((currentTime - this->lastUngroupedSoldierTaskTime) / 1000 >= 60) {
        this->lastUngroupedSoldierTaskTime = currentTime;
        soldierObj = this->md->object(
            -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
        if (soldierObj != 0) {
            centerPoint.x = (int)soldierObj->world_x;
            centerPoint.y = (int)soldierObj->world_y;
            i = 0;
            if (0 < this->soldiers.numberValue) {
                ManagedArray<int>& soldiers = this->soldiers;
                do {
                    if (i > soldiers.maximumSizeValue - 1) {
                        soldiers.resize(i + 1);
                    }

                    TacticalAIGroup* group =
                        this->groupUnitIsIn(soldiers.value[i]);
                    if (group != 0) {
                        if (i > soldiers.maximumSizeValue - 1) {
                            soldiers.resize(i + 1);
                        }
                        this->ungroupedSoldiers.remove(
                            soldiers.value[i]);
                    }
                    else {
                        if (i > soldiers.maximumSizeValue - 1) {
                            soldiers.resize(i + 1);
                        }
                        soldierObj = this->md->object(soldiers.value[i]);
                        if (soldierObj != 0) {
                            if (i > soldiers.maximumSizeValue - 1) {
                                soldiers.resize(i + 1);
                            }

                            ManagedArray<int>* ungrouped =
                                &this->ungroupedSoldiers;
                            int j = 0;
                            if (0 < ungrouped->numberValue) {
                                do {
                                    if (j >= ungrouped->maximumSizeValue)
                                        break;
                                    if (ungrouped->value[j] == soldiers.value[i])
                                        goto next_soldier;
                                    j++;
                                } while (j < ungrouped->numberValue);
                            }

                            {
                                int soldier = soldiers[i];
                                if (ungrouped->contains(soldier) == 0) {
                                    int count = ungrouped->numberValue;
                                    if (count >
                                        ungrouped->maximumSizeValue - 1) {
                                        ungrouped->resize(count + 1);
                                    }
                                    ungrouped->value[ungrouped->numberValue] =
                                        soldier;
                                    ungrouped->numberValue++;
                                }

                            {
                                int result =
                                    this->md->informationAI.findGatherPosition(
                                        centerPoint, 1, 1,
                                        this->sn[0x16], this->sn[0x48],
                                        soldierObj, gatherPoint);
                                if (result == 1) {
                                    if (i > soldiers.maximumSizeValue - 1) {
                                        soldiers.resize(i + 1);
                                    }
                                    this->moveUnit(
                                        soldiers.value[i],
                                        (float)gatherPoint.x,
                                        (float)gatherPoint.y, 0x32);
                                }
                            }
                            }
                        }
                    }

                next_soldier:
                    i = i + 1;
                } while (i < this->soldiers.numberValue);
            }
        }
    }
}
