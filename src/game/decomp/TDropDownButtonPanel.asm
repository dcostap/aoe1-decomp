// Auto-generated scaffold unit: TDropDownButtonPanel.asm
#include "../include/common.h"

// Offset: 0x00475490
void* TDropDownButtonPanel::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TDropDownButtonPanel::`vector deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TDropDownButtonPanel 
    //              void *            EAX:4          <RETURN>
    //              TDropDownButto    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00475498(R)  
    //                               ??_GTDropDownButtonPanel@@UAEPAXI@Z                          XREF[1]:     005712c0(*)  
    //                               ??_ETDropDownButtonPanel@@UAEPAXI@Z
    //                               TDropDownButtonPanel::`vector_deleting_destructor'
    //         00475490     PUSH       ESI
    //         00475491     MOV        ESI,this
    //         00475493     CALL       TDropDownButtonPanel::~TDropDownButtonPanel      void ~TDropDownButtonPanel(TDropDownButtonPan
    //         00475498     TEST       byte ptr [ESP + param_1],0x1
    //         0047549d     JZ         LAB_004754a8
    //         0047549f     PUSH       ESI
    //         004754a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004754a5     ADD        ESP,0x4
    //                               LAB_004754a8                                                 XREF[1]:     0047549d(j)  
    //         004754a8     MOV        EAX,ESI
    //         004754aa     POP        ESI
    //         004754ab     RET        0x4
}

