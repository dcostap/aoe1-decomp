// VA: 005213A0 TRIBE_Game::~TRIBE_Game (625 B)
// PDB source: tribegam.cpp (lines 347-413)
// Attempt log:
// baseline: replaced the destructor scaffold with natural virtual/base
// destruction, window cleanup, exact panel/resource teardown order, and the
// StringTableX FreeLibrary guard.
// layout: corrected windows_mouse to the inherited +0x1DC field; the natural
// destructor then produced an exact 625-byte match with all 37 ordered calls.

extern "C" {
    __declspec(dllimport) int __stdcall DestroyWindow(void* window);
    __declspec(dllimport) int __stdcall FreeLibrary(void* module);
}

extern void* StringTableX;
extern void __cdecl RESFILE_close_new_resource_file(const char* name);

#include "../../include/tribegam_context.h"

#if 0
class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x1AC];
    int prog_mode; // +0x1B0
    char gap_1B4[0x28];
    void* windows_mouse; // +0x1DC
    char gap_1E0[0xA24 - 0x1E0];
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x1250 - 0xA24];
    int inHandleIdle; // +0x1250

    virtual ~TRIBE_Game();
    void close_game_screens(int destroy_game_screen);
};
#endif

TRIBE_Game::~TRIBE_Game()
{
    this->inHandleIdle = 0;
    this->prog_mode = 0;

    if (this->windows_mouse != 0) {
        DestroyWindow(this->windows_mouse);
        this->windows_mouse = 0;
    }

    this->close_game_screens(1);

    panel_system.destroyPanel("Video Screen");
    panel_system.destroyPanel("Create Dialog");
    panel_system.destroyPanel("Campaign Editor Screen");
    panel_system.destroyPanel("Game Setup Screen");
    panel_system.destroyPanel("Game Settings Screen");
    panel_system.destroyPanel("Select Scenario Screen");
    panel_system.destroyPanel("Campaign Selection Screen");
    panel_system.destroyPanel("Load Saved Game Screen");
    panel_system.destroyPanel("MP Startup Screen");
    panel_system.destroyPanel("MP Setup Screen");
    panel_system.destroyPanel("Connecting Screen");
    panel_system.destroyPanel("Join Screen");
    panel_system.destroyPanel("Main Menu");
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("End Screen");
    panel_system.destroyPanel("Scenario Editor Menu");
    panel_system.destroyPanel("Scenario Editor Open");
    panel_system.destroyPanel("Scenario Editor Screen");
    panel_system.destroyPanel("Single Player Menu");
    panel_system.destroyPanel("New Name Dialog");
    panel_system.destroyPanel("Name Selection Screen");
    panel_system.destroyPanel("Status Screen");
    panel_system.destroyPanel("Temp Screen");
    panel_system.destroyPanel("ScenarioEditorInfo");
    panel_system.destroyPanel("FeaturesInfo");
    panel_system.destroyPanel("QuotesInfo");
    panel_system.destroyPanel("Logo1Screen");
    panel_system.destroyPanel("Logo2Screen");

    RESFILE_close_new_resource_file("sounds.drs");
    RESFILE_close_new_resource_file("graphics.drs");
    RESFILE_close_new_resource_file("Terrain.drs");
    RESFILE_close_new_resource_file("Border.drs");
    RESFILE_close_new_resource_file("Interfac.drs");

    if (StringTableX != 0) {
        FreeLibrary(StringTableX);
        StringTableX = 0;
    }
}
