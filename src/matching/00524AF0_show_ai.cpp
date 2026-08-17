// VA: 00524AF0 TRIBE_Game::show_ai
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
// 21: this claim tested a natural contiguous destination cursor at s[1]; it reached 636 bytes and diff 595, but kept this in EBP and was rolled back.
// 22: register-qualified cursor rooted at s[2] did not change VC5 allocation; rolled back.
// 23: typed array cursor with destination[-1] was emitted identically to the prior cursor basin.
// 24: explicit game=this alias with the typed cursor was a codegen duplicate.
// 25: register-qualified typed cursor was a duplicate; VC5 still kept this in EBP.
// 26: grouping i and the typed cursor in the for initializer returned the clean 640-byte basin.
// 27: pairing the typed cursor with i <= 6 changed only resync cost, not structural bytes.
// 28: mutable char* name ABI matched the binary pointer surface but emitted no new code.
// 29: Restored the real string literals. The former absolute addresses were
//     diagnostic data plumbing, not valid source ownership.
// 30: Recovered the original typed row-cursor flow: initialize i before the
//     destination row pointer, keep output separate from the nullable name,
//     and use a default empty source with a non-null replacement.
// 31: The natural i <= 6 loop then matched all 636 bytes, calls, frame, and
//     boundary. Removing the redundant game=this alias kept the exact match.

#include <string.h>
#include <stdio.h>

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

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x7C - 0x44];
    short curr_player;
};

class TRIBE_Screen_Game {
public:
    void show_ai(char*, char*, char*, char*, char*, char*);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
    char gap_3F8[0xA24 - 0x3F8];
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0xC24 - 0xA24];
    TRIBE_Screen_Game* game_screen;
    virtual void show_ai();
};

void TRIBE_Game::show_ai()
{
    int i;
    char s[6][256];
    if (this->world->players == 0) {
        return;
    }

    if (this->world->players[this->world->curr_player]->computerPlayer() == 1) {
        const char* n = this->world->players[this->world->curr_player]->name(1);
        if (n == 0) {
            sprintf(s[0], "Player #%d: AI is not functional.",
                    (int)this->world->curr_player);
        } else {
            sprintf(s[0], "Player #%d: %s",
                    (int)this->world->curr_player, n);
        }
        i = 2;
        char (*destination)[256] = &s[2];
        for (; i <= 6; ++i) {
            const char* p = this->world->players[
                this->world->curr_player]->name(i);
            char* output = destination[-1];
            const char* source = "";
            if (p != 0) {
                source = p;
            }
            strcpy(output, source);
            ++destination;
        }
    } else {
        const char* p = this->world->players[
            this->world->curr_player]->name(0);
        strcpy(s[0], p);
        sprintf(s[1], "Player #%d is not a computer player.",
                (int)this->world->curr_player);
        strcpy(s[2], "");
        strcpy(s[3], "");
        strcpy(s[4], "");
        strcpy(s[5], "");
    }

    if (this->game_screen != 0) {
        if (this->world->players[this->world->curr_player]->computerPlayer() == 1) {
            this->game_screen->show_ai(s[5], s[4], s[3], s[2], s[1], s[0]);
        } else {
            this->game_screen->show_ai(s[0], s[1], s[2], s[3], s[4], s[5]);
        }
    }
}
