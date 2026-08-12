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

#include <stdlib.h>

void __cdecl debug_srand(char* file, int line, unsigned int seed);

extern int world_update_counter;

struct RGE_Map_Gen_Info {
    unsigned char base_terrain;
    char gap_01[0x51F];
};

struct RGE_Player_Info {
    char gap_00[0x294];
    short player_num;
    char gap_296[2];
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    char gap_2A0[2];
    short map_width;
    short map_height;
};

struct TCommunications_Handler {
    unsigned long GetRandomSeed();
};

struct RGE_Command {
    char gap_00[0x14];
    TCommunications_Handler* com_hand;
};

struct RGE_Player;
struct RGE_Game_World;
struct RGE_Tile;

struct RGE_Map {
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
    void* map_data;
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x0A];
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    char gap_8DA0[0x30];
    void new_map(long width, long height);
    void clear_map(unsigned char terrain, unsigned char fill);
};

struct RGE_Player {
    void set_map_visible();
};

struct RGE_Game_World {
    virtual unsigned char data_load_world(void*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map();
    virtual void data_load_random_map();
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, void*);
    virtual void init_sprites(int);
    virtual void map_init(int, void*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, void*);
    virtual void world_init(int, void*, void*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual unsigned char new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual void load_scenario1(); virtual void load_scenario2();
    virtual void load_scenario3(); virtual void load_scenario4();
    virtual void load_scenario5(); virtual void load_scenario6();
    virtual void load_scenario7(); virtual void load_scenario8();
    virtual void logStatus(void*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, void*, void*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info*, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual void* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(RGE_Game_World*);
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    char gap_10[4];
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    char gap_1D[0x28 - 0x1D];
    RGE_Map* map;
    char gap_2C[0x3C - 0x2C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x58 - 0x44];
    RGE_Command* commands;
    char gap_5C[0x78 - 0x5C];
    int random_seed;
    short curr_player;
    char gap_7E[2];
    char* sound_driver;
    float world_time_delta_seconds;
    char gap_88[0x7C];

    unsigned char new_scenario(RGE_Player_Info& info, int seed);
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
    this->map->clear_map(info.map_info->base_terrain, 1);

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
