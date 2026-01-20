// Auto-generated scaffold unit: aiconmod.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aiconmod.cpp
#include "../include/common.h"

// Offset: 0x0040AA90
undefined ConstructionAIModule(ConstructionAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ConstructionAIModule::ConstructionAIModule(void *,int)                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ConstructionAIModule(ConstructionAIModule * thi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0040aaa6(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040aaae(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040aad5(W), 0040aaea(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040ab6d(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040aac2(W)  
    //                               ??0ConstructionAIModule@@QAE@PAXH@Z                          XREF[1]:     TribeConstructionAIModule:004d5e6f
    //                               ConstructionAIModule::ConstructionAIModule
    //                              aiconmod.cpp:36 (134)
    //         0040aa90     PUSH       -0x1
    //         0040aa92     PUSH       FUN_0055c536
    //         0040aa97     MOV        EAX,FS:[0x0]
    //         0040aa9d     PUSH       EAX
    //         0040aa9e     MOV        dword ptr FS:[0x0],ESP
    //         0040aaa5     PUSH       this
    //         0040aaa6     MOV        EAX,dword ptr [ESP + param_1]
    //         0040aaaa     PUSH       EBX
    //         0040aaab     PUSH       EBP
    //         0040aaac     MOV        EBX,this
    //         0040aaae     MOV        this,dword ptr [ESP + param_2]
    //         0040aab2     PUSH       ESI
    //         0040aab3     PUSH       EDI
    //         0040aab4     PUSH       EAX
    //         0040aab5     PUSH       this
    //                              language.dll match for 0x3ea: "X"
    //         0040aab6     PUSH       0x3ea
    //         0040aabb     PUSH       s_ConAI                                          = "ConAI"
    //         0040aac0     MOV        this,EBX
    //         0040aac2     MOV        dword ptr [ESP + local_10],EBX
    //         0040aac6     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040aacb     LEA        ESI,[EBX + 0xf4]
    //         0040aad1     XOR        EBP,EBP
    //         0040aad3     MOV        this,ESI
    //         0040aad5     MOV        dword ptr [ESP + local_4],EBP
    //         0040aad9     MOV        dword ptr [EBX + 0xf0],EBP
    //         0040aadf     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //         0040aae4     LEA        EDI,[EBX + 0x178]
    //         0040aaea     MOV        byte ptr [ESP + local_4],0x1
    //         0040aaef     MOV        this,EDI
    //         0040aaf1     MOV        dword ptr [EBX + 0x174],EBP
    //         0040aaf7     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //         0040aafc     MOV        EAX,0xbf800000
    //         0040ab01     OR         this,0xffffffff
    //         0040ab04     MOV        dword ptr [EBX + 0x2fc],EAX
    //         0040ab0a     MOV        dword ptr [EBX + 0x300],EAX
    //         0040ab10     MOV        dword ptr [EBX + 0x304],EAX
    //                              aiconmod.cpp:39 (6)
    //         0040ab16     MOV        dword ptr [EBX + 0x1e4],EDI
    //                              aiconmod.cpp:40 (6)
    //         0040ab1c     MOV        dword ptr [EBX + 0x1e8],EDI
    //                              aiconmod.cpp:42 (68)
    //         0040ab22     MOV        EDI,s_                                           = ""
    //         0040ab27     XOR        EAX,EAX
    //         0040ab29     MOV        dword ptr [EBX + 0x308],this
    //         0040ab2f     MOV        dword ptr [EBX + 0x30c],this
    //         0040ab35     MOV        dword ptr [EBX + 0x310],EBP
    //         0040ab3b     MOV        dword ptr [EBX],ConstructionAIModule::`vftable'  = 0040ab90
    //         0040ab41     MOV        dword ptr [EBX + 0x160],ESI
    //         0040ab47     MOV        dword ptr [EBX + 0x164],ESI
    //         0040ab4d     LEA        EDX,[EBX + 0x1f8]
    //         0040ab53     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040ab55     NOT        this
    //         0040ab57     SUB        EDI,this
    //         0040ab59     MOV        EAX,this
    //         0040ab5b     MOV        ESI,EDI
    //         0040ab5d     MOV        EDI,EDX
    //         0040ab5f     SHR        this,0x2
    //         0040ab62     MOVSD.REP  ES:EDI,ESI
    //         0040ab64     MOV        this,EAX
    //                              aiconmod.cpp:43 (28)
    //         0040ab66     MOV        EAX,EBX
    //         0040ab68     AND        this,0x3
    //         0040ab6b     MOVSB.REP  ES:EDI,ESI
    //         0040ab6d     MOV        this,dword ptr [ESP + local_c]
    //         0040ab71     POP        EDI
    //         0040ab72     POP        ESI
    //         0040ab73     POP        EBP
    //         0040ab74     MOV        dword ptr FS:[0x0],this
    //         0040ab7b     POP        EBX
    //         0040ab7c     ADD        ESP,0x10
    //         0040ab7f     RET        0x8
}

// Offset: 0x0040ABB0
undefined ConstructionAIModule(ConstructionAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ConstructionAIModule::ConstructionAIModule(int,int)                                *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ConstructionAIModule(ConstructionAIModule * thi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040abcb(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040ac3d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     0040abfc(W), 0040ac18(W), 0040ac48(W), 0040ae52(W), 
    //                                                                                     0040ae98(W), 0040b03d(W), 0040b083(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040b0f6(R)  
    //              char[257]         Stack[-0x114   name                      XREF[1,4]:   0040abe5(W), 0040ad57(*), 0040ae60(*), 0040af42(*), 
    //                                                                                     0040b04b(*)  
    //              undefined4        Stack[-0x118   local_118                 XREF[2]:     0040ae4c(W), 0040b037(W)  
    //              undefined4        Stack[-0x11c   local_11c                 XREF[3]:     0040ad35(W), 0040aef6(R), 0040af05(W)  
    //              int               Stack[-0x120   i                         XREF[4]:     0040addf(*), 0040ae6a(R), 0040af6a(*), 0040b0a8(R)  
    //              int               Stack[-0x124   gameID                    XREF[4]:     0040adbf(*), 0040ae74(R), 0040b00a(*), 0040b090(R)  
    //              int               Stack[-0x128   builtValue                XREF[4]:     0040adff(*), 0040aed5(R), 0040af55(*), 0040b047(R)  
    //              int               Stack[-0x12c   typeID@fffffed4           XREF[4]:     0040ad6a(*), 0040ae5c(R), 0040afea(*), 0040b0c0(R)  
    //              int               Stack[-0x130   skipValue                 XREF[4]:     0040ad8f(*), 0040aec9(R), 0040afda(*), 0040b050(R)  
    //              float             Stack[-0x134   zSize                     XREF[4]:     0040adaf(*), 0040ae79(R), 0040affa(*), 0040b07c(R)  
    //              int               Stack[-0x138   inProgressValue@fffffec8  XREF[4]:     0040ad7f(*), 0040aebd(R), 0040afca(*), 0040b055(R)  
    //              float             Stack[-0x13c   ySize@fffffec4            XREF[4]:     0040adcf(*), 0040ae6f(R), 0040b01a(*), 0040b09c(R)  
    //              int               Stack[-0x140   buildAttemptsValue@fffff  XREF[4]:     0040ae2f(*), 0040aeb1(R), 0040afba(*), 0040b05a(R)  
    //              float             Stack[-0x144   xSize                     XREF[4]:     0040adef(*), 0040ae65(R), 0040af7a(*), 0040b0b4(R)  
    //              int               Stack[-0x148   uniqueID@fffffeb8         XREF[4]:     0040ae1f(*), 0040aea5(R), 0040afaa(*), 0040b05f(R)  
    //              float             Stack[-0x14c   z@fffffeb4                XREF[4]:     0040ae0f(*), 0040ae91(R), 0040af9a(*), 0040b064(R)  
    //              float             Stack[-0x150   y                         XREF[4]:     0040ad9f(*), 0040ae7e(R), 0040af8a(*), 0040b069(R)  
    //              float             Stack[-0x154   x                         XREF[9]:     0040aca6(*), 0040acb3(R), 0040acc8(R), 0040ad43(*), 
    //                                                                                     0040ad50(R), 0040ad63(R), 0040af2e(*), 0040af3b(R), 
    //                                                                                     0040af4e(R)  
    //              int               Stack[-0x158   tempInt
    //                               ??0ConstructionAIModule@@QAE@HH@Z                            XREF[1]:     TribeConstructionAIModule:004d5ebf
    //                               ConstructionAIModule::ConstructionAIModule
    //                              aiconmod.cpp:57 (129)
    //         0040abb0     PUSH       -0x1
    //         0040abb2     PUSH       FUN_0055c589
    //         0040abb7     MOV        EAX,FS:[0x0]
    //         0040abbd     PUSH       EAX
    //         0040abbe     MOV        dword ptr FS:[0x0],ESP
    //         0040abc5     SUB        ESP,0x148
    //         0040abcb     MOV        EAX,dword ptr [ESP + param_1]
    //         0040abd2     PUSH       EBX
    //         0040abd3     PUSH       EBP
    //         0040abd4     PUSH       ESI
    //         0040abd5     PUSH       EDI
    //         0040abd6     PUSH       0x0
    //         0040abd8     PUSH       EAX
    //         0040abd9     MOV        EDI,this
    //                              language.dll match for 0x3ea: "X"
    //         0040abdb     PUSH       0x3ea
    //         0040abe0     PUSH       s_ConAI                                          = "ConAI"
    //         0040abe5     MOV        dword ptr [ESP + name[0]],EDI
    //         0040abe9     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040abee     LEA        EBX,[EDI + 0xf0]
    //         0040abf4     LEA        ESI,[EDI + 0xf4]
    //         0040abfa     MOV        this,ESI
    //         0040abfc     MOV        dword ptr [ESP + local_4],0x0
    //         0040ac07     MOV        dword ptr [EBX],0x0
    //         0040ac0d     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //         0040ac12     LEA        EBP,[EDI + 0x178]
    //         0040ac18     MOV        byte ptr [ESP + local_4],0x1
    //         0040ac20     MOV        this,EBP
    //         0040ac22     MOV        dword ptr [EDI + 0x174],0x0
    //         0040ac2c     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //                              aiconmod.cpp:58 (6)
    //         0040ac31     MOV        dword ptr [EDI + 0x160],ESI
    //                              aiconmod.cpp:59 (6)
    //         0040ac37     MOV        dword ptr [EDI + 0x164],ESI
    //                              aiconmod.cpp:64 (105)
    //         0040ac3d     MOV        ESI,dword ptr [ESP + param_2]
    //         0040ac44     PUSH       0x4
    //         0040ac46     PUSH       EBX
    //         0040ac47     PUSH       ESI
    //         0040ac48     MOV        byte ptr [ESP + local_4],0x2
    //         0040ac50     MOV        dword ptr [EDI + 0x2fc],0xbf800000
    //         0040ac5a     MOV        dword ptr [EDI + 0x300],0xbf800000
    //         0040ac64     MOV        dword ptr [EDI + 0x304],0xbf800000
    //         0040ac6e     MOV        dword ptr [EDI + 0x308],0xffffffff
    //         0040ac78     MOV        dword ptr [EDI + 0x30c],0xffffffff
    //         0040ac82     MOV        dword ptr [EDI + 0x310],0x0
    //         0040ac8c     MOV        dword ptr [EDI],ConstructionAIModule::`vftable'  = 0040ab90
    //         0040ac92     MOV        dword ptr [EDI + 0x1e4],EBP
    //         0040ac98     MOV        dword ptr [EDI + 0x1e8],EBP
    //         0040ac9e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040aca3     ADD        ESP,0xc
    //                              aiconmod.cpp:67 (13)
    //         0040aca6     LEA        this=>x,[ESP + 0x10]
    //         0040acaa     PUSH       0x4
    //         0040acac     PUSH       this
    //         0040acad     PUSH       ESI
    //         0040acae     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:68 (21)
    //         0040acb3     MOV        EDX,dword ptr [ESP + x]
    //         0040acb7     ADD        ESP,0xc
    //         0040acba     LEA        EAX,[EDI + 0x1f8]
    //         0040acc0     PUSH       EDX
    //         0040acc1     PUSH       EAX
    //         0040acc2     PUSH       ESI
    //         0040acc3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:69 (7)
    //         0040acc8     MOV        this,dword ptr [ESP + x]
    //         0040accc     ADD        ESP,0xc
    //                              aiconmod.cpp:71 (26)
    //         0040accf     LEA        EAX,[EDI + 0x2fc]
    //         0040acd5     PUSH       0x4
    //         0040acd7     PUSH       EAX
    //         0040acd8     PUSH       ESI
    //         0040acd9     MOV        byte ptr [ECX + EDI*0x1 + this->constructionPl
    //         0040ace1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ace6     ADD        ESP,0xc
    //                              aiconmod.cpp:72 (18)
    //         0040ace9     LEA        EAX,[EDI + 0x300]
    //         0040acef     PUSH       0x4
    //         0040acf1     PUSH       EAX
    //         0040acf2     PUSH       ESI
    //         0040acf3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040acf8     ADD        ESP,0xc
    //                              aiconmod.cpp:73 (18)
    //         0040acfb     LEA        EAX,[EDI + 0x304]
    //         0040ad01     PUSH       0x4
    //         0040ad03     PUSH       EAX
    //         0040ad04     PUSH       ESI
    //         0040ad05     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ad0a     ADD        ESP,0xc
    //                              aiconmod.cpp:74 (18)
    //         0040ad0d     LEA        EAX,[EDI + 0x308]
    //         0040ad13     PUSH       0x4
    //         0040ad15     PUSH       EAX
    //         0040ad16     PUSH       ESI
    //         0040ad17     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ad1c     ADD        ESP,0xc
    //                              aiconmod.cpp:75 (15)
    //         0040ad1f     LEA        EAX,[EDI + 0x30c]
    //         0040ad25     PUSH       0x4
    //         0040ad27     PUSH       EAX
    //         0040ad28     PUSH       ESI
    //         0040ad29     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:78 (21)
    //         0040ad2e     MOV        EAX,dword ptr [EBX]
    //         0040ad30     ADD        ESP,0xc
    //         0040ad33     TEST       EAX,EAX
    //         0040ad35     MOV        dword ptr [ESP + local_11c],0x0
    //         0040ad3d     JLE        LAB_0040af0f
    //                               LAB_0040ad43                                                 XREF[1]:     0040af09(j)  
    //                              aiconmod.cpp:81 (13)
    //         0040ad43     LEA        EDX=>x,[ESP + 0x10]
    //         0040ad47     PUSH       0x4
    //         0040ad49     PUSH       EDX
    //         0040ad4a     PUSH       ESI
    //         0040ad4b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:82 (19)
    //         0040ad50     MOV        EAX,dword ptr [ESP + x]
    //         0040ad54     ADD        ESP,0xc
    //         0040ad57     LEA        this=>name[4],[ESP + 0x54]
    //         0040ad5b     PUSH       EAX
    //         0040ad5c     PUSH       this
    //         0040ad5d     PUSH       ESI
    //         0040ad5e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:83 (7)
    //         0040ad63     MOV        EDX,dword ptr [ESP + x]
    //         0040ad67     ADD        ESP,0xc
    //                              aiconmod.cpp:86 (21)
    //         0040ad6a     LEA        EAX=>typeID@fffffed4,[ESP + 0x38]
    //         0040ad6e     PUSH       0x4
    //         0040ad70     PUSH       EAX
    //         0040ad71     PUSH       ESI
    //         0040ad72     MOV        byte ptr [ESP + EDX*0x1 + 0x60],0x0
    //         0040ad77     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ad7c     ADD        ESP,0xc
    //                              aiconmod.cpp:88 (16)
    //         0040ad7f     LEA        this=>inProgressValue@fffffec8,[ESP + 0x2c]
    //         0040ad83     PUSH       0x4
    //         0040ad85     PUSH       this
    //         0040ad86     PUSH       ESI
    //         0040ad87     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ad8c     ADD        ESP,0xc
    //                              aiconmod.cpp:90 (16)
    //         0040ad8f     LEA        EDX=>skipValue,[ESP + 0x34]
    //         0040ad93     PUSH       0x4
    //         0040ad95     PUSH       EDX
    //         0040ad96     PUSH       ESI
    //         0040ad97     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ad9c     ADD        ESP,0xc
    //                              aiconmod.cpp:92 (16)
    //         0040ad9f     LEA        EAX=>y,[ESP + 0x14]
    //         0040ada3     PUSH       0x4
    //         0040ada5     PUSH       EAX
    //         0040ada6     PUSH       ESI
    //         0040ada7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040adac     ADD        ESP,0xc
    //                              aiconmod.cpp:94 (16)
    //         0040adaf     LEA        this=>zSize,[ESP + 0x30]
    //         0040adb3     PUSH       0x4
    //         0040adb5     PUSH       this
    //         0040adb6     PUSH       ESI
    //         0040adb7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040adbc     ADD        ESP,0xc
    //                              aiconmod.cpp:96 (16)
    //         0040adbf     LEA        EDX=>gameID,[ESP + 0x40]
    //         0040adc3     PUSH       0x4
    //         0040adc5     PUSH       EDX
    //         0040adc6     PUSH       ESI
    //         0040adc7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040adcc     ADD        ESP,0xc
    //                              aiconmod.cpp:98 (16)
    //         0040adcf     LEA        EAX=>ySize@fffffec4,[ESP + 0x28]
    //         0040add3     PUSH       0x4
    //         0040add5     PUSH       EAX
    //         0040add6     PUSH       ESI
    //         0040add7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040addc     ADD        ESP,0xc
    //                              aiconmod.cpp:100 (16)
    //         0040addf     LEA        this=>i,[ESP + 0x44]
    //         0040ade3     PUSH       0x4
    //         0040ade5     PUSH       this
    //         0040ade6     PUSH       ESI
    //         0040ade7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040adec     ADD        ESP,0xc
    //                              aiconmod.cpp:102 (16)
    //         0040adef     LEA        EDX=>xSize,[ESP + 0x20]
    //         0040adf3     PUSH       0x4
    //         0040adf5     PUSH       EDX
    //         0040adf6     PUSH       ESI
    //         0040adf7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040adfc     ADD        ESP,0xc
    //                              aiconmod.cpp:104 (16)
    //         0040adff     LEA        EAX=>builtValue,[ESP + 0x3c]
    //         0040ae03     PUSH       0x4
    //         0040ae05     PUSH       EAX
    //         0040ae06     PUSH       ESI
    //         0040ae07     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ae0c     ADD        ESP,0xc
    //                              aiconmod.cpp:107 (16)
    //         0040ae0f     LEA        this=>z@fffffeb4,[ESP + 0x18]
    //         0040ae13     PUSH       0x4
    //         0040ae15     PUSH       this
    //         0040ae16     PUSH       ESI
    //         0040ae17     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ae1c     ADD        ESP,0xc
    //                              aiconmod.cpp:109 (16)
    //         0040ae1f     LEA        EDX=>uniqueID@fffffeb8,[ESP + 0x1c]
    //         0040ae23     PUSH       0x4
    //         0040ae25     PUSH       EDX
    //         0040ae26     PUSH       ESI
    //         0040ae27     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ae2c     ADD        ESP,0xc
    //                              aiconmod.cpp:111 (16)
    //         0040ae2f     LEA        EAX=>buildAttemptsValue@fffffec0,[ESP + 0x24]
    //         0040ae33     PUSH       0x4
    //         0040ae35     PUSH       EAX
    //         0040ae36     PUSH       ESI
    //         0040ae37     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040ae3c     ADD        ESP,0xc
    //                              language.dll match for 0x80: "Arial"
    //                              aiconmod.cpp:114 (82)
    //         0040ae3f     PUSH       0x80
    //         0040ae44     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040ae49     ADD        ESP,0x4
    //         0040ae4c     MOV        dword ptr [ESP + local_118],EAX
    //         0040ae50     TEST       EAX,EAX
    //         0040ae52     MOV        byte ptr [ESP + local_4],0x3
    //         0040ae5a     JZ         LAB_0040ae8f
    //         0040ae5c     MOV        EDX,dword ptr [ESP + typeID@fffffed4]
    //         0040ae60     LEA        this=>name[4],[ESP + 0x54]
    //         0040ae64     PUSH       this
    //         0040ae65     MOV        this,dword ptr [ESP + xSize]
    //         0040ae69     PUSH       EDX
    //         0040ae6a     MOV        EDX,dword ptr [ESP + i]
    //         0040ae6e     PUSH       this
    //         0040ae6f     MOV        this,dword ptr [ESP + ySize@fffffec4]
    //         0040ae73     PUSH       EDX
    //         0040ae74     MOV        EDX,dword ptr [ESP + gameID]
    //         0040ae78     PUSH       this
    //         0040ae79     MOV        this,dword ptr [ESP + zSize]
    //         0040ae7d     PUSH       EDX
    //         0040ae7e     MOV        EDX,dword ptr [ESP + y]
    //         0040ae82     PUSH       this
    //         0040ae83     PUSH       EDX
    //         0040ae84     MOV        this,EAX
    //         0040ae86     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //         0040ae8b     MOV        EBP,EAX
    //         0040ae8d     JMP        LAB_0040ae91
    //                               LAB_0040ae8f                                                 XREF[1]:     0040ae5a(j)  
    //         0040ae8f     XOR        EBP,EBP
    //                               LAB_0040ae91                                                 XREF[1]:     0040ae8d(j)  
    //                              aiconmod.cpp:115 (20)
    //         0040ae91     MOV        EAX,dword ptr [ESP + z@fffffeb4]
    //         0040ae95     MOV        this,EBP
    //         0040ae97     PUSH       EAX
    //         0040ae98     MOV        byte ptr [ESP + local_4],0x2
    //         0040aea0     CALL       ConstructionItem::setInProgress                  void setInProgress(ConstructionItem * this, i
    //                              aiconmod.cpp:116 (12)
    //         0040aea5     MOV        this,dword ptr [ESP + uniqueID@fffffeb8]
    //         0040aea9     PUSH       this
    //         0040aeaa     MOV        this,EBP
    //         0040aeac     CALL       ConstructionItem::setBuilt                       void setBuilt(ConstructionItem * this, int pa
    //                              aiconmod.cpp:117 (12)
    //         0040aeb1     MOV        EDX,dword ptr [ESP + buildAttemptsValue@fffffe
    //         0040aeb5     MOV        this,EBP
    //         0040aeb7     PUSH       EDX
    //         0040aeb8     CALL       ConstructionItem::setBuildAttempts               void setBuildAttempts(ConstructionItem * this
    //                              aiconmod.cpp:118 (12)
    //         0040aebd     MOV        EAX,dword ptr [ESP + inProgressValue@fffffec8]
    //         0040aec1     MOV        this,EBP
    //         0040aec3     PUSH       EAX
    //         0040aec4     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
    //                              aiconmod.cpp:119 (12)
    //         0040aec9     MOV        this,dword ptr [ESP + skipValue]
    //         0040aecd     PUSH       this
    //         0040aece     MOV        this,EBP
    //         0040aed0     CALL       BaseItem::setUniqueID                            void setUniqueID(BaseItem * this, int param_1)
    //                              aiconmod.cpp:120 (12)
    //         0040aed5     MOV        EDX,dword ptr [ESP + builtValue]
    //         0040aed9     MOV        this,EBP
    //         0040aedb     PUSH       EDX
    //         0040aedc     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
    //                              aiconmod.cpp:123 (9)
    //         0040aee1     LEA        EAX,[EDI + 0xf4]
    //         0040aee7     MOV        dword ptr [EBP + 0x6c],EAX
    //                              aiconmod.cpp:124 (9)
    //         0040aeea     MOV        EAX,dword ptr [EDI + 0x164]
    //         0040aef0     MOV        dword ptr [EBP + 0x70],EAX
    //                              aiconmod.cpp:125 (12)
    //         0040aef3     MOV        dword ptr [EAX + 0x6c],EBP
    //         0040aef6     MOV        EAX,dword ptr [ESP + local_11c]
    //         0040aefa     MOV        this,dword ptr [EBX]
    //         0040aefc     INC        EAX
    //         0040aefd     CMP        EAX,this
    //                              aiconmod.cpp:126 (16)
    //         0040aeff     MOV        dword ptr [EDI + 0x164],EBP
    //         0040af05     MOV        dword ptr [ESP + local_11c],EAX
    //         0040af09     JL         LAB_0040ad43
    //                               LAB_0040af0f                                                 XREF[1]:     0040ad3d(j)  
    //                              aiconmod.cpp:130 (15)
    //         0040af0f     LEA        EBP,[EDI + 0x174]
    //         0040af15     PUSH       0x4
    //         0040af17     PUSH       EBP
    //         0040af18     PUSH       ESI
    //         0040af19     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:132 (16)
    //         0040af1e     MOV        EAX,dword ptr [EBP]
    //         0040af21     ADD        ESP,0xc
    //         0040af24     XOR        EBX,EBX
    //         0040af26     TEST       EAX,EAX
    //         0040af28     JLE        LAB_0040b0f6
    //                               LAB_0040af2e                                                 XREF[1]:     0040b0f0(j)  
    //                              aiconmod.cpp:135 (13)
    //         0040af2e     LEA        EAX=>x,[ESP + 0x10]
    //         0040af32     PUSH       0x4
    //         0040af34     PUSH       EAX
    //         0040af35     PUSH       ESI
    //         0040af36     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:136 (19)
    //         0040af3b     MOV        this,dword ptr [ESP + x]
    //         0040af3f     ADD        ESP,0xc
    //         0040af42     LEA        EDX=>name[4],[ESP + 0x54]
    //         0040af46     PUSH       this
    //         0040af47     PUSH       EDX
    //         0040af48     PUSH       ESI
    //         0040af49     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aiconmod.cpp:137 (7)
    //         0040af4e     MOV        EAX,dword ptr [ESP + x]
    //         0040af52     ADD        ESP,0xc
    //                              aiconmod.cpp:140 (21)
    //         0040af55     LEA        this=>builtValue,[ESP + 0x3c]
    //         0040af59     PUSH       0x4
    //         0040af5b     PUSH       this
    //         0040af5c     PUSH       ESI
    //         0040af5d     MOV        byte ptr [ESP + EAX*0x1 + 0x60],0x0
    //         0040af62     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040af67     ADD        ESP,0xc
    //                              aiconmod.cpp:142 (16)
    //         0040af6a     LEA        EDX=>i,[ESP + 0x44]
    //         0040af6e     PUSH       0x4
    //         0040af70     PUSH       EDX
    //         0040af71     PUSH       ESI
    //         0040af72     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040af77     ADD        ESP,0xc
    //                              aiconmod.cpp:144 (16)
    //         0040af7a     LEA        EAX=>xSize,[ESP + 0x20]
    //         0040af7e     PUSH       0x4
    //         0040af80     PUSH       EAX
    //         0040af81     PUSH       ESI
    //         0040af82     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040af87     ADD        ESP,0xc
    //                              aiconmod.cpp:146 (16)
    //         0040af8a     LEA        this=>y,[ESP + 0x14]
    //         0040af8e     PUSH       0x4
    //         0040af90     PUSH       this
    //         0040af91     PUSH       ESI
    //         0040af92     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040af97     ADD        ESP,0xc
    //                              aiconmod.cpp:148 (16)
    //         0040af9a     LEA        EDX=>z@fffffeb4,[ESP + 0x18]
    //         0040af9e     PUSH       0x4
    //         0040afa0     PUSH       EDX
    //         0040afa1     PUSH       ESI
    //         0040afa2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040afa7     ADD        ESP,0xc
    //                              aiconmod.cpp:150 (16)
    //         0040afaa     LEA        EAX=>uniqueID@fffffeb8,[ESP + 0x1c]
    //         0040afae     PUSH       0x4
    //         0040afb0     PUSH       EAX
    //         0040afb1     PUSH       ESI
    //         0040afb2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040afb7     ADD        ESP,0xc
    //                              aiconmod.cpp:152 (16)
    //         0040afba     LEA        this=>buildAttemptsValue@fffffec0,[ESP + 0x24]
    //         0040afbe     PUSH       0x4
    //         0040afc0     PUSH       this
    //         0040afc1     PUSH       ESI
    //         0040afc2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040afc7     ADD        ESP,0xc
    //                              aiconmod.cpp:154 (16)
    //         0040afca     LEA        EDX=>inProgressValue@fffffec8,[ESP + 0x2c]
    //         0040afce     PUSH       0x4
    //         0040afd0     PUSH       EDX
    //         0040afd1     PUSH       ESI
    //         0040afd2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040afd7     ADD        ESP,0xc
    //                              aiconmod.cpp:156 (16)
    //         0040afda     LEA        EAX=>skipValue,[ESP + 0x34]
    //         0040afde     PUSH       0x4
    //         0040afe0     PUSH       EAX
    //         0040afe1     PUSH       ESI
    //         0040afe2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040afe7     ADD        ESP,0xc
    //                              aiconmod.cpp:158 (16)
    //         0040afea     LEA        this=>typeID@fffffed4,[ESP + 0x38]
    //         0040afee     PUSH       0x4
    //         0040aff0     PUSH       this
    //         0040aff1     PUSH       ESI
    //         0040aff2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040aff7     ADD        ESP,0xc
    //                              aiconmod.cpp:161 (16)
    //         0040affa     LEA        EDX=>zSize,[ESP + 0x30]
    //         0040affe     PUSH       0x4
    //         0040b000     PUSH       EDX
    //         0040b001     PUSH       ESI
    //         0040b002     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040b007     ADD        ESP,0xc
    //                              aiconmod.cpp:163 (16)
    //         0040b00a     LEA        EAX=>gameID,[ESP + 0x40]
    //         0040b00e     PUSH       0x4
    //         0040b010     PUSH       EAX
    //         0040b011     PUSH       ESI
    //         0040b012     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040b017     ADD        ESP,0xc
    //                              aiconmod.cpp:165 (16)
    //         0040b01a     LEA        this=>ySize@fffffec4,[ESP + 0x28]
    //         0040b01e     PUSH       0x4
    //         0040b020     PUSH       this
    //         0040b021     PUSH       ESI
    //         0040b022     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040b027     ADD        ESP,0xc
    //                              language.dll match for 0x80: "Arial"
    //                              aiconmod.cpp:168 (82)
    //         0040b02a     PUSH       0x80
    //         0040b02f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040b034     ADD        ESP,0x4
    //         0040b037     MOV        dword ptr [ESP + local_118],EAX
    //         0040b03b     TEST       EAX,EAX
    //         0040b03d     MOV        byte ptr [ESP + local_4],0x4
    //         0040b045     JZ         LAB_0040b07a
    //         0040b047     MOV        this,dword ptr [ESP + builtValue]
    //         0040b04b     LEA        EDX=>name[4],[ESP + 0x54]
    //         0040b04f     PUSH       EDX
    //         0040b050     MOV        EDX,dword ptr [ESP + skipValue]
    //         0040b054     PUSH       this
    //         0040b055     MOV        this,dword ptr [ESP + inProgressValue@fffffec8]
    //         0040b059     PUSH       EDX
    //         0040b05a     MOV        EDX,dword ptr [ESP + buildAttemptsValue@fffffe
    //         0040b05e     PUSH       this
    //         0040b05f     MOV        this,dword ptr [ESP + uniqueID@fffffeb8]
    //         0040b063     PUSH       EDX
    //         0040b064     MOV        EDX,dword ptr [ESP + z@fffffeb4]
    //         0040b068     PUSH       this
    //         0040b069     MOV        this,dword ptr [ESP + y]
    //         0040b06d     PUSH       EDX
    //         0040b06e     PUSH       this
    //         0040b06f     MOV        this,EAX
    //         0040b071     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //         0040b076     MOV        EBP,EAX
    //         0040b078     JMP        LAB_0040b07c
    //                               LAB_0040b07a                                                 XREF[1]:     0040b045(j)  
    //         0040b07a     XOR        EBP,EBP
    //                               LAB_0040b07c                                                 XREF[1]:     0040b078(j)  
    //                              aiconmod.cpp:169 (20)
    //         0040b07c     MOV        EDX,dword ptr [ESP + zSize]
    //         0040b080     MOV        this,EBP
    //         0040b082     PUSH       EDX
    //         0040b083     MOV        byte ptr [ESP + local_4],0x2
    //         0040b08b     CALL       ConstructionItem::setInProgress                  void setInProgress(ConstructionItem * this, i
    //                              aiconmod.cpp:170 (12)
    //         0040b090     MOV        EAX,dword ptr [ESP + gameID]
    //         0040b094     MOV        this,EBP
    //         0040b096     PUSH       EAX
    //         0040b097     CALL       ConstructionItem::setBuilt                       void setBuilt(ConstructionItem * this, int pa
    //                              aiconmod.cpp:171 (12)
    //         0040b09c     MOV        this,dword ptr [ESP + ySize@fffffec4]
    //         0040b0a0     PUSH       this
    //         0040b0a1     MOV        this,EBP
    //         0040b0a3     CALL       ConstructionItem::setBuildAttempts               void setBuildAttempts(ConstructionItem * this
    //                              aiconmod.cpp:172 (12)
    //         0040b0a8     MOV        EDX,dword ptr [ESP + i]
    //         0040b0ac     MOV        this,EBP
    //         0040b0ae     PUSH       EDX
    //         0040b0af     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
    //                              aiconmod.cpp:173 (12)
    //         0040b0b4     MOV        EAX,dword ptr [ESP + xSize]
    //         0040b0b8     MOV        this,EBP
    //         0040b0ba     PUSH       EAX
    //         0040b0bb     CALL       BaseItem::setUniqueID                            void setUniqueID(BaseItem * this, int param_1)
    //                              aiconmod.cpp:174 (12)
    //         0040b0c0     MOV        this,dword ptr [ESP + typeID@fffffed4]
    //         0040b0c4     PUSH       this
    //         0040b0c5     MOV        this,EBP
    //         0040b0c7     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
    //                              aiconmod.cpp:177 (10)
    //         0040b0cc     LEA        EAX,[EDI + 0x178]
    //         0040b0d2     INC        EBX
    //         0040b0d3     MOV        dword ptr [EBP + 0x6c],EAX
    //                              aiconmod.cpp:178 (9)
    //         0040b0d6     MOV        EAX,dword ptr [EDI + 0x1e8]
    //         0040b0dc     MOV        dword ptr [EBP + 0x70],EAX
    //                              aiconmod.cpp:179 (11)
    //         0040b0df     MOV        dword ptr [EAX + 0x6c],EBP
    //         0040b0e2     MOV        EAX,dword ptr [EDI + 0x174]
    //         0040b0e8     CMP        EBX,EAX
    //                              aiconmod.cpp:180 (12)
    //         0040b0ea     MOV        dword ptr [EDI + 0x1e8],EBP
    //         0040b0f0     JL         LAB_0040af2e
    //                               LAB_0040b0f6                                                 XREF[1]:     0040af28(j)  
    //                              aiconmod.cpp:182 (29)
    //         0040b0f6     MOV        this,dword ptr [ESP + local_c]
    //         0040b0fd     MOV        EAX,EDI
    //         0040b0ff     POP        EDI
    //         0040b100     POP        ESI
    //         0040b101     POP        EBP
    //         0040b102     MOV        dword ptr FS:[0x0],this
    //         0040b109     POP        EBX
    //         0040b10a     ADD        ESP,0x154
    //         0040b110     RET        0x8
}

// Offset: 0x0040B120
void ConstructionAIModule(ConstructionAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall ConstructionAIModule::~ConstructionAIModule(void)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~ConstructionAIModule(ConstructionAIModule * this)
    //              void              <VOID>         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0040b149(W), 0040b160(W), 0040b170(W), 0040b17c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040b189(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040b139(W)  
    //                               ??1ConstructionAIModule@@UAE@XZ                              XREF[2]:     `scalar_deleting_destructor':0040a
    //                               ConstructionAIModule::~ConstructionAIModule                               ~TribeConstructionAIModule:004d5ee
    //                              aiconmod.cpp:187 (35)
    //         0040b120     PUSH       -0x1
    //         0040b122     PUSH       FUN_0055c5c4
    //         0040b127     MOV        EAX,FS:[0x0]
    //         0040b12d     PUSH       EAX
    //         0040b12e     MOV        dword ptr FS:[0x0],ESP
    //         0040b135     PUSH       this
    //         0040b136     PUSH       ESI
    //         0040b137     MOV        ESI,this
    //         0040b139     MOV        dword ptr [ESP + local_10],ESI
    //         0040b13d     MOV        dword ptr [ESI],ConstructionAIModule::`vftable'  = 0040ab90
    //                              aiconmod.cpp:188 (18)
    //         0040b143     MOV        EAX,dword ptr [ESI + 0xf0]
    //         0040b149     MOV        dword ptr [ESP + local_4],0x2
    //         0040b151     TEST       EAX,EAX
    //         0040b153     JLE        LAB_0040b15a
    //                              aiconmod.cpp:189 (11)
    //         0040b155     CALL       ConstructionAIModule::removeOldLots              void removeOldLots(ConstructionAIModule * this)
    //                               LAB_0040b15a                                                 XREF[1]:     0040b153(j)  
    //         0040b15a     LEA        this,[ESI + 0x178]
    //                              aiconmod.cpp:190 (57)
    //         0040b160     MOV        byte ptr [ESP + local_4],0x1
    //         0040b165     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
    //         0040b16a     LEA        this,[ESI + 0xf4]
    //         0040b170     MOV        byte ptr [ESP + local_4],0x0
    //         0040b175     CALL       ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
    //         0040b17a     MOV        this,ESI
    //         0040b17c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0040b184     CALL       AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //         0040b189     MOV        this,dword ptr [ESP + local_c]
    //         0040b18d     POP        ESI
    //         0040b18e     MOV        dword ptr FS:[0x0],this
    //         0040b195     ADD        ESP,0x10
    //         0040b198     RET
}

// Offset: 0x0040B1A0
int ConstructionAIModule::save(int param_1) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall ConstructionAIModule::save(int)                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall save(ConstructionAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040b1a7(R)  
    //              char[257]         Stack[-0x108   tempString                XREF[3,10]:  0040b1bd(W), 0040b286(R), 0040b47a(R), 0040b1da(*), 
    //                                                                                     0040b1f4(*), 0040b20f(*), 0040b220(*), 0040b2bb(*), 
    //                                                                                     0040b2db(*), 0040b2fd(*), 0040b4be(*), 0040b4de(*), 
    //                                                                                     0040b500(*)  
    //              undefined4        Stack[-0x10c   local_10c                 XREF[4]:     0040b29b(W), 0040b46b(R), 0040b49e(W), 0040b66e(R)  
    //              undefined4        Stack[-0x110   local_110                 XREF[12]:    0040b406(*), 0040b40e(W), 0040b421(*), 0040b429(W), 
    //                                                                                     0040b43c(W), 0040b440(*), 0040b609(*), 0040b611(W), 
    //                                                                                     0040b624(*), 0040b62c(W), 0040b63f(W), 0040b643(*)  
    //              int               Stack[-0x114   tempBOOL                  XREF[24]:    0040b364(W), 0040b368(*), 0040b37f(W), 0040b383(*), 
    //                                                                                     0040b39a(W), 0040b39e(*), 0040b3b5(W), 0040b3b9(*), 
    //                                                                                     0040b3d0(W), 0040b3d4(*), 0040b3eb(W), 0040b3ef(*), 
    //                                                                                     0040b567(W), 0040b56b(*), 0040b582(W), 0040b586(*), 
    //                                                                                     0040b59d(W), 0040b5a1(*), 0040b5b8(W), 0040b5bc(*)  
    //              float             Stack[-0x118   tempFloat                 XREF[24]:    0040b200(W), 0040b204(*), 0040b2e7(W), 0040b2eb(*), 
    //                                                                                     0040b2f6(R), 0040b313(*), 0040b31b(W), 0040b32e(*), 
    //                                                                                     0040b336(W), 0040b349(W), 0040b34d(*), 0040b457(*), 
    //                                                                                     0040b45f(W), 0040b4ea(W), 0040b4ee(*), 0040b4f9(R), 
    //                                                                                     0040b516(*), 0040b51e(W), 0040b531(*), 0040b539(W)  
    //              int               Stack[-0x11c   tempInt
    //                               ?save@ConstructionAIModule@@UAEHH@Z                          XREF[2]:     0056e7dc(*), 005754dc(*)  
    //                               ConstructionAIModule::save
    //                              aiconmod.cpp:195 (7)
    //         0040b1a0     SUB        ESP,0x118
    //         0040b1a6     PUSH       EBX
    //                              aiconmod.cpp:205 (31)
    //         0040b1a7     MOV        EBX,dword ptr [ESP + param_1]
    //         0040b1ae     PUSH       EBP
    //         0040b1af     MOV        EBP,this
    //         0040b1b1     PUSH       ESI
    //         0040b1b2     PUSH       EDI
    //         0040b1b3     LEA        EAX,[EBP + 0xf0]
    //         0040b1b9     PUSH       0x4
    //         0040b1bb     PUSH       EAX
    //         0040b1bc     PUSH       EBX
    //         0040b1bd     MOV        dword ptr [ESP + tempString[0]],EBP
    //         0040b1c1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:208 (30)
    //         0040b1c6     LEA        EDI,[EBP + 0x1f8]
    //         0040b1cc     OR         this,0xffffffff
    //         0040b1cf     XOR        EAX,EAX
    //         0040b1d1     ADD        ESP,0xc
    //         0040b1d4     SCASB.RE   ES:EDI
    //         0040b1d6     NOT        this
    //         0040b1d8     SUB        EDI,this
    //         0040b1da     LEA        EDX=>tempString[4],[ESP + 0x24]
    //         0040b1de     MOV        EAX,this
    //         0040b1e0     MOV        ESI,EDI
    //         0040b1e2     MOV        EDI,EDX
    //                              aiconmod.cpp:210 (43)
    //         0040b1e4     PUSH       0x4
    //         0040b1e6     SHR        this,0x2
    //         0040b1e9     MOVSD.REP  ES:EDI,ESI
    //         0040b1eb     MOV        this,EAX
    //         0040b1ed     XOR        EAX,EAX
    //         0040b1ef     AND        this,0x3
    //         0040b1f2     MOVSB.REP  ES:EDI,ESI
    //         0040b1f4     LEA        EDI=>tempString[4],[ESP + 0x28]
    //         0040b1f8     OR         this,0xffffffff
    //         0040b1fb     SCASB.RE   ES:EDI
    //         0040b1fd     NOT        this
    //         0040b1ff     DEC        this
    //         0040b200     MOV        dword ptr [ESP + tempFloat],this
    //         0040b204     LEA        this=>tempFloat,[ESP + 0x14]
    //         0040b208     PUSH       this
    //         0040b209     PUSH       EBX
    //         0040b20a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:211 (32)
    //         0040b20f     LEA        EDI=>tempString[4],[ESP + 0x30]
    //         0040b213     OR         this,0xffffffff
    //         0040b216     XOR        EAX,EAX
    //         0040b218     ADD        ESP,0xc
    //         0040b21b     SCASB.RE   ES:EDI
    //         0040b21d     NOT        this
    //         0040b21f     DEC        this
    //         0040b220     LEA        EDX=>tempString[4],[ESP + 0x24]
    //         0040b224     PUSH       this
    //         0040b225     PUSH       EDX
    //         0040b226     PUSH       EBX
    //         0040b227     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b22c     ADD        ESP,0xc
    //                              aiconmod.cpp:213 (18)
    //         0040b22f     LEA        EAX,[EBP + 0x2fc]
    //         0040b235     PUSH       0x4
    //         0040b237     PUSH       EAX
    //         0040b238     PUSH       EBX
    //         0040b239     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b23e     ADD        ESP,0xc
    //                              aiconmod.cpp:214 (18)
    //         0040b241     LEA        this,[EBP + 0x300]
    //         0040b247     PUSH       0x4
    //         0040b249     PUSH       this
    //         0040b24a     PUSH       EBX
    //         0040b24b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b250     ADD        ESP,0xc
    //                              aiconmod.cpp:215 (18)
    //         0040b253     LEA        EDX,[EBP + 0x304]
    //         0040b259     PUSH       0x4
    //         0040b25b     PUSH       EDX
    //         0040b25c     PUSH       EBX
    //         0040b25d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b262     ADD        ESP,0xc
    //                              aiconmod.cpp:217 (18)
    //         0040b265     LEA        EAX,[EBP + 0x308]
    //         0040b26b     PUSH       0x4
    //         0040b26d     PUSH       EAX
    //         0040b26e     PUSH       EBX
    //         0040b26f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b274     ADD        ESP,0xc
    //                              aiconmod.cpp:218 (15)
    //         0040b277     LEA        this,[EBP + 0x30c]
    //         0040b27d     PUSH       0x4
    //         0040b27f     PUSH       this
    //         0040b280     PUSH       EBX
    //         0040b281     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:221 (39)
    //         0040b286     MOV        EDX,dword ptr [ESP + tempString[0]]
    //         0040b28a     MOV        EBP,dword ptr [EBP + 0x160]
    //         0040b290     ADD        ESP,0xc
    //         0040b293     LEA        EAX,[EDX + 0xf4]
    //         0040b299     CMP        EBP,EAX
    //         0040b29b     MOV        dword ptr [ESP + local_10c],EAX
    //         0040b29f     JZ         LAB_0040b47a
    //                               LAB_0040b2a5                                                 XREF[1]:     0040b474(j)  
    //         0040b2a5     TEST       EBP,EBP
    //         0040b2a7     JZ         LAB_0040b47a
    //                              aiconmod.cpp:223 (24)
    //         0040b2ad     MOV        this,EBP
    //         0040b2af     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         0040b2b4     MOV        EDI,EAX
    //         0040b2b6     OR         this,0xffffffff
    //         0040b2b9     XOR        EAX,EAX
    //         0040b2bb     LEA        EDX=>tempString[4],[ESP + 0x24]
    //         0040b2bf     SCASB.RE   ES:EDI
    //         0040b2c1     NOT        this
    //         0040b2c3     SUB        EDI,this
    //                              aiconmod.cpp:225 (49)
    //         0040b2c5     PUSH       0x4
    //         0040b2c7     MOV        EAX,this
    //         0040b2c9     MOV        ESI,EDI
    //         0040b2cb     MOV        EDI,EDX
    //         0040b2cd     SHR        this,0x2
    //         0040b2d0     MOVSD.REP  ES:EDI,ESI
    //         0040b2d2     MOV        this,EAX
    //         0040b2d4     XOR        EAX,EAX
    //         0040b2d6     AND        this,0x3
    //         0040b2d9     MOVSB.REP  ES:EDI,ESI
    //         0040b2db     LEA        EDI=>tempString[4],[ESP + 0x28]
    //         0040b2df     OR         this,0xffffffff
    //         0040b2e2     SCASB.RE   ES:EDI
    //         0040b2e4     NOT        this
    //         0040b2e6     DEC        this
    //         0040b2e7     MOV        dword ptr [ESP + tempFloat],this
    //         0040b2eb     LEA        this=>tempFloat,[ESP + 0x14]
    //         0040b2ef     PUSH       this
    //         0040b2f0     PUSH       EBX
    //         0040b2f1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:226 (22)
    //         0040b2f6     MOV        EDX,dword ptr [ESP + tempFloat]
    //         0040b2fa     ADD        ESP,0xc
    //         0040b2fd     LEA        EAX=>tempString[4],[ESP + 0x24]
    //         0040b301     PUSH       EDX
    //         0040b302     PUSH       EAX
    //         0040b303     PUSH       EBX
    //         0040b304     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b309     ADD        ESP,0xc
    //                              aiconmod.cpp:227 (7)
    //         0040b30c     MOV        this,EBP
    //         0040b30e     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //                              aiconmod.cpp:228 (20)
    //         0040b313     LEA        this=>tempFloat,[ESP + 0x10]
    //         0040b317     PUSH       0x4
    //         0040b319     PUSH       this
    //         0040b31a     PUSH       EBX
    //         0040b31b     MOV        dword ptr [ESP + tempFloat],EAX
    //         0040b31f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b324     ADD        ESP,0xc
    //                              aiconmod.cpp:229 (7)
    //         0040b327     MOV        this,EBP
    //         0040b329     CALL       BaseItem::gameID                                 int gameID(BaseItem * this)
    //                              aiconmod.cpp:230 (20)
    //         0040b32e     LEA        EDX=>tempFloat,[ESP + 0x10]
    //         0040b332     PUSH       0x4
    //         0040b334     PUSH       EDX
    //         0040b335     PUSH       EBX
    //         0040b336     MOV        dword ptr [ESP + tempFloat],EAX
    //         0040b33a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b33f     ADD        ESP,0xc
    //                              aiconmod.cpp:231 (11)
    //         0040b342     MOV        this,EBP
    //         0040b344     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         0040b349     MOV        dword ptr [ESP + tempFloat],EAX
    //                              aiconmod.cpp:232 (16)
    //         0040b34d     LEA        EAX=>tempFloat,[ESP + 0x10]
    //         0040b351     PUSH       0x4
    //         0040b353     PUSH       EAX
    //         0040b354     PUSH       EBX
    //         0040b355     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b35a     ADD        ESP,0xc
    //                              aiconmod.cpp:233 (11)
    //         0040b35d     MOV        this,EBP
    //         0040b35f     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040b364     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:234 (16)
    //         0040b368     LEA        this=>tempBOOL,[ESP + 0x14]
    //         0040b36c     PUSH       0x4
    //         0040b36e     PUSH       this
    //         0040b36f     PUSH       EBX
    //         0040b370     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b375     ADD        ESP,0xc
    //                              aiconmod.cpp:235 (11)
    //         0040b378     MOV        this,EBP
    //         0040b37a     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040b37f     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:236 (16)
    //         0040b383     LEA        EDX=>tempBOOL,[ESP + 0x14]
    //         0040b387     PUSH       0x4
    //         0040b389     PUSH       EDX
    //         0040b38a     PUSH       EBX
    //         0040b38b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b390     ADD        ESP,0xc
    //                              aiconmod.cpp:237 (11)
    //         0040b393     MOV        this,EBP
    //         0040b395     CALL       BaseItem::z                                      float z(BaseItem * this)
    //         0040b39a     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:238 (16)
    //         0040b39e     LEA        EAX=>tempBOOL,[ESP + 0x14]
    //         0040b3a2     PUSH       0x4
    //         0040b3a4     PUSH       EAX
    //         0040b3a5     PUSH       EBX
    //         0040b3a6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b3ab     ADD        ESP,0xc
    //                              aiconmod.cpp:239 (11)
    //         0040b3ae     MOV        this,EBP
    //         0040b3b0     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
    //         0040b3b5     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:240 (16)
    //         0040b3b9     LEA        this=>tempBOOL,[ESP + 0x14]
    //         0040b3bd     PUSH       0x4
    //         0040b3bf     PUSH       this
    //         0040b3c0     PUSH       EBX
    //         0040b3c1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b3c6     ADD        ESP,0xc
    //                              aiconmod.cpp:241 (11)
    //         0040b3c9     MOV        this,EBP
    //         0040b3cb     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
    //         0040b3d0     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:242 (16)
    //         0040b3d4     LEA        EDX=>tempBOOL,[ESP + 0x14]
    //         0040b3d8     PUSH       0x4
    //         0040b3da     PUSH       EDX
    //         0040b3db     PUSH       EBX
    //         0040b3dc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b3e1     ADD        ESP,0xc
    //                              aiconmod.cpp:243 (11)
    //         0040b3e4     MOV        this,EBP
    //         0040b3e6     CALL       BaseItem::zSize                                  float zSize(BaseItem * this)
    //         0040b3eb     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:244 (16)
    //         0040b3ef     LEA        EAX=>tempBOOL,[ESP + 0x14]
    //         0040b3f3     PUSH       0x4
    //         0040b3f5     PUSH       EAX
    //         0040b3f6     PUSH       EBX
    //         0040b3f7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b3fc     ADD        ESP,0xc
    //                              aiconmod.cpp:245 (7)
    //         0040b3ff     MOV        this,EBP
    //         0040b401     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //                              aiconmod.cpp:246 (20)
    //         0040b406     LEA        this=>local_110,[ESP + 0x18]
    //         0040b40a     PUSH       0x4
    //         0040b40c     PUSH       this
    //         0040b40d     PUSH       EBX
    //         0040b40e     MOV        dword ptr [ESP + local_110],EAX
    //         0040b412     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b417     ADD        ESP,0xc
    //                              aiconmod.cpp:249 (7)
    //         0040b41a     MOV        this,EBP
    //         0040b41c     CALL       ConstructionItem::inProgress                     int inProgress(ConstructionItem * this)
    //                              aiconmod.cpp:250 (20)
    //         0040b421     LEA        EDX=>local_110,[ESP + 0x18]
    //         0040b425     PUSH       0x4
    //         0040b427     PUSH       EDX
    //         0040b428     PUSH       EBX
    //         0040b429     MOV        dword ptr [ESP + local_110],EAX
    //         0040b42d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b432     ADD        ESP,0xc
    //                              aiconmod.cpp:251 (11)
    //         0040b435     MOV        this,EBP
    //         0040b437     CALL       ConstructionItem::built                          int built(ConstructionItem * this)
    //         0040b43c     MOV        dword ptr [ESP + local_110],EAX
    //                              aiconmod.cpp:252 (16)
    //         0040b440     LEA        EAX=>local_110,[ESP + 0x18]
    //         0040b444     PUSH       0x4
    //         0040b446     PUSH       EAX
    //         0040b447     PUSH       EBX
    //         0040b448     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b44d     ADD        ESP,0xc
    //                              aiconmod.cpp:253 (7)
    //         0040b450     MOV        this,EBP
    //         0040b452     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
    //                              aiconmod.cpp:254 (17)
    //         0040b457     LEA        this=>tempFloat,[ESP + 0x10]
    //         0040b45b     PUSH       0x4
    //         0040b45d     PUSH       this
    //         0040b45e     PUSH       EBX
    //         0040b45f     MOV        dword ptr [ESP + tempFloat],EAX
    //         0040b463     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:257 (18)
    //         0040b468     MOV        EBP,dword ptr [EBP + 0x6c]
    //         0040b46b     MOV        EAX,dword ptr [ESP + local_10c]
    //         0040b46f     ADD        ESP,0xc
    //         0040b472     CMP        EBP,EAX
    //         0040b474     JNZ        LAB_0040b2a5
    //                               LAB_0040b47a                                                 XREF[2]:     0040b29f(j), 0040b2a7(j)  
    //                              aiconmod.cpp:260 (19)
    //         0040b47a     MOV        ESI,dword ptr [ESP + tempString[0]]
    //         0040b47e     PUSH       0x4
    //         0040b480     LEA        EDX,[ESI + 0x174]
    //         0040b486     PUSH       EDX
    //         0040b487     PUSH       EBX
    //         0040b488     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:261 (6)
    //         0040b48d     MOV        EBP,dword ptr [ESI + 0x1e4]
    //                              aiconmod.cpp:262 (29)
    //         0040b493     LEA        EAX,[ESI + 0x178]
    //         0040b499     ADD        ESP,0xc
    //         0040b49c     CMP        EBP,EAX
    //         0040b49e     MOV        dword ptr [ESP + local_10c],EAX
    //         0040b4a2     JZ         LAB_0040b67d
    //                               LAB_0040b4a8                                                 XREF[1]:     0040b677(j)  
    //         0040b4a8     TEST       EBP,EBP
    //         0040b4aa     JZ         LAB_0040b67d
    //                              aiconmod.cpp:264 (24)
    //         0040b4b0     MOV        this,EBP
    //         0040b4b2     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         0040b4b7     MOV        EDI,EAX
    //         0040b4b9     OR         this,0xffffffff
    //         0040b4bc     XOR        EAX,EAX
    //         0040b4be     LEA        EDX=>tempString[4],[ESP + 0x24]
    //         0040b4c2     SCASB.RE   ES:EDI
    //         0040b4c4     NOT        this
    //         0040b4c6     SUB        EDI,this
    //                              aiconmod.cpp:266 (49)
    //         0040b4c8     PUSH       0x4
    //         0040b4ca     MOV        EAX,this
    //         0040b4cc     MOV        ESI,EDI
    //         0040b4ce     MOV        EDI,EDX
    //         0040b4d0     SHR        this,0x2
    //         0040b4d3     MOVSD.REP  ES:EDI,ESI
    //         0040b4d5     MOV        this,EAX
    //         0040b4d7     XOR        EAX,EAX
    //         0040b4d9     AND        this,0x3
    //         0040b4dc     MOVSB.REP  ES:EDI,ESI
    //         0040b4de     LEA        EDI=>tempString[4],[ESP + 0x28]
    //         0040b4e2     OR         this,0xffffffff
    //         0040b4e5     SCASB.RE   ES:EDI
    //         0040b4e7     NOT        this
    //         0040b4e9     DEC        this
    //         0040b4ea     MOV        dword ptr [ESP + tempFloat],this
    //         0040b4ee     LEA        this=>tempFloat,[ESP + 0x14]
    //         0040b4f2     PUSH       this
    //         0040b4f3     PUSH       EBX
    //         0040b4f4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:267 (22)
    //         0040b4f9     MOV        EDX,dword ptr [ESP + tempFloat]
    //         0040b4fd     ADD        ESP,0xc
    //         0040b500     LEA        EAX=>tempString[4],[ESP + 0x24]
    //         0040b504     PUSH       EDX
    //         0040b505     PUSH       EAX
    //         0040b506     PUSH       EBX
    //         0040b507     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b50c     ADD        ESP,0xc
    //                              aiconmod.cpp:268 (7)
    //         0040b50f     MOV        this,EBP
    //         0040b511     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //                              aiconmod.cpp:269 (20)
    //         0040b516     LEA        this=>tempFloat,[ESP + 0x10]
    //         0040b51a     PUSH       0x4
    //         0040b51c     PUSH       this
    //         0040b51d     PUSH       EBX
    //         0040b51e     MOV        dword ptr [ESP + tempFloat],EAX
    //         0040b522     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b527     ADD        ESP,0xc
    //                              aiconmod.cpp:270 (7)
    //         0040b52a     MOV        this,EBP
    //         0040b52c     CALL       BaseItem::gameID                                 int gameID(BaseItem * this)
    //                              aiconmod.cpp:271 (20)
    //         0040b531     LEA        EDX=>tempFloat,[ESP + 0x10]
    //         0040b535     PUSH       0x4
    //         0040b537     PUSH       EDX
    //         0040b538     PUSH       EBX
    //         0040b539     MOV        dword ptr [ESP + tempFloat],EAX
    //         0040b53d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b542     ADD        ESP,0xc
    //                              aiconmod.cpp:272 (11)
    //         0040b545     MOV        this,EBP
    //         0040b547     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         0040b54c     MOV        dword ptr [ESP + tempFloat],EAX
    //                              aiconmod.cpp:273 (16)
    //         0040b550     LEA        EAX=>tempFloat,[ESP + 0x10]
    //         0040b554     PUSH       0x4
    //         0040b556     PUSH       EAX
    //         0040b557     PUSH       EBX
    //         0040b558     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b55d     ADD        ESP,0xc
    //                              aiconmod.cpp:274 (11)
    //         0040b560     MOV        this,EBP
    //         0040b562     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040b567     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:275 (16)
    //         0040b56b     LEA        this=>tempBOOL,[ESP + 0x14]
    //         0040b56f     PUSH       0x4
    //         0040b571     PUSH       this
    //         0040b572     PUSH       EBX
    //         0040b573     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b578     ADD        ESP,0xc
    //                              aiconmod.cpp:276 (11)
    //         0040b57b     MOV        this,EBP
    //         0040b57d     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040b582     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:277 (16)
    //         0040b586     LEA        EDX=>tempBOOL,[ESP + 0x14]
    //         0040b58a     PUSH       0x4
    //         0040b58c     PUSH       EDX
    //         0040b58d     PUSH       EBX
    //         0040b58e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b593     ADD        ESP,0xc
    //                              aiconmod.cpp:278 (11)
    //         0040b596     MOV        this,EBP
    //         0040b598     CALL       BaseItem::z                                      float z(BaseItem * this)
    //         0040b59d     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:279 (16)
    //         0040b5a1     LEA        EAX=>tempBOOL,[ESP + 0x14]
    //         0040b5a5     PUSH       0x4
    //         0040b5a7     PUSH       EAX
    //         0040b5a8     PUSH       EBX
    //         0040b5a9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b5ae     ADD        ESP,0xc
    //                              aiconmod.cpp:280 (11)
    //         0040b5b1     MOV        this,EBP
    //         0040b5b3     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
    //         0040b5b8     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:281 (16)
    //         0040b5bc     LEA        this=>tempBOOL,[ESP + 0x14]
    //         0040b5c0     PUSH       0x4
    //         0040b5c2     PUSH       this
    //         0040b5c3     PUSH       EBX
    //         0040b5c4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b5c9     ADD        ESP,0xc
    //                              aiconmod.cpp:282 (11)
    //         0040b5cc     MOV        this,EBP
    //         0040b5ce     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
    //         0040b5d3     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:283 (16)
    //         0040b5d7     LEA        EDX=>tempBOOL,[ESP + 0x14]
    //         0040b5db     PUSH       0x4
    //         0040b5dd     PUSH       EDX
    //         0040b5de     PUSH       EBX
    //         0040b5df     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b5e4     ADD        ESP,0xc
    //                              aiconmod.cpp:284 (11)
    //         0040b5e7     MOV        this,EBP
    //         0040b5e9     CALL       BaseItem::zSize                                  float zSize(BaseItem * this)
    //         0040b5ee     FSTP       float ptr [ESP + tempBOOL]
    //                              aiconmod.cpp:285 (16)
    //         0040b5f2     LEA        EAX=>tempBOOL,[ESP + 0x14]
    //         0040b5f6     PUSH       0x4
    //         0040b5f8     PUSH       EAX
    //         0040b5f9     PUSH       EBX
    //         0040b5fa     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b5ff     ADD        ESP,0xc
    //                              aiconmod.cpp:286 (7)
    //         0040b602     MOV        this,EBP
    //         0040b604     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //                              aiconmod.cpp:287 (20)
    //         0040b609     LEA        this=>local_110,[ESP + 0x18]
    //         0040b60d     PUSH       0x4
    //         0040b60f     PUSH       this
    //         0040b610     PUSH       EBX
    //         0040b611     MOV        dword ptr [ESP + local_110],EAX
    //         0040b615     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b61a     ADD        ESP,0xc
    //                              aiconmod.cpp:290 (7)
    //         0040b61d     MOV        this,EBP
    //         0040b61f     CALL       ConstructionItem::inProgress                     int inProgress(ConstructionItem * this)
    //                              aiconmod.cpp:291 (20)
    //         0040b624     LEA        EDX=>local_110,[ESP + 0x18]
    //         0040b628     PUSH       0x4
    //         0040b62a     PUSH       EDX
    //         0040b62b     PUSH       EBX
    //         0040b62c     MOV        dword ptr [ESP + local_110],EAX
    //         0040b630     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b635     ADD        ESP,0xc
    //                              aiconmod.cpp:292 (11)
    //         0040b638     MOV        this,EBP
    //         0040b63a     CALL       ConstructionItem::built                          int built(ConstructionItem * this)
    //         0040b63f     MOV        dword ptr [ESP + local_110],EAX
    //                              aiconmod.cpp:293 (16)
    //         0040b643     LEA        EAX=>local_110,[ESP + 0x18]
    //         0040b647     PUSH       0x4
    //         0040b649     PUSH       EAX
    //         0040b64a     PUSH       EBX
    //         0040b64b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040b650     ADD        ESP,0xc
    //                              aiconmod.cpp:294 (7)
    //         0040b653     MOV        this,EBP
    //         0040b655     CALL       ConstructionItem::buildAttempts                  int buildAttempts(ConstructionItem * this)
    //                              aiconmod.cpp:295 (17)
    //         0040b65a     LEA        this=>tempFloat,[ESP + 0x10]
    //         0040b65e     PUSH       0x4
    //         0040b660     PUSH       this
    //         0040b661     PUSH       EBX
    //         0040b662     MOV        dword ptr [ESP + tempFloat],EAX
    //         0040b666     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aiconmod.cpp:298 (18)
    //         0040b66b     MOV        EBP,dword ptr [EBP + 0x6c]
    //         0040b66e     MOV        EAX,dword ptr [ESP + local_10c]
    //         0040b672     ADD        ESP,0xc
    //         0040b675     CMP        EBP,EAX
    //         0040b677     JNZ        LAB_0040b4a8
    //                               LAB_0040b67d                                                 XREF[2]:     0040b4a2(j), 0040b4aa(j)  
    //                              aiconmod.cpp:302 (18)
    //         0040b67d     POP        EDI
    //         0040b67e     POP        ESI
    //         0040b67f     POP        EBP
    //         0040b680     MOV        EAX,0x1
    //         0040b685     POP        EBX
    //         0040b686     ADD        ESP,0x118
    //         0040b68c     RET        0x4
}

// Offset: 0x0040B690
int ConstructionAIModule::loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall ConstructionAIModule::loadConstructionPlan(char *,int,int,float,flo... *
    //                              *********************************************************************************************************
    //                              int __thiscall loadConstructionPlan(ConstructionAIModule * this, cha
    //              int               EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040b6ee(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040b6cc(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040b6c4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0040b6af(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0040b6bb(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     0040b69e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040b866(W), 0040b8ac(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040b950(R)  
    //              char[256]         Stack[-0x110   temp                      XREF[0,6]:   0040b75a(*), 0040b76d(*), 0040b78a(*), 0040b7b0(*), 
    //                                                                                     0040b7ff(*), 0040b8d3(*)  
    //              char[64]          Stack[-0x150   name                      XREF[1,2]:   0040b860(W), 0040b7d7(*), 0040b877(*)  
    //              undefined4        Stack[-0x154   local_154                 XREF[2]:     0040b7e5(*), 0040b881(R)  
    //              float             Stack[-0x158   ySize                     XREF[2]:     0040b7ea(*), 0040b886(R)  
    //              float             Stack[-0x15c   xSize                     XREF[2]:     0040b7db(*), 0040b873(R)  
    //              int               Stack[-0x160   id                        XREF[2]:     0040b6ff(W), 0040b8ed(R)  
    //              undefined4        Stack[-0x164   local_164                 XREF[2]:     0040b7e0(*), 0040b87c(R)  
    //              float             Stack[-0x168   zSize                     XREF[4]:     0040b7ef(*), 0040b83a(R), 0040b846(W), 0040b88b(R)  
    //              float             Stack[-0x16c   z                         XREF[5]:     0040b7f9(*), 0040b817(R), 0040b81e(W), 0040b82c(R), 
    //                                                                                     0040b895(R)  
    //              float             Stack[-0x170   x                         XREF[5]:     0040b7f4(*), 0040b828(R), 0040b830(W), 0040b83e(R), 
    //                                                                                     0040b890(R)  
    //              float             Stack[-0x174   y                         XREF[0,4]:   0040b7aa(*), 0040b7c2(R), 0040b7a6(*), 0040b7cd(R)  
    //              char              Stack[-0x175   commentTemp2
    //              char              Stack[-0x176   commentTemp1
    //                               ?loadConstructionPlan@ConstructionAIModule@@UAEHPADHHMMM@Z   XREF[2]:     0056e7e0(*), 005754e0(*)  
    //                               ConstructionAIModule::loadConstructionPlan
    //                              aiconmod.cpp:308 (14)
    //         0040b690     MOV        EAX,FS:[0x0]
    //         0040b696     PUSH       -0x1
    //         0040b698     PUSH       FUN_0055c5de
    //         0040b69d     PUSH       EAX
    //                              aiconmod.cpp:309 (63)
    //         0040b69e     MOV        EAX,dword ptr [ESP + param_6]
    //         0040b6a2     MOV        dword ptr FS:[0x0],ESP
    //         0040b6a9     SUB        ESP,0x168
    //         0040b6af     MOV        EDX,dword ptr [ESP + param_4]
    //         0040b6b6     PUSH       EBX
    //         0040b6b7     PUSH       EBP
    //         0040b6b8     MOV        EBP,this
    //         0040b6ba     PUSH       ESI
    //         0040b6bb     MOV        this,dword ptr [ESP + param_5]
    //         0040b6c2     PUSH       EDI
    //         0040b6c3     PUSH       EAX
    //         0040b6c4     MOV        EAX,dword ptr [ESP + param_3]
    //         0040b6cb     PUSH       this
    //         0040b6cc     MOV        this,dword ptr [ESP + param_2]
    //         0040b6d3     PUSH       EDX
    //         0040b6d4     PUSH       EAX
    //         0040b6d5     PUSH       this
    //         0040b6d6     MOV        this,EBP
    //         0040b6d8     CALL       ConstructionAIModule::setReferencePoint          void setReferencePoint(ConstructionAIModule *
    //                              aiconmod.cpp:312 (10)
    //         0040b6dd     MOV        EAX,dword ptr [EBP + 0xf0]
    //         0040b6e3     TEST       EAX,EAX
    //         0040b6e5     JLE        LAB_0040b6ee
    //                              aiconmod.cpp:313 (7)
    //         0040b6e7     MOV        this,EBP
    //         0040b6e9     CALL       ConstructionAIModule::removeOldLots              void removeOldLots(ConstructionAIModule * this)
    //                               LAB_0040b6ee                                                 XREF[1]:     0040b6e5(j)  
    //                              aiconmod.cpp:317 (29)
    //         0040b6ee     MOV        EDI,dword ptr [ESP + param_1]
    //         0040b6f5     LEA        EBX,[EBP + 0x1f8]
    //         0040b6fb     PUSH       0x3f
    //         0040b6fd     PUSH       EDI
    //         0040b6fe     PUSH       EBX
    //         0040b6ff     MOV        dword ptr [ESP + id],EBX
    //         0040b703     CALL       strncpy                                          undefined strncpy()
    //         0040b708     ADD        ESP,0xc
    //                              aiconmod.cpp:319 (64)
    //         0040b70b     MOV        ESI,s_NONE                                       = 4Eh
    //         0040b710     MOV        EAX,EBX
    //                               LAB_0040b712                                                 XREF[1]:     0040b730(j)  
    //         0040b712     MOV        DL,byte ptr [EAX]
    //         0040b714     MOV        this,DL
    //         0040b716     CMP        DL,byte ptr [ESI]=>s_NONE                        = 4Eh
    //         0040b718     JNZ        LAB_0040b736
    //         0040b71a     TEST       this,this
    //         0040b71c     JZ         LAB_0040b732
    //         0040b71e     MOV        DL,byte ptr [EAX + 0x1]
    //         0040b721     MOV        this,DL
    //         0040b723     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0057f351            = 4Fh
    //                                                                                  = 45h
    //         0040b726     JNZ        LAB_0040b736
    //         0040b728     ADD        EAX,0x2
    //         0040b72b     ADD        ESI,0x2
    //         0040b72e     TEST       this,this
    //         0040b730     JNZ        LAB_0040b712
    //                               LAB_0040b732                                                 XREF[1]:     0040b71c(j)  
    //         0040b732     XOR        EAX,EAX
    //         0040b734     JMP        LAB_0040b73b
    //                               LAB_0040b736                                                 XREF[2]:     0040b718(j), 0040b726(j)  
    //         0040b736     SBB        EAX,EAX
    //         0040b738     SBB        EAX,-0x1
    //                               LAB_0040b73b                                                 XREF[1]:     0040b734(j)  
    //         0040b73b     TEST       EAX,EAX
    //         0040b73d     JZ         LAB_0040b917
    //         0040b743     TEST       EBX,EBX
    //         0040b745     JZ         LAB_0040b91b
    //                              aiconmod.cpp:325 (15)
    //         0040b74b     PUSH       EDI
    //         0040b74c     PUSH       s_Loading_construction_plan_in_fil               = "Loading construction plan in file '%s'."
    //         0040b751     PUSH       EBP
    //         0040b752     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0040b757     ADD        ESP,0xc
    //                              aiconmod.cpp:327 (19)
    //         0040b75a     LEA        EAX=>temp[4],[ESP + 0x78]
    //         0040b75e     PUSH       EBX
    //         0040b75f     PUSH       s_%s                                             = "%s"
    //         0040b764     PUSH       EAX
    //         0040b765     CALL       sprintf                                          undefined sprintf()
    //         0040b76a     ADD        ESP,0xc
    //                              aiconmod.cpp:328 (20)
    //         0040b76d     LEA        this=>temp[4],[ESP + 0x78]
    //         0040b771     PUSH       s_r                                              = "r"
    //         0040b776     PUSH       this
    //         0040b777     CALL       fopen                                            undefined fopen()
    //         0040b77c     MOV        ESI,EAX
    //         0040b77e     ADD        ESP,0x8
    //                              aiconmod.cpp:329 (8)
    //         0040b781     TEST       ESI,ESI
    //         0040b783     JZ         LAB_0040b950
    //                              aiconmod.cpp:332 (29)
    //         0040b789     PUSH       ESI
    //         0040b78a     LEA        EDX=>temp[4],[ESP + 0x7c]
    //         0040b78e     PUSH       0x100
    //         0040b793     PUSH       EDX
    //         0040b794     CALL       fgets                                            undefined fgets()
    //         0040b799     ADD        ESP,0xc
    //         0040b79c     TEST       EAX,EAX
    //         0040b79e     JZ         LAB_0040b8f1
    //         0040b7a4     MOV        BL,0x2f
    //                               LAB_0040b7a6                                                 XREF[1]:     0040b8e7(j)  
    //                              aiconmod.cpp:345 (28)
    //         0040b7a6     LEA        EAX=>y+0x3,[ESP + 0x13]
    //         0040b7aa     LEA        this=>y+0x2,[ESP + 0x12]
    //         0040b7ae     PUSH       EAX
    //         0040b7af     PUSH       this
    //         0040b7b0     LEA        EDX=>temp[4],[ESP + 0x80]
    //         0040b7b7     PUSH       s__%c%c                                          = " %c%c"
    //         0040b7bc     PUSH       EDX
    //         0040b7bd     CALL       sscanf                                           undefined sscanf()
    //                              aiconmod.cpp:346 (21)
    //         0040b7c2     MOV        AL,byte ptr [ESP + y+0x2]
    //         0040b7c6     ADD        ESP,0x10
    //         0040b7c9     CMP        AL,BL
    //         0040b7cb     JNZ        LAB_0040b7d7
    //         0040b7cd     CMP        byte ptr [ESP + y+0x3],BL
    //         0040b7d1     JZ         LAB_0040b8d2
    //                               LAB_0040b7d7                                                 XREF[1]:     0040b7cb(j)  
    //                              aiconmod.cpp:350 (58)
    //         0040b7d7     LEA        EAX=>name[4],[ESP + 0x38]
    //         0040b7db     LEA        this=>xSize,[ESP + 0x28]
    //         0040b7df     PUSH       EAX
    //         0040b7e0     LEA        EDX=>local_164,[ESP + 0x24]
    //         0040b7e4     PUSH       this
    //         0040b7e5     LEA        EAX=>local_154,[ESP + 0x38]
    //         0040b7e9     PUSH       EDX
    //         0040b7ea     LEA        this=>ySize,[ESP + 0x38]
    //         0040b7ee     PUSH       EAX
    //         0040b7ef     LEA        EDX=>zSize,[ESP + 0x2c]
    //         0040b7f3     PUSH       this
    //         0040b7f4     LEA        EAX=>x,[ESP + 0x28]
    //         0040b7f8     PUSH       EDX
    //         0040b7f9     LEA        this=>z,[ESP + 0x30]
    //         0040b7fd     PUSH       EAX
    //         0040b7fe     PUSH       this
    //         0040b7ff     LEA        EDX=>temp[4],[ESP + 0x98]
    //         0040b806     PUSH       s_%f_%f_%f_%f_%f_%f_%d_%s_                       = "%f %f %f %f %f %f %d %s "
    //         0040b80b     PUSH       EDX
    //         0040b80c     CALL       sscanf                                           undefined sscanf()
    //                              aiconmod.cpp:354 (17)
    //         0040b811     FLD        float ptr [EBP + 0x2fc]
    //         0040b817     FADD       float ptr [ESP + z]
    //         0040b81b     ADD        ESP,0x28
    //         0040b81e     FSTP       float ptr [ESP + z]
    //                              aiconmod.cpp:355 (10)
    //         0040b822     FLD        float ptr [EBP + 0x300]
    //         0040b828     FADD       float ptr [ESP + x]
    //                              aiconmod.cpp:358 (39)
    //         0040b82c     MOV        this,dword ptr [ESP + z]
    //         0040b830     FSTP       float ptr [ESP + x]
    //         0040b834     FLD        float ptr [EBP + 0x304]
    //         0040b83a     FADD       float ptr [ESP + zSize]
    //         0040b83e     MOV        EAX,dword ptr [ESP + x]
    //         0040b842     PUSH       EAX
    //         0040b843     PUSH       this
    //         0040b844     MOV        this,EBP
    //         0040b846     FSTP       float ptr [ESP + zSize]
    //         0040b84a     CALL       ConstructionAIModule::lot                        ConstructionItem * lot(ConstructionAIModule *
    //         0040b84f     TEST       EAX,EAX
    //         0040b851     JNZ        LAB_0040b8d2
    //                              language.dll match for 0x80: "Arial"
    //                              aiconmod.cpp:366 (83)
    //         0040b853     PUSH       0x80
    //         0040b858     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040b85d     ADD        ESP,0x4
    //         0040b860     MOV        dword ptr [ESP + name[0]],EAX
    //         0040b864     TEST       EAX,EAX
    //         0040b866     MOV        dword ptr [ESP + local_4],0x0
    //         0040b871     JZ         LAB_0040b8a4
    //         0040b873     MOV        this,dword ptr [ESP + xSize]
    //         0040b877     LEA        EDX=>name[4],[ESP + 0x38]
    //         0040b87b     PUSH       EDX
    //         0040b87c     MOV        EDX,dword ptr [ESP + local_164]
    //         0040b880     PUSH       this
    //         0040b881     MOV        this,dword ptr [ESP + local_154]
    //         0040b885     PUSH       EDX
    //         0040b886     MOV        EDX,dword ptr [ESP + ySize]
    //         0040b88a     PUSH       this
    //         0040b88b     MOV        this,dword ptr [ESP + zSize]
    //         0040b88f     PUSH       EDX
    //         0040b890     MOV        EDX,dword ptr [ESP + x]
    //         0040b894     PUSH       this
    //         0040b895     MOV        this,dword ptr [ESP + z]
    //         0040b899     PUSH       EDX
    //         0040b89a     PUSH       this
    //         0040b89b     MOV        this,EAX
    //         0040b89d     CALL       ConstructionItem::ConstructionItem               undefined ConstructionItem(ConstructionItem *
    //         0040b8a2     JMP        LAB_0040b8a6
    //                               LAB_0040b8a4                                                 XREF[1]:     0040b871(j)  
    //         0040b8a4     XOR        EAX,EAX
    //                               LAB_0040b8a6                                                 XREF[1]:     0040b8a2(j)  
    //                              aiconmod.cpp:369 (20)
    //         0040b8a6     LEA        EDX,[EBP + 0xf4]
    //         0040b8ac     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0040b8b7     MOV        dword ptr [EAX + 0x6c],EDX
    //                              aiconmod.cpp:370 (9)
    //         0040b8ba     MOV        this,dword ptr [EBP + 0x164]
    //         0040b8c0     MOV        dword ptr [EAX + 0x70],this
    //                              aiconmod.cpp:371 (3)
    //         0040b8c3     MOV        dword ptr [ECX + this->_padding_],EAX
    //                              aiconmod.cpp:372 (6)
    //         0040b8c6     MOV        dword ptr [EBP + 0x164],EAX
    //                              aiconmod.cpp:373 (33)
    //         0040b8cc     INC        dword ptr [EBP + 0xf0]
    //                               LAB_0040b8d2                                                 XREF[2]:     0040b7d1(j), 0040b851(j)  
    //         0040b8d2     PUSH       ESI
    //         0040b8d3     LEA        EAX=>temp[4],[ESP + 0x7c]
    //         0040b8d7     PUSH       0x100
    //         0040b8dc     PUSH       EAX
    //         0040b8dd     CALL       fgets                                            undefined fgets()
    //         0040b8e2     ADD        ESP,0xc
    //         0040b8e5     TEST       EAX,EAX
    //         0040b8e7     JNZ        LAB_0040b7a6
    //                              aiconmod.cpp:332 (4)
    //         0040b8ed     MOV        EBX,dword ptr [ESP + id]
    //                               LAB_0040b8f1                                                 XREF[1]:     0040b79e(j)  
    //                              aiconmod.cpp:375 (9)
    //         0040b8f1     PUSH       ESI
    //         0040b8f2     CALL       fclose                                           undefined fclose()
    //         0040b8f7     ADD        ESP,0x4
    //                              aiconmod.cpp:377 (18)
    //         0040b8fa     PUSH       s_.tmp                                           = ".tmp"
    //         0040b8ff     PUSH       EBX
    //         0040b900     CALL       strstr                                           undefined strstr()
    //         0040b905     ADD        ESP,0x8
    //         0040b908     TEST       EAX,EAX
    //         0040b90a     JZ         LAB_0040b94b
    //                              aiconmod.cpp:378 (9)
    //         0040b90c     PUSH       EBX
    //         0040b90d     CALL       __unlink                                         undefined __unlink()
    //         0040b912     ADD        ESP,0x4
    //                              aiconmod.cpp:379 (2)
    //         0040b915     JMP        LAB_0040b94b
    //                               LAB_0040b917                                                 XREF[1]:     0040b73d(j)  
    //                              aiconmod.cpp:320 (4)
    //         0040b917     TEST       EBX,EBX
    //         0040b919     JNZ        LAB_0040b93d
    //                               LAB_0040b91b                                                 XREF[1]:     0040b745(j)  
    //                              aiconmod.cpp:321 (34)
    //         0040b91b     MOV        EDI,s_NULL                                       = 4Eh
    //         0040b920     OR         this,0xffffffff
    //         0040b923     XOR        EAX,EAX
    //         0040b925     SCASB.RE   ES:EDI=>s_NULL                                   = 4Eh
    //                                                                                  = 55h
    //         0040b927     NOT        this
    //         0040b929     SUB        EDI,this
    //         0040b92b     MOV        EDX,this
    //         0040b92d     MOV        ESI,EDI
    //         0040b92f     XOR        EDI,EDI
    //         0040b931     SHR        this,0x2
    //         0040b934     MOVSD.REP  ES:EDI,ESI
    //         0040b936     MOV        this,EDX
    //         0040b938     AND        this,0x3
    //         0040b93b     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0040b93d                                                 XREF[1]:     0040b919(j)  
    //                              aiconmod.cpp:322 (14)
    //         0040b93d     PUSH       s_There_is_no_construction_plan_to               = "There is no construction plan to load."
    //         0040b942     PUSH       EBP
    //         0040b943     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0040b948     ADD        ESP,0x8
    //                               LAB_0040b94b                                                 XREF[2]:     0040b90a(j), 0040b915(j)  
    //                              aiconmod.cpp:323 (5)
    //         0040b94b     MOV        EAX,0x1
    //                               LAB_0040b950                                                 XREF[1]:     0040b783(j)  
    //                              aiconmod.cpp:380 (27)
    //         0040b950     MOV        this,dword ptr [ESP + local_c]
    //         0040b957     POP        EDI
    //         0040b958     POP        ESI
    //         0040b959     POP        EBP
    //         0040b95a     MOV        dword ptr FS:[0x0],this
    //         0040b961     POP        EBX
    //         0040b962     ADD        ESP,0x174
    //         0040b968     RET        0x18
}

// Offset: 0x0040B970
char* constructionPlanName(ConstructionAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall ConstructionAIModule::constructionPlanName(void)                            *
    //                              *********************************************************************************************************
    //                              char * __thiscall constructionPlanName(ConstructionAIModule * this)
    //              char *            EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //                               ?constructionPlanName@ConstructionAIModule@@QAEPADXZ         XREF[2]:     aiStatus:0051481a(c), 
    //                               ConstructionAIModule::constructionPlanName                                logStatus:00518fb4(c)  
    //                              aiconmod.cpp:385 (6)
    //         0040b970     LEA        EAX,[ECX + this->constructionPlanNameValue[0]]
    //                              aiconmod.cpp:387 (1)
    //         0040b976     RET
}

// Offset: 0x0040B980
void setReferencePoint(ConstructionAIModule* this_, int param_2, int param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall ConstructionAIModule::setReferencePoint(int,int,float,float,float)            *
    //                              *********************************************************************************************************
    //                              void __thiscall setReferencePoint(ConstructionAIModule * this, int p
    //              void              <VOID>         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[10]:    0040b984(R), 0040b9e2(R), 0040ba6d(W), 0040ba7e(R), 
    //                                                                                     0040ba9a(W), 0040baab(R), 0040bac3(W), 0040badf(R), 
    //                                                                                     0040baf7(W), 0040bb13(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[6]:     0040b995(R), 0040b9f5(R), 0040badb(W), 0040bae3(R), 
    //                                                                                     0040bb0f(W), 0040bb17(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[4]:     0040b980(R), 0040b991(R), 0040b9e6(R), 0040ba2b(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[4]:     0040b9a0(R), 0040b9cd(R), 0040b9f9(R), 0040ba41(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[2]:     0040b9b0(R), 0040ba57(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0040ba32(*), 0040ba48(*), 0040ba5e(*)  
    //                               ?setReferencePoint@ConstructionAIModule@@QAEXHHMMM@Z         XREF[2]:     loadConstructionPlan:0040b6d8(c), 
    //                               ConstructionAIModule::setReferencePoint                                   updateBuildAIWithObjects:004e6233(
    //                              aiconmod.cpp:393 (136)
    //         0040b980     FLD        float ptr [ESP + param_3]
    //         0040b984     MOV        EAX,dword ptr [ESP + param_1]
    //         0040b988     PUSH       EBX
    //         0040b989     FCOMP      double ptr [null_0056e800]                       = align(11)
    //         0040b98f     MOV        EBX,this
    //         0040b991     MOV        EDX,dword ptr [ESP + param_3]
    //         0040b995     MOV        this,dword ptr [ESP + param_2]
    //         0040b999     PUSH       EBP
    //         0040b99a     MOV        dword ptr [EBX + 0x308],EAX
    //         0040b9a0     MOV        EAX,dword ptr [ESP + param_4]
    //         0040b9a4     MOV        dword ptr [EBX + 0x300],EAX
    //         0040b9aa     MOV        dword ptr [EBX + 0x30c],this
    //         0040b9b0     MOV        this,dword ptr [ESP + param_5]
    //         0040b9b4     PUSH       ESI
    //         0040b9b5     FNSTSW     AX
    //         0040b9b7     PUSH       EDI
    //         0040b9b8     MOV        dword ptr [EBX + 0x2fc],EDX
    //         0040b9be     TEST       AH,0x41
    //         0040b9c1     MOV        dword ptr [EBX + 0x304],this
    //         0040b9c7     JNZ        LAB_0040bb61
    //         0040b9cd     FLD        float ptr [ESP + param_4]
    //         0040b9d1     FCOMP      double ptr [null_0056e800]                       = align(11)
    //         0040b9d7     FNSTSW     AX
    //         0040b9d9     TEST       AH,0x41
    //         0040b9dc     JNZ        LAB_0040bb61
    //         0040b9e2     FILD       dword ptr [ESP + param_1]
    //         0040b9e6     FCOMP      float ptr [ESP + param_3]
    //         0040b9ea     FNSTSW     AX
    //         0040b9ec     TEST       AH,0x41
    //         0040b9ef     JNZ        LAB_0040bb61
    //         0040b9f5     FILD       dword ptr [ESP + param_2]
    //         0040b9f9     FCOMP      float ptr [ESP + param_4]
    //         0040b9fd     FNSTSW     AX
    //         0040b9ff     TEST       AH,0x41
    //         0040ba02     JNZ        LAB_0040bb61
    //                              aiconmod.cpp:417 (6)
    //         0040ba08     MOV        ESI,dword ptr [EBX + 0x160]
    //                              aiconmod.cpp:418 (22)
    //         0040ba0e     LEA        EBP,[EBX + 0xf4]
    //         0040ba14     CMP        ESI,EBP
    //         0040ba16     JZ         LAB_0040bb68
    //                               LAB_0040ba1c                                                 XREF[1]:     0040bb54(j)  
    //         0040ba1c     TEST       ESI,ESI
    //         0040ba1e     JZ         LAB_0040bb68
    //                              aiconmod.cpp:419 (22)
    //         0040ba24     MOV        this,ESI
    //         0040ba26     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040ba2b     FADD       float ptr [ESP + param_3]
    //         0040ba2f     PUSH       this
    //         0040ba30     MOV        this,ESI
    //         0040ba32     FSTP       float ptr [ESP]=>local_14
    //         0040ba35     CALL       BaseItem::setX                                   void setX(BaseItem * this, float param_1)
    //                              aiconmod.cpp:420 (22)
    //         0040ba3a     MOV        this,ESI
    //         0040ba3c     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040ba41     FADD       float ptr [ESP + param_4]
    //         0040ba45     PUSH       this
    //         0040ba46     MOV        this,ESI
    //         0040ba48     FSTP       float ptr [ESP]=>local_14
    //         0040ba4b     CALL       BaseItem::setY                                   void setY(BaseItem * this, float param_1)
    //                              aiconmod.cpp:421 (22)
    //         0040ba50     MOV        this,ESI
    //         0040ba52     CALL       BaseItem::z                                      float z(BaseItem * this)
    //         0040ba57     FADD       float ptr [ESP + param_5]
    //         0040ba5b     PUSH       this
    //         0040ba5c     MOV        this,ESI
    //         0040ba5e     FSTP       float ptr [ESP]=>local_14
    //         0040ba61     CALL       BaseItem::setZ                                   void setZ(BaseItem * this, float param_1)
    //                              aiconmod.cpp:428 (190)
    //         0040ba66     MOV        this,ESI
    //         0040ba68     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040ba6d     FSTP       float ptr [ESP + param_1]
    //         0040ba71     MOV        this,ESI
    //         0040ba73     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
    //         0040ba78     FMUL       float ptr [null_0056e808]                        = align(3)
    //         0040ba7e     FSUBR      float ptr [ESP + param_1]
    //         0040ba82     FCOMP      float ptr [DAT_0056e80c]
    //         0040ba88     FNSTSW     AX
    //         0040ba8a     TEST       AH,0x1
    //         0040ba8d     JNZ        LAB_0040bb29
    //         0040ba93     MOV        this,ESI
    //         0040ba95     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040ba9a     FSTP       float ptr [ESP + param_1]
    //         0040ba9e     MOV        this,ESI
    //         0040baa0     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
    //         0040baa5     FMUL       float ptr [null_0056e808]                        = align(3)
    //         0040baab     FSUBR      float ptr [ESP + param_1]
    //         0040baaf     FCOMP      float ptr [DAT_0056e80c]
    //         0040bab5     FNSTSW     AX
    //         0040bab7     TEST       AH,0x1
    //         0040baba     JNZ        LAB_0040bb29
    //         0040babc     MOV        this,ESI
    //         0040babe     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040bac3     FSTP       float ptr [ESP + param_1]
    //         0040bac7     MOV        this,ESI
    //         0040bac9     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
    //         0040bace     MOV        EDX,dword ptr [EBX + 0x308]
    //         0040bad4     FMUL       float ptr [DAT_0056e810]
    //         0040bada     DEC        EDX
    //         0040badb     MOV        dword ptr [ESP + param_2],EDX
    //         0040badf     FSUBR      float ptr [ESP + param_1]
    //         0040bae3     FILD       dword ptr [ESP + param_2]
    //         0040bae7     FCOMPP
    //         0040bae9     FNSTSW     AX
    //         0040baeb     TEST       AH,0x1
    //         0040baee     JNZ        LAB_0040bb29
    //         0040baf0     MOV        this,ESI
    //         0040baf2     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040baf7     FSTP       float ptr [ESP + param_1]
    //         0040bafb     MOV        this,ESI
    //         0040bafd     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
    //         0040bb02     MOV        EAX,dword ptr [EBX + 0x30c]
    //         0040bb08     FMUL       float ptr [DAT_0056e810]
    //         0040bb0e     DEC        EAX
    //         0040bb0f     MOV        dword ptr [ESP + param_2],EAX
    //         0040bb13     FSUBR      float ptr [ESP + param_1]
    //         0040bb17     FILD       dword ptr [ESP + param_2]
    //         0040bb1b     FCOMPP
    //         0040bb1d     FNSTSW     AX
    //         0040bb1f     TEST       AH,0x1
    //         0040bb22     JNZ        LAB_0040bb29
    //                              aiconmod.cpp:441 (5)
    //         0040bb24     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040bb27     JMP        LAB_0040bb52
    //                               LAB_0040bb29                                                 XREF[4]:     0040ba8d(j), 0040baba(j), 
    //                                                                                                         0040baee(j), 0040bb22(j)  
    //                              aiconmod.cpp:433 (6)
    //         0040bb29     MOV        this,dword ptr [EBX + 0xf0]
    //                              aiconmod.cpp:437 (33)
    //         0040bb2f     PUSH       0x1
    //         0040bb31     DEC        this
    //         0040bb32     MOV        dword ptr [EBX + 0xf0],this
    //         0040bb38     MOV        this,dword ptr [ESI + 0x70]
    //         0040bb3b     MOV        EDI,dword ptr [ESI + 0x6c]
    //         0040bb3e     MOV        dword ptr [ECX + this->_padding_],EDI
    //         0040bb41     MOV        EDX,dword ptr [ESI + 0x6c]
    //         0040bb44     MOV        EAX,dword ptr [ESI + 0x70]
    //         0040bb47     MOV        this,ESI
    //         0040bb49     MOV        dword ptr [EDX + 0x70],EAX
    //         0040bb4c     MOV        EDX,dword ptr [ESI]
    //         0040bb4e     CALL       dword ptr [EDX]
    //                              aiconmod.cpp:438 (2)
    //         0040bb50     MOV        ESI,EDI
    //                               LAB_0040bb52                                                 XREF[1]:     0040bb27(j)  
    //                              aiconmod.cpp:418 (8)
    //         0040bb52     CMP        ESI,EBP
    //         0040bb54     JNZ        LAB_0040ba1c
    //                              aiconmod.cpp:443 (7)
    //         0040bb5a     POP        EDI
    //         0040bb5b     POP        ESI
    //         0040bb5c     POP        EBP
    //         0040bb5d     POP        EBX
    //         0040bb5e     RET        0x14
    //                               LAB_0040bb61                                                 XREF[4]:     0040b9c7(j), 0040b9dc(j), 
    //                                                                                                         0040b9ef(j), 0040ba02(j)  
    //                              aiconmod.cpp:412 (7)
    //         0040bb61     MOV        this,EBX
    //         0040bb63     CALL       ConstructionAIModule::removeOldLots              void removeOldLots(ConstructionAIModule * this)
    //                               LAB_0040bb68                                                 XREF[2]:     0040ba16(j), 0040ba1e(j)  
    //                              aiconmod.cpp:443 (7)
    //         0040bb68     POP        EDI
    //         0040bb69     POP        ESI
    //         0040bb6a     POP        EBP
    //         0040bb6b     POP        EBX
    //         0040bb6c     RET        0x14
}

// Offset: 0x0040BB70
float xReferencePoint(ConstructionAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall ConstructionAIModule::xReferencePoint(void)                                  *
    //                              *********************************************************************************************************
    //                              float __thiscall xReferencePoint(ConstructionAIModule * this)
    //              float             ST0:10         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //                               ?xReferencePoint@ConstructionAIModule@@QAEMXZ
    //                               ConstructionAIModule::xReferencePoint
    //                              aiconmod.cpp:448 (6)
    //         0040bb70     FLD        float ptr [ECX + this->xReferencePointValue]
    //                              aiconmod.cpp:450 (1)
    //         0040bb76     RET
}

// Offset: 0x0040BB80
float yReferencePoint(ConstructionAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall ConstructionAIModule::yReferencePoint(void)                                  *
    //                              *********************************************************************************************************
    //                              float __thiscall yReferencePoint(ConstructionAIModule * this)
    //              float             ST0:10         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //                               ?yReferencePoint@ConstructionAIModule@@QAEMXZ
    //                               ConstructionAIModule::yReferencePoint
    //                              aiconmod.cpp:455 (6)
    //         0040bb80     FLD        float ptr [ECX + this->yReferencePointValue]
    //                              aiconmod.cpp:457 (1)
    //         0040bb86     RET
}

// Offset: 0x0040BB90
ConstructionItem* ConstructionAIModule::placeStructure(BuildItem* param_1) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class ConstructionItem * __thiscall ConstructionAIModule::placeStructure(class Bui... *
    //                              *********************************************************************************************************
    //                              ConstructionItem * __thiscall placeStructure(ConstructionAIModule * 
    //              ConstructionIt    EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              BuildItem *       Stack[0x4]:4   param_1
    //                               ?placeStructure@ConstructionAIModule@@UAEPAVConstructionIte  XREF[2]:     0056e7e4(*), 005754e4(*)  
    //                               ConstructionAIModule::placeStructure
    //                              aiconmod.cpp:462 (2)
    //         0040bb90     XOR        EAX,EAX
    //                              aiconmod.cpp:464 (3)
    //         0040bb92     RET        0x4
}

// Offset: 0x0040BBA0
PlacementResult lastPlacementReturnCode(ConstructionAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: enum ConstructionAIModule::PlacementResult __thiscall ConstructionAIModule::lastPlacementR... *
    //                              *********************************************************************************************************
    //                              PlacementResult __thiscall lastPlacementReturnCode(ConstructionAIMod
    //              PlacementResult   EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //                               ?lastPlacementReturnCode@ConstructionAIModule@@QAE?AW4Place
    //                               ConstructionAIModule::lastPlacementReturnCode
    //                              aiconmod.cpp:470 (6)
    //         0040bba0     MOV        EAX,dword ptr [ECX + this->lastPlacementReturn
    //                              aiconmod.cpp:472 (1)
    //         0040bba6     RET
}

// Offset: 0x0040BBB0
void ConstructionAIModule::setBuilt(ConstructionItem* param_1, int param_2) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall ConstructionAIModule::setBuilt(class ConstructionItem *,int)          *
    //                              *********************************************************************************************************
    //                              void __thiscall setBuilt(ConstructionAIModule * this, ConstructionIt
    //              void              <VOID>         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              ConstructionIt    Stack[0x4]:4   param_1                   XREF[1]:     0040bbc3(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040bbe6(R)  
    //                               ?setBuilt@ConstructionAIModule@@UAEXPAVConstructionItem@@H@Z XREF[2]:     0056e7e8(*), 005754e8(*)  
    //                               ConstructionAIModule::setBuilt
    //                              aiconmod.cpp:477 (2)
    //         0040bbb0     PUSH       EBX
    //         0040bbb1     PUSH       ESI
    //                              aiconmod.cpp:478 (7)
    //         0040bbb2     MOV        ESI,dword ptr [ECX + this+0x160]
    //         0040bbb8     PUSH       EDI
    //                              aiconmod.cpp:479 (18)
    //         0040bbb9     LEA        EDI,[ECX + this->constructionLots._padding_]
    //         0040bbbf     CMP        ESI,EDI
    //         0040bbc1     JZ         LAB_0040bbf2
    //         0040bbc3     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_0040bbc7                                                 XREF[1]:     0040bbde(j)  
    //         0040bbc7     TEST       ESI,ESI
    //         0040bbc9     JZ         LAB_0040bbf2
    //                              aiconmod.cpp:480 (14)
    //         0040bbcb     PUSH       EBX
    //         0040bbcc     PUSH       ESI
    //         0040bbcd     CALL       operator==                                       int operator==(ConstructionItem * param_1, Co
    //         0040bbd2     ADD        ESP,0x8
    //         0040bbd5     TEST       EAX,EAX
    //         0040bbd7     JNZ        LAB_0040bbe6
    //                              aiconmod.cpp:484 (7)
    //         0040bbd9     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040bbdc     CMP        ESI,EDI
    //         0040bbde     JNZ        LAB_0040bbc7
    //                              aiconmod.cpp:486 (6)
    //         0040bbe0     POP        EDI
    //         0040bbe1     POP        ESI
    //         0040bbe2     POP        EBX
    //         0040bbe3     RET        0x8
    //                               LAB_0040bbe6                                                 XREF[1]:     0040bbd7(j)  
    //                              aiconmod.cpp:481 (12)
    //         0040bbe6     MOV        EAX,dword ptr [ESP + param_2]
    //         0040bbea     MOV        this,ESI
    //         0040bbec     PUSH       EAX
    //         0040bbed     CALL       ConstructionItem::setBuilt                       void setBuilt(ConstructionItem * this, int pa
    //                               LAB_0040bbf2                                                 XREF[2]:     0040bbc1(j), 0040bbc9(j)  
    //                              aiconmod.cpp:486 (6)
    //         0040bbf2     POP        EDI
    //         0040bbf3     POP        ESI
    //         0040bbf4     POP        EBX
    //         0040bbf5     RET        0x8
}

// Offset: 0x0040BC00
int ConstructionAIModule::unplaceStructure(ConstructionItem* param_1, int param_2) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall ConstructionAIModule::unplaceStructure(class ConstructionItem *,int)   *
    //                              *********************************************************************************************************
    //                              int __thiscall unplaceStructure(ConstructionAIModule * this, Constru
    //              int               EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              ConstructionIt    Stack[0x4]:4   param_1                   XREF[1]:     0040bc13(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040bc5d(R)  
    //                               ?unplaceStructure@ConstructionAIModule@@UAEHPAVConstruction  XREF[2]:     0056e7f0(*), 005754f0(*)  
    //                               ConstructionAIModule::unplaceStructure
    //                              aiconmod.cpp:492 (2)
    //         0040bc00     PUSH       EBX
    //         0040bc01     PUSH       ESI
    //                              aiconmod.cpp:493 (7)
    //         0040bc02     MOV        ESI,dword ptr [ECX + this+0x160]
    //         0040bc08     PUSH       EDI
    //                              aiconmod.cpp:494 (18)
    //         0040bc09     LEA        EDI,[ECX + this->constructionLots._padding_]
    //         0040bc0f     CMP        ESI,EDI
    //         0040bc11     JZ         LAB_0040bc73
    //         0040bc13     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_0040bc17                                                 XREF[1]:     0040bc2e(j)  
    //         0040bc17     TEST       ESI,ESI
    //         0040bc19     JZ         LAB_0040bc73
    //                              aiconmod.cpp:495 (14)
    //         0040bc1b     PUSH       EBX
    //         0040bc1c     PUSH       ESI
    //         0040bc1d     CALL       operator==                                       int operator==(ConstructionItem * param_1, Co
    //         0040bc22     ADD        ESP,0x8
    //         0040bc25     TEST       EAX,EAX
    //         0040bc27     JNZ        LAB_0040bc39
    //                              aiconmod.cpp:505 (7)
    //         0040bc29     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040bc2c     CMP        ESI,EDI
    //         0040bc2e     JNZ        LAB_0040bc17
    //                              aiconmod.cpp:507 (3)
    //         0040bc30     OR         EAX,0xffffffff
    //                              aiconmod.cpp:508 (6)
    //         0040bc33     POP        EDI
    //         0040bc34     POP        ESI
    //         0040bc35     POP        EBX
    //         0040bc36     RET        0x8
    //                               LAB_0040bc39                                                 XREF[1]:     0040bc27(j)  
    //                              aiconmod.cpp:496 (9)
    //         0040bc39     PUSH       0x0
    //         0040bc3b     MOV        this,ESI
    //         0040bc3d     CALL       ConstructionItem::setInProgress                  void setInProgress(ConstructionItem * this, i
    //                              aiconmod.cpp:497 (9)
    //         0040bc42     PUSH       0x0
    //         0040bc44     MOV        this,ESI
    //         0040bc46     CALL       ConstructionItem::setBuilt                       void setBuilt(ConstructionItem * this, int pa
    //                              aiconmod.cpp:498 (7)
    //         0040bc4b     MOV        this,ESI
    //         0040bc4d     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //                              aiconmod.cpp:499 (11)
    //         0040bc52     PUSH       -0x1
    //         0040bc54     MOV        this,ESI
    //         0040bc56     MOV        EDI,EAX
    //         0040bc58     CALL       BaseItem::setUniqueID                            void setUniqueID(BaseItem * this, int param_1)
    //                              aiconmod.cpp:501 (7)
    //         0040bc5d     CMP        dword ptr [ESP + param_2],0x1
    //         0040bc62     JNZ        LAB_0040bc6b
    //                              aiconmod.cpp:502 (7)
    //         0040bc64     MOV        this,ESI
    //         0040bc66     CALL       ConstructionItem::decrementBuildAttempts         void decrementBuildAttempts(ConstructionItem 
    //                               LAB_0040bc6b                                                 XREF[1]:     0040bc62(j)  
    //                              aiconmod.cpp:503 (2)
    //         0040bc6b     MOV        EAX,EDI
    //                              aiconmod.cpp:508 (15)
    //         0040bc6d     POP        EDI
    //         0040bc6e     POP        ESI
    //         0040bc6f     POP        EBX
    //         0040bc70     RET        0x8
    //                               LAB_0040bc73                                                 XREF[2]:     0040bc11(j), 0040bc19(j)  
    //         0040bc73     POP        EDI
    //         0040bc74     POP        ESI
    //         0040bc75     OR         EAX,0xffffffff
    //         0040bc78     POP        EBX
    //         0040bc79     RET        0x8
}

// Offset: 0x0040BC80
int ConstructionAIModule::unplaceStructure(float param_1, float param_2, int param_3) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall ConstructionAIModule::unplaceStructure(float,float,int)                *
    //                              *********************************************************************************************************
    //                              int __thiscall unplaceStructure(ConstructionAIModule * this, float p
    //              int               EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040bc9d(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0040bcaf(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040bced(R)  
    //                               ?unplaceStructure@ConstructionAIModule@@UAEHMMH@Z            XREF[2]:     0056e7ec(*), 005754ec(*)  
    //                               ConstructionAIModule::unplaceStructure
    //                              aiconmod.cpp:513 (1)
    //         0040bc80     PUSH       ESI
    //                              aiconmod.cpp:514 (7)
    //         0040bc81     MOV        ESI,dword ptr [ECX + this+0x160]
    //         0040bc87     PUSH       EDI
    //                              aiconmod.cpp:515 (14)
    //         0040bc88     LEA        EDI,[ECX + this->constructionLots._padding_]
    //         0040bc8e     CMP        ESI,EDI
    //         0040bc90     JZ         LAB_0040bd02
    //                               LAB_0040bc92                                                 XREF[1]:     0040bcbf(j)  
    //         0040bc92     TEST       ESI,ESI
    //         0040bc94     JZ         LAB_0040bd02
    //                              aiconmod.cpp:516 (36)
    //         0040bc96     MOV        this,ESI
    //         0040bc98     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040bc9d     FCOMP      float ptr [ESP + param_1]
    //         0040bca1     FNSTSW     AX
    //         0040bca3     TEST       AH,0x40
    //         0040bca6     JZ         LAB_0040bcba
    //         0040bca8     MOV        this,ESI
    //         0040bcaa     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040bcaf     FCOMP      float ptr [ESP + param_2]
    //         0040bcb3     FNSTSW     AX
    //         0040bcb5     TEST       AH,0x40
    //         0040bcb8     JNZ        LAB_0040bcc9
    //                               LAB_0040bcba                                                 XREF[1]:     0040bca6(j)  
    //                              aiconmod.cpp:526 (7)
    //         0040bcba     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040bcbd     CMP        ESI,EDI
    //         0040bcbf     JNZ        LAB_0040bc92
    //                              aiconmod.cpp:528 (3)
    //         0040bcc1     OR         EAX,0xffffffff
    //                              aiconmod.cpp:529 (5)
    //         0040bcc4     POP        EDI
    //         0040bcc5     POP        ESI
    //         0040bcc6     RET        0xc
    //                               LAB_0040bcc9                                                 XREF[1]:     0040bcb8(j)  
    //                              aiconmod.cpp:517 (9)
    //         0040bcc9     PUSH       0x0
    //         0040bccb     MOV        this,ESI
    //         0040bccd     CALL       ConstructionItem::setInProgress                  void setInProgress(ConstructionItem * this, i
    //                              aiconmod.cpp:518 (9)
    //         0040bcd2     PUSH       0x0
    //         0040bcd4     MOV        this,ESI
    //         0040bcd6     CALL       ConstructionItem::setBuilt                       void setBuilt(ConstructionItem * this, int pa
    //                              aiconmod.cpp:519 (7)
    //         0040bcdb     MOV        this,ESI
    //         0040bcdd     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //                              aiconmod.cpp:520 (11)
    //         0040bce2     PUSH       -0x1
    //         0040bce4     MOV        this,ESI
    //         0040bce6     MOV        EDI,EAX
    //         0040bce8     CALL       BaseItem::setUniqueID                            void setUniqueID(BaseItem * this, int param_1)
    //                              aiconmod.cpp:522 (7)
    //         0040bced     CMP        dword ptr [ESP + param_3],0x1
    //         0040bcf2     JNZ        LAB_0040bcfb
    //                              aiconmod.cpp:523 (7)
    //         0040bcf4     MOV        this,ESI
    //         0040bcf6     CALL       ConstructionItem::decrementBuildAttempts         void decrementBuildAttempts(ConstructionItem 
    //                               LAB_0040bcfb                                                 XREF[1]:     0040bcf2(j)  
    //                              aiconmod.cpp:524 (2)
    //         0040bcfb     MOV        EAX,EDI
    //                              aiconmod.cpp:529 (13)
    //         0040bcfd     POP        EDI
    //         0040bcfe     POP        ESI
    //         0040bcff     RET        0xc
    //                               LAB_0040bd02                                                 XREF[2]:     0040bc90(j), 0040bc94(j)  
    //         0040bd02     POP        EDI
    //         0040bd03     OR         EAX,0xffffffff
    //         0040bd06     POP        ESI
    //         0040bd07     RET        0xc
}

// Offset: 0x0040BD10
void ConstructionAIModule::decrementBuildAttempts(float param_1, float param_2, int param_3) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall ConstructionAIModule::decrementBuildAttempts(float,float,int)         *
    //                              *********************************************************************************************************
    //                              void __thiscall decrementBuildAttempts(ConstructionAIModule * this, 
    //              void              <VOID>         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040bd14(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0040bd10(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040bd27(R)  
    //                               ?decrementBuildAttempts@ConstructionAIModule@@UAEXMMH@Z      XREF[2]:     0056e7f4(*), 005754f4(*)  
    //                               ConstructionAIModule::decrementBuildAttempts
    //                              aiconmod.cpp:534 (19)
    //         0040bd10     MOV        EAX,dword ptr [ESP + param_2]
    //         0040bd14     MOV        EDX,dword ptr [ESP + param_1]
    //         0040bd18     PUSH       ESI
    //         0040bd19     PUSH       EDI
    //         0040bd1a     PUSH       EAX
    //         0040bd1b     PUSH       EDX
    //         0040bd1c     CALL       ConstructionAIModule::lot                        ConstructionItem * lot(ConstructionAIModule *
    //         0040bd21     MOV        ESI,EAX
    //                              aiconmod.cpp:536 (4)
    //         0040bd23     TEST       ESI,ESI
    //         0040bd25     JZ         LAB_0040bd39
    //                              aiconmod.cpp:537 (8)
    //         0040bd27     MOV        EDI,dword ptr [ESP + param_3]
    //         0040bd2b     TEST       EDI,EDI
    //         0040bd2d     JLE        LAB_0040bd39
    //                               LAB_0040bd2f                                                 XREF[1]:     0040bd37(j)  
    //                              aiconmod.cpp:538 (10)
    //         0040bd2f     MOV        this,ESI
    //         0040bd31     CALL       ConstructionItem::decrementBuildAttempts         void decrementBuildAttempts(ConstructionItem 
    //         0040bd36     DEC        EDI
    //         0040bd37     JNZ        LAB_0040bd2f
    //                               LAB_0040bd39                                                 XREF[2]:     0040bd25(j), 0040bd2d(j)  
    //                              aiconmod.cpp:540 (5)
    //         0040bd39     POP        EDI
    //         0040bd3a     POP        ESI
    //         0040bd3b     RET        0xc
}

// Offset: 0x0040BD40
void ConstructionAIModule::incrementBuildAttempts(float param_1, float param_2, int param_3) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall ConstructionAIModule::incrementBuildAttempts(float,float,int)         *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementBuildAttempts(ConstructionAIModule * this, 
    //              void              <VOID>         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040bd44(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0040bd40(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040bd57(R)  
    //                               ?incrementBuildAttempts@ConstructionAIModule@@UAEXMMH@Z      XREF[2]:     0056e7f8(*), 005754f8(*)  
    //                               ConstructionAIModule::incrementBuildAttempts
    //                              aiconmod.cpp:545 (19)
    //         0040bd40     MOV        EAX,dword ptr [ESP + param_2]
    //         0040bd44     MOV        EDX,dword ptr [ESP + param_1]
    //         0040bd48     PUSH       ESI
    //         0040bd49     PUSH       EDI
    //         0040bd4a     PUSH       EAX
    //         0040bd4b     PUSH       EDX
    //         0040bd4c     CALL       ConstructionAIModule::lot                        ConstructionItem * lot(ConstructionAIModule *
    //         0040bd51     MOV        ESI,EAX
    //                              aiconmod.cpp:547 (4)
    //         0040bd53     TEST       ESI,ESI
    //         0040bd55     JZ         LAB_0040bd69
    //                              aiconmod.cpp:548 (8)
    //         0040bd57     MOV        EDI,dword ptr [ESP + param_3]
    //         0040bd5b     TEST       EDI,EDI
    //         0040bd5d     JLE        LAB_0040bd69
    //                               LAB_0040bd5f                                                 XREF[1]:     0040bd67(j)  
    //                              aiconmod.cpp:549 (10)
    //         0040bd5f     MOV        this,ESI
    //         0040bd61     CALL       ConstructionItem::incrementBuildAttempts         void incrementBuildAttempts(ConstructionItem 
    //         0040bd66     DEC        EDI
    //         0040bd67     JNZ        LAB_0040bd5f
    //                               LAB_0040bd69                                                 XREF[2]:     0040bd55(j), 0040bd5d(j)  
    //                              aiconmod.cpp:551 (5)
    //         0040bd69     POP        EDI
    //         0040bd6a     POP        ESI
    //         0040bd6b     RET        0xc
}

// Offset: 0x0040BD70
ConstructionItem* lot(ConstructionAIModule* this_, float param_2, float param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ConstructionItem * __thiscall ConstructionAIModule::lot(float,float)                    *
    //                              *********************************************************************************************************
    //                              ConstructionItem * __thiscall lot(ConstructionAIModule * this, float
    //              ConstructionIt    EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0040bd90(R), 0040bdcf(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[2]:     0040bda2(R), 0040bde1(R)  
    //                               ?lot@ConstructionAIModule@@QAEPAVConstructionItem@@MM@Z      XREF[5]:     loadConstructionPlan:0040b84a(c), 
    //                               ConstructionAIModule::lot                                                 decrementBuildAttempts:0040bd1c(c)
    //                                                                                                         incrementBuildAttempts:0040bd4c(c)
    //                                                                                                         cancelBuildItem:004d53bd(c), 
    //                                                                                                         placeStructure:004d664c(c)  
    //                              aiconmod.cpp:556 (5)
    //         0040bd70     PUSH       EBX
    //         0040bd71     MOV        EBX,this
    //         0040bd73     PUSH       ESI
    //         0040bd74     PUSH       EDI
    //                              aiconmod.cpp:557 (6)
    //         0040bd75     MOV        ESI,dword ptr [EBX + 0x160]
    //                              aiconmod.cpp:558 (14)
    //         0040bd7b     LEA        EDI,[EBX + 0xf4]
    //         0040bd81     CMP        ESI,EDI
    //         0040bd83     JZ         LAB_0040bdb4
    //                               LAB_0040bd85                                                 XREF[1]:     0040bdb2(j)  
    //         0040bd85     TEST       ESI,ESI
    //         0040bd87     JZ         LAB_0040bdb4
    //                              aiconmod.cpp:559 (36)
    //         0040bd89     MOV        this,ESI
    //         0040bd8b     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040bd90     FCOMP      float ptr [ESP + param_1]
    //         0040bd94     FNSTSW     AX
    //         0040bd96     TEST       AH,0x40
    //         0040bd99     JZ         LAB_0040bdad
    //         0040bd9b     MOV        this,ESI
    //         0040bd9d     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040bda2     FCOMP      float ptr [ESP + param_2]
    //         0040bda6     FNSTSW     AX
    //         0040bda8     TEST       AH,0x40
    //         0040bdab     JNZ        LAB_0040bdfb
    //                               LAB_0040bdad                                                 XREF[1]:     0040bd99(j)  
    //                              aiconmod.cpp:561 (7)
    //         0040bdad     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040bdb0     CMP        ESI,EDI
    //         0040bdb2     JNZ        LAB_0040bd85
    //                               LAB_0040bdb4                                                 XREF[2]:     0040bd83(j), 0040bd87(j)  
    //                              aiconmod.cpp:563 (6)
    //         0040bdb4     MOV        ESI,dword ptr [EBX + 0x1e4]
    //                              aiconmod.cpp:564 (14)
    //         0040bdba     LEA        EDI,[EBX + 0x178]
    //         0040bdc0     CMP        ESI,EDI
    //         0040bdc2     JZ         LAB_0040be03
    //                               LAB_0040bdc4                                                 XREF[1]:     0040bdf1(j)  
    //         0040bdc4     TEST       ESI,ESI
    //         0040bdc6     JZ         LAB_0040be03
    //                              aiconmod.cpp:565 (36)
    //         0040bdc8     MOV        this,ESI
    //         0040bdca     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040bdcf     FCOMP      float ptr [ESP + param_1]
    //         0040bdd3     FNSTSW     AX
    //         0040bdd5     TEST       AH,0x40
    //         0040bdd8     JZ         LAB_0040bdec
    //         0040bdda     MOV        this,ESI
    //         0040bddc     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040bde1     FCOMP      float ptr [ESP + param_2]
    //         0040bde5     FNSTSW     AX
    //         0040bde7     TEST       AH,0x40
    //         0040bdea     JNZ        LAB_0040bdfb
    //                               LAB_0040bdec                                                 XREF[1]:     0040bdd8(j)  
    //                              aiconmod.cpp:567 (7)
    //         0040bdec     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040bdef     CMP        ESI,EDI
    //         0040bdf1     JNZ        LAB_0040bdc4
    //                              aiconmod.cpp:569 (2)
    //         0040bdf3     XOR        EAX,EAX
    //                              aiconmod.cpp:570 (6)
    //         0040bdf5     POP        EDI
    //         0040bdf6     POP        ESI
    //         0040bdf7     POP        EBX
    //         0040bdf8     RET        0x8
    //                               LAB_0040bdfb                                                 XREF[2]:     0040bdab(j), 0040bdea(j)  
    //                              aiconmod.cpp:566 (2)
    //         0040bdfb     MOV        EAX,ESI
    //                              aiconmod.cpp:570 (14)
    //         0040bdfd     POP        EDI
    //         0040bdfe     POP        ESI
    //         0040bdff     POP        EBX
    //         0040be00     RET        0x8
    //                               LAB_0040be03                                                 XREF[2]:     0040bdc2(j), 0040bdc6(j)  
    //         0040be03     POP        EDI
    //         0040be04     POP        ESI
    //         0040be05     XOR        EAX,EAX
    //         0040be07     POP        EBX
    //         0040be08     RET        0x8
}

// Offset: 0x0040BE10
ConstructionItem* randomLot(ConstructionAIModule* this_, float param_2, float param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ConstructionItem * __thiscall ConstructionAIModule::randomLot(float,float)              *
    //                              *********************************************************************************************************
    //                              ConstructionItem * __thiscall randomLot(ConstructionAIModule * this,
    //              ConstructionIt    EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040be2d(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0040be3f(R)  
    //                               ?randomLot@ConstructionAIModule@@QAEPAVConstructionItem@@MM@Z XREF[1]:     placeDock:004d9d00(c)  
    //                               ConstructionAIModule::randomLot
    //                              aiconmod.cpp:575 (1)
    //         0040be10     PUSH       ESI
    //                              aiconmod.cpp:576 (7)
    //         0040be11     MOV        ESI,dword ptr [ECX + this+0x1e4]
    //         0040be17     PUSH       EDI
    //                              aiconmod.cpp:577 (14)
    //         0040be18     LEA        EDI,[ECX + this->randomConstructionLots._paddi
    //         0040be1e     CMP        ESI,EDI
    //         0040be20     JZ         LAB_0040be5f
    //                               LAB_0040be22                                                 XREF[1]:     0040be4f(j)  
    //         0040be22     TEST       ESI,ESI
    //         0040be24     JZ         LAB_0040be5f
    //                              aiconmod.cpp:578 (36)
    //         0040be26     MOV        this,ESI
    //         0040be28     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         0040be2d     FCOMP      float ptr [ESP + param_1]
    //         0040be31     FNSTSW     AX
    //         0040be33     TEST       AH,0x40
    //         0040be36     JZ         LAB_0040be4a
    //         0040be38     MOV        this,ESI
    //         0040be3a     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         0040be3f     FCOMP      float ptr [ESP + param_2]
    //         0040be43     FNSTSW     AX
    //         0040be45     TEST       AH,0x40
    //         0040be48     JNZ        LAB_0040be58
    //                               LAB_0040be4a                                                 XREF[1]:     0040be36(j)  
    //                              aiconmod.cpp:580 (7)
    //         0040be4a     MOV        ESI,dword ptr [ESI + 0x6c]
    //         0040be4d     CMP        ESI,EDI
    //         0040be4f     JNZ        LAB_0040be22
    //                              aiconmod.cpp:582 (2)
    //         0040be51     XOR        EAX,EAX
    //                              aiconmod.cpp:583 (5)
    //         0040be53     POP        EDI
    //         0040be54     POP        ESI
    //         0040be55     RET        0x8
    //                               LAB_0040be58                                                 XREF[1]:     0040be48(j)  
    //                              aiconmod.cpp:579 (2)
    //         0040be58     MOV        EAX,ESI
    //                              aiconmod.cpp:583 (12)
    //         0040be5a     POP        EDI
    //         0040be5b     POP        ESI
    //         0040be5c     RET        0x8
    //                               LAB_0040be5f                                                 XREF[2]:     0040be20(j), 0040be24(j)  
    //         0040be5f     POP        EDI
    //         0040be60     XOR        EAX,EAX
    //         0040be62     POP        ESI
    //         0040be63     RET        0x8
}

// Offset: 0x0040BE70
void removeOldLots(ConstructionAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall ConstructionAIModule::removeOldLots(void)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall removeOldLots(ConstructionAIModule * this)
    //              void              <VOID>         <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //                               ?removeOldLots@ConstructionAIModule@@IAEXXZ                  XREF[3]:     ~ConstructionAIModule:0040b155(c), 
    //                               ConstructionAIModule::removeOldLots                                       loadConstructionPlan:0040b6e9(c), 
    //                                                                                                         setReferencePoint:0040bb63(c)  
    //                              aiconmod.cpp:588 (5)
    //         0040be70     PUSH       EBX
    //         0040be71     MOV        EBX,this
    //         0040be73     PUSH       ESI
    //         0040be74     PUSH       EDI
    //                              aiconmod.cpp:589 (6)
    //         0040be75     MOV        this,dword ptr [EBX + 0x160]
    //                              aiconmod.cpp:591 (14)
    //         0040be7b     LEA        EDI,[EBX + 0xf4]
    //         0040be81     CMP        this,EDI
    //         0040be83     JZ         LAB_0040be98
    //                               LAB_0040be85                                                 XREF[1]:     0040be96(j)  
    //         0040be85     TEST       this,this
    //         0040be87     JZ         LAB_0040be98
    //                              aiconmod.cpp:593 (11)
    //         0040be89     MOV        EAX,dword ptr [this->_padding_]
    //         0040be8b     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         0040be8e     PUSH       0x1
    //         0040be90     CALL       dword ptr [EAX]
    //         0040be92     CMP        ESI,EDI
    //                              aiconmod.cpp:594 (4)
    //         0040be94     MOV        this,ESI
    //         0040be96     JNZ        LAB_0040be85
    //                               LAB_0040be98                                                 XREF[2]:     0040be83(j), 0040be87(j)  
    //                              aiconmod.cpp:596 (6)
    //         0040be98     MOV        dword ptr [EBX + 0x160],EDI
    //                              aiconmod.cpp:597 (6)
    //         0040be9e     MOV        dword ptr [EBX + 0x164],EDI
    //                              aiconmod.cpp:599 (14)
    //         0040bea4     POP        EDI
    //         0040bea5     MOV        dword ptr [EBX + 0xf0],0x0
    //         0040beaf     POP        ESI
    //         0040beb0     POP        EBX
    //         0040beb1     RET
}

