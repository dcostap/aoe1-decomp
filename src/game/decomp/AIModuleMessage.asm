// Auto-generated scaffold unit: AIModuleMessage.asm
#include "../include/common.h"

// Offset: 0x0040DF30
void* AIModuleMessage::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall AIModuleMessage::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(AIModuleMessage * thi
    //              void *            EAX:4          <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040df38(R)  
    //                               ??_EAIModuleMessage@@UAEPAXI@Z                               XREF[1]:     0056e92c(*)  
    //                               ??_GAIModuleMessage@@UAEPAXI@Z
    //                               AIModuleMessage::`scalar_deleting_destructor'
    //         0040df30     PUSH       ESI
    //         0040df31     MOV        ESI,this
    //         0040df33     CALL       AIModuleMessage::~AIModuleMessage                void ~AIModuleMessage(AIModuleMessage * this)
    //         0040df38     TEST       byte ptr [ESP + param_1],0x1
    //         0040df3d     JZ         LAB_0040df48
    //         0040df3f     PUSH       ESI
    //         0040df40     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040df45     ADD        ESP,0x4
    //                               LAB_0040df48                                                 XREF[1]:     0040df3d(j)  
    //         0040df48     MOV        EAX,ESI
    //         0040df4a     POP        ESI
    //         0040df4b     RET        0x4
}

