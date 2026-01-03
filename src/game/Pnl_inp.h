#pragma once
#include "../common.h"

typedef enum ActionType : unsigned int {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};

typedef enum FormatType : unsigned int {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};

class TInputPanel : public TTextPanel {
public:
    uchar caret_color;                       // 0x188
    ulong caret_interval;                    // 0x18C
    ulong caret_last_time;                   // 0x190
    int draw_caret;                          // 0x194
    TDigital* overLengthSound;               // 0x198
    FormatType format_type;                  // 0x19C
    char* input_buffer;                      // 0x1A0
    char* input_buffer1;                     // 0x1A4
    char* input_buffer2;                     // 0x1A8
    short input_len;                         // 0x1AC
    short max_len;                           // 0x1AE
    int insert_mode;                         // 0x1B0
    short input_pos;                         // 0x1B4

    TInputPanel();
    virtual ~TInputPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, char* param_10, int param_11, uchar param_12, int param_13, uchar param_14, uchar param_15, short param_16, TDigital* param_17, char* param_18, FormatType param_19);
    virtual void set_focus(int param_1);
    virtual void set_format(FormatType param_1);
    virtual long handle_idle();
    virtual long char_action(long param_1, short param_2);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual void draw();
    virtual void set_text(char* param_1);
    virtual void set_text(char** param_1, short param_2);
    virtual char* get_input_buffer();
    virtual int append_character(long param_1);
    virtual int insert_character(long param_1);
    virtual int delete_character();
    virtual int backspace_character();
    virtual int paste();
    virtual void reformat();
    virtual void calc_input_pos();
    virtual void calc_cur_line_col();
    virtual int is_blank();
    virtual char* get_trimmed_str(char* param_1, int param_2);
};

static_assert(sizeof(TInputPanel) == 0x1B8, "TInputPanel Size Mismatch");
static_assert(offsetof(TInputPanel, input_pos) == 0x1B4, "TInputPanel Offset Mismatch");

