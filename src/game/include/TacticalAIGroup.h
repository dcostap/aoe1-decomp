#pragma once
#include "common.h"
#include "Waypoint.h"

class TribeTacticalAIModule;

class TacticalAIGroup {
public:
    TacticalAIGroup();

    // Virtuals (best-effort)
    virtual ~TacticalAIGroup(); // vt[0] (0x0)
    int load(int param_1);
    int save(int param_1);
    int id() const;
    void setID(int param_1);
    int inUse() const;
    void setInUse(int param_1);
    int type() const;
    void setType(int param_1);
    int subType() const;
    void setSubType(int param_1);
    int addUnit(int param_1, TribeMainDecisionAIModule* param_2);
    int removeUnit(int param_1, TribeMainDecisionAIModule* param_2);
    int removeUnitByIndex(int param_1, TribeMainDecisionAIModule* param_2);
    void removeUnits(TribeMainDecisionAIModule* param_1);
    int removeExtraUnits(TribeMainDecisionAIModule* param_1);
    int removeUnboardedUnits(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    int containsUnit(int param_1);
    int numberUnits();
    int unit(int param_1);
    int unitOriginalHitPoints(int param_1);
    int desiredNumberUnits() const;
    void setDesiredNumberUnits(int param_1);
    int commander() const;
    void setSpecificCommander(int param_1, TribeMainDecisionAIModule* param_2);
    int currentHitPoints(TribeMainDecisionAIModule* param_1) const;
    int originalHitPoints() const;
    void setOriginalHitPoints(int param_1);
    int originalUnitNumber() const;
    void setOriginalUnitNumber(int param_1);
    Waypoint* location();
    void setLocation(float param_1, float param_2, float param_3);
    int action() const;
    void setAction(int param_1);
    int target() const;
    void setTarget(int param_1);
    int targetType() const;
    void setTargetType(int param_1);
    Waypoint* targetLocation();
    void setAllLocations(float param_1, float param_2, float param_3);
    void setTargetLocation(float param_1, float param_2, float param_3);
    Waypoint* gatherLocation();
    void setGatherLocation(float param_1, float param_2, float param_3);
    Waypoint* retreatLocation();
    void setRetreatLocation(float param_1, float param_2, float param_3);
    int priority() const;
    void setPriority(int param_1);
    int waitCode() const;
    void setWaitCode(int param_1);
    int assistGroupID() const;
    void setAssistGroupID(int param_1);
    int assistGroupType() const;
    void setAssistGroupType(int param_1);
    int task(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2, int param_3, int param_4, int param_5);
    int isGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    int isTightGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    int allUnitsIdle(TribeMainDecisionAIModule* param_1, int param_2);
    unsigned long consecutiveIdleUnitCount() const;
    void setConsecutiveIdleUnitCount(unsigned long param_1);
    void incrementConsecutiveIdleUnitCount(unsigned long param_1);
    unsigned char numberAttackWaypoints() const;
    unsigned char currentAttackWaypoint() const;
    void setCurrentAttackWaypoint(unsigned char param_1);
    void addAttackWaypoint(float param_1, float param_2);
    Waypoint* attackWaypoint(unsigned char param_1);
    int firstIdleUnit(TribeMainDecisionAIModule* param_1);
    int objectToDestroy(int param_1);
    int addObjectToDestroy(int param_1);

    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;
    Waypoint locationValue;
    int actionValue;
    int targetValue;
    int targetTypeValue;
    Waypoint targetLocationValue;
    Waypoint gatherLocationValue;
    Waypoint retreatLocationValue;
    int priorityValue;
    int waitCodeValue;
    int assistGroupIDValue;
    int assistGroupTypeValue;
    unsigned long consecutiveIdleUnitCountValue;
    int playNumberValue;
    unsigned char numberAttackWaypointsValue;
    unsigned char currentAttackWaypointValue;
    Waypoint attackWaypoints[15];
    unsigned char consecutiveGatherAttemptsValue;
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    unsigned long lastAttackRoundupTime;
    unsigned long lastAddedUnitTimeValue;
};
static_assert(sizeof(TacticalAIGroup) == 0x330, "Size mismatch");
