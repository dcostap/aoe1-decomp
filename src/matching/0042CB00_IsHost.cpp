class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;
    char gap_20[0x10C4];
    int Multiplayer;

    int IsHost(void);
};

int TCommunications_Handler::IsHost(void) {
    if (Multiplayer != 0) {
        return MeHost;
    }
    return 1;
}
