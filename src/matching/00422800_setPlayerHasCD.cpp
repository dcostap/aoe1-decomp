class RGE_Base_Game_cd {
public:
    void setPlayerHasCD(int player, unsigned char hasCD);
    char gap_00[0x98A];
    unsigned char playerCDVersion[1];
};

void RGE_Base_Game_cd::setPlayerHasCD(int player, unsigned char hasCD) {
    unsigned char val = *((unsigned char*)this + 0x98A + player);
    val = (val & 0xFE) | hasCD;
    *((unsigned char*)this + 0x98A + player) = val;
}
