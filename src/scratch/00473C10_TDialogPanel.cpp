// tried the direct TEasy_Panel base-constructor call and the visible font/id zeroing pattern
// tried base sizing with vtable-first and vtable-last spellings; remaining mismatch is still the prolog/body basin
// the stubborn delta is the constructor's early vtable/store order right after the 0xB font-id setup

class TEasy_Panel {
public:
    void* vftable;
    char gap_04[0x474];

    TEasy_Panel(char* param_1);
};

class TDialogPanel : public TEasy_Panel {
public:
    int dlg_wnd;            // 0x478
    int save_parent_child;  // 0x47C
    int text_font_id;       // 0x480
    int input_font_id;      // 0x484
    int button_font_id;     // 0x488
    int button_sound_id;    // 0x48C

    TDialogPanel(char* param_1);
};

TDialogPanel::TDialogPanel(char* param_1) : TEasy_Panel(param_1) {
    int font_id = 0xB;
    int zero = 0;
    this->text_font_id = font_id;
    this->input_font_id = font_id;
    this->button_font_id = font_id;
    this->dlg_wnd = zero;
    this->save_parent_child = zero;
    this->button_sound_id = zero;
    this->vftable = (void*)0x005710B0;
}
