#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::transform
#include <cctype>    // for ::toupper
#include <mmsystem.h> // for timeGetTime
#include <cstdarg>   // for va_list, va_start, va_end
#include <stdlib.h>  // for _splitpath_s
#pragma comment(lib, "winmm.lib")

// --- Forward Declarations & Global Placeholders ---

class MainApp;
struct GraphicsManager;

MainApp* g_pMainApp = nullptr;
GraphicsManager* g_pGraphicsManager = nullptr;
HANDLE g_hHeap = nullptr;
HMODULE g_hLanguageDLL = nullptr;
HMODULE DAT_00585ddc = nullptr; 

// --- Placeholder Structs ---
struct GraphicsManager {
    int drive_index_1;              // Offset 0x00
    char string_at_0x4[256];        // Offset 0x04
    char unknown_data_0x104[4];     // Padding
    int drive_index_2;              // Offset 0x104
    char source_string_at_0x108[256]; // Offset 0x108
    char unknown_data_after[628 - 524]; // Pad to 0x274 bytes
};

struct GameData {
    char unknown_data_0[0x1F8];
    char data_path[MAX_PATH];       
    char unknown_data_1[0x410 - 0x1F8 - MAX_PATH];
    HINSTANCE hInstance;            
    char unknown_data_2[0x87C - 0x410 - sizeof(HINSTANCE)];
    int unknown_0x87c;              
    char unknown_data_3[0x88C - 0x87C - 4];
    int unknown_0x88c;              
    char unknown_data_4[0x8C8 - 0x88C - 4];
    int scroll_speed_1;             
    char unknown_data_5[4];
    int scroll_speed_2;             
    char unknown_data_6[8];
    short mouse_style;              
    char unknown_data_7[2];
    int screen_width;               
    int screen_height;              
    char unknown_data_8[0xC17 - 0x8E4 - 4];
    char scenario_name[MAX_PATH];   
    char command_line[MAX_PATH];
};

// --- VTable Simulation ---
struct VTable {
    using FuncPtr = int(*)(void*);
    FuncPtr functions[81];
    
    static int destructor(void* self) { std::cout << "VTable[0] (destructor) called." << std::endl; return 0; }
    static int func_1(void* self) { std::cout << "VTable[1] called." << std::endl; return 0; }
    static int get_initialization_status(void* self);
    static int func_8(void* self) { std::cout << "VTable[8] called." << std::endl; return 0; }
    static int func_10(void* self) { std::cout << "VTable[10] called." << std::endl; return 0; }
    static int vfunc_3(void* self, int p1) { std::cout << "  [STUB] VTable[3] (0xc) called." << std::endl; return 0; }
    static int vfunc_26(void* self) { std::cout << "  [STUB] VTable[26] (0x68) called." << std::endl; return 1; }
    static int vfunc_27(void* self) { std::cout << "  [STUB] VTable[27] (0x6c) called." << std::endl; return 1; }
    static int vfunc_28(void* self) { std::cout << "  [STUB] VTable[28] (0x70) called." << std::endl; return 1; }
    static int vfunc_29(void* self) { std::cout << "  [STUB] VTable[29] (0x74) called." << std::endl; return 1; }
    static int vfunc_30(void* self) { std::cout << "  [STUB] VTable[30] (0x78) called." << std::endl; return 1; }
    static int vfunc_33(void* self) { std::cout << "  [STUB] VTable[33] (0x84) called." << std::endl; return 1; }
    static int vfunc_34(void* self) { std::cout << "  [STUB] VTable[34] (0x88) called." << std::endl; return 1; }
    static int vfunc_35(void* self) { std::cout << "  [STUB] VTable[35] (0x8c) called." << std::endl; return 1; }
    static int vfunc_36(void* self) { std::cout << "  [STUB] VTable[36] (0x90) called." << std::endl; return 1; }
    static int vfunc_37(void* self) { std::cout << "  [STUB] VTable[37] (0x94) called." << std::endl; return 1; }
    static int vfunc_38(void* self) { std::cout << "  [STUB] VTable[38] (0x98) called." << std::endl; return 1; }
    static int vfunc_39(void* self) { std::cout << "  [STUB] VTable[39] (0x9c) called." << std::endl; return 1; }
    static int vfunc_40(void* self) { std::cout << "  [STUB] VTable[40] (0xa0) called." << std::endl; return 1; }
    static int vfunc_57(void* self, HWND p1, int p2, int p3, int p4) { std::cout << "  [STUB] VTable[57] (0xe4) called." << std::endl; return 1; }
    static int vfunc_79(void* self) { std::cout << "  [STUB] VTable[79] (0x13c) called." << std::endl; return 1; }
    static int vfunc_80(void* self) { std::cout << "  [STUB] VTable[80] (0x140) called." << std::endl; return 1; }

