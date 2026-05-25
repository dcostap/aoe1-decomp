// 00424440 RGE_Color_Table::RGE_Color_Table(FILE*, short)
// Source: color.cpp lines 191-209
// Retry 2026-05-21: replaced placeholder with full behavior: id, zero table, fscanf("%hd %s %hd %hd"), map/type from stack slots, addstring .col, strcpy back, free. Baseline full behavior is exact-size 169B and 61.5385% positional; moving file_name=0 after fscanf improved to 17.7515% positional / 13.6095% edit (kept) but differs from original's pre-fscanf zero store. Tried volatile/comma first-arg initialization, volatile file_name, raw zero store, no init, zero before addstring, hardcoded format/ext addresses, manual strcpy, manual table zero loop, file/name locals, and map/type/zero reorderings. None recovered the original schedule: file_name=0 after all fscanf pushes but before call, followed by map/type stores before addstring. Leaving in scratch; no accepted_drift because remaining diff changes call/setup scheduling and store order around fscanf/addstring, not a localized benign hunk.
// Retry 2026-05-24 Boss pass: MATCH. Key fix was declaring `char* file_name = 0;` at local declaration and removing the later explicit `file_name = 0;`. VC5 schedules that initializer into the original slot after all fscanf arguments are pushed but before the call; spelling the assignment as a separate statement after fscanf kept it too late, while a separate statement before fscanf stayed in the older 61.54% family.

#include "..\..\include\game_globals.h"
#include <stdio.h>
#include <string.h>

extern "C" void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" void __cdecl free(void* ptr);

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

RGE_Color_Table::RGE_Color_Table(FILE* file, short id_val)
{
    char* file_name = 0;
    this->id = id_val;
    memset(this->table, 0, 256);

    fscanf(file, "%hd %s %hd %hd", &this->resource_id, this->color_table_name, &id_val, &file);
    this->map_color = (unsigned char)id_val;
    this->type = (unsigned char)file;
    addstring(&file_name, this->color_table_name, ".col");
    strcpy(this->color_table_name, file_name);
    if (file_name != 0) {
        free(file_name);
    }
}
