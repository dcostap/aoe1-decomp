// VA: 00506320 TribeTradeShipUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 1823-1976
// Attempt log:
// - Clean baseline: restored the period typed UnitAIModule/RGE_Static_Object/
//   RGE_Player surfaces from exact taiuaimd.cpp siblings.  The notification
//   list and growth path follows the matching fishing/transport implementations;
//   trade retry uses the proven closestObject/tradeWithObject and
//   closestUndiscoveredTile/explore virtual slots.  The +0x1c callback in the
//   retry cleanup is UnitAIModule::notifyCommander(NotifyEvent*), not a
//   recursive processNotify call.
// - Baseline was exact in size/frame/CFG with a 3-byte mismatch: the trade
//   retry dispatch read +0x28, while the oracle reads currentAction at +0x30.
// - Correcting both retry comparisons to currentActionValue reduced the gap
//   to two bytes; the only remaining issue was the +0x18/+0x1c overload slot.
// - A pointer overload declared after the six-argument notifyCommander (and a
//   void*/distinct-name diagnostic) selected +0x18 under VC5.  Mirroring the
//   exact sibling's pointer-before-six-argument declaration order selects the
//   proven +0x1c callback and closes the match.  No custom flags or asm.

#include <stdio.h>

#ifndef TAIUAIMD_COMPLETE_TU
typedef unsigned long ulong;

extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);
extern FILE* actionFile;

struct NotifyEvent {
    int caller;
    char gap_04[4];
    int mType;
    char gap_0c[4];
    int p2;
};

class RGE_Player {
public:
    virtual ~RGE_Player(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56(); virtual void p57();
    virtual void notifyCommander(int, int, int, long, long, long); // +0xe8
    int computerPlayer();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual void ve0(); virtual void ve4();
    virtual unsigned char underAttack(); // +0xe8
    virtual void setUnderAttack(unsigned char one); // +0xec

    int id;                         // +0x04
    void* master_obj;               // +0x08
    RGE_Player* owner;              // +0x0c
    char gap_10[0x174];
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*); // +0x40
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int); // +0x48
    virtual void logDebug(char*);
    virtual int canAttackUnit(void*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int); // +0x58
    virtual int attackObject(int, int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int, int);
    virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int);
    virtual int repairObject(int, int);
    virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int); // +0x7c
    virtual int explore(int, int, int); // +0x80
    virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int); // +0xa4
    virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(void*, int);
    virtual int processNotify(NotifyEvent*, ulong);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

    RGE_Static_Object* objectValue;       // +0x04
    int moodValue;                        // +0x08
    int objectCategoryValue;              // +0x0c
    int orderQueueSizeValue;              // +0x10
    int orderQueueMaxSizeValue;           // +0x14
    void* orderQueueValue;                // +0x18
    int notifyQueueSizeValue;             // +0x1c
    int notifyQueueMaxSizeValue;          // +0x20
    void* notifyQueueValue;               // +0x24
    int currentOrderValue;                // +0x28
    int currentOrderPriorityValue;        // +0x2c
    int currentActionValue;               // +0x30
    int currentTargetValue;               // +0x34
    int currentTargetTypeValue;           // +0x38
    float currentTargetXValue;            // +0x3c
    float currentTargetYValue;            // +0x40
    float currentTargetZValue;            // +0x44
    float desiredTargetDistanceValue;     // +0x48
    int defendTargetValue;                // +0x4c
    int lastOrderValue;                   // +0x50
    int lastActionValue;                  // +0x54
    int lastTargetValue;                  // +0x58
    int lastTargetTypeValue;              // +0x5c
    int* helpList;                        // +0x60
    int helpCount;                        // +0x64
    int helpDesired;                      // +0x68
    int helpMax;                          // +0x6c

    int addToWaypointQueue(int, int);
    void purgeNotifyQueue(ulong param_2);
    void askForHelp(int caller);
    void removeCurrentTarget();
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, ulong param_2);
};
#endif

int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;

    case 0x202:
        if (this->currentActionValue == 0x267) {
            int id = this->closestObject(-1, 0, 2, 0x2d, 0);
            if (id != -1 && this->tradeWithObject(id, 1) == 1) {
                return 6;
            }

            id = this->closestObject(-1, 1, 2, 0x2d, 0);
            if (id != -1 && this->tradeWithObject(id, 1) == 1) {
                return 6;
            }
        } else if (this->currentActionValue == 0x25d) {
            int x;
            int y;
            if (this->closestUndiscoveredTile(&x, &y, 1) == 1) {
                this->addToWaypointQueue(x, y);
                if (this->explore(x, y, 1) == 0) {
                    this->removeCurrentTarget();
                    if (actionFile != 0) {
                        int id;
                        if (this->objectValue != 0) {
                            id = this->objectValue->id;
                        } else {
                            id = -1;
                        }
                        fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                                "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x79c);
                    }
                    this->stopObject(1);
                    this->notifyCommander(event);
                }
            } else {
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    int id;
                    if (this->objectValue != 0) {
                        id = this->objectValue->id;
                    } else {
                        id = -1;
                    }
                    fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                            "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7a8);
                }
                this->stopObject(1);
                this->notifyCommander(event);
            }
        }

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x7b0);
        }
        this->stopObject(1);
        this->notifyCommander(event);
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
#ifdef TAIUAIMD_COMPLETE_TU
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x209, event->caller, 0, 0);
#else
        obj->owner->notifyCommander(obj->id, obj->id, 0x209, event->caller, 0, 0);
#endif
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->helpCount == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
#ifdef TAIUAIMD_COMPLETE_TU
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x201, event->caller, 0, 0);
#else
        obj->owner->notifyCommander(obj->id, obj->id, 0x201, event->caller, 0, 0);
#endif
    }

    int count = this->helpCount;
    int i = 0;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == event->caller) {
            goto skip_help;
        }
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != event->caller) {
        this->askForHelp(event->caller);
    }

skip_help:
    i = 0;
    int caller = event->caller;
    count = this->helpCount;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == caller) {
            goto after_add;
        }
    }

    if (this->helpCount > this->helpMax - 1) {
        int newMax = this->helpCount + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->helpMax && i < newMax; ++i) {
                newList[i] = this->helpList[i];
            }
            operator delete(this->helpList);
            this->helpList = newList;
            this->helpMax = newMax;
        }
    }
    this->helpList[this->helpCount] = caller;
    this->helpCount++;

after_add:
    this->objectValue->setUnderAttack(1);
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x761);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}
