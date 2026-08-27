#include "../include/sprite.h"
#include "../include/game_globals.h"

#include <stdio.h>
#include <stdlib.h>

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern "C" void __cdecl rge_write(int handle, void* buffer, int count);
extern "C" void __cdecl convert_us(char* string);
extern void __cdecl operator_delete(void* block);
extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl _ASMSet_Color_Xform(int value);
extern void __cdecl write_draw_log(char* text);
extern void __cdecl write_draw_log2(char* text);

static const char sprite_format[] =
    " %s %s %d %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %f %hd %hd %hd";
static const char picture_format[] = " %hd %hd %hd %hd";
static const char sound_format[] = "%hd %hd %hd";

// PDB order: sprite.cpp lines 42-72.
RGE_Sprite::RGE_Sprite(short sprite_id)
{
    this->color_tables = 0;
    this->id = sprite_id;
    this->last_time = 0;
    this->delta_time = 0;
    this->name[0] = 0;
    this->pict_name[0] = 0;
    this->resource_id = 0;
    this->frame_num = 0;
    this->facet_num = 0;
    this->color_table = 0;
    this->box_x1 = 0;
    this->box_y1 = 0;
    this->box_x2 = 0;
    this->box_y2 = 0;
    this->base_speed = 0.0f;
    this->duration = 0.0f;
    this->pause_between_loops = 0.0f;
    this->draw_list_num = 0;
    this->loaded = 0;
    this->shape = 0;
    this->main_sound = 0;
    this->mirror_flag = 0;
    this->color_flag = 0;
    this->draw_level = 0;
    this->transparent_picking_flag = 0;
    this->micro_man_sound = 0;
    this->flags = 0;
    this->draw_list = 0;
    this->sound_list = 0;
}

// PDB order: sprite.cpp lines 78-135.
RGE_Sprite::RGE_Sprite(int handle, RGE_Sound** sounds,
                       RGE_Color_Table** color_tables)
{
    this->color_tables = color_tables;
    this->last_time = 0;
    this->delta_time = 0;

    rge_read(handle, this->name, 0x15);
    rge_read(handle, this, 0x0D);
    rge_read(handle, &this->resource_id, 4);
    rge_read(handle, &this->loaded, 1);
    rge_read(handle, &this->color_flag, 1);
    rge_read(handle, &this->draw_level, 1);
    rge_read(handle, &this->color_table, 2);
    rge_read(handle, &this->transparent_picking_flag, 1);
    rge_read(handle, &this->box_x1, 2);
    rge_read(handle, &this->box_y1, 2);
    rge_read(handle, &this->box_x2, 2);
    rge_read(handle, &this->box_y2, 2);
    rge_read(handle, &this->draw_list_num, 2);

    short main_sound_id;
    rge_read(handle, &main_sound_id, 2);
    rge_read(handle, &this->micro_man_sound, 1);
    rge_read(handle, &this->frame_num, 2);
    rge_read(handle, &this->facet_num, 2);
    rge_read(handle, &this->base_speed, 4);
    rge_read(handle, &this->duration, 4);
    rge_read(handle, &this->pause_between_loops, 4);
    rge_read(handle, &this->flags, 1);
    rge_read(handle, &this->id, 2);
    rge_read(handle, &this->mirror_flag, 1);

    RGE_Sound* main_sound;
    if (main_sound_id >= 0) {
        main_sound = sounds[main_sound_id];
    } else {
        main_sound = 0;
    }
    this->main_sound = main_sound;

    if (this->draw_list_num > 0) {
        this->draw_list = (RGE_Picture_List*)calloc(
            (unsigned int)this->draw_list_num, 0x10);
        rge_read(handle, this->draw_list,
                 ((int)this->draw_list_num) << 4);
    } else {
        this->draw_list = 0;
    }

    if (this->micro_man_sound != 0) {
        this->sound_list = (RGE_Sound_List*)calloc(
            (unsigned int)this->facet_num, 0x14);

        int i = 0;
        if (this->facet_num > 0) {
            do {
                RGE_Sound_List* facet = &this->sound_list[i];
                for (int j = 0; j < 3; ++j) {
                    rge_read(handle, &facet->frame[j], 2);
                    short sound_id;
                    rge_read(handle, &sound_id, 2);
                    if (sound_id < 0) {
                        facet->sound[j] = 0;
                    } else {
                        facet->sound[j] = sounds[sound_id];
                    }
                }
                ++i;
            } while (i < this->facet_num);
        }
    } else {
        this->sound_list = 0;
    }
}

