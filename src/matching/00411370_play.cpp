// VA: 00411370
// PDB-qualified owner: public: class AIPlay *__thiscall AIPlayBook::play(char *)
// PDB source: C:\msdev\work\age1_x1\aipbook.cpp, lines 1304-1312
// Body boundary: 00411370-004113F2; the next PDB owner starts at 00411400.
// FLAGS: /nologo /c /O2 /Oy
//
// BINARY NOTE: The null-play and non-positive-count guards occur in this order.
// The returned pointer uses the 0x608-byte AIPlay stride.
// The canonical aipbook context supplies the reviewed AIPlayBook owner and layout.
// The natural for-loop supplies the one emitted count guard.

#include "../../include/aipbook_context.h"

AIPlay* AIPlayBook::play(char* name) {
    if (this->plays == 0) return 0;
    for (int i = 0; i < this->numberPlaysValue; i++) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return &this->plays[i];
        }
    }
    return 0;
}
