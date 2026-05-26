// ACCEPTED_DRIFT: reviewed 2026-05-26 by orchestrator. Exact behavior/calls/stack effects; nonzero diff is localized to equivalent x87 multiply encoding (`fild speed; fmulp` vs `fimul speed`) causing 2-byte shift and branch displacement/tail padding differences only.
// TScrollTextPanel::handle_idle
// VA: 00492FB0
// scr_cred.cpp
// Attempts: rebuilt natural member/virtual/IAT surfaces; fixed set_redraw slot +0x20 and child notify slot +0xB4.
// Tried FPU amount forms: inline int multiply, explicit (double)speed, named double val, val*=speed, swapped operands, (float)speed, volatile speed, and /Op,/Oi,/Og,/Ot,/O1 flags.
// Best remaining drift: VC5 emits `fimul dword [esi+190h]` (6B) for `elapsed*const*speed`; original emits equivalent `fild dword [esi+190h]; fmulp` (8B). This 2-byte arithmetic encoding difference shifts branch displacements/tail by 2; behavior/calls/stack effects otherwise match.

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

struct TPanel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set_redraw(int flag); // +0x20
    char gap_04[0x3C];
    void* child; // +0x40
    long handle_idle();
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

struct TChildNotify {
    VPAD32(0) VPAD8(32) VPAD4(40) VPAD1(44)
    virtual void notify(void* panel, int a, int b, int c); // +0xB4 slot45
};

class TScrollTextPanel : public TPanel {
public:
    char gap_44[0x144];
    int scroll;       // +0x188
    unsigned long last_time; // +0x18C
    int speed;        // +0x190
    int done;         // +0x194
    virtual long handle_idle();
};

long TScrollTextPanel::handle_idle()
{
    if (this->last_time == 0) {
        this->last_time = debug_timeGetTime((char*)0x5862BC, 0x1DC);
    } else {
        unsigned long now = debug_timeGetTime((char*)0x5862BC, 0x1DF);
        __int64 elapsed = (unsigned long)(now - this->last_time);
        int amount = (long)(((double)elapsed * *(float*)0x572968) * this->speed);
        if (amount > 0) {
            this->scroll += amount;
            this->set_redraw(1);
            this->last_time = now;
        }
    }
    if (this->done != 0) {
        if (this->child != 0) {
            ((TChildNotify*)this->child)->notify(this, 1, 0, 0);
        }
    }
    return this->TPanel::handle_idle();
}
