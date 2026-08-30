#include "../include/move_obj.h"
#include "../include/sprite.h"
#include "../include/player.h"
#include "../include/m_mo_obj.h"
#include "../include/command_waypoint.h"
#include "../include/pathsys.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"
#include "../include/game_globals.h"
#include "../include/basegame.h"
#include "../include/rge_fio.h"
#include "../include/xyz_point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern int displayPathingFlags;
extern int displayPathObjectID;



RGE_Moving_Object::RGE_Moving_Object(RGE_Master_Moving_Object* master,
                                     RGE_Player* player,
                                     float x, float y, float z,
                                     int doSetup)
    : RGE_Animated_Object(master,
                          player, x, y, z, 0),
      pathValue(10),
      exceptionPathValue(10),
      rangeStatusValue(2),
      currentTerrainException1(-1),
      currentTerrainException2(-1),
      storePathInExceptionPath(0),
      waitingToMoveValue(0),
      numberWaitDelays(0),
      userDefinedWaypoints(0),
      numberUserDefinedWaypointsValue(0),
      maxUserDefinedWaypointsValue(0),
      finalUserDefinedWaypoint(0) {
    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->setGoal(0.0f, 0.0f, 0.0f);
    this->turnTimer = 0.0f;
    this->lastFacet = 0xFF;
    this->lastFacet2 = 0xFF;
    this->collisionAvoidanceDistance = 0.0f;
    this->actionRange = 0.0f;
    this->targetIDValue = -1;
    this->targetRadiusX = 0.0f;
    this->targetRadiusY = 0.0f;
    this->continueCounter = 0;
    this->closestDistanceToWaypoint = 100000.0f;

    if (doSetup != 0) {
        this->setup(master, player, x, y, z);
    }
}



RGE_Moving_Object::RGE_Moving_Object(int mode,
                                     RGE_Game_World* world,
                                     int doSetup)
    : RGE_Animated_Object(mode, world, 0),
      pathValue(10),
      exceptionPathValue(10),
      rangeStatusValue(2),
      currentTerrainException1(-1),
      currentTerrainException2(-1),
      storePathInExceptionPath(0),
      waitingToMoveValue(0),
      numberWaitDelays(0),
      userDefinedWaypoints(0),
      numberUserDefinedWaypointsValue(0),
      maxUserDefinedWaypointsValue(0),
      finalUserDefinedWaypoint(0) {

    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->setGoal(0.0f, 0.0f, 0.0f);
    this->turnTimer = 0.0f;
    this->lastFacet = 0xFF;
    this->lastFacet2 = 0xFF;
    this->collisionAvoidanceDistance = 0.0f;
    this->actionRange = 0.0f;
    this->targetIDValue = -1;
    this->targetRadiusX = 0.0f;
    this->targetRadiusY = 0.0f;
    this->continueCounter = 0;
    this->closestDistanceToWaypoint = 100000.0f;

    if (doSetup != 0) {
        this->setup(mode, world);
    }
}



RGE_Moving_Object::~RGE_Moving_Object() {
    if (this->userDefinedWaypoints != 0) {
        operator delete(this->userDefinedWaypoints);
        this->userDefinedWaypoints = 0;
    }
}



void RGE_Moving_Object::recycle_in_to_game(
    RGE_Master_Static_Object* master,
    RGE_Player* player,
    float x, float y, float z)
{
    {
        Path path(10);
        this->pathValue = path;
    }

    this->rangeStatusValue = 2;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    this->storePathInExceptionPath = 0;
    this->waitingToMoveValue = 0;
    this->numberWaitDelays = 0;
    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->setGoal(0.0f, 0.0f, 0.0f);

    this->lastFacet = 0xFF;
    this->lastFacet2 = 0xFF;
    this->turnTimer = 0.0f;
    this->collisionAvoidanceDistance = 0.0f;
    this->actionRange = 0.0f;
    this->targetIDValue = -1;
    this->targetRadiusX = 0.0f;
    this->targetRadiusY = 0.0f;
    this->continueCounter = 0;
    this->closestDistanceToWaypoint = 100000.0f;

    RGE_Animated_Object::recycle_in_to_game(master, player, x, y, z);

    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    if (this->sprite != 0) {
        if ((this->sprite->flags & 2) != 0) {
            if (this->sprite->facet_num > 1) {
                this->angle =
                    (DAT_00570b40 / (float)this->sprite->facet_num) *
                    (float)((debug_rand(
                            (char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xC5) *
                             this->sprite->facet_num) / 0x7FFF);

                if (this->angle < DAT_00570b48) {
                    this->angle = this->angle - DAT_00570b4c;
                } else if (this->angle > DAT_00570b50) {
                    this->angle = this->angle - DAT_00570b50;
    }
}

        }
    }

    this->set_angle();
}



int RGE_Moving_Object::setup(RGE_Master_Moving_Object* master_obj,
                             RGE_Player* player, float x, float y, float z) {
    this->RGE_Animated_Object::setup(master_obj, player, x, y, z);

    this->type = 0x1E;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    if (this->sprite != 0) {
        if ((this->sprite->flags & 2) != 0) {
            if (1 < this->sprite->facet_num) {
                float random_angle =
                    DAT_00570b40 / (float)(int)this->sprite->facet_num *
                    (float)((debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xDE) *
                             (int)this->sprite->facet_num) / 0x7FFF);
                this->angle = random_angle;

                if (this->angle < DAT_00570b48) {
                    this->angle = random_angle - DAT_00570b4c;
                    this->set_angle();
                    return 1;
                }
                if (this->angle > DAT_00570b50) {
                    this->angle = random_angle - DAT_00570b50;
                    this->set_angle();
                    return 1;
                }
            }
        }
    }

    this->set_angle();
    return 1;
}

// Path insertion/reset, user-defined waypoint allocation/load, and version-gated fields.
// Path::initToStart, and Path::moveToNextWaypoint. The legacy fallback assigns

int RGE_Moving_Object::setup(int fd, RGE_Game_World* world)
{
    RGE_Animated_Object::setup(fd, world);
    this->type = 0x1e;

    rge_read(fd, &this->trail_remainder, 4);
    rge_read(fd, &this->velocity_x, 4);
    rge_read(fd, &this->velocity_y, 4);
    rge_read(fd, &this->velocity_z, 4);
    rge_read(fd, &this->angle, 4);
    rge_read(fd, &this->turn_towards_time, 4);

    int count;
    rge_read(fd, &count, 4);
    for (int i = 0; i < count; ++i) {
        Waypoint wp;
        rge_read(fd, &wp, 0x10);
        this->pathValue.insertAtEnd(wp);
    }

    int reset_count;
    rge_read(fd, &reset_count, 4);
    int j = 0;
    this->pathValue.initToStart();
    for (; j < reset_count; ++j) {
        this->pathValue.moveToNextWaypoint();
    }

    rge_read(fd, &this->startValue, 0x10);
    rge_read(fd, &this->goalValue, 0x10);
    rge_read(fd, &this->turnTimer, 4);
    rge_read(fd, &this->collisionAvoidanceDistance, 4);
    rge_read(fd, &this->actionRange, 4);
    rge_read(fd, &this->targetIDValue, 4);
    rge_read(fd, &this->targetRadiusX, 4);
    rge_read(fd, &this->targetRadiusY, 4);
    rge_read(fd, &this->continueCounter, 4);
    rge_read(fd, &this->rangeStatusValue, 4);
    rge_read(fd, &this->waitingToMoveValue, 1);
    rge_read(fd, &this->numberWaitDelays, 1);

    rge_read(fd, &this->numberUserDefinedWaypointsValue, 4);
    rge_read(fd, &this->maxUserDefinedWaypointsValue, 4);
    this->userDefinedWaypoints = (XYZBYTEPoint*)operator new(this->maxUserDefinedWaypointsValue * 3);
    for (int k = 0; k < this->numberUserDefinedWaypointsValue; ++k) {
        rge_read(fd, &this->userDefinedWaypoints[k], 3);
    }

    rge_read(fd, &this->finalUserDefinedWaypoint, 1);

    if (!(save_game_version < DAT_00570b54)) {
        rge_read(fd, &this->minInitialPointValue.x, 8);
        rge_read(fd, &this->maxInitialPointValue.x, 8);
    } else {
        this->minInitialPointValue.x = -1;
        this->minInitialPointValue.y = -1;
        this->maxInitialPointValue.x = -1;
        this->maxInitialPointValue.y = -1;
    }

    if (!(save_game_version < DAT_00570b58)) {
        rge_read(fd, &this->closestDistanceToWaypoint, 4);
        rge_read(fd, &this->lastFacet, 1);
    } else {
        this->closestDistanceToWaypoint = 100000.0f;
        this->lastFacet = 0xff;
    }

    if (!(save_game_version < DAT_00570b5c)) {
        rge_read(fd, &this->lastFacet2, 1);
        return 1;
    }
    this->lastFacet2 = 0xff;
    return 1;
}

