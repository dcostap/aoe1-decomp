// Auto-generated scaffold unit: TRIBE_Master_Tree_Object.asm
#include "../include/common.h"

// Offset: 0x0050F1F0
void* TRIBE_Master_Tree_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Master_Tree_Object::`scalar deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Master_Tree_Obj
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050f1f8(R)  
    //                               ??_ETRIBE_Master_Tree_Object@@UAEPAXI@Z                      XREF[1]:     00576790(*)  
    //                               ??_GTRIBE_Master_Tree_Object@@UAEPAXI@Z
    //                               TRIBE_Master_Tree_Object::`scalar_deleting_destructor'
    //         0050f1f0     PUSH       ESI
    //         0050f1f1     MOV        ESI,this
    //         0050f1f3     CALL       TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_O   void ~TRIBE_Master_Tree_Object(TRIBE_Master_T
    //         0050f1f8     TEST       byte ptr [ESP + param_1],0x1
    //         0050f1fd     JZ         LAB_0050f208
    //         0050f1ff     PUSH       ESI
    //         0050f200     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050f205     ADD        ESP,0x4
    //                               LAB_0050f208                                                 XREF[1]:     0050f1fd(j)  
    //         0050f208     MOV        EAX,ESI
    //         0050f20a     POP        ESI
    //         0050f20b     RET        0x4
}

