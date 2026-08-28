// 00440360 TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu
// Source: dlg_sedm.cpp lines 64-75
//
// Attempt log:
// Probe 1: close but esi/edi registers swapped for this vs loop pointer
// Probe 2: reorder locals to influence register allocation

#include "../../include/game_globals.h"

#ifndef DLG_SEDM_SHARED_CONTEXT
class TRIBE_Screen_Sed;
class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];
    virtual ~TPanel();
    void delete_panel(TPanel** panel_ptr);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
};
extern TPanelSystem panel_system;

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor; // +0x490
    TPanel* title;          // +0x494
    TButtonPanel* buttons[7]; // +0x498 to +0x4B0

    virtual ~TRIBE_Dialog_Sed_Menu();
};
#endif

TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu()
{
    panel_system.destroyPanel("Open Dialog");
    panel_system.destroyPanel("New Dialog");

    delete_panel(&this->title);

    int count = 7;
    TButtonPanel** pp = this->buttons;
    do {
        delete_panel((TPanel**)pp);
        pp++;
        count--;
    } while (count != 0);
}
