// VA: 0042DF40 UpdatePlayers (65 B)
// PDB source: Com_hand.cpp lines 5990-5998

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x170C];
    unsigned short HighPlayerNumber;  // +0x1710
    unsigned short LowPlayerNumber;   // +0x1712
    void UpdatePlayer(unsigned int id, int timeout);
    void NotifyWindow(int message);
    void UpdatePlayers();
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::UpdatePlayers() {
    int low = this->PlayerOptions.LowPlayerNumber;
    int high = this->PlayerOptions.HighPlayerNumber;
    if (low <= high) {
        do {
            UpdatePlayer(low, 0);
        } while (++low <= this->PlayerOptions.HighPlayerNumber);
    }
    NotifyWindow(0x17A4);
}
