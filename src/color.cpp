#include "../include/color.h"
#include "../include/drawarea.h"

#include <stdio.h>
#include <string.h>

extern void __cdecl rge_read(int fd, void* buf, int size);
extern void __cdecl rge_write(int fd, void* data, int size);
extern "C" void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" void __cdecl free(void* ptr);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" long __cdecl _ftol();
extern char s_C__msdev_work_age1_x1_color_cpp[];

void __cdecl RGE_translate_palette(tagPALETTEENTRY* src, tagPALETTEENTRY* dst,
                                   tagPALETTEENTRY color, long pct,
                                   int keep1, int keep2)
{
    unsigned char* d;
    unsigned char* s;
    long diff;
    long index1;
    long intense[4];
    intense[0] = 0;
    d = &dst->peFlags;
    diff = (int)dst - (int)src;
    s = &src->peGreen;

    do {
        if (intense[0] == keep1 || intense[0] == keep2) {
            d[-3] = s[-1];
            s[diff] = *s;
            d[-1] = s[1];
            d[0] = s[2];
        } else {
            tagPALETTEENTRY t = *(tagPALETTEENTRY*)(s - 1);
            intense[1] = t.peRed;
            intense[2] = *s;
            intense[3] = s[1];

            index1 = 2;
            do {
                long* p = &intense[2];
                for (long n = 2; n != 0; n--) {
                    long a = p[-1];
                    long b = p[0];
                    if (a < b) {
                        p[-1] = b;
                        p[0] = a;
                    }
                    p++;
                }
                index1--;
            } while (index1 != 0);

            long minv = intense[1];
            long inten = (((intense[2] + intense[3]) * (0xff - minv)) / 512) + minv;
            long v;
            v = ((color.peRed * inten) / 255 - t.peRed) * pct;
            d[-3] = (unsigned char)(t.peRed + (v / 100));
            v = ((color.peGreen * inten) / 255 - *s) * pct;
            s[diff] = (unsigned char)(*s + (v / 100));
            v = ((color.peBlue * inten) / 255 - s[1]) * pct;
            d[-1] = (unsigned char)(s[1] + (v / 100));
            d[0] = s[2];
        }
        intense[0]++;
        s += 4;
        d += 4;
    } while (intense[0] < 0x100);
}

void __cdecl RGE_fade_palette(TDrawArea* draw_area, tagPALETTEENTRY fade_color,
                              float fade_time, unsigned char fade_type,
                              tagPALETTEENTRY* palette, int first, int last)
{
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

    if (palette == 0) {
        draw_area->GetPalette(palette1);
    } else {
        tagPALETTEENTRY* target = palette1;
        tagPALETTEENTRY* source = palette;
        for (int j = 0; j < 256; j++) {
            target->peRed = source->peRed;
            target->peBlue = source->peBlue;
            target->peGreen = source->peGreen;
            target->peFlags = source->peFlags;
            ++target;
            ++source;
        }
    }

    old_time = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp, 0x69);
    fade_time2 = fade_time * fade_time;

    if (fade_type == 1) {
        do {
            long pct;
            long cur_time = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp, 0x70);
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
            RGE_translate_palette(palette1, palette2, fade_color, pct, first, last);
            draw_area->SetPalette(palette2);
        } while (!done);
    } else {
        do {
            long pct;
            long cur_time = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp, 0x88);
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
            RGE_translate_palette(palette1, palette2, fade_color, pct, first, last);
            draw_area->SetPalette(palette2);
        } while (!done);
    }
}

RGE_Color_Table::RGE_Color_Table(int fd)
{
    struct ColorFileScratch {
        char prefix[2];
        short temp_color;
        char tempname[300];
    } scratch;

    rge_read(fd, this->color_table_name, 0x1E);
    rge_read(fd, &this->id, 2);
    rge_read(fd, &this->resource_id, 2);
    rge_read(fd, &this->map_color, 1);
    rge_read(fd, &this->type, 1);

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

RGE_Color_Table::RGE_Color_Table(FILE* file, short id_val)
{
    char* file_name = 0;
    this->id = id_val;
    memset(this->table, 0, 256);

    fscanf(file, "%hd %s %hd %hd", &this->resource_id, this->color_table_name,
           &id_val, &file);
    this->map_color = (unsigned char)id_val;
    this->type = (unsigned char)file;
    addstring(&file_name, this->color_table_name, ".col");
    strcpy(this->color_table_name, file_name);
    if (file_name != 0) {
        free(file_name);
    }
}

RGE_Color_Table::RGE_Color_Table(char* name)
{
    short temp_color;
    char tempname[300];

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, 256);
    strcpy(this->color_table_name, name);
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

RGE_Color_Table::RGE_Color_Table(TDrawArea* area, long amount,
                                 tagPALETTEENTRY* base_color,
                                 tagPALETTEENTRY* palette_source)
{
    long temp_color;
    tagPALETTEENTRY palette[256];
    tagPALETTEENTRY temp_palette[256];
    tagPALETTEENTRY color;
    long index;

    if (palette_source == 0) {
        area->GetPalette(palette);
    } else {
        for (int i = 0; i < 256; i++) {
            palette[i].peRed = palette_source[i].peRed;
            palette[i].peGreen = palette_source[i].peGreen;
            palette[i].peBlue = palette_source[i].peBlue;
            palette[i].peFlags = palette_source[i].peFlags;
        }
    }

    if (base_color == 0) {
        color.peRed = 0;
        color.peBlue = 0;
        color.peGreen = 0;
        color.peFlags = 0;
    } else {
        color.peRed = base_color->peRed;
        color.peBlue = base_color->peBlue;
        color.peGreen = base_color->peGreen;
        color.peFlags = base_color->peFlags;
    }

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, 256);

    RGE_translate_palette(palette, temp_palette, color, amount, -1, -1);

    index = 0;
    do {
        temp_color = 0;
        int i = 0;
        int best_distance = 20000;
        int red = temp_palette[index].peRed;
        int green = temp_palette[index].peGreen;
        int blue = temp_palette[index].peBlue;

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

        this->table[index] = (unsigned char)temp_color;
        index++;
    } while (index <= 0xff);
}

RGE_Color_Table::~RGE_Color_Table()
{
}

void RGE_Color_Table::save(int param1)
{
    rge_write(param1, this->color_table_name, 0x1E);
    rge_write(param1, &this->id, 2);
    rge_write(param1, &this->resource_id, 2);
    rge_write(param1, &this->map_color, 1);
    rge_write(param1, &this->type, 1);
}
