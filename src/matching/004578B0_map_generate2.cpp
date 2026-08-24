// VA: 004578B0 map_generate2 (266B)
// map.cpp:1478-1511
//
// Baseline reconstruction: preserve the map/world/random-map ownership shown by
// the executable.  The random-map controller's virtual surface is the one used
// by the exact rmm_dbct.cpp init/de_init donors: generate at slot 0, the four
// module additions at slots 1-4, init at slot 5, and de_init at slot 6.
// Main-agent audit restored canonical world/base-game ownership and the full
// RGE_Map virtual prefix through map_generate2; emitted code remains exact.

class RGE_Game_World;
class RGE_Random_Map_Module;
class RGE_RMM_Database_Controller;
class RGE_Player;
class TDebuggingLog;

extern "C" int debug_rand(char* file, int line);
void debug_srand(char* file, int line, unsigned int seed);

#ifndef MAP_CONTEXT_H
class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    virtual void add_land_module(unsigned char value);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual unsigned char init(class RGE_Map* map, RGE_Game_World* world,
                               unsigned char map_type, long players,
                               unsigned char value);
    virtual unsigned char de_init();
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x19];
    unsigned char game_state;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x28];
    int random_map_seed;
    char gap_30[0x4];
    int save_random_map_seed;
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern RGE_Base_Game* rge_base_game;
extern TDebuggingLog* L;

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long, unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, void*, unsigned char*);
    virtual void map_generate2(RGE_Game_World* world, long p2, long p3,
                               unsigned char p4, long p5);

    char gap_04[0x8DBC - 4];
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;

    void clear_map(RGE_Player* player, RGE_Game_World* world,
                   unsigned char value, long width, long height);
};

#endif

void RGE_Map::map_generate2(RGE_Game_World* param_1, long param_2,
                            long param_3, unsigned char param_4, long param_5)
{
    unsigned char old_state = this->game_world->game_state;
    this->game_world->game_state = 3;

    int seed = rge_base_game->random_map_seed;
    if (seed == -1) {
        seed = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5CE);
    }

    rge_base_game->save_random_map_seed = seed;
    L->Log("Random Map Seed = %d", seed);

    debug_srand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5DA, seed);
    this->clear_map(0, param_1, 0, param_2, param_3);

    debug_srand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5DD, seed);
    this->random_map->init(this, param_1, param_4, param_5, 1);

    debug_srand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5E0, seed);
    this->random_map->generate();
    this->random_map->de_init();

    int after_seed = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5E5);
    L->Log("After Random Map Generation random number is %d", after_seed);

    this->game_world->game_state = old_state;
}
