// Auto-generated scaffold unit: RGE_Action_Explore.asm
#include "../include/common.h"

// Offset: 0x00402B70
void* RGE_Action_Explore::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Explore::`scalar deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Action_Explore * 
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Exp    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00402b78(R)  
    //                               ??_ERGE_Action_Explore@@UAEPAXI@Z                            XREF[1]:     0056e1b0(*)  
    //                               ??_GRGE_Action_Explore@@UAEPAXI@Z
    //                               RGE_Action_Explore::`scalar_deleting_destructor'
    //         00402b70     PUSH       ESI
    //         00402b71     MOV        ESI,this
    //         00402b73     CALL       RGE_Action_Explore::~RGE_Action_Explore          void ~RGE_Action_Explore(RGE_Action_Explore *
    //         00402b78     TEST       byte ptr [ESP + param_1],0x1
    //         00402b7d     JZ         LAB_00402b88
    //         00402b7f     PUSH       ESI
    //         00402b80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00402b85     ADD        ESP,0x4
    //                               LAB_00402b88                                                 XREF[1]:     00402b7d(j)  
    //         00402b88     MOV        EAX,ESI
    //         00402b8a     POP        ESI
    //         00402b8b     RET        0x4
}

