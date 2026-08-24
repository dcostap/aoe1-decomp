#ifndef PLAYER_GROUPED_TU
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

    int isAlly(int player);
};
#endif

int RGE_Player::isAlly(int player) {
    if (player == this->id) {
        return 1;
    }
    if ((((0 < player) && (player < this->world->player_num)) && (this->relations[player] == 0))) {
        return 1;
    }
    return 0;
}
