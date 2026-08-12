// VA: 0052EAC0 TRIBE_World::check_destructables (560 B)
// PDB source: tworld.cpp
// Packet-grounded: inspect nearby master objects and notify/destruct objects
// whose bounding radii overlap the requested map coordinate.
// Attempt log:
// - Recovered typed ownership: world->players[short] -> master_objects,
//   RGE_Map rows of 0x18-byte RGE_Tile records, inline tile object lists, and
//   RGE_Static_Object/master radius fields.  All six oracle calls are aligned.
// - Short coordinate locals and named master radius locals reproduce the
//   oracle's word clamps, four __ftol conversions, and x87 overlap predicate.
// - A typed row/tile do-while is retained as the clean source.  Raw row-table
//   byte-cursor and explicit world-alias variants were diagnostic only and
//   regressed or were codegen-neutral; no opaque cursor survives here.
// - Sequential pass probes: moving the horizontal-range gate inside the outer
//   row loop recovered the oracle's per-row branch and raised the candidate to
//   523 B/frame 0x18; an explicit x_min*0x18 tile offset improved block coverage
//   without changing size.  Direct parameter-home mutation changed register
//   coloring but was not kept; the final source uses named short bounds and a
//   saved master id, while preserving the proven inner gate and tile offset.
// - A volatile late radius-y home reached frame 0x1c/535 B but worsened shape;
//   it was removed as codegen-only.  The final canonical candidate is 522 B,
//   frame 0x18, six aligned calls, and 20.57% exact-block coverage.
// - Left in scratch: rebuilt 522B/frame 0x18 versus oracle 560B/frame 0x20;
//   remaining drift is structural local/parameter-home and register topology
//   around the late tile-list loops, despite exact call set/CFG counts.
// - Sequential TU pass: a combined overlap predicate and scoped world owners
//   were neutral. Reordering the inner countdown regressed the loop schedule.
//   Naming both object radii before coordinate math follows the oracle's early
//   radius-y load and reaches 538B/frame 0x1c, but leaves the same structural
//   prologue gap. Map aliases and a world reference changed no useful topology;
//   direct typed map access remains the clean source form.
// - Main-agent audit rolled back the radius-preload diagnostic. It changed no
//   behavior evidence and was compiler steering, not plausible source recovery.

class RGE_Map;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Object_Node;

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short count;
    char gap_0A[2];
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char gap_06[6];
    RGE_Object_List objects;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;                 // +0x08
    int map_height;                // +0x0C
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;     // +0x8D8C
};

class RGE_Game_World {
public:
    virtual void vf00();
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
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual ~RGE_Game_World();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    char gap_04[0x24];
    RGE_Map* map;                  // +0x28
    char gap_2C[0x14];
    RGE_Player** players;          // +0x40
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                      // +0x10
    char gap_12[0x1E];
    float radius_x;                // +0x30
    float radius_y;                // +0x34
    char gap_38[0x13];
    unsigned char can_be_built_on; // +0x4B
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();     // deleting destructor at vslot +0x00
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
    virtual void vf68();           // vslot +0x68

    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x;                 // +0x38
    float world_y;                 // +0x3C
};

class TRIBE_World : public RGE_Game_World {
public:
    void check_destructables(short player_id, short master_id,
                             float x, float y, unsigned char flag);
};

void TRIBE_World::check_destructables(short player_id, short master_id,
                                      float x, float y, unsigned char flag)
{
    short target_master_id = master_id;
    RGE_Master_Static_Object* master =
        this->players[player_id]->master_objects[master_id];

    if (master != 0) {
        float radius_x = master->radius_x;
        float radius_y = master->radius_y;
        if (radius_x > 0.0f || radius_y > 0.0f) {
            short x_min = (short)(x - 0.5f);
            short y_min = (short)(y - 0.5f);
            short x_max = (short)(x + 0.5f);
            short y_max = (short)(y + 0.5f);
            if (x_min < 0)
                x_min = 0;
            if (x_max >= this->map->map_width)
                x_max = (short)(this->map->map_width - 1);
            if (y_min < 0)
                y_min = 0;
            if (y_max >= this->map->map_height)
                y_max = this->map->map_height - 1;

            if (y_min <= y_max) {
                RGE_Tile** row_ptr = this->map->map_row_offset + y_min;
                int row_count = (int)y_max - (int)y_min + 1;
                int column_count = (int)x_max - (int)x_min + 1;
                int tile_offset = (int)x_min * (int)sizeof(RGE_Tile);
                do {
                    if (x_min <= x_max) {
                        RGE_Tile* tile =
                            (RGE_Tile*)((char*)*row_ptr + tile_offset);
                        int columns = column_count;
                        do {
                            RGE_Object_Node* node = tile->objects.list;
                            while (node != 0) {
                                RGE_Static_Object* object = node->object;
                                node = node->next;
                                RGE_Master_Static_Object* object_master = object->master_obj;

                                if (object_master->id != target_master_id &&
                                    object_master->can_be_built_on != 0) {
                                    float dy = object->world_y - y;
                                    float dx = object->world_x - x;
                                    if (dy < 0.0f)
                                        dy = -dy;
                                    if (dx < 0.0f)
                                        dx = -dx;

                                    if (dx < object_master->radius_x + radius_x) {
                                        float object_radius_y = object_master->radius_y;
                                        if (dy < object_radius_y + radius_y) {
                                            if (flag != 0) {
                                                if (object != 0)
                                                    delete object;
                                            } else {
                                                object->vf68();
                                            }
                                        }
                                    }
                                }
                            }
                            ++tile;
                            --columns;
                        } while (columns != 0);
                    }
                    ++row_ptr;
                    --row_count;
                } while (row_count != 0);
            }
        }
    }
}
