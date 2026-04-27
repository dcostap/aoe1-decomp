// VA: 004213E0 RGE_Base_Game::handle_paint (1096 B)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass

extern void color_log(unsigned char a, unsigned char b, int c);
extern unsigned long debug_timeGetTime(const char* file, int line);
extern int check_paint(void* self);
extern void add_to_timing(void* self, int slot, int val);
extern void TDrawSystem_ModifyPalette(void* ds, int a, int b, void* ptr);
extern void TSound_Driver_play_list(void* sd);
extern void TSound_Driver_reset_play_list(void* sd);
extern void TMousePointer_erase(void* mp);
extern void TMousePointer_draw(void* mp, int flag);
extern void* TPanelSystem_currentPanel(void* ps);
extern void* rge_base_game;
extern void clear_window(void* self);
extern void TDrawSystem_Paint(void* ds, void* rect);
extern int ValidateRect(void* hwnd, void* rect);
extern int SetCursor(int cur);
extern int SetClassLongA(void* hwnd, int idx, int val);
extern int restore_mouse_after_paint;

extern unsigned long panel_system;

struct Shim_213E0 {
    char p0[0x0C];
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char p14[0x48 - 0x14];
    void* draw_system;         // +0x48
    void* draw_area;           // +0x4C
    char p50[4];
    void* mouse_inactive;      // +0x54
    char p58[8];
    void* sound_system;        // +0x60
    char p64[0x1B0 - 0x64];
    int game_mode;             // +0x1B0
    char p1B4[0x1C0 - 0x1B4];
    void* mouse_pointer;       // +0x1C0
    int flag_1C4;              // +0x1C4
    int flag_1C8;              // +0x1C8
    int field_1CC;             // +0x1CC
    int field_1D0;             // +0x1D0
    int field_1D4;             // +0x1D4
    char p1D8[0x3F8 - 0x1D8];
    int flag_menu;             // +0x3F8
    char p3FC[0x504 - 0x3FC];
    int timer_frame;           // +0x504
    char p508[0x8E8 - 0x508];
    int flag_ai;               // +0x8E8
};

int RGE_Base_Game_handle_paint(Shim_213E0* self, void* param1, unsigned int param2, unsigned int param3, long param4)
{
    color_log(0x32, 0x32, 4);
    
    unsigned long t0 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x10EA);
    int canPaint = check_paint(self);
    unsigned long t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x10EE);
    add_to_timing(self, 5, t1 - t0);
    
    if (!canPaint) {
        color_log(0x32, 0x5F, 4);
        return 0;
    }
    
    // Fade-in animation check
    if (self->game_mode == 4 || self->game_mode == 6 || self->game_mode == 7) {
        if (*(unsigned char*)((char*)self->draw_system + 0x478) != 1 &&
            self->mouse_inactive &&
            self->flag_1C8)
        {
            // Surface animation: call save_random_map_seed on draw_area surface
            // This is a fade-in/transition animation loop
            while (1) {
                void* surf = *(void**)((char*)self->draw_system + 0x1C);
                unsigned long result;
                
                // play - save/restore loop
                void** svtable = *(void***)surf;
                result = ((unsigned long(*)(void*, int))svtable[0x34 / 4])(surf, 1);
                
                t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x10FC);
                unsigned long deadline = t1 + 100;
                
                if (result != 0x8876021C)
                    break;
                
                surf = *(void**)((char*)self->draw_system + 0x1C);
                svtable = *(void***)surf;
                result = ((unsigned long(*)(void*, int))svtable[0x34 / 4])(surf, 1);
                
                t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1100);
                if (t1 > deadline)
                    break;
                
                if (result != 0x8876021C)
                    goto anim_done;
            }
            self->flag_1C8 = 0;
        }
    }
    
