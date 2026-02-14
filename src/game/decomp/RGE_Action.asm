// Auto-generated scaffold unit: RGE_Action.asm
#include "../include/common.h"

// Offset: 0x004074A0
void* RGE_Action::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action * this, ui
    //              void *            EAX:4          <RETURN>
    //              RGE_Action *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004074a8(R)  
    //                               ??_GRGE_Action@@UAEPAXI@Z                                    XREF[1]:     0056e6d0(*)  
    //                               ??_ERGE_Action@@UAEPAXI@Z
    //                               RGE_Action::`vector_deleting_destructor'
    //         004074a0     PUSH       ESI
    //         004074a1     MOV        ESI,this
    //         004074a3     CALL       RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
    //         004074a8     TEST       byte ptr [ESP + param_1],0x1
    //         004074ad     JZ         LAB_004074b8
    //         004074af     PUSH       ESI
    //         004074b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004074b5     ADD        ESP,0x4
    //                               LAB_004074b8                                                 XREF[1]:     004074ad(j)  
    //         004074b8     MOV        EAX,ESI
    //         004074ba     POP        ESI
    //         004074bb     RET        0x4
}

