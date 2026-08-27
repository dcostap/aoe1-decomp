#include "../include/rge_tslc.h"

#include <stdio.h>

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

RGE_TimeSinceLastCall::RGE_TimeSinceLastCall()
{
    lowTSLC = 99999;
    highTSLC = 0;
    Offset = 0;
    cps = 0;

    unsigned long time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 13);
    FirstCall = time;
    Now = time;
    LastCall = time;

    for (int i = 0; i < 101; i++)
        aTSLC[i] = 0;
}

RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall()
{
}

unsigned long RGE_TimeSinceLastCall::GetAvg(int count)
{
    unsigned long sum = 0;

    if (count >= 1 && count <= 100) {
        int index = Offset;

        for (int i = 0; i < count; i++) {
            index--;
            if (index <= 0)
                index = 100;

            sum += aTSLC[index];
            if (sum >= 1000)
                cps = i;
        }

        return sum / count;
    }

    return 0;
}

unsigned long RGE_TimeSinceLastCall::Get()
{
    return debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 86) - LastCall;
}

unsigned long RGE_TimeSinceLastCall::Set()
{
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 93);
    if (LastCall == now)
        return 0;

    unsigned long old = LastCall;
    TSLC = now - old;
    LastCall = now;

    Offset++;
    if (Offset > 100)
        Offset = 0;

    aTSLC[Offset] = TSLC;

    if (TSLC < lowTSLC)
        lowTSLC = TSLC;
    if (TSLC > highTSLC)
        highTSLC = TSLC;

    return TSLC;
}

void RGE_TimeSinceLastCall::Skip()
{
    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 120);
    LastCall = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 121);
}

char* RGE_TimeSinceLastCall::GetAvgInfo(int count)
{
    unsigned long average = GetAvg(count);
    sprintf(TBuff, "Avg %d / %d", average, count);
    return TBuff;
}

char* RGE_TimeSinceLastCall::GetHiLoMaxInfo(int count)
{
    unsigned long sum = 0;
    unsigned long high = 0;
    unsigned long low = 999999;
    unsigned long average;
    unsigned long maximum;
    unsigned long minimum;
    int original_count = count;

    // ORIGINAL BUG: Invalid counts leave these automatic values unset, but the
    // shipped function still reads them through sprintf below. The executable
    // obtains all three values from the incoming count home.
    if (count >= 1 && count <= 100) {
        int index = Offset;

        if (count > 0) {
            int remaining = count;
            do {
                index--;
                if (index <= 0)
                    index = 100;

                unsigned long value = aTSLC[index];
                sum += value;
                if (value < low)
                    low = value;
                if (value > high)
                    high = value;

                remaining--;
            } while (remaining != 0);
        }

        average = sum / original_count;
        minimum = low;
        maximum = high;
    }

    sprintf(TBuff, "(LoLo %d) Lo=%d < Avg=%d / %d > Hi=%d  (HiHi %d)",
            lowTSLC, minimum, average, original_count, maximum, highTSLC);
    return TBuff;
}

char* RGE_TimeSinceLastCall::GetHiLoInfo(int count)
{
    unsigned long sum = 0;
    unsigned long high = 0;
    unsigned long low = 999999;
    unsigned long average;
    unsigned long maximum;
    unsigned long minimum;

    // ORIGINAL BUG: Invalid counts leave these automatic values unset, but the
    // shipped function still reads them through sprintf below. The executable
    // obtains all three values from the incoming count home.
    if (count >= 1 && count <= 100) {
        int index = Offset;

        if (count > 0) {
            int remaining = count;
            do {
                index--;
                if (index <= 0)
                    index = 100;

                unsigned long value = aTSLC[index];
                sum += value;
                if (value < low)
                    low = value;
                if (value > high)
                    high = value;

                remaining--;
            } while (remaining != 0);
        }

        average = sum / count;
        minimum = low;
        maximum = high;
    }

    sprintf(TBuff, "Lo=%d < Avg=%d > Hi=%d of %d",
            minimum, average, maximum, count);
    return TBuff;
}

unsigned long RGE_TimeSinceLastCall::CPS()
{
    cps = 0;
    GetAvg(100);
    return cps;
}

unsigned long RGE_TimeSinceLastCall::GetFirstCall()
{
    return FirstCall;
}

char* RGE_TimeSinceLastCall::GetElapsedFirstCall()
{
    long hours = 0;
    long minutes = 0;
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 181);
    Now = now;
    int seconds = (int)((now - FirstCall) / 1000);

    if (seconds > 59) {
        minutes = seconds / 60;
        seconds -= minutes * 60;

        if (minutes > 59) {
            hours = minutes / 60;
            minutes -= hours * 60;
        }
    }

    sprintf(TBuff, "%02ld:%02ld:%02ld", hours, minutes, seconds);
    return TBuff;
}

void RGE_TimeSinceLastCall::Test()
{
    for (int i = 0; i < 100; i++)
        aTSLC[i] = 10;
}
