// VA: 0045AB20 RGE_Missile_Object::make_object_collision_list
// PDB source: misl_obj.cpp lines 148-236
// attempt log:
// 1: natural decompiler-shaped C++ with /GX likely needed for new/delete EH.
// 2: explicit operator_new + placement ctor was too small (736B) and lacked EH cleanup.
// 3: C++ new/delete with /GX gives 800B vs original 802B; extraction stops before diff, likely close EH/source-shape but still short.
// 4: reversed initial radius check order; no size change.
// 5: flag probes: /O2 /GX no /Oy still 800B; /O1 /GX 678B; /Od /GX reaches 802B but broad mismatch from offset 0, rolled back.
// 6: restored canonical owner->world->map chain, master/object field ownership, 3-tile coordinate bounds, and typed tile object-list traversal; reduced to 772B before liveness shaping.
// 7: retained proven byte cursors for map rows/tile offsets, materialized object radii before checks, and reversed z comparison to dz-first; 821B, exact frame, 208 positional diff.
// 8: coordinate declaration/role swaps and a zero flag local were duplicate codegen; no emitted change.
// 9: positive valid-body/invalid-return control-flow forms were duplicate at the best 821B basin; a result-local form changed tail layout but not diff.
// 10: lower-x alias and EH-enabled 9-variant lab were nonproductive; lab grouped 3 basins, no size/frame-eligible match.
// 11: initialized the list result before a positive radius body to seek one common return topology; 806B with one return but 729-byte drift, restored.
// 12: rewrote the inner collision-node walk as a natural for loop; emitted code was unchanged, restored the clean while form.
// 13: natural declaration initializers for the four coordinate ftol results were codegen-duplicate.
// 14: moved the short coordinate declarations to the function declaration group; codegen was unchanged.
// 15: replaced proven zero, +/-3, and -0.1 constants with the shared DAT_00570934/38/3c/40 globals; codegen metrics were unchanged.
// 16: assigned an uninitialized list result in the invalid-radius arm and returned once; size became 798B with one return, but structural shape fell to 82.57% and broad drift, restored.
// 17: moved that result declaration before radius locals; codegen was unchanged, restored.
// 18: modeled the proven virtual master/map/player surfaces and RGE_Combat_Object base; codegen was unchanged, restored.
// 19: grouped the four coordinate initializers; diff improved to 170B and the x homes matched, but the required ownership use was wrong, restored.
// 20: reordered row/tile locals, tried typed row-pointer traversal, and moved bounds declarations; each worsened or duplicated codegen, restored.
// 21: revalidated the pinned 821B baseline; all nine calls and the 0x3C frame
// remain exact, but coordinate-result homes and the tail still differ.
// 22: reviewed DAT_00570934/38/3c/40 externs; named globals changed no checked
// metric, but they remain the binary-supported constant surface.
// 23: natural map_row_offset[y][x] indexing reduced code size but moved to a
// 0x34 frame and broad drift; restored for comparison.
// 24: declaration-order and coordinate-name swaps were codegen duplicates.
// 25: removing the explicit positive-body else was a codegen duplicate.
// 26: explicit int row/column indices reached 803B but lost the original CFG
// and frame topology.
// 27: real virtual destructors changed the destructor call to an indirect call
// and removed the required delete site; rejected as an ABI mismatch.
// 28: <stdlib.h> changed local scheduling but not checked metrics.
// 29: typed row-pointer cursors, split row pointers, and cached row tables all
// entered worse 0x34-frame basins.
// 30: result initialization before the radius guard was a codegen duplicate.
// 31: declaration initializers changed expression order or were duplicates.
// 32: direct typed tile addressing with map_row_offset[y][x] was the best
// policy-valid natural form tested, but measured 787B, 0x34 frame, and 547
// positional bytes; natural counted short loops were also worse.
// 33: a nine-variant lab over coordinate declaration and map-index forms found
// no size/frame/call-set eligible variant and six emitted-code groups.
// 34: final policy source uses reviewed constants, typed map_row_offset[y][x],
// natural new/delete, and a real object-list destructor declaration.  Final
// validation is 787B versus 802B, 0x34 versus 0x3C frame, 547 positional bytes,
// and nine aligned calls.  No policy-valid exact source was found.
// 35: restored the 821B raw row/tile cursor source and correct lower/upper
// coordinate ownership; this recovered the 0x3C frame and 208B mismatch.
// 36: kept the four short initializers in the original result roles.  The
// coordinate-home basin improved to 170B only while the clamp ownership was
// wrong, so that form is not retained.
// 37: mirrored the stat_obj.cpp donor declaration scope and short order;
// emitted code was unchanged or returned to the 208B basin.
// 38: initialized each tile pointer before the inner x-range guard.  Original
// assembly loads the row table and tile address before that compare, and this
// natural fault order reduced the mismatch to 206B with 91.53% shape.
// 39: register hints, widened lower-x aliases, result locals, and declaration
// order did not improve the 206B basin.  Result-local variants had broad
// structural drift or the wrong return layout and were restored.
// 40: final natural candidate retains the proven pre-guard tile load, raw row
// offset cursor, direct new/delete, and semantic lower/upper bounds.  It is
// 821B versus 802B, 0x3C frame, 9 aligned calls, 206B strict mismatch,
// 91.53% shape, and 68.05% exact-block coverage.  The remaining residue is
// coordinate register coloring, the reversed cmp operand, and return-tail
// placement.  No policy-valid exact source was found.
// 41: canonical misl_obj.cpp context now includes the PDB-order owners through
// this target. The earlier owner COMDATs are byte-identical in the grouped
// object, including the canonical teleport and 0x6C die_die_die dispatch surface.
// The grouped target keeps the 0x3C frame, pre-guard tile load, and nine calls;
// its 816-byte COMDAT remains a context reconstruction, not an exact claim.
// 42: cvdump module 147 gives original local records for dx, dy, rx, ry, rx2,
// ry2, map, check_list, x1, and x2.  It has no separate result pointer.  The
// source now uses those radius and overlap roles; this does not change codegen.
// 43: natural typed map_row_offset[row][column] loops in the authentic wrapper
// produced a 784-byte, 0x34-frame basin.  The raw row/tile cursor remains because
// it preserves the original pre-guard tile read, 0x3C frame, and loop lowering.
// 44: a fresh canonical misl_obj.cpp wrapper build is 802 bytes with the exact
// frame, nine calls, CFG counts, and one return.  Its 160-byte residue is only
// from x1/x2 register and stack-home selection between offsets +0x6C and +0x176.
// The original PDB places x2 at -0x44 and x1 at -0x40.  VC5 instead assigns the
// current natural roles to the opposite homes.  Declaration order, scopes,
// register hints, loop forms, PDB-backed float lifetimes, full map declarations,
// and supported headers did not change that allocation.
// 45: a fresh grouped build removed the two real destructor COMDAT neighbors
// that have no module-local PDB owners.  The target stayed 802B/160B with the
// same frame, allocation, publication, overlap path, and nine calls.
// 46: explicit vptr-leading master, map, world, and player declarations kept
// every proven offset and all grouped metrics unchanged.  They do not restore
// the x1/x2 homes.
// 47: an authoritative grouped check with the PDB-order owner wrapper reports
// 802B, 0x3C, one return, nine ordered calls, and 160 positional bytes.
// It verifies the owner symbol and boundary, but it is not exact.
// 48: the wrapper probe was restored to this standalone PDB-local owner.
// Fresh validation remains 821B/206B, 0x3C, one extra return, and nine calls.
// 49: replaced the fallback raw-vtable field with a natural virtual destructor
// declaration.  The target reads only the list member; output stayed unchanged.
// 50: fresh PDB inspection confirms parameter delta, locals x1/x2, and the
// dx/dy/radius homes. Grouped source-shape probes retained the 802-byte frame
// and nine ordered calls, but no natural form matched the x1/x2 homes.
// 51: grouped coordinate declaration, assignment, scope, role, register, and
// float-order labs produced four codegen groups. The closest was 124 bytes
// different and used an unsupported coordinate-role interpretation.
// 52: adding period <windows.h> to the authentic missile-object context changed
// no group. It is not retained because no target evidence requires it here.
// 53: fresh checks preserve map anchors 00458600, 004595E0, 00459900, and
// 00459A00. Fresh moving-object checks preserve 0045C450, 0045C5C0, and
// 0045C700. No shared context file changed during this pass.
// FLAGS: config/flags/0045AB20_make_object_collision_list.rsp (/nologo /c /O2 /Oy /GX)

