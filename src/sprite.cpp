#include "../include/sprite.h"
#include "../include/asm_draw.h"
#include "../include/sprite_records.h"
#include "../include/sound.h"
#include "../include/view.h"
#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/color.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/rge_fio.h"
extern void __cdecl convert_us(char* string);
#include <new.h>
extern void __cdecl addstring(char** dst, char* base, char* ext);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl write_draw_log(char* text);
extern void __cdecl write_draw_log2(char* text);
extern int do_draw_log;
extern int safe_draw_log;
extern double DAT_00574528;

static const char sprite_format[] =
    " %s %s %d %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %f %hd %hd %hd";
static const char picture_format[] = " %hd %hd %hd %hd";
static const char sound_format[] = "%hd %hd %hd";

RGE_Sprite::RGE_Sprite(short in_id) {
    this->color_tables = 0;
    this->id = in_id;
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

RGE_Sprite::RGE_Sprite(int infile, RGE_Sound** sounds, RGE_Color_Table** c_tables) {
    this->color_tables = c_tables;
    this->last_time = 0;
    this->delta_time = 0;

    rge_read(infile, this->name, 21);
    rge_read(infile, this, 13);
    rge_read(infile, &this->resource_id, 4);
    rge_read(infile, &this->loaded, 1);
    rge_read(infile, &this->color_flag, 1);
    rge_read(infile, &this->draw_level, 1);
    rge_read(infile, &this->color_table, 2);
    rge_read(infile, &this->transparent_picking_flag, 1);
    rge_read(infile, &this->box_x1, 2);
    rge_read(infile, &this->box_y1, 2);
    rge_read(infile, &this->box_x2, 2);
    rge_read(infile, &this->box_y2, 2);
    rge_read(infile, &this->draw_list_num, 2);

    short info;
    rge_read(infile, &info, 2);
    rge_read(infile, &this->micro_man_sound, 1);
    rge_read(infile, &this->frame_num, 2);
    rge_read(infile, &this->facet_num, 2);
    rge_read(infile, &this->base_speed, 4);
    rge_read(infile, &this->duration, 4);
    rge_read(infile, &this->pause_between_loops, 4);
    rge_read(infile, &this->flags, 1);
    rge_read(infile, &this->id, 2);
    rge_read(infile, &this->mirror_flag, 1);

    RGE_Sound* main_sound;
    if (info >= 0) {
        main_sound = sounds[info];
    } else {
        main_sound = 0;
    }
    this->main_sound = main_sound;

    if (this->draw_list_num > 0) {
        this->draw_list = (RGE_Picture_List*)calloc(
            (unsigned int)this->draw_list_num, 16);
        rge_read(infile, this->draw_list,
                 ((int)this->draw_list_num) << 4);
    } else {
        this->draw_list = 0;
    }

    if (this->micro_man_sound != 0) {
        this->sound_list = (RGE_Sound_List*)calloc(
            (unsigned int)this->facet_num, 20);

        int i = 0;
        if (this->facet_num > 0) {
            do {
                RGE_Sound_List* facet = &this->sound_list[i];
                for (int index1 = 0; index1 < 3; ++index1) {
                    rge_read(infile, &facet->frame[index1], 2);
                    short lock1;
                    rge_read(infile, &lock1, 2);
                    if (lock1 < 0) {
                        facet->sound[index1] = 0;
                    } else {
                        facet->sound[index1] = sounds[lock1];
                    }
                }
                ++i;
            } while (i < this->facet_num);
        }
    } else {
        this->sound_list = 0;
    }
}

RGE_Sprite::RGE_Sprite(FILE* infile, short in_id, RGE_Sound** sounds) {
    this->color_tables = 0;
    this->id = in_id;
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
    int sound_index;

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
        // the final count reuses in_id's parameter home.
        // Keep this alias so a partial scan keeps the shipped value.
        &in_id);

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
    this->micro_man_sound = (unsigned char)(0 < in_id);

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
            (unsigned int)*draw_count, 16);
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
            (unsigned int)this->facet_num, 20);

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

        sound_index = 0;
        if (in_id > 0) {
            int sound_count = in_id;
            do {
                short index1;
                short sound_frame_value;
                short last_facet;
                short sound_slot;
                int scan = fscanf(infile, sound_format,
                                   &index1, &sound_frame_value, &last_facet);
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
                            sound_frame_value;
                    }
                }
                ++sound_index;
            } while ((short)sound_index < in_id);
        }
    } else {
        this->sound_list = 0;
    }
}

