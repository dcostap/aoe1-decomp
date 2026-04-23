struct PlayerWorld {
    char gap_00[0x3C];
    short player_num;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    PlayerWorld* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x36];
    unsigned char* relations;

    int isEnemy(int player);
};

int RGE_Player::isEnemy(int player) {
    if ((((player != this->id) && (player > 0)) && (player < this->world->player_num)) && (this->relations[player] == 3)) {
        return 1;
    }
    return 0;
}
