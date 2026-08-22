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
// The original call pushes the second tile coordinate first; testing the
// source-level get_terrain(row,col) order against the map_row_offset[col][row]
// ownership is the next structural lead.
// The tile's +0x10 access is the list member of its inline RGE_Object_List,
// not an independently owned pointer; the nested typed surface is now tested.
// The oracle has one initial null guard and a bottom-tested shared tail; test
// the natural positive if/do-while form instead of a top-tested while.
// The placement arm reuses the master pointer loaded for the ID test; retain a
// named local so that this proven cross-branch lifetime can be tested directly.
// This worker's get_terrain(row,col) order moved the mismatch 334 -> 332 bytes;
// current-node/master locals, declaration order, and the inline list surface
// were emitted-code duplicates.  Delayed result initialization worsened the
// result, while an int accumulator was only a one-byte diagnostic improvement;
// the period-plausible short result is retained.  A single guarded while scan
// collapsed two required removal call sites and emitted 301 bytes, so the
// nested if/do scan was restored.  Final current candidate is 356 bytes with
// all seven call targets aligned; the 35-byte prologue/register and scan gap
// remains a structural blocker for this assignment.
// sa-e790ae6f-r1 probe 22: restore the period class declaration context that
// the local source lacked: RGE_Static_Object virtuals after destroy_obj and
// the complete RGE_Map virtual/nonvirtual prefix.  A 128-variant lab found
// this supported surface changes the target basin from 356 to 349 bytes,
// while preserving all seven call targets.  The added methods do not change
// any proven field offset.
//
// sa-0ba55ae7 pass: baseline check confirmed 356 bytes, 7/7 ordered calls,
// no frame, and 332 differing bytes.  Direct object/master expressions,
// adjacent create_terrain_object declaration order, result width and init
// placement, complete map virtual context, register hints, and a named tile
// pointer were all codegen duplicates.  The inner guarded while scan removed
// two required call sites and was restored.  The clean typed reconstruction
// remains unresolved; the next useful evidence is a compiler-basin donor or
// source declaration proof for the target EBX map and EBP result allocation.
//
// sa-4633c59f-r1 revisit: the pinned source remains the clean 356-byte basin.
// A placement-only current_node->node reload reproduced four late exact blocks
// but merged one earlier cleanup call, yielding 346 bytes and 6 calls.  Scoping
// or removing the object alias merged more cleanup calls.  Direct master-id
// use, cleanup-polarity reversal, declaration reordering, and swapping the
// active/next node locals were duplicates or worse.  Restore the typed source
// until a period declaration or compiler-basin donor explains the EBX/EBP
// allocation and the target's separate cleanup sites.

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

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_0A[0x2];
};

class RGE_Tile {
public:
    char gap_00[0xC];
    RGE_Object_List objects;
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
    virtual void die_die_die();
    virtual void damage(int amount, void* armor, float value, RGE_Player* player,
                        RGE_Static_Object* object);
    virtual float calculateDamage(int amount, void* armor, float value,
                                  RGE_Player* player, RGE_Static_Object* object);
    virtual void rotate(long angle);
    virtual unsigned char can_attack();
    virtual void set_attribute(short type, float value);
    virtual void set_attribute_amount(float value, unsigned char a,
                                      unsigned char b);
    virtual int heal(int amount, int type);
    virtual unsigned char heal_float(float amount);
    virtual int canRepair();
    virtual void notify_of_relation(long relation, unsigned char flag);

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
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char do_terrain_brush(long x, long y, long radius,
                                           unsigned char terrain);
    virtual unsigned char do_terrain_brush_stroke(long x0, long y0, long x1,
                                                  long y1, long radius,
                                                  unsigned char terrain);
    virtual unsigned char do_elevation_brush(long x, long y, long radius,
                                              unsigned char elevation);
    virtual unsigned char do_elevation_brush_stroke(long x0, long y0, long x1,
                                                    long y1, long radius,
                                                    unsigned char elevation);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                         unsigned char b);
    virtual unsigned char do_cliff_brush_stroke(long x0, long y0, long x1,
                                                long y1, unsigned char a,
                                                unsigned char b);
    virtual void map_generate(RGE_Player* player, RGE_Game_World* world,
                              void* info, unsigned char* data);
    virtual void map_generate2(RGE_Game_World* world, long a, long b,
                               unsigned char c, long d);
    virtual void save(int file);
    char gap_04[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    RGE_Tile** map_row_offset;

    void load_map(int file);
    void init_tile_sizes();
    void set_tile_size(unsigned char index, short width, short height,
                       short delta);
    void load_terrain_types(void* sounds);
    void load_border_types(void* sounds);
    void new_map(long width, long height);
    RGE_Tile* get_tile(int col, int row);
    long get_map_width();
    long get_map_height();
    RGE_Tile** give_up_map_offsets();
    void get_point(short* a, short* b, float c, float d, float e,
                   short f, short g);
    void tile_map_coords(short a, short b, RGE_Tile* tile, float* c, float* d);
    unsigned char check_map_coords(short col, short row);
    void set_map_screen_pos(int a, int b, int c, int d);
    void clear_map(void* player, RGE_Game_World* world,
                   unsigned char terrain, long width, long height);
    void scenario_save(int file);
    void scenario_load(int file, unsigned char* data);
    void save_map(int file);
    void set_terrain(void* player, RGE_Game_World* world, short col,
                     short row, unsigned char terrain, unsigned char a,
                     unsigned char b);
    void set_terrain_absolute(RGE_Game_World* world, short col, short row,
                              unsigned char terrain, int a, int b);
    void place_terrain_object(void* player, RGE_Game_World* world, short row,
                              short col, int object_id, int single);
    void create_terrain_objects(void* player, RGE_Game_World* world);
    unsigned char get_tile_type(short col, short row);
    void rebuild_tile_types(short a, short b, short c, short d);
    void rebuild_border_types(short a, short b, short c, short d);
    unsigned char get_border_type(short col, short row);
    void clean_borders(long a, long b, long c, long d);
    void delete_objects_on_tile(void* player, RGE_Game_World* world,
                                int a, int b, int c, int d);
    void delete_all_objects_on_tile(int a, int b);
    void update(unsigned long time);
    void load_terrain_obj_types(char* file);
    void create_terrain_object(void* player, RGE_Game_World* world,
                               short row, short col, short terrain,
                               int remove_now, int min_id, int max_id);

    unsigned char get_terrain(short row, short col);
    int clear_terrain_object(RGE_Game_World* world, short col, short row,
                             short old_terrain, int remove_now,
                             int min_id, int max_id);
};

int RGE_Map::clear_terrain_object(RGE_Game_World* world, short col,
                                  short row, short old_terrain,
                                  int remove_now, int min_id, int max_id)
{
    short object_id;
    RGE_Object_Node* node;
    RGE_Object_Node* current_node;
    short result = -1;
    short object_type;
    RGE_Static_Object* object;
    RGE_Master_Static_Object* master_obj;

    get_terrain(row, col);
    node = this->map_row_offset[col][row].objects.list;

    if (node != 0) {
        do {
            current_node = node;
            object = current_node->node;
            node = current_node->next;
            master_obj = object->master_obj;
            object_id = master_obj->id;

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

        if (master_obj->check_placement(
                object->owner, object->world_x, object->world_y, 0,
                0, 1, 1, 1, 0, 0)) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
        }
        } while (node != 0);
    }

    return result;
}
