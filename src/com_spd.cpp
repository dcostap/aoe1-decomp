/* Authentic C++ source module for C:\\msdev\\work\\age1_x1\\com_spd.cpp. */
// The definitions below follow the 27-owner PDB source order.
#include "../include/com_spd.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char s_self_player_optimal_speed_text[152];
static char s_player_speed_status_text[256];
static char s_machine_speed_info_text[256];

RGE_Communications_Speed::RGE_Communications_Speed(
    TCommunications_Handler* handler)
{
    // BINARY NOTE: The constructor initializes ten player records, then
    // allocates FrameTSLC before TurnTSLC.
    Comm = handler;
    CurrentBufferGranularity = 90;
    OptimalBufferGranularity = 90;
    CurrentBufferFrames = 10;
    OptimalBufferFrames = 10;
    SpeedControlEnabled = 1;
    OverheadFactor = 0;
    LastAdjusted = 0;
    AdjustmentCount = 0;
    LastFrameHadTime = 0;
    TotalBufferFramesRemaining = 0;
    TimeSinceLastBuffer = 0;
    TargetTurnLengthMsec = 500;
    RealTimePassed = 0;
    BufferTimePassed = 0;
    DroppedFrames = 0;
    DroppedFramesTurn = 0;
    NextLatencyChangeTurn = 0;
    FutureBufferFrames = 0;
    FutureBufferGranularity = 0;

    for (int i = 0; i < 10; i++) {
        ActualLatency[i] = 30;
        AverageTSLC[i] = 0;
        RequestFasterOrSlower[i] = 0;
        PlayerAvgFramesMsec[i] = 0;
        PlayerHighLatencyMsec[i] = 0;
    }

    HighestLatencyMsec = 500;

    FrameTSLC = new RGE_TimeSinceLastCall();
    TurnTSLC = new RGE_TimeSinceLastCall();
}

RGE_Communications_Speed::~RGE_Communications_Speed()
{
    RGE_TimeSinceLastCall* tslc;

    tslc = this->FrameTSLC;
    if (tslc != 0) {
        delete tslc;
    }

    tslc = this->TurnTSLC;
    if (tslc != 0) {
        delete tslc;
    }
}

void RGE_Communications_Speed::SetPlayerTurnSpeed(
    unsigned int player, unsigned char avg_frames_msec,
    unsigned char high_latency)
{
    if (player < 1 || player > 9) {
        return;
    }
    this->PlayerAvgFramesMsec[player] = avg_frames_msec;
    this->PlayerHighLatencyMsec[player] = high_latency * 10;
}

void RGE_Communications_Speed::SetActualLatency(
    unsigned int player, unsigned long latency)
{
    if (player >= 1 && player <= 9) {
        if (latency < 30)
            latency = 30;
        if (latency > 6000)
            latency = 6000;
        this->ActualLatency[player] = latency;
    }
}

void RGE_Communications_Speed::SetFutureSpeedChange(
    unsigned int buffer_frames, unsigned int granularity,
    unsigned long turn_change)
{
    if (this->NextLatencyChangeTurn)
        return;
    this->FutureBufferFrames = buffer_frames;
    this->FutureBufferGranularity = granularity;
    this->NextLatencyChangeTurn = turn_change;
}

void RGE_Communications_Speed::EnableSpeedControl(int value)
{
    this->SpeedControlEnabled = value;
}

unsigned int RGE_Communications_Speed::GetBufferGranularity()
{
    return this->CurrentBufferGranularity;
}

unsigned long RGE_Communications_Speed::GetAdjustmentCount()
{
    return this->AdjustmentCount;
}

unsigned int RGE_Communications_Speed::GetBufferGranularityAdjusted()
{
    LastFrameHadTime = 1;
    return CurrentBufferGranularity;
}

unsigned int RGE_Communications_Speed::BufferFramesRemaining()
{
    return this->TotalBufferFramesRemaining;
}

unsigned int RGE_Communications_Speed::WaitingOnAcknowledgement()
{
    return ++this->SkipFrames;
}

void RGE_Communications_Speed::AdjustLocalSpeed()
{
    unsigned long next_latency_change_turn;
    TCommunications_Handler* comm;
    unsigned int adjustment_count;

    next_latency_change_turn = this->NextLatencyChangeTurn;
    if (next_latency_change_turn == 0) {
        return;
    }

    comm = this->Comm;
    this->LastAdjusted = 0;
    if (comm->current_turn < next_latency_change_turn) {
        return;
    }

    adjustment_count = this->AdjustmentCount;
    this->NextLatencyChangeTurn = 0;
    adjustment_count++;
    this->AdjustmentCount = adjustment_count;
    this->CurrentBufferFrames = this->FutureBufferFrames;
    this->CurrentBufferGranularity = this->FutureBufferGranularity;
    this->FutureBufferFrames = 0;
    this->FutureBufferGranularity = 0;
}

