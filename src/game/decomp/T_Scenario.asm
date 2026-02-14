// Auto-generated scaffold unit: T_Scenario.asm
#include "../include/common.h"

// Offset: 0x0052AB60
void* T_Scenario::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall T_Scenario::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(T_Scenario * this, ui
    //              void *            EAX:4          <RETURN>
    //              T_Scenario *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0052ab68(R)  
    //                               ??_GT_Scenario@@UAEPAXI@Z                                    XREF[1]:     0057730c(*)  
    //                               ??_ET_Scenario@@UAEPAXI@Z
    //                               T_Scenario::`vector_deleting_destructor'
    //         0052ab60     PUSH       ESI
    //         0052ab61     MOV        ESI,this
    //         0052ab63     CALL       T_Scenario::~T_Scenario                          void ~T_Scenario(T_Scenario * this)
    //         0052ab68     TEST       byte ptr [ESP + param_1],0x1
    //         0052ab6d     JZ         LAB_0052ab78
    //         0052ab6f     PUSH       ESI
    //         0052ab70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0052ab75     ADD        ESP,0x4
    //                               LAB_0052ab78                                                 XREF[1]:     0052ab6d(j)  
    //         0052ab78     MOV        EAX,ESI
    //         0052ab7a     POP        ESI
    //         0052ab7b     RET        0x4
}