// six float fields, Path count and records, current index, object fields, and
// user-waypoint fields. The binary has no save error branch.
// explicit byte-offset user-waypoint loop: 642B, three bytes too large; the
// Width audit: 4-byte scalars and records use 4/0x10, points use 8, and byte

void RGE_Moving_Object::save(int handle) {
    RGE_Animated_Object::save(handle);

    rge_write(handle, &this->trail_remainder, 4);
    rge_write(handle, &this->velocity_x, 4);
    rge_write(handle, &this->velocity_y, 4);
    rge_write(handle, &this->velocity_z, 4);
    rge_write(handle, &this->angle, 4);
    rge_write(handle, &this->turn_towards_time, 4);

    Path* path = &this->pathValue;
    int numberOfWaypoints = path->numberOfWaypoints();
    rge_write(handle, &numberOfWaypoints, 4);

    for (int iWaypoint = 0; iWaypoint < numberOfWaypoints; ++iWaypoint) {
        rge_write(handle, (void*)path->waypoint(iWaypoint), 0x10);
    }

    int currentWaypoint = path->currentWaypointNumber();
    rge_write(handle, &currentWaypoint, 4);

    rge_write(handle, &this->startValue, 0x10);
    rge_write(handle, &this->goalValue, 0x10);
    rge_write(handle, &this->turnTimer, 4);
    rge_write(handle, &this->collisionAvoidanceDistance, 4);
    rge_write(handle, &this->actionRange, 4);
    rge_write(handle, &this->targetIDValue, 4);
    rge_write(handle, &this->targetRadiusX, 4);
    rge_write(handle, &this->targetRadiusY, 4);
    rge_write(handle, &this->continueCounter, 4);
    rge_write(handle, &this->rangeStatusValue, 4);
    rge_write(handle, &this->waitingToMoveValue, 1);
    rge_write(handle, &this->numberWaitDelays, 1);

    rge_write(handle, &this->numberUserDefinedWaypointsValue, 4);
    rge_write(handle, &this->maxUserDefinedWaypointsValue, 4);

    for (int iUser = 0; iUser < this->numberUserDefinedWaypointsValue; ++iUser) {
        rge_write(handle, &this->userDefinedWaypoints[iUser], 3);
    }

    rge_write(handle, &this->finalUserDefinedWaypoint, 1);
    rge_write(handle, &this->minInitialPointValue.x, 8);
    rge_write(handle, &this->maxInitialPointValue.x, 8);
    rge_write(handle, &this->closestDistanceToWaypoint, 4);
    rge_write(handle, &this->lastFacet, 1);
    rge_write(handle, &this->lastFacet2, 1);
}

void RGE_Moving_Object::new_sprite(RGE_Sprite* sprite) {
    if (sprite == 0) {
        sprite = this->master_obj->sprite;
    }
    if (this->sprite != sprite) {
        this->old_sprite = this->sprite;
        RGE_Static_Object::new_sprite(sprite);
        this->set_angle();
    }
}

RGE_Static_Object* RGE_Moving_Object::spawn_death_obj(void) {
    RGE_Static_Object* obj = RGE_Static_Object::spawn_death_obj();
    if (obj != 0 && obj->master_obj->master_type >= 0x1E) {
        obj->new_angle(this->angle);
    }
    return obj;
}

void RGE_Moving_Object::transform(RGE_Master_Static_Object* master) {
    this->RGE_Animated_Object::transform(master);
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->collisionAvoidanceDistance = 0.0f;
    this->turnTimer = 0.0f;
    this->turn_towards_time = 0.0f;
    this->set_angle();
}

unsigned char RGE_Moving_Object::is_moving() {
    if (this->speed > 0.0f) {
        return 1;
    }
    return 0;
}

void RGE_Moving_Object::stop_moving() { this->speed = 0; }



float RGE_Moving_Object::angle_to_object(RGE_Static_Object* target, float tx, float ty)
{
    RGE_Sprite* g = this->sprite;
    if (g != 0 && (g->flags & 2) != 0 && g->facet_num > 0) {
        float ax;
        float ay;
        if (target) {
            ay = target->world_y;
            ax = target->world_x;
        } else {
            ay = ty;
            ax = tx;
        }

        float a = (float)atan2((double)(ay - world_y), (double)(ax - world_x));
        if (a < DAT_00570b48)
            a -= DAT_00570b4c;
        a -= angle;
        if (a > DAT_00570b68)
            a -= DAT_00570b50;
        if (a < DAT_00570b70)
            a -= DAT_00570b4c;

        return ((float)g->facet_num * DAT_00570b78) * a;
    }
    return DAT_00570b48;
}

// move_obj.cpp lines 475-505
//   angle field; packet evidence proves a virtual unsigned-char method taking
//   RGE_Static_Object*, float, float and returning the post-turn tolerance.
//   turn_speed, sprite->facet_num, angle/turn_towards_time, direct
//   topology through a natural angle local.

unsigned char RGE_Moving_Object::turn_towards(RGE_Static_Object* object,
                                               float x, float y) {
    float turnTime;
    float angle = this->angle_to_object(object, x, y);
    if (angle <= 0.5f) {
        if (angle >= -0.5f) {
            return 1;
        }
    }

    turnTime = (float)this->owner->world->world_time * DAT_00570b84;
    if (turnTime - this->turn_towards_time <
        ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed) {
        return 0;
    }

    if (angle < 0.0f) {
        this->angle -=
            (float)(DAT_00570b40 / (float)(int)this->sprite->facet_num);
    } else {
        this->angle +=
            (float)(DAT_00570b40 / (float)(int)this->sprite->facet_num);
    }

    if (this->angle < 0.0f) {
        this->angle = this->angle - DAT_00570b4c;
    } else if (this->angle > DAT_00570b50) {
        this->angle = this->angle - DAT_00570b50;
    }

    this->set_angle();
    this->turn_towards_time = turnTime;

    angle = this->angle_to_object(object, x, y);
    if (angle <= 0.5f) {
        if (angle >= -0.5f) {
            return 1;
        }
    }
    return 0;
}

void RGE_Moving_Object::set_angle() {
    RGE_Sprite* sprite = this->sprite;
    if (sprite == 0 || (sprite->flags & 2) == 0 || sprite->facet_num <= 0) {
        this->facet = 0;
        return;
    }

    float temp = this->angle - DAT_00570b88;
    int facet_num = sprite->facet_num;
    temp = temp * (float)facet_num;
    temp = temp * DAT_00570b78;
    temp = temp - DAT_00570b80;
    if (temp < DAT_00570b48) {
        temp = temp + (float)facet_num;
    }
    this->facet = (unsigned char)((int)temp);
}



