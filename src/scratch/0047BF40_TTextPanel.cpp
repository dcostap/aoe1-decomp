// VA: 0047BF40 TTextPanel::TTextPanel
// Pnl_txt.cpp:73-78
// Baseline reconstruction: use the real TPanel base constructor and the
// named text-panel fields proved by the constructor's stores.
// Attempt log:
// - Replaced the raw helper call and fake flat object with a natural derived
//   constructor; the first check below records the resulting ABI/codegen.
// - Expanded the same-TU TPanel virtual surface and TTextPanel draw override;
//   this was a codegen duplicate. Natural VC5 places the derived vtable store
//   at entry, while the oracle sinks it after the field stores; forcing that
//   placement would require the prohibited manual-vtable source shape.
// - Main-agent audit retained natural base/derived construction and the full
//   named text-panel field layout; no explicit vptr store is permitted.
// - Removing the derived destructor declaration was a codegen duplicate;
//   restored the ABI-proven virtual destructor surface.
// - An explicit natural `: TPanel()` initializer was also a duplicate;
//   restored the implicit base-construction spelling.

class TPanel {
public:
    virtual ~TPanel();
    TPanel();

    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00C();
    virtual void vf_010();
    virtual void vf_014();
    virtual void vf_018();
    virtual void vf_01C();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02C();
    virtual void vf_030();
    virtual void vf_034();
    virtual void vf_038();
    virtual void vf_03C();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04C();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void vf_05C();
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06C();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07C();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08C();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09C();
    virtual void vf_0A0();
    virtual void vf_0A4();
    virtual void vf_0A8();
    virtual void vf_0AC();
    virtual void vf_0B0();
    virtual void vf_0B4();
    virtual void vf_0B8();
    virtual void vf_0BC();
    virtual void vf_0C0();
    virtual void vf_0C4();
    virtual void vf_0C8();
    virtual void vf_0CC();
    virtual void vf_0D0();
    virtual void vf_0D4();
    virtual void vf_0D8();
    virtual void vf_0DC();
    virtual void vf_0E0();
    virtual void vf_0E4();
    virtual void set_text(char* text);

    char gap_04[0x7C];
    int panel_state_80;
    char gap_84[0x6A];
    unsigned char panel_flag_EE;
    char gap_EF[0x05];
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void draw();

    void* list;                         // +0xF4
    short num_lines;                    // +0xF8
    short draw_lines;                   // +0xFA
    short top_line;                     // +0xFC
    short bot_line;                     // +0xFE
    short cur_line;                     // +0x100
    short cur_col;                      // +0x102
    void* font;                         // +0x104
    long font_wid;                      // +0x108
    long font_hgt;                      // +0x10C
    long vert_align;                    // +0x110
    long horz_align;                    // +0x114
    int word_wrap;                      // +0x118
    long text_style;                    // +0x11C
    unsigned long text_color1;          // +0x120
    unsigned long text_color2;          // +0x124
    unsigned long highlight_text_color1;// +0x128
    unsigned long highlight_text_color2;// +0x12C
    void* scbar_panel;                  // +0x130
    int auto_scbar;                     // +0x134
    short fixed_len;                    // +0x138
    char gap_13A[0x02];
    long text_wid;                      // +0x13C
    long text_hgt;                      // +0x140
    void* back_pic;                     // +0x144
    short back_pic_wid;                 // +0x148
    short back_pic_hgt;                 // +0x14A
    int fill_back;                      // +0x14C
    unsigned char back_color;            // +0x150
    char gap_151[0x03];
    int outline;                        // +0x154
    unsigned char outline_color;         // +0x158
    char gap_159[0x03];
    int sorted;                         // +0x15C
    long second_column_pos;             // +0x160
    long full_width;                    // +0x164
    long scbar_width;                   // +0x168
    int scbar_active;                   // +0x16C
    int bevel_type;                     // +0x170
    unsigned char bevel_color1;          // +0x174
    unsigned char bevel_color2;          // +0x175
    unsigned char bevel_color3;          // +0x176
    unsigned char bevel_color4;          // +0x177
    unsigned char bevel_color5;          // +0x178
    unsigned char bevel_color6;          // +0x179
    char gap_17A[0x02];
    void* clip_rgn2;                    // +0x17C
    int border_size;                    // +0x180
    int spacer_size;                    // +0x184

    TTextPanel();
};

TTextPanel::TTextPanel()
{
    this->back_color = 0xFF;
    this->list = 0;
    this->num_lines = 0;
    this->draw_lines = 0;
    this->top_line = 0;
    this->bot_line = 0;
    this->cur_line = 0;
    this->cur_col = 0;
    this->font = 0;
    this->font_wid = 0;
    this->font_hgt = 0;
    this->vert_align = 0;
    this->horz_align = 0;
    this->word_wrap = 0;
    this->text_style = 2;
    this->text_color1 = 0xFFFFFF;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;
    this->scbar_panel = 0;
    this->auto_scbar = 0;
    this->fixed_len = 0;
    this->text_wid = 0;
    this->text_hgt = 0;
    this->back_pic = 0;
    this->back_pic_wid = 0;
    this->back_pic_hgt = 0;
    this->fill_back = 0;
    this->outline = 0;
    this->outline_color = 0;
    this->sorted = 0;
    this->second_column_pos = 0;
    this->full_width = 0;
    this->scbar_width = 0;
    this->scbar_active = 0;
    this->bevel_type = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->clip_rgn2 = 0;
    this->border_size = 0;
    this->spacer_size = 0;

    this->panel_state_80 = 0;
    this->highlight_text_color1 = 0xFFFF;
    this->panel_flag_EE = 1;
}
