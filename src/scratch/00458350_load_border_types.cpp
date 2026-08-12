// 00458350 RGE_Map::load_border_types
// Attempt log:
// 1: packet/decompiler based implementation had an approximate border record,
//    used strupr instead of convert_us, used the wrong tile shape-index store,
//    and returned before the original unconditional fclose; it was 771 bytes.
// 2: clean reconstruction: use the binary-proven RGE_Border_Set ownership and
//    0x5A0 record stride, the original 16-field fscanf format, convert_us and
//    intrinsic strcpy copies, and the 19x12 RGE_TOB_Picts grid.
// 3: guard the full record body instead of breaking on malformed/out-of-range
//    records; this restored the original seven ordered call sites and shared
//    resource-count tail.  The remaining structural gap is local pointer/frame
//    placement around the nested grid.
// 4: tested the binary-proven four-byte input-buffer payload offset
//    (name+4/pict_name+4 in the giant fscanf); the final clean source keeps
//    ordinary name/pict copies because that spelling emits the better basin.
// 5: the clean typed row-anchor pair reached exact size/frame but the anchor
//    spilled at +0x3C instead of the oracle's +0x24.  Test a binary-backed
//    pointer/float local overlay to let VC5 classify that proven stack slot.
// 6: final ABI/local-home probe follows the listing's true ownership: the
//    second %f is a float local named infile, while local_30 is the FILE* used
//    by all stream calls (the decompiler had these names crossed).
// 7: declaration reordering, the period CRT header combination, the 17-byte
//    prefixed-buffer variant, a typed pointer/float union, and the corrected
//    FILE*/float naming all either duplicated the 679-byte result or worsened
//    it.  Best clean reconstruction is exact in size/frame and all seven
//    ordered calls; remaining drift is VC5 local-home/register/block placement
//    around the row anchor and downstream field scheduling.
// 8: left in scratch after the 10-hypothesis budget.  The executable proves
//    the 0x338C map base, 0x5A0 border stride, +0x42 19x12 record grid, and
//    +0x28..+0x41 animation fields; do not replace these with raw decompiler
//    offsets.  Next lead is a fresh map.cpp donor/TU-local declaration-order
//    reconstruction for the +0x24 row-anchor versus +0x28 frame-rate homes.
// Fresh pass: a single cursor with p += 12 reduced the diagnostic diff but
// removed the target row-anchor spill and frame bytes, so it was restored.
// Reversed cursor roles, declaration order, and explicit count-down loops did
// not change or improve the exact-size clean basin. The typed two-cursor source
// remains the best period-plausible reconstruction; the row-anchor home is the
// open blocker.
//
// The border record layout is shared with the exact map.cpp constructors and
// update routine.  The map file's signed color/index locals intentionally retain
// their narrow input widths; only the resource id and timing values are widened
// at the operations where the original ABI requires it.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern "C" void __cdecl convert_us(char* str);
extern float DAT_005706ac;

class RGE_Sound;
class RGE_Tile;
class RGE_Player;
class RGE_Game_World;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;
class TShape;

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

class RGE_Border_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts borders[19][12];
    unsigned char draw_tile;
    unsigned char pad_0;
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long,
                                                   unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long, long,
                                                     unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long,
                                                 unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, void*, unsigned char*);
    virtual void map_generate2(void*, long, long, unsigned char, long);

    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    struct RGE_Tile_Size {
        short width;
        short height;
        short y_delta;
    } tilesizes[19];
    char pad_8A[2];
    char terrain_types[0x3300];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;

    void load_border_types(char*, RGE_Sound**);
};

void RGE_Map::load_border_types(char* filename, RGE_Sound** sounds)
{
    short sound_id;
    short low_color;
    short med_color;
    short hi_color;
    short is_animated;
    short animation_frames;
    short tile_flag;
    short underlay_terrain;
    short border_style;
    short random;
    short local_48;
    short local_46;
    RGE_TOB_Picts* p;
    RGE_TOB_Picts* row_start;
    float frame_rate;
    int local_3c;
    float infile;
    FILE* local_30;
    int resource_id;
    int local_28;
    char name[13];
    char pict_name[13];

    int i;
    for (i = 15; i >= 0; --i)
        this->border_types[i].loaded = 0;

    local_30 = fopen(filename, "r");
    if (local_30 != 0) {
        fscanf(local_30, "%hd", &this->num_borders);
        short remaining = this->num_borders - 1;
        if (remaining >= 0) {
            resource_id = (int)remaining + 1;
            do {
                short border_num;
                short shape_index = 0;
                if (fscanf(local_30,
                           "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd",
                           &border_num, name + 4, pict_name + 4, &local_28,
                           &local_46, &is_animated, &animation_frames, &hi_color,
                           &med_color, &tile_flag, &underlay_terrain, &frame_rate,
                           &infile, &border_style, &random, &local_48) != -1 &&
                    border_num < 16 && border_num >= 0) {
                    RGE_Border_Set* border = &this->border_types[border_num];
                    p = border->borders[0];
                    for (int row = 0; row < 19; ++row) {
                        row_start = p;
                        for (int col = 0; col < 12; ++col) {
                            fscanf(local_30, "%hd %hd", &p->count,
                                   &p->animations);
                            p->shape_index = shape_index;
                            shape_index += p->count * p->animations;
                            ++p;
                        }
                        p = row_start + 12;
                    }

                    if (med_color >= 0)
                        border->sound = sounds[med_color];
                    else
                        border->sound = 0;
                    border->map_low_color = (unsigned char)hi_color;
                    border->map_med_color = (unsigned char)is_animated;
                    border->map_hi_color = (unsigned char)animation_frames;
                    convert_us(name);
                    strcpy(border->name, name);
                    strcpy(border->pict_name, pict_name);
                    border->loaded = 1;
                    border->resource_id = local_28;
                    border->is_animated = (unsigned char)tile_flag;
                    border->animation_frames = underlay_terrain;
                    if (frame_rate == DAT_005706ac)
                        border->pause_frames = 0;
                    else
                        border->pause_frames = (short)(long)(infile / frame_rate);
                    border->interval = frame_rate;
                    border->pause_between_loops = infile;
                    border->frame = 0;
                    border->draw_frame = 0;
                    border->animate_last = 0.0f;
                    border->frame_changed = 0;
                    border->drawn = 0;
                    border->draw_tile = (unsigned char)border_style;
                    border->underlay_terrain = random;
                    border->border_style = local_48;
                }
            } while (--resource_id != 0);
        }
    }
    fclose(local_30);
}