float RGE_Moving_Object::teleport(float x, float y, float z) {
    if (((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_options != 0 &&
        this->tile != 0) {
        RGE_Master_Static_Object* trail_master =
            this->owner->master_objects[
                ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_id];

        if (trail_master != 0) {
            switch (((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_options) {
            case 1: {
                RGE_Static_Object* trail =
                    trail_master->make_new_obj(this->owner, x, y, z);
                if (trail->master_obj->id > 30) {
                    trail->new_angle(this->angle);
                }
                break;
            }

            case 2: {
                float dz;
                float tx;
                float ty;
                float tz;
                float distance;
                float dx;
                float dy;
                // The original adds trail_remainder to distance
                // at 0045D458, then adds it again in the count <= 0 branch at
                dx = x - this->world_x;
                dy = y - this->world_y;
                dz = z - this->world_z;
                distance =
                    (float)sqrt(dx * dx + dy * dy + dz * dz) +
                    this->trail_remainder;
                short count =
                    (short)(distance /
                            ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_spacing);

                if (count > 0) {
                    dx /= (float)count;
                    dy /= (float)count;
                    dz /= (float)count;
                    tx = this->world_x;
                    ty = this->world_y;
                    tz = this->world_z;
                    if (0 < count) {
                        int loop_count = count;
                        do {
                            RGE_Static_Object* trail =
                                trail_master->make_new_obj(
                                    this->owner, tx, ty, tz);
                            if (trail->master_obj->id > 30) {
                                trail->new_angle(this->angle);
                            }
                            tx += dx;
                            ty += dy;
                            tz += dz;
                        } while (--loop_count != 0);
                    }

                    this->trail_remainder =
                        distance -
                        ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_spacing *
                            (float)count;
                } else {
                    this->trail_remainder = distance + this->trail_remainder;
                }
                break;
            }
            }
        }
    }

    return RGE_Static_Object::teleport(x, y, z);
}

void RGE_Moving_Object::set_velocity(float a, float b, float c) {
    this->velocity_x = a;
    this->velocity_y = b;
    this->velocity_z = c;
}

// other_method declaration produced the wrong direct symbol. A direct float
// assignment preserves the executable's bit-copy store without a pointer cast.
void RGE_Moving_Object::new_angle(float param_1) {
    this->angle = param_1;
    this->set_angle();
}

const Path& RGE_Moving_Object::getPath() const { return this->pathValue; }

unsigned char RGE_Moving_Object::facetToNextWaypoint() const {
    Waypoint* waypoint;

    waypoint = this->pathValue.currentWaypoint();
    if (waypoint != 0) {
        waypoint = this->pathValue.currentWaypoint();
        return waypoint->facetToNextWaypoint;
    }
    return 0xFF;
}

void RGE_Moving_Object::setGoal(float a, float b, float c) {
    this->goalValue.x = a;
    this->goalValue.y = b;
    this->goalValue.z = c;
}

void RGE_Moving_Object::setActionRange(float v) { this->actionRange = v; }

void RGE_Moving_Object::setTargetID(int v) { this->targetIDValue = v; }

void RGE_Moving_Object::setTargetRadius(float a, float b) {
    this->targetRadiusX = a;
    this->targetRadiusY = b;
}



RGE_Moving_Object::PathResult RGE_Moving_Object::findPath()
{
    if (this->master_obj->radius_z <= 0.0f) {
        this->setWaitingToMove(0);
        this->setStart(this->world_x, this->world_y, this->world_z);
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

    // the executable keeps this constant guard and its unreachable cleanup arm.
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
            // natural casts keep __ftol input on x87 ST0.
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
        fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                this->owner->world->world_time, this->id,
                this->startValue.x, this->startValue.y,
                this->goalValue.x, this->goalValue.y);
        this->pathValue.initToStart();
        int i = 0;
        while (i < this->pathValue.numberOfWaypoints()) {
            fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i,
                    this->pathValue.currentWaypoint()->x,
                    this->pathValue.currentWaypoint()->y);
            i++;
            this->pathValue.moveToNextWaypoint();
        }
        fprintf(actionFile, ".\n");
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
    }

    if (!found && this->pathValue.numberOfWaypoints() == 1) {
        // cast each floor result before subtracting the float tile bias.
        if (pathSystem.passable(this,
                                (float)floor((double)this->world_x) - DAT_00570b80,
                                (float)floor((double)this->world_y) - DAT_00570b80, 1)) {
            if ((this->world_x - floor((double)this->world_x)) != 0.5 ||
                (this->world_y - floor((double)this->world_y)) != 0.5) {
                this->teleport(
                    (float)floor((double)this->world_x) - DAT_00570b80,
                    (float)floor((double)this->world_y) - DAT_00570b80, this->world_z);
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



int RGE_Moving_Object::doMove() {
    Path* path;
    Waypoint* waypoint;
    int path_result;
    float distance;
    float dY;
    float newDY;

    this->setWaitingToMove(0);

    distance = this->goalValue.x - this->world_x;
    dY = this->goalValue.y - this->world_y;
    if (distance < DAT_00570b48) {
        distance = -distance;
    }
    if (dY < DAT_00570b48) {
        dY = -dY;
    }

    distance = distance - (this->targetRadiusX + this->master_obj->radius_x);
    dY = dY - (this->master_obj->radius_y + this->targetRadiusY);
    if (distance < DAT_00570b48) {
        distance = 0.0f;
    }
    if (dY < DAT_00570b48) {
        dY = 0.0f;
    }

    distance = (float)sqrt(distance * distance + dY * dY);
    if (this->actionRange > DAT_00570b98 && distance <= this->actionRange) {
        this->speed = 0.0f;
        this->rangeStatusValue = 1;
        this->removeAllUserDefinedWaypoints(0);
        this->pathingGroupMembers.numberValue = 0;
        return 2;
    }

    if (distance < DAT_00570b90) {
        path = &this->pathValue;
        newDY = distance;
        if (path->currentWaypoint() != 0) {
            waypoint = path->currentWaypoint();
            newDY = waypoint->x - this->world_x;
            waypoint = path->currentWaypoint();
            dY = waypoint->y - this->world_y;
            newDY = (float)sqrt(dY * dY + newDY * newDY);
        }
        if (newDY == DAT_00570b48) {
            this->pathingGroupMembers.numberValue = 0;
            return 2;
        }

        int result = this->doTrivialMove(this->goalValue.x, this->goalValue.y);
        if (result == 5) {
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->pathingGroupMembers.numberValue = 0;
            return 2;
        }
        if (result != 0) {
            if (result == 1 || result == 6) {
                this->speed = 0.0f;
                this->rangeStatusValue = 2;
                return 1;
            }
            if (result == 2 || result == 3 || result == 4) {
                this->speed = 0.0f;
                this->rangeStatusValue = 1;
                this->removeAllUserDefinedWaypoints(0);
                this->pathingGroupMembers.numberValue = 0;
                return 2;
            }
        } else {
            this->rangeStatusValue = 2;
            return 1;
        }
    }

    path = &this->pathValue;
    path_result = 1;
    newDY = (float)sqrt(this->master_obj->radius_x * this->master_obj->radius_x +
                        this->master_obj->radius_y * this->master_obj->radius_y);
    waypoint = path->currentWaypoint();
    if (waypoint != 0) {
        waypoint = path->currentWaypoint();
        float dx = waypoint->x - this->world_x;
        waypoint = path->currentWaypoint();
        float dy = waypoint->y - this->world_y;
        if ((float)sqrt(dy * dy + dx * dx) == DAT_00570b48) {
            waypoint = path->currentWaypoint();
            float y = waypoint->y;
            waypoint = path->currentWaypoint();
            if (pathSystem.passable(this, waypoint->x, y, path_result) != 0) {
                this->teleport(path->currentWaypoint()->x,
                               path->currentWaypoint()->y,
                               path->currentWaypoint()->z);
            }
            path_result = path->moveToNextWaypoint();
            this->closestDistanceToWaypoint = 100000.0f;
        }
    } else {
        path_result = 0;
    }

    float distanceToGoal = 0.0f;
    if (this->numberUserDefinedWaypointsValue > 1 && distance > DAT_00570ba0) {
        unsigned char zone1 = this->lookupZone(this->userDefinedWaypoints[0].x,
                                               this->userDefinedWaypoints[0].y);
        unsigned char zone2 = this->lookupZone(this->userDefinedWaypoints[1].x,
                                               this->userDefinedWaypoints[1].y);
        if (zone1 == zone2) {
            distanceToGoal = 3.0f;
        }
    }

    if (path_result == 0) {
        if (distance <= distanceToGoal + newDY + this->actionRange) {
            this->speed = 0.0f;
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->pathingGroupMembers.numberValue = 0;
            return 2;
        }
        int retry_success = 0;
        while (retry_success == 0) {
            this->removeUserDefinedWaypoint(0);
            if (this->numberUserDefinedWaypointsValue < 1) {
                return 0;
            }
            float retry_dx = (float)this->userDefinedWaypoints[0].x - this->world_x;
            float retry_dy = (float)this->userDefinedWaypoints[0].y - this->world_y;
            if (newDY + this->actionRange - DAT_00570ba8 <
                (float)sqrt(retry_dy * retry_dy + retry_dx * retry_dx)) {
                retry_success = 1;
            }
        }

        int old_continue = this->continueCounter;
        int next_continue = old_continue - 1;
        this->continueCounter = next_continue;
        if (next_continue < 1) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue > 1) {
                this->continueCounter = old_continue + 4;
                return 1;
            }
            return 0;
        }

        if (this->owner->availablePathingAttempts(this->numberWaitDelays) == 0) {
            this->speed = 0.0f;
            this->numberWaitDelays++;
            return 1;
        }
        this->owner->incrementPathingAttempts();
        this->startValue.x = this->world_x;
        this->startValue.y = this->world_y;
        this->startValue.z = this->world_z;
        this->numberWaitDelays = 0;
        pathSystem.incrementContinuePaths();

        int found;
        if (this->numberUserDefinedWaypointsValue < 1) {
            found = pathSystem.findTilePath((int)this->startValue.x,
                                            (int)this->startValue.y,
                                            (int)this->goalValue.x,
                                            (int)this->goalValue.y,
                                            this, this->actionRange, this->targetIDValue,
                                            1, (float*)0, 1, 1, 1, 1, -1, -1);
        } else {
            found = pathSystem.findTilePath((int)this->startValue.x,
                                            (int)this->startValue.y,
                                            this->userDefinedWaypoints[0].x,
                                            this->userDefinedWaypoints[0].y,
                                            this, this->actionRange, this->targetIDValue,
                                            1, (float*)0, 1, 1, 1, 1, -1, -1);
        }
        this->pathingGroupMembers.numberValue = 0;

        if (actionFile != 0) {
            fprintf(actionFile,
                    "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                    this->owner->world->world_time, this->id,
                    this->startValue.x, this->startValue.y,
                    this->goalValue.x, this->goalValue.y);
            path->initToStart();
            int i = 0;
            int n = path->numberOfWaypoints();
            if (n > 0) {
                do {
                    fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i,
                            path->currentWaypoint()->x,
                            path->currentWaypoint()->y);
                    i++;
                    path->moveToNextWaypoint();
                    n = path->numberOfWaypoints();
                } while (i < n);
            }
            fprintf(actionFile, ".\n");
            path->initToStart();
            path->moveToNextWaypoint();
        }

        if (found == 0 && path->numberOfWaypoints() == 1) {
            if (pathSystem.passable(this,
                                    (float)(floor((double)this->world_x) - DAT_00570b80),
                                    (float)(floor((double)this->world_y) - DAT_00570b80),
                                    1) == 0 ||
                (this->world_x - (float)floor((double)this->world_x) == DAT_00570b90 &&
                 this->world_y - (float)floor((double)this->world_y) == DAT_00570b90)) {
                this->speed = 0.0f;
                this->rangeStatusValue = 2;
                if (this->numberUserDefinedWaypointsValue > 1) {
                    this->continueCounter += 5;
                    return 1;
                }
                return 0;
            } else {
                this->teleport(
                    (float)(floor((double)this->world_x) - DAT_00570b80),
                    (float)(floor((double)this->world_y) - DAT_00570b80),
                    this->world_z);
            }
        }

        int display_object_id = displayPathObjectID;
        if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
            path->initToStart();
            int i = 0;
            int n = path->numberOfWaypoints();
            while (i < n) {
                    this->owner->master_objects[display_object_id]->make_new_obj(
                        this->owner, path->currentWaypoint()->x,
                        path->currentWaypoint()->y, 1.0f);
                ++i;
                path->moveToNextWaypoint();
                n = path->numberOfWaypoints();
            }
            path->initToStart();
            path->moveToNextWaypoint();
        }

        path->initToStart();
        path_result = path->moveToNextWaypoint();
        if (path_result == 0) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue > 1) {
                this->continueCounter += 5;
                return 1;
            }
            return 0;
        }
        this->closestDistanceToWaypoint = 100000.0f;
    }

    waypoint = path->currentWaypoint();
    if (waypoint != 0) {
        int result = this->doTrivialMove(path->currentWaypoint()->x,
                                         path->currentWaypoint()->y);
        if (result == 5) {
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->pathingGroupMembers.numberValue = 0;
            return 2;
        }
        if (result == 0) {
            this->rangeStatusValue = 2;
            return 1;
        }
        if (result == 1) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            return 1;
        }
        if (result == 2) {
            if (path->moveToNextWaypoint() != 0) {
                this->rangeStatusValue = 2;
                return 1;
            }

            int retry_success = 0;
            while (retry_success == 0) {
                this->removeUserDefinedWaypoint(0);
                if (this->numberUserDefinedWaypointsValue < 1) {
                    return 0;
                }
                float retry_dx = (float)this->userDefinedWaypoints[0].x - this->world_x;
                float retry_dy = (float)this->userDefinedWaypoints[0].y - this->world_y;
                if (newDY + this->actionRange - DAT_00570ba8 <
                    (float)sqrt(retry_dy * retry_dy + retry_dx * retry_dx)) {
                    retry_success = 1;
                }
            }

            if (this->owner->availablePathingAttempts(this->numberWaitDelays) == 0) {
                this->speed = 0.0f;
                this->numberWaitDelays++;
                return 1;
            }
            this->owner->incrementPathingAttempts();
            this->startValue.x = this->world_x;
            this->startValue.y = this->world_y;
            this->startValue.z = this->world_z;
            this->numberWaitDelays = 0;
            pathSystem.incrementContinuePaths();

            int found;
            if (this->numberUserDefinedWaypointsValue < 1) {
                found = pathSystem.findTilePath((int)this->startValue.x,
                                                (int)this->startValue.y,
                                                (int)this->goalValue.x,
                                                (int)this->goalValue.y,
                                                this, this->actionRange, this->targetIDValue,
                                                1, (float*)0, 1, 1, 1, 1, -1, -1);
            } else {
                found = pathSystem.findTilePath((int)this->startValue.x,
                                                (int)this->startValue.y,
                                                this->userDefinedWaypoints[0].x,
                                                this->userDefinedWaypoints[0].y,
                                                this, this->actionRange, this->targetIDValue,
                                                1, (float*)0, 1, 1, 1, 1, -1, -1);
            }
            this->pathingGroupMembers.numberValue = 0;

            if (actionFile != 0) {
                fprintf(actionFile,
                        "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                        this->owner->world->world_time, this->id,
                        this->startValue.x, this->startValue.y,
                        this->goalValue.x, this->goalValue.y);
                path->initToStart();
                int i = 0;
                int n = path->numberOfWaypoints();
                if (n > 0) {
                    do {
                        fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i,
                                path->currentWaypoint()->x,
                                path->currentWaypoint()->y);
                        i++;
                        path->moveToNextWaypoint();
                        n = path->numberOfWaypoints();
                    } while (i < n);
                }
                fprintf(actionFile, ".\n");
                path->initToStart();
                path->moveToNextWaypoint();
            }

            if (found == 0 && path->numberOfWaypoints() == 1) {
                if (pathSystem.passable(this,
                                        (float)(floor((double)this->world_x) - DAT_00570b80),
                                        (float)(floor((double)this->world_y) - DAT_00570b80),
                                        1)) {
                    if (this->world_x - (float)floor((double)this->world_x) == DAT_00570b90 &&
                        this->world_y - (float)floor((double)this->world_y) == DAT_00570b90) {
                        this->speed = 0.0f;
                        this->rangeStatusValue = 2;
                        if (this->numberUserDefinedWaypointsValue > 1) {
                            this->continueCounter += 5;
                            return 1;
                        }
                        return 0;
                    }
                    this->teleport(
                        (float)(floor((double)this->world_x) - DAT_00570b80),
                        (float)(floor((double)this->world_y) - DAT_00570b80),
                        this->world_z);
                }
            }

            int display_object_id = displayPathObjectID;
            if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
                path->initToStart();
                int i = 0;
                int n = path->numberOfWaypoints();
                while (i < n) {
                    this->owner->master_objects[display_object_id]->make_new_obj(
                        this->owner, path->currentWaypoint()->x,
                        path->currentWaypoint()->y, 1.0f);
                    ++i;
                    path->moveToNextWaypoint();
                    n = path->numberOfWaypoints();
                }
                path->initToStart();
                path->moveToNextWaypoint();
            }

            path->initToStart();
            path_result = path->moveToNextWaypoint();
            if (path_result == 0) {
                this->speed = 0.0f;
                this->rangeStatusValue = 2;
                if (this->numberUserDefinedWaypointsValue > 1) {
                    this->continueCounter += 5;
                    return 1;
                }
                return 0;
            }
            this->closestDistanceToWaypoint = 100000.0f;
        }
    }

    this->rangeStatusValue = 2;
    return 1;
}



