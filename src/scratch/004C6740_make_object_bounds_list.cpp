// VA: 004C6740 RGE_Static_Object::make_object_bounds_list
// stat_obj.cpp
// FLAGS: /GX
// Attempt log:
// clean reconstruction: restored the stat_obj ownership surface (master
// radii, player/world/map, typed map rows/tiles/object nodes) and the
// decompiler-supported bounds/overlap behavior.  This is the first clean
// candidate; later probes will be recorded below.
// probe layout: corrected RGE_Map's vptr/map/width/height/row-table offsets;
// this moved the map accesses to the proven +8/+C/+8D8C fields.
// probe liveness: cached the other-master x/y radii and used z >= -radius;
// this recovered the original 0x40 frame/859-byte size and fcompp topology.
// probe layout: a typed master-object owner local for the initial radius
// precheck was an emitted-code duplicate; restored direct master ownership.
// negative probes: short-bound declaration/identity reorder and register hint
// were codegen duplicates; splitting the x-sign flag, a saved x-start, and an
// int lower-x home did not improve the structural basin.  A precomputed extent
// pair improved x87 shape but grew the function to 876 bytes, so it was
// restored to the typed inline sums.
// structural retry: moving map/check-list/result declarations before the
// radii was a codegen duplicate.  A row-pointer plus byte-offset tile cursor
// worsened the result to 713 bytes with a 0x3C frame, so it was restored.
// A common positive-radius result path improved shape but lost 33 bytes and
// was restored; an explicit invalid-radius else block was also a duplicate.
// left in scratch: all nine calls and frame/size match, but initial float/local
// homes, coordinate register coloring, and the late x/y FPU schedule remain
// broad positional drift (final validation records the restored metrics).

extern float DAT_00574720;
extern double DAT_00574718;
extern float DAT_00574748;
extern float DAT_0057474c;

class RGE_Static_Object;

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char gap_0D[3];
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
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x2C];
    float radius_x;
    float radius_y;
    float radius_z;
};

struct RGE_Check_Node {
    RGE_Static_Object* node;
    float dx;
    float dy;
    unsigned char flag;
    unsigned char gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;

    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object* object, float dx, float dy,
                  unsigned char flag);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    RGE_Check_List* make_object_bounds_list(float max_dist);
};

RGE_Check_List* RGE_Static_Object::make_object_bounds_list(float max_dist) {
    float radius_x;
    float radius_y;
    short x2;
    short y1;
    short x1;
    short y2;
    RGE_Map* map;
    RGE_Check_List* check_list;
    RGE_Check_List* result;

    radius_x = this->master_obj->radius_x;
    radius_y = this->master_obj->radius_y;
    if (radius_x <= DAT_00574720 || radius_y <= DAT_00574720 ||
        this->master_obj->radius_z <= DAT_00574718) {
        return 0;
    }

    x1 = (short)(this->world_x - DAT_00574748);
    y1 = (short)(this->world_y - DAT_00574748);
    x2 = (short)(this->world_x - DAT_0057474c);
    y2 = (short)(this->world_y - DAT_0057474c);

    map = this->owner->world->map;
    check_list = new RGE_Check_List;
    result = check_list;

    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= map->map_width) {
        x2 = (short)(map->map_width - 1);
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= map->map_height) {
        y2 = (short)(map->map_height - 1);
    }

    if (y1 <= y2) {
        int row = (int)y1;
        int row_count = (int)y2 - (int)y1 + 1;
        do {
            RGE_Tile* tile = map->map_row_offset[row] + (int)x1;
            if (x1 <= x2) {
                int col_count = (int)x2 - (int)x1 + 1;
                do {
                    RGE_Object_Node* object_node = tile->objects.list;
                    while (object_node != 0) {
                        RGE_Static_Object* object = object_node->node;
                        if (object != this) {
                            RGE_Master_Static_Object* object_master =
                                object->master_obj;
                            float object_radius_y = object_master->radius_y;
                            float object_radius_x = object_master->radius_x;
                            if (object_radius_y > DAT_00574720 &&
                                object_radius_x > DAT_00574720) {
                                float z = object->world_z - this->world_z;
                                if (z >= -object_master->radius_z &&
                                    z <= this->master_obj->radius_z) {
                                    float dx = object->world_x - this->world_x;
                                    float dy = object->world_y - this->world_y;
                                    unsigned char flag;

                                    if (dx < DAT_00574720) {
                                        dx = -dx;
                                        flag = 1;
                                    } else {
                                        flag = 0;
                                    }
                                    if (dy < DAT_00574720) {
                                        flag = (unsigned char)(flag + 2);
                                        dy = -dy;
                                    }

                                    dx -= object_radius_x + radius_x;
                                    dy -= object_radius_y + radius_y;
                                    if (dx < max_dist && dy < max_dist &&
                                        (DAT_00574720 <= dy ||
                                         DAT_00574720 <= dx)) {
                                        check_list->add_node(object, dx, dy,
                                                             flag);
                                    }
                                }
                            }
                        }
                        object_node = object_node->next;
                    }
                    ++tile;
                    --col_count;
                } while (col_count != 0);
            }
            ++row;
            --row_count;
        } while (row_count != 0);
    }

    if (check_list->list == 0) {
        if (check_list != 0) {
            check_list->~RGE_Check_List();
            operator delete(check_list);
        }
        result = 0;
    }
    return result;
}
