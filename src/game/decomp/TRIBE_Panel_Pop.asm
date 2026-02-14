// Auto-generated scaffold unit: TRIBE_Panel_Pop.asm
#include "../include/common.h"

// Offset: 0x0051CD90
void* TRIBE_Panel_Pop::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Panel_Pop::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Panel_Pop * thi
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Panel_Po    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0051cd98(R)  
    //                               ??_ETRIBE_Panel_Pop@@UAEPAXI@Z                               XREF[1]:     00576dc0(*)  
    //                               ??_GTRIBE_Panel_Pop@@UAEPAXI@Z
    //                               TRIBE_Panel_Pop::`scalar_deleting_destructor'
    //         0051cd90     PUSH       ESI
    //         0051cd91     MOV        ESI,this
    //         0051cd93     CALL       TRIBE_Panel_Pop::~TRIBE_Panel_Pop                void ~TRIBE_Panel_Pop(TRIBE_Panel_Pop * this)
    //         0051cd98     TEST       byte ptr [ESP + param_1],0x1
    //         0051cd9d     JZ         LAB_0051cda8
    //         0051cd9f     PUSH       ESI
    //         0051cda0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051cda5     ADD        ESP,0x4
    //                               LAB_0051cda8                                                 XREF[1]:     0051cd9d(j)  
    //         0051cda8     MOV        EAX,ESI
    //         0051cdaa     POP        ESI
    //         0051cdab     RET        0x4
}

