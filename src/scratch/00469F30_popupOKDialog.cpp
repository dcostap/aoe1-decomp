// 00469F30 TEasy_Panel::popupOKDialog (Panel_ez.cpp:1772-1793, 263B)
// SEH-framed. Pops up an OK dialog with the given title or default.
// FLAGS: /nologo /c /O2 /Oy /GX
//
// Attempt log:
// - Base class offsets now correct (void* vtable without inheritance fixes 0xF0 shift)
// - strcpy inlines correctly (repne scasb + rep movsd + rep movsb)
// - Remaining diff (~76%) is instruction scheduling within basic blocks:
//   * SEH prologue instruction order (param load before/after sub esp)
//   * Default string selection control flow (different branch polarity)
//   * Setup call arg evaluation order (same values, different push sequence)
//   * All struct offsets verified correct ([ebx+444h], [ebx+340h])
// - Suggest variant_lab for scheduling/comparison-order fixes

void* __cdecl operator new(unsigned int size);

struct TPanel {
    void* vtable;  // +0x00
};

struct TEasy_Panel {
    void* vtable;  // +0x00
    char gap_04[0x340 - 4];
    /* +0x340 */ char popup_info_file_name[260];
    /* +0x444 */ long popup_info_id;

    void popupOKDialog(char* text_title, char* panel_name, int a3, int a4);
};

struct TPanelSystem {
    char gap_00[0x14];
    TPanel* panel(char* name);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;  // at 0x62E870

struct TMessageDialog {
    char gap_00[0x490];
    unsigned char dlg_type;
    char gap_491[3];
    void* text;
    void* button0;
    void* button1;
    void* button2;

    TMessageDialog(char* param_1);
    long setup(TPanel* parent, char* info_file, long info_id,
               long a3, long a4, int zero, char* title,
               int w, int h);
};

extern const char s_OKDialog[];  // default "OKDialog" at 0x584EB4

void TEasy_Panel::popupOKDialog(char* text_title, char* panel_name, int a3, int a4) {
    char temp_title[256];
    char* src;

    if (panel_name != 0 && *panel_name != 0) {
        src = panel_name;
    } else {
        src = (char*)s_OKDialog;
    }

    {
        int i = 0;
        do {
            temp_title[i] = src[i];
        } while (src[i++] != 0);
    }

    if (panel_system.panel(temp_title) != 0) {
        panel_system.destroyPanel(temp_title);
    }

    TMessageDialog* dlg = new TMessageDialog(temp_title);
    if (dlg != 0) {
        dlg->setup((TPanel*)this, popup_info_file_name, popup_info_id,
                   a3, a4, 0, text_title, 0x5A, 0x1E);
    }
}
