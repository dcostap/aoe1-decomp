// VA: 0045B5D0 TMousePointer::create_surfaces
// Exact-finish retrospective:
// - Evidence: the original has a counted loop with `jl` back to the cursor
//   body. Its success cleanup follows that branch, and its failure cleanup is
//   after success. The original also uses the left operand `0 < Max_Cursors`.
// - Decisive change: replace the guarded do/while with a natural counted
//   `for` loop. This removes the extra jump and six bytes.
// - Walkback: restoring the do/while rebuilt 400 bytes with a 173-byte diff.
//   Joining `i = 0` into the for header stayed exact. Post-increment also
//   stayed exact, so the source keeps the period-plausible `i++` spelling.
//   Changing the guard to `Max_Cursors > 0` rebuilt 396 bytes with a 159-byte
//   diff. The original operand order is required.
// - Required changes: the counted-loop topology and `0 < Max_Cursors`.
//   The separate index assignment was incidental and is removed.
// - BINARY NOTE: allocation publishes each cursor before Init. A null
//   allocation or failed Init returns zero. The save area follows the same
//   ownership and fault order. All seven direct calls, EH exits, and the
//   394-byte boundary match under the registered Mouseptr.cpp context.

#include "../../include/mouseptr_context.h"

extern "C" int sprintf(char* buffer, const char* format, ...);

int TMousePointer::create_surfaces()
{
    int i;
    char NameBuf[32];

    if (this->custom_draw == 0) {
        return 1;
    }

    if (this->save_area == 0 && this->Max_CX > 0 && this->Max_CY > 0) {
        this->save_area = new TDrawArea("Mouse Save area", 0);
        if (this->save_area == 0) {
            return 0;
        }
        if (this->save_area->Init(this->render_area->DrawSystem, this->Max_CX, this->Max_CY, 0, 0) == 0) {
            return 0;
        }
    }

    if (this->Mouse_Mode == 0 && 0 < this->Max_Cursors) {
        for (i = 0; i < this->Max_Cursors; i++) {
            if (this->cursors[i] == 0) {
                sprintf(NameBuf, "Mouse Cursor #%d", i);
                this->cursors[i] = new TDrawArea(NameBuf, 0);
                if (this->cursors[i] == 0) {
                    return 0;
                }
                if (this->cursors[i]->Init(this->render_area->DrawSystem, this->Max_CX, this->Max_CY, 0, 0) == 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}
