// VA 004909D0 TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection
// scr_cams.cpp:48-125
// Attempt log:
// 1: Natural constructor from packet/decompiler, with /GX expected for EH frame.
// 2: Added TScreenPanel/TEasy_Panel inheritance and create_text/list/scrollbar/dropdown/button surfaces; first build exact size but broad due base size wrong.
// 3: Added TPanel 0xF0 payload so derived member offsets land at +0x478..+0x4C8; mismatch improved to 17.57%, first mismatch branch displacement near first create_text failure target.
// 4: Removed explicit tabList[0]=this after base ctor; this eliminated an extra mov after EH state and improved to 17.57% -> 17.57% with first mismatch later (offset 202), matching the main constructor body through early widget creation.
// 5: Modeled virtual set_string at vtable +0xE4 and close-button virtual calls at +0x14/+0x18; direct call order now matches large middle region.
// 6: Tried local cancel pointer for hotkey/hotkey_shift before close-button creation; compiler delayed stores across argument pushes and shifted close-button block.
// 7: Tried closePtr local for &close_button; no codegen change.
// 8: Found tab-order source needs five entries plus a cancel-button value in the adjacent local slot; array[6]/out-of-bounds tabList[5] improved body to 2.6679% but forced stack frame sub esp,1C instead of original sub esp,18.
// 9: Tried removing cancel local/direct cancelButton hotkey stores; stack stayed 1C or broad block regressed.
// 10: Tried separate cancelTab local instead of tabList[5]; restored sub esp,18 but lost the near-exact tab-order block, leaving 12.5115% mismatch, first mismatch offset 202.
// 11: Replaced cancelTab and the decompiler index order with one late five-element TPanel array in campaign, scenario, dropdown, cancel, ok slot order; set_tab_order now receives its base. This restored the original frame and reduced the mismatch to 13 bytes.
// 12: Aggregate initialization, assignment permutations, and late declaration checks did not change the 13-byte result or improve the clean source model.
// PAUSED: exact call set, size, frame, CFG, and all earlier blocks match. Remaining drift is the localized cancel/ok load scheduling at the array stores (+03D4..+03E3); no source-plausible lead remains in this session.
// FLAGS: /GX

class TPanel {
public:
    virtual ~TPanel();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void enable(int); // +14
    virtual void setup_colours(int,int,int,int,int,int,int,int,int,int,int,int,int); // +18
#define TPAD(n) virtual void p##n();
    TPAD(1) TPAD(2) TPAD(3) TPAD(4) TPAD(5) TPAD(6) TPAD(7) TPAD(8)
    TPAD(9) TPAD(10) TPAD(11) TPAD(12) TPAD(13) TPAD(14) TPAD(15) TPAD(16)
    TPAD(17) TPAD(18) TPAD(19) TPAD(20) TPAD(21) TPAD(22) TPAD(23) TPAD(24)
    TPAD(25) TPAD(26) TPAD(27) TPAD(28) TPAD(29) TPAD(30) TPAD(31) TPAD(32)
    TPAD(33) TPAD(34) TPAD(35) TPAD(36) TPAD(37) TPAD(38) TPAD(39) TPAD(40)
    TPAD(41) TPAD(42) TPAD(43) TPAD(44) TPAD(45) TPAD(46) TPAD(47) TPAD(48)
    TPAD(49) TPAD(50)
#undef TPAD
    virtual void set_string(long id); // +E4 approximate
    char gap_004[0xF0];
    void set_tab_order(TPanel** list, int count);
    void set_curr_child(TPanel* p);
};

class TDrawArea;
class TScreenPanel : public TPanel {
public:
    char gap_F4[0x384];
    TScreenPanel(char* name);
    long setup(TDrawArea* area, char* prefix, int id, int flag);
};

class TTextPanel : public TPanel { public: char gap[0x68]; int zero_15c; };
class TDropDownPanel : public TPanel {
public:
    void empty_list();
    int append_line(long id, long data);
    long get_line(long data);
    void set_line(long line);
};
class TButtonPanel : public TPanel { public: char gap[0x1A4]; int hotkey; int hotkey_shift; };

