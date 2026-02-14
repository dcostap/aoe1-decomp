// Auto-generated scaffold unit: AIModuleID.asm
#include "../include/common.h"

// Offset: 0x0040DDF0
void* AIModuleID::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall AIModuleID::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(AIModuleID * this, ui
    //              void *            EAX:4          <RETURN>
    //              AIModuleID *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040ddf8(R)  
    //                               ??_GAIModuleID@@UAEPAXI@Z                                    XREF[1]:     0056e928(*)  
    //                               ??_EAIModuleID@@UAEPAXI@Z
    //                               AIModuleID::`vector_deleting_destructor'
    //         0040ddf0     PUSH       ESI
    //         0040ddf1     MOV        ESI,this
    //         0040ddf3     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040ddf8     TEST       byte ptr [ESP + param_1],0x1
    //         0040ddfd     JZ         LAB_0040de08
    //         0040ddff     PUSH       ESI
    //         0040de00     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040de05     ADD        ESP,0x4
    //                               LAB_0040de08                                                 XREF[1]:     0040ddfd(j)  
    //         0040de08     MOV        EAX,ESI
    //         0040de0a     POP        ESI
    //         0040de0b     RET        0x4
}

