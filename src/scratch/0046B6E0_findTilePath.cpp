// VA: 0046B6E0 PathingSystem::findTilePath
// PDB source: pathsys.cpp
// Attempt log:
// - Started from the Ghidra/PDB packet and reconstructed the full high-level pathing routine rather than a tiny placeholder.
// - Added a local PathingSystem/RGE object layout surface from the inventory type dumps: facet/cost/open heap/obstruction/misc arrays and the +0x11DCxx working fields are modeled at their binary offsets.
// - Added real member-call surfaces for Path::killPath, RGE_Game_World::object/objectGroupOnTile, RGE_Static_Object obstruction-map helpers, RGE_Moving_Object::setInitialPoints, and RGE_Player::computerPlayer.
// - Added padded virtual surfaces for the observed calls at vtable +0xF4/+0xFC/+0x130 and the rge_base_game redraw path.
// - This is a broad behavioral scaffold, not an exact candidate.  The hard areas still needing packet-by-packet shaping are the FPU footprint conversion block, direction/footprint switch details, obstruction scanning topology, heap sift code, and duplicated obstruction-restore tails.
// - Expanded the direction footprint rectangle switch enough for a full-length compare; no padding or inline asm was used.
// - check_function 2026-05-30: MISMATCH, 6522/6946 positional bytes differ (93.8958%), edit diff 8355, first mismatch offset 4.  Rebuilt prologue has VC5 stack alignment (`and esp, -8`) and a smaller frame (`sub esp,74h`) while original is `sub esp,7Ch` without stack alignment.  A brief `#pragma optimize("y", off)` probe removed the alignment but shortened .text to 6688B, so it was rolled back.
// - shardB5-6B6E0 baseline: the typed PathingSystem layout, pathsys call family,
//   and full path-search control flow compile as a 7072-byte structural candidate.
//   The current check is 6866 differing bytes, frame 0x74 versus 0x7c, and 66
//   ordered calls versus 75.  The first hard gap is eight missing __ftol calls;
//   structural and conversion-source work must precede any register variants.
// - No codegen variants were run in this tranche.  The current source remains
//   the best typed behavior reconstruction for the next worker.
// - luna-46B6E0-r1 corrected min/max initial positions to use world coordinates,
//   object radii, and the observed scale constant; this recovered four target
//   __ftol calls and reduced the size gap.
// - Reconstructed the separate float footprint bounds and four-times bounds
//   after setInitialPoints.  Reusing dead parameter homes restored all twenty
//   target __ftol calls and reduced the frame from 0x84 to 0x74.
// - Split the success and failure obstruction-map tails to preserve the two
//   observed current-object add sites.  The target call count now matches 75.
// - Removed badBounds and reversed the tolerance comparison for direct guard
//   and FPU order.  A local optimize-y pragma was tested and rolled back:
//   it improved bytes but produced an implausible 0x68 frame.
// - Direct integer zero stores for the two early costOut exits reduced the
//   candidate by 4 bytes and matched the original store form.
// - Moved the shared success restore tail before heap exhaustion.  This
//   restored the original 75-call order and raised shape similarity to 60%.
// - Reused the dead goalY parameter home for repeated path-group resize
//   pointers, matching the original allocation scratch without a new local.
// - Reduced the distance estimate to signed deltas and absolute values.
//   This reached the original 0x7c frame and exact function size.
// - Tested and rolled back ordered estimate swaps, unobPlayerID scratch,
//   shared direction-Y goto, and display-mask temporary variants when they
//   worsened structural output.  The current source remains typed and plain.
// - luna-46B6E0-r2 tested spelling the initial tolerance gate with tolerance
//   on the left.  It matched the original FPU load order and improved shape
//   by 0.14 points, but worsened positional diff by 6 bytes; restored clean.
// - luna-46B6E0-r4 tested the exact named global surface: DAT_00570e54..78
//   from game_globals.h, plus Ghidra-proven MapPathsDisplay,
//   numberPathingIterations, rge_base_game, DiagionalDistance, FacetSkipMask,
//   ObstructionValueShift, and ObstructionMasks declarations.  The named
//   surface changed the prologue, frame, call order, and size by 118-126
//   bytes.  It was restored.  This scratch candidate still has a global-surface
//   blocker: the best codegen requires the original globals to remain bound by
//   address until a matching shared declaration context is found.
// - Tested delaying the display-mask store until after the typed tile-pointer
//   increment.  It reduced positional diff by 129 bytes but made the source
//   decompiler-shaped and worsened CFG/edit similarity.  The current pass
//   retains it because the executable proves the byte load/store order.
// - Current pass: 20 evidence-led probes.  The clean source keeps exact size,
//   frame, and all 75 ordered calls, but remains nonexact at 6539 differing
//   bytes.  The first blocker remains VC5 stack alignment and local-home
//   layout.  No exact source was found.
// - BINARY NOTE: the entry gate takes the full path when tolerance <= the
//   shipped float at 00570E54.  The FPU status test proves this direction.
// - BINARY NOTE: display clearing loads the draw byte before advancing the
//   tile cursor, then stores the masked byte through the prior tile.

