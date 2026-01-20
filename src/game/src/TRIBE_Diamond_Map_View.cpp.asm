// Auto-generated scaffold unit: TRIBE_Diamond_Map_View.cpp.asm
#include "../include/common.h"

// Offset: 0x0052CA00
void* TRIBE_Diamond_Map_View::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Diamond_Map_View::`scalar deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Diamond_Map_Vie
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Diamond_    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0052ca08(R)  
    //                               ??_ETRIBE_Diamond_Map_View@@UAEPAXI@Z                        XREF[1]:     00577350(*)  
    //                               ??_GTRIBE_Diamond_Map_View@@UAEPAXI@Z
    //                               TRIBE_Diamond_Map_View::`scalar_deleting_destructor'
    //         0052ca00     PUSH       ESI
    //         0052ca01     MOV        ESI,this
    //         0052ca03     CALL       TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View  void ~TRIBE_Diamond_Map_View(TRIBE_Diamond_Ma
    //         0052ca08     TEST       byte ptr [ESP + param_1],0x1
    //         0052ca0d     JZ         LAB_0052ca18
    //         0052ca0f     PUSH       ESI
    //         0052ca10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0052ca15     ADD        ESP,0x4
    //                               LAB_0052ca18                                                 XREF[1]:     0052ca0d(j)  
    //         0052ca18     MOV        EAX,ESI
    //         0052ca1a     POP        ESI
    //         0052ca1b     RET        0x4
}

