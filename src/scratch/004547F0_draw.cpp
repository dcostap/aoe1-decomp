// VA: 004547F0 RGE_Master_Static_Object::draw (348 bytes)
// m_s_obj.cpp:1126-1147
//
// Baseline reconstruction: draw the master sprite, then project the four
// outline corners into the clipping list when outline capture is requested.
// Attempt log:
// - Baseline reaches exact size/frame and all six ordered direct calls; the
//   remaining 314 differing bytes begin in the prologue.
// - Receiver-alias, split-sprite-fetch, scoped-lifetime, early-return, and
//   reduced-virtual-surface probes all emitted the same 348-byte basin (the
//   rebuilt function saves ESI at entry while the oracle homes this and saves
//   ESI only in the outline arm).
// - Formal-home/float-window and donor-shaped screen-local variants widened
//   or broadly disturbed the function and were rolled back.
// - Corrected get_point to (short*, short*, float, float, float, int, int)
//   and AddGDINode to eight short coordinate parameters; all six calls remain
//   aligned, but VC5 moved to a 331-byte, 0x0C-frame codegen basin.
// - Retested a branch-local receiver alias after the ABI correction; emitted
//   code was unchanged and the alias was rolled back.
// - Restored complete m_s_obj field ownership and the three missing virtual
//   slots; emitted code was unchanged.
// - A natural sprite local was codegen-identical and was rolled back.
// - A named y-line local widened the first block and worsened positional diff.
// - Canonical Base_Game, Game_World, and Map virtual surfaces preserved all
//   proven offsets but were codegen-neutral.
// - Typed map-before-radii checkpoint with exact-donor pointer/int get_point
//   and short-coordinate AddGDINode worsened strict diff to 338 bytes and
//   retained the 0x0C frame; it was rolled back.
// - A diagnostic narrow get_point surface plus all-int AddGDINode surface and
//   map-before-radius order produced exact bytes. Exact callee donors reject
//   those ABIs, so main-agent audit did not retain or promote that form.
// - Keep the exact-donor pointer/int get_point and short-coordinate AddGDINode
//   surfaces. The remaining caller drift is an unresolved declaration-context
//   issue, not permission to use incompatible local prototypes.
// - An entry self alias modeled the original this home at [esp+0C], but VC5
//   emitted the same 331-byte code; rolled back as neutral evidence.
// - This pass retested period standard-header context, map/world declaration
//   forms, radius initialization and order, coordinate local scope/order,
//   receiver reference aliases, register-qualified screen parameters, and
//   explicit coordinate casts. Compatible forms were neutral or worse.
// - A function-scope sprite local, natural short-to-int promotion, persistent
//   screen-coordinate locals, and the same-TU donor's combined typed receiver
//   and world aliases were each codegen-neutral; all were rolled back.
// - Final unchanged validation remains 331 bytes, 0x0C frame, six ordered
//   calls, and 316 strict differing bytes; the pinned natural source is kept.
// - Fresh revisit tested the decompiler's coordinate copies, signed y local,
//   post-sprite receiver alias, and exact same-TU class declaration surface;
//   each emitted the same 331-byte basin. The clean typed source is restored.
// - Behavior correction: the binary resolves rge_base_game->world before it
//   reads this object's outline radii. Keep that fault order in the source.
// - Accepted-drift blocker: VC5 still hoists the outline_radius_x load between
//   the global base load and its world dereference. The executable dereferences
//   the world first. Invalid owners can therefore fault in a different context.
// - This claim tested a function-scope self alias, an intermediate world local,
//   an in-guard self alias, virtual declaration placement, and decompiler
//   coordinate-copy forms. These emitted the clean 0x0C-frame basin unchanged.
// - A named int x copy reduced positional diff from 338 to 336 bytes but made
//   an early sign-extension and worsened resynchronization; it is not retained.
// - A named int y copy worsened positional diff by one byte. The clean source
//   is restored; no natural source form fixed the saved-this frame or register
//   ownership during this claim.

class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Map;
class RGE_Game_World;
class DClipInfo_List;
class DClipInfo_Node;
class RGE_Master_Combat_Object;
class RGE_Static_Object;
class RGE_Player;

class RGE_Sprite {
public:
    unsigned char draw(long param_1, long param_2, long param_3, long param_4,
                       long param_5, long param_6, RGE_Color_Table* param_7,
                       TDrawArea* param_8, unsigned char param_9);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char do_terrain_brush(long a, long b, long c, unsigned char d);
    virtual unsigned char do_terrain_brush_stroke(long a, long b, long c, long d,
                                                   long e, unsigned char f);
    virtual unsigned char do_elevation_brush(long a, long b, long c, unsigned char d);
    virtual unsigned char do_elevation_brush_stroke(long a, long b, long c, long d,
                                                     long e, unsigned char f);
    virtual unsigned char do_cliff_brush(long a, long b, unsigned char c,
                                         unsigned char d);
    virtual unsigned char do_cliff_brush_stroke(long a, long b, long c, long d,
                                                unsigned char e, unsigned char f);
    virtual void map_generate(void* player, RGE_Game_World* world, void* info,
                              unsigned char* flags);
    virtual void map_generate2(RGE_Game_World* world, long w, long h,
                               unsigned char flag, long value);
    virtual void save(int file);
    void get_point(short* out_x, short* out_y, float param_3, float param_4,
                   float param_5, int param_6, int param_7);
};

