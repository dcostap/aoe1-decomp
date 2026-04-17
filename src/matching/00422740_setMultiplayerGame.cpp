class RGE_Base_Game {
public:
    char gap_0[0x97D];
    unsigned char singlePlayerGame; // offset 0x97D
    unsigned char multiplayerGame;  // offset 0x97E

    void setMultiplayerGame(int v);
};

void RGE_Base_Game::setMultiplayerGame(int v)
{
    this->multiplayerGame = (unsigned char)v;
    this->singlePlayerGame = (unsigned char)(v == 0);
}
