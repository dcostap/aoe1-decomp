#ifndef AOE1_AIUAIMOD_H
#define AOE1_AIUAIMOD_H

// Canonical declarations for the PDB aiuaimod.cpp source module.
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
extern const char str_aiuaimod_path[];

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

// No reviewed owner header exists for this point record.
struct XYZPoint {
    int x;
    int y;
    int z;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);
    virtual int notify(int, int, int, long, long, long);
    // VC5 reverses this adjacent overload pair in the vtable.
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
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*, ...);
    virtual int canAttackUnit(RGE_Static_Object*);
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
    virtual int moveTo(int, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float, int);
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
    virtual int canConvert(int) { return 0; }

protected:
    virtual int processOrder(OrderEvent*, int);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual void processGroupNotify(NotifyEvent*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);
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

    UnitAIModule(RGE_Static_Object*, int);
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
    void setDefenseBuffer(float);
    int orderQueueSize() const;
    OrderEvent* orderQueueElement(int) const;
    void purgeOrderQueue();

protected:
    int addToOrderQueue(OrderEvent*, int);
    int addToOrderQueue(int, int, int, int, float, float, float, float,
                        int, int);
    int addToNotifyQueue(NotifyEvent*);
    int addToNotifyQueue(int, int, int, long, long, long);
    RGE_Static_Object* lookupObject(int);

public:
    int currentOrder() const;
    void setCurrentOrder(int);
    int currentOrderPriority() const;
    void setCurrentOrderPriority(int);
    int currentAction() const;
    void setCurrentAction(int);
    void setCurrentTarget(int, float, float, float);
    void setCurrentTarget(int, int, float, float, float);
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
    int attackingUnitID(int);
    int numberAttackingUnits() const;
    int update(unsigned long);
    unsigned char visibleStatus(RGE_Visible_Map*, int, int);
    void removeCurrentTarget();
    void purgeNotifyQueue(unsigned long);
    void updateGroup(unsigned long);
    int selectNewPlayPhase(int phase, int parameter);
    Waypoint* waypoint(int) const;
    int waypointQueueSize() const;
    int addToWaypointQueue(int, int);
    int inWaypointQueue(int, int) const;
    void clearWaypointQueue();
    int isEnemyOwner(int);
    int isAllyOwner(int);
    int isNeutralOwner(int);
    void setTaskedByPlayer();
    void setPlayStatus(AIPlayStatus*);
    int hasOrderOnQueue(int);
    void askForHelp(int);
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
