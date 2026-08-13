// VA: 00477CB0 TInputPanel::paste
// Source: Pnl_inp.cpp lines 780-868
// Attempt log:
// 1: initial natural reconstruction from packet and neighboring TInputPanel functions.
// 2: fixed capacity check to use input_len, not cursor/input_pos; matches through overlength branch.
// 3: spelled capacity test as max_len <= len + input_len; no register improvement.
// 4: inverted capacity test into success block; goto form grew by 8 bytes, rolled back.
// 5: introduced max_len/total_len locals; no codegen change.
// 6: split dst_tail initialization before _mbsninc; no change.
// 7: changed _mbsncpy/_mbsninc count signedness int/long; no change, restored unsigned int.
// 8: swapped max_len/total_len declaration order; no change.
// r1 baseline: rebuilt the canonical clipboard and alternating-buffer path; body parity reaches the capacity gate.
// r1 cached input_len/max_len locals: codegen duplicate; rolled back.
// r1 len-derived accumulator and typed short max_len probes: codegen duplicates; rolled back.
// r1 field-first capacity sum and split old-style assignments: no improvement; rolled back.
// r1 focused capacity variant lab: five natural declaration/expression forms produced two groups and no exact match.
// r1 local declaration reorder: one-byte farther and rolled back.
// r2 typed ABI/control-flow reconstruction: used char buffers and the direct max_len <= input_len + len predicate; diff improved to 277, but shape/edit diagnostics worsened and codegen duplicated an earlier group; kept as the best natural typed source.
// left in scratch: behavior/calls/stack frame match closely through clipboard path; remaining mismatch starts at capacity-test register allocation (rebuilt computes sum in ecx and max in edx, original uses edx=len+input_len and eax=max), causing 2-byte shift and later scheduling/register-order drift around _mbsninc calls.

typedef unsigned long ulong;
typedef void* HANDLE;
typedef void* HWND;

extern "C" __declspec(dllimport) int __stdcall IsClipboardFormatAvailable(unsigned int format);
extern "C" __declspec(dllimport) int __stdcall OpenClipboard(HWND hwnd);
extern "C" __declspec(dllimport) HANDLE __stdcall GetClipboardData(unsigned int format);
extern "C" __declspec(dllimport) void* __stdcall GlobalLock(HANDLE hMem);
extern "C" __declspec(dllimport) int __stdcall GlobalUnlock(HANDLE hMem);
extern "C" __declspec(dllimport) int __stdcall CloseClipboard(void);
extern "C" __declspec(dllimport) int __stdcall MessageBeep(unsigned int type);

extern "C" int __cdecl _mbslen(const char* str);
extern "C" char* __cdecl _mbsncpy(char* dst, const char* src, unsigned int count);
extern "C" char* __cdecl _mbsninc(const char* str, unsigned int count);
extern ulong __cdecl debug_timeGetTime(char* file, int line);

class TDigital { public: int play(); };

class TInputPanel {
public:
    char gap_000[0x20];
    struct Owner { char gap[4]; HWND hwnd; }* owner;
    char gap_024[0x190 - 0x24];
    ulong caret_last_time;
    int draw_caret;
    TDigital* overLengthSound;
    char gap_19C[0x1A0 - 0x19C];
    char* input_buffer;
    char* input_buffer1;
    char* input_buffer2;
    short input_len;
    short max_len;
    char gap_1B0[4];
    short input_pos;

    void reformat();
    void calc_cur_line_col();
    int paste();
};

int TInputPanel::paste()
{
    int len;
    HANDLE data_handle;
    char* locked;
    char* old_str;
    char* new_cur;
    char* old_tail;
    char* dst_tail;
    char new_str[0x1000];

    len = 0;
    new_str[0] = 0;
    if (!IsClipboardFormatAvailable(1)) {
        return 0;
    }
    if (!OpenClipboard(this->owner->hwnd)) {
        return 0;
    }
    data_handle = GetClipboardData(1);
    if (data_handle != 0) {
        locked = (char*)GlobalLock(data_handle);
        if (locked != 0) {
            len = _mbslen(locked);
            if (len > 0xfff) {
                len = 0xfff;
            }
            for (int i = 0; i < 0x1000; ++i) {
                new_str[i] = 0;
            }
            _mbsncpy(new_str, locked, len);
            GlobalUnlock(data_handle);
        }
    }
    CloseClipboard();

    {
        if (this->max_len <= len + this->input_len) {
            if (this->overLengthSound != 0) {
                this->overLengthSound->play();
                return 0;
            }
            MessageBeep(0xffffffff);
            return 0;
        }
    }

    new_cur = this->input_buffer1;
    if (this->input_buffer == new_cur) {
        old_str = new_cur;
        new_cur = this->input_buffer2;
    } else {
        old_str = this->input_buffer2;
    }
    this->input_buffer = new_cur;
    *new_cur = 0;

    _mbsncpy(new_cur, old_str, (int)this->input_pos);
    old_tail = _mbsninc(old_str, (int)this->input_pos);
    dst_tail = new_cur;
    dst_tail = _mbsninc(dst_tail, (int)this->input_pos);
    _mbsncpy(dst_tail, new_str, len);
    dst_tail = _mbsninc(dst_tail, len);
    _mbsncpy(dst_tail, old_tail, ((int)this->input_len - (int)this->input_pos) + 1);

    this->input_len += (short)len;
    this->input_pos += (short)len;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 0x362);
    return 1;
}
