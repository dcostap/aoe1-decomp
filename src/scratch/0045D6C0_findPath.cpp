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
// 15: caching displayPathObjectID before the display guard recovered the 0x10 frame and the original stack-home shape.
// 16: a typed master-object call at vslot +0x18 recovered the donor-backed path-display ownership and improved block coverage.
// 17: a loop-local owner alias plus a direct typed master-object call removed the raw call surface and improved block coverage.
// 18: DAT_00570B80 and explicit double floor operands recovered the shipped float subtraction form.
// 19: the +0x34 virtual move_to call takes three floats; passing z recovered the full move-to block and reduced diff to 914 bytes in the guarded diagnostic.
// 20: a typed master pointer at +0x38 produced the same bytes as the proven raw access and is retained as the simpler ownership model.
// 21: the pointer-to-member guard reached 50 calls, 1232 bytes, and 914-byte diff, but it used metric-only scaffolding and was removed.
// 22: same-TU and PDB evidence replace the master vf placeholders with the canonical destructor, copy, modify, save, and make_new_obj names.
// 23: staging waypoint coordinates before the master lookup changed the frame to 0x18 and worsened the result; direct expressions were restored.
// 24: the owner cache keeps the owner in EBX, but VC5 emits the master-table reload before currentWaypoint in this source form. The original reload is after both waypoint calls.

#include <math.h>
#include <stdio.h>

typedef unsigned char uchar;
extern "C" int __cdecl fprintf(FILE*, const char*, ...);
extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;
extern float DAT_00570B80;

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facet;
    unsigned char pad[3];
};

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
    void setTimeStamp(int);
    void killPath();
    int insertAtCurrent(Waypoint*);
    void initToStart();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Moving_Object {
public:
    char gap00[0x38];
    float pathingValue;
};

class RGE_Player {
public:
    char gap00[0x24];
    // BINARY NOTE: the +0x24 table uses the master-object make_new_obj slot.
    RGE_Master_Static_Object** master_objects;
    char gap28[0x14];
    void* time;
    int availablePathingAttempts(unsigned char n);
    void incrementPathingAttempts();
    int computerPlayer();
};

class RGE_Moving_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
};

class PathingSystem {
public:
    void incrementInitialPaths();
    int findTilePath(int,int,int,int,RGE_Moving_Object*,float,int,int,float*,int,int,int,int,int,int);
    int passable(RGE_Moving_Object*, float, float, int);
};
extern PathingSystem pathSystem;

class RGE_Moving_Object {
public:
    enum PathResult {
        PathFound = 0,
        PathNoPath = 1,
        WaitingOnPathingCap = 2
    };
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
    // BINARY NOTE: the +0x34 call pushes three float arguments.
    virtual float move_to(float, float, float);
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
    virtual void setWaitingToMove(unsigned char);
    int id;
    RGE_Master_Moving_Object* master_obj;
    RGE_Player* owner;
    char gap10[0x24];
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float x; float y; float z;
    char gap44[0x10];
    ManagedArrayInt pathingGroupMembers;
    char gap64[0x40];
    Path path;                 // +A4
    Path exceptionPath;        // +D8
    Waypoint startValue;       // +10C
    Waypoint goalValue;        // +11C
    float turnTimer;           // +12C
    float collisionAvoidanceDistance; // +130
    float actionRange;         // +134
    int targetIDValue;          // +138
    float targetRadiusX;       // +13C
    float targetRadiusY;       // +140
    int continueCounter;       // +144
    char gap148[0xE];          // through +156
    unsigned char numberWaitDelays; // +156
    char gap157[0x11];
    XYZBYTEPoint* userDefinedWaypoints; // +168
    int numberUserDefinedWaypointsValue; // +16C
    int maxUserDefinedWaypoints; // +170
    char gap174[4];
    float closestDistanceToWaypoint; // +178
    PathResult findPath();
};


