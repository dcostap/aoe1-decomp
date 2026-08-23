// first pass: direct byte flag check, then whitelist the live-target action ids
// if this misses, the remaining mismatch is likely only the early return layout or the byte-field placement

#include "../../include/aiuaimod_context.h"

int UnitAIModule::actionRequiresLiveTarget(int actionId) {
    if (this->stopAfterTargetKilledValue != 1) {
        if (actionId != 0x258 && actionId != 0x259 && actionId != 0x25B && actionId != 0x25C && actionId != 0x26A && actionId != 0x264) {
            return 0;
        }
    }

    return 1;
}
