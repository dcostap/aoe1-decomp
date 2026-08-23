// 0045D6C0 RGE_Moving_Object::findPath
// Attempt log:
// 1: reconstructed behavior from packet/Ghidra, with raw offsets for moving object, Path, player, pathing system and debug globals.
// 2: initial virtual calls via raw function-pointer casts compiled but default cdecl cleanup was wrong for original thiscall virtuals and text was 1152 (<1232).
// 3: replaced raw vf pointer with a padded virtual surface so stop_action is slot +0x12c and move_to is slot +0x34; this gives natural thiscall virtual dispatch but still 1152 bytes under /O2.
// 4: /Op probe grew only to 1168 and remained under-size; /Od produced 1232 bytes but wrong EBP/debug-frame basin (82.3864% positional, 111.5260% edit) and was removed.
// 5: remaining model is behavior-oriented but incomplete for exact shape: original has aligned /O2 frame, explicit [esp+10]/[esp+14] scratch use, precise __ftol/floor stack choreography, and exact pathing/debug loops not reproduced. Not accepted_drift-safe.
// 6: direct currentWaypoint() expressions restored the oracle's two call sites per coordinate pair and aligned all 50 calls.
// 7: the original 0045D76B block is an unreachable compiler-generated vcall-thunk guard; an address-based diagnostic reproduced its CFG/size but was removed from the living source as opaque scaffolding.
// 8: canonicalized Waypoint and moving-object field ownership (selected +36, actionRange +134, targetID +138); remaining drift is source/VC5 topology, not a proven field offset.
// 9: paused after the bounded assignment; clean source is frame-exact with 49/50 calls, while the diagnostic guard reached size/CFG/call parity but was not a plausible source reconstruction.
// 10: tested the natural pre-gate waiting-state reset from the ordered call map; it improved size but changed the later virtual call to an indirect register call, so it was restored.
// 11: named a local start waypoint pointer to follow the original EBP-preserved address; first mismatch shifted earlier and diff worsened to 1120, so it was restored.
// 12: donor-backed typed member-pointer null guard plus canonical ManagedArray ownership restored the missing vcall and matched 50/50 calls and CFG, but worsened positional diff to 1106; rolled back as opaque compiler steering.
// 13: fresh pass tested 27 distinct source, ABI, layout, liveness, and control-flow hypotheses. The best clean guarded model reached 50/50 calls, 1207 bytes, and diff 931, but its null guard is not supported by the constant vcall-thunk condition and was not retained.
// 14: natural float-to-int casts preserve the original ST0 __ftol ABI. Direct branch-local findTilePath calls preserve the original user-waypoint setup and tail-merge to one emitted call; the clean result remains unresolved at 49/50 calls because the unreachable compiler block is omitted.
// 15: binary call-map audit restored the vcall-thunk guard as a pointer-to-member expression. It restores the original 50-call CFG island, but the source remains nonexact.
// 16: the reviewed int availablePathingAttempts ABI restores the original zero-extended byte argument and improves the clean result to 422 differing bytes.
// 17: the selected-bit publication guard restores the original test byte +0x36,1 and improves the clean result to 331 differing bytes with 50/50 calls.
// 18: direct owner rereads preserve fault order but change the publication codegen basin.
// 19: named floor-result temporaries change x87 lifetime. Direct expressions keep the shipped stack order.
// 20: the PDB lists setStart and displayPath as inline RGE_Moving_Object methods.
//     The complete line-808 band is the inlined displayPath body.
// 21: casting each floor result before subtraction restores both x87 argument blocks.
//     Casting the complete subtraction adds two bytes and produces 381 differing bytes.
// 22: ManagedArray<int>::zeroNumber restores the fast-path Path receiver schedule.
//     A direct numberValue store produces 35 differing bytes.
// 23: expanding displayPath at the call site removes two bytes and produces 115 differing bytes.
//     The displayPath and floor-cast changes form one required exact-size group.
// 24: the second zeroNumber call is codegen-incidental. Protected ManagedArray ownership still requires it.
// 25: canonical Path ABI, inheritance, fields, names, and standard-header cleanup emit identical bytes.
// FINAL EXACT: move_obj.cpp:663-815, 1232 bytes, 50 ordered calls, default flags, and 0.0000% difference.

