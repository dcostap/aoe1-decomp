// Auto-generated scaffold unit: TRIBE_Screen_Main_Menu.asm
#include "../include/common.h"

// Offset: 0x0049EBE0
void* TRIBE_Screen_Main_Menu::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Main_Menu::`scalar deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Screen_Main_Men
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_M    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0049ebe8(R)  
    //                               ??_ETRIBE_Screen_Main_Menu@@UAEPAXI@Z                        XREF[1]:     00572f50(*)  
    //                               ??_GTRIBE_Screen_Main_Menu@@UAEPAXI@Z
    //                               TRIBE_Screen_Main_Menu::`scalar_deleting_destructor'
    //         0049ebe0     PUSH       ESI
    //         0049ebe1     MOV        ESI,this
    //         0049ebe3     CALL       TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu  void ~TRIBE_Screen_Main_Menu(TRIBE_Screen_Mai
    //         0049ebe8     TEST       byte ptr [ESP + param_1],0x1
    //         0049ebed     JZ         LAB_0049ebf8
    //         0049ebef     PUSH       ESI
    //         0049ebf0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0049ebf5     ADD        ESP,0x4
    //                               LAB_0049ebf8                                                 XREF[1]:     0049ebed(j)  
    //         0049ebf8     MOV        EAX,ESI
    //         0049ebfa     POP        ESI
    //         0049ebfb     RET        0x4
}