#include <math.h>
#include <string.h>

typedef unsigned char uchar;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

class RGE_Static_Object;
class RGE_Moving_Object;
class RGE_Game_World;
class RGE_Map;
class RGE_Tile;
class RGE_Player;
class RGE_View;

#define FADDR(a) (*(float*)(a))
#define DADDR(a) (*(double*)(a))
#define MapPathsDisplay (*(int*)0x86B138)
#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define numberPathingIterations (*(int*)0x57F9F4)
#define DiagionalDistance ((int*)0x74D040)
#define FacetSkipMask ((int*)0x584EF8)
#define ObstructionValueShift ((unsigned char*)0x584EF4)
#define ObstructionMasks ((unsigned int*)0x584F20)

#define VPAD1(n) virtual void vpad_##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

#define ESTIMATE_DISTANCE(out, ax, ay, bx, by) do { \
    int _ed_dx = (ax) - (bx); \
    int _ed_dy = (ay) - (by); \
    int _ed_diag; \
    int _ed_straight; \
    if (_ed_dx < 0) _ed_dx = -_ed_dx; \
    if (_ed_dy < 0) _ed_dy = -_ed_dy; \
    if (_ed_dx < _ed_dy) { _ed_diag = _ed_dx; _ed_straight = _ed_dy - _ed_dx; } \
    else { _ed_diag = _ed_dy; _ed_straight = _ed_dx - _ed_dy; } \
    (out) = DiagionalDistance[_ed_diag & 0xff] + _ed_straight * 4; \
} while (0)

struct XYPoint {
    int x;
    int y;
};

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad[3];
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
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

    void killPath();
};

class __declspec(novtable) RGE_View {
public:
    VPAD8(view0)
    virtual void redraw(int mode);
};

class __declspec(novtable) RGE_Base_Game {
public:
    VPAD8(bg0) VPAD2(bg8) VPAD1(bg10)
    virtual RGE_View* get_view();
};

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    unsigned char master_type;
    unsigned char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char pad_16[0x10];
    float los;
    unsigned char obj_max;
    unsigned char pad_2d[3];
    float radius_x;
    float radius_y;
    float radius_z;
    unsigned char pad_3c[0x2a];
    short terrain;
};

class RGE_Player {
public:
    void* vtable_ptr;
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    char pad_14[0x36];
    short id;

    int computerPlayer();
};

class __declspec(novtable) RGE_Static_Object {
public:
    VPAD32(so0) VPAD16(so32) VPAD8(so48) VPAD4(so56) VPAD1(so60)
    virtual float vf_f4();
    VPAD1(so62)
    virtual float vf_fc();
    VPAD8(so64) VPAD4(so72)
    virtual unsigned char vf_130();

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
    ManagedArray_int pathingGroupMembers;
    ManagedArray_int groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char pad_end;

    int removeFromObstructionMap(int aiPS);
    int addToObstructionMap(int aiPS);
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
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;
    void* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char pad_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;
    unsigned char pad_17e[2];

    void setInitialPoints(XYPoint* minp, XYPoint* maxp);
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
    char objects[0x0c];
};

class RGE_Border_Set {
public:
    char pad_000[0x59c];
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    void* vtable_ptr;
    RGE_Tile* map;
    int map_width;
    int map_height;
    int world_width;
    int world_height;
    char pad_18[0x338c - 0x18];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char pad_04[0x50];
    float** terrains;

    int objectGroupOnTile(int playerId, int objectGroup, int tileX, int tileY, int* objectCountOnTile);
    RGE_Static_Object* object(int id);
};

class PathingSystem {
public:
    void* vtable_ptr;
    int xSizeValue;
    int ySizeValue;
    unsigned char facetValue[255][255];
    unsigned char pad_fe0d[3];
    int MGP_costValue[255][255];
    struct MGP_FloatHeap {
        unsigned char x;
        unsigned char y;
        unsigned short next;
        int total;
    };
    MGP_FloatHeap MGP_openPaths[65026];
    unsigned char obstructionValue[1020][255];
    unsigned char miscValue[255][255];
    unsigned char pad_11dc29[3];
    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    RGE_Map* mapValue;
    RGE_Game_World* worldValue;
    RGE_Moving_Object* currentObject;
    int currentObjectInObMap;
    int currentTargetID;
    float* currentTerrainTable;
    float currentXOffset;
    float currentYOffset;
    int currentTerrainException1;
    int currentTerrainException2;
    ManagedArray_int initialCollidingObjects;
    int startOfPath;
    int checkTerrainOnFirstPass;
    XYPoint initialTile;
    XYPoint minTarget;
    XYPoint maxTarget;
    XYPoint minInitialPosition;
    XYPoint maxInitialPosition;
    float averageNumWaypoints;
    float averagePathLength;
    float averagePathIterations;
    int numAttempts;
    int numFails;
    int numSuccesses;
    int numInitialPathsValue;
    int numContinuePathsValue;
    int numCanPathsValue;
    int MGP_closestTargetDistance;
    float averageClosestTargetDistance;
    float averageSuccessTime;
    float averageFailTime;
    unsigned char CurrentFacetMask;
    unsigned char pad_11dcd9[3];
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray_int currentUnobstructibles;
    int aiPS;

