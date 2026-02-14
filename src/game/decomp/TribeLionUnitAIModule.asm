// Auto-generated scaffold unit: TribeLionUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00504440
void* TribeLionUnitAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeLionUnitAIModule::`vector deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeLionUnitAIModule
    //              void *            EAX:4          <RETURN>
    //              TribeLionUnitA    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504448(R)  
    //                               ??_GTribeLionUnitAIModule@@UAEPAXI@Z                         XREF[1]:     00575aa8(*)  
    //                               ??_ETribeLionUnitAIModule@@UAEPAXI@Z
    //                               TribeLionUnitAIModule::`vector_deleting_destructor'
    //         00504440     PUSH       ESI
    //         00504441     MOV        ESI,this
    //         00504443     CALL       TribeLionUnitAIModule::~TribeLionUnitAIModule    void ~TribeLionUnitAIModule(TribeLionUnitAIMo
    //         00504448     TEST       byte ptr [ESP + param_1],0x1
    //         0050444d     JZ         LAB_00504458
    //         0050444f     PUSH       ESI
    //         00504450     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504455     ADD        ESP,0x4
    //                               LAB_00504458                                                 XREF[1]:     0050444d(j)  
    //         00504458     MOV        EAX,ESI
    //         0050445a     POP        ESI
    //         0050445b     RET        0x4
}

