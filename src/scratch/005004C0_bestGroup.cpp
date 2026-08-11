// VA: 005004C0 TribeTacticalAIModule::bestGroup (430 bytes)
// PDB: taitacmd.cpp:11348-11391
//
// Attempt log:
// - Replaced the old decompiler-shaped scaffold (which filtered on desired and
//   actual unit counts) with the packet-proven type/action, assist-group,
//   commander-zone, and gather-distance selection logic.
// - Baseline candidate: natural typed list walk with an explicit sentinel local,
//   the type-106 assist-group scan, and four direct gatherLocation() reads.
// - Split id/assist calls restored the oracle's ordered call multiset but moved
//   the saved-this/point and validity registers; declaration-order and bool/int
//   variants were duplicates or worse, so they were rolled back.
// - Swapping sentinel/best declarations improved late block alignment but left
//   the prologue stack homes wrong and was rolled back.
// - A 12-variant natural lab over initial-local order, assist-loop form, and
//   direct versus split id calls found no exact output. The direct do/break
//   family retained the best clean basin; top-tested variants lost size.
// - Final clean source: exact size/frame and typed behavior/call set; remaining
//   drift is the assist id/validity call-order and early local-home/register
//   basin. No canonical layout or behavioral uncertainty remains.

#include <math.h>

struct XYPoint {
    int x;
    int y;
};

struct Waypoint {
    float x;
    float y;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;

    int type() const;
    int action() const;
    int id() const;
    int assistGroupID() const;
    int commander() const;
    Waypoint* gatherLocation() const;
};

class RGE_Static_Object {
public:
    unsigned char currentZone();
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_004[0xEC];
    MainDecisionAIModule* md;
    char gap_0F4[0x8E0];
    TacticalAIGroup groups;

    TacticalAIGroup* bestGroup(int type, int action, int maxDistance,
                               XYPoint& point, int zone);
};

TacticalAIGroup* TribeTacticalAIModule::bestGroup(
    int type, int action, int maxDistance, XYPoint& point, int zone)
{
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* best = 0;
    int bestDistance = -1;
    TacticalAIGroup* sentinel = &this->groups;

    if (group != sentinel) {
        do {
            if (group == 0)
                return best;

            if ((type == -1 || group->type() == type) &&
                (action == -1 || group->action() == action)) {
                if (type == 0x6A) {
                    int valid = 1;
                    TacticalAIGroup* assist = this->groups.next;

                    if (assist != sentinel) {
                        do {
                            if (assist == 0)
                                break;
                            if (!valid)
                                goto next_group;
                            if (group->id() == assist->assistGroupID())
                                valid = 0;
                            assist = assist->next;
                            sentinel = &this->groups;
                        } while (assist != sentinel);
                    }

                    if (!valid)
                        goto next_group;
                }

                if (zone != -1) {
                    RGE_Static_Object* object =
                        this->md->object(group->commander());
                    if (object == 0 || object->currentZone() != zone)
                        goto next_group;
                }

                int distanceSquared =
                    (point.y - (int)group->gatherLocation()->y) *
                    (point.y - (int)group->gatherLocation()->y) +
                    (point.x - (int)group->gatherLocation()->x) *
                    (point.x - (int)group->gatherLocation()->x);
                int distance = (int)sqrt((double)distanceSquared);

                if ((distance < maxDistance && bestDistance == -1) ||
                    (maxDistance == -1 || distance < bestDistance)) {
                    best = group;
                    bestDistance = distance;
                }
            }

        next_group:
            group = group->next;
            sentinel = &this->groups;
        } while (group != sentinel);
    }

    return best;
}
