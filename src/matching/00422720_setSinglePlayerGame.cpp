// STATUS: scratch
// FLAGS: config\flags\00422720_setSinglePlayerGame.rsp

class RGE_Base_Game {
public:
    char gap_0[0x97D];
    unsigned char singlePlayerGame; // offset 0x97D
    unsigned char multiplayerGame;  // offset 0x97E

    void setSinglePlayerGame(int v);
};

void RGE_Base_Game::setSinglePlayerGame(int v)
{
    this->singlePlayerGame = (unsigned char)v;
    this->multiplayerGame = (unsigned char)(v == 0);
}
