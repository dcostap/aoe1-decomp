// VA: 005410E0 RGE_Game_World::data_load_sprites
// Attempt log:
// - Baseline used raw string-address macros, hand-declared stdio calls, and a
//   member for the file count; it had the right calls but the wrong frame and
//   stack layout.
// - Reconstructing the same-TU typed stdio/stdlib surface and a local short
//   file count follows the exact data_load_sounds donor.  The original also
//   proves that the world field at +0x30 is the sprite constructor's sound
//   table and that sprite_count is at +0x34.

#include <stdio.h>
#include <stdlib.h>

struct RGE_Sound;

class RGE_Sprite {
public:
    virtual ~RGE_Sprite();
    char gap_04[0x74];
    RGE_Sprite(FILE* file, short id, RGE_Sound** sounds);
    RGE_Sprite(short id);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x2C];
    RGE_Sound** sounds;
    short sprite_count;
    char gap_36[2];
    RGE_Sprite** sprites;

    unsigned char data_load_sprites(char* filename);
};

unsigned char RGE_Game_World::data_load_sprites(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != 0) {
        short file_sprite_count;
        short i;
        short id;
        int result;

        result = fscanf(file, "%hd %hd", &this->sprite_count, &file_sprite_count);
        if (result != -1) {
            this->sprites = (RGE_Sprite**)calloc(this->sprite_count, 4);

            for (i = 0; i < file_sprite_count; i++) {
                if (fscanf(file, "%hd", &id) != -1) {
                    RGE_Sprite* sprite = new RGE_Sprite(file, id, this->sounds);
                    this->sprites[id] = sprite;
                }
            }

            for (i = 0; i < file_sprite_count; i++) {
                if (this->sprites[i] == 0) {
                    RGE_Sprite* sprite = new RGE_Sprite(i);
                    this->sprites[i] = sprite;
                }
            }
        } else {
            this->sprite_count = 0;
            this->sprites = 0;
        }
        fclose(file);
    }
    return 1;
}
