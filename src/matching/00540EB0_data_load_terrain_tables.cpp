// 00540EB0 RGE_Game_World::data_load_terrain_tables
// World.cpp:422-460, 282 bytes
// Attempt log:
// - baseline decompiler-shaped locals had a 0xC frame and four saved registers.
// - positive file guard with direct terrain members restored the 0x8 frame and conditional saves.
// - positive fscanf-success arm plus a short outer counter reproduced the original branch layout and exact bytes.
// - typed stdio/stdlib declarations were retained; emitted code stayed exact.
// - Main-agent audit restored canonical world polymorphic ownership; emitted
//   code remains exact.

#include <stdio.h>
#include <stdlib.h>

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char _gap_04[0x4C];
    short terrain_num;
    short terrain_size;
    float** terrains;

    unsigned char data_load_terrain_tables(char* filename);
};

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
