// Attempt log for 00520AE0 Time_Line_Panel::draw_icon
// try 1: natural reconstruction from packet/decompiler with minimal surfaces; too small 528B.
// try 2: add all post-location draw cases and closer decompiler fields; exact size but EBP=this, no IAT ptr local, wrong palette +8 load.
// try 3: use self local, explicit GetNearestPaletteIndex function-pointer local, and palette[2] expression; edit diff improved to 31.5%, but EBP=this instead of EBX=this.
// try 4: predeclare minute/hour locals at top to encourage EBP as arithmetic local; no codegen change.
// try 5: /O1 flag probe; too small 422B, rolled back.
// try 6: /Oy- flag probe; worse from offset 0, rolled back.
// try 7: remove self local and use direct this to probe EBX allocation; no change.
// try 8: remove getNearest local and call import pointer directly; worse (75.7%/33.9%), rolled back.
// try 9: restore getNearest local best form.
// try 10: reviewed switch vs if-chain; switch dispatch matches original jump-table family, so kept.
// BLOCKER: exact 581B size, call set and much of structure plausible, but register allocation remains wrong from prologue (rebuilt EBP=this, original EBX=this with EBP used later for hour quotient). This shifts all this-relative encodings and broad positional diff. Not accepted_drift-safe.

#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;
extern "C" unsigned int (__stdcall* const GetNearestPaletteIndex)(void*, unsigned int);

class TDrawArea { public: void DrawVertLine(long,long,long,uchar); };
class TShape { public: uchar shape_draw(TDrawArea*, short, long, long, long, long, long); };
class Special_Events { public: int time_slice; int X_line_pos; int Y_line_pos; int intermediate_y_line_segment; int pop_total; int integer_value_1; int integer_value_2; int start_x; int start_y; int gap24; int gap28; int gap2c; unsigned char event; char gap_31[0x0b]; char text1[0x34]; int text_length1; char text2[0x34]; int text_length2; };
class Time_Line_Panel { public: void* vtable; char gap_04[0x1c]; TDrawArea* draw_area; char gap_24[0x4b0]; TShape* shape; int get_string(int, char*, int); int calculate_icon_location(Special_Events*, short, uchar); void draw_icon(Special_Events*, short, uchar); };

void Time_Line_Panel::draw_icon(Special_Events* ev, short param_2, uchar param_3)
{
    char temp_str[50];
    uchar black_color;
    int hi_top;
    int q_top;
    unsigned int (__stdcall* getNearest)(void*, unsigned int) = GetNearestPaletteIndex;
    getNearest((*(void***)this->draw_area)[2], 0xffffff);
    black_color = (uchar)getNearest((*(void***)this->draw_area)[2], 0);

    switch (ev->event) {
    case 0:
        if (this->get_string(0x106a, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 1:
        if (this->get_string(0x106b, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 2:
        if (this->get_string(0x106c, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 8:
        sprintf(temp_str + 4, "%ld/%1d", ev->integer_value_1, ev->integer_value_2);
        sprintf(ev->text1, "%s", temp_str + 4);
        // fall through
    case 3: {
        sprintf(ev->text1, "%ld", ev->pop_total);
        ev->text_length1 = strlen(ev->text1);
        int total = ev->time_slice * 15;
        hi_top = 0;
        if (total > 59) {
            q_top = total / 60;
            if (q_top > 59) {
                hi_top = q_top / 60;
                q_top = q_top - hi_top * 60;
            }
            total = q_top;
        }
        sprintf(temp_str + 4, "%1ld:%02ld", hi_top, total);
        sprintf(ev->text2, "%s", temp_str + 4);
        ev->text_length2 = strlen(ev->text2);
        break;
    }
    default:
        break;
    }

    int ok = this->calculate_icon_location(ev, param_2, param_3);
    switch (ev->event) {
    case 0:
        this->draw_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, black_color);
        return;
    case 1:
        this->draw_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, black_color);
        return;
    case 2:
        this->draw_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, black_color);
        return;
    default:
        if (ok) {
            this->shape->shape_draw(this->draw_area, param_2, ev->start_x, ev->start_y, 0, 0, 0);
        }
        return;
    }
}
