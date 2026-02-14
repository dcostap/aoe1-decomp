// Auto-generated scaffold unit: TScrollTextPanel.asm
#include "../include/common.h"

// Offset: 0x00492F50
void* TScrollTextPanel::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TScrollTextPanel::`vector deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TScrollTextPanel * th
    //              void *            EAX:4          <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00492f58(R)  
    //                               ??_GTScrollTextPanel@@UAEPAXI@Z                              XREF[1]:     00572878(*)  
    //                               ??_ETScrollTextPanel@@UAEPAXI@Z
    //                               TScrollTextPanel::`vector_deleting_destructor'
    //         00492f50     PUSH       ESI
    //         00492f51     MOV        ESI,this
    //         00492f53     CALL       TScrollTextPanel::~TScrollTextPanel              void ~TScrollTextPanel(TScrollTextPanel * this)
    //         00492f58     TEST       byte ptr [ESP + param_1],0x1
    //         00492f5d     JZ         LAB_00492f68
    //         00492f5f     PUSH       ESI
    //         00492f60     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00492f65     ADD        ESP,0x4
    //                               LAB_00492f68                                                 XREF[1]:     00492f5d(j)  
    //         00492f68     MOV        EAX,ESI
    //         00492f6a     POP        ESI
    //         00492f6b     RET        0x4
}

