#include "common.h"
#include "aimdmod.h"

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall MainDecisionAIModule(MainDecisionAIModule * thi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0040cdfe(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040ce0c(R)  
    //              RGE_Player *      Stack[0xc]:4   param_3                   XREF[1]:     0040ce23(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040ce27(R)  
    //                               ??0MainDecisionAIModule@@QAE@PAXHPAVRGE_Player@@@Z           XREF[1]:     TribeMainDecisionAIModule:004e482f
    //                               MainDecisionAIModule::MainDecisionAIModule
    //                              aimdmod.cpp:34 (55)
    //         0040cdf0     MOV        EAX,FS:[0x0]
    //         0040cdf6     PUSH       -0x1
    //         0040cdf8     PUSH       FUN_0055c638
    //         0040cdfd     PUSH       EAX
    //         0040cdfe     MOV        EAX,dword ptr [ESP + param_1]
    //         0040ce02     MOV        dword ptr FS:[0x0],ESP
    //         0040ce09     PUSH       ESI
    //         0040ce0a     MOV        ESI,this
    //         0040ce0c     MOV        this,dword ptr [ESP + param_2]
    //         0040ce10     PUSH       EAX
    //         0040ce11     PUSH       this
    //         0040ce12     PUSH       0x3e8
    //         0040ce17     PUSH       s_Main_Decision_AI                               = "Main Decision AI"
    //         0040ce1c     MOV        this,ESI
    //         0040ce1e     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040ce23     MOV        EDX,dword ptr [ESP + param_3]
    //                              aimdmod.cpp:35 (58)
    //         0040ce27     MOV        this,dword ptr [ESP + local_c]
    //         0040ce2b     XOR        EAX,EAX
    //         0040ce2d     MOV        dword ptr [ESI + 0xf0],EDX
    //         0040ce33     MOV        dword ptr [ESI + 0xf4],EAX
    //         0040ce39     MOV        dword ptr [ESI + 0xf8],EAX
    //         0040ce3f     MOV        dword ptr [ESI + 0xfc],EAX
    //         0040ce45     MOV        dword ptr [ESI + 0x100],EAX
    //         0040ce4b     MOV        dword ptr [ESI],MainDecisionAIModule::`vftable'  = 0040ce70
    //         0040ce51     MOV        EAX,ESI
    //         0040ce53     MOV        dword ptr FS:[0x0],this
    //         0040ce5a     POP        ESI
    //         0040ce5b     ADD        ESP,0xc
    //         0040ce5e     RET        0xc
    //         0040ce61     ??         90h
    //         0040ce62     NOP
    //         0040ce63     NOP
    //         0040ce64     NOP
    //         0040ce65     NOP
    //         0040ce66     NOP
    //         0040ce67     NOP
    //         0040ce68     NOP
    //         0040ce69     NOP
    //         0040ce6a     NOP
    //         0040ce6b     NOP
    //         0040ce6c     NOP
    //         0040ce6d     NOP
    //         0040ce6e     NOP
    //         0040ce6f     NOP
}

MainDecisionAIModule::MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall MainDecisionAIModule(MainDecisionAIModule * thi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0040cea8(R), 0040cf12(W), 0040cfea(R), 0040cff5(W)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[3]:     0040cec7(R), 0040cf26(*), 0040cf39(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     0040ceed(R), 0040cf22(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040cecb(W), 0040cef9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040d001(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040cebe(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0040cef1(*), 0040cf09(R), 0040cfee(R)  
    //              int               Stack[-0x18]:4 numberUnits
    //                               ??0MainDecisionAIModule@@QAE@HPAVRGE_Player@@H@Z             XREF[1]:     TribeMainDecisionAIModule:004e4baf
    //                               MainDecisionAIModule::MainDecisionAIModule
    //                              aimdmod.cpp:43 (93)
    //         0040ce90     PUSH       -0x1
    //         0040ce92     PUSH       FUN_0055c666
    //         0040ce97     MOV        EAX,FS:[0x0]
    //         0040ce9d     PUSH       EAX
    //         0040ce9e     MOV        dword ptr FS:[0x0],ESP
    //         0040cea5     SUB        ESP,0x8
    //         0040cea8     MOV        EAX,dword ptr [ESP + param_1]
    //         0040ceac     PUSH       ESI
    //         0040cead     PUSH       EDI
    //         0040ceae     XOR        EDI,EDI
    //         0040ceb0     PUSH       EDI
    //         0040ceb1     PUSH       EAX
    //         0040ceb2     MOV        ESI,this
    //         0040ceb4     PUSH       0x3e8
    //         0040ceb9     PUSH       s_Main_Decision_AI                               = "Main Decision AI"
    //         0040cebe     MOV        dword ptr [ESP + local_10],ESI
    //         0040cec2     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040cec7     MOV        this,dword ptr [ESP + param_2]
    //         0040cecb     MOV        dword ptr [ESP + local_4],EDI
    //         0040cecf     MOV        dword ptr [ESI + 0xf0],this
    //         0040ced5     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040cedb     MOV        dword ptr [ESI + 0xf8],EDI
    //         0040cee1     MOV        dword ptr [ESI + 0xfc],EDI
    //         0040cee7     MOV        dword ptr [ESI + 0x100],EDI
    //                              aimdmod.cpp:46 (28)
    //         0040ceed     MOV        EAX,dword ptr [ESP + param_3]
    //         0040cef1     LEA        EDX=>local_14,[ESP + 0x8]
    //         0040cef5     PUSH       0x4
    //         0040cef7     PUSH       EDX
    //         0040cef8     PUSH       EAX
    //         0040cef9     MOV        byte ptr [ESP + local_4],0x1
    //         0040cefe     MOV        dword ptr [ESI],MainDecisionAIModule::`vftable'  = 0040ce70
    //         0040cf04     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aimdmod.cpp:47 (25)
    //         0040cf09     MOV        EAX,dword ptr [ESP + local_14]
    //         0040cf0d     ADD        ESP,0xc
    //         0040cf10     CMP        EAX,EDI
    //         0040cf12     MOV        dword ptr [ESP + param_1],EDI
    //         0040cf16     JLE        LAB_0040d001
    //         0040cf1c     PUSH       EBP
    //         0040cf1d     PUSH       EBX
    //         0040cf1e     JMP        LAB_0040cf22
    //                               LAB_0040cf20                                                 XREF[1]:     0040cff9(j)  
    //         0040cf20     XOR        EDI,EDI
    //                               LAB_0040cf22                                                 XREF[1]:     0040cf1e(j)  
    //                              aimdmod.cpp:49 (17)
    //         0040cf22     MOV        EDX,dword ptr [ESP + param_3]
    //         0040cf26     LEA        this=>param_2,[ESP + 0x2c]
    //         0040cf2a     PUSH       0x4
    //         0040cf2c     PUSH       this
    //         0040cf2d     PUSH       EDX
    //         0040cf2e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              aimdmod.cpp:50 (206)
    //         0040cf33     MOV        this,dword ptr [ESI + 0xf8]
    //         0040cf39     MOV        EDX,dword ptr [ESP + param_2]
    //         0040cf3d     ADD        ESP,0xc
    //         0040cf40     XOR        EAX,EAX
    //         0040cf42     CMP        this,EDI
    //         0040cf44     MOV        EBP,EDX
    //         0040cf46     JLE        LAB_0040cf66
    //         0040cf48     MOV        EDI,dword ptr [ESI + 0x100]
    //                               LAB_0040cf4e                                                 XREF[1]:     0040cf64(j)  
    //         0040cf4e     CMP        EAX,EDI
    //         0040cf50     JGE        LAB_0040cf66
    //         0040cf52     MOV        EBX,dword ptr [ESI + 0xf4]
    //         0040cf58     CMP        dword ptr [EBX + EAX*0x4],EDX
    //         0040cf5b     JZ         LAB_0040cfea
    //         0040cf61     INC        EAX
    //         0040cf62     CMP        EAX,this
    //         0040cf64     JL         LAB_0040cf4e
    //                               LAB_0040cf66                                                 XREF[2]:     0040cf46(j), 0040cf50(j)  
    //         0040cf66     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040cf6c     DEC        EAX
    //         0040cf6d     CMP        this,EAX
    //         0040cf6f     JLE        LAB_0040cfce
    //         0040cf71     LEA        EBX,[ECX + this+0x1]
    //         0040cf74     LEA        this,[EBX*0x4 + 0x0]
    //         0040cf7b     PUSH       this
    //         0040cf7c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040cf81     MOV        EDI,EAX
    //         0040cf83     ADD        ESP,0x4
    //         0040cf86     TEST       EDI,EDI
    //         0040cf88     JZ         LAB_0040cfce
    //         0040cf8a     MOV        this,dword ptr [ESI + 0x100]
    //         0040cf90     XOR        EAX,EAX
    //         0040cf92     TEST       this,this
    //         0040cf94     JLE        LAB_0040cfb3
    //                               LAB_0040cf96                                                 XREF[1]:     0040cfb1(j)  
    //         0040cf96     CMP        EAX,EBX
    //         0040cf98     JGE        LAB_0040cfb3
    //         0040cf9a     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040cfa0     INC        EAX
    //         0040cfa1     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040cfa5     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040cfa9     MOV        this,dword ptr [ESI + 0x100]
    //         0040cfaf     CMP        EAX,this
    //         0040cfb1     JL         LAB_0040cf96
    //                               LAB_0040cfb3                                                 XREF[2]:     0040cf94(j), 0040cf98(j)  
    //         0040cfb3     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040cfb9     PUSH       EDX
    //         0040cfba     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040cfbf     ADD        ESP,0x4
    //         0040cfc2     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040cfc8     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040cfce                                                 XREF[2]:     0040cf6f(j), 0040cf88(j)  
    //         0040cfce     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040cfd4     MOV        this,dword ptr [ESI + 0xf4]
    //         0040cfda     MOV        dword ptr [this->_padding_ + EAX*0x4],EBP
    //         0040cfdd     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040cfe3     INC        EAX
    //         0040cfe4     MOV        dword ptr [ESI + 0xf8],EAX
    //                               LAB_0040cfea                                                 XREF[1]:     0040cf5b(j)  
    //         0040cfea     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cfee     MOV        this,dword ptr [ESP + local_14]
    //         0040cff2     INC        EAX
    //         0040cff3     CMP        EAX,this
    //         0040cff5     MOV        dword ptr [ESP + param_1],EAX
    //         0040cff9     JL         LAB_0040cf20
    //         0040cfff     POP        EBX
    //         0040d000     POP        EBP
    //                               LAB_0040d001                                                 XREF[1]:     0040cf16(j)  
    //                              aimdmod.cpp:52 (21)
    //         0040d001     MOV        this,dword ptr [ESP + local_c]
    //         0040d005     MOV        EAX,ESI
    //         0040d007     POP        EDI
    //         0040d008     MOV        dword ptr FS:[0x0],this
    //         0040d00f     POP        ESI
    //         0040d010     ADD        ESP,0x14
    //         0040d013     RET        0xc
    //         0040d016     ??         90h
    //         0040d017     NOP
    //         0040d018     NOP
    //         0040d019     NOP
    //         0040d01a     NOP
    //         0040d01b     NOP
    //         0040d01c     NOP
    //         0040d01d     NOP
    //         0040d01e     NOP
    //         0040d01f     NOP
}

MainDecisionAIModule::~MainDecisionAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~MainDecisionAIModule(MainDecisionAIModule * this)
    //              void              <VOID>         <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040d049(W), 0040d072(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040d07f(R)  
    //                               ??1MainDecisionAIModule@@UAE@XZ                              XREF[4]:     `vector_deleting_destructor':0040c
    //                               MainDecisionAIModule::~MainDecisionAIModule                               ~TribeMainDecisionAIModule:004e4f8
    //                                                                                                         FUN_00560620:00560623(c), 
    //                                                                                                         FUN_005606b0:005606b3(c)  
    //                              aimdmod.cpp:57 (82)
    //         0040d020     MOV        EAX,FS:[0x0]
    //         0040d026     PUSH       -0x1
    //         0040d028     PUSH       FUN_0055c678
    //         0040d02d     PUSH       EAX
    //         0040d02e     MOV        dword ptr FS:[0x0],ESP
    //         0040d035     PUSH       ESI
    //         0040d036     MOV        ESI,this
    //         0040d038     PUSH       EDI
    //         0040d039     MOV        dword ptr [ESI],MainDecisionAIModule::`vftable'  = 0040ce70
    //         0040d03f     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d045     XOR        EDI,EDI
    //         0040d047     CMP        EAX,EDI
    //         0040d049     MOV        dword ptr [ESP + local_4],EDI
    //         0040d04d     JZ         LAB_0040d05e
    //         0040d04f     PUSH       EAX
    //         0040d050     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d055     ADD        ESP,0x4
    //         0040d058     MOV        dword ptr [ESI + 0xf4],EDI
    //                               LAB_0040d05e                                                 XREF[1]:     0040d04d(j)  
    //         0040d05e     MOV        this,ESI
    //         0040d060     MOV        dword ptr [ESI + 0xf8],EDI
    //         0040d066     MOV        dword ptr [ESI + 0xfc],EDI
    //         0040d06c     MOV        dword ptr [ESI + 0x100],EDI
    //                              aimdmod.cpp:58 (30)
    //         0040d072     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0040d07a     CALL       AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //         0040d07f     MOV        this,dword ptr [ESP + local_c]
    //         0040d083     POP        EDI
    //         0040d084     MOV        dword ptr FS:[0x0],this
    //         0040d08b     POP        ESI
    //         0040d08c     ADD        ESP,0xc
    //         0040d08f     RET
}

void MainDecisionAIModule::setLogHistory(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall setLogHistory(MainDecisionAIModule * this, int param
    //              void              <VOID>         <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?setLogHistory@MainDecisionAIModule@@UAEXH@Z                 XREF[2]:     setLogHistory:004e503b(c), 
    //                               MainDecisionAIModule::setLogHistory                                       0056e8e0(*)  
    //                              aimdmod.cpp:63 (3)
    //         0040d090     RET        0x4
    //         0040d093     ??         90h
    //         0040d094     NOP
    //         0040d095     NOP
    //         0040d096     NOP
    //         0040d097     NOP
    //         0040d098     NOP
    //         0040d099     NOP
    //         0040d09a     NOP
    //         0040d09b     NOP
    //         0040d09c     NOP
    //         0040d09d     NOP
    //         0040d09e     NOP
    //         0040d09f     NOP
    return;
}

int MainDecisionAIModule::save(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall save(MainDecisionAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0040d0a1(R), 0040d14d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0040d0a9(*), 0040d0b7(W), 0040d143(*), 0040d152(W)  
    //              int               Stack[-0x8]:4  tempInt
    //                               ?save@MainDecisionAIModule@@UAEHH@Z                          XREF[2]:     save:004e5db9(c), 0056e914(*)  
    //                               MainDecisionAIModule::save
    //                              aimdmod.cpp:69 (1)
    //         0040d0a0     PUSH       this
    //                              aimdmod.cpp:71 (31)
    //         0040d0a1     MOV        EDX,dword ptr [ESP + param_1]
    //         0040d0a5     PUSH       EBX
    //         0040d0a6     PUSH       ESI
    //         0040d0a7     MOV        ESI,this
    //         0040d0a9     LEA        this=>local_4,[ESP + 0x8]
    //         0040d0ad     PUSH       0x4
    //         0040d0af     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d0b5     PUSH       this
    //         0040d0b6     PUSH       EDX
    //         0040d0b7     MOV        dword ptr [ESP + local_4],EAX
    //         0040d0bb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              aimdmod.cpp:72 (21)
    //         0040d0c0     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d0c6     ADD        ESP,0xc
    //         0040d0c9     XOR        EBX,EBX
    //         0040d0cb     TEST       EAX,EAX
    //         0040d0cd     JLE        LAB_0040d16f
    //         0040d0d3     PUSH       EDI
    //         0040d0d4     PUSH       EBP
    //                               LAB_0040d0d5                                                 XREF[1]:     0040d167(j)  
    //                              aimdmod.cpp:73 (110)
    //         0040d0d5     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d0db     DEC        EAX
    //         0040d0dc     CMP        EBX,EAX
    //         0040d0de     JLE        LAB_0040d13d
    //         0040d0e0     LEA        this,[EBX*0x4 + 0x4]
    //         0040d0e7     LEA        EBP,[EBX + 0x1]
    //         0040d0ea     PUSH       this
    //         0040d0eb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d0f0     MOV        EDI,EAX
    //         0040d0f2     ADD        ESP,0x4
    //         0040d0f5     TEST       EDI,EDI
    //         0040d0f7     JZ         LAB_0040d13d
    //         0040d0f9     MOV        this,dword ptr [ESI + 0x100]
    //         0040d0ff     XOR        EAX,EAX
    //         0040d101     TEST       this,this
    //         0040d103     JLE        LAB_0040d122
    //                               LAB_0040d105                                                 XREF[1]:     0040d120(j)  
    //         0040d105     CMP        EAX,EBP
    //         0040d107     JGE        LAB_0040d122
    //         0040d109     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d10f     INC        EAX
    //         0040d110     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d114     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d118     MOV        this,dword ptr [ESI + 0x100]
    //         0040d11e     CMP        EAX,this
    //         0040d120     JL         LAB_0040d105
    //                               LAB_0040d122                                                 XREF[2]:     0040d103(j), 0040d107(j)  
    //         0040d122     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d128     PUSH       EDX
    //         0040d129     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d12e     ADD        ESP,0x4
    //         0040d131     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d137     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040d13d                                                 XREF[2]:     0040d0de(j), 0040d0f7(j)  
    //         0040d13d     MOV        EAX,dword ptr [ESI + 0xf4]
    //                              aimdmod.cpp:74 (44)
    //         0040d143     LEA        EDX=>local_4,[ESP + 0x10]
    //         0040d147     PUSH       0x4
    //         0040d149     PUSH       EDX
    //         0040d14a     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040d14d     MOV        EAX,dword ptr [ESP + param_1]
    //         0040d151     PUSH       EAX
    //         0040d152     MOV        dword ptr [ESP + local_4],this
    //         0040d156     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040d15b     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d161     ADD        ESP,0xc
    //         0040d164     INC        EBX
    //         0040d165     CMP        EBX,EAX
    //         0040d167     JL         LAB_0040d0d5
    //         0040d16d     POP        EBP
    //         0040d16e     POP        EDI
    //                               LAB_0040d16f                                                 XREF[1]:     0040d0cd(j)  
    //                              aimdmod.cpp:77 (11)
    //         0040d16f     POP        ESI
    //         0040d170     MOV        EAX,0x1
    //         0040d175     POP        EBX
    //         0040d176     POP        this
    //         0040d177     RET        0x4
    //         0040d17a     ??         90h
    //         0040d17b     NOP
    //         0040d17c     NOP
    //         0040d17d     NOP
    //         0040d17e     NOP
    //         0040d17f     NOP
    return 0;
}

int MainDecisionAIModule::addObject(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall addObject(MainDecisionAIModule * this, RGE_Static_Obj
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0040d180(R)  
    //                               ?addObject@MainDecisionAIModule@@UAEHPAVRGE_Static_Object@@@Z XREF[2]:     addObject:004e5fce(c), 
    //                               MainDecisionAIModule::addObject                                           0056e918(*)  
    //                              aimdmod.cpp:82 (11)
    //         0040d180     MOV        EAX,dword ptr [ESP + param_1]
    //         0040d184     PUSH       ESI
    //         0040d185     TEST       EAX,EAX
    //         0040d187     MOV        ESI,this
    //         0040d189     JNZ        LAB_0040d18f
    //                              aimdmod.cpp:87 (4)
    //         0040d18b     POP        ESI
    //         0040d18c     RET        0x4
    //                               LAB_0040d18f                                                 XREF[1]:     0040d189(j)  
    //                              aimdmod.cpp:85 (183)
    //         0040d18f     MOV        this,dword ptr [ESI + 0xf8]
    //         0040d195     PUSH       EDI
    //         0040d196     PUSH       EBP
    //         0040d197     MOV        EBP,dword ptr [EAX + 0x4]
    //         0040d19a     XOR        EAX,EAX
    //         0040d19c     PUSH       EBX
    //         0040d19d     TEST       this,this
    //         0040d19f     JLE        LAB_0040d1bf
    //         0040d1a1     MOV        EDX,dword ptr [ESI + 0x100]
    //                               LAB_0040d1a7                                                 XREF[1]:     0040d1bd(j)  
    //         0040d1a7     CMP        EAX,EDX
    //         0040d1a9     JGE        LAB_0040d1bf
    //         0040d1ab     MOV        EDI,dword ptr [ESI + 0xf4]
    //         0040d1b1     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         0040d1b4     JZ         LAB_0040d243
    //         0040d1ba     INC        EAX
    //         0040d1bb     CMP        EAX,this
    //         0040d1bd     JL         LAB_0040d1a7
    //                               LAB_0040d1bf                                                 XREF[2]:     0040d19f(j), 0040d1a9(j)  
    //         0040d1bf     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d1c5     DEC        EAX
    //         0040d1c6     CMP        this,EAX
    //         0040d1c8     JLE        LAB_0040d227
    //         0040d1ca     LEA        EBX,[ECX + this+0x1]
    //         0040d1cd     LEA        this,[EBX*0x4 + 0x0]
    //         0040d1d4     PUSH       this
    //         0040d1d5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d1da     MOV        EDI,EAX
    //         0040d1dc     ADD        ESP,0x4
    //         0040d1df     TEST       EDI,EDI
    //         0040d1e1     JZ         LAB_0040d227
    //         0040d1e3     MOV        this,dword ptr [ESI + 0x100]
    //         0040d1e9     XOR        EAX,EAX
    //         0040d1eb     TEST       this,this
    //         0040d1ed     JLE        LAB_0040d20c
    //                               LAB_0040d1ef                                                 XREF[1]:     0040d20a(j)  
    //         0040d1ef     CMP        EAX,EBX
    //         0040d1f1     JGE        LAB_0040d20c
    //         0040d1f3     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d1f9     INC        EAX
    //         0040d1fa     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d1fe     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d202     MOV        this,dword ptr [ESI + 0x100]
    //         0040d208     CMP        EAX,this
    //         0040d20a     JL         LAB_0040d1ef
    //                               LAB_0040d20c                                                 XREF[2]:     0040d1ed(j), 0040d1f1(j)  
    //         0040d20c     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d212     PUSH       EDX
    //         0040d213     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d218     ADD        ESP,0x4
    //         0040d21b     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d221     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040d227                                                 XREF[2]:     0040d1c8(j), 0040d1e1(j)  
    //         0040d227     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d22d     MOV        this,dword ptr [ESI + 0xf4]
    //         0040d233     MOV        dword ptr [this->_padding_ + EAX*0x4],EBP
    //         0040d236     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d23c     INC        EAX
    //         0040d23d     MOV        dword ptr [ESI + 0xf8],EAX
    //                               LAB_0040d243                                                 XREF[1]:     0040d1b4(j)  
    //         0040d243     POP        EBX
    //         0040d244     POP        EBP
    //         0040d245     POP        EDI
    //                              aimdmod.cpp:86 (5)
    //         0040d246     MOV        EAX,0x1
    //                              aimdmod.cpp:87 (4)
    //         0040d24b     POP        ESI
    //         0040d24c     RET        0x4
    //         0040d24f     ??         90h
    return 0;
}

int MainDecisionAIModule::removeObject(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall removeObject(MainDecisionAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d264(R)  
    //                               ?removeObject@MainDecisionAIModule@@UAEHH@Z                  XREF[2]:     removeObject:004e600f(c), 
    //                               MainDecisionAIModule::removeObject                                        0056e91c(*)  
    //                              aimdmod.cpp:92 (1)
    //         0040d250     PUSH       ESI
    //                              aimdmod.cpp:93 (41)
    //         0040d251     MOV        ESI,dword ptr [ECX + this+0x100]
    //         0040d257     XOR        EAX,EAX
    //         0040d259     TEST       ESI,ESI
    //         0040d25b     PUSH       EDI
    //         0040d25c     JLE        LAB_0040d274
    //         0040d25e     MOV        EDX,dword ptr [ECX + this->objects.value]
    //         0040d264     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_0040d268                                                 XREF[1]:     0040d272(j)  
    //         0040d268     CMP        dword ptr [EDX],EDI
    //         0040d26a     JZ         LAB_0040d274
    //         0040d26c     INC        EAX
    //         0040d26d     ADD        EDX,0x4
    //         0040d270     CMP        EAX,ESI
    //         0040d272     JL         LAB_0040d268
    //                               LAB_0040d274                                                 XREF[2]:     0040d25c(j), 0040d26a(j)  
    //         0040d274     CMP        EAX,ESI
    //         0040d276     JL         LAB_0040d27f
    //         0040d278     XOR        EAX,EAX
    //                              aimdmod.cpp:94 (5)
    //         0040d27a     POP        EDI
    //         0040d27b     POP        ESI
    //         0040d27c     RET        0x4
    //                               LAB_0040d27f                                                 XREF[1]:     0040d276(j)  
    //                              aimdmod.cpp:93 (55)
    //         0040d27f     DEC        ESI
    //         0040d280     CMP        EAX,ESI
    //         0040d282     JGE        LAB_0040d29d
    //                               LAB_0040d284                                                 XREF[1]:     0040d29b(j)  
    //         0040d284     MOV        EDX,dword ptr [ECX + this->objects.value]
    //         0040d28a     INC        EAX
    //         0040d28b     MOV        ESI,dword ptr [EDX + EAX*0x4]
    //         0040d28e     MOV        dword ptr [EDX + EAX*0x4 + -0x4],ESI
    //         0040d292     MOV        EDX,dword ptr [ECX + this+0x100]
    //         0040d298     DEC        EDX
    //         0040d299     CMP        EAX,EDX
    //         0040d29b     JL         LAB_0040d284
    //                               LAB_0040d29d                                                 XREF[1]:     0040d282(j)  
    //         0040d29d     MOV        EAX,dword ptr [ECX + this+0xf8]
    //         0040d2a3     DEC        EAX
    //         0040d2a4     MOV        dword ptr [ECX + this+0xf8],EAX
    //         0040d2aa     JNS        LAB_0040d2b6
    //         0040d2ac     MOV        dword ptr [ECX + this+0xf8],0x0
    //                               LAB_0040d2b6                                                 XREF[1]:     0040d2aa(j)  
    //                              aimdmod.cpp:94 (10)
    //         0040d2b6     POP        EDI
    //         0040d2b7     POP        ESI
    //         0040d2b8     MOV        EAX,0x1
    //         0040d2bd     RET        0x4
    return 0;
}

int MainDecisionAIModule::numberObjects() {
    /* TODO: Stub */
    //                              int __thiscall numberObjects(MainDecisionAIModule * this)
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //                               ?numberObjects@MainDecisionAIModule@@QAEHXZ
    //                               MainDecisionAIModule::numberObjects
    //                              aimdmod.cpp:99 (6)
    //         0040d2c0     MOV        EAX,dword ptr [ECX + this+0xf8]
    //                              aimdmod.cpp:101 (1)
    //         0040d2c6     RET
    //         0040d2c7     ??         90h
    //         0040d2c8     NOP
    //         0040d2c9     NOP
    //         0040d2ca     NOP
    //         0040d2cb     NOP
    //         0040d2cc     NOP
    //         0040d2cd     NOP
    //         0040d2ce     NOP
    //         0040d2cf     NOP
    return 0;
}

int MainDecisionAIModule::numberObjectsWithAction(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall numberObjectsWithAction(MainDecisionAIModule * this, 
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d388(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040d2d7(W), 0040d38e(RW), 0040d3a3(R)  
    //              int               Stack[-0x8]:4  count
    //                               ?numberObjectsWithAction@MainDecisionAIModule@@QAEHH@Z       XREF[4]:     doSomething:004f0548(c), 
    //                               MainDecisionAIModule::numberObjectsWithAction                             doSomething:004f064d(c), 
    //                                                                                                         doSomething:004f0734(c), 
    //                                                                                                         doSomething:004f080b(c)  
    //                              aimdmod.cpp:106 (5)
    //         0040d2d0     PUSH       this
    //         0040d2d1     PUSH       EBX
    //         0040d2d2     PUSH       ESI
    //         0040d2d3     MOV        ESI,this
    //                              aimdmod.cpp:107 (6)
    //         0040d2d5     XOR        EBX,EBX
    //         0040d2d7     MOV        dword ptr [ESP + local_4],EBX
    //                              aimdmod.cpp:108 (14)
    //         0040d2db     CMP        dword ptr [ESI + 0xf8],EBX
    //         0040d2e1     JLE        LAB_0040d3a3
    //         0040d2e7     PUSH       EDI
    //         0040d2e8     PUSH       EBP
    //                               LAB_0040d2e9                                                 XREF[1]:     0040d39b(j)  
    //                              aimdmod.cpp:109 (130)
    //         0040d2e9     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d2ef     DEC        EAX
    //         0040d2f0     CMP        EBX,EAX
    //         0040d2f2     JLE        LAB_0040d351
    //         0040d2f4     LEA        this,[EBX*0x4 + 0x4]
    //         0040d2fb     LEA        EBP,[EBX + 0x1]
    //         0040d2fe     PUSH       this
    //         0040d2ff     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d304     MOV        EDI,EAX
    //         0040d306     ADD        ESP,0x4
    //         0040d309     TEST       EDI,EDI
    //         0040d30b     JZ         LAB_0040d351
    //         0040d30d     MOV        this,dword ptr [ESI + 0x100]
    //         0040d313     XOR        EAX,EAX
    //         0040d315     TEST       this,this
    //         0040d317     JLE        LAB_0040d336
    //                               LAB_0040d319                                                 XREF[1]:     0040d334(j)  
    //         0040d319     CMP        EAX,EBP
    //         0040d31b     JGE        LAB_0040d336
    //         0040d31d     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d323     INC        EAX
    //         0040d324     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d328     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d32c     MOV        this,dword ptr [ESI + 0x100]
    //         0040d332     CMP        EAX,this
    //         0040d334     JL         LAB_0040d319
    //                               LAB_0040d336                                                 XREF[2]:     0040d317(j), 0040d31b(j)  
    //         0040d336     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d33c     PUSH       EDX
    //         0040d33d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d342     ADD        ESP,0x4
    //         0040d345     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d34b     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040d351                                                 XREF[2]:     0040d2f2(j), 0040d30b(j)  
    //         0040d351     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d357     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d35d     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040d360     PUSH       this
    //         0040d361     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d364     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040d369     MOV        EDI,EAX
    //                              aimdmod.cpp:110 (15)
    //         0040d36b     TEST       EDI,EDI
    //         0040d36d     JZ         LAB_0040d392
    //         0040d36f     MOV        this,EDI
    //         0040d371     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d376     TEST       EAX,EAX
    //         0040d378     JZ         LAB_0040d392
    //                              aimdmod.cpp:112 (20)
    //         0040d37a     MOV        this,EDI
    //         0040d37c     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d381     MOV        this,EAX
    //         0040d383     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040d388     CMP        EAX,dword ptr [ESP + param_1]
    //         0040d38c     JNZ        LAB_0040d392
    //                              aimdmod.cpp:113 (21)
    //         0040d38e     INC        dword ptr [ESP + local_4]
    //                               LAB_0040d392                                                 XREF[3]:     0040d36d(j), 0040d378(j), 
    //                                                                                                         0040d38c(j)  
    //         0040d392     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d398     INC        EBX
    //         0040d399     CMP        EBX,EAX
    //         0040d39b     JL         LAB_0040d2e9
    //         0040d3a1     POP        EBP
    //         0040d3a2     POP        EDI
    //                               LAB_0040d3a3                                                 XREF[1]:     0040d2e1(j)  
    //                              aimdmod.cpp:115 (4)
    //         0040d3a3     MOV        EAX,dword ptr [ESP + local_4]
    //                              aimdmod.cpp:116 (6)
    //         0040d3a7     POP        ESI
    //         0040d3a8     POP        EBX
    //         0040d3a9     POP        this
    //         0040d3aa     RET        0x4
    //         0040d3ad     ??         90h
    //         0040d3ae     NOP
    //         0040d3af     NOP
    return 0;
}

int MainDecisionAIModule::numberObjectsWithGroup(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall numberObjectsWithGroup(MainDecisionAIModule * this, i
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d454(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040d3b7(W), 0040d45a(RW), 0040d46f(R)  
    //              int               Stack[-0x8]:4  count
    //                               ?numberObjectsWithGroup@MainDecisionAIModule@@QAEHH@Z
    //                               MainDecisionAIModule::numberObjectsWithGroup
    //                              aimdmod.cpp:121 (5)
    //         0040d3b0     PUSH       this
    //         0040d3b1     PUSH       EBX
    //         0040d3b2     PUSH       ESI
    //         0040d3b3     MOV        ESI,this
    //                              aimdmod.cpp:122 (6)
    //         0040d3b5     XOR        EBX,EBX
    //         0040d3b7     MOV        dword ptr [ESP + local_4],EBX
    //                              aimdmod.cpp:123 (14)
    //         0040d3bb     CMP        dword ptr [ESI + 0xf8],EBX
    //         0040d3c1     JLE        LAB_0040d46f
    //         0040d3c7     PUSH       EDI
    //         0040d3c8     PUSH       EBP
    //                               LAB_0040d3c9                                                 XREF[1]:     0040d467(j)  
    //                              aimdmod.cpp:124 (128)
    //         0040d3c9     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d3cf     DEC        EAX
    //         0040d3d0     CMP        EBX,EAX
    //         0040d3d2     JLE        LAB_0040d431
    //         0040d3d4     LEA        this,[EBX*0x4 + 0x4]
    //         0040d3db     LEA        EBP,[EBX + 0x1]
    //         0040d3de     PUSH       this
    //         0040d3df     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d3e4     MOV        EDI,EAX
    //         0040d3e6     ADD        ESP,0x4
    //         0040d3e9     TEST       EDI,EDI
    //         0040d3eb     JZ         LAB_0040d431
    //         0040d3ed     MOV        this,dword ptr [ESI + 0x100]
    //         0040d3f3     XOR        EAX,EAX
    //         0040d3f5     TEST       this,this
    //         0040d3f7     JLE        LAB_0040d416
    //                               LAB_0040d3f9                                                 XREF[1]:     0040d414(j)  
    //         0040d3f9     CMP        EAX,EBP
    //         0040d3fb     JGE        LAB_0040d416
    //         0040d3fd     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d403     INC        EAX
    //         0040d404     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d408     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d40c     MOV        this,dword ptr [ESI + 0x100]
    //         0040d412     CMP        EAX,this
    //         0040d414     JL         LAB_0040d3f9
    //                               LAB_0040d416                                                 XREF[2]:     0040d3f7(j), 0040d3fb(j)  
    //         0040d416     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d41c     PUSH       EDX
    //         0040d41d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d422     ADD        ESP,0x4
    //         0040d425     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d42b     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040d431                                                 XREF[2]:     0040d3d2(j), 0040d3eb(j)  
    //         0040d431     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d437     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d43d     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040d440     PUSH       this
    //         0040d441     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d444     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              aimdmod.cpp:125 (4)
    //         0040d449     TEST       EAX,EAX
    //         0040d44b     JZ         LAB_0040d45e
    //                              aimdmod.cpp:127 (13)
    //         0040d44d     MOV        EAX,dword ptr [EAX + 0x8]
    //         0040d450     MOVSX      this,word ptr [EAX + 0x14]
    //         0040d454     CMP        this,dword ptr [ESP + param_1]
    //         0040d458     JNZ        LAB_0040d45e
    //                              aimdmod.cpp:128 (21)
    //         0040d45a     INC        dword ptr [ESP + local_4]
    //                               LAB_0040d45e                                                 XREF[2]:     0040d44b(j), 0040d458(j)  
    //         0040d45e     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d464     INC        EBX
    //         0040d465     CMP        EBX,EAX
    //         0040d467     JL         LAB_0040d3c9
    //         0040d46d     POP        EBP
    //         0040d46e     POP        EDI
    //                               LAB_0040d46f                                                 XREF[1]:     0040d3c1(j)  
    //                              aimdmod.cpp:130 (4)
    //         0040d46f     MOV        EAX,dword ptr [ESP + local_4]
    //                              aimdmod.cpp:131 (6)
    //         0040d473     POP        ESI
    //         0040d474     POP        EBX
    //         0040d475     POP        this
    //         0040d476     RET        0x4
    //         0040d479     ??         90h
    //         0040d47a     NOP
    //         0040d47b     NOP
    //         0040d47c     NOP
    //         0040d47d     NOP
    //         0040d47e     NOP
    //         0040d47f     NOP
    return 0;
}

int MainDecisionAIModule::numberObjectsWithActionAndTarget(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall numberObjectsWithActionAndTarget(MainDecisionAIModule
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d538(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040d54c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040d487(W), 0040d552(RW), 0040d567(R)  
    //              int               Stack[-0x8]:4  count
    //                               ?numberObjectsWithActionAndTarget@MainDecisionAIModule@@QAE
    //                               MainDecisionAIModule::numberObjectsWithActionAndTarget
    //                              aimdmod.cpp:137 (5)
    //         0040d480     PUSH       this
    //         0040d481     PUSH       EBX
    //         0040d482     PUSH       ESI
    //         0040d483     MOV        ESI,this
    //                              aimdmod.cpp:138 (6)
    //         0040d485     XOR        EBX,EBX
    //         0040d487     MOV        dword ptr [ESP + local_4],EBX
    //                              aimdmod.cpp:139 (14)
    //         0040d48b     CMP        dword ptr [ESI + 0xf8],EBX
    //         0040d491     JLE        LAB_0040d567
    //         0040d497     PUSH       EDI
    //         0040d498     PUSH       EBP
    //                               LAB_0040d499                                                 XREF[1]:     0040d55f(j)  
    //                              aimdmod.cpp:140 (130)
    //         0040d499     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d49f     DEC        EAX
    //         0040d4a0     CMP        EBX,EAX
    //         0040d4a2     JLE        LAB_0040d501
    //         0040d4a4     LEA        this,[EBX*0x4 + 0x4]
    //         0040d4ab     LEA        EBP,[EBX + 0x1]
    //         0040d4ae     PUSH       this
    //         0040d4af     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d4b4     MOV        EDI,EAX
    //         0040d4b6     ADD        ESP,0x4
    //         0040d4b9     TEST       EDI,EDI
    //         0040d4bb     JZ         LAB_0040d501
    //         0040d4bd     MOV        this,dword ptr [ESI + 0x100]
    //         0040d4c3     XOR        EAX,EAX
    //         0040d4c5     TEST       this,this
    //         0040d4c7     JLE        LAB_0040d4e6
    //                               LAB_0040d4c9                                                 XREF[1]:     0040d4e4(j)  
    //         0040d4c9     CMP        EAX,EBP
    //         0040d4cb     JGE        LAB_0040d4e6
    //         0040d4cd     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d4d3     INC        EAX
    //         0040d4d4     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d4d8     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d4dc     MOV        this,dword ptr [ESI + 0x100]
    //         0040d4e2     CMP        EAX,this
    //         0040d4e4     JL         LAB_0040d4c9
    //                               LAB_0040d4e6                                                 XREF[2]:     0040d4c7(j), 0040d4cb(j)  
    //         0040d4e6     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d4ec     PUSH       EDX
    //         0040d4ed     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d4f2     ADD        ESP,0x4
    //         0040d4f5     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d4fb     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040d501                                                 XREF[2]:     0040d4a2(j), 0040d4bb(j)  
    //         0040d501     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d507     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d50d     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040d510     PUSH       this
    //         0040d511     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d514     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040d519     MOV        EDI,EAX
    //                              aimdmod.cpp:141 (15)
    //         0040d51b     TEST       EDI,EDI
    //         0040d51d     JZ         LAB_0040d556
    //         0040d51f     MOV        this,EDI
    //         0040d521     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d526     TEST       EAX,EAX
    //         0040d528     JZ         LAB_0040d556
    //                              aimdmod.cpp:144 (40)
    //         0040d52a     MOV        this,EDI
    //         0040d52c     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d531     MOV        this,EAX
    //         0040d533     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040d538     CMP        EAX,dword ptr [ESP + param_1]
    //         0040d53c     JNZ        LAB_0040d556
    //         0040d53e     MOV        this,EDI
    //         0040d540     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d545     MOV        this,EAX
    //         0040d547     CALL       UnitAIModule::currentTarget                      int currentTarget(UnitAIModule * this)
    //         0040d54c     CMP        EAX,dword ptr [ESP + param_2]
    //         0040d550     JNZ        LAB_0040d556
    //                              aimdmod.cpp:145 (21)
    //         0040d552     INC        dword ptr [ESP + local_4]
    //                               LAB_0040d556                                                 XREF[4]:     0040d51d(j), 0040d528(j), 
    //                                                                                                         0040d53c(j), 0040d550(j)  
    //         0040d556     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d55c     INC        EBX
    //         0040d55d     CMP        EBX,EAX
    //         0040d55f     JL         LAB_0040d499
    //         0040d565     POP        EBP
    //         0040d566     POP        EDI
    //                               LAB_0040d567                                                 XREF[1]:     0040d491(j)  
    //                              aimdmod.cpp:147 (4)
    //         0040d567     MOV        EAX,dword ptr [ESP + local_4]
    //                              aimdmod.cpp:148 (6)
    //         0040d56b     POP        ESI
    //         0040d56c     POP        EBX
    //         0040d56d     POP        this
    //         0040d56e     RET        0x8
    //         0040d571     ??         90h
    //         0040d572     NOP
    //         0040d573     NOP
    //         0040d574     NOP
    //         0040d575     NOP
    //         0040d576     NOP
    //         0040d577     NOP
    //         0040d578     NOP
    //         0040d579     NOP
    //         0040d57a     NOP
    //         0040d57b     NOP
    //         0040d57c     NOP
    //         0040d57d     NOP
    //         0040d57e     NOP
    //         0040d57f     NOP
    return 0;
}

int MainDecisionAIModule::numberObjectsWithTargetType(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall numberObjectsWithTargetType(MainDecisionAIModule * th
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d638(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040d587(W), 0040d63e(RW), 0040d653(R)  
    //              int               Stack[-0x8]:4  count
    //                               ?numberObjectsWithTargetType@MainDecisionAIModule@@QAEHH@Z
    //                               MainDecisionAIModule::numberObjectsWithTargetType
    //                              aimdmod.cpp:153 (5)
    //         0040d580     PUSH       this
    //         0040d581     PUSH       EBX
    //         0040d582     PUSH       ESI
    //         0040d583     MOV        ESI,this
    //                              aimdmod.cpp:154 (6)
    //         0040d585     XOR        EBX,EBX
    //         0040d587     MOV        dword ptr [ESP + local_4],EBX
    //                              aimdmod.cpp:155 (14)
    //         0040d58b     CMP        dword ptr [ESI + 0xf8],EBX
    //         0040d591     JLE        LAB_0040d653
    //         0040d597     PUSH       EDI
    //         0040d598     PUSH       EBP
    //                               LAB_0040d599                                                 XREF[1]:     0040d64b(j)  
    //                              aimdmod.cpp:156 (130)
    //         0040d599     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d59f     DEC        EAX
    //         0040d5a0     CMP        EBX,EAX
    //         0040d5a2     JLE        LAB_0040d601
    //         0040d5a4     LEA        this,[EBX*0x4 + 0x4]
    //         0040d5ab     LEA        EBP,[EBX + 0x1]
    //         0040d5ae     PUSH       this
    //         0040d5af     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d5b4     MOV        EDI,EAX
    //         0040d5b6     ADD        ESP,0x4
    //         0040d5b9     TEST       EDI,EDI
    //         0040d5bb     JZ         LAB_0040d601
    //         0040d5bd     MOV        this,dword ptr [ESI + 0x100]
    //         0040d5c3     XOR        EAX,EAX
    //         0040d5c5     TEST       this,this
    //         0040d5c7     JLE        LAB_0040d5e6
    //                               LAB_0040d5c9                                                 XREF[1]:     0040d5e4(j)  
    //         0040d5c9     CMP        EAX,EBP
    //         0040d5cb     JGE        LAB_0040d5e6
    //         0040d5cd     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d5d3     INC        EAX
    //         0040d5d4     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d5d8     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d5dc     MOV        this,dword ptr [ESI + 0x100]
    //         0040d5e2     CMP        EAX,this
    //         0040d5e4     JL         LAB_0040d5c9
    //                               LAB_0040d5e6                                                 XREF[2]:     0040d5c7(j), 0040d5cb(j)  
    //         0040d5e6     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d5ec     PUSH       EDX
    //         0040d5ed     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d5f2     ADD        ESP,0x4
    //         0040d5f5     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d5fb     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040d601                                                 XREF[2]:     0040d5a2(j), 0040d5bb(j)  
    //         0040d601     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d607     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d60d     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040d610     PUSH       this
    //         0040d611     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d614     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040d619     MOV        EDI,EAX
    //                              aimdmod.cpp:157 (15)
    //         0040d61b     TEST       EDI,EDI
    //         0040d61d     JZ         LAB_0040d642
    //         0040d61f     MOV        this,EDI
    //         0040d621     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d626     TEST       EAX,EAX
    //         0040d628     JZ         LAB_0040d642
    //                              aimdmod.cpp:159 (20)
    //         0040d62a     MOV        this,EDI
    //         0040d62c     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d631     MOV        this,EAX
    //         0040d633     CALL       UnitAIModule::currentTargetType                  int currentTargetType(UnitAIModule * this)
    //         0040d638     CMP        EAX,dword ptr [ESP + param_1]
    //         0040d63c     JNZ        LAB_0040d642
    //                              aimdmod.cpp:160 (21)
    //         0040d63e     INC        dword ptr [ESP + local_4]
    //                               LAB_0040d642                                                 XREF[3]:     0040d61d(j), 0040d628(j), 
    //                                                                                                         0040d63c(j)  
    //         0040d642     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d648     INC        EBX
    //         0040d649     CMP        EBX,EAX
    //         0040d64b     JL         LAB_0040d599
    //         0040d651     POP        EBP
    //         0040d652     POP        EDI
    //                               LAB_0040d653                                                 XREF[1]:     0040d591(j)  
    //                              aimdmod.cpp:162 (4)
    //         0040d653     MOV        EAX,dword ptr [ESP + local_4]
    //                              aimdmod.cpp:163 (6)
    //         0040d657     POP        ESI
    //         0040d658     POP        EBX
    //         0040d659     POP        this
    //         0040d65a     RET        0x4
    //         0040d65d     ??         90h
    //         0040d65e     NOP
    //         0040d65f     NOP
    return 0;
}

int MainDecisionAIModule::numberObjectsWithActionAndTargetType(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall numberObjectsWithActionAndTargetType(MainDecisionAIMo
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d718(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040d72c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040d667(W), 0040d732(RW), 0040d747(R)  
    //              int               Stack[-0x8]:4  count
    //                               ?numberObjectsWithActionAndTargetType@MainDecisionAIModule@
    //                               MainDecisionAIModule::numberObjectsWithActionAndTargetType
    //                              aimdmod.cpp:169 (5)
    //         0040d660     PUSH       this
    //         0040d661     PUSH       EBX
    //         0040d662     PUSH       ESI
    //         0040d663     MOV        ESI,this
    //                              aimdmod.cpp:170 (6)
    //         0040d665     XOR        EBX,EBX
    //         0040d667     MOV        dword ptr [ESP + local_4],EBX
    //                              aimdmod.cpp:171 (14)
    //         0040d66b     CMP        dword ptr [ESI + 0xf8],EBX
    //         0040d671     JLE        LAB_0040d747
    //         0040d677     PUSH       EDI
    //         0040d678     PUSH       EBP
    //                               LAB_0040d679                                                 XREF[1]:     0040d73f(j)  
    //                              aimdmod.cpp:172 (130)
    //         0040d679     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d67f     DEC        EAX
    //         0040d680     CMP        EBX,EAX
    //         0040d682     JLE        LAB_0040d6e1
    //         0040d684     LEA        this,[EBX*0x4 + 0x4]
    //         0040d68b     LEA        EBP,[EBX + 0x1]
    //         0040d68e     PUSH       this
    //         0040d68f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d694     MOV        EDI,EAX
    //         0040d696     ADD        ESP,0x4
    //         0040d699     TEST       EDI,EDI
    //         0040d69b     JZ         LAB_0040d6e1
    //         0040d69d     MOV        this,dword ptr [ESI + 0x100]
    //         0040d6a3     XOR        EAX,EAX
    //         0040d6a5     TEST       this,this
    //         0040d6a7     JLE        LAB_0040d6c6
    //                               LAB_0040d6a9                                                 XREF[1]:     0040d6c4(j)  
    //         0040d6a9     CMP        EAX,EBP
    //         0040d6ab     JGE        LAB_0040d6c6
    //         0040d6ad     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d6b3     INC        EAX
    //         0040d6b4     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d6b8     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d6bc     MOV        this,dword ptr [ESI + 0x100]
    //         0040d6c2     CMP        EAX,this
    //         0040d6c4     JL         LAB_0040d6a9
    //                               LAB_0040d6c6                                                 XREF[2]:     0040d6a7(j), 0040d6ab(j)  
    //         0040d6c6     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d6cc     PUSH       EDX
    //         0040d6cd     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d6d2     ADD        ESP,0x4
    //         0040d6d5     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d6db     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040d6e1                                                 XREF[2]:     0040d682(j), 0040d69b(j)  
    //         0040d6e1     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d6e7     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d6ed     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040d6f0     PUSH       this
    //         0040d6f1     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d6f4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040d6f9     MOV        EDI,EAX
    //                              aimdmod.cpp:173 (15)
    //         0040d6fb     TEST       EDI,EDI
    //         0040d6fd     JZ         LAB_0040d736
    //         0040d6ff     MOV        this,EDI
    //         0040d701     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d706     TEST       EAX,EAX
    //         0040d708     JZ         LAB_0040d736
    //                              aimdmod.cpp:176 (40)
    //         0040d70a     MOV        this,EDI
    //         0040d70c     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d711     MOV        this,EAX
    //         0040d713     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040d718     CMP        EAX,dword ptr [ESP + param_1]
    //         0040d71c     JNZ        LAB_0040d736
    //         0040d71e     MOV        this,EDI
    //         0040d720     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d725     MOV        this,EAX
    //         0040d727     CALL       UnitAIModule::currentTargetType                  int currentTargetType(UnitAIModule * this)
    //         0040d72c     CMP        EAX,dword ptr [ESP + param_2]
    //         0040d730     JNZ        LAB_0040d736
    //                              aimdmod.cpp:177 (21)
    //         0040d732     INC        dword ptr [ESP + local_4]
    //                               LAB_0040d736                                                 XREF[4]:     0040d6fd(j), 0040d708(j), 
    //                                                                                                         0040d71c(j), 0040d730(j)  
    //         0040d736     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d73c     INC        EBX
    //         0040d73d     CMP        EBX,EAX
    //         0040d73f     JL         LAB_0040d679
    //         0040d745     POP        EBP
    //         0040d746     POP        EDI
    //                               LAB_0040d747                                                 XREF[1]:     0040d671(j)  
    //                              aimdmod.cpp:179 (4)
    //         0040d747     MOV        EAX,dword ptr [ESP + local_4]
    //                              aimdmod.cpp:180 (6)
    //         0040d74b     POP        ESI
    //         0040d74c     POP        EBX
    //         0040d74d     POP        this
    //         0040d74e     RET        0x8
    //         0040d751     ??         90h
    //         0040d752     NOP
    //         0040d753     NOP
    //         0040d754     NOP
    //         0040d755     NOP
    //         0040d756     NOP
    //         0040d757     NOP
    //         0040d758     NOP
    //         0040d759     NOP
    //         0040d75a     NOP
    //         0040d75b     NOP
    //         0040d75c     NOP
    //         0040d75d     NOP
    //         0040d75e     NOP
    //         0040d75f     NOP
    return 0;
}

RGE_Static_Object* MainDecisionAIModule::object(int param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall object(MainDecisionAIModule * this, i
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d766(R)  
    //                               ?object@MainDecisionAIModule@@QAEPAVRGE_Static_Object@@H@Z   XREF[168]:   addImportantObject:004daf8e(c), 
    //                               MainDecisionAIModule::object                                              objectToAttack:004dc791(c), 
    //                                                                                                         objectToAttack:004dc86f(c), 
    //                                                                                                         setupInfluenceMap:004defc0(c), 
    //                                                                                                         setupInfluenceMap:004df435(c), 
    //                                                                                                         findObjectMemoryLimits:004dfd9f(c)
    //                                                                                                         findObjectMemoryLimits:004dfdf5(c)
    //                                                                                                         findObjectMemoryLimits:004dfe62(c)
    //                                                                                                         findClosestDropsite:004e2ab6(c), 
    //                                                                                                         updateAllResourceDropsites:004e2d5
    //                                                                                                         damagePerSecond:004e33a9(c), 
    //                                                                                                         damagePerSecond:004e340e(c), 
    //                                                                                                         wonderToAttack:004e36d3(c), 
    //                                                                                                         numberAvailableGranaries:004e3fca(
    //                                                                                                         currentHitPoints:004eb44c(c), 
    //                                                                                                         isGathered:004ecd9f(c), 
    //                                                                                                         allUnitsIdle:004ecf31(c), 
    //                                                                                                         taskWaterFisher:004fb171(c), 
    //                                                                                                         removeFromTaskLists:004fbba1(c), 
    //                                                                                                         displayBoatGroups:0050018f(c), 
    //                                                                                                         [more]
    //                              aimdmod.cpp:185 (19)
    //         0040d760     MOV        this,dword ptr [ECX + this->player]
    //         0040d766     MOV        EAX,dword ptr [ESP + param_1]
    //         0040d76a     PUSH       EAX
    //         0040d76b     MOV        this,dword ptr [ECX + this->_padding_]
    //         0040d76e     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              aimdmod.cpp:187 (3)
    //         0040d773     RET        0x4
    //         0040d776     ??         90h
    //         0040d777     NOP
    //         0040d778     NOP
    //         0040d779     NOP
    //         0040d77a     NOP
    //         0040d77b     NOP
    //         0040d77c     NOP
    //         0040d77d     NOP
    //         0040d77e     NOP
    //         0040d77f     NOP
    //                              * public: class RGE_Static_Object * __thiscall MainDecisionAIModule::object(int,int,int,int,int,int,... *
    //                              RGE_Static_Object * __thiscall object(MainDecisionAIModule * this, i
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d83a(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040d84c(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040d864(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040d87c(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0040d89b(R), 0040d912(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0040d930(R)  
    //              int               Stack[0x1c]:4  param_7
    //              int               Stack[0x20]:4  param_8
    //              int               Stack[0x24]:4  param_9
    //              int               Stack[0x28]:4  param_10
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0040d78f(W), 0040d8ac(R), 0040d91f(R), 0040d98d(R), 
    //                                                                                     0040d99a(W)  
    //              int               Stack[-0x8]:4  i
    //                               ?object@MainDecisionAIModule@@QAEPAVRGE_Static_Object@@HHHH  XREF[28]:    nextBuildableItem:004d4d73(c), 
    //                               MainDecisionAIModule::object                                              placeStructure:004d6275(c), 
    //                                                                                                         influencePlaceStructure:004db2cf(c
    //                                                                                                         influencePlaceStructure:004db3d9(c
    //                                                                                                         ruinToCapture:004e3862(c), 
    //                                                                                                         artifactToCapture:004e39f1(c), 
    //                                                                                                         numberAvailableStoragePits:004e3ee
    //                                                                                                         numberAvailableGranaries:004e3fb2(
    //                                                                                                         taskCivilians:004f166e(c), 
    //                                                                                                         taskCivilians:004f1701(c), 
    //                                                                                                         taskCivilians:004f1726(c), 
    //                                                                                                         taskCivilians:004f191f(c), 
    //                                                                                                         taskIdleSoldiers:004f1f44(c), 
    //                                                                                                         taskActiveSoldiers:004f2394(c), 
    //                                                                                                         taskActiveSoldiers:004f36ba(c), 
    //                                                                                                         taskUngroupedSoldiers:004f4af1(c), 
    //                                                                                                         notify:004f6846(c), 
    //                                                                                                         setGatherLocation:00500c1e(c), 
    //                                                                                                         setAllGroupLocations:00500d3e(c), 
    //                                                                                                         unexploredArea:005016e0(c), [more]
    //                              aimdmod.cpp:194 (6)
    //         0040d780     PUSH       this
    //         0040d781     PUSH       EBX
    //         0040d782     PUSH       EBP
    //         0040d783     PUSH       ESI
    //         0040d784     MOV        ESI,this
    //                              aimdmod.cpp:195 (27)
    //         0040d786     XOR        EBP,EBP
    //         0040d788     PUSH       EDI
    //         0040d789     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d78f     MOV        dword ptr [ESP + local_4],EBP
    //         0040d793     TEST       EAX,EAX
    //         0040d795     JLE        LAB_0040d9b8
    //         0040d79b     JMP        LAB_0040d7a1
    //                               LAB_0040d79d                                                 XREF[1]:     0040d99e(j)  
    //         0040d79d     MOV        EBP,dword ptr [ESP + 0x10]
    //                               LAB_0040d7a1                                                 XREF[1]:     0040d79b(j)  
    //                              aimdmod.cpp:196 (130)
    //         0040d7a1     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d7a7     DEC        EAX
    //         0040d7a8     CMP        EBP,EAX
    //         0040d7aa     JLE        LAB_0040d809
    //         0040d7ac     LEA        this,[EBP*0x4 + 0x4]
    //         0040d7b3     LEA        EBX,[EBP + 0x1]
    //         0040d7b6     PUSH       this
    //         0040d7b7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d7bc     MOV        EDI,EAX
    //         0040d7be     ADD        ESP,0x4
    //         0040d7c1     TEST       EDI,EDI
    //         0040d7c3     JZ         LAB_0040d809
    //         0040d7c5     MOV        this,dword ptr [ESI + 0x100]
    //         0040d7cb     XOR        EAX,EAX
    //         0040d7cd     TEST       this,this
    //         0040d7cf     JLE        LAB_0040d7ee
    //                               LAB_0040d7d1                                                 XREF[1]:     0040d7ec(j)  
    //         0040d7d1     CMP        EAX,EBX
    //         0040d7d3     JGE        LAB_0040d7ee
    //         0040d7d5     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d7db     INC        EAX
    //         0040d7dc     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d7e0     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d7e4     MOV        this,dword ptr [ESI + 0x100]
    //         0040d7ea     CMP        EAX,this
    //         0040d7ec     JL         LAB_0040d7d1
    //                               LAB_0040d7ee                                                 XREF[2]:     0040d7cf(j), 0040d7d3(j)  
    //         0040d7ee     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d7f4     PUSH       EDX
    //         0040d7f5     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d7fa     ADD        ESP,0x4
    //         0040d7fd     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d803     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040d809                                                 XREF[2]:     0040d7aa(j), 0040d7c3(j)  
    //         0040d809     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d80f     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d815     MOV        this,dword ptr [EAX + EBP*0x4]
    //         0040d818     PUSH       this
    //         0040d819     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d81c     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040d821     MOV        EBP,EAX
    //                              aimdmod.cpp:197 (23)
    //         0040d823     TEST       EBP,EBP
    //         0040d825     JZ         LAB_0040d98d
    //         0040d82b     MOV        this,EBP
    //         0040d82d     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d832     TEST       EAX,EAX
    //         0040d834     JZ         LAB_0040d98d
    //                              aimdmod.cpp:207 (339)
    //         0040d83a     MOV        EAX,dword ptr [ESP + param_1]
    //         0040d83e     CMP        EAX,-0x1
    //         0040d841     JZ         LAB_0040d84c
    //         0040d843     CMP        dword ptr [EBP + 0x4],EAX
    //         0040d846     JNZ        LAB_0040d98d
    //                               LAB_0040d84c                                                 XREF[1]:     0040d841(j)  
    //         0040d84c     MOV        EAX,dword ptr [ESP + param_2]
    //         0040d850     CMP        EAX,-0x1
    //         0040d853     JZ         LAB_0040d864
    //         0040d855     MOV        this,dword ptr [EBP + 0x8]
    //         0040d858     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040d85c     CMP        EDX,EAX
    //         0040d85e     JNZ        LAB_0040d98d
    //                               LAB_0040d864                                                 XREF[1]:     0040d853(j)  
    //         0040d864     MOV        EAX,dword ptr [ESP + param_3]
    //         0040d868     CMP        EAX,-0x1
    //         0040d86b     JZ         LAB_0040d87c
    //         0040d86d     MOV        this,dword ptr [EBP + 0x8]
    //         0040d870     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040d874     CMP        EDX,EAX
    //         0040d876     JNZ        LAB_0040d98d
    //                               LAB_0040d87c                                                 XREF[1]:     0040d86b(j)  
    //         0040d87c     MOV        EDI,dword ptr [ESP + param_4]
    //         0040d880     CMP        EDI,-0x1
    //         0040d883     JZ         LAB_0040d89b
    //         0040d885     MOV        this,EBP
    //         0040d887     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d88c     MOV        this,EAX
    //         0040d88e     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040d893     CMP        EAX,EDI
    //         0040d895     JNZ        LAB_0040d98d
    //                               LAB_0040d89b                                                 XREF[1]:     0040d883(j)  
    //         0040d89b     CMP        dword ptr [ESP + param_5],-0x1
    //         0040d8a0     JZ         LAB_0040d930
    //         0040d8a6     MOV        this,dword ptr [ESI + 0x100]
    //         0040d8ac     MOV        EAX,dword ptr [ESP + local_4]
    //         0040d8b0     DEC        this
    //         0040d8b1     CMP        EAX,this
    //         0040d8b3     JLE        LAB_0040d912
    //         0040d8b5     LEA        EDX,[EAX*0x4 + 0x4]
    //         0040d8bc     LEA        EBX,[EAX + 0x1]
    //         0040d8bf     PUSH       EDX
    //         0040d8c0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d8c5     MOV        EDI,EAX
    //         0040d8c7     ADD        ESP,0x4
    //         0040d8ca     TEST       EDI,EDI
    //         0040d8cc     JZ         LAB_0040d912
    //         0040d8ce     MOV        this,dword ptr [ESI + 0x100]
    //         0040d8d4     XOR        EAX,EAX
    //         0040d8d6     TEST       this,this
    //         0040d8d8     JLE        LAB_0040d8f7
    //                               LAB_0040d8da                                                 XREF[1]:     0040d8f5(j)  
    //         0040d8da     CMP        EAX,EBX
    //         0040d8dc     JGE        LAB_0040d8f7
    //         0040d8de     MOV        this,dword ptr [ESI + 0xf4]
    //         0040d8e4     INC        EAX
    //         0040d8e5     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         0040d8e9     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         0040d8ed     MOV        this,dword ptr [ESI + 0x100]
    //         0040d8f3     CMP        EAX,this
    //         0040d8f5     JL         LAB_0040d8da
    //                               LAB_0040d8f7                                                 XREF[2]:     0040d8d8(j), 0040d8dc(j)  
    //         0040d8f7     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d8fd     PUSH       EAX
    //         0040d8fe     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d903     ADD        ESP,0x4
    //         0040d906     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d90c     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040d912                                                 XREF[2]:     0040d8b3(j), 0040d8cc(j)  
    //         0040d912     MOV        EAX,dword ptr [ESP + param_5]
    //         0040d916     MOV        this,dword ptr [ESI + 0xf4]
    //         0040d91c     MOV        EDX,dword ptr [ESI]
    //         0040d91e     PUSH       EAX
    //         0040d91f     MOV        EAX,dword ptr [ESP + local_4]
    //         0040d923     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0040d926     PUSH       this
    //         0040d927     MOV        this,ESI
    //         0040d929     CALL       dword ptr [EDX + 0x4c]
    //         0040d92c     TEST       EAX,EAX
    //         0040d92e     JZ         LAB_0040d98d
    //                               LAB_0040d930                                                 XREF[1]:     0040d8a0(j)  
    //         0040d930     MOV        EDI,dword ptr [ESP + param_6]
    //         0040d934     CMP        EDI,-0x1
    //         0040d937     JZ         LAB_0040d94b
    //         0040d939     MOV        this,EBP
    //         0040d93b     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d940     MOV        this,EAX
    //         0040d942     CALL       UnitAIModule::currentTarget                      int currentTarget(UnitAIModule * this)
    //         0040d947     CMP        EAX,EDI
    //         0040d949     JNZ        LAB_0040d98d
    //                               LAB_0040d94b                                                 XREF[1]:     0040d937(j)  
    //         0040d94b     MOV        EDI,dword ptr [ESP + 0x30]
    //         0040d94f     CMP        EDI,-0x1
    //         0040d952     JZ         LAB_0040d966
    //         0040d954     MOV        this,EBP
    //         0040d956     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d95b     MOV        this,EAX
    //         0040d95d     CALL       UnitAIModule::currentTargetType                  int currentTargetType(UnitAIModule * this)
    //         0040d962     CMP        EAX,EDI
    //         0040d964     JNZ        LAB_0040d98d
    //                               LAB_0040d966                                                 XREF[1]:     0040d952(j)  
    //         0040d966     MOV        EAX,dword ptr [ESP + 0x38]
    //         0040d96a     CMP        EAX,-0x1
    //         0040d96d     JZ         LAB_0040d978
    //         0040d96f     XOR        EDX,EDX
    //         0040d971     MOV        DL,byte ptr [EBP + 0x48]
    //         0040d974     CMP        EDX,EAX
    //         0040d976     JNZ        LAB_0040d98d
    //                               LAB_0040d978                                                 XREF[1]:     0040d96d(j)  
    //         0040d978     CMP        dword ptr [ESP + 0x3c],-0x1
    //         0040d97d     JZ         LAB_0040d9ae
    //         0040d97f     FILD       dword ptr [ESP + 0x3c]
    //         0040d983     FCOMP      float ptr [EBP + 0x44]
    //         0040d986     FNSTSW     AX
    //         0040d988     TEST       AH,0x1
    //         0040d98b     JZ         LAB_0040d9ae
    //                               LAB_0040d98d                                                 XREF[10]:    0040d825(j), 0040d834(j), 
    //                                                                                                         0040d846(j), 0040d85e(j), 
    //                                                                                                         0040d876(j), 0040d895(j), 
    //                                                                                                         0040d92e(j), 0040d949(j), 
    //                                                                                                         0040d964(j), 0040d976(j)  
    //                              aimdmod.cpp:195 (23)
    //         0040d98d     MOV        EAX,dword ptr [ESP + local_4]
    //         0040d991     MOV        this,dword ptr [ESI + 0xf8]
    //         0040d997     INC        EAX
    //         0040d998     CMP        EAX,this
    //         0040d99a     MOV        dword ptr [ESP + local_4],EAX
    //         0040d99e     JL         LAB_0040d79d
    //                              aimdmod.cpp:212 (2)
    //         0040d9a4     XOR        EAX,EAX
    //                              aimdmod.cpp:213 (8)
    //         0040d9a6     POP        EDI
    //         0040d9a7     POP        ESI
    //         0040d9a8     POP        EBP
    //         0040d9a9     POP        EBX
    //         0040d9aa     POP        this
    //         0040d9ab     RET        0x28
    //                               LAB_0040d9ae                                                 XREF[2]:     0040d97d(j), 0040d98b(j)  
    //                              aimdmod.cpp:210 (2)
    //         0040d9ae     MOV        EAX,EBP
    //                              aimdmod.cpp:213 (18)
    //         0040d9b0     POP        EDI
    //         0040d9b1     POP        ESI
    //         0040d9b2     POP        EBP
    //         0040d9b3     POP        EBX
    //         0040d9b4     POP        this
    //         0040d9b5     RET        0x28
    //                               LAB_0040d9b8                                                 XREF[1]:     0040d795(j)  
    //         0040d9b8     POP        EDI
    //         0040d9b9     POP        ESI
    //         0040d9ba     POP        EBP
    //         0040d9bb     XOR        EAX,EAX
    //         0040d9bd     POP        EBX
    //         0040d9be     POP        this
    //         0040d9bf     RET        0x28
    //         0040d9c2     ??         90h
    //         0040d9c3     NOP
    //         0040d9c4     NOP
    //         0040d9c5     NOP
    //         0040d9c6     NOP
    //         0040d9c7     NOP
    //         0040d9c8     NOP
    //         0040d9c9     NOP
    //         0040d9ca     NOP
    //         0040d9cb     NOP
    //         0040d9cc     NOP
    //         0040d9cd     NOP
    //         0040d9ce     NOP
    //         0040d9cf     NOP
    return 0;
}

RGE_Static_Object* MainDecisionAIModule::object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall object(MainDecisionAIModule * this, i
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d766(R)  
    //                               ?object@MainDecisionAIModule@@QAEPAVRGE_Static_Object@@H@Z   XREF[168]:   addImportantObject:004daf8e(c), 
    //                               MainDecisionAIModule::object                                              objectToAttack:004dc791(c), 
    //                                                                                                         objectToAttack:004dc86f(c), 
    //                                                                                                         setupInfluenceMap:004defc0(c), 
    //                                                                                                         setupInfluenceMap:004df435(c), 
    //                                                                                                         findObjectMemoryLimits:004dfd9f(c)
    //                                                                                                         findObjectMemoryLimits:004dfdf5(c)
    //                                                                                                         findObjectMemoryLimits:004dfe62(c)
    //                                                                                                         findClosestDropsite:004e2ab6(c), 
    //                                                                                                         updateAllResourceDropsites:004e2d5
    //                                                                                                         damagePerSecond:004e33a9(c), 
    //                                                                                                         damagePerSecond:004e340e(c), 
    //                                                                                                         wonderToAttack:004e36d3(c), 
    //                                                                                                         numberAvailableGranaries:004e3fca(
    //                                                                                                         currentHitPoints:004eb44c(c), 
    //                                                                                                         isGathered:004ecd9f(c), 
    //                                                                                                         allUnitsIdle:004ecf31(c), 
    //                                                                                                         taskWaterFisher:004fb171(c), 
    //                                                                                                         removeFromTaskLists:004fbba1(c), 
    //                                                                                                         displayBoatGroups:0050018f(c), 
    //                                                                                                         [more]
    //                              aimdmod.cpp:185 (19)
    //         0040d760     MOV        this,dword ptr [ECX + this->player]
    //         0040d766     MOV        EAX,dword ptr [ESP + param_1]
    //         0040d76a     PUSH       EAX
    //         0040d76b     MOV        this,dword ptr [ECX + this->_padding_]
    //         0040d76e     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              aimdmod.cpp:187 (3)
    //         0040d773     RET        0x4
    //         0040d776     ??         90h
    //         0040d777     NOP
    //         0040d778     NOP
    //         0040d779     NOP
    //         0040d77a     NOP
    //         0040d77b     NOP
    //         0040d77c     NOP
    //         0040d77d     NOP
    //         0040d77e     NOP
    //         0040d77f     NOP
    //                              * public: class RGE_Static_Object * __thiscall MainDecisionAIModule::object(int,int,int,int,int,int,... *
    //                              RGE_Static_Object * __thiscall object(MainDecisionAIModule * this, i
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040d83a(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040d84c(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040d864(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040d87c(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0040d89b(R), 0040d912(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0040d930(R)  
    //              int               Stack[0x1c]:4  param_7
    //              int               Stack[0x20]:4  param_8
    //              int               Stack[0x24]:4  param_9
    //              int               Stack[0x28]:4  param_10
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0040d78f(W), 0040d8ac(R), 0040d91f(R), 0040d98d(R), 
    //                                                                                     0040d99a(W)  
    //              int               Stack[-0x8]:4  i
    //                               ?object@MainDecisionAIModule@@QAEPAVRGE_Static_Object@@HHHH  XREF[28]:    nextBuildableItem:004d4d73(c), 
    //                               MainDecisionAIModule::object                                              placeStructure:004d6275(c), 
    //                                                                                                         influencePlaceStructure:004db2cf(c
    //                                                                                                         influencePlaceStructure:004db3d9(c
    //                                                                                                         ruinToCapture:004e3862(c), 
    //                                                                                                         artifactToCapture:004e39f1(c), 
    //                                                                                                         numberAvailableStoragePits:004e3ee
    //                                                                                                         numberAvailableGranaries:004e3fb2(
    //                                                                                                         taskCivilians:004f166e(c), 
    //                                                                                                         taskCivilians:004f1701(c), 
    //                                                                                                         taskCivilians:004f1726(c), 
    //                                                                                                         taskCivilians:004f191f(c), 
    //                                                                                                         taskIdleSoldiers:004f1f44(c), 
    //                                                                                                         taskActiveSoldiers:004f2394(c), 
    //                                                                                                         taskActiveSoldiers:004f36ba(c), 
    //                                                                                                         taskUngroupedSoldiers:004f4af1(c), 
    //                                                                                                         notify:004f6846(c), 
    //                                                                                                         setGatherLocation:00500c1e(c), 
    //                                                                                                         setAllGroupLocations:00500d3e(c), 
    //                                                                                                         unexploredArea:005016e0(c), [more]
    //                              aimdmod.cpp:194 (6)
    //         0040d780     PUSH       this
    //         0040d781     PUSH       EBX
    //         0040d782     PUSH       EBP
    //         0040d783     PUSH       ESI
    //         0040d784     MOV        ESI,this
    //                              aimdmod.cpp:195 (27)
    //         0040d786     XOR        EBP,EBP
    //         0040d788     PUSH       EDI
    //         0040d789     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d78f     MOV        dword ptr [ESP + local_4],EBP
    //         0040d793     TEST       EAX,EAX
    //         0040d795     JLE        LAB_0040d9b8
    //         0040d79b     JMP        LAB_0040d7a1
    //                               LAB_0040d79d                                                 XREF[1]:     0040d99e(j)  
    //         0040d79d     MOV        EBP,dword ptr [ESP + 0x10]
    //                               LAB_0040d7a1                                                 XREF[1]:     0040d79b(j)  
    //                              aimdmod.cpp:196 (130)
    //         0040d7a1     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d7a7     DEC        EAX
    //         0040d7a8     CMP        EBP,EAX
    //         0040d7aa     JLE        LAB_0040d809
    //         0040d7ac     LEA        this,[EBP*0x4 + 0x4]
    //         0040d7b3     LEA        EBX,[EBP + 0x1]
    //         0040d7b6     PUSH       this
    //         0040d7b7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d7bc     MOV        EDI,EAX
    //         0040d7be     ADD        ESP,0x4
    //         0040d7c1     TEST       EDI,EDI
    //         0040d7c3     JZ         LAB_0040d809
    //         0040d7c5     MOV        this,dword ptr [ESI + 0x100]
    //         0040d7cb     XOR        EAX,EAX
    //         0040d7cd     TEST       this,this
    //         0040d7cf     JLE        LAB_0040d7ee
    //                               LAB_0040d7d1                                                 XREF[1]:     0040d7ec(j)  
    //         0040d7d1     CMP        EAX,EBX
    //         0040d7d3     JGE        LAB_0040d7ee
    //         0040d7d5     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d7db     INC        EAX
    //         0040d7dc     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040d7e0     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040d7e4     MOV        this,dword ptr [ESI + 0x100]
    //         0040d7ea     CMP        EAX,this
    //         0040d7ec     JL         LAB_0040d7d1
    //                               LAB_0040d7ee                                                 XREF[2]:     0040d7cf(j), 0040d7d3(j)  
    //         0040d7ee     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040d7f4     PUSH       EDX
    //         0040d7f5     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d7fa     ADD        ESP,0x4
    //         0040d7fd     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d803     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040d809                                                 XREF[2]:     0040d7aa(j), 0040d7c3(j)  
    //         0040d809     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d80f     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040d815     MOV        this,dword ptr [EAX + EBP*0x4]
    //         0040d818     PUSH       this
    //         0040d819     MOV        this,dword ptr [EDX + 0x3c]
    //         0040d81c     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040d821     MOV        EBP,EAX
    //                              aimdmod.cpp:197 (23)
    //         0040d823     TEST       EBP,EBP
    //         0040d825     JZ         LAB_0040d98d
    //         0040d82b     MOV        this,EBP
    //         0040d82d     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d832     TEST       EAX,EAX
    //         0040d834     JZ         LAB_0040d98d
    //                              aimdmod.cpp:207 (339)
    //         0040d83a     MOV        EAX,dword ptr [ESP + param_1]
    //         0040d83e     CMP        EAX,-0x1
    //         0040d841     JZ         LAB_0040d84c
    //         0040d843     CMP        dword ptr [EBP + 0x4],EAX
    //         0040d846     JNZ        LAB_0040d98d
    //                               LAB_0040d84c                                                 XREF[1]:     0040d841(j)  
    //         0040d84c     MOV        EAX,dword ptr [ESP + param_2]
    //         0040d850     CMP        EAX,-0x1
    //         0040d853     JZ         LAB_0040d864
    //         0040d855     MOV        this,dword ptr [EBP + 0x8]
    //         0040d858     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040d85c     CMP        EDX,EAX
    //         0040d85e     JNZ        LAB_0040d98d
    //                               LAB_0040d864                                                 XREF[1]:     0040d853(j)  
    //         0040d864     MOV        EAX,dword ptr [ESP + param_3]
    //         0040d868     CMP        EAX,-0x1
    //         0040d86b     JZ         LAB_0040d87c
    //         0040d86d     MOV        this,dword ptr [EBP + 0x8]
    //         0040d870     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040d874     CMP        EDX,EAX
    //         0040d876     JNZ        LAB_0040d98d
    //                               LAB_0040d87c                                                 XREF[1]:     0040d86b(j)  
    //         0040d87c     MOV        EDI,dword ptr [ESP + param_4]
    //         0040d880     CMP        EDI,-0x1
    //         0040d883     JZ         LAB_0040d89b
    //         0040d885     MOV        this,EBP
    //         0040d887     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d88c     MOV        this,EAX
    //         0040d88e     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040d893     CMP        EAX,EDI
    //         0040d895     JNZ        LAB_0040d98d
    //                               LAB_0040d89b                                                 XREF[1]:     0040d883(j)  
    //         0040d89b     CMP        dword ptr [ESP + param_5],-0x1
    //         0040d8a0     JZ         LAB_0040d930
    //         0040d8a6     MOV        this,dword ptr [ESI + 0x100]
    //         0040d8ac     MOV        EAX,dword ptr [ESP + local_4]
    //         0040d8b0     DEC        this
    //         0040d8b1     CMP        EAX,this
    //         0040d8b3     JLE        LAB_0040d912
    //         0040d8b5     LEA        EDX,[EAX*0x4 + 0x4]
    //         0040d8bc     LEA        EBX,[EAX + 0x1]
    //         0040d8bf     PUSH       EDX
    //         0040d8c0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040d8c5     MOV        EDI,EAX
    //         0040d8c7     ADD        ESP,0x4
    //         0040d8ca     TEST       EDI,EDI
    //         0040d8cc     JZ         LAB_0040d912
    //         0040d8ce     MOV        this,dword ptr [ESI + 0x100]
    //         0040d8d4     XOR        EAX,EAX
    //         0040d8d6     TEST       this,this
    //         0040d8d8     JLE        LAB_0040d8f7
    //                               LAB_0040d8da                                                 XREF[1]:     0040d8f5(j)  
    //         0040d8da     CMP        EAX,EBX
    //         0040d8dc     JGE        LAB_0040d8f7
    //         0040d8de     MOV        this,dword ptr [ESI + 0xf4]
    //         0040d8e4     INC        EAX
    //         0040d8e5     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         0040d8e9     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         0040d8ed     MOV        this,dword ptr [ESI + 0x100]
    //         0040d8f3     CMP        EAX,this
    //         0040d8f5     JL         LAB_0040d8da
    //                               LAB_0040d8f7                                                 XREF[2]:     0040d8d8(j), 0040d8dc(j)  
    //         0040d8f7     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040d8fd     PUSH       EAX
    //         0040d8fe     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040d903     ADD        ESP,0x4
    //         0040d906     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040d90c     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040d912                                                 XREF[2]:     0040d8b3(j), 0040d8cc(j)  
    //         0040d912     MOV        EAX,dword ptr [ESP + param_5]
    //         0040d916     MOV        this,dword ptr [ESI + 0xf4]
    //         0040d91c     MOV        EDX,dword ptr [ESI]
    //         0040d91e     PUSH       EAX
    //         0040d91f     MOV        EAX,dword ptr [ESP + local_4]
    //         0040d923     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0040d926     PUSH       this
    //         0040d927     MOV        this,ESI
    //         0040d929     CALL       dword ptr [EDX + 0x4c]
    //         0040d92c     TEST       EAX,EAX
    //         0040d92e     JZ         LAB_0040d98d
    //                               LAB_0040d930                                                 XREF[1]:     0040d8a0(j)  
    //         0040d930     MOV        EDI,dword ptr [ESP + param_6]
    //         0040d934     CMP        EDI,-0x1
    //         0040d937     JZ         LAB_0040d94b
    //         0040d939     MOV        this,EBP
    //         0040d93b     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d940     MOV        this,EAX
    //         0040d942     CALL       UnitAIModule::currentTarget                      int currentTarget(UnitAIModule * this)
    //         0040d947     CMP        EAX,EDI
    //         0040d949     JNZ        LAB_0040d98d
    //                               LAB_0040d94b                                                 XREF[1]:     0040d937(j)  
    //         0040d94b     MOV        EDI,dword ptr [ESP + 0x30]
    //         0040d94f     CMP        EDI,-0x1
    //         0040d952     JZ         LAB_0040d966
    //         0040d954     MOV        this,EBP
    //         0040d956     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040d95b     MOV        this,EAX
    //         0040d95d     CALL       UnitAIModule::currentTargetType                  int currentTargetType(UnitAIModule * this)
    //         0040d962     CMP        EAX,EDI
    //         0040d964     JNZ        LAB_0040d98d
    //                               LAB_0040d966                                                 XREF[1]:     0040d952(j)  
    //         0040d966     MOV        EAX,dword ptr [ESP + 0x38]
    //         0040d96a     CMP        EAX,-0x1
    //         0040d96d     JZ         LAB_0040d978
    //         0040d96f     XOR        EDX,EDX
    //         0040d971     MOV        DL,byte ptr [EBP + 0x48]
    //         0040d974     CMP        EDX,EAX
    //         0040d976     JNZ        LAB_0040d98d
    //                               LAB_0040d978                                                 XREF[1]:     0040d96d(j)  
    //         0040d978     CMP        dword ptr [ESP + 0x3c],-0x1
    //         0040d97d     JZ         LAB_0040d9ae
    //         0040d97f     FILD       dword ptr [ESP + 0x3c]
    //         0040d983     FCOMP      float ptr [EBP + 0x44]
    //         0040d986     FNSTSW     AX
    //         0040d988     TEST       AH,0x1
    //         0040d98b     JZ         LAB_0040d9ae
    //                               LAB_0040d98d                                                 XREF[10]:    0040d825(j), 0040d834(j), 
    //                                                                                                         0040d846(j), 0040d85e(j), 
    //                                                                                                         0040d876(j), 0040d895(j), 
    //                                                                                                         0040d92e(j), 0040d949(j), 
    //                                                                                                         0040d964(j), 0040d976(j)  
    //                              aimdmod.cpp:195 (23)
    //         0040d98d     MOV        EAX,dword ptr [ESP + local_4]
    //         0040d991     MOV        this,dword ptr [ESI + 0xf8]
    //         0040d997     INC        EAX
    //         0040d998     CMP        EAX,this
    //         0040d99a     MOV        dword ptr [ESP + local_4],EAX
    //         0040d99e     JL         LAB_0040d79d
    //                              aimdmod.cpp:212 (2)
    //         0040d9a4     XOR        EAX,EAX
    //                              aimdmod.cpp:213 (8)
    //         0040d9a6     POP        EDI
    //         0040d9a7     POP        ESI
    //         0040d9a8     POP        EBP
    //         0040d9a9     POP        EBX
    //         0040d9aa     POP        this
    //         0040d9ab     RET        0x28
    //                               LAB_0040d9ae                                                 XREF[2]:     0040d97d(j), 0040d98b(j)  
    //                              aimdmod.cpp:210 (2)
    //         0040d9ae     MOV        EAX,EBP
    //                              aimdmod.cpp:213 (18)
    //         0040d9b0     POP        EDI
    //         0040d9b1     POP        ESI
    //         0040d9b2     POP        EBP
    //         0040d9b3     POP        EBX
    //         0040d9b4     POP        this
    //         0040d9b5     RET        0x28
    //                               LAB_0040d9b8                                                 XREF[1]:     0040d795(j)  
    //         0040d9b8     POP        EDI
    //         0040d9b9     POP        ESI
    //         0040d9ba     POP        EBP
    //         0040d9bb     XOR        EAX,EAX
    //         0040d9bd     POP        EBX
    //         0040d9be     POP        this
    //         0040d9bf     RET        0x28
    //         0040d9c2     ??         90h
    //         0040d9c3     NOP
    //         0040d9c4     NOP
    //         0040d9c5     NOP
    //         0040d9c6     NOP
    //         0040d9c7     NOP
    //         0040d9c8     NOP
    //         0040d9c9     NOP
    //         0040d9ca     NOP
    //         0040d9cb     NOP
    //         0040d9cc     NOP
    //         0040d9cd     NOP
    //         0040d9ce     NOP
    //         0040d9cf     NOP
    return 0;
}

RGE_Static_Object* MainDecisionAIModule::object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall object(MainDecisionAIModule * this, i
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040da77(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040da85(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040da99(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040dabb(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0040dacf(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0040dad5(R)  
    //                               ?object@MainDecisionAIModule@@QAEPAVRGE_Static_Object@@HHHH  XREF[2]:     taskTrain:004fb595(c), 
    //                               MainDecisionAIModule::object                                              taskResearch:004fb755(c)  
    //                              aimdmod.cpp:219 (5)
    //         0040d9d0     PUSH       EBX
    //         0040d9d1     PUSH       EBP
    //         0040d9d2     PUSH       ESI
    //         0040d9d3     MOV        ESI,this
    //                              aimdmod.cpp:220 (17)
    //         0040d9d5     XOR        EBP,EBP
    //         0040d9d7     PUSH       EDI
    //         0040d9d8     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040d9de     TEST       EAX,EAX
    //         0040d9e0     JLE        LAB_0040db08
    //                               LAB_0040d9e6                                                 XREF[1]:     0040daf0(j)  
    //                              aimdmod.cpp:221 (130)
    //         0040d9e6     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040d9ec     DEC        EAX
    //         0040d9ed     CMP        EBP,EAX
    //         0040d9ef     JLE        LAB_0040da4e
    //         0040d9f1     LEA        this,[EBP*0x4 + 0x4]
    //         0040d9f8     LEA        EBX,[EBP + 0x1]
    //         0040d9fb     PUSH       this
    //         0040d9fc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040da01     MOV        EDI,EAX
    //         0040da03     ADD        ESP,0x4
    //         0040da06     TEST       EDI,EDI
    //         0040da08     JZ         LAB_0040da4e
    //         0040da0a     MOV        this,dword ptr [ESI + 0x100]
    //         0040da10     XOR        EAX,EAX
    //         0040da12     TEST       this,this
    //         0040da14     JLE        LAB_0040da33
    //                               LAB_0040da16                                                 XREF[1]:     0040da31(j)  
    //         0040da16     CMP        EAX,EBX
    //         0040da18     JGE        LAB_0040da33
    //         0040da1a     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040da20     INC        EAX
    //         0040da21     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040da25     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040da29     MOV        this,dword ptr [ESI + 0x100]
    //         0040da2f     CMP        EAX,this
    //         0040da31     JL         LAB_0040da16
    //                               LAB_0040da33                                                 XREF[2]:     0040da14(j), 0040da18(j)  
    //         0040da33     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040da39     PUSH       EDX
    //         0040da3a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040da3f     ADD        ESP,0x4
    //         0040da42     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040da48     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0040da4e                                                 XREF[2]:     0040d9ef(j), 0040da08(j)  
    //         0040da4e     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040da54     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040da5a     MOV        this,dword ptr [EAX + EBP*0x4]
    //         0040da5d     PUSH       this
    //         0040da5e     MOV        this,dword ptr [EDX + 0x3c]
    //         0040da61     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040da66     MOV        EDI,EAX
    //                              aimdmod.cpp:222 (15)
    //         0040da68     TEST       EDI,EDI
    //         0040da6a     JZ         LAB_0040dae7
    //         0040da6c     MOV        this,EDI
    //         0040da6e     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040da73     TEST       EAX,EAX
    //         0040da75     JZ         LAB_0040dae7
    //                              aimdmod.cpp:229 (112)
    //         0040da77     MOV        EAX,dword ptr [ESP + param_1]
    //         0040da7b     CMP        EAX,-0x1
    //         0040da7e     JZ         LAB_0040da85
    //         0040da80     CMP        dword ptr [EDI + 0x4],EAX
    //         0040da83     JNZ        LAB_0040dae7
    //                               LAB_0040da85                                                 XREF[1]:     0040da7e(j)  
    //         0040da85     MOV        EAX,dword ptr [ESP + param_2]
    //         0040da89     CMP        EAX,-0x1
    //         0040da8c     JZ         LAB_0040da99
    //         0040da8e     MOV        this,dword ptr [EDI + 0x8]
    //         0040da91     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040da95     CMP        EDX,EAX
    //         0040da97     JNZ        LAB_0040dae7
    //                               LAB_0040da99                                                 XREF[1]:     0040da8c(j)  
    //         0040da99     MOV        EAX,dword ptr [ESP + param_3]
    //         0040da9d     CMP        EAX,-0x1
    //         0040daa0     JZ         LAB_0040daad
    //         0040daa2     MOV        this,dword ptr [EDI + 0x8]
    //         0040daa5     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040daa9     CMP        EDX,EAX
    //         0040daab     JNZ        LAB_0040dae7
    //                               LAB_0040daad                                                 XREF[1]:     0040daa0(j)  
    //         0040daad     MOV        this,EDI
    //         0040daaf     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040dab4     MOV        this,EAX
    //         0040dab6     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040dabb     CMP        EAX,dword ptr [ESP + param_4]
    //         0040dabf     JZ         LAB_0040dae7
    //         0040dac1     MOV        this,EDI
    //         0040dac3     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040dac8     MOV        this,EAX
    //         0040daca     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040dacf     CMP        EAX,dword ptr [ESP + param_5]
    //         0040dad3     JZ         LAB_0040dae7
    //         0040dad5     MOV        EAX,dword ptr [ESP + param_6]
    //         0040dad9     CMP        EAX,-0x1
    //         0040dadc     JZ         LAB_0040daff
    //         0040dade     XOR        this,this
    //         0040dae0     MOV        this,byte ptr [EDI + 0x48]
    //         0040dae3     CMP        this,EAX
    //         0040dae5     JZ         LAB_0040daff
    //                               LAB_0040dae7                                                 XREF[7]:     0040da6a(j), 0040da75(j), 
    //                                                                                                         0040da83(j), 0040da97(j), 
    //                                                                                                         0040daab(j), 0040dabf(j), 
    //                                                                                                         0040dad3(j)  
    //                              aimdmod.cpp:220 (15)
    //         0040dae7     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040daed     INC        EBP
    //         0040daee     CMP        EBP,EAX
    //         0040daf0     JL         LAB_0040d9e6
    //                              aimdmod.cpp:234 (2)
    //         0040daf6     XOR        EAX,EAX
    //                              aimdmod.cpp:235 (7)
    //         0040daf8     POP        EDI
    //         0040daf9     POP        ESI
    //         0040dafa     POP        EBP
    //         0040dafb     POP        EBX
    //         0040dafc     RET        0x18
    //                               LAB_0040daff                                                 XREF[2]:     0040dadc(j), 0040dae5(j)  
    //                              aimdmod.cpp:232 (2)
    //         0040daff     MOV        EAX,EDI
    //                              aimdmod.cpp:235 (16)
    //         0040db01     POP        EDI
    //         0040db02     POP        ESI
    //         0040db03     POP        EBP
    //         0040db04     POP        EBX
    //         0040db05     RET        0x18
    //                               LAB_0040db08                                                 XREF[1]:     0040d9e0(j)  
    //         0040db08     POP        EDI
    //         0040db09     POP        ESI
    //         0040db0a     POP        EBP
    //         0040db0b     XOR        EAX,EAX
    //         0040db0d     POP        EBX
    //         0040db0e     RET        0x18
    //         0040db11     ??         90h
    //         0040db12     NOP
    //         0040db13     NOP
    //         0040db14     NOP
    //         0040db15     NOP
    //         0040db16     NOP
    //         0040db17     NOP
    //         0040db18     NOP
    //         0040db19     NOP
    //         0040db1a     NOP
    //         0040db1b     NOP
    //         0040db1c     NOP
    //         0040db1d     NOP
    //         0040db1e     NOP
    //         0040db1f     NOP
    return 0;
}

int MainDecisionAIModule::objectGroupThatCanPerformAction(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall objectGroupThatCanPerformAction(MainDecisionAIModule 
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040db20(R)  
    //                               ?objectGroupThatCanPerformAction@MainDecisionAIModule@@UAEH  XREF[2]:     objectGroupThatCanPerformAction:00
    //                               MainDecisionAIModule::objectGroupThatCanPerformAction                     0056e920(*)  
    //                              aimdmod.cpp:240 (19)
    //         0040db20     MOV        EAX,dword ptr [ESP + param_1]
    //         0040db24     PUSH       EAX
    //         0040db25     PUSH       s_ERROR!__%d_is_an_unrecognized_ac               = "ERROR!  %d is an unrecognized action id."
    //         0040db2a     PUSH       this
    //         0040db2b     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0040db30     ADD        ESP,0xc
    //                              aimdmod.cpp:242 (3)
    //         0040db33     OR         EAX,0xffffffff
    //                              aimdmod.cpp:243 (3)
    //         0040db36     RET        0x4
    //         0040db39     ??         90h
    //         0040db3a     NOP
    //         0040db3b     NOP
    //         0040db3c     NOP
    //         0040db3d     NOP
    //         0040db3e     NOP
    //         0040db3f     NOP
    return 0;
}

int MainDecisionAIModule::canPerformAction(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall canPerformAction(MainDecisionAIModule * this, int par
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?canPerformAction@MainDecisionAIModule@@UAEHHH@Z             XREF[1]:     0056e924(*)  
    //                               MainDecisionAIModule::canPerformAction
    //                              aimdmod.cpp:248 (2)
    //         0040db40     XOR        EAX,EAX
    //                              aimdmod.cpp:250 (3)
    //         0040db42     RET        0x8
    //         0040db45     ??         90h
    //         0040db46     NOP
    //         0040db47     NOP
    //         0040db48     NOP
    //         0040db49     NOP
    //         0040db4a     NOP
    //         0040db4b     NOP
    //         0040db4c     NOP
    //         0040db4d     NOP
    //         0040db4e     NOP
    //         0040db4f     NOP
    return 0;
}

int MainDecisionAIModule::numberBusyObjects() {
    /* TODO: Stub */
    //                              int __thiscall numberBusyObjects(MainDecisionAIModule * this)
    //              int               EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040db57(W), 0040dc0d(RW), 0040dc22(R)  
    //              int               Stack[-0x8]:4  count
    //                               ?numberBusyObjects@MainDecisionAIModule@@QAEHXZ
    //                               MainDecisionAIModule::numberBusyObjects
    //                              aimdmod.cpp:255 (5)
    //         0040db50     PUSH       this
    //         0040db51     PUSH       EBX
    //         0040db52     PUSH       ESI
    //         0040db53     MOV        ESI,this
    //                              aimdmod.cpp:256 (6)
    //         0040db55     XOR        EBX,EBX
    //         0040db57     MOV        dword ptr [ESP + local_4],EBX
    //                              aimdmod.cpp:257 (14)
    //         0040db5b     CMP        dword ptr [ESI + 0xf8],EBX
    //         0040db61     JLE        LAB_0040dc22
    //         0040db67     PUSH       EDI
    //         0040db68     PUSH       EBP
    //                               LAB_0040db69                                                 XREF[1]:     0040dc1a(j)  
    //                              aimdmod.cpp:258 (130)
    //         0040db69     MOV        EAX,dword ptr [ESI + 0x100]
    //         0040db6f     DEC        EAX
    //         0040db70     CMP        EBX,EAX
    //         0040db72     JLE        LAB_0040dbd1
    //         0040db74     LEA        this,[EBX*0x4 + 0x4]
    //         0040db7b     LEA        EBP,[EBX + 0x1]
    //         0040db7e     PUSH       this
    //         0040db7f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040db84     MOV        EDI,EAX
    //         0040db86     ADD        ESP,0x4
    //         0040db89     TEST       EDI,EDI
    //         0040db8b     JZ         LAB_0040dbd1
    //         0040db8d     MOV        this,dword ptr [ESI + 0x100]
    //         0040db93     XOR        EAX,EAX
    //         0040db95     TEST       this,this
    //         0040db97     JLE        LAB_0040dbb6
    //                               LAB_0040db99                                                 XREF[1]:     0040dbb4(j)  
    //         0040db99     CMP        EAX,EBP
    //         0040db9b     JGE        LAB_0040dbb6
    //         0040db9d     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040dba3     INC        EAX
    //         0040dba4     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040dba8     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040dbac     MOV        this,dword ptr [ESI + 0x100]
    //         0040dbb2     CMP        EAX,this
    //         0040dbb4     JL         LAB_0040db99
    //                               LAB_0040dbb6                                                 XREF[2]:     0040db97(j), 0040db9b(j)  
    //         0040dbb6     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0040dbbc     PUSH       EDX
    //         0040dbbd     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040dbc2     ADD        ESP,0x4
    //         0040dbc5     MOV        dword ptr [ESI + 0xf4],EDI
    //         0040dbcb     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_0040dbd1                                                 XREF[2]:     0040db72(j), 0040db8b(j)  
    //         0040dbd1     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0040dbd7     MOV        EDX,dword ptr [ESI + 0xf0]
    //         0040dbdd     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0040dbe0     PUSH       this
    //         0040dbe1     MOV        this,dword ptr [EDX + 0x3c]
    //         0040dbe4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040dbe9     MOV        EDI,EAX
    //                              aimdmod.cpp:259 (15)
    //         0040dbeb     TEST       EDI,EDI
    //         0040dbed     JZ         LAB_0040dc11
    //         0040dbef     MOV        this,EDI
    //         0040dbf1     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040dbf6     TEST       EAX,EAX
    //         0040dbf8     JZ         LAB_0040dc11
    //                              aimdmod.cpp:261 (19)
    //         0040dbfa     MOV        this,EDI
    //         0040dbfc     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040dc01     MOV        this,EAX
    //         0040dc03     CALL       UnitAIModule::currentAction                      int currentAction(UnitAIModule * this)
    //         0040dc08     CMP        EAX,-0x1
    //         0040dc0b     JNZ        LAB_0040dc11
    //                              aimdmod.cpp:262 (21)
    //         0040dc0d     INC        dword ptr [ESP + local_4]
    //                               LAB_0040dc11                                                 XREF[3]:     0040dbed(j), 0040dbf8(j), 
    //                                                                                                         0040dc0b(j)  
    //         0040dc11     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0040dc17     INC        EBX
    //         0040dc18     CMP        EBX,EAX
    //         0040dc1a     JL         LAB_0040db69
    //         0040dc20     POP        EBP
    //         0040dc21     POP        EDI
    //                               LAB_0040dc22                                                 XREF[1]:     0040db61(j)  
    //                              aimdmod.cpp:264 (4)
    //         0040dc22     MOV        EAX,dword ptr [ESP + local_4]
    //                              aimdmod.cpp:265 (4)
    //         0040dc26     POP        ESI
    //         0040dc27     POP        EBX
    //         0040dc28     POP        this
    //         0040dc29     RET
    //         0040dc2a     ??         90h
    //         0040dc2b     NOP
    //         0040dc2c     NOP
    //         0040dc2d     NOP
    //         0040dc2e     NOP
    //         0040dc2f     NOP
    return 0;
}

RGE_Static_Object* MainDecisionAIModule::mostDamaged(int param_1, int param_2) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall mostDamaged(MainDecisionAIModule * th
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040dcf2(R)  
    //              int               Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040dd02(W), 0040dd06(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0040dc39(W), 0040dd7b(R)  
    //              RGE_Static_Obj    Stack[-0xc]:4  mDB                       XREF[1]:     0040dc3d(W)  
    //              int               Stack[-0x10]:4 damagePercentage
    //                               ?mostDamaged@MainDecisionAIModule@@QAEPAVRGE_Static_Object@  XREF[2]:     doSomething:004f0688(c), 
    //                               MainDecisionAIModule::mostDamaged                                         doSomething:004f075f(c)  
    //                              aimdmod.cpp:270 (7)
    //         0040dc30     SUB        ESP,0xc
    //         0040dc33     PUSH       EBP
    //         0040dc34     PUSH       EDI
    //         0040dc35     MOV        EDI,this
    //                              aimdmod.cpp:271 (6)
    //         0040dc37     XOR        EBP,EBP
    //         0040dc39     MOV        dword ptr [ESP + local_8],EBP
    //                              aimdmod.cpp:272 (4)
    //         0040dc3d     MOV        dword ptr [ESP + mDB],EBP
    //                              aimdmod.cpp:273 (14)
    //         0040dc41     CMP        dword ptr [EDI + 0xf8],EBP
    //         0040dc47     JLE        LAB_0040dd7b
    //         0040dc4d     PUSH       ESI
    //         0040dc4e     PUSH       EBX
    //                               LAB_0040dc4f                                                 XREF[1]:     0040dd73(j)  
    //                              aimdmod.cpp:274 (130)
    //         0040dc4f     MOV        EAX,dword ptr [EDI + 0x100]
    //         0040dc55     DEC        EAX
    //         0040dc56     CMP        EBP,EAX
    //         0040dc58     JLE        LAB_0040dcb7
    //         0040dc5a     LEA        this,[EBP*0x4 + 0x4]
    //         0040dc61     LEA        EBX,[EBP + 0x1]
    //         0040dc64     PUSH       this
    //         0040dc65     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040dc6a     MOV        ESI,EAX
    //         0040dc6c     ADD        ESP,0x4
    //         0040dc6f     TEST       ESI,ESI
    //         0040dc71     JZ         LAB_0040dcb7
    //         0040dc73     MOV        this,dword ptr [EDI + 0x100]
    //         0040dc79     XOR        EAX,EAX
    //         0040dc7b     TEST       this,this
    //         0040dc7d     JLE        LAB_0040dc9c
    //                               LAB_0040dc7f                                                 XREF[1]:     0040dc9a(j)  
    //         0040dc7f     CMP        EAX,EBX
    //         0040dc81     JGE        LAB_0040dc9c
    //         0040dc83     MOV        EDX,dword ptr [EDI + 0xf4]
    //         0040dc89     INC        EAX
    //         0040dc8a     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040dc8e     MOV        dword ptr [ESI + EAX*0x4 + -0x4],this
    //         0040dc92     MOV        this,dword ptr [EDI + 0x100]
    //         0040dc98     CMP        EAX,this
    //         0040dc9a     JL         LAB_0040dc7f
    //                               LAB_0040dc9c                                                 XREF[2]:     0040dc7d(j), 0040dc81(j)  
    //         0040dc9c     MOV        EDX,dword ptr [EDI + 0xf4]
    //         0040dca2     PUSH       EDX
    //         0040dca3     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040dca8     ADD        ESP,0x4
    //         0040dcab     MOV        dword ptr [EDI + 0xf4],ESI
    //         0040dcb1     MOV        dword ptr [EDI + 0x100],EBX
    //                               LAB_0040dcb7                                                 XREF[2]:     0040dc58(j), 0040dc71(j)  
    //         0040dcb7     MOV        EAX,dword ptr [EDI + 0xf4]
    //         0040dcbd     MOV        EDX,dword ptr [EDI + 0xf0]
    //         0040dcc3     MOV        this,dword ptr [EAX + EBP*0x4]
    //         0040dcc6     PUSH       this
    //         0040dcc7     MOV        this,dword ptr [EDX + 0x3c]
    //         0040dcca     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0040dccf     MOV        ESI,EAX
    //                              aimdmod.cpp:275 (23)
    //         0040dcd1     TEST       ESI,ESI
    //         0040dcd3     JZ         LAB_0040dd6a
    //         0040dcd9     MOV        this,ESI
    //         0040dcdb     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040dce0     TEST       EAX,EAX
    //         0040dce2     JZ         LAB_0040dd6a
    //                              aimdmod.cpp:278 (7)
    //         0040dce8     MOV        AL,byte ptr [ESI + 0x48]
    //         0040dceb     TEST       AL,AL
    //         0040dced     JZ         LAB_0040dd6a
    //                              aimdmod.cpp:281 (15)
    //         0040dcef     MOV        EAX,dword ptr [ESI + 0x8]
    //         0040dcf2     MOV        EDX,dword ptr [ESP + param_1]
    //         0040dcf6     MOVSX      this,word ptr [EAX + 0x14]
    //         0040dcfa     CMP        this,EDX
    //         0040dcfc     JNZ        LAB_0040dd6a
    //                              aimdmod.cpp:284 (57)
    //         0040dcfe     MOVSX      EDX,word ptr [EAX + 0x26]
    //         0040dd02     MOV        dword ptr [ESP + local_4],EDX
    //         0040dd06     FILD       dword ptr [ESP + local_4]
    //         0040dd0a     FCOMP      float ptr [ESI + 0x30]
    //         0040dd0d     FNSTSW     AX
    //         0040dd0f     TEST       AH,0x41
    //         0040dd12     JNZ        LAB_0040dd6a
    //         0040dd14     MOV        EAX,dword ptr [ESI]
    //         0040dd16     MOV        this,ESI
    //         0040dd18     CALL       dword ptr [EAX + 0x90]
    //         0040dd1e     CMP        EAX,0x1
    //         0040dd21     JNZ        LAB_0040dd6a
    //         0040dd23     MOV        EAX,dword ptr [ESP + 0x24]
    //         0040dd27     CMP        EAX,-0x1
    //         0040dd2a     JZ         LAB_0040dd37
    //         0040dd2c     MOV        this,dword ptr [ESI + 0x8]
    //         0040dd2f     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0040dd33     CMP        EAX,EDX
    //         0040dd35     JNZ        LAB_0040dd6a
    //                               LAB_0040dd37                                                 XREF[1]:     0040dd2a(j)  
    //                              aimdmod.cpp:286 (26)
    //         0040dd37     MOV        EAX,dword ptr [ESI + 0x8]
    //         0040dd3a     MOVSX      EBX,word ptr [EAX + 0x26]
    //         0040dd3e     MOV        dword ptr [ESP + 0x18],EBX
    //         0040dd42     FILD       dword ptr [ESP + 0x18]
    //         0040dd46     FSUB       float ptr [ESI + 0x30]
    //         0040dd49     CALL       __ftol                                           undefined __ftol()
    //         0040dd4e     LEA        EAX,[EAX + EAX*0x4]
    //                              aimdmod.cpp:287 (17)
    //         0040dd51     MOV        this,dword ptr [ESP + 0x10]
    //         0040dd55     LEA        EAX,[EAX + EAX*0x4]
    //         0040dd58     SHL        EAX,0x2
    //         0040dd5b     CDQ
    //         0040dd5c     IDIV       EBX
    //         0040dd5e     CMP        EAX,this
    //         0040dd60     JLE        LAB_0040dd6a
    //                              aimdmod.cpp:288 (4)
    //         0040dd62     MOV        dword ptr [ESP + 0x14],ESI
    //                              aimdmod.cpp:289 (21)
    //         0040dd66     MOV        dword ptr [ESP + 0x10],EAX
    //                               LAB_0040dd6a                                                 XREF[8]:     0040dcd3(j), 0040dce2(j), 
    //                                                                                                         0040dced(j), 0040dcfc(j), 
    //                                                                                                         0040dd12(j), 0040dd21(j), 
    //                                                                                                         0040dd35(j), 0040dd60(j)  
    //         0040dd6a     MOV        EAX,dword ptr [EDI + 0xf8]
    //         0040dd70     INC        EBP
    //         0040dd71     CMP        EBP,EAX
    //         0040dd73     JL         LAB_0040dc4f
    //         0040dd79     POP        EBX
    //         0040dd7a     POP        ESI
    //                               LAB_0040dd7b                                                 XREF[1]:     0040dc47(j)  
    //                              aimdmod.cpp:294 (4)
    //         0040dd7b     MOV        EAX,dword ptr [ESP + local_8]
    //                              aimdmod.cpp:295 (8)
    //         0040dd7f     POP        EDI
    //         0040dd80     POP        EBP
    //         0040dd81     ADD        ESP,0xc
    //         0040dd84     RET        0x8
    //         0040dd87     ??         90h
    //         0040dd88     NOP
    //         0040dd89     NOP
    //         0040dd8a     NOP
    //         0040dd8b     NOP
    //         0040dd8c     NOP
    //         0040dd8d     NOP
    //         0040dd8e     NOP
    //         0040dd8f     NOP
    return 0;
}

