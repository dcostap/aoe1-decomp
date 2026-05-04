// VA: 00478010, TInputPanel::calc_cur_line_col
// Source: Pnl_inp.cpp lines 943-985
// Attempt log:
// - Initial source mirrored matched calc_input_pos inverse line/column logic.

#include <stddef.h>

typedef unsigned char uchar;

extern "C" short __cdecl __mbslen(const char* str);

struct TextNode {
    char* text;            // +0x00
    char* text2;           // +0x04
    long id;               // +0x08
    TextNode* next_node;   // +0x0C
};

class TPanel {
public:
    char gap_00[0xF4];
};

class TTextPanel : public TPanel {
public:
    TextNode* list;          // +0xF4
    short num_lines;         // +0xF8
    short draw_lines;        // +0xFA
    short top_line;          // +0xFC
    short bot_line;          // +0xFE
    short cur_line;          // +0x100
    short cur_col;           // +0x102
    char gap_104[0x188 - 0x104];

    void scroll(uchar direction, uchar param2, uchar param3);
};

class TInputPanel : public TTextPanel {
public:
    char gap_188[0x1A0 - 0x188];
    char* input_buffer;      // +0x1A0
    char gap_1A4[0x1B4 - 0x1A4];
    short input_pos;         // +0x1B4

    void calc_cur_line_col();
};

void TInputPanel::calc_cur_line_col()
{
    TextNode* node;
    short offset;
    short len;

    node = this->list;
    this->cur_line = 0;
    this->cur_col = 0;
    offset = 0;

    while (node != 0 && this->cur_line != this->num_lines - 1) {
        len = __mbslen(node->text);
        if (offset + len > this->input_pos) {
            break;
        }
        offset += len;
        this->cur_line++;
        node = node->next_node;
    }

    this->cur_col = this->input_pos - offset;

    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\n') {
        this->input_pos--;
        this->cur_col--;
    }

    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\r') {
        this->input_pos--;
        this->cur_col--;
    }

    if (this->cur_line < this->top_line) {
        do {
            this->scroll(3, 1, 1);
        } while (this->cur_line < this->top_line);
    }

    if (this->cur_line > this->bot_line) {
        do {
            this->scroll(2, 1, 1);
        } while (this->cur_line > this->bot_line);
    }
}
