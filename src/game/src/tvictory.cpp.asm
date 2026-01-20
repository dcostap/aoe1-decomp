// Auto-generated scaffold unit: tvictory.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/tvictory.cpp
#include "../include/common.h"

// Offset: 0x0052C8F0
undefined TRIBE_Victory_Conditions(TRIBE_Victory_Conditions* this_, RGE_Player* param_2, int param_3, long* param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *,int,long ... *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0052C920
undefined TRIBE_Victory_Conditions(TRIBE_Victory_Conditions* this_, RGE_Player* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *)             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0052C940
void TRIBE_Victory_Conditions(TRIBE_Victory_Conditions* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions(void)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Victory_Conditions(TRIBE_Victory_Conditions *
    //              void              <VOID>         <RETURN>
    //              TRIBE_Victory_    ECX:4 (auto)   this
    //                               ??1TRIBE_Victory_Conditions@@QAE@XZ
    //                               TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions
    //                              tvictory.cpp:43 (11)
    //         0052c940     MOV        dword ptr [this->field0_0x0],TRIBE_Victory_Con   = 00531f30
    //         0052c946     JMP        RGE_Victory_Conditions::~RGE_Victory_Conditions  void ~RGE_Victory_Conditions(RGE_Victory_Cond
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0052C950
void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Victory_Conditions::handle_condition(struct RGE_Victory_Entr... *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0052C970
void handle_tech(TRIBE_Victory_Conditions* this_, RGE_Victory_Entry* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TRIBE_Victory_Conditions::handle_tech(struct RGE_Victory_Entry *)          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0052C9B0
uchar add_tech(TRIBE_Victory_Conditions* this_, uchar param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Victory_Conditions::add_tech(unsigned char,long)               *
    //                              *********************************************************************************************************
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
}

