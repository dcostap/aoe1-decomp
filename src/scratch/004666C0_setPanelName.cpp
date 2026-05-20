// 004666C0 TPanel::setPanelName
// Panel.cpp:2398-2413, 166 bytes, __thiscall, ret 4
// Retry 2026-05-20: 15 honest variants.
// - Baseline strlen/malloc/memcpy was very close structurally but compiled to 160B for 166B target;
//   it matches prologue and main REP-copy family but places cleanup early/short and lacks original block sizes.
// - Tried positive if/else cleanup-at-end, nested positive guards, explicit return/goto cleanup labels,
//   saved strlen locals, strcpy surface, old-panel-name local, volatile old local, goto-free/alloc/copy labels,
//   memcpy vs strcpy, saved malloc len. Exact-size variants existed but still broad mismatches.
// - Best exact-size kept below: strcpy + explicit old/goto free/alloc/copy labels, 57.8313% positional /
//   18.0723% edit. It preserves high-level behavior and size but still shifts branch targets and differs
//   in redundant old-pointer test/free scheduling plus strcpy vs original memcpy REP-copy details.
// GIVEUP: remaining mismatch spans block layout, cleanup placement, allocation/free scheduling, and copy
// helper lowering. Not accepted_drift: broad control-flow/copy drift, not localized benign drift.

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
        if (old == 0) goto alloc;
        free(old);
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
