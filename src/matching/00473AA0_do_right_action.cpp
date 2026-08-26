// VA: 00473AA0 do_right_action (209B)
// Pnl_btn.cpp
//
// Attempt log:
// - Reconstructed from the neighboring Pnl_btn.cpp actions: state buttons
//   advance through the E0 virtual setter, radio buttons call
//   set_radio_button, and the parent receives action codes 6/4 before the
//   non-NotifyAction path sends WM_COMMAND (0x111).
// - The setter takes a short state. Direct id/id2 rereads remain in the
//   WM_COMMAND gate while the preloaded values serve its call.

extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

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
