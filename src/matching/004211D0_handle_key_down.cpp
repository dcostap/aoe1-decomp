// VA: 004211D0 RGE_Base_Game::handle_key_down (268 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline used a free-function shim and local globals; it had the wrong
//   __thiscall prologue and helper/call surfaces (90.7143% positional diff).
// - Reconstructed the period RGE_Base_Game member layout, imported GetKeyState
//   pointer, TDrawArea::take_snapshot(char*, int&), and action_key_down slot.
// - A local GetKeyState pointer alias after the readiness guard reproduces the
//   original one-time IAT load into ESI and three calls through that pointer.
// - Main-agent audit restored the canonical base-game destructor slot while
//   preserving the proven +0xC4/+0x100 virtual positions; output remains exact.

extern int snapshot_number;

extern unsigned int DAT_005b2164;
extern unsigned int DAT_005b2368;
extern unsigned int DAT_005b2370;
extern unsigned int DAT_0062c4b4;
extern unsigned int DAT_0062c4bc;







int RGE_Base_Game::handle_key_down(void* param_1, unsigned int param_2,
                                   unsigned int param_3, long param_4)
{
    if (this->prog_ready == 0) {
        return 1;
    }

    short (__stdcall *get_key_state)(int) = GetKeyState;

    DAT_005b2368 = param_3;
    DAT_005b2370 = param_4 & 0xFFFF;
    DAT_0062c4bc = (get_key_state(0x11) < 0);
    DAT_0062c4b4 = (get_key_state(0x12) < 0);
    DAT_005b2164 = (get_key_state(0x10) < 0);

    if (param_1 == this->prog_window && param_2 == 0x104 &&
        (DAT_005b2368 == 0x12 || DAT_005b2368 == 0x20 ||
         DAT_005b2368 == 0x79) &&
        this->prog_info->full_screen != 0 &&
        IsIconic(this->prog_window) == 0) {
        return 0;
    }

    if (DAT_0062c4bc != 0 && DAT_005b2368 == 0x7B) {
        this->draw_system->DrawArea->take_snapshot(
            ".\\AoE%04d.bmp", snapshot_number);
        return 0;
    }

    return this->action_key_down(DAT_005b2368, DAT_005b2370,
                                 DAT_0062c4bc, DAT_0062c4b4,
                                 DAT_005b2164) != 0;
}
