// Auto-generated scaffold unit: BuildAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00408820
void* BuildAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall BuildAIModule::`scalar deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(BuildAIModule * this,
    //              void *            EAX:4          <RETURN>
    //              BuildAIModule *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00408828(R)  
    //                               ??_EBuildAIModule@@UAEPAXI@Z                                 XREF[1]:     0056e738(*)  
    //                               ??_GBuildAIModule@@UAEPAXI@Z
    //                               BuildAIModule::`scalar_deleting_destructor'
    //         00408820     PUSH       ESI
    //         00408821     MOV        ESI,this
    //         00408823     CALL       BuildAIModule::~BuildAIModule                    void ~BuildAIModule(BuildAIModule * this)
    //         00408828     TEST       byte ptr [ESP + param_1],0x1
    //         0040882d     JZ         LAB_00408838
    //         0040882f     PUSH       ESI
    //         00408830     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00408835     ADD        ESP,0x4
    //                               LAB_00408838                                                 XREF[1]:     0040882d(j)  
    //         00408838     MOV        EAX,ESI
    //         0040883a     POP        ESI
    //         0040883b     RET        0x4
}

