// VA: 00432DE0 RGE_Communications_Speed::AnalyzeGameSpeed
// com_spd.cpp lines 451-577

// Matching attempt log:
// - Baseline raw communication cursor plus pre-call pointer increment: 419
//   positional diff bytes, effective size 442 versus 455, frame 0x8 versus 0xC.
// - Explicit self aliases, register hints, and donor stdio/string context were
//   either codegen duplicates or a worse basin; rolled back.
// - Recovered the binary's natural cursor topology by starting at
//   PlayerHighLatencyMsec + 1 and advancing ptr beside i at loop bottom. This
//   moved the emitted code to 235 diff bytes, effective size 448, and preserved
//   ESI=this with the observed bottom add esi,4.
// - Canonicalized TCommunications_Handler ownership for current_turn (+10C8)
//   and PlayerOptions.CommandTurnIncrement (+1590). Split declarations and
//   total_turns assignment were codegen duplicates at the final basin.
// - Reversed min/max declaration order once; it swapped the callee-save values
//   away from the oracle, so the current source keeps min_avg before max_high.
// - Best unresolved result: 235 positional diff bytes, 364 equal/resynchronized
//   bytes, calls 4/4 with exact target identity, effective size 448/455, frame
//   0x8/0xC. The remaining structural lead is the missing 4-byte local/frame
//   slot and associated total-turn/cur-gran stack-home schedule.
// - Modeled the binary-named unsigned long SyncTurn local and current-frame
//   local in the declaration block. Replaced manual signed-difference branches
//   with stdlib abs and typed both difference locals unsigned long. This
//   recovered the 0xC frame, the SyncTurn home at [esp+14], branchless abs,
//   and unsigned threshold branches: 162 positional diff bytes, 456/455
//   bytes, 0xC/0xC frame, and calls 4/4. Total-turn and product-order probes
//   were duplicates. Remaining drift is the early register/load schedule,
//   loop-init order, product coloring, and one-byte size surplus.
// - Reopened on the auditor lead and initialized i before the latency cursor.
//   This improved positional diff from 162 to 154 bytes and aligned more of
//   the initialization block. Size remains 456 versus 455; no broad tuning was attempted.
// - Reopened on the one-byte boundary lead; array-index terminal stores were
//   codegen-identical, so the canonical dereference stores remain.
// Left in scratch after the bounded 10-hypothesis assignment.

#include <stdlib.h>

class COMMPLAYEROPTIONS {
public:
    unsigned char gap_00[0x40];
    unsigned char CommandTurnIncrement; // +0x40
};

class TCommunications_Handler {
public:
    unsigned char gap_00[0x10C8];
    unsigned int current_turn; // +0x10C8
    unsigned char gap_10CC[0x1550 - 0x10CC];
    COMMPLAYEROPTIONS PlayerOptions; // +0x1550

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

    unsigned char command_increment = Comm->PlayerOptions.CommandTurnIncrement;
    unsigned int total_turns = Comm->current_turn + command_increment;
    if (total_turns < 20) return 0;
    
    LastAdjusted++;
    if (LastAdjusted < 5) return 0;
    
    unsigned int min_avg;
    unsigned int max_high;
    unsigned long* ptr;
    int i;
    unsigned long SyncTurn;
    unsigned int cur_frames;
    min_avg = 10;
    max_high = 30;
    i = 1;
    ptr = PlayerHighLatencyMsec + 1; // player 1, +0x1E8
    do {
        if (Comm->IsPlayerHuman(i)) {
            unsigned long avg = *(ptr - 10);  // PlayerAvgFramesMsec[i]
            if (min_avg <= avg) min_avg = avg;
            if (max_high <= *ptr) max_high = *ptr;
        }
        i++;
        ptr++;
    } while (i <= 9);
    
    unsigned int new_gran = ((min_avg + 5) / 10) * 10;
    if (new_gran > 150) new_gran = 150;
    
    SyncTurn = CurrentBufferGranularity;
    unsigned long gran_diff = abs((int)(new_gran - SyncTurn));
    if (gran_diff < 10) new_gran = SyncTurn;
    
    unsigned int new_frames = max_high / new_gran + 2;
    if (new_frames >= 20) new_frames = 20;
    if (new_frames <= 4) new_frames = 4;
    
    if (new_frames * new_gran < 250) {
        new_frames = 250 / new_gran + 1;
    }
    
    cur_frames = CurrentBufferFrames;
    unsigned long throughput_diff = abs((int)(new_gran * new_frames) - (int)(cur_frames * SyncTurn));
    if (throughput_diff <= 10) return 0;
    
    if (new_gran * new_frames < cur_frames * SyncTurn &&
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
