// 004F1E10 TribeTacticalAIModule::taskIdleSoldiers
// taitacmd.cpp
// Attempt log:
// try 1-11: prior broad scaffold used placeholder canUse/object/command
// helpers and was 704 bytes; it was structurally short and did not preserve
// the original direct-call set.
// probe 12: restored the binary-backed TacticalAIGroup, MainDecisionAI,
// information/strategy subobjects, object/zone APIs, and the nested
// skip-invalid-group loop from the same-TU decompiler control flow.  This is
// the clean typed reconstruction to check before any codegen-only probes.
// probe 13: proper direct method names/layout reached exact size, 0x10 frame,
// 47/47 conditional CFG, and 51 calls; the first broad result was 777 bytes
// different.  The remaining call topology is concentrated in the action
// selection tail (rebuilt 4 setAction/16 type versus original 1 setAction/19
// type), while the task call is in a relocated cold block.
// probe 14: moved the invalid-group advance to an out-of-line source label
// and shared the loop-test; rebuilt remained exact-size/frame and improved to
// 756 differing bytes with 73.77% exact-block coverage.  Direct-sentinel and
// positive-predicate variants were codegen duplicates.
// probe 15: structured/common setAction-tail and action-result liveness
// variants were codegen duplicates or larger; rolled back to the cleanest
// typed form.  No inline asm, fake imports, or custom flags retained.
// left in scratch: exact matching is paused at the 10-hypothesis budget.  The
// best rebuilt code is 989 bytes, 0x10 frame, 51 calls, 85.08% shape, 756
// strict differing bytes (76.4408%), and 63.50% bounded edit similarity.
// - Named the debug source file. The previous literal address was not valid
//   source ownership.
// probe 24: reordered the ready/task arms to follow the original PDB line
// order, with task before action selection. This moved task into the original
// inline block and improved shape, calls, and exact blocks, but removed three
// type calls, shortened the function by 34 bytes, and worsened strict diff;
// restored the clean source.
//
// Current pass probes 1-20: a top-level do-loop with invalid-group continue,
// delayed isGathered initialization, the int currentZone() & 0xff form, the
// inverted zone test, and the explicit fully-explored failure edge are all
// supported by closer code. The best clean checkpoint is 1008 bytes, 0x10
// frame, 51 calls, 90.97% shape, 274 differing bytes, and 81.35% bounded
// similarity. The action tail remains unresolved: the executable has 19 type
// calls and one shared setAction call, while the clean source emits 16 type
// calls and four setAction calls. Fresh predicates, nested assignments,
// scopes, initializers, and shared-label forms did not reach that call set.
//
// probe 22: restored the PDB-order inactive arm and wrote the action choices
// as direct setAction calls. VC5 merged their common call tail, recovered all
// 19 type calls, and proved that setType(0x69) continues to action 8. This
// reached 35 differing bytes with exact frame, calls, and call order.
// probe 23: replaced the repeated do-loop sentinel guard with the natural
// pretest while loop shown by 004F1E71 and 004F21CD. This removed the final
// redundant branch and reached an exact 989-byte match at 0.0000%.

static const char s_taitacmd_cpp[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";

class RGE_Player;
class RGE_Static_Object;
class TribeMainDecisionAIModule;
class TribeTacticalAIModule;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class TacticalAIModule : public AIModule {
public:
    virtual ~TacticalAIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];

    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int,
                              int);
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class TribeInformationAIModule : public InformationAIModule {
public:
    char gap_F0[0x10090 - 0xF0];

    int fullyExploredZone(int commander);
};

class StrategyAIModule : public AIModule {
public:
    virtual ~StrategyAIModule();
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    char gap_F0[0x5F8 - 0xF0];

    int currentVictoryCondition();
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0xCEC - 0x104];
    TribeInformationAIModule informationAI;
    char gap_10D7C[0x10E74 - 0x10D7C];
    TribeStrategyAIModule strategyAI;
};

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x2BC];
    unsigned char consecutiveGatherAttemptsValue;
    char gap_2C9[3];
    char gap_2CC[0x64];

    int id();
    int type();
    int action();
    int isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int desiredNumberUnits();
    int numberUnits();
    int commander();
    int allUnitsIdle(TribeMainDecisionAIModule*, int);
    void setDesiredNumberUnits(int);
    void setSubType(int);
    void setType(int);
    void setAction(int);
    int task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int,
             int);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;

    unsigned char currentZone();
    unsigned char lookupZone(int, int);
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_F4[0x8E0];
    TacticalAIGroup groups;
    char gap_D04[0x27C];
    int nextIdleSoldierGroupToTaskValue;

    int numberItemsToDefend();
    int numberItemsToAttack();
    int itemToCapture();
    int itemToBringToArea();

    void taskIdleSoldiers(unsigned long, unsigned long);
};

