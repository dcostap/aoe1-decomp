// VA: 00422A10 GetWorldChecksum (64B)
// basegame.cpp - RGE_Base_Game member function

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
    long sum;
    RGE_Game_World* world;

    sum = 0;
    world = this->world;
    if (world != 0) {
        int i = 0;
        if (world->player_num > 0) {
            do {
                sum += world->players[i]->get_checksum();
                world = this->world;
                i++;
            } while (i < world->player_num);
        }
        return sum;
    }
    return 0;
}
