// VA: 00420F60 RGE_Base_Game::handle_idle (431 B)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass

extern void color_log(unsigned char a, unsigned char b, int c);
extern int do_restore_palette;
extern int restore_palette_timer;
extern int debug_timeGetTime(const char* file, int line);
extern void TDrawSystem_ModifyPalette(void* ds, int pal, int size, void* ptr);
extern void* TPanelSystem_currentPanel(void* ps);
extern int TSound_Driver_handle_messages(void* sd, void* hwnd, int msg, int wp, int lp);
extern int RGE_Base_Game_multiplayerGame(void* self);
extern void TCommunications_Handler_ReceiveGameMessages(void* ch);

// Global panel_system
extern unsigned long panel_system;

struct Shim_20F60 {
    char p0[0x10];
    void* prog_window;         // +0x10
    void* prog_ready;          // +0x14
    void* prog_active;         // +0x18
    char p1C[0x48 - 0x1C];
    void* draw_system;         // +0x48
    char p4C[0x60 - 0x4C];
    void* sound_system;        // +0x60
    char p64[0x18C - 0x64];
    void* comm_handler;        // +0x18C
    char p190[0x8EC - 0x190];
    int do_show_comm;          // +0x8EC
    int do_show_ai;            // +0x8F0
};

int RGE_Base_Game_handle_idle(Shim_20F60* self)
{
    if (!self->prog_ready || !self->prog_window)
        return 0;
    
    color_log(0x16, 0x16, 2);
    
    if (do_restore_palette && self->prog_active) {
        int delay = 0xFA;
        if (do_restore_palette > 5)
            delay = 0x1F4;
        
        unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0xF9A);
        if ((t - restore_palette_timer) >= (unsigned long)delay) {
            if (self->draw_system) {
                TDrawSystem_ModifyPalette(self->draw_system, 0, 0x100,
                    (char*)self->draw_system + 0x78);
            }
            do_restore_palette--;
            restore_palette_timer = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0xFA4);
        }
    }
    
    color_log(0x32, 0x32, 5);
    
    if (self->sound_system) {
        color_log(0x16, 0xBA, 2);
        TSound_Driver_handle_messages(self->sound_system, self->prog_window, 0x113, 0, 0);
    }
    
    if (TPanelSystem_currentPanel((void*)&panel_system) != 0) {
        color_log(0x16, 0x45, 2);
        void* panel = TPanelSystem_currentPanel((void*)&panel_system);
        if (panel) {
            void** vtable = *(void***)panel;
            ((void(*)(void*))vtable[0x4C / 4])(panel);
        }
    }
    
    if (self->comm_handler) {
        int isMp = RGE_Base_Game_multiplayerGame(self);
        if (isMp) {
            color_log(0x45, 0x45, 1);
            TCommunications_Handler_ReceiveGameMessages(self->comm_handler);
            color_log(0x45, 0x5F, 1);
        }
    }
    
    if (self->do_show_comm) {
        color_log(0x16, 0x32, 2);
        void** vtable = *(void***)self;
        ((void(*)(void*))vtable[0x134 / 4])(self);
    }
    
    if (self->do_show_ai) {
        color_log(0x16, 0x24, 2);
        void** vtable = *(void***)self;
        ((void(*)(void*))vtable[0x138 / 4])(self);
    }
    
    color_log(0x32, 0x5F, 5);
    color_log(0x16, 0x5F, 2);
    
    return 1;
}
