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

#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::numberAvailableGranaries() {
    int val = this->closestDropsiteValue[0];

    if (val == -1) {
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
