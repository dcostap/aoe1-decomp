// Auto-generated scaffold unit: TRIBE_Master_Building_Object.asm
#include "../include/common.h"

// Offset: 0x0050E0A0
void* TRIBE_Master_Building_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Master_Building_Object::`vector deleting destructor'(unsig... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Master_Building
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050e0a8(R)  
    //                               ??_GTRIBE_Master_Building_Object@@UAEPAXI@Z                  XREF[1]:     00576700(*)  
    //                               ??_ETRIBE_Master_Building_Object@@UAEPAXI@Z
    //                               TRIBE_Master_Building_Object::`vector_deleting_destructor'
    //         0050e0a0     PUSH       ESI
    //         0050e0a1     MOV        ESI,this
    //         0050e0a3     CALL       TRIBE_Master_Building_Object::~TRIBE_Master_Bu   void ~TRIBE_Master_Building_Object(TRIBE_Mast
    //         0050e0a8     TEST       byte ptr [ESP + param_1],0x1
    //         0050e0ad     JZ         LAB_0050e0b8
    //         0050e0af     PUSH       ESI
    //         0050e0b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050e0b5     ADD        ESP,0x4
    //                               LAB_0050e0b8                                                 XREF[1]:     0050e0ad(j)  
    //         0050e0b8     MOV        EAX,ESI
    //         0050e0ba     POP        ESI
    //         0050e0bb     RET        0x4
}

