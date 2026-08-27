// PDB source module: C:\\msdev\\work\\age1_x1\\basegame.cpp.
//
// P0 prefix only.  These owners follow the original PDB source-line order.
// 0041E7A0 is the next source owner, but its ABI is not closed by basegame.h.
// 0041B6A0 then needs the complete RGE_Prog_Info source type.

#include <windows.h>
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <string.h>

#include "../include/basegame.h"

extern FILE* draw_log;
extern char draw_log_name[260];

// 0041B620 write_draw_log, basegame.cpp:199-205 (44 bytes).
void __cdecl write_draw_log(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fflush(draw_log);
    }
}

// 0041B650 write_draw_log2, basegame.cpp:208-215 (67 bytes).
void __cdecl write_draw_log2(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}
