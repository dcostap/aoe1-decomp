// attempt 2: natural shadow amount setter with virtual delete of old color table and palette-derived replacement

void TEasy_Panel::set_shadow_amount(long amount) {
    PALETTEENTRY palette_entries[256];

    if (amount == -1) {
        this->shadow_amount = 0;
    } else {
        this->shadow_amount = amount;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->palette != 0 && this->shadow_amount > 0) {
        if (GetPaletteEntries(this->palette, 0, 0x100, palette_entries)) {
            this->shadow_color_table = new RGE_Color_Table(this->draw_area, this->shadow_amount, 0, palette_entries);
        }
    }

    if (this->panel_window != 0) {
        this->redraw(2);
    }
}
