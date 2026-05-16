// 004862B0 RGE_RMM_Object_Generator::place_avoid_objects(...)
// Source: rmm_obj.cpp lines 255-324
// Attempt log:
// - Initial natural source from packet/decompiler.
// - Fixed RGE_RMM_Object_Generator layout after first compile: scratch is +0x20, map_info +0x30, avoid list +0x12C8, avoid_count +0x18F8.
// - Replaced manual byte loop with `memset(this->scratch, 1, width*height)`; VC5 inlines it into the original `mov eax,01010101h` / `rep stosd` / `rep stosb` family.
// - Corrected can_place_on virtual surface to 10 explicit arguments (land, x/y floats, and seven ints) to match the ten pushes before vcall +0x20.
// - Current build compiles but check_function stops: rebuilt .text is 560 bytes vs original 568. Structure is close after memset/layout fixes, but still different register allocation and frame pressure: rebuilt keeps `this` in EBX and object def in ESI with 0x24 local frame, while original keeps `this` in ESI, object def in EDI, and has 0x30 local frame. Remaining differences affect stack local offsets and later loop layout, not safe accepted drift. No inline asm.

extern "C" void* __cdecl memset(void*, int, unsigned int);
class RGE_Map_Object;
class RGE_Map_Land;

struct Map_Stack { int a; int b; int c; int d; };

struct AvoidArea { int x; int y; char gap[8]; };
struct ObjectDef {
    int object_id;      // +0
    int terrain_mask;   // +4
    unsigned char type; // +8
    char gap09[0x14-0x09];
    int count;          // +14
    char gap18[4];
    int land_id;        // +1c
    char gap20[4];
    int radius;         // +24
    char gap28[4];
    int area_remove;    // +2c
};

class RGE_Map_Tile_Object {
public:
    char gap[5];
    unsigned char terrain;
};

class RGE_Map_Row {
public:
    RGE_Map_Tile_Object* tiles;
};

class RGE_Map_Object {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual char can_place_on(RGE_Map_Land* land, float x, float y, int, int, int, int, int, int, int);
    char gap_04[0x30-4];
    float x;
    float y;
    virtual void place(int object_id, float x, float y, int, int);
};

class RGE_Map_Land {
public:
    int id;
    char gap[0x20];
    RGE_Map_Object*** objects_by_type;
};

class RGE_WorldMapInfo { public: char gap[0x40]; RGE_Map_Land** lands; };

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x10];
    RGE_Map_Row** map_rows;
    int width;
    int height;
    char gap_1C[4];
    unsigned char* scratch;
    char gap_24[0x30-0x24];
    RGE_WorldMapInfo* map_info;
    char gap_34[0x12C8-0x34];
    AvoidArea avoid[99];
    int avoid_count;

    void set_search_area(int x, int y, int radius, int flag);
    void init_stack(Map_Stack* s);
    void deinit_stack(Map_Stack* s);
    void make_placement_stack(Map_Stack* s, int, int, int, int);
    int pop_stack(Map_Stack* s, int* x, int* tile_x, int* y);
    void remove_area_from_lists(int x, int y, int radius);
    void place_group(ObjectDef* def, int x, int y, RGE_Map_Land* land);
    void place_cluster(ObjectDef* def, int x, int y, RGE_Map_Land* land);
    void place_avoid_objects(ObjectDef* def, int unused);
};

void RGE_RMM_Object_Generator::place_avoid_objects(ObjectDef* def, int unused)
{
    Map_Stack stack;
    int x;
    int tile_x;
    int y;
    int count;
    float fx;
    float fy;
    int tmp;
    RGE_Map_Land* land;
    RGE_Map_Object* obj;
    int i;

    memset(this->scratch, 1, this->width * this->height);

    for (i = 0; i < this->avoid_count; i++) {
        this->set_search_area(this->avoid[i].x, this->avoid[i].y, def->radius, 0);
    }

    this->init_stack(&stack);
    this->make_placement_stack(&stack, -1, -1, -1, -1);

    if (def->land_id <= -1) tmp = 0; else tmp = def->land_id;
    land = this->map_info->lands[tmp];
    count = def->count;

    if (this->pop_stack(&stack, &x, &tile_x, &y) && count > 0) {
        do {
            if (def->terrain_mask >= 0) {
                unsigned char terr = this->map_rows[x]->tiles[tile_x].terrain & 0x1F;
                if ((int)terr != def->terrain_mask) goto next;
            }

            fx = (float)tile_x;
            obj = land->objects_by_type[def->object_id][0];
            fy = (float)x;
            tmp = (int)obj->x;
            if (obj->x - (float)tmp >= 0.5f) fx -= 0.5f;
            tmp = (int)obj->y;
            if (obj->y - (float)tmp >= 0.5f) fy -= 0.5f;

            if (!obj->can_place_on(land, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                this->remove_area_from_lists(x, tile_x, def->area_remove);
                switch (def->type) {
                case 0:
                    land->objects_by_type[def->object_id][0]->place(def->object_id, fx, fy, 0, 1);
                    break;
                case 1:
                    this->place_group(def, x, tile_x, land);
                    break;
                case 2:
                    this->place_cluster(def, x, tile_x, land);
                    break;
                }
                count--;
            }
next:
            ;
        } while (this->pop_stack(&stack, &x, &tile_x, &y));
    }
    this->deinit_stack(&stack);
}
