#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    char gap_00[0x84];
    unsigned char* relations;

    unsigned char relation(long param);
};
#endif

unsigned char RGE_Player::relation(long param) {
    return relations[param];
}