RGE_Sprite::~RGE_Sprite() {
    TShape* shape = this->shape;
    if (shape != 0 && this->loaded != 0) {
        if (this->shape != 0) {
            shape->~TShape();
            ::operator delete(shape);
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

void RGE_Sprite::rehook(RGE_Sprite** sprites) {
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

void RGE_Sprite::save(int outfile) {
    int info = -1;

    if (this->main_sound != 0) {
        info = this->main_sound->id;
    }

    rge_write(outfile, this->name, 21);
    rge_write(outfile, this, 13);
    rge_write(outfile, &this->resource_id, 4);
    rge_write(outfile, &this->loaded, 1);
    rge_write(outfile, &this->color_flag, 1);
    rge_write(outfile, &this->draw_level, 1);
    rge_write(outfile, &this->color_table, 2);
    rge_write(outfile, &this->transparent_picking_flag, 1);
    rge_write(outfile, &this->box_x1, 2);
    rge_write(outfile, &this->box_y1, 2);
    rge_write(outfile, &this->box_x2, 2);
    rge_write(outfile, &this->box_y2, 2);
    rge_write(outfile, &this->draw_list_num, 2);
    rge_write(outfile, &info, 2);
    rge_write(outfile, &this->micro_man_sound, 1);
    rge_write(outfile, &this->frame_num, 2);
    rge_write(outfile, &this->facet_num, 2);
    rge_write(outfile, &this->base_speed, 4);
    rge_write(outfile, &this->duration, 4);
    rge_write(outfile, &this->pause_between_loops, 4);
    rge_write(outfile, &this->flags, 1);
    rge_write(outfile, &this->id, 2);
    rge_write(outfile, &this->mirror_flag, 1);

    if (this->draw_list != 0) {
        rge_write(outfile, this->draw_list,
                  ((int)this->draw_list_num) << 4);
    }

    if (this->micro_man_sound != 0) {
        int index1 = 0;
        if (this->facet_num > 0) {
            do {
                for (int j = 0; j < 3; ++j) {
                    RGE_Sound* sound = this->sound_list[index1].sound[j];
                    int lock1;
                    if (sound != 0) {
                        lock1 = sound->id;
                    } else {
                        lock1 = -1;
                    }
                    short* frame = &this->sound_list[index1].frame[j];
                    rge_write(outfile, frame, 2);
                    rge_write(outfile, &lock1, 2);
                }
                ++index1;
            } while (index1 < this->facet_num);
        }
    }
}

void RGE_Sprite::load_facets(RGE_Sprite** sprites) {
    this->shape = 0;
    this->loaded = 1;
}

void RGE_Sprite::play_sound(short frame1, short frame2, short facet) {
    if (facet >= this->facet_num) {
        facet = 0;
    }

    if (frame1 != frame2) {
        if (this->main_sound != 0 &&
            (frame1 == 0 || (frame2 < frame1 && frame2 != 0))) {
            this->main_sound->play(1);
        }

        if (this->micro_man_sound != 0) {
            if (frame1 < frame2) {
                int i = 0;
                while (i < 3) {
                    int frame = this->sound_list[facet].frame[i];
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= frame1 && frame < frame2) {
                        this->sound_list[facet].sound[i]->play(1);
                    }
                    i++;
                }
            } else {
                int i = 0;
                while (i < 3) {
                    int frame = this->sound_list[facet].frame[i];
                    if (frame <= -1) {
                        return;
                    }
                    if (frame >= frame1 || frame < frame2) {
                        this->sound_list[facet].sound[i]->play(1);
                    }
                    i++;
                }
            }
        }
    }
}

unsigned char RGE_Sprite::get_facetindex(long facet, long frame, long& facetindex) {
    if (this->mirror_flag != 0 && this->facet_num == 2) {
        facetindex = frame;
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
        facetindex = i;
        int tmp = facetindex;
        facetindex = (tmp - ((int)this->facet_num >> 2)) *
                    (int)this->frame_num + frame;
        return 1;
    }

    if (this->mirror_flag != 0) {
        facetindex = (facet - ((int)this->facet_num >> 2)) *
                    (int)this->frame_num + frame;
        return 0;
    }

    facetindex = (int)this->frame_num * facet + frame;
    return 0;
}

void RGE_Sprite::do_draw(long facet, long frame, long x, long y,
                         RGE_Color_Table* player_color,
                         TDrawArea* draw_area, unsigned char min_draw_level) {
    char s[256];
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
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 488);
        this->shape = new TShape(fname, this->resource_id);
        unsigned long end =
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 490);
        rge_base_game->add_to_timing(0x0B, end - start);
        free(fname);
    }

    this->delta_time = 0;
    SDI_Draw_Level = this->draw_level;
    if (SDI_Draw_Level < min_draw_level) {
        SDI_Draw_Level = min_draw_level;
    }
    SDI_List->Select_Box = 0;
    if (this->box_x1 != 0) {
        SDI_List->Select_Box = &this->box_x1;
    }

    unsigned char mirrored = this->get_facetindex(facet, frame, facetindex);
    if (mirrored != 0) {
        if (do_draw_log != 0) {
            sprintf(s, "<%s,%d,%d,%d,%d,m", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(s);
            } else {
                write_draw_log(s);
            }
        }

        if (this->color_table < 0) {
            if (player_color != 0) {
                ASMSet_Color_Xform((player_color->id + 1) * 0x10);
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, player_color->table);
            } else {
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, 0);
            }
            goto draw_done;
        } else {
            if (this->color_tables[this->color_table] != 0) {
                ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                this->shape->shape_mirror(
                    draw_area, x, y, facetindex, this->color_flag,
                    this->color_tables[this->color_table]->table);
            } else {
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, 0);
            }
        }
    } else {
        if (do_draw_log != 0) {
            sprintf(s, "<%s,%d,%d,%d,%d,u", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(s);
            } else {
                write_draw_log(s);
            }
        }

        if (this->color_table < 0) {
            if (player_color != 0) {
                ASMSet_Color_Xform((player_color->id + 1) * 0x10);
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, player_color->table);
            } else {
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, 0);
            }
        } else {
            if (this->color_tables[this->color_table] != 0) {
                ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                this->shape->shape_draw(
                    draw_area, x, y, facetindex, this->color_flag,
                    this->color_tables[this->color_table]->table);
            } else {
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, 0);
            }
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

