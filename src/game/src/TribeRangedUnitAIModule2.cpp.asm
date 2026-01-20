// Auto-generated scaffold unit: TribeRangedUnitAIModule2.cpp.asm
#include "../include/common.h"

// Offset: 0x005048A0
void* TribeRangedUnitAIModule2::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeRangedUnitAIModule2::`vector deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeRangedUnitAIModu
    //              void *            EAX:4          <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005048a8(R)  
    //                               ??_GTribeRangedUnitAIModule2@@UAEPAXI@Z                      XREF[1]:     00575c68(*)  
    //                               ??_ETribeRangedUnitAIModule2@@UAEPAXI@Z
    //                               TribeRangedUnitAIModule2::`vector_deleting_destructor'
    //         005048a0     PUSH       ESI
    //         005048a1     MOV        ESI,this
    //         005048a3     CALL       TribeRangedUnitAIModule2::~TribeRangedUnitAIMo   void ~TribeRangedUnitAIModule2(TribeRangedUni
    //         005048a8     TEST       byte ptr [ESP + param_1],0x1
    //         005048ad     JZ         LAB_005048b8
    //         005048af     PUSH       ESI
    //         005048b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005048b5     ADD        ESP,0x4
    //                               LAB_005048b8                                                 XREF[1]:     005048ad(j)  
    //         005048b8     MOV        EAX,ESI
    //         005048ba     POP        ESI
    //         005048bb     RET        0x4
}

