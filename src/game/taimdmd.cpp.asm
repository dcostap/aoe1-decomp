#include "common.h"
#include "taimdmd.h"

TribeMainDecisionAIModule::~TribeMainDecisionAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeMainDecisionAIModule(TribeMainDecisionAIModule
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[10]:    004e4ee9(W), 004e4efc(W), 004e4f0c(W), 004e4f1c(W), 
    //                                                                                     004e4f2c(W), 004e4f3c(W), 004e4f4c(W), 004e4f5c(W), 
    //                                                                                     004e4f6c(W), 004e4f78(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004e4f85(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004e4ed9(W)  
    //                               ??1TribeMainDecisionAIModule@@UAE@XZ                         XREF[1]:     `scalar_deleting_destructor':004e4
    //                               TribeMainDecisionAIModule::~TribeMainDecisionAIModule
    //                              taimdmd.cpp:236 (60)
    //         004e4ec0     PUSH       -0x1
    //         004e4ec2     PUSH       FUN_00560728
    //         004e4ec7     MOV        EAX,FS:[0x0]
    //         004e4ecd     PUSH       EAX
    //         004e4ece     MOV        dword ptr FS:[0x0],ESP
    //         004e4ed5     PUSH       this
    //         004e4ed6     PUSH       ESI
    //         004e4ed7     MOV        ESI,this
    //         004e4ed9     MOV        dword ptr [ESP + local_10],ESI
    //         004e4edd     MOV        dword ptr [ESI],TribeMainDecisionAIModule::`vf   = 004e4b60
    //         004e4ee3     LEA        this,[ESI + 0x12478]
    //         004e4ee9     MOV        dword ptr [ESP + local_4],0x8
    //         004e4ef1     CALL       TradeAIModule::~TradeAIModule                    void ~TradeAIModule(TradeAIModule * this)
    //         004e4ef6     LEA        this,[ESI + 0x1146c]
    //                              taimdmd.cpp:237 (153)
    //         004e4efc     MOV        byte ptr [ESP + local_4],0x7
    //         004e4f01     CALL       TribeTacticalAIModule::~TribeTacticalAIModule    void ~TribeTacticalAIModule(TribeTacticalAIMo
    //         004e4f06     LEA        this,[ESI + 0x10e74]
    //         004e4f0c     MOV        byte ptr [ESP + local_4],0x6
    //         004e4f11     CALL       TribeStrategyAIModule::~TribeStrategyAIModule    void ~TribeStrategyAIModule(TribeStrategyAIMo
    //         004e4f16     LEA        this,[ESI + 0x10d7c]
    //         004e4f1c     MOV        byte ptr [ESP + local_4],0x5
    //         004e4f21     CALL       TribeResourceAIModule::~TribeResourceAIModule    void ~TribeResourceAIModule(TribeResourceAIMo
    //         004e4f26     LEA        this,[ESI + 0xcec]
    //         004e4f2c     MOV        byte ptr [ESP + local_4],0x4
    //         004e4f31     CALL       TribeInformationAIModule::~TribeInformationAIM   void ~TribeInformationAIModule(TribeInformati
    //         004e4f36     LEA        this,[ESI + 0xb2c]
    //         004e4f3c     MOV        byte ptr [ESP + local_4],0x3
    //         004e4f41     CALL       EmotionalAIModule::~EmotionalAIModule            void ~EmotionalAIModule(EmotionalAIModule * t
    //         004e4f46     LEA        this,[ESI + 0x9dc]
    //         004e4f4c     MOV        byte ptr [ESP + local_4],0x2
    //         004e4f51     CALL       DiplomacyAIModule::~DiplomacyAIModule            void ~DiplomacyAIModule(DiplomacyAIModule * t
    //         004e4f56     LEA        this,[ESI + 0x6c4]
    //         004e4f5c     MOV        byte ptr [ESP + local_4],0x1
    //         004e4f61     CALL       TribeConstructionAIModule::~TribeConstructionA   void ~TribeConstructionAIModule(TribeConstruc
    //         004e4f66     LEA        this,[ESI + 0x104]
    //         004e4f6c     MOV        byte ptr [ESP + local_4],0x0
    //         004e4f71     CALL       TribeBuildAIModule::~TribeBuildAIModule          void ~TribeBuildAIModule(TribeBuildAIModule *
    //         004e4f76     MOV        this,ESI
    //         004e4f78     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004e4f80     CALL       MainDecisionAIModule::~MainDecisionAIModule      void ~MainDecisionAIModule(MainDecisionAIModu
    //         004e4f85     MOV        this,dword ptr [ESP + local_c]
    //         004e4f89     POP        ESI
    //         004e4f8a     MOV        dword ptr FS:[0x0],this
    //         004e4f91     ADD        ESP,0x10
    //         004e4f94     RET
    //         004e4f95     ??         90h
    //         004e4f96     NOP
    //         004e4f97     NOP
    //         004e4f98     NOP
    //         004e4f99     NOP
    //         004e4f9a     NOP
    //         004e4f9b     NOP
    //         004e4f9c     NOP
    //         004e4f9d     NOP
    //         004e4f9e     NOP
    //         004e4f9f     NOP
}

