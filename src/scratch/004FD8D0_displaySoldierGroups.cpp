// 004FD8D0 TribeTacticalAIModule::displaySoldierGroups
// Attempt log:
// try 1: direct logging/control-flow reconstruction from packet with local method/type stubs; exact-size comparable under default /O2 but broad mismatch (70.1662% positional, 93.3535% edit). Prologue differs because VC5 emits EBP/8-byte stack alignment for double varargs in this local surface.
// try 2: tested /GX; no change, rolled back.
// try 3: tested /Zp4 with /O2; no change, rolled back.
// try 4: tested /O1: too small (.text 1260 vs 1324), rolled back.
// try 5: tested /Od: exact-size comparable but worse debug-basin mismatch (74.3202% positional, 142.9003% edit), rolled back.
// left in scratch: behavior/call-set skeleton covers group filtering, target/object logging, object-to-destroy/unit/waypoint loops, but not accepted_drift quality. Needs exact declaration/prototype context for AIModule::logCommonHistory and group/unit surfaces to avoid stack-alignment/prologue and broad call-order drift.

struct Waypoint { float x; float y; };
class UnitAIModule { public: int currentAction(); int currentOrder(); int currentTarget(); int currentOrderPriority(); float currentTargetX(); float currentTargetY(); };
struct MasterObj { char gap[8]; char* name; };
struct Owner { char gap[0x4a]; short id; };
class RGE_Static_Object { public: char gap0[8]; MasterObj* master_obj; Owner* owner; char gap10[0x28]; float x; float y; char gap40[8]; unsigned char object_state; UnitAIModule* unitAI(); };
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

extern "C" void logCommonHistory(void* self, const char* fmt, ...);

class TribeTacticalAIModule {
public:
    char gap0[0xF0]; MainDecisionAIModule* md;
    char gapf4[0x8e0]; TacticalAIGroup groups;
    void displaySoldierGroups();
};

void TribeTacticalAIModule::displaySoldierGroups()
{
    logCommonHistory(this, (char*)0x588964);
    TacticalAIGroup* g = this->groups.next;
    while (g != &this->groups) {
        if (!g) return;
        if (g->type() == 100 || g->type() == 101 || g->type() == 102 || g->type() == 109) {
            if (g->type() == 100) logCommonHistory(this, (char*)0x58893c, g->id(), g->type());
            else if (g->type() == 101) logCommonHistory(this, (char*)0x588914, g->id(), g->type());
            else if (g->type() == 102) logCommonHistory(this, (char*)0x5888e8, g->id(), g->type());
            else if (g->type() == 109) logCommonHistory(this, (char*)0x5888bc, g->id(), g->type());

            logCommonHistory(this, (char*)0x588874, g->numberUnits(), g->desiredNumberUnits(), g->originalUnitNumber(), g->action(), g->inUse());
            RGE_Static_Object* target = this->md->object(g->target());
            if (target) {
                logCommonHistory(this, (char*)0x588838, g->target(), target->master_obj->name, g->commander(), g->currentHitPoints(this->md), this->md, g->originalHitPoints(), g->waitCode());
            } else {
                logCommonHistory(this, (char*)0x588800, g->target(), g->commander(), g->currentHitPoints(this->md), this->md, g->originalHitPoints(), g->waitCode());
            }
            logCommonHistory(this, (char*)0x5887c0, g->assistGroupID(), g->assistGroupType(), g->consecutiveIdleUnitCount());
            logCommonHistory(this, (char*)0x5887a8, g->location()->x, g->location()->y);
            logCommonHistory(this, (char*)0x588788, g->gatherLocation()->x, g->gatherLocation()->y);
            logCommonHistory(this, (char*)0x588768, g->retreatLocation()->x, g->retreatLocation()->y);
            logCommonHistory(this, (char*)0x587f58, g->targetLocation()->x, g->targetLocation()->y);
            logCommonHistory(this, (char*)0x588758, g->playNumberValue);
            logCommonHistory(this, (char*)0x588738, g->numberObjectsToDestroyValue);
            if (g->numberObjectsToDestroyValue > 0) {
                for (int i = 0; i < g->numberObjectsToDestroyValue; ++i) {
                    RGE_Static_Object* o = this->md->object(g->objectToDestroy(i));
                    if (!o) logCommonHistory(this, (char*)0x588700, i, g->objectToDestroy(i), i);
                    else logCommonHistory(this, (char*)0x5886d4, i, g->objectToDestroy(i), i, o->master_obj->name);
                }
            }
            for (int i = 0; i < g->numberUnits(); ++i) {
                RGE_Static_Object* u = this->md->object(g->unit(i));
                if (!u) {
                    logCommonHistory(this, (char*)0x5883d4);
                } else if (!u->unitAI()) {
                    logCommonHistory(this, (char*)0x5883b4);
                } else {
                    UnitAIModule* ai = u->unitAI();
                    logCommonHistory(this, (char*)0x58866c, g->unit(i), u->master_obj->name, u->object_state, ai->currentAction(), ai->currentTarget(), ai->currentOrder(), ai->currentOrderPriority(), u->x, u->y, ai->currentTargetX(), ai->currentTargetY());
                    if (u->unitAI()->currentTarget() != -1) {
                        RGE_Static_Object* t = this->md->object(u->unitAI()->currentTarget());
                        if (t) logCommonHistory(this, (char*)0x588650, t->master_obj->name, t->owner->id);
                    }
                }
            }
            if (!g->numberAttackWaypoints()) {
                logCommonHistory(this, (char*)0x58863c);
            } else {
                logCommonHistory(this, (char*)0x58862c);
                for (int i = 0; i < (int)(unsigned int)g->numberAttackWaypoints(); ++i) {
                    logCommonHistory(this, (char*)0x58861c, g->attackWaypoint(i)->x, g->attackWaypoint(i)->y);
                }
                logCommonHistory(this, (char*)0x588600, (unsigned int)g->currentAttackWaypoint());
            }
        }
        g = g->next;
    }
}
