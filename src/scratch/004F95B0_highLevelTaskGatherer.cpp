// 004F95B0 TribeTacticalAIModule::highLevelTaskGatherer
// taitacmd.cpp: 7988-8225
// Attempt log:
// - Prior worker left a broad raw-offset reconstruction (885B rebuilt, 24/32
//   calls).  The source was reset to the same-TU typed tactical-AI surface
//   before further code-generation work.
// - Baseline candidate: named UnitData/gatherer ownership, the real world /
//   object / UnitAI member calls, resource-AI member call, and the natural
//   four-distribution task loop.  The five-word tried array models the binary's
//   object slot at element zero and four task flags at elements one through
//   four; the fallback passes element one as the output flag array.
// - Baseline check: 32/32 ordered calls and the 0x18 frame were recovered, but
//   the clean typed candidate is 910B versus 1018B (50.30% shape, 934 strict
//   diff bytes); the remaining structural gap is return/block topology.
// - Probes: reducing the scan to a four-word flag array improved frame-local
//   layout but did not change the 910B basin; a typed object/flag union and
//   shared failure/success labels were diagnostic variants only.  The union
//   reached 900B/926 diff bytes but lost the proven 0x18 frame and was rolled
//   back.  All typed variants kept the complete 32-call multiset/site order.
// - Left in scratch: canonical typed baseline, unresolved broad VC5 block
//   layout and duplicated-epilogue topology; no accepted drift.
// - Direct indexed/typed gatherer fields recovered the original folded
//   this-relative addressing and raised shape to 66.39%; a named gatherer
//   pointer had better register coloring but wrong field displacements.
// - Initializing taskResult with triedTasking[1..3] removed the unsupported
//   fifth flag slot and recovered most structural islands.  A shared null
//   tail improved this to 1030B/916 diff, with all 32 ordered calls aligned.
// - A shared success-tail variant was diagnostic only (937B/936 diff) and was
//   rolled back.  Remaining blocker: 0x1C versus 0x18 frame and stack-home/
//   register-color differences; checker remains in STRUCTURAL RECONSTRUCTION.
// - Replaced the raw debug-file address with the named source string. This does
//   not change code generation.

#include "..\..\include\game_globals.h"

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

static const char s_taitacmd_cpp[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";

struct RGE_Static_Object;
struct UnitAIModule;

struct RGE_Game_World {
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

struct TribeResourceAIModule {
    int resource(int index) const;
};

struct TribeMainDecisionAIModule {
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    char gap_F4[0x10D7C - 0xF4];
    TribeResourceAIModule resourceAI;
};

struct UnitAIModule {
    int currentAction();
    int currentOrder();
    int currentOrderPriority();
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char gap_04[0x40];
    float attribute_amount_held;
    UnitAIModule* unitAI();
};

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int data4;
    int lastTaskTime;
};

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct TribeTacticalAIModule {
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    ManagedIntArray civilians;
    ManagedIntArray civilianExplorers;
    char gap_114[0x354];
    int age2Enabled;
    int age3Enabled;
    int age4Enabled;
    char gap_474[0xA8];
    UnitData gatherers[50];
    int numberGatherersValue;
    char gap_9D0[0x398];
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];

    int isFarmer(RGE_Static_Object* object);
    int numberFarmers();
    int inAge(int age);
    int taskGatherer(int id, int task, int mode, ulong param, int* tried);
    int highLevelTaskGatherer(int id, ulong param);
};

int TribeTacticalAIModule::highLevelTaskGatherer(int id, ulong param)
{
    int i;
    int task;
    int remaining;
    int* tried;
    int* desired;
    UnitData* gatherer;
    RGE_Static_Object* gathererObj;
    UnitAIModule* ai;
    unsigned long now;
    int triedTasking[4];
    int taskResult;

    i = 0;
    taskResult = 0;
    triedTasking[1] = 0;
    triedTasking[2] = 0;
    triedTasking[3] = 0;
    gatherer = this->gatherers;
    for (i = 0; i < this->numberGatherersValue; ++i, ++gatherer) {
        if (gatherer->id == id)
            break;
    }
    if (i >= this->numberGatherersValue)
        goto fail;

    now = debug_timeGetTime(s_taitacmd_cpp, 0x1F5C);
    if (now - this->gatherers[i].lastTaskTime < 5000)
        return 1;
    this->gatherers[i].lastTaskTime = now;

    gathererObj = this->md->player->world->object(id);
    if (gathererObj == 0)
        goto fail;
    if (gathererObj->unitAI() == 0)
        goto fail;

    ai = gathererObj->unitAI();
    if (ai->currentAction() == 0x258)
        return 1;
    ai = gathererObj->unitAI();
    if (ai->currentAction() == 0x25A)
        return 1;
    ai = gathererObj->unitAI();
    if (ai->currentAction() == 0x26A)
        return 1;

    if (gathererObj->attribute_amount_held > DAT_005756f0)
        return 1;

    if (this->isFarmer(gathererObj) == 1) {
        remaining = this->civilians.numberValue;
        remaining -= this->numberFarmers();
        if (this->md->resourceAI.resource(0) < 1000 && remaining > 3)
            return 1;
    }

    ai = gathererObj->unitAI();
    if (ai->currentOrder() == 0x2C6) {
        ai = gathererObj->unitAI();
        if (ai->currentOrderPriority() == 100)
            return 1;
    }
    ai = gathererObj->unitAI();
    if (ai->currentOrder() == 0x2BE)
        return 1;

    if (this->gatherers[i].data3 < this->gatherers[i].data2) {
        ai = gathererObj->unitAI();
        if (ai->currentAction() != -1)
            return 1;
        task = this->gatherers[i].data1;
        triedTasking[task + 1] = 1;
        taskResult = this->taskGatherer(this->gatherers[i].id, task, 0, param, 0);
        if (taskResult == 1)
            return 1;
        this->gatherers[i].data1 = -1;
        this->gatherers[i].data2 = -1;
        this->gatherers[i].data3 = -1;
    }

    tried = triedTasking + 1;
    desired = this->desiredGathererDistribution;
    i = 0;
    task = 0;
    do {
        if (*tried != 1 && this->actualGathererDistribution[task] < *desired) {
            if (this->gatherers[i].data1 == task) {
                ai = gathererObj->unitAI();
                if (ai->currentAction() == 0x265)
                    return 1;
                ai = gathererObj->unitAI();
                if (ai->currentAction() == 0x261)
                    return 1;
            }
            *tried = 1;
            taskResult = this->taskGatherer(this->gatherers[i].id, task, 0, param, 0);
            if (taskResult == 1)
                return 1;
        }
        ++task;
        ++tried;
        ++desired;
        ++i;
    } while (i < 4);

    task = 0;
    if (this->inAge(1) != 0 && this->age2Enabled == 1) {
        triedTasking[1] = 1;
    } else if (this->inAge(2) != 0 && this->age3Enabled == 1 && triedTasking[1] == 0) {
        task = 0;
        triedTasking[1] = 1;
    } else if (this->inAge(3) != 0 && this->age4Enabled == 1) {
        if (triedTasking[1] == 0) {
            taskResult = this->taskGatherer(this->gatherers[i].id, 0, 1, param, 0);
            triedTasking[1] = 1;
        }
        if (taskResult != 0)
            return 1;
        task = 3;
    } else {
        task = 0;
        triedTasking[1] = 1;
    }

    taskResult = this->taskGatherer(this->gatherers[i].id, task, 1, param, 0);
    if (taskResult == 0)
        this->taskGatherer(this->gatherers[i].id, -1, 1, param, triedTasking + 1);

    return 1;

fail:
    return 0;
}
