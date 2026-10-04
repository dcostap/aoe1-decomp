
#include "../include/tpnl_tml.h"
#include "../include/game_globals.h"
#include "../include/pnl_lst.h"
#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/world.h"
#include "../include/tplayer.h"
#include "../include/t_histry.h"
#include "../include/color.h"
#include "../include/resource_ids.h"
#include <new.h>
#include <stdio.h>
#include <string.h>

static char s_tpnl_tml_draw_axis[] = "tpnl_tml::draw_axis";

extern "C" int __cdecl stricmp(const char*, const char*);

Time_Line_Panel::Time_Line_Panel()
    : axis_font(0),
      axis_font_wid(0),
      axis_font_hgt(0),
      body_font(0),
      body_font_wid(0),
      body_font_hgt(0),
      text_style(ChiseledStyle),
      text_color1(0xFFFFFF),
      text_color2(0),
      highlightTextColor1(0xFFFF),
      highlightTextColor2(0),
      text_wid(0),
      text_hgt(0),
      background_pic(0),
      background_pic_wid(0),
      background_pic_hgt(0),
      fill_back(0),
      back_color(0xFF),
      outline(0),
      outline_color(0),
      bevel_type(0),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0),
      special_events_pic(0),
      special_events_pic_wid(0),
      special_events_pic_hgt(0),
      total_slices_to_drop(0),
      time_slice_events(0) {
    this->handle_mouse_input = 0;
    this->timeline_flag = 1;
    this->drop_flag = 0;
    this->pop_reading_rate = 12;

    for (int i = 0; i < 3; i++) {
        this->legend_entry_text[i] = 0;
    }
}

Time_Line_Panel::~Time_Line_Panel() {
    Special_Events* p;

    while (this->time_slice_events != NULL) {
        p = this->time_slice_events;
        this->time_slice_events = p->next;
        free(p);
    }

    if (this->background_pic != NULL) {
        delete this->background_pic;
        this->background_pic = NULL;
    }

    if (this->special_events_pic != NULL) {
        delete this->special_events_pic;
        this->special_events_pic = NULL;
    }

    for (int i = 0; i < 3; i++) {
        this->delete_panel(reinterpret_cast<TPanel**>(&this->legend_entry_text[i]));
    }

}

long Time_Line_Panel::create_timeline(TPanel* parent, Time_Line_Panel** time_line, long x, long y, long width, long height, long axis_font_num, long body_font_num, long ideal_width, long ideal_height) {
    long left = parent->width() * x / ideal_width;
    long top = parent->height() * y / ideal_height;
    long right = parent->width() * width / ideal_width;
    long bottom = parent->height() * height / ideal_height;

    Time_Line_Panel* panel = new Time_Line_Panel();
    *time_line = panel;
    if (panel == 0 || panel->error_code != 0) {
        this->error_code = 1;
        return 0;
    }

    RGE_Font* axis_font;
    if (axis_font_num >= 0) {
        axis_font = rge_base_game->get_font(axis_font_num);
    } else {
        axis_font = rge_base_game->get_font(RGE_FONT_STANDARD);
    }

    RGE_Font* body_font;
    if (body_font_num >= 0) {
        body_font = rge_base_game->get_font(body_font_num);
    } else {
        body_font = rge_base_game->get_font(RGE_FONT_STANDARD);
    }

    if ((*time_line)->setup(parent->renderArea(), parent, left, top, right, bottom,
                            axis_font->font, axis_font->font_wid, axis_font->font_hgt,
                            body_font->font, body_font->font_wid, body_font->font_hgt, 0, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return 0;
    }

    (*time_line)->init_timeline();
    return 1;
}

long Time_Line_Panel::setup(
    TDrawArea* render_area_in,
    TPanel* parent_panel_in,
    long x_in,
    long y_in,
    long wid_in,
    long hgt_in,
    void* axis_font_in,
    long axis_font_wid_in,
    long axis_font_hgt_in,
    void* body_font_in,
    long body_font_wid_in,
    long body_font_hgt_in,
    char* back_pic_in,
    char* special_event_pic_in,
    int fill_back_in,
    unsigned char back_color_in,
    int outline_in,
    unsigned char outline_color_in
) {
    this->TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);

    this->fill_back = fill_back_in;
    this->back_color = back_color_in;
    this->outline = outline_in;
    this->outline_color = outline_color_in;

    if (outline_in) {
        this->bevel_type = 1;
    }

    this->set_axis_font(axis_font_in, axis_font_wid_in, axis_font_hgt_in);
    this->set_body_font(body_font_in, body_font_wid_in, body_font_hgt_in);
    this->set_background(back_pic_in);
    this->set_special_events(special_event_pic_in);

    unsigned char pal_idx = static_cast<unsigned char>(GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0));
    this->set_back_color(1, pal_idx);

    return 1;
}

void Time_Line_Panel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = bevel_type_in;
    bevel_color1 = c1;
    bevel_color2 = c2;
    bevel_color3 = c3;
    bevel_color4 = c4;
    bevel_color5 = c5;
    bevel_color6 = c6;
}

