// 004779D0 TInputPanel::insert_character (Pnl_inp.cpp:586-657, 287B)
// Inserts a character at the current input position.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* __cdecl _mbsncpy(void* dest, void* src, int count);
extern "C" void* __cdecl _mbsninc(void* str, int count);
extern "C" void* __cdecl _mbsinc(void* str);
extern "C" void (__stdcall* const MessageBeep)(unsigned int);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

struct TDigital {
    void* vtable;
    unsigned char play();
};

struct TInputPanel {
    char gap_00[0x188];
    unsigned char caret_color;         // +0x188
    char pad_189[3];
    unsigned long caret_interval;      // +0x18C
    unsigned long caret_last_time;     // +0x190
    int draw_caret;                    // +0x194
    TDigital* overLengthSound;         // +0x198
    int format_type;                   // +0x19C
    char* input_buffer;                // +0x1A0
    char* input_buffer1;               // +0x1A4
    char* input_buffer2;               // +0x1A8
    short input_len;                   // +0x1AC
    short max_len;                     // +0x1AE
    int insert_mode;                   // +0x1B0
    short input_pos;                   // +0x1B4

    int insert_character(long ch);
    void reformat();
    void calc_cur_line_col();
};

int TInputPanel::insert_character(long ch) {
    if (input_len >= max_len) {
        if (overLengthSound != 0) {
            overLengthSound->play();
        } else {
            MessageBeep(0xFFFFFFFF);
        }
        return 0;
    }

    char* src_buffer;
    char* dst_buffer;

    if (input_buffer == input_buffer1) {
        src_buffer = input_buffer1;
        dst_buffer = input_buffer2;
    } else {
        src_buffer = input_buffer2;
        dst_buffer = input_buffer1;
    }

    input_buffer = dst_buffer;
    *dst_buffer = 0;

    if (input_pos > 0) {
        _mbsncpy(dst_buffer, src_buffer, input_pos);
        src_buffer = (char*)_mbsninc(src_buffer, input_pos);
        dst_buffer = (char*)_mbsninc(dst_buffer, input_pos);
    }

    _mbsncpy(dst_buffer, &ch, 1);
    dst_buffer = (char*)_mbsinc(dst_buffer);
    _mbsncpy(dst_buffer, src_buffer, input_len - input_pos + 1);

    input_len++;
    input_pos++;

    reformat();
    calc_cur_line_col();

    draw_caret = 1;
    caret_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 0x28F);

    return 1;
}
