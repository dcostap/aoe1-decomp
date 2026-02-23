#include "../include/RGE_Communications_Speed.h"

#include "../include/RGE_TimeSinceLastCall.h"
#include "../include/TCommunications_Handler.h"

#include <stdio.h>
#include <string.h>

namespace {
static char s_self_optimal_speed_str[256];
static char s_player_speed_status_str[256];
static char s_machine_speed_info_str[512];
}

RGE_Communications_Speed::RGE_Communications_Speed(TCommunications_Handler* comm) {
    // Source of truth: com_spd.cpp.decomp @ 0x00432620
    this->Comm = comm;
    this->CurrentBufferGranularity = 0x5A;
    this->OptimalBufferGranularity = 0x5A;
    this->CurrentBufferFrames = 10;
    this->OptimalBufferFrames = 10;
    this->SpeedControlEnabled = 1;
    this->OverheadFactor = 0;
    this->LastAdjusted = 0;
    this->AdjustmentCount = 0;
    this->LastFrameHadTime = 0;
    this->TotalBufferFramesRemaining = 0;
    this->TimeSinceLastBuffer = 0;
    this->TargetTurnLengthMsec = 500;
    this->RealTimePassed = 0;
    this->BufferTimePassed = 0;
    this->DroppedFrames = 0;
    this->DroppedFramesTurn = 0;
    this->NextLatencyChangeTurn = 0;
    this->FutureBufferFrames = 0;
    this->FutureBufferGranularity = 0;

    for (int i = 0; i < 10; ++i) {
        this->ActualLatency[i] = 0x1E;
        this->AverageTSLC[i] = 0;
        this->RequestFasterOrSlower[i] = 0;
        this->PlayerAvgFramesMsec[i] = 0;
        this->PlayerHighLatencyMsec[i] = 0;
        this->PlayerOptimalFrames[i] = 0;
        this->PlayerOptimalGranularity[i] = 0;
    }

    this->HighestLatencyMsec = 500;

    this->FrameTSLC = new RGE_TimeSinceLastCall();
    this->TurnTSLC = new RGE_TimeSinceLastCall();
}

RGE_Communications_Speed::~RGE_Communications_Speed() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432780
    delete this->FrameTSLC;
    this->FrameTSLC = nullptr;
    delete this->TurnTSLC;
    this->TurnTSLC = nullptr;
}

void RGE_Communications_Speed::SetPlayerTurnSpeed(uint player, uchar avg_frames_msec, uchar high_latency_centi) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x004327C0
    if (player != 0 && player < 10) {
        this->PlayerAvgFramesMsec[player] = (ulong)avg_frames_msec;
        this->PlayerHighLatencyMsec[player] = (ulong)high_latency_centi * 10;
    }
}

void RGE_Communications_Speed::SetActualLatency(uint player, ulong latency_msec) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432800
    if (player != 0 && player < 10) {
        if (latency_msec < 0x1E) latency_msec = 0x1E;
        if (latency_msec > 6000) latency_msec = 6000;
        this->ActualLatency[player] = (uint)latency_msec;
    }
}

void RGE_Communications_Speed::SetFutureSpeedChange(uint future_frames, uint future_granularity, ulong change_turn) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432840
    if (this->NextLatencyChangeTurn == 0) {
        this->FutureBufferFrames = future_frames;
        this->FutureBufferGranularity = future_granularity;
        this->NextLatencyChangeTurn = change_turn;
    }
}

void RGE_Communications_Speed::EnableSpeedControl(int enable) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432870
    this->SpeedControlEnabled = enable;
}

uint RGE_Communications_Speed::GetBufferGranularity() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432880
    return this->CurrentBufferGranularity;
}

ulong RGE_Communications_Speed::GetAdjustmentCount() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432890
    return this->AdjustmentCount;
}

uint RGE_Communications_Speed::GetBufferGranularityAdjusted() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x004328A0
    this->LastFrameHadTime = 1;
    return this->CurrentBufferGranularity;
}

uint RGE_Communications_Speed::BufferFramesRemaining() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x004328C0
    return this->TotalBufferFramesRemaining;
}

uint RGE_Communications_Speed::WaitingOnAcknowledgement() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x004328D0
    const uint next = this->SkipFrames + 1;
    this->SkipFrames = next;
    return next;
}

void RGE_Communications_Speed::AdjustLocalSpeed() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x004328E0
    if (this->NextLatencyChangeTurn != 0) {
        this->LastAdjusted = 0;
        if (this->Comm != nullptr && this->NextLatencyChangeTurn <= this->Comm->current_turn) {
            this->NextLatencyChangeTurn = 0;
            this->AdjustmentCount += 1;
            this->CurrentBufferFrames = this->FutureBufferFrames;
            this->CurrentBufferGranularity = this->FutureBufferGranularity;
            this->FutureBufferFrames = 0;
            this->FutureBufferGranularity = 0;
        }
    }
}

