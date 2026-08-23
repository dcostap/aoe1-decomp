// VA: 0045F820 canPath (419B)
// move_obj.cpp:2208-2256
// Attempt log:
// - Reconstructed the period-typed XYZPoint canPath surface, owner/world/map
//   bounds, cached zone-map lookup, zone comparison, and path-system calls.
// - Baseline had the complete call set but used short failure branches and was
//   17 bytes too large. Reformed the success gates to restore the original CFG.
// - Split the negative coordinate checks before the map bounds check. VC5 then
//   reused the incoming XYZPoint home and emitted all 419 bytes exactly.
// - Exact with default flags. No inline asm or custom flags.
// - PDB-qualified owner is public virtual RGE_Moving_Object::canPath in
//   move_obj.cpp:2208-2256. The body ends at ret 24h, 0045F9C2; padding starts
//   at 0045F9C3. The virtual qualifier keeps the rebuilt owner symbol exact.

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
    char gap_04[4];
    int map_width;
    int map_height;
    char gap_10[0x8DB4];
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

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x38];
    int zoneMapIndex;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual int canPath(XYZPoint point, float tolerance, int targetID,
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

int RGE_Moving_Object::canPath(XYZPoint point, float tolerance, int targetID,
                               float* costOut, int useAI, int unobPlayerID,
                               int unobGroupID) {
    if (point.x < 0 || point.y < 0) {
        return 0;
    }

    RGE_Map* map = this->owner->world->map;
    if (point.x < map->map_width && point.y < map->map_height) {
            if (this->zoneMapIndex == -1) {
                this->owner->world->map->map_zones->get_zone_map(
                    this->owner->world->terrains[this->master_obj->terrain],
                    this->owner->world->terrain_size, this->zoneMapIndex);
            }

            RGE_Zone_Map* zone_map =
                this->owner->world->map->map_zones->get_zone_map(
                    this->zoneMapIndex);
            if (zone_map != 0) {
                int start_zone = zone_map->get_zone_info(
                    (long)this->world_x, (long)this->world_y);
                int goal_zone = zone_map->get_zone_info(point.x, point.y);
                if (goal_zone != start_zone) {
                    XYPoint start;
                    start.x = (int)this->world_x;
                    start.y = (int)this->world_y;

                    XYPoint goal;
                    goal.x = point.x;
                    goal.y = point.y;

                    if (zone_map->withinRange(start, goal, tolerance) == 0) {
                        return 0;
                    }
                }

                if (useAI != 0) {
                    aiPathSystem.incrementCanPaths();
                    return aiPathSystem.findTilePath(
                        (int)this->world_x, (int)this->world_y, point.x,
                        point.y, this, tolerance, targetID, 0, costOut, 1,
                        1, 1, 1, unobPlayerID, unobGroupID);
                }

                pathSystem.incrementCanPaths();
                return pathSystem.findTilePath(
                    (int)this->world_x, (int)this->world_y, point.x, point.y,
                    this, tolerance, targetID, 0, costOut, 1, 1, 1, 1,
                    unobPlayerID, unobGroupID);
            }
        }

    return 0;
}
