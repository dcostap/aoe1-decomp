// attempt 1: natural save/clamp/scroll shape from the asm
// result: close, but the saved short register assignment landed swapped
// attempt 2: swap the local birth/order so old_cur stays with the first clamp and old_top with scroll
// attempt 3: restore the original save order after the vtable/layout fix; that should put the saved shorts back in the right registers
// attempt 4: try a single saved line-count temp so both clamps share the same compare source
// still stuck: only the saved-short register assignment is swapped; the branch/body shape is otherwise aligned

class TTTextPanel {
public:
    char gap_0[0xF8 - 0x4];
    short num_lines;   // +0xF8
    short draw_lines;  // +0xFA
    short top_line;    // +0xFC
    short bot_line;    // +0xFE
    short cur_line;    // +0x100
    short cur_col;     // +0x102
    char gap_1[0x188 - 0x104];

    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int param_1);

    void set_text(char* text);
    void scroll(unsigned char mode, short value, int param_3);
};

class TInputPanel : public TTTextPanel {
public:
    unsigned char caret_color; // +0x188
    unsigned char _pad_0[0x3];
    unsigned long caret_interval; // +0x18C
    unsigned long caret_last_time; // +0x190
    int draw_caret; // +0x194
    void* overLengthSound; // +0x198
    int format_type; // +0x19C
    char* input_buffer; // +0x1A0
    char* input_buffer1; // +0x1A4
    char* input_buffer2; // +0x1A8
    short input_len; // +0x1AC
    short max_len; // +0x1AE
    int insert_mode; // +0x1B0
    short input_pos; // +0x1B4

    void reformat();
};

void TInputPanel::reformat() {
    short old_top = this->top_line;
    short old_cur = this->cur_line;

    this->set_text(this->input_buffer);

    short line_count = this->num_lines;
    if (old_cur >= line_count) {
        old_cur = line_count - 1;
    }
    this->cur_line = old_cur;

    if (old_top >= line_count) {
        old_top = line_count - 1;
    }
    this->top_line = old_top;

    this->scroll(1, old_top, 1);
    this->vf20(1);
}
