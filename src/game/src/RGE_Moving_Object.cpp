#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/XYZBYTEPoint.h"
#include "../include/globals.h"

#include <string.h>

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
// Computes facet from angle based on sprite's number of facets.
void RGE_Moving_Object::set_angle() {
    // From ASM: reads this->sprite (offset 0x10), checks sprite->flags (offset 0x70)
    // and sprite->num_facets (offset 0x60). Computes facet = (angle / 2PI) * num_facets.
    // For now, simple stub that sets facet to 0 if no sprite info.
    RGE_Sprite* spr = this->sprite;
    if (spr != nullptr) {
        short* pNumFacets = (short*)((char*)spr + 0x60);
        unsigned char* pFlags = (unsigned char*)((char*)spr + 0x70);
        if ((*pFlags & 2) != 0 && *pNumFacets > 0) {
            short numFacets = *pNumFacets;
            float adjusted = (this->angle - 1.5707964f) * (float)numFacets * (1.0f / 6.2831855f) - 0.5f;
            if (adjusted < 0.0f) {
                adjusted += (float)numFacets;
            }
            this->facet = (unsigned char)(int)adjusted;
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
