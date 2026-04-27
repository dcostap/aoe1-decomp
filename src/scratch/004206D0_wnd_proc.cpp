// VA: 004206D0 RGE_Base_Game::wnd_proc (2181 B)
// Calling convention: __stdcall (hwnd, msg, wparam, lparam)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass — main Windows message pump

extern void color_log(unsigned char a, unsigned char b, int c);
extern int TSound_Driver_handle_messages(void* sd, void* hwnd, unsigned int msg, unsigned int wp, unsigned int lp);
extern int TMusic_System_handle_messages(void* ms, void* hwnd, unsigned int msg, unsigned int wp, unsigned int lp);
extern int TPanelSystem_handle_message(void* ps, void* hwnd, unsigned int msg, unsigned int wp, unsigned int lp);
extern int TPanelSystem_currentPanel(void* ps);
extern int DefWindowProcA(void* hwnd, unsigned int msg, unsigned int wp, unsigned int lp);
extern void TDrawSystem_ModifyPalette(void* ds, int a, int b, void* ptr);
extern void TDrawSystem_CheckSurfaces(void* ds);
extern void TDrawSystem_SetDisplaySize(void* ds, int w, int h, int flags);
extern void TMousePointer_Shutdown_Mouse(void* mp);
extern void set_render_all(void* self);
extern int SetCursorPos(int x, int y);
extern int SetCapture(void* hwnd);
extern int ReleaseCapture(void);
extern int ShowWindow(void* hwnd, int cmd);
extern int SetWindowPos(void* hwnd, void* after, int x, int y, int w, int h, int flags);

extern unsigned long panel_system;
extern int restore_mouse_after_paint;

struct Shim_wndproc {
    char gap00[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    void* field_14;            // +0x14
    void* field_18;            // +0x18
    void* field_1C;            // +0x1C
    void* field_20;            // +0x20
    int field_24;              // +0x24
    int field_28;              // +0x28
    int field_2C;              // +0x2C
    int field_30;              // +0x30
    int field_34;              // +0x34
    int field_38;              // +0x38
    int field_3C;              // +0x3C
    int error_code;            // +0x40
    int field_44;              // +0x44
    void* draw_system;         // +0x48
    void* draw_area;           // +0x4C
    unsigned char field_50;    // +0x50
    char gap51[3];
    int mouse_inactive;        // +0x54
    short field_58;            // +0x58
    void* shapes;              // +0x5C
    void* sound_system;        // +0x60
    void* music_system;        // +0x64
    char gap68[0x1B0 - 0x68];
    int game_mode;             // +0x1B0
    char gap1B4[0x1C0 - 0x1B4];
    void* mouse_pointer;       // +0x1C0
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;             // +0x1D4 (cursor handle)
    int field_1D8;
    char gap1DC[0x8E8 - 0x1DC];
    int field_8E8;             // +0x8E8
    int field_8EC;             // +0x8EC
};

int __stdcall RGE_Base_Game_wnd_proc(Shim_wndproc* self, void* hwnd, unsigned int msg, unsigned int wp, unsigned int lp)
{
    int handled = 0;
    
    // Color log entry
    color_log(0x24, 0x24, 3);
    
    // Mouse-move window messages range 0x201-0x206
    if (msg >= 0x201 && msg <= 0x206) {
        color_log(0x4C, 0x4C, 4);
        handled = 1;
    }
    
    // Restore key params
    // EBP = hwnd, EDI = msg, EBX = wparam, ESI = self
    
    // Forward to sound driver
    if (self->sound_system) {
        TSound_Driver_handle_messages(self->sound_system, hwnd, msg, wp, lp);
    }
    
    color_log(0x24, 0x16, 3);
    
    // Forward to music system
    if (self->music_system) {
        TMusic_System_handle_messages(self->music_system, hwnd, msg, wp, lp);
    }
    
    color_log(0x24, 0x4C, 3);
    
    // Forward to panel system
    void* panelResult = (void*)TPanelSystem_handle_message((void*)&panel_system, hwnd, msg, wp, lp);
    
    // If panel handled it AND msg is not WM_COMMAND(0x111) and not WM_INITDIALOG(0x110)
    if (panelResult && msg != 0x200 && msg != 0x113) {
        // Use the panel result directly
        // (code continues with large switch on lparam msg)
    }
    
    // Large message switch
    switch (msg) {
    case 2: // WM_DESTROY
        // ...
        break;
    case 5: // WM_SIZE
        if (self->field_14) {
            // Get window/Client rect, handle size
        }
        break;
    case 6: // WM_ACTIVATE
        // handle activation
        break;
    case 0x0F: // WM_PAINT-ish
        // Handle palette changes
        break;
    case 0x1C: // WM_ACTIVATEAPP
        // Handle app activation
        break;
    case 0x10: // WM_CLOSE
        // ...
        break;
    case 0x11: // WM_ERASEBKGND
        // return 1;
        break;
    case 0x24: // WM_GETMINMAXINFO
        // ...
        break;
    case 0x7E: // WM_DISPLAYCHANGE
        // ...
        break;
    case 0x100: // WM_KEYDOWN
    case 0x101: // WM_KEYUP
    case 0x102: // WM_CHAR
        // Forward to panel system
        break;
    case 0x111: // WM_COMMAND
        // Forward to panel command
        break;
    case 0x113: // WM_TIMER
        // Timer handling
        break;
    case 0x200: // WM_MOUSEMOVE
        // Mouse tracking
        break;
    case 0x201: // WM_LBUTTONDOWN
    case 0x204: // WM_RBUTTONDOWN
    case 0x207: // WM_MBUTTONDOWN
        // Mouse buttons
        break;
    default:
        return DefWindowProcA(hwnd, msg, wp, lp);
    }
    
    if (handled) {
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return 0;
    }
    
    color_log(0x24, 0x5F, 3);
    return DefWindowProcA(hwnd, msg, wp, lp);
}
