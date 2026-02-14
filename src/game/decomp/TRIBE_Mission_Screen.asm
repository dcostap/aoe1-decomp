// Auto-generated scaffold unit: TRIBE_Mission_Screen.asm
#include "../include/common.h"

// Offset: 0x004B87B0
void* TRIBE_Mission_Screen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Mission_Screen::`vector deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Mission_Screen 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Mission_    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b87b8(R)  
    //                               ??_GTRIBE_Mission_Screen@@UAEPAXI@Z                          XREF[1]:     00574318(*)  
    //                               ??_ETRIBE_Mission_Screen@@UAEPAXI@Z
    //                               TRIBE_Mission_Screen::`vector_deleting_destructor'
    //         004b87b0     PUSH       ESI
    //         004b87b1     MOV        ESI,this
    //         004b87b3     CALL       TRIBE_Mission_Screen::~TRIBE_Mission_Screen      void ~TRIBE_Mission_Screen(TRIBE_Mission_Scre
    //         004b87b8     TEST       byte ptr [ESP + param_1],0x1
    //         004b87bd     JZ         LAB_004b87c8
    //         004b87bf     PUSH       ESI
    //         004b87c0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b87c5     ADD        ESP,0x4
    //                               LAB_004b87c8                                                 XREF[1]:     004b87bd(j)  
    //         004b87c8     MOV        EAX,ESI
    //         004b87ca     POP        ESI
    //         004b87cb     RET        0x4
}

