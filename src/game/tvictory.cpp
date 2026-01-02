#include "../common.h"
#include "tvictory.h"

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Victory_Conditions(TRIBE_Victory_Conditio
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Victory_    ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0052c920(R)
//                               ??0TRIBE_Victory_Conditions@@QAE@PAVRGE_Player@@@Z           XREF[1]:     new_victory:00519536(c)
//                               TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
//                              tvictory.cpp:37 (19)
//         0052c920     MOV        EAX,dword ptr [ESP + param_1]
//         0052c924     PUSH       ESI
//         0052c925     MOV        ESI,this
//         0052c927     PUSH       EAX
//         0052c928     CALL       RGE_Victory_Conditions::RGE_Victory_Conditions   undefined RGE_Victory_Conditions(RGE_Victory_
//         0052c92d     MOV        dword ptr [ESI],TRIBE_Victory_Conditions::`vft   = 00531f30
//                              tvictory.cpp:38 (6)
//         0052c933     MOV        EAX,ESI
//         0052c935     POP        ESI
//         0052c936     RET        0x4
//         0052c939     ??         90h
//         0052c93a     NOP
//         0052c93b     NOP
//         0052c93c     NOP
//         0052c93d     NOP
//         0052c93e     NOP
//         0052c93f     NOP
}

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Victory_Conditions(TRIBE_Victory_Conditio
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Victory_    ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0052c920(R)
//                               ??0TRIBE_Victory_Conditions@@QAE@PAVRGE_Player@@@Z           XREF[1]:     new_victory:00519536(c)
//                               TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
//                              tvictory.cpp:37 (19)
//         0052c920     MOV        EAX,dword ptr [ESP + param_1]
//         0052c924     PUSH       ESI
//         0052c925     MOV        ESI,this
//         0052c927     PUSH       EAX
//         0052c928     CALL       RGE_Victory_Conditions::RGE_Victory_Conditions   undefined RGE_Victory_Conditions(RGE_Victory_
//         0052c92d     MOV        dword ptr [ESI],TRIBE_Victory_Conditions::`vft   = 00531f30
//                              tvictory.cpp:38 (6)
//         0052c933     MOV        EAX,ESI
//         0052c935     POP        ESI
//         0052c936     RET        0x4
//         0052c939     ??         90h
//         0052c93a     NOP
//         0052c93b     NOP
//         0052c93c     NOP
//         0052c93d     NOP
//         0052c93e     NOP
//         0052c93f     NOP
}

TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Victory_Conditions(TRIBE_Victory_Conditions *
//              void              <VOID>         <RETURN>
//              TRIBE_Victory_    ECX:4 (auto)   this
//                               ??1TRIBE_Victory_Conditions@@QAE@XZ
//                               TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions
//                              tvictory.cpp:43 (11)
//         0052c940     MOV        dword ptr [this->field0_0x0],TRIBE_Victory_Con   = 00531f30
//         0052c946     JMP        RGE_Victory_Conditions::~RGE_Victory_Conditions  void ~RGE_Victory_Conditions(RGE_Victory_Cond
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0052c94b     ??         90h
//         0052c94c     NOP
//         0052c94d     NOP
//         0052c94e     NOP
//         0052c94f     NOP
}

void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
//                              void __thiscall handle_condition(TRIBE_Victory_Conditions * this, RG
//              void              <VOID>         <RETURN>
//              TRIBE_Victory_    ECX:4 (auto)   this
//              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     0052c950(R)
//                               ?handle_condition@TRIBE_Victory_Conditions@@UAEXPAURGE_Vict  XREF[1]:     00577344(*)
//                               TRIBE_Victory_Conditions::handle_condition
//                              tvictory.cpp:49 (4)
//         0052c950     MOV        EAX,dword ptr [ESP + param_1]
//                              tvictory.cpp:57 (11)
//         0052c954     PUSH       EAX
//         0052c955     CMP        byte ptr [EAX],0x64
//         0052c958     JZ         LAB_0052c962
//         0052c95a     CALL       RGE_Victory_Conditions::handle_condition         void handle_condition(RGE_Victory_Conditions
//                              tvictory.cpp:59 (3)
//         0052c95f     RET        0x4
//                               LAB_0052c962                                                 XREF[1]:     0052c958(j)
//                              tvictory.cpp:53 (5)
//         0052c962     CALL       TRIBE_Victory_Conditions::handle_tech            void handle_tech(TRIBE_Victory_Conditions * t
//                              tvictory.cpp:59 (3)
//         0052c967     RET        0x4
//         0052c96a     ??         90h
//         0052c96b     NOP
//         0052c96c     NOP
//         0052c96d     NOP
//         0052c96e     NOP
//         0052c96f     NOP
    return;
}

