// VA: 0053D200, dump_vismap_log, 328 bytes
// Source: visible.cpp lines 1199-1249
// FLAGS: default
// ACCEPTED_DRIFT: only the final 14-byte epilogue differs (pop ebx/esi order vs fclose call).
// First 314 bytes (95.7%) are EXACT - switch, interleaved mov/push, loop, indexing all match.
// VC5 register scheduling: original pops ebx/esi before fclose, our VC5 does after.

#include <stddef.h>
#include <stdio.h>

extern int VCALL_LOG_HEAD;    // 58CDD8h
extern int VCALL_LOG_TAIL;    // 58CDDCh

#define VISLOG_BASE 0x87D808

void __cdecl dump_vismap_log()
{
    int done = 0;
    FILE* f = fopen("c:\\aoeexlog.txt", "w");
    
    if (VCALL_LOG_HEAD < 0) {
        fprintf(f, "NULL LOG\n");
        fclose(f);
        return;
    }
    
    int idx = VCALL_LOG_TAIL;
    if (idx < 0) {
        idx = 0;
    }
    
    do {
        int esi = idx * 36;
        int action = *(int*)(VISLOG_BASE + 8 + esi);
        
        switch (action) {
        case 1:
            fprintf(f, "EXPLORE     ");
            break;
        case 2:
            fprintf(f, "EXPLORE SQ  ");
            break;
        case 3:
            fprintf(f, "UNEXPLORE   ");
            break;
        case 4:
            fprintf(f, "UNEXPLORE SQ");
            break;
        case 5:
            fprintf(f, "SET ALL     ");
            break;
        case 6:
            fprintf(f, "EXPLORE ALL ");
            break;
        default:
            fprintf(f, "*ERROR* Undef Action = %d ", action);
            break;
        }
        
        fprintf(f,
            " wt = %d, plyr = %d, id = %d, x1=%d, y1=%d, x2=%d, y2=%d, wt=%d",
            *(int*)(VISLOG_BASE + 0 + esi),
            *(int*)(VISLOG_BASE + 4 + esi),
            *(int*)(VISLOG_BASE + 0xC + esi),
            *(int*)(VISLOG_BASE + 0x10 + esi),
            *(int*)(VISLOG_BASE + 0x14 + esi),
            *(int*)(VISLOG_BASE + 0x18 + esi),
            *(int*)(VISLOG_BASE + 0x1C + esi),
            *(int*)(VISLOG_BASE + 0x20 + esi));
        
        if (idx == VCALL_LOG_HEAD) {
            done = 1;
        }
        
        idx++;
        if (idx >= 0x400) {
            idx = 0;
        }
    } while (!done);
    
    fclose(f);
}
