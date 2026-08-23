// attempt 6: direct non-virtual DrawSystem::Paint call via draw_area->draw_system
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);
#include "../../include/mouseptr_context.h"
void TMousePointer::off() {
    if (this->Shutdown == 0) {
        if (this->custom_draw != 0 && this->drawn != 0 && this->save_area_valid != 0) {
            this->erase();
        this->render_area->DrawSystem->Paint(&this->restore_rect);
        }
        SetCursor(0);
        this->active = 0;
        this->reset();
    }
}
