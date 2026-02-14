// Auto-generated scaffold unit: RGE_Game_World.asm
#include "../include/common.h"

// Offset: 0x00540A20
void* RGE_Game_World::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Game_World::`scalar deleting destructor'(unsigned int)          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Game_World * this
    //              void *            EAX:4          <RETURN>
    //              RGE_Game_World    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00540a28(R)  
    //                               ??_ERGE_Game_World@@UAEPAXI@Z                                XREF[1]:     005779b0(*)  
    //                               ??_GRGE_Game_World@@UAEPAXI@Z
    //                               RGE_Game_World::`scalar_deleting_destructor'
    //         00540a20     PUSH       ESI
    //         00540a21     MOV        ESI,this
    //         00540a23     CALL       RGE_Game_World::~RGE_Game_World                  void ~RGE_Game_World(RGE_Game_World * this)
    //         00540a28     TEST       byte ptr [ESP + param_1],0x1
    //         00540a2d     JZ         LAB_00540a38
    //         00540a2f     PUSH       ESI
    //         00540a30     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00540a35     ADD        ESP,0x4
    //                               LAB_00540a38                                                 XREF[1]:     00540a2d(j)  
    //         00540a38     MOV        EAX,ESI
    //         00540a3a     POP        ESI
    //         00540a3b     RET        0x4
}

