// VA: 0043AD70 TribeAboutDialog::TribeAboutDialog
// dlg_abt.cpp lines 46-148

// Attempt log:
// P1: member init list, separate local arrays (temp_str[512]+str[4096]), explicit tagRECT+tab_arr.
//     Compiled 1388/1388 (exact size!) but alloca 0x1228 vs 0x1220 (8 too large). 79% diff.
// P2: body-style ctor call. ERROR: no default ctor for TDialogPanel.
// P3: init list, combined buf[0x1200], removed rect/tab_arr locals.
//     Alloca 0x1218 (8 too small). Adjusted to buf[0x1220] → alloca 0x1238 (24 too large).
// P4: back to two arrays (temp_str[520]+str[4096]). Alloca 0x1220! Perfect. 78% diff.
// P5: added gradient vtable call. 77% diff (minor improvement).
// P6: added missing '1' param to setup(), reordered field declarations. 78% diff.
// P7: pointer vars for field init. 79% diff.
// Remaining gap: pervasive register allocation/statement order diffs (initial
// esi/edi/ebx assignment, early push optimization, gradient vtable call encoding).
// Original asm at offset 45+ differs in register choice and order throughout.
// P8: nested setup argument evaluation plus an explicit RECT recovered the
//     0x1220 stack window and raised shape similarity to 96.68%.
// P9: fixed-address string diagnostics moved strict bytes slightly farther but
//     improved edit alignment; main-agent audit restored the actual literals.
// P10: inlined picture y/x arithmetic to avoid compiler-carried temporaries;
//      edit diff improved, with the same 1390-byte result.
// P11: moved the natural background null initialization after credits, close,
//      and circle-picture initialization to match the ordered member stores;
//      diff improved 782 -> 710 bytes and exact-block coverage 74.50% -> 85.81%.
// Left in scratch after the prior bounded session: canonical source is retained.
// The remaining
// hard blocker is VC5 emitting __chkstk where the original names __alloca_probe;
// residual drift is prologue/register scheduling plus a two-byte downstream
// shift, not an unresolved panel-layout fact. Main-agent normalization of
// string literals and direct panel ownership improved the strict diff from
// 782 to 732 bytes and shape from 96.68% to 97.57%.

#include <string.h>
#include <stdio.h>

#include <string.h>
#include <stdio.h>

class TPanel;
class TScreenPanel;
class TTextPanel;
class TButtonPanel;

class TDrawArea {
public:
    char gap_000[4];
};

class TPanel {
public:
    char _gap_04[0x4];
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    TDrawArea* render_area;   // +0x20
    char _gap_24[0x1C];
    TPanel* parent_panel;     // +0x40
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    char render_rect[16];
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();

    TDrawArea* renderArea();
    int get_string(int id, char* buf, int max_len);
    char* get_string(int id);
    long xPosition();
    long width();
    void set_tab_order(TPanel** tab_list, short count);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(TPanel*, void*, char*, short, int, long, long, long, long, long);
    virtual int create_edit(TPanel*, void*, char*, short, int, long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, void*, long, long, long, long, long, long, long);
    virtual int create_list(TPanel*, void*, long, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, void*, TPanel*, long, long, long, long, long);
    virtual int create_auto_scrollbar(void*, TPanel*, long);
    virtual int create_vert_slider(TPanel*, void*, long, long, long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, void*, long, long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    void* background_pic;
    void* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char gradient_color_0;
    unsigned char gradient_color_1;
    unsigned char gradient_color_2;
    unsigned char gradient_color_3;
    unsigned char gradient_color_4;
    unsigned char gradient_color_5;
    char _gap_326[2];
    char _gap_328_to_478[0x150];

    long get_popup_info_id();
    char* get_popup_info_file();
};

class TDialogPanel : public TEasy_Panel {
public:
    char _gap_478[0x18];
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea* draw_area, TScreenPanel* parent, int w, int h, char* info_file, long info_id, int param_8);
};

class TTextPanel : public TPanel {
public:
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char _gap_F4[0x94];
    int get_text_rect(void* rect);
};

struct RECT_STUB {
    int l, t, r, b;
};

class TPicturePanel : public TPanel {
public:
    char gap_F4[0x28];
    virtual ~TPicturePanel();
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, int y, int p4, int p5, int p6, char* name, int p8, int p9, int p10);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
};

class TScreenPanel : public TEasy_Panel {
};

class TRegistry {
public:
    char* RegGetAscii(int param_1, char* key);
};

extern TRegistry* Regs;

