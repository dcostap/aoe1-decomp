// VA: 00432C70 RGE_Communications_Speed::GetMachineSpeedInfo
// com_spd.cpp lines 377-395
// 2026-05-24 Boss pass: MATCH. Fixes: model global output and string literals as absolute-address macros, use 24-byte local buffer, loop players 1..9, and pass `buf` (not decompiler-labeled `buf+4`) to sprintf/strcat; transient vararg pushes make it appear as `[esp+20]/[esp+28]` in asm.

#include <string.h>
#include <stdio.h>
#include "../../include/com_spd_context.h"

#define global_buf ((char*)0x0062D070)
#define S_PLRSPEED ((char*)0x005836A8)
#define S_PLAYERFMT ((char*)0x00583694)

char* RGE_Communications_Speed::GetMachineSpeedInfo() {
    char buf[24];
    strcpy(global_buf, S_PLRSPEED);

    for (int i = 1; i <= 9; i++) {
        if (Comm->IsPlayerHuman(i)) {
            sprintf(buf, S_PLAYERFMT, i, PlayerAvgFramesMsec[i], PlayerHighLatencyMsec[i]);
            strcat(global_buf, buf);
        }
    }

    return global_buf;
}
