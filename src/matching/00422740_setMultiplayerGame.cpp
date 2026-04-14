class RGE_Base_Game {
public:
    char gap_0[0x97D];
    unsigned char field_97D;
    unsigned char field_97E;
    void setMultiplayerGame(int v);
};

void RGE_Base_Game::setMultiplayerGame(int v) {
    this->field_97E = (unsigned char)v;
    this->field_97D = (unsigned char)(v == 0);
}
