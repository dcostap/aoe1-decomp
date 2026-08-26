// 00441EB0 RGE_Doppleganger_Object::update
// Source: dpl_obj.cpp lines 331-414, size 196 bytes
// virtual uchar update(void)
//
// Attempt log:
// 1: wrong RGE_Static_Object size (missing padding fields) → doppled_object at wrong offset
// 2: an incomplete base surface moved destroy_obj to +0x58 instead of +0x68
// 3: the complete named base surface restored destroy_obj at +0x68 ✓
// 4: two-if approach (if(&&) + if(==0)) caused redundant re-read of doppled_object (+10 bytes)
// 5: else-if matches original flow exactly → first 66 bytes now identical
// 6: loop needed ((uv4&1)==1) for mov/and/cmp/jne pattern instead of test/je
// 7: FILE* temp for DDlogf vs direct access — register allocation choice for DDlogf load
//
// Previous baseline: cached `RGE_Player* plyr` kept the right structure but chose
// ECX for the owner and encoded DDlogf as `mov eax,[addr]`, leaving a scheduling
// mismatch after the first 66 bytes.
// Current pass: a local FILE* logf was a codegen duplicate and was rolled back.
// Removing the cached owner and using direct this->owner reads reproduces the
// original EAX owner / ECX DDlogf coloring and matches all 196 bytes.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

unsigned char RGE_Doppleganger_Object::update()
{
    unsigned char result = RGE_Animated_Object::update();

    if (this->doppled_object == 0) {
        this->doppledObjectID = -1;
    } else if (this->doppled_object->object_state >= 7) {
        this->doppled_object = 0;
        this->doppledObjectID = -1;
    }

    unsigned long uVar1 = *this->MapAddress;
    if (uVar1 != this->LastMapValue) {
        if ((this->owner->mutualVisibleMask & uVar1) != 0 && this->object_state < 3) {
            if (DDlogf != 0) {
                fprintf(DDlogf, "DIE DOP (@%d) id=%d own=%d\n",
                    this->owner->world->someField,
                    this->id,
                    this->owner->id);
            }
            this->destroy_obj();
        }

        unsigned long uVar4 = this->owner->nonMutualVisibleMask & uVar1;
        if (uVar4 != 0) {
            unsigned long* puVar5 = (unsigned long*)((char*)this->owner + 0xDC);
            do {
                if ((uVar4 & 1) == 1) {
                    this->CantSeeBits |= *puVar5;
                }
                puVar5++;
                uVar4 >>= 1;
            } while (uVar4 != 0);
        }
        this->LastMapValue = uVar1;
    }

    return result;
}
