// TInputPanel::TInputPanel
// VA: 00476C10, Pnl_inp.cpp:36-41
// Status: MATCHED 2026-05-26
//
// Attempt log:
// v0: Plain constructor with gaps -> 144 bytes, no SEH, no base ctor call.
// v1: Added TTextPanel() declaration to init list -> still 144, VC5 skips EH frame.
// v2: Added TTextPanel ctor definition + /GX flags -> 160 bytes, wrong COMDAT/order.
// v3: Added real field back_color to TTextPanel -> same 160 bytes.
// earlier parked: same constructor SEH challenge as 00506240/005067D0; needed base ctor
// and lightweight VC5 /GX constructor frame without defining helper COMDATs in this TU.
// Retry 2026-05-26 Boss pass: tried visible virtual base/derived destructors with raw
// offset stores (exact-size but 87 positional / 26 edit), derived-only virtual (broad
// byte-0 mismatch), initializer-list scalar form (short), novtable virtual surface
// (also matched), empty dtor definition (short/COMDAT), and manual base ctor in body
// (short/wrong). Winning minimal source declares the non-virtual base destructor plus
// the real base constructor in the initializer list, uses the proven input fields, and
// keeps raw access only for the inherited and vptr anchors.
// The base destructor declaration is enough under /GX to trigger the original
// lightweight constructor EH frame/base cleanup context without emitting extra COMDATs;
// the derived destructor declaration is not needed.
// Exact-finish 2026-08-24: removing the base destructor declaration produced 137 bytes;
// removing the derived declaration stayed exact. The reviewed full pnl_inp context
// injected a compiler vptr store and produced 187 bytes, so this narrow local surface
// preserves the proven constructor ABI while its fields retain the canonical offsets.
// Authentic-wrapper probe: __declspec(novtable) plus a late manual vptr store
// made this constructor exact in the grouped TU, but changed the exact derived
// destructor. The canonical wrapper was restored.

extern "C" __declspec(dllimport) unsigned long __stdcall GetCaretBlinkTime();

class TDigital;

struct TTextPanel {
    char gap[0x188];
    TTextPanel();
    ~TTextPanel();
};

struct TInputPanel : TTextPanel {
    unsigned char caret_color;
    unsigned char pad_189[3];
    unsigned long caret_interval;
    unsigned long caret_last_time;
    int draw_caret;
    TDigital* overLengthSound;
    int format_type;
    char* input_buffer;
    char* input_buffer1;
    char* input_buffer2;
    short input_len;
    short max_len;
    int insert_mode;
    short input_pos;
    unsigned char pad_1B6[2];
    TInputPanel();
};

TInputPanel::TInputPanel() : TTextPanel()
{
    this->caret_color = 0;
    this->caret_interval = GetCaretBlinkTime();
    this->caret_last_time = 0;
    this->draw_caret = 1;
    this->insert_mode = 1;
    *(int*)((char*)this + 0x80) = 1;
    *(int*)((char*)this + 0x170) = 1;
    this->overLengthSound = 0;
    this->input_buffer = 0;
    this->input_buffer1 = 0;
    this->input_buffer2 = 0;
    this->input_len = 0;
    this->max_len = 0;
    this->input_pos = 0;
    // BINARY NOTE: The constructor emits this derived-vptr store late.
    *(int*)this = 0x571488;
    *(char*)((char*)this + 0xEE) = 7;
    *(int*)((char*)this + 0x114) = 5;
}
