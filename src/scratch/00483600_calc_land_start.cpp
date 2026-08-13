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
// current: retain the bool candidate; calls and frame are exact, while the
// remaining drift is block shape and register/local-home placement.

#include <math.h>

// The land table is embedded in the controller's land_info member.  Its y
// field is the cursor used by the original compiler, hence the characteristic
// controller+0x48 + index*0x34 address in the packet.
extern "C" int __cdecl debug_rand(const char*, int);
extern "C" void __cdecl Log(void*, const char*, ...);
extern void* L;

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

struct LandInfo {
    char gap0[0x11];
    unsigned char placement;
    char gap12[2];
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
    void* parent;
    void* list;
    void* map;
    void* map_row_offset;
    int map_width;
    int map_height;
    float schedule;
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    void* world;
    int map_type;
    int number_of_players;
    LandInfoTable land_info;
    void calc_land_start(int start, int radius, int count, LandInfo* land);
};

void RGE_RMM_Database_Controller::calc_land_start(int start, int radius, int count, LandInfo* land) {
    int i;
    int j;
    int x;
    int y;
    bool retry;
    int two;
    float bound;
    float bound_square;
    int minx;
    int miny;
    int maxx;
    int maxy;

    Log(L,(const char*)0x585D20, debug_rand((const char*)0x585D50,0x1c3));
    two = radius + radius;
    bound = (float)(this->map_width - two) / sqrt((float)count);
    if (count > 3 && count < 7)
        bound *= 0.9;
    else if (count >= 7)
        bound *= 0.8;

    bound_square = bound * bound;
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
        Log(L,(const char*)0x585C68);
        for (i=start;i<start+count;i++) {
            land_info.land[i].x = (debug_rand((const char*)0x585D50,0x1e5) * (this->map_width - two)) / 0x7fff + radius;
            land_info.land[i].y = (debug_rand((const char*)0x585D50,0x1e6) * (this->map_height - two)) / 0x7fff + radius;
        }
        break;
    case 1:
        Log(L,(const char*)0x585C94);
        for (i=start;i<start+count;i++) {
            land_info.land[i].x = land->x;
            land_info.land[i].y = land->y;
        }
        break;
    case 2:
        Log(L,(const char*)0x585CF4);
        for (i=start;i<start+count;i++) {
            retry = 0;
            do {
                x = (debug_rand((const char*)0x585D50,0x1fc) * (this->map_width - two)) / 0x7fff + radius;
                y = (debug_rand((const char*)0x585D50,0x1fd) * (this->map_height - two)) / 0x7fff + radius;
                if (x > minx && x < maxx && y > miny && y < maxy) {
                    retry = 1;
                }
                else {
                    for (j=start; j<i; ++j) {
                        int dx=x-land_info.land[j].x; if (dx<0) dx=-dx;
                        int dy=y-land_info.land[j].y; if (dy<0) dy=-dy;
                        if ((float)(dx*dx + dy*dy) <= bound_square) {
                            if (j == i - 1) {
                                land_info.land[i].x = x;
                                land_info.land[i].y = y;
                                Log(L,(const char*)0x585CC0,i,x,y);
                            }
                            retry = 1;
                            break;
                        }
                    }
                }
            } while (retry);
            land_info.land[i].x=x; land_info.land[i].y=y;
            Log(L,(const char*)0x585CC0,i,x,y);
        }
        break;
    default:
        break;
    }
    Log(L,(const char*)0x585C40);
}
