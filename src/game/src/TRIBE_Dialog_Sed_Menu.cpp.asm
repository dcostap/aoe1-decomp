// Auto-generated scaffold unit: TRIBE_Dialog_Sed_Menu.cpp.asm
#include "../include/common.h"

// Offset: 0x00440340
void* TRIBE_Dialog_Sed_Menu::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Dialog_Sed_Menu::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Dialog_Sed_Menu
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Dialog_S    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00440348(R)  
    //                               ??_ETRIBE_Dialog_Sed_Menu@@UAEPAXI@Z                         XREF[1]:     0056fe90(*)  
    //                               ??_GTRIBE_Dialog_Sed_Menu@@UAEPAXI@Z
    //                               TRIBE_Dialog_Sed_Menu::`scalar_deleting_destructor'
    //         00440340     PUSH       ESI
    //         00440341     MOV        ESI,this
    //         00440343     CALL       TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu    void ~TRIBE_Dialog_Sed_Menu(TRIBE_Dialog_Sed_
    //         00440348     TEST       byte ptr [ESP + param_1],0x1
    //         0044034d     JZ         LAB_00440358
    //         0044034f     PUSH       ESI
    //         00440350     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00440355     ADD        ESP,0x4
    //                               LAB_00440358                                                 XREF[1]:     0044034d(j)  
    //         00440358     MOV        EAX,ESI
    //         0044035a     POP        ESI
    //         0044035b     RET        0x4
}

