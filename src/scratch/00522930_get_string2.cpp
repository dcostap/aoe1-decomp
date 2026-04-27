// VA: 00522930 TRIBE_Game::get_string2 (2287 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: string table lookup with language/option dispatch

extern char* TPanelSystem_getString(void* panelSys, int id);
extern int strcmp(const char* a, const char* b);
extern int strlen(const char* s);
extern char* strcpy(char* dst, const char* src);

char* TRIBE_Game_get_string2(void* self, int id)
{
    // Look up string from language DLL
    // ...
    
    // Fallback chain based on game options
    // ...
    
    return 0;
}
