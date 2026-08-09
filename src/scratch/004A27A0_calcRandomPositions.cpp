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
        if (rge_base_game->numberPlayers() > 0) {
            do {
                position_used[0] = player + 1;
                int humanity = comm->GetPlayerHumanity(position_used[0]);
                if (humanity == 2 || humanity == 4) {
                    int j = 0;
                    int count = this->scenarioPlayerCount;
                    if (count > 0) {
                        int* position = &position_used[1];
                        for (; j < count; ++j, ++position) {
                            if (*position == -1) {
                                selected_position = j;
                                break;
                            }
                        }
                    }

                    int tries = 0;
                    int new_position;
                    do {
                        int count = this->scenarioPlayerCount;
                        int random = debug_rand(
                            "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x5E4);
                        new_position = (count * random) / 0x7FFF;
                        if (new_position >= count) {
                            new_position = count - 1;
                        } else if (new_position < 0) {
                            new_position = 0;
                        }
                        if (position_used[new_position + 1] == -1) {
                            selected_position = new_position;
                            break;
                        }
                    } while (++tries < 1000);

                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(player, selected_position);
                    position_used[selected_position + 1] = player;
                }
                player = position_used[0];
                players = rge_base_game->numberPlayers();
            } while (player < players);
        }
    }
}
