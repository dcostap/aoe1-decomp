// attempt 2: natural focus handling: load cursor, switch draw palette, redraw, and toggle IME

void TEasy_Panel::set_focus(int focus) {
    TPanel::set_focus(focus);

    if (this->focused != 0) {
        if ((this->cursor_file[0] != 0 || this->cursor_id >= 0) && rge_base_game->mouse_pointer != 0) {
            rge_base_game->mouse_pointer->LoadCursors(this->cursor_file, this->cursor_id, 0);
        }

        if (this->draw_area != 0 && this->draw_area->DrawSystem != 0) {
            void* pal = this->palette;
            if (pal == 0) {
                pal = rge_base_game->prog_palette;
            }
            if (pal != 0 && this->draw_area->DrawSystem->Pal != pal) {
                this->draw_area->Clear(0, 0);
                this->draw_area->DrawSystem->Paint(0);
                this->draw_area->DrawSystem->SetPalette(pal);
                // BINARY NOTE: this is TPanel::set_redraw at vslot +0x20.
                this->set_redraw((TPanel::RedrawMode)2);
            }
        }
    }

    if (this->enable_ime != 0) {
        if (this->focused != 0) {
            panel_system.EnableIME();
        } else {
            panel_system.DisableIME();
        }
    }
}
