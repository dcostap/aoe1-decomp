// Auto-generated scaffold unit: RGE_Master_Doppleganger_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x00451120
void* RGE_Master_Doppleganger_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Doppleganger_Object::`scalar deleting destructor'(uns... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Master_Dopplegang
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Dop    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00451128(R)  
    //                               ??_ERGE_Master_Doppleganger_Object@@UAEPAXI@Z                XREF[1]:     00570520(*)  
    //                               ??_GRGE_Master_Doppleganger_Object@@UAEPAXI@Z
    //                               RGE_Master_Doppleganger_Object::`scalar_deleting_destructor'
    //         00451120     PUSH       ESI
    //         00451121     MOV        ESI,this
    //         00451123     CALL       RGE_Master_Doppleganger_Object::~RGE_Master_Do   void ~RGE_Master_Doppleganger_Object(RGE_Mast
    //         00451128     TEST       byte ptr [ESP + param_1],0x1
    //         0045112d     JZ         LAB_00451138
    //         0045112f     PUSH       ESI
    //         00451130     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00451135     ADD        ESP,0x4
    //                               LAB_00451138                                                 XREF[1]:     0045112d(j)  
    //         00451138     MOV        EAX,ESI
    //         0045113a     POP        ESI
    //         0045113b     RET        0x4
}

