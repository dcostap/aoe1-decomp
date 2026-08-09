// 0047D570 TTextPanel::draw_border
// Pnl_txt.cpp:1095-1133
//
// Canonical ownership: TTextPanel supplies the panel rectangle, outline and
// six bevel colors; TDrawArea supplies the lock/draw/unlock operations.  The
// switch intentionally keeps the period shared call tails for bevel types
// 2/5, 3/6, and 4/7.
//
// Attempt log:
// - Replaced the field-only scaffold with the same typed switch/lock/tail
//   shape as the exact same-TU Time_Line_Panel::draw_border donor.  Target
//   color fields are +0x174..+0x179 and outline_color is +0x158.

class TDrawArea {
public:
    unsigned char* Lock(char* name, int mode);
    void Unlock(char* name);
    void DrawRect(long x1, long y1, long x2, long y2, unsigned char color);
    void DrawBevel(long x1, long y1, long x2, long y2,
                   unsigned char c1, unsigned char c2);
    void DrawBevel2(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4);
    void DrawBevel3(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4,
                    unsigned char c5, unsigned char c6);
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x08];
    long x;                              // +0x0C
    long y;                              // +0x10
    long width;                          // +0x14
    long height;                         // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;              // +0x20
    char gap_24[0xD0];                   // TPanel ends at +0xF4
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x60];                   // through +0x154
    int outline;                         // +0x154
    unsigned char outline_color;         // +0x158
    char gap_159[0x17];                  // through +0x170
    int bevel_type;                      // +0x170
    unsigned char bevel_color1;          // +0x174
    unsigned char bevel_color2;          // +0x175
    unsigned char bevel_color3;          // +0x176
    unsigned char bevel_color4;          // +0x177
    unsigned char bevel_color5;          // +0x178
    unsigned char bevel_color6;          // +0x179

    void draw_border();
};

void TTextPanel::draw_border()
{
    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_txt::draw_border", 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->outline_color);
                break;
            case 2:
                this->render_area->DrawBevel(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color4, this->bevel_color3,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(
                    this->x, this->y,
                    this->x + this->width - 1,
                    this->y + this->height - 1,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("pnl_txt::draw_border");
    }
}
