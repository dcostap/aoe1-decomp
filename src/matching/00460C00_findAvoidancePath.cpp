// VA: 00460C00 findAvoidancePath (292B)
// move_obj.cpp:2949-3035
// Attempt log:
// - Reconstructed the lazy zone-map lookup, zone gate, and exception-path
//   pathing call from the packet using named period-era object/map types.
// - Corrected map_zones to the proven RGE_Map +0x8DC4 field and preserved the
//   base tail padding needed for the derived +0x88 layout.
// - Kept zone-info results as int locals; VC5 then emits the observed byte
//   masks/full-register comparison. The final source matches all 292 bytes.
// - Main-agent audit restored canonical map/world/player/master destructor
//   ownership; emitted code remains exact.

struct XYPoint {
    int x;
    int y;
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

class RGE_Zone_Map;
class RGE_Map;

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

class Path {
public:
    char gap_00[0x7C];
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
    char gap_40[0x3C];
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
    unsigned char storePathInExceptionPath;

    virtual Path* findAvoidancePath(XYZPoint& point, float range, int targetID);
};

class PathingSystem {
public:
    int findTilePath(int startX, int startY, int goalX, int goalY,
                     RGE_Moving_Object* object, float tolerance, int targetID,
                     int mode, float* costOut, int useIterationCap,
                     int checkObstructions, int checkTerrain, int step,
                     int unobPlayerID, int unobGroupID);
    void initMisc(unsigned char value);
};

extern PathingSystem aiPathSystem;

Path* RGE_Moving_Object::findAvoidancePath(XYZPoint& point, float range,
                                           int targetID) {
    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(
            this->owner->world->terrains[this->master_obj->terrain],
            this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);

    int start_zone = zone_map->get_zone_info(
        (long)this->world_x, (long)this->world_y);
    int goal_zone =
        zone_map->get_zone_info(point.x, point.y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = point.x;
        goal.y = point.y;

        if (zone_map->withinRange(start, goal, range) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    aiPathSystem.findTilePath(
        (int)this->world_x, (int)this->world_y, point.x, point.y, this,
        range, targetID, 1, 0, 0, 1, 1, 1, -1, -1);
    this->storePathInExceptionPath = 0;
    aiPathSystem.initMisc(0);
    return &this->exceptionPathValue;
}
