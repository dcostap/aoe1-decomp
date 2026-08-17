// 00483600 RGE_RMM_Database_Controller::calc_land_start
// rmm_dbct.cpp
// Attempt log:
// try 1-11 (prior worker): broad decompiler-shaped reconstruction.  It used
// roundFloat/rand_scaled helpers and an incorrectly sized local slot record;
// the resulting 960-byte output had five extra helper calls and a 0x2c frame.
// try 12: restored the period typed RGE_Land_Info ownership (0x34-byte lines),
// inline debug_rand scaling, the x87 sqrt/bound expressions, and the binary's
// retry-on-inner-box / retry-on-close-neighbor control flow.
// try 13: restored the same-TU polymorphic base/controller surface; emitted
// bytes were unchanged, confirming the touched offsets are already canonical.
// try 14: delayed radius+radius until after the first log; this moved the
// callee-save coloring and improved the positional diff to 970 bytes.
// try 15: tested a saved original-radius plus typed current/previous cursor
// mode-2 source; it reached 967 bytes but grew the function to 1067 bytes and
// lost block coverage, so it was restored to the cleaner 1059-byte candidate.
// try 16: named map-range and register-qualified radius probes were codegen
// duplicates; no further source axis was productive within this assignment.
// try 17: changed the retry state from int to typed bool; the packet's byte
// parameter-home writes became a 0x30-frame, 0-byte-size candidate and cut
// positional drift from 970 to 575 bytes while preserving all 16 calls.
// worker probes: inverted the mode-2 bounds arm, removed the doubled-radius
// local, named the controller, hoisted distance deltas, and saved the radius;
// each was a codegen duplicate. Reusing the radius parameter as the loop index
// preserved some late blocks but grew the frame to 0x34 and drift to 1002.
// An explicit inner while loop was also a duplicate. Restore the typed-bool
// candidate; the remaining gap is saved-register and local-home allocation.
// current: retain the bool candidate; calls and frame are exact, while the
// remaining drift is block shape and register/local-home placement.
// Named rmm_dbct.cpp and debug-log literals retained the typed source and
// improved positional drift to 570 bytes.
// Current worker pass (probes 1-30): canonical long/RGE data ownership and the
// same-TU controller virtual surface were codegen duplicates. Float suffixes on
// the two branch scale constants improved drift from 570 to 568 bytes. The
// executable proves one shared retry-store block: an accepted box candidate and
// an accepted distance candidate both reach it, while scan exhaustion skips it.
// Explicit labels for that block improved drift to 544 bytes with exact frame,
// size, call count, and CFG counts. Typed explicit scan cursors, parameter
// mutation, declaration scopes, and register hints did not improve it. The
// current clean source remains unresolved at the saved-register/local-home
// boundary, with target this=EDI/two=EBP versus rebuilt this=EBP/two=EDI.

#include <math.h>

// The land table is embedded in the controller's land_info member.  Its y
// field is the cursor used by the original compiler, hence the characteristic
// controller+0x48 + index*0x34 address in the packet.
extern "C" int __cdecl debug_rand(const char*, int);
extern "C" void __cdecl Log(void*, const char*, ...);
extern void* L;

class RGE_Map;

static const char s_rmm_dbct_path[] = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp";
static const char s_calc_land_start[] =
    "********Random Map calc land start, rand: %d";
static const char s_calc_land_end_point1[] =
    "********Random Map calc land end (point1) ";
static const char s_calc_land_end_point2[] =
    "********Random Map calc land end (point2) ";
static const char s_calc_land_end_point3[] =
    "********Random Map calc land end (point3) ";
static const char s_calc_land_xy[] =
    "********Random Map calc land xy player %d (%d, %d)";
static const char s_calc_land_end[] =
    "********Random Map calc land end, rand:";

struct LandInfoLine {
    int land_size;
    int terrain_type;
    int x;
    int y;
    int base_size;
    int area;
    unsigned char zone;
    unsigned char pad_19[3];
    int clumpiness_factor;
    int wall_1;
    int wall_2;
    int wall_3;
    int wall_4;
    unsigned char wall_fade;
    unsigned char pad_31[3];
};

struct RGE_Land_Data_Entry {
    long land_id;
    unsigned char terrain_type;
    unsigned char pad_05[3];
    long land_avoidance_tiles;
    long base_square_radius;
    unsigned char zone;
    unsigned char placement;
    unsigned char pad_12[2];
    int x;
    int y;
};

