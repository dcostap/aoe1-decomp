#include <windows.h>

#include "../../include/tribegam_context.h"

#if 0
class RGE_Base_Game {
public:
    void* player_game_info;      // +0x04
    void* scenario_info;         // +0x08
    void* prog_info;             // +0x0C
    void* prog_window;           // +0x10
    int prog_ready;              // +0x14
    int prog_active;             // +0x18
    void* prog_palette;          // +0x1C

    virtual int setup_palette();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual int setup_palette();
};
#endif

int TRIBE_Game::setup_palette() {
    if (!RGE_Base_Game::setup_palette()) {
        return 0;
    }

    {
        PALETTEENTRY pal_entries[7] = {
            { 0x17, 0x27, 0x7C, 0x00 },
            { 0x27, 0x3F, 0x90, 0x00 },
            { 0x3F, 0x5F, 0x9F, 0x00 },
            { 0x57, 0x7B, 0xB4, 0x00 },
            { 0x3F, 0x5F, 0xA0, 0x00 },
            { 0x27, 0x3F, 0x91, 0x00 },
            { 0x17, 0x27, 0x7B, 0x00 }
        };

        SetPaletteEntries(prog_palette, 0xF8, 7, pal_entries);
    }
    return 1;
}
