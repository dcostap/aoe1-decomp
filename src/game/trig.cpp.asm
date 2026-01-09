#include "common.h"
#include "trig.h"

TRIGONOMETRY::TRIGONOMETRY() {
    /* TODO: Stub */
    //                              undefined __thiscall TRIGONOMETRY(TRIGONOMETRY * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0052a739(W), 0052a743(R), 0052a7ad(W), 0052a7bb(W), 
    //                                                                                     0052a7bf(R), 0052a826(W)  
    //              int               Stack[-0x8]:4  i
    //                               ??0TRIGONOMETRY@@QAE@XZ                                      XREF[1]:     $E1:0052a985(c)  
    //                               TRIGONOMETRY::TRIGONOMETRY
    //                              trig.cpp:11 (5)
    //         0052a730     PUSH       this
    //         0052a731     PUSH       ESI
    //         0052a732     PUSH       EDI
    //         0052a733     MOV        EAX,this
    //                              trig.cpp:12 (14)
    //         0052a735     XOR        EDI,EDI
    //         0052a737     XOR        EDX,EDX
    //         0052a739     MOV        dword ptr [ESP + local_4],EDX
    //         0052a73d     LEA        ESI,[EAX + 0x8000]
    //                               LAB_0052a743                                                 XREF[1]:     0052a7b1(j)  
    //                              trig.cpp:14 (4)
    //         0052a743     FILD       dword ptr [ESP + local_4]
    //                              trig.cpp:20 (56)
    //         0052a747     CMP        EDX,0x400
    //         0052a74d     FMUL       double ptr [DAT_005772f0]                        = 33h    3
    //         0052a753     FLD        ST0
    //         0052a755     FLD        ST1
    //         0052a757     FXCH
    //         0052a759     FSIN
    //         0052a75b     FXCH
    //         0052a75d     FCOS
    //         0052a75f     FXCH
    //         0052a761     FSTP       float ptr [ESI + 0xffff8000]
    //         0052a767     FSTP       float ptr [ESI + 0xffffc000]
    //         0052a76d     JZ         LAB_0052a781
    //         0052a76f     CMP        EDX,0xc00
    //         0052a775     JZ         LAB_0052a781
    //         0052a777     FLD        ST0
    //         0052a779     FPTAN
    //         0052a77b     FSTP       ST0
    //         0052a77d     FSTP       float ptr [ESI]
    //                              trig.cpp:21 (4)
    //         0052a77f     JMP        LAB_0052a783
    //                               LAB_0052a781                                                 XREF[2]:     0052a76d(j), 0052a775(j)  
    //         0052a781     MOV        dword ptr [ESI],EDI
    //                               LAB_0052a783                                                 XREF[1]:     0052a77f(j)  
    //                              trig.cpp:22 (22)
    //         0052a783     CMP        EDX,EDI
    //         0052a785     JZ         LAB_0052a79b
    //         0052a787     CMP        EDX,0x800
    //         0052a78d     JZ         LAB_0052a79b
    //         0052a78f     FLD1
    //         0052a791     FPATAN
    //         0052a793     FSTP       float ptr [ESI + 0x4000]
    //                              trig.cpp:23 (2)
    //         0052a799     JMP        LAB_0052a7a3
    //                               LAB_0052a79b                                                 XREF[2]:     0052a785(j), 0052a78d(j)  
    //                              trig.cpp:20 (2)
    //         0052a79b     FSTP       ST0
    //                              trig.cpp:23 (22)
    //         0052a79d     MOV        dword ptr [ESI + 0x4000],EDI
    //                               LAB_0052a7a3                                                 XREF[1]:     0052a799(j)  
    //         0052a7a3     INC        EDX
    //         0052a7a4     ADD        ESI,0x4
    //         0052a7a7     CMP        EDX,0x1000
    //         0052a7ad     MOV        dword ptr [ESP + local_4],EDX
    //         0052a7b1     JL         LAB_0052a743
    //                              trig.cpp:25 (2)
    //         0052a7b3     XOR        EDX,EDX
    //                              trig.cpp:35 (51)
    //         0052a7b5     LEA        ESI,[EAX + 0x10b40]
    //         0052a7bb     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_0052a7bf                                                 XREF[1]:     0052a82a(j)  
    //         0052a7bf     FILD       dword ptr [ESP + local_4]
    //         0052a7c3     CMP        EDX,0x5a
    //         0052a7c6     FMUL       double ptr [DAT_005772f8]                        = 11h
    //         0052a7cc     FLD        ST0
    //         0052a7ce     FLD        ST1
    //         0052a7d0     FXCH
    //         0052a7d2     FSIN
    //         0052a7d4     FXCH
    //         0052a7d6     FCOS
    //         0052a7d8     FXCH
    //         0052a7da     FSTP       float ptr [ESI + 0xfffff4c0]
    //         0052a7e0     FSTP       float ptr [ESI + 0xfffffa60]
    //         0052a7e6     JZ         LAB_0052a7fa
    //                              trig.cpp:30 (16)
    //         0052a7e8     CMP        EDX,0x10e
    //         0052a7ee     JZ         LAB_0052a7fa
    //         0052a7f0     FLD        ST0
    //         0052a7f2     FPTAN
    //         0052a7f4     FSTP       ST0
    //         0052a7f6     FSTP       float ptr [ESI]
    //                              trig.cpp:31 (4)
    //         0052a7f8     JMP        LAB_0052a7fc
    //                               LAB_0052a7fa                                                 XREF[2]:     0052a7e6(j), 0052a7ee(j)  
    //         0052a7fa     MOV        dword ptr [ESI],EDI
    //                               LAB_0052a7fc                                                 XREF[1]:     0052a7f8(j)  
    //                              trig.cpp:32 (22)
    //         0052a7fc     CMP        EDX,EDI
    //         0052a7fe     JZ         LAB_0052a814
    //         0052a800     CMP        EDX,0xb4
    //         0052a806     JZ         LAB_0052a814
    //         0052a808     FLD1
    //         0052a80a     FPATAN
    //         0052a80c     FSTP       float ptr [ESI + 0x5a0]
    //                              trig.cpp:33 (2)
    //         0052a812     JMP        LAB_0052a81c
    //                               LAB_0052a814                                                 XREF[2]:     0052a7fe(j), 0052a806(j)  
    //                              trig.cpp:30 (2)
    //         0052a814     FSTP       ST0
    //                              trig.cpp:33 (22)
    //         0052a816     MOV        dword ptr [ESI + 0x5a0],EDI
    //                               LAB_0052a81c                                                 XREF[1]:     0052a812(j)  
    //         0052a81c     INC        EDX
    //         0052a81d     ADD        ESI,0x4
    //         0052a820     CMP        EDX,0x168
    //         0052a826     MOV        dword ptr [ESP + local_4],EDX
    //         0052a82a     JL         LAB_0052a7bf
    //                              trig.cpp:35 (4)
    //         0052a82c     POP        EDI
    //         0052a82d     POP        ESI
    //         0052a82e     POP        this
    //         0052a82f     RET
}

