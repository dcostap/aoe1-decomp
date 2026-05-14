// 0051F120 Time_Line_Panel::draw_border
// Attempt log:
// 1: Natural switch reconstruction from packet, local TDrawArea method surface: 8.17% diff, exact size; class field offsets after +18 were 4 bytes low.
// 2: Add missing +1C..+1F gap so draw_area/bevel/color offsets match packet: only one byte diff remains, lock-fail branch target skipped Unlock.
// 3: Move Unlock outside the Lock-success guarded switch so lock failure/default both execute Unlock like original.

class TDrawArea {
public:
    unsigned char* Lock(char* name, int mode);
    void Unlock(char* name);
    void DrawRect(long x1, long y1, long x2, long y2, unsigned char color);
    void DrawBevel2(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2);
    void DrawBevel4(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4);
    void DrawBevel6(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6);
};

class Time_Line_Panel {
public:
    char gap_00[0x0c];
    long y1;
    long x1;
    long y2;
    long x2;
    char gap_1c[4];
    TDrawArea* draw_area;
    char gap_24[0x4c0 - 0x24];
    unsigned char border_color;
    char gap_4c1[0x4c8 - 0x4c1];
    long bevel_type;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned char c5;

    void draw_border();
};

void Time_Line_Panel::draw_border()
{
    if (this->bevel_type != 0) {
        if (this->draw_area->Lock((char*)0x58b770, 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->draw_area->DrawRect(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->border_color);
                break;
            case 2:
                this->draw_area->DrawBevel2(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->c5, this->c0);
                break;
            case 3:
                this->draw_area->DrawBevel4(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->c5, this->c4, this->c1, this->c0);
                break;
            case 4:
                this->draw_area->DrawBevel6(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->c5, this->c4, this->c3, this->c2, this->c1, this->c0);
                break;
            case 5:
                this->draw_area->DrawBevel2(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->c0, this->c5);
                break;
            case 6:
                this->draw_area->DrawBevel4(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->c0, this->c1, this->c4, this->c5);
                break;
            case 7:
                this->draw_area->DrawBevel6(this->y1, this->x1, this->y2 + this->y1 - 1, this->x2 + this->x1 - 1, this->c0, this->c1, this->c2, this->c3, this->c4, this->c5);
                break;
            }
        }
        this->draw_area->Unlock((char*)0x58b770);
    }
}
