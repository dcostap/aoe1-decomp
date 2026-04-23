extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

extern int do_debug_timeGetTime;
extern int debug_timeGetTime_on;
extern unsigned long debug_timeGetTime_cnt;
extern unsigned long debug_timeGetTime_interval;
extern unsigned long debug_timeGetTime_time;

unsigned long __cdecl debug_timeGetTime(char* param_1, int param_2) {
    if (do_debug_timeGetTime != 0 && debug_timeGetTime_on != 0) {
        debug_timeGetTime_cnt = debug_timeGetTime_cnt + 1;
        if (debug_timeGetTime_cnt == debug_timeGetTime_interval) {
            debug_timeGetTime_cnt = 0;
            debug_timeGetTime_time = debug_timeGetTime_time + 1;
        }
        return debug_timeGetTime_time;
    }
    return timeGetTime();
}
