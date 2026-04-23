// tried the decompiler-shaped loop with a nullable world pointer and reloads from this->world
// tried a direct-this version and an early-return version; mismatch stayed in the prolog basin
// remaining gap looks like saved-register / push-order codegen (esi/edi/ebx) rather than behavior

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
    if (this->world == 0) {
        return 0;
    }

    long sum = 0;
    int i = 0;
    if (0 < this->world->player_num) {
        do {
            sum += this->world->players[i]->get_checksum();
            i++;
        } while (i < this->world->player_num);
    }
    return sum;
}
