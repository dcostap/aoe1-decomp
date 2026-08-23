// VA: 0048FA40 TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen()
// PDB source: scr_cam.cpp lines 150-205
// attempt 1: natural virtual destructor with panel_system destroyPanel calls and scalar deletes in source order.

#include "../../include/scr_cam_context.h"

#if 0

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TPanel {
public:
    virtual ~TPanel();
};

class TRIBE_Campaign_Editor_Screen : public TScreenPanel {
public:
    char gap_004[0x478];
    TPanel* title;                         // +0x47C
    TPanel* filename_title;                // +0x480
    TPanel* scenarios_title;               // +0x484
    TPanel* campaign_scenarios_title;      // +0x488
    TPanel* scenarios;                     // +0x48C
    TPanel* campaign_scenarios;            // +0x490
    TPanel* scenarios_bar;                 // +0x494
    TPanel* campaign_scenarios_bar;        // +0x498
    TPanel* filename;                      // +0x49C
    TPanel* ok_button;                     // +0x4A0
    TPanel* cancel_button;                 // +0x4A4
    TPanel* save_button;                   // +0x4A8
    TPanel* add_button;                    // +0x4AC
    TPanel* remove_button;                 // +0x4B0
    TPanel* move_scenario_up_button;       // +0x4B4
    TPanel* move_scenario_down_button;     // +0x4B8
    TPanel* filename_drop;                 // +0x4BC

    virtual ~TRIBE_Campaign_Editor_Screen();
};
#endif

TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen()
{
    panel_system.destroyPanel("Cancel Dialog");
    panel_system.destroyPanel("Load Dialog");

    delete this->title;
    delete this->scenarios_title;
    delete this->campaign_scenarios_title;
    delete this->scenarios;
    delete this->scenarios_bar;
    delete this->campaign_scenarios;
    delete this->campaign_scenarios_bar;
    delete this->filename_title;
    delete this->filename;
    delete this->filename_drop;
    delete this->cancel_button;
    delete this->save_button;
    delete this->ok_button;
    delete this->add_button;
    delete this->remove_button;
    delete this->move_scenario_up_button;
    delete this->move_scenario_down_button;
}
