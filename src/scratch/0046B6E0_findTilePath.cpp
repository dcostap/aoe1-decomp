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
// - pi-01a01a7e completed a second 20-check pass.  It corrected the semantic
//   roles of parameters +0x30 and +0x34, the unconditional terrain scan, the
//   target-overlap obstruction result, unobstructible search state, heap pop,
//   computer-player iteration scaling, and the entry tolerance predicate.
// - The straight part of the distance estimate now uses the binary-proven
//   scale of 16.  The equivalent absolute-delta form remains because both an
//   ordered macro and an inline helper changed the frame and whole code basin.
// - Binding only DAT_00570e54 to its reviewed extern makes the entry compare
//   block exact.  The broad named-global surface remains unsuitable.
// - The clean source removes the two post-switch sorts absent from the target.
//   It keeps exact size, a 0x7C frame, and all 75 ordered calls.  The final
//   validation has 6717 differing bytes, 60.34% shape, 53.28% resync, and
//   18.99% exact-block coverage.  The next work must reconstruct the separate
//   terrain and obstruction bound outputs without adding local homes.
// - pi-01a01a7e completed a third 18-check pass.  Separate double conversions
//   of squared deltas recover the target fild/fild/faddp/fsqrt sequence.
//   Explicit X-then-Y footprint minima recover the target evaluation order.
// - The initial heuristic now uses `dist`.  It no longer overwrites startY and
//   corrupts initial tile indexes.  oldX and oldY preserve the original start
//   tile for the later geometric iteration estimate.
// - directionFromHere is now an unsigned byte with an FF sentinel.  This makes
//   target blocks +0C24 and +0C27 exact.  A separate byte facetLow models the
//   later turn-cost direction without changing the integer skip-mask index.
// - A refined eight-bound switch confirms the binary's separate tile and
//   quarter-bound model, but it adds 242 bytes in the current compiler basin.
//   A saved flat index and facet pointer also need that full liveness context;
//   isolated forms shrink the frame and lose exact blocks.
// - Final third-pass validation keeps exact size, a 0x7C frame, and all 75
//   ordered calls.  It has 6687 differing bytes, 60.67% shape, 53.83% resync,
//   and 18.31% exact-block coverage.  Stack alignment remains the first global
//   mismatch.  The standalone pragma optimize("y",off) form is not useful.
// - pi-01a01a7e completed a fourth 18-check pass.  Combining the full
//   eight-bound model with pragma optimize("y",off) removes stack alignment.
//   Target-proven byte terrain counters then reduce the size gap to 30 bytes
//   and add exact blocks +0E46, +0E4A, +0E61, +1146, and +12AF.
// - The loop contains a target-retained distance estimate before its geometric
//   fsqrt estimate.  VC5 removes most of the dead first result in simple forms.
// - currentTile and nextTile now own the two coordinate pairs.  This model
//   makes additional movement blocks exact and gives the best positional
//   result.  The final fourth-pass build is two bytes short with a 0x74 frame.
//   It has 6393 differing bytes, 41.99% shape, 53.64% resync, and 15.76%
//   exact-block coverage.  All 75 call targets remain present; two cold blocks
//   prevent full ordered alignment.  The next blocker is the missing two
//   coordinate-sized homes at the bottom of the target frame.
// - pi-01a01a7e completed a fifth 19-check pass.  A shared copiedTile restores
//   the target 0x7C frame and makes the prologue block exact.
// - Separate scalar quarter bounds free four input parameter homes for scratch.
//   This change raises shape and exact-block coverage across the cold restores.
// - deltaMin and scanMin use proven X/Y ownership.  Maximum bounds stay scalar;
//   their aggregate forms grow the frame or lose alignment.
// - A narrow volatile startY alias retains the target loop estimator table read
//   and store.  The ordered form matches its local control flow.
// - Final fifth-pass validation has exact size, a 0x7C frame, and 75 call
//   targets.  It has 6366 differing bytes, 44.92% shape, 50.79% resync, and
//   20.92% exact-block coverage.  Two cold blocks still prevent full call
//   alignment.  The entry estimator remains the first structural mismatch.
// - pi-01a01a7e completed a sixth 13-check pass.  Splitting loop failure from
//   path exhaustion restores the target cold-region order.  Shape rises above
//   57%, and four allocator blocks become exact.
// - PathTileWork owns current, next, and copied coordinate pairs in target
//   stack order.  Current now uses -7C/-78, and next uses -74/-70.
// - Four-temporary global estimators add 150 bytes.  Inline estimators remove a
//   required killPath call.  Keep the narrow ordered loop estimator only.
// - Byte copied-coordinate fields improve local shape but add 70 bytes.  Keep
//   dword fields until their separate scratch-home ownership is reconstructed.
// - Final sixth-pass validation has exact size, a 0x7C frame, and 75 call
//   targets.  It has 6354 differing bytes, 57.56% shape, 57.86% resync, and
//   22.12% exact-block coverage.  The entry estimator is still the first hunk.
// - BINARY NOTE: the entry gate runs the early distance tests only when
//   tolerance is greater than the shipped float at 00570E54.
// - BINARY NOTE: display clearing loads the draw byte before advancing the
//   tile cursor, then stores the masked byte through the prior tile.

