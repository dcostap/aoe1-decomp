// Auto-generated scaffold unit: RGE_Action_Enter.asm
#include "../include/common.h"

// Offset: 0x004023F0
void* RGE_Action_Enter::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Enter::`scalar deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Action_Enter * th
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Ent    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004023f8(R)  
    //                               ??_ERGE_Action_Enter@@UAEPAXI@Z                              XREF[1]:     0056e140(*)  
    //                               ??_GRGE_Action_Enter@@UAEPAXI@Z
    //                               RGE_Action_Enter::`scalar_deleting_destructor'
    //         004023f0     PUSH       ESI
    //         004023f1     MOV        ESI,this
    //         004023f3     CALL       RGE_Action_Enter::~RGE_Action_Enter              void ~RGE_Action_Enter(RGE_Action_Enter * this)
    //         004023f8     TEST       byte ptr [ESP + param_1],0x1
    //         004023fd     JZ         LAB_00402408
    //         004023ff     PUSH       ESI
    //         00402400     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00402405     ADD        ESP,0x4
    //                               LAB_00402408                                                 XREF[1]:     004023fd(j)  
    //         00402408     MOV        EAX,ESI
    //         0040240a     POP        ESI
    //         0040240b     RET        0x4
}

