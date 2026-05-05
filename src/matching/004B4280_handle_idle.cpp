// attempt 2: minimal local class surface for exact handle_idle
class TPanel {
public:
    virtual long handle_idle();
    void set_curr_child(TPanel* child);
};
class RGE_Base_Game { public: char gap[0x1D8]; long input_enabled; void enable_input(); };
extern RGE_Base_Game* rge_base_game;
class TribeSelectScenarioScreen : public TPanel {
public:
    char gap_004[0x494-4];
    TPanel* scenarioList;
    char gap_498[0x4A8-0x498];
    long scenariosLoaded;
    void fillScenarios();
    void fillMissionText();
    void activatePanels();
    virtual long handle_idle();
};
long TribeSelectScenarioScreen::handle_idle() {
    if (this->scenariosLoaded == 0) {
        this->fillScenarios();
        this->fillMissionText();
        this->scenariosLoaded = 1;
        this->activatePanels();
        this->set_curr_child(this->scenarioList);
    }
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}
