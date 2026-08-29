#ifndef AOE1_PNL_INP_H
#define AOE1_PNL_INP_H

// This header owns TInputPanel.
#include "pnl_lst.h"
#include "sounddrv.h"

class TInputPanel : public TTextPanel {
public:
    enum FormatType {
        FormatSingleLine = 0, FormatNumber = 1, FormatInteger = 2,
        FormatUnsignedInt = 3, FormatFile = 4, FormatFileNoExt = 5,
        FormatPath = 6, FormatMultiLine = 7, FormatPercent = 8
    };
    TInputPanel();
    virtual ~TInputPanel();
    unsigned char caret_color;
    unsigned char pad_189[3];
    unsigned long caret_interval;
    unsigned long caret_last_time;
    int draw_caret;
    TDigital* overLengthSound;
    FormatType format_type;
    char* input_buffer;
    char* input_buffer1;
    char* input_buffer2;
    short input_len;
    short max_len;
    int insert_mode;
    short input_pos;
    unsigned char pad_1B6[2];
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, unsigned char,
               short, TDigital*, char*, FormatType);
    virtual void set_focus(int);
    void set_format(FormatType);
    virtual long handle_idle();
    virtual long char_action(long, short);
    virtual long key_down_action(long, short, int, int, int);
    virtual void draw();
    virtual void set_text(char*);
    virtual void set_text(char**, short);
    char* get_input_buffer();
protected:
    int append_character(long);
    int insert_character(long);
    int delete_character();
    int backspace_character();
    int paste();
    void reformat();
    void calc_input_pos();
    void calc_cur_line_col();
public:
    int is_blank();
    char* get_trimmed_str(char*, int);
};

#endif
