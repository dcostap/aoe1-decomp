// TDialogPanel::TDialogPanel
// VA: 00473C10
// Source: pnl_dlg.cpp lines 33-34
// Size: 68 bytes
//
// Attempt log:
// Probe 1-3: comments only
// Probe 4: natural ctor with body assigns (42.6%) — vtable at start vs end
// Probe 5: init list, same
// Probe 6-8: /O1, /Os, dtor def, this->  — all same or worse
// Remaining 42.6% (29 bytes): vtable write scheduling (start vs end),
//   xor ecx vs xor eax cascade. Default flags minimal diff; deep codegen basin.
// Left in scratch.

#include "../../include/game_globals.h"

class TPanel {
public:
    char _pad04[0x1C];
    void* render_area;
    char _pad24[0x1C];
    void* parent_panel;
    char _pad44[0x28];
    int active;
    int visible;
    char _pad74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _pad9C[0x44];
    int display_changed_count;
    char _padE4[0x10];
    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    char _padF4[0x384];
    TEasy_Panel(char* name);
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;          // +0x478
    TPanel* save_parent;    // +0x47C
    int text_font_id;       // +0x480
    int input_font_id;      // +0x484
    int button_font_id;     // +0x488
    int button_sound_id;    // +0x48C

    TDialogPanel(char* name);
    virtual ~TDialogPanel();
};

TDialogPanel::TDialogPanel(char* name)
    : TEasy_Panel(name)
{
    text_font_id = 11;
    input_font_id = 11;
    button_font_id = 11;
    dlg_wnd = 0;
    save_parent = 0;
    button_sound_id = 0;
}
