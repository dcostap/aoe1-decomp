// Shared UnitAIModule class definition for combined TU compilation.
// This is the canonical layout derived from binary analysis.
// Size: 0x131 (305 bytes, 4 + 0x04..0x130 fields, +0x130 is a byte)

#pragma once

class RGE_Static_Object;
class RGE_Master_Object;
class NotifyEvent;
class OrderEvent;
struct RGE_Visible_Map;

class UnitAIModule {
public:
    // vfptr at +0x00 (implicit, compiler-generated, 4 bytes)
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
    int* attackingUnitsValue_value;                     // +0x60
    int attackingUnitsValue_numberValue;                // +0x64
    int attackingUnitsValue_desiredNumberValue;         // +0x68
    int attackingUnitsValue_maximumSizeValue;           // +0x6C
    char waypointGap[0x80];                             // +0x70 to +0xEF
    int waypointQueueSizeValue;                         // +0xF0
    unsigned long lastUpdateTimeValue;                  // +0xF4
    unsigned long idleTimerValue;                       // +0xF8
    unsigned long adjustedIdleTimeoutValue;             // +0xFC
    unsigned long idleTimeoutValue;                     // +0x100
    unsigned long secondaryTimerValue;                  // +0x104
    unsigned long lookAroundTimerValue;                 // +0x108
    unsigned long lookAroundTimeoutValue;               // +0x10C
    float lastWorldPositionX;                           // +0x110
    float lastWorldPositionY;                           // +0x114
    float lastWorldPositionZ;                           // +0x118
    char gap_11C[4];                                    // +0x11C
    float defenseBufferValue;                           // +0x120
    int* importantObjects;                              // +0x124
    int numberImportantObjects;                         // +0x128
    char gap_12C[4];                                    // +0x12C
    char stopAfterTargetKilledValue;                    // +0x130


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
    int canAttackUnit(int);
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
    void load(int fd);
    void logDebug(char* param_1, ...);
    void lookAround();
    int mood();
    int mostDangerousEnemy();
    int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    int notify(int a1, int a2, int a3);
    int notifyCommander(NotifyEvent* event);
    int notifyCommander(int a1, int a2, int a3);
    int numberAttackingUnits();
    void* object();
    int objectCategory();
    int objectID();
    void order(int a1, int a2, int a3);
    void* orderQueueElement(int index);
    int orderQueueSize();
    int owner();
    void processGroupNotify(int a1, int a2);
    int processIdle(int param);
    void processOrder(int a1, int a2);
    void purgeNotifyQueue();
    void purgeOrderQueue();
    int retryableOrder(int);
    void runAwayFromAttackers();
    void save(int fd);
    void search();
    unsigned long secondaryTimer();
    int seekAndDestroy(int param_1, int param_2, int param_3, int param_4);
    void setAdjustedIdleTimeout(void);
    void setCurrentAction(int value);
    void setCurrentOrder(int value);
    void setCurrentOrderPriority(int v);
    void setCurrentTarget(int id, int x, int y, int z);
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
    int intelligentEvasiveMoveTo(int targetId, float x, float y, float z, int flag);
    void update();
    int selectNewPlayPhase();
    int processNotify(int caller, int recipient, int mType, int p1, int p2, int p3);
    void processMisc();
};
// Total size check: vfptr(4) + 0x04..0x130 = 4 + 0x130 = 0x134 bytes
// But last field is at +0x130 which is a byte, so sizeof = 0x131
// With vfptr adjustment: vfptr(4) + 0x130 = 0x134... hmm
// Actually this might have padding at the end