extern unsigned long debug_timeGetTime(const char*, int);

void TribeTacticalAIModule::taskIdleSoldiers(unsigned long startTime,
                                              unsigned long maxTime)
{
    TacticalAIGroup* group = this->groups.next;

    if (this->nextIdleSoldierGroupToTaskValue != -1) {
        while ((group != &this->groups && group != 0) &&
               (group->id() != this->nextIdleSoldierGroupToTaskValue)) {
            group = group->next;
        }
        if (group->id() != this->nextIdleSoldierGroupToTaskValue) {
            group = this->groups.next;
        }
    }

    TacticalAIGroup* end = &this->groups;
    int readyToTask;
    int isGathered;
    int desired;
    int number;
    while (group != end) {
        if (group == 0) {
            this->nextIdleSoldierGroupToTaskValue = -1;
            return;
        }

        if (group->type() == 0x6B || group->type() == 0x6C ||
            group->type() == 0x6A ||
            (group->action() != 0 && group->action() != 1)) {
            group = group->next;
            continue;
        }

        readyToTask = 1;
        if (group->consecutiveGatherAttemptsValue <= 10) {
            isGathered = group->isGathered(this, this->md);
        }
        else {
            isGathered = 1;
        }

        desired = group->desiredNumberUnits();
        number = group->numberUnits();
        if (desired > number) {
            RGE_Static_Object* commanderObj =
                this->md->object(group->commander());
            RGE_Static_Object* targetObj =
                this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1,
                                 -1);
            if (commanderObj == 0 || targetObj == 0) {
                readyToTask = 0;
            }
            else {
                int zone = commanderObj->currentZone() & 0xff;
                if (zone != commanderObj->lookupZone(
                               (int)targetObj->world_x,
                               (int)targetObj->world_y)) {
                    group->setDesiredNumberUnits(group->numberUnits());
                }
                else {
                    readyToTask = 0;
                }
            }
        }
        else if (isGathered == 0) {
            readyToTask = 0;
        }
        else if (group->allUnitsIdle(this->md, 1) == 0) {
            readyToTask = 0;
        }
        else {
            if (group->type() == 0x66 || group->type() == 0x69) {
                if (this->md->informationAI.fullyExploredZone(
                        group->commander()) == 0) {
                    readyToTask = 0;
                    goto ready_to_task_check;
                }
            }

            if (group->type() == 0x64 || group->type() == 0x67) {
                if (this->md->strategyAI.currentVictoryCondition() == 0) {
                    if (this->itemToCapture() == -1 &&
                        group->type() == 0x64) {
                        readyToTask = 0;
                    }
                    else {
                        group->setSubType(0);
                    }
                }
                if (this->md->strategyAI.currentVictoryCondition() == 4) {
                    if (this->itemToBringToArea() == -1 &&
                        group->type() == 0x64) {
                        readyToTask = 0;
                    }
                    else {
                        group->setSubType(4);
                    }
                }
            }
            else if ((group->type() == 0x65 || group->type() == 0x68) &&
                     this->numberItemsToDefend() == 0) {
                readyToTask = 0;
            }
        }

ready_to_task_check:
        if (readyToTask == 0) {
            if (isGathered == 0) {
                group->task(this, this->md, 9, 1, 0);
            }
        }
        else {
            if (group->type() == 0x66 || group->type() == 0x69) {
                group->setAction(8);
            }
            else if (group->type() == 0x64 || group->type() == 0x67) {
                if (this->numberItemsToAttack() == 0 &&
                    group->type() == 0x67) {
                    group->setType(0x69);
                    group->setAction(8);
                }
                else {
                    group->setAction(2);
                }
            }
            else if (group->type() == 0x65 || group->type() == 0x68) {
                group->setAction(4);
            }
            else if (group->type() == 0x6D) {
                group->setAction(0x13);
            }
        }

        goto next_group;

next_group:
        group = group->next;
        this->nextIdleSoldierGroupToTaskValue = group->id();
        if (debug_timeGetTime(s_taitacmd_cpp, 0xEA9) - startTime >=
            maxTime) {
            return;
        }
    }

    this->nextIdleSoldierGroupToTaskValue = -1;
}
