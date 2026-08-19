// 00503070 TribeTacticalAIModule::taskElephantGatherers(int,int,int)
// Source: taitacmd.cpp lines 13148-13219
// FLAGS: config/flags/00503070_taskElephantGatherers.rsp
// Attempt log:
// - Fresh typed reconstruction from the exact same-TU tactical task donors.
// - Canonical ownership: md +0xF0; gatherers +0x51C with 0x18-byte UnitData;
//   numberGatherersValue +0x9CC; local ManagedArray<int> fields are value,
//   numberValue, desiredNumberValue, and maximumSizeValue.
// - The original initializes one local ManagedArray slot with resize(1), then
//   appends first through numberValue. The desiredNumberValue field is not used.
// - Baseline: typed source reached 620 bytes with the correct 0x20 frame and
//   nine-call set; first mismatch was the outer scan setup, not a call boundary.
// - Correcting UnitData to 0x18 bytes restored the proven +0x9CC gatherer count
//   and improved block shape. Adding MainDecision objects at +0xF4 restored
//   aiPlayer +0x1256C and improved exact-block coverage again.
// - Hoisted local declarations, swapped declaration order, matched the
//   preincrement growth copy, and tested a counted outer loop. These produced
//   duplicate code or only register/home drift. Reversed duplicate-scan compare
//   operands reduced exact-block coverage and was restored.
// - Replaced the outer counted for with a typed do-while to match the original
//   count-positive entry guard and tail test; emitted code was unchanged and
//   the clean counted-loop reconstruction was restored.
// - Canonical bounded indexed scans removed the extra bottom capacity tests and
//   restored the original scan blocks. The donor-style two-condition growth
//   copy restored its complete copy block and reduced the best diff to 174.
// - Direct return on no selected gatherer restored the original cold cleanup
//   size, but changed later liveness; the shared break is retained instead.
// - Best current check: 600 rebuilt bytes versus 618 original, 92.50% shape,
//   89.85% exact-block coverage, 100% ordered-call alignment, and 174 strict
//   differing bytes. The remaining structural hunk starts at outer-loop zero
//   register setup; the FPU predicate remains a separate codegen gap.
// - Revisited with the natural counted while, the reviewed DAT_00575758
//   sentinel, and bestDistance > distance. The external sentinel and operand
//   order recover the original fcomp/test-ah,41 sequence.
// - Returning directly when no gatherer is selected recovers the original
//   separate destructor cleanup block: 618 bytes, 197 instructions, exact
//   frame/CFG/call count, and 13/13 relocation identities.
// - Current best is a four-byte local scheduling drift at +012E: VC5 reloads
//   maximumSizeValue before numberValue, while the original reverses them.
//   Expanded updates were duplicate codegen; pointer-first updates and a
//   cached count were worse and were restored.
// ACCEPTED DRIFT: The four changed bytes move two adjacent stack reloads past
//   each other. The original loads numberValue into ECX, then maximumSizeValue
//   into ESI. The rebuild reverses these loads. No instruction occurs between
//   them, and both registers have the same values before the next instruction.
//   Calls, writes, predicates, fault order, cleanup, and all later bytes match.
// - No unsupported raw vtable or inline-assembly form is retained.

void* operator new(unsigned int size);
void operator delete(void* ptr);
extern float DAT_00575758;

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    int resize(int newSize);

    ~ManagedArray() {
        if (this->value != 0)
            operator delete(this->value);
    }
};

struct UnitData {
    int id;
    int data1;
    char gap_08[0x10];
};

