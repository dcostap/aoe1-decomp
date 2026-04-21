struct ConnectionInfo_gsi {
    char gap_00[0x08];
    void* session_desc;
};

class RGE_Lobby_gsi {
public:
    unsigned char GetSessionInfo(void* out);
    char gap_00[0x10];
    ConnectionInfo_gsi* lobby_data;
    unsigned char lobby_game;
};

unsigned char RGE_Lobby_gsi::GetSessionInfo(void* out) {
    if (!this->lobby_game) return 0;
    // copies 20 dwords (80 bytes) from session_desc to out
    int* dst = (int*)out;
    int* src = (int*)this->lobby_data->session_desc;
    for (int i = 0; i < 20; i++)
        dst[i] = src[i];
    return 1;
}
