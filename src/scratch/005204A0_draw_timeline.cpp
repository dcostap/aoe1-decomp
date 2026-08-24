// VA: 005204A0 Time_Line_Panel::draw_timeline (1565 bytes)
// Source: tpnl_tml.cpp lines 1191-1427
// Attempt log:
// - Initial bounded reconstruction from packet/Ghidra, preserving the original nested player scans,
//   switch color dispatch, x87 conversion expressions, and early-return behavior.
// - Probe: removed the decompiler-only special-event counter; original increment has no later read.
// - Probe: restored the packet's overlapping pop_total/event local and its zero initialization.
// - Structural probe: restored donor-proven byte-cursor scans and the original fractional segment
//   correction/local counter topology; replaced diagnostic _ftol stubs with typed conversions.
// - Probe: promoted the repeated segment temporary to the named local lifetime used by the draw loop.
// - Probe: typed conversion and outer-temporary variants preserved the 19-call set but did not
//   reduce the 0x64 frame; the prior clean result was 1565 bytes and 56.5% shape.
// - Probe: the binary's repeated player guard is `player_num - 1 > 0`; the simpler guard improved
//   CFG parity from 37/41 to 37/38 conditions.
// - Probe: direct repeated world/player expressions remove cached object homes and improve shape
//   to 65.5%; the candidate is 1616 bytes with a 0x5C frame and 19 aligned calls.
// - Probe: reusing local_38 as the inner player cursor is codegen-duplicate evidence.
// - Probe: modeled history samples as a float time_slice and kept the returned sample in a signed dword temp;
//   this reached the original 0x50/0x54 frame basin and reduced strict drift to 1337 bytes.
// - Probe: separated the 32-bit switch palette input from the byte palette-index result; this preserved the
//   original EAX switch constants and reduced strict drift to 1300 bytes with 73.7% shape similarity.
// - Probe: ordered the Y-line total load before the explicit sample conversion; the current clean source is
//   1600 bytes with a 0x50 frame, 19 aligned calls, and 1299-byte strict drift.
// - Current claim probes 1-20: tested loop forms, local types and order, interpolation groupings,
//   canonical class context, and Windows header context. Header context and alternate loop forms did not
//   improve strict output. Duplicate codegen ruled out several declaration and cast variants.
// - Binary-supported recovery: the inner bar loop has independent intermediate_x_pos and special_event_flag
//   counters. The stack uses [esp+4Ch] for interpolation and [esp+48h] for first-column event gating.
//   Restoring both counters reaches the original 0x54 frame and 19-call set, but remains nonexact at 1620
//   bytes, 70.04% shape, and 1310 strict-drift bytes. The pinned final source keeps this natural model.
// - Unresolved: initial local-home permutation, early page/history CFG layout, and x87 sample conversion
//   scheduling still differ. The separate bar_length local is retained because its source form is closer
//   than the binary-overlapped reuse variant; no unsupported register steering or inline assembly was used.
// - Follow-up claim probes 21-33 tested outer-loop forms, local scope and width, operand order, accumulator
//   forms, x87 interpolation ownership, and address-taken sample storage. No probe improved the clean bytes.
// - Final clean result: 1620 emitted bytes versus 1565, 0x54 frame, 19 ordered calls, 70.04% shape,
//   and 1310 strict-drift bytes. Keep the simplest two-counter source until new binary evidence appears.

#ifndef TPNL_TML_WRAPPER
extern "C" unsigned char (__stdcall* const GetNearestPaletteIndex)(void*, unsigned long);
#endif

#ifndef TPNL_TML_WRAPPER
struct RGE_Game_World;
struct RGE_Base_Game {
    char gap_000[0x3f4];
    RGE_Game_World* world;
};
extern RGE_Base_Game* rge_base_game;

struct RGE_Game_World {
    char gap_000[0x3c];
    short player_num;
    short gap_03e;
    struct TRIBE_Player** players;
};

struct TRIBE_History_Info {
    unsigned char get_history_entry(unsigned char mode, long index);
    unsigned char get_history_event(long index, unsigned char& event);
};

struct TRIBE_Player_Details {
    char gap_000[0x26];
    short civilization;
};

struct TRIBE_Player {
    char gap_000[0x108];
    TRIBE_Player_Details* details;
    char gap_10c[0x730];
    TRIBE_History_Info* history_info;
};

class TDrawArea {
public:
    unsigned char Lock(char* tag, int flag);
    void Unlock(char* tag);
    void DrawVertLine(long x, long y, long h, unsigned char color);
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x1c];
    TDrawArea* draw_area;
    char gap_024[0xd0];
};

