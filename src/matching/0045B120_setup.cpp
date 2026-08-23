// attempt 1: natural mouse pointer setup with TShape load and cursor initialization
// baseline: 352 rebuilt bytes versus 353 original; call set was wrong because
// the final cursor initialization used wrapper names instead of the Mouseptr
// methods, and TShape lacked its trailing shape_info member.
// probe 2: using the actual Mouseptr methods, imported SetCursor, and the full
// 0x20-byte TShape restored all nine calls and produced an exact 353-byte match.
// The names/layout below retain the canonical TMousePointer/TDrawArea ownership
// proved by the exact Mouseptr siblings rather than decompiler cursor names.
#include <stdio.h>

#include "../../include/mouseptr_context.h"

extern TMousePointer* MouseSystem;
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void*);

int TMousePointer::setup(int custom_draw, TDrawArea* render_area, char* base, int palette, int max_cursors) {
    char file_name[260];
    MouseSystem = this;
    this->custom_draw = custom_draw;
    this->render_area = render_area;
    if (custom_draw == 0) return 1;
    if (render_area->DrawSystem->DrawType == 1) return 0;
    this->renderSurface = render_area->DrawSurface;
    this->PrimarySurface = render_area->DrawSystem->PrimarySurface;
    this->primary_area = render_area->DrawSystem->PrimaryArea;
    SetCursor(0);
    sprintf(file_name, "%s.slp", base);
    this->Cursor_Shape = new TShape(file_name, palette);
    if (this->Cursor_Shape == 0) return 0;
    if (!this->Cursor_Shape->is_loaded()) return 0;
    if (this->Cursor_Shape->FShape == 0) return 0;
    this->Max_Cursors = max_cursors;
    if (max_cursors < 1 || max_cursors > 16) return 0;
    this->Num_Cursors = this->Cursor_Shape->shape_count();
    if (this->Num_Cursors > this->Max_Cursors) return 0;
    if (!this->LoadCursors(base, palette, 0)) return 0;
    this->set_facet(0);
    this->set_game_facet(0);
    this->Setup = 1;
    return 1;
}
