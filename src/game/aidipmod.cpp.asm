#include "common.h"
#include "aidipmod.h"

DiplomacyAIModule::DiplomacyAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall DiplomacyAIModule(DiplomacyAIModule * this, voi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0040bec0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040bec8(R)  
    //                               ??0DiplomacyAIModule@@QAE@PAXH@Z                             XREF[1]:     TribeMainDecisionAIModule:004e4868
    //                               DiplomacyAIModule::DiplomacyAIModule
    //                              aidipmod.cpp:26 (51)
    //         0040bec0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040bec4     PUSH       ESI
    //         0040bec5     MOV        ESI,this
    //         0040bec7     PUSH       EDI
    //         0040bec8     MOV        this,dword ptr [ESP + param_2]
    //         0040becc     PUSH       EAX
    //         0040becd     PUSH       this
    //                              language.dll match for 0x3eb: "Age of Empires Help"
    //         0040bece     PUSH       0x3eb
    //         0040bed3     PUSH       s_Diplomacy_AI                                   = "Diplomacy AI"
    //         0040bed8     MOV        this,ESI
    //         0040beda     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040bedf     XOR        EAX,EAX
    //         0040bee1     MOV        dword ptr [ESI],DiplomacyAIModule::`vftable'     = 0040bf20
    //         0040bee7     MOV        dword ptr [ESI + 0xf0],EAX
    //         0040beed     LEA        this,[ESI + 0x11c]
    //                              aidipmod.cpp:28 (7)
    //         0040bef3     MOV        EDI,0x31
    //         0040bef8     MOV        DL,0x1
    //                               LAB_0040befa                                                 XREF[1]:     0040bf0d(j)  
    //                              aidipmod.cpp:29 (3)
    //         0040befa     MOV        dword ptr [this->_padding_ + -0x28],EDI
    //                              aidipmod.cpp:30 (2)
    //         0040befd     MOV        dword ptr [this->_padding_],EDI
    //                              aidipmod.cpp:31 (16)
    //         0040beff     MOV        byte ptr [EAX + ESI*0x1 + 0x144],DL
    //         0040bf06     INC        EAX
    //         0040bf07     ADD        this,0x4
    //         0040bf0a     CMP        EAX,0x9
    //         0040bf0d     JLE        LAB_0040befa
    //                              aidipmod.cpp:33 (7)
    //         0040bf0f     MOV        EAX,ESI
    //         0040bf11     POP        EDI
    //         0040bf12     POP        ESI
    //         0040bf13     RET        0x8
    //         0040bf16     ??         90h
    //         0040bf17     NOP
    //         0040bf18     NOP
    //         0040bf19     NOP
    //         0040bf1a     NOP
    //         0040bf1b     NOP
    //         0040bf1c     NOP
    //         0040bf1d     NOP
    //         0040bf1e     NOP
    //         0040bf1f     NOP
}

