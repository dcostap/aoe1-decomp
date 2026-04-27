// VA: 0041FF20 RGE_Base_Game::check_paint (221 B)
// PDB source: basegame.cpp
// Packet-grounded: check ready/iconic/active, surface check

extern int CheckSurfaces(void* ds);
extern void ClearRestored(void* ds);
extern void set_render_all(void* self);
extern int GetUpdateRect(void* hwnd, void* rect, int erase);
extern int ValidateRect(void* hwnd, void* rect);
extern int IsIconic(void* hwnd);
extern void clear_window(void* self);
extern int DestroyWindow(void* hwnd);

struct Shim_1FF20 {
    char p0[8];
    int prog_ready;
    char p0C[0x10 - 0x0C];
    int prog_active;
    char p14[0x1C - 0x14];
    void* draw_system;
    void* prog_window;
};

int RGE_Base_Game_check_paint(Shim_1FF20* self)
{
    if (!self->prog_ready) { clear_window(self); ValidateRect(self->prog_window, 0); return 0; }
    if (IsIconic(self->prog_window)) { ValidateRect(self->prog_window, 0); return 0; }
    if (!self->prog_active) {
        if (GetUpdateRect(self->prog_window, 0, 0)) ClearRestored(self->draw_system);
        ValidateRect(self->prog_window, 0);
        return 0;
    }
    {
        int r = CheckSurfaces(self->draw_system);
        if (r == 2) { ClearRestored(self->draw_system); set_render_all(self); }
        else if (r == 3) { ValidateRect(self->prog_window, 0); DestroyWindow(self->prog_window); return 0; }
        else if (r != 1) return 1;
    }
    return 0;
}
