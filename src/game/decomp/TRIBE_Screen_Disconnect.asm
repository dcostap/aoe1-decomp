// Auto-generated scaffold unit: TRIBE_Screen_Disconnect.asm
#include "../include/common.h"

// Offset: 0x004A6270
void* TRIBE_Screen_Disconnect::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Disconnect::`vector deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Disconne
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_D    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a6278(R)  
    //                               ??_GTRIBE_Screen_Disconnect@@UAEPAXI@Z                       XREF[1]:     00573518(*)  
    //                               ??_ETRIBE_Screen_Disconnect@@UAEPAXI@Z
    //                               TRIBE_Screen_Disconnect::`vector_deleting_destructor'
    //         004a6270     PUSH       ESI
    //         004a6271     MOV        ESI,this
    //         004a6273     CALL       TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconn   void ~TRIBE_Screen_Disconnect(TRIBE_Screen_Di
    //         004a6278     TEST       byte ptr [ESP + param_1],0x1
    //         004a627d     JZ         LAB_004a6288
    //         004a627f     PUSH       ESI
    //         004a6280     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a6285     ADD        ESP,0x4
    //                               LAB_004a6288                                                 XREF[1]:     004a627d(j)  
    //         004a6288     MOV        EAX,ESI
    //         004a628a     POP        ESI
    //         004a628b     RET        0x4
}

