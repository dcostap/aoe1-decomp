// VA: 00432B20 RGE_Communications_Speed::GetLatencyInfo
// com_spd.cpp lines 328-343

// attempt 1: builds latency string for each human player
// 167/167 exact size, 123 diff bytes
// Manual string ops codegen basin (strlen/memcpy/sprintf pattern differs)
// Left in scratch.

#include <string.h>
#include <stdio.h>
#include "../../include/com_spd_context.h"

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
