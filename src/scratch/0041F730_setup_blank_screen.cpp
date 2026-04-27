// VA: 0041F730 RGE_Base_Game::setup_blank_screen (196 B) EH-framed
// PDB source: basegame.cpp
// Packet-grounded: operator_new + TScreenPanel ctor + setup + set_current + render_all + SendMessage

extern void* operator_new(unsigned int size);
extern int TScreenPanel_ctor(void* panel, const char* name);
extern int TScreenPanel_setup(void* panel, void* draw_area, void* parent, int x, int y, int flags);
extern void set_current_panel(const char* name, int flag);
extern void set_render_all(void* self);
extern long SendMessageA_impl(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);

struct Shim_BaseGame {
    char pad[0x10];
    void* prog_window;        // +0x10
    char pad14[0x4C - 0x14];
    void* draw_area;          // +0x4C
};

int RGE_Base_Game_setup_blank_screen(Shim_BaseGame* self)
{
    void* panel;
    int r;
    
    panel = operator_new(0x478);
    if (panel)
        TScreenPanel_ctor(panel, "Blank Screen");
    
    if (panel == 0)
        return 0;
    
    r = TScreenPanel_setup(panel, self->draw_area, 0, -1, 0);
    if (r == 0)
        return 0;
    
    set_current_panel("Blank Screen", 0);
    set_render_all(self);
    SendMessageA_impl(self->prog_window, 0x0F, 0, 0);
    return 1;
}