anim_done:
    color_log(0x32, 0xBA, 4);
    
    t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x110C);
    void* soundDrv = *(void**)((char*)rge_base_game + 0x60);
    
    if (soundDrv) {
        TSound_Driver_play_list(soundDrv);
        TSound_Driver_reset_play_list(soundDrv);
    }
    
    add_to_timing(self, 10, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1115) - t1);
    
    t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x111C);
    
    // Erase mouse flag handling
    if (self->flag_1C4) {
        color_log(0x32, 0x4C, 4);
        if (!self->flag_menu && self->mouse_inactive)
            TMousePointer_erase(self->mouse_pointer);
        self->flag_1C4 = 0;
    }
    
    // Panel painting
    unsigned long tp = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1127);
    unsigned long tp2 = tp - t1;
    
    t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x112A);
    color_log(0x32, 0x16, 4);
    
    if (TPanelSystem_currentPanel((void*)&panel_system)) {
        color_log(0x16, 0x16, 1);
        if (self->flag_menu) {
            void* panel = TPanelSystem_currentPanel((void*)&panel_system);
            void** pv = *(void***)panel;
            ((void(*)(void*, int))pv[0x20 / 4])(panel, 2);
        }
        
        void* panel = TPanelSystem_currentPanel((void*)&panel_system);
        void** pv = *(void***)panel;
        ((void(*)(void*))pv[0x54 / 4])(panel);
        
        color_log(0x16, 0x5F, 1);
    } else {
        clear_window(self);
    }
    
    color_log(0x32, 0x24, 4);
    
    // FPS rate-limited callback
    {
        extern int g_62C57C;
        if (g_62C57C) {
            g_62C57C = 0;
            if (self->game_mode == 4 || self->game_mode == 5) {
                if (self->flag_ai)
                    ((void(*)(Shim_213E0*))((*(void***)self)[0x130 / 4]))(self);
            }
        }
    }
    
    add_to_timing(self, 2, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1147) - t1);
    
    t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x114B);
    color_log(0x32, 0x54, 4);
    
    // Mouse draw
    if (self->mouse_inactive && !self->field_1D0) {
        TMousePointer_draw(self->mouse_pointer, 1);
        self->flag_1C4 = 1;
    }
    
    add_to_timing(self, 8, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x115B) - t1 + tp2);
    
    // DrawSystem Paint + ValidateRect
    t1 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1160);
    color_log(0x32, 0x45, 4);
    
    TDrawSystem_Paint(self->draw_system, 0);
    ValidateRect(self->prog_window, 0);
    ValidateRect(self->prog_window, 0);
    
    self->flag_menu = 0;
    
    add_to_timing(self, 3, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1176) - t1);
    
    color_log(0x32, 0x5F, 4);
    
    // Frame counter
    self->timer_frame++;
    
    // FPS tracking (every 1000ms)
    {
        extern int g_62C578;
        extern int g_62C57C;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1182);
        if (now - g_62C578 >= 1000) {
            ((void(*)(Shim_213E0*))((*(void***)self)[0x128 / 4]))(self);
            g_62C578 = now;
            g_62C57C = 1;
        }
    }
    
    // Mouse restore after paint
    if (restore_mouse_after_paint) {
        if (self->mouse_pointer) {
            // Restore mouse surface
            ((void(*)(void*, void*))((*(void***)self->mouse_pointer)[0x28 / 4]))(self->mouse_pointer, self->draw_area);
            
            if (self->field_1CC) {
                if (self->mouse_inactive && !self->field_1D0) {
                    // invalidate region and restore cursor
                    // g_MouseOvl or similar
                    if (*(int*)((char*)self->mouse_pointer + 0x40)) {
                        TMousePointer_draw(self->mouse_pointer, 1);
                    }
                } else {
                    SetCursor(self->field_1D4);
                    SetClassLongA(self->prog_window, -12, (long)self->field_1D4);
                }
            }
            
            SetCursor(0);
            SetClassLongA(self->prog_window, -12, 0);
        }
        
        restore_mouse_after_paint = 0;
    }
    
    return 1;
}
