// VA: 00421BF0 RGE_Base_Game::calc_timings (934 B)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass
// Timing accumulator and debug-print profiler

extern unsigned long debug_timeGetTime(const char* file, int line);
extern int sprintf(char* buf, const char* fmt, ...);
extern void debug_printf(void* format, ...);

extern int g_62C530; // time counter
extern int g_62C538;
extern int g_62C53C;
extern int g_62C540;
extern int g_62C544;
extern int g_62C52C; // profile enable flag

struct Shim_21BF0 {
    // Start of array of 30 structs at +0x528, each 0x20 bytes
    // offset fields:
    //   +0x00: cur_start (dword)
    //   +0x04: accum (dword)
    //   +0x08: timer_start (dword)
    //   +0x0C: cur_total (dword)
    //   +0x10: running (dword)
    //   +0x14: pad (dword)
    //   +0x18: prev_total (dword)
    //   +0x1C: pad (dword)
    // End of array at +0x528 + 30*0x20 = +0x528 + 0x3C0 = +0x8E8
    
    char p0[0x504];
    int timer_frame;           // +0x504
    int timer_game;            // +0x508
    int timer_idle;            // +0x50C
    int timer_frame_save;      // +0x510
    int timer_game_save;       // +0x514
    int timer_idle_save;       // +0x518
    int fps_calc;              // +0x51C
    int ups_calc;              // +0x520
    int ips_calc;              // +0x524
    // Array starts at +0x528
};

void RGE_Base_Game_calc_timings(Shim_21BF0* self)
{
    int oldAccum = 0;
    int i;
    void* slot;
    int totalTime;
    
    // Accumulate all running timers
    for (i = 0; i < 30; i++) {
        slot = (char*)self + 0x528 + i * 0x20;
        if (!*(int*)((char*)slot + 0x10)) { // not running
            // Store previous and reset start
            *(int*)((char*)slot + 4) = *(int*)slot;
            *(int*)((char*)slot + 0x1C) = *(int*)((char*)slot + 0x18);
            *(int*)slot = 0;
            *(int*)((char*)slot + 0x18) = 0;
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12B5);
        } else {
            oldAccum += *(int*)((char*)slot + 4);
        }
    }
    
    totalTime = *(int*)((char*)self + 0x530);
    
    if (totalTime > 0) {
        debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12BE);
        *(int*)((char*)self + 0x52C) = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12BE) - totalTime;
    } else {
        *(int*)((char*)self + 0x52C) = oldAccum;
    }
    
    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12C1);
    int oldTotal = *(int*)((char*)self + 0x52C);
    *(int*)((char*)self + 0x530) = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12C1);
    
    if (oldTotal <= oldAccum)
        *(int*)((char*)self + 0x5AC) = 0;
    else
        *(int*)((char*)self + 0x5AC) = oldTotal - oldAccum;
    
    // Compute idle time
    int frameTotal = *(int*)((char*)self + 0x5EC);
    int idleTotal = *(int*)((char*)self + 0x60C);
    int gameTotal = *(int*)((char*)self + 0x56C);
    int sumFI = frameTotal + idleTotal;
    
    if (gameTotal > sumFI)
        *(int*)((char*)self + 0x64C) = gameTotal - frameTotal - idleTotal;
    else
        *(int*)((char*)self + 0x64C) = 0;
    
    // Calculate FPS
    if (oldTotal && self->timer_frame && self->timer_frame != 0) {
        int div = oldTotal / self->timer_frame;
        if (div) {
            self->fps_calc = 1000 / div;
        } else {
            self->fps_calc = 1000;
        }
    } else {
        self->fps_calc = 1000;
    }
    
    // Calculate UPS
    if (oldTotal && self->timer_game && self->timer_game != 0) {
        int div = oldTotal / self->timer_game;
        if (div) {
            self->ups_calc = 1000 / div;
        } else {
            self->ups_calc = 0;
        }
    } else {
        self->ups_calc = 0;
    }
    
    // Calculate IPS
    if (oldTotal && self->timer_idle && self->timer_idle != 0) {
        int div = oldTotal / self->timer_idle;
        if (div) {
            self->ips_calc = 1000 / div;
        } else {
            self->ips_calc = 0;
        }
    } else {
        self->ips_calc = 0;
    }
    
    // Virtual call to gather timings
    // (vmcall +0x12C) — possibly calc_other_timings or similar
    void** vtable = *(void***)self;
    ((void(*)(Shim_21BF0*))vtable[0x12C / 4])(self);
    
    // Debug printing if profile mode active
    if (g_62C52C) {
        // Complex timing dump
        // Only executes when mode == 4
    }
    
    // Save and reset timers
    self->timer_frame_save = self->timer_frame;
    self->timer_game_save = self->timer_game;
    self->timer_idle_save = self->timer_idle;
    self->timer_frame = 0;
    self->timer_game = 0;
    self->timer_idle = 0;
}
