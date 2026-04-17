extern void* DAT_0062c4fc;
void __cdecl debug_log_ill(void* log, const char* fmt, ...);
extern char DAT_005832e8[];

class RGE_Lobby_ill {
public:
    int IsLobbyLaunched(void);
    char gap_00[0x14];
    unsigned char lobby_game;
};

int RGE_Lobby_ill::IsLobbyLaunched(void) {
    debug_log_ill(DAT_0062c4fc, DAT_005832e8, (unsigned int)this->lobby_game);
    int launched = (unsigned int)this->lobby_game;
    return launched;
}
