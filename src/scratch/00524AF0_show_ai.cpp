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

#include <string.h>
#include <stdio.h>

#define EMPTY_AI ((const char*)0x00592A40)

class AiNameProvider {
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
    AiNameProvider** providers;
    char gap_44[0x7C - 0x44];
    short current;
};

class Panel {
public:
    void show_ai(char*, char*, char*, char*, char*, char*);
};

class TribeGame {
public:
    char gap_000[0x3F4];
    PlayerSlot* playerSlot;
    char gap_3F8[0xC24 - 0x3F8];
    Panel* panel;
    void show_ai();
};

void TribeGame::show_ai()
{
    char s0[256];
    char s1[256];
    char s2[256];
    char s3[256];
    char s4[256];
    char s5[256];

    PlayerSlot* ps = this->playerSlot;
    if (ps->providers == 0) {
        return;
    }

    AiNameProvider* provider = ps->providers[ps->current];
    if (provider->computerPlayer() == 1) {
        const char* n = provider->name(1);
        if (n == 0) {
            sprintf(s0, (const char*)0x0058BD28, (int)ps->current);
        } else {
            sprintf(s0, (const char*)0x0058BD18, (int)ps->current, n);
        }
        const char* p2 = ps->providers[ps->current]->name(2); if (p2 == 0) p2 = EMPTY_AI; strcpy(s1, p2);
        const char* p3 = ps->providers[ps->current]->name(3); if (p3 == 0) p3 = EMPTY_AI; strcpy(s2, p3);
        const char* p4 = ps->providers[ps->current]->name(4); if (p4 == 0) p4 = EMPTY_AI; strcpy(s3, p4);
        const char* p5 = ps->providers[ps->current]->name(5); if (p5 == 0) p5 = EMPTY_AI; strcpy(s4, p5);
        const char* p6 = ps->providers[ps->current]->name(6); if (p6 == 0) p6 = EMPTY_AI; strcpy(s5, p6);
    } else {
        const char* p = provider->name(0);
        strcpy(s0, p);
        sprintf(s1, (const char*)0x0058BCF0, (int)ps->current);
        strcpy(s2, EMPTY_AI);
        strcpy(s3, EMPTY_AI);
        strcpy(s4, EMPTY_AI);
        strcpy(s5, EMPTY_AI);
    }

    if (this->panel != 0) {
        provider = ps->providers[ps->current];
        if (provider->computerPlayer() == 1) {
            this->panel->show_ai(s5, s4, s3, s2, s1, s0);
        } else {
            this->panel->show_ai(s0, s1, s2, s3, s4, s5);
        }
    }
}
