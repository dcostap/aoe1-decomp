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
// Current session probes: named the groups sentinel (both initialization
// orders), swapped the commutative x/y distance terms, and nested the final
// distance guards; sentinel/term forms duplicated the 68-byte basin and the
// nested guards regressed to 296 bytes before restoration. A proven
// TacticalAIModule base likewise duplicated the basin.
// - This session's 18-variant local declaration/predicate lab produced two
//   size/frame/call-set-preserving codegen groups, neither closer than 68
//   bytes; register-qualified point/type parameters and a full self alias
//   were also codegen duplicates.
// - Restored the period math-header surface and the generated polymorphic
//   AIModule/TacticalAIModule/TribeTacticalAIModule and TacticalAIGroup
//   destructor ownership. These canonical source corrections emit the same
//   317-byte function and preserve the proven +0xF0/+0x9D4 offsets.
// Current bounded pass: behavior, calls, frame, boundary, and typed ownership
// are stable; remaining drift is the first prologue/local-home/register basin
// (68 bytes, 21.4511%).
// - Current TU pass: a natural do-while list form added four bytes and a
//   branch, then was restored. A typed self alias combined with direct type
//   filtering and ordered desired/number locals was codegen-duplicate. The
//   dossier and same-TU donors add no new ownership or ABI fact, so the clean
//   source remains authoritative.
// - This pass tested direct and separate filter locals, declaration order,
//   register-qualified parameters, point aliases, guard nesting, and class
//   surface variants. These forms stayed in the 68-byte basin.
// - A volatile best-distance diagnostic reached 52 bytes but remains an
//   unsupported metric-only form. A 32-sample ambient declaration sweep found
//   one codegen group. No natural exact source emerged.
// - A simpler direct type predicate with one block-local desired value and a
//   direct numberUnits call preserves the typed scan and lowers drift to 30
//   bytes. The remaining mismatch is local-home rotation and one deferred type
//   load; declaration, sentinel, and initializer variants duplicate this basin.
// - Revisit probe: a natural sentinel local used for both list-end comparisons
//   was codegen-neutral. The pinned direct-predicate source remains the clean
//   reconstruction; no policy-valid exact source emerged.

#include <math.h>

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
    virtual ~TacticalAIGroup();
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
    virtual ~TribeMainDecisionAIModule();
    char gap_00[0xF0];
};

// Main-agent audit confirmed canonical tactical/group/object ownership and kept
// the natural ready/idle scan.  The module hierarchy is polymorphic in the
// period class surface; preserve the proven base boundary at +0xF0.
class AIModule {
public:
    virtual ~AIModule();
    char gap_004[0xEC];
};

class TacticalAIModule : public AIModule {
public:
    virtual ~TacticalAIModule();
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
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

    group = this->groups.next;
    bestGroup = 0;
    bestDistance = -1;

    if (group != &this->groups) {
        while (1) {
            if (group == 0) {
                return bestGroup;
            }

            if (type == -1 || group->type() == type) {
                int desired = group->desiredNumberUnits();
                if (desired <= group->numberUnits() &&
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
