// Auto-generated scaffold unit: TRIBE_Credits_Screen.cpp.asm
#include "../include/common.h"

// Offset: 0x00492950
void* TRIBE_Credits_Screen::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Credits_Screen::`scalar deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Credits_Screen 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00492958(R)  
    //                               ??_ETRIBE_Credits_Screen@@UAEPAXI@Z                          XREF[1]:     00572750(*)  
    //                               ??_GTRIBE_Credits_Screen@@UAEPAXI@Z
    //                               TRIBE_Credits_Screen::`scalar_deleting_destructor'
    //         00492950     PUSH       ESI
    //         00492951     MOV        ESI,this
    //         00492953     CALL       TRIBE_Credits_Screen::~TRIBE_Credits_Screen      void ~TRIBE_Credits_Screen(TRIBE_Credits_Scre
    //         00492958     TEST       byte ptr [ESP + param_1],0x1
    //         0049295d     JZ         LAB_00492968
    //         0049295f     PUSH       ESI
    //         00492960     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00492965     ADD        ESP,0x4
    //                               LAB_00492968                                                 XREF[1]:     0049295d(j)  
    //         00492968     MOV        EAX,ESI
    //         0049296a     POP        ESI
    //         0049296b     RET        0x4
}

