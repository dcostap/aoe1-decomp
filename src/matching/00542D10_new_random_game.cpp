// VA: 00542D10 new_random_game
// PDB source: World.cpp
// Attempt log:
// - First attempt: flat class with implicit vtable at +0x00

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

extern int debug_rand(const char* file, int line);

class RGE_Player_Info {
public:
    char gap_00[0x2A0];
    short map_type;      // +0x2A0
};

class RGE_Map {
public:
    // vtable at +0x00 (implicit)
    char gap_04[0x8DD0 - 4]; // full size minus vtable
};

class RGE_Player {
public:
    // vtable at +0x00 (implicit)
};

// RGE_Map_pad: vtable with map_generate2 at vt[10] (offset 0x28)
class RGE_Map_pad : public RGE_Map {
public:
    VPAD8(0) VPAD1(8) VPAD1(9)
    virtual void map_generate2(void* world, long p2, long p3, unsigned char p4, long p5);
};

// RGE_Player_pad: vtable with player_update at vt[31] (offset 0x7C)
class RGE_Player_pad : public RGE_Player {
public:
    VPAD16(0) VPAD8(16) VPAD4(24) VPAD2(28) VPAD1(30)
    virtual void player_update();
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;
extern int world_update_counter;

// RGE_Game_World with everything at correct offsets
// vtable implicit at +0x00 (since class has virtual functions)
// Fields start at +0x04
class RGE_Game_World {
public:
    // vt[0..24] = 25 padding virtuals
    VPAD16(0) VPAD8(16) VPAD1(24)
    // vt[25] = new_random_game
    virtual unsigned char new_random_game(RGE_Player_Info& param_1);
    // vt[26..41] = 16 padding virtuals
    VPAD16(26)
    // vt[42] = setup_player_colors(RGE_Player_Info*)
    virtual void setup_player_colors(RGE_Player_Info* param_1);
    // vt[43..59] = 17 padding virtuals
    VPAD16(43) VPAD1(59)
    // vt[60] = scenario_init(RGE_Game_World*)
    virtual void scenario_init(RGE_Game_World* param_1);

    // Data fields (all shifted by 4 due to vtable pointer)
    char gap_04[0x24];              // +0x04-0x27
    RGE_Map_pad* map;               // +0x28
    char gap_2C[0x10];              // +0x2C-0x3B
    short player_num;               // +0x3C
    char gap_3E[0x2];               // +0x3E-0x3F
    RGE_Player_pad** players;       // +0x40
    char gap_44[0x34];              // +0x44-0x77
    unsigned int random_seed;       // +0x78
    short curr_player;              // +0x7C

    // Defined in another TU
    int initializePathingSystem();
};

unsigned char RGE_Game_World::new_random_game(RGE_Player_Info& param_1)
{
    short saved_curr_player;
    int loop_count;
    short i;
    RGE_Player_pad* player;

    world_update_counter = 0;
    this->setup_player_colors(&param_1);
    this->scenario_init(this);

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x612);
    L->Log("  World: before_map_gen (rand=%d)", this->random_seed);

    this->map->map_generate2(this, -1, -1, (unsigned char)param_1.map_type, this->player_num - 1);

    this->initializePathingSystem();

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x61A);
    L->Log("  World: after_map_gen (rand=%d)", this->random_seed);

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x622);
    L->Log("  World: after_player_random_start (rand=%d)", this->random_seed);

    saved_curr_player = this->curr_player;
    this->curr_player = -1;

    loop_count = 3;
    do {
        world_update_counter++;
        for (i = 0; i < this->player_num; i++) {
            player = this->players[i];
            if (player != 0) {
                player->player_update();
            }
        }
        loop_count--;
    } while (loop_count != 0);

    this->curr_player = saved_curr_player;
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x631);
    L->Log("  World: after_player_update (rand=%d)", this->random_seed);

    return 1;
}
