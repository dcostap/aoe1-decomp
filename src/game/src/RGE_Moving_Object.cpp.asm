// Auto-generated scaffold unit: RGE_Moving_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0045C5A0
void* RGE_Moving_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Moving_Object::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Moving_Object * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Moving_Obj    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0045c5a8(R)  
    //                               ??_ERGE_Moving_Object@@UAEPAXI@Z                             XREF[1]:     00570948(*)  
    //                               ??_GRGE_Moving_Object@@UAEPAXI@Z
    //                               RGE_Moving_Object::`scalar_deleting_destructor'
    //         0045c5a0     PUSH       ESI
    //         0045c5a1     MOV        ESI,this
    //         0045c5a3     CALL       RGE_Moving_Object::~RGE_Moving_Object            void ~RGE_Moving_Object(RGE_Moving_Object * t
    //         0045c5a8     TEST       byte ptr [ESP + param_1],0x1
    //         0045c5ad     JZ         LAB_0045c5b8
    //         0045c5af     PUSH       ESI
    //         0045c5b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045c5b5     ADD        ESP,0x4
    //                               LAB_0045c5b8                                                 XREF[1]:     0045c5ad(j)  
    //         0045c5b8     MOV        EAX,ESI
    //         0045c5ba     POP        ESI
    //         0045c5bb     RET        0x4
}

