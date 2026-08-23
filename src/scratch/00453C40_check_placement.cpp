// VA: 00453C40 check_placement (1909B)
// m_s_obj.cpp, lines 778-1011
// RGE_Master_Static_Object::check_placement (vt[8], slot 0x20)
// Validates placement of an object/building at (x,y): map bounds, center and
// surrounding required terrain, terrain movement cost, elevation, visibility,
// and overlap with existing objects.
//
// ATTEMPT LOG:
// probe1 (baseline): full clean reconstruction from original asm/Ghidra. frame=0x44/0x44,
//   calls 11/11 aligned, CFG cond 82/82, jumps 5/5, returns 9/9 all match. positional diff
//   1820B (95%) because FPU scheduling + register alloc + statement order differ broadly.
//   code_size 1777 vs 1909 (-132).
// probe2 (layout): load world->terrains[terrain] before world->map to match orig load order
//   (orig: edx=[world+54h] terrains first, ebx=[world+28h] map). No diff change; first
//   mismatch moved +0x11 -> +0x16. Remaining gap is not load order but FPU scheduling.
// probe3 (semantic/structure): audited the executable instead of trusting the prior decompiler
//   scaffold. The placement bounds use x/y +/- radius with a -0.001f upper-edge epsilon; the
//   perimeter is top/right/bottom/left around [x_min..x_max]x[y_min..y_max]; elevation is a
//   switch over flag 1/2; and the object scan uses +/-3.0f tile bounds. Rebuilt those facts with
//   short coordinate locals, explicit float edge temps, and the binary's nested x-then-y loops.
// probe4 (behavior): the semantic reconstruction moved to frame 0x44, 1863B, 71.48% shape,
//   and 1762B strict diff. It also kept all 11 calls and 82/82 conditional CFG parity. The
//   prior 62% result was not pure FPU scheduling: center acceptance must not overwrite the
//   full placement box used by the later cost/elevation scan.
// probe5 (context): a temporary world pointer and declaration-order variant was worse; the
//   living source uses direct player->world chains. Probe6 (behavior) restored the 0x44 frame
//   after separating immutable box bounds from the four perimeter-edge coordinates.
// probe7/8 (context): direct chains were unchanged; terrain-table-before-map moved the strict
//   diff to 1761B but did not recover the original saved-register coloring.
// probe9 (liveness): split edge assignments worsened the emitted body; restored explicit float
//   initializers. Probe10 (control-flow): mutating the outer box cursor worsened shape/frame;
//   restored a separate x cursor. Probe11 (liveness): a left-only pre-test temp was worse.
// probe12 (control-flow): changed the overlap column pass to the packet-proven guarded do/while;
//   metrics stayed at 1761B/71.31% with frame 0x44. Kept because it reflects the original
//   do/while/pointer progression rather than the earlier broad decompiler-shaped scaffold.
//
// ===== worker_sa26 session (10 probes) =====
// probe14 (control-flow): radius selection arm order swapped to `if (p8 != 0) {construction}
//   else {radius}` — binary has construction INLINE with je to the radius path (PDB 819/820
//   inline, 824/825 at target). diff 1761->1758.
// probe15 (behavior): traced original FPU stack byte-by-byte: the beta binary has TRANSPOSED
//   axes in the placement box — test2 compares map_width <= (radius_y_value + y) - 0.001 and
//   test4 map_height <= (radius_x_value + x) - 0.001; x_max=(int)(ry+y-0.001), y_max=(int)(rx+x-0.001).
//   The earlier scratch had "corrected" the geometry; the original bug must be reproduced.
//   The perimeter column/row ranges and the +/-3 overlap scan confirm the transposition is
//   consistent (matters only when radius_x != radius_y). 1758->1757.
// probe16 (layout): added `RGE_Game_World* world = player->world;` (PDB lines 779/806/807).
//   codegen-neutral (0 bytes) but kept as line-accurate.
// probe17 (layout): edge declaration order left,bottom(x-derived),right(y-derived),top with
//   -0.001 in declarations — 1789 (worse; extra fxch in fstp sequence). restored.
// probe18 (restore): back to 1757.
// probe19 (layout): -0.001 epsilon moved INTO the bound tests (PDB line 833 attribution;
//   original applies the fsubs at the compare site) with left,bottom,right,top declaration
//   order — 1745. The fsubs then land in the compare blocks (rebuilt B004/B006) rather than
//   the first FPU block, so this is not a final shape, but the slot layout improved overall.
// probe20 (layout): anchored the top/bottom perimeter walk pointers at the terrain byte
//   ((unsigned char*)&row[col] + 5) so the +5 folds into the addressing LEA (Ghidra shows
//   pbVar17 anchored at field_0x5). 1745->1746 but shape 71.48->72.23 and the interior
//   elevation/visibility region became byte-shape exact. (bitfield &: first attempt failed C2104.)
// probe21 (layout): edge-coordinate assignment order per PDB: center path y_min,x_min,x_max,
//   y_max (854-855); non-center x_max,x_min,y_min,y_max (860-862). interior +14 but overlap
//   -17; net 1753. shape 72.33, exact-blocks 37.48.
// probe22 (liveness): staged master->radius_x/y/z into locals mrx/mry/mrz (original reuses the
//   dead [esp+74]/[6C]/[68] parameter homes and re-reads the slots in the distance test).
//   BIG win: 1753->1720, size gap -54->-11 (1898/1909), shape 72.65, resync 67.31.
// probe23 (layout): ry-first radius branch assignment (ry before rx) to break the join-store
//   coalescing — 1723 (worse). restored.
// probe24 (layout): -0.001 back in the edge declarations (left,right(y),top,bottom(x)) keeping
//   byte anchors + mrx staging — 1731. FPU block closer but center-check region worse; restored
//   the condition-form.
// probe26 (layout): one shared perimeter counter declared before the short box coordinates
//   (a natural declaration-order lead from the first-hunk evidence) changed only 14 emitted
//   bytes, with no positional or shape gain; restored the scoped counters.
// probe27-45 (worker_sa0966ff4c): completed 20 meaningful hypotheses. Register-qualified
//   map, a receiver alias, an early terrain-index local, expanded edge assignments, int box
//   bounds, direct node-slot aliases, split bound guards, cached map dimensions, alternate
//   edge declaration permutations, and cached map-row pointers either duplicated the basin
//   or worsened frame/shape. A bool spelling for the two terrain flags was codegen-neutral.
//   Direct map-first player->world expressions gave the best clean frontier: 1718B strict
//   diff, 72.82% shape, 0x44 frame, 11/11 calls, and 82/82 conditional CFG signals.
//   A four-way edge-order variant lab found no exact result; the original lbrt order remained
//   the smallest source and size basin. No exact result was reached.
// - Follow-up: a cursor from one tile's objects.list member to the next improved
//   the strict diff to 1706 bytes. It required pointer arithmetic across member
//   subobjects, so it was rejected. Keep typed row and tile indexing.
//
// LEFT IN SCRATCH: semantically faithful, period-plausible reconstruction reproducing the
//   original placement box. Best recorded state: 1718B strict diff, 67.21% resync similarity,
//   72.82% shape, 1898/1909 size, 596/587 instructions, 11/11 calls, 82/82 conditional CFG,
//   and 37.48% exact-block coverage.
// NEXT LEADS:
//  * Original saves this in EBP and carries map in EBX; the clean source currently saves this
//    in ESI and leaves map in a local. This is a real declaration/liveness axis, not a reason
//    to add fake aliases or volatility. The interior/overlap regions now match shape exactly,
//    so the whole remaining diff is the early-region coloring + slot layout + the radius
//    branch join-store coalescing (original stores BOTH radius values in each branch; rebuilt
//    coalesces radius_y_value to the join because both branches leave it in EAX).
//  * The initial FPU topology is close in values/order but stack homes differ: original stores
//    left/right/top/bottom at [74]/[3c]/[2c]/[28]; current homes are compiler-selected. A later
//    worker should try a natural local declaration/order reproducer for the original's
//    `fld ry; fld rx; fadd x; fxch st2; fst [74]; fxch; fadd y` schedule (store left BEFORE
//    computing ry+y) — declaration-form -0.001 puts the fsubs in the first FPU block but
//    reorders the fst; condition-form matches the compare-site fsubs but defers them.
//  * Original overlap reuses the dead p10 home at [esp+7c] for the current row and keeps
//    overlap_x_min in edi (reloaded per row); current source keeps the row as a short local.
//    Verify whether a natural row-local declaration can recover that coalescing without
//    changing the proven unsigned-char parameter ABI.
// Context probe: an authentic owner-order wrapper with offset-equivalent,
// gap-only RGE_Game_World and RGE_Map declarations kept the 1725-byte current
// diff, exact 0x44 frame, and 11 ordered calls. Shared world/map vptr context is
// not the early prologue cause. The diagnostic variant was not retained.

