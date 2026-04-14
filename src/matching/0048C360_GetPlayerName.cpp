class TComm_System {
public:
    char gap_0[0x0D];
    char playerNames[1][256];
    char *GetPlayerName(int index);
};

char *TComm_System::GetPlayerName(int index) {
    return &this->playerNames[index][0];
}
