#pragma once
#include "common.h"
#include "Waypoint.h"
#include "AIPlayStatus.h"

class RGE_Static_Object;
class RGE_Player;
class RGE_Visible_Map;

// Size/layout source of truth: all_types_ground_truth.h
struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};
static_assert(sizeof(NotifyEvent) == 0x18, "Size mismatch");

struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
};
static_assert(sizeof(OrderEvent) == 0x24, "Size mismatch");

class UnitAIModule {
public:
    UnitAIModule(RGE_Static_Object* param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~UnitAIModule();         // vt[0] (0x0)
    virtual void save(int param_1);  // vt[1] (0x4)
    virtual void load(int param_1);  // vt[2] (0x8)

    virtual RGE_Player* owner() const;              // vt[3]
    virtual RGE_Static_Object* object() const;      // vt[4]
    virtual int objectID() const;                   // vt[5]
    int objectCategory() const;
    int mood() const;
    unsigned long lastUpdateTime() const;
    unsigned long idleTimer() const;
    unsigned long idleTimeout() const;
    unsigned long secondaryTimer() const;
    float defenseBuffer() const;
    void setDefenseBuffer(float param_1);
    int orderQueueSize() const;
    OrderEvent* orderQueueElement(int param_1) const;
    void purgeOrderQueue();
    int currentOrder() const;
    void setCurrentOrder(int param_1);
    int currentOrderPriority() const;
    void setCurrentOrderPriority(int param_1);
    int currentAction() const;
    void setCurrentAction(int param_1);
    int currentTarget() const;
    int currentTargetType() const;
    float currentTargetX() const;
    float currentTargetY() const;
    float currentTargetZ() const;
    int lastAction() const;
    int lastOrder() const;
    int lastTarget() const;
    int lastTargetType() const;
    float desiredTargetDistance() const;
    int attackingUnitID(int param_1);
    int numberAttackingUnits() const;
    Waypoint* waypoint(int param_1) const;
    int waypointQueueSize() const;
    int addToWaypointQueue(int param_1, int param_2);
    int inWaypointQueue(int param_1, int param_2) const;
    void clearWaypointQueue();
    virtual int order(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10, int param_11); // vt[6]
    virtual int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt[7]
    virtual int notifyCommander(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt[8]
    virtual int notifyCommander(NotifyEvent* param_1); // vt[9]
    virtual void search(); // vt[10]
    virtual int importantWhenDead(int param_1); // vt[11]
    virtual int retryableOrder(int param_1); // vt[12]
    virtual int actionRequiresLiveTarget(int param_1); // vt[13]
    virtual int bestUnitToAttack(int param_1, int param_2, float* param_3); // vt[14]
    virtual int mostDangerousEnemy(float* param_1); // vt[15]
    virtual int weakestEnemy(float* param_1); // vt[16]
    virtual int closestAttacker(float* param_1); // vt[17]
    virtual int closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5); // vt[18]
    virtual int closestResourceObject(int param_1, int* param_2); // vt[19]
    virtual int closestUndiscoveredTile(int* param_1, int* param_2, int param_3); // vt[20]
    virtual void logDebug(char* param_1); // vt[21]
    virtual int canAttackUnit(RGE_Static_Object* param_1); // vt[22]
    virtual int canAttackUnitAtNeutrality(int param_1); // vt[23]
    virtual int stopObject(int param_1); // vt[24]
    virtual int attackObject(int param_1, int param_2); // vt[25]
    virtual int attackRoundupObject(int param_1); // vt[26]
    virtual int huntObject(int param_1, int param_2); // vt[27]
    virtual int gatherObject(int param_1, int param_2); // vt[28]
    virtual int convertObject(int param_1, int param_2); // vt[29]
    virtual int healObject(int param_1, int param_2); // vt[30]
    virtual int repairObject(int param_1, int param_2); // vt[31]
    virtual int buildObject(int param_1, int param_2); // vt[32]
    virtual int tradeWithObject(int param_1, int param_2); // vt[33]
    virtual int explore(int param_1, int param_2, int param_3); // vt[34]
    virtual int enterObject(int param_1, int param_2); // vt[35]
    virtual int unload(int param_1, float param_2, float param_3); // vt[36]
    virtual int transportObject(float param_1, float param_2, float param_3, int param_4); // vt[37]
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5); // vt[38]
    virtual int moveTo(int param_1, float param_2, int param_3); // vt[39]
    virtual int moveTo(int param_1, int param_2); // vt[40]
    virtual int evasiveMoveTo(float param_1, float param_2, float param_3, int param_4); // vt[41]
    virtual int intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5); // vt[42]
    virtual int runAwayFromAttackers(int param_1); // vt[43]
    virtual int followObject(int param_1, float param_2, int param_3); // vt[44]
    virtual int defendObject(int param_1, float param_2, int param_3); // vt[45]
    virtual int defendPosition(float param_1, float param_2, float param_3, int param_4); // vt[46]
    virtual int seekAndDestroy(int param_1, int param_2, int param_3, int param_4); // vt[47]
    virtual int exploreAndDestroy(int param_1, int param_2, int param_3); // vt[48]
    virtual int importantObject(int param_1); // vt[49]
    virtual int convertToLOSResourceType(int param_1); // vt[50]
    virtual int canConvert(int param_1); // vt[51]
    virtual int processOrder(OrderEvent* param_1, int param_2); // vt[52]
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2); // vt[53]
    virtual void processGroupNotify(NotifyEvent* param_1); // vt[54]
    virtual int processIdle(int param_1); // vt[55]
    virtual int processMisc(); // vt[56]
    virtual int processRetryableOrder(); // vt[57]
    virtual int update(unsigned long param_1); // vt[58]
    virtual void updateGroup(unsigned long param_1); // vt[59]
    int selectNewPlayPhase(unsigned int param_1, int param_2);
    void removeCurrentTarget();
    void setCurrentTarget(int param_1, float param_2, float param_3, float param_4);
    void setCurrentTarget(int param_1, int param_2, float param_3, float param_4, float param_5);
    int isEnemyOwner(int param_1);
    int isAllyOwner(int param_1);
    int isNeutralOwner(int param_1);
    unsigned char visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3);
    void setTaskedByPlayer();
    void setPlayStatus(AIPlayStatus* param_1);
    void lookAround();
    int hasOrderOnQueue(int param_1);
    void askForHelp(int param_1);
    void purgeNotifyQueue(unsigned long param_1);
    RGE_Static_Object* lookupObject(int param_1);