class RGE_Game_World;
class RGE_Map;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Object_Node;
#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Visible_Map {
public:
    unsigned char get_visible(int col, int row);
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short count;
    char pad_0A[2];
};

class RGE_Tile {
public:
    short screen_xpos;               // +0x0
    short screen_ypos;               // +0x2
    unsigned char tile_type;         // +0x4
    unsigned char terrain_type : 5;  // +0x5
    unsigned char border_type : 4;   // +0x6
    unsigned char last_drawn_as;     // +0x7
    unsigned char last_drawn_shape;  // +0x8
    unsigned char draw_as;           // +0x9
    unsigned char draw_attribute;    // +0xA
    unsigned char last_drawn_shape2; // +0xB
    RGE_Object_List objects;          // +0xC
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;         // +0x0
    RGE_Object_Node* next;           // +0x4
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;                         // +0x4
    RGE_Master_Static_Object* master_obj; // +0x8
    char gap_0C[0x2C];
    float world_x;                   // +0x38
    float world_y;                   // +0x3C
    char gap_40[0x8];
    unsigned char object_state;      // +0x48
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;                   // +0x4
    long map_width;                  // +0x8
    long map_height;                 // +0xC
    char gap_10[0x8D7C];             // 0x10..0x8D8B
    RGE_Tile** map_row_offset;       // +0x8D8C
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;                    // +0x28
    char gap_2C[0x28];
    float** terrains;                // +0x54
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;        // +0x38
    RGE_Game_World* world;           // +0x3C
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;                   // +0x1B0
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* src);
    virtual void modify(float val, unsigned char op);
    virtual void modify_delta(float val, unsigned char op);
    virtual void modify_percent(float val, unsigned char op);
    virtual void save(int param_1);
    virtual void* make_new_obj(void*, float, float, float);
    virtual void* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
        unsigned char, unsigned char, unsigned char, unsigned char,
        unsigned char, unsigned char);
    virtual unsigned char alignment(float&, float&, RGE_Game_World*, unsigned char);

    unsigned char master_type;         // +0x4
    char _pad1[3];
    char* name;                        // +0x8
    short string_id;                   // +0xC
    short string_id2;                  // +0xE
    short id;                          // +0x10
    short copy_id;                     // +0x12
    short object_group;                // +0x14
    char _pad2[2];
    void* sprite;                      // +0x18
    void* death_sprite;                // +0x1C
    void* undead_sprite;               // +0x20
    unsigned char undead_flag;         // +0x24
    char _pad3;
    short hp;                          // +0x26
    float los;                         // +0x28
    unsigned char obj_max;             // +0x2C
    char _pad4[3];
    float radius_x;                    // +0x30
    float radius_y;                    // +0x34
    float radius_z;                    // +0x38
    void* selected_sound;              // +0x3C
    void* created_sound;               // +0x40
    void* death_sound;                 // +0x44
    short death_spawn_obj_id;          // +0x48
    unsigned char sort_number;         // +0x4A
    unsigned char can_be_built_on;     // +0x4B
    short button_pict;                 // +0x4C
    unsigned char hide_in_scenario_editor; // +0x4E
    char _pad5;
    short portrait_pict;               // +0x50
    unsigned char available;           // +0x52
    char _pad6;
    short tile_req1;                   // +0x54
    short tile_req2;                   // +0x56
    short center_tile_req1;            // +0x58
    short center_tile_req2;            // +0x5A
    float construction_radius_x;       // +0x5C
    float construction_radius_y;       // +0x60
    unsigned char elevation_flag;      // +0x64
    unsigned char fog_flag;            // +0x65
    short terrain;                     // +0x66
};
#endif

