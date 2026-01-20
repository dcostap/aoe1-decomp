// Auto-generated scaffold unit: TPanel.cpp.asm
#include "../include/common.h"

// Offset: 0x00464890
void* TPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TPanel::`scalar deleting destructor'(unsigned int)                  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TPanel * this, uint p
    //              void *            EAX:4          <RETURN>
    //              TPanel *          ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00464898(R)  
    //                               ??_ETPanel@@UAEPAXI@Z                                        XREF[1]:     00570c38(*)  
    //                               ??_GTPanel@@UAEPAXI@Z
    //                               TPanel::`scalar_deleting_destructor'
    //         00464890     PUSH       ESI
    //         00464891     MOV        ESI,this
    //         00464893     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         00464898     TEST       byte ptr [ESP + param_1],0x1
    //         0046489d     JZ         LAB_004648a8
    //         0046489f     PUSH       ESI
    //         004648a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004648a5     ADD        ESP,0x4
    //                               LAB_004648a8                                                 XREF[1]:     0046489d(j)  
    //         004648a8     MOV        EAX,ESI
    //         004648aa     POP        ESI
    //         004648ab     RET        0x4
}

