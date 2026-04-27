// VA: 0041E920 RGE_Base_Game::setup_graphics_system (672 B)
// PDB source: basegame.cpp
// EH-framed (FS:[0] prolog/epilog). Needs /GX rsp for EH frame.
// Packet-grounded structural first-pass

extern void* operator_new(unsigned int size);
extern int GetDC(void* hwnd);
extern int GetDeviceCaps(int dc, int cap);
extern int ReleaseDC(void* hwnd, int dc);
extern int TDrawSystem_ctor(void* ds);
extern void TDrawSystem_CheckAvailModes(void* ds, int fullScreen);
extern int TDrawSystem_IsModeAvail(void* ds, int w, int unused, int bpp);
extern int TDrawSystem_Init(void* ds, void* inst, void* hwnd, void* pal, int a, int b, int w, int h, int c);
extern int TDrawArea_Clear(void* da, void* rect, int flag);
extern int TDrawSystem_Paint(void* ds, void* rect);
extern int TPanelSystem_release_palette(void* ps, void* pal);
extern void* TPanelSystem_get_palette(void* ps, const char* name, int flags);

extern unsigned long panel_system;

struct Shim_1E920 {
    char p0[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char p14[8];
    void* prog_palette;        // +0x1C
    char p20[0x40 - 0x20];
    int error_code;            // +0x40
    char p44[0x48 - 0x44];
    void* draw_system;         // +0x48
    void* draw_area;           // +0x4C
};

int RGE_Base_Game_setup_graphics_system(Shim_1E920* self)
{
    void* prog_info = self->prog_info;
    
    if (*(int*)((char*)prog_info + 0x89C)) {
        int dc = GetDC(0);
        int bits = GetDeviceCaps(dc, 0x0C);
        ReleaseDC(0, dc);
        if (bits < 8) {
            self->error_code = 0x13;
            return 0;
        }
    }
    
    int useDirDraw = *(int*)((char*)prog_info + 0x89C);
    int useSysMem = *(int*)((char*)prog_info + 0x8A0);
    int fullScreen = *(int*)((char*)prog_info + 0x894);
    
    void* ds = operator_new(0x47C);
    if (ds) {
        TDrawSystem_ctor(ds);
    } else {
        ds = 0;
    }
    self->draw_system = ds;
    
    if (!ds)
        return 0;
    
    TDrawSystem_CheckAvailModes(ds, fullScreen);
    
    int targetW = *(int*)((char*)prog_info + 0x8E0);
    int targetH = *(int*)((char*)prog_info + 0x8E4);
    
    if (!TDrawSystem_IsModeAvail(ds, targetW, 0, 8)) {
        // Try 640x480
        if (targetW != 0x280) {
            if (TDrawSystem_IsModeAvail(ds, 0x280, 0, 8)) {
                *(int*)((char*)prog_info + 0x8E0) = 0x280;
                *(int*)((char*)prog_info + 0x8E4) = 0x1E0;
                targetW = 0x280;
                targetH = 0x1E0;
                goto init_step;
            }
        }
        // Try 800x600
        if (targetW != 800) {
            if (TDrawSystem_IsModeAvail(ds, 800, 0, 8)) {
                *(int*)((char*)prog_info + 0x8E0) = 800;
                *(int*)((char*)prog_info + 0x8E4) = 600;
                targetW = 800;
                targetH = 600;
                goto init_step;
            }
        }
        // Try 1024x768
        if (targetW != 0x400) {
            if (TDrawSystem_IsModeAvail(ds, 0x400, 0, 8)) {
                *(int*)((char*)prog_info + 0x8E0) = 0x400;
                *(int*)((char*)prog_info + 0x8E4) = 0x300;
                targetW = 0x400;
                targetH = 0x300;
                goto init_step;
            }
        }
        // Try 1280x1024
        if (targetW != 0x500) {
            if (TDrawSystem_IsModeAvail(ds, 0x400, 0, 8)) {
                *(int*)((char*)prog_info + 0x8E0) = 0x500;
                *(int*)((char*)prog_info + 0x8E4) = 0x400;
                targetW = 0x500;
                targetH = 0x400;
                goto init_step;
            }
        }
        return 0;
    }
    
init_step:
    {
        int drawType = (useDirDraw != 0) + 1;
        int drawMode = (fullScreen != 0) + 1;
        int useSysMemFlag = (useSysMem != 0);
        
        if (!TDrawSystem_Init(ds,
            *(void**)((char*)prog_info + 0x410),
            self->prog_window,
            self->prog_palette,
            drawType,
            drawMode,
            targetW,
            targetH,
            useSysMemFlag))
        {
            return 0;
        }
    }
    
    TPanelSystem_release_palette((void*)&panel_system, self->prog_palette);
    self->prog_palette = TPanelSystem_get_palette((void*)&panel_system,
        (char*)prog_info + 0x66E, 0xC544);
    
    self->draw_area = *(void**)((char*)self->draw_system + 0x0C);
    
    TDrawArea_Clear(self->draw_area, 0, 0);
    TDrawSystem_Paint(self->draw_system, 0);
    
    return 1;
}
