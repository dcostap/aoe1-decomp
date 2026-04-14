struct DPLCONNECTION_gpi {
    char gap_00[0x08];
    void* player_name_ptr;
};

struct ConnectionInfo_gpi {
    char gap_00[0x08];
    DPLCONNECTION_gpi* conn_settings;
};

class RGE_Lobby_gpi {
public:
    unsigned char GetPlayerInfo(int* out);
    char gap_00[0x10];
    ConnectionInfo_gpi* lobby_data;
    unsigned char lobby_game;
};

unsigned char RGE_Lobby_gpi::GetPlayerInfo(int* out) {
    if (!this->lobby_game) return 0;
    *out = (int)this->lobby_data->conn_settings->player_name_ptr;
    return 1;
}
