// 004EEB40 TribeTacticalAIModule::~TribeTacticalAIModule
// Source: taitacmd.cpp lines 2032-2034
// EH-framed destructor: base cleanup, ResourceItem dtor, 13 managed arrays, base dtor
//
// Attempt log:
// Probe 1: proper EH destructor with /GX

#include "..\..\include\game_globals.h"

extern "C" void __cdecl operator_delete(void*);

// Forward declarations for cleanup helpers
void __fastcall removeAllGroups(void*);   // 005003A0
void __fastcall ResourceItem_dtor(void*); // 004120B0
void __fastcall cleanupManagedArray(void*); // 00408D20 (for ecx=this+0F4?)
void __fastcall baseClass_dtor(void*);    // 00412BA0

class TribeTacticalAIModule {
public:
    // Inherits from some base (vtable at 0)
    // Managed arrays at various offsets, each 16 bytes:
    //   +0: value (int*), +4: count, +8: gap, +0xC: maxSize
    
    // +0x0F4: some ManagedArray-like object? call 00408D20
    // +0x104: array 13
    // +0x114: array 12
    // +0x124: array 11
    // +0x134: array 10
    // +0x144: array 9
    // +0x154: array 8
    // +0x164: array 7
    // +0x174: array 6
    // +0x184: array 5
    // +0x9D4: ResourceItem
    // +0xD28: array 4
    // +0xD38: array 3
    // +0xD48: array 2
    // +0xD58: array 1

    // Let's just write the destructor body directly
    virtual ~TribeTacticalAIModule();
};

// Helper: clean up one managed int array at given offset
static void cleanupIntArray(int*& value, int& count, int& gap, int& maxSize)
{
    if (value != 0) {
        operator_delete(value);
        value = 0;
    }
    count = 0;
    gap = 0;
    maxSize = 0;
}

TribeTacticalAIModule::~TribeTacticalAIModule()
{
    // removeAllGroups
    removeAllGroups(this);
    
    // ResourceItem at +0xDA8 destructor
    ResourceItem_dtor((char*)this + 0xDA8);
    
    // Clean up 13 managed arrays
    
    // Array at +0xD58
    {
        int** pv = (int**)((char*)this + 0xD58);
        int* pc = (int*)((char*)this + 0xD5C);
        int* pg = (int*)((char*)this + 0xD60);
        int* pm = (int*)((char*)this + 0xD64);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0xD48
    {
        int** pv = (int**)((char*)this + 0xD48);
        int* pc = (int*)((char*)this + 0xD4C);
        int* pg = (int*)((char*)this + 0xD50);
        int* pm = (int*)((char*)this + 0xD54);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0xD38
    {
        int** pv = (int**)((char*)this + 0xD38);
        int* pc = (int*)((char*)this + 0xD3C);
        int* pg = (int*)((char*)this + 0xD40);
        int* pm = (int*)((char*)this + 0xD44);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0xD28
    {
        int** pv = (int**)((char*)this + 0xD28);
        int* pc = (int*)((char*)this + 0xD2C);
        int* pg = (int*)((char*)this + 0xD30);
        int* pm = (int*)((char*)this + 0xD34);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Resource cleanup at +0x9D4
    // call cleanupManagedArray at ecx=this+0x9D4? Let's skip for now
    
    // Array at +0x184
    {
        int** pv = (int**)((char*)this + 0x184);
        int* pc = (int*)((char*)this + 0x188);
        int* pg = (int*)((char*)this + 0x18C);
        int* pm = (int*)((char*)this + 0x190);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x174
    {
        int** pv = (int**)((char*)this + 0x174);
        int* pc = (int*)((char*)this + 0x178);
        int* pg = (int*)((char*)this + 0x17C);
        int* pm = (int*)((char*)this + 0x180);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x164
    {
        int** pv = (int**)((char*)this + 0x164);
        int* pc = (int*)((char*)this + 0x168);
        int* pg = (int*)((char*)this + 0x16C);
        int* pm = (int*)((char*)this + 0x170);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x154
    {
        int** pv = (int**)((char*)this + 0x154);
        int* pc = (int*)((char*)this + 0x158);
        int* pg = (int*)((char*)this + 0x15C);
        int* pm = (int*)((char*)this + 0x160);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x144
    {
        int** pv = (int**)((char*)this + 0x144);
        int* pc = (int*)((char*)this + 0x148);
        int* pg = (int*)((char*)this + 0x14C);
        int* pm = (int*)((char*)this + 0x150);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x134
    {
        int** pv = (int**)((char*)this + 0x134);
        int* pc = (int*)((char*)this + 0x138);
        int* pg = (int*)((char*)this + 0x13C);
        int* pm = (int*)((char*)this + 0x140);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x124
    {
        int** pv = (int**)((char*)this + 0x124);
        int* pc = (int*)((char*)this + 0x128);
        int* pg = (int*)((char*)this + 0x12C);
        int* pm = (int*)((char*)this + 0x130);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x114 (soldiers)
    {
        int** pv = (int**)((char*)this + 0x114);
        int* pc = (int*)((char*)this + 0x118);
        int* pg = (int*)((char*)this + 0x11C);
        int* pm = (int*)((char*)this + 0x120);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // Array at +0x104
    {
        int** pv = (int**)((char*)this + 0x104);
        int* pc = (int*)((char*)this + 0x108);
        int* pg = (int*)((char*)this + 0x10C);
        int* pm = (int*)((char*)this + 0x110);
        cleanupIntArray(*pv, *pc, *pg, *pm);
    }
    
    // ManagedArray-like cleanup at +0x0F4 (call 00408D20)
    cleanupManagedArray((char*)this + 0x0F4);
    
    // Base class destructor
    baseClass_dtor(this);
}
