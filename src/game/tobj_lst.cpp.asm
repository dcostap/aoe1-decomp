#include "common.h"
#include "tobj_lst.h"

void TRIBE_Object_List::load(uchar param_1, int param_2, RGE_Game_World* param_3) {
    /* TODO: Stub */
    //                              void __thiscall load(TRIBE_Object_List * this, uchar param_1, int pa
    //              void              <VOID>         <RETURN>
    //              TRIBE_Object_L    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[3]:     00511b0e(R), 00511b4f(W), 00511b90(W)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     00511b26(R), 00511b63(R), 00511ba4(R)  
    //              RGE_Game_World    Stack[0xc]:4   param_3                   XREF[3]:     00511b21(R), 00511b5f(R), 00511ba0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00511b55(W), 00511b96(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00511b31(*), 00511b72(*), 00511bb3(*)  
    //                               ?load@TRIBE_Object_List@@MAEXEHPAVRGE_Game_World@@@Z         XREF[1]:     0057699c(*)  
    //                               TRIBE_Object_List::load
    //                              tobj_lst.cpp:24 (14)
    //         00511b00     MOV        EAX,FS:[0x0]
    //         00511b06     PUSH       -0x1
    //         00511b08     PUSH       FUN_00561116
    //         00511b0d     PUSH       EAX
    //                              tobj_lst.cpp:25 (19)
    //         00511b0e     MOV        EAX,dword ptr [ESP + param_1]
    //         00511b12     MOV        dword ptr FS:[0x0],ESP
    //         00511b19     CMP        AL,0x46
    //         00511b1b     JZ         LAB_00511b83
    //         00511b1d     CMP        AL,0x50
    //         00511b1f     JZ         LAB_00511b42
    //                              tobj_lst.cpp:34 (16)
    //         00511b21     MOV        EDX,dword ptr [ESP + param_3]
    //         00511b25     PUSH       EDX
    //         00511b26     MOV        EDX,dword ptr [ESP + param_2]
    //         00511b2a     PUSH       EDX
    //         00511b2b     PUSH       EAX
    //         00511b2c     CALL       RGE_Object_List::load                            void load(RGE_Object_List * this, uchar param
    //                              tobj_lst.cpp:37 (17)
    //         00511b31     MOV        this,dword ptr [ESP]=>local_c
    //         00511b35     MOV        dword ptr FS:[0x0],this
    //         00511b3c     ADD        ESP,0xc
    //         00511b3f     RET        0xc
    //                               LAB_00511b42                                                 XREF[1]:     00511b1f(j)  
    //                              tobj_lst.cpp:31 (48)
    //         00511b42     PUSH       0x204
    //         00511b47     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00511b4c     ADD        ESP,0x4
    //         00511b4f     MOV        dword ptr [ESP + param_1],EAX
    //         00511b53     TEST       EAX,EAX
    //         00511b55     MOV        dword ptr [ESP + local_4],0x1
    //         00511b5d     JZ         LAB_00511bb3
    //         00511b5f     MOV        this,dword ptr [ESP + param_3]
    //         00511b63     MOV        EDX,dword ptr [ESP + param_2]
    //         00511b67     PUSH       0x1
    //         00511b69     PUSH       this
    //         00511b6a     PUSH       EDX
    //         00511b6b     MOV        this,EAX
    //         00511b6d     CALL       TRIBE_Building_Object::TRIBE_Building_Object     undefined TRIBE_Building_Object(TRIBE_Buildin
    //                              tobj_lst.cpp:37 (17)
    //         00511b72     MOV        this,dword ptr [ESP]=>local_c
    //         00511b76     MOV        dword ptr FS:[0x0],this
    //         00511b7d     ADD        ESP,0xc
    //         00511b80     RET        0xc
    //                               LAB_00511b83                                                 XREF[1]:     00511b1b(j)  
    //                              tobj_lst.cpp:28 (48)
    //         00511b83     PUSH       0x1c8
    //         00511b88     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00511b8d     ADD        ESP,0x4
    //         00511b90     MOV        dword ptr [ESP + param_1],EAX
    //         00511b94     TEST       EAX,EAX
    //         00511b96     MOV        dword ptr [ESP + local_4],0x0
    //         00511b9e     JZ         LAB_00511bb3
    //         00511ba0     MOV        this,dword ptr [ESP + param_3]
    //         00511ba4     MOV        EDX,dword ptr [ESP + param_2]
    //         00511ba8     PUSH       0x1
    //         00511baa     PUSH       this
    //         00511bab     PUSH       EDX
    //         00511bac     MOV        this,EAX
    //         00511bae     CALL       TRIBE_Combat_Object::TRIBE_Combat_Object         undefined TRIBE_Combat_Object(TRIBE_Combat_Ob
    //                               LAB_00511bb3                                                 XREF[2]:     00511b5d(j), 00511b9e(j)  
    //                              tobj_lst.cpp:37 (17)
    //         00511bb3     MOV        this,dword ptr [ESP]=>local_c
    //         00511bb7     MOV        dword ptr FS:[0x0],this
    //         00511bbe     ADD        ESP,0xc
    //         00511bc1     RET        0xc
    //         00511bc4     ??         90h
    //         00511bc5     NOP
    //         00511bc6     NOP
    //         00511bc7     NOP
    //         00511bc8     NOP
    //         00511bc9     NOP
    //         00511bca     NOP
    //         00511bcb     NOP
    //         00511bcc     NOP
    //         00511bcd     NOP
    //         00511bce     NOP
    //         00511bcf     NOP
    return;
}

