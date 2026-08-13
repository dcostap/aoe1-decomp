// VA: 005204A0 Time_Line_Panel::draw_timeline (1565 bytes)
// Source: tpnl_tml.cpp lines 1191-1427
// Attempt log:
// - Initial bounded reconstruction from packet/Ghidra, preserving the original nested player scans,
//   switch color dispatch, x87 conversion expressions, and early-return behavior.
// - Bounded pass: typed player/history surface recovers observed +0x83C history pointer and 19-call set;
//   best retained baseline is 1536B vs original 1565B, frame 0x5C vs 0x54, 53.1% shape similarity.
// - Tried volatile self, history return-width/temporary placement, and float conversion spellings;
//   extra-ftol variants changed call count to 23 and were reverted. No shared-header changes or asm.
// - Left in scratch: broad early local/frame/register drift with several exact small block islands; no match.
// - Shard C clean-source reset: replaced the byte-cursor player scans and volatile self with
//   typed world->players[i + 1] traversal, RGE_Civilization ownership, and named event storage.
// - Donor-backed structural lead: adopted the exact draw_axis TDrawSystem::Pal surface for palette lookup.
// - Current clean source keeps the 19-call set and natural player ownership; broad CFG/frame drift
//   remains, so stop before register or scheduling variants. Next lead: reconstruct local lifetime
//   bands from the original 0x54 frame and line records.

extern "C" unsigned char (__stdcall* const GetNearestPaletteIndex)(void*, unsigned long);

struct RGE_Game_World;
struct RGE_Base_Game {
    virtual ~RGE_Base_Game();
    char gap_004[0x3f0];
    RGE_Game_World* world;
};
extern RGE_Base_Game* rge_base_game;

struct RGE_Game_World {
    virtual unsigned char data_load_world(void* file);
    char gap_000[0x3c];
    short player_num;
    short gap_03e;
    struct TRIBE_Player** players;
};

struct TRIBE_History_Info {
    unsigned char get_history_entry(unsigned char mode, long index);
    unsigned char get_history_event(long index, unsigned char& event);
};

struct RGE_Civilization {
    char gap_000[0x26];
    short color;
};

struct TRIBE_Player {
    char gap_000[0x108];
    RGE_Civilization* civilization;
    char gap_10c[0x730];
    TRIBE_History_Info* history_info;
};

struct TDrawSystem {
    char gap_000[8];
    void* Pal;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_004[0x34];
    unsigned char Lock(char* tag, int flag);
    void Unlock(char* tag);
    void DrawVertLine(long x, long y, long h, unsigned char color);
};

