// VA: 0041E7D0 RGE_Base_Game::setup_main_window (330 B)
// PDB source: basegame.cpp
// Packet-grounded: GetSystemMetrics, fullscreen/window check, CreateWindowExA, GetWindowRect/ClientRect, SetWindowPos, ShowWindow, panel IME disable

extern int GetSystemMetrics(int index);
extern void* CreateWindowExA(int ex, const char* cls, const char* title, int style, int x, int y, int w, int h, void* parent, void* menu, void* inst, void* param);
extern int GetWindowRect(void* hwnd, int* rect);
extern int GetClientRect(void* hwnd, int* rect);
extern int SetWindowPos(void* hwnd, void* after, int x, int y, int w, int h, int flags);
extern int ShowWindow(void* hwnd, int cmd);
extern int UpdateWindow(void* hwnd);
extern void* SetFocus(void* hwnd);
extern void TPanelSystem_DisableIME(int sys);
extern int panel_system;

struct Shim_1E7D0 {
    char p0[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char p14[0x4C - 0x14];
    void* draw_area;           // +0x4C
};

int RGE_Base_Game_setup_main_window(Shim_1E7D0* self)
{
    int scr_w, scr_h;
    int style;
    int x, y, w, h;
    int win_rect[4];
    int cli_rect[4];
    void* info;
    
    scr_w = GetSystemMetrics(0);
    scr_h = GetSystemMetrics(1);
    
    info = self->prog_info;
    if (*(int*)((char*)info + 0x894) == 0 &&
        (scr_w != *(int*)((char*)info + 0x8E0) || scr_h != *(int*)((char*)info + 0x8E4)))
    {
        style = 0x2CA0000;
        self->prog_window = CreateWindowExA(
            0, (const char*)info, *(const char**)((char*)info + 0x410),
            style, 0, 0,
            *(int*)((char*)info + 0x8E0), *(int*)((char*)info + 0x8E4),
            0, 0, *(void**)((char*)info + 0x410), 0);
    } else {
        style = 0x82080000;
        self->prog_window = CreateWindowExA(
            0, (const char*)info, *(const char**)((char*)info + 0x410),
            style, 0, 0, scr_w, scr_h,
            0, 0, *(void**)((char*)info + 0x410), 0);
    }
    
    if (!self->prog_window)
        return 0;
    
    GetWindowRect(self->prog_window, win_rect);
    GetClientRect(self->prog_window, cli_rect);
    
    if (cli_rect[3] != *(int*)((char*)info + 0x8E0) || cli_rect[0] != *(int*)((char*)info + 0x8E4)) {
        SetWindowPos(self->prog_window, 0,
            win_rect[0], win_rect[1],
            ((win_rect[2] - win_rect[0]) - cli_rect[3]) + *(int*)((char*)info + 0x8E0),
            ((*(int*)((char*)info + 0x8E4) - win_rect[1]) - cli_rect[0]) + cli_rect[2],
            0);
    }
    
    if (*(int*)((char*)info + 0x894)) {
        ShowWindow(self->prog_window, *(int*)((char*)info + 0x618));
        UpdateWindow(self->prog_window);
        SetFocus(self->prog_window);
    }
    
    *(int*)0x5B236C = (int)self->prog_window;  // AppWnd
    TPanelSystem_DisableIME(panel_system);
    return 1;
}
