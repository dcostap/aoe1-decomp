// 00424350 RGE_Color_Table::RGE_Color_Table(int fd)
// Source: color.cpp lines 162-186
// Size: 203 bytes
//
// Attempt log:
// Probe 1: 203/203B, 33% diff — codegen basin (stack size, sprintf args)

#include "..\..\include\game_globals.h"
#include <stdio.h>

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table() {}
    char color_table_name[30];   // +0x04
    short resource_id;           // +0x22
    unsigned char type;          // +0x24
    unsigned char map_color;     // +0x25
    short id;                    // +0x26
    unsigned char table[256];    // +0x28

    RGE_Color_Table(int fd);
};

extern int __cdecl rge_read(int fd, void* buf, int size);

RGE_Color_Table::RGE_Color_Table(int fd)
{
    rge_read(fd, this->color_table_name, 0x1E);
    rge_read(fd, &this->id, 2);
    rge_read(fd, &this->resource_id, 2);
    rge_read(fd, &this->map_color, 1);
    rge_read(fd, &this->type, 1);

    char filename[256];
    sprintf(filename, "%s\\%s", this->color_table_name, ".pal");

    FILE* fp = fopen(filename, "rb");
    if (fp) {
        short val;
        for (int i = 0; i < 256; i++) {
            fscanf(fp, "%hd", &val);
            this->table[i] = (unsigned char)val;
        }
        fclose(fp);
    }
}
