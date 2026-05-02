// tried a direct high-level translation with virtual setText/get_line; vcall landed at slot 0 instead of +0xE8
// tried a manual vtable call; got the right behavior but wrong call shape and extra code in the prolog
// remaining mismatch is the first setText dispatch slot / TU codegen around the missionText clear call
class TTextPanel {
public:
    virtual void setText(char* text);
    virtual long get_line();
};

class TListPanel : public TTextPanel {
};

class TribeSelectScenarioScreen {
public:
    char gap_00[0x494];
    TListPanel* scenarioList;
    char gap_498[0x8];
    char** scenarioMission;
    char gap_4A4[0x1C];
    TTextPanel* missionText;
    char gap_4C4[0x10];
    int last_scenario_line;

    void fillMissionText();
};

void TribeSelectScenarioScreen::fillMissionText()
{
    long line;

    this->missionText->setText((char*)0x592A40);
    line = this->scenarioList->get_line();
    if (line >= 0)
        this->missionText->setText(this->scenarioMission[line]);
    this->last_scenario_line = line;
}
