#ifndef COM_LOBY_CONTEXT
struct DPNAME_gpi {
    char gap_00[0x08];
    char* lpszShortName;
};

struct DPLCONNECTION_gpi {
    char gap_00[0x0C];
    DPNAME_gpi* lpPlayerName;
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
    *out = this->glpdplConnection->lpPlayerName->lpszShortName;
    return 1;
}