void RGE_Communications_Speed::ReloadBufferFrames() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432940
    if (this->TurnTSLC != nullptr) {
        (void)this->TurnTSLC->Set();
    }
    this->DroppedFramesTurn = 0;
    this->AdjustLocalSpeed();
    this->TotalBufferFramesRemaining = this->CurrentBufferFrames;
}

uint RGE_Communications_Speed::BufferTimeToUse(ulong frame_no) {
    // Source of truth: com_spd.cpp.decomp @ 0x00432970
    if (this->FrameTSLC != nullptr) {
        if (this->LastFrameHadTime == 0) {
            this->FrameTSLC->Skip();
        } else {
            (void)this->FrameTSLC->Set();
        }
    }

    this->LastFrameHadTime = 0;

    if (this->TotalBufferFramesRemaining == 0) {
        this->LastFrameHadTime = 0;
        return 0;
    }

    if (this->TurnTSLC != nullptr) {
        this->RealTimePassed = this->TurnTSLC->Get();
    } else {
        this->RealTimePassed = 0;
    }

    if (this->Comm != nullptr) {
        if (this->Comm->AllPlayersAcknowledged() != 0) {
            this->AllAcknowledgedBuffersRemaining += this->TotalBufferFramesRemaining;
        }
    }

    const uint buffer_time = (this->CurrentBufferFrames - this->TotalBufferFramesRemaining) * this->CurrentBufferGranularity;
    this->BufferTimePassed = buffer_time;

    if (this->OverheadFactor + this->RealTimePassed < buffer_time) {
        if (frame_no > 6) {
            this->DroppedFrames += 1;
            this->DroppedFramesTurn += 1;
        }
        this->LastFrameHadTime = 0;
        return 0;
    }

    this->LastFrameHadTime = 1;
    this->TotalBufferFramesRemaining -= 1;
    return this->CurrentBufferGranularity;
}

void RGE_Communications_Speed::Skip() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432A70
    if (this->FrameTSLC != nullptr) {
        this->FrameTSLC->Skip();
    }
    this->LastFrameHadTime = 0;
}

uchar RGE_Communications_Speed::GetHighLatencyCenti() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432A90
    uint highest = 0;
    uint player = 1;
    do {
        if (this->Comm != nullptr && this->Comm->IsPlayerHuman(player) != 0) {
            if (highest <= this->ActualLatency[player]) {
                highest = this->ActualLatency[player];
            }
        }
        ++player;
    } while (player < 10);

    this->HighestLatencyMsec = (ulong)highest;
    uint centi = (highest + 5) / 10;
    if (centi < 2) centi = 1;
    if (centi > 0xFE) centi = 0xFF;
    return (uchar)centi;
}

ulong RGE_Communications_Speed::GetPlayerLatency(uint player) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432B00
    if (player != 0 && player < 10) {
        return this->ActualLatency[player];
    }
    return 0;
}

char* RGE_Communications_Speed::GetLatencyInfo() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432B20
    strcpy(this->TBuff, "Latency> ");

    for (uint p = 1; p <= 9; ++p) {
        if (this->Comm != nullptr && this->Comm->IsPlayerHuman(p) != 0) {
            char buf[32];
            sprintf(buf, "P%d=%d,", p, (int)this->ActualLatency[p]);
            strncat(this->TBuff, buf, sizeof(this->TBuff) - strlen(this->TBuff) - 1);
        }
    }

    return this->TBuff;
}

char* RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432BD0
    const uint frames = this->GetRecommendedBufferFrames();
    const uint gran = this->GetRecommendedBufferGranularity();

    const int fps = (gran != 0) ? (int)(1000 / (int)gran) : 0;
    sprintf(s_self_optimal_speed_str, "MeOptimal: Buf %3d Gran %3d  Tar %d  %d", frames, gran, fps, gran * frames);
    return s_self_optimal_speed_str;
}

char* RGE_Communications_Speed::GetPlayerSpeedStatusStr(int player) {
    // Source of truth: com_spd.cpp.decomp @ 0x00432C10
    if (player > -1 && player < 10) {
        const uint gran = this->CurrentBufferGranularity;
        const uint frames = this->CurrentBufferFrames;
        const char* hilo = (this->FrameTSLC != nullptr) ? this->FrameTSLC->GetHiLoInfo(0x32) : "";
        sprintf(s_player_speed_status_str, "Buf %3d/%3d  Gran %3dms  turn=%d  %s", this->TotalBufferFramesRemaining, frames, gran,
                frames * gran, hilo);
        return s_player_speed_status_str;
    }
    return nullptr;
}

