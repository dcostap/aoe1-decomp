// Auto-generated scaffold unit: TribeTradeShipUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x005062F0
void* TribeTradeShipUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeTradeShipUnitAIModule::`scalar deleting destructor'(unsigne... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeTradeShipUnitAIM
    //              void *            EAX:4          <RETURN>
    //              TribeTradeShip    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005062f8(R)  
    //                               ??_ETribeTradeShipUnitAIModule@@UAEPAXI@Z                    XREF[1]:     00575f10(*)  
    //                               ??_GTribeTradeShipUnitAIModule@@UAEPAXI@Z
    //                               TribeTradeShipUnitAIModule::`scalar_deleting_destructor'
    //         005062f0     PUSH       ESI
    //         005062f1     MOV        ESI,this
    //         005062f3     CALL       TribeTradeShipUnitAIModule::~TribeTradeShipUni   void ~TribeTradeShipUnitAIModule(TribeTradeSh
    //         005062f8     TEST       byte ptr [ESP + param_1],0x1
    //         005062fd     JZ         LAB_00506308
    //         005062ff     PUSH       ESI
    //         00506300     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506305     ADD        ESP,0x4
    //                               LAB_00506308                                                 XREF[1]:     005062fd(j)  
    //         00506308     MOV        EAX,ESI
    //         0050630a     POP        ESI
    //         0050630b     RET        0x4
}

