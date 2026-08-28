#ifndef AOE1_PNL_LST_H
#define AOE1_PNL_LST_H

// PDB source: C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp.
// This header owns TTextPanel and TListPanel.
#include "panel.h"
#include "drawarea.h"
#include "Shape.h"

extern char s_pnl_lst__draw[];
extern char s_pnl_lst__draw_highlight_bar[];

class TScrollBarPanel;

class TTextPanel : public TPanel {
public:
    class TextNode {
    public:
        char* text;
        char* text2;
        long id;
        TextNode* next_node;
    };

    enum CharType {
        SingleByteChar = 0,
        SingleByteKanaChar = 1,
        DoubleByteChar = 2
    };
    enum Alignment {
        AlignCenter = 0,
        AlignLeft = 1,
        AlignRight = 2,
        AlignTop = 3,
        AlignBottom = 4,
        AlignHorizontalScroll = 5,
        AlignWordwrap = 6
    };
    enum Style {
        NormalStyle = 0,
        BeveledStyle = 1,
        ChiseledStyle = 2
    };

    TTextPanel();
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, char*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, long);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, char**, short);
    void set_font(void*, long, long);
    void set_alignment(Alignment, Alignment);
    void set_word_wrap(int);
    void set_style(Style);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_fill_back(int, unsigned char);
    void set_back_pic(char*);
    void set_outline(int, unsigned char);
    void set_spacer_size(int);
    void set_scrollbar(TScrollBarPanel*, int);
    CharType char_type(unsigned char*);
    int word_wrap_append(char*);
    void calc_draw_info(int);
    void scroll(unsigned char, short, int);
    void draw_background();
    void draw_border();
    void draw_line(void*, short, short, unsigned long, unsigned long);
    void calc_line_pos(void*, short, short, tagRECT*, long*);
    void free_text();
    int append_line(const char*, long);
    int append_line(char*, long);
    int append_line(char*, char*, long);
    int append_line(long, long);
    int append_line(long, long, long);
    int insert_line(long, char*, long);
    int insert_line(long, char*, char*, long);
    int insert_line(long, long, long);
    int insert_line(long, long, long, long);
    int change_line(long, char*, char*, long);
    int change_line(long, long, long, long);
    int delete_line(long);
    long get_line();
    long get_line(long);
    long get_line(char*);
    char* get_text();
    char* get_text(long);
    char* get_text2();
    char* get_text2(long);
    long get_id();
    long get_id(long);
    void set_second_column_pos(long);
    void empty_list();
    void set_line(long);
    void set_line_by_id(long);
    char* currentLine();
    int numberLines() const;
    int numberDrawLines() const;
    int currentLineNumber() const;
    void setCurrentLineNumber(int);
    int get_text_rect(RECT*);

    TextNode* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    Alignment vert_align;
    Alignment horz_align;
    int word_wrap;
    Style text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    unsigned char pad_13A[2];
    long text_wid;
    long text_hgt;
    TShape* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    unsigned char pad_151[3];
    int outline;
    unsigned char outline_color;
    unsigned char pad_159[3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_17A[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;
};

typedef char pnl_lst_textnode_size_check[
    (sizeof(TTextPanel::TextNode) == 0x10) ? 1 : -1];
typedef char pnl_lst_ttextpanel_size_check[
    (sizeof(TTextPanel) == 0x188) ? 1 : -1];

class TListPanel : public TTextPanel {
public:
    TListPanel();
    virtual ~TListPanel();
    virtual void draw();
    virtual long handle_idle();
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_focus(int);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;

    void set_auto_track(int);
    void setDrawHighlightBar(int);
    void scroll_cur_line(unsigned char, short, int);
    short item_at(long, long);
    void goto_item(long, long);
    void draw_highlight_bar();
};

typedef char pnl_lst_tlistpanel_size_check[
    (sizeof(TListPanel) == 0x1A0) ? 1 : -1];

#endif
