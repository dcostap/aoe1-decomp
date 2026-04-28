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

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;                // +0x3C (signed word)
    char gap_3E[0x40 - 0x3E];
    void** players;                  // +0x40
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
    int current = this->currentUpdateComputerPlayer;
    if (current == -1) {
        int n = this->player_num;
        if (n > 0) {
            void** ptr = this->players;
            for (int i = 0; i < n; i++, ptr++) {
                if (((RGE_Player*)*ptr)->type == (unsigned char)param_1) {
                    this->currentUpdateComputerPlayer = i;
                    return;
                }
            }
        }
        return;
    }

    int n = this->player_num;
    int start = current;
    if (start >= n) return;

    int counter = 0;
    while (counter < n) {
        RGE_Player* pp = (RGE_Player*)this->players[start];
        if (pp->type == (unsigned char)param_1 && start != current) {
            this->currentUpdateComputerPlayer = start;
            return;
        }
        start = (start + 1) % n;
        counter++;
    }
}