unsigned char RGE_Sprite::draw(long facet, long frame, long x, long y,
                               long sx, long sy,
                               RGE_Color_Table* player_color,
                               TDrawArea* draw_area,
                               unsigned char min_draw_level) {
    int count;
    int entry_offset;

    if (facet >= (signed short)this->facet_num) {
        facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if (this->draw_level <= 0xa) {
            this->do_draw(facet, frame, sx, sy,
                          player_color, draw_area, min_draw_level);
        } else {
            this->do_draw(facet, frame, x, y,
                          player_color, draw_area, min_draw_level);
        }
        count = 1;
    } else {
        count = 0;
        if (0 < this->draw_list_num) {
            TDrawArea* loop_draw_area = draw_area;
            RGE_Color_Table* loop_color_table = player_color;
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
                        sprite->do_draw(child_facet, frame,
                                        (long)entry->offset_x + sx,
                                        (long)entry->offset_y + sy,
                                        loop_color_table, loop_draw_area,
                                        min_draw_level);
                    } else {
                        sprite->do_draw(child_facet, frame,
                                        (long)entry->offset_x + x,
                                        (long)entry->offset_y + y,
                                        loop_color_table, loop_draw_area,
                                        min_draw_level);
                    }
                }
                count = count + 1;
                entry_offset = entry_offset + 0x10;
            } while (count < this->draw_list_num);
        }
    }
    return (unsigned char)count;
}

