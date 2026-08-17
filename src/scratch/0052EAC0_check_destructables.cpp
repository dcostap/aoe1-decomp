// VA: 0052EAC0 TRIBE_World::check_destructables (560 B)
// PDB source: tworld.cpp
// Packet-grounded: inspect nearby master objects and notify/destruct objects
// whose bounding radii overlap the requested map coordinate.
// Attempt log:
// - Recovered typed ownership: world->players[short] -> master_objects,
//   RGE_Map rows of 0x18-byte RGE_Tile records, inline tile object lists, and
//   RGE_Static_Object/master radius fields.  All six oracle calls are aligned.
// - Short coordinate locals reproduce the word clamps and four __ftol calls.
//   The typed row/tile do-while preserves the natural object-list traversal.
// - A direct row index plus the known 0x18-byte tile stride is closer than a
//   cached row pointer. Raw byte cursors and parameter-home mutation are not
//   retained because policy forbids them.
// - Naming both real object radius fields before coordinate math, then using a
//   combined overlap predicate, reaches 560 B/frame 0x20 and 81.42% shape.
//   It also raises exact-block coverage to 43.43% with all six calls aligned.
// - The pre-audit clean candidate was still a mismatch: 309 strict bytes
//   differed, with 183 rebuilt instructions versus 175 original instructions.
//   Its first mismatch was the natural world-pointer local at the prologue.
// - World/map aliases and alternate radius operand directions were tested and
//   discarded when they worsened or did not change the natural code shape.
// - Canonical class-dump audit: replaced the world/object/list vfXX surfaces
//   with their reviewed names and signatures, retained TRIBE_World inheritance,
//   and used the canonical RGE_Tile/RGE_Object_Node fields.
// - The row walk now uses map_row_offset[row_index] + x_min.  It does not use
//   a raw byte cursor.  The notification call uses destroy_obj at vslot +0x68.
// - This pass remains non-exact: 530 strict bytes differ and the rebuilt body
//   is 543 bytes.  The canonical audit changed the compiler basin, but all six
//   calls and the typed traversal remain aligned.

class RGE_Map;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Object_Node;
class RGE_Player_Info;
class RGE_Sound;
class RGE_Scenario;
class TSound_Driver;
class TCommunications_Handler;
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;

typedef void FILE;

