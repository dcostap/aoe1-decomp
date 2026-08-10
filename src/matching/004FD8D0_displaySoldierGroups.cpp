// 004FD8D0 TribeTacticalAIModule::displaySoldierGroups
// Attempt log:
// try 1: direct logging/control-flow reconstruction from packet with local method/type stubs; exact-size comparable under default /O2 but broad mismatch (70.1662% positional, 93.3535% edit). Prologue differs because VC5 emits EBP/8-byte stack alignment for double varargs in this local surface.
// try 2: tested /GX; no change, rolled back.
// try 3: tested /Zp4 with /O2; no change, rolled back.
// try 4: tested /O1: too small (.text 1260 vs 1324), rolled back.
// try 5: tested /Od: exact-size comparable but worse debug-basin mismatch (74.3202% positional, 142.9003% edit), rolled back.
// left in scratch: behavior/call-set skeleton covers group filtering, target/object logging, object-to-destroy/unit/waypoint loops, but not accepted_drift quality. Needs exact declaration/prototype context for AIModule::logCommonHistory and group/unit surfaces to avoid stack-alignment/prologue and broad call-order drift.
// try 6: restored the repeated direct unitAI() receivers in the large unit
//   varargs expression, then removed duplicate md/index varargs from the two
//   target and object-to-destroy logs.  This recovered all 99 call sites and
//   matched 1324/1324 bytes; direct receiver repetition is period-plausible
//   and also preserves the original right-to-left varargs evaluation order.
// exact candidate: 0-byte positional and edit/resync diff under default flags;
//   kept in scratch for main-agent audit as requested.
// Source audit: restored the original format strings as ordinary literals and
// modeled the AIModule base plus object/player virtual surfaces.  This keeps
// the direct cdecl member logger and proven field ownership period-plausible.

struct Waypoint { float x; float y; };
class UnitAIModule { public: int currentAction(); int currentOrder(); int currentTarget(); int currentOrderPriority(); float currentTargetX(); float currentTargetY(); };
class MasterObj {
public:
    virtual ~MasterObj();
    char gap_04[4];
    char* name;
};
class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    void* world;
    char gap_40[0x0A];
    short id;
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    MasterObj* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float x;
    float y;
    char gap_40[8];
    unsigned char object_state;
    UnitAIModule* unitAI();
};
class MainDecisionAIModule { public: RGE_Static_Object* object(int id); };

class TacticalAIGroup {
public:
    TacticalAIGroup* prev;
    TacticalAIGroup* next;
    char gap08[0x1c8]; int playNumberValue;
    char gap1d4[0xf8]; int numberObjectsToDestroyValue;
    int type(); int id(); int inUse(); int numberUnits(); int desiredNumberUnits(); int originalUnitNumber(); int action(); int target();
    int commander(); int currentHitPoints(MainDecisionAIModule* md); int originalHitPoints(); int waitCode();
    int assistGroupID(); int assistGroupType(); unsigned long consecutiveIdleUnitCount();
    Waypoint* location(); Waypoint* gatherLocation(); Waypoint* retreatLocation(); Waypoint* targetLocation();
    int objectToDestroy(int i); int unit(int i);
    unsigned char numberAttackWaypoints(); Waypoint* attackWaypoint(int i); unsigned char currentAttackWaypoint();
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void __cdecl logCommonHistory(char* fmt, ...);
};

class TribeTacticalAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    char gapf4[0x8e0]; TacticalAIGroup groups;
    void displaySoldierGroups();
};

