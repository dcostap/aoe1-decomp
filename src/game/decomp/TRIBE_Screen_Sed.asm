// Auto-generated scaffold unit: TRIBE_Screen_Sed.asm
#include "../include/common.h"

// Offset: 0x004A8750
void* TRIBE_Screen_Sed::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Sed::`vector deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Sed * th
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a8758(R)  
    //                               ??_GTRIBE_Screen_Sed@@UAEPAXI@Z                              XREF[1]:     005739c0(*)  
    //                               ??_ETRIBE_Screen_Sed@@UAEPAXI@Z
    //                               TRIBE_Screen_Sed::`vector_deleting_destructor'
    //         004a8750     PUSH       ESI
    //         004a8751     MOV        ESI,this
    //         004a8753     CALL       TRIBE_Screen_Sed::~TRIBE_Screen_Sed              void ~TRIBE_Screen_Sed(TRIBE_Screen_Sed * this)
    //         004a8758     TEST       byte ptr [ESP + param_1],0x1
    //         004a875d     JZ         LAB_004a8768
    //         004a875f     PUSH       ESI
    //         004a8760     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a8765     ADD        ESP,0x4
    //                               LAB_004a8768                                                 XREF[1]:     004a875d(j)  
    //         004a8768     MOV        EAX,ESI
    //         004a876a     POP        ESI
    //         004a876b     RET        0x4
}

