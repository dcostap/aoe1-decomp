// VA: 00422A10 GetWorldChecksum (64B)
// basegame.cpp - RGE_Base_Game member function
// sum declared before null check to match original prolog order

class RGE_Player {
public:
    long get_checksum(void);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;

    long GetWorldChecksum(void);
};

long RGE_Base_Game::GetWorldChecksum(void) {
    long sum = 0;
    if (this->world == 0) {
        return 0;
    }

    int i = 0;
    if (0 < this->world->player_num) {
        do {
            sum += this->world->players[i]->get_checksum();
            i++;
        } while (i < this->world->player_num);
    }
    return sum;
}
