// Auto-generated scaffold unit: RGE_Command.cpp.asm
#include "../include/common.h"

// Offset: 0x00433D70
void* RGE_Command::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Command::`vector deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Command * this, u
    //              void *            EAX:4          <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00433d78(R)  
    //                               ??_GRGE_Command@@UAEPAXI@Z                                   XREF[1]:     0056f4c4(*)  
    //                               ??_ERGE_Command@@UAEPAXI@Z
    //                               RGE_Command::`vector_deleting_destructor'
    //         00433d70     PUSH       ESI
    //         00433d71     MOV        ESI,this
    //         00433d73     CALL       RGE_Command::~RGE_Command                        void ~RGE_Command(RGE_Command * this)
    //         00433d78     TEST       byte ptr [ESP + param_1],0x1
    //         00433d7d     JZ         LAB_00433d88
    //         00433d7f     PUSH       ESI
    //         00433d80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00433d85     ADD        ESP,0x4
    //                               LAB_00433d88                                                 XREF[1]:     00433d7d(j)  
    //         00433d88     MOV        EAX,ESI
    //         00433d8a     POP        ESI
    //         00433d8b     RET        0x4
}

