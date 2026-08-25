// VA: 004E3F80 TribeInformationAIModule::numberAvailableGranaries
// taiinfmd.cpp:8134-8175
//
// Attempt log:
// v0: Direct this->closestDropsiteValue check -> 176 bytes, uses esi for this instead of ebx
// v1: self=this local, first access closestDropsiteValue -> same
// v2: int val = this->closestDropsiteValue[0] temp var -> same (VC5 optimized to direct cmp)
// v3: (int)*this->closestDropsiteValue cast -> same
// v4: self=this, int val, aimd=this->md locals -> same
// v5: swapped access order (val first, then aimd) -> same
// v6: vc5-small flag preset on variant_lab -> all 12 flag variants produce identical code
// v7: fixed RGE_Static_Object local layout to put field_38/field_3C at +0x38/+0x3C and kept currentZone/lookupZone as unsigned char returns; assigning to int with &0xff lets VC5 emit the original and eax,0xff / mov ebp,eax pattern. MATCH.
// BINARY NOTE: The authentic taiinfmd.cpp address sequence is represented by
// the information_dropsites TU prefix. It keeps 004E3E90 before this symbol
// and preserves the information-AI declaration context.
// BINARY NOTE: The shipped body rereads closestDropsiteValue after the
// strategicNumber call. The source keeps that direct member expression.
// BINARY NOTE: The eight-call sibling 004E3E90 remains exact in this context;
// this target has seven calls, including two natural __ftol calls.
// Exact-finish: reduced source retains the direct object calls, uchar zone
// returns, early returns, late strategicNumber publication, and fault order.
// Exact-finish walkback: removing the initial val local stayed exact in this
// TU, so the direct first guard is the reduced source form.

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

int TribeInformationAIModule::numberAvailableGranaries() {
    if (this->closestDropsiteValue[0] == -1) {
        return 0;
    }

    RGE_Static_Object* obj = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1
    );

    if (obj != 0) {
        RGE_Static_Object* filterObj = this->md->object(
            this->closestDropsiteResourceID[0]
        );

        if (filterObj != 0) {
            int zone = obj->currentZone() & 0xff;
            int val3C = (int)filterObj->world_y;
            int val38 = (int)filterObj->world_x;
            int lookup = obj->lookupZone(val38, val3C) & 0xff;
            if (zone != lookup) {
                return 0;
            }
        }
    }

    int strategicN = this->md->tacticalAI.strategicNumber(0xA3);
    return (strategicN < this->closestDropsiteValue[0]) ? 1 : 0;
}
