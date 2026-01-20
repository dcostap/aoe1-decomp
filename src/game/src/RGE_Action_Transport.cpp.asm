// Auto-generated scaffold unit: RGE_Action_Transport.cpp.asm
#include "../include/common.h"

// Offset: 0x00406D90
void* RGE_Action_Transport::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Transport::`vector deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Transport 
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Tra    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00406d98(R)  
    //                               ??_GRGE_Action_Transport@@UAEPAXI@Z                          XREF[1]:     0056e650(*)  
    //                               ??_ERGE_Action_Transport@@UAEPAXI@Z
    //                               RGE_Action_Transport::`vector_deleting_destructor'
    //         00406d90     PUSH       ESI
    //         00406d91     MOV        ESI,this
    //         00406d93     CALL       RGE_Action_Transport::~RGE_Action_Transport      void ~RGE_Action_Transport(RGE_Action_Transpo
    //         00406d98     TEST       byte ptr [ESP + param_1],0x1
    //         00406d9d     JZ         LAB_00406da8
    //         00406d9f     PUSH       ESI
    //         00406da0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00406da5     ADD        ESP,0x4
    //                               LAB_00406da8                                                 XREF[1]:     00406d9d(j)  
    //         00406da8     MOV        EAX,ESI
    //         00406daa     POP        ESI
    //         00406dab     RET        0x4
}

