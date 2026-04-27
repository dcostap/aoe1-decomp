// VA: 00432DE0 RGE_Communications_Speed::AnalyzeGameSpeed
// com_spd.cpp lines 451-577

// attempt 1: speed analysis with player loop, division, output params
// 448/455 bytes (98.5%) — 7 bytes short
// Register allocation basin issue (ebp vs esi for this)
// Left in scratch.

class TCommunications_Handler {
public:
    int IsHost();
    int IsPlayerHuman(int player_index);
    void SendSpeedChange(int a, int b);
};

class RGE_Communications_Speed {
public:
    char TBuff[255];                       // +0x00
    unsigned char _pad_0[1];               // +0xFF
    void* TurnTSLC;                        // +0x100
    void* FrameTSLC;                       // +0x104
    TCommunications_Handler* Comm;         // +0x108
    unsigned char _pad_1[4];               // +0x10C
    double AccumDiff;                      // +0x110
    int SpeedControlEnabled;               // +0x118
    unsigned int CurrentBufferFrames;      // +0x11C
    unsigned int FutureBufferFrames;       // +0x120
    unsigned int TotalBufferFramesRemaining; // +0x124
    unsigned int TargetTurnLengthMsec;     // +0x128
    unsigned int CurrentBufferGranularity; // +0x12C
    unsigned int FutureBufferGranularity;  // +0x130
    unsigned int OverheadFactor;           // +0x134
    unsigned long TimeSinceLastBuffer;     // +0x138
    unsigned long FutureSpeedChangeTurn;   // +0x13C
    unsigned long NextLatencyChangeTurn;   // +0x140
    unsigned int ActualLatency[10];        // +0x144
    unsigned int AverageTSLC[10];          // +0x16C
    unsigned char PlayerOptimalFrames[10]; // +0x194
    unsigned char PlayerOptimalGranularity[10]; // +0x19E
    unsigned short RequestFasterOrSlower[10];  // +0x1A8
    unsigned long PlayerAvgFramesMsec[10]; // +0x1BC
    unsigned long PlayerHighLatencyMsec[10]; // +0x1E4
    unsigned long HighestLatencyMsec;      // +0x20C
    unsigned int SkipFrames;               // +0x210
    unsigned int OptimalBufferFrames;      // +0x214
    unsigned int OptimalBufferGranularity; // +0x218
    unsigned int DiffOffset;               // +0x21C
    unsigned int AllAcknowledgedBuffersRemaining; // +0x220
    unsigned int LastAdjusted;             // +0x224
    unsigned long RealTimePassed;          // +0x228
    unsigned long BufferTimePassed;        // +0x22C
    unsigned int DroppedFrames;            // +0x230
    unsigned int DroppedFramesTurn;        // +0x234
    unsigned long AdjustmentCount;         // +0x238
    int LastFrameHadTime;                  // +0x23C

    void SetFutureSpeedChange(int a, int b, int c);
    int AnalyzeGameSpeed(unsigned int* out_granularity, unsigned int* out_frames, int param_3);
};

int RGE_Communications_Speed::AnalyzeGameSpeed(unsigned int* out_granularity, unsigned int* out_frames, int param_3) {
    if (!Comm->IsHost()) return 0;
    if (NextLatencyChangeTurn != 0) return 0;
    
    char* comm_base = (char*)Comm;
    unsigned int total_turns = *(unsigned long*)(comm_base + 0x10C8) + (unsigned char)*(comm_base + 0x1590);
    if (total_turns < 20) return 0;
    
    LastAdjusted++;
    if (LastAdjusted < 5) return 0;
    
    unsigned int min_avg = 10;
    unsigned int max_high = 30;
    unsigned long* ptr = PlayerHighLatencyMsec; // +0x1E4
    int i = 1;
    do {
        ptr++;
        if (Comm->IsPlayerHuman(i)) {
            unsigned long avg = *(ptr - 10);  // PlayerAvgFramesMsec[i]
            if (min_avg <= avg) min_avg = avg;
            if (max_high <= *ptr) max_high = *ptr;
        }
        i++;
    } while (i <= 9);
    
    unsigned int new_gran = ((min_avg + 5) / 10) * 10;
    if (new_gran > 150) new_gran = 150;
    
    unsigned int cur_gran = CurrentBufferGranularity;
    int gran_diff = new_gran - cur_gran;
    if (gran_diff < 0) gran_diff = -gran_diff;
    if (gran_diff < 10) new_gran = cur_gran;
    
    unsigned int new_frames = max_high / new_gran + 2;
    if (new_frames >= 20) new_frames = 20;
    if (new_frames <= 4) new_frames = 4;
    
    if (new_gran * new_frames < 250) {
        new_frames = 250 / new_gran + 1;
    }
    
    unsigned int cur_frames = CurrentBufferFrames;
    int throughput_diff = (int)(new_gran * new_frames) - (int)(cur_frames * cur_gran);
    if (throughput_diff < 0) throughput_diff = -throughput_diff;
    if ((unsigned int)throughput_diff < 11) return 0;
    
    if (new_gran * new_frames < cur_frames * cur_gran &&
        throughput_diff > 100 &&
        cur_frames > 4) {
        new_frames = cur_frames - 1;
    }
    
    *out_granularity = new_gran;
    *out_frames = new_frames;
    
    if (param_3 != 0 && SpeedControlEnabled != 0) {
        SetFutureSpeedChange(new_frames, new_gran, total_turns);
        Comm->SendSpeedChange(new_frames, new_gran);
    }
    
    return 1;
}
