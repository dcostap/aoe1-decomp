// VA: 0051F310, Time_Line_Panel::init_timeline, 455 bytes
// Source: tpnl_tml.cpp lines 476-538
// Attempt log:
// - v1: natural reconstruction from packet/decompiler with local layout fields and direct TPanel methods.
// - v2: modeled rge_base_game->world (+0x3f4), world->player_num (+0x3c), players (+0x40), player history_info (+0x83c).
// - v3: used explicit int stack temps for FILD conversions and exact field offsets from type dump/asm.
// - v4: split usable_X assignment/subtraction to probe width-result register allocation.
// - v5: changed usable_X to long to probe local register choice.
// - v6: hoisted entries local before width call; worsened first mismatch to +0x62, rolled back.
// - v7: delayed entries local until after FILD setup, using member load for temp2 to probe edx/ecx swap.
// - v8: changed TPanel position/size return declarations from long to int; no change.
// - v9: spell usable_X as `-0x31 + width()` single expression; no change.
// - v10: reversed line-max assignments to probe late load/store order; edit diff improved to 8.79%.
// - v11: routed width result through temp1; worsened first mismatch/size family, rolled back.
// - v12: inverted float compare spelling to `1.0f > bar_thickness`; worsened edit diff, rolled back.
// - v13: paused in scratch with a 455-byte near-match; the remaining ECX/EDX
//   lifetime swap was traced to persistent entries/diff/temp copies.
// - v14: removed those compiler-steering copies and used direct member arithmetic;
//   the emitted function became an exact 455-byte match.
// - v15: removed the unused player_off increment scaffold; typed players[i+1]
//   traversal remained exact and is the cleaner source model.
// - v16: removed the unused explicit _ftol declaration; natural casts remained exact.
// Exact: 455/455 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.

class TRIBE_History_Info {
public:
    long get_history_entry_num();
};

class TRIBE_Player {
public:
    char gap_000[0x83c];
    TRIBE_History_Info* history_info;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x38];
    short player_num;
    short pad_3e;
    TRIBE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_004[0x3f0];
    RGE_Game_World* world;
};

extern RGE_Base_Game* rge_base_game;

class Time_Line_Panel {
public:
    char gap_000[0x480];
    int axis_font_hgt;          // +480
    char gap_484[0x4dc - 0x484];
    int X_start_line_pos;       // +4dc
    int Y_start_line_pos;       // +4e0
    int X_line_pos;             // +4e4
    int Y_line_pos;             // +4e8
    int X_line_max_width;       // +4ec
    int Y_line_max_length;      // +4f0
    int X_axis_length;          // +4f4
    int Y_axis_length;          // +4f8
    float bar_thickness;        // +4fc
    int pop_reading_rate;       // +500
    float time_slice_drop_rate; // +504
    int total_slices_to_drop;   // +508
    unsigned char drop_flag;    // +50c
    char gap_50d[3];
    int num_entries_page;       // +510
    int num_history_entries;    // +514
    char gap_518[4];
    unsigned char timeline_flag;// +51c

    int xPosition();
    int yPosition();
    int width();
    int height();
    void init_timeline();
};

void Time_Line_Panel::init_timeline()
{
    int i = 0;
    this->num_history_entries = 0;
    RGE_Game_World* world = rge_base_game->world;
    int count = (int)world->player_num - 1;
    if (count > 0) {
        do {
            int n = world->players[i + 1]->history_info->get_history_entry_num();
            if (this->num_history_entries < n) {
                this->num_history_entries = n;
            }
            i++;
            world = rge_base_game->world;
        } while (i < (int)world->player_num - 1);
    }

    int usable_X = -0x31 + this->width();
    if (this->num_history_entries == 0) {
        this->num_history_entries = 1;
        this->timeline_flag = 0;
    }

    this->time_slice_drop_rate = 0.0f;
    this->bar_thickness = (float)usable_X / (float)this->num_history_entries;

    if (this->bar_thickness < 1.0f) {
        this->bar_thickness = 1.0f;
        this->num_entries_page = usable_X;
        this->drop_flag = 1;
        this->total_slices_to_drop = this->num_history_entries - usable_X;
        this->time_slice_drop_rate =
            (float)usable_X / (float)this->total_slices_to_drop;
    } else {
        this->num_entries_page = this->num_history_entries;
    }

    this->X_axis_length = (long)((float)this->num_entries_page * this->bar_thickness) + 4;
    this->Y_axis_length = this->height() - this->axis_font_hgt * 4 - 0x1a;
    this->X_start_line_pos = this->xPosition() + 0x1b;
    int y = this->yPosition() + this->axis_font_hgt * 2 + 0x0f;
    this->X_line_pos = this->X_start_line_pos;
    this->Y_start_line_pos = y;
    this->Y_line_pos = y;
    this->Y_line_max_length = this->Y_axis_length - 3;
    this->X_line_max_width = this->X_axis_length - 2;

    if (this->num_entries_page < 12) {
        this->pop_reading_rate = 1;
    } else {
        this->pop_reading_rate =
            (long)((float)(this->num_entries_page - 1) * 0.1f);
    }
}
