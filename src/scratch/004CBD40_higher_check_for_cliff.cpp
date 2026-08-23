// 004CBD40 TRIBE_Combat_Object::higher_check_for_cliff
// Source: t_c_obj.cpp lines 1379-1442
// attempt 1: natural decompiler-shaped source with local layout/types; close but RGE_Tile size wrong (20 vs 24), fcom constants double, and register coloring differs.
// attempt 2: fixed RGE_Tile to 0x18 so map_row_offset[row][col] emits lea x+x*2 then [row+x*8+10h]; moved first mismatch from tile indexing to register coloring.
// attempt 3: used absolute float constants for 0.0/2pi; got correct dword global fcom/fsub addresses but introduced extra FPU stack shuffling when a was a named float.
// attempt 4: kept double atan2/fpatan value with absolute float constants; better size, but remaining broad drift starts at EBX/EBP/EDI allocation for node/angle/y2.
// attempt 5: rewrote angle tests using decompiler's outside-range condition; improved to best edit diff 120B and first mismatch 70.
// attempt 6: tried register-qualified node/angle/y2 locals; VC5 ignored/helped none, no metric improvement.
// attempt 7: tried while(1) with explicit null-return at loop bottom; worsened early branch spans.
// attempt 8: tried explicit angle_local/y2_bits locals to force EDI/EBP; worsened to first mismatch 19.
// attempt 9: tried for-loop over node->next; worsened loop entry/null-test shape.
// attempt 10: tried naming lines_intersect result local; worsened call/branch scheduling and reverted.
// session baseline: default VC5 build is 421 bytes with exact frame/saved-reg/call-set parity;
//   first mismatch is +0x46, where node/angle/facet/offset color as EBP/EBX/EDI/ESI
//   instead of the oracle's EBX/EDI/ESI/EAX.  The remaining drift is a broad liveness basin.
// session ABI probe: PDB's float&/int& output ABI emits the same bytes as pointer proxies;
//   references are retained as the more plausible source surface.
// session layout probe: restored the canonical 24-byte RGE_Tile/RGE_Object_List ownership;
//   objects.list emits the same bytes as the narrow +0x10 tile stub.
// session probes: direct angle lvalue, byte facet, local declaration-order variants, and
//   facet/offset order variants did not improve the basin; compare-before-store angle adds 10 bytes.
// fresh pass r2: baseline reconfirmed 421 bytes / 258 positional diff. Named endpoint-y2,
// reversed endpoint addition, named tile, virtual object/list/map donors, the intermediate
// combat-object hierarchy, entry-declared node/cliff locals, and entry endpoint-y2 all emitted
// the same 421-byte basin. Restored the clean typed source; unresolved clue remains oracle
// EBP=y2 plus EBX=node while this build chooses EBP=node and EBX=angle.
// fresh pass r3: reversed the typed map-height predicate to map->map_height <= row, matching
// the decompiler predicate; VC5 reversed cmp operands and jge to jle, worsening the first hunk.
// Restored the clean predicate; no source change retained.
// fresh pass r4: split the typed terrain height and width bounds into separate natural guards;
// VC5 reversed the height/width compares and worsened the first hunk by 4 bytes.
// Restored the combined clean guard; no source change retained.
// fresh pass r5: natural while-loop, pointer output ABI, math-header context, direct angle
// assignment, angle alias, split cliff guards, endpoint-y2 local, and named angle globals
// did not improve the 421-byte basin.  Virtual static/master surfaces preserve the same bytes
// and restore the oracle's virtual decorated member identity; retain those natural declarations.
// fresh pass r6: spelling the facet cutoff as facet >= 0x19 recovers the oracle's cmp 19/jge,
// one exact late block, and better block/resync metrics without changing positional diff.
// Reordering offset/facet declarations is emitted-code duplicate.  A typed eight-float cliff
// table removes raw address expressions but worsens size and positional drift.
// Main review retained that typed table because raw absolute addresses are not
// valid living source. Numeric pool values are ordinary source constants.
// Left in scratch: behavior and call set look right, but broad register-allocation/FPU compare drift remains; not an accepted_drift candidate.
// fresh pass r7: replaced the unresolved typed table and numeric absolute-address
// expressions with reviewed data symbols and the proven 0x20-byte table stride.
// This restores the 421-byte code-size basin and improves positional diff to 257.
// The source remains a typed float access over a binary-proven contiguous table.
// Seven follow-up probes covered angle aliases, endpoint lifetimes, loop forms,
// narrow facet width, and comparison direction. They did not improve the basin.
// BINARY NOTE: The shipped upper-bound tests use x87 C0|C3 status bits. Keep the
// natural bound-left `upper > angle` spelling so unordered values follow those
// branches; the equivalent bound-right spelling emits only C0 in VC5.
// Canonical stat-object, map, tile, list, and node fields are retained from
// exact stat_obj donors. They preserve proven offsets but are codegen-neutral.

extern "C" double __cdecl atan2(double, double);
extern float DAT_00574c98;
extern float DAT_00574ca4;

typedef unsigned char uchar;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    uchar master_type;
    char gap_05[3];
    void* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char gap_16[0xC2];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;                 // +0x35
    uchar selected;
    uchar selected_group;
    float world_x;               // +0x38
    float world_y;               // +0x3C
    float world_z;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    uchar centered;
    uchar gap_0D[3];
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
};

extern "C" int __cdecl lines_intersect(float, float, float, float, float, float, float, float);

extern float DAT_0058725c;
extern float DAT_00587268;
#define CLIFF_VALUE(offset) (*(float*)((char*)&DAT_00587268 + (offset)))
#define CLIFF_ANGLE(offset) (*(float*)((char*)&DAT_0058725c + (offset)))

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    virtual int higher_check_for_cliff(RGE_Static_Object* obj, int col, int row,
                                       float x1, float y1, float x2, float y2,
                                       RGE_Map* map, RGE_Static_Object* old_obj,
                                       float& angle, int& dir);
};

int TRIBE_Combat_Object::higher_check_for_cliff(RGE_Static_Object* obj, int col, int row,
                                                float x1, float y1, float x2, float y2,
                                                RGE_Map* map, RGE_Static_Object* old_obj,
                                                float& angle, int& dir)
{
    if (row < 0 || row >= map->map_height || col < 0 || col >= map->map_width) {
        return 0;
    }

    RGE_Object_Node* node = map->map_row_offset[row][col].objects.list;
    if (node == 0) {
        return 0;
    }
    do {
        RGE_Static_Object* cliff = node->node;
        if (cliff->master_obj->object_group == 0x22 && cliff != old_obj) {
            old_obj = cliff;
            if (angle == -1.0f) {
                double a = atan2((double)(obj->world_y - this->world_y), (double)(obj->world_x - this->world_x));
                angle = (float)a;
                if (a < DAT_00574c98) {
                    angle = (float)(a - DAT_00574ca4);
                }
            }

            int facet = cliff->facet;
            int off = facet << 5;
            if (lines_intersect(x1, y1, x2, y2,
                                CLIFF_VALUE(off) + x1,
                                CLIFF_VALUE(off + 4) + y1,
                                CLIFF_VALUE(off + 8) + x2,
                                CLIFF_VALUE(off + 12) + y2)) {
                if ((facet >= 0x19 || angle < CLIFF_ANGLE(off - 4) || CLIFF_ANGLE(off) > angle) &&
                    (angle < CLIFF_ANGLE(off + 4) || CLIFF_ANGLE(off + 8) > angle)) {
                    --dir;
                    return 1;
                }
                ++dir;
                return 1;
            }
        }
        node = node->next;
    } while (node != 0);

    return 0;
}
