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

extern "C" int __cdecl _mbslen(const unsigned char* str);
extern "C" unsigned char* __cdecl _mbsncpy(unsigned char* dst, const unsigned char* src, unsigned int count);
extern "C" unsigned char* __cdecl _mbsninc(const unsigned char* str, unsigned int count);
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
    unsigned char* input_buffer;
    unsigned char* input_buffer1;
    unsigned char* input_buffer2;
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
    unsigned char* locked;
    unsigned char* old_str;
    unsigned char* new_cur;
    unsigned char* old_tail;
    unsigned char* dst_tail;
    unsigned char new_str[0x1000];

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
        locked = (unsigned char*)GlobalLock(data_handle);
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
        int max_len = this->max_len;
        int total_len = len + this->input_len;
        if (total_len >= max_len) {
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
