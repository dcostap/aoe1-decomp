// 00540DA0 RGE_Game_World::data_load_sounds (World.cpp:393-418, 257 bytes)
// EH-framed (SEH from /GX + new expression + CRT calls).
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stdio.h>
#include <stdlib.h>

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    void* sounds;                // +0x04
    unsigned long cache_time;    // +0x08
    short id;                    // +0x0C

    RGE_Sound(FILE* fp, short id);
};

class RGE_Game_World {
public:
    /* +0x00 */ void* vtable;
    char gap_04[0x28];
    /* +0x2C */ short sound_num;
    char gap_2E[2];
    /* +0x30 */ RGE_Sound** sounds;

    unsigned char data_load_sounds(char* name);
};

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
