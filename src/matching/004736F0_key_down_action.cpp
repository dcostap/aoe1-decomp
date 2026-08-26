// VA: 004736F0 TButtonPanel::key_down_action (359 B)
// PDB source: Pnl_btn.cpp
//
// Attempt log:
// - Baseline reconstruction uses the period panel/button ownership: TPanel's
//   tab-order fields, TButtonPanel's key/button state, TDigital sound
//   playback, and the panel action virtual at +0xB4.  The four-key dispatch is
//   expressed as an ordinary switch with one shared tab-child tail.
// - Main-agent audit confirmed canonical panel/button/sound ownership and
//   natural shared-tail switch flow; exact bytes were revalidated.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

long TButtonPanel::key_down_action(long key, short ch, int a3, int a4, int a5) {
    TPanel* child;

    if (key_down != 0) {
        return 0;
    }

    switch (key) {
    case 0x28:
        if (a3 == 0 && a4 == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_next_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case 0x26:
        if (a3 == 0 && a4 == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_prev_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case 0x0D:
    case 0x20:
        if (disabled != 0 || a3 != 0 || a4 != 0) {
            break;
        }
        if (sound != 0) {
            if (sound->is_playing() != 0) {
                sound->stop();
            }
            sound->play();
        }
        key_down = key;
        is_down = 1;
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x44B);
        set_redraw(1);
        if (parent_panel != 0) {
            parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
        }
        return 1;

    default:
        break;
    }
    return 0;
}
