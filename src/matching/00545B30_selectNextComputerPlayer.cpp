// 00545B30 RGE_Game_World::selectNextComputerPlayer
// Source: World.cpp lines 3460-3487. 143 bytes. __thiscall, ret 4.
//
// Exact-finish audit: World.cpp lines 3460-3487 own boundary 00545B30-00545BBE.
// The qualified symbol is RGE_Game_World::selectNextComputerPlayer(int).
// Walkback removed the first-loop locals without codegen change; caching the second-pass
// current player added 9 bytes and failed. Versioned scenario loaders were not changed.
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
// Retry 2026-05-20 Boss pass: revalidated kept improved source (143B, 38.4615% positional, 46.1538% edit, first mismatch +7). Tried 11 more probes: decompiler-shaped source with separate else, for-loop first pass with int temp, unsigned-char temp, volatile current load, nested-if do second loop, loading player_num before current, plus /O1, /O2 without /Oy, /Ox, /Oa, and /Og flag probes. All source variants either reintroduced the this-home prologue / first-byte mismatch or worsened to 94%+ positional; flag variants were unchanged except /O1 too small.
// Retry 2026-05-21 Boss pass: 17 more probes. Removed register current, original if/else/decompiler order, delayed n load, first-loop for form, param/type locals, second do/for forms, compare operand order, manual modulo, goto split, volatile current, indexed first loop, volatile/member-direct player_num. Best kept below improves to 27.2727% positional / 32.8671% edit, first mismatch +12, by reloading currentUpdateComputerPlayer directly in the second loop instead of preserving the first current local. Second-loop register topology now mostly matches; remaining mismatch is first-loop load order/topology (player_num hoisted before current compare, duplicated first-loop body) and not accepted_drift quality.
// Retry 2026-05-24 Boss pass: MATCH. Key final probe used a normal for-loop in the first-pass scan and explicitly named the loaded player pointer and widened type local inside the loop (`RGE_Player* p = *ptr; int t = p->type;`). That made VC5 keep the clean `jl` backedge, place `mov ecx,[edx]` before `xor ebx,ebx`, and also stopped hoisting `player_num` before the current-player compare while preserving the matched second-loop direct reload of currentUpdateComputerPlayer.
// Exact-finish walkback: removing those first-pass aliases preserved the same bytes.

#ifndef WORLD_TU
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
#endif

void RGE_Game_World::selectNextComputerPlayer(int param_1) {
    int current = this->currentUpdateComputerPlayer;
    if (current == -1) {
        int i = 0;
        int n = this->player_num;
        if (i < n) {
            RGE_Player** ptr = this->players;
            for (; i < n; ++i, ++ptr) {
                if ((*ptr)->type == param_1) {
                    this->currentUpdateComputerPlayer = i;
                    return;
                }
            }
        }
        return;
    }

    int n = this->player_num;
    int start = this->currentUpdateComputerPlayer;
    int counter = 0;
    if (start >= n)
        return;
    while (start < n) {
        if (counter >= n)
            return;
        RGE_Player* p = this->players[start];
        if (p->type == param_1 && start != this->currentUpdateComputerPlayer) {
            this->currentUpdateComputerPlayer = start;
            return;
        }
        start = (start + 1) % n;
        ++counter;
    }
}
