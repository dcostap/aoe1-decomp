// 004B6870 TribeGameSettingsScreen::activateVictoryPanels (scr_set.cpp:1026-1064, 292B)
// Manages victory condition UI panel visibility based on game scenario state.
// FLAGS: /nologo /c /O2 /Oy

#define SCR_SET_CONTEXT_GROUP 1
#include "../../include/scr_set_context.h"
#ifndef SCR_SET_CONTEXT_GROUP
struct TTextPanel {
    unsigned char gap_00[0xF8];
    short num_lines;
    unsigned char gap_FA[0x6];
    short cur_line;

    long get_line();
};

struct MemberType {
    int get_id();
};

struct TDropDownPanel {
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_id();
};

struct PanelDispatch {
    virtual void dummy0() {}
    virtual void dummy1() {}
    virtual void dummy2() {}
    virtual void dummy3() {}
    virtual void dummy4() {}
    virtual void setVisible(int v) {}
};

struct TribeGameSettingsScreen {
    char gap_00[0x47C];
    int state;                              // +0x47C
    char gap_480[0x10];                     // 0x480-0x48F
    PanelDispatch* victoryTypeLabel;        // +0x490
    PanelDispatch* victoryTypeDrop;         // +0x494
    PanelDispatch* victoryFixedText;        // +0x498
    char gap_49C[4];                        // 0x49C-0x49F
    PanelDispatch* scoreLabel;              // +0x4A0
    PanelDispatch* scoreDrop;               // +0x4A4
    PanelDispatch* timeLabel;               // +0x4A8
    PanelDispatch* timeDrop;                // +0x4AC
    char gap_4B0[0x40];                     // 0x4B0-0x4EF
    TTextPanel* scenarioList;               // +0x4F0
    char gap_4F4[0x0C];                     // 0x4F4-0x4FF
    int* scenarioFixed;                     // +0x500 (int array)
    void* scenariosLoaded;                  // +0x504 (non-null check)
    char gap_508[0x50];                     // 0x508-0x557
    int scenario_line_offset;               // +0x558

    void activateVictoryPanels();
};

#endif

void TribeGameSettingsScreen::activateVictoryPanels() {
    timeLabel->setVisible(0);
    timeDrop->setVisible(0);
    scoreLabel->setVisible(0);
    scoreDrop->setVisible(0);

    if (state == 0) {
        long firstLine = scenarioList->get_line();
        long secondLine = scenarioList->get_line();

        if (scenariosLoaded != 0 && secondLine >= 0 &&
            scenarioFixed[scenario_line_offset + firstLine] != 0) {
            victoryFixedText->setVisible(1);
            victoryTypeLabel->setVisible(0);
            victoryTypeDrop->setVisible(0);
            return;
        }
    }

    victoryFixedText->setVisible(0);
    victoryTypeLabel->setVisible(1);
    victoryTypeDrop->setVisible(1);

    if (((TDropDownPanel*)victoryTypeDrop)->get_id() == 7) {
        timeLabel->setVisible(1);
        timeDrop->setVisible(1);
    }

    if (((TDropDownPanel*)victoryTypeDrop)->get_id() == 8) {
        scoreLabel->setVisible(1);
        scoreDrop->setVisible(1);
    }
}
