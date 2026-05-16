// 004A6D50 TRIBE_Dialog_Name::TRIBE_Dialog_Name (scr_name.cpp:329-361)
// Attempt log:
// 1: Natural constructor with /GX but no visible base dtor/size: emitted no EH prologue, 448B, fields -4.
// 2: Virtual base dtor triggered EH but introduced this+4 adjustments and broad 75.57% diff.
// 3: Non-virtual base dtor kept EH/this but fields still -4 and no explicit vtable store.
// 4: Base pad + manual vtable improved to 63.35%/23.8%; extra EH this-store at [esp+18] shifts early block.
// 5: 3-entry list without explicit tab[0] gives best so far (padded diagnostic 15.53% diff), but EBP/EBX field-addresses swapped.
// 6: Explicit pointer locals did not alter EBP/EBX allocation.
// 7: Swapping local order emitted EBP=input then EBX=title; still opposite of original.
// 8: register title pointer did not change allocation.
// 9: Restored explicit tab_list[0] gives comparable 483B, final 63.35% positional / 23.81% edit.
// 10: Removing register keyword made no codegen change.
// FLAGS: config/flags/004A6D50_TRIBE_Dialog_Name.rsp uses /GX; needed to get EH prologue after declaring a visible base destructor.
// Left in scratch: behavior/call sequence is largely aligned and size matches, but VC5 context is still wrong. Need real TDialogPanel/TEasy_Panel base surface: without visible base dtor no EH prologue and 448B; with non-virtual base dtor EH appears but adds an extra cleanup-this local/store and keeps field-address registers swapped (rebuilt EBP=input, EBX=title vs original EBP=title, EBX=input). This shifts later branch targets and tail by ~3 bytes.

class TDrawArea;
class TPanel {
public:
    TDrawArea* renderArea();
    void set_tab_order(TPanel** list, int count);
    void set_curr_child(TPanel* p);
};
class TEasy_Panel : public TPanel {
public:
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_text(TPanel* parent, TPanel** out, int id, int x, int y, int w, int h, int a, int b, int c, int d);
    int create_edit(TPanel* parent, TPanel** out, char* text, int maxlen, int fmt, int x, int font, int w, int h, int unk, int a, int b);
    int create_button(TPanel* parent, TPanel** out, int id, int x, int y, int w, int h, int a, int b, int c, int d);
};
class TDialogPanel : public TEasy_Panel {
public:
    char base_pad[0x490];
    TDialogPanel(char* name);
    ~TDialogPanel();
    int setup(TDrawArea* area, TPanel* parent, long w, long h, char* file, long id, int flag);
};
class TRIBE_Dialog_Name : public TDialogPanel {
public:
    TPanel* title;
    TPanel* name_text;
    TPanel* name_input;
    TPanel* ok_button;
    TPanel* cancel_button;

    TRIBE_Dialog_Name(TPanel* screen);
};

TRIBE_Dialog_Name::TRIBE_Dialog_Name(TPanel* screen)
    : TDialogPanel("New Name Dialog")
{
    TPanel* tab_list[3];
    tab_list[0] = this;
    TEasy_Panel* easy = (TEasy_Panel*)screen;
    TPanel** input_ptr = &this->name_input;
    TPanel** title_ptr = &this->title;

    *(void**)this = (void*)0x00573768;
    this->title = 0;
    this->name_text = 0;
    this->name_input = 0;
    this->ok_button = 0;
    this->cancel_button = 0;

    if (!this->setup(screen->renderArea(), screen, 0x1f4, 0xe6, easy->get_popup_info_file(), easy->get_popup_info_id(), 1)) return;
    if (!this->create_text(this, title_ptr, 0x2a03, 0x14, 0x14, 0x1cc, 0x1e, 1, 1, 1, 0)) return;
    if (!this->create_text(this, &this->name_text, 0x2a04, 0x28, 0x55, 0x1a4, 0x14, 4, 0, 1, 0)) return;
    if (!this->create_edit(this, input_ptr, "", 0x0f, 0, 0x28, 0x6e, 0x1a4, 0x17, 0x0b, 1, 1)) return;
    if (!this->create_button(this, &this->ok_button, 0x0fa1, 0, 0x3c, 0x0b4, 0x0b4, 0x1e, 0, 0, 0)) return;
    if (!this->create_button(this, &this->cancel_button, 0x0fa2, 0, 0x104, 0x0b4, 0x0b4, 0x1e, 0, 0, 0)) return;

    *(int*)((char*)this->cancel_button + 0x298) = 0x1b;
    *(int*)((char*)this->cancel_button + 0x29c) = 0;
    tab_list[1] = *input_ptr;
    tab_list[2] = this->ok_button;
    this->set_tab_order(&tab_list[1], 3);
    this->set_curr_child(this->name_input);
}
