// Auto-generated scaffold unit: TButtonPanel.cpp.asm
#include "../include/common.h"

// Offset: 0x00472010
void* TButtonPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TButtonPanel::`scalar deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TButtonPanel * this, 
    //              void *            EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00472018(R)  
    //                               ??_ETButtonPanel@@UAEPAXI@Z                                  XREF[1]:     00570fc8(*)  
    //                               ??_GTButtonPanel@@UAEPAXI@Z
    //                               TButtonPanel::`scalar_deleting_destructor'
    //         00472010     PUSH       ESI
    //         00472011     MOV        ESI,this
    //         00472013     CALL       TButtonPanel::~TButtonPanel                      void ~TButtonPanel(TButtonPanel * this)
    //         00472018     TEST       byte ptr [ESP + param_1],0x1
    //         0047201d     JZ         LAB_00472028
    //         0047201f     PUSH       ESI
    //         00472020     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00472025     ADD        ESP,0x4
    //                               LAB_00472028                                                 XREF[1]:     0047201d(j)  
    //         00472028     MOV        EAX,ESI
    //         0047202a     POP        ESI
    //         0047202b     RET        0x4
}

