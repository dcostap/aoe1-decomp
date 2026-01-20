// Auto-generated scaffold unit: TRIBE_Master_Combat_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0050E9D0
void* TRIBE_Master_Combat_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Master_Combat_Object::`vector deleting destructor'(unsigne... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Master_Combat_O
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050e9d8(R)  
    //                               ??_GTRIBE_Master_Combat_Object@@UAEPAXI@Z                    XREF[1]:     00576740(*)  
    //                               ??_ETRIBE_Master_Combat_Object@@UAEPAXI@Z
    //                               TRIBE_Master_Combat_Object::`vector_deleting_destructor'
    //         0050e9d0     PUSH       ESI
    //         0050e9d1     MOV        ESI,this
    //         0050e9d3     CALL       TRIBE_Master_Combat_Object::~TRIBE_Master_Comb   void ~TRIBE_Master_Combat_Object(TRIBE_Master
    //         0050e9d8     TEST       byte ptr [ESP + param_1],0x1
    //         0050e9dd     JZ         LAB_0050e9e8
    //         0050e9df     PUSH       ESI
    //         0050e9e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050e9e5     ADD        ESP,0x4
    //                               LAB_0050e9e8                                                 XREF[1]:     0050e9dd(j)  
    //         0050e9e8     MOV        EAX,ESI
    //         0050e9ea     POP        ESI
    //         0050e9eb     RET        0x4
}

