// 00476CF0 TInputPanel::~TInputPanel
// Source: Pnl_inp.cpp lines 47-60. 140 bytes (expected). __thiscall, EH destructor.
// Needs /GX for EH frame generation.
//
// Parked: EH frame generation requires TU-level context. In single-function
// scratch, VC5 with /GX doesn't emit EH prologue/epilogue for destructors
// without try/catch/new expressions. Body can match (96/140 bytes body-only)
// but the full 44 bytes of EH frame (push -1, push handler, fs:0 save/restore,
// push ecx, add esp 0x10) can't be forced from isolated source.

extern "C" void operator_delete(void* p);

class TTextPanel {
public:
    char gap_00[0x184]; // +4 for implicit vtable = 0x188

    virtual ~TTextPanel();
};

class TInputPanel : public TTextPanel {
public:
    char pad_188[0x18];
    char* input_buffer;           // +0x1A0
    char* input_buffer1;          // +0x1A4
    char* input_buffer2;          // +0x1A8
    char gap_1AC[0x1B8 - 0x1AC];

    virtual ~TInputPanel();
};

TInputPanel::~TInputPanel() {
    if (this->input_buffer1 != 0) {
        operator_delete(this->input_buffer1);
        this->input_buffer1 = 0;
    }
    if (this->input_buffer2 != 0) {
        operator_delete(this->input_buffer2);
        this->input_buffer2 = 0;
    }
    this->input_buffer = 0;
    *(int*)((char*)this + 0x80) = 1;
}