    int passable(RGE_Moving_Object* obj, float x, float y, int checkObjects);
    int copyPath(int step);
    int findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object* obj,
                     float tolerance, int targetID, int mode, float* costOut, int useIterationCap,
                     int checkObstructions, int checkTerrain, int step, int unobPlayerID,
                     int unobGroupID);
};

#define ACTIVE_PATH(o) ((o)->storePathInExceptionPath ? &(o)->exceptionPathValue : &(o)->pathValue)

#define RESTORE_COLLIDING_OBJECTS(ps) do { \
    RGE_Moving_Object* _rc_obj = (ps)->currentObject; \
    int _rc_i = 0; \
    while (_rc_i < _rc_obj->pathingGroupMembers.numberValue) { \
        int _rc_index = _rc_i; \
        if (_rc_obj->pathingGroupMembers.maximumSizeValue - 1 < _rc_i) { \
            goalY = (int)operator_new(_rc_i * 4 + 4); \
            if (goalY != 0) { \
                int _rc_j = 0; \
                while (_rc_j < _rc_obj->pathingGroupMembers.maximumSizeValue && _rc_j < _rc_i + 1) { \
                    ((int*)goalY)[_rc_j] = _rc_obj->pathingGroupMembers.value[_rc_j]; \
                    ++_rc_j; \
                } \
                operator_delete(_rc_obj->pathingGroupMembers.value); \
                _rc_obj->pathingGroupMembers.value = (int*)goalY; \
                _rc_obj->pathingGroupMembers.maximumSizeValue = _rc_i + 1; \
            } \
        } \
        RGE_Static_Object* _rc_other = (ps)->worldValue->object(_rc_obj->pathingGroupMembers.value[_rc_index]); \
        if (_rc_other != 0 && _rc_other->id != (ps)->currentObject->id && \
            _rc_other->lastInObstructionMapValue == 1 && _rc_other->inside_obj == 0) { \
            _rc_other->addToObstructionMap((ps)->aiPS); \
        } \
        ++_rc_i; \
    } \
} while (0)

