// VA: 004C0B70 RGE_Sprite::get_frame_min_max
// PDB source: sprite.cpp, lines 763-803
// Attempt log:
// - Natural baseline matched size/frame/calls but used the opposite compare
//   operand order and kept the facet result byte-sized (167 differing bytes).
// - Reversed the equivalent frame bound and kept the facet result in an int;
//   this recovered the original compare, mask, call setup, and all four
//   return/update block shapes (110 differing bytes, exact size/frame/calls).
// - Reused formal frame/facet values, full donor-proven RGE_Sprite layout,
//   declaration-order, explicit adjusted-bound, and compound-assignment
//   variants; all emitted the same 110-byte basin or were worse. A six-case
//   variant lab likewise found one emitted group and no exact result.
// Final clean source: retain the natural formal-parameter/temporary form;
// remaining drift is VC5 register/liveness coloring after the second call.

class RGE_Color_Table;
class TShape;
class RGE_Picture_List;
class RGE_Sound;
class RGE_Sound_List;

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    char gap_5D[1];
    short frame_num;
    short facet_num;
    char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flag;
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    unsigned char get_facetindex(long frame, long facet, long& frame_out);
    int get_size(long& min_x, long& max_y, long& max_x, long& max_y2,
                 long facet);
    int get_frame_min_max(short& min_x, short& min_y, short& max_x,
                          short& max_y, long frame, long facet,
                          short offset_x, short offset_y);
};

int RGE_Sprite::get_frame_min_max(short& min_x, short& min_y, short& max_x,
                                  short& max_y, long frame, long facet,
                                  short offset_x, short offset_y) {
    long frame_index = facet;
    long calc_min_y;
    long calc_max_y;
    long local_4;
    int facet_index;
    int x1;
    int x2;
    int y1;
    int y2;

    if (facet >= this->frame_num) {
        frame_index = 0;
    }

    facet_index = this->get_facetindex(frame, frame_index, calc_min_y);
    if (this->get_size(frame, calc_max_y, facet, local_4, calc_min_y) == 0) {
        return 0;
    }

    if (facet_index != 0) {
        x1 = -frame;
        frame = -facet;
        facet = x1;
    }

    x1 = frame + offset_x;
    x2 = facet + offset_x;
    y1 = calc_max_y + offset_y;
    y2 = local_4 + offset_y;

    if (x1 < min_x) {
        min_x = (short)x1;
    }
    if (y1 < min_y) {
        min_y = (short)y1;
    }
    if (max_x < x2) {
        max_x = (short)x2;
    }
    if (max_y < y2) {
        max_y = (short)y2;
    }
    return 1;
}
