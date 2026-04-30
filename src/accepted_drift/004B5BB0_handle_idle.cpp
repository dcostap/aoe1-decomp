// TribeGameSettingsScreen::handle_idle
// VA: 004B5BB0, scr_set.cpp:554-582
// Status: PARKED in scratch - 1-byte VC5 branch target drift
//
// Attempt log:
// v0: Basic member function struct layout → 2 bytes diff (1.09%)
//      - jne offset: 0x0b vs 0x05 (mov ecx reload placement)
//      - sub vs cmp (timeGetTime compare)
// v1: Sub instead of cmp via (cur_time - last_send_shared) != 0 → 1 byte diff
// v2: Comma expression, dummy if, etc. → no effect on jne target
// v3: Local pointer scope block → extra push edi (64% regression)
//
// Remaining diff: 1 byte at offset 0x47
//   Original: 75 0b (jne past call + reload = 11 bytes)
//   Rebuilt:  75 05 (jne past call only = 5 bytes, reload outside block)
// The `mov ecx, [62C574h]` reload is placed INSIDE the if-true block in
// the original but OUTSIDE in the rebuilt. VC5 optimization difference -
// cannot force reload position from C++ source without extra register
// allocation.
//
// Everything else (182 of 183 bytes) matches exactly including:
//   - Prologue: push esi, mov esi, ecx
//   - All field accesses ([esi+504h], [esi+4F0h], [esi+55Ch])
//   - All call sites (fillScenarios, fillMissionText, activatePanels,
//     set_curr_child, enable_input, multiplayerGame, debug_timeGetTime,
//     SendSharedData, TPanel::handle_idle)
//   - Sub eax, ecx for time comparison
//   - Ret clean epilogue

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

struct TCommunications_Handler {
    char gap_00[0x0FC5];
    char TBuff[257];
    char gap_10C6[0x20E];
    int CommunicationsStatus;

    long SendSharedData(int a1);
};

struct RGE_Base_Game {
    char gap_00[0x1D8];
    int input_enabled;

    void enable_input();
    int multiplayerGame();
};

struct TPanel {
    char gap_00[0x4F0];

    long handle_idle();
    void set_curr_child(void* child);
};

struct TribeGameSettingsScreen : TPanel {
    void* scenarioList;              // +0x4F0
    char gap_4F4[0x10];
    int scenariosLoaded;             // +0x504
    char gap_508[0x54];
    unsigned long last_send_shared;  // +0x55C
    // total size: 0x560

    void fillScenarios();
    void fillMissionText();
    void activatePanels();
    long handle_idle();
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define comm (*(TCommunications_Handler**)0x62C4C0)

long TribeGameSettingsScreen::handle_idle() {
    if (scenariosLoaded == 0) {
        fillScenarios();
        fillMissionText();
        scenariosLoaded = 1;
        activatePanels();
        set_curr_child(scenarioList);
    }

    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }

    if (rge_base_game->multiplayerGame() != 0) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 0x23A);
        } else {
            unsigned long cur_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 0x23D);
            if ((cur_time - last_send_shared) != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 0x240);
            }
        }
    }

    return TPanel::handle_idle();
}
