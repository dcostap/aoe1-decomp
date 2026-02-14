// Auto-generated scaffold unit: TListPanel.asm
#include "../include/common.h"

// Offset: 0x00478310
void* TListPanel::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TListPanel::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TListPanel * this, ui
    //              void *            EAX:4          <RETURN>
    //              TListPanel *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00478318(R)  
    //                               ??_GTListPanel@@UAEPAXI@Z                                    XREF[1]:     00571578(*)  
    //                               ??_ETListPanel@@UAEPAXI@Z
    //                               TListPanel::`vector_deleting_destructor'
    //         00478310     PUSH       ESI
    //         00478311     MOV        ESI,this
    //         00478313     CALL       TListPanel::~TListPanel                          void ~TListPanel(TListPanel * this)
    //         00478318     TEST       byte ptr [ESP + param_1],0x1
    //         0047831d     JZ         LAB_00478328
    //         0047831f     PUSH       ESI
    //         00478320     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00478325     ADD        ESP,0x4
    //                               LAB_00478328                                                 XREF[1]:     0047831d(j)  
    //         00478328     MOV        EAX,ESI
    //         0047832a     POP        ESI
    //         0047832b     RET        0x4
}

