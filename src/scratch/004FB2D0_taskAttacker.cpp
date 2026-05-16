// VA: 004FB2D0 TribeTacticalAIModule::taskAttacker
// Source: taitacmd.cpp lines 9056-9125
// Attempt log:
// 1: initial packet/decompiler reconstruction with local stubs and inline ManagedArray<int> add.
// 2: rewrote early failure paths to shared fail label and corrected world pointer chain (+f0/+f0/+3c).
// 3: made attackerID parameter const to avoid early save in ebx; prologue now matches through first object lookup, but function became 1 byte short and fail block placed early.
// 4: replaced direct fail returns with result variable and done label; no placement change.
// 5: expanded RGE_Static_Object virtual surface so vf_10c call lands at vtable +0x10c.
// 6: corrected command id expression: original maps commandFlag==1 to 0x2d9, otherwise 0x2bc.
// 7: rewrote assigned-attacker duplicate scan using direct indexed array access; no size/codegen improvement.
// 8: verified object lookup chain now matches original +0xf0/+0xf0/+0x3c and first prologue matches after const attackerID.
// 9: remaining target-command branch still differs broadly; vtable +0x10c is fixed but stack argument scheduling and command vtable call are wrong.
// 10: final state compiles but check_function cannot compare because rebuilt .text is 544 bytes vs original configured 545; not accepted_drift-safe.

extern "C" void* __cdecl operator_new(unsigned long sz);
extern "C" void __cdecl operator_delete(void* p);
extern "C" long __cdecl _ftol();

struct Waypoint { float x; float y; int a; int b; };

class RGE_Game_World { public: void* object(int id); };
class UnitAIModule { public: char gap[0x4A]; short type_id; };
class Player { public: char gap_00[0x3C]; RGE_Game_World* world; char gap_40[0xF0 - 0x40]; UnitAIModule* md; };
class WorldHolder { public: char gap[0xF0]; Player* player; };

class RGE_Static_Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual float vf_10c(int, int, int);
    void* unitAI();
    float distance_to_object(RGE_Static_Object* other);
    float distance_to_position(int x, int y, float z);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    WorldHolder* owner;
    char gap_0F4[0xD58 - 0xF4];
    int* attackersValue;
    int attackersNumber;
    char gap_D60[4];
    int attackersMax;

    int taskAttacker(const int attackerID, int x, float y, float z, int targetID, int arg6, Waypoint* waypoints, int waypointCount, int commandFlag);
    void addWaypoint(int unitID, int x, int y);
    int calculatePriority(float dist);
    int moveUnit(int id, int x, int y, int priority);
};

int TribeTacticalAIModule::taskAttacker(const int attackerID, int x, float y, float z, int targetID, int arg6, Waypoint* waypoints, int waypointCount, int commandFlag)
{
    RGE_Static_Object* attacker;
    int priority;
    int i;
    int result;

    result = 0;
    if (attackerID == -1) {
        goto fail;
    }

    attacker = (RGE_Static_Object*)this->owner->player->world->object(attackerID);
    if (attacker == 0) {
        goto fail;
    }
    if (attacker->unitAI() == 0) {
        goto fail;
    }

    if (waypoints != 0 && waypointCount > 0) {
        do {
            this->addWaypoint(attackerID, (int)waypoints->x, (int)waypoints->y);
            ++waypoints;
            --waypointCount;
        } while (waypointCount != 0);
    }

    if (targetID != -1) {
        RGE_Static_Object* target = (RGE_Static_Object*)this->owner->player->world->object(targetID);
        if (target == 0) {
            goto fail;
        }
        float dist = attacker->distance_to_object(target);
        priority = this->calculatePriority(dist);
        UnitAIModule* md = this->owner->player->md;
        int cmd = (commandFlag == 1) ? 0x2d9 : 0x2bc;
        int zero = *(int*)this->owner->player;
        float f = attacker->vf_10c(1, 0, priority);
        (void)f;
        // virtual command call approximated through vtable slot on md
        typedef void (*CmdFn)(UnitAIModule*, int, int, int, int, int, int, int, int, float, float);
        (*(CmdFn*)((char*)*(int*)zero + 0x30))((UnitAIModule*)md, md->type_id, attackerID, cmd, zero, x, *(int*)&y, *(int*)&z, targetID, 1.0f, f);
    } else {
        int ix = x;
        int iy = *(int*)&y;
        float dist = attacker->distance_to_position(ix, iy, 1.0f);
        priority = this->calculatePriority(dist);
        i = this->moveUnit(attackerID, ix, iy, priority);
    }

    i = 0;
    if (this->attackersNumber > 0) {
        do {
            if (i >= this->attackersMax) {
                break;
            }
            if (*(this->attackersValue + i) == attackerID) {
                result = 1;
                goto done;
            }
            ++i;
        } while (i < this->attackersNumber);
    }

    if (this->attackersNumber > this->attackersMax - 1) {
        int newMax = this->attackersNumber + 1;
        int* newArr = (int*)operator_new(newMax * 4);
        if (newArr != 0) {
            int j = 0;
            if (this->attackersMax > 0) {
                do {
                    if (j >= newMax) break;
                    newArr[j] = this->attackersValue[j];
                    ++j;
                } while (j < this->attackersMax);
            }
            operator_delete(this->attackersValue);
            this->attackersValue = newArr;
            this->attackersMax = newMax;
        }
    }
    this->attackersValue[this->attackersNumber] = attackerID;
    ++this->attackersNumber;
    result = 1;
    goto done;

fail:
    result = 0;

done:
    return result;
}
