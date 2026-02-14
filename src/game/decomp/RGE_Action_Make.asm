// Auto-generated scaffold unit: RGE_Action_Make.asm
#include "../include/common.h"

// Offset: 0x004049E0
void* RGE_Action_Make::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Make::`vector deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Make * thi
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004049e8(R)  
    //                               ??_GRGE_Action_Make@@UAEPAXI@Z                               XREF[1]:     0056e2b8(*)  
    //                               ??_ERGE_Action_Make@@UAEPAXI@Z
    //                               RGE_Action_Make::`vector_deleting_destructor'
    //         004049e0     PUSH       ESI
    //         004049e1     MOV        ESI,this
    //         004049e3     CALL       RGE_Action_Make::~RGE_Action_Make                void ~RGE_Action_Make(RGE_Action_Make * this)
    //         004049e8     TEST       byte ptr [ESP + param_1],0x1
    //         004049ed     JZ         LAB_004049f8
    //         004049ef     PUSH       ESI
    //         004049f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004049f5     ADD        ESP,0x4
    //                               LAB_004049f8                                                 XREF[1]:     004049ed(j)  
    //         004049f8     MOV        EAX,ESI
    //         004049fa     POP        ESI
    //         004049fb     RET        0x4
}