    VTable() {
        memset(functions, 0, sizeof(functions));
        functions[0] = &destructor; functions[1] = &func_1; functions[3] = (FuncPtr)&vfunc_3;
        functions[6] = &get_initialization_status; functions[8] = &func_8; functions[10] = &func_10;
        functions[26] = &vfunc_26; functions[27] = &vfunc_27; functions[28] = &vfunc_28;
        functions[29] = &vfunc_29; functions[30] = &vfunc_30; functions[33] = &vfunc_33;
        functions[34] = &vfunc_34; functions[35] = &vfunc_35; functions[36] = &vfunc_36;
        functions[37] = &vfunc_37; functions[38] = &vfunc_38; functions[39] = &vfunc_39;
        functions[40] = &vfunc_40; functions[57] = (FuncPtr)&vfunc_57; functions[79] = &vfunc_79;
        functions[80] = &vfunc_80;
    }
};
VTable g_MainAppVTable;

// --- Main Application Class ---
class MainApp {
public:
    VTable* vfptr;                       
    int game_file_num;                   
    int scenario_info;                   
    GameData* pGameData;                 
    HWND hWnd;                           
    int is_shown;                        
    int unknown_0x18;
    HPALETTE hPalette;                   
    char unknown_data_0x20[8];
    int screen_saver_active;             
    int low_power_active;                
    int initialization_status;           
    UINT_PTR timer_id;                   
    char unknown_data_after_timer[0x2ED - 0x44 - 4];
    char dll_name[10];                   
    char unknown_data_after_dll[0xA08 - 0x2ED - 10];
    int use_rollover_text;               
    float game_speed;                    
    int difficulty;                      
    char unknown_data_after_difficulty[0xAAD - 0xA10 - 4];
    int some_flag_0x26b;                 

    MainApp(HINSTANCE hInstance, const char* lpCmdLine);
    int perform_initial_setup();         
    int initialize_system_and_graphics();
};

// Original Ghidra symbol: FUN_00417ab0
int VTable::get_initialization_status(void* self) {
    return static_cast<MainApp*>(self)->initialization_status;
}

// --- Function Stubs & Implementations (Global Scope) ---

// Original Ghidra symbol: FUN_005288a0
// Behavior: Wrapper for sprintf.
void format_string(char* dest, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsprintf_s(dest, MAX_PATH, format, args);
    va_end(args);
}

