// Auto-generated scaffold unit: RGE_Master_Moving_Object.asm
#include "../include/common.h"

// Offset: 0x00451A80
void* RGE_Master_Moving_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Moving_Object::`vector deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Moving_Obj
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00451a88(R)  
    //                               ??_GRGE_Master_Moving_Object@@UAEPAXI@Z                      XREF[1]:     005705a0(*)  
    //                               ??_ERGE_Master_Moving_Object@@UAEPAXI@Z
    //                               RGE_Master_Moving_Object::`vector_deleting_destructor'
    //         00451a80     PUSH       ESI
    //         00451a81     MOV        ESI,this
    //         00451a83     CALL       RGE_Master_Moving_Object::~RGE_Master_Moving_O   void ~RGE_Master_Moving_Object(RGE_Master_Mov
    //         00451a88     TEST       byte ptr [ESP + param_1],0x1
    //         00451a8d     JZ         LAB_00451a98
    //         00451a8f     PUSH       ESI
    //         00451a90     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00451a95     ADD        ESP,0x4
    //                               LAB_00451a98                                                 XREF[1]:     00451a8d(j)  
    //         00451a98     MOV        EAX,ESI
    //         00451a9a     POP        ESI
    //         00451a9b     RET        0x4
}

