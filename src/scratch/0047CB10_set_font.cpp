class TScrollBarPanel;

class TTTextPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int param_1);

    class TextNode {
    public:
        char* text;
        char* text2;
        long id;
        TextNode* next_node;
    };

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
    int vert_align;
    int horz_align;
    int word_wrap;
    int text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    char gap_13A[2];
    long text_wid;
    long text_hgt;
    void* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    char gap_151[3];
    int outline;
    unsigned char outline_color;
    char gap_159[3];
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
    char gap_17A[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;

    void calc_draw_info(int param_1);
    void set_font(void* param_1, long param_2, long param_3);
};

void TTTextPanel::set_font(void* param_1, long param_2, long param_3) {
    this->font_wid = param_2;
    this->font = param_1;
    this->font_hgt = param_3;
    this->calc_draw_info(1);
    this->vf20(1);
}