unsigned char RGE_Sprite::normal_draw(long facet, long frame, long x, long y,
                                      RGE_Color_Table* player_color,
                                      TDrawArea* draw_area) {
    long local_facet;
    int index;
    int count;
    local_facet = facet;
    if (facet >= this->facet_num) {
        local_facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if (this->draw_level == 0x14) {
            this->do_draw(local_facet, frame, x, y,
                          player_color, draw_area, 0);
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
                     (this->draw_list[index].facet == local_facet))) {
                    sprite->do_draw((sprite->facet_num * local_facet) /
                                        (int)this->facet_num,
                                    frame,
                                    (long)this->draw_list[index].offset_x +
                                        x,
                                    (long)this->draw_list[index].offset_y +
                                        y,
                                    player_color, draw_area, 0);
                }
                count = count + 1;
                index = index + 1;
            } while (count < this->draw_list_num);
            return (unsigned char)count;
        }
    }
    return (unsigned char)count;
}

unsigned char RGE_Sprite::shadow_draw(long facet, long frame, long x, long y,
                                      RGE_Color_Table* player_color,
                                      TDrawArea* draw_area,
                                      unsigned char flag) {
    RGE_Sprite* sprite;
    long local_facet = facet;
    if (facet >= this->facet_num) {
        local_facet = 0;
    }

    if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
        if ((this->draw_level != flag) && (this->draw_level < 0x14)) {
            this->do_draw(local_facet, frame, x, y,
                          player_color, draw_area, 0);
        }
        facet = 1;
    } else {
        facet = 0;
        if (0 < this->draw_list_num) {
            do {
                sprite = this->draw_list[facet].sprite;
                if ((sprite->draw_level != flag) &&
                    (sprite->draw_level < 0x14) &&
                    ((this->draw_list[facet].facet < 0) ||
                     (this->draw_list[facet].facet == local_facet))) {
                    sprite->do_draw((sprite->facet_num * local_facet) /
                                        (int)this->facet_num,
                                    frame,
                                    (long)this->draw_list[facet].offset_x + x,
                                    (long)this->draw_list[facet].offset_y + y,
                                    player_color, draw_area, 0);
                }
                facet++;
            } while (facet < this->draw_list_num);
            return (unsigned char)facet;
        }
    }
    return (unsigned char)facet;
}

int RGE_Sprite::get_size(long& xmin, long& ymin, long& xmax, long& ymax, long facet) {
    char* fname;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 697);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 699);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            return 0;
        }
    }

    return this->shape->shape_minmax(xmin, ymin, xmax, ymax, facet);
}

