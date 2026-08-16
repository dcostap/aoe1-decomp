// VA: 00420150 virtual RGE_Base_Game::set_player
// Exact under VC5 host with default /O2 /Oy flags.
// world is at +0x3F4; its num_players, current_player, and map fields are
// at +0x3C, +0x7C, and +0x28. Keep the null and signed bound guards.

class RGE_Map {
public:
    void clear_map_view_info(void);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x10];
    short num_players;
    char gap_3E[0x3E];
    short current_player;
};

class RGE_Base_Game {
public:
    virtual void set_player(short player_id);
    char gap_04[0x3F0];
    RGE_Game_World* world;
};

void RGE_Base_Game::set_player(short player_id) {
    RGE_Game_World* w = this->world;
    if (w == 0) return;
    if (player_id >= w->num_players) return;
    w->current_player = player_id;
    this->world->map->clear_map_view_info();
}
