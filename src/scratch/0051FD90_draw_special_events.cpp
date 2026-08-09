// 0051FD90 Time_Line_Panel::draw_special_events (tpnl_tml.cpp:923-1055)
// Attempt log:
// - Existing baseline used an incorrect EventNode layout, IsLocked/TextOut switch,
//   and a sub-esp frame; it was 674 bytes but only 73.7% call-site aligned.
// - Reconstructed the period TDrawSystem/TDrawArea palette ownership, exact
//   Special_Events offsets, Lock->Unlock->GetDc lifecycle, and the two switch
//   families from the executable packet.  The first compile is the current
//   structural hypothesis; further probes will focus on switch duplication and
//   text-expression source order.
// - Correct palette ownership changed the two calls to load TDrawSystem::Pal
//   ([draw_area]->[0]->[8]) and brought the ordered call set to 19/19.
// - Direct per-case draw_icon calls preserved a clean natural source but left
//   four duplicated pushes for the -1 position; the shared-local/goto variants
//   added a stack home and were rolled back as less plausible and farther.
// - Removing named x/y temporaries from the type-3 text path kept the frame
//   smaller and improved the resynchronized diff; the nearest-pointer scope
//   and shared iterator/lifetime probes emitted duplicate code.
// - Independent named strlen temporaries caused a larger frame.  The final
//   natural expression keeps the two binary-observed strlen scans inline, so
//   VC5 pushes the TextOut length before yPosition and rescans for centering.
// - Grouping event types 0..3 at one draw_icon body with the shared -1
//   position is the current best source reconstruction: exact size/frame,
//   19/19 ordered calls, 95.53% shape, 86.18% exact blocks. Main-agent string
//   normalization improved the strict diff from 570 to 569 bytes. The
//   remaining drift begins in the first switch's byte-load/jump-table shape;
//   budget exhausted without a source-plausible exact lead.

#include <string.h>

typedef unsigned char uchar;
typedef void* HDC;
typedef void* HGDIOBJ;
typedef unsigned int COLORREF;

extern "C" {
extern unsigned int (__stdcall* const GetNearestPaletteIndex)(void*, unsigned int);
extern COLORREF (__stdcall* const SetTextColor)(HDC, COLORREF);
extern int (__stdcall* const SetBkMode)(HDC, int);
extern HGDIOBJ (__stdcall* const SelectObject)(HDC, HGDIOBJ);
extern int (__stdcall* const TextOutA)(HDC, int, int, const char*, int);
}

class TDrawSystem {
public:
    void* inst;
    void* wnd;
    void* palette;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;       // +0x00
    char gap_04[0x34];
    HDC DrawDc;                    // +0x38

    uchar* Lock(char*, int);
    void Unlock(char*);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

struct Special_Events {
    long time_slice;                       // +0x00
    long X_line_pos;                       // +0x04
    long Y_line_pos;                       // +0x08
    long intermediate_y_line_segment;      // +0x0C
    uchar player_id;                       // +0x10
    uchar player_color;                    // +0x11
    uchar event;                            // +0x12
    char gap_13;
    long pop_total;                        // +0x14
    long integer_value_1;                  // +0x18
    long integer_value_2;                  // +0x1C
    long start_x;                          // +0x20
    long start_y;                          // +0x24
    long start_txt_x1;                     // +0x28
    long start_txt_y1;                     // +0x2C
    long start_txt_x2;                     // +0x30
    long start_txt_y2;                     // +0x34
    long text_length1;                     // +0x38
    char text1[0x34];                      // +0x3C
    long text_length2;                     // +0x70
    char text2[0x34];                      // +0x74
    long icon_flag;                        // +0xA8
    Special_Events* next;                  // +0xAC
};

class Time_Line_Panel {
public:
    char gap_000[0x20];
    TDrawArea* render_area;                // +0x20
    char gap_024[0x454];                    // +0x24..+0x477
    void* axis_font;                       // +0x478
    long axis_font_wid;                    // +0x47C
    long axis_font_hgt;                    // +0x480
    HGDIOBJ body_font;                     // +0x484
    long body_font_wid;                    // +0x488
    long body_font_hgt;                    // +0x48C
    char gap_490[0x88];                     // +0x490..+0x517
    Special_Events* time_slice_events;     // +0x518
    uchar timeline_flag;                   // +0x51C

    long yPosition();
    long height();
    void draw_icon(Special_Events*, short, uchar);
    void draw_special_events();
};

void Time_Line_Panel::draw_special_events()
{
    Special_Events* event;
    HGDIOBJ old_font;

    if (this->timeline_flag != 0) {
        {
            unsigned int (__stdcall* nearest)(void*, unsigned int) =
                GetNearestPaletteIndex;
            nearest(this->render_area->DrawSystem->palette, 0xFFFFFF);
            nearest(this->render_area->DrawSystem->palette, 0);
        }

        if (this->render_area->Lock("tpnl_tml::draw_special_events", 1) != 0) {
            for (event = this->time_slice_events;
                 event != 0; event = event->next) {
                switch (event->event) {
                case 0:
                case 1:
                case 2:
                case 3:
                    this->draw_icon(event, -1, event->event);
                    break;
                case 4:
                    this->draw_icon(event, 0, 4);
                    break;
                case 5:
                    this->draw_icon(event, 1, 5);
                    break;
                case 6:
                    this->draw_icon(event, 2, 6);
                    break;
                case 7:
                    this->draw_icon(event, 3, 7);
                    break;
                case 8:
                    this->draw_icon(event, 4, 8);
                    break;
                }
            }
        }

        this->render_area->Unlock("tpnl_tml::draw_special_events");
        if (this->render_area->GetDc("tpnl_tml::draw_special_events") != 0) {
            SetBkMode(this->render_area->DrawDc, 1);
            old_font = SelectObject(this->render_area->DrawDc,
                                    this->body_font);

            for (event = this->time_slice_events;
                 event != 0; event = event->next) {
                switch (event->event) {
                case 0:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc,
                             event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 1:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc,
                             event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 2:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc,
                             event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 3: {
                    int x_offset = (event->time_slice != 0) ? -2 : 2;
                    SetTextColor(this->render_area->DrawDc, 0xFFFFFF);

                    TextOutA(this->render_area->DrawDc,
                             x_offset - (strlen(event->text1) >> 1)
                                 * this->axis_font_wid
                                 + event->X_line_pos,
                             this->yPosition() + 8 + this->axis_font_hgt,
                             event->text1, strlen(event->text1));
                    TextOutA(this->render_area->DrawDc,
                             x_offset - (strlen(event->text2) >> 1)
                                 * this->axis_font_wid
                                 + event->X_line_pos,
                             this->yPosition() + this->height()
                                 - this->axis_font_hgt * 2 - 7,
                             event->text2, strlen(event->text2));
                    break;
                }
                case 6:
                    if (event->icon_flag != 0) {
                        SetTextColor(this->render_area->DrawDc, 0);
                        TextOutA(this->render_area->DrawDc,
                                 event->start_txt_x1, event->start_txt_y1,
                                 event->text1, event->text_length1);
                    }
                    break;
                case 8:
                    if (event->icon_flag != 0) {
                        SetTextColor(this->render_area->DrawDc, 0);
                        TextOutA(this->render_area->DrawDc,
                                 event->start_txt_x1, event->start_txt_y1,
                                 event->text1, event->text_length1);
                    }
                    break;
                }
            }

            SelectObject(this->render_area->DrawDc, old_font);
            this->render_area->ReleaseDc("tpnl_tml::draw_special_events");
        }
    }
}
