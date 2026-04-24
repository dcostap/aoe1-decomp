// attempt 1: simple class, /GX; only 32 bytes (no EH frame generated)
// attempt 2: inheritance + /GX; 80 bytes, 6 short (missing explicit vtable store)
// attempt 3: explicit vtable ptr with extern; only 48 bytes (worse)
// attempt 4: back to 80-byte shape; same 80
// attempt 5: stdlib.h/stddef.h include; same 80
// attempt 6: vtable ptr assignment with local; 48 bytes (worse)
// attempt 7: lea for message addr, fixed delete_panel(0, p); same 80
// Left in scratch: 80 vs 86 bytes; VC5 doesn't emit explicit destroying vtable store
// (mov dword [esi], 0x573518 = 6 bytes) with this class hierarchy. Behavior correct.

#include <stddef.h>

void TPanel_delete_panel(void* thisPtr, void** p);
void TScreenPanel_destructor(void* thisPtr);

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    virtual void update();
};

class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    char gap_00[0x47C];
    void* message;

    virtual ~TRIBE_Screen_Disconnect();
    virtual void update();
};

TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect() {
    void** p = (void**)((char*)this + 0x47C);
    TPanel_delete_panel(0, p);
    TScreenPanel::~TScreenPanel();
}