extern RGE_Base_Game* rge_base_game;

unsigned char RGE_Master_Static_Object::check_placement(
    RGE_Player* player, float x, float y, int* obj_id,
    unsigned char p5, unsigned char p6, unsigned char p7,
    unsigned char p8, unsigned char p9, unsigned char p10)
{
    RGE_Map* map = player->world->map;
    float* terrain_cost = player->world->terrains[terrain];

    float radius_x_value, radius_y_value;
    if (p8 != 0) {
        radius_x_value = construction_radius_x;
        radius_y_value = construction_radius_y;
    } else {
        radius_x_value = radius_x;
        radius_y_value = radius_y;
    }

    // BINARY-PROVEN GEOMETRY: the original beta code swaps the coordinate
    // axes for the upper edges. The executable computes the four edges in
    // declaration order left, bottom(x-derived), right(y-derived), top, then
    // tests: left<0, width<=right-0.001, top<0, height<=bottom-0.001 (the
    // -0.001 inward epsilon is applied inside the bound tests). right is
    // Y-derived and bottom is X-derived (an original transposition bug,
    // relevant only when radius_x != radius_y). The perimeter scans bound
    // columns by [x_min..x_max] and rows by [y_min..y_max] where
    // x_max=(int)right and y_max=(int)bottom.
    float left_edge = x - radius_x_value;
    float bottom_edge = radius_x_value + x;
    float right_edge = radius_y_value + y;
    float top_edge = y - radius_y_value;
    if (left_edge < 0.0 ||
        (float)map->map_width <= right_edge - 0.001f ||
        top_edge < 0.0 ||
        (float)map->map_height <= bottom_edge - 0.001f) {
        return 7;
    }

    short x_min = (short)left_edge;
    short x_max = (short)(right_edge - 0.001f);
    short y_min = (short)top_edge;
    short y_max = (short)(bottom_edge - 0.001f);

    short center_y;
    short center_x;
    short edge_y_min;
    short edge_x_max;
    short edge_y_max;
    short edge_x_min;
    short req_center1 = center_tile_req1;

    if (req_center1 >= 0 || center_tile_req2 >= 0) {
        // The center tile must be one of the requested terrain types. The
        // original converts y before x and reads the center only after bounds.
        center_y = (short)y;
        center_x = (short)x;
        unsigned short center_terrain =
            (unsigned short)(map->map_row_offset[center_y][center_x].terrain_type & 0x1f);
        if (center_terrain != (unsigned short)req_center1 &&
            center_terrain != (unsigned short)center_tile_req2) {
            return 1;
        }
        edge_y_min = center_y;
        edge_x_min = center_x;
        edge_x_max = center_x;
        edge_y_max = center_y;
    } else {
        edge_x_max = x_max;
        edge_x_min = x_min;
        edge_y_min = y_min;
        edge_y_max = y_max;
    }

    bool bVar9 = false;
    bool bVar10 = false;
    short req_terrain1 = tile_req1;

    if (req_terrain1 >= 0 || tile_req2 >= 0) {
        short terrain_table = (short)(edge_x_min - 1);

        // Top edge (row y_min-1), columns x_min..x_max. The original anchors
        // the walk pointer at the terrain-type byte (+5), folding it into the
        // addressing LEA.
        if ((short)(edge_y_min - 1) >= 0 && edge_x_min <= edge_x_max) {
            unsigned char* pb =
                (unsigned char*)&map->map_row_offset[(short)(edge_y_min - 1)][edge_x_min] + 5;
            int n = (int)edge_x_max - (int)edge_x_min + 1;
            do {
                unsigned short t = (unsigned short)(*pb & 0x1f);
                if (t == (unsigned short)req_terrain1) bVar9 = 1;
                if (t == (unsigned short)tile_req2) bVar10 = 1;
                pb += 0x18;
                n--;
            } while (n != 0);
        }

        // Right edge (column x_max+1), rows y_min..y_max.
        if ((short)(edge_x_max + 1) < map->map_width && edge_y_min <= edge_y_max) {
            RGE_Tile** pp = map->map_row_offset + edge_y_min;
            int n = (int)edge_y_max - (int)edge_y_min + 1;
            do {
                unsigned short t =
                    (unsigned short)((*pp)[(short)(edge_x_max + 1)].terrain_type & 0x1f);
                if (t == (unsigned short)req_terrain1) bVar9 = 1;
                if (t == (unsigned short)tile_req2) bVar10 = 1;
                pp++;
                n--;
            } while (n != 0);
        }

        // Bottom edge (row y_max+1), columns x_max..x_min (reverse).
        if ((short)(edge_y_max + 1) < map->map_height && edge_x_min <= edge_x_max) {
            unsigned char* pb =
                (unsigned char*)&map->map_row_offset[(short)(edge_y_max + 1)][edge_x_max] + 5;
            int n = (int)edge_x_max - (int)edge_x_min + 1;
            do {
                unsigned short t = (unsigned short)(*pb & 0x1f);
                if (t == (unsigned short)req_terrain1) bVar9 = 1;
                if (t == (unsigned short)tile_req2) bVar10 = 1;
                pb -= 0x18;
                n--;
            } while (n != 0);
        }

        // Left edge (column x_min-1), rows y_max..y_min (reverse).
        if (terrain_table >= 0 && edge_y_min <= edge_y_max) {
            RGE_Tile** pp = map->map_row_offset + edge_y_max;
            int n = (int)edge_y_max - (int)edge_y_min + 1;
            do {
                unsigned short t =
                    (unsigned short)((*pp)[terrain_table].terrain_type & 0x1f);
                if (t == (unsigned short)req_terrain1) bVar9 = 1;
                if (t == (unsigned short)tile_req2) bVar10 = 1;
                pp--;
                n--;
            } while (n != 0);
        }

        if (!bVar9 && !bVar10) return 1;
    }

    // Interior cost / elevation / visibility check over the whole box.
    bVar9 = false;
    for (short col = x_min; col <= x_max; col++) {
        for (short row = y_min; row <= y_max; row++) {
            unsigned char ct =
                (unsigned char)(map->map_row_offset[row][col].terrain_type & 0x1f);
            if (terrain_cost[ct] <= 0.0f) {
                return 2;
            }
            if (p5 != 0 &&
                (rge_base_game->prog_mode == 7 ||
                 player->visible->get_visible(col, row))) {
                bVar9 = 1;
            }
            if (p6 != 0) {
                unsigned short tt = map->map_row_offset[row][col].tile_type;
                switch (elevation_flag) {
                    case 1:
                        if ((tt != 0 && tt != 5 && tt != 7) &&
                            (tt != 6 && tt != 8)) {
                            return 3;
                        }
                        break;
                    case 2:
                        if (tt != 0) {
                            return 3;
                        }
                        break;
                }
            }
        }
    }

    if (p5 == 1 && !bVar9) return 5;
    if (radius_x_value <= 0.0f && radius_y_value <= 0.0f) return 0;

    // Object-overlap scan.
    short overlap_x_min = (short)(x - 3.0f);
    short overlap_y_min = (short)(y - 3.0f);
    short overlap_x_max = (short)(x - (-3.0f));
    short overlap_y_max = (short)(y - (-3.0f));
    if (overlap_x_min < 0) overlap_x_min = 0;
    if (overlap_x_max >= map->map_width) overlap_x_max = (short)map->map_width - 1;
    if (overlap_y_min < 0) overlap_y_min = 0;
    if (overlap_y_max >= map->map_height) overlap_y_max = (short)map->map_height - 1;

    if (p10 != 0 && (p9 != 0 || radius_z > 0.0) &&
        overlap_y_min <= overlap_y_max) {
        do {
            if (overlap_x_min <= overlap_x_max) {
                short col2 = overlap_x_min;
                do {
                    for (RGE_Object_Node* node = map->map_row_offset[overlap_y_min][col2].objects.list;
                         node != 0; node = node->next) {
                        RGE_Static_Object* obj = node->node;
                        if (obj->object_state < 7 &&
                            ((p9 == 0 || obj->master_obj->can_be_built_on != 1) ||
                             can_be_built_on != 0)) {
                            RGE_Master_Static_Object* master = obj->master_obj;
                            // The original stages the three radii into local
                            // slots (reusing dead parameter homes) before the
                            // compares, then reuses them in the distance test.
                            float mrx = master->radius_x;
                            float mry = master->radius_y;
                            float mrz = master->radius_z;
                            if ((mrx > 0.0 && mry > 0.0) &&
                                ((mrz > 0.0 && radius_z > 0.0) ||
                                 (mrz <= 0.0 && radius_z <= 0.0))) {
                                float dy = obj->world_y - y;
                                float dx = obj->world_x - x;
                                if (dy < 0.0f) dy = -dy;
                                if (dx < 0.0f) dx = -dx;
                                if (dx < mrx + radius_x_value &&
                                    dy < mry + radius_y_value) {
                                    if (obj_id != 0) *obj_id = obj->id;
                                    return 6;
                                }
                            }
                        }
                    }
                    col2++;
                } while (col2 <= overlap_x_max);
            }
            overlap_y_min++;
        } while (overlap_y_min <= overlap_y_max);
    }

    return 0;
}
