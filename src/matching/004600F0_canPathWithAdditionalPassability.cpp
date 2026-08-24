// VA: 004600F0 RGE_Moving_Object::canPathWithAdditionalPassability
// PDB donor: move_obj.cpp:2509-2545
// Attempt log:
// - Replaced the placeholder with the period-plausible pathing implementation.
//   The point bounds are checked through owner->world->map; exception fields are
//   set before selecting pathSystem versus aiPathSystem, and both branches call
//   the real path finder with the four object-coordinate conversions.
// - Baseline had the correct 276-byte structure but scheduled the two exception
//   stores in the opposite order (5 differing bytes).
// - Swapping the source exception-field assignments reduced the drift to the
//   branch opcode; placing the aiPathSystem arm first made the zero-useAI path
//   the late branch target and produced an exact match.
// - Main-agent audit restored canonical map/world/player destructor ownership;
//   emitted code remains exact.

#ifndef MOVE_OBJ_CANONICAL_TU
struct XYZPoint {
    int x;
    int y;
    int z;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;
    int map_height;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[8];
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    char gap_40[0x48];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char gap_8C[0xC0];
    int currentTerrainException1;
    int currentTerrainException2;
    unsigned char storePathInExceptionPath;

    int canPathWithAdditionalPassability(XYZPoint point, float tolerance,
                                         int targetID, float* costOut,
                                         int terrainException1,
                                         int terrainException2, int useAI,
                                         int unobPlayerID, int unobGroupID);
};

class PathingSystem {
public:
    void incrementCanPaths();
    int findTilePath(int startX, int startY, int goalX, int goalY,
                     RGE_Moving_Object* object, float tolerance, int targetID,
                     int mode, float* costOut, int useIterationCap,
                     int checkObstructions, int checkTerrain, int step,
                     int unobPlayerID, int unobGroupID);
};

extern PathingSystem aiPathSystem;
extern PathingSystem pathSystem;
#endif

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