class RGE_Game_World {
public:
    virtual void data_load_world(void* file);
    virtual void data_load_terrain_tables(char* file);
    virtual void data_load_players(char* file);
    virtual void data_load_objects(char* file);
    virtual void data_load_sounds(char* file);
    virtual void data_load_color_tables(char* file);
    virtual void data_load_sprites(char* file);
    virtual void data_load_players_type(short a, short b, void* file);
    virtual void data_load_effects(char* file);
    virtual void data_load_map(char* a, char* b, char* c, char* d, short e,
                               short f, short g, void* sounds, char* name);
    virtual void data_load_random_map(char* a, char* b, char* c, char* d);
    virtual void init_player_type(int a, short b, unsigned char c);
    virtual void init_player(int a);
    virtual void load_player(int a, unsigned char b, short c);
    virtual void color_table_init(int a);
    virtual void terrain_tables_init(int a);
    virtual void init_sounds(int a, void* driver);
    virtual void init_sprites(int a);
    virtual void map_init(int a, void* driver);
    virtual void effects_init(int a);
    virtual void master_player_init(int a);
    virtual void command_init(int a, void* handler);
    virtual void world_init(int a, void* driver, void* handler);
    virtual void setup_gaia();
    virtual void setup_players(void* info);
    virtual unsigned char new_random_game(void* info);
    virtual void save(int file);
    virtual void scenario_make_player(short a, unsigned char b, unsigned char c,
                                      unsigned char d, char* name);
    virtual void scenario_make_map(int a);
    virtual unsigned char load_scenario(void* info);
    virtual unsigned char load_scenario(char* file, void* info);
    virtual void load_scenario1(int a, void* info);
    virtual void load_scenario2(int a, void* info);
    virtual void load_scenario3(int a, void* info);
    virtual void load_scenario4(int a, void* info);
    virtual void load_scenario5(int a, void* info);
    virtual void load_scenario6(int a, void* info);
    virtual void load_scenario7(int a, void* info);
    virtual void load_scenario8(int a, void* info);
    virtual void logStatus(void* file, int a);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(void* info);
    virtual unsigned char data_load(char* a, char* b);
    virtual unsigned char init(char* a, void* driver, void* handler);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int a);
    virtual unsigned char load_game(char* file);
    virtual unsigned char new_game(void* info, int a);
    virtual unsigned char new_scenario(void* info, int a);
    virtual unsigned char save_game(char* file);
    virtual void base_save(char* file);
    virtual void base_save(int file);
    virtual unsigned char save_scenario(char* file);
    virtual void* get_scenario_info(char* file);
    virtual void pause(unsigned char flag);
    virtual void scenario_init(RGE_Game_World* world);
    virtual void scenario_init(int a, RGE_Game_World* world);
    virtual int addObject(void* object);
    virtual int removeObject(int id);
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_00[0x3F0];
    RGE_Game_World* world;
};

class DClipInfo_List {
public:
    DClipInfo_Node* AddGDINode(int param_1, int param_2, short param_3,
                               short param_4, short param_5, short param_6,
                               short param_7, short param_8, short param_9,
                               short param_10, int param_11, int param_12,
                               int param_13);
};

extern RGE_Base_Game* rge_base_game;
extern DClipInfo_List* SDI_List;
extern int SDI_Object_ID;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* src);
    virtual void modify(float value, unsigned char op);
    virtual void modify_delta(float value, unsigned char op);
    virtual void modify_percent(float value, unsigned char op);
    virtual void save(int file_handle);
    virtual void* make_new_obj(void* player, float x, float y, float z);
    virtual void* make_new_master();
    virtual unsigned char check_placement(void* player, float x, float y,
                                           int* values, unsigned char p5,
                                           unsigned char p6, unsigned char p7,
                                           unsigned char p8, unsigned char p9,
                                           unsigned char p10);
    virtual unsigned char alignment(float& x, float& y, RGE_Game_World* world,
                                    unsigned char mode);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();

    unsigned char master_type;
    char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    char pad_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    unsigned char pad_4F;
    short portrait_pict;
    unsigned char available;
    unsigned char pad_53;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    unsigned char pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char pad_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    void* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    unsigned char pad_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;

    virtual void draw(TDrawArea* draw_area, short x, short y,
                      RGE_Color_Table* color_table, long param_5, long param_6,
                      int param_7, unsigned char param_8);
};

void RGE_Master_Static_Object::draw(TDrawArea* draw_area, short x, short y,
                                    RGE_Color_Table* color_table, long param_5,
                                    long param_6, int param_7,
                                    unsigned char param_8) {
    if (this->sprite != 0) {
        this->sprite->draw(param_5, param_6, (int)x, (int)y, (int)x, (int)y,
                           color_table, draw_area, 10);

        if (param_7 != 0) {
            RGE_Map* map = rge_base_game->world->map;
            float rx1 = this->outline_radius_x;
            float ry1 = this->outline_radius_y;
            short x1;
            short y1;
            short x2;
            short y2;
            short x3;
            short y3;
            short x4;
            short y4;

            map->get_point(&x1, &y1, rx1, -ry1, 0.0f, x, y);
            map->get_point(&x2, &y2, rx1, ry1, 0.0f, x, y);
            rx1 = -rx1;
            map->get_point(&x3, &y3, rx1, ry1, 0.0f, x, y);
            map->get_point(&x4, &y4, rx1, -ry1, 0.0f, x, y);

            SDI_List->AddGDINode(1, (int)y, x1, y1, x2, y2, x3, y3, x4, y4,
                                 10, (int)(param_8 & 0xFF), SDI_Object_ID);
        }
    }
}