void RGE_Communications_Speed::ReloadBufferFrames()
{
    this->TurnTSLC->Set();
    this->DroppedFramesTurn = 0;
    this->AdjustLocalSpeed();
    this->TotalBufferFramesRemaining = this->CurrentBufferFrames;
}

unsigned int RGE_Communications_Speed::BufferTimeToUse(unsigned long value)
{
    if (this->LastFrameHadTime != 0) {
        this->FrameTSLC->Set();
    } else {
        this->FrameTSLC->Skip();
    }

    this->LastFrameHadTime = 0;
    if (this->TotalBufferFramesRemaining <= 0) {
        this->LastFrameHadTime = 0;
        return 0;
    }

    this->RealTimePassed = this->TurnTSLC->Get();
    if (this->Comm->AllPlayersAcknowledged() != 0) {
        this->AllAcknowledgedBuffersRemaining =
            this->AllAcknowledgedBuffersRemaining +
            this->TotalBufferFramesRemaining;
    }

    this->BufferTimePassed =
        (this->CurrentBufferFrames - this->TotalBufferFramesRemaining) *
        this->CurrentBufferGranularity;
    if (this->OverheadFactor + this->RealTimePassed < this->BufferTimePassed) {
        if (value > 6) {
            this->DroppedFrames = this->DroppedFrames + 1;
            this->DroppedFramesTurn = this->DroppedFramesTurn + 1;
        }
        this->LastFrameHadTime = 0;
        return 0;
    }

    this->LastFrameHadTime = 1;
    this->TotalBufferFramesRemaining = this->TotalBufferFramesRemaining - 1;
    return this->CurrentBufferGranularity;
}

void RGE_Communications_Speed::Skip()
{
    FrameTSLC->Skip();
    LastFrameHadTime = 0;
}

unsigned char RGE_Communications_Speed::GetHighLatencyCenti()
{
    unsigned int high_latency;
    unsigned int player;
    unsigned int* latency;

    high_latency = 0;
    player = 1;
    latency = &this->ActualLatency[1];
    do {
        if (this->Comm->IsPlayerHuman(player) != 0) {
            if (high_latency <= *latency) {
                high_latency = *latency;
            }
        }
        player++;
        latency++;
    } while (player <= 9);

    this->HighestLatencyMsec = high_latency;
    high_latency = (high_latency + 5) / 10;
    if (high_latency <= 1) {
        high_latency = 1;
    }
    if (high_latency >= 0xFF) {
        high_latency = 0xFF;
    }
    return static_cast<unsigned char>(high_latency);
}

unsigned long RGE_Communications_Speed::GetPlayerLatency(unsigned int player)
{
    if (player < 1 || player > 9) {
        return 0;
    }
    return this->ActualLatency[player];
}

char* RGE_Communications_Speed::GetLatencyInfo()
{
    char buf[24];

    strcpy(this->TBuff, "Latency> ");
    for (unsigned int i = 1; i <= 9; i++) {
        if (this->Comm->IsPlayerHuman(i)) {
            sprintf(buf, "P%d=%d ", i, this->ActualLatency[i]);
            strcat(this->TBuff, buf);
        }
    }
    return this->TBuff;
}

char* RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr()
{
    unsigned int frames;
    unsigned int granularity;

    frames = this->GetRecommendedBufferFrames();
    granularity = this->GetRecommendedBufferGranularity();
    sprintf(
        s_self_player_optimal_speed_text,
        "MeOptimal: Buf=%3d Gran=%3d  Target FPS=%3d Latency=%3d",
        frames,
        granularity,
        1000 / static_cast<int>(granularity),
        granularity * frames
    );
    return s_self_player_optimal_speed_text;
}

char* RGE_Communications_Speed::GetPlayerSpeedStatusStr(int player)
{
    unsigned int granularity;
    unsigned int frames;
    char* hi_lo_info;

    if (player < 0 || player > 9) {
        return 0;
    }

    granularity = this->CurrentBufferGranularity;
    frames = this->CurrentBufferFrames;
    hi_lo_info = this->FrameTSLC->GetHiLoInfo(0x32);
    sprintf(
        s_player_speed_status_text,
        "Buf=%3d / %3d * Gran=%3dms = turn %4dms  %s",
        this->TotalBufferFramesRemaining,
        frames,
        granularity,
        frames * granularity,
        hi_lo_info
    );
    return s_player_speed_status_text;
}

