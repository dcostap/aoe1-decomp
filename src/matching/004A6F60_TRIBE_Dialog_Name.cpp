// VA: 004A6F60 TRIBE_Dialog_Name::~TRIBE_Dialog_Name
// PDB: scr_name.cpp lines 367-373 (142 bytes, 38 asm lines)
// MATCH: `python tools/check_function.py --va 004A6F60` -> 0.0000%.
// Natural C++ destructor with the correct TPanel/TEasy_Panel/TDialogPanel layout
// and existing /GX flag emits the original EH frame, vtable restore, five
// delete_panel calls, and base TDialogPanel destructor.

#include "..\..\include\game_globals.h"

#ifdef SCR_NAME_TU_CONTEXT
#include "..\..\include\scr_name_context.h"
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

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
};

class TRIBE_Dialog_Name : public TDialogPanel {
public:
    TPanel* title;
    TPanel* name_text;
    TPanel* name_input;
    TPanel* ok_button;
    TPanel* cancel_button;

    virtual ~TRIBE_Dialog_Name();
};
#endif

TRIBE_Dialog_Name::~TRIBE_Dialog_Name()
{
    this->delete_panel(&this->title);
    this->delete_panel(&this->name_text);
    this->delete_panel(&this->name_input);
    this->delete_panel(&this->ok_button);
    this->delete_panel(&this->cancel_button);
}
