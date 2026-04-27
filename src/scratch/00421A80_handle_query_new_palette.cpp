// VA: 00421A80 RGE_Base_Game::handle_query_new_palette (234 B)
// PDB source: basegame.cpp
// Packet-grounded: dispatch palette query to draw_system or GDI32 palette API

extern int InvalidateRect(void* hwnd, void* rect, int erase);
extern int TDrawSystem_HandleQueryNewPalette(void* ds, void* hwnd, unsigned int p2, unsigned int p3, long p4);
extern void* GetDC(void* hwnd);
extern void* TPanelSystem_currentPanel(void* sys);
extern void* TEasy_Panel_get_palette(void* panel);
extern void* SelectPalette(void* dc, void* pal, int force_bg);
extern int RealizePalette(void* dc);
extern int ReleaseDC(void* hwnd, void* dc);
extern void* panel_system;

struct Shim_21A80 {
    char p0[0x1C];
    void* prog_palette;        // +0x1C
    char p20[0x48 - 0x20];
    void* draw_system;         // +0x48
};

int RGE_Base_Game_handle_query_new_palette(
    Shim_21A80* self, void* hwnd, unsigned int msg, unsigned int wparam, long lparam)
{
    void* ds = self->draw_system;
    
    if (ds && *(unsigned char*)((char*)ds + 0x478) != 1 && *(unsigned char*)((char*)ds + 0x479) != 1) {
        InvalidateRect(hwnd, 0, 0);
        return TDrawSystem_HandleQueryNewPalette(ds, hwnd, wparam, lparam, (long)hwnd);
    }
    
    {
        void* dc = GetDC(hwnd);
        void* panel = TPanelSystem_currentPanel(panel_system);
        void* palette;
        
        if (panel) {
            void* panel2 = TPanelSystem_currentPanel(panel_system);
            palette = TEasy_Panel_get_palette(panel2);
            if (palette)
                palette = TEasy_Panel_get_palette(panel2);
        } else {
            palette = self->prog_palette;
            if (!palette)
                goto skip_select;
        }
        SelectPalette(dc, palette, 0);
        
skip_select:
        RealizePalette(dc);
        ReleaseDC(hwnd, dc);
        
        if (RealizePalette(dc))
            InvalidateRect(hwnd, 0, 0);
        
        if (self->draw_system)
            return TDrawSystem_HandleQueryNewPalette(self->draw_system, hwnd, wparam, lparam, lparam);
        
        return 1;
    }
}
