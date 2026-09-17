#include "../include/color.h"
#include "../include/drawarea.h"

#include <stdio.h>
#include <string.h>

extern void __cdecl rge_read(int fd, void* buf, int size);
extern void __cdecl rge_write(int fd, void* data, int size);
extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" void __cdecl free(void* ptr);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" long __cdecl _ftol();
extern char s_C__msdev_work_age1_x1_color_cpp[];

void __cdecl RGE_translate_palette(tagPALETTEENTRY* palette1, tagPALETTEENTRY* palette2, tagPALETTEENTRY color, long amount, int ignore_color1, int ignore_color2) {
    long index1;
    long intense[3];

    for (index1 = 0; index1 < 256; index1++) {
        if (index1 == ignore_color1 || index1 == ignore_color2) {
            palette2[index1].peRed = palette1[index1].peRed;
            palette2[index1].peGreen = palette1[index1].peGreen;
            palette2[index1].peBlue = palette1[index1].peBlue;
            palette2[index1].peFlags = palette1[index1].peFlags;
        } else {
            intense[0] = palette1[index1].peRed;
            intense[1] = palette1[index1].peGreen;
            intense[2] = palette1[index1].peBlue;

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (intense[j] < intense[j + 1]) {
                        long temp = intense[j];
                        intense[j] = intense[j + 1];
                        intense[j + 1] = temp;
                    }
                }
            }

            long intensity = intense[0]
                           + (intense[1] + intense[2])
                           * (255 - intense[0]) / 512;

            palette2[index1].peRed = palette1[index1].peRed
                + ((color.peRed * intensity / 255
                    - palette1[index1].peRed) * amount / 100);
            palette2[index1].peGreen = palette1[index1].peGreen
                + ((color.peGreen * intensity / 255
                    - palette1[index1].peGreen) * amount / 100);
            palette2[index1].peBlue = palette1[index1].peBlue
                + ((color.peBlue * intensity / 255
                    - palette1[index1].peBlue) * amount / 100);
            palette2[index1].peFlags = palette1[index1].peFlags;
        }
    }
}

void __cdecl RGE_fade_palette(TDrawArea* surface, tagPALETTEENTRY color, float fade_time, unsigned char direction, tagPALETTEENTRY* new_palette, int ignore_color1, int ignore_color2) {
    float delta_time;
    bool done;
    long old_time;
    float fade_time2;
    tagPALETTEENTRY palette1[256];
    tagPALETTEENTRY palette2[256];

    done = false;

    for (int i = 0; i < 256; i++) {
        palette1[i].peRed = 0;
        palette2[i].peRed = 0;
        palette1[i].peBlue = 0;
        palette2[i].peBlue = 0;
        palette1[i].peGreen = 0;
        palette2[i].peGreen = 0;
        palette1[i].peFlags = 0;
        palette2[i].peFlags = 0;
    }

    if (new_palette == 0) {
        surface->GetPalette(palette1);
    } else {
        tagPALETTEENTRY* target = palette1;
        tagPALETTEENTRY* source = new_palette;
        for (int j = 0; j < 256; j++) {
            target->peRed = source->peRed;
            target->peBlue = source->peBlue;
            target->peGreen = source->peGreen;
            target->peFlags = source->peFlags;
            ++target;
            ++source;
        }
    }

    old_time = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp, 105);
    fade_time2 = fade_time * fade_time;

    if (direction == 1) {
        do {
            long pct;
            long cur_time = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp, 112);
            delta_time = (float)(cur_time - old_time) * 0.001f;
            if (fade_time <= 0.0 || delta_time > fade_time || delta_time < 0.0f) {
                pct = 100;
            } else {
                pct = (long)((delta_time * delta_time / fade_time2) * 100.0f);
            }
            if (pct >= 100) {
                pct = 100;
                done = 1;
            }
            RGE_translate_palette(palette1, palette2, color, pct, ignore_color1, ignore_color2);
            surface->SetPalette(palette2);
        } while (!done);
    } else {
        do {
            long pct;
            long cur_time = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp, 136);
            delta_time = fade_time - ((float)(cur_time - old_time) * 0.001f);
            if (fade_time <= 0.0 || delta_time > fade_time || delta_time < 0.0f) {
                pct = 0;
            } else {
                pct = (long)((delta_time * delta_time / fade_time2) * 100.0f);
            }
            if (pct <= 0) {
                pct = 0;
                done = 1;
            }
            RGE_translate_palette(palette1, palette2, color, pct, ignore_color1, ignore_color2);
            surface->SetPalette(palette2);
        } while (!done);
    }
}

