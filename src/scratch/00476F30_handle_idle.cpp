// Pnl_inp.cpp:153-168, 107 bytes
// attempt 1: compile errors
// attempt 2: 65.4%, offsets wrong due to vtable
// attempt 3: 53.3%, fixed offsets
// attempt 4: 32.7%, string lit optimized to null
// attempt 5: 32.7%, same
// attempt 6: 62.6%, extern char* worse
// BEST: 32.7% (attempts 4/5). BLOCKER: string literal optimized to push 0
//   instead of push 585348h. Rest of function matches perfectly.
extern unsigned long __cdecl debug_timeGetTime(const char*, int);

class TPanel {
public:
    long handle_idle();
};

class TInputPanel : public TPanel {
public:
    char gap_00[0x78];
    int debug;              // +0x78
    char gap_7C[0x18C - 0x7C];
    unsigned long caret_interval;   // +0x18C
    unsigned long caret_last_time;  // +0x190
    int draw_caret;         // +0x194

    long handle_idle();
};

long TInputPanel::handle_idle() {
    if (debug != 0) {
        unsigned long now = debug_timeGetTime("Pnl_inp.cpp", 0x9E);
        if ((now - caret_last_time) >= caret_interval) {
            draw_caret = (draw_caret == 0) ? 1 : 0;
            ((void(*)(void*,int))(*(void***)this)[0x20/4])(this, 1);
            now = debug_timeGetTime("Pnl_inp.cpp", 0xA3);
            caret_last_time = now;
        }
    }
    return TPanel::handle_idle();
}
