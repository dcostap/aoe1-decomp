// VA: 004B6500 TribeGameSettingsScreen::sendSettings
// Attempt log:
// 1: natural reconstruction from packet/decompiler.
// 2: added setMpPathFinding to base-game surface after compile failure.
// 3: first build same-size but broad diff; get_id default argument emitted extra push 0 and local field layout was shifted by -8 from bad gaps.
// 4: fixed field offsets and no-arg get_id calls; first mismatch moved to victory dispatch shape (cmp vs original sub/dec).
// 5: rewrote victory dispatch with v-=7/--v and overloaded one-arg setVictoryType for default; removes extra setVictoryType arg but inlined per-case calls instead of original shared tail.
// 6: inverted victory if order to match original default/score/time block order; positional 40.7%, not better than previous but block order is closer conceptually.
// 7: tried /GX; unchanged.
// 8: tried /O2 without /Oy; unchanged.
// 9: remaining main mismatch starts in victory-type dispatch/call-tail sharing: original uses sub/dec with shared setVictoryType tail and unusual one/two pushed args; rebuilt emits separate calls/branches.
// 10: left in scratch: all settings calls and offsets are modeled, same-size 567 B, but broad mid-function branch/call-layout mismatch remains and is not accepted_drift-safe.
// SA60574_send: the default victory arm is a two-int setVictoryType call;
// right-to-left lowering intentionally leaves the literal 1 below the
// no-argument victory get_id result before the shared setter tail. A direct
// switch with the three typed setter calls reproduces the original sub/dec
// dispatch and tail merge exactly.
// SA60574_send: replaced the raw empty-string address with the natural ""
// literal; it remains an exact 567-byte match under default.rsp.

#define SCR_SET_CONTEXT_GROUP 1
#include "../../include/scr_set_context.h"
#ifndef SCR_SET_CONTEXT_GROUP
class TTextPanel { public: long get_id(); char* get_text(); };
class TDropDownPanel { public: long get_id(); };
class TButtonPanel { public: int get_state(); };

class RGE_Base_Game {
public:
    void setScenarioGame(int);
    void setScenarioName(char*);
    int randomGame();
    void setAllowCheatCodes(int);
    void setFullVisibility(int);
    void setPathFinding(unsigned char);
    void setMpPathFinding(unsigned char);
    void setDifficulty(int);
    int multiplayerGame();
    int singlePlayerGame();
    void set_single_player_difficulty(int);
};
class TRIBE_Game : public RGE_Base_Game {
public:
    void setMapSize(int);
    void setMapType(int);
    void setVictoryType(int, int);
    void setDeathMatch(unsigned char);
    void setRandomizePositions(unsigned char);
    void setFullTechTree(int);
    void setResourceLevel(int);
    void setStartingAge(int);
    void setPopLimit(unsigned char);
};
extern TRIBE_Game* rge_base_game;

class TribeGameSettingsScreen {
public:
    char gap_000[0x484];
    TDropDownPanel* mapSizeDrop;      // +484
    char gap_488[4];
    TDropDownPanel* mapTypeDrop;      // +48C
    char gap_490[4];
    TDropDownPanel* victoryTypeDrop;  // +494
    char gap_498[0x4A4 - 0x498];
    TDropDownPanel* scoreDrop;        // +4A4
    char gap_4A8[4];
    TDropDownPanel* timeDrop;         // +4AC
    char gap_4B0[4];
    TDropDownPanel* difficultyDrop;   // +4B4
    char gap_4B8[4];
    TDropDownPanel* ageDrop;          // +4BC
    char gap_4C0[4];
    TDropDownPanel* resourcesDrop;    // +4C4
    char gap_4C8[4];
    TDropDownPanel* pathingDrop;      // +4CC
    char gap_4D0[4];
    TDropDownPanel* limitDrop;        // +4D4
    char gap_4D8[0x4F0 - 0x4D8];
    TTextPanel* scenarioList;         // +4F0
    char gap_4F4[0x524 - 0x4F4];
    TButtonPanel* optionButton0;      // +524
    TButtonPanel* optionButton1;      // +528
    TButtonPanel* optionButton2;      // +52C
    TButtonPanel* optionButton3;      // +530

    void sendSettings();
};

#endif

void TribeGameSettingsScreen::sendSettings()
{
    if (this->scenarioList->get_id() >= 0) {
        rge_base_game->setScenarioGame(1);
        rge_base_game->setScenarioName(this->scenarioList->get_text());
    } else {
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName("");
    }

    rge_base_game->setDeathMatch(this->scenarioList->get_id() == -1);

    switch (this->victoryTypeDrop->get_id()) {
    case 7:
        rge_base_game->setVictoryType(7, this->timeDrop->get_id());
        break;
    case 8:
        rge_base_game->setVictoryType(8, this->scoreDrop->get_id());
        break;
    default:
        rge_base_game->setVictoryType(this->victoryTypeDrop->get_id(), 1);
        break;
    }

    if (rge_base_game->randomGame()) {
        rge_base_game->setMapSize(this->mapSizeDrop->get_id());
        rge_base_game->setMapType(this->mapTypeDrop->get_id());
    }
    if (this->optionButton3 != 0) {
        rge_base_game->setAllowCheatCodes(this->optionButton3->get_state());
    }
    rge_base_game->setFullVisibility(this->optionButton1->get_state());
    rge_base_game->setRandomizePositions(this->optionButton0->get_state() == 0);
    rge_base_game->setFullTechTree(this->optionButton2->get_state());

    if (this->scenarioList->get_id() == -1) {
        rge_base_game->setResourceLevel(0);
    } else {
        rge_base_game->setResourceLevel(this->resourcesDrop->get_id());
    }

    if (rge_base_game->multiplayerGame()) {
        rge_base_game->setMpPathFinding(this->pathingDrop->get_id());
    } else {
        rge_base_game->setPathFinding(this->pathingDrop->get_id());
    }
    if (rge_base_game->multiplayerGame()) {
        rge_base_game->setPopLimit(this->limitDrop->get_id());
    }
    rge_base_game->setStartingAge(this->ageDrop->get_id());
    rge_base_game->setDifficulty(this->difficultyDrop->get_id());
    if (rge_base_game->singlePlayerGame()) {
        rge_base_game->set_single_player_difficulty(this->difficultyDrop->get_id());
    }
}