// Original Ghidra symbols: FUN_0043be20, FUN_0052ad80, FUN_0052ac00
// Behavior: Gets the CWD, splits it into components, and rebuilds it into a string.
void split_and_rebuild_path(GraphicsManager* mgr) {
    char full_path[MAX_PATH];
    if (GetCurrentDirectoryA(MAX_PATH, full_path) == 0) {
        mgr->source_string_at_0x108[0] = '\0';
        return;
    }

    char drive[_MAX_DRIVE], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
    _splitpath_s(full_path, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

    format_string(mgr->source_string_at_0x108, "%s%s%s", dir, fname, ext);
}

// Original Ghidra symbol: FUN_0052abb0
// Behavior: Gets an index for the current drive (A=1, B=2, C=3, etc.)
int get_drive_index() {
    char current_dir[MAX_PATH];
    if (GetCurrentDirectoryA(MAX_PATH, current_dir) > 0 && current_dir[1] == ':') {
        char drive_letter = toupper(current_dir[0]);
        if (drive_letter >= 'A' && drive_letter <= 'Z') return (drive_letter - 'A') + 1;
    }
    return 0; // Failure case
}

// Original Ghidra symbol: FUN_0043bdd0
// Behavior: Allocates and initializes the main graphics manager object.
GraphicsManager* create_graphics_manager() {
    std::cout << "  [INFO] Creating graphics manager..." << std::endl;
    GraphicsManager* mgr = new GraphicsManager;
    if (!mgr) return nullptr;
    memset(mgr, 0, sizeof(GraphicsManager));

    int drive_index = get_drive_index();
    mgr->drive_index_1 = drive_index;
    mgr->drive_index_2 = drive_index;
    
    split_and_rebuild_path(mgr);
    strcpy_s(mgr->string_at_0x4, 256, mgr->source_string_at_0x108);
    
    std::cout << "  [OK] Graphics manager created with path: " << mgr->string_at_0x4 << std::endl;
    return mgr;
}

// Original Ghidra symbol: FUN_00529590
const char* find_substring_case_insensitive(const char* str, const char* substr) { return strstr(str, substr); }

// Original Ghidra symbol: FUN_005283d0
int initialize_memory_manager() { g_hHeap = GetProcessHeap(); return 1; }

// Original Ghidra symbol: FUN_005004c0
MainApp** create_main_app_instance(HINSTANCE hInstance, const char* lpCmdLine) {
    if (!g_pMainApp) { g_pMainApp = new MainApp(hInstance, lpCmdLine); }
    return &g_pMainApp;
}

// --- Stubs for yet-to-be-implemented functions ---
// Original Ghidra symbol: FUN_0046c120
int FUN_0046c120(int category, const char* key) { return -1; }
// Original Ghidra symbol: FUN_00419d50
int FUN_00419d50() { return 1; }
// Original Ghidra symbol: FUN_00419dc0
int FUN_00419dc0() { return 1; }
// Original Ghidra symbol: FUN_0041c5a0
bool FUN_0041c5a0(const char* flag) { return false; }
// Original Ghidra symbol: FUN_0043da60
void FUN_0043da60(UINT* v_maj, int* v_min) { *v_maj = 0x600; *v_min = 0; }
// Original Ghidra symbol: FUN_00419c00
int FUN_00419c00(int val) { return 1; }
// Original Ghidra symbol: FUN_0041a2a0
void FUN_0041a2a0() { }


// --- MainApp Method Implementations ---

// Original Ghidra symbol: FUN_005004c0
MainApp::MainApp(HINSTANCE hInstance, const char* lpCmdLine) {
    std::cout << "MainApp constructor started." << std::endl;
    memset(this, 0, sizeof(MainApp));
    this->vfptr = &g_MainAppVTable;
    this->pGameData = new GameData;
    memset(this->pGameData, 0, sizeof(GameData));
    this->pGameData->hInstance = hInstance;
    strncpy_s(this->pGameData->command_line, MAX_PATH, lpCmdLine, _TRUNCATE);
    strcpy_s(this->pGameData->scenario_name, "DEFAULT");
    strcpy_s(this->dll_name, "empires.dll");

    if (this->perform_initial_setup() == 0 && this->initialization_status == 0) {
        this->initialization_status = -1;
    }
    std::cout << "MainApp constructor finished." << std::endl;
}

// Original Ghidra symbol: FUN_00416d50
int MainApp::initialize_system_and_graphics() {
    std::cout << "--- MainApp::initialize_system_and_graphics called ---" << std::endl;
    
    DAT_00585ddc = LoadLibraryA(this->dll_name);
    if (DAT_00585ddc == NULL) { this->initialization_status = 1; return 0; }
    
    MEMORYSTATUS mem_status;
    GlobalMemoryStatus(&mem_status);
    if (mem_status.dwAvailPhys < 0x1400000 && mem_status.dwAvailPageFile < 0x1e00000) {
        this->initialization_status = 0x16; return 0;
    }

    this->vfptr->functions[80](this);
    if (this->pGameData->unknown_0x87c != 0 && FUN_00419d50() == 0) { this->initialization_status = 3; return 0; }
    if (this->pGameData->unknown_0x88c != 0 && FUN_00419dc0() == 0) { this->initialization_status = 4; return 0; }
    
    if (!FUN_0041c5a0("NODXCHECK")) {
        UINT dx_ver_major; int dx_ver_minor;
        FUN_0043da60(&dx_ver_major, &dx_ver_minor);
        if (dx_ver_major < 0x501) { this->initialization_status = 0x14; return 0; }
    }

    SystemParametersInfoA(SPI_GETSCREENSAVEACTIVE, 0, &this->screen_saver_active, 0);
    if(this->screen_saver_active) { SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE, 0, (PVOID)0, SPIF_SENDCHANGE); }
    SystemParametersInfoA(SPI_GETLOWPOWERACTIVE, 0, &this->low_power_active, 0);
    if(this->low_power_active) { SystemParametersInfoA(SPI_SETLOWPOWERACTIVE, 0, (PVOID)0, SPIF_SENDCHANGE); }

    this->some_flag_0x26b = FUN_00419c00(0);

    if (this->vfptr->functions[26](this) == 0) { this->initialization_status = 5; return 0; }
    if (this->vfptr->functions[27](this) == 0) { this->initialization_status = 6; return 0; }
    if (this->vfptr->functions[28](this) == 0) { if(this->initialization_status == 0) {this->initialization_status = 7;} return 0; }
    if (this->vfptr->functions[29](this) == 0) { this->initialization_status = 0x11; return 0; }
    if (this->vfptr->functions[38](this) == 0) { this->initialization_status = 7; return 0; }
    if (this->vfptr->functions[79](this) == 0) { this->initialization_status = 7; return 0; }
    if (this->vfptr->functions[30](this) == 0) { this->initialization_status = 8; return 0; }
    if (this->vfptr->functions[35](this) == 0) { this->initialization_status = 10; return 0; }
    if (this->vfptr->functions[33](this) == 0) { this->initialization_status = 0x10; return 0; }
    if (this->vfptr->functions[34](this) == 0) { this->initialization_status = 9; return 0; }
    if (this->vfptr->functions[36](this) == 0) { this->initialization_status = 0xb; return 0; }
    if (this->vfptr->functions[37](this) == 0) { this->initialization_status = 0xc; return 0; }

    g_pGraphicsManager = create_graphics_manager();
    if (g_pGraphicsManager == nullptr) { return 0; }

    if (this->vfptr->functions[39](this) == 0) { this->initialization_status = 0xd; return 0; }
    
    ((int(*)(void*, int))this->vfptr->functions[3])(this, 0);
    this->vfptr->functions[40](this);
    ((int(*)(void*, HWND, int, int, int))this->vfptr->functions[57])(this, this->hWnd, 0, 0, 0);

    this->is_shown = 1;
    ShowWindow(this->hWnd, SW_SHOW);
    SetFocus(this->hWnd);
    FUN_0041a2a0();
    this->timer_id = SetTimer(this->hWnd, 1, 50, NULL);
    
    std::cout << "--- MainApp::initialize_system_and_graphics finished successfully ---" << std::endl;
    return 1; // Success
}

