// 004F95B0 TribeTacticalAIModule::highLevelTaskGatherer
// taitacmd.cpp
// Attempt log:
// try 1: broad reconstruction from packet: find gatherer slot, throttle, validate object/AI action, attempt tasking priorities.
// try 2: modeled initial gatherer-slot search over +0x51C records with count at +0x9CC and 0x18-byte stride.
// try 3: modeled debug_timeGetTime(0x5880C0,0x1F5C) throttle using slot+0x14 and 5000ms early return.
// try 4: modeled world/object table lookup through this+0xF0 and md+0x3C, then UnitAI/ActionState call chain.
// try 5: modeled early returns for current actions 0x258, 0x25A, 0x26A and nonnegative resourceAmount at object+0x44.
// try 6: modeled canTask(obj) resource-pressure branch using idle/desired difference and resource estimate < 1000.
// try 7: modeled order/subaction early returns for order 0x2C6/subaction 100 and order 0x2BE.
// try 8: modeled priority-slot logic around +0x520/+0x524 and assignTask(004FA170) failure reset.
// try 9: modeled four triedTasking slots and later task attempts for modes 1/2/3 and fallback assignTask.
// try 10: compiled default: rebuilt .text 896B vs original 1018B, no full diff.
// try 11: /GX probe made no code/size change (still 896B), removed flag file.
// left in scratch: broad control/call behavior is reconstructed, but exact inlined assign-task decision tree and multiple repeated ActionState calls are incomplete/collapsed; rebuilt is size-short. No accepted_drift: no comparable localized diff.

class ActionState { public: int currentAction(); int currentOrder(); int currentSubAction(); };
class UnitAI { public: ActionState* state(); };
class StaticObj { public: char gap0[0x40]; float resourceAmount; UnitAI* unitAI(); };
class ObjTable { public: StaticObj* object(int); };
class World { public: char gap0[0xf0]; void* md; };
class ResourceAI { public: int estimate(int); };

class TribeTacticalAIModule {
public:
    char gap0[0xf0]; World* world; int idleCount; int maxCivs; char gap0fc[0x468-0xfc];
    int task1Enabled; int task2Enabled; int task3Enabled;
    char gap474[0x51c-0x474];
    int gathererId; int currentTask; int priority; int lastObj; int lastTask; int lastTime; // +51c, stride-ish
    char gap534[0x9cc-0x534]; int gathererCount;

    int highLevelTaskGatherer(int id, unsigned int arg);
    int canTask(StaticObj*);
    int availableCount();
    int desiredCount();
    int isGathererBusy(int);
    int assignTask(int objId,int task,int a,int b,int c);
    int checkMode(int);
};
extern unsigned long debug_timeGetTime(const char*, int);

int TribeTacticalAIModule::highLevelTaskGatherer(int id, unsigned int arg) {
    int tried[4];
    int i;
    int idx;
    int delta;
    StaticObj* obj;
    ActionState* st;
    int taskResult;

    tried[0]=tried[1]=tried[2]=tried[3]=0;
    idx = 0;
    while (idx < gathererCount) {
        if (*((int*)((char*)this + 0x51c + idx*0x18)) == id) break;
        ++idx;
    }
    if (idx >= gathererCount) return 0;

    unsigned long now = debug_timeGetTime((const char*)0x5880C0,0x1f5c);
    int* slot = (int*)((char*)this + 0x51c + idx*0x18);
    delta = now - slot[5];
    if ((unsigned int)delta < 5000) return 1;
    slot[5] = now;

    obj = ((ObjTable*)*((void**)((char*)world->md + 0x3c)))->object(id);
    if (!obj || !obj->unitAI()) return 0;
    st = obj->unitAI()->state();
    if (st->currentAction() == 0x258) return 1;
    if (st->currentAction() == 0x25a || st->currentAction() == 0x26a) return 1;
    if (obj->resourceAmount >= 0.0f) return 1;
    if (canTask(obj) == 1) {
        int avail = idleCount;
        int desired = desiredCount();
        avail -= desired;
        if (((ResourceAI*)((char*)world + 0x10d7c))->estimate(0) < 1000 && avail > 3) return 1;
    }
    if (st->currentOrder() == 0x2c6 && st->currentSubAction() == 100) return 1;
    if (st->currentOrder() == 0x2be) return 1;

    int* slot2 = (int*)((char*)this + 0x51c + (idx+0x37)*0x18);
    if (*(int*)((char*)this+0x524) > slot2[0]) {
        if (st->currentAction() != -1) return 1;
        taskResult = assignTask(*((int*)((char*)this+0x51c)), arg, 0, 0, 0);
        if (taskResult == 1) return 1;
        *((int*)((char*)this+0x520)) = -1;
        *((int*)((char*)this+0x524)) = -1;
        slot2[0] = -1;
    }

    for (i=0;i<4;i++) {
        if (tried[i] != 1) {
            int* q = (int*)((char*)this + 0xd78 + i*4);
            if (q[-4] < q[0]) {
                if (*((int*)((char*)this+0x520)) == 0) {
                    if (st->currentAction()==0x265 || st->currentAction()==0x261) return 1;
                }
                tried[i] = 1;
                taskResult = assignTask(*((int*)((char*)this+0x51c)), arg, 0, i, 0);
                if (taskResult == 1) return 1;
            }
        }
    }
    taskResult = 0;
    if (checkMode(1) && task1Enabled == 1) {
        taskResult = assignTask(*((int*)((char*)this+0x51c)), arg, 1, 0, 0);
        tried[0]=1;
    } else if (checkMode(2) && task2Enabled == 1 && !tried[0]) {
        taskResult = assignTask(*((int*)((char*)this+0x51c)), arg, 1, 0, 0);
    } else if (checkMode(3) && task3Enabled == 1 && !tried[0]) {
        taskResult = assignTask(*((int*)((char*)this+0x51c)), arg, 1, 0, 0);
        tried[0]=1;
    }
    if (!taskResult) taskResult = assignTask(*((int*)((char*)this+0x51c)), arg, 1, -1, &tried[0] != 0);
    return 1;
}