int RGE_Moving_Object::doTrivialMove(float x, float y)
{
    int numberFacets;
    float targetDY;
    float dX;
    float newAngle;
    float distanceToCover;
    float newX;
    float newY;
    float curDistance;
    int alreadyMoving;
    float dY;
    float angleDelta;
    int i;
    int found;
    int passable;

    alreadyMoving = 1;

    if (this->speed == DAT_00570b98) {
        RGE_Sprite* sprite = this->sprite;
        alreadyMoving = 0;
        if (sprite == 0 || sprite->base_speed <= DAT_00570b98) {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed;
        } else {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed * sprite->base_speed;
        }
    }

    newAngle = this->owner->world->world_time_delta_seconds * this->speed;

    if (this->collisionAvoidanceDistance > DAT_00570b98) {
        this->collisionAvoidanceDistance = this->collisionAvoidanceDistance - newAngle;
        if (this->collisionAvoidanceDistance > DAT_00570b98) {
            this->speed = 0.0f;
            return 0;
        }
        this->collisionAvoidanceDistance = -1.0f;
    }

    if (((RGE_Master_Moving_Object*)this->master_obj)->turn_speed > DAT_00570b98) {
        if (this->turnTimer < DAT_00570b98) {
            this->turnTimer = 0.0f;
        } else {
            this->turnTimer = this->turnTimer - this->owner->world->world_time_delta_seconds;
        }
    }

    if (this->sprite != 0) {
        numberFacets = (int)this->sprite->facet_num;
    } else {
        numberFacets = 8;
    }

    if (alreadyMoving == 1) {
        dX = x - this->world_x;
        dY = y - this->world_y;
    } else {
        dX = x - ((float)floor((double)this->world_x) - DAT_00570b80);
        dY = y - ((float)floor((double)this->world_y) - DAT_00570b80);
    }

    targetDY = (float)atan2((double)dY, (double)dX);
    this->boundAngle(&targetDY, -1);

    angleDelta = targetDY - this->angle;
    while (angleDelta < DAT_00570b70) {
        angleDelta = angleDelta - DAT_00570b4c;
    }
    while (angleDelta > DAT_00570b68) {
        angleDelta = angleDelta - DAT_00570b50;
    }

    float facetDelta = (float)(angleDelta * numberFacets) * DAT_00570b78;
    this->boundAngle(&this->angle, numberFacets);

    while (this->turnTimer <= DAT_00570b48 &&
           (facetDelta > DAT_00570bb0 || facetDelta < DAT_00570bb8)) {
        this->turnTimer = ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed + this->turnTimer;
        if (angleDelta >= DAT_00570b48) {
            facetDelta = facetDelta - DAT_00570b64;
            this->angle = DAT_00570b40 / (float)numberFacets + this->angle;
        } else {
            facetDelta = facetDelta - DAT_00570b60;
            this->angle = this->angle - DAT_00570b40 / (float)numberFacets;
        }
    }

    this->boundAngle(&this->angle, numberFacets);
    this->set_angle();

    this->velocity_x = (float)cos((double)this->angle) * newAngle;
    this->velocity_y = (float)sin((double)this->angle) * newAngle;
    distanceToCover = this->velocity_y;
    newX = this->world_x + this->velocity_x;
    newY = this->world_y + distanceToCover;

    passable = 1;
    if (((RGE_Master_Static_Object*)this->master_obj)->radius_z > DAT_00570b48) {
        passable = pathSystem.passable(this, newX, newY, 1);
    }

    if (passable == 0) {
        if (this->collisionAvoidanceDistance == DAT_00570b48) {
            if (this->speed <= DAT_00570b48) {
                this->speed = 0.0f;
                this->collisionAvoidanceDistance =
                    (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x6D1) % 6) * DAT_00570bc0 - DAT_00570b80;
                return 0;
            }
                this->collisionAvoidanceDistance =
                (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x6CF) % 6) * DAT_00570bc0 - DAT_00570b80 / this->speed;
                this->speed = 0.0f;
            return 0;
        }

        passable = 1;
        this->collisionAvoidanceDistance = 0.0f;
        newX = (float)floor((double)this->world_x) - DAT_00570b80;
        newY = (float)floor((double)this->world_y) - DAT_00570b80;
        passable = pathSystem.passable(this, newX, newY, passable);
        if (passable != 0) {
            this->teleport((float)floor((double)this->world_x) - DAT_00570b80,
                           (float)floor((double)this->world_y) - DAT_00570b80,
                           this->world_z);
        }
    }

    if (this->targetIDValue != -1) {
        RGE_Game_World* world = this->owner->world;
        RGE_Static_Object* target = world->object(this->targetIDValue);
        if (target != 0) {
            RGE_Master_Static_Object* master =
                (RGE_Master_Static_Object*)this->master_obj;
            float targetDX = target->world_x - this->world_x;
            float targetDY2 = target->world_y - this->world_y;
            float targetDistance =
                (float)sqrt(targetDY2 * targetDY2 + targetDX * targetDX);
            if (targetDistance <
                (float)sqrt(master->radius_y * master->radius_y +
                            master->radius_x * master->radius_x) +
                this->actionRange - DAT_00570ba8) {
                return 5;
            }
        }
    }

    passable = pathSystem.passable(this, x, y, 1);
    if (passable == 0) {
        return 2;
    }

    --this->continueCounter;
    if (this->continueCounter < 1) {
        return 4;
    }

    if (this->owner->availablePathingAttempts(this->numberWaitDelays) == 0) {
        ++this->numberWaitDelays;
        return 1;
    }

    this->owner->incrementPathingAttempts();
    this->startValue.x = this->world_x;
    this->startValue.y = this->world_y;
    this->startValue.z = this->world_z;
    this->numberWaitDelays = 0;
    pathSystem.incrementContinuePaths();

    if (this->numberUserDefinedWaypointsValue > 0) {
        found = pathSystem.findTilePath((int)this->startValue.x,
                                         (int)this->startValue.y,
                                         this->userDefinedWaypoints->x,
                                         this->userDefinedWaypoints->y,
                                         this, this->actionRange, this->targetIDValue,
                                         1, (float*)0, 1, 1, 1, 1, -1, -1);
    } else {
        found = pathSystem.findTilePath((int)this->startValue.x,
                                         (int)this->startValue.y,
                                         (int)this->goalValue.x,
                                         (int)this->goalValue.y,
                                         this, this->actionRange, this->targetIDValue,
                                         1, (float*)0, 1, 1, 1, 1, -1, -1);
    }

    if (actionFile != 0) {
        fprintf(actionFile,
                "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                this->owner->world->world_time, this->id,
                this->startValue.x, this->startValue.y,
                this->goalValue.x, this->goalValue.y);

        Path* path = &this->pathValue;
        path->initToStart();
        i = 0;
        while (i < path->numberOfWaypoints()) {
            float waypointY = path->currentWaypoint()->y;
            float waypointX = path->currentWaypoint()->x;
            fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i,
                    waypointX, waypointY);
            ++i;
            path->moveToNextWaypoint();
        }
        fprintf(actionFile, ".\n");
        path->initToStart();
        path->moveToNextWaypoint();
    }

    Path* path = &this->pathValue;
    if (found == 0 && path->numberOfWaypoints() == 1) {
        dX = (float)floor((double)this->world_x) - DAT_00570b80;
        newY = (float)floor((double)this->world_y) - DAT_00570b80;
        if (pathSystem.passable(this, dX, newY, 1)) {
            if (this->world_x - (float)floor((double)this->world_x) == DAT_00570b90 &&
                this->world_y - (float)floor((double)this->world_y) == DAT_00570b90) {
                return 4;
            }
            this->teleport((float)floor((double)this->world_x) - DAT_00570b80,
                           (float)floor((double)this->world_y) - DAT_00570b80,
                           this->world_z);
        }
    }

    int displayObjectID = displayPathObjectID;
    if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
        path->initToStart();
        i = 0;
        while (i < path->numberOfWaypoints()) {
            RGE_Master_Static_Object* master =
                this->owner->master_objects[displayObjectID];
            float waypointY = path->currentWaypoint()->y;
            float waypointX = path->currentWaypoint()->x;
            master->make_new_obj(this->owner, waypointX, waypointY, 1.0f);
            ++i;
            path->moveToNextWaypoint();
        }
        path->initToStart();
        path->moveToNextWaypoint();
    }

    path->initToStart();
    if (path->moveToNextWaypoint() == 0) {
        return 4;
    }

    this->closestDistanceToWaypoint = 100000.0f;

    if (alreadyMoving == 1) {
        dX = path->currentWaypoint()->x - this->world_x;
        dY = path->currentWaypoint()->y - this->world_y;
    } else {
        dX = path->currentWaypoint()->x - ((float)floor((double)this->world_x) - DAT_00570b80);
        dY = path->currentWaypoint()->y - ((float)floor((double)this->world_y) - DAT_00570b80);
    }

    targetDY = (float)atan2((double)dY, (double)dX);
    this->boundAngle(&targetDY, -1);
    angleDelta = targetDY - this->angle;
    facetDelta = (float)(angleDelta * numberFacets) * DAT_00570b78;

    if (this->turnTimer > DAT_00570b48) {
        this->speed = 0.0f;
        return 0;
    }

    do {
        if (facetDelta <= DAT_00570bc8 && facetDelta >= DAT_00570bd0) {
            break;
        }
        this->turnTimer = ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed + this->turnTimer;
        if (angleDelta >= DAT_00570b48) {
            facetDelta = facetDelta - DAT_00570b64;
            this->angle = DAT_00570b40 / (float)numberFacets + this->angle;
        } else {
            facetDelta = facetDelta - DAT_00570b60;
            this->angle = this->angle - DAT_00570b40 / (float)numberFacets;
        }
    } while (this->turnTimer <= DAT_00570b48);

    this->boundAngle(&this->angle, numberFacets);
    this->set_angle();

    this->velocity_y = (float)sin((double)this->angle) * newAngle;
    this->velocity_x = (float)cos((double)this->angle) * newAngle;
    distanceToCover = this->velocity_y;
    newX = this->world_x + this->velocity_x;
    newY = this->world_y + distanceToCover;

    passable = 1;
    if (((RGE_Master_Static_Object*)this->master_obj)->radius_z > DAT_00570b48) {
        passable = pathSystem.passable(this, newX, newY, 1);
    }
    if (passable == 0) {
        if (this->owner->computerPlayer() == 1) {
            return 4;
        }
        if (this->speed <= DAT_00570b48) {
            this->collisionAvoidanceDistance =
                (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x7D5) % 6) * DAT_00570bc0 - DAT_00570b80;
            this->speed = 0.0f;
        } else {
            this->collisionAvoidanceDistance =
                (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x7D3) % 6) * DAT_00570bc0 - DAT_00570b80 / this->speed;
            this->speed = 0.0f;
        }
        return 0;
    }

    // The waypoint-snap branch above jumps to moved without
    // initializing destinationZ. The original tail at 0045F704 reads this
    // stale stack value for deltaZ and speedMultiplier. Preserve that read.
    float destinationZ;
    Waypoint* waypoint = path->currentWaypoint();
    if (waypoint == 0) {
        float dx = x - newX;
        float dy = y - newY;
        curDistance = (float)sqrt(dy * dy + dx * dx);
        destinationZ = this->world_z + this->velocity_z;
    } else {
        float dx = path->currentWaypoint()->x - this->world_x;
        float dy = path->currentWaypoint()->y - this->world_y;
        curDistance = (float)sqrt(dy * dy + dx * dx);

        dx = path->currentWaypoint()->x - (this->world_x + this->velocity_x);
        dy = path->currentWaypoint()->y - (this->world_y + this->velocity_y);
        float nextDistance =
            (float)sqrt(dy * dy + (double)dx * (double)dx);

        if ((this->closestDistanceToWaypoint < nextDistance && curDistance < 0.25f) ||
            (this->lastFacet2 == this->facet && this->lastFacet2 != this->lastFacet &&
             curDistance < 0.5f)) {
            int ok = 1;
            waypoint = path->currentWaypoint();
            float waypointY = waypoint->y;
            waypoint = path->currentWaypoint();
            ok = pathSystem.passable(this, waypoint->x, waypointY, ok);
            if (ok == 0) {
                return 2;
            }

            this->teleport(path->currentWaypoint()->x,
                           path->currentWaypoint()->y,
                           path->currentWaypoint()->z);
            goto moved;
        }
        destinationZ = this->world_z + this->velocity_z;
    }

    this->teleport(newX, newY, destinationZ);

