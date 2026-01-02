#pragma once
#include "../common.h"

class TRIBE_Campaign_Editor_Screen : public TScreenPanel {
public:
    uchar need_to_save;                      // 0x478
    TTextPanel* title;                       // 0x47C
    TTextPanel* filename_title;              // 0x480
    TTextPanel* scenarios_title;             // 0x484
    TTextPanel* campaign_scenarios_title;    // 0x488
    TListPanel* scenarios;                   // 0x48C
    TListPanel* campaign_scenarios;          // 0x490
    TScrollBarPanel* scenarios_bar;          // 0x494
    TScrollBarPanel* campaign_scenarios_bar; // 0x498
    TEditPanel* filename;                    // 0x49C
    TButtonPanel* ok_button;                 // 0x4A0
    TButtonPanel* cancel_button;             // 0x4A4
    TButtonPanel* save_button;               // 0x4A8
    TButtonPanel* add_button;                // 0x4AC
    TButtonPanel* remove_button;             // 0x4B0
    TButtonPanel* move_scenario_up_button;   // 0x4B4
    TButtonPanel* move_scenario_down_button; // 0x4B8
    TDropDownPanel* filename_drop;           // 0x4BC
    RGE_Campaign* campaign;                  // 0x4C0

    TRIBE_Campaign_Editor_Screen();
    virtual ~TRIBE_Campaign_Editor_Screen();
    virtual void fill_campaign_drop();
    virtual void fill_scenario_list();
    virtual void fill_campaign_scenario_list();
    virtual uchar check_lists();
    virtual void load_campaign();
    virtual void make_campaign();
    virtual void add_scenario();
    virtual void remove_scenario();
    virtual void move_scenario_up();
    virtual void move_scenario_down();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TRIBE_Campaign_Editor_Screen) == 0x4C4, "TRIBE_Campaign_Editor_Screen Size Mismatch");
static_assert(offsetof(TRIBE_Campaign_Editor_Screen, campaign) == 0x4C0, "TRIBE_Campaign_Editor_Screen Offset Mismatch");