char* RGE_Communications_Speed::GetMachineSpeedInfo()
{
    char buf[24];

    strcpy(s_machine_speed_info_text, "PlrSpeed> ");
    for (int i = 1; i <= 9; i++) {
        if (Comm->IsPlayerHuman(i)) {
            sprintf(buf, "P#%1d(fr%d lat%d) ", i,
                    PlayerAvgFramesMsec[i], PlayerHighLatencyMsec[i]);
            strcat(s_machine_speed_info_text, buf);
        }
    }

    return s_machine_speed_info_text;
}

unsigned int RGE_Communications_Speed::GetRecommendedBufferFrames()
{
    unsigned int high_latency;
    unsigned int player;

    high_latency = 0;
    for (player = 1; player <= 9; ++player) {
        if (this->Comm->IsPlayerHuman(player) != 0) {
            if (high_latency <= this->ActualLatency[player]) {
                high_latency = this->ActualLatency[player];
            }
        }
    }

    high_latency = high_latency / this->CurrentBufferGranularity;
    this->OptimalBufferFrames = high_latency;
    if (high_latency >= 0x14) {
        high_latency = 0x14;
    }
    this->OptimalBufferFrames = high_latency;
    if (high_latency <= 4) {
        high_latency = 4;
    }
    this->OptimalBufferFrames = high_latency + 1;
    return high_latency + 1;
}

unsigned int RGE_Communications_Speed::GetAvgFrameRate()
{
    return this->FrameTSLC->GetAvg(0x32);
}

unsigned int RGE_Communications_Speed::GetRecommendedBufferGranularity()
{
    unsigned int granularity;

    granularity = this->FrameTSLC->GetAvg(0x32);
    this->OptimalBufferGranularity = granularity;
    if (granularity > 0x96) {
        granularity = 0x96;
    }
    this->OptimalBufferGranularity = granularity;
    if (granularity < 10) {
        granularity = 10;
    }
    this->OptimalBufferGranularity = granularity;
    return granularity;
}

int RGE_Communications_Speed::AnalyzeGameSpeed(
    unsigned int* out_granularity, unsigned int* out_frames, int param_3)
{
    if (!Comm->IsHost()) return 0;
    if (NextLatencyChangeTurn != 0) return 0;

    unsigned long total_turns = Comm->current_turn +
                                 Comm->PlayerOptions.CommandTurnIncrement;
    if (total_turns < 20) return 0;

    LastAdjusted++;
    if (LastAdjusted < 5) return 0;

    unsigned int min_avg;
    unsigned int max_high;
    int i;
    unsigned long SyncTurn;
    unsigned int cur_frames;
    min_avg = 10;
    max_high = 30;
    for (i = 1; i <= 9; ++i) {
        if (Comm->IsPlayerHuman(i)) {
            unsigned long avg = PlayerAvgFramesMsec[i];
            if (min_avg <= avg) min_avg = avg;
            if (max_high <= PlayerHighLatencyMsec[i]) {
                max_high = PlayerHighLatencyMsec[i];
            }
        }
    }

    unsigned int new_gran = ((min_avg + 5) / 10) * 10;
    if (new_gran > 150) new_gran = 150;

    SyncTurn = CurrentBufferGranularity;
    unsigned long gran_diff = abs(static_cast<int>(new_gran - SyncTurn));
    if (gran_diff < 10) new_gran = SyncTurn;

    unsigned int new_frames = max_high / new_gran + 2;
    if (new_frames >= 20) new_frames = 20;
    if (new_frames <= 4) new_frames = 4;

    if (new_gran * new_frames < 250) {
        new_frames = 250 / new_gran + 1;
    }

    cur_frames = CurrentBufferFrames;
    unsigned long throughput_diff =
        abs(static_cast<int>(new_gran * new_frames) -
            static_cast<int>(cur_frames * SyncTurn));
    if (throughput_diff <= 10) return 0;

    if (new_gran * new_frames < cur_frames * SyncTurn &&
        throughput_diff > 100 && cur_frames > 4) {
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

void RGE_Communications_Speed::SetV1(unsigned long value)
{
    L->Log("Speed set V1=%d", value);
}

void RGE_Communications_Speed::SetV2(unsigned long value)
{
    L->Log("Speed set V2=%d", value);
}
