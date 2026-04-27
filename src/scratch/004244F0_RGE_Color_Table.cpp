// 004244F0 RGE_Color_Table::RGE_Color_Table(char*)
// Source: color.cpp lines 214-232
// Size: 243 bytes
//
// Attempt log:
// Probe 1: natural C++

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

    RGE_Color_Table(char* name);
};

RGE_Color_Table::RGE_Color_Table(char* name)
{
    memset(this->table, 0, 256);
    strcpy(this->color_table_name, name);
}
