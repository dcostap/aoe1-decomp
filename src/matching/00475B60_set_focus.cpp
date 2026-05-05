// VA: 00475B60 TEditPanel::set_focus | pnl_edit.cpp:314-395

typedef void* HWND;
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;
typedef unsigned long HIMC;

extern "C" __declspec(dllimport) HWND __stdcall GetFocus(void);
extern "C" __declspec(dllimport) HWND __stdcall SetFocus(HWND wnd);
extern "C" __declspec(dllimport) LRESULT __stdcall SendMessageA(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
extern "C" __declspec(dllimport) int __stdcall ShowWindow(HWND wnd, int cmd);
extern "C" HIMC __stdcall ImmGetContext(HWND wnd);
extern "C" HIMC __stdcall ImmAssociateContext(HWND wnd, HIMC context);
extern "C" int __stdcall ImmSetOpenStatus(HIMC context, int open);
extern int imc_retval;
extern int DAT_0086b240;
extern int DAT_0086b244;

struct TPanel {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void redraw(int flags);
    void* field_04;
    char gap_08[0x18];
    TPanel* parent;
    char gap_24[0x54];
    int focus;
    void set_focus(int focus);
};

struct TEditPanel : public TPanel {
    char gap_7C[0xF4 - 0x7C];
    HWND edit_wnd;
    char gap_F8[0x104 - 0xF8];
    int hidden;
    char gap_108[0x148 - 0x108];
    int auto_sel;
    char gap_14C[0x160 - 0x14C];
    HIMC imc;
    int enable_ime;
    int turn_ime_on;

    void update_text();
    void set_focus(int focus);
};

void TEditPanel::set_focus(int focus)
{
    int old_focus;
    HWND hwnd;
    HIMC context;

    old_focus = this->focus;
    TPanel::set_focus(focus);

    if (this->edit_wnd != 0) {
        HWND current = GetFocus();
        if (this->focus != 0) {
            if (current != this->edit_wnd) {
                SetFocus(this->edit_wnd);
            }
            if (this->imc == 0) {
                if (this->enable_ime != 0) {
                    this->imc = ImmGetContext(this->edit_wnd);
                } else {
                    this->imc = ImmAssociateContext(this->edit_wnd, 0);
                }
            }
            context = this->imc;
            if (context != 0 && this->enable_ime != 0) {
                if (this->turn_ime_on != 0) {
                    imc_retval = ImmSetOpenStatus(context, 1);
                } else {
                    imc_retval = ImmSetOpenStatus(context, 0);
                }
            }
        } else {
            if (current == this->edit_wnd) {
                hwnd = (HWND)this->parent->field_04;
                if (current != hwnd) {
                    SetFocus(hwnd);
                }
            }
        }
    }

    if (old_focus != 0 && this->focus == 0) {
        this->update_text();
        this->redraw(1);
    }
    if (this->edit_wnd != 0 && this->focus != 0 && old_focus == 0 && this->auto_sel != 0) {
        SendMessageA(this->edit_wnd, 0xb1, 0, -1);
    }
    if (DAT_0086b240 == 0 && this->edit_wnd != 0 && this->focus == 0 && this->hidden == 0) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }
    if (this->focus != 0) {
        DAT_0086b244 = 0;
    }
}
