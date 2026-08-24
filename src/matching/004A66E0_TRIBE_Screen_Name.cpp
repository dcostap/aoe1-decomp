// VA: 004A66E0 TRIBE_Screen_Name::~TRIBE_Screen_Name
// PDB: scr_name.cpp lines 102-114
// Baseline reconstruction: natural /GX virtual destructor surface with the
// binary-proven TPanel/TScreenPanel layout and nine child-panel members.

#include "../../include/game_globals.h"

#ifdef SCR_NAME_TU_CONTEXT
#include "../../include/scr_name_context.h"
#else
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

class TScreenPanel : public TPanel {
public:
    char _gap_F4[0x384];
    virtual ~TScreenPanel();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TPanel* title;              // +0x478
    TPanel* name_text;          // +0x47C
    TPanel* name_list;          // +0x480
    TPanel* name_scrollbar;     // +0x484
    TPanel* new_button;         // +0x488
    TPanel* remove_button;      // +0x48C
    TPanel* ok_button;          // +0x490
    TPanel* cancel_button;      // +0x494
    TPanel* close_button;       // +0x498

    virtual ~TRIBE_Screen_Name();
};
#endif

TRIBE_Screen_Name::~TRIBE_Screen_Name()
{
    panel_system.setCurrentPanel("New Name Dialog", 0);

    this->delete_panel(&this->title);
    this->delete_panel(&this->name_text);
    this->delete_panel(&this->name_list);
    this->delete_panel(&this->name_scrollbar);
    this->delete_panel(&this->new_button);
    this->delete_panel(&this->remove_button);
    this->delete_panel(&this->ok_button);
    this->delete_panel(&this->cancel_button);
    this->delete_panel(&this->close_button);
}
