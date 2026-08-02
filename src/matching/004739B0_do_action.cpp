// VA: 004739B0 do_action (230B)
// Pnl_btn.cpp
//
// Attempt log:
// - Reconstructed from the matched sibling Pnl_btn.cpp do_right_action
//   (00473AA0) which shares the state-advance (E0 setter), radio-button,
//   parent action, and WM_COMMAND structure. Reused its proven TPanel/
//   TButtonPanel vtable-pad surface verbatim.
// - Differences vs do_right_action: action codes 3/1 (vs 6/4), no ctrl
//   parameter (plain ret), and id/id2 are read inside the parent-panel
//   block via direct member access (not preloaded locals): the binary
//   loads [esi+1F6h]/id/id2 only after the parent_panel test and reuses
//   the tested id value in ecx for the SendMessageA push while reloading
//   id2 fresh.

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
    void do_action(void);
};

void TButtonPanel::do_action(void) {
    if (this->buttonTypeValue == 3) {
        if ((int)this->cur_state == this->num_states - 1) {
            this->set_state(0);
        } else {
            this->set_state(this->cur_state + 1);
        }
    } else if (this->buttonTypeValue == 2) {
        this->set_radio_button();
    }

    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 3, this->id[this->cur_state],
                                   this->id2[this->cur_state]);
    }

    if (this->notifyTypeValue == 1) {
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 1, this->id[this->cur_state],
                                       this->id2[this->cur_state]);
            return;
        }
    } else if (this->id[this->cur_state] != 0 ||
               this->id2[this->cur_state] != 0) {
        SendMessageA(this->render_area->Wnd, 0x111,
                     this->id[this->cur_state], this->id2[this->cur_state]);
    }
}