moved:
    float deltaZ = destinationZ - this->world_z;
    float speedMultiplier = 1.0f;
    this->lastFacet2 = this->lastFacet;
    this->lastFacet = this->facet;
    this->closestDistanceToWaypoint = curDistance;

    if (deltaZ < DAT_00570be0) {
        speedMultiplier = 0.9f;
    } else if (deltaZ > DAT_00570bf0) {
        speedMultiplier = 1.03f;
    } else {
        if (this->sprite == 0 || this->sprite->base_speed <= DAT_00570b98) {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed;
        } else {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed * this->sprite->base_speed;
        }
    }

    if (this->tile != 0) {
        speedMultiplier = this->get_terrain_speed((unsigned char)(this->tile->terrain_type & 0x1F)) * speedMultiplier;
    }
    if (speedMultiplier > DAT_00570b48) {
        this->speed = speedMultiplier * this->speed;
    }
    return 0;
}

// Qualified owner: RGE_Moving_Object::passableTile in move_obj.cpp.
// selects the pathing receiver; the helper gets this, x, y, and literal 1.


int RGE_Moving_Object::passableTile(float x, float y, int mode) {
    if (mode != 0) {
        return aiPathSystem.passable(this, x, y, 1);
    }
    return pathSystem.passable(this, x, y, 1);
}



