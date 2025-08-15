#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::transform
#include <cctype>    // for ::toupper

// --- Forward Declarations & Global Placeholders ---

class MainApp;
MainApp* g_pMainApp = nullptr;
HANDLE g_hHeap = nullptr;
HMODULE g_hLanguageDLL = nullptr;

// --- Placeholder Structs ---
// Placeholder for a structure containing game paths, handles, etc.
struct GameData {
    char unknown_data_0[0x1F8];
    char data_path[MAX_PATH];       // Offset 0x1F8 (approx.)
    char unknown_data_1[0x410 - 0x1F8 - MAX_PATH];
    HINSTANCE hInstance;            // Offset 0x410
    char unknown_data_2[0x518 - 0x410 - sizeof(HINSTANCE)];
    char command_line[MAX_PATH];    // Offset 0x518 (approx.)
};

// --- VTable Simulation ---
struct VTable {
    using FuncPtr = int(*)(MainApp*);
    FuncPtr functions[11];
    static int destructor(MainApp* self) { std::cout << "VTable[0] (destructor) called." << std::endl; return 0; }
    static int func_1(MainApp* self) { std::cout << "VTable[1] called." << std::endl; return 0; }
    static int get_initialization_status(MainApp* self);
    static int func_8(MainApp* self) { std::cout << "VTable[8] called." << std::endl; return 0; }
    static int func_10(MainApp* self) { std::cout << "VTable[10] called." << std::endl; return 0; }
    VTable() {
        memset(functions, 0, sizeof(functions));
        functions[0] = &destructor; functions[1] = &func_1; functions[6] = &get_initialization_status; functions[8] = &func_8; functions[10] = &func_10;
    }
};
VTable g_MainAppVTable;

// --- Main Application Class ---
class MainApp {
public:
    VTable* vfptr;                       // Offset 0x00
    int unknown_0x04;
    int unknown_0x08;
    GameData* pGameData;                 // Offset 0x0C (Ghidra: param_1[3])
    HWND hWnd;                           // Offset 0x10 (Ghidra: param_1[4])
    int unknown_0x14;
    int unknown_0x18;
    HPALETTE hPalette;                   // Offset 0x1C (Ghidra: param_1[7])
    char unknown_data_0x20[0x40 - 0x20];
    int initialization_status;           // Offset 0x40 (Ghidra: param_1[0x10])
    char unknown_data_0x44[0x77 * 4 - 0x44];
    HWND hInputDisabledWindow;           // Offset 0x1DC (Ghidra: param_1[0x77])
    char unknown_data_after[4800 - (0x77 * 4 + 4)];

    MainApp(int param_2, int param_3, HINSTANCE hInstance, const char* lpCmdLine);
    int perform_initial_setup(); // Corresponds to Ghidra's FUN_00500b30
};

int VTable::get_initialization_status(MainApp* self) {
    // Corresponds to Ghidra's FUN_00417ab0
    return self->initialization_status;
}

// --- Function Stubs (Global Scope) ---

// Original Ghidra symbol: FUN_00529590
// Behavior: Case-insensitive substring search.
const char* find_substring_case_insensitive(const char* str, const char* substr) {
    std::string s(str);
    std::string sub(substr);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return strstr(s.c_str(), sub.c_str());
}

// Original Ghidra symbol: FUN_005283d0
// Behavior: Initializes the game's custom memory manager.
int initialize_memory_manager() {
    g_hHeap = GetProcessHeap();
    return 1;
}

// Original Ghidra symbol: FUN_005004c0
// Behavior: Acts as a factory for the MainApp object.
MainApp** create_main_app_instance(HINSTANCE hInstance, const char* lpCmdLine) {
    if (!g_pMainApp) {
        g_pMainApp = new MainApp(0, 1, hInstance, lpCmdLine);
    }
    return &g_pMainApp;
}


// --- MainApp Method Implementations ---

// Original Ghidra symbol: FUN_005004c0
MainApp::MainApp(int param_2, int param_3, HINSTANCE hInstance, const char* lpCmdLine) {
    std::cout << "MainApp constructor started." << std::endl;

    memset(this, 0, sizeof(MainApp));
    this->vfptr = &g_MainAppVTable;
    this->pGameData = new GameData;
    memset(this->pGameData, 0, sizeof(GameData));
    this->pGameData->hInstance = hInstance;
    strncpy_s(this->pGameData->command_line, MAX_PATH, lpCmdLine, _TRUNCATE);

    int success = this->perform_initial_setup();
    
    // The original logic sets a non-zero status code on failure.
    // If setup was successful (returned 1), our status remains 0.
    if (success == 0 && this->initialization_status == 0) {
        this->initialization_status = -1; // Set a generic failure code if none was set
    }
    
    std::cout << "MainApp constructor finished." << std::endl;
}

