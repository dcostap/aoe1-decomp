#pragma once
#include "../common.h"
#include "stat_obj.h"
#include "player.h"
#include "m_an_obj.h"
#include "aipbook.h"

class UnitAIModule {
public:
    RGE_Static_Object* objectValue;          // 0x4
    int moodValue;                           // 0x8
    int objectCategoryValue;                 // 0xC
    int orderQueueSizeValue;                 // 0x10
    int orderQueueMaxSizeValue;              // 0x14
    OrderEvent* orderQueueValue;             // 0x18
    int notifyQueueSizeValue;                // 0x1C
    int notifyQueueMaxSizeValue;             // 0x20
    NotifyEvent* notifyQueueValue;           // 0x24
    int currentOrderValue;                   // 0x28
    int currentOrderPriorityValue;           // 0x2C
    int currentActionValue;                  // 0x30
    int currentTargetValue;                  // 0x34
    int currentTargetTypeValue;              // 0x38
    float currentTargetXValue;               // 0x3C
    float currentTargetYValue;               // 0x40
    float currentTargetZValue;               // 0x44
    float desiredTargetDistanceValue;        // 0x48
    int defendTargetValue;                   // 0x4C
    int lastOrderValue;                      // 0x50
    int lastActionValue;                     // 0x54
    int lastTargetValue;                     // 0x58
    int lastTargetTypeValue;                 // 0x5C
    ManagedArray_int attackingUnitsValue;   // 0x60
    Waypoint waypointQueue[8];               // 0x70
    int waypointQueueSizeValue;              // 0xF0
    ulong lastUpdateTimeValue;               // 0xF4
    ulong idleTimerValue;                    // 0xF8
    ulong adjustedIdleTimeoutValue;          // 0xFC
    ulong idleTimeoutValue;                  // 0x100
    ulong secondaryTimerValue;               // 0x104
    ulong lookAroundTimerValue;              // 0x108
    ulong lookAroundTimeoutValue;            // 0x10C
    Waypoint lastWorldPositionValue;         // 0x110
    float defenseBufferValue;                // 0x120
    int* importantObjects;                   // 0x124
    int numberImportantObjects;              // 0x128
    AIPlayStatus* playStatus;                // 0x12C
    uchar stopAfterTargetKilledValue;        // 0x130

    UnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~UnitAIModule();
    virtual void save(int param_1);
    virtual void load(int param_1);
    virtual RGE_Player* owner();
    virtual RGE_Static_Object* object();
    virtual int objectID();
    virtual int objectCategory();
    virtual int mood();
    virtual ulong lastUpdateTime();
    virtual ulong idleTimer();
    virtual ulong idleTimeout();
    virtual ulong secondaryTimer();
    virtual float defenseBuffer();
    virtual int canConvert(int param_1);
    virtual void setDefenseBuffer(float param_1);
    virtual int orderQueueSize();
    virtual OrderEvent* orderQueueElement(int param_1);
    virtual void purgeOrderQueue();
    virtual int currentOrder();
    virtual void setCurrentOrder(int param_1);
    virtual int currentOrderPriority();
    virtual void setCurrentOrderPriority(int param_1);
    virtual int currentAction();
    virtual void setCurrentAction(int param_1);
    virtual int currentTarget();
    virtual int currentTargetType();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual int lastAction();
    virtual int lastOrder();
    virtual int lastTarget();
    virtual int lastTargetType();
    virtual float desiredTargetDistance();
    virtual int attackingUnitID(int param_1);
    virtual int numberAttackingUnits();
    virtual int update(ulong param_1);
    virtual void updateGroup(ulong param_1);
    virtual int selectNewPlayPhase(int param_1, int param_2);
    virtual int order(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10, int param_11);
    virtual int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual int notifyCommander(NotifyEvent* param_1);
    virtual int notifyCommander(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual void search();
    virtual int importantWhenDead(int param_1);
    virtual int retryableOrder(int param_1);
    virtual int actionRequiresLiveTarget(int param_1);
    virtual int bestUnitToAttack(int param_1, int param_2, float* param_3);
    virtual int mostDangerousEnemy(float* param_1);
    virtual int weakestEnemy(float* param_1);
    virtual int closestAttacker(float* param_1);
    virtual int closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5);
    virtual int closestResourceObject(int param_1, int* param_2);
    virtual int closestUndiscoveredTile(int* param_1, int* param_2, int param_3);
    virtual Waypoint* waypoint(int param_1);
    virtual int waypointQueueSize();
    virtual int addToWaypointQueue(int param_1, int param_2);
    virtual int inWaypointQueue(int param_1, int param_2);
    virtual void clearWaypointQueue();
    virtual int canAttackUnit(RGE_Static_Object* param_1);
    virtual int canAttackUnitAtNeutrality(int param_1);
    virtual int stopObject(int param_1);
    virtual int attackObject(int param_1, int param_2);
    virtual int attackRoundupObject(int param_1);
    virtual int huntObject(int param_1, int param_2);
    virtual int convertObject(int param_1, int param_2);
    virtual int healObject(int param_1, int param_2);
    virtual int gatherObject(int param_1, int param_2);
    virtual int repairObject(int param_1, int param_2);
    virtual int buildObject(int param_1, int param_2);
    virtual int tradeWithObject(int param_1, int param_2);
    virtual int explore(int param_1, int param_2, int param_3);
    virtual int enterObject(int param_1, int param_2);
    virtual int transportObject(float param_1, float param_2, float param_3, int param_4);
    virtual int unload(int param_1, float param_2, float param_3);
    virtual int moveTo(int param_1, int param_2);
    virtual int moveTo(int param_1, float param_2, int param_3);
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    virtual int evasiveMoveTo(float param_1, float param_2, float param_3, int param_4);
    virtual int intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5);
    virtual int runAwayFromAttackers(int param_1);
    virtual int followObject(int param_1, float param_2, int param_3);
    virtual int defendObject(int param_1, float param_2, int param_3);
    virtual int defendPosition(float param_1, float param_2, float param_3, int param_4);
    virtual int seekAndDestroy(int param_1, int param_2, int param_3, int param_4);
    virtual int exploreAndDestroy(int param_1, int param_2, int param_3);
    virtual void removeCurrentTarget();
    virtual void setCurrentTarget(int param_1, float param_2, float param_3, float param_4);
    virtual void setCurrentTarget(int param_1, int param_2, float param_3, float param_4, float param_5);
    virtual int importantObject(int param_1);
    virtual int isEnemyOwner(int param_1);
    virtual int isAllyOwner(int param_1);
    virtual int isNeutralOwner(int param_1);
    virtual uchar visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3);
    virtual void setAdjustedIdleTimeout();
    virtual void setTaskedByPlayer();
    virtual int convertToLOSResourceType(int param_1);
    virtual void setPlayStatus(AIPlayStatus* param_1);
    virtual void lookAround();
    virtual int hasOrderOnQueue(int param_1);
    virtual void askForHelp(int param_1);
    virtual int processOrder(OrderEvent* param_1, int param_2);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual void processGroupNotify(NotifyEvent* param_1);
    virtual int processIdle(int param_1);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int addToOrderQueue(OrderEvent* param_1, int param_2);
    virtual int addToOrderQueue(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10);
    virtual int addToNotifyQueue(NotifyEvent* param_1);
    virtual int addToNotifyQueue(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual void purgeNotifyQueue(ulong param_1);
    virtual RGE_Static_Object* lookupObject(int param_1);
    virtual void logDebug(char* param_1);
};

static_assert(sizeof(UnitAIModule) == 0x134, "UnitAIModule Size Mismatch");
static_assert(offsetof(UnitAIModule, stopAfterTargetKilledValue) == 0x130, "UnitAIModule Offset Mismatch");

int UnitAIModule::canConvert(int param_1) {
    /* TODO: Stub */
//                              int __thiscall canConvert(UnitAIModule * this, int param_1)
//              int               EAX:4          <RETURN>
//              UnitAIModule *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?canConvert@UnitAIModule@@UAEHH@Z                            XREF[15]:    0056eb9c(*), 00575894(*),
//                               UnitAIModule::canConvert                                                  005759ac(*), 00575a8c(*),
//                                                                                                         00575b6c(*), 00575c4c(*),
//                                                                                                         00575d2c(*), 00575e0c(*),
//                                                                                                         00575fd4(*), 005760b4(*),
//                                                                                                         00576194(*), 00576274(*),
//                                                                                                         00576354(*), 00576434(*),
//                                                                                                         00576514(*)
//                              aiuaimod.h:210 (5)
//         004138b0     XOR        EAX,EAX
//         004138b2     RET        0x4
//         004138b5     ??         90h
//         004138b6     NOP
//         004138b7     NOP
//         004138b8     NOP
//         004138b9     NOP
//         004138ba     NOP
//         004138bb     NOP
//         004138bc     NOP
//         004138bd     NOP
//         004138be     NOP
//         004138bf     NOP
    return 0;
}

