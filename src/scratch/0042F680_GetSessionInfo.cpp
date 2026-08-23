struct DPSESSIONDESC2_gsi {
    int dword[20];
};

struct ConnectionInfo_gsi {
    char gap_00[0x08];
    DPSESSIONDESC2_gsi* session_desc;
};

class RGE_Lobby_gsi {
public:
    unsigned char GetSessionInfo(DPSESSIONDESC2_gsi* out);
    char gap_00[0x10];
    ConnectionInfo_gsi* lobby_data;
    unsigned char lobby_game;
};

unsigned char RGE_Lobby_gsi::GetSessionInfo(DPSESSIONDESC2_gsi* out) {
    if (!this->lobby_game) {
        return 0;
    }
    *out = *this->lobby_data->session_desc;
    return 1;
}
