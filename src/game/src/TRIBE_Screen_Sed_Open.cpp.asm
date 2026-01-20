// Auto-generated scaffold unit: TRIBE_Screen_Sed_Open.cpp.asm
#include "../include/common.h"

// Offset: 0x004B3680
void* TRIBE_Screen_Sed_Open::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Sed_Open::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Screen_Sed_Open
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b3688(R)  
    //                               ??_ETRIBE_Screen_Sed_Open@@UAEPAXI@Z                         XREF[1]:     00573c28(*)  
    //                               ??_GTRIBE_Screen_Sed_Open@@UAEPAXI@Z
    //                               TRIBE_Screen_Sed_Open::`scalar_deleting_destructor'
    //         004b3680     PUSH       ESI
    //         004b3681     MOV        ESI,this
    //         004b3683     CALL       TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open    void ~TRIBE_Screen_Sed_Open(TRIBE_Screen_Sed_
    //         004b3688     TEST       byte ptr [ESP + param_1],0x1
    //         004b368d     JZ         LAB_004b3698
    //         004b368f     PUSH       ESI
    //         004b3690     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b3695     ADD        ESP,0x4
    //                               LAB_004b3698                                                 XREF[1]:     004b368d(j)  
    //         004b3698     MOV        EAX,ESI
    //         004b369a     POP        ESI
    //         004b369b     RET        0x4
}