// PDB order: sprite.cpp lines 140-262.
RGE_Sprite::RGE_Sprite(FILE* infile, short sprite_id, RGE_Sound** sounds)
{
    this->color_tables = 0;
    this->id = sprite_id;
    this->last_time = 0;
    this->delta_time = 0;

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
    short sound_facet = (short)-1;
    int local_4;

    int result = fscanf(infile,
        sprite_format,
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
        // BINARY NOTE: the final count reuses sprite_id's parameter home.
        // Keep this alias so a partial scan keeps the shipped value.
        &sprite_id);

    if (result == -1) {
        return;
    }

    this->loaded = 0;
    this->shape = 0;
    convert_us(this->name);

    RGE_Sound* parsed_main_sound;
    if (temp_color_flag >= 0) {
        parsed_main_sound = sounds[temp_color_flag];
    } else {
        parsed_main_sound = 0;
    }
    this->main_sound = parsed_main_sound;

    if (temp_draw_level > 0) {
        this->mirror_flag = (char)((this->facet_num >> 1) +
                                   (this->facet_num >> 2));
    } else {
        this->mirror_flag = 0;
    }

    this->color_flag = (unsigned char)temp_transparent_picking_flag;
    this->draw_level = (unsigned char)temp_animated;
    this->transparent_picking_flag = (unsigned char)temp_directional;
    this->micro_man_sound = (unsigned char)(0 < sprite_id);

    this->flags = (unsigned char)(0 < temp_randomize_on_start);
    if (temp_loop_once != 0) {
        this->flags = (unsigned char)((0 < temp_randomize_on_start) + 2);
    }
    if (sound_id != 0) {
        this->flags = (unsigned char)(this->flags + 4);
    }
    if (sound_frame != 0) {
        this->flags = (unsigned char)(this->flags + 8);
    }

    if (*draw_count > 0) {
        RGE_Picture_List* allocated_draw_list = (RGE_Picture_List*)calloc(
            (unsigned int)*draw_count, 0x10);
        short i = 0;
        if (i < *draw_count) {
            this->draw_list = allocated_draw_list;
            do {
                RGE_Picture_List* entry = &this->draw_list[i];
                fscanf(infile, picture_format,
                       &entry->picture_num,
                       &entry->offset_x,
                       &entry->offset_y,
                       &entry->facet);
                ++i;
            } while (i < *draw_count);
        } else {
            this->draw_list = allocated_draw_list;
        }
    } else {
        this->draw_list = 0;
    }

    if (this->micro_man_sound != 0) {
        RGE_Sound_List* allocated_sound_list = (RGE_Sound_List*)calloc(
            (unsigned int)this->facet_num, 0x14);

        short i = 0;
        if (i < *facet_count) {
            this->sound_list = allocated_sound_list;
            do {
                for (int slot = 0; slot < 3; ++slot) {
                    this->sound_list[i].frame[slot] = (short)-1;
                }
                ++i;
            } while (i < *facet_count);
        } else {
            this->sound_list = allocated_sound_list;
        }

        local_4 = 0;
        if (sprite_id > 0) {
            int sound_count = sprite_id;
            do {
                short index1;
                short local_e;
                short last_facet;
                short sound_slot;
                int scan = fscanf(infile, sound_format,
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
            } while ((short)local_4 < sprite_id);
        }
    } else {
        this->sound_list = 0;
    }
}

// PDB order: sprite.cpp lines 267-288.
RGE_Sprite::~RGE_Sprite()
{
    TShape* shape = this->shape;
    if (shape != 0 && this->loaded != 0) {
        if (this->shape != 0) {
            shape->~TShape();
            operator_delete(shape);
        }
        this->loaded = 0;
    }

    this->shape = 0;

    if (this->sound_list != 0) {
        free(this->sound_list);
        this->sound_list = 0;
    }

    if (this->draw_list != 0) {
        free(this->draw_list);
        this->draw_list = 0;
    }

    this->color_tables = 0;
}

// PDB order: sprite.cpp lines 292-305.
void RGE_Sprite::rehook(RGE_Sprite** sprites)
{
    short i;
    if (draw_list_num > 0 && draw_list != 0) {
        i = 0;
        if (draw_list_num > 0) {
            goto loop_test;
loop_body:
            if (draw_list[i].picture_num == -1) {
                draw_list[i].sprite = this;
            } else {
                draw_list[i].sprite = sprites[draw_list[i].picture_num];
            }
            i++;
loop_test:
            if (i < draw_list_num) goto loop_body;
        }
    }
    load_facets(sprites);
}

// PDB order: sprite.cpp lines 309-358.
void RGE_Sprite::save(int handle)
{
    int info = -1;

    if (this->main_sound != 0) {
        info = this->main_sound->id;
    }

    rge_write(handle, this->name, 0x15);
    rge_write(handle, this, 0x0D);
    rge_write(handle, &this->resource_id, 4);
    rge_write(handle, &this->loaded, 1);
    rge_write(handle, &this->color_flag, 1);
    rge_write(handle, &this->draw_level, 1);
    rge_write(handle, &this->color_table, 2);
    rge_write(handle, &this->transparent_picking_flag, 1);
    rge_write(handle, &this->box_x1, 2);
    rge_write(handle, &this->box_y1, 2);
    rge_write(handle, &this->box_x2, 2);
    rge_write(handle, &this->box_y2, 2);
    rge_write(handle, &this->draw_list_num, 2);
    rge_write(handle, &info, 2);
    rge_write(handle, &this->micro_man_sound, 1);
    rge_write(handle, &this->frame_num, 2);
    rge_write(handle, &this->facet_num, 2);
    rge_write(handle, &this->base_speed, 4);
    rge_write(handle, &this->duration, 4);
    rge_write(handle, &this->pause_between_loops, 4);
    rge_write(handle, &this->flags, 1);
    rge_write(handle, &this->id, 2);
    rge_write(handle, &this->mirror_flag, 1);

    if (this->draw_list != 0) {
        rge_write(handle, this->draw_list,
                  ((int)this->draw_list_num) << 4);
    }

    if (this->micro_man_sound != 0) {
        int i = 0;
        if (this->facet_num > 0) {
            do {
                for (int j = 0; j < 3; ++j) {
                    RGE_Sound* sound = this->sound_list[i].sound[j];
                    int sound_id;
                    if (sound != 0) {
                        sound_id = sound->id;
                    } else {
                        sound_id = -1;
                    }
                    short* frame = &this->sound_list[i].frame[j];
                    rge_write(handle, frame, 2);
                    rge_write(handle, &sound_id, 2);
                }
                ++i;
            } while (i < this->facet_num);
        }
    }
}

// PDB order: sprite.cpp lines 362-392.
void RGE_Sprite::load_facets(RGE_Sprite** facets)
{
    this->shape = 0;
    this->loaded = 1;
}

// PDB order: sprite.cpp lines 396-437.
void RGE_Sprite::play_sound(short param_1, short param_2, short param_3)
{
    if (param_3 >= this->facet_num) {
        param_3 = 0;
    }

    if (param_1 != param_2) {
        if (this->main_sound != 0 &&
            (param_1 == 0 || (param_2 < param_1 && param_2 != 0))) {
            this->main_sound->play(1);
        }

        if (this->micro_man_sound != 0) {
            if (param_1 < param_2) {
                int i = 0;
                while (i < 3) {
                    int frame = this->sound_list[param_3].frame[i];
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= param_1 && frame < param_2) {
                        this->sound_list[param_3].sound[i]->play(1);
                    }
                    i++;
                }
            } else {
                int i = 0;
                while (i < 3) {
                    int frame = this->sound_list[param_3].frame[i];
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= param_1 || frame < param_2) {
                        this->sound_list[param_3].sound[i]->play(1);
                    }
                    i++;
                }
            }
        }
    }
}

