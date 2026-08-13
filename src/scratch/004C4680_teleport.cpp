// VA: 004C4680 RGE_Static_Object::teleport(float, float, float)
// PDB: stat_obj.cpp:2105-2373
// Attempt log:
// - The packet's initial scratch used a reduced tile-shape switch and helper
//   shims; it was 409 bytes short and had direct add/remove/update calls.
// - Current pass restores the typed RGE world/map/tile/object-list ownership,
//   the 17-case switch, parameter-home coordinate clamps, and vslot D8/DC
//   terrain calls from the executable's original control flow.
// - Canonical typed calls align all 12 call sites and full switch/terrain
//   behavior; natural double-zero comparison improved the FPU shape.
// - Volatile-result and parameter-home/goto diagnostics were rolled back; the
//   remaining structural lead is the original zero-temporary spill and VC5
//   switch block placement (best rebuilt size 1208 vs 1285).
// - Kept one typed result initialized at entry for the early return and switch
//   default; the original zero spill supports this lifetime, but VC5 emitted
//   the same code (no positional gain, edit/resync 45.84%).

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;

extern long __ftol(void);

#define ZERO_F (*(float*)0x574720)
#define ONE_F (*(float*)0x57472C)
#define TILE_EPSILON (*(float*)0x574744)
#define SCREEN_BIAS (*(float*)0x574730)

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    int gap_0C;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
    short number_of_objects;
    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
    RGE_Object_Node* add_node(RGE_Static_Object* object);
};

class RGE_Tile {
public:
    char gap_00[4];
    unsigned char tile_type;                // +0x04
    unsigned char tile_level;               // +0x05
    char gap_06[6];
    RGE_Object_List objects;                // +0x0C
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;                          // +0x08
    int map_height;                         // +0x0C
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;              // +0x8D8C
    char gap_8D90[0x0A];
    short screen_y_scale;                   // +0x8D9A
    short screen_x_scale;                   // +0x8D9C
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;                            // +0x28
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;                   // +0x3C
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x38];
    float radius_z;                          // +0x38
    char gap_3C[0x68 - 0x3C];
    unsigned char movement_type;             // +0x68
};

class RGE_Static_Object_vtable_pad {
public:
#define OBJECT_PAD(n) virtual void object_pad##n();
    OBJECT_PAD(00) OBJECT_PAD(04) OBJECT_PAD(08) OBJECT_PAD(0C)
    OBJECT_PAD(10) OBJECT_PAD(14) OBJECT_PAD(18) OBJECT_PAD(1C)
    OBJECT_PAD(20) OBJECT_PAD(24) OBJECT_PAD(28) OBJECT_PAD(2C)
    OBJECT_PAD(30)
#undef OBJECT_PAD
};

class RGE_Static_Object : public RGE_Static_Object_vtable_pad {
public:
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Static_Object* sprite);
#define OBJECT_PAD2(n) virtual void object_pad2_##n();
    OBJECT_PAD2(00) OBJECT_PAD2(01) OBJECT_PAD2(02) OBJECT_PAD2(03)
    OBJECT_PAD2(04) OBJECT_PAD2(05) OBJECT_PAD2(06) OBJECT_PAD2(07)
    OBJECT_PAD2(08) OBJECT_PAD2(09) OBJECT_PAD2(10) OBJECT_PAD2(11)
    OBJECT_PAD2(12) OBJECT_PAD2(13) OBJECT_PAD2(14) OBJECT_PAD2(15)
    OBJECT_PAD2(16) OBJECT_PAD2(17) OBJECT_PAD2(18) OBJECT_PAD2(19)
    OBJECT_PAD2(20) OBJECT_PAD2(21) OBJECT_PAD2(22) OBJECT_PAD2(23)
    OBJECT_PAD2(24) OBJECT_PAD2(25) OBJECT_PAD2(26) OBJECT_PAD2(27)
    OBJECT_PAD2(28) OBJECT_PAD2(29) OBJECT_PAD2(30) OBJECT_PAD2(31)
    OBJECT_PAD2(32) OBJECT_PAD2(33) OBJECT_PAD2(34) OBJECT_PAD2(35)
    OBJECT_PAD2(36) OBJECT_PAD2(37) OBJECT_PAD2(38)
#undef OBJECT_PAD2
    virtual int explore_terrain(RGE_Player* player, unsigned char mode, int value);
    virtual void unexplore_terrain(RGE_Player* player, unsigned char mode, int value);

    long id;                                  // +0x04
    RGE_Master_Static_Object* master_obj;     // +0x08
    RGE_Player* owner;                        // +0x0C
    void* sprite;                             // +0x10
    void* old_sprite;                         // +0x14
    void* sprite_list;                        // +0x18
    RGE_Tile* tile;                           // +0x1C
    RGE_Static_Object* inside_obj;            // +0x20
    RGE_Object_List* objects;                 // +0x24
    short screen_x_offset;                    // +0x28
    short screen_y_offset;                    // +0x2A
    short shadow_x_offset;                    // +0x2C
    short shadow_y_offset;                    // +0x2E
    float hp;                                  // +0x30
    unsigned char curr_damage_percent;        // +0x34
    unsigned char facet;                      // +0x35
    unsigned char selected;                   // +0x36
    unsigned char selected_group;             // +0x37
    float world_x;                            // +0x38
    float world_y;                            // +0x3C
    float world_z;                            // +0x40
    float attribute_amount_held;              // +0x44
    unsigned char object_state;               // +0x48
    unsigned char sleep_flag;                 // +0x49
    unsigned char dopple_flag;                // +0x4A
    unsigned char goto_sleep_flag;            // +0x4B
    short attribute_type_held;                // +0x4C
    unsigned char type;                       // +0x4E
    unsigned char worker_num;                 // +0x4F
    RGE_Object_Node* player_object_node;      // +0x50
    char gap_54[0x34];

    int removeFromObstructionMap(int mode);
    int addToObstructionMap(int mode);
};

