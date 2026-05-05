// 00455000 RGE_Map::RGE_Map ctor
// first pass: natural member calls and direct field offsets.
// HollowSnowdrop pass: improved to exact size with 6.3% edit diff / 13.4% positional. Remaining drift is localized after rge_read: original loads world into ECX and stores map=0 before homing ECX; rebuilt wants ECX=this before first call and uses EAX for world. Tried explicit game/world locals; still same family.

extern "C" void __cdecl rge_read(int fd, void* buf, int size);

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
    void* vptr;
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

RGE_Map::RGE_Map(int fd, RGE_Sound** sounds, unsigned char load_random) {
    this->vptr = (void*)0x570678;
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
