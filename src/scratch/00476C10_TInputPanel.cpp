// TInputPanel::TInputPanel
// VA: 00476C10, Pnl_inp.cpp:36-41
// Status: PARKED in scratch - VC5 auto constructor SEH frame + TU context
//
// Attempt log:
// v0: Plain constructor with gaps → 144 bytes, no SEH, no base ctor call
// v1: Added TTextPanel() declaration to init list → still 144, VC5 skips base call
// v2: Added TTextPanel ctor definition + /GX flags → 160 bytes (TTextPanel ctor at offset 0 pushes TInputPanel)
// v3: Added real field back_color to TTextPanel → same 160 bytes
//
// Same SEH frame challenge as 00506240, 005067D0:
// - Lightweight constructor SEH (push -1, push handler, fs:[0], push ecx)
// - /GX alone doesn't trigger it in standalone compilation
// - try/catch generates heavy _CxxFrameHandler (different frame)
//
// Additional challenge: TTextPanel base constructor must be at VA 0047BF40,
// but defining it in the same TU pushes TInputPanel past its expected VA.
// This needs TU-level compilation or external symbol linking.
//
// Struct layout (TInputPanel extends TTextPanel which extends TPanel):
//   TPanel: +0x000 to +0x0F3 (0xF4 bytes)
//   TTextPanel: +0x0F4 to +0x187 (0x188 total)
//   TInputPanel: starts at +0x188
//     caret_color (+0x188, byte), caret_interval (+0x18C, int)
//     caret_last_time (+0x190, int), draw_caret (+0x194, int)
//     overLengthSound (+0x198, int), pad_19C (+0x19C, int)
//     input_buffer (+0x1A0, int), input_buffer1 (+0x1A4, int)
//     input_buffer2 (+0x1A8, int), input_len (+0x1AC, short)
//     max_len (+0x1AE, short), insert_mode (+0x1B0, int)
//     input_pos (+0x1B4, short)
//   Base fields accessed: +0x80=1, +0xEE=7, +0x114=5, +0x170=1
//   Vtable: 571488h

extern "C" __declspec(dllimport) unsigned long __stdcall GetCaretBlinkTime();

struct TTextPanel {
    char gap_00[0x188];          // size 0x188

    TTextPanel();
};

struct TInputPanel : TTextPanel {
    char caret_color;            // +0x188
    char pad_189[3];             // +0x189
    int caret_interval;          // +0x18C
    int caret_last_time;         // +0x190
    int draw_caret;              // +0x194
    int overLengthSound;         // +0x198
    int pad_19C;                 // +0x19C
    int input_buffer;            // +0x1A0
    int input_buffer1;           // +0x1A4
    int input_buffer2;           // +0x1A8
    short input_len;             // +0x1AC
    short max_len;               // +0x1AE
    int insert_mode;             // +0x1B0
    short input_pos;             // +0x1B4

    TInputPanel();
};

TInputPanel::TInputPanel() : TTextPanel() {
    caret_color = 0;
    caret_interval = GetCaretBlinkTime();
    caret_last_time = 0;
    draw_caret = 1;
    insert_mode = 1;

    // Base class field initializations
    *(int*)((char*)this + 0x80) = 1;
    *(int*)((char*)this + 0x170) = 1;

    overLengthSound = 0;
    input_buffer = 0;
    input_buffer1 = 0;
    input_buffer2 = 0;
    input_len = 0;
    max_len = 0;
    input_pos = 0;

    // vtable + base fields
    *(int*)this = 0x571488;
    *(char*)((char*)this + 0xEE) = 7;
    *(int*)((char*)this + 0x114) = 5;
}
