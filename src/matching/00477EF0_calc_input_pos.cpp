// VA: 00477EF0, TInputPanel::calc_input_pos, 274 bytes
// Source: Pnl_inp.cpp lines 900-935
// FLAGS: default

#include <stddef.h>

typedef unsigned short ushort;
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

    void calc_input_pos();
};

void TInputPanel::calc_input_pos()
{
    TextNode* node;
    short i;
    short len;

    node = this->list;
    this->input_pos = 0;

    for (i = 0; node != 0 && i < this->cur_line; i++) {
        len = __mbslen(node->text);
        this->input_pos = this->input_pos + len;
        node = node->next_node;
    }

    short col = this->cur_col;
    this->input_pos = this->input_pos + col;

    short pos = this->input_pos;
    if (col > 0 && pos > 0) {
        if (this->input_buffer[pos - 1] == '\n') {
            this->input_pos = pos - 1;
            this->cur_col = col - 1;
        }
    }

    short col2 = this->cur_col;
    if (col2 > 0) {
        short pos2 = this->input_pos;
        if (pos2 > 0) {
            if (this->input_buffer[pos2 - 1] == '\r') {
                this->input_pos = pos2 - 1;
                this->cur_col = col2 - 1;
            }
        }
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
