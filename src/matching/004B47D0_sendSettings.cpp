class TTextPanel {
public:
    char* get_text(void);
};

class RGE_Base_Game {
public:
    void setScenarioGame(int value);
    void setScenarioName(char* name);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setDeathMatch(unsigned char value);
};

extern TRIBE_Game* rge_base_game;

class TribeSelectScenarioScreen {
public:
    char gap_00[0x494];
    TTextPanel* scenarioList;

    void sendSettings(void);
};

void TribeSelectScenarioScreen::sendSettings(void) {
    rge_base_game->setScenarioGame(1);
    rge_base_game->setScenarioName(this->scenarioList->get_text());
    rge_base_game->setDeathMatch(0);
}
