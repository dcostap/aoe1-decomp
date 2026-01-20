// Auto-generated scaffold unit: RGE_Timeline.cpp.asm
#include "../include/common.h"

// Offset: 0x0050D790
void* RGE_Timeline::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Timeline::`vector deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Timeline * this, 
    //              void *            EAX:4          <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050d798(R)  
    //                               ??_GRGE_Timeline@@UAEPAXI@Z                                  XREF[1]:     005766f4(*)  
    //                               ??_ERGE_Timeline@@UAEPAXI@Z
    //                               RGE_Timeline::`vector_deleting_destructor'
    //         0050d790     PUSH       ESI
    //         0050d791     MOV        ESI,this
    //         0050d793     CALL       RGE_Timeline::~RGE_Timeline                      void ~RGE_Timeline(RGE_Timeline * this)
    //         0050d798     TEST       byte ptr [ESP + param_1],0x1
    //         0050d79d     JZ         LAB_0050d7a8
    //         0050d79f     PUSH       ESI
    //         0050d7a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050d7a5     ADD        ESP,0x4
    //                               LAB_0050d7a8                                                 XREF[1]:     0050d79d(j)  
    //         0050d7a8     MOV        EAX,ESI
    //         0050d7aa     POP        ESI
    //         0050d7ab     RET        0x4
}

