// Auto-generated scaffold unit: RGE_Action_Gather.asm
#include "../include/common.h"

// Offset: 0x00402F10
void* RGE_Action_Gather::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Gather::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Gather * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Gat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00402f18(R)  
    //                               ??_GRGE_Action_Gather@@UAEPAXI@Z                             XREF[1]:     0056e218(*)  
    //                               ??_ERGE_Action_Gather@@UAEPAXI@Z
    //                               RGE_Action_Gather::`vector_deleting_destructor'
    //         00402f10     PUSH       ESI
    //         00402f11     MOV        ESI,this
    //         00402f13     CALL       RGE_Action_Gather::~RGE_Action_Gather            void ~RGE_Action_Gather(RGE_Action_Gather * t
    //         00402f18     TEST       byte ptr [ESP + param_1],0x1
    //         00402f1d     JZ         LAB_00402f28
    //         00402f1f     PUSH       ESI
    //         00402f20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00402f25     ADD        ESP,0x4
    //                               LAB_00402f28                                                 XREF[1]:     00402f1d(j)  
    //         00402f28     MOV        EAX,ESI
    //         00402f2a     POP        ESI
    //         00402f2b     RET        0x4
}

