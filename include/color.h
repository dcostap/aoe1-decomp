#ifndef AOE1_COLOR_H
#define AOE1_COLOR_H

// Compiler-facing declarations for the complete color.cpp source module.
// The source file keeps its handwritten owners in PDB order.

#include <windows.h>

struct _iobuf;
typedef struct _iobuf FILE;

class TDrawArea;

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();

    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];

    RGE_Color_Table(int fd);
    RGE_Color_Table(FILE* file, short id_val);
    RGE_Color_Table(char* name);
    RGE_Color_Table(TDrawArea* area, long amount,
                    tagPALETTEENTRY* base_color,
                    tagPALETTEENTRY* palette);
    void save(int param1);
};

typedef char color_table_size_check[(sizeof(RGE_Color_Table) == 0x128) ? 1 : -1];

void __cdecl color_log(unsigned char, unsigned char, int);

#endif  // AOE1_COLOR_H
