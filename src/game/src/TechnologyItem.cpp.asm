// Auto-generated scaffold unit: TechnologyItem.cpp.asm
#include "../include/common.h"

// Offset: 0x00412C00
void* TechnologyItem::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TechnologyItem::`scalar deleting destructor'(unsigned int)          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TechnologyItem * this
    //              void *            EAX:4          <RETURN>
    //              TechnologyItem    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00412c08(R)  
    //                               ??_ETechnologyItem@@UAEPAXI@Z                                XREF[1]:     0056ea94(*)  
    //                               ??_GTechnologyItem@@UAEPAXI@Z
    //                               TechnologyItem::`scalar_deleting_destructor'
    //         00412c00     PUSH       ESI
    //         00412c01     MOV        ESI,this
    //         00412c03     CALL       TechnologyItem::~TechnologyItem                  void ~TechnologyItem(TechnologyItem * this)
    //         00412c08     TEST       byte ptr [ESP + param_1],0x1
    //         00412c0d     JZ         LAB_00412c18
    //         00412c0f     PUSH       ESI
    //         00412c10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00412c15     ADD        ESP,0x4
    //                               LAB_00412c18                                                 XREF[1]:     00412c0d(j)  
    //         00412c18     MOV        EAX,ESI
    //         00412c1a     POP        ESI
    //         00412c1b     RET        0x4
}

