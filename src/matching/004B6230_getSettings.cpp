// TribeGameSettingsScreen::getSettings
// VA: 004B6230, scr_set.cpp:841-897

#define SCR_SET_CONTEXT_GROUP 1
#include "../../include/scr_set_context.h"
#ifndef SCR_SET_CONTEXT_GROUP
struct RGE_Base_Game {
    int scenarioGame();
    char* scenarioName();
    int allowCheatCodes();
    int fullVisibility();
    int difficulty();
    int multiplayerGame();
    unsigned char mpPathFinding();
    unsigned char pathFinding();
};

struct TRIBE_Game : RGE_Base_Game {
    unsigned char deathMatch();
    int mapSize();
    int mapType();
    int victoryType();
    int victoryAmount();
    int randomizePositions();
    int fullTechTree();
    int resourceLevel();
    int startingAge();
    unsigned char popLimit();
};

struct TListPanel {
    long get_line(char* s);
    void scroll_cur_line(unsigned char mode, short line, int update_scrollbar);
};

struct TDropDownPanel {
    long get_line(long v);
    void set_line(long v);
};

struct TButtonPanel {
    virtual void pad00(); virtual void pad01(); virtual void pad02(); virtual void pad03();
    virtual void pad04(); virtual void pad05(); virtual void pad06(); virtual void pad07();
    virtual void pad08(); virtual void pad09(); virtual void pad10(); virtual void pad11();
    virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15();
    virtual void pad16(); virtual void pad17(); virtual void pad18(); virtual void pad19();
    virtual void pad20(); virtual void pad21(); virtual void pad22(); virtual void pad23();
    virtual void pad24(); virtual void pad25(); virtual void pad26(); virtual void pad27();
    virtual void pad28(); virtual void pad29(); virtual void pad30(); virtual void pad31();
    virtual void pad32(); virtual void pad33(); virtual void pad34(); virtual void pad35();
    virtual void pad36(); virtual void pad37(); virtual void pad38(); virtual void pad39();
    virtual void pad40(); virtual void pad41(); virtual void pad42(); virtual void pad43();
    virtual void pad44(); virtual void pad45(); virtual void pad46(); virtual void pad47();
    virtual void pad48(); virtual void pad49(); virtual void pad50(); virtual void pad51();
    virtual void pad52(); virtual void pad53(); virtual void pad54(); virtual void pad55();
    virtual void set_state(int state);
};

struct TribeGameSettingsScreen {
    char gap_000[0x47c];
    int state;
    char gap_480[4];
    TDropDownPanel* mapSizeDrop;
    char gap_488[4];
    TDropDownPanel* mapTypeDrop;
    char gap_490[4];
    TDropDownPanel* victoryTypeDrop;
    char gap_498[12];
    TDropDownPanel* scoreDrop;
    char gap_4A8[4];
    TDropDownPanel* timeDrop;
    char gap_4B0[4];
    TDropDownPanel* difficultyDrop;
    char gap_4B8[4];
    TDropDownPanel* ageDrop;
    char gap_4C0[4];
    TDropDownPanel* resourcesDrop;
    char gap_4C8[4];
    TDropDownPanel* pathingDrop;
    char gap_4D0[4];
    TDropDownPanel* limitDrop;
    char gap_4D8[0x18];
    TListPanel* scenarioList;
    char gap_4F4[0x30];
    TButtonPanel* optionButton0;
    TButtonPanel* optionButton1;
    TButtonPanel* optionButton2;
    TButtonPanel* optionButton3;
    char gap_534[0x20];
    int last_scenario_line;

    void getSettings();
};

#define rge_base_game (*(TRIBE_Game**)0x62C574)

#endif

void TribeGameSettingsScreen::getSettings() {
    if (rge_base_game->scenarioGame() != 0) {
        this->state = 0;
    } else {
        this->state = 1;
    }

    this->last_scenario_line = 0;
    if (this->state == 1) {
        if (rge_base_game->deathMatch() != 0) {
            this->scenarioList->scroll_cur_line(1, 1, 1);
        } else {
            this->scenarioList->scroll_cur_line(1, 0, 1);
        }
    } else {
        long line = this->scenarioList->get_line(rge_base_game->scenarioName());
        if (line != -1) {
            this->scenarioList->scroll_cur_line(1, (short)line, 1);
            this->last_scenario_line = line - 1;
        } else {
            this->scenarioList->scroll_cur_line(1, 0, 1);
        }
    }

    this->mapSizeDrop->set_line(this->mapSizeDrop->get_line(rge_base_game->mapSize()));
    this->mapTypeDrop->set_line(this->mapTypeDrop->get_line(rge_base_game->mapType()));
    this->victoryTypeDrop->set_line(this->victoryTypeDrop->get_line(rge_base_game->victoryType()));

    if (this->optionButton3 != 0) {
        this->optionButton3->set_state(rge_base_game->allowCheatCodes());
    }
    this->optionButton1->set_state(rge_base_game->fullVisibility());
    this->optionButton0->set_state(rge_base_game->randomizePositions() == 0);
    this->optionButton2->set_state(rge_base_game->fullTechTree());

    this->resourcesDrop->set_line(this->resourcesDrop->get_line(rge_base_game->resourceLevel()));
    this->ageDrop->set_line(this->ageDrop->get_line(rge_base_game->startingAge()));
    this->difficultyDrop->set_line(this->difficultyDrop->get_line(rge_base_game->difficulty()));

    if (rge_base_game->multiplayerGame() != 0) {
        this->pathingDrop->set_line(this->pathingDrop->get_line((unsigned int)rge_base_game->mpPathFinding()));
    } else {
        this->pathingDrop->set_line(this->pathingDrop->get_line((unsigned int)rge_base_game->pathFinding()));
    }

    if (rge_base_game->multiplayerGame() != 0) {
        this->limitDrop->set_line(this->limitDrop->get_line((unsigned int)rge_base_game->popLimit()));
    }

    if (rge_base_game->victoryType() == 7) {
        this->timeDrop->set_line(this->timeDrop->get_line(rge_base_game->victoryAmount()));
    } else if (rge_base_game->victoryType() == 8) {
        this->scoreDrop->set_line(this->scoreDrop->get_line(rge_base_game->victoryAmount()));
    }
}
