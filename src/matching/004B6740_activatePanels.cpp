// 004B6740 TribeGameSettingsScreen::activatePanels (scr_set.cpp:970-1020, 296B)
// Controls visibility of scenario/mission panels based on state and multiplayer.
// FLAGS: /nologo /c /O2 /Oy

// Panel with setVisible at vtable slot 5 (+0x14)
struct PanelDispatch3 {
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void setVisible(int v) = 0;
};

// Base class for vtable slot 50 (0xC8 = 4*50) dispatch
struct PanelBase50 {
    virtual void d00() = 0;
    virtual void d01() = 0;
    virtual void d02() = 0;
    virtual void d03() = 0;
    virtual void d04() = 0;
    virtual void d05() = 0;
    virtual void d06() = 0;
    virtual void d07() = 0;
    virtual void d08() = 0;
    virtual void d09() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void d45() = 0;
    virtual void d46() = 0;
    virtual void d47() = 0;
    virtual void d48() = 0;
    virtual void d49() = 0;
};

struct TTextPanel3 {
    char _gap_00[4];
    long get_id();
};

struct RGE_Game_Options2 {
    float versionValue;
    unsigned char scenarioGameValue;
    char _pad_05[0x7F];
    unsigned char singlePlayerGameValue;
    unsigned char multiplayerGameValue;
};

struct RGE_BaseGame2 {
    char _gap_00[4];
    char _pad_04[0x8F8];
    RGE_Game_Options2 rge_game_options;

    int multiplayerGame();
};

extern "C" {
    extern RGE_BaseGame2* rge_base_game;
}

struct TribeGameSettingsScreen : PanelBase50 {
    char _pad_04[0x3C - 4];
    void* field_3C;                      // +0x3C
    char _pad_40[0x47C - 0x40];
    int state;                           // +0x47C
    PanelDispatch3* mapSizeDrop;         // +0x480
    PanelDispatch3* mapTypeDrop;         // +0x484
    PanelDispatch3* mapSizeLabel;        // +0x488
    PanelDispatch3* mapTypeLabel;        // +0x48C
    char _pad_490[0x4C0 - 0x490];
    PanelDispatch3* resourcesLabel;      // +0x4C0
    PanelDispatch3* resourcesDrop;       // +0x4C4
    char _pad_4C8[0x4F0 - 0x4C8];
    TTextPanel3* scenarioList;           // +0x4F0
    char _pad_4F4[0x508 - 0x4F4];
    PanelDispatch3* missionTitle;        // +0x508
    char _pad_50C[0x51C - 0x50C];
    PanelDispatch3* missionText;         // +0x51C
    char _pad_520[0x544 - 0x520];
    PanelDispatch3* okButton;            // +0x544
    PanelDispatch3* cancelButton;        // +0x548

    void activateVictoryPanels();
    virtual void setTabList(void** list, int count); // vtable slot 50 (0xC8)
    void set_curr_child(PanelDispatch3* child);
    void activatePanels();
};

void TribeGameSettingsScreen::activatePanels() {
    void* tabList[3];
    int isScenario;
    int count;

    isScenario = (state == 0);
    if (isScenario) {
        missionTitle->setVisible(1);
        missionText->setVisible(1);
    } else {
        missionTitle->setVisible(0);
        missionText->setVisible(0);
    }

    mapTypeDrop->setVisible(isScenario == 0);
    mapTypeLabel->setVisible(isScenario == 0);
    mapSizeDrop->setVisible(isScenario == 0);
    mapSizeLabel->setVisible(isScenario == 0);

    if (scenarioList->get_id() == -1) {
        resourcesDrop->setVisible(0);
        resourcesLabel->setVisible(0);
    } else {
        resourcesDrop->setVisible(1);
        resourcesLabel->setVisible(1);
    }

    activateVictoryPanels();
    count = 0;
    if (rge_base_game->multiplayerGame() != 0) {
        tabList[0] = scenarioList;
        count = 1;
    }
    tabList[count] = okButton;
    count++;
    tabList[count] = cancelButton;
    count++;
    setTabList(tabList, count);

    if (field_3C == 0 || *(int*)((char*)field_3C + 0x6C) == 0) {
        set_curr_child(okButton);
    }
}