#include <math.h>
#include <stdio.h>

typedef unsigned char uchar;
extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;
extern float DAT_00570B80;

struct Waypoint {
    float x;
    float y;
    float z;
    uchar facetToNextWaypoint;
    uchar pad[3];
};

template<class T>
class ManagedArray {
public:
    void zeroNumber() { this->numberValue = 0; }

protected:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct XYZBYTEPoint {
    uchar x;
    uchar y;
    uchar z;
};

class Path {
public:
    void setTimeStamp(unsigned long);
    void killPath();
    int insertAtCurrent(const Waypoint&);
    void initToStart();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();

protected:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};

class RGE_Static_Object;
class RGE_Master_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap28[0x14];
    RGE_Game_World* world;
    int availablePathingAttempts(int n);
    void incrementPathingAttempts();
    int computerPlayer();
};

class RGE_Moving_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    char gap04[0x2C];
    float radius_x;
    float radius_y;
    float radius_z;
};

class PathingSystem {
public:
    void incrementInitialPaths();
    int findTilePath(int, int, int, int, RGE_Moving_Object*, float, int,
                     int, float*, int, int, int, int, int, int);
    int passable(RGE_Moving_Object*, float, float, int);
};
extern PathingSystem pathSystem;

class RGE_Static_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual float teleport(float, float, float);
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void setWaitingToMove(uchar);
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x; float world_y; float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    void* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar pad87;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    enum PathResult {
        PathFound = 0,
        NoPathFound = 1,
        WaitingOnPathingCap = 2
    };
    virtual float teleport(float, float, float);
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;            // +A4
    Path exceptionPathValue;   // +D8
    Waypoint startValue;       // +10C
    Waypoint goalValue;        // +11C
    float turnTimer;           // +12C
    float collisionAvoidanceDistance; // +130
    float actionRange;         // +134
    int targetIDValue;          // +138
    float targetRadiusX;        // +13C
    float targetRadiusY;        // +140
    int continueCounter;        // +144
    int rangeStatusValue;       // +148
    int currentTerrainException1; // +14C
    int currentTerrainException2; // +150
    uchar storePathInExceptionPath; // +154
    uchar waitingToMoveValue;   // +155
    uchar numberWaitDelays;     // +156
    uchar pad157;
    int minInitialPointX;       // +158
    int minInitialPointY;       // +15C
    int maxInitialPointX;       // +160
    int maxInitialPointY;       // +164
    XYZBYTEPoint* userDefinedWaypoints; // +168
    int numberUserDefinedWaypointsValue; // +16C
    int maxUserDefinedWaypointsValue; // +170
    uchar finalUserDefinedWaypoint; // +174
    uchar pad175[3];
    float closestDistanceToWaypoint; // +178
    void setStart(float startX, float startY, float startZ) {
        this->startValue.x = startX;
        this->startValue.y = startY;
        this->startValue.z = startZ;
    }
    PathResult findPath();
    // BINARY NOTE: PDB line 808 maps this complete inline body to one source call.
    void displayPath(int objectID) {
        if (displayPathingFlags && (this->selected & 1) != 0) {
            this->pathValue.initToStart();
            int i = 0;
            while (i < this->pathValue.numberOfWaypoints()) {
                this->owner->master_objects[objectID]->make_new_obj(
                    this->owner, this->pathValue.currentWaypoint()->x,
                    this->pathValue.currentWaypoint()->y, 1.0f);
                i++;
                this->pathValue.moveToNextWaypoint();
            }
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }
    }
};

