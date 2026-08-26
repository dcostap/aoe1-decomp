// VA: 00419BC0 UnitAIModule::processRetryableOrder
// PDB owner/access: protected virtual UnitAIModule::processRetryableOrder
// (?processRetryableOrder@UnitAIModule@@MAEHXZ), aiuaimod.cpp:5694-5746.
// Body boundary: 00419BC0-00419C26; 00419C30 is the next sibling.
// EXACT MATCH: switch generates subtract-chain matching original
//
// Exact-finish notes:
// - REQUIRED: the protected virtual declaration restores the PDB-qualified ABI
//   without changing the exact body bytes.
// - WALKBACK: public nonvirtual spelling also emitted exact bytes, but its
//   decorated owner was QAEH rather than the PDB's MAEH protected virtual.
// - BINARY NOTE: lastOrderValue is read before call28 and reread after call40.
//   Do not cache it across either virtual call.
// - BINARY NOTE: the four virtual calls use slots +0x28, +0x40, +0x64, +0x68,
//   with no stores, publication, or cleanup side effects in this body.
// - BINARY NOTE: the fallback return is reached after failed calls or unknown
//   orders; the two recognized orders return 8 only when the final call returns
//   1, and return 7 otherwise.

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
#define AOE1_AIUAIMOD_COMPLETE_TU
#include "../../include/aiuaimod_context.h"
#endif

int UnitAIModule::processRetryableOrder() {
    int result;

    result = this->retryableOrder(this->lastOrderValue);
    if (result == 1) {
        result = this->closestObject(this->lastTargetTypeValue, -1, -1, -1, 0);
        if (result != -1) {
            switch (this->lastOrderValue) {
            case 0x2C5:
                result = this->gatherObject(result, 0);
                return (result == 1) ? 8 : 7;
            case 0x2C9:
                result = this->huntObject(result, 0);
                return (result == 1) ? 8 : 7;
            default:
                return 7;
            }
        }
    }
    return 7;
}
