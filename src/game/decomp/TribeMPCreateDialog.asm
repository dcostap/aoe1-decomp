// Auto-generated scaffold unit: TribeMPCreateDialog.asm
#include "../include/common.h"

// Offset: 0x00492310
void* TribeMPCreateDialog::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeMPCreateDialog::`vector deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeMPCreateDialog *
    //              void *            EAX:4          <RETURN>
    //              TribeMPCreateD    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00492318(R)  
    //                               ??_GTribeMPCreateDialog@@UAEPAXI@Z                           XREF[1]:     00572620(*)  
    //                               ??_ETribeMPCreateDialog@@UAEPAXI@Z
    //                               TribeMPCreateDialog::`vector_deleting_destructor'
    //         00492310     PUSH       ESI
    //         00492311     MOV        ESI,this
    //         00492313     CALL       TribeMPCreateDialog::~TribeMPCreateDialog        void ~TribeMPCreateDialog(TribeMPCreateDialog
    //         00492318     TEST       byte ptr [ESP + param_1],0x1
    //         0049231d     JZ         LAB_00492328
    //         0049231f     PUSH       ESI
    //         00492320     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00492325     ADD        ESP,0x4
    //                               LAB_00492328                                                 XREF[1]:     0049231d(j)  
    //         00492328     MOV        EAX,ESI
    //         0049232a     POP        ESI
    //         0049232b     RET        0x4
}