#include <math.h>
#include <string.h>

typedef unsigned char uchar;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);
extern float DAT_00570e54;

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
    (out) = DiagionalDistance[_ed_diag & 0xff] + (_ed_straight << 4); \
} while (0)

#define ESTIMATE_DISTANCE_ORDERED(out, ax, ay, bx, by) do { \
    int _edo_ax = (ax); \
    int _edo_ay = (ay); \
    int _edo_bx = (bx); \
    int _edo_by = (by); \
    int _edo_swap; \
    int _edo_diag; \
    int _edo_straight; \
    if (_edo_ax < _edo_bx) { _edo_swap = _edo_ax; _edo_ax = _edo_bx; _edo_bx = _edo_swap; } \
    if (_edo_ay < _edo_by) { _edo_swap = _edo_ay; _edo_ay = _edo_by; _edo_by = _edo_swap; } \
    _edo_ax -= _edo_bx; \
    _edo_ay -= _edo_by; \
    if (_edo_ax < _edo_ay) { _edo_diag = _edo_ax; _edo_straight = _edo_ay - _edo_ax; } \
    else { _edo_diag = _edo_ay; _edo_straight = _edo_ax - _edo_ay; } \
    (out) = DiagionalDistance[_edo_diag & 0xff] + (_edo_straight << 4); \
} while (0)

struct XYPoint {
    int x;
    int y;
};

