#ifndef COM_LOBY_CONTEXT
struct LobbyConnection {
    int unknown_00;
    unsigned int dwFlags;
};

class RGE_Lobby {
public:
    char gap_00[0x10];
    LobbyConnection* glpdplConnection;
    unsigned char lobby_game;

    unsigned char IsThisHost();
};
#endif

unsigned char RGE_Lobby::IsThisHost() {
    if (!this->lobby_game) {
        return 0;
    }

    // Keeping the host-bit test in explicit 0/1 branch form preserves the
    // original VC5 basin: full dword load from dwFlags, then AL-only shift/mask.
    if (!((this->glpdplConnection->dwFlags >> 1) & 1)) {
        return 0;
    }
    return 1;
}