int TRIGONOMETRY::RestrictAngle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall RestrictAngle(TRIGONOMETRY * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a830(R)  
    //                               ?RestrictAngle@TRIGONOMETRY@@AAEHH@Z                         XREF[4]:     sine:0052a878(c), 
    //                               TRIGONOMETRY::RestrictAngle                                               cosine:0052a898(c), 
    //                                                                                                         tangent:0052a8b8(c), 
    //                                                                                                         atangent:0052a8d8(c)  
    //                              trig.cpp:37 (22)
    //         0052a830     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a834     CDQ
    //         0052a835     XOR        EAX,EDX
    //         0052a837     SUB        EAX,EDX
    //         0052a839     AND        EAX,0xfff
    //         0052a83e     XOR        EAX,EDX
    //         0052a840     SUB        EAX,EDX
    //         0052a842     JNS        LAB_0052a846
    //         0052a844     NEG        EAX
    //                               LAB_0052a846                                                 XREF[1]:     0052a842(j)  
    //                              trig.cpp:40 (3)
    //         0052a846     RET        0x4
    //         0052a849     ??         90h
    //         0052a84a     NOP
    //         0052a84b     NOP
    //         0052a84c     NOP
    //         0052a84d     NOP
    //         0052a84e     NOP
    //         0052a84f     NOP
    return 0;
}

