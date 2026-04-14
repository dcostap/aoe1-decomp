class RGE_Player_gp;

class RGE_Game_World_gp {
public:
    char gap_00[0x3C];
    short num_players;
    char gap_3E[0x02];
    void** player_list;
    char gap_44[0x38];
    short current_player;
};

class RGE_Base_Game_gp {
public:
    RGE_Player_gp* get_player(void);
    char gap_00[0x3F4];
    RGE_Game_World_gp* world;
};

RGE_Player_gp* RGE_Base_Game_gp::get_player(void) {
    RGE_Game_World_gp* w = this->world;
    if (!w) return 0;
    if (!w->num_players) return 0;
    if (w->current_player >= w->num_players) return 0;
    return (RGE_Player_gp*)w->player_list[(int)(short)w->current_player];
}
