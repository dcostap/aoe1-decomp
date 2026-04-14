class RGE_Player {
public:
    char gap_00[0x84];
    unsigned char* relations;

    unsigned char relation(long param);
};

unsigned char RGE_Player::relation(long param) {
    return relations[param];
}
