// 00543770 RGE_Game_World::save_game
// PDB: World.cpp:2072-2104, 212 bytes
// __thiscall, returns unsigned char, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1: 31.6% - first diff at +90, jne instead of je for fd==-1 check
//   VC5 inverts block order: puts fail path as fall-through
// probe 2: if(fd!=-1){body}return0 -> MATCH (0.0000%)
//   Key: `if (fd != -1)` makes VC5 put the common continue path as
//   fall-through, matching the original's `je short fail_path` pattern.
//   With `if (fd == -1) return 0;`, VC5 puts the fail path as fall-through
//   (inverted block order) with `jne` to the continue path.

#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::save_game(char* name) {
    char tempname[300];

    save_game_version = 7.23f;
    sprintf(tempname, "%s%s", rge_base_game->save_prog_info->save_dir, name);
    int fd = rge_open(tempname, 0x8309, 0x180);
    if (fd != -1) {
        rge_write_error = 0;
        rge_write(fd, "VER 8.6", 8);
        rge_write(fd, &save_game_version, 4);

        this->save(fd);

        rge_close(fd);

        if (rge_write_error != 0) {
            _unlink(tempname);
            return 0;
        }
        return 1;
    }
    return 0;
}