int PathingSystem::findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object* obj,
                                float tolerance, int targetID, int mode, float* costOut,
                                int useIterationCap, int checkObstructions, int checkTerrain,
                                int step, int unobPlayerID, int unobGroupID)
{
    int dist;
    int currentEstimate;
    int bestLimit;
    int iterationCap;
    int iterations;
    int i;
    int skipBit;
    int heapCount;
    int hole;
    int child;
    int tempTotal;
    int curX;
    int curY;
    int nextX;
    int nextY;
    int oldX;
    int oldY;
    int status;
    int found;
    int hitCount;
    int hitId;
    int row;
    int col;
    int minScanX;
    int maxScanX;
    int minScanY;
    int maxScanY;
    int left;
    int right;
    int top;
    int bottom;
    int widthCount;
    int h;
    int maskIndex;
    int objectHit;
    int foundBlockingOwnGroup;
    int objectCountOnTile;
    int newCost;
    int parentCost;
    int oldHeuristic;
    int newHeuristic;
    int misc;
    int directionFromHere;
    int currentFacet;
    int deltaMinX;
    int deltaMinY;
    int deltaMaxX;
    int deltaMaxY;
    int scanLeftRaw;
    int scanTopRaw;
    int scanRightRaw;
    int scanBottomRaw;
    int tmp;
    int tmp2;
    int openIndex;
    int parentIndex;
    int insertIndex;
    int movedIndex;
    int copiedX;
    int copiedY;
    int savedTotal;
    int restoreResult;
    int reached;
    float unobstructibleObjectHitpoints;
    float fx;
    float fy;
    RGE_Map* map;
    RGE_Tile* tile;
    RGE_Static_Object* target;
    RGE_Static_Object* other;
    RGE_Moving_Object* curObj;
    RGE_Master_Static_Object* master;
    Path* path;
    unsigned char facetByte;
    unsigned char facetLow;
    unsigned char thisMask;
    unsigned int maskA;
    unsigned int maskB;
    unsigned char* obstructionPtr;

    if (startX < 0 || startY < 0 || startX > this->xSizeValue || startY > this->xSizeValue ||
        goalX < 0 || goalY < 0 || goalX > this->xSizeValue || goalY > this->xSizeValue) {
        if (mode == 1) {
            path = ACTIVE_PATH(obj);
            path->killPath();
        }
        return 0;
    }

    if (tolerance <= FADDR(0x570E54)) {
        ESTIMATE_DISTANCE(dist, goalX, goalY, startX, startY);
        if ((float)dist < tolerance * FADDR(0x570E58)) {
            if (costOut != 0) *costOut = 0;
            if (mode == 1) {
                path = ACTIVE_PATH(obj);
                path->killPath();
            }
            return 1;
        }
        if (obj->vf_fc() == FADDR(0x570E5C)) {
            if (costOut != 0) *costOut = 0;
            if (mode == 1) {
                path = ACTIVE_PATH(obj);
                path->killPath();
            }
            return 0;
        }
    }

    this->currentObject = obj;
    this->currentTerrainTable = this->worldValue->terrains[obj->master_obj->terrain];
    this->currentTerrainException1 = obj->currentTerrainException1;
    this->currentTerrainException2 = obj->currentTerrainException2;
    this->currentUnobstructiblePlayerID = unobPlayerID;
    this->currentUnobstructibleGroupID = unobGroupID;
    this->currentUnobstructibles.numberValue = 0;

    if (MapPathsDisplay != 0) {
        map = this->mapValue;
        row = 0;
        while (row < map->map_height) {
            tile = map->map_row_offset[row];
            col = 0;
            while (col < map->map_width) {
                unsigned char drawAttribute = tile->draw_attribute;
                ++tile;
                ++col;
                (tile - 1)->draw_attribute = (unsigned char)(drawAttribute & 0x70);
            }
            ++row;
            map = this->mapValue;
        }
        rge_base_game->get_view()->redraw(2);
    }

    this->minTarget.x = goalX * 4;
    this->minTarget.y = goalY * 4;
    this->currentTargetID = targetID;
    this->maxTarget.x = goalX * 4 + 3;
    this->maxTarget.y = goalY * 4 + 3;
    if (targetID != -1) {
        target = this->worldValue->object(targetID);
        if (target == 0) {
            this->currentTargetID = -1;
        } else {
            this->minTarget.x = (int)((target->world_x - target->master_obj->radius_x) * FADDR(0x570E60));
            this->minTarget.y = (int)((target->world_y - target->master_obj->radius_y) * FADDR(0x570E60));
            this->maxTarget.x = (int)((target->master_obj->radius_x + target->world_x) * FADDR(0x570E60));
            this->maxTarget.y = (int)((target->master_obj->radius_y + target->world_y) * FADDR(0x570E60));
        }
    }

    this->startOfPath = 1;
    this->checkTerrainOnFirstPass = checkTerrain;
    this->currentObjectInObMap = obj->removeFromObstructionMap(this->aiPS);

    fx = (float)floor((double)obj->world_x) - FADDR(0x570E64);
    fy = (float)floor((double)obj->world_y) - FADDR(0x570E64);
    if (this->passable(obj, fx, fy, 1) == 0) {
        this->currentXOffset = obj->world_x - (float)floor((double)obj->world_x);
        this->currentYOffset = obj->world_y - (float)floor((double)obj->world_y);
    } else {
        this->currentXOffset = FADDR(0x570E64);
        this->currentYOffset = FADDR(0x570E64);
    }

    curObj = this->currentObject;
    if (curObj->continueCounter >= 10 && curObj->pathingGroupMembers.numberValue > 0) {
        i = 0;
        while (i < curObj->pathingGroupMembers.numberValue) {
            if (curObj->pathingGroupMembers.maximumSizeValue - 1 < i) {
                int* newValue = (int*)operator_new(i * 4 + 4);
                if (newValue != 0) {
                    int j = 0;
                    while (j < curObj->pathingGroupMembers.maximumSizeValue && j < i + 1) {
                        newValue[j] = curObj->pathingGroupMembers.value[j];
                        ++j;
                    }
                    operator_delete(curObj->pathingGroupMembers.value);
                    curObj->pathingGroupMembers.value = newValue;
                    curObj->pathingGroupMembers.maximumSizeValue = i + 1;
                }
            }
            other = this->worldValue->object(curObj->pathingGroupMembers.value[i]);
            if (other != 0 && other->id != this->currentObject->id) {
                unsigned char canShare = other->vf_130();
                float cap = other->vf_f4();
                float held = other->attribute_amount_held;
                if (canShare != 0 || cap != FADDR(0x570E5C) || held > FADDR(0x570E5C)) {
                    other->removeFromObstructionMap(this->aiPS);
                }
            }
            curObj = this->currentObject;
            ++i;
        }
    }

    curObj = this->currentObject;
    master = curObj->master_obj;
    this->minInitialPosition.x = (int)((curObj->world_x - master->radius_x) * FADDR(0x570E60));
    if (this->minInitialPosition.x < 0) this->minInitialPosition.x = 0;
    this->minInitialPosition.y = (int)((curObj->world_y - master->radius_y) * FADDR(0x570E60));
    if (this->minInitialPosition.y < 0) this->minInitialPosition.y = 0;
    this->maxInitialPosition.x = (int)((master->radius_x + curObj->world_x) * FADDR(0x570E60));
    tmp = this->xSizeValue * 4;
    if (this->maxInitialPosition.x > tmp) this->maxInitialPosition.x = tmp;
    this->maxInitialPosition.y = (int)((master->radius_y + curObj->world_y) * FADDR(0x570E60));
    tmp = this->ySizeValue * 4;
    if (this->maxInitialPosition.y > tmp) this->maxInitialPosition.y = tmp;

    curObj->setInitialPoints(&this->minInitialPosition, &this->maxInitialPosition);

    this->initialTile.y = startY;
    this->initialTile.x = startX;
    this->MGP_closestTargetDistance = -1;
    if (this->CurrentFacetMask >= 0xf0) {
        this->CurrentFacetMask = 0;
        memset(this->facetValue, 0xff, sizeof(this->facetValue));
    } else {
        this->CurrentFacetMask = (unsigned char)(this->CurrentFacetMask + 8);
    }
    this->numberOpenPathsValue = 1;
    this->numberTraversedPathsValue = 0;

    ESTIMATE_DISTANCE(startY, goalX, goalY, startX, startY);
    this->MGP_costValue[startX][startY] = startY;
    this->MGP_openPaths[1].total = startY;
    this->MGP_bestTraversedPath.total = startY;
    this->MGP_openPaths[1].x = (unsigned char)startX;
    this->MGP_openPaths[1].y = (unsigned char)startY;
    this->MGP_openPaths[0].total = -2000000000;
    this->MGP_bestTraversedPath.x = (unsigned char)startX;
    this->MGP_bestTraversedPath.y = (unsigned char)startY;

    if ((float)step <= tolerance) bestLimit = (int)(tolerance * FADDR(0x570E58));
    else bestLimit = step << 4;

    deltaMinX = (int)(((this->currentXOffset - FADDR(0x570E68)) - master->radius_x) - FADDR(0x570E6C)) - 100;
    deltaMaxX = (int)((master->radius_x + this->currentXOffset) - FADDR(0x570E70)) - 100;
    deltaMinY = (int)(((this->currentYOffset - FADDR(0x570E68)) - master->radius_y) - FADDR(0x570E6C)) - 100;
    deltaMaxY = (int)((master->radius_y + this->currentYOffset) - FADDR(0x570E70)) - 100;
    startX = -400 - (int)((this->currentXOffset - FADDR(0x570E68) - master->radius_x) * FADDR(0x570E74));
    startY = -400 - (int)((this->currentYOffset - FADDR(0x570E68) - master->radius_y) * FADDR(0x570E74));
    targetID = -400 - (int)((master->radius_x + this->currentXOffset - FADDR(0x570E68)) * FADDR(0x570E74));
    unobPlayerID = -400 - (int)((master->radius_y + this->currentYOffset - FADDR(0x570E68)) * FADDR(0x570E74));

    tmp = goalX - startX;
    tmp2 = goalY - startY;
    iterationCap = (int)(sqrt((float)(tmp * tmp + tmp2 * tmp2)) * DADDR(0x570E78));
    iterationCap = (iterationCap + ((iterationCap >> 31) & 0x0f)) >> 4;
    if (iterationCap <= 10) iterationCap = (iterationCap * numberPathingIterations) / 10;
    else iterationCap = (iterationCap * numberPathingIterations) / 100;
    if (this->currentObject->owner->id == 0 && iterationCap > 100) iterationCap = 100;
    if (this->currentObject->owner->computerPlayer() == 1) iterationCap = (iterationCap * 0x9c4) / 100;

    iterations = 0;
    while (this->numberOpenPathsValue > 0) {
        if (numberPathingIterations != -1 && useIterationCap == 1 && iterations > iterationCap) break;
        if (iterations > 0x4e20) break;

        curX = this->MGP_openPaths[1].x;
        curY = this->MGP_openPaths[1].y;
        if (MapPathsDisplay != 0) {
            this->mapValue->map_row_offset[curY][curX].draw_attribute = 0x81;
        }

        tmp = goalX - curX;
        tmp2 = goalY - curY;
        currentEstimate = (int)(sqrt((float)(tmp * tmp + tmp2 * tmp2)) * DADDR(0x570E78));
        if (this->MGP_closestTargetDistance == -1 || currentEstimate < this->MGP_closestTargetDistance) {
            this->MGP_closestTargetDistance = currentEstimate;
        }

        if (currentEstimate < bestLimit) {
            if (mode == 1 && this->copyPath(step) == 0) {
                ACTIVE_PATH(obj)->killPath();
                RESTORE_COLLIDING_OBJECTS(this);
                restoreResult = 0;
                goto final_failure_restore;
            }
            if (costOut != 0) *costOut = (float)this->MGP_costValue[curX][curY];
            RESTORE_COLLIDING_OBJECTS(this);
            restoreResult = 1;
            goto final_success_restore;
        }

        if (currentEstimate < this->MGP_bestTraversedPath.total) {
            this->MGP_bestTraversedPath.total = currentEstimate;
            this->MGP_bestTraversedPath.x = (unsigned char)curX;
            this->MGP_bestTraversedPath.y = (unsigned char)curY;
        }

        ++this->numberTraversedPathsValue;
        heapCount = this->numberOpenPathsValue;
        copiedX = this->MGP_openPaths[heapCount].x;
        copiedY = this->MGP_openPaths[heapCount].y;
        savedTotal = this->MGP_openPaths[heapCount].total;
        --heapCount;
        this->numberOpenPathsValue = heapCount;
        hole = 1;
        while (hole < heapCount / 2) {
            child = hole * 2;
            if (child < heapCount && this->MGP_openPaths[child + 1].total < this->MGP_openPaths[child].total) ++child;
            if (savedTotal < this->MGP_openPaths[child].total) break;
            this->MGP_openPaths[hole] = this->MGP_openPaths[child];
            hole = child;
        }
        if (hole != 1) {
            this->MGP_openPaths[hole].x = (unsigned char)copiedX;
            this->MGP_openPaths[hole].y = (unsigned char)copiedY;
            this->MGP_openPaths[hole].total = savedTotal;
        } else if (heapCount > 0) {
            this->MGP_openPaths[1].x = (unsigned char)copiedX;
            this->MGP_openPaths[1].y = (unsigned char)copiedY;
            this->MGP_openPaths[1].total = savedTotal;
        }

        i = 0;
        skipBit = 1;
        nextX = curX;
        nextY = curY;
        while (i < 8) {
            switch (i) {
            case 0: nextX -= step; nextY -= step; break;
            case 1:
            case 2: nextX += step; break;
            case 3:
            case 4: nextY += step; break;
            case 5:
            case 6: nextX -= step; break;
            case 7: nextY -= step; break;
            }

            facetByte = this->facetValue[curX][curY];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) currentFacet = facetByte & 7;
            else currentFacet = 8;
            if ((FacetSkipMask[currentFacet] & skipBit) != 0) goto next_direction;
            if (nextX < 0 || nextY < 0 || nextX >= this->xSizeValue || nextY >= this->ySizeValue) goto next_direction;
            if (nextX == this->initialTile.x && nextY == this->initialTile.y) goto next_direction;

            tmp = nextX - curX;
            tmp2 = nextY - curY;
            tmp = (int)(sqrt((float)(tmp * tmp + tmp2 * tmp2)) * DADDR(0x570E78));
            parentCost = this->MGP_costValue[curX][curY];
            ESTIMATE_DISTANCE(oldHeuristic, goalX, goalY, curX, curY);
            ESTIMATE_DISTANCE(newHeuristic, goalX, goalY, nextX, nextY);
            newCost = newHeuristic + tmp + parentCost - oldHeuristic;

            facetByte = this->facetValue[nextX][nextY];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) directionFromHere = facetByte & 7;
            else directionFromHere = -1;
            if (directionFromHere < 8 && this->MGP_costValue[nextX][nextY] <= newCost) goto next_direction;

            status = 1;
            scanLeftRaw = nextX * 4;
            scanTopRaw = nextY * 4;
            scanRightRaw = scanLeftRaw + step * 4;
            scanBottomRaw = scanTopRaw + step * 4;
            switch (i) {
            case 0:
                scanLeftRaw = nextX * 4 + startX;
                scanTopRaw = nextY * 4 + startY;
                scanRightRaw = curX * 4 + deltaMaxX;
                scanBottomRaw = curY * 4 + deltaMaxY;
                break;
            case 1:
                scanLeftRaw = nextX * 4 + deltaMinX;
                scanTopRaw = nextY * 4 + startY;
                scanRightRaw = curX * 4 + deltaMaxX;
                scanBottomRaw = curY * 4 + deltaMaxY;
                break;
            case 2:
                scanLeftRaw = curX * 4 + deltaMinX;
                scanTopRaw = nextY * 4 + startY;
                scanRightRaw = nextX * 4 + targetID;
                scanBottomRaw = curY * 4 + deltaMaxY;
                break;
            case 3:
                scanLeftRaw = curX * 4 + deltaMinX;
                scanTopRaw = nextY * 4 + deltaMinY;
                scanRightRaw = nextX * 4 + targetID;
                scanBottomRaw = curY * 4 + deltaMaxY;
                break;
            case 4:
                scanLeftRaw = curX * 4 + deltaMinX;
                scanTopRaw = curY * 4 + deltaMinY;
                scanRightRaw = nextX * 4 + targetID;
                scanBottomRaw = nextY * 4 + unobPlayerID;
                break;
            case 5:
                scanLeftRaw = curX * 4 + deltaMinX;
                scanTopRaw = curY * 4 + deltaMinY;
                scanRightRaw = nextX * 4 + deltaMaxX;
                scanBottomRaw = nextY * 4 + unobPlayerID;
                break;
            case 6:
                scanLeftRaw = nextX * 4 + startX;
                scanTopRaw = curY * 4 + deltaMinY;
                scanRightRaw = curX * 4 + deltaMaxX;
                scanBottomRaw = nextY * 4 + unobPlayerID;
                break;
            case 7:
                scanLeftRaw = nextX * 4 + startX;
                scanTopRaw = curY * 4 + deltaMinY;
                scanRightRaw = curX * 4 + deltaMaxX;
                scanBottomRaw = nextY * 4 + deltaMaxY;
                break;
            }
            if (scanRightRaw < scanLeftRaw) { tmp = scanLeftRaw; scanLeftRaw = scanRightRaw; scanRightRaw = tmp; }
            if (scanBottomRaw < scanTopRaw) { tmp = scanTopRaw; scanTopRaw = scanBottomRaw; scanBottomRaw = tmp; }
            minScanX = scanLeftRaw;
            minScanY = scanTopRaw;
            maxScanX = scanRightRaw;
            maxScanY = scanBottomRaw;
            if (minScanX < 0) ++minScanX;
            if (minScanY < 0) ++minScanY;
            if (maxScanX < 0) ++maxScanX;
            if (maxScanY < 0) ++maxScanY;
            minScanX >>= 2;
            minScanY >>= 2;
            maxScanX >>= 2;
            maxScanY >>= 2;
            if (checkTerrain) {
                map = this->mapValue;
                if ((minScanX & 0xff) >= map->map_width || (minScanY & 0xff) >= map->map_height) {
                    status = 0xfe;
                } else {
                    row = minScanY & 0xff;
                    while (row <= (maxScanY & 0xff) && status == 1) {
                        col = minScanX & 0xff;
                        while (col <= (maxScanX & 0xff)) {
                            if (this->initialTile.x != col || this->initialTile.y != row) {
                                tile = &map->map_row_offset[row][col];
                                tmp = tile->terrain_type & 0x1f;
                                if (tmp != this->currentTerrainException1 && tmp != this->currentTerrainException2 && this->currentTerrainTable[tmp] <= DADDR(0x570E80)) {
                                    status = 0xfe;
                                    break;
                                }
                                tmp = tile->border_type & 0x0f;
                                if (tmp != 0 && this->currentTerrainTable[map->border_types[tmp].underlay_terrain] <= DADDR(0x570E80)) {
                                    status = 0xfe;
                                    break;
                                }
                            }
                            ++col;
                        }
                        ++row;
                    }
                }
            }

            if (status == 1 && checkObstructions == 1) {
                left = scanLeftRaw;
                right = scanRightRaw;
                top = scanTopRaw;
                bottom = scanBottomRaw;
                if (right < left) { tmp = left; left = right; right = tmp; }
                if (bottom < top) { tmp = top; top = bottom; bottom = tmp; }
                if (left < 0) ++left;
                if (right < 0) ++right;
                if (top < 0) ++top;
                if (bottom < 0) ++bottom;
                h = bottom - top - 1;
                objectHit = 0;
                if (h >= 0) {
                    if (h < 0x18 && (this->maxTarget.x < left || this->maxTarget.y < top || right < this->minTarget.x || bottom < this->minTarget.y)) {
                        maskIndex = (top & 3) + h * 4;
                        maskA = ObstructionMasks[maskIndex * 2];
                        maskB = ObstructionMasks[maskIndex * 2 + 1];
                        if (left < right) {
                            obstructionPtr = this->obstructionValue[left] + (top >> 2);
                            col = left;
                            while (col < right) {
                                if (((*(unsigned int*)obstructionPtr & maskA) != 0) ||
                                    (maskB != 0 && ((*(unsigned int*)(obstructionPtr + 4) & maskB) != 0))) {
                                    objectHit = 1;
                                    break;
                                }
                                ++col;
                                obstructionPtr += 0xff;
                            }
                        }
                    } else if (left < right) {
                        col = left;
                        while (col < right && objectHit == 0) {
                            row = top;
                            while (row < bottom) {
                                if (((this->obstructionValue[0][col * 0xff + (row >> 2)] >> (ObstructionValueShift[row & 3] & 0x1f)) & 3) != 0) {
                                    if (this->currentTargetID == -1 || col < this->minTarget.x || this->maxTarget.x < col || row < this->minTarget.y || this->maxTarget.y < row) {
                                        objectHit = 1;
                                        break;
                                    }
                                    foundBlockingOwnGroup = 1;
                                }
                                ++row;
                            }
                            ++col;
                        }
                    }
                }
                if (objectHit) status = 0xfe;
            }

            if (status == 1 && this->minTarget.x <= scanRightRaw && scanLeftRaw <= this->maxTarget.x &&
                this->minTarget.y <= scanBottomRaw && scanTopRaw <= this->maxTarget.y) {
                status = 0;
            }

            unobstructibleObjectHitpoints = FADDR(0x570E5C);
            if (status == 0xfe) {
                if (this->currentUnobstructibleGroupID == -1) goto next_direction;
                found = 0;
                hitCount = 0;
                minScanX = nextX - 1;
                if (minScanX < 0) minScanX = 0;
                maxScanX = nextX + 1;
                row = minScanX;
                while (row <= maxScanX && row < this->xSizeValue && hitCount == 0) {
                    minScanY = nextY - 1;
                    if (minScanY < 0) minScanY = 0;
                    maxScanY = nextY + 1;
                    col = minScanY;
                    while (col <= maxScanY && col < this->ySizeValue && hitCount == 0) {
                        objectCountOnTile = 0;
                        hitId = this->worldValue->objectGroupOnTile(this->currentUnobstructiblePlayerID, this->currentUnobstructibleGroupID, row, col, &objectCountOnTile);
                        if (hitId == -1) {
                            if (objectCountOnTile > 0) found = 1;
                        } else {
                            other = this->worldValue->object(hitId);
                            if (other != 0) {
                                unobstructibleObjectHitpoints = other->hp;
                                hitCount = 1;
                            }
                        }
                        ++col;
                    }
                    ++row;
                    hitCount = found;
                }
                if (hitCount == 1) goto next_direction;
            }

            misc = this->miscValue[nextX][nextY];
            newCost += misc * 0x10;
            if (unobstructibleObjectHitpoints != FADDR(0x570E5C)) {
                if (unobstructibleObjectHitpoints < 10.0f) newCost += 0x10;
                else newCost += 0x3c;
            }
            facetByte = this->facetValue[curX][curY];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) currentFacet = facetByte & 7;
            else currentFacet = 0xff;
            if (i != currentFacet) ++newCost;
            if (status == 0) newCost = 0;

            this->MGP_costValue[nextX][nextY] = newCost;
            this->facetValue[nextX][nextY] = (unsigned char)((i & 7) | this->CurrentFacetMask);
            openIndex = this->numberOpenPathsValue + 1;
            this->numberOpenPathsValue = openIndex;
            this->MGP_openPaths[openIndex].x = (unsigned char)nextX;
            this->MGP_openPaths[openIndex].y = (unsigned char)nextY;
            this->MGP_openPaths[openIndex].total = newCost;

            insertIndex = openIndex;
            if (insertIndex > 0) {
                copiedX = this->MGP_openPaths[insertIndex].x;
                copiedY = this->MGP_openPaths[insertIndex].y;
                savedTotal = this->MGP_openPaths[insertIndex].total;
                parentIndex = insertIndex / 2;
                while (savedTotal < this->MGP_openPaths[parentIndex].total) {
                    this->MGP_openPaths[insertIndex] = this->MGP_openPaths[parentIndex];
                    insertIndex = insertIndex / 2;
                    parentIndex = parentIndex / 2;
                }
                if (insertIndex != openIndex) {
                    this->MGP_openPaths[insertIndex].x = (unsigned char)copiedX;
                    this->MGP_openPaths[insertIndex].y = (unsigned char)copiedY;
                    this->MGP_openPaths[insertIndex].total = savedTotal;
                }
            }
            if (status == 0) {
                if (mode == 1 && this->copyPath(step) == 0) {
                    ACTIVE_PATH(obj)->killPath();
                    RESTORE_COLLIDING_OBJECTS(this);
                    restoreResult = 0;
                    goto final_failure_restore;
                }
                if (costOut != 0) *costOut = (float)this->MGP_costValue[curX][curY];
                RESTORE_COLLIDING_OBJECTS(this);
                restoreResult = 1;
                goto final_success_restore;
            }

