// Auto-generated scaffold unit: TradeAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00412E80
void* TradeAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TradeAIModule::`scalar deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TradeAIModule * this,
    //              void *            EAX:4          <RETURN>
    //              TradeAIModule *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00412e88(R)  
    //                               ??_ETradeAIModule@@UAEPAXI@Z                                 XREF[1]:     0056ea98(*)  
    //                               ??_GTradeAIModule@@UAEPAXI@Z
    //                               TradeAIModule::`scalar_deleting_destructor'
    //         00412e80     PUSH       ESI
    //         00412e81     MOV        ESI,this
    //         00412e83     CALL       TradeAIModule::~TradeAIModule                    void ~TradeAIModule(TradeAIModule * this)
    //         00412e88     TEST       byte ptr [ESP + param_1],0x1
    //         00412e8d     JZ         LAB_00412e98
    //         00412e8f     PUSH       ESI
    //         00412e90     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00412e95     ADD        ESP,0x4
    //                               LAB_00412e98                                                 XREF[1]:     00412e8d(j)  
    //         00412e98     MOV        EAX,ESI
    //         00412e9a     POP        ESI
    //         00412e9b     RET        0x4
}