void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
//                              void __thiscall handle_tech(TRIBE_Victory_Conditions * this, RGE_Vic
//              void              <VOID>         <RETURN>
//              TRIBE_Victory_    ECX:4 (auto)   this
//              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     0052c978(R)
//                               ?handle_tech@TRIBE_Victory_Conditions@@IAEXPAURGE_Victory_E  XREF[1]:     handle_condition:0052c962(c)
//                               TRIBE_Victory_Conditions::handle_tech
//                              tvictory.cpp:63 (19)
//         0052c970     MOV        EAX,dword ptr [ECX + this->field12_0xc]
//         0052c973     PUSH       ESI
//         0052c974     TEST       EAX,EAX
//         0052c976     JZ         LAB_0052c99d
//         0052c978     MOV        ESI,dword ptr [ESP + param_1]
//         0052c97c     MOV        this,byte ptr [ESI + 0x2e]
//         0052c97f     TEST       this,this
//         0052c981     JNZ        LAB_0052c99d
//                              tvictory.cpp:65 (22)
//         0052c983     MOV        this,word ptr [ESI + 0x20]
//         0052c987     PUSH       this
//         0052c988     MOV        this,dword ptr [EAX + 0x220]
//         0052c98e     CALL       TRIBE_Player_Tech::get_tech_state                short get_tech_state(TRIBE_Player_Tech * this
//         0052c993     CMP        AX,0x3
//         0052c997     JNZ        LAB_0052c99d
//                              tvictory.cpp:66 (4)
//         0052c999     MOV        byte ptr [ESI + 0x2e],0x2
//                               LAB_0052c99d                                                 XREF[3]:     0052c976(j), 0052c981(j),
//                                                                                                         0052c997(j)
//                              tvictory.cpp:67 (4)
//         0052c99d     POP        ESI
//         0052c99e     RET        0x4
//         0052c9a1     ??         90h
//         0052c9a2     NOP
//         0052c9a3     NOP
//         0052c9a4     NOP
//         0052c9a5     NOP
//         0052c9a6     NOP
//         0052c9a7     NOP
//         0052c9a8     NOP
//         0052c9a9     NOP
//         0052c9aa     NOP
//         0052c9ab     NOP
//         0052c9ac     NOP
//         0052c9ad     NOP
//         0052c9ae     NOP
//         0052c9af     NOP
    return;
}

uchar TRIBE_Victory_Conditions::add_tech(uchar param_1, long param_2) {
    /* TODO: Stub */
//                              uchar __thiscall add_tech(TRIBE_Victory_Conditions * this, uchar par
//              uchar             AL:1           <RETURN>
//              TRIBE_Victory_    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0052c9b0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0052c9c0(R)
//                               ?add_tech@TRIBE_Victory_Conditions@@QAEEEJ@Z                 XREF[1]:     Save_victory_conditions_into_playe
//                               TRIBE_Victory_Conditions::add_tech
//                              tvictory.cpp:71 (12)
//         0052c9b0     MOV        EAX,dword ptr [ESP + param_1]
//         0052c9b4     PUSH       0x0
//         0052c9b6     PUSH       EAX
//         0052c9b7     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
//                              tvictory.cpp:75 (4)
//         0052c9bc     TEST       EAX,EAX
//         0052c9be     JZ         LAB_0052c9cf
//                              tvictory.cpp:78 (10)
//         0052c9c0     MOV        this,dword ptr [ESP + param_2]
//         0052c9c4     MOV        byte ptr [EAX],0x64
//         0052c9c7     MOV        dword ptr [EAX + 0x20],this
//                              tvictory.cpp:79 (2)
//         0052c9ca     MOV        AL,0x1
//                              tvictory.cpp:83 (3)
//         0052c9cc     RET        0x8
//                               LAB_0052c9cf                                                 XREF[1]:     0052c9be(j)
//                              tvictory.cpp:82 (2)
//         0052c9cf     XOR        AL,AL
//                              tvictory.cpp:83 (3)
//         0052c9d1     RET        0x8
//         0052c9d4     ??         90h
//         0052c9d5     NOP
//         0052c9d6     NOP
//         0052c9d7     NOP
//         0052c9d8     NOP
//         0052c9d9     NOP
//         0052c9da     NOP
//         0052c9db     NOP
//         0052c9dc     NOP
//         0052c9dd     NOP
//         0052c9de     NOP
//         0052c9df     NOP
    return 0;
}