// left in scratch: 821B rebuilt vs 802B original, 206 positional bytes, exact frame/call set; remaining gap is coordinate-result register/home assignment plus tail/block layout.

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
struct RGE_Check_Node;
class RGE_Static_Object;

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object* object, float dx, float dy, unsigned char flag);
};

struct RGE_Check_Node {
    RGE_Static_Object* object;
    float dx;
    float dy;
    unsigned char flag;
    unsigned char gap[3];
    RGE_Check_Node* next;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
    float radius_z;
};

class RGE_Map;

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects;
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Missile_Object : public RGE_Static_Object {
public:
    RGE_Check_List* make_object_collision_list(float extra);
};
#endif

RGE_Check_List* RGE_Missile_Object::make_object_collision_list(float extra) {
    float dx;
    float dy;
    float rx;
    float ry;
    float rx2;
    float ry2;
    short local_40;
    short x1;
    short sVar9;
    short sVar10;
    RGE_Map* map;
    RGE_Check_List* list;

    rx = this->master_obj->radius_x;
    ry = this->master_obj->radius_y;

    if (rx <= 0.0f || ry <= 0.0f) {
        return 0;
    } else {

    local_40 = (short)(int)(this->world_x - 3.0f);
    sVar9 = (short)(int)(this->world_y - 3.0f);
    x1 = (short)(int)(this->world_x + 3.0f);
    sVar10 = (short)(int)(this->world_y + 3.0f);

    map = this->owner->world->map;
    list = new RGE_Check_List;

    if (local_40 < 0) {
        local_40 = 0;
    }
    if ((int)x1 >= map->map_width) {
        x1 = (short)(map->map_width - 1);
    }
    if (sVar9 < 0) {
        sVar9 = 0;
    }
    if ((int)sVar10 >= map->map_height) {
        sVar10 = (short)(map->map_height - 1);
    }

    if (sVar9 <= sVar10) {
        int tile_offset = (int)local_40 * (int)sizeof(RGE_Tile);
        int row_offset = (int)sVar9 * (int)sizeof(RGE_Tile*);
        int row_count = (int)sVar10 - (int)sVar9 + 1;
        do {
            RGE_Tile* tile = (RGE_Tile*)((char*)
                *(RGE_Tile**)((char*)map->map_row_offset + row_offset) + tile_offset);
            if (local_40 <= x1) {
                int column_count = (int)x1 - (int)local_40 + 1;
                do {
                    RGE_Object_Node* node = tile->objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->object;
                        if (object != this) {
                            RGE_Master_Static_Object* object_master = object->master_obj;
                            ry2 = object_master->radius_y;
                            rx2 = object_master->radius_x;
                            if (ry2 > 0.0f && rx2 > 0.0f) {
                                float dz = object->world_z - this->world_z;
                                if (dz >= -(object_master->radius_z - -0.1f) &&
                                    dz <= this->master_obj->radius_z - -0.1f) {
                                    dx = object->world_x - this->world_x;
                                    dy = object->world_y - this->world_y;
                                    if (dx < 0.0f) {
                                        dx = -dx;
                                    }
                                    if (dy < 0.0f) {
                                        dy = -dy;
                                    }
                                    dx = dx - (rx2 + rx + extra);
                                    dy = dy - (ry2 + ry + extra);
                                    if (dx <= 0.0f && dy <= 0.0f) {
                                        list->add_node(object, dx, dy, 0);
                                    }
                                }
                            }
                        }
                        node = node->next;
                    }
                    tile++;
                    column_count--;
                } while (column_count != 0);
            }
            row_offset += 4;
            row_count--;
        } while (row_count != 0);
    }

    if (list->list == 0) {
        delete list;
        list = 0;
    }
    return list;
    }
}
