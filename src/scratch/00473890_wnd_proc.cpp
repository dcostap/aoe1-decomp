// VA: 00473890 TButtonPanel::wnd_proc (131B)
// Pnl_btn.cpp lines 1118-1135
// Attempt log:
// - Previous scratch had wrong offsets (+2A4/+1F4) and wrong branch factoring.
// - 2026-05-10 StarryZephyr pass: rewrote with direct member offsets/fallback virtual-ish surface and original action order.
//   Now behavior/offsets/call order are correct; remaining drift is mostly declaration/call surface: fake wrappers produce
//   direct static calls instead of exact virtual/base calls/IAT SendMessageA shape in the original. Trying a one-arg
//   virtual call removed 3 bytes but produced a 128-byte too-short window, so restored two-arg call. No accepted_drift.

class TPanel {
public:
    virtual ~TPanel();
    long wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp);
};

class TButtonPanel : public TPanel {
public:
    char gap_004[0x20 - 0x04];
    void* hwnd_holder;
    char gap_024[0x13C - 0x24];
    int buttonTypeValue;
    char gap_140[0x1F8 - 0x140];
    int is_down;
    char gap_1FC[0x2AC - 0x1FC];
    unsigned key_down;

    long wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp);
    void do_action();
};

extern "C" long __stdcall SendMessageA(void* hwnd, unsigned msg, unsigned wparam, long lparam);

long TButtonPanel::wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp) {
    if (msg == 0x101 && this->key_down != 0 && wp == this->key_down) {
        int buttonType = this->buttonTypeValue;
        this->key_down = 0;
        if (buttonType != 2) {
            this->is_down = 0;
        }
        ((void (__stdcall*)(TButtonPanel*, int))(*(void***)this)[8])(this, 1);
        SendMessageA(*(void**)((char*)this->hwnd_holder + 4), 0x0F, 0, 0);
        this->do_action();
        return 1;
    }
    return TPanel::wnd_proc(hwnd, msg, wp, lp);
}
