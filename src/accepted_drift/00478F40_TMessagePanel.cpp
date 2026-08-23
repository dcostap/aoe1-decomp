// ACCEPTED_DRIFT: exact bytes differ only by VC5 scheduling of the font_wid store at +0x308.
// The rebuilt constructor stores font_wid just before the scalar zero-init block; the original stores the same value just after show_message_interval.
// There are no intervening calls or reads of that field, EH state is already active in both forms, and all constructor stores/calls/return behavior are preserved.
// first pass: natural constructor with explicit local TPanel surface and packet-observed init order
// FLAGS: config/flags/00478F40_TMessagePanel.rsp uses /GX; needed to reproduce the EH frame/base cleanup context
// adding visible virtual destructors produced the right EH-framed size/control skeleton
// explicit late vptr store matches the original late TMessagePanel vtable restore; natural generated vptr was too early
// remaining mismatch is localized to early param2/param3 register scheduling around font_wid/font_hgt stores, plus masked call relocations
// tried volatile saved font_wid to force an early param2 load; it added stack spill code and worsened the diff, rolled back
// tried swapped formal names while preserving observed stores; no codegen change, rolled back
// tried volatile font_hgt member to force the early +30C store; no codegen change, rolled back
// tried raw offset stores for the constructor params; no codegen change, rolled back
// tried swapped local field names/order (same physical offsets); no codegen change, rolled back
// tried an initializer list for the early parameter/LastIB stores; no codegen change, rolled back
// tried a volatile-this store for font_hgt; no codegen change, rolled back
// pointer-mediated font_hgt assignment moved the +30C store early but loaded param3 into EDX and worsened the diff; saved-font_wid did not help, rolled back
// early source assignment of font_wid before font_hgt produced the right early param2 load but stores +308 before the zero-init block
// saved font_wid temp, duplicate store, and reference-mediated delayed store did not preserve the original later +308 store; keeping the closest early-load version
#ifndef AOE1_PNL_MSG_CONTEXT_H
extern int TMessagePanel_vftable;

class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void pv8(int);

    char gap_004[0x7C];
    int handle_mouse_input;
    char gap_084[0x70];

    TPanel(void);
    virtual ~TPanel(void);
    void set_active(int active);
};

class TMessagePanel : public TPanel {
public:
    enum MessageType {
        InfoMessage = 0,
        BadMessage = 1,
        DebugMessage = 2,
        ChatMessage = 3,
        ColoredChatMessage = 4,
        RightInfoMessage = 5
    };
    enum JustType {
        TopJust = 0,
        BottomJust = 1,
        LeftJust = 2,
        RightJust = 3,
        CenterJust = 4
    };
    MessageType message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    char gap_312[0xE];
    JustType horz_just;
    JustType vert_just;
    int word_wrap;
    void* image_clip_region;
    void* ImageBuffer;
    char gap_334[0x30];
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    void* Icon1;
    void* Icon2;
    int IconFrame1;
    int IconFrame2;

    TMessagePanel(void* font, long font_wid, long font_hgt);
    virtual ~TMessagePanel(void);
};
#endif

TMessagePanel::TMessagePanel(void* font, long font_wid, long font_hgt)
    : TPanel() {
    this->font = font;
    this->font_wid = font_wid;
    this->font_hgt = font_hgt;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->message_type = InfoMessage;
    this->showing_message = 0;
    this->start_time = 0;
    this->show_message_interval = 8000;
    this->font_color = 0;
    this->back_color = 0;
    this->horz_just = LeftJust;
    this->vert_just = TopJust;
    this->word_wrap = 0;
    this->image_clip_region = 0;
    this->ImageBuffer = 0;
    this->ImageTextActive = 0;
    this->Icon1 = 0;
    this->Icon2 = 0;
    this->IconFrame1 = 0;
    this->IconFrame2 = 0;
    *(int*)this = 0x00571668;
    this->text[0] = 0;
    this->handle_mouse_input = 0;
    this->set_active(0);
}
