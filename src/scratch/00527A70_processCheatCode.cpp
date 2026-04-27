// VA: 00527A70 TRIBE_Game::processCheatCode (3071 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: cheat code string dispatcher

extern int stricmp(const char* a, const char* b);
extern int strnicmp(const char* a, const char* b, int n);
extern int atoi(const char* s);
extern int sprintf(char* buf, const char* fmt, ...);

void TRIBE_Game_processCheatCode(void* self, const char* cheat)
{
    // Check various cheat codes
    if (stricmp(cheat, "BIGDADDY") == 0) {
        // ...
    } else if (stricmp(cheat, "HOMERUN") == 0) {
        // ...
    } else if (stricmp(cheat, "STEROIDS") == 0) {
        // ...
    } else if (stricmp(cheat, "MEDAL") == 0) {
        // ...
    } else if (stricmp(cheat, "REVEAL") == 0) {
        // ...
    } else if (stricmp(cheat, "PEPPERONI") == 0) {
        // ...
    } else if (strnicmp(cheat, "RESOURCE", 8) == 0) {
        // ...
    } else if (stricmp(cheat, "NOFOG") == 0) {
        // ...
    }
    
    // Log cheat usage
    // ...
}