int RGE_Sprite::get_frame(short& min_x, short& min_y, short& max_x, short& max_y, long facet, long frame) {
    char* fname;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 722);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 724);
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
                                    facet, frame, 0, 0);
        } else {
            for (int i = 0; i < this->draw_list_num; ++i) {
                if (this->transparent_picking_flag > 0) {
                    this->draw_list[i].sprite->get_frame_min_max(
                        min_x, min_y, max_x, max_y,
                        (this->draw_list[i].sprite->facet_num * facet) /
                            this->facet_num,
                        frame,
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

int RGE_Sprite::get_frame_min_max(short& min_x, short& min_y, short& max_x,
                                  short& max_y, long facet, long frame,
                                  short pic_x, short pic_y) {
    int facetindex;
    long frame_index = frame;
    long calc_min_y;
    long calc_max_y;
    long calc_max_y_value;

    if (frame >= frame_num) {
        frame_index = 0;
    }

    facetindex = get_facetindex(facet, frame_index, calc_min_y);
    if (get_size(facet, calc_max_y, frame, calc_max_y_value, calc_min_y) == 0) {
        return 0;
    }

    if (facetindex != 0) {
        int swap_temp;
        swap_temp = -facet;
        facet = -frame;
        frame = swap_temp;
    }

    facet += pic_x;
    frame += pic_x;
    calc_max_y += pic_y;
    calc_max_y_value += pic_y;

    if (facet < min_x) {
        min_x = (short)facet;
    }
    if (calc_max_y < min_y) {
        min_y = (short)calc_max_y;
    }
    if (frame > max_x) {
        max_x = (short)frame;
    }
    if (calc_max_y_value > max_y) {
        max_y = (short)calc_max_y_value;
    }
    return 1;
}

unsigned char RGE_Sprite::get_lowest_draw_level(void) {
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

unsigned char RGE_Sprite::hit_test(short x, short y, long facet, long frame) {
    if (((this->box_x1 != 0) || (this->box_x2 != 0)) &&
        ((this->box_y1 != 0) || (this->box_y2 != 0))) {
        if ((x >= this->box_x1) && (x <= this->box_x2) &&
            (y >= this->box_y1) && (y <= this->box_y2)) {
            return 1;
        }
    }

    if ((this->draw_list_num > 0) && (this->draw_list != 0)) {
        int index = 0;
        if (this->draw_list_num > 0) {
            while (index < this->draw_list_num) {
                RGE_Sprite* sprite = this->draw_list[index].sprite;
                if (sprite->shape_hit_test(
                        x - this->draw_list[index].offset_x,
                        y - this->draw_list[index].offset_y,
                        (sprite->facet_num * facet) /
                            (int)this->facet_num,
                        frame)) {
                    return 1;
                }
                index++;
            }
        }
        return 0;
    }

    return this->shape_hit_test(x, y, facet, frame);
}

unsigned char RGE_Sprite::shape_hit_test(short x, short y, long facet, long frame) {
    char* fname;
    long shape_num;
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
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 870);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 872);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            goto fail;
        }
    }

    if (frame > this->frame_num) {
        frame = 0;
    }

    facet_index = this->get_facetindex(facet, frame, shape_num);

    switch (this->transparent_picking_flag) {
    case 0:
        break;

    case 1:
        if (this->shape != 0) {
            if (facet_index != 0) {
                return this->shape->shape_check(-x, y, shape_num);
            }
            return this->shape->shape_check(x, y, shape_num);
        }
        break;

    case 2:
        if (this->shape != 0) {
            this->shape->shape_minmax(min_x, min_y, max_x, max_y,
                                      shape_num);
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

RGE_Active_Sprite* RGE_Sprite::make_active_sprite() {
    if (this->flags & 1) {
        return new RGE_Active_Animated_Sprite(this);
    }
    return new RGE_Active_Sprite(this);
}

int RGE_Sprite::check_for_shadows() {
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

void RGE_Sprite::update(unsigned long curr_time) {
    if (this->loaded != 0 && this->shape != 0) {
        long old_delta_time = this->delta_time;
        if (old_delta_time == DAT_00574528) {
            this->last_time = curr_time;
            this->delta_time = 1;
        } else {
            unsigned long elapsed_time = curr_time - this->last_time;
            this->last_time = curr_time;
            elapsed_time += old_delta_time;
            this->delta_time = elapsed_time;

            if (this->delta_time >= 180000) {
                delete this->shape;
                this->shape = 0;
            }
        }
    }
}
