// 0043B300 TribeAboutDialog::~TribeAboutDialog
// Source: dlg_abt.cpp lines 154-168
//
// Attempt log:
// Probe 1: wrong inheritance — TDialogPanel from TPanel (fields at 0xF4 instead of 0x490)
//   Also vtable not set (0 instead of 56F610h)
// Probe 2: fix inheritance chain, proper gap size

#ifndef DLG_ABT_CANONICAL_TU
#include "..\..\include\game_globals.h"
#endif

#ifndef DLG_ABT_CANONICAL_TU
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

class TribeAboutDialog : public TDialogPanel {
public:
    // 13 TPanel* fields at +0x490 to +0x4C0
    TPanel* title_text;       // +0x490
    TPanel* version_text;     // +0x494
    TPanel* ms_copy_text1;    // +0x498
    TPanel* ms_copy_text2;    // +0x49C
    TPanel* ens_copy_text;    // +0x4A0
    TPanel* genie_copy_text;  // +0x4A4
    TPanel* pid_label_text;   // +0x4A8
    TPanel* pid_text;         // +0x4AC
    TPanel* warning_text;     // +0x4B0
    TPanel* bg_display;       // +0x4B4 (circle_p_pic)
    TPanel* credits_button;   // +0x4B8
    TPanel* close_button;     // +0x4BC
    TPanel* background;       // +0x4C0

    virtual ~TribeAboutDialog();
};
#endif

TribeAboutDialog::~TribeAboutDialog()
{
    this->delete_panel((TPanel**)&this->title_text);
    this->delete_panel((TPanel**)&this->version_text);
    this->delete_panel((TPanel**)&this->ms_copy_text1);
    this->delete_panel((TPanel**)&this->ms_copy_text2);
    this->delete_panel((TPanel**)&this->ens_copy_text);
    this->delete_panel((TPanel**)&this->genie_copy_text);
    this->delete_panel((TPanel**)&this->pid_label_text);
    this->delete_panel((TPanel**)&this->pid_text);
    this->delete_panel((TPanel**)&this->warning_text);
    this->delete_panel((TPanel**)&this->credits_button);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->background);
    this->delete_panel((TPanel**)&this->circle_p_pic);
}