next_direction:
            ++i;
            skipBit <<= 1;
        }

        ++iterations;
        this->startOfPath = 0;
    }

    goto path_exhausted;

final_success_restore:
    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return 1;

path_exhausted:
    openIndex = this->numberOpenPathsValue + 1;
    this->numberOpenPathsValue = openIndex;
    this->MGP_openPaths[openIndex].x = this->MGP_bestTraversedPath.x;
    this->MGP_openPaths[openIndex].y = this->MGP_bestTraversedPath.y;
    this->MGP_openPaths[openIndex].total = 0;
    if (openIndex > 0) {
        copiedX = this->MGP_openPaths[openIndex].x;
        copiedY = this->MGP_openPaths[openIndex].y;
        savedTotal = this->MGP_openPaths[openIndex].total;
        insertIndex = openIndex;
        parentIndex = insertIndex / 2;
        while (savedTotal < this->MGP_openPaths[parentIndex].total) {
            this->MGP_openPaths[insertIndex] = this->MGP_openPaths[parentIndex];
            insertIndex = insertIndex / 2;
            parentIndex = parentIndex / 2;
        }
        if (insertIndex != openIndex) {
            this->MGP_openPaths[insertIndex].x = (unsigned char)copiedX;
            this->MGP_openPaths[insertIndex].y = (unsigned char)copiedY;
            this->MGP_openPaths[insertIndex].total = savedTotal;
        }
    }

    if (mode == 1 && this->copyPath(step) == 0) {
        ACTIVE_PATH(obj)->killPath();
        RESTORE_COLLIDING_OBJECTS(this);
        restoreResult = 0;
    } else {
        if (costOut != 0) *costOut = (float)this->MGP_bestTraversedPath.total;
        RESTORE_COLLIDING_OBJECTS(this);
        restoreResult = 0;
    }

final_failure_restore:
    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return restoreResult;
}
