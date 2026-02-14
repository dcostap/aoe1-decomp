// Auto-generated scaffold unit: RGE_Master_Static_Object.asm
#include "../include/common.h"

// Offset: 0x00452150
void* RGE_Master_Static_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Static_Object::`scalar deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Master_Static_Obj
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00452158(R)  
    //                               ??_ERGE_Master_Static_Object@@UAEPAXI@Z                      XREF[1]:     005705d8(*)  
    //                               ??_GRGE_Master_Static_Object@@UAEPAXI@Z
    //                               RGE_Master_Static_Object::`scalar_deleting_destructor'
    //         00452150     PUSH       ESI
    //         00452151     MOV        ESI,this
    //         00452153     CALL       RGE_Master_Static_Object::~RGE_Master_Static_O   void ~RGE_Master_Static_Object(RGE_Master_Sta
    //         00452158     TEST       byte ptr [ESP + param_1],0x1
    //         0045215d     JZ         LAB_00452168
    //         0045215f     PUSH       ESI
    //         00452160     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00452165     ADD        ESP,0x4
    //                               LAB_00452168                                                 XREF[1]:     0045215d(j)  
    //         00452168     MOV        EAX,ESI
    //         0045216a     POP        ESI
    //         0045216b     RET        0x4
}

