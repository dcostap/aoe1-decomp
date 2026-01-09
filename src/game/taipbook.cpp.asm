#include "common.h"
#include "taipbook.h"

TribeAIPlayBook::TribeAIPlayBook() {
    /* TODO: Stub */
    //                              undefined __thiscall TribeAIPlayBook(TribeAIPlayBook * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //                               ??0TribeAIPlayBook@@QAE@XZ                                   XREF[1]:     TRIBE_World:0052dfe1(c)  
    //                               TribeAIPlayBook::TribeAIPlayBook
    //                              taipbook.cpp:23 (14)
    //         004e68b0     PUSH       ESI
    //         004e68b1     MOV        ESI,this
    //         004e68b3     CALL       AIPlayBook::AIPlayBook                           undefined AIPlayBook(AIPlayBook * this)
    //         004e68b8     MOV        dword ptr [ESI],TribeAIPlayBook::`vftable'       = 004e68d0
    //                              taipbook.cpp:24 (4)
    //         004e68be     MOV        EAX,ESI
    //         004e68c0     POP        ESI
    //         004e68c1     RET
    //         004e68c2     ??         90h
    //         004e68c3     NOP
    //         004e68c4     NOP
    //         004e68c5     NOP
    //         004e68c6     NOP
    //         004e68c7     NOP
    //         004e68c8     NOP
    //         004e68c9     NOP
    //         004e68ca     NOP
    //         004e68cb     NOP
    //         004e68cc     NOP
    //         004e68cd     NOP
    //         004e68ce     NOP
    //         004e68cf     NOP
}