RGE_Color_Table::RGE_Color_Table(int infile) {
    struct ColorFileScratch {
        char prefix[2];
        short temp_color;
        char tempname[300];
    } scratch;

    rge_read(infile, this->color_table_name, 30);
    rge_read(infile, &this->id, 2);
    rge_read(infile, &this->resource_id, 2);
    rge_read(infile, &this->map_color, 1);
    rge_read(infile, &this->type, 1);

    sprintf(scratch.tempname, "data\\%s", this->color_table_name);

    FILE* fp = fopen(scratch.tempname, "r");
    if (fp) {
        for (int i = 0; i < 256; i++) {
            fscanf(fp, "%hd", &scratch.temp_color);
            this->table[i] = (unsigned char)scratch.temp_color;
        }
        fclose(fp);
    }
}

RGE_Color_Table::RGE_Color_Table(FILE* infile, short id_val) {
    char* file_name = 0;
    this->id = id_val;
    memset(this->table, 0, 256);

    fscanf(infile, "%hd %s %hd %hd", &this->resource_id, this->color_table_name, &id_val, &infile);
    this->map_color = (unsigned char)id_val;
    this->type = (unsigned char)infile;
    addstring(&file_name, this->color_table_name, ".col");
    strcpy(this->color_table_name, file_name);
    if (file_name != 0) {
        free(file_name);
    }
}

RGE_Color_Table::RGE_Color_Table(char* filename) {
    short temp_color;
    char tempname[300];

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, 256);
    strcpy(this->color_table_name, filename);
    strcat(this->color_table_name, ".col");

    sprintf(tempname, "data\\%s", this->color_table_name);
    FILE* fp = fopen(tempname, "r");
    if (fp) {
        for (int i = 0; i < 256; i++) {
            fscanf(fp, "%hd", &temp_color);
            this->table[i] = (unsigned char)temp_color;
        }
        fclose(fp);
    }
}

RGE_Color_Table::RGE_Color_Table(TDrawArea* surface, long amount, tagPALETTEENTRY* in_color, tagPALETTEENTRY* palette1) {
    long temp_color;
    tagPALETTEENTRY palette[256];
    tagPALETTEENTRY temp_palette[256];
    tagPALETTEENTRY color;
    long index1;

    if (palette1 == 0) {
        surface->GetPalette(palette);
    } else {
        for (int i = 0; i < 256; i++) {
            palette[i].peRed = palette1[i].peRed;
            palette[i].peGreen = palette1[i].peGreen;
            palette[i].peBlue = palette1[i].peBlue;
            palette[i].peFlags = palette1[i].peFlags;
        }
    }

    if (in_color == 0) {
        color.peRed = 0;
        color.peBlue = 0;
        color.peGreen = 0;
        color.peFlags = 0;
    } else {
        color.peRed = in_color->peRed;
        color.peBlue = in_color->peBlue;
        color.peGreen = in_color->peGreen;
        color.peFlags = in_color->peFlags;
    }

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, 256);

    RGE_translate_palette(palette, temp_palette, color, amount, -1, -1);

    index1 = 0;
    do {
        temp_color = 0;
        int i = 0;
        int best_distance = 20000;
        int red = temp_palette[index1].peRed;
        int green = temp_palette[index1].peGreen;
        int blue = temp_palette[index1].peBlue;

        for (; i <= 0xff; i++) {
            int red_difference = red - palette[i].peRed;
            int green_difference = green - palette[i].peGreen;
            int blue_difference = blue - palette[i].peBlue;
            int distance = red_difference * red_difference
                         + green_difference * green_difference
                         + blue_difference * blue_difference;
            if (distance < best_distance) {
                best_distance = distance;
                temp_color = i;
            }
        }

        this->table[index1] = (unsigned char)temp_color;
        index1++;
    } while (index1 <= 0xff);
}

RGE_Color_Table::~RGE_Color_Table() {
}

void RGE_Color_Table::save(int outfile) {
    rge_write(outfile, this->color_table_name, 30);
    rge_write(outfile, &this->id, 2);
    rge_write(outfile, &this->resource_id, 2);
    rge_write(outfile, &this->map_color, 1);
    rge_write(outfile, &this->type, 1);
}
