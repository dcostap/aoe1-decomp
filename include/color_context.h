#ifndef AOE1_COLOR_CONTEXT_H
#define AOE1_COLOR_CONTEXT_H

// Shared declarations for the authentic color.cpp owner order.
// COLOR_TU_CONTEXT is defined only by src/color_tu.cpp.

#ifdef COLOR_TU_CONTEXT

#include <windows.h>

struct _iobuf;
typedef struct _iobuf FILE;

class TDrawSystem;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void GetPalette(tagPALETTEENTRY* entries);
    void SetPalette(tagPALETTEENTRY* entries);
};

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

#endif  // COLOR_TU_CONTEXT
#endif  // AOE1_COLOR_CONTEXT_H
