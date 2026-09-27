#include "../include/com_spd.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buf[152];
static char speedstr[256];
static char Info[256];

RGE_Communications_Speed::RGE_Communications_Speed(TCommunications_Handler* c) {
    Comm = c;
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

RGE_Communications_Speed::~RGE_Communications_Speed() {
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

void RGE_Communications_Speed::SetPlayerTurnSpeed(unsigned int PlayerNo, unsigned char AvgFramesMsec, unsigned char HiLatencyCenti) {
    if (PlayerNo < 1 || PlayerNo > 9) {
        return;
    }
    this->PlayerAvgFramesMsec[PlayerNo] = AvgFramesMsec;
    this->PlayerHighLatencyMsec[PlayerNo] = HiLatencyCenti * 10;
}

void RGE_Communications_Speed::SetActualLatency(unsigned int PlayerNo, unsigned long Msec) {
    if (PlayerNo >= 1 && PlayerNo <= 9) {
        if (Msec < 30)
            Msec = 30;
        if (Msec > 6000)
            Msec = 6000;
        this->ActualLatency[PlayerNo] = Msec;
    }
}

void RGE_Communications_Speed::SetFutureSpeedChange(unsigned int BuffCount, unsigned int BuffGran, unsigned long ExecTurn) {
    if (this->NextLatencyChangeTurn)
        return;
    this->FutureBufferFrames = BuffCount;
    this->FutureBufferGranularity = BuffGran;
    this->NextLatencyChangeTurn = ExecTurn;
}

void RGE_Communications_Speed::EnableSpeedControl(int TorF) {
    this->SpeedControlEnabled = TorF;
}

unsigned int RGE_Communications_Speed::GetBufferGranularity() {
    return this->CurrentBufferGranularity;
}

unsigned long RGE_Communications_Speed::GetAdjustmentCount() {
    return this->AdjustmentCount;
}

unsigned int RGE_Communications_Speed::GetBufferGranularityAdjusted() {
    LastFrameHadTime = 1;
    return CurrentBufferGranularity;
}

unsigned int RGE_Communications_Speed::BufferFramesRemaining() {
    return this->TotalBufferFramesRemaining;
}

unsigned int RGE_Communications_Speed::WaitingOnAcknowledgement() {
    return ++this->SkipFrames;
}

void RGE_Communications_Speed::AdjustLocalSpeed() {
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

void RGE_Communications_Speed::ReloadBufferFrames() {
    this->TurnTSLC->Set();
    this->DroppedFramesTurn = 0;
    this->AdjustLocalSpeed();
    this->TotalBufferFramesRemaining = this->CurrentBufferFrames;
}

unsigned int RGE_Communications_Speed::BufferTimeToUse(unsigned long current_turn) {
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
        if (current_turn > 6) {
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

void RGE_Communications_Speed::Skip() {
    FrameTSLC->Skip();
    LastFrameHadTime = 0;
}

unsigned char RGE_Communications_Speed::GetHighLatencyCenti() {
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

unsigned long RGE_Communications_Speed::GetPlayerLatency(unsigned int PlayerNo) {
    if (PlayerNo < 1 || PlayerNo > 9) {
        return 0;
    }
    return this->ActualLatency[PlayerNo];
}

char* RGE_Communications_Speed::GetLatencyInfo() {
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

char* RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr() {
    unsigned int frames;
    unsigned int granularity;

    frames = this->GetRecommendedBufferFrames();
    granularity = this->GetRecommendedBufferGranularity();
    sprintf(buf, "MeOptimal: Buf=%3d Gran=%3d  Target FPS=%3d Latency=%3d", frames, granularity,
            1000 / static_cast<int>(granularity), granularity * frames);
    return buf;
}

char* RGE_Communications_Speed::GetPlayerSpeedStatusStr(int PlayerNo) {
    unsigned int granularity;
    unsigned int frames;
    char* hi_lo_info;

    if (PlayerNo < 0 || PlayerNo > 9) {
        return 0;
    }

    granularity = this->CurrentBufferGranularity;
    frames = this->CurrentBufferFrames;
    hi_lo_info = this->FrameTSLC->GetHiLoInfo(50);
    sprintf(speedstr, "Buf=%3d / %3d * Gran=%3dms = turn %4dms  %s", this->TotalBufferFramesRemaining, frames, granularity,
            frames * granularity, hi_lo_info);
    return speedstr;
}

char* RGE_Communications_Speed::GetMachineSpeedInfo() {
    char buf[24];

    strcpy(Info, "PlrSpeed> ");
    for (int i = 1; i <= 9; i++) {
        if (Comm->IsPlayerHuman(i)) {
            sprintf(buf, "P#%1d(fr%d lat%d) ", i, PlayerAvgFramesMsec[i], PlayerHighLatencyMsec[i]);
            strcat(Info, buf);
        }
    }

    return Info;
}

unsigned int RGE_Communications_Speed::GetRecommendedBufferFrames() {
    unsigned int high_latency;
    int player;

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
    if (high_latency >= 20) {
        high_latency = 20;
    }
    this->OptimalBufferFrames = high_latency;
    if (high_latency <= 4) {
        high_latency = 4;
    }
    this->OptimalBufferFrames = high_latency + 1;
    return high_latency + 1;
}

unsigned int RGE_Communications_Speed::GetAvgFrameRate() {
    return this->FrameTSLC->GetAvg(50);
}

unsigned int RGE_Communications_Speed::GetRecommendedBufferGranularity() {
    unsigned int granularity;

    granularity = this->FrameTSLC->GetAvg(50);
    this->OptimalBufferGranularity = granularity;
    if (granularity > 150) {
        granularity = 150;
    }
    this->OptimalBufferGranularity = granularity;
    if (granularity < 10) {
        granularity = 10;
    }
    this->OptimalBufferGranularity = granularity;
    return granularity;
}

int RGE_Communications_Speed::AnalyzeGameSpeed(
    unsigned int* NewGranularity, unsigned int* NewBufferFrames,
    int ChangeAlso) {
    unsigned long SyncTurn;
    unsigned int AvgFramesMsec;
    unsigned int HighLatencyMsec;
    unsigned int Granularity;
    unsigned int BufferFrames;
    unsigned int CurrentTurnMsec;
    unsigned int NewTurnMsec;
    unsigned int Difference;

    if (this->Comm->IsHost() == 0) {
        return 0;
    }
    if (this->NextLatencyChangeTurn != 0) {
        return 0;
    }

    SyncTurn = this->Comm->current_turn +
               this->Comm->PlayerOptions.CommandTurnIncrement;
    if (SyncTurn < 20) {
        return 0;
    }

    this->LastAdjusted++;
    if (this->LastAdjusted < 5) {
        return 0;
    }

    AvgFramesMsec = 10;
    HighLatencyMsec = 30;
    for (int player = 1; player <= 9; player++) {
        if (this->Comm->IsPlayerHuman(player) != 0) {
            if (AvgFramesMsec <= this->PlayerAvgFramesMsec[player]) {
                AvgFramesMsec = this->PlayerAvgFramesMsec[player];
            }
            if (HighLatencyMsec <= this->PlayerHighLatencyMsec[player]) {
                HighLatencyMsec = this->PlayerHighLatencyMsec[player];
            }
        }
    }

    Granularity = ((AvgFramesMsec + 5) / 10) * 10;
    if (Granularity > 150) {
        Granularity = 150;
    }

    Difference = abs((int)(Granularity - this->CurrentBufferGranularity));
    if (Difference < 10) {
        Granularity = this->CurrentBufferGranularity;
    }

    BufferFrames = HighLatencyMsec / Granularity + 2;
    if (BufferFrames >= 20) {
        BufferFrames = 20;
    }
    if (BufferFrames <= 4) {
        BufferFrames = 4;
    }
    if (Granularity * BufferFrames < 250) {
        BufferFrames = 250 / Granularity + 1;
    }

    CurrentTurnMsec =
        this->CurrentBufferFrames * this->CurrentBufferGranularity;
    NewTurnMsec = Granularity * BufferFrames;
    Difference = abs((int)(NewTurnMsec - CurrentTurnMsec));
    if (Difference <= 10) {
        return 0;
    }

    if (NewTurnMsec < CurrentTurnMsec && Difference > 100 && this->CurrentBufferFrames > 4) {
        BufferFrames = this->CurrentBufferFrames - 1;
    }

    *NewGranularity = Granularity;
    *NewBufferFrames = BufferFrames;

    if (ChangeAlso != 0 && this->SpeedControlEnabled != 0) {
        this->SetFutureSpeedChange(BufferFrames, Granularity, SyncTurn);
        this->Comm->SendSpeedChange(BufferFrames, Granularity);
    }
    return 1;
}

void RGE_Communications_Speed::SetV1(unsigned long v1) {
    L->Log("Speed set V1=%d", v1);
}

void RGE_Communications_Speed::SetV2(unsigned long v2) {
    L->Log("Speed set V2=%d", v2);
}
