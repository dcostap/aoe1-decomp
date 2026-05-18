// 0043E9E0 THelpDialog::setup_help
// Attempt log:
// 1: natural source from packet/decompiler with local class/vtable surface.
// 2: initial compile failed on abs/signature; replaced abs with explicit sign fixups and corrected button arg count.
// 3: natural source with manual string loop produced 832-byte .text (< original 849), too small to compare.
// 4: using strcpy surface improved to 848-byte .text and reproduced the original early repne-scan/rep-mov copy family, still 1 byte short.
// 5: probed /GX response file; no size/codegen improvement, removed.
// 6: fixed create_list virtual signature/order so the source pushes this,&list,param before geometry like the original.
// 7: kept a local volatile size probe only to force a comparable 849-byte object; best comparable check is broad mismatch (84.69% positional, 70.67% edit).
// 8: main blocker: without the probe, code is exactly 1 byte short but much closer at the top; with the probe, prologue is perturbed (`mov edx,[esp+18]` before pushes).
// 9: remaining source model likely needs exact original class/TU context and child-creation signatures; current natural source gets broad behavior/calls but not local scheduling.
// GIVEUP: left in scratch; no accepted_drift proposal because the comparable diff is broad and the unprobed build is size-short, not localized equivalent drift.

extern void* rge_base_game;
extern "C" char* strcpy(char*, const char*);

class TDrawArea;
class RGE_Font;
class TPanel;

class RGE_Base_Game {
public:
    RGE_Font* get_font(int id);
    int singlePlayerGame();
};

class TPanel {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void set_rect(int x, int y, int w, int h); // +0x1c
    char gap_04[0xB0 - 4];
    int field_B0;
    char gap_B4[4];
    int field_B8;
    char gap_BC[0x298 - 0xBC];
    int hotkey;
    int hotkey_shift;
    int width();
    int xPosition();
    int yPosition();
    int height();
    TDrawArea* renderArea();
    void set_curr_child(TPanel* child);
    char* get_string(int id);
};

class TEasy_Panel : public TPanel {
public:
    char* get_popup_info_file();
    int get_popup_info_id();
};

class THelpDialog : public TPanel {
public:
    char gap_2A0[0x490 - 0x2A0];
    int help_page_id;
    char parent_panel[0x100]; // +494
    TPanel* title;       // +594
    TPanel* list;        // +598
    TPanel* ok_button;   // +59c
    TPanel* encyclopedia_button; // +5a0

    virtual void pad020(); virtual void pad024(); virtual void pad028(); virtual void pad02c();
    virtual void pad030(); virtual void pad034(); virtual void pad038(); virtual void pad03c();
    virtual void pad040(); virtual void pad044(); virtual void pad048(); virtual void pad04c();
    virtual void pad050(); virtual void pad054(); virtual void pad058(); virtual void pad05c();
    virtual void pad060(); virtual void pad064(); virtual void pad068(); virtual void pad06c();
    virtual void pad070(); virtual void pad074(); virtual void pad078(); virtual void pad07c();
    virtual void pad080(); virtual void pad084(); virtual void pad088(); virtual void pad08c();
    virtual void pad090(); virtual void pad094(); virtual void pad098(); virtual void pad09c();
    virtual void pad0a0(); virtual void pad0a4(); virtual void pad0a8(); virtual void pad0ac();
    virtual void pad0b0(); virtual void pad0b4(); virtual void pad0b8(); virtual void pad0bc();
    virtual void pad0c0(); virtual void pad0c4();
    virtual void set_child_list(TPanel** list, int count); // +0xc8
    virtual void pad0cc(); virtual void pad0d0(); virtual void pad0d4(); virtual void pad0d8(); virtual void pad0dc(); virtual void pad0e0();
    virtual void set_something2(int a, int b); // +0xe4
    virtual TPanel* create_button(TPanel** out, int id, int zero, int x, int y, int w, int h, int a, int b, int c); // +0xe8
    virtual void pad0ec(); virtual void pad0f0(); virtual void pad0f4(); virtual void pad0f8(); virtual void pad0fc();
    virtual int create_list(THelpDialog* parent, TPanel** out, long param, int x, int y, int w, int h, int line_h, int flags, int a, int b); // +0x100
    virtual void pad104(); virtual void pad108(); virtual void pad10c(); virtual void pad110(); virtual void pad114(); virtual void pad118(); virtual void pad11c(); virtual void pad120(); virtual void pad124(); virtual void pad128();
    virtual int setup(TDrawArea* area, TPanel* parent, int w, int h, char* info_file, int info_id, int flag); // +0x12c

