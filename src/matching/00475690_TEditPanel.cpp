// VA: 00475690 ~TEditPanel (216B)
// PDB donor: pnl_edit.cpp, lines 83-112
// Attempt log:
// baseline: natural TPanel-derived destructor with the binary-proven edit window,
// text buffer, and IME fields; calls and cleanup order follow the original.
// FLAGS: /GX is retained because the original has EH registration and base-dtor cleanup.

#include <stdlib.h>

typedef void* HWND;
typedef void* HIMC;

extern "C" __declspec(dllimport) int __stdcall ShowWindow(HWND hwnd, int command);
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(HWND hwnd);
extern "C" int __stdcall ImmNotifyIME(HIMC context, unsigned int action,
                                      unsigned int index, unsigned int value);
extern "C" int __stdcall ImmReleaseContext(HWND hwnd, HIMC context);

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TEditPanel : public TPanel {
public:
    HWND edit_wnd;                 // +0xF4
    char gap_F8[4];
    char* text;                    // +0xFC
    int text_len;                  // +0x100
    int hidden;                    // +0x104
    char gap_108[0x58];
    HIMC imc;                      // +0x160
    int enable_ime;                // +0x164
    int turn_ime_on;               // +0x168

    virtual ~TEditPanel();
};

TEditPanel::~TEditPanel() {
    if ((this->edit_wnd != 0) && (this->hidden == 0)) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }

    if (this->text != 0) {
        free(this->text);
        this->text = 0;
    }

    if (this->edit_wnd != 0) {
        if (this->imc != 0) {
            ImmNotifyIME(this->imc, 0x15, 4, 0);
            if (this->enable_ime != 0) {
                ImmReleaseContext(this->edit_wnd, this->imc);
            }
            this->imc = 0;
        }
        DestroyWindow(this->edit_wnd);
        this->edit_wnd = 0;
    }
}
