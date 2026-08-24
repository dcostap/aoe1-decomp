// VA: 0042DC20, TCommunications_Handler::LaunchMultiplayerGame, 325 bytes
// Source: Com_hand.cpp lines 5856-5897
// FLAGS: default

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

#if !defined(COM_HAND_TU_CONTEXT)
extern "C" void __cdecl Log(void* log, const char* fmt, ...);
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern void* g_pDebugLog;     // at 62C4FCh
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern long g_DAT_0062c5ec;   // at 62C5ECh
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    void EnableNewPlayers(long param_2, long param_3);
    int CalculatePlayerRange();
    void ClearRXandTX();
    void PackPlayersDown();
    long SendSharedData(long param_1);
    void ResetLastCommunicationTimes();
    void NotifyWindow(long param_1);

    void LaunchMultiplayerGame();

    // Fields accessed
    char pad_0000[0x10C8];
    int current_turn;                    // +0x10C8
    char pad_10CC[0x14];                 // 0x10CC to 0x10DF
    int Me;                              // +0x10E0
    int Multiplayer;                     // +0x10E4
    char pad_10E8[0x1F0];               // 0x10E8 to 0x12D7
    ushort MaxGamePlayers;               // +0x12D8
    char pad_12DA[0x20A];               // 0x12DA to 0x14E3
    int GTDSerialNo;                     // +0x14E4
    char pad_14E8[0x44];                // 0x14E8 to 0x152B
    int PlayerHighSerialNumber;          // +0x152C
    char pad_1530[0x28];                // 0x1530 to 0x1557
    int ProgramState;                    // +0x1558
    char pad_155C[0x34];                // 0x155C to 0x158F
    uchar CommandTurnIncrement;          // +0x1590
    char pad_1591[0x17F];               // 0x1591 to 0x170F
    ushort HighPlayerNumber;             // +0x1710
    ushort LowPlayerNumber;              // +0x1712
    char pad_1714[0x04];                // 0x1714 to 0x1717
    int GameHasStarted;                  // +0x1718
    char pad_171C[0x04];                // 0x171C to 0x171F
    int LastTurnAck;                     // +0x1720
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::LaunchMultiplayerGame()
{
    this->EnableNewPlayers((int)g_DAT_0062c5ec, 0);
    this->PlayerOptions.ProgramState = 5;
    this->CalculatePlayerRange();
    unsigned int idx = 1;
    this->PlayerOptions.GameHasStarted = 1;
    this->ClearRXandTX();
    this->PackPlayersDown();

    // Loop over players to set serial numbers (uses idx=1 with jbe loop)
    if (this->MaxGamePlayers >= 1) {
        int base_serial = 2000;
        int* pp = (int*)&this->PlayerHighSerialNumber[0];
        do {
            if (pp[15] != 0) {
                *pp = base_serial;
                Log(g_pDebugLog, "Set expected ser# for player %d to %d", idx, base_serial + 1);
            }
            idx++;
            pp++;
            base_serial += 2000;
        } while (idx <= this->MaxGamePlayers);
    }

    // Compute GTDSerialNo = (Me * 125 * 16) + 1 = (Me * 2000) + 1
    this->GTDSerialNo = this->Me * 2000 + 1;
    Log(g_pDebugLog, "HOST Set own serial to =%d", this->GTDSerialNo);
    this->SendSharedData(1);
    this->current_turn = this->PlayerOptions.CommandTurnIncrement + 1;

    // Clear player acknowledgements if multiplayer
    if (this->Multiplayer != 0) {
        Log(g_pDebugLog, "Clear player acknowledgements");
        unsigned int low = this->PlayerOptions.LowPlayerNumber;
        unsigned int i = low;
        if (i <= this->PlayerOptions.HighPlayerNumber) {
            // NOTE: high is NOT cached — reloaded from memory each iteration
            int* ack = (int*)this->LastTurnAck + low;
            do {
                if (i != (unsigned int)this->Me) {
                    *ack = 0;
                }
                i++;
                ack++;
            } while (i <= this->PlayerOptions.HighPlayerNumber);
        }
    }

    this->ResetLastCommunicationTimes();
    this->NotifyWindow(0x17A6);
}
