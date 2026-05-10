// 00470600 RGE_Player::win_game_now
// Working pass: natural player/world loop.

class RGE_World;

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
    char gap_40[0x4A - 0x40];
    short id;
    char gap_4C[0x104 - 0x4C];
    unsigned char allied_victory;

    void victory_if_game_on();
    void loss_if_game_on();
    unsigned char relation(long player_id);
    void win_game_now();
};

class RGE_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x40 - 0x3E];
    RGE_Player** players;
};

void RGE_Player::win_game_now() {
    this->victory_if_game_on();
    for (int i = 1; i < this->world->player_num; i++) {
        if (i != this->id) {
            if (this->allied_victory) {
                if (!this->relation(i)) {
                    if (!this->world->players[i]->relation((long)this->id) && this->world->players[i]->allied_victory) {
                        this->world->players[i]->victory_if_game_on();
                        continue;
                    }
                }
            }
            this->world->players[i]->loss_if_game_on();
        }
    }
}
