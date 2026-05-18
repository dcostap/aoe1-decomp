// VA: 00486700 RGE_RMM_Object_Generator::place_land_objects
// Attempt log:
// try 1: natural reconstruction from packet plus sibling place_objects/place_avoid_objects; compiled too small (784B vs 855B).
// try 2: corrected land index logic: def->land_id when positive, otherwise fallback from +12D4+land_param*0x10; no size/codegen improvement.
// try 3: added temporary diagnostic-only padding branch to reach byte compare, then removed it. Padded diagnostic showed broad mismatch (65.8480% positional / 71.5789% edit), first mismatch at frame size 0x38 vs 0x3c due padding and many later semantic/layout differences.
// Observed original has extra mid-function terrain/land helper calls (005473B0 and 00546EB0) before stack iteration, exact stack local topology, and a compact pop_stack loop not captured by the natural reconstruction.
// GIVEUP: remaining blockers are broad: exact parameter roles, land/object lookup surfaces, unknown helper calls around 005473B0/00546EB0, pop_stack arg/local topology, terrain/inside-radius predicate shape, and object placement/group/cluster branch layout. No inline asm used; not accepted_drift quality.

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct Map_Stack { char data[0x18]; };
struct Tile { char gap[5]; unsigned char terrain; char rest[18]; };
struct Row { Tile* tiles; };

struct ObjectDef {
    int object_id;      // +00
    int terrain;        // +04
    unsigned char type; // +08
    char gap09[0x14-0x09];
    int count;          // +14
    char gap18[4];
    int land_id;        // +1c
    char gap20[4];
    int radius;         // +24
    char gap28[4];
    int area_remove;    // +2c
};

class RGE_Map_Land;
class RGE_Map_Object {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual unsigned char can_place_on(RGE_Map_Land*, float, float, int, int, int, int, int, int, int);
    char gap04[0x30-4];
    float radius_x;
    float radius_y;
    char gap38[0x94-0x38];
    virtual void place(int object_id, float x, float y, int, int);
};

class RGE_Map_Land { public: int id; char gap04[0x20]; RGE_Map_Object*** objects_by_type; };
class WorldInfo { public: char gap00[0x40]; RGE_Map_Land** lands; char gap44[0x10]; RGE_Map_Object*** objects_by_type; };
struct AvoidArea { int x; int y; char gap[8]; };

class RGE_RMM_Object_Generator {
public:
    char gap00[0x10];
    Row** rows;       // +10
    int width;        // +14
    int height;       // +18
    char gap1c[4];
    unsigned char* scratch; // +20
    char gap24[0x30-0x24];
    WorldInfo* info;  // +30
    char gap34[0x12C8-0x34];
    AvoidArea avoid[99];
    int avoid_count;  // +18f8

    void set_search_area(int x, int y, int radius, int flag);
    void init_stack(Map_Stack* s);
    void deinit_stack(Map_Stack* s);
    void make_placement_stack(Map_Stack* s, int x, int y, int unk, int land);
    int pop_stack(Map_Stack* s, int* x, int* tile_x, int* y);
    void remove_area_from_lists(int x, int y, int radius);
    void place_group(ObjectDef* def, int x, int y, RGE_Map_Land* land);
    void place_cluster(ObjectDef* def, int x, int y, RGE_Map_Land* land);
    void place_land_objects(ObjectDef* def, int x, int y, int radius, int land, int unused);
};

void RGE_RMM_Object_Generator::place_land_objects(ObjectDef* def, int x, int y, int radius, int land_id, int unused)
{
    int min_x = x - radius;
    int min_y = y - radius;
    int max_x = x + radius;
    int max_y = y + radius;
    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->width) max_x = this->width - 1;
    if (max_y >= this->height) max_y = this->height - 1;

    memset(this->scratch, 1, this->width * this->height);
    for (int i = 0; i < this->avoid_count; ++i) {
        this->set_search_area(this->avoid[i].x, this->avoid[i].y, radius, 0);
    }

    Map_Stack stack;
    this->init_stack(&stack);
    this->make_placement_stack(&stack, x, y, radius, land_id);

    ObjectDef* cur = def;
    int land_index = cur->land_id;
    if (land_index <= -1) {
        int fallback = *(int*)((char*)this + 0x12D4 + land_id * 0x10);
        if (fallback > 0) land_index = fallback;
        else land_index = 0;
    }

    RGE_Map_Land* land = this->info->lands[land_index];
    RGE_Map_Object* obj = land->objects_by_type[cur->object_id][0];
    if (obj == 0) { this->deinit_stack(&stack); return; }

    int sx, tile_x, sy;
    float fx, fy;
    int tmp;
    RGE_Map_Object* mo;
    int* terrain_obj = 0;
    unsigned char first_ok = obj->can_place_on(land, (float)x, (float)y, 0, 0, 1, 1, 1, 0, 1);
    int remaining = cur->count;
    if (this->pop_stack(&stack, &sx, &tile_x, &sy) && remaining > 0) {
        do {
            if (cur->terrain >= 0) {
                int terr = this->rows[sy]->tiles[tile_x].terrain & 0x1f;
                if (terr != cur->terrain) goto next;
            }
            if (tile_x > min_x && tile_x < max_x && sy > min_y && sy < max_y) goto next;

            fx = (float)tile_x;
            fy = (float)sy;
            mo = land->objects_by_type[cur->object_id][0];
            tmp = (short)(int)mo->radius_x;
            if (0.0f < mo->radius_x - (float)tmp) fx -= -0.5f;
            tmp = (short)(int)mo->radius_y;
            if (0.0f < mo->radius_y - (float)tmp) fy -= -0.5f;

            if (!mo->can_place_on(land, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                this->remove_area_from_lists(tile_x, sy, cur->area_remove);
                switch (cur->type) {
                case 0:
                    land->objects_by_type[cur->object_id][0]->place(cur->object_id, fx, fy, 0, 1);
                    break;
                case 1:
                    this->place_group(cur, tile_x, sy, land);
                    break;
                case 2:
                    this->place_cluster(cur, tile_x, sy, land);
                    break;
                }
                --remaining;
            } else if (cur->type == 0 && unused == 0) {
                land->objects_by_type[cur->object_id][0]->place(cur->object_id, fx, fy, 0, 1);
            }
next:
            ;
        } while (this->pop_stack(&stack, &sx, &tile_x, &sy));
    }
    this->deinit_stack(&stack);
}
