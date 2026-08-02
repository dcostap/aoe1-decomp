// VA: 00473AA0 do_right_action (209B)
// Pnl_btn.cpp
//
// Attempt log:
// - Reconstructed from the neighboring Pnl_btn.cpp actions and the binary:
//   state buttons advance through the E0 virtual setter, radio buttons call
//   set_radio_button, and the parent receives action codes 6/4 before the
//   non-NotifyAction path sends WM_COMMAND (0x111).
// - Restored the sound pointer at +148 so the proven num_states/cur_state
//   fields remain at +1F4/+1F6.
// - The setter takes a short state; with the signed comparison cast this
//   preserves the original low-word load, per-arm vtable loads, and increment.
// - Kept direct id/id2 rereads in the WM_COMMAND gate while retaining the
//   preloaded values for its call, matching the original tail exactly.

extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

class TDrawArea {
public:
    char gap_00[0x04];
    void* Wnd;
};

class TButtonPanel;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    virtual ~TPanel();
    VPAD4(1)
    VPAD2(5)
    VPAD1(7)
    virtual void set_redraw(int mode);
    VPAD32(9)
    VPAD4(41)
    virtual long action(TButtonPanel* panel, long code, long id, long id2);

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0x1C];
    TPanel* parent_panel;
    char gap_44[0xB0];
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    VPAD8(47)
    VPAD2(55)
    virtual void set_state(short state);

    long id[9];
    long id2[9];
    int buttonTypeValue;
    int drawTypeValue;
    int notifyTypeValue;
    void* sound;
    char gap_14C[0xA8];
    short num_states;
    short cur_state;

    void set_radio_button(void);
    void do_right_action(int ctrl);
};

void TButtonPanel::do_right_action(int ctrl) {
    if (this->buttonTypeValue == 3) {
        if ((int)this->cur_state == this->num_states - 1) {
            this->set_state(0);
        } else {
            this->set_state(this->cur_state + 1);
        }
    } else if (this->buttonTypeValue == 2) {
        this->set_radio_button();
    }

    short state = this->cur_state;
    long id_value = this->id[state];
    long id2_value = this->id2[state];

    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 6, id_value, id2_value);
    }

    if (this->notifyTypeValue == 1) {
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 4, id_value, id2_value);
            return;
        }
    } else if (this->id[this->cur_state] != 0 ||
               this->id2[this->cur_state] != 0) {
        SendMessageA(this->render_area->Wnd, 0x111, id_value, id2_value);
    }
}
