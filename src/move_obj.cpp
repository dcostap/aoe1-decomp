#include "../include/move_obj.h"
#include "../include/sprite.h"
#include "../include/player.h"
#include "../include/m_mo_obj.h"
#include "../include/command_waypoint.h"
#include "../include/pathsys.h"
#include "../include/aiuaimod.h"
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

RGE_Moving_Object::RGE_Moving_Object(RGE_Master_Moving_Object* tobj,
                                     RGE_Player* obj_owner,
                                     float x, float y, float z,
                                     int do_setup)
    : RGE_Animated_Object(tobj, obj_owner, x, y, z, 0),
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

    if (do_setup != 0) {
        this->setup(tobj, obj_owner, x, y, z);
    }
}

RGE_Moving_Object::RGE_Moving_Object(int infile,
                                     RGE_Game_World* gworld,
                                     int do_setup)
    : RGE_Animated_Object(infile, gworld, 0),
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

    if (do_setup != 0) {
        this->setup(infile, gworld);
    }
}

RGE_Moving_Object::~RGE_Moving_Object() {
    if (this->userDefinedWaypoints != 0) {
        operator delete(this->userDefinedWaypoints);
        this->userDefinedWaypoints = 0;
    }
}

void RGE_Moving_Object::recycle_in_to_game(RGE_Master_Static_Object* tobj,
                                           RGE_Player* obj_owner,
                                           float x, float y, float z) {
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

    RGE_Animated_Object::recycle_in_to_game(tobj, obj_owner, x, y, z);

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
                    (g_move_full_circle_double / (float)this->sprite->facet_num) *
                    (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 197) *
                             this->sprite->facet_num) / 0x7FFF);

                if (this->angle < g_move_zero_angle) {
                    this->angle = this->angle - g_move_negative_two_pi;
                } else if (this->angle > g_move_two_pi) {
                    this->angle = this->angle - g_move_two_pi;
                }
            }

        }
    }

    this->set_angle();
}

int RGE_Moving_Object::setup(RGE_Master_Moving_Object* tobj,
                             RGE_Player* obj_owner, float x, float y, float z) {
    this->RGE_Animated_Object::setup(tobj, obj_owner, x, y, z);

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
                    g_move_full_circle_double / (float)(int)this->sprite->facet_num *
                    (float)((debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 222) *
                             (int)this->sprite->facet_num) / 0x7FFF);
                this->angle = random_angle;

                if (this->angle < g_move_zero_angle) {
                    this->angle = random_angle - g_move_negative_two_pi;
                    this->set_angle();
                    return 1;
                }
                if (this->angle > g_move_two_pi) {
                    this->angle = random_angle - g_move_two_pi;
                    this->set_angle();
                    return 1;
                }
            }
        }
    }

    this->set_angle();
    return 1;
}

int RGE_Moving_Object::setup(int infile, RGE_Game_World* gworld) {
    RGE_Animated_Object::setup(infile, gworld);
    this->type = 0x1e;

    rge_read(infile, &this->trail_remainder, 4);
    rge_read(infile, &this->velocity_x, 4);
    rge_read(infile, &this->velocity_y, 4);
    rge_read(infile, &this->velocity_z, 4);
    rge_read(infile, &this->angle, 4);
    rge_read(infile, &this->turn_towards_time, 4);

    int numberOfWaypoints;
    rge_read(infile, &numberOfWaypoints, 4);
    for (int i = 0; i < numberOfWaypoints; ++i) {
        Waypoint temp;
        rge_read(infile, &temp, 16);
        this->pathValue.insertAtEnd(temp);
    }

    int currentWaypoint;
    rge_read(infile, &currentWaypoint, 4);
    int j = 0;
    this->pathValue.initToStart();
    for (; j < currentWaypoint; ++j) {
        this->pathValue.moveToNextWaypoint();
    }

    rge_read(infile, &this->startValue, 16);
    rge_read(infile, &this->goalValue, 16);
    rge_read(infile, &this->turnTimer, 4);
    rge_read(infile, &this->collisionAvoidanceDistance, 4);
    rge_read(infile, &this->actionRange, 4);
    rge_read(infile, &this->targetIDValue, 4);
    rge_read(infile, &this->targetRadiusX, 4);
    rge_read(infile, &this->targetRadiusY, 4);
    rge_read(infile, &this->continueCounter, 4);
    rge_read(infile, &this->rangeStatusValue, 4);
    rge_read(infile, &this->waitingToMoveValue, 1);
    rge_read(infile, &this->numberWaitDelays, 1);

    rge_read(infile, &this->numberUserDefinedWaypointsValue, 4);
    rge_read(infile, &this->maxUserDefinedWaypointsValue, 4);
    this->userDefinedWaypoints = (XYZBYTEPoint*)operator new(this->maxUserDefinedWaypointsValue * 3);
    for (int k = 0; k < this->numberUserDefinedWaypointsValue; ++k) {
        rge_read(infile, &this->userDefinedWaypoints[k], 3);
    }

    rge_read(infile, &this->finalUserDefinedWaypoint, 1);

    if (!(save_game_version < g_move_save_version_1_3)) {
        rge_read(infile, &this->minInitialPointValue.x, 8);
        rge_read(infile, &this->maxInitialPointValue.x, 8);
    } else {
        this->minInitialPointValue.x = -1;
        this->minInitialPointValue.y = -1;
        this->maxInitialPointValue.x = -1;
        this->maxInitialPointValue.y = -1;
    }

    if (!(save_game_version < g_move_save_version_7_22)) {
        rge_read(infile, &this->closestDistanceToWaypoint, 4);
        rge_read(infile, &this->lastFacet, 1);
    } else {
        this->closestDistanceToWaypoint = 100000.0f;
        this->lastFacet = 0xff;
    }

    if (!(save_game_version < g_move_save_version_7_23)) {
        rge_read(infile, &this->lastFacet2, 1);
        return 1;
    }
    this->lastFacet2 = 0xff;
    return 1;
}

void RGE_Moving_Object::save(int outfile) {
    RGE_Animated_Object::save(outfile);

    rge_write(outfile, &this->trail_remainder, 4);
    rge_write(outfile, &this->velocity_x, 4);
    rge_write(outfile, &this->velocity_y, 4);
    rge_write(outfile, &this->velocity_z, 4);
    rge_write(outfile, &this->angle, 4);
    rge_write(outfile, &this->turn_towards_time, 4);

    Path* path = &this->pathValue;
    int numberOfWaypoints = path->numberOfWaypoints();
    rge_write(outfile, &numberOfWaypoints, 4);

    for (int iWaypoint = 0; iWaypoint < numberOfWaypoints; ++iWaypoint) {
        rge_write(outfile, (void*)path->waypoint(iWaypoint), 16);
    }

    int currentWaypoint = path->currentWaypointNumber();
    rge_write(outfile, &currentWaypoint, 4);

    rge_write(outfile, &this->startValue, 16);
    rge_write(outfile, &this->goalValue, 16);
    rge_write(outfile, &this->turnTimer, 4);
    rge_write(outfile, &this->collisionAvoidanceDistance, 4);
    rge_write(outfile, &this->actionRange, 4);
    rge_write(outfile, &this->targetIDValue, 4);
    rge_write(outfile, &this->targetRadiusX, 4);
    rge_write(outfile, &this->targetRadiusY, 4);
    rge_write(outfile, &this->continueCounter, 4);
    rge_write(outfile, &this->rangeStatusValue, 4);
    rge_write(outfile, &this->waitingToMoveValue, 1);
    rge_write(outfile, &this->numberWaitDelays, 1);

    rge_write(outfile, &this->numberUserDefinedWaypointsValue, 4);
    rge_write(outfile, &this->maxUserDefinedWaypointsValue, 4);

    for (int iUser = 0; iUser < this->numberUserDefinedWaypointsValue; ++iUser) {
        rge_write(outfile, &this->userDefinedWaypoints[iUser], 3);
    }

    rge_write(outfile, &this->finalUserDefinedWaypoint, 1);
    rge_write(outfile, &this->minInitialPointValue.x, 8);
    rge_write(outfile, &this->maxInitialPointValue.x, 8);
    rge_write(outfile, &this->closestDistanceToWaypoint, 4);
    rge_write(outfile, &this->lastFacet, 1);
    rge_write(outfile, &this->lastFacet2, 1);
}

