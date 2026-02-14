// Auto-generated scaffold unit: TEditPanel.asm
#include "../include/common.h"

// Offset: 0x00475670
void* TEditPanel::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TEditPanel::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TEditPanel * this, ui
    //              void *            EAX:4          <RETURN>
    //              TEditPanel *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00475678(R)  
    //                               ??_GTEditPanel@@UAEPAXI@Z                                    XREF[1]:     005713a8(*)  
    //                               ??_ETEditPanel@@UAEPAXI@Z
    //                               TEditPanel::`vector_deleting_destructor'
    //         00475670     PUSH       ESI
    //         00475671     MOV        ESI,this
    //         00475673     CALL       TEditPanel::~TEditPanel                          void ~TEditPanel(TEditPanel * this)
    //         00475678     TEST       byte ptr [ESP + param_1],0x1
    //         0047567d     JZ         LAB_00475688
    //         0047567f     PUSH       ESI
    //         00475680     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00475685     ADD        ESP,0x4
    //                               LAB_00475688                                                 XREF[1]:     0047567d(j)  
    //         00475688     MOV        EAX,ESI
    //         0047568a     POP        ESI
    //         0047568b     RET        0x4
}

