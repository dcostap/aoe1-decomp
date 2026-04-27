// VA: 0041C270 ~RGE_Base_Game (1136 B)
// PDB source: basegame.cpp
// Packet-grounded structural first-pass

extern void debug_random_write(void);
extern void dump_vismap_log(void);
extern int TRegistry_RegSetInt(void* reg, int a, const char* name, int val);
extern int TRegistry_RegGetInt(void* reg, int a, const char* name);
extern int sprintf(char* buf, const char* fmt, ...);
extern int RGE_Base_Game_pathFinding(void* self);
extern int RGE_Base_Game_mpPathFinding(void* self);
extern void RGE_Scenario_File_Info_dtor(void* info);
extern int RGE_Game_Info_save(void* info, const char* name);
extern void RGE_Game_Info_dtor(void* info);
extern void TDrawArea_dtor(void* da);
extern void TMousePointer_dtor(void* mp);
extern void TCommunications_Handler_dtor(void* ch);
extern void TChat_dtor(void* ch);
extern void TDrawSystem_dtor(void* ds);
extern void TRegistry_dtor(void* reg);
extern void TDebuggingLog_dtor(void* log);
extern void TShape_dtor(void* shape);
extern void TPanelSystem_destroyPanel(void* ps, const char* name);
extern void TPanelSystem_release_palette(void* ps, void* pal);
extern void RGE_Base_Game_stop_sound_system(void* self);
extern void RGE_Base_Game_get_string(void* self, char* buf, int id, int size);
extern void operator_delete(void* p);
extern void free(void* p);
extern int _ftol(double v);
extern int DeleteObject(void* obj);
extern int SystemParametersInfoA(int action, int param, void* v, int flags);
extern int CloseHandle(void* h);
extern int DestroyWindow(void* hwnd);
extern void* FindWindowA(const char* cls, const char* name);
extern int SendMessageA(void* hwnd, int msg, void* wp, void* lp);
extern int FreeLibrary(void* h);

extern int do_debug_random;
extern int wrote_debug_random_log;
extern int actionFile;
extern int fps_log;
extern int draw_log;
extern int g_5B2160;
extern int g_62C530; // fps_log
extern int g_62C4CCh; // actionFile
extern void* rge_base_game;
extern int g_62C4A0; // StringTable
extern int g_5B215Ch; // driveInfo
extern int g_62C4B8; // chat
extern unsigned long panel_system;

/* Shim - declaration-order (ascending offsets) */
struct Shim_1C270 {
    char gap00[4];
    int game_info;             // +0x04
    int scenario_info;         // +0x08
    void* prog_info;           // +0x0C
    void* prog_window;         // +0x10
    char gap14[8];             // +0x14..0x1B
    void* prog_palette;        // +0x1C
    void* field_20;            // +0x20
    char gap24[0x38 - 0x24];
    void* field_38;            // +0x38
    void* field_3C;            // +0x3C
    int error_code;            // +0x40
    char gap44[4];
    void* draw_system;         // +0x48
    void* draw_area;           // +0x4C
    char gap50[8];
    short shape_count;         // +0x58
    void* shapes;              // +0x5C
    void* sound_system;        // +0x60
    void* music_system;        // +0x64
    char gap68[0x18C - 0x68];
    void* comm_handler;        // +0x18C
    char gap190[0x1A4 - 0x190];
    int debug_log;             // +0x1A4
    int field_1A8;             // +0x1A8
    void* registry;            // +0x1AC
    int game_mode;             // +0x1B0
    int field_1B4;             // +0x1B4
    int field_1B8;             // +0x1B8
    int field_1BC;             // +0x1BC
    void* mouse_pointer;       // +0x1C0
    int field_1C4;             // +0x1C4
    int field_1C8;             // +0x1C8
    char gap1CC[0x1E0 - 0x1CC];
    short font_count;          // +0x1E0
    int fonts;                 // +0x1E4
    char work_dir[0x100];      // +0x1E8
    char gap2E8[0x3F4 - 0x2E8];
    void* field_3F4;           // +0x3F4
    int field_3F8;             // +0x3F8
    char gap3FC[0xA08 - 0x3FC];
    int field_A08;             // +0xA08
    int field_A0C;             // +0xA0C
    int field_A10;             // +0xA10
    char gapA14[0xA20 - 0xA14];
    void* draw_area_screen;    // +0xA20
};

