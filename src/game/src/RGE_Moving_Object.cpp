#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/PathingSystem.h"
#include "../include/RGE_Zone_Map.h"
#include "../include/RGE_Zone_Map_List.h"
#include "../include/debug_helpers.h"
#include "../include/XYZBYTEPoint.h"
#include "../include/globals.h"

#include <math.h>
#include <string.h>

static const float kPi = 3.14159265f;
static const float kTwoPi = 6.2831855f;
static const float kInvTwoPi = 0.15915494f;

static int rge_ftol(float value) {
    return (int)(long)value;
}

static float rge_tile_center(float value) {
    return (float)floor((double)value) + 0.5f;
}

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

// Fully verified. Source of truth: obj_list.cpp.asm @ 0x00463055
void RGE_Moving_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4) {
    RGE_Animated_Object::draw(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: obj_list.cpp.asm @ 0x00463139
void RGE_Moving_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {
    RGE_Animated_Object::shadow_draw(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: obj_list.cpp.asm @ 0x004631ba
void RGE_Moving_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3) {
    RGE_Animated_Object::normal_draw(param_1, param_2, param_3);
}

// Fully verified. Source of truth: obj_list.cpp.asm @ 0x00463227
uchar RGE_Moving_Object::update() {
    return RGE_Animated_Object::update();
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

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x0045D3D0
float RGE_Moving_Object::teleport(float param_1, float param_2, float param_3) {
    RGE_Master_Moving_Object* master = (RGE_Master_Moving_Object*)this->master_obj;
    if (master != nullptr) {
        unsigned char trail_options = master->obj_trail_options;
        if (trail_options != 0 && this->owner != nullptr && this->owner->master_objects != nullptr) {
            short trail_id = master->obj_trail_id;
            if (trail_id >= 0) {
                RGE_Master_Static_Object* trail_master = this->owner->master_objects[trail_id];
                if (trail_master != nullptr) {
                    if (trail_options == 1) {
                        RGE_Static_Object* trail_obj = trail_master->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
                        if (trail_obj != nullptr && trail_obj->master_obj != nullptr && trail_obj->master_obj->id > 0x1E) {
                            trail_obj->new_angle(this->angle);
                        }
                    } else if (trail_options == 2) {
                        float dx = param_1 - this->world_x;
                        float dy = param_2 - this->world_y;
                        float dz = param_3 - this->world_z;

                        float dist = sqrtf(dx * dx + dy * dy + dz * dz) + this->trail_remainder;
                        float spacing = master->obj_trail_spacing;
                        short count = (spacing != 0.0f) ? (short)(long)(dist / spacing) : 0;
                        if (count < 1) {
                            this->trail_remainder = dist;
                        } else {
                            float step_count = (float)(int)count;
                            float step_x = dx / step_count;
                            float step_y = dy / step_count;
                            float step_z = dz / step_count;

                            float tx = this->world_x;
                            float ty = this->world_y;
                            float tz = this->world_z;
                            for (short i = 0; i < count; ++i) {
                                RGE_Static_Object* trail_obj = trail_master->make_new_obj(this->owner, tx, ty, tz);
                                if (trail_obj != nullptr && trail_obj->master_obj != nullptr && trail_obj->master_obj->id > 0x1E) {
                                    trail_obj->new_angle(this->angle);
                                }
                                ty += step_y;
                                tx += step_x;
                                tz += step_z;
                            }

                            this->trail_remainder = dist - (spacing * step_count);
                        }
                    }
                }
            }
        }
    }

    return RGE_Static_Object::teleport(param_1, param_2, param_3);
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

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x0045D6C0
RGE_Moving_Object::PathResult RGE_Moving_Object::findPath() {
    RGE_Master_Static_Object* master = this->master_obj;
    if (master != nullptr && master->radius_z <= 0.0f) {
        this->setWaitingToMove(0);
        this->startValue.x = this->world_x;
        this->startValue.y = this->world_y;
        this->startValue.z = this->world_z;
        this->pathingGroupMembers.numberValue = 0;

        if (this->owner != nullptr && this->owner->world != nullptr) {
            this->pathValue.setTimeStamp((ulong)this->owner->world->world_time);
        }
        this->pathValue.killPath();
        (void)this->pathValue.insertAtCurrent(this->goalValue);
        (void)this->pathValue.insertAtCurrent(this->startValue);
        this->pathValue.initToStart();
        (void)this->pathValue.moveToNextWaypoint();
        this->closestDistanceToWaypoint = 100000.0f;
        return PathFound;
    }

    if (this->owner == nullptr) {
        this->pathingGroupMembers.numberValue = 0;
        this->setWaitingToMove(0);
        return PathFailed;
    }

    if (this->owner->availablePathingAttempts((uint)this->numberWaitDelays) == 0) {
        this->numberWaitDelays = (uchar)(this->numberWaitDelays + 1);
        return WaitingOnPathingCap;
    }

    this->owner->incrementPathingAttempts();
    this->numberWaitDelays = 0;
    this->setWaitingToMove(0);

    if (this->owner->computerPlayer() == 0) {
        this->continueCounter = this->numberUserDefinedWaypointsValue + 0x19;
    } else {
        this->continueCounter = this->numberUserDefinedWaypointsValue + 0x0F;
    }

    this->startValue.x = this->world_x;
    this->startValue.y = this->world_y;
    this->startValue.z = this->world_z;
    this->closestDistanceToWaypoint = 100000.0f;

    pathSystem.incrementInitialPaths();

    int goal_y;
    int goal_x;
    if (this->numberUserDefinedWaypointsValue < 1) {
        goal_y = rge_ftol(this->goalValue.y);
        goal_x = rge_ftol(this->goalValue.x);
    } else {
        goal_y = (int)this->userDefinedWaypoints[0].y;
        goal_x = (int)this->userDefinedWaypoints[0].x;
    }

    int start_y = rge_ftol(this->startValue.y);
    int start_x = rge_ftol(this->startValue.x);

    int path_ok = pathSystem.findTilePath(start_x, start_y, goal_x, goal_y, this, this->actionRange, this->targetIDValue, 1, nullptr, 1, 1, 1, 1, -1, -1);

    if (actionFile != nullptr) {
        fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)",
                (long)this->owner->world->world_time, (int)this->id, (double)this->startValue.x, (double)this->startValue.y, (double)this->goalValue.x,
                (double)this->goalValue.y);

        this->pathValue.initToStart();
        int i = 0;
        int n = this->pathValue.numberOfWaypoints();
        while (i < n) {
            Waypoint* wp = this->pathValue.currentWaypoint();
            if (wp != nullptr) {
                fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, (double)wp->x, (double)wp->y);
            }
            i = i + 1;
            this->pathValue.moveToNextWaypoint();
            n = this->pathValue.numberOfWaypoints();
        }
        fprintf(actionFile, ".\n");
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
    }

    if ((path_ok == 0) && (this->pathValue.numberOfWaypoints() == 1)) {
        float center_x = rge_tile_center(this->world_x);
        float center_y = rge_tile_center(this->world_y);
        if (pathSystem.passable(this, center_x, center_y, 1) != 0) {
            float frac_x = this->world_x - (float)floor((double)this->world_x);
            float frac_y = this->world_y - (float)floor((double)this->world_y);
            if ((frac_x != 0.5f) || (frac_y != 0.5f)) {
                (void)this->teleport(center_x, center_y, this->world_z);
                return WaitingOnPathingCap;
            }
        }
    }

    if (this->owner->world != nullptr) {
        this->pathValue.setTimeStamp((ulong)this->owner->world->world_time);
    }

    if ((displayPathingFlags != 0) && ((this->selected & 1) != 0)) {
        this->pathValue.initToStart();
        int i = 0;
        int n = this->pathValue.numberOfWaypoints();
        while (i < n) {
            RGE_Master_Static_Object* marker_master = (this->owner->master_objects != nullptr) ? this->owner->master_objects[displayPathObjectID] : nullptr;
            Waypoint* wp = this->pathValue.currentWaypoint();
            if (marker_master != nullptr && wp != nullptr) {
                marker_master->make_new_obj(this->owner, wp->x, wp->y, 1.0f);
            }
            i = i + 1;
            this->pathValue.moveToNextWaypoint();
            n = this->pathValue.numberOfWaypoints();
        }
        this->pathValue.initToStart();
        this->pathValue.moveToNextWaypoint();
    }

    this->pathValue.initToStart();
    this->pathValue.moveToNextWaypoint();
    return PathFound;
}

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x0045DB90
int RGE_Moving_Object::doMove() {
    this->setWaitingToMove(0);

    RGE_Master_Static_Object* master = this->master_obj;
    float dx = this->goalValue.x - this->world_x;
    float dy = this->goalValue.y - this->world_y;
    if (dx < 0.0f) {
        dx = -dx;
    }
    if (dy < 0.0f) {
        dy = -dy;
    }

    float rx = (master != nullptr) ? master->radius_x : 0.0f;
    float ry = (master != nullptr) ? master->radius_y : 0.0f;

    dx = dx - (this->targetRadiusX + rx);
    dy = dy - (this->targetRadiusY + ry);
    if (dx < 0.0f) {
        dx = 0.0f;
    }
    if (dy < 0.0f) {
        dy = 0.0f;
    }

    float distance_to_goal = sqrtf(dy * dy + dx * dx);

in_range:
    if ((0.0f < this->actionRange) && (distance_to_goal <= this->actionRange)) {
        this->speed = 0.0f;
        this->rangeStatusValue = 1;
        this->removeAllUserDefinedWaypoints(0);
        this->speed = 0.0f;
        return 2;
    }

    if (distance_to_goal < 0.5f) {
        float cur_wp_dist = distance_to_goal;
        Waypoint* cur_wp = this->pathValue.currentWaypoint();
        if (cur_wp != nullptr) {
            float wdx = cur_wp->x - this->world_x;
            float wdy = cur_wp->y - this->world_y;
            cur_wp_dist = sqrtf(wdy * wdy + wdx * wdx);
        }

        if (cur_wp_dist == 0.0f) {
            this->speed = 0.0f;
            return 2;
        }

        int trivial_result = this->doTrivialMove(this->goalValue.x, this->goalValue.y);
        if (trivial_result == 5) {
            distance_to_goal = 0.0f;
            goto in_range;
        }
        if (trivial_result == 0) {
            this->rangeStatusValue = 2;
            return 1;
        }
        if ((trivial_result == 1) || (trivial_result == 6)) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            return 1;
        }
        if ((trivial_result == 2) || (trivial_result == 3) || (trivial_result == 4)) {
            this->speed = 0.0f;
            distance_to_goal = 0.0f;
            goto in_range;
        }
    }

    // Ensure we have a non-degenerate current waypoint
    int have_waypoint = 1;
    float target_radius = sqrtf(ry * ry + rx * rx);
    Waypoint* cur_wp = this->pathValue.currentWaypoint();
    if (cur_wp == nullptr) {
        have_waypoint = 0;
    } else {
        float wdx = cur_wp->x - this->world_x;
        float wdy = cur_wp->y - this->world_y;
        if (sqrtf(wdy * wdy + wdx * wdx) == 0.0f) {
            if (pathSystem.passable(this, cur_wp->x, cur_wp->y, 1) != 0) {
                (void)this->teleport(cur_wp->x, cur_wp->y, cur_wp->z);
            }
            (void)this->pathValue.moveToNextWaypoint();
            this->closestDistanceToWaypoint = 100000.0f;
        }
    }

    float zone_distance_to_goal = 0.0f;
    if ((1 < this->numberUserDefinedWaypointsValue) && (4.0f < distance_to_goal)) {
        uchar z1 = this->lookupZone((int)this->userDefinedWaypoints[0].x, (int)this->userDefinedWaypoints[0].y);
        uchar z2 = this->lookupZone((int)this->userDefinedWaypoints[1].x, (int)this->userDefinedWaypoints[1].y);
        if (z1 == z2) {
            zone_distance_to_goal = 3.0f;
        }
    }

    if (have_waypoint == 0) {
        if (distance_to_goal <= zone_distance_to_goal + target_radius + this->actionRange) {
            this->speed = 0.0f;
            this->rangeStatusValue = 1;
            this->removeAllUserDefinedWaypoints(0);
            this->speed = 0.0f;
            return 2;
        }

        // Trim too-close user-defined waypoints
        for (;;) {
            this->removeUserDefinedWaypoint(0);
            if (this->numberUserDefinedWaypointsValue < 1) {
                return 0;
            }
            float udx = (float)this->userDefinedWaypoints[0].x - this->world_x;
            float udy = (float)this->userDefinedWaypoints[0].y - this->world_y;
            if ((target_radius + this->actionRange) + 0.3f < sqrtf(udy * udy + udx * udx)) {
                break;
            }
        }

        int old_continue = this->continueCounter;
        this->continueCounter = this->continueCounter - 1;
        if (this->continueCounter < 1) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
            }
            this->continueCounter = old_continue + 4;
            return 1;
        }

        if (this->owner->availablePathingAttempts((uint)this->numberWaitDelays) == 0) {
            this->speed = 0.0f;
            this->numberWaitDelays = (uchar)(this->numberWaitDelays + 1);
            return 1;
        }

        this->owner->incrementPathingAttempts();
        this->startValue.x = this->world_x;
        this->startValue.y = this->world_y;
        this->startValue.z = this->world_z;
        this->numberWaitDelays = 0;

        pathSystem.incrementContinuePaths();

        int goal_y;
        int goal_x;
        if (this->numberUserDefinedWaypointsValue < 1) {
            goal_y = rge_ftol(this->goalValue.y);
            goal_x = rge_ftol(this->goalValue.x);
        } else {
            goal_y = (int)this->userDefinedWaypoints[0].y;
            goal_x = (int)this->userDefinedWaypoints[0].x;
        }

        int start_y = rge_ftol(this->startValue.y);
        int start_x = rge_ftol(this->startValue.x);

        int path_ok = pathSystem.findTilePath(start_x, start_y, goal_x, goal_y, this, this->actionRange, this->targetIDValue, 1, nullptr, 1, 1, 1, 1, -1, -1);
        this->speed = 0.0f;

        if (actionFile != nullptr && this->owner->world != nullptr) {
            fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)",
                    (long)this->owner->world->world_time, (int)this->id, (double)this->startValue.x, (double)this->startValue.y, (double)this->goalValue.x,
                    (double)this->goalValue.y);
            this->pathValue.initToStart();
            int i = 0;
            int n = this->pathValue.numberOfWaypoints();
            while (i < n) {
                Waypoint* wp = this->pathValue.currentWaypoint();
                if (wp != nullptr) {
                    fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, (double)wp->x, (double)wp->y);
                }
                i = i + 1;
                this->pathValue.moveToNextWaypoint();
                n = this->pathValue.numberOfWaypoints();
            }
            fprintf(actionFile, ".\n");
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        if ((path_ok == 0) && (this->pathValue.numberOfWaypoints() == 1)) {
            float center_x = rge_tile_center(this->world_x);
            float center_y = rge_tile_center(this->world_y);
            if (pathSystem.passable(this, center_x, center_y, 1) != 0) {
                float frac_x = this->world_x - (float)floor((double)this->world_x);
                float frac_y = this->world_y - (float)floor((double)this->world_y);
                if ((frac_x == 0.5f) && (frac_y == 0.5f)) {
                    this->rangeStatusValue = 2;
                    if (this->numberUserDefinedWaypointsValue < 2) {
                        return 0;
                    }
                    this->continueCounter = this->continueCounter + 5;
                    return 1;
                }
                (void)this->teleport(center_x, center_y, this->world_z);
            }
        }

        if ((displayPathingFlags != 0) && ((this->selected & 1) != 0)) {
            this->pathValue.initToStart();
            int i = 0;
            int n = this->pathValue.numberOfWaypoints();
            while (i < n) {
                RGE_Master_Static_Object* marker_master = (this->owner->master_objects != nullptr) ? this->owner->master_objects[displayPathObjectID] : nullptr;
                Waypoint* wp = this->pathValue.currentWaypoint();
                if (marker_master != nullptr && wp != nullptr) {
                    marker_master->make_new_obj(this->owner, wp->x, wp->y, 1.0f);
                }
                i = i + 1;
                this->pathValue.moveToNextWaypoint();
                n = this->pathValue.numberOfWaypoints();
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
            this->continueCounter = this->continueCounter + 5;
            return 1;
        }

        this->closestDistanceToWaypoint = 100000.0f;
    }

    cur_wp = this->pathValue.currentWaypoint();
    if (cur_wp != nullptr) {
        int trivial_result = this->doTrivialMove(cur_wp->x, cur_wp->y);
        if (trivial_result == 5) {
            this->speed = 0.0f;
            distance_to_goal = 0.0f;
            goto in_range;
        }
        if (trivial_result == 0) {
            this->rangeStatusValue = 2;
            return 1;
        }
        if (trivial_result == 1) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            return 1;
        }
        if (trivial_result == 2) {
            if (this->pathValue.moveToNextWaypoint() == 0) {
                // Force a repath next update
                for (;;) {
                    this->removeUserDefinedWaypoint(0);
                    if (this->numberUserDefinedWaypointsValue < 1) {
                        return 0;
                    }
                    float udx = (float)this->userDefinedWaypoints[0].x - this->world_x;
                    float udy = (float)this->userDefinedWaypoints[0].y - this->world_y;
                    if ((target_radius + this->actionRange) + 0.3f < sqrtf(udy * udy + udx * udx)) {
                        break;
                    }
                }
                if (this->owner->availablePathingAttempts((uint)this->numberWaitDelays) == 0) {
                    this->speed = 0.0f;
                    this->numberWaitDelays = (uchar)(this->numberWaitDelays + 1);
                    return 1;
                }
                this->owner->incrementPathingAttempts();
                this->startValue.x = this->world_x;
                this->startValue.y = this->world_y;
                this->startValue.z = this->world_z;
                this->numberWaitDelays = 0;
                pathSystem.incrementContinuePaths();

                int goal_y;
                int goal_x;
                if (this->numberUserDefinedWaypointsValue < 1) {
                    goal_y = rge_ftol(this->goalValue.y);
                    goal_x = rge_ftol(this->goalValue.x);
                } else {
                    goal_y = (int)this->userDefinedWaypoints[0].y;
                    goal_x = (int)this->userDefinedWaypoints[0].x;
                }

                int start_y = rge_ftol(this->startValue.y);
                int start_x = rge_ftol(this->startValue.x);

                int path_ok = pathSystem.findTilePath(start_x, start_y, goal_x, goal_y, this, this->actionRange, this->targetIDValue, 1, nullptr, 1, 1, 1, 1, -1, -1);
                this->speed = 0.0f;

                if ((path_ok == 0) && (this->pathValue.numberOfWaypoints() == 1)) {
                    float center_x = rge_tile_center(this->world_x);
                    float center_y = rge_tile_center(this->world_y);
                    if (pathSystem.passable(this, center_x, center_y, 1) != 0) {
                        float frac_x = this->world_x - (float)floor((double)this->world_x);
                        float frac_y = this->world_y - (float)floor((double)this->world_y);
                        if ((frac_x == 0.5f) && (frac_y == 0.5f)) {
                            this->rangeStatusValue = 2;
                            if (this->numberUserDefinedWaypointsValue < 2) {
                                return 0;
                            }
                            this->continueCounter = this->continueCounter + 5;
                            return 1;
                        }
                        (void)this->teleport(center_x, center_y, this->world_z);
                    }
                }

                this->pathValue.initToStart();
                if (this->pathValue.moveToNextWaypoint() == 0) {
                    this->speed = 0.0f;
                    this->rangeStatusValue = 2;
                    if (this->numberUserDefinedWaypointsValue < 2) {
                        return 0;
                    }
                    this->continueCounter = this->continueCounter + 5;
                    return 1;
                }
            }
            this->rangeStatusValue = 2;
            return 1;
        }
    }

    this->speed = 0.0f;
    this->rangeStatusValue = 2;
    if (this->numberUserDefinedWaypointsValue < 2) {
        return 0;
    }
    this->continueCounter = this->continueCounter + 5;
    return 1;
}

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x0045E970
int RGE_Moving_Object::doTrivialMove(float param_1, float param_2) {
    int already_moving = 1;
    if (this->speed == 0.0f) {
        already_moving = 0;
        float sprite_speed = 0.0f;
        if (this->sprite != nullptr) {
            sprite_speed = *(float*)((char*)this->sprite + 0x64);
        }
        if (this->sprite != nullptr && sprite_speed > 0.0f) {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed * sprite_speed;
        } else {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed;
        }
    }

    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    float dt = (world != nullptr) ? world->world_time_delta_seconds : 0.0f;
    float distance_to_cover = dt * this->speed;

    if (0.0f < this->collisionAvoidanceDistance) {
        this->collisionAvoidanceDistance = this->collisionAvoidanceDistance - distance_to_cover;
        if (0.0f < this->collisionAvoidanceDistance) {
            this->speed = 0.0f;
            return 0;
        }
        this->collisionAvoidanceDistance = -1.0f;
    }

    RGE_Master_Moving_Object* master = (RGE_Master_Moving_Object*)this->master_obj;
    if (master != nullptr && 0.0f < master->turn_speed) {
        if (0.0f <= this->turnTimer) {
            this->turnTimer = this->turnTimer - dt;
        } else {
            this->turnTimer = 0.0f;
        }
    }

    int number_facets = 8;
    if (this->sprite != nullptr) {
        number_facets = (int)*(short*)((char*)this->sprite + 0x60);
    }

    float dx;
    float dy;
    if (already_moving != 0) {
        dx = param_1 - this->world_x;
        dy = param_2 - this->world_y;
    } else {
        dx = param_1 - rge_tile_center(this->world_x);
        dy = param_2 - rge_tile_center(this->world_y);
    }

    float target_angle = atan2f(dy, dx);
    boundAngle(&target_angle, -1);

    float d_angle = target_angle - this->angle;
    while (d_angle < -kPi) {
        d_angle += kTwoPi;
    }
    while (kPi < d_angle) {
        d_angle -= kTwoPi;
    }

    float facet_delta = d_angle * (float)number_facets * kInvTwoPi;
    boundAngle(&this->angle, number_facets);

    while ((this->turnTimer <= 0.0f) && ((0.8f < facet_delta) || (facet_delta < -0.8f))) {
        this->turnTimer = master->turn_speed + this->turnTimer;
        if (0.0f <= d_angle) {
            facet_delta = facet_delta - 1.0f;
            this->angle = (kTwoPi / (float)number_facets) + this->angle;
        } else {
            facet_delta = facet_delta + 1.0f;
            this->angle = this->angle - (kTwoPi / (float)number_facets);
        }
    }

    boundAngle(&this->angle, number_facets);
    set_angle();

    float cos_a = cosf(this->angle);
    float sin_a = sinf(this->angle);

    this->velocity_x = cos_a * distance_to_cover;
    this->velocity_y = sin_a * distance_to_cover;

    float new_x = this->world_x + this->velocity_x;
    float new_y = this->world_y + this->velocity_y;

    int passable = 1;
    if (this->master_obj != nullptr && this->master_obj->radius_z > 0.0f) {
        passable = pathSystem.passable(this, new_x, new_y, 1);
    }

    if (passable == 0) {
        if (this->collisionAvoidanceDistance == 0.0f) {
            int rv = debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", (this->speed <= 0.0f) ? 0x6D1 : 0x6CF);
            float delay = (float)(rv % 6) * 0.1f;
            if (this->speed <= 0.0f) {
                this->collisionAvoidanceDistance = delay + 0.5f;
            } else {
                this->collisionAvoidanceDistance = delay + (0.5f / this->speed);
            }
            this->speed = 0.0f;
            return 0;
        }

        this->collisionAvoidanceDistance = 0.0f;

        float center_x = rge_tile_center(this->world_x);
        float center_y = rge_tile_center(this->world_y);
        if (pathSystem.passable(this, center_x, center_y, 1) != 0) {
            (void)this->teleport(center_x, center_y, this->world_z);
        }

        if (this->targetIDValue != -1 && world != nullptr) {
            RGE_Static_Object* target = world->object((long)this->targetIDValue);
            if (target != nullptr) {
                float tdx = target->world_x - this->world_x;
                float tdy = target->world_y - this->world_y;
                float dist = sqrtf(tdy * tdy + tdx * tdx);
                float base_r = sqrtf(((RGE_Master_Static_Object*)this->master_obj)->radius_y * ((RGE_Master_Static_Object*)this->master_obj)->radius_y +
                                     ((RGE_Master_Static_Object*)this->master_obj)->radius_x * ((RGE_Master_Static_Object*)this->master_obj)->radius_x);
                if (dist < base_r + this->actionRange + 0.3f) {
                    return 5;
                }
            }
        }

        if (pathSystem.passable(this, param_1, param_2, 1) == 0) {
            return 2;
        }

        this->continueCounter = this->continueCounter - 1;
        if (this->continueCounter < 1) {
            return 4;
        }

        if (this->owner != nullptr && this->owner->availablePathingAttempts((uint)this->numberWaitDelays) == 0) {
            this->numberWaitDelays = (uchar)(this->numberWaitDelays + 1);
            return 1;
        }

        if (this->owner != nullptr) {
            this->owner->incrementPathingAttempts();
        }

        this->startValue.x = this->world_x;
        this->startValue.y = this->world_y;
        this->startValue.z = this->world_z;
        this->numberWaitDelays = 0;

        pathSystem.incrementContinuePaths();

        int goal_y;
        int goal_x;
        if (this->numberUserDefinedWaypointsValue < 1) {
            goal_y = rge_ftol(param_2);
            goal_x = rge_ftol(param_1);
        } else {
            goal_y = (int)this->userDefinedWaypoints[0].y;
            goal_x = (int)this->userDefinedWaypoints[0].x;
        }

        int start_y = rge_ftol(this->startValue.y);
        int start_x = rge_ftol(this->startValue.x);

        float path_distance = (float)pathSystem.findTilePath(start_x, start_y, goal_x, goal_y, this, this->actionRange, this->targetIDValue, 1, nullptr, 1, 1, 1, 1, -1, -1);
        (void)path_distance;

        if (actionFile != nullptr && this->owner != nullptr && this->owner->world != nullptr) {
            fprintf(actionFile, "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)",
                    (long)this->owner->world->world_time, (int)this->id, (double)this->startValue.x, (double)this->startValue.y, (double)this->goalValue.x,
                    (double)this->goalValue.y);
            this->pathValue.initToStart();
            int i = 0;
            int n = this->pathValue.numberOfWaypoints();
            while (i < n) {
                Waypoint* wp = this->pathValue.currentWaypoint();
                if (wp != nullptr) {
                    fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i, (double)wp->x, (double)wp->y);
                }
                i = i + 1;
                this->pathValue.moveToNextWaypoint();
                n = this->pathValue.numberOfWaypoints();
            }
            fprintf(actionFile, ".\n");
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        if ((path_distance == 0.0f) && (this->pathValue.numberOfWaypoints() == 1)) {
            float center_x2 = rge_tile_center(this->world_x);
            float center_y2 = rge_tile_center(this->world_y);
            if (pathSystem.passable(this, center_x2, center_y2, 1) != 0) {
                float frac_x = this->world_x - (float)floor((double)this->world_x);
                float frac_y = this->world_y - (float)floor((double)this->world_y);
                if ((frac_x == 0.5f) && (frac_y == 0.5f)) {
                    return 4;
                }
                (void)this->teleport(center_x2, center_y2, this->world_z);
            }
        }

        if ((displayPathingFlags != 0) && ((this->selected & 1) != 0)) {
            this->pathValue.initToStart();
            int i = 0;
            int n = this->pathValue.numberOfWaypoints();
            while (i < n) {
                RGE_Master_Static_Object* marker_master = (this->owner != nullptr && this->owner->master_objects != nullptr) ? this->owner->master_objects[displayPathObjectID] : nullptr;
                Waypoint* wp = this->pathValue.currentWaypoint();
                if (marker_master != nullptr && wp != nullptr) {
                    marker_master->make_new_obj(this->owner, wp->x, wp->y, 1.0f);
                }
                i = i + 1;
                this->pathValue.moveToNextWaypoint();
                n = this->pathValue.numberOfWaypoints();
            }
            this->pathValue.initToStart();
            this->pathValue.moveToNextWaypoint();
        }

        this->pathValue.initToStart();
        if (this->pathValue.moveToNextWaypoint() == 0) {
            return 4;
        }
        this->closestDistanceToWaypoint = 100000.0f;

        // Try to turn toward the new path before continuing movement.
        Waypoint* next = this->pathValue.currentWaypoint();
        if (next != nullptr) {
            float ndx = (already_moving != 0) ? (next->x - this->world_x) : (next->x - rge_tile_center(this->world_x));
            float ndy = (already_moving != 0) ? (next->y - this->world_y) : (next->y - rge_tile_center(this->world_y));
            float next_angle = atan2f(ndy, ndx);
            boundAngle(&next_angle, -1);

            float delta = next_angle - this->angle;
            float facet_delta2 = delta * (float)number_facets * kInvTwoPi;
            if (0.0f < this->turnTimer) {
                this->speed = 0.0f;
                return 0;
            }

            while ((facet_delta2 > 0.9f) || (facet_delta2 < -0.9f)) {
                this->turnTimer = master->turn_speed + this->turnTimer;
                if (0.0f <= delta) {
                    facet_delta2 = facet_delta2 - 1.0f;
                    this->angle = (kTwoPi / (float)number_facets) + this->angle;
                } else {
                    facet_delta2 = facet_delta2 + 1.0f;
                    this->angle = this->angle - (kTwoPi / (float)number_facets);
                }
                if (this->turnTimer > 0.0f) {
                    break;
                }
            }

            boundAngle(&this->angle, number_facets);
            set_angle();

            float sin2 = sinf(this->angle);
            float cos2 = cosf(this->angle);
            this->velocity_x = cos2 * distance_to_cover;
            this->velocity_y = sin2 * distance_to_cover;
            new_x = this->world_x + this->velocity_x;
            new_y = this->world_y + this->velocity_y;

            if (pathSystem.passable(this, new_x, new_y, 1) == 0) {
                if (this->owner != nullptr && this->owner->computerPlayer() != 1) {
                    int rv = debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", (this->speed <= 0.0f) ? 0x7D5 : 0x7D3);
                    float delay = (float)(rv % 6) * 0.1f;
                    if (this->speed <= 0.0f) {
                        this->collisionAvoidanceDistance = delay + 0.5f;
                    } else {
                        this->collisionAvoidanceDistance = delay + (0.5f / this->speed);
                    }
                    this->speed = 0.0f;
                    return 0;
                }
                return 4;
            }
        }
    }

    float new_z = this->world_z + this->velocity_z;

    // If we overshoot the current waypoint, snap to it.
    Waypoint* wp = this->pathValue.currentWaypoint();
    float dist_to_waypoint = 0.0f;
    if (wp != nullptr) {
        float wdx = wp->x - this->world_x;
        float wdy = wp->y - this->world_y;
        dist_to_waypoint = sqrtf(wdy * wdy + wdx * wdx);

        float pdx = wp->x - (this->world_x + this->velocity_x);
        float pdy = wp->y - (this->world_y + this->velocity_y);
        float predicted = sqrtf(pdy * pdy + pdx * pdx);

        if (((this->closestDistanceToWaypoint < predicted) && (dist_to_waypoint < 0.25f)) ||
            ((this->lastFacet2 == this->facet) && (this->lastFacet2 != this->lastFacet) && (dist_to_waypoint < 0.5f))) {
            if (pathSystem.passable(this, wp->x, wp->y, 1) == 0) {
                return 2;
            }
            (void)this->teleport(wp->x, wp->y, wp->z);
        } else {
            (void)this->teleport(new_x, new_y, new_z);
        }
    } else {
        (void)this->teleport(new_x, new_y, new_z);
        float ddx = param_1 - new_x;
        float ddy = param_2 - new_y;
        dist_to_waypoint = sqrtf(ddy * ddy + ddx * ddx);
    }

    // Update facet history and closest distance
    float dz = new_z - this->world_z;
    unsigned char old_last = this->lastFacet;
    this->lastFacet = this->facet;
    this->lastFacet2 = old_last;
    this->closestDistanceToWaypoint = dist_to_waypoint;

    float speed_factor = 1.0f;
    if (dz < -0.02f) {
        speed_factor = 0.9f;
    } else if (dz <= 0.02f) {
        float sprite_speed = 0.0f;
        if (this->sprite != nullptr) {
            sprite_speed = *(float*)((char*)this->sprite + 0x64);
        }
        if (this->sprite != nullptr && sprite_speed > 0.0f) {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed * sprite_speed;
        } else {
            this->speed = ((RGE_Master_Animated_Object*)this->master_obj)->speed;
        }
    } else {
        speed_factor = 1.03f;
    }

    if (this->tile != nullptr) {
        speed_factor = this->get_terrain_speed((unsigned char)this->tile->terrain_type) * speed_factor;
    }

    if (0.0f < speed_factor) {
        this->speed = speed_factor * this->speed;
    }
    return 0;
}

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x004608D0
float RGE_Moving_Object::maximumSpeed() {
    if (this->sprite != nullptr) {
        float sprite_speed = *(float*)((char*)this->sprite + 0x64);
        if (sprite_speed > 0.0f) {
            return ((RGE_Master_Animated_Object*)this->master_obj)->speed * sprite_speed;
        }
    }
    return ((RGE_Master_Animated_Object*)this->master_obj)->speed;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045F7F0
int RGE_Moving_Object::passableTile(float param_1, float param_2, int param_3) {
    PathingSystem* sys = &aiPathSystem;
    if (param_3 == 0) {
        sys = &pathSystem;
    }
    return sys->passable(this, param_1, param_2, 1);
}

static RGE_Zone_Map* rge_moving_get_zone_map(RGE_Moving_Object* obj) {
    RGE_Game_World* world = (obj != nullptr && obj->owner != nullptr) ? obj->owner->world : nullptr;
    if (world == nullptr || world->map == nullptr || world->map->map_zones == nullptr || obj->master_obj == nullptr) {
        return nullptr;
    }

    if (obj->zoneMapIndex == -1) {
        world->map->map_zones->get_zone_map(world->terrains[obj->master_obj->terrain], (int)world->terrain_size, &obj->zoneMapIndex);
    }

    return world->map->map_zones->get_zone_map((long)obj->zoneMapIndex);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045F820
int RGE_Moving_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) {
    if ((param_1.x < 0) || (param_1.y < 0)) {
        return 0;
    }

    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    if (world == nullptr || world->map == nullptr) {
        return 0;
    }

    if ((param_1.x >= (int)world->map->map_width) || (param_1.y >= (int)world->map->map_height)) {
        return 0;
    }

    RGE_Zone_Map* zone_map = rge_moving_get_zone_map(this);
    if (zone_map == nullptr) {
        return 0;
    }

    int start_y = rge_ftol(this->world_y);
    int start_x = rge_ftol(this->world_x);
    uchar start_zone = zone_map->get_zone_info((long)start_x, (long)start_y);
    uchar goal_zone = zone_map->get_zone_info((long)param_1.x, (long)param_1.y);
    if (goal_zone != start_zone) {
        XYPoint start;
        start.x = start_x;
        start.y = start_y;
        XYPoint goal;
        goal.x = param_1.x;
        goal.y = param_1.y;
        if (zone_map->withinRange(start, goal, param_2) == 0) {
            return 0;
        }
    }

    PathingSystem* sys = (param_5 == 0) ? &pathSystem : &aiPathSystem;
    sys->incrementCanPaths();
    return sys->findTilePath(start_x, start_y, param_1.x, param_1.y, this, param_2, param_3, 0, param_4, 1, 1, 1, 1, param_6, param_7);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045F9D0
int RGE_Moving_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) {
    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    if (world == nullptr) {
        return 0;
    }

    RGE_Static_Object* goal_obj = world->object(param_1);
    if (goal_obj == nullptr) {
        return 0;
    }

    RGE_Zone_Map* zone_map = rge_moving_get_zone_map(this);
    if (zone_map == nullptr) {
        return 0;
    }

    int start_y = rge_ftol(this->world_y);
    int start_x = rge_ftol(this->world_x);
    uchar start_zone = zone_map->get_zone_info((long)start_x, (long)start_y);

    int goal_y = rge_ftol(goal_obj->world_y);
    int goal_x = rge_ftol(goal_obj->world_x);
    uchar goal_zone = zone_map->get_zone_info((long)goal_x, (long)goal_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        start.x = start_x;
        start.y = start_y;
        XYPoint goal;
        goal.x = goal_x;
        goal.y = goal_y;
        if (zone_map->withinRange(start, goal, param_2) == 0) {
            return 0;
        }
    }

    PathingSystem* sys = (param_4 == 0) ? &pathSystem : &aiPathSystem;
    sys->incrementCanPaths();
    return sys->findTilePath(start_x, start_y, goal_x, goal_y, this, param_2, param_1, 0, param_3, 1, 1, 1, 1, param_5, param_6);
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045FBC0
int RGE_Moving_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) {
    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    if (world == nullptr) {
        return 0;
    }

    RGE_Static_Object* obj1 = world->object(param_1);
    RGE_Static_Object* obj2 = world->object(param_2);
    if (obj1 == nullptr || obj2 == nullptr) {
        return 0;
    }

    RGE_Zone_Map* zone_map = rge_moving_get_zone_map(this);
    if (zone_map == nullptr) {
        return 0;
    }

    int start_y = rge_ftol(obj1->world_y);
    int start_x = rge_ftol(obj1->world_x);
    uchar start_zone = zone_map->get_zone_info((long)start_x, (long)start_y);

    int goal_y = rge_ftol(obj2->world_y);
    int goal_x = rge_ftol(obj2->world_x);
    uchar goal_zone = zone_map->get_zone_info((long)goal_x, (long)goal_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        start.x = start_x;
        start.y = start_y;
        XYPoint goal;
        goal.x = goal_x;
        goal.y = goal_y;
        if (zone_map->withinRange(start, goal, param_3) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;

    PathingSystem* sys = (param_5 == 0) ? &pathSystem : &aiPathSystem;
    sys->incrementCanPaths();
    int ok = sys->findTilePath(start_x, start_y, goal_x, goal_y, this, param_3, param_1, 1, param_4, 1, 1, 1, 1, param_6, param_7);
    if (ok == 0) {
        this->storePathInExceptionPath = 0;
        return 0;
    }

    Waypoint* last = this->exceptionPathValue.lastWaypoint();
    if (last == nullptr) {
        this->storePathInExceptionPath = 0;
        return 0;
    }

    int back_start_y = rge_ftol(last->y);
    int back_start_x = rge_ftol(last->x);
    int back_goal_y = rge_ftol(obj2->world_y);
    int back_goal_x = rge_ftol(obj2->world_x);

    int back_ok = sys->findTilePath(back_start_x, back_start_y, back_goal_x, back_goal_y, this, param_3, param_2, 0, param_4, 1, 1, 1, 1, param_6, param_7);
    this->storePathInExceptionPath = 0;
    return back_ok;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x0045FED0
int RGE_Moving_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6,
                                               ManagedArray<int>* param_7) {
    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    if (world == nullptr) {
        return 0;
    }

    RGE_Static_Object* goal_obj = world->object(param_1);
    if (goal_obj == nullptr) {
        return 0;
    }

    RGE_Zone_Map* zone_map = rge_moving_get_zone_map(this);
    if (zone_map == nullptr) {
        return 0;
    }

    int start_y = rge_ftol(this->world_y);
    int start_x = rge_ftol(this->world_x);
    uchar start_zone = zone_map->get_zone_info((long)start_x, (long)start_y);

    int goal_y = rge_ftol(goal_obj->world_y);
    int goal_x = rge_ftol(goal_obj->world_x);
    uchar goal_zone = zone_map->get_zone_info((long)goal_x, (long)goal_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        start.x = start_x;
        start.y = start_y;
        XYPoint goal;
        goal.x = goal_x;
        goal.y = goal_y;
        if (zone_map->withinRange(start, goal, param_2) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;

    PathingSystem* sys = (param_4 == 0) ? &pathSystem : &aiPathSystem;
    sys->incrementCanPaths();
    int ok = sys->findTilePath(start_x, start_y, goal_x, goal_y, this, param_2, param_1, 1, param_3, 1, 1, 1, 1, param_5, param_6);

    if (param_6 != -1 && param_7 != nullptr) {
        sys->copyUnobstructibles(*param_7);
    }

    this->storePathInExceptionPath = 0;
    return ok;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x004600F0
int RGE_Moving_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6,
                                                        int param_7, int param_8, int param_9) {
    if ((param_1.x < 0) || (param_1.y < 0)) {
        return 0;
    }

    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    if (world == nullptr || world->map == nullptr) {
        return 0;
    }

    if ((param_1.x >= (int)world->map->map_width) || (param_1.y >= (int)world->map->map_height)) {
        return 0;
    }

    this->currentTerrainException2 = param_6;
    this->currentTerrainException1 = param_5;
    this->storePathInExceptionPath = 1;

    int start_y = rge_ftol(this->world_y);
    int start_x = rge_ftol(this->world_x);

    PathingSystem* sys = (param_7 == 0) ? &pathSystem : &aiPathSystem;
    sys->incrementCanPaths();
    int ok = sys->findTilePath(start_x, start_y, param_1.x, param_1.y, this, param_2, param_3, 1, param_4, 1, 1, 1, 1, param_8, param_9);

    this->storePathInExceptionPath = 0;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    return ok;
}

// Fully verified. Source of truth: move_obj.cpp.asm @ 0x00460210
int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) {
    Path* p = &this->exceptionPathValue;
    int n = p->numberOfWaypoints();
    if (n <= 1) {
        return 0;
    }

    p->initToStart();
    Waypoint* w0 = p->currentWaypoint();
    if (w0 == nullptr) {
        return 0;
    }

    XYPoint p1;
    p1.x = rge_ftol(w0->x);
    p1.y = rge_ftol(w0->y);
    p->moveToNextWaypoint();

    Waypoint* w1 = p->currentWaypoint();
    if (w1 == nullptr) {
        return 0;
    }

    XYPoint p2;
    p2.x = rge_ftol(w1->x);
    p2.y = rge_ftol(w1->y);

    XYPoint rVal;
    int i = 1;
    n = p->numberOfWaypoints();
    while (i < n) {
        if (this->firstTileAlongLine(&p1, &p2, &rVal, param_1, param_1, 1) == 1) {
            if (param_2 != nullptr) {
                *param_2 = (float)rVal.y + 0.5f;
            }
            if (param_3 != nullptr) {
                *param_3 = (float)rVal.y + 0.5f;
            }
            return 1;
        }

        w0 = p->currentWaypoint();
        if (w0 == nullptr) {
            return 0;
        }
        p1.x = rge_ftol(w0->x);
        p1.y = rge_ftol(w0->y);
        p->moveToNextWaypoint();

        w1 = p->currentWaypoint();
        if (w1 == nullptr) {
            return 0;
        }
        p2.x = rge_ftol(w1->x);
        p2.y = rge_ftol(w1->y);

        i = i + 1;
        n = p->numberOfWaypoints();
    }

    if (param_2 != nullptr) {
        *param_2 = -1.0f;
    }
    if (param_3 != nullptr) {
        *param_3 = -1.0f;
    }
    return 0;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x004603B0
int RGE_Moving_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) {
    int x0 = param_1->x;
    int y0 = param_1->y;
    float dx = (float)(param_2->x - x0);
    float dy = (float)(param_2->y - y0);
    if (dx == 0.0f && dy == 0.0f) {
        return 0;
    }

    int steps = 0;
    if (fabsf(dy) <= fabsf(dx)) {
        steps = abs(rge_ftol(fabsf(dx))) * 2;
    } else {
        steps = abs(rge_ftol(fabsf(dy))) * 2;
    }

    int last_x = -999;
    int last_y = -999;
    float cx = (float)x0;
    float cy = (float)y0;
    if (steps < 1) {
        return 1;
    }

    for (int i = 0; i < steps; ++i) {
        cx += dx / (float)steps;
        cy += dy / (float)steps;
        int tx = rge_ftol(cx);
        int ty = rge_ftol(cy);
        if (tx != last_x || ty != last_y) {
            if (this->passableTile(cx, cy, param_5) == 0) {
                if (param_4 != nullptr) {
                    param_4->x = tx;
                    param_4->y = ty;
                }
                return 0;
            }
            float rdx = (float)param_2->x - cx;
            float rdy = (float)param_2->y - cy;
            last_x = tx;
            last_y = ty;
            if (sqrtf(rdy * rdy + rdx * rdx) <= param_3) {
                return 1;
            }
        }
    }
    return 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460570
int RGE_Moving_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) {
    if (((float)(param_3 - param_1) == 0.0f) && ((float)(param_4 - param_2) == 0.0f)) {
        return 0;
    }

    float dx = (float)(param_3 - param_1);
    float dy = (float)(param_4 - param_2);
    int steps = 0;
    if (fabsf(dy) <= fabsf(dx)) {
        steps = abs(rge_ftol(fabsf(dx))) * 2;
    } else {
        steps = abs(rge_ftol(fabsf(dy))) * 2;
    }

    int last_x = -999;
    int last_y = -999;
    float cx = (float)param_1;
    float cy = (float)param_2;
    if (steps < 1) {
        return 1;
    }

    for (int i = 0; i < steps; ++i) {
        cx += dx / (float)steps;
        cy += dy / (float)steps;
        int tx = rge_ftol(cx);
        int ty = rge_ftol(cy);
        if (tx != last_x || ty != last_y) {
            if (this->passableTile(cx, cy, param_6) == 0) {
                return 0;
            }
            last_x = tx;
            last_y = ty;
            float rdx = (float)param_3 - cx;
            float rdy = (float)param_4 - cy;
            if (sqrtf(rdy * rdy + rdx * rdx) <= param_5) {
                return 1;
            }
        }
    }
    return 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460710
int RGE_Moving_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) {
    int x0 = param_1->x;
    int y0 = param_1->y;
    float dx = (float)(param_2->x - x0);
    float dy = (float)(param_2->y - y0);
    if (dx == 0.0f && dy == 0.0f) {
        return 0;
    }

    int steps = 0;
    if (fabsf(dy) <= fabsf(dx)) {
        steps = abs(rge_ftol(fabsf(dx))) * 2;
    } else {
        steps = abs(rge_ftol(fabsf(dy))) * 2;
    }

    int last_x = -999;
    int last_y = -999;
    float cx = (float)x0;
    float cy = (float)y0;
    RGE_Game_World* world = (this->owner != nullptr) ? this->owner->world : nullptr;
    RGE_Map* map = (world != nullptr) ? world->map : nullptr;
    if (map == nullptr || steps <= 0) {
        return 0;
    }

    for (int i = 0; i < steps; ++i) {
        cx += dx / (float)steps;
        cy += dy / (float)steps;
        int tx = rge_ftol(cx);
        int ty = rge_ftol(cy);
        if (tx != last_x || ty != last_y) {
            uchar terrain = map->get_terrain((short)tx, (short)ty);
            last_x = tx;
            last_y = ty;
            if ((((int)terrain == param_4) || ((int)terrain == param_5)) && (param_6 == 1)) {
                if (this->passableTile(cx, cy, 0) == 1) {
                    if (param_3 != nullptr) {
                        param_3->x = tx;
                        param_3->y = ty;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
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

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00405F60
int RGE_Moving_Object::numberUserDefinedWaypoints() {
    return this->numberUserDefinedWaypointsValue;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460BF0
void RGE_Moving_Object::setFinalUserDefinedWaypoint() {
    this->finalUserDefinedWaypoint = 1;
}

// Fully verified. Source of truth: move_obj.cpp.decomp @ 0x00460C00
Path* RGE_Moving_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) {
    if (param_1 == nullptr) {
        return nullptr;
    }

    RGE_Zone_Map* zone_map = rge_moving_get_zone_map(this);
    if (zone_map == nullptr) {
        return nullptr;
    }

    int start_y = rge_ftol(this->world_y);
    int start_x = rge_ftol(this->world_x);
    uchar start_zone = zone_map->get_zone_info((long)start_x, (long)start_y);
    uchar goal_zone = zone_map->get_zone_info((long)param_1->x, (long)param_1->y);
    if (goal_zone != start_zone) {
        XYPoint start;
        start.x = start_x;
        start.y = start_y;
        XYPoint goal;
        goal.x = param_1->x;
        goal.y = param_1->y;
        if (zone_map->withinRange(start, goal, param_2) == 0) {
            return nullptr;
        }
    }

    this->storePathInExceptionPath = 1;
    (void)aiPathSystem.findTilePath(start_x, start_y, param_1->x, param_1->y, this, param_2, param_3, 1, nullptr, 0, 1, 1, 1, -1, -1);
    this->storePathInExceptionPath = 0;

    aiPathSystem.initMisc(0);
    return &this->exceptionPathValue;
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
