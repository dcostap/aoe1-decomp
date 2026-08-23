// VA: 005410E0 RGE_Game_World::data_load_sprites
// Attempt log:
// - Baseline used raw string-address macros, hand-declared stdio calls, and a
//   member for the file count; it had the right calls but the wrong frame and
//   stack layout.
// - Reconstructing the same-TU typed stdio/stdlib surface and a local short
//   file count follows the exact data_load_sounds donor.  The original also
//   proves that the world field at +0x30 is the sprite constructor's sound
//   table and that sprite_num is at +0x34.
// BINARY NOTE: The sprite array is published at +0x38. Keep the fopen guard,
// fscanf guards, short loop locals, allocation order, fallback loop, and
// fclose cleanup. These preserve the original fault order.
// CONTEXT NOTE: PDB lines 493-520 belong to World.cpp. The real grouped
// source includes this owner after 00540EB0 and 00540FD0. With /GX, the
// grouped object has the original owner, 348 bytes, 9 calls, and all bytes
// match after relocation normalization. 00540FD0 is not an exact anchor.
// EXACT-FINISH: Removing the result temporary kept the isolated and grouped
// matches. The former private class surface had the wrong owner and call ABI.

#include <stdio.h>
#include <stdlib.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::data_load_sprites(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != 0) {
        short file_sprite_count;
        short i;
        short id;

        if (fscanf(file, "%hd %hd", &this->sprite_num, &file_sprite_count) != -1) {
            this->sprites = (RGE_Sprite**)calloc(this->sprite_num, 4);

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
            this->sprite_num = 0;
            this->sprites = 0;
        }
        fclose(file);
    }
    return 1;
}