void RGE_Base_Game_dtor(Shim_1C270* self)
{
    int i;
    
    // Vtable restore
    *(void**)self = (void*)0x56EED0;
    
    // Debug random log dump
    if (do_debug_random && !wrote_debug_random_log) {
        debug_random_write();
        dump_vismap_log();
    }
    
    // Save screen size
    if (self->draw_system) {
        TRegistry_RegSetInt(self->registry, 1, "Screen Size",
            *(int*)((char*)self->draw_system + 0x2C));
    }
    
    // Save rollover text setting
    {
        int rolloverVal = -(self->field_A08 != 0);
        rolloverVal = (rolloverVal & 1) + 2;
        TRegistry_RegSetInt(self->registry, 1, "Rollover Text", rolloverVal);
    }
    
    // Save mouse style
    if (*(short*)((char*)self->prog_info + 0x8DC) == 2)
        TRegistry_RegSetInt(self->registry, 1, "Mouse Style", 2);
    else
        TRegistry_RegSetInt(self->registry, 1, "Mouse Style", 1);
    
    // Save game speed
    {
        float speed = *(float*)&self->field_A0C;
        int speedInt = _ftol((double)(speed * 1.0f));  /* placeholder, g_56F018 factor */
        TRegistry_RegSetInt(self->registry, 1, "Game Speed", speedInt);
    }
    
    // Save difficulty
    TRegistry_RegSetInt(self->registry, 1, "Difficulty", self->field_A10);
    
    // Save path finding
    {
        int pf = RGE_Base_Game_pathFinding(self) & 0xFF;
        TRegistry_RegSetInt(self->registry, 1, "Path Finding", pf + 1);
    }
    
    // Save MP path finding
    {
        int mpf = RGE_Base_Game_mpPathFinding(self) & 0xFF;
        TRegistry_RegSetInt(self->registry, 1, "MP Path Finding", mpf + 1);
    }
    
    // Save scroll speed
    TRegistry_RegSetInt(self->registry, 1, "Scroll Speed",
        *(int*)((char*)self->prog_info + 0x8C8));
    
    // Close action file
    if (g_62C4CCh) {
        /* fclose((void*)g_62C4CCh); */
        g_62C4CCh = 0;
    }
    
    // Close FPS log
    if (g_62C530) {
        /* fclose((void*)g_62C530); */
        g_62C530 = 0;
    }
    
    // Close draw log
    if (draw_log) {
        /* fclose((void*)draw_log); */
        draw_log = 0;
    }
    
    // Destroy scenario file info
    if (self->scenario_info) {
        RGE_Scenario_File_Info_dtor((void*)self->scenario_info);
        operator_delete((void*)self->scenario_info);
        self->scenario_info = 0;
    }
    
    // Save game info
    if (self->game_info) {
        int fileNum = TRegistry_RegGetInt(self->registry, 0, "Game File Number");
        if (fileNum >= 0) {
            fileNum = TRegistry_RegGetInt(self->registry, 0, "Game File Number");
            char filename[260];
            sprintf(filename, "game%d.nfo", fileNum);
            RGE_Game_Info_save((void*)self->game_info, filename);
        }
        
        if (self->game_info) {
            RGE_Game_Info_dtor((void*)self->game_info);
            operator_delete((void*)self->game_info);
            self->game_info = 0;
        }
    }
    
    // Clean up scenario holder
    self->game_mode = 0;
    if (self->field_3F4) {
        void** vt = *(void***)self->field_3F4;
        ((void(*)(void*, int))vt[0xA0 / 4])(self->field_3F4, 1);
        self->field_3F4 = 0;
    }
    
    // Destroy screen draw area
    if (self->draw_area_screen) {
        TDrawArea_dtor(self->draw_area_screen);
        operator_delete(self->draw_area_screen);
        self->draw_area_screen = 0;
    }
    
    // Destroy mouse pointer
    if (self->mouse_pointer) {
        TMousePointer_dtor(self->mouse_pointer);
        operator_delete(self->mouse_pointer);
        self->mouse_pointer = 0;
    }
    
    // Delete drive info
    if (g_5B215Ch) {
        operator_delete((void*)g_5B215Ch);
        g_5B215Ch = 0;
    }
    
    // Destroy comm handler
    if (self->comm_handler) {
        TCommunications_Handler_dtor(self->comm_handler);
        operator_delete(self->comm_handler);
        self->comm_handler = 0;
    }
    
    // Destroy chat
    if (g_62C4B8) {
        TChat_dtor((void*)g_62C4B8);
        operator_delete((void*)g_62C4B8);
        g_62C4B8 = 0;
    }
    
    // Delete font objects
    if (self->fonts) {
        for (i = 0; i < (int)self->font_count; i++) {
            void* hfont = *(void**)((char*)self->fonts + i * 12);
            if (hfont)
                DeleteObject(hfont);
        }
        free((void*)self->fonts);
        self->fonts = 0;
    }
    
    // Stop sound system
    RGE_Base_Game_stop_sound_system(self);
    
    // Destroy blank screen panel
    TPanelSystem_destroyPanel((void*)&panel_system, "Blank Screen");
    
    // Destroy draw system
    if (self->draw_system) {
        TDrawSystem_dtor(self->draw_system);
        operator_delete(self->draw_system);
        self->draw_system = 0;
        self->draw_area = 0;
    }
    
    // System parameters restore
    if (self->field_38) {
        SystemParametersInfoA(0x11, 0, 0, 2);
    }
    if (self->field_3C) {
        SystemParametersInfoA(0x55, 0, 0, 2);
    }
    
    // Release palette
    if (self->prog_palette) {
        TPanelSystem_release_palette((void*)&panel_system, self->prog_palette);
        self->prog_palette = 0;
    }
    
    // Destroy registry
    if (self->registry) {
        TRegistry_dtor(self->registry);
        operator_delete(self->registry);
        self->registry = 0;
    }
    
    // Close handle
    if (self->field_20) {
        CloseHandle(self->field_20);
        self->field_20 = 0;
    }
    
    // Clear global
    rge_base_game = 0;
    
    // Destroy window
    if (self->prog_window) {
        DestroyWindow(self->prog_window);
    }
    
    // Help window cleanup (string 0x3EB)
    {
        int strID = 0x3EB;
        char buf[256];
        RGE_Base_Game_get_string(self, buf, strID, 0x100);
        if (buf[0]) {
            void* hwndHelp = FindWindowA("MS_WINHELP", buf);
            if (hwndHelp)
                SendMessageA(hwndHelp, 0x10, 0, 0);
        }
    }
    
    // Free string table library
    if (g_62C4A0 && g_62C4A0 != *(int*)((char*)self->prog_info + 0x410)) {
        FreeLibrary((void*)g_62C4A0);
        g_62C4A0 = 0;
    }
    
    // Destroy debug log
    if (self->debug_log) {
        TDebuggingLog_dtor((void*)self->debug_log);
        operator_delete((void*)self->debug_log);
        self->debug_log = 0;
    }
    
    // Free shapes
    if (self->shapes) {
        for (i = 0; i < (int)self->shape_count; i++) {
            void* shape = *(void**)((char*)self->shapes + i * 4);
            if (shape) {
                TShape_dtor(shape);
                operator_delete(shape);
            }
        }
        free(self->shapes);
    }
}
