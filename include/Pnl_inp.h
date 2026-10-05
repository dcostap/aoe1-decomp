#ifndef AOE1_PNL_INP_H
#define AOE1_PNL_INP_H

// This header owns TInputPanel.
#include "pnl_lst.h"
#include "sounddrv.h"

class TInputPanel : public TTextPanel {
  public:
    enum FormatType {
        FormatSingleLine = 0,
        FormatNumber = 1,
        FormatInteger = 2,
        FormatUnsignedInt = 3,
        FormatFile = 4,
        FormatFileNoExt = 5,
        FormatPath = 6,
        FormatMultiLine = 7,
        FormatPercent = 8
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
    long setup(
        TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in,
        void* font_in, long font_wid_in, long font_hgt_in, char* back_pic_in, int fill_back_in,
        unsigned char back_color_in, int outline_in, unsigned char outline_color_in, unsigned char caret_color_in,
        short max_len_in, TDigital* overLengthSoundIn, char* text_in, FormatType format_type_in
    );
    virtual void set_focus(int have_focus_in);
    void set_format(FormatType format_type_in);
    virtual long handle_idle();
    virtual long char_action(long key, short count);
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
    virtual void draw();
    virtual void set_text(char* text_in);
    virtual void set_text(char** text_in, short num_lines_in);
    char* get_input_buffer();

  protected:
    int append_character(long c);
    int insert_character(long c);
    int delete_character();
    int backspace_character();
    int paste();
    void reformat();
    void calc_input_pos();
    void calc_cur_line_col();

  public:
    int is_blank();
    char* get_trimmed_str(char* str, int str_len);
};

#endif
