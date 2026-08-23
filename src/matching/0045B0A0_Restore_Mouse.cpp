// 0045B0A0 TMousePointer::Restore_Mouse
// Source: Mouseptr.cpp lines 163-185. 115 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 115-byte match confirmed via local check_function.py.
// First-pass match with correct member offsets from inventory type dumps.

#include "../../include/mouseptr_context.h"

int TMousePointer::Restore_Mouse(TDrawArea* param_1) {
    if (this->Shutdown == 0)
        return 0;

    if (this->custom_draw != 0) {
        if (this->Setup == 0)
            return 0;

        this->render_area = param_1;
        this->renderSurface = param_1->DrawSurface;
        this->PrimarySurface = param_1->DrawSystem->PrimarySurface;
        this->primary_area = param_1->DrawSystem->PrimaryArea;

        if (this->LoadCursors(0, -1, 1) == 0)
            return 0;

        this->Shutdown = 0;
    }

    return 1;
}
