// Auto-generated scaffold unit: taibldmd.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/taibldmd.cpp
#include "../include/common.h"

// Offset: 0x004D3A80
undefined TribeBuildAIModule(TribeBuildAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeBuildAIModule::TribeBuildAIModule(void *,int)                                 *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeBuildAIModule(TribeBuildAIModule * this, v
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004d3a88(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d3a80(R)  
    //                               ??0TribeBuildAIModule@@QAE@PAXH@Z                            XREF[1]:     TribeMainDecisionAIModule:004e4844
    //                               TribeBuildAIModule::TribeBuildAIModule
    //                              taibldmd.cpp:62 (36)
    //         004d3a80     MOV        EAX,dword ptr [ESP + param_2]
    //         004d3a84     PUSH       ESI
    //         004d3a85     MOV        ESI,this
    //         004d3a87     PUSH       EAX
    //         004d3a88     MOV        this,dword ptr [ESP + param_1]
    //         004d3a8c     PUSH       this
    //         004d3a8d     MOV        this,ESI
    //         004d3a8f     CALL       BuildAIModule::BuildAIModule                     undefined BuildAIModule(BuildAIModule * this,
    //         004d3a94     MOV        dword ptr [ESI + 0x5bc],0x0
    //         004d3a9e     MOV        dword ptr [ESI],TribeBuildAIModule::`vftable'    = 004d3ab0
    //                              taibldmd.cpp:63 (6)
    //         004d3aa4     MOV        EAX,ESI
    //         004d3aa6     POP        ESI
    //         004d3aa7     RET        0x8
}

// Offset: 0x004D3AD0
undefined TribeBuildAIModule(TribeBuildAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeBuildAIModule::TribeBuildAIModule(int,int)                                    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeBuildAIModule(TribeBuildAIModule * this, i
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d3ad8(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d3ad0(R)  
    //                               ??0TribeBuildAIModule@@QAE@HH@Z                              XREF[1]:     TribeMainDecisionAIModule:004e4bc4
    //                               TribeBuildAIModule::TribeBuildAIModule
    //                              taibldmd.cpp:70 (36)
    //         004d3ad0     MOV        EAX,dword ptr [ESP + param_2]
    //         004d3ad4     PUSH       ESI
    //         004d3ad5     MOV        ESI,this
    //         004d3ad7     PUSH       EAX
    //         004d3ad8     MOV        this,dword ptr [ESP + param_1]
    //         004d3adc     PUSH       this
    //         004d3add     MOV        this,ESI
    //         004d3adf     CALL       BuildAIModule::BuildAIModule                     undefined BuildAIModule(BuildAIModule * this,
    //         004d3ae4     MOV        dword ptr [ESI + 0x5bc],0x0
    //         004d3aee     MOV        dword ptr [ESI],TribeBuildAIModule::`vftable'    = 004d3ab0
    //                              taibldmd.cpp:71 (6)
    //         004d3af4     MOV        EAX,ESI
    //         004d3af6     POP        ESI
    //         004d3af7     RET        0x8
}

// Offset: 0x004D3B00
void TribeBuildAIModule(TribeBuildAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeBuildAIModule::~TribeBuildAIModule(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeBuildAIModule(TribeBuildAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //                               ??1TribeBuildAIModule@@UAE@XZ                                XREF[4]:     `vector_deleting_destructor':004d3
    //                               TribeBuildAIModule::~TribeBuildAIModule                                   ~TribeMainDecisionAIModule:004e4f7
    //                                                                                                         FUN_00560628:00560631(c), 
    //                                                                                                         FUN_005606b8:005606c1(c)  
    //                              taibldmd.cpp:76 (11)
    //         004d3b00     MOV        dword ptr [this->_padding_],TribeBuildAIModule   = 004d3ab0
    //         004d3b06     JMP        BuildAIModule::~BuildAIModule                    void ~BuildAIModule(BuildAIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004D3B10
void setMainDecisionAI(TribeBuildAIModule* this_, TribeMainDecisionAIModule* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeBuildAIModule::setMainDecisionAI(class TribeMainDecisionAIModule *)      *
    //                              *********************************************************************************************************
    //                              void __thiscall setMainDecisionAI(TribeBuildAIModule * this, TribeMa
    //              void              <VOID>         <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              TribeMainDecis    Stack[0x4]:4   param_1                   XREF[1]:     004d3b10(R)  
    //                               ?setMainDecisionAI@TribeBuildAIModule@@QAEXPAVTribeMainDeci  XREF[2]:     TribeMainDecisionAIModule:004e497d
    //                               TribeBuildAIModule::setMainDecisionAI                                     TribeMainDecisionAIModule:004e4cc0
    //                              taibldmd.cpp:82 (10)
    //         004d3b10     MOV        EAX,dword ptr [ESP + param_1]
    //         004d3b14     MOV        dword ptr [ECX + this->md],EAX
    //                              taibldmd.cpp:84 (3)
    //         004d3b1a     RET        0x4
}

// Offset: 0x004D3B20
int TribeBuildAIModule::loadBuildList(char* param_1, RGE_Player* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TribeBuildAIModule::loadBuildList(char *,class RGE_Player *)           *
    //                              *********************************************************************************************************
    //                              int __thiscall loadBuildList(TribeBuildAIModule * this, char * param
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004d3d42(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     004d3d3e(R)  
    //                               ?loadBuildList@TribeBuildAIModule@@UAEHPADPAVRGE_Player@@@Z  XREF[1]:     00575484(*)  
    //                               TribeBuildAIModule::loadBuildList
    //                              taibldmd.cpp:89 (4)
    //         004d3b20     PUSH       EBX
    //         004d3b21     PUSH       ESI
    //         004d3b22     MOV        ESI,this
    //                              taibldmd.cpp:91 (180)
    //         004d3b24     XOR        EAX,EAX
    //         004d3b26     PUSH       EDI
    //         004d3b27     MOV        this,dword ptr [ESI + 0x5b0]
    //         004d3b2d     TEST       this,this
    //         004d3b2f     JLE        LAB_004d3b50
    //         004d3b31     MOV        EDX,dword ptr [ESI + 0x5b8]
    //                               LAB_004d3b37                                                 XREF[1]:     004d3b4e(j)  
    //         004d3b37     CMP        EAX,EDX
    //         004d3b39     JGE        LAB_004d3b50
    //         004d3b3b     MOV        EDI,dword ptr [ESI + 0x5ac]
    //         004d3b41     CMP        dword ptr [EDI + EAX*0x4],0x46
    //         004d3b45     JZ         LAB_004d3bd8
    //         004d3b4b     INC        EAX
    //         004d3b4c     CMP        EAX,this
    //         004d3b4e     JL         LAB_004d3b37
    //                               LAB_004d3b50                                                 XREF[2]:     004d3b2f(j), 004d3b39(j)  
    //         004d3b50     MOV        EAX,dword ptr [ESI + 0x5b8]
    //         004d3b56     DEC        EAX
    //         004d3b57     CMP        this,EAX
    //         004d3b59     JLE        LAB_004d3bb8
    //         004d3b5b     LEA        EBX,[ECX + this+0x1]
    //         004d3b5e     LEA        this,[EBX*0x4 + 0x0]
    //         004d3b65     PUSH       this
    //         004d3b66     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d3b6b     MOV        EDI,EAX
    //         004d3b6d     ADD        ESP,0x4
    //         004d3b70     TEST       EDI,EDI
    //         004d3b72     JZ         LAB_004d3bb8
    //         004d3b74     MOV        this,dword ptr [ESI + 0x5b8]
    //         004d3b7a     XOR        EAX,EAX
    //         004d3b7c     TEST       this,this
    //         004d3b7e     JLE        LAB_004d3b9d
    //                               LAB_004d3b80                                                 XREF[1]:     004d3b9b(j)  
    //         004d3b80     CMP        EAX,EBX
    //         004d3b82     JGE        LAB_004d3b9d
    //         004d3b84     MOV        EDX,dword ptr [ESI + 0x5ac]
    //         004d3b8a     INC        EAX
    //         004d3b8b     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004d3b8f     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         004d3b93     MOV        this,dword ptr [ESI + 0x5b8]
    //         004d3b99     CMP        EAX,this
    //         004d3b9b     JL         LAB_004d3b80
    //                               LAB_004d3b9d                                                 XREF[2]:     004d3b7e(j), 004d3b82(j)  
    //         004d3b9d     MOV        EDX,dword ptr [ESI + 0x5ac]
    //         004d3ba3     PUSH       EDX
    //         004d3ba4     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d3ba9     ADD        ESP,0x4
    //         004d3bac     MOV        dword ptr [ESI + 0x5ac],EDI
    //         004d3bb2     MOV        dword ptr [ESI + 0x5b8],EBX
    //                               LAB_004d3bb8                                                 XREF[2]:     004d3b59(j), 004d3b72(j)  
    //         004d3bb8     MOV        EAX,dword ptr [ESI + 0x5b0]
    //         004d3bbe     MOV        this,dword ptr [ESI + 0x5ac]
    //         004d3bc4     MOV        dword ptr [this->_padding_ + EAX*0x4],0x46
    //         004d3bcb     MOV        EAX,dword ptr [ESI + 0x5b0]
    //         004d3bd1     INC        EAX
    //         004d3bd2     MOV        dword ptr [ESI + 0x5b0],EAX
    //                               LAB_004d3bd8                                                 XREF[1]:     004d3b45(j)  
    //                              taibldmd.cpp:92 (179)
    //         004d3bd8     MOV        this,dword ptr [ESI + 0x5b0]
    //         004d3bde     XOR        EAX,EAX
    //         004d3be0     TEST       this,this
    //         004d3be2     JLE        LAB_004d3c03
    //         004d3be4     MOV        EDX,dword ptr [ESI + 0x5b8]
    //                               LAB_004d3bea                                                 XREF[1]:     004d3c01(j)  
    //         004d3bea     CMP        EAX,EDX
    //         004d3bec     JGE        LAB_004d3c03
    //         004d3bee     MOV        EDI,dword ptr [ESI + 0x5ac]
    //         004d3bf4     CMP        dword ptr [EDI + EAX*0x4],0x67
    //         004d3bf8     JZ         LAB_004d3c8b
    //         004d3bfe     INC        EAX
    //         004d3bff     CMP        EAX,this
    //         004d3c01     JL         LAB_004d3bea
    //                               LAB_004d3c03                                                 XREF[2]:     004d3be2(j), 004d3bec(j)  
    //         004d3c03     MOV        EDX,dword ptr [ESI + 0x5b8]
    //         004d3c09     DEC        EDX
    //         004d3c0a     CMP        this,EDX
    //         004d3c0c     JLE        LAB_004d3c6b
    //         004d3c0e     LEA        EBX,[ECX + this+0x1]
    //         004d3c11     LEA        EAX,[EBX*0x4 + 0x0]
    //         004d3c18     PUSH       EAX
    //         004d3c19     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d3c1e     MOV        EDI,EAX
    //         004d3c20     ADD        ESP,0x4
    //         004d3c23     TEST       EDI,EDI
    //         004d3c25     JZ         LAB_004d3c6b
    //         004d3c27     MOV        this,dword ptr [ESI + 0x5b8]
    //         004d3c2d     XOR        EAX,EAX
    //         004d3c2f     TEST       this,this
    //         004d3c31     JLE        LAB_004d3c50
    //                               LAB_004d3c33                                                 XREF[1]:     004d3c4e(j)  
    //         004d3c33     CMP        EAX,EBX
    //         004d3c35     JGE        LAB_004d3c50
    //         004d3c37     MOV        this,dword ptr [ESI + 0x5ac]
    //         004d3c3d     INC        EAX
    //         004d3c3e     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004d3c42     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         004d3c46     MOV        this,dword ptr [ESI + 0x5b8]
    //         004d3c4c     CMP        EAX,this
    //         004d3c4e     JL         LAB_004d3c33
    //                               LAB_004d3c50                                                 XREF[2]:     004d3c31(j), 004d3c35(j)  
    //         004d3c50     MOV        EAX,dword ptr [ESI + 0x5ac]
    //         004d3c56     PUSH       EAX
    //         004d3c57     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d3c5c     ADD        ESP,0x4
    //         004d3c5f     MOV        dword ptr [ESI + 0x5ac],EDI
    //         004d3c65     MOV        dword ptr [ESI + 0x5b8],EBX
    //                               LAB_004d3c6b                                                 XREF[2]:     004d3c0c(j), 004d3c25(j)  
    //         004d3c6b     MOV        this,dword ptr [ESI + 0x5b0]
    //         004d3c71     MOV        EDX,dword ptr [ESI + 0x5ac]
    //         004d3c77     MOV        dword ptr [EDX + this->_padding_*0x4],0x67
    //         004d3c7e     MOV        EAX,dword ptr [ESI + 0x5b0]
    //         004d3c84     INC        EAX
    //         004d3c85     MOV        dword ptr [ESI + 0x5b0],EAX
    //                               LAB_004d3c8b                                                 XREF[1]:     004d3bf8(j)  
    //                              taibldmd.cpp:93 (179)
    //         004d3c8b     MOV        this,dword ptr [ESI + 0x5b0]
    //         004d3c91     XOR        EAX,EAX
    //         004d3c93     TEST       this,this
    //         004d3c95     JLE        LAB_004d3cb6
    //         004d3c97     MOV        EDX,dword ptr [ESI + 0x5b8]
    //                               LAB_004d3c9d                                                 XREF[1]:     004d3cb4(j)  
    //         004d3c9d     CMP        EAX,EDX
    //         004d3c9f     JGE        LAB_004d3cb6
    //         004d3ca1     MOV        EDI,dword ptr [ESI + 0x5ac]
    //         004d3ca7     CMP        dword ptr [EDI + EAX*0x4],0x44
    //         004d3cab     JZ         LAB_004d3d3e
    //         004d3cb1     INC        EAX
    //         004d3cb2     CMP        EAX,this
    //         004d3cb4     JL         LAB_004d3c9d
    //                               LAB_004d3cb6                                                 XREF[2]:     004d3c95(j), 004d3c9f(j)  
    //         004d3cb6     MOV        EAX,dword ptr [ESI + 0x5b8]
    //         004d3cbc     DEC        EAX
    //         004d3cbd     CMP        this,EAX
    //         004d3cbf     JLE        LAB_004d3d1e
    //         004d3cc1     LEA        EBX,[ECX + this+0x1]
    //         004d3cc4     LEA        this,[EBX*0x4 + 0x0]
    //         004d3ccb     PUSH       this
    //         004d3ccc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004d3cd1     MOV        EDI,EAX
    //         004d3cd3     ADD        ESP,0x4
    //         004d3cd6     TEST       EDI,EDI
    //         004d3cd8     JZ         LAB_004d3d1e
    //         004d3cda     MOV        this,dword ptr [ESI + 0x5b8]
    //         004d3ce0     XOR        EAX,EAX
    //         004d3ce2     TEST       this,this
    //         004d3ce4     JLE        LAB_004d3d03
    //                               LAB_004d3ce6                                                 XREF[1]:     004d3d01(j)  
    //         004d3ce6     CMP        EAX,EBX
    //         004d3ce8     JGE        LAB_004d3d03
    //         004d3cea     MOV        EDX,dword ptr [ESI + 0x5ac]
    //         004d3cf0     INC        EAX
    //         004d3cf1     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004d3cf5     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         004d3cf9     MOV        this,dword ptr [ESI + 0x5b8]
    //         004d3cff     CMP        EAX,this
    //         004d3d01     JL         LAB_004d3ce6
    //                               LAB_004d3d03                                                 XREF[2]:     004d3ce4(j), 004d3ce8(j)  
    //         004d3d03     MOV        EDX,dword ptr [ESI + 0x5ac]
    //         004d3d09     PUSH       EDX
    //         004d3d0a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d3d0f     ADD        ESP,0x4
    //         004d3d12     MOV        dword ptr [ESI + 0x5ac],EDI
    //         004d3d18     MOV        dword ptr [ESI + 0x5b8],EBX
    //                               LAB_004d3d1e                                                 XREF[2]:     004d3cbf(j), 004d3cd8(j)  
    //         004d3d1e     MOV        EAX,dword ptr [ESI + 0x5b0]
    //         004d3d24     MOV        this,dword ptr [ESI + 0x5ac]
    //         004d3d2a     MOV        dword ptr [this->_padding_ + EAX*0x4],0x44
    //         004d3d31     MOV        EAX,dword ptr [ESI + 0x5b0]
    //         004d3d37     INC        EAX
    //         004d3d38     MOV        dword ptr [ESI + 0x5b0],EAX
    //                               LAB_004d3d3e                                                 XREF[1]:     004d3cab(j)  
    //                              taibldmd.cpp:94 (17)
    //         004d3d3e     MOV        EDX,dword ptr [ESP + param_2]
    //         004d3d42     MOV        EAX,dword ptr [ESP + param_1]
    //         004d3d46     PUSH       EDX
    //         004d3d47     PUSH       EAX
    //         004d3d48     MOV        this,ESI
    //         004d3d4a     CALL       BuildAIModule::loadBuildList                     int loadBuildList(BuildAIModule * this, char 
    //                              taibldmd.cpp:95 (6)
    //         004d3d4f     POP        EDI
    //         004d3d50     POP        ESI
    //         004d3d51     POP        EBX
    //         004d3d52     RET        0x8
}

// Offset: 0x004D3D60
void initialize(TribeBuildAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeBuildAIModule::initialize(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall initialize(TribeBuildAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d4309(W), 004d442b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d443b(R)  
    //              ResourceItem      Stack[-0x80]   resourceCount             XREF[3,8]:   004d3da4(W), 004d3e60(RW), 004d4134(R), 004d42f9(*), 
    //                                                                                     004d4304(*), 004d435c(*), 004d4380(*), 004d43b0(*), 
    //                                                                                     004d43cb(*), 004d43ef(*), 004d4427(*)  
    //              int               Stack[-0x84]:4 warshipCount              XREF[5]:     004d3da8(W), 004d3e9f(W), 004d3f81(R), 004d4018(R), 
    //                                                                                     004d40a3(R)  
    //              int               Stack[-0x88]:4 toolAgeIndex              XREF[4]:     004d3d9c(W), 004d3e21(RW), 004d3fc5(R), 004d3ffc(R)  
    //              int               Stack[-0x8c]:4 fishingBoatCount          XREF[4]:     004d3da0(W), 004d3e69(RW), 004d405c(R), 004d409b(R)  
    //              int               Stack[-0x90]:4 transportCount            XREF[4]:     004d3d98(W), 004d3e02(RW), 004d3f34(R), 004d3f6b(R)  
    //              int               Stack[-0x94]:4 dockCount                 XREF[5]:     004d3dbc(W), 004d3f07(W), 004d4100(R), 004d42d7(W), 
    //                                                                                     004d43d6(R)  
    //              int               Stack[-0x98]:4 totalPercentage           XREF[5]:     004d3db0(W), 004d3ecb(W), 004d4108(R), 004d415f(R), 
    //                                                                                     004d41b0(R)  
    //              int               Stack[-0x9c]:4 ironAgeIndex              XREF[6]:     004d3db4(W), 004d3edb(W), 004d41b8(R), 004d42e7(W), 
    //                                                                                     004d43f8(R), 004d4415(R)  
    //              int               Stack[-0xa0]:4 divisionSize              XREF[6]:     004d3db8(W), 004d3ef1(W), 004d41d2(R), 004d43a5(W), 
    //                                                                                     004d4402(W), 004d4411(R)  
    //              int               Stack[-0xa4]:4 count                     XREF[7]:     004d3dac(W), 004d3f1a(W), 004d4008(R), 004d40ba(R), 
    //                                                                                     004d40c2(R), 004d4163(R), 004d41b4(R)  
    //              int               Stack[-0xa8]:4 bronzeAgeIndex            XREF[10]:    004d3d86(W), 004d3de9(RW), 004d41ec(R), 004d4229(W), 
    //                                                                                     004d4259(RW), 004d425d(R), 004d4323(W), 004d43c7(R), 
    //                                                                                     004d43fc(R), 004d440a(W)  
    //              int               Stack[-0xac]:4 requiredPop
    //                               ?initialize@TribeBuildAIModule@@QAEXXZ                       XREF[1]:     update:004e511f(c)  
    //                               TribeBuildAIModule::initialize
    //                              taibldmd.cpp:100 (33)
    //         004d3d60     PUSH       -0x1
    //         004d3d62     PUSH       FUN_00560278
    //         004d3d67     MOV        EAX,FS:[0x0]
    //         004d3d6d     PUSH       EAX
    //         004d3d6e     MOV        dword ptr FS:[0x0],ESP
    //         004d3d75     SUB        ESP,0x9c
    //         004d3d7b     PUSH       EBX
    //         004d3d7c     PUSH       EBP
    //         004d3d7d     PUSH       ESI
    //         004d3d7e     PUSH       EDI
    //         004d3d7f     MOV        EDI,this
    //                              taibldmd.cpp:102 (2)
    //         004d3d81     XOR        EAX,EAX
    //                              taibldmd.cpp:107 (7)
    //         004d3d83     OR         EBP,0xffffffff
    //         004d3d86     MOV        dword ptr [ESP + bronzeAgeIndex],EAX
    //                              taibldmd.cpp:113 (6)
    //         004d3d8a     MOV        ESI,dword ptr [EDI + 0x15c]
    //                              taibldmd.cpp:114 (66)
    //         004d3d90     LEA        EBX,[EDI + 0xf0]
    //         004d3d96     CMP        ESI,EBX
    //         004d3d98     MOV        dword ptr [ESP + transportCount],EAX
    //         004d3d9c     MOV        dword ptr [ESP + toolAgeIndex],EAX
    //         004d3da0     MOV        dword ptr [ESP + fishingBoatCount],EAX
    //         004d3da4     MOV        dword ptr [ESP + resourceCount._padding_],EAX
    //         004d3da8     MOV        dword ptr [ESP + warshipCount],EBP
    //         004d3dac     MOV        dword ptr [ESP + count],EBP
    //         004d3db0     MOV        dword ptr [ESP + totalPercentage],EBP
    //         004d3db4     MOV        dword ptr [ESP + ironAgeIndex],EAX
    //         004d3db8     MOV        dword ptr [ESP + divisionSize],EAX
    //         004d3dbc     MOV        dword ptr [ESP + dockCount],EAX
    //         004d3dc0     JZ         LAB_004d3f1e
    //         004d3dc6     JMP        LAB_004d3dca
    //                               LAB_004d3dc8                                                 XREF[1]:     004d3f14(j)  
    //         004d3dc8     XOR        EAX,EAX
    //                               LAB_004d3dca                                                 XREF[1]:     004d3dc6(j)  
    //         004d3dca     CMP        ESI,EAX
    //         004d3dcc     JZ         LAB_004d3f1a
    //                              taibldmd.cpp:115 (9)
    //         004d3dd2     MOV        this,ESI
    //         004d3dd4     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d3dd9     TEST       EAX,EAX
    //                              taibldmd.cpp:116 (14)
    //         004d3ddb     MOV        this,ESI
    //         004d3ddd     JNZ        LAB_004d3e0b
    //         004d3ddf     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3de4     CMP        EAX,0x46
    //         004d3de7     JNZ        LAB_004d3df2
    //                              taibldmd.cpp:117 (4)
    //         004d3de9     INC        dword ptr [ESP + bronzeAgeIndex]
    //                              taibldmd.cpp:118 (21)
    //         004d3ded     JMP        LAB_004d3f0f
    //                               LAB_004d3df2                                                 XREF[1]:     004d3de7(j)  
    //         004d3df2     MOV        this,ESI
    //         004d3df4     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3df9     CMP        EAX,0x2d
    //         004d3dfc     JNZ        LAB_004d3f0f
    //                              taibldmd.cpp:119 (4)
    //         004d3e02     INC        dword ptr [ESP + transportCount]
    //                              taibldmd.cpp:121 (13)
    //         004d3e06     JMP        LAB_004d3f0f
    //                               LAB_004d3e0b                                                 XREF[1]:     004d3ddd(j)  
    //         004d3e0b     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d3e10     CMP        EAX,0x2
    //                              taibldmd.cpp:122 (14)
    //         004d3e13     MOV        this,ESI
    //         004d3e15     JNZ        LAB_004d3e72
    //         004d3e17     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3e1c     CMP        EAX,0xd
    //         004d3e1f     JNZ        LAB_004d3e2a
    //                              taibldmd.cpp:123 (4)
    //         004d3e21     INC        dword ptr [ESP + toolAgeIndex]
    //                              taibldmd.cpp:124 (29)
    //         004d3e25     JMP        LAB_004d3f0f
    //                               LAB_004d3e2a                                                 XREF[1]:     004d3e1f(j)  
    //         004d3e2a     MOV        this,ESI
    //         004d3e2c     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3e31     CMP        EAX,0x11
    //         004d3e34     JZ         LAB_004d3e69
    //         004d3e36     MOV        this,ESI
    //         004d3e38     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3e3d     CMP        EAX,0x12
    //         004d3e40     JZ         LAB_004d3e69
    //                              taibldmd.cpp:126 (30)
    //         004d3e42     MOV        this,ESI
    //         004d3e44     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3e49     CMP        EAX,0x13
    //         004d3e4c     JZ         LAB_004d3e60
    //         004d3e4e     MOV        this,ESI
    //         004d3e50     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3e55     CMP        EAX,0xfa
    //         004d3e5a     JNZ        LAB_004d3f0f
    //                               LAB_004d3e60                                                 XREF[1]:     004d3e4c(j)  
    //                              taibldmd.cpp:127 (9)
    //         004d3e60     INC        dword ptr [ESP + resourceCount._padding_]
    //         004d3e64     JMP        LAB_004d3f0f
    //                               LAB_004d3e69                                                 XREF[2]:     004d3e34(j), 004d3e40(j)  
    //                              taibldmd.cpp:125 (4)
    //         004d3e69     INC        dword ptr [ESP + fishingBoatCount]
    //                              taibldmd.cpp:129 (31)
    //         004d3e6d     JMP        LAB_004d3f0f
    //                               LAB_004d3e72                                                 XREF[1]:     004d3e15(j)  
    //         004d3e72     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d3e77     CMP        EAX,0x1
    //         004d3e7a     JZ         LAB_004d3e8c
    //         004d3e7c     MOV        this,ESI
    //         004d3e7e     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d3e83     CMP        EAX,0x4
    //         004d3e86     JNZ        LAB_004d3f0f
    //                               LAB_004d3e8c                                                 XREF[1]:     004d3e7a(j)  
    //                              taibldmd.cpp:130 (10)
    //         004d3e8c     MOV        this,ESI
    //         004d3e8e     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3e93     CMP        EAX,0x65
    //                              taibldmd.cpp:131 (13)
    //         004d3e96     MOV        this,ESI
    //         004d3e98     JNZ        LAB_004d3ea5
    //         004d3e9a     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d3e9f     MOV        dword ptr [ESP + warshipCount],EAX
    //                              taibldmd.cpp:132 (10)
    //         004d3ea3     JMP        LAB_004d3f0f
    //                               LAB_004d3ea5                                                 XREF[1]:     004d3e98(j)  
    //         004d3ea5     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3eaa     CMP        EAX,0x66
    //                              taibldmd.cpp:133 (11)
    //         004d3ead     MOV        this,ESI
    //         004d3eaf     JNZ        LAB_004d3eba
    //         004d3eb1     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d3eb6     MOV        EBP,EAX
    //                              taibldmd.cpp:134 (10)
    //         004d3eb8     JMP        LAB_004d3f0f
    //                               LAB_004d3eba                                                 XREF[1]:     004d3eaf(j)  
    //         004d3eba     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3ebf     CMP        EAX,0x67
    //                              taibldmd.cpp:135 (13)
    //         004d3ec2     MOV        this,ESI
    //         004d3ec4     JNZ        LAB_004d3ed1
    //         004d3ec6     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d3ecb     MOV        dword ptr [ESP + totalPercentage],EAX
    //                              taibldmd.cpp:136 (12)
    //         004d3ecf     JMP        LAB_004d3f0f
    //                               LAB_004d3ed1                                                 XREF[1]:     004d3ec4(j)  
    //         004d3ed1     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3ed6     CMP        EAX,0x5
    //         004d3ed9     JNZ        LAB_004d3ee5
    //                              taibldmd.cpp:137 (8)
    //         004d3edb     MOV        dword ptr [ESP + ironAgeIndex],0x1
    //                              taibldmd.cpp:138 (14)
    //         004d3ee3     JMP        LAB_004d3f0f
    //                               LAB_004d3ee5                                                 XREF[1]:     004d3ed9(j)  
    //         004d3ee5     MOV        this,ESI
    //         004d3ee7     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3eec     CMP        EAX,0x7
    //         004d3eef     JNZ        LAB_004d3efb
    //                              taibldmd.cpp:139 (8)
    //         004d3ef1     MOV        dword ptr [ESP + divisionSize],0x1
    //                              taibldmd.cpp:140 (14)
    //         004d3ef9     JMP        LAB_004d3f0f
    //                               LAB_004d3efb                                                 XREF[1]:     004d3eef(j)  
    //         004d3efb     MOV        this,ESI
    //         004d3efd     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d3f02     CMP        EAX,0x8
    //         004d3f05     JNZ        LAB_004d3f0f
    //                              taibldmd.cpp:141 (8)
    //         004d3f07     MOV        dword ptr [ESP + dockCount],0x1
    //                               LAB_004d3f0f                                                 XREF[14]:    004d3ded(j), 004d3dfc(j), 
    //                                                                                                         004d3e06(j), 004d3e25(j), 
    //                                                                                                         004d3e5a(j), 004d3e64(j), 
    //                                                                                                         004d3e6d(j), 004d3e86(j), 
    //                                                                                                         004d3ea3(j), 004d3eb8(j), 
    //                                                                                                         004d3ecf(j), 004d3ee3(j), 
    //                                                                                                         004d3ef9(j), 004d3f05(j)  
    //                              taibldmd.cpp:144 (11)
    //         004d3f0f     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d3f12     CMP        ESI,EBX
    //         004d3f14     JNZ        LAB_004d3dc8
    //                               LAB_004d3f1a                                                 XREF[1]:     004d3dcc(j)  
    //                              taibldmd.cpp:133 (4)
    //         004d3f1a     MOV        dword ptr [ESP + count],EBP
    //                               LAB_004d3f1e                                                 XREF[1]:     004d3dc0(j)  
    //                              taibldmd.cpp:160 (55)
    //         004d3f1e     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d3f24     PUSH       0xd4
    //         004d3f29     ADD        this,0x1146c
    //         004d3f2f     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d3f34     CMP        dword ptr [ESP + transportCount],EAX
    //         004d3f38     JGE        LAB_004d3faf
    //         004d3f3a     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d3f40     PUSH       0xd0
    //         004d3f45     ADD        this,0x1146c
    //         004d3f4b     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d3f50     CMP        EAX,0x1
    //         004d3f53     JNZ        LAB_004d3faf
    //                              taibldmd.cpp:161 (30)
    //         004d3f55     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d3f5b     PUSH       0xd4
    //         004d3f60     ADD        this,0x1146c
    //         004d3f66     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d3f6b     MOV        EDX,dword ptr [ESP + transportCount]
    //         004d3f6f     MOV        this,EAX
    //         004d3f71     SUB        this,EDX
    //                              taibldmd.cpp:168 (5)
    //         004d3f73     CMP        EBP,-0x1
    //         004d3f76     JZ         LAB_004d3f81
    //                              taibldmd.cpp:169 (7)
    //         004d3f78     MOV        EAX,EBP
    //         004d3f7a     CDQ
    //         004d3f7b     IDIV       this
    //         004d3f7d     MOV        EBX,EAX
    //                              taibldmd.cpp:170 (11)
    //         004d3f7f     JMP        LAB_004d3f96
    //                               LAB_004d3f81                                                 XREF[1]:     004d3f76(j)  
    //         004d3f81     MOV        EAX,dword ptr [ESP + warshipCount]
    //         004d3f85     CMP        EAX,-0x1
    //         004d3f88     JZ         LAB_004d3f91
    //                              taibldmd.cpp:171 (5)
    //         004d3f8a     CDQ
    //         004d3f8b     IDIV       this
    //         004d3f8d     MOV        EBX,EAX
    //                              taibldmd.cpp:172 (2)
    //         004d3f8f     JMP        LAB_004d3f96
    //                               LAB_004d3f91                                                 XREF[1]:     004d3f88(j)  
    //                              taibldmd.cpp:173 (5)
    //         004d3f91     MOV        EBX,0xa
    //                               LAB_004d3f96                                                 XREF[2]:     004d3f7f(j), 004d3f8f(j)  
    //                              taibldmd.cpp:174 (8)
    //         004d3f96     TEST       this,this
    //         004d3f98     JLE        LAB_004d3faf
    //         004d3f9a     MOV        ESI,EBX
    //         004d3f9c     MOV        EBP,this
    //                               LAB_004d3f9e                                                 XREF[1]:     004d3fad(j)  
    //                              taibldmd.cpp:175 (17)
    //         004d3f9e     PUSH       ESI
    //         004d3f9f     PUSH       -0x1
    //         004d3fa1     PUSH       0x2d
    //         004d3fa3     MOV        this,EDI
    //         004d3fa5     CALL       TribeBuildAIModule::insert                       int insert(TribeBuildAIModule * this, int par
    //         004d3faa     ADD        ESI,EBX
    //         004d3fac     DEC        EBP
    //         004d3fad     JNZ        LAB_004d3f9e
    //                               LAB_004d3faf                                                 XREF[3]:     004d3f38(j), 004d3f53(j), 
    //                                                                                                         004d3f98(j)  
    //                              taibldmd.cpp:184 (55)
    //         004d3faf     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d3fb5     PUSH       0xd5
    //         004d3fba     ADD        this,0x1146c
    //         004d3fc0     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d3fc5     CMP        dword ptr [ESP + toolAgeIndex],EAX
    //         004d3fc9     JGE        LAB_004d4046
    //         004d3fcb     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d3fd1     PUSH       0xd1
    //         004d3fd6     ADD        this,0x1146c
    //         004d3fdc     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d3fe1     CMP        EAX,0x1
    //         004d3fe4     JNZ        LAB_004d4046
    //                              taibldmd.cpp:185 (30)
    //         004d3fe6     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d3fec     PUSH       0xd5
    //         004d3ff1     ADD        this,0x1146c
    //         004d3ff7     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d3ffc     MOV        EDX,dword ptr [ESP + toolAgeIndex]
    //         004d4000     MOV        this,EAX
    //         004d4002     SUB        this,EDX
    //                              taibldmd.cpp:191 (4)
    //         004d4004     TEST       this,this
    //         004d4006     JLE        LAB_004d4046
    //                              taibldmd.cpp:193 (9)
    //         004d4008     MOV        EAX,dword ptr [ESP + count]
    //         004d400c     CMP        EAX,-0x1
    //         004d400f     JZ         LAB_004d4018
    //                              taibldmd.cpp:194 (5)
    //         004d4011     CDQ
    //         004d4012     IDIV       this
    //         004d4014     MOV        EBX,EAX
    //                              taibldmd.cpp:195 (11)
    //         004d4016     JMP        LAB_004d402d
    //                               LAB_004d4018                                                 XREF[1]:     004d400f(j)  
    //         004d4018     MOV        EAX,dword ptr [ESP + warshipCount]
    //         004d401c     CMP        EAX,-0x1
    //         004d401f     JZ         LAB_004d4028
    //                              taibldmd.cpp:196 (5)
    //         004d4021     CDQ
    //         004d4022     IDIV       this
    //         004d4024     MOV        EBX,EAX
    //                              taibldmd.cpp:197 (2)
    //         004d4026     JMP        LAB_004d402d
    //                               LAB_004d4028                                                 XREF[1]:     004d401f(j)  
    //                              taibldmd.cpp:198 (5)
    //         004d4028     MOV        EBX,0xa
    //                               LAB_004d402d                                                 XREF[2]:     004d4016(j), 004d4026(j)  
    //                              taibldmd.cpp:199 (8)
    //         004d402d     TEST       this,this
    //         004d402f     JLE        LAB_004d4046
    //         004d4031     MOV        ESI,EBX
    //         004d4033     MOV        EBP,this
    //                               LAB_004d4035                                                 XREF[1]:     004d4044(j)  
    //                              taibldmd.cpp:200 (17)
    //         004d4035     PUSH       ESI
    //         004d4036     PUSH       -0x1
    //         004d4038     PUSH       0xd
    //         004d403a     MOV        this,EDI
    //         004d403c     CALL       TribeBuildAIModule::insert                       int insert(TribeBuildAIModule * this, int par
    //         004d4041     ADD        ESI,EBX
    //         004d4043     DEC        EBP
    //         004d4044     JNZ        LAB_004d4035
    //                               LAB_004d4046                                                 XREF[4]:     004d3fc9(j), 004d3fe4(j), 
    //                                                                                                         004d4006(j), 004d402f(j)  
    //                              taibldmd.cpp:210 (63)
    //         004d4046     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d404c     PUSH       0xd6
    //         004d4051     ADD        this,0x1146c
    //         004d4057     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d405c     CMP        dword ptr [ESP + fishingBoatCount],EAX
    //         004d4060     JGE        LAB_004d411e
    //         004d4066     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d406c     PUSH       0xd2
    //         004d4071     ADD        this,0x1146c
    //         004d4077     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d407c     CMP        EAX,0x1
    //         004d407f     JNZ        LAB_004d411e
    //                              taibldmd.cpp:211 (30)
    //         004d4085     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d408b     PUSH       0xd6
    //         004d4090     ADD        this,0x1146c
    //         004d4096     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d409b     MOV        EDX,dword ptr [ESP + fishingBoatCount]
    //         004d409f     MOV        this,EAX
    //         004d40a1     SUB        this,EDX
    //                              taibldmd.cpp:218 (9)
    //         004d40a3     MOV        EDX,dword ptr [ESP + warshipCount]
    //         004d40a7     CMP        EDX,-0x1
    //         004d40aa     JZ         LAB_004d40c2
    //                              taibldmd.cpp:219 (14)
    //         004d40ac     MOV        EAX,dword ptr [EDI + 0x1a0]
    //         004d40b2     LEA        ESI,[ECX + ECX*0x1]
    //         004d40b5     SUB        EAX,EDX
    //         004d40b7     CDQ
    //         004d40b8     IDIV       ESI
    //                              taibldmd.cpp:220 (6)
    //         004d40ba     MOV        ESI,dword ptr [ESP + count]
    //         004d40be     MOV        EBX,EAX
    //                              taibldmd.cpp:222 (11)
    //         004d40c0     JMP        LAB_004d40e7
    //                               LAB_004d40c2                                                 XREF[1]:     004d40aa(j)  
    //         004d40c2     MOV        EDX,dword ptr [ESP + count]
    //         004d40c6     CMP        EDX,-0x1
    //         004d40c9     JZ         LAB_004d40e0
    //                              taibldmd.cpp:223 (14)
    //         004d40cb     MOV        EAX,dword ptr [EDI + 0x1a0]
    //         004d40d1     LEA        ESI,[ECX + ECX*0x1]
    //         004d40d4     SUB        EAX,EDX
    //         004d40d6     CDQ
    //         004d40d7     IDIV       ESI
    //                              taibldmd.cpp:224 (5)
    //         004d40d9     OR         ESI,0xffffffff
    //         004d40dc     MOV        EBX,EAX
    //                              taibldmd.cpp:226 (2)
    //         004d40de     JMP        LAB_004d40e7
    //                               LAB_004d40e0                                                 XREF[1]:     004d40c9(j)  
    //                              taibldmd.cpp:227 (5)
    //         004d40e0     MOV        EBX,0xa
    //                              taibldmd.cpp:228 (2)
    //         004d40e5     XOR        ESI,ESI
    //                               LAB_004d40e7                                                 XREF[2]:     004d40c0(j), 004d40de(j)  
    //                              taibldmd.cpp:230 (8)
    //         004d40e7     TEST       this,this
    //         004d40e9     JLE        LAB_004d4100
    //         004d40eb     ADD        ESI,EBX
    //         004d40ed     MOV        EBP,this
    //                               LAB_004d40ef                                                 XREF[1]:     004d40fe(j)  
    //                              taibldmd.cpp:231 (17)
    //         004d40ef     PUSH       ESI
    //         004d40f0     PUSH       -0x1
    //         004d40f2     PUSH       0x11
    //         004d40f4     MOV        this,EDI
    //         004d40f6     CALL       TribeBuildAIModule::insert                       int insert(TribeBuildAIModule * this, int par
    //         004d40fb     ADD        ESI,EBX
    //         004d40fd     DEC        EBP
    //         004d40fe     JNZ        LAB_004d40ef
    //                               LAB_004d4100                                                 XREF[1]:     004d40e9(j)  
    //                              taibldmd.cpp:236 (17)
    //         004d4100     MOV        EAX,dword ptr [ESP + dockCount]
    //         004d4104     TEST       EAX,EAX
    //         004d4106     JNZ        LAB_004d411e
    //         004d4108     MOV        EAX,dword ptr [ESP + totalPercentage]
    //         004d410c     CMP        EAX,-0x1
    //         004d410f     JZ         LAB_004d411e
    //                              taibldmd.cpp:237 (13)
    //         004d4111     ADD        EAX,0x2
    //         004d4114     MOV        this,EDI
    //         004d4116     PUSH       EAX
    //         004d4117     PUSH       0x8
    //         004d4119     CALL       TribeBuildAIModule::insertResearch               int insertResearch(TribeBuildAIModule * this,
    //                               LAB_004d411e                                                 XREF[4]:     004d4060(j), 004d407f(j), 
    //                                                                                                         004d4106(j), 004d410f(j)  
    //                              taibldmd.cpp:247 (83)
    //         004d411e     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4124     PUSH       0xe0
    //         004d4129     ADD        this,0x1146c
    //         004d412f     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4134     MOV        EBX,dword ptr [ESP + resourceCount._padding_]
    //         004d4138     CMP        EBX,EAX
    //         004d413a     JGE        LAB_004d41ec
    //         004d4140     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4146     PUSH       0xdf
    //         004d414b     ADD        this,0x1146c
    //         004d4151     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4156     CMP        EAX,0x1
    //         004d4159     JNZ        LAB_004d41ec
    //         004d415f     MOV        ESI,dword ptr [ESP + totalPercentage]
    //         004d4163     MOV        EBP,dword ptr [ESP + count]
    //         004d4167     CMP        ESI,-0x1
    //         004d416a     JNZ        LAB_004d4171
    //         004d416c     CMP        EBP,-0x1
    //         004d416f     JZ         LAB_004d41ec
    //                               LAB_004d4171                                                 XREF[1]:     004d416a(j)  
    //                              taibldmd.cpp:248 (24)
    //         004d4171     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4177     PUSH       0xe0
    //         004d417c     ADD        this,0x1146c
    //         004d4182     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4187     MOV        this,EAX
    //                              taibldmd.cpp:255 (9)
    //         004d4189     MOV        EAX,ESI
    //         004d418b     SUB        this,EBX
    //         004d418d     CMP        ESI,-0x1
    //         004d4190     JNZ        LAB_004d4194
    //                              taibldmd.cpp:257 (5)
    //         004d4192     MOV        EAX,EBP
    //                               LAB_004d4194                                                 XREF[1]:     004d4190(j)  
    //         004d4194     CDQ
    //         004d4195     IDIV       this
    //                              taibldmd.cpp:258 (10)
    //         004d4197     TEST       this,this
    //         004d4199     MOV        EBX,EAX
    //         004d419b     JLE        LAB_004d41b8
    //         004d419d     MOV        ESI,EBX
    //         004d419f     MOV        EBP,this
    //                               LAB_004d41a1                                                 XREF[1]:     004d41ae(j)  
    //                              taibldmd.cpp:259 (23)
    //         004d41a1     PUSH       ESI
    //         004d41a2     PUSH       0x13
    //         004d41a4     MOV        this,EDI
    //         004d41a6     CALL       TribeBuildAIModule::insertResearch               int insertResearch(TribeBuildAIModule * this,
    //         004d41ab     ADD        ESI,EBX
    //         004d41ad     DEC        EBP
    //         004d41ae     JNZ        LAB_004d41a1
    //         004d41b0     MOV        ESI,dword ptr [ESP + totalPercentage]
    //         004d41b4     MOV        EBP,dword ptr [ESP + count]
    //                               LAB_004d41b8                                                 XREF[1]:     004d419b(j)  
    //                              taibldmd.cpp:265 (13)
    //         004d41b8     MOV        EAX,dword ptr [ESP + ironAgeIndex]
    //         004d41bc     TEST       EAX,EAX
    //         004d41be     JNZ        LAB_004d41d2
    //         004d41c0     CMP        EBP,-0x1
    //         004d41c3     JZ         LAB_004d41d2
    //                              taibldmd.cpp:266 (13)
    //         004d41c5     ADD        EBP,0x5
    //         004d41c8     MOV        this,EDI
    //         004d41ca     PUSH       EBP
    //         004d41cb     PUSH       0x5
    //         004d41cd     CALL       TribeBuildAIModule::insertResearch               int insertResearch(TribeBuildAIModule * this,
    //                               LAB_004d41d2                                                 XREF[2]:     004d41be(j), 004d41c3(j)  
    //                              taibldmd.cpp:271 (13)
    //         004d41d2     MOV        EAX,dword ptr [ESP + divisionSize]
    //         004d41d6     TEST       EAX,EAX
    //         004d41d8     JNZ        LAB_004d41ec
    //         004d41da     CMP        ESI,-0x1
    //         004d41dd     JZ         LAB_004d41ec
    //                              taibldmd.cpp:272 (13)
    //         004d41df     ADD        ESI,0x5
    //         004d41e2     MOV        this,EDI
    //         004d41e4     PUSH       ESI
    //         004d41e5     PUSH       0x7
    //         004d41e7     CALL       TribeBuildAIModule::insertResearch               int insertResearch(TribeBuildAIModule * this,
    //                               LAB_004d41ec                                                 XREF[5]:     004d413a(j), 004d4159(j), 
    //                                                                                                         004d416f(j), 004d41d8(j), 
    //                                                                                                         004d41dd(j)  
    //                              taibldmd.cpp:281 (43)
    //         004d41ec     MOV        EAX,dword ptr [ESP + bronzeAgeIndex]
    //         004d41f0     TEST       EAX,EAX
    //         004d41f2     JNZ        LAB_004d42ae
    //         004d41f8     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d41fe     PUSH       0xb4
    //         004d4203     ADD        this,0x1146c
    //         004d4209     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d420e     CMP        EAX,0x1
    //         004d4211     JNZ        LAB_004d42ae
    //                              taibldmd.cpp:292 (6)
    //         004d4217     MOV        ESI,dword ptr [EDI + 0x15c]
    //                              taibldmd.cpp:293 (22)
    //         004d421d     LEA        EAX,[EDI + 0xf0]
    //         004d4223     XOR        EBP,EBP
    //         004d4225     XOR        EBX,EBX
    //         004d4227     CMP        ESI,EAX
    //         004d4229     MOV        dword ptr [ESP + bronzeAgeIndex],EBP
    //         004d422d     JZ         LAB_004d42ae
    //                               LAB_004d422f                                                 XREF[1]:     004d42ac(j)  
    //         004d422f     TEST       ESI,ESI
    //         004d4231     JZ         LAB_004d42ae
    //                              taibldmd.cpp:300 (23)
    //         004d4233     MOV        this,ESI
    //         004d4235     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d423a     TEST       EAX,EAX
    //         004d423c     JNZ        LAB_004d424d
    //         004d423e     MOV        this,ESI
    //         004d4240     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4245     CMP        EAX,0x6d
    //         004d4248     JNZ        LAB_004d424d
    //                              taibldmd.cpp:304 (3)
    //         004d424a     ADD        EBX,0x4
    //                               LAB_004d424d                                                 XREF[2]:     004d423c(j), 004d4248(j)  
    //                              taibldmd.cpp:307 (12)
    //         004d424d     MOV        this,ESI
    //         004d424f     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4254     CMP        EAX,0x2
    //         004d4257     JNZ        LAB_004d425d
    //                              taibldmd.cpp:311 (4)
    //         004d4259     INC        dword ptr [ESP + bronzeAgeIndex]
    //                               LAB_004d425d                                                 XREF[1]:     004d4257(j)  
    //                              taibldmd.cpp:316 (6)
    //         004d425d     CMP        dword ptr [ESP + bronzeAgeIndex],EBX
    //         004d4261     JLE        LAB_004d4283
    //                              taibldmd.cpp:322 (5)
    //         004d4263     CMP        EBP,0x1
    //         004d4266     JLE        LAB_004d426e
    //                              taibldmd.cpp:323 (4)
    //         004d4268     LEA        EAX,[EBP + -0x1]
    //         004d426b     PUSH       EAX
    //                              taibldmd.cpp:324 (2)
    //         004d426c     JMP        LAB_004d4270
    //                               LAB_004d426e                                                 XREF[1]:     004d4266(j)  
    //                              taibldmd.cpp:325 (13)
    //         004d426e     PUSH       0x1
    //                               LAB_004d4270                                                 XREF[1]:     004d426c(j)  
    //         004d4270     PUSH       -0x1
    //         004d4272     PUSH       0x46
    //         004d4274     MOV        this,EDI
    //         004d4276     CALL       TribeBuildAIModule::insert                       int insert(TribeBuildAIModule * this, int par
    //                              taibldmd.cpp:327 (5)
    //         004d427b     CMP        EAX,0x1
    //         004d427e     JNZ        LAB_004d4283
    //                              taibldmd.cpp:331 (3)
    //         004d4280     ADD        EBX,0x4
    //                               LAB_004d4283                                                 XREF[2]:     004d4261(j), 004d427e(j)  
    //                              taibldmd.cpp:340 (29)
    //         004d4283     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4289     PUSH       0x98
    //         004d428e     ADD        this,0x1146c
    //         004d4294     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4299     ADD        EAX,0x32
    //         004d429c     CMP        EBX,EAX
    //         004d429e     JG         LAB_004d42ae
    //                              taibldmd.cpp:348 (9)
    //         004d42a0     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d42a3     LEA        EAX,[EDI + 0xf0]
    //                              taibldmd.cpp:349 (5)
    //         004d42a9     INC        EBP
    //         004d42aa     CMP        ESI,EAX
    //         004d42ac     JNZ        LAB_004d422f
    //                               LAB_004d42ae                                                 XREF[5]:     004d41f2(j), 004d4211(j), 
    //                                                                                                         004d422d(j), 004d4231(j), 
    //                                                                                                         004d429e(j)  
    //                              taibldmd.cpp:356 (22)
    //         004d42ae     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d42b4     PUSH       0xa0
    //         004d42b9     ADD        this,0x1146c
    //         004d42bf     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //                              taibldmd.cpp:358 (33)
    //         004d42c4     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d42ca     MOV        ESI,EAX
    //         004d42cc     PUSH       0x9b
    //         004d42d1     ADD        this,0x1146c
    //         004d42d7     MOV        dword ptr [ESP + dockCount],ESI
    //         004d42db     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d42e0     MOV        EBX,EAX
    //         004d42e2     ADD        EBX,0x4
    //                              taibldmd.cpp:365 (12)
    //         004d42e5     TEST       ESI,ESI
    //         004d42e7     MOV        dword ptr [ESP + ironAgeIndex],EBX
    //         004d42eb     JZ         LAB_004d443b
    //                              taibldmd.cpp:372 (6)
    //         004d42f1     MOV        EBP,dword ptr [EDI + 0x15c]
    //                              taibldmd.cpp:374 (13)
    //         004d42f7     PUSH       0x4
    //         004d42f9     LEA        this=>resourceCount.next,[ESP + 0x40]
    //         004d42fd     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
    //         004d4302     XOR        ESI,ESI
    //                              taibldmd.cpp:375 (17)
    //         004d4304     LEA        this=>resourceCount.next,[ESP + 0x3c]
    //         004d4308     PUSH       ESI
    //         004d4309     MOV        dword ptr [ESP + local_4],ESI
    //         004d4310     CALL       ResourceItem::setAllValues                       void setAllValues(ResourceItem * this, int pa
    //                              taibldmd.cpp:378 (14)
    //         004d4315     LEA        EAX,[EDI + 0xf0]
    //         004d431b     CMP        EBP,EAX
    //         004d431d     JZ         LAB_004d4427
    //                              taibldmd.cpp:434 (4)
    //         004d4323     MOV        dword ptr [ESP + bronzeAgeIndex],ESI
    //                               LAB_004d4327                                                 XREF[1]:     004d4421(j)  
    //                              taibldmd.cpp:378 (8)
    //         004d4327     TEST       EBP,EBP
    //         004d4329     JZ         LAB_004d4427
    //                              taibldmd.cpp:380 (12)
    //         004d432f     MOV        this,EBP
    //         004d4331     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4336     CMP        EAX,0x6
    //         004d4339     JNZ        LAB_004d4344
    //                              taibldmd.cpp:382 (4)
    //         004d433b     MOV        EBP,dword ptr [EBP + 0x6c]
    //         004d433e     INC        ESI
    //                              taibldmd.cpp:383 (5)
    //         004d433f     JMP        LAB_004d4419
    //                               LAB_004d4344                                                 XREF[1]:     004d4339(j)  
    //                              taibldmd.cpp:388 (24)
    //         004d4344     MOV        this,EBP
    //         004d4346     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d434b     CMP        EAX,0x1
    //         004d434e     JZ         LAB_004d4380
    //         004d4350     MOV        this,EBP
    //         004d4352     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4357     CMP        EAX,0x4
    //         004d435a     JZ         LAB_004d4380
    //                              taibldmd.cpp:391 (36)
    //         004d435c     LEA        this=>resourceCount.next,[ESP + 0x3c]
    //         004d4360     PUSH       0x1
    //         004d4362     PUSH       this
    //         004d4363     PUSH       -0x1
    //         004d4365     MOV        this,EBP
    //         004d4367     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d436c     MOV        EDX,dword ptr [EDI + 0x5bc]
    //         004d4372     PUSH       EAX
    //         004d4373     MOV        this,dword ptr [EDX + 0x1256c]
    //         004d4379     CALL       TRIBE_Player::objectCost                         void objectCost(TRIBE_Player * this, int para
    //         004d437e     JMP        LAB_004d43a2
    //                               LAB_004d4380                                                 XREF[2]:     004d434e(j), 004d435a(j)  
    //                              taibldmd.cpp:389 (34)
    //         004d4380     LEA        EAX=>resourceCount.next,[ESP + 0x3c]
    //         004d4384     PUSH       0x1
    //         004d4386     PUSH       EAX
    //         004d4387     PUSH       -0x1
    //         004d4389     MOV        this,EBP
    //         004d438b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4390     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4396     PUSH       EAX
    //         004d4397     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d439d     CALL       TRIBE_Player::researchCost                       void researchCost(TRIBE_Player * this, int pa
    //                               LAB_004d43a2                                                 XREF[1]:     004d437e(j)  
    //                              taibldmd.cpp:392 (1)
    //         004d43a2     INC        ESI
    //                              taibldmd.cpp:400 (8)
    //         004d43a3     CMP        ESI,EBX
    //         004d43a5     MOV        dword ptr [ESP + divisionSize],ESI
    //         004d43a9     JL         LAB_004d440e
    //                              taibldmd.cpp:405 (2)
    //         004d43ab     XOR        EBX,EBX
    //                              taibldmd.cpp:406 (2)
    //         004d43ad     XOR        ESI,ESI
    //                               LAB_004d43af                                                 XREF[1]:     004d43bf(j)  
    //                              taibldmd.cpp:407 (18)
    //         004d43af     PUSH       ESI
    //         004d43b0     LEA        this=>resourceCount.next,[ESP + 0x40]
    //         004d43b4     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         004d43b9     ADD        EBX,EAX
    //         004d43bb     INC        ESI
    //         004d43bc     CMP        ESI,0x4
    //         004d43bf     JL         LAB_004d43af
    //                              taibldmd.cpp:411 (4)
    //         004d43c1     TEST       EBX,EBX
    //         004d43c3     JLE        LAB_004d440e
    //                              taibldmd.cpp:412 (2)
    //         004d43c5     XOR        ESI,ESI
    //                               LAB_004d43c7                                                 XREF[1]:     004d43eb(j)  
    //                              taibldmd.cpp:419 (38)
    //         004d43c7     MOV        EDX,dword ptr [ESP + bronzeAgeIndex]
    //         004d43cb     LEA        this=>resourceCount.next,[ESP + 0x3c]
    //         004d43cf     PUSH       EDX
    //         004d43d0     PUSH       ESI
    //         004d43d1     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         004d43d6     IMUL       EAX,dword ptr [ESP + dockCount]
    //         004d43db     CDQ
    //         004d43dc     IDIV       EBX
    //         004d43de     MOV        this,EDI
    //         004d43e0     PUSH       EAX
    //         004d43e1     PUSH       ESI
    //         004d43e2     CALL       TribeBuildAIModule::insertGathererPercentage     int insertGathererPercentage(TribeBuildAIModu
    //         004d43e7     INC        ESI
    //         004d43e8     CMP        ESI,0x4
    //         004d43eb     JL         LAB_004d43c7
    //                              taibldmd.cpp:423 (11)
    //         004d43ed     PUSH       0x0
    //         004d43ef     LEA        this=>resourceCount.next,[ESP + 0x40]
    //         004d43f3     CALL       ResourceItem::setAllValues                       void setAllValues(ResourceItem * this, int pa
    //                              taibldmd.cpp:425 (22)
    //         004d43f8     MOV        EAX,dword ptr [ESP + ironAgeIndex]
    //         004d43fc     MOV        this,dword ptr [ESP + bronzeAgeIndex]
    //         004d4400     ADD        this,EAX
    //         004d4402     MOV        dword ptr [ESP + divisionSize],0x0
    //         004d440a     MOV        dword ptr [ESP + bronzeAgeIndex],this
    //                               LAB_004d440e                                                 XREF[2]:     004d43a9(j), 004d43c3(j)  
    //                              taibldmd.cpp:428 (29)
    //         004d440e     MOV        EBP,dword ptr [EBP + 0x6c]
    //         004d4411     MOV        ESI,dword ptr [ESP + divisionSize]
    //         004d4415     MOV        EBX,dword ptr [ESP + ironAgeIndex]
    //                               LAB_004d4419                                                 XREF[1]:     004d433f(j)  
    //         004d4419     LEA        EAX,[EDI + 0xf0]
    //         004d441f     CMP        EBP,EAX
    //         004d4421     JNZ        LAB_004d4327
    //                               LAB_004d4427                                                 XREF[2]:     004d431d(j), 004d4329(j)  
    //         004d4427     LEA        this=>resourceCount.next,[ESP + 0x3c]
    //                              taibldmd.cpp:434 (41)
    //         004d442b     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004d4436     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //                               LAB_004d443b                                                 XREF[1]:     004d42eb(j)  
    //         004d443b     MOV        this,dword ptr [ESP + local_c]
    //         004d4442     POP        EDI
    //         004d4443     POP        ESI
    //         004d4444     POP        EBP
    //         004d4445     MOV        dword ptr FS:[0x0],this
    //         004d444c     POP        EBX
    //         004d444d     ADD        ESP,0xa8
    //         004d4453     RET
}

// Offset: 0x004D4460
void skipNextBuildListItem(TribeBuildAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeBuildAIModule::skipNextBuildListItem(void)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall skipNextBuildListItem(TribeBuildAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //                               ?skipNextBuildListItem@TribeBuildAIModule@@QAEXXZ            XREF[1]:     kick:004e5f52(c)  
    //                               TribeBuildAIModule::skipNextBuildListItem
    //                              taibldmd.cpp:439 (6)
    //         004d4460     PUSH       EBX
    //         004d4461     PUSH       EBP
    //         004d4462     PUSH       ESI
    //         004d4463     PUSH       EDI
    //         004d4464     MOV        EDI,this
    //                              taibldmd.cpp:440 (6)
    //         004d4466     MOV        ESI,dword ptr [EDI + 0x15c]
    //                              taibldmd.cpp:441 (22)
    //         004d446c     LEA        EBX,[EDI + 0xf0]
    //         004d4472     CMP        ESI,EBX
    //         004d4474     JZ         LAB_004d4535
    //                               LAB_004d447a                                                 XREF[1]:     004d44d7(j)  
    //         004d447a     TEST       ESI,ESI
    //         004d447c     JZ         LAB_004d4535
    //                              taibldmd.cpp:449 (80)
    //         004d4482     MOV        this,ESI
    //         004d4484     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d4489     TEST       EAX,EAX
    //         004d448b     JNZ        LAB_004d44d2
    //         004d448d     MOV        this,ESI
    //         004d448f     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d4494     TEST       EAX,EAX
    //         004d4496     JNZ        LAB_004d44d2
    //         004d4498     MOV        this,ESI
    //         004d449a     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //         004d449f     CMP        EAX,0x1
    //         004d44a2     JZ         LAB_004d44d2
    //         004d44a4     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d44aa     PUSH       0xb1
    //         004d44af     ADD        this,0x1146c
    //         004d44b5     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d44ba     MOV        this,ESI
    //         004d44bc     MOV        EBP,EAX
    //         004d44be     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d44c3     CMP        EAX,EBP
    //         004d44c5     JNZ        LAB_004d44de
    //         004d44c7     MOV        this,ESI
    //         004d44c9     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d44ce     TEST       EAX,EAX
    //         004d44d0     JNZ        LAB_004d44de
    //                               LAB_004d44d2                                                 XREF[3]:     004d448b(j), 004d4496(j), 
    //                                                                                                         004d44a2(j)  
    //                              taibldmd.cpp:457 (7)
    //         004d44d2     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d44d5     CMP        ESI,EBX
    //         004d44d7     JNZ        LAB_004d447a
    //                              taibldmd.cpp:459 (5)
    //         004d44d9     POP        EDI
    //         004d44da     POP        ESI
    //         004d44db     POP        EBP
    //         004d44dc     POP        EBX
    //         004d44dd     RET
    //                               LAB_004d44de                                                 XREF[2]:     004d44c5(j), 004d44d0(j)  
    //                              taibldmd.cpp:450 (27)
    //         004d44de     MOV        this,dword ptr [EDI + 0x5bc]
    //                              language.dll match for 0x72: "21"
    //         004d44e4     PUSH       0x72
    //         004d44e6     ADD        this,0x1146c
    //         004d44ec     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d44f1     PUSH       EAX
    //         004d44f2     MOV        this,ESI
    //         004d44f4     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                              taibldmd.cpp:451 (9)
    //         004d44f9     PUSH       0x1
    //         004d44fb     MOV        this,ESI
    //         004d44fd     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
    //                              taibldmd.cpp:452 (7)
    //         004d4502     MOV        this,ESI
    //         004d4504     CALL       BuildItem::incrementSkipCycles                   void incrementSkipCycles(BuildItem * this)
    //                              taibldmd.cpp:453 (35)
    //         004d4509     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d450f     PUSH       0x92
    //         004d4514     ADD        this,0x1146c
    //         004d451a     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d451f     MOV        this,ESI
    //         004d4521     MOV        EDI,EAX
    //         004d4523     CALL       BuildItem::skipCycles                            int skipCycles(BuildItem * this)
    //         004d4528     CMP        EAX,EDI
    //         004d452a     JNZ        LAB_004d4535
    //                              taibldmd.cpp:454 (9)
    //         004d452c     PUSH       0x1
    //         004d452e     MOV        this,ESI
    //         004d4530     CALL       BuildItem::setPermanentSkip                      void setPermanentSkip(BuildItem * this, uchar
    //                               LAB_004d4535                                                 XREF[3]:     004d4474(j), 004d447c(j), 
    //                                                                                                         004d452a(j)  
    //                              taibldmd.cpp:459 (5)
    //         004d4535     POP        EDI
    //         004d4536     POP        ESI
    //         004d4537     POP        EBP
    //         004d4538     POP        EBX
    //         004d4539     RET
}

// Offset: 0x004D4540
BuildItem* nextBuildableItem(TribeBuildAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class BuildItem * __thiscall TribeBuildAIModule::nextBuildableItem(int)                       *
    //                              *********************************************************************************************************
    //                              BuildItem * __thiscall nextBuildableItem(TribeBuildAIModule * this, 
    //              BuildItem *       EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              ResourceItem      Stack[-0x80]   itemCost@ffffff80
    //              ResourceItem      Stack[-0xf0]   itemCost
    //              int               Stack[-0xf4]:4 numHouses
    //              int               Stack[-0xf8]:4 realCount
    //              int               Stack[-0xfc]:4 numStoragePits
    //              int               Stack[-0x100   numGranaries
    //              int               Stack[-0x104   count
    //                               ?nextBuildableItem@TribeBuildAIModule@@QAEPAVBuildItem@@H@Z  XREF[5]:     doSomething:004f0406(c), 
    //                               TribeBuildAIModule::nextBuildableItem                                     doSomething:004f0478(c), 
    //                                                                                                         doSomething:004f04cd(c), 
    //                                                                                                         doSomething:004f0849(c), 
    //                                                                                                         taskBuilder:004f9aef(c)  
    //                              taibldmd.cpp:464 (33)
    //         004d4540     PUSH       -0x1
    //         004d4542     PUSH       FUN_005602a3
    //         004d4547     MOV        EAX,FS:[0x0]
    //         004d454d     PUSH       EAX
    //         004d454e     MOV        dword ptr FS:[0x0],ESP
    //         004d4555     SUB        ESP,0xf4
    //         004d455b     PUSH       EBX
    //         004d455c     PUSH       EBP
    //         004d455d     PUSH       ESI
    //         004d455e     PUSH       EDI
    //         004d455f     MOV        EDI,this
    //                              taibldmd.cpp:477 (12)
    //         004d4561     XOR        EBX,EBX
    //         004d4563     PUSH       EBX
    //                              language.dll match for 0x67: "Comic Sans MS"
    //         004d4564     PUSH       0x67
    //         004d4566     MOV        EAX,dword ptr [EDI]
    //         004d4568     MOV        ESI,dword ptr [EAX + 0x48]
    //         004d456b     CALL       ESI
    //                              taibldmd.cpp:478 (11)
    //         004d456d     PUSH       EBX
    //         004d456e     PUSH       offset DAT_fffffff8
    //         004d4570     MOV        this,EDI
    //         004d4572     MOV        dword ptr [ESP + 0x20],EAX
    //         004d4576     CALL       ESI
    //                              taibldmd.cpp:479 (11)
    //         004d4578     PUSH       EBX
    //         004d4579     PUSH       offset DAT_fffffff8
    //         004d457b     MOV        this,EDI
    //         004d457d     MOV        dword ptr [ESP + 0x1c],EAX
    //         004d4581     CALL       ESI
    //                              taibldmd.cpp:485 (67)
    //         004d4583     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4589     MOV        ESI,dword ptr [EDI + 0x15c]
    //                              language.dll match for 0x73: "B"
    //         004d458f     PUSH       0x73
    //         004d4591     ADD        this,0x1146c
    //         004d4597     MOV        dword ptr [ESP + 0x24],EAX
    //         004d459b     MOV        dword ptr [ESP + 0x20],EBX
    //         004d459f     MOV        dword ptr [ESP + 0x14],EBX
    //         004d45a3     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d45a8     TEST       EAX,EAX
    //         004d45aa     JL         LAB_004d499b
    //                               LAB_004d45b0                                                 XREF[1]:     004d48b8(j)  
    //         004d45b0     LEA        EAX,[EDI + 0xf0]
    //         004d45b6     CMP        ESI,EAX
    //         004d45b8     JZ         LAB_004d499b
    //         004d45be     TEST       ESI,ESI
    //         004d45c0     JZ         LAB_004d499b
    //                              taibldmd.cpp:498 (44)
    //         004d45c6     MOV        this,ESI
    //         004d45c8     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d45cd     CMP        EAX,0x1
    //         004d45d0     JZ         LAB_004d45de
    //         004d45d2     MOV        this,ESI
    //         004d45d4     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d45d9     CMP        EAX,0x4
    //         004d45dc     JNZ        switchD_004d4615::default
    //                               LAB_004d45de                                                 XREF[1]:     004d45d0(j)  
    //         004d45de     MOV        this,ESI
    //         004d45e0     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d45e5     PUSH       EAX
    //         004d45e6     MOV        this,EDI
    //         004d45e8     CALL       TribeBuildAIModule::isAgeResearch                int isAgeResearch(TribeBuildAIModule * this, 
    //         004d45ed     CMP        EAX,0x1
    //         004d45f0     JNZ        switchD_004d4615::default
    //                              taibldmd.cpp:499 (30)
    //         004d45f2     MOV        this,ESI
    //         004d45f4     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d45f9     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d45ff     PUSH       EAX
    //         004d4600     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d4606     CALL       TRIBE_Player::researchState                      uchar researchState(TRIBE_Player * this, int 
    //         004d460b     AND        EAX,0xff
    //                              taibldmd.cpp:500 (12)
    //         004d4610     CMP        EAX,0x3
    //         004d4613     JA         switchD_004d4615::default
    //                               switchD_004d4615::switchD
    //         004d4615     JMP        dword ptr [EAX*0x4 + switchD_004d4615::switchd   = 004d461c
    //                               switchD_004d4615::caseD_1                                    XREF[3]:     004d4615(j), 004d4d98(*), 
    //                               switchD_004d4615::caseD_0                                                 004d4d9c(*)  
    //                              taibldmd.cpp:504 (2)
    //         004d461c     PUSH       0x0
    //                              taibldmd.cpp:506 (2)
    //         004d461e     JMP        LAB_004d462f
    //                               switchD_004d4615::caseD_2                                    XREF[2]:     004d4615(j), 004d4da0(*)  
    //                              taibldmd.cpp:509 (9)
    //         004d4620     PUSH       0x0
    //         004d4622     MOV        this,ESI
    //         004d4624     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:510 (2)
    //         004d4629     PUSH       0x1
    //                              taibldmd.cpp:511 (2)
    //         004d462b     JMP        LAB_004d4638
    //                               switchD_004d4615::caseD_3                                    XREF[2]:     004d4615(j), 004d4da4(*)  
    //                              taibldmd.cpp:514 (9)
    //         004d462d     PUSH       0x1
    //                               LAB_004d462f                                                 XREF[1]:     004d461e(j)  
    //         004d462f     MOV        this,ESI
    //         004d4631     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:515 (9)
    //         004d4636     PUSH       0x0
    //                               LAB_004d4638                                                 XREF[1]:     004d462b(j)  
    //         004d4638     MOV        this,ESI
    //         004d463a     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                               switchD_004d4615::default                                    XREF[3]:     004d45dc(j), 004d45f0(j), 
    //                                                                                                         004d4613(j)  
    //                              taibldmd.cpp:522 (30)
    //         004d463f     MOV        this,ESI
    //         004d4641     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d4646     TEST       EAX,EAX
    //         004d4648     JNZ        LAB_004d489e
    //         004d464e     MOV        this,ESI
    //         004d4650     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d4655     TEST       EAX,EAX
    //         004d4657     JNZ        LAB_004d489e
    //                              taibldmd.cpp:524 (4)
    //         004d465d     MOV        EBP,dword ptr [ESP + 0x1c]
    //                              taibldmd.cpp:536 (34)
    //         004d4661     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4667     INC        EBP
    //         004d4668     PUSH       0xa1
    //         004d466d     MOV        dword ptr [ESP + 0x20],EBP
    //         004d4671     ADD        this,0x1146c
    //         004d4677     MOV        EBP,0x1
    //         004d467c     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4681     MOV        EBX,EAX
    //                              taibldmd.cpp:537 (20)
    //         004d4683     CMP        EBX,EBP
    //         004d4685     JNZ        LAB_004d4699
    //         004d4687     MOV        EAX,dword ptr [ESP + 0x14]
    //         004d468b     TEST       EAX,EAX
    //         004d468d     JNZ        LAB_004d4699
    //         004d468f     MOV        EAX,dword ptr [ESP + 0x18]
    //         004d4693     TEST       EAX,EAX
    //         004d4695     JNZ        LAB_004d4699
    //                              taibldmd.cpp:538 (2)
    //         004d4697     XOR        EBP,EBP
    //                               LAB_004d4699                                                 XREF[3]:     004d4685(j), 004d468d(j), 
    //                                                                                                         004d4695(j)  
    //                              taibldmd.cpp:541 (39)
    //         004d4699     CMP        EBX,0x2
    //         004d469c     JNZ        LAB_004d46c2
    //         004d469e     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d46a4     PUSH       0x1
    //         004d46a6     ADD        this,0x10d7c
    //         004d46ac     CALL       TribeResourceAIModule::resource                  int resource(TribeResourceAIModule * this, in
    //         004d46b1     CMP        EAX,0xfa
    //         004d46b6     JGE        LAB_004d46c2
    //         004d46b8     MOV        EAX,dword ptr [ESP + 0x18]
    //         004d46bc     TEST       EAX,EAX
    //         004d46be     JNZ        LAB_004d46c2
    //                              taibldmd.cpp:542 (2)
    //         004d46c0     XOR        EBP,EBP
    //                               LAB_004d46c2                                                 XREF[3]:     004d469c(j), 004d46b6(j), 
    //                                                                                                         004d46be(j)  
    //                              taibldmd.cpp:543 (13)
    //         004d46c2     CMP        EBX,0x3
    //         004d46c5     JNZ        LAB_004d46d1
    //         004d46c7     MOV        EAX,dword ptr [ESP + 0x14]
    //         004d46cb     TEST       EAX,EAX
    //         004d46cd     JNZ        LAB_004d46d1
    //                              taibldmd.cpp:544 (2)
    //         004d46cf     XOR        EBP,EBP
    //                               LAB_004d46d1                                                 XREF[2]:     004d46c5(j), 004d46cd(j)  
    //                              taibldmd.cpp:545 (21)
    //         004d46d1     CMP        EBX,0x4
    //         004d46d4     JNZ        LAB_004d46e8
    //         004d46d6     MOV        EAX,dword ptr [ESP + 0x14]
    //         004d46da     TEST       EAX,EAX
    //         004d46dc     JZ         LAB_004d46e6
    //         004d46de     MOV        EAX,dword ptr [ESP + 0x18]
    //         004d46e2     TEST       EAX,EAX
    //         004d46e4     JNZ        LAB_004d46e8
    //                               LAB_004d46e6                                                 XREF[1]:     004d46dc(j)  
    //                              taibldmd.cpp:546 (2)
    //         004d46e6     XOR        EBP,EBP
    //                               LAB_004d46e8                                                 XREF[2]:     004d46d4(j), 004d46e4(j)  
    //                              taibldmd.cpp:556 (76)
    //         004d46e8     MOV        EAX,dword ptr [ESP + 0x114]
    //         004d46ef     TEST       EAX,EAX
    //         004d46f1     JNZ        LAB_004d47a4
    //         004d46f7     TEST       EBP,EBP
    //         004d46f9     JNZ        LAB_004d473a
    //         004d46fb     MOV        this,ESI
    //         004d46fd     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4702     TEST       EAX,EAX
    //         004d4704     JNZ        LAB_004d473a
    //         004d4706     MOV        this,ESI
    //         004d4708     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d470d     CMP        EAX,0x46
    //         004d4710     JZ         LAB_004d473a
    //         004d4712     MOV        this,ESI
    //         004d4714     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4719     CMP        EAX,0x6d
    //         004d471c     JZ         LAB_004d473a
    //         004d471e     MOV        this,ESI
    //         004d4720     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4725     CMP        EAX,0x67
    //         004d4728     JZ         LAB_004d473a
    //         004d472a     MOV        this,ESI
    //         004d472c     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4731     CMP        EAX,0x44
    //                              taibldmd.cpp:561 (6)
    //         004d4734     JNZ        LAB_004d489e
    //                               LAB_004d473a                                                 XREF[5]:     004d46f9(j), 004d4704(j), 
    //                                                                                                         004d4710(j), 004d471c(j), 
    //                                                                                                         004d4728(j)  
    //                              taibldmd.cpp:572 (100)
    //         004d473a     MOV        EAX,dword ptr [ESP + 0x114]
    //         004d4741     TEST       EAX,EAX
    //         004d4743     JNZ        LAB_004d47a4
    //         004d4745     MOV        this,ESI
    //         004d4747     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d474c     TEST       EAX,EAX
    //         004d474e     JNZ        LAB_004d47a4
    //         004d4750     MOV        EAX,dword ptr [ESP + 0x14]
    //         004d4754     TEST       EAX,EAX
    //         004d4756     JZ         LAB_004d4760
    //         004d4758     MOV        EAX,dword ptr [ESP + 0x18]
    //         004d475c     TEST       EAX,EAX
    //         004d475e     JNZ        LAB_004d47a4
    //                               LAB_004d4760                                                 XREF[1]:     004d4756(j)  
    //         004d4760     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4766     PUSH       0xae
    //         004d476b     ADD        this,0x1146c
    //         004d4771     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4776     CMP        dword ptr [ESP + 0x20],EAX
    //         004d477a     JL         LAB_004d47a4
    //         004d477c     MOV        this,ESI
    //         004d477e     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4783     CMP        EAX,0x6d
    //         004d4786     JZ         LAB_004d47a4
    //         004d4788     MOV        this,ESI
    //         004d478a     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d478f     CMP        EAX,0x67
    //         004d4792     JZ         LAB_004d47a4
    //         004d4794     MOV        this,ESI
    //         004d4796     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d479b     CMP        EAX,0x44
    //                              taibldmd.cpp:578 (6)
    //         004d479e     JNZ        LAB_004d489e
    //                               LAB_004d47a4                                                 XREF[7]:     004d46f1(j), 004d4743(j), 
    //                                                                                                         004d474e(j), 004d475e(j), 
    //                                                                                                         004d477a(j), 004d4786(j), 
    //                                                                                                         004d4792(j)  
    //                              taibldmd.cpp:583 (20)
    //         004d47a4     MOV        this,ESI
    //         004d47a6     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d47ab     CMP        EAX,0x5
    //         004d47ae     JNZ        LAB_004d47d0
    //         004d47b0     MOV        EAX,dword ptr [ESP + 0x10]
    //         004d47b4     TEST       EAX,EAX
    //         004d47b6     JNZ        LAB_004d47d0
    //                              taibldmd.cpp:584 (19)
    //         004d47b8     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d47be     PUSH       0x1
    //         004d47c0     ADD        this,0x1146c
    //         004d47c6     CALL       TribeTacticalAIModule::enableAttack              void enableAttack(TribeTacticalAIModule * thi
    //                              taibldmd.cpp:588 (5)
    //         004d47cb     JMP        LAB_004d488c
    //                               LAB_004d47d0                                                 XREF[2]:     004d47ae(j), 004d47b6(j)  
    //                              taibldmd.cpp:593 (12)
    //         004d47d0     MOV        this,ESI
    //         004d47d2     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d47d7     CMP        EAX,0x6
    //         004d47da     JNZ        LAB_004d480f
    //                              taibldmd.cpp:594 (11)
    //         004d47dc     CMP        dword ptr [ESP + 0x10],0x1
    //         004d47e1     JGE        LAB_004d489e
    //                              taibldmd.cpp:600 (38)
    //         004d47e7     MOV        this,ESI
    //         004d47e9     CALL       BuildItem::buildFrom                             int buildFrom(BuildItem * this)
    //         004d47ee     PUSH       EAX
    //         004d47ef     MOV        this,ESI
    //         004d47f1     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d47f6     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d47fc     ADD        EAX,0x9c
    //         004d4801     PUSH       EAX=>DAT_fffffff8
    //         004d4802     ADD        this,0x1146c
    //         004d4808     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taibldmd.cpp:605 (2)
    //         004d480d     JMP        LAB_004d488c
    //                               LAB_004d480f                                                 XREF[1]:     004d47da(j)  
    //                              taibldmd.cpp:610 (24)
    //         004d480f     MOV        EBP,dword ptr [ESP + 0x114]
    //         004d4816     CMP        EBP,0x3
    //         004d4819     JNZ        LAB_004d4827
    //         004d481b     MOV        EAX,dword ptr [ESP + 0x10]
    //         004d481f     TEST       EAX,EAX
    //         004d4821     JG         LAB_004d499b
    //                               LAB_004d4827                                                 XREF[1]:     004d4819(j)  
    //                              taibldmd.cpp:615 (30)
    //         004d4827     MOV        this,ESI
    //         004d4829     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
    //         004d482e     CMP        EAX,-0x1
    //         004d4831     JZ         LAB_004d4847
    //         004d4833     MOV        this,ESI
    //         004d4835     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
    //         004d483a     MOV        this,ESI
    //         004d483c     MOV        EBX,EAX
    //         004d483e     CALL       BuildItem::numberBuilds                          int numberBuilds(BuildItem * this)
    //         004d4843     CMP        EAX,EBX
    //                              taibldmd.cpp:621 (2)
    //         004d4845     JG         LAB_004d489e
    //                               LAB_004d4847                                                 XREF[1]:     004d4831(j)  
    //                              taibldmd.cpp:629 (69)
    //         004d4847     CMP        EBP,0x1
    //         004d484a     JNZ        LAB_004d49b8
    //         004d4850     MOV        this,ESI
    //         004d4852     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4857     CMP        EAX,EBP
    //         004d4859     JZ         LAB_004d486b
    //         004d485b     MOV        this,ESI
    //         004d485d     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4862     CMP        EAX,0x4
    //         004d4865     JNZ        LAB_004d49b8
    //                               LAB_004d486b                                                 XREF[1]:     004d4859(j)  
    //         004d486b     MOV        this,ESI
    //         004d486d     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4872     MOV        EDX,dword ptr [EDI + 0x5bc]
    //         004d4878     PUSH       EAX
    //         004d4879     MOV        this,dword ptr [EDX + 0x1256c]
    //         004d487f     CALL       TRIBE_Player::researchEverAvailable              int researchEverAvailable(TRIBE_Player * this
    //         004d4884     TEST       EAX,EAX
    //         004d4886     JNZ        LAB_004d49b8
    //                               LAB_004d488c                                                 XREF[2]:     004d47cb(j), 004d480d(j)  
    //                              taibldmd.cpp:634 (9)
    //         004d488c     PUSH       0x0
    //         004d488e     MOV        this,ESI
    //         004d4890     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:635 (9)
    //         004d4895     PUSH       0x1
    //         004d4897     MOV        this,ESI
    //         004d4899     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                               LAB_004d489e                                                 XREF[13]:    004d4648(j), 004d4657(j), 
    //                                                                                                         004d4734(j), 004d479e(j), 
    //                                                                                                         004d47e1(j), 004d4845(j), 
    //                                                                                                         004d4a8e(j), 004d4b3b(j), 
    //                                                                                                         004d4b4f(j), 004d4c41(j), 
    //                                                                                                         004d4c61(j), 004d4c9c(j), 
    //                                                                                                         004d4cba(j)  
    //                              taibldmd.cpp:884 (3)
    //         004d489e     MOV        ESI,dword ptr [ESI + 0x6c]
    //                               LAB_004d48a1                                                 XREF[1]:     004d4d93(j)  
    //                              taibldmd.cpp:485 (34)
    //         004d48a1     MOV        this,dword ptr [EDI + 0x5bc]
    //                              language.dll match for 0x73: "B"
    //         004d48a7     PUSH       0x73
    //         004d48a9     ADD        this,0x1146c
    //         004d48af     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d48b4     CMP        dword ptr [ESP + 0x10],EAX
    //         004d48b8     JLE        LAB_004d45b0
    //         004d48be     JMP        LAB_004d499b
    //                               LAB_004d48c3                                                 XREF[2]:     004d4a22(j), 004d4a43(j)  
    //                              taibldmd.cpp:649 (24)
    //         004d48c3     MOV        dword ptr [ESP + 0x10c],EBX
    //         004d48ca     LEA        this,[ESP + 0x94]
    //                               LAB_004d48d1                                                 XREF[1]:     004d4a5a(j)  
    //         004d48d1     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //         004d48d6     JMP        LAB_004d499b
    //                               LAB_004d48db                                                 XREF[2]:     004d4b63(j), 004d4bc1(j)  
    //                              taibldmd.cpp:744 (9)
    //         004d48db     PUSH       0x0
    //         004d48dd     MOV        this,ESI
    //         004d48df     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                              taibldmd.cpp:745 (5)
    //         004d48e4     JMP        LAB_004d499b
    //                               LAB_004d48e9                                                 XREF[1]:     004d4c74(j)  
    //                              taibldmd.cpp:771 (25)
    //         004d48e9     PUSH       0x3f
    //         004d48eb     MOV        this,ESI
    //         004d48ed     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         004d48f2     LEA        EDX,[EDI + 0x3a6]
    //         004d48f8     PUSH       EAX=>DAT_fffffff8
    //         004d48f9     PUSH       EDX=>DAT_fffffff4
    //         004d48fa     CALL       strncpy                                          undefined strncpy()
    //         004d48ff     ADD        ESP,0xc
    //                              taibldmd.cpp:772 (13)
    //         004d4902     MOV        this,ESI
    //         004d4904     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d4909     MOV        dword ptr [EDI + 0x5a8],EAX
    //                              taibldmd.cpp:773 (26)
    //         004d490f     MOV        this,dword ptr [ESI + 0x6c]
    //         004d4912     PUSH       0x3f
    //         004d4914     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         004d4919     PUSH       EAX=>DAT_fffffff8
    //         004d491a     LEA        EAX,[EDI + 0x4a7]
    //         004d4920     PUSH       EAX=>DAT_fffffff4
    //         004d4921     CALL       strncpy                                          undefined strncpy()
    //         004d4926     ADD        ESP,0xc
    //                              taibldmd.cpp:774 (13)
    //         004d4929     MOV        this,ESI
    //         004d492b     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d4930     MOV        dword ptr [EDI + 0x5a8],EAX
    //                              taibldmd.cpp:775 (4)
    //         004d4936     MOV        EAX,ESI
    //         004d4938     JMP        LAB_004d499d
    //                               LAB_004d493a                                                 XREF[1]:     004d4d7a(j)  
    //                              taibldmd.cpp:850 (25)
    //         004d493a     PUSH       0x3f
    //         004d493c     MOV        this,ESI
    //         004d493e     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         004d4943     LEA        this,[EDI + 0x3a6]
    //         004d4949     PUSH       EAX=>DAT_fffffff8
    //         004d494a     PUSH       this=>DAT_fffffff4
    //         004d494b     CALL       strncpy                                          undefined strncpy()
    //         004d4950     ADD        ESP,0xc
    //                              taibldmd.cpp:851 (13)
    //         004d4953     MOV        this,ESI
    //         004d4955     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d495a     MOV        dword ptr [EDI + 0x5a8],EAX
    //                              taibldmd.cpp:852 (26)
    //         004d4960     MOV        this,dword ptr [ESI + 0x6c]
    //         004d4963     PUSH       0x3f
    //         004d4965     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         004d496a     LEA        EDX,[EDI + 0x4a7]
    //         004d4970     PUSH       EAX=>DAT_fffffff8
    //         004d4971     PUSH       EDX=>DAT_fffffff4
    //         004d4972     CALL       strncpy                                          undefined strncpy()
    //         004d4977     ADD        ESP,0xc
    //                              taibldmd.cpp:853 (17)
    //         004d497a     MOV        this,ESI
    //         004d497c     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d4981     LEA        this,[ESP + 0x24]
    //         004d4985     MOV        dword ptr [EDI + 0x5a8],EAX
    //                              taibldmd.cpp:854 (16)
    //         004d498b     MOV        dword ptr [ESP + 0x10c],EBX
    //         004d4992     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //         004d4997     MOV        EAX,ESI
    //         004d4999     JMP        LAB_004d499d
    //                               LAB_004d499b                                                 XREF[7]:     004d45aa(j), 004d45b8(j), 
    //                                                                                                         004d45c0(j), 004d4821(j), 
    //                                                                                                         004d48be(j), 004d48d6(j), 
    //                                                                                                         004d48e4(j)  
    //                              taibldmd.cpp:890 (2)
    //         004d499b     XOR        EAX,EAX
    //                               LAB_004d499d                                                 XREF[2]:     004d4938(j), 004d4999(j)  
    //                              taibldmd.cpp:891 (27)
    //         004d499d     MOV        this,dword ptr [ESP + 0x104]
    //         004d49a4     POP        EDI
    //         004d49a5     POP        ESI
    //         004d49a6     POP        EBP
    //         004d49a7     MOV        dword ptr FS:[0x0],this
    //         004d49ae     POP        EBX
    //         004d49af     ADD        ESP,0x100
    //         004d49b5     RET        0x4
    //                               LAB_004d49b8                                                 XREF[3]:     004d484a(j), 004d4865(j), 
    //                                                                                                         004d4886(j)  
    //                              taibldmd.cpp:641 (16)
    //         004d49b8     MOV        this,ESI
    //         004d49ba     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d49bf     CMP        EAX,0x4
    //         004d49c2     JNZ        LAB_004d4a65
    //                              taibldmd.cpp:642 (13)
    //         004d49c8     PUSH       EAX
    //         004d49c9     LEA        this,[ESP + 0x98]
    //         004d49d0     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
    //                              taibldmd.cpp:643 (50)
    //         004d49d5     LEA        EAX,[ESP + 0x94]
    //         004d49dc     PUSH       0x1
    //         004d49de     OR         EBX,0xffffffff
    //         004d49e1     PUSH       EAX=>DAT_fffffff8
    //         004d49e2     PUSH       EBX=>DAT_fffffff4
    //         004d49e3     MOV        this,ESI
    //         004d49e5     MOV        dword ptr [ESP + 0x118],0x0
    //         004d49f0     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d49f5     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d49fb     PUSH       EAX=>DAT_fffffff0
    //         004d49fc     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d4a02     CALL       TRIBE_Player::researchCost                       void researchCost(TRIBE_Player * this, int pa
    //                              taibldmd.cpp:645 (66)
    //         004d4a07     MOV        this,ESI
    //         004d4a09     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4a0e     MOV        EDX,dword ptr [EDI + 0x5bc]
    //         004d4a14     PUSH       EAX
    //         004d4a15     MOV        this,dword ptr [EDX + 0x1256c]
    //         004d4a1b     CALL       TRIBE_Player::researchAvailable                  int researchAvailable(TRIBE_Player * this, in
    //         004d4a20     TEST       EAX,EAX
    //         004d4a22     JZ         LAB_004d48c3
    //         004d4a28     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4a2e     LEA        EAX,[ESP + 0x94]
    //         004d4a35     PUSH       EAX
    //         004d4a36     ADD        this,0x10d7c
    //         004d4a3c     CALL       TribeResourceAIModule::resourcesAvailable        int resourcesAvailable(TribeResourceAIModule 
    //         004d4a41     TEST       EAX,EAX
    //         004d4a43     JZ         LAB_004d48c3
    //                              taibldmd.cpp:653 (3)
    //         004d4a49     CMP        EBP,0x1
    //                              taibldmd.cpp:659 (25)
    //         004d4a4c     MOV        dword ptr [ESP + 0x10c],EBX
    //         004d4a53     LEA        this,[ESP + 0x94]
    //         004d4a5a     JNZ        LAB_004d48d1
    //         004d4a60     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //                               LAB_004d4a65                                                 XREF[1]:     004d49c2(j)  
    //                              taibldmd.cpp:664 (34)
    //         004d4a65     MOV        this,ESI
    //         004d4a67     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //         004d4a6c     CMP        EAX,0x1
    //         004d4a6f     JNZ        LAB_004d4a7c
    //         004d4a71     MOV        this,ESI
    //         004d4a73     CALL       BuildItem::buildAttempts                         int buildAttempts(BuildItem * this)
    //         004d4a78     TEST       EAX,EAX
    //         004d4a7a     JG         LAB_004d4a87
    //                               LAB_004d4a7c                                                 XREF[1]:     004d4a6f(j)  
    //         004d4a7c     MOV        this,ESI
    //         004d4a7e     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
    //         004d4a83     TEST       AL,AL
    //         004d4a85     JZ         LAB_004d4a93
    //                               LAB_004d4a87                                                 XREF[1]:     004d4a7a(j)  
    //                              taibldmd.cpp:665 (7)
    //         004d4a87     MOV        this,ESI
    //         004d4a89     CALL       BuildItem::decrementBuildAttempts                void decrementBuildAttempts(BuildItem * this)
    //                              taibldmd.cpp:671 (5)
    //         004d4a8e     JMP        LAB_004d489e
    //                               LAB_004d4a93                                                 XREF[1]:     004d4a85(j)  
    //                              taibldmd.cpp:674 (23)
    //         004d4a93     MOV        this,ESI
    //         004d4a95     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //         004d4a9a     CMP        EAX,0x1
    //         004d4a9d     JNZ        LAB_004d4af2
    //         004d4a9f     MOV        this,ESI
    //         004d4aa1     CALL       BuildItem::buildAttempts                         int buildAttempts(BuildItem * this)
    //         004d4aa6     TEST       EAX,EAX
    //         004d4aa8     JG         LAB_004d4af2
    //                              taibldmd.cpp:678 (9)
    //         004d4aaa     PUSH       0x0
    //         004d4aac     MOV        this,ESI
    //         004d4aae     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
    //                              taibldmd.cpp:684 (35)
    //         004d4ab3     MOV        this,ESI
    //         004d4ab5     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4aba     TEST       EAX,EAX
    //         004d4abc     JNZ        LAB_004d4af2
    //         004d4abe     MOV        this,ESI
    //         004d4ac0     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4ac5     CMP        EAX,0x67
    //         004d4ac8     JZ         LAB_004d4ad6
    //         004d4aca     MOV        this,ESI
    //         004d4acc     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4ad1     CMP        EAX,0x44
    //         004d4ad4     JNZ        LAB_004d4af2
    //                               LAB_004d4ad6                                                 XREF[1]:     004d4ac8(j)  
    //                              taibldmd.cpp:685 (28)
    //         004d4ad6     MOV        this,dword ptr [EDI + 0x5bc]
    //                              language.dll match for 0x72: "21"
    //         004d4adc     PUSH       0x72
    //         004d4ade     ADD        this,0x1146c
    //         004d4ae4     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4ae9     DEC        EAX
    //         004d4aea     MOV        this,ESI
    //         004d4aec     PUSH       EAX
    //         004d4aed     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                               LAB_004d4af2                                                 XREF[4]:     004d4a9d(j), 004d4aa8(j), 
    //                                                                                                         004d4abc(j), 004d4ad4(j)  
    //                              taibldmd.cpp:691 (43)
    //         004d4af2     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4af8     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004d4afe     MOV        EAX,dword ptr [EDX + 0x50]
    //         004d4b01     FLD        float ptr [EAX + 0x2c]
    //         004d4b04     FCOMP      float ptr [EAX + 0x80]
    //         004d4b0a     FNSTSW     AX
    //         004d4b0c     TEST       AH,0x1
    //         004d4b0f     JNZ        LAB_004d4b1d
    //         004d4b11     MOV        this,ESI
    //         004d4b13     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4b18     CMP        EAX,0x2
    //         004d4b1b     JZ         LAB_004d4b21
    //                               LAB_004d4b1d                                                 XREF[1]:     004d4b0f(j)  
    //                              taibldmd.cpp:692 (4)
    //         004d4b1d     INC        dword ptr [ESP + 0x10]
    //                               LAB_004d4b21                                                 XREF[1]:     004d4b1b(j)  
    //                              taibldmd.cpp:697 (46)
    //         004d4b21     CMP        EBP,0x1
    //         004d4b24     JNZ        LAB_004d4b46
    //         004d4b26     MOV        this,ESI
    //         004d4b28     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4b2d     CMP        EAX,EBP
    //         004d4b2f     JZ         LAB_004d4b41
    //         004d4b31     MOV        this,ESI
    //         004d4b33     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4b38     CMP        EAX,0x4
    //         004d4b3b     JNZ        LAB_004d489e
    //                               LAB_004d4b41                                                 XREF[1]:     004d4b2f(j)  
    //         004d4b41     CMP        EBP,0x1
    //         004d4b44     JZ         LAB_004d4b55
    //                               LAB_004d4b46                                                 XREF[1]:     004d4b24(j)  
    //         004d4b46     MOV        this,ESI
    //         004d4b48     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4b4d     CMP        EBP,EAX
    //                              taibldmd.cpp:703 (6)
    //         004d4b4f     JNZ        LAB_004d489e
    //                               LAB_004d4b55                                                 XREF[1]:     004d4b44(j)  
    //                              taibldmd.cpp:713 (20)
    //         004d4b55     CMP        EBP,0x3
    //         004d4b58     JNZ        LAB_004d4b69
    //         004d4b5a     MOV        this,ESI
    //         004d4b5c     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4b61     CMP        EAX,EBP
    //         004d4b63     JNZ        LAB_004d48db
    //                               LAB_004d4b69                                                 XREF[1]:     004d4b58(j)  
    //                              taibldmd.cpp:722 (7)
    //         004d4b69     MOV        this,ESI
    //         004d4b6b     CALL       BuildItem::incrementBuildAttempts                void incrementBuildAttempts(BuildItem * this)
    //                              taibldmd.cpp:728 (7)
    //         004d4b70     MOV        this,ESI
    //         004d4b72     CALL       BuildItem::buildAttempts                         int buildAttempts(BuildItem * this)
    //                              taibldmd.cpp:729 (21)
    //         004d4b77     MOV        this,dword ptr [EDI + 0x5bc]
    //                              language.dll match for 0x72: "21"
    //         004d4b7d     PUSH       0x72
    //         004d4b7f     ADD        this,0x1146c
    //         004d4b85     MOV        EBX,EAX
    //         004d4b87     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //                              taibldmd.cpp:732 (38)
    //         004d4b8c     CMP        EBX,EAX
    //         004d4b8e     JLE        LAB_004d4c66
    //         004d4b94     MOV        this,ESI
    //         004d4b96     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //         004d4b9b     TEST       EAX,EAX
    //         004d4b9d     JNZ        LAB_004d4c66
    //         004d4ba3     MOV        this,ESI
    //         004d4ba5     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
    //         004d4baa     TEST       AL,AL
    //         004d4bac     JNZ        LAB_004d4c66
    //                              taibldmd.cpp:740 (21)
    //         004d4bb2     CMP        EBP,0x1
    //         004d4bb5     JNZ        LAB_004d4bc7
    //         004d4bb7     MOV        this,ESI
    //         004d4bb9     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4bbe     CMP        EAX,0x4
    //         004d4bc1     JZ         LAB_004d48db
    //                               LAB_004d4bc7                                                 XREF[1]:     004d4bb5(j)  
    //                              taibldmd.cpp:747 (46)
    //         004d4bc7     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4bcd     PUSH       0xb1
    //         004d4bd2     ADD        this,0x1146c
    //         004d4bd8     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4bdd     MOV        this,ESI
    //         004d4bdf     MOV        EBX,EAX
    //         004d4be1     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4be6     CMP        EAX,EBX
    //         004d4be8     JNZ        LAB_004d4bf5
    //         004d4bea     MOV        this,ESI
    //         004d4bec     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4bf1     TEST       EAX,EAX
    //         004d4bf3     JZ         LAB_004d4c66
    //                               LAB_004d4bf5                                                 XREF[1]:     004d4be8(j)  
    //                              taibldmd.cpp:751 (9)
    //         004d4bf5     PUSH       0x1
    //         004d4bf7     MOV        this,ESI
    //         004d4bf9     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
    //                              taibldmd.cpp:755 (35)
    //         004d4bfe     MOV        this,ESI
    //         004d4c00     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4c05     TEST       EAX,EAX
    //         004d4c07     JNZ        LAB_004d4c46
    //         004d4c09     MOV        this,ESI
    //         004d4c0b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4c10     CMP        EAX,0x67
    //         004d4c13     JZ         LAB_004d4c21
    //         004d4c15     MOV        this,ESI
    //         004d4c17     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4c1c     CMP        EAX,0x44
    //         004d4c1f     JNZ        LAB_004d4c46
    //                               LAB_004d4c21                                                 XREF[1]:     004d4c13(j)  
    //                              taibldmd.cpp:756 (22)
    //         004d4c21     MOV        this,dword ptr [EDI + 0x5bc]
    //                              language.dll match for 0x72: "21"
    //         004d4c27     PUSH       0x72
    //         004d4c29     ADD        this,0x1146c
    //         004d4c2f     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4c34     LEA        EAX,[EAX + EAX*0x2]
    //                              taibldmd.cpp:758 (10)
    //         004d4c37     MOV        this,ESI
    //         004d4c39     SHL        EAX,0x1
    //         004d4c3b     PUSH       EAX
    //         004d4c3c     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                              taibldmd.cpp:760 (5)
    //         004d4c41     JMP        LAB_004d489e
    //                               LAB_004d4c46                                                 XREF[2]:     004d4c07(j), 004d4c1f(j)  
    //                              taibldmd.cpp:758 (27)
    //         004d4c46     MOV        this,dword ptr [EDI + 0x5bc]
    //                              language.dll match for 0x72: "21"
    //         004d4c4c     PUSH       0x72
    //         004d4c4e     ADD        this,0x1146c
    //         004d4c54     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004d4c59     PUSH       EAX
    //         004d4c5a     MOV        this,ESI
    //         004d4c5c     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                              taibldmd.cpp:760 (5)
    //         004d4c61     JMP        LAB_004d489e
    //                               LAB_004d4c66                                                 XREF[4]:     004d4b8e(j), 004d4b9d(j), 
    //                                                                                                         004d4bac(j), 004d4bf3(j)  
    //                              taibldmd.cpp:766 (20)
    //         004d4c66     CMP        EBP,0x3
    //         004d4c69     JNZ        LAB_004d4c7a
    //         004d4c6b     MOV        this,ESI
    //         004d4c6d     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4c72     CMP        EAX,EBP
    //         004d4c74     JZ         LAB_004d48e9
    //                               LAB_004d4c7a                                                 XREF[1]:     004d4c69(j)  
    //                              taibldmd.cpp:779 (3)
    //         004d4c7a     CMP        EBP,0x1
    //                              taibldmd.cpp:780 (31)
    //         004d4c7d     MOV        this,ESI
    //         004d4c7f     JNZ        LAB_004d4ca1
    //         004d4c81     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4c86     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4c8c     PUSH       EAX
    //         004d4c8d     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d4c93     CALL       TRIBE_Player::researchAvailable                  int researchAvailable(TRIBE_Player * this, in
    //         004d4c98     TEST       EAX,EAX
    //         004d4c9a     JNZ        LAB_004d4cc0
    //                              taibldmd.cpp:786 (5)
    //         004d4c9c     JMP        LAB_004d489e
    //                               LAB_004d4ca1                                                 XREF[1]:     004d4c7f(j)  
    //                              taibldmd.cpp:789 (25)
    //         004d4ca1     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4ca6     MOV        EDX,dword ptr [EDI + 0x5bc]
    //         004d4cac     PUSH       EAX
    //         004d4cad     MOV        this,dword ptr [EDX + 0x1256c]
    //         004d4cb3     CALL       TRIBE_Player::objectAvailable                    int objectAvailable(TRIBE_Player * this, int 
    //         004d4cb8     TEST       EAX,EAX
    //                              taibldmd.cpp:794 (6)
    //         004d4cba     JZ         LAB_004d489e
    //                               LAB_004d4cc0                                                 XREF[1]:     004d4c9a(j)  
    //                              taibldmd.cpp:799 (11)
    //         004d4cc0     PUSH       0x4
    //         004d4cc2     LEA        this,[ESP + 0x28]
    //         004d4cc6     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
    //                              taibldmd.cpp:800 (14)
    //         004d4ccb     CMP        EBP,0x1
    //         004d4cce     MOV        dword ptr [ESP + 0x10c],0x1
    //                              taibldmd.cpp:801 (38)
    //         004d4cd9     PUSH       0x1
    //         004d4cdb     JNZ        LAB_004d4d01
    //         004d4cdd     LEA        EAX,[ESP + 0x28]
    //         004d4ce1     OR         EBX,0xffffffff
    //         004d4ce4     PUSH       EAX=>DAT_fffffff8
    //         004d4ce5     PUSH       EBX=>DAT_fffffff4
    //         004d4ce6     MOV        this,ESI
    //         004d4ce8     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4ced     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4cf3     PUSH       EAX=>DAT_fffffff0
    //         004d4cf4     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d4cfa     CALL       TRIBE_Player::researchCost                       void researchCost(TRIBE_Player * this, int pa
    //                              taibldmd.cpp:802 (2)
    //         004d4cff     JMP        LAB_004d4d23
    //                               LAB_004d4d01                                                 XREF[1]:     004d4cdb(j)  
    //                              taibldmd.cpp:803 (34)
    //         004d4d01     LEA        EDX,[ESP + 0x28]
    //         004d4d05     OR         EBX,0xffffffff
    //         004d4d08     PUSH       EDX=>DAT_fffffff8
    //         004d4d09     PUSH       EBX=>DAT_fffffff4
    //         004d4d0a     MOV        this,ESI
    //         004d4d0c     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4d11     PUSH       EAX=>DAT_fffffff0
    //         004d4d12     MOV        EAX,dword ptr [EDI + 0x5bc]
    //         004d4d18     MOV        this,dword ptr [EAX + 0x1256c]
    //         004d4d1e     CALL       TRIBE_Player::objectCost                         void objectCost(TRIBE_Player * this, int para
    //                               LAB_004d4d23                                                 XREF[1]:     004d4cff(j)  
    //                              taibldmd.cpp:804 (24)
    //         004d4d23     LEA        this,[ESP + 0x24]
    //         004d4d27     PUSH       this
    //         004d4d28     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4d2e     ADD        this,0x10d7c
    //         004d4d34     CALL       TribeResourceAIModule::resourcesAvailable        int resourcesAvailable(TribeResourceAIModule 
    //         004d4d39     TEST       EAX,EAX
    //                              taibldmd.cpp:817 (2)
    //         004d4d3b     JZ         LAB_004d4d80
    //                              taibldmd.cpp:823 (10)
    //         004d4d3d     CMP        EBP,0x2
    //         004d4d40     JZ         LAB_004d4d5b
    //         004d4d42     CMP        EBP,0x1
    //         004d4d45     JZ         LAB_004d4d5b
    //                              taibldmd.cpp:835 (18)
    //         004d4d47     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4d4d     PUSH       ESI
    //         004d4d4e     ADD        this,0x6c4
    //         004d4d54     CALL       TribeConstructionAIModule::canPlace              int canPlace(TribeConstructionAIModule * this
    //                              taibldmd.cpp:840 (2)
    //         004d4d59     JMP        LAB_004d4d78
    //                               LAB_004d4d5b                                                 XREF[2]:     004d4d40(j), 004d4d45(j)  
    //                              taibldmd.cpp:825 (37)
    //         004d4d5b     PUSH       EBX
    //         004d4d5c     PUSH       offset DAT_fffffff8
    //         004d4d5e     PUSH       EBX=>DAT_fffffff4
    //         004d4d5f     PUSH       EBX=>DAT_fffffff0
    //         004d4d60     PUSH       EBX
    //         004d4d61     PUSH       EBX
    //         004d4d62     PUSH       EBX
    //         004d4d63     PUSH       EBX
    //         004d4d64     MOV        this,ESI
    //         004d4d66     CALL       BuildItem::buildFrom                             int buildFrom(BuildItem * this)
    //         004d4d6b     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d4d71     PUSH       EAX
    //         004d4d72     PUSH       EBX
    //         004d4d73     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
    //                               LAB_004d4d78                                                 XREF[1]:     004d4d59(j)  
    //         004d4d78     TEST       EAX,EAX
    //         004d4d7a     JNZ        LAB_004d493a
    //                               LAB_004d4d80                                                 XREF[1]:     004d4d3b(j)  
    //                              taibldmd.cpp:829 (7)
    //         004d4d80     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d4d83     LEA        this,[ESP + 0x24]
    //                              taibldmd.cpp:830 (17)
    //         004d4d87     MOV        dword ptr [ESP + 0x10c],EBX
    //         004d4d8e     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //         004d4d93     JMP        LAB_004d48a1
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004d4615::switchdataD_004d4d98                       XREF[1]:     nextBuildableItem:004d4615(*)  
    //                              taibldmd.cpp:891 (16)
}

// Offset: 0x004D4DB0
int nextBuildListItemCategory(TribeBuildAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::nextBuildListItemCategory(void)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall nextBuildListItemCategory(TribeBuildAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //                               ?nextBuildListItemCategory@TribeBuildAIModule@@QAEHXZ
    //                               TribeBuildAIModule::nextBuildListItemCategory
    //                              taibldmd.cpp:896 (1)
    //         004d4db0     PUSH       ESI
    //                              taibldmd.cpp:897 (7)
    //         004d4db1     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004d4db7     PUSH       EDI
    //                              taibldmd.cpp:898 (14)
    //         004d4db8     LEA        EDI,[ECX + this->_padding_]
    //         004d4dbe     CMP        ESI,EDI
    //         004d4dc0     JZ         LAB_004d4e09
    //                               LAB_004d4dc2                                                 XREF[1]:     004d4df8(j)  
    //         004d4dc2     TEST       ESI,ESI
    //         004d4dc4     JZ         LAB_004d4e09
    //                              taibldmd.cpp:904 (45)
    //         004d4dc6     MOV        this,ESI
    //         004d4dc8     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d4dcd     TEST       EAX,EAX
    //         004d4dcf     JNZ        LAB_004d4df3
    //         004d4dd1     MOV        this,ESI
    //         004d4dd3     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d4dd8     TEST       EAX,EAX
    //         004d4dda     JNZ        LAB_004d4df3
    //         004d4ddc     MOV        this,ESI
    //         004d4dde     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //         004d4de3     CMP        EAX,0x1
    //         004d4de6     JZ         LAB_004d4df3
    //         004d4de8     MOV        this,ESI
    //         004d4dea     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
    //         004d4def     TEST       AL,AL
    //         004d4df1     JZ         LAB_004d4dff
    //                               LAB_004d4df3                                                 XREF[3]:     004d4dcf(j), 004d4dda(j), 
    //                                                                                                         004d4de6(j)  
    //                              taibldmd.cpp:907 (7)
    //         004d4df3     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d4df6     CMP        ESI,EDI
    //         004d4df8     JNZ        LAB_004d4dc2
    //                              taibldmd.cpp:909 (2)
    //         004d4dfa     XOR        EAX,EAX
    //                              taibldmd.cpp:910 (3)
    //         004d4dfc     POP        EDI
    //         004d4dfd     POP        ESI
    //         004d4dfe     RET
    //                               LAB_004d4dff                                                 XREF[1]:     004d4df1(j)  
    //                              taibldmd.cpp:905 (7)
    //         004d4dff     MOV        this,ESI
    //         004d4e01     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //                              taibldmd.cpp:910 (8)
    //         004d4e06     POP        EDI
    //         004d4e07     POP        ESI
    //         004d4e08     RET
    //                               LAB_004d4e09                                                 XREF[2]:     004d4dc0(j), 004d4dc4(j)  
    //         004d4e09     POP        EDI
    //         004d4e0a     XOR        EAX,EAX
    //         004d4e0c     POP        ESI
    //         004d4e0d     RET
}

// Offset: 0x004D4E10
int blockingResource(TribeBuildAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::blockingResource(void)                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall blockingResource(TribeBuildAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004d4e96(W), 004d4f33(W), 004d4f5b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004d4f45(R), 004d4f6b(R)  
    //              ResourceItem      Stack[-0x80]   itemCost                  XREF[0,7]:   004d4e8b(*), 004d4eb7(*), 004d4edb(*), 004d4efd(*), 
    //                                                                                     004d4f1d(*), 004d4f2d(*), 004d4f57(*)  
    //                               ?blockingResource@TribeBuildAIModule@@QAEHXZ
    //                               TribeBuildAIModule::blockingResource
    //                              taibldmd.cpp:915 (29)
    //         004d4e10     MOV        EAX,FS:[0x0]
    //         004d4e16     PUSH       -0x1
    //         004d4e18     PUSH       FUN_005602b8
    //         004d4e1d     PUSH       EAX
    //         004d4e1e     MOV        dword ptr FS:[0x0],ESP
    //         004d4e25     SUB        ESP,0x70
    //         004d4e28     PUSH       EBX
    //         004d4e29     MOV        EBX,this
    //         004d4e2b     PUSH       ESI
    //         004d4e2c     PUSH       EDI
    //                              taibldmd.cpp:923 (6)
    //         004d4e2d     MOV        ESI,dword ptr [EBX + 0x15c]
    //                              taibldmd.cpp:924 (18)
    //         004d4e33     LEA        EDI,[EBX + 0xf0]
    //         004d4e39     CMP        ESI,EDI
    //         004d4e3b     JZ         LAB_004d4f6b
    //                               LAB_004d4e41                                                 XREF[1]:     004d4e77(j)  
    //         004d4e41     TEST       ESI,ESI
    //         004d4e43     JZ         LAB_004d4e79
    //                              taibldmd.cpp:928 (45)
    //         004d4e45     MOV        this,ESI
    //         004d4e47     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d4e4c     TEST       EAX,EAX
    //         004d4e4e     JNZ        LAB_004d4e72
    //         004d4e50     MOV        this,ESI
    //         004d4e52     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d4e57     TEST       EAX,EAX
    //         004d4e59     JNZ        LAB_004d4e72
    //         004d4e5b     MOV        this,ESI
    //         004d4e5d     CALL       BaseItem::skip                                   int skip(BaseItem * this)
    //         004d4e62     CMP        EAX,0x1
    //         004d4e65     JZ         LAB_004d4e72
    //         004d4e67     MOV        this,ESI
    //         004d4e69     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
    //         004d4e6e     TEST       AL,AL
    //         004d4e70     JZ         LAB_004d4e79
    //                               LAB_004d4e72                                                 XREF[3]:     004d4e4e(j), 004d4e59(j), 
    //                                                                                                         004d4e65(j)  
    //                              taibldmd.cpp:931 (7)
    //         004d4e72     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d4e75     CMP        ESI,EDI
    //         004d4e77     JNZ        LAB_004d4e41
    //                               LAB_004d4e79                                                 XREF[2]:     004d4e43(j), 004d4e70(j)  
    //                              taibldmd.cpp:934 (16)
    //         004d4e79     CMP        ESI,EDI
    //         004d4e7b     JZ         LAB_004d4f6b
    //         004d4e81     TEST       ESI,ESI
    //         004d4e83     JZ         LAB_004d4f6b
    //                              taibldmd.cpp:938 (11)
    //         004d4e89     PUSH       0x4
    //         004d4e8b     LEA        this=>itemCost.next,[ESP + 0x10]
    //         004d4e8f     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
    //                              taibldmd.cpp:940 (35)
    //         004d4e94     MOV        this,ESI
    //         004d4e96     MOV        dword ptr [ESP + local_4],0x0
    //         004d4ea1     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4ea6     CMP        EAX,0x1
    //         004d4ea9     JZ         LAB_004d4edb
    //         004d4eab     MOV        this,ESI
    //         004d4ead     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4eb2     CMP        EAX,0x4
    //         004d4eb5     JZ         LAB_004d4edb
    //                              taibldmd.cpp:943 (36)
    //         004d4eb7     LEA        EAX=>itemCost.next,[ESP + 0xc]
    //         004d4ebb     PUSH       0x1
    //         004d4ebd     PUSH       EAX
    //         004d4ebe     PUSH       -0x1
    //         004d4ec0     MOV        this,ESI
    //         004d4ec2     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4ec7     MOV        this,dword ptr [EBX + 0x5bc]
    //         004d4ecd     PUSH       EAX
    //         004d4ece     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d4ed4     CALL       TRIBE_Player::objectCost                         void objectCost(TRIBE_Player * this, int para
    //         004d4ed9     JMP        LAB_004d4efd
    //                               LAB_004d4edb                                                 XREF[2]:     004d4ea9(j), 004d4eb5(j)  
    //                              taibldmd.cpp:941 (34)
    //         004d4edb     LEA        EDX=>itemCost.next,[ESP + 0xc]
    //         004d4edf     PUSH       0x1
    //         004d4ee1     PUSH       EDX
    //         004d4ee2     PUSH       -0x1
    //         004d4ee4     MOV        this,ESI
    //         004d4ee6     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d4eeb     PUSH       EAX
    //         004d4eec     MOV        EAX,dword ptr [EBX + 0x5bc]
    //         004d4ef2     MOV        this,dword ptr [EAX + 0x1256c]
    //         004d4ef8     CALL       TRIBE_Player::researchCost                       void researchCost(TRIBE_Player * this, int pa
    //                               LAB_004d4efd                                                 XREF[1]:     004d4ed9(j)  
    //                              taibldmd.cpp:944 (26)
    //         004d4efd     LEA        this=>itemCost.next,[ESP + 0xc]
    //         004d4f01     PUSH       this
    //         004d4f02     MOV        this,dword ptr [EBX + 0x5bc]
    //         004d4f08     ADD        this,0x10d7c
    //         004d4f0e     CALL       TribeResourceAIModule::resourcesAvailable        int resourcesAvailable(TribeResourceAIModule 
    //         004d4f13     TEST       EAX,EAX
    //         004d4f15     JNZ        LAB_004d4f57
    //                              taibldmd.cpp:949 (46)
    //         004d4f17     MOV        this,dword ptr [EBX + 0x5bc]
    //         004d4f1d     LEA        EDX=>itemCost.next,[ESP + 0xc]
    //         004d4f21     PUSH       EDX
    //         004d4f22     ADD        this,0x10d7c
    //         004d4f28     CALL       TribeResourceAIModule::unavailableResource       int unavailableResource(TribeResourceAIModule
    //         004d4f2d     LEA        this=>itemCost.next,[ESP + 0xc]
    //         004d4f31     MOV        ESI,EAX
    //         004d4f33     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004d4f3e     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //         004d4f43     MOV        EAX,ESI
    //                              taibldmd.cpp:956 (22)
    //         004d4f45     MOV        this,dword ptr [ESP + local_c]
    //         004d4f49     MOV        dword ptr FS:[0x0],this
    //         004d4f50     POP        EDI
    //         004d4f51     POP        ESI
    //         004d4f52     POP        EBX
    //         004d4f53     ADD        ESP,0x7c
    //         004d4f56     RET
    //                               LAB_004d4f57                                                 XREF[1]:     004d4f15(j)  
    //         004d4f57     LEA        this=>itemCost.next,[ESP + 0xc]
    //                              taibldmd.cpp:951 (16)
    //         004d4f5b     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004d4f66     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //                               LAB_004d4f6b                                                 XREF[3]:     004d4e3b(j), 004d4e7b(j), 
    //                                                                                                         004d4e83(j)  
    //                              taibldmd.cpp:956 (21)
    //         004d4f6b     MOV        this,dword ptr [ESP + local_c]
    //         004d4f6f     POP        EDI
    //         004d4f70     POP        ESI
    //         004d4f71     OR         EAX,0xffffffff
    //         004d4f74     MOV        dword ptr FS:[0x0],this
    //         004d4f7b     POP        EBX
    //         004d4f7c     ADD        ESP,0x7c
    //         004d4f7f     RET
}

// Offset: 0x004D4F80
int mostNeededResource(TribeBuildAIModule* this_, ResourceItem* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::mostNeededResource(class ResourceItem &,int)               *
    //                              *********************************************************************************************************
    //                              int __thiscall mostNeededResource(TribeBuildAIModule * this, Resourc
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[5]:     004d4f81(R), 004d4fa1(W), 004d505b(R), 004d5066(W), 
    //                                                                                     004d507d(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d505f(R)  
    //                               ?mostNeededResource@TribeBuildAIModule@@QAEHAAVResourceItem  XREF[1]:     updateNeededResources:004f8c63(c)  
    //                               TribeBuildAIModule::mostNeededResource
    //                              taibldmd.cpp:962 (1)
    //         004d4f80     PUSH       EBX
    //                              taibldmd.cpp:968 (18)
    //         004d4f81     MOV        EBX,dword ptr [ESP + param_1]
    //         004d4f85     PUSH       EBP
    //         004d4f86     PUSH       ESI
    //         004d4f87     PUSH       EDI
    //         004d4f88     MOV        EDI,this
    //         004d4f8a     PUSH       0x0
    //         004d4f8c     MOV        this,EBX
    //         004d4f8e     CALL       ResourceItem::setAllValues                       void setAllValues(ResourceItem * this, int pa
    //                              taibldmd.cpp:971 (6)
    //         004d4f93     MOV        ESI,dword ptr [EDI + 0x15c]
    //                              taibldmd.cpp:974 (30)
    //         004d4f99     LEA        EAX,[EDI + 0xf0]
    //         004d4f9f     CMP        ESI,EAX
    //         004d4fa1     MOV        dword ptr [ESP + param_1],0x0
    //         004d4fa9     JZ         LAB_004d507d
    //                               LAB_004d4faf                                                 XREF[1]:     004d5077(j)  
    //         004d4faf     TEST       ESI,ESI
    //         004d4fb1     JZ         LAB_004d507d
    //                              taibldmd.cpp:982 (46)
    //         004d4fb7     MOV        this,ESI
    //         004d4fb9     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d4fbe     TEST       EAX,EAX
    //         004d4fc0     JNZ        LAB_004d506c
    //         004d4fc6     MOV        this,ESI
    //         004d4fc8     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d4fcd     TEST       EAX,EAX
    //         004d4fcf     JNZ        LAB_004d506c
    //         004d4fd5     MOV        this,ESI
    //         004d4fd7     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d4fdc     CMP        EAX,0x6
    //         004d4fdf     JZ         LAB_004d506c
    //                              taibldmd.cpp:984 (30)
    //         004d4fe5     MOV        this,ESI
    //         004d4fe7     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
    //         004d4fec     CMP        EAX,-0x1
    //         004d4fef     JZ         LAB_004d5005
    //         004d4ff1     MOV        this,ESI
    //         004d4ff3     CALL       BuildItem::numberBuilds                          int numberBuilds(BuildItem * this)
    //         004d4ff8     MOV        this,ESI
    //         004d4ffa     MOV        EBP,EAX
    //         004d4ffc     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
    //         004d5001     CMP        EBP,EAX
    //                              taibldmd.cpp:989 (2)
    //         004d5003     JG         LAB_004d506c
    //                               LAB_004d5005                                                 XREF[1]:     004d4fef(j)  
    //                              taibldmd.cpp:997 (24)
    //         004d5005     MOV        this,ESI
    //         004d5007     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d500c     CMP        EAX,0x1
    //         004d500f     JZ         LAB_004d503d
    //         004d5011     MOV        this,ESI
    //         004d5013     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d5018     CMP        EAX,0x4
    //         004d501b     JZ         LAB_004d503d
    //                              taibldmd.cpp:1000 (32)
    //         004d501d     PUSH       0x1
    //         004d501f     PUSH       EBX
    //         004d5020     PUSH       -0x1
    //         004d5022     MOV        this,ESI
    //         004d5024     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5029     PUSH       EAX
    //         004d502a     MOV        EAX,dword ptr [EDI + 0x5bc]
    //         004d5030     MOV        this,dword ptr [EAX + 0x1256c]
    //         004d5036     CALL       TRIBE_Player::objectCost                         void objectCost(TRIBE_Player * this, int para
    //         004d503b     JMP        LAB_004d505b
    //                               LAB_004d503d                                                 XREF[2]:     004d500f(j), 004d501b(j)  
    //                              taibldmd.cpp:998 (30)
    //         004d503d     PUSH       0x1
    //         004d503f     PUSH       EBX
    //         004d5040     PUSH       -0x1
    //         004d5042     MOV        this,ESI
    //         004d5044     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5049     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d504f     PUSH       EAX
    //         004d5050     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d5056     CALL       TRIBE_Player::researchCost                       void researchCost(TRIBE_Player * this, int pa
    //                               LAB_004d505b                                                 XREF[1]:     004d503b(j)  
    //                              taibldmd.cpp:1011 (4)
    //         004d505b     MOV        EAX,dword ptr [ESP + param_1]
    //                              taibldmd.cpp:1012 (13)
    //         004d505f     MOV        this,dword ptr [ESP + param_2]
    //         004d5063     INC        EAX
    //         004d5064     CMP        EAX,this
    //         004d5066     MOV        dword ptr [ESP + param_1],EAX
    //         004d506a     JZ         LAB_004d507d
    //                               LAB_004d506c                                                 XREF[4]:     004d4fc0(j), 004d4fcf(j), 
    //                                                                                                         004d4fdf(j), 004d5003(j)  
    //                              taibldmd.cpp:1015 (17)
    //         004d506c     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d506f     LEA        EAX,[EDI + 0xf0]
    //         004d5075     CMP        ESI,EAX
    //         004d5077     JNZ        LAB_004d4faf
    //                               LAB_004d507d                                                 XREF[3]:     004d4fa9(j), 004d4fb1(j), 
    //                                                                                                         004d506a(j)  
    //                              taibldmd.cpp:1025 (4)
    //         004d507d     MOV        EAX,dword ptr [ESP + param_1]
    //                              taibldmd.cpp:1026 (7)
    //         004d5081     POP        EDI
    //         004d5082     POP        ESI
    //         004d5083     POP        EBP
    //         004d5084     POP        EBX
    //         004d5085     RET        0x8
}

// Offset: 0x004D5090
int addItem(TribeBuildAIModule* this_, RGE_Static_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::addItem(class RGE_Static_Object *,int)                     *
    //                              *********************************************************************************************************
    //                              int __thiscall addItem(TribeBuildAIModule * this, RGE_Static_Object 
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d5096(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d50c4(R)  
    //                               ?addItem@TribeBuildAIModule@@QAEHPAVRGE_Static_Object@@H@Z   XREF[2]:     updateBuildAIWithObjects:004e61fe(
    //                               TribeBuildAIModule::addItem                                               addObject:005150cc(c)  
    //                              taibldmd.cpp:1032 (6)
    //         004d5090     PUSH       EBX
    //         004d5091     PUSH       EBP
    //         004d5092     MOV        EBP,this
    //         004d5094     PUSH       ESI
    //         004d5095     PUSH       EDI
    //                              taibldmd.cpp:1041 (26)
    //         004d5096     MOV        EDI,dword ptr [ESP + param_1]
    //         004d509a     MOV        this,dword ptr [EBP + 0x5bc]
    //         004d50a0     PUSH       EDI
    //         004d50a1     ADD        this,0xcec
    //         004d50a7     CALL       TribeInformationAIModule::isBuilding             int isBuilding(TribeInformationAIModule * thi
    //         004d50ac     TEST       EAX,EAX
    //         004d50ae     JZ         LAB_004d50c4
    //                              taibldmd.cpp:1042 (20)
    //         004d50b0     MOV        this,dword ptr [EBP + 0x5bc]
    //         004d50b6     PUSH       0x1
    //         004d50b8     PUSH       EDI
    //         004d50b9     ADD        this,0x6c4
    //         004d50bf     CALL       TribeConstructionAIModule::setBuilt              void setBuilt(TribeConstructionAIModule * thi
    //                               LAB_004d50c4                                                 XREF[1]:     004d50ae(j)  
    //                              taibldmd.cpp:1046 (12)
    //         004d50c4     MOV        EAX,dword ptr [ESP + param_2]
    //         004d50c8     TEST       EAX,EAX
    //         004d50ca     JNZ        LAB_004d515f
    //                              taibldmd.cpp:1051 (6)
    //         004d50d0     MOV        ESI,dword ptr [EBP + 0x15c]
    //                              taibldmd.cpp:1052 (14)
    //         004d50d6     LEA        EBX,[EBP + 0xf0]
    //         004d50dc     CMP        ESI,EBX
    //         004d50de     JZ         LAB_004d515f
    //                               LAB_004d50e0                                                 XREF[1]:     004d5106(j)  
    //         004d50e0     TEST       ESI,ESI
    //         004d50e2     JZ         LAB_004d515f
    //                              taibldmd.cpp:1058 (29)
    //         004d50e4     MOV        this,ESI
    //         004d50e6     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d50eb     MOV        this,dword ptr [EDI + 0x8]
    //         004d50ee     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004d50f2     CMP        EAX,EDX
    //         004d50f4     JNZ        LAB_004d5101
    //         004d50f6     MOV        this,ESI
    //         004d50f8     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d50fd     TEST       EAX,EAX
    //         004d50ff     JZ         LAB_004d5111
    //                               LAB_004d5101                                                 XREF[1]:     004d50f4(j)  
    //                              taibldmd.cpp:1081 (7)
    //         004d5101     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d5104     CMP        ESI,EBX
    //         004d5106     JNZ        LAB_004d50e0
    //                              taibldmd.cpp:1087 (2)
    //         004d5108     XOR        EAX,EAX
    //                              taibldmd.cpp:1088 (7)
    //         004d510a     POP        EDI
    //         004d510b     POP        ESI
    //         004d510c     POP        EBP
    //         004d510d     POP        EBX
    //         004d510e     RET        0x8
    //                               LAB_004d5111                                                 XREF[1]:     004d50ff(j)  
    //                              taibldmd.cpp:1060 (11)
    //         004d5111     MOV        EAX,dword ptr [EDI + 0x4]
    //         004d5114     MOV        this,ESI
    //         004d5116     PUSH       EAX
    //         004d5117     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
    //                              taibldmd.cpp:1065 (9)
    //         004d511c     PUSH       0x0
    //         004d511e     MOV        this,ESI
    //         004d5120     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1066 (9)
    //         004d5125     PUSH       0x1
    //         004d5127     MOV        this,ESI
    //         004d5129     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:1067 (7)
    //         004d512e     MOV        this,ESI
    //         004d5130     CALL       BuildItem::incrementNumberBuilds                 void incrementNumberBuilds(BuildItem * this)
    //                              taibldmd.cpp:1070 (14)
    //         004d5135     MOV        this,ESI
    //         004d5137     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d513c     CMP        EAX,0x114
    //         004d5141     JNZ        LAB_004d5153
    //                              taibldmd.cpp:1071 (16)
    //         004d5143     MOV        this,dword ptr [EBP + 0x5bc]
    //         004d5149     MOV        dword ptr [this->_padding_ + 0x122b4],0x1
    //                               LAB_004d5153                                                 XREF[1]:     004d5141(j)  
    //                              taibldmd.cpp:1079 (5)
    //         004d5153     MOV        EAX,0x1
    //                              taibldmd.cpp:1088 (16)
    //         004d5158     POP        EDI
    //         004d5159     POP        ESI
    //         004d515a     POP        EBP
    //         004d515b     POP        EBX
    //         004d515c     RET        0x8
    //                               LAB_004d515f                                                 XREF[3]:     004d50ca(j), 004d50de(j), 
    //                                                                                                         004d50e2(j)  
    //         004d515f     POP        EDI
    //         004d5160     POP        ESI
    //         004d5161     POP        EBP
    //         004d5162     XOR        EAX,EAX
    //         004d5164     POP        EBX
    //         004d5165     RET        0x8
}

// Offset: 0x004D5170
int addBuiltItem(TribeBuildAIModule* this_, RGE_Static_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::addBuiltItem(class RGE_Static_Object *,int)                *
    //                              *********************************************************************************************************
    //                              int __thiscall addBuiltItem(TribeBuildAIModule * this, RGE_Static_Ob
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d518c(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     004d51c1(R), 004d51cf(R)  
    //                               ?addBuiltItem@TribeBuildAIModule@@QAEHPAVRGE_Static_Object@  XREF[1]:     registerBuild:005151da(c)  
    //                               TribeBuildAIModule::addBuiltItem
    //                              taibldmd.cpp:1093 (6)
    //         004d5170     PUSH       EBX
    //         004d5171     PUSH       EBP
    //         004d5172     PUSH       ESI
    //         004d5173     PUSH       EDI
    //         004d5174     MOV        EDI,this
    //                              taibldmd.cpp:1103 (8)
    //         004d5176     XOR        EBX,EBX
    //         004d5178     MOV        ESI,dword ptr [EDI + 0x15c]
    //                              taibldmd.cpp:1107 (34)
    //         004d517e     LEA        EAX,[EDI + 0xf0]
    //         004d5184     CMP        ESI,EAX
    //         004d5186     JZ         LAB_004d524f
    //         004d518c     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_004d5190                                                 XREF[1]:     004d5249(j)  
    //         004d5190     TEST       ESI,ESI
    //         004d5192     JZ         LAB_004d524f
    //         004d5198     TEST       EBX,EBX
    //         004d519a     JNZ        LAB_004d524f
    //                              taibldmd.cpp:1117 (53)
    //         004d51a0     MOV        this,ESI
    //         004d51a2     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d51a7     MOV        this,dword ptr [EBP + 0x8]
    //         004d51aa     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004d51ae     CMP        EAX,EDX
    //         004d51b0     JNZ        LAB_004d523e
    //         004d51b6     MOV        this,ESI
    //         004d51b8     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d51bd     TEST       EAX,EAX
    //         004d51bf     JNZ        LAB_004d523e
    //         004d51c1     CMP        dword ptr [ESP + param_2],-0x1
    //         004d51c6     JZ         LAB_004d523e
    //         004d51c8     MOV        this,ESI
    //         004d51ca     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d51cf     CMP        EAX,dword ptr [ESP + param_2]
    //         004d51d3     JNZ        LAB_004d523e
    //                              taibldmd.cpp:1118 (8)
    //         004d51d5     PUSH       EBX
    //         004d51d6     MOV        this,ESI
    //         004d51d8     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1119 (13)
    //         004d51dd     MOV        EBX,0x1
    //         004d51e2     MOV        this,ESI
    //         004d51e4     PUSH       EBX
    //         004d51e5     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:1120 (11)
    //         004d51ea     MOV        EAX,dword ptr [EBP + 0x4]
    //         004d51ed     MOV        this,ESI
    //         004d51ef     PUSH       EAX
    //         004d51f0     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
    //                              taibldmd.cpp:1121 (7)
    //         004d51f5     MOV        this,ESI
    //         004d51f7     CALL       BuildItem::incrementNumberBuilds                 void incrementNumberBuilds(BuildItem * this)
    //                              taibldmd.cpp:1124 (14)
    //         004d51fc     MOV        this,ESI
    //         004d51fe     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5203     CMP        EAX,0x114
    //         004d5208     JNZ        LAB_004d5216
    //                              taibldmd.cpp:1125 (12)
    //         004d520a     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d5210     MOV        dword ptr [this->_padding_ + 0x122b4],EBX
    //                               LAB_004d5216                                                 XREF[1]:     004d5208(j)  
    //                              taibldmd.cpp:1127 (25)
    //         004d5216     PUSH       0x3f
    //         004d5218     MOV        this,ESI
    //         004d521a     CALL       BaseItem::name                                   char * name(BaseItem * this)
    //         004d521f     LEA        EDX,[EDI + 0x2a5]
    //         004d5225     PUSH       EAX
    //         004d5226     PUSH       EDX
    //         004d5227     CALL       strncpy                                          undefined strncpy()
    //         004d522c     ADD        ESP,0xc
    //                              taibldmd.cpp:1128 (13)
    //         004d522f     MOV        this,ESI
    //         004d5231     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d5236     MOV        dword ptr [EDI + 0x5a8],EAX
    //                              taibldmd.cpp:1137 (2)
    //         004d523c     JMP        LAB_004d5241
    //                               LAB_004d523e                                                 XREF[4]:     004d51b0(j), 004d51bf(j), 
    //                                                                                                         004d51c6(j), 004d51d3(j)  
    //                              taibldmd.cpp:1138 (3)
    //         004d523e     MOV        ESI,dword ptr [ESI + 0x6c]
    //                               LAB_004d5241                                                 XREF[1]:     004d523c(j)  
    //                              taibldmd.cpp:1107 (14)
    //         004d5241     LEA        EAX,[EDI + 0xf0]
    //         004d5247     CMP        ESI,EAX
    //         004d5249     JNZ        LAB_004d5190
    //                               LAB_004d524f                                                 XREF[3]:     004d5186(j), 004d5192(j), 
    //                                                                                                         004d519a(j)  
    //                              taibldmd.cpp:1145 (17)
    //         004d524f     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d5255     ADD        this,0x1146c
    //         004d525b     CALL       TribeTacticalAIModule::updateNeededResources     void updateNeededResources(TribeTacticalAIMod
    //                              taibldmd.cpp:1147 (12)
    //         004d5260     POP        EDI
    //         004d5261     POP        ESI
    //         004d5262     POP        EBP
    //         004d5263     MOV        EAX,0x1
    //         004d5268     POP        EBX
    //         004d5269     RET        0x8
}

// Offset: 0x004D5270
int removeBuiltItem(TribeBuildAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::removeBuiltItem(int)                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall removeBuiltItem(TribeBuildAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5297(R)  
    //                               ?removeBuiltItem@TribeBuildAIModule@@QAEHH@Z                 XREF[1]:     removeObject:004e5ffb(c)  
    //                               TribeBuildAIModule::removeBuiltItem
    //                              taibldmd.cpp:1152 (5)
    //         004d5270     PUSH       EBX
    //         004d5271     MOV        EBX,this
    //         004d5273     PUSH       EBP
    //         004d5274     PUSH       ESI
    //                              taibldmd.cpp:1158 (7)
    //         004d5275     MOV        ESI,dword ptr [EBX + 0x15c]
    //         004d527b     PUSH       EDI
    //                              taibldmd.cpp:1160 (20)
    //         004d527c     LEA        EBP,[EBX + 0xf0]
    //         004d5282     XOR        EDI,EDI
    //         004d5284     CMP        ESI,EBP
    //         004d5286     JZ         LAB_004d52f2
    //                               LAB_004d5288                                                 XREF[1]:     004d52f0(j)  
    //         004d5288     TEST       ESI,ESI
    //         004d528a     JZ         LAB_004d52f2
    //         004d528c     TEST       EDI,EDI
    //         004d528e     JNZ        LAB_004d52f2
    //                              taibldmd.cpp:1161 (25)
    //         004d5290     MOV        this,ESI
    //         004d5292     CALL       BaseItem::gameID                                 int gameID(BaseItem * this)
    //         004d5297     CMP        EAX,dword ptr [ESP + param_1]
    //         004d529b     JNZ        LAB_004d52eb
    //         004d529d     MOV        this,ESI
    //         004d529f     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d52a4     CMP        EAX,0x1
    //         004d52a7     JNZ        LAB_004d52eb
    //                              taibldmd.cpp:1162 (8)
    //         004d52a9     PUSH       EDI
    //         004d52aa     MOV        this,ESI
    //         004d52ac     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1163 (8)
    //         004d52b1     PUSH       EDI
    //         004d52b2     MOV        this,ESI
    //         004d52b4     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:1164 (9)
    //         004d52b9     PUSH       -0x1
    //         004d52bb     MOV        this,ESI
    //         004d52bd     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
    //                              taibldmd.cpp:1165 (8)
    //         004d52c2     PUSH       EDI
    //         004d52c3     MOV        this,ESI
    //         004d52c5     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                              taibldmd.cpp:1171 (14)
    //         004d52ca     MOV        this,ESI
    //         004d52cc     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d52d1     CMP        EAX,0x114
    //         004d52d6     JNZ        LAB_004d52e4
    //                              taibldmd.cpp:1172 (12)
    //         004d52d8     MOV        EAX,dword ptr [EBX + 0x5bc]
    //         004d52de     MOV        dword ptr [EAX + 0x122b4],EDI
    //                               LAB_004d52e4                                                 XREF[1]:     004d52d6(j)  
    //                              taibldmd.cpp:1173 (5)
    //         004d52e4     MOV        EDI,0x1
    //                              taibldmd.cpp:1175 (2)
    //         004d52e9     JMP        LAB_004d52ee
    //                               LAB_004d52eb                                                 XREF[2]:     004d529b(j), 004d52a7(j)  
    //                              taibldmd.cpp:1176 (3)
    //         004d52eb     MOV        ESI,dword ptr [ESI + 0x6c]
    //                               LAB_004d52ee                                                 XREF[1]:     004d52e9(j)  
    //                              taibldmd.cpp:1160 (4)
    //         004d52ee     CMP        ESI,EBP
    //         004d52f0     JNZ        LAB_004d5288
    //                               LAB_004d52f2                                                 XREF[3]:     004d5286(j), 004d528a(j), 
    //                                                                                                         004d528e(j)  
    //                              taibldmd.cpp:1187 (17)
    //         004d52f2     MOV        this,dword ptr [EBX + 0x5bc]
    //         004d52f8     ADD        this,0x1146c
    //         004d52fe     CALL       TribeTacticalAIModule::updateNeededResources     void updateNeededResources(TribeTacticalAIMod
    //                              taibldmd.cpp:1189 (12)
    //         004d5303     POP        EDI
    //         004d5304     POP        ESI
    //         004d5305     POP        EBP
    //         004d5306     MOV        EAX,0x1
    //         004d530b     POP        EBX
    //         004d530c     RET        0x4
}

// Offset: 0x004D5310
int cancelBuildItem(TribeBuildAIModule* this_, int param_2, int param_3, int param_4, float param_5, float param_6, int param_7, int param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::cancelBuildItem(int,int,int,float,float,int,int)           *
    //                              *********************************************************************************************************
    //                              int __thiscall cancelBuildItem(TribeBuildAIModule * this, int param_
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[9]:     004d532c(R), 004d53d3(W), 004d53e7(R), 004d53f3(W), 
    //                                                                                     004d5407(R), 004d5413(W), 004d5427(R), 004d5433(W), 
    //                                                                                     004d5455(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[4]:     004d536e(R), 004d5397(R), 004d544a(R), 004d548b(R)  
    //              int               Stack[0xc]:4   param_3
    //              float             Stack[0x10]:4  param_4                   XREF[3]:     004d5382(R), 004d546e(R), 004d5492(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[3]:     004d537e(R), 004d5464(R), 004d5478(R)  
    //              int               Stack[0x18]:4  param_6
    //              int               Stack[0x1c]:4  param_7                   XREF[6]:     004d5311(R), 004d5333(W), 004d5348(W), 004d535e(W), 
    //                                                                                     004d5364(W), 004d54e5(R)  
    //              undefined1        Stack[-0x4]:1  local_4                   XREF[2]:     004d533a(W), 004d5352(W)  
    //              uchar             Stack[-0x8]:1  newLotStatus
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     004d53eb(*), 004d548f(*)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     004d540b(*), 004d54a5(*)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     004d542b(*), 004d54ab(*)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[2]:     004d5459(*), 004d54af(*)  
    //                               ?cancelBuildItem@TribeBuildAIModule@@QAEHHHHMMHH@Z           XREF[1]:     cancelBuild:005151b3(c)  
    //                               TribeBuildAIModule::cancelBuildItem
    //                              taibldmd.cpp:1195 (1)
    //         004d5310     PUSH       this
    //                              taibldmd.cpp:1219 (15)
    //         004d5311     MOV        EAX,dword ptr [ESP + param_7]
    //         004d5315     PUSH       EBX
    //         004d5316     PUSH       EBP
    //         004d5317     PUSH       ESI
    //         004d5318     CMP        EAX,-0x1
    //         004d531b     PUSH       EDI
    //         004d531c     MOV        ESI,this
    //         004d531e     JZ         LAB_004d532c
    //                              taibldmd.cpp:1223 (12)
    //         004d5320     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d5326     PUSH       EAX
    //         004d5327     CALL       TribeMainDecisionAIModule::detask                void detask(TribeMainDecisionAIModule * this,
    //                               LAB_004d532c                                                 XREF[1]:     004d531e(j)  
    //                              taibldmd.cpp:1231 (28)
    //         004d532c     MOV        EAX,dword ptr [ESP + param_1]
    //         004d5330     XOR        EDI,EDI
    //         004d5332     INC        EAX
    //         004d5333     MOV        dword ptr [ESP + param_7],EDI
    //         004d5337     CMP        EAX,0x9
    //         004d533a     MOV        byte ptr [ESP + local_4],0x2
    //         004d533f     JA         switchD_004d5341::caseD_0
    //                               switchD_004d5341::switchD
    //         004d5341     JMP        dword ptr [EAX*0x4 + switchD_004d5341::switchd   = 004d5348
    //                               switchD_004d5341::caseD_ffffffff                             XREF[2]:     004d5341(j), 004d5568(*)  
    //                              taibldmd.cpp:1233 (8)
    //         004d5348     MOV        dword ptr [ESP + param_7],0x1
    //                              taibldmd.cpp:1234 (2)
    //         004d5350     XOR        EDI,EDI
    //                              taibldmd.cpp:1238 (5)
    //         004d5352     MOV        byte ptr [ESP + local_4],0x0
    //                              taibldmd.cpp:1239 (2)
    //         004d5357     JMP        switchD_004d5341::caseD_1
    //                               switchD_004d5341::caseD_8                                    XREF[2]:     004d5341(j), 004d558c(*)  
    //                              taibldmd.cpp:1271 (5)
    //         004d5359     MOV        EDI,0x1
    //                              taibldmd.cpp:1272 (4)
    //         004d535e     MOV        dword ptr [ESP + param_7],EDI
    //                              taibldmd.cpp:1278 (2)
    //         004d5362     JMP        switchD_004d5341::caseD_1
    //                               switchD_004d5341::caseD_0                                    XREF[3]:     004d533f(j), 004d5341(j), 
    //                                                                                                         004d556c(*)  
    //                              taibldmd.cpp:1285 (8)
    //         004d5364     MOV        dword ptr [ESP + param_7],0x1
    //                              taibldmd.cpp:1286 (2)
    //         004d536c     XOR        EDI,EDI
    //                               switchD_004d5341::caseD_2                                    XREF[10]:    004d5341(j), 004d5357(j), 
    //                               switchD_004d5341::caseD_3                                                 004d5362(j), 004d5570(*), 
    //                               switchD_004d5341::caseD_4                                                 004d5574(*), 004d5578(*), 
    //                               switchD_004d5341::caseD_5                                                 004d557c(*), 004d5580(*), 
    //                               switchD_004d5341::caseD_6                                                 004d5584(*), 004d5588(*)  
    //                               switchD_004d5341::caseD_7
    //                               switchD_004d5341::caseD_1
    //                              taibldmd.cpp:1295 (16)
    //         004d536e     MOV        this,dword ptr [ESP + param_2]
    //         004d5372     PUSH       this
    //         004d5373     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d5379     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
    //                              taibldmd.cpp:1301 (25)
    //         004d537e     MOV        EBP,dword ptr [ESP + param_5]
    //         004d5382     MOV        EBX,dword ptr [ESP + param_4]
    //         004d5386     TEST       EAX,EAX
    //         004d5388     JZ         LAB_004d54d3
    //         004d538e     CMP        EDI,0x1
    //         004d5391     JNZ        LAB_004d54d3
    //                              taibldmd.cpp:1305 (16)
    //         004d5397     MOV        EDX,dword ptr [ESP + param_2]
    //         004d539b     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d53a1     PUSH       EDX
    //         004d53a2     CALL       TribeMainDecisionAIModule::isMoveable            int isMoveable(TribeMainDecisionAIModule * th
    //                              taibldmd.cpp:1307 (8)
    //         004d53a7     CMP        EAX,EDI
    //         004d53a9     JNZ        LAB_004d54ba
    //                              taibldmd.cpp:1315 (21)
    //         004d53af     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d53b5     PUSH       EBP
    //         004d53b6     PUSH       EBX
    //         004d53b7     ADD        this,0x6c4
    //         004d53bd     CALL       ConstructionAIModule::lot                        ConstructionItem * lot(ConstructionAIModule *
    //         004d53c2     MOV        EDI,EAX
    //                              taibldmd.cpp:1318 (8)
    //         004d53c4     TEST       EDI,EDI
    //         004d53c6     JZ         LAB_004d5464
    //                              taibldmd.cpp:1323 (150)
    //         004d53cc     MOV        this,EDI
    //         004d53ce     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         004d53d3     FSTP       float ptr [ESP + param_1]
    //         004d53d7     MOV        this,EDI
    //         004d53d9     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
    //         004d53de     FMUL       float ptr [DAT_0057548c]                         = align(3)
    //         004d53e4     PUSH       this
    //         004d53e5     MOV        this,EDI
    //         004d53e7     FSUBR      float ptr [ESP + param_1]
    //         004d53eb     FSTP       float ptr [ESP]=>local_18
    //         004d53ee     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         004d53f3     FSTP       float ptr [ESP + param_1]
    //         004d53f7     MOV        this,EDI
    //         004d53f9     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
    //         004d53fe     FMUL       float ptr [DAT_0057548c]                         = align(3)
    //         004d5404     PUSH       this
    //         004d5405     MOV        this,EDI
    //         004d5407     FSUBR      float ptr [ESP + param_1]
    //         004d540b     FSTP       float ptr [ESP]=>local_1c
    //         004d540e     CALL       BaseItem::y                                      float y(BaseItem * this)
    //         004d5413     FSTP       float ptr [ESP + param_1]
    //         004d5417     MOV        this,EDI
    //         004d5419     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
    //         004d541e     FMUL       float ptr [DAT_00575490]
    //         004d5424     PUSH       this
    //         004d5425     MOV        this,EDI
    //         004d5427     FSUBR      float ptr [ESP + param_1]
    //         004d542b     FSTP       float ptr [ESP]=>local_20
    //         004d542e     CALL       BaseItem::x                                      float x(BaseItem * this)
    //         004d5433     FSTP       float ptr [ESP + param_1]
    //         004d5437     MOV        this,EDI
    //         004d5439     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
    //         004d543e     FMUL       float ptr [DAT_00575490]
    //         004d5444     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d544a     MOV        EAX,dword ptr [ESP + param_2]
    //         004d544e     PUSH       this
    //         004d544f     ADD        this,0x1146c
    //         004d5455     FSUBR      float ptr [ESP + param_1]
    //         004d5459     FSTP       float ptr [ESP]=>local_24
    //         004d545c     PUSH       EAX
    //         004d545d     CALL       TribeTacticalAIModule::clearArea                 int clearArea(TribeTacticalAIModule * this, i
    //                              taibldmd.cpp:1324 (2)
    //         004d5462     JMP        LAB_004d54d3
    //                               LAB_004d5464                                                 XREF[1]:     004d53c6(j)  
    //                              taibldmd.cpp:1327 (84)
    //         004d5464     FLD        float ptr [ESP + param_5]
    //         004d5468     FSUB       float ptr [DAT_00575494]
    //         004d546e     FLD        float ptr [ESP + param_4]
    //         004d5472     FSUB       float ptr [DAT_00575494]
    //         004d5478     FLD        float ptr [ESP + param_5]
    //         004d547c     FSUB       float ptr [DAT_00575498]
    //         004d5482     FXCH       ST2
    //         004d5484     PUSH       this
    //         004d5485     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d548b     MOV        EDX,dword ptr [ESP + param_2]
    //         004d548f     FSTP       float ptr [ESP]=>local_18
    //         004d5492     FLD        float ptr [ESP + param_4]
    //         004d5496     FSUB       float ptr [DAT_00575498]
    //         004d549c     FXCH
    //         004d549e     PUSH       this
    //         004d549f     ADD        this,0x1146c
    //         004d54a5     FSTP       float ptr [ESP]=>local_1c
    //         004d54a8     PUSH       this
    //         004d54a9     FXCH
    //         004d54ab     FSTP       float ptr [ESP]=>local_20
    //         004d54ae     PUSH       this
    //         004d54af     FSTP       float ptr [ESP]=>local_24
    //         004d54b2     PUSH       EDX
    //         004d54b3     CALL       TribeTacticalAIModule::clearArea                 int clearArea(TribeTacticalAIModule * this, i
    //                              taibldmd.cpp:1329 (2)
    //         004d54b8     JMP        LAB_004d54d3
    //                               LAB_004d54ba                                                 XREF[1]:     004d53a9(j)  
    //                              taibldmd.cpp:1337 (25)
    //         004d54ba     MOV        EAX,dword ptr [ESI + 0x5bc]
    //         004d54c0     PUSH       0xa
    //         004d54c2     PUSH       EBP
    //         004d54c3     PUSH       EBX
    //         004d54c4     LEA        this,[EAX + 0x6c4]
    //         004d54ca     MOV        EAX,dword ptr [EAX + 0x6c4]
    //         004d54d0     CALL       dword ptr [EAX + 0x58]
    //                               LAB_004d54d3                                                 XREF[4]:     004d5388(j), 004d5391(j), 
    //                                                                                                         004d5462(j), 004d54b8(j)  
    //                              taibldmd.cpp:1349 (28)
    //         004d54d3     MOV        EAX,dword ptr [ESI + 0x5bc]
    //         004d54d9     MOV        EDX,dword ptr [EAX + 0x6c4]
    //         004d54df     LEA        this,[EAX + 0x6c4]
    //         004d54e5     MOV        EAX,dword ptr [ESP + param_7]
    //         004d54e9     PUSH       EAX
    //         004d54ea     PUSH       EBP=>DAT_fffffff8
    //         004d54eb     PUSH       EBX=>DAT_fffffff4
    //         004d54ec     CALL       dword ptr [EDX + 0x4c]
    //                              taibldmd.cpp:1356 (14)
    //         004d54ef     MOV        this,dword ptr [ESP + 0x2c]
    //         004d54f3     PUSH       this
    //         004d54f4     MOV        this,ESI
    //         004d54f6     CALL       BuildAIModule::specificBuildListItem             BuildItem * specificBuildListItem(BuildAIModu
    //         004d54fb     MOV        EDI,EAX
    //                              taibldmd.cpp:1357 (4)
    //         004d54fd     TEST       EDI,EDI
    //         004d54ff     JZ         LAB_004d555a
    //                              taibldmd.cpp:1358 (9)
    //         004d5501     PUSH       0x0
    //         004d5503     MOV        this,EDI
    //         004d5505     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1361 (50)
    //         004d550a     MOV        EDX,dword ptr [ESP + 0x10]
    //         004d550e     FLD        float ptr [ESP + 0x28]
    //         004d5512     PUSH       EDX
    //         004d5513     CALL       __ftol                                           undefined __ftol()
    //         004d5518     FLD        float ptr [ESP + 0x28]
    //         004d551c     PUSH       EAX=>DAT_fffffff8
    //         004d551d     CALL       __ftol                                           undefined __ftol()
    //         004d5522     PUSH       EAX=>DAT_fffffff4
    //         004d5523     MOV        this,EDI
    //         004d5525     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d552a     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d5530     PUSH       EAX=>DAT_fffffff0
    //         004d5531     ADD        this,0xcec
    //         004d5537     CALL       TribeInformationAIModule::removeLot              void removeLot(TribeInformationAIModule * thi
    //                              taibldmd.cpp:1364 (14)
    //         004d553c     MOV        this,EDI
    //         004d553e     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5543     CMP        EAX,0x114
    //         004d5548     JNZ        LAB_004d555a
    //                              taibldmd.cpp:1365 (16)
    //         004d554a     MOV        EAX,dword ptr [ESI + 0x5bc]
    //         004d5550     MOV        dword ptr [EAX + 0x122b0],0x0
    //                               LAB_004d555a                                                 XREF[2]:     004d54ff(j), 004d5548(j)  
    //                              taibldmd.cpp:1368 (54)
    //         004d555a     POP        EDI
    //         004d555b     POP        ESI
    //         004d555c     POP        EBP
    //         004d555d     MOV        EAX,0x1
    //         004d5562     POP        EBX
    //         004d5563     POP        this
    //         004d5564     RET        0x1c
}

// Offset: 0x004D5590
int addTrainedUnit(TribeBuildAIModule* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::addTrainedUnit(int,int,int,int)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall addTrainedUnit(TribeBuildAIModule * this, int param_1
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d55c9(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d5590(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004d55b6(R)  
    //                               ?addTrainedUnit@TribeBuildAIModule@@QAEHHHHH@Z               XREF[1]:     registerTrain:00515274(c)  
    //                               TribeBuildAIModule::addTrainedUnit
    //                              taibldmd.cpp:1374 (16)
    //         004d5590     MOV        EAX,dword ptr [ESP + param_3]
    //         004d5594     PUSH       ESI
    //         004d5595     PUSH       EDI
    //         004d5596     MOV        EDI,this
    //         004d5598     PUSH       EAX
    //         004d5599     CALL       BuildAIModule::specificBuildListItem             BuildItem * specificBuildListItem(BuildAIModu
    //         004d559e     MOV        ESI,EAX
    //                              taibldmd.cpp:1382 (4)
    //         004d55a0     TEST       ESI,ESI
    //         004d55a2     JZ         LAB_004d55c9
    //                              taibldmd.cpp:1383 (9)
    //         004d55a4     PUSH       0x0
    //         004d55a6     MOV        this,ESI
    //         004d55a8     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1384 (9)
    //         004d55ad     PUSH       0x1
    //         004d55af     MOV        this,ESI
    //         004d55b1     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:1385 (12)
    //         004d55b6     MOV        this,dword ptr [ESP + param_4]
    //         004d55ba     PUSH       this
    //         004d55bb     MOV        this,ESI
    //         004d55bd     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
    //                              taibldmd.cpp:1386 (7)
    //         004d55c2     MOV        this,ESI
    //         004d55c4     CALL       BuildItem::incrementNumberBuilds                 void incrementNumberBuilds(BuildItem * this)
    //                               LAB_004d55c9                                                 XREF[1]:     004d55a2(j)  
    //                              taibldmd.cpp:1395 (16)
    //         004d55c9     MOV        EDX,dword ptr [ESP + param_2]
    //         004d55cd     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d55d3     PUSH       EDX
    //         004d55d4     CALL       TribeMainDecisionAIModule::detask                void detask(TribeMainDecisionAIModule * this,
    //                              taibldmd.cpp:1397 (17)
    //         004d55d9     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d55df     ADD        this,0x1146c
    //         004d55e5     CALL       TribeTacticalAIModule::updateNeededResources     void updateNeededResources(TribeTacticalAIMod
    //                              taibldmd.cpp:1399 (10)
    //         004d55ea     POP        EDI
    //         004d55eb     MOV        EAX,0x1
    //         004d55f0     POP        ESI
    //         004d55f1     RET        0x10
}

// Offset: 0x004D5600
int cancelTrainUnit(TribeBuildAIModule* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::cancelTrainUnit(int,int,int,int)                           *
    //                              *********************************************************************************************************
    //                              int __thiscall cancelTrainUnit(TribeBuildAIModule * this, int param_
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5608(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d5600(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004d562c(R)  
    //                               ?cancelTrainUnit@TribeBuildAIModule@@QAEHHHHH@Z              XREF[1]:     cancelTrain:00515244(c)  
    //                               TribeBuildAIModule::cancelTrainUnit
    //                              taibldmd.cpp:1405 (44)
    //         004d5600     MOV        EAX,dword ptr [ESP + param_3]
    //         004d5604     PUSH       ESI
    //         004d5605     MOV        ESI,this
    //         004d5607     PUSH       EDI
    //         004d5608     MOV        this,dword ptr [ESP + param_2]
    //         004d560c     PUSH       EAX
    //         004d560d     MOV        EDX,dword ptr [ESI + 0x5bc]
    //         004d5613     PUSH       this
    //         004d5614     MOV        EAX,dword ptr [EDX + 0xf0]
    //         004d561a     MOV        this,dword ptr [EAX + 0x3c]
    //         004d561d     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004d5620     PUSH       EDX
    //         004d5621     PUSH       s_Canceling_training_(WT=%ld)_for_               = "Canceling training (WT=%ld) for item of ty
    //         004d5626     PUSH       ESI
    //         004d5627     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              taibldmd.cpp:1416 (17)
    //         004d562c     MOV        EAX,dword ptr [ESP + param_4]
    //         004d5630     ADD        ESP,0x14
    //         004d5633     MOV        this,ESI
    //         004d5635     PUSH       EAX
    //         004d5636     CALL       BuildAIModule::specificBuildListItem             BuildItem * specificBuildListItem(BuildAIModu
    //         004d563b     MOV        EDI,EAX
    //                              taibldmd.cpp:1417 (4)
    //         004d563d     TEST       EDI,EDI
    //         004d563f     JZ         LAB_004d5671
    //                              taibldmd.cpp:1419 (22)
    //         004d5641     MOV        this,EDI
    //         004d5643     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d5648     PUSH       EAX
    //         004d5649     PUSH       s___Setting_build_item_#%d_in_prog               = "  Setting build item #%d in progress to FA
    //         004d564e     PUSH       ESI
    //         004d564f     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004d5654     ADD        ESP,0xc
    //                              taibldmd.cpp:1421 (9)
    //         004d5657     MOV        this,EDI
    //         004d5659     PUSH       0x0
    //         004d565b     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1429 (7)
    //         004d5660     MOV        EDX,dword ptr [ESI]
    //         004d5662     MOV        this,ESI
    //         004d5664     CALL       dword ptr [EDX + 0x40]
    //                              taibldmd.cpp:1431 (5)
    //         004d5667     MOV        EAX,0x1
    //                              taibldmd.cpp:1432 (5)
    //         004d566c     POP        EDI
    //         004d566d     POP        ESI
    //         004d566e     RET        0x10
    //                               LAB_004d5671                                                 XREF[1]:     004d563f(j)  
    //                              taibldmd.cpp:1425 (11)
    //         004d5671     PUSH       s___ERROR!__Invalid_build_item.                  = "  ERROR!  Invalid build item."
    //         004d5676     PUSH       ESI
    //         004d5677     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              taibldmd.cpp:1429 (10)
    //         004d567c     MOV        EDX,dword ptr [ESI]
    //         004d567e     ADD        ESP,0x8
    //         004d5681     MOV        this,ESI
    //         004d5683     CALL       dword ptr [EDX + 0x40]
    //                              taibldmd.cpp:1432 (10)
    //         004d5686     POP        EDI
    //         004d5687     MOV        EAX,0x1
    //         004d568c     POP        ESI
    //         004d568d     RET        0x10
}

// Offset: 0x004D5690
int addResearch(TribeBuildAIModule* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::addResearch(int,int,int)                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall addResearch(TribeBuildAIModule * this, int param_1, i
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d56bd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d5690(R)  
    //                               ?addResearch@TribeBuildAIModule@@QAEHHHH@Z                   XREF[1]:     registerResearch:005152ff(c)  
    //                               TribeBuildAIModule::addResearch
    //                              taibldmd.cpp:1437 (16)
    //         004d5690     MOV        EAX,dword ptr [ESP + param_3]
    //         004d5694     PUSH       ESI
    //         004d5695     PUSH       EDI
    //         004d5696     MOV        EDI,this
    //         004d5698     PUSH       EAX
    //         004d5699     CALL       BuildAIModule::specificBuildListItem             BuildItem * specificBuildListItem(BuildAIModu
    //         004d569e     MOV        ESI,EAX
    //                              taibldmd.cpp:1445 (4)
    //         004d56a0     TEST       ESI,ESI
    //         004d56a2     JZ         LAB_004d56bd
    //                              taibldmd.cpp:1446 (9)
    //         004d56a4     PUSH       0x0
    //         004d56a6     MOV        this,ESI
    //         004d56a8     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1447 (9)
    //         004d56ad     PUSH       0x1
    //         004d56af     MOV        this,ESI
    //         004d56b1     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
    //                              taibldmd.cpp:1448 (7)
    //         004d56b6     MOV        this,ESI
    //         004d56b8     CALL       BuildItem::incrementNumberBuilds                 void incrementNumberBuilds(BuildItem * this)
    //                               LAB_004d56bd                                                 XREF[1]:     004d56a2(j)  
    //                              taibldmd.cpp:1452 (16)
    //         004d56bd     MOV        this,dword ptr [ESP + param_2]
    //         004d56c1     PUSH       this
    //         004d56c2     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d56c8     CALL       TribeMainDecisionAIModule::detask                void detask(TribeMainDecisionAIModule * this,
    //                              taibldmd.cpp:1454 (17)
    //         004d56cd     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d56d3     ADD        this,0x1146c
    //         004d56d9     CALL       TribeTacticalAIModule::updateNeededResources     void updateNeededResources(TribeTacticalAIMod
    //                              taibldmd.cpp:1456 (10)
    //         004d56de     POP        EDI
    //         004d56df     MOV        EAX,0x1
    //         004d56e4     POP        ESI
    //         004d56e5     RET        0xc
}

// Offset: 0x004D56F0
int cancelResearch(TribeBuildAIModule* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::cancelResearch(int,int,int,int)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall cancelResearch(TribeBuildAIModule * this, int param_1
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d56f8(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d56f0(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004d571c(R)  
    //                               ?cancelResearch@TribeBuildAIModule@@QAEHHHHH@Z               XREF[1]:     cancelResearch:005152d4(c)  
    //                               TribeBuildAIModule::cancelResearch
    //                              taibldmd.cpp:1462 (44)
    //         004d56f0     MOV        EAX,dword ptr [ESP + param_3]
    //         004d56f4     PUSH       ESI
    //         004d56f5     MOV        ESI,this
    //         004d56f7     PUSH       EDI
    //         004d56f8     MOV        this,dword ptr [ESP + param_2]
    //         004d56fc     PUSH       EAX
    //         004d56fd     MOV        EDX,dword ptr [ESI + 0x5bc]
    //         004d5703     PUSH       this
    //         004d5704     MOV        EAX,dword ptr [EDX + 0xf0]
    //         004d570a     MOV        this,dword ptr [EAX + 0x3c]
    //         004d570d     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004d5710     PUSH       EDX
    //         004d5711     PUSH       s_Canceling_research_(WT=%ld)_for_               = "Canceling research (WT=%ld) for item of ty
    //         004d5716     PUSH       ESI
    //         004d5717     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              taibldmd.cpp:1473 (17)
    //         004d571c     MOV        EAX,dword ptr [ESP + param_4]
    //         004d5720     ADD        ESP,0x14
    //         004d5723     MOV        this,ESI
    //         004d5725     PUSH       EAX
    //         004d5726     CALL       BuildAIModule::specificBuildListItem             BuildItem * specificBuildListItem(BuildAIModu
    //         004d572b     MOV        EDI,EAX
    //                              taibldmd.cpp:1474 (4)
    //         004d572d     TEST       EDI,EDI
    //         004d572f     JZ         LAB_004d5761
    //                              taibldmd.cpp:1476 (22)
    //         004d5731     MOV        this,EDI
    //         004d5733     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
    //         004d5738     PUSH       EAX
    //         004d5739     PUSH       s___Setting_build_item_#%d_in_prog               = "  Setting build item #%d in progress to FA
    //         004d573e     PUSH       ESI
    //         004d573f     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004d5744     ADD        ESP,0xc
    //                              taibldmd.cpp:1478 (9)
    //         004d5747     MOV        this,EDI
    //         004d5749     PUSH       0x0
    //         004d574b     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
    //                              taibldmd.cpp:1486 (7)
    //         004d5750     MOV        EDX,dword ptr [ESI]
    //         004d5752     MOV        this,ESI
    //         004d5754     CALL       dword ptr [EDX + 0x40]
    //                              taibldmd.cpp:1488 (5)
    //         004d5757     MOV        EAX,0x1
    //                              taibldmd.cpp:1489 (5)
    //         004d575c     POP        EDI
    //         004d575d     POP        ESI
    //         004d575e     RET        0x10
    //                               LAB_004d5761                                                 XREF[1]:     004d572f(j)  
    //                              taibldmd.cpp:1482 (11)
    //         004d5761     PUSH       s___ERROR!__Invalid_build_item.                  = "  ERROR!  Invalid build item."
    //         004d5766     PUSH       ESI
    //         004d5767     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              taibldmd.cpp:1486 (10)
    //         004d576c     MOV        EDX,dword ptr [ESI]
    //         004d576e     ADD        ESP,0x8
    //         004d5771     MOV        this,ESI
    //         004d5773     CALL       dword ptr [EDX + 0x40]
    //                              taibldmd.cpp:1489 (10)
    //         004d5776     POP        EDI
    //         004d5777     MOV        EAX,0x1
    //         004d577c     POP        ESI
    //         004d577d     RET        0x10
}

// Offset: 0x004D5780
int isAgeResearch(TribeBuildAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::isAgeResearch(int)                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall isAgeResearch(TribeBuildAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5780(R)  
    //                               ?isAgeResearch@TribeBuildAIModule@@QAEHH@Z                   XREF[1]:     nextBuildableItem:004d45e8(c)  
    //                               TribeBuildAIModule::isAgeResearch
    //                              taibldmd.cpp:1494 (19)
    //         004d5780     MOV        EAX,dword ptr [ESP + param_1]
    //         004d5784     CMP        EAX,0x65
    //         004d5787     JZ         LAB_004d5798
    //         004d5789     CMP        EAX,0x66
    //         004d578c     JZ         LAB_004d5798
    //         004d578e     CMP        EAX,0x67
    //         004d5791     JZ         LAB_004d5798
    //                              taibldmd.cpp:1499 (2)
    //         004d5793     XOR        EAX,EAX
    //                              taibldmd.cpp:1500 (3)
    //         004d5795     RET        0x4
    //                               LAB_004d5798                                                 XREF[3]:     004d5787(j), 004d578c(j), 
    //                                                                                                         004d5791(j)  
    //                              taibldmd.cpp:1498 (5)
    //         004d5798     MOV        EAX,0x1
    //                              taibldmd.cpp:1500 (3)
    //         004d579d     RET        0x4
}

// Offset: 0x004D57A0
int insert(TribeBuildAIModule* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::insert(int,int,int)                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall insert(TribeBuildAIModule * this, int param_1, int pa
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004d57a3(R), 004d58d6(R), 004d58f2(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     004d58f6(R), 004d592a(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d58b9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d57b0(W), 004d5900(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[11]:    004d581a(W), 004d582c(W), 004d585c(W), 004d586b(W), 
    //                                                                                     004d5877(W), 004d5886(W), 004d5895(W), 004d58a4(W), 
    //                                                                                     004d58b1(W), 004d58fa(R), 004d5925(R)  
    //              int               Stack[-0xc]:4  buildCategory
    //                               ?insert@TribeBuildAIModule@@QAEHHHH@Z                        XREF[14]:    initialize:004d3fa5(c), 
    //                               TribeBuildAIModule::insert                                                initialize:004d403c(c), 
    //                                                                                                         initialize:004d40f6(c), 
    //                                                                                                         initialize:004d4276(c), 
    //                                                                                                         kick:004e5f68(c), 
    //                                                                                                         evaluateBuildListInsertions:004f60
    //                                                                                                         evaluateBuildListInsertions:004f60
    //                                                                                                         evaluateBuildListInsertions:004f60
    //                                                                                                         taskGatherer:004fa553(c), 
    //                                                                                                         checkForBuildInsertion:00501ed9(c)
    //                                                                                                         checkForBuildInsertion:00501f6b(c)
    //                                                                                                         checkForBuildInsertion:0050206f(c)
    //                                                                                                         checkForAttackResponseBuildInserti
    //                                                                                                         FUN_005024b3:00502563(c)  
    //                              taibldmd.cpp:1505 (3)
    //         004d57a0     SUB        ESP,0x8
    //                              taibldmd.cpp:1511 (35)
    //         004d57a3     MOV        EAX,dword ptr [ESP + param_1]
    //         004d57a7     PUSH       EBX
    //         004d57a8     PUSH       EBP
    //         004d57a9     MOV        EBX,this
    //         004d57ab     PUSH       ESI
    //         004d57ac     CMP        EAX,0xb
    //         004d57af     PUSH       EDI
    //         004d57b0     MOV        dword ptr [ESP + local_4],EBX
    //         004d57b4     JG         LAB_004d57d2
    //         004d57b6     JZ         switchD_004d580e::caseD_23
    //         004d57b8     CMP        EAX,0x4
    //         004d57bb     JL         switchD_004d57e5::caseD_e
    //         004d57c1     CMP        EAX,0x5
    //         004d57c4     JLE        switchD_004d580e::caseD_27
    //                              taibldmd.cpp:1578 (2)
    //         004d57c6     XOR        EAX,EAX
    //                              taibldmd.cpp:1600 (10)
    //         004d57c8     POP        EDI
    //         004d57c9     POP        ESI
    //         004d57ca     POP        EBP
    //         004d57cb     POP        EBX
    //         004d57cc     ADD        ESP,0x8
    //         004d57cf     RET        0xc
    //                               LAB_004d57d2                                                 XREF[1]:     004d57b4(j)  
    //                              taibldmd.cpp:1511 (67)
    //         004d57d2     CMP        EAX,0x19
    //         004d57d5     JG         LAB_004d57ec
    //         004d57d7     JZ         switchD_004d580e::caseD_27
    //         004d57d9     LEA        this,[EAX + -0xd]
    //         004d57dc     CMP        this,0x6
    //         004d57df     JA         switchD_004d57e5::caseD_e
    //                               switchD_004d57e5::switchD
    //         004d57e5     JMP        dword ptr [this->_padding_*0x4 + switchD_004d5   = 004d589f
    //                               LAB_004d57ec                                                 XREF[1]:     004d57d5(j)  
    //         004d57ec     CMP        EAX,0x46
    //         004d57ef     JG         LAB_004d5839
    //         004d57f1     CMP        EAX,0x44
    //         004d57f4     JGE        switchD_004d580e::caseD_2d
    //         004d57fa     LEA        this,[EAX + -0x23]
    //         004d57fd     CMP        this,0xf
    //         004d5800     JA         switchD_004d57e5::caseD_e
    //         004d5806     XOR        EDX,EDX
    //         004d5808     MOV        DL,byte ptr [this->_padding_ + 0x4d59a0]=>swit
    //                               switchD_004d580e::switchD
    //         004d580e     JMP        dword ptr [EDX*0x4 + switchD_004d580e::switchd   = 004d5827
    //                               switchD_004d580e::caseD_29                                   XREF[5]:     004d57c4(j), 004d57d7(j), 
    //                               switchD_004d580e::caseD_27                                                004d580e(j), 004d5984(*), 
    //                                                                                                         004d598c(*)  
    //                              taibldmd.cpp:1526 (5)
    //         004d5815     MOV        EBP,0x57
    //                              taibldmd.cpp:1527 (8)
    //         004d581a     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1528 (5)
    //         004d5822     JMP        LAB_004d58b9
    //                               switchD_004d580e::caseD_24                                   XREF[3]:     004d57b6(j), 004d580e(j), 
    //                               switchD_004d580e::caseD_23                                                004d597c(*)  
    //                              taibldmd.cpp:1532 (5)
    //         004d5827     MOV        EBP,0x31
    //                              taibldmd.cpp:1533 (8)
    //         004d582c     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1534 (5)
    //         004d5834     JMP        LAB_004d58b9
    //                               LAB_004d5839                                                 XREF[1]:     004d57ef(j)  
    //                              taibldmd.cpp:1511 (30)
    //         004d5839     LEA        this,[EAX + -0x49]
    //         004d583c     CMP        this,0xe2
    //         004d5842     JA         switchD_004d57e5::caseD_e
    //         004d5848     XOR        EDX,EDX
    //         004d584a     MOV        DL,byte ptr [this->_padding_ + 0x4d59e4]=>PTR_
    //                               switchD_004d5850::switchD
    //         004d5850     JMP        dword ptr [EDX*0x4 + switchD_004d5850::switchd   = 004d5866
    //                               switchD_004d5850::caseD_53                                   XREF[2]:     004d5850(j), 004d59bc(*)  
    //                              taibldmd.cpp:1513 (5)
    //         004d5857     MOV        EBP,0x6d
    //                              taibldmd.cpp:1514 (8)
    //         004d585c     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1515 (2)
    //         004d5864     JMP        LAB_004d58b9
    //                               switchD_004d5850::caseD_4b                                   XREF[3]:     004d5850(j), 004d59b0(*), 
    //                               switchD_004d5850::caseD_49                                                004d59b4(*)  
    //                              taibldmd.cpp:1518 (5)
    //         004d5866     MOV        EBP,0xc
    //                              taibldmd.cpp:1519 (8)
    //         004d586b     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1520 (2)
    //         004d5873     JMP        LAB_004d58b9
    //                               switchD_004d5850::caseD_5d                                   XREF[2]:     004d5850(j), 004d59c0(*)  
    //                              taibldmd.cpp:1536 (2)
    //         004d5875     XOR        EBP,EBP
    //                              taibldmd.cpp:1537 (8)
    //         004d5877     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1538 (2)
    //         004d587f     JMP        LAB_004d58b9
    //                               switchD_004d5850::caseD_7d                                   XREF[2]:     004d5850(j), 004d59c8(*)  
    //                              taibldmd.cpp:1540 (5)
    //         004d5881     MOV        EBP,0x68
    //                              taibldmd.cpp:1541 (8)
    //         004d5886     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1542 (2)
    //         004d588e     JMP        LAB_004d58b9
    //                               switchD_004d580e::caseD_28                                   XREF[6]:     004d580e(j), 004d5850(j), 
    //                               switchD_004d580e::caseD_2e                                                004d5980(*), 004d5988(*), 
    //                               switchD_004d5850::caseD_12b                                               004d5994(*), 004d59dc(*)  
    //                               switchD_004d580e::caseD_25
    //                              taibldmd.cpp:1547 (5)
    //         004d5890     MOV        EBP,0x65
    //                              taibldmd.cpp:1548 (8)
    //         004d5895     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1549 (2)
    //         004d589d     JMP        LAB_004d58b9
    //                               switchD_004d57e5::caseD_f                                    XREF[8]:     004d57e5(j), 004d5850(j), 
    //                               switchD_004d57e5::caseD_11                                                004d5960(*), 004d5968(*), 
    //                               switchD_004d57e5::caseD_12                                                004d5970(*), 004d5974(*), 
    //                               switchD_004d57e5::caseD_13                                                004d5978(*), 004d59d0(*)  
    //                               switchD_004d5850::caseD_fa
    //                               switchD_004d57e5::caseD_d
    //                              taibldmd.cpp:1556 (5)
    //         004d589f     MOV        EBP,0x2d
    //                              taibldmd.cpp:1557 (8)
    //         004d58a4     MOV        dword ptr [ESP + local_8],0x2
    //                              taibldmd.cpp:1558 (2)
    //         004d58ac     JMP        LAB_004d58b9
    //                               switchD_004d580e::caseD_31                                   XREF[10]:    004d57f4(j), 004d580e(j), 
    //                               switchD_004d580e::caseD_32                                                004d5850(j), 004d5990(*), 
    //                               switchD_004d5850::caseD_4f                                                004d5998(*), 004d59b8(*), 
    //                               switchD_004d5850::caseD_67                                                004d59c4(*), 004d59cc(*), 
    //                               switchD_004d5850::caseD_c7                                                004d59d4(*), 004d59d8(*)  
    //                               switchD_004d5850::caseD_114
    //                               switchD_004d5850::caseD_116
    //                               switchD_004d580e::caseD_2d
    //                              taibldmd.cpp:1571 (3)
    //         004d58ae     OR         EBP,0xffffffff
    //                              taibldmd.cpp:1572 (8)
    //         004d58b1     MOV        dword ptr [ESP + local_8],0x0
    //                               LAB_004d58b9                                                 XREF[8]:     004d5822(j), 004d5834(j), 
    //                                                                                                         004d5864(j), 004d5873(j), 
    //                                                                                                         004d587f(j), 004d588e(j), 
    //                                                                                                         004d589d(j), 004d58ac(j)  
    //                              taibldmd.cpp:1581 (9)
    //         004d58b9     MOV        this,dword ptr [ESP + param_3]
    //         004d58bd     CMP        this,-0x1
    //         004d58c0     JNZ        LAB_004d5925
    //                              taibldmd.cpp:1583 (6)
    //         004d58c2     MOV        ESI,dword ptr [EBX + 0x15c]
    //                              taibldmd.cpp:1584 (22)
    //         004d58c8     ADD        EBX,0xf0
    //         004d58ce     XOR        EDI,EDI
    //         004d58d0     CMP        ESI,EBX
    //         004d58d2     JZ         LAB_004d58f6
    //         004d58d4     JMP        LAB_004d58da
    //                               LAB_004d58d6                                                 XREF[1]:     004d58f0(j)  
    //         004d58d6     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_004d58da                                                 XREF[1]:     004d58d4(j)  
    //         004d58da     TEST       ESI,ESI
    //         004d58dc     JZ         LAB_004d58f6
    //                              taibldmd.cpp:1585 (12)
    //         004d58de     MOV        this,ESI
    //         004d58e0     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d58e5     CMP        EAX,0x1
    //         004d58e8     JNZ        LAB_004d58f2
    //                              taibldmd.cpp:1589 (8)
    //         004d58ea     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d58ed     INC        EDI
    //         004d58ee     CMP        ESI,EBX
    //         004d58f0     JNZ        LAB_004d58d6
    //                               LAB_004d58f2                                                 XREF[1]:     004d58e8(j)  
    //                              taibldmd.cpp:1584 (4)
    //         004d58f2     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_004d58f6                                                 XREF[2]:     004d58d2(j), 004d58dc(j)  
    //                              taibldmd.cpp:1594 (37)
    //         004d58f6     MOV        this,dword ptr [ESP + param_2]
    //         004d58fa     MOV        EDX,dword ptr [ESP + local_8]
    //         004d58fe     PUSH       EDI
    //         004d58ff     PUSH       this
    //         004d5900     MOV        this,dword ptr [ESP + local_4]
    //         004d5904     PUSH       EBP
    //         004d5905     PUSH       EDX
    //         004d5906     PUSH       0x1
    //         004d5908     PUSH       EAX
    //         004d5909     MOV        EAX,dword ptr [ECX + this->md]
    //         004d590f     MOV        EDX,dword ptr [EAX + 0xf0]
    //         004d5915     PUSH       EDX
    //         004d5916     CALL       BuildAIModule::insertItem                        int insertItem(BuildAIModule * this, RGE_Play
    //                              taibldmd.cpp:1600 (10)
    //         004d591b     POP        EDI
    //         004d591c     POP        ESI
    //         004d591d     POP        EBP
    //         004d591e     POP        EBX
    //         004d591f     ADD        ESP,0x8
    //         004d5922     RET        0xc
    //                               LAB_004d5925                                                 XREF[1]:     004d58c0(j)  
    //                              taibldmd.cpp:1599 (35)
    //         004d5925     MOV        EDX,dword ptr [ESP + local_8]
    //         004d5929     PUSH       this
    //         004d592a     MOV        this,dword ptr [ESP + param_2]
    //         004d592e     PUSH       this
    //         004d592f     PUSH       EBP
    //         004d5930     PUSH       EDX
    //         004d5931     PUSH       0x1
    //         004d5933     PUSH       EAX
    //         004d5934     MOV        EAX,dword ptr [EBX + 0x5bc]
    //         004d593a     MOV        this,dword ptr [EAX + 0xf0]
    //         004d5940     PUSH       this
    //         004d5941     MOV        this,EBX
    //         004d5943     CALL       BuildAIModule::insertItem                        int insertItem(BuildAIModule * this, RGE_Play
    //                              taibldmd.cpp:1600 (383)
    //         004d5948     POP        EDI
    //         004d5949     POP        ESI
    //         004d594a     POP        EBP
    //         004d594b     POP        EBX
    //         004d594c     ADD        ESP,0x8
    //         004d594f     RET        0xc
    //                               switchD_004d57e5::caseD_10                                   XREF[11]:    004d57bb(j), 004d57df(j), 
    //                               switchD_004d580e::caseD_26                                                004d57e5(j), 004d5800(j), 
    //                               switchD_004d580e::caseD_2a                                                004d580e(j), 004d5842(j), 
    //                               switchD_004d580e::caseD_2b                                                004d5850(j), 004d5964(*), 
    //                               switchD_004d580e::caseD_2c                                                004d596c(*), 004d599c(*), 
    //                               switchD_004d580e::caseD_2f                                                004d59e0(*)  
    //                               switchD_004d580e::caseD_30
    //                               switchD_004d5850::caseD_4a
    //                               switchD_004d5850::caseD_4c
    //                               switchD_004d5850::caseD_4d
    //                               switchD_004d5850::caseD_4e
    //                               switchD_004d5850::caseD_50
    //                               switchD_004d5850::caseD_51
    //                               switchD_004d5850::caseD_52
    //                               switchD_004d5850::caseD_54
    //                               switchD_004d5850::caseD_55
    //                               switchD_004d5850::caseD_56
    //                               switchD_004d5850::caseD_57
    //                               switchD_004d5850::caseD_58
    //                               switchD_004d5850::caseD_59
    //                               switchD_004d5850::caseD_5a
    //                               switchD_004d5850::caseD_5b
    //                               switchD_004d5850::caseD_5c
    //                               switchD_004d5850::caseD_5e
    //                               switchD_004d5850::caseD_5f
    //                               switchD_004d5850::caseD_60
    //                               switchD_004d5850::caseD_61
    //                               switchD_004d5850::caseD_62
    //                               switchD_004d5850::caseD_63
    //                               switchD_004d5850::caseD_64
    //                               switchD_004d5850::caseD_65
    //                               switchD_004d5850::caseD_66
    //                               switchD_004d5850::caseD_68
    //                               switchD_004d5850::caseD_69
    //                               switchD_004d5850::caseD_6a
    //                               switchD_004d5850::caseD_6b
    //                               switchD_004d5850::caseD_6c
    //                               switchD_004d5850::caseD_6d
    //                               switchD_004d5850::caseD_6e
    //                               switchD_004d5850::caseD_6f
    //                               switchD_004d5850::caseD_70
    //                               switchD_004d5850::caseD_71
    //                               switchD_004d5850::caseD_72
    //                               switchD_004d5850::caseD_73
    //                               switchD_004d5850::caseD_74
    //                               switchD_004d5850::caseD_75
    //                               switchD_004d5850::caseD_76
    //                               switchD_004d5850::caseD_77
    //                               switchD_004d5850::caseD_78
    //                               switchD_004d5850::caseD_79
    //                               switchD_004d5850::caseD_7a
    //                               switchD_004d5850::caseD_7b
    //                               switchD_004d5850::caseD_7c
    //                               switchD_004d5850::caseD_7e
    //                               switchD_004d5850::caseD_7f
    //                               switchD_004d5850::caseD_80
    //                               switchD_004d5850::caseD_81
    //                               switchD_004d5850::caseD_82
    //                               switchD_004d5850::caseD_83
    //                               switchD_004d5850::caseD_84
    //                               switchD_004d5850::caseD_85
    //                               switchD_004d5850::caseD_86
    //                               switchD_004d5850::caseD_87
    //                               switchD_004d5850::caseD_88
    //                               switchD_004d5850::caseD_89
    //                               switchD_004d5850::caseD_8a
    //                               switchD_004d5850::caseD_8b
    //                               switchD_004d5850::caseD_8c
    //                               switchD_004d5850::caseD_8d
    //                               switchD_004d5850::caseD_8e
    //                               switchD_004d5850::caseD_8f
    //                               switchD_004d5850::caseD_90
    //                               switchD_004d5850::caseD_91
    //                               switchD_004d5850::caseD_92
    //                               switchD_004d5850::caseD_93
    //                               switchD_004d5850::caseD_94
    //                               switchD_004d5850::caseD_95
    //                               switchD_004d5850::caseD_96
    //                               switchD_004d5850::caseD_97
    //                               switchD_004d5850::caseD_98
    //                               switchD_004d5850::caseD_99
    //                               switchD_004d5850::caseD_9a
    //                               switchD_004d5850::caseD_9b
    //                               switchD_004d5850::caseD_9c
    //                               switchD_004d5850::caseD_9d
    //                               switchD_004d5850::caseD_9e
    //                               switchD_004d5850::caseD_9f
    //                               switchD_004d5850::caseD_a0
    //                               switchD_004d5850::caseD_a1
    //                               switchD_004d5850::caseD_a2
    //                               switchD_004d5850::caseD_a3
    //                               switchD_004d5850::caseD_a4
    //                               switchD_004d5850::caseD_a5
    //                               switchD_004d5850::caseD_a6
    //                               switchD_004d5850::caseD_a7
    //                               switchD_004d5850::caseD_a8
    //                               switchD_004d5850::caseD_a9
    //                               switchD_004d5850::caseD_aa
    //                               switchD_004d5850::caseD_ab
    //                               switchD_004d5850::caseD_ac
    //                               switchD_004d5850::caseD_ad
    //                               switchD_004d5850::caseD_ae
    //                               switchD_004d5850::caseD_af
    //                               switchD_004d5850::caseD_b0
    //                               switchD_004d5850::caseD_b1
    //                               switchD_004d5850::caseD_b2
    //                               switchD_004d5850::caseD_b3
    //                               switchD_004d5850::caseD_b4
    //                               switchD_004d5850::caseD_b5
    //                               switchD_004d5850::caseD_b6
    //                               switchD_004d5850::caseD_b7
    //                               switchD_004d5850::caseD_b8
    //                               switchD_004d5850::caseD_b9
    //                               switchD_004d5850::caseD_ba
    //                               switchD_004d5850::caseD_bb
    //                               switchD_004d5850::caseD_bc
    //                               switchD_004d5850::caseD_bd
    //                               switchD_004d5850::caseD_be
    //                               switchD_004d5850::caseD_bf
    //                               switchD_004d5850::caseD_c0
    //                               switchD_004d5850::caseD_c1
    //                               switchD_004d5850::caseD_c2
    //                               switchD_004d5850::caseD_c3
    //                               switchD_004d5850::caseD_c4
    //                               switchD_004d5850::caseD_c5
    //                               switchD_004d5850::caseD_c6
    //                               switchD_004d5850::caseD_c8
    //                               switchD_004d5850::caseD_c9
    //                               switchD_004d5850::caseD_ca
    //                               switchD_004d5850::caseD_cb
    //                               switchD_004d5850::caseD_cc
    //                               switchD_004d5850::caseD_cd
    //                               switchD_004d5850::caseD_ce
    //                               switchD_004d5850::caseD_cf
    //                               switchD_004d5850::caseD_d0
    //                               switchD_004d5850::caseD_d1
    //                               switchD_004d5850::caseD_d2
    //                               switchD_004d5850::caseD_d3
    //                               switchD_004d5850::caseD_d4
    //                               switchD_004d5850::caseD_d5
    //                               switchD_004d5850::caseD_d6
    //                               switchD_004d5850::caseD_d7
    //                               switchD_004d5850::caseD_d8
    //                               switchD_004d5850::caseD_d9
    //                               switchD_004d5850::caseD_da
    //                               switchD_004d5850::caseD_db
    //                               switchD_004d5850::caseD_dc
    //                               switchD_004d5850::caseD_dd
    //                               switchD_004d5850::caseD_de
    //                               switchD_004d5850::caseD_df
    //                               switchD_004d5850::caseD_e0
    //                               switchD_004d5850::caseD_e1
    //                               switchD_004d5850::caseD_e2
    //                               switchD_004d5850::caseD_e3
    //                               switchD_004d5850::caseD_e4
    //                               switchD_004d5850::caseD_e5
    //                               switchD_004d5850::caseD_e6
    //                               switchD_004d5850::caseD_e7
    //                               switchD_004d5850::caseD_e8
    //                               switchD_004d5850::caseD_e9
    //                               switchD_004d5850::caseD_ea
    //                               switchD_004d5850::caseD_eb
    //                               switchD_004d5850::caseD_ec
    //                               switchD_004d5850::caseD_ed
    //                               switchD_004d5850::caseD_ee
    //                               switchD_004d5850::caseD_ef
    //                               switchD_004d5850::caseD_f0
    //                               switchD_004d5850::caseD_f1
    //                               switchD_004d5850::caseD_f2
    //                               switchD_004d5850::caseD_f3
    //                               switchD_004d5850::caseD_f4
    //                               switchD_004d5850::caseD_f5
    //                               switchD_004d5850::caseD_f6
    //                               switchD_004d5850::caseD_f7
    //                               switchD_004d5850::caseD_f8
    //                               switchD_004d5850::caseD_f9
    //                               switchD_004d5850::caseD_fb
    //                               switchD_004d5850::caseD_fc
    //                               switchD_004d5850::caseD_fd
    //                               switchD_004d5850::caseD_fe
    //                               switchD_004d5850::caseD_ff
    //                               switchD_004d5850::caseD_100
    //                               switchD_004d5850::caseD_101
    //                               switchD_004d5850::caseD_102
    //                               switchD_004d5850::caseD_103
    //                               switchD_004d5850::caseD_104
    //                               switchD_004d5850::caseD_105
    //                               switchD_004d5850::caseD_106
    //                               switchD_004d5850::caseD_107
    //                               switchD_004d5850::caseD_108
    //                               switchD_004d5850::caseD_109
    //                               switchD_004d5850::caseD_10a
    //                               switchD_004d5850::caseD_10b
    //                               switchD_004d5850::caseD_10c
    //                               switchD_004d5850::caseD_10d
    //                               switchD_004d5850::caseD_10e
    //                               switchD_004d5850::caseD_10f
    //                               switchD_004d5850::caseD_110
    //                               switchD_004d5850::caseD_111
    //                               switchD_004d5850::caseD_112
    //                               switchD_004d5850::caseD_113
    //                               switchD_004d5850::caseD_115
    //                               switchD_004d5850::caseD_117
    //                               switchD_004d5850::caseD_118
    //                               switchD_004d5850::caseD_119
    //                               switchD_004d5850::caseD_11a
    //                               switchD_004d5850::caseD_11b
    //                               switchD_004d5850::caseD_11c
    //                               switchD_004d5850::caseD_11d
    //                               switchD_004d5850::caseD_11e
    //                               switchD_004d5850::caseD_11f
    //                               switchD_004d5850::caseD_120
    //                               switchD_004d5850::caseD_121
    //                               switchD_004d5850::caseD_122
    //                               switchD_004d5850::caseD_123
    //                               switchD_004d5850::caseD_124
    //                               switchD_004d5850::caseD_125
    //                               switchD_004d5850::caseD_126
    //                               switchD_004d5850::caseD_127
    //                               switchD_004d5850::caseD_128
    //                               switchD_004d5850::caseD_129
    //                               switchD_004d5850::caseD_12a
    //                               switchD_004d57e5::caseD_e
    //         004d5952     POP        EDI
    //         004d5953     POP        ESI
    //         004d5954     POP        EBP
    //         004d5955     XOR        EAX,EAX
    //         004d5957     POP        EBX
    //         004d5958     ADD        ESP,0x8
    //         004d595b     RET        0xc
}

// Offset: 0x004D595E
undefined FUN_004d595e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004d595e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004d595e
    //         004d595e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004d57e5::switchdataD_004d5960                       XREF[1]:     insert:004d57e5(*)  
}

// Offset: 0x004D5AD0
int insertResearch(TribeBuildAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::insertResearch(int,int)                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall insertResearch(TribeBuildAIModule * this, int param_1
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     004d5ad3(R), 004d5b2b(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5af2(R)  
    //                               ?insertResearch@TribeBuildAIModule@@QAEHHH@Z                 XREF[4]:     initialize:004d4119(c), 
    //                               TribeBuildAIModule::insertResearch                                        initialize:004d41a6(c), 
    //                                                                                                         initialize:004d41cd(c), 
    //                                                                                                         initialize:004d41e7(c)  
    //                              taibldmd.cpp:1605 (3)
    //         004d5ad0     PUSH       EBX
    //         004d5ad1     MOV        EBX,this
    //                              taibldmd.cpp:1610 (22)
    //         004d5ad3     MOV        this,dword ptr [ESP + param_1]
    //         004d5ad7     PUSH       EBP
    //         004d5ad8     PUSH       ESI
    //         004d5ad9     CMP        this,0x5
    //         004d5adc     PUSH       EDI
    //         004d5add     JZ         LAB_004d5af2
    //         004d5adf     CMP        this,0x6
    //         004d5ae2     JLE        LAB_004d5ae9
    //         004d5ae4     CMP        this,0x8
    //         004d5ae7     JLE        LAB_004d5af2
    //                               LAB_004d5ae9                                                 XREF[1]:     004d5ae2(j)  
    //                              taibldmd.cpp:1620 (2)
    //         004d5ae9     XOR        EAX,EAX
    //                              taibldmd.cpp:1642 (7)
    //         004d5aeb     POP        EDI
    //         004d5aec     POP        ESI
    //         004d5aed     POP        EBP
    //         004d5aee     POP        EBX
    //         004d5aef     RET        0x8
    //                               LAB_004d5af2                                                 XREF[2]:     004d5add(j), 004d5ae7(j)  
    //                              taibldmd.cpp:1623 (9)
    //         004d5af2     MOV        EAX,dword ptr [ESP + param_2]
    //         004d5af6     CMP        EAX,-0x1
    //         004d5af9     JNZ        LAB_004d5b4e
    //                              taibldmd.cpp:1625 (6)
    //         004d5afb     MOV        ESI,dword ptr [EBX + 0x15c]
    //                              taibldmd.cpp:1626 (16)
    //         004d5b01     LEA        EDI,[EBX + 0xf0]
    //         004d5b07     XOR        EBP,EBP
    //         004d5b09     CMP        ESI,EDI
    //         004d5b0b     JZ         LAB_004d5b25
    //                               LAB_004d5b0d                                                 XREF[1]:     004d5b23(j)  
    //         004d5b0d     TEST       ESI,ESI
    //         004d5b0f     JZ         LAB_004d5b25
    //                              taibldmd.cpp:1627 (12)
    //         004d5b11     MOV        this,ESI
    //         004d5b13     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d5b18     CMP        EAX,0x1
    //         004d5b1b     JNZ        LAB_004d5b25
    //                              taibldmd.cpp:1631 (8)
    //         004d5b1d     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d5b20     INC        EBP
    //         004d5b21     CMP        ESI,EDI
    //         004d5b23     JNZ        LAB_004d5b0d
    //                               LAB_004d5b25                                                 XREF[3]:     004d5b0b(j), 004d5b0f(j), 
    //                                                                                                         004d5b1b(j)  
    //                              taibldmd.cpp:1636 (27)
    //         004d5b25     MOV        this,dword ptr [EBX + 0x5bc]
    //         004d5b2b     MOV        EAX,dword ptr [ESP + param_1]
    //         004d5b2f     PUSH       EBP
    //         004d5b30     PUSH       0x1
    //         004d5b32     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004d5b38     PUSH       0x2d
    //         004d5b3a     PUSH       0x1
    //         004d5b3c     PUSH       0x1
    //         004d5b3e     PUSH       EAX
    //         004d5b3f     PUSH       EDX
    //                              taibldmd.cpp:1641 (7)
    //         004d5b40     MOV        this,EBX
    //         004d5b42     CALL       BuildAIModule::insertItem                        int insertItem(BuildAIModule * this, RGE_Play
    //                              taibldmd.cpp:1642 (7)
    //         004d5b47     POP        EDI
    //         004d5b48     POP        ESI
    //         004d5b49     POP        EBP
    //         004d5b4a     POP        EBX
    //         004d5b4b     RET        0x8
    //                               LAB_004d5b4e                                                 XREF[1]:     004d5af9(j)  
    //                              taibldmd.cpp:1641 (30)
    //         004d5b4e     PUSH       EAX
    //         004d5b4f     MOV        EAX,dword ptr [EBX + 0x5bc]
    //         004d5b55     PUSH       0x1
    //         004d5b57     PUSH       0x2d
    //         004d5b59     PUSH       0x1
    //         004d5b5b     PUSH       0x1
    //         004d5b5d     PUSH       this
    //         004d5b5e     MOV        this,dword ptr [EAX + 0xf0]
    //         004d5b64     PUSH       this
    //         004d5b65     MOV        this,EBX
    //         004d5b67     CALL       BuildAIModule::insertItem                        int insertItem(BuildAIModule * this, RGE_Play
    //                              taibldmd.cpp:1642 (7)
    //         004d5b6c     POP        EDI
    //         004d5b6d     POP        ESI
    //         004d5b6e     POP        EBP
    //         004d5b6f     POP        EBX
    //         004d5b70     RET        0x8
}

// Offset: 0x004D5B80
int insertGathererPercentage(TribeBuildAIModule* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::insertGathererPercentage(int,int,int)                      *
    //                              *********************************************************************************************************
    //                              int __thiscall insertGathererPercentage(TribeBuildAIModule * this, i
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5b89(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5b84(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d5b80(R)  
    //                               ?insertGathererPercentage@TribeBuildAIModule@@QAEHHHH@Z      XREF[1]:     initialize:004d43e2(c)  
    //                               TribeBuildAIModule::insertGathererPercentage
    //                              taibldmd.cpp:1647 (39)
    //         004d5b80     MOV        EAX,dword ptr [ESP + param_3]
    //         004d5b84     MOV        EDX,dword ptr [ESP + param_2]
    //         004d5b88     PUSH       EAX
    //         004d5b89     MOV        EAX,dword ptr [ESP + param_1]
    //         004d5b8d     PUSH       0x1
    //         004d5b8f     PUSH       EDX
    //         004d5b90     MOV        EDX,dword ptr [ECX + this->md]
    //         004d5b96     PUSH       0x6
    //         004d5b98     PUSH       0x1
    //         004d5b9a     PUSH       EAX
    //         004d5b9b     MOV        EAX,dword ptr [EDX + 0xf0]
    //         004d5ba1     PUSH       EAX
    //         004d5ba2     CALL       BuildAIModule::insertItem                        int insertItem(BuildAIModule * this, RGE_Play
    //                              taibldmd.cpp:1653 (3)
    //         004d5ba7     RET        0xc
}

// Offset: 0x004D5BB0
int TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int param_1, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int,int)        *
    //                              *********************************************************************************************************
    //                              int __thiscall numberBuiltOrInProgressItemsOfType(TribeBuildAIModule
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5bb6(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5bb0(R)  
    //                               ?numberBuiltOrInProgressItemsOfType@TribeBuildAIModule@@UAE  XREF[1]:     00575488(*)  
    //                               TribeBuildAIModule::numberBuiltOrInProgressItemsOfType
    //                              taibldmd.cpp:1658 (27)
    //         004d5bb0     MOV        EAX,dword ptr [ESP + param_2]
    //         004d5bb4     PUSH       EBX
    //         004d5bb5     PUSH       ESI
    //         004d5bb6     MOV        ESI,dword ptr [ESP + param_1]
    //         004d5bba     PUSH       EDI
    //         004d5bbb     MOV        EDI,this
    //         004d5bbd     TEST       EAX,EAX
    //         004d5bbf     JNZ        LAB_004d5c0c
    //         004d5bc1     CMP        ESI,0x67
    //         004d5bc4     JZ         LAB_004d5bcb
    //         004d5bc6     CMP        ESI,0x44
    //         004d5bc9     JNZ        LAB_004d5c0c
    //                               LAB_004d5bcb                                                 XREF[1]:     004d5bc4(j)  
    //                              taibldmd.cpp:1666 (10)
    //         004d5bcb     PUSH       0x0
    //         004d5bcd     PUSH       ESI
    //         004d5bce     MOV        this,EDI
    //         004d5bd0     CALL       BuildAIModule::numberInProgressItemsOfType       int numberInProgressItemsOfType(BuildAIModule
    //                              taibldmd.cpp:1668 (26)
    //         004d5bd5     MOV        this,dword ptr [EDI + 0x5bc]
    //         004d5bdb     CMP        ESI,0x67
    //         004d5bde     MOV        EBX,EAX
    //         004d5be0     JNZ        LAB_004d5bf7
    //         004d5be2     ADD        this,0xcec
    //         004d5be8     CALL       TribeInformationAIModule::numberStoragePits      int numberStoragePits(TribeInformationAIModul
    //         004d5bed     ADD        EBX,EAX
    //                              taibldmd.cpp:1674 (2)
    //         004d5bef     MOV        EAX,EBX
    //                              taibldmd.cpp:1675 (6)
    //         004d5bf1     POP        EDI
    //         004d5bf2     POP        ESI
    //         004d5bf3     POP        EBX
    //         004d5bf4     RET        0x8
    //                               LAB_004d5bf7                                                 XREF[1]:     004d5be0(j)  
    //                              taibldmd.cpp:1670 (13)
    //         004d5bf7     ADD        this,0xcec
    //         004d5bfd     CALL       TribeInformationAIModule::numberGranaries        int numberGranaries(TribeInformationAIModule 
    //         004d5c02     ADD        EBX,EAX
    //                              taibldmd.cpp:1674 (2)
    //         004d5c04     MOV        EAX,EBX
    //                              taibldmd.cpp:1675 (6)
    //         004d5c06     POP        EDI
    //         004d5c07     POP        ESI
    //         004d5c08     POP        EBX
    //         004d5c09     RET        0x8
    //                               LAB_004d5c0c                                                 XREF[2]:     004d5bbf(j), 004d5bc9(j)  
    //                              taibldmd.cpp:1673 (11)
    //         004d5c0c     PUSH       EAX
    //         004d5c0d     PUSH       ESI
    //         004d5c0e     MOV        this,EDI
    //         004d5c10     CALL       BuildAIModule::numberBuiltOrInProgressItemsOfT   int numberBuiltOrInProgressItemsOfType(BuildA
    //         004d5c15     MOV        EBX,EAX
    //                              taibldmd.cpp:1675 (6)
    //         004d5c17     POP        EDI
    //         004d5c18     POP        ESI
    //         004d5c19     POP        EBX
    //         004d5c1a     RET        0x8
}

// Offset: 0x004D5C20
int allBuilt(TribeBuildAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::allBuilt(int,int)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall allBuilt(TribeBuildAIModule * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5c38(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5c34(R)  
    //                               ?allBuilt@TribeBuildAIModule@@QAEHHH@Z                       XREF[2]:     checkForBuildInsertion:00501e78(c)
    //                               TribeBuildAIModule::allBuilt                                              checkForBuildInsertion:0050202e(c)
    //                              taibldmd.cpp:1680 (3)
    //         004d5c20     PUSH       EBX
    //         004d5c21     PUSH       EBP
    //         004d5c22     PUSH       ESI
    //                              taibldmd.cpp:1684 (7)
    //         004d5c23     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004d5c29     PUSH       EDI
    //                              taibldmd.cpp:1685 (22)
    //         004d5c2a     LEA        EDI,[ECX + this->_padding_]
    //         004d5c30     CMP        ESI,EDI
    //         004d5c32     JZ         LAB_004d5c88
    //         004d5c34     MOV        EBX,dword ptr [ESP + param_2]
    //         004d5c38     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_004d5c3c                                                 XREF[1]:     004d5c71(j)  
    //         004d5c3c     TEST       ESI,ESI
    //         004d5c3e     JZ         LAB_004d5c88
    //                              taibldmd.cpp:1689 (44)
    //         004d5c40     MOV        this,ESI
    //         004d5c42     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d5c47     CMP        EAX,EBP
    //         004d5c49     JZ         LAB_004d5c56
    //         004d5c4b     MOV        this,ESI
    //         004d5c4d     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d5c52     CMP        EAX,EBX
    //         004d5c54     JNZ        LAB_004d5c6c
    //                               LAB_004d5c56                                                 XREF[1]:     004d5c49(j)  
    //         004d5c56     MOV        this,ESI
    //         004d5c58     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d5c5d     TEST       EAX,EAX
    //         004d5c5f     JNZ        LAB_004d5c6c
    //         004d5c61     MOV        this,ESI
    //         004d5c63     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d5c68     TEST       EAX,EAX
    //         004d5c6a     JZ         LAB_004d5c7f
    //                               LAB_004d5c6c                                                 XREF[2]:     004d5c54(j), 004d5c5f(j)  
    //                              taibldmd.cpp:1691 (7)
    //         004d5c6c     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d5c6f     CMP        ESI,EDI
    //         004d5c71     JNZ        LAB_004d5c3c
    //                              taibldmd.cpp:1694 (5)
    //         004d5c73     MOV        EAX,0x1
    //                              taibldmd.cpp:1695 (7)
    //         004d5c78     POP        EDI
    //         004d5c79     POP        ESI
    //         004d5c7a     POP        EBP
    //         004d5c7b     POP        EBX
    //         004d5c7c     RET        0x8
    //                               LAB_004d5c7f                                                 XREF[1]:     004d5c6a(j)  
    //                              taibldmd.cpp:1690 (2)
    //         004d5c7f     XOR        EAX,EAX
    //                              taibldmd.cpp:1695 (19)
    //         004d5c81     POP        EDI
    //         004d5c82     POP        ESI
    //         004d5c83     POP        EBP
    //         004d5c84     POP        EBX
    //         004d5c85     RET        0x8
    //                               LAB_004d5c88                                                 XREF[2]:     004d5c32(j), 004d5c3e(j)  
    //         004d5c88     POP        EDI
    //         004d5c89     POP        ESI
    //         004d5c8a     POP        EBP
    //         004d5c8b     MOV        EAX,0x1
    //         004d5c90     POP        EBX
    //         004d5c91     RET        0x8
}

// Offset: 0x004D5CA0
int readyToResearch(TribeBuildAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeBuildAIModule::readyToResearch(int,int)                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall readyToResearch(TribeBuildAIModule * this, int param_
    //              int               EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004d5cad(R), 004d5ccb(R), 004d5d13(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5ca0(R)  
    //                               ?readyToResearch@TribeBuildAIModule@@QAEHHH@Z                XREF[6]:     updateGathererDistribution:004f8fb
    //                               TribeBuildAIModule::readyToResearch                                       updateGathererDistribution:004f906
    //                                                                                                         updateGathererDistribution:004f915
    //                                                                                                         checkForASAPAgeResearch:00502c17(c
    //                                                                                                         checkForASAPAgeResearch:00502c7d(c
    //                                                                                                         checkForASAPAgeResearch:00502ce9(c
    //                              taibldmd.cpp:1700 (13)
    //         004d5ca0     MOV        EAX,dword ptr [ESP + param_2]
    //         004d5ca4     PUSH       ESI
    //         004d5ca5     CMP        EAX,0x1
    //         004d5ca8     PUSH       EDI
    //         004d5ca9     MOV        ESI,this
    //         004d5cab     JNZ        LAB_004d5d0d
    //                              taibldmd.cpp:1703 (9)
    //         004d5cad     MOV        EDI,dword ptr [ESP + param_1]
    //         004d5cb1     CMP        EDI,0x2
    //         004d5cb4     JNZ        LAB_004d5ccb
    //                              taibldmd.cpp:1704 (25)
    //         004d5cb6     MOV        EAX,dword ptr [ESI + 0x5bc]
    //                              language.dll match for 0x65: "1"
    //         004d5cbc     PUSH       0x65
    //         004d5cbe     MOV        this,dword ptr [EAX + 0x1256c]
    //         004d5cc4     CALL       TRIBE_Player::researchState                      uchar researchState(TRIBE_Player * this, int 
    //         004d5cc9     JMP        LAB_004d5ccf
    //                               LAB_004d5ccb                                                 XREF[1]:     004d5cb4(j)  
    //         004d5ccb     MOV        AL,byte ptr [ESP + param_1]
    //                               LAB_004d5ccf                                                 XREF[1]:     004d5cc9(j)  
    //                              taibldmd.cpp:1705 (5)
    //         004d5ccf     CMP        EDI,0x3
    //         004d5cd2     JNZ        LAB_004d5ce7
    //                              taibldmd.cpp:1706 (19)
    //         004d5cd4     MOV        this,dword ptr [ESI + 0x5bc]
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         004d5cda     PUSH       0x66
    //         004d5cdc     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d5ce2     CALL       TRIBE_Player::researchState                      uchar researchState(TRIBE_Player * this, int 
    //                               LAB_004d5ce7                                                 XREF[1]:     004d5cd2(j)  
    //                              taibldmd.cpp:1707 (5)
    //         004d5ce7     CMP        EDI,0x4
    //         004d5cea     JNZ        LAB_004d5d23
    //                              taibldmd.cpp:1708 (14)
    //         004d5cec     MOV        EDX,dword ptr [ESI + 0x5bc]
    //                              language.dll match for 0x67: "Comic Sans MS"
    //         004d5cf2     PUSH       0x67
    //         004d5cf4     MOV        this,dword ptr [EDX + 0x1256c]
    //                              taibldmd.cpp:1711 (5)
    //         004d5cfa     CALL       TRIBE_Player::researchState                      uchar researchState(TRIBE_Player * this, int 
    //                              taibldmd.cpp:1713 (9)
    //         004d5cff     XOR        EDX,EDX
    //         004d5d01     CMP        AL,0x1
    //         004d5d03     SETZ       DL
    //         004d5d06     MOV        EAX,EDX
    //                              taibldmd.cpp:1716 (5)
    //         004d5d08     POP        EDI
    //         004d5d09     POP        ESI
    //         004d5d0a     RET        0x8
    //                               LAB_004d5d0d                                                 XREF[1]:     004d5cab(j)  
    //                              taibldmd.cpp:1711 (22)
    //         004d5d0d     MOV        this,dword ptr [ESI + 0x5bc]
    //         004d5d13     MOV        EAX,dword ptr [ESP + param_1]
    //         004d5d17     PUSH       EAX
    //         004d5d18     MOV        this,dword ptr [this->_padding_ + 0x1256c]
    //         004d5d1e     CALL       TRIBE_Player::researchState                      uchar researchState(TRIBE_Player * this, int 
    //                               LAB_004d5d23                                                 XREF[1]:     004d5cea(j)  
    //                              taibldmd.cpp:1713 (7)
    //         004d5d23     XOR        EDX,EDX
    //         004d5d25     CMP        AL,0x1
    //         004d5d27     SETZ       DL
    //                              taibldmd.cpp:1716 (7)
    //         004d5d2a     POP        EDI
    //         004d5d2b     MOV        EAX,EDX
    //         004d5d2d     POP        ESI
    //         004d5d2e     RET        0x8
}

// Offset: 0x004D5D40
void unskipBuildList(TribeBuildAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeBuildAIModule::unskipBuildList(int,int)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall unskipBuildList(TribeBuildAIModule * this, int param
    //              void              <VOID>         <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?unskipBuildList@TribeBuildAIModule@@QAEXHH@Z                XREF[1]:     doSomething:004f0aa7(c)  
    //                               TribeBuildAIModule::unskipBuildList
    //                              taibldmd.cpp:1721 (6)
    //         004d5d40     PUSH       EBX
    //         004d5d41     PUSH       EBP
    //         004d5d42     PUSH       ESI
    //         004d5d43     PUSH       EDI
    //         004d5d44     MOV        EDI,this
    //                              taibldmd.cpp:1729 (11)
    //         004d5d46     PUSH       0x0
    //                              language.dll match for 0x67: "Comic Sans MS"
    //         004d5d48     PUSH       0x67
    //         004d5d4a     MOV        EAX,dword ptr [EDI]
    //         004d5d4c     MOV        ESI,dword ptr [EAX + 0x48]
    //         004d5d4f     CALL       ESI
    //                              taibldmd.cpp:1730 (10)
    //         004d5d51     PUSH       0x0
    //         004d5d53     PUSH       offset DAT_fffffff8
    //         004d5d55     MOV        this,EDI
    //         004d5d57     MOV        EBX,EAX
    //         004d5d59     CALL       ESI
    //                              taibldmd.cpp:1733 (22)
    //         004d5d5b     MOV        ESI,dword ptr [EDI + 0x15c]
    //         004d5d61     ADD        EDI,0xf0
    //         004d5d67     CMP        ESI,EDI
    //         004d5d69     MOV        EBP,EAX
    //         004d5d6b     JZ         LAB_004d5dd4
    //                               LAB_004d5d6d                                                 XREF[1]:     004d5dd2(j)  
    //         004d5d6d     TEST       ESI,ESI
    //         004d5d6f     JZ         LAB_004d5dd4
    //                              taibldmd.cpp:1735 (24)
    //         004d5d71     MOV        this,ESI
    //         004d5d73     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d5d78     CMP        EAX,0x1
    //         004d5d7b     JZ         LAB_004d5dcd
    //         004d5d7d     MOV        this,ESI
    //         004d5d7f     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d5d84     CMP        EAX,0x1
    //         004d5d87     JZ         LAB_004d5dcd
    //                              taibldmd.cpp:1738 (16)
    //         004d5d89     TEST       EBX,EBX
    //         004d5d8b     JLE        LAB_004d5d99
    //         004d5d8d     MOV        this,ESI
    //         004d5d8f     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5d94     CMP        EAX,0x67
    //         004d5d97     JZ         LAB_004d5dcd
    //                               LAB_004d5d99                                                 XREF[1]:     004d5d8b(j)  
    //                              taibldmd.cpp:1740 (16)
    //         004d5d99     TEST       EBP,EBP
    //         004d5d9b     JLE        LAB_004d5da9
    //         004d5d9d     MOV        this,ESI
    //         004d5d9f     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5da4     CMP        EAX,0x44
    //         004d5da7     JZ         LAB_004d5dcd
    //                               LAB_004d5da9                                                 XREF[1]:     004d5d9b(j)  
    //                              taibldmd.cpp:1743 (9)
    //         004d5da9     PUSH       0x0
    //         004d5dab     MOV        this,ESI
    //         004d5dad     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
    //                              taibldmd.cpp:1744 (9)
    //         004d5db2     PUSH       0x0
    //         004d5db4     MOV        this,ESI
    //         004d5db6     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
    //                              taibldmd.cpp:1745 (9)
    //         004d5dbb     PUSH       0x0
    //         004d5dbd     MOV        this,ESI
    //         004d5dbf     CALL       BuildItem::setSkipCycles                         void setSkipCycles(BuildItem * this, int para
    //                              taibldmd.cpp:1746 (16)
    //         004d5dc4     PUSH       0x0
    //         004d5dc6     MOV        this,ESI
    //         004d5dc8     CALL       BuildItem::setPermanentSkip                      void setPermanentSkip(BuildItem * this, uchar
    //                               LAB_004d5dcd                                                 XREF[4]:     004d5d7b(j), 004d5d87(j), 
    //                                                                                                         004d5d97(j), 004d5da7(j)  
    //         004d5dcd     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d5dd0     CMP        ESI,EDI
    //         004d5dd2     JNZ        LAB_004d5d6d
    //                               LAB_004d5dd4                                                 XREF[2]:     004d5d6b(j), 004d5d6f(j)  
    //                              taibldmd.cpp:1753 (7)
    //         004d5dd4     POP        EDI
    //         004d5dd5     POP        ESI
    //         004d5dd6     POP        EBP
    //         004d5dd7     POP        EBX
    //         004d5dd8     RET        0x8
}

// Offset: 0x004D5DE0
BuildItem* buildItem(TribeBuildAIModule* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class BuildItem * __thiscall TribeBuildAIModule::buildItem(int,int,int)                       *
    //                              *********************************************************************************************************
    //                              BuildItem * __thiscall buildItem(TribeBuildAIModule * this, int para
    //              BuildItem *       EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004d5e1d(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004d5df8(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004d5df4(R)  
    //                               ?buildItem@TribeBuildAIModule@@QAEPAVBuildItem@@HHH@Z        XREF[3]:     checkForASAPAgeResearch:00502c4c(c
    //                               TribeBuildAIModule::buildItem                                             checkForASAPAgeResearch:00502cb2(c
    //                                                                                                         checkForASAPAgeResearch:00502d38(c
    //                              taibldmd.cpp:1759 (3)
    //         004d5de0     PUSH       EBX
    //         004d5de1     PUSH       EBP
    //         004d5de2     PUSH       ESI
    //                              taibldmd.cpp:1761 (7)
    //         004d5de3     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004d5de9     PUSH       EDI
    //                              taibldmd.cpp:1762 (22)
    //         004d5dea     LEA        EDI,[ECX + this->_padding_]
    //         004d5df0     CMP        ESI,EDI
    //         004d5df2     JZ         LAB_004d5e52
    //         004d5df4     MOV        EBX,dword ptr [ESP + param_3]
    //         004d5df8     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_004d5dfc                                                 XREF[1]:     004d5e3e(j)  
    //         004d5dfc     TEST       ESI,ESI
    //         004d5dfe     JZ         LAB_004d5e52
    //                              taibldmd.cpp:1768 (57)
    //         004d5e00     MOV        this,ESI
    //         004d5e02     CALL       BuildItem::built                                 int built(BuildItem * this)
    //         004d5e07     TEST       EAX,EAX
    //         004d5e09     JNZ        LAB_004d5e39
    //         004d5e0b     MOV        this,ESI
    //         004d5e0d     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
    //         004d5e12     TEST       EAX,EAX
    //         004d5e14     JNZ        LAB_004d5e39
    //         004d5e16     MOV        this,ESI
    //         004d5e18     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
    //         004d5e1d     CMP        EAX,dword ptr [ESP + param_1]
    //         004d5e21     JNZ        LAB_004d5e39
    //         004d5e23     MOV        this,ESI
    //         004d5e25     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d5e2a     CMP        EAX,EBP
    //         004d5e2c     JZ         LAB_004d5e49
    //         004d5e2e     MOV        this,ESI
    //         004d5e30     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
    //         004d5e35     CMP        EAX,EBX
    //         004d5e37     JZ         LAB_004d5e49
    //                               LAB_004d5e39                                                 XREF[3]:     004d5e09(j), 004d5e14(j), 
    //                                                                                                         004d5e21(j)  
    //                              taibldmd.cpp:1770 (7)
    //         004d5e39     MOV        ESI,dword ptr [ESI + 0x6c]
    //         004d5e3c     CMP        ESI,EDI
    //         004d5e3e     JNZ        LAB_004d5dfc
    //                              taibldmd.cpp:1772 (2)
    //         004d5e40     XOR        EAX,EAX
    //                              taibldmd.cpp:1773 (7)
    //         004d5e42     POP        EDI
    //         004d5e43     POP        ESI
    //         004d5e44     POP        EBP
    //         004d5e45     POP        EBX
    //         004d5e46     RET        0xc
    //                               LAB_004d5e49                                                 XREF[2]:     004d5e2c(j), 004d5e37(j)  
    //                              taibldmd.cpp:1769 (2)
    //         004d5e49     MOV        EAX,ESI
    //                              taibldmd.cpp:1773 (16)
    //         004d5e4b     POP        EDI
    //         004d5e4c     POP        ESI
    //         004d5e4d     POP        EBP
    //         004d5e4e     POP        EBX
    //         004d5e4f     RET        0xc
    //                               LAB_004d5e52                                                 XREF[2]:     004d5df2(j), 004d5dfe(j)  
    //         004d5e52     POP        EDI
    //         004d5e53     POP        ESI
    //         004d5e54     POP        EBP
    //         004d5e55     XOR        EAX,EAX
    //         004d5e57     POP        EBX
    //         004d5e58     RET        0xc
}

