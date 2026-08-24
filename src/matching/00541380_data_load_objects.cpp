// 00541380 RGE_Game_World::data_load_objects (World.cpp:568-601, 279B)
// Loads object data from file for all master players.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Baseline continue-heavy for loops had the right calls/fields but entry-saved EBX/EBP and 12B of overflow.
// - Positive do/while guards removed the duplicate inner count test and restored size/CFG parity.
// - Binding the outer counter's zeroing to the successful player-count fscanf, then restoring the positive fp guard,
//   reproduced the original staged EBP/EBX saves and shared fclose/return epilogue.
// - The binary's inner fscanf LEAs prove the first parsed value is the load_object v2 argument and the second is v1;
//   source therefore passes &v2, &v1 to the varargs call to preserve both behavior and VC5 right-to-left scheduling.
// - Exact with default flags: 279B, 9 calls, slots 3/4, fields +0x30/+0x38/+0x48, 0-byte diff.
// - The parameter-home cast is intentional: fscanf writes the incoming filename slot as the short player index, as proved by the original stack accesses.
// - Main-agent audit replaced empty inline virtual bodies and the raw world vptr
//   with canonical declarations; emitted code remains exact.

#include "../../include/world_context.h"

unsigned char RGE_Game_World::data_load_objects(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp != 0) {
        short player_count;
        short object_id;
        short player_idx;
        if (fscanf(fp, "%hd", &player_count) != -1 && (player_idx = 0, player_count > 0)) {
            do {
                if (fscanf(fp, "%hd", (short*)&filename) != -1) {
                    fscanf(fp, "%hd", &object_id);
                    master_players[*(short*)&filename]->create_master_object_space(object_id);

                    fscanf(fp, "%hd", &object_id);
                    short j = 0;
                    if (j < object_id) {
                        short v1, v2;
                        do {
                            if (fscanf(fp, "%hd %hd", &v2, &v1) != -1) {
                                master_players[*(short*)&filename]->load_object(fp, v2, sprites, sounds, v1);
                            }
                            ++j;
                        } while (j < object_id);
                    }
                }
                ++player_idx;
            } while (player_idx < player_count);
        }

        fclose(fp);
    }
    return 1;
}
