struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    unsigned char _pad0[3];
    unsigned long LastSentTime;
    int ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned char _pad1[3];
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    unsigned char _pad2[3];
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    int Humanity[10];
    unsigned char InvalidPlayer[10];
    unsigned char _pad3[2];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};

class TCommunications_Handler {
public:
    char gap_00[0x1550];
    COMMPLAYEROPTIONS PlayerOptions;

    void InitPlayerInformation(unsigned int player, unsigned long player_id, char* name, char* formal_name);
    void UpdatePlayerInformation(unsigned long player_id, char* name, char* formal_name);
};

void TCommunications_Handler::UpdatePlayerInformation(unsigned long player_id, char* name, char* formal_name) {
    int player;
    int high;
    unsigned long* current;

    if (player_id != 0) {
        player = this->PlayerOptions.LowPlayerNumber;
        high = this->PlayerOptions.HighPlayerNumber;
        if ((int)player <= (int)high) {
            for (; (int)player <= (int)high; player++) {
                if (this->PlayerOptions.dcoID[player] == player_id) {
                    goto found;
                }
            }
        }
    }
    player = 0;
found:
    if (player == 0) {
        this->InitPlayerInformation(0, player_id, name, formal_name);
    }
}
