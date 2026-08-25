// 0045D6C0 RGE_Moving_Object::findPath
// The canonical RGE_Moving_Object, Path, and UnitAIModule surfaces live in
// include/move_obj_context.h. The source uses those named declarations.
// Standalone owner checkpoint: move_obj.cpp:663-815, 1232 bytes, 50 ordered
// calls, default flags, and 0.0000% difference. The grouped wrapper remains
// the validation authority for this module context.

#include <math.h>
#include <stdio.h>

extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;
extern float DAT_00570B80;

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
