// VA: 004739B0 do_action (230B)
// Pnl_btn.cpp
//
// Attempt log:
// - Reconstructed from the matched sibling Pnl_btn.cpp do_right_action
//   (00473AA0) which shares the state-advance (E0 setter), radio-button,
//   parent action, and WM_COMMAND structure. Reused its reviewed panel and
//   button ownership.
// - Differences vs do_right_action: action codes 3/1 (vs 6/4), no ctrl
//   parameter (plain ret), and id/id2 are read inside the parent-panel block
//   via direct member access.

extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

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
