// VA: 00540FD0, RGE_Game_World::data_load_color_tables, 264 bytes
// Source: World.cpp lines 464-489.
// PDB-qualified owner/name: protected virtual unsigned char __thiscall
// RGE_Game_World::data_load_color_tables(char*).
// BINARY NOTE: The body boundary is 00540FD0-005410D8. The next PDB sibling
// starts at 005410E0, with padding between the symbols.
// BINARY NOTE: The shared World surface keeps map at +0x28, color_table_num at
// +0x60, and color_tables at +0x64. Do not replace the protected ABI or header.
// BINARY NOTE: The positive fscanf-success arm, short loop index, null guards,
// publication order, cleanup, and fault order produce the exact body.
// EXACT-FINISH: The short loop index is required for the original 16-bit
// comparison. The positive success arm is required for the original branch.
// Walkback of either change is nonexact.
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stdlib.h>
#include <stdio.h>
#include "../../include/world_scenario_context.h"

uchar RGE_Game_World::data_load_color_tables(char* filename)
{
    short count;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        goto epilogue;

    if (fscanf(f, "%hd %hd", &this->color_table_num, &count) != -1) {
        this->color_tables = (RGE_Color_Table**)calloc(this->color_table_num, 4);
        for (short i = 0; i < count; i++) {
            short index;
            if (fscanf(f, "%hd", &index) != -1) {
                RGE_Color_Table* ct = new RGE_Color_Table(f, index);
                this->color_tables[index] = ct;
            }
        }
    } else {
        this->color_table_num = 0;
        this->color_tables = NULL;
    }

    fclose(f);

epilogue:
    return 1;
}