class Time_Line_Panel {
public:
    char gap_000[0x20];
    TDrawArea* draw_area;
    char gap_024[0x4b8];
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

void Time_Line_Panel::draw_timeline()
{
    float temp_pop_num;
    long time_slice;
    int next_pop_total;
    float float_remainder;
    long error_correction_drop_time_slice_rate;
    long pop_sample_cntr;
    long time_slice_cntr;
    long local_28;
    long error_correction_time_slice_thickness;
    long local_10;
    long y_line_segment_length;
    unsigned char temp_color;
    long intermediate_x_pos;
    long cntr2;
    long cntr_droped_slice_rate;
    long Y_line_total;
    unsigned char event;

    if (this->timeline_flag == 0) return;

    if (this->draw_area->Lock((char*)0x58B820, 1) == 0) return;

    this->X_line_pos = this->X_start_line_pos;
    next_pop_total = 0;
    pop_sample_cntr = 0;
    time_slice_cntr = 0;
    local_28 = 0;
    local_10 = 0;
    if (this->num_history_entries > 0) {
        error_correction_drop_time_slice_rate = 1;
        do {
            if (local_28 >= this->num_entries_page) break;

            temp_pop_num = 0.0f;
            error_correction_time_slice_thickness = 0;
            RGE_Game_World* world = rge_base_game->world;
            if (world->player_num > 1) {
                for (int i = 0; i < (int)world->player_num - 1; ++i) {
                    TRIBE_Player* player = world->players[i + 1];
                    time_slice = (long)player->history_info->get_history_entry(0, next_pop_total);
                    temp_color = (unsigned char)time_slice;
                    if (player->history_info->get_history_event(next_pop_total,
                            event) != 0) {
                        error_correction_time_slice_thickness = 1;
                    }
                    temp_pop_num = (float)time_slice + temp_pop_num;
                }
            }

            if (temp_pop_num == 0.0f) return;

            long drop_rate = (long)this->time_slice_drop_rate;
            long scaled_drop = (long)((float)error_correction_drop_time_slice_rate * this->time_slice_drop_rate);
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
                    world = rge_base_game->world;
                    if (world->player_num > 1) {
                        long next_index = next_pop_total + 1;
                        for (int i = 0; i < (int)world->player_num - 1; ++i) {
                            TRIBE_Player* player = world->players[i + 1];
                            time_slice = (long)player->history_info->get_history_entry(0, next_index);
                            temp_color = (unsigned char)time_slice;
                            float_remainder = (float)time_slice + float_remainder;
                        }
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
                long y_line_length = (long)((float)y_line_segment_length * this->bar_thickness);
                long bar_length = (long)this->bar_thickness;
                if (bar_length * y_line_segment_length < y_line_length - local_10) {
                    bar_length = (y_line_length - local_10) - bar_length * y_line_segment_length + bar_length;
                    local_10++;
                }
                intermediate_x_pos = 0;
                if (bar_length > 0) {
                    do {
                        this->Y_line_pos = this->Y_start_line_pos;
                        cntr2 = 0;
                        cntr_droped_slice_rate = 0;
                        world = rge_base_game->world;
                        if (world->player_num > 1) {
                            for (int i = 0; i < (int)world->player_num - 1; ++i) {
                                TRIBE_Player* player = world->players[i + 1];
                                unsigned long color;
                                switch (player->civilization->color) {
                                case 0: color = 0x00C40000; break;
                                case 1: color = 0x000000C8; break;
                                case 2: color = 0x0000EAEA; break;
                                case 3: color = 0x00215A8C; break;
                                case 4: color = 0x000080FF; break;
                                case 5: color = 0x00008000; break;
                                case 6: color = 0x00808080; break;
                                case 7: color = 0x00808040; break;
                                default: color = 0x00FFFFFF; break;
                                }
                                color = (unsigned long)GetNearestPaletteIndex(
                                    this->draw_area->DrawSystem->Pal, color);
                                time_slice = (long)player->history_info->get_history_entry(0, next_pop_total);
                                Y_line_total = this->Y_line_max_length;
                                temp_pop_num = (float)time_slice / temp_pop_num * (float)Y_line_total;
                                long segment = (long)temp_pop_num;
                                if ((time_slice >= 1) && (segment < 1)) segment = 1;

                                if (this->bar_thickness != 1.0f) {
                                    if (next_pop_total != this->num_entries_page - 1) {
                                        time_slice = (long)player->history_info->get_history_entry(0, y_line_segment_length);
                                    }
                                    Y_line_total = this->Y_line_max_length;
                                    long next_segment = (long)((float)time_slice / float_remainder * (float)Y_line_total);
                                    long difference = next_segment - segment;
                                    temp_pop_num = (float)difference / this->bar_thickness + (float)segment;
                                    segment = (long)temp_pop_num;
                                    if ((time_slice >= 1) && (segment < 1)) segment = 1;
                                }

                                if (i == (int)world->player_num - 2) {
                                    if (Y_line_total < segment + cntr2) segment = Y_line_total - cntr2;
                                    if (segment + cntr2 < Y_line_total) segment = Y_line_total - cntr2;
                                }

                                this->draw_area->DrawVertLine(this->X_line_pos, this->Y_line_pos, segment, (unsigned char)color);
                                if (intermediate_x_pos == 0) {
                                    this->record_special_event((unsigned char)(i + 1), player->history_info,
                                        (unsigned char)color, next_pop_total, this->X_line_pos,
                                        this->Y_line_pos, segment);
                                }
                                this->Y_line_pos += segment;
                                cntr2 += segment;
                            }
                        }
                        intermediate_x_pos++;
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
