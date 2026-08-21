// 00542BF0 RGE_Game_World::new_scenario (World.cpp:1478-1537, 275B)
// Creates a new scenario from Player_Info and seed.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Virtual calls via this->method() with the owning world virtual surface generate
//   the expected [ebp+offset] dispatches with ecx=this.
// - Field offsets verified correct (world_time_delta_seconds at +0x84, random_seed at +0x78, etc.)
// - Remaining ~85% positional diff is purely instruction scheduling within basic blocks:
//   * GetRandomSeed return → push order vs store order (mov ecx,eax + push ecx vs push eax)
//   * map->new_map argument evaluation ordering (register allocation)
//   * map->clear_map argument evaluation ordering
//   * All struct fields at correct offsets
// - Strong candidate for variant_lab to find right evaluation/scheduling order
// - Probe 1 baseline: natural source emitted the scenario-null arm inline, but the
//   original keeps the load_scenario arm inline and places the null setup arm late.
// - Probe 2: inverted the scenario guard; all calls now align, but the seed local
//   still causes the debug_srand argument to be pushed before random_seed is stored.
// - Probe 3: mutating the input seed was codegen-identical; try reading the just-
//   stored random_seed member as the debug_srand argument to preserve its value.
// - Probe 4: give the first map call a local owning pointer; the original loads
//   map before cdecl cleanup, unlike the direct-member baseline.
// - Probe 5: fold the random_seed assignment into the debug_srand third argument;
//   this tests whether the original's store-before-push is an assignment result.
// - Probe 7 variant lab: seed spellings and direct/first-local map receivers all
//   collapse to the same 275-byte group; shared map locals add three prologue bytes.
// - Probe 8: direct member player_num spelling was codegen-identical to the local
//   count; try explicit this->map receiver expressions for the nonvirtual map calls.
// - Probe 9: explicit this->map receivers were codegen-identical; use the player_num
//   assignment as calloc's second argument to force a source dependency on its store.
// - Final source normalization: the assignment-expression probe was also identical;
//   retain the ordinary member assignment before calloc for a plausible source form.
// - Probe 13: restored the proven polymorphic/full-layout RGE_Map surface; no emitted change.
// - Probes 14-20: split the player count, corrected GetRandomSeed's unsigned-long ABI,
//   corrected clear_map's uchar/uchar ABI, and completed the generated object layouts;
//   all were emitted-code duplicates.
// - Probe 21: load_scenario(char*, RGE_Player_Info*) and setup_player_colors(info) share
//   the pre-branch info push required by the vslot ABI. This restored the late setup
//   block and improved shape to 93.41% (50% exact-block coverage), but not bytes.
// - Probe 22: a named copy of random_seed before debug_srand was codegen-identical.
// - Main-agent audit removed the proxy-vtable base and empty inline virtual bodies;
//   canonical world ownership preserves the remaining 221-byte scheduling gap.
// - Current assignment: the guarded do/while final scan, signed calloc/debug ABI,
//   virtual reference declaration, top-level count local, localized volatile store,
//   and unsigned-long random_seed variants were all emitted-code duplicates except
//   the top-level seed local (size +2); the clean typed source was restored.
// - Variant lab: 240 seed/map/count/loop combinations reduced to two emitted groups;
//   200 preserved size/frame/call-set, none matched. The remaining first hunk is the
//   seed store/push schedule at +0x2D; later map/count/register drift is shifted from it.
// - stdlib.h context for the period calloc surface was a duplicate and is retained;
//   paused after the 10-hypothesis assignment with exact size, CFG, and call parity.
// - Member-based debug_srand seed argument, matching exact World.cpp new_game donor,
//   was codegen-identical; restored the clean typed source.
// - Follow-up: corrected world_update_counter ownership to the named World.cpp
//   global; positional metrics stayed unchanged.
// - Follow-up: exact loader overload order moved the scenario call to vslot +74;
//   restored the target's char* loader surface at +78.
// - Follow-up: comma sequencing, one-line seed statements, explicit this member
//   spelling, and explicit long map casts were all codegen duplicates; restored
//   the natural typed source.
// - Follow-up: a fresh build confirms the first mismatch remains the seed
//   store/push schedule at +0x2D. Same-TU new_game uses a different statement
//   context and does not provide a new source lead for this function.
// - Current session: no evidence-backed natural source axis remains after the
//   prior seed/map variant family. Keep this clean typed reconstruction.
// - Worker pass sa-828576d2: the unchanged clean-source check preserved the
//   exact 275-byte size, frame, saved registers, CFG, and 12-call set. It still
//   mismatches at +0x2D (the original copies EAX to ECX, stores random_seed,
//   then pushes ECX). The prior natural seed, map, count, ABI, layout, and
//   branch-shape probes remain the useful evidence; no new source axis was
//   found. Leave this source in scratch for a later context or compiler study.
// - Revisit sa-fd5f5826: typed seed aliases, assignment forms, declaration
//   scope changes, player-pointer locals, standard-header combinations, and a
//   512-sample ambient declaration sweep did not improve the clean codegen.
//   One branch-local pointer was one byte larger; all other valid variants were
//   duplicates. Keep this natural source. The next useful evidence is the
//   historical World.cpp translation-unit or compiler context.
// - Object audit confirms the 275-byte FPO range, no locals, four saved
//   registers, ABI, field layouts, and 12 relocations. PDB names only this,
//   info, random_seed_in, and retval. Exact names are byte-neutral. No record
//   supports a local_count alias for the remaining seed/count scheduling.
// - Accepted-drift audit: do not promote this candidate. Before new_map, the
//   original reads this->map before info.map_height and info.map_width. The
//   rebuild reads both dimensions before this->map. Invalid world-map or info
//   pointers therefore fault in a different order.

