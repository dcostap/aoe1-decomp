// VA: 00458B40 RGE_Map::clear_terrain_object
// map.cpp lines 2096-2162
//
// Walk the object list attached to a tile.  Objects inside the caller's ID
// range are retained; out-of-range objects are removed when they belong to
// the old terrain, or when the master placement test says they should go.
// The remove_now flag selects virtual deletion versus destroy_obj().
//
// Attempt log:
// - Baseline reconstruction uses named RGE_Map terrain/object ownership,
//   typed virtual destructor/destroy surfaces, and a natural node scan.
// - Collapsing the transient node alias, moving the result declaration, and
//   capturing `this` as a map local were codegen duplicates.  A guarded-while
//   object-type scan lost the two removal call sites and was restored.
// - The proven col,row signature/row-offset ownership is retained; it is also
//   a codegen duplicate.  The best clean candidate remains broad (356 emitted
//   bytes versus 321), with all seven call targets aligned but wrong prologue,
//   register coloring, and object-type scan topology.
// Main-agent audit restored canonical polymorphic map ownership and retained
// the ordinary typed tile-object scan and destruction paths.
// Current worker: a named master_obj, object-before-node declaration order,
// and a for-loop node increment were separately tested; the first two were
// emitted-code duplicates and the for form widened the body to 358 bytes.
// Restored the clean natural scan; the original 321-byte prologue/register
// topology remains unresolved.

class RGE_Game_World;
class RGE_Player;
class RGE_Tile;
class RGE_Object_Node;
class RGE_Static_Object;
class RGE_Master_Static_Object;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x10];
    RGE_Object_Node* objects;
    char gap_14[0x4];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void destroy_obj();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* other);
    virtual void modify(float value, unsigned char flag);
    virtual void modify_delta(float value, unsigned char flag);
    virtual void modify_percent(float value, unsigned char flag);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                            float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player* owner, float x, float y, int* value,
        unsigned char a, unsigned char b, unsigned char c,
        unsigned char d, unsigned char e, unsigned char f);

    char gap_04[0xC];
    short id;
};

class RGE_Tile_Set {
public:
    char gap_00[0xFE];
    short obj_types[30];
    char gap_13A[0x5A];
    short num_obj_type;
    char gap_196[0x2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    RGE_Tile** map_row_offset;

    unsigned char get_terrain(short row, short col);
    int clear_terrain_object(RGE_Game_World* world, short col, short row,
                             short old_terrain, int remove_now,
                             int min_id, int max_id);
};

int RGE_Map::clear_terrain_object(RGE_Game_World* world, short col,
                                  short row, short old_terrain,
                                  int remove_now, int min_id, int max_id)
{
    short result = -1;
    RGE_Object_Node* node;
    RGE_Static_Object* object;
    short object_id;
    short object_type;

    get_terrain(col, row);
    node = this->map_row_offset[col][row].objects;

    while (node != 0) {
        object = node->node;
        node = node->next;
        object_id = object->master_obj->id;

        if (object_id >= min_id && object_id <= max_id)
            continue;

        if (old_terrain < 0) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
            continue;
        }

        result = object_id;
        object_type = this->terrain_types[old_terrain].num_obj_type;
        if (object_type >= 0) {
            do {
                if (this->terrain_types[old_terrain].obj_types[object_type] ==
                    object_id)
                    break;
                --object_type;
            } while (object_type >= 0);
        }

        if (object_type >= 0) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
            continue;
        }

        if (object->master_obj->check_placement(
                object->owner, object->world_x, object->world_y, 0,
                0, 1, 1, 1, 0, 0)) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
        }
    }

    return result;
}
