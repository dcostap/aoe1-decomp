// Auto-generated scaffold unit: TribeInformationAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x004D7050
void* TribeInformationAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeInformationAIModule::`scalar deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeInformationAIMod
    //              void *            EAX:4          <RETURN>
    //              TribeInformati    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d7058(R)  
    //                               ??_ETribeInformationAIModule@@UAEPAXI@Z                      XREF[1]:     00575510(*)  
    //                               ??_GTribeInformationAIModule@@UAEPAXI@Z
    //                               TribeInformationAIModule::`scalar_deleting_destructor'
    //         004d7050     PUSH       ESI
    //         004d7051     MOV        ESI,this
    //         004d7053     CALL       TribeInformationAIModule::~TribeInformationAIM   void ~TribeInformationAIModule(TribeInformati
    //         004d7058     TEST       byte ptr [ESP + param_1],0x1
    //         004d705d     JZ         LAB_004d7068
    //         004d705f     PUSH       ESI
    //         004d7060     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d7065     ADD        ESP,0x4
    //                               LAB_004d7068                                                 XREF[1]:     004d705d(j)  
    //         004d7068     MOV        EAX,ESI
    //         004d706a     POP        ESI
    //         004d706b     RET        0x4
}

