// VA: 004C0960 RGE_Sprite::get_frame (514B)
// PDB source: sprite.cpp, lines 711-759
// EH frame (/GX)
// Attempt log:
// - Replaced the old field-only scaffold with the natural lazy-shape load,
//   bounding-box fast path, and transparent draw-list aggregation recovered
//   from the executable.  Baseline: exact frame/prologue/calls, 533-byte
//   rebuild versus 514 bytes, 157 strict differing bytes.
// - Count-guard, shared-return, positive-gate, and short-count variants did
//   not improve the structural basin; direct typed list access preserved the
//   same code while the explicit unsigned transparent > 0 spelling improved
//   block/edit diagnostics by one byte.
// - Final clean source retains named RGE_Picture_List ownership and natural
//   member calls.  Remaining drift is the outer draw-list guard spelling and
//   late argument evaluation/block layout; no call-set or frame mismatch.
// - Continuation: <= 0 and negated-positive outer count guards compiled to a
//   direct memory compare or a larger structural basin; neither reproduced
//   the original test-AX/jle sequence.
// - Shared-result/goto and single-break-loop return forms did not retain the
//   original shared epilogue; receiver/offset locals were codegen-neutral.
// - A split raw record cursor/count variant was worse (275-byte diff), so it
//   was discarded.  Restored final natural typed source: 157-byte diff,
//   exact frame/call set, with the remaining guard, tail, and argument-order
//   drift documented for the next worker.
// Worker pass sprite-sa-0aea9221-0960: retested the binary-looking outer
// `draw_list_num <= 0` spelling; it moved to a 237-byte structural basin.
// Restored the natural typed `< 1` source; next lead is a source/context form
// that preserves the test-AX/jle guard without disturbing the EH tail.

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);

class TShape {
public:
    char data[0x20];

    TShape(char* filename, long resource_id);
    ~TShape();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    void add_to_timing(int index, unsigned long value);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Sprite;

class RGE_Picture_List {
public:
    short picture_num;
    char gap_02[2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
};

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
    RGE_Picture_List* draw_list;
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

    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y,
                  long frame, long facet);
    int get_frame_min_max(short& min_x, short& min_y, short& max_x,
                          short& max_y, long frame, long facet,
                          short offset_x, short offset_y);
};

int RGE_Sprite::get_frame(short& min_x, short& min_y, short& max_x,
                          short& max_y, long frame, long facet)
{
    char* fname;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2d2);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2d4);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            return 0;
        }
    }

    if (((this->box_x1 == 0) && (this->box_x2 == 0)) ||
        ((this->box_y1 == 0) && (this->box_y2 == 0))) {
        min_x = 0;
        min_y = 0;
        max_x = 0;
        max_y = 0;

        if ((this->draw_list_num < 1) || (this->draw_list == 0)) {
            this->get_frame_min_max(min_x, min_y, max_x, max_y,
                                    frame, facet, 0, 0);
        } else {
            int i = 0;
            if (this->draw_list_num > 0) {
                do {
                    if (this->transparent_picking_flag > 0) {
                        RGE_Picture_List* list = this->draw_list;
                        list[i].sprite->get_frame_min_max(
                            min_x, min_y, max_x, max_y,
                            (list[i].sprite->facet_num * facet) /
                                this->facet_num,
                            frame, list[i].offset_x, list[i].offset_y);
                    }
                    ++i;
                } while (i < this->draw_list_num);
            }
        }

        if (((min_x == 0) && (max_x == 0)) ||
            ((min_y == 0) && (max_y == 0))) {
            return 0;
        }
    } else {
        min_x = this->box_x1;
        min_y = this->box_y1;
        max_x = this->box_x2;
        max_y = this->box_y2;
    }

    return 1;
}
