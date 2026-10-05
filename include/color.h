#ifndef AOE1_COLOR_H
#define AOE1_COLOR_H

// Compiler-facing declarations for the complete color.cpp source module.

#include <windows.h>

struct _iobuf;
typedef struct _iobuf FILE;

class TDrawArea;

// ASM owner: bucket_056C.asm. The routine updates the process color transform.

class RGE_Color_Table {
  public:
    virtual ~RGE_Color_Table();

    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];

    RGE_Color_Table(int infile);
    RGE_Color_Table(FILE* infile, short id_val);
    RGE_Color_Table(char* filename);
    RGE_Color_Table(TDrawArea* surface, long amount, tagPALETTEENTRY* in_color, tagPALETTEENTRY* palette1);
    void save(int outfile);
};

typedef char color_table_size_check[(sizeof(RGE_Color_Table) == 0x128) ? 1 : -1];

void __cdecl color_log(unsigned char c1, unsigned char c2, int pos);

#endif // AOE1_COLOR_H
