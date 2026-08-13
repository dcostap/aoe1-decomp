// VA: 0045E970 RGE_Moving_Object::doTrivialMove
// Canonical source reconstruction from move_obj.cpp:1509-2185.
// Attempt log:
// - baseline: natural named moving-object/master/world/path ownership, typed x87 math,
//   complete named RGE_Static_Object and RGE_Master_Static_Object virtual surfaces.
// - restored period-correct double-zero comparisons and the observed sprite layout;
//   this removed the extra speed store and moved the structural frontier substantially.
// - repeated currentWaypoint() expressions to preserve the original ordered calls;
//   the final direct snap call now matches all 83 original call sites.
// - inlined the target-radius predicate as one typed expression; this is the cleanest
//   source reconstruction, although the compiler still reserves an 0x24 rather than
//   the original 0x2C frame and leaves broad positional drift.
// - reversed the first turnTimer guard to the original negative-first source shape;
//   this closed the first local CFG hunk and improved the diff by 26 bytes.
// - promoting one Waypoint* across the repeated path scans collapsed the frame to
//   0x1C and worsened the structural diff; rolled back.
// - reordering the real arithmetic locals to the dossier order was emitted-code
//   duplicate evidence; rolled back.
// - cached displayPathObjectID before the display gate, matching its original
//   pre-gate load; size moved 18 bytes closer, but positional diff worsened by 1.
// - current bounded pause: exact matching remains unresolved after this claim's
//   three evidence-backed hypotheses;
//   remaining evidence points to original local-frame/register topology and VC5
//   tail/block scheduling, not a missing call or virtual-surface declaration.
// - reintroduced the decompiler's zero-initialized first-turn temporary; it
//   improved exact-block coverage but worsened positional bytes, so rolled back.
// - swapped the commutative master-radius terms; shape improved without a
//   positional change, so kept the radius_y/radius_x source order.
// - restored named target-distance and radius temporaries from the original
//   stack hunk; size moved 6 bytes closer and positional diff improved to 2826.
// - naming the owner world and radius components was emitted-code duplicate or
//   worse; kept only the natural target-distance temporaries.

#include <math.h>
#include <stdio.h>

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad[3];
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Sprite;

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    void initToStart();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char operation);
    virtual void modify_delta(float value, unsigned char operation);
    virtual void modify_percent(float value, unsigned char operation);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);

    char gap_04[0x2C];
    float radius_x;
    float radius_y;
    float radius_z;
    char gap_3C[0x7C];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[8];
    float turn_speed;
};

class RGE_Sprite {
public:
    char gap_00[0x60];
    short facet_num;
    char gap_62[2];
    float base_speed;
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char objects[0x0C];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    char pathingGroupMembers[0x10];
    char groupMembers[0x10];
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_end;

    float get_terrain_speed(unsigned char terrain_type);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;
    Path exceptionPathValue;
    Waypoint startValue;
    Waypoint goalValue;
    float turnTimer;
    float collisionAvoidanceDistance;
    float actionRange;
    int targetIDValue;
    float targetRadiusX;
    float targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;
    unsigned char storePathInExceptionPath;
    unsigned char waitingToMoveValue;
    unsigned char numberWaitDelays;
    unsigned char pad_157;
    int minInitialPointX;
    int minInitialPointY;
    int maxInitialPointX;
    int maxInitialPointY;
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char pad_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;
    unsigned char pad_17e[2];