RGE_Moving_Object::PathResult RGE_Moving_Object::findPath()
{
    if (this->master_obj->radius_z <= 0.0f) {
        this->setWaitingToMove(0);
        this->setStart(this->world_x, this->world_y, this->world_z);
        // BINARY NOTE: the inline helper is required for the original Path receiver schedule.
        this->pathingGroupMembers.zeroNumber();
        this->pathValue.setTimeStamp(this->owner->world->world_time);
        this->pathValue.killPath();
        this->pathValue.insertAtCurrent(this->goalValue);
        this->pathValue.insertAtCurrent(this->startValue);
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
        this->closestDistanceToWaypoint = 100000.0f;
        return PathFound;
    }

    // BINARY NOTE: the executable keeps this constant guard and its unreachable cleanup arm.
    void (RGE_Moving_Object::*waitFunction)(uchar) =
        &RGE_Moving_Object::setWaitingToMove;
    if (waitFunction == 0) {
        this->pathingGroupMembers.zeroNumber();
        this->setWaitingToMove(0);
        return NoPathFound;
    }

    if (!this->owner->availablePathingAttempts(this->numberWaitDelays)) {
        this->numberWaitDelays++;
        return WaitingOnPathingCap;
    }
    this->owner->incrementPathingAttempts();
    this->numberWaitDelays = 0;
    this->setWaitingToMove(0);
    if (!this->owner->computerPlayer()) {
        this->continueCounter = this->numberUserDefinedWaypointsValue + 0x19;
    } else {
        this->continueCounter = this->numberUserDefinedWaypointsValue + 0x0f;
    }
    this->setStart(this->world_x, this->world_y, this->world_z);
    this->closestDistanceToWaypoint = 100000.0f;
    pathSystem.incrementInitialPaths();

    int found;
    if (this->numberUserDefinedWaypointsValue > 0) {
        found = pathSystem.findTilePath(
            // BINARY NOTE: natural casts keep __ftol input on x87 ST0.
            (int)this->startValue.x, (int)this->startValue.y,
            this->userDefinedWaypoints->x, this->userDefinedWaypoints->y,
            this, this->actionRange, this->targetIDValue,
            1, 0, 1, 1, 1, 1, -1, -1);
    } else {
        found = pathSystem.findTilePath(
            (int)this->startValue.x, (int)this->startValue.y,
            (int)this->goalValue.x, (int)this->goalValue.y,
            this, this->actionRange, this->targetIDValue,
            1, 0, 1, 1, 1, 1, -1, -1);
    }

    if (actionFile != 0) {
        fprintf(actionFile, (const char*)0x584C9C,
                this->owner->world->world_time, this->id,
                this->startValue.x, this->startValue.y,
                this->goalValue.x, this->goalValue.y);
        this->pathValue.initToStart();
        int i = 0;
        while (i < this->pathValue.numberOfWaypoints()) {
            fprintf(actionFile, (const char*)0x584C84, i,
                    this->pathValue.currentWaypoint()->x,
                    this->pathValue.currentWaypoint()->y);
            i++;
            this->pathValue.moveToNextWaypoint();
        }
        fprintf(actionFile, (const char*)0x584C80);
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
    }

    if (!found && this->pathValue.numberOfWaypoints() == 1) {
        // BINARY NOTE: cast each floor result before subtracting the float tile bias.
        if (pathSystem.passable(this,
                                (float)floor((double)this->world_x) - DAT_00570B80,
                                (float)floor((double)this->world_y) - DAT_00570B80, 1)) {
            if ((this->world_x - floor((double)this->world_x)) != 0.5 ||
                (this->world_y - floor((double)this->world_y)) != 0.5) {
                this->teleport(
                    (float)floor((double)this->world_x) - DAT_00570B80,
                    (float)floor((double)this->world_y) - DAT_00570B80, this->world_z);
                return WaitingOnPathingCap;
            }
        }
    }

    this->pathValue.setTimeStamp(this->owner->world->world_time);
    this->displayPath(displayPathObjectID);
    this->pathValue.initToStart();
    this->pathValue.moveToNextWaypoint();
    return PathFound;
}
