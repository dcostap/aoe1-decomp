#ifndef AOE1_SCR_CAM_H
#define AOE1_SCR_CAM_H

// PDB source module: C:\\msdev\\work\\age1_x1\\scr_cam.cpp.
// This header owns only the campaign editor screen. Shared panel, screen,
// control, campaign, and game declarations stay in their owner headers.
#include "Pnl_scr.h"

class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TEditPanel;
class TDropDownPanel;
class RGE_Campaign;

class TRIBE_Campaign_Editor_Screen : public TScreenPanel {
public:
    unsigned char need_to_save;
    char gap_479[3];
    TTextPanel* title;
    TTextPanel* filename_title;
    TTextPanel* scenarios_title;
    TTextPanel* campaign_scenarios_title;
    TListPanel* scenarios;
    TListPanel* campaign_scenarios;
    TScrollBarPanel* scenarios_bar;
    TScrollBarPanel* campaign_scenarios_bar;
    TEditPanel* filename;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;
    TButtonPanel* save_button;
    TButtonPanel* add_button;
    TButtonPanel* remove_button;
    TButtonPanel* move_scenario_up_button;
    TButtonPanel* move_scenario_down_button;
    TDropDownPanel* filename_drop;
    RGE_Campaign* campaign;

    TRIBE_Campaign_Editor_Screen();
    virtual ~TRIBE_Campaign_Editor_Screen();

protected:
    void fill_campaign_drop();
    void fill_scenario_list();
    void fill_campaign_scenario_list();
    unsigned char check_lists();
    void load_campaign();
    void make_campaign();
    void add_scenario();
    void remove_scenario();
    void move_scenario_up();
    void move_scenario_down();
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
};

typedef char scr_cam_screen_size_check[
    (sizeof(TRIBE_Campaign_Editor_Screen) == 0x4C4) ? 1 : -1];

#endif
