// VA: 004653E0 TPanel::wnd_proc
// Attempt log:
// try 1: natural reconstruction from packet: active guard, child-chain dispatch,
// mouse/key/command/timer/scroll switch families, panel-system owner selection, and GetKeyState modifier path. Compiled too small (832B vs 870B).
// try 2: temporary diagnostic-only padding branch reached byte compare, then removed. Diagnostic was broad mismatch (81.4943% positional / 137.8161% edit); prologue had no original 0x0c local frame and register/branch layout was very different.
// Blockers observed from packet: original calls helper 00466170 to decode mouse lParam/wParam into stack locals before dispatch; source model currently computes x/y inline. Original tests render_area->hwnd and input enabled before owner selection in two separate mouse/key families, uses dense switch/jump-table shapes, and has specific shared epilogues. Current model has approximate behavior but wrong local topology and call surfaces.
// GIVEUP: broad model/layout mismatch remains; no accepted_drift proposal and no inline asm used.

extern "C" short (__stdcall* const GetKeyState)(int);

class TPanel;
struct ChildNode { TPanel* panel; ChildNode* next; };
struct RenderArea { int gap0; void* hwnd; };

class TPanelSystem {
public:
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    int GetInputEnabled();
};
extern TPanelSystem panel_system;

class TPanel {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44();
    virtual int wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam); // +48
    virtual void v4c(); virtual void v50(); virtual void v54();
    virtual int handle_key_down(long key, short repeat, int shift, int ctrl, int alt); // +58
    virtual int handle_char(long ch, short repeat); // +5c
    virtual int handle_command(unsigned int w, long l); // +60
    virtual int handle_user_command(unsigned int w, long l); // +64
    virtual int handle_timer_command(unsigned int w, long l); // +68
    virtual int handle_scroll(long w, long l); // +6c
    virtual int handle_mouse_down(unsigned char button, long x, long y, int shift, int ctrl); // +70
    virtual int handle_mouse_move(long x, long y, int shift, int ctrl); // +74
    virtual int handle_mouse_up(unsigned char button, long x, long y, int shift, int ctrl); // +78
    virtual int handle_mouse_dbl_click(unsigned char button, long x, long y, int shift, int ctrl); // +7c

    char gap04[0x1c];
    RenderArea* render_area; // +20
    char gap24[0x38];
    ChildNode* children; // +5c
    char gap60[0x0c];
    int active; // +6c
};

int TPanel::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    if (this->active == 0) return 0;

    if (msg >= 0x200 && msg <= 0x206) {
        if (this->render_area->hwnd != hwnd) return 0;
        if (!panel_system.GetInputEnabled()) return 0;
        TPanel* target;
        if (panel_system.mouseOwner() != 0) target = panel_system.mouseOwner();
        else if (panel_system.keyboardOwner() != 0) target = panel_system.keyboardOwner();
        else if (panel_system.modalPanel() != 0) target = panel_system.modalPanel();
        else target = this;

        long x = (short)(lParam & 0xffff);
        long y = (short)((unsigned long)lParam >> 16);
        switch (msg) {
        case 0x200:
            return target->handle_mouse_move(x, y, wParam, 0);
        case 0x201:
            return target->handle_mouse_down(1, x, y, wParam, 0);
        case 0x202:
            return target->handle_mouse_up(1, x, y, wParam, 0);
        case 0x203:
            return target->handle_mouse_dbl_click(1, x, y, wParam, 0);
        case 0x204:
            return target->handle_mouse_down(2, x, y, wParam, 0);
        case 0x205:
            return target->handle_mouse_up(2, x, y, wParam, 0);
        case 0x206:
            return target->handle_mouse_dbl_click(2, x, y, wParam, 0);
        }
    } else if (msg == 0x100 || msg == 0x102 || msg == 0x104) {
        if (this->render_area->hwnd != hwnd) return 0;
        if (!panel_system.GetInputEnabled()) return 0;
        TPanel* target;
        if (panel_system.keyboardOwner() != 0) target = panel_system.keyboardOwner();
        else if (panel_system.modalPanel() != 0) target = panel_system.modalPanel();
        else target = this;
        if (msg == 0x100 || msg == 0x104) {
            int shift = (GetKeyState(0x10) < 0);
            int ctrl = (GetKeyState(0x11) < 0);
            int alt = (GetKeyState(0x12) < 0);
            return target->handle_key_down(wParam, (short)lParam, shift, ctrl, alt);
        }
        return target->handle_char(wParam, (short)lParam);
    }

    ChildNode* n = this->children;
    while (n != 0) {
        if (n->panel->wnd_proc(hwnd, msg, wParam, lParam)) return 1;
        n = n->next;
    }

    if (msg <= 0x400) {
        if (msg == 0x400) return this->handle_user_command(wParam, lParam);
        switch (msg) {
        case 0x111: return this->handle_command(wParam, lParam);
        case 0x113: return this->handle_timer_command(wParam, lParam);
        case 0x115: return this->handle_scroll(wParam, lParam);
        }
    }
    return 0;
}
