#include "../include/RGE_TimeSinceLastCall.h"
#include "../include/debug_helpers.h"

#include <stdio.h>
#include <string.h>

RGE_TimeSinceLastCall::RGE_TimeSinceLastCall() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480390
    this->lowTSLC = 99999;
    this->highTSLC = 0;
    this->Offset = 0;
    this->cps = 0;

    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/RGE_TSLC.cpp", 0x0D);
    this->FirstCall = now;
    this->Now = now;
    this->LastCall = now;

    for (int i = 0; i < 0x65; ++i) {
        this->aTSLC[i] = 0;
    }
}

RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x004803F0
}

ulong RGE_TimeSinceLastCall::GetAvg(int sample_count) {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480400
    uint sum = 0;

    if (sample_count > 0 && sample_count < 0x65) {
        int offset = this->Offset;
        for (ulong i = 0; i < (ulong)sample_count; ++i) {
            --offset;
            if (offset < 1) {
                offset = 100;
            }
            sum += (uint)this->aTSLC[offset];
            if (sum > 999) {
                this->cps = i;
            }
        }
        return (ulong)(sum / (uint)sample_count);
    }

    return 0;
}

ulong RGE_TimeSinceLastCall::Get() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480460
    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/RGE_TSLC.cpp", 0x56);
    return now - this->LastCall;
}

ulong RGE_TimeSinceLastCall::Set() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480480
    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/RGE_TSLC.cpp", 0x5D);
    const ulong last = this->LastCall;
    if (last == now) {
        return 0;
    }

    this->LastCall = now;
    int offset = this->Offset + 1;
    this->TSLC = now - last;
    this->Offset = offset;
    if (offset > 100) {
        this->Offset = 0;
    }

    this->aTSLC[this->Offset] = this->TSLC;
    const uint tslc = (uint)this->TSLC;

    uint lo = this->lowTSLC;
    if (tslc < lo) {
        lo = tslc;
    }
    this->lowTSLC = lo;

    uint hi = this->highTSLC;
    if (hi < tslc) {
        hi = tslc;
    }
    this->highTSLC = hi;

    return (ulong)tslc;
}

void RGE_TimeSinceLastCall::Skip() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480510
    (void)debug_timeGetTime("C:/msdev/work/age1_x1/RGE_TSLC.cpp", 0x78);
    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/RGE_TSLC.cpp", 0x79);
    this->LastCall = now;
}

char* RGE_TimeSinceLastCall::GetAvgInfo(int sample_count) {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480540
    const ulong avg = this->GetAvg(sample_count);
    sprintf(this->TBuff, "Avg %d / %d", (uint)avg, sample_count);
    return this->TBuff;
}

static void tslc_calc_hilo(int sample_count, int offset, const ulong* samples, uint* out_sum, uint* out_lo, uint* out_hi) {
    uint sum = 0;
    uint lo = 999999;
    uint hi = 0;

    for (int i = 0; i < sample_count; ++i) {
        --offset;
        if (offset < 1) {
            offset = 100;
        }
        const uint v = (uint)samples[offset];
        sum += v;
        if (v < lo) lo = v;
        if (hi < v) hi = v;
    }

    *out_sum = sum;
    *out_lo = lo;
    *out_hi = hi;
}

char* RGE_TimeSinceLastCall::GetHiLoMaxInfo(int sample_count) {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480570
    int original = sample_count;
    uint sum = 0;
    uint lo = 999999;
    uint hi = 0;
    uint max_v = (uint)sample_count;
    uint min_v = (uint)sample_count;

    if (sample_count > 0 && sample_count < 0x65) {
        tslc_calc_hilo(sample_count, this->Offset, this->aTSLC, &sum, &min_v, &max_v);
        sample_count = (int)(sum / (uint)original);
        hi = max_v;
        lo = min_v;
    }

    sprintf(this->TBuff, "<LoLo %d Lo %d < Avg %d / %d > Hi %d HiHi %d", (uint)this->lowTSLC, lo, (uint)sample_count, original,
            hi, (uint)this->highTSLC);
    return this->TBuff;
}

char* RGE_TimeSinceLastCall::GetHiLoInfo(int sample_count) {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480610
    int original = sample_count;
    uint sum = 0;
    uint lo = 999999;
    uint hi = 0;
    uint max_v = (uint)sample_count;
    uint min_v = (uint)sample_count;

    if (sample_count > 0 && sample_count < 0x65) {
        tslc_calc_hilo(sample_count, this->Offset, this->aTSLC, &sum, &min_v, &max_v);
        sample_count = (int)(sum / (uint)original);
        hi = max_v;
        lo = min_v;
    }

    sprintf(this->TBuff, "Lo %d < Avg %d > Hi %d of %d", lo, (uint)sample_count, hi, original);
    return this->TBuff;
}

ulong RGE_TimeSinceLastCall::CPS() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x004806A0
    this->cps = 0;
    (void)this->GetAvg(100);
    return this->cps;
}

ulong RGE_TimeSinceLastCall::GetFirstCall() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x004806C0
    return this->FirstCall;
}

char* RGE_TimeSinceLastCall::GetElapsedFirstCall() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x004806D0
    uint hours = 0;
    uint mins = 0;

    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/RGE_TSLC.cpp", 0xB5);
    this->Now = now;

    uint secs = (uint)((now - this->FirstCall) / 1000);
    if (secs > 0x3B) {
        mins = secs / 0x3C;
        secs = secs % 0x3C;
        if (mins > 0x3B) {
            hours = mins / 0x3C;
            mins = mins % 0x3C;
        }
    }

    sprintf(this->TBuff, "%02ld:%02ld:%02ld", hours, mins, secs);
    return this->TBuff;
}

void RGE_TimeSinceLastCall::Test() {
    // Fully verified. Source of truth: rge_tslc.cpp.decomp @ 0x00480770
    for (int i = 0; i < 100; ++i) {
        this->aTSLC[i] = 10;
    }
}

