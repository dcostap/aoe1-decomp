// Auto-generated scaffold unit: RGE_Doppleganger_Object.asm
#include "../include/common.h"

// Offset: 0x00441A40
void* RGE_Doppleganger_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Doppleganger_Object::`scalar deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Doppleganger_Obje
    //              void *            EAX:4          <RETURN>
    //              RGE_Dopplegang    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00441a48(R)  
    //                               ??_ERGE_Doppleganger_Object@@UAEPAXI@Z                       XREF[1]:     00570220(*)  
    //                               ??_GRGE_Doppleganger_Object@@UAEPAXI@Z
    //                               RGE_Doppleganger_Object::`scalar_deleting_destructor'
    //         00441a40     PUSH       ESI
    //         00441a41     MOV        ESI,this
    //         00441a43     CALL       RGE_Doppleganger_Object::~RGE_Doppleganger_Obj   void ~RGE_Doppleganger_Object(RGE_Dopplegange
    //         00441a48     TEST       byte ptr [ESP + param_1],0x1
    //         00441a4d     JZ         LAB_00441a58
    //         00441a4f     PUSH       ESI
    //         00441a50     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00441a55     ADD        ESP,0x4
    //                               LAB_00441a58                                                 XREF[1]:     00441a4d(j)  
    //         00441a58     MOV        EAX,ESI
    //         00441a5a     POP        ESI
    //         00441a5b     RET        0x4
}

