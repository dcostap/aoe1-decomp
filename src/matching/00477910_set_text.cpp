// 00477910 TInputPanel::set_text
// Source: Pnl_inp.cpp lines 532-554. 125 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 125-byte match confirmed via local check_function.py.
// Straightforward one-pass match. Key: correct member offsets from
// type dump (cur_line at +0x100, cur_col at +0x102, input_buffer at
// +0x1A0, format_type at +0x19C, input_len at +0x1AC, input_pos at +0x1B4).

extern "C" char* __mbscpy(char* dst, const char* src);
extern "C" short __mbslen(const char* str);

enum FormatType {
    FormatSingleLine = 0,
    FormatMultiLine = 7
};

class TInputPanel {
public:
    char gap_00[0x0F4];
    void* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;      // +0x100
    short cur_col;       // +0x102
    char gap_106[0x082]; // 0x106 to 0x187 (130 bytes)
    unsigned char caret_color; // +0x188
    char gap_189[0x013]; // 0x189 to 0x19B
    FormatType format_type; // +0x19C
    char* input_buffer;  // +0x1A0
    char* input_buffer1; // +0x1A4
    char* input_buffer2; // +0x1A8
    short input_len;     // +0x1AC
    short max_len;       // +0x1AE
    int insert_mode;     // +0x1B0
    short input_pos;     // +0x1B4

    void set_text(char* param_1);
    void reformat();
};

void TInputPanel::set_text(char* param_1) {
    char* buf = this->input_buffer;
    if (buf != 0) {
        if (param_1 == 0) {
            *buf = 0;
        } else {
            __mbscpy(buf, param_1);
        }
        short len = __mbslen(this->input_buffer);
        this->input_len = len;
        this->input_pos = 0;
        this->cur_line = 0;
        this->cur_col = 0;
        if (this->format_type != FormatMultiLine && len > 0) {
            this->input_pos = len;
            this->cur_col = len;
        }
        this->reformat();
    }
}
