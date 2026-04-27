// VA: 00521FA0 TRIBE_Game::setup_cmd_options (598 B)
// PDB source: tribegam.cpp
// Packet-grounded: command line option parsing

extern int strcmp(const char* a, const char* b);
extern int stricmp(const char* a, const char* b);
extern char* strstr(const char* haystack, const char* needle);
extern char* strncpy(char* dst, const char* src, int n);
extern int atoi(const char* s);
extern char* GetCommandLineA(void);
extern char* strchr(const char* s, int c);

int opt_run_log;     // 0x62C4F4
int opt_no_music;    // 0x???
int opt_debug;       // ...

void TRIBE_Game_setup_cmd_options(void* self)
{
    char* cmdLine = GetCommandLineA();
    char* p = cmdLine;
    
    // Parse tokens separated by spaces/arguments
    while (*p) {
        // Skip whitespace
        
        if (stricmp(p, "MUTI") == 0) {
            // Set multiplayer mode
        } else if (stricmp(p, "NOMUSIC") == 0) {
            // Disable music
        } else if (stricmp(p, "NOMOV") == 0) {
            // Disable movies
        } else if (stricmp(p, "NORMAL") == 0) {
            // Normal mode
        } else if (strstr(p, "WIDTH") == p) {
            // Parse width: WIDTH640, WIDTH800, WIDTH1024, WIDTH1280
            // ...
        }
        
        // Advance to next token
        // ...
    }
    
    // Set run_log flag
    opt_run_log = 1;
}
