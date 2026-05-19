// 00545B30 RGE_Game_World::selectNextComputerPlayer
// Source: World.cpp lines 3460-3487. 143 bytes. __thiscall, ret 4.
//
// Parked after 8 probes. Best result: 52% positional diff.
// Core issues:
// 1) push ecx at prologue — VC5 needs stack slot for `this` because EBP/EDI
//    get reused for players/counter in second loop (register pressure with 4
//    callee-save regs vs 5 needed locals). Original keeps `this` in EBP
//    throughout and current in scratch ECX.
// 2) First loop: `while(1)` + `if (i>=n) break;` generates `jge; jmp` back-edge
//    instead of original's clean `jl` back-edge when written as `for(...; i<n; ...)`.
// 3) Member offsets confirmed: currentUpdateComputerPlayer @ +0xFC, player_num @ +0x3C
//    (signed word, movsx), players @ +0x40, RGE_Player::type @ +0x48.
// Retry 2026-05-19/20 assigned pass:
// - Revalidated current source: 143/143, MISMATCH, 83.9161% positional / 62.9371% edit; first byte differs due extra `push ecx`/this home.
// - Removed `(unsigned char)` param casts: first loop moved closer to original dword-param compare via zero-extended type, but overall worsened to 96.5035% and kept this home; rolled back.
// - Changed `players` to typed `RGE_Player**`: no codegen change from the no-cast form; rolled back.
// - Tested reloading `currentUpdateComputerPlayer` in the else path instead of preserving a `current` local: no codegen improvement; rolled back.
// - /Og flag probe: no improvement; removed.
// Boss retry 2026-05-19:
// - Forward-declared typed RGE_Player** players and volatile indexed access: removed some byte-temp
//   widening but kept this-home/prologue; 83.2168% positional.
// - Added currentPtr store alias: no codegen change from typed/volatile form.
// - Rewrote first loop as do/while and second loop with explicit start<n outer guard: removed the
//   this-home prologue and improved to 55/143 positional (38.4615%), first mismatch +7, but current
//   lives in EBX not original ECX and first loop got duplicated compare body / different exit.
// - `register int current` did not move current to ECX. Kept improved no-this-home source.
// GIVEUP: no accepted_drift. Remaining mismatch is broad register allocation and loop-topology drift, not localized benign equivalence.

class RGE_Player;

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;                // +0x3C (signed word)
    char gap_3E[0x40 - 0x3E];
    RGE_Player** players;            // +0x40
    char gap_44[0xFC - 0x44];
    int currentUpdateComputerPlayer; // +0xFC

    void selectNextComputerPlayer(int param_1);
};

class RGE_Player {
public:
    char gap_00[0x48];
    unsigned char type;              // +0x48
};

void RGE_Game_World::selectNextComputerPlayer(int param_1) {
    register int current = this->currentUpdateComputerPlayer;
    if (current == -1) {
        int n = this->player_num;
        int i = 0;
        if (i < n) {
            RGE_Player** ptr = this->players;
            do {
                if ((*ptr)->type == param_1) {
                    this->currentUpdateComputerPlayer = i;
                    return;
                }
                ++i;
                ++ptr;
            } while (i < n);
        }
        return;
    }

    int n = this->player_num;
    int start = current;
    int counter = 0;
    if (start >= n) return;
    while (start < n) {
        if (counter >= n) return;
        RGE_Player* pp = this->players[start];
        if (pp->type == param_1 && start != current) {
            this->currentUpdateComputerPlayer = start;
            return;
        }
        start = (start + 1) % n;
        ++counter;
    }
}
