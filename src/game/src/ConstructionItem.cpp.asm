// Auto-generated scaffold unit: ConstructionItem.cpp.asm
#include "../include/common.h"

// Offset: 0x0040A850
void* ConstructionItem::scalar_deleting_destructor(uint param_1) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ConstructionItem::`scalar deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(ConstructionItem * th
    //              void *            EAX:4          <RETURN>
    //              ConstructionIt    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040a858(R)  
    //                               ??_EConstructionItem@@UAEPAXI@Z                              XREF[1]:     0056e79c(*)  
    //                               ??_GConstructionItem@@UAEPAXI@Z
    //                               ConstructionItem::`scalar_deleting_destructor'
    //         0040a850     PUSH       ESI
    //         0040a851     MOV        ESI,this
    //         0040a853     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
    //         0040a858     TEST       byte ptr [ESP + param_1],0x1
    //         0040a85d     JZ         LAB_0040a868
    //         0040a85f     PUSH       ESI
    //         0040a860     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040a865     ADD        ESP,0x4
    //                               LAB_0040a868                                                 XREF[1]:     0040a85d(j)  
    //         0040a868     MOV        EAX,ESI
    //         0040a86a     POP        ESI
    //         0040a86b     RET        0x4
}

