// Auto-generated scaffold unit: TRIBE_Tree_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x004CCAF0
void* TRIBE_Tree_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Tree_Object::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Tree_Object * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Tree_Obj    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ccaf8(R)  
    //                               ??_ETRIBE_Tree_Object@@UAEPAXI@Z                             XREF[1]:     00574cb0(*)  
    //                               ??_GTRIBE_Tree_Object@@UAEPAXI@Z
    //                               TRIBE_Tree_Object::`scalar_deleting_destructor'
    //         004ccaf0     PUSH       ESI
    //         004ccaf1     MOV        ESI,this
    //         004ccaf3     CALL       TRIBE_Tree_Object::~TRIBE_Tree_Object            void ~TRIBE_Tree_Object(TRIBE_Tree_Object * t
    //         004ccaf8     TEST       byte ptr [ESP + param_1],0x1
    //         004ccafd     JZ         LAB_004ccb08
    //         004ccaff     PUSH       ESI
    //         004ccb00     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ccb05     ADD        ESP,0x4
    //                               LAB_004ccb08                                                 XREF[1]:     004ccafd(j)  
    //         004ccb08     MOV        EAX,ESI
    //         004ccb0a     POP        ESI
    //         004ccb0b     RET        0x4
}

