// VA: 00506140 TribePriestUnitAIModule::processMisc
// PDB: taiuaimd.cpp:1761-1796
//
// Attempt log:
// baseline: natural UnitAIModule/Action_Object ownership, direct helper
// methods, and the period Priest virtual surface; exact 247-byte match.

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;

class RGE_Player {
public:
    int computerPlayer();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[0x08];
    uchar state;
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    char gap_04[4];
    uchar have_action();
    RGE_Action* get_action();
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    int id;
    char gap_08[4];
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
    char gap_48[0x13C];
    RGE_Action_List* actions;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*);
    virtual int canAttackUnit(void*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int);
    virtual int attackObject(int, int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int, int);
    virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int);
    virtual int repairObject(int, int);
    virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int);
    virtual int explore(int, int, int);
    virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int);
    virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(void*, int);
    virtual int processNotify(void*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

    RGE_Action_Object* objectValue;
    char gap_08[0x20];
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;
    int currentTargetValue;
    char gap_38[4];
    float currentTargetXValue;
    float currentTargetYValue;
    float currentTargetZValue;
    float desiredTargetDistanceValue;
    char gap_4C[4];
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    int processMisc();
};

extern FILE* actionFile;

int TribePriestUnitAIModule::processMisc()
{
    if (this->objectValue->owner->computerPlayer() == 1) {
        RGE_Action_Object* object = this->objectValue;

        if (object->attribute_amount_held >= 100.0f) {
            if (object->actions->have_action() != 1 ||
                object->actions->get_action()->state != 7) {
                int target = this->bestUnitToAttack(1, 1, 0);

                if (target != -1 && this->currentTargetValue != target) {
                    if (this->currentOrderValue != -1) {
                        this->order(
                            this->objectValue->id,
                            this->currentOrderValue,
                            this->currentTargetValue,
                            -1,
                            this->currentTargetXValue,
                            this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue,
                            0,
                            0,
                            this->currentOrderPriorityValue);

                        if (actionFile != 0) {
                            int objectID;
                            if (this->objectValue != 0) {
                                objectID = this->objectValue->id;
                            } else {
                                objectID = -1;
                            }
                            fprintf(actionFile,
                                "#%d call stopObject %s %d\n",
                                objectID,
                                "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp",
                                0x6F8);
                        }

                        this->stopObject(1);
                    }

                    if (this->attackObject(target, 1) == 1) {
                        return 10;
                    }
                }
            }
        }
    }

    return 9;
}
