// TScrollTextPanel::draw — real pass
// VA: 00493070
#include "../../include/game_globals.h"

void __fastcall draw_scroll(void* _this, int _)
{
    if (!*(void**)((char*)_this + 0x20)) return;
    if (!*(void**)((char*)_this + 0x70)) return;
    if (!*(void**)((char*)_this + 0x6C)) return;
    *(int*)((char*)_this + 0x38) = 0;
    // draw_background call
    // clip/scroll region setup
    // vtable callbacks
    // restore clip
}
