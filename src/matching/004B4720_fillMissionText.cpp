// probe 3: use the real setText vtable slot surface from the sibling fillMissionText match

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TTextPanel {
public:
    VPAD32(0)
    VPAD16(32)
    VPAD8(48)
    VPAD1(56)
    VPAD1(57)
    virtual void setText(char* text);

    long get_line();
};

class TribeSelectScenarioScreen {
public:
    char gap_00[0x494];
    TTextPanel* scenarioList;
    char gap_498[0x8];
    char** scenarioMission;
    char gap_4A4[0x1C];
    TTextPanel* missionText;
    char gap_4C4[0x10];
    int last_scenario_line;

    void fillMissionText();
};

void TribeSelectScenarioScreen::fillMissionText() {
    long line;

    this->missionText->setText((char*)0x592A40);
    line = this->scenarioList->get_line();
    if (line >= 0) {
        this->missionText->setText(this->scenarioMission[line]);
    }
    this->last_scenario_line = line;
}