// PDB order: sprite.cpp lines 441-471.
unsigned char RGE_Sprite::get_facetindex(long facet, long frame, long& index)
{
    if (this->mirror_flag != 0 && this->facet_num == 2) {
        index = frame;
        return (unsigned char)facet;
    }

    if (this->mirror_flag != 0 &&
        (facet > (long)(unsigned int)this->mirror_flag ||
         facet < ((int)this->facet_num >> 2))) {
        int i = (int)this->facet_num >> 1;
        if (facet > i) {
            i = i - facet;
            i = i + (int)this->facet_num;
        } else {
            i = i - facet;
        }
        index = i;
        int tmp = index;
        index = (tmp - ((int)this->facet_num >> 2)) *
                    (int)this->frame_num + frame;
        return 1;
    }

    if (this->mirror_flag != 0) {
        index = (facet - ((int)this->facet_num >> 2)) *
                    (int)this->frame_num + frame;
        return 0;
    }

    index = (int)this->frame_num * facet + frame;
    return 0;
}

// PDB order: sprite.cpp lines 475-590.
void RGE_Sprite::do_draw(long facet, long frame, long x, long y,
                         RGE_Color_Table* color_table,
                         TDrawArea* draw_area, unsigned char draw_level)
{
    char draw_log[256];
    long facetindex;
    char* fname = 0;

    if (frame >= this->frame_num) {
        frame = 0;
    }

    if (this->shape == 0) {
        if (this->loaded == 0) {
            return;
        }
        addstring(&fname, this->pict_name, ".shp");
        unsigned long start =
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x1E8);
        this->shape = new TShape(fname, this->resource_id);
        unsigned long end =
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x1EA);
        rge_base_game->add_to_timing(0x0B, end - start);
        free(fname);
    }

    this->delta_time = 0;
    SDI_Draw_Level = this->draw_level;
    if (SDI_Draw_Level < draw_level) {
        SDI_Draw_Level = draw_level;
    }
    SDI_List->Select_Box = 0;
    if (this->box_x1 != 0) {
        SDI_List->Select_Box = &this->box_x1;
    }

    unsigned char mirrored = this->get_facetindex(facet, frame, facetindex);
    if (mirrored != 0) {
        if (do_draw_log != 0) {
            sprintf(draw_log, "<%s,%d,%d,%d,%d,m", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(draw_log);
            } else {
                write_draw_log(draw_log);
            }
        }

        if (this->color_table < 0) {
            if (color_table != 0) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, color_table->table);
            } else {
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, 0);
            }
            goto draw_done;
        } else {
            unsigned char* table;
            unsigned char color = this->color_flag;
            if (this->color_tables[this->color_table] != 0) {
                _ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                table = this->color_tables[this->color_table]->table;
            } else {
                table = 0;
            }
            this->shape->shape_mirror(draw_area, x, y, facetindex,
                                      color, table);
        }
    } else {
        if (do_draw_log != 0) {
            sprintf(draw_log, "<%s,%d,%d,%d,%d,u", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(draw_log);
            } else {
                write_draw_log(draw_log);
            }
        }

        if (this->color_table < 0) {
            if (color_table != 0) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, color_table->table);
            } else {
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, 0);
            }
        } else {
            unsigned char* table;
            if (this->color_tables[this->color_table] != 0) {
                _ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                table = this->color_tables[this->color_table]->table;
            } else {
                table = 0;
            }
            this->shape->shape_draw(draw_area, x, y, facetindex,
                                    this->color_flag, table);
        }
    }

