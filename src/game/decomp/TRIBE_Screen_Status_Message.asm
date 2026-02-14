// Auto-generated scaffold unit: TRIBE_Screen_Status_Message.asm
#include "../include/common.h"

// Offset: 0x004B7310
void* TRIBE_Screen_Status_Message::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Status_Message::`vector deleting destructor'(unsign... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Status_M
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b7318(R)  
    //                               ??_GTRIBE_Screen_Status_Message@@UAEPAXI@Z                   XREF[1]:     005740c8(*)  
    //                               ??_ETRIBE_Screen_Status_Message@@UAEPAXI@Z
    //                               TRIBE_Screen_Status_Message::`vector_deleting_destructor'
    //         004b7310     PUSH       ESI
    //         004b7311     MOV        ESI,this
    //         004b7313     CALL       TRIBE_Screen_Status_Message::~TRIBE_Screen_Sta   void ~TRIBE_Screen_Status_Message(TRIBE_Scree
    //         004b7318     TEST       byte ptr [ESP + param_1],0x1
    //         004b731d     JZ         LAB_004b7328
    //         004b731f     PUSH       ESI
    //         004b7320     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b7325     ADD        ESP,0x4
    //                               LAB_004b7328                                                 XREF[1]:     004b731d(j)  
    //         004b7328     MOV        EAX,ESI
    //         004b732a     POP        ESI
    //         004b732b     RET        0x4
}