char* RGE_Communications_Speed::GetMachineSpeedInfo() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432C70
    strcpy(s_machine_speed_info_str, "PlrSpeed> ");

    for (uint p = 1; p <= 9; ++p) {
        if (this->Comm != nullptr && this->Comm->IsPlayerHuman(p) != 0) {
            char buf[48];
            sprintf(buf, "P%1d fr=%d lat=%d,", p, (int)this->PlayerAvgFramesMsec[p], (int)this->PlayerHighLatencyMsec[p]);
            strncat(s_machine_speed_info_str, buf, sizeof(s_machine_speed_info_str) - strlen(s_machine_speed_info_str) - 1);
        }
    }

    return s_machine_speed_info_str;
}

uint RGE_Communications_Speed::GetRecommendedBufferFrames() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432D20
    uint highest = 0;
    for (uint p = 1; p < 10; ++p) {
        if (this->Comm != nullptr && this->Comm->IsPlayerHuman(p) != 0) {
            if (highest <= this->ActualLatency[p]) {
                highest = this->ActualLatency[p];
            }
        }
    }

    uint frames = (this->CurrentBufferGranularity != 0) ? (highest / this->CurrentBufferGranularity) : 0;
    this->OptimalBufferFrames = frames;
    if (frames > 0x13) frames = 0x14;
    this->OptimalBufferFrames = frames;
    if (frames < 5) frames = 4;
    this->OptimalBufferFrames = frames + 1;
    return frames + 1;
}

uint RGE_Communications_Speed::GetAvgFrameRate() {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432D90
    return (this->FrameTSLC != nullptr) ? (uint)this->FrameTSLC->GetAvg(0x32) : 0;
}

uint RGE_Communications_Speed::GetRecommendedBufferGranularity() {
    // Source of truth: com_spd.cpp.decomp @ 0x00432DA0
    uint gran = (this->FrameTSLC != nullptr) ? (uint)this->FrameTSLC->GetAvg(0x32) : 0;
    this->OptimalBufferGranularity = gran;
    if (gran > 0x96) gran = 0x96;
    this->OptimalBufferGranularity = gran;
    if (gran < 10) gran = 10;
    this->OptimalBufferGranularity = gran;
    return gran;
}

int RGE_Communications_Speed::AnalyzeGameSpeed(uint* out_granularity, uint* out_frames, int apply_change) {
    // Source of truth: com_spd.cpp.decomp @ 0x00432DE0
    if (this->Comm == nullptr || this->Comm->IsHost() == 0) {
        return 0;
    }
    if (this->NextLatencyChangeTurn != 0) {
        return 0;
    }

    const uint change_turn = (uint)this->Comm->current_turn + (uint)this->Comm->PlayerOptions.CommandTurnIncrement;
    if (change_turn < 0x14) {
        return 0;
    }

    this->LastAdjusted += 1;
    if (this->LastAdjusted < 5) {
        return 0;
    }

    uint max_frames = 10;
    uint max_latency = 0x1E;
    for (uint p = 1; p < 10; ++p) {
        if (this->Comm->IsPlayerHuman(p) != 0) {
            if (max_frames <= (uint)this->PlayerAvgFramesMsec[p]) {
                max_frames = (uint)this->PlayerAvgFramesMsec[p];
            }
            if (max_latency <= (uint)this->PlayerHighLatencyMsec[p]) {
                max_latency = (uint)this->PlayerHighLatencyMsec[p];
            }
        }
    }

    uint new_gran = ((max_frames + 5) / 10) * 10;
    if (new_gran > 0x96) new_gran = 0x96;

    const uint cur_gran = this->CurrentBufferGranularity;
    const int diff = (int)new_gran - (int)cur_gran;
    if (diff < 10 && diff > -10) {
        new_gran = cur_gran;
    }

    uint new_frames = (new_gran != 0) ? (max_latency / new_gran + 2) : 0;
    if (new_frames > 0x13) new_frames = 0x14;
    if (new_frames < 5) new_frames = 4;

    if (new_gran * new_frames < 0xFA) {
        new_frames = (uint)(0xFA / (unsigned long long)new_gran) + 1;
    }

    const uint cur_frames = this->CurrentBufferFrames;
    const uint delta = new_gran * new_frames - cur_frames * cur_gran;
    const uint abs_delta = (uint)((int)delta < 0 ? -(int)delta : (int)delta);
    if (abs_delta < 0x0B) {
        return 0;
    }

    if ((new_gran * new_frames < cur_frames * cur_gran) && (abs_delta > 100) && (cur_frames > 4)) {
        new_frames = cur_frames - 1;
    }

    if (out_granularity != nullptr) *out_granularity = new_gran;
    if (out_frames != nullptr) *out_frames = new_frames;

    if (apply_change != 0 && this->SpeedControlEnabled != 0) {
        this->SetFutureSpeedChange(new_frames, new_gran, (ulong)change_turn);
        this->Comm->SendSpeedChange(new_frames, new_gran);
    }

    return 1;
}

void RGE_Communications_Speed::SetV1(ulong /*v*/) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432FB0
}

void RGE_Communications_Speed::SetV2(ulong /*v*/) {
    // Fully verified. Source of truth: com_spd.cpp.decomp @ 0x00432FD0
}

