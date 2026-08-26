// attempt log:
// first pass: direct loop over the three attribute slots with raw offsets and the owner vcall
// second pass: align the status/value offsets to the packet's odd mixed index/offset walk and use a raw owner vcall surface
// third pass: swap the attribute-id address expression so VC5 can land the base/index registers in the packet order
// fourth pass: separate the attribute pointer into a named temp to bias the final [reg+reg] encoding
// fifth pass: tried pointer-index spellings instead of byte-offset math to see if VC5 flips the register order on the type load; it moved away from the target basin
// paused here: the remaining mismatch is a single register-order byte on the attr-id load, and the natural byte-offset form is the closest lead
// target shape: for each slot, require status 1..2 and type >= 0, then call owner vfunc +0x78 with (type, value, 0)

#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

void RGE_Static_Object::give_attribute_to_owner(void) {
    int i = 0;
    int local_4 = 0x6A;
    int value_offset = 0x70;

    do {
        RGE_Master_Static_Object* master = this->master_obj;
        unsigned char status = *(unsigned char*)((char*)master + 0x88 + i);
        if (status >= 1 && status <= 2) {
            short* attr_ptr = (short*)((char*)master + local_4);
            short attr_id = *attr_ptr;
            if (attr_id >= 0) {
                float value = *(float*)((char*)master + value_offset);
                this->owner->add_attribute_num(attr_id, value, 0);
            }
        }
        i++;
        local_4 += 2;
        value_offset += 4;
    } while (value_offset < 0x7C);
}
