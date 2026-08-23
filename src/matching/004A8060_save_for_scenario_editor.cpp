// attempt 1: natural save-for-scenario-editor flow; default flags missed original EH frame and first stub had wrong scenario holder/new size
// attempt 2: use /GX, 0x490 Sed_Open size, scenario pointer at +0x5c, and virtual save at vtable +0xe4
// MODULE FLAGS: config/flags/scr_save.rsp

#include "../../include/scr_save_context.h"

#if 0
class TPanelSystem {
public:
    void* panel(char* name);
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Scenario {
public:
    void Set_scenario_name(char* name);
};

class ScenarioHolder {
public:
    char gap_0[0x58];
    RGE_Scenario* scenario;

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual bool save_scenario(char* name);
};

class TRIBE_Game {
public:
    char gap_0[0x3F4];
    ScenarioHolder* scenario_holder;

    void show_status_message(long id, long a, long b);
    int start_menu();
    void close();
    int start_scenario_editor(int a, int b);
};

extern TRIBE_Game* rge_base_game;

class TRIBE_Screen_Sed_Open {
public:
    char pad[0x490];

    TRIBE_Screen_Sed_Open();
};

void* operator new(unsigned int size);

class TribeSaveGameScreen {
public:
    char gap_0[0x494];
    char fileName[260];
    char gap_598[0x6A0 - 0x598];
    int quit_after_save;

    void popupOKDialog(long id, long a, long b, long c);
    void save_for_scenario_editor();
};
#endif

void TribeSaveGameScreen::save_for_scenario_editor() {
    ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, 0, -1);

    rge_base_game->world->scenario->Set_scenario_name(this->fileName);
    if (!rge_base_game->world->save_scenario(this->fileName)) {
        this->popupOKDialog(0x963, 0, 0x1C2, 100);
        return;
    }

    char* scenarioName = "Scenario Editor Screen";
    char* openName = "Scenario Editor Open";

    char* panel = (char*)panel_system.panel(scenarioName);
    if (panel != 0) {
        panel[0x4C0] = 0;
    }

    int quit = this->quit_after_save;
    if (quit == 1) {
        if (!((TRIBE_Game*)rge_base_game)->start_menu()) {
            ((TRIBE_Game*)rge_base_game)->close();
            return;
        }
        panel_system.destroyPanel(scenarioName);
    } else if (quit == 2) {
        TRIBE_Screen_Sed_Open* p = new TRIBE_Screen_Sed_Open;
        panel_system.setCurrentPanel(openName, 0);
    } else if (quit == 3) {
        ((TRIBE_Game*)rge_base_game)->start_scenario_editor(0, 0);
    } else {
        panel_system.setCurrentPanel(scenarioName, 0);
    }

    panel_system.destroyPanel("Status Screen");
    panel_system.destroyPanel("Save Game Screen");
}
