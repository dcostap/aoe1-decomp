// VA: 004C0D80 RGE_Sprite::shape_hit_test (516B)
// PDB source: sprite.cpp, lines 855-915
// EH frame (/GX)
// Attempt log:
// - Replaced the field-only scaffold with the natural lazy TShape load,
//   facet-index lookup, transparent-picking switch, and typed shape bounds
//   checks recovered from the executable.  The first checker run is the
//   clean-source baseline.
// - Reversed the frame-bound compare and added explicit switch case 0;
//   the latter recovered the original sub/dec dispatch family.
// - Routed lazy/bounds failures through the proven shared fail epilogue;
//   this reached exact size/frame/instruction/call parity.
// - Recovered the mirrored-arm-first source order and canonical min/max
//   ownership.  Best clean result: 516-byte rebuild, 72 strict differing
//   bytes, 96.32% shape similarity; residual drift is the shape_minmax local
//   address/evaluation and one late mirrored-bound jump.
// - Fresh bounded pass kept the canonical typed source and changed the
//   shared y bounds to explicit fail checks.  This improved the clean output
//   to 70 differing bytes and 97.55% shape similarity; direct x and width
//   variants were worse.  Three focused variant families found no exact
//   source spelling.  The remaining drift is the mirrored max assignment's
//   register and branch placement.
// - Duplicated the typed upper x comparison inside both mirror arms to test
//   the original paired compare hunk; this widened the function to 522 bytes
//   and worsened the positional diff to 189 bytes.  Restored the clean arm.

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);

class TShape {
public:
    char data[0x20];

    TShape(char* filename, long resource_id);
    ~TShape();
    unsigned char shape_check(long x, long y, long frame);
    unsigned char shape_minmax(long* out_minx, long* out_miny,
                               long* out_maxx, long* out_maxy,
                               long frame);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    void add_to_timing(int index, unsigned long value);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    void* color_tables;
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
    void* draw_list;
    void* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    void* sound_list;
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

    unsigned char get_facetindex(long facet, long frame, long& frame_out);
    unsigned char shape_hit_test(short x, short y, long facet, long frame);
};

unsigned char RGE_Sprite::shape_hit_test(short x, short y, long facet,
                                         long frame)
{
    char* fname;
    long shape_frame;
    long min_x;
    long min_y;
    long max_x;
    long max_y;
    unsigned char facet_index;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x366);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x368);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            goto fail;
        }
    }

    if (frame > this->frame_num) {
        frame = 0;
    }

    facet_index = this->get_facetindex(facet, frame, shape_frame);

    switch (this->transparent_picking_flag) {
    case 0:
        break;

    case 1:
        if (this->shape != 0) {
            if (facet_index == 0) {
                return this->shape->shape_check(x, y, shape_frame);
            }
            return this->shape->shape_check(-x, y, shape_frame);
        }
        break;

    case 2:
        if (this->shape != 0) {
            this->shape->shape_minmax(&min_x, &min_y, &max_x,
                                      &max_y, shape_frame);
            int x_value = x;
            if (facet_index != 0) {
                if (x_value < -max_x) {
                    goto fail;
                }
                max_x = -min_x;
            } else {
                if (x_value < min_x) {
                    goto fail;
                }
            }

            if (x_value > max_x) {
                goto fail;
            }
            if (y < min_y) {
                goto fail;
            }
            if (y > max_y) {
                goto fail;
            }
            return 1;
        }
        break;
    }

fail:
    return 0;
}
