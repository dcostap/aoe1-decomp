// VA: 00422B10 RGE_Base_Game::set_screen_size (430 B)
// PDB source: basegame.cpp
// Packet-grounded: check draw_area size, SetCursor/SetClassLong/mouse shutdown, or CreateICA+GetDeviceCaps, SetWindowLongA/SetWindowPos

extern void SetCursor(void* cur);
extern int SetClassLongA(void* hwnd, int idx, long val);
extern int TMousePointer_Shutdown_Mouse(void* mp);
extern int TDrawSystem_SetDisplaySize(void* ds, long w, long h, int flags);
extern int TDrawSystem_CheckSurfaces(void* ds);
extern void TDrawSystem_ClearRestored(void* ds);
extern void set_render_all(void* self);
extern void* CreateICA(const char* driver, const char* device, const char* port, const void* data);
extern int GetDeviceCaps(void* dc, int cap);
extern int DeleteDC(void* dc);
extern long SetWindowLongA(void* hwnd, int idx, long val);
extern int SetWindowPos(void* hwnd, void* after, int x, int y, int w, int h, int flags);
extern int GetWindowRect(void* hwnd, int* rect);
extern int GetClientRect(void* hwnd, int* rect);
extern int restore_mouse_after_paint;

// OFF-DECLARATION-ORDER struct: fields sorted by ascending offset
// Actual offsets: prog_window(+0x10), window_style(+0x24), draw_system(+0x48),
//   draw_area(+0x4C), mouse_pointer(+0x1C0)
#define Shim_22B10_mouse_pointer_offset 0x1C0

struct Shim_22B10 {
    char p0[0x10];
    void* prog_window;         // +0x10
    char p14[0x24 - 0x14];
    int window_style;          // +0x24
    char p28[0x48 - 0x28];
    void* draw_system;         // +0x48
    char p4C[4];
    void* draw_area;           // +0x4C
    // +0x50 to +0x1C0 not listed here (accessed via pointer math)
};

void RGE_Base_Game_set_screen_size(Shim_22B10* self, long w, long h)
{
    int win_rect[4];
    int cli_rect[4];
    void* dc;
    int dev_w, dev_h;
    long style;
    int idx1, idx2;
    
    if (self->draw_area && *(int*)((char*)self->draw_area + 0x18) == w && *(int*)((char*)self->draw_area + 0x1C) == h)
        return;
    
    if (self->draw_system &&
        *(unsigned char*)((char*)self->draw_system + 0x478) == 2 &&
        *(unsigned char*)((char*)self->draw_system + 0x479) == 2)
    {
        SetCursor(0);
        SetClassLongA(self->prog_window, -12, 0);
        TMousePointer_Shutdown_Mouse(*(void**)((char*)self + 0x1C0));
        TDrawSystem_SetDisplaySize(self->draw_system, w, h, 8);
        TDrawSystem_CheckSurfaces(self->draw_system);
        TDrawSystem_ClearRestored(self->draw_system);
        set_render_all(self);
        restore_mouse_after_paint = 1;
        return;
    }
    
    dev_w = 0;
    dev_h = 0;
    dc = CreateICA("DISPLAY", 0, 0, 0);
    if (dc) {
        dev_w = GetDeviceCaps(dc, 8);
        dev_h = GetDeviceCaps(dc, 10);
        DeleteDC(dc);
    }
    
    if (w > dev_w || h > dev_h)
        return;
    
    if (dev_w == (int)w && dev_h == (int)h) {
        style = 0x92080000;
        self->window_style = style;
        SetWindowLongA(self->prog_window, -16, style);
        SetWindowLongA(self->prog_window, -12, style);
    } else {
        style = 0x12CA0000;
        self->window_style = style;
        SetWindowLongA(self->prog_window, -12, style);
        SetWindowLongA(self->prog_window, -16, style);
    }
    
    SetWindowPos(self->prog_window, 0, 0, 0, w, h, 0);
    GetWindowRect(self->prog_window, win_rect);
    GetClientRect(self->prog_window, cli_rect);
    
    if (win_rect[2] - win_rect[0] != w || win_rect[3] - win_rect[1] != h) {
        SetWindowPos(self->prog_window, 0,
            win_rect[0], win_rect[1],
            w + (cli_rect[2] - (win_rect[2] - win_rect[0])),
            h + (cli_rect[3] - (win_rect[3] - win_rect[1])),
            0);
    }
}
