// 00441EB0 RGE_Doppleganger_Object::update
// Source: dpl_obj.cpp lines 331-414, size 196 bytes
// virtual uchar update(void)
//
// Attempt log:
// 1: wrong RGE_Static_Object size (missing padding fields) → doppled_object at wrong offset
// 2: vtable names conflicted between base/derived (vf0C, vf10, vf14, vf18 reused) → destroy_obj at +0x58, not +0x68
// 3: renamed dummies with unique 'slotN' names → destroy_obj at +0x68 ✓
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
// RGE_Game_World stub
struct RGE_Game_World {
    char gap_00[4];
    int someField;  // +0x04
};

// RGE_Player layout (partial)
struct RGE_Player {
    char gap_00[0x3C];
    RGE_Game_World* world;                     // +0x3C
    char gap_40[0x0A];
    short id;                                  // +0x4A
    char gap_4C[0x88];
    unsigned long mutualVisibleMask;           // +0xD4
    unsigned long nonMutualVisibleMask;        // +0xD8
    unsigned long RemoveVisibleBits[9];        // +0xDC
};

// RGE_Static_Object layout (size 0x88 = 136 bytes)
struct RGE_Static_Object {
    // vt[0..8]: base virtuals
    virtual void dtor_base();
    virtual void vf04_base();
    virtual void vf08_base();
    virtual void vf0C_base();
    virtual void vf10_base();
    virtual void vf14_base();
    virtual void vf18_base();
    virtual void vf1C_base();
    virtual void vf20_base();

    long id;                              // +0x04
    RGE_Static_Object* master_obj;        // +0x08
    RGE_Player* owner;                    // +0x0C
    char pad_10[0x38];                    // +0x10 to +0x47
    unsigned char object_state;           // +0x48
    char pad_49[0x3F];                    // +0x49 to +0x87
};

// RGE_Animated_Object : RGE_Static_Object (size 0x8C)
struct RGE_Animated_Object : public RGE_Static_Object {
    float speed;                          // +0x88
    virtual unsigned char update();       // vt[9] = +0x24
};

// RGE_Doppleganger_Object : RGE_Animated_Object (size 0xB0)
struct RGE_Doppleganger_Object : public RGE_Animated_Object {
    RGE_Static_Object* doppled_object;    // +0x8C
    char pad_90[0x0C];                    // +0x90 to +0x9B
    unsigned long* MapAddress;            // +0x9C
    unsigned long LastMapValue;           // +0xA0
    unsigned long CantSeeBits;            // +0xA4
    char pad_A8[0x04];                    // +0xA8 to +0xAB
    int doppledObjectID;                  // +0xAC

    // vt[9] = +0x24: update() — override
    // vt[10..25] = +0x28..+0x64: 16 dummies
    // vt[26] = +0x68: destroy_obj()
    virtual unsigned char update();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void destroy_obj();
};

// Global DDlogf at VA 0x0062E638
extern FILE* DDlogf;
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