int RGE_Moving_Object::canPath(XYZPoint point, float tolerance, int targetID,
                               float* costOut, int useAI, int unobPlayerID,
                               int unobGroupID) {
    if (point.x < 0 || point.y < 0) {
        return 0;
    }

    RGE_Map* map = this->owner->world->map;
    if (point.x < map->map_width && point.y < map->map_height) {
            if (this->zoneMapIndex == -1) {
                this->owner->world->map->map_zones->get_zone_map(
                    this->owner->world->terrains[this->master_obj->terrain],
                    this->owner->world->terrain_size, this->zoneMapIndex);
            }

            RGE_Zone_Map* zone_map =
                this->owner->world->map->map_zones->get_zone_map(
                    this->zoneMapIndex);
            if (zone_map != 0) {
                int start_zone = zone_map->get_zone_info(
                    (long)this->world_x, (long)this->world_y);
                int goal_zone = zone_map->get_zone_info(point.x, point.y);
                if (goal_zone != start_zone) {
                    XYPoint start;
                    start.x = (int)this->world_x;
                    start.y = (int)this->world_y;

                    XYPoint goal;
                    goal.x = point.x;
                    goal.y = point.y;

                    if (zone_map->withinRange(start, goal, tolerance) == 0) {
                        return 0;
                    }
                }

                if (useAI != 0) {
                    aiPathSystem.incrementCanPaths();
                    return aiPathSystem.findTilePath(
                        (int)this->world_x, (int)this->world_y, point.x,
                        point.y, this, tolerance, targetID, 0, costOut, 1,
                        1, 1, 1, unobPlayerID, unobGroupID);
                }

                pathSystem.incrementCanPaths();
                return pathSystem.findTilePath(
                    (int)this->world_x, (int)this->world_y, point.x, point.y,
                    this, tolerance, targetID, 0, costOut, 1, 1, 1, 1,
                    unobPlayerID, unobGroupID);
            }
        }

    return 0;
}



int RGE_Moving_Object::canPath(int targetID, float tolerance, float* costOut,
                               int useAI, int unobPlayerID, int unobGroupID) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(
            this->owner->world->terrains[this->master_obj->terrain],
            this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zone_map == 0) {
        return 0;
    }

    int start_zone = zone_map->get_zone_info(
        (long)this->world_x, (long)this->world_y);
    int goal_zone = zone_map->get_zone_info(
        (long)target->world_x, (long)target->world_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = (int)target->world_x;
        goal.y = (int)target->world_y;

        if (zone_map->withinRange(start, goal, tolerance) == 0) {
            return 0;
        }
    }

    if (useAI != 0) {
        aiPathSystem.incrementCanPaths();
        return aiPathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)target->world_x, (int)target->world_y, this,
            tolerance, targetID, 0, costOut, 1, 1, 1, 1,
            unobPlayerID, unobGroupID);
    }

    pathSystem.incrementCanPaths();
    return pathSystem.findTilePath(
        (int)this->world_x, (int)this->world_y,
        (int)target->world_x, (int)target->world_y, this,
        tolerance, targetID, 0, costOut, 1, 1, 1, 1,
        unobPlayerID, unobGroupID);
}



int RGE_Moving_Object::canBidirectionPath(
    int sourceID, int goalID, float tolerance, float* costOut, int useAI,
    int unobPlayerID, int unobGroupID) {
    RGE_Static_Object* source;
    RGE_Static_Object* goal;
    RGE_Zone_Map* zone_map;
    int start_zone;
    int goal_zone;
    XYPoint start;
    XYPoint goal_point;

    source = this->owner->world->object(sourceID);
    goal = this->owner->world->object(goalID);
    if (source == 0 || goal == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(
            this->owner->world->terrains[this->master_obj->terrain],
            this->owner->world->terrain_size, this->zoneMapIndex);
    }

    zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zone_map == 0) {
        return 0;
    }

    start_zone = zone_map->get_zone_info(
        (long)this->world_x, (long)this->world_y);
    goal_zone = zone_map->get_zone_info(
        (long)source->world_x, (long)source->world_y);

    if (goal_zone != start_zone) {
        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal_point.x = (int)source->world_x;
        goal_point.y = (int)source->world_y;

        if (zone_map->withinRange(start, goal_point, tolerance) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    if (useAI != 0) {
        aiPathSystem.incrementCanPaths();
        int result = aiPathSystem.findTilePath(
                (int)this->world_x, (int)this->world_y,
                (int)source->world_x, (int)source->world_y, this, tolerance,
                sourceID, 1, costOut, 1, 1, 1, 1, unobPlayerID,
                unobGroupID);
        if (result == 0) {
            this->storePathInExceptionPath = (unsigned char)result;
            return result;
        }

        result = aiPathSystem.findTilePath(
            (int)this->exceptionPathValue.lastWaypoint()->x,
            (int)this->exceptionPathValue.lastWaypoint()->y,
            (int)goal->world_x, (int)goal->world_y, this, tolerance, goalID, 0,
            costOut, 1, 1, 1, 1, unobPlayerID, unobGroupID);
        this->storePathInExceptionPath = 0;
        return result;
    }

    pathSystem.incrementCanPaths();
    int result = pathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)source->world_x, (int)source->world_y, this, tolerance,
            sourceID, 1, costOut, 1, 1, 1, 1, unobPlayerID,
            unobGroupID);
    if (result == 0) {
        this->storePathInExceptionPath = (unsigned char)result;
        return result;
    }

    result = pathSystem.findTilePath(
        (int)this->exceptionPathValue.lastWaypoint()->x,
        (int)this->exceptionPathValue.lastWaypoint()->y,
        (int)goal->world_x, (int)goal->world_y, this, tolerance, goalID, 0,
        costOut, 1, 1, 1, 1, unobPlayerID, unobGroupID);
    this->storePathInExceptionPath = 0;
    return result;
}



