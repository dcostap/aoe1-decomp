#pragma once
#include "../common.h"
#include "stat_obj.h"
#include "player.h"
#include "m_an_obj.h"
#include "aipbook.h"

class UnitAIModule       {
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
    ManagedArray<int> attackingUnitsValue;   // 0x60
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~UnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 02] Offset 0x08 (Override)
    virtual void load(int param_1); // Ghidra: load

    // [Slot 03] Offset 0x0C (Override)
    virtual RGE_Player* owner(); // Ghidra: owner

    // [Slot 04] Offset 0x10 (Override)
    virtual int order(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10, int param_11); // Ghidra: order

    // [Slot 05] Offset 0x14 (Override)
    virtual int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notify

    // [Slot 06] Offset 0x18 (Override)
    virtual int notifyCommander(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notifyCommander

    // [Slot 07] Offset 0x1C (Override)
    virtual int notifyCommander(NotifyEvent* param_1); // Ghidra: notifyCommander

    // [Slot 08] Offset 0x20 (Override)
    virtual void search(); // Ghidra: search

    // [Slot 09] Offset 0x24 (Override)
    virtual int importantWhenDead(int param_1); // Ghidra: importantWhenDead

    // [Slot 10] Offset 0x28 (Override)
    virtual int retryableOrder(int param_1); // Ghidra: retryableOrder

    // [Slot 11] Offset 0x2C (Override)
    virtual int actionRequiresLiveTarget(int param_1); // Ghidra: actionRequiresLiveTarget

    // [Slot 12] Offset 0x30 (Override)
    virtual int bestUnitToAttack(int param_1, int param_2, float* param_3); // Ghidra: bestUnitToAttack

    // [Slot 13] Offset 0x34 (Override)
    virtual int mostDangerousEnemy(float* param_1); // Ghidra: mostDangerousEnemy

    // [Slot 14] Offset 0x38 (Override)
    virtual int weakestEnemy(float* param_1); // Ghidra: weakestEnemy

    // [Slot 15] Offset 0x3C (Override)
    virtual int closestAttacker(float* param_1); // Ghidra: closestAttacker

    // [Slot 16] Offset 0x40 (Override)
    virtual int closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5); // Ghidra: closestObject

    // [Slot 17] Offset 0x44 (Override)
    virtual int closestResourceObject(int param_1, int* param_2); // Ghidra: closestResourceObject

    // [Slot 18] Offset 0x48 (Override)
    virtual int closestUndiscoveredTile(int* param_1, int* param_2, int param_3); // Ghidra: closestUndiscoveredTile

    // [Slot 19] Offset 0x4C (Override)
    virtual void logDebug(char* param_1); // Ghidra: logDebug

    // [Slot 20] Offset 0x50 (Override)
    virtual int canAttackUnit(RGE_Static_Object* param_1); // Ghidra: canAttackUnit

    // [Slot 21] Offset 0x54 (Override)
    virtual int canAttackUnitAtNeutrality(int param_1); // Ghidra: canAttackUnitAtNeutrality

    // [Slot 22] Offset 0x58 (Override)
    virtual int stopObject(int param_1); // Ghidra: stopObject

    // [Slot 23] Offset 0x5C (Override)
    virtual int attackObject(int param_1, int param_2); // Ghidra: attackObject

    // [Slot 24] Offset 0x60 (Override)
    virtual int attackRoundupObject(int param_1); // Ghidra: attackRoundupObject

    // [Slot 25] Offset 0x64 (Override)
    virtual int huntObject(int param_1, int param_2); // Ghidra: huntObject

    // [Slot 26] Offset 0x68 (Override)
    virtual int gatherObject(int param_1, int param_2); // Ghidra: gatherObject

    // [Slot 27] Offset 0x6C (Override)
    virtual int convertObject(int param_1, int param_2); // Ghidra: convertObject

    // [Slot 28] Offset 0x70 (Override)
    virtual int healObject(int param_1, int param_2); // Ghidra: healObject

    // [Slot 29] Offset 0x74 (Override)
    virtual int repairObject(int param_1, int param_2); // Ghidra: repairObject

    // [Slot 30] Offset 0x78 (Override)
    virtual int buildObject(int param_1, int param_2); // Ghidra: buildObject

    // [Slot 31] Offset 0x7C (Override)
    virtual int tradeWithObject(int param_1, int param_2); // Ghidra: tradeWithObject

    // [Slot 32] Offset 0x80 (Override)
    virtual int explore(int param_1, int param_2, int param_3); // Ghidra: explore

    // [Slot 33] Offset 0x84 (Override)
    virtual int enterObject(int param_1, int param_2); // Ghidra: enterObject

    // [Slot 34] Offset 0x88 (Override)
    virtual int unload(int param_1, float param_2, float param_3); // Ghidra: unload

    // [Slot 35] Offset 0x8C (Override)
    virtual int transportObject(float param_1, float param_2, float param_3, int param_4); // Ghidra: transportObject

    // [Slot 36] Offset 0x90 (Override)
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5); // Ghidra: moveTo

    // [Slot 37] Offset 0x94 (Override)
    virtual int moveTo(int param_1, float param_2, int param_3); // Ghidra: moveTo

    // [Slot 38] Offset 0x98 (Override)
    virtual int moveTo(int param_1, int param_2); // Ghidra: moveTo

    // [Slot 39] Offset 0x9C (Override)
    virtual int evasiveMoveTo(float param_1, float param_2, float param_3, int param_4); // Ghidra: evasiveMoveTo

    // [Slot 40] Offset 0xA0 (Override)
    virtual int intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5); // Ghidra: intelligentEvasiveMoveTo

    // [Slot 41] Offset 0xA4 (Override)
    virtual int runAwayFromAttackers(int param_1); // Ghidra: runAwayFromAttackers

    // [Slot 42] Offset 0xA8 (Override)
    virtual int followObject(int param_1, float param_2, int param_3); // Ghidra: followObject

    // [Slot 43] Offset 0xAC (Override)
    virtual int defendObject(int param_1, float param_2, int param_3); // Ghidra: defendObject

    // [Slot 44] Offset 0xB0 (Override)
    virtual int defendPosition(float param_1, float param_2, float param_3, int param_4); // Ghidra: defendPosition

    // [Slot 45] Offset 0xB4 (Override)
    virtual int seekAndDestroy(int param_1, int param_2, int param_3, int param_4); // Ghidra: seekAndDestroy

    // [Slot 46] Offset 0xB8 (Override)
    virtual int exploreAndDestroy(int param_1, int param_2, int param_3); // Ghidra: exploreAndDestroy

    // [Slot 47] Offset 0xBC (Override)
    virtual int importantObject(int param_1); // Ghidra: importantObject

    // [Slot 48] Offset 0xC0 (Override)
    virtual int convertToLOSResourceType(int param_1); // Ghidra: convertToLOSResourceType

    // [Slot 49] Offset 0xC4 (Override)
    virtual int canConvert(int param_1); // Ghidra: canConvert

    // [Slot 50] Offset 0xC8 (Override)
    virtual int processOrder(OrderEvent* param_1, int param_2); // Ghidra: processOrder

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 (Override)
    virtual void processGroupNotify(NotifyEvent* param_1); // Ghidra: processGroupNotify

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 (Override)
    virtual int processMisc(); // Ghidra: processMisc

    // [Slot 55] Offset 0xDC (Override)
    virtual int processRetryableOrder(); // Ghidra: processRetryableOrder

    // --- Non-Virtual Members ---
    RGE_Static_Object* object();
    int objectID();
    int objectCategory();
    int mood();
    ulong lastUpdateTime();
    ulong idleTimer();
    ulong idleTimeout();
    ulong secondaryTimer();
    float defenseBuffer();
    void setDefenseBuffer(float param_1);
    int orderQueueSize();
    OrderEvent* orderQueueElement(int param_1);
    void purgeOrderQueue();
    int currentOrder();
    void setCurrentOrder(int param_1);
    int currentOrderPriority();
    void setCurrentOrderPriority(int param_1);
    int currentAction();
    void setCurrentAction(int param_1);
    int currentTarget();
    int currentTargetType();
    float currentTargetX();
    float currentTargetY();
    float currentTargetZ();
    int lastAction();
    int lastOrder();
    int lastTarget();
    int lastTargetType();
    float desiredTargetDistance();
    int attackingUnitID(int param_1);
    int numberAttackingUnits();
    int update(ulong param_1);
    void updateGroup(ulong param_1);
    int selectNewPlayPhase(int param_1, int param_2);
    Waypoint* waypoint(int param_1);
    int waypointQueueSize();
    int addToWaypointQueue(int param_1, int param_2);
    int inWaypointQueue(int param_1, int param_2);
    void clearWaypointQueue();
    void removeCurrentTarget();
    void setCurrentTarget(int param_1, float param_2, float param_3, float param_4);
    void setCurrentTarget(int param_1, int param_2, float param_3, float param_4, float param_5);
    int isEnemyOwner(int param_1);
    int isAllyOwner(int param_1);
    int isNeutralOwner(int param_1);
    uchar visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3);
    void setAdjustedIdleTimeout();
    void setTaskedByPlayer();
    void setPlayStatus(AIPlayStatus* param_1);
    void lookAround();
    int hasOrderOnQueue(int param_1);
    void askForHelp(int param_1);
    int addToOrderQueue(OrderEvent* param_1, int param_2);
    int addToOrderQueue(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10);
    int addToNotifyQueue(NotifyEvent* param_1);
    int addToNotifyQueue(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    void purgeNotifyQueue(ulong param_1);
    RGE_Static_Object* lookupObject(int param_1);
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

