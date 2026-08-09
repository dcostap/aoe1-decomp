// VA: 004653E0 TPanel::wnd_proc
// Attempt log:
// baseline: the old approximate source was 824 rebuilt bytes, had no local frame,
// and was missing the direct get_mouse_info call.
// probes 2-4: added the typed get_mouse_info surface and moved mouse/key handlers
// out of the common child/command path. The helper fixed the call multiset and
// recovered the 0x0c frame; an unscoped modifier/local layout temporarily made a
// 0x10 frame, then scoping restored it. The out-of-line topology improved edit
// alignment but did not align the compiler's block order with the original.
// probes 5-8: made child traversal the default fallthrough, modeled the 0x400
// user-command and msg-0x111 switch, and tested switch-shaped input dispatch.
// The natural command switch reached exact size (870 bytes) and 30 calls; the
// sparse input-switch variants changed the virtual-call order and were rejected.
// probe 9: used the Panel.cpp-era local GetKeyState function-pointer alias. Best
// current result is exact size/frame/instruction count, 30 calls, 796 differing
// bytes, and 83.33% ordered-call alignment. Remaining structural drift starts
// after the prologue: VC5 places the mouse/key blocks before the original child
// and command fallthrough, and colors the selected target/register homes
// differently. The helper output flags remain clean typed locals; no parameter
// home casts or inline asm were used.
// probe 10: positive key-family spelling worsened ordered calls and was rolled
// back. Final validated source is the probe-9 canonical reconstruction; paused
// because the remaining block-order/register basin is not a bounded blind axis.
// Main-agent audit restored canonical panel/draw-area destructor ownership and
// removed the function-pointer cache retained solely for codegen metrics. Final
// audited check: exact 870-byte size/0xC frame, 30/30 calls with 83.33% ordered
// alignment, 798-byte diff.

extern "C" short (__stdcall* const GetKeyState)(int);

class TPanel;
struct tagPOINT { long x; long y; };
struct PanelNode { TPanel* panel; PanelNode* prev_node; PanelNode* next_node; };
struct TDrawArea { virtual ~TDrawArea(); void* Wnd; };

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
    virtual ~TPanel(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44();
    virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam); // +48
    virtual void v4c(); virtual void v50(); virtual void v54();
    virtual long handle_key_down(long key, short repeat, int a3, int a4, int a5); // +58
    virtual long handle_char(long ch, short repeat); // +5c
    virtual long handle_command(unsigned int w, long l); // +60
    virtual long handle_user_command(unsigned int w, long l); // +64
    virtual long handle_timer_command(unsigned int w, long l); // +68
    virtual long handle_scroll(long w, long l); // +6c
    virtual long handle_mouse_down(unsigned char button, long x, long y, int a4, int a5); // +70
    virtual long handle_mouse_move(long x, long y, int a3, int a4); // +74
    virtual long handle_mouse_up(unsigned char button, long x, long y, int a4, int a5); // +78
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y, int a4, int a5); // +7c

    char gap04[0x1c];
    TDrawArea* render_area; // +20
    char gap24[0x38];
    PanelNode* last_child_node; // +5c
    char gap60[0x0c];
    int active; // +6c

    void get_mouse_info(unsigned int keys, long packed_pos, tagPOINT& point,
                        int& focus_flag, int& capture_flag);
};

long TPanel::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    tagPOINT point;
    TPanel* target;
    PanelNode* node;
    long result;

    if (this->active == 0) {
        goto done;
    }

    if (msg <= 0x206) {
        if (msg >= 0x200) {
            goto mouse_input;
        } else if (msg != 0x100 && msg != 0x102 && msg != 0x104) {
            ;
        } else {
            goto keyboard_input;
        }
    }

    node = this->last_child_node;
    while (node != 0) {
        result = node->panel->wnd_proc(hwnd, msg, wParam, lParam);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    if (msg <= 0x400) {
        if (msg == 0x400) {
            return this->handle_user_command(wParam, lParam);
        }
        switch (msg - 0x111) {
        case 0:
            return this->handle_command(wParam, lParam);
        case 2:
            return this->handle_timer_command(wParam, lParam);
        case 3:
        case 4:
            return this->handle_scroll(wParam, lParam);
        }
    }

done:
    return 0;

mouse_input:
{
    int focus_flag;
    int capture_flag;
    if (this->render_area->Wnd != hwnd) {
        goto done;
    }
    if (panel_system.GetInputEnabled() == 0) {
        goto done;
    }

    this->get_mouse_info(wParam, lParam, point, focus_flag, capture_flag);
    target = this;
    if (panel_system.mouseOwner() != 0) {
        target = panel_system.mouseOwner();
    } else if (panel_system.keyboardOwner() != 0) {
        target = panel_system.keyboardOwner();
    } else if (panel_system.modalPanel() != 0) {
        target = panel_system.modalPanel();
    }

    switch (msg) {
    case 0x200:
        return target->handle_mouse_move(point.x, point.y, focus_flag, capture_flag);
    case 0x201:
        return target->handle_mouse_down(1, point.x, point.y, focus_flag, capture_flag);
    case 0x202:
        return target->handle_mouse_up(1, point.x, point.y, focus_flag, capture_flag);
    case 0x203:
        return target->handle_mouse_dbl_click(1, point.x, point.y, focus_flag, capture_flag);
    case 0x204:
        return target->handle_mouse_down(2, point.x, point.y, focus_flag, capture_flag);
    case 0x205:
        return target->handle_mouse_up(2, point.x, point.y, focus_flag, capture_flag);
    case 0x206:
        return target->handle_mouse_dbl_click(2, point.x, point.y, focus_flag, capture_flag);
    }
    goto done;
}

keyboard_input:
{
    int alt;
    int ctrl;
    int shift;
    if (this->render_area->Wnd != hwnd) {
        goto done;
    }
    if (panel_system.GetInputEnabled() == 0) {
        goto done;
    }

    target = this;
    if (panel_system.keyboardOwner() != 0) {
        target = panel_system.keyboardOwner();
    } else if (panel_system.modalPanel() != 0) {
        target = panel_system.modalPanel();
    }

    if (msg == 0x102) {
        return target->handle_char(wParam, (short)lParam);
    }

    alt = GetKeyState(0x12) < 0;
    ctrl = GetKeyState(0x11) < 0;
    shift = GetKeyState(0x10) < 0;
    return target->handle_key_down(wParam, (short)lParam, alt, ctrl, shift);
}
}
