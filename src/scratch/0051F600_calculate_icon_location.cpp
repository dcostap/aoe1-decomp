// 0051F600 Time_Line_Panel::calculate_icon_location
// Attempt log:
// try 1-10 (prior worker): decompiler-shaped reconstruction with an incomplete
// Special_Events/Time_Line_Panel surface and a two-argument ABI; exact size was
// padded but the emitted body was broad drift.
// baseline candidate: restored the ground-truth Special_Events and
// Time_Line_Panel ownership/layout, the three-argument __thiscall ABI, the
// typed TShape reference surface, and direct strlen/switch source shape.
// probe 2: changed the valid flag to period-style `ok = 1` with an explicit
// null test; this recovered the original prologue and reduced the strict diff.
// probe 3: reversed the ordinary zero-initialized local declaration order;
// this recovered the +20/+1c/+18 initialization homes exactly.
// probe 4: reversed the centered-icon bound predicate; only the compare
// allocation changed, but the original operand polarity remained supported.
// probe 5: a named centered-x temporary was codegen-duplicate and rolled back.
// probe 7: a named right-bound temporary was codegen-duplicate and rolled back.
// probe 8: delayed case-2's text-x store with a scoped case local; this kept
// separate case-0/case-2 handlers and improved emitted size by 20 bytes.
// probe 9: named max-x/product-first truncation predicates were effectively
// duplicate; retained only as the cleaner phase-local source form.
// probe 10: swapping semantic start-x/start-y local ownership regressed the
// proven initialization homes; restored the probe-9 source.
// current claim probe: a separate natural left-x temporary was codegen-
// duplicate; restored the clean source.
// current claim probe: reversed the three text-fit predicates so the overflow
// arm stays inline and the fit arm branches to the later block; this reduced
// the strict diff by one byte and improved block topology, so it is retained.
// current claim probe: nested the post-shape-bounds ok guard as suggested by
// the decompiler's proven nested source structure; it worsened size by 8 bytes
// and lost the exact block at +00a4, so it was restored.
// Paused blocker: the typed ABI/layout, frame, saved-register set, and three
// direct calls are exact, but VC5 still chooses the wrong centered-bound
// register/reload topology and omits the oracle's case-0 stack stores and
// modes-6/8 parameter-home spill.  The remaining branch/case placement and
// final temporary coloring are structural/source-shape leads, not a safe blind
// register tweak.  No inline asm or opaque address plumbing was used.

#include <string.h>

typedef unsigned char uchar;

class TShape {
public:
    long shape_count();
    unsigned char shape_bounds(long index, short& width, short& height);
};

class Special_Events {
public:
    long time_slice;
    long X_line_pos;
    long Y_line_pos;
    long intermediate_y_line_segment;
    uchar player_id;
    uchar player_color;
    uchar event;
    uchar gap_13;
    long pop_total;
    long integer_value_1;
    long integer_value_2;
    long start_x;
    long start_y;
    long start_txt_x1;
    long start_txt_y1;
    long start_txt_x2;
    long start_txt_y2;
    int text_length1;
    char text1[50];
    uchar gap_6e[2];
    int text_length2;
    char text2[50];
    uchar gap_a6[2];
    int icon_flag;
    Special_Events* next;
};

class Time_Line_Panel {
public:
    char gap_000[0x478];
    void* axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    void* body_font;
    long body_font_wid;
    long body_font_hgt;
    int text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    long text_wid;
    long text_hgt;
    char gap_4ac[0x28];
    TShape* special_events_pic;
    short special_events_pic_wid;
    short special_events_pic_hgt;
    long X_start_line_pos;
    long Y_start_line_pos;
    long X_line_pos;
    long Y_line_pos;
    long X_line_max_width;
    long Y_line_max_length;
    long X_axis_length;
    long Y_axis_length;
    float bar_thickness;
    long pop_reading_rate;
    float time_slice_drop_rate;
    long total_slices_to_drop;
    uchar drop_flag;
    uchar gap_50d[3];
    long num_entries_page;
    long num_history_entries;
    Special_Events* time_slice_events;
    uchar timeline_flag;

    int calculate_icon_location(Special_Events*, short, uchar);
};

