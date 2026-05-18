// VA: 004C6740 RGE_Static_Object::make_object_bounds_list
// stat_obj.cpp
// FLAGS: /GX
// Attempt log:
// try 1: broad reconstruction from packet/decompiler: early object validity checks, tile bounds clamp, map tile object-list scan, separating-axis-ish overlap tests, add_node calls, empty-list delete.
// try 2: added /GX because original has VC5 EH registration around `new RGE_Check_List`; without /GX rebuilt .text was only 784B.
// try 3: modeled RGE_Check_List ctor/dtor/add_node from matched nearby functions 004C66C0/004C66D0/004C6700.
// try 4: modeled RGE_Static_Object layout info +8, map +0xC, x/y/z +0x38/+0x3C/+0x40; ObjectInfo hp/damage/radius +0x30/+0x34/+0x38.
// try 5: modeled map dimensions +8/+0xC, row table +0x8D8C, tile object-list at tile+0x10, tile stride 0x18.
// try 6: used natural `new RGE_Check_List` then empty-list dtor/delete to recover EH/new/delete surface.
// try 7: first /GX version compiled to equal 859B but broad mismatch: 81.37% positional, 70.55% edit, first mismatch at frame size (0x38 vs original 0x40) and early-return FPU/control layout.
// try 8: changed early validation returns to a shared `return_null` tail to mimic original single null-return block; this reduced .text to 848B vs original 859B and still did not diff.
// try 9: top-declared locals to allow shared-fail goto across initializations; compiles but size remains 848B.
// try 10: probed no-/GX; function shrinks to 784B, confirming /GX is required but not sufficient.
// Current blocker: behavior surface/call set are broad but source still misses exact VC5 FPU stack/control layout and loop register family; original keeps a 0x40 EH frame, delayed shared null tail, and very specific nested row/tile/node scan scheduling.
// No accepted_drift: broad frame/FPU/control-flow mismatch from the start.

class RGE_Static_Object;

struct RGE_Check_Node {
    RGE_Static_Object* node;
    float dx;
    float dy;
    unsigned char flag;
    char gap[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object* object, float dx, float dy, unsigned char flag);
};


struct ObjectInfo {
    char gap_00[0x30];
    float hp;        // +30
    float damage;    // +34
    float radius;    // +38
};

struct TileObjNode { RGE_Static_Object* obj; TileObjNode* next; };
struct Tile { char gap_00[0x10]; TileObjNode* objects; };

class RGE_Map {
public:
    char gap_00[8];
    int width;
    int height;
    char gap_10[0x3C-0x10];
    void* world;
    char gap_40[0x8D8C-0x40];
    unsigned char** rows;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    ObjectInfo* info;
    RGE_Map* map;
    char gap_10[0x28];
    float x;
    float y;
    float z;

    RGE_Check_List* make_object_bounds_list(float max_dist);
};

RGE_Check_List* RGE_Static_Object::make_object_bounds_list(float max_dist) {
    ObjectInfo* info = this->info;
    float hp;
    float dmg;
    short minx;
    short miny;
    short maxx;
    short maxy;
    RGE_Map* map;
    void* world;
    RGE_Check_List* list;

    hp = info->hp;
    dmg = info->damage;
    if (!(hp > 0.0f)) goto return_null;
    if (!(dmg > 0.0f)) goto return_null;
    if (!((double)info->radius > 0.0)) goto return_null;

    minx = (short)(this->x - 0.5f);
    miny = (short)(this->y - 0.5f);
    maxx = (short)(this->x - 1.5f);
    maxy = (short)(this->y - 1.5f);

    map = this->map;
    world = *(void**)((char*)map->world + 0x28);
    list = new RGE_Check_List;

    if (minx < 0) minx = 0;
    if (maxx >= map->width) maxx = (short)(map->width - 1);
    if (miny < 0) miny = 0;
    if (maxy >= map->height) maxy = (short)(map->height - 1);

    if (miny <= maxy) {
        int y0 = miny;
        int row_count = (int)maxy - (int)miny + 1;
        int row_offset = y0 * 24;
        int col_offset = (int)minx * 4;
        int col_count = (int)maxx - (int)minx + 1;
        do {
            unsigned char* row = map->rows[(int)minx];
            Tile* tile = (Tile*)(row + row_offset);
            short curx = minx;
            int count = col_count;
            if (minx <= maxx) {
                do {
                    TileObjNode* node = tile->objects;
                    while (node != 0) {
                        RGE_Static_Object* other = node->obj;
                        if (other != this) {
                            ObjectInfo* oi = other->info;
                            float od = oi->damage;
                            float oh = oi->hp;
                            if (od > 0.0f && oh > 0.0f) {
                                float dz = other->z - this->z;
                                if (dz >= -info->radius && dz < this->info->radius) {
                                    float dx = other->x - this->x;
                                    float oy = other->y;
                                    float dy = oy - this->y;
                                    unsigned char flag;
                                    if (dx < 0.0f) {
                                        dx = -dx;
                                        flag = 1;
                                    } else {
                                        flag = 0;
                                    }
                                    if (dy < 0.0f) {
                                        flag = (unsigned char)(flag + 2);
                                        dy = -dy;
                                    }
                                    float sep1 = dx - dy;
                                    float sep2 = dx + dy;
                                    if (sep2 < max_dist && sep1 < max_dist) {
                                        if (!(sep1 < 0.0f) || !(sep2 < 0.0f)) {
                                            list->add_node(other, dx, dy, flag);
                                        }
                                    }
                                }
                            }
                        }
                        node = node->next;
                    }
                    tile = (Tile*)((char*)tile + 0x18);
                    count--;
                } while (count != 0);
            }
            col_offset += 4;
            row_count--;
        } while (row_count != 0);
    }

    if (list->list == 0) {
        if (list != 0) {
            list->~RGE_Check_List();
            operator delete(list);
        }
        list = 0;
    }
    return list;
return_null:
    return 0;
}