#include <stdio.h>
#include <stdlib.h>

void __cdecl debug_srand(char* file, int line, unsigned int seed);

extern int world_update_counter;

// Source-gate audit: these local declarations use the reviewed World, Map,
// Player, Command, and Player_Info surfaces.  The target symbol proves that
// Player_Info is a struct.  The target vtable calls prove the pointer-shaped
// overload slots retained below.  No raw address, manual vtable, or filler
// virtual remains in this source.

class RGE_Info_Line {
public:
    float clump_num;
    short percent_of_tiles_covered;
    short percent_updown;
    short min_elevation;
    short max_elevation;
    short terrain_type;
    short terrain_base;
    char obj_id;
    unsigned char gap_11[3];
};

struct RGE_Map_Gen_Info {
public:
    short base_terrain;
    unsigned char gap_02[2];
    RGE_Info_Line land;
    RGE_Info_Line elevation[20];
    short elevation_num;
    unsigned char gap_1AA[2];
    RGE_Info_Line terrain[20];
    short terrain_num;
    unsigned char gap_33E[2];
    RGE_Info_Line objects[20];
    short objects_num;
    short player_num;
    short player_x[9];
    short player_y[9];
    short player_connect[9];
    short player_base_land[9];
    short space_between_islands_or_edge;
    unsigned char gap_end[2];
};

struct RGE_Player_Info {
public:
    char name[9][65];
    char type[9];
    char tribe[9];
    unsigned char gap_25B;
    short color[9];
    unsigned char gap_26E[2];
    long player_id_hash[9];
    short player_num;
    unsigned char gap_296[2];
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
    unsigned char gap_end[3];
};

class RGE_Player;
class RGE_Game_World;
class RGE_Tile;
class TCommunications_Handler {
public:
    unsigned long GetRandomSeed();
};

class RGE_Command {
public:
    void* vtable_ptr;
    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
};

class RGE_TOB_Picts {
public:
    short count;
    short animations;
    short shape_index;
};

class RGE_Tile_Size {
public:
    short width;
    short height;
    short y_delta;
};

class TShape;
class RGE_Sound;

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
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
    unsigned char gap_end[2];
};

class RGE_Border_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
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
    RGE_TOB_Picts borders[19][12];
    unsigned char draw_tile;
    unsigned char gap_59B;
    short underlay_terrain;
    short border_style;
};

class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;

class RGE_Map {
    virtual ~RGE_Map();
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long, unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, RGE_Player_Info*, unsigned char*);
    virtual void map_generate2(RGE_Game_World*, long, long, unsigned char, long);
    virtual void save(int);
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    unsigned char gap_8A[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    unsigned char any_frame_change;
    unsigned char gap_8DAD[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    unsigned char gap_8DBA[2];
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;

public:
    void new_map(long width, long height);
    void clear_map(unsigned char terrain, unsigned char height);
};

class RGE_Object_Node;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class Visible_Resource_Manager;
class RGE_Tile_List_Node;
class RGE_Static_Object;
class XYZBYTEPoint;
class RGE_Sprite;

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
    short attribute_num;
    unsigned char gap_4E[2];
    float* attributes;
    unsigned char culture;
    unsigned char gap_55[3];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
    unsigned char gap_82[2];
    unsigned char* relations;
    int unitDiplomacy[9];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char gap_106[2];
    RGE_Color_Table* color_table;
    long tribe_effect;
    Visible_Resource_Manager* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    unsigned char gap_12E[2];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    unsigned char groups_used[127];
    unsigned char gap_end[3];

    void set_map_visible();
};

class TSound_Driver;
class RGE_Scenario;
class RGE_Master_Player;
class RGE_Effects;
class RGE_Color_Table;
class RGE_Object_List;

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual unsigned char new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    // The old World.cpp vtable exposes these overloads through pointer-shaped
    // slots.  Keep the slot ABI while the target member itself uses a struct
    // reference, as shown by its decorated symbol.
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(RGE_Game_World*);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    unsigned char gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    unsigned char gap_36[2];
    RGE_Sprite** sprites;
    short player_num;
    unsigned char gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    unsigned char gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    RGE_Command* commands;
    RGE_Scenario* scenario;
    short color_table_num;
    unsigned char gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;
    unsigned char gap_75[3];
    unsigned int random_seed;
    short curr_player;
    unsigned char gap_7E[2];
    TSound_Driver* sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    class AIPlayBook* playbook;
    long campaign;
    long campaign_player;
    long campaign_scenario;
    int player_turn;
    unsigned long player_time_delta[9];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
};

unsigned char RGE_Game_World::new_scenario(RGE_Player_Info& info, int seed) {
    world_update_counter = 0;
    this->del_game_info();

    curr_player = 0;

    if (seed == 0) {
        seed = commands->com_hand->GetRandomSeed();
    }

    random_seed = seed;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x5D5, seed);

    this->map->new_map(info.map_width, info.map_height);
    this->map->clear_map((unsigned char)info.map_info->base_terrain, 1);

    player_num = info.player_num + 1;
    players = (RGE_Player**)calloc(4, player_num);

    this->setup_gaia();
    this->setup_players(info);

    world_time = 0;
    old_world_time = 0;
    world_time_delta = 0;
    old_time = 0;
    game_speed = 1.0f;
    temp_pause = 0;
    world_time_delta_seconds = 0.0f;

    unsigned char result;
    if (info.scenario != 0) {
        result = this->load_scenario(info.scenario, &info);
    } else {
        this->setup_player_colors(&info);
        this->scenario_init(this);
        result = 1;
    }

    if (result != 0) {
        int i;
        for (i = 0; i < (int)player_num; i++) {
            players[i]->set_map_visible();
        }
    }

    return result;
}
