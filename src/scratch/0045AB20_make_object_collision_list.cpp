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
// FLAGS: config/flags/0045AB20_make_object_collision_list.rsp (/nologo /c /O2 /Oy /GX)
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
    void* vtable;
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

    if (dx <= 0.0f || dy <= 0.0f) {
        return 0;
    } else {

    short x1;
    short local_40;
    short sVar9;
    short sVar10;
    x1 = (short)(int)(this->world_x - 3.0f);
    sVar9 = (short)(int)(this->world_y - 3.0f);
    local_40 = (short)(int)(this->world_x + 3.0f);
    sVar10 = (short)(int)(this->world_y + 3.0f);

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
        int tile_offset = (int)x1 * (int)sizeof(RGE_Tile);
        int row_offset = (int)sVar9 * (int)sizeof(RGE_Tile*);
        int row_count = (int)sVar10 - (int)sVar9 + 1;
        do {
            if (x1 <= local_40) {
                RGE_Tile* tile = (RGE_Tile*)((char*)
                    *(RGE_Tile**)((char*)map->map_row_offset + row_offset) + tile_offset);
                int column_count = (int)local_40 - (int)x1 + 1;
                do {
                    RGE_Object_Node* node = tile->objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->object;
                        if (object != this) {
                            RGE_Master_Static_Object* object_master = object->master_obj;
                            float object_dy = object_master->radius_y;
                            float object_dx = object_master->radius_x;
                            if (object_dy > 0.0f && object_dx > 0.0f) {
                                float dz = object->world_z - this->world_z;
                                if (dz >= -(object_master->radius_z - -0.1f) &&
                                    dz <= this->master_obj->radius_z - -0.1f) {
                                    float rx = object->world_x - this->world_x;
                                    float ry = object->world_y - this->world_y;
                                    if (rx < 0.0f) {
                                        rx = -rx;
                                    }
                                    if (ry < 0.0f) {
                                        ry = -ry;
                                    }
                                    rx = rx - (object_dx + dx + extra);
                                    ry = ry - (object_dy + dy + extra);
                                    if (rx <= 0.0f && ry <= 0.0f) {
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
