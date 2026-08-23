// BINARY NOTE: the canonical Drawarea context preserves the exact owner and
// the member-call ABI for HandleQueryNewPalette.
#include "../../include/drawarea_context.h"

void TDrawSystem::HandlePaletteChanged(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (hwnd != this->Wnd) {
        HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }
}
