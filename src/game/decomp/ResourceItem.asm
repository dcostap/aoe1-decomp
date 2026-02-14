// Auto-generated scaffold unit: ResourceItem.asm
#include "../include/common.h"

// Offset: 0x00411EF0
void* ResourceItem::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ResourceItem::`scalar deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(ResourceItem * this, 
    //              void *            EAX:4          <RETURN>
    //              ResourceItem *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00411ef8(R)  
    //                               ??_EResourceItem@@UAEPAXI@Z                                  XREF[1]:     0056e9d0(*)  
    //                               ??_GResourceItem@@UAEPAXI@Z
    //                               ResourceItem::`scalar_deleting_destructor'
    //         00411ef0     PUSH       ESI
    //         00411ef1     MOV        ESI,this
    //         00411ef3     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //         00411ef8     TEST       byte ptr [ESP + param_1],0x1
    //         00411efd     JZ         LAB_00411f08
    //         00411eff     PUSH       ESI
    //         00411f00     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00411f05     ADD        ESP,0x4
    //                               LAB_00411f08                                                 XREF[1]:     00411efd(j)  
    //         00411f08     MOV        EAX,ESI
    //         00411f0a     POP        ESI
    //         00411f0b     RET        0x4
}

