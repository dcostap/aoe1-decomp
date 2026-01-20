// Auto-generated scaffold unit: TRIBE_Campaign_Editor_Screen.cpp.asm
#include "../include/common.h"

// Offset: 0x0048FA20
void* TRIBE_Campaign_Editor_Screen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Campaign_Editor_Screen::`vector deleting destructor'(unsig... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Campaign_Editor
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Campaign    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0048fa28(R)  
    //                               ??_GTRIBE_Campaign_Editor_Screen@@UAEPAXI@Z                  XREF[1]:     005722a8(*)  
    //                               ??_ETRIBE_Campaign_Editor_Screen@@UAEPAXI@Z
    //                               TRIBE_Campaign_Editor_Screen::`vector_deleting_destructor'
    //         0048fa20     PUSH       ESI
    //         0048fa21     MOV        ESI,this
    //         0048fa23     CALL       TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_   void ~TRIBE_Campaign_Editor_Screen(TRIBE_Camp
    //         0048fa28     TEST       byte ptr [ESP + param_1],0x1
    //         0048fa2d     JZ         LAB_0048fa38
    //         0048fa2f     PUSH       ESI
    //         0048fa30     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048fa35     ADD        ESP,0x4
    //                               LAB_0048fa38                                                 XREF[1]:     0048fa2d(j)  
    //         0048fa38     MOV        EAX,ESI
    //         0048fa3a     POP        ESI
    //         0048fa3b     RET        0x4
}

