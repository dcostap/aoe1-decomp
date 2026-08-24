// VA: 0049EC00 ~TRIBE_Screen_Main_Menu dtor (203B)
// Scr_main.cpp lines 199-214
// EH-framed destructor: delete_panel for all sub-panels, then scalar delete for circle_p_pic and ms_title_text, then base dtor
// FLAGS: /GX (EH)

#include <windows.h>
#include "../../include/scr_main_context.h"

#if 0
class TPanel {
public:
    char __gap[0x1C];
    void* render_area;
    char __gap2[0x1C];
    void* parent_panel;
    char __gap3[0x28];
    int active;
    int visible;
    char __gap4[0x14];
    void* clip_rgn;
    RECT render_rect;
    char __gap5[0x44];
    int display_changed_count;
    char __gap6[0x10];

    virtual ~TPanel();
    void delete_panel(TPanel** panel_ptr);
};

class TScreenPanel : public TPanel {
public:
    char __gap7[0x384];
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TPanel* title1;              // +0x478
    TPanel* title2;              // +0x47C
    TPanel* button[7];           // +0x480-0x49C
    TPanel* ms_title_text;       // +0x49C
    TPanel* ms_copy_text1;       // +0x4A0
    TPanel* ms_copy_text2;       // +0x4A4
    TPanel* warning_text;        // +0x4A8
    TPanel* circle_p_pic;        // +0x4AC

    virtual ~TRIBE_Screen_Main_Menu();
};
#endif

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {
    this->delete_panel((TPanel**)&this->title1);
    this->delete_panel((TPanel**)&this->title2);
    this->delete_panel((TPanel**)&this->ms_copy_text1);
    this->delete_panel((TPanel**)&this->ms_copy_text2);
    this->delete_panel((TPanel**)&this->warning_text);

    for (int i = 0; i < 7; i++) {
        this->delete_panel((TPanel**)&this->button[i]);
    }

    if (this->circle_p_pic != (TPanel*)0x0) {
        delete this->circle_p_pic;
    }
    if (this->ms_title_text != (TPanel*)0x0) {
        delete this->ms_title_text;
    }
}