int Time_Line_Panel::set_background(char* file_name) {
    long x_max;
    long x_min;
    long y_max;
    long y_min;

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (file_name == 0 || *file_name == '\0') {
        return 0;
    }

    this->background_pic = new TShape(file_name, -1);
    this->background_pic->shape_minmax(x_max, x_min, y_max, y_min, static_cast<long>(0));
    this->background_pic_wid = static_cast<short>(y_max - x_max + 1);
    this->background_pic_hgt = static_cast<short>(y_min - x_min + 1);
    return 1;
}

int Time_Line_Panel::set_background(char* file_name, long resource_id) {
    long y_max;
    long y_min;
    long x_min;
    long x_max;
    char file_name2[260];

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (file_name != 0 && *file_name != 0 && stricmp(file_name, "none") != 0) {
        if (strchr(file_name, '.') == 0) {
            sprintf(file_name2, "%s.shp", file_name);
        } else {
            sprintf(file_name2, "%s", file_name);
        }
        this->background_pic = new TShape(file_name2, resource_id);
    } else if (resource_id != -1) {
        this->background_pic = new TShape("", resource_id);
    }

    if (this->background_pic != 0 && this->background_pic->is_loaded() == 0) {
        delete this->background_pic;
        this->background_pic = 0;
    }

    if (this->background_pic != 0) {
        this->background_pic->shape_minmax(x_max, x_min, y_max, y_min, static_cast<long>(0));
        this->background_pic_wid = static_cast<short>(y_max - x_max + 1);
        this->background_pic_hgt = static_cast<short>(y_min - x_min + 1);
        return 1;
    }
    return 0;
}

int Time_Line_Panel::set_special_events(char* file_name) {
    long x_min;
    long y_max;
    long y_min;
    long loc;
    if (this->special_events_pic) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }
    if (file_name && *file_name) {
        this->special_events_pic = new TShape(file_name, -1);
        this->special_events_pic->shape_minmax(y_max, loc, x_min, y_min, 0);
        this->special_events_pic_wid = static_cast<short>(x_min - y_max + 1);
        this->special_events_pic_hgt = static_cast<short>(y_min - loc + 1);
        return 1;
    }
    return 0;
}

int Time_Line_Panel::set_special_events(char* file_name, long resource_id) {
    long y_max;
    long y_min;
    long x_min;
    long x_max;
    char file_name2[260];

    if (this->special_events_pic != 0) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }

    if (file_name != 0 && *file_name != 0 && stricmp(file_name, "none") != 0) {
        if (strchr(file_name, '.') == 0) {
            sprintf(file_name2, "%s.shp", file_name);
        } else {
            sprintf(file_name2, "%s", file_name);
        }
        this->special_events_pic = new TShape(file_name2, resource_id);
    } else if (resource_id != -1) {
        this->special_events_pic = new TShape("", resource_id);
    }

    if (this->special_events_pic != 0 && this->special_events_pic->is_loaded() == 0) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
    }

    if (this->special_events_pic != 0) {
        this->special_events_pic->shape_minmax(x_max, x_min, y_max, y_min, static_cast<long>(0));
        this->special_events_pic_wid = static_cast<short>(y_max - x_max + 1);
        this->special_events_pic_hgt = static_cast<short>(y_min - x_min + 1);
        return 1;
    }
    return 0;
}

