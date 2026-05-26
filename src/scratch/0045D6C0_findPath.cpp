// 0045D6C0 RGE_Moving_Object::findPath
// Attempt log:
// 1: reconstructed behavior from packet/Ghidra, with raw offsets for moving object, Path, player, pathing system and debug globals.
// 2: initial virtual calls via raw function-pointer casts compiled but default cdecl cleanup was wrong for original thiscall virtuals and text was 1152 (<1232).
// 3: replaced raw vf pointer with a padded virtual surface so stop_action is slot +0x12c and move_to is slot +0x34; this gives natural thiscall virtual dispatch but still 1152 bytes under /O2.
// 4: /Op probe grew only to 1168 and remained under-size; /Od produced 1232 bytes but wrong EBP/debug-frame basin (82.3864% positional, 111.5260% edit) and was removed.
// 5: remaining model is behavior-oriented but incomplete for exact shape: original has aligned /O2 frame, explicit [esp+10]/[esp+14] scratch use, precise __ftol/floor stack choreography, and exact pathing/debug loops not reproduced. Not accepted_drift-safe.

#include <math.h>
#include <stdio.h>

typedef unsigned char uchar;
extern "C" int __cdecl _ftol(double);
extern "C" int __cdecl fprintf(FILE*, const char*, ...);
extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;

struct Waypoint { float x; float y; float z; float w; };

class Path {
public:
    char data[0x34];
    void setTimeStamp(int);
    void killPath();
    int insertAtCurrent(Waypoint*);
    void initToStart();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

class RGE_Player {
public:
    char gap00[0x24];
    void** objects;
    char gap28[0x14];
    void* time;
    int availablePathingAttempts(unsigned char n);
    void incrementPathingAttempts();
    int computerPlayer();
};

class PathingSystem {
public:
    void incrementInitialPaths();
    int findTilePath(int,int,int,int,void*,float,int,int,float*,int,int,int,int,int,int);
    int passable(void*, float, float, int);
};
extern PathingSystem pathSystem;

class RGE_Moving_Object {
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
    virtual float move_to(float, float);
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
    virtual void stop_action(int);
    int id;
    void* master;
    RGE_Player* owner;
    char gap10[0x28];
    float x; float y; float z;
    char gap44[0x14];
    int field58;
    char gap5c[0x48];
    Path path;                 // +A4
    Path exceptionPath;        // +D8
    Waypoint startValue;       // +10C
    Waypoint goalValue;        // +11C
    char gap12c[8];
    int targetIDValue;         // +134
    int targetClass;           // +138
    char gap13c[8];
    int continueCounter;       // +144
    char gap148[0xE];
    unsigned char numberWaitDelays; // +156
    char gap157[0x11];
    unsigned char* userDefinedWaypoints; // +168
    int numberUserDefinedWaypointsValue; // +16C
    int maxUserDefinedWaypoints; // +170
    char gap174[4];
    float closestDistanceToWaypoint; // +178
    int findPath();
};


int RGE_Moving_Object::findPath()
{
    if (*(float*)((char*)this->master + 0x38) <= 0.0f) {
        this->stop_action(0);
        this->startValue.x = this->x;
        this->startValue.y = this->y;
        this->startValue.z = this->z;
        this->field58 = 0;
        this->path.setTimeStamp(*(int*)((char*)this->owner->time + 4));
        this->path.killPath();
        this->path.insertAtCurrent(&this->goalValue);
        this->path.insertAtCurrent(&this->startValue);
        this->path.initToStart();
        this->path.moveToNextWaypoint();
        this->closestDistanceToWaypoint = 100000.0f;
        return 0;
    }

    if (!this->owner->availablePathingAttempts(this->numberWaitDelays)) {
        this->numberWaitDelays++;
        return 2;
    }
    this->owner->incrementPathingAttempts();
    this->numberWaitDelays = 0;
    this->stop_action(0);
    if (!this->owner->computerPlayer()) this->continueCounter = this->numberUserDefinedWaypointsValue + 0x19;
    else this->continueCounter = this->numberUserDefinedWaypointsValue + 0x0f;
    this->startValue.x = this->x;
    this->startValue.y = this->y;
    this->startValue.z = this->z;
    this->closestDistanceToWaypoint = 100000.0f;
    pathSystem.incrementInitialPaths();

    int sx, sy;
    if (this->numberUserDefinedWaypointsValue > 0) {
        sy = this->userDefinedWaypoints[1];
        sx = this->userDefinedWaypoints[0];
    } else {
        sy = _ftol(this->goalValue.y);
        sx = _ftol(this->goalValue.x);
    }
    int ey = _ftol(this->startValue.y);
    int ex = _ftol(this->startValue.x);
    int found = pathSystem.findTilePath(ex, ey, sx, sy, this, *(float*)((char*)this + 0x120), this->targetIDValue, 1, 0, 1, 1, 1, 1, -1, -1);

    if (actionFile != 0) {
        fprintf(actionFile, (const char*)0x584C9C, *(int*)((char*)this->owner->time + 4), this->id, this->startValue.x, this->startValue.y, this->goalValue.x, this->goalValue.y);
        this->path.initToStart();
        int i=0;
        while (i < this->path.numberOfWaypoints()) {
            Waypoint* w=this->path.currentWaypoint();
            fprintf(actionFile, (const char*)0x584C84, i, w->x, w->y);
            i++;
            this->path.moveToNextWaypoint();
        }
        fprintf(actionFile, (const char*)0x584C80);
        this->path.initToStart();
        this->path.moveToNextWaypoint();
    }

    if (!found && this->path.numberOfWaypoints() == 1) {
        float fx = (float)(floor(this->x) + 0.5);
        float fy = (float)(floor(this->y) + 0.5);
        if (pathSystem.passable(this, fx, fy, 1)) {
            if ((this->x - floor(this->x)) != 0.5 || (this->y - floor(this->y)) != 0.5) {
                this->move_to((float)(floor(this->x)+0.5), (float)(floor(this->y)+0.5));
                return 2;
            }
        }
    }

    this->path.setTimeStamp(*(int*)((char*)this->owner->time + 4));
    if (displayPathingFlags && (((int*)this)[0x0d] & 1)) {
        this->path.initToStart();
        int i=0;
        while (i < this->path.numberOfWaypoints()) {
            void* obj = this->owner->objects[displayPathObjectID];
            Waypoint* w=this->path.currentWaypoint();
            ((void (*)(void*, RGE_Moving_Object*, float, float, float))(*(void***)obj)[6])(obj, this, w->x, w->y, 1.0f);
            i++;
            this->path.moveToNextWaypoint();
        }
        this->path.initToStart();
        this->path.moveToNextWaypoint();
    }
    this->path.initToStart();
    this->path.moveToNextWaypoint();
    return 0;
}