int TRIGONOMETRY::RestrictAngle360(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall RestrictAngle360(TRIGONOMETRY * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a850(R)  
    //                               ?RestrictAngle360@TRIGONOMETRY@@AAEHH@Z                      XREF[4]:     sin360:0052a8f8(c), 
    //                               TRIGONOMETRY::RestrictAngle360                                            cos360:0052a918(c), 
    //                                                                                                         tan360:0052a938(c), 
    //                                                                                                         atan360:0052a958(c)  
    //                              trig.cpp:43 (20)
    //         0052a850     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a854     MOV        this,0x168
    //         0052a859     CDQ
    //         0052a85a     IDIV       this
    //         0052a85c     MOV        EAX,EDX
    //         0052a85e     TEST       EAX,EAX
    //         0052a860     JGE        LAB_0052a864
    //         0052a862     NEG        EAX
    //                               LAB_0052a864                                                 XREF[1]:     0052a860(j)  
    //                              trig.cpp:46 (3)
    //         0052a864     RET        0x4
    //         0052a867     ??         90h
    //         0052a868     NOP
    //         0052a869     NOP
    //         0052a86a     NOP
    //         0052a86b     NOP
    //         0052a86c     NOP
    //         0052a86d     NOP
    //         0052a86e     NOP
    //         0052a86f     NOP
    return 0;
}

float TRIGONOMETRY::sine(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall sine(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a870(R)  
    //                               ?sine@TRIGONOMETRY@@QAEMH@Z
    //                               TRIGONOMETRY::sine
    //                              trig.cpp:48 (20)
    //         0052a870     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a874     PUSH       ESI
    //         0052a875     MOV        ESI,this
    //         0052a877     PUSH       EAX
    //         0052a878     CALL       TRIGONOMETRY::RestrictAngle                      int RestrictAngle(TRIGONOMETRY * this, int pa
    //         0052a87d     FLD        float ptr [ESI + EAX*0x4]
    //         0052a880     POP        ESI
    //         0052a881     RET        0x4
    //         0052a884     ??         90h
    //         0052a885     NOP
    //         0052a886     NOP
    //         0052a887     NOP
    //         0052a888     NOP
    //         0052a889     NOP
    //         0052a88a     NOP
    //         0052a88b     NOP
    //         0052a88c     NOP
    //         0052a88d     NOP
    //         0052a88e     NOP
    //         0052a88f     NOP
    return 0;
}

float TRIGONOMETRY::cosine(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall cosine(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a890(R)  
    //                               ?cosine@TRIGONOMETRY@@QAEMH@Z
    //                               TRIGONOMETRY::cosine
    //                              trig.cpp:49 (24)
    //         0052a890     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a894     PUSH       ESI
    //         0052a895     MOV        ESI,this
    //         0052a897     PUSH       EAX
    //         0052a898     CALL       TRIGONOMETRY::RestrictAngle                      int RestrictAngle(TRIGONOMETRY * this, int pa
    //         0052a89d     FLD        float ptr [ESI + EAX*0x4 + 0x4000]
    //         0052a8a4     POP        ESI
    //         0052a8a5     RET        0x4
    //         0052a8a8     ??         90h
    //         0052a8a9     NOP
    //         0052a8aa     NOP
    //         0052a8ab     NOP
    //         0052a8ac     NOP
    //         0052a8ad     NOP
    //         0052a8ae     NOP
    //         0052a8af     NOP
    return 0;
}

float TRIGONOMETRY::tangent(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall tangent(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a8b0(R)  
    //                               ?tangent@TRIGONOMETRY@@QAEMH@Z
    //                               TRIGONOMETRY::tangent
    //                              trig.cpp:50 (24)
    //         0052a8b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a8b4     PUSH       ESI
    //         0052a8b5     MOV        ESI,this
    //         0052a8b7     PUSH       EAX
    //         0052a8b8     CALL       TRIGONOMETRY::RestrictAngle                      int RestrictAngle(TRIGONOMETRY * this, int pa
    //         0052a8bd     FLD        float ptr [ESI + EAX*0x4 + 0x8000]
    //         0052a8c4     POP        ESI
    //         0052a8c5     RET        0x4
    //         0052a8c8     ??         90h
    //         0052a8c9     NOP
    //         0052a8ca     NOP
    //         0052a8cb     NOP
    //         0052a8cc     NOP
    //         0052a8cd     NOP
    //         0052a8ce     NOP
    //         0052a8cf     NOP
    return 0;
}

float TRIGONOMETRY::atangent(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall atangent(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a8d0(R)  
    //                               ?atangent@TRIGONOMETRY@@QAEMH@Z
    //                               TRIGONOMETRY::atangent
    //                              trig.cpp:51 (24)
    //         0052a8d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a8d4     PUSH       ESI
    //         0052a8d5     MOV        ESI,this
    //         0052a8d7     PUSH       EAX
    //         0052a8d8     CALL       TRIGONOMETRY::RestrictAngle                      int RestrictAngle(TRIGONOMETRY * this, int pa
    //         0052a8dd     FLD        float ptr [ESI + EAX*0x4 + 0xc000]
    //         0052a8e4     POP        ESI
    //         0052a8e5     RET        0x4
    //         0052a8e8     ??         90h
    //         0052a8e9     NOP
    //         0052a8ea     NOP
    //         0052a8eb     NOP
    //         0052a8ec     NOP
    //         0052a8ed     NOP
    //         0052a8ee     NOP
    //         0052a8ef     NOP
    return 0;
}

float TRIGONOMETRY::sin360(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall sin360(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a8f0(R)  
    //                               ?sin360@TRIGONOMETRY@@QAEMH@Z                                XREF[2]:     AddingCircle:0044bfe3(c), 
    //                               TRIGONOMETRY::sin360                                                      AddingCircle:0044c0af(c)  
    //                              trig.cpp:53 (24)
    //         0052a8f0     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a8f4     PUSH       ESI
    //         0052a8f5     MOV        ESI,this
    //         0052a8f7     PUSH       EAX
    //         0052a8f8     CALL       TRIGONOMETRY::RestrictAngle360                   int RestrictAngle360(TRIGONOMETRY * this, int
    //         0052a8fd     FLD        float ptr [ESI + EAX*0x4 + 0x10000]
    //         0052a904     POP        ESI
    //         0052a905     RET        0x4
    //         0052a908     ??         90h
    //         0052a909     NOP
    //         0052a90a     NOP
    //         0052a90b     NOP
    //         0052a90c     NOP
    //         0052a90d     NOP
    //         0052a90e     NOP
    //         0052a90f     NOP
    return 0;
}

float TRIGONOMETRY::cos360(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall cos360(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a910(R)  
    //                               ?cos360@TRIGONOMETRY@@QAEMH@Z                                XREF[2]:     AddingCircle:0044bff6(c), 
    //                               TRIGONOMETRY::cos360                                                      AddingCircle:0044c0f6(c)  
    //                              trig.cpp:54 (24)
    //         0052a910     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a914     PUSH       ESI
    //         0052a915     MOV        ESI,this
    //         0052a917     PUSH       EAX
    //         0052a918     CALL       TRIGONOMETRY::RestrictAngle360                   int RestrictAngle360(TRIGONOMETRY * this, int
    //         0052a91d     FLD        float ptr [ESI + EAX*0x4 + 0x105a0]
    //         0052a924     POP        ESI
    //         0052a925     RET        0x4
    //         0052a928     ??         90h
    //         0052a929     NOP
    //         0052a92a     NOP
    //         0052a92b     NOP
    //         0052a92c     NOP
    //         0052a92d     NOP
    //         0052a92e     NOP
    //         0052a92f     NOP
    return 0;
}

float TRIGONOMETRY::tan360(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall tan360(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a930(R)  
    //                               ?tan360@TRIGONOMETRY@@QAEMH@Z
    //                               TRIGONOMETRY::tan360
    //                              trig.cpp:55 (24)
    //         0052a930     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a934     PUSH       ESI
    //         0052a935     MOV        ESI,this
    //         0052a937     PUSH       EAX
    //         0052a938     CALL       TRIGONOMETRY::RestrictAngle360                   int RestrictAngle360(TRIGONOMETRY * this, int
    //         0052a93d     FLD        float ptr [ESI + EAX*0x4 + 0x10b40]
    //         0052a944     POP        ESI
    //         0052a945     RET        0x4
    //         0052a948     ??         90h
    //         0052a949     NOP
    //         0052a94a     NOP
    //         0052a94b     NOP
    //         0052a94c     NOP
    //         0052a94d     NOP
    //         0052a94e     NOP
    //         0052a94f     NOP
    return 0;
}

float TRIGONOMETRY::atan360(int param_1) {
    /* TODO: Stub */
    //                              float __thiscall atan360(TRIGONOMETRY * this, int param_1)
    //              float             ST0:10         <RETURN>
    //              TRIGONOMETRY *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0052a950(R)  
    //                               ?atan360@TRIGONOMETRY@@QAEMH@Z
    //                               TRIGONOMETRY::atan360
    //                              trig.cpp:56 (24)
    //         0052a950     MOV        EAX,dword ptr [ESP + param_1]
    //         0052a954     PUSH       ESI
    //         0052a955     MOV        ESI,this
    //         0052a957     PUSH       EAX
    //         0052a958     CALL       TRIGONOMETRY::RestrictAngle360                   int RestrictAngle360(TRIGONOMETRY * this, int
    //         0052a95d     FLD        float ptr [ESI + EAX*0x4 + 0x110e0]
    //         0052a964     POP        ESI
    //         0052a965     RET        0x4
    //         0052a968     ??         90h
    //         0052a969     NOP
    //         0052a96a     NOP
    //         0052a96b     NOP
    //         0052a96c     NOP
    //         0052a96d     NOP
    //         0052a96e     NOP
    //         0052a96f     NOP
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk undefined $E2()
    //                                Thunked-Function: $E1
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E2
    //         0052a970     JMP        $E1
    //         0052a975     ??         90h
    //         0052a976     NOP
    //         0052a977     NOP
    //         0052a978     NOP
    //         0052a979     NOP
    //         0052a97a     NOP
    //         0052a97b     NOP
    //         0052a97c     NOP
    //         0052a97d     NOP
    //         0052a97e     NOP
    //         0052a97f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E1                                                          XREF[1]:     $E2:0052a970(T), $E2:0052a970(j)  
    //                              trig.cpp:58 (10)
    //         0052a980     MOV        ECX,trig
    //         0052a985     JMP        TRIGONOMETRY::TRIGONOMETRY                       undefined TRIGONOMETRY(TRIGONOMETRY * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0052a98a     ??         90h
    //         0052a98b     NOP
    //         0052a98c     NOP
    //         0052a98d     NOP
    //         0052a98e     NOP
    //         0052a98f     NOP
    return 0;
}

