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
// Probes 1-21 tested canonical row/col ownership, positive and nested CFG
// forms, explicit tail labels, result widths and init sites, direct versus
// named master/object aliases, register hints, cleanup polarity, node and
// result scopes, late placement reloads, and split cleanup labels.  The
// 347-byte full-context source below is the best clean all-call basin; the
// late-reload and label variants lost a required call site.
// sa-e790ae6f-r1 probe 24: combine the full period class context with the
// decompiler-proven result declaration after the tile-list load.  The lab
// produced a 347-byte, seven-call basin with 11.97% exact blocks.
// sa-e790ae6f-r1 probe 25: remove the iteration-local master alias from the
// improved basin and use direct typed object->master_obj expressions.  The
// Ghidra source names only the object pointer, so this tests owner spelling.
// Probes 26-30: early-null return, late scan-local scope, iteration-local
// object/current-node aliases, and top-tested while were tested.  They either
// worsened shape or emitted the same 347-byte basin.  Keep the simple loop.
// sa-e790ae6f-r1 probe 31: restore the reviewed RGE_Object_List method
// surface, including its real virtual load slot, while preserving the proven
// 0xC layout.  This tests nested list class context omitted by the prior basin.
// sa-e790ae6f-r1 probe 32: replace the guarded reverse do loop with the
// decompiler's short-circuit while predicate.  The target has one initial
// sign test and a bottom backedge; test this exact source topology.
// sa-e790ae6f-r1 probe 33: split the while guard from the table predicate:
// while (object_type >= 0) { if (match) break; --object_type; }.  This keeps
// the target's explicit comparison while avoiding the short-circuit lowering
// that removed two cleanup call sites.
// sa-e790ae6f-r1 probe 27: move object_type next to the late result
// declaration in the full-context basin.  This tests scan-local scope against
// the target's AX induction value.
// sa-e790ae6f-r1 probe 28: move the object declaration into the node-loop
// iteration.  This tests whether the target ECX receiver is an iteration-local
// value rather than a function-scope pointer.
// sa-e790ae6f-r1 probe 29: make current_node iteration-local as well, matching
// the decompiler's pRVar3 assignment inside the scan.  Test its interaction
// with the improved full-context source.
// sa-e790ae6f-r1 probe 30: use a top-tested while(node) scan with the same
// object/next update order.  This tests loop rotation against the target's
// initial guard and bottom shared tail.
// Probe 26: use the early node-null return with the improved full-context and
// late-result source.  The Ghidra listing shows this initial guard explicitly.
// sa-e790ae6f-r1 probe 23: make the master pointer a const, iteration-local
// alias.  The target carries one master value in EDI from ID load through the
// placement call; this tests whether scope and constness preserve that value.
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

// sa-18f9837d-r1 finish: the period map.cpp header surface and the complete
// RGE_Tile_Set terrain layout from exact 00458600 were restored.  They preserve
// all proven offsets and keep the 347-byte, seven-call natural basin.
// Short-circuit terrain scans and placement-node reloads moved registers closer
// but merged a required cleanup call.  Explicit cleanup labels also worsened
// the call graph.  Those forms were discarded.  The remaining gap is the
// source lifetime that selects the original EBX/EBP/ESI/EDI allocation.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MAP_CONTEXT_H
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
    virtual void load(unsigned char flag, int file, RGE_Game_World* world);
    void removeAllObjects();
    void rehook_list();
    void update();
    void draw(void* area, short x, short y, unsigned char flag);
    void shadow_draw(void* area, short x, short y, unsigned char a,
                     unsigned char b);
    void normal_draw(void* area, short x, short y, unsigned char flag);
    RGE_Object_Node* sort();
    RGE_Static_Object* find_by_group(long group);
    RGE_Object_Node* add_node(RGE_Static_Object* object);
    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
    RGE_Static_Object* find_by_id(long id);
    void save(int file);
    void load_list(int file, RGE_Game_World* world);
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
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                     float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
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

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    void* shape;
    void* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
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

#endif

int RGE_Map::clear_terrain_object(RGE_Game_World* world, short col,
                                  short row, short old_terrain,
                                  int remove_now, int min_id, int max_id)
{
    short object_id;
    RGE_Object_Node* node;
    RGE_Object_Node* current_node;
    short object_type;
    RGE_Static_Object* object;

    get_terrain(row, col);
    node = this->map_row_offset[col][row].objects.list;
    short result = -1;

    while (node != 0) {
            current_node = node;
            object = current_node->node;
            node = current_node->next;
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
