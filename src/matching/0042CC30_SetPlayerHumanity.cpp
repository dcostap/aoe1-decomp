// attempt log:
// first pass: natural guard/store/call form with the player humanity table and the host-only follow-up
// target shape: bounds check, store humanity at +0x16D4, UpdatePlayer(player,1), NotifyWindow(0x17A6), optional send-shared-data path

#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    unsigned char _pad_0[3];
    unsigned long LastSentTime;
    int ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned char _pad_1[3];
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    unsigned char _pad_2[3];
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    int Humanity[10];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;
    char gap_20[0x12B8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x276];
    COMMPLAYEROPTIONS PlayerOptions;

    void UpdatePlayer(int player, int zero);
    void NotifyWindow(int message);
    void SendSharedData(int zero);

    void SetPlayerHumanity(unsigned int player, int humanity);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetPlayerHumanity(unsigned int player, int humanity) {
    if (player < 1) {
        return;
    }
    if (player > this->MaxGamePlayers) {
        return;
    }

    this->PlayerOptions.Humanity[player] = humanity;
    this->UpdatePlayer(player, 1);
    this->NotifyWindow(0x17A6);
    if (this->MeHost != 0 && this->PlayerOptions.ProgramState == 3) {
        this->PlayerOptions.NeedsToBeSent = 1;
        this->SendSharedData(0);
    }
}
