// VA: 00457F80 RGE_Map::load_terrain_types
// Attempt log:
// baseline: typed terrain record reconstruction used an approximate record.
// probe 2: canonical RGE_Tile_Set fields, reverse loaded-byte clear, convert_us,
// direct float conversion, unconditional fclose, and tile shape totals.
// probe 3: reordered locals toward the binary stack map; diff improved.
// probe 4: restored count-minus-one loop and full giant fscanf argument surface.
// probe 5: one FILE local and the second parsed float as infile; diff 333 bytes.
// probes 6-10: tested format-width, parameter-home, cursor, and interval-home
// variants. They did not improve the best source and are not retained.
// New pass: one natural forward tile cursor reduced positional drift by 2 bytes,
// while typed stdio context and cursor declaration scope emitted no new bytes.
// The positive sound-index guard follows the target branch shape but did not
// improve positional drift. The remaining gap is the input-field overlay and
// local home/register placement. Calls, cleanup, record stride, and widths match.
// Fresh shard probe: moved shape_index initialization before the giant fscanf to
// match the oracle's pre-call EBX clear; this worsened the diff by 2 bytes and
// was restored. The input-field overlay remains the next structural blocker.

#include <stdio.h>

extern "C" void __cdecl convert_us(char*);
extern "C" void __cdecl strcpy(char*, char*);

class RGE_Sound;

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    void* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
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
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    unsigned char pad_end[2];
};

class RGE_Map {
public:
    char gap_00[0x8C];
    RGE_Tile_Set terrain_types[32];
    char gap_after_terrain[0x8D90 - 0x338C];
    short num_terrain;

    void load_terrain_types(char*, RGE_Sound**);
};

void RGE_Map::load_terrain_types(char* filename, RGE_Sound** sounds)
{
    int i;
    for (i = 31; i >= 0; --i) {
        this->terrain_types[i].loaded = 0;
    }

    FILE* local_38 = fopen(filename, "r");
    if (local_38 != 0) {
        fscanf(local_38, (char*)"%hd", &this->num_terrain);
        short terrain_count = this->num_terrain - 1;
        if (terrain_count >= 0) {
            int resource_id = (int)terrain_count + 1;
            do {
                short border_num;
                short border;
                short sound_id;
                short low_color;
                short med_color;
                short hi_color;
                short lt_cliff_color;
                short rt_cliff_color;
                short impassable_terrain;
                short passable_terrain;
                short row;
                short col;
                short is_animated;
                short animation_frames;
                short terrain_to_draw;
                short random;
                float interval;
                float infile;
                float local_30;
                long local_28;
                short terrain_id;
                char name[13];
                char pict_name[13];
                int i2;
                RGE_TOB_Picts* tile;

                if (fscanf(local_38, (char*)"%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %hd %hd",
                           &terrain_id, name, pict_name, &local_28,
                           &border_num, &lt_cliff_color, &rt_cliff_color, &hi_color,
                           &med_color, &terrain_to_draw, &random, &infile,
                           &local_30, &interval, &is_animated, &animation_frames,
                           &impassable_terrain, &passable_terrain, &row, &col,
                           &sound_id) != -1) {
                    if (terrain_id < 32 && terrain_id >= 0) {
                        RGE_Tile_Set* terrain = &this->terrain_types[terrain_id];
                        short shape_index = 0;
                        int tile_count = 19;
                        tile = terrain->tiles;
                        do {
                            fscanf(local_38, (char*)"%hd %hd",
                                   &tile->count, &tile->animations);
                            tile->shape_index = shape_index;
                            shape_index += tile->count * tile->animations;
                            ++tile;
                            --tile_count;
                        } while (tile_count != 0);

                        i2 = 0;
                        if (sound_id > 0) {
                            do {
                                fscanf(local_38, (char*)"%hd %hd", &border, &low_color);
                                terrain->borders[border] = low_color;
                                ++i2;
                            } while (i2 < sound_id);
                        }

                        if (med_color >= 0) {
                            terrain->sound = sounds[med_color];
                        } else {
                            terrain->sound = 0;
                        }
                        terrain->map_low_color = (unsigned char)hi_color;
                        terrain->map_med_color = (unsigned char)lt_cliff_color;
                        terrain->map_hi_color = (unsigned char)rt_cliff_color;
                        terrain->map_lt_cliff_color = (unsigned char)impassable_terrain;
                        terrain->map_rt_cliff_color = (unsigned char)passable_terrain;
                        terrain->impassable_terrain = (unsigned char)row;
                        terrain->passable_terrain = (unsigned char)col;
                        convert_us(name);
                        strcpy(terrain->name, name);
                        strcpy(terrain->pict_name, pict_name);
                        terrain->animate_last = 0.0f;
                        terrain->resource_id = local_28;
                        terrain->loaded = 1;
                        terrain->rows = is_animated;
                        terrain->cols = animation_frames;
                        terrain->is_animated = (unsigned char)terrain_to_draw;
                        terrain->animation_frames = random;
                        if (infile == 0.0f) {
                            terrain->pause_frames = 0;
                        } else {
                            terrain->pause_frames = (short)(local_30 / infile);
                        }
                        terrain->interval = infile;
                        terrain->frame = 0;
                        terrain->pause_between_loops = local_30;
                        terrain->draw_frame = 0;
                        terrain->frame_changed = 0;
                        terrain->drawn = 0;
                        terrain->terrain_to_draw = sound_id;
                    }
                }
                --resource_id;
            } while (resource_id != 0);
        }
    }
    fclose(local_38);
}
