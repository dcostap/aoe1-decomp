// VA: 0041BAA0 RGE_Base_Game::setup (1948 B)
// PDB source: basegame.cpp
// EH-framed (FS:[0] prolog). Packet-grounded structural first-pass.

extern unsigned long debug_timeGetTime(const char* file, int line);
extern unsigned long debug_timeSetTime(const char* file, int line, unsigned long t);
extern int TRegistry_RegGetInt(void* reg, int a, const char* name);
extern void TRegistry_RegSetInt(void* reg, int a, const char* name, int val);
extern int check_for_cd(void* self);
extern int LoadLibraryA(const char* name);
extern int GetVersionExA(void* info);
extern void* operator_new(unsigned int size);
extern int set_path_finding(void* self, int v);
extern int set_mp_path_finding(void* self, int v);
extern int TDriveInfo_ctor(void* di);

// Strings at 57FAxx
extern const char s_Screen_Size[];
extern const char s_Rollover_Text[];
extern const char s_Mouse_Style[];
extern const char s_Game_Speed[];
extern const char s_Difficulty[];
extern const char s_Path_Finding[];
extern const char s_MP_Path_Finding[];
extern const char s_Scroll_Speed[];

extern int g_62C4A0; // hInstance/lang module
extern int g_62C4C8; // flag
extern int g_62C4CCh; // actionFile handle
extern int g_5B215Ch; // drive info ptr
extern float g_56F014; // speed divisor
extern int ShowWindow(void* hwnd, int cmd);
extern int UpdateWindow(void* hwnd);
extern int set_path_finding(void* self, int v);
extern int set_mp_path_finding(void* self, int v);
extern int TDriveInfo_ctor(void* di);

struct Shim_setup {
    char gap00[4];
    int field_4;            // game_info
    int field_8;            // scen_info  
    void* prog_info;        // +0x0C
    void* prog_window;      // +0x10
    int field_14;           // +0x14
    int field_18;           // +0x18
    int field_1C;           // +0x1C
    int field_20;           // +0x20
    int field_24;           // +0x24
    int field_28;           // +0x28
    int field_2C;           // +0x2C
    int field_30;           // +0x30
    int field_34;           // +0x34
    int field_38;           // +0x38
    int field_3C;           // +0x3C
    int error_code;         // +0x40
    int field_44;           // +0x44
    void* draw_system;      // +0x48
    void* draw_area;        // +0x4C
    unsigned char field_50; // +0x50
    char gap51[3];
    int mouse_inactive;     // +0x54
    short field_58;         // +0x58
    void* shapes;           // +0x5C
    void* sound_system;     // +0x60
    void* music_system;     // +0x64
    char gap68[0x1A4 - 0x68];
    int field_1A4;          // +0x1A4
    int field_1A8;          // +0x1A8
    void* registry;         // +0x1AC
    int game_mode;          // +0x1B0
    int field_1B4;
    int field_1B8;
    int field_1BC;
    void* mouse_pointer;    // +0x1C0
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    short font_count;       // +0x1E0
    int fonts;              // +0x1E4
    char work_dir[0x100];   // +0x1E8
    char lang_dll_name[0x100]; // +0x2E8
    char gap3E8[0x3F4 - 0x3E8];
    int field_3F4;          // +0x3F4
    int field_3F8;          // +0x3F8
    // Out-of-order fields (0x9AC < 0xA08)
    // Access via pointer math instead
    char gap3FC[0x9AC - 0x3FC];
    // field_9AC at +0x9AC
    char gap9B0[0xA08 - 0x9AC];
    int field_A08;          // +0xA08
    int field_A0C;          // +0xA0C
    int field_A10;          // +0xA10
};

