// VA: 0041EBF0 RGE_Base_Game::setup_mouse (270 B) EH-framed
// PDB source: basegame.cpp lines 2404-2431
//
// Probe 1 baseline used free-function shims and included decompiler-inferred
// helper calls.  The packet proves the period setup flow is only the registry
// mode read/write, TMousePointer construction/setup, and mouse_off.
// Probe 2: replaced the shims with typed member calls and a real new-expression
// under the basegame /GX context; call set and layout then aligned.
// Probe 3: a direct-result switch preserved EAX but used the wrong branch order.
// Probe 4: a register result local plus a separate constructor-mode local
// reproduced the original branch/lifetime topology exactly.
// The result==2 arm intentionally leaves custom_type unassigned: the original
// reloads that local's incoming stack home before construction, so initializing
// it would change the observed behavior and bytes.
// Main-agent audit restored the canonical base-game destructor surface;
// emitted code remains exact.

#include <new.h>

class TDrawArea;




int RGE_Base_Game::setup_mouse()
{
    register int result;
    int custom_type;
    TMousePointer* mouse_pointer;

    result = this->registry->RegGetInt(0, "Custom Mouse");
    if (result == -1) {
        this->registry->RegSetInt(0, "Custom Mouse", 0);
        custom_type = 0;
    }
    else if (result == 1) {
        custom_type = result;
    }
    else if (result == 2) {
        this->custom_mouse = 0;
    }
    else {
        custom_type = 0;
    }

    mouse_pointer = new TMousePointer(custom_type);
    this->mouse_pointer = mouse_pointer;
    if (mouse_pointer == 0)
        return 0;

    if (mouse_pointer->setup(this->custom_mouse, this->draw_area,
                             this->prog_info->cursor_file,
                             0xC738, 10) == 0)
        return 0;

    this->mouse_off();
    return 1;
}