RGE_Moving_Object::PathResult RGE_Moving_Object::findPath()
{
    float x;
    float y;
    float z;
    if (this->master_obj->pathingValue <= 0.0f) {
        this->setWaitingToMove(0);
        x = this->x;
        y = this->y;
        z = this->z;
        this->startValue.x = x;
        this->startValue.y = y;
        this->startValue.z = z;
        // BINARY NOTE: this is the ManagedArray count at object offset +0x58.
        this->pathingGroupMembers.numberValue = 0;
        this->path.setTimeStamp(*(int*)((char*)this->owner->time + 4));
        this->path.killPath();
        this->path.insertAtCurrent(&this->goalValue);
        this->path.insertAtCurrent(&this->startValue);
        this->path.initToStart();
        this->path.moveToNextWaypoint();
        this->closestDistanceToWaypoint = 100000.0f;
        return PathFound;
    }

    if (!this->owner->availablePathingAttempts(this->numberWaitDelays)) {
        this->numberWaitDelays++;
        return WaitingOnPathingCap;
    }
    this->owner->incrementPathingAttempts();
    this->numberWaitDelays = 0;
    this->setWaitingToMove(0);
    if (!this->owner->computerPlayer()) this->continueCounter = this->numberUserDefinedWaypointsValue + 0x19;
    else this->continueCounter = this->numberUserDefinedWaypointsValue + 0x0f;
    x = this->x;
    y = this->y;
    z = this->z;
    this->startValue.x = x;
    this->startValue.y = y;
    this->startValue.z = z;
    this->closestDistanceToWaypoint = 100000.0f;
    pathSystem.incrementInitialPaths();

    int found;
    // LIKELY INTENT: separate calls let VC5 keep branch-local argument setup.
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
        fprintf(actionFile, (const char*)0x584C9C, *(int*)((char*)this->owner->time + 4), this->id, this->startValue.x, this->startValue.y, this->goalValue.x, this->goalValue.y);
        this->path.initToStart();
        int i = 0;
        while (i < this->path.numberOfWaypoints()) {
            fprintf(actionFile, (const char*)0x584C84, i,
                    this->path.currentWaypoint()->x,
                    this->path.currentWaypoint()->y);
            i++;
            this->path.moveToNextWaypoint();
        }
        fprintf(actionFile, (const char*)0x584C80);
        this->path.initToStart();
        this->path.moveToNextWaypoint();
    }

    if (!found && this->path.numberOfWaypoints() == 1) {
        if (pathSystem.passable(this,
                                (float)(floor((double)this->x) - DAT_00570B80),
                                (float)(floor((double)this->y) - DAT_00570B80), 1)) {
            if ((this->x - floor((double)this->x)) != 0.5 ||
                (this->y - floor((double)this->y)) != 0.5) {
                this->move_to(
                    (float)(floor((double)this->x) - DAT_00570B80),
                    (float)(floor((double)this->y) - DAT_00570B80), this->z);
                return WaitingOnPathingCap;
            }
        }
    }

    this->path.setTimeStamp(*(int*)((char*)this->owner->time + 4));
    // BINARY NOTE: the original caches this global before the display guard.
    int objectID = displayPathObjectID;
    if (displayPathingFlags && this->selected) {
        this->path.initToStart();
        int i = 0;
        while (i < this->path.numberOfWaypoints()) {
            // BINARY NOTE: owner stays cached, but VC5 orders the table lookup before waypoint reads here.
            RGE_Player* owner = this->owner;
            owner->master_objects[objectID]->make_new_obj(
                owner, this->path.currentWaypoint()->x,
                this->path.currentWaypoint()->y, 1.0f);
            i++;
            this->path.moveToNextWaypoint();
        }
        this->path.initToStart();
        this->path.moveToNextWaypoint();
    }
    this->path.initToStart();
    this->path.moveToNextWaypoint();
    return PathFound;
}