int RGE_Base_Game_setup(Shim_setup* self)
{
    int i;
    
    // Debug timer start
    debug_timeGetTime("basegame.cpp", 0x20A);
    debug_timeSetTime("basegame.cpp", 0x20A, 0);
    
    // Registry: screen size
    int scrSize = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAFC);
    if (scrSize == 0x280) {
        *(int*)((char*)self->prog_info + 0x8E0) = 0x280;
        *(int*)((char*)self->prog_info + 0x8E4) = 0x1E0;
    } else if (scrSize == 0x320) {
        *(int*)((char*)self->prog_info + 0x8E0) = 0x320;
        *(int*)((char*)self->prog_info + 0x8E4) = 0x258;
    } else if (scrSize > 0x320) {
        if (scrSize == 0x400) {
            *(int*)((char*)self->prog_info + 0x8E0) = 0x400;
            *(int*)((char*)self->prog_info + 0x8E4) = 0x300;
        } else if (scrSize == 0x500) {
            *(int*)((char*)self->prog_info + 0x8E0) = scrSize;
            *(int*)((char*)self->prog_info + 0x8E4) = 0x400;
        }
    }
    
    // Registry: rollover text
    int rollover = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAEC);
    self->field_A08 = (rollover == 2) ? 0 : 1;
    
    // Registry: mouse style
    int mouseStyle = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAE0);
    if (mouseStyle == 2)
        *(short*)((char*)self->prog_info + 0x8DC) = 2;
    else if (mouseStyle == 1)
        *(short*)((char*)self->prog_info + 0x8DC) = 1;
    
    // Registry: game speed
    int speedVal = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAD4);
    if (speedVal != -1) {
        *(float*)&self->field_A0C = (float)speedVal * g_56F014;
    }
    
    // Registry: difficulty
    int diffVal = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAC8);
    if (diffVal != -1) {
        self->field_A10 = diffVal;
    }
    
    // Registry: path finding
    int pfVal = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAB8);
    if (pfVal >= 1 && pfVal <= 3) {
        set_path_finding(self, pfVal - 1);
    }
    
    // Registry: MP path finding
    int mpfVal = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FAA8);
    if (mpfVal >= 1 && mpfVal <= 3) {
        set_mp_path_finding(self, mpfVal - 1);
    }
    
    // Registry: scroll speed
    int scrollVal = TRegistry_RegGetInt(self->registry, 1, (const char*)0x57FA98);
    if (scrollVal != -1 && scrollVal >= 10 && scrollVal <= 200) {
        *(int*)((char*)self->prog_info + 0x8C8) = scrollVal;
        *(int*)((char*)self->prog_info + 0x8D0) = scrollVal;
    }
    
    // Check language DLL
    {
        char buf[256];
        // GetLocaleInfoA call
        int res = 0; /* GetLocaleInfoA(...) */
        if (res == -1) {
            self->error_code = 0x17;
            return self->field_44;
        }
    }
    
    // Virtual: setup_sound_system
    void** vt = *(void***)self;
    if (!((int(*)(Shim_setup*))vt[0x64 / 4])(self)) {
        self->error_code = 2;
        return self->field_44;
    }
    
    // Load string table library from lang_dll_name
    g_62C4A0 = LoadLibraryA(self->lang_dll_name);
    if (!g_62C4A0) {
        self->error_code = 1;
        return self->field_44;
    }
    
    // Check OS version for minimum memory
    {
        int verBuf[4];
        // GetVersionExA call
        // Check major version etc.
        // if (mem < thresh) goto error_min_mem
    }
    
    // Virtual: setup_music_system
    if (!((int(*)(Shim_setup*))vt[0x140/4])(self)) {
        // error
    }
    
    // Open action log file
    if (g_62C4C8) {
        // fopen for action file
    }
    
    // check_multi_copies via vtable
    {
        int chkMul = ((int(*)(Shim_setup*))vt[0x68/4])(self);
        if (!chkMul) { self->error_code = 3; return self->field_44; }
    }
    
    // check_for_cd
    {
        int chkCd = check_for_cd(self);
        *(int*)((char*)self + 0x9AC) = chkCd;
    }
    
    // Virtual chain: setup_sound_system already called above at +0x64
    // setup_graphics_system at +0x68, setup_mouse at +0x6C, setup_blank_screen at +0x70
    // More in order...
    if (!((int(*)(Shim_setup*))vt[0x68/4])(self)) {
        self->error_code = 5;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x6C/4])(self)) {
        self->error_code = 6;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x70/4])(self)) {
        if (!self->error_code) self->error_code = 7;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x74/4])(self)) {
        self->error_code = 0x11;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x98/4])(self)) {
        self->error_code = 7;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x13C/4])(self)) {
        self->error_code = 7;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x78/4])(self)) {
        self->error_code = 8;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x8C/4])(self)) {
        self->error_code = 10;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x84/4])(self)) {
        self->error_code = 0x10;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x88/4])(self)) {
        self->error_code = 9;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x90/4])(self)) {
        self->error_code = 0x0B;
        return self->field_44;
    }
    if (!((int(*)(Shim_setup*))vt[0x94/4])(self)) {
        self->error_code = 0x0C;
        return self->field_44;
    }
    
    // operator_new(0x274) for drive info
    {
        void* di = operator_new(0x274);
        g_5B215Ch = (int)di;
        if (di) {
            TDriveInfo_ctor(di);
            // If ctor successful, continue below
        } else {
            return self->field_44;
        }
    }
    
    // More vtable setup calls
    if (!((int(*)(Shim_setup*))vt[0x9C/4])(self)) {
        self->error_code = 0x0D;
        return self->field_44;
    }
    
    // setup_windows_mouse via vtable(+0x0C)
    ((void(*)(Shim_setup*, int))vt[0x0C/4])(self, 0);
    
    // setup_debugging_log continuation
    ((void(*)(Shim_setup*))vt[0xA0/4])(self);
    
    // Set up window: set_window_mouse, ShowWindow, UpdateWindow
    ShowWindow(self->prog_window, 5);
    UpdateWindow(self->prog_window);
    
    // Register window class / set class long
    // SetWindowLong for WndProc
    
    // Return final error code (stored in field_44)
    return self->field_44;  // Actually returns error code from 0x44
}