draw_done:
    if (do_draw_log != 0) {
        if (safe_draw_log != 0) {
            write_draw_log2(">");
        } else {
            write_draw_log(">");
        }
    }
}

// PDB order: sprite.cpp lines 594-621.
unsigned char RGE_Sprite::draw(long facet, long param_2, long param_3,
                               long param_4, long param_5, long param_6,
                               RGE_Color_Table* color_table,
                               TDrawArea* draw_area,
                               unsigned char color_index)
{
    int count;
    int entry_offset;

    if (facet >= (signed short)this->facet_num) {
        facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if (this->draw_level <= 0xa) {
            this->do_draw(facet, param_2, param_5, param_6,
                          color_table, draw_area, color_index);
        } else {
            this->do_draw(facet, param_2, param_3, param_4,
                          color_table, draw_area, color_index);
        }
        count = 1;
    } else {
        count = 0;
        if (0 < this->draw_list_num) {
            TDrawArea* loop_draw_area = draw_area;
            RGE_Color_Table* loop_color_table = color_table;
            entry_offset = 0;
            do {
                RGE_Picture_List* entry =
                    (RGE_Picture_List*)((char*)this->draw_list + entry_offset);
                short entry_facet = entry->facet;
                if ((entry_facet < 0) || (entry_facet == facet)) {
                    RGE_Sprite* sprite =
                        *(RGE_Sprite**)((char*)this->draw_list +
                                        entry_offset + 4);
                    int child_facet =
                        (sprite->facet_num * facet) /
                        (int)this->facet_num;
                    if (sprite->draw_level <= 0xa) {
                        sprite->do_draw(child_facet, param_2,
                                        (long)entry->offset_x + param_5,
                                        (long)entry->offset_y + param_6,
                                        loop_color_table, loop_draw_area,
                                        color_index);
                    } else {
                        sprite->do_draw(child_facet, param_2,
                                        (long)entry->offset_x + param_3,
                                        (long)entry->offset_y + param_4,
                                        loop_color_table, loop_draw_area,
                                        color_index);
                    }
                }
                count = count + 1;
                entry_offset = entry_offset + 0x10;
            } while (count < this->draw_list_num);
        }
    }
    return (unsigned char)count;
}

