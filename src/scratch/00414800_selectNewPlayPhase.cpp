// VA: 00414800 UnitAIModule::selectNewPlayPhase (1298B)
// aiuaimod.cpp
// Period-plausible reconstruction of play-phase command selection.
//
// Attempt log:
// - Replaced the raw-pointer placeholder with typed playbook, phase-command,
//   group-member, and UnitAIModule ownership.
// - The source keeps all 25 ordered calls and the original direct-call ABI set.
// - Binary tests covered branch shape, loop form, local scope, point layout,
//   coordinate load order, vtable context, and case-5 result lifetime.
// - The case-5 scan uses groupValue at grouping offset +4. The original loads
//   this byte before lookup. It reuses param_1 for the found object id.
// - The case-5 scan uses a body-first do-while. The original increments its
//   8-byte cursor after the body and compares it with 0x190.
// - The best natural source is 1248 rebuilt bytes versus 1298 original bytes.
//   It has a 0x38 frame versus 0x44 and 1188 strict differing bytes.
// - The earlier clean common-tail source had 1186 differing bytes, but kept
//   an extra found-id local and a for loop. Those forms conflict with assembly.
// - Twenty recorded probes did not reach an exact result. The main remaining
//   gap is the original local frame and register schedule.
//
// Current status: structural reconstruction remains incomplete. Keep this
// readable common-tail source as the best behavior-backed candidate.
// MANAGEDARRAY AUDIT: group-member capacity checks, resize calls, value reads,
// and field offsets follow the expected template behavior. No shared template
// change is required.
// BLOCKER: The rebuild is 50 bytes short, with a 0x38 frame versus 0x44 and 29
// fewer instructions. Broad CFG and local-lifetime recovery remains incomplete
// despite all 25 calls aligning.

void __cdecl operator delete(void* block);

class AIPlay;
class AIPlayBook;
class AIPlayPhase;
class AIPlayPhaseCommand;
class AIPlayStatus;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class UnitAIModule;

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int newSize);
};

class AIPlayBook {
public:
    AIPlay* play(int playNumber);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x9C];
    AIPlayBook* playbook;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short maximumHitPoints;
    char gap_28[0x08];
    float hitPoints;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x20];
    ManagedArray<int> groupMembers;

    UnitAIModule* unitAI();
    float distance_to_position(float x, float y, float z);
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_02[2];
    int value1Value;
    int value2Value;
    int value3Value;
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand* command(int index);
};

class AIPlay {
public:
    AIPlayPhase* phase(int phaseNumber);
    int gatherTolerance(int group, int phase);
};

struct AIPlayGrouping {
    int id;
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_06[2];
};

class AIPlayStatus {
public:
    AIPlayGrouping groupings[50];
    int playNumberValue;
    int targetValue;
    int originalPointX;
    int originalPointY;
    int originalPointZ;
    char gap_1A4[0x14];
    unsigned char currentPhaseValue;
    char gap_1B9[3];
    int savedAttackerValue;

    unsigned char group(int id);
    void resetHitPoints(int group, RGE_Game_World* world);
    void removeDeadUnits(int group, RGE_Game_World* world);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);

    RGE_Static_Object* objectValue;
    char gap_08[0x124];
    AIPlayStatus* playStatus;

    RGE_Static_Object* lookupObject(int id);
    int currentAction();
    int selectNewPlayPhase(int phase, int param_2);
};

