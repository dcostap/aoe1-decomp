#include "common.h"
#include "tairesmd.h"

TribeResourceAIModule::TribeResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeResourceAIModule(TribeResourceAIModule * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004e6b40(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e6b48(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004e6b5e(R)  
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //              int               Stack[0x18]:4  param_6
    //                               ??0TribeResourceAIModule@@QAE@PAXHHHHH@Z                     XREF[1]:     TribeMainDecisionAIModule:004e48ae
    //                               TribeResourceAIModule::TribeResourceAIModule
    //                              tairesmd.cpp:30 (56)
    //         004e6b40     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6b44     PUSH       ESI
    //         004e6b45     MOV        ESI,this
    //         004e6b47     PUSH       EAX
    //         004e6b48     MOV        this,dword ptr [ESP + param_2]
    //         004e6b4c     PUSH       this
    //         004e6b4d     PUSH       0x3ef
    //         004e6b52     PUSH       s_Resource_AI                                    = "Resource AI"
    //         004e6b57     MOV        this,ESI
    //         004e6b59     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         004e6b5e     MOV        EDX,dword ptr [ESP + param_3]
    //         004e6b62     MOV        dword ptr [ESI + 0xf0],0x0
    //         004e6b6c     MOV        dword ptr [ESI + 0xf4],EDX
    //         004e6b72     MOV        dword ptr [ESI],TribeResourceAIModule::`vftable' = 004e6b80
    //                              tairesmd.cpp:31 (6)
    //         004e6b78     MOV        EAX,ESI
    //         004e6b7a     POP        ESI
    //         004e6b7b     RET        0x18
    //         004e6b7e     ??         90h
    //         004e6b7f     NOP
}

TribeResourceAIModule::TribeResourceAIModule(int param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeResourceAIModule(TribeResourceAIModule * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6bb6(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e6bd3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004e6be1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004e6bfe(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004e6bca(W)  
    //                               ??0TribeResourceAIModule@@QAE@HH@Z                           XREF[1]:     TribeMainDecisionAIModule:004e4c1e
    //                               TribeResourceAIModule::TribeResourceAIModule
    //                              tairesmd.cpp:38 (51)
    //         004e6ba0     PUSH       -0x1
    //         004e6ba2     PUSH       FUN_00560768
    //         004e6ba7     MOV        EAX,FS:[0x0]
    //         004e6bad     PUSH       EAX
    //         004e6bae     MOV        dword ptr FS:[0x0],ESP
    //         004e6bb5     PUSH       this
    //         004e6bb6     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6bba     PUSH       ESI
    //         004e6bbb     PUSH       0x0
    //         004e6bbd     PUSH       EAX
    //         004e6bbe     MOV        ESI,this
    //         004e6bc0     PUSH       0x3ef
    //         004e6bc5     PUSH       s_ResAI                                          = "ResAI"
    //         004e6bca     MOV        dword ptr [ESP + local_10],ESI
    //         004e6bce     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //                              tairesmd.cpp:39 (43)
    //         004e6bd3     MOV        EDX,dword ptr [ESP + param_2]
    //         004e6bd7     LEA        this,[ESI + 0xf4]
    //         004e6bdd     PUSH       0x4
    //         004e6bdf     PUSH       this
    //         004e6be0     PUSH       EDX
    //         004e6be1     MOV        dword ptr [ESP + local_4],0x0
    //         004e6be9     MOV        dword ptr [ESI + 0xf0],0x0
    //         004e6bf3     MOV        dword ptr [ESI],TribeResourceAIModule::`vftable' = 004e6b80
    //         004e6bf9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              tairesmd.cpp:40 (23)
    //         004e6bfe     MOV        this,dword ptr [ESP + local_c]
    //         004e6c02     ADD        ESP,0xc
    //         004e6c05     MOV        EAX,ESI
    //         004e6c07     MOV        dword ptr FS:[0x0],this
    //         004e6c0e     POP        ESI
    //         004e6c0f     ADD        ESP,0x10
    //         004e6c12     RET        0x8
    //         004e6c15     ??         90h
    //         004e6c16     NOP
    //         004e6c17     NOP
    //         004e6c18     NOP
    //         004e6c19     NOP
    //         004e6c1a     NOP
    //         004e6c1b     NOP
    //         004e6c1c     NOP
    //         004e6c1d     NOP
    //         004e6c1e     NOP
    //         004e6c1f     NOP
}

TribeResourceAIModule::~TribeResourceAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeResourceAIModule(TribeResourceAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //                               ??1TribeResourceAIModule@@UAE@XZ                             XREF[4]:     ~TribeMainDecisionAIModule:004e4f2
    //                               TribeResourceAIModule::~TribeResourceAIModule                             `scalar_deleting_destructor':004e6
    //                                                                                                         FUN_0056066e:00560677(c), 
    //                                                                                                         FUN_005606fe:00560707(c)  
    //                              tairesmd.cpp:45 (11)
    //         004e6c20     MOV        dword ptr [this->_padding_],TribeResourceAIMod   = 004e6b80
    //         004e6c26     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         004e6c2b     ??         90h
    //         004e6c2c     NOP
    //         004e6c2d     NOP
    //         004e6c2e     NOP
    //         004e6c2f     NOP
}

void TribeResourceAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setMainDecisionAI(TribeResourceAIModule * this, Trib
    //              void              <VOID>         <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              TribeMainDecis    Stack[0x4]:4   param_1                   XREF[1]:     004e6c30(R)  
    //                               ?setMainDecisionAI@TribeResourceAIModule@@QAEXPAVTribeMainD  XREF[2]:     TribeMainDecisionAIModule:004e49b5
    //                               TribeResourceAIModule::setMainDecisionAI                                  TribeMainDecisionAIModule:004e4cfc
    //                              tairesmd.cpp:51 (10)
    //         004e6c30     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6c34     MOV        dword ptr [ECX + this->md],EAX
    //                              tairesmd.cpp:53 (3)
    //         004e6c3a     RET        0x4
    //         004e6c3d     ??         90h
    //         004e6c3e     NOP
    //         004e6c3f     NOP
    return;
}

int TribeResourceAIModule::save(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall save(TribeResourceAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6c40(R)  
    //                               ?save@TribeResourceAIModule@@UAEHH@Z                         XREF[1]:     00575674(*)  
    //                               TribeResourceAIModule::save
    //                              tairesmd.cpp:58 (22)
    //         004e6c40     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6c44     ADD        this,0xf4
    //         004e6c4a     PUSH       0x4
    //         004e6c4c     PUSH       this
    //         004e6c4d     PUSH       EAX
    //         004e6c4e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e6c53     ADD        ESP,0xc
    //                              tairesmd.cpp:60 (5)
    //         004e6c56     MOV        EAX,0x1
    //                              tairesmd.cpp:61 (3)
    //         004e6c5b     RET        0x4
    //         004e6c5e     ??         90h
    //         004e6c5f     NOP
    //                              * public: int __thiscall TribeResourceAIModule::numberResources(void)const                              *
    //                              int __thiscall numberResources(TribeResourceAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //                               ?numberResources@TribeResourceAIModule@@QBEHXZ
    //                               TribeResourceAIModule::numberResources
    //                              tairesmd.cpp:66 (6)
    //         004e6c60     MOV        EAX,dword ptr [ECX + this->numberResourcesValue]
    //                              tairesmd.cpp:68 (1)
    //         004e6c66     RET
    //         004e6c67     ??         90h
    //         004e6c68     NOP
    //         004e6c69     NOP
    //         004e6c6a     NOP
    //         004e6c6b     NOP
    //         004e6c6c     NOP
    //         004e6c6d     NOP
    //         004e6c6e     NOP
    //         004e6c6f     NOP
    //                              * public: int __thiscall TribeResourceAIModule::resource(int)const                                      *
    //                              int __thiscall resource(TribeResourceAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6c70(R)  
    //                               ?resource@TribeResourceAIModule@@QBEHH@Z                     XREF[28]:    nextBuildableItem:004d46ac(c), 
    //                               TribeResourceAIModule::resource                                           evaluateBuildListInsertions:004f60
    //                                                                                                         updateNeededResources:004f8cb5(c), 
    //                                                                                                         updateNeededResources:004f8cf8(c), 
    //                                                                                                         updateNeededResources:004f8d1b(c), 
    //                                                                                                         updateNeededResources:004f8d3a(c), 
    //                                                                                                         updateNeededResources:004f8d59(c), 
    //                                                                                                         updateGathererDistribution:004f8fd
    //                                                                                                         updateGathererDistribution:004f908
    //                                                                                                         updateGathererDistribution:004f90a
    //                                                                                                         highLevelTaskGatherer:004f9710(c), 
    //                                                                                                         trackUnitGather:00501b10(c), 
    //                                                                                                         numberAvailableStoragePits:00501bc
    //                                                                                                         numberAvailableGranaries:00501ca8(
    //                                                                                                         checkForCoopTributeGift:00502a73(c
    //                                                                                                         checkForCoopTributeGift:00502b84(c
    //                                                                                                         checkForASAPAgeResearch:00502c2e(c
    //                                                                                                         checkForASAPAgeResearch:00502c94(c
    //                                                                                                         checkForASAPAgeResearch:00502d00(c
    //                                                                                                         checkForASAPAgeResearch:00502d1a(c
    //                                                                                                         [more]
    //                              tairesmd.cpp:73 (16)
    //         004e6c70     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6c74     TEST       EAX,EAX
    //         004e6c76     JL         LAB_004e6c9a
    //         004e6c78     CMP        EAX,dword ptr [ECX + this->numberResourcesValue]
    //         004e6c7e     JGE        LAB_004e6c9a
    //                              tairesmd.cpp:76 (23)
    //         004e6c80     MOV        this,dword ptr [ECX + this->md]
    //         004e6c86     MOV        EDX,dword ptr [ECX + this->md]
    //         004e6c8c     MOV        this,dword ptr [EDX + 0x50]
    //         004e6c8f     FLD        float ptr [this->_padding_ + EAX*0x4]
    //         004e6c92     CALL       __ftol                                           undefined __ftol()
    //                              tairesmd.cpp:77 (3)
    //         004e6c97     RET        0x4
    //                               LAB_004e6c9a                                                 XREF[2]:     004e6c76(j), 004e6c7e(j)  
    //                              tairesmd.cpp:75 (3)
    //         004e6c9a     OR         EAX,0xffffffff
    //                              tairesmd.cpp:77 (3)
    //         004e6c9d     RET        0x4
    return 0;
}

int TribeResourceAIModule::resourcesAvailable(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              int __thiscall resourcesAvailable(TribeResourceAIModule * this, Reso
    //              int               EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[3]:     004e6ca4(R), 004e6cf3(W), 004e6cf7(R)  
    //                               ?resourcesAvailable@TribeResourceAIModule@@QAEHPAVResourceI  XREF[6]:     nextBuildableItem:004d4a3c(c), 
    //                               TribeResourceAIModule::resourcesAvailable                                 nextBuildableItem:004d4d34(c), 
    //                                                                                                         blockingResource:004d4f0e(c), 
    //                                                                                                         checkForBuildInsertion:00501e28(c)
    //                                                                                                         checkForBuildInsertion:00501ffe(c)
    //                                                                                                         FUN_005024b3:00502549(c)  
    //                              tairesmd.cpp:82 (4)
    //         004e6ca0     PUSH       EBX
    //         004e6ca1     PUSH       EBP
    //         004e6ca2     PUSH       ESI
    //         004e6ca3     PUSH       EDI
    //                              tairesmd.cpp:83 (10)
    //         004e6ca4     MOV        EDI,dword ptr [ESP + param_1]
    //         004e6ca8     MOV        EBX,this
    //         004e6caa     TEST       EDI,EDI
    //         004e6cac     JNZ        LAB_004e6cb7
    //                              tairesmd.cpp:84 (2)
    //         004e6cae     XOR        EAX,EAX
    //                              tairesmd.cpp:110 (7)
    //         004e6cb0     POP        EDI
    //         004e6cb1     POP        ESI
    //         004e6cb2     POP        EBP
    //         004e6cb3     POP        EBX
    //         004e6cb4     RET        0x4
    //                               LAB_004e6cb7                                                 XREF[1]:     004e6cac(j)  
    //                              tairesmd.cpp:87 (15)
    //         004e6cb7     MOV        this,EDI
    //         004e6cb9     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004e6cbe     CMP        dword ptr [EBX + 0xf4],EAX
    //         004e6cc4     JZ         LAB_004e6ccf
    //                              tairesmd.cpp:88 (2)
    //         004e6cc6     XOR        EAX,EAX
    //                              tairesmd.cpp:110 (7)
    //         004e6cc8     POP        EDI
    //         004e6cc9     POP        ESI
    //         004e6cca     POP        EBP
    //         004e6ccb     POP        EBX
    //         004e6ccc     RET        0x4
    //                               LAB_004e6ccf                                                 XREF[1]:     004e6cc4(j)  
    //                              tairesmd.cpp:96 (13)
    //         004e6ccf     MOV        this,EDI
    //         004e6cd1     XOR        ESI,ESI
    //         004e6cd3     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004e6cd8     TEST       EAX,EAX
    //         004e6cda     JLE        LAB_004e6d27
    //                               LAB_004e6cdc                                                 XREF[1]:     004e6d10(j)  
    //                              tairesmd.cpp:101 (54)
    //         004e6cdc     MOV        EAX,dword ptr [EBX + 0xf0]
    //         004e6ce2     PUSH       ESI
    //         004e6ce3     MOV        this,dword ptr [EAX + 0xf0]
    //         004e6ce9     MOV        EBP,dword ptr [ECX + this->_padding_]
    //         004e6cec     MOV        this,EDI
    //         004e6cee     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         004e6cf3     MOV        dword ptr [ESP + param_1],EAX
    //         004e6cf7     FILD       dword ptr [ESP + param_1]
    //         004e6cfb     FCOMP      float ptr [EBP + ESI*0x4]
    //         004e6cff     FNSTSW     AX
    //         004e6d01     TEST       AH,0x41
    //         004e6d04     JZ         LAB_004e6d1e
    //         004e6d06     MOV        this,EDI
    //         004e6d08     INC        ESI
    //         004e6d09     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004e6d0e     CMP        ESI,EAX
    //         004e6d10     JL         LAB_004e6cdc
    //                              tairesmd.cpp:109 (5)
    //         004e6d12     MOV        EAX,0x1
    //                              tairesmd.cpp:110 (7)
    //         004e6d17     POP        EDI
    //         004e6d18     POP        ESI
    //         004e6d19     POP        EBP
    //         004e6d1a     POP        EBX
    //         004e6d1b     RET        0x4
    //                               LAB_004e6d1e                                                 XREF[1]:     004e6d04(j)  
    //                              tairesmd.cpp:106 (2)
    //         004e6d1e     XOR        EAX,EAX
    //                              tairesmd.cpp:110 (19)
    //         004e6d20     POP        EDI
    //         004e6d21     POP        ESI
    //         004e6d22     POP        EBP
    //         004e6d23     POP        EBX
    //         004e6d24     RET        0x4
    //                               LAB_004e6d27                                                 XREF[1]:     004e6cda(j)  
    //         004e6d27     POP        EDI
    //         004e6d28     POP        ESI
    //         004e6d29     POP        EBP
    //         004e6d2a     MOV        EAX,0x1
    //         004e6d2f     POP        EBX
    //         004e6d30     RET        0x4
    //         004e6d33     ??         90h
    //         004e6d34     NOP
    //         004e6d35     NOP
    //         004e6d36     NOP
    //         004e6d37     NOP
    //         004e6d38     NOP
    //         004e6d39     NOP
    //         004e6d3a     NOP
    //         004e6d3b     NOP
    //         004e6d3c     NOP
    //         004e6d3d     NOP
    //         004e6d3e     NOP
    //         004e6d3f     NOP
    return 0;
}

int TribeResourceAIModule::unavailableResource(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              int __thiscall unavailableResource(TribeResourceAIModule * this, Res
    //              int               EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[3]:     004e6d44(R), 004e6d8a(W), 004e6d8e(R)  
    //                               ?unavailableResource@TribeResourceAIModule@@QAEHPAVResource  XREF[1]:     blockingResource:004d4f28(c)  
    //                               TribeResourceAIModule::unavailableResource
    //                              tairesmd.cpp:115 (4)
    //         004e6d40     PUSH       EBX
    //         004e6d41     PUSH       EBP
    //         004e6d42     PUSH       ESI
    //         004e6d43     PUSH       EDI
    //                              tairesmd.cpp:116 (10)
    //         004e6d44     MOV        EDI,dword ptr [ESP + param_1]
    //         004e6d48     MOV        EBX,this
    //         004e6d4a     TEST       EDI,EDI
    //         004e6d4c     JNZ        LAB_004e6d57
    //                              tairesmd.cpp:117 (2)
    //         004e6d4e     XOR        EAX,EAX
    //                              tairesmd.cpp:128 (7)
    //         004e6d50     POP        EDI
    //         004e6d51     POP        ESI
    //         004e6d52     POP        EBP
    //         004e6d53     POP        EBX
    //         004e6d54     RET        0x4
    //                               LAB_004e6d57                                                 XREF[1]:     004e6d4c(j)  
    //                              tairesmd.cpp:120 (13)
    //         004e6d57     MOV        this,EDI
    //         004e6d59     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004e6d5e     CMP        dword ptr [EBX + 0xf4],EAX
    //                              tairesmd.cpp:121 (2)
    //         004e6d64     JNZ        LAB_004e6dbc
    //                              tairesmd.cpp:124 (13)
    //         004e6d66     MOV        this,EDI
    //         004e6d68     XOR        ESI,ESI
    //         004e6d6a     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004e6d6f     TEST       EAX,EAX
    //         004e6d71     JLE        LAB_004e6dbc
    //                               LAB_004e6d73                                                 XREF[1]:     004e6da7(j)  
    //                              tairesmd.cpp:125 (54)
    //         004e6d73     MOV        EAX,dword ptr [EBX + 0xf0]
    //         004e6d79     PUSH       ESI
    //         004e6d7a     MOV        this,dword ptr [EAX + 0xf0]
    //         004e6d80     MOV        EBP,dword ptr [ECX + this->_padding_]
    //         004e6d83     MOV        this,EDI
    //         004e6d85     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         004e6d8a     MOV        dword ptr [ESP + param_1],EAX
    //         004e6d8e     FILD       dword ptr [ESP + param_1]
    //         004e6d92     FCOMP      float ptr [EBP + ESI*0x4]
    //         004e6d96     FNSTSW     AX
    //         004e6d98     TEST       AH,0x41
    //         004e6d9b     JZ         LAB_004e6db3
    //         004e6d9d     MOV        this,EDI
    //         004e6d9f     INC        ESI
    //         004e6da0     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004e6da5     CMP        ESI,EAX
    //         004e6da7     JL         LAB_004e6d73
    //                              tairesmd.cpp:127 (3)
    //         004e6da9     OR         EAX,0xffffffff
    //                              tairesmd.cpp:128 (7)
    //         004e6dac     POP        EDI
    //         004e6dad     POP        ESI
    //         004e6dae     POP        EBP
    //         004e6daf     POP        EBX
    //         004e6db0     RET        0x4
    //                               LAB_004e6db3                                                 XREF[1]:     004e6d9b(j)  
    //                              tairesmd.cpp:126 (2)
    //         004e6db3     MOV        EAX,ESI
    //                              tairesmd.cpp:128 (17)
    //         004e6db5     POP        EDI
    //         004e6db6     POP        ESI
    //         004e6db7     POP        EBP
    //         004e6db8     POP        EBX
    //         004e6db9     RET        0x4
    //                               LAB_004e6dbc                                                 XREF[2]:     004e6d64(j), 004e6d71(j)  
    //         004e6dbc     POP        EDI
    //         004e6dbd     POP        ESI
    //         004e6dbe     POP        EBP
    //         004e6dbf     OR         EAX,0xffffffff
    //         004e6dc2     POP        EBX
    //         004e6dc3     RET        0x4
    //         004e6dc6     ??         90h
    //         004e6dc7     NOP
    //         004e6dc8     NOP
    //         004e6dc9     NOP
    //         004e6dca     NOP
    //         004e6dcb     NOP
    //         004e6dcc     NOP
    //         004e6dcd     NOP
    //         004e6dce     NOP
    //         004e6dcf     NOP
    return 0;
}

char* TribeResourceAIModule::resourceName(int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall resourceName(TribeResourceAIModule * this, int par
    //              char *            EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6dd0(R)  
    //                               ?resourceName@TribeResourceAIModule@@QAEPADH@Z               XREF[12]:    aiStatus:00514887(c), 
    //                               TribeResourceAIModule::resourceName                                       aiStatus:005148c1(c), 
    //                                                                                                         aiStatus:005148fb(c), 
    //                                                                                                         aiStatus:00514935(c), 
    //                                                                                                         aiStatus:0051496f(c), 
    //                                                                                                         aiStatus:005149a9(c), 
    //                                                                                                         aiStatus:005149e3(c), 
    //                                                                                                         aiStatus:00514a1d(c), 
    //                                                                                                         aiStatus:00514ac2(c), 
    //                                                                                                         aiStatus:00514b10(c), 
    //                                                                                                         aiStatus:00514b5e(c), 
    //                                                                                                         aiStatus:00514bac(c)  
    //                              tairesmd.cpp:133 (8)
    //         004e6dd0     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6dd4     TEST       EAX,EAX
    //         004e6dd6     JNZ        LAB_004e6de0
    //                              tairesmd.cpp:135 (5)
    //         004e6dd8     MOV        EAX,s_Food                                       = "Food"
    //                              tairesmd.cpp:143 (3)
    //         004e6ddd     RET        0x4
    //                               LAB_004e6de0                                                 XREF[1]:     004e6dd6(j)  
    //                              tairesmd.cpp:136 (5)
    //         004e6de0     CMP        EAX,0x1
    //         004e6de3     JNZ        LAB_004e6ded
    //                              tairesmd.cpp:137 (5)
    //         004e6de5     MOV        EAX,s_Wood                                       = "Wood"
    //                              tairesmd.cpp:143 (3)
    //         004e6dea     RET        0x4
    //                               LAB_004e6ded                                                 XREF[1]:     004e6de3(j)  
    //                              tairesmd.cpp:138 (5)
    //         004e6ded     CMP        EAX,0x2
    //         004e6df0     JNZ        LAB_004e6dfa
    //                              tairesmd.cpp:139 (5)
    //         004e6df2     MOV        EAX,s_Stone                                      = "Stone"
    //                              tairesmd.cpp:143 (3)
    //         004e6df7     RET        0x4
    //                               LAB_004e6dfa                                                 XREF[1]:     004e6df0(j)  
    //                              tairesmd.cpp:140 (3)
    //         004e6dfa     CMP        EAX,0x3
    //                              tairesmd.cpp:141 (7)
    //         004e6dfd     MOV        EAX,s_Gold                                       = "Gold"
    //         004e6e02     JZ         LAB_004e6e09
    //                              tairesmd.cpp:142 (5)
    //         004e6e04     MOV        EAX,s_Unknown                                    = 55h
    //                               LAB_004e6e09                                                 XREF[1]:     004e6e02(j)  
    //                              tairesmd.cpp:143 (3)
    //         004e6e09     RET        0x4
    //         004e6e0c     ??         90h
    //         004e6e0d     NOP
    //         004e6e0e     NOP
    //         004e6e0f     NOP
    return 0;
}

int TribeResourceAIModule::numberResources() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TribeResourceAIModule::resource(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

