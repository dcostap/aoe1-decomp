// Auto-generated scaffold unit: TRIBE_Screen_Sed_Menu.asm
#include "../include/common.h"

// Offset: 0x004B30F0
void* TRIBE_Screen_Sed_Menu::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Sed_Menu::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Screen_Sed_Menu
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b30f8(R)  
    //                               ??_ETRIBE_Screen_Sed_Menu@@UAEPAXI@Z                         XREF[1]:     00573b00(*)  
    //                               ??_GTRIBE_Screen_Sed_Menu@@UAEPAXI@Z
    //                               TRIBE_Screen_Sed_Menu::`scalar_deleting_destructor'
    //         004b30f0     PUSH       ESI
    //         004b30f1     MOV        ESI,this
    //         004b30f3     CALL       TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu    void ~TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_
    //         004b30f8     TEST       byte ptr [ESP + param_1],0x1
    //         004b30fd     JZ         LAB_004b3108
    //         004b30ff     PUSH       ESI
    //         004b3100     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b3105     ADD        ESP,0x4
    //                               LAB_004b3108                                                 XREF[1]:     004b30fd(j)  
    //         004b3108     MOV        EAX,ESI
    //         004b310a     POP        ESI
    //         004b310b     RET        0x4
}

