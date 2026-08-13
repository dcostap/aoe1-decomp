#include <math.h>
#include <stdio.h>

// Attempt log:
// - Reconstructed the moving-object, Path, PathingSystem, player, and waypoint
//   ownership from the packet, exact move_obj.cpp donors, and original x87 flow.
// - The speed reset is the inherited RGE_Animated_Object field at +0x88;
//   trail_remainder begins at +0x8c and is not the field written by doMove.
// - Shared range-success tails and the one-waypoint retry/passable/teleport
//   behavior follow the observed branch and call structure.  Explicit retry
//   labels and direct do/while spelling were codegen duplicates; the living
//   source keeps the natural loop form.
// - Reordered the initial squared-distance terms to reproduce the original
//   distance-square-before-dY-square x87 evaluation.  A pointer-to-virtual-
//   member experiment was rolled back: it emitted direct ?_9 calls and was
//   neither an exact structural match nor a plausible original surface.
// - Remaining structural gap: VC5 emits two extra indirect retry call sites
//   for removeUserDefinedWaypoint and keeps a 0x10 frame versus the original
//   0x18; no padding or manual-vtable source was retained.
// - Ghidra confirms a separate int retry-success flag (bVar4) in both scans.
//   Its natural form reached a 0x18 frame and diff 3048, but VC5 still used
//   EAX for the cached vtable and emitted two retry calls. It was rolled back.
// - A donor-backed raw member-pointer cache removed the two extra indirect
//   call sites only when it loaded through an explicit saved vtable pointer;
//   direct-this loading classified them as virtual calls and kept the frame
//   at 0x10. The saved-vtable form reached a 0x18 frame and four new exact
//   blocks, but duplicated vtable homes in the prologue, worsened diff to
//   3359, and left the structural call gap. Both forms were rolled back as
//   codegen steering rather than source reconstruction.

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

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Moving_Object;

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
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x, float y,
                                          int* result, unsigned char a, unsigned char b,
                                          unsigned char c, unsigned char d, unsigned char e,
                                          unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char flag);

    char gap_00[0x30 - 4];
    float radius_x;
    float radius_y;
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
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);

    long id;
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
    ManagedArrayInt pathingGroupMembers;
    ManagedArrayInt groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_end;

    unsigned char lookupZone(int x, int y);
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

    int doTrivialMove(float x, float y);
    int doMove();
};

class RGE_Game_World {
public:
    char gap_00[4];
    int world_time;
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;

    int availablePathingAttempts(int value);
    void incrementPathingAttempts();
};

class PathingSystem {
public:
    virtual ~PathingSystem();
    void incrementContinuePaths();
    int passable(RGE_Moving_Object* object, float x, float y, int in_obstruction_map);
    int findTilePath(int start_x, int start_y, int goal_x, int goal_y,
                    RGE_Moving_Object* object, float action_range, int target_id,
                    int param_8, float* param_9, int param_10, int param_11,
                    int param_12, int param_13, int param_14, int param_15);
};

extern PathingSystem pathSystem;
extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;
extern float DAT_00570b48;
extern float DAT_00570b80;
extern double DAT_00570b90;
extern double DAT_00570b98;
extern float DAT_00570ba0;
extern float DAT_00570ba8;

