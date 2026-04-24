// tried pointer-walk, direct indexing, and the decompiler-shaped loop; VC5 stayed in the wrong register basin and kept saving ebx
// remaining mismatch is the prolog/register allocation around the first stack arg load
class COMMPLAYEROPTIONS {
public:
    unsigned char NeedsToBeSent;
    unsigned char _pad_0[0x3];
    unsigned long LastSentTime;
    int ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned char _pad_1[0x3];
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    unsigned char _pad_2[0x3];
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    unsigned long Humanity[10];
    unsigned char InvalidPlayer[10];
    unsigned char _pad_3[0x2];
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
    unsigned int uVar1;
    unsigned int uVar2;
    unsigned long* puVar3;

    if (player_id != 0) {
        uVar1 = (unsigned int)this->PlayerOptions.LowPlayerNumber;
        uVar2 = (unsigned int)this->PlayerOptions.HighPlayerNumber;
        if (uVar1 <= uVar2) {
            puVar3 = &this->PlayerOptions.dcoID[uVar1];
            do {
                if (*puVar3 == player_id) {
                    uVar1 = 1;
                    goto LAB_0042D155;
                }
                uVar1 = uVar1 + 1;
                puVar3 = puVar3 + 1;
            } while ((int)uVar1 <= (int)uVar2);
        }
    }
    uVar1 = 0;
LAB_0042D155:
    if (uVar1 == 0) {
        this->InitPlayerInformation(0, player_id, name, formal_name);
    }
}