class TribeAboutDialog : public TDialogPanel {
public:
    TTextPanel* title_text;
    TTextPanel* version_text;
    TTextPanel* ms_copy_text1;
    TTextPanel* ms_copy_text2;
    TTextPanel* ens_copy_text;
    TTextPanel* genie_copy_text;
    TTextPanel* pid_label_text;
    TTextPanel* pid_text;
    TTextPanel* warning_text;
    TTextPanel* background;
    TButtonPanel* credits_button;
    TButtonPanel* close_button;
    TPicturePanel* circle_p_pic;

    TribeAboutDialog(TScreenPanel* param_1);
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

TribeAboutDialog::TribeAboutDialog(TScreenPanel* param_1) : TDialogPanel("About Dialog") {
    // Stack buffers
    char temp_str[512];
    char str[4096];
    RECT_STUB rect;

    int modal = 1;
    title_text = 0;
    version_text = 0;
    ms_copy_text1 = 0;
    ms_copy_text2 = 0;
    ens_copy_text = 0;
    genie_copy_text = 0;
    pid_label_text = 0;
    pid_text = 0;
    warning_text = 0;
    credits_button = 0;
    close_button = 0;
    circle_p_pic = 0;
    background = 0;

    if (!TDialogPanel::setup(param_1->renderArea(), param_1, 0x208, 0x19c,
                             param_1->get_popup_info_file(),
                             param_1->get_popup_info_id(), modal))
        return;

    TEasy_Panel::create_text(this, &background, "", 10, 10, 500, 0x15e, 4, 0, 0, 0);

    background->set_bevel_info(3, gradient_color_0, gradient_color_1,
                                gradient_color_2, gradient_color_3,
                                gradient_color_4, gradient_color_5);

    TEasy_Panel::create_text(this, &title_text, 0x2419, 0x14, 0x14, 0x1e0, 0x14, 4, 0, 0, 0);
    TEasy_Panel::create_text(this, &version_text, 0x241a, 0x14, 0x28, 0x1e0, 0x14, 0xb, 0, 0, 0);

    TPanel::get_string(0x2424, temp_str, 0x200);
    if (temp_str[0] == '\0') {
        TEasy_Panel::create_text(this, &ms_copy_text1, 0x241b, 0x14, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);

        if (ms_copy_text1) {
            if (ms_copy_text1->get_text_rect(&rect)) {
                circle_p_pic = new TPicturePanel();
                if (circle_p_pic) {
                    circle_p_pic->setup(render_area, this, (rect.r - field_0C) + 3,
                                        0x42, 0xf, 0xe, "circlep", 0xc4e0, 0, 1);
                    int x = circle_p_pic->xPosition() - field_0C + circle_p_pic->width();
                    TEasy_Panel::create_text(this, &ms_copy_text2, 0x241c, x, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);
                }
            }
        }
    } else {
        strcpy(temp_str, TPanel::get_string(0x241b));
        strcat(temp_str, TPanel::get_string(0x2424));
        strcat(temp_str, " ");
        strcat(temp_str, TPanel::get_string(0x241c));
        TEasy_Panel::create_text(this, &ms_copy_text1, temp_str, 0x14, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);
    }

    TEasy_Panel::create_text(this, &ens_copy_text, 0x241d, 0x14, 0x55, 0x1e0, 0x14, 10, 0, 0, 0);
    TEasy_Panel::create_text(this, &genie_copy_text, 0x2423, 0x14, 0x69, 0x1e0, 0x28, 10, 0, 0, 1);
    TEasy_Panel::create_text(this, &pid_label_text, 0x241e, 0x14, 0x96, 0x5f, 0x14, 10, 0, 0, 0);

    if (pid_label_text) {
        if (pid_label_text->get_text_rect(&rect)) {
            char* pid_str = Regs->RegGetAscii(0, "PID");
            if (!pid_str) pid_str = "00000-000-0000000-00000";
            sprintf(str, "%s", pid_str);
            int y = (rect.b - field_0C) + 4;
            TEasy_Panel::create_text(this, &pid_text, str, y, 0x96, 200, 0x14, 0xb, 0, 0, 0);
        }
    }

    TPanel::get_string(0x241f, str, 0x1000);
    TEasy_Panel::create_text(this, &warning_text, str, 0x14, 0xaf, 0x1e0, 0xdc, 10, 0, 0, 1);

    TEasy_Panel::create_button(this, &credits_button, 0x2420, 0, 0x46, 0x172, 0xaa, 0x1e, 0, 0, 0);
    TEasy_Panel::create_button(this, &close_button, 0x2421, 0, 0x118, 0x172, 0xaa, 0x1e, 0, 0, 0);

    TButtonPanel* cb = close_button;
    cb->hotkey = 0x1b;
    cb->hotkey_shift = 0;

    TPanel* tabs[2];
    tabs[0] = credits_button;
    tabs[1] = close_button;
    TPanel::set_tab_order(tabs, 2);
    TPanel::set_curr_child(credits_button);
}
