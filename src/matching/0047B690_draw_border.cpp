// VA: 0047B690 TScrollBarPanel::draw_border
// Source: Pnl_scbr.cpp lines 703-759
// Attempt log:
// 1: natural switch reconstruction from packet.

class TDrawArea {
public:
    void DrawRect(long left, long top, long right, long bottom, unsigned char color);
    void DrawVertLine(long x, long y, long len, unsigned char color);
    void DrawHorzLine(long x, long y, long len, unsigned char color);
    void DrawBevel(long left, long top, long right, long bottom, unsigned char c1, unsigned char c2);
    void DrawBevel2(long left, long top, long right, long bottom, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4);
    void DrawBevel3(long left, long top, long right, long bottom, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6);
};

class TScrollBarPanel {
public:
    char gap_00[0x20];
    TDrawArea* draw_area;
    char gap_24[0x1B8 - 0x24];
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;

    void draw_border(int raised, int flag, long left, long top, long right, long bottom);
};

void TScrollBarPanel::draw_border(int raised, int flag, long left, long top, long right, long bottom)
{
    if (left != right && top != bottom) {
        if (flag != 0) {
            switch (this->bevel_type) {
            case 1:
                if (raised != 0) {
                    this->draw_area->DrawRect(left + 1, top + 1, right, bottom, 0xff);
                } else {
                    this->draw_area->DrawRect(left, top, right - 1, bottom, 0xff);
                }
                return;
            case 2:
                this->draw_area->DrawBevel(left, top, right, bottom, this->bevel_color6, this->bevel_color1);
                return;
            case 3:
                this->draw_area->DrawBevel2(left, top, right, bottom, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                return;
            case 4:
                this->draw_area->DrawBevel3(left, top, right, bottom, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                return;
            }
        } else {
            switch (this->bevel_type) {
            case 1:
                if (raised != 0) {
                    this->draw_area->DrawVertLine(right, top + 1, bottom - top, 0);
                    this->draw_area->DrawHorzLine(left + 1, top, right - left, 0);
                    this->draw_area->DrawRect(left, top, right - 1, top - 1, 0xff);
                } else {
                    this->draw_area->DrawRect(left, top, right - 1, bottom, 0);
                }
                return;
            case 2:
                this->draw_area->DrawBevel(left, top, right, bottom, this->bevel_color1, this->bevel_color6);
                return;
            case 3:
                this->draw_area->DrawBevel2(left, top, right, bottom, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                return;
            case 4:
                this->draw_area->DrawBevel3(left, top, right, bottom, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                return;
            }
        }
    }
}
