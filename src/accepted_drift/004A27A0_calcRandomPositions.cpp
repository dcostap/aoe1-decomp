// VA: 004A27A0 calcRandomPositions
// PDB donor: scr_mps.cpp:1452-1526
//
// Baseline reconstruction: the routine counts human players, records the
// currently available scenario-player positions, and assigns each human a
// random unused position.  position_used[0] is the per-iteration player
// scratch slot; entries 1..8 are the eight dropdown positions.
//
// Attempt log (sa64f8-calc):
// - Baseline named the screen/dropdown/game/communications surfaces and
//   recovered the 0x2C frame, four saved registers, and all nine call sites.
// - Swapping local declaration order, scoping the zero-based player counter,
//   and separating its one-based humanity query recovered the original saved
//   this home, second-loop register roles, player argument, and most block
//   placement.  The setScenarioPlayer/store values are intentionally zero
//   based; only GetPlayerHumanity receives player+1.
// - An explicit bounded pointer for-loop is the best source basin.  Guarded
//   do/while, unguarded for, pointer-base/preincrement, and explicit-continue
//   variants grew the frame or moved the whole function; rolled back.
// - Caching scenarioPlayerCount and reversing the random product/retry
//   spellings were codegen duplicates.  Best current result is 372 rebuilt
//   bytes versus 366, 94.31% shape, 165 positional diff bytes, 9/9 calls;
//   remaining structural drift starts at the nested count scan (duplicated
//   test/LEA layout), followed by the random-loop tail.
// - Fresh pass isolated guarded do/while scans (pointer, indexed, reused-index,
//   and declaration-order forms); all added a 0x30 frame and broad drift.
//   while/short-circuit forms retained the duplicate count test. A for-header
//   retry loop improved structural shape to 97.54% and resync similarity to
//   91.08% (370 bytes), but strict drift was 171 bytes; compound random
//   multiplication was codegen-neutral. Removing only the nested count guard
//   preserved size but moved the whole local basin (220-byte drift). Restored
//   the validated 372-byte natural candidate.
// - Fresh claim probes: guarded do/while scans with the original polarity
//   entered a +0x30-frame compiler basin; indexed, infinite, and labeled forms
//   were duplicate variants of that basin. Removing the guard alone also moved
//   the frame/register basin. Adding <stdio.h> (and <stdlib.h>) was neutral.
// - The natural inverted-predicate do/while (`*position != -1` advances,
//   otherwise records the index) restores the original single count test,
//   0x2C frame, and nested scan block: 368 bytes, 95.87% shape, 76 diff bytes,
//   9/9 calls. Swapping/compounding the random product was codegen-neutral;
//   the remaining 2-byte size/tail drift is in the magic random division.
// - Fresh claim: reusing the debug_rand result for the quotient and adding a
//   natural product temporary were codegen duplicates. A combined retry
//   predicate improved the retry jump but worsened the local block topology;
//   restored the pinned inverted-scan source.
// - Fresh bounded pass: inlining debug_rand in the scaling expression matches
//   the oracle's ECX-held magic-division schedule and improves diff 76 -> 66.
//   Combined retry, explicit else, and infinite-loop spellings were worse or
//   duplicate; keep the natural do/while.  A bounded for-header retry loop
//   instead reproduces the oracle's direct JL backedge, exact size, CFG, and
//   every byte except the final player-count compare (cmp esi,eax vs ebp,eax).
// ACCEPTED_DRIFT: main-agent adjudication confirmed EBP is copied from ESI
// before numberPlayers. That call preserves ESI. Both compares therefore use
// the same value and set identical flags. No memory or call effect differs.

#include <stdio.h>

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TScreenPanel : public TPanel {
public:
    char gap_F4[0x384];
};

class TDropDownPanel {
public:
    long get_line(long index);
};

class RGE_Base_Game {
public:
    int numberPlayers() const;
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setScenarioPlayer(int player, int scenario_player);
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(unsigned int player);
};

class TribeMPSetupScreen : public TScreenPanel {
public:
    char gap_478[0x178];
    TDropDownPanel* scenarioPlayerDrop[8]; // +0x5F0
    char gap_610[0x110];
    int cancelMode;                         // +0x720
    int playerToKick;                       // +0x724
    int scenarioPlayerCount;                // +0x728

    void calcRandomPositions();
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern "C" int __cdecl debug_rand(char* file, int line);

void TribeMPSetupScreen::calcRandomPositions() {
    int selected_position;
    int position_used[9];
    int human_players = 0;
    int i = 0;
    int players = rge_base_game->numberPlayers();

    if (players > 0) {
        do {
            ++i;
            int humanity = comm->GetPlayerHumanity(i);
            if (humanity == 2 || humanity == 4) {
                ++human_players;
            }
            players = rge_base_game->numberPlayers();
        } while (i < players);
    }

    int available = 0;
    i = 0;
    do {
        long line = this->scenarioPlayerDrop[0]->get_line(i);
        if (line == -1) {
            position_used[i + 1] = -2;
        } else {
            position_used[i + 1] = -1;
            ++available;
        }
        ++i;
    } while (i < 8);

    if (human_players <= available) {
        int player = 0;
        for (; player < rge_base_game->numberPlayers(); player = position_used[0]) {
                position_used[0] = player + 1;
                int humanity = comm->GetPlayerHumanity(position_used[0]);
                if (humanity == 2 || humanity == 4) {
                    int j = 0;
                    int count = this->scenarioPlayerCount;
                    if (count > 0) {
                        int* position = &position_used[1];
                        do {
                            if (*position != -1) {
                                ++j;
                                ++position;
                            } else {
                                selected_position = j;
                                break;
                            }
                        } while (j < count);
                    }

                    int tries = 0;
                    int new_position;
                    for (; tries < 1000; ++tries) {
                        int count = this->scenarioPlayerCount;
                        new_position =
                            (debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x5E4) * count) /
                            0x7FFF;
                        if (new_position >= count) {
                            new_position = count - 1;
                        } else if (new_position < 0) {
                            new_position = 0;
                        }
                        if (position_used[new_position + 1] == -1) {
                            selected_position = new_position;
                            break;
                        }
                    }

                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(player, selected_position);
                    position_used[selected_position + 1] = player;
                }
        }
    }
}
