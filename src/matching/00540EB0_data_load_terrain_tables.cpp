// 00540EB0 RGE_Game_World::data_load_terrain_tables
// World.cpp:422-460, 282 bytes
// PDB-qualified owner/name: protected virtual unsigned char __thiscall
// RGE_Game_World::data_load_terrain_tables(char*).
// BINARY NOTE: The body is 00540EB0-00540FC9. It follows the exact
// data_load_sounds body at 00540DA0-00540EA0 and ends before padding and
// data_load_color_tables at 00540FD0.
// BINARY NOTE: The reviewed world layout keeps map at +0x28, sound_num at
// +0x2C, sounds at +0x30, terrain_num at +0x50, terrain_size at +0x52, and
// terrains at +0x54. Keep the direct fields and their publication order.
// Attempt log:
// - baseline decompiler-shaped locals had a 0xC frame and four saved registers.
// - positive file guard with direct terrain members restored the 0x8 frame and conditional saves.
// - positive fscanf-success arm plus a short outer counter reproduced the original branch layout and exact bytes.
// - typed stdio/stdlib declarations were retained; emitted code stayed exact.
// - Main-agent audit restored canonical world polymorphic ownership; emitted
//   code remains exact.
// - Exact-finish audit retained short locals, null guards, ordered fscanf/calloc
//   calls, direct publication, fclose cleanup, and the original fault order.

#include <stdio.h>
#include <stdlib.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::data_load_terrain_tables(char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f != 0) {
        if (fscanf(f, "%hd %hd", &this->terrain_num, &this->terrain_size) != -1) {
            this->terrains = (float**)calloc(this->terrain_num, 4);

            short outer = 0;
            if (outer < this->terrain_num) {
                do {
                    short type;
                    short index;

                    if (fscanf(f, "%hd %hd", &type, &index) != -1) {
                        this->terrains[type] = (float*)calloc(this->terrain_size, 4);

                        short si = 0;
                        if (si < index) {
                            do {
                                short local_6;
                                fscanf(f, "%hd", &local_6);
                                fscanf(f, "%f", &this->terrains[type][local_6]);
                                ++si;
                            } while (si < index);
                        }
                    }

                    ++outer;
                } while (outer < this->terrain_num);
            }
        } else {
            this->terrain_num = 0;
            this->terrains = 0;
        }

        fclose(f);
    }
    return 1;
}
