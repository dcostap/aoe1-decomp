// Auto-generated scaffold unit: TRIBE_Command.cpp.asm
#include "../include/common.h"

// Offset: 0x00509740
void* TRIBE_Command::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Command::`vector deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Command * this,
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Command *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00509748(R)  
    //                               ??_GTRIBE_Command@@UAEPAXI@Z                                 XREF[1]:     0057655c(*)  
    //                               ??_ETRIBE_Command@@UAEPAXI@Z
    //                               TRIBE_Command::`vector_deleting_destructor'
    //         00509740     PUSH       ESI
    //         00509741     MOV        ESI,this
    //         00509743     CALL       TRIBE_Command::~TRIBE_Command                    void ~TRIBE_Command(TRIBE_Command * this)
    //         00509748     TEST       byte ptr [ESP + param_1],0x1
    //         0050974d     JZ         LAB_00509758
    //         0050974f     PUSH       ESI
    //         00509750     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00509755     ADD        ESP,0x4
    //                               LAB_00509758                                                 XREF[1]:     0050974d(j)  
    //         00509758     MOV        EAX,ESI
    //         0050975a     POP        ESI
    //         0050975b     RET        0x4
}