int UnitAIModule::selectNewPlayPhase(int param_1, int param_2)
{
    int phase = 0;

    if (this->playStatus == 0) {
        return 0;
    }

    AIPlay* play = this->objectValue->owner->world->playbook->play(
        this->playStatus->playNumberValue);
    if (play == 0) {
        return 0;
    }

    if (param_1 == 0xFE) {
        operator delete(this->playStatus);
        this->playStatus = 0;
        return 1;
    }

    AIPlayPhase* phaseObject = play->phase(param_1);
    if (phaseObject == 0) {
        return 0;
    }

    RGE_Static_Object* target =
        this->lookupObject(this->playStatus->targetValue);
    if (target == 0) {
        return 0;
    }

    this->playStatus->currentPhaseValue = (unsigned char)param_1;

    phase = 0;
    do {
        AIPlayPhaseCommand* command = phaseObject->command(phase);
        if (command != 0 && command->typeValue != 0) {
            if ((command->typeValue == 6 || command->typeValue == 7) &&
                param_2 == 0) {
                switch (command->typeValue) {
                case 6:
                    this->playStatus->resetHitPoints(
                        command->groupValue, this->objectValue->owner->world);
                    break;
                case 7:
                    this->playStatus->removeDeadUnits(
                        command->groupValue, this->objectValue->owner->world);
                    break;
                }
            } else {
                int i = 0;
                RGE_Static_Object* member = this->objectValue;
                if (member->groupMembers.numberValue > 0) {
                    do {
                        if (i > member->groupMembers.maximumSizeValue - 1) {
                            member->groupMembers.resize(i + 1);
                        }

                        member = this->lookupObject(member->groupMembers.value[i]);
                        if (member != 0 && member->unitAI() != 0 &&
                            this->playStatus->group(member->id) ==
                                command->groupValue &&
                            (param_2 != 1 ||
                             member->unitAI()->currentAction() == -1)) {
                            int sendOrder = 0;
                            int orderAction = 0;
                            int orderTargetOwner = -1;
                            float orderX = -1.0f;
                            float orderY = -1.0f;
                            float orderZ = -1.0f;
                            UnitAIModule* memberAI = 0;

                            switch (command->typeValue) {
                            case 1: {
                                int distance = (int)member->distance_to_position(
                                    (float)command->value1Value + target->world_x,
                                    (float)command->value2Value + target->world_y,
                                    (float)command->value3Value + target->world_z);
                                if (distance > play->gatherTolerance(
                                        command->groupValue,
                                        this->playStatus->currentPhaseValue)) {
                                    memberAI = member->unitAI();
                                    sendOrder = 1;
                                    orderAction = 0x2C6;
                                    param_1 = -1;
                                    orderX = (float)command->value1Value + target->world_x;
                                    orderY = (float)command->value2Value + target->world_y;
                                    orderZ = (float)command->value3Value + target->world_z;
                                }
                                break;
                            }
                            case 2:
                                memberAI = member->unitAI();
                                sendOrder = 1;
                                orderAction = 0x2BC;
                                param_1 = target->id;
                                orderTargetOwner = target->owner->id;
                                break;
                            case 3:
                                memberAI = member->unitAI();
                                sendOrder = 1;
                                orderAction = 0x2BC;
                                param_1 = this->playStatus->savedAttackerValue;
                                break;
                            case 4:
                                memberAI = member->unitAI();
                                sendOrder = 1;
                                orderAction = 0x2C6;
                                param_1 = -1;
                                orderX = (float)this->playStatus->originalPointX;
                                orderY = (float)this->playStatus->originalPointY;
                                orderZ = (float)this->playStatus->originalPointZ;
                                break;
                            case 5: {
                                param_1 = -1;
                                int groupingOffset = 0;
                                do {
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus + groupingOffset);
                                    if (grouping->groupValue == command->value1Value) {
                                        RGE_Static_Object* found =
                                            this->lookupObject(grouping->id);
                                        if (found != 0 &&
                                            (int)found->master_obj->hitPoints + 1 <
                                                found->master_obj->maximumHitPoints) {
                                            param_1 = found->id;
                                            break;
                                        }
                                    }
                                    groupingOffset += 8;
                                } while (groupingOffset < 0x190);
                                if (param_1 != -1) {
                                    memberAI = member->unitAI();
                                    sendOrder = 1;
                                    orderAction = 0x2BF;
                                }
                                break;
                            }
                            case 8:
                                memberAI = member->unitAI();
                                sendOrder = 1;
                                orderAction = 0x2D8;
                                param_1 = -1;
                                orderX = (float)command->value1Value + target->world_x;
                                orderY = (float)command->value2Value + target->world_y;
                                orderZ = (float)command->value3Value + target->world_z;
                                break;
                            default:
                                break;
                            }

                            if (sendOrder) {
                                memberAI->order(
                                    this->objectValue->id, orderAction, param_1,
                                    orderTargetOwner, orderX, orderY, orderZ,
                                    1.0f, 1, 0, 100);
                            }
                        }

                        member = this->objectValue;
                        ++i;
                    } while (i < this->objectValue->groupMembers.numberValue);
                }
            }
        }

        ++phase;
    } while (phase < 5);

    return 1;
}
