// Auto-generated scaffold unit: TRIBE_Screen_Info.cpp.asm
#include "../include/common.h"

// Offset: 0x0049D5E0
void* TRIBE_Screen_Info::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Info::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Screen_Info * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0049d5e8(R)  
    //                               ??_ETRIBE_Screen_Info@@UAEPAXI@Z                             XREF[1]:     00572d00(*)  
    //                               ??_GTRIBE_Screen_Info@@UAEPAXI@Z
    //                               TRIBE_Screen_Info::`scalar_deleting_destructor'
    //         0049d5e0     PUSH       ESI
    //         0049d5e1     MOV        ESI,this
    //         0049d5e3     CALL       TRIBE_Screen_Info::~TRIBE_Screen_Info            void ~TRIBE_Screen_Info(TRIBE_Screen_Info * t
    //         0049d5e8     TEST       byte ptr [ESP + param_1],0x1
    //         0049d5ed     JZ         LAB_0049d5f8
    //         0049d5ef     PUSH       ESI
    //         0049d5f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0049d5f5     ADD        ESP,0x4
    //                               LAB_0049d5f8                                                 XREF[1]:     0049d5ed(j)  
    //         0049d5f8     MOV        EAX,ESI
    //         0049d5fa     POP        ESI
    //         0049d5fb     RET        0x4
}

