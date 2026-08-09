// 00542BF0 RGE_Game_World::new_scenario (World.cpp:1478-1537, 275B)
// Creates a new scenario from Player_Info and seed.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Virtual calls via this->method() with the owning world virtual surface (slots 23,24,30,42,46,60)
//   generate correct call [ebp+offset] with ecx=this
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
// - Main-agent audit removed the proxy-vtable base and empty inline virtual bodies;
//   canonical world ownership preserves the validated 221-byte scheduling gap.

void* __cdecl calloc(unsigned int n, unsigned int size);
void __cdecl debug_srand(char* file, int line, unsigned int seed);

extern int world_update_counter;

struct RGE_Map_Gen_Info {
    unsigned char base_terrain;
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
    unsigned int GetRandomSeed();
};

struct RGE_Command {
    char gap_00[0x14];
    TCommunications_Handler* com_hand;
};

struct RGE_Map {
    void new_map(long width, long height);
    void clear_map(unsigned char terrain, int fill);
};

struct RGE_Player {
    void set_map_visible();
};

struct RGE_Game_World {
    virtual ~RGE_Game_World();    virtual void d1();    virtual void d2();    virtual void d3();    virtual void d4();    virtual void d5();    virtual void d6();    virtual void d7();    virtual void d8();    virtual void d9();    virtual void d10();    virtual void d11();    virtual void d12();    virtual void d13();    virtual void d14();    virtual void d15();    virtual void d16();    virtual void d17();    virtual void d18();    virtual void d19();    virtual void d20();    virtual void d21();    virtual void d22();    virtual void step1();    virtual void step2(RGE_Player_Info&);    virtual void d25();    virtual void d26();    virtual void d27();    virtual void d28();    virtual void d29();    virtual unsigned char load_scenario(char*);    virtual void d31();    virtual void d32();    virtual void d33();    virtual void d34();    virtual void d35();    virtual void d36();    virtual void d37();    virtual void d38();    virtual void d39();    virtual void d40();    virtual void d41();    virtual void step3(RGE_Player_Info&);    virtual void d43();    virtual void d44();    virtual void d45();    virtual void update();    virtual void d47();    virtual void d48();    virtual void d49();    virtual void d50();    virtual void d51();    virtual void d52();    virtual void d53();    virtual void d54();    virtual void d55();    virtual void d56();    virtual void d57();    virtual void d58();    virtual void d59();    virtual void step4(RGE_Game_World*);
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
    unsigned int random_seed;
    short curr_player;
    char gap_7E[2];
    char* sound_driver;
    float world_time_delta_seconds;

    unsigned char new_scenario(RGE_Player_Info& info, int seed);
};

unsigned char RGE_Game_World::new_scenario(RGE_Player_Info& info, int seed) {
    world_update_counter = 0;
    this->update();

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

    this->step1();
    this->step2(info);

    world_time = 0;
    old_world_time = 0;
    world_time_delta = 0;
    old_time = 0;
    game_speed = 1.0f;
    temp_pause = 0;
    world_time_delta_seconds = 0.0f;

    unsigned char result;
    if (info.scenario != 0) {
        result = this->load_scenario(info.scenario);
    } else {
        this->step3(info);
        this->step4(this);
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
