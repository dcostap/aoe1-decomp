// 00455000 RGE_Map::RGE_Map ctor
// first pass: natural member calls and direct field offsets.
// HollowSnowdrop pass: improved to exact size with 6.3% edit diff / 13.4% positional. Remaining drift is localized after rge_read: original loads world into ECX and stores map=0 before homing ECX; rebuilt wants ECX=this before first call and uses EAX for world. Tried explicit game/world locals; still same family.
// 2026-05-10 SpruceGlow Boss-assigned pass: tried 12 more variants: no world local, direct global,
// store world before map, raw stores, delayed/unqualified calls, volatile game/world locals, shared zero local,
// call-arg casts, positive `if(load_random)`, fd local, and load_random local. No exact; best/current remains
// 127/127 with positional diff 17, edit diff 8, first mismatch 49. Drift is localized after `rge_read`: same
// values/stores/calls/control flow, but VC5 schedules `mov ecx,esi`, uses EAX for world, and moves the `push edi`
// before homing `game_world`.
// ACCEPTED_DRIFT: reviewed by Boss. Same size, stores, calls, control flow, stack cleanup, and returned this pointer. Remaining drift is localized post-rge_read scheduling/register choice: world carried in EAX instead of ECX, this loaded into ECX earlier for the upcoming member call, and push edi is moved before the game_world store. No behavior or memory-effect change.

extern "C" void __cdecl rge_read(int fd, void* buf, int size);

#ifndef MAP_CONTEXT_H

class RGE_Sound;
class RGE_Game_World;

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};
extern RGE_Base_Game* rge_base_game;

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;
    char gap_08[0x8D8C - 0x08];
    void* map_row_offset;
    char gap_8D90[0x8DB0 - 0x8D90];
    void* search_map;
    void* search_map_rows;
    char gap_8DB8[0x8DC0 - 0x8DB8];
    RGE_Game_World* game_world;
    void* map_zones;

    void load_terrain_types(RGE_Sound** sounds);
    void load_border_types(RGE_Sound** sounds);
    void init_tile_sizes();
    void data_load_random_map(int fd);

    RGE_Map(int fd, RGE_Sound** sounds, unsigned char load_random);
};

#endif

RGE_Map::RGE_Map(int fd, RGE_Sound** sounds, unsigned char load_random) {
    this->map_zones = 0;
    rge_read(fd, this, 0x8DD0);
    RGE_Base_Game* game = rge_base_game;
    RGE_Game_World* world = game->world;
    this->map = 0;
    this->game_world = world;
    this->search_map = 0;
    this->map_row_offset = 0;
    this->search_map_rows = 0;
    this->load_terrain_types(sounds);
    this->load_border_types(sounds);
    this->init_tile_sizes();
    if (load_random != 0) {
        this->data_load_random_map(fd);
    }
}