void TribeMainDecisionAIModule::setLogHistory(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall setLogHistory(TribeMainDecisionAIModule * this, int 
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e4fa4(R)  
    //                               ?setLogHistory@TribeMainDecisionAIModule@@UAEXH@Z            XREF[1]:     005755d0(*)  
    //                               TribeMainDecisionAIModule::setLogHistory
    //                              taimdmd.cpp:242 (4)
    //         004e4fa0     PUSH       ESI
    //         004e4fa1     MOV        ESI,this
    //         004e4fa3     PUSH       EDI
    //                              taimdmd.cpp:243 (20)
    //         004e4fa4     MOV        EDI,dword ptr [ESP + param_1]
    //         004e4fa8     MOV        EAX,dword ptr [ESI + 0x104]
    //         004e4fae     LEA        this,[ESI + 0x104]
    //         004e4fb4     PUSH       EDI
    //         004e4fb5     CALL       dword ptr [EAX + 0x8]
    //                              taimdmd.cpp:244 (16)
    //         004e4fb8     MOV        EDX,dword ptr [ESI + 0x6c4]
    //         004e4fbe     LEA        this,[ESI + 0x6c4]
    //         004e4fc4     PUSH       EDI
    //         004e4fc5     CALL       dword ptr [EDX + 0x8]
    //                              taimdmd.cpp:245 (16)
    //         004e4fc8     MOV        EAX,dword ptr [ESI + 0x9dc]
    //         004e4fce     LEA        this,[ESI + 0x9dc]
    //         004e4fd4     PUSH       EDI
    //         004e4fd5     CALL       dword ptr [EAX + 0x8]
    //                              taimdmd.cpp:246 (16)
    //         004e4fd8     MOV        EDX,dword ptr [ESI + 0xb2c]
    //         004e4fde     LEA        this,[ESI + 0xb2c]
    //         004e4fe4     PUSH       EDI
    //         004e4fe5     CALL       dword ptr [EDX + 0x8]
    //                              taimdmd.cpp:247 (16)
    //         004e4fe8     MOV        EAX,dword ptr [ESI + 0xcec]
    //         004e4fee     LEA        this,[ESI + 0xcec]
    //         004e4ff4     PUSH       EDI
    //         004e4ff5     CALL       dword ptr [EAX + 0x8]
    //                              taimdmd.cpp:248 (16)
    //         004e4ff8     MOV        EDX,dword ptr [ESI + 0x10d7c]
    //         004e4ffe     LEA        this,[ESI + 0x10d7c]
    //         004e5004     PUSH       EDI
    //         004e5005     CALL       dword ptr [EDX + 0x8]
    //                              taimdmd.cpp:249 (16)
    //         004e5008     MOV        EAX,dword ptr [ESI + 0x10e74]
    //         004e500e     LEA        this,[ESI + 0x10e74]
    //         004e5014     PUSH       EDI
    //         004e5015     CALL       dword ptr [EAX + 0x8]
    //                              taimdmd.cpp:250 (16)
    //         004e5018     MOV        EDX,dword ptr [ESI + 0x1146c]
    //         004e501e     LEA        this,[ESI + 0x1146c]
    //         004e5024     PUSH       EDI
    //         004e5025     CALL       dword ptr [EDX + 0x8]
    //                              taimdmd.cpp:251 (16)
    //         004e5028     MOV        EAX,dword ptr [ESI + 0x12478]
    //         004e502e     LEA        this,[ESI + 0x12478]
    //         004e5034     PUSH       EDI
    //         004e5035     CALL       dword ptr [EAX + 0x8]
    //                              taimdmd.cpp:252 (8)
    //         004e5038     PUSH       EDI
    //         004e5039     MOV        this,ESI
    //         004e503b     CALL       MainDecisionAIModule::setLogHistory              void setLogHistory(MainDecisionAIModule * thi
    //                              taimdmd.cpp:253 (5)
    //         004e5040     POP        EDI
    //         004e5041     POP        ESI
    //         004e5042     RET        0x4
    //         004e5045     ??         90h
    //         004e5046     NOP
    //         004e5047     NOP
    //         004e5048     NOP
    //         004e5049     NOP
    //         004e504a     NOP
    //         004e504b     NOP
    //         004e504c     NOP
    //         004e504d     NOP
    //         004e504e     NOP
    //         004e504f     NOP
    return;
}

int TribeMainDecisionAIModule::update(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall update(TribeMainDecisionAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              char[256]         Stack[-0x110   tempString
    //              int[9]            Stack[-0x134   neutralList
    //              ManagedArray<i    Stack[-0x144   swayableCPs
    //              RGE_Player *      Stack[-0x148   temp2
    //              int               Stack[-0x14c   numberNeutralCPs
    //              TRIBE_World *     Stack[-0x150   world
    //              int               Stack[-0x154   newEnemy
    //                               ?update@TribeMainDecisionAIModule@@UAEHH@Z                   XREF[1]:     005755f8(*)  
    //                               TribeMainDecisionAIModule::update
    //                              taimdmd.cpp:258 (32)
    //         004e5050     MOV        EAX,FS:[0x0]
    //         004e5056     PUSH       -0x1
    //         004e5058     PUSH       FUN_0056074b
    //         004e505d     PUSH       EAX
    //         004e505e     MOV        dword ptr FS:[0x0],ESP
    //         004e5065     SUB        ESP,0x144
    //         004e506b     PUSH       EBX
    //         004e506c     PUSH       EBP
    //         004e506d     PUSH       ESI
    //         004e506e     MOV        ESI,this
    //                              taimdmd.cpp:267 (40)
    //         004e5070     XOR        EBX,EBX
    //         004e5072     PUSH       EDI
    //         004e5073     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5079     MOV        EBP,0x1
    //         004e507e     MOV        this,dword ptr [EAX + 0x3c]
    //         004e5081     MOV        AL,byte ptr [ECX + this+0x1d]
    //         004e5084     TEST       AL,AL
    //         004e5086     JNZ        LAB_004e5213
    //         004e508c     CMP        dword ptr [ESI + 0x12570],EBP
    //         004e5092     JNZ        LAB_004e5213
    //                              taimdmd.cpp:273 (17)
    //         004e5098     PUSH       s_Initial_Diplomacy_Settings:                    = "Initial Diplomacy Settings:"
    //         004e509d     PUSH       ESI
    //         004e509e     MOV        dword ptr [ESI + 0x12570],EBX
    //         004e50a4     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              taimdmd.cpp:274 (20)
    //         004e50a9     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e50af     ADD        ESP,0x8
    //         004e50b2     MOV        EDI,EBP
    //         004e50b4     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004e50b7     CMP        word ptr [EAX + 0x3c],BP
    //         004e50bb     JLE        LAB_004e5109
    //                              taimdmd.cpp:278 (71)
    //         004e50bd     LEA        EBP,[ESI + 0x9dc]
    //                               LAB_004e50c3                                                 XREF[1]:     004e5102(j)  
    //         004e50c3     PUSH       0x1
    //         004e50c5     PUSH       EDI
    //         004e50c6     MOV        this,EBP
    //         004e50c8     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
    //         004e50cd     PUSH       EAX
    //         004e50ce     PUSH       0x2
    //         004e50d0     PUSH       EDI
    //         004e50d1     MOV        this,EBP
    //         004e50d3     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
    //         004e50d8     PUSH       EAX
    //         004e50d9     PUSH       EBX
    //         004e50da     PUSH       EDI
    //         004e50db     MOV        this,EBP
    //         004e50dd     CALL       DiplomacyAIModule::stance                        int stance(DiplomacyAIModule * this, int para
    //         004e50e2     PUSH       EAX
    //         004e50e3     PUSH       EDI
    //         004e50e4     PUSH       s___Player_#%d:_Dislike=%d,_Like=%               = "  Player #%d: Dislike=%d, Like=%d, Ambival
    //         004e50e9     PUSH       ESI
    //         004e50ea     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004e50ef     MOV        this,dword ptr [ESI + 0xf0]
    //         004e50f5     ADD        ESP,0x18
    //         004e50f8     INC        EDI
    //         004e50f9     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e50fc     MOVSX      EAX,word ptr [EDX + 0x3c]
    //         004e5100     CMP        EDI,EAX
    //         004e5102     JL         LAB_004e50c3
    //                              taimdmd.cpp:274 (5)
    //         004e5104     MOV        EBP,0x1
    //                               LAB_004e5109                                                 XREF[1]:     004e50bb(j)  
    //                              taimdmd.cpp:282 (16)
    //         004e5109     MOV        EDX,dword ptr [ESI + 0x10e74]
    //         004e510f     LEA        this,[ESI + 0x10e74]
    //         004e5115     PUSH       EBX
    //         004e5116     CALL       dword ptr [EDX + 0x30]
    //                              taimdmd.cpp:285 (11)
    //         004e5119     LEA        this,[ESI + 0x104]
    //         004e511f     CALL       TribeBuildAIModule::initialize                   void initialize(TribeBuildAIModule * this)
    //                              taimdmd.cpp:288 (11)
    //         004e5124     LEA        this,[ESI + 0xcec]
    //         004e512a     CALL       TribeInformationAIModule::initialize             int initialize(TribeInformationAIModule * this)
    //                              taimdmd.cpp:301 (7)
    //         004e512f     MOV        this,ESI
    //         004e5131     CALL       TribeMainDecisionAIModule::setTributeChat        void setTributeChat(TribeMainDecisionAIModule
    //                              taimdmd.cpp:306 (35)
    //         004e5136     LEA        EDI,[ESI + 0x1146c]
    //                              language.dll match for 0x81: "10"
    //         004e513c     PUSH       0x81
    //         004e5141     MOV        this,EDI
    //         004e5143     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5148     CMP        EAX,EBP
    //         004e514a     JNZ        LAB_004e5165
    //                              language.dll match for 0x7d: "Arial"
    //         004e514c     PUSH       0x7d
    //         004e514e     MOV        this,EDI
    //         004e5150     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5155     TEST       EAX,EAX
    //         004e5157     JNZ        LAB_004e5165
    //                              taimdmd.cpp:307 (6)
    //         004e5159     MOV        dword ptr [ESI + 0x1258c],EBP
    //                              taimdmd.cpp:308 (6)
    //         004e515f     MOV        dword ptr [ESI + 0x12598],EBX
    //                               LAB_004e5165                                                 XREF[2]:     004e514a(j), 004e5157(j)  
    //                              taimdmd.cpp:312 (12)
    //         004e5165     PUSH       0x8a
    //         004e516a     MOV        this,EDI
    //         004e516c     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //                              taimdmd.cpp:313 (8)
    //         004e5171     CMP        EAX,EBX
    //         004e5173     MOV        dword ptr [ESP + 0x1c],EAX
    //         004e5177     JZ         LAB_004e5190
    //                              taimdmd.cpp:314 (23)
    //         004e5179     MOV        this,dword ptr [ESI + 0xf0]
    //         004e517f     FILD       dword ptr [ESP + 0x1c]
    //         004e5183     MOV        EAX,dword ptr [this->_padding_]
    //         004e5185     PUSH       this
    //         004e5186     FSTP       float ptr [ESP]
    //         004e5189     PUSH       EBX=>DAT_fffffff8
    //         004e518a     CALL       dword ptr [EAX + 0xb4]
    //                               LAB_004e5190                                                 XREF[1]:     004e5177(j)  
    //                              taimdmd.cpp:315 (12)
    //         004e5190     PUSH       0x8b
    //         004e5195     MOV        this,EDI
    //         004e5197     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //                              taimdmd.cpp:316 (8)
    //         004e519c     CMP        EAX,EBX
    //         004e519e     MOV        dword ptr [ESP + 0x1c],EAX
    //         004e51a2     JZ         LAB_004e51bc
    //                              taimdmd.cpp:317 (24)
    //         004e51a4     MOV        this,dword ptr [ESI + 0xf0]
    //         004e51aa     FILD       dword ptr [ESP + 0x1c]
    //         004e51ae     MOV        EDX,dword ptr [this->_padding_]
    //         004e51b0     PUSH       this
    //         004e51b1     FSTP       float ptr [ESP]
    //         004e51b4     PUSH       offset DAT_fffffff8
    //         004e51b6     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_004e51bc                                                 XREF[1]:     004e51a2(j)  
    //                              taimdmd.cpp:318 (12)
    //         004e51bc     PUSH       0x8c
    //         004e51c1     MOV        this,EDI
    //         004e51c3     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //                              taimdmd.cpp:319 (8)
    //         004e51c8     CMP        EAX,EBX
    //         004e51ca     MOV        dword ptr [ESP + 0x1c],EAX
    //         004e51ce     JZ         LAB_004e51e8
    //                              taimdmd.cpp:320 (24)
    //         004e51d0     MOV        this,dword ptr [ESI + 0xf0]
    //         004e51d6     FILD       dword ptr [ESP + 0x1c]
    //         004e51da     MOV        EAX,dword ptr [this->_padding_]
    //         004e51dc     PUSH       this
    //         004e51dd     FSTP       float ptr [ESP]
    //         004e51e0     PUSH       offset DAT_fffffff8
    //         004e51e2     CALL       dword ptr [EAX + 0xb4]
    //                               LAB_004e51e8                                                 XREF[1]:     004e51ce(j)  
    //                              taimdmd.cpp:321 (12)
    //         004e51e8     PUSH       0x8d
    //         004e51ed     MOV        this,EDI
    //         004e51ef     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //                              taimdmd.cpp:322 (8)
    //         004e51f4     CMP        EAX,EBX
    //         004e51f6     MOV        dword ptr [ESP + 0x1c],EAX
    //         004e51fa     JZ         LAB_004e5213
    //                              taimdmd.cpp:323 (23)
    //         004e51fc     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5202     FILD       dword ptr [ESP + 0x1c]
    //         004e5206     MOV        EDX,dword ptr [this->_padding_]
    //         004e5208     PUSH       this
    //         004e5209     FSTP       float ptr [ESP]
    //         004e520c     PUSH       EBP=>DAT_fffffff8
    //         004e520d     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_004e5213                                                 XREF[3]:     004e5086(j), 004e5092(j), 
    //                                                                                                         004e51fa(j)  
    //                              taimdmd.cpp:326 (7)
    //         004e5213     MOV        this,dword ptr [ESI + 0x12578]
    //         004e5219     INC        this
    //                              taimdmd.cpp:328 (13)
    //         004e521a     MOV        EAX,this
    //         004e521c     MOV        dword ptr [ESI + 0x12578],this
    //         004e5222     CMP        EAX,0x14
    //         004e5225     JL         LAB_004e523d
    //                              taimdmd.cpp:329 (16)
    //         004e5227     MOV        EAX,dword ptr [ESI + 0x10e74]
    //         004e522d     LEA        this,[ESI + 0x10e74]
    //         004e5233     PUSH       EBX
    //         004e5234     CALL       dword ptr [EAX + 0x30]
    //                              taimdmd.cpp:330 (6)
    //         004e5237     MOV        dword ptr [ESI + 0x12578],EBX
    //                               LAB_004e523d                                                 XREF[1]:     004e5225(j)  
    //                              taimdmd.cpp:335 (16)
    //         004e523d     MOV        EDX,dword ptr [ESI + 0xcec]
    //         004e5243     LEA        this,[ESI + 0xcec]
    //         004e5249     PUSH       EBX
    //         004e524a     CALL       dword ptr [EDX + 0x30]
    //                              taimdmd.cpp:339 (38)
    //         004e524d     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5253     MOV        EBP,dword ptr [ESI + 0x1257c]
    //         004e5259     LEA        this,[EAX + 0x3c]
    //         004e525c     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004e525f     MOV        EDX,dword ptr [EAX + 0x4]
    //         004e5262     MOV        EAX,0x10624dd3
    //         004e5267     SUB        EDX,EBP
    //         004e5269     MUL        EDX
    //         004e526b     SHR        EDX,0x6
    //         004e526e     CMP        EDX,0x3c
    //         004e5271     JC         LAB_004e5298
    //                              taimdmd.cpp:343 (16)
    //         004e5273     MOV        EAX,dword ptr [ESI + 0x9dc]
    //         004e5279     LEA        this,[ESI + 0x9dc]
    //         004e527f     PUSH       EBX
    //         004e5280     CALL       dword ptr [EAX + 0x30]
    //                              taimdmd.cpp:344 (21)
    //         004e5283     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5289     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004e528c     LEA        this,[EAX + 0x3c]
    //         004e528f     MOV        EAX,dword ptr [EDX + 0x4]
    //         004e5292     MOV        dword ptr [ESI + 0x1257c],EAX
    //                               LAB_004e5298                                                 XREF[1]:     004e5271(j)  
    //                              taimdmd.cpp:348 (13)
    //         004e5298     MOV        this,dword ptr [this->_padding_]
    //         004e529a     MOV        EBP,dword ptr [ESI + 0x12584]
    //         004e52a0     MOV        EAX,0x10624dd3
    //                              taimdmd.cpp:349 (35)
    //         004e52a5     LEA        EDI,[ESI + 0x1146c]
    //         004e52ab     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              language.dll match for 0x7c: "B"
    //         004e52ae     PUSH       0x7c
    //         004e52b0     SUB        EDX,EBP
    //         004e52b2     MOV        this,EDI
    //         004e52b4     MUL        EDX
    //         004e52b6     MOV        EBP,EDX
    //         004e52b8     SHR        EBP,0x6
    //         004e52bb     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e52c0     TEST       EAX,EAX
    //         004e52c2     JLE        LAB_004e56fa
    //                              taimdmd.cpp:356 (12)
    //         004e52c8     CMP        dword ptr [ESI + 0x12594],EBX
    //         004e52ce     JNZ        LAB_004e56fa
    //                              taimdmd.cpp:362 (29)
    //         004e52d4     CMP        EBP,dword ptr [ESI + 0x12588]
    //         004e52da     JC         LAB_004e546d
    //                              language.dll match for 0x7d: "Arial"
    //         004e52e0     PUSH       0x7d
    //         004e52e2     MOV        this,EDI
    //         004e52e4     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e52e9     TEST       EAX,EAX
    //         004e52eb     JLE        LAB_004e546d
    //                              taimdmd.cpp:365 (8)
    //         004e52f1     CMP        dword ptr [ESI + 0x1258c],EBX
    //         004e52f7     JNZ        LAB_004e5324
    //                              language.dll match for 0x7f: "N"
    //                              taimdmd.cpp:370 (22)
    //         004e52f9     PUSH       0x7f
    //         004e52fb     MOV        this,EDI
    //         004e52fd     MOV        dword ptr [ESI + 0x1258c],0x1
    //         004e5307     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e530c     LEA        EAX,[EAX + EAX*0x4]
    //                              taimdmd.cpp:371 (21)
    //         004e530f     MOV        dword ptr [ESI + 0x12598],EBX
    //         004e5315     LEA        EAX,[EAX + EAX*0x4]
    //         004e5318     LEA        EAX,[EAX + EAX*0x4]
    //         004e531b     SHL        EAX,0x3
    //         004e531e     MOV        dword ptr [ESI + 0x12590],EAX
    //                               LAB_004e5324                                                 XREF[1]:     004e52f7(j)  
    //                              taimdmd.cpp:374 (6)
    //         004e5324     MOV        this,dword ptr [ESI + 0xf0]
    //                              language.dll match for 0x82: "B"
    //                              taimdmd.cpp:376 (29)
    //         004e532a     PUSH       0x82
    //         004e532f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e5332     MOV        this,EDI
    //         004e5334     MOV        EAX,dword ptr [EDX + 0x4]
    //         004e5337     MOV        dword ptr [ESI + 0x12584],EAX
    //         004e533d     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5342     CMP        EAX,0x1
    //         004e5345     JNZ        LAB_004e53aa
    //                              taimdmd.cpp:377 (6)
    //         004e5347     MOV        EAX,dword ptr [ESI + 0x12598]
    //                              taimdmd.cpp:379 (30)
    //         004e534d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e5353     CMP        EAX,EBX
    //         004e5355     JLE        LAB_004e5383
    //         004e5357     MOV        EDX,dword ptr [this->_padding_]
    //         004e5359     LEA        EAX,[ESP + 0x54]
    //         004e535d     PUSH       0x100
    //         004e5362     PUSH       EAX=>DAT_fffffff8
    //                              language.dll match for 0x902: "Tribute %d more gold to me or 
    //         004e5363     PUSH       offset DAT_fffffff4
    //         004e5368     CALL       dword ptr [EDX + 0x20]
    //                              language.dll match for 0x7c: "B"
    //                              taimdmd.cpp:381 (22)
    //         004e536b     PUSH       0x7c
    //         004e536d     MOV        this,EDI
    //         004e536f     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5374     MOV        this,dword ptr [ESI + 0x12598]
    //         004e537a     SUB        EAX,this
    //         004e537c     LEA        this,[ESP + 0x54]
    //         004e5380     PUSH       EAX
    //                              taimdmd.cpp:383 (2)
    //         004e5381     JMP        LAB_004e53f1
    //                               LAB_004e5383                                                 XREF[1]:     004e5355(j)  
    //                              taimdmd.cpp:385 (20)
    //         004e5383     MOV        EAX,dword ptr [this->_padding_]
    //         004e5385     LEA        EDX,[ESP + 0x54]
    //         004e5389     PUSH       0x100
    //         004e538e     PUSH       EDX=>DAT_fffffff8
    //                              language.dll match for 0x903: "Tribute %d gold to me or you w
    //         004e538f     PUSH       offset DAT_fffffff4
    //         004e5394     CALL       dword ptr [EAX + 0x20]
    //                              language.dll match for 0x7c: "B"
    //                              taimdmd.cpp:387 (14)
    //         004e5397     PUSH       0x7c
    //         004e5399     MOV        this,EDI
    //         004e539b     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e53a0     PUSH       EAX
    //         004e53a1     LEA        EAX,[ESP + 0x58]
    //                              taimdmd.cpp:390 (26)
    //         004e53a5     JMP        LAB_004e5443
    //                              language.dll match for 0x81: "10"
    //                               LAB_004e53aa                                                 XREF[1]:     004e5345(j)  
    //         004e53aa     PUSH       0x81
    //         004e53af     MOV        this,EDI
    //         004e53b1     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e53b6     CMP        EAX,0x1
    //         004e53b9     JNZ        LAB_004e5461
    //                              taimdmd.cpp:391 (6)
    //         004e53bf     MOV        EAX,dword ptr [ESI + 0x12598]
    //                              taimdmd.cpp:393 (30)
    //         004e53c5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e53cb     CMP        EAX,EBX
    //         004e53cd     JLE        LAB_004e541b
    //         004e53cf     MOV        EDX,dword ptr [this->_padding_]
    //         004e53d1     LEA        EAX,[ESP + 0x54]
    //         004e53d5     PUSH       0x100
    //         004e53da     PUSH       EAX=>DAT_fffffff8
    //                              language.dll match for 0x904: "If you tribute me %d gold, I w
    //         004e53db     PUSH       offset DAT_fffffff4
    //         004e53e0     CALL       dword ptr [EDX + 0x20]
    //                              language.dll match for 0x7c: "B"
    //                              taimdmd.cpp:395 (36)
    //         004e53e3     PUSH       0x7c
    //         004e53e5     MOV        this,EDI
    //         004e53e7     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e53ec     PUSH       EAX
    //         004e53ed     LEA        this,[ESP + 0x58]
    //                               LAB_004e53f1                                                 XREF[1]:     004e5381(j)  
    //         004e53f1     PUSH       this=>DAT_fffffff8
    //         004e53f2     PUSH       EBX=>DAT_fffffff4
    //                              language.dll match for 0x80: "Arial"
    //         004e53f3     PUSH       offset DAT_fffffff0
    //         004e53f8     MOV        this,EDI
    //         004e53fa     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e53ff     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e5405     PUSH       EAX=>DAT_fffffff0
    //         004e5406     PUSH       EDX
    //                              taimdmd.cpp:401 (8)
    //         004e5407     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //         004e540c     ADD        ESP,0x14
    //                              taimdmd.cpp:406 (7)
    //         004e540f     MOV        this,ESI
    //         004e5411     CALL       TribeMainDecisionAIModule::setTributeChat        void setTributeChat(TribeMainDecisionAIModule
    //                              taimdmd.cpp:410 (5)
    //         004e5416     JMP        LAB_004e56fa
    //                               LAB_004e541b                                                 XREF[1]:     004e53cd(j)  
    //                              taimdmd.cpp:399 (20)
    //         004e541b     MOV        EAX,dword ptr [this->_padding_]
    //         004e541d     LEA        EDX,[ESP + 0x54]
    //         004e5421     PUSH       0x100
    //         004e5426     PUSH       EDX=>DAT_fffffff8
    //                              language.dll match for 0x905: "If you tribute me %d more gold
    //         004e5427     PUSH       offset DAT_fffffff4
    //         004e542c     CALL       dword ptr [EAX + 0x20]
    //                              language.dll match for 0x7c: "B"
    //                              taimdmd.cpp:401 (50)
    //         004e542f     PUSH       0x7c
    //         004e5431     MOV        this,EDI
    //         004e5433     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5438     SUB        EAX,dword ptr [ESI + 0x12598]
    //         004e543e     PUSH       EAX
    //         004e543f     LEA        EAX,[ESP + 0x58]
    //                               LAB_004e5443                                                 XREF[1]:     004e53a5(j)  
    //         004e5443     PUSH       EAX=>DAT_fffffff8
    //         004e5444     PUSH       EBX=>DAT_fffffff4
    //                              language.dll match for 0x80: "Arial"
    //         004e5445     PUSH       offset DAT_fffffff0
    //         004e544a     MOV        this,EDI
    //         004e544c     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5451     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5457     PUSH       EAX=>DAT_fffffff0
    //         004e5458     PUSH       this
    //         004e5459     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //         004e545e     ADD        ESP,0x14
    //                               LAB_004e5461                                                 XREF[1]:     004e53b9(j)  
    //                              taimdmd.cpp:406 (7)
    //         004e5461     MOV        this,ESI
    //         004e5463     CALL       TribeMainDecisionAIModule::setTributeChat        void setTributeChat(TribeMainDecisionAIModule
    //                              taimdmd.cpp:410 (18)
    //         004e5468     JMP        LAB_004e56fa
    //                               LAB_004e546d                                                 XREF[2]:     004e52da(j), 004e52eb(j)  
    //         004e546d     CMP        dword ptr [ESI + 0x1258c],0x1
    //         004e5474     JNZ        LAB_004e56fa
    //                              taimdmd.cpp:411 (20)
    //         004e547a     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e5480     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004e5483     MOV        EDX,dword ptr [ESI + 0x12590]
    //         004e5489     MOV        this,dword ptr [EAX + 0xc]
    //         004e548c     SUB        EDX,this
    //                              taimdmd.cpp:417 (16)
    //         004e548e     MOV        EAX,EDX
    //         004e5490     MOV        dword ptr [ESI + 0x12590],EDX
    //         004e5496     CMP        EAX,EBX
    //         004e5498     JG         LAB_004e55ab
    //                              language.dll match for 0x82: "B"
    //                              taimdmd.cpp:422 (21)
    //         004e549e     PUSH       0x82
    //         004e54a3     MOV        this,EDI
    //         004e54a5     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e54aa     CMP        EAX,0x1
    //         004e54ad     JNZ        LAB_004e5573
    //                              taimdmd.cpp:429 (30)
    //         004e54b3     PUSH       0x64
    //         004e54b5     PUSH       0x0=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e54b7     PUSH       offset DAT_fffffff4
    //         004e54bc     MOV        this,EDI
    //         004e54be     LEA        EBX,[ESI + 0x9dc]
    //         004e54c4     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e54c9     PUSH       EAX=>DAT_fffffff4
    //         004e54ca     MOV        this,EBX
    //         004e54cc     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:432 (24)
    //         004e54d1     PUSH       0x0
    //         004e54d3     PUSH       offset DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e54d5     PUSH       offset DAT_fffffff4
    //         004e54da     MOV        this,EDI
    //         004e54dc     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e54e1     PUSH       EAX=>DAT_fffffff4
    //         004e54e2     MOV        this,EBX
    //         004e54e4     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:434 (32)
    //         004e54e9     MOV        EDX,dword ptr [ESI + 0x1256c]
    //         004e54ef     PUSH       0x3
    //                              language.dll match for 0x80: "Arial"
    //         004e54f1     PUSH       offset DAT_fffffff8
    //         004e54f6     MOV        this,EDI
    //         004e54f8     MOV        EBX,dword ptr [EDX]
    //         004e54fa     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e54ff     MOV        this,dword ptr [ESI + 0x1256c]
    //         004e5505     PUSH       EAX=>DAT_fffffff8
    //         004e5506     CALL       dword ptr [EBX + 0x28]
    //                              taimdmd.cpp:437 (26)
    //         004e5509     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e550f     LEA        EDX,[ESP + 0x54]
    //         004e5513     PUSH       0x100
    //         004e5518     PUSH       EDX=>DAT_fffffff8
    //         004e5519     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x901: "You dare defy me?! Prepare to 
    //         004e551b     PUSH       offset DAT_fffffff4
    //         004e5520     CALL       dword ptr [EAX + 0x20]
    //                              taimdmd.cpp:438 (32)
    //         004e5523     LEA        EAX,[ESP + 0x54]
    //         004e5527     MOV        this,EDI
    //         004e5529     PUSH       EAX
    //         004e552a     PUSH       0x0=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e552c     PUSH       offset DAT_fffffff4
    //         004e5531     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5536     MOV        this,dword ptr [ESI + 0xf0]
    //         004e553c     PUSH       EAX=>DAT_fffffff4
    //         004e553d     PUSH       this=>DAT_fffffff0
    //         004e553e     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //                              taimdmd.cpp:442 (19)
    //         004e5543     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e5549     MOV        dword ptr [ESI + 0x1258c],0x0
    //         004e5553     ADD        ESP,0x10
    //                              taimdmd.cpp:447 (50)
    //         004e5556     XOR        EBX,EBX
    //         004e5558     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004e555b     MOV        this,dword ptr [EAX + 0x4]
    //         004e555e     MOV        dword ptr [ESI + 0x12594],0x1
    //         004e5568     MOV        dword ptr [ESI + 0x12584],this
    //         004e556e     JMP        LAB_004e56fa
    //                              language.dll match for 0x81: "10"
    //                               LAB_004e5573                                                 XREF[1]:     004e54ad(j)  
    //         004e5573     PUSH       0x81
    //         004e5578     MOV        this,EDI
    //         004e557a     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e557f     CMP        EAX,0x1
    //         004e5582     JNZ        LAB_004e56fa
    //                              taimdmd.cpp:449 (26)
    //         004e5588     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e558e     LEA        EAX,[ESP + 0x54]
    //         004e5592     PUSH       0x100
    //         004e5597     PUSH       EAX=>DAT_fffffff8
    //         004e5598     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0x900: "Alas! We could have made an un
    //         004e559a     PUSH       offset DAT_fffffff4
    //         004e559f     CALL       dword ptr [EDX + 0x20]
    //                              taimdmd.cpp:450 (4)
    //         004e55a2     LEA        this,[ESP + 0x54]
    //                              taimdmd.cpp:462 (26)
    //         004e55a6     JMP        LAB_004e5646
    //                              language.dll match for 0x7c: "B"
    //                               LAB_004e55ab                                                 XREF[1]:     004e5498(j)  
    //         004e55ab     PUSH       0x7c
    //         004e55ad     MOV        this,EDI
    //         004e55af     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e55b4     CMP        dword ptr [ESI + 0x12598],EAX
    //         004e55ba     JL         LAB_004e56fa
    //                              language.dll match for 0x81: "10"
    //                              taimdmd.cpp:467 (21)
    //         004e55c0     PUSH       0x81
    //         004e55c5     MOV        this,EDI
    //         004e55c7     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e55cc     CMP        EAX,0x1
    //         004e55cf     JNZ        LAB_004e567e
    //                              taimdmd.cpp:474 (28)
    //         004e55d5     PUSH       EBX
    //         004e55d6     PUSH       EBX=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e55d7     PUSH       offset DAT_fffffff4
    //         004e55dc     MOV        this,EDI
    //         004e55de     LEA        EBP,[ESI + 0x9dc]
    //         004e55e4     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e55e9     PUSH       EAX=>DAT_fffffff4
    //         004e55ea     MOV        this,EBP
    //         004e55ec     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:477 (24)
    //         004e55f1     PUSH       0x64
    //         004e55f3     PUSH       offset DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e55f5     PUSH       offset DAT_fffffff4
    //         004e55fa     MOV        this,EDI
    //         004e55fc     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5601     PUSH       EAX=>DAT_fffffff4
    //         004e5602     MOV        this,EBP
    //         004e5604     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:479 (31)
    //         004e5609     MOV        EAX,dword ptr [ESI + 0x1256c]
    //         004e560f     PUSH       EBX
    //                              language.dll match for 0x80: "Arial"
    //         004e5610     PUSH       offset DAT_fffffff8
    //         004e5615     MOV        this,EDI
    //         004e5617     MOV        EBP,dword ptr [EAX]
    //         004e5619     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e561e     MOV        this,dword ptr [ESI + 0x1256c]
    //         004e5624     PUSH       EAX=>DAT_fffffff8
    //         004e5625     CALL       dword ptr [EBP + 0x28]
    //                              taimdmd.cpp:482 (26)
    //         004e5628     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e562e     LEA        EAX,[ESP + 0x54]
    //         004e5632     PUSH       0x100
    //         004e5637     PUSH       EAX=>DAT_fffffff8
    //         004e5638     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0x8ff: "You have made a wise choice --
    //         004e563a     PUSH       offset DAT_fffffff4
    //         004e563f     CALL       dword ptr [EDX + 0x20]
    //                              taimdmd.cpp:483 (31)
    //         004e5642     LEA        this,[ESP + 0x54]
    //                               LAB_004e5646                                                 XREF[1]:     004e55a6(j)  
    //         004e5646     PUSH       this
    //         004e5647     PUSH       EBX=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e5648     PUSH       offset DAT_fffffff4
    //         004e564d     MOV        this,EDI
    //         004e564f     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5654     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e565a     PUSH       EAX=>DAT_fffffff4
    //         004e565b     PUSH       EDX=>DAT_fffffff0
    //         004e565c     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //                              taimdmd.cpp:487 (27)
    //         004e5661     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5667     MOV        dword ptr [ESI + 0x1258c],EBX
    //         004e566d     ADD        ESP,0x10
    //         004e5670     MOV        this,dword ptr [EAX + 0x3c]
    //         004e5673     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e5676     MOV        dword ptr [ESI + 0x12584],EDX
    //                              taimdmd.cpp:498 (19)
    //         004e567c     JMP        LAB_004e56e3
    //                              language.dll match for 0x82: "B"
    //                               LAB_004e567e                                                 XREF[1]:     004e55cf(j)  
    //         004e567e     PUSH       0x82
    //         004e5683     MOV        this,EDI
    //         004e5685     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e568a     CMP        EAX,0x1
    //         004e568d     JNZ        LAB_004e56fa
    //                              taimdmd.cpp:500 (26)
    //         004e568f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e5695     LEA        EDX,[ESP + 0x54]
    //         004e5699     PUSH       0x100
    //         004e569e     PUSH       EDX=>DAT_fffffff8
    //         004e569f     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x8fe: "It was wise to do as I request
    //         004e56a1     PUSH       offset DAT_fffffff4
    //         004e56a6     CALL       dword ptr [EAX + 0x20]
    //                              taimdmd.cpp:501 (31)
    //         004e56a9     LEA        EAX,[ESP + 0x54]
    //         004e56ad     MOV        this,EDI
    //         004e56af     PUSH       EAX
    //         004e56b0     PUSH       EBX=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e56b1     PUSH       offset DAT_fffffff4
    //         004e56b6     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e56bb     MOV        this,dword ptr [ESI + 0xf0]
    //         004e56c1     PUSH       EAX=>DAT_fffffff4
    //         004e56c2     PUSH       this=>DAT_fffffff0
    //         004e56c3     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //                              taimdmd.cpp:505 (27)
    //         004e56c8     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e56ce     MOV        dword ptr [ESI + 0x1258c],EBX
    //         004e56d4     ADD        ESP,0x10
    //         004e56d7     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004e56da     MOV        this,dword ptr [EAX + 0x4]
    //         004e56dd     MOV        dword ptr [ESI + 0x12584],this
    //                              language.dll match for 0x84: "8"
    //                               LAB_004e56e3                                                 XREF[1]:     004e567c(j)  
    //                              taimdmd.cpp:506 (23)
    //         004e56e3     PUSH       0x84
    //         004e56e8     MOV        this,EDI
    //         004e56ea     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e56ef     NEG        EAX
    //         004e56f1     SBB        EAX,EAX
    //         004e56f3     INC        EAX
    //         004e56f4     MOV        dword ptr [ESI + 0x12594],EAX
    //                               LAB_004e56fa                                                 XREF[9]:     004e52c2(j), 004e52ce(j), 
    //                                                                                                         004e5416(j), 004e5468(j), 
    //                                                                                                         004e5474(j), 004e556e(j), 
    //                                                                                                         004e5582(j), 004e55ba(j), 
    //                                                                                                         004e568d(j)  
    //                              taimdmd.cpp:519 (34)
    //         004e56fa     CMP        dword ptr [ESI + 0x1259c],EBX
    //         004e5700     JNZ        LAB_004e5bb1
    //         004e5706     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e570c     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004e570f     CMP        dword ptr [EDX + 0x4],0x2710
    //         004e5716     JBE        LAB_004e5bb1
    //                              taimdmd.cpp:524 (11)
    //         004e571c     MOV        EBP,0x1
    //         004e5721     MOV        dword ptr [ESI + 0x1259c],EBP
    //                              taimdmd.cpp:525 (3)
    //         004e5727     MOV        EBX,dword ptr [EAX + 0x3c]
    //                              taimdmd.cpp:528 (6)
    //         004e572a     XOR        EAX,EAX
    //         004e572c     MOV        dword ptr [ESP + 0x14],EBX
    //                              taimdmd.cpp:533 (18)
    //         004e5730     CMP        word ptr [EBX + 0x3c],BP
    //         004e5734     MOV        dword ptr [ESP + 0x10],EAX
    //         004e5738     MOV        dword ptr [ESP + 0x1c],EAX
    //         004e573c     MOV        dword ptr [ESP + 0x18],EAX
    //         004e5740     JLE        LAB_004e5792
    //                               LAB_004e5742                                                 XREF[1]:     004e5790(j)  
    //                              taimdmd.cpp:534 (6)
    //         004e5742     MOV        EAX,dword ptr [EBX + 0x40]
    //         004e5745     MOV        EDI,dword ptr [EAX + EBP*0x4]
    //                              taimdmd.cpp:536 (11)
    //         004e5748     MOV        this,EDI
    //         004e574a     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e574f     TEST       EAX,EAX
    //         004e5751     JNZ        LAB_004e5759
    //                              taimdmd.cpp:540 (4)
    //         004e5753     INC        dword ptr [ESP + 0x1c]
    //                              taimdmd.cpp:542 (2)
    //         004e5757     JMP        LAB_004e5789
    //                               LAB_004e5759                                                 XREF[1]:     004e5751(j)  
    //                              taimdmd.cpp:546 (4)
    //         004e5759     MOV        EDX,dword ptr [ESP + 0x10]
    //                              taimdmd.cpp:550 (17)
    //         004e575d     MOV        this,EDI
    //         004e575f     INC        EDX
    //         004e5760     MOV        dword ptr [ESP + 0x10],EDX
    //         004e5764     MOV        EDX,dword ptr [EDI]
    //         004e5766     CALL       dword ptr [EDX + 0x24]
    //         004e5769     CMP        EAX,0x1
    //         004e576c     JNZ        LAB_004e5781
    //                              taimdmd.cpp:551 (4)
    //         004e576e     MOV        EAX,dword ptr [ESP + 0x18]
    //                              taimdmd.cpp:552 (13)
    //         004e5772     MOV        dword ptr [ESP + EBP*0x4 + 0x30],0x1
    //         004e577a     INC        EAX
    //         004e577b     MOV        dword ptr [ESP + 0x18],EAX
    //                              taimdmd.cpp:554 (2)
    //         004e577f     JMP        LAB_004e5789
    //                               LAB_004e5781                                                 XREF[1]:     004e576c(j)  
    //                              taimdmd.cpp:555 (8)
    //         004e5781     MOV        dword ptr [ESP + EBP*0x4 + 0x30],0x0
    //                               LAB_004e5789                                                 XREF[2]:     004e5757(j), 004e577f(j)  
    //                              taimdmd.cpp:533 (9)
    //         004e5789     MOVSX      EAX,word ptr [EBX + 0x3c]
    //         004e578d     INC        EBP
    //         004e578e     CMP        EBP,EAX
    //         004e5790     JL         LAB_004e5742
    //                               LAB_004e5792                                                 XREF[1]:     004e5740(j)  
    //                              taimdmd.cpp:561 (9)
    //         004e5792     CMP        byte ptr [EBX + 0x11d],0xff
    //         004e5799     JNZ        LAB_004e5813
    //                              taimdmd.cpp:563 (7)
    //         004e579b     CMP        dword ptr [ESP + 0x10],0x1
    //         004e57a0     JNZ        LAB_004e57b7
    //                              taimdmd.cpp:564 (19)
    //         004e57a2     MOV        this,dword ptr [ESI + 0xf0]
    //         004e57a8     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e57ac     MOV        DL,byte ptr [ECX + this+0x4a]
    //         004e57af     MOV        byte ptr [EAX + 0x11d],DL
    //                              taimdmd.cpp:565 (2)
    //         004e57b5     JMP        LAB_004e5813
    //                               LAB_004e57b7                                                 XREF[1]:     004e57a0(j)  
    //                              taimdmd.cpp:566 (20)
    //         004e57b7     PUSH       0x236
    //         004e57bc     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e57c1     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e57c6     CDQ
    //         004e57c7     IDIV       dword ptr [ESP + 0x18]
    //                              taimdmd.cpp:567 (21)
    //         004e57cb     MOV        this,dword ptr [ESP + 0x1c]
    //         004e57cf     ADD        ESP,0x8
    //         004e57d2     MOV        EBP,0x1
    //         004e57d7     MOV        EBX,EDX
    //         004e57d9     INC        EBX
    //         004e57da     CMP        word ptr [ECX + this->_padding_],BP
    //         004e57de     JLE        LAB_004e5813
    //                               LAB_004e57e0                                                 XREF[1]:     004e5811(j)  
    //                              taimdmd.cpp:568 (10)
    //         004e57e0     MOV        EDX,dword ptr [ESP + 0x14]
    //         004e57e4     MOV        EAX,dword ptr [EDX + 0x40]
    //         004e57e7     MOV        EDI,dword ptr [EAX + EBP*0x4]
    //                              taimdmd.cpp:571 (12)
    //         004e57ea     MOV        this,EDI
    //         004e57ec     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e57f1     CMP        EAX,0x1
    //         004e57f4     JNZ        LAB_004e5806
    //                              taimdmd.cpp:572 (1)
    //         004e57f6     DEC        EBX
    //                              taimdmd.cpp:573 (2)
    //         004e57f7     JNZ        LAB_004e5806
    //                              taimdmd.cpp:574 (26)
    //         004e57f9     MOV        EDX,dword ptr [ESP + 0x14]
    //         004e57fd     MOV        this,byte ptr [EDI + 0x4a]
    //         004e5800     MOV        byte ptr [EDX + 0x11d],this
    //                               LAB_004e5806                                                 XREF[2]:     004e57f4(j), 004e57f7(j)  
    //         004e5806     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e580a     INC        EBP
    //         004e580b     MOVSX      this,word ptr [EAX + 0x3c]
    //         004e580f     CMP        EBP,this
    //         004e5811     JL         LAB_004e57e0
    //                               LAB_004e5813                                                 XREF[3]:     004e5799(j), 004e57b5(j), 
    //                                                                                                         004e57de(j)  
    //                              taimdmd.cpp:581 (27)
    //         004e5813     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e5817     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e581d     MOV        this,byte ptr [EAX + 0x11d]
    //         004e5823     MOV        AL,byte ptr [EDX + 0x4a]
    //         004e5826     CMP        this,AL
    //         004e5828     JNZ        LAB_004e5bb1
    //                              taimdmd.cpp:582 (21)
    //         004e582e     MOV        EAX,dword ptr [ESP + 0x10]
    //         004e5832     MOV        EDX,dword ptr [ESP + 0x1c]
    //         004e5836     SUB        EAX,EDX
    //         004e5838     CDQ
    //         004e5839     SUB        EAX,EDX
    //         004e583b     MOV        EBX,EAX
    //         004e583d     SAR        EBX,0x1
    //         004e583f     MOV        dword ptr [ESP + 0x10],EBX
    //                              taimdmd.cpp:583 (2)
    //         004e5843     JNS        LAB_004e584b
    //                              taimdmd.cpp:584 (6)
    //         004e5845     XOR        EBX,EBX
    //         004e5847     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_004e584b                                                 XREF[1]:     004e5843(j)  
    //                              taimdmd.cpp:585 (8)
    //         004e584b     MOV        EDI,dword ptr [ESP + 0x18]
    //         004e584f     CMP        EBX,EDI
    //         004e5851     JLE        LAB_004e5859
    //                              taimdmd.cpp:586 (6)
    //         004e5853     MOV        EBX,EDI
    //         004e5855     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_004e5859                                                 XREF[1]:     004e5851(j)  
    //                              taimdmd.cpp:589 (15)
    //         004e5859     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e585f     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
    //         004e5864     CMP        AL,0x1
    //         004e5866     JNZ        LAB_004e586e
    //                              taimdmd.cpp:590 (6)
    //         004e5868     XOR        EBX,EBX
    //         004e586a     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_004e586e                                                 XREF[1]:     004e5866(j)  
    //                              taimdmd.cpp:598 (20)
    //         004e586e     CMP        EDI,EBX
    //         004e5870     JL         LAB_004e5bb1
    //         004e5876     MOV        EAX,dword ptr [ESP + 0x18]
    //         004e587a     TEST       EAX,EAX
    //         004e587c     JLE        LAB_004e5bb1
    //                              taimdmd.cpp:602 (20)
    //         004e5882     XOR        EAX,EAX
    //         004e5884     XOR        EBX,EBX
    //         004e5886     MOV        dword ptr [ESP + 0x20],EAX
    //         004e588a     MOV        dword ptr [ESP + 0x24],EBX
    //         004e588e     MOV        dword ptr [ESP + 0x28],EAX
    //         004e5892     MOV        dword ptr [ESP + 0x2c],EAX
    //                              taimdmd.cpp:604 (30)
    //         004e5896     MOV        EDX,dword ptr [ESP + 0x14]
    //         004e589a     MOV        EBP,0x1
    //         004e589f     MOV        dword ptr [ESP + 0x15c],EAX
    //         004e58a6     MOV        dword ptr [ESP + 0x18],EBP
    //         004e58aa     CMP        word ptr [EDX + 0x3c],BP
    //         004e58ae     JLE        LAB_004e59a1
    //                               LAB_004e58b4                                                 XREF[1]:     004e599b(j)  
    //                              taimdmd.cpp:605 (10)
    //         004e58b4     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e58b8     MOV        this,dword ptr [EAX + 0x40]
    //         004e58bb     MOV        EDI,dword ptr [this->_padding_ + EBP*0x4]
    //                              taimdmd.cpp:607 (27)
    //         004e58be     MOV        this,EDI
    //         004e58c0     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e58c5     TEST       EAX,EAX
    //         004e58c7     JZ         LAB_004e598c
    //         004e58cd     MOV        EAX,dword ptr [ESP + EBP*0x4 + 0x30]
    //         004e58d1     TEST       EAX,EAX
    //         004e58d3     JZ         LAB_004e598c
    //                              taimdmd.cpp:610 (32)
    //         004e58d9     MOV        EDX,dword ptr [ESP + 0x14]
    //         004e58dd     MOVZX      AX,byte ptr [EDX + 0x11d]
    //         004e58e5     CMP        AX,word ptr [EDI + 0x4a]
    //         004e58e9     JZ         LAB_004e598c
    //         004e58ef     CMP        EBX,dword ptr [ESP + 0x10]
    //         004e58f3     JGE        LAB_004e598c
    //                              taimdmd.cpp:613 (6)
    //         004e58f9     XOR        EAX,EAX
    //         004e58fb     TEST       EBX,EBX
    //         004e58fd     JLE        LAB_004e5919
    //                              taimdmd.cpp:784 (8)
    //         004e58ff     MOV        this,dword ptr [ESP + 0x20]
    //         004e5903     MOV        EDX,dword ptr [ESP + 0x2c]
    //                               LAB_004e5907                                                 XREF[1]:     004e5915(j)  
    //                              taimdmd.cpp:613 (66)
    //         004e5907     CMP        EAX,EDX
    //         004e5909     JGE        LAB_004e591d
    //         004e590b     CMP        dword ptr [this->_padding_],EBP
    //         004e590d     JZ         LAB_004e598c
    //         004e590f     INC        EAX
    //         004e5910     ADD        this,0x4
    //         004e5913     CMP        EAX,EBX
    //         004e5915     JL         LAB_004e5907
    //         004e5917     JMP        LAB_004e591d
    //                               LAB_004e5919                                                 XREF[1]:     004e58fd(j)  
    //         004e5919     MOV        EDX,dword ptr [ESP + 0x2c]
    //                               LAB_004e591d                                                 XREF[2]:     004e5909(j), 004e5917(j)  
    //         004e591d     DEC        EDX
    //         004e591e     CMP        EBX,EDX
    //         004e5920     JLE        LAB_004e597f
    //         004e5922     LEA        EBP,[EBX + 0x1]
    //         004e5925     LEA        this,[EBP*0x4 + 0x0]
    //         004e592c     PUSH       this
    //         004e592d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e5932     MOV        EDI,EAX
    //         004e5934     ADD        ESP,0x4
    //         004e5937     TEST       EDI,EDI
    //         004e5939     JZ         LAB_004e597b
    //         004e593b     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004e593f     XOR        this,this
    //         004e5941     TEST       EAX,EAX
    //         004e5943     JLE        LAB_004e5966
    //         004e5945     MOV        EDX,dword ptr [ESP + 0x20]
    //                              taimdmd.cpp:784 (4)
    //         004e5949     MOV        EAX,EDI
    //         004e594b     SUB        EDX,EDI
    //                               LAB_004e594d                                                 XREF[1]:     004e5964(j)  
    //                              taimdmd.cpp:613 (84)
    //         004e594d     CMP        this,EBP
    //         004e594f     JGE        LAB_004e5966
    //         004e5951     MOV        EBX,dword ptr [EDX + EAX*0x1]
    //         004e5954     INC        this
    //         004e5955     MOV        dword ptr [EAX],EBX
    //         004e5957     MOV        EBX,dword ptr [ESP + 0x2c]
    //         004e595b     ADD        EAX,0x4
    //         004e595e     CMP        this,EBX
    //         004e5960     MOV        EBX,dword ptr [ESP + 0x24]
    //         004e5964     JL         LAB_004e594d
    //                               LAB_004e5966                                                 XREF[2]:     004e5943(j), 004e594f(j)  
    //         004e5966     MOV        EDX,dword ptr [ESP + 0x20]
    //         004e596a     PUSH       EDX
    //         004e596b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e5970     ADD        ESP,0x4
    //         004e5973     MOV        dword ptr [ESP + 0x20],EDI
    //         004e5977     MOV        dword ptr [ESP + 0x2c],EBP
    //                               LAB_004e597b                                                 XREF[1]:     004e5939(j)  
    //         004e597b     MOV        EBP,dword ptr [ESP + 0x18]
    //                               LAB_004e597f                                                 XREF[1]:     004e5920(j)  
    //         004e597f     MOV        EAX,dword ptr [ESP + 0x20]
    //         004e5983     INC        EBX
    //         004e5984     MOV        dword ptr [ESP + 0x24],EBX
    //         004e5988     MOV        dword ptr [EAX + EBX*0x4 + -0x4],EBP
    //                               LAB_004e598c                                                 XREF[5]:     004e58c7(j), 004e58d3(j), 
    //                                                                                                         004e58e9(j), 004e58f3(j), 
    //                                                                                                         004e590d(j)  
    //         004e598c     MOV        this,dword ptr [ESP + 0x14]
    //         004e5990     INC        EBP
    //         004e5991     MOV        dword ptr [ESP + 0x18],EBP
    //         004e5995     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004e5999     CMP        EBP,EDX
    //         004e599b     JL         LAB_004e58b4
    //                               LAB_004e59a1                                                 XREF[1]:     004e58ae(j)  
    //                              taimdmd.cpp:621 (35)
    //         004e59a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              language.dll match for 0x7d0: "place holder"
    //         004e59a7     MOV        dword ptr [ESP + 0x10],0x7d0
    //         004e59af     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
    //         004e59b4     CMP        EAX,0x4
    //         004e59b7     JA         switchD_004e59bd::default
    //                               switchD_004e59bd::switchD
    //         004e59bd     JMP        dword ptr [EAX*0x4 + switchD_004e59bd::switchd   = 004e59c4
    //                               switchD_004e59bd::caseD_0                                    XREF[2]:     004e59bd(j), 004e5d98(*)  
    //                              taimdmd.cpp:622 (37)
    //         004e59c4     PUSH       0x26e
    //         004e59c9     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e59ce     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e59d3     CDQ
    //         004e59d4     MOV        this,0x1f4
    //         004e59d9     ADD        ESP,0x8
    //         004e59dc     IDIV       this
    //         004e59de     ADD        EDX,0x578
    //         004e59e4     JMP        LAB_004e5a6f
    //                               switchD_004e59bd::caseD_1                                    XREF[2]:     004e59bd(j), 004e5d9c(*)  
    //                              taimdmd.cpp:623 (34)
    //         004e59e9     PUSH       0x26f
    //         004e59ee     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e59f3     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e59f8     CDQ
    //         004e59f9     MOV        this,0x190
    //         004e59fe     ADD        ESP,0x8
    //         004e5a01     IDIV       this
    //         004e5a03     ADD        EDX,0x3e8
    //         004e5a09     JMP        LAB_004e5a6f
    //                               switchD_004e59bd::caseD_2                                    XREF[2]:     004e59bd(j), 004e5da0(*)  
    //                              taimdmd.cpp:624 (34)
    //         004e5a0b     PUSH       0x270
    //         004e5a10     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e5a15     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e5a1a     CDQ
    //         004e5a1b     MOV        this,0x12c
    //         004e5a20     ADD        ESP,0x8
    //         004e5a23     IDIV       this
    //         004e5a25     ADD        EDX,0x2bc
    //         004e5a2b     JMP        LAB_004e5a6f
    //                               switchD_004e59bd::caseD_3                                    XREF[2]:     004e59bd(j), 004e5da4(*)  
    //                              taimdmd.cpp:625 (34)
    //         004e5a2d     PUSH       0x271
    //         004e5a32     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e5a37     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e5a3c     CDQ
    //         004e5a3d     MOV        this,0xc8
    //         004e5a42     ADD        ESP,0x8
    //         004e5a45     IDIV       this
    //         004e5a47     ADD        EDX,0x1c2
    //         004e5a4d     JMP        LAB_004e5a6f
    //                               switchD_004e59bd::caseD_4                                    XREF[2]:     004e59bd(j), 004e5da8(*)  
    //                              taimdmd.cpp:626 (36)
    //         004e5a4f     PUSH       0x272
    //         004e5a54     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e5a59     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e5a5e     CDQ
    //         004e5a5f     MOV        this,0x64
    //         004e5a64     ADD        ESP,0x8
    //         004e5a67     IDIV       this
    //         004e5a69     ADD        EDX,0x12c
    //                               LAB_004e5a6f                                                 XREF[4]:     004e59e4(j), 004e5a09(j), 
    //                                                                                                         004e5a2b(j), 004e5a4d(j)  
    //         004e5a6f     MOV        dword ptr [ESP + 0x10],EDX
    //                               switchD_004e59bd::default                                    XREF[1]:     004e59b7(j)  
    //                              taimdmd.cpp:633 (27)
    //         004e5a73     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e5a77     MOV        this,0x1
    //         004e5a7c     MOV        dword ptr [ESP + 0x18],this
    //         004e5a80     CMP        word ptr [EAX + 0x3c],this
    //         004e5a84     JLE        LAB_004e5b95
    //                               LAB_004e5a8a                                                 XREF[1]:     004e5b8f(j)  
    //         004e5a8a     MOV        EDI,dword ptr [ESP + 0x18]
    //                              taimdmd.cpp:634 (6)
    //         004e5a8e     MOV        EDX,dword ptr [EAX + 0x40]
    //         004e5a91     MOV        EBP,dword ptr [EDX + EDI*0x4]
    //                              taimdmd.cpp:636 (27)
    //         004e5a94     MOV        this,EBP
    //         004e5a96     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e5a9b     TEST       EAX,EAX
    //         004e5a9d     JZ         LAB_004e5b7c
    //         004e5aa3     MOV        EAX,dword ptr [ESP + EDI*0x4 + 0x30]
    //         004e5aa7     TEST       EAX,EAX
    //         004e5aa9     JZ         LAB_004e5b7c
    //                              taimdmd.cpp:639 (6)
    //         004e5aaf     XOR        EAX,EAX
    //         004e5ab1     TEST       EBX,EBX
    //         004e5ab3     JLE        LAB_004e5af4
    //                              taimdmd.cpp:784 (8)
    //         004e5ab5     MOV        this,dword ptr [ESP + 0x20]
    //         004e5ab9     MOV        EDX,dword ptr [ESP + 0x2c]
    //                               LAB_004e5abd                                                 XREF[1]:     004e5acb(j)  
    //                              taimdmd.cpp:639 (18)
    //         004e5abd     CMP        EAX,EDX
    //         004e5abf     JGE        LAB_004e5af4
    //         004e5ac1     CMP        dword ptr [this->_padding_],EDI
    //         004e5ac3     JZ         LAB_004e5acf
    //         004e5ac5     INC        EAX
    //         004e5ac6     ADD        this,0x4
    //         004e5ac9     CMP        EAX,EBX
    //         004e5acb     JL         LAB_004e5abd
    //         004e5acd     JMP        LAB_004e5af4
    //                               LAB_004e5acf                                                 XREF[1]:     004e5ac3(j)  
    //                              taimdmd.cpp:646 (30)
    //         004e5acf     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5ad5     MOV        EDI,dword ptr [ESP + 0x10]
    //         004e5ad9     MOV        EAX,dword ptr [EBP]
    //         004e5adc     PUSH       0x0
    //         004e5ade     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004e5ae2     PUSH       0x0=>DAT_fffffff8
    //         004e5ae4     PUSH       EDI=>DAT_fffffff4
    //         004e5ae5     PUSH       offset DAT_fffffff0
    //         004e5ae7     PUSH       EDX
    //         004e5ae8     MOV        this,EBP
    //         004e5aea     CALL       dword ptr [EAX + 0x54]
    //                              taimdmd.cpp:647 (7)
    //         004e5aed     LEA        EAX,[EDI + EDI*0x1]
    //         004e5af0     MOV        dword ptr [ESP + 0x10],EAX
    //                               LAB_004e5af4                                                 XREF[3]:     004e5ab3(j), 004e5abf(j), 
    //                                                                                                         004e5acd(j)  
    //                              taimdmd.cpp:661 (15)
    //         004e5af4     MOV        this,dword ptr [ESP + 0x14]
    //         004e5af8     MOV        EDI,0x1
    //         004e5afd     CMP        word ptr [ECX + this->_padding_],DI
    //         004e5b01     JLE        LAB_004e5b7c
    //                               LAB_004e5b03                                                 XREF[1]:     004e5b7a(j)  
    //                              taimdmd.cpp:662 (6)
    //         004e5b03     CMP        dword ptr [ESP + 0x18],EDI
    //         004e5b07     JZ         LAB_004e5b6f
    //                              taimdmd.cpp:664 (14)
    //         004e5b09     MOV        EDX,dword ptr [ESP + 0x14]
    //         004e5b0d     MOV        EAX,dword ptr [EDX + 0x40]
    //         004e5b10     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004e5b13     MOV        dword ptr [ESP + 0x1c],this
    //                              taimdmd.cpp:667 (39)
    //         004e5b17     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e5b1c     TEST       EAX,EAX
    //         004e5b1e     JNZ        LAB_004e5b47
    //         004e5b20     TEST       EBX,EBX
    //         004e5b22     JLE        LAB_004e5b3e
    //         004e5b24     MOV        this,dword ptr [ESP + 0x20]
    //                               LAB_004e5b28                                                 XREF[1]:     004e5b3c(j)  
    //         004e5b28     CMP        EAX,dword ptr [ESP + 0x2c]
    //         004e5b2c     JGE        LAB_004e5b3e
    //         004e5b2e     MOV        EDX,dword ptr [ESP + 0x18]
    //         004e5b32     CMP        dword ptr [this->_padding_],EDX
    //         004e5b34     JZ         LAB_004e5b47
    //         004e5b36     INC        EAX
    //         004e5b37     ADD        this,0x4
    //         004e5b3a     CMP        EAX,EBX
    //         004e5b3c     JL         LAB_004e5b28
    //                               LAB_004e5b3e                                                 XREF[2]:     004e5b22(j), 004e5b2c(j)  
    //                              taimdmd.cpp:673 (7)
    //         004e5b3e     MOV        EAX,dword ptr [EBP]
    //         004e5b41     PUSH       0x0
    //         004e5b43     PUSH       0x0=>DAT_fffffff8
    //                              taimdmd.cpp:676 (16)
    //         004e5b45     JMP        LAB_004e5b5c
    //                               LAB_004e5b47                                                 XREF[2]:     004e5b1e(j), 004e5b34(j)  
    //         004e5b47     MOV        this,dword ptr [ESP + 0x1c]
    //         004e5b4b     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e5b50     CMP        EAX,0x1
    //         004e5b53     JNZ        LAB_004e5b6f
    //                              taimdmd.cpp:682 (39)
    //         004e5b55     MOV        EAX,dword ptr [EBP]
    //         004e5b58     PUSH       0x0
    //         004e5b5a     PUSH       offset DAT_fffffff8
    //                               LAB_004e5b5c                                                 XREF[1]:     004e5b45(j)  
    //         004e5b5c     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5b62     PUSH       EDI=>DAT_fffffff4
    //         004e5b63     PUSH       offset DAT_fffffff0
    //         004e5b65     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004e5b69     PUSH       EDX
    //         004e5b6a     MOV        this,EBP
    //         004e5b6c     CALL       dword ptr [EAX + 0x54]
    //                               LAB_004e5b6f                                                 XREF[2]:     004e5b07(j), 004e5b53(j)  
    //         004e5b6f     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e5b73     INC        EDI
    //         004e5b74     MOVSX      this,word ptr [EAX + 0x3c]
    //         004e5b78     CMP        EDI,this
    //         004e5b7a     JL         LAB_004e5b03
    //                               LAB_004e5b7c                                                 XREF[3]:     004e5a9d(j), 004e5aa9(j), 
    //                                                                                                         004e5b01(j)  
    //                              taimdmd.cpp:633 (25)
    //         004e5b7c     MOV        EAX,dword ptr [ESP + 0x14]
    //         004e5b80     MOV        this,dword ptr [ESP + 0x18]
    //         004e5b84     INC        this
    //         004e5b85     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         004e5b89     CMP        this,EDX
    //         004e5b8b     MOV        dword ptr [ESP + 0x18],this
    //         004e5b8f     JL         LAB_004e5a8a
    //                               LAB_004e5b95                                                 XREF[1]:     004e5a84(j)  
    //                              taimdmd.cpp:687 (28)
    //         004e5b95     MOV        EAX,dword ptr [ESP + 0x20]
    //         004e5b99     MOV        dword ptr [ESP + 0x15c],0xffffffff
    //         004e5ba4     TEST       EAX,EAX
    //         004e5ba6     JZ         LAB_004e5bb1
    //         004e5ba8     PUSH       EAX
    //         004e5ba9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e5bae     ADD        ESP,0x4
    //                               LAB_004e5bb1                                                 XREF[6]:     004e5700(j), 004e5716(j), 
    //                                                                                                         004e5828(j), 004e5870(j), 
    //                                                                                                         004e587c(j), 004e5ba6(j)  
    //                              taimdmd.cpp:693 (27)
    //         004e5bb1     LEA        EDI,[ESI + 0x1146c]
    //         004e5bb7     PUSH       0xd9
    //         004e5bbc     MOV        this,EDI
    //         004e5bbe     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5bc3     CMP        EAX,0x1
    //         004e5bc6     JNZ        LAB_004e5d36
    //                              language.dll match for 0x68: "Arial"
    //                              taimdmd.cpp:701 (24)
    //         004e5bcc     PUSH       0x68
    //         004e5bce     MOV        this,EDI
    //         004e5bd0     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e5bd5     SUB        EAX,0x3
    //         004e5bd8     LEA        EAX,[EAX + EAX*0x4]
    //         004e5bdb     LEA        EAX,[EAX + EAX*0x4]
    //         004e5bde     LEA        EAX,[EAX + EAX*0x4]
    //         004e5be1     SHL        EAX,0x3
    //                              taimdmd.cpp:702 (2)
    //         004e5be4     JNS        LAB_004e5be8
    //                              taimdmd.cpp:703 (2)
    //         004e5be6     XOR        EAX,EAX
    //                               LAB_004e5be8                                                 XREF[1]:     004e5be4(j)  
    //                              taimdmd.cpp:705 (18)
    //         004e5be8     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5bee     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e5bf1     CMP        dword ptr [EDX + 0x4],EAX
    //         004e5bf4     JBE        LAB_004e5d36
    //                              taimdmd.cpp:710 (14)
    //         004e5bfa     PUSH       0x0
    //         004e5bfc     PUSH       offset DAT_fffffff8
    //         004e5c01     MOV        this,EDI
    //         004e5c03     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taimdmd.cpp:720 (27)
    //         004e5c08     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5c0e     MOV        EDI,0x1
    //         004e5c13     OR         EBX,0xffffffff
    //         004e5c16     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004e5c19     MOV        dword ptr [ESP + 0x10],EBX
    //         004e5c1d     CMP        word ptr [EAX + 0x3c],DI
    //         004e5c21     JLE        LAB_004e5c4d
    //                               LAB_004e5c23                                                 XREF[1]:     004e5c43(j)  
    //                              taimdmd.cpp:723 (36)
    //         004e5c23     MOV        this,dword ptr [EAX + 0x40]
    //         004e5c26     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
    //         004e5c29     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e5c2e     CMP        EAX,0x1
    //         004e5c31     JNZ        LAB_004e5c47
    //         004e5c33     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e5c39     INC        EDI
    //         004e5c3a     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004e5c3d     MOVSX      this,word ptr [EAX + 0x3c]
    //         004e5c41     CMP        EDI,this
    //         004e5c43     JL         LAB_004e5c23
    //         004e5c45     JMP        LAB_004e5c4d
    //                               LAB_004e5c47                                                 XREF[1]:     004e5c31(j)  
    //                              taimdmd.cpp:725 (6)
    //         004e5c47     MOV        EBX,EDI
    //         004e5c49     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_004e5c4d                                                 XREF[2]:     004e5c21(j), 004e5c45(j)  
    //                              taimdmd.cpp:730 (9)
    //         004e5c4d     CMP        EBX,-0x1
    //         004e5c50     JZ         LAB_004e5d36
    //                              taimdmd.cpp:735 (16)
    //         004e5c56     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5c5c     PUSH       EBX
    //         004e5c5d     MOV        EDX,dword ptr [this->_padding_]
    //         004e5c5f     CALL       dword ptr [EDX + 0x18]
    //         004e5c62     TEST       EAX,EAX
    //         004e5c64     JNZ        LAB_004e5c7d
    //                              taimdmd.cpp:736 (23)
    //         004e5c66     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5c6c     PUSH       0x0
    //         004e5c6e     PUSH       0x0=>DAT_fffffff8
    //         004e5c70     PUSH       EBX=>DAT_fffffff4
    //         004e5c71     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004e5c75     MOV        EAX,dword ptr [this->_padding_]
    //         004e5c77     PUSH       offset DAT_fffffff0
    //         004e5c79     PUSH       EDX
    //         004e5c7a     CALL       dword ptr [EAX + 0x54]
    //                               LAB_004e5c7d                                                 XREF[1]:     004e5c64(j)  
    //                              taimdmd.cpp:739 (30)
    //         004e5c7d     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5c83     MOV        EBP,0x1
    //         004e5c88     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004e5c8b     CMP        word ptr [EAX + 0x3c],BP
    //         004e5c8f     JLE        LAB_004e5d36
    //         004e5c95     JMP        LAB_004e5c9b
    //                               LAB_004e5c97                                                 XREF[1]:     004e5d30(j)  
    //         004e5c97     MOV        EBX,dword ptr [ESP + 0x10]
    //                               LAB_004e5c9b                                                 XREF[1]:     004e5c95(j)  
    //                              taimdmd.cpp:740 (12)
    //         004e5c9b     MOVSX      this,word ptr [ECX + this+0x4a]
    //         004e5c9f     CMP        EBP,this
    //         004e5ca1     JZ         LAB_004e5d20
    //         004e5ca3     CMP        EBP,EBX
    //         004e5ca5     JZ         LAB_004e5d20
    //                              taimdmd.cpp:742 (3)
    //         004e5ca7     MOV        EDX,dword ptr [EAX + 0x40]
    //                              taimdmd.cpp:745 (20)
    //         004e5caa     MOV        EAX,dword ptr [ESP + 0x10]
    //         004e5cae     PUSH       EAX
    //         004e5caf     MOV        EDI,dword ptr [EDX + EBP*0x4]
    //         004e5cb2     MOV        this,EDI
    //         004e5cb4     MOV        EBX,dword ptr [EDI]
    //         004e5cb6     CALL       dword ptr [EBX + 0x18]
    //         004e5cb9     CMP        EAX,0x1
    //         004e5cbc     JNZ        LAB_004e5cfa
    //                              taimdmd.cpp:750 (23)
    //         004e5cbe     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5cc4     PUSH       0x0
    //         004e5cc6     PUSH       offset DAT_fffffff8
    //         004e5cc8     PUSH       EBP=>DAT_fffffff4
    //         004e5cc9     MOVSX      EAX,word ptr [ECX + this+0x4a]
    //         004e5ccd     MOV        EDX,dword ptr [this->_padding_]
    //         004e5ccf     PUSH       offset DAT_fffffff0
    //         004e5cd1     PUSH       EAX
    //         004e5cd2     CALL       dword ptr [EDX + 0x54]
    //                              taimdmd.cpp:751 (12)
    //         004e5cd5     MOV        this,EDI
    //         004e5cd7     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         004e5cdc     CMP        EAX,0x1
    //         004e5cdf     JNZ        LAB_004e5d20
    //                              taimdmd.cpp:755 (23)
    //         004e5ce1     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5ce7     PUSH       0x0
    //         004e5ce9     PUSH       offset DAT_fffffff8
    //         004e5ceb     MOVSX      EAX,word ptr [ECX + this+0x4a]
    //         004e5cef     PUSH       EAX=>DAT_fffffff4
    //         004e5cf0     PUSH       offset DAT_fffffff0
    //         004e5cf2     PUSH       EAX
    //         004e5cf3     MOV        this,EDI
    //         004e5cf5     CALL       dword ptr [EBX + 0x54]
    //                              taimdmd.cpp:759 (17)
    //         004e5cf8     JMP        LAB_004e5d20
    //                               LAB_004e5cfa                                                 XREF[1]:     004e5cbc(j)  
    //         004e5cfa     MOV        EDX,dword ptr [ESP + 0x10]
    //         004e5cfe     MOV        this,EDI
    //         004e5d00     PUSH       EDX
    //         004e5d01     CALL       dword ptr [EBX + 0x1c]
    //         004e5d04     CMP        EAX,0x1
    //         004e5d07     JNZ        LAB_004e5d20
    //                              taimdmd.cpp:763 (45)
    //         004e5d09     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5d0f     PUSH       0x0
    //         004e5d11     PUSH       0x0=>DAT_fffffff8
    //         004e5d13     PUSH       EBP=>DAT_fffffff4
    //         004e5d14     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004e5d18     MOV        EAX,dword ptr [this->_padding_]
    //         004e5d1a     PUSH       offset DAT_fffffff0
    //         004e5d1c     PUSH       EDX
    //         004e5d1d     CALL       dword ptr [EAX + 0x54]
    //                               LAB_004e5d20                                                 XREF[5]:     004e5ca1(j), 004e5ca5(j), 
    //                                                                                                         004e5cdf(j), 004e5cf8(j), 
    //                                                                                                         004e5d07(j)  
    //         004e5d20     MOV        this,dword ptr [ESI + 0xf0]
    //         004e5d26     INC        EBP
    //         004e5d27     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004e5d2a     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         004e5d2e     CMP        EBP,EDX
    //         004e5d30     JL         LAB_004e5c97
    //                               LAB_004e5d36                                                 XREF[4]:     004e5bc6(j), 004e5bf4(j), 
    //                                                                                                         004e5c50(j), 004e5c8f(j)  
    //                              taimdmd.cpp:779 (28)
    //         004e5d36     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5d3c     MOV        this,dword ptr [EAX + 0x3c]
    //         004e5d3f     MOV        DL,byte ptr [ECX + this+0x1d]
    //         004e5d42     TEST       DL,DL
    //         004e5d44     JNZ        LAB_004e5d75
    //         004e5d46     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004e5d4a     CMP        dword ptr [ECX + this->_padding_],EAX
    //         004e5d50     JNZ        LAB_004e5d75
    //                              taimdmd.cpp:780 (17)
    //         004e5d52     MOV        EDX,dword ptr [ESI + 0x1146c]
    //         004e5d58     LEA        this,[ESI + 0x1146c]
    //         004e5d5e     PUSH       0x0
    //         004e5d60     CALL       dword ptr [EDX + 0x30]
    //                              taimdmd.cpp:781 (18)
    //         004e5d63     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e5d69     MOV        this,dword ptr [EAX + 0x3c]
    //         004e5d6c     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e5d6f     MOV        dword ptr [ESI + 0x12580],EDX
    //                               LAB_004e5d75                                                 XREF[2]:     004e5d44(j), 004e5d50(j)  
    //                              taimdmd.cpp:784 (55)
    //         004e5d75     MOV        this,dword ptr [ESP + 0x154]
    //         004e5d7c     POP        EDI
    //         004e5d7d     POP        ESI
    //         004e5d7e     POP        EBP
    //         004e5d7f     MOV        EAX,0x1
    //         004e5d84     MOV        dword ptr FS:[0x0],this
    //         004e5d8b     POP        EBX
    //         004e5d8c     ADD        ESP,0x150
    //         004e5d92     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004e5d95()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004e5d95
    //         004e5d95     NOP
    //         004e5d96     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e59bd::switchdataD_004e5d98                       XREF[1]:     update:004e59bd(*)  
    //         004e5d98     addr       switchD_004e59bd::caseD_0
    //         004e5d9c     addr       switchD_004e59bd::caseD_1
    //         004e5da0     addr       switchD_004e59bd::caseD_2
    //         004e5da4     addr       switchD_004e59bd::caseD_3
    //         004e5da8     addr       switchD_004e59bd::caseD_4
    //         004e5dac     ??         90h
    //         004e5dad     ??         90h
    //         004e5dae     ??         90h
    //         004e5daf     ??         90h
    return 0;
}

int TribeMainDecisionAIModule::save(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall save(TribeMainDecisionAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e5db2(R)  
    //                               ?save@TribeMainDecisionAIModule@@UAEHH@Z                     XREF[1]:     00575604(*)  
    //                               TribeMainDecisionAIModule::save
    //                              taimdmd.cpp:789 (2)
    //         004e5db0     PUSH       ESI
    //         004e5db1     PUSH       EDI
    //                              taimdmd.cpp:791 (12)
    //         004e5db2     MOV        EDI,dword ptr [ESP + param_1]
    //         004e5db6     MOV        ESI,this
    //         004e5db8     PUSH       EDI
    //         004e5db9     CALL       MainDecisionAIModule::save                       int save(MainDecisionAIModule * this, int par
    //                              taimdmd.cpp:793 (16)
    //         004e5dbe     MOV        EAX,dword ptr [ESI + 0x104]
    //         004e5dc4     LEA        this,[ESI + 0x104]
    //         004e5dca     PUSH       EDI
    //         004e5dcb     CALL       dword ptr [EAX + 0x3c]
    //                              taimdmd.cpp:794 (16)
    //         004e5dce     MOV        EDX,dword ptr [ESI + 0x6c4]
    //         004e5dd4     LEA        this,[ESI + 0x6c4]
    //         004e5dda     PUSH       EDI
    //         004e5ddb     CALL       dword ptr [EDX + 0x3c]
    //                              taimdmd.cpp:795 (16)
    //         004e5dde     MOV        EAX,dword ptr [ESI + 0x9dc]
    //         004e5de4     LEA        this,[ESI + 0x9dc]
    //         004e5dea     PUSH       EDI
    //         004e5deb     CALL       dword ptr [EAX + 0x3c]
    //                              taimdmd.cpp:796 (16)
    //         004e5dee     MOV        EDX,dword ptr [ESI + 0xb2c]
    //         004e5df4     LEA        this,[ESI + 0xb2c]
    //         004e5dfa     PUSH       EDI
    //         004e5dfb     CALL       dword ptr [EDX + 0x3c]
    //                              taimdmd.cpp:797 (12)
    //         004e5dfe     PUSH       EDI
    //         004e5dff     LEA        this,[ESI + 0xcec]
    //         004e5e05     CALL       TribeInformationAIModule::save                   int save(TribeInformationAIModule * this, int
    //                              taimdmd.cpp:798 (16)
    //         004e5e0a     MOV        EAX,dword ptr [ESI + 0x10d7c]
    //         004e5e10     LEA        this,[ESI + 0x10d7c]
    //         004e5e16     PUSH       EDI
    //         004e5e17     CALL       dword ptr [EAX + 0x3c]
    //                              taimdmd.cpp:799 (16)
    //         004e5e1a     MOV        EDX,dword ptr [ESI + 0x10e74]
    //         004e5e20     LEA        this,[ESI + 0x10e74]
    //         004e5e26     PUSH       EDI
    //         004e5e27     CALL       dword ptr [EDX + 0x3c]
    //                              taimdmd.cpp:800 (16)
    //         004e5e2a     MOV        EAX,dword ptr [ESI + 0x1146c]
    //         004e5e30     LEA        this,[ESI + 0x1146c]
    //         004e5e36     PUSH       EDI
    //         004e5e37     CALL       dword ptr [EAX + 0x3c]
    //                              taimdmd.cpp:801 (16)
    //         004e5e3a     MOV        EDX,dword ptr [ESI + 0x12478]
    //         004e5e40     LEA        this,[ESI + 0x12478]
    //         004e5e46     PUSH       EDI
    //         004e5e47     CALL       dword ptr [EDX + 0x3c]
    //                              taimdmd.cpp:803 (18)
    //         004e5e4a     LEA        EAX,[ESI + 0x12578]
    //         004e5e50     PUSH       0x4
    //         004e5e52     PUSH       EAX
    //         004e5e53     PUSH       EDI
    //         004e5e54     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5e59     ADD        ESP,0xc
    //                              taimdmd.cpp:804 (18)
    //         004e5e5c     LEA        this,[ESI + 0x1257c]
    //         004e5e62     PUSH       0x4
    //         004e5e64     PUSH       this
    //         004e5e65     PUSH       EDI
    //         004e5e66     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5e6b     ADD        ESP,0xc
    //                              taimdmd.cpp:805 (18)
    //         004e5e6e     LEA        EDX,[ESI + 0x12580]
    //         004e5e74     PUSH       0x4
    //         004e5e76     PUSH       EDX
    //         004e5e77     PUSH       EDI
    //         004e5e78     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5e7d     ADD        ESP,0xc
    //                              taimdmd.cpp:806 (18)
    //         004e5e80     LEA        EAX,[ESI + 0x12584]
    //         004e5e86     PUSH       0x4
    //         004e5e88     PUSH       EAX
    //         004e5e89     PUSH       EDI
    //         004e5e8a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5e8f     ADD        ESP,0xc
    //                              taimdmd.cpp:807 (18)
    //         004e5e92     LEA        this,[ESI + 0x12588]
    //         004e5e98     PUSH       0x4
    //         004e5e9a     PUSH       this
    //         004e5e9b     PUSH       EDI
    //         004e5e9c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5ea1     ADD        ESP,0xc
    //                              taimdmd.cpp:808 (18)
    //         004e5ea4     LEA        EDX,[ESI + 0x1258c]
    //         004e5eaa     PUSH       0x4
    //         004e5eac     PUSH       EDX
    //         004e5ead     PUSH       EDI
    //         004e5eae     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5eb3     ADD        ESP,0xc
    //                              taimdmd.cpp:809 (18)
    //         004e5eb6     LEA        EAX,[ESI + 0x12590]
    //         004e5ebc     PUSH       0x4
    //         004e5ebe     PUSH       EAX
    //         004e5ebf     PUSH       EDI
    //         004e5ec0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5ec5     ADD        ESP,0xc
    //                              taimdmd.cpp:810 (18)
    //         004e5ec8     LEA        this,[ESI + 0x12594]
    //         004e5ece     PUSH       0x4
    //         004e5ed0     PUSH       this
    //         004e5ed1     PUSH       EDI
    //         004e5ed2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5ed7     ADD        ESP,0xc
    //                              taimdmd.cpp:811 (18)
    //         004e5eda     LEA        EDX,[ESI + 0x12598]
    //         004e5ee0     PUSH       0x4
    //         004e5ee2     PUSH       EDX
    //         004e5ee3     PUSH       EDI
    //         004e5ee4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5ee9     ADD        ESP,0xc
    //                              taimdmd.cpp:812 (18)
    //         004e5eec     LEA        EAX,[ESI + 0x1259c]
    //         004e5ef2     PUSH       0x4
    //         004e5ef4     PUSH       EAX
    //         004e5ef5     PUSH       EDI
    //         004e5ef6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5efb     ADD        ESP,0xc
    //                              taimdmd.cpp:813 (18)
    //         004e5efe     LEA        this,[ESI + 0x125a0]
    //         004e5f04     PUSH       0x4
    //         004e5f06     PUSH       this
    //         004e5f07     PUSH       EDI
    //         004e5f08     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5f0d     ADD        ESP,0xc
    //                              taimdmd.cpp:814 (18)
    //         004e5f10     ADD        ESI,0x125a4
    //         004e5f16     PUSH       0x24
    //         004e5f18     PUSH       ESI
    //         004e5f19     PUSH       EDI
    //         004e5f1a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e5f1f     ADD        ESP,0xc
    //                              taimdmd.cpp:815 (5)
    //         004e5f22     MOV        EAX,0x1
    //                              taimdmd.cpp:816 (5)
    //         004e5f27     POP        EDI
    //         004e5f28     POP        ESI
    //         004e5f29     RET        0x4
    //         004e5f2c     ??         90h
    //         004e5f2d     NOP
    //         004e5f2e     NOP
    //         004e5f2f     NOP
    return 0;
}

void TribeMainDecisionAIModule::kick(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall kick(TribeMainDecisionAIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e5f32(R)  
    //                               ?kick@TribeMainDecisionAIModule@@QAEXH@Z                     XREF[1]:     kickAI:00514f9f(c)  
    //                               TribeMainDecisionAIModule::kick
    //                              taimdmd.cpp:821 (2)
    //         004e5f30     PUSH       ESI
    //         004e5f31     PUSH       EDI
    //                              taimdmd.cpp:822 (21)
    //         004e5f32     MOV        EDI,dword ptr [ESP + param_1]
    //         004e5f36     MOV        ESI,this
    //         004e5f38     PUSH       EDI
    //         004e5f39     PUSH       s_Got_a_kick=%d.                                 = "Got a kick=%d."
    //         004e5f3e     PUSH       ESI
    //         004e5f3f     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004e5f44     ADD        ESP,0xc
    //                              taimdmd.cpp:823 (5)
    //         004e5f47     CMP        EDI,0x1
    //         004e5f4a     JNZ        LAB_004e5f57
    //                              taimdmd.cpp:824 (11)
    //         004e5f4c     LEA        this,[ESI + 0x104]
    //         004e5f52     CALL       TribeBuildAIModule::skipNextBuildListItem        void skipNextBuildListItem(TribeBuildAIModule
    //                               LAB_004e5f57                                                 XREF[1]:     004e5f4a(j)  
    //                              taimdmd.cpp:825 (5)
    //         004e5f57     CMP        EDI,0x2
    //         004e5f5a     JNZ        LAB_004e5f6d
    //                              taimdmd.cpp:826 (17)
    //         004e5f5c     PUSH       -0x1
    //         004e5f5e     PUSH       0x1
    //         004e5f60     PUSH       0x53
    //         004e5f62     LEA        this,[ESI + 0x104]
    //         004e5f68     CALL       TribeBuildAIModule::insert                       int insert(TribeBuildAIModule * this, int par
    //                               LAB_004e5f6d                                                 XREF[1]:     004e5f5a(j)  
    //                              taimdmd.cpp:827 (5)
    //         004e5f6d     CMP        EDI,0x3
    //         004e5f70     JNZ        LAB_004e5f8f
    //                              taimdmd.cpp:828 (11)
    //         004e5f72     PUSH       s_Current_Build_list_is:                         = "Current Build list is:"
    //         004e5f77     PUSH       ESI
    //         004e5f78     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              taimdmd.cpp:830 (18)
    //         004e5f7d     MOV        EAX,dword ptr [ESI + 0x104]
    //         004e5f83     LEA        this,[ESI + 0x104]
    //         004e5f89     ADD        ESP,0x8
    //         004e5f8c     CALL       dword ptr [EAX + 0x40]
    //                               LAB_004e5f8f                                                 XREF[1]:     004e5f70(j)  
    //                              taimdmd.cpp:832 (5)
    //         004e5f8f     POP        EDI
    //         004e5f90     POP        ESI
    //         004e5f91     RET        0x4
    //         004e5f94     ??         90h
    //         004e5f95     NOP
    //         004e5f96     NOP
    //         004e5f97     NOP
    //         004e5f98     NOP
    //         004e5f99     NOP
    //         004e5f9a     NOP
    //         004e5f9b     NOP
    //         004e5f9c     NOP
    //         004e5f9d     NOP
    //         004e5f9e     NOP
    //         004e5f9f     NOP
    return;
}

int TribeMainDecisionAIModule::addObject(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall addObject(TribeMainDecisionAIModule * this, RGE_Stati
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004e5fa2(R)  
    //                               ?addObject@TribeMainDecisionAIModule@@UAEHPAVRGE_Static_Obj  XREF[1]:     00575608(*)  
    //                               TribeMainDecisionAIModule::addObject
    //                              taimdmd.cpp:837 (2)
    //         004e5fa0     PUSH       ESI
    //         004e5fa1     PUSH       EDI
    //                              taimdmd.cpp:838 (10)
    //         004e5fa2     MOV        EDI,dword ptr [ESP + param_1]
    //         004e5fa6     MOV        ESI,this
    //         004e5fa8     TEST       EDI,EDI
    //         004e5faa     JNZ        LAB_004e5fb3
    //                              taimdmd.cpp:839 (2)
    //         004e5fac     XOR        EAX,EAX
    //                              taimdmd.cpp:846 (5)
    //         004e5fae     POP        EDI
    //         004e5faf     POP        ESI
    //         004e5fb0     RET        0x4
    //                               LAB_004e5fb3                                                 XREF[1]:     004e5faa(j)  
    //                              taimdmd.cpp:842 (12)
    //         004e5fb3     PUSH       EDI
    //         004e5fb4     LEA        this,[ESI + 0x1146c]
    //         004e5fba     CALL       TribeTacticalAIModule::addObject                 void addObject(TribeTacticalAIModule * this, 
    //                              taimdmd.cpp:843 (12)
    //         004e5fbf     PUSH       EDI
    //         004e5fc0     LEA        this,[ESI + 0xcec]
    //         004e5fc6     CALL       TribeInformationAIModule::addObject              void addObject(TribeInformationAIModule * thi
    //                              taimdmd.cpp:845 (8)
    //         004e5fcb     PUSH       EDI
    //         004e5fcc     MOV        this,ESI
    //         004e5fce     CALL       MainDecisionAIModule::addObject                  int addObject(MainDecisionAIModule * this, RG
    //                              taimdmd.cpp:846 (5)
    //         004e5fd3     POP        EDI
    //         004e5fd4     POP        ESI
    //         004e5fd5     RET        0x4
    //         004e5fd8     ??         90h
    //         004e5fd9     NOP
    //         004e5fda     NOP
    //         004e5fdb     NOP
    //         004e5fdc     NOP
    //         004e5fdd     NOP
    //         004e5fde     NOP
    //         004e5fdf     NOP
    return 0;
}

int TribeMainDecisionAIModule::removeObject(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall removeObject(TribeMainDecisionAIModule * this, int pa
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e5fe2(R)  
    //                               ?removeObject@TribeMainDecisionAIModule@@UAEHH@Z             XREF[1]:     0057560c(*)  
    //                               TribeMainDecisionAIModule::removeObject
    //                              taimdmd.cpp:851 (2)
    //         004e5fe0     PUSH       ESI
    //         004e5fe1     PUSH       EDI
    //                              taimdmd.cpp:853 (18)
    //         004e5fe2     MOV        EDI,dword ptr [ESP + param_1]
    //         004e5fe6     MOV        ESI,this
    //         004e5fe8     PUSH       EDI
    //         004e5fe9     LEA        this,[ESI + 0x1146c]
    //         004e5fef     CALL       TribeTacticalAIModule::removeObject              void removeObject(TribeTacticalAIModule * thi
    //                              taimdmd.cpp:855 (12)
    //         004e5ff4     PUSH       EDI
    //         004e5ff5     LEA        this,[ESI + 0x104]
    //         004e5ffb     CALL       TribeBuildAIModule::removeBuiltItem              int removeBuiltItem(TribeBuildAIModule * this
    //                              taimdmd.cpp:857 (12)
    //         004e6000     PUSH       EDI
    //         004e6001     LEA        this,[ESI + 0xcec]
    //         004e6007     CALL       TribeInformationAIModule::removeObject           void removeObject(TribeInformationAIModule * 
    //                              taimdmd.cpp:858 (8)
    //         004e600c     PUSH       EDI
    //         004e600d     MOV        this,ESI
    //         004e600f     CALL       MainDecisionAIModule::removeObject               int removeObject(MainDecisionAIModule * this,
    //                              taimdmd.cpp:859 (5)
    //         004e6014     POP        EDI
    //         004e6015     POP        ESI
    //         004e6016     RET        0x4
    //         004e6019     ??         90h
    //         004e601a     NOP
    //         004e601b     NOP
    //         004e601c     NOP
    //         004e601d     NOP
    //         004e601e     NOP
    //         004e601f     NOP
    return 0;
}

int TribeMainDecisionAIModule::objectGroupThatCanPerformAction(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall objectGroupThatCanPerformAction(TribeMainDecisionAIMo
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6021(R)  
    //                               ?objectGroupThatCanPerformAction@TribeMainDecisionAIModule@  XREF[1]:     00575610(*)  
    //                               TribeMainDecisionAIModule::objectGroupThatCanPerformAction
    //                              taimdmd.cpp:864 (1)
    //         004e6020     PUSH       ESI
    //                              taimdmd.cpp:867 (30)
    //         004e6021     MOV        ESI,dword ptr [ESP + param_1]
    //         004e6025     LEA        EAX,[ESI + 0xfffffda6]
    //         004e602b     CMP        EAX,0x12
    //         004e602e     JA         switchD_004e6038::caseD_25b
    //         004e6030     XOR        EDX,EDX
    //         004e6032     MOV        DL,byte ptr [EAX + switchD_004e6038::switchdat
    //                               switchD_004e6038::switchD
    //         004e6038     JMP        dword ptr [EDX*0x4 + switchD_004e6038::switchd   = 004e603f
    //                               switchD_004e6038::caseD_25d                                  XREF[5]:     004e6038(j), 004e605c(*), 
    //                               switchD_004e6038::caseD_261                                               004e6060(*), 004e6064(*), 
    //                               switchD_004e6038::caseD_265                                               004e6068(*)  
    //                               switchD_004e6038::caseD_25a
    //                              taimdmd.cpp:872 (5)
    //         004e603f     MOV        EAX,0x4
    //                              taimdmd.cpp:880 (4)
    //         004e6044     POP        ESI
    //         004e6045     RET        0x4
    //                               switchD_004e6038::caseD_26c                                  XREF[2]:     004e6038(j), 004e606c(*)  
    //                               switchD_004e6038::caseD_26b
    //                              taimdmd.cpp:876 (5)
    //         004e6048     MOV        EAX,0x3
    //                              taimdmd.cpp:880 (4)
    //         004e604d     POP        ESI
    //         004e604e     RET        0x4
    //                               switchD_004e6038::caseD_25c                                  XREF[3]:     004e602e(j), 004e6038(j), 
    //                               switchD_004e6038::caseD_25e                                               004e6070(*)  
    //                               switchD_004e6038::caseD_25f
    //                               switchD_004e6038::caseD_260
    //                               switchD_004e6038::caseD_262
    //                               switchD_004e6038::caseD_263
    //                               switchD_004e6038::caseD_264
    //                               switchD_004e6038::caseD_266
    //                               switchD_004e6038::caseD_267
    //                               switchD_004e6038::caseD_268
    //                               switchD_004e6038::caseD_269
    //                               switchD_004e6038::caseD_26a
    //                               switchD_004e6038::caseD_25b
    //                              taimdmd.cpp:879 (6)
    //         004e6051     PUSH       ESI
    //         004e6052     CALL       MainDecisionAIModule::objectGroupThatCanPerfor   int objectGroupThatCanPerformAction(MainDecis
    //                              taimdmd.cpp:880 (48)
    //         004e6057     POP        ESI
    //         004e6058     RET        0x4
    //         004e605b     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e6038::switchdataD_004e605c                       XREF[1]:     objectGroupThatCanPerformAction:00
    //         004e605c     addr       switchD_004e6038::caseD_25a
    //         004e6060     addr       switchD_004e6038::caseD_25a
    //         004e6064     addr       switchD_004e6038::caseD_25a
    //         004e6068     addr       switchD_004e6038::caseD_25a
    //         004e606c     addr       switchD_004e6038::caseD_26b
    //         004e6070     addr       switchD_004e6038::caseD_25b
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e6038::switchdataD_004e6074                       XREF[1]:     objectGroupThatCanPerformAction:00
    //         004e6074     db         0h
    //         004e6075     db         5h
    //         004e6076     db         5h
    //         004e6077     db         1h
    //         004e6078     db         5h
    //         004e6079     db         5h
    //         004e607a     db         5h
    //         004e607b     db         2h
    //         004e607c     db         5h
    //         004e607d     db         5h
    //         004e607e     db         5h
    //         004e607f     db         3h
    //         004e6080     db         5h
    //         004e6081     db         5h
    //         004e6082     db         5h
    //         004e6083     db         5h
    //         004e6084     db         5h
    //         004e6085     db         4h
    //         004e6086     db         4h
    //         004e6087     ??         90h
    //         004e6088     ??         90h
    //         004e6089     ??         90h
    //         004e608a     ??         90h
    //         004e608b     ??         90h
    //         004e608c     ??         90h
    //         004e608d     ??         90h
    //         004e608e     ??         90h
    //         004e608f     ??         90h
    return 0;
}

int TribeMainDecisionAIModule::canPerformAction(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall canPerformAction(TribeMainDecisionAIModule * this, in
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6090(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e60a4(R)  
    //                               ?canPerformAction@TribeMainDecisionAIModule@@UAEHHH@Z        XREF[1]:     00575614(*)  
    //                               TribeMainDecisionAIModule::canPerformAction
    //                              taimdmd.cpp:885 (16)
    //         004e6090     MOV        EAX,dword ptr [ESP + param_1]
    //         004e6094     PUSH       ESI
    //         004e6095     PUSH       EDI
    //         004e6096     MOV        ESI,this
    //         004e6098     PUSH       EAX
    //         004e6099     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
    //         004e609e     MOV        EDI,EAX
    //                              taimdmd.cpp:888 (27)
    //         004e60a0     TEST       EDI,EDI
    //         004e60a2     JZ         LAB_004e60c5
    //         004e60a4     MOV        EAX,dword ptr [ESP + param_2]
    //         004e60a8     MOV        EDX,dword ptr [ESI]
    //         004e60aa     PUSH       EAX
    //         004e60ab     MOV        this,ESI
    //         004e60ad     CALL       dword ptr [EDX + 0x48]
    //         004e60b0     MOV        this,dword ptr [EDI + 0x8]
    //         004e60b3     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004e60b7     CMP        EDX,EAX
    //         004e60b9     JNZ        LAB_004e60c5
    //                              taimdmd.cpp:889 (5)
    //         004e60bb     MOV        EAX,0x1
    //                              taimdmd.cpp:891 (12)
    //         004e60c0     POP        EDI
    //         004e60c1     POP        ESI
    //         004e60c2     RET        0x8
    //                               LAB_004e60c5                                                 XREF[2]:     004e60a2(j), 004e60b9(j)  
    //         004e60c5     POP        EDI
    //         004e60c6     XOR        EAX,EAX
    //         004e60c8     POP        ESI
    //         004e60c9     RET        0x8
    //         004e60cc     ??         90h
    //         004e60cd     NOP
    //         004e60ce     NOP
    //         004e60cf     NOP
    return 0;
}

void TribeMainDecisionAIModule::detask(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall detask(TribeMainDecisionAIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e60d0(R)  
    //                               ?detask@TribeMainDecisionAIModule@@QAEXH@Z                   XREF[3]:     cancelBuildItem:004d5327(c), 
    //                               TribeMainDecisionAIModule::detask                                         addTrainedUnit:004d55d4(c), 
    //                                                                                                         addResearch:004d56c8(c)  
    //                              taimdmd.cpp:896 (16)
    //         004e60d0     MOV        EAX,dword ptr [ESP + param_1]
    //         004e60d4     ADD        this,0x1146c
    //         004e60da     PUSH       EAX
    //         004e60db     CALL       TribeTacticalAIModule::detask                    void detask(TribeTacticalAIModule * this, int
    //                              taimdmd.cpp:899 (3)
    //         004e60e0     RET        0x4
    //         004e60e3     ??         90h
    //         004e60e4     NOP
    //         004e60e5     NOP
    //         004e60e6     NOP
    //         004e60e7     NOP
    //         004e60e8     NOP
    //         004e60e9     NOP
    //         004e60ea     NOP
    //         004e60eb     NOP
    //         004e60ec     NOP
    //         004e60ed     NOP
    //         004e60ee     NOP
    //         004e60ef     NOP
    return;
}

int TribeMainDecisionAIModule::isMoveable(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall isMoveable(TribeMainDecisionAIModule * this, int para
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e60f0(R)  
    //                               ?isMoveable@TribeMainDecisionAIModule@@QAEHH@Z               XREF[2]:     cancelBuildItem:004d53a2(c), 
    //                               TribeMainDecisionAIModule::isMoveable                                     taskActiveSoldiers:004f3edc(c)  
    //                              taimdmd.cpp:904 (10)
    //         004e60f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004e60f4     PUSH       EAX
    //         004e60f5     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
    //                              taimdmd.cpp:907 (2)
    //         004e60fa     TEST       EAX,EAX
    //                              taimdmd.cpp:908 (2)
    //         004e60fc     JZ         LAB_004e6155
    //                              taimdmd.cpp:921 (79)
    //         004e60fe     MOV        this,dword ptr [EAX + 0x8]
    //         004e6101     MOV        AX,word ptr [ECX + this->_padding_]
    //         004e6105     CMP        AX,0x3
    //         004e6109     JZ         LAB_004e6155
    //         004e610b     CMP        AX,0x1b
    //         004e610f     JZ         LAB_004e6155
    //         004e6111     CMP        AX,0x1e
    //         004e6115     JZ         LAB_004e6155
    //         004e6117     CMP        AX,0x1f
    //         004e611b     JZ         LAB_004e6155
    //         004e611d     CMP        AX,0x5
    //         004e6121     JZ         LAB_004e6155
    //         004e6123     CMP        AX,0x21
    //         004e6127     JZ         LAB_004e6155
    //         004e6129     CMP        AX,0x7
    //         004e612d     JZ         LAB_004e6155
    //         004e612f     CMP        AX,0x8
    //         004e6133     JZ         LAB_004e6155
    //         004e6135     CMP        AX,0x20
    //         004e6139     JZ         LAB_004e6155
    //         004e613b     CMP        AX,0x10
    //         004e613f     JZ         LAB_004e6155
    //         004e6141     CMP        AX,0xe
    //         004e6145     JZ         LAB_004e6155
    //         004e6147     CMP        AX,0xf
    //         004e614b     JZ         LAB_004e6155
    //                              taimdmd.cpp:923 (5)
    //         004e614d     MOV        EAX,0x1
    //                              taimdmd.cpp:924 (3)
    //         004e6152     RET        0x4
    //                               LAB_004e6155                                                 XREF[13]:    004e60fc(j), 004e6109(j), 
    //                                                                                                         004e610f(j), 004e6115(j), 
    //                                                                                                         004e611b(j), 004e6121(j), 
    //                                                                                                         004e6127(j), 004e612d(j), 
    //                                                                                                         004e6133(j), 004e6139(j), 
    //                                                                                                         004e613f(j), 004e6145(j), 
    //                                                                                                         004e614b(j)  
    //                              taimdmd.cpp:922 (2)
    //         004e6155     XOR        EAX,EAX
    //                              taimdmd.cpp:924 (3)
    //         004e6157     RET        0x4
    //         004e615a     ??         90h
    //         004e615b     NOP
    //         004e615c     NOP
    //         004e615d     NOP
    //         004e615e     NOP
    //         004e615f     NOP
    return 0;
}

void TribeMainDecisionAIModule::updateBuildAIWithObjects() {
    /* TODO: Stub */
    //                              void __thiscall updateBuildAIWithObjects(TribeMainDecisionAIModule *
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //                               ?updateBuildAIWithObjects@TribeMainDecisionAIModule@@QAEXXZ  XREF[2]:     doSomething:004f0517(c), 
    //                               TribeMainDecisionAIModule::updateBuildAIWithObjects                       loadAIInformation:00515855(c)  
    //                              taimdmd.cpp:929 (4)
    //         004e6160     PUSH       EBX
    //         004e6161     PUSH       ESI
    //         004e6162     MOV        ESI,this
    //                              taimdmd.cpp:931 (18)
    //         004e6164     XOR        EBX,EBX
    //         004e6166     MOV        EAX,dword ptr [ESI + 0xf8]
    //         004e616c     TEST       EAX,EAX
    //         004e616e     JLE        LAB_004e6249
    //         004e6174     PUSH       EDI
    //         004e6175     PUSH       EBP
    //                               LAB_004e6176                                                 XREF[1]:     004e6241(j)  
    //                              taimdmd.cpp:932 (123)
    //         004e6176     MOV        EAX,dword ptr [ESI + 0x100]
    //         004e617c     DEC        EAX
    //         004e617d     CMP        EBX,EAX
    //         004e617f     JLE        LAB_004e61de
    //         004e6181     LEA        this,[EBX*0x4 + 0x4]
    //         004e6188     LEA        EBP,[EBX + 0x1]
    //         004e618b     PUSH       this
    //         004e618c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e6191     MOV        EDI,EAX
    //         004e6193     ADD        ESP,0x4
    //         004e6196     TEST       EDI,EDI
    //         004e6198     JZ         LAB_004e61de
    //         004e619a     MOV        this,dword ptr [ESI + 0x100]
    //         004e61a0     XOR        EAX,EAX
    //         004e61a2     TEST       this,this
    //         004e61a4     JLE        LAB_004e61c3
    //                               LAB_004e61a6                                                 XREF[1]:     004e61c1(j)  
    //         004e61a6     CMP        EAX,EBP
    //         004e61a8     JGE        LAB_004e61c3
    //         004e61aa     MOV        EDX,dword ptr [ESI + 0xf4]
    //         004e61b0     INC        EAX
    //         004e61b1     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004e61b5     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         004e61b9     MOV        this,dword ptr [ESI + 0x100]
    //         004e61bf     CMP        EAX,this
    //         004e61c1     JL         LAB_004e61a6
    //                               LAB_004e61c3                                                 XREF[2]:     004e61a4(j), 004e61a8(j)  
    //         004e61c3     MOV        EDX,dword ptr [ESI + 0xf4]
    //         004e61c9     PUSH       EDX
    //         004e61ca     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e61cf     ADD        ESP,0x4
    //         004e61d2     MOV        dword ptr [ESI + 0xf4],EDI
    //         004e61d8     MOV        dword ptr [ESI + 0x100],EBP
    //                               LAB_004e61de                                                 XREF[2]:     004e617f(j), 004e6198(j)  
    //         004e61de     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004e61e4     MOV        this,dword ptr [EAX + EBX*0x4]
    //         004e61e7     PUSH       this
    //         004e61e8     MOV        this,ESI
    //         004e61ea     CALL       MainDecisionAIModule::object                     RGE_Static_Object * object(MainDecisionAIModu
    //         004e61ef     MOV        EDI,EAX
    //                              taimdmd.cpp:933 (4)
    //         004e61f1     TEST       EDI,EDI
    //         004e61f3     JZ         LAB_004e6238
    //                              taimdmd.cpp:936 (14)
    //         004e61f5     PUSH       0x0
    //         004e61f7     PUSH       EDI
    //         004e61f8     LEA        this,[ESI + 0x104]
    //         004e61fe     CALL       TribeBuildAIModule::addItem                      int addItem(TribeBuildAIModule * this, RGE_St
    //                              taimdmd.cpp:938 (10)
    //         004e6203     MOV        EDX,dword ptr [EDI + 0x8]
    //         004e6206     CMP        word ptr [EDX + 0x10],0x6d
    //         004e620b     JNZ        LAB_004e6238
    //                              taimdmd.cpp:941 (60)
    //         004e620d     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e6213     MOV        EDX,dword ptr [EDI + 0x40]
    //         004e6216     PUSH       EDX
    //         004e6217     MOV        EDX,dword ptr [EDI + 0x38]
    //         004e621a     MOV        this,dword ptr [EAX + 0x3c]
    //         004e621d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004e6220     MOV        this,dword ptr [EDI + 0x3c]
    //         004e6223     PUSH       this
    //         004e6224     PUSH       EDX
    //         004e6225     MOV        this,dword ptr [EAX + 0xc]
    //         004e6228     MOV        EDX,dword ptr [EAX + 0x8]
    //         004e622b     PUSH       this
    //         004e622c     PUSH       EDX
    //         004e622d     LEA        this,[ESI + 0x6c4]
    //         004e6233     CALL       ConstructionAIModule::setReferencePoint          void setReferencePoint(ConstructionAIModule *
    //                               LAB_004e6238                                                 XREF[2]:     004e61f3(j), 004e620b(j)  
    //         004e6238     MOV        EAX,dword ptr [ESI + 0xf8]
    //         004e623e     INC        EBX
    //         004e623f     CMP        EBX,EAX
    //         004e6241     JL         LAB_004e6176
    //         004e6247     POP        EBP
    //         004e6248     POP        EDI
    //                               LAB_004e6249                                                 XREF[1]:     004e616e(j)  
    //                              taimdmd.cpp:943 (3)
    //         004e6249     POP        ESI
    //         004e624a     POP        EBX
    //         004e624b     RET
    //         004e624c     ??         90h
    //         004e624d     NOP
    //         004e624e     NOP
    //         004e624f     NOP
    return;
}

void TribeMainDecisionAIModule::tributeNotify(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall tributeNotify(TribeMainDecisionAIModule * this, int 
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6258(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e6280(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[3]:     004e628a(R), 004e62d3(R), 004e62fe(R)  
    //              char[256]         Stack[-0x104   tempString
    //              RGE_Player *      Stack[-0x108   newAlly                   XREF[1]:     004e62b7(W)  
    //                               ?tributeNotify@TribeMainDecisionAIModule@@QAEXHHH@Z          XREF[1]:     notifyAI:00515d68(c)  
    //                               TribeMainDecisionAIModule::tributeNotify
    //                              taimdmd.cpp:949 (8)
    //         004e6250     SUB        ESP,0x108
    //         004e6256     PUSH       EBX
    //         004e6257     PUSH       EBP
    //                              taimdmd.cpp:959 (50)
    //         004e6258     MOV        EBX,dword ptr [ESP + param_1]
    //         004e625f     PUSH       ESI
    //         004e6260     MOV        ESI,this
    //         004e6262     PUSH       EDI
    //         004e6263     CMP        dword ptr [ESI + 0x1258c],0x1
    //         004e626a     JNZ        LAB_004e62ac
    //                              language.dll match for 0x80: "Arial"
    //         004e626c     PUSH       0x80
    //         004e6271     LEA        this,[ESI + 0x1146c]
    //         004e6277     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e627c     CMP        EBX,EAX
    //         004e627e     JNZ        LAB_004e62ac
    //         004e6280     CMP        dword ptr [ESP + param_2],0x3
    //         004e6288     JNZ        LAB_004e62ac
    //                              taimdmd.cpp:960 (21)
    //         004e628a     MOV        EAX,dword ptr [ESP + param_3]
    //         004e6291     MOV        this,dword ptr [ESI + 0x12598]
    //         004e6297     ADD        this,EAX
    //         004e6299     MOV        dword ptr [ESI + 0x12598],this
    //                              taimdmd.cpp:1015 (13)
    //         004e629f     POP        EDI
    //         004e62a0     POP        ESI
    //         004e62a1     POP        EBP
    //         004e62a2     POP        EBX
    //         004e62a3     ADD        ESP,0x108
    //         004e62a9     RET        0xc
    //                               LAB_004e62ac                                                 XREF[3]:     004e626a(j), 004e627e(j), 
    //                                                                                                         004e6288(j)  
    //                              taimdmd.cpp:968 (28)
    //         004e62ac     LEA        this,[ESI + 0x1146c]
    //                              language.dll match for 0x80: "Arial"
    //         004e62b2     PUSH       0x80
    //         004e62b7     MOV        dword ptr [ESP + newAlly],this
    //         004e62bb     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e62c0     CMP        EBX,EAX
    //         004e62c2     JZ         LAB_004e647b
    //                              taimdmd.cpp:969 (5)
    //         004e62c8     MOV        EAX,0x51eb851f
    //                              taimdmd.cpp:970 (36)
    //         004e62cd     LEA        EBP,[ESI + 0x9dc]
    //         004e62d3     IMUL       dword ptr [ESP + param_3]
    //         004e62da     SAR        EDX,0x5
    //         004e62dd     MOV        this,EDX
    //         004e62df     SHR        this,0x1f
    //         004e62e2     ADD        EDX,this
    //         004e62e4     MOV        this,EBP
    //         004e62e6     MOV        EDI,EDX
    //         004e62e8     PUSH       EDI
    //         004e62e9     PUSH       0x2
    //         004e62eb     PUSH       EBX
    //         004e62ec     CALL       DiplomacyAIModule::changeStance                  void changeStance(DiplomacyAIModule * this, i
    //                              taimdmd.cpp:971 (13)
    //         004e62f1     NEG        EDI
    //         004e62f3     PUSH       EDI
    //         004e62f4     PUSH       0x0
    //         004e62f6     PUSH       EBX
    //         004e62f7     MOV        this,EBP
    //         004e62f9     CALL       DiplomacyAIModule::changeStance                  void changeStance(DiplomacyAIModule * this, i
    //                              taimdmd.cpp:974 (16)
    //         004e62fe     MOV        EDX,dword ptr [ESP + param_3]
    //         004e6305     MOV        EDI,dword ptr [ESI + EBX*0x4 + 0x125a4]
    //         004e630c     ADD        EDI,EDX
    //                              taimdmd.cpp:981 (75)
    //         004e630e     PUSH       EBX
    //         004e630f     MOV        dword ptr [ESI + EBX*0x4 + 0x125a4],EDI
    //         004e6316     MOV        this,dword ptr [ESI + 0xf0]
    //         004e631c     MOV        EAX,dword ptr [this->_padding_]
    //         004e631e     CALL       dword ptr [EAX + 0x20]
    //         004e6321     MOV        EDI,0x1
    //         004e6326     CMP        EAX,EDI
    //         004e6328     JNZ        LAB_004e643a
    //         004e632e     MOV        this,dword ptr [ESP + 0x10]
    //         004e6332     PUSH       0xd9
    //         004e6337     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e633c     CMP        EAX,EDI
    //         004e633e     JNZ        LAB_004e643a
    //         004e6344     MOV        this,dword ptr [ESI + EBX*0x4 + 0x125a4]
    //         004e634b     MOV        EAX,dword ptr [ESI + 0x125a0]
    //         004e6351     CMP        this,EAX
    //         004e6353     JL         LAB_004e643a
    //                              taimdmd.cpp:987 (23)
    //         004e6359     MOV        this,dword ptr [ESI + 0xf0]
    //         004e635f     PUSH       0x0
    //         004e6361     PUSH       offset DAT_fffffff8
    //         004e6363     PUSH       EBX=>DAT_fffffff4
    //         004e6364     MOVSX      EAX,word ptr [ECX + this+0x4a]
    //         004e6368     MOV        EDX,dword ptr [this->_padding_]
    //         004e636a     PUSH       offset DAT_fffffff0
    //         004e636c     PUSH       EAX
    //         004e636d     CALL       dword ptr [EDX + 0x54]
    //                              taimdmd.cpp:989 (26)
    //         004e6370     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e6376     LEA        EAX,[ESP + 0x18]
    //         004e637a     PUSH       0x100
    //         004e637f     PUSH       EAX=>DAT_fffffff8
    //         004e6380     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0x907: "Your empire is worthy of my al
    //         004e6382     PUSH       offset DAT_fffffff4
    //         004e6387     CALL       dword ptr [EDX + 0x20]
    //                              taimdmd.cpp:990 (20)
    //         004e638a     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e6390     LEA        this,[ESP + 0x18]
    //         004e6394     PUSH       this
    //         004e6395     PUSH       0x0=>DAT_fffffff8
    //         004e6397     PUSH       EBX=>DAT_fffffff4
    //         004e6398     PUSH       EDX=>DAT_fffffff0
    //         004e6399     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //                              taimdmd.cpp:992 (15)
    //         004e639e     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e63a4     ADD        ESP,0x10
    //         004e63a7     MOV        this,dword ptr [EAX + 0x3c]
    //         004e63aa     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              taimdmd.cpp:993 (19)
    //         004e63ad     CMP        word ptr [ECX + this->_padding_],DI
    //         004e63b1     MOV        EDX,dword ptr [EDX + EBX*0x4]
    //         004e63b4     MOV        dword ptr [ESP + 0x14],EDX
    //         004e63b8     JLE        LAB_004e641d
    //         004e63ba     JMP        LAB_004e63c0
    //                               LAB_004e63bc                                                 XREF[1]:     004e641b(j)  
    //         004e63bc     MOV        EDX,dword ptr [ESP + 0x14]
    //                               LAB_004e63c0                                                 XREF[1]:     004e63ba(j)  
    //                              taimdmd.cpp:994 (12)
    //         004e63c0     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004e63c4     CMP        EDI,EAX
    //         004e63c6     JZ         LAB_004e640b
    //         004e63c8     CMP        EDI,EBX
    //         004e63ca     JZ         LAB_004e640b
    //                              taimdmd.cpp:997 (13)
    //         004e63cc     MOV        EBP,dword ptr [EDX]
    //         004e63ce     PUSH       EDI
    //         004e63cf     MOV        this,EDX
    //         004e63d1     CALL       dword ptr [EBP + 0x1c]
    //         004e63d4     CMP        EAX,0x1
    //         004e63d7     JNZ        LAB_004e63e7
    //                              taimdmd.cpp:998 (12)
    //         004e63d9     MOV        this,dword ptr [ESI + 0xf0]
    //         004e63df     PUSH       0x0
    //         004e63e1     PUSH       offset DAT_fffffff8
    //         004e63e3     MOV        EDX,dword ptr [this->_padding_]
    //                              taimdmd.cpp:1000 (15)
    //         004e63e5     JMP        LAB_004e6400
    //                               LAB_004e63e7                                                 XREF[1]:     004e63d7(j)  
    //         004e63e7     MOV        this,dword ptr [ESP + 0x14]
    //         004e63eb     PUSH       EDI
    //         004e63ec     CALL       dword ptr [EBP + 0x18]
    //         004e63ef     CMP        EAX,0x1
    //         004e63f2     JNZ        LAB_004e640b
    //                              taimdmd.cpp:1001 (41)
    //         004e63f4     MOV        this,dword ptr [ESI + 0xf0]
    //         004e63fa     PUSH       0x0
    //         004e63fc     PUSH       0x0=>DAT_fffffff8
    //         004e63fe     MOV        EDX,dword ptr [this->_padding_]
    //                               LAB_004e6400                                                 XREF[1]:     004e63e5(j)  
    //         004e6400     MOVSX      EAX,word ptr [ECX + this+0x4a]
    //         004e6404     PUSH       EDI=>DAT_fffffff4
    //         004e6405     PUSH       offset DAT_fffffff0
    //         004e6407     PUSH       EAX
    //         004e6408     CALL       dword ptr [EDX + 0x54]
    //                               LAB_004e640b                                                 XREF[3]:     004e63c6(j), 004e63ca(j), 
    //                                                                                                         004e63f2(j)  
    //         004e640b     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e6411     INC        EDI
    //         004e6412     MOV        this,dword ptr [EAX + 0x3c]
    //         004e6415     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004e6419     CMP        EDI,EDX
    //         004e641b     JL         LAB_004e63bc
    //                               LAB_004e641d                                                 XREF[1]:     004e63b8(j)  
    //                              taimdmd.cpp:1005 (16)
    //         004e641d     MOV        this,dword ptr [ESP + 0x10]
    //         004e6421     PUSH       0x0
    //         004e6423     PUSH       offset DAT_fffffff8
    //         004e6428     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taimdmd.cpp:1015 (13)
    //         004e642d     POP        EDI
    //         004e642e     POP        ESI
    //         004e642f     POP        EBP
    //         004e6430     POP        EBX
    //         004e6431     ADD        ESP,0x108
    //         004e6437     RET        0xc
    //                               LAB_004e643a                                                 XREF[3]:     004e6328(j), 004e633e(j), 
    //                                                                                                         004e6353(j)  
    //                              taimdmd.cpp:1009 (16)
    //         004e643a     MOV        this,dword ptr [ESI + 0xf0]
    //         004e6440     PUSH       EBX
    //         004e6441     MOV        EAX,dword ptr [this->_padding_]
    //         004e6443     CALL       dword ptr [EAX + 0x18]
    //         004e6446     CMP        EAX,EDI
    //         004e6448     JNZ        LAB_004e647b
    //                              taimdmd.cpp:1011 (26)
    //         004e644a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e6450     LEA        EAX,[ESP + 0x18]
    //         004e6454     PUSH       0x100
    //         004e6459     PUSH       EAX=>DAT_fffffff8
    //         004e645a     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0x906: "Your petty offerings will not 
    //         004e645c     PUSH       offset DAT_fffffff4
    //         004e6461     CALL       dword ptr [EDX + 0x20]
    //                              taimdmd.cpp:1012 (23)
    //         004e6464     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e646a     LEA        this,[ESP + 0x18]
    //         004e646e     PUSH       this
    //         004e646f     PUSH       0x0=>DAT_fffffff8
    //         004e6471     PUSH       EBX=>DAT_fffffff4
    //         004e6472     PUSH       EDX=>DAT_fffffff0
    //         004e6473     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //         004e6478     ADD        ESP,0x10
    //                               LAB_004e647b                                                 XREF[2]:     004e62c2(j), 004e6448(j)  
    //                              taimdmd.cpp:1015 (13)
    //         004e647b     POP        EDI
    //         004e647c     POP        ESI
    //         004e647d     POP        EBP
    //         004e647e     POP        EBX
    //         004e647f     ADD        ESP,0x108
    //         004e6485     RET        0xc
    //         004e6488     ??         90h
    //         004e6489     NOP
    //         004e648a     NOP
    //         004e648b     NOP
    //         004e648c     NOP
    //         004e648d     NOP
    //         004e648e     NOP
    //         004e648f     NOP
    return;
}

void TribeMainDecisionAIModule::revokeTributeAlliance() {
    /* TODO: Stub */
    //                              void __thiscall revokeTributeAlliance(TribeMainDecisionAIModule * th
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              char[256]         Stack[-0x104   tempString
    //                               ?revokeTributeAlliance@TribeMainDecisionAIModule@@QAEXXZ     XREF[1]:     notify:004f6608(c)  
    //                               TribeMainDecisionAIModule::revokeTributeAlliance
    //                              taimdmd.cpp:1020 (11)
    //         004e6490     SUB        ESP,0x100
    //         004e6496     PUSH       EBX
    //         004e6497     PUSH       ESI
    //         004e6498     MOV        ESI,this
    //         004e649a     PUSH       EDI
    //                              language.dll match for 0x80: "Arial"
    //                              taimdmd.cpp:1025 (44)
    //         004e649b     PUSH       0x80
    //         004e64a0     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e64a6     LEA        EDI,[ESI + 0x1146c]
    //         004e64ac     MOV        this,EDI
    //         004e64ae     MOV        EBX,dword ptr [EAX]
    //         004e64b0     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e64b5     MOV        this,dword ptr [ESI + 0xf0]
    //         004e64bb     PUSH       EAX
    //         004e64bc     CALL       dword ptr [EBX + 0x18]
    //         004e64bf     TEST       EAX,EAX
    //         004e64c1     JNZ        LAB_004e656c
    //                              taimdmd.cpp:1028 (28)
    //         004e64c7     PUSH       EAX
    //         004e64c8     PUSH       EAX=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e64c9     PUSH       offset DAT_fffffff4
    //         004e64ce     MOV        this,EDI
    //         004e64d0     LEA        EBX,[ESI + 0x9dc]
    //         004e64d6     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e64db     PUSH       EAX=>DAT_fffffff4
    //         004e64dc     MOV        this,EBX
    //         004e64de     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:1031 (24)
    //         004e64e3     PUSH       0x64
    //         004e64e5     PUSH       offset DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e64e7     PUSH       offset DAT_fffffff4
    //         004e64ec     MOV        this,EDI
    //         004e64ee     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e64f3     PUSH       EAX=>DAT_fffffff4
    //         004e64f4     MOV        this,EBX
    //         004e64f6     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:1033 (32)
    //         004e64fb     MOV        this,dword ptr [ESI + 0x1256c]
    //         004e6501     PUSH       0x3
    //                              language.dll match for 0x80: "Arial"
    //         004e6503     PUSH       offset DAT_fffffff8
    //         004e6508     MOV        EBX,dword ptr [this->_padding_]
    //         004e650a     MOV        this,EDI
    //         004e650c     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e6511     MOV        this,dword ptr [ESI + 0x1256c]
    //         004e6517     PUSH       EAX=>DAT_fffffff8
    //         004e6518     CALL       dword ptr [EBX + 0x28]
    //                              taimdmd.cpp:1036 (26)
    //         004e651b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e6521     LEA        EAX,[ESP + 0xc]
    //         004e6525     PUSH       0x100
    //         004e652a     PUSH       EAX=>DAT_fffffff8
    //         004e652b     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0x8fd: "You traitorous wretch! Vengean
    //         004e652d     PUSH       offset DAT_fffffff4
    //         004e6532     CALL       dword ptr [EDX + 0x20]
    //                              taimdmd.cpp:1037 (35)
    //         004e6535     LEA        this,[ESP + 0xc]
    //         004e6539     PUSH       this
    //         004e653a     PUSH       0x0=>DAT_fffffff8
    //                              language.dll match for 0x80: "Arial"
    //         004e653c     PUSH       offset DAT_fffffff4
    //         004e6541     MOV        this,EDI
    //         004e6543     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e6548     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e654e     PUSH       EAX=>DAT_fffffff4
    //         004e654f     PUSH       EDX=>DAT_fffffff0
    //         004e6550     CALL       RGE_Player::sendChatMessage                      void sendChatMessage(RGE_Player * this, int p
    //         004e6555     ADD        ESP,0x10
    //                              taimdmd.cpp:1040 (10)
    //         004e6558     MOV        dword ptr [ESI + 0x1258c],0x0
    //                              taimdmd.cpp:1041 (10)
    //         004e6562     MOV        dword ptr [ESI + 0x12594],0x1
    //                               LAB_004e656c                                                 XREF[1]:     004e64c1(j)  
    //                              taimdmd.cpp:1043 (10)
    //         004e656c     POP        EDI
    //         004e656d     POP        ESI
    //         004e656e     POP        EBX
    //         004e656f     ADD        ESP,0x100
    //         004e6575     RET
    //         004e6576     ??         90h
    //         004e6577     NOP
    //         004e6578     NOP
    //         004e6579     NOP
    //         004e657a     NOP
    //         004e657b     NOP
    //         004e657c     NOP
    //         004e657d     NOP
    //         004e657e     NOP
    //         004e657f     NOP
    return;
}

void TribeMainDecisionAIModule::setTributeChat() {
    /* TODO: Stub */
    //                              void __thiscall setTributeChat(TribeMainDecisionAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //                               ?setTributeChat@TribeMainDecisionAIModule@@IAEXXZ            XREF[3]:     update:004e5131(c), 
    //                               TribeMainDecisionAIModule::setTributeChat                                 update:004e5411(c), 
    //                                                                                                         update:004e5463(c)  
    //                              taimdmd.cpp:1048 (4)
    //         004e6580     PUSH       ESI
    //         004e6581     PUSH       EDI
    //         004e6582     MOV        EDI,this
    //                              language.dll match for 0x7e: "10"
    //                              taimdmd.cpp:1049 (20)
    //         004e6584     PUSH       0x7e
    //         004e6586     LEA        ESI,[EDI + 0x1146c]
    //         004e658c     MOV        this,ESI
    //         004e658e     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e6593     TEST       EAX,EAX
    //         004e6595     JLE        LAB_004e65e3
    //         004e6597     PUSH       EBX
    //                              taimdmd.cpp:1053 (72)
    //         004e6598     PUSH       0x41d
    //         004e659d     PUSH       s_C:\msdev\work\age1_x1\taimdmd.cp               = "C:\\msdev\\work\\age1_x1\\taimdmd.cpp"
    //         004e65a2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004e65a7     ADD        ESP,0x8
    //         004e65aa     MOV        this,ESI
    //         004e65ac     MOV        EBX,EAX
    //                              language.dll match for 0x7e: "10"
    //         004e65ae     PUSH       0x7e
    //         004e65b0     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e65b5     MOV        this,EAX
    //         004e65b7     MOV        EAX,EBX
    //         004e65b9     CDQ
    //         004e65ba     IDIV       this
    //                              language.dll match for 0x7e: "10"
    //         004e65bc     PUSH       0x7e
    //         004e65be     MOV        this,ESI
    //         004e65c0     MOV        EBX,EDX
    //         004e65c2     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e65c7     CDQ
    //         004e65c8     SUB        EAX,EDX
    //                              language.dll match for 0x7d: "Arial"
    //         004e65ca     PUSH       0x7d
    //         004e65cc     SAR        EAX,0x1
    //         004e65ce     MOV        this,ESI
    //         004e65d0     SUB        EBX,EAX
    //         004e65d2     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e65d7     ADD        EBX,EAX
    //         004e65d9     MOV        dword ptr [EDI + 0x12588],EBX
    //         004e65df     POP        EBX
    //                              taimdmd.cpp:1059 (3)
    //         004e65e0     POP        EDI
    //         004e65e1     POP        ESI
    //         004e65e2     RET
    //                              language.dll match for 0x7d: "Arial"
    //                               LAB_004e65e3                                                 XREF[1]:     004e6595(j)  
    //                              taimdmd.cpp:1055 (15)
    //         004e65e3     PUSH       0x7d
    //         004e65e5     MOV        this,ESI
    //         004e65e7     CALL       TribeTacticalAIModule::strategicNumber           int strategicNumber(TribeTacticalAIModule * t
    //         004e65ec     MOV        dword ptr [EDI + 0x12588],EAX
    //                              taimdmd.cpp:1059 (3)
    //         004e65f2     POP        EDI
    //         004e65f3     POP        ESI
    //         004e65f4     RET
    //         004e65f5     ??         90h
    //         004e65f6     NOP
    //         004e65f7     NOP
    //         004e65f8     NOP
    //         004e65f9     NOP
    //         004e65fa     NOP
    //         004e65fb     NOP
    //         004e65fc     NOP
    //         004e65fd     NOP
    //         004e65fe     NOP
    //         004e65ff     NOP
    return;
}

int TribeMainDecisionAIModule::processAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
    //                              int __thiscall processAICommand(TribeMainDecisionAIModule * this, in
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     004e6635(R), 004e66ab(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e6600(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[4]:     004e667f(R), 004e66c0(R), 004e66dd(R), 004e6704(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     004e6686(R), 004e66bb(R), 004e6718(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004e66b7(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004e6683(*)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     004e668b(*)  
    //                               ?processAICommand@TribeMainDecisionAIModule@@QAEHHHHHH@Z     XREF[1]:     sendAICommand:00515068(c)  
    //                               TribeMainDecisionAIModule::processAICommand
    //                              taimdmd.cpp:1065 (25)
    //         004e6600     MOV        EAX,dword ptr [ESP + param_2]
    //         004e6604     PUSH       EBX
    //         004e6605     PUSH       ESI
    //         004e6606     CMP        EAX,0x7
    //         004e6609     PUSH       EDI
    //         004e660a     MOV        EBX,this
    //         004e660c     JA         switchD_004e6612::caseD_4
    //                               switchD_004e6612::switchD
    //         004e6612     JMP        dword ptr [EAX*0x4 + switchD_004e6612::switchd   = 004e6619
    //                               switchD_004e6612::caseD_0                                    XREF[2]:     004e6612(j), 004e6844(*)  
    //                              taimdmd.cpp:1072 (11)
    //         004e6619     LEA        this,[EBX + 0xcec]
    //         004e661f     CALL       TribeInformationAIModule::lookAtMap              void lookAtMap(TribeInformationAIModule * this)
    //                              taimdmd.cpp:1073 (5)
    //         004e6624     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e6629     POP        EDI
    //         004e662a     POP        ESI
    //         004e662b     POP        EBX
    //         004e662c     RET        0x14
    //                               switchD_004e6612::caseD_1                                    XREF[2]:     004e6612(j), 004e6848(*)  
    //                              taimdmd.cpp:1079 (22)
    //         004e662f     MOV        EAX,dword ptr [EBX + 0xf0]
    //         004e6635     MOV        ESI,dword ptr [ESP + param_1]
    //         004e6639     MOVSX      this,word ptr [EAX + 0x4a]
    //         004e663d     CMP        ESI,this
    //         004e663f     JZ         LAB_004e682e
    //                              taimdmd.cpp:1085 (40)
    //         004e6645     MOV        EDX,dword ptr [EBX + 0x1256c]
    //         004e664b     PUSH       0x0
    //         004e664d     PUSH       0x2
    //         004e664f     PUSH       0x0
    //         004e6651     MOV        this,dword ptr [EDX + 0x28]
    //         004e6654     PUSH       0xbf800000
    //         004e6659     PUSH       0xbf800000
    //         004e665e     PUSH       0x54
    //         004e6660     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //         004e6665     TEST       EAX,EAX
    //         004e6667     JZ         LAB_004e682e
    //                              taimdmd.cpp:1086 (41)
    //         004e666d     MOV        this,dword ptr [EBX + 0x1256c]
    //         004e6673     PUSH       this
    //         004e6674     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e6677     MOV        EAX,dword ptr [this->_padding_]
    //         004e6679     FLD        float ptr [EDX + 0xb8]
    //         004e667f     MOV        EDX,dword ptr [ESP + param_3]
    //         004e6683     FSTP       float ptr [ESP]=>local_10
    //         004e6686     FILD       dword ptr [ESP + param_4]
    //         004e668a     PUSH       this
    //         004e668b     FSTP       float ptr [ESP]=>local_14
    //         004e668e     PUSH       EDX
    //         004e668f     PUSH       ESI
    //         004e6690     CALL       dword ptr [EAX + 0xf8]
    //                              taimdmd.cpp:1088 (5)
    //         004e6696     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e669b     POP        EDI
    //         004e669c     POP        ESI
    //         004e669d     POP        EBX
    //         004e669e     RET        0x14
    //                               switchD_004e6612::caseD_3                                    XREF[3]:     004e6612(j), 004e684c(*), 
    //                               switchD_004e6612::caseD_2                                                 004e6850(*)  
    //                              taimdmd.cpp:1092 (22)
    //         004e66a1     MOV        EAX,dword ptr [EBX + 0xf0]
    //         004e66a7     MOVSX      this,word ptr [EAX + 0x4a]
    //         004e66ab     MOV        EAX,dword ptr [ESP + param_1]
    //         004e66af     CMP        EAX,this
    //         004e66b1     JZ         LAB_004e682e
    //                              taimdmd.cpp:1097 (27)
    //         004e66b7     MOV        EDX,dword ptr [ESP + param_5]
    //         004e66bb     MOV        this,dword ptr [ESP + param_4]
    //         004e66bf     PUSH       EDX
    //         004e66c0     MOV        EDX,dword ptr [ESP + param_3]
    //         004e66c4     PUSH       this
    //         004e66c5     PUSH       EDX
    //         004e66c6     PUSH       EAX
    //         004e66c7     LEA        this,[EBX + 0x1146c]
    //         004e66cd     CALL       TribeTacticalAIModule::processCoopAttack         int processCoopAttack(TribeTacticalAIModule *
    //                              taimdmd.cpp:1099 (5)
    //         004e66d2     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e66d7     POP        EDI
    //         004e66d8     POP        ESI
    //         004e66d9     POP        EBX
    //         004e66da     RET        0x14
    //                               switchD_004e6612::caseD_7                                    XREF[2]:     004e6612(j), 004e6860(*)  
    //                              taimdmd.cpp:1105 (4)
    //         004e66dd     MOV        EAX,dword ptr [ESP + param_3]
    //                              taimdmd.cpp:1107 (24)
    //         004e66e1     PUSH       0x1
    //         004e66e3     PUSH       0xd9
    //         004e66e8     LEA        this,[EBX + 0x1146c]
    //         004e66ee     MOV        dword ptr [EBX + 0x125a0],EAX
    //         004e66f4     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taimdmd.cpp:1108 (5)
    //         004e66f9     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e66fe     POP        EDI
    //         004e66ff     POP        ESI
    //         004e6700     POP        EBX
    //         004e6701     RET        0x14
    //                               switchD_004e6612::caseD_6                                    XREF[2]:     004e6612(j), 004e685c(*)  
    //                              taimdmd.cpp:1113 (20)
    //         004e6704     MOV        EDI,dword ptr [ESP + param_3]
    //         004e6708     LEA        ESI,[EBX + 0x9dc]
    //         004e670e     PUSH       0x1
    //         004e6710     PUSH       EDI
    //         004e6711     MOV        this,ESI
    //         004e6713     CALL       DiplomacyAIModule::setChangeable                 void setChangeable(DiplomacyAIModule * this, 
    //                              taimdmd.cpp:1115 (27)
    //         004e6718     MOV        EAX,dword ptr [ESP + param_4]
    //         004e671c     SUB        EAX,0x0
    //         004e671f     JZ         LAB_004e680e
    //         004e6725     DEC        EAX
    //         004e6726     JZ         LAB_004e67f2
    //         004e672c     DEC        EAX
    //         004e672d     JNZ        LAB_004e6824
    //                              taimdmd.cpp:1146 (12)
    //         004e6733     PUSH       0x64
    //         004e6735     PUSH       0x2
    //         004e6737     PUSH       EDI
    //         004e6738     MOV        this,ESI
    //         004e673a     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:1147 (10)
    //         004e673f     PUSH       0x0
    //         004e6741     PUSH       EDI
    //         004e6742     MOV        this,ESI
    //         004e6744     CALL       DiplomacyAIModule::setRelation                   void setRelation(DiplomacyAIModule * this, in
    //                              taimdmd.cpp:1150 (16)
    //         004e6749     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e674f     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
    //         004e6754     CMP        EAX,0x4
    //         004e6757     JNZ        LAB_004e67c5
    //                              taimdmd.cpp:1151 (20)
    //         004e6759     MOV        this,dword ptr [EBX + 0xf0]
    //         004e675f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004e6762     MOV        EAX,dword ptr [EDX + 0x40]
    //         004e6765     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004e6768     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //                              taimdmd.cpp:1152 (28)
    //         004e676d     MOV        EBX,dword ptr [EBX + 0xf0]
    //         004e6773     TEST       EAX,EAX
    //         004e6775     JNZ        LAB_004e679e
    //         004e6777     MOV        this,word ptr [EBX + 0x4a]
    //         004e677b     MOV        EDX,dword ptr [EBX + 0x3c]
    //         004e677e     PUSH       0x1
    //         004e6780     PUSH       this
    //         004e6781     MOV        this,dword ptr [EDX + 0x58]
    //         004e6784     CALL       TRIBE_Command::command_allied_victory            void command_allied_victory(TRIBE_Command * t
    //                              taimdmd.cpp:1162 (10)
    //         004e6789     PUSH       0x0
    //         004e678b     PUSH       EDI
    //         004e678c     MOV        this,ESI
    //         004e678e     CALL       DiplomacyAIModule::setChangeable                 void setChangeable(DiplomacyAIModule * this, 
    //                              taimdmd.cpp:1163 (5)
    //         004e6793     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e6798     POP        EDI
    //         004e6799     POP        ESI
    //         004e679a     POP        EBX
    //         004e679b     RET        0x14
    //                               LAB_004e679e                                                 XREF[1]:     004e6775(j)  
    //                              taimdmd.cpp:1154 (18)
    //         004e679e     MOV        this,dword ptr [EBX + 0x3c]
    //         004e67a1     MOV        AX,word ptr [EBX + 0x4a]
    //         004e67a5     PUSH       0x0
    //         004e67a7     PUSH       EAX
    //         004e67a8     MOV        this,dword ptr [ECX + this->_padding_]
    //         004e67ab     CALL       TRIBE_Command::command_allied_victory            void command_allied_victory(TRIBE_Command * t
    //                              taimdmd.cpp:1162 (10)
    //         004e67b0     PUSH       0x0
    //         004e67b2     PUSH       EDI
    //         004e67b3     MOV        this,ESI
    //         004e67b5     CALL       DiplomacyAIModule::setChangeable                 void setChangeable(DiplomacyAIModule * this, 
    //                              taimdmd.cpp:1163 (5)
    //         004e67ba     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e67bf     POP        EDI
    //         004e67c0     POP        ESI
    //         004e67c1     POP        EBX
    //         004e67c2     RET        0x14
    //                               LAB_004e67c5                                                 XREF[1]:     004e6757(j)  
    //                              taimdmd.cpp:1157 (24)
    //         004e67c5     MOV        EBX,dword ptr [EBX + 0xf0]
    //         004e67cb     PUSH       0x1
    //         004e67cd     MOV        EAX,dword ptr [EBX + 0x3c]
    //         004e67d0     MOV        DX,word ptr [EBX + 0x4a]
    //         004e67d4     PUSH       EDX
    //         004e67d5     MOV        this,dword ptr [EAX + 0x58]
    //         004e67d8     CALL       TRIBE_Command::command_allied_victory            void command_allied_victory(TRIBE_Command * t
    //                              taimdmd.cpp:1162 (10)
    //         004e67dd     PUSH       0x0
    //         004e67df     PUSH       EDI
    //         004e67e0     MOV        this,ESI
    //         004e67e2     CALL       DiplomacyAIModule::setChangeable                 void setChangeable(DiplomacyAIModule * this, 
    //                              taimdmd.cpp:1163 (5)
    //         004e67e7     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (6)
    //         004e67ec     POP        EDI
    //         004e67ed     POP        ESI
    //         004e67ee     POP        EBX
    //         004e67ef     RET        0x14
    //                               LAB_004e67f2                                                 XREF[1]:     004e6726(j)  
    //                              taimdmd.cpp:1133 (12)
    //         004e67f2     PUSH       0x31
    //         004e67f4     PUSH       0x0
    //         004e67f6     PUSH       EDI
    //         004e67f7     MOV        this,ESI
    //         004e67f9     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:1136 (12)
    //         004e67fe     PUSH       0x31
    //         004e6800     PUSH       0x2
    //         004e6802     PUSH       EDI
    //         004e6803     MOV        this,ESI
    //         004e6805     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:1137 (2)
    //         004e680a     PUSH       0x1
    //                              taimdmd.cpp:1138 (2)
    //         004e680c     JMP        LAB_004e681c
    //                               LAB_004e680e                                                 XREF[1]:     004e671f(j)  
    //                              taimdmd.cpp:1123 (12)
    //         004e680e     PUSH       0x64
    //         004e6810     PUSH       0x0
    //         004e6812     PUSH       EDI
    //         004e6813     MOV        this,ESI
    //         004e6815     CALL       DiplomacyAIModule::setStance                     void setStance(DiplomacyAIModule * this, int 
    //                              taimdmd.cpp:1124 (10)
    //         004e681a     PUSH       0x3
    //                               LAB_004e681c                                                 XREF[1]:     004e680c(j)  
    //         004e681c     PUSH       EDI
    //         004e681d     MOV        this,ESI
    //         004e681f     CALL       DiplomacyAIModule::setRelation                   void setRelation(DiplomacyAIModule * this, in
    //                               LAB_004e6824                                                 XREF[1]:     004e672d(j)  
    //                              taimdmd.cpp:1162 (10)
    //         004e6824     PUSH       0x0
    //         004e6826     PUSH       EDI
    //         004e6827     MOV        this,ESI
    //         004e6829     CALL       DiplomacyAIModule::setChangeable                 void setChangeable(DiplomacyAIModule * this, 
    //                               LAB_004e682e                                                 XREF[3]:     004e663f(j), 004e6667(j), 
    //                                                                                                         004e66b1(j)  
    //                              taimdmd.cpp:1163 (5)
    //         004e682e     MOV        EAX,0x1
    //                              taimdmd.cpp:1170 (49)
    //         004e6833     POP        EDI
    //         004e6834     POP        ESI
    //         004e6835     POP        EBX
    //         004e6836     RET        0x14
    //                               switchD_004e6612::caseD_5                                    XREF[4]:     004e660c(j), 004e6612(j), 
    //                               switchD_004e6612::caseD_4                                                 004e6854(*), 004e6858(*)  
    //         004e6839     POP        EDI
    //         004e683a     POP        ESI
    //         004e683b     XOR        EAX,EAX
    //         004e683d     POP        EBX
    //         004e683e     RET        0x14
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004e6841()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004e6841
    //         004e6841     NOP
    //         004e6842     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e6612::switchdataD_004e6844                       XREF[1]:     processAICommand:004e6612(*)  
    //         004e6844     addr       switchD_004e6612::caseD_0
    //         004e6848     addr       switchD_004e6612::caseD_1
    //         004e684c     addr       switchD_004e6612::caseD_2
    //         004e6850     addr       switchD_004e6612::caseD_2
    //         004e6854     addr       switchD_004e6612::caseD_4
    //         004e6858     addr       switchD_004e6612::caseD_4
    //         004e685c     addr       switchD_004e6612::caseD_6
    //         004e6860     addr       switchD_004e6612::caseD_7
    //         004e6864     ??         90h
    //         004e6865     ??         90h
    //         004e6866     ??         90h
    //         004e6867     ??         90h
    //         004e6868     ??         90h
    //         004e6869     ??         90h
    //         004e686a     ??         90h
    //         004e686b     ??         90h
    //         004e686c     ??         90h
    //         004e686d     ??         90h
    //         004e686e     ??         90h
    //         004e686f     ??         90h
    return 0;
}

int TribeMainDecisionAIModule::currentScore(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall currentScore(TribeMainDecisionAIModule * this, int pa
    //              int               EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e6870(R)  
    //                               ?currentScore@TribeMainDecisionAIModule@@QAEHH@Z
    //                               TribeMainDecisionAIModule::currentScore
    //                              taimdmd.cpp:1175 (26)
    //         004e6870     MOV        EDX,dword ptr [ESP + param_1]
    //         004e6874     CMP        EDX,0x1
    //         004e6877     JL         LAB_004e689b
    //         004e6879     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004e687f     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004e6882     MOVSX      this,word ptr [EAX + 0x3c]
    //         004e6886     CMP        EDX,this
    //         004e6888     JG         LAB_004e689b
    //                              taimdmd.cpp:1180 (14)
    //         004e688a     MOV        EAX,dword ptr [EAX + 0x40]
    //         004e688d     MOV        this,dword ptr [EAX + EDX*0x4]
    //         004e6890     MOV        this,dword ptr [ECX + this->_padding_]
    //         004e6893     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //                              taimdmd.cpp:1181 (3)
    //         004e6898     RET        0x4
    //                               LAB_004e689b                                                 XREF[2]:     004e6877(j), 004e6888(j)  
    //                              taimdmd.cpp:1179 (3)
    //         004e689b     OR         EAX,0xffffffff
    //                              taimdmd.cpp:1181 (3)
    //         004e689e     RET        0x4
    //         004e68a1     ??         90h
    //         004e68a2     NOP
    //         004e68a3     NOP
    //         004e68a4     NOP
    //         004e68a5     NOP
    //         004e68a6     NOP
    //         004e68a7     NOP
    //         004e68a8     NOP
    //         004e68a9     NOP
    //         004e68aa     NOP
    //         004e68ab     NOP
    //         004e68ac     NOP
    //         004e68ad     NOP
    //         004e68ae     NOP
    //         004e68af     NOP
    return 0;
}

TribeMainDecisionAIModule::TribeMainDecisionAIModule(void* param_1, int param_2, char* param_3, TRIBE_Player* param_4, char* param_5, char* param_6, char* param_7) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TribeMainDecisionAIModule::TribeMainDecisionAIModule(int param_1, char* param_2, TRIBE_Player* param_3, int param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

