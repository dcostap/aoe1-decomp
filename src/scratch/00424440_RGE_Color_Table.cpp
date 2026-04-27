// 00424440 RGE_Color_Table::RGE_Color_Table(FILE*, short)
// Source: color.cpp lines 191-209
// Size: 169 bytes
//
// Attempt log:
// Probe 1: 112/169B — structural probe, too short (more complex fscanf + string copy logic)

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

    RGE_Color_Table(FILE* file, short id_val);
};

extern int __cdecl rge_read(int fd, void* buf, int size);

RGE_Color_Table::RGE_Color_Table(FILE* file, short id_val)
{
    this->id = id_val;
    memset(this->table, 0, 256);

    fscanf(file, "%hd %hd %s", &this->resource_id, &this->id, this->color_table_name);
    this->map_color = 2;
    this->type = 1;
}
