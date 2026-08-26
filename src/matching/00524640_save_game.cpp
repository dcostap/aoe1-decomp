// VA: 00524640 TRIBE_Game::save_game (332 B)
// PDB source: tribegam.cpp:1909-1959
//
// Attempt log:
// - Initial scaffold was incomplete (free-function/raw-offset calls and an
//   omitted world save/copy/panel path).
// - Baseline reconstruction below uses the proven TRIBE_Game/base-game/world
//   ownership, the slot-0xD8 TRIBE_World::save_game surface, the 260-byte
//   filename buffer, and the natural strcpy/strchr path from the packet.
// - Main-agent audit confirmed canonical game/world/panel ownership and natural
//   save flow; exact bytes were revalidated after promotion.

extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" char* __cdecl strchr(const char* source, int character);

extern int ENABLE_COMPRESSION; // 00585A6C

#ifndef TRIBEGAM_TU_CONTEXT
#include "../tribegam_context_local.h"
#define TRIBEGAM_TU_CONTEXT 1
#endif

int TRIBE_Game::save_game(char* filename)
{
    if (this->prog_mode != SaveModeA && this->prog_mode != SaveModeB &&
        this->prog_mode != SaveModeC && this->prog_mode != SaveModeD) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x453, 0, -1);

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0) {
        ENABLE_COMPRESSION = 0;
    }

    int result = this->world->save_game(filename);
    ENABLE_COMPRESSION = 1;
    if (result == 0) {
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    char fileNameNoExt[260];
    strcpy(fileNameNoExt, filename);
    char* extension = strchr(fileNameNoExt, '.');
    if (extension != 0) {
        *extension = 0;
    }
    this->set_save_game_name(fileNameNoExt);

    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    panel_system.setCurrentPanel((char*)"Game Screen", 0);
    panel_system.destroyPanel((char*)"Save Game Screen");
    panel_system.destroyPanel((char*)"Status Screen");
    this->enable_input();
    return 1;
}