void TribeTacticalAIModule::displaySoldierGroups()
{
    RGE_Static_Object* object;

    this->logCommonHistory("Soldier Groups:");
    TacticalAIGroup* g = this->groups.next;
    while (g != &this->groups) {
        if (!g) return;
        if (g->type() == 100 || g->type() == 101 || g->type() == 102 || g->type() == 109) {
            if (g->type() == 100) this->logCommonHistory("  Group ID#%d:  Attack Group (Type=%d).", g->id(), g->type());
            else if (g->type() == 101) this->logCommonHistory("  Group ID#%d:  Defend Group (Type=%d).", g->id(), g->type());
            else if (g->type() == 102) this->logCommonHistory("  Group ID#%d:  Explore Group (Type=%d).", g->id(), g->type());
            else if (g->type() == 109) this->logCommonHistory("  Group ID#%d:  Artifact Group (Type=%d).", g->id(), g->type());

            this->logCommonHistory("    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d.", g->numberUnits(), g->desiredNumberUnits(), g->originalUnitNumber(), g->action(), g->inUse());
            object = this->md->object(g->target());
            if (object) {
                this->logCommonHistory("    Target=%d (%s), CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(), object->master_obj->name, g->commander(), g->currentHitPoints(this->md), g->originalHitPoints(), g->waitCode());
            } else {
                this->logCommonHistory("    Target=%d, CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(), g->commander(), g->currentHitPoints(this->md), g->originalHitPoints(), g->waitCode());
            }
            this->logCommonHistory("    AssistGroupID=%d, AssistGroupType=%d, ConsecIdleCount=%ld.", g->assistGroupID(), g->assistGroupType(), g->consecutiveIdleUnitCount());
            this->logCommonHistory("    Location=(%f, %f).", g->location()->x, g->location()->y);
            this->logCommonHistory("    Gather Location=(%f, %f).", g->gatherLocation()->x, g->gatherLocation()->y);
            this->logCommonHistory("    Retreat Location=(%f, %f).", g->retreatLocation()->x, g->retreatLocation()->y);
            this->logCommonHistory("    Target Location=(%f, %f).", g->targetLocation()->x, g->targetLocation()->y);
            this->logCommonHistory("    Play=%d.", g->playNumberValue);
            this->logCommonHistory("    NumberObjectsToDestroy=%d.", g->numberObjectsToDestroyValue);
            if (g->numberObjectsToDestroyValue > 0) {
                for (int i = 0; i < g->numberObjectsToDestroyValue; ++i) {
                    object = this->md->object(g->objectToDestroy(i));
                    if (!object) this->logCommonHistory("      ObjectToDestroy #%d:  Unit #%d, but it's gone.", i, g->objectToDestroy(i));
                    else this->logCommonHistory("      ObjectToDestroy #%d:  Unit #%d (%s).", i, g->objectToDestroy(i), object->master_obj->name);
                }
            }
            for (int i = 0; i < g->numberUnits(); ++i) {
                object = this->md->object(g->unit(i));
                if (!object) {
                    this->logCommonHistory("    Unit %d is invalid.");
                } else if (!object->unitAI()) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                } else {
                    this->logCommonHistory("    Unit %d (%s): state=%d, action=%d, target=%d, order=%d, pri=%d, loc=(%3f, %3f), tLoc=(%3f, %3f).", g->unit(i), object->master_obj->name, object->object_state, object->unitAI()->currentAction(), object->unitAI()->currentTarget(), object->unitAI()->currentOrder(), object->unitAI()->currentOrderPriority(), object->x, object->y, object->unitAI()->currentTargetX(), object->unitAI()->currentTargetY());
                    if (object->unitAI()->currentTarget() != -1) {
                        object = this->md->object(object->unitAI()->currentTarget());
                        if (object) this->logCommonHistory("      Target: %s, Owner=%d.", object->master_obj->name, object->owner->id);
                    }
                }
            }
            if (!g->numberAttackWaypoints()) {
                this->logCommonHistory("    No waypoints.");
            } else {
                this->logCommonHistory("    Waypoints:");
                for (int i = 0; i < (int)(unsigned int)g->numberAttackWaypoints(); ++i) {
                    this->logCommonHistory("      (%f, %f).", g->attackWaypoint(i)->x, g->attackWaypoint(i)->y);
                }
                this->logCommonHistory("    Current waypoints=%d.", (unsigned int)g->currentAttackWaypoint());
            }
        }
        g = g->next;
    }
}
