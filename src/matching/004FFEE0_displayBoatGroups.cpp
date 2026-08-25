#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FFEE0 TribeTacticalAIModule::displayBoatGroups
// taitacmd.cpp
// Attempt log:
// try 1: natural reconstruction from packet: walk boat group linked list, type-specific logging, stats, positions, per-boat loop.
// try 2: modeled list sentinel at this+0x9D4/next +0x9D8 and loop exit on sentinel/null.
// try 3: modeled TacticalAIGroup methods for observed calls: type 004EAF60, id 004EAF20, count 004EB2C0, object id 004EB2D0, stat getters and position getters.
// try 4: modeled first type filter exactly as repeated `type()` calls for 0x67,0x68,0x69,0x6B,0x6C,0x6A rather than caching type.
// try 5: modeled type-specific log strings at 0x58893C/0x588914/0x5888E8/0x588A6C/0x588A44/0x588A18 and shared log call.
// try 6: modeled stat summary and position logs with double promotion from float getters/fields.
// try 7: initially used `logCommonHistory(char*, ...)`; compiled equal 889B after adding player lookup, but broad 69.63% positional diff and first mismatch at prologue: compiler emitted EBP frame/stack alignment (`push ebp; mov ebp,esp; and esp,-8; sub esp,8`) while original is frameless push ebx/ebp/esi/edi.
// try 8: added Player::find_object(id) call for the observed 0040D760 lookup; this fixed size from 880B to 889B in varargs version.
// try 9: replaced varargs log declaration with fixed overloads to avoid stack-realignment prologue; this removed the EBP frame but shrank .text to 864B vs original 889B.
// Probe 11: restored the same-TU donor's AIModule base and cdecl varargs
// logger, then replaced decompiler-only group/object shims with the
// binary-backed method names and ABIs.  The target's [this+0xf0] value is the
// MainDecisionAIModule pointer, not a Player/finder object; the final log is
// the five-value unit state record (the md argument belongs only to
// currentHitPoints()).
// Exact under the default VC5 flags: 889/889 bytes, 69/69 ordered calls,
// frameless push ebx/ebp/esi/edi prologue.  The readable typed source is kept
// for promotion; no compiler-steering or inline assembly is used.

#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint {
    float x;
    float y;
};

class MainDecisionAIModule;
class UnitAIModule;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void __cdecl logCommonHistory(char* format, ...);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float x;
    float y;
    char gap_40[8];
    unsigned char object_state;
    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    int currentAction();
    int currentOrder();
    int currentTarget();
    int currentOrderPriority();
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int objectID);
};

class TacticalAIGroup {
public:
    TacticalAIGroup* prev;
    TacticalAIGroup* next;
    int type();
    int id();
    int inUse();
    int action();
    int originalUnitNumber();
    int desiredNumberUnits();
    int numberUnits();
    int assistGroupID();
    int originalHitPoints();
    int currentHitPoints(MainDecisionAIModule* md);
    int commander();
    int target();
    Waypoint* location();
    Waypoint* gatherLocation();
    Waypoint* retreatLocation();
    Waypoint* targetLocation();
    int unit(int index);
};

class TribeTacticalAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    char gap_F4[0x8E0];
    TacticalAIGroup groups; // +0x9D4; next is +0x9D8
    void displayBoatGroups();
};

#endif
void TribeTacticalAIModule::displayBoatGroups()
{
    this->logCommonHistory("Boat Groups:");
    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return;

        if (group->type() == 0x67 || group->type() == 0x68 ||
            group->type() == 0x69 || group->type() == 0x6B ||
            group->type() == 0x6C || group->type() == 0x6A) {
            if (group->type() == 0x67)
                this->logCommonHistory(
                    "  Group ID#%d:  Attack Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x68)
                this->logCommonHistory(
                    "  Group ID#%d:  Defend Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x69)
                this->logCommonHistory(
                    "  Group ID#%d:  Explore Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x6B)
                this->logCommonHistory(
                    "  Group ID#%d:  Fishing Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x6C)
                this->logCommonHistory(
                    "  Group ID#%d:  Trade Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x6A)
                this->logCommonHistory(
                    "  Group ID#%d:  Transport Group (Type=%d).",
                    group->id(), group->type());

            this->logCommonHistory(
                "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d.",
                group->numberUnits(), group->desiredNumberUnits(),
                group->originalUnitNumber(), group->action(), group->inUse());
            this->logCommonHistory(
                "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroupID=%d.",
                group->target(), group->commander(),
                group->currentHitPoints(this->md), group->originalHitPoints(),
                group->assistGroupID());
            this->logCommonHistory("    Location=(%f, %f).",
                                   group->location()->x, group->location()->y);
            this->logCommonHistory("    Gather Location=(%f, %f).",
                                   group->gatherLocation()->x,
                                   group->gatherLocation()->y);
            this->logCommonHistory("    Retreat Location=(%f, %f).",
                                   group->retreatLocation()->x,
                                   group->retreatLocation()->y);
            this->logCommonHistory("    Target Location=(%f, %f).",
                                   group->targetLocation()->x,
                                   group->targetLocation()->y);

            for (int i = 0; i < group->numberUnits(); ++i) {
                this->logCommonHistory("    Unit #%d.", group->unit(i));
                RGE_Static_Object* object =
                    this->md->object(group->unit(i));
                if (object == 0) {
                    this->logCommonHistory("    Unit %d is invalid.");
                }
                else if (object->unitAI() == 0) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                }
                else {
                    this->logCommonHistory(
                        "    Unit %d: state=%d, action=%d, target=%d, order=%d, priority=%d, location=(%f, %f).",
                        group->unit(i), object->object_state,
                        object->unitAI()->currentAction(),
                        object->unitAI()->currentTarget(),
                        object->unitAI()->currentOrder(),
                        object->unitAI()->currentOrderPriority(), object->x,
                        object->y);
                }
            }
        }
        group = group->next;
    }
}
#else
void TribeTacticalAIModule::displayBoatGroups() {}
#endif