int RGE_Moving_Object::doMove() {
    float distance;
    float dY;
    float newDY;
    float distanceToGoal;
    Path* path;
    Waypoint* waypoint;
    int path_result;
    float object_radius_x;
    float object_radius_y;
    float retry_dx;
    float retry_dy;

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
    dY = dY - (this->targetRadiusY + this->master_obj->radius_y);
    if (distance < DAT_00570b48) {
        distance = 0.0f;
    }
    if (dY < DAT_00570b48) {
        dY = 0.0f;
    }

    distance = (float)sqrt(distance * distance + dY * dY);
    if (this->actionRange > DAT_00570b98 && distance <= this->actionRange) {
        this->speed = 0.0f;
        goto range_success;
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
            goto range_success;
        }
        if (result == 0) {
            this->rangeStatusValue = 2;
            return 1;
        }
        if (result == 1 || result == 6) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            return 1;
        }
        if (result == 2 || result == 3 || result == 4) {
            this->speed = 0.0f;
            goto range_success;
        }
    }

    path = &this->pathValue;
    path_result = 1;
    object_radius_x = this->master_obj->radius_x;
    object_radius_y = this->master_obj->radius_y;
    newDY = (float)sqrt(object_radius_y * object_radius_y + object_radius_x * object_radius_x);
    waypoint = path->currentWaypoint();
    if (waypoint == 0) {
        path_result = 0;
    } else {
        waypoint = path->currentWaypoint();
        float dx = waypoint->x - this->world_x;
        waypoint = path->currentWaypoint();
        float dy = waypoint->y - this->world_y;
        if ((float)sqrt(dy * dy + dx * dx) == DAT_00570b48) {
            path_result = 1;
            waypoint = path->currentWaypoint();
            float y = waypoint->y;
            waypoint = path->currentWaypoint();
            path_result = pathSystem.passable(this, waypoint->x, y, path_result);
            if (path_result != 0) {
                this->teleport(path->currentWaypoint()->x,
                               path->currentWaypoint()->y,
                               path->currentWaypoint()->z);
            }
            path->moveToNextWaypoint();
            this->closestDistanceToWaypoint = 100000.0f;
        }
    }

    distanceToGoal = 0.0f;
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

        do {
            this->removeUserDefinedWaypoint(0);
            if (this->numberUserDefinedWaypointsValue < 1) {
                return 0;
            }
            retry_dx = (float)this->userDefinedWaypoints[0].x - this->world_x;
            retry_dy = (float)this->userDefinedWaypoints[0].y - this->world_y;
        } while (newDY + this->actionRange - DAT_00570ba8 >=
                 (float)sqrt(retry_dy * retry_dy + retry_dx * retry_dx));

        int old_continue = this->continueCounter;
        int next_continue = old_continue - 1;
        this->continueCounter = next_continue;
        if (next_continue < 1) {
            this->speed = 0.0f;
            this->rangeStatusValue = 2;
            if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
            }
            this->continueCounter = old_continue + 4;
            return 1;
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
            while (i < path->numberOfWaypoints()) {
                fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i,
                        path->currentWaypoint()->x,
                        path->currentWaypoint()->y);
                i++;
                path->moveToNextWaypoint();
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
                    if (this->numberUserDefinedWaypointsValue < 2) {
                        return 0;
                    }
                    this->continueCounter += 5;
                    return found;
                }
                this->teleport(
                    (float)(floor((double)this->world_x) - DAT_00570b80),
                    (float)(floor((double)this->world_y) - DAT_00570b80),
                    this->world_z);
            }
        }

        if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
            path->initToStart();
            int i = 0;
            int n = path->numberOfWaypoints();
            while (i < n) {
                RGE_Master_Static_Object* master =
                    this->owner->master_objects[displayPathObjectID];
                master->make_new_obj(this->owner,
                                     path->currentWaypoint()->x,
                                     path->currentWaypoint()->y,
                                     1.0f);
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
            if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
            }
            this->continueCounter += 5;
            return 1;
        }
        this->closestDistanceToWaypoint = 100000.0f;
    }

    waypoint = path->currentWaypoint();
    if (waypoint != 0) {
        int result = this->doTrivialMove(path->currentWaypoint()->x,
                                         path->currentWaypoint()->y);
        if (result == 5) {
            goto range_success;
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

            do {
                this->removeUserDefinedWaypoint(0);
                if (this->numberUserDefinedWaypointsValue < 1) {
                    return 0;
                }
                retry_dx = (float)this->userDefinedWaypoints[0].x - this->world_x;
                retry_dy = (float)this->userDefinedWaypoints[0].y - this->world_y;
            } while (newDY + this->actionRange - DAT_00570ba8 >=
                     (float)sqrt(retry_dy * retry_dy + retry_dx * retry_dx));

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
                while (i < path->numberOfWaypoints()) {
                    fprintf(actionFile, ", WP#%d(%6.2f, %6.2f)", i,
                            path->currentWaypoint()->x,
                            path->currentWaypoint()->y);
                    i++;
                    path->moveToNextWaypoint();
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
                        if (this->numberUserDefinedWaypointsValue < 2) {
                            return 0;
                        }
                        this->continueCounter += 5;
                        return found;
                    }
                    this->teleport(
                        (float)(floor((double)this->world_x) - DAT_00570b80),
                        (float)(floor((double)this->world_y) - DAT_00570b80),
                        this->world_z);
                }
            }

            if (displayPathingFlags != 0 && (this->selected & 1) != 0) {
                path->initToStart();
                int i = 0;
                int n = path->numberOfWaypoints();
                while (i < n) {
                    RGE_Master_Static_Object* master =
                        this->owner->master_objects[displayPathObjectID];
                    master->make_new_obj(this->owner,
                                         path->currentWaypoint()->x,
                                         path->currentWaypoint()->y,
                                         1.0f);
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
                if (this->numberUserDefinedWaypointsValue < 2) {
                    return 0;
                }
                this->continueCounter += 5;
                return 1;
            }
            this->closestDistanceToWaypoint = 100000.0f;
        }
    }

    this->rangeStatusValue = 2;
    return 1;

range_success:
    this->rangeStatusValue = 1;
    this->removeAllUserDefinedWaypoints(0);
    this->pathingGroupMembers.numberValue = 0;
    return 2;
}