int RGE_Moving_Object::canPathWithObstructions(
    int targetID, float range, float* costOut, int useAI,
    int unobPlayerID, int unobGroupID, ManagedArray<int>& unobstructibles) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(
            this->owner->world->terrains[this->master_obj->terrain],
            this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zone_map == 0) {
        return 0;
    }

    int start_zone = zone_map->get_zone_info(
        (long)this->world_x, (long)this->world_y);
    int goal_zone = zone_map->get_zone_info(
        (long)target->world_x, (long)target->world_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = (int)target->world_x;
        goal.y = (int)target->world_y;

        if (zone_map->withinRange(start, goal, range) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    if (useAI != 0) {
        aiPathSystem.incrementCanPaths();
        int result = aiPathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)target->world_x, (int)target->world_y, this,
            range, targetID, 1, costOut, 1, 1, 1, 1,
            unobPlayerID, unobGroupID);
        if (unobGroupID != -1) {
            aiPathSystem.copyUnobstructibles(unobstructibles);
        }
        this->storePathInExceptionPath = 0;
        return result;
    } else {
        pathSystem.incrementCanPaths();
        int result = pathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)target->world_x, (int)target->world_y, this,
            range, targetID, 1, costOut, 1, 1, 1, 1,
            unobPlayerID, unobGroupID);
        if (unobGroupID != -1) {
            pathSystem.copyUnobstructibles(unobstructibles);
        }
        this->storePathInExceptionPath = 0;
        return result;
    }
}



int RGE_Moving_Object::canPathWithAdditionalPassability(
    XYZPoint point, float tolerance, int targetID, float* costOut,
    int terrainException1, int terrainException2, int useAI,
    int unobPlayerID, int unobGroupID) {
    if (point.x < 0 || point.y < 0 ||
        point.x >= this->owner->world->map->map_width ||
        point.y >= this->owner->world->map->map_height) {
        return 0;
    }

    this->currentTerrainException1 = terrainException1;
    this->currentTerrainException2 = terrainException2;
    this->storePathInExceptionPath = 1;

    int result;
    if (useAI != 0) {
        aiPathSystem.incrementCanPaths();
        result = aiPathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y, point.x, point.y, this,
            tolerance, targetID, 1, costOut, 1, 1, 1, 1, unobPlayerID,
            unobGroupID);
    } else {
        pathSystem.incrementCanPaths();
        result = pathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y, point.x, point.y, this,
            tolerance, targetID, 1, costOut, 1, 1, 1, 1, unobPlayerID,
            unobGroupID);
    }

    this->storePathInExceptionPath = 0;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    return result;
}

// declarations live in include/move_obj.h.


int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(
    int terrain, float* result_x, float* result_y) {
    int i;
    XYPoint p1, p2, rVal;
    Path* path = &this->exceptionPathValue;

    if (path->numberOfWaypoints() < 2) {
        return 0;
    }

    path->initToStart();
    if (path->currentWaypoint() == 0) {
        return 0;
    }

    p1.x = (int)path->currentWaypoint()->x;
    p1.y = (int)path->currentWaypoint()->y;
    path->moveToNextWaypoint();
    if (path->currentWaypoint() == 0) {
        return 0;
    }

    p2.x = (int)path->currentWaypoint()->x;
    p2.y = (int)path->currentWaypoint()->y;
    i = 1;
    while (i < path->numberOfWaypoints()) {
        if (this->firstTileAlongLine(&p1, &p2, &rVal,
                                     terrain, terrain, 1) == 1) {
            // The original 00460210 body writes the x-derived
            // result to both output pointers at 0046038D-0046039E.
            float result = (float)rVal.x - DAT_00570b80;
            *result_x = result;
            *result_y = result;
            return 1;
        }

        p1.x = (int)path->currentWaypoint()->x;
        p1.y = (int)path->currentWaypoint()->y;
        path->moveToNextWaypoint();
        if (path->currentWaypoint() == 0) {
            return 0;
        }

        p2.x = (int)path->currentWaypoint()->x;
        p2.y = (int)path->currentWaypoint()->y;
        ++i;
    }

    *result_x = -1.0f;
    *result_y = -1.0f;
    return 0;
}

// The canonical RGE_Moving_Object and XYPoint declarations live in


