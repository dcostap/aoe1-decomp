// Auto-generated scaffold unit: AIModule.asm
#include "../include/common.h"

// Offset: 0x0040E2B0
void* AIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall AIModule::`scalar deleting destructor'(unsigned int)                *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(AIModule * this, uint
    //              void *            EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040e2b8(R)  
    //                               ??_EAIModule@@UAEPAXI@Z                                      XREF[1]:     0056e930(*)  
    //                               ??_GAIModule@@UAEPAXI@Z
    //                               AIModule::`scalar_deleting_destructor'
    //         0040e2b0     PUSH       ESI
    //         0040e2b1     MOV        ESI,this
    //         0040e2b3     CALL       AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //         0040e2b8     TEST       byte ptr [ESP + param_1],0x1
    //         0040e2bd     JZ         LAB_0040e2c8
    //         0040e2bf     PUSH       ESI
    //         0040e2c0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040e2c5     ADD        ESP,0x4
    //                               LAB_0040e2c8                                                 XREF[1]:     0040e2bd(j)  
    //         0040e2c8     MOV        EAX,ESI
    //         0040e2ca     POP        ESI
    //         0040e2cb     RET        0x4
}

