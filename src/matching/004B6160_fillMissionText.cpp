// 004B6160 TribeGameSettingsScreen::fillMissionText
// Size: 197 bytes (0xC5)

class TTextPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);          // vtable+0xE0
    virtual void setStringID(int id); // vtable+0xE4
    virtual void setText(const char* s); // vtable+0xE8

    long get_line();   // 0047E1E0
    int get_id();      // 0047E330
};

class TDropDownPanel {
public:
    void set_line(long param);  // 00475250
};

class TPanel {
public:
    char gap_00[0xF4];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
};

class TScrollBarPanel;
class TButtonPanel;
class TribeMPSetupScreen;

class TribeGameSettingsScreen : public TScreenPanel {
public:
    TTextPanel* title;              // +0x478
    int state;                      // +0x47C
    TTextPanel* mapSizeLabel;       // +0x480
    TDropDownPanel* mapSizeDrop;    // +0x484
    TTextPanel* mapTypeLabel;       // +0x488
    TDropDownPanel* mapTypeDrop;    // +0x48C
    TTextPanel* victoryTypeLabel;   // +0x490
    TDropDownPanel* victoryTypeDrop;// +0x494
    TTextPanel* victoryFixedText;   // +0x498
    TTextPanel* percentLabel;       // +0x49C
    TTextPanel* scoreLabel;         // +0x4A0
    TDropDownPanel* scoreDrop;      // +0x4A4
    TTextPanel* timeLabel;          // +0x4A8
    TDropDownPanel* timeDrop;       // +0x4AC
    TTextPanel* difficultyLabel;    // +0x4B0
    TDropDownPanel* difficultyDrop; // +0x4B4
    TTextPanel* ageLabel;           // +0x4B8
    TDropDownPanel* ageDrop;        // +0x4BC
    TTextPanel* resourcesLabel;     // +0x4C0
    TDropDownPanel* resourcesDrop;  // +0x4C4
    TTextPanel* pathingLabel;       // +0x4C8
    TDropDownPanel* pathingDrop;    // +0x4CC
    TTextPanel* limitLabel;         // +0x4D0
    TDropDownPanel* limitDrop;      // +0x4D4
    TTextPanel* scenarioTitle;      // +0x4D8
    TTextPanel* scenarioPlayersTitle;// +0x4DC
    int scenarioListX;              // +0x4E0
    int scenarioListY;              // +0x4E4
    int scenarioListWidth;          // +0x4E8
    int scenarioListHeight;         // +0x4EC
    TTextPanel* scenarioList;       // +0x4F0
    TScrollBarPanel* scenarioScrollbar; // +0x4F4
    int scenarioCount;              // +0x4F8
    char** scenarioMission;         // +0x4FC
    int* scenarioFixed;             // +0x500
    int scenariosLoaded;            // +0x504
    TTextPanel* missionTitle;       // +0x508
    int missionTextX;               // +0x50C
    int missionTextY;               // +0x510
    int missionTextWidth;           // +0x514
    int missionTextHeight;          // +0x518
    TTextPanel* missionText;        // +0x51C
    TScrollBarPanel* missionScrollbar; // +0x520
    TButtonPanel* optionButton[4];  // +0x524
    TTextPanel* optionText[4];      // +0x534
    TButtonPanel* okButton;         // +0x544
    TButtonPanel* cancelButton;     // +0x548
    TButtonPanel* help_button;      // +0x54C
    TribeMPSetupScreen* chat_scr;   // +0x550
    int last_scenario_line;         // +0x554
    int scenario_line_offset;       // +0x558
    unsigned long last_send_shared; // +0x55C

    void fillMissionText(void);
};

void TribeGameSettingsScreen::fillMissionText(void) {
    long line;
    int id;

    this->missionText->setText("");
    line = this->scenarioList->get_line();
    id = this->scenarioList->get_id();

    if (id == -2) {
        this->missionText->setStringID(0x25DC);
    } else if (id == -1) {
        this->missionText->setStringID(0x2618);
    } else {
        this->missionText->setText(this->scenarioMission[this->scenario_line_offset + line]);
    }

    if (line != this->last_scenario_line) {
        this->victoryTypeDrop->set_line(0);
    }

    if (id < 0) {
        this->state = 1;
        this->last_scenario_line = line;
        return;
    }

    this->last_scenario_line = line;
    this->state = 0;
}
