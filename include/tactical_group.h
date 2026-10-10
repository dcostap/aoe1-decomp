#ifndef AOE1_TACTICAL_GROUP_H
#define AOE1_TACTICAL_GROUP_H

#include "waypoint.h"

class TribeMainDecisionAIModule;
class TribeTacticalAIModule;

// TacticalAIGroup::typeValue IDs. The group-status log names soldier and boat groups separately.
#define TACTICAL_GROUP_TYPE_ATTACK        100
#define TACTICAL_GROUP_TYPE_DEFEND        101
#define TACTICAL_GROUP_TYPE_EXPLORE       102
#define TACTICAL_GROUP_TYPE_BOAT_ATTACK   103
#define TACTICAL_GROUP_TYPE_BOAT_DEFEND   104
#define TACTICAL_GROUP_TYPE_BOAT_EXPLORE  105
#define TACTICAL_GROUP_TYPE_TRANSPORT     106
#define TACTICAL_GROUP_TYPE_FISHING       107
#define TACTICAL_GROUP_TYPE_TRADE         108
#define TACTICAL_GROUP_TYPE_ARTIFACT      109

// TacticalAIGroup::actionValue IDs, also passed to task(). These are cleanup names inferred from
// what each task() case does; the original task log strings are empty. Unclear values stay numeric:
// 5, 6, 13, 14, 15, 16, 21, and 22.
#define TACTICAL_GROUP_ACTION_NONE              0
#define TACTICAL_GROUP_ACTION_IDLE              1
#define TACTICAL_GROUP_ACTION_ATTACK            2
#define TACTICAL_GROUP_ACTION_RETREAT           3
#define TACTICAL_GROUP_ACTION_DEFEND            4
#define TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE  7
#define TACTICAL_GROUP_ACTION_EXPLORE           8
#define TACTICAL_GROUP_ACTION_GATHER            9
#define TACTICAL_GROUP_ACTION_FISH              10
#define TACTICAL_GROUP_ACTION_TRADE             11
#define TACTICAL_GROUP_ACTION_TRANSPORT         12
#define TACTICAL_GROUP_ACTION_ARTIFACT          19
#define TACTICAL_GROUP_ACTION_ATTACK_ROUNDUP    20

class TacticalAIGroup {
  public:
    virtual ~TacticalAIGroup();

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

    TacticalAIGroup();
    static void load(TacticalAIGroup* self, int file);
    int load(int);
    int save(int);
    int id() const;
    void setID(int);
    int inUse() const;
    void setInUse(int);
    int type() const;
    void setType(int);
    int subType() const;
    void setSubType(int);
    int addUnit(int, TribeMainDecisionAIModule*);
    int removeUnit(int, TribeMainDecisionAIModule*);
    int removeUnitByIndex(int, TribeMainDecisionAIModule*);
    void removeUnits(TribeMainDecisionAIModule*);
    int removeExtraUnits(TribeMainDecisionAIModule*);
    int removeUnboardedUnits(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int containsUnit(int);
    int numberUnits();
    int unit(int);
    int unitOriginalHitPoints(int);
    int desiredNumberUnits() const;
    void setDesiredNumberUnits(int);
    int commander() const;
    void setSpecificCommander(int, TribeMainDecisionAIModule*);
    int currentHitPoints(TribeMainDecisionAIModule*) const;
    int originalHitPoints() const;
    void setOriginalHitPoints(int);
    int originalUnitNumber() const;
    void setOriginalUnitNumber(int);
    const Waypoint& location() const;
    void setCurrentAttackWaypoint(unsigned char);
    void setLocation(float, float, float);
    void setLocation(int, int, int);
    int action() const;
    void setAction(int);
    int target() const;
    void setTarget(int);
    int targetType() const;
    void setTargetType(int);
    const Waypoint& targetLocation() const;
    void setAllLocations(float, float, float);
    void setTargetLocation(float, float, float);
    void setTargetLocation(int, int, int);
    const Waypoint& gatherLocation() const;
    void setGatherLocation(float, float, float);
    void setGatherLocation(int, int, int);
    const Waypoint& retreatLocation() const;
    void setRetreatLocation(float, float, float);
    void setRetreatLocation(int, int, int);
    int priority() const;
    void setPriority(int);
    int waitCode() const;
    void setWaitCode(int);
    int assistGroupID() const;
    void setAssistGroupID(int);
    int assistGroupType() const;
    void setAssistGroupType(int);
    int isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int isTightGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int allUnitsIdle(TribeMainDecisionAIModule*, int);
    unsigned long consecutiveIdleUnitCount() const;
    void setConsecutiveIdleUnitCount(unsigned long);
    void incrementConsecutiveIdleUnitCount(unsigned long);
    unsigned char numberAttackWaypoints() const;
    unsigned char currentAttackWaypoint() const;
    void addAttackWaypoint(float, float);
    Waypoint* attackWaypoint(unsigned char);
    int firstIdleUnit(TribeMainDecisionAIModule*);
    int objectToDestroy(int);
    int addObjectToDestroy(int);
    int task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
};

typedef char tactical_group_size_check[(sizeof(TacticalAIGroup) == 0x330) ? 1 : -1];

#endif
