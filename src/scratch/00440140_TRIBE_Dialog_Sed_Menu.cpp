// 00440140 TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu
// Source: dlg_sedm.cpp lines 41-58
// Size: 505 bytes
//
// Attempt log:
// Probe 1: skeleton, compile errors
// Probe 2: fix params/ctor syntax
// Probe 3: /GX flag for EH prologue -> EH matches, ~69% remaining
//          Remaining: instruction scheduling/register cascade.
// Left in scratch.
// FLAGS: /GX (config/flags/00440140_TRIBE_Dialog_Sed_Menu.rsp; needed for EH prologue;
// default flags produce no EH frame — tested and failed)

#include "../../include/game_globals.h"

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
    void* renderArea();
};

class TButtonPanel : public TPanel {
public:
    char _gap_F4[0x1A4];
    int field_298;
    int field_29C;
    virtual ~TButtonPanel();
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x384];
    virtual ~TEasy_Panel();
};

class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    virtual ~TRIBE_Screen_Sed();
    int get_popup_info_id();
    char* get_popup_info_file();
    void* renderArea();
};

class TDialogPanel : public TEasy_Panel {
public:
    char _gap_478[0x18];
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    int setup(void* renderArea, void* param1, int a, int b, int c, int d, int e);
    int create_button(TPanel** button_ptr, TPanel* parent, int string_id, int x, int y, int w, int h, int a, int b, int c, int d);
};

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TPanel* parent_field;   // +0x490
    TPanel* title;          // +0x494
    TPanel* buttons[7];     // +0x498 to +0x4B0

    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1);
    virtual ~TRIBE_Dialog_Sed_Menu();
};

TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1)
    : TDialogPanel("Scenario Menu Dialog")
{
    int id;
    char* file;
    int i;
    void* area;

    this->parent_field = param_1;
    this->title = 0;

    i = 0;
    while (i < 7) {
        this->buttons[i] = 0;
        i++;
    }

    id = param_1->get_popup_info_id();
    file = param_1->get_popup_info_file();
    area = param_1->renderArea();

    if (this->setup(area, param_1, 0x1CC, 0x190, (int)file, id, 1) == 0)
        return;

    if (this->create_button(&this->buttons[0], this, 0x2443, 0, 0x1E, 0x14, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(&this->buttons[1], this, 0x2441, 0, 0x1E, 0x46, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(&this->buttons[2], this, 0x2442, 0, 0x1E, 0x78, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(&this->buttons[3], this, 0x2445, 0, 0x1E, 0xAA, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(&this->buttons[4], this, 0x242E, 0, 0x1E, 0xDC, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(&this->buttons[5], this, 0x2446, 0, 0x1E, 0x10E, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(&this->buttons[6], this, 0x2444, 0, 0x1E, 0x154, 0x190, 0x28, 0, 0, 0) == 0)
        return;

    ((TButtonPanel*)this->buttons[6])->field_298 = 0x1B;
    ((TButtonPanel*)this->buttons[6])->field_29C = 0;
}
