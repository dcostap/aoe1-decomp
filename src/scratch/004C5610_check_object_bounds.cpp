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
// 16: named the x-overlap sum before the final comparison to test a derived
// bound matching the original fcompp; rebuilt 524 B with diff 120, so restored
// the clean direct predicate.
// 17: absolute zero and the 3/-3 coordinate constants are required for the
// original memory operands; the extern declarations preserve that context.
// 18: volatile dx recovered one stack reload and improved the diagnostic to
// 98 bytes, but added an FPU exchange and was rejected as metric-only steering.
// 19: final clean source restores nonvolatile dx, direct overlap arithmetic,
// and the early y-range failure. Validation remains a 524-byte mismatch.
// 20: positive y-range guard was codegen-equivalent to the early failure form.
// 21: grouped declarations and declaration-time bound initialization were
// codegen-equivalent; x2/y2 homes remained swapped.
// 22: x-overlap operand reversal, !(dx > limit), and explicit failure-OR
// forms were codegen-equivalent; none recovered the original fcompp.
// 23: declaring dx before dy while keeping dy-then-dx evaluation was a
// codegen duplicate. Reversing the second y2/x2 initialization pair worsened
// size and call scheduling, so the original order was restored.
// 24: positive guard plus infinite outer loop, explicit post-increment return,
// and inverted continue forms were all codegen-equivalent to the clean loop.
// 25: a minimal polymorphic RGE_Static_Object declaration was a codegen
// duplicate; the explicit vptr field remains the smaller local surface.
// BINARY NOTE: The executable's final X overlap accepts less, equal, and
// unordered x87 results. The named X limit preserves that shipped NaN behavior.
// TU context audit: same-module stat_obj.cpp owners were tested in address order.
// No tested authentic nearest-one or cumulative multi-owner prefix compiled
// with this standalone class surface. Padding-only owners were excluded. No
// context change is validated.
// Resume audit: build/stat_obj_context_r2.h compiles the smallest shared
// surface with real owners 004C1CF0-004C23F0 in PDB order, plus this body.
// /GX is required for the real allocation owners. The target remains 524 B.
// The named X limit reduces the strict difference from 102 to 43 bytes. The
// rebuilt final X predicate now matches the executable through FCOMPP and the
// C0-or-C3 status test. The first later normal owner, 004C2970,
// is blocked by missing TDrawArea/ScreenPoint/Win32 drawing surfaces. No
// config change was made. Earlier x2/y2 spill homes and the final loop exit
// shape remain unresolved.
// Continuation audit:
// - Original DIA locals prove nonvolatile float dx at entry ESP-0x2C, short
//   x2 at -0x14, short y2 at -0x10, and short y_index at -0x0C.
// - Declaration order, function scope, register hints, casts, named temporary
//   assignments, map/traversal scope, and debug flags reproduced one 43-byte
//   basin. These forms do not control the two upper-bound homes.
// - Volatile dx selects the original x2/y2 homes. It also adds a false x87
//   exchange at the final X test. DIA proves dx is not volatile, so reject it.
// - Reusing y_index for the initial Y bound changed the complete frame use.
//   The omitted optimized y1 PDB record does not prove source-variable reuse.
// - Separate row-failure returns and binary-shaped labels tail-merge to the
//   same late CFG. The remaining 43 bytes need a natural liveness or context
//   fact that selects both the original homes and the direct near backedge.
// Exact-finish audit:
// - Scoped and declaration-initialized bounds changed size or block shape;
//   reordered bounds did not change their homes.
// - Found labels, explicit outer-loop labels, positive continue forms,
//   register hints, and the authentic target line number did not change code.
// - The clean source remains the smallest tested natural reconstruction.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
typedef unsigned char uchar;

extern float DAT_00574720;
extern float DAT_00574748;
extern float DAT_0057474c;

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

#endif

RGE_Static_Object* RGE_Static_Object::check_object_bounds()
{
    float radius_x;
    float radius_y;
    short x1;
    short y1;
    short x2;
    short y2;
    short y_index;

    radius_x = this->master_obj->radius_x;
    radius_y = this->master_obj->radius_y;
    if (!(radius_x <= DAT_00574720 && radius_y <= DAT_00574720)) {
        x1 = (short)(int)(this->world_x - DAT_00574748);
        y1 = (short)(int)(this->world_y - DAT_00574748);
        x2 = (short)(int)(this->world_x - DAT_0057474c);
        y2 = (short)(int)(this->world_y - DAT_0057474c);
        RGE_Map* map = this->owner->world->map;
        if (x1 < 0) x1 = 0;
        if (x2 >= map->map_width) x2 = (short)map->map_width - 1;
        if (y1 < 0) y1 = 0;
        if (y2 >= map->map_height) y2 = (short)map->map_height - 1;
        y_index = y1;
        if (y1 > y2) return 0;
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
                            if (object_radius_x > DAT_00574720 && object_radius_y > DAT_00574720) {
                                float dy = obj->world_y - this->world_y;
                                float dx = obj->world_x - this->world_x;
                                if (dy < DAT_00574720) dy = -dy;
                                if (dx < DAT_00574720) dx = -dx;
                                if (dy <= object_radius_y + radius_y) {
                                    float x_limit = object_radius_x + radius_x;
                                    if (!(dx > x_limit)) {
                                        return obj;
                                    }
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
    return 0;
}