void RGE_Moving_Object::new_sprite(RGE_Sprite* nsprite) {
    if (nsprite == 0) {
        nsprite = this->master_obj->sprite;
    }
    if (this->sprite != nsprite) {
        this->old_sprite = this->sprite;
        RGE_Static_Object::new_sprite(nsprite);
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

void RGE_Moving_Object::transform(RGE_Master_Static_Object* obj) {
    this->RGE_Animated_Object::transform(obj);
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

float RGE_Moving_Object::angle_to_object(RGE_Static_Object* to_object,
                                         float x, float y) {
    RGE_Sprite* g = this->sprite;
    if (g != 0 && (g->flags & 2) != 0 && g->facet_num > 0) {
        float ax;
        float ay;
        if (to_object) {
            ay = to_object->world_y;
            ax = to_object->world_x;
        } else {
            ay = y;
            ax = x;
        }

        float x_delta = ax - world_x;
        float a = atan2(ay - world_y, x_delta);
        if (a < g_move_zero_angle)
            a -= g_move_negative_two_pi;
        a -= angle;
        if (a > g_move_pi_double)
            a -= g_move_two_pi;
        if (a < g_move_negative_pi_double)
            a -= g_move_negative_two_pi;

        return ((float)g->facet_num * g_move_inverse_full_circle) * a;
    }
    return g_move_zero_angle;
}

unsigned char RGE_Moving_Object::turn_towards(RGE_Static_Object* obj,
                                               float x, float y) {
    float world_time;
    float angle_delta = this->angle_to_object(obj, x, y);
    if (angle_delta <= 0.5f) {
        if (angle_delta >= -0.5f) {
            return 1;
        }
    }

    world_time = (float)this->owner->world->world_time * g_move_time_scale;
    if (world_time - this->turn_towards_time < ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed) {
        return 0;
    }

    if (angle_delta < 0.0f) {
        this->angle -=
            (float)(g_move_full_circle_double / (float)(int)this->sprite->facet_num);
    } else {
        this->angle +=
            (float)(g_move_full_circle_double / (float)(int)this->sprite->facet_num);
    }

    if (this->angle < 0.0f) {
        this->angle = this->angle - g_move_negative_two_pi;
    } else if (this->angle > g_move_two_pi) {
        this->angle = this->angle - g_move_two_pi;
    }

    this->set_angle();
    this->turn_towards_time = world_time;

    angle_delta = this->angle_to_object(obj, x, y);
    if (angle_delta <= 0.5f) {
        if (angle_delta >= -0.5f) {
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

    float temp = this->angle - g_move_quarter_pi;
    int facet_num = sprite->facet_num;
    temp = temp * (float)facet_num;
    temp = temp * g_move_inverse_full_circle;
    temp = temp - g_move_negative_half_float;
    if (temp < g_move_zero_angle) {
        temp = temp + (float)facet_num;
    }
    this->facet = (unsigned char)((int)temp);
}

float RGE_Moving_Object::teleport(float x, float y, float z) {
    if (((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_options != 0 && this->tile != 0) {
        RGE_Master_Static_Object* trail_master =
            this->owner->master_objects[
                ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_id];

        if (trail_master != 0) {
            switch (((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_options) {
            case 1: {
                RGE_Static_Object* trail =
                    trail_master->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
                if (trail->master_obj->id > 30) {
                    trail->new_angle(this->angle);
                }
                break;
            }

            case 2: {
                float dx;
                float dy;
                float dz;
                float d;
                float tx;
                float ty;
                float tz;
                //! @bug This branch adds trail_remainder twice when count is nonpositive.
                dx = x - this->world_x;
                dy = y - this->world_y;
                dz = z - this->world_z;
                d =
                    (float)sqrt(dx * dx + dy * dy + dz * dz) +
                    this->trail_remainder;
                short count =
                    (short)(d / ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_spacing);

                if (count > 0) {
                    dx /= (float)count;
                    dy /= (float)count;
                    dz /= (float)count;
                    tx = this->world_x;
                    ty = this->world_y;
                    tz = this->world_z;
                    for (short i = 0; i < count; ++i) {
                        RGE_Static_Object* trail =
                            trail_master->make_new_obj(this->owner, tx, ty, tz);
                        if (trail->master_obj->id > 30) {
                            trail->new_angle(this->angle);
                        }
                        tx += dx;
                        ty += dy;
                        tz += dz;
                    }

                    this->trail_remainder =
                        d -
                        ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_spacing *
                            (float)count;
                } else {
                    this->trail_remainder = d + this->trail_remainder;
                }
                break;
            }
            }
        }
    }

    return RGE_Static_Object::teleport(x, y, z);
}

void RGE_Moving_Object::set_velocity(float x, float y, float z) {
    this->velocity_x = x;
    this->velocity_y = y;
    this->velocity_z = z;
}

void RGE_Moving_Object::new_angle(float new_angle) {
    // The direct float assignment preserves the executable's bit-copy store
    // and direct symbol.
    this->angle = new_angle;
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

void RGE_Moving_Object::setGoal(float gX, float gY, float gZ) {
    this->goalValue.x = gX;
    this->goalValue.y = gY;
    this->goalValue.z = gZ;
}

void RGE_Moving_Object::setActionRange(float r) { this->actionRange = r; }

void RGE_Moving_Object::setTargetID(int tid) { this->targetIDValue = tid; }

void RGE_Moving_Object::setTargetRadius(float x, float y) {
    this->targetRadiusX = x;
    this->targetRadiusY = y;
}

inline void RGE_Moving_Object::setStart(float x, float y, float z) {
    this->startValue.x = x;
    this->startValue.y = y;
    this->startValue.z = z;
}

inline void RGE_Moving_Object::displayPath(int object_id) {
    if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
        this->pathValue.initToStart();
        int i = 0;
        int n = this->pathValue.numberOfWaypoints();
        while (i < n) {
            this->owner->master_objects[object_id]->make_new_obj(this->owner, this->pathValue.currentWaypoint()->x,
                                                                 this->pathValue.currentWaypoint()->y, 1.0f);
            ++i;
            this->pathValue.moveToNextWaypoint();
            n = this->pathValue.numberOfWaypoints();
        }
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
    }
}

RGE_Moving_Object::PathResult RGE_Moving_Object::findPath() {
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

    // The executable keeps this constant guard and its unreachable cleanup arm.
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
        found = pathSystem.findTilePath(// Natural casts keep __ftol input on x87 ST0.
                                        (int)this->startValue.x, (int)this->startValue.y, this->userDefinedWaypoints->x, this->userDefinedWaypoints->y,
                                        this, this->actionRange, this->targetIDValue, 1, 0, 1, 1, 1, 1, -1, -1);
    } else {
        found = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                        (int)this->goalValue.x, (int)this->goalValue.y, this, this->actionRange, this->targetIDValue,
                                        1, 0, 1, 1, 1, 1, -1, -1);
    }

    if (actionFile != 0) {
        fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n", this->owner->world->world_time, this->id,
                this->startValue.x, this->startValue.y, this->goalValue.x, this->goalValue.y);
        this->pathValue.initToStart();
        int i = 0;
        while (i < this->pathValue.numberOfWaypoints()) {
            fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, this->pathValue.currentWaypoint()->x,
                    this->pathValue.currentWaypoint()->y);
            i++;
            this->pathValue.moveToNextWaypoint();
        }
        fprintf(actionFile, ".\n");
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
    }

    // Cast each floor result before subtracting the float tile bias.
    if (!found && this->pathValue.numberOfWaypoints() == 1) {
        if (pathSystem.passable(this, (float)floor((double)this->world_x) - g_move_negative_half_float,
                                (float)floor((double)this->world_y) - g_move_negative_half_float, 1)) {
            if ((this->world_x - floor((double)this->world_x)) != 0.5 ||
                (this->world_y - floor((double)this->world_y)) != 0.5) {
                this->teleport((float)floor((double)this->world_x) - g_move_negative_half_float,
                               (float)floor((double)this->world_y) - g_move_negative_half_float, this->world_z);
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
    float distanceToGoal;
    float dY;
    float newDY;
    float dX;
    float radiusDistance;
    int waypointStatus;
    int found;
    int i;
    int displayObjectID;

    this->setWaitingToMove(0);

    dX = this->goalValue.x - this->world_x;
    dY = this->goalValue.y - this->world_y;
    if (dX < g_move_zero_angle) {
        dX = -dX;
    }
    if (dY < g_move_zero_angle) {
        dY = -dY;
    }

    dX = dX - (this->targetRadiusX + this->master_obj->radius_x);
    dY = dY - (this->targetRadiusY + this->master_obj->radius_y);
    if (dX < g_move_zero_angle) {
        dX = 0.0f;
    }
    if (dY < g_move_zero_angle) {
        dY = g_move_zero_angle;
    }

    distanceToGoal = (float)sqrt(dY * dY + dX * dX);
    if (this->actionRange > g_move_zero_double && distanceToGoal <= this->actionRange) {
        this->speed = 0.0f;
        this->rangeStatusValue = 1;
        this->removeAllUserDefinedWaypoints(0);
        this->pathingGroupMembers.zeroNumber();
        return 2;
    }

    if (distanceToGoal < g_move_half_double) {
        float trivialDistance = distanceToGoal;
        Waypoint* waypoint = this->pathValue.currentWaypoint();
        if (waypoint != 0) {
            waypoint = this->pathValue.currentWaypoint();
            dX = waypoint->x - this->world_x;
            waypoint = this->pathValue.currentWaypoint();
            dY = waypoint->y - this->world_y;
            trivialDistance = (float)sqrt(dY * dY + dX * dX);
        }

        if (trivialDistance == g_move_zero_angle) {
            this->pathingGroupMembers.zeroNumber();
            return 2;
        }

        int trivialResult =
            this->doTrivialMove(this->goalValue.x, this->goalValue.y);
        if (trivialResult == 5) {
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->pathingGroupMembers.zeroNumber();
            return 2;
        }
        if (trivialResult == 0) {
            this->rangeStatusValue = 2;
            return 1;
        }
        if (trivialResult == 1 || trivialResult == 6) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            return 1;
        }
        if (trivialResult == 2 || trivialResult == 3 || trivialResult == 4) {
            this->speed = 0.0f;
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->pathingGroupMembers.zeroNumber();
            return 2;
        }
    }

    radiusDistance = (float)sqrt(this->master_obj->radius_y * this->master_obj->radius_y +
                                 this->master_obj->radius_x * this->master_obj->radius_x);
    waypointStatus = 1;
    Waypoint* waypoint = this->pathValue.currentWaypoint();
    if (waypoint == 0) {
        waypointStatus = 0;
    } else {
        waypoint = this->pathValue.currentWaypoint();
        dX = waypoint->x - this->world_x;
        waypoint = this->pathValue.currentWaypoint();
        dY = waypoint->y - this->world_y;
        if ((float)sqrt(dY * dY + dX * dX) == g_move_zero_angle) {
            waypointStatus = 1;
            waypoint = this->pathValue.currentWaypoint();
            dY = waypoint->y;
            waypoint = this->pathValue.currentWaypoint();
            waypointStatus = pathSystem.passable(this, waypoint->x, dY, waypointStatus);
            if (waypointStatus != 0) {
                waypoint = this->pathValue.currentWaypoint();
                float waypointZ = waypoint->z;
                waypoint = this->pathValue.currentWaypoint();
                dY = waypoint->y;
                waypoint = this->pathValue.currentWaypoint();
                this->teleport(waypoint->x, dY, waypointZ);
            }
            waypointStatus = this->pathValue.moveToNextWaypoint();
            this->closestDistanceToWaypoint = 100000.0f;
        }
    }

    newDY = 0.0f;
    if (this->numberUserDefinedWaypointsValue > 1 && distanceToGoal > g_move_waypoint_distance_threshold) {
        unsigned char firstZone = this->lookupZone((int)this->userDefinedWaypoints[0].x,
                                                   (int)this->userDefinedWaypoints[0].y);
        unsigned char secondZone = this->lookupZone((int)this->userDefinedWaypoints[1].x,
                                                    (int)this->userDefinedWaypoints[1].y);
        if (firstZone == secondZone) {
            newDY = 3.0f;
        }
    }

    if (waypointStatus == 0) {
        if (distanceToGoal <= newDY + radiusDistance + this->actionRange) {
            this->speed = 0.0f;
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->pathingGroupMembers.zeroNumber();
            return 2;
        }

        int reachedWaypoint = 0;
        do {
            this->removeUserDefinedWaypoint(0);
            if (this->numberUserDefinedWaypointsValue < 1) {
                return 0;
            }
            dX = (float)this->userDefinedWaypoints->x - this->world_x;
            dY = (float)this->userDefinedWaypoints->y - this->world_y;
            if (radiusDistance + this->actionRange - g_move_radius_distance_adjustment < (float)sqrt(dY * dY + dX * dX)) {
                reachedWaypoint = 1;
            }
        } while (reachedWaypoint == 0);

        int oldContinueCounter = this->continueCounter;
        this->continueCounter = oldContinueCounter - 1;
        if (this->continueCounter < 1) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
            }
            this->continueCounter = oldContinueCounter + 4;
            return 1;
        }

        if (this->owner->availablePathingAttempts(this->numberWaitDelays) == 0) {
            this->speed = 0.0f;
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
            found = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                            this->userDefinedWaypoints->x, this->userDefinedWaypoints->y, this, this->actionRange, this->targetIDValue,
                                            1, (float*)0, 1, 1, 1, 1, -1, -1);
        } else {
            found = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                            (int)this->goalValue.x, (int)this->goalValue.y, this, this->actionRange, this->targetIDValue,
                                            1, (float*)0, 1, 1, 1, 1, -1, -1);
        }

        this->pathingGroupMembers.zeroNumber();
        if (actionFile != 0) {
            fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                    this->owner->world->world_time, this->id, this->startValue.x, this->startValue.y,
                    this->goalValue.x, this->goalValue.y);
            this->pathValue.initToStart();
            i = 0;
            while (i < this->pathValue.numberOfWaypoints()) {
                fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, this->pathValue.currentWaypoint()->x,
                        this->pathValue.currentWaypoint()->y);
                ++i;
                this->pathValue.moveToNextWaypoint();
            }
            fprintf(actionFile, ".\n");
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        if (found == 0 && this->pathValue.numberOfWaypoints() == 1) {
            if (pathSystem.passable(this, (float)floor((double)this->world_x) - g_move_negative_half_float,
                                    (float)floor((double)this->world_y) - g_move_negative_half_float, 1) == 0) {
                this->speed = 0.0f;
                this->rangeStatusValue = 2;
                if (this->numberUserDefinedWaypointsValue < 2) {
                    return 0;
                }
                this->continueCounter += 5;
                return 1;
            }
            if (this->world_x - floor((double)this->world_x) == g_move_half_double &&
                this->world_y - floor((double)this->world_y) == g_move_half_double) {
                this->speed = 0.0f;
                this->rangeStatusValue = 2;
                if (this->numberUserDefinedWaypointsValue < 2) {
                    return 0;
                }
                this->continueCounter += 5;
                return 1;
            }
            this->teleport((float)floor((double)this->world_x) - g_move_negative_half_float,
                           (float)floor((double)this->world_y) - g_move_negative_half_float, this->world_z);
        }

        displayObjectID = displayPathObjectID;
        if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
            this->pathValue.initToStart();
            i = 0;
            while (i < this->pathValue.numberOfWaypoints()) {
                RGE_Master_Static_Object* master =
                    this->owner->master_objects[displayObjectID];
                master->make_new_obj(this->owner, this->pathValue.currentWaypoint()->x,
                                     this->pathValue.currentWaypoint()->y, 1.0f);
                ++i;
                this->pathValue.moveToNextWaypoint();
            }
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        this->pathValue.initToStart();
        if (this->pathValue.moveToNextWaypoint() == 0) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
            }
            this->continueCounter += 5;
            return 1;
        }
        this->closestDistanceToWaypoint = 100000.0f;
    }

    waypoint = this->pathValue.currentWaypoint();
    if (waypoint == 0) {
        this->speed = 0.0f;
        this->rangeStatusValue = 2;
        if (this->numberUserDefinedWaypointsValue < 2) {
            return 0;
        }
        this->continueCounter += 5;
        return 1;
    }

    waypoint = this->pathValue.currentWaypoint();
    dY = waypoint->y;
    waypoint = this->pathValue.currentWaypoint();
    int trivialResult = this->doTrivialMove(waypoint->x, dY);
    if (trivialResult == 5) {
        this->rangeStatusValue = 1;
        this->removeAllUserDefinedWaypoints(0);
        this->pathingGroupMembers.zeroNumber();
        return 2;
    }
    if (trivialResult == 0) {
        this->rangeStatusValue = 2;
        return 1;
    }
    if (trivialResult == 1) {
        this->speed = 0.0f;
        this->rangeStatusValue = 2;
        return 1;
    }
    if (trivialResult == 2) {
        if (this->pathValue.moveToNextWaypoint() != 0) {
            this->rangeStatusValue = 2;
            return 1;
        }

        int reachedWaypoint = 0;
        do {
            this->removeUserDefinedWaypoint(0);
            if (this->numberUserDefinedWaypointsValue < 1) {
                return 0;
            }
            dX = (float)this->userDefinedWaypoints->x - this->world_x;
            dY = (float)this->userDefinedWaypoints->y - this->world_y;
            if (radiusDistance + this->actionRange - g_move_radius_distance_adjustment < (float)sqrt(dY * dY + dX * dX)) {
                reachedWaypoint = 1;
            }
        } while (reachedWaypoint == 0);

        if (this->owner->availablePathingAttempts(this->numberWaitDelays) == 0) {
            this->speed = 0.0f;
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
            found = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                            this->userDefinedWaypoints->x, this->userDefinedWaypoints->y, this, this->actionRange, this->targetIDValue,
                                            1, (float*)0, 1, 1, 1, 1, -1, -1);
        } else {
            found = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                            (int)this->goalValue.x, (int)this->goalValue.y, this, this->actionRange, this->targetIDValue,
                                            1, (float*)0, 1, 1, 1, 1, -1, -1);
        }

        this->pathingGroupMembers.zeroNumber();
        if (actionFile != 0) {
            fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                    this->owner->world->world_time, this->id, this->startValue.x, this->startValue.y,
                    this->goalValue.x, this->goalValue.y);
            this->pathValue.initToStart();
            i = 0;
            while (i < this->pathValue.numberOfWaypoints()) {
                fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, this->pathValue.currentWaypoint()->x,
                        this->pathValue.currentWaypoint()->y);
                ++i;
                this->pathValue.moveToNextWaypoint();
            }
            fprintf(actionFile, ".\n");
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        if (found == 0 && this->pathValue.numberOfWaypoints() == 1) {
            if (pathSystem.passable(this, (float)floor((double)this->world_x) - g_move_negative_half_float,
                                    (float)floor((double)this->world_y) - g_move_negative_half_float, 1) != 0) {
                if (this->world_x - floor((double)this->world_x) != g_move_half_double ||
                    this->world_y - floor((double)this->world_y) != g_move_half_double) {
                    this->teleport((float)floor((double)this->world_x) - g_move_negative_half_float,
                                   (float)floor((double)this->world_y) - g_move_negative_half_float, this->world_z);
                } else {
                    this->speed = 0.0f;
                    this->rangeStatusValue = 2;
                    if (this->numberUserDefinedWaypointsValue < 2) {
                        return 0;
                    }
                    this->continueCounter += 5;
                    return 1;
                }
            }
        }

        displayObjectID = displayPathObjectID;
        if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
            this->pathValue.initToStart();
            i = 0;
            while (i < this->pathValue.numberOfWaypoints()) {
                RGE_Master_Static_Object* master =
                    this->owner->master_objects[displayObjectID];
                master->make_new_obj(this->owner, this->pathValue.currentWaypoint()->x,
                                     this->pathValue.currentWaypoint()->y, 1.0f);
                ++i;
                this->pathValue.moveToNextWaypoint();
            }
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        this->pathValue.initToStart();
        if (this->pathValue.moveToNextWaypoint() == 0) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
            }
            this->continueCounter += 5;
            return 1;
        }
        this->rangeStatusValue = 2;
        return 1;
    }

    this->speed = 0.0f;
    this->rangeStatusValue = 2;
    if (this->numberUserDefinedWaypointsValue < 2) {
        return 0;
    }
    this->continueCounter += 5;
    return 1;
}

