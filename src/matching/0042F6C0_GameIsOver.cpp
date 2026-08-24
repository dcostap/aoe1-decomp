#ifndef COM_LOBY_CONTEXT
class RGE_Lobby {
public:
    char gap_0[0x14];
    unsigned char lobby_game;
    int GameIsOver(void);
};
#endif

int RGE_Lobby::GameIsOver(void) {
    return this->lobby_game != 0;
}
