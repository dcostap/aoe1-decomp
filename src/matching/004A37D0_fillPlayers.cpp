// VA: 004A37D0 TribeMPSetupScreen::fillPlayers
// PDB donor: scr_mps.cpp:1940-2203
//
// Baseline reconstruction: preserve the proven player-panel arrays, the two
// source loops, and the natural typed panel/game/communications surfaces.
//
// Attempt log:
// - established the +0x490..+0x5F0 panel arrays and +0x72C/+0x738/+0x85C
//   fields; the natural typed baseline has the correct 0x14 frame and 116 calls.
// - corrected the panel integer/string virtual slots, +0x610 layout gap, and
//   setPlayerTeam(int,int); this removed the call-count and relocation gaps.
// - tested humanity/is_me declaration order, function-scope homes, pointer and
//   union reuse, and bool predicate forms.  Bool forms moved the whole register
//   basin and pointer/union forms either duplicated the clean code or grew the
//   frame; none fixed the original humanity stack home.
// - audited the packet's 116 calls: player/color/team/version calls, dropdown
//   line effects, and all virtual panel slots/arities are represented; the clean
//   candidate keeps the exact frame and call count.
// - corrected donor ABI spellings for const game queries, long dropdown indices,
//   and unsigned-long text colors; these are source-correct but codegen-neutral.
// - diagnostic volatile humanity reproduced the original humanity stack store
//   but added non-source volatile traffic; rolled back.
// - MATCH (2026-08): the basin-breaking fix was to stop reassigning humanity
//   mid-loop.  set_state_by_id takes a SEPARATE color temp (myPlayerColor or
//   playerColor(i)), so the top-of-loop humanity value stays spilled at
//   [esp+10h] while is_me earns EBP; the old single-variable form forced
//   humanity into EBP and reversed both homes.
// - the original mixes `is_me == 1` (cmp ebp,1) at the color/team/single-name
//   sites with plain `is_me` (test ebp,ebp) at the boolean sites; spelled both.
// - name_color is inverted vs naive reading: not-ready -> 0xFF, ready -> 0xFF00.
// - name-drop block: multiplayer branch inline first, single-player is_me==1
//   branch as the late je target (matches L2113-L2127 layout).
// - civ/scenarioPlayer mode!=2 blocks need the get_line/set_line call duplicated
//   in both arms so ecx=[drop] stays live across the if-arm and VC5 tail-merges
//   at `call get_line` (if-arm: push eax; jmp join).

#define VP(n) virtual void v##n();

class TPanel {
public:
    VP(0) VP(1) VP(2) VP(3) VP(4)
    virtual void set_active(int value);
    VP(6) VP(7) VP(8) VP(9) VP(10) VP(11) VP(12) VP(13) VP(14) VP(15)
    VP(16) VP(17) VP(18) VP(19) VP(20) VP(21) VP(22) VP(23) VP(24) VP(25)
    VP(26) VP(27) VP(28) VP(29) VP(30) VP(31) VP(32) VP(33) VP(34) VP(35)
    VP(36) VP(37) VP(38) VP(39) VP(40) VP(41) VP(42) VP(43) VP(44) VP(45)
    VP(46) VP(47) VP(48) VP(49) VP(50) VP(51) VP(52) VP(53) VP(54) VP(55)
    virtual void set_state(short state);
    virtual void set_text_id(int string_id);
    virtual void set_text_string(char* text);

    char gap_04[0xF0];
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x2C];
    unsigned long text_color1; // +0x120

    void set_text_color(unsigned long color1, unsigned long color2);
};

class TButtonPanel : public TPanel {
public:
    void set_state_by_id(long id);
    int get_state();
    int get_text(short state, char** text1, char** text2);
    void get_text_color(short state, unsigned long* color1, unsigned long* color2);
    void set_disabled(int disabled);
};

class TDropDownPanel : public TPanel {
public:
    char gap_F4[0x10];
    int mode; // +0x104

