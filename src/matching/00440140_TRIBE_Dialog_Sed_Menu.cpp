// 00440140 TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu
// Source: dlg_sedm.cpp lines 41-58
// Size: 505 bytes
//
// Recovered layout and lifetime:
// - TDialogPanel ends at +0x490. The derived fields are parent_field (+0x490),
//   title (+0x494), and seven button slots (+0x498 through +0x4B0).
// - The base constructor runs first. The initializer list stores parent_field
//   and title before VC5 writes the derived vtable at +0x0.
// - /GX creates the original EH registration and one common failure return.
//   Setup and each button call return through that common path.
// - setup evaluates its arguments right to left. It calls popup id, popup file,
//   and renderArea before it calls setup. create_button takes parent first and
//   the output slot second.
// - The final button pointer stays in a local before both hotkey stores.
//
// Attempt log:
// Probe 1: natural typed layout baseline; /GX was already required for EH.
// Probe 2: omitting explicit virtual on the derived destructor changed no code.
// Probe 3: moved parent and title to the initializer list; diff fell to 374.
// Probe 4: passed popup calls directly to setup; diff fell to 100 and size to +2.
// Probe 5: kept the final button in a local; diff fell to 61 and size matched.
// Probe 6: corrected create_button argument order; exact 505-byte match.
// FLAGS: /GX (config/flags/00440140_TRIBE_Dialog_Sed_Menu.rsp; needed for EH prologue;
// default flags produce no EH frame — tested and failed)

#include "../../include/game_globals.h"

#ifndef DLG_SEDM_SHARED_CONTEXT
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
    int setup(void* renderArea, void* param1, int width, int height,
              char* file, int info_id, int modal);
    int create_button(TPanel* parent, TButtonPanel** button_ptr, int string_id,
                      int x, int y, int w, int h, int a, int b, int c, int d);
};

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor; // +0x490
    TPanel* title;          // +0x494
    TButtonPanel* buttons[7]; // +0x498 to +0x4B0

    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1);
    virtual ~TRIBE_Dialog_Sed_Menu();
};
#endif

TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1)
    : TDialogPanel("Scenario Menu Dialog"), scenario_editor(param_1), title(0)
{
    int i;

    i = 0;
    while (i < 7) {
        this->buttons[i] = 0;
        i++;
    }

    if (this->setup(param_1->renderArea(), param_1, 0x1CC, 0x190,
                    param_1->get_popup_info_file(),
                    param_1->get_popup_info_id(), 1) == 0)
        return;

    if (this->create_button(this, &this->buttons[0], 0x2443, 0, 0x1E, 0x14, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[1], 0x2441, 0, 0x1E, 0x46, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[2], 0x2442, 0, 0x1E, 0x78, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[3], 0x2445, 0, 0x1E, 0xAA, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[4], 0x242E, 0, 0x1E, 0xDC, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[5], 0x2446, 0, 0x1E, 0x10E, 0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[6], 0x2444, 0, 0x1E, 0x154, 0x190, 0x28, 0, 0, 0) == 0)
        return;

    TButtonPanel* cancel = (TButtonPanel*)this->buttons[6];
    cancel->field_298 = 0x1B;
    cancel->field_29C = 0;
}
