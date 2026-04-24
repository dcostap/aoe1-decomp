// attempt 1: __thiscall on extern declarations - VC5 ignores it, still __cdecl
// attempt 2: use member functions so VC5 knows to use __thiscall

class RGE_Base_Game {
public:
    char* scenarioName();
};

class TTextPanel {
public:
    long get_line(char*);
};

class TListPanel {
public:
    void scroll_cur_line(unsigned char, long, unsigned char);
};

class TribeSelectScenarioScreen {
public:
    char pad_000[0x494];
    TListPanel* scenarioList;
    char pad_498[0x3C];
    long last_scenario_line;

    void getSettings();
};

void TribeSelectScenarioScreen::getSettings() {
    this->last_scenario_line = -1;

    RGE_Base_Game* game = *(RGE_Base_Game**)0x62C574;
    char* scenarioName = game->scenarioName();

    long line = ((TTextPanel*)this->scenarioList)->get_line(scenarioName);

    if (line != -1) {
        this->scenarioList->scroll_cur_line(1, line, 1);
        this->last_scenario_line = line - 1;
    } else {
        this->scenarioList->scroll_cur_line(1, 0, 1);
    }
}
