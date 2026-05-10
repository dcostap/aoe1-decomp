// UnitAIModule::setPlayStatus
// VA: 004177D0 (131 bytes, EH-framed)
// Attempt log:
// - Previous fake-dtor/raw-call source forced an EH frame but used wrong prologue order, extra EDI, indirect call wrappers,
//   and broad stack drift.
// - 2026-05-10 StarryZephyr pass: rewrote as natural typed AIPlayStatus new/copy under /GX. This recovers the original
//   prologue family, no extra EDI, new-expression shape, direct ctor/copy calls, and exact byte count. Remaining mismatch
//   is still broad tail scheduling around common join/new result store.

void* __cdecl operator new(unsigned int sz);

class AIPlayStatus {
public:
    char gap_00[0x1C8];
    AIPlayStatus();
    void copy(AIPlayStatus* other);
};

class UnitAIModule {
public:
    char gap_00[0x12C];
    AIPlayStatus* play_status;

    void setPlayStatus(AIPlayStatus* status);
};

void UnitAIModule::setPlayStatus(AIPlayStatus* status) {
    if (play_status == 0) {
        play_status = new AIPlayStatus();
    }
    if (play_status != 0 && status != 0) {
        play_status->copy(status);
    }
}