    void boundAngle(float* angle, int numberFacets);
    void set_angle();
    int doTrivialMove(float x, float y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_08[0x7C];
    float world_time_delta_seconds;

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;

    int availablePathingAttempts(unsigned char numberWaitDelays);
    void incrementPathingAttempts();
    int computerPlayer();
};

class PathingSystem {
public:
    void incrementContinuePaths();
    int passable(RGE_Moving_Object* object, float x, float y, int checkObjects);
    int findTilePath(int startX, int startY, int goalX, int goalY,
                     RGE_Moving_Object* object, float actionRange, int targetID,
                     int mode, float* cost, int useIterationCap, int checkObstructions,
                     int checkTerrain, int step, int unobPlayerID, int unobGroupID);
};

extern PathingSystem pathSystem;
extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;
extern int debug_rand(char* file, int line);

extern double DAT_00570b40;
extern float DAT_00570b48;
extern float DAT_00570b4c;
extern float DAT_00570b50;
extern float DAT_00570b60;
extern float DAT_00570b64;
extern double DAT_00570b68;
extern double DAT_00570b70;
extern float DAT_00570b78;
extern float DAT_00570b80;
extern double DAT_00570b90;
extern double DAT_00570b98;
extern float DAT_00570ba8;
extern double DAT_00570bb0;
extern double DAT_00570bb8;
extern float DAT_00570bc0;
extern double DAT_00570bc8;
extern double DAT_00570bd0;
extern float DAT_00570bd8;
extern double DAT_00570be0;
extern double DAT_00570bf0;

int RGE_Moving_Object::doTrivialMove(float x, float y)
{
    int numberFacets;
    float dX;
    float targetDY;
    float newAngle;
    float dY;
    float newY;
    float distanceToCover;
    int curDistance;
    int i;
    int found;
    int passable;

    curDistance = 1;

    if (this->speed == DAT_00570b98) {
        RGE_Sprite* sprite = this->sprite;
        curDistance = 0;
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

    if (curDistance == 1) {
        dX = x - this->world_x;
        dY = y - this->world_y;
    } else {
        dX = x - ((float)floor((double)this->world_x) - DAT_00570b80);
        dY = y - ((float)floor((double)this->world_y) - DAT_00570b80);
    }

    targetDY = (float)atan2((double)dY, (double)dX);
    this->boundAngle(&targetDY, -1);

    dY = targetDY - this->angle;
    while (dY < DAT_00570b70) {
        dY = dY - DAT_00570b4c;
    }
    while (dY > DAT_00570b68) {
        dY = dY - DAT_00570b50;
    }

    newY = dY * (float)numberFacets * DAT_00570b78;
    this->boundAngle(&this->angle, numberFacets);

    while (this->turnTimer <= DAT_00570b48 &&
           (newY > DAT_00570bb0 || newY < DAT_00570bb8)) {
        this->turnTimer = ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed + this->turnTimer;
        if (dY >= DAT_00570b48) {
            newY = newY - DAT_00570b64;
            this->angle = DAT_00570b40 / (float)numberFacets + this->angle;
        } else {
            newY = newY - DAT_00570b60;
            this->angle = this->angle - DAT_00570b40 / (float)numberFacets;
        }
    }

    this->boundAngle(&this->angle, numberFacets);
    this->set_angle();

    this->velocity_x = (float)cos((double)this->angle) * newAngle;
    this->velocity_y = (float)sin((double)this->angle) * newAngle;
    distanceToCover = this->velocity_y;
    dX = this->world_x + this->velocity_x;
    newY = this->world_y + distanceToCover;

    passable = 1;
    if (((RGE_Master_Static_Object*)this->master_obj)->radius_z > DAT_00570b48) {
        passable = pathSystem.passable(this, dX, newY, 1);
    }

    if (passable == 0) {
        if (this->collisionAvoidanceDistance == DAT_00570b48) {
            if (this->speed <= DAT_00570b48) {
                this->speed = 0.0f;
                this->collisionAvoidanceDistance =
                    (float)(debug_rand((char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x6D1) % 6) * DAT_00570bc0 - DAT_00570b80;
                return 0;
            }
                this->collisionAvoidanceDistance =
                    (float)(debug_rand((char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x6CF) % 6) * DAT_00570bc0 - DAT_00570b80 / this->speed;
                this->speed = 0.0f;
            return 0;
        }

        passable = 1;
        this->collisionAvoidanceDistance = 0.0f;
        dX = (float)floor((double)this->world_x) - DAT_00570b80;
        newY = (float)floor((double)this->world_y) - DAT_00570b80;
        passable = pathSystem.passable(this, dX, newY, passable);
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
            float radius =
                (float)sqrt(master->radius_y * master->radius_y +
                            master->radius_x * master->radius_x);
            float targetDX = target->world_x - this->world_x;
            float targetDY2 = target->world_y - this->world_y;
            float targetDistance =
                (float)sqrt(targetDY2 * targetDY2 + targetDX * targetDX);
            if (targetDistance < radius + this->actionRange - DAT_00570ba8) {
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

    if (curDistance == 1) {
        dX = path->currentWaypoint()->x - this->world_x;
        dY = path->currentWaypoint()->y - this->world_y;
    } else {
        dX = path->currentWaypoint()->x - ((float)floor((double)this->world_x) - DAT_00570b80);
        dY = path->currentWaypoint()->y - ((float)floor((double)this->world_y) - DAT_00570b80);
    }

    targetDY = (float)atan2((double)dY, (double)dX);
    this->boundAngle(&targetDY, -1);
    dY = targetDY - this->angle;
    newY = dY * (float)numberFacets * DAT_00570b78;

    if (this->turnTimer > DAT_00570b48) {
        this->speed = 0.0f;
        return 0;
    }

    do {
        if (newY <= DAT_00570bc8 && newY >= DAT_00570bd0) {
            break;
        }
        this->turnTimer = ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed + this->turnTimer;
        if (dY >= DAT_00570b48) {
            newY = newY - DAT_00570b64;
            this->angle = DAT_00570b40 / (float)numberFacets + this->angle;
        } else {
            newY = newY - DAT_00570b60;
            this->angle = this->angle - DAT_00570b40 / (float)numberFacets;
        }
    } while (this->turnTimer <= DAT_00570b48);

    this->boundAngle(&this->angle, numberFacets);
    this->set_angle();

    this->velocity_x = (float)cos((double)this->angle) * newAngle;
    this->velocity_y = (float)sin((double)this->angle) * newAngle;
    distanceToCover = this->velocity_y;
    dX = this->world_x + this->velocity_x;
    newY = this->world_y + distanceToCover;

    passable = 1;
    if (((RGE_Master_Static_Object*)this->master_obj)->radius_z > DAT_00570b48) {
        passable = pathSystem.passable(this, dX, newY, 1);
    }
    if (passable == 0) {
        if (this->owner->computerPlayer() == 1) {
            return 4;
        }
        if (this->speed <= DAT_00570b48) {
            this->collisionAvoidanceDistance =
                (float)(debug_rand((char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x7D5) % 6) * DAT_00570bc0 - DAT_00570b80;
            this->speed = 0.0f;
        } else {
            this->collisionAvoidanceDistance =
                (float)(debug_rand((char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0x7D3) % 6) * DAT_00570bc0 - DAT_00570b80 / this->speed;
            this->speed = 0.0f;
        }
        return 0;
    }

    float destinationZ;
    Waypoint* waypoint = path->currentWaypoint();
    if (waypoint == 0) {
        float dx = x - dX;
        float dy = y - newY;
        distanceToCover = (float)sqrt(dy * dy + dx * dx);
        destinationZ = this->world_z + this->velocity_z;
    } else {
        float dx = path->currentWaypoint()->x - this->world_x;
        float dy = path->currentWaypoint()->y - this->world_y;
        distanceToCover = (float)sqrt(dy * dy + dx * dx);

        dx = path->currentWaypoint()->x - (this->world_x + this->velocity_x);
        dy = path->currentWaypoint()->y - (this->world_y + this->velocity_y);
        float nextDistance = (float)sqrt(dy * dy + dx * dx);

        if ((this->closestDistanceToWaypoint > nextDistance && distanceToCover < 0.25f) ||
            (this->lastFacet2 == this->facet && this->lastFacet2 != this->lastFacet &&
             distanceToCover < 0.5f)) {
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

    this->teleport(dX, newY, destinationZ);

moved:
    float deltaZ = destinationZ - this->world_z;
    float speedMultiplier = 1.0f;
    this->lastFacet2 = this->lastFacet;
    this->lastFacet = this->facet;
    this->closestDistanceToWaypoint = distanceToCover;

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
