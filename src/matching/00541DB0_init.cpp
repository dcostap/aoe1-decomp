// 00541DB0 RGE_Game_World::init
// PDB: World.cpp:871-896, 190 bytes
// Virtual slot: vt[44] (0xB0)
// FLAGS: default
//
// Exact match: the natural outer `fd != -1` guard with an inner mismatch-first
// version guard reproduces the original block order and epilogues.
// Positional diff: 0/190 (0.0%), Edit diff: 0 (0.0%)
// Relocs masked: 5
//
// Attempt log:
// prior probes 1-16: direct fd-failure forms, comparison-direction forms,
// explicit fail labels, and a focused variant lab left two codegen groups;
// the best success-first form was 55 positional bytes away in this TU.
// current probe: put the read/version logic inside `if (fd != -1)` and use
// `if (strcmp(...) != 0)` for the close/false arm; exact 190-byte match.

#include <string.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    char version[8];

    this->sound_driver = param_2;
    this->next_object_id = 0;

    int fd = rge_open(param_1, 0x8000);
    if (fd != -1) {
        rge_read(fd, version, 8);

        if (strcmp(version, "VER 3.7") != 0) {
            rge_close(fd);
            return 0;
        }

        this->world_init(fd, param_2, param_3);
        rge_close(fd);
        return 1;
    }

    return 0;
}
