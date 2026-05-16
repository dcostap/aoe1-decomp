// 004B42E0 TribeSelectScenarioScreen::action
// Attempt log:
// 1: initial natural implementation with local class/member surfaces and /GX hypothesis for new+ctor EH: compile failed due explicit operator new declaration conflict.
// 2: remove operator new declaration and rely on builtin new: close (8.5% edit diff); main drift from action virtual slot emitted [eax] not [eax+0xB4], shifting tail 4 bytes.
// 3: pad TPanel vtable so action is slot 45 (+0xB4).

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    VPAD32(0)
    VPAD8(32)
    VPAD4(40)
    VPAD1(44)
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void set_curr_child(TPanel* child);
};

class RGE_Base_Game {
public:
    void close();
    void disable_input();
};
extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int arg);
    int destroyPanel(char* name);
};
extern TPanelSystem panel_system;

class TribeMPSetupScreen { public: TribeMPSetupScreen(); char pad[0x890]; };
class TribeSPMenuScreen { public: TribeSPMenuScreen(); char pad[0x49c]; };

class TribeSelectScenarioScreen : public TPanel {
public:
    char gap_004[0x494-4];
    TPanel* scenarioList;
    char gap_498[0x4A8-0x498];
    int scenariosLoaded;
    char gap_4AC[0x4C8-0x4AC];
    TPanel* okButton;
    TPanel* cancelButton;
    TPanel* closeButton;

    void sendSettings();
    void fillMissionText();
    void activatePanels();
    virtual long action(TPanel* panel, long event, unsigned long p3, unsigned long p4);
};

long TribeSelectScenarioScreen::action(TPanel* panel, long event, unsigned long p3, unsigned long p4)
{
    if (panel != 0 && this->scenariosLoaded != 0) {
        if (panel == this->okButton && event == 1) {
            this->set_curr_child(this->scenarioList);
            this->sendSettings();
            rge_base_game->disable_input();
            new TribeMPSetupScreen;
            panel_system.setCurrentPanel((char*)0x5861AC, 0);
            panel_system.destroyPanel((char*)0x5868B0);
            return 1;
        }
        if (panel == this->cancelButton && event == 1) {
            this->set_curr_child(this->scenarioList);
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel((char*)0x586638, 0);
            panel_system.destroyPanel((char*)0x5868B0);
            return 1;
        }
        if (panel == this->closeButton && event == 1) {
            rge_base_game->close();
            return 1;
        }
        if (panel == this->scenarioList) {
            if (event == 3) {
                this->action(this->okButton, 1, 0, 0);
                return 1;
            }
            if (event == 1) {
                this->fillMissionText();
                this->activatePanels();
                return 1;
            }
        }
    }
    return TPanel::action(panel, event, p3, p4);
}
