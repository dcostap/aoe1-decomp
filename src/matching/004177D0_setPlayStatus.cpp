// UnitAIModule::setPlayStatus
// VA: 004177D0 (131 bytes, EH-framed)
// Attempt log:
// - Previous fake-dtor/raw-call source forced an EH frame but used wrong prologue order, extra EDI, indirect call wrappers,
//   and broad stack drift.
// - 2026-05-10 StarryZephyr pass: rewrote as natural typed AIPlayStatus new/copy under /GX. This recovers the original
//   prologue family, no extra EDI, new-expression shape, direct ctor/copy calls, and exact byte count. Remaining mismatch
//   is still broad tail scheduling around common join/new result store.

void* __cdecl operator new(unsigned int sz);

#include "../../include/aiuaimod_context.h"

void UnitAIModule::setPlayStatus(AIPlayStatus* status) {
    if (playStatus == 0) {
        playStatus = new AIPlayStatus();
    }
    if (playStatus != 0 && status != 0) {
        playStatus->copy(status);
    }
}
