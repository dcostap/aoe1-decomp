#ifndef COM_LOBY_CONTEXT
class RGE_Lobby {
public:
    char gap_0[0x14];
    unsigned char lobby_game;
    long SendZoneHandshakeResponse(void);
};
#endif

long RGE_Lobby::SendZoneHandshakeResponse(void) {
    return this->lobby_game != 0;
}
