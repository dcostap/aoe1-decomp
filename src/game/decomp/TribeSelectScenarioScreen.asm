// Auto-generated scaffold unit: TribeSelectScenarioScreen.asm
#include "../include/common.h"

// Offset: 0x004B4100
void* TribeSelectScenarioScreen::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSelectScenarioScreen::`scalar deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeSelectScenarioSc
    //              void *            EAX:4          <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b4108(R)  
    //                               ??_ETribeSelectScenarioScreen@@UAEPAXI@Z                     XREF[1]:     00573d50(*)  
    //                               ??_GTribeSelectScenarioScreen@@UAEPAXI@Z
    //                               TribeSelectScenarioScreen::`scalar_deleting_destructor'
    //         004b4100     PUSH       ESI
    //         004b4101     MOV        ESI,this
    //         004b4103     CALL       TribeSelectScenarioScreen::~TribeSelectScenari   void ~TribeSelectScenarioScreen(TribeSelectSc
    //         004b4108     TEST       byte ptr [ESP + param_1],0x1
    //         004b410d     JZ         LAB_004b4118
    //         004b410f     PUSH       ESI
    //         004b4110     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b4115     ADD        ESP,0x4
    //                               LAB_004b4118                                                 XREF[1]:     004b410d(j)  
    //         004b4118     MOV        EAX,ESI
    //         004b411a     POP        ESI
    //         004b411b     RET        0x4
}