int Time_Line_Panel::calculate_icon_location(
    Special_Events* param_1, short param_2, uchar param_3)
{
    Special_Events* event = param_1;
    short width;
    short height;
    int bounds_result;
    int ok = 1;
    int local_4 = 0;
    long start_y = 0;
    long start_x = 0;
    int body_height;
    int max_length;
    int top;
    int max_x;

    event->icon_flag = 0;

    if (this->special_events_pic == 0) {
        ok = 0;
    }
    if (this->special_events_pic->shape_count() == 0) {
        ok = 0;
    }
    if (this->special_events_pic->shape_count() < (long)param_2) {
        ok = 0;
    }

    if (ok != 0) {
        this->special_events_pic->shape_bounds(param_2, width, height);
        if (width > 0) {
            this->special_events_pic_wid = width;
        }
        if (height > 0) {
            this->special_events_pic_hgt = height;
        }
    }

    if (ok != 0) {
        if (this->special_events_pic_hgt > event->intermediate_y_line_segment) {
            ok = 0;
        }

        int half_width = this->special_events_pic_wid / 2;
        if (event->X_line_pos + half_width >
            this->X_line_max_width + this->X_start_line_pos) {
            ok = 0;
        }
        half_width = event->X_line_pos - half_width;
        if (half_width < this->X_start_line_pos) {
            ok = 0;
        }

        if (ok != 0) {
            start_x = (event->intermediate_y_line_segment / 2 +
                       event->Y_line_pos * 2) -
                      this->special_events_pic_hgt / 2;
            local_4 = half_width;
        }
    }

    switch (event->event) {
    case 0:
        event->text_length1 = strlen(event->text1);
        bounds_result = this->body_font_wid * event->text_length1;
        if (bounds_result + 2 + event->X_line_pos >=
            this->X_line_max_width + this->X_start_line_pos) {
            start_y = this->X_line_max_width - bounds_result - 3 +
                      this->X_start_line_pos;
        } else {
            start_y = event->X_line_pos + 2;
        }
        bounds_result = event->Y_line_pos +
                        event->intermediate_y_line_segment -
                        this->body_font_hgt;
        break;

    case 1:
        event->text_length1 = strlen(event->text1);
        bounds_result = this->body_font_wid * event->text_length1;
        if (bounds_result + 2 + event->X_line_pos >=
            this->X_line_max_width + this->X_start_line_pos) {
            start_y = this->X_line_max_width - bounds_result - 8 +
                      this->X_start_line_pos;
        } else {
            start_y = event->X_line_pos + 2;
        }
        bounds_result = event->Y_line_pos;
        if (this->Y_start_line_pos + this->Y_line_max_length <=
            this->body_font_hgt + 2 + bounds_result) {
            bounds_result = this->Y_start_line_pos +
                            this->Y_line_max_length -
                            this->body_font_hgt - 2;
            goto store_location;
        }
        goto top_location;

    case 2:
    {
        event->text_length1 = strlen(event->text1);
        bounds_result = this->body_font_wid * event->text_length1;
        int case2_x;
        if (bounds_result + 2 + event->X_line_pos >=
            this->X_line_max_width + this->X_start_line_pos) {
            case2_x = this->X_line_max_width - bounds_result - 3 +
                      this->X_start_line_pos;
        } else {
            case2_x = event->X_line_pos + 2;
        }
        bounds_result = event->Y_line_pos +
                        event->intermediate_y_line_segment -
                        this->body_font_hgt;
        start_y = case2_x;
        break;
    }

    default:
        goto store_location;

    case 6:
        max_x = this->X_start_line_pos + this->X_line_max_width;
        if ((int)(strlen(event->text1) * this->body_font_wid +
                  event->X_line_pos) > max_x) {
            event->text_length1 =
                (max_x - event->X_line_pos) / this->body_font_wid;
        } else {
            event->text_length1 = strlen(event->text1);
        }
        if (event->text_length1 > 2) {
            event->text_length1 = 2;
        }
        bounds_result = this->special_events_pic_hgt;
        body_height = this->body_font_hgt;
        max_length = this->Y_line_max_length;
        top = this->Y_start_line_pos;
        if (max_length + top < start_x + body_height + 1 + bounds_result) {
            start_x = (max_length - body_height) - bounds_result - 1 + top;
        }
        start_y = local_4;
        bounds_result = start_x + 1 + bounds_result;
        goto store_location;

    case 8:
        max_x = this->X_start_line_pos + this->X_line_max_width;
        if ((int)(strlen(event->text1) * this->body_font_wid +
                  event->X_line_pos) > max_x) {
            event->text_length1 =
                (max_x - event->X_line_pos) / this->body_font_wid;
        } else {
            event->text_length1 = strlen(event->text1);
        }
        if (event->text_length1 > 5) {
            event->text_length1 = 5;
        }
        bounds_result = this->special_events_pic_hgt;
        body_height = this->body_font_hgt;
        max_length = this->Y_line_max_length;
        top = this->Y_start_line_pos;
        if (max_length + top < start_x + body_height + 1 + bounds_result) {
            start_x = (max_length - body_height) - bounds_result - 1 + top;
        }
        start_y = local_4;
        bounds_result = start_x + 1 + bounds_result;
        goto store_location;
    }

    bounds_result -= 2;
    {
        int top = this->Y_start_line_pos;
        if (top < bounds_result) {
            int bottom = this->Y_line_max_length + top;
            if (bottom <= bounds_result) {
                bounds_result = bottom - this->body_font_hgt - 3;
            }
        } else {
            bounds_result = top + 2;
        }
    }
    goto store_location;

top_location:
    bounds_result = event->Y_line_pos + 2;
    goto store_location;

store_location:
    event->start_x = local_4;
    event->start_txt_x1 = start_y;
    event->start_y = start_x;
    event->start_txt_y1 = bounds_result;
    if (ok != 0) {
        event->icon_flag = 1;
    }
    return ok;
}