    void setup_help(TEasy_Panel* parent, char* text, char* more_text, long page_id, long x_limit, long y_limit);
};

void THelpDialog::setup_help(TEasy_Panel* parent, char* text, char* more_text, long page_id, long x_limit, long y_limit)
{
    TPanel* tabList[2];
    volatile RGE_Font* rge_text_font;
    volatile int force_size;

    force_size = page_id;
    force_size = force_size + 1;
    this->ok_button = 0;
    this->encyclopedia_button = 0;
    this->title = 0;
    this->list = 0;
    strcpy(this->parent_panel, text);
    this->help_page_id = page_id;
    rge_text_font = ((RGE_Base_Game*)rge_base_game)->get_font(11);

    if (this->setup(parent->renderArea(), parent, 0x154, 0x190, parent->get_popup_info_file(), parent->get_popup_info_id(), 1)) {
        this->create_list(this, &this->list, y_limit, 10, 10, 0x14a, 0x186, 11, 0, 0, 1);
        int line_count = *(short*)((char*)this->list + 0xfe) + 2;
        int text_h = line_count * *(int*)((char*)rge_text_font + 8) + 0x37;

        int x;
        int right = parent->width() + parent->xPosition();
        if (right >= x_limit + 0x163) {
            x = parent->xPosition() - x_limit - 5; if (x < 0) x = -x;
        } else if (parent->xPosition() + 10 <= x_limit - 0x159) {
            x = (x_limit - 0x159) - parent->xPosition(); if (x < 0) x = -x;
        } else {
            x = parent->width() / 2 - 0xaa;
        }
        if (x < 0) x = 0;

        int h_rem = y_limit - text_h;
        int y;
        if (parent->yPosition() <= h_rem - 10) {
            y = h_rem - parent->yPosition() - 10; if (y < 0) y = -y;
        } else {
            int bottom = parent->height() + parent->yPosition();
            if (text_h + y_limit + 10 <= bottom) {
                y = y_limit - parent->yPosition() + 10; if (y < 0) y = -y;
            } else {
                y = parent->height() / 2 - text_h / 2;
            }
        }
        if (y < 0) y = 0;

        this->set_rect(x, y, 0x154, text_h);
        this->set_something2(this->field_B0, this->field_B8);
        this->list->set_rect(10, 10, 0x14a, line_count * *(int*)((char*)rge_text_font + 8));

        if (((RGE_Base_Game*)rge_base_game)->singlePlayerGame() && (int)more_text >= 0) {
            char* s = this->get_string((int)more_text);
            if (s != 0 && *s != 0) {
                this->create_button(&this->encyclopedia_button, 0x243d, 0, 0, 25, line_count * *(int*)((char*)rge_text_font + 8) + 20, 0x78, 25, 11, 0);
            }
        }

        int button_x;
        if (this->encyclopedia_button == 0) {
            button_x = 0x6e;
        } else {
            button_x = 0xc3;
        }
        this->create_button(&this->ok_button, 0xfa1, 0, button_x, line_count * *(int*)((char*)rge_text_font + 8) + 20, 0x78, 25, 11, 0, 0);
        this->ok_button->hotkey = 0x1b;
        this->ok_button->hotkey_shift = 0;
        this->set_curr_child(this->ok_button);
        tabList[0] = this->ok_button;
        int count = 1;
        if (this->encyclopedia_button != 0) {
            tabList[1] = this->encyclopedia_button;
            count = 2;
        }
        this->set_child_list(tabList, count);
    }
}
