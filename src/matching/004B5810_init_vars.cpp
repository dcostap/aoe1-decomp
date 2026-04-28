// 004B5810 TribeGameSettingsScreen::init_vars
// Size: 271 bytes (0x10F)

class TTextPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TribeMPSetupScreen;

class TPanel {
public:
    char gap_00[0xF4];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384]; // 0x478 - 0xF4
};

class TScreenPanel : public TEasy_Panel {
public:
    // no additional fields beyond TEasy_Panel
};

class TribeGameSettingsScreen : public TScreenPanel {
public:
    TTextPanel* title; // +0x478
    int state; // +0x47C (not zeroed)
    TTextPanel* mapSizeLabel; // +0x480
    TDropDownPanel* mapSizeDrop; // +0x484
    TTextPanel* mapTypeLabel; // +0x488
    TDropDownPanel* mapTypeDrop; // +0x48C
    TTextPanel* victoryTypeLabel; // +0x490
    TDropDownPanel* victoryTypeDrop; // +0x494
    TTextPanel* victoryFixedText; // +0x498
    TTextPanel* percentLabel; // +0x49C (not zeroed)
    TTextPanel* scoreLabel; // +0x4A0
    TDropDownPanel* scoreDrop; // +0x4A4
    TTextPanel* timeLabel; // +0x4A8
    TDropDownPanel* timeDrop; // +0x4AC
    TTextPanel* difficultyLabel; // +0x4B0
    TDropDownPanel* difficultyDrop; // +0x4B4
    TTextPanel* ageLabel; // +0x4B8
    TDropDownPanel* ageDrop; // +0x4BC
    TTextPanel* resourcesLabel; // +0x4C0
    TDropDownPanel* resourcesDrop; // +0x4C4
    TTextPanel* pathingLabel; // +0x4C8
    TDropDownPanel* pathingDrop; // +0x4CC
    TTextPanel* limitLabel; // +0x4D0
    TDropDownPanel* limitDrop; // +0x4D4
    TTextPanel* scenarioTitle; // +0x4D8
    TTextPanel* scenarioPlayersTitle; // +0x4DC
    int scenarioListX; // +0x4E0 (not zeroed)
    int scenarioListY; // +0x4E4 (not zeroed)
    int scenarioListWidth; // +0x4E8 (not zeroed)
    int scenarioListHeight; // +0x4EC (not zeroed)
    TListPanel* scenarioList; // +0x4F0
    TScrollBarPanel* scenarioScrollbar; // +0x4F4
    int scenarioCount; // +0x4F8
    char** scenarioMission; // +0x4FC
    int* scenarioFixed; // +0x500
    int scenariosLoaded; // +0x504
    TTextPanel* missionTitle; // +0x508
    int missionTextX; // +0x50C (not zeroed)
    int missionTextY; // +0x510 (not zeroed)
    int missionTextWidth; // +0x514 (not zeroed)
    int missionTextHeight; // +0x518 (not zeroed)
    TTextPanel* missionText; // +0x51C
    TScrollBarPanel* missionScrollbar; // +0x520
    TButtonPanel* optionButton[4]; // +0x524
    TTextPanel* optionText[4]; // +0x534
    TButtonPanel* okButton; // +0x544
    TButtonPanel* cancelButton; // +0x548
    TButtonPanel* help_button; // +0x54C
    TribeMPSetupScreen* chat_scr; // +0x550
    int last_scenario_line; // +0x554
    int scenario_line_offset; // +0x558
    unsigned long last_send_shared; // +0x55C

    void init_vars(void);
};

void TribeGameSettingsScreen::init_vars(void) {
    this->title = 0;
    this->mapSizeLabel = 0;
    this->mapSizeDrop = 0;
    this->mapTypeLabel = 0;
    this->mapTypeDrop = 0;
    this->victoryTypeLabel = 0;
    this->victoryTypeDrop = 0;
    this->scoreLabel = 0;
    this->scoreDrop = 0;
    this->timeLabel = 0;
    this->timeDrop = 0;
    this->victoryFixedText = 0;
    this->difficultyLabel = 0;
    this->difficultyDrop = 0;
    this->ageLabel = 0;
    this->ageDrop = 0;
    this->limitLabel = 0;
    this->limitDrop = 0;
    this->resourcesLabel = 0;
    this->resourcesDrop = 0;
    this->pathingLabel = 0;
    this->pathingDrop = 0;
    this->scenarioTitle = 0;
    this->scenarioPlayersTitle = 0;
    this->scenarioList = 0;
    this->scenarioScrollbar = 0;
    this->scenarioCount = 0;
    this->scenarioMission = 0;
    this->scenarioFixed = 0;
    this->scenariosLoaded = 0;
    this->missionTitle = 0;
    this->missionText = 0;
    this->missionScrollbar = 0;

    {
        int i;
        for (i = 0; i < 4; i++) {
            this->optionButton[i] = 0;
            this->optionText[i] = 0;
        }
    }

    this->okButton = 0;
    this->cancelButton = 0;
    this->help_button = 0;
    this->chat_scr = 0;
    this->last_scenario_line = -1;
    this->scenario_line_offset = 0;
    this->last_send_shared = 0;
}
