#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Player.h"
#include "../include/debug_helpers.h"
#include "../include/XYZBYTEPoint.h"
#include "../include/globals.h"

#include <math.h>
#include <string.h>

static const float kPi = 3.14159265f;
static const float kTwoPi = 6.2831855f;
static const float kInvTwoPi = 0.15915494f;

// Helper to zero-init Moving_Object specific fields
static void rge_moving_ctor_common_init(RGE_Moving_Object* obj) {
    obj->rangeStatusValue = 2;
    obj->currentTerrainException1 = -1;
    obj->currentTerrainException2 = -1;
    obj->storePathInExceptionPath = '\0';
    obj->waitingToMoveValue = '\0';
    obj->numberWaitDelays = '\0';
    obj->userDefinedWaypoints = nullptr;
    obj->numberUserDefinedWaypointsValue = 0;
    obj->maxUserDefinedWaypointsValue = 0;
    obj->finalUserDefinedWaypoint = '\0';
    obj->startValue.x = 0.0f;
    obj->startValue.y = 0.0f;
    obj->startValue.z = 0.0f;
    obj->setGoal(0.0f, 0.0f, 0.0f);
    obj->turnTimer = 0.0f;
    obj->lastFacet = 0xFF;
    obj->lastFacet2 = 0xFF;
    obj->collisionAvoidanceDistance = 0.0f;
    obj->actionRange = 0.0f;
    obj->targetIDValue = -1;
    obj->targetRadiusX = 0.0f;
    obj->targetRadiusY = 0.0f;
    obj->continueCounter = 0;
    obj->closestDistanceToWaypoint = 100000.0f;
}

