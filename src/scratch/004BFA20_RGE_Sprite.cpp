// VA: 004BFA20 RGE_Sprite::RGE_Sprite (701B)
// PDB source: sprite.cpp, lines 140-262
// Text-file sprite constructor.  The fields, temporary widths, and parser
// order follow the binary evidence; the source remains a normal typed
// reconstruction rather than the decompiler's raw cursor form.
// Attempt log:
// - Baseline natural parser matched all six calls and CFG count but was
//   21 bytes short with a 0x20 frame.
// - Named draw/facet pointers improved the basin; a shared short index and
//   source-local register variants were tested and rolled back when they
//   broadened drift.
// - Hoisting the -1 sound-facet sentinel and using a short sound slot
//   recovered the exact 701-byte size/frame and 84.84% shape similarity,
//   with 549 strict differing bytes and 36.71% exact-block coverage.
// - Paused at the bounded limit.  Remaining drift starts with parameter
//   load/zero-store scheduling and later draw-list/sound-loop register and
//   cleanup topology; field ownership, parser order, calls, and behavior
//   surfaces are reconstructed in named typed C++.
// - Reordered the natural id assignment before the initial zero stores to
//   follow the first binary hunk; this moved the parameter load before the
//   saved-register prologue and worsened the block shape, so it was rolled
//   back.

#include <stdio.h>

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl convert_us(char* str);

class RGE_Color_Table;
class RGE_Sprite;

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
};

class RGE_Picture_List {
public:
    short picture_num;
    short gap_02;
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
    short gap_0E;
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    short gap_12;
};

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    void* shape;
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

    RGE_Sprite(FILE* infile, short sprite_id, RGE_Sound** sounds);
};

RGE_Sprite::RGE_Sprite(FILE* infile, short sprite_id, RGE_Sound** sounds)
{
    this->color_tables = 0;
    this->last_time = 0;
    this->delta_time = 0;
    this->id = sprite_id;

    short* draw_count = &this->draw_list_num;
    short* facet_count = &this->facet_num;

    short temp_draw_level;
    short temp_color_flag;
    short temp_transparent_picking_flag;
    short temp_animated;
    short temp_directional;
    short temp_randomize_on_start;
    short temp_loop_once;
    short sound_id;
    short sound_frame;
    short temp_micro_man_sound;
    short sound_facet = (short)-1;
    int local_4;

    int result = fscanf(infile,
        (const char*)0x005870D8,
        this->name,
        this->pict_name,
        &this->resource_id,
        &this->frame_num,
        facet_count,
        &temp_draw_level,
        &temp_transparent_picking_flag,
        &temp_animated,
        &this->color_table,
        &sound_id,
        &temp_directional,
        &temp_randomize_on_start,
        &temp_loop_once,
        &sound_frame,
        &this->box_x1,
        &this->box_y1,
        &this->box_x2,
        &this->box_y2,
        &this->base_speed,
        &this->duration,
        &this->pause_between_loops,
        draw_count,
        &temp_color_flag,
        &temp_micro_man_sound);

    if (result == -1) {
        return;
    }

    this->loaded = 0;
    this->shape = 0;
    convert_us(this->name);

    if (temp_color_flag < 0) {
        this->main_sound = 0;
    } else {
        this->main_sound = sounds[temp_color_flag];
    }

    if (temp_draw_level < 1) {
        this->mirror_flag = 0;
    } else {
        this->mirror_flag = (char)((this->facet_num >> 1) +
                                   (this->facet_num >> 2));
    }

    this->color_flag = (unsigned char)temp_transparent_picking_flag;
    this->draw_level = (unsigned char)temp_animated;
    this->transparent_picking_flag = (unsigned char)temp_directional;
    this->micro_man_sound = (unsigned char)(0 < temp_micro_man_sound);

    this->flag = (unsigned char)(0 < temp_randomize_on_start);
    if (temp_loop_once != 0) {
        this->flag = (unsigned char)((0 < temp_randomize_on_start) + 2);
    }
    if (sound_id != 0) {
        this->flag = (unsigned char)(this->flag + 4);
    }
    if (sound_frame != 0) {
        this->flag = (unsigned char)(this->flag + 8);
    }

    if (*draw_count < 1) {
        this->draw_list = 0;
    } else {
        this->draw_list = (RGE_Picture_List*)calloc(
            (unsigned int)*draw_count, 0x10);
        short i = 0;
        if (*draw_count > 0) {
            do {
                RGE_Picture_List* entry = &this->draw_list[i];
                fscanf(infile, (const char*)0x005870C4,
                       &entry->picture_num,
                       &entry->offset_x,
                       &entry->offset_y,
                       &entry->facet);
                ++i;
            } while (i < *draw_count);
        }
    }

    if (this->micro_man_sound == 0) {
        this->sound_list = 0;
    } else {
        this->sound_list = (RGE_Sound_List*)calloc(
            (unsigned int)this->facet_num, 0x14);

        short i = 0;
        if (*facet_count > 0) {
            do {
                for (int slot = 0; slot < 3; ++slot) {
                    this->sound_list[i].frame[slot] = (short)-1;
                }
                ++i;
            } while (i < *facet_count);
        }

        int sound_count = 0;
        local_4 = 0;
        if (temp_micro_man_sound > 0) {
            do {
                short index1;
                short local_e;
                short last_facet;
                short sound_slot;
                int scan = fscanf(infile, (const char*)0x0058491C,
                                   &index1, &local_e, &last_facet);
                if (scan != -1) {
                    if (sound_facet == index1) {
                        ++sound_count;
                    } else {
                        sound_count = 0;
                        sound_facet = index1;
                    }

                    sound_slot = (short)sound_count;
                    if (index1 >= 0 && index1 < this->facet_num &&
                        sound_slot < 3) {
                        this->sound_list[index1].sound[sound_slot] =
                            sounds[last_facet];
                        this->sound_list[index1].frame[sound_slot] =
                            local_e;
                    }
                }
                ++local_4;
            } while (local_4 < temp_micro_man_sound);
        }
    }
}
