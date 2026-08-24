#ifndef COM_LOBY_CONTEXT
class TDebuggingLog {
public:
    void Log(char* format, ...);
};
extern TDebuggingLog* L;

class RGE_Lobby {
public:
    int IsLobbyLaunched(void);
    char gap_00[0x14];
    unsigned char lobby_game;
};
#endif

int RGE_Lobby::IsLobbyLaunched(void) {
    L->Log((char*)"LOBBY GAME LAUNCH STATUS = %d",
           (unsigned int)this->lobby_game);
    return (unsigned int)this->lobby_game;
}
