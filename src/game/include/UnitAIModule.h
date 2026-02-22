#pragma once
#include "common.h"
#include "Waypoint.h"
#include "AIPlayStatus.h"

class RGE_Static_Object;
class RGE_Player;

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

protected:
    int addToOrderQueue(const OrderEvent* param_1, int param_2);
    int addToNotifyQueue(const NotifyEvent* param_1);
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

