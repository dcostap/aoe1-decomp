// VA: 0045FED0 RGE_Moving_Object::canPathWithObstructions (534B)
// PDB-qualified owner/name: RGE_Moving_Object::canPathWithObstructions
// PDB donor: move_obj.cpp:2439-2501
// Binary boundary: [0045FED0,004600E6); the next PDB function begins at
// 004600F0 after the ten-byte gap. The exact preceding anchor is
// RGE_Moving_Object::canBidirectionPath [0045FBC0,0045FECB).
// Attempt log:
// - Replaced the placeholder with the period-typed object/world/zone-map
//   reconstruction.  The body follows the adjacent exact findAvoidancePath
//   donor for lazy zone-map lookup, zone checks, and path-system dispatch.
// - Baseline: exact 534-byte size/frame/call set/CFG; remaining 17 bytes are a
//   localized callee-save coloring gap beginning after get_zone_map.  The
//   oracle carries zone_map in EBP and the first zone result in EBX, while
//   default VC5 source coloring reverses those roles (and later reuses them
//   for range/group arguments).
// - Tried declaration/lifetime order, a zone-map alias, reversed comparison,
//   split target assignment, and <stdlib.h> context; emitted code stayed in
//   the same 17-byte basin.  Narrow byte zone locals lost 10 bytes of size;
//   a shared PathingSystem/goto tail widened the localized drift.  Restored
//   the clean typed reconstruction; no ABI/call/behavior blocker found.
// - Tried a natural direct comparison of the two zone-map results, supported
//   by the decompiler's immediate uchar result evidence; it lost 10 bytes and
//   changed the first result to BL.  Restored the named typed results.
// - Declared the typed zone-map handle before target lookup but assigned it at
//   the existing path point; emitted code stayed in the same 17-byte basin.
// - Matched the exact canBidirectionPath donor's function-scope declarations
//   for target, zone map, zone results, and points; emitted code stayed equal.
// - Tested the Ghidra/PDB reference ABI for unobstructibles; pointer and
//   reference spellings emitted the same bytes. Restored the pointer form.
// - Tested a mixed API-width hypothesis with unsigned-char start_zone and int
//   goal_zone; it added 7 bytes and broke the zone-gate block. Restored int
//   locals; the original 17-byte register-coloring gap remains.
// - A 128-sample ambient file-scope declaration sweep produced one 534-byte
//   group with the same 17-byte gap. Explicit long/int zone-result forms,
//   implicit coordinate conversions, and full function-scope declarations
//   also stayed nonexact; those variants remain discarded.
// - Recovered the controlling source shape from the adjacent exact
//   canBidirectionPath donor: declare result inside each path-system arm,
//   duplicate the cleanup and return in both arms, and let VC5 tail-merge the
//   common epilogue. This swaps zone_map to EBP and the first zone result to
//   EBX without changing behavior or call order. The target now matches all
//   534 bytes.
// - Exact-finish walkback: the prior checkpoint with one function-scope result
//   and one shared cleanup returned to the 17-byte mismatch. Keep the
//   branch-local results and duplicated cleanup because the recorded bytes
//   prove this source shape is required.

struct XYPoint {
    int x;
    int y;
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

template<class T> class ManagedArray;

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

    virtual int canPathWithObstructions(int targetID, float range,
                                        float* costOut, int useAI,
                                        int unobPlayerID, int unobGroupID,
                                        ManagedArray<int>* unobstructibles);
};

class PathingSystem {
public:
    void incrementCanPaths();
    int findTilePath(int startX, int startY, int goalX, int goalY,
                     RGE_Moving_Object* object, float tolerance, int targetID,
                     int mode, float* costOut, int useIterationCap,
                     int checkObstructions, int checkTerrain, int step,
                     int unobPlayerID, int unobGroupID);
    void copyUnobstructibles(ManagedArray<int>& out);
};

extern PathingSystem aiPathSystem;
extern PathingSystem pathSystem;

int RGE_Moving_Object::canPathWithObstructions(
    int targetID, float range, float* costOut, int useAI,
    int unobPlayerID, int unobGroupID, ManagedArray<int>* unobstructibles) {
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

        if (zone_map->withinRange(start, goal, range) == 0) {
            return 0;
        }
    }

    this->storePathInExceptionPath = 1;
    if (useAI != 0) {
        aiPathSystem.incrementCanPaths();
        int result = aiPathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)target->world_x, (int)target->world_y, this,
            range, targetID, 1, costOut, 1, 1, 1, 1,
            unobPlayerID, unobGroupID);
        if (unobGroupID != -1) {
            aiPathSystem.copyUnobstructibles(*unobstructibles);
        }
        this->storePathInExceptionPath = 0;
        return result;
    } else {
        pathSystem.incrementCanPaths();
        int result = pathSystem.findTilePath(
            (int)this->world_x, (int)this->world_y,
            (int)target->world_x, (int)target->world_y, this,
            range, targetID, 1, costOut, 1, 1, 1, 1,
            unobPlayerID, unobGroupID);
        if (unobGroupID != -1) {
            pathSystem.copyUnobstructibles(*unobstructibles);
        }
        this->storePathInExceptionPath = 0;
        return result;
    }
}
