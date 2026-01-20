// Auto-generated scaffold unit: aipbook.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aipbook.cpp
#include "../include/common.h"

// Offset: 0x0040E930
undefined AIPlayPhaseCommand(AIPlayPhaseCommand* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(void)                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhaseCommand(AIPlayPhaseCommand * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhaseCom    ECX:4 (auto)   this
    //                               ??0AIPlayPhaseCommand@@QAE@XZ                                XREF[1]:     AIPlayPhase:0040f0ae(c)  
    //                               AIPlayPhaseCommand::AIPlayPhaseCommand
    //                              aipbook.cpp:26 (18)
    //         0040e930     MOV        EAX,this
    //         0040e932     XOR        this,this
    //         0040e934     MOV        byte ptr [EAX],this
    //         0040e936     MOV        byte ptr [EAX + 0x1],this
    //         0040e939     MOV        dword ptr [EAX + 0x4],this
    //         0040e93c     MOV        dword ptr [EAX + 0x8],this
    //         0040e93f     MOV        dword ptr [EAX + 0xc],this
    //                              aipbook.cpp:27 (1)
    //         0040e942     RET
}

// Offset: 0x0040E950
undefined AIPlayPhaseCommand(AIPlayPhaseCommand* this_, uchar param_2, uchar param_3, int param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char,unsigned char,int,int,int)    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhaseCommand(AIPlayPhaseCommand * this, u
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhaseCom    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040e956(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0040e950(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040e95c(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040e963(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0040e96a(R)  
    //                               ??0AIPlayPhaseCommand@@QAE@EEHHH@Z                           XREF[1]:     loadPlays:00411259(c)  
    //                               AIPlayPhaseCommand::AIPlayPhaseCommand
    //                              aipbook.cpp:37 (36)
    //         0040e950     MOV        DL,byte ptr [ESP + param_2]
    //         0040e954     MOV        EAX,this
    //         0040e956     MOV        this,byte ptr [ESP + param_1]
    //         0040e95a     MOV        byte ptr [EAX],this
    //         0040e95c     MOV        this,dword ptr [ESP + param_3]
    //         0040e960     MOV        byte ptr [EAX + 0x1],DL
    //         0040e963     MOV        EDX,dword ptr [ESP + param_4]
    //         0040e967     MOV        dword ptr [EAX + 0x4],this
    //         0040e96a     MOV        this,dword ptr [ESP + param_5]
    //         0040e96e     MOV        dword ptr [EAX + 0x8],EDX
    //         0040e971     MOV        dword ptr [EAX + 0xc],this
    //                              aipbook.cpp:38 (3)
    //         0040e974     RET        0x14
}

// Offset: 0x0040E980
undefined AIPlayPhaseCommand(AIPlayPhaseCommand* this_, uchar param_2, char* param_3, int param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char,char *,int,int,int)           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhaseCommand(AIPlayPhaseCommand * this, u
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhaseCom    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040e980(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0040e987(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040e995(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040e9a0(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0040e999(R)  
    //                               ??0AIPlayPhaseCommand@@QAE@EPADHHH@Z                         XREF[1]:     loadPlays:00410dfd(c)  
    //                               AIPlayPhaseCommand::AIPlayPhaseCommand
    //                              aipbook.cpp:48 (45)
    //         0040e980     MOV        AL,byte ptr [ESP + param_1]
    //         0040e984     PUSH       ESI
    //         0040e985     MOV        ESI,this
    //         0040e987     MOV        this,dword ptr [ESP + param_2]
    //         0040e98b     PUSH       this
    //         0040e98c     MOV        this,ESI
    //         0040e98e     MOV        byte ptr [ESI],AL
    //         0040e990     CALL       AIPlayPhaseCommand::convertToIntType             uchar convertToIntType(AIPlayPhaseCommand * t
    //         0040e995     MOV        EDX,dword ptr [ESP + param_3]
    //         0040e999     MOV        this,dword ptr [ESP + param_5]
    //         0040e99d     MOV        byte ptr [ESI + 0x1],AL
    //         0040e9a0     MOV        EAX,dword ptr [ESP + param_4]
    //         0040e9a4     MOV        dword ptr [ESI + 0x8],EAX
    //         0040e9a7     MOV        dword ptr [ESI + 0x4],EDX
    //         0040e9aa     MOV        dword ptr [ESI + 0xc],this
    //                              aipbook.cpp:49 (6)
    //         0040e9ad     MOV        EAX,ESI
    //         0040e9af     POP        ESI
    //         0040e9b0     RET        0x14
}

// Offset: 0x0040E9C0
char* nameType(AIPlayPhaseCommand* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall AIPlayPhaseCommand::nameType(void)const                                     *
    //                              *********************************************************************************************************
    //                              char * __thiscall nameType(AIPlayPhaseCommand * this)
    //              char *            EAX:4          <RETURN>
    //              AIPlayPhaseCom    ECX:4 (auto)   this
    //                               ?nameType@AIPlayPhaseCommand@@QBEPADXZ
    //                               AIPlayPhaseCommand::nameType
    //                              aipbook.cpp:54 (9)
    //         0040e9c0     MOV        AL,byte ptr [ECX + this->typeValue]
    //         0040e9c3     PUSH       EAX
    //         0040e9c4     CALL       AIPlayPhaseCommand::convertToNameType            char * convertToNameType(AIPlayPhaseCommand *
    //                              aipbook.cpp:56 (1)
    //         0040e9c9     RET
}

// Offset: 0x0040E9D0
uchar convertToIntType(AIPlayPhaseCommand* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall AIPlayPhaseCommand::convertToIntType(char *)const                 *
    //                              *********************************************************************************************************
    //                              uchar __thiscall convertToIntType(AIPlayPhaseCommand * this, char * 
    //              uchar             AL:1           <RETURN>
    //              AIPlayPhaseCom    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040e9d3(R)  
    //                               ?convertToIntType@AIPlayPhaseCommand@@IBEEPAD@Z              XREF[1]:     AIPlayPhaseCommand:0040e990(c)  
    //                               AIPlayPhaseCommand::convertToIntType
    //                              aipbook.cpp:61 (3)
    //         0040e9d0     PUSH       EBX
    //         0040e9d1     PUSH       ESI
    //         0040e9d2     PUSH       EDI
    //                              aipbook.cpp:62 (60)
    //         0040e9d3     MOV        EDI,dword ptr [ESP + param_1]
    //         0040e9d7     MOV        ESI,s_Move                                       = 4Dh
    //         0040e9dc     MOV        EAX,EDI
    //                               LAB_0040e9de                                                 XREF[1]:     0040ea00(j)  
    //         0040e9de     MOV        DL,byte ptr [EAX]
    //         0040e9e0     MOV        BL,byte ptr [ESI]=>s_Move                        = 4Dh
    //                                                                                  = 76h
    //         0040e9e2     MOV        this,DL
    //         0040e9e4     CMP        DL,BL
    //         0040e9e6     JNZ        LAB_0040ea06
    //         0040e9e8     TEST       this,this
    //         0040e9ea     JZ         LAB_0040ea02
    //         0040e9ec     MOV        DL,byte ptr [EAX + 0x1]
    //         0040e9ef     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f101            = 6Fh
    //                                                                                  = 65h
    //         0040e9f2     MOV        this,DL
    //         0040e9f4     CMP        DL,BL
    //         0040e9f6     JNZ        LAB_0040ea06
    //         0040e9f8     ADD        EAX,0x2
    //         0040e9fb     ADD        ESI,0x2
    //         0040e9fe     TEST       this,this
    //         0040ea00     JNZ        LAB_0040e9de
    //                               LAB_0040ea02                                                 XREF[1]:     0040e9ea(j)  
    //         0040ea02     XOR        EAX,EAX
    //         0040ea04     JMP        LAB_0040ea0b
    //                               LAB_0040ea06                                                 XREF[2]:     0040e9e6(j), 0040e9f6(j)  
    //         0040ea06     SBB        EAX,EAX
    //         0040ea08     SBB        EAX,-0x1
    //                               LAB_0040ea0b                                                 XREF[1]:     0040ea04(j)  
    //         0040ea0b     TEST       EAX,EAX
    //         0040ea0d     JNZ        LAB_0040ea17
    //                              aipbook.cpp:63 (2)
    //         0040ea0f     MOV        AL,0x1
    //                              aipbook.cpp:79 (6)
    //         0040ea11     POP        EDI
    //         0040ea12     POP        ESI
    //         0040ea13     POP        EBX
    //         0040ea14     RET        0x4
    //                               LAB_0040ea17                                                 XREF[1]:     0040ea0d(j)  
    //                              aipbook.cpp:64 (56)
    //         0040ea17     MOV        ESI,s_Attack                                     = 41h
    //         0040ea1c     MOV        EAX,EDI
    //                               LAB_0040ea1e                                                 XREF[1]:     0040ea40(j)  
    //         0040ea1e     MOV        DL,byte ptr [EAX]
    //         0040ea20     MOV        BL,byte ptr [ESI]=>s_Attack                      = 41h
    //                                                                                  = 74h
    //         0040ea22     MOV        this,DL
    //         0040ea24     CMP        DL,BL
    //         0040ea26     JNZ        LAB_0040ea46
    //         0040ea28     TEST       this,this
    //         0040ea2a     JZ         LAB_0040ea42
    //         0040ea2c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ea2f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f0b5            = 74h
    //                                                                                  = 006b6361
    //         0040ea32     MOV        this,DL
    //         0040ea34     CMP        DL,BL
    //         0040ea36     JNZ        LAB_0040ea46
    //         0040ea38     ADD        EAX,0x2
    //         0040ea3b     ADD        ESI,0x2
    //         0040ea3e     TEST       this,this
    //         0040ea40     JNZ        LAB_0040ea1e
    //                               LAB_0040ea42                                                 XREF[1]:     0040ea2a(j)  
    //         0040ea42     XOR        EAX,EAX
    //         0040ea44     JMP        LAB_0040ea4b
    //                               LAB_0040ea46                                                 XREF[2]:     0040ea26(j), 0040ea36(j)  
    //         0040ea46     SBB        EAX,EAX
    //         0040ea48     SBB        EAX,-0x1
    //                               LAB_0040ea4b                                                 XREF[1]:     0040ea44(j)  
    //         0040ea4b     TEST       EAX,EAX
    //         0040ea4d     JNZ        LAB_0040ea57
    //                              aipbook.cpp:65 (2)
    //         0040ea4f     MOV        AL,0x2
    //                              aipbook.cpp:79 (6)
    //         0040ea51     POP        EDI
    //         0040ea52     POP        ESI
    //         0040ea53     POP        EBX
    //         0040ea54     RET        0x4
    //                               LAB_0040ea57                                                 XREF[1]:     0040ea4d(j)  
    //                              aipbook.cpp:66 (56)
    //         0040ea57     MOV        ESI,s_AttackSavedTarget                          = 41h
    //         0040ea5c     MOV        EAX,EDI
    //                               LAB_0040ea5e                                                 XREF[1]:     0040ea80(j)  
    //         0040ea5e     MOV        DL,byte ptr [EAX]
    //         0040ea60     MOV        BL,byte ptr [ESI]=>s_AttackSavedTarget           = 41h
    //                                                                                  = 74h
    //         0040ea62     MOV        this,DL
    //         0040ea64     CMP        DL,BL
    //         0040ea66     JNZ        LAB_0040ea86
    //         0040ea68     TEST       this,this
    //         0040ea6a     JZ         LAB_0040ea82
    //         0040ea6c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ea6f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f539            = 74h
    //                                                                                  = "ackSavedTarget"
    //         0040ea72     MOV        this,DL
    //         0040ea74     CMP        DL,BL
    //         0040ea76     JNZ        LAB_0040ea86
    //         0040ea78     ADD        EAX,0x2
    //         0040ea7b     ADD        ESI,0x2
    //         0040ea7e     TEST       this,this
    //         0040ea80     JNZ        LAB_0040ea5e
    //                               LAB_0040ea82                                                 XREF[1]:     0040ea6a(j)  
    //         0040ea82     XOR        EAX,EAX
    //         0040ea84     JMP        LAB_0040ea8b
    //                               LAB_0040ea86                                                 XREF[2]:     0040ea66(j), 0040ea76(j)  
    //         0040ea86     SBB        EAX,EAX
    //         0040ea88     SBB        EAX,-0x1
    //                               LAB_0040ea8b                                                 XREF[1]:     0040ea84(j)  
    //         0040ea8b     TEST       EAX,EAX
    //         0040ea8d     JNZ        LAB_0040ea97
    //                              aipbook.cpp:67 (2)
    //         0040ea8f     MOV        AL,0x3
    //                              aipbook.cpp:79 (6)
    //         0040ea91     POP        EDI
    //         0040ea92     POP        ESI
    //         0040ea93     POP        EBX
    //         0040ea94     RET        0x4
    //                               LAB_0040ea97                                                 XREF[1]:     0040ea8d(j)  
    //                              aipbook.cpp:68 (56)
    //         0040ea97     MOV        ESI,s_Retreat                                    = 52h
    //         0040ea9c     MOV        EAX,EDI
    //                               LAB_0040ea9e                                                 XREF[1]:     0040eac0(j)  
    //         0040ea9e     MOV        DL,byte ptr [EAX]
    //         0040eaa0     MOV        BL,byte ptr [ESI]=>s_Retreat                     = 52h
    //                                                                                  = 74h
    //         0040eaa2     MOV        this,DL
    //         0040eaa4     CMP        DL,BL
    //         0040eaa6     JNZ        LAB_0040eac6
    //         0040eaa8     TEST       this,this
    //         0040eaaa     JZ         LAB_0040eac2
    //         0040eaac     MOV        DL,byte ptr [EAX + 0x1]
    //         0040eaaf     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f531            = 65h
    //                                                                                  = 72h
    //         0040eab2     MOV        this,DL
    //         0040eab4     CMP        DL,BL
    //         0040eab6     JNZ        LAB_0040eac6
    //         0040eab8     ADD        EAX,0x2
    //         0040eabb     ADD        ESI,0x2
    //         0040eabe     TEST       this,this
    //         0040eac0     JNZ        LAB_0040ea9e
    //                               LAB_0040eac2                                                 XREF[1]:     0040eaaa(j)  
    //         0040eac2     XOR        EAX,EAX
    //         0040eac4     JMP        LAB_0040eacb
    //                               LAB_0040eac6                                                 XREF[2]:     0040eaa6(j), 0040eab6(j)  
    //         0040eac6     SBB        EAX,EAX
    //         0040eac8     SBB        EAX,-0x1
    //                               LAB_0040eacb                                                 XREF[1]:     0040eac4(j)  
    //         0040eacb     TEST       EAX,EAX
    //         0040eacd     JNZ        LAB_0040ead7
    //                              aipbook.cpp:69 (2)
    //         0040eacf     MOV        AL,0x4
    //                              aipbook.cpp:79 (6)
    //         0040ead1     POP        EDI
    //         0040ead2     POP        ESI
    //         0040ead3     POP        EBX
    //         0040ead4     RET        0x4
    //                               LAB_0040ead7                                                 XREF[1]:     0040eacd(j)  
    //                              aipbook.cpp:70 (56)
    //         0040ead7     MOV        ESI,s_Heal                                       = 48h
    //         0040eadc     MOV        EAX,EDI
    //                               LAB_0040eade                                                 XREF[1]:     0040eb00(j)  
    //         0040eade     MOV        DL,byte ptr [EAX]
    //         0040eae0     MOV        BL,byte ptr [ESI]=>s_Heal                        = 48h
    //                                                                                  = 61h
    //         0040eae2     MOV        this,DL
    //         0040eae4     CMP        DL,BL
    //         0040eae6     JNZ        LAB_0040eb06
    //         0040eae8     TEST       this,this
    //         0040eaea     JZ         LAB_0040eb02
    //         0040eaec     MOV        DL,byte ptr [EAX + 0x1]
    //         0040eaef     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f529            = 65h
    //                                                                                  = 6Ch
    //         0040eaf2     MOV        this,DL
    //         0040eaf4     CMP        DL,BL
    //         0040eaf6     JNZ        LAB_0040eb06
    //         0040eaf8     ADD        EAX,0x2
    //         0040eafb     ADD        ESI,0x2
    //         0040eafe     TEST       this,this
    //         0040eb00     JNZ        LAB_0040eade
    //                               LAB_0040eb02                                                 XREF[1]:     0040eaea(j)  
    //         0040eb02     XOR        EAX,EAX
    //         0040eb04     JMP        LAB_0040eb0b
    //                               LAB_0040eb06                                                 XREF[2]:     0040eae6(j), 0040eaf6(j)  
    //         0040eb06     SBB        EAX,EAX
    //         0040eb08     SBB        EAX,-0x1
    //                               LAB_0040eb0b                                                 XREF[1]:     0040eb04(j)  
    //         0040eb0b     TEST       EAX,EAX
    //         0040eb0d     JNZ        LAB_0040eb17
    //                              aipbook.cpp:71 (2)
    //         0040eb0f     MOV        AL,0x5
    //                              aipbook.cpp:79 (6)
    //         0040eb11     POP        EDI
    //         0040eb12     POP        ESI
    //         0040eb13     POP        EBX
    //         0040eb14     RET        0x4
    //                               LAB_0040eb17                                                 XREF[1]:     0040eb0d(j)  
    //                              aipbook.cpp:72 (56)
    //         0040eb17     MOV        ESI,s_ResetHitPoints                             = 52h
    //         0040eb1c     MOV        EAX,EDI
    //                               LAB_0040eb1e                                                 XREF[1]:     0040eb40(j)  
    //         0040eb1e     MOV        DL,byte ptr [EAX]
    //         0040eb20     MOV        BL,byte ptr [ESI]=>s_ResetHitPoints              = 52h
    //                                                                                  = 73h
    //         0040eb22     MOV        this,DL
    //         0040eb24     CMP        DL,BL
    //         0040eb26     JNZ        LAB_0040eb46
    //         0040eb28     TEST       this,this
    //         0040eb2a     JZ         LAB_0040eb42
    //         0040eb2c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040eb2f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f519            = 65h
    //                                                                                  = "etHitPoints"
    //         0040eb32     MOV        this,DL
    //         0040eb34     CMP        DL,BL
    //         0040eb36     JNZ        LAB_0040eb46
    //         0040eb38     ADD        EAX,0x2
    //         0040eb3b     ADD        ESI,0x2
    //         0040eb3e     TEST       this,this
    //         0040eb40     JNZ        LAB_0040eb1e
    //                               LAB_0040eb42                                                 XREF[1]:     0040eb2a(j)  
    //         0040eb42     XOR        EAX,EAX
    //         0040eb44     JMP        LAB_0040eb4b
    //                               LAB_0040eb46                                                 XREF[2]:     0040eb26(j), 0040eb36(j)  
    //         0040eb46     SBB        EAX,EAX
    //         0040eb48     SBB        EAX,-0x1
    //                               LAB_0040eb4b                                                 XREF[1]:     0040eb44(j)  
    //         0040eb4b     TEST       EAX,EAX
    //         0040eb4d     JNZ        LAB_0040eb57
    //                              aipbook.cpp:73 (2)
    //         0040eb4f     MOV        AL,0x6
    //                              aipbook.cpp:79 (6)
    //         0040eb51     POP        EDI
    //         0040eb52     POP        ESI
    //         0040eb53     POP        EBX
    //         0040eb54     RET        0x4
    //                               LAB_0040eb57                                                 XREF[1]:     0040eb4d(j)  
    //                              aipbook.cpp:74 (56)
    //         0040eb57     MOV        ESI,s_ResetAliveCount                            = 52h
    //         0040eb5c     MOV        EAX,EDI
    //                               LAB_0040eb5e                                                 XREF[1]:     0040eb80(j)  
    //         0040eb5e     MOV        DL,byte ptr [EAX]
    //         0040eb60     MOV        BL,byte ptr [ESI]=>s_ResetAliveCount             = 52h
    //                                                                                  = 73h
    //         0040eb62     MOV        this,DL
    //         0040eb64     CMP        DL,BL
    //         0040eb66     JNZ        LAB_0040eb86
    //         0040eb68     TEST       this,this
    //         0040eb6a     JZ         LAB_0040eb82
    //         0040eb6c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040eb6f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f509            = 65h
    //                                                                                  = "etAliveCount"
    //         0040eb72     MOV        this,DL
    //         0040eb74     CMP        DL,BL
    //         0040eb76     JNZ        LAB_0040eb86
    //         0040eb78     ADD        EAX,0x2
    //         0040eb7b     ADD        ESI,0x2
    //         0040eb7e     TEST       this,this
    //         0040eb80     JNZ        LAB_0040eb5e
    //                               LAB_0040eb82                                                 XREF[1]:     0040eb6a(j)  
    //         0040eb82     XOR        EAX,EAX
    //         0040eb84     JMP        LAB_0040eb8b
    //                               LAB_0040eb86                                                 XREF[2]:     0040eb66(j), 0040eb76(j)  
    //         0040eb86     SBB        EAX,EAX
    //         0040eb88     SBB        EAX,-0x1
    //                               LAB_0040eb8b                                                 XREF[1]:     0040eb84(j)  
    //         0040eb8b     TEST       EAX,EAX
    //         0040eb8d     JNZ        LAB_0040eb97
    //                              aipbook.cpp:75 (2)
    //         0040eb8f     MOV        AL,0x7
    //                              aipbook.cpp:79 (6)
    //         0040eb91     POP        EDI
    //         0040eb92     POP        ESI
    //         0040eb93     POP        EBX
    //         0040eb94     RET        0x4
    //                               LAB_0040eb97                                                 XREF[1]:     0040eb8d(j)  
    //                              aipbook.cpp:76 (54)
    //         0040eb97     MOV        ESI,s_Wait                                       = 57h
    //         0040eb9c     MOV        EAX,EDI
    //                               LAB_0040eb9e                                                 XREF[1]:     0040ebc0(j)  
    //         0040eb9e     MOV        DL,byte ptr [EAX]
    //         0040eba0     MOV        BL,byte ptr [ESI]=>s_Wait                        = 57h
    //                                                                                  = 69h
    //         0040eba2     MOV        this,DL
    //         0040eba4     CMP        DL,BL
    //         0040eba6     JNZ        LAB_0040ebd3
    //         0040eba8     TEST       this,this
    //         0040ebaa     JZ         LAB_0040ebc2
    //         0040ebac     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ebaf     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f149            = 61h
    //                                                                                  = 74h
    //         0040ebb2     MOV        this,DL
    //         0040ebb4     CMP        DL,BL
    //         0040ebb6     JNZ        LAB_0040ebd3
    //         0040ebb8     ADD        EAX,0x2
    //         0040ebbb     ADD        ESI,0x2
    //         0040ebbe     TEST       this,this
    //         0040ebc0     JNZ        LAB_0040eb9e
    //                               LAB_0040ebc2                                                 XREF[1]:     0040ebaa(j)  
    //         0040ebc2     XOR        EAX,EAX
    //         0040ebc4     TEST       EAX,EAX
    //         0040ebc6     SETNZ      AL
    //         0040ebc9     DEC        EAX
    //         0040ebca     AND        EAX,0x8
    //                              aipbook.cpp:79 (6)
    //         0040ebcd     POP        EDI
    //         0040ebce     POP        ESI
    //         0040ebcf     POP        EBX
    //         0040ebd0     RET        0x4
    //                               LAB_0040ebd3                                                 XREF[2]:     0040eba6(j), 0040ebb6(j)  
    //                              aipbook.cpp:76 (2)
    //         0040ebd3     SBB        EAX,EAX
    //                              aipbook.cpp:79 (18)
    //         0040ebd5     POP        EDI
    //         0040ebd6     SBB        EAX,-0x1
    //         0040ebd9     POP        ESI
    //         0040ebda     TEST       EAX,EAX
    //         0040ebdc     SETNZ      AL
    //         0040ebdf     DEC        EAX
    //         0040ebe0     POP        EBX
    //         0040ebe1     AND        EAX,0x8
    //         0040ebe4     RET        0x4
}

// Offset: 0x0040EBF0
char* convertToNameType(AIPlayPhaseCommand* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: char * __thiscall AIPlayPhaseCommand::convertToNameType(unsigned char)const                *
    //                              *********************************************************************************************************
    //                              char * __thiscall convertToNameType(AIPlayPhaseCommand * this, uchar
    //              char *            EAX:4          <RETURN>
    //              AIPlayPhaseCom    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040ebf0(R)  
    //                               ?convertToNameType@AIPlayPhaseCommand@@IBEPADE@Z             XREF[1]:     nameType:0040e9c4(c)  
    //                               AIPlayPhaseCommand::convertToNameType
    //                              aipbook.cpp:84 (22)
    //         0040ebf0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040ebf4     AND        EAX,0xff
    //         0040ebf9     DEC        EAX
    //         0040ebfa     CMP        EAX,0x7
    //         0040ebfd     JA         switchD_0040ebff::default
    //                               switchD_0040ebff::switchD
    //         0040ebff     JMP        dword ptr [EAX*0x4 + switchD_0040ebff::switchd   = 0040ec06
    //                               switchD_0040ebff::caseD_1                                    XREF[2]:     0040ebff(j), 0040ec50(*)  
    //                              aipbook.cpp:86 (5)
    //         0040ec06     MOV        EAX,s_Move                                       = 4Dh
    //                              aipbook.cpp:96 (3)
    //         0040ec0b     RET        0x4
    //                               switchD_0040ebff::caseD_2                                    XREF[2]:     0040ebff(j), 0040ec54(*)  
    //                              aipbook.cpp:87 (5)
    //         0040ec0e     MOV        EAX,s_Attack                                     = 41h
    //                              aipbook.cpp:96 (3)
    //         0040ec13     RET        0x4
    //                               switchD_0040ebff::caseD_3                                    XREF[2]:     0040ebff(j), 0040ec58(*)  
    //                              aipbook.cpp:88 (5)
    //         0040ec16     MOV        EAX,s_AttackSavedTarget                          = 41h
    //                              aipbook.cpp:96 (3)
    //         0040ec1b     RET        0x4
    //                               switchD_0040ebff::caseD_4                                    XREF[2]:     0040ebff(j), 0040ec5c(*)  
    //                              aipbook.cpp:89 (5)
    //         0040ec1e     MOV        EAX,s_Retreat                                    = 52h
    //                              aipbook.cpp:96 (3)
    //         0040ec23     RET        0x4
    //                               switchD_0040ebff::caseD_5                                    XREF[2]:     0040ebff(j), 0040ec60(*)  
    //                              aipbook.cpp:90 (5)
    //         0040ec26     MOV        EAX,s_Heal                                       = 48h
    //                              aipbook.cpp:96 (3)
    //         0040ec2b     RET        0x4
    //                               switchD_0040ebff::caseD_6                                    XREF[2]:     0040ebff(j), 0040ec64(*)  
    //                              aipbook.cpp:91 (5)
    //         0040ec2e     MOV        EAX,s_ResetHitPoints                             = 52h
    //                              aipbook.cpp:96 (3)
    //         0040ec33     RET        0x4
    //                               switchD_0040ebff::caseD_7                                    XREF[2]:     0040ebff(j), 0040ec68(*)  
    //                              aipbook.cpp:92 (5)
    //         0040ec36     MOV        EAX,s_ResetAliveCount                            = 52h
    //                              aipbook.cpp:96 (3)
    //         0040ec3b     RET        0x4
    //                               switchD_0040ebff::caseD_8                                    XREF[2]:     0040ebff(j), 0040ec6c(*)  
    //                              aipbook.cpp:93 (5)
    //         0040ec3e     MOV        EAX,s_Wait                                       = 57h
    //                              aipbook.cpp:96 (3)
    //         0040ec43     RET        0x4
    //                               switchD_0040ebff::default                                    XREF[1]:     0040ebfd(j)  
    //                              aipbook.cpp:95 (5)
    //         0040ec46     MOV        EAX,s_Invalid                                    = "Invalid"
    //                              aipbook.cpp:96 (37)
    //         0040ec4b     RET        0x4
}

// Offset: 0x0040EC4E
undefined FUN_0040ec4e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0040ec4e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0040ec4e
    //         0040ec4e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040ebff::switchdataD_0040ec50                       XREF[1]:     convertToNameType:0040ebff(*)  
}

// Offset: 0x0040EC70
undefined AIPlayPhaseTrigger(AIPlayPhaseTrigger* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(void)                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhaseTrigger(AIPlayPhaseTrigger * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhaseTri    ECX:4 (auto)   this
    //                               ??0AIPlayPhaseTrigger@@QAE@XZ                                XREF[1]:     AIPlayPhase:0040f0c3(c)  
    //                               AIPlayPhaseTrigger::AIPlayPhaseTrigger
    //                              aipbook.cpp:107 (21)
    //         0040ec70     MOV        EAX,this
    //         0040ec72     XOR        DL,DL
    //         0040ec74     OR         this,0xffffffff
    //         0040ec77     MOV        byte ptr [EAX],DL
    //         0040ec79     MOV        dword ptr [EAX + 0x4],this
    //         0040ec7c     MOV        dword ptr [EAX + 0x8],this
    //         0040ec7f     MOV        byte ptr [EAX + 0xc],DL
    //         0040ec82     MOV        byte ptr [EAX + 0xd],DL
    //                              aipbook.cpp:108 (1)
    //         0040ec85     RET
}

// Offset: 0x0040EC90
undefined AIPlayPhaseTrigger(AIPlayPhaseTrigger* this_, uchar param_2, int param_3, int param_4, uchar param_5, uchar param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(unsigned char,int,int,unsigned char,unsi... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhaseTrigger(AIPlayPhaseTrigger * this, u
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhaseTri    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040ec96(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040ec90(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040ec9c(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0040eca3(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0040ecaa(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0040ecb1(R)  
    //                               ??0AIPlayPhaseTrigger@@QAE@EHHEEH@Z
    //                               AIPlayPhaseTrigger::AIPlayPhaseTrigger
    //                              aipbook.cpp:119 (43)
    //         0040ec90     MOV        EDX,dword ptr [ESP + param_2]
    //         0040ec94     MOV        EAX,this
    //         0040ec96     MOV        this,byte ptr [ESP + param_1]
    //         0040ec9a     MOV        byte ptr [EAX],this
    //         0040ec9c     MOV        this,dword ptr [ESP + param_3]
    //         0040eca0     MOV        dword ptr [EAX + 0x4],EDX
    //         0040eca3     MOV        DL,byte ptr [ESP + param_4]
    //         0040eca7     MOV        dword ptr [EAX + 0x8],this
    //         0040ecaa     MOV        this,byte ptr [ESP + param_5]
    //         0040ecae     MOV        byte ptr [EAX + 0xc],DL
    //         0040ecb1     MOV        EDX,dword ptr [ESP + param_6]
    //         0040ecb5     MOV        byte ptr [EAX + 0xd],this
    //         0040ecb8     MOV        dword ptr [EAX + 0x10],EDX
    //                              aipbook.cpp:120 (3)
    //         0040ecbb     RET        0x18
}

// Offset: 0x0040ECC0
undefined AIPlayPhaseTrigger(AIPlayPhaseTrigger* this_, char* param_2, int param_3, int param_4, uchar param_5, uchar param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(char *,int,int,unsigned char,unsigned ch... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhaseTrigger(AIPlayPhaseTrigger * this, c
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhaseTri    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040ecc0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040eccd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040ecd1(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0040ecd7(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0040ecde(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0040ece5(R)  
    //                               ??0AIPlayPhaseTrigger@@QAE@PADHHEEH@Z                        XREF[2]:     loadPlays:00410eca(c), 
    //                               AIPlayPhaseTrigger::AIPlayPhaseTrigger                                    loadPlays:00410f9f(c)  
    //                              aipbook.cpp:131 (50)
    //         0040ecc0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040ecc4     PUSH       ESI
    //         0040ecc5     MOV        ESI,this
    //         0040ecc7     PUSH       EAX
    //         0040ecc8     CALL       AIPlayPhaseTrigger::convertToIntType             uchar convertToIntType(AIPlayPhaseTrigger * t
    //         0040eccd     MOV        this,dword ptr [ESP + param_2]
    //         0040ecd1     MOV        EDX,dword ptr [ESP + param_3]
    //         0040ecd5     MOV        byte ptr [ESI],AL
    //         0040ecd7     MOV        AL,byte ptr [ESP + param_4]
    //         0040ecdb     MOV        dword ptr [ESI + 0x4],this
    //         0040ecde     MOV        this,byte ptr [ESP + param_5]
    //         0040ece2     MOV        dword ptr [ESI + 0x8],EDX
    //         0040ece5     MOV        EDX,dword ptr [ESP + param_6]
    //         0040ece9     MOV        byte ptr [ESI + 0xc],AL
    //         0040ecec     MOV        byte ptr [ESI + 0xd],this
    //         0040ecef     MOV        dword ptr [ESI + 0x10],EDX
    //                              aipbook.cpp:132 (6)
    //         0040ecf2     MOV        EAX,ESI
    //         0040ecf4     POP        ESI
    //         0040ecf5     RET        0x18
}

// Offset: 0x0040ED00
char* nameType(AIPlayPhaseTrigger* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall AIPlayPhaseTrigger::nameType(void)const                                     *
    //                              *********************************************************************************************************
    //                              char * __thiscall nameType(AIPlayPhaseTrigger * this)
    //              char *            EAX:4          <RETURN>
    //              AIPlayPhaseTri    ECX:4 (auto)   this
    //                               ?nameType@AIPlayPhaseTrigger@@QBEPADXZ
    //                               AIPlayPhaseTrigger::nameType
    //                              aipbook.cpp:137 (8)
    //         0040ed00     MOV        AL,byte ptr [this->typeValue]
    //         0040ed02     PUSH       EAX
    //         0040ed03     CALL       AIPlayPhaseTrigger::convertToNameType            char * convertToNameType(AIPlayPhaseTrigger *
    //                              aipbook.cpp:139 (1)
    //         0040ed08     RET
}

// Offset: 0x0040ED10
uchar convertToIntType(AIPlayPhaseTrigger* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall AIPlayPhaseTrigger::convertToIntType(char *)const                 *
    //                              *********************************************************************************************************
    //                              uchar __thiscall convertToIntType(AIPlayPhaseTrigger * this, char * 
    //              uchar             AL:1           <RETURN>
    //              AIPlayPhaseTri    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040ed13(R)  
    //                               ?convertToIntType@AIPlayPhaseTrigger@@IBEEPAD@Z              XREF[1]:     AIPlayPhaseTrigger:0040ecc8(c)  
    //                               AIPlayPhaseTrigger::convertToIntType
    //                              aipbook.cpp:144 (3)
    //         0040ed10     PUSH       EBX
    //         0040ed11     PUSH       ESI
    //         0040ed12     PUSH       EDI
    //                              aipbook.cpp:145 (60)
    //         0040ed13     MOV        EDI,dword ptr [ESP + param_1]
    //         0040ed17     MOV        ESI,s_Gather                                     = 47h
    //         0040ed1c     MOV        EAX,EDI
    //                               LAB_0040ed1e                                                 XREF[1]:     0040ed40(j)  
    //         0040ed1e     MOV        DL,byte ptr [EAX]
    //         0040ed20     MOV        BL,byte ptr [ESI]=>s_Gather                      = 47h
    //                                                                                  = 74h
    //         0040ed22     MOV        this,DL
    //         0040ed24     CMP        DL,BL
    //         0040ed26     JNZ        LAB_0040ed46
    //         0040ed28     TEST       this,this
    //         0040ed2a     JZ         LAB_0040ed42
    //         0040ed2c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ed2f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f09d            = 61h
    //                                                                                  = 00726568
    //         0040ed32     MOV        this,DL
    //         0040ed34     CMP        DL,BL
    //         0040ed36     JNZ        LAB_0040ed46
    //         0040ed38     ADD        EAX,0x2
    //         0040ed3b     ADD        ESI,0x2
    //         0040ed3e     TEST       this,this
    //         0040ed40     JNZ        LAB_0040ed1e
    //                               LAB_0040ed42                                                 XREF[1]:     0040ed2a(j)  
    //         0040ed42     XOR        EAX,EAX
    //         0040ed44     JMP        LAB_0040ed4b
    //                               LAB_0040ed46                                                 XREF[2]:     0040ed26(j), 0040ed36(j)  
    //         0040ed46     SBB        EAX,EAX
    //         0040ed48     SBB        EAX,-0x1
    //                               LAB_0040ed4b                                                 XREF[1]:     0040ed44(j)  
    //         0040ed4b     TEST       EAX,EAX
    //         0040ed4d     JNZ        LAB_0040ed57
    //                              aipbook.cpp:146 (2)
    //         0040ed4f     MOV        AL,0x1
    //                              aipbook.cpp:168 (6)
    //         0040ed51     POP        EDI
    //         0040ed52     POP        ESI
    //         0040ed53     POP        EBX
    //         0040ed54     RET        0x4
    //                               LAB_0040ed57                                                 XREF[1]:     0040ed4d(j)  
    //                              aipbook.cpp:147 (56)
    //         0040ed57     MOV        ESI,s_Death                                      = 44h
    //         0040ed5c     MOV        EAX,EDI
    //                               LAB_0040ed5e                                                 XREF[1]:     0040ed80(j)  
    //         0040ed5e     MOV        DL,byte ptr [EAX]
    //         0040ed60     MOV        BL,byte ptr [ESI]=>s_Death                       = 44h
    //                                                                                  = 61h
    //         0040ed62     MOV        this,DL
    //         0040ed64     CMP        DL,BL
    //         0040ed66     JNZ        LAB_0040ed86
    //         0040ed68     TEST       this,this
    //         0040ed6a     JZ         LAB_0040ed82
    //         0040ed6c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ed6f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5dd            = 65h
    //                                                                                  = 74h
    //         0040ed72     MOV        this,DL
    //         0040ed74     CMP        DL,BL
    //         0040ed76     JNZ        LAB_0040ed86
    //         0040ed78     ADD        EAX,0x2
    //         0040ed7b     ADD        ESI,0x2
    //         0040ed7e     TEST       this,this
    //         0040ed80     JNZ        LAB_0040ed5e
    //                               LAB_0040ed82                                                 XREF[1]:     0040ed6a(j)  
    //         0040ed82     XOR        EAX,EAX
    //         0040ed84     JMP        LAB_0040ed8b
    //                               LAB_0040ed86                                                 XREF[2]:     0040ed66(j), 0040ed76(j)  
    //         0040ed86     SBB        EAX,EAX
    //         0040ed88     SBB        EAX,-0x1
    //                               LAB_0040ed8b                                                 XREF[1]:     0040ed84(j)  
    //         0040ed8b     TEST       EAX,EAX
    //         0040ed8d     JNZ        LAB_0040ed97
    //                              aipbook.cpp:148 (2)
    //         0040ed8f     MOV        AL,0x2
    //                              aipbook.cpp:168 (6)
    //         0040ed91     POP        EDI
    //         0040ed92     POP        ESI
    //         0040ed93     POP        EBX
    //         0040ed94     RET        0x4
    //                               LAB_0040ed97                                                 XREF[1]:     0040ed8d(j)  
    //                              aipbook.cpp:149 (56)
    //         0040ed97     MOV        ESI,s_HealthLost                                 = 48h
    //         0040ed9c     MOV        EAX,EDI
    //                               LAB_0040ed9e                                                 XREF[1]:     0040edc0(j)  
    //         0040ed9e     MOV        DL,byte ptr [EAX]
    //         0040eda0     MOV        BL,byte ptr [ESI]=>s_HealthLost                  = 48h
    //                                                                                  = 61h
    //         0040eda2     MOV        this,DL
    //         0040eda4     CMP        DL,BL
    //         0040eda6     JNZ        LAB_0040edc6
    //         0040eda8     TEST       this,this
    //         0040edaa     JZ         LAB_0040edc2
    //         0040edac     MOV        DL,byte ptr [EAX + 0x1]
    //         0040edaf     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5d1            = 65h
    //                                                                                  = "lthLost"
    //         0040edb2     MOV        this,DL
    //         0040edb4     CMP        DL,BL
    //         0040edb6     JNZ        LAB_0040edc6
    //         0040edb8     ADD        EAX,0x2
    //         0040edbb     ADD        ESI,0x2
    //         0040edbe     TEST       this,this
    //         0040edc0     JNZ        LAB_0040ed9e
    //                               LAB_0040edc2                                                 XREF[1]:     0040edaa(j)  
    //         0040edc2     XOR        EAX,EAX
    //         0040edc4     JMP        LAB_0040edcb
    //                               LAB_0040edc6                                                 XREF[2]:     0040eda6(j), 0040edb6(j)  
    //         0040edc6     SBB        EAX,EAX
    //         0040edc8     SBB        EAX,-0x1
    //                               LAB_0040edcb                                                 XREF[1]:     0040edc4(j)  
    //         0040edcb     TEST       EAX,EAX
    //         0040edcd     JNZ        LAB_0040edd7
    //                              aipbook.cpp:150 (2)
    //         0040edcf     MOV        AL,0x3
    //                              aipbook.cpp:168 (6)
    //         0040edd1     POP        EDI
    //         0040edd2     POP        ESI
    //         0040edd3     POP        EBX
    //         0040edd4     RET        0x4
    //                               LAB_0040edd7                                                 XREF[1]:     0040edcd(j)  
    //                              aipbook.cpp:151 (56)
    //         0040edd7     MOV        ESI,s_DamageToGroup                              = 44h
    //         0040eddc     MOV        EAX,EDI
    //                               LAB_0040edde                                                 XREF[1]:     0040ee00(j)  
    //         0040edde     MOV        DL,byte ptr [EAX]
    //         0040ede0     MOV        BL,byte ptr [ESI]=>s_DamageToGroup               = 44h
    //                                                                                  = 6Dh
    //         0040ede2     MOV        this,DL
    //         0040ede4     CMP        DL,BL
    //         0040ede6     JNZ        LAB_0040ee06
    //         0040ede8     TEST       this,this
    //         0040edea     JZ         LAB_0040ee02
    //         0040edec     MOV        DL,byte ptr [EAX + 0x1]
    //         0040edef     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5c1            = 61h
    //                                                                                  = "ageToGroup"
    //         0040edf2     MOV        this,DL
    //         0040edf4     CMP        DL,BL
    //         0040edf6     JNZ        LAB_0040ee06
    //         0040edf8     ADD        EAX,0x2
    //         0040edfb     ADD        ESI,0x2
    //         0040edfe     TEST       this,this
    //         0040ee00     JNZ        LAB_0040edde
    //                               LAB_0040ee02                                                 XREF[1]:     0040edea(j)  
    //         0040ee02     XOR        EAX,EAX
    //         0040ee04     JMP        LAB_0040ee0b
    //                               LAB_0040ee06                                                 XREF[2]:     0040ede6(j), 0040edf6(j)  
    //         0040ee06     SBB        EAX,EAX
    //         0040ee08     SBB        EAX,-0x1
    //                               LAB_0040ee0b                                                 XREF[1]:     0040ee04(j)  
    //         0040ee0b     TEST       EAX,EAX
    //         0040ee0d     JNZ        LAB_0040ee17
    //                              aipbook.cpp:152 (2)
    //         0040ee0f     MOV        AL,0x4
    //                              aipbook.cpp:168 (6)
    //         0040ee11     POP        EDI
    //         0040ee12     POP        ESI
    //         0040ee13     POP        EBX
    //         0040ee14     RET        0x4
    //                               LAB_0040ee17                                                 XREF[1]:     0040ee0d(j)  
    //                              aipbook.cpp:153 (56)
    //         0040ee17     MOV        ESI,s_DamageToAnyGroup                           = 44h
    //         0040ee1c     MOV        EAX,EDI
    //                               LAB_0040ee1e                                                 XREF[1]:     0040ee40(j)  
    //         0040ee1e     MOV        DL,byte ptr [EAX]
    //         0040ee20     MOV        BL,byte ptr [ESI]=>s_DamageToAnyGroup            = 44h
    //                                                                                  = 6Dh
    //         0040ee22     MOV        this,DL
    //         0040ee24     CMP        DL,BL
    //         0040ee26     JNZ        LAB_0040ee46
    //         0040ee28     TEST       this,this
    //         0040ee2a     JZ         LAB_0040ee42
    //         0040ee2c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ee2f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5ad            = 61h
    //                                                                                  = "ageToAnyGroup"
    //         0040ee32     MOV        this,DL
    //         0040ee34     CMP        DL,BL
    //         0040ee36     JNZ        LAB_0040ee46
    //         0040ee38     ADD        EAX,0x2
    //         0040ee3b     ADD        ESI,0x2
    //         0040ee3e     TEST       this,this
    //         0040ee40     JNZ        LAB_0040ee1e
    //                               LAB_0040ee42                                                 XREF[1]:     0040ee2a(j)  
    //         0040ee42     XOR        EAX,EAX
    //         0040ee44     JMP        LAB_0040ee4b
    //                               LAB_0040ee46                                                 XREF[2]:     0040ee26(j), 0040ee36(j)  
    //         0040ee46     SBB        EAX,EAX
    //         0040ee48     SBB        EAX,-0x1
    //                               LAB_0040ee4b                                                 XREF[1]:     0040ee44(j)  
    //         0040ee4b     TEST       EAX,EAX
    //         0040ee4d     JNZ        LAB_0040ee57
    //                              aipbook.cpp:154 (2)
    //         0040ee4f     MOV        AL,0x5
    //                              aipbook.cpp:168 (6)
    //         0040ee51     POP        EDI
    //         0040ee52     POP        ESI
    //         0040ee53     POP        EBX
    //         0040ee54     RET        0x4
    //                               LAB_0040ee57                                                 XREF[1]:     0040ee4d(j)  
    //                              aipbook.cpp:155 (56)
    //         0040ee57     MOV        ESI,s_Level1EnemySighted                         = 4Ch
    //         0040ee5c     MOV        EAX,EDI
    //                               LAB_0040ee5e                                                 XREF[1]:     0040ee80(j)  
    //         0040ee5e     MOV        DL,byte ptr [EAX]
    //         0040ee60     MOV        BL,byte ptr [ESI]=>s_Level1EnemySighted          = 4Ch
    //                                                                                  = 76h
    //         0040ee62     MOV        this,DL
    //         0040ee64     CMP        DL,BL
    //         0040ee66     JNZ        LAB_0040ee86
    //         0040ee68     TEST       this,this
    //         0040ee6a     JZ         LAB_0040ee82
    //         0040ee6c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ee6f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f599            = 65h
    //                                                                                  = "el1EnemySighted"
    //         0040ee72     MOV        this,DL
    //         0040ee74     CMP        DL,BL
    //         0040ee76     JNZ        LAB_0040ee86
    //         0040ee78     ADD        EAX,0x2
    //         0040ee7b     ADD        ESI,0x2
    //         0040ee7e     TEST       this,this
    //         0040ee80     JNZ        LAB_0040ee5e
    //                               LAB_0040ee82                                                 XREF[1]:     0040ee6a(j)  
    //         0040ee82     XOR        EAX,EAX
    //         0040ee84     JMP        LAB_0040ee8b
    //                               LAB_0040ee86                                                 XREF[2]:     0040ee66(j), 0040ee76(j)  
    //         0040ee86     SBB        EAX,EAX
    //         0040ee88     SBB        EAX,-0x1
    //                               LAB_0040ee8b                                                 XREF[1]:     0040ee84(j)  
    //         0040ee8b     TEST       EAX,EAX
    //         0040ee8d     JNZ        LAB_0040ee97
    //                              aipbook.cpp:156 (2)
    //         0040ee8f     MOV        AL,0x6
    //                              aipbook.cpp:168 (6)
    //         0040ee91     POP        EDI
    //         0040ee92     POP        ESI
    //         0040ee93     POP        EBX
    //         0040ee94     RET        0x4
    //                               LAB_0040ee97                                                 XREF[1]:     0040ee8d(j)  
    //                              aipbook.cpp:157 (56)
    //         0040ee97     MOV        ESI,s_Level2EnemySighted                         = 4Ch
    //         0040ee9c     MOV        EAX,EDI
    //                               LAB_0040ee9e                                                 XREF[1]:     0040eec0(j)  
    //         0040ee9e     MOV        DL,byte ptr [EAX]
    //         0040eea0     MOV        BL,byte ptr [ESI]=>s_Level2EnemySighted          = 4Ch
    //                                                                                  = 76h
    //         0040eea2     MOV        this,DL
    //         0040eea4     CMP        DL,BL
    //         0040eea6     JNZ        LAB_0040eec6
    //         0040eea8     TEST       this,this
    //         0040eeaa     JZ         LAB_0040eec2
    //         0040eeac     MOV        DL,byte ptr [EAX + 0x1]
    //         0040eeaf     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f585            = 65h
    //                                                                                  = "el2EnemySighted"
    //         0040eeb2     MOV        this,DL
    //         0040eeb4     CMP        DL,BL
    //         0040eeb6     JNZ        LAB_0040eec6
    //         0040eeb8     ADD        EAX,0x2
    //         0040eebb     ADD        ESI,0x2
    //         0040eebe     TEST       this,this
    //         0040eec0     JNZ        LAB_0040ee9e
    //                               LAB_0040eec2                                                 XREF[1]:     0040eeaa(j)  
    //         0040eec2     XOR        EAX,EAX
    //         0040eec4     JMP        LAB_0040eecb
    //                               LAB_0040eec6                                                 XREF[2]:     0040eea6(j), 0040eeb6(j)  
    //         0040eec6     SBB        EAX,EAX
    //         0040eec8     SBB        EAX,-0x1
    //                               LAB_0040eecb                                                 XREF[1]:     0040eec4(j)  
    //         0040eecb     TEST       EAX,EAX
    //         0040eecd     JNZ        LAB_0040eed7
    //                              aipbook.cpp:158 (2)
    //         0040eecf     MOV        AL,0x7
    //                              aipbook.cpp:168 (6)
    //         0040eed1     POP        EDI
    //         0040eed2     POP        ESI
    //         0040eed3     POP        EBX
    //         0040eed4     RET        0x4
    //                               LAB_0040eed7                                                 XREF[1]:     0040eecd(j)  
    //                              aipbook.cpp:159 (56)
    //         0040eed7     MOV        ESI,s_DeathOfGroup                               = 44h
    //         0040eedc     MOV        EAX,EDI
    //                               LAB_0040eede                                                 XREF[1]:     0040ef00(j)  
    //         0040eede     MOV        DL,byte ptr [EAX]
    //         0040eee0     MOV        BL,byte ptr [ESI]=>s_DeathOfGroup                = 44h
    //                                                                                  = 61h
    //         0040eee2     MOV        this,DL
    //         0040eee4     CMP        DL,BL
    //         0040eee6     JNZ        LAB_0040ef06
    //         0040eee8     TEST       this,this
    //         0040eeea     JZ         LAB_0040ef02
    //         0040eeec     MOV        DL,byte ptr [EAX + 0x1]
    //         0040eeef     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f575            = 65h
    //                                                                                  = "thOfGroup"
    //         0040eef2     MOV        this,DL
    //         0040eef4     CMP        DL,BL
    //         0040eef6     JNZ        LAB_0040ef06
    //         0040eef8     ADD        EAX,0x2
    //         0040eefb     ADD        ESI,0x2
    //         0040eefe     TEST       this,this
    //         0040ef00     JNZ        LAB_0040eede
    //                               LAB_0040ef02                                                 XREF[1]:     0040eeea(j)  
    //         0040ef02     XOR        EAX,EAX
    //         0040ef04     JMP        LAB_0040ef0b
    //                               LAB_0040ef06                                                 XREF[2]:     0040eee6(j), 0040eef6(j)  
    //         0040ef06     SBB        EAX,EAX
    //         0040ef08     SBB        EAX,-0x1
    //                               LAB_0040ef0b                                                 XREF[1]:     0040ef04(j)  
    //         0040ef0b     TEST       EAX,EAX
    //         0040ef0d     JNZ        LAB_0040ef17
    //                              aipbook.cpp:160 (2)
    //         0040ef0f     MOV        AL,0x8
    //                              aipbook.cpp:168 (6)
    //         0040ef11     POP        EDI
    //         0040ef12     POP        ESI
    //         0040ef13     POP        EBX
    //         0040ef14     RET        0x4
    //                               LAB_0040ef17                                                 XREF[1]:     0040ef0d(j)  
    //                              aipbook.cpp:161 (56)
    //         0040ef17     MOV        ESI,s_HealOfGroup                                = 48h
    //         0040ef1c     MOV        EAX,EDI
    //                               LAB_0040ef1e                                                 XREF[1]:     0040ef40(j)  
    //         0040ef1e     MOV        DL,byte ptr [EAX]
    //         0040ef20     MOV        BL,byte ptr [ESI]=>s_HealOfGroup                 = 48h
    //                                                                                  = 61h
    //         0040ef22     MOV        this,DL
    //         0040ef24     CMP        DL,BL
    //         0040ef26     JNZ        LAB_0040ef46
    //         0040ef28     TEST       this,this
    //         0040ef2a     JZ         LAB_0040ef42
    //         0040ef2c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ef2f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f569            = 65h
    //                                                                                  = "lOfGroup"
    //         0040ef32     MOV        this,DL
    //         0040ef34     CMP        DL,BL
    //         0040ef36     JNZ        LAB_0040ef46
    //         0040ef38     ADD        EAX,0x2
    //         0040ef3b     ADD        ESI,0x2
    //         0040ef3e     TEST       this,this
    //         0040ef40     JNZ        LAB_0040ef1e
    //                               LAB_0040ef42                                                 XREF[1]:     0040ef2a(j)  
    //         0040ef42     XOR        EAX,EAX
    //         0040ef44     JMP        LAB_0040ef4b
    //                               LAB_0040ef46                                                 XREF[2]:     0040ef26(j), 0040ef36(j)  
    //         0040ef46     SBB        EAX,EAX
    //         0040ef48     SBB        EAX,-0x1
    //                               LAB_0040ef4b                                                 XREF[1]:     0040ef44(j)  
    //         0040ef4b     TEST       EAX,EAX
    //         0040ef4d     JNZ        LAB_0040ef57
    //                              aipbook.cpp:162 (2)
    //         0040ef4f     MOV        AL,0x9
    //                              aipbook.cpp:168 (6)
    //         0040ef51     POP        EDI
    //         0040ef52     POP        ESI
    //         0040ef53     POP        EBX
    //         0040ef54     RET        0x4
    //                               LAB_0040ef57                                                 XREF[1]:     0040ef4d(j)  
    //                              aipbook.cpp:163 (56)
    //         0040ef57     MOV        ESI,s_Immediate                                  = 49h
    //         0040ef5c     MOV        EAX,EDI
    //                               LAB_0040ef5e                                                 XREF[1]:     0040ef80(j)  
    //         0040ef5e     MOV        DL,byte ptr [EAX]
    //         0040ef60     MOV        BL,byte ptr [ESI]=>s_Immediate                   = 49h
    //                                                                                  = 6Dh
    //         0040ef62     MOV        this,DL
    //         0040ef64     CMP        DL,BL
    //         0040ef66     JNZ        LAB_0040ef86
    //         0040ef68     TEST       this,this
    //         0040ef6a     JZ         LAB_0040ef82
    //         0040ef6c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040ef6f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f55d            = 6Dh
    //                                                                                  = "ediate"
    //         0040ef72     MOV        this,DL
    //         0040ef74     CMP        DL,BL
    //         0040ef76     JNZ        LAB_0040ef86
    //         0040ef78     ADD        EAX,0x2
    //         0040ef7b     ADD        ESI,0x2
    //         0040ef7e     TEST       this,this
    //         0040ef80     JNZ        LAB_0040ef5e
    //                               LAB_0040ef82                                                 XREF[1]:     0040ef6a(j)  
    //         0040ef82     XOR        EAX,EAX
    //         0040ef84     JMP        LAB_0040ef8b
    //                               LAB_0040ef86                                                 XREF[2]:     0040ef66(j), 0040ef76(j)  
    //         0040ef86     SBB        EAX,EAX
    //         0040ef88     SBB        EAX,-0x1
    //                               LAB_0040ef8b                                                 XREF[1]:     0040ef84(j)  
    //         0040ef8b     TEST       EAX,EAX
    //         0040ef8d     JNZ        LAB_0040ef97
    //                              aipbook.cpp:164 (2)
    //         0040ef8f     MOV        AL,0xa
    //                              aipbook.cpp:168 (6)
    //         0040ef91     POP        EDI
    //         0040ef92     POP        ESI
    //         0040ef93     POP        EBX
    //         0040ef94     RET        0x4
    //                               LAB_0040ef97                                                 XREF[1]:     0040ef8d(j)  
    //                              aipbook.cpp:165 (54)
    //         0040ef97     MOV        ESI,s_Time                                       = 54h
    //         0040ef9c     MOV        EAX,EDI
    //                               LAB_0040ef9e                                                 XREF[1]:     0040efc0(j)  
    //         0040ef9e     MOV        DL,byte ptr [EAX]
    //         0040efa0     MOV        BL,byte ptr [ESI]=>s_Time                        = 54h
    //                                                                                  = 6Dh
    //         0040efa2     MOV        this,DL
    //         0040efa4     CMP        DL,BL
    //         0040efa6     JNZ        LAB_0040efd3
    //         0040efa8     TEST       this,this
    //         0040efaa     JZ         LAB_0040efc2
    //         0040efac     MOV        DL,byte ptr [EAX + 0x1]
    //         0040efaf     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f555            = 69h
    //                                                                                  = 65h
    //         0040efb2     MOV        this,DL
    //         0040efb4     CMP        DL,BL
    //         0040efb6     JNZ        LAB_0040efd3
    //         0040efb8     ADD        EAX,0x2
    //         0040efbb     ADD        ESI,0x2
    //         0040efbe     TEST       this,this
    //         0040efc0     JNZ        LAB_0040ef9e
    //                               LAB_0040efc2                                                 XREF[1]:     0040efaa(j)  
    //         0040efc2     XOR        EAX,EAX
    //         0040efc4     TEST       EAX,EAX
    //         0040efc6     SETNZ      AL
    //         0040efc9     DEC        EAX
    //         0040efca     AND        EAX,0xb
    //                              aipbook.cpp:168 (6)
    //         0040efcd     POP        EDI
    //         0040efce     POP        ESI
    //         0040efcf     POP        EBX
    //         0040efd0     RET        0x4
    //                               LAB_0040efd3                                                 XREF[2]:     0040efa6(j), 0040efb6(j)  
    //                              aipbook.cpp:165 (2)
    //         0040efd3     SBB        EAX,EAX
    //                              aipbook.cpp:168 (18)
    //         0040efd5     POP        EDI
    //         0040efd6     SBB        EAX,-0x1
    //         0040efd9     POP        ESI
    //         0040efda     TEST       EAX,EAX
    //         0040efdc     SETNZ      AL
    //         0040efdf     DEC        EAX
    //         0040efe0     POP        EBX
    //         0040efe1     AND        EAX,0xb
    //         0040efe4     RET        0x4
}

// Offset: 0x0040EFF0
char* convertToNameType(AIPlayPhaseTrigger* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: char * __thiscall AIPlayPhaseTrigger::convertToNameType(unsigned char)const                *
    //                              *********************************************************************************************************
    //                              char * __thiscall convertToNameType(AIPlayPhaseTrigger * this, uchar
    //              char *            EAX:4          <RETURN>
    //              AIPlayPhaseTri    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040eff0(R)  
    //                               ?convertToNameType@AIPlayPhaseTrigger@@IBEPADE@Z             XREF[1]:     nameType:0040ed03(c)  
    //                               AIPlayPhaseTrigger::convertToNameType
    //                              aipbook.cpp:173 (22)
    //         0040eff0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040eff4     AND        EAX,0xff
    //         0040eff9     DEC        EAX
    //         0040effa     CMP        EAX,0xa
    //         0040effd     JA         switchD_0040efff::default
    //                               switchD_0040efff::switchD
    //         0040efff     JMP        dword ptr [EAX*0x4 + switchD_0040efff::switchd   = 0040f006
    //                               switchD_0040efff::caseD_1                                    XREF[2]:     0040efff(j), 0040f068(*)  
    //                              aipbook.cpp:175 (5)
    //         0040f006     MOV        EAX,s_Gather                                     = 47h
    //                              aipbook.cpp:188 (3)
    //         0040f00b     RET        0x4
    //                               switchD_0040efff::caseD_2                                    XREF[2]:     0040efff(j), 0040f06c(*)  
    //                              aipbook.cpp:176 (5)
    //         0040f00e     MOV        EAX,s_Death                                      = 44h
    //                              aipbook.cpp:188 (3)
    //         0040f013     RET        0x4
    //                               switchD_0040efff::caseD_3                                    XREF[2]:     0040efff(j), 0040f070(*)  
    //                              aipbook.cpp:177 (5)
    //         0040f016     MOV        EAX,s_HealthLost                                 = 48h
    //                              aipbook.cpp:188 (3)
    //         0040f01b     RET        0x4
    //                               switchD_0040efff::caseD_4                                    XREF[2]:     0040efff(j), 0040f074(*)  
    //                              aipbook.cpp:178 (5)
    //         0040f01e     MOV        EAX,s_DamageToGroup                              = 44h
    //                              aipbook.cpp:188 (3)
    //         0040f023     RET        0x4
    //                               switchD_0040efff::caseD_5                                    XREF[2]:     0040efff(j), 0040f078(*)  
    //                              aipbook.cpp:179 (5)
    //         0040f026     MOV        EAX,s_DamageToAnyGroup                           = 44h
    //                              aipbook.cpp:188 (3)
    //         0040f02b     RET        0x4
    //                               switchD_0040efff::caseD_6                                    XREF[2]:     0040efff(j), 0040f07c(*)  
    //                              aipbook.cpp:180 (5)
    //         0040f02e     MOV        EAX,s_Level1EnemySighted                         = 4Ch
    //                              aipbook.cpp:188 (3)
    //         0040f033     RET        0x4
    //                               switchD_0040efff::caseD_7                                    XREF[2]:     0040efff(j), 0040f080(*)  
    //                              aipbook.cpp:181 (5)
    //         0040f036     MOV        EAX,s_Level2EnemySighted                         = 4Ch
    //                              aipbook.cpp:188 (3)
    //         0040f03b     RET        0x4
    //                               switchD_0040efff::caseD_8                                    XREF[2]:     0040efff(j), 0040f084(*)  
    //                              aipbook.cpp:182 (5)
    //         0040f03e     MOV        EAX,s_DeathOfGroup                               = 44h
    //                              aipbook.cpp:188 (3)
    //         0040f043     RET        0x4
    //                               switchD_0040efff::caseD_9                                    XREF[2]:     0040efff(j), 0040f088(*)  
    //                              aipbook.cpp:183 (5)
    //         0040f046     MOV        EAX,s_HealOfGroup                                = 48h
    //                              aipbook.cpp:188 (3)
    //         0040f04b     RET        0x4
    //                               switchD_0040efff::caseD_a                                    XREF[2]:     0040efff(j), 0040f08c(*)  
    //                              aipbook.cpp:184 (5)
    //         0040f04e     MOV        EAX,s_Immediate                                  = 49h
    //                              aipbook.cpp:188 (3)
    //         0040f053     RET        0x4
    //                               switchD_0040efff::caseD_b                                    XREF[2]:     0040efff(j), 0040f090(*)  
    //                              aipbook.cpp:185 (5)
    //         0040f056     MOV        EAX,s_Time                                       = 54h
    //                              aipbook.cpp:188 (3)
    //         0040f05b     RET        0x4
    //                               switchD_0040efff::default                                    XREF[1]:     0040effd(j)  
    //                              aipbook.cpp:187 (5)
    //         0040f05e     MOV        EAX,s_Invalid                                    = "Invalid"
    //                              aipbook.cpp:188 (49)
    //         0040f063     RET        0x4
}

// Offset: 0x0040F066
undefined FUN_0040f066() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0040f066()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0040f066
    //         0040f066     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040efff::switchdataD_0040f068                       XREF[1]:     convertToNameType:0040efff(*)  
}

// Offset: 0x0040F0A0
undefined AIPlayPhase(AIPlayPhase* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayPhase::AIPlayPhase(void)                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayPhase(AIPlayPhase * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayPhase *     ECX:4 (auto)   this
    //                               ??0AIPlayPhase@@QAE@XZ                                       XREF[1]:     AIPlay:0040f325(c)  
    //                               AIPlayPhase::AIPlayPhase
    //                              aipbook.cpp:194 (28)
    //         0040f0a0     PUSH       EBX
    //         0040f0a1     PUSH       ESI
    //         0040f0a2     MOV        EBX,this
    //         0040f0a4     PUSH       EDI
    //         0040f0a5     MOV        ESI,EBX
    //         0040f0a7     MOV        EDI,0x5
    //                               LAB_0040f0ac                                                 XREF[1]:     0040f0b7(j)  
    //         0040f0ac     MOV        this,ESI
    //         0040f0ae     CALL       AIPlayPhaseCommand::AIPlayPhaseCommand           undefined AIPlayPhaseCommand(AIPlayPhaseComma
    //         0040f0b3     ADD        ESI,0x10
    //         0040f0b6     DEC        EDI
    //         0040f0b7     JNZ        LAB_0040f0ac
    //         0040f0b9     LEA        ESI,[EBX + 0x50]
    //                              aipbook.cpp:196 (31)
    //         0040f0bc     MOV        EDI,0x3
    //                               LAB_0040f0c1                                                 XREF[1]:     0040f0cc(j)  
    //         0040f0c1     MOV        this,ESI
    //         0040f0c3     CALL       AIPlayPhaseTrigger::AIPlayPhaseTrigger           undefined AIPlayPhaseTrigger(AIPlayPhaseTrigg
    //         0040f0c8     ADD        ESI,0x14
    //         0040f0cb     DEC        EDI
    //         0040f0cc     JNZ        LAB_0040f0c1
    //         0040f0ce     MOV        this,EBX
    //         0040f0d0     CALL       AIPlayPhase::initialize                          void initialize(AIPlayPhase * this)
    //         0040f0d5     POP        EDI
    //         0040f0d6     MOV        EAX,EBX
    //         0040f0d8     POP        ESI
    //         0040f0d9     POP        EBX
    //         0040f0da     RET
}

// Offset: 0x0040F110
AIPlayPhaseCommand* command(AIPlayPhase* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIPlayPhaseCommand * __thiscall AIPlayPhase::command(int)                               *
    //                              *********************************************************************************************************
    //                              AIPlayPhaseCommand * __thiscall command(AIPlayPhase * this, int para
    //              AIPlayPhaseCom    EAX:4          <RETURN>
    //              AIPlayPhase *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f110(R)  
    //                               ?command@AIPlayPhase@@QAEPAVAIPlayPhaseCommand@@H@Z          XREF[7]:     groupGivenCommandOnPhase:0040f9e8(
    //                               AIPlayPhase::command                                                      groupGivenCommandOnPhase:0040f9f8(
    //                                                                                                         locationsOnMap:0040fbd0(c), 
    //                                                                                                         loadPlays:004111e7(c), 
    //                                                                                                         updateGroup:0041444d(c), 
    //                                                                                                         selectNewPlayPhase:004148e5(c), 
    //                                                                                                         objectToAttackWithPlay:004dc5a8(c)
    //                              aipbook.cpp:201 (13)
    //         0040f110     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f114     TEST       EAX,EAX
    //         0040f116     JL         LAB_0040f125
    //         0040f118     CMP        EAX,0x5
    //         0040f11b     JGE        LAB_0040f125
    //                              aipbook.cpp:203 (5)
    //         0040f11d     SHL        EAX,0x4
    //         0040f120     ADD        EAX,this
    //                              aipbook.cpp:205 (3)
    //         0040f122     RET        0x4
    //                               LAB_0040f125                                                 XREF[2]:     0040f116(j), 0040f11b(j)  
    //                              aipbook.cpp:204 (2)
    //         0040f125     XOR        EAX,EAX
    //                              aipbook.cpp:205 (3)
    //         0040f127     RET        0x4
}

// Offset: 0x0040F130
AIPlayPhaseTrigger* trigger(AIPlayPhase* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIPlayPhaseTrigger * __thiscall AIPlayPhase::trigger(int)                               *
    //                              *********************************************************************************************************
    //                              AIPlayPhaseTrigger * __thiscall trigger(AIPlayPhase * this, int para
    //              AIPlayPhaseTri    EAX:4          <RETURN>
    //              AIPlayPhase *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f130(R)  
    //                               ?trigger@AIPlayPhase@@QAEPAVAIPlayPhaseTrigger@@H@Z          XREF[4]:     gatherTolerance:0040f4a7(c), 
    //                               AIPlayPhase::trigger                                                      loadPlays:00411288(c), 
    //                                                                                                         updateGroup:004143d5(c), 
    //                                                                                                         processGroupNotify:0041958c(c)  
    //                              aipbook.cpp:210 (13)
    //         0040f130     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f134     TEST       EAX,EAX
    //         0040f136     JL         LAB_0040f149
    //         0040f138     CMP        EAX,0x3
    //         0040f13b     JGE        LAB_0040f149
    //                              aipbook.cpp:212 (9)
    //         0040f13d     ADD        EAX,0x4
    //         0040f140     LEA        EAX,[EAX + EAX*0x4]
    //         0040f143     LEA        EAX,[this->commands[0].groupValue + EAX*0x4]
    //                              aipbook.cpp:214 (3)
    //         0040f146     RET        0x4
    //                               LAB_0040f149                                                 XREF[2]:     0040f136(j), 0040f13b(j)  
    //                              aipbook.cpp:213 (2)
    //         0040f149     XOR        EAX,EAX
    //                              aipbook.cpp:214 (3)
    //         0040f14b     RET        0x4
}

// Offset: 0x0040F150
int addCommand(AIPlayPhase* this_, AIPlayPhaseCommand* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayPhase::addCommand(class AIPlayPhaseCommand &)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall addCommand(AIPlayPhase * this, AIPlayPhaseCommand * p
    //              int               EAX:4          <RETURN>
    //              AIPlayPhase *     ECX:4 (auto)   this
    //              AIPlayPhaseCom    Stack[0x4]:4   param_1                   XREF[1]:     0040f16d(R)  
    //                               ?addCommand@AIPlayPhase@@QAEHAAVAIPlayPhaseCommand@@@Z       XREF[2]:     loadPlays:00410e0c(c), 
    //                               AIPlayPhase::addCommand                                                   loadPlays:0041126a(c)  
    //                              aipbook.cpp:219 (5)
    //         0040f150     XOR        EAX,EAX
    //         0040f152     LEA        EDX,[ECX + this+0x1]
    //                               LAB_0040f155                                                 XREF[1]:     0040f161(j)  
    //                              aipbook.cpp:222 (14)
    //         0040f155     CMP        byte ptr [EDX],0x0
    //         0040f158     JZ         LAB_0040f168
    //         0040f15a     INC        EAX
    //         0040f15b     ADD        EDX,0x10
    //         0040f15e     CMP        EAX,0x5
    //         0040f161     JL         LAB_0040f155
    //                              aipbook.cpp:231 (2)
    //         0040f163     XOR        EAX,EAX
    //                              aipbook.cpp:232 (3)
    //         0040f165     RET        0x4
    //                               LAB_0040f168                                                 XREF[1]:     0040f158(j)  
    //                              aipbook.cpp:223 (13)
    //         0040f168     SHL        EAX,0x4
    //         0040f16b     ADD        EAX,this
    //         0040f16d     MOV        this,dword ptr [ESP + param_1]
    //         0040f171     MOV        DL,byte ptr [this->commands[0].groupValue]
    //         0040f173     MOV        byte ptr [EAX],DL
    //                              aipbook.cpp:224 (6)
    //         0040f175     MOV        DL,byte ptr [ECX + this+0x1]
    //         0040f178     MOV        byte ptr [EAX + 0x1],DL
    //                              aipbook.cpp:225 (6)
    //         0040f17b     MOV        EDX,dword ptr [ECX + this+0x4]
    //         0040f17e     MOV        dword ptr [EAX + 0x4],EDX
    //                              aipbook.cpp:226 (6)
    //         0040f181     MOV        EDX,dword ptr [ECX + this+0x8]
    //         0040f184     MOV        dword ptr [EAX + 0x8],EDX
    //                              aipbook.cpp:227 (6)
    //         0040f187     MOV        this,dword ptr [ECX + this+0xc]
    //         0040f18a     MOV        dword ptr [EAX + 0xc],this
    //                              aipbook.cpp:228 (5)
    //         0040f18d     MOV        EAX,0x1
    //                              aipbook.cpp:232 (3)
    //         0040f192     RET        0x4
}

// Offset: 0x0040F1A0
int addTrigger(AIPlayPhase* this_, AIPlayPhaseTrigger* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayPhase::addTrigger(class AIPlayPhaseTrigger &)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall addTrigger(AIPlayPhase * this, AIPlayPhaseTrigger * p
    //              int               EAX:4          <RETURN>
    //              AIPlayPhase *     ECX:4 (auto)   this
    //              AIPlayPhaseTri    Stack[0x4]:4   param_1                   XREF[1]:     0040f1c7(R)  
    //                               ?addTrigger@AIPlayPhase@@QAEHAAVAIPlayPhaseTrigger@@@Z       XREF[3]:     loadPlays:00410ed9(c), 
    //                               AIPlayPhase::addTrigger                                                   loadPlays:00410fae(c), 
    //                                                                                                         loadPlays:00411292(c)  
    //                              aipbook.cpp:237 (4)
    //         0040f1a0     PUSH       EBX
    //         0040f1a1     PUSH       ESI
    //         0040f1a2     MOV        ESI,this
    //                              aipbook.cpp:239 (5)
    //         0040f1a4     XOR        EAX,EAX
    //         0040f1a6     LEA        EDX,[ESI + 0x50]
    //                               LAB_0040f1a9                                                 XREF[1]:     0040f1b5(j)  
    //                              aipbook.cpp:240 (14)
    //         0040f1a9     CMP        byte ptr [EDX],0x0
    //         0040f1ac     JZ         LAB_0040f1be
    //         0040f1ae     INC        EAX
    //         0040f1af     ADD        EDX,0x14
    //         0040f1b2     CMP        EAX,0x3
    //         0040f1b5     JL         LAB_0040f1a9
    //                              aipbook.cpp:250 (2)
    //         0040f1b7     XOR        EAX,EAX
    //                              aipbook.cpp:251 (5)
    //         0040f1b9     POP        ESI
    //         0040f1ba     POP        EBX
    //         0040f1bb     RET        0x4
    //                               LAB_0040f1be                                                 XREF[1]:     0040f1ac(j)  
    //                              aipbook.cpp:241 (3)
    //         0040f1be     LEA        EDX,[EAX + 0x4]
    //                              aipbook.cpp:242 (24)
    //         0040f1c1     LEA        EAX,[EAX + EAX*0x4]
    //         0040f1c4     LEA        this,[EDX + EDX*0x4]
    //         0040f1c7     MOV        EDX,dword ptr [ESP + param_1]
    //         0040f1cb     LEA        EAX,[ESI + EAX*0x4]
    //         0040f1ce     MOV        BL,byte ptr [EDX]
    //         0040f1d0     MOV        byte ptr [ESI + this->commands[0].groupValue*0
    //         0040f1d3     MOV        this,dword ptr [EDX + 0x4]
    //         0040f1d6     MOV        dword ptr [EAX + 0x54],this
    //                              aipbook.cpp:243 (6)
    //         0040f1d9     MOV        this,dword ptr [EDX + 0x8]
    //         0040f1dc     MOV        dword ptr [EAX + 0x58],this
    //                              aipbook.cpp:244 (6)
    //         0040f1df     MOV        this,byte ptr [EDX + 0xc]
    //         0040f1e2     MOV        byte ptr [EAX + 0x5c],this
    //                              aipbook.cpp:245 (6)
    //         0040f1e5     MOV        this,byte ptr [EDX + 0xd]
    //         0040f1e8     MOV        byte ptr [EAX + 0x5d],this
    //                              aipbook.cpp:246 (6)
    //         0040f1eb     MOV        EDX,dword ptr [EDX + 0x10]
    //         0040f1ee     MOV        dword ptr [EAX + 0x60],EDX
    //                              aipbook.cpp:247 (5)
    //         0040f1f1     MOV        EAX,0x1
    //                              aipbook.cpp:251 (5)
    //         0040f1f6     POP        ESI
    //         0040f1f7     POP        EBX
    //         0040f1f8     RET        0x4
}

// Offset: 0x0040F200
void initialize(AIPlayPhase* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall AIPlayPhase::initialize(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall initialize(AIPlayPhase * this)
    //              void              <VOID>         <RETURN>
    //              AIPlayPhase *     ECX:4 (auto)   this
    //                               ?initialize@AIPlayPhase@@IAEXXZ                              XREF[1]:     AIPlayPhase:0040f0d0(c)  
    //                               AIPlayPhase::initialize
    //                              aipbook.cpp:256 (8)
    //         0040f200     LEA        EAX,[ECX + this+0x1]
    //         0040f203     MOV        EDX,0x5
    //                               LAB_0040f208                                                 XREF[1]:     0040f20f(j)  
    //                              aipbook.cpp:258 (9)
    //         0040f208     MOV        byte ptr [EAX],0x0
    //         0040f20b     ADD        EAX,0x10
    //         0040f20e     DEC        EDX
    //         0040f20f     JNZ        LAB_0040f208
    //                              aipbook.cpp:261 (18)
    //         0040f211     LEA        EAX,[ECX + this->triggers[0].typeValue]
    //         0040f214     MOV        this,0x3
    //                               LAB_0040f219                                                 XREF[1]:     0040f220(j)  
    //         0040f219     MOV        byte ptr [EAX],0x0
    //         0040f21c     ADD        EAX,0x14
    //         0040f21f     DEC        this
    //         0040f220     JNZ        LAB_0040f219
    //         0040f222     RET
}

// Offset: 0x0040F230
undefined AIPlayGroup(AIPlayGroup* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayGroup::AIPlayGroup(void)                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayGroup(AIPlayGroup * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayGroup *     ECX:4 (auto)   this
    //                               ??0AIPlayGroup@@QAE@XZ                                       XREF[1]:     AIPlay:0040f30d(c)  
    //                               AIPlayGroup::AIPlayGroup
    //                              aipbook.cpp:267 (3)
    //         0040f230     PUSH       ESI
    //         0040f231     MOV        ESI,this
    //                              aipbook.cpp:268 (5)
    //         0040f233     CALL       AIPlayGroup::initialize                          void initialize(AIPlayGroup * this)
    //                              aipbook.cpp:269 (4)
    //         0040f238     MOV        EAX,ESI
    //         0040f23a     POP        ESI
    //         0040f23b     RET
}

// Offset: 0x0040F240
uchar minimum(AIPlayGroup* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlayGroup::minimum(int)const                                       *
    //                              *********************************************************************************************************
    //                              uchar __thiscall minimum(AIPlayGroup * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlayGroup *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f240(R)  
    //                               ?minimum@AIPlayGroup@@QBEEH@Z                                XREF[3]:     fillGroups:0040f63b(c), 
    //                               AIPlayGroup::minimum                                                      fillGroups:0040f946(c), 
    //                                                                                                         loadPlays:00411165(c)  
    //                              aipbook.cpp:274 (13)
    //         0040f240     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f244     TEST       EAX,EAX
    //         0040f246     JL         LAB_0040f253
    //         0040f248     CMP        EAX,0x6
    //         0040f24b     JGE        LAB_0040f253
    //                              aipbook.cpp:276 (3)
    //         0040f24d     MOV        AL,byte ptr [this->minValue[0] + EAX*0x1]
    //                              aipbook.cpp:278 (3)
    //         0040f250     RET        0x4
    //                               LAB_0040f253                                                 XREF[2]:     0040f246(j), 0040f24b(j)  
    //                              aipbook.cpp:277 (2)
    //         0040f253     XOR        AL,AL
    //                              aipbook.cpp:278 (3)
    //         0040f255     RET        0x4
}

// Offset: 0x0040F260
void setMinimum(AIPlayGroup* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayGroup::setMinimum(int,int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall setMinimum(AIPlayGroup * this, int param_1, int para
    //              void              <VOID>         <RETURN>
    //              AIPlayGroup *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f260(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040f26d(R)  
    //                               ?setMinimum@AIPlayGroup@@QAEXHH@Z                            XREF[2]:     loadPlays:00410c90(c), 
    //                               AIPlayGroup::setMinimum                                                   loadPlays:00411175(c)  
    //                              aipbook.cpp:283 (13)
    //         0040f260     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f264     TEST       EAX,EAX
    //         0040f266     JL         LAB_0040f274
    //         0040f268     CMP        EAX,0x6
    //         0040f26b     JGE        LAB_0040f274
    //                              aipbook.cpp:285 (7)
    //         0040f26d     MOV        DL,byte ptr [ESP + param_2]
    //         0040f271     MOV        byte ptr [this->minValue[0] + EAX*0x1],DL
    //                               LAB_0040f274                                                 XREF[2]:     0040f266(j), 0040f26b(j)  
    //                              aipbook.cpp:286 (3)
    //         0040f274     RET        0x8
}

// Offset: 0x0040F280
uchar maximum(AIPlayGroup* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlayGroup::maximum(int)const                                       *
    //                              *********************************************************************************************************
    //                              uchar __thiscall maximum(AIPlayGroup * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlayGroup *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f280(R)  
    //                               ?maximum@AIPlayGroup@@QBEEH@Z                                XREF[3]:     fillGroups:0040f7a4(c), 
    //                               AIPlayGroup::maximum                                                      fillGroups:0040f879(c), 
    //                                                                                                         loadPlays:0041117f(c)  
    //                              aipbook.cpp:291 (13)
    //         0040f280     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f284     TEST       EAX,EAX
    //         0040f286     JL         LAB_0040f294
    //         0040f288     CMP        EAX,0x6
    //         0040f28b     JGE        LAB_0040f294
    //                              aipbook.cpp:293 (4)
    //         0040f28d     MOV        AL,byte ptr [ECX + EAX*0x1 + this->maxValue[0]]
    //                              aipbook.cpp:295 (3)
    //         0040f291     RET        0x4
    //                               LAB_0040f294                                                 XREF[2]:     0040f286(j), 0040f28b(j)  
    //                              aipbook.cpp:294 (2)
    //         0040f294     OR         AL,0xff
    //                              aipbook.cpp:295 (3)
    //         0040f296     RET        0x4
}

// Offset: 0x0040F2A0
void setMaximum(AIPlayGroup* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayGroup::setMaximum(int,int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall setMaximum(AIPlayGroup * this, int param_1, int para
    //              void              <VOID>         <RETURN>
    //              AIPlayGroup *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f2a0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040f2ad(R)  
    //                               ?setMaximum@AIPlayGroup@@QAEXHH@Z                            XREF[2]:     loadPlays:00410cbd(c), 
    //                               AIPlayGroup::setMaximum                                                   loadPlays:0041118f(c)  
    //                              aipbook.cpp:300 (13)
    //         0040f2a0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f2a4     TEST       EAX,EAX
    //         0040f2a6     JL         LAB_0040f2b5
    //         0040f2a8     CMP        EAX,0x6
    //         0040f2ab     JGE        LAB_0040f2b5
    //                              aipbook.cpp:302 (8)
    //         0040f2ad     MOV        DL,byte ptr [ESP + param_2]
    //         0040f2b1     MOV        byte ptr [ECX + EAX*0x1 + this->maxValue[0]],DL
    //                               LAB_0040f2b5                                                 XREF[2]:     0040f2a6(j), 0040f2ab(j)  
    //                              aipbook.cpp:303 (3)
    //         0040f2b5     RET        0x8
}

// Offset: 0x0040F2C0
void initialize(AIPlayGroup* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall AIPlayGroup::initialize(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall initialize(AIPlayGroup * this)
    //              void              <VOID>         <RETURN>
    //              AIPlayGroup *     ECX:4 (auto)   this
    //                               ?initialize@AIPlayGroup@@IAEXXZ                              XREF[1]:     AIPlayGroup:0040f233(c)  
    //                               AIPlayGroup::initialize
    //                              aipbook.cpp:308 (13)
    //         0040f2c0     MOV        EDX,0xfffffffa
    //         0040f2c5     LEA        EAX,[ECX + this->maxValue[0]]
    //         0040f2c8     SUB        EDX,this
    //         0040f2ca     PUSH       ESI
    //         0040f2cb     XOR        this,this
    //                               LAB_0040f2cd                                                 XREF[1]:     0040f2da(j)  
    //                              aipbook.cpp:310 (3)
    //         0040f2cd     MOV        byte ptr [EAX + -0x6],this
    //                              aipbook.cpp:311 (12)
    //         0040f2d0     MOV        byte ptr [EAX],0xfe
    //         0040f2d3     INC        EAX
    //         0040f2d4     LEA        ESI,[EDX + EAX*0x1]
    //         0040f2d7     CMP        ESI,0x6
    //         0040f2da     JL         LAB_0040f2cd
    //                              aipbook.cpp:313 (2)
    //         0040f2dc     POP        ESI
    //         0040f2dd     RET
}

// Offset: 0x0040F2E0
undefined AIPlay(AIPlay* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlay::AIPlay(void)                                                               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlay(AIPlay * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //                               ??0AIPlay@@QAE@XZ                                            XREF[1]:     loadPlays:004103da(c)  
    //                               AIPlay::AIPlay
    //                              aipbook.cpp:326 (62)
    //         0040f2e0     PUSH       EBX
    //         0040f2e1     PUSH       EBP
    //         0040f2e2     PUSH       ESI
    //         0040f2e3     MOV        ESI,this
    //         0040f2e5     MOV        AL,0x1
    //         0040f2e7     MOV        EBX,0x5
    //         0040f2ec     MOV        byte ptr [ESI + 0x41],AL
    //         0040f2ef     MOV        byte ptr [ESI + 0x43],AL
    //         0040f2f2     MOV        byte ptr [ESI + 0x4f],AL
    //         0040f2f5     MOV        AL,0x32
    //         0040f2f7     PUSH       EDI
    //         0040f2f8     MOV        byte ptr [ESI + 0x42],0xff
    //         0040f2fc     MOV        byte ptr [ESI + 0x4e],0x0
    //         0040f300     MOV        byte ptr [ESI + 0x50],AL
    //         0040f303     MOV        byte ptr [ESI + 0x51],AL
    //         0040f306     LEA        EDI,[ESI + 0x53]
    //         0040f309     MOV        EBP,EBX
    //                               LAB_0040f30b                                                 XREF[1]:     0040f316(j)  
    //         0040f30b     MOV        this,EDI
    //         0040f30d     CALL       AIPlayGroup::AIPlayGroup                         undefined AIPlayGroup(AIPlayGroup * this)
    //         0040f312     ADD        EDI,0xc
    //         0040f315     DEC        EBP
    //         0040f316     JNZ        LAB_0040f30b
    //         0040f318     LEA        EDI,[ESI + 0x90]
    //                              aipbook.cpp:332 (51)
    //         0040f31e     MOV        EBP,0xa
    //                               LAB_0040f323                                                 XREF[1]:     0040f331(j)  
    //         0040f323     MOV        this,EDI
    //         0040f325     CALL       AIPlayPhase::AIPlayPhase                         undefined AIPlayPhase(AIPlayPhase * this)
    //         0040f32a     ADD        EDI,0x8c
    //         0040f330     DEC        EBP
    //         0040f331     JNZ        LAB_0040f323
    //         0040f333     MOV        this,0xffffffb7
    //         0040f338     LEA        EAX,[ESI + 0x49]
    //         0040f33b     SUB        this,ESI
    //                               LAB_0040f33d                                                 XREF[1]:     0040f348(j)  
    //         0040f33d     MOV        byte ptr [EAX + -0x5],BL
    //         0040f340     MOV        byte ptr [EAX],BL
    //         0040f342     INC        EAX
    //         0040f343     LEA        EDX,[this->nameValue[0] + EAX*0x1]
    //         0040f346     CMP        EDX,EBX
    //         0040f348     JL         LAB_0040f33d
    //         0040f34a     MOV        EAX,ESI
    //         0040f34c     POP        EDI
    //         0040f34d     POP        ESI
    //         0040f34e     POP        EBP
    //         0040f34f     POP        EBX
    //         0040f350     RET
}

// Offset: 0x0040F360
void setName(AIPlay* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlay::setName(char *)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall setName(AIPlay * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040f360(R)  
    //                               ?setName@AIPlay@@QAEXPAD@Z                                   XREF[2]:     loadPlays:004105d7(c), 
    //                               AIPlay::setName                                                           loadPlays:00411097(c)  
    //                              aipbook.cpp:337 (8)
    //         0040f360     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f364     TEST       EAX,EAX
    //         0040f366     JZ         LAB_0040f374
    //                              aipbook.cpp:340 (12)
    //         0040f368     PUSH       0x40
    //         0040f36a     PUSH       EAX
    //         0040f36b     PUSH       this
    //         0040f36c     CALL       strncpy                                          undefined strncpy()
    //         0040f371     ADD        ESP,0xc
    //                               LAB_0040f374                                                 XREF[1]:     0040f366(j)  
    //                              aipbook.cpp:341 (3)
    //         0040f374     RET        0x4
}

// Offset: 0x0040F380
int humanPlay(AIPlay* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::humanPlay(void)const                                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall humanPlay(AIPlay * this)
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //                               ?humanPlay@AIPlay@@QBEHXZ                                    XREF[1]:     objectToAttackWithPlay:004dc53b(c)
    //                               AIPlay::humanPlay
    //                              aipbook.cpp:346 (11)
    //         0040f380     CMP        byte ptr [this->nameValue[0]],0x48
    //         0040f383     JNZ        LAB_0040f391
    //         0040f385     CMP        byte ptr [ECX + this+0x1],0x50
    //         0040f389     JNZ        LAB_0040f391
    //                              aipbook.cpp:348 (5)
    //         0040f38b     MOV        EAX,0x1
    //                              aipbook.cpp:350 (1)
    //         0040f390     RET
    //                               LAB_0040f391                                                 XREF[2]:     0040f383(j), 0040f389(j)  
    //                              aipbook.cpp:349 (2)
    //         0040f391     XOR        EAX,EAX
    //                              aipbook.cpp:350 (1)
    //         0040f393     RET
}

// Offset: 0x0040F3A0
char* typeName(AIPlay* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall AIPlay::typeName(void)const                                                 *
    //                              *********************************************************************************************************
    //                              char * __thiscall typeName(AIPlay * this)
    //              char *            EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //                               ?typeName@AIPlay@@QBEPADXZ
    //                               AIPlay::typeName
    //                              aipbook.cpp:355 (9)
    //         0040f3a0     MOV        AL,byte ptr [ECX + this->typeValue]
    //         0040f3a3     PUSH       EAX
    //         0040f3a4     CALL       AIPlay::convertToNameType                        char * convertToNameType(AIPlay * this, uchar
    //                              aipbook.cpp:357 (1)
    //         0040f3a9     RET
}

// Offset: 0x0040F3B0
uchar targetType(AIPlay* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlay::targetType(int)const                                         *
    //                              *********************************************************************************************************
    //                              uchar __thiscall targetType(AIPlay * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f3b0(R)  
    //                               ?targetType@AIPlay@@QBEEH@Z                                  XREF[1]:     loadPlays:004110f3(c)  
    //                               AIPlay::targetType
    //                              aipbook.cpp:362 (13)
    //         0040f3b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f3b4     TEST       EAX,EAX
    //         0040f3b6     JL         LAB_0040f3c4
    //         0040f3b8     CMP        EAX,0x5
    //         0040f3bb     JGE        LAB_0040f3c4
    //                              aipbook.cpp:364 (4)
    //         0040f3bd     MOV        AL,byte ptr [ECX + EAX*0x1 + this->targetTypeV
    //                              aipbook.cpp:366 (3)
    //         0040f3c1     RET        0x4
    //                               LAB_0040f3c4                                                 XREF[2]:     0040f3b6(j), 0040f3bb(j)  
    //                              aipbook.cpp:365 (2)
    //         0040f3c4     XOR        AL,AL
    //                              aipbook.cpp:366 (3)
    //         0040f3c6     RET        0x4
}

// Offset: 0x0040F3D0
int isTargetType(AIPlay* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::isTargetType(unsigned char)const                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall isTargetType(AIPlay * this, uchar param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040f3d0(R)  
    //                               ?isTargetType@AIPlay@@QBEHE@Z
    //                               AIPlay::isTargetType
    //                              aipbook.cpp:371 (6)
    //         0040f3d0     MOV        DL,byte ptr [ESP + param_1]
    //         0040f3d4     XOR        EAX,EAX
    //                               LAB_0040f3d6                                                 XREF[1]:     0040f3e0(j)  
    //                              aipbook.cpp:373 (12)
    //         0040f3d6     CMP        byte ptr [EAX + this->nameValue[0]*0x1 + 0x44]
    //         0040f3da     JZ         LAB_0040f3e7
    //         0040f3dc     INC        EAX
    //         0040f3dd     CMP        EAX,0x5
    //         0040f3e0     JL         LAB_0040f3d6
    //                              aipbook.cpp:375 (2)
    //         0040f3e2     XOR        EAX,EAX
    //                              aipbook.cpp:376 (3)
    //         0040f3e4     RET        0x4
    //                               LAB_0040f3e7                                                 XREF[1]:     0040f3da(j)  
    //                              aipbook.cpp:374 (5)
    //         0040f3e7     MOV        EAX,0x1
    //                              aipbook.cpp:376 (3)
    //         0040f3ec     RET        0x4
}

// Offset: 0x0040F3F0
int addTargetType(AIPlay* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::addTargetType(unsigned char)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall addTargetType(AIPlay * this, uchar param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040f409(R)  
    //                               ?addTargetType@AIPlay@@QAEHE@Z                               XREF[2]:     loadPlays:00410b24(c), 
    //                               AIPlay::addTargetType                                                     loadPlays:00411100(c)  
    //                              aipbook.cpp:381 (2)
    //         0040f3f0     XOR        EDX,EDX
    //                               LAB_0040f3f2                                                 XREF[1]:     0040f402(j)  
    //                              aipbook.cpp:384 (18)
    //         0040f3f2     MOV        AL,byte ptr [EDX + this->nameValue[0]*0x1 + 0x
    //         0040f3f6     TEST       AL,AL
    //         0040f3f8     JZ         LAB_0040f409
    //         0040f3fa     CMP        AL,0x5
    //         0040f3fc     JZ         LAB_0040f409
    //         0040f3fe     INC        EDX
    //         0040f3ff     CMP        EDX,0x5
    //         0040f402     JL         LAB_0040f3f2
    //                              aipbook.cpp:388 (2)
    //         0040f404     XOR        EAX,EAX
    //                              aipbook.cpp:389 (3)
    //         0040f406     RET        0x4
    //                               LAB_0040f409                                                 XREF[2]:     0040f3f8(j), 0040f3fc(j)  
    //                              aipbook.cpp:385 (8)
    //         0040f409     MOV        AL,byte ptr [ESP + param_1]
    //         0040f40d     MOV        byte ptr [EDX + this->nameValue[0]*0x1 + 0x44]
    //                              aipbook.cpp:386 (5)
    //         0040f411     MOV        EAX,0x1
    //                              aipbook.cpp:389 (3)
    //         0040f416     RET        0x4
}

// Offset: 0x0040F420
uchar targetCharacteristic(AIPlay* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlay::targetCharacteristic(int)const                               *
    //                              *********************************************************************************************************
    //                              uchar __thiscall targetCharacteristic(AIPlay * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f420(R)  
    //                               ?targetCharacteristic@AIPlay@@QBEEH@Z                        XREF[1]:     loadPlays:0041110d(c)  
    //                               AIPlay::targetCharacteristic
    //                              aipbook.cpp:394 (13)
    //         0040f420     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f424     TEST       EAX,EAX
    //         0040f426     JL         LAB_0040f434
    //         0040f428     CMP        EAX,0x5
    //         0040f42b     JGE        LAB_0040f434
    //                              aipbook.cpp:396 (4)
    //         0040f42d     MOV        AL,byte ptr [ECX + EAX*0x1 + this->targetChara
    //                              aipbook.cpp:398 (3)
    //         0040f431     RET        0x4
    //                               LAB_0040f434                                                 XREF[2]:     0040f426(j), 0040f42b(j)  
    //                              aipbook.cpp:397 (2)
    //         0040f434     XOR        AL,AL
    //                              aipbook.cpp:398 (3)
    //         0040f436     RET        0x4
}

// Offset: 0x0040F440
int isTargetCharacteristic(AIPlay* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::isTargetCharacteristic(unsigned char)const                             *
    //                              *********************************************************************************************************
    //                              int __thiscall isTargetCharacteristic(AIPlay * this, uchar param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040f440(R)  
    //                               ?isTargetCharacteristic@AIPlay@@QBEHE@Z
    //                               AIPlay::isTargetCharacteristic
    //                              aipbook.cpp:403 (6)
    //         0040f440     MOV        DL,byte ptr [ESP + param_1]
    //         0040f444     XOR        EAX,EAX
    //                               LAB_0040f446                                                 XREF[1]:     0040f450(j)  
    //                              aipbook.cpp:405 (12)
    //         0040f446     CMP        byte ptr [EAX + this->nameValue[0]*0x1 + 0x49]
    //         0040f44a     JZ         LAB_0040f457
    //         0040f44c     INC        EAX
    //         0040f44d     CMP        EAX,0x5
    //         0040f450     JL         LAB_0040f446
    //                              aipbook.cpp:407 (2)
    //         0040f452     XOR        EAX,EAX
    //                              aipbook.cpp:408 (3)
    //         0040f454     RET        0x4
    //                               LAB_0040f457                                                 XREF[1]:     0040f44a(j)  
    //                              aipbook.cpp:406 (5)
    //         0040f457     MOV        EAX,0x1
    //                              aipbook.cpp:408 (3)
    //         0040f45c     RET        0x4
}

// Offset: 0x0040F460
int addTargetCharacteristic(AIPlay* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::addTargetCharacteristic(unsigned char)                                 *
    //                              *********************************************************************************************************
    //                              int __thiscall addTargetCharacteristic(AIPlay * this, uchar param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040f479(R)  
    //                               ?addTargetCharacteristic@AIPlay@@QAEHE@Z                     XREF[2]:     loadPlays:00410a97(c), 
    //                               AIPlay::addTargetCharacteristic                                           loadPlays:0041111a(c)  
    //                              aipbook.cpp:413 (2)
    //         0040f460     XOR        EDX,EDX
    //                               LAB_0040f462                                                 XREF[1]:     0040f472(j)  
    //                              aipbook.cpp:416 (18)
    //         0040f462     MOV        AL,byte ptr [EDX + this->nameValue[0]*0x1 + 0x
    //         0040f466     TEST       AL,AL
    //         0040f468     JZ         LAB_0040f479
    //         0040f46a     CMP        AL,0x5
    //         0040f46c     JZ         LAB_0040f479
    //         0040f46e     INC        EDX
    //         0040f46f     CMP        EDX,0x5
    //         0040f472     JL         LAB_0040f462
    //                              aipbook.cpp:420 (2)
    //         0040f474     XOR        EAX,EAX
    //                              aipbook.cpp:421 (3)
    //         0040f476     RET        0x4
    //                               LAB_0040f479                                                 XREF[2]:     0040f468(j), 0040f46c(j)  
    //                              aipbook.cpp:417 (8)
    //         0040f479     MOV        AL,byte ptr [ESP + param_1]
    //         0040f47d     MOV        byte ptr [EDX + this->nameValue[0]*0x1 + 0x49]
    //                              aipbook.cpp:418 (5)
    //         0040f481     MOV        EAX,0x1
    //                              aipbook.cpp:421 (3)
    //         0040f486     RET        0x4
}

// Offset: 0x0040F490
int gatherTolerance(AIPlay* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::gatherTolerance(int,int)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall gatherTolerance(AIPlay * this, int param_1, int param
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040f490(R)  
    //                               ?gatherTolerance@AIPlay@@QAEHHH@Z                            XREF[1]:     selectNewPlayPhase:00414a5b(c)  
    //                               AIPlay::gatherTolerance
    //                              aipbook.cpp:426 (14)
    //         0040f490     MOV        EAX,dword ptr [ESP + param_2]
    //         0040f494     PUSH       ESI
    //         0040f495     PUSH       EDI
    //         0040f496     PUSH       EAX
    //         0040f497     CALL       AIPlay::phase                                    AIPlayPhase * phase(AIPlay * this, int param_1)
    //         0040f49c     MOV        EDI,EAX
    //                              aipbook.cpp:431 (2)
    //         0040f49e     TEST       EDI,EDI
    //                              aipbook.cpp:432 (2)
    //         0040f4a0     JZ         LAB_0040f4cd
    //                              aipbook.cpp:433 (2)
    //         0040f4a2     XOR        ESI,ESI
    //                               LAB_0040f4a4                                                 XREF[1]:     0040f4b9(j)  
    //                              aipbook.cpp:434 (8)
    //         0040f4a4     PUSH       ESI
    //         0040f4a5     MOV        this,EDI
    //         0040f4a7     CALL       AIPlayPhase::trigger                             AIPlayPhaseTrigger * trigger(AIPlayPhase * th
    //                              aipbook.cpp:435 (4)
    //         0040f4ac     TEST       EAX,EAX
    //         0040f4ae     JZ         LAB_0040f4b5
    //                              aipbook.cpp:437 (5)
    //         0040f4b0     CMP        byte ptr [EAX],0x1
    //         0040f4b3     JZ         LAB_0040f4c5
    //                               LAB_0040f4b5                                                 XREF[1]:     0040f4ae(j)  
    //                              aipbook.cpp:433 (6)
    //         0040f4b5     INC        ESI
    //         0040f4b6     CMP        ESI,0x3
    //         0040f4b9     JL         LAB_0040f4a4
    //                              aipbook.cpp:440 (5)
    //         0040f4bb     MOV        EAX,0x2
    //                              aipbook.cpp:441 (5)
    //         0040f4c0     POP        EDI
    //         0040f4c1     POP        ESI
    //         0040f4c2     RET        0x8
    //                               LAB_0040f4c5                                                 XREF[1]:     0040f4b3(j)  
    //                              aipbook.cpp:438 (3)
    //         0040f4c5     MOV        EAX,dword ptr [EAX + 0x4]
    //                              aipbook.cpp:441 (15)
    //         0040f4c8     POP        EDI
    //         0040f4c9     POP        ESI
    //         0040f4ca     RET        0x8
    //                               LAB_0040f4cd                                                 XREF[1]:     0040f4a0(j)  
    //         0040f4cd     POP        EDI
    //         0040f4ce     MOV        EAX,0x2
    //         0040f4d3     POP        ESI
    //         0040f4d4     RET        0x8
}

// Offset: 0x0040F4E0
AIPlayGroup* group(AIPlay* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIPlayGroup * __thiscall AIPlay::group(int)                                             *
    //                              *********************************************************************************************************
    //                              AIPlayGroup * __thiscall group(AIPlay * this, int param_1)
    //              AIPlayGroup *     EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f4e0(R)  
    //                               ?group@AIPlay@@QAEPAVAIPlayGroup@@H@Z                        XREF[8]:     fillGroups:0040f60b(c), 
    //                               AIPlay::group                                                             fillGroups:0040f77f(c), 
    //                                                                                                         fillGroups:0040f858(c), 
    //                                                                                                         fillGroups:0040f92e(c), 
    //                                                                                                         loadPlays:00410c89(c), 
    //                                                                                                         loadPlays:00410cb6(c), 
    //                                                                                                         loadPlays:00411144(c), 
    //                                                                                                         loadPlays:00411155(c)  
    //                              aipbook.cpp:446 (13)
    //         0040f4e0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040f4e4     TEST       EAX,EAX
    //         0040f4e6     JL         LAB_0040f4f7
    //         0040f4e8     CMP        EAX,0x5
    //         0040f4eb     JGE        LAB_0040f4f7
    //                              aipbook.cpp:448 (7)
    //         0040f4ed     LEA        EAX,[EAX + EAX*0x2]
    //         0040f4f0     LEA        EAX,[ECX + EAX*0x4 + this->groups[0].minValue[
    //                              aipbook.cpp:450 (3)
    //         0040f4f4     RET        0x4
    //                               LAB_0040f4f7                                                 XREF[2]:     0040f4e6(j), 0040f4eb(j)  
    //                              aipbook.cpp:449 (2)
    //         0040f4f7     XOR        EAX,EAX
    //                              aipbook.cpp:450 (3)
    //         0040f4f9     RET        0x4
}

// Offset: 0x0040F500
AIPlayPhase* phase(AIPlay* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIPlayPhase * __thiscall AIPlay::phase(int)                                             *
    //                              *********************************************************************************************************
    //                              AIPlayPhase * __thiscall phase(AIPlay * this, int param_1)
    //              AIPlayPhase *     EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040f500(R)  
    //                               ?phase@AIPlay@@QAEPAVAIPlayPhase@@H@Z                        XREF[10]:    gatherTolerance:0040f497(c), 
    //                               AIPlay::phase                                                             loadPlays:00410dd3(c), 
    //                                                                                                         loadPlays:00410ea2(c), 
    //                                                                                                         loadPlays:00410f74(c), 
    //                                                                                                         loadPlays:004111bc(c), 
    //                                                                                                         loadPlays:004111cd(c), 
    //                                                                                                         updateGroup:004143b5(c), 
    //                                                                                                         selectNewPlayPhase:00414883(c), 
    //                                                                                                         processGroupNotify:00419556(c), 
    //                                                                                                         objectToAttackWithPlay:004dc5a1(c)
    //                              aipbook.cpp:455 (13)
    //         0040f500     MOV        EDX,dword ptr [ESP + param_1]
    //         0040f504     TEST       EDX,EDX
    //         0040f506     JL         LAB_0040f521
    //         0040f508     CMP        EDX,0xa
    //         0040f50b     JGE        LAB_0040f521
    //                              aipbook.cpp:457 (17)
    //         0040f50d     MOV        EAX,EDX
    //         0040f50f     SHL        EAX,0x3
    //         0040f512     SUB        EAX,EDX
    //         0040f514     LEA        EAX,[EAX + EAX*0x4]
    //         0040f517     LEA        EAX,[ECX + EAX*0x4 + this->phases[0].commands[
    //                              aipbook.cpp:459 (3)
    //         0040f51e     RET        0x4
    //                               LAB_0040f521                                                 XREF[2]:     0040f506(j), 0040f50b(j)  
    //                              aipbook.cpp:458 (2)
    //         0040f521     XOR        EAX,EAX
    //                              aipbook.cpp:459 (3)
    //         0040f523     RET        0x4
}

// Offset: 0x0040F530
int fillGroups(AIPlay* this_, AIPlayStatus* param_2, int* param_3, int param_4, RGE_Game_World* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::fillGroups(class AIPlayStatus *,int *,int,class RGE_Game_World *)      *
    //                              *********************************************************************************************************
    //                              int __thiscall fillGroups(AIPlay * this, AIPlayStatus * param_1, int
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              AIPlayStatus *    Stack[0x4]:4   param_1                   XREF[1]:     0040f53f(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[1]:     0040f593(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040f588(R)  
    //              RGE_Game_World    Stack[0x10]:4  param_4                   XREF[1]:     0040f537(R)  
    //              int[6][50]        Stack[-0x4b4   unitsByType
    //              int[6]            Stack[-0x4cc   unitsByTypeCount          XREF[1,1]:   0040f547(W), 0040f57a(*)  
    //              AIPlayGroup *     Stack[-0x4d0   group
    //              int               Stack[-0x4d8   a
    //              int               Stack[-0x4dc   smallestGroupSize
    //              int               Stack[-0x4e0   minUnits                  XREF[2]:     0040f57e(W), 0040f5df(W)  
    //              int               Stack[-0x4e4   rVal
    //              undefined4        Stack[-0x4e8   local_4e8                 XREF[1]:     0040f5f7(W)  
    //              int               Stack[-0x4ec   i
    //              int               Stack[-0x4f0   j                         XREF[3]:     0040f59a(W), 0040f5e3(R), 0040f5eb(W)  
    //              int               Stack[-0x4f4   deviation                 XREF[3]:     0040f560(W), 0040f5f1(R), 0040f606(R)  
    //              AIPlay *          Stack[-0x4f8   play
    //                               ?fillGroups@AIPlay@@QAEHPAVAIPlayStatus@@PAHHPAVRGE_Game_Wo  XREF[2]:     updateGroup:00414327(c), 
    //                               AIPlay::fillGroups                                                        objectToAttackWithPlay:004dc571(c)
    //                              aipbook.cpp:465 (7)
    //         0040f530     SUB        ESP,0x4f8
    //         0040f536     PUSH       EBX
    //                              aipbook.cpp:467 (39)
    //         0040f537     MOV        EBX,dword ptr [ESP + param_4]
    //         0040f53e     PUSH       EBP
    //         0040f53f     MOV        EBP,dword ptr [ESP + param_1]
    //         0040f546     PUSH       ESI
    //         0040f547     MOV        dword ptr [ESP + unitsByTypeCount[0]],this
    //         0040f54b     MOV        EAX,dword ptr [EBP + 0x190]
    //         0040f551     MOV        this,dword ptr [EBX + 0xa0]
    //         0040f557     PUSH       EDI
    //         0040f558     PUSH       EAX
    //         0040f559     CALL       AIPlayBook::play                                 AIPlay * play(AIPlayBook * this, int param_1)
    //                              aipbook.cpp:468 (8)
    //         0040f55e     TEST       EAX,EAX
    //         0040f560     MOV        dword ptr [ESP + deviation],EAX
    //         0040f564     JNZ        LAB_0040f573
    //                              aipbook.cpp:640 (13)
    //         0040f566     POP        EDI
    //         0040f567     POP        ESI
    //         0040f568     POP        EBP
    //         0040f569     POP        EBX
    //         0040f56a     ADD        ESP,0x4f8
    //         0040f570     RET        0x10
    //                               LAB_0040f573                                                 XREF[1]:     0040f564(j)  
    //                              aipbook.cpp:475 (11)
    //         0040f573     MOV        this,0x6
    //         0040f578     XOR        EAX,EAX
    //         0040f57a     LEA        EDI=>unitsByTypeCount[1],[ESP + 0x40]
    //                              aipbook.cpp:478 (10)
    //         0040f57e     MOV        dword ptr [ESP + minUnits],0x1
    //         0040f586     STOSD.REP  ES:EDI
    //                              aipbook.cpp:479 (11)
    //         0040f588     MOV        EAX,dword ptr [ESP + param_3]
    //         0040f58f     TEST       EAX,EAX
    //         0040f591     JLE        LAB_0040f5f1
    //                              aipbook.cpp:640 (43)
    //         0040f593     MOV        ESI,dword ptr [ESP + param_2]
    //         0040f59a     MOV        dword ptr [ESP + j],EAX
    //                               LAB_0040f59e                                                 XREF[1]:     0040f5ef(j)  
    //         0040f59e     MOV        this,dword ptr [ESI]
    //         0040f5a0     PUSH       this
    //         0040f5a1     MOV        this,EBX
    //         0040f5a3     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040f5a8     XOR        EDI,EDI
    //         0040f5aa     CMP        EAX,EDI
    //         0040f5ac     JZ         LAB_0040f5df
    //         0040f5ae     MOV        this,dword ptr [EBX + 0xa0]
    //         0040f5b4     PUSH       EAX
    //         0040f5b5     MOV        EDX,dword ptr [this->nameValue[0]]
    //         0040f5b7     CALL       dword ptr [EDX + 0x10]
    //         0040f5ba     CMP        EAX,EDI
    //         0040f5bc     JL         LAB_0040f5df
    //                              aipbook.cpp:488 (5)
    //         0040f5be     CMP        EAX,0x6
    //         0040f5c1     JGE        LAB_0040f5df
    //                              aipbook.cpp:495 (19)
    //         0040f5c3     MOV        EDX,dword ptr [ESP + EAX*0x4 + 0x40]
    //         0040f5c7     LEA        this,[ESP + EAX*0x4 + 0x40]
    //         0040f5cb     MOV        EDI,dword ptr [ESI]
    //         0040f5cd     LEA        EAX,[EAX + EAX*0x4]
    //         0040f5d0     LEA        EAX,[EAX + EAX*0x4]
    //         0040f5d3     LEA        EAX,[EDX + EAX*0x2]
    //                              aipbook.cpp:496 (7)
    //         0040f5d6     INC        EDX
    //         0040f5d7     MOV        dword ptr [this->nameValue[0]],EDX
    //         0040f5d9     MOV        dword ptr [ESP + EAX*0x4 + 0x58],EDI
    //                              aipbook.cpp:497 (2)
    //         0040f5dd     JMP        LAB_0040f5e3
    //                               LAB_0040f5df                                                 XREF[3]:     0040f5ac(j), 0040f5bc(j), 
    //                                                                                                         0040f5c1(j)  
    //                              aipbook.cpp:489 (4)
    //         0040f5df     MOV        dword ptr [ESP + minUnits],EDI
    //                               LAB_0040f5e3                                                 XREF[1]:     0040f5dd(j)  
    //                              aipbook.cpp:479 (14)
    //         0040f5e3     MOV        EAX,dword ptr [ESP + j]
    //         0040f5e7     ADD        ESI,0x4
    //         0040f5ea     DEC        EAX
    //         0040f5eb     MOV        dword ptr [ESP + j],EAX
    //         0040f5ef     JNZ        LAB_0040f59e
    //                               LAB_0040f5f1                                                 XREF[1]:     0040f591(j)  
    //                              aipbook.cpp:501 (21)
    //         0040f5f1     MOV        this,dword ptr [ESP + deviation]
    //         0040f5f5     XOR        EAX,EAX
    //         0040f5f7     MOV        dword ptr [ESP + local_4e8],EAX
    //         0040f5fb     MOV        DL,byte ptr [ECX + this->numberGroupsValue]
    //         0040f5fe     TEST       DL,DL
    //         0040f600     JBE        LAB_0040f70a
    //                               LAB_0040f606                                                 XREF[1]:     0040f704(j)  
    //                              aipbook.cpp:502 (10)
    //         0040f606     MOV        this,dword ptr [ESP + deviation]
    //         0040f60a     PUSH       EAX
    //         0040f60b     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //                              aipbook.cpp:503 (14)
    //         0040f610     XOR        this,this
    //         0040f612     MOV        dword ptr [ESP + 0x34],EAX
    //         0040f616     CMP        EAX,this
    //         0040f618     JZ         LAB_0040f99f
    //                              aipbook.cpp:640 (22)
    //         0040f61e     LEA        EDX,[ESP + 0x40]
    //         0040f622     MOV        dword ptr [ESP + 0x1c],this
    //         0040f626     MOV        dword ptr [ESP + 0x24],this
    //         0040f62a     MOV        dword ptr [ESP + 0x18],EDX
    //         0040f62e     JMP        LAB_0040f634
    //                               LAB_0040f630                                                 XREF[1]:     0040f6ea(j)  
    //         0040f630     MOV        EAX,dword ptr [ESP + 0x34]
    //                               LAB_0040f634                                                 XREF[1]:     0040f62e(j)  
    //                              aipbook.cpp:509 (21)
    //         0040f634     MOV        this,dword ptr [ESP + 0x1c]
    //         0040f638     PUSH       this
    //         0040f639     MOV        this,EAX
    //         0040f63b     CALL       AIPlayGroup::minimum                             uchar minimum(AIPlayGroup * this, int param_1)
    //         0040f640     AND        EAX,0xff
    //         0040f645     MOV        dword ptr [ESP + 0x2c],EAX
    //                              aipbook.cpp:511 (2)
    //         0040f649     JZ         LAB_0040f6c6
    //                              aipbook.cpp:517 (24)
    //         0040f64b     MOV        EDX,dword ptr [ESP + 0x18]
    //         0040f64f     XOR        EBX,EBX
    //         0040f651     XOR        EDI,EDI
    //         0040f653     MOV        EAX,dword ptr [EDX]
    //         0040f655     TEST       EAX,EAX
    //         0040f657     MOV        dword ptr [ESP + 0x38],EAX
    //         0040f65b     JLE        LAB_0040f6c6
    //                               LAB_0040f65d                                                 XREF[1]:     0040f6c4(j)  
    //         0040f65d     CMP        EBX,dword ptr [ESP + 0x2c]
    //         0040f661     JGE        LAB_0040f6c6
    //                              aipbook.cpp:520 (20)
    //         0040f663     MOV        EAX,dword ptr [ESP + 0x24]
    //         0040f667     LEA        this,[EDI + EAX*0x1]
    //         0040f66a     MOV        EAX,dword ptr [ESP + this->nameValue[0]*0x4 + 
    //         0040f66e     CMP        EAX,-0x1
    //         0040f671     LEA        ESI,[ESP + this->nameValue[0]*0x4 + 0x58]
    //         0040f675     JZ         LAB_0040f6bd
    //                              aipbook.cpp:525 (23)
    //         0040f677     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0040f67b     MOV        this,dword ptr [ESP + 0x20]
    //         0040f67f     PUSH       EDX
    //         0040f680     PUSH       this=>DAT_fffffff8
    //         0040f681     PUSH       EAX=>DAT_fffffff4
    //         0040f682     MOV        this,EBP
    //         0040f684     CALL       AIPlayStatus::addGrouping                        int addGrouping(AIPlayStatus * this, int para
    //         0040f689     CMP        EAX,0x1
    //         0040f68c     JNZ        LAB_0040f6b5
    //                              aipbook.cpp:529 (33)
    //         0040f68e     MOV        EDX,dword ptr [ESP + 0x14]
    //         0040f692     INC        EBX
    //         0040f693     MOV        dword ptr [ESP + 0x30],EBX
    //         0040f697     MOV        this,EBP
    //         0040f699     MOV        BL,byte ptr [EDX + 0x42]
    //         0040f69c     MOV        dword ptr [ESI],0xffffffff
    //         0040f6a2     CALL       AIPlayStatus::numberInPlay                       uchar numberInPlay(AIPlayStatus * this)
    //         0040f6a7     CMP        AL,BL
    //         0040f6a9     JZ         LAB_0040f918
    //                              aipbook.cpp:532 (6)
    //         0040f6af     MOV        EBX,dword ptr [ESP + 0x30]
    //         0040f6b3     JMP        LAB_0040f6bd
    //                               LAB_0040f6b5                                                 XREF[1]:     0040f68c(j)  
    //                              aipbook.cpp:533 (8)
    //         0040f6b5     MOV        dword ptr [ESP + 0x28],0x0
    //                               LAB_0040f6bd                                                 XREF[2]:     0040f675(j), 0040f6b3(j)  
    //                              aipbook.cpp:517 (9)
    //         0040f6bd     MOV        EAX,dword ptr [ESP + 0x38]
    //         0040f6c1     INC        EDI
    //         0040f6c2     CMP        EDI,EAX
    //         0040f6c4     JL         LAB_0040f65d
    //                               LAB_0040f6c6                                                 XREF[3]:     0040f649(j), 0040f65b(j), 
    //                                                                                                         0040f661(j)  
    //                              aipbook.cpp:508 (68)
    //         0040f6c6     MOV        EAX,dword ptr [ESP + 0x24]
    //         0040f6ca     MOV        EDI,dword ptr [ESP + 0x1c]
    //         0040f6ce     MOV        EDX,dword ptr [ESP + 0x18]
    //         0040f6d2     ADD        EAX,0x32
    //         0040f6d5     INC        EDI
    //         0040f6d6     ADD        EDX,0x4
    //         0040f6d9     CMP        EAX,0x12c
    //         0040f6de     MOV        dword ptr [ESP + 0x1c],EDI
    //         0040f6e2     MOV        dword ptr [ESP + 0x24],EAX
    //         0040f6e6     MOV        dword ptr [ESP + 0x18],EDX
    //         0040f6ea     JL         LAB_0040f630
    //         0040f6f0     MOV        EDX,dword ptr [ESP + 0x14]
    //         0040f6f4     MOV        EAX,dword ptr [ESP + 0x20]
    //         0040f6f8     XOR        this,this
    //         0040f6fa     INC        EAX
    //         0040f6fb     MOV        this,byte ptr [EDX + 0x52]
    //         0040f6fe     MOV        dword ptr [ESP + 0x20],EAX
    //         0040f702     CMP        EAX,this
    //         0040f704     JL         LAB_0040f606
    //                               LAB_0040f70a                                                 XREF[1]:     0040f600(j)  
    //                              aipbook.cpp:544 (24)
    //         0040f70a     LEA        EAX,[ESP + 0x40]
    //         0040f70e     LEA        this,[ESP + 0x58]
    //         0040f712     MOV        dword ptr [ESP + 0x20],0x0
    //         0040f71a     MOV        dword ptr [ESP + 0x24],EAX
    //         0040f71e     MOV        dword ptr [ESP + 0x18],this
    //                               LAB_0040f722                                                 XREF[1]:     0040f912(j)  
    //                              aipbook.cpp:545 (34)
    //         0040f722     MOV        EDX,dword ptr [ESP + 0x24]
    //         0040f726     MOV        dword ptr [ESP + 0x34],0x0
    //         0040f72e     MOV        EAX,dword ptr [EDX]
    //         0040f730     TEST       EAX,EAX
    //         0040f732     MOV        dword ptr [ESP + 0x38],EAX
    //         0040f736     JLE        LAB_0040f8ed
    //         0040f73c     MOV        EAX,dword ptr [ESP + 0x18]
    //         0040f740     MOV        dword ptr [ESP + 0x1c],EAX
    //                               LAB_0040f744                                                 XREF[1]:     0040f8e7(j)  
    //                              aipbook.cpp:547 (19)
    //         0040f744     MOV        this,dword ptr [ESP + 0x1c]
    //         0040f748     MOV        this,dword ptr [this->nameValue[0]]
    //         0040f74a     CMP        this,-0x1
    //         0040f74d     MOV        dword ptr [ESP + 0x2c],this
    //         0040f751     JZ         LAB_0040f8cd
    //                              aipbook.cpp:554 (15)
    //         0040f757     MOV        EDX,dword ptr [ESP + 0x3c]
    //         0040f75b     MOV        AL,byte ptr [EDX + 0x4f]
    //         0040f75e     CMP        AL,0x1
    //         0040f760     JNZ        LAB_0040f83e
    //                              aipbook.cpp:561 (20)
    //         0040f766     MOV        EAX,dword ptr [ESP + 0x14]
    //         0040f76a     OR         EDI,0xffffffff
    //         0040f76d     XOR        ESI,ESI
    //         0040f76f     MOV        DL,byte ptr [EAX + 0x52]
    //         0040f772     MOV        dword ptr [ESP + 0x30],ESI
    //         0040f776     TEST       DL,DL
    //         0040f778     JBE        LAB_0040f7f0
    //                               LAB_0040f77a                                                 XREF[1]:     0040f7ea(j)  
    //                              aipbook.cpp:562 (12)
    //         0040f77a     MOV        this,dword ptr [ESP + 0x14]
    //         0040f77e     PUSH       ESI
    //         0040f77f     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //         0040f784     MOV        EBX,EAX
    //                              aipbook.cpp:563 (4)
    //         0040f786     TEST       EBX,EBX
    //         0040f788     JZ         LAB_0040f7de
    //                              aipbook.cpp:570 (65)
    //         0040f78a     MOV        this,dword ptr [ESP + 0x20]
    //         0040f78e     PUSH       this
    //         0040f78f     PUSH       ESI=>DAT_fffffff8
    //         0040f790     MOV        this,EBP
    //         0040f792     CALL       AIPlayStatus::numberOfTypeInGroup                uchar numberOfTypeInGroup(AIPlayStatus * this
    //         0040f797     MOV        DL,AL
    //         0040f799     MOV        EAX,dword ptr [ESP + 0x20]
    //         0040f79d     PUSH       EAX
    //         0040f79e     MOV        this,EBX
    //         0040f7a0     MOV        byte ptr [ESP + 0x17],DL
    //         0040f7a4     CALL       AIPlayGroup::maximum                             uchar maximum(AIPlayGroup * this, int param_1)
    //         0040f7a9     MOV        this,byte ptr [ESP + 0x13]
    //         0040f7ad     CMP        AL,this
    //         0040f7af     JBE        LAB_0040f7de
    //         0040f7b1     CMP        EDI,-0x1
    //         0040f7b4     JZ         LAB_0040f7cb
    //         0040f7b6     PUSH       ESI
    //         0040f7b7     MOV        this,EBP
    //         0040f7b9     CALL       AIPlayStatus::numberInGroup                      uchar numberInGroup(AIPlayStatus * this, int 
    //         0040f7be     MOV        this,dword ptr [ESP + 0x30]
    //         0040f7c2     AND        EAX,0xff
    //         0040f7c7     CMP        this,EAX
    //         0040f7c9     JLE        LAB_0040f7de
    //                               LAB_0040f7cb                                                 XREF[1]:     0040f7b4(j)  
    //                              aipbook.cpp:572 (33)
    //         0040f7cb     PUSH       ESI
    //         0040f7cc     MOV        this,EBP
    //         0040f7ce     MOV        EDI,ESI
    //         0040f7d0     CALL       AIPlayStatus::numberInGroup                      uchar numberInGroup(AIPlayStatus * this, int 
    //         0040f7d5     AND        EAX,0xff
    //         0040f7da     MOV        dword ptr [ESP + 0x30],EAX
    //                               LAB_0040f7de                                                 XREF[3]:     0040f788(j), 0040f7af(j), 
    //                                                                                                         0040f7c9(j)  
    //         0040f7de     MOV        EAX,dword ptr [ESP + 0x14]
    //         0040f7e2     XOR        EDX,EDX
    //         0040f7e4     INC        ESI
    //         0040f7e5     MOV        DL,byte ptr [EAX + 0x52]
    //         0040f7e8     CMP        ESI,EDX
    //         0040f7ea     JL         LAB_0040f77a
    //                              aipbook.cpp:561 (4)
    //         0040f7ec     MOV        this,dword ptr [ESP + 0x2c]
    //                               LAB_0040f7f0                                                 XREF[1]:     0040f778(j)  
    //                              aipbook.cpp:579 (9)
    //         0040f7f0     CMP        EDI,-0x1
    //         0040f7f3     JZ         LAB_0040f8cd
    //                              aipbook.cpp:580 (19)
    //         0040f7f9     MOV        EDX,dword ptr [ESP + 0x20]
    //         0040f7fd     PUSH       EDX
    //         0040f7fe     PUSH       EDI=>DAT_fffffff8
    //         0040f7ff     PUSH       this=>DAT_fffffff4
    //         0040f800     MOV        this,EBP
    //         0040f802     CALL       AIPlayStatus::addGrouping                        int addGrouping(AIPlayStatus * this, int para
    //         0040f807     CMP        EAX,0x1
    //         0040f80a     JNZ        LAB_0040f831
    //                              aipbook.cpp:583 (32)
    //         0040f80c     MOV        this,dword ptr [ESP + 0x14]
    //         0040f810     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0040f814     MOV        BL,byte ptr [ECX + this->maximumNumberUnitsVal
    //         0040f817     MOV        this,EBP
    //         0040f819     MOV        dword ptr [EAX],0xffffffff
    //         0040f81f     CALL       AIPlayStatus::numberInPlay                       uchar numberInPlay(AIPlayStatus * this)
    //         0040f824     CMP        AL,BL
    //         0040f826     JZ         LAB_0040f918
    //                              aipbook.cpp:586 (5)
    //         0040f82c     JMP        LAB_0040f8cd
    //                               LAB_0040f831                                                 XREF[1]:     0040f80a(j)  
    //                              aipbook.cpp:587 (8)
    //         0040f831     MOV        dword ptr [ESP + 0x28],0x0
    //                              aipbook.cpp:591 (13)
    //         0040f839     JMP        LAB_0040f8cd
    //                               LAB_0040f83e                                                 XREF[1]:     0040f760(j)  
    //         0040f83e     CMP        AL,0x2
    //         0040f840     JNZ        LAB_0040f8cd
    //                              aipbook.cpp:593 (13)
    //         0040f846     MOV        EDX,dword ptr [ESP + 0x14]
    //         0040f84a     XOR        ESI,ESI
    //         0040f84c     MOV        AL,byte ptr [EDX + 0x52]
    //         0040f84f     TEST       AL,AL
    //         0040f851     JBE        LAB_0040f8cd
    //                               LAB_0040f853                                                 XREF[1]:     0040f8ad(j)  
    //                              aipbook.cpp:594 (12)
    //         0040f853     MOV        this,dword ptr [ESP + 0x14]
    //         0040f857     PUSH       ESI
    //         0040f858     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //         0040f85d     MOV        EBX,EAX
    //                              aipbook.cpp:595 (4)
    //         0040f85f     TEST       EBX,EBX
    //         0040f861     JZ         LAB_0040f8a1
    //                              aipbook.cpp:600 (35)
    //         0040f863     MOV        EDI,dword ptr [ESP + 0x20]
    //         0040f867     MOV        this,EBP
    //         0040f869     PUSH       EDI
    //         0040f86a     PUSH       ESI=>DAT_fffffff8
    //         0040f86b     CALL       AIPlayStatus::numberOfTypeInGroup                uchar numberOfTypeInGroup(AIPlayStatus * this
    //         0040f870     MOV        DL,AL
    //         0040f872     PUSH       EDI
    //         0040f873     MOV        this,EBX
    //         0040f875     MOV        byte ptr [ESP + 0x17],DL
    //         0040f879     CALL       AIPlayGroup::maximum                             uchar maximum(AIPlayGroup * this, int param_1)
    //         0040f87e     MOV        this,byte ptr [ESP + 0x13]
    //         0040f882     CMP        AL,this
    //         0040f884     JBE        LAB_0040f8a1
    //                              aipbook.cpp:601 (19)
    //         0040f886     MOV        EDX,dword ptr [ESP + 0x2c]
    //         0040f88a     PUSH       EDI
    //         0040f88b     PUSH       ESI=>DAT_fffffff8
    //         0040f88c     PUSH       EDX=>DAT_fffffff4
    //         0040f88d     MOV        this,EBP
    //         0040f88f     CALL       AIPlayStatus::addGrouping                        int addGrouping(AIPlayStatus * this, int para
    //         0040f894     CMP        EAX,0x1
    //         0040f897     JZ         LAB_0040f8b1
    //                              aipbook.cpp:609 (8)
    //         0040f899     MOV        dword ptr [ESP + 0x28],0x0
    //                               LAB_0040f8a1                                                 XREF[2]:     0040f861(j), 0040f884(j)  
    //                              aipbook.cpp:593 (16)
    //         0040f8a1     MOV        this,dword ptr [ESP + 0x14]
    //         0040f8a5     XOR        EAX,EAX
    //         0040f8a7     INC        ESI
    //         0040f8a8     MOV        AL,byte ptr [ECX + this->numberGroupsValue]
    //         0040f8ab     CMP        ESI,EAX
    //         0040f8ad     JL         LAB_0040f853
    //         0040f8af     JMP        LAB_0040f8cd
    //                               LAB_0040f8b1                                                 XREF[1]:     0040f897(j)  
    //                              aipbook.cpp:602 (4)
    //         0040f8b1     MOV        EDX,dword ptr [ESP + 0x1c]
    //                              aipbook.cpp:604 (24)
    //         0040f8b5     MOV        EAX,dword ptr [ESP + 0x14]
    //         0040f8b9     MOV        this,EBP
    //         0040f8bb     MOV        BL,byte ptr [EAX + 0x42]
    //         0040f8be     MOV        dword ptr [EDX],0xffffffff
    //         0040f8c4     CALL       AIPlayStatus::numberInPlay                       uchar numberInPlay(AIPlayStatus * this)
    //         0040f8c9     CMP        AL,BL
    //         0040f8cb     JZ         LAB_0040f918
    //                               LAB_0040f8cd                                                 XREF[7]:     0040f751(j), 0040f7f3(j), 
    //                                                                                                         0040f82c(j), 0040f839(j), 
    //                                                                                                         0040f840(j), 0040f851(j), 
    //                                                                                                         0040f8af(j)  
    //                              aipbook.cpp:545 (32)
    //         0040f8cd     MOV        EAX,dword ptr [ESP + 0x34]
    //         0040f8d1     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0040f8d5     MOV        this,dword ptr [ESP + 0x38]
    //         0040f8d9     INC        EAX
    //         0040f8da     ADD        EDX,0x4
    //         0040f8dd     CMP        EAX,this
    //         0040f8df     MOV        dword ptr [ESP + 0x34],EAX
    //         0040f8e3     MOV        dword ptr [ESP + 0x1c],EDX
    //         0040f8e7     JL         LAB_0040f744
    //                               LAB_0040f8ed                                                 XREF[1]:     0040f736(j)  
    //                              aipbook.cpp:544 (43)
    //         0040f8ed     MOV        EAX,dword ptr [ESP + 0x20]
    //         0040f8f1     MOV        ESI,dword ptr [ESP + 0x18]
    //         0040f8f5     MOV        EDX,dword ptr [ESP + 0x24]
    //         0040f8f9     INC        EAX
    //         0040f8fa     ADD        ESI,0xc8
    //         0040f900     ADD        EDX,0x4
    //         0040f903     CMP        EAX,0x6
    //         0040f906     MOV        dword ptr [ESP + 0x20],EAX
    //         0040f90a     MOV        dword ptr [ESP + 0x18],ESI
    //         0040f90e     MOV        dword ptr [ESP + 0x24],EDX
    //         0040f912     JL         LAB_0040f722
    //                              Symbol Ref: No symbol: CountDeviation
    //                               LAB_0040f918                                                 XREF[3]:     0040f6a9(j), 0040f826(j), 
    //                                                                                                         0040f8cb(j)  
    //                              aipbook.cpp:624 (17)
    //         0040f918     MOV        this,dword ptr [ESP + 0x14]
    //         0040f91c     XOR        EDI,EDI
    //         0040f91e     MOV        dword ptr [ESP + 0x18],EDI
    //         0040f922     MOV        AL,byte ptr [ECX + this->numberGroupsValue]
    //         0040f925     TEST       AL,AL
    //         0040f927     JBE        LAB_0040f984
    //                               LAB_0040f929                                                 XREF[1]:     0040f982(j)  
    //                              aipbook.cpp:625 (10)
    //         0040f929     MOV        this,dword ptr [ESP + 0x14]
    //         0040f92d     PUSH       EDI
    //         0040f92e     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //                              aipbook.cpp:626 (8)
    //         0040f933     TEST       EAX,EAX
    //         0040f935     MOV        dword ptr [ESP + 0x3c],EAX
    //         0040f939     JZ         LAB_0040f976
    //                              aipbook.cpp:630 (8)
    //         0040f93b     XOR        EBX,EBX
    //         0040f93d     JMP        LAB_0040f943
    //                               LAB_0040f93f                                                 XREF[1]:     0040f974(j)  
    //         0040f93f     MOV        EAX,dword ptr [ESP + 0x3c]
    //                               LAB_0040f943                                                 XREF[1]:     0040f93d(j)  
    //                              aipbook.cpp:631 (13)
    //         0040f943     PUSH       EBX
    //         0040f944     MOV        this,EAX
    //         0040f946     CALL       AIPlayGroup::minimum                             uchar minimum(AIPlayGroup * this, int param_1)
    //         0040f94b     AND        EAX,0xff
    //                              aipbook.cpp:632 (16)
    //         0040f950     PUSH       EBX
    //         0040f951     PUSH       EDI=>DAT_fffffff8
    //         0040f952     MOV        this,EBP
    //         0040f954     MOV        ESI,EAX
    //         0040f956     CALL       AIPlayStatus::numberOfTypeInGroup                uchar numberOfTypeInGroup(AIPlayStatus * this
    //         0040f95b     AND        EAX,0xff
    //                              aipbook.cpp:633 (4)
    //         0040f960     CMP        ESI,EAX
    //         0040f962     JLE        LAB_0040f970
    //                              aipbook.cpp:634 (18)
    //         0040f964     SUB        ESI,EAX
    //         0040f966     MOV        EAX,dword ptr [ESP + 0x18]
    //         0040f96a     ADD        EAX,ESI
    //         0040f96c     MOV        dword ptr [ESP + 0x18],EAX
    //                               LAB_0040f970                                                 XREF[1]:     0040f962(j)  
    //         0040f970     INC        EBX
    //         0040f971     CMP        EBX,0x6
    //         0040f974     JL         LAB_0040f93f
    //                               LAB_0040f976                                                 XREF[1]:     0040f939(j)  
    //                              aipbook.cpp:624 (14)
    //         0040f976     MOV        EAX,dword ptr [ESP + 0x14]
    //         0040f97a     XOR        EDX,EDX
    //         0040f97c     INC        EDI
    //         0040f97d     MOV        DL,byte ptr [EAX + 0x52]
    //         0040f980     CMP        EDI,EDX
    //         0040f982     JL         LAB_0040f929
    //                               LAB_0040f984                                                 XREF[1]:     0040f927(j)  
    //                              aipbook.cpp:637 (4)
    //         0040f984     MOV        this,byte ptr [ESP + 0x18]
    //                              aipbook.cpp:639 (10)
    //         0040f988     MOV        EAX,dword ptr [ESP + 0x28]
    //         0040f98c     MOV        byte ptr [EBP + 0x1c4],this
    //                              aipbook.cpp:640 (28)
    //         0040f992     POP        EDI
    //         0040f993     POP        ESI
    //         0040f994     POP        EBP
    //         0040f995     POP        EBX
    //         0040f996     ADD        ESP,0x4f8
    //         0040f99c     RET        0x10
    //                               LAB_0040f99f                                                 XREF[1]:     0040f618(j)  
    //         0040f99f     POP        EDI
    //         0040f9a0     POP        ESI
    //         0040f9a1     POP        EBP
    //         0040f9a2     XOR        EAX,EAX
    //         0040f9a4     POP        EBX
    //         0040f9a5     ADD        ESP,0x4f8
    //         0040f9ab     RET        0x10
}

// Offset: 0x0040F9B0
int groupGivenCommandOnPhase(AIPlay* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::groupGivenCommandOnPhase(int,int,int)                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall groupGivenCommandOnPhase(AIPlay * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     0040f9b2(R), 0040fa00(W), 0040fa04(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040f9d0(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040f9c1(R)  
    //                               ?groupGivenCommandOnPhase@AIPlay@@QAEHHHH@Z                  XREF[1]:     updateGroup:0041443a(c)  
    //                               AIPlay::groupGivenCommandOnPhase
    //                              aipbook.cpp:645 (2)
    //         0040f9b0     PUSH       EBX
    //         0040f9b1     PUSH       EBP
    //                              aipbook.cpp:649 (28)
    //         0040f9b2     MOV        EBP,dword ptr [ESP + param_1]
    //         0040f9b6     PUSH       ESI
    //         0040f9b7     TEST       EBP,EBP
    //         0040f9b9     PUSH       EDI
    //         0040f9ba     JL         LAB_0040fa2a
    //         0040f9bc     CMP        EBP,0x5
    //         0040f9bf     JGE        LAB_0040fa2a
    //         0040f9c1     MOV        EDX,dword ptr [ESP + param_3]
    //         0040f9c5     TEST       EDX,EDX
    //         0040f9c7     JL         LAB_0040fa2a
    //         0040f9c9     CMP        EDX,0xa
    //         0040f9cc     JGE        LAB_0040fa2a
    //                              aipbook.cpp:654 (67)
    //         0040f9ce     MOV        EAX,EDX
    //         0040f9d0     MOV        EBX,dword ptr [ESP + param_2]
    //         0040f9d4     SHL        EAX,0x3
    //         0040f9d7     XOR        ESI,ESI
    //         0040f9d9     SUB        EAX,EDX
    //         0040f9db     LEA        EAX,[EAX + EAX*0x4]
    //         0040f9de     LEA        EDI,[ECX + EAX*0x4 + this->phases[0].commands[
    //                               LAB_0040f9e5                                                 XREF[1]:     0040fa15(j)  
    //         0040f9e5     PUSH       ESI
    //         0040f9e6     MOV        this,EDI
    //         0040f9e8     CALL       AIPlayPhase::command                             AIPlayPhaseCommand * command(AIPlayPhase * th
    //         0040f9ed     XOR        this,this
    //         0040f9ef     MOV        this,byte ptr [EAX]
    //         0040f9f1     CMP        this,EBP
    //         0040f9f3     JNZ        LAB_0040fa11
    //         0040f9f5     PUSH       ESI
    //         0040f9f6     MOV        this,EDI
    //         0040f9f8     CALL       AIPlayPhase::command                             AIPlayPhaseCommand * command(AIPlayPhase * th
    //         0040f9fd     MOV        DL,byte ptr [EAX + 0x1]
    //         0040fa00     MOV        byte ptr [ESP + param_1],DL
    //         0040fa04     MOV        EAX,dword ptr [ESP + param_1]
    //         0040fa08     AND        EAX,0xff
    //         0040fa0d     CMP        EAX,EBX
    //         0040fa0f     JZ         LAB_0040fa21
    //                               LAB_0040fa11                                                 XREF[1]:     0040f9f3(j)  
    //                              aipbook.cpp:652 (6)
    //         0040fa11     INC        ESI
    //         0040fa12     CMP        ESI,0x5
    //         0040fa15     JL         LAB_0040f9e5
    //                              aipbook.cpp:650 (3)
    //         0040fa17     OR         EAX,0xffffffff
    //                              aipbook.cpp:658 (7)
    //         0040fa1a     POP        EDI
    //         0040fa1b     POP        ESI
    //         0040fa1c     POP        EBP
    //         0040fa1d     POP        EBX
    //         0040fa1e     RET        0xc
    //                               LAB_0040fa21                                                 XREF[1]:     0040fa0f(j)  
    //                              aipbook.cpp:655 (2)
    //         0040fa21     MOV        EAX,ESI
    //                              aipbook.cpp:658 (17)
    //         0040fa23     POP        EDI
    //         0040fa24     POP        ESI
    //         0040fa25     POP        EBP
    //         0040fa26     POP        EBX
    //         0040fa27     RET        0xc
    //                               LAB_0040fa2a                                                 XREF[4]:     0040f9ba(j), 0040f9bf(j), 
    //                                                                                                         0040f9c7(j), 0040f9cc(j)  
    //         0040fa2a     POP        EDI
    //         0040fa2b     POP        ESI
    //         0040fa2c     POP        EBP
    //         0040fa2d     OR         EAX,0xffffffff
    //         0040fa30     POP        EBX
    //         0040fa31     RET        0xc
}

// Offset: 0x0040FA40
uchar convertToIntType(AIPlay* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall AIPlay::convertToIntType(char *)const                             *
    //                              *********************************************************************************************************
    //                              uchar __thiscall convertToIntType(AIPlay * this, char * param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040fa43(R)  
    //                               ?convertToIntType@AIPlay@@IBEEPAD@Z                          XREF[1]:     loadPlays:00410650(c)  
    //                               AIPlay::convertToIntType
    //                              aipbook.cpp:663 (3)
    //         0040fa40     PUSH       EBX
    //         0040fa41     PUSH       ESI
    //         0040fa42     PUSH       EDI
    //                              aipbook.cpp:664 (60)
    //         0040fa43     MOV        EDI,dword ptr [ESP + param_1]
    //         0040fa47     MOV        ESI,s_Attack                                     = 41h
    //         0040fa4c     MOV        EAX,EDI
    //                               LAB_0040fa4e                                                 XREF[1]:     0040fa70(j)  
    //         0040fa4e     MOV        DL,byte ptr [EAX]
    //         0040fa50     MOV        BL,byte ptr [ESI]=>s_Attack                      = 41h
    //                                                                                  = 74h
    //         0040fa52     MOV        this,DL
    //         0040fa54     CMP        DL,BL
    //         0040fa56     JNZ        LAB_0040fa76
    //         0040fa58     TEST       this,this
    //         0040fa5a     JZ         LAB_0040fa72
    //         0040fa5c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040fa5f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f0b5            = 74h
    //                                                                                  = 006b6361
    //         0040fa62     MOV        this,DL
    //         0040fa64     CMP        DL,BL
    //         0040fa66     JNZ        LAB_0040fa76
    //         0040fa68     ADD        EAX,0x2
    //         0040fa6b     ADD        ESI,0x2
    //         0040fa6e     TEST       this,this
    //         0040fa70     JNZ        LAB_0040fa4e
    //                               LAB_0040fa72                                                 XREF[1]:     0040fa5a(j)  
    //         0040fa72     XOR        EAX,EAX
    //         0040fa74     JMP        LAB_0040fa7b
    //                               LAB_0040fa76                                                 XREF[2]:     0040fa56(j), 0040fa66(j)  
    //         0040fa76     SBB        EAX,EAX
    //         0040fa78     SBB        EAX,-0x1
    //                               LAB_0040fa7b                                                 XREF[1]:     0040fa74(j)  
    //         0040fa7b     TEST       EAX,EAX
    //         0040fa7d     JNZ        LAB_0040fa87
    //                              aipbook.cpp:665 (2)
    //         0040fa7f     MOV        AL,0x1
    //                              aipbook.cpp:673 (6)
    //         0040fa81     POP        EDI
    //         0040fa82     POP        ESI
    //         0040fa83     POP        EBX
    //         0040fa84     RET        0x4
    //                               LAB_0040fa87                                                 XREF[1]:     0040fa7d(j)  
    //                              aipbook.cpp:666 (56)
    //         0040fa87     MOV        ESI,s_Annoy                                      = 41h
    //         0040fa8c     MOV        EAX,EDI
    //                               LAB_0040fa8e                                                 XREF[1]:     0040fab0(j)  
    //         0040fa8e     MOV        DL,byte ptr [EAX]
    //         0040fa90     MOV        BL,byte ptr [ESI]=>s_Annoy                       = 41h
    //                                                                                  = 6Eh
    //         0040fa92     MOV        this,DL
    //         0040fa94     CMP        DL,BL
    //         0040fa96     JNZ        LAB_0040fab6
    //         0040fa98     TEST       this,this
    //         0040fa9a     JZ         LAB_0040fab2
    //         0040fa9c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040fa9f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5f5            = 6Eh
    //                                                                                  = 6Fh
    //         0040faa2     MOV        this,DL
    //         0040faa4     CMP        DL,BL
    //         0040faa6     JNZ        LAB_0040fab6
    //         0040faa8     ADD        EAX,0x2
    //         0040faab     ADD        ESI,0x2
    //         0040faae     TEST       this,this
    //         0040fab0     JNZ        LAB_0040fa8e
    //                               LAB_0040fab2                                                 XREF[1]:     0040fa9a(j)  
    //         0040fab2     XOR        EAX,EAX
    //         0040fab4     JMP        LAB_0040fabb
    //                               LAB_0040fab6                                                 XREF[2]:     0040fa96(j), 0040faa6(j)  
    //         0040fab6     SBB        EAX,EAX
    //         0040fab8     SBB        EAX,-0x1
    //                               LAB_0040fabb                                                 XREF[1]:     0040fab4(j)  
    //         0040fabb     TEST       EAX,EAX
    //         0040fabd     JNZ        LAB_0040fac7
    //                              aipbook.cpp:667 (2)
    //         0040fabf     MOV        AL,0x2
    //                              aipbook.cpp:673 (6)
    //         0040fac1     POP        EDI
    //         0040fac2     POP        ESI
    //         0040fac3     POP        EBX
    //         0040fac4     RET        0x4
    //                               LAB_0040fac7                                                 XREF[1]:     0040fabd(j)  
    //                              aipbook.cpp:668 (56)
    //         0040fac7     MOV        ESI,s_Flank                                      = 46h
    //         0040facc     MOV        EAX,EDI
    //                               LAB_0040face                                                 XREF[1]:     0040faf0(j)  
    //         0040face     MOV        DL,byte ptr [EAX]
    //         0040fad0     MOV        BL,byte ptr [ESI]=>s_Flank                       = 46h
    //                                                                                  = 61h
    //         0040fad2     MOV        this,DL
    //         0040fad4     CMP        DL,BL
    //         0040fad6     JNZ        LAB_0040faf6
    //         0040fad8     TEST       this,this
    //         0040fada     JZ         LAB_0040faf2
    //         0040fadc     MOV        DL,byte ptr [EAX + 0x1]
    //         0040fadf     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5ed            = 6Ch
    //                                                                                  = 6Eh
    //         0040fae2     MOV        this,DL
    //         0040fae4     CMP        DL,BL
    //         0040fae6     JNZ        LAB_0040faf6
    //         0040fae8     ADD        EAX,0x2
    //         0040faeb     ADD        ESI,0x2
    //         0040faee     TEST       this,this
    //         0040faf0     JNZ        LAB_0040face
    //                               LAB_0040faf2                                                 XREF[1]:     0040fada(j)  
    //         0040faf2     XOR        EAX,EAX
    //         0040faf4     JMP        LAB_0040fafb
    //                               LAB_0040faf6                                                 XREF[2]:     0040fad6(j), 0040fae6(j)  
    //         0040faf6     SBB        EAX,EAX
    //         0040faf8     SBB        EAX,-0x1
    //                               LAB_0040fafb                                                 XREF[1]:     0040faf4(j)  
    //         0040fafb     TEST       EAX,EAX
    //         0040fafd     JNZ        LAB_0040fb07
    //                              aipbook.cpp:669 (2)
    //         0040faff     MOV        AL,0x3
    //                              aipbook.cpp:673 (6)
    //         0040fb01     POP        EDI
    //         0040fb02     POP        ESI
    //         0040fb03     POP        EBX
    //         0040fb04     RET        0x4
    //                               LAB_0040fb07                                                 XREF[1]:     0040fafd(j)  
    //                              aipbook.cpp:670 (54)
    //         0040fb07     MOV        ESI,s_Recon                                      = 52h
    //         0040fb0c     MOV        EAX,EDI
    //                               LAB_0040fb0e                                                 XREF[1]:     0040fb30(j)  
    //         0040fb0e     MOV        DL,byte ptr [EAX]
    //         0040fb10     MOV        BL,byte ptr [ESI]=>s_Recon                       = 52h
    //                                                                                  = 63h
    //         0040fb12     MOV        this,DL
    //         0040fb14     CMP        DL,BL
    //         0040fb16     JNZ        LAB_0040fb43
    //         0040fb18     TEST       this,this
    //         0040fb1a     JZ         LAB_0040fb32
    //         0040fb1c     MOV        DL,byte ptr [EAX + 0x1]
    //         0040fb1f     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f5e5            = 65h
    //                                                                                  = 6Fh
    //         0040fb22     MOV        this,DL
    //         0040fb24     CMP        DL,BL
    //         0040fb26     JNZ        LAB_0040fb43
    //         0040fb28     ADD        EAX,0x2
    //         0040fb2b     ADD        ESI,0x2
    //         0040fb2e     TEST       this,this
    //         0040fb30     JNZ        LAB_0040fb0e
    //                               LAB_0040fb32                                                 XREF[1]:     0040fb1a(j)  
    //         0040fb32     XOR        EAX,EAX
    //         0040fb34     TEST       EAX,EAX
    //         0040fb36     SETNZ      AL
    //         0040fb39     DEC        EAX
    //         0040fb3a     AND        EAX,0x4
    //                              aipbook.cpp:673 (6)
    //         0040fb3d     POP        EDI
    //         0040fb3e     POP        ESI
    //         0040fb3f     POP        EBX
    //         0040fb40     RET        0x4
    //                               LAB_0040fb43                                                 XREF[2]:     0040fb16(j), 0040fb26(j)  
    //                              aipbook.cpp:670 (2)
    //         0040fb43     SBB        EAX,EAX
    //                              aipbook.cpp:673 (18)
    //         0040fb45     POP        EDI
    //         0040fb46     SBB        EAX,-0x1
    //         0040fb49     POP        ESI
    //         0040fb4a     TEST       EAX,EAX
    //         0040fb4c     SETNZ      AL
    //         0040fb4f     DEC        EAX
    //         0040fb50     POP        EBX
    //         0040fb51     AND        EAX,0x4
    //         0040fb54     RET        0x4
}

// Offset: 0x0040FB60
char* convertToNameType(AIPlay* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: char * __thiscall AIPlay::convertToNameType(unsigned char)const                            *
    //                              *********************************************************************************************************
    //                              char * __thiscall convertToNameType(AIPlay * this, uchar param_1)
    //              char *            EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0040fb60(R)  
    //                               ?convertToNameType@AIPlay@@IBEPADE@Z                         XREF[1]:     typeName:0040f3a4(c)  
    //                               AIPlay::convertToNameType
    //                              aipbook.cpp:678 (22)
    //         0040fb60     MOV        EAX,dword ptr [ESP + param_1]
    //         0040fb64     AND        EAX,0xff
    //         0040fb69     DEC        EAX
    //         0040fb6a     CMP        EAX,0x3
    //         0040fb6d     JA         switchD_0040fb6f::default
    //                               switchD_0040fb6f::switchD
    //         0040fb6f     JMP        dword ptr [EAX*0x4 + switchD_0040fb6f::switchd   = 0040fb76
    //                               switchD_0040fb6f::caseD_1                                    XREF[2]:     0040fb6f(j), 0040fba0(*)  
    //                              aipbook.cpp:680 (5)
    //         0040fb76     MOV        EAX,s_Attack                                     = 41h
    //                              aipbook.cpp:686 (3)
    //         0040fb7b     RET        0x4
    //                               switchD_0040fb6f::caseD_2                                    XREF[2]:     0040fb6f(j), 0040fba4(*)  
    //                              aipbook.cpp:681 (5)
    //         0040fb7e     MOV        EAX,s_Annoy                                      = 41h
    //                              aipbook.cpp:686 (3)
    //         0040fb83     RET        0x4
    //                               switchD_0040fb6f::caseD_3                                    XREF[2]:     0040fb6f(j), 0040fba8(*)  
    //                              aipbook.cpp:682 (5)
    //         0040fb86     MOV        EAX,s_Flank                                      = 46h
    //                              aipbook.cpp:686 (3)
    //         0040fb8b     RET        0x4
    //                               switchD_0040fb6f::caseD_4                                    XREF[2]:     0040fb6f(j), 0040fbac(*)  
    //                              aipbook.cpp:683 (5)
    //         0040fb8e     MOV        EAX,s_Recon                                      = 52h
    //                              aipbook.cpp:686 (3)
    //         0040fb93     RET        0x4
    //                               switchD_0040fb6f::default                                    XREF[1]:     0040fb6d(j)  
    //                              aipbook.cpp:685 (5)
    //         0040fb96     MOV        EAX,s_Invalid                                    = "Invalid"
    //                              aipbook.cpp:686 (21)
    //         0040fb9b     RET        0x4
}

// Offset: 0x0040FB9E
undefined FUN_0040fb9e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0040fb9e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0040fb9e
    //         0040fb9e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040fb6f::switchdataD_0040fba0                       XREF[1]:     convertToNameType:0040fb6f(*)  
}

// Offset: 0x0040FBB0
int locationsOnMap(AIPlay* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlay::locationsOnMap(int,int,int,int)                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall locationsOnMap(AIPlay * this, int param_1, int param_
    //              int               EAX:4          <RETURN>
    //              AIPlay *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fbb2(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040fbb7(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040fbed(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040fbf3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040fbbd(W), 0040fbff(R), 0040fc0d(W)  
    //              int               Stack[-0x8]:4  p
    //                               ?locationsOnMap@AIPlay@@QAEHHHHH@Z
    //                               AIPlay::locationsOnMap
    //                              aipbook.cpp:691 (2)
    //         0040fbb0     PUSH       this
    //         0040fbb1     PUSH       EBX
    //                              aipbook.cpp:692 (25)
    //         0040fbb2     MOV        EBX,dword ptr [ESP + param_1]
    //         0040fbb6     PUSH       EBP
    //         0040fbb7     MOV        EBP,dword ptr [ESP + param_2]
    //         0040fbbb     PUSH       ESI
    //         0040fbbc     PUSH       EDI
    //         0040fbbd     MOV        dword ptr [ESP + local_4],0x0
    //         0040fbc5     LEA        EDI,[ECX + this->phases[0].commands[0].groupVa
    //                               LAB_0040fbcb                                                 XREF[1]:     0040fc11(j)  
    //                              aipbook.cpp:693 (2)
    //         0040fbcb     XOR        ESI,ESI
    //                               LAB_0040fbcd                                                 XREF[1]:     0040fbfd(j)  
    //                              aipbook.cpp:696 (8)
    //         0040fbcd     PUSH       ESI
    //         0040fbce     MOV        this,EDI
    //         0040fbd0     CALL       AIPlayPhase::command                             AIPlayPhaseCommand * command(AIPlayPhase * th
    //                              aipbook.cpp:697 (6)
    //         0040fbd5     CMP        byte ptr [EAX + 0x1],0x1
    //         0040fbd9     JNZ        LAB_0040fbf9
    //                              aipbook.cpp:698 (3)
    //         0040fbdb     MOV        this,dword ptr [EAX + 0x4]
    //                              aipbook.cpp:699 (7)
    //         0040fbde     MOV        EAX,dword ptr [EAX + 0x8]
    //         0040fbe1     ADD        this,EBX
    //         0040fbe3     ADD        EAX,EBP
    //                              aipbook.cpp:700 (20)
    //         0040fbe5     TEST       this,this
    //         0040fbe7     JL         LAB_0040fc20
    //         0040fbe9     TEST       EAX,EAX
    //         0040fbeb     JL         LAB_0040fc20
    //         0040fbed     CMP        this,dword ptr [ESP + param_3]
    //         0040fbf1     JGE        LAB_0040fc20
    //         0040fbf3     CMP        EAX,dword ptr [ESP + param_4]
    //         0040fbf7     JGE        LAB_0040fc20
    //                               LAB_0040fbf9                                                 XREF[1]:     0040fbd9(j)  
    //                              aipbook.cpp:693 (26)
    //         0040fbf9     INC        ESI
    //         0040fbfa     CMP        ESI,0x5
    //         0040fbfd     JL         LAB_0040fbcd
    //         0040fbff     MOV        EAX,dword ptr [ESP + local_4]
    //         0040fc03     ADD        EDI,0x8c
    //         0040fc09     INC        EAX
    //         0040fc0a     CMP        EAX,0xa
    //         0040fc0d     MOV        dword ptr [ESP + local_4],EAX
    //         0040fc11     JL         LAB_0040fbcb
    //                              aipbook.cpp:705 (5)
    //         0040fc13     MOV        EAX,0x1
    //                              aipbook.cpp:706 (8)
    //         0040fc18     POP        EDI
    //         0040fc19     POP        ESI
    //         0040fc1a     POP        EBP
    //         0040fc1b     POP        EBX
    //         0040fc1c     POP        this
    //         0040fc1d     RET        0x10
    //                               LAB_0040fc20                                                 XREF[4]:     0040fbe7(j), 0040fbeb(j), 
    //                                                                                                         0040fbf1(j), 0040fbf7(j)  
    //                              aipbook.cpp:701 (2)
    //         0040fc20     XOR        EAX,EAX
    //                              aipbook.cpp:706 (8)
    //         0040fc22     POP        EDI
    //         0040fc23     POP        ESI
    //         0040fc24     POP        EBP
    //         0040fc25     POP        EBX
    //         0040fc26     POP        this
    //         0040fc27     RET        0x10
}

// Offset: 0x0040FC30
undefined AIPlayStatus(AIPlayStatus* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayStatus::AIPlayStatus(void)                                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayStatus(AIPlayStatus * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //                               ??0AIPlayStatus@@QAE@XZ                                      XREF[4]:     load:004137ac(c), 
    //                               AIPlayStatus::AIPlayStatus                                                setPlayStatus:00417812(c), 
    //                                                                                                         processOrder:00417be2(c), 
    //                                                                                                         objectToAttackWithPlay:004dc54d(c)
    //                              aipbook.cpp:719 (76)
    //         0040fc30     PUSH       ESI
    //         0040fc31     PUSH       EDI
    //         0040fc32     MOV        ESI,this
    //         0040fc34     PUSH       0x0
    //         0040fc36     OR         EDI,0xffffffff
    //         0040fc39     PUSH       0x0
    //         0040fc3b     PUSH       0x0
    //         0040fc3d     LEA        this,[ESI + 0x198]
    //         0040fc43     MOV        dword ptr [ESI + 0x190],EDI
    //         0040fc49     MOV        dword ptr [ESI + 0x194],EDI
    //         0040fc4f     CALL       XYZ::XYZ                                         undefined XYZ(XYZ * this, int param_1, int pa
    //         0040fc54     MOV        byte ptr [ESI + 0x1b8],0xfd
    //         0040fc5b     MOV        dword ptr [ESI + 0x1bc],EDI
    //         0040fc61     MOV        dword ptr [ESI + 0x1c0],0x0
    //         0040fc6b     MOV        byte ptr [ESI + 0x1c4],0x0
    //         0040fc72     LEA        EAX,[ESI + 0x5]
    //         0040fc75     MOV        this,0x32
    //         0040fc7a     MOV        DL,0xff
    //                               LAB_0040fc7c                                                 XREF[1]:     0040fc88(j)  
    //                              aipbook.cpp:721 (3)
    //         0040fc7c     MOV        dword ptr [EAX + -0x5],EDI
    //                              aipbook.cpp:722 (3)
    //         0040fc7f     MOV        byte ptr [EAX + -0x1],DL
    //                              aipbook.cpp:723 (8)
    //         0040fc82     MOV        byte ptr [EAX],DL
    //         0040fc84     ADD        EAX,0x8
    //         0040fc87     DEC        this
    //         0040fc88     JNZ        LAB_0040fc7c
    //                              aipbook.cpp:726 (6)
    //         0040fc8a     MOV        dword ptr [ESI + 0x1a4],EDI
    //                              aipbook.cpp:727 (29)
    //         0040fc90     MOV        EAX,ESI
    //         0040fc92     MOV        dword ptr [ESI + 0x1a8],EDI
    //         0040fc98     MOV        dword ptr [ESI + 0x1ac],EDI
    //         0040fc9e     MOV        dword ptr [ESI + 0x1b0],EDI
    //         0040fca4     MOV        dword ptr [ESI + 0x1b4],EDI
    //         0040fcaa     POP        EDI
    //         0040fcab     POP        ESI
    //         0040fcac     RET
}

// Offset: 0x0040FCB0
int originalHitPoints(AIPlayStatus* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayStatus::originalHitPoints(int)const                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall originalHitPoints(AIPlayStatus * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fcb0(R)  
    //                               ?originalHitPoints@AIPlayStatus@@QBEHH@Z                     XREF[2]:     updateGroup:004145bc(c), 
    //                               AIPlayStatus::originalHitPoints                                           updateGroup:004145d2(c)  
    //                              aipbook.cpp:732 (13)
    //         0040fcb0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040fcb4     TEST       EAX,EAX
    //         0040fcb6     JL         LAB_0040fcc7
    //         0040fcb8     CMP        EAX,0x5
    //         0040fcbb     JGE        LAB_0040fcc7
    //                              aipbook.cpp:734 (7)
    //         0040fcbd     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->originalH
    //                              aipbook.cpp:736 (3)
    //         0040fcc4     RET        0x4
    //                               LAB_0040fcc7                                                 XREF[2]:     0040fcb6(j), 0040fcbb(j)  
    //                              aipbook.cpp:735 (3)
    //         0040fcc7     OR         EAX,0xffffffff
    //                              aipbook.cpp:736 (3)
    //         0040fcca     RET        0x4
}

// Offset: 0x0040FCD0
void setOriginalHitPoints(AIPlayStatus* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::setOriginalHitPoints(int,int)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall setOriginalHitPoints(AIPlayStatus * this, int param_
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fcd0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040fcdd(R)  
    //                               ?setOriginalHitPoints@AIPlayStatus@@QAEXHH@Z                 XREF[2]:     resetHitPoints:004101a0(c), 
    //                               AIPlayStatus::setOriginalHitPoints                                        updateGroup:00414387(c)  
    //                              aipbook.cpp:741 (13)
    //         0040fcd0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040fcd4     TEST       EAX,EAX
    //         0040fcd6     JL         LAB_0040fce8
    //         0040fcd8     CMP        EAX,0x5
    //         0040fcdb     JGE        LAB_0040fce8
    //                              aipbook.cpp:743 (11)
    //         0040fcdd     MOV        EDX,dword ptr [ESP + param_2]
    //         0040fce1     MOV        dword ptr [ECX + EAX*0x4 + this->originalHitPo
    //                               LAB_0040fce8                                                 XREF[2]:     0040fcd6(j), 0040fcdb(j)  
    //                              aipbook.cpp:744 (3)
    //         0040fce8     RET        0x8
}

// Offset: 0x0040FCF0
uchar numberInPlay(AIPlayStatus* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlayStatus::numberInPlay(void)const                                *
    //                              *********************************************************************************************************
    //                              uchar __thiscall numberInPlay(AIPlayStatus * this)
    //              uchar             AL:1           <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //                               ?numberInPlay@AIPlayStatus@@QBEEXZ                           XREF[3]:     fillGroups:0040f6a2(c), 
    //                               AIPlayStatus::numberInPlay                                                fillGroups:0040f81f(c), 
    //                                                                                                         fillGroups:0040f8c4(c)  
    //                              aipbook.cpp:749 (7)
    //         0040fcf0     XOR        AL,AL
    //         0040fcf2     MOV        EDX,0x32
    //                               LAB_0040fcf7                                                 XREF[1]:     0040fd02(j)  
    //                              aipbook.cpp:752 (5)
    //         0040fcf7     CMP        dword ptr [this->groupings[0].id],-0x1
    //         0040fcfa     JZ         LAB_0040fcfe
    //                              aipbook.cpp:753 (2)
    //         0040fcfc     INC        AL
    //                               LAB_0040fcfe                                                 XREF[1]:     0040fcfa(j)  
    //                              aipbook.cpp:751 (6)
    //         0040fcfe     ADD        this,0x8
    //         0040fd01     DEC        EDX
    //         0040fd02     JNZ        LAB_0040fcf7
    //                              aipbook.cpp:755 (1)
    //         0040fd04     RET
}

// Offset: 0x0040FD10
uchar numberInGroup(AIPlayStatus* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlayStatus::numberInGroup(int)                                     *
    //                              *********************************************************************************************************
    //                              uchar __thiscall numberInGroup(AIPlayStatus * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fd12(R)  
    //                               ?numberInGroup@AIPlayStatus@@QAEEH@Z                         XREF[2]:     fillGroups:0040f7b9(c), 
    //                               AIPlayStatus::numberInGroup                                               fillGroups:0040f7d0(c)  
    //                              aipbook.cpp:760 (2)
    //         0040fd10     PUSH       EBX
    //         0040fd11     PUSH       ESI
    //                              aipbook.cpp:761 (11)
    //         0040fd12     MOV        ESI,dword ptr [ESP + param_1]
    //         0040fd16     XOR        AL,AL
    //         0040fd18     MOV        EDX,0x32
    //                               LAB_0040fd1d                                                 XREF[1]:     0040fd31(j)  
    //                              aipbook.cpp:763 (14)
    //         0040fd1d     CMP        dword ptr [this->groupings[0].id],-0x1
    //         0040fd20     JZ         LAB_0040fd2d
    //         0040fd22     XOR        EBX,EBX
    //         0040fd24     MOV        BL,byte ptr [ECX + this+0x4]
    //         0040fd27     CMP        EBX,ESI
    //         0040fd29     JNZ        LAB_0040fd2d
    //                              aipbook.cpp:764 (2)
    //         0040fd2b     INC        AL
    //                               LAB_0040fd2d                                                 XREF[2]:     0040fd20(j), 0040fd29(j)  
    //                              aipbook.cpp:762 (6)
    //         0040fd2d     ADD        this,0x8
    //         0040fd30     DEC        EDX
    //         0040fd31     JNZ        LAB_0040fd1d
    //                              aipbook.cpp:766 (5)
    //         0040fd33     POP        ESI
    //         0040fd34     POP        EBX
    //         0040fd35     RET        0x4
}

// Offset: 0x0040FD40
uchar numberOfTypeInGroup(AIPlayStatus* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlayStatus::numberOfTypeInGroup(int,int)                           *
    //                              *********************************************************************************************************
    //                              uchar __thiscall numberOfTypeInGroup(AIPlayStatus * this, int param_
    //              uchar             AL:1           <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fd48(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040fd43(R)  
    //                               ?numberOfTypeInGroup@AIPlayStatus@@QAEEHH@Z                  XREF[3]:     fillGroups:0040f792(c), 
    //                               AIPlayStatus::numberOfTypeInGroup                                         fillGroups:0040f86b(c), 
    //                                                                                                         fillGroups:0040f956(c)  
    //                              aipbook.cpp:771 (3)
    //         0040fd40     PUSH       EBX
    //         0040fd41     PUSH       EBP
    //         0040fd42     PUSH       ESI
    //                              aipbook.cpp:772 (22)
    //         0040fd43     MOV        ESI,dword ptr [ESP + param_2]
    //         0040fd47     PUSH       EDI
    //         0040fd48     MOV        EDI,dword ptr [ESP + param_1]
    //         0040fd4c     XOR        AL,AL
    //         0040fd4e     ADD        this,0x5
    //         0040fd51     MOV        EDX,0x32
    //         0040fd56     OR         EBP,0xffffffff
    //                               LAB_0040fd59                                                 XREF[1]:     0040fd75(j)  
    //                              aipbook.cpp:776 (22)
    //         0040fd59     CMP        dword ptr [this->groupings[0].id + -0x5],EBP
    //         0040fd5c     JZ         LAB_0040fd71
    //         0040fd5e     XOR        EBX,EBX
    //         0040fd60     MOV        BL,byte ptr [this->groupings[0].id + -0x1]
    //         0040fd63     CMP        EBX,EDI
    //         0040fd65     JNZ        LAB_0040fd71
    //         0040fd67     XOR        EBX,EBX
    //         0040fd69     MOV        BL,byte ptr [this->groupings[0].id]
    //         0040fd6b     CMP        EBX,ESI
    //         0040fd6d     JNZ        LAB_0040fd71
    //                              aipbook.cpp:777 (2)
    //         0040fd6f     INC        AL
    //                               LAB_0040fd71                                                 XREF[3]:     0040fd5c(j), 0040fd65(j), 
    //                                                                                                         0040fd6d(j)  
    //                              aipbook.cpp:773 (6)
    //         0040fd71     ADD        this,0x8
    //         0040fd74     DEC        EDX
    //         0040fd75     JNZ        LAB_0040fd59
    //                              aipbook.cpp:779 (7)
    //         0040fd77     POP        EDI
    //         0040fd78     POP        ESI
    //         0040fd79     POP        EBP
    //         0040fd7a     POP        EBX
    //         0040fd7b     RET        0x8
}

// Offset: 0x0040FD80
uchar group(AIPlayStatus* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall AIPlayStatus::group(int)                                             *
    //                              *********************************************************************************************************
    //                              uchar __thiscall group(AIPlayStatus * this, int param_1)
    //              uchar             AL:1           <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fd81(R)  
    //                               ?group@AIPlayStatus@@QAEEH@Z                                 XREF[3]:     updateGroup:0041434d(c), 
    //                               AIPlayStatus::group                                                       selectNewPlayPhase:004149c7(c), 
    //                                                                                                         processGroupNotify:004195b6(c)  
    //                              aipbook.cpp:784 (1)
    //         0040fd80     PUSH       ESI
    //                              aipbook.cpp:785 (6)
    //         0040fd81     MOV        ESI,dword ptr [ESP + param_1]
    //         0040fd85     TEST       ESI,ESI
    //                              aipbook.cpp:786 (2)
    //         0040fd87     JL         LAB_0040fda8
    //                              aipbook.cpp:788 (2)
    //         0040fd89     XOR        EAX,EAX
    //                              aipbook.cpp:792 (15)
    //         0040fd8b     MOV        EDX,this
    //                               LAB_0040fd8d                                                 XREF[1]:     0040fd98(j)  
    //         0040fd8d     CMP        dword ptr [EDX],ESI
    //         0040fd8f     JZ         LAB_0040fda0
    //         0040fd91     INC        EAX
    //         0040fd92     ADD        EDX,0x8
    //         0040fd95     CMP        EAX,0x32
    //         0040fd98     JL         LAB_0040fd8d
    //                              aipbook.cpp:791 (2)
    //         0040fd9a     OR         AL,0xff
    //                              aipbook.cpp:792 (4)
    //         0040fd9c     POP        ESI
    //         0040fd9d     RET        0x4
    //                               LAB_0040fda0                                                 XREF[1]:     0040fd8f(j)  
    //                              aipbook.cpp:790 (4)
    //         0040fda0     MOV        AL,byte ptr [ECX + EAX*0x8 + this+0x4]
    //                              aipbook.cpp:792 (10)
    //         0040fda4     POP        ESI
    //         0040fda5     RET        0x4
    //                               LAB_0040fda8                                                 XREF[1]:     0040fd87(j)  
    //         0040fda8     OR         AL,0xff
    //         0040fdaa     POP        ESI
    //         0040fdab     RET        0x4
}

// Offset: 0x0040FDB0
int addGrouping(AIPlayStatus* this_, int param_2, uchar param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayStatus::addGrouping(int,unsigned char,unsigned char)                     *
    //                              *********************************************************************************************************
    //                              int __thiscall addGrouping(AIPlayStatus * this, int param_1, uchar p
    //              int               EAX:4          <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fdc7(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0040fdce(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0040fdd6(R)  
    //                               ?addGrouping@AIPlayStatus@@QAEHHEE@Z                         XREF[3]:     fillGroups:0040f684(c), 
    //                               AIPlayStatus::addGrouping                                                 fillGroups:0040f802(c), 
    //                                                                                                         fillGroups:0040f88f(c)  
    //                              aipbook.cpp:797 (4)
    //         0040fdb0     XOR        EAX,EAX
    //         0040fdb2     MOV        EDX,this
    //                               LAB_0040fdb4                                                 XREF[1]:     0040fdc0(j)  
    //                              aipbook.cpp:799 (14)
    //         0040fdb4     CMP        dword ptr [EDX],-0x1
    //         0040fdb7     JZ         LAB_0040fdc7
    //         0040fdb9     INC        EAX
    //         0040fdba     ADD        EDX,0x8
    //         0040fdbd     CMP        EAX,0x32
    //         0040fdc0     JL         LAB_0040fdb4
    //                              aipbook.cpp:805 (2)
    //         0040fdc2     XOR        EAX,EAX
    //                              aipbook.cpp:806 (3)
    //         0040fdc4     RET        0xc
    //                               LAB_0040fdc7                                                 XREF[1]:     0040fdb7(j)  
    //                              aipbook.cpp:800 (7)
    //         0040fdc7     MOV        EDX,dword ptr [ESP + param_1]
    //         0040fdcb     MOV        dword ptr [this->groupings[0].id + EAX*0x8],EDX
    //                              aipbook.cpp:801 (8)
    //         0040fdce     MOV        DL,byte ptr [ESP + param_2]
    //         0040fdd2     MOV        byte ptr [ECX + EAX*0x8 + this+0x4],DL
    //                              aipbook.cpp:802 (8)
    //         0040fdd6     MOV        DL,byte ptr [ESP + param_3]
    //         0040fdda     MOV        byte ptr [ECX + EAX*0x8 + this+0x5],DL
    //                              aipbook.cpp:803 (5)
    //         0040fdde     MOV        EAX,0x1
    //                              aipbook.cpp:806 (3)
    //         0040fde3     RET        0xc
}

// Offset: 0x0040FDF0
int removeGrouping(AIPlayStatus* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayStatus::removeGrouping(int)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall removeGrouping(AIPlayStatus * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040fdf1(R)  
    //                               ?removeGrouping@AIPlayStatus@@QAEHH@Z
    //                               AIPlayStatus::removeGrouping
    //                              aipbook.cpp:811 (1)
    //         0040fdf0     PUSH       ESI
    //                              aipbook.cpp:812 (8)
    //         0040fdf1     MOV        ESI,dword ptr [ESP + param_1]
    //         0040fdf5     XOR        EAX,EAX
    //         0040fdf7     MOV        EDX,this
    //                               LAB_0040fdf9                                                 XREF[1]:     0040fe04(j)  
    //                              aipbook.cpp:813 (13)
    //         0040fdf9     CMP        dword ptr [EDX],ESI
    //         0040fdfb     JZ         LAB_0040fe0c
    //         0040fdfd     INC        EAX
    //         0040fdfe     ADD        EDX,0x8
    //         0040fe01     CMP        EAX,0x32
    //         0040fe04     JL         LAB_0040fdf9
    //                              aipbook.cpp:819 (2)
    //         0040fe06     XOR        EAX,EAX
    //                              aipbook.cpp:820 (4)
    //         0040fe08     POP        ESI
    //         0040fe09     RET        0x4
    //                               LAB_0040fe0c                                                 XREF[1]:     0040fdfb(j)  
    //                              aipbook.cpp:815 (13)
    //         0040fe0c     MOV        DL,0xff
    //         0040fe0e     MOV        dword ptr [this->groupings[0].id + EAX*0x8],0x
    //         0040fe15     MOV        byte ptr [ECX + EAX*0x8 + this+0x4],DL
    //                              aipbook.cpp:816 (4)
    //         0040fe19     MOV        byte ptr [ECX + EAX*0x8 + this+0x5],DL
    //                              aipbook.cpp:817 (5)
    //         0040fe1d     MOV        EAX,0x1
    //                              aipbook.cpp:820 (4)
    //         0040fe22     POP        ESI
    //         0040fe23     RET        0x4
}

// Offset: 0x0040FE30
void zeroAllGroupings(AIPlayStatus* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::zeroAllGroupings(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall zeroAllGroupings(AIPlayStatus * this)
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //                               ?zeroAllGroupings@AIPlayStatus@@QAEXXZ
    //                               AIPlayStatus::zeroAllGroupings
    //                              aipbook.cpp:825 (1)
    //         0040fe30     PUSH       ESI
    //                              aipbook.cpp:826 (13)
    //         0040fe31     LEA        EAX,[ECX + this+0x5]
    //         0040fe34     MOV        this,0x32
    //         0040fe39     OR         ESI,0xffffffff
    //         0040fe3c     MOV        DL,0xff
    //                               LAB_0040fe3e                                                 XREF[1]:     0040fe4a(j)  
    //                              aipbook.cpp:827 (3)
    //         0040fe3e     MOV        dword ptr [EAX + -0x5],ESI
    //                              aipbook.cpp:828 (3)
    //         0040fe41     MOV        byte ptr [EAX + -0x1],DL
    //                              aipbook.cpp:829 (8)
    //         0040fe44     MOV        byte ptr [EAX],DL
    //         0040fe46     ADD        EAX,0x8
    //         0040fe49     DEC        this
    //         0040fe4a     JNZ        LAB_0040fe3e
    //                              aipbook.cpp:831 (2)
    //         0040fe4c     POP        ESI
    //         0040fe4d     RET
}

// Offset: 0x0040FE50
void copyUnits(AIPlayStatus* this_, int* param_2, int* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::copyUnits(int *,int &)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall copyUnits(AIPlayStatus * this, int * param_1, int * 
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int *             Stack[0x4]:4   param_1                   XREF[1]:     0040fe57(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[1]:     0040fe50(R)  
    //                               ?copyUnits@AIPlayStatus@@QAEXPAHAAH@Z                        XREF[1]:     objectToAttackWithPlay:004dc6d2(c)
    //                               AIPlayStatus::copyUnits
    //                              aipbook.cpp:836 (22)
    //         0040fe50     MOV        EDX,dword ptr [ESP + param_2]
    //         0040fe54     PUSH       EBX
    //         0040fe55     PUSH       ESI
    //         0040fe56     PUSH       EDI
    //         0040fe57     MOV        EDI,dword ptr [ESP + param_1]
    //         0040fe5b     MOV        dword ptr [EDX],0x0
    //         0040fe61     MOV        ESI,0x32
    //                               LAB_0040fe66                                                 XREF[1]:     0040fe7b(j)  
    //                              aipbook.cpp:839 (7)
    //         0040fe66     MOV        EAX,dword ptr [this->groupings[0].id]
    //         0040fe68     CMP        EAX,-0x1
    //         0040fe6b     JZ         LAB_0040fe77
    //                              aipbook.cpp:840 (5)
    //         0040fe6d     MOV        EBX,dword ptr [EDX]
    //         0040fe6f     MOV        dword ptr [EDI + EBX*0x4],EAX
    //                              aipbook.cpp:841 (11)
    //         0040fe72     MOV        EAX,dword ptr [EDX]
    //         0040fe74     INC        EAX
    //         0040fe75     MOV        dword ptr [EDX],EAX
    //                               LAB_0040fe77                                                 XREF[1]:     0040fe6b(j)  
    //         0040fe77     ADD        this,0x8
    //         0040fe7a     DEC        ESI
    //         0040fe7b     JNZ        LAB_0040fe66
    //                              aipbook.cpp:843 (6)
    //         0040fe7d     POP        EDI
    //         0040fe7e     POP        ESI
    //         0040fe7f     POP        EBX
    //         0040fe80     RET        0x8
}

// Offset: 0x0040FE90
void load(AIPlayStatus* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::load(int)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall load(AIPlayStatus * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[7]:     0040fe94(R), 0040febc(*), 0040fec9(R), 0040fed0(*), 
    //                                                                                     0040fee3(R), 0040feea(*), 0040fefd(R)  
    //                               ?load@AIPlayStatus@@QAEXH@Z                                  XREF[1]:     load:004137c6(c)  
    //                               AIPlayStatus::load
    //                              aipbook.cpp:848 (4)
    //         0040fe90     PUSH       ESI
    //         0040fe91     MOV        ESI,this
    //         0040fe93     PUSH       EDI
    //                              aipbook.cpp:850 (22)
    //         0040fe94     MOV        EDI,dword ptr [ESP + param_1]
    //         0040fe98     LEA        EAX,[ESI + 0x190]
    //         0040fe9e     PUSH       0x4
    //         0040fea0     PUSH       EAX
    //         0040fea1     PUSH       EDI
    //         0040fea2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040fea7     ADD        ESP,0xc
    //                              aipbook.cpp:851 (18)
    //         0040feaa     LEA        this,[ESI + 0x194]
    //         0040feb0     PUSH       0x4
    //         0040feb2     PUSH       this
    //         0040feb3     PUSH       EDI
    //         0040feb4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040feb9     ADD        ESP,0xc
    //                              aipbook.cpp:852 (13)
    //         0040febc     LEA        EDX=>param_1,[ESP + 0xc]
    //         0040fec0     PUSH       0x4
    //         0040fec2     PUSH       EDX
    //         0040fec3     PUSH       EDI
    //         0040fec4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aipbook.cpp:853 (7)
    //         0040fec9     MOV        EAX,dword ptr [ESP + param_1]
    //         0040fecd     ADD        ESP,0xc
    //                              aipbook.cpp:854 (19)
    //         0040fed0     LEA        this=>param_1,[ESP + 0xc]
    //         0040fed4     MOV        dword ptr [ESI + 0x198],EAX
    //         0040feda     PUSH       0x4
    //         0040fedc     PUSH       this
    //         0040fedd     PUSH       EDI
    //         0040fede     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aipbook.cpp:855 (7)
    //         0040fee3     MOV        EDX,dword ptr [ESP + param_1]
    //         0040fee7     ADD        ESP,0xc
    //                              aipbook.cpp:856 (19)
    //         0040feea     LEA        EAX=>param_1,[ESP + 0xc]
    //         0040feee     MOV        dword ptr [ESI + 0x19c],EDX
    //         0040fef4     PUSH       0x4
    //         0040fef6     PUSH       EAX
    //         0040fef7     PUSH       EDI
    //         0040fef8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aipbook.cpp:857 (7)
    //         0040fefd     MOV        this,dword ptr [ESP + param_1]
    //         0040ff01     ADD        ESP,0xc
    //                              aipbook.cpp:858 (24)
    //         0040ff04     LEA        EDX,[ESI + 0x1a4]
    //         0040ff0a     MOV        dword ptr [ESI + 0x1a0],this
    //         0040ff10     PUSH       0x14
    //         0040ff12     PUSH       EDX
    //         0040ff13     PUSH       EDI
    //         0040ff14     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ff19     ADD        ESP,0xc
    //                              aipbook.cpp:859 (18)
    //         0040ff1c     LEA        EAX,[ESI + 0x1b8]
    //         0040ff22     PUSH       0x1
    //         0040ff24     PUSH       EAX
    //         0040ff25     PUSH       EDI
    //         0040ff26     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ff2b     ADD        ESP,0xc
    //                              aipbook.cpp:860 (15)
    //         0040ff2e     PUSH       0x190
    //         0040ff33     PUSH       ESI
    //         0040ff34     PUSH       EDI
    //         0040ff35     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ff3a     ADD        ESP,0xc
    //                              aipbook.cpp:861 (18)
    //         0040ff3d     LEA        this,[ESI + 0x1bc]
    //         0040ff43     PUSH       0x4
    //         0040ff45     PUSH       this
    //         0040ff46     PUSH       EDI
    //         0040ff47     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ff4c     ADD        ESP,0xc
    //                              aipbook.cpp:862 (18)
    //         0040ff4f     ADD        ESI,0x1c0
    //         0040ff55     PUSH       0x4
    //         0040ff57     PUSH       ESI
    //         0040ff58     PUSH       EDI
    //         0040ff59     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ff5e     ADD        ESP,0xc
    //                              aipbook.cpp:863 (5)
    //         0040ff61     POP        EDI
    //         0040ff62     POP        ESI
    //         0040ff63     RET        0x4
}

// Offset: 0x0040FF70
void save(AIPlayStatus* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::save(int)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall save(AIPlayStatus * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[7]:     0040ff74(R), 0040ffa2(*), 0040ffa6(W), 0040ffbc(*), 
    //                                                                                     0040ffc0(W), 0040ffd6(*), 0040ffda(W)  
    //                               ?save@AIPlayStatus@@QAEXH@Z                                  XREF[1]:     save:00413428(c)  
    //                               AIPlayStatus::save
    //                              aipbook.cpp:868 (4)
    //         0040ff70     PUSH       ESI
    //         0040ff71     MOV        ESI,this
    //         0040ff73     PUSH       EDI
    //                              aipbook.cpp:869 (22)
    //         0040ff74     MOV        EDI,dword ptr [ESP + param_1]
    //         0040ff78     LEA        EAX,[ESI + 0x190]
    //         0040ff7e     PUSH       0x4
    //         0040ff80     PUSH       EAX
    //         0040ff81     PUSH       EDI
    //         0040ff82     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040ff87     ADD        ESP,0xc
    //                              aipbook.cpp:870 (15)
    //         0040ff8a     LEA        this,[ESI + 0x194]
    //         0040ff90     PUSH       0x4
    //         0040ff92     PUSH       this
    //         0040ff93     PUSH       EDI
    //         0040ff94     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aipbook.cpp:871 (9)
    //         0040ff99     MOV        EDX,dword ptr [ESI + 0x198]
    //         0040ff9f     ADD        ESP,0xc
    //                              aipbook.cpp:872 (17)
    //         0040ffa2     LEA        EAX=>param_1,[ESP + 0xc]
    //         0040ffa6     MOV        dword ptr [ESP + param_1],EDX
    //         0040ffaa     PUSH       0x4
    //         0040ffac     PUSH       EAX
    //         0040ffad     PUSH       EDI
    //         0040ffae     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aipbook.cpp:873 (9)
    //         0040ffb3     MOV        this,dword ptr [ESI + 0x19c]
    //         0040ffb9     ADD        ESP,0xc
    //                              aipbook.cpp:874 (17)
    //         0040ffbc     LEA        EDX=>param_1,[ESP + 0xc]
    //         0040ffc0     MOV        dword ptr [ESP + param_1],this
    //         0040ffc4     PUSH       0x4
    //         0040ffc6     PUSH       EDX
    //         0040ffc7     PUSH       EDI
    //         0040ffc8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aipbook.cpp:875 (9)
    //         0040ffcd     MOV        EAX,dword ptr [ESI + 0x1a0]
    //         0040ffd3     ADD        ESP,0xc
    //                              aipbook.cpp:876 (20)
    //         0040ffd6     LEA        this=>param_1,[ESP + 0xc]
    //         0040ffda     MOV        dword ptr [ESP + param_1],EAX
    //         0040ffde     PUSH       0x4
    //         0040ffe0     PUSH       this
    //         0040ffe1     PUSH       EDI
    //         0040ffe2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040ffe7     ADD        ESP,0xc
    //                              aipbook.cpp:877 (18)
    //         0040ffea     LEA        EDX,[ESI + 0x1a4]
    //         0040fff0     PUSH       0x14
    //         0040fff2     PUSH       EDX
    //         0040fff3     PUSH       EDI
    //         0040fff4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040fff9     ADD        ESP,0xc
    //                              aipbook.cpp:878 (18)
    //         0040fffc     LEA        EAX,[ESI + 0x1b8]
    //         00410002     PUSH       0x1
    //         00410004     PUSH       EAX
    //         00410005     PUSH       EDI
    //         00410006     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0041000b     ADD        ESP,0xc
    //                              aipbook.cpp:879 (15)
    //         0041000e     PUSH       0x190
    //         00410013     PUSH       ESI
    //         00410014     PUSH       EDI
    //         00410015     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0041001a     ADD        ESP,0xc
    //                              aipbook.cpp:880 (18)
    //         0041001d     LEA        this,[ESI + 0x1bc]
    //         00410023     PUSH       0x4
    //         00410025     PUSH       this
    //         00410026     PUSH       EDI
    //         00410027     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0041002c     ADD        ESP,0xc
    //                              aipbook.cpp:881 (18)
    //         0041002f     ADD        ESI,0x1c0
    //         00410035     PUSH       0x4
    //         00410037     PUSH       ESI
    //         00410038     PUSH       EDI
    //         00410039     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0041003e     ADD        ESP,0xc
    //                              aipbook.cpp:882 (5)
    //         00410041     POP        EDI
    //         00410042     POP        ESI
    //         00410043     RET        0x4
}

// Offset: 0x00410050
void copy(AIPlayStatus* this_, AIPlayStatus* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::copy(class AIPlayStatus *)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall copy(AIPlayStatus * this, AIPlayStatus * param_1)
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              AIPlayStatus *    Stack[0x4]:4   param_1                   XREF[1]:     00410050(R)  
    //                               ?copy@AIPlayStatus@@QAEXPAV1@@Z                              XREF[1]:     setPlayStatus:0041783c(c)  
    //                               AIPlayStatus::copy
    //                              aipbook.cpp:887 (24)
    //         00410050     MOV        EDX,dword ptr [ESP + param_1]
    //         00410054     PUSH       EBP
    //         00410055     PUSH       ESI
    //         00410056     PUSH       EDI
    //         00410057     MOV        EAX,dword ptr [EDX + 0x190]
    //         0041005d     MOV        EBP,0x32
    //         00410062     MOV        dword ptr [ECX + this->playNumberValue],EAX
    //                              aipbook.cpp:889 (12)
    //         00410068     MOV        EAX,dword ptr [EDX + 0x194]
    //         0041006e     MOV        dword ptr [ECX + this->targetValue],EAX
    //                              aipbook.cpp:890 (36)
    //         00410074     MOV        EAX,dword ptr [EDX + 0x1a0]
    //         0041007a     MOV        ESI,dword ptr [EDX + 0x19c]
    //         00410080     MOV        EDI,dword ptr [EDX + 0x198]
    //         00410086     MOV        dword ptr [ECX + this->originalPointValue.xVal
    //         0041008c     MOV        dword ptr [ECX + this+0x19c],ESI
    //         00410092     MOV        dword ptr [ECX + this+0x1a0],EAX
    //                              aipbook.cpp:891 (12)
    //         00410098     MOV        AL,byte ptr [EDX + 0x1b8]
    //         0041009e     MOV        byte ptr [ECX + this->currentPhaseValue],AL
    //                              aipbook.cpp:892 (12)
    //         004100a4     MOV        EAX,dword ptr [EDX + 0x1bc]
    //         004100aa     MOV        dword ptr [ECX + this->savedAttackerValue],EAX
    //                              aipbook.cpp:893 (6)
    //         004100b0     MOV        EAX,dword ptr [EDX + 0x1c0]
    //                              aipbook.cpp:894 (15)
    //         004100b6     MOV        EDI,EDX
    //         004100b8     MOV        dword ptr [ECX + this->lastPhaseChangeTimeValu
    //         004100be     MOV        ESI,EDX
    //         004100c0     LEA        EAX,[ECX + this+0x4]
    //         004100c3     SUB        EDI,this
    //                               LAB_004100c5                                                 XREF[1]:     004100dc(j)  
    //                              aipbook.cpp:895 (8)
    //         004100c5     MOV        EDX,dword ptr [ESI]
    //         004100c7     ADD        ESI,0x8
    //         004100ca     MOV        dword ptr [EAX + -0x4],EDX
    //                              aipbook.cpp:896 (5)
    //         004100cd     MOV        DL,byte ptr [EDI + EAX*0x1]
    //         004100d0     MOV        byte ptr [EAX],DL
    //                              aipbook.cpp:897 (12)
    //         004100d2     MOV        DL,byte ptr [ESI + -0x3]
    //         004100d5     MOV        byte ptr [EAX + 0x1],DL
    //         004100d8     ADD        EAX,0x8
    //         004100db     DEC        EBP
    //         004100dc     JNZ        LAB_004100c5
    //                              aipbook.cpp:901 (28)
    //         004100de     LEA        EAX,[ECX + this->originalHitPointsValue[0]]
    //         004100e4     MOV        this,0x5
    //                               LAB_004100e9                                                 XREF[1]:     004100f2(j)  
    //         004100e9     MOV        EDX,dword ptr [EAX + EDI*0x1]
    //         004100ec     MOV        dword ptr [EAX],EDX
    //         004100ee     ADD        EAX,0x4
    //         004100f1     DEC        this
    //         004100f2     JNZ        LAB_004100e9
    //         004100f4     POP        EDI
    //         004100f5     POP        ESI
    //         004100f6     POP        EBP
    //         004100f7     RET        0x4
}

// Offset: 0x00410100
void removeDeadUnits(AIPlayStatus* this_, int param_2, RGE_Game_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::removeDeadUnits(int,class RGE_Game_World *)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall removeDeadUnits(AIPlayStatus * this, int param_1, RG
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00410104(R)  
    //                               ?removeDeadUnits@AIPlayStatus@@QAEXHPAVRGE_Game_World@@@Z    XREF[1]:     selectNewPlayPhase:00414935(c)  
    //                               AIPlayStatus::removeDeadUnits
    //                              aipbook.cpp:906 (4)
    //         00410100     PUSH       EBX
    //         00410101     PUSH       EBP
    //         00410102     PUSH       ESI
    //         00410103     PUSH       EDI
    //                              aipbook.cpp:907 (13)
    //         00410104     MOV        EDI,dword ptr [ESP + param_2]
    //         00410108     MOV        ESI,this
    //         0041010a     MOV        EBP,0x32
    //         0041010f     MOV        BL,0xff
    //                               LAB_00410111                                                 XREF[1]:     0041013a(j)  
    //                              aipbook.cpp:908 (7)
    //         00410111     MOV        EAX,dword ptr [ESI]
    //         00410113     CMP        EAX,-0x1
    //         00410116     JZ         LAB_00410136
    //                              aipbook.cpp:909 (8)
    //         00410118     PUSH       EAX
    //         00410119     MOV        this,EDI
    //         0041011b     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              aipbook.cpp:911 (10)
    //         00410120     TEST       EAX,EAX
    //         00410122     JZ         LAB_0041012a
    //         00410124     CMP        byte ptr [EAX + 0x48],0x2
    //         00410128     JBE        LAB_00410136
    //                               LAB_0041012a                                                 XREF[1]:     00410122(j)  
    //                              aipbook.cpp:912 (6)
    //         0041012a     MOV        dword ptr [ESI],0xffffffff
    //                              aipbook.cpp:913 (3)
    //         00410130     MOV        byte ptr [ESI + 0x4],BL
    //                              aipbook.cpp:914 (9)
    //         00410133     MOV        byte ptr [ESI + 0x5],BL
    //                               LAB_00410136                                                 XREF[2]:     00410116(j), 00410128(j)  
    //         00410136     ADD        ESI,0x8
    //         00410139     DEC        EBP
    //         0041013a     JNZ        LAB_00410111
    //                              aipbook.cpp:918 (7)
    //         0041013c     POP        EDI
    //         0041013d     POP        ESI
    //         0041013e     POP        EBP
    //         0041013f     POP        EBX
    //         00410140     RET        0x8
}

// Offset: 0x00410150
void resetHitPoints(AIPlayStatus* this_, int param_2, RGE_Game_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIPlayStatus::resetHitPoints(int,class RGE_Game_World *)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall resetHitPoints(AIPlayStatus * this, int param_1, RGE
    //              void              <VOID>         <RETURN>
    //              AIPlayStatus *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0041016d(R), 00410196(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00410155(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00410159(W), 0041019a(R)  
    //                               ?resetHitPoints@AIPlayStatus@@QAEXHPAVRGE_Game_World@@@Z     XREF[1]:     selectNewPlayPhase:00414954(c)  
    //                               AIPlayStatus::resetHitPoints
    //                              aipbook.cpp:923 (5)
    //         00410150     PUSH       this
    //         00410151     PUSH       EBX
    //         00410152     PUSH       EBP
    //         00410153     PUSH       ESI
    //         00410154     PUSH       EDI
    //                              aipbook.cpp:924 (17)
    //         00410155     MOV        EDI,dword ptr [ESP + param_2]
    //         00410159     MOV        dword ptr [ESP + local_4],this
    //         0041015d     XOR        EBP,EBP
    //         0041015f     MOV        ESI,this
    //         00410161     MOV        EBX,0x32
    //                               LAB_00410166                                                 XREF[1]:     00410194(j)  
    //                              aipbook.cpp:927 (20)
    //         00410166     MOV        EAX,dword ptr [ESI]
    //         00410168     CMP        EAX,-0x1
    //         0041016b     JZ         LAB_00410190
    //         0041016d     MOV        EDX,dword ptr [ESP + param_1]
    //         00410171     XOR        this,this
    //         00410173     MOV        this,byte ptr [ESI + 0x4]
    //         00410176     CMP        this,EDX
    //         00410178     JNZ        LAB_00410190
    //                              aipbook.cpp:928 (8)
    //         0041017a     PUSH       EAX
    //         0041017b     MOV        this,EDI
    //         0041017d     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              aipbook.cpp:929 (4)
    //         00410182     TEST       EAX,EAX
    //         00410184     JZ         LAB_00410190
    //                              aipbook.cpp:930 (16)
    //         00410186     FLD        float ptr [EAX + 0x30]
    //         00410189     CALL       __ftol                                           undefined __ftol()
    //         0041018e     ADD        EBP,EAX
    //                               LAB_00410190                                                 XREF[3]:     0041016b(j), 00410178(j), 
    //                                                                                                         00410184(j)  
    //         00410190     ADD        ESI,0x8
    //         00410193     DEC        EBX
    //         00410194     JNZ        LAB_00410166
    //                              aipbook.cpp:933 (15)
    //         00410196     MOV        EDX,dword ptr [ESP + param_1]
    //         0041019a     MOV        this,dword ptr [ESP + local_4]
    //         0041019e     PUSH       EBP
    //         0041019f     PUSH       EDX
    //         004101a0     CALL       AIPlayStatus::setOriginalHitPoints               void setOriginalHitPoints(AIPlayStatus * this
    //                              aipbook.cpp:934 (8)
    //         004101a5     POP        EDI
    //         004101a6     POP        ESI
    //         004101a7     POP        EBP
    //         004101a8     POP        EBX
    //         004101a9     POP        this
    //         004101aa     RET        0x8
}

// Offset: 0x004101B0
undefined AIPlayBook(AIPlayBook* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIPlayBook::AIPlayBook(void)                                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIPlayBook(AIPlayBook * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //                               ??0AIPlayBook@@QAE@XZ                                        XREF[1]:     TribeAIPlayBook:004e68b3(c)  
    //                               AIPlayBook::AIPlayBook
    //                              aipbook.cpp:941 (16)
    //         004101b0     MOV        EAX,this
    //         004101b2     XOR        this,this
    //         004101b4     MOV        dword ptr [EAX + 0x4],this
    //         004101b7     MOV        dword ptr [EAX + 0x4c],this
    //         004101ba     MOV        dword ptr [EAX],AIPlayBook::`vftable'            = 004101d0
    //                              aipbook.cpp:942 (1)
    //         004101c0     RET
}

// Offset: 0x004101F0
void AIPlayBook(AIPlayBook* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall AIPlayBook::~AIPlayBook(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~AIPlayBook(AIPlayBook * this)
    //              void              <VOID>         <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //                               ??1AIPlayBook@@UAE@XZ                                        XREF[2]:     `vector_deleting_destructor':00410
    //                               AIPlayBook::~AIPlayBook                                                   ~AIPlayBook:004e68ee(T), 
    //                                                                                                         ~TribeAIPlayBook:004e68f0(j)  
    //                              aipbook.cpp:947 (3)
    //         004101f0     PUSH       ESI
    //         004101f1     MOV        ESI,this
    //                              aipbook.cpp:948 (13)
    //         004101f3     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004101f6     MOV        dword ptr [ESI],AIPlayBook::`vftable'            = 004101d0
    //         004101fc     TEST       EAX,EAX
    //         004101fe     JZ         LAB_00410217
    //                              aipbook.cpp:950 (16)
    //         00410200     PUSH       EAX
    //         00410201     MOV        dword ptr [ESI + 0x4],0x0
    //         00410208     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0041020d     ADD        ESP,0x4
    //                              aipbook.cpp:951 (7)
    //         00410210     MOV        dword ptr [ESI + 0x4c],0x0
    //                               LAB_00410217                                                 XREF[1]:     004101fe(j)  
    //                              aipbook.cpp:953 (2)
    //         00410217     POP        ESI
    //         00410218     RET
}

// Offset: 0x00410220
int loadPlays(AIPlayBook* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayBook::loadPlays(char *)                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall loadPlays(AIPlayBook * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0041023d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004103c3(W), 004103ec(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041131a(R)  
    //              char[256]         Stack[-0x110   temp6                     XREF[0,13]:  00410469(*), 00410a53(*), 00410a72(*), 00410ae0(*), 
    //                                                                                     00410aff(*), 00410bff(*), 00410c39(*), 00410d87(*), 
    //                                                                                     00410dec(*), 00410e6b(*), 00410eba(*), 00410f3d(*), 
    //                                                                                     00410f8f(*)  
    //              AIPlayPhaseTri    Stack[-0x124   trigger@fffffedc          XREF[0,2]:   00410f98(*), 00410fa4(*)  
    //              AIPlayPhaseTri    Stack[-0x138   trigger                   XREF[0,2]:   00410ec3(*), 00410ecf(*)  
    //              char[256]         Stack[-0x238   temp                      XREF[0,31]:  0041029b(*), 004102b1(*), 004102ea(*), 0041030a(*), 
    //                                                                                     00410321(*), 00410376(*), 0041041c(*), 0041043a(*), 
    //                                                                                     004104be(*), 004104f2(*), 00410546(R), 00410624(*), 
    //                                                                                     004106a0(*), 00410714(*), 00410788(*), 00410804(*), 
    //                                                                                     00410905(*), 004109ae(*), 00410a5a(*), 00410ae7(*)  
    //              AIPlayPhaseCom    Stack[-0x248   newCommand                XREF[0,2]:   00411252(*), 0041125e(*)  
    //              AIPlayPhaseCom    Stack[-0x258   command                   XREF[0,2]:   00410df6(*), 00410e02(*)  
    //              char[256]         Stack[-0x358   temp2                     XREF[0,74]:  0041031d(*), 00410337(*), 00410342(*), 0041045f(*), 
    //                                                                                     004104ee(*), 0041050d(*), 00410511(*), 0041059b(*), 
    //                                                                                     004105cf(*), 004105e6(*), 004105ea(*), 00410620(*), 
    //                                                                                     00410646(*), 00410662(*), 00410666(*), 004106d6(*), 
    //                                                                                     004106da(*), 0041074a(*), 0041074e(*), 004107be(*)  
    //              XYZ               Stack[-0x364   origin                    XREF[0,2]:   004111fd(*), 0041122d(*)  
    //              XYZ               Stack[-0x370   originalPoint             XREF[1,2]:   0041123c(R), 0041121b(*), 00411233(*)  
    //              XYZ               Stack[-0x37c   rotatedPoint              XREF[4,4]:   004102cc(W), 00410400(R), 00410418(R), 004112d1(R), 
    //                                                                                     00411206(*), 00411228(*), 00411244(R), 00411240(R)  
    //              _iobuf *          Stack[-0x380   fileIn                    XREF[5]:     004104b4(W), 00410d79(*), 00410de2(R), 00410f2f(*), 
    //                                                                                     00410f79(R)  
    //              int               Stack[-0x384   temp7                     XREF[5]:     004104b8(W), 00410e62(*), 00410eab(R), 00410f33(*), 
    //                                                                                     00410f7d(R)  
    //              int               Stack[-0x388   temp8                     XREF[5]:     00411058(W), 00411069(R), 00411224(R), 004112af(R), 
    //                                                                                     004112b7(W)  
    //              int               Stack[-0x38c   i                         XREF[4]:     004104b0(W), 00410bf6(*), 00410d7d(*), 00410dd8(R)  
    //              int               Stack[-0x390   temp5                     XREF[6]:     004103bb(W), 00411026(W), 0041102e(R), 004111c1(W), 
    //                                                                                     004111e2(R), 00411283(R)  
    //              AIPlayPhase *     Stack[-0x394   refPhase                  XREF[5]:     00410410(W), 004105b9(W), 00410fff(R), 00411062(W), 
    //                                                                                     004112c1(R)  
    //              int               Stack[-0x398   currentPlay               XREF[7]:     0041115a(W), 0041116a(R), 00411184(R), 004111d6(W), 
    //                                                                                     004111de(R), 0041126f(R), 00411277(W)  
    //              int               Stack[-0x39c   a                         XREF[6]:     00411149(W), 00411160(R), 0041117a(R), 004111d2(W), 
    //                                                                                     00411266(R), 0041128d(R)  
    //              AIPlayPhase *     Stack[-0x3a0   curPhase                  XREF[8]:     00411128(W), 00411138(R), 0041119a(R), 004111a2(W), 
    //                                                                                     004111a8(W), 004111b0(R), 0041129d(R), 004112a5(W)  
    //              int               Stack[-0x3a4   j                         XREF[0,2]:   00410492(*), 004104dc(R)  
    //              char              Stack[-0x3a5   commentTemp1
    //              int               Stack[-0x3ac   currentPhase              XREF[0,2]:   004104a8(*), 004104e3(R)  
    //              char              Stack[-0x3ad   commentTemp2
    //              int               Stack[-0x3b4   temp4                     XREF[25]:    004104a2(W), 00410575(W), 0041069c(*), 004106c5(R), 
    //                                                                                     00410710(*), 00410739(R), 00410784(*), 004107ad(R), 
    //                                                                                     00410901(*), 00410918(R), 004109aa(*), 004109c1(R), 
    //                                                                                     00410b6d(*), 00410b8b(R), 00410c07(*), 00410c1f(R), 
    //                                                                                     00410d06(*), 00410d1d(R), 00410d8f(*), 00410da7(R)  
    //              int               Stack[-0x3b8   temp3
    //                               ?loadPlays@AIPlayBook@@QAEHPAD@Z                             XREF[1]:     TRIBE_World:0052dfff(c)  
    //                               AIPlayBook::loadPlays
    //                              aipbook.cpp:958 (29)
    //         00410220     MOV        EAX,FS:[0x0]
    //         00410226     PUSH       -0x1
    //         00410228     PUSH       FUN_0055c73e
    //         0041022d     PUSH       EAX
    //         0041022e     MOV        dword ptr FS:[0x0],ESP
    //         00410235     SUB        ESP,0x3a8
    //         0041023b     PUSH       EBX
    //         0041023c     PUSH       EBP
    //                              aipbook.cpp:959 (79)
    //         0041023d     MOV        EBP,dword ptr [ESP + param_1]
    //         00410244     PUSH       ESI
    //         00410245     TEST       EBP,EBP
    //         00410247     PUSH       EDI
    //         00410248     MOV        EBX,this
    //         0041024a     JZ         LAB_004112e9
    //         00410250     MOV        EDI,s_NONE                                       = 4Eh
    //         00410255     MOV        ESI,EBP
    //                               LAB_00410257                                                 XREF[1]:     00410279(j)  
    //         00410257     MOV        this,byte ptr [ESI]
    //         00410259     MOV        DL,byte ptr [EDI]=>s_NONE                        = 4Eh
    //         0041025b     MOV        AL,this
    //         0041025d     CMP        this,DL
    //         0041025f     JNZ        LAB_0041027f
    //         00410261     TEST       AL,AL
    //         00410263     JZ         LAB_0041027b
    //         00410265     MOV        DL,byte ptr [ESI + 0x1]
    //         00410268     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f351          = 4Fh
    //                                                                                  = 45h
    //         0041026b     MOV        AL,DL
    //         0041026d     CMP        DL,this
    //         0041026f     JNZ        LAB_0041027f
    //         00410271     ADD        ESI,0x2
    //         00410274     ADD        EDI,0x2
    //         00410277     TEST       AL,AL
    //         00410279     JNZ        LAB_00410257
    //                               LAB_0041027b                                                 XREF[1]:     00410263(j)  
    //         0041027b     XOR        EAX,EAX
    //         0041027d     JMP        LAB_00410284
    //                               LAB_0041027f                                                 XREF[2]:     0041025f(j), 0041026f(j)  
    //         0041027f     SBB        EAX,EAX
    //         00410281     SBB        EAX,-0x1
    //                               LAB_00410284                                                 XREF[1]:     0041027d(j)  
    //         00410284     TEST       EAX,EAX
    //         00410286     JZ         LAB_004112e5
    //                              aipbook.cpp:966 (15)
    //         0041028c     LEA        ESI,[EBX + 0x8]
    //         0041028f     PUSH       0x40
    //         00410291     PUSH       EBP
    //         00410292     PUSH       ESI
    //         00410293     CALL       strncpy                                          undefined strncpy()
    //         00410298     ADD        ESP,0xc
    //                              aipbook.cpp:972 (22)
    //         0041029b     LEA        EAX=>temp[4],[ESP + 0x190]
    //         004102a2     PUSH       ESI
    //         004102a3     PUSH       s_%s                                             = "%s"
    //         004102a8     PUSH       EAX
    //         004102a9     CALL       sprintf                                          undefined sprintf()
    //         004102ae     ADD        ESP,0xc
    //                              aipbook.cpp:973 (20)
    //         004102b1     LEA        this=>temp[4],[ESP + 0x190]
    //         004102b8     PUSH       s_r                                              = "r"
    //         004102bd     PUSH       this
    //         004102be     CALL       fopen                                            undefined fopen()
    //         004102c3     MOV        EBP,EAX
    //                              aipbook.cpp:974 (11)
    //         004102c5     XOR        ESI,ESI
    //         004102c7     ADD        ESP,0x8
    //         004102ca     CMP        EBP,ESI
    //         004102cc     MOV        dword ptr [ESP + rotatedPoint.xValue],EBP
    //                              aipbook.cpp:975 (6)
    //         004102d0     JZ         LAB_00411318
    //                              aipbook.cpp:978 (7)
    //         004102d6     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004102d9     CMP        EAX,ESI
    //         004102db     JZ         LAB_004102e9
    //                              aipbook.cpp:979 (9)
    //         004102dd     PUSH       EAX
    //         004102de     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004102e3     ADD        ESP,0x4
    //                              aipbook.cpp:980 (3)
    //         004102e6     MOV        dword ptr [EBX + 0x4c],ESI
    //                               LAB_004102e9                                                 XREF[1]:     004102db(j)  
    //                              aipbook.cpp:986 (33)
    //         004102e9     PUSH       EBP
    //         004102ea     LEA        EDX=>temp[4],[ESP + 0x194]
    //         004102f1     PUSH       0x100
    //         004102f6     PUSH       EDX
    //         004102f7     MOV        dword ptr [EBX + 0x4],ESI
    //         004102fa     CALL       fgets                                            undefined fgets()
    //         004102ff     ADD        ESP,0xc
    //         00410302     TEST       EAX,EAX
    //         00410304     JZ         LAB_00410393
    //                               LAB_0041030a                                                 XREF[1]:     0041038d(j)  
    //                              aipbook.cpp:988 (19)
    //         0041030a     LEA        EDI=>temp[4],[ESP + 0x190]
    //         00410311     OR         this,0xffffffff
    //         00410314     XOR        EAX,EAX
    //         00410316     SCASB.RE   ES:EDI
    //         00410318     NOT        this
    //         0041031a     DEC        this
    //         0041031b     JZ         LAB_00410375
    //                              aipbook.cpp:990 (26)
    //         0041031d     LEA        EAX=>temp2[4],[ESP + 0x70]
    //         00410321     LEA        this=>temp[4],[ESP + 0x190]
    //         00410328     PUSH       EAX
    //         00410329     PUSH       s_%s_                                            = "%s "
    //         0041032e     PUSH       this
    //         0041032f     CALL       sscanf                                           undefined sscanf()
    //         00410334     ADD        ESP,0xc
    //                              aipbook.cpp:991 (58)
    //         00410337     LEA        EDI=>temp2[4],[ESP + 0x70]
    //         0041033b     MOV        ESI,s_Play                                       = 50h
    //                               LAB_00410340                                                 XREF[1]:     00410362(j)  
    //         00410340     MOV        DL,byte ptr [ESI]=>s_Play                        = 50h
    //                                                                                  = 61h
    //         00410342     MOV        this,byte ptr [EDI]=>temp2[4]
    //         00410344     MOV        AL,DL
    //         00410346     CMP        DL,this
    //         00410348     JNZ        LAB_00410368
    //         0041034a     TEST       AL,AL
    //         0041034c     JZ         LAB_00410364
    //         0041034e     MOV        this,byte ptr [ESI + 0x1]=>DAT_0057f711          = 6Ch
    //                                                                                  = 79h
    //         00410351     MOV        DL,byte ptr [EDI + temp2[5]]
    //         00410354     MOV        AL,this
    //         00410356     CMP        this,DL
    //         00410358     JNZ        LAB_00410368
    //         0041035a     ADD        ESI,0x2
    //         0041035d     ADD        EDI,0x2
    //         00410360     TEST       AL,AL
    //         00410362     JNZ        LAB_00410340
    //                               LAB_00410364                                                 XREF[1]:     0041034c(j)  
    //         00410364     XOR        EAX,EAX
    //         00410366     JMP        LAB_0041036d
    //                               LAB_00410368                                                 XREF[2]:     00410348(j), 00410358(j)  
    //         00410368     SBB        EAX,EAX
    //         0041036a     SBB        EAX,-0x1
    //                               LAB_0041036d                                                 XREF[1]:     00410366(j)  
    //         0041036d     TEST       EAX,EAX
    //         0041036f     JNZ        LAB_00410375
    //                              aipbook.cpp:992 (34)
    //         00410371     ADD        dword ptr [EBX + 0x4],0x8
    //                               LAB_00410375                                                 XREF[2]:     0041031b(j), 0041036f(j)  
    //         00410375     PUSH       EBP
    //         00410376     LEA        EDX=>temp[4],[ESP + 0x194]
    //         0041037d     PUSH       0x100
    //         00410382     PUSH       EDX
    //         00410383     CALL       fgets                                            undefined fgets()
    //         00410388     ADD        ESP,0xc
    //         0041038b     TEST       EAX,EAX
    //         0041038d     JNZ        LAB_0041030a
    //                               LAB_00410393                                                 XREF[1]:     00410304(j)  
    //                              aipbook.cpp:995 (12)
    //         00410393     MOV        this,dword ptr [EBX + 0x4]
    //         00410396     MOV        EAX,0x3e80
    //         0041039b     CMP        this,EAX
    //         0041039d     JLE        LAB_004103a2
    //                              aipbook.cpp:996 (3)
    //         0041039f     MOV        dword ptr [EBX + 0x4],EAX
    //                               LAB_004103a2                                                 XREF[1]:     0041039d(j)  
    //                              aipbook.cpp:997 (51)
    //         004103a2     MOV        EDI,dword ptr [EBX + 0x4]
    //         004103a5     LEA        EAX,[EDI + EDI*0x2]
    //         004103a8     SHL        EAX,0x6
    //         004103ab     ADD        EAX,EDI
    //         004103ad     SHL        EAX,0x3
    //         004103b0     PUSH       EAX
    //         004103b1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004103b6     MOV        EBP,EAX
    //         004103b8     ADD        ESP,0x4
    //         004103bb     MOV        dword ptr [ESP + temp5],EBP
    //         004103bf     XOR        EAX,EAX
    //         004103c1     CMP        EBP,EAX
    //         004103c3     MOV        dword ptr [ESP + local_4],EAX
    //         004103ca     JZ         LAB_004103ea
    //         004103cc     LEA        EAX,[EDI + -0x1]
    //         004103cf     MOV        ESI,EBP
    //         004103d1     TEST       EAX,EAX
    //         004103d3     JL         LAB_004103e8
    //                              aipbook.cpp:1290 (3)
    //         004103d5     LEA        EDI,[EAX + 0x1]
    //                               LAB_004103d8                                                 XREF[1]:     004103e6(j)  
    //                              aipbook.cpp:997 (18)
    //         004103d8     MOV        this,ESI
    //         004103da     CALL       AIPlay::AIPlay                                   undefined AIPlay(AIPlay * this)
    //         004103df     ADD        ESI,0x608
    //         004103e5     DEC        EDI
    //         004103e6     JNZ        LAB_004103d8
    //                               LAB_004103e8                                                 XREF[1]:     004103d3(j)  
    //         004103e8     MOV        EAX,EBP
    //                               LAB_004103ea                                                 XREF[1]:     004103ca(j)  
    //                              aipbook.cpp:998 (16)
    //         004103ea     TEST       EAX,EAX
    //         004103ec     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004103f7     MOV        dword ptr [EBX + 0x4c],EAX
    //                              aipbook.cpp:999 (6)
    //         004103fa     JZ         LAB_00411318
    //                              aipbook.cpp:1001 (13)
    //         00410400     MOV        this,dword ptr [ESP + rotatedPoint.xValue]
    //         00410404     PUSH       this
    //         00410405     CALL       rewind                                           undefined rewind()
    //         0041040a     ADD        ESP,0x4
    //                              aipbook.cpp:1003 (7)
    //         0041040d     OR         EBP,0xffffffff
    //         00410410     MOV        dword ptr [ESP + refPhase],EBP
    //                              aipbook.cpp:1004 (4)
    //         00410414     MOV        dword ptr [ESP + Stack[-0x3a8]],EBP
    //                               LAB_00410418                                                 XREF[1]:     004112cb(j)  
    //                              aipbook.cpp:1010 (34)
    //         00410418     MOV        EDX,dword ptr [ESP + rotatedPoint.xValue]
    //         0041041c     LEA        EAX=>temp[4],[ESP + 0x190]
    //         00410423     PUSH       EDX
    //         00410424     PUSH       0x100
    //         00410429     PUSH       EAX
    //         0041042a     CALL       fgets                                            undefined fgets()
    //         0041042f     ADD        ESP,0xc
    //         00410432     TEST       EAX,EAX
    //         00410434     JZ         LAB_004112d1
    //                              aipbook.cpp:1012 (23)
    //         0041043a     LEA        EDI=>temp[4],[ESP + 0x190]
    //         00410441     OR         this,0xffffffff
    //         00410444     XOR        EAX,EAX
    //         00410446     SCASB.RE   ES:EDI
    //         00410448     NOT        this
    //         0041044a     DEC        this
    //         0041044b     JZ         LAB_004112c5
    //                              aipbook.cpp:1015 (24)
    //         00410451     MOV        EDI,s_                                           = ""
    //         00410456     OR         this,0xffffffff
    //         00410459     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0041045b     NOT        this
    //         0041045d     SUB        EDI,this
    //         0041045f     LEA        EDX=>temp2[4],[ESP + 0x70]
    //         00410463     MOV        EAX,this
    //         00410465     MOV        ESI,EDI
    //         00410467     MOV        EDI,EDX
    //                              aipbook.cpp:1016 (41)
    //         00410469     LEA        EDX=>temp6[4],[ESP + 0x2b8]
    //         00410470     SHR        this,0x2
    //         00410473     MOVSD.REP  ES:EDI,ESI
    //         00410475     MOV        this,EAX
    //         00410477     XOR        EAX,EAX
    //         00410479     AND        this,0x3
    //         0041047c     MOVSB.REP  ES:EDI,ESI
    //         0041047e     MOV        EDI,s_                                           = ""
    //         00410483     OR         this,0xffffffff
    //         00410486     SCASB.RE   ES:EDI=>s_                                       = ""
    //         00410488     NOT        this
    //         0041048a     SUB        EDI,this
    //         0041048c     MOV        EAX,this
    //         0041048e     MOV        ESI,EDI
    //         00410490     MOV        EDI,EDX
    //                              aipbook.cpp:1026 (74)
    //         00410492     LEA        EDX=>j+0x3,[ESP + 0x23]
    //         00410496     SHR        this,0x2
    //         00410499     MOVSD.REP  ES:EDI,ESI
    //         0041049b     MOV        this,EAX
    //         0041049d     XOR        EAX,EAX
    //         0041049f     AND        this,0x3
    //         004104a2     MOV        dword ptr [ESP + temp4],EAX
    //         004104a6     MOVSB.REP  ES:EDI,ESI
    //         004104a8     LEA        this=>currentPhase+0x3,[ESP + 0x1b]
    //         004104ac     MOV        dword ptr [ESP + Stack[-0x3b0]],EAX
    //         004104b0     MOV        dword ptr [ESP + i],EAX
    //         004104b4     MOV        dword ptr [ESP + fileIn],EAX
    //         004104b8     MOV        dword ptr [ESP + temp7],EAX
    //         004104bc     PUSH       this
    //         004104bd     PUSH       EDX
    //         004104be     LEA        EAX=>temp[4],[ESP + 0x198]
    //         004104c5     PUSH       s__%c%c                                          = " %c%c"
    //         004104ca     PUSH       EAX
    //         004104cb     CALL       sscanf                                           undefined sscanf()
    //         004104d0     ADD        ESP,0x10
    //         004104d3     CMP        EAX,-0x1
    //         004104d6     JZ         LAB_004112c5
    //                              aipbook.cpp:1028 (18)
    //         004104dc     CMP        byte ptr [ESP + j+0x3],0x2f
    //         004104e1     JNZ        LAB_004104ee
    //         004104e3     CMP        byte ptr [ESP + currentPhase+0x3],0x2f
    //         004104e8     JZ         LAB_004112c5
    //                               LAB_004104ee                                                 XREF[1]:     004104e1(j)  
    //                              aipbook.cpp:1032 (26)
    //         004104ee     LEA        this=>temp2[4],[ESP + 0x70]
    //         004104f2     LEA        EDX=>temp[4],[ESP + 0x190]
    //         004104f9     PUSH       this
    //         004104fa     PUSH       s_%s_                                            = "%s "
    //         004104ff     PUSH       EDX
    //         00410500     CALL       sscanf                                           undefined sscanf()
    //         00410505     ADD        ESP,0xc
    //                              aipbook.cpp:1036 (62)
    //         00410508     MOV        EDI,s_Play                                       = 50h
    //         0041050d     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410511                                                 XREF[1]:     00410533(j)  
    //         00410511     MOV        this,byte ptr [ESI]=>temp2[4]
    //         00410513     MOV        DL,byte ptr [EDI]=>s_Play                        = 50h
    //                                                                                  = 61h
    //         00410515     MOV        AL,this
    //         00410517     CMP        this,DL
    //         00410519     JNZ        LAB_00410539
    //         0041051b     TEST       AL,AL
    //         0041051d     JZ         LAB_00410535
    //         0041051f     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410522     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f711          = 6Ch
    //                                                                                  = 79h
    //         00410525     MOV        AL,DL
    //         00410527     CMP        DL,this
    //         00410529     JNZ        LAB_00410539
    //         0041052b     ADD        ESI,0x2
    //         0041052e     ADD        EDI,0x2
    //         00410531     TEST       AL,AL
    //         00410533     JNZ        LAB_00410511
    //                               LAB_00410535                                                 XREF[1]:     0041051d(j)  
    //         00410535     XOR        EAX,EAX
    //         00410537     JMP        LAB_0041053e
    //                               LAB_00410539                                                 XREF[2]:     00410519(j), 00410529(j)  
    //         00410539     SBB        EAX,EAX
    //         0041053b     SBB        EAX,-0x1
    //                               LAB_0041053e                                                 XREF[1]:     00410537(j)  
    //         0041053e     TEST       EAX,EAX
    //         00410540     JNZ        LAB_004105e1
    //                              aipbook.cpp:1039 (28)
    //         00410546     MOV        AL,byte ptr [ESP + temp[4]]
    //         0041054d     XOR        this,this
    //         0041054f     XOR        EDX,EDX
    //         00410551     CMP        AL,0x22
    //         00410553     JZ         LAB_00410562
    //                               LAB_00410555                                                 XREF[1]:     00410560(j)  
    //         00410555     MOV        AL,byte ptr [ESP + EDX*0x1 + temp[6]]
    //         0041055c     INC        EDX
    //         0041055d     INC        this
    //         0041055e     CMP        AL,0x22
    //         00410560     JNZ        LAB_00410555
    //                               LAB_00410562                                                 XREF[1]:     00410553(j)  
    //                              aipbook.cpp:1040 (1)
    //         00410562     INC        EDX
    //                              aipbook.cpp:1041 (1)
    //         00410563     INC        this
    //                              aipbook.cpp:1042 (38)
    //         00410564     CMP        byte ptr [ESP + EDX*0x1 + temp[5]],0x22
    //         0041056c     MOV        EAX,this
    //         0041056e     LEA        EDX=>temp[6],[ESP + EDX*0x1 + 0x190]
    //         00410575     MOV        dword ptr [ESP + temp4],this
    //         00410579     MOV        dword ptr [ESP + Stack[-0x3b0]],EAX
    //         0041057d     JZ         LAB_0041058a
    //                               LAB_0041057f                                                 XREF[1]:     00410584(j)  
    //         0041057f     INC        EDX
    //         00410580     INC        EAX
    //         00410581     CMP        byte ptr [EDX]=>temp[7],0x22
    //         00410584     JNZ        LAB_0041057f
    //         00410586     MOV        dword ptr [ESP + Stack[-0x3b0]],EAX
    //                               LAB_0041058a                                                 XREF[1]:     0041057d(j)  
    //                              aipbook.cpp:1043 (2)
    //         0041058a     XOR        EDX,EDX
    //                              aipbook.cpp:1044 (33)
    //         0041058c     CMP        this,EAX
    //         0041058e     JGE        LAB_004105ad
    //         00410590     SUB        EAX,this
    //         00410592     LEA        ESI=>temp[6],[ESP + this->_padding_*0x1 + 0x190]
    //         00410599     MOV        this,EAX
    //         0041059b     LEA        EDI=>temp2[4],[ESP + 0x70]
    //         0041059f     MOV        EDX,this
    //         004105a1     SHR        this,0x2
    //         004105a4     MOVSD.REP  ES:EDI,ESI
    //         004105a6     MOV        this,EDX
    //         004105a8     AND        this,0x3
    //         004105ab     MOVSB.REP  ES:EDI,ESI
    //                               LAB_004105ad                                                 XREF[1]:     0041058e(j)  
    //                              aipbook.cpp:1047 (6)
    //         004105ad     INC        EBP
    //         004105ae     MOV        byte ptr [ESP + EDX*0x1 + temp2[5]],0x0
    //                              aipbook.cpp:1048 (16)
    //         004105b3     CMP        EBP,0x3e80
    //         004105b9     MOV        dword ptr [ESP + refPhase],EBP
    //         004105bd     JGE        LAB_004112d1
    //                              aipbook.cpp:1050 (25)
    //         004105c3     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004105c6     LEA        this,[EBP + EBP*0x2]
    //         004105ca     SHL        this,0x6
    //         004105cd     ADD        this,EBP
    //         004105cf     LEA        EAX=>temp2[4],[ESP + 0x70]
    //         004105d3     PUSH       EAX
    //         004105d4     LEA        this,[EDX + this->_padding_*0x8]
    //         004105d7     CALL       AIPlay::setName                                  void setName(AIPlay * this, char * param_1)
    //                              aipbook.cpp:1051 (5)
    //         004105dc     JMP        LAB_004112c5
    //                               LAB_004105e1                                                 XREF[1]:     00410540(j)  
    //                              aipbook.cpp:1055 (63)
    //         004105e1     MOV        EDI,s_PlayType                                   = 50h
    //         004105e6     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_004105ea                                                 XREF[1]:     0041060c(j)  
    //         004105ea     MOV        this,byte ptr [ESI]=>temp2[4]
    //         004105ec     MOV        DL,byte ptr [EDI]=>s_PlayType                    = 50h
    //                                                                                  = 61h
    //         004105ee     MOV        AL,this
    //         004105f0     CMP        this,DL
    //         004105f2     JNZ        LAB_00410612
    //         004105f4     TEST       AL,AL
    //         004105f6     JZ         LAB_0041060e
    //         004105f8     MOV        DL,byte ptr [ESI + temp2[5]]
    //         004105fb     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f705          = 6Ch
    //                                                                                  = "yType"
    //         004105fe     MOV        AL,DL
    //         00410600     CMP        DL,this
    //         00410602     JNZ        LAB_00410612
    //         00410604     ADD        ESI,0x2
    //         00410607     ADD        EDI,0x2
    //         0041060a     TEST       AL,AL
    //         0041060c     JNZ        LAB_004105ea
    //                               LAB_0041060e                                                 XREF[1]:     004105f6(j)  
    //         0041060e     XOR        EAX,EAX
    //         00410610     JMP        LAB_00410617
    //                               LAB_00410612                                                 XREF[2]:     004105f2(j), 00410602(j)  
    //         00410612     SBB        EAX,EAX
    //         00410614     SBB        EAX,-0x1
    //                               LAB_00410617                                                 XREF[1]:     00410610(j)  
    //         00410617     TEST       EAX,EAX
    //         00410619     JNZ        LAB_0041065d
    //         0041061b     CMP        EBP,-0x1
    //         0041061e     JZ         LAB_0041065d
    //                              aipbook.cpp:1056 (23)
    //         00410620     LEA        EAX=>temp2[4],[ESP + 0x70]
    //         00410624     LEA        this=>temp[4],[ESP + 0x190]
    //         0041062b     PUSH       EAX
    //         0041062c     PUSH       s_%*s_%s_                                        = "%*s %s "
    //         00410631     PUSH       this
    //         00410632     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1057 (33)
    //         00410637     MOV        EAX,dword ptr [EBX + 0x4c]
    //         0041063a     LEA        EDX,[EBP + EBP*0x2]
    //         0041063e     SHL        EDX,0x6
    //         00410641     ADD        EDX,EBP
    //         00410643     ADD        ESP,0xc
    //         00410646     LEA        this=>temp2[4],[ESP + 0x70]
    //         0041064a     LEA        ESI,[EAX + EDX*0x8]
    //         0041064d     PUSH       this
    //         0041064e     MOV        this,ESI
    //         00410650     CALL       AIPlay::convertToIntType                         uchar convertToIntType(AIPlay * this, char * 
    //         00410655     MOV        byte ptr [ESI + 0x43],AL
    //                              aipbook.cpp:1058 (5)
    //         00410658     JMP        LAB_004112c5
    //                               LAB_0041065d                                                 XREF[2]:     00410619(j), 0041061e(j)  
    //                              aipbook.cpp:1062 (63)
    //         0041065d     MOV        EDI,s_MinUnits                                   = 4Dh
    //         00410662     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410666                                                 XREF[1]:     00410688(j)  
    //         00410666     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410668     MOV        this,byte ptr [EDI]=>s_MinUnits                  = 4Dh
    //                                                                                  = 6Eh
    //         0041066a     MOV        AL,DL
    //         0041066c     CMP        DL,this
    //         0041066e     JNZ        LAB_0041068e
    //         00410670     TEST       AL,AL
    //         00410672     JZ         LAB_0041068a
    //         00410674     MOV        this,byte ptr [ESI + temp2[5]]
    //         00410677     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f6f1            = 69h
    //                                                                                  = "Units"
    //         0041067a     MOV        AL,this
    //         0041067c     CMP        this,DL
    //         0041067e     JNZ        LAB_0041068e
    //         00410680     ADD        ESI,0x2
    //         00410683     ADD        EDI,0x2
    //         00410686     TEST       AL,AL
    //         00410688     JNZ        LAB_00410666
    //                               LAB_0041068a                                                 XREF[1]:     00410672(j)  
    //         0041068a     XOR        EAX,EAX
    //         0041068c     JMP        LAB_00410693
    //                               LAB_0041068e                                                 XREF[2]:     0041066e(j), 0041067e(j)  
    //         0041068e     SBB        EAX,EAX
    //         00410690     SBB        EAX,-0x1
    //                               LAB_00410693                                                 XREF[1]:     0041068c(j)  
    //         00410693     TEST       EAX,EAX
    //         00410695     JNZ        LAB_004106d1
    //         00410697     CMP        EBP,-0x1
    //         0041069a     JZ         LAB_004106d1
    //                              aipbook.cpp:1063 (23)
    //         0041069c     LEA        EDX=>temp4,[ESP + 0x10]
    //         004106a0     LEA        EAX=>temp[4],[ESP + 0x190]
    //         004106a7     PUSH       EDX
    //         004106a8     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         004106ad     PUSH       EAX
    //         004106ae     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1064 (25)
    //         004106b3     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004106b6     LEA        this,[EBP + EBP*0x2]
    //         004106ba     SHL        this,0x6
    //         004106bd     ADD        ESP,0xc
    //         004106c0     ADD        this,EBP
    //         004106c2     LEA        EAX,[EDX + this->_padding_*0x8]
    //         004106c5     MOV        this,byte ptr [ESP + temp4]
    //         004106c9     MOV        byte ptr [EAX + 0x41],this
    //                              aipbook.cpp:1065 (5)
    //         004106cc     JMP        LAB_004112c5
    //                               LAB_004106d1                                                 XREF[2]:     00410695(j), 0041069a(j)  
    //                              aipbook.cpp:1069 (63)
    //         004106d1     MOV        EDI,s_MaxUnits                                   = 4Dh
    //         004106d6     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_004106da                                                 XREF[1]:     004106fc(j)  
    //         004106da     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         004106dc     MOV        this,byte ptr [EDI]=>s_MaxUnits                  = 4Dh
    //                                                                                  = 78h
    //         004106de     MOV        AL,DL
    //         004106e0     CMP        DL,this
    //         004106e2     JNZ        LAB_00410702
    //         004106e4     TEST       AL,AL
    //         004106e6     JZ         LAB_004106fe
    //         004106e8     MOV        this,byte ptr [ESI + temp2[5]]
    //         004106eb     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f6dd            = 61h
    //                                                                                  = "Units"
    //         004106ee     MOV        AL,this
    //         004106f0     CMP        this,DL
    //         004106f2     JNZ        LAB_00410702
    //         004106f4     ADD        ESI,0x2
    //         004106f7     ADD        EDI,0x2
    //         004106fa     TEST       AL,AL
    //         004106fc     JNZ        LAB_004106da
    //                               LAB_004106fe                                                 XREF[1]:     004106e6(j)  
    //         004106fe     XOR        EAX,EAX
    //         00410700     JMP        LAB_00410707
    //                               LAB_00410702                                                 XREF[2]:     004106e2(j), 004106f2(j)  
    //         00410702     SBB        EAX,EAX
    //         00410704     SBB        EAX,-0x1
    //                               LAB_00410707                                                 XREF[1]:     00410700(j)  
    //         00410707     TEST       EAX,EAX
    //         00410709     JNZ        LAB_00410745
    //         0041070b     CMP        EBP,-0x1
    //         0041070e     JZ         LAB_00410745
    //                              aipbook.cpp:1070 (23)
    //         00410710     LEA        EDX=>temp4,[ESP + 0x10]
    //         00410714     LEA        EAX=>temp[4],[ESP + 0x190]
    //         0041071b     PUSH       EDX
    //         0041071c     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         00410721     PUSH       EAX
    //         00410722     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1071 (25)
    //         00410727     MOV        EDX,dword ptr [EBX + 0x4c]
    //         0041072a     LEA        this,[EBP + EBP*0x2]
    //         0041072e     SHL        this,0x6
    //         00410731     ADD        ESP,0xc
    //         00410734     ADD        this,EBP
    //         00410736     LEA        EAX,[EDX + this->_padding_*0x8]
    //         00410739     MOV        this,byte ptr [ESP + temp4]
    //         0041073d     MOV        byte ptr [EAX + 0x42],this
    //                              aipbook.cpp:1072 (5)
    //         00410740     JMP        LAB_004112c5
    //                               LAB_00410745                                                 XREF[2]:     00410709(j), 0041070e(j)  
    //                              aipbook.cpp:1076 (63)
    //         00410745     MOV        EDI,s_Power                                      = 50h
    //         0041074a     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_0041074e                                                 XREF[1]:     00410770(j)  
    //         0041074e     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410750     MOV        this,byte ptr [EDI]=>s_Power                     = 50h
    //                                                                                  = 77h
    //         00410752     MOV        AL,DL
    //         00410754     CMP        DL,this
    //         00410756     JNZ        LAB_00410776
    //         00410758     TEST       AL,AL
    //         0041075a     JZ         LAB_00410772
    //         0041075c     MOV        this,byte ptr [ESI + temp2[5]]
    //         0041075f     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f6d5            = 6Fh
    //                                                                                  = 65h
    //         00410762     MOV        AL,this
    //         00410764     CMP        this,DL
    //         00410766     JNZ        LAB_00410776
    //         00410768     ADD        ESI,0x2
    //         0041076b     ADD        EDI,0x2
    //         0041076e     TEST       AL,AL
    //         00410770     JNZ        LAB_0041074e
    //                               LAB_00410772                                                 XREF[1]:     0041075a(j)  
    //         00410772     XOR        EAX,EAX
    //         00410774     JMP        LAB_0041077b
    //                               LAB_00410776                                                 XREF[2]:     00410756(j), 00410766(j)  
    //         00410776     SBB        EAX,EAX
    //         00410778     SBB        EAX,-0x1
    //                               LAB_0041077b                                                 XREF[1]:     00410774(j)  
    //         0041077b     TEST       EAX,EAX
    //         0041077d     JNZ        LAB_004107b9
    //         0041077f     CMP        EBP,-0x1
    //         00410782     JZ         LAB_004107b9
    //                              aipbook.cpp:1077 (23)
    //         00410784     LEA        EDX=>temp4,[ESP + 0x10]
    //         00410788     LEA        EAX=>temp[4],[ESP + 0x190]
    //         0041078f     PUSH       EDX
    //         00410790     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         00410795     PUSH       EAX
    //         00410796     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1078 (25)
    //         0041079b     MOV        EDX,dword ptr [EBX + 0x4c]
    //         0041079e     LEA        this,[EBP + EBP*0x2]
    //         004107a2     SHL        this,0x6
    //         004107a5     ADD        ESP,0xc
    //         004107a8     ADD        this,EBP
    //         004107aa     LEA        EAX,[EDX + this->_padding_*0x8]
    //         004107ad     MOV        this,byte ptr [ESP + temp4]
    //         004107b1     MOV        byte ptr [EAX + 0x4e],this
    //                              aipbook.cpp:1079 (5)
    //         004107b4     JMP        LAB_004112c5
    //                               LAB_004107b9                                                 XREF[2]:     0041077d(j), 00410782(j)  
    //                              aipbook.cpp:1083 (71)
    //         004107b9     MOV        EDI,s_Overflow                                   = 4Fh
    //         004107be     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_004107c2                                                 XREF[1]:     004107e4(j)  
    //         004107c2     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         004107c4     MOV        this,byte ptr [EDI]=>s_Overflow                  = 4Fh
    //                                                                                  = 65h
    //         004107c6     MOV        AL,DL
    //         004107c8     CMP        DL,this
    //         004107ca     JNZ        LAB_004107ea
    //         004107cc     TEST       AL,AL
    //         004107ce     JZ         LAB_004107e6
    //         004107d0     MOV        this,byte ptr [ESI + temp2[5]]
    //         004107d3     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f6c9            = 76h
    //                                                                                  = "rflow"
    //         004107d6     MOV        AL,this
    //         004107d8     CMP        this,DL
    //         004107da     JNZ        LAB_004107ea
    //         004107dc     ADD        ESI,0x2
    //         004107df     ADD        EDI,0x2
    //         004107e2     TEST       AL,AL
    //         004107e4     JNZ        LAB_004107c2
    //                               LAB_004107e6                                                 XREF[1]:     004107ce(j)  
    //         004107e6     XOR        EAX,EAX
    //         004107e8     JMP        LAB_004107ef
    //                               LAB_004107ea                                                 XREF[2]:     004107ca(j), 004107da(j)  
    //         004107ea     SBB        EAX,EAX
    //         004107ec     SBB        EAX,-0x1
    //                               LAB_004107ef                                                 XREF[1]:     004107e8(j)  
    //         004107ef     TEST       EAX,EAX
    //         004107f1     JNZ        LAB_004108c2
    //         004107f7     CMP        EBP,-0x1
    //         004107fa     JZ         LAB_004108c2
    //                              aipbook.cpp:1084 (26)
    //         00410800     LEA        EDX=>temp2[4],[ESP + 0x70]
    //         00410804     LEA        EAX=>temp[4],[ESP + 0x190]
    //         0041080b     PUSH       EDX
    //         0041080c     PUSH       s_%*s_%s_                                        = "%*s %s "
    //         00410811     PUSH       EAX
    //         00410812     CALL       sscanf                                           undefined sscanf()
    //         00410817     ADD        ESP,0xc
    //                              aipbook.cpp:1085 (58)
    //         0041081a     MOV        EDI,s_Balance                                    = 42h
    //         0041081f     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410823                                                 XREF[1]:     00410845(j)  
    //         00410823     MOV        this,byte ptr [ESI]=>temp2[4]
    //         00410825     MOV        DL,byte ptr [EDI]=>s_Balance                     = 42h
    //                                                                                  = 6Ch
    //         00410827     MOV        AL,this
    //         00410829     CMP        this,DL
    //         0041082b     JNZ        LAB_0041084b
    //         0041082d     TEST       AL,AL
    //         0041082f     JZ         LAB_00410847
    //         00410831     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410834     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f6c1          = 61h
    //         00410837     MOV        AL,DL
    //         00410839     CMP        DL,this
    //         0041083b     JNZ        LAB_0041084b
    //         0041083d     ADD        ESI,0x2
    //         00410840     ADD        EDI,0x2
    //         00410843     TEST       AL,AL
    //         00410845     JNZ        LAB_00410823
    //                               LAB_00410847                                                 XREF[1]:     0041082f(j)  
    //         00410847     XOR        EAX,EAX
    //         00410849     JMP        LAB_00410850
    //                               LAB_0041084b                                                 XREF[2]:     0041082b(j), 0041083b(j)  
    //         0041084b     SBB        EAX,EAX
    //         0041084d     SBB        EAX,-0x1
    //                               LAB_00410850                                                 XREF[1]:     00410849(j)  
    //         00410850     TEST       EAX,EAX
    //         00410852     JNZ        LAB_0041086c
    //                              aipbook.cpp:1086 (19)
    //         00410854     MOV        this,dword ptr [EBX + 0x4c]
    //         00410857     LEA        EAX,[EBP + EBP*0x2]
    //         0041085b     SHL        EAX,0x6
    //         0041085e     ADD        EAX,EBP
    //         00410860     LEA        EAX,[this->_padding_ + EAX*0x8]
    //         00410863     MOV        byte ptr [EAX + 0x4f],0x1
    //                              aipbook.cpp:1087 (67)
    //         00410867     JMP        LAB_004112c5
    //                               LAB_0041086c                                                 XREF[1]:     00410852(j)  
    //         0041086c     MOV        EDI,s_FirstGroup                                 = 46h
    //         00410871     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410875                                                 XREF[1]:     00410897(j)  
    //         00410875     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410877     MOV        this,byte ptr [EDI]=>s_FirstGroup                = 46h
    //                                                                                  = 72h
    //         00410879     MOV        AL,DL
    //         0041087b     CMP        DL,this
    //         0041087d     JNZ        LAB_0041089d
    //         0041087f     TEST       AL,AL
    //         00410881     JZ         LAB_00410899
    //         00410883     MOV        this,byte ptr [ESI + temp2[5]]
    //         00410886     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f6b5            = 69h
    //                                                                                  = "stGroup"
    //         00410889     MOV        AL,this
    //         0041088b     CMP        this,DL
    //         0041088d     JNZ        LAB_0041089d
    //         0041088f     ADD        ESI,0x2
    //         00410892     ADD        EDI,0x2
    //         00410895     TEST       AL,AL
    //         00410897     JNZ        LAB_00410875
    //                               LAB_00410899                                                 XREF[1]:     00410881(j)  
    //         00410899     XOR        EAX,EAX
    //         0041089b     JMP        LAB_004108a2
    //                               LAB_0041089d                                                 XREF[2]:     0041087d(j), 0041088d(j)  
    //         0041089d     SBB        EAX,EAX
    //         0041089f     SBB        EAX,-0x1
    //                               LAB_004108a2                                                 XREF[1]:     0041089b(j)  
    //         004108a2     TEST       EAX,EAX
    //         004108a4     JNZ        LAB_004112c5
    //                              aipbook.cpp:1088 (19)
    //         004108aa     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004108ad     LEA        EDX,[EBP + EBP*0x2]
    //         004108b1     SHL        EDX,0x6
    //         004108b4     ADD        EDX,EBP
    //         004108b6     LEA        EAX,[EAX + EDX*0x8]
    //         004108b9     MOV        byte ptr [EAX + 0x4f],0x2
    //                              aipbook.cpp:1089 (5)
    //         004108bd     JMP        LAB_004112c5
    //                               LAB_004108c2                                                 XREF[2]:     004107f1(j), 004107fa(j)  
    //                              aipbook.cpp:1093 (63)
    //         004108c2     MOV        EDI,s_DeathPercentage                            = 44h
    //         004108c7     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_004108cb                                                 XREF[1]:     004108ed(j)  
    //         004108cb     MOV        this,byte ptr [ESI]=>temp2[4]
    //         004108cd     MOV        DL,byte ptr [EDI]=>s_DeathPercentage             = 44h
    //                                                                                  = 61h
    //         004108cf     MOV        AL,this
    //         004108d1     CMP        this,DL
    //         004108d3     JNZ        LAB_004108f3
    //         004108d5     TEST       AL,AL
    //         004108d7     JZ         LAB_004108ef
    //         004108d9     MOV        DL,byte ptr [ESI + temp2[5]]
    //         004108dc     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f6a5          = 65h
    //                                                                                  = "thPercentage"
    //         004108df     MOV        AL,DL
    //         004108e1     CMP        DL,this
    //         004108e3     JNZ        LAB_004108f3
    //         004108e5     ADD        ESI,0x2
    //         004108e8     ADD        EDI,0x2
    //         004108eb     TEST       AL,AL
    //         004108ed     JNZ        LAB_004108cb
    //                               LAB_004108ef                                                 XREF[1]:     004108d7(j)  
    //         004108ef     XOR        EAX,EAX
    //         004108f1     JMP        LAB_004108f8
    //                               LAB_004108f3                                                 XREF[2]:     004108d3(j), 004108e3(j)  
    //         004108f3     SBB        EAX,EAX
    //         004108f5     SBB        EAX,-0x1
    //                               LAB_004108f8                                                 XREF[1]:     004108f1(j)  
    //         004108f8     TEST       EAX,EAX
    //         004108fa     JNZ        LAB_0041096b
    //         004108fc     CMP        EBP,-0x1
    //         004108ff     JZ         LAB_0041096b
    //                              aipbook.cpp:1094 (23)
    //         00410901     LEA        EAX=>temp4,[ESP + 0x10]
    //         00410905     LEA        this=>temp[4],[ESP + 0x190]
    //         0041090c     PUSH       EAX
    //         0041090d     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         00410912     PUSH       this
    //         00410913     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1095 (11)
    //         00410918     MOV        EAX,dword ptr [ESP + temp4]
    //         0041091c     ADD        ESP,0xc
    //         0041091f     TEST       EAX,EAX
    //         00410921     JGE        LAB_0041093b
    //                              aipbook.cpp:1096 (19)
    //         00410923     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00410926     LEA        EDX,[EBP + EBP*0x2]
    //         0041092a     SHL        EDX,0x6
    //         0041092d     ADD        EDX,EBP
    //         0041092f     LEA        EAX,[EAX + EDX*0x8]
    //         00410932     MOV        byte ptr [EAX + 0x51],0x0
    //                              aipbook.cpp:1097 (8)
    //         00410936     JMP        LAB_004112c5
    //                               LAB_0041093b                                                 XREF[1]:     00410921(j)  
    //         0041093b     CMP        EAX,0x64
    //                              aipbook.cpp:1098 (21)
    //         0041093e     LEA        this,[EBP + EBP*0x2]
    //         00410942     JLE        LAB_00410958
    //         00410944     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00410947     SHL        this,0x6
    //         0041094a     ADD        this,EBP
    //         0041094c     LEA        EAX,[EDX + this->_padding_*0x8]
    //         0041094f     MOV        byte ptr [EAX + 0x51],0x64
    //                              aipbook.cpp:1099 (5)
    //         00410953     JMP        LAB_004112c5
    //                               LAB_00410958                                                 XREF[1]:     00410942(j)  
    //                              aipbook.cpp:1100 (14)
    //         00410958     MOV        EDX,dword ptr [EBX + 0x4c]
    //         0041095b     SHL        this,0x6
    //         0041095e     ADD        this,EBP
    //         00410960     LEA        this,[EDX + this->_padding_*0x8]
    //         00410963     MOV        byte ptr [this->_padding_ + 0x51],AL
    //                              aipbook.cpp:1101 (5)
    //         00410966     JMP        LAB_004112c5
    //                               LAB_0041096b                                                 XREF[2]:     004108fa(j), 004108ff(j)  
    //                              aipbook.cpp:1105 (63)
    //         0041096b     MOV        EDI,s_Intelligence                               = 49h
    //         00410970     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410974                                                 XREF[1]:     00410996(j)  
    //         00410974     MOV        this,byte ptr [ESI]=>temp2[4]
    //         00410976     MOV        DL,byte ptr [EDI]=>s_Intelligence                = 49h
    //                                                                                  = 74h
    //         00410978     MOV        AL,this
    //         0041097a     CMP        this,DL
    //         0041097c     JNZ        LAB_0041099c
    //         0041097e     TEST       AL,AL
    //         00410980     JZ         LAB_00410998
    //         00410982     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410985     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f695          = 6Eh
    //                                                                                  = "elligence"
    //         00410988     MOV        AL,DL
    //         0041098a     CMP        DL,this
    //         0041098c     JNZ        LAB_0041099c
    //         0041098e     ADD        ESI,0x2
    //         00410991     ADD        EDI,0x2
    //         00410994     TEST       AL,AL
    //         00410996     JNZ        LAB_00410974
    //                               LAB_00410998                                                 XREF[1]:     00410980(j)  
    //         00410998     XOR        EAX,EAX
    //         0041099a     JMP        LAB_004109a1
    //                               LAB_0041099c                                                 XREF[2]:     0041097c(j), 0041098c(j)  
    //         0041099c     SBB        EAX,EAX
    //         0041099e     SBB        EAX,-0x1
    //                               LAB_004109a1                                                 XREF[1]:     0041099a(j)  
    //         004109a1     TEST       EAX,EAX
    //         004109a3     JNZ        LAB_00410a14
    //         004109a5     CMP        EBP,-0x1
    //         004109a8     JZ         LAB_00410a14
    //                              aipbook.cpp:1106 (23)
    //         004109aa     LEA        EAX=>temp4,[ESP + 0x10]
    //         004109ae     LEA        this=>temp[4],[ESP + 0x190]
    //         004109b5     PUSH       EAX
    //         004109b6     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         004109bb     PUSH       this
    //         004109bc     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1107 (11)
    //         004109c1     MOV        EAX,dword ptr [ESP + temp4]
    //         004109c5     ADD        ESP,0xc
    //         004109c8     TEST       EAX,EAX
    //         004109ca     JGE        LAB_004109e4
    //                              aipbook.cpp:1108 (19)
    //         004109cc     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004109cf     LEA        EDX,[EBP + EBP*0x2]
    //         004109d3     SHL        EDX,0x6
    //         004109d6     ADD        EDX,EBP
    //         004109d8     LEA        EAX,[EAX + EDX*0x8]
    //         004109db     MOV        byte ptr [EAX + 0x50],0x0
    //                              aipbook.cpp:1109 (8)
    //         004109df     JMP        LAB_004112c5
    //                               LAB_004109e4                                                 XREF[1]:     004109ca(j)  
    //         004109e4     CMP        EAX,0x64
    //                              aipbook.cpp:1110 (21)
    //         004109e7     LEA        this,[EBP + EBP*0x2]
    //         004109eb     JLE        LAB_00410a01
    //         004109ed     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004109f0     SHL        this,0x6
    //         004109f3     ADD        this,EBP
    //         004109f5     LEA        EAX,[EDX + this->_padding_*0x8]
    //         004109f8     MOV        byte ptr [EAX + 0x50],0x64
    //                              aipbook.cpp:1111 (5)
    //         004109fc     JMP        LAB_004112c5
    //                               LAB_00410a01                                                 XREF[1]:     004109eb(j)  
    //                              aipbook.cpp:1112 (14)
    //         00410a01     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00410a04     SHL        this,0x6
    //         00410a07     ADD        this,EBP
    //         00410a09     LEA        this,[EDX + this->_padding_*0x8]
    //         00410a0c     MOV        byte ptr [ECX + this+0x50],AL
    //                              aipbook.cpp:1113 (5)
    //         00410a0f     JMP        LAB_004112c5
    //                               LAB_00410a14                                                 XREF[2]:     004109a3(j), 004109a8(j)  
    //                              aipbook.cpp:1118 (63)
    //         00410a14     MOV        EDI,s_TargetChar                                 = 54h
    //         00410a19     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410a1d                                                 XREF[1]:     00410a3f(j)  
    //         00410a1d     MOV        this,byte ptr [ESI]=>temp2[4]
    //         00410a1f     MOV        DL,byte ptr [EDI]=>s_TargetChar                  = 54h
    //                                                                                  = 72h
    //         00410a21     MOV        AL,this
    //         00410a23     CMP        this,DL
    //         00410a25     JNZ        LAB_00410a45
    //         00410a27     TEST       AL,AL
    //         00410a29     JZ         LAB_00410a41
    //         00410a2b     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410a2e     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f689          = 61h
    //                                                                                  = "getChar"
    //         00410a31     MOV        AL,DL
    //         00410a33     CMP        DL,this
    //         00410a35     JNZ        LAB_00410a45
    //         00410a37     ADD        ESI,0x2
    //         00410a3a     ADD        EDI,0x2
    //         00410a3d     TEST       AL,AL
    //         00410a3f     JNZ        LAB_00410a1d
    //                               LAB_00410a41                                                 XREF[1]:     00410a29(j)  
    //         00410a41     XOR        EAX,EAX
    //         00410a43     JMP        LAB_00410a4a
    //                               LAB_00410a45                                                 XREF[2]:     00410a25(j), 00410a35(j)  
    //         00410a45     SBB        EAX,EAX
    //         00410a47     SBB        EAX,-0x1
    //                               LAB_00410a4a                                                 XREF[1]:     00410a43(j)  
    //         00410a4a     TEST       EAX,EAX
    //         00410a4c     JNZ        LAB_00410aa1
    //         00410a4e     CMP        EBP,-0x1
    //         00410a51     JZ         LAB_00410aa1
    //                              aipbook.cpp:1119 (26)
    //         00410a53     LEA        EAX=>temp6[4],[ESP + 0x2b8]
    //         00410a5a     LEA        this=>temp[4],[ESP + 0x190]
    //         00410a61     PUSH       EAX
    //         00410a62     PUSH       s_%*s_%s_                                        = "%*s %s "
    //         00410a67     PUSH       this
    //         00410a68     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1120 (18)
    //         00410a6d     MOV        EDX,dword ptr [EBX]
    //         00410a6f     ADD        ESP,0xc
    //         00410a72     LEA        EAX=>temp6[4],[ESP + 0x2b8]
    //         00410a79     MOV        this,EBX
    //         00410a7b     PUSH       EAX
    //         00410a7c     CALL       dword ptr [EDX + 0x8]
    //                              aipbook.cpp:1121 (8)
    //         00410a7f     TEST       EAX,EAX
    //         00410a81     JZ         LAB_004112c5
    //                              aipbook.cpp:1122 (21)
    //         00410a87     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00410a8a     LEA        this,[EBP + EBP*0x2]
    //         00410a8e     SHL        this,0x6
    //         00410a91     ADD        this,EBP
    //         00410a93     PUSH       EAX
    //         00410a94     LEA        this,[EDX + this->_padding_*0x8]
    //         00410a97     CALL       AIPlay::addTargetCharacteristic                  int addTargetCharacteristic(AIPlay * this, uc
    //                              aipbook.cpp:1123 (5)
    //         00410a9c     JMP        LAB_004112c5
    //                               LAB_00410aa1                                                 XREF[2]:     00410a4c(j), 00410a51(j)  
    //                              aipbook.cpp:1128 (63)
    //         00410aa1     MOV        EDI,s_TargetType                                 = 54h
    //         00410aa6     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410aaa                                                 XREF[1]:     00410acc(j)  
    //         00410aaa     MOV        this,byte ptr [ESI]=>temp2[4]
    //         00410aac     MOV        DL,byte ptr [EDI]=>s_TargetType                  = 54h
    //                                                                                  = 72h
    //         00410aae     MOV        AL,this
    //         00410ab0     CMP        this,DL
    //         00410ab2     JNZ        LAB_00410ad2
    //         00410ab4     TEST       AL,AL
    //         00410ab6     JZ         LAB_00410ace
    //         00410ab8     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410abb     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f67d          = 61h
    //                                                                                  = "getType"
    //         00410abe     MOV        AL,DL
    //         00410ac0     CMP        DL,this
    //         00410ac2     JNZ        LAB_00410ad2
    //         00410ac4     ADD        ESI,0x2
    //         00410ac7     ADD        EDI,0x2
    //         00410aca     TEST       AL,AL
    //         00410acc     JNZ        LAB_00410aaa
    //                               LAB_00410ace                                                 XREF[1]:     00410ab6(j)  
    //         00410ace     XOR        EAX,EAX
    //         00410ad0     JMP        LAB_00410ad7
    //                               LAB_00410ad2                                                 XREF[2]:     00410ab2(j), 00410ac2(j)  
    //         00410ad2     SBB        EAX,EAX
    //         00410ad4     SBB        EAX,-0x1
    //                               LAB_00410ad7                                                 XREF[1]:     00410ad0(j)  
    //         00410ad7     TEST       EAX,EAX
    //         00410ad9     JNZ        LAB_00410b2e
    //         00410adb     CMP        EBP,-0x1
    //         00410ade     JZ         LAB_00410b2e
    //                              aipbook.cpp:1129 (26)
    //         00410ae0     LEA        EAX=>temp6[4],[ESP + 0x2b8]
    //         00410ae7     LEA        this=>temp[4],[ESP + 0x190]
    //         00410aee     PUSH       EAX
    //         00410aef     PUSH       s_%*s_%s_                                        = "%*s %s "
    //         00410af4     PUSH       this
    //         00410af5     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1130 (18)
    //         00410afa     MOV        EDX,dword ptr [EBX]
    //         00410afc     ADD        ESP,0xc
    //         00410aff     LEA        EAX=>temp6[4],[ESP + 0x2b8]
    //         00410b06     MOV        this,EBX
    //         00410b08     PUSH       EAX
    //         00410b09     CALL       dword ptr [EDX + 0x4]
    //                              aipbook.cpp:1131 (8)
    //         00410b0c     TEST       EAX,EAX
    //         00410b0e     JZ         LAB_004112c5
    //                              aipbook.cpp:1132 (21)
    //         00410b14     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00410b17     LEA        this,[EBP + EBP*0x2]
    //         00410b1b     SHL        this,0x6
    //         00410b1e     ADD        this,EBP
    //         00410b20     PUSH       EAX
    //         00410b21     LEA        this,[EDX + this->_padding_*0x8]
    //         00410b24     CALL       AIPlay::addTargetType                            int addTargetType(AIPlay * this, uchar param_1)
    //                              aipbook.cpp:1133 (5)
    //         00410b29     JMP        LAB_004112c5
    //                               LAB_00410b2e                                                 XREF[2]:     00410ad9(j), 00410ade(j)  
    //                              aipbook.cpp:1138 (63)
    //         00410b2e     MOV        EDI,s_NumberGroups                               = 4Eh
    //         00410b33     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410b37                                                 XREF[1]:     00410b59(j)  
    //         00410b37     MOV        this,byte ptr [ESI]=>temp2[4]
    //         00410b39     MOV        DL,byte ptr [EDI]=>s_NumberGroups                = 4Eh
    //                                                                                  = 6Dh
    //         00410b3b     MOV        AL,this
    //         00410b3d     CMP        this,DL
    //         00410b3f     JNZ        LAB_00410b5f
    //         00410b41     TEST       AL,AL
    //         00410b43     JZ         LAB_00410b5b
    //         00410b45     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410b48     MOV        this,byte ptr [EDI + 0x1]=>DAT_0057f66d          = 75h
    //                                                                                  = "berGroups"
    //         00410b4b     MOV        AL,DL
    //         00410b4d     CMP        DL,this
    //         00410b4f     JNZ        LAB_00410b5f
    //         00410b51     ADD        ESI,0x2
    //         00410b54     ADD        EDI,0x2
    //         00410b57     TEST       AL,AL
    //         00410b59     JNZ        LAB_00410b37
    //                               LAB_00410b5b                                                 XREF[1]:     00410b43(j)  
    //         00410b5b     XOR        EAX,EAX
    //         00410b5d     JMP        LAB_00410b64
    //                               LAB_00410b5f                                                 XREF[2]:     00410b3f(j), 00410b4f(j)  
    //         00410b5f     SBB        EAX,EAX
    //         00410b61     SBB        EAX,-0x1
    //                               LAB_00410b64                                                 XREF[1]:     00410b5d(j)  
    //         00410b64     TEST       EAX,EAX
    //         00410b66     JNZ        LAB_00410ba2
    //         00410b68     CMP        EBP,-0x1
    //         00410b6b     JZ         LAB_00410ba2
    //                              aipbook.cpp:1139 (23)
    //         00410b6d     LEA        EAX=>temp4,[ESP + 0x10]
    //         00410b71     LEA        this=>temp[4],[ESP + 0x190]
    //         00410b78     PUSH       EAX
    //         00410b79     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         00410b7e     PUSH       this
    //         00410b7f     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1140 (25)
    //         00410b84     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00410b87     LEA        EDX,[EBP + EBP*0x2]
    //         00410b8b     MOV        this,byte ptr [ESP + temp4]
    //         00410b8f     ADD        ESP,0xc
    //         00410b92     SHL        EDX,0x6
    //         00410b95     ADD        EDX,EBP
    //         00410b97     LEA        EAX,[EAX + EDX*0x8]
    //         00410b9a     MOV        byte ptr [EAX + 0x52],this
    //                              aipbook.cpp:1141 (5)
    //         00410b9d     JMP        LAB_004112c5
    //                               LAB_00410ba2                                                 XREF[2]:     00410b66(j), 00410b6b(j)  
    //                              aipbook.cpp:1146 (84)
    //         00410ba2     MOV        EDI,s_Group                                      = 47h
    //         00410ba7     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410bab                                                 XREF[1]:     00410bcd(j)  
    //         00410bab     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410bad     MOV        this,byte ptr [EDI]=>s_Group                     = 47h
    //                                                                                  = 6Fh
    //         00410baf     MOV        AL,DL
    //         00410bb1     CMP        DL,this
    //         00410bb3     JNZ        LAB_00410bd3
    //         00410bb5     TEST       AL,AL
    //         00410bb7     JZ         LAB_00410bcf
    //         00410bb9     MOV        this,byte ptr [ESI + temp2[5]]
    //         00410bbc     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f665            = 72h
    //                                                                                  = 75h
    //         00410bbf     MOV        AL,this
    //         00410bc1     CMP        this,DL
    //         00410bc3     JNZ        LAB_00410bd3
    //         00410bc5     ADD        ESI,0x2
    //         00410bc8     ADD        EDI,0x2
    //         00410bcb     TEST       AL,AL
    //         00410bcd     JNZ        LAB_00410bab
    //                               LAB_00410bcf                                                 XREF[1]:     00410bb7(j)  
    //         00410bcf     XOR        EAX,EAX
    //         00410bd1     JMP        LAB_00410bd8
    //                               LAB_00410bd3                                                 XREF[2]:     00410bb3(j), 00410bc3(j)  
    //         00410bd3     SBB        EAX,EAX
    //         00410bd5     SBB        EAX,-0x1
    //                               LAB_00410bd8                                                 XREF[1]:     00410bd1(j)  
    //         00410bd8     TEST       EAX,EAX
    //         00410bda     JNZ        LAB_00410cc7
    //         00410be0     CMP        EBP,-0x1
    //         00410be3     JZ         LAB_00410cc7
    //         00410be9     MOV        this,dword ptr [ESP + Stack[-0x3a8]]
    //         00410bed     CMP        this,-0x1
    //         00410bf0     JNZ        LAB_00410ccb
    //                              aipbook.cpp:1147 (41)
    //         00410bf6     LEA        EDX=>i,[ESP + 0x38]
    //         00410bfa     LEA        EAX=>Stack[-0x3b0],[ESP + 0x14]
    //         00410bfe     PUSH       EDX
    //         00410bff     LEA        this=>temp6[4],[ESP + 0x2bc]
    //         00410c06     PUSH       EAX
    //         00410c07     LEA        EDX=>temp4,[ESP + 0x18]
    //         00410c0b     PUSH       this
    //         00410c0c     PUSH       EDX
    //         00410c0d     LEA        EAX=>temp[4],[ESP + 0x1a0]
    //         00410c14     PUSH       s_%*s_%d_%s_%d_-_%d_                             = "%*s %d %s %d - %d "
    //         00410c19     PUSH       EAX
    //         00410c1a     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1148 (24)
    //         00410c1f     MOV        EAX,dword ptr [ESP + temp4]
    //         00410c23     ADD        ESP,0x18
    //         00410c26     TEST       EAX,EAX
    //         00410c28     JL         LAB_004112c5
    //         00410c2e     CMP        EAX,0x5
    //         00410c31     JGE        LAB_004112c5
    //                              aipbook.cpp:1149 (17)
    //         00410c37     MOV        EDX,dword ptr [EBX]
    //         00410c39     LEA        EAX=>temp6[4],[ESP + 0x2b8]
    //         00410c40     PUSH       EAX
    //         00410c41     MOV        this,EBX
    //         00410c43     CALL       dword ptr [EDX + 0xc]
    //         00410c46     MOV        EDI,EAX
    //                              aipbook.cpp:1150 (9)
    //         00410c48     CMP        EDI,-0x1
    //         00410c4b     JZ         LAB_004112c5
    //                              aipbook.cpp:1151 (4)
    //         00410c51     MOV        EAX,dword ptr [ESP + 0x38]
    //                              aipbook.cpp:1152 (27)
    //         00410c55     LEA        ESI,[EBP + EBP*0x2]
    //         00410c59     TEST       EAX,EAX
    //         00410c5b     JL         LAB_00410c72
    //         00410c5d     MOV        this,dword ptr [ESP + 0x14]
    //         00410c61     MOV        EDX,dword ptr [ESP + 0x10]
    //         00410c65     SHL        ESI,0x6
    //         00410c68     ADD        ESI,EBP
    //         00410c6a     PUSH       this
    //         00410c6b     PUSH       EDI=>DAT_fffffff8
    //         00410c6c     PUSH       EDX=>DAT_fffffff4
    //         00410c6d     SHL        ESI,0x3
    //                              aipbook.cpp:1153 (2)
    //         00410c70     JMP        LAB_00410c82
    //                               LAB_00410c72                                                 XREF[1]:     00410c5b(j)  
    //                              aipbook.cpp:1154 (35)
    //         00410c72     MOV        EAX,dword ptr [ESP + 0x10]
    //         00410c76     PUSH       0x0
    //         00410c78     SHL        ESI,0x6
    //         00410c7b     ADD        ESI,EBP
    //         00410c7d     PUSH       EDI=>DAT_fffffff8
    //         00410c7e     SHL        ESI,0x3
    //         00410c81     PUSH       EAX=>DAT_fffffff4
    //                               LAB_00410c82                                                 XREF[1]:     00410c70(j)  
    //         00410c82     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00410c85     MOV        this,ESI
    //         00410c87     ADD        this,EAX
    //         00410c89     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //         00410c8e     MOV        this,EAX
    //         00410c90     CALL       AIPlayGroup::setMinimum                          void setMinimum(AIPlayGroup * this, int param
    //                              aipbook.cpp:1155 (9)
    //         00410c95     MOV        EAX,dword ptr [ESP + 0x38]
    //         00410c99     CMP        EAX,0x32
    //         00410c9c     JG         LAB_00410ca7
    //                              aipbook.cpp:1156 (7)
    //         00410c9e     MOV        this,dword ptr [ESP + 0x10]
    //         00410ca2     PUSH       EAX
    //         00410ca3     PUSH       EDI=>DAT_fffffff8
    //         00410ca4     PUSH       this=>DAT_fffffff4
    //                              aipbook.cpp:1157 (2)
    //         00410ca5     JMP        LAB_00410caf
    //                               LAB_00410ca7                                                 XREF[1]:     00410c9c(j)  
    //                              aipbook.cpp:1158 (27)
    //         00410ca7     MOV        EDX,dword ptr [ESP + 0x10]
    //         00410cab     PUSH       0x32
    //         00410cad     PUSH       EDI=>DAT_fffffff8
    //         00410cae     PUSH       EDX=>DAT_fffffff4
    //                               LAB_00410caf                                                 XREF[1]:     00410ca5(j)  
    //         00410caf     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00410cb2     MOV        this,ESI
    //         00410cb4     ADD        this,EAX
    //         00410cb6     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //         00410cbb     MOV        this,EAX
    //         00410cbd     CALL       AIPlayGroup::setMaximum                          void setMaximum(AIPlayGroup * this, int param
    //                              aipbook.cpp:1161 (9)
    //         00410cc2     JMP        LAB_004112c5
    //                               LAB_00410cc7                                                 XREF[2]:     00410bda(j), 00410be3(j)  
    //         00410cc7     MOV        this,dword ptr [ESP + Stack[-0x3a8]]
    //                               LAB_00410ccb                                                 XREF[1]:     00410bf0(j)  
    //                              aipbook.cpp:1165 (59)
    //         00410ccb     MOV        EDI,s_Phase                                      = 50h
    //         00410cd0     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410cd4                                                 XREF[1]:     00410cf2(j)  
    //         00410cd4     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410cd6     MOV        AL,DL
    //         00410cd8     CMP        DL,byte ptr [EDI]=>s_Phase                       = 50h
    //                                                                                  = 61h
    //         00410cda     JNZ        LAB_00410cf8
    //         00410cdc     TEST       AL,AL
    //         00410cde     JZ         LAB_00410cf4
    //         00410ce0     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410ce3     MOV        AL,DL
    //         00410ce5     CMP        DL,byte ptr [EDI + 0x1]=>DAT_0057f649            = 68h
    //                                                                                  = 73h
    //         00410ce8     JNZ        LAB_00410cf8
    //         00410cea     ADD        ESI,0x2
    //         00410ced     ADD        EDI,0x2
    //         00410cf0     TEST       AL,AL
    //         00410cf2     JNZ        LAB_00410cd4
    //                               LAB_00410cf4                                                 XREF[1]:     00410cde(j)  
    //         00410cf4     XOR        EAX,EAX
    //         00410cf6     JMP        LAB_00410cfd
    //                               LAB_00410cf8                                                 XREF[2]:     00410cda(j), 00410ce8(j)  
    //         00410cf8     SBB        EAX,EAX
    //         00410cfa     SBB        EAX,-0x1
    //                               LAB_00410cfd                                                 XREF[1]:     00410cf6(j)  
    //         00410cfd     TEST       EAX,EAX
    //         00410cff     JNZ        LAB_00410d2d
    //         00410d01     CMP        EBP,-0x1
    //         00410d04     JZ         LAB_00410d2d
    //                              aipbook.cpp:1166 (23)
    //         00410d06     LEA        EAX=>temp4,[ESP + 0x10]
    //         00410d0a     LEA        this=>temp[4],[ESP + 0x190]
    //         00410d11     PUSH       EAX
    //         00410d12     PUSH       s_%*s_%d_                                        = "%*s %d "
    //         00410d17     PUSH       this
    //         00410d18     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1167 (11)
    //         00410d1d     MOV        EDX,dword ptr [ESP + temp4]
    //         00410d21     ADD        ESP,0xc
    //         00410d24     MOV        dword ptr [ESP + Stack[-0x3a8]],EDX
    //                              aipbook.cpp:1168 (5)
    //         00410d28     JMP        LAB_004112c5
    //                               LAB_00410d2d                                                 XREF[2]:     00410cff(j), 00410d04(j)  
    //                              aipbook.cpp:1173 (76)
    //         00410d2d     MOV        EDI,s_Group                                      = 47h
    //         00410d32     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410d36                                                 XREF[1]:     00410d54(j)  
    //         00410d36     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410d38     MOV        AL,DL
    //         00410d3a     CMP        DL,byte ptr [EDI]=>s_Group                       = 47h
    //                                                                                  = 6Fh
    //         00410d3c     JNZ        LAB_00410d5a
    //         00410d3e     TEST       AL,AL
    //         00410d40     JZ         LAB_00410d56
    //         00410d42     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410d45     MOV        AL,DL
    //         00410d47     CMP        DL,byte ptr [EDI + 0x1]=>DAT_0057f665            = 72h
    //                                                                                  = 75h
    //         00410d4a     JNZ        LAB_00410d5a
    //         00410d4c     ADD        ESI,0x2
    //         00410d4f     ADD        EDI,0x2
    //         00410d52     TEST       AL,AL
    //         00410d54     JNZ        LAB_00410d36
    //                               LAB_00410d56                                                 XREF[1]:     00410d40(j)  
    //         00410d56     XOR        EAX,EAX
    //         00410d58     JMP        LAB_00410d5f
    //                               LAB_00410d5a                                                 XREF[2]:     00410d3c(j), 00410d4a(j)  
    //         00410d5a     SBB        EAX,EAX
    //         00410d5c     SBB        EAX,-0x1
    //                               LAB_00410d5f                                                 XREF[1]:     00410d58(j)  
    //         00410d5f     TEST       EAX,EAX
    //         00410d61     JNZ        LAB_00410e16
    //         00410d67     CMP        EBP,-0x1
    //         00410d6a     JZ         LAB_00410e16
    //         00410d70     CMP        this,-0x1
    //         00410d73     JZ         LAB_00410e16
    //                              aipbook.cpp:1174 (46)
    //         00410d79     LEA        EAX=>fileIn,[ESP + 0x44]
    //         00410d7d     LEA        this=>i,[ESP + 0x38]
    //         00410d81     PUSH       EAX
    //         00410d82     LEA        EDX=>Stack[-0x3b0],[ESP + 0x18]
    //         00410d86     PUSH       this
    //         00410d87     LEA        EAX=>temp6[4],[ESP + 0x2c0]
    //         00410d8e     PUSH       EDX
    //         00410d8f     LEA        this=>temp4,[ESP + 0x1c]
    //         00410d93     PUSH       EAX
    //         00410d94     PUSH       this
    //         00410d95     LEA        EDX=>temp[4],[ESP + 0x1a4]
    //         00410d9c     PUSH       s_%*s_%d_%s_%d_%d_%d_                            = "%*s %d %s %d %d %d "
    //         00410da1     PUSH       EDX
    //         00410da2     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1175 (24)
    //         00410da7     MOV        EAX,dword ptr [ESP + temp4]
    //         00410dab     ADD        ESP,0x1c
    //         00410dae     TEST       EAX,EAX
    //         00410db0     JL         LAB_004112c5
    //         00410db6     CMP        EAX,0x5
    //         00410db9     JGE        LAB_004112c5
    //                              aipbook.cpp:1176 (25)
    //         00410dbf     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00410dc2     MOV        EAX,dword ptr [ESP + Stack[-0x3a8]]
    //         00410dc6     LEA        this,[EBP + EBP*0x2]
    //         00410dca     PUSH       EAX
    //         00410dcb     SHL        this,0x6
    //         00410dce     ADD        this,EBP
    //         00410dd0     LEA        this,[EDX + this->_padding_*0x8]
    //         00410dd3     CALL       AIPlay::phase                                    AIPlayPhase * phase(AIPlay * this, int param_1)
    //                              aipbook.cpp:1177 (42)
    //         00410dd8     MOV        this,dword ptr [ESP + i]
    //         00410ddc     MOV        EDX,dword ptr [ESP + Stack[-0x3b0]]
    //         00410de0     MOV        ESI,EAX
    //         00410de2     MOV        EAX,dword ptr [ESP + fileIn]
    //         00410de6     PUSH       EAX
    //         00410de7     PUSH       this
    //         00410de8     MOV        this,dword ptr [ESP + temp4]
    //         00410dec     LEA        EAX=>temp6[4],[ESP + 0x2c0]
    //         00410df3     PUSH       EDX
    //         00410df4     PUSH       EAX
    //         00410df5     PUSH       this
    //         00410df6     LEA        this=>command.value1Value,[ESP + 0x184]
    //         00410dfd     CALL       AIPlayPhaseCommand::AIPlayPhaseCommand           undefined AIPlayPhaseCommand(AIPlayPhaseComma
    //                              aipbook.cpp:1178 (15)
    //         00410e02     LEA        EDX=>command.value1Value,[ESP + 0x170]
    //         00410e09     MOV        this,ESI
    //         00410e0b     PUSH       EDX
    //         00410e0c     CALL       AIPlayPhase::addCommand                          int addCommand(AIPlayPhase * this, AIPlayPhas
    //                              aipbook.cpp:1180 (5)
    //         00410e11     JMP        LAB_004112c5
    //                               LAB_00410e16                                                 XREF[3]:     00410d61(j), 00410d6a(j), 
    //                                                                                                         00410d73(j)  
    //                              aipbook.cpp:1185 (76)
    //         00410e16     MOV        EDI,s_Trigger                                    = 54h
    //         00410e1b     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410e1f                                                 XREF[1]:     00410e3d(j)  
    //         00410e1f     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410e21     MOV        AL,DL
    //         00410e23     CMP        DL,byte ptr [EDI]=>s_Trigger                     = 54h
    //                                                                                  = 69h
    //         00410e25     JNZ        LAB_00410e43
    //         00410e27     TEST       AL,AL
    //         00410e29     JZ         LAB_00410e3f
    //         00410e2b     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410e2e     MOV        AL,DL
    //         00410e30     CMP        DL,byte ptr [EDI + 0x1]=>DAT_0057f62d            = 72h
    //                                                                                  = 67h
    //         00410e33     JNZ        LAB_00410e43
    //         00410e35     ADD        ESI,0x2
    //         00410e38     ADD        EDI,0x2
    //         00410e3b     TEST       AL,AL
    //         00410e3d     JNZ        LAB_00410e1f
    //                               LAB_00410e3f                                                 XREF[1]:     00410e29(j)  
    //         00410e3f     XOR        EAX,EAX
    //         00410e41     JMP        LAB_00410e48
    //                               LAB_00410e43                                                 XREF[2]:     00410e25(j), 00410e33(j)  
    //         00410e43     SBB        EAX,EAX
    //         00410e45     SBB        EAX,-0x1
    //                               LAB_00410e48                                                 XREF[1]:     00410e41(j)  
    //         00410e48     TEST       EAX,EAX
    //         00410e4a     JNZ        LAB_00410ee3
    //         00410e50     CMP        EBP,-0x1
    //         00410e53     JZ         LAB_00410ee3
    //         00410e59     CMP        this,-0x1
    //         00410e5c     JZ         LAB_00410ee3
    //                              aipbook.cpp:1186 (41)
    //         00410e62     LEA        EAX=>temp7,[ESP + 0x40]
    //         00410e66     LEA        this=>Stack[-0x3b0],[ESP + 0x14]
    //         00410e6a     PUSH       EAX
    //         00410e6b     LEA        EDX=>temp6[4],[ESP + 0x2bc]
    //         00410e72     PUSH       this
    //         00410e73     LEA        EAX=>temp4,[ESP + 0x18]
    //         00410e77     PUSH       EDX
    //         00410e78     PUSH       EAX
    //         00410e79     LEA        this=>temp[4],[ESP + 0x1a0]
    //         00410e80     PUSH       s_%*s_%d_%s_%d_%d_                               = "%*s %d %s %d %d "
    //         00410e85     PUSH       this
    //         00410e86     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1187 (28)
    //         00410e8b     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00410e8e     MOV        EDI,dword ptr [ESP + Stack[-0x3a8]]
    //         00410e92     LEA        EDX,[EBP + EBP*0x2]
    //         00410e96     ADD        ESP,0x18
    //         00410e99     SHL        EDX,0x6
    //         00410e9c     ADD        EDX,EBP
    //         00410e9e     PUSH       EDI
    //         00410e9f     LEA        this,[EAX + EDX*0x8]
    //         00410ea2     CALL       AIPlay::phase                                    AIPlayPhase * phase(AIPlay * this, int param_1)
    //                              aipbook.cpp:1189 (40)
    //         00410ea7     MOV        this,dword ptr [ESP + temp4]
    //         00410eab     MOV        EDX,dword ptr [ESP + temp7]
    //         00410eaf     PUSH       0x0
    //         00410eb1     MOV        ESI,EAX
    //         00410eb3     MOV        EAX,dword ptr [ESP + Stack[-0x3b0]]
    //         00410eb7     PUSH       this
    //         00410eb8     PUSH       EDI
    //         00410eb9     PUSH       EDX
    //         00410eba     LEA        this=>temp6[4],[ESP + 0x2c8]
    //         00410ec1     PUSH       EAX
    //         00410ec2     PUSH       this
    //         00410ec3     LEA        this=>trigger.value1Value,[ESP + 0x2a8]
    //         00410eca     CALL       AIPlayPhaseTrigger::AIPlayPhaseTrigger           undefined AIPlayPhaseTrigger(AIPlayPhaseTrigg
    //                              aipbook.cpp:1190 (15)
    //         00410ecf     LEA        EDX=>trigger.value1Value,[ESP + 0x290]
    //         00410ed6     MOV        this,ESI
    //         00410ed8     PUSH       EDX
    //         00410ed9     CALL       AIPlayPhase::addTrigger                          int addTrigger(AIPlayPhase * this, AIPlayPhas
    //                              aipbook.cpp:1191 (5)
    //         00410ede     JMP        LAB_004112c5
    //                               LAB_00410ee3                                                 XREF[3]:     00410e4a(j), 00410e53(j), 
    //                                                                                                         00410e5c(j)  
    //                              aipbook.cpp:1196 (76)
    //         00410ee3     MOV        EDI,s_RTrigger                                   = 52h
    //         00410ee8     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410eec                                                 XREF[1]:     00410f0a(j)  
    //         00410eec     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410eee     MOV        AL,DL
    //         00410ef0     CMP        DL,byte ptr [EDI]=>s_RTrigger                    = 52h
    //                                                                                  = 72h
    //         00410ef2     JNZ        LAB_00410f10
    //         00410ef4     TEST       AL,AL
    //         00410ef6     JZ         LAB_00410f0c
    //         00410ef8     MOV        DL,byte ptr [ESI + temp2[5]]
    //         00410efb     MOV        AL,DL
    //         00410efd     CMP        DL,byte ptr [EDI + 0x1]=>DAT_0057f60d            = 54h
    //                                                                                  = "igger"
    //         00410f00     JNZ        LAB_00410f10
    //         00410f02     ADD        ESI,0x2
    //         00410f05     ADD        EDI,0x2
    //         00410f08     TEST       AL,AL
    //         00410f0a     JNZ        LAB_00410eec
    //                               LAB_00410f0c                                                 XREF[1]:     00410ef6(j)  
    //         00410f0c     XOR        EAX,EAX
    //         00410f0e     JMP        LAB_00410f15
    //                               LAB_00410f10                                                 XREF[2]:     00410ef2(j), 00410f00(j)  
    //         00410f10     SBB        EAX,EAX
    //         00410f12     SBB        EAX,-0x1
    //                               LAB_00410f15                                                 XREF[1]:     00410f0e(j)  
    //         00410f15     TEST       EAX,EAX
    //         00410f17     JNZ        LAB_00410fb8
    //         00410f1d     CMP        EBP,-0x1
    //         00410f20     JZ         LAB_00410fb8
    //         00410f26     CMP        this,-0x1
    //         00410f29     JZ         LAB_00410fb8
    //                              aipbook.cpp:1197 (46)
    //         00410f2f     LEA        EAX=>fileIn,[ESP + 0x44]
    //         00410f33     LEA        this=>temp7,[ESP + 0x40]
    //         00410f37     PUSH       EAX
    //         00410f38     LEA        EDX=>Stack[-0x3b0],[ESP + 0x18]
    //         00410f3c     PUSH       this
    //         00410f3d     LEA        EAX=>temp6[4],[ESP + 0x2c0]
    //         00410f44     PUSH       EDX
    //         00410f45     LEA        this=>temp4,[ESP + 0x1c]
    //         00410f49     PUSH       EAX
    //         00410f4a     PUSH       this
    //         00410f4b     LEA        EDX=>temp[4],[ESP + 0x1a4]
    //         00410f52     PUSH       s_%*s_%d_%s_%d_%d_%d_                            = "%*s %d %s %d %d %d "
    //         00410f57     PUSH       EDX
    //         00410f58     CALL       sscanf                                           undefined sscanf()
    //                              aipbook.cpp:1198 (28)
    //         00410f5d     MOV        this,dword ptr [EBX + 0x4c]
    //         00410f60     MOV        EDI,dword ptr [ESP + Stack[-0x3a8]]
    //         00410f64     LEA        EAX,[EBP + EBP*0x2]
    //         00410f68     ADD        ESP,0x1c
    //         00410f6b     SHL        EAX,0x6
    //         00410f6e     ADD        EAX,EBP
    //         00410f70     PUSH       EDI
    //         00410f71     LEA        this,[this->_padding_ + EAX*0x8]
    //         00410f74     CALL       AIPlay::phase                                    AIPlayPhase * phase(AIPlay * this, int param_1)
    //                              aipbook.cpp:1199 (43)
    //         00410f79     MOV        EDX,dword ptr [ESP + fileIn]
    //         00410f7d     MOV        this,dword ptr [ESP + temp7]
    //         00410f81     MOV        ESI,EAX
    //         00410f83     MOV        EAX,dword ptr [ESP + temp4]
    //         00410f87     PUSH       EDX
    //         00410f88     MOV        EDX,dword ptr [ESP + Stack[-0x3b0]]
    //         00410f8c     PUSH       EAX
    //         00410f8d     PUSH       EDI
    //         00410f8e     PUSH       this
    //         00410f8f     LEA        EAX=>temp6[4],[ESP + 0x2c8]
    //         00410f96     PUSH       EDX
    //         00410f97     PUSH       EAX
    //         00410f98     LEA        this=>trigger@fffffedc.value1Value,[ESP + 0x2bc]
    //         00410f9f     CALL       AIPlayPhaseTrigger::AIPlayPhaseTrigger           undefined AIPlayPhaseTrigger(AIPlayPhaseTrigg
    //                              aipbook.cpp:1200 (15)
    //         00410fa4     LEA        this=>trigger@fffffedc.value1Value,[ESP + 0x2a4]
    //         00410fab     PUSH       this
    //         00410fac     MOV        this,ESI
    //         00410fae     CALL       AIPlayPhase::addTrigger                          int addTrigger(AIPlayPhase * this, AIPlayPhas
    //                              aipbook.cpp:1201 (5)
    //         00410fb3     JMP        LAB_004112c5
    //                               LAB_00410fb8                                                 XREF[3]:     00410f17(j), 00410f20(j), 
    //                                                                                                         00410f29(j)  
    //                              aipbook.cpp:1206 (71)
    //         00410fb8     MOV        EDI,s_EndPlay                                    = 45h
    //         00410fbd     LEA        ESI=>temp2[4],[ESP + 0x70]
    //                               LAB_00410fc1                                                 XREF[1]:     00410fe3(j)  
    //         00410fc1     MOV        DL,byte ptr [ESI]=>temp2[4]
    //         00410fc3     MOV        this,byte ptr [EDI]=>s_EndPlay                   = 45h
    //                                                                                  = 64h
    //         00410fc5     MOV        AL,DL
    //         00410fc7     CMP        DL,this
    //         00410fc9     JNZ        LAB_00410fe9
    //         00410fcb     TEST       AL,AL
    //         00410fcd     JZ         LAB_00410fe5
    //         00410fcf     MOV        this,byte ptr [ESI + temp2[5]]
    //         00410fd2     MOV        DL,byte ptr [EDI + 0x1]=>DAT_0057f605            = 6Eh
    //                                                                                  = 50h
    //         00410fd5     MOV        AL,this
    //         00410fd7     CMP        this,DL
    //         00410fd9     JNZ        LAB_00410fe9
    //         00410fdb     ADD        ESI,0x2
    //         00410fde     ADD        EDI,0x2
    //         00410fe1     TEST       AL,AL
    //         00410fe3     JNZ        LAB_00410fc1
    //                               LAB_00410fe5                                                 XREF[1]:     00410fcd(j)  
    //         00410fe5     XOR        EAX,EAX
    //         00410fe7     JMP        LAB_00410fee
    //                               LAB_00410fe9                                                 XREF[2]:     00410fc9(j), 00410fd9(j)  
    //         00410fe9     SBB        EAX,EAX
    //         00410feb     SBB        EAX,-0x1
    //                               LAB_00410fee                                                 XREF[1]:     00410fe7(j)  
    //         00410fee     TEST       EAX,EAX
    //         00410ff0     JNZ        LAB_004112c5
    //         00410ff6     CMP        EBP,-0x1
    //         00410ff9     JZ         LAB_004112c5
    //                              aipbook.cpp:1212 (63)
    //         00410fff     MOV        EDX,dword ptr [ESP + refPhase]
    //         00411003     MOV        ESI,dword ptr [EBX + 0x4c]
    //         00411006     OR         this,0xffffffff
    //         00411009     LEA        EBP,[EDX + EDX*0x2]
    //         0041100c     MOV        dword ptr [ESP + Stack[-0x3a8]],this
    //         00411010     SHL        EBP,0x6
    //         00411013     ADD        EBP,EDX
    //         00411015     SHL        EBP,0x3
    //         00411018     MOV        EDI,EBP
    //         0041101a     ADD        EDI,ESI
    //         0041101c     LEA        ESI=>temp2[4],[ESP + 0x70]
    //         00411020     SCASB.RE   ES:EDI
    //         00411022     NOT        this
    //         00411024     SUB        EDI,this
    //         00411026     MOV        dword ptr [ESP + temp5],ESI
    //         0041102a     MOV        EAX,this
    //         0041102c     MOV        ESI,EDI
    //         0041102e     MOV        EDI,dword ptr [ESP + temp5]
    //         00411032     SHR        this,0x2
    //         00411035     MOVSD.REP  ES:EDI,ESI
    //         00411037     MOV        this,EAX
    //         00411039     AND        this,0x3
    //         0041103c     MOVSB.REP  ES:EDI,ESI
    //                              aipbook.cpp:1213 (14)
    //         0041103e     CMP        byte ptr [ESP + temp2[4]],0x48
    //         00411043     JNZ        LAB_00411055
    //         00411045     CMP        byte ptr [ESP + temp2[5]],0x50
    //         0041104a     JNZ        LAB_00411055
    //                              aipbook.cpp:1214 (4)
    //         0041104c     ADD        dword ptr [EBX + 0x4],-0x7
    //                              aipbook.cpp:1215 (5)
    //         00411050     JMP        LAB_004112c1
    //                               LAB_00411055                                                 XREF[2]:     00411043(j), 0041104a(j)  
    //                              aipbook.cpp:1219 (3)
    //         00411055     ADD        EDX,0x7
    //                              aipbook.cpp:1220 (14)
    //         00411058     MOV        dword ptr [ESP + temp8],0x1
    //         00411060     MOV        ESI,EBP
    //         00411062     MOV        dword ptr [ESP + refPhase],EDX
    //                               LAB_00411066                                                 XREF[1]:     004112bb(j)  
    //                              aipbook.cpp:1222 (28)
    //         00411066     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00411069     MOV        this,dword ptr [ESP + temp8]
    //         0041106d     MOV        EDX,EBP
    //         0041106f     PUSH       this
    //         00411070     ADD        EDX,EAX
    //         00411072     LEA        EAX=>temp2[4],[ESP + 0x74]
    //         00411076     PUSH       EDX
    //         00411077     PUSH       s_%sF%d                                          = "%sF%d"
    //         0041107c     PUSH       EAX
    //         0041107d     CALL       sprintf                                          undefined sprintf()
    //                              aipbook.cpp:1224 (26)
    //         00411082     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00411085     ADD        ESP,0x10
    //         00411088     LEA        this=>temp2[4],[ESP + 0x70]
    //         0041108c     ADD        ESI,0x608
    //         00411092     PUSH       this
    //         00411093     MOV        this,ESI
    //         00411095     ADD        this,EAX
    //         00411097     CALL       AIPlay::setName                                  void setName(AIPlay * this, char * param_1)
    //                              aipbook.cpp:1226 (3)
    //         0041109c     MOV        EAX,dword ptr [EBX + 0x4c]
    //                              aipbook.cpp:1239 (76)
    //         0041109f     XOR        EDI,EDI
    //         004110a1     MOV        this,byte ptr [EBP + EAX*0x1 + 0x43]
    //         004110a5     MOV        byte ptr [ESI + EAX*0x1 + 0x43],this
    //         004110a9     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004110ac     MOV        this,byte ptr [EBP + EAX*0x1 + 0x41]
    //         004110b0     MOV        byte ptr [ESI + EAX*0x1 + 0x41],this
    //         004110b4     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004110b7     MOV        this,byte ptr [EBP + EAX*0x1 + 0x42]
    //         004110bb     MOV        byte ptr [ESI + EAX*0x1 + 0x42],this
    //         004110bf     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004110c2     MOV        this,byte ptr [EBP + EAX*0x1 + 0x4e]
    //         004110c6     MOV        byte ptr [ESI + EAX*0x1 + 0x4e],this
    //         004110ca     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004110cd     MOV        this,byte ptr [EBP + EAX*0x1 + 0x4f]
    //         004110d1     MOV        byte ptr [ESI + EAX*0x1 + 0x4f],this
    //         004110d5     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004110d8     MOV        this,byte ptr [EBP + EAX*0x1 + 0x51]
    //         004110dc     MOV        byte ptr [ESI + EAX*0x1 + 0x51],this
    //         004110e0     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004110e3     MOV        this,byte ptr [EBP + EAX*0x1 + 0x50]
    //         004110e7     MOV        byte ptr [ESI + EAX*0x1 + 0x50],this
    //                               LAB_004110eb                                                 XREF[1]:     00411123(j)  
    //                              aipbook.cpp:1240 (26)
    //         004110eb     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004110ee     MOV        this,EBP
    //         004110f0     PUSH       EDI
    //         004110f1     ADD        this,EDX
    //         004110f3     CALL       AIPlay::targetType                               uchar targetType(AIPlay * this, int param_1)
    //         004110f8     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004110fb     MOV        this,ESI
    //         004110fd     PUSH       EAX
    //         004110fe     ADD        this,EDX
    //         00411100     CALL       AIPlay::addTargetType                            int addTargetType(AIPlay * this, uchar param_1)
    //                              aipbook.cpp:1241 (32)
    //         00411105     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00411108     MOV        this,EBP
    //         0041110a     PUSH       EDI
    //         0041110b     ADD        this,EDX
    //         0041110d     CALL       AIPlay::targetCharacteristic                     uchar targetCharacteristic(AIPlay * this, int
    //         00411112     MOV        EDX,dword ptr [EBX + 0x4c]
    //         00411115     MOV        this,ESI
    //         00411117     PUSH       EAX
    //         00411118     ADD        this,EDX
    //         0041111a     CALL       AIPlay::addTargetCharacteristic                  int addTargetCharacteristic(AIPlay * this, uc
    //         0041111f     INC        EDI
    //         00411120     CMP        EDI,0x5
    //         00411123     JL         LAB_004110eb
    //                              aipbook.cpp:1244 (3)
    //         00411125     MOV        EAX,dword ptr [EBX + 0x4c]
    //                              aipbook.cpp:1246 (16)
    //         00411128     MOV        dword ptr [ESP + curPhase],0x0
    //         00411130     MOV        this,byte ptr [EBP + EAX*0x1 + 0x52]
    //         00411134     MOV        byte ptr [ESI + EAX*0x1 + 0x52],this
    //                               LAB_00411138                                                 XREF[1]:     004111a6(j)  
    //                              aipbook.cpp:1247 (21)
    //         00411138     MOV        EDI,dword ptr [ESP + curPhase]
    //         0041113c     MOV        EDX,dword ptr [EBX + 0x4c]
    //         0041113f     MOV        this,EBP
    //         00411141     PUSH       EDI
    //         00411142     ADD        this,EDX
    //         00411144     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //         00411149     MOV        dword ptr [ESP + a],EAX
    //                              aipbook.cpp:1248 (17)
    //         0041114d     MOV        EAX,dword ptr [EBX + 0x4c]
    //         00411150     MOV        this,ESI
    //         00411152     PUSH       EDI
    //         00411153     ADD        this,EAX
    //         00411155     CALL       AIPlay::group                                    AIPlayGroup * group(AIPlay * this, int param_1)
    //         0041115a     MOV        dword ptr [ESP + currentPlay],EAX
    //                              aipbook.cpp:1249 (2)
    //         0041115e     XOR        EDI,EDI
    //                               LAB_00411160                                                 XREF[1]:     00411198(j)  
    //                              aipbook.cpp:1250 (26)
    //         00411160     MOV        this,dword ptr [ESP + a]
    //         00411164     PUSH       EDI
    //         00411165     CALL       AIPlayGroup::minimum                             uchar minimum(AIPlayGroup * this, int param_1)
    //         0041116a     MOV        this,dword ptr [ESP + currentPlay]
    //         0041116e     AND        EAX,0xff
    //         00411173     PUSH       EAX
    //         00411174     PUSH       EDI
    //         00411175     CALL       AIPlayGroup::setMinimum                          void setMinimum(AIPlayGroup * this, int param
    //                              aipbook.cpp:1251 (46)
    //         0041117a     MOV        this,dword ptr [ESP + a]
    //         0041117e     PUSH       EDI
    //         0041117f     CALL       AIPlayGroup::maximum                             uchar maximum(AIPlayGroup * this, int param_1)
    //         00411184     MOV        this,dword ptr [ESP + currentPlay]
    //         00411188     AND        EAX,0xff
    //         0041118d     PUSH       EAX
    //         0041118e     PUSH       EDI
    //         0041118f     CALL       AIPlayGroup::setMaximum                          void setMaximum(AIPlayGroup * this, int param
    //         00411194     INC        EDI
    //         00411195     CMP        EDI,0x6
    //         00411198     JL         LAB_00411160
    //         0041119a     MOV        EAX,dword ptr [ESP + curPhase]
    //         0041119e     INC        EAX
    //         0041119f     CMP        EAX,0x5
    //         004111a2     MOV        dword ptr [ESP + curPhase],EAX
    //         004111a6     JL         LAB_00411138
    //                              aipbook.cpp:1255 (8)
    //         004111a8     MOV        dword ptr [ESP + curPhase],0x0
    //                               LAB_004111b0                                                 XREF[1]:     004112a9(j)  
    //                              aipbook.cpp:1256 (21)
    //         004111b0     MOV        EDI,dword ptr [ESP + curPhase]
    //         004111b4     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004111b7     MOV        this,EBP
    //         004111b9     PUSH       EDI
    //         004111ba     ADD        this,EDX
    //         004111bc     CALL       AIPlay::phase                                    AIPlayPhase * phase(AIPlay * this, int param_1)
    //         004111c1     MOV        dword ptr [ESP + temp5],EAX
    //                              aipbook.cpp:1257 (17)
    //         004111c5     MOV        EAX,dword ptr [EBX + 0x4c]
    //         004111c8     MOV        this,ESI
    //         004111ca     PUSH       EDI
    //         004111cb     ADD        this,EAX
    //         004111cd     CALL       AIPlay::phase                                    AIPlayPhase * phase(AIPlay * this, int param_1)
    //         004111d2     MOV        dword ptr [ESP + a],EAX
    //                              aipbook.cpp:1258 (8)
    //         004111d6     MOV        dword ptr [ESP + currentPlay],0x0
    //                               LAB_004111de                                                 XREF[1]:     0041127b(j)  
    //                              aipbook.cpp:1259 (16)
    //         004111de     MOV        EDX,dword ptr [ESP + currentPlay]
    //         004111e2     MOV        this,dword ptr [ESP + temp5]
    //         004111e6     PUSH       EDX
    //         004111e7     CALL       AIPlayPhase::command                             AIPlayPhaseCommand * command(AIPlayPhase * th
    //         004111ec     MOV        EDI,EAX
    //                              aipbook.cpp:1262 (6)
    //         004111ee     CMP        byte ptr [EDI + 0x1],0x1
    //         004111f2     JZ         LAB_004111f7
    //                              aipbook.cpp:1263 (1)
    //         004111f4     PUSH       EDI
    //                              aipbook.cpp:1266 (2)
    //         004111f5     JMP        LAB_00411266
    //                               LAB_004111f7                                                 XREF[1]:     004111f2(j)  
    //                              aipbook.cpp:1267 (15)
    //         004111f7     PUSH       0x0
    //         004111f9     PUSH       0x0
    //         004111fb     PUSH       0x0
    //         004111fd     LEA        this=>origin.yValue,[ESP + 0x70]
    //         00411201     CALL       XYZ::XYZ                                         undefined XYZ(XYZ * this, int param_1, int pa
    //                              aipbook.cpp:1268 (9)
    //         00411206     LEA        this=>rotatedPoint.yValue,[ESP + 0x4c]
    //         0041120a     CALL       XYZ::XYZ                                         undefined XYZ(XYZ * this)
    //                              aipbook.cpp:1269 (21)
    //         0041120f     MOV        EAX,dword ptr [EDI + 0xc]
    //         00411212     MOV        this,dword ptr [EDI + 0x8]
    //         00411215     MOV        EDX,dword ptr [EDI + 0x4]
    //         00411218     PUSH       EAX
    //         00411219     PUSH       this
    //         0041121a     PUSH       EDX
    //         0041121b     LEA        this=>originalPoint.yValue,[ESP + 0x64]
    //         0041121f     CALL       XYZ::XYZ                                         undefined XYZ(XYZ * this, int param_1, int pa
    //                              aipbook.cpp:1270 (24)
    //         00411224     MOV        EAX,dword ptr [ESP + temp8]
    //         00411228     LEA        this=>rotatedPoint.yValue,[ESP + 0x4c]
    //         0041122c     PUSH       EAX
    //         0041122d     LEA        EDX=>origin.yValue,[ESP + 0x68]
    //         00411231     PUSH       this
    //         00411232     PUSH       EDX
    //         00411233     LEA        this=>originalPoint.yValue,[ESP + 0x64]
    //         00411237     CALL       XYZ::rotateXYByFacet                             void rotateXYByFacet(XYZ * this, XYZ * param_
    //                              aipbook.cpp:1273 (34)
    //         0041123c     MOV        EAX,dword ptr [ESP + originalPoint.xValue]
    //         00411240     MOV        this,dword ptr [ESP + rotatedPoint.zValue]
    //         00411244     MOV        EDX,dword ptr [ESP + rotatedPoint.yValue]
    //         00411248     PUSH       EAX
    //         00411249     MOV        AL,byte ptr [EDI + 0x1]
    //         0041124c     PUSH       this
    //         0041124d     MOV        this,byte ptr [EDI]
    //         0041124f     PUSH       EDX
    //         00411250     PUSH       EAX
    //         00411251     PUSH       this
    //         00411252     LEA        this=>newCommand.value1Value,[ESP + 0x194]
    //         00411259     CALL       AIPlayPhaseCommand::AIPlayPhaseCommand           undefined AIPlayPhaseCommand(AIPlayPhaseComma
    //                              aipbook.cpp:1274 (35)
    //         0041125e     LEA        EDX=>newCommand.value1Value,[ESP + 0x180]
    //         00411265     PUSH       EDX
    //                               LAB_00411266                                                 XREF[1]:     004111f5(j)  
    //         00411266     MOV        this,dword ptr [ESP + a]
    //         0041126a     CALL       AIPlayPhase::addCommand                          int addCommand(AIPlayPhase * this, AIPlayPhas
    //         0041126f     MOV        EAX,dword ptr [ESP + currentPlay]
    //         00411273     INC        EAX
    //         00411274     CMP        EAX,0x5
    //         00411277     MOV        dword ptr [ESP + currentPlay],EAX
    //         0041127b     JL         LAB_004111de
    //                              aipbook.cpp:1277 (2)
    //         00411281     XOR        EDI,EDI
    //                               LAB_00411283                                                 XREF[1]:     0041129b(j)  
    //                              aipbook.cpp:1278 (10)
    //         00411283     MOV        this,dword ptr [ESP + temp5]
    //         00411287     PUSH       EDI
    //         00411288     CALL       AIPlayPhase::trigger                             AIPlayPhaseTrigger * trigger(AIPlayPhase * th
    //                              aipbook.cpp:1279 (52)
    //         0041128d     MOV        this,dword ptr [ESP + a]
    //         00411291     PUSH       EAX
    //         00411292     CALL       AIPlayPhase::addTrigger                          int addTrigger(AIPlayPhase * this, AIPlayPhas
    //         00411297     INC        EDI
    //         00411298     CMP        EDI,0x3
    //         0041129b     JL         LAB_00411283
    //         0041129d     MOV        EAX,dword ptr [ESP + curPhase]
    //         004112a1     INC        EAX
    //         004112a2     CMP        EAX,0xa
    //         004112a5     MOV        dword ptr [ESP + curPhase],EAX
    //         004112a9     JL         LAB_004111b0
    //         004112af     MOV        EAX,dword ptr [ESP + temp8]
    //         004112b3     INC        EAX
    //         004112b4     CMP        EAX,0x8
    //         004112b7     MOV        dword ptr [ESP + temp8],EAX
    //         004112bb     JL         LAB_00411066
    //                               LAB_004112c1                                                 XREF[1]:     00411050(j)  
    //                              aipbook.cpp:1220 (4)
    //         004112c1     MOV        EBP,dword ptr [ESP + refPhase]
    //                               LAB_004112c5                                                 XREF[34]:    0041044b(j), 004104d6(j), 
    //                                                                                                         004104e8(j), 004105dc(j), 
    //                                                                                                         00410658(j), 004106cc(j), 
    //                                                                                                         00410740(j), 004107b4(j), 
    //                                                                                                         00410867(j), 004108a4(j), 
    //                                                                                                         004108bd(j), 00410936(j), 
    //                                                                                                         00410953(j), 00410966(j), 
    //                                                                                                         004109df(j), 004109fc(j), 
    //                                                                                                         00410a0f(j), 00410a81(j), 
    //                                                                                                         00410a9c(j), 00410b0e(j), [more]
    //                              aipbook.cpp:1010 (12)
    //         004112c5     CMP        EBP,0x3e80
    //         004112cb     JL         LAB_00410418
    //                               LAB_004112d1                                                 XREF[2]:     00410434(j), 004105bd(j)  
    //                              aipbook.cpp:1288 (13)
    //         004112d1     MOV        EAX,dword ptr [ESP + rotatedPoint.xValue]
    //         004112d5     PUSH       EAX
    //         004112d6     CALL       fclose                                           undefined fclose()
    //         004112db     ADD        ESP,0x4
    //                              aipbook.cpp:1289 (7)
    //         004112de     MOV        EAX,0x1
    //         004112e3     JMP        LAB_0041131a
    //                               LAB_004112e5                                                 XREF[1]:     00410286(j)  
    //                              aipbook.cpp:960 (4)
    //         004112e5     TEST       EBP,EBP
    //         004112e7     JNZ        LAB_004112f3
    //                               LAB_004112e9                                                 XREF[1]:     0041024a(j)  
    //                              aipbook.cpp:961 (8)
    //         004112e9     LEA        EDX,[EBX + 0x8]
    //         004112ec     MOV        EDI,s_NULL                                       = 4Eh
    //                              aipbook.cpp:962 (2)
    //         004112f1     JMP        LAB_004112fb
    //                               LAB_004112f3                                                 XREF[1]:     004112e7(j)  
    //                              aipbook.cpp:963 (37)
    //         004112f3     LEA        EDX,[EBX + 0x8]
    //         004112f6     MOV        EDI,s_NONE                                       = 4Eh
    //                               LAB_004112fb                                                 XREF[1]:     004112f1(j)  
    //         004112fb     OR         this,0xffffffff
    //         004112fe     XOR        EAX,EAX
    //         00411300     SCASB.RE   ES:EDI=>s_NULL                                   = 4Eh
    //                                                                                  = 55h
    //         00411302     NOT        this
    //         00411304     SUB        EDI,this
    //         00411306     MOV        EAX,this
    //         00411308     MOV        ESI,EDI
    //         0041130a     MOV        EDI,EDX
    //         0041130c     SHR        this,0x2
    //         0041130f     MOVSD.REP  ES:EDI,ESI
    //         00411311     MOV        this,EAX
    //         00411313     AND        this,0x3
    //         00411316     MOVSB.REP  ES:EDI,ESI
    //                               LAB_00411318                                                 XREF[2]:     004102d0(j), 004103fa(j)  
    //                              aipbook.cpp:964 (2)
    //         00411318     XOR        EAX,EAX
    //                               LAB_0041131a                                                 XREF[1]:     004112e3(j)  
    //                              aipbook.cpp:1290 (27)
    //         0041131a     MOV        this,dword ptr [ESP + local_c]
    //         00411321     POP        EDI
    //         00411322     POP        ESI
    //         00411323     POP        EBP
    //         00411324     MOV        dword ptr FS:[0x0],this
    //         0041132b     POP        EBX
    //         0041132c     ADD        ESP,0x3b4
    //         00411332     RET        0x4
}

// Offset: 0x00411340
AIPlay* play(AIPlayBook* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIPlay * __thiscall AIPlayBook::play(int)                                               *
    //                              *********************************************************************************************************
    //                              AIPlay * __thiscall play(AIPlayBook * this, int param_1)
    //              AIPlay *          EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00411347(R)  
    //                               ?play@AIPlayBook@@QAEPAVAIPlay@@H@Z                          XREF[8]:     fillGroups:0040f559(c), 
    //                               AIPlayBook::play                                                          updateGroup:00414070(c), 
    //                                                                                                         selectNewPlayPhase:00414837(c), 
    //                                                                                                         processOrder:00417ba4(c), 
    //                                                                                                         processGroupNotify:00419538(c), 
    //                                                                                                         sendPlayCommand:0046f077(c), 
    //                                                                                                         sendPlayCommand:0046f161(c), 
    //                                                                                                         objectToAttackWithPlay:004dc526(c)
    //                              aipbook.cpp:1295 (20)
    //         00411340     MOV        EDX,dword ptr [ECX + this->plays]
    //         00411343     TEST       EDX,EDX
    //         00411345     JZ         LAB_00411362
    //         00411347     MOV        EAX,dword ptr [ESP + param_1]
    //         0041134b     TEST       EAX,EAX
    //         0041134d     JL         LAB_00411362
    //         0041134f     CMP        EAX,dword ptr [ECX + this->numberPlaysValue]
    //         00411352     JGE        LAB_00411362
    //                              aipbook.cpp:1297 (11)
    //         00411354     LEA        this,[EAX + EAX*0x2]
    //         00411357     SHL        this,0x6
    //         0041135a     ADD        this,EAX
    //         0041135c     LEA        EAX,[EDX + this->_padding_*0x8]
    //                              aipbook.cpp:1299 (3)
    //         0041135f     RET        0x4
    //                               LAB_00411362                                                 XREF[3]:     00411345(j), 0041134d(j), 
    //                                                                                                         00411352(j)  
    //                              aipbook.cpp:1298 (2)
    //         00411362     XOR        EAX,EAX
    //                              aipbook.cpp:1299 (3)
    //         00411364     RET        0x4
}

// Offset: 0x00411370
AIPlay* play(AIPlayBook* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIPlay * __thiscall AIPlayBook::play(char *)                                            *
    //                              *********************************************************************************************************
    //                              AIPlay * __thiscall play(AIPlayBook * this, char * param_1)
    //              AIPlay *          EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00411389(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041137a(W), 004113d1(R)  
    //                               ?play@AIPlayBook@@QAEPAVAIPlay@@PAD@Z
    //                               AIPlayBook::play
    //                              aipbook.cpp:1304 (5)
    //         00411370     PUSH       this
    //         00411371     PUSH       EBX
    //         00411372     PUSH       EBP
    //         00411373     PUSH       ESI
    //         00411374     PUSH       EDI
    //                              aipbook.cpp:1305 (9)
    //         00411375     MOV        EDI,dword ptr [ECX + this->plays]
    //         00411378     TEST       EDI,EDI
    //         0041137a     MOV        dword ptr [ESP + local_4],EDI
    //                              aipbook.cpp:1306 (2)
    //         0041137e     JZ         LAB_004113e9
    //                              aipbook.cpp:1308 (9)
    //         00411380     MOV        EDX,dword ptr [ECX + this->numberPlaysValue]
    //         00411383     XOR        EBP,EBP
    //         00411385     TEST       EDX,EDX
    //         00411387     JLE        LAB_004113e9
    //                               LAB_00411389                                                 XREF[1]:     004113c5(j)  
    //                              aipbook.cpp:1309 (62)
    //         00411389     MOV        ESI,dword ptr [ESP + param_1]
    //         0041138d     MOV        EAX,EDI
    //                               LAB_0041138f                                                 XREF[1]:     004113ad(j)  
    //         0041138f     MOV        BL,byte ptr [EAX]
    //         00411391     MOV        this,BL
    //         00411393     CMP        BL,byte ptr [ESI]
    //         00411395     JNZ        LAB_004113b3
    //         00411397     TEST       this,this
    //         00411399     JZ         LAB_004113af
    //         0041139b     MOV        BL,byte ptr [EAX + 0x1]
    //         0041139e     MOV        this,BL
    //         004113a0     CMP        BL,byte ptr [ESI + 0x1]
    //         004113a3     JNZ        LAB_004113b3
    //         004113a5     ADD        EAX,0x2
    //         004113a8     ADD        ESI,0x2
    //         004113ab     TEST       this,this
    //         004113ad     JNZ        LAB_0041138f
    //                               LAB_004113af                                                 XREF[1]:     00411399(j)  
    //         004113af     XOR        EAX,EAX
    //         004113b1     JMP        LAB_004113b8
    //                               LAB_004113b3                                                 XREF[2]:     00411395(j), 004113a3(j)  
    //         004113b3     SBB        EAX,EAX
    //         004113b5     SBB        EAX,-0x1
    //                               LAB_004113b8                                                 XREF[1]:     004113b1(j)  
    //         004113b8     TEST       EAX,EAX
    //         004113ba     JZ         LAB_004113d1
    //         004113bc     INC        EBP
    //         004113bd     ADD        EDI,0x608
    //         004113c3     CMP        EBP,EDX
    //         004113c5     JL         LAB_00411389
    //                              aipbook.cpp:1311 (2)
    //         004113c7     XOR        EAX,EAX
    //                              aipbook.cpp:1312 (8)
    //         004113c9     POP        EDI
    //         004113ca     POP        ESI
    //         004113cb     POP        EBP
    //         004113cc     POP        EBX
    //         004113cd     POP        this
    //         004113ce     RET        0x4
    //                               LAB_004113d1                                                 XREF[1]:     004113ba(j)  
    //                              aipbook.cpp:1310 (16)
    //         004113d1     MOV        this,dword ptr [ESP + local_4]
    //         004113d5     LEA        EAX,[EBP + EBP*0x2]
    //         004113d9     SHL        EAX,0x6
    //         004113dc     ADD        EAX,EBP
    //         004113de     LEA        EAX,[this->_padding_ + EAX*0x8]
    //                              aipbook.cpp:1312 (18)
    //         004113e1     POP        EDI
    //         004113e2     POP        ESI
    //         004113e3     POP        EBP
    //         004113e4     POP        EBX
    //         004113e5     POP        this
    //         004113e6     RET        0x4
    //                               LAB_004113e9                                                 XREF[2]:     0041137e(j), 00411387(j)  
    //         004113e9     POP        EDI
    //         004113ea     POP        ESI
    //         004113eb     POP        EBP
    //         004113ec     XOR        EAX,EAX
    //         004113ee     POP        EBX
    //         004113ef     POP        this
    //         004113f0     RET        0x4
}

// Offset: 0x00411400
int playNumber(AIPlayBook* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIPlayBook::playNumber(char *)                                                 *
    //                              *********************************************************************************************************
    //                              int __thiscall playNumber(AIPlayBook * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00411416(R)  
    //                               ?playNumber@AIPlayBook@@QAEHPAD@Z                            XREF[1]:     processCheatCode:005285b0(c)  
    //                               AIPlayBook::playNumber
    //                              aipbook.cpp:1317 (9)
    //         00411400     MOV        EDX,dword ptr [ECX + this->plays]
    //         00411403     PUSH       EBX
    //         00411404     PUSH       EBP
    //         00411405     PUSH       ESI
    //         00411406     TEST       EDX,EDX
    //         00411408     PUSH       EDI
    //                              aipbook.cpp:1319 (2)
    //         00411409     JZ         LAB_00411467
    //                              aipbook.cpp:1321 (9)
    //         0041140b     MOV        EAX,dword ptr [ECX + this->numberPlaysValue]
    //         0041140e     XOR        EBP,EBP
    //         00411410     TEST       EAX,EAX
    //         00411412     JLE        LAB_00411467
    //                              aipbook.cpp:1325 (2)
    //         00411414     MOV        EDI,EDX
    //                               LAB_00411416                                                 XREF[1]:     00411452(j)  
    //                              aipbook.cpp:1322 (62)
    //         00411416     MOV        ESI,dword ptr [ESP + param_1]
    //         0041141a     MOV        this,EDI
    //                               LAB_0041141c                                                 XREF[1]:     0041143a(j)  
    //         0041141c     MOV        BL,byte ptr [this->_padding_]
    //         0041141e     MOV        DL,BL
    //         00411420     CMP        BL,byte ptr [ESI]
    //         00411422     JNZ        LAB_00411440
    //         00411424     TEST       DL,DL
    //         00411426     JZ         LAB_0041143c
    //         00411428     MOV        BL,byte ptr [ECX + this+0x1]
    //         0041142b     MOV        DL,BL
    //         0041142d     CMP        BL,byte ptr [ESI + 0x1]
    //         00411430     JNZ        LAB_00411440
    //         00411432     ADD        this,0x2
    //         00411435     ADD        ESI,0x2
    //         00411438     TEST       DL,DL
    //         0041143a     JNZ        LAB_0041141c
    //                               LAB_0041143c                                                 XREF[1]:     00411426(j)  
    //         0041143c     XOR        this,this
    //         0041143e     JMP        LAB_00411445
    //                               LAB_00411440                                                 XREF[2]:     00411422(j), 00411430(j)  
    //         00411440     SBB        this,this
    //         00411442     SBB        this,-0x1
    //                               LAB_00411445                                                 XREF[1]:     0041143e(j)  
    //         00411445     TEST       this,this
    //         00411447     JZ         LAB_0041145e
    //         00411449     INC        EBP
    //         0041144a     ADD        EDI,0x608
    //         00411450     CMP        EBP,EAX
    //         00411452     JL         LAB_00411416
    //                              aipbook.cpp:1324 (3)
    //         00411454     OR         EAX,0xffffffff
    //                              aipbook.cpp:1325 (7)
    //         00411457     POP        EDI
    //         00411458     POP        ESI
    //         00411459     POP        EBP
    //         0041145a     POP        EBX
    //         0041145b     RET        0x4
    //                               LAB_0041145e                                                 XREF[1]:     00411447(j)  
    //                              aipbook.cpp:1323 (2)
    //         0041145e     MOV        EAX,EBP
    //                              aipbook.cpp:1325 (17)
    //         00411460     POP        EDI
    //         00411461     POP        ESI
    //         00411462     POP        EBP
    //         00411463     POP        EBX
    //         00411464     RET        0x4
    //                               LAB_00411467                                                 XREF[2]:     00411409(j), 00411412(j)  
    //         00411467     POP        EDI
    //         00411468     POP        ESI
    //         00411469     POP        EBP
    //         0041146a     OR         EAX,0xffffffff
    //         0041146d     POP        EBX
    //         0041146e     RET        0x4
}

// Offset: 0x00411480
int AIPlayBook::convertTargetNameToIntType(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIPlayBook::convertTargetNameToIntType(char *)const                    *
    //                              *********************************************************************************************************
    //                              int __thiscall convertTargetNameToIntType(AIPlayBook * this, char * 
    //              int               EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00411480(R)  
    //                               ?convertTargetNameToIntType@AIPlayBook@@UBEHPAD@Z            XREF[2]:     convertTargetNameToIntType:004e690
    //                               AIPlayBook::convertTargetNameToIntType                                    0056e974(*)  
    //                              aipbook.cpp:1330 (58)
    //         00411480     MOV        EAX,dword ptr [ESP + param_1]
    //         00411484     PUSH       EBX
    //         00411485     PUSH       ESI
    //         00411486     MOV        ESI,s_Any                                        = 41h
    //                               LAB_0041148b                                                 XREF[1]:     004114ad(j)  
    //         0041148b     MOV        DL,byte ptr [EAX]
    //         0041148d     MOV        BL,byte ptr [ESI]=>s_Any                         = 41h
    //                                                                                  = 79h
    //         0041148f     MOV        this,DL
    //         00411491     CMP        DL,BL
    //         00411493     JNZ        LAB_004114bf
    //         00411495     TEST       this,this
    //         00411497     JZ         LAB_004114af
    //         00411499     MOV        DL,byte ptr [EAX + 0x1]
    //         0041149c     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f71d            = 6Eh
    //         0041149f     MOV        this,DL
    //         004114a1     CMP        DL,BL
    //         004114a3     JNZ        LAB_004114bf
    //         004114a5     ADD        EAX,0x2
    //         004114a8     ADD        ESI,0x2
    //         004114ab     TEST       this,this
    //         004114ad     JNZ        LAB_0041148b
    //                               LAB_004114af                                                 XREF[1]:     00411497(j)  
    //         004114af     XOR        EAX,EAX
    //         004114b1     NEG        EAX
    //         004114b3     SBB        EAX,EAX
    //         004114b5     AND        AL,0xfb
    //         004114b7     ADD        EAX,0x5
    //                              aipbook.cpp:1334 (5)
    //         004114ba     POP        ESI
    //         004114bb     POP        EBX
    //         004114bc     RET        0x4
    //                               LAB_004114bf                                                 XREF[2]:     00411493(j), 004114a3(j)  
    //                              aipbook.cpp:1331 (2)
    //         004114bf     SBB        EAX,EAX
    //                              aipbook.cpp:1334 (17)
    //         004114c1     POP        ESI
    //         004114c2     SBB        EAX,-0x1
    //         004114c5     POP        EBX
    //         004114c6     NEG        EAX
    //         004114c8     SBB        EAX,EAX
    //         004114ca     AND        AL,0xfb
    //         004114cc     ADD        EAX,0x5
    //         004114cf     RET        0x4
}

// Offset: 0x004114E0
int AIPlayBook::convertTargetCharacteristicNameToIntType(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIPlayBook::convertTargetCharacteristicNameToIntType(char *)const      *
    //                              *********************************************************************************************************
    //                              int __thiscall convertTargetCharacteristicNameToIntType(AIPlayBook *
    //              int               EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004114e3(R)  
    //                               ?convertTargetCharacteristicNameToIntType@AIPlayBook@@UBEHP  XREF[2]:     convertTargetCharacteristicNameToI
    //                               AIPlayBook::convertTargetCharacteristicNameToIntType                      0056e978(*)  
    //                              aipbook.cpp:1339 (3)
    //         004114e0     PUSH       EBX
    //         004114e1     PUSH       ESI
    //         004114e2     PUSH       EDI
    //                              aipbook.cpp:1340 (60)
    //         004114e3     MOV        EDI,dword ptr [ESP + param_1]
    //         004114e7     MOV        ESI,s_Stationary                                 = 53h
    //         004114ec     MOV        EAX,EDI
    //                               LAB_004114ee                                                 XREF[1]:     00411510(j)  
    //         004114ee     MOV        DL,byte ptr [EAX]
    //         004114f0     MOV        BL,byte ptr [ESI]=>s_Stationary                  = 53h
    //                                                                                  = 61h
    //         004114f2     MOV        this,DL
    //         004114f4     CMP        DL,BL
    //         004114f6     JNZ        LAB_00411516
    //         004114f8     TEST       this,this
    //         004114fa     JZ         LAB_00411512
    //         004114fc     MOV        DL,byte ptr [EAX + 0x1]
    //         004114ff     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f739            = 74h
    //                                                                                  = "tionary"
    //         00411502     MOV        this,DL
    //         00411504     CMP        DL,BL
    //         00411506     JNZ        LAB_00411516
    //         00411508     ADD        EAX,0x2
    //         0041150b     ADD        ESI,0x2
    //         0041150e     TEST       this,this
    //         00411510     JNZ        LAB_004114ee
    //                               LAB_00411512                                                 XREF[1]:     004114fa(j)  
    //         00411512     XOR        EAX,EAX
    //         00411514     JMP        LAB_0041151b
    //                               LAB_00411516                                                 XREF[2]:     004114f6(j), 00411506(j)  
    //         00411516     SBB        EAX,EAX
    //         00411518     SBB        EAX,-0x1
    //                               LAB_0041151b                                                 XREF[1]:     00411514(j)  
    //         0041151b     TEST       EAX,EAX
    //         0041151d     JNZ        LAB_0041152a
    //                              aipbook.cpp:1341 (5)
    //         0041151f     MOV        EAX,0x1
    //                              aipbook.cpp:1351 (6)
    //         00411524     POP        EDI
    //         00411525     POP        ESI
    //         00411526     POP        EBX
    //         00411527     RET        0x4
    //                               LAB_0041152a                                                 XREF[1]:     0041151d(j)  
    //                              aipbook.cpp:1342 (56)
    //         0041152a     MOV        ESI,s_Moving                                     = 4Dh
    //         0041152f     MOV        EAX,EDI
    //                               LAB_00411531                                                 XREF[1]:     00411553(j)  
    //         00411531     MOV        DL,byte ptr [EAX]
    //         00411533     MOV        BL,byte ptr [ESI]=>s_Moving                      = 4Dh
    //                                                                                  = 76h
    //         00411535     MOV        this,DL
    //         00411537     CMP        DL,BL
    //         00411539     JNZ        LAB_00411559
    //         0041153b     TEST       this,this
    //         0041153d     JZ         LAB_00411555
    //         0041153f     MOV        DL,byte ptr [EAX + 0x1]
    //         00411542     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f731            = 6Fh
    //                                                                                  = 00676e69
    //         00411545     MOV        this,DL
    //         00411547     CMP        DL,BL
    //         00411549     JNZ        LAB_00411559
    //         0041154b     ADD        EAX,0x2
    //         0041154e     ADD        ESI,0x2
    //         00411551     TEST       this,this
    //         00411553     JNZ        LAB_00411531
    //                               LAB_00411555                                                 XREF[1]:     0041153d(j)  
    //         00411555     XOR        EAX,EAX
    //         00411557     JMP        LAB_0041155e
    //                               LAB_00411559                                                 XREF[2]:     00411539(j), 00411549(j)  
    //         00411559     SBB        EAX,EAX
    //         0041155b     SBB        EAX,-0x1
    //                               LAB_0041155e                                                 XREF[1]:     00411557(j)  
    //         0041155e     TEST       EAX,EAX
    //         00411560     JNZ        LAB_0041156d
    //                              aipbook.cpp:1343 (5)
    //         00411562     MOV        EAX,0x2
    //                              aipbook.cpp:1351 (6)
    //         00411567     POP        EDI
    //         00411568     POP        ESI
    //         00411569     POP        EBX
    //         0041156a     RET        0x4
    //                               LAB_0041156d                                                 XREF[1]:     00411560(j)  
    //                              aipbook.cpp:1344 (56)
    //         0041156d     MOV        ESI,s_Slow                                       = 53h
    //         00411572     MOV        EAX,EDI
    //                               LAB_00411574                                                 XREF[1]:     00411596(j)  
    //         00411574     MOV        DL,byte ptr [EAX]
    //         00411576     MOV        BL,byte ptr [ESI]=>s_Slow                        = 53h
    //                                                                                  = 6Fh
    //         00411578     MOV        this,DL
    //         0041157a     CMP        DL,BL
    //         0041157c     JNZ        LAB_0041159c
    //         0041157e     TEST       this,this
    //         00411580     JZ         LAB_00411598
    //         00411582     MOV        DL,byte ptr [EAX + 0x1]
    //         00411585     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f729            = 6Ch
    //                                                                                  = 77h
    //         00411588     MOV        this,DL
    //         0041158a     CMP        DL,BL
    //         0041158c     JNZ        LAB_0041159c
    //         0041158e     ADD        EAX,0x2
    //         00411591     ADD        ESI,0x2
    //         00411594     TEST       this,this
    //         00411596     JNZ        LAB_00411574
    //                               LAB_00411598                                                 XREF[1]:     00411580(j)  
    //         00411598     XOR        EAX,EAX
    //         0041159a     JMP        LAB_004115a1
    //                               LAB_0041159c                                                 XREF[2]:     0041157c(j), 0041158c(j)  
    //         0041159c     SBB        EAX,EAX
    //         0041159e     SBB        EAX,-0x1
    //                               LAB_004115a1                                                 XREF[1]:     0041159a(j)  
    //         004115a1     TEST       EAX,EAX
    //         004115a3     JNZ        LAB_004115b0
    //                              aipbook.cpp:1345 (5)
    //         004115a5     MOV        EAX,0x3
    //                              aipbook.cpp:1351 (6)
    //         004115aa     POP        EDI
    //         004115ab     POP        ESI
    //         004115ac     POP        EBX
    //         004115ad     RET        0x4
    //                               LAB_004115b0                                                 XREF[1]:     004115a3(j)  
    //                              aipbook.cpp:1346 (56)
    //         004115b0     MOV        ESI,s_Fast                                       = 46h
    //         004115b5     MOV        EAX,EDI
    //                               LAB_004115b7                                                 XREF[1]:     004115d9(j)  
    //         004115b7     MOV        DL,byte ptr [EAX]
    //         004115b9     MOV        BL,byte ptr [ESI]=>s_Fast                        = 46h
    //                                                                                  = 73h
    //         004115bb     MOV        this,DL
    //         004115bd     CMP        DL,BL
    //         004115bf     JNZ        LAB_004115df
    //         004115c1     TEST       this,this
    //         004115c3     JZ         LAB_004115db
    //         004115c5     MOV        DL,byte ptr [EAX + 0x1]
    //         004115c8     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f721            = 61h
    //                                                                                  = 74h
    //         004115cb     MOV        this,DL
    //         004115cd     CMP        DL,BL
    //         004115cf     JNZ        LAB_004115df
    //         004115d1     ADD        EAX,0x2
    //         004115d4     ADD        ESI,0x2
    //         004115d7     TEST       this,this
    //         004115d9     JNZ        LAB_004115b7
    //                               LAB_004115db                                                 XREF[1]:     004115c3(j)  
    //         004115db     XOR        EAX,EAX
    //         004115dd     JMP        LAB_004115e4
    //                               LAB_004115df                                                 XREF[2]:     004115bf(j), 004115cf(j)  
    //         004115df     SBB        EAX,EAX
    //         004115e1     SBB        EAX,-0x1
    //                               LAB_004115e4                                                 XREF[1]:     004115dd(j)  
    //         004115e4     TEST       EAX,EAX
    //         004115e6     JNZ        LAB_004115f3
    //                              aipbook.cpp:1347 (5)
    //         004115e8     MOV        EAX,0x4
    //                              aipbook.cpp:1351 (6)
    //         004115ed     POP        EDI
    //         004115ee     POP        ESI
    //         004115ef     POP        EBX
    //         004115f0     RET        0x4
    //                               LAB_004115f3                                                 XREF[1]:     004115e6(j)  
    //                              aipbook.cpp:1348 (54)
    //         004115f3     MOV        ESI,s_Any                                        = 41h
    //         004115f8     MOV        EAX,EDI
    //                               LAB_004115fa                                                 XREF[1]:     0041161c(j)  
    //         004115fa     MOV        DL,byte ptr [EAX]
    //         004115fc     MOV        BL,byte ptr [ESI]=>s_Any                         = 41h
    //                                                                                  = 79h
    //         004115fe     MOV        this,DL
    //         00411600     CMP        DL,BL
    //         00411602     JNZ        LAB_0041162f
    //         00411604     TEST       this,this
    //         00411606     JZ         LAB_0041161e
    //         00411608     MOV        DL,byte ptr [EAX + 0x1]
    //         0041160b     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f71d            = 6Eh
    //         0041160e     MOV        this,DL
    //         00411610     CMP        DL,BL
    //         00411612     JNZ        LAB_0041162f
    //         00411614     ADD        EAX,0x2
    //         00411617     ADD        ESI,0x2
    //         0041161a     TEST       this,this
    //         0041161c     JNZ        LAB_004115fa
    //                               LAB_0041161e                                                 XREF[1]:     00411606(j)  
    //         0041161e     XOR        EAX,EAX
    //         00411620     NEG        EAX
    //         00411622     SBB        EAX,EAX
    //         00411624     AND        AL,0xfb
    //         00411626     ADD        EAX,0x5
    //                              aipbook.cpp:1351 (6)
    //         00411629     POP        EDI
    //         0041162a     POP        ESI
    //         0041162b     POP        EBX
    //         0041162c     RET        0x4
    //                               LAB_0041162f                                                 XREF[2]:     00411602(j), 00411612(j)  
    //                              aipbook.cpp:1348 (2)
    //         0041162f     SBB        EAX,EAX
    //                              aipbook.cpp:1351 (18)
    //         00411631     POP        EDI
    //         00411632     SBB        EAX,-0x1
    //         00411635     POP        ESI
    //         00411636     NEG        EAX
    //         00411638     SBB        EAX,EAX
    //         0041163a     POP        EBX
    //         0041163b     AND        AL,0xfb
    //         0041163d     ADD        EAX,0x5
    //         00411640     RET        0x4
}

// Offset: 0x00411650
int AIPlayBook::convertUnitNameToIntType(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIPlayBook::convertUnitNameToIntType(char *)const                      *
    //                              *********************************************************************************************************
    //                              int __thiscall convertUnitNameToIntType(AIPlayBook * this, char * pa
    //              int               EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?convertUnitNameToIntType@AIPlayBook@@UBEHPAD@Z              XREF[2]:     convertUnitNameToIntType:004e6ac0(
    //                               AIPlayBook::convertUnitNameToIntType                                      0056e97c(*)  
    //                              aipbook.cpp:1356 (3)
    //         00411650     OR         EAX,0xffffffff
    //                              aipbook.cpp:1358 (3)
    //         00411653     RET        0x4
}

// Offset: 0x00411660
int AIPlayBook::convertUnitToIntType(RGE_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIPlayBook::convertUnitToIntType(class RGE_Static_Object *)const       *
    //                              *********************************************************************************************************
    //                              int __thiscall convertUnitToIntType(AIPlayBook * this, RGE_Static_Ob
    //              int               EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1
    //                               ?convertUnitToIntType@AIPlayBook@@UBEHPAVRGE_Static_Object@  XREF[1]:     0056e980(*)  
    //                               AIPlayBook::convertUnitToIntType
    //                              aipbook.cpp:1363 (3)
    //         00411660     OR         EAX,0xffffffff
    //                              aipbook.cpp:1365 (3)
    //         00411663     RET        0x4
}

