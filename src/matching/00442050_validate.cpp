// 00442050 RGE_Doppleganger_Object::validate
// Source: dpl_obj.cpp lines 467-506, size 172 bytes
// Attempt log:
// first: wrong — nested expression merged offsets (8D9Ch), only one ftol.
// second: prologue + pointer chain + ftol interleaving byte-identical.
//         Fixes needed: virtual call via class (not fn ptr), remove & 0x1F.
// third: MATCH (172/172, 0.0000%)
// Key: the canonical RGE_Static_Object::destroy_obj method owns the vtable+0x68 call;
//      no &0x1F on shifts (shl hardware-masks);
//      step-by-step pointer chain interleaved with ftol.

struct ListNode {
    void* object;     // +0x00
    ListNode* next;   // +0x04
};

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

void RGE_Doppleganger_Object::validate() {
    void* tmp_a = *(void**)((char*)this->world + 0x3C);
    void* tmp_b = *(void**)((char*)tmp_a + 0x28);
    int row = (int)this->y;
    void* grid = *(void**)((char*)tmp_b + 0x8D8C);
    int col = (int)this->x;

    ListNode* entry = *(ListNode**)((char*)*(void**)((char*)grid + row * 4) + col * 0x18 + 0x10);

    if (entry != 0) {
        unsigned char checkVal = 2;

        do {
            RGE_Doppleganger_Object* obj = (RGE_Doppleganger_Object*)entry->object;
            if (obj != 0 &&
                *(unsigned char*)((char*)obj + 0x4E) == 0x19 &&
                *(int*)((char*)obj + 0x04) != this->id &&
                *(int*)((char*)obj + 0xAC) == this->doppledObjID &&
                *(unsigned char*)((char*)obj + 0x48) == checkVal) {

                unsigned short s = *(unsigned short*)((char*)this->world + 0x4A);
                if (*(unsigned short*)((char*)*(void**)((char*)obj + 0x0C) + 0x4A) == s) {
                    obj->destroy_obj();
                } else {
                    *(int*)((char*)obj + 0xA4) |= 1 << s;
                    this->cantSeeBits |= 1 << *(unsigned char*)((char*)*(void**)((char*)obj + 0x0C) + 0x4A);
                }
            }
            entry = entry->next;
        } while (entry != 0);
    }
}
