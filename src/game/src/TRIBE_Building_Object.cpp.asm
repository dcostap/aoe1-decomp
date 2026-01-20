// Auto-generated scaffold unit: TRIBE_Building_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x004C8090
void* TRIBE_Building_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Building_Object::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Building_Object
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004c8098(R)  
    //                               ??_ETRIBE_Building_Object@@UAEPAXI@Z                         XREF[1]:     00574778(*)  
    //                               ??_GTRIBE_Building_Object@@UAEPAXI@Z
    //                               TRIBE_Building_Object::`scalar_deleting_destructor'
    //         004c8090     PUSH       ESI
    //         004c8091     MOV        ESI,this
    //         004c8093     CALL       TRIBE_Building_Object::~TRIBE_Building_Object    void ~TRIBE_Building_Object(TRIBE_Building_Ob
    //         004c8098     TEST       byte ptr [ESP + param_1],0x1
    //         004c809d     JZ         LAB_004c80a8
    //         004c809f     PUSH       ESI
    //         004c80a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004c80a5     ADD        ESP,0x4
    //                               LAB_004c80a8                                                 XREF[1]:     004c809d(j)  
    //         004c80a8     MOV        EAX,ESI
    //         004c80aa     POP        ESI
    //         004c80ab     RET        0x4
}

