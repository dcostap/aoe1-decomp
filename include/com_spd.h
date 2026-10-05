#ifndef AOE1_COM_SPD_H
#define AOE1_COM_SPD_H

#include "com_hand.h"
#include "debuglog.h"
#include "rge_tslc.h"

class RGE_Communications_Speed {
    friend class TRIBE_Screen_Game;
    friend class TCommunications_Handler;

  private:
    char TBuff[255];                              // +0x00
    RGE_TimeSinceLastCall* TurnTSLC;              // +0x100
    RGE_TimeSinceLastCall* FrameTSLC;             // +0x104
    TCommunications_Handler* Comm;                // +0x108
    double AccumDiff;                             // +0x110
    int SpeedControlEnabled;                      // +0x118
    unsigned int CurrentBufferFrames;             // +0x11C
    unsigned int FutureBufferFrames;              // +0x120
    unsigned int TotalBufferFramesRemaining;      // +0x124
    unsigned int TargetTurnLengthMsec;            // +0x128
    unsigned int CurrentBufferGranularity;        // +0x12C
    unsigned int FutureBufferGranularity;         // +0x130
    unsigned int OverheadFactor;                  // +0x134
    unsigned long TimeSinceLastBuffer;            // +0x138
    unsigned long FutureSpeedChangeTurn;          // +0x13C
    unsigned long NextLatencyChangeTurn;          // +0x140
    unsigned int ActualLatency[10];               // +0x144
    unsigned int AverageTSLC[10];                 // +0x16C
    unsigned char PlayerOptimalFrames[10];        // +0x194
    unsigned char PlayerOptimalGranularity[10];   // +0x19E
    unsigned short RequestFasterOrSlower[10];     // +0x1A8
    unsigned long PlayerAvgFramesMsec[10];        // +0x1BC
    unsigned long PlayerHighLatencyMsec[10];      // +0x1E4
    unsigned long HighestLatencyMsec;             // +0x20C
    unsigned int SkipFrames;                      // +0x210
    unsigned int OptimalBufferFrames;             // +0x214
    unsigned int OptimalBufferGranularity;        // +0x218
    unsigned int DiffOffset;                      // +0x21C
    unsigned int AllAcknowledgedBuffersRemaining; // +0x220
    unsigned int LastAdjusted;                    // +0x224
    unsigned long RealTimePassed;                 // +0x228
    unsigned long BufferTimePassed;               // +0x22C
    unsigned int DroppedFrames;                   // +0x230
    unsigned int DroppedFramesTurn;               // +0x234
    unsigned long AdjustmentCount;                // +0x238
    int LastFrameHadTime;                         // +0x23C

  public:
    RGE_Communications_Speed(TCommunications_Handler* c);
    ~RGE_Communications_Speed();

    int AnalyzeGameSpeed(unsigned int* NewGranularity, unsigned int* NewBufferFrames, int ChangeAlso);
    unsigned int BufferFramesRemaining();
    unsigned int BufferTimeToUse(unsigned long current_turn);
    char* GetSelfPlayerOptimalSpeedStr();
    char* GetPlayerSpeedStatusStr(int PlayerNo);
    char* GetLatencyInfo();
    char* GetMachineSpeedInfo();
    unsigned int WaitingOnAcknowledgement();
    void SendDefaultSpeedChange();
    void Skip();
    unsigned int GetBufferGranularity();
    unsigned int GetBufferGranularityAdjusted();
    unsigned int GetRecommendedBufferFrames();
    unsigned int GetRecommendedBufferGranularity();
    unsigned long GetPlayerLatency(unsigned int PlayerNo);
    unsigned long GetPlayerRecommendedMsec(unsigned int player);
    unsigned int GetAvgFrameRate();
    unsigned char GetHighLatencyCenti();
    void SetFutureSpeedChange(unsigned int BuffCount, unsigned int BuffGran, unsigned long ExecTurn);
    void SetBufferFrames(unsigned int frames);
    void SetBufferGranularity(unsigned int granularity);
    void EnableSpeedControl(int TorF);
    void ReloadBufferFrames();
    void SetActualLatency(unsigned int PlayerNo, unsigned long Msec);
    void SetPlayerTurnSpeed(unsigned int PlayerNo, unsigned char AvgFramesMsec, unsigned char HiLatencyCenti);
    unsigned long GetAdjustmentCount();
    void SetV1(unsigned long v1);
    void SetV2(unsigned long v2);

    unsigned long GetPlayerAvgFramesMsec(unsigned int player) {
        if (player < 1 || player > 9)
            return 0;
        return this->PlayerAvgFramesMsec[player];
    }
    unsigned long GetPlayerHighLatencyMsec(unsigned int player) {
        if (player < 1 || player > 9)
            return 0;
        return this->PlayerHighLatencyMsec[player];
    }
    unsigned long GetHighestLatencyMsec() {
        return this->HighestLatencyMsec;
    }

  protected:
    void AdjustLocalSpeed();
};

typedef char com_spd_size_check[(sizeof(RGE_Communications_Speed) == 0x240) ? 1 : -1];

extern TDebuggingLog* L;

#endif
