// Auto-generated scaffold unit: TDropDownPanel.asm
#include "../include/common.h"

// Offset: 0x00473F30
void* TDropDownPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TDropDownPanel::`scalar deleting destructor'(unsigned int)          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TDropDownPanel * this
    //              void *            EAX:4          <RETURN>
    //              TDropDownPanel    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00473f38(R)  
    //                               ??_ETDropDownPanel@@UAEPAXI@Z                                XREF[1]:     005711e0(*)  
    //                               ??_GTDropDownPanel@@UAEPAXI@Z
    //                               TDropDownPanel::`scalar_deleting_destructor'
    //         00473f30     PUSH       ESI
    //         00473f31     MOV        ESI,this
    //         00473f33     CALL       TDropDownPanel::~TDropDownPanel                  void ~TDropDownPanel(TDropDownPanel * this)
    //         00473f38     TEST       byte ptr [ESP + param_1],0x1
    //         00473f3d     JZ         LAB_00473f48
    //         00473f3f     PUSH       ESI
    //         00473f40     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00473f45     ADD        ESP,0x4
    //                               LAB_00473f48                                                 XREF[1]:     00473f3d(j)  
    //         00473f48     MOV        EAX,ESI
    //         00473f4a     POP        ESI
    //         00473f4b     RET        0x4
}

