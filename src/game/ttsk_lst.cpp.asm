#include "common.h"
#include "ttsk_lst.h"

int TRIBE_Task_List::is_attack_task(RGE_Task* param_1) {
    /* TODO: Stub */
    //                              int __thiscall is_attack_task(TRIBE_Task_List * this, RGE_Task * par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Task_Lis    ECX:4 (auto)   this
    //              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     0052c8d0(R)  
    //                               ?is_attack_task@TRIBE_Task_List@@UAEHPAVRGE_Task@@@Z         XREF[1]:     00576788(*)  
    //                               TRIBE_Task_List::is_attack_task
    //                              ttsk_lst.cpp:299 (11)
    //         0052c8d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0052c8d4     CMP        word ptr [EAX + 0x6],0x68
    //         0052c8d9     JNZ        LAB_0052c8e3
    //                              ttsk_lst.cpp:301 (5)
    //         0052c8db     MOV        EAX,0x1
    //                              ttsk_lst.cpp:304 (3)
    //         0052c8e0     RET        0x4
    //                               LAB_0052c8e3                                                 XREF[1]:     0052c8d9(j)  
    //                              ttsk_lst.cpp:303 (6)
    //         0052c8e3     PUSH       EAX
    //         0052c8e4     CALL       RGE_Task_List::is_attack_task                    int is_attack_task(RGE_Task_List * this, RGE_
    //                              ttsk_lst.cpp:304 (3)
    //         0052c8e9     RET        0x4
    //         0052c8ec     ??         90h
    //         0052c8ed     NOP
    //         0052c8ee     NOP
    //         0052c8ef     NOP
    //                              * public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *,int,long ... *
    //                              undefined __thiscall TRIBE_Victory_Conditions(TRIBE_Victory_Conditio
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Victory_    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0052c900(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0052c8f4(R)  
    //              long *            Stack[0xc]:4   param_3                   XREF[1]:     0052c8fb(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0052c8f0(R)  
    //                               ??0TRIBE_Victory_Conditions@@QAE@PAVRGE_Player@@HPAJE@Z      XREF[1]:     load_victory:005194d5(c)  
    //                               TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
    //                              tvictory.cpp:30 (36)
    //         0052c8f0     MOV        EAX,dword ptr [ESP + param_4]
    //         0052c8f4     MOV        EDX,dword ptr [ESP + param_2]
    //         0052c8f8     PUSH       ESI
    //         0052c8f9     MOV        ESI,this
    //         0052c8fb     MOV        this,dword ptr [ESP + param_3]
    //         0052c8ff     PUSH       EAX
    //         0052c900     MOV        EAX,dword ptr [ESP + param_1]
    //         0052c904     PUSH       this
    //         0052c905     PUSH       EDX
    //         0052c906     PUSH       EAX
    //         0052c907     MOV        this,ESI
    //         0052c909     CALL       RGE_Victory_Conditions::RGE_Victory_Conditions   undefined RGE_Victory_Conditions(RGE_Victory_
    //         0052c90e     MOV        dword ptr [ESI],TRIBE_Victory_Conditions::`vft   = 00531f30
    //                              tvictory.cpp:31 (6)
    //         0052c914     MOV        EAX,ESI
    //         0052c916     POP        ESI
    //         0052c917     RET        0x10
    //         0052c91a     ??         90h
    //         0052c91b     NOP
    //         0052c91c     NOP
    //         0052c91d     NOP
    //         0052c91e     NOP
    //         0052c91f     NOP
    return 0;
}

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