class RGE_Object_List {
public:
    virtual void load(unsigned char load_flag, int file, RGE_Game_World* world);
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char border_type : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* map_name, char* map_type,
                                 char* map_size, char* map_info);
    virtual unsigned char do_terrain_brush(long x, long y, long terrain,
                                           unsigned char flag);
    virtual unsigned char do_terrain_brush_stroke(
        long x1, long y1, long x2, long y2, long terrain,
        unsigned char flag);
    virtual unsigned char do_elevation_brush(long x, long y, long elevation,
                                             unsigned char flag);
    virtual unsigned char do_elevation_brush_stroke(
        long x1, long y1, long x2, long y2, long elevation,
        unsigned char flag);
    virtual unsigned char do_cliff_brush(long x, long y,
                                         unsigned char cliff,
                                         unsigned char flag);
    virtual unsigned char do_cliff_brush_stroke(
        long x1, long y1, long x2, long y2, unsigned char cliff,
        unsigned char flag);
    virtual void map_generate(RGE_Player* player, RGE_Game_World* world,
                              RGE_Player_Info* info, unsigned char* data);
    virtual void map_generate2(RGE_Game_World* world, long x, long y,
                               unsigned char flag, long seed);
    virtual void save(int file);

    RGE_Tile* map;                 // +0x04
    long map_width;                // +0x08
    long map_height;               // +0x0C
    long world_width;              // +0x10
    long world_height;             // +0x14
    char gap_18[0x8D74];
    RGE_Tile** map_row_offset;     // +0x8D8C
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* file);
    virtual unsigned char data_load_players(char* file);
    virtual unsigned char data_load_objects(char* file);
    virtual unsigned char data_load_sounds(char* file);
    virtual unsigned char data_load_color_tables(char* file);
    virtual unsigned char data_load_sprites(char* file);
    virtual void data_load_players_type(short player, short type, FILE* file);
    virtual void data_load_effects(char* file);
    virtual void data_load_map(char* map_name, char* map_type, char* map_size,
                               char* map_info, short width, short height,
                               short terrain, RGE_Sound** sounds,
                               char* filename);
    virtual void data_load_random_map(char* map_name, char* map_type,
                                      char* map_size, char* map_info);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char flag);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short player_id);
    virtual void color_table_init(int count);
    virtual void terrain_tables_init(int count);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count, TSound_Driver* driver);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, TCommunications_Handler* handler);
    virtual void world_init(int count, TSound_Driver* driver,
                            TCommunications_Handler* handler);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info* info);
    virtual unsigned char new_random_game(RGE_Player_Info* info);
    virtual void save(int file);
    virtual void scenario_make_player(short player, unsigned char master_id,
                                      unsigned char type, unsigned char civ,
                                      char* info);
    virtual void scenario_make_map(int file);
    virtual unsigned char load_scenario(RGE_Player_Info* info);
    virtual unsigned char load_scenario(char* file, RGE_Player_Info* info);
    virtual void load_scenario1(int file, RGE_Player_Info* info);
    virtual void load_scenario2(int file, RGE_Player_Info* info);
    virtual void load_scenario3(int file, RGE_Player_Info* info);
    virtual void load_scenario4(int file, RGE_Player_Info* info);
    virtual void load_scenario5(int file, RGE_Player_Info* info);
    virtual void load_scenario6(int file, RGE_Player_Info* info);
    virtual void load_scenario7(int file, RGE_Player_Info* info);
    virtual void load_scenario8(int file, RGE_Player_Info* info);
    virtual void logStatus(FILE* file, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* info);
    virtual unsigned char data_load(char* file, char* info);
    virtual unsigned char init(char* file, TSound_Driver* driver,
                               TCommunications_Handler* handler);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int file);
    virtual unsigned char load_game(char* file);
    virtual unsigned char new_game(RGE_Player_Info* info, int file);
    virtual unsigned char new_scenario(RGE_Player_Info* info, int file);
    virtual unsigned char save_game(char* file);
    virtual void base_save(char* file);
    virtual void base_save(int file);
    virtual unsigned char save_scenario(char* file);
    virtual RGE_Scenario* get_scenario_info(char* file);
    virtual void pause(unsigned char flag);
    virtual void scenario_init(RGE_Game_World* world);
    virtual void scenario_init(int file, RGE_Game_World* world);
    virtual int addObject(RGE_Static_Object* object);
    virtual int removeObject(int id);
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
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    char gap_0D[3];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();     // deleting destructor at vslot +0x00
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors);
    virtual void shadow_draw(TDrawArea* area, short x, short y,
                             unsigned char flag);
    virtual void normal_draw(TDrawArea* area, short x, short y);
    virtual void draw_front_frame(TDrawArea* area, short x, short y);
    virtual void draw_back_frame(TDrawArea* area, short x, short y);
    virtual void draw_frame(TDrawArea* area, short x, short y);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int file);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void add_overlay_sprite(RGE_Sprite* sprite, unsigned char flag);
    virtual void remove_overlay_sprite(RGE_Sprite* sprite);
    virtual void change_ownership(RGE_Player* player);
    virtual void modify(float amount, unsigned char attribute);
    virtual void modify_delta(float amount, unsigned char attribute);
    virtual void modify_percent(float amount, unsigned char attribute);
    virtual void transform(RGE_Master_Static_Object* master);
    virtual void copy_obj(RGE_Master_Static_Object* master);
    virtual void set_object_state(unsigned char state);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();           // vslot +0x68

    long id;                             // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                   // +0x0C
    char gap_10[0x28];
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
                int row_index = y_min;
                int row_count = (int)y_max - (int)y_min + 1;
                int column_count = (int)x_max - (int)x_min + 1;
                do {
                    if (x_min <= x_max) {
                        RGE_Tile* tile =
                            this->map->map_row_offset[row_index] + x_min;
                        int columns = column_count;
                        do {
                            RGE_Object_Node* node = tile->objects.list;
                            while (node != 0) {
                                RGE_Static_Object* object = node->node;
                                node = node->next;
                                RGE_Master_Static_Object* object_master = object->master_obj;

                                if (object_master->id != target_master_id &&
                                    object_master->can_be_built_on != 0) {
                                    float object_radius_x = object_master->radius_x;
                                    float object_radius_y = object_master->radius_y;
                                    float dy = object->world_y - y;
                                    float dx = object->world_x - x;
                                    if (dy < 0.0f)
                                        dy = -dy;
                                    if (dx < 0.0f)
                                        dx = -dx;

                                    if (dx < object_radius_x + radius_x &&
                                        dy < object_radius_y + radius_y) {
                                        if (flag != 0) {
                                            if (object != 0)
                                                delete object;
                                        } else {
                                            object->destroy_obj();
                                        }
                                    }
                                }
                            }
                            ++tile;
                            --columns;
                        } while (columns != 0);
                    }
                    ++row_index;
                    --row_count;
                } while (row_count != 0);
            }
        }
    }
}
