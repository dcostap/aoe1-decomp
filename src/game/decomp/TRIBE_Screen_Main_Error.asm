// Auto-generated scaffold unit: TRIBE_Screen_Main_Error.asm
#include "../include/common.h"

// Offset: 0x0049F220
void* TRIBE_Screen_Main_Error::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Main_Error::`vector deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Main_Err
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_M    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0049f228(R)  
    //                               ??_GTRIBE_Screen_Main_Error@@UAEPAXI@Z                       XREF[1]:     00573078(*)  
    //                               ??_ETRIBE_Screen_Main_Error@@UAEPAXI@Z
    //                               TRIBE_Screen_Main_Error::`vector_deleting_destructor'
    //         0049f220     PUSH       ESI
    //         0049f221     MOV        ESI,this
    //         0049f223     CALL       TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Er   void ~TRIBE_Screen_Main_Error(TRIBE_Screen_Ma
    //         0049f228     TEST       byte ptr [ESP + param_1],0x1
    //         0049f22d     JZ         LAB_0049f238
    //         0049f22f     PUSH       ESI
    //         0049f230     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0049f235     ADD        ESP,0x4
    //                               LAB_0049f238                                                 XREF[1]:     0049f22d(j)  
    //         0049f238     MOV        EAX,ESI
    //         0049f23a     POP        ESI
    //         0049f23b     RET        0x4
}

