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

#ifndef BASEGAME_GROUPED_TU
class RGE_Prog_Info {
public:
    char gap_000[0x773];
    char cursor_file[0x105];
};

class TRegistry {
public:
    int RegGetInt(int use_user, const char* name);
    int RegSetInt(int use_user, const char* name, int value);
};

class TMousePointer {
public:
    char gap_000[0x254];

    TMousePointer(int mode);
    int setup(int custom_draw, TDrawArea* draw_area, char* base,
              int palette, int shape_number);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_004[0x08];
    RGE_Prog_Info* prog_info;
    char gap_010[0x4C - 0x10];
    TDrawArea* draw_area;
    char gap_050[0x54 - 0x50];
    int custom_mouse;
    char gap_058[0x1AC - 0x58];
    TRegistry* registry;
    char gap_1B0[0x1C0 - 0x1B0];
    TMousePointer* mouse_pointer;

protected:
    virtual int setup_mouse();
public:
    void mouse_off();
};
#endif

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
