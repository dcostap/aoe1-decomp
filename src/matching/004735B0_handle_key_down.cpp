// VA: 004735B0 TButtonPanel::handle_key_down (307 B)
// PDB source: Pnl_btn.cpp
//
// Attempt log:
// - Baseline reconstruction uses the period panel/button ownership: TPanel's
//   active/tab/focus/parent fields, TButtonPanel's hotkey and button state,
//   TDigital sound playback, and the panel action virtual at +0xB4.
// - Main-agent audit confirmed canonical panel/button/sound ownership and
//   natural hotkey flow; exact bytes were revalidated after promotion.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

long TButtonPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    if (active != 0 && disabled == 0 && a3 == 0 && a4 == 0 &&
        hotkey != 0 && key == hotkey && key_down == 0 &&
        (hotkey_shift == 0 || a5 == hotkey_shift)) {
        if (tab_stop != 0 && parent_panel != 0 && have_focus == 0) {
            parent_panel->set_curr_child(this);
        }
        if (sound != 0) {
            if (sound->is_playing() != 0) {
                sound->stop();
            }
            sound->play();
        }
        key_down = key;
        is_down = 1;
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x421);
        set_redraw(1);
        if (parent_panel != 0) {
            parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
        }
        return 1;
    }
    return TPanel::handle_key_down(key, ch, a3, a4, a5);
}