void Time_Line_Panel::set_axis_font(void* font_in, long font_wid_in, long font_hgt_in) {
    this->axis_font = font_in;
    this->axis_font_wid = font_wid_in;
    this->axis_font_hgt = font_hgt_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void Time_Line_Panel::set_body_font(void* font_in, long font_wid_in, long font_hgt_in) {
    this->body_font = font_in;
    this->body_font_wid = font_wid_in;
    this->body_font_hgt = font_hgt_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void Time_Line_Panel::set_back_color(int use_back_color_flag_in, unsigned char back_color_in) {
    this->fill_back = use_back_color_flag_in;
    this->back_color = back_color_in;
}

void Time_Line_Panel::draw_border() {
    if (this->bevel_type != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_border", 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->outline_color);
                break;
            case 2:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("tpnl_tml::draw_border");
    }
}


void Time_Line_Panel::init_timeline() {
    int i = 0;
    this->num_history_entries = 0;
    RGE_Game_World* world = rge_base_game->world;
    int count = static_cast<int>(world->player_num) - 1;
    if (count > 0) {
        do {
            int n = static_cast<TRIBE_Player*>(world->players[i + 1])
                        ->history->get_history_entry_num();
            if (this->num_history_entries < n) {
                this->num_history_entries = n;
            }
            i++;
            world = rge_base_game->world;
        } while (i < static_cast<int>(world->player_num) - 1);
    }

    int usable_X = -49 + this->width();
    if (this->num_history_entries == 0) {
        this->num_history_entries = 1;
        this->timeline_flag = 0;
    }

    this->time_slice_drop_rate = 0.0f;
    this->bar_thickness = static_cast<float>(usable_X) /
                          static_cast<float>(this->num_history_entries);

    if (this->bar_thickness < 1.0f) {
        this->bar_thickness = 1.0f;
        this->num_entries_page = usable_X;
        this->drop_flag = 1;
        this->total_slices_to_drop = this->num_history_entries - usable_X;
        this->time_slice_drop_rate =
            static_cast<float>(usable_X) /
            static_cast<float>(this->total_slices_to_drop);
    } else {
        this->num_entries_page = this->num_history_entries;
    }

    this->X_axis_length = static_cast<long>(static_cast<float>(this->num_entries_page) * this->bar_thickness) + 4;
    this->Y_axis_length = this->height() - this->axis_font_hgt * 4 - 26;
    this->X_start_line_pos = this->xPosition() + 27;
    int y = this->yPosition() + this->axis_font_hgt * 2 + 15;
    this->X_line_pos = this->X_start_line_pos;
    this->Y_start_line_pos = y;
    this->Y_line_pos = y;
    this->Y_line_max_length = this->Y_axis_length - 3;
    this->X_line_max_width = this->X_axis_length - 2;

    if (this->num_entries_page < 12) {
        this->pop_reading_rate = 1;
    } else {
        this->pop_reading_rate =
            static_cast<long>(static_cast<float>(this->num_entries_page - 1) * (1.0f / 12.0f));
    }
}

void Time_Line_Panel::add_pop_total_special_event(long sample_time_slice, long sample_pop_total, long sample_x_line_pos, int time_flag) {
    Special_Events* se = static_cast<Special_Events*>(calloc(1, 176));

    se->time_slice = sample_time_slice;
    se->X_line_pos = sample_x_line_pos;
    se->Y_line_pos = 0;
    se->intermediate_y_line_segment = 0;
    se->player_id = 0;
    se->player_color = 0;
    se->event = 3;
    se->pop_total = sample_pop_total;
    se->integer_value_1 = 0;
    se->integer_value_2 = 0;
    se->start_x = 0;
    se->start_y = 0;
    se->start_txt_x1 = 0;
    se->start_txt_y1 = 0;
    se->start_txt_x2 = 0;
    se->start_txt_y2 = 0;
    se->text_length1 = 0;
    se->text1[0] = 0;
    se->text_length2 = 0;
    se->text2[0] = 0;
    se->icon_flag = time_flag;
    se->next = this->time_slice_events;
    this->time_slice_events = se;
}

void Time_Line_Panel::record_special_event(
    unsigned char player_id, TRIBE_History_Info* history,
    unsigned char player_color, long time_slice, long x_line_pos,
    long y_line_pos, long intermediate_y_line_segment) {
    unsigned char event;
    if (!history->get_history_event(time_slice, event)) {
        return;
    }

    Special_Events* special_event = static_cast<Special_Events*>(calloc(1, 176));
    special_event->X_line_pos = x_line_pos;
    special_event->Y_line_pos = y_line_pos;
    special_event->intermediate_y_line_segment = intermediate_y_line_segment;
    special_event->time_slice = time_slice;
    special_event->player_id = player_id;
    special_event->player_color = player_color;
    special_event->event = event;
    special_event->pop_total = 0;
    special_event->integer_value_1 = 0;
    special_event->integer_value_2 = 0;
    special_event->start_x = 0;
    special_event->start_y = 0;
    special_event->start_txt_x1 = 0;
    special_event->start_txt_y1 = 0;
    special_event->start_txt_x2 = 0;
    special_event->start_txt_y2 = 0;
    special_event->text_length1 = 0;
    special_event->text1[0] = 0;
    special_event->text_length2 = 0;
    special_event->text2[0] = 0;
    special_event->icon_flag = 0;
    special_event->next = time_slice_events;
    time_slice_events = special_event;
}

int Time_Line_Panel::calculate_icon_location(
    Special_Events* event_ptr, short icon_number, unsigned char history_type) {
    int result = 1;
    long start_x = 0;
    long start_y = 0;
    long start_text_x = 0;
    long start_text_y = 0;

    event_ptr->icon_flag = 0;

    if (this->special_events_pic == 0) {
        result = 0;
    }
    if (this->special_events_pic->shape_count() == 0) {
        result = 0;
    }
    if (this->special_events_pic->shape_count() < icon_number) {
        result = 0;
    }

    if (result != 0) {
        short width;
        short height;
        this->special_events_pic->shape_bounds(icon_number, width, height);
        if (width > 0) {
            this->special_events_pic_wid = width;
        }
        if (height > 0) {
            this->special_events_pic_hgt = height;
        }
    }

    if (result != 0) {
        if (this->special_events_pic_hgt > event_ptr->intermediate_y_line_segment) {
            result = 0;
        }
        long half_width = this->special_events_pic_wid / 2;
        if (event_ptr->X_line_pos + half_width > this->X_start_line_pos + this->X_line_max_width) {
            result = 0;
        }
        long icon_start_x = event_ptr->X_line_pos - half_width;
        if (icon_start_x < this->X_start_line_pos) {
            result = 0;
        }

        if (result != 0) {
            start_x = icon_start_x;
            start_y = event_ptr->Y_line_pos * 2
                + event_ptr->intermediate_y_line_segment / 2
                - this->special_events_pic_hgt / 2;
        }
    }

    switch (event_ptr->event) {
    case 0: {
        event_ptr->text_length1 = strlen(event_ptr->text1);
        long text_width = this->body_font_wid * event_ptr->text_length1;
        if (event_ptr->X_line_pos + text_width + 2 < this->X_start_line_pos + this->X_line_max_width) {
            start_text_x = event_ptr->X_line_pos + 2;
        } else {
            start_text_x = this->X_start_line_pos
                + this->X_line_max_width - text_width - 3;
        }

        start_text_y = event_ptr->Y_line_pos
            + event_ptr->intermediate_y_line_segment
            - this->body_font_hgt - 2;
        if (start_text_y <= this->Y_start_line_pos) {
            start_text_y = this->Y_start_line_pos + 2;
        } else if (start_text_y >= this->Y_start_line_pos + this->Y_line_max_length) {
            start_text_y = this->Y_start_line_pos
                + this->Y_line_max_length - this->body_font_hgt - 3;
        }
        break;
    }

    case 1: {
        event_ptr->text_length1 = strlen(event_ptr->text1);
        long text_width = this->body_font_wid * event_ptr->text_length1;
        if (event_ptr->X_line_pos + text_width + 2 < this->X_start_line_pos + this->X_line_max_width) {
            start_text_x = event_ptr->X_line_pos + 2;
        } else {
            start_text_x = this->X_start_line_pos
                + this->X_line_max_width - text_width - 8;
        }

        if (event_ptr->Y_line_pos + this->body_font_hgt + 2 < this->Y_start_line_pos + this->Y_line_max_length) {
            start_text_y = this->Y_start_line_pos + 2;
        } else {
            start_text_y = this->Y_start_line_pos
                + this->Y_line_max_length - this->body_font_hgt - 2;
        }
        break;
    }

    case 2: {
        event_ptr->text_length1 = strlen(event_ptr->text1);
        long text_width = this->body_font_wid * event_ptr->text_length1;
        if (event_ptr->X_line_pos + text_width + 2 < this->X_start_line_pos + this->X_line_max_width) {
            start_text_x = event_ptr->X_line_pos + 2;
        } else {
            start_text_x = this->X_start_line_pos
                + this->X_line_max_width - text_width - 3;
        }

        start_text_y = event_ptr->Y_line_pos
            + event_ptr->intermediate_y_line_segment
            - this->body_font_hgt - 2;
        if (start_text_y <= this->Y_start_line_pos) {
            start_text_y = this->Y_start_line_pos + 2;
        } else if (start_text_y >= this->Y_start_line_pos + this->Y_line_max_length) {
            start_text_y = this->Y_start_line_pos
                + this->Y_line_max_length - this->body_font_hgt - 3;
        }
        break;
    }

    case 6: {
        long right = this->X_start_line_pos + this->X_line_max_width;
        long text_length = static_cast<long>(strlen(event_ptr->text1));
        if (event_ptr->X_line_pos + text_length * this->body_font_wid > right) {
            event_ptr->text_length1 =
                (right - event_ptr->X_line_pos) / this->body_font_wid;
        } else {
            event_ptr->text_length1 = strlen(event_ptr->text1);
        }
        if (event_ptr->text_length1 > 2) {
            event_ptr->text_length1 = 2;
        }

        if (start_y + this->body_font_hgt + this->special_events_pic_hgt + 1 >
            this->Y_start_line_pos + this->Y_line_max_length) {
            start_y = this->Y_start_line_pos + this->Y_line_max_length
                - this->body_font_hgt - this->special_events_pic_hgt - 1;
        }
        start_text_x = start_x;
        start_text_y = start_y + this->special_events_pic_hgt + 1;
        break;
    }

    case 8: {
        long right = this->X_start_line_pos + this->X_line_max_width;
        long text_length = static_cast<long>(strlen(event_ptr->text1));
        if (event_ptr->X_line_pos + text_length * this->body_font_wid > right) {
            event_ptr->text_length1 =
                (right - event_ptr->X_line_pos) / this->body_font_wid;
        } else {
            event_ptr->text_length1 = strlen(event_ptr->text1);
        }
        if (event_ptr->text_length1 > 5) {
            event_ptr->text_length1 = 5;
        }

        if (start_y + this->body_font_hgt + this->special_events_pic_hgt + 1 >
            this->Y_start_line_pos + this->Y_line_max_length) {
            start_y = this->Y_start_line_pos + this->Y_line_max_length
                - this->body_font_hgt - this->special_events_pic_hgt - 1;
        }
        start_text_x = start_x;
        start_text_y = start_y + this->special_events_pic_hgt + 1;
        break;
    }
    }

    event_ptr->start_x = start_x;
    event_ptr->start_txt_x1 = start_text_x;
    event_ptr->start_y = start_y;
    event_ptr->start_txt_y1 = start_text_y;
    if (result != 0) {
        event_ptr->icon_flag = 1;
    }
    return result;
}

void Time_Line_Panel::draw(void) {
    TPanel::draw();
    this->need_redraw = 0;
    if (this->render_area != 0 && this->visible != 0 && this->active != 0) {
        this->draw_setup(0);
        this->draw_background();
        this->draw_border();
        this->draw_axis();
        this->draw_timeline();
        this->draw_special_events();
        this->draw_civilization_names();
        this->draw_finish();
    }
}


void Time_Line_Panel::draw_axis() {
    HGDIOBJ old_font;
    char temp_str[100];
    uchar white_color;

    white_color = static_cast<uchar>(GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0xFFFFFF));

    if (this->render_area->Lock(s_tpnl_tml_draw_axis, 1) != 0) {
        this->render_area->FillRect(this->xPosition() + 25, this->yPosition() + this->axis_font_hgt * 2 + 12
                                    + this->Y_axis_length, this->xPosition() + 24 + this->X_axis_length,
                                    this->yPosition() + this->axis_font_hgt * 2 + 13 + this->Y_axis_length, white_color);

        this->render_area->FillRect(this->xPosition() + 25, this->yPosition() + this->axis_font_hgt * 2 + 13,
                                    this->xPosition() + 24 + this->X_axis_length, this->yPosition() + this->axis_font_hgt * 2 + 14, white_color);

        this->render_area->FillRect(this->xPosition() + 25, this->yPosition() + this->axis_font_hgt * 2 + 13,
                                    this->xPosition() + 26, this->yPosition() + this->axis_font_hgt * 2 + 13 + this->Y_axis_length, white_color);

        this->render_area->FillRect(this->xPosition() + 23 + this->X_axis_length,
                                    this->yPosition() + this->axis_font_hgt * 2 + 13, this->xPosition() + 24 + this->X_axis_length,
                                    this->yPosition() + this->axis_font_hgt * 2 + 13 + this->Y_axis_length, white_color);
    }

    this->render_area->Unlock(s_tpnl_tml_draw_axis);
    if (this->render_area->GetDc(s_tpnl_tml_draw_axis) != 0) {
        SetBkMode(this->render_area->DrawDc, TRANSPARENT);
        old_font = SelectObject(this->render_area->DrawDc, this->axis_font);

        if (this->get_string(STRING_ID_WORLD_POPULATION, temp_str, 100) != 0) {
            int x = this->xPosition() + 8;
            int y = this->yPosition() + 5;
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            TextOutA(this->render_area->DrawDc, x, y, temp_str, strlen(temp_str));
        }

        if (this->get_string(STRING_ID_TIME_HOUR_MINUTE, temp_str, 100) != 0) {
            int x = this->X_start_line_pos;
            x -= (strlen(temp_str) * this->axis_font_wid) / 2;
            x += this->X_axis_length / 2;
            int y = this->height();
            y += this->yPosition();
            y -= this->axis_font_hgt + 5;
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            TextOutA(this->render_area->DrawDc, x, y, temp_str, strlen(temp_str));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_tml_draw_axis);
    }
}

void Time_Line_Panel::draw_special_events() {
    Special_Events* event;
    HGDIOBJ old_font;

    if (this->timeline_flag != 0) {
        GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0xFFFFFF);
        GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0);

        if (this->render_area->Lock("tpnl_tml::draw_special_events", 1) != 0) {
            for (event = this->time_slice_events; event != 0; event = event->next) {
                switch (event->event) {
                case 0:
                    this->draw_icon(event, -1, 0);
                    break;
                case 1:
                    this->draw_icon(event, -1, 1);
                    break;
                case 2:
                    this->draw_icon(event, -1, 2);
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
                case 3:
                    this->draw_icon(event, -1, 3);
                    break;
                }
            }
        }

        this->render_area->Unlock("tpnl_tml::draw_special_events");
        if (this->render_area->GetDc("tpnl_tml::draw_special_events") != 0) {
            SetBkMode(this->render_area->DrawDc, TRANSPARENT);
            old_font = SelectObject(this->render_area->DrawDc, this->body_font);

            for (event = this->time_slice_events; event != 0; event = event->next) {
                switch (event->event) {
                case 0:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc, event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 1:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc, event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 2:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc, event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 3: {
                    int x_offset = (event->time_slice != 0) ? -2 : 2;
                    SetTextColor(this->render_area->DrawDc, 0xFFFFFF);

                    TextOutA(this->render_area->DrawDc, x_offset - (strlen(event->text1) >> 1) * this->axis_font_wid
                             + event->X_line_pos, this->yPosition() + 8 + this->axis_font_hgt,
                             event->text1, strlen(event->text1));
                    size_t text_length2 = strlen(event->text2);
                    long text_y2 = this->yPosition();
                    text_y2 += this->height();
                    TextOutA(this->render_area->DrawDc, x_offset - (strlen(event->text2) >> 1) * this->axis_font_wid
                             + event->X_line_pos, text_y2 - this->axis_font_hgt * 2 - 7, event->text2, text_length2);
                    break;
                }
                case 6:
                    if (event->icon_flag != 0) {
                        SetTextColor(this->render_area->DrawDc, 0);
                        TextOutA(this->render_area->DrawDc, event->start_txt_x1, event->start_txt_y1,
                                 event->text1, event->text_length1);
                    }
                    break;
                case 8:
                    if (event->icon_flag != 0) {
                        SetTextColor(this->render_area->DrawDc, 0);
                        TextOutA(this->render_area->DrawDc, event->start_txt_x1, event->start_txt_y1,
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

void Time_Line_Panel::draw_background() {
    int pic_rows;
    int tile_rows;

    if (this->background_pic != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background", 1) == 0) {
            return;
        }

        if (this->background_pic_wid >= this->pnl_wid) {
            pic_rows = 1;
        } else {
            pic_rows = this->pnl_wid / this->background_pic_wid;
            if (static_cast<short>(pic_rows) * this->background_pic_wid < this->pnl_wid) {
                pic_rows++;
            }
        }

        if (this->background_pic_hgt >= this->pnl_hgt) {
            tile_rows = this->pnl_hgt / this->background_pic_hgt;
            if (static_cast<short>(tile_rows) * this->background_pic_hgt < this->pnl_hgt) {
                tile_rows++;
            }
        }

        if (static_cast<short>(tile_rows) > 0) {
            int row = 0;
            tile_rows = static_cast<short>(tile_rows);
            do {
                if (static_cast<short>(pic_rows) > 0) {
                    int col = 0;
                    int count = static_cast<short>(pic_rows);
                    do {
                        this->background_pic->shape_draw(this->render_area, col * this->background_pic_wid + this->pnl_x,
                                                         row * this->background_pic_hgt + this->pnl_y, 0, 0, 0);
                        col++;
                        count--;
                    } while (count != 0);
                }
                row++;
                tile_rows--;
            } while (tile_rows != 0);
        }

        this->render_area->Unlock("tpnl_tml::draw_background");
        return;
    }

    if (this->fill_back != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background2", 1) == 0) {
            return;
        }
        this->render_area->FillRect(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                    this->pnl_y + this->pnl_hgt - 1, this->back_color);
        this->render_area->Unlock("tpnl_tml::draw_background2");
        return;
    }

    if (this->parent_panel != 0) {
        if (this->bevel_type >= 2 && this->bevel_type <= 7) {
            this->parent_panel->draw_rect2(&this->clip_rect);
            return;
        }
        if (this->parent_panel->just_drawn == 0) {
            this->parent_panel->draw_rect(&this->clip_rect);
        }
    }
}

void Time_Line_Panel::draw_civilization_names() {
    char temp_str[100];
    char civ_str[100];
    char name_str[100];
    HGDIOBJ old_font;
    int X_line_pos;
    int Y_line_pos;
    long y_line_segment_length;
    float pop_total;

    if (this->timeline_flag != 0) {
        SetTextColor(this->render_area->DrawDc, 0);
        if (this->render_area->GetDc("tpnl_tml::draw_civilization_names") != 0) {
            SetBkMode(this->render_area->DrawDc, TRANSPARENT);
            old_font = SelectObject(this->render_area->DrawDc, this->body_font);
            pop_total = 0.0f;
            int player_index = 0;
            TRIBE_Player* player;
            if (rge_base_game->world->player_num - 1 > 0) {
                do {
                    player = static_cast<TRIBE_Player*>(rge_base_game->world->players[player_index + 1]);
                    pop_total += static_cast<float>(player->history->get_history_entry(0, 0) & 0xff);
                    player_index++;
                } while (player_index < rge_base_game->world->player_num - 1);
            }
            if (pop_total != 0.0f) {
                X_line_pos = this->X_start_line_pos + 3;
                Y_line_pos = this->Y_start_line_pos;
                if (rge_base_game->world->player_num - 1 > 0) {
                    y_line_segment_length = 0;
                    do {
                        player = static_cast<TRIBE_Player*>(rge_base_game->world->players[y_line_segment_length + 1]);
                        int seg = static_cast<int>((static_cast<float>(player->history->get_history_entry(0, 0) & 0xff) /
                            pop_total) * static_cast<float>(this->Y_line_max_length));
                        player = static_cast<TRIBE_Player*>(rge_base_game->world->players[y_line_segment_length + 1]);
                        rge_base_game->get_string2(RGE_STRING_TYPE_CIVILIZATION, player->master_player_id, 0, civ_str, 100);
                        player = static_cast<TRIBE_Player*>(rge_base_game->world->players[y_line_segment_length + 1]);
                        strcpy(name_str, player->name);
                        sprintf(temp_str, "%s - %s", name_str, civ_str);
                        TextOutA(this->render_area->DrawDc, X_line_pos, Y_line_pos + (seg / 2 - this->body_font_hgt / 2),
                                 temp_str, strlen(temp_str));
                        Y_line_pos += seg;
                        y_line_segment_length++;
                    } while (y_line_segment_length < rge_base_game->world->player_num - 1);
                }
                SelectObject(this->render_area->DrawDc, old_font);
                this->render_area->ReleaseDc("tpnl_tml::draw_civilization_names");
            }
        }
    }
}

void Time_Line_Panel::draw_timeline() {
    if (this->timeline_flag == 0) {
        return;
    }

    if (this->render_area->Lock("tpnl_tml::draw_timeline", 1) != 0) {
        long pop_label_counter = 0;
        long time_slice_thickness_error = 0;
        long time_slice_counter = 0;
        long pop_sample_counter = 0;
        long displayed_slice_counter = 0;
        long time_slice = 0;

        this->X_line_pos = this->X_start_line_pos;

        if (this->num_history_entries > 0) {
            long dropped_slice_counter = 1;

            do {
                if (displayed_slice_counter >= this->num_entries_page) {
                    break;
                }

                float pop_total = 0.0f;
                int special_event = 0;
                RGE_Game_World* world = rge_base_game->world;
                int player_index = 0;

                if (static_cast<int>(world->player_num) - 1 > 0) {
                    do {
                        TRIBE_Player* player = static_cast<TRIBE_Player*>(world->players[player_index + 1]);
                        float population = static_cast<float>(player->history->get_history_entry(0, time_slice));
                        unsigned char event;
                        player = static_cast<TRIBE_Player*>(rge_base_game->world->players[player_index + 1]);
                        if (player->history->get_history_event(time_slice, event) != 0) {
                            special_event = 1;
                        }
                        pop_total += population;
                        player_index++;
                        world = rge_base_game->world;
                    } while (player_index < static_cast<int>(world->player_num) - 1);
                }

                if (pop_total == 0.0f) {
                    return;
                }

                long base_drop_rate =
                    static_cast<long>(this->time_slice_drop_rate);
                long drop_limit = static_cast<long>(static_cast<float>(dropped_slice_counter) * this->time_slice_drop_rate);
                drop_limit += (1 - dropped_slice_counter) * base_drop_rate;
                drop_limit -= time_slice_counter;

                if (this->drop_flag != 0 && special_event == 0 && pop_sample_counter >= drop_limit &&
                    dropped_slice_counter - 1 < this->total_slices_to_drop) {
                    dropped_slice_counter++;
                    pop_sample_counter = 0;
                    if (drop_limit > base_drop_rate) {
                        time_slice_counter++;
                    }
                } else {
                    pop_sample_counter++;
                    displayed_slice_counter++;

                    float next_pop_total;
                    if (time_slice == this->num_entries_page - 1) {
                        next_pop_total = pop_total;
                    } else {
                        next_pop_total = 0.0f;
                        world = rge_base_game->world;
                        player_index = 0;
                        if (static_cast<int>(world->player_num) - 1 > 0) {
                            do {
                                TRIBE_Player* player =
                                    static_cast<TRIBE_Player*>(world->players[player_index + 1]);
                                next_pop_total += static_cast<float>(player->history->get_history_entry(0, time_slice + 1));
                                player_index++;
                                world = rge_base_game->world;
                            } while (player_index < static_cast<int>(world->player_num) - 1);
                        }
                        if (next_pop_total == 0.0f) {
                            return;
                        }
                    }

                    if (pop_label_counter == this->pop_reading_rate - 1 || time_slice == 0) {
                        this->add_pop_total_special_event(time_slice, static_cast<long>(pop_total), this->X_line_pos, 1);
                        pop_label_counter = 0;
                    } else {
                        pop_label_counter++;
                    }

                    long next_time_slice = time_slice + 1;
                    long time_slice_thickness = static_cast<long>(static_cast<float>(next_time_slice) *
                                                                  this->bar_thickness);
                    long base_thickness =
                        static_cast<long>(this->bar_thickness);
                    long regular_position = base_thickness * next_time_slice;

                    if (regular_position < time_slice_thickness - time_slice_thickness_error) {
                        time_slice_thickness =
                            time_slice_thickness -
                            time_slice_thickness_error - regular_position +
                            base_thickness;
                        time_slice_thickness_error++;
                    } else {
                        time_slice_thickness = base_thickness;
                    }

                    long intermediate_x_pos = 0;
                    long interpolation_counter = 0;

                    if (time_slice_thickness > 0) {
                        do {
                            this->Y_line_pos = this->Y_start_line_pos;
                            long y_line_total = 0;
                            volatile float segment_remainder = 0.0f;
                            world = rge_base_game->world;
                            player_index = 0;

                            if (static_cast<int>(world->player_num) - 1 > 0) {
                                do {
                                    TRIBE_Player* player =
                                        static_cast<TRIBE_Player*>(world->players[player_index + 1]);
                                    unsigned long color;
                                    switch (player->color_table->id) {
                                    case 0: color = 0xC40000; break;
                                    case 1: color = 0x0000C8; break;
                                    case 2: color = 0x00EAEA; break;
                                    case 3: color = 0x215A8C; break;
                                    case 4: color = 0x0080FF; break;
                                    case 5: color = 0x008000; break;
                                    case 6: color = 0x808080; break;
                                    case 7: color = 0x808040; break;
                                    default: color = 0xFFFFFF; break;
                                    }

                                    unsigned char player_color =
                                        static_cast<unsigned char>(GetNearestPaletteIndex(
                                                this->render_area->DrawSystem->Pal, color));

                                    player = static_cast<TRIBE_Player*>(rge_base_game->world->players[player_index + 1]);
                                    unsigned char population =
                                        player->history->get_history_entry(0, time_slice);
                                    float player_population =
                                        static_cast<float>(population);
                                    long segment = static_cast<long>(player_population / pop_total * static_cast<float>(
                                            this->Y_line_max_length));

                                    if (player_population >= 1.0f && segment < 1) {
                                        segment = 1;
                                    }

                                    if (this->bar_thickness != 1.0f) {
                                        float next_population;
                                        if (time_slice == this->num_entries_page - 1) {
                                            next_population =
                                                player_population;
                                        } else {
                                            player =
                                                static_cast<TRIBE_Player*>(rge_base_game->world ->players[
                                                                           player_index + 1]);
                                            next_population =
                                                static_cast<float>(player->history ->get_history_entry(0, next_time_slice));
                                        }

                                        long next_segment =
                                            static_cast<long>(next_population / next_pop_total * static_cast<float>(
                                                    this->Y_line_max_length));
                                        long segment_change =
                                            next_segment - segment;
                                        float interpolated_segment =
                                            static_cast<float>(segment) +
                                            static_cast<float>(segment_change) *
                                                (static_cast<float>(interpolation_counter) /
                                                 this->bar_thickness);
                                        segment = static_cast<long>(interpolated_segment);

                                        if (player_population >= 1.0f && segment < 1) {
                                            segment = 1;
                                        }

                                        segment_remainder =
                                            (segment_remainder +
                                             interpolated_segment) -
                                            static_cast<float>(segment);
                                        if (segment_remainder > 1.0) {
                                            segment_remainder -= 1.0f;
                                            segment++;
                                        }
                                    }

                                    if (player_index == static_cast<int>(rge_base_game->world->player_num) - 2) {
                                        if (segment + y_line_total > this->Y_line_max_length) {
                                            segment = this->Y_line_max_length -
                                                      y_line_total;
                                        }
                                        if (segment + y_line_total < this->Y_line_max_length) {
                                            segment = this->Y_line_max_length -
                                                      y_line_total;
                                        }
                                    }

                                    this->render_area->DrawVertLine(this->X_line_pos, this->Y_line_pos,
                                                                    segment, player_color);

                                    if (intermediate_x_pos == 0) {
                                        player = static_cast<TRIBE_Player*>(rge_base_game->world->players[
                                                                            player_index + 1]);
                                        this->record_special_event(static_cast<unsigned char>(player_index + 1),
                                                                   player->history, player_color, time_slice, this->X_line_pos,
                                                                   this->Y_line_pos, segment);
                                    }

                                    this->Y_line_pos += segment;
                                    y_line_total += segment;
                                    player_index++;
                                    world = rge_base_game->world;
                                } while (player_index < static_cast<int>(world->player_num) - 1);
                            }

                            intermediate_x_pos++;
                            interpolation_counter++;
                            this->X_line_pos++;
                        } while (intermediate_x_pos < time_slice_thickness);
                    }
                }

                time_slice++;
            } while (time_slice < this->num_history_entries);
        }
    }

    this->render_area->Unlock("tpnl_tml::draw_timeline");
}

void Time_Line_Panel::draw_icon(Special_Events* event_ptr, short icon_number, uchar history_type) {
    char temp_str[54];
    long total;
    long hi_top;
    long q_top;
    unsigned int (__stdcall* getNearest)(void*, unsigned long) =
        GetNearestPaletteIndex;
    getNearest(this->render_area->DrawSystem->Pal, 0xffffff);
    temp_str[0] = static_cast<char>(getNearest(this->render_area->DrawSystem->Pal, 0));

    switch (event_ptr->event) {
    case 0:
        if (this->get_string(STRING_ID_AGE_TOOL, temp_str + 4, 50)) sprintf(event_ptr->text1, "%s", temp_str + 4); else event_ptr->text1[0] = 0;
        break;
    case 1:
        if (this->get_string(STRING_ID_AGE_BRONZE, temp_str + 4, 50)) sprintf(event_ptr->text1, "%s", temp_str + 4); else event_ptr->text1[0] = 0;
        break;
    case 2:
        if (this->get_string(STRING_ID_AGE_IRON, temp_str + 4, 50)) sprintf(event_ptr->text1, "%s", temp_str + 4); else event_ptr->text1[0] = 0;
        break;
    case 8:
        sprintf(temp_str + 4, "%ld/%1d", event_ptr->integer_value_1, event_ptr->integer_value_2);
        sprintf(event_ptr->text1, "%s", temp_str + 4);
    case 3: {
        sprintf(event_ptr->text1, "%ld", event_ptr->pop_total);
        hi_top = 0;
        event_ptr->text_length1 = strlen(event_ptr->text1);
        q_top = 0;
        total = event_ptr->time_slice * 15;
        if (total > 59) {
            q_top = total / 60;
            if (q_top > 59) {
                hi_top = q_top / 60;
                q_top = q_top - hi_top * 60;
            }
        }
        sprintf(temp_str + 4, "%1ld:%02ld", hi_top, q_top);
        sprintf(event_ptr->text2, "%s", temp_str + 4);
        event_ptr->text_length2 = strlen(event_ptr->text2);
        break;
    }
    default:
        break;
    }

    int ok = this->calculate_icon_location(event_ptr, icon_number, history_type);
    switch (event_ptr->event) {
    case 0:
            this->render_area->DrawVertLine(event_ptr->X_line_pos, event_ptr->Y_line_pos,
                                            event_ptr->intermediate_y_line_segment, static_cast<uchar>(temp_str[0]));
        return;
    case 1:
        this->render_area->DrawVertLine(event_ptr->X_line_pos, event_ptr->Y_line_pos,
                                        event_ptr->intermediate_y_line_segment, static_cast<uchar>(temp_str[0]));
        return;
    case 2:
        this->render_area->DrawVertLine(event_ptr->X_line_pos, event_ptr->Y_line_pos,
                                        event_ptr->intermediate_y_line_segment, static_cast<uchar>(temp_str[0]));
        return;
    default:
        if (ok) {
            this->special_events_pic->shape_draw(this->render_area, event_ptr->start_x, event_ptr->start_y,
                                                 static_cast<int>(icon_number), 0, 0);
        }
        return;
    }
}

void Time_Line_Panel::draw_legend() {
    if (this->special_events_pic != 0) {
        if (this->special_events_pic->shape_count() != 0) {
            width();
        }
    }
}