// Original Ghidra symbol: FUN_00500b30
int MainApp::perform_initial_setup() {
    std::cout << "--- MainApp::perform_initial_setup called ---" << std::endl;
    
    // 1. Determine and load the language DLL.
    char language_dll_name[MAX_PATH] = "languagex.dll"; // Default value
    std::string cmd_line_upper = this->pGameData->command_line;
    std::transform(cmd_line_upper.begin(), cmd_line_upper.end(), cmd_line_upper.begin(), ::toupper);
    
    // The original string at s_STRING=_0055fbb8 is likely "/LANGUAGE=".
    const char* lang_arg_key = "/LANGUAGE=";
    size_t lang_pos = cmd_line_upper.find(lang_arg_key);

    if (lang_pos != std::string::npos) {
        // Found the language override argument.
        size_t value_start = lang_pos + strlen(lang_arg_key);
        // Find the end of the value (space or end of string).
        size_t value_end = cmd_line_upper.find(' ', value_start);
        if (value_end == std::string::npos) {
            value_end = cmd_line_upper.length();
        }
        std::string lang_value = std::string(this->pGameData->command_line).substr(value_start, value_end - value_start);
        
        // The original logic copies this value into the buffer, let's construct the DLL name.
        sprintf_s(language_dll_name, MAX_PATH, "language%s.dll", lang_value.c_str());
        std::cout << "  [INFO] Command line override found. Trying to load: " << language_dll_name << std::endl;
    }

    g_hLanguageDLL = LoadLibraryA(language_dll_name);
    if (g_hLanguageDLL == NULL) {
        // If the custom one fails, it might try the default. The Ghidra code is a bit ambiguous,
        // but failing seems to be the direct result.
        this->initialization_status = 1; // Error code for DLL load failure
        std::cout << "  [FAIL] Could not load " << language_dll_name << std::endl;
        return 0; // Failure
    }
    std::cout << "  [OK] Loaded " << language_dll_name << std::endl;

    // 2. Register all the main data archive (.drs) files.
    // This is the complete list from the decompilation.
    auto register_drs_file = [&](const char* f, const char* g, const char* p, int fl) { /* stub */ }; // Original: FUN_0046c190
    register_drs_file("sounds.drs", "tribe", this->pGameData->data_path, 1);
    register_drs_file("graphics.drs", "tribe", this->pGameData->data_path, 0);
    register_drs_file("Interfac.drs", "tribe", this->pGameData->data_path, 0);
    register_drs_file("sounds.drs", "tribe", "data\\", 1);
    register_drs_file("graphics.drs", "tribe", "data\\", 0);
    register_drs_file("Terrain.drs", "tribe", "data\\", 0);
    register_drs_file("Border.drs", "tribe", "data\\", 0);
    register_drs_file("Interfac.drs", "tribe", "data\\", 0);

    // 3. Perform a critical graphics/device initialization.
    // Original Ghidra symbol: FUN_00416d50
    auto some_graphics_or_device_init = [&]() { std::cout << "  [STUB] Performing graphics/device init (FUN_00416d50)." << std::endl; return 1; };
    if (some_graphics_or_device_init() == 0) {
        return 0; // Failure
    }

    // 4. Create a hidden helper window.
    this->hInputDisabledWindow = CreateWindowExA(0, "STATIC", "InputDisabledWindow", WS_POPUP, 0, 0, 1, 1, this->hWnd, NULL, this->pGameData->hInstance, NULL);

    // 5. Check for lobby mode to decide the game flow.
    auto check_command_line_flag = [&](const char* f) { return false; }; // Original: FUN_0041c5a0
    auto load_game_screen = [&](const char* s) { std::cout << "  [STUB] Loading game screen: " << s << std::endl; };
    auto show_logo_screen = [&]() { std::cout << "  [STUB] Showing logo screen." << std::endl; };

    if (check_command_line_flag("LOBBY")) {
        load_game_screen("MP_Setup_Screen");
    } else {
        show_logo_screen();
        load_game_screen("Main_Menu");
    }

    // 6. Write debug info to a log file.
    auto write_to_log = [&](const char* m, int t) { std::cout << "  [LOG] " << m << std::endl; }; // Original: FUN_005003c0
    write_to_log("------------------------------", 0);
    write_to_log("", 1);
    
    std::cout << "--- MainApp::perform_initial_setup finished successfully ---" << std::endl;
    return 1; // Success
}

// --- Main Entry Point ---
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    AllocConsole();
    FILE* console_stream;
    freopen_s(&console_stream, "CONOUT$", "w", stdout);
    std::cout << "WinMain started." << std::endl;

    int exit_code = 1;

    if (initialize_memory_manager() == 0) {
        MessageBoxA(NULL, "Memory manager initialization failed.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    MainApp** ppApp = create_main_app_instance(hInstance, lpCmdLine);
    if (ppApp == nullptr || *ppApp == nullptr) {
        MessageBoxA(NULL, "Failed to create main application object.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    MainApp* pApp = *ppApp;
    VTable* pVTable = pApp->vfptr;
    
    int init_status = pVTable->functions[6](pApp);

    if (init_status == 0) {
        std::cout << "Initialization status was 0 (Success). Continuing." << std::endl;
        exit_code = pVTable->functions[1](pApp);
        pVTable->functions[0](pApp);
    } else {
        std::cout << "Initialization status was " << init_status << " (Failure). Aborting." << std::endl;
        pVTable->functions[8](pApp);
        pVTable->functions[10](pApp);
        pVTable->functions[0](pApp);
        MessageBoxA(NULL, "Game initialization check failed.", "Error", MB_OK | MB_ICONERROR);
    }
    
    std::cout << "WinMain finished. Exiting with code " << exit_code << "." << std::endl;

    delete g_pMainApp->pGameData;
    delete g_pMainApp;
    g_pMainApp = nullptr;
    if (console_stream) fclose(console_stream);
    FreeConsole();
    
    return exit_code;
}