int RGE_Moving_Object::doTrivialMove(float x, float y) {
    int alreadyMoving = 1;
    if (this->speed == g_move_zero_double) {
        alreadyMoving = 0;
        if (this->sprite != 0 && this->sprite->base_speed > g_move_zero_double) {
            this->speed =
                ((RGE_Master_Moving_Object*)this->master_obj)->speed *
                this->sprite->base_speed;
        } else {
            this->speed =
                ((RGE_Master_Moving_Object*)this->master_obj)->speed;
        }
    }

    float distanceToCover =
        this->owner->world->world_time_delta_seconds * this->speed;

    if (this->collisionAvoidanceDistance > g_move_zero_double) {
        this->collisionAvoidanceDistance -= distanceToCover;
        if (this->collisionAvoidanceDistance > g_move_zero_double) {
            this->speed = 0.0f;
            return 0;
        }
        this->collisionAvoidanceDistance = -1.0f;
    }

    if (((RGE_Master_Moving_Object*)this->master_obj)->turn_speed > g_move_zero_double) {
        if (this->turnTimer >= g_move_zero_double) {
            this->turnTimer -= this->owner->world->world_time_delta_seconds;
        } else {
            this->turnTimer = 0.0f;
        }
    }

    int numberFacets;
    if (this->sprite != 0) {
        numberFacets = this->sprite->facet_num;
    } else {
        numberFacets = 8;
    }

    float targetDX;
    float targetDY;
    if (alreadyMoving != 0) {
        targetDX = x - this->world_x;
        targetDY = y - this->world_y;
    } else {
        targetDX = x - ((float)floor((double)this->world_x) - g_move_negative_half_float);
        targetDY = y - ((float)floor((double)this->world_y) - g_move_negative_half_float);
    }

    float newAngle = (float)atan2((double)targetDY, (double)targetDX);
    this->boundAngle(&newAngle, -1);
    float angleDelta = newAngle - this->angle;
    while (angleDelta < g_move_negative_pi_double) {
        angleDelta -= g_move_negative_two_pi;
    }
    while (angleDelta > g_move_pi_double) {
        angleDelta -= g_move_two_pi;
    }

    float facetDelta =
        angleDelta * (float)numberFacets * g_move_inverse_full_circle;
    this->boundAngle(&this->angle, numberFacets);
    while (this->turnTimer <= g_move_zero_angle && (facetDelta > g_move_turn_delta_upper || facetDelta < g_move_turn_delta_lower)) {
        this->turnTimer +=
            ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed;
        if (angleDelta >= g_move_zero_angle) {
            facetDelta -= g_move_positive_one;
            this->angle += (float)(g_move_full_circle_double / (float)numberFacets);
        } else {
            facetDelta -= g_move_negative_one;
            this->angle -= (float)(g_move_full_circle_double / (float)numberFacets);
        }
    }

    this->boundAngle(&this->angle, numberFacets);
    this->set_angle();

    this->velocity_x = (float)cos((double)this->angle) * distanceToCover;
    this->velocity_y = (float)sin((double)this->angle) * distanceToCover;
    float newX = this->world_x + this->velocity_x;
    float newY = this->world_y + this->velocity_y;

    int result = 1;
    if (((RGE_Master_Moving_Object*)this->master_obj)->radius_z > g_move_zero_angle) {
        result = pathSystem.passable(this, newX, newY, 1);
    }

    if (result == 0) {
        if (this->collisionAvoidanceDistance == g_move_zero_angle) {
            if (this->speed > g_move_zero_angle) {
                this->collisionAvoidanceDistance =
                    (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 1743) % 6) *
                        g_move_speed_offset_base - g_move_negative_half_float / this->speed;
            } else {
                this->collisionAvoidanceDistance =
                    (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 1745) % 6) *
                        g_move_speed_offset_base - g_move_negative_half_float;
            }
            this->speed = 0.0f;
            return 0;
        }

        this->collisionAvoidanceDistance = 0.0f;
        if (pathSystem.passable(this, (float)floor((double)this->world_x) - g_move_negative_half_float,
                                (float)floor((double)this->world_y) - g_move_negative_half_float, 1) != 0) {
            this->teleport((float)floor((double)this->world_x) - g_move_negative_half_float,
                           (float)floor((double)this->world_y) - g_move_negative_half_float, this->world_z);
        }

        if (this->targetIDValue != -1) {
            RGE_Static_Object* target =
                this->owner->world->object(this->targetIDValue);
            if (target != 0) {
                RGE_Master_Moving_Object* currentMaster =
                    (RGE_Master_Moving_Object*)this->master_obj;
                if ((float)sqrt((target->world_x - this->world_x) * (target->world_x - this->world_x) +
                                (target->world_y - this->world_y) * (target->world_y - this->world_y)) <
                    (float)sqrt(currentMaster->radius_x * currentMaster->radius_x +
                                currentMaster->radius_y * currentMaster->radius_y) + this->actionRange - g_move_radius_distance_adjustment) {
                    return 5;
                }
            }
        }

        if (pathSystem.passable(this, x, y, 1) == 0) {
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
            result = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                             this->userDefinedWaypoints[0].x, this->userDefinedWaypoints[0].y,
                                             this, this->actionRange, this->targetIDValue, 1, 0, 1, 1, 1, 1, -1, -1);
        } else {
            result = pathSystem.findTilePath((int)this->startValue.x, (int)this->startValue.y,
                                             (int)this->goalValue.x, (int)this->goalValue.y, this, this->actionRange, this->targetIDValue,
                                             1, 0, 1, 1, 1, 1, -1, -1);
        }

        if (actionFile != 0) {
            fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)\n",
                    this->owner->world->world_time, this->id, this->startValue.x, this->startValue.y,
                    this->goalValue.x, this->goalValue.y);
            Path* path = &this->pathValue;
            path->initToStart();
            int i = 0;
            while (i < path->numberOfWaypoints()) {
                fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, path->currentWaypoint()->x, path->currentWaypoint()->y);
                ++i;
                path->moveToNextWaypoint();
            }
            fprintf(actionFile, ".\n");
            path->initToStart();
            path->moveToNextWaypoint();
        }

        if (result == 0 && this->pathValue.numberOfWaypoints() == 1) {
            if (pathSystem.passable(this, (float)floor((double)this->world_x) - g_move_negative_half_float,
                                    (float)floor((double)this->world_y) - g_move_negative_half_float, 1) != 0) {
                if (this->world_x - floor((double)this->world_x) == g_move_half_double &&
                    this->world_y - floor((double)this->world_y) == g_move_half_double) {
                    return 4;
                }
                this->teleport((float)floor((double)this->world_x) - g_move_negative_half_float,
                               (float)floor((double)this->world_y) - g_move_negative_half_float, this->world_z);
            }
        }

        int displayObjectID = displayPathObjectID;
        if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
            this->pathValue.initToStart();
            int i = 0;
            while (i < this->pathValue.numberOfWaypoints()) {
                this->owner->master_objects[displayObjectID]->make_new_obj(
                    this->owner, this->pathValue.currentWaypoint()->x, this->pathValue.currentWaypoint()->y, 1.0f);
                ++i;
                this->pathValue.moveToNextWaypoint();
            }
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        this->pathValue.initToStart();
        if (this->pathValue.moveToNextWaypoint() == 0) {
            return 4;
        }
        this->closestDistanceToWaypoint = 100000.0f;

        Waypoint* waypoint;
        if (alreadyMoving != 0) {
            waypoint = this->pathValue.currentWaypoint();
            targetDX = waypoint->x - this->world_x;
            waypoint = this->pathValue.currentWaypoint();
            targetDY = waypoint->y - this->world_y;
        } else {
            waypoint = this->pathValue.currentWaypoint();
            targetDX = waypoint->x -
                ((float)floor((double)this->world_x) - g_move_negative_half_float);
            waypoint = this->pathValue.currentWaypoint();
            targetDY = waypoint->y -
                ((float)floor((double)this->world_y) - g_move_negative_half_float);
        }

        newAngle = (float)atan2((double)targetDY, (double)targetDX);
        this->boundAngle(&newAngle, -1);
        angleDelta = newAngle - this->angle;
        facetDelta = angleDelta * (float)numberFacets * g_move_inverse_full_circle;

        if (this->turnTimer > g_move_zero_angle) {
            this->speed = 0.0f;
            return 0;
        }

        while (facetDelta > g_move_turn_delta_upper_wide || facetDelta < g_move_turn_delta_lower_wide) {
            this->turnTimer +=
                ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed;
            if (angleDelta >= g_move_zero_angle) {
                facetDelta -= g_move_positive_one;
                this->angle += (float)(g_move_full_circle_double / (float)numberFacets);
            } else {
                facetDelta -= g_move_negative_one;
                this->angle -= (float)(g_move_full_circle_double / (float)numberFacets);
            }
            if (this->turnTimer > g_move_zero_angle) {
                break;
            }
        }

        this->boundAngle(&this->angle, numberFacets);
        this->set_angle();
        this->velocity_x =
            (float)cos((double)this->angle) * distanceToCover;
        this->velocity_y =
            (float)sin((double)this->angle) * distanceToCover;
        newX = this->world_x + this->velocity_x;
        newY = this->world_y + this->velocity_y;

        if (pathSystem.passable(this, newX, newY, 1) == 0) {
            if (this->owner->computerPlayer() == 1) {
                return 4;
            }
            if (this->speed > g_move_zero_angle) {
                this->collisionAvoidanceDistance =
                    (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 2003) % 6) *
                        g_move_speed_offset_base - g_move_negative_half_float / this->speed;
            } else {
                this->collisionAvoidanceDistance =
                    (float)(debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 2005) % 6) *
                        g_move_speed_offset_base - g_move_negative_half_float;
            }
            this->speed = 0.0f;
            return 0;
        }
    }

    float tempZ = this->world_z;
    float curDistance;
    Waypoint* waypoint = this->pathValue.currentWaypoint();
    if (waypoint != 0) {
        waypoint = this->pathValue.currentWaypoint();
        float dX = waypoint->x - this->world_x;
        waypoint = this->pathValue.currentWaypoint();
        float dY = waypoint->y - this->world_y;
        curDistance = (float)sqrt(dX * dX + dY * dY);

        waypoint = this->pathValue.currentWaypoint();
        dX = waypoint->x - (this->world_x + this->velocity_x);
        waypoint = this->pathValue.currentWaypoint();
        dY = waypoint->y - (this->world_y + this->velocity_y);
        float newDistance = (float)sqrt(dX * dX + dY * dY);

        if ((this->closestDistanceToWaypoint < newDistance && curDistance < g_move_waypoint_distance_threshold_close) ||
            (this->lastFacet2 == this->facet && this->lastFacet2 != this->lastFacet && curDistance < g_move_half_float)) {
            if (pathSystem.passable(this, this->pathValue.currentWaypoint()->x,
                                    this->pathValue.currentWaypoint()->y, 1) == 0) {
                return 2;
            }
            this->teleport(this->pathValue.currentWaypoint()->x, this->pathValue.currentWaypoint()->y,
                           this->pathValue.currentWaypoint()->z);
        } else {
            this->teleport(newX, newY, this->world_z + this->velocity_z);
        }
    } else {
        float dY = y - newY;
        float dX = x - newX;
        curDistance = (float)sqrt(dY * dY + dX * dX);
        this->teleport(newX, newY, this->world_z + this->velocity_z);
    }

    float speedOffset = tempZ - this->world_z;
    float speedMultiplier = 1.0f;
    unsigned char oldFacet = this->lastFacet;
    this->lastFacet = this->facet;
    this->lastFacet2 = oldFacet;
    this->closestDistanceToWaypoint = curDistance;

    if (speedOffset < g_move_speed_offset_lower) {
        speedMultiplier = 0.9f;
    } else if (speedOffset > g_move_speed_offset_upper) {
        speedMultiplier = 1.03f;
    } else if (this->sprite != 0 && this->sprite->base_speed > g_move_zero_double) {
        this->speed =
            ((RGE_Master_Moving_Object*)this->master_obj)->speed *
            this->sprite->base_speed;
    } else {
        this->speed =
            ((RGE_Master_Moving_Object*)this->master_obj)->speed;
    }

    if (this->tile != 0) {
        speedMultiplier *= this->get_terrain_speed(this->tile->terrain_type & 0x1f);
    }
    if (speedMultiplier > g_move_zero_angle) {
        this->speed *= speedMultiplier;
    }
    return 0;
}