float RGE_Static_Object::teleport(float param_1, float param_2, float param_3) {
    float result;
    RGE_Map* map;
    float rx;
    float rz;
    int tx;
    int ty;
    RGE_Tile* new_tile;
    result = ZERO_F;
    map = this->owner->world->map;
    if (this->inside_obj != 0) {
        return result;
    }

    if (0.0 < this->master_obj->radius_z) {
        this->removeFromObstructionMap(2);
    }

    if (param_1 < 0.0f) {
        param_1 = 0.0f;
    }
    tx = map->map_width;
    if ((float)tx <= param_1) {
        param_1 = (float)tx - TILE_EPSILON;
    }
    if (param_2 < 0.0f) {
        param_2 = 0.0f;
    }
    ty = map->map_height;
    if ((float)ty <= param_2) {
        param_2 = (float)ty - TILE_EPSILON;
    }

    tx = (int)param_1;
    ty = (int)param_2;
    rx = param_1 - (float)tx;
    rz = param_2 - (float)ty;
    if (tx < map->map_width) {
        if (tx < 0) {
            tx = 0;
        }
    } else {
        tx = map->map_width - 1;
    }
    if (ty < map->map_height) {
        if (ty < 0) {
            ty = 0;
        }
    } else {
        ty = map->map_height - 1;
    }

    new_tile = map->map_row_offset[ty] + tx;
    if (new_tile == this->tile || this->inside_obj != 0) {
        this->world_x = param_1;
        this->world_y = param_2;
        this->world_z = param_3;
    } else {
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
        }
        new_tile->objects.add_node(this);
        if (this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
        }
        this->world_z = param_3;
        this->world_x = param_1;
        this->world_y = param_2;
        this->tile = new_tile;
        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }
    }

    if (0.0 < this->master_obj->radius_z) {
        this->addToObstructionMap(2);
    }

    switch (new_tile->tile_type) {
    case 1:
        if (rx + rz < ONE_F) {
            result = rz;
        } else {
            result = 1.0f - rx;
        }
        break;
    case 2:
        if (rx + rz < ONE_F) {
            result = rx;
        } else {
            result = 1.0f - rz;
        }
        break;
    case 3:
        if (rx <= rz) {
            result = 1.0f - rz;
        } else {
            result = 1.0f - rx;
        }
        break;
    case 4:
        if (rx <= rz) {
            result = rx;
        } else {
            result = rz;
        }
        break;
    case 5:
        result = 1.0f - rx;
        break;
    case 6:
        result = 1.0f - rz;
        break;
    case 7:
        result = rz;
        break;
    case 8:
        result = rx;
        break;
    case 9:
        if (rx - rz < 0.0f) {
            result = -(rx - rz);
        } else {
            result = 0.0f;
        }
        break;
    case 10:
        result = rx - rz;
        if (result <= 0.0f) {
            result = 0.0f;
        }
        break;
    case 11:
        if (rx + rz < 1.0f) {
            result = 1.0f - (rx + rz);
        } else {
            result = 0.0f;
        }
        break;
    case 12:
        if (1.0f < rx + rz) {
            result = (rx + rz) - 1.0f;
        } else {
            result = 0.0f;
        }
        break;
    case 0:
        result = 0.0f;
        break;
    case 13:
        if (1.0f <= rx + rz) {
            result = rz;
        } else {
            result = 1.0f - rx;
        }
        break;
    case 14:
        if (1.0f <= rx + rz) {
            result = rx;
        } else {
            result = 1.0f - rz;
        }
        break;
    case 15:
        if (rx <= rz) {
            result = rz;
        } else {
            result = rx;
        }
        break;
    case 16:
        if (rx <= rz) {
            result = 1.0f - rx;
        } else {
            result = 1.0f - rz;
        }
        break;
    default:
        result = 0.0f;
        break;
    }

    RGE_Master_Static_Object* master = this->master_obj;
    unsigned char movement = master->movement_type;
    result += (float)(new_tile->tile_level >> 5);
    if (movement == 0 || (movement == 1 && this->world_z < result)) {
        this->world_z = result;
    }

    this->screen_x_offset = (short)((rx + rz) * map->screen_x_scale);
    this->screen_y_offset = (short)((result + rx - SCREEN_BIAS - rz - this->world_z) * map->screen_y_scale);

    if (movement == 0) {
        this->shadow_x_offset = this->screen_x_offset;
        this->shadow_y_offset = this->screen_y_offset;
    } else if (movement == 1) {
        this->shadow_x_offset = (short)((rx + rz) * map->screen_x_scale);
        this->shadow_y_offset = (short)((result - rz) * map->screen_y_scale);
    }
    return result;
}
