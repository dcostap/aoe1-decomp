// tried the simple low/high loop and the do/while shape; one build came out 1 byte short
// tried a direct early-return form; VC5 still wanted a different register basin at the top
// leaving this in scratch because the remaining gap is prolog/register-allocation drift, not call/behavior drift
class TCommunications_Handler {
public:
    char gap_0000[0x1550];
    struct {
        char gap_00[0x1C0];
        unsigned short HighPlayerNumber;
        unsigned short LowPlayerNumber;
    } PlayerOptions;

    void UpdatePlayer(unsigned short player, int zero);
    void NotifyWindow(int message);
    void UpdatePlayers(void);
};

void TCommunications_Handler::UpdatePlayers(void) {
    unsigned short player = this->PlayerOptions.LowPlayerNumber;
    unsigned short high = this->PlayerOptions.HighPlayerNumber;

    if (player > high) {
        this->NotifyWindow(0x17A4);
        return;
    }

    do {
        this->UpdatePlayer(player, 0);
        ++player;
    } while (player <= high);

    this->NotifyWindow(0x17A4);
}
