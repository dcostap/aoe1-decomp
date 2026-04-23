class RGE_Player {
public:
    void remake_visible_map(void);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;

    void reset_player_visible_maps(void);
};

void RGE_Game_World::reset_player_visible_maps(void) {
    int i = 0;

    if (i < this->player_num) {
        do {
            if (this->players[i] != 0) {
                this->players[i]->remake_visible_map();
            }
            i = i + 1;
        } while (i < this->player_num);
    }
}
