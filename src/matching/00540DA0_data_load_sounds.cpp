// 00540DA0 RGE_Game_World::data_load_sounds (World.cpp:393-418, 257 bytes)
// EH-framed (SEH from /GX + new expression + CRT calls).
// FLAGS: /nologo /c /O2 /Oy /GX
// PDB-qualified owner/name: public virtual unsigned char __thiscall
// RGE_Game_World::data_load_sounds(char*).
// BINARY NOTE: The body is 00540DA0-00540EA0, after set_map_fog at
// 00540D80-00540D93. The reviewed world layout keeps map at +0x28,
// sound_num at +0x2C, and sounds at +0x30.
// BINARY NOTE: Keep the short locals, null guards, direct calls, publication,
// and failure order. The source emits the original frame and stack cleanup.

#include <stdio.h>
#include <stdlib.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::data_load_sounds(char* name) {
    FILE* fp = fopen(name, "r");
    if (fp != 0) {
        short count;
        short i;
        short index;
        int result;
        result = fscanf(fp, "%hd %hd", &this->sound_num, &count);
        if (result != -1) {
            this->sounds = (RGE_Sound**)calloc(this->sound_num, 4);
            for (i = 0; i < count; i++) {
                if (fscanf(fp, "%hd", &index) != -1) {
                    RGE_Sound* s = new RGE_Sound(fp, index);
                    this->sounds[index] = s;
                }
            }
        } else {
            this->sound_num = 0;
            this->sounds = 0;
        }
        fclose(fp);
    }
    return 1;
}
