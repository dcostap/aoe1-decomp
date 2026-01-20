// Auto-generated scaffold unit: RGE_Master_Action_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0044F0D0
void* RGE_Master_Action_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Action_Object::`vector deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Action_Obj
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Act    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0044f0d8(R)  
    //                               ??_GRGE_Master_Action_Object@@UAEPAXI@Z                      XREF[1]:     00570448(*)  
    //                               ??_ERGE_Master_Action_Object@@UAEPAXI@Z
    //                               RGE_Master_Action_Object::`vector_deleting_destructor'
    //         0044f0d0     PUSH       ESI
    //         0044f0d1     MOV        ESI,this
    //         0044f0d3     CALL       RGE_Master_Action_Object::~RGE_Master_Action_O   void ~RGE_Master_Action_Object(RGE_Master_Act
    //         0044f0d8     TEST       byte ptr [ESP + param_1],0x1
    //         0044f0dd     JZ         LAB_0044f0e8
    //         0044f0df     PUSH       ESI
    //         0044f0e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044f0e5     ADD        ESP,0x4
    //                               LAB_0044f0e8                                                 XREF[1]:     0044f0dd(j)  
    //         0044f0e8     MOV        EAX,ESI
    //         0044f0ea     POP        ESI
    //         0044f0eb     RET        0x4
}

