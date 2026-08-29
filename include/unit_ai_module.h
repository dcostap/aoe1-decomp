
#pragma once

#include "utmarray.h"
#include "waypoint.h"

class RGE_Static_Object;
class RGE_Master_Object;
class RGE_Player;
class NotifyEvent;
class OrderEvent;
struct RGE_Visible_Map;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int fd);
    virtual void load(int fd);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);
    virtual int notify(int, int, int, long, long, long);

    RGE_Static_Object* objectValue;                     // +0x04
    int moodValue;                                      // +0x08
    int objectCategoryValue;                            // +0x0C
    int orderQueueSizeValue;                            // +0x10
    int orderQueueMaxSizeValue;                         // +0x14
    void* orderQueueValue;                              // +0x18
    int notifyQueueSizeValue;                           // +0x1C
    int notifyQueueMaxSizeValue;                        // +0x20
    void* notifyQueueValue;                             // +0x24
    int currentOrderValue;                              // +0x28
    int currentOrderPriorityValue;                      // +0x2C
    int currentActionValue;                             // +0x30
    int currentTargetValue;                             // +0x34
    int currentTargetTypeValue;                         // +0x38
    float currentTargetXValue;                          // +0x3C
    float currentTargetYValue;                          // +0x40
    float currentTargetZValue;                          // +0x44
    float desiredTargetDistanceValue;                   // +0x48
    int defendTargetValue;                              // +0x4C
    int lastOrderValue;                                 // +0x50
    int lastActionValue;                                // +0x54
    int lastTargetValue;                                // +0x58
    int lastTargetTypeValue;                            // +0x5C
    ManagedArray<int> attackingUnitsValue;              // +0x60
    Waypoint waypointQueue[8];                          // +0x70
    int waypointQueueSizeValue;                         // +0xF0
    unsigned long lastUpdateTimeValue;                  // +0xF4
    unsigned long idleTimerValue;                       // +0xF8
    unsigned long adjustedIdleTimeoutValue;             // +0xFC
    unsigned long idleTimeoutValue;                     // +0x100
    unsigned long secondaryTimerValue;                  // +0x104
    unsigned long lookAroundTimerValue;                 // +0x108
    unsigned long lookAroundTimeoutValue;               // +0x10C
    Waypoint lastWorldPositionValue;                    // +0x110
    float defenseBufferValue;                           // +0x120
    int* importantObjects;                              // +0x124
    int numberImportantObjects;                         // +0x128
    void* playStatus;                                   // +0x12C (AIPlayStatus*)
    unsigned char stopAfterTargetKilledValue;           // +0x130


    // Method declarations (auto-generated)
    int actionRequiresLiveTarget(int actionId);
    int addToNotifyQueue(NotifyEvent* event);
    void addToNotifyQueue(int a1, int a2, int a3);
    int addToOrderQueue(OrderEvent* order, int param2);
    int addToOrderQueue(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
    int addToWaypointQueue(int param_1, int param_2);
    void askForHelp();
    int attackRoundupObject(int obj);
    int bestUnitToAttack();
    virtual int canAttackUnit(RGE_Static_Object*);
    int canAttackUnitAtNeutrality(int);
    int canConvert(int p0);
    void clearWaypointQueue();
    int closestAttacker();
    int closestObject(int objType);
    int closestResourceObject(int resourceType);
    int closestUndiscoveredTile(int* param_1, int* param_2, int param_3);
    int convertObject(int targetId, int flag);
    int convertToLOSResourceType(int);
    int currentAction();
    int currentOrder();
    int currentOrderPriority();
    int currentTarget();
    int currentTargetType();
    float currentTargetX();
    float currentTargetY();
    float currentTargetZ();
    int defendObject(int id, float distance, int allow_when_busy);
    int defendPosition(float x, float y, float distance, int flag);
    float defenseBuffer();
    float desiredTargetDistance();
    int enterObject(int param_1, int param_2);
    int explore(int param_1, int param_2, int param_3);
    int exploreAndDestroy(int param_1, int param_2, int param_3);
    int followObject(int param_1, float param_2, int param_3);
    int gatherObject(int targetId, int flag);
    int hasOrderOnQueue(int param_1);
    int huntObject(int obj);
    unsigned long idleTimeout();
    unsigned long idleTimer();
    int importantObject(int obj);
    int importantWhenDead(int value);
    int inWaypointQueue(int x, int y);
    int isAllyOwner(int player_id);
    int lastAction();
    int lastOrder();
    int lastTarget();
    int lastTargetType();
    unsigned long lastUpdateTime();
    void logDebug(char* param_1, ...);
    void lookAround();
    int mood();
    virtual int mostDangerousEnemy(float*);
    int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    int notifyCommander(NotifyEvent* event);
    int notifyCommander(int a1, int a2, int a3);
    int numberAttackingUnits();
    void* object();
    int objectCategory();
    int objectID();
    void* orderQueueElement(int index);
    int orderQueueSize();
    void processGroupNotify(int a1, int a2);
    int processIdle(int param);
    void processOrder(int a1, int a2);
    void purgeNotifyQueue(unsigned long);
    void purgeOrderQueue();
    int retryableOrder(int);
    void runAwayFromAttackers();
    void search();
    unsigned long secondaryTimer();
    virtual int seekAndDestroy(int param_1, int param_2, int param_3,
                               int param_4);
    void setAdjustedIdleTimeout(void);
    void setCurrentAction(int value);
    void setCurrentOrder(int value);
    void setCurrentOrderPriority(int v);
    void setCurrentTarget(int target, int target_type, float x, float y,
                          float z);
    void setCurrentTarget(int target, float x, float y, float z);
    void setDefenseBuffer(float v);
    int stopObject(int param);
    int transportObject(float param_1, float param_2, float param_3, int param_4);
    void unload(int a1);
    void updateGroup(int groupIndex);
    unsigned char visibleStatus(RGE_Visible_Map* param_1, int param_2, int param_3);
    int waypoint(int);
    int waypointQueueSize();
    int evasiveMoveTo(float x, float y, float z, int flag);
    int intelligentEvasiveMoveTo(float x, float y, float z, int targetId, int flag);
    int update(unsigned long param_1);
    int selectNewPlayPhase(int playNumber, int param2);
    int processNotify(void* notifyEvent);
    void processMisc();
    void setTaskedByPlayer();
};
typedef char unit_ai_module_size_check[
    (sizeof(UnitAIModule) == 0x134) ? 1 : -1];
