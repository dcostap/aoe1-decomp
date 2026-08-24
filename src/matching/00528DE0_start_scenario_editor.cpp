// VA: 00528DE0 TRIBE_Game::start_scenario_editor (374 B)
// PDB source: tribegam.cpp:4365-4412
// FLAGS: config/flags/00528DE0_start_scenario_editor.rsp
//
// Attempt log:
// - Initial scaffold omitted the two source parameters, constructor/EH
//   ownership, fallback panel selection, music cleanup, and mouse centering.
// - Baseline follows the same-TU save-for-scenario-editor donor: /GX, a
//   typed TRIBE_Screen_Sed new-expression of size 0x948, and natural typed
//   panel/music/mouse calls.
// - The first compile exposed a missing polymorphic vptr (0x944 allocation and
//   +0xD4 flag); declaring the proven screen destructor restored +0xD8/0x948
//   and produced the exact 374-byte function.
// - Main-agent audit confirmed canonical editor/game/music/mouse ownership and
//   natural fallback flow; exact bytes were revalidated after promotion.

#ifndef TRIBEGAM_TU_CONTEXT
class TPanel {
};
class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TMusic_System {
public:
    int stop_track();
};

class TMousePointer {
public:
    void center();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x64 - 0x04];
    TMusic_System* music; // +0x64
    char gap_68[0x1C0 - 0x68];
    TMousePointer* mouse_pointer; // +0x1C0
    char gap_1C4[0xC1C - 0x1C4];
    int started_menu_music; // +0xC1C

    void disable_input();
    void enable_input();
};

class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed();
    char gap_04[0xD8 - 0x04];
    int need_to_save_flag; // +0xD8
    char gap_DC[0x948 - 0xDC];

    TRIBE_Screen_Sed(char* scenario_filename, int mode);
};

void* operator new(unsigned int size);

class TRIBE_Game : public RGE_Base_Game {
public:
    int start_scenario_editor(char* scenario_filename, int mode);
};
#endif

int TRIBE_Game::start_scenario_editor(char* scenario_filename, int mode)
{
    this->disable_input();
    panel_system.destroyPanel("Scenario Editor Screen");

    TRIBE_Screen_Sed* editor =
        new TRIBE_Screen_Sed(scenario_filename, mode);
    if (editor != 0 && editor->need_to_save_flag == 0) {
        if (this->music_system != 0) {
            this->music_system->stop_track();
            this->started_menu_music = 0;
        }

        panel_system.setCurrentPanel("Scenario Editor Screen", 0);
        panel_system.destroyPanel("Scenario Editor Open");
        panel_system.destroyPanel("Scenario Editor Menu");
        panel_system.destroyPanel("Status Screen");
        this->mouse_pointer->center();
        this->enable_input();
        return 1;
    }

    if (panel_system.panel("Scenario Editor Open") != 0) {
        panel_system.setCurrentPanel("Scenario Editor Open", 0);
    } else if (panel_system.panel("Scenario Editor Menu") != 0) {
        panel_system.setCurrentPanel("Scenario Editor Menu", 0);
    } else {
        panel_system.setCurrentPanel("Blank Screen", 0);
    }

    panel_system.destroyPanel("Scenario Editor Screen");
    panel_system.destroyPanel("Status Screen");
    this->enable_input();
    return 0;
}
