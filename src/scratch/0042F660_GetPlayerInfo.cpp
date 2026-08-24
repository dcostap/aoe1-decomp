#ifndef COM_LOBY_CONTEXT
struct DPLCONNECTION_gpi {
    char gap_00[0x0C];
    void* lpPlayerName;
};

class RGE_Lobby {
public:
    unsigned char GetPlayerInfo(char** out);
    char gap_00[0x10];
    DPLCONNECTION_gpi* glpdplConnection;
    unsigned char lobby_game;
};
#endif

unsigned char RGE_Lobby::GetPlayerInfo(char** out) {
    if (this->lobby_game == 0) {
        return 0;
    }
    *out = (char*)this->glpdplConnection->lpPlayerName;
    return 1;
}
