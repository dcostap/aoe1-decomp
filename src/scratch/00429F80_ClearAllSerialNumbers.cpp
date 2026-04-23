// attempt log:
// tried direct cdecl-style Log helper with the global logger pointer; call order matched, but ESI/EDI allocation drifted
// tried removing the bound local; loop base fixed at +13E4, then the xor-edi / bound-load order became the first mismatch
// tried moving the bound local into the loop body; that fixed nothing useful and made the counter path worse, so it was rolled back
// paused here because the remaining mismatch is register-allocation/order drift around the loop bound, not a behavior change
class TDebuggingLog;

void Log(TDebuggingLog* log, char* text);

class TCommunications_Handler {
public:
    int OptionsChanged;
    char* OptionsData;
    int Steps;
    unsigned long TickStart;
    unsigned long TickCount;
    unsigned long TimeSinceLastCall;
    void* Chat;
    int MeHost;
    int HaveHostInit;
    char InCommBuff[4001];
    char TBuff[257];
    unsigned char _pad_0[2];
    unsigned long current_turn;
    unsigned long next_command_turn;
    unsigned int sequence;
    long WaitOnPlayer;
    unsigned long TurnSpeedMsec;
    unsigned long AcknowledgeAfterMsec;
    unsigned int Me;
    int Multiplayer;
    int OutOfSyncFlag;
    unsigned long dwStopTime;
    float lastRXDataRate;
    float lastTXDataRate;
    char MyFriendlyName[129];
    char MyFormalName[129];
    char MyGameTitle[129];
    unsigned char _pad_1[1];
    unsigned long CurrentPlayers;
    int previous_last_world_random;
    int last_world_random;
    int StepMode;
    unsigned long turnstart;
    unsigned long lastcalltick;
    unsigned long mselapsed;
    int AvgTurnTime;
    int SkipFrames;
    int PauseChangePending;
    unsigned long CommunicationsVersionCode;
    int ShuttingDown;
    unsigned long ReturnElapsed;
    unsigned long ReturnRXPacketSize;
    unsigned long ReturnTXPacketSize;
    unsigned long RXPacketLength;
    unsigned long RXPacketLengthHigh;
    unsigned long TXPacketLength;
    unsigned long TXPacketLengthHigh;
    void* FriendlyName;
    void* FormalName;
    unsigned long LastTimeoutMessageTime;
    int CommunicationsStatus;
    unsigned short MaxGamePlayers;
    unsigned char _pad_2[2];
    char gap_12dc[0x108];
    unsigned int LastSerialRequestedTX[10];

    void ClearAllSerialNumbers();
};

void TCommunications_Handler::ClearAllSerialNumbers() {
    unsigned int* serials;
    unsigned int i;

    Log(*(TDebuggingLog**)0x62C4FC, (char*)"Cleared all serial numbers.");
    i = 0;
    serials = this->LastSerialRequestedTX;
    do {
        serials[0x51] = 0;
        serials[0] = 0;
        serials[10] = 0;
        serials[0x14] = 0;
        serials[0x1e] = 0;
        i = i + 1;
        serials = serials + 1;
    } while (i <= this->MaxGamePlayers);
}
