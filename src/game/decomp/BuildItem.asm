// Auto-generated scaffold unit: BuildItem.asm
#include "../include/common.h"

// Offset: 0x00408200
void* BuildItem::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall BuildItem::`vector deleting destructor'(unsigned int)               *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(BuildItem * this, uin
    //              void *            EAX:4          <RETURN>
    //              BuildItem *       ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00408208(R)  
    //                               ??_GBuildItem@@UAEPAXI@Z                                     XREF[1]:     0056e734(*)  
    //                               ??_EBuildItem@@UAEPAXI@Z
    //                               BuildItem::`vector_deleting_destructor'
    //         00408200     PUSH       ESI
    //         00408201     MOV        ESI,this
    //         00408203     CALL       BuildItem::~BuildItem                            void ~BuildItem(BuildItem * this)
    //         00408208     TEST       byte ptr [ESP + param_1],0x1
    //         0040820d     JZ         LAB_00408218
    //         0040820f     PUSH       ESI
    //         00408210     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00408215     ADD        ESP,0x4
    //                               LAB_00408218                                                 XREF[1]:     0040820d(j)  
    //         00408218     MOV        EAX,ESI
    //         0040821a     POP        ESI
    //         0040821b     RET        0x4
}