struct LandInfoTable {
    LandInfoLine land[99];
    int land_num;
    unsigned char base_terrain;
    unsigned char pad_1421[3];
    int wall_1;
    int wall_2;
    int wall_3;
    int wall_4;
    unsigned char wall_fade;
    unsigned char pad_end[3];
};

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    void* stack_array;
    unsigned char** search_map_rows;
    void* stack_offsets;
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    void* world;
    int map_type;
    int number_of_players;
    LandInfoTable land_info;
    virtual unsigned char generate();
    virtual void add_land_module(unsigned char);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual unsigned char init(RGE_Map*, void*, unsigned char, long, unsigned char);
    virtual unsigned char de_init();
protected:
    void calc_land_start(long start, long radius, long count,
                         RGE_Land_Data_Entry* land);
};

void RGE_RMM_Database_Controller::calc_land_start(long start, long radius, long count,
                                                  RGE_Land_Data_Entry* land) {
    long i;
    long j;
    long x;
    long y;
    bool retry;
    float bound;
    long minx;
    long miny;
    long maxx;
    long maxy;

    Log(L, s_calc_land_start, debug_rand(s_rmm_dbct_path, 0x1c3));
    long two = radius + radius;
    bound = (float)(this->map_width - two) / sqrt((float)count);
    if (count > 3 && count < 7)
        bound *= 0.9F;
    else if (count >= 7)
        bound *= 0.8F;

    // BINARY NOTE: The scale factors here are 4-byte float constants.
    // The coordinate factors below are 8-byte constants in the executable.
    float bound_square = bound * bound;
    minx = (int)((this->map_width / 2) - (bound * 0.9));
    miny = (int)((this->map_height / 2) - (bound * 0.9));
    maxx = (int)((this->map_width / 2) - (bound * -0.9));
    maxy = (int)((this->map_height / 2) - (bound * -0.9));
    if (minx <= radius) minx = radius + 1;
    if (miny <= radius) miny = radius + 1;
    if (maxx >= this->map_width - radius - 1) maxx = this->map_width - radius - 2;
    if (maxy >= this->map_height - radius - 1) maxy = this->map_height - radius - 2;

    switch (land->placement) {
    case 0:
        Log(L, s_calc_land_end_point1);
        for (i=start;i<start+count;i++) {
            land_info.land[i].x = (debug_rand(s_rmm_dbct_path, 0x1e5) * (this->map_width - two)) / 0x7fff + radius;
            land_info.land[i].y = (debug_rand(s_rmm_dbct_path, 0x1e6) * (this->map_height - two)) / 0x7fff + radius;
        }
        break;
    case 1:
        Log(L, s_calc_land_end_point2);
        for (i=start;i<start+count;i++) {
            land_info.land[i].x = land->x;
            land_info.land[i].y = land->y;
        }
        break;
    case 2:
        Log(L, s_calc_land_end_point3);
        for (i=start;i<start+count;i++) {
            retry = 0;
            do {
                x = (debug_rand(s_rmm_dbct_path, 0x1fc) * (this->map_width - two)) / 0x7fff + radius;
                y = (debug_rand(s_rmm_dbct_path, 0x1fd) * (this->map_height - two)) / 0x7fff + radius;
                if (x > minx && x < maxx && y > miny && y < maxy)
                    goto retry_found;
                for (j=start; j<i; ++j) {
                    int dx=x-land_info.land[j].x; if (dx<0) dx=-dx;
                    int dy=y-land_info.land[j].y; if (dy<0) dy=-dy;
                    if ((float)(dx*dx + dy*dy) <= bound_square) {
                        if (j == i - 1) {
                            land_info.land[i].x = x;
                            land_info.land[i].y = y;
                            Log(L, s_calc_land_xy, i, x, y);
                        }
                        goto retry_found;
                    }
                }
                goto retry_done;
retry_found:
                // BINARY NOTE: Both accepted candidates use this retry store.
                retry = 1;
retry_done:
                ;
            } while (retry);
            land_info.land[i].x=x; land_info.land[i].y=y;
            Log(L, s_calc_land_xy, i, x, y);
        }
        break;
    default:
        break;
    }
    Log(L, s_calc_land_end);
}
