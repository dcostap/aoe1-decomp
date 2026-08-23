// VA: 0045FBC0 RGE_Moving_Object::canBidirectionPath
// PDB owner: move_obj.cpp:2319-2432; binary span: 0045FBC0-0045FECB.
// PDB sibling order: exact RGE_Moving_Object::canPath at 0045F9D0, then this
// function, then canPathWithObstructions at 0045FED0.
// Attempt log:
// - Prior scaffold used placeholder ownership and one shared path-system pointer.
// - Fresh reconstruction follows exact canPath donors: named owner/world/map and
//   terrain-backed lazy zone-map lookup, typed zone points, and two explicit
//   AI/normal path phases for the source and goal objects.
// - Keeping each first-phase result and assigning it to the flag on failure
//   reproduces the original failure tail and the complete 779-byte function.
// - The public virtual declaration preserves the PDB ABI and emits the original
//   UAE decorated symbol without changing the exact body.
// - ABI walkback: the nonvirtual spelling also matched body bytes but emitted
//   QAE; it is not retained because the PDB symbol is virtual (UAE).

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

class RGE_Zone_Map;
class RGE_Map;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Moving_Object;

class Path {
public:
    char gap_00[0x24];
    Waypoint* pathValue;
    char gap_28[4];
    int currentSizeValue;
    char gap_30[4];

    const Waypoint* lastWaypoint() const;
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
    RGE_Zone_Map* get_zone_map(long zone_map_index);
};

class RGE_Zone_Map {
public:
    unsigned char get_zone_info(long x, long y);
    int withinRange(XYPoint point, XYPoint from, float range);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x8DC0];
    RGE_Zone_Map_List* map_zones;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x24];
    short terrain_num;
    short terrain_size;
    float** terrains;

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x62];
    short terrain;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x38];
    int zoneMapIndex;
    char gap_80[8];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char gap_8C[0x4C];
    Path exceptionPathValue;
    char gap_10C[0x48];
    unsigned char storePathInExceptionPath;

    virtual int canBidirectionPath(int sourceID, int goalID, float tolerance,
                                   float* costOut, int useAI, int unobPlayerID,
                                   int unobGroupID);
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
