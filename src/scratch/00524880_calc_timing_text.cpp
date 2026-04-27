// VA: 00524880 TRIBE_Game::calc_timing_text (476 B)
// PDB source: tribegam.cpp
// Packet-grounded: format timing stats string with many division/sprintf calls

extern int sprintf(char* buf, const char* fmt, ...);
extern unsigned long debug_timeGetTime(const char* file, int line);

int debug_init_done;  // 0x86BCD0
int debug_init_time;  // 0x86BCD8

int TRIBE_Game_calc_timing_text(void* self, char* buf)
{
    if (!debug_init_done) {
        debug_init_done = 1;
        debug_init_time = debug_timeGetTime("tribegam.cpp", 0x7D4);
    }
    
    debug_init_time = debug_timeGetTime("tribegam.cpp", 0x7D6);
    
    int totalTime = *(int*)((char*)self + 0x508);
    
    if (!totalTime) {
        // Copy fixed string
        extern const char timingDefaultStr[];
        // ...
        return 0;
    }
    
    extern int debug_disable_timing;  // 0x86BDF4
    
    if (!debug_disable_timing) {
        // Calculate various timing stats by dividing counters by totalTime
        int a1 = *(int*)((char*)self + 0x5AC) / totalTime;
        int a2 = *(int*)((char*)self + 0x6CC) / totalTime;
        int a3 = (*(int*)((char*)self + 0x66C) + *(int*)((char*)self + 0x6AC)) / totalTime;
        int a4 = *(int*)((char*)self + 0x6EC) / totalTime;
        int a5 = *(int*)((char*)self + 0x54C) / totalTime;
        int a6 = *(int*)((char*)self + 0x58C) / totalTime;
        int a7 = *(int*)((char*)self + 0x74C) / totalTime;
        int a8 = *(int*)((char*)self + 0x60C) / totalTime;
        int a9 = *(int*)((char*)self + 0x5EC) / totalTime;
        // ... more divisions
        
        // Format: sprintf(buf, "...", a1..a9);
    }
    
    return 0;
}
