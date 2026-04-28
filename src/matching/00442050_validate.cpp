// 00442050 RGE_Doppleganger_Object::validate
// Source: dpl_obj.cpp lines 467-506, size 172 bytes
// Attempt log:
// first: wrong — nested expression merged offsets (8D9Ch), only one ftol.
// second: prologue + pointer chain + ftol interleaving byte-identical.
//         Fixes needed: virtual call via class (not fn ptr), remove & 0x1F.
// third: MATCH (172/172, 0.0000%)
// Key: VirtualHelper with 27 virtual methods for vtable+0x68 call;
//      no &0x1F on shifts (shl hardware-masks);
//      step-by-step pointer chain interleaved with ftol.

struct ListNode {
    void* object;     // +0x00
    ListNode* next;   // +0x04
};

// Helper class for virtual call at vtable+0x68 (slot 26 = 0x68/4)
struct VirtualHelper {
    virtual void _v00();   // vtable[+0x00]
    virtual void _v04();   // vtable[+0x04]
    virtual void _v08();   // vtable[+0x08]
    virtual void _v0C();   // vtable[+0x0C]
    virtual void _v10();   // vtable[+0x10]
    virtual void _v14();   // vtable[+0x14]
    virtual void _v18();   // vtable[+0x18]
    virtual void _v1C();   // vtable[+0x1C]
    virtual void _v20();   // vtable[+0x20]
    virtual void _v24();   // vtable[+0x24]
    virtual void _v28();   // vtable[+0x28]
    virtual void _v2C();   // vtable[+0x2C]
    virtual void _v30();   // vtable[+0x30]
    virtual void _v34();   // vtable[+0x34]
    virtual void _v38();   // vtable[+0x38]
    virtual void _v3C();   // vtable[+0x3C]
    virtual void _v40();   // vtable[+0x40]
    virtual void _v44();   // vtable[+0x44]
    virtual void _v48();   // vtable[+0x48]
    virtual void _v4C();   // vtable[+0x4C]
    virtual void _v50();   // vtable[+0x50]
    virtual void _v54();   // vtable[+0x54]
    virtual void _v58();   // vtable[+0x58]
    virtual void _v5C();   // vtable[+0x5C]
    virtual void _v60();   // vtable[+0x60]
    virtual void _v64();   // vtable[+0x64]
    virtual void _v68();   // vtable[+0x68] — the actual method
};

struct RGE_Doppleganger_Object {
    char gap_00[4];     // vtable +0x00
    int id;             // +0x04
    char gap_08[4];     // +0x08
    void* world;        // +0x0C
    char gap_10[0x28];  // +0x10 to +0x37
    float x;            // +0x38
    float y;            // +0x3C
    char gap_40[0x64];  // +0x40 to +0xA3
    int cantSeeBits;    // +0xA4
    char gap_A8[4];     // +0xA8
    int doppledObjID;   // +0xAC

    void validate();
};

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
            VirtualHelper* obj = (VirtualHelper*)entry->object;
            if (obj != 0 &&
                *(unsigned char*)((char*)obj + 0x4E) == 0x19 &&
                *(int*)((char*)obj + 0x04) != this->id &&
                *(int*)((char*)obj + 0xAC) == this->doppledObjID &&
                *(unsigned char*)((char*)obj + 0x48) == checkVal) {

                unsigned short s = *(unsigned short*)((char*)this->world + 0x4A);
                if (*(unsigned short*)((char*)*(void**)((char*)obj + 0x0C) + 0x4A) == s) {
                    obj->_v68();
                } else {
                    *(int*)((char*)obj + 0xA4) |= 1 << s;
                    this->cantSeeBits |= 1 << *(unsigned char*)((char*)*(void**)((char*)obj + 0x0C) + 0x4A);
                }
            }
            entry = entry->next;
        } while (entry != 0);
    }
}
