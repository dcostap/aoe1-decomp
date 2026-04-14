class DiamondMapView_sp {
public:
    void clear_info(void);
};

class RGE_Game_World_sp {
public:
    char gap_00[0x28];
    DiamondMapView_sp* diamond_map;
    char gap_2C[0x10];
    short num_players;
    char gap_3E[0x3E];
    short current_player;
};

class RGE_Base_Game_sp {
public:
    void set_player(short player_id);
    char gap_00[0x3F4];
    RGE_Game_World_sp* world;
};

void RGE_Base_Game_sp::set_player(short player_id) {
    RGE_Game_World_sp* w = this->world;
    if (w == 0) return;
    if (player_id >= w->num_players) return;
    w->current_player = player_id;
    this->world->diamond_map->clear_info();
}
