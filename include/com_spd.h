#ifndef AOE1_COM_SPD_H
#define AOE1_COM_SPD_H

#include <stddef.h>
#include "rge_tslc.h"

enum COMMSTATES {
    COMM_STATE_JOINNOW = 3
};

#pragma pack(push, 1)
struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    unsigned char _pad_0[3];
    unsigned long LastSentTime;
    COMMSTATES ProgramState;
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
    unsigned char InvalidPlayer[10];
    unsigned char _pad_3[2];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};
#pragma pack(pop)

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
    unsigned char _pad_10C6[2];
    unsigned long current_turn;
    unsigned char gap_10CC[0x484];
    COMMPLAYEROPTIONS PlayerOptions;

    int IsHost();
    int IsPlayerHuman(unsigned int player_index);
    int AllPlayersAcknowledged();
    void SendSpeedChange(unsigned int buffer_frames, unsigned int granularity);
};

class RGE_Communications_Speed {
public:
    char TBuff[255];                            // +0x00
    unsigned char _pad_0[1];                    // +0xFF
    RGE_TimeSinceLastCall* TurnTSLC;            // +0x100
    RGE_TimeSinceLastCall* FrameTSLC;           // +0x104
    TCommunications_Handler* Comm;              // +0x108
    unsigned char _pad_1[4];                    // +0x10C
    double AccumDiff;                           // +0x110
    int SpeedControlEnabled;                    // +0x118
    unsigned int CurrentBufferFrames;           // +0x11C
    unsigned int FutureBufferFrames;            // +0x120
    unsigned int TotalBufferFramesRemaining;    // +0x124
    unsigned int TargetTurnLengthMsec;          // +0x128
    unsigned int CurrentBufferGranularity;      // +0x12C
    unsigned int FutureBufferGranularity;       // +0x130
    unsigned int OverheadFactor;                // +0x134
    unsigned long TimeSinceLastBuffer;          // +0x138
    unsigned long FutureSpeedChangeTurn;        // +0x13C
    unsigned long NextLatencyChangeTurn;        // +0x140
    unsigned int ActualLatency[10];              // +0x144
    unsigned int AverageTSLC[10];                // +0x16C
    unsigned char PlayerOptimalFrames[10];       // +0x194
    unsigned char PlayerOptimalGranularity[10];  // +0x19E
    unsigned short RequestFasterOrSlower[10];    // +0x1A8
    unsigned long PlayerAvgFramesMsec[10];       // +0x1BC
    unsigned long PlayerHighLatencyMsec[10];     // +0x1E4
    unsigned long HighestLatencyMsec;            // +0x20C
    unsigned int SkipFrames;                     // +0x210
    unsigned int OptimalBufferFrames;            // +0x214
    unsigned int OptimalBufferGranularity;       // +0x218
    unsigned int DiffOffset;                     // +0x21C
    unsigned int AllAcknowledgedBuffersRemaining;// +0x220
    unsigned int LastAdjusted;                   // +0x224
    unsigned long RealTimePassed;                // +0x228
    unsigned long BufferTimePassed;              // +0x22C
    unsigned int DroppedFrames;                  // +0x230
    unsigned int DroppedFramesTurn;              // +0x234
    unsigned long AdjustmentCount;               // +0x238
    int LastFrameHadTime;                        // +0x23C

    RGE_Communications_Speed(TCommunications_Handler* handler);
    ~RGE_Communications_Speed();

    void SetPlayerTurnSpeed(unsigned int player, unsigned char avg_frames_msec,
                            unsigned char high_latency);
    void SetActualLatency(unsigned int player, unsigned long latency);
    void SetFutureSpeedChange(unsigned int buffer_frames,
                              unsigned int granularity,
                              unsigned long turn_change);
    void EnableSpeedControl(int value);
    unsigned int GetBufferGranularity();
    unsigned long GetAdjustmentCount();
    unsigned int GetBufferGranularityAdjusted();
    unsigned int BufferFramesRemaining();
    unsigned int WaitingOnAcknowledgement();

protected:
    void AdjustLocalSpeed();

public:
    void ReloadBufferFrames();
    unsigned int BufferTimeToUse(unsigned long value);
    void Skip();
    unsigned char GetHighLatencyCenti();
    unsigned long GetPlayerLatency(unsigned int player);
    char* GetLatencyInfo();
    char* GetSelfPlayerOptimalSpeedStr();
    char* GetPlayerSpeedStatusStr(int player);
    char* GetMachineSpeedInfo();
    unsigned int GetRecommendedBufferFrames();
    unsigned int GetAvgFrameRate();
    unsigned int GetRecommendedBufferGranularity();
    int AnalyzeGameSpeed(unsigned int* out_granularity,
                         unsigned int* out_frames, int param_3);
    void SetV1(unsigned long value);
    void SetV2(unsigned long value);
};

typedef char com_spd_size_check[(sizeof(RGE_Communications_Speed) == 0x240) ? 1 : -1];
typedef char com_spd_options_size_check[(sizeof(COMMPLAYEROPTIONS) == 0x1D0) ? 1 : -1];
typedef char com_spd_handler_options_check[
    (offsetof(TCommunications_Handler, PlayerOptions) == 0x1550) ? 1 : -1];

extern char DAT_0062d070[256];
extern char DAT_0062cf70[256];
extern char DAT_0062d170[152];

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;

#endif
