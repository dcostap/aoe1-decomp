// Auto-generated scaffold unit: TRIBE_Dialog_Name.asm
#include "../include/common.h"

// Offset: 0x004A6F40
void* TRIBE_Dialog_Name::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Dialog_Name::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Dialog_Name * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Dialog_N    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a6f48(R)  
    //                               ??_ETRIBE_Dialog_Name@@UAEPAXI@Z                             XREF[1]:     00573768(*)  
    //                               ??_GTRIBE_Dialog_Name@@UAEPAXI@Z
    //                               TRIBE_Dialog_Name::`scalar_deleting_destructor'
    //         004a6f40     PUSH       ESI
    //         004a6f41     MOV        ESI,this
    //         004a6f43     CALL       TRIBE_Dialog_Name::~TRIBE_Dialog_Name            void ~TRIBE_Dialog_Name(TRIBE_Dialog_Name * t
    //         004a6f48     TEST       byte ptr [ESP + param_1],0x1
    //         004a6f4d     JZ         LAB_004a6f58
    //         004a6f4f     PUSH       ESI
    //         004a6f50     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a6f55     ADD        ESP,0x4
    //                               LAB_004a6f58                                                 XREF[1]:     004a6f4d(j)  
    //         004a6f58     MOV        EAX,ESI
    //         004a6f5a     POP        ESI
    //         004a6f5b     RET        0x4
}

