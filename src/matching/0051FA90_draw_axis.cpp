// VA: 0051FA90 Time_Line_Panel::draw_axis
// Attempt log:
// - The prior rough source used a raw palette pointer, wrong GDI calls, wrong
//   string helper, and four-argument FillRect calls. It was not a valid source
//   reconstruction.
// - Rebuilt the panel geometry from the exact tpnl_tml.cpp donors and the
//   original call order. The palette belongs to DrawSystem::Pal. The axis is
//   four typed FillRect calls with the saved palette index as the fifth arg.
// - Baseline: this typed source reached 744 bytes with all 38 calls ordered,
//   but the third and fourth top edges lacked Y_axis_length.
// - Added the proven Y_axis_length terms. The result reached 762 bytes and
//   exposed the original centered-label load order.
// - Split centered-label x placement into ordered statements. This restored
//   the X_start_line_pos reload before strlen and produced an exact match.
// Exact: 760/760 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.

#include <windows.h>
#include <string.h>

typedef unsigned char uchar;

extern char s_tpnl_tml_draw_axis[];

#ifndef TPNL_TML_WRAPPER
struct TDrawSystem {
    char gap_00[8];
    void* Pal;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    HDC DrawDc;

    uchar* Lock(char*, int);
    void Unlock(char*);
    void FillRect(long, long, long, long, uchar);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class Time_Line_Panel {
public:
    char gap_000[0x20];
    TDrawArea* render_area;
    char gap_024[0x454];
    HGDIOBJ axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    char gap_484[0x4dc - 0x484];
    long X_start_line_pos;
    long Y_start_line_pos;
    long X_line_pos;
    long Y_line_pos;
    long X_line_max_width;
    long Y_line_max_length;
    long X_axis_length;
    long Y_axis_length;

    long xPosition();
    long yPosition();
    long height();
    int get_string(int, char*, int);
    void draw_axis();
};
#endif

void Time_Line_Panel::draw_axis()
{
    HGDIOBJ old_font;
    char temp_str[100];
    uchar white_color;

    white_color = (uchar)GetNearestPaletteIndex(
        this->render_area->DrawSystem->Pal, 0xFFFFFF);

    if (this->render_area->Lock(s_tpnl_tml_draw_axis, 1) != 0) {
        this->render_area->FillRect(
            this->xPosition() + 0x19,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0C
                + this->Y_axis_length,
            this->xPosition() + 0x18 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D
                + this->Y_axis_length,
            white_color);

        this->render_area->FillRect(
            this->xPosition() + 0x19,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D,
            this->xPosition() + 0x18 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0E,
            white_color);

        this->render_area->FillRect(
            this->xPosition() + 0x19,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D,
            this->xPosition() + 0x1A,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D
                + this->Y_axis_length,
            white_color);

        this->render_area->FillRect(
            this->xPosition() + 0x17 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D,
            this->xPosition() + 0x18 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D
                + this->Y_axis_length,
            white_color);
    }

    this->render_area->Unlock(s_tpnl_tml_draw_axis);
    if (this->render_area->GetDc(s_tpnl_tml_draw_axis) != 0) {
        SetBkMode(this->render_area->DrawDc, 1);
        old_font = SelectObject(this->render_area->DrawDc, this->axis_font);

        if (this->get_string(0x2C57, temp_str, 100) != 0) {
            int x = this->xPosition() + 8;
            int y = this->yPosition() + 5;
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            TextOutA(this->render_area->DrawDc, x, y, temp_str,
                     strlen(temp_str));
        }

        if (this->get_string(0x2C56, temp_str, 100) != 0) {
            int x = this->X_start_line_pos;
            x -= (strlen(temp_str) * this->axis_font_wid) / 2;
            x += this->X_axis_length / 2;
            int y = this->height();
            y += this->yPosition();
            y -= this->axis_font_hgt + 5;
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            TextOutA(this->render_area->DrawDc, x, y, temp_str,
                     strlen(temp_str));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_tml_draw_axis);
    }
}
