#ifndef COM_LOBY_CONTEXT
struct DPSESSIONDESC2_gsi {
    unsigned long dword[20];
};
typedef DPSESSIONDESC2_gsi DPSESSIONDESC2;

struct DPLCONNECTION_gsi {
    char gap_00[0x08];
    DPSESSIONDESC2_gsi* lpSessionDesc;
};

class RGE_Lobby {
public:
    unsigned char GetSessionInfo(DPSESSIONDESC2* out);
    char gap_00[0x10];
    DPLCONNECTION_gsi* glpdplConnection;
    unsigned char lobby_game;
};
#endif

unsigned char RGE_Lobby::GetSessionInfo(DPSESSIONDESC2* out) {
    if (this->lobby_game == 0) {
        return 0;
    }
    *out = *this->glpdplConnection->lpSessionDesc;
    return 1;
}
