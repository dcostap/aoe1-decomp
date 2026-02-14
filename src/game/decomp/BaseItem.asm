// Auto-generated scaffold unit: BaseItem.asm
#include "../include/common.h"

// Offset: 0x00407DE0
void* BaseItem::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall BaseItem::`scalar deleting destructor'(unsigned int)                *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(BaseItem * this, uint
    //              void *            EAX:4          <RETURN>
    //              BaseItem *        ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00407de8(R)  
    //                               ??_EBaseItem@@UAEPAXI@Z                                      XREF[1]:     0056e730(*)  
    //                               ??_GBaseItem@@UAEPAXI@Z
    //                               BaseItem::`scalar_deleting_destructor'
    //         00407de0     PUSH       ESI
    //         00407de1     MOV        ESI,this
    //         00407de3     CALL       BaseItem::~BaseItem                              void ~BaseItem(BaseItem * this)
    //         00407de8     TEST       byte ptr [ESP + param_1],0x1
    //         00407ded     JZ         LAB_00407df8
    //         00407def     PUSH       ESI
    //         00407df0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00407df5     ADD        ESP,0x4
    //                               LAB_00407df8                                                 XREF[1]:     00407ded(j)  
    //         00407df8     MOV        EAX,ESI
    //         00407dfa     POP        ESI
    //         00407dfb     RET        0x4
}

