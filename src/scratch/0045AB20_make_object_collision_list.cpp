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
// FLAGS: config/flags/0045AB20_make_object_collision_list.rsp (/nologo /c /O2 /Oy /GX)

extern float DAT_00570934;
extern float DAT_00570938;
extern float DAT_0057093c;
extern float DAT_00570940;
// left in scratch: 821B rebuilt vs 802B original, 208 positional bytes, exact frame/call set; remaining gap is coordinate-result register/home assignment plus tail/block layout.

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

RGE_Check_List* RGE_Missile_Object::make_object_collision_list(float extra) {
    RGE_Master_Static_Object* master = this->master_obj;
    float dx = master->radius_x;
    float dy = master->radius_y;

    if (dx <= DAT_00570934 || dy <= DAT_00570934) {
        return 0;
    } else {

    short x1;
    short local_40;
    short sVar9;
    short sVar10;
    x1 = (short)(int)(this->world_x - DAT_00570938);
    sVar9 = (short)(int)(this->world_y - DAT_00570938);
    local_40 = (short)(int)(this->world_x - DAT_0057093c);
    sVar10 = (short)(int)(this->world_y - DAT_0057093c);

    RGE_Map* map = this->owner->world->map;
    RGE_Check_List* list = new RGE_Check_List;

    if (x1 < 0) {
        x1 = 0;
    }
    if ((int)local_40 >= map->map_width) {
        local_40 = (short)(map->map_width - 1);
    }
    if (sVar9 < 0) {
        sVar9 = 0;
    }
    if ((int)sVar10 >= map->map_height) {
        sVar10 = (short)(map->map_height - 1);
    }

    if (sVar9 <= sVar10) {
        int row_count = (int)sVar10 - (int)sVar9 + 1;
        do {
            if (x1 <= local_40) {
                RGE_Tile* tile = &map->map_row_offset[sVar9][x1];
                int column_count = (int)local_40 - (int)x1 + 1;
                do {
                    RGE_Object_Node* node = tile->objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->object;
                        if (object != this) {
                            RGE_Master_Static_Object* object_master = object->master_obj;
                            float object_dy = object_master->radius_y;
                            float object_dx = object_master->radius_x;
                            if (object_dy > DAT_00570934 && object_dx > DAT_00570934) {
                                float dz = object->world_z - this->world_z;
                                if (dz >= -(object_master->radius_z - DAT_00570940) &&
                                    dz <= this->master_obj->radius_z - DAT_00570940) {
                                    float rx = object->world_x - this->world_x;
                                    float ry = object->world_y - this->world_y;
                                    if (rx < DAT_00570934) {
                                        rx = -rx;
                                    }
                                    if (ry < DAT_00570934) {
                                        ry = -ry;
                                    }
                                    rx = rx - (object_dx + dx + extra);
                                    ry = ry - (object_dy + dy + extra);
                                    if (rx <= DAT_00570934 && ry <= DAT_00570934) {
                                        list->add_node(object, rx, ry, 0);
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
