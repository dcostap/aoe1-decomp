// 0043F6B0 TribeMenuDialog::~TribeMenuDialog
//
// Probe 1: while loop with pointer — wrong loop structure
// Probe 2: fixed TPanel size (0xF4) — button at +0x490 ✓, but while loop uses pointer-compare not count-down
// Probe 3: count-down loop to match original `dec ebx; jne`

#include "..\..\include\game_globals.h"

#ifndef DLG_MENU_SHARED_CONTEXT
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
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
};

class TButtonPanel;

class TribeMenuDialog : public TDialogPanel {
public:
    TButtonPanel* button[11];

    virtual ~TribeMenuDialog();
};
#endif

TribeMenuDialog::~TribeMenuDialog()
{
    int count = 11;
    TPanel** pp = (TPanel**)this->button;
    
    do {
        this->delete_panel(pp);
        pp++;
        count--;
    } while (count != 0);
}
