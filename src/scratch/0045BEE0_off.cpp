// attempt 1: offsets wrong (+0x134 vs +0x130)
// attempt 2: offsets fixed, Paint call missing vtbl deref (direct call)
// attempt 3: same, renamed member
// attempt 4: Paint as virtual, correct vtbl shape but lea edx vs lea eax (3-byte je offset drift)
// attempt 5: left in scratch after 5 attempts
// Remaining: 87 bytes match but body 3 bytes shorter (lea register choice: edx vs eax cascades into different jump offsets)

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);

class TDrawSystem {
public:
    virtual void Paint(void* rect) = 0;
};

class TMousePointer {
public:
    void* vftable;
    TDrawSystem* draw_system;
    char gap_08[0xB0];
    void* save_area_valid;
    char gap_B8[0x44];
    void* restore_rect;
    char gap_100[0x24];
    int active;
    int drawn;
    int Shutdown;

    void erase();
    void reset();
    void off();
};

void TMousePointer::off() {
    if (!Shutdown) {
        if (vftable && drawn && save_area_valid) {
            erase();
            draw_system->Paint((void*)((char*)this + 0xFC));
        }
        SetCursor(0);
        active = 0;
        reset();
    }
}
