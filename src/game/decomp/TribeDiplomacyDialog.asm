// Auto-generated scaffold unit: TribeDiplomacyDialog.asm
#include "../include/common.h"

// Offset: 0x0043D6C0
void* TribeDiplomacyDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeDiplomacyDialog::`scalar deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeDiplomacyDialog 
    //              void *            EAX:4          <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043d6c8(R)  
    //                               ??_ETribeDiplomacyDialog@@UAEPAXI@Z                          XREF[1]:     0056f898(*)  
    //                               ??_GTribeDiplomacyDialog@@UAEPAXI@Z
    //                               TribeDiplomacyDialog::`scalar_deleting_destructor'
    //         0043d6c0     PUSH       ESI
    //         0043d6c1     MOV        ESI,this
    //         0043d6c3     CALL       TribeDiplomacyDialog::~TribeDiplomacyDialog      void ~TribeDiplomacyDialog(TribeDiplomacyDial
    //         0043d6c8     TEST       byte ptr [ESP + param_1],0x1
    //         0043d6cd     JZ         LAB_0043d6d8
    //         0043d6cf     PUSH       ESI
    //         0043d6d0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043d6d5     ADD        ESP,0x4
    //                               LAB_0043d6d8                                                 XREF[1]:     0043d6cd(j)  
    //         0043d6d8     MOV        EAX,ESI
    //         0043d6da     POP        ESI
    //         0043d6db     RET        0x4
}