class TEasy_Panel : public TScreenPanel {
public:
    TEasy_Panel(char* name) : TScreenPanel(name) {}
    void setup_shadow_area(int);
    void set_ideal_size(long,long);
    int create_text(TPanel*, TPanel**, long, long, long, long, long, long, long, long, long);
    int create_list(TPanel*, TPanel**, long, long, long, long, long);
    int create_auto_scrollbar(TPanel**, TTextPanel*, long);
    int create_drop_down(TPanel*, TPanel**, long, long, long, long, long, long, long);
    int create_button(TPanel*, TPanel**, long, long, long, long, long, long, long, long, long);
};
class RGE_Base_Game { public: char gap[0x4c]; TDrawArea* draw_area; int difficulty(); };
extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Campaign_Selection : public TEasy_Panel {
public:
    TPanel* title;               // +0x478
    int campaignListX; int campaignListY; int campaignListWidth; int campaignListHeight;
    TPanel* campaignTitle;       // +0x48C
    TTextPanel* campaignList;    // +0x490
    TPanel* campaignScrollbar;   // +0x494
    int scenarioListX; int scenarioListY; int scenarioListWidth; int scenarioListHeight;
    TPanel* scenarioTitle;       // +0x4A8
    TTextPanel* scenarioList;    // +0x4AC
    TPanel* scenarioScrollbar;   // +0x4B0
    TPanel* difficultyTitle;     // +0x4B4
    TDropDownPanel* difficultyDrop; // +0x4B8
    TPanel* okButton;            // +0x4BC
    TButtonPanel* cancelButton;  // +0x4C0
    TPanel* close_button;        // +0x4C4
    int campaignsLoaded;         // +0x4C8

    TRIBE_Screen_Campaign_Selection();
    void init_vars();
    void fillCampaigns();
    void fillScenarios();
};

TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection()
    : TEasy_Panel("Campaign Selection Screen")
{
    *(int*)this = 0x5723D0;
    init_vars();
    if (!setup(rge_base_game->draw_area, "scr2", 0xC384, 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }
    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);
    if (create_text((TPanel*)this, &title, 0x2BCD, 0x14, 10, 600, 0x1E, 1, 1, 0, 0)) {
        campaignListX = 0x14; campaignListY = 0x46; campaignListWidth = 600; campaignListHeight = 0x82;
        if (create_list((TPanel*)this, (TPanel**)&campaignList, 0x14, 0x46, 600, 0x82, 0x0B)) {
            if (create_auto_scrollbar(&campaignScrollbar, campaignList, 0x14)) {
                if (create_text((TPanel*)this, &campaignTitle, 0x2BCE, campaignListX - 5, campaignListY - 0x14, 200, 0x14, 4, 0, 0, 0)) {
                    campaignList->set_string(0x2B5D);
                    scenarioListX = 0x14; scenarioListY = campaignListY + campaignListHeight + 0x1E; scenarioListWidth = 600; scenarioListHeight = 0x82;
                    if (create_list((TPanel*)this, (TPanel**)&scenarioList, scenarioListX, scenarioListY, scenarioListWidth, scenarioListHeight, 0x0B)) {
                        if (create_auto_scrollbar(&scenarioScrollbar, scenarioList, 0x14)) {
                            if (create_text((TPanel*)this, &scenarioTitle, 0x25FE, scenarioListX - 5, scenarioListY - 0x14, 200, 0x14, 4, 0, 0, 0)) {
                                scenarioList->zero_15c = 0;
                                if (create_text((TPanel*)this, &difficultyTitle, 0x2BCF, 0x0F, 0x172, 200, 0x14, 4, 0, 0, 0)) {
                                    if (create_drop_down((TPanel*)this, (TPanel**)&difficultyDrop, 0x82, 100, 0x14, 0x186, 0x82, 0x18, 0x0B)) {
                                        difficultyDrop->empty_list();
                                        difficultyDrop->append_line(0x2BD4, 4);
                                        difficultyDrop->append_line(0x2BD3, 3);
                                        difficultyDrop->append_line(0x2BD2, 2);
                                        difficultyDrop->append_line(0x2BD1, 1);
                                        difficultyDrop->append_line(0x2BD0, 0);
                                        difficultyDrop->set_line(difficultyDrop->get_line(rge_base_game->difficulty()));
                                        if (create_button((TPanel*)this, &okButton, 0x0FA1, 0, 0x46, 0x1B8, 0x0F0, 0x1E, 0, 0, 0)) {
                                            if (create_button((TPanel*)this, (TPanel**)&cancelButton, 0x0FA2, 0, 0x14A, 0x1B8, 0x0F0, 0x1E, 0, 0, 0)) {
                                                TButtonPanel* cancel = cancelButton;
                                                cancel->hotkey = 0x1B;
                                                cancel->hotkey_shift = 0;
                                                if (create_button((TPanel*)this, &close_button, 0x03EA, 0, 0, 0, 0, 0, -1, -1, 0)) {
                                                    close_button->enable(1);
                                                    close_button->setup_colours(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                                                    TPanel* tabList[5];
                                                    tabList[0] = campaignList;
                                                    tabList[1] = scenarioList;
                                                    tabList[2] = difficultyDrop;
                                                    tabList[3] = cancelButton;
                                                    tabList[4] = okButton;
                                                    set_tab_order(tabList, 5);
                                                    set_curr_child(okButton);
                                                    fillCampaigns();
                                                    fillScenarios();
                                                    set_curr_child(campaignList);
                                                    campaignsLoaded = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
