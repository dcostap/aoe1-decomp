// VA: 00421830 RGE_Base_Game::handle_activate (215 B)
// PDB source: basegame.cpp
// Packet-grounded: activation state/auto-pause/virtual dispatch

extern void* currentPanel(void* sys);
extern int singlePlayerGame(void* self);
extern int get_paused(void* self);
extern void set_paused(void* self, int flag, int unknown);
extern void panel_dispatch(void* panel);
extern void dispatch_110(void* self);
extern void dispatch_114(void* self);
extern void* panel_system;
extern void pad_0();
extern void pad_1();
extern void pad_2();
extern void pad_3();


struct Shim_21830 {
    void* vt;
    char p4[0x10 - 4];
    int prog_active;
    char p14[0x18 - 0x14];
    int prog_mode;
    char p1C[0x24 - 0x1C];
    int auto_paused;
};

int RGE_Base_Game_handle_activate(Shim_21830* self, void* hwnd, unsigned int msg, unsigned int active, long lparam)
{
    if (active) {
        self->prog_active = 1;
        if ((self->prog_mode == 4 || self->prog_mode == 6 || self->prog_mode == 7) && self->auto_paused == 1) {
            self->auto_paused = 0;
            set_paused(self, 0, 0);
        }
        if (currentPanel(panel_system)) panel_dispatch(currentPanel(panel_system));
        dispatch_110(self);
    } else {
        self->prog_active = 0;
        if ((self->prog_mode == 4 || self->prog_mode == 6 || self->prog_mode == 7) && singlePlayerGame(self) && !get_paused(self)) {
            self->auto_paused = 1;
            set_paused(self, 1, 0);
        }
        dispatch_114(self);
    }
        pad_0();
        pad_1();
        pad_2();
        pad_3();

    return 1;
}
