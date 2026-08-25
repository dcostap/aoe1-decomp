#ifndef TAITACMD_SHARED_CONTEXT
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
// - Fresh pass: removing the outer sentinel refresh worsened the frame and
//   CFG. Reversing the assist-id equality was the only small metric gain, but
//   it did not change VC5 call order. Point aliases, pointer/reference ABI,
//   declaration splitting, donor constness, and alternate null exits were
//   codegen duplicates or worse.
// - Final clean source: exact size/frame and typed behavior/call set; remaining
//   drift is the assist id/validity call-order and early local-home/register
//   basin. No canonical layout or behavioral uncertainty remains.
// - Tried the natural id-first equality spelling; VC5 kept the call-site order
//   mismatch and moved one byte farther from the oracle, so the assist-first
//   clean form remains selected.
// - Tried a natural outer while sentinel walk in place of the if/do form; it
//   improved shape but worsened positional drift from 350 to 372 bytes and did
//   not change the first local-home hunk or assist call order, so it was rolled
//   back.

#include <math.h>

#ifndef TAITACMD_SHARED_CONTEXT
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
    const Waypoint& gatherLocation() const;
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

#endif
TacticalAIGroup* TribeTacticalAIModule::bestGroup(
    int type, int action, int maxDistance, XYPoint& point, int zone)
{
    TacticalAIGroup* group;
    TacticalAIGroup* best;
    int bestDistance;
    TacticalAIGroup* sentinel;

    group = this->groups.next;
    best = 0;
    bestDistance = -1;

    if (group != &this->groups) {
        sentinel = &this->groups;
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
                            if (assist->assistGroupID() == group->id())
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
                    (point.y - (int)group->gatherLocation().y) *
                    (point.y - (int)group->gatherLocation().y) +
                    (point.x - (int)group->gatherLocation().x) *
                    (point.x - (int)group->gatherLocation().x);
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

// Session audit:
// - PDB sibling selection identifies 005004C0 as the first unowned normal
//   tactical-AI sibling after 00500670 in source order. Its owner is the
//   qualified TribeTacticalAIModule::bestGroup symbol and its boundary is
//   005004C0-0050066D.
// - The clean source preserves the sentinel walk, type/action/id/null checks,
//   ordered direct calls, candidate return, and fault order.
// - The exact-size clean reconstruction remains nonexact at 339 differing
//   bytes. The first ordered call gap is id versus assistGroupID evaluation.
// - Tested id-first temporaries, direct and sentinel guards, loop forms,
//   declaration order, point aliases, and label forms. None produced an exact
//   result. The current source is restored to the pinned clean form.
#else
TacticalAIGroup* TribeTacticalAIModule::bestGroup(
    int type, int action, int maxDistance, XYPoint& point, int zone) {
    return 0;
}
#endif
