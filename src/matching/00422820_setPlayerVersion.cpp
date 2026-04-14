class RGE_Base_Game_ver {
public:
    void setPlayerVersion(int player, unsigned char version);
    char gap_00[0x98A];
    unsigned char playerCDVersion[1];
};

void RGE_Base_Game_ver::setPlayerVersion(int player, unsigned char version) {
    unsigned char v = version << 1;
    unsigned char old = *((unsigned char*)this + 0x98A + player);
    v = v | (old & 1);
    *((unsigned char*)this + 0x98A + player) = v;
}
