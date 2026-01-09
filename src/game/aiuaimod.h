#pragma once
#include "common.h"

class UnitAIModule {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
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

    virtual void save(int param_1);                         // vt0[1]+0x4=0x413150
    virtual void load(int param_1);                         // vt0[2]+0x8=0x413450
    virtual RGE_Player* owner();                            // vt0[3]+0xC=0x413810
    virtual int order(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8, int param_9, int param_10, int param_11); // vt0[4]+0x10=0x414D40
    virtual int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[5]+0x14=0x414E80
    virtual int notifyCommander(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[6]+0x18=0x414F70
    virtual int notifyCommander(NotifyEvent* param_1);      // vt0[7]+0x1C=0x414F40
    virtual void search();                                  // vt0[8]+0x20=0x415040
    virtual int importantWhenDead(int param_1);             // vt0[9]+0x24=0x415120
    virtual int retryableOrder(int param_1);                // vt0[10]+0x28=0x415150
    virtual int actionRequiresLiveTarget(int param_1);      // vt0[11]+0x2C=0x415160
    virtual int bestUnitToAttack(int param_1, int param_2, float* param_3); // vt0[12]+0x30=0x4151B0
    virtual int mostDangerousEnemy(float* param_1);         // vt0[13]+0x34=0x415A10
    virtual int weakestEnemy(float* param_1);               // vt0[14]+0x38=0x415AD0
    virtual int closestAttacker(float* param_1);            // vt0[15]+0x3C=0x415B50
    virtual int closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5); // vt0[16]+0x40=0x415CA0
    virtual int closestResourceObject(int param_1, int* param_2); // vt0[17]+0x44=0x415E50
    virtual int closestUndiscoveredTile(int* param_1, int* param_2, int param_3); // vt0[18]+0x48=0x415F40
    virtual void logDebug(char* param_1);                   // vt0[19]+0x4C=0x41A100
    virtual int canAttackUnit(RGE_Static_Object* param_1);  // vt0[20]+0x50=0x4162A0
    virtual int canAttackUnitAtNeutrality(int param_1);     // vt0[21]+0x54=0x4162B0
    virtual int stopObject(int param_1);                    // vt0[22]+0x58=0x4162C0
    virtual int attackObject(int param_1, int param_2);     // vt0[23]+0x5C=0x416340
    virtual int attackRoundupObject(int param_1);           // vt0[24]+0x60=0x4163C0
    virtual int huntObject(int param_1, int param_2);       // vt0[25]+0x64=0x416470
    virtual int gatherObject(int param_1, int param_2);     // vt0[26]+0x68=0x416690
    virtual int convertObject(int param_1, int param_2);    // vt0[27]+0x6C=0x416550
    virtual int healObject(int param_1, int param_2);       // vt0[28]+0x70=0x4165F0
    virtual int repairObject(int param_1, int param_2);     // vt0[29]+0x74=0x416730
    virtual int buildObject(int param_1, int param_2);      // vt0[30]+0x78=0x4167D0
    virtual int tradeWithObject(int param_1, int param_2);  // vt0[31]+0x7C=0x416870
    virtual int explore(int param_1, int param_2, int param_3); // vt0[32]+0x80=0x416910
    virtual int enterObject(int param_1, int param_2);      // vt0[33]+0x84=0x416980
    virtual int unload(int param_1, float param_2, float param_3); // vt0[34]+0x88=0x416A50
    virtual int transportObject(float param_1, float param_2, float param_3, int param_4); // vt0[35]+0x8C=0x4169E0
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5); // vt0[36]+0x90=0x416C10
    virtual int moveTo(int param_1, float param_2, int param_3); // vt0[37]+0x94=0x416B80
    virtual int moveTo(int param_1, int param_2);           // vt0[38]+0x98=0x416AF0
    virtual int evasiveMoveTo(float param_1, float param_2, float param_3, int param_4); // vt0[39]+0x9C=0x416C80
    virtual int intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5); // vt0[40]+0xA0=0x416F30
    virtual int runAwayFromAttackers(int param_1);          // vt0[41]+0xA4=0x4171F0
    virtual int followObject(int param_1, float param_2, int param_3); // vt0[42]+0xA8=0x417360
    virtual int defendObject(int param_1, float param_2, int param_3); // vt0[43]+0xAC=0x4173D0
    virtual int defendPosition(float param_1, float param_2, float param_3, int param_4); // vt0[44]+0xB0=0x417440
    virtual int seekAndDestroy(int param_1, int param_2, int param_3, int param_4); // vt0[45]+0xB4=0x4174A0
    virtual int exploreAndDestroy(int param_1, int param_2, int param_3); // vt0[46]+0xB8=0x417510
    virtual int importantObject(int param_1);               // vt0[47]+0xBC=0x417640
    virtual int convertToLOSResourceType(int param_1);      // vt0[48]+0xC0=0x4177C0
    virtual int canConvert(int param_1);                    // vt0[49]+0xC4=0x4138B0
    virtual int processOrder(OrderEvent* param_1, int param_2); // vt0[50]+0xC8=0x417B50
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x4180C0
    virtual void processGroupNotify(NotifyEvent* param_1);  // vt0[52]+0xD0=0x419510
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x4195F0
    virtual int processMisc();                              // vt0[54]+0xD8=0x419650
    virtual int processRetryableOrder();                    // vt0[55]+0xDC=0x419BC0
    UnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~UnitAIModule();
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