    long get_id();
    long get_id(long param);
    char* get_text();
    long get_line(long index);
    long set_line(long line);
    int delete_line(long line);
    int insert_line(long line, char* text, long value);
    void set_val_text_color(unsigned long foreground, unsigned long background);
};

class TScreenPanel : public TPanel {
public:
    char gap_F4[0x384];
};

class RGE_Scenario;
class RGE_Scenario_Header;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options(); // +0x48

    int multiplayerGame() const;
    int numberPlayers() const;
    int singlePlayerGame() const;
    int playerHasCD(int player);
    unsigned char playerVersion(int player);
    char* playerVersionString(int player);
    void setPlayerVersion(int player, unsigned char version);
    int playerTeam(int player);
    void setPlayerTeam(int player, int team);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int playerColor(int player);
    int civilization(int player);
    void setCivilization(int player, int civilization);
    int scenarioPlayer(int player);
};

class TCommunications_Handler {
public:
    int IsHost();
    int IsPlayerReady(unsigned int player);
    int GetPlayerHumanity(unsigned int player);
    int WhoAmI();
    char* GetPlayerName(unsigned int player);
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TDebuggingLog* L;

class TribeMPSetupScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* playerTitle;
    TTextPanel* civTitle;
    TTextPanel* settingsTitle;
    TTextPanel* colorTitle;
    TTextPanel* teamTitle;
    TTextPanel* playerNameText[8];
    TTextPanel* playerCivText[8];
    TTextPanel* scenarioPlayerText[8];
    TTextPanel* playerCDText[8];
    TTextPanel* playerVersionText[8];
    TTextPanel* playerColorText[8];
    TTextPanel* playerTeamText[8];
    TButtonPanel* playerColor[8];
    TButtonPanel* playerTeam[8];
    TDropDownPanel* playerNameDrop[8];
    TDropDownPanel* playerCivDrop[8];
    TDropDownPanel* scenarioPlayerDrop[8];
    char gap_610[0x11C];
    int myCivilization;       // +0x72C
    int myScenarioPlayer;     // +0x730
    int myPlayerColor;        // +0x734
    int myPlayerTeam;         // +0x738
    char gap_73C[0x114];
    int numberAnyPlayers;     // +0x850
    char gap_854[0x08];
    int i_am_ready;           // +0x85C
    char gap_860[0x30];

    virtual ~TribeMPSetupScreen();
    void fillPlayers();
    void fillPlayerColors();
};