int RGE_Moving_Object::passableTile(float x, float y, int aiCheck) {
    if (aiCheck != 0) {
        return aiPathSystem.passable(this, x, y, 1);
    }
    return pathSystem.passable(this, x, y, 1);
}

int RGE_Moving_Object::canPath(XYZPoint p, float aRange, int targetID,
                               float* pathDistance, int aiCheck,
                               int unobstructiblePlayerID,
                               int unobstructibleGroupID) {
    if (p.x < 0 || p.y < 0) {
        return 0;
    }

    RGE_Map* map = this->owner->world->map;
    if (p.x < map->map_width && p.y < map->map_height) {
        if (this->zoneMapIndex == -1) {
            this->owner->world->map->map_zones->get_zone_map(this->owner->world->terrains[this->master_obj->terrain],
                                                             this->owner->world->terrain_size, this->zoneMapIndex);
        }

        RGE_Zone_Map* zone_map =
            this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
        if (zone_map != 0) {
            int initialZone = zone_map->get_zone_info((long)this->world_x, (long)this->world_y);
            int goal_zone = zone_map->get_zone_info(p.x, p.y);
            if (goal_zone != initialZone) {
                XYPoint start;
                start.x = (int)this->world_x;
                start.y = (int)this->world_y;

                XYPoint goal;
                goal.x = p.x;
                goal.y = p.y;

                if (zone_map->withinRange(start, goal, aRange) == 0) {
                    return 0;
                }
            }

            if (aiCheck != 0) {
                aiPathSystem.incrementCanPaths();
                return aiPathSystem.findTilePath((int)this->world_x, (int)this->world_y, p.x, p.y,
                                                 this, aRange, targetID, 0, pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
            }

            pathSystem.incrementCanPaths();
            return pathSystem.findTilePath((int)this->world_x, (int)this->world_y, p.x, p.y, this,
                                           aRange, targetID, 0, pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
        }
    }

    return 0;
}

int RGE_Moving_Object::canPath(int targetID, float aRange,
                               float* pathDistance, int aiCheck,
                               int unobstructiblePlayerID,
                               int unobstructibleGroupID) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(this->owner->world->terrains[this->master_obj->terrain],
                                                         this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zone_map == 0) {
        return 0;
    }

    int start_zone = zone_map->get_zone_info((long)this->world_x, (long)this->world_y);
    int goal_zone = zone_map->get_zone_info((long)target->world_x, (long)target->world_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = (int)target->world_x;
        goal.y = (int)target->world_y;

        if (zone_map->withinRange(start, goal, aRange) == 0) {
            return 0;
        }
    }

    if (aiCheck != 0) {
        aiPathSystem.incrementCanPaths();
        return aiPathSystem.findTilePath((int)this->world_x, (int)this->world_y,
                                         (int)target->world_x, (int)target->world_y, this, aRange, targetID, 0, pathDistance, 1, 1, 1, 1,
                                         unobstructiblePlayerID, unobstructibleGroupID);
    }

    pathSystem.incrementCanPaths();
    return pathSystem.findTilePath((int)this->world_x, (int)this->world_y, (int)target->world_x, (int)target->world_y, this,
                                   aRange, targetID, 0, pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
}

int RGE_Moving_Object::canBidirectionPath(
    int targetID, int targetID2, float aRange, float* pathDistance,
    int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID) {
    RGE_Static_Object* source;
    RGE_Static_Object* goal;
    RGE_Zone_Map* zoneMap;
    int initialZone;
    int goal_zone;
    XYPoint start;
    XYPoint goal_point;

    source = this->owner->world->object(targetID);
    goal = this->owner->world->object(targetID2);
    if (source == 0 || goal == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(this->owner->world->terrains[this->master_obj->terrain],
                                                         this->owner->world->terrain_size, this->zoneMapIndex);
    }

    zoneMap =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zoneMap == 0) {
        return 0;
    }

    initialZone = zoneMap->get_zone_info((long)this->world_x, (long)this->world_y);
    goal_zone = zoneMap->get_zone_info((long)source->world_x, (long)source->world_y);

    if (goal_zone != initialZone) {
        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal_point.x = (int)source->world_x;
        goal_point.y = (int)source->world_y;

        if (zoneMap->withinRange(start, goal_point, aRange) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    if (aiCheck != 0) {
        aiPathSystem.incrementCanPaths();
        int result = aiPathSystem.findTilePath((int)this->world_x, (int)this->world_y,
                                               (int)source->world_x, (int)source->world_y, this, aRange, targetID, 1, pathDistance, 1, 1, 1, 1,
                                               unobstructiblePlayerID, unobstructibleGroupID);
        if (result == 0) {
            this->storePathInExceptionPath = (unsigned char)result;
            return result;
        }

        result = aiPathSystem.findTilePath((int)this->exceptionPathValue.lastWaypoint()->x,
                                           (int)this->exceptionPathValue.lastWaypoint()->y,
                                           (int)goal->world_x, (int)goal->world_y, this, aRange, targetID2, 0,
                                           pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
        this->storePathInExceptionPath = 0;
        return result;
    }

    pathSystem.incrementCanPaths();
    int result = pathSystem.findTilePath((int)this->world_x, (int)this->world_y,
                                         (int)source->world_x, (int)source->world_y, this, aRange, targetID, 1, pathDistance, 1, 1, 1, 1,
                                         unobstructiblePlayerID, unobstructibleGroupID);
    if (result == 0) {
        this->storePathInExceptionPath = (unsigned char)result;
        return result;
    }

    result = pathSystem.findTilePath((int)this->exceptionPathValue.lastWaypoint()->x,
                                     (int)this->exceptionPathValue.lastWaypoint()->y, (int)goal->world_x, (int)goal->world_y, this, aRange, targetID2, 0,
                                     pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
    this->storePathInExceptionPath = 0;
    return result;
}

int RGE_Moving_Object::canPathWithObstructions(
    int targetID, float aRange, float* pathDistance, int aiCheck,
    int unobstructiblePlayerID, int unobstructibleGroupID,
    ManagedArray<int>& obstructions) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(this->owner->world->terrains[this->master_obj->terrain],
                                                         this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zone_map == 0) {
        return 0;
    }

    int start_zone = zone_map->get_zone_info((long)this->world_x, (long)this->world_y);
    int goal_zone = zone_map->get_zone_info((long)target->world_x, (long)target->world_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = (int)target->world_x;
        goal.y = (int)target->world_y;

        if (zone_map->withinRange(start, goal, aRange) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    if (aiCheck != 0) {
        aiPathSystem.incrementCanPaths();
        int result = aiPathSystem.findTilePath((int)this->world_x, (int)this->world_y,
                                               (int)target->world_x, (int)target->world_y, this, aRange, targetID, 1, pathDistance, 1, 1, 1, 1,
                                               unobstructiblePlayerID, unobstructibleGroupID);
        if (unobstructibleGroupID != -1) {
            aiPathSystem.copyUnobstructibles(obstructions);
        }
        this->storePathInExceptionPath = 0;
        return result;
    } else {
        pathSystem.incrementCanPaths();
        int result = pathSystem.findTilePath((int)this->world_x, (int)this->world_y,
                                             (int)target->world_x, (int)target->world_y, this, aRange, targetID, 1, pathDistance, 1, 1, 1, 1,
                                             unobstructiblePlayerID, unobstructibleGroupID);
        if (unobstructibleGroupID != -1) {
            pathSystem.copyUnobstructibles(obstructions);
        }
        this->storePathInExceptionPath = 0;
        return result;
    }
}

int RGE_Moving_Object::canPathWithAdditionalPassability(
    XYZPoint p, float aRange, int targetID, float* pathDistance,
    int eTerrain1, int eTerrain2, int aiCheck,
    int unobstructiblePlayerID, int unobstructibleGroupID) {
    if (p.x < 0 || p.y < 0 || p.x >= this->owner->world->map->map_width || p.y >= this->owner->world->map->map_height) {
        return 0;
    }

    this->currentTerrainException1 = eTerrain1;
    this->currentTerrainException2 = eTerrain2;
    this->storePathInExceptionPath = 1;

    int result;
    if (aiCheck != 0) {
        aiPathSystem.incrementCanPaths();
        result = aiPathSystem.findTilePath((int)this->world_x, (int)this->world_y, p.x, p.y, this,
                                           aRange, targetID, 1, pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
    } else {
        pathSystem.incrementCanPaths();
        result = pathSystem.findTilePath((int)this->world_x, (int)this->world_y, p.x, p.y, this,
                                         aRange, targetID, 1, pathDistance, 1, 1, 1, 1, unobstructiblePlayerID, unobstructibleGroupID);
    }

    this->storePathInExceptionPath = 0;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    return result;
}

int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(
    int eTerrain, float* rX, float* rY) {
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
        if (this->firstTileAlongLine((const XYPoint&)p1, (const XYPoint&)p2, rVal, eTerrain, eTerrain, 1) == 1) {
            //! @bug The original writes the x result to both output pointers.
            float result = (float)rVal.x - g_move_negative_half_float;
            *rX = result;
            *rY = result;
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

    *rX = -1.0f;
    *rY = -1.0f;
    return 0;
}

int RGE_Moving_Object::canLinePath(const XYPoint& s, const XYPoint& d,
                                   float range, XYPoint& rPoint,
                                   int aiCheck) {
    int lastX;
    int priorY;
    float xDistance;
    float yDistance;
    int startX = s.x;
    int endX = d.x;
    int startY = s.y;
    int endY = d.y;

    xDistance = (float)(endX - startX);
    yDistance = (float)(endY - startY);

    if ((xDistance == g_move_zero_angle) && (yDistance == g_move_zero_angle)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float xTile;
    float yTile;

    if (fabs(yDistance) > fabs(xDistance)) {
        numSteps = abs((int)yDistance) * 2;
    } else {
        numSteps = abs((int)xDistance) * 2;
    }

    lastX = -999;
    priorY = -999;
    i = 0;
    xStep = 0.0f;
    xStep = xDistance / (float)numSteps;
    yStep = yDistance / (float)numSteps;
    xTile = (float)startX;
    yTile = (float)startY;

    for (; i < numSteps; ++i) {
        xTile += xStep;
        yTile += yStep;
        int tile_x = (int)xTile;
        int tile_y = (int)yTile;

        if (tile_x != lastX || tile_y != priorY) {
            lastX = tile_x;
            priorY = tile_y;
            if (this->passableTile(xTile, yTile, aiCheck) == 0) {
                rPoint.x = tile_x;
                rPoint.y = tile_y;
                return 0;
            }

            if ((float)sqrt(((float)d.x - xTile) * ((float)d.x - xTile) + ((float)d.y - yTile) * ((float)d.y - yTile)) <=
                range) {
                return 1;
            }
        }
    }

    return 1;
}

int RGE_Moving_Object::canLinePath(int sX, int sY, int dX, int dY,
                                   float range, int aiCheck) {
    int lastX;
    int lastY;
    float xDistance = (float)(dX - sX);
    float yDistance = (float)(dY - sY);

    if ((xDistance == g_move_zero_angle) && (yDistance == g_move_zero_angle)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float xTile;
    float yTile;

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

    xTile = (float)sX;
    yTile = (float)sY;

    for (i = 0; i < numSteps; ++i) {
        xTile += xStep;
        yTile += yStep;
        int tile_x = (int)xTile;
        int tile_y = (int)yTile;

        if (tile_x != lastX || tile_y != lastY) {
            lastX = tile_x;
            lastY = tile_y;
            if (this->passableTile(xTile, yTile, aiCheck) == 0) {
                return 0;
            }

            if ((float)sqrt(((float)dX - xTile) * ((float)dX - xTile) + ((float)dY - yTile) * ((float)dY - yTile)) <=
                range) {
                return 1;
            }
        }

    }

    return 1;
}

int RGE_Moving_Object::firstTileAlongLine(const XYPoint& s,
                                           const XYPoint& d,
                                           XYPoint& rPoint,
                                           int tType1, int tType2,
                                           int checkPassability) {
    int lastX;
    int lastY;
    float xDistance = (float)(d.x - s.x);
    float yDistance = (float)(d.y - s.y);

    if ((xDistance == g_move_zero_angle) && (yDistance == g_move_zero_angle)) {
        return 0;
    }

    int numSteps;
    int i;
    float xStep;
    float yStep;
    float xTile;
    float yTile;
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
    xTile = (float)s.x;
    yTile = (float)s.y;
    map = this->owner->world->map;

    while (i < numSteps) {
        xTile += xStep;
        yTile += yStep;
        int tile_x = (int)xTile;
        int tile_y = (int)yTile;

        if ((tile_x != lastX) || (tile_y != lastY)) {
            lastX = tile_x;
            lastY = tile_y;
            tileType = map->get_terrain((short)tile_x, (short)tile_y);
            if (((int)tileType == tType1 || (int)tileType == tType2) && (checkPassability == 1)) {
                if (this->passableTile(xTile, yTile, 0) == 1) {
                    rPoint.x = tile_x;
                    rPoint.y = tile_y;
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

unsigned char RGE_Moving_Object::waitingToMove(void) const {
    unsigned int state = this->actionState();

    if ((state == 6) || (state == 7)) {
        return 0;
    }
    return this->waitingToMoveValue;
}

void RGE_Moving_Object::setWaitingToMove(unsigned char w) { this->waitingToMoveValue = w; }

XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int v) {
    if (v < 0 || v >= numberUserDefinedWaypointsValue) return 0;
    return (XYZBYTEPoint*)((char*)userDefinedWaypoints + v * 3);
}

int RGE_Moving_Object::addUserDefinedWaypoint(XYZBYTEPoint* p, int stopObject) {
    if (this->finalUserDefinedWaypoint == 1) {
        this->removeAllUserDefinedWaypoints(stopObject);
        this->finalUserDefinedWaypoint = 0;
    }

    if (this->maxUserDefinedWaypointsValue > this->numberUserDefinedWaypointsValue) {
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].x = p->x;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].y = p->y;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].z = p->z;
    } else {
        if (this->maxUserDefinedWaypointsValue == 0) {
            this->userDefinedWaypoints =
                (XYZBYTEPoint*)operator new(0x0F);
            this->maxUserDefinedWaypointsValue = 5;
            this->numberUserDefinedWaypointsValue = 0;
        } else {
            XYZBYTEPoint* newWaypoints = (XYZBYTEPoint*)operator new(this->maxUserDefinedWaypointsValue * 6);
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
            this->numberUserDefinedWaypointsValue].x = p->x;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].y = p->y;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].z = p->z;
    }

    ++this->numberUserDefinedWaypointsValue;
    return 1;
}

void RGE_Moving_Object::removeAllUserDefinedWaypoints(int stopObject) {
    this->numberUserDefinedWaypointsValue = 0;
    if (stopObject == 1 && this->unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", this->id, "C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xb59);
        }
        this->unitAIValue->stopObject(0);
    }
}

void RGE_Moving_Object::removeUserDefinedWaypoint(int v) {
    int i;

    if (v < 0 || v >= numberUserDefinedWaypointsValue) return;
    for (i = 0; i < numberUserDefinedWaypointsValue && i < v; i++) {
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

Path* RGE_Moving_Object::findAvoidancePath(XYZPoint& goalPoint, float aRange,
                                           int targetID) {
    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(this->owner->world->terrains[this->master_obj->terrain],
                                                         this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);

    int start_zone = zone_map->get_zone_info((long)this->world_x, (long)this->world_y);
    int goal_zone =
        zone_map->get_zone_info(goalPoint.x, goalPoint.y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = goalPoint.x;
        goal.y = goalPoint.y;

        if (zone_map->withinRange(start, goal, aRange) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    aiPathSystem.findTilePath((int)this->world_x, (int)this->world_y, goalPoint.x, goalPoint.y,
                              this, aRange, targetID, 1, 0, 0, 1, 1, 1, -1, -1);
    this->storePathInExceptionPath = 0;
    aiPathSystem.initMisc(0);
    return &this->exceptionPathValue;
}

void RGE_Moving_Object::setInitialPoints(XYPoint& min, XYPoint& max) {
    this->minInitialPointValue.x = min.x;
    this->minInitialPointValue.y = min.y;
    this->maxInitialPointValue.x = max.x;
    this->maxInitialPointValue.y = max.y;
}

void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* source2) {
    RGE_Sprite* sprite = 0;
    RGE_Master_Moving_Object* old_master = (RGE_Master_Moving_Object*)this->master_obj;
    RGE_Master_Moving_Object* new_master = (RGE_Master_Moving_Object*)source2;

    if (this->sprite == old_master->move_sprite) {
        sprite = new_master->move_sprite;
    } else if (this->sprite == old_master->run_sprite) {
        sprite = new_master->run_sprite;
    }
    if (sprite != 0) {
        this->new_sprite(sprite);
    }
    // The sprite call at 00460D99 is virtual. The final call at 00460D9F
    // directly targets RGE_Static_Object::copy_obj at 004C4FB0.
    RGE_Static_Object::copy_obj(source2);
}

void RGE_Moving_Object::boundAngle(float* x, int numFacets) {
    float wrappedAngle = *x;

    if (*x < g_move_zero_angle) {
        do {
            wrappedAngle -= g_move_negative_two_pi;
        } while (wrappedAngle < g_move_zero_angle);
        *x = wrappedAngle;
    } else {
        while (wrappedAngle > 6.2831855f) {
            *x = wrappedAngle = *x - 6.2831855f;
        }
    }

    if (numFacets != -1) {
        float bestDifference;
        if (numFacets == 8) {
            bestDifference = 0.785398185f;
        } else {
            bestDifference = 0.392699093f;
        }

        int bestFacet = -1;
        int i = 0;
        if (numFacets >= 0) {
            do {
                float difference = *x - (float)i * bestDifference;
                if (difference < g_move_zero_double) {
                    difference = -difference;
                }
                if (difference < bestDifference) {
                    bestDifference = difference;
                    bestFacet = i;
                }
                if (bestDifference < g_move_angle_tolerance) {
                    break;
                }
                ++i;
            } while (i <= numFacets);
        }

        if (numFacets == 8) {
            *x = (float)bestFacet * g_move_quarter_pi;
        } else {
            *x = (float)bestFacet * g_move_facet_angle;
        }
    }
}

void RGE_Moving_Object::rotate(long amount) {
    RGE_Sprite* sprite;
    float angle2;

    sprite = this->sprite;
    angle2 = (float)(((double)amount * 6.2831853) / (double)sprite->facet_num) + this->angle;

    if (angle2 < 0.0f) {
        do {
            angle2 += 6.2831853f;
        } while (angle2 < 0.0f);
    }
    if (angle2 >= 6.2831853) {
        do {
            angle2 -= 6.2831853f;
        } while (angle2 >= 6.2831853);
    }

    this->new_angle(angle2);
}

long RGE_Moving_Object::get_waypoint_checksum() {
    float temp = 0.0f;
    Path* path = &this->pathValue;
    int savedIndex = path->currentWaypointNumber();
    path->initToStart();
    int i = 0;
    if (path->numberOfWaypoints() > 0) {
        do {
            // Keep currentWaypoint calls at 00460F72 and 00460F7B. The binary
            // uses y(first) + x(second) + temp at 00460F80, 00460F83, and 00460F88.
            Waypoint* yWaypoint = path->currentWaypoint();
            Waypoint* xWaypoint = path->currentWaypoint();
            float waypointSum = yWaypoint->y + xWaypoint->x;
            temp += waypointSum;
            i++;
            path->moveToNextWaypoint();
        } while (i < path->numberOfWaypoints());
    }
    path->setCurrentWaypointNumber(savedIndex);
    return (long)(int)temp;
}