// Original Ghidra symbol: FUN_00500b30
int MainApp::perform_initial_setup() {
    std::cout << "--- MainApp::perform_initial_setup called ---" << std::endl;
    
    char language_dll_name[MAX_PATH] = "language.dll";
    if (find_substring_case_insensitive(this->pGameData->command_line, "/LANGUAGE=")) {
        sprintf_s(language_dll_name, MAX_PATH, "language_override.dll");
    }

    g_hLanguageDLL = LoadLibraryA(language_dll_name);
    if (g_hLanguageDLL == NULL) { this->initialization_status = 1; return 0; }
    
    if (this->initialize_system_and_graphics() == 0) { return 0; }
    
    std::cout << "--- MainApp::perform_initial_setup finished successfully ---" << std::endl;
    return 1; // Success
}

// --- Main Entry Point ---
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    AllocConsole();
    FILE* console_stream;
    freopen_s(&console_stream, "CONOUT$", "w", stdout);
    std::cout << "WinMain started." << std::endl;

    if (initialize_memory_manager() == 0) { MessageBoxA(NULL, "Memory manager initialization failed.", "Error", MB_OK | MB_ICONERROR); return 1; }
    
    MainApp** ppApp = create_main_app_instance(hInstance, lpCmdLine);
    if (ppApp == nullptr || *ppApp == nullptr) { MessageBoxA(NULL, "Failed to create main application object.", "Error", MB_OK | MB_ICONERROR); return 1; }
    
    MainApp* pApp = *ppApp;
    int init_status = pApp->vfptr->functions[6](pApp);

    if (init_status == 0) {
        std::cout << "Initialization status was 0 (Success). Continuing." << std::endl;
        pApp->vfptr->functions[1](pApp);
        pApp->vfptr->functions[0](pApp);
    } else {
        std::cout << "Initialization status was " << init_status << " (Failure). Aborting." << std::endl;
        pApp->vfptr->functions[8](pApp);
        pApp->vfptr->functions[10](pApp);
        pApp->vfptr->functions[0](pApp);
    }
    
    std::cout << "WinMain finished." << std::endl;

    delete g_pGraphicsManager;
    delete g_pMainApp->pGameData;
    delete g_pMainApp;
    if (console_stream) fclose(console_stream);
    FreeConsole();
    
    return 0;
}