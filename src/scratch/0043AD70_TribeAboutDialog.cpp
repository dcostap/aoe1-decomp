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
// Left in scratch: 1388-byte EH-framed constructor with alloca, 7 probes exhausted.

#include <string.h>
#include <stdio.h>

#include <string.h>
#include <stdio.h>

class TPanel;
class TScreenPanel;

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
    virtual long vf04();
    virtual long vf08();
    virtual long vf0C();
    virtual long vf10();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    virtual long vf14();

    TDrawArea* renderArea();
    int get_string(int id, char* buf, int max_len);
    char* get_string(int id);
    long xPosition();
    long width();
    void set_tab_order(TPanel** tab_list, int count);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4_extra[0x22C];
    char gradient_color_0;
    char gradient_color_1;
    char gradient_color_2;
    char gradient_color_3;
    char gradient_color_4;
    char gradient_color_5;
    char _gap_326_to_490[0x490 - 0x326];

    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_text(TPanel* parent, TPanel** panel_out, int string_id, int x, int y, int w, int h, int align, int unk1, int unk2, int unk3);
    int create_text(TPanel* parent, TPanel** panel_out, char* text, int x, int y, int w, int h, int align, int unk1, int unk2, int unk3);
    int create_button(TPanel* parent, TPanel** panel_out, int string_id, int x, int y, int w, int h, int align, int unk1, int unk2, int unk3);
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    int setup(TDrawArea* draw_area, TScreenPanel* parent, int w, int h, char* info_file, long info_id, int param_8);
};

class TTextPanel : public TPanel {
public:
    int get_text_rect(void* rect);
};

struct RECT_STUB {
    int l, t, r, b;
};

class TPicturePanel {
public:
    char gap_000[0x11C];
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, int y, int p4, int p5, int p6, char* name, int p8, int p9, int p10);
};

class TButtonPanel {
public:
    char gap_000[0x298];
    int hotkey;
    int hotkey_shift;
};

class TRegistry {
public:
    char* RegGetAscii(int param_1, char* key);
};

extern TRegistry* Regs;

class TribeAboutDialog : public TDialogPanel {
public:
    TPanel* title_text;
    TPanel* version_text;
    TPanel* ms_copy_text1;
    TPanel* ms_copy_text2;
    TPanel* ens_copy_text;
    TPanel* genie_copy_text;
    TPanel* pid_label_text;
    TPanel* pid_text;
    TPanel* warning_text;
    TPanel* credits_button;
    TPanel* close_button;
    TPanel* background;
    TPanel* bg_display;

    TribeAboutDialog(TScreenPanel* param_1);
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

TribeAboutDialog::TribeAboutDialog(TScreenPanel* param_1) : TDialogPanel("About Dialog") {
    // Stack buffers
    char temp_str[520];
    char str[4096];

    // Init all panel pointers to 0 using ptr arithmetic to match original asm
    TPanel** p_title = &title_text;
    TPanel** p_ms_copy = &ms_copy_text1;
    TPanel** p_bg = &bg_display;
    *p_title = 0;
    version_text = 0;
    *p_ms_copy = 0;
    ms_copy_text2 = 0;
    ens_copy_text = 0;
    genie_copy_text = 0;
    pid_label_text = 0;
    pid_text = 0;
    warning_text = 0;
    credits_button = 0;
    close_button = 0;
    background = 0;
    *p_bg = 0;

    long info_id = TEasy_Panel::get_popup_info_id();
    char* info_file = TEasy_Panel::get_popup_info_file();
    TDrawArea* draw_area = TPanel::renderArea();

    if (!TDialogPanel::setup(draw_area, param_1, 0x208, 0x19c, info_file, info_id, 1))
        return;

    TEasy_Panel::create_text(this, &bg_display, "", 10, 10, 500, 0x15e, 4, 0, 0, 0);

    // Gradient color vtable call on bg_display (slot 0xEC)
    {
        void* panel = bg_display;
        int c0 = (unsigned char)((TEasy_Panel*)this)->gradient_color_0;
        int c1 = (unsigned char)((TEasy_Panel*)this)->gradient_color_1;
        int c2 = (unsigned char)((TEasy_Panel*)this)->gradient_color_2;
        int c3 = (unsigned char)((TEasy_Panel*)this)->gradient_color_3;
        int c4 = (unsigned char)((TEasy_Panel*)this)->gradient_color_4;
        int c5 = (unsigned char)((TEasy_Panel*)this)->gradient_color_5;
        ((void (__stdcall *)(int, int, int, int, int, int, int))(*((int*)panel + 59)))(3, c0, c1, c2, c3, c4, c5);
    }

    TEasy_Panel::create_text(this, &title_text, 0x2419, 0x14, 0x14, 0x1e0, 0x14, 4, 0, 0, 0);
    TEasy_Panel::create_text(this, &version_text, 0x241a, 0x14, 0x28, 0x1e0, 0x14, 0xb, 0, 0, 0);

    TPanel::get_string(0x2424, temp_str, 0x200);
    if (temp_str[0] == '\0') {
        TEasy_Panel::create_text(this, &ms_copy_text1, 0x241b, 0x14, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);

        if (ms_copy_text1) {
            RECT_STUB* r = (RECT_STUB*)temp_str;
            if (((TTextPanel*)ms_copy_text1)->get_text_rect(r)) {
                TPicturePanel* pic = new TPicturePanel();
                if (pic) {
                    background = (TPanel*)pic;
                    int y = (r->r - field_0C) + 3;
                    pic->setup(draw_area, this, y, 0x42, 0xf, 0xe, "circlep", 0xc4e0, 0, 1);
                    int xp = TPanel::xPosition();
                    int wd = TPanel::width();
                    int x = (xp - field_0C) + wd;
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
        RECT_STUB* r = (RECT_STUB*)(temp_str + 0x14);
        if (((TTextPanel*)pid_label_text)->get_text_rect(r)) {
            char* pid_str = Regs->RegGetAscii(0, "PID");
            if (!pid_str) pid_str = "00000-000-0000000-00000";
            sprintf(str, "%s", pid_str);
            int y = (r->b - field_0C) + 4;
            TEasy_Panel::create_text(this, &pid_text, str, y, 0x96, 200, 0x14, 0xb, 0, 0, 0);
        }
    }

    TPanel::get_string(0x241f, str, 0x1000);
    TEasy_Panel::create_text(this, &warning_text, str, 0x14, 0xaf, 0x1e0, 0xdc, 10, 0, 0, 1);

    TEasy_Panel::create_button(this, &credits_button, 0x2420, 0, 0x46, 0x172, 0xaa, 0x1e, 0, 0, 0);
    TEasy_Panel::create_button(this, &close_button, 0x2421, 0, 0x118, 0x172, 0xaa, 0x1e, 0, 0, 0);

    TButtonPanel* cb = (TButtonPanel*)close_button;
    cb->hotkey = 0x1b;
    cb->hotkey_shift = 0;

    TPanel* tabs[2];
    tabs[0] = credits_button;
    tabs[1] = close_button;
    TPanel::set_tab_order(tabs, 2);
    TPanel::set_curr_child(credits_button);
}
