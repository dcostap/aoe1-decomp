#ifndef PNL_DLG_TU_CONTEXT
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_04[0x474];

    TEasy_Panel(char* name);
};

class TDialogPanel : public TEasy_Panel {
public:
    int dlg_wnd;            // +0x478
    int save_parent_child;  // +0x47C
    int text_font_id;       // +0x480
    int input_font_id;      // +0x484
    int button_font_id;     // +0x488
    int button_sound_id;    // +0x48C

    virtual ~TDialogPanel();
    TDialogPanel(char* name);
};
#endif

TDialogPanel::TDialogPanel(char* name)
    : TEasy_Panel(name)
    , dlg_wnd(0)
    , save_parent_child(0)
    , text_font_id(0xB)
    , input_font_id(0xB)
    , button_font_id(0xB)
    , button_sound_id(0)
{
}
