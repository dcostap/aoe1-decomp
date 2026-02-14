// Auto-generated scaffold unit: Time_Line_Panel.asm
#include "../include/common.h"

// Offset: 0x0051E770
void* Time_Line_Panel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall Time_Line_Panel::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(Time_Line_Panel * thi
    //              void *            EAX:4          <RETURN>
    //              Time_Line_Pane    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0051e778(R)  
    //                               ??_ETime_Line_Panel@@UAEPAXI@Z                               XREF[1]:     00576f88(*)  
    //                               ??_GTime_Line_Panel@@UAEPAXI@Z
    //                               Time_Line_Panel::`scalar_deleting_destructor'
    //         0051e770     PUSH       ESI
    //         0051e771     MOV        ESI,this
    //         0051e773     CALL       Time_Line_Panel::~Time_Line_Panel                void ~Time_Line_Panel(Time_Line_Panel * this)
    //         0051e778     TEST       byte ptr [ESP + param_1],0x1
    //         0051e77d     JZ         LAB_0051e788
    //         0051e77f     PUSH       ESI
    //         0051e780     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051e785     ADD        ESP,0x4
    //                               LAB_0051e788                                                 XREF[1]:     0051e77d(j)  
    //         0051e788     MOV        EAX,ESI
    //         0051e78a     POP        ESI
    //         0051e78b     RET        0x4
}