// PDB order: sprite.cpp lines 625-652.
unsigned char RGE_Sprite::normal_draw(long param_1, long param_2,
                                      long param_3, long param_4,
                                      RGE_Color_Table* param_5,
                                      TDrawArea* param_6)
{
    long facet;
    int index;
    int count;
    facet = param_1;
    if (param_1 >= this->facet_num) {
        facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if (this->draw_level == 0x14) {
            this->do_draw(facet, param_2, param_3, param_4,
                          param_5, param_6, 0);
        }
        count = 1;
    } else {
        count = 0;
        if (0 < this->draw_list_num) {
            index = 0;
            do {
                RGE_Sprite* sprite = this->draw_list[index].sprite;
                if ((sprite->draw_level == 0x14) &&
                    ((this->draw_list[index].facet < 0) ||
                     (this->draw_list[index].facet == facet))) {
                    sprite->do_draw((sprite->facet_num * facet) /
                                        (int)this->facet_num,
                                    param_2,
                                    (long)this->draw_list[index].offset_x +
                                        param_3,
                                    (long)this->draw_list[index].offset_y +
                                        param_4,
                                    param_5, param_6, 0);
                }
                count = count + 1;
                index = index + 1;
            } while (count < this->draw_list_num);
            return (unsigned char)count;
        }
    }
    return (unsigned char)count;
}

// PDB order: sprite.cpp lines 656-684.
unsigned char RGE_Sprite::shadow_draw(long param_1, long param_2,
                                      long param_3, long param_4,
                                      RGE_Color_Table* param_5,
                                      TDrawArea* param_6,
                                      unsigned char param_7)
{
    RGE_Sprite* sprite;
    long facet = param_1;
    int entry_offset;
    if (param_1 >= this->facet_num) {
        facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if ((this->draw_level != param_7) && (this->draw_level < 0x14)) {
            this->do_draw(facet, param_2, param_3, param_4,
                          param_5, param_6, 0);
        }
        param_1 = 1;
    } else {
        param_1 = 0;
        if (0 < this->draw_list_num) {
            entry_offset = 0;
            do {
                sprite = *(RGE_Sprite**)((char*)this->draw_list +
                                         entry_offset + 4);
                RGE_Picture_List* entry =
                    (RGE_Picture_List*)((char*)this->draw_list + entry_offset);
                if ((sprite->draw_level != param_7) &&
                    (sprite->draw_level < 0x14) &&
                    ((entry->facet < 0) || (entry->facet == facet))) {
                    sprite->do_draw((sprite->facet_num * facet) /
                                        (int)this->facet_num,
                                    param_2,
                                    (long)entry->offset_x + param_3,
                                    (long)entry->offset_y + param_4,
                                    param_5, param_6, 0);
                }
                param_1++;
                entry_offset = entry_offset + 0x10;
            } while (param_1 < this->draw_list_num);
            return (unsigned char)param_1;
        }
    }
    return (unsigned char)param_1;
}

// PDB order: sprite.cpp lines 688-707.
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

