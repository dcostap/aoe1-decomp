// 00476F30 TInputPanel::handle_idle()
// Source: Pnl_inp.cpp lines 153-168
// Attempt 9: helper class for vcall convention without shifting field offsets

extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);

class TPanel {
public:
    long handle_idle();
};

/* Helper whose vtable layout matches TInputPanel's vtable at slot 8 (0x20).
 * Using this via cast generates: mov ecx,this; push arg; call [vtable+0x20]
 * without adding a compiler vtable ptr to TInputPanel (which would shift fields). */
struct TInputPanel_VTableHelper {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void draw_caret_method(int x);
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
            ((TInputPanel_VTableHelper*)this)->draw_caret_method(1);
            now = debug_timeGetTime("Pnl_inp.cpp", 0xA3);
            caret_last_time = now;
        }
    }
    return TPanel::handle_idle();
}
