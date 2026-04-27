// VA: 0048F530 TribeAchievementsScreen::wnd_proc (146 B)
// PDB source: scr_ach.cpp
// Packet-grounded: WM_CLOSE(0x10) confirm dialog, else base class wnd_proc

extern int confirmed_close;
extern void* rge_base_game;
extern int IsIconic(void* hwnd);
extern int TPanel_get_string(void* self, int id);
extern int TEasy_Panel_popupYesNoDialog(void* self, const char* msg, void* unk, int a, int b);
extern long TPanel_wnd_proc(void* self, void* h1, unsigned int msg, unsigned int w, long l);

// Shim: +0x20 = draw_surface (has hwnd at +0x04)
struct Shim_wndproc_F530 {
    char gap00[0x20];
    void* draw_surface;        // +0x20
};

long TribeAchievementsScreen_wnd_proc(Shim_wndproc_F530* self, void* h1, unsigned int msg, unsigned int w, long l)
{
    if (msg == 0x10 && !confirmed_close) {
        confirmed_close = 1;
        int mode = *(int*)((char*)rge_base_game + 0x1B0);
        if (mode == 4 || mode == 5 || mode == 6 || mode == 7) {
            if (!IsIconic(*(void**)((char*)self->draw_surface + 4))) {
                const char* str = (const char*)TPanel_get_string(self, 0xC1D);
                TEasy_Panel_popupYesNoDialog(self, str, 0, 0x1C2, 100);
                return 1;
            }
        }
    }
    return TPanel_wnd_proc(self, h1, msg, w, l);
}
