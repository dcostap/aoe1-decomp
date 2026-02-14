// Auto-generated scaffold unit: TribeTransportShipUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00506880
void* TribeTransportShipUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeTransportShipUnitAIModule::`scalar deleting destructor'(uns... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeTransportShipUni
    //              void *            EAX:4          <RETURN>
    //              TribeTransport    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00506888(R)  
    //                               ??_ETribeTransportShipUnitAIModule@@UAEPAXI@Z                XREF[1]:     00575ff0(*)  
    //                               ??_GTribeTransportShipUnitAIModule@@UAEPAXI@Z
    //                               TribeTransportShipUnitAIModule::`scalar_deleting_destructor'
    //         00506880     PUSH       ESI
    //         00506881     MOV        ESI,this
    //         00506883     CALL       TribeTransportShipUnitAIModule::~TribeTranspor   void ~TribeTransportShipUnitAIModule(TribeTra
    //         00506888     TEST       byte ptr [ESP + param_1],0x1
    //         0050688d     JZ         LAB_00506898
    //         0050688f     PUSH       ESI
    //         00506890     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506895     ADD        ESP,0x4
    //                               LAB_00506898                                                 XREF[1]:     0050688d(j)  
    //         00506898     MOV        EAX,ESI
    //         0050689a     POP        ESI
    //         0050689b     RET        0x4
}