void TribeMPSetupScreen::fillPlayers()
{
    if (rge_base_game->multiplayerGame() && comm->IsHost()) {
        int color2 = 0;
        TTextPanel** text1 = 0;
        int i = 0;
        if (rge_base_game->numberPlayers() > 0) {
            text1 = this->playerNameText;
            do {
                int player = i + 1;
                if (comm->IsPlayerReady(player) && text1[0]->text_color1 == 0xFF) {
                    int j = 0;
                    int inner_players = rge_base_game->numberPlayers();
                    if (inner_players > 0) {
                        do {
                            if (i != j && comm->IsPlayerReady(j + 1)) {
                                int other_color = ((TRIBE_Game*)rge_base_game)->playerColor(j);
                                int player_color = ((TRIBE_Game*)rge_base_game)->playerColor(i);
                                if (other_color == player_color) {
                                    L->Log("$$$ SETTING CIV/TEAM+50 (%d,%d)", i, j);
                                    int civ = ((TRIBE_Game*)rge_base_game)->civilization(i);
                                    ((TRIBE_Game*)rge_base_game)->setCivilization(j, civ + 0x32);
                                    int team = rge_base_game->playerTeam(i);
                                    rge_base_game->setPlayerTeam(j, team + 0x32);
                                    color2 = 1;
                                }
                            }
                            ++j;
                            inner_players = rge_base_game->numberPlayers();
                        } while (j < inner_players);
                    }
                }
                ++i;
                ++text1;
            } while (i < rge_base_game->numberPlayers());
        }
        if (color2 != 0) {
            rge_base_game->send_game_options();
        }
    }

    int i = 0;
    int players = rge_base_game->numberPlayers();
    if (players > 0) {
        do {
            int is_me;
            int humanity;
            if (rge_base_game->multiplayerGame()) {
                int player = i + 1;
                humanity = comm->GetPlayerHumanity(player);
                is_me = comm->WhoAmI() == player;
            } else if (i == 0) {
                humanity = 2;
                is_me = 1;
            } else {
                humanity = this->playerNameDrop[i]->get_id();
                is_me = 0;
            }

            if (!rge_base_game->multiplayerGame() || humanity != 2) {
                this->playerCDText[i]->set_active(0);
                this->playerVersionText[i]->set_active(0);
            } else {
                this->playerCDText[i]->set_active(rge_base_game->playerHasCD(i));
                if (comm->IsHost() || rge_base_game->playerVersion(0) != 0) {
                    this->playerVersionText[i]->set_text_string(rge_base_game->playerVersionString(i));
                    this->playerVersionText[i]->set_active(1);
                } else if (i == 0) {
                    this->playerVersionText[0]->set_text_string(rge_base_game->playerVersionString(0));
                    this->playerVersionText[0]->set_active(1);
                } else if (is_me) {
                    rge_base_game->setPlayerVersion(i, 1);
                    this->playerVersionText[i]->set_text_string(rge_base_game->playerVersionString(i));
                    this->playerVersionText[i]->set_active(1);
                } else {
                    this->playerVersionText[i]->set_active(0);
                }
            }

            int color;
            if (is_me == 1 && this->myPlayerColor != 0) {
                color = this->myPlayerColor;
            } else {
                color = ((TRIBE_Game*)rge_base_game)->playerColor(i);
            }
            this->playerColor[i]->set_state_by_id(color);
            int state = this->playerColor[i]->get_state();
            char* text1;
            char* text2;
            unsigned long color1;
            unsigned long color2;
            this->playerColor[i]->get_text((short)state, &text1, &text2);
            this->playerColor[i]->get_text_color((short)state, &color1, &color2);
            this->playerColorText[i]->set_text_string(text1);
            this->playerColorText[i]->set_text_color(color1, color2);
            this->playerColor[i]->set_active(0);
            this->playerColorText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() && is_me && this->i_am_ready == 0) ||
                (rge_base_game->singlePlayerGame() && is_me && this->numberAnyPlayers > 1)) {
                this->playerColor[i]->set_active(1);
                this->playerColor[i]->set_disabled(0);
            } else if (humanity == 2) {
                this->playerColorText[i]->set_active(1);
            }

            if (is_me == 1 && this->myPlayerTeam != 0) {
                this->playerTeam[i]->set_state((short)this->myPlayerTeam - 1);
            } else {
                int team = rge_base_game->playerTeam(i);
                if (team >= 0x32) {
                    team -= 0x32;
                }
                this->playerTeam[i]->set_state(team - 1);
            }

            state = this->playerTeam[i]->get_state();
            this->playerTeam[i]->get_text((short)state, &text1, &text2);
            this->playerTeamText[i]->set_text_string(text1);
            this->playerTeam[i]->set_active(0);
            this->playerTeamText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() &&
                 ((is_me && this->i_am_ready == 0) ||
                  (comm->IsHost() && humanity == 4 && this->i_am_ready == 0))) ||
                (rge_base_game->singlePlayerGame() && (is_me || humanity == 4))) {
                this->playerTeam[i]->set_active(1);
                this->playerTeam[i]->set_disabled(0);
            } else if (humanity == 2 || humanity == 4) {
                this->playerTeamText[i]->set_active(1);
            }

            if (rge_base_game->multiplayerGame()) {
                int name_color;
                if (humanity == 2 && !comm->IsPlayerReady(i + 1)) {
                    name_color = 0xFF;
                } else {
                    name_color = 0xFF00;
                }
                this->playerNameDrop[i]->set_val_text_color(name_color, 0);
                this->playerNameText[i]->set_text_color(name_color, 0);
            }

            if (rge_base_game->multiplayerGame()) {
                if (this->playerNameDrop[i]->get_id(0) == 2) {
                    this->playerNameDrop[i]->delete_line(0);
                }
                if (humanity == 2) {
                    this->playerNameDrop[i]->insert_line(0, comm->GetPlayerName(i + 1), humanity);
                }
                this->playerNameDrop[i]->set_line(this->playerNameDrop[i]->get_line(humanity));
                this->playerNameText[i]->set_text_string(this->playerNameDrop[i]->get_text());
            } else {
                if (is_me == 1) {
                    this->playerNameText[i]->set_text_id(0x25B3);
                } else {
                    this->playerNameText[i]->set_text_string(this->playerNameDrop[i]->get_text());
                }
            }

            if (this->playerCivDrop[i]->mode != 2) {
                if (is_me == 1 && this->myCivilization != 0) {
                    this->playerCivDrop[i]->set_line(
                        this->playerCivDrop[i]->get_line(this->myCivilization));
                } else {
                    int civ = ((TRIBE_Game*)rge_base_game)->civilization(i);
                    if (civ >= 0x32) {
                        civ -= 0x32;
                    }
                    this->playerCivDrop[i]->set_line(
                        this->playerCivDrop[i]->get_line(civ));
                }
            }
            this->playerCivText[i]->set_text_string(this->playerCivDrop[i]->get_text());

            if (this->scenarioPlayerDrop[i]->mode != 2) {
                if (is_me == 1 && this->myScenarioPlayer != -1) {
                    this->scenarioPlayerDrop[i]->set_line(
                        this->scenarioPlayerDrop[i]->get_line(this->myScenarioPlayer));
                } else {
                    int scenario_player = ((TRIBE_Game*)rge_base_game)->scenarioPlayer(i);
                    this->scenarioPlayerDrop[i]->set_line(
                        this->scenarioPlayerDrop[i]->get_line(scenario_player));
                }
            }
            this->scenarioPlayerText[i]->set_text_string(this->scenarioPlayerDrop[i]->get_text());

            if (rge_base_game->multiplayerGame() && comm->IsHost() && !is_me) {
                this->playerNameDrop[i]->set_active(1);
                this->playerNameText[i]->set_active(0);
            } else {
                this->playerNameDrop[i]->set_active(0);
                this->playerNameText[i]->set_active(1);
            }
            this->playerCivDrop[i]->set_active(0);
            this->playerCivText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() &&
                 ((is_me && this->i_am_ready == 0) ||
                  (comm->IsHost() && humanity == 4 && this->i_am_ready == 0))) ||
                (rge_base_game->singlePlayerGame() && (is_me || humanity == 4))) {
                this->playerCivDrop[i]->set_active(1);
            } else if (humanity == 2 || humanity == 4) {
                this->playerCivText[i]->set_active(1);
            }
            this->scenarioPlayerDrop[i]->set_active(0);
            this->scenarioPlayerText[i]->set_active(0);

            ++i;
            players = rge_base_game->numberPlayers();
        } while (i < players);
    }

    if (i < 8) {
        TDropDownPanel** p = this->playerCivDrop + i;
        int remaining = 8 - i;
        do {
            p[-8]->set_active(0);
            p[0]->set_active(0);
            p[8]->set_active(0);
            p[-24]->set_active(0);
            p[-40]->set_active(0);
            p[-16]->set_active(0);
            p[-32]->set_active(0);
            p[-80]->set_active(0);
            p[-72]->set_active(0);
            p[-64]->set_active(0);
            p[-56]->set_active(0);
            p[-48]->set_active(0);
            ++p;
            --remaining;
        } while (remaining != 0);
    }

    this->fillPlayerColors();
}

#undef VP
