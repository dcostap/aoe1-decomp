// 004244F0 RGE_Color_Table::RGE_Color_Table(char*)
// Source: color.cpp lines 214-232
// Size: 243 bytes
//
// Attempt log:
// Probe 1: incomplete natural C++ scaffold (missing filename construction/file loop).
// Baseline check: 65-byte body with no external calls; structural reconstruction required.
// Probe 2: restored the binary-backed resource initialization, `.col` append,
// data-path formatting, and 256-entry fscanf/fclose loop; exact 243-byte match.

#include "..\..\include\game_globals.h"
#include <stdio.h>
#include <string.h>

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