TribeAIPlayBook::~TribeAIPlayBook() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeAIPlayBook(TribeAIPlayBook * this)
    //              void              <VOID>         <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //                               ??1TribeAIPlayBook@@UAE@XZ                                   XREF[1]:     `vector_deleting_destructor':004e6
    //                               TribeAIPlayBook::~TribeAIPlayBook
    //         004e68f0     JMP        AIPlayBook::~AIPlayBook
    //         004e68f5     ??         90h
    //         004e68f6     NOP
    //         004e68f7     NOP
    //         004e68f8     NOP
    //         004e68f9     NOP
    //         004e68fa     NOP
    //         004e68fb     NOP
    //         004e68fc     NOP
    //         004e68fd     NOP
    //         004e68fe     NOP
    //         004e68ff     NOP
    //                              * public: virtual int __thiscall TribeAIPlayBook::convertTargetNameToIntType(char *)const               *
    //                              int __thiscall convertTargetNameToIntType(TribeAIPlayBook * this, ch
    //              int               EAX:4          <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004e6900(R)  
    //                               ?convertTargetNameToIntType@TribeAIPlayBook@@UBEHPAD@Z       XREF[1]:     00575624(*)  
    //                               TribeAIPlayBook::convertTargetNameToIntType
    //                              taipbook.cpp:29 (10)
    //         004e6900     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6904     PUSH       EAX
    //         004e6905     CALL       AIPlayBook::convertTargetNameToIntType           int convertTargetNameToIntType(AIPlayBook * t
    //                              taipbook.cpp:31 (3)
    //         004e690a     RET        0x4
    //         004e690d     ??         90h
    //         004e690e     NOP
    //         004e690f     NOP
    //                              * public: virtual int __thiscall TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char *)co... *
    //                              int __thiscall convertTargetCharacteristicNameToIntType(TribeAIPlayB
    //              int               EAX:4          <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004e6910(R)  
    //                               ?convertTargetCharacteristicNameToIntType@TribeAIPlayBook@@  XREF[1]:     00575628(*)  
    //                               TribeAIPlayBook::convertTargetCharacteristicNameToIntType
    //                              taipbook.cpp:36 (10)
    //         004e6910     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6914     PUSH       EAX
    //         004e6915     CALL       AIPlayBook::convertTargetCharacteristicNameToI   int convertTargetCharacteristicNameToIntType(
    //                              taipbook.cpp:38 (3)
    //         004e691a     RET        0x4
    //         004e691d     ??         90h
    //         004e691e     NOP
    //         004e691f     NOP
    //                              * public: virtual int __thiscall TribeAIPlayBook::convertUnitNameToIntType(char *)const                 *
    //                              int __thiscall convertUnitNameToIntType(TribeAIPlayBook * this, char
    //              int               EAX:4          <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004e6924(R)  
    //                               ?convertUnitNameToIntType@TribeAIPlayBook@@UBEHPAD@Z         XREF[1]:     0057562c(*)  
    //                               TribeAIPlayBook::convertUnitNameToIntType
    //                              taipbook.cpp:43 (4)
    //         004e6920     PUSH       EBX
    //         004e6921     PUSH       EBP
    //         004e6922     PUSH       ESI
    //         004e6923     PUSH       EDI
    //                              taipbook.cpp:44 (62)
    //         004e6924     MOV        EDI,dword ptr [ESP + param_1]
    //         004e6928     MOV        EBP,this
    //         004e692a     MOV        ESI,s_Hand                                       = 48h
    //         004e692f     MOV        EAX,EDI
    //                               LAB_004e6931                                                 XREF[1]:     004e6953(j)  
    //         004e6931     MOV        this,byte ptr [EAX]
    //         004e6933     MOV        BL,byte ptr [ESI]=>s_Hand                        = 48h
    //                                                                                  = 6Eh
    //         004e6935     MOV        DL,this
    //         004e6937     CMP        this,BL
    //         004e6939     JNZ        LAB_004e6959
    //         004e693b     TEST       DL,DL
    //         004e693d     JZ         LAB_004e6955
    //         004e693f     MOV        this,byte ptr [EAX + 0x1]
    //         004e6942     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00587a7d            = 61h
    //                                                                                  = 64h
    //         004e6945     MOV        DL,this
    //         004e6947     CMP        this,BL
    //         004e6949     JNZ        LAB_004e6959
    //         004e694b     ADD        EAX,0x2
    //         004e694e     ADD        ESI,0x2
    //         004e6951     TEST       DL,DL
    //         004e6953     JNZ        LAB_004e6931
    //                               LAB_004e6955                                                 XREF[1]:     004e693d(j)  
    //         004e6955     XOR        EAX,EAX
    //         004e6957     JMP        LAB_004e695e
    //                               LAB_004e6959                                                 XREF[2]:     004e6939(j), 004e6949(j)  
    //         004e6959     SBB        EAX,EAX
    //         004e695b     SBB        EAX,-0x1
    //                               LAB_004e695e                                                 XREF[1]:     004e6957(j)  
    //         004e695e     TEST       EAX,EAX
    //         004e6960     JNZ        LAB_004e6969
    //                              taipbook.cpp:57 (7)
    //         004e6962     POP        EDI
    //         004e6963     POP        ESI
    //         004e6964     POP        EBP
    //         004e6965     POP        EBX
    //         004e6966     RET        0x4
    //                               LAB_004e6969                                                 XREF[1]:     004e6960(j)  
    //                              taipbook.cpp:46 (56)
    //         004e6969     MOV        ESI,s_Ranged                                     = 52h
    //         004e696e     MOV        EAX,EDI
    //                               LAB_004e6970                                                 XREF[1]:     004e6992(j)  
    //         004e6970     MOV        this,byte ptr [EAX]
    //         004e6972     MOV        BL,byte ptr [ESI]=>s_Ranged                      = 52h
    //                                                                                  = 6Eh
    //         004e6974     MOV        DL,this
    //         004e6976     CMP        this,BL
    //         004e6978     JNZ        LAB_004e6998
    //         004e697a     TEST       DL,DL
    //         004e697c     JZ         LAB_004e6994
    //         004e697e     MOV        this,byte ptr [EAX + 0x1]
    //         004e6981     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00587a75            = 61h
    //                                                                                  = 00646567
    //         004e6984     MOV        DL,this
    //         004e6986     CMP        this,BL
    //         004e6988     JNZ        LAB_004e6998
    //         004e698a     ADD        EAX,0x2
    //         004e698d     ADD        ESI,0x2
    //         004e6990     TEST       DL,DL
    //         004e6992     JNZ        LAB_004e6970
    //                               LAB_004e6994                                                 XREF[1]:     004e697c(j)  
    //         004e6994     XOR        EAX,EAX
    //         004e6996     JMP        LAB_004e699d
    //                               LAB_004e6998                                                 XREF[2]:     004e6978(j), 004e6988(j)  
    //         004e6998     SBB        EAX,EAX
    //         004e699a     SBB        EAX,-0x1
    //                               LAB_004e699d                                                 XREF[1]:     004e6996(j)  
    //         004e699d     TEST       EAX,EAX
    //         004e699f     JNZ        LAB_004e69ad
    //                              taipbook.cpp:47 (5)
    //         004e69a1     MOV        EAX,0x1
    //                              taipbook.cpp:57 (7)
    //         004e69a6     POP        EDI
    //         004e69a7     POP        ESI
    //         004e69a8     POP        EBP
    //         004e69a9     POP        EBX
    //         004e69aa     RET        0x4
    //                               LAB_004e69ad                                                 XREF[1]:     004e699f(j)  
    //                              taipbook.cpp:48 (56)
    //         004e69ad     MOV        ESI,s_Priest                                     = 50h
    //         004e69b2     MOV        EAX,EDI
    //                               LAB_004e69b4                                                 XREF[1]:     004e69d6(j)  
    //         004e69b4     MOV        this,byte ptr [EAX]
    //         004e69b6     MOV        BL,byte ptr [ESI]=>s_Priest                      = 50h
    //                                                                                  = 69h
    //         004e69b8     MOV        DL,this
    //         004e69ba     CMP        this,BL
    //         004e69bc     JNZ        LAB_004e69dc
    //         004e69be     TEST       DL,DL
    //         004e69c0     JZ         LAB_004e69d8
    //         004e69c2     MOV        this,byte ptr [EAX + 0x1]
    //         004e69c5     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00587a6d            = 72h
    //                                                                                  = 00747365
    //         004e69c8     MOV        DL,this
    //         004e69ca     CMP        this,BL
    //         004e69cc     JNZ        LAB_004e69dc
    //         004e69ce     ADD        EAX,0x2
    //         004e69d1     ADD        ESI,0x2
    //         004e69d4     TEST       DL,DL
    //         004e69d6     JNZ        LAB_004e69b4
    //                               LAB_004e69d8                                                 XREF[1]:     004e69c0(j)  
    //         004e69d8     XOR        EAX,EAX
    //         004e69da     JMP        LAB_004e69e1
    //                               LAB_004e69dc                                                 XREF[2]:     004e69bc(j), 004e69cc(j)  
    //         004e69dc     SBB        EAX,EAX
    //         004e69de     SBB        EAX,-0x1
    //                               LAB_004e69e1                                                 XREF[1]:     004e69da(j)  
    //         004e69e1     TEST       EAX,EAX
    //         004e69e3     JNZ        LAB_004e69f1
    //                              taipbook.cpp:49 (5)
    //         004e69e5     MOV        EAX,0x4
    //                              taipbook.cpp:57 (7)
    //         004e69ea     POP        EDI
    //         004e69eb     POP        ESI
    //         004e69ec     POP        EBP
    //         004e69ed     POP        EBX
    //         004e69ee     RET        0x4
    //                               LAB_004e69f1                                                 XREF[1]:     004e69e3(j)  
    //                              taipbook.cpp:50 (56)
    //         004e69f1     MOV        ESI,s_Siege                                      = 53h
    //         004e69f6     MOV        EAX,EDI
    //                               LAB_004e69f8                                                 XREF[1]:     004e6a1a(j)  
    //         004e69f8     MOV        this,byte ptr [EAX]
    //         004e69fa     MOV        BL,byte ptr [ESI]=>s_Siege                       = 53h
    //                                                                                  = 65h
    //         004e69fc     MOV        DL,this
    //         004e69fe     CMP        this,BL
    //         004e6a00     JNZ        LAB_004e6a20
    //         004e6a02     TEST       DL,DL
    //         004e6a04     JZ         LAB_004e6a1c
    //         004e6a06     MOV        this,byte ptr [EAX + 0x1]
    //         004e6a09     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00587a65            = 69h
    //                                                                                  = 67h
    //         004e6a0c     MOV        DL,this
    //         004e6a0e     CMP        this,BL
    //         004e6a10     JNZ        LAB_004e6a20
    //         004e6a12     ADD        EAX,0x2
    //         004e6a15     ADD        ESI,0x2
    //         004e6a18     TEST       DL,DL
    //         004e6a1a     JNZ        LAB_004e69f8
    //                               LAB_004e6a1c                                                 XREF[1]:     004e6a04(j)  
    //         004e6a1c     XOR        EAX,EAX
    //         004e6a1e     JMP        LAB_004e6a25
    //                               LAB_004e6a20                                                 XREF[2]:     004e6a00(j), 004e6a10(j)  
    //         004e6a20     SBB        EAX,EAX
    //         004e6a22     SBB        EAX,-0x1
    //                               LAB_004e6a25                                                 XREF[1]:     004e6a1e(j)  
    //         004e6a25     TEST       EAX,EAX
    //         004e6a27     JNZ        LAB_004e6a35
    //                              taipbook.cpp:51 (5)
    //         004e6a29     MOV        EAX,0x5
    //                              taipbook.cpp:57 (7)
    //         004e6a2e     POP        EDI
    //         004e6a2f     POP        ESI
    //         004e6a30     POP        EBP
    //         004e6a31     POP        EBX
    //         004e6a32     RET        0x4
    //                               LAB_004e6a35                                                 XREF[1]:     004e6a27(j)  
    //                              taipbook.cpp:52 (56)
    //         004e6a35     MOV        ESI,s_Cavalry                                    = 43h
    //         004e6a3a     MOV        EAX,EDI
    //                               LAB_004e6a3c                                                 XREF[1]:     004e6a5e(j)  
    //         004e6a3c     MOV        this,byte ptr [EAX]
    //         004e6a3e     MOV        BL,byte ptr [ESI]=>s_Cavalry                     = 43h
    //                                                                                  = 76h
    //         004e6a40     MOV        DL,this
    //         004e6a42     CMP        this,BL
    //         004e6a44     JNZ        LAB_004e6a64
    //         004e6a46     TEST       DL,DL
    //         004e6a48     JZ         LAB_004e6a60
    //         004e6a4a     MOV        this,byte ptr [EAX + 0x1]
    //         004e6a4d     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00587a5d            = 61h
    //         004e6a50     MOV        DL,this
    //         004e6a52     CMP        this,BL
    //         004e6a54     JNZ        LAB_004e6a64
    //         004e6a56     ADD        EAX,0x2
    //         004e6a59     ADD        ESI,0x2
    //         004e6a5c     TEST       DL,DL
    //         004e6a5e     JNZ        LAB_004e6a3c
    //                               LAB_004e6a60                                                 XREF[1]:     004e6a48(j)  
    //         004e6a60     XOR        EAX,EAX
    //         004e6a62     JMP        LAB_004e6a69
    //                               LAB_004e6a64                                                 XREF[2]:     004e6a44(j), 004e6a54(j)  
    //         004e6a64     SBB        EAX,EAX
    //         004e6a66     SBB        EAX,-0x1
    //                               LAB_004e6a69                                                 XREF[1]:     004e6a62(j)  
    //         004e6a69     TEST       EAX,EAX
    //         004e6a6b     JNZ        LAB_004e6a79
    //                              taipbook.cpp:53 (5)
    //         004e6a6d     MOV        EAX,0x2
    //                              taipbook.cpp:57 (7)
    //         004e6a72     POP        EDI
    //         004e6a73     POP        ESI
    //         004e6a74     POP        EBP
    //         004e6a75     POP        EBX
    //         004e6a76     RET        0x4
    //                               LAB_004e6a79                                                 XREF[1]:     004e6a6b(j)  
    //                              taipbook.cpp:54 (56)
    //         004e6a79     MOV        ESI,s_Legion                                     = 4Ch
    //         004e6a7e     MOV        EAX,EDI
    //                               LAB_004e6a80                                                 XREF[1]:     004e6aa2(j)  
    //         004e6a80     MOV        this,byte ptr [EAX]
    //         004e6a82     MOV        BL,byte ptr [ESI]=>s_Legion                      = 4Ch
    //                                                                                  = 67h
    //         004e6a84     MOV        DL,this
    //         004e6a86     CMP        this,BL
    //         004e6a88     JNZ        LAB_004e6aa8
    //         004e6a8a     TEST       DL,DL
    //         004e6a8c     JZ         LAB_004e6aa4
    //         004e6a8e     MOV        this,byte ptr [EAX + 0x1]
    //         004e6a91     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00587a55            = 65h
    //                                                                                  = 006e6f69
    //         004e6a94     MOV        DL,this
    //         004e6a96     CMP        this,BL
    //         004e6a98     JNZ        LAB_004e6aa8
    //         004e6a9a     ADD        EAX,0x2
    //         004e6a9d     ADD        ESI,0x2
    //         004e6aa0     TEST       DL,DL
    //         004e6aa2     JNZ        LAB_004e6a80
    //                               LAB_004e6aa4                                                 XREF[1]:     004e6a8c(j)  
    //         004e6aa4     XOR        EAX,EAX
    //         004e6aa6     JMP        LAB_004e6aad
    //                               LAB_004e6aa8                                                 XREF[2]:     004e6a88(j), 004e6a98(j)  
    //         004e6aa8     SBB        EAX,EAX
    //         004e6aaa     SBB        EAX,-0x1
    //                               LAB_004e6aad                                                 XREF[1]:     004e6aa6(j)  
    //         004e6aad     TEST       EAX,EAX
    //         004e6aaf     JNZ        LAB_004e6abd
    //                              taipbook.cpp:55 (5)
    //         004e6ab1     MOV        EAX,0x3
    //                              taipbook.cpp:57 (7)
    //         004e6ab6     POP        EDI
    //         004e6ab7     POP        ESI
    //         004e6ab8     POP        EBP
    //         004e6ab9     POP        EBX
    //         004e6aba     RET        0x4
    //                               LAB_004e6abd                                                 XREF[1]:     004e6aaf(j)  
    //                              taipbook.cpp:56 (8)
    //         004e6abd     PUSH       EDI
    //         004e6abe     MOV        this,EBP
    //         004e6ac0     CALL       AIPlayBook::convertUnitNameToIntType             int convertUnitNameToIntType(AIPlayBook * thi
    //                              taipbook.cpp:57 (7)
    //         004e6ac5     POP        EDI
    //         004e6ac6     POP        ESI
    //         004e6ac7     POP        EBP
    //         004e6ac8     POP        EBX
    //         004e6ac9     RET        0x4
    //         004e6acc     ??         90h
    //         004e6acd     NOP
    //         004e6ace     NOP
    //         004e6acf     NOP
    //                              * public: virtual int __thiscall TribeAIPlayBook::convertUnitToIntType(class RGE_Static_Object *)const  *
    //                              int __thiscall convertUnitToIntType(TribeAIPlayBook * this, RGE_Stat
    //              int               EAX:4          <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004e6ad0(R)  
    //                               ?convertUnitToIntType@TribeAIPlayBook@@UBEHPAVRGE_Static_Ob  XREF[1]:     00575630(*)  
    //                               TribeAIPlayBook::convertUnitToIntType
    //                              taipbook.cpp:62 (17)
    //         004e6ad0     MOV        this,dword ptr [ESP + param_1]
    //         004e6ad4     MOV        EAX,dword ptr [ECX + this->field8_0x8]
    //         004e6ad7     MOV        AX,word ptr [EAX + 0x14]
    //         004e6adb     CMP        AX,0x12
    //         004e6adf     JNZ        LAB_004e6ae9
    //                              taipbook.cpp:65 (5)
    //         004e6ae1     MOV        EAX,0x4
    //                              taipbook.cpp:81 (3)
    //         004e6ae6     RET        0x4
    //                               LAB_004e6ae9                                                 XREF[1]:     004e6adf(j)  
    //                              taipbook.cpp:67 (6)
    //         004e6ae9     CMP        AX,0x1c
    //         004e6aed     JNZ        LAB_004e6af7
    //                              taipbook.cpp:68 (5)
    //         004e6aef     MOV        EAX,0x3
    //                              taipbook.cpp:81 (3)
    //         004e6af4     RET        0x4
    //                               LAB_004e6af7                                                 XREF[1]:     004e6aed(j)  
    //                              taipbook.cpp:70 (6)
    //         004e6af7     CMP        AX,0xd
    //         004e6afb     JNZ        LAB_004e6b05
    //                              taipbook.cpp:71 (5)
    //         004e6afd     MOV        EAX,0x5
    //                              taipbook.cpp:81 (3)
    //         004e6b02     RET        0x4
    //                               LAB_004e6b05                                                 XREF[1]:     004e6afb(j)  
    //                              taipbook.cpp:74 (12)
    //         004e6b05     CMP        AX,0xc
    //         004e6b09     JZ         LAB_004e6b33
    //         004e6b0b     CMP        AX,0x23
    //         004e6b0f     JZ         LAB_004e6b33
    //                              taipbook.cpp:77 (21)
    //         004e6b11     MOV        EDX,dword ptr [this->field0_0x0]
    //         004e6b13     CALL       dword ptr [EDX + 0x10c]
    //         004e6b19     FCOMP      float ptr [DAT_00575634]                         = align(2)
    //         004e6b1f     FNSTSW     AX
    //         004e6b21     TEST       AH,0x41
    //         004e6b24     JNZ        LAB_004e6b2e
    //                              taipbook.cpp:78 (5)
    //         004e6b26     MOV        EAX,0x1
    //                              taipbook.cpp:81 (3)
    //         004e6b2b     RET        0x4
    //                               LAB_004e6b2e                                                 XREF[1]:     004e6b24(j)  
    //                              taipbook.cpp:80 (2)
    //         004e6b2e     XOR        EAX,EAX
    //                              taipbook.cpp:81 (3)
    //         004e6b30     RET        0x4
    //                               LAB_004e6b33                                                 XREF[2]:     004e6b09(j), 004e6b0f(j)  
    //                              taipbook.cpp:75 (5)
    //         004e6b33     MOV        EAX,0x2
    //                              taipbook.cpp:81 (3)
    //         004e6b38     RET        0x4
    //         004e6b3b     ??         90h
    //         004e6b3c     NOP
    //         004e6b3d     NOP
    //         004e6b3e     NOP
    //         004e6b3f     NOP
}

int TribeAIPlayBook::convertTargetNameToIntType(char* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TribeAIPlayBook::convertUnitNameToIntType(char* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