class TEasy_Panel : public TPanel {
public:
    char gap_0f4[0x384];
};

class Time_Line_Panel : public TEasy_Panel {
public:
    void* axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    void* body_font;
    long body_font_wid;
    long body_font_hgt;
    int text_style;
    int text_color1;
    int text_color2;
    int highlight_text_color1;
    int highlight_text_color2;
    int text_wid;
    int text_hgt;
    void* background_pic;
    short background_pic_wid;
    short background_pic_hgt;
    int fill_back;
    unsigned char back_color;
    char gap_4b9[3];
    int outline;
    unsigned char outline_color;
    char gap_4c1[3];
    int sorted;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_4d2[2];
    void* special_events_pic;
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
    unsigned char drop_flag;
    char gap_50d[3];
    long num_entries_page;
    long num_history_entries;
    char gap_518[4];
    unsigned char timeline_flag;
    char gap_51d[3];

    void add_pop_total_special_event(long time_slice, long pop_total, long X_line_pos, int icon_flag);
    void record_special_event(unsigned char player_id, TRIBE_History_Info* history,
                              unsigned char color, long time_slice, long X_line_pos,
                              long Y_line_pos, long segment_length);
    void draw_timeline();
};
#endif

void Time_Line_Panel::draw_timeline()
{
    unsigned char event;
    float pop_total;
    float temp_pop_num;
    float time_slice;
    long next_pop_total;
    float float_remainder;
    float cntr_droped_slice_rate;
    long pop_sample_cntr;
    int local_38;
    int local_34;
    long error_correction_drop_time_slice_rate;
    long time_slice_cntr;
    int local_28;
    long Y_line_total;
    long cntr2;
    long intermediate_x_pos;
    long error_correction_time_slice_thickness;
    int local_10;
    long y_line_segment_length;
    long temp_color;
    long segment;
    int special_event_flag;

    if (this->timeline_flag == 0) return;

    if (this->draw_area->Lock((char*)0x58B820, 1) == 0) return;

    this->X_line_pos = this->X_start_line_pos;
    local_38 = 0;
    local_10 = 0;
    time_slice_cntr = 0;
    pop_sample_cntr = 0;
    local_28 = 0;
    next_pop_total = 0;

    if (this->num_history_entries > 0) {
        error_correction_drop_time_slice_rate = 1;
        do {
            if (local_28 >= this->num_entries_page) break;

            temp_pop_num = 0.0f;
            error_correction_time_slice_thickness = 0;
            int i = 0;
            if ((int)rge_base_game->world->player_num - 1 > 0) {
                int player_offset = 4;
                do {
                    temp_color = (*(TRIBE_Player**)((char*)rge_base_game->world->players + player_offset))
                        ->history_info->get_history_entry(0, (long)next_pop_total);
                    time_slice = (float)temp_color;
                    if ((*(TRIBE_Player**)((char*)rge_base_game->world->players + player_offset))
                            ->history_info->get_history_event((long)next_pop_total, event) != 0) {
                        error_correction_time_slice_thickness = 1;
                    }
                    temp_pop_num = time_slice + temp_pop_num;
                    i++;
                    player_offset += 4;
                } while (i < (int)rge_base_game->world->player_num - 1);
            }

            if (temp_pop_num == 0.0f) return;

            long drop_rate = (long)this->time_slice_drop_rate;
            long scaled_drop = (long)((float)error_correction_drop_time_slice_rate *
                                      this->time_slice_drop_rate);
            long error_correction = scaled_drop + (1 - error_correction_drop_time_slice_rate) * drop_rate - time_slice_cntr;
            if ((this->drop_flag == 0) || (error_correction_time_slice_thickness != 0) ||
                (pop_sample_cntr < error_correction) ||
                (error_correction_drop_time_slice_rate - 1 >= this->total_slices_to_drop)) {
                pop_sample_cntr++;
                local_28++;

                if (next_pop_total == this->num_entries_page - 1) {
                    float_remainder = temp_pop_num;
                } else {
                    float_remainder = 0.0f;
                    i = 0;
                    if ((int)rge_base_game->world->player_num - 1 > 0) {
                        int player_offset = 4;
                        do {
                            temp_color = (*(TRIBE_Player**)((char*)rge_base_game->world->players + player_offset))
                                ->history_info->get_history_entry(0, next_pop_total + 1);
                            float_remainder = (float)temp_color + float_remainder;
                            i++;
                            player_offset += 4;
                        } while (i < (int)rge_base_game->world->player_num - 1);
                    }
                    if (float_remainder == 0.0f) return;
                }

                if ((local_28 == this->pop_reading_rate - 1) || (next_pop_total == 0)) {
                    this->add_pop_total_special_event(next_pop_total,
                        (long)temp_pop_num, this->X_line_pos, 1);
                    local_28 = 0;
                } else {
                    local_28++;
                }

                y_line_segment_length = (long)next_pop_total + 1;
                long y_line_length =
                    (long)((float)y_line_segment_length * this->bar_thickness);
                long bar_length = (long)this->bar_thickness;
                if (bar_length * y_line_segment_length < y_line_length - local_10) {
                    bar_length = (y_line_length - local_10) - bar_length * y_line_segment_length + bar_length;
                    local_10++;
                }
                intermediate_x_pos = 0;
                special_event_flag = 0;
                if (bar_length > 0) {
                    do {
                        this->Y_line_pos = this->Y_start_line_pos;
                        cntr2 = 0;
                        cntr_droped_slice_rate = 0;
                        local_34 = 0;
                        if ((int)rge_base_game->world->player_num - 1 > 0) {
                            local_38 = 4;
                            do {
                                unsigned long palette_color;
                                unsigned char color;
                                switch ((*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))
                                            ->details->civilization) {
                                case 0: palette_color = 0x00C40000; break;
                                case 1: palette_color = 0x000000C8; break;
                                case 2: palette_color = 0x0000EAEA; break;
                                case 3: palette_color = 0x00215A8C; break;
                                case 4: palette_color = 0x000080FF; break;
                                case 5: palette_color = 0x00008000; break;
                                case 6: palette_color = 0x00808080; break;
                                case 7: palette_color = 0x00808040; break;
                                default: palette_color = 0x00FFFFFF; break;
                                }
                                color = GetNearestPaletteIndex((*(void***)this->draw_area)[2], palette_color);
                                temp_color = (long)(*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))
                                    ->history_info->get_history_entry(0, next_pop_total);
                                Y_line_total = this->Y_line_max_length;
                                time_slice = (float)temp_color;
                                temp_pop_num = (time_slice / temp_pop_num) *
                                                (float)Y_line_total;
                                segment = (long)temp_pop_num;
                                if ((time_slice >= 1.0f) && (segment < 1)) segment = 1;

                                if (this->bar_thickness != 1.0f) {
                                    if (next_pop_total != this->num_entries_page - 1) {
                                        time_slice = (float)(*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))
                                            ->history_info->get_history_entry(0, y_line_segment_length);
                                    }
                                    Y_line_total = this->Y_line_max_length;
                                    long next_segment = (long)(time_slice /
                                                               float_remainder *
                                                               (float)Y_line_total);
                                    long difference = next_segment - segment;
                                    temp_pop_num = (float)segment +
                                                    (float)difference *
                                                    ((float)intermediate_x_pos / this->bar_thickness);
                                    segment = (long)temp_pop_num;
                                    if ((time_slice >= 1.0f) && (segment < 1)) segment = 1;
                                    cntr_droped_slice_rate += temp_pop_num - (float)segment;
                                    if (cntr_droped_slice_rate > 1.0f) {
                                        cntr_droped_slice_rate -= 1.0f;
                                        segment++;
                                    }
                                }

                                if (local_34 == (int)rge_base_game->world->player_num - 2) {
                                    if (Y_line_total < segment + cntr2) segment = Y_line_total - cntr2;
                                    if (segment + cntr2 < Y_line_total) segment = Y_line_total - cntr2;
                                }

                                this->draw_area->DrawVertLine(this->X_line_pos, this->Y_line_pos, segment, (unsigned char)color);
                                if (special_event_flag == 0) {
                                this->record_special_event((unsigned char)(local_34 + 1),
                                    (*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))->history_info,
                                        (unsigned char)color, next_pop_total, this->X_line_pos,
                                        this->Y_line_pos, segment);
                                }
                                this->Y_line_pos += segment;
                                cntr2 += segment;
                                local_34++;
                                local_38 += 4;
                            } while (local_34 < (int)rge_base_game->world->player_num - 1);
                        }
                        intermediate_x_pos++;
                        special_event_flag++;
                        this->X_line_pos++;
                    } while (intermediate_x_pos < bar_length);
                }
            } else {
                error_correction_drop_time_slice_rate++;
                pop_sample_cntr = 0;
                if (error_correction_drop_time_slice_rate > drop_rate) time_slice_cntr++;
            }
            next_pop_total++;
        } while (next_pop_total < this->num_history_entries);
    }

    this->draw_area->Unlock((char*)0x58B820);
}