// Default constructor
RGE_Moving_Object::RGE_Moving_Object()
    : RGE_Animated_Object(), pathValue(10), exceptionPathValue(10)
{
    rge_moving_ctor_common_init(this);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045C5C0
RGE_Moving_Object::RGE_Moving_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Animated_Object(param_1, param_2, 0), pathValue(10), exceptionPathValue(10)
{
    rge_moving_ctor_common_init(this);

    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D650
void RGE_Moving_Object::setGoal(float x, float y, float z) {
    this->goalValue.x = x;
    this->goalValue.y = y;
    this->goalValue.z = z;
}

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x0045D360
void RGE_Moving_Object::set_angle() {
    RGE_Sprite* spr = this->sprite;
    if (spr != nullptr) {
        short numFacets = *(short*)((char*)spr + 0x60);
        unsigned char flags = *(unsigned char*)((char*)spr + 0x70);
        if (((flags & 2) != 0) && numFacets > 0) {
            float idx = ((this->angle - (kPi * 0.5f)) * (float)numFacets * kInvTwoPi) - 0.5f;
            if (idx < 0.0f) {
                idx += (float)numFacets;
            }
            this->facet = (unsigned char)((int)idx);
            return;
        }
    }
    this->facet = 0;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045CAA0
int RGE_Moving_Object::setup(int param_1, RGE_Game_World* param_2) {
    int fd = param_1;

    RGE_Animated_Object::setup(fd, param_2);
    this->type = 0x1E;

    // Read movement fields
    rge_read(fd, &this->trail_remainder, 4);
    rge_read(fd, &this->velocity_x, 4);
    rge_read(fd, &this->velocity_y, 4);
    rge_read(fd, &this->velocity_z, 4);
    rge_read(fd, &this->angle, 4);
    rge_read(fd, &this->turn_towards_time, 4);

    // Read path waypoints
    int numWaypoints = 0;
    rge_read(fd, &numWaypoints, 4);
    for (int i = 0; i < numWaypoints; i++) {
        Waypoint temp;
        rge_read(fd, &temp, 0x10);
        this->pathValue.insertAtEnd(temp);
    }

    // Read current waypoint position and advance to it
    int currentWaypoint = 0;
    rge_read(fd, &currentWaypoint, 4);
    this->pathValue.initToStart();
    for (int i = 0; i < currentWaypoint; i++) {
        this->pathValue.moveToNextWaypoint();
    }

    // Read start/goal waypoints
    rge_read(fd, &this->startValue, 0x10);
    rge_read(fd, &this->goalValue, 0x10);

    // Read movement parameters
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

    // Read user-defined waypoints
    rge_read(fd, &this->numberUserDefinedWaypointsValue, 4);
    rge_read(fd, &this->maxUserDefinedWaypointsValue, 4);
    XYZBYTEPoint* udWp = (XYZBYTEPoint*)operator new(this->maxUserDefinedWaypointsValue * 3);
    this->userDefinedWaypoints = udWp;
    for (int i = 0; i < this->numberUserDefinedWaypointsValue; i++) {
        rge_read(fd, &this->userDefinedWaypoints[i], 3);
    }
    rge_read(fd, &this->finalUserDefinedWaypoint, 1);

    // Version-gated reads
    if (save_game_version < 1.3f) {
        this->minInitialPointValue.x = -1;
        this->minInitialPointValue.y = -1;
        this->maxInitialPointValue.x = -1;
        this->maxInitialPointValue.y = -1;
    } else {
        rge_read(fd, &this->minInitialPointValue, 8);
        rge_read(fd, &this->maxInitialPointValue, 8);
    }

    if (save_game_version < 7.22f) {
        this->closestDistanceToWaypoint = 100000.0f;
        this->lastFacet = 0xFF;
    } else {
        rge_read(fd, &this->closestDistanceToWaypoint, 4);
        rge_read(fd, &this->lastFacet, 1);
    }

    if (save_game_version >= 7.23f) {
        rge_read(fd, &this->lastFacet2, 1);
        return 1;
    }
    this->lastFacet2 = 0xFF;
    return 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045C700
RGE_Moving_Object::~RGE_Moving_Object() {
    if (this->userDefinedWaypoints != nullptr) {
        operator delete(this->userDefinedWaypoints);
        this->userDefinedWaypoints = nullptr;
    }
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045C790
void RGE_Moving_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2,
                                            float param_3, float param_4, float param_5) {
    Path emptyPath(10);
    this->pathValue = emptyPath;

    this->rangeStatusValue = 2;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    this->storePathInExceptionPath = '\0';
    this->waitingToMoveValue = '\0';
    this->numberWaitDelays = '\0';
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

    RGE_Animated_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);

    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    if (this->sprite != nullptr) {
        short numFacets = *(short*)((char*)this->sprite + 0x60);
        unsigned char flags = *(unsigned char*)((char*)this->sprite + 0x70);
        if (((flags & 2) != 0) && numFacets > 1) {
            int rv = debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xC5);
            float a = (kTwoPi / (float)numFacets) * (float)((rv * numFacets) / 0x7FFF);
            this->angle = a;
            if (a < 0.0f) {
                this->angle = a + kTwoPi;
            } else if (a > kTwoPi) {
                this->angle = a - kTwoPi;
            }
        }
    }
    set_angle();
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045C970
int RGE_Moving_Object::setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3,
                             float param_4, float param_5) {
    RGE_Animated_Object::setup((RGE_Master_Animated_Object*)param_1, param_2, param_3, param_4, param_5);
    this->type = 0x1E;

    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    if (this->sprite != nullptr) {
        short numFacets = *(short*)((char*)this->sprite + 0x60);
        unsigned char flags = *(unsigned char*)((char*)this->sprite + 0x70);
        if (((flags & 2) != 0) && numFacets > 1) {
            int rv = debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xDE);
            float a = (kTwoPi / (float)numFacets) * (float)((rv * numFacets) / 0x7FFF);
            this->angle = a;
            if (a < 0.0f) {
                this->angle = a + kTwoPi;
                set_angle();
                return 1;
            }
            if (a > kTwoPi) {
                this->angle = a - kTwoPi;
                set_angle();
                return 1;
            }
        }
    }

    set_angle();
    return 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045CE00
void RGE_Moving_Object::save(int param_1) {
    RGE_Animated_Object::save(param_1);

    rge_write(param_1, &this->trail_remainder, 4);
    rge_write(param_1, &this->velocity_x, 4);
    rge_write(param_1, &this->velocity_y, 4);
    rge_write(param_1, &this->velocity_z, 4);
    rge_write(param_1, &this->angle, 4);
    rge_write(param_1, &this->turn_towards_time, 4);

    int numWaypoints = this->pathValue.numberOfWaypoints();
    rge_write(param_1, &numWaypoints, 4);
    for (int i = 0; i < numWaypoints; ++i) {
        Waypoint* wp = this->pathValue.waypoint(i);
        rge_write(param_1, wp, 0x10);
    }

    int currentWaypoint = this->pathValue.currentWaypointNumber();
    rge_write(param_1, &currentWaypoint, 4);

    rge_write(param_1, &this->startValue, 0x10);
    rge_write(param_1, &this->goalValue, 0x10);
    rge_write(param_1, &this->turnTimer, 4);
    rge_write(param_1, &this->collisionAvoidanceDistance, 4);
    rge_write(param_1, &this->actionRange, 4);
    rge_write(param_1, &this->targetIDValue, 4);
    rge_write(param_1, &this->targetRadiusX, 4);
    rge_write(param_1, &this->targetRadiusY, 4);
    rge_write(param_1, &this->continueCounter, 4);
    rge_write(param_1, &this->rangeStatusValue, 4);
    rge_write(param_1, &this->waitingToMoveValue, 1);
    rge_write(param_1, &this->numberWaitDelays, 1);
    rge_write(param_1, &this->numberUserDefinedWaypointsValue, 4);
    rge_write(param_1, &this->maxUserDefinedWaypointsValue, 4);

    for (int i = 0; i < this->numberUserDefinedWaypointsValue; ++i) {
        rge_write(param_1, &this->userDefinedWaypoints[i], 3);
    }

    rge_write(param_1, &this->finalUserDefinedWaypoint, 1);
    rge_write(param_1, &this->minInitialPointValue, 8);
    rge_write(param_1, &this->maxInitialPointValue, 8);
    rge_write(param_1, &this->closestDistanceToWaypoint, 4);
    rge_write(param_1, &this->lastFacet, 1);
    rge_write(param_1, &this->lastFacet2, 1);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D080
void RGE_Moving_Object::new_sprite(RGE_Sprite* param_1) {
    if (param_1 == nullptr) {
        param_1 = this->master_obj->sprite;
    }

    if (this->sprite != param_1) {
        RGE_Static_Object::new_sprite(param_1);
        set_angle();
    }
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D0B0
RGE_Static_Object* RGE_Moving_Object::spawn_death_obj() {
    RGE_Static_Object* obj = RGE_Static_Object::spawn_death_obj();
    if (obj != nullptr && obj->master_obj->master_type > 0x1D) {
        obj->new_angle(this->angle);
    }
    return obj;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D0E0
void RGE_Moving_Object::transform(RGE_Master_Static_Object* param_1) {
    RGE_Animated_Object::transform(param_1);
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->collisionAvoidanceDistance = 0.0f;
    this->turnTimer = 0.0f;
    this->turn_towards_time = 0.0f;
    set_angle();
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D120
uchar RGE_Moving_Object::is_moving() {
    return (this->speed > 0.0f) ? 1 : 0;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D140
void RGE_Moving_Object::stop_moving() {
    this->speed = 0.0f;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D150
float RGE_Moving_Object::angle_to_object(RGE_Static_Object* param_1, float param_2, float param_3) {
    if (this->sprite == nullptr) {
        return 0.0f;
    }

    short numFacets = *(short*)((char*)this->sprite + 0x60);
    unsigned char flags = *(unsigned char*)((char*)this->sprite + 0x70);
    if (((flags & 2) == 0) || numFacets <= 0) {
        return 0.0f;
    }

    if (param_1 != nullptr) {
        param_2 = param_1->world_x;
        param_3 = param_1->world_y;
    }

    float a = atan2f(param_3 - this->world_y, param_2 - this->world_x);
    if (a < 0.0f) {
        a += kTwoPi;
    }

    float d = a - this->angle;
    if (d > kPi) {
        d -= kTwoPi;
    }
    if (d < -kPi) {
        d += kTwoPi;
    }

    return ((float)numFacets * kInvTwoPi) * d;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D1F0
uchar RGE_Moving_Object::turn_towards(RGE_Static_Object* param_1, float param_2, float param_3) {
    float delta = angle_to_object(param_1, param_2, param_3);
    if (delta <= 0.5f && delta >= -0.5f) {
        return 1;
    }

    float now = (float)this->owner->world->world_time * 0.001f;
    if (now - this->turn_towards_time < ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed) {
        return 0;
    }

    short numFacets = *(short*)((char*)this->sprite + 0x60);
    if (delta >= 0.0f) {
        this->angle = this->angle + (kTwoPi / (float)numFacets);
    } else {
        this->angle = this->angle - (kTwoPi / (float)numFacets);
    }

    if (this->angle < 0.0f) {
        this->angle += kTwoPi;
    } else if (this->angle > kTwoPi) {
        this->angle -= kTwoPi;
    }

    set_angle();
    this->turn_towards_time = now;
    delta = angle_to_object(param_1, param_2, param_3);
    return (delta < 0.5f && delta >= -0.5f) ? 1 : 0;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D5C0
void RGE_Moving_Object::set_velocity(float param_1, float param_2, float param_3) {
    this->velocity_x = param_1;
    this->velocity_y = param_2;
    this->velocity_z = param_3;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D5F0
void RGE_Moving_Object::new_angle(float param_1) {
    this->angle = param_1;
    set_angle();
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D610
const Path& RGE_Moving_Object::getPath() const {
    return this->pathValue;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D620
uchar RGE_Moving_Object::facetToNextWaypoint() {
    Waypoint* wp = this->pathValue.currentWaypoint();
    if (wp != nullptr) {
        return wp->facetToNextWaypoint;
    }
    return 0xFF;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D680
void RGE_Moving_Object::setActionRange(float param_1) {
    this->actionRange = param_1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D690
void RGE_Moving_Object::setTargetID(int param_1) {
    this->targetIDValue = param_1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D6A0
void RGE_Moving_Object::setTargetRadius(float param_1, float param_2) {
    this->targetRadiusX = param_1;
    this->targetRadiusY = param_2;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x004608D0
float RGE_Moving_Object::maximumSpeed() {
    if (this->master_obj != nullptr && this->speed > 0.0f) {
        return ((RGE_Master_Animated_Object*)this->master_obj)->speed * this->speed;
    }
    return ((RGE_Master_Animated_Object*)this->master_obj)->speed;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460900
uchar RGE_Moving_Object::waitingToMove() {
    uchar state = this->actionState();
    if (state == 6 || state == 7) {
        return 0;
    }
    return this->waitingToMoveValue;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460930
void RGE_Moving_Object::setWaitingToMove(uchar param_1) {
    this->waitingToMoveValue = param_1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460940
XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int param_1) {
    if (param_1 >= 0 && param_1 < this->numberUserDefinedWaypointsValue) {
        return this->userDefinedWaypoints + param_1;
    }
    return nullptr;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460970
int RGE_Moving_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) {
    if (this->finalUserDefinedWaypoint == 1) {
        this->stopAction();
        this->finalUserDefinedWaypoint = 0;
    }

    if (this->numberUserDefinedWaypointsValue >= this->maxUserDefinedWaypointsValue) {
        if (this->maxUserDefinedWaypointsValue == 0) {
            this->userDefinedWaypoints = (XYZBYTEPoint*)operator new(0xF);
            this->maxUserDefinedWaypointsValue = 5;
            this->numberUserDefinedWaypointsValue = 0;
        } else {
            XYZBYTEPoint* newBuf = (XYZBYTEPoint*)operator new(this->maxUserDefinedWaypointsValue * 6);
            if (newBuf == nullptr) {
                return 0;
            }

            for (int i = 0; i < this->numberUserDefinedWaypointsValue; ++i) {
                newBuf[i] = this->userDefinedWaypoints[i];
            }
            int oldCount = this->numberUserDefinedWaypointsValue;
            this->maxUserDefinedWaypointsValue = this->maxUserDefinedWaypointsValue * 2;
            for (int i = oldCount; i < this->maxUserDefinedWaypointsValue; ++i) {
                newBuf[i].x = 0;
                newBuf[i].y = 0;
                newBuf[i].z = 0;
            }
            operator delete(this->userDefinedWaypoints);
            this->userDefinedWaypoints = newBuf;
        }
    }

    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue] = *param_1;
    this->numberUserDefinedWaypointsValue = this->numberUserDefinedWaypointsValue + 1;
    (void)param_2;
    return 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460B20
void RGE_Moving_Object::removeAllUserDefinedWaypoints(int param_1) {
    this->numberUserDefinedWaypointsValue = 0;
    if (param_1 == 1 && this->owner != nullptr) {
        if (actionFile != nullptr) {
            fprintf(actionFile, "  %d call stopObject %s(%d)\n", this->id,
                    "C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xB59);
        }
        this->stop();
    }
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460B70
void RGE_Moving_Object::removeUserDefinedWaypoint(int param_1) {
    if (param_1 < 0 || param_1 >= this->numberUserDefinedWaypointsValue) {
        return;
    }

    for (int i = param_1; i < this->numberUserDefinedWaypointsValue - 1; ++i) {
        this->userDefinedWaypoints[i] = this->userDefinedWaypoints[i + 1];
    }
    this->numberUserDefinedWaypointsValue = this->numberUserDefinedWaypointsValue - 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045D6xx + 0x00405F60
int RGE_Moving_Object::numberUserDefinedWaypoints() {
    return this->numberUserDefinedWaypointsValue;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460BF0
void RGE_Moving_Object::setFinalUserDefinedWaypoint() {
    this->finalUserDefinedWaypoint = 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460D30
void RGE_Moving_Object::setInitialPoints(XYPoint* param_1, XYPoint* param_2) {
    this->minInitialPointValue.x = param_1->x;
    this->minInitialPointValue.y = param_1->y;
    this->maxInitialPointValue.x = param_2->x;
    this->maxInitialPointValue.y = param_2->y;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460D60
void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    RGE_Static_Object::copy_obj(param_1);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460DB0
void RGE_Moving_Object::boundAngle(float* param_1, int param_2) {
    float angleValue = *param_1;
    if (angleValue >= 0.0f) {
        while (angleValue > kTwoPi) {
            angleValue -= kTwoPi;
        }
    } else {
        do {
            angleValue += kTwoPi;
        } while (angleValue < 0.0f);
    }
    *param_1 = angleValue;

    if (param_2 != -1) {
        float best = (param_2 == 8) ? 0.7853982f : 0.3926991f;
        int bestIndex = -1;
        for (int i = 0; i <= param_2; ++i) {
            float d = *param_1 - ((float)i * best);
            if (d < 0.0f) {
                d = -d;
            }
            if (d < best) {
                best = d;
                bestIndex = i;
            }
            if (best < 0.1f) {
                break;
            }
        }

        if (param_2 == 8) {
            *param_1 = (float)bestIndex * 0.7853982f;
        } else {
            *param_1 = (float)bestIndex * 0.3926991f;
        }
    }
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460EB0
void RGE_Moving_Object::rotate(long param_1) {
    short numFacets = *(short*)((char*)this->sprite + 0x60);
    float a = (((float)param_1 * kTwoPi) / (float)numFacets) + this->angle;
    while (a < 0.0f) {
        a += kTwoPi;
    }
    while (a >= kTwoPi) {
        a -= kTwoPi;
    }
    this->new_angle(a);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00405F50
float RGE_Moving_Object::getAngle() {
    return this->angle;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460F40
long RGE_Moving_Object::get_waypoint_checksum() {
    Path* p = &this->pathValue;
    int saved = p->currentWaypointNumber();
    p->initToStart();

    float temp = 0.0f;
    int i = 0;
    int n = p->numberOfWaypoints();
    while (i < n) {
        Waypoint* w0 = p->currentWaypoint();
        Waypoint* w1 = p->currentWaypoint();
        temp += w0->y + w1->x;
        i = i + 1;
        p->moveToNextWaypoint();
        n = p->numberOfWaypoints();
    }

    p->setCurrentWaypointNumber(saved);
    return (long)temp;
}
