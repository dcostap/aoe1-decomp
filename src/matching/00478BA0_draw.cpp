// TListPanel::draw - draw items in the visible range
//
// The inherited panel fields and the TTextPanel line/color fields are kept
// named here so the proven offsets remain part of the source model.
//
// Attempt log: canonical inherited offsets, the imported GDI surface, the
// external draw string, the short draw_line ABI, the focus/capture predicate,
// and the counted visible-line loop produce the exact 303-byte owner.
// The complete Pnl_lst wrapper confirms all 13 ordered calls and the original
// panel inheritance. Keep the typed drawing ownership and loop bounds.

void TListPanel::draw()
{
    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    void* dc = this->render_area->GetDc(s_pnl_lst__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        void* old_font = SelectObject(dc, this->font);
        SetBkMode(dc, 1);

        for (short line = this->top_line, line_index = 0;
             line <= this->bot_line; ++line, ++line_index) {
            if (this->drawHighlightBar != 0 &&
                (this->have_focus != 0 || this->mouse_captured != 0) &&
                line_index + this->top_line == this->cur_line) {
                this->draw_line(dc, line_index, line,
                                this->highlightTextColor1,
                                this->highlightTextColor2);
            } else {
                this->draw_line(dc, line_index, line,
                                this->text_color1, this->text_color2);
            }
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc(s_pnl_lst__draw);
    }

    this->draw_border();
    this->draw_highlight_bar();
    this->draw_finish();
}
