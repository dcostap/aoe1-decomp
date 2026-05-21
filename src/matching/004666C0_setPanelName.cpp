// 004666C0 TPanel::setPanelName
// Panel.cpp:2398-2413, 166 bytes, __thiscall, ret 4
// MATCHED 2026-05-21: exact after preserving strcpy's REP-copy lowering but spelling
// the second stale-pointer guard as `if (panel_name == 0)` / `free(panel_name)` instead
// of reusing the proven-nonzero `old` local. That forced VC5 to keep the original
// redundant test/free block while retaining the strcpy copy-shape.

#include <string.h>
#include <stdlib.h>

class TPanel {
public:
    unsigned char gap_00[0x1C];
    char* panel_name;  // +0x1C
    
    void setPanelName(const char* name);
};

void TPanel::setPanelName(const char* name) {
    if (name != 0 && strlen(name) != 0) {
        char* old = panel_name;
        if (old == 0) goto alloc;
        if (strlen(old) >= strlen(name)) goto copy;
        if (panel_name == 0) goto alloc;
        free(panel_name);
alloc:
        panel_name = (char*)malloc(strlen(name) + 1);
copy:
        strcpy(panel_name, name);
    } else {
        if (panel_name != 0) {
            free(panel_name);
            panel_name = 0;
        }
    }
}
