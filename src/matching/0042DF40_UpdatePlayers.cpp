// VA: 0042DF40 UpdatePlayers (65 B)
// PDB source: Com_hand.cpp lines 5990-5998

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

void TCommunications_Handler::UpdatePlayers() {
    int low = this->LowPlayerNumber;
    int high = this->HighPlayerNumber;
    if (low <= high) {
        do {
            UpdatePlayer(low, 0);
        } while (++low <= this->HighPlayerNumber);
    }
    NotifyWindow(0x17A4);
}