class RGE_Player;

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;

    void* unitAI();
    float distance_to_object(RGE_Static_Object* object);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    ManagedArray<int> objects;

    RGE_Static_Object* object(int id);
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void vpad_01();
    virtual void vpad_02();
    virtual void vpad_03();
    virtual void vpad_04();
    virtual void vpad_05();
    virtual void vpad_06();
    virtual void vpad_07();
    virtual void vpad_08();
    virtual void vpad_09();
    virtual void vpad_10();
    virtual void vpad_11();
    virtual void vpad_12();
    virtual void vpad_13();
    virtual void vpad_14();
    virtual void vpad_15();
    virtual void vpad_16();
    virtual void vpad_17();
    virtual void vpad_18();
    virtual void vpad_19();
    virtual void vpad_20();
    virtual void vpad_21();
    virtual void vpad_22();
    virtual void vpad_23();
    virtual void vpad_24();
    virtual void vpad_25();
    virtual void vpad_26();
    virtual void vpad_27();
    virtual void vpad_28();
    virtual void vpad_29();
    virtual void vpad_30();
    virtual void vpad_31();
    virtual void vpad_32();
    virtual void vpad_33();
    virtual void vpad_34();
    virtual void vpad_35();
    virtual void vpad_36();
    virtual void vpad_37();
    virtual void vpad_38();
    virtual void vpad_39();
    virtual void vpad_40();
    virtual void vpad_41();
    virtual void vpad_42();
    virtual void vpad_43();
    virtual void vpad_44();
    virtual void vpad_45();
    virtual void vpad_46();
    virtual void vpad_47();
    virtual void vpad_48();
    virtual void vpad_49();
    virtual void vpad_50();
    virtual void vpad_51();
    virtual void vpad_52();
    virtual void vpad_53();
    virtual void vpad_54();
    virtual void vpad_55();
    virtual void vpad_56();
    virtual void vpad_57();
    virtual void vpad_58();
    virtual void vpad_59();
    virtual void vpad_60();
    virtual void vpad_61();
    virtual void vpad_62();
    virtual void vpad_63();
    virtual void vpad_64();
    virtual void vpad_65();
    virtual void vpad_66();
    virtual void vpad_67();
    virtual void vpad_68();
    virtual void vpad_69();
    virtual void vpad_70();
    virtual void vpad_71();
    virtual void vpad_72();
    virtual void taskResourceGatherer(int unitID, int targetID, int ownerID,
                                      float x, float y);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    TRIBE_Player* aiPlayer;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_F4[0x51C - 0xF4];
    UnitData gatherers[50];
    int numberGatherersValue;

    void taskElephantGatherers(int first, int count, int target);
};

void TribeTacticalAIModule::taskElephantGatherers(int first, int count, int target)
{
    RGE_Static_Object* targetObject = this->md->object(target);
    if (targetObject != 0) {
        ManagedArray<int> alreadyTasked;
        int loop;

        alreadyTasked.resize(1);
        alreadyTasked.value[alreadyTasked.numberValue] = first;
        alreadyTasked.numberValue++;
        loop = 0;

        while (loop < count) {
                float bestDistance;
                int bestValueID;
                int i;
                bestDistance = -1.0f;
                bestValueID = -1;
                i = 0;

                if (this->numberGatherersValue > 0) {
                    UnitData* gatherer = this->gatherers;
                    do {
                        RGE_Static_Object* object;
                        for (int j = 0; j < alreadyTasked.numberValue; j++) {
                            if (j >= alreadyTasked.maximumSizeValue)
                                break;
                            if (alreadyTasked.value[j] == gatherer->id)
                                goto nextGatherer;
                        }

                        object = this->md->object(gatherer->id);
                        if (object != 0 && object->unitAI() != 0 &&
                            gatherer->data1 == 0) {
                            float distance = object->distance_to_object(targetObject);
                            if (bestDistance == DAT_00575758 ||
                                bestDistance > distance) {
                                bestValueID = gatherer->id;
                                bestDistance = distance;
                            }
                        }

nextGatherer:
                        i++;
                        gatherer++;
                    } while (i < this->numberGatherersValue);
                }

                if (bestValueID == -1)
                    return;

                this->md->aiPlayer->taskResourceGatherer(
                    bestValueID, target, 0,
                    targetObject->world_x, targetObject->world_y);

                for (int j = 0; j < alreadyTasked.numberValue; j++) {
                    if (j >= alreadyTasked.maximumSizeValue)
                        break;
                    if (alreadyTasked.value[j] == bestValueID)
                        goto afterAdd;
                }

                if (alreadyTasked.numberValue >
                    alreadyTasked.maximumSizeValue - 1) {
                    int newSize = alreadyTasked.numberValue + 1;
                    int* newValue = new int[newSize];
                    if (newValue != 0) {
                        for (int k = 0;
                             k < alreadyTasked.maximumSizeValue && k < newSize;
                             k++) {
                            newValue[k] = alreadyTasked.value[k];
                        }
                        operator delete(alreadyTasked.value);
                        alreadyTasked.value = newValue;
                        alreadyTasked.maximumSizeValue = newSize;
                    }
                }

                alreadyTasked.value[alreadyTasked.numberValue] = bestValueID;
                alreadyTasked.numberValue++;

afterAdd:
                loop++;
        }
    }
}