protected:
    int addToOrderQueue(const OrderEvent* param_1, int param_2);
    int addToOrderQueue(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10);
    int addToNotifyQueue(const NotifyEvent* param_1);
    int addToNotifyQueue(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    void setAdjustedIdleTimeout();

public:
    RGE_Static_Object* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    OrderEvent* orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    NotifyEvent* notifyQueueValue;
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXValue;
    float currentTargetYValue;
    float currentTargetZValue;
    float desiredTargetDistanceValue;
    int defendTargetValue;
    int lastOrderValue;
    int lastActionValue;
    int lastTargetValue;
    int lastTargetTypeValue;
    ManagedArray<int> attackingUnitsValue;
    Waypoint waypointQueue[8];
    int waypointQueueSizeValue;
    unsigned long lastUpdateTimeValue;
    unsigned long idleTimerValue;
    unsigned long adjustedIdleTimeoutValue;
    unsigned long idleTimeoutValue;
    unsigned long secondaryTimerValue;
    unsigned long lookAroundTimerValue;
    unsigned long lookAroundTimeoutValue;
    Waypoint lastWorldPositionValue;
    float defenseBufferValue;
    int* importantObjects;
    int numberImportantObjects;
    AIPlayStatus* playStatus;
    unsigned char stopAfterTargetKilledValue;
    unsigned char _pad_end[0x3];
};
static_assert(sizeof(UnitAIModule) == 0x134, "Size mismatch");