DiplomacyAIModule::DiplomacyAIModule(int param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall DiplomacyAIModule(DiplomacyAIModule * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040bf56(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040bf81(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0040bf77(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040bfca(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0040bf6e(W), 0040bfce(R)  
    //                               ??0DiplomacyAIModule@@QAE@HH@Z                               XREF[1]:     TribeMainDecisionAIModule:004e4be8
    //                               DiplomacyAIModule::DiplomacyAIModule
    //                              aidipmod.cpp:40 (92)
    //         0040bf40     PUSH       -0x1
    //         0040bf42     PUSH       FUN_0055c5f8
    //         0040bf47     MOV        EAX,FS:[0x0]
    //         0040bf4d     PUSH       EAX
    //         0040bf4e     MOV        dword ptr FS:[0x0],ESP
    //         0040bf55     PUSH       this
    //         0040bf56     MOV        EAX,dword ptr [ESP + param_1]
    //         0040bf5a     PUSH       EBX
    //         0040bf5b     PUSH       EBP
    //         0040bf5c     PUSH       ESI
    //         0040bf5d     PUSH       EDI
    //         0040bf5e     XOR        EDI,EDI
    //         0040bf60     PUSH       EDI
    //         0040bf61     PUSH       EAX
    //         0040bf62     MOV        ESI,this
    //                              language.dll match for 0x3eb: "Age of Empires Help"
    //         0040bf64     PUSH       0x3eb
    //         0040bf69     PUSH       s_Diplomacy_AI                                   = "Diplomacy AI"
    //         0040bf6e     MOV        dword ptr [ESP + local_10],ESI
    //         0040bf72     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040bf77     MOV        dword ptr [ESP + local_4],EDI
    //         0040bf7b     MOV        dword ptr [ESI + 0xf0],EDI
    //         0040bf81     MOV        EDI,dword ptr [ESP + param_2]
    //         0040bf85     MOV        dword ptr [ESI],DiplomacyAIModule::`vftable'     = 0040bf20
    //         0040bf8b     LEA        EBX,[ESI + 0x144]
    //         0040bf91     ADD        ESI,0x11c
    //         0040bf97     MOV        EBP,0xa
    //                               LAB_0040bf9c                                                 XREF[1]:     0040bfc8(j)  
    //                              aidipmod.cpp:42 (3)
    //         0040bf9c     LEA        this,[ESI + -0x28]
    //                              aidipmod.cpp:43 (12)
    //         0040bf9f     PUSH       0x4
    //         0040bfa1     PUSH       this
    //         0040bfa2     PUSH       EDI
    //         0040bfa3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040bfa8     ADD        ESP,0xc
    //                              aidipmod.cpp:44 (12)
    //         0040bfab     PUSH       0x4
    //         0040bfad     PUSH       ESI
    //         0040bfae     PUSH       EDI
    //         0040bfaf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040bfb4     ADD        ESP,0xc
    //                              aidipmod.cpp:45 (19)
    //         0040bfb7     PUSH       0x1
    //         0040bfb9     PUSH       EBX
    //         0040bfba     PUSH       EDI
    //         0040bfbb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040bfc0     ADD        ESP,0xc
    //         0040bfc3     ADD        ESI,0x4
    //         0040bfc6     INC        EBX
    //         0040bfc7     DEC        EBP
    //         0040bfc8     JNZ        LAB_0040bf9c
    //                              aidipmod.cpp:47 (25)
    //         0040bfca     MOV        this,dword ptr [ESP + local_c]
    //         0040bfce     MOV        EAX,dword ptr [ESP + local_10]
    //         0040bfd2     POP        EDI
    //         0040bfd3     POP        ESI
    //         0040bfd4     POP        EBP
    //         0040bfd5     MOV        dword ptr FS:[0x0],this
    //         0040bfdc     POP        EBX
    //         0040bfdd     ADD        ESP,0x10
    //         0040bfe0     RET        0x8
    //         0040bfe3     ??         90h
    //         0040bfe4     NOP
    //         0040bfe5     NOP
    //         0040bfe6     NOP
    //         0040bfe7     NOP
    //         0040bfe8     NOP
    //         0040bfe9     NOP
    //         0040bfea     NOP
    //         0040bfeb     NOP
    //         0040bfec     NOP
    //         0040bfed     NOP
    //         0040bfee     NOP
    //         0040bfef     NOP
}

DiplomacyAIModule::~DiplomacyAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~DiplomacyAIModule(DiplomacyAIModule * this)
    //              void              <VOID>         <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //                               ??1DiplomacyAIModule@@UAE@XZ                                 XREF[4]:     `scalar_deleting_destructor':0040b
    //                               DiplomacyAIModule::~DiplomacyAIModule                                     ~TribeMainDecisionAIModule:004e4f5
    //                                                                                                         FUN_00560644:0056064d(c), 
    //                                                                                                         FUN_005606d4:005606dd(c)  
    //                              aidipmod.cpp:52 (11)
    //         0040bff0     MOV        dword ptr [this->_padding_],DiplomacyAIModule:   = 0040bf20
    //         0040bff6     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0040bffb     ??         90h
    //         0040bffc     NOP
    //         0040bffd     NOP
    //         0040bffe     NOP
    //         0040bfff     NOP
}

void DiplomacyAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setMainDecisionAI(DiplomacyAIModule * this, MainDeci
    //              void              <VOID>         <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              MainDecisionAI    Stack[0x4]:4   param_1                   XREF[1]:     0040c000(R)  
    //                               ?setMainDecisionAI@DiplomacyAIModule@@QAEXPAVMainDecisionAI  XREF[2]:     TribeMainDecisionAIModule:004e4995
    //                               DiplomacyAIModule::setMainDecisionAI                                      TribeMainDecisionAIModule:004e4cd8
    //                              aidipmod.cpp:58 (10)
    //         0040c000     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c004     MOV        dword ptr [ECX + this->md],EAX
    //                              aidipmod.cpp:60 (3)
    //         0040c00a     RET        0x4
    //         0040c00d     ??         90h
    //         0040c00e     NOP
    //         0040c00f     NOP
    return;
}

int DiplomacyAIModule::update(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall update(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?update@DiplomacyAIModule@@UAEHH@Z                           XREF[1]:     0056e848(*)  
    //                               DiplomacyAIModule::update
    //                              aidipmod.cpp:65 (4)
    //         0040c010     PUSH       ESI
    //         0040c011     PUSH       EDI
    //         0040c012     MOV        EDI,this
    //                              aidipmod.cpp:66 (26)
    //         0040c014     MOV        ESI,0x1
    //         0040c019     MOV        EAX,dword ptr [EDI + 0xf0]
    //         0040c01f     MOV        EAX,dword ptr [EAX + 0xf0]
    //         0040c025     MOV        this,dword ptr [EAX + 0x3c]
    //         0040c028     CMP        word ptr [ECX + this->_padding_],SI
    //         0040c02c     JLE        LAB_0040c095
    //                               LAB_0040c02e                                                 XREF[1]:     0040c093(j)  
    //                              aidipmod.cpp:68 (8)
    //         0040c02e     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0040c032     CMP        ESI,EDX
    //         0040c034     JZ         LAB_0040c07d
    //                              aidipmod.cpp:73 (24)
    //         0040c036     PUSH       ESI
    //         0040c037     MOV        this,EDI
    //         0040c039     CALL       DiplomacyAIModule::isAlly                        int isAlly(DiplomacyAIModule * this, int para
    //         0040c03e     TEST       EAX,EAX
    //         0040c040     JZ         LAB_0040c059
    //         0040c042     PUSH       ESI
    //         0040c043     MOV        this,EDI
    //         0040c045     CALL       DiplomacyAIModule::isAlliedWithMe                int isAlliedWithMe(DiplomacyAIModule * this, 
    //         0040c04a     TEST       EAX,EAX
    //         0040c04c     JNZ        LAB_0040c059
    //                              aidipmod.cpp:74 (11)
    //         0040c04e     PUSH       0x1
    //         0040c050     PUSH       EAX
    //         0040c051     PUSH       ESI
    //         0040c052     MOV        this,EDI
    //         0040c054     CALL       DiplomacyAIModule::changeStance                  void changeStance(DiplomacyAIModule * this, i
    //                               LAB_0040c059                                                 XREF[2]:     0040c040(j), 0040c04c(j)  
    //                              aidipmod.cpp:78 (24)
    //         0040c059     PUSH       ESI
    //         0040c05a     MOV        this,EDI
    //         0040c05c     CALL       DiplomacyAIModule::isAlly                        int isAlly(DiplomacyAIModule * this, int para
    //         0040c061     TEST       EAX,EAX
    //         0040c063     JNZ        LAB_0040c07d
    //         0040c065     PUSH       ESI
    //         0040c066     MOV        this,EDI
    //         0040c068     CALL       DiplomacyAIModule::isAlliedWithMe                int isAlliedWithMe(DiplomacyAIModule * this, 
    //         0040c06d     TEST       EAX,EAX
    //         0040c06f     JZ         LAB_0040c07d
    //                              aidipmod.cpp:79 (36)
    //         0040c071     PUSH       0x1
    //         0040c073     PUSH       0x2
    //         0040c075     PUSH       ESI
    //         0040c076     MOV        this,EDI
    //         0040c078     CALL       DiplomacyAIModule::changeStance                  void changeStance(DiplomacyAIModule * this, i
    //                               LAB_0040c07d                                                 XREF[3]:     0040c034(j), 0040c063(j), 
    //                                                                                                         0040c06f(j)  
    //         0040c07d     MOV        EAX,dword ptr [EDI + 0xf0]
    //         0040c083     INC        ESI
    //         0040c084     MOV        EAX,dword ptr [EAX + 0xf0]
    //         0040c08a     MOV        this,dword ptr [EAX + 0x3c]
    //         0040c08d     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040c091     CMP        ESI,EDX
    //         0040c093     JL         LAB_0040c02e
    //                               LAB_0040c095                                                 XREF[1]:     0040c02c(j)  
    //                              aidipmod.cpp:93 (10)
    //         0040c095     POP        EDI
    //         0040c096     MOV        EAX,0x1
    //         0040c09b     POP        ESI
    //         0040c09c     RET        0x4
    //         0040c09f     ??         90h
    return 0;
}

int DiplomacyAIModule::save(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall save(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c0a4(R)  
    //                               ?save@DiplomacyAIModule@@UAEHH@Z                             XREF[1]:     0056e854(*)  
    //                               DiplomacyAIModule::save
    //                              aidipmod.cpp:98 (4)
    //         0040c0a0     PUSH       EBX
    //         0040c0a1     PUSH       EBP
    //         0040c0a2     PUSH       ESI
    //         0040c0a3     PUSH       EDI
    //                              aidipmod.cpp:99 (24)
    //         0040c0a4     MOV        EDI,dword ptr [ESP + param_1]
    //         0040c0a8     LEA        EBX,[ECX + this->changeableTable[0]]
    //         0040c0ae     LEA        ESI,[ECX + this->likeTable[0]]
    //         0040c0b4     MOV        EBP,0xa
    //                               LAB_0040c0b9                                                 XREF[1]:     0040c0e5(j)  
    //         0040c0b9     LEA        EAX,[ESI + -0x28]
    //                              aidipmod.cpp:100 (12)
    //         0040c0bc     PUSH       0x4
    //         0040c0be     PUSH       EAX
    //         0040c0bf     PUSH       EDI
    //         0040c0c0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040c0c5     ADD        ESP,0xc
    //                              aidipmod.cpp:101 (12)
    //         0040c0c8     PUSH       0x4
    //         0040c0ca     PUSH       ESI
    //         0040c0cb     PUSH       EDI
    //         0040c0cc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040c0d1     ADD        ESP,0xc
    //                              aidipmod.cpp:102 (19)
    //         0040c0d4     PUSH       0x1
    //         0040c0d6     PUSH       EBX
    //         0040c0d7     PUSH       EDI
    //         0040c0d8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040c0dd     ADD        ESP,0xc
    //         0040c0e0     ADD        ESI,0x4
    //         0040c0e3     INC        EBX
    //         0040c0e4     DEC        EBP
    //         0040c0e5     JNZ        LAB_0040c0b9
    //                              aidipmod.cpp:105 (12)
    //         0040c0e7     POP        EDI
    //         0040c0e8     POP        ESI
    //         0040c0e9     POP        EBP
    //         0040c0ea     MOV        EAX,0x1
    //         0040c0ef     POP        EBX
    //         0040c0f0     RET        0x4
    //         0040c0f3     ??         90h
    //         0040c0f4     NOP
    //         0040c0f5     NOP
    //         0040c0f6     NOP
    //         0040c0f7     NOP
    //         0040c0f8     NOP
    //         0040c0f9     NOP
    //         0040c0fa     NOP
    //         0040c0fb     NOP
    //         0040c0fc     NOP
    //         0040c0fd     NOP
    //         0040c0fe     NOP
    //         0040c0ff     NOP
    //                              * public: int __thiscall DiplomacyAIModule::stance(int,int)const                                        *
    //                              int __thiscall stance(DiplomacyAIModule * this, int param_1, int par
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c100(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c121(R)  
    //                               ?stance@DiplomacyAIModule@@QBEHHH@Z                          XREF[30]:    update:004ef3a4(c), 
    //                               DiplomacyAIModule::stance                                                 update:004ef3fa(c), 
    //                                                                                                         update:004ef415(c), 
    //                                                                                                         aiStatus:00514cb0(c), 
    //                                                                                                         aiStatus:00514cc6(c), 
    //                                                                                                         aiStatus:00514cdc(c), 
    //                                                                                                         aiStatus:00514cf2(c), 
    //                                                                                                         aiStatus:00514d08(c), 
    //                                                                                                         aiStatus:00514d1e(c), 
    //                                                                                                         aiStatus:00514d34(c), 
    //                                                                                                         aiStatus:00514d4a(c), 
    //                                                                                                         aiStatus:00514d60(c), 
    //                                                                                                         aiStatus:00514d76(c), 
    //                                                                                                         aiStatus:00514d8c(c), 
    //                                                                                                         aiStatus:00514da2(c), 
    //                                                                                                         aiStatus:00514db8(c), 
    //                                                                                                         aiStatus:00514dce(c), 
    //                                                                                                         aiStatus:00514de4(c), 
    //                                                                                                         aiStatus:00514dfa(c), 
    //                                                                                                         aiStatus:00514e10(c), [more]
    //                              aidipmod.cpp:110 (33)
    //         0040c100     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c104     PUSH       ESI
    //         0040c105     TEST       EAX,EAX
    //         0040c107     PUSH       EDI
    //         0040c108     JLE        LAB_0040c17e
    //         0040c10a     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c110     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c116     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c119     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c11d     CMP        EAX,EDX
    //         0040c11f     JGE        LAB_0040c17e
    //                              aidipmod.cpp:116 (13)
    //         0040c121     MOV        EDX,dword ptr [ESP + param_2]
    //         0040c125     SUB        EDX,0x0
    //         0040c128     JZ         LAB_0040c172
    //         0040c12a     DEC        EDX
    //         0040c12b     JZ         LAB_0040c13c
    //         0040c12d     DEC        EDX
    //                              aidipmod.cpp:137 (2)
    //         0040c12e     JNZ        LAB_0040c17e
    //                              aidipmod.cpp:135 (7)
    //         0040c130     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->likeTable
    //                              aidipmod.cpp:138 (5)
    //         0040c137     POP        EDI
    //         0040c138     POP        ESI
    //         0040c139     RET        0x8
    //                               LAB_0040c13c                                                 XREF[1]:     0040c12b(j)  
    //                              aidipmod.cpp:124 (14)
    //         0040c13c     MOV        EDX,dword ptr [ECX + EAX*0x4 + this->dislikeTa
    //         0040c143     MOV        ESI,0x31
    //         0040c148     SUB        ESI,EDX
    //                              aidipmod.cpp:125 (2)
    //         0040c14a     JNS        LAB_0040c14e
    //                              aidipmod.cpp:126 (2)
    //         0040c14c     NEG        ESI
    //                               LAB_0040c14e                                                 XREF[1]:     0040c14a(j)  
    //                              aidipmod.cpp:127 (14)
    //         0040c14e     MOV        EDI,dword ptr [ECX + EAX*0x4 + this->likeTable
    //         0040c155     MOV        EDX,0x31
    //         0040c15a     SUB        EDX,EDI
    //                              aidipmod.cpp:128 (2)
    //         0040c15c     JNS        LAB_0040c160
    //                              aidipmod.cpp:129 (2)
    //         0040c15e     NEG        EDX
    //                               LAB_0040c160                                                 XREF[1]:     0040c15c(j)  
    //                              aidipmod.cpp:130 (9)
    //         0040c160     MOV        EAX,0x64
    //         0040c165     SUB        EAX,ESI
    //         0040c167     SUB        EAX,EDX
    //                              aidipmod.cpp:131 (2)
    //         0040c169     JNS        LAB_0040c181
    //                              aidipmod.cpp:132 (2)
    //         0040c16b     XOR        EAX,EAX
    //                              aidipmod.cpp:138 (5)
    //         0040c16d     POP        EDI
    //         0040c16e     POP        ESI
    //         0040c16f     RET        0x8
    //                               LAB_0040c172                                                 XREF[1]:     0040c128(j)  
    //                              aidipmod.cpp:118 (7)
    //         0040c172     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->dislikeTa
    //                              aidipmod.cpp:138 (5)
    //         0040c179     POP        EDI
    //         0040c17a     POP        ESI
    //         0040c17b     RET        0x8
    //                               LAB_0040c17e                                                 XREF[3]:     0040c108(j), 0040c11f(j), 
    //                                                                                                         0040c12e(j)  
    //                              aidipmod.cpp:113 (3)
    //         0040c17e     OR         EAX,0xffffffff
    //                               LAB_0040c181                                                 XREF[1]:     0040c169(j)  
    //                              aidipmod.cpp:138 (5)
    //         0040c181     POP        EDI
    //         0040c182     POP        ESI
    //         0040c183     RET        0x8
    //         0040c186     ??         90h
    //         0040c187     NOP
    //         0040c188     NOP
    //         0040c189     NOP
    //         0040c18a     NOP
    //         0040c18b     NOP
    //         0040c18c     NOP
    //         0040c18d     NOP
    //         0040c18e     NOP
    //         0040c18f     NOP
    return 0;
}

void DiplomacyAIModule::changeStance(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall changeStance(DiplomacyAIModule * this, int param_1, 
    //              void              <VOID>         <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c190(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c1b8(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     0040c1ca(R), 0040c23c(R)  
    //                               ?changeStance@DiplomacyAIModule@@QAEXHHH@Z                   XREF[7]:     update:0040c054(c), 
    //                               DiplomacyAIModule::changeStance                                           update:0040c078(c), 
    //                                                                                                         tributeNotify:004e62ec(c), 
    //                                                                                                         tributeNotify:004e62f9(c), 
    //                                                                                                         notify:004f6510(c), 
    //                                                                                                         notify:004f6532(c), 
    //                                                                                                         notifyAI:00515d4b(c)  
    //                              aidipmod.cpp:144 (40)
    //         0040c190     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c194     PUSH       ESI
    //         0040c195     TEST       EAX,EAX
    //         0040c197     JLE        LAB_0040c2a7
    //         0040c19d     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c1a3     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c1a9     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c1ac     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c1b0     CMP        EAX,EDX
    //         0040c1b2     JGE        LAB_0040c2a7
    //                              aidipmod.cpp:153 (18)
    //         0040c1b8     MOV        EDX,dword ptr [ESP + param_2]
    //         0040c1bc     SUB        EDX,0x0
    //         0040c1bf     JZ         LAB_0040c23c
    //         0040c1c1     SUB        EDX,0x2
    //         0040c1c4     JNZ        LAB_0040c2a7
    //                              aidipmod.cpp:174 (20)
    //         0040c1ca     MOV        EDX,dword ptr [ESP + param_3]
    //         0040c1ce     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->likeTable
    //         0040c1d5     ADD        ESI,EDX
    //         0040c1d7     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:175 (12)
    //         0040c1de     CMP        byte ptr [ECX + EAX*0x1 + this->changeableTabl
    //         0040c1e6     MOV        EDX,ESI
    //         0040c1e8     JZ         LAB_0040c215
    //                              aidipmod.cpp:176 (4)
    //         0040c1ea     TEST       EDX,EDX
    //         0040c1ec     JGE        LAB_0040c1fd
    //                              aidipmod.cpp:177 (11)
    //         0040c1ee     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:189 (4)
    //         0040c1f9     POP        ESI
    //         0040c1fa     RET        0xc
    //                               LAB_0040c1fd                                                 XREF[1]:     0040c1ec(j)  
    //                              aidipmod.cpp:178 (9)
    //         0040c1fd     CMP        EDX,0x64
    //         0040c200     JLE        LAB_0040c2a7
    //                              aidipmod.cpp:179 (11)
    //         0040c206     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:189 (4)
    //         0040c211     POP        ESI
    //         0040c212     RET        0xc
    //                               LAB_0040c215                                                 XREF[1]:     0040c1e8(j)  
    //                              aidipmod.cpp:182 (4)
    //         0040c215     TEST       EDX,EDX
    //         0040c217     JGE        LAB_0040c228
    //                              aidipmod.cpp:183 (11)
    //         0040c219     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:189 (4)
    //         0040c224     POP        ESI
    //         0040c225     RET        0xc
    //                               LAB_0040c228                                                 XREF[1]:     0040c217(j)  
    //                              aidipmod.cpp:184 (5)
    //         0040c228     CMP        EDX,0x30
    //         0040c22b     JLE        LAB_0040c2a7
    //                              aidipmod.cpp:185 (11)
    //         0040c22d     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:189 (4)
    //         0040c238     POP        ESI
    //         0040c239     RET        0xc
    //                               LAB_0040c23c                                                 XREF[1]:     0040c1bf(j)  
    //                              aidipmod.cpp:155 (20)
    //         0040c23c     MOV        EDX,dword ptr [ESP + param_3]
    //         0040c240     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->dislikeTa
    //         0040c247     ADD        ESI,EDX
    //         0040c249     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:156 (12)
    //         0040c250     CMP        byte ptr [ECX + EAX*0x1 + this->changeableTabl
    //         0040c258     MOV        EDX,ESI
    //         0040c25a     JZ         LAB_0040c283
    //                              aidipmod.cpp:157 (4)
    //         0040c25c     TEST       EDX,EDX
    //         0040c25e     JGE        LAB_0040c26f
    //                              aidipmod.cpp:158 (11)
    //         0040c260     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:189 (4)
    //         0040c26b     POP        ESI
    //         0040c26c     RET        0xc
    //                               LAB_0040c26f                                                 XREF[1]:     0040c25e(j)  
    //                              aidipmod.cpp:159 (5)
    //         0040c26f     CMP        EDX,0x64
    //         0040c272     JLE        LAB_0040c2a7
    //                              aidipmod.cpp:166 (11)
    //         0040c274     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:189 (4)
    //         0040c27f     POP        ESI
    //         0040c280     RET        0xc
    //                               LAB_0040c283                                                 XREF[1]:     0040c25a(j)  
    //                              aidipmod.cpp:163 (5)
    //         0040c283     CMP        EDX,0x32
    //         0040c286     JGE        LAB_0040c297
    //                              aidipmod.cpp:164 (11)
    //         0040c288     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:189 (4)
    //         0040c293     POP        ESI
    //         0040c294     RET        0xc
    //                               LAB_0040c297                                                 XREF[1]:     0040c286(j)  
    //                              aidipmod.cpp:165 (5)
    //         0040c297     CMP        EDX,0x64
    //         0040c29a     JLE        LAB_0040c2a7
    //                              aidipmod.cpp:166 (11)
    //         0040c29c     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                               LAB_0040c2a7                                                 XREF[7]:     0040c197(j), 0040c1b2(j), 
    //                                                                                                         0040c1c4(j), 0040c200(j), 
    //                                                                                                         0040c22b(j), 0040c272(j), 
    //                                                                                                         0040c29a(j)  
    //                              aidipmod.cpp:189 (4)
    //         0040c2a7     POP        ESI
    //         0040c2a8     RET        0xc
    //         0040c2ab     ??         90h
    //         0040c2ac     NOP
    //         0040c2ad     NOP
    //         0040c2ae     NOP
    //         0040c2af     NOP
    return;
}

void DiplomacyAIModule::setStance(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall setStance(DiplomacyAIModule * this, int param_1, int
    //              void              <VOID>         <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c2b0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c2d7(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     0040c2e9(R), 0040c34c(R)  
    //                               ?setStance@DiplomacyAIModule@@QAEXHHH@Z                      XREF[16]:    update:004e54cc(c), 
    //                               DiplomacyAIModule::setStance                                              update:004e54e4(c), 
    //                                                                                                         update:004e55ec(c), 
    //                                                                                                         update:004e5604(c), 
    //                                                                                                         revokeTributeAlliance:004e64de(c), 
    //                                                                                                         revokeTributeAlliance:004e64f6(c), 
    //                                                                                                         processAICommand:004e673a(c), 
    //                                                                                                         processAICommand:004e67f9(c), 
    //                                                                                                         processAICommand:004e6805(c), 
    //                                                                                                         processAICommand:004e6815(c), 
    //                                                                                                         notify:004f65a5(c), 
    //                                                                                                         processCoopAttack:00502f5a(c), 
    //                                                                                                         loadAIInformation:00515885(c), 
    //                                                                                                         loadAIInformation:005158ab(c), 
    //                                                                                                         loadAIInformation:005158cf(c), 
    //                                                                                                         loadAIInformation:005158e5(c)  
    //                              aidipmod.cpp:195 (39)
    //         0040c2b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c2b4     TEST       EAX,EAX
    //         0040c2b6     JLE        LAB_0040c3a9
    //         0040c2bc     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c2c2     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c2c8     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c2cb     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c2cf     CMP        EAX,EDX
    //         0040c2d1     JGE        LAB_0040c3a9
    //                              aidipmod.cpp:204 (18)
    //         0040c2d7     MOV        EDX,dword ptr [ESP + param_2]
    //         0040c2db     SUB        EDX,0x0
    //         0040c2de     JZ         LAB_0040c34c
    //         0040c2e0     SUB        EDX,0x2
    //         0040c2e3     JNZ        LAB_0040c3a9
    //                              aidipmod.cpp:225 (11)
    //         0040c2e9     MOV        EDX,dword ptr [ESP + param_3]
    //         0040c2ed     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:226 (10)
    //         0040c2f4     CMP        byte ptr [ECX + EAX*0x1 + this->changeableTabl
    //         0040c2fc     JZ         LAB_0040c327
    //                              aidipmod.cpp:227 (4)
    //         0040c2fe     TEST       EDX,EDX
    //         0040c300     JGE        LAB_0040c310
    //                              aidipmod.cpp:228 (11)
    //         0040c302     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:240 (3)
    //         0040c30d     RET        0xc
    //                               LAB_0040c310                                                 XREF[1]:     0040c300(j)  
    //                              aidipmod.cpp:229 (9)
    //         0040c310     CMP        EDX,0x64
    //         0040c313     JLE        LAB_0040c3a9
    //                              aidipmod.cpp:230 (11)
    //         0040c319     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:240 (3)
    //         0040c324     RET        0xc
    //                               LAB_0040c327                                                 XREF[1]:     0040c2fc(j)  
    //                              aidipmod.cpp:233 (4)
    //         0040c327     TEST       EDX,EDX
    //         0040c329     JGE        LAB_0040c339
    //                              aidipmod.cpp:234 (11)
    //         0040c32b     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:240 (3)
    //         0040c336     RET        0xc
    //                               LAB_0040c339                                                 XREF[1]:     0040c329(j)  
    //                              aidipmod.cpp:235 (5)
    //         0040c339     CMP        EDX,0x30
    //         0040c33c     JLE        LAB_0040c3a9
    //                              aidipmod.cpp:236 (11)
    //         0040c33e     MOV        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //                              aidipmod.cpp:240 (3)
    //         0040c349     RET        0xc
    //                               LAB_0040c34c                                                 XREF[1]:     0040c2de(j)  
    //                              aidipmod.cpp:206 (11)
    //         0040c34c     MOV        EDX,dword ptr [ESP + param_3]
    //         0040c350     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:207 (10)
    //         0040c357     CMP        byte ptr [ECX + EAX*0x1 + this->changeableTabl
    //         0040c35f     JZ         LAB_0040c386
    //                              aidipmod.cpp:208 (4)
    //         0040c361     TEST       EDX,EDX
    //         0040c363     JGE        LAB_0040c373
    //                              aidipmod.cpp:209 (11)
    //         0040c365     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:240 (3)
    //         0040c370     RET        0xc
    //                               LAB_0040c373                                                 XREF[1]:     0040c363(j)  
    //                              aidipmod.cpp:210 (5)
    //         0040c373     CMP        EDX,0x64
    //         0040c376     JLE        LAB_0040c3a9
    //                              aidipmod.cpp:217 (11)
    //         0040c378     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:240 (3)
    //         0040c383     RET        0xc
    //                               LAB_0040c386                                                 XREF[1]:     0040c35f(j)  
    //                              aidipmod.cpp:214 (5)
    //         0040c386     CMP        EDX,0x32
    //         0040c389     JGE        LAB_0040c399
    //                              aidipmod.cpp:215 (11)
    //         0040c38b     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                              aidipmod.cpp:240 (3)
    //         0040c396     RET        0xc
    //                               LAB_0040c399                                                 XREF[1]:     0040c389(j)  
    //                              aidipmod.cpp:216 (5)
    //         0040c399     CMP        EDX,0x64
    //         0040c39c     JLE        LAB_0040c3a9
    //                              aidipmod.cpp:217 (11)
    //         0040c39e     MOV        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //                               LAB_0040c3a9                                                 XREF[7]:     0040c2b6(j), 0040c2d1(j), 
    //                                                                                                         0040c2e3(j), 0040c313(j), 
    //                                                                                                         0040c33c(j), 0040c376(j), 
    //                                                                                                         0040c39c(j)  
    //                              aidipmod.cpp:240 (3)
    //         0040c3a9     RET        0xc
    //         0040c3ac     ??         90h
    //         0040c3ad     NOP
    //         0040c3ae     NOP
    //         0040c3af     NOP
    //                              * public: int __thiscall DiplomacyAIModule::isDisliked(int)const                                        *
    //                              int __thiscall isDisliked(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c3b0(R)  
    //                               ?isDisliked@DiplomacyAIModule@@QBEHH@Z                       XREF[1]:     isAmbivalent:0040c3f9(c)  
    //                               DiplomacyAIModule::isDisliked
    //                              aidipmod.cpp:245 (31)
    //         0040c3b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c3b4     TEST       EAX,EAX
    //         0040c3b6     JLE        LAB_0040c3e1
    //         0040c3b8     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c3be     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c3c4     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c3c7     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c3cb     CMP        EAX,EDX
    //         0040c3cd     JGE        LAB_0040c3e1
    //                              aidipmod.cpp:249 (10)
    //         0040c3cf     CMP        dword ptr [ECX + EAX*0x4 + this->dislikeTable[
    //         0040c3d7     JLE        LAB_0040c3e1
    //                              aidipmod.cpp:250 (5)
    //         0040c3d9     MOV        EAX,0x1
    //                              aidipmod.cpp:252 (3)
    //         0040c3de     RET        0x4
    //                               LAB_0040c3e1                                                 XREF[3]:     0040c3b6(j), 0040c3cd(j), 
    //                                                                                                         0040c3d7(j)  
    //                              aidipmod.cpp:251 (2)
    //         0040c3e1     XOR        EAX,EAX
    //                              aidipmod.cpp:252 (3)
    //         0040c3e3     RET        0x4
    //         0040c3e6     ??         90h
    //         0040c3e7     NOP
    //         0040c3e8     NOP
    //         0040c3e9     NOP
    //         0040c3ea     NOP
    //         0040c3eb     NOP
    //         0040c3ec     NOP
    //         0040c3ed     NOP
    //         0040c3ee     NOP
    //         0040c3ef     NOP
    //                              * public: int __thiscall DiplomacyAIModule::isAmbivalent(int)const                                      *
    //                              int __thiscall isAmbivalent(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c3f2(R)  
    //                               ?isAmbivalent@DiplomacyAIModule@@QBEHH@Z
    //                               DiplomacyAIModule::isAmbivalent
    //                              aidipmod.cpp:257 (2)
    //         0040c3f0     PUSH       ESI
    //         0040c3f1     PUSH       EDI
    //                              aidipmod.cpp:258 (28)
    //         0040c3f2     MOV        EDI,dword ptr [ESP + param_1]
    //         0040c3f6     MOV        ESI,this
    //         0040c3f8     PUSH       EDI
    //         0040c3f9     CALL       DiplomacyAIModule::isDisliked                    int isDisliked(DiplomacyAIModule * this, int 
    //         0040c3fe     TEST       EAX,EAX
    //         0040c400     JNZ        LAB_0040c418
    //         0040c402     PUSH       EDI
    //         0040c403     MOV        this,ESI
    //         0040c405     CALL       DiplomacyAIModule::isLiked                       int isLiked(DiplomacyAIModule * this, int par
    //         0040c40a     TEST       EAX,EAX
    //         0040c40c     JNZ        LAB_0040c418
    //                              aidipmod.cpp:259 (5)
    //         0040c40e     MOV        EAX,0x1
    //                              aidipmod.cpp:261 (12)
    //         0040c413     POP        EDI
    //         0040c414     POP        ESI
    //         0040c415     RET        0x4
    //                               LAB_0040c418                                                 XREF[2]:     0040c400(j), 0040c40c(j)  
    //         0040c418     POP        EDI
    //         0040c419     XOR        EAX,EAX
    //         0040c41b     POP        ESI
    //         0040c41c     RET        0x4
    //         0040c41f     ??         90h
    //                              * public: int __thiscall DiplomacyAIModule::isLiked(int)const                                           *
    //                              int __thiscall isLiked(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c420(R)  
    //                               ?isLiked@DiplomacyAIModule@@QBEHH@Z                          XREF[1]:     isAmbivalent:0040c405(c)  
    //                               DiplomacyAIModule::isLiked
    //                              aidipmod.cpp:266 (31)
    //         0040c420     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c424     TEST       EAX,EAX
    //         0040c426     JLE        LAB_0040c451
    //         0040c428     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c42e     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c434     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c437     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c43b     CMP        EAX,EDX
    //         0040c43d     JGE        LAB_0040c451
    //                              aidipmod.cpp:269 (10)
    //         0040c43f     CMP        dword ptr [ECX + EAX*0x4 + this->likeTable[0]]
    //         0040c447     JLE        LAB_0040c451
    //                              aidipmod.cpp:270 (5)
    //         0040c449     MOV        EAX,0x1
    //                              aidipmod.cpp:272 (3)
    //         0040c44e     RET        0x4
    //                               LAB_0040c451                                                 XREF[3]:     0040c426(j), 0040c43d(j), 
    //                                                                                                         0040c447(j)  
    //                              aidipmod.cpp:271 (2)
    //         0040c451     XOR        EAX,EAX
    //                              aidipmod.cpp:272 (3)
    //         0040c453     RET        0x4
    //         0040c456     ??         90h
    //         0040c457     NOP
    //         0040c458     NOP
    //         0040c459     NOP
    //         0040c45a     NOP
    //         0040c45b     NOP
    //         0040c45c     NOP
    //         0040c45d     NOP
    //         0040c45e     NOP
    //         0040c45f     NOP
    //                              * public: int __thiscall DiplomacyAIModule::isChangeable(int)const                                      *
    //                              int __thiscall isChangeable(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c460(R)  
    //                               ?isChangeable@DiplomacyAIModule@@QBEHH@Z                     XREF[4]:     update:004ef388(c), 
    //                               DiplomacyAIModule::isChangeable                                           update:004ef3de(c), 
    //                                                                                                         update:004ef42f(c), 
    //                                                                                                         update:004ef474(c)  
    //                              aidipmod.cpp:277 (31)
    //         0040c460     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c464     TEST       EAX,EAX
    //         0040c466     JLE        LAB_0040c491
    //         0040c468     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c46e     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c474     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c477     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c47b     CMP        EAX,EDX
    //         0040c47d     JGE        LAB_0040c491
    //                              aidipmod.cpp:279 (10)
    //         0040c47f     CMP        byte ptr [ECX + EAX*0x1 + this->changeableTabl
    //         0040c487     JNZ        LAB_0040c491
    //                              aidipmod.cpp:280 (5)
    //         0040c489     MOV        EAX,0x1
    //                              aidipmod.cpp:282 (3)
    //         0040c48e     RET        0x4
    //                               LAB_0040c491                                                 XREF[3]:     0040c466(j), 0040c47d(j), 
    //                                                                                                         0040c487(j)  
    //                              aidipmod.cpp:281 (2)
    //         0040c491     XOR        EAX,EAX
    //                              aidipmod.cpp:282 (3)
    //         0040c493     RET        0x4
    //         0040c496     ??         90h
    //         0040c497     NOP
    //         0040c498     NOP
    //         0040c499     NOP
    //         0040c49a     NOP
    //         0040c49b     NOP
    //         0040c49c     NOP
    //         0040c49d     NOP
    //         0040c49e     NOP
    //         0040c49f     NOP
    return;
}

void DiplomacyAIModule::setChangeable(int param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall setChangeable(DiplomacyAIModule * this, int param_1,
    //              void              <VOID>         <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c4a0(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0040c4bf(R)  
    //                               ?setChangeable@DiplomacyAIModule@@QAEXHE@Z                   XREF[8]:     processAICommand:004e6713(c), 
    //                               DiplomacyAIModule::setChangeable                                          processAICommand:004e678e(c), 
    //                                                                                                         processAICommand:004e67b5(c), 
    //                                                                                                         processAICommand:004e67e2(c), 
    //                                                                                                         processAICommand:004e6829(c), 
    //                                                                                                         notify:004f6588(c), 
    //                                                                                                         notify:004f65db(c), 
    //                                                                                                         loadAIInformation:00515933(c)  
    //                              aidipmod.cpp:287 (31)
    //         0040c4a0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c4a4     TEST       EAX,EAX
    //         0040c4a6     JLE        LAB_0040c4ca
    //         0040c4a8     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c4ae     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c4b4     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0040c4b7     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c4bb     CMP        EAX,EDX
    //         0040c4bd     JGE        LAB_0040c4ca
    //                              aidipmod.cpp:289 (11)
    //         0040c4bf     MOV        DL,byte ptr [ESP + param_2]
    //         0040c4c3     MOV        byte ptr [ECX + EAX*0x1 + this->changeableTabl
    //                               LAB_0040c4ca                                                 XREF[2]:     0040c4a6(j), 0040c4bd(j)  
    //                              aidipmod.cpp:290 (3)
    //         0040c4ca     RET        0x8
    //         0040c4cd     ??         90h
    //         0040c4ce     NOP
    //         0040c4cf     NOP
    //                              * public: int __thiscall DiplomacyAIModule::mostHated(int,int,int,int)const                             *
    //                              int __thiscall mostHated(DiplomacyAIModule * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c523(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c52b(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040c561(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040c501(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040c4da(W), 0040c579(W), 0040c5a2(R)  
    //              int               Stack[-0x8]:4  highest                   XREF[3]:     0040c4de(W), 0040c573(R), 0040c57d(W)  
    //              int               Stack[-0xc]:4  highestValue
    //                               ?mostHated@DiplomacyAIModule@@QBEHHHHH@Z                     XREF[1]:     update:004ef0d7(c)  
    //                               DiplomacyAIModule::mostHated
    //                              aidipmod.cpp:296 (7)
    //         0040c4d0     SUB        ESP,0x8
    //         0040c4d3     PUSH       ESI
    //         0040c4d4     PUSH       EDI
    //         0040c4d5     MOV        EDI,this
    //                              aidipmod.cpp:299 (7)
    //         0040c4d7     OR         EAX,0xffffffff
    //         0040c4da     MOV        dword ptr [ESP + local_4],EAX
    //                              aidipmod.cpp:300 (4)
    //         0040c4de     MOV        dword ptr [ESP + highest],EAX
    //                              aidipmod.cpp:301 (42)
    //         0040c4e2     MOV        EAX,dword ptr [EDI + 0xf0]
    //         0040c4e8     MOV        ESI,0x1
    //         0040c4ed     MOV        this,dword ptr [EAX + 0xf0]
    //         0040c4f3     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0040c4f6     CMP        word ptr [EAX + 0x3c],SI
    //         0040c4fa     JLE        LAB_0040c5a2
    //         0040c500     PUSH       EBP
    //         0040c501     MOV        EBP,dword ptr [ESP + param_4]
    //         0040c505     PUSH       EBX
    //         0040c506     LEA        EBX,[EDI + 0xf8]
    //                               LAB_0040c50c                                                 XREF[1]:     0040c59a(j)  
    //                              aidipmod.cpp:303 (8)
    //         0040c50c     MOVSX      this,word ptr [ECX + this+0x4a]
    //         0040c510     CMP        ESI,this
    //         0040c512     JZ         LAB_0040c581
    //                              aidipmod.cpp:306 (15)
    //         0040c514     MOV        EDX,dword ptr [EAX + 0x40]
    //         0040c517     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         0040c51a     CMP        byte ptr [EAX + 0x80],0x2
    //         0040c521     JZ         LAB_0040c581
    //                              aidipmod.cpp:311 (26)
    //         0040c523     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c527     TEST       EAX,EAX
    //         0040c529     JLE        LAB_0040c53d
    //         0040c52b     CMP        dword ptr [ESP + param_2],ESI
    //         0040c52f     JNZ        LAB_0040c53d
    //         0040c531     PUSH       ESI
    //         0040c532     MOV        this,EDI
    //         0040c534     CALL       DiplomacyAIModule::isAlly                        int isAlly(DiplomacyAIModule * this, int para
    //         0040c539     TEST       EAX,EAX
    //         0040c53b     JNZ        LAB_0040c581
    //                               LAB_0040c53d                                                 XREF[2]:     0040c529(j), 0040c52f(j)  
    //                              aidipmod.cpp:316 (29)
    //         0040c53d     MOV        this,dword ptr [EDI + 0xf0]
    //         0040c543     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c549     MOV        EAX,dword ptr [EDX + 0x3c]
    //         0040c54c     MOV        this,dword ptr [EAX + 0x40]
    //         0040c54f     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         0040c552     MOV        this,dword ptr [EDX + 0x34]
    //         0040c555     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //                              aidipmod.cpp:317 (2)
    //         0040c55a     MOV        this,dword ptr [EBX]
    //                              aidipmod.cpp:318 (5)
    //         0040c55c     CMP        EBP,0x1
    //         0040c55f     JLE        LAB_0040c573
    //                              aidipmod.cpp:321 (5)
    //         0040c561     CMP        dword ptr [ESP + param_3],0x1
    //                              aidipmod.cpp:322 (7)
    //         0040c566     CDQ
    //         0040c567     JNZ        LAB_0040c56f
    //         0040c569     IDIV       EBP
    //         0040c56b     ADD        this,EAX
    //                              aidipmod.cpp:323 (2)
    //         0040c56d     JMP        LAB_0040c573
    //                               LAB_0040c56f                                                 XREF[1]:     0040c567(j)  
    //                              aidipmod.cpp:324 (4)
    //         0040c56f     IDIV       EBP
    //         0040c571     SUB        this,EAX
    //                               LAB_0040c573                                                 XREF[2]:     0040c55f(j), 0040c56d(j)  
    //                              aidipmod.cpp:327 (6)
    //         0040c573     CMP        this,dword ptr [ESP + highest]
    //         0040c577     JLE        LAB_0040c581
    //                              aidipmod.cpp:328 (4)
    //         0040c579     MOV        dword ptr [ESP + local_4],ESI
    //                              aidipmod.cpp:329 (37)
    //         0040c57d     MOV        dword ptr [ESP + highest],this
    //                               LAB_0040c581                                                 XREF[4]:     0040c512(j), 0040c521(j), 
    //                                                                                                         0040c53b(j), 0040c577(j)  
    //         0040c581     MOV        EAX,dword ptr [EDI + 0xf0]
    //         0040c587     INC        ESI
    //         0040c588     ADD        EBX,0x4
    //         0040c58b     MOV        this,dword ptr [EAX + 0xf0]
    //         0040c591     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0040c594     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         0040c598     CMP        ESI,EDX
    //         0040c59a     JL         LAB_0040c50c
    //         0040c5a0     POP        EBX
    //         0040c5a1     POP        EBP
    //                               LAB_0040c5a2                                                 XREF[1]:     0040c4fa(j)  
    //                              aidipmod.cpp:332 (4)
    //         0040c5a2     MOV        EAX,dword ptr [ESP + local_4]
    //                              aidipmod.cpp:333 (8)
    //         0040c5a6     POP        EDI
    //         0040c5a7     POP        ESI
    //         0040c5a8     ADD        ESP,0x8
    //         0040c5ab     RET        0x10
    //         0040c5ae     ??         90h
    //         0040c5af     NOP
    //                              * public: int __thiscall DiplomacyAIModule::mostLiked(int,int)const                                     *
    //                              int __thiscall mostLiked(DiplomacyAIModule * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c60a(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c612(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040c5e7(W), 0040c5ed(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0040c5c6(W), 0040c62a(W), 0040c64c(R)  
    //              int               Stack[-0xc]:4  highest
    //                               ?mostLiked@DiplomacyAIModule@@QBEHHH@Z                       XREF[1]:     update:004ef0fc(c)  
    //                               DiplomacyAIModule::mostLiked
    //                              aidipmod.cpp:338 (8)
    //         0040c5b0     SUB        ESP,0x8
    //         0040c5b3     PUSH       EBX
    //         0040c5b4     PUSH       EBP
    //         0040c5b5     MOV        EBP,this
    //         0040c5b7     PUSH       ESI
    //                              aidipmod.cpp:343 (57)
    //         0040c5b8     MOV        ESI,0x1
    //         0040c5bd     OR         EBX,0xffffffff
    //         0040c5c0     MOV        EAX,dword ptr [EBP + 0xf0]
    //         0040c5c6     MOV        dword ptr [ESP + local_8],EBX
    //         0040c5ca     MOV        this,dword ptr [EAX + 0xf0]
    //         0040c5d0     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0040c5d3     CMP        word ptr [EAX + 0x3c],SI
    //         0040c5d7     JLE        LAB_0040c64c
    //         0040c5d9     MOV        EDX,0xfffffee4
    //         0040c5de     PUSH       EDI
    //         0040c5df     SUB        EDX,EBP
    //         0040c5e1     LEA        EDI,[EBP + 0x120]
    //         0040c5e7     MOV        dword ptr [ESP + local_4],EDX
    //         0040c5eb     JMP        LAB_0040c5f1
    //                               LAB_0040c5ed                                                 XREF[1]:     0040c649(j)  
    //         0040c5ed     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_0040c5f1                                                 XREF[1]:     0040c5eb(j)  
    //                              aidipmod.cpp:345 (8)
    //         0040c5f1     MOVSX      this,word ptr [ECX + this+0x4a]
    //         0040c5f5     CMP        ESI,this
    //         0040c5f7     JZ         LAB_0040c630
    //                              aidipmod.cpp:348 (17)
    //         0040c5f9     MOV        EAX,dword ptr [EAX + 0x40]
    //         0040c5fc     ADD        EAX,EDX
    //         0040c5fe     MOV        this,dword ptr [EAX + EDI*0x1]
    //         0040c601     CMP        byte ptr [ECX + this->_padding_],0x2
    //         0040c608     JZ         LAB_0040c630
    //                              aidipmod.cpp:353 (26)
    //         0040c60a     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c60e     TEST       EAX,EAX
    //         0040c610     JLE        LAB_0040c624
    //         0040c612     CMP        dword ptr [ESP + param_2],ESI
    //         0040c616     JNZ        LAB_0040c624
    //         0040c618     PUSH       ESI
    //         0040c619     MOV        this,EBP
    //         0040c61b     CALL       DiplomacyAIModule::isEnemy                       int isEnemy(DiplomacyAIModule * this, int par
    //         0040c620     TEST       EAX,EAX
    //         0040c622     JNZ        LAB_0040c630
    //                               LAB_0040c624                                                 XREF[2]:     0040c610(j), 0040c616(j)  
    //                              aidipmod.cpp:356 (6)
    //         0040c624     MOV        EAX,dword ptr [EDI]
    //         0040c626     CMP        EAX,EBX
    //         0040c628     JLE        LAB_0040c630
    //                              aidipmod.cpp:357 (4)
    //         0040c62a     MOV        dword ptr [ESP + local_8],ESI
    //                              aidipmod.cpp:358 (29)
    //         0040c62e     MOV        EBX,EAX
    //                               LAB_0040c630                                                 XREF[4]:     0040c5f7(j), 0040c608(j), 
    //                                                                                                         0040c622(j), 0040c628(j)  
    //         0040c630     MOV        EDX,dword ptr [EBP + 0xf0]
    //         0040c636     INC        ESI
    //         0040c637     ADD        EDI,0x4
    //         0040c63a     MOV        this,dword ptr [EDX + 0xf0]
    //         0040c640     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0040c643     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         0040c647     CMP        ESI,EDX
    //         0040c649     JL         LAB_0040c5ed
    //                              aidipmod.cpp:338 (1)
    //         0040c64b     POP        EDI
    //                               LAB_0040c64c                                                 XREF[1]:     0040c5d7(j)  
    //                              aidipmod.cpp:361 (4)
    //         0040c64c     MOV        EAX,dword ptr [ESP + local_8]
    //                              aidipmod.cpp:362 (9)
    //         0040c650     POP        ESI
    //         0040c651     POP        EBP
    //         0040c652     POP        EBX
    //         0040c653     ADD        ESP,0x8
    //         0040c656     RET        0x8
    //         0040c659     ??         90h
    //         0040c65a     NOP
    //         0040c65b     NOP
    //         0040c65c     NOP
    //         0040c65d     NOP
    //         0040c65e     NOP
    //         0040c65f     NOP
    //                              * public: int __thiscall DiplomacyAIModule::isEnemy(int)const                                           *
    //                              int __thiscall isEnemy(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c660(R)  
    //                               ?isEnemy@DiplomacyAIModule@@QBEHH@Z                          XREF[2]:     mostLiked:0040c61b(c), 
    //                               DiplomacyAIModule::isEnemy                                                update:004ef36e(c)  
    //                              aidipmod.cpp:367 (51)
    //         0040c660     MOV        EDX,dword ptr [ESP + param_1]
    //         0040c664     TEST       EDX,EDX
    //         0040c666     JLE        LAB_0040c69b
    //         0040c668     MOV        EAX,dword ptr [ECX + this->md]
    //         0040c66e     MOV        EAX,dword ptr [EAX + 0xf0]
    //         0040c674     MOV        this,dword ptr [EAX + 0x3c]
    //         0040c677     MOVSX      this,word ptr [ECX + this->_padding_]
    //         0040c67b     CMP        EDX,this
    //         0040c67d     JG         LAB_0040c69b
    //         0040c67f     MOVSX      this,word ptr [EAX + 0x4a]
    //         0040c683     CMP        EDX,this
    //         0040c685     JZ         LAB_0040c69b
    //         0040c687     MOV        EAX,dword ptr [EAX + 0x84]
    //         0040c68d     CMP        byte ptr [EAX + EDX*0x1],0x3
    //         0040c691     JNZ        LAB_0040c69b
    //                              aidipmod.cpp:376 (5)
    //         0040c693     MOV        EAX,0x1
    //                              aidipmod.cpp:378 (3)
    //         0040c698     RET        0x4
    //                               LAB_0040c69b                                                 XREF[4]:     0040c666(j), 0040c67d(j), 
    //                                                                                                         0040c685(j), 0040c691(j)  
    //                              aidipmod.cpp:377 (2)
    //         0040c69b     XOR        EAX,EAX
    //                              aidipmod.cpp:378 (3)
    //         0040c69d     RET        0x4
    //                              * public: int __thiscall DiplomacyAIModule::isNeutral(int)const                                         *
    //                              int __thiscall isNeutral(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c6a0(R)  
    //                               ?isNeutral@DiplomacyAIModule@@QBEHH@Z                        XREF[1]:     update:004ef45e(c)  
    //                               DiplomacyAIModule::isNeutral
    //                              aidipmod.cpp:383 (51)
    //         0040c6a0     MOV        EDX,dword ptr [ESP + param_1]
    //         0040c6a4     TEST       EDX,EDX
    //         0040c6a6     JLE        LAB_0040c6db
    //         0040c6a8     MOV        EAX,dword ptr [ECX + this->md]
    //         0040c6ae     MOV        EAX,dword ptr [EAX + 0xf0]
    //         0040c6b4     MOV        this,dword ptr [EAX + 0x3c]
    //         0040c6b7     MOVSX      this,word ptr [ECX + this->_padding_]
    //         0040c6bb     CMP        EDX,this
    //         0040c6bd     JG         LAB_0040c6db
    //         0040c6bf     MOVSX      this,word ptr [EAX + 0x4a]
    //         0040c6c3     CMP        EDX,this
    //         0040c6c5     JZ         LAB_0040c6db
    //         0040c6c7     MOV        EAX,dword ptr [EAX + 0x84]
    //         0040c6cd     CMP        byte ptr [EAX + EDX*0x1],0x1
    //         0040c6d1     JNZ        LAB_0040c6db
    //                              aidipmod.cpp:392 (5)
    //         0040c6d3     MOV        EAX,0x1
    //                              aidipmod.cpp:394 (3)
    //         0040c6d8     RET        0x4
    //                               LAB_0040c6db                                                 XREF[4]:     0040c6a6(j), 0040c6bd(j), 
    //                                                                                                         0040c6c5(j), 0040c6d1(j)  
    //                              aidipmod.cpp:393 (2)
    //         0040c6db     XOR        EAX,EAX
    //                              aidipmod.cpp:394 (3)
    //         0040c6dd     RET        0x4
    //                              * public: int __thiscall DiplomacyAIModule::isAlly(int)const                                            *
    //                              int __thiscall isAlly(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c6e6(R)  
    //                               ?isAlly@DiplomacyAIModule@@QBEHH@Z                           XREF[5]:     update:0040c039(c), 
    //                               DiplomacyAIModule::isAlly                                                 update:0040c05c(c), 
    //                                                                                                         mostHated:0040c534(c), 
    //                                                                                                         update:004ef3c4(c), 
    //                                                                                                         update:004ef445(c)  
    //                              aidipmod.cpp:399 (24)
    //         0040c6e0     MOV        EAX,dword ptr [ECX + this->md]
    //         0040c6e6     MOV        this,dword ptr [ESP + param_1]
    //         0040c6ea     MOV        EAX,dword ptr [EAX + 0xf0]
    //         0040c6f0     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0040c6f4     CMP        this,EDX
    //         0040c6f6     JNZ        LAB_0040c700
    //                              aidipmod.cpp:402 (5)
    //         0040c6f8     MOV        EAX,0x1
    //                              aidipmod.cpp:413 (3)
    //         0040c6fd     RET        0x4
    //                               LAB_0040c700                                                 XREF[1]:     0040c6f6(j)  
    //                              aidipmod.cpp:410 (27)
    //         0040c700     TEST       this,this
    //         0040c702     JLE        LAB_0040c723
    //         0040c704     MOV        EDX,dword ptr [EAX + 0x3c]
    //         0040c707     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0040c70b     CMP        this,EDX
    //         0040c70d     JG         LAB_0040c723
    //         0040c70f     MOV        EAX,dword ptr [EAX + 0x84]
    //         0040c715     CMP        byte ptr [EAX + this->_padding_*0x1],0x0
    //         0040c719     JNZ        LAB_0040c723
    //                              aidipmod.cpp:411 (5)
    //         0040c71b     MOV        EAX,0x1
    //                              aidipmod.cpp:413 (3)
    //         0040c720     RET        0x4
    //                               LAB_0040c723                                                 XREF[3]:     0040c702(j), 0040c70d(j), 
    //                                                                                                         0040c719(j)  
    //                              aidipmod.cpp:412 (2)
    //         0040c723     XOR        EAX,EAX
    //                              aidipmod.cpp:413 (3)
    //         0040c725     RET        0x4
    //         0040c728     ??         90h
    //         0040c729     NOP
    //         0040c72a     NOP
    //         0040c72b     NOP
    //         0040c72c     NOP
    //         0040c72d     NOP
    //         0040c72e     NOP
    //         0040c72f     NOP
    //                              * public: int __thiscall DiplomacyAIModule::isAlliedWithMe(int)const                                    *
    //                              int __thiscall isAlliedWithMe(DiplomacyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c730(R)  
    //                               ?isAlliedWithMe@DiplomacyAIModule@@QBEHH@Z                   XREF[2]:     update:0040c045(c), 
    //                               DiplomacyAIModule::isAlliedWithMe                                         update:0040c068(c)  
    //                              aidipmod.cpp:418 (32)
    //         0040c730     MOV        EDX,dword ptr [ESP + param_1]
    //         0040c734     PUSH       ESI
    //         0040c735     TEST       EDX,EDX
    //         0040c737     JLE        LAB_0040c771
    //         0040c739     MOV        EAX,dword ptr [ECX + this->md]
    //         0040c73f     MOV        ESI,dword ptr [EAX + 0xf0]
    //         0040c745     MOV        EAX,dword ptr [ESI + 0x3c]
    //         0040c748     MOVSX      this,word ptr [EAX + 0x3c]
    //         0040c74c     CMP        EDX,this
    //         0040c74e     JGE        LAB_0040c771
    //                              aidipmod.cpp:423 (6)
    //         0040c750     MOV        EAX,dword ptr [EAX + 0x40]
    //         0040c753     MOV        this,dword ptr [EAX + EDX*0x4]
    //                              aidipmod.cpp:424 (18)
    //         0040c756     TEST       this,this
    //         0040c758     JZ         LAB_0040c771
    //         0040c75a     MOVSX      EAX,word ptr [ESI + 0x4a]
    //         0040c75e     MOV        EDX,dword ptr [this->_padding_]
    //         0040c760     PUSH       EAX
    //         0040c761     CALL       dword ptr [EDX + 0x1c]
    //         0040c764     TEST       EAX,EAX
    //         0040c766     JZ         LAB_0040c771
    //                              aidipmod.cpp:425 (5)
    //         0040c768     MOV        EAX,0x1
    //                              aidipmod.cpp:427 (4)
    //         0040c76d     POP        ESI
    //         0040c76e     RET        0x4
    //                               LAB_0040c771                                                 XREF[4]:     0040c737(j), 0040c74e(j), 
    //                                                                                                         0040c758(j), 0040c766(j)  
    //                              aidipmod.cpp:421 (2)
    //         0040c771     XOR        EAX,EAX
    //                              aidipmod.cpp:427 (4)
    //         0040c773     POP        ESI
    //         0040c774     RET        0x4
    //         0040c777     ??         90h
    //         0040c778     NOP
    //         0040c779     NOP
    //         0040c77a     NOP
    //         0040c77b     NOP
    //         0040c77c     NOP
    //         0040c77d     NOP
    //         0040c77e     NOP
    //         0040c77f     NOP
    return;
}

void DiplomacyAIModule::setRelation(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall setRelation(DiplomacyAIModule * this, int param_1, i
    //              void              <VOID>         <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c780(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c7ac(R)  
    //                               ?setRelation@DiplomacyAIModule@@QAEXHH@Z                     XREF[4]:     processAICommand:004e6744(c), 
    //                               DiplomacyAIModule::setRelation                                            processAICommand:004e681f(c), 
    //                                                                                                         update:004ef48c(c), 
    //                                                                                                         notify:004f65c0(c)  
    //                              aidipmod.cpp:432 (33)
    //         0040c780     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c784     PUSH       EBX
    //         0040c785     TEST       EAX,EAX
    //         0040c787     PUSH       ESI
    //         0040c788     JLE        LAB_0040c7b9
    //         0040c78a     MOV        EDX,dword ptr [ECX + this->md]
    //         0040c790     MOV        EDX,dword ptr [EDX + 0xf0]
    //         0040c796     MOV        ESI,dword ptr [EDX + 0x3c]
    //         0040c799     MOVSX      ESI,word ptr [ESI + 0x3c]
    //         0040c79d     CMP        EAX,ESI
    //         0040c79f     JGE        LAB_0040c7b9
    //                              aidipmod.cpp:438 (11)
    //         0040c7a1     MOV        BL,byte ptr [ECX + EAX*0x1 + this->changeableT
    //         0040c7a8     TEST       BL,BL
    //         0040c7aa     JZ         LAB_0040c7b9
    //                              aidipmod.cpp:441 (13)
    //         0040c7ac     MOV        this,dword ptr [ESP + param_2]
    //         0040c7b0     MOV        ESI,dword ptr [EDX]
    //         0040c7b2     PUSH       this
    //         0040c7b3     PUSH       EAX
    //         0040c7b4     MOV        this,EDX
    //         0040c7b6     CALL       dword ptr [ESI + 0x28]
    //                               LAB_0040c7b9                                                 XREF[3]:     0040c788(j), 0040c79f(j), 
    //                                                                                                         0040c7aa(j)  
    //                              aidipmod.cpp:442 (5)
    //         0040c7b9     POP        ESI
    //         0040c7ba     POP        EBX
    //         0040c7bb     RET        0x8
    //         0040c7be     ??         90h
    //         0040c7bf     NOP
    return;
}

int DiplomacyAIModule::stance(int param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isDisliked(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isAmbivalent(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isLiked(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isChangeable(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::mostHated(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::mostLiked(int param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isEnemy(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isNeutral(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isAlly(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DiplomacyAIModule::isAlliedWithMe(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

