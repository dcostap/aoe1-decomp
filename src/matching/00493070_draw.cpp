// TScrollTextPanel::draw — real pass
// VA: 00493070
//
// Canonical ownership (binary-proven offsets):
//   +0x20 render_area (TDrawArea*), +0x38 need_redraw, +0x6C active,
//   +0x70 field_70, +0x88 clip_rgn, +0xF8 line_count (short),
//   +0x104 font, +0x120/+0x124 text_color1/text_color2.
// Virtual slots: 0x28 draw_setup(int), 0x2C draw_finish(), 0x30 draw().
// Direct base calls: TTextPanel::draw_background (0047D3D0),
// TTextPanel::draw_border (0047D570), TScrollTextPanel::draw_scrolled_line
// (00493160). IAT: SelectClipRgn (88A5DC), SelectObject (88A59C),
// SetBkMode (88A5EC). PDB lines 500-540, scr_cred.cpp.
//
// Attempt log:
// - baseline: natural guarded reconstruction; draw_scrolled_line declared
//   with the exact ?draw_scrolled_line@TScrollTextPanel@@QAEXPAXFFKK@Z
//   surface, GetDc/ReleaseDc with char* (PAD) like the matched donors.

#include "../../include/scr_cred_context.h"

void TScrollTextPanel::draw()
{
    this->need_redraw = 0;
    if (this->render_area != 0 && this->field_70 != 0 && this->active != 0)
    {
        this->draw_background();
        this->draw_setup(0);
        void* dc = this->render_area->GetDc((char*)s_scr_cred_draw_005862e0);
        if (dc != 0)
        {
            SelectClipRgn(dc, this->clip_rgn);
            void* old_font = SelectObject(dc, this->font);
            SetBkMode(dc, 1);
            for (short i = 0; i < this->line_count; i++)
            {
                this->draw_scrolled_line(dc, i, i,
                                         this->text_color1, this->text_color2);
            }
            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc((char*)s_scr_cred_draw_005862e0);
        }
        this->draw_border();
        this->draw_finish();
    }
}
