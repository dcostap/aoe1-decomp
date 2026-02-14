// Auto-generated scaffold unit: TListDialog.asm
#include "../include/common.h"

// Offset: 0x0043EEC0
void* TListDialog::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TListDialog::`vector deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TListDialog * this, u
    //              void *            EAX:4          <RETURN>
    //              TListDialog *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043eec8(R)  
    //                               ??_GTListDialog@@UAEPAXI@Z                                   XREF[1]:     0056faf8(*)  
    //                               ??_ETListDialog@@UAEPAXI@Z
    //                               TListDialog::`vector_deleting_destructor'
    //         0043eec0     PUSH       ESI
    //         0043eec1     MOV        ESI,this
    //         0043eec3     CALL       TListDialog::~TListDialog                        void ~TListDialog(TListDialog * this)
    //         0043eec8     TEST       byte ptr [ESP + param_1],0x1
    //         0043eecd     JZ         LAB_0043eed8
    //         0043eecf     PUSH       ESI
    //         0043eed0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043eed5     ADD        ESP,0x4
    //                               LAB_0043eed8                                                 XREF[1]:     0043eecd(j)  
    //         0043eed8     MOV        EAX,ESI
    //         0043eeda     POP        ESI
    //         0043eedb     RET        0x4
}

