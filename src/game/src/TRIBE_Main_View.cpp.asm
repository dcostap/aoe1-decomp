// Auto-generated scaffold unit: TRIBE_Main_View.cpp.asm
#include "../include/common.h"

// Offset: 0x00495470
void* TRIBE_Main_View::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Main_View::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Main_View * thi
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Main_Vie    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00495478(R)  
    //                               ??_ETRIBE_Main_View@@UAEPAXI@Z                               XREF[1]:     00572aa8(*)  
    //                               ??_GTRIBE_Main_View@@UAEPAXI@Z
    //                               TRIBE_Main_View::`scalar_deleting_destructor'
    //         00495470     PUSH       ESI
    //         00495471     MOV        ESI,this
    //         00495473     CALL       TRIBE_Main_View::~TRIBE_Main_View                void ~TRIBE_Main_View(TRIBE_Main_View * this)
    //         00495478     TEST       byte ptr [ESP + param_1],0x1
    //         0049547d     JZ         LAB_00495488
    //         0049547f     PUSH       ESI
    //         00495480     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00495485     ADD        ESP,0x4
    //                               LAB_00495488                                                 XREF[1]:     0049547d(j)  
    //         00495488     MOV        EAX,ESI
    //         0049548a     POP        ESI
    //         0049548b     RET        0x4
}

