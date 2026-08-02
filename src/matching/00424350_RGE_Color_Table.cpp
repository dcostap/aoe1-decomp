// 00424350 RGE_Color_Table::RGE_Color_Table(int fd)
// Source: color.cpp lines 162-186
// Size: 203 bytes
//
// Attempt log:
// Baseline: period-plausible color.cpp constructor with the binary-proven
// fields, 300-byte filename workspace, and short fscanf temporary; exact size,
// calls, and loop body, but tempname addresses were 4 bytes late (2-byte diff).
// Tried local declaration order, scoped temp_color, a 304-byte buffer, a
// short* alias, top-level FILE* declaration, and a nested filename scope;
// none changed the 2-byte stack-address drift. A binary-proven local overlay
// (prefix[2], temp_color, tempname[300]) reproduces the original compiler's
// reused stack window exactly; retain it as the minimal exact local frame model.

#include "..\..\include\game_globals.h"
#include <stdio.h>

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];   // +0x04
    short resource_id;           // +0x22
    unsigned char type;          // +0x24
    unsigned char map_color;     // +0x25
    short id;                    // +0x26
    unsigned char table[256];    // +0x28

    RGE_Color_Table(int fd);
};

extern void __cdecl rge_read(int fd, void* buf, int size);

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
