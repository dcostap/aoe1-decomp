// VA: 00524AF0 TribeGame::show_ai
// Source: tribegam.cpp lines 2100-2137
// Attempt log:
// 1: natural reconstruction from packet: gather six player AI strings and pass them to UI display; after adding missing computerPlayer declaration compiled too small (608 vs 636).
// 2: tried /Oi for inline strcpy/sprintf-style sequence; no size change, flag removed.
// 3: unrolled computer-player name copy loop; size now matches 636 but broad prologue/register and block layout mismatch.
// 4: tried /O1 /Oy flag probe; object shrank to 545 and failed configured size, flag removed.
// 5: reviewed stack layout: original has six 0x100 buffers plus 4-byte home (0x604); current source matches total after unroll.
// 6: reviewed computer-player branch: original uses a loop with EBX=2..6 and EBP walking output buffers; unrolled source matches size but loses loop topology.
// 7: loop form source originally was closer semantically but too small; unroll fixes size at cost of topology.
// 8: reviewed non-computer branch: original performs one provider name copy, sprintf for player id, then four EMPTY_AI copies; modeled.
// 9: final display call argument order modeled for both computer/non-computer paths, but rebuilt has different push/order schedule.
// 10: left in scratch: remaining drift is broad and not accepted_drift-safe; exact source likely needs original loop/string-copy shape with inline rep movs/scas and correct this register EBX.
// 11: replaced the five unrolled computer-name calls with one natural indexed loop; call set/CFG then aligned and the frame reached 0x604.
// 12: changed the provider declaration to RGE_Player so computerPlayer uses the proven direct method symbol; emitted bytes were unchanged.
// 13: removed cached player/provider locals and used direct member expressions; this recovered the original reload topology and 77.94% exact-block coverage.
// 14: an explicit game=this alias was a codegen duplicate and was rolled back.
// 15: restored the virtual/base layout (player slot at +0x3F4, panel at +0xC24); the layout is canonical but did not change this register basin.
// 16: function-scope loop-index and inherited-base variants were codegen duplicates.
// 17: a pointer-cursor spelling moved four bytes closer but was less plausible than the direct indexed array loop, so it was rolled back.
// 18: paused after the bounded pass: current natural source has 9/9 ordered calls, 0x604 frame, 640 emitted bytes versus 636, and broad register/prologue drift.
// 19: renamed the panel declaration to TRIBE_Screen_Game; relocation identity is now period-canonical with no emitted-byte change.
// 20: tested the packet's cmp-6/jle loop spelling as i <= 6; only resync cost improved, so restored i < 7.

#include <string.h>
#include <stdio.h>

#define EMPTY_AI ((const char*)0x00592A40)

class RGE_Player {
public:
    int computerPlayer();
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual const char* name(int slot); // +14
};

class PlayerSlot {
public:
    int computerPlayer();
    virtual void v00();
    char gap_04[0x40 - 0x04];
    RGE_Player** providers;
    char gap_44[0x7C - 0x44];
    short current;
};

class TRIBE_Screen_Game {
public:
    void show_ai(char*, char*, char*, char*, char*, char*);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    PlayerSlot* playerSlot;
    char gap_3F8[0xA24 - 0x3F8];
};

class TribeGame : public RGE_Base_Game {
public:
    char gap_A24[0xC24 - 0xA24];
    TRIBE_Screen_Game* panel;
    virtual void show_ai();
};

void TribeGame::show_ai()
{
    int i;
    char s[6][256];
    if (this->playerSlot->providers == 0) {
        return;
    }

    if (this->playerSlot->providers[this->playerSlot->current]->computerPlayer() == 1) {
        const char* n = this->playerSlot->providers[this->playerSlot->current]->name(1);
        if (n == 0) {
            sprintf(s[0], (const char*)0x0058BD28,
                    (int)this->playerSlot->current);
        } else {
            sprintf(s[0], (const char*)0x0058BD18,
                    (int)this->playerSlot->current, n);
        }
        for (i = 2; i < 7; ++i) {
            const char* p = this->playerSlot->providers[
                this->playerSlot->current]->name(i);
            if (p == 0) {
                p = EMPTY_AI;
            }
            strcpy(s[i - 1], p);
        }
    } else {
        const char* p = this->playerSlot->providers[
            this->playerSlot->current]->name(0);
        strcpy(s[0], p);
        sprintf(s[1], (const char*)0x0058BCF0,
                (int)this->playerSlot->current);
        strcpy(s[2], EMPTY_AI);
        strcpy(s[3], EMPTY_AI);
        strcpy(s[4], EMPTY_AI);
        strcpy(s[5], EMPTY_AI);
    }

    if (this->panel != 0) {
        if (this->playerSlot->providers[this->playerSlot->current]->computerPlayer() == 1) {
            this->panel->show_ai(s[5], s[4], s[3], s[2], s[1], s[0]);
        } else {
            this->panel->show_ai(s[0], s[1], s[2], s[3], s[4], s[5]);
        }
    }
}
