// VA: 004C5610 RGE_Static_Object::check_object_bounds
// Attempt log:
// 1: natural typed reconstruction from packet/decompiler: correct size but 68.7% diff; early float compare used reversed constant-load form and coord names swapped.
// 2: changed float compare spelling to `rx > 0.0f` and fixed x/y clamp names; first mismatch moved to stack-slot offsets, diff improved to 55.9%.
// 3: reordered local declarations to mirror Ghidra stack names; no codegen change.
// 4: inverted top-level radius test with `!(<= && <=)`; no codegen change.
// 5: added dummy local assignment to try stack slot shift; optimized away/no codegen change.
// 6: tried /GX; unchanged.
// 7: tried /O2 without /Oy; unchanged.
// 8: fixed overlap predicate to `dy <= ry+ry2` per decompiler/original branch sense; behavior fix, only tiny edit-diff improvement.
// 9: current best same-size 524 B, first mismatch at initial radius stack slots: original stores rx/ry at [esp+24]/[esp+1C], rebuilt at [esp+28]/[esp+20]. Later FPU/control-flow broadly close but shifted stack-slot topology cascades.
// 10: left in scratch: behavior/call surface understood, but remaining 55.9% positional diff is too broad for accepted_drift.
// 11: typed row/tile traversal with a short outer-row index recovered exact
// map setup, 0x2C frame, and 71.6% exact-block coverage; remaining drift is
// the x2/y2 spill-home swap and late return-compare block shape.
// 12: equivalent x-overlap operand reversal was a codegen duplicate; restored
// the direct `dx <= rx + rx2` spelling for source clarity.
// 13: adopted the same-TU make_object_bounds_list donor's named radius,
// bound-local order, and positive overlap arithmetic; codegen was unchanged,
// so the donor-backed natural source is retained.
// 14: reversed the typed x-overlap predicate to test the original fcompp
// branch shape; emitted code was unchanged, so the clean predicate is kept.
// 15: declared the natural outer y_index temp before y2 to test the first
// spill-home topology; emitted code was unchanged, so the clean order is kept.

typedef unsigned char uchar;

class RGE_Static_Object;

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

struct RGE_Tile {
    char gap_00[0x10];
    RGE_Object_Node* objects;
    char gap_14[4];
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World { public: char gap_00[0x28]; RGE_Map* map; };
class RGE_Player { public: char gap_00[0x3C]; RGE_Game_World* world; };

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x38 - 0x10];
    float world_x;
    float world_y;

    RGE_Static_Object* check_object_bounds();
};

RGE_Static_Object* RGE_Static_Object::check_object_bounds()
{
    float radius_x;
    float radius_y;
    short x2;
    short y1;
    short x1;
    short y2;
    short y_index;

    radius_x = this->master_obj->radius_x;
    radius_y = this->master_obj->radius_y;
    if (!(radius_x <= 0.0f && radius_y <= 0.0f)) {
        x1 = (short)(int)(this->world_x - 0.5f);
        y1 = (short)(int)(this->world_y - 0.5f);
        x2 = (short)(int)(this->world_x + 0.5f);
        y2 = (short)(int)(this->world_y + 0.5f);
        RGE_Map* map = this->owner->world->map;
        if (x1 < 0) x1 = 0;
        if (x2 >= map->map_width) x2 = (short)map->map_width - 1;
        if (y1 < 0) y1 = 0;
        if (y2 >= map->map_height) y2 = (short)map->map_height - 1;
        y_index = y1;
        if (y1 <= y2) {
            RGE_Tile** rows = map->map_row_offset;
            int x_offset = (int)x1 * 24;
            do {
                RGE_Tile* tile = (RGE_Tile*)((char*)rows[y_index] + x_offset);
                short x = x1;
                if (x1 <= x2) {
                    do {
                        RGE_Object_Node* n = tile->objects;
                        if (n != 0) {
                            do {
                                RGE_Static_Object* obj = n->node;
                                RGE_Master_Static_Object* master = obj->master_obj;
                                float object_radius_y = master->radius_y;
                                float object_radius_x = master->radius_x;
                                if (object_radius_x > 0.0f && object_radius_y > 0.0f) {
                                    float dy = obj->world_y - this->world_y;
                                    float dx = obj->world_x - this->world_x;
                                    if (dy < 0.0f) dy = -dy;
                                    if (dx < 0.0f) dx = -dx;
                                    if (dy <= object_radius_y + radius_y &&
                                        dx <= object_radius_x + radius_x) {
                                        return obj;
                                    }
                                }
                                n = n->next;
                            } while (n != 0);
                        }
                        tile = (RGE_Tile*)((char*)tile + 24);
                        x++;
                    } while (x <= x2);
                }
                y_index++;
            } while (y_index <= y2);
        }
    }
    return 0;
}
