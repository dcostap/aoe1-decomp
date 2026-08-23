extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void* instance, const char* name);
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);
#include "../../include/mouseptr_context.h"

void TMousePointer::on(void) {
    if (this->Shutdown == 0) {
        if (this->custom_draw == 0) {
            SetCursor(LoadCursorA(0, (const char*)0x7F00));
        }
        this->active = 1;
    }
}