// PDB order: sprite.cpp lines 711-759.
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

        if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
            this->get_frame_min_max(min_x, min_y, max_x, max_y,
                                    frame, facet, 0, 0);
        } else {
            for (int i = 0; i < this->draw_list_num; ++i) {
                if (this->transparent_picking_flag > 0) {
                    this->draw_list[i].sprite->get_frame_min_max(
                        min_x, min_y, max_x, max_y,
                        (this->draw_list[i].sprite->facet_num * frame) /
                            this->facet_num,
                        facet,
                        this->draw_list[i].offset_x,
                        this->draw_list[i].offset_y);
                }
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

// PDB order: sprite.cpp lines 763-803.
int RGE_Sprite::get_frame_min_max(short& min_x, short& min_y, short& max_x,
                                  short& max_y, long frame, long facet,
                                  short offset_x, short offset_y)
{
    int facet_index;
    long frame_index = facet;
    long calc_min_y;
    long calc_max_y;
    long local_4;

    if (facet >= frame_num) {
        frame_index = 0;
    }

    facet_index = get_facetindex(frame, frame_index, calc_min_y);
    if (get_size(frame, calc_max_y, facet, local_4, calc_min_y) == 0) {
        return 0;
    }

    if (facet_index != 0) {
        int swap_temp;
        swap_temp = -frame;
        frame = -facet;
        facet = swap_temp;
    }

    frame += offset_x;
    facet += offset_x;
    calc_max_y += offset_y;
    local_4 += offset_y;

    if (frame < min_x) {
        min_x = (short)frame;
    }
    if (calc_max_y < min_y) {
        min_y = (short)calc_max_y;
    }
    if (facet > max_x) {
        max_x = (short)facet;
    }
    if (local_4 > max_y) {
        max_y = (short)local_4;
    }
    return 1;
}

// PDB order: sprite.cpp lines 807-827.
unsigned char RGE_Sprite::get_lowest_draw_level(void)
{
    short count = this->draw_list_num;
    if (count == 0) return this->draw_level;

    unsigned char lowest = 0x14;
    if (count > 0) {
        char* entry = (char*)this->draw_list + 4;
        int i = count;
        do {
            RGE_Sprite* sprite = *(RGE_Sprite**)(entry);
            if (sprite->draw_level < lowest) lowest = sprite->draw_level;
            entry += 0x10;
        } while (--i != 0);
    }
    return lowest;
}

// PDB order: sprite.cpp lines 831-850.
unsigned char RGE_Sprite::hit_test(short x, short y, long facet, long value)
{
    int index = 0;

    if (((this->box_x1 != 0) || (this->box_x2 != 0)) &&
        ((this->box_y1 != 0) || (this->box_y2 != 0))) {
        if ((x >= this->box_x1) && (x <= this->box_x2) &&
            (y >= this->box_y1) && (y <= this->box_y2)) {
            return 1;
        }
    }

    if ((this->draw_list_num > 0) && (this->draw_list != 0)) {
        int i = 0;
        if (this->draw_list_num > 0) {
            while (i < this->draw_list_num) {
                RGE_Sprite* sprite =
                    *(RGE_Sprite**)((char*)&this->draw_list->sprite + index);
                if (sprite->shape_hit_test(
                        x - *(short*)((char*)&this->draw_list->offset_x + index),
                        y - *(short*)((char*)&this->draw_list->offset_y + index),
                        (sprite->facet_num * facet) /
                            (int)this->facet_num,
                        value)) {
                    return 1;
                }
                index += 0x10;
                i++;
            }
        }
        return 0;
    }

    return this->shape_hit_test(x, y, facet, value);
}

// PDB order: sprite.cpp lines 855-915.
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
            if (facet_index != 0) {
                return this->shape->shape_check(-x, y, shape_frame);
            }
            return this->shape->shape_check(x, y, shape_frame);
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

// PDB order: sprite.cpp lines 919-924.
RGE_Active_Sprite* RGE_Sprite::make_active_sprite()
{
    if (this->flags & 1) {
        return new RGE_Active_Animated_Sprite(this);
    }
    return new RGE_Active_Sprite(this);
}

// PDB order: sprite.cpp lines 930-951.
int RGE_Sprite::check_for_shadows()
{
    short count;
    int limit;
    RGE_Picture_List* list;
    RGE_Sprite** sprite_ptr;
    int i;

    count = this->draw_list_num;
    if (count <= 0) goto fallback;
    list = this->draw_list;
    if (list == 0) goto fallback;
    limit = count;
    i = 0;
    if (limit <= 0) goto ret0;
    sprite_ptr = &list->sprite;

    while (1) {
        if ((*sprite_ptr)->draw_level == 0) goto ret1;
        i = i + 1;
        sprite_ptr = (RGE_Sprite**)((char*)sprite_ptr + 0x10);
        if (i < count) continue;
        return 0;
    }

fallback:
    if (this->draw_level == 0) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}

// PDB order: sprite.cpp lines 955-975.
void RGE_Sprite::update(unsigned long param_1)
{
    if (loaded) {
        TShape* pS = shape;
        if (pS) {
            int dt = delta_time;
            unsigned long time = param_1;
            // BINARY NOTE: update compares against the double at 00574528.
            if ((double)dt == DAT_00574528) {
                this->last_time = time;
                this->delta_time = 1;
                return;
            }
            int old_time = this->last_time;
            int elapsed = time - old_time;
            this->last_time = time;
            int new_dt = elapsed + dt;
            this->delta_time = new_dt;
            if (180000 <= new_dt) {
                TShape* pS2 = this->shape;
                if (pS2) {
                    pS2->~TShape();
                    operator_delete(pS2);
                }
                this->shape = 0;
            }
        }
    }
}