struct PathTileWork {
    XYPoint current;
    XYPoint next;
    XYPoint copied;
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
                     int checkTerrain, int checkObstructions, int step, int unobPlayerID,
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

#pragma optimize("y", off)
int PathingSystem::findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object* obj,
                                float tolerance, int targetID, int mode, float* costOut,
                                int useIterationCap, int checkTerrain, int checkObstructions,
                                int step, int unobPlayerID, int unobGroupID)
{
    int dist;
    int currentEstimate;
    volatile int& loopEstimate = startY;
    int bestLimit;
    int iterationCap;
    int iterations;
    int i;
    int skipBit;
    int heapCount;
    int hole;
    int child;
    int tempTotal;
    PathTileWork tileWork;
    int& curX = tileWork.current.x;
    int& curY = tileWork.current.y;
    int& nextX = tileWork.next.x;
    int& nextY = tileWork.next.y;
    int& copiedX = tileWork.copied.x;
    int& copiedY = tileWork.copied.y;
    int oldX;
    int oldY;
    int status;
    int found;
    int hitCount;
    int hitId;
    int row;
    int col;
    XYPoint scanMin;
    int& minScanX = scanMin.x;
    int& minScanY = scanMin.y;
    int maxScanX;
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
    unsigned char directionFromHere;
    int currentFacet;
    XYPoint deltaMin;
    int& deltaMinX = deltaMin.x;
    int& deltaMinY = deltaMin.y;
    int deltaMaxX;
    int deltaMaxY;
    int quarterMinX;
    int quarterMinY;
    int quarterMaxX;
    int quarterMaxY;
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
    unsigned char terrainRow;
    unsigned char terrainCol;
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

    if (tolerance > DAT_00570e54) {
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

    oldX = startX;
    oldY = startY;
    ESTIMATE_DISTANCE(dist, goalX, goalY, startX, startY);
    this->MGP_costValue[startX][startY] = dist;
    this->MGP_openPaths[1].total = dist;
    this->MGP_bestTraversedPath.total = dist;
    this->MGP_openPaths[1].x = (unsigned char)startX;
    this->MGP_openPaths[1].y = (unsigned char)startY;
    this->MGP_openPaths[0].total = -2000000000;
    this->MGP_bestTraversedPath.x = (unsigned char)startX;
    this->MGP_bestTraversedPath.y = (unsigned char)startY;

    if ((float)step <= tolerance) bestLimit = (int)(tolerance * FADDR(0x570E58));
    else bestLimit = step << 4;

    fx = (this->currentXOffset - FADDR(0x570E68)) - master->radius_x;
    deltaMinX = (int)(fx - FADDR(0x570E6C)) - 100;
    deltaMaxX = (int)((master->radius_x + this->currentXOffset) - FADDR(0x570E70)) - 100;
    fy = (this->currentYOffset - FADDR(0x570E68)) - master->radius_y;
    deltaMinY = (int)(fy - FADDR(0x570E6C)) - 100;
    deltaMaxY = (int)((master->radius_y + this->currentYOffset) - FADDR(0x570E70)) - 100;
    quarterMinX = -400 - (int)(fx * FADDR(0x570E74));
    quarterMinY = -400 - (int)(fy * FADDR(0x570E74));
    quarterMaxX = -400 - (int)((master->radius_x + this->currentXOffset - FADDR(0x570E68)) * FADDR(0x570E74));
    quarterMaxY = -400 - (int)((master->radius_y + this->currentYOffset - FADDR(0x570E68)) * FADDR(0x570E74));

    tmp = goalX - oldX;
    tmp2 = goalY - oldY;
    dist = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * DADDR(0x570E78));
    dist = (dist + ((dist >> 31) & 0x0f)) >> 4;
    if (dist <= 10) iterationCap = (dist * numberPathingIterations) / 10;
    else iterationCap = (dist * numberPathingIterations) / 100;
    if (this->currentObject->owner->id == 0 && iterationCap > 100) iterationCap = 100;
    if (this->currentObject->owner->computerPlayer() == 1) iterationCap = (dist * 0x9c4) / 100;

    iterations = 0;
    while (this->numberOpenPathsValue > 0) {
        if (numberPathingIterations != -1 && useIterationCap == 1 && iterations > iterationCap) break;
        if (iterations > 0x4e20) break;

        curX = this->MGP_openPaths[1].x;
        curY = this->MGP_openPaths[1].y;
        if (MapPathsDisplay != 0) {
            this->mapValue->map_row_offset[curY][curX].draw_attribute = 0x81;
        }

        ESTIMATE_DISTANCE_ORDERED(loopEstimate, goalX, goalY, curX, curY);
        tmp = goalX - this->MGP_openPaths[1].x;
        tmp2 = goalY - this->MGP_openPaths[1].y;
        currentEstimate = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * DADDR(0x570E78));
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
        this->MGP_openPaths[1] = this->MGP_openPaths[heapCount];
        --heapCount;
        this->numberOpenPathsValue = heapCount;
        copiedX = this->MGP_openPaths[1].x;
        copiedY = this->MGP_openPaths[1].y;
        savedTotal = this->MGP_openPaths[1].total;
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
            tmp = (int)(sqrt((double)(tmp * tmp) + (double)(tmp2 * tmp2)) * DADDR(0x570E78));
            parentCost = this->MGP_costValue[curX][curY];
            ESTIMATE_DISTANCE(oldHeuristic, goalX, goalY, curX, curY);
            ESTIMATE_DISTANCE(newHeuristic, goalX, goalY, nextX, nextY);
            newCost = newHeuristic + tmp + parentCost - oldHeuristic;

            facetByte = this->facetValue[nextX][nextY];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) directionFromHere = facetByte & 7;
            else directionFromHere = 0xff;
            if (directionFromHere < 8 && this->MGP_costValue[nextX][nextY] <= newCost) goto next_direction;

            status = 1;
            switch (i) {
            case 0:
                minScanX = nextX + deltaMinX;
                minScanY = nextY + deltaMinY;
                maxScanX = curX + deltaMaxX;
                maxScanY = curY + deltaMaxY;
                scanLeftRaw = nextX * 4 + quarterMinX;
                scanTopRaw = nextY * 4 + quarterMinY;
                scanRightRaw = curX * 4 + quarterMaxX;
                scanBottomRaw = curY * 4 + quarterMaxY;
                break;
            case 1:
                minScanX = curX + deltaMinX;
                minScanY = nextY + deltaMinY;
                maxScanX = curX + deltaMaxX;
                maxScanY = curY + deltaMaxY;
                scanLeftRaw = curX * 4 + quarterMinX;
                scanTopRaw = nextY * 4 + quarterMinY;
                scanRightRaw = curX * 4 + quarterMaxX;
                scanBottomRaw = curY * 4 + quarterMaxY;
                break;
            case 2:
                minScanX = curX + deltaMinX;
                minScanY = nextY + deltaMinY;
                maxScanX = nextX + deltaMaxX;
                maxScanY = curY + deltaMaxY;
                scanLeftRaw = curX * 4 + quarterMinX;
                scanTopRaw = nextY * 4 + quarterMinY;
                scanRightRaw = nextX * 4 + quarterMaxX;
                scanBottomRaw = curY * 4 + quarterMaxY;
                break;
            case 3:
                minScanX = curX + deltaMinX;
                minScanY = curY + deltaMinY;
                maxScanX = nextX + deltaMaxX;
                maxScanY = curY + deltaMaxY;
                scanLeftRaw = curX * 4 + quarterMinX;
                scanTopRaw = curY * 4 + quarterMinY;
                scanRightRaw = nextX * 4 + quarterMaxX;
                scanBottomRaw = curY * 4 + quarterMaxY;
                break;
            case 4:
                minScanX = curX + deltaMinX;
                minScanY = curY + deltaMinY;
                maxScanX = nextX + deltaMaxX;
                maxScanY = nextY + deltaMaxY;
                scanLeftRaw = curX * 4 + quarterMinX;
                scanTopRaw = curY * 4 + quarterMinY;
                scanRightRaw = nextX * 4 + quarterMaxX;
                scanBottomRaw = nextY * 4 + quarterMaxY;
                break;
            case 5:
                minScanX = curX + deltaMinX;
                minScanY = curY + deltaMinY;
                maxScanX = curX + deltaMaxX;
                maxScanY = nextY + deltaMaxY;
                scanLeftRaw = curX * 4 + quarterMinX;
                scanTopRaw = curY * 4 + quarterMinY;
                scanRightRaw = curX * 4 + quarterMaxX;
                scanBottomRaw = nextY * 4 + quarterMaxY;
                break;
            case 6:
                minScanX = nextX + deltaMinX;
                minScanY = curY + deltaMinY;
                maxScanX = curX + deltaMaxX;
                maxScanY = nextY + deltaMaxY;
                scanLeftRaw = nextX * 4 + quarterMinX;
                scanTopRaw = curY * 4 + quarterMinY;
                scanRightRaw = curX * 4 + quarterMaxX;
                scanBottomRaw = nextY * 4 + quarterMaxY;
                break;
            case 7:
                minScanX = nextX + deltaMinX;
                minScanY = curY + deltaMinY;
                maxScanX = curX + deltaMaxX;
                maxScanY = curY + deltaMaxY;
                scanLeftRaw = nextX * 4 + quarterMinX;
                scanTopRaw = curY * 4 + quarterMinY;
                scanRightRaw = curX * 4 + quarterMaxX;
                scanBottomRaw = curY * 4 + quarterMaxY;
                break;
            default:
                minScanX = nextX;
                minScanY = nextY;
                maxScanX = nextX;
                maxScanY = nextY;
                scanLeftRaw = nextX * 4 + quarterMinX;
                scanTopRaw = nextY * 4 + quarterMinY;
                scanRightRaw = nextX * 4 + quarterMaxX;
                scanBottomRaw = nextY * 4 + quarterMaxY;
                break;
            }
            if (minScanX < 0) ++minScanX;
            if (minScanY < 0) ++minScanY;
            if (maxScanX < 0) ++maxScanX;
            if (maxScanY < 0) ++maxScanY;
            map = this->mapValue;
            if ((maxScanX & 0xff) >= map->map_width || (maxScanY & 0xff) >= map->map_height) {
                status = 0xfe;
            } else {
                terrainRow = (unsigned char)minScanY;
                while (terrainRow <= (unsigned char)maxScanY && status == 1) {
                    terrainCol = (unsigned char)minScanX;
                    while (terrainCol <= (unsigned char)maxScanX) {
                        if (this->initialTile.x != terrainCol || this->initialTile.y != terrainRow) {
                            tile = &map->map_row_offset[terrainRow][terrainCol];
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
                        ++terrainCol;
                    }
                    ++terrainRow;
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
                foundBlockingOwnGroup = 0;
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
                else status = foundBlockingOwnGroup != 1;
            }

            if (status == 1 && this->minTarget.x <= scanRightRaw && scanLeftRaw <= this->maxTarget.x &&
                this->minTarget.y <= scanBottomRaw && scanTopRaw <= this->maxTarget.y) {
                status = 0;
            }

            unobstructibleObjectHitpoints = FADDR(0x570E5C);
            reached = 0;
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
                                reached = 1;
                            }
                        }
                        ++col;
                        hitCount = found;
                    }
                    ++row;
                }
                if (hitCount == 1) goto next_direction;
            }

            misc = this->miscValue[nextX][nextY];
            newCost += misc * 0x10;
            if (reached == 1) {
                if (unobstructibleObjectHitpoints < 10.0f) newCost += 0x10;
                else newCost += 0x3c;
            }
            facetByte = this->facetValue[curX][curY];
            if ((facetByte & 0xf8) == this->CurrentFacetMask) facetLow = facetByte & 7;
            else facetLow = 0xff;
            if (i != facetLow) ++newCost;
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

final_failure_restore:
    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return restoreResult;

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

    if (this->currentObjectInObMap == 1 && this->currentObject->inside_obj == 0) {
        this->currentObject->addToObstructionMap(this->aiPS);
    }
    return 0;
}
#pragma optimize("y", on)
