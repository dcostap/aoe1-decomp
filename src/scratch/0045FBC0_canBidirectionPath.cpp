// VA: 0045FBC0 RGE_Moving_Object::canBidirectionPath
// Attempt log:
// v1 natural implementation from packet/decompiler; broad first-pass source model: /O2 undersized 496B vs original 779B.
// v2 /GX: no change/benefit, still 496B; rolled back flag, no EH in original.
// v3 /Od: 676B but EBP-frame/debug family and still undersized; rolled back flag.
// v4 inspected packet line map: original has explicit zone-map lazy initialization, two get_zone_info calls, withinRange gate, two findTilePath phases, and duplicated aiPathSystem/pathSystem halves.
// v5 current source leaves behavior-shaped model but uses placeholder zone-map side-effect and shared PathingSystem pointer; not accepted-drift-safe.
// scratch give-up: needs real RGE_Moving_Object/terrain zone-map layout and source shape for duplicated pathSystem vs aiPathSystem blocks; current object is only a broad behavioral scaffold.

extern "C" long __cdecl _ftol();

struct Waypoint { float x; float y; };
struct Path { Waypoint* lastWaypoint(); };
class RGE_Static_Object { public: char gap_00[0x38]; float x; float y; float z; };
class RGE_Game_World { public: RGE_Static_Object* object(int); };
class RGE_Zone_Map { public: unsigned char get_zone_info(long,long); int withinRange(int sx,int sy,int gx,int gy,float range); };
class RGE_Zone_Map_List { public: RGE_Zone_Map* get_zone_map(int); RGE_Zone_Map* get_zone_map(void*, int, int*); };
class PathingSystem { public: void incrementCanPaths(); int findTilePath(int,int,int,int,void*,float,int,int,float*,int,int,int,int,int,int); };

#define aiPathSystem (*(PathingSystem*)0x62F348)
#define pathSystem (*(PathingSystem*)0x74D440)

struct ObjInfo { char gap_00[0x28]; void* map; char gap_2c[0x10]; RGE_Game_World* world; char gap_40[0x12]; short zone_count; char gap_54[2]; void** zones; };
struct OwnerInfo { char gap_00[0x66]; short zone_index; };
struct WorldHolder { char gap_00[0x28]; char* ptr28; char gap_2c[0x10]; ObjInfo* info; };

class RGE_Moving_Object {
public:
    char gap_00[8];
    OwnerInfo* owner;
    WorldHolder* holder;
    char gap_10[0x28];
    float x;
    float y;
    char gap_40[0x3c];
    int zone_map_id;
    char gap_80[0x58];
    Path exceptionPathValue;
    char gap_DC[0x78];
    unsigned char storePathInExceptionPath;

    int canBidirectionPath(int param_1,int param_2,float param_3,float* param_4,int param_5,int param_6,int param_7);
};

static int ftol_f(float f) { return (int)f; }

int RGE_Moving_Object::canBidirectionPath(int param_1,int param_2,float param_3,float* param_4,int param_5,int param_6,int param_7)
{
    RGE_Static_Object* obj1 = this->holder->info->world->object(param_1);
    RGE_Static_Object* obj2 = this->holder->info->world->object(param_2);
    if (obj1 == 0 || obj2 == 0) return 0;

    if (this->zone_map_id == -1) {
        this->zone_map_id = (int)this->holder->info->map; // placeholder for get_zone_map side effect
    }
    RGE_Zone_Map_List* zlist = *(RGE_Zone_Map_List**)(this->holder->ptr28 + 0x8dc4);
    RGE_Zone_Map* zoneMap = zlist->get_zone_map(this->zone_map_id);
    if (zoneMap == 0) return 0;

    int sY = (int)this->y;
    int sX = (int)this->x;
    unsigned char zs = zoneMap->get_zone_info(sX, sY);
    int gY = (int)obj1->y;
    int gX = (int)obj1->x;
    unsigned char zg = zoneMap->get_zone_info(gX, gY);
    if (zg != zs) {
        int sx = (int)this->x;
        int sy = (int)this->y;
        int gx = (int)obj1->x;
        int gy = (int)obj1->y;
        if (zoneMap->withinRange(sx, sy, gx, gy, param_3) == 0) return 0;
    }

    this->storePathInExceptionPath = 1;
    PathingSystem* ps;
    if (param_5 != 0) ps = &aiPathSystem; else ps = &pathSystem;
    ps->incrementCanPaths();
    int ok = ps->findTilePath((int)this->x, (int)this->y, (int)obj1->x, (int)obj1->y,
                              this, param_3, param_1, 1, param_4, 1, 1, 1, 1, param_6, param_7);
    if (ok == 0) {
        this->storePathInExceptionPath = 0;
        return 0;
    }
    Waypoint* wp = this->exceptionPathValue.lastWaypoint();
    int lx = (int)wp->x;
    wp = this->exceptionPathValue.lastWaypoint();
    int ly = (int)wp->y;
    ok = ps->findTilePath(lx, ly, (int)obj2->x, (int)obj2->y,
                          this, param_3, param_2, 0, param_4, 1, 1, 1, 1, param_6, param_7);
    this->storePathInExceptionPath = 0;
    return ok;
}
