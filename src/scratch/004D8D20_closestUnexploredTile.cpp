// 004D8D20 TribeInformationAIModule::closestUnexploredTile
// taiinfmd.cpp
// Attempt log:
// try 1: broad reconstruction from packet: spiral search around object tile, visibility/explored checks, then fallback region selection.
// try 2: modeled owner/world/object-table chain from this+0x100 -> +0xF0 -> object table +0x38/+0x3C and early null-object return.
// try 3: modeled building flag from object type word +0x14 == 4 and initial object terrain/tile state calls.
// try 4: modeled random initial direction using debug_rand(0x5878DC,0x397), signed abs, and modulo-4 direction.
// try 5: modeled float-to-int conversion of input x/y and a four-direction expanding spiral with left/right/top/bottom boundary flags.
// try 6: modeled boundary checks against module width/height +0x104/+0x108.
// try 7: modeled explored/tile filters: terrain byte == 0x0F skip; allowHidden toggles 0xFF/2 acceptance; can_place and tile_ok checks before accepting.
// try 8: modeled accept path writing output tile coordinates and return 0; exhausted path calls postTile(objectId,1) and returns 0.
// try 9: initial source left ring uninitialized; fixed to ring=0, no size change.
// try 10: /GX probe made no code/size change (560B); removed flag.
// try 11: reviewed original: after spiral search there is a second large fallback that scans precomputed region records at +0x408, randomizes candidates, computes scaled coordinates, and writes output. Current source omits most of that and is 560B vs original 977B.
// left in scratch: first-pass spiral behavior is broad, but fallback region-selection half and exact call/struct surfaces are missing. No accepted_drift: rebuilt is size-short/no comparable localized diff.

extern "C" int debug_rand(const char*, int);
extern "C" int __cdecl _ftol(float);

struct Point3 { int x,y,z; };
class ObjType { public: char gap0[0x14]; short type; };
class Obj { public: void** vt; char gap4[4]; ObjType* type; char gapC[0x1C]; float x; char gap2C[0x14]; float z; int can_place(Point3,int,int,int,int,int,int); int tile_ok(int,int); int terrain_at(int,int); };
class ObjTable { public: Obj* object(int); };
class MapMask { public: unsigned char get(int,int); void set(int,int,int); };
class TileMap { public: unsigned char get(int,int); };
class World { public: char gap0[0x38]; ObjTable* objects; char gap3C[0xFC]; int width; int height; char gap140[0x18]; MapMask mask; char gap408[1]; };
class Owner { public: char gap0[0x100]; World* world; };

class TribeInformationAIModule {
public:
    char gap0[0x100]; Owner* owner; int width; int height; char gap10C[0x158-0x10C]; TileMap explored;
    int closestUnexploredTile(int objectId, float x, float y, int allowHidden, int* out);
    int postTile(int objectId, int flag);
};

int TribeInformationAIModule::closestUnexploredTile(int objectId, float fx, float fy, int allowHidden, int* out) {
    World* world;
    Obj* obj;
    int isBuilding;
    unsigned char baseTerrain;
    int dir;
    int ix, iy;
    int left,right,top,bottom;
    int ring, pass, step;

    world = owner->world;
    obj = world->objects->object(objectId);
    if (!obj) return 0;
    isBuilding = (obj->type->type == 4);
    baseTerrain = obj->terrain_at(0,0);
    dir = debug_rand((const char*)0x5878DC, 0x397);
    dir = (dir < 0 ? -dir : dir) & 3;
    ix = _ftol(fx);
    iy = _ftol(fy);
    left = right = top = bottom = 0;
    ring = 0;

    while (!(left && right && top && bottom)) {
        ++ring;
        for (pass=0; pass<2; ++pass) {
            for (step=0; step<ring; ++step) {
                dir = (dir + 1) & 3;
                switch (dir) { case 0: ++iy; break; case 1: ++ix; break; case 2: --iy; break; case 3: --ix; break; }
                if (ix < 0) { left=1; continue; }
                if (ix >= width) { right=1; continue; }
                if (iy < 0) { top=1; continue; }
                if (iy >= height) { bottom=1; continue; }
                unsigned char e = explored.get(ix,iy);
                unsigned char t = world->mask.get(ix,iy);
                if (t == 0x0f) continue;
                if (allowHidden == 1) { if (e != 0xff) continue; }
                else { if (e == 0xff || e == 2) continue; }
                if (obj->can_place(*(Point3*)&ix, 1, -1, -1, -1, -1, -1)) {
                    if (obj->tile_ok(ix,iy) == baseTerrain) {
                        obj->vt[0];
                        out[0]=ix; out[1]=iy;
                        return 0;
                    }
                }
            }
        }
    }

    postTile(objectId,1);
    return 0;
}
