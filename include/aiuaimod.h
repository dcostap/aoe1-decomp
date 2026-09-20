#ifndef AOE1_AIUAIMOD_H
#define AOE1_AIUAIMOD_H

// UnitAIModule owns the class surface. Other objects come from their owner
// headers so this module does not carry duplicate provider views.

#include "act_list.h"
#include "aipbook.h"
#include "basegame.h"
#include "m_co_obj.h"
#include "m_s_obj.h"
#include "map.h"
#include "player.h"
#include "stat_obj.h"
#include "utmarray.h"
#include "view.h"
#include "visible.h"
#include "vis_unit.h"
#include "waypoint.h"
#include "world.h"

extern const char str_fmt_stopObject[];

typedef unsigned char uchar;

// aiuaimod.cpp owns these queue records.
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

struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int outfile);
    virtual void load(int infile);
    virtual RGE_Player* owner() const;
    virtual int order(int issuer, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority);
    virtual int notify(int callerID, int recipientID, int mType, long p1, long p2, long p3);
    // VC5 reverses this adjacent overload pair in the vtable.
    virtual int notifyCommander(NotifyEvent* nEvent);
    virtual int notifyCommander(int callerID, int recipientID, int mType, long p1, long p2, long p3);
    virtual void search();
    virtual int importantWhenDead(int objectType);
    virtual int retryableOrder(int orderType);
    virtual int actionRequiresLiveTarget(int aID);
    virtual int bestUnitToAttack(int allowWallAttacks, int quickCheck, float* threatSlot);
    virtual int mostDangerousEnemy(float* threatSlot);
    virtual int weakestEnemy(float* threatSlot);
    virtual int closestAttacker(float* threatSlot);
    virtual int closestObject(int objectGroup, int desiredRelation, int objectState, int objectType, int* threatSlot);
    virtual int closestResourceObject(int resourceType, int* dSlot);
    virtual int closestUndiscoveredTile(int* tX, int* tY, int checkWaypointQueue);
    virtual void logDebug(char* textIn, ...);
    virtual int canAttackUnit(RGE_Static_Object* target);
    virtual int canAttackUnitAtNeutrality(int uID);
    virtual int stopObject(int checkOrderAndAction);
    virtual int attackObject(int targetID, int unconditional);
    virtual int attackRoundupObject(int targetID);
    virtual int huntObject(int targetID, int unconditional);
    virtual int gatherObject(int targetID, int unconditional);
    virtual int convertObject(int targetID, int unconditional);
    virtual int healObject(int targetID, int unconditional);
    virtual int repairObject(int targetID, int unconditional);
    virtual int buildObject(int targetID, int unconditional);
    virtual int tradeWithObject(int targetID, int unconditional);
    virtual int explore(int tX, int tY, int unconditional);
    virtual int enterObject(int targetID, int unconditional);
    virtual int unload(int unconditional, float x, float y);
    virtual int transportObject(float tX, float tY, float tZ, int unconditional);
    virtual int moveTo(int targetID, int unconditional);
    virtual int moveTo(int targetID, float minimumRange, int unconditional);
    virtual int moveTo(float targetX, float targetY, float targetZ, float minimumRange, int unconditional);
    virtual int evasiveMoveTo(float targetX, float targetY, float targetZ, int unconditional);
    virtual int intelligentEvasiveMoveTo(float targetX, float targetY, float targetZ, int goCloser, int unconditional);
    virtual int runAwayFromAttackers(int unconditional);
    virtual int followObject(int targetID, float desiredDistance, int unconditional);
    virtual int defendObject(int targetID, float desiredDistance, int unconditional);
    virtual int defendPosition(float targetX, float targetY, float desiredDistance, int unconditional);
    virtual int seekAndDestroy(int targetID, int tX, int tY, int unconditional);
    virtual int exploreAndDestroy(int tX, int tY, int unconditional);
    virtual int importantObject(int unitType);
    virtual int convertToLOSResourceType(int type);
    virtual int canConvert(int) { return 0; }

protected:
    virtual int processOrder(OrderEvent* oEvent, int orderNumber);
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual void processGroupNotify(NotifyEvent* nEvent);
    virtual int processIdle(int doSearch);
    virtual int processMisc();
    virtual int processRetryableOrder();
    int get_type();
    int find_unit(int, int, int);
    int do_stuff(int, int);
    int call28(int);
    int call40(int, int, int, int, int);
    int call64(int, int);
    int call68(int, int);

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

    UnitAIModule(RGE_Static_Object* o, int iQS);
    void setAdjustedIdleTimeout();
    RGE_Static_Object* object() const;
    int objectID() const;
    int objectCategory() const;
    int mood() const;
    unsigned long lastUpdateTime() const;
    unsigned long idleTimer() const;
    unsigned long idleTimeout() const;
    unsigned long secondaryTimer() const;
    float defenseBuffer() const;
    void setDefenseBuffer(float v);
    int orderQueueSize() const;
    OrderEvent* orderQueueElement(int v) const;
    void purgeOrderQueue();

protected:
    int addToOrderQueue(OrderEvent* oEvent, int inFront);
    int addToOrderQueue(int issuer, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int inFront, int priority);
    int addToNotifyQueue(NotifyEvent* nEvent);
    int addToNotifyQueue(int callerID, int recipientID, int mType, long p1, long p2, long p3);
    RGE_Static_Object* lookupObject(int id);

public:
    int currentOrder() const;
    void setCurrentOrder(int v);
    int currentOrderPriority() const;
    void setCurrentOrderPriority(int v);
    int currentAction() const;
    void setCurrentAction(int v);
    void setCurrentTarget(int o, float x, float y, float z);
    void setCurrentTarget(int o, int t, float x, float y, float z);
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
    int attackingUnitID(int v);
    int numberAttackingUnits() const;
    int update(unsigned long uTime);
    unsigned char visibleStatus(RGE_Visible_Map* vMap, int x, int y);
    void removeCurrentTarget();
    void purgeNotifyQueue(unsigned long uTime);
    void updateGroup(unsigned long uTime);
    int selectNewPlayPhase(int newPhase, int pickup);
    Waypoint* waypoint(int i) const;
    int waypointQueueSize() const;
    int addToWaypointQueue(int x, int y);
    int inWaypointQueue(int x, int y) const;
    void clearWaypointQueue();
    int isEnemyOwner(int oID);
    int isAllyOwner(int oID);
    int isNeutralOwner(int oID);
    void setTaskedByPlayer();
    void setPlayStatus(AIPlayStatus* ps);
    int hasOrderOnQueue(int orderNumber);
    void askForHelp(int unitToAttack);
    void lookAround();
};

typedef char verify_aiuaimod_UnitAIModule_size[
    (sizeof(UnitAIModule) == 0x134) ? 1 : -1];
typedef char verify_aiuaimod_OrderEvent_size[
    (sizeof(OrderEvent) == 0x24) ? 1 : -1];
typedef char verify_aiuaimod_NotifyEvent_size[
    (sizeof(NotifyEvent) == 0x18) ? 1 : -1];

typedef char verify_aiuaimod_VisibleUnitRecord_size[
    (sizeof(VISIBLE_UNIT_REC) == 0x08) ? 1 : -1];

#endif
