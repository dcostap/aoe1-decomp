// VA: 00414800 UnitAIModule::selectNewPlayPhase (1298B)
// aiuaimod.cpp
// Period-plausible reconstruction of play-phase command selection.
//
// Attempt log:
// - Replaced the raw-pointer placeholder with typed playbook, phase-command,
//   group-member, and UnitAIModule ownership. Baseline follows the packet's
//   five-command phase scan and common order-dispatch tail.
// - Factored all recognized order arms through one common virtual order tail;
//   this fixed the call count and ordered call-site identity (25/25).
// - Mirrored the original member-pointer loop reset, parameter-home target
//   reuse, and case-5 found-object scan. A two-case switch reproduces the
//   original type-6/type-7 sub/dec dispatch.
// - Paused after the bounded ten-hypothesis session. Current source is a
//   typed reconstruction; remaining drift is structural/codegen (1248 vs
//   1298 bytes, frame 0x38 vs 0x44, 1188 positional diff bytes) with all
//   25 calls aligned. No inline asm or raw vtable plumbing is used.
// Main-agent source audit: replaced raw vtable/gap-only World/Player/master/
// object surfaces with donor-backed virtual destructors at unchanged offsets.
// Revalidation is codegen-unchanged; the frame and phase-scan topology remain
// unresolved.

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
    AIPlay* play;
    AIPlayPhase* phase;
    RGE_Static_Object* target;
    RGE_Static_Object* member;
    int phaseCommandIndex;
    int i;
    int sendOrder;
    int orderAction;
    int orderTargetOwner;
    float orderX;
    float orderY;
    float orderZ;
    UnitAIModule* memberAI;
    int distance;
    int groupingOffset;
    RGE_Static_Object* found;

    if (this->playStatus == 0) {
        return 0;
    }

    play = this->objectValue->owner->world->playbook->play(
        this->playStatus->playNumberValue);
    if (play == 0) {
        return 0;
    }

    if (param_1 == 0xFE) {
        operator delete(this->playStatus);
        this->playStatus = 0;
        return 1;
    }

    phase = play->phase(param_1);
    if (phase == 0) {
        return 0;
    }

    target =
        this->lookupObject(this->playStatus->targetValue);
    if (target == 0) {
        return 0;
    }

    this->playStatus->currentPhaseValue = (unsigned char)param_1;

    phaseCommandIndex = 0;
    do {
        AIPlayPhaseCommand* command = phase->command(phaseCommandIndex);
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
                i = 0;
                member = this->objectValue;
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
                            sendOrder = 0;
                            orderAction = 0;
                            orderTargetOwner = -1;
                            orderX = -1.0f;
                            orderY = -1.0f;
                            orderZ = -1.0f;
                            memberAI = 0;

                            switch (command->typeValue) {
                            case 1: {
                                distance = (int)member->distance_to_position(
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
                                found = 0;
                                param_1 = -1;
                                for (groupingOffset = 0;
                                     groupingOffset < 0x190;
                                     groupingOffset += 8) {
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus + groupingOffset);
                                    if (grouping->typeValue == command->value1Value) {
                                        RGE_Static_Object* found =
                                            this->lookupObject(grouping->id);
                                        if (found != 0 &&
                                            (int)found->master_obj->hitPoints + 1 <
                                                found->master_obj->maximumHitPoints) {
                                            param_1 = found->id;
                                            break;
                                        }
                                    }
                                }
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
                                    this->objectValue->id, orderAction,
                                    param_1, orderTargetOwner,
                                    orderX, orderY, orderZ, 1.0f,
                                    1, 0, 100);
                            }
                        }

                        member = this->objectValue;
                        ++i;
                    } while (i < this->objectValue->groupMembers.numberValue);
                }
            }
        }

        ++phaseCommandIndex;
    } while (phaseCommandIndex < 5);

    return 1;
}
