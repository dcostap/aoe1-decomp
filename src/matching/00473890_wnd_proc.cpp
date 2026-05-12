// VA: 00473890 TButtonPanel::wnd_proc
// PDB: Pnl_btn.cpp lines 1118-1135 (131 bytes, 42 asm lines)
// Default flags. No inline asm/hacks.

extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hwnd, unsigned msg, unsigned wparam, long lparam);

class TPanel {
public:
    virtual ~TPanel();
    long wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp);
};

class TButtonPanel : public TPanel {
public:
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void v20(int arg);
    virtual void padA();

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

long TButtonPanel::wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp) {
    if (msg == 0x101 && this->key_down != 0 && wp == this->key_down) {
        int buttonType = this->buttonTypeValue;
        this->key_down = 0;
        if (buttonType != 2) {
            this->is_down = 0;
        }
        this->v20(1);
        SendMessageA(*(void**)((char*)this->hwnd_holder + 4), 0x0F, 0, 0);
        this->do_action();
        return 1;
    }
    return TPanel::wnd_proc(hwnd, msg, wp, lp);
}
