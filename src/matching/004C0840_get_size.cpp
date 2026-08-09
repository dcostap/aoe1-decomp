// VA: 004C0840 RGE_Sprite::get_size (279B)
// PDB source: sprite.cpp, lines 688-707
// FLAGS: config/flags/004C0840_get_size.rsp (/GX required by the TShape new-expression EH frame)
// Attempt log:
// probe 1 baseline: natural lazy TShape construction, timing calls, and typed
// shape_minmax references were exact-size/frame/call-set, but initialized fname at
// the function declaration and emitted the opposite EH-prologue order (247 diff).
// probe 2: baseline was exact-size/frame/call-set but initialized fname at the
// function declaration; original delays the fname zero store into line 696's
// call setup. Delaying the assignment recovered the mov-fs-first EH prologue and
// stack schedule (223 diff), leaving only the loaded-gate polarity/block placement.
// probe 3: positive nested loaded success with an explicit failure else matched
// the original je-to-0942 topology exactly (MATCH).
// main-agent audit restored canonical base-game polymorphic ownership; emitted
// code remains exact.

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);

class TShape {
public:
    char data[0x20];

    TShape(char* filename, long resource_id);
    ~TShape();
    unsigned char shape_minmax(long* out_minx, long* out_miny,
                               long* out_maxx, long* out_maxy,
                               long facet);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    void add_to_timing(int index, unsigned long value);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Color_Table;
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

    int get_size(long& min_x, long& min_y, long& max_x, long& max_y,
                 long facet);
};

int RGE_Sprite::get_size(long& min_x, long& min_y, long& max_x,
                         long& max_y, long facet)
{
    char* fname;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2b9);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2bb);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            return 0;
        }
    }

    return this->shape->shape_minmax(&min_x, &min_y, &max_x, &max_y, facet);
}
