// 00500670 TribeTacticalAIModule::readyAndIdleGroup
// Source: taitacmd.cpp lines 11397-11422
// Attempt log:
// - Replaced the parked raw-pointer scaffold with the packet-supported typed
//   group walk: desired/actual, isGathered/allUnitsIdle gates, four gathered
//   location reads, integer distance, and best-group update.
// - Explicit top-null/bottom-sentinel control flow plus separate
//   desired-before-number assignments restored the original ordered call set
//   and exact size, but the remaining EBX/EBP/EDI register and local-home
//   rotation stayed 68 bytes from the oracle. Reusing the decompiler's one
//   value local for type and desired, and a target alias, were codegen-neutral.
// - Left in scratch: behavior, calls, frame, and boundary are understood; the
//   unresolved basin is prologue/local-home/register coloring.

extern "C" double sqrt(double value);
#pragma intrinsic(sqrt)

struct XYPoint {
    int x;
    int y;
};

struct Waypoint {
    float x;
    float y;
};

class TribeMainDecisionAIModule;
class TribeTacticalAIModule;

class TacticalAIGroup {
public:
    virtual void destroy(int flags);
    TacticalAIGroup* next;
    TacticalAIGroup* prev;

    int type();
    int desiredNumberUnits();
    int numberUnits();
    int isGathered(TribeTacticalAIModule* tactical,
                   TribeMainDecisionAIModule* md);
    int allUnitsIdle(TribeMainDecisionAIModule* md, int flag);
    Waypoint* gatherLocation();
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
};

// Main-agent audit confirmed canonical tactical/group/object ownership and kept
// the natural ready/idle scan.
class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x8E0];
    TacticalAIGroup groups;

    TacticalAIGroup* readyAndIdleGroup(int type, int maxDistance,
                                       XYPoint& point);
};

TacticalAIGroup* TribeTacticalAIModule::readyAndIdleGroup(
    int type, int maxDistance, XYPoint& point)
{
    int bestDistance;
    TacticalAIGroup* group;
    TacticalAIGroup* bestGroup;
    int value;

    group = this->groups.next;
    bestGroup = 0;
    bestDistance = -1;

    if (group != &this->groups) {
        while (1) {
            if (group == 0) {
                return bestGroup;
            }

            value = type;
            if (value == -1 || group->type() == value) {
                value = group->desiredNumberUnits();
                int number = group->numberUnits();
                if (value <= number &&
                    group->isGathered(this, this->md) != 0 &&
                    group->allUnitsIdle(this->md, 1) != 0) {
                    int distanceSquared =
                        (point.y - (int)group->gatherLocation()->y) *
                        (point.y - (int)group->gatherLocation()->y) +
                        (point.x - (int)group->gatherLocation()->x) *
                        (point.x - (int)group->gatherLocation()->x);
                    int distance = (int)sqrt((double)distanceSquared);

                    if (distance < maxDistance &&
                        (bestDistance == -1 || distance < bestDistance)) {
                        bestGroup = group;
                        bestDistance = distance;
                    }
                }
            }

            group = group->next;
            if (group == &this->groups) {
                break;
            }
        }
    }
    return bestGroup;
}