int RGE_Moving_Object::canLinePath(const XYPoint& a, const XYPoint& b,
                                   float maxDistance, XYPoint& result,
                                   int terrain) {
    int lastX;
    int lastY;
    float xDistance;
    float yDistance;
    int startX = a.x;
    int endX = b.x;
    int startY = a.y;
    int endY = b.y;

    xDistance = (float)(endX - startX);
    yDistance = (float)(endY - startY);

    if ((xDistance == DAT_00570b48) &&
        (yDistance == DAT_00570b48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float x;
    float y;

    if (fabs(yDistance) > fabs(xDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    lastX = -999;
    lastY = -999;
    i = 0;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;
    x = (float)startX;
    y = (float)startY;

    for (; i < numSteps; ++i) {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if (tileX != lastX || tileY != lastY) {
                lastX = tileX;
                lastY = tileY;
                if (this->passableTile(x, y, terrain) == 0) {
                    result.x = tileX;
                    result.y = tileY;
                    return 0;
                }

                if ((float)sqrt(((float)b.x - x) * ((float)b.x - x) +
                                ((float)b.y - y) * ((float)b.y - y)) <=
                    maxDistance) {
                    return 1;
                }
            }
    }

    return 1;
}

// The canonical RGE_Moving_Object declaration lives in
// include/move_obj.h. This is the integer-coordinate overload.


int RGE_Moving_Object::canLinePath(int x1, int y1, int x2, int y2,
                                   float maxDistance, int terrain) {
    int lastX;
    int lastY;
    float xDistance = (float)(x2 - x1);
    float yDistance = (float)(y2 - y1);

    if ((xDistance == DAT_00570b48) &&
        (yDistance == DAT_00570b48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float x;
    float y;

    if (fabs(yDistance) > fabs(xDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    lastX = -999;
    lastY = -999;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;

    x = (float)x1;
    y = (float)y1;

    for (i = 0; i < numSteps; ++i) {
        x += xStep;
        y += yStep;
        int tileX = (int)x;
        int tileY = (int)y;

        if (tileX != lastX || tileY != lastY) {
            lastX = tileX;
            lastY = tileY;
            if (this->passableTile(x, y, terrain) == 0) {
                return 0;
            }

            if ((float)sqrt(((float)x2 - x) * ((float)x2 - x) +
                            ((float)y2 - y) * ((float)y2 - y)) <=
                maxDistance) {
                return 1;
            }
        }

    }

    return 1;
}

// The canonical map, player, moving-object, and point layouts live in
// include/move_obj.h. The inherited passableTile ABI is named there.


int RGE_Moving_Object::firstTileAlongLine(const XYPoint& a,
                                           const XYPoint& b,
                                           XYPoint& result,
                                           int terrain1, int terrain2,
                                           int checkTerrain) {
    int lastX;
    int lastY;
    float xDistance = (float)(b.x - a.x);
    float yDistance = (float)(b.y - a.y);

    if ((xDistance == DAT_00570b48) &&
        (yDistance == DAT_00570b48)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float x;
    float y;
    RGE_Map* map;
    unsigned char tileType;

    if (fabs(yDistance) > fabs(xDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    lastX = -999;
    lastY = -999;
    i = 0;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;
    x = (float)a.x;
    y = (float)a.y;
    map = this->owner->world->map;

    while (i < numSteps) {
            x += xStep;
            y += yStep;
            int tileX = (int)x;
            int tileY = (int)y;

            if ((tileX != lastX) || (tileY != lastY)) {
                lastX = tileX;
                lastY = tileY;
                tileType = map->get_terrain((short)tileX, (short)tileY);
                if (((int)tileType == terrain1 ||
                     (int)tileType == terrain2) &&
                    (checkTerrain == 1)) {
                    if (this->passableTile(x, y, 0) == 1) {
                        result.x = tileX;
                        result.y = tileY;
                        return 1;
                    }
                }
            }

        ++i;
    }

    return 0;
}

float RGE_Moving_Object::maximumSpeed(void) {
    if (this->sprite != 0 && this->sprite->base_speed > 0.0) {
        return ((RGE_Master_Moving_Object*)this->master_obj)->speed *
               this->sprite->base_speed;
    }
    return ((RGE_Master_Moving_Object*)this->master_obj)->speed;
}

// The canonical RGE_Moving_Object declaration and named movement-state
// methods live in include/move_obj.h.

unsigned char RGE_Moving_Object::waitingToMove(void) const {
    unsigned int state = this->actionState();

    if ((state == 6) || (state == 7)) {
        return 0;
    }
    return this->waitingToMoveValue;
}

void RGE_Moving_Object::setWaitingToMove(unsigned char v) { this->waitingToMoveValue = v; }



XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int param_1) {
    if (param_1 < 0 || param_1 >= numberUserDefinedWaypointsValue) return 0;
    return (XYZBYTEPoint*)((char*)userDefinedWaypoints + param_1 * 3);
}



int RGE_Moving_Object::addUserDefinedWaypoint(XYZBYTEPoint* point, int param_2) {
    if (this->finalUserDefinedWaypoint == 1) {
        this->removeAllUserDefinedWaypoints(param_2);
        this->finalUserDefinedWaypoint = 0;
    }

    if (this->maxUserDefinedWaypointsValue >
        this->numberUserDefinedWaypointsValue) {
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].x = point->x;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].y = point->y;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].z = point->z;
    } else {
        if (this->maxUserDefinedWaypointsValue == 0) {
            this->userDefinedWaypoints =
                (XYZBYTEPoint*)operator new(0x0F);
            this->maxUserDefinedWaypointsValue = 5;
            this->numberUserDefinedWaypointsValue = 0;
        } else {
            XYZBYTEPoint* newWaypoints = (XYZBYTEPoint*)operator new(
                this->maxUserDefinedWaypointsValue * 6);
            if (newWaypoints == 0) {
                return 0;
            }

            int i = 0;
            for (; i < this->numberUserDefinedWaypointsValue; ++i) {
                newWaypoints[i].x = this->userDefinedWaypoints[i].x;
                newWaypoints[i].y = this->userDefinedWaypoints[i].y;
                newWaypoints[i].z = this->userDefinedWaypoints[i].z;
            }

            this->maxUserDefinedWaypointsValue =
                this->maxUserDefinedWaypointsValue * 2;
            for (; i < this->maxUserDefinedWaypointsValue; ++i) {
                newWaypoints[i].x = 0;
                newWaypoints[i].y = 0;
                newWaypoints[i].z = 0;
            }

            operator delete(this->userDefinedWaypoints);
            this->userDefinedWaypoints = newWaypoints;
        }

        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].x = point->x;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].y = point->y;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].z = point->z;
    }

    ++this->numberUserDefinedWaypointsValue;
    return 1;
}


void RGE_Moving_Object::removeAllUserDefinedWaypoints(int param_1) {
    this->numberUserDefinedWaypointsValue = 0;
    if (param_1 == 1 && this->unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", this->id, "C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xb59);
        }
        this->unitAIValue->stopObject(0);
    }
}



void RGE_Moving_Object::removeUserDefinedWaypoint(int index) {
    int i;

    if (index < 0 || index >= numberUserDefinedWaypointsValue) return;
    for (i = 0; i < numberUserDefinedWaypointsValue && i < index; i++) {
    }
    for (; i < numberUserDefinedWaypointsValue; i++) {
        if (i) {
            userDefinedWaypoints[i - 1].x = userDefinedWaypoints[i].x;
            userDefinedWaypoints[i - 1].y = userDefinedWaypoints[i].y;
            userDefinedWaypoints[i - 1].z = userDefinedWaypoints[i].z;
        }
    }
    numberUserDefinedWaypointsValue--;
}

void RGE_Moving_Object::setFinalUserDefinedWaypoint() { this->finalUserDefinedWaypoint = 1; }



Path* RGE_Moving_Object::findAvoidancePath(XYZPoint& point, float range,
                                           int targetID) {
    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(
            this->owner->world->terrains[this->master_obj->terrain],
            this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);

    int start_zone = zone_map->get_zone_info(
        (long)this->world_x, (long)this->world_y);
    int goal_zone =
        zone_map->get_zone_info(point.x, point.y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = point.x;
        goal.y = point.y;

        if (zone_map->withinRange(start, goal, range) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    aiPathSystem.findTilePath(
        (int)this->world_x, (int)this->world_y, point.x, point.y, this,
        range, targetID, 1, 0, 0, 1, 1, 1, -1, -1);
    this->storePathInExceptionPath = 0;
    aiPathSystem.initMisc(0);
    return &this->exceptionPathValue;
}

void RGE_Moving_Object::setInitialPoints(XYPoint& minPoint, XYPoint& maxPoint) {
    this->minInitialPointValue.x = minPoint.x;
    this->minInitialPointValue.y = minPoint.y;
    this->maxInitialPointValue.x = maxPoint.x;
    this->maxInitialPointValue.y = maxPoint.y;
}

// The canonical RGE_Static_Object and RGE_Master_Moving_Object layouts live
// in include/move_obj.h. Their named virtual surface preserves both
// direct target identity and the final base copy call.

void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    RGE_Sprite* sprite = 0;
    RGE_Master_Moving_Object* old_master = (RGE_Master_Moving_Object*)this->master_obj;
    RGE_Master_Moving_Object* new_master = (RGE_Master_Moving_Object*)master_obj;

    if (this->sprite == old_master->move_sprite) {
        sprite = new_master->move_sprite;
    } else if (this->sprite == old_master->run_sprite) {
        sprite = new_master->run_sprite;
    }
    if (sprite != 0) {
        this->new_sprite(sprite);
    }
    RGE_Static_Object::copy_obj(master_obj);
}



void RGE_Moving_Object::boundAngle(float* angle, int numberFacets) {
    float wrappedAngle = *angle;

    if (*angle < DAT_00570b48) {
        do {
            wrappedAngle -= DAT_00570b4c;
        } while (wrappedAngle < DAT_00570b48);
        *angle = wrappedAngle;
    } else {
        while (wrappedAngle > 6.2831855f) {
            *angle = wrappedAngle = *angle - 6.2831855f;
        }
    }

    if (numberFacets != -1) {
        float facetAngle;
        if (numberFacets == 8) {
            facetAngle = 0.785398185f;
        } else {
            facetAngle = 0.392699093f;
        }

        int closestFacet = -1;
        int i = 0;
        if (numberFacets >= 0) {
            do {
                float difference = *angle - (float)i * facetAngle;
                if (difference < DAT_00570b98) {
                    difference = -difference;
                }
                if (difference < facetAngle) {
                    facetAngle = difference;
                    closestFacet = i;
                }
                if (facetAngle < DAT_00570c00) {
                    break;
                }
                ++i;
            } while (i <= numberFacets);
        }

        if (numberFacets == 8) {
            *angle = (float)closestFacet * DAT_00570b88;
        } else {
            *angle = (float)closestFacet * DAT_00570bfc;
        }
    }
}

// The canonical RGE_Moving_Object and RGE_Sprite layouts live in
// include/move_obj.h. new_angle is the inherited slot at +0xB4.

void RGE_Moving_Object::rotate(long angleDeg) {
    RGE_Sprite* sprite;
    float rotation;

    sprite = this->sprite;
    rotation = (float)(((double)angleDeg * 6.283185307179586) /
                       (double)sprite->facet_num) + this->angle;

    if (rotation < 0.0f) {
        do {
            rotation += 6.283185f;
        } while (rotation < 0.0f);
    }
    if (rotation >= 6.283185307179586) {
        do {
            rotation -= 6.283185f;
        } while (rotation >= 6.283185307179586);
    }

    this->new_angle(rotation);
}

// The canonical RGE_Moving_Object and Path layouts live in
// EBX/EBP allocation swap and commutative FPU add order.


long RGE_Moving_Object::get_waypoint_checksum() {
    float sum = 0.0f;
    int savedIndex;
    Path* path = &this->pathValue;
    savedIndex = path->currentWaypointNumber();
    path->initToStart();
    int i = 0;
    if (path->numberOfWaypoints() > 0) {
        do {
            Waypoint* wp1 = path->currentWaypoint();
            Waypoint* wp2 = path->currentWaypoint();
            sum += wp1->y + wp2->x;
            i++;
            path->moveToNextWaypoint();
        } while (i < path->numberOfWaypoints());
    }
    path->setCurrentWaypointNumber(savedIndex);
    return (long)(int)sum;
}
