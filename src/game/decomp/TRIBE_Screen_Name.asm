// Auto-generated scaffold unit: TRIBE_Screen_Name.asm
#include "../include/common.h"

// Offset: 0x004A66C0
void* TRIBE_Screen_Name::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Name::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Name * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a66c8(R)  
    //                               ??_GTRIBE_Screen_Name@@UAEPAXI@Z                             XREF[1]:     00573640(*)  
    //                               ??_ETRIBE_Screen_Name@@UAEPAXI@Z
    //                               TRIBE_Screen_Name::`vector_deleting_destructor'
    //         004a66c0     PUSH       ESI
    //         004a66c1     MOV        ESI,this
    //         004a66c3     CALL       TRIBE_Screen_Name::~TRIBE_Screen_Name            void ~TRIBE_Screen_Name(TRIBE_Screen_Name * t
    //         004a66c8     TEST       byte ptr [ESP + param_1],0x1
    //         004a66cd     JZ         LAB_004a66d8
    //         004a66cf     PUSH       ESI
    //         004a66d0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a66d5     ADD        ESP,0x4
    //                               LAB_004a66d8                                                 XREF[1]:     004a66cd(j)  
    //         004a66d8     MOV        EAX,ESI
    //         004a66da     POP        ESI
    //         004a66db     RET        0x4
}

