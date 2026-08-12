// VA: 0045F9D0 RGE_Moving_Object::canPath (487B)
// PDB donor: move_obj.cpp:2263-2312
// Attempt log:
// - Replaced the placeholder with the period-plausible typed pathing
//   reconstruction.  The target lookup, lazy zone-map ownership, zone gate,
//   and duplicated AI/normal path-system calls follow the binary evidence.
// - Baseline matched structure and all calls but passed mode 1 to findTilePath.
//   Changed both calls to the binary-proven mode 0; the function now matches.
// Source audit: named world, map, zone-map, object, and path-system ownership;
// no inline assembly or codegen-only scaffolding.

struct XYPoint {
    int x;
    int y;
};

class RGE_Zone_Map;
class RGE_Map;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Moving_Object;

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
    char gap_8C[0xC0];

    int canPath(int targetID, float tolerance, float* costOut, int useAI,
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

int RGE_Moving_Object::canPath(int targetID, float tolerance, float* costOut,
                               int useAI, int unobPlayerID, int unobGroupID) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        this->owner->world->map->map_zones->get_zone_map(
            this->owner->world->terrains[this->master_obj->terrain],
            this->owner->world->terrain_size, this->zoneMapIndex);
    }

    RGE_Zone_Map* zone_map =
        this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    if (zone_map == 0) {
        return 0;
    }

    int start_zone = zone_map->get_zone_info(
        (long)this->world_x, (long)this->world_y);
    int goal_zone = zone_map->get_zone_info(
        (long)target->world_x, (long)target->world_y);

    if (goal_zone != start_zone) {
        XYPoint start;
        XYPoint goal;

        start.x = (int)this->world_x;
        start.y = (int)this->world_y;
        goal.x = (int)target->world_x;
        goal.y = (int)target->world_y;

        if (zone_map->withinRange(start, goal, tolerance) == 0) {
            return 0;
        }
    }

    if (useAI != 0) {
        aiPathSystem.incrementCanPaths();
        return aiPathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)target->world_x, (int)target->world_y, this,
            tolerance, targetID, 0, costOut, 1, 1, 1, 1,
            unobPlayerID, unobGroupID);
    }

    pathSystem.incrementCanPaths();
    return pathSystem.findTilePath(
        (int)this->world_x, (int)this->world_y,
        (int)target->world_x, (int)target->world_y, this,
        tolerance, targetID, 0, costOut, 1, 1, 1, 1,
        unobPlayerID, unobGroupID);
}
