// Auto-generated scaffold unit: aiemomod.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aiemomod.cpp
#include "../include/common.h"

// Offset: 0x0040C7C0
undefined EmotionalAIModule(EmotionalAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall EmotionalAIModule::EmotionalAIModule(void *,int)                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall EmotionalAIModule(EmotionalAIModule * this, voi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0040c7c0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c7c8(R)  
    //                               ??0EmotionalAIModule@@QAE@PAXH@Z                             XREF[1]:     TribeMainDecisionAIModule:004e487a
    //                               EmotionalAIModule::EmotionalAIModule
    //                              aiemomod.cpp:23 (38)
    //         0040c7c0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c7c4     PUSH       EBX
    //         0040c7c5     MOV        EBX,this
    //         0040c7c7     PUSH       ESI
    //         0040c7c8     MOV        this,dword ptr [ESP + param_2]
    //         0040c7cc     PUSH       EDI
    //         0040c7cd     PUSH       EAX
    //         0040c7ce     PUSH       this
    //         0040c7cf     PUSH       0x3ec
    //         0040c7d4     PUSH       s_Emotional_AI                                   = "Emotional AI"
    //         0040c7d9     MOV        this,EBX
    //         0040c7db     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040c7e0     LEA        EDI,[EBX + 0xf4]
    //                              aiemomod.cpp:25 (26)
    //         0040c7e6     MOV        this,0x6
    //         0040c7eb     MOV        EAX,0x31
    //         0040c7f0     MOV        dword ptr [EBX + 0xf0],0x0
    //         0040c7fa     MOV        dword ptr [EBX],EmotionalAIModule::`vftable'     = 0040c900
    //                              aiemomod.cpp:27 (33)
    //         0040c800     LEA        EDX,[EBX + 0x10c]
    //         0040c806     STOSD.REP  ES:EDI
    //         0040c808     OR         this,0xffffffff
    //         0040c80b     MOV        EDI,s_Aggressive                                 = 41h
    //         0040c810     XOR        EAX,EAX
    //         0040c812     SCASB.RE   ES:EDI=>s_Aggressive                             = 41h
    //                                                                                  = "ggressive"
    //         0040c814     NOT        this
    //         0040c816     SUB        EDI,this
    //         0040c818     MOV        EAX,this
    //         0040c81a     MOV        ESI,EDI
    //         0040c81c     SHR        this,0x2
    //         0040c81f     MOV        EDI,EDX
    //                              aiemomod.cpp:28 (37)
    //         0040c821     LEA        EDX,[EBX + 0x12a]
    //         0040c827     MOVSD.REP  ES:EDI,ESI=>s_Aggressive                         = 41h
    //         0040c829     MOV        this,EAX
    //         0040c82b     XOR        EAX,EAX
    //         0040c82d     AND        this,0x3
    //         0040c830     MOVSB.REP  ES:EDI,ESI=>s_Aggressive                         = 41h
    //         0040c832     MOV        EDI,s_Compassionate                              = 43h
    //         0040c837     OR         this,0xffffffff
    //         0040c83a     SCASB.RE   ES:EDI=>s_Compassionate                          = 43h
    //                                                                                  = "ompassionate"
    //         0040c83c     NOT        this
    //         0040c83e     SUB        EDI,this
    //         0040c840     MOV        EAX,this
    //         0040c842     MOV        ESI,EDI
    //         0040c844     MOV        EDI,EDX
    //                              aiemomod.cpp:29 (40)
    //         0040c846     LEA        EDX,[EBX + 0x148]
    //         0040c84c     SHR        this,0x2
    //         0040c84f     MOVSD.REP  ES:EDI,ESI=>s_Compassionate                      = 43h
    //         0040c851     MOV        this,EAX
    //         0040c853     XOR        EAX,EAX
    //         0040c855     AND        this,0x3
    //         0040c858     MOVSB.REP  ES:EDI,ESI=>s_Compassionate                      = 43h
    //         0040c85a     MOV        EDI,s_Defensive                                  = 44h
    //         0040c85f     OR         this,0xffffffff
    //         0040c862     SCASB.RE   ES:EDI=>s_Defensive                              = 44h
    //                                                                                  = "efensive"
    //         0040c864     NOT        this
    //         0040c866     SUB        EDI,this
    //         0040c868     MOV        EAX,this
    //         0040c86a     MOV        ESI,EDI
    //         0040c86c     MOV        EDI,EDX
    //                              aiemomod.cpp:30 (40)
    //         0040c86e     LEA        EDX,[EBX + 0x166]
    //         0040c874     SHR        this,0x2
    //         0040c877     MOVSD.REP  ES:EDI,ESI=>s_Defensive                          = 44h
    //         0040c879     MOV        this,EAX
    //         0040c87b     XOR        EAX,EAX
    //         0040c87d     AND        this,0x3
    //         0040c880     MOVSB.REP  ES:EDI,ESI=>s_Defensive                          = 44h
    //         0040c882     MOV        EDI,s_Friendly                                   = 46h
    //         0040c887     OR         this,0xffffffff
    //         0040c88a     SCASB.RE   ES:EDI=>s_Friendly                               = 46h
    //                                                                                  = "riendly"
    //         0040c88c     NOT        this
    //         0040c88e     SUB        EDI,this
    //         0040c890     MOV        EAX,this
    //         0040c892     MOV        ESI,EDI
    //         0040c894     MOV        EDI,EDX
    //                              aiemomod.cpp:31 (40)
    //         0040c896     LEA        EDX,[EBX + 0x184]
    //         0040c89c     SHR        this,0x2
    //         0040c89f     MOVSD.REP  ES:EDI,ESI=>s_Friendly                           = 46h
    //         0040c8a1     MOV        this,EAX
    //         0040c8a3     AND        this,0x3
    //         0040c8a6     MOVSB.REP  ES:EDI,ESI=>s_Friendly                           = 46h
    //         0040c8a8     MOV        EDI,s_Passive                                    = 50h
    //         0040c8ad     OR         this,0xffffffff
    //         0040c8b0     XOR        EAX,EAX
    //         0040c8b2     SCASB.RE   ES:EDI=>s_Passive                                = 50h
    //                                                                                  = "assive"
    //         0040c8b4     NOT        this
    //         0040c8b6     SUB        EDI,this
    //         0040c8b8     MOV        EAX,this
    //         0040c8ba     MOV        ESI,EDI
    //         0040c8bc     MOV        EDI,EDX
    //                              aiemomod.cpp:32 (47)
    //         0040c8be     LEA        EDX,[EBX + 0x1a2]
    //         0040c8c4     SHR        this,0x2
    //         0040c8c7     MOVSD.REP  ES:EDI,ESI=>s_Passive                            = 50h
    //         0040c8c9     MOV        this,EAX
    //         0040c8cb     XOR        EAX,EAX
    //         0040c8cd     AND        this,0x3
    //         0040c8d0     MOVSB.REP  ES:EDI,ESI=>s_Passive                            = 50h
    //         0040c8d2     MOV        EDI,s_Vengeful                                   = 56h
    //         0040c8d7     OR         this,0xffffffff
    //         0040c8da     SCASB.RE   ES:EDI=>s_Vengeful                               = 56h
    //                                                                                  = "engeful"
    //         0040c8dc     NOT        this
    //         0040c8de     SUB        EDI,this
    //         0040c8e0     MOV        EAX,this
    //         0040c8e2     MOV        ESI,EDI
    //         0040c8e4     MOV        EDI,EDX
    //         0040c8e6     SHR        this,0x2
    //         0040c8e9     MOVSD.REP  ES:EDI,ESI=>s_Vengeful                           = 56h
    //         0040c8eb     MOV        this,EAX
    //                              aiemomod.cpp:33 (13)
    //         0040c8ed     MOV        EAX,EBX
    //         0040c8ef     AND        this,0x3
    //         0040c8f2     MOVSB.REP  ES:EDI,ESI=>s_Vengeful                           = 56h
    //         0040c8f4     POP        EDI
    //         0040c8f5     POP        ESI
    //         0040c8f6     POP        EBX
    //         0040c8f7     RET        0x8
}

// Offset: 0x0040C920
undefined EmotionalAIModule(EmotionalAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall EmotionalAIModule::EmotionalAIModule(int,int)                                      *
    //                              *********************************************************************************************************
    //                              undefined __thiscall EmotionalAIModule(EmotionalAIModule * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040c936(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040c957(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0040c95b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040ca7a(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040c94e(W)  
    //                               ??0EmotionalAIModule@@QAE@HH@Z                               XREF[1]:     TribeMainDecisionAIModule:004e4bfa
    //                               EmotionalAIModule::EmotionalAIModule
    //                              aiemomod.cpp:40 (86)
    //         0040c920     PUSH       -0x1
    //         0040c922     PUSH       FUN_0055c618
    //         0040c927     MOV        EAX,FS:[0x0]
    //         0040c92d     PUSH       EAX
    //         0040c92e     MOV        dword ptr FS:[0x0],ESP
    //         0040c935     PUSH       this
    //         0040c936     MOV        EAX,dword ptr [ESP + param_1]
    //         0040c93a     PUSH       EBX
    //         0040c93b     PUSH       EBP
    //         0040c93c     PUSH       ESI
    //         0040c93d     XOR        ESI,ESI
    //         0040c93f     PUSH       EDI
    //         0040c940     PUSH       ESI
    //         0040c941     PUSH       EAX
    //         0040c942     MOV        EBX,this
    //         0040c944     PUSH       0x3ec
    //         0040c949     PUSH       s_Emotional_AI                                   = "Emotional AI"
    //         0040c94e     MOV        dword ptr [ESP + local_10],EBX
    //         0040c952     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040c957     MOV        EBP,dword ptr [ESP + param_2]
    //         0040c95b     MOV        dword ptr [ESP + local_4],ESI
    //         0040c95f     MOV        dword ptr [EBX + 0xf0],ESI
    //         0040c965     MOV        dword ptr [EBX],EmotionalAIModule::`vftable'     = 0040c900
    //         0040c96b     LEA        ESI,[EBX + 0xf4]
    //         0040c971     MOV        EDI,0x6
    //                               LAB_0040c976                                                 XREF[1]:     0040c986(j)  
    //                              aiemomod.cpp:42 (18)
    //         0040c976     PUSH       0x4
    //         0040c978     PUSH       ESI
    //         0040c979     PUSH       EBP
    //         0040c97a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040c97f     ADD        ESP,0xc
    //         0040c982     ADD        ESI,0x4
    //         0040c985     DEC        EDI
    //         0040c986     JNZ        LAB_0040c976
    //                              aiemomod.cpp:44 (31)
    //         0040c988     OR         this,0xffffffff
    //         0040c98b     MOV        EDI,s_Aggressive                                 = 41h
    //         0040c990     XOR        EAX,EAX
    //         0040c992     LEA        EDX,[EBX + 0x10c]
    //         0040c998     SCASB.RE   ES:EDI=>s_Aggressive                             = 41h
    //                                                                                  = "ggressive"
    //         0040c99a     NOT        this
    //         0040c99c     SUB        EDI,this
    //         0040c99e     MOV        EAX,this
    //         0040c9a0     MOV        ESI,EDI
    //         0040c9a2     SHR        this,0x2
    //         0040c9a5     MOV        EDI,EDX
    //                              aiemomod.cpp:45 (40)
    //         0040c9a7     LEA        EDX,[EBX + 0x12a]
    //         0040c9ad     MOVSD.REP  ES:EDI,ESI
    //         0040c9af     MOV        this,EAX
    //         0040c9b1     XOR        EAX,EAX
    //         0040c9b3     AND        this,0x3
    //         0040c9b6     MOVSB.REP  ES:EDI,ESI
    //         0040c9b8     OR         this,0xffffffff
    //         0040c9bb     MOV        EDI,s_Compassionate                              = 43h
    //         0040c9c0     SCASB.RE   ES:EDI=>s_Compassionate                          = 43h
    //                                                                                  = "ompassionate"
    //         0040c9c2     NOT        this
    //         0040c9c4     SUB        EDI,this
    //         0040c9c6     MOV        EAX,this
    //         0040c9c8     MOV        ESI,EDI
    //         0040c9ca     SHR        this,0x2
    //         0040c9cd     MOV        EDI,EDX
    //                              aiemomod.cpp:46 (37)
    //         0040c9cf     LEA        EDX,[EBX + 0x148]
    //         0040c9d5     MOVSD.REP  ES:EDI,ESI
    //         0040c9d7     MOV        this,EAX
    //         0040c9d9     XOR        EAX,EAX
    //         0040c9db     AND        this,0x3
    //         0040c9de     MOVSB.REP  ES:EDI,ESI
    //         0040c9e0     OR         this,0xffffffff
    //         0040c9e3     MOV        EDI,s_Defensive                                  = 44h
    //         0040c9e8     SCASB.RE   ES:EDI=>s_Defensive                              = 44h
    //                                                                                  = "efensive"
    //         0040c9ea     NOT        this
    //         0040c9ec     SUB        EDI,this
    //         0040c9ee     MOV        EAX,this
    //         0040c9f0     MOV        ESI,EDI
    //         0040c9f2     MOV        EDI,EDX
    //                              aiemomod.cpp:47 (40)
    //         0040c9f4     LEA        EDX,[EBX + 0x166]
    //         0040c9fa     SHR        this,0x2
    //         0040c9fd     MOVSD.REP  ES:EDI,ESI
    //         0040c9ff     MOV        this,EAX
    //         0040ca01     XOR        EAX,EAX
    //         0040ca03     AND        this,0x3
    //         0040ca06     MOVSB.REP  ES:EDI,ESI
    //         0040ca08     MOV        EDI,s_Friendly                                   = 46h
    //         0040ca0d     OR         this,0xffffffff
    //         0040ca10     SCASB.RE   ES:EDI=>s_Friendly                               = 46h
    //                                                                                  = "riendly"
    //         0040ca12     NOT        this
    //         0040ca14     SUB        EDI,this
    //         0040ca16     MOV        EAX,this
    //         0040ca18     MOV        ESI,EDI
    //         0040ca1a     MOV        EDI,EDX
    //                              aiemomod.cpp:48 (40)
    //         0040ca1c     LEA        EDX,[EBX + 0x184]
    //         0040ca22     SHR        this,0x2
    //         0040ca25     MOVSD.REP  ES:EDI,ESI
    //         0040ca27     MOV        this,EAX
    //         0040ca29     XOR        EAX,EAX
    //         0040ca2b     AND        this,0x3
    //         0040ca2e     MOVSB.REP  ES:EDI,ESI
    //         0040ca30     MOV        EDI,s_Passive                                    = 50h
    //         0040ca35     OR         this,0xffffffff
    //         0040ca38     SCASB.RE   ES:EDI=>s_Passive                                = 50h
    //                                                                                  = "assive"
    //         0040ca3a     NOT        this
    //         0040ca3c     SUB        EDI,this
    //         0040ca3e     MOV        EAX,this
    //         0040ca40     MOV        ESI,EDI
    //         0040ca42     MOV        EDI,EDX
    //                              aiemomod.cpp:49 (47)
    //         0040ca44     LEA        EDX,[EBX + 0x1a2]
    //         0040ca4a     SHR        this,0x2
    //         0040ca4d     MOVSD.REP  ES:EDI,ESI
    //         0040ca4f     MOV        this,EAX
    //         0040ca51     XOR        EAX,EAX
    //         0040ca53     AND        this,0x3
    //         0040ca56     MOVSB.REP  ES:EDI,ESI
    //         0040ca58     MOV        EDI,s_Vengeful                                   = 56h
    //         0040ca5d     OR         this,0xffffffff
    //         0040ca60     SCASB.RE   ES:EDI=>s_Vengeful                               = 56h
    //                                                                                  = "engeful"
    //         0040ca62     NOT        this
    //         0040ca64     SUB        EDI,this
    //         0040ca66     MOV        EAX,this
    //         0040ca68     MOV        ESI,EDI
    //         0040ca6a     MOV        EDI,EDX
    //         0040ca6c     SHR        this,0x2
    //         0040ca6f     MOVSD.REP  ES:EDI,ESI
    //         0040ca71     MOV        this,EAX
    //                              aiemomod.cpp:50 (28)
    //         0040ca73     MOV        EAX,EBX
    //         0040ca75     AND        this,0x3
    //         0040ca78     MOVSB.REP  ES:EDI,ESI
    //         0040ca7a     MOV        this,dword ptr [ESP + local_c]
    //         0040ca7e     POP        EDI
    //         0040ca7f     POP        ESI
    //         0040ca80     POP        EBP
    //         0040ca81     MOV        dword ptr FS:[0x0],this
    //         0040ca88     POP        EBX
    //         0040ca89     ADD        ESP,0x10
    //         0040ca8c     RET        0x8
}

// Offset: 0x0040CA90
void EmotionalAIModule(EmotionalAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall EmotionalAIModule::~EmotionalAIModule(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~EmotionalAIModule(EmotionalAIModule * this)
    //              void              <VOID>         <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //                               ??1EmotionalAIModule@@UAE@XZ                                 XREF[4]:     `vector_deleting_destructor':0040c
    //                               EmotionalAIModule::~EmotionalAIModule                                     ~TribeMainDecisionAIModule:004e4f4
    //                                                                                                         FUN_00560652:0056065b(c), 
    //                                                                                                         FUN_005606e2:005606eb(c)  
    //                              aiemomod.cpp:55 (11)
    //         0040ca90     MOV        dword ptr [this->_padding_],EmotionalAIModule:   = 0040c900
    //         0040ca96     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0040CAA0
void setMainDecisionAI(EmotionalAIModule* this_, MainDecisionAIModule* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall EmotionalAIModule::setMainDecisionAI(class MainDecisionAIModule *)            *
    //                              *********************************************************************************************************
    //                              void __thiscall setMainDecisionAI(EmotionalAIModule * this, MainDeci
    //              void              <VOID>         <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              MainDecisionAI    Stack[0x4]:4   param_1                   XREF[1]:     0040caa0(R)  
    //                               ?setMainDecisionAI@EmotionalAIModule@@QAEXPAVMainDecisionAI  XREF[2]:     TribeMainDecisionAIModule:004e49a1
    //                               EmotionalAIModule::setMainDecisionAI                                      TribeMainDecisionAIModule:004e4ce4
    //                              aiemomod.cpp:61 (10)
    //         0040caa0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040caa4     MOV        dword ptr [ECX + this->md],EAX
    //                              aiemomod.cpp:63 (3)
    //         0040caaa     RET        0x4
}

// Offset: 0x0040CAB0
int EmotionalAIModule::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall EmotionalAIModule::save(int)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall save(EmotionalAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cab1(R)  
    //                               ?save@EmotionalAIModule@@UAEHH@Z                             XREF[1]:     0056e894(*)  
    //                               EmotionalAIModule::save
    //                              aiemomod.cpp:68 (1)
    //         0040cab0     PUSH       EBX
    //                              aiemomod.cpp:69 (17)
    //         0040cab1     MOV        EBX,dword ptr [ESP + param_1]
    //         0040cab5     PUSH       ESI
    //         0040cab6     PUSH       EDI
    //         0040cab7     LEA        ESI,[ECX + this->stateValue[0]]
    //         0040cabd     MOV        EDI,0x6
    //                               LAB_0040cac2                                                 XREF[1]:     0040cad2(j)  
    //                              aiemomod.cpp:70 (18)
    //         0040cac2     PUSH       0x4
    //         0040cac4     PUSH       ESI
    //         0040cac5     PUSH       EBX
    //         0040cac6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040cacb     ADD        ESP,0xc
    //         0040cace     ADD        ESI,0x4
    //         0040cad1     DEC        EDI
    //         0040cad2     JNZ        LAB_0040cac2
    //                              aiemomod.cpp:72 (11)
    //         0040cad4     POP        EDI
    //         0040cad5     POP        ESI
    //         0040cad6     MOV        EAX,0x1
    //         0040cadb     POP        EBX
    //         0040cadc     RET        0x4
}

// Offset: 0x0040CAE0
char* stateName(EmotionalAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall EmotionalAIModule::stateName(int)                                           *
    //                              *********************************************************************************************************
    //                              char * __thiscall stateName(EmotionalAIModule * this, int param_1)
    //              char *            EAX:4          <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cae0(R)  
    //                               ?stateName@EmotionalAIModule@@QAEPADH@Z
    //                               EmotionalAIModule::stateName
    //                              aiemomod.cpp:77 (13)
    //         0040cae0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cae4     TEST       EAX,EAX
    //         0040cae6     JL         LAB_0040cafd
    //         0040cae8     CMP        EAX,0x6
    //         0040caeb     JGE        LAB_0040cafd
    //                              aiemomod.cpp:80 (13)
    //         0040caed     LEA        EAX,[EAX + EAX*0x2]
    //         0040caf0     LEA        EAX,[EAX + EAX*0x4]
    //         0040caf3     LEA        EAX,[ECX + EAX*0x2 + this->stateNameValue[0][0]]
    //                              aiemomod.cpp:81 (3)
    //         0040cafa     RET        0x4
    //                               LAB_0040cafd                                                 XREF[2]:     0040cae6(j), 0040caeb(j)  
    //                              aiemomod.cpp:79 (2)
    //         0040cafd     XOR        EAX,EAX
    //                              aiemomod.cpp:81 (3)
    //         0040caff     RET        0x4
}

// Offset: 0x0040CB10
int state(EmotionalAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall EmotionalAIModule::state(int)const                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall state(EmotionalAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cb10(R)  
    //                               ?state@EmotionalAIModule@@QBEHH@Z
    //                               EmotionalAIModule::state
    //                              aiemomod.cpp:86 (13)
    //         0040cb10     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cb14     TEST       EAX,EAX
    //         0040cb16     JL         LAB_0040cb27
    //         0040cb18     CMP        EAX,0x6
    //         0040cb1b     JGE        LAB_0040cb27
    //                              aiemomod.cpp:89 (7)
    //         0040cb1d     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->stateValu
    //                              aiemomod.cpp:90 (3)
    //         0040cb24     RET        0x4
    //                               LAB_0040cb27                                                 XREF[2]:     0040cb16(j), 0040cb1b(j)  
    //                              aiemomod.cpp:88 (3)
    //         0040cb27     OR         EAX,0xffffffff
    //                              aiemomod.cpp:90 (3)
    //         0040cb2a     RET        0x4
}

// Offset: 0x0040CB30
void setState(EmotionalAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall EmotionalAIModule::setState(int,int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall setState(EmotionalAIModule * this, int param_1, int 
    //              void              <VOID>         <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cb30(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040cb3d(R)  
    //                               ?setState@EmotionalAIModule@@QAEXHH@Z
    //                               EmotionalAIModule::setState
    //                              aiemomod.cpp:95 (13)
    //         0040cb30     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cb34     TEST       EAX,EAX
    //         0040cb36     JL         LAB_0040cb48
    //         0040cb38     CMP        EAX,0x6
    //         0040cb3b     JGE        LAB_0040cb48
    //                              aiemomod.cpp:97 (11)
    //         0040cb3d     MOV        EDX,dword ptr [ESP + param_2]
    //         0040cb41     MOV        dword ptr [ECX + EAX*0x4 + this->stateValue[0]
    //                               LAB_0040cb48                                                 XREF[2]:     0040cb36(j), 0040cb3b(j)  
    //                              aiemomod.cpp:98 (3)
    //         0040cb48     RET        0x8
}

// Offset: 0x0040CB50
void incrementState(EmotionalAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall EmotionalAIModule::incrementState(int,int)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementState(EmotionalAIModule * this, int param_1
    //              void              <VOID>         <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cb50(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040cb5d(R)  
    //                               ?incrementState@EmotionalAIModule@@QAEXHH@Z
    //                               EmotionalAIModule::incrementState
    //                              aiemomod.cpp:103 (13)
    //         0040cb50     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cb54     TEST       EAX,EAX
    //         0040cb56     JL         LAB_0040cb73
    //         0040cb58     CMP        EAX,0x6
    //         0040cb5b     JGE        LAB_0040cb73
    //                              aiemomod.cpp:105 (22)
    //         0040cb5d     MOV        EDX,dword ptr [ESP + param_2]
    //         0040cb61     PUSH       ESI
    //         0040cb62     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->stateValu
    //         0040cb69     ADD        ESI,EDX
    //         0040cb6b     MOV        dword ptr [ECX + EAX*0x4 + this->stateValue[0]
    //         0040cb72     POP        ESI
    //                               LAB_0040cb73                                                 XREF[2]:     0040cb56(j), 0040cb5b(j)  
    //                              aiemomod.cpp:106 (3)
    //         0040cb73     RET        0x8
}

// Offset: 0x0040CB80
void decrementState(EmotionalAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall EmotionalAIModule::decrementState(int,int)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall decrementState(EmotionalAIModule * this, int param_1
    //              void              <VOID>         <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cb80(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040cb8d(R)  
    //                               ?decrementState@EmotionalAIModule@@QAEXHH@Z
    //                               EmotionalAIModule::decrementState
    //                              aiemomod.cpp:111 (13)
    //         0040cb80     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cb84     TEST       EAX,EAX
    //         0040cb86     JL         LAB_0040cba3
    //         0040cb88     CMP        EAX,0x6
    //         0040cb8b     JGE        LAB_0040cba3
    //                              aiemomod.cpp:113 (22)
    //         0040cb8d     MOV        EDX,dword ptr [ESP + param_2]
    //         0040cb91     PUSH       ESI
    //         0040cb92     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->stateValu
    //         0040cb99     SUB        ESI,EDX
    //         0040cb9b     MOV        dword ptr [ECX + EAX*0x4 + this->stateValue[0]
    //         0040cba2     POP        ESI
    //                               LAB_0040cba3                                                 XREF[2]:     0040cb86(j), 0040cb8b(j)  
    //                              aiemomod.cpp:114 (3)
    //         0040cba3     RET        0x8
}

// Offset: 0x0040CBB0
int overallState(EmotionalAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall EmotionalAIModule::overallState(void)const                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall overallState(EmotionalAIModule * this)
    //              int               EAX:4          <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //                               ?overallState@EmotionalAIModule@@QBEHXZ
    //                               EmotionalAIModule::overallState
    //                              aiemomod.cpp:119 (2)
    //         0040cbb0     PUSH       ESI
    //         0040cbb1     PUSH       EDI
    //                              aiemomod.cpp:122 (8)
    //         0040cbb2     MOV        EDI,dword ptr [ECX + this->stateValue[0]]
    //         0040cbb8     XOR        EAX,EAX
    //                              aiemomod.cpp:123 (11)
    //         0040cbba     MOV        EDX,0x1
    //         0040cbbf     LEA        ESI,[ECX + this+0xf8]
    //                               LAB_0040cbc5                                                 XREF[1]:     0040cbd6(j)  
    //                              aiemomod.cpp:124 (6)
    //         0040cbc5     MOV        this,dword ptr [ESI]
    //         0040cbc7     CMP        EDI,this
    //         0040cbc9     JGE        LAB_0040cbcf
    //                              aiemomod.cpp:125 (2)
    //         0040cbcb     MOV        EAX,EDX
    //                              aiemomod.cpp:126 (11)
    //         0040cbcd     MOV        EDI,this
    //                               LAB_0040cbcf                                                 XREF[1]:     0040cbc9(j)  
    //         0040cbcf     INC        EDX
    //         0040cbd0     ADD        ESI,0x4
    //         0040cbd3     CMP        EDX,0x6
    //         0040cbd6     JL         LAB_0040cbc5
    //                              aiemomod.cpp:129 (3)
    //         0040cbd8     POP        EDI
    //         0040cbd9     POP        ESI
    //         0040cbda     RET
}

// Offset: 0x0040CBE0
void setOverallState(EmotionalAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall EmotionalAIModule::setOverallState(int)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall setOverallState(EmotionalAIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040cbe0(R)  
    //                               ?setOverallState@EmotionalAIModule@@QAEXH@Z                  XREF[2]:     TribeMainDecisionAIModule:004e4b33
    //                               EmotionalAIModule::setOverallState                                        loadAIInformation:00515958(c)  
    //                              aiemomod.cpp:134 (20)
    //         0040cbe0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cbe4     CMP        EAX,0x5
    //         0040cbe7     JA         switchD_0040cbed::default
    //                               switchD_0040cbed::switchD
    //         0040cbed     JMP        dword ptr [EAX*0x4 + switchD_0040cbed::switchd   = 0040cbf4
    //                               switchD_0040cbed::caseD_0                                    XREF[2]:     0040cbed(j), 0040cd60(*)  
    //                              aiemomod.cpp:140 (21)
    //         0040cbf4     MOV        EAX,0xa
    //         0040cbf9     MOV        dword ptr [ECX + this->stateValue[0]],0x64
    //         0040cc03     MOV        dword ptr [ECX + this+0x104],EAX
    //                              aiemomod.cpp:141 (6)
    //         0040cc09     MOV        dword ptr [ECX + this+0xf8],EAX
    //                              aiemomod.cpp:142 (6)
    //         0040cc0f     MOV        dword ptr [ECX + this+0x100],EAX
    //                              aiemomod.cpp:143 (10)
    //         0040cc15     MOV        dword ptr [ECX + this+0xfc],0x0
    //                              aiemomod.cpp:144 (10)
    //         0040cc1f     MOV        dword ptr [ECX + this+0x108],0x46
    //                              aiemomod.cpp:187 (3)
    //         0040cc29     RET        0x4
    //                               switchD_0040cbed::caseD_4                                    XREF[2]:     0040cbed(j), 0040cd70(*)  
    //                              aiemomod.cpp:147 (10)
    //         0040cc2c     MOV        dword ptr [ECX + this->stateValue[0]],0x14
    //                              aiemomod.cpp:148 (10)
    //         0040cc36     MOV        dword ptr [ECX + this+0x104],0x64
    //                              aiemomod.cpp:149 (10)
    //         0040cc40     MOV        dword ptr [ECX + this+0xf8],0x46
    //                              aiemomod.cpp:150 (10)
    //         0040cc4a     MOV        dword ptr [ECX + this+0x100],0x32
    //                              aiemomod.cpp:151 (10)
    //         0040cc54     MOV        dword ptr [ECX + this+0xfc],0x3c
    //                              aiemomod.cpp:152 (10)
    //         0040cc5e     MOV        dword ptr [ECX + this+0x108],0x0
    //                              aiemomod.cpp:187 (3)
    //         0040cc68     RET        0x4
    //                               switchD_0040cbed::caseD_1                                    XREF[2]:     0040cbed(j), 0040cd64(*)  
    //                              aiemomod.cpp:156 (21)
    //         0040cc6b     MOV        EAX,0x32
    //         0040cc70     MOV        dword ptr [ECX + this->stateValue[0]],0xa
    //         0040cc7a     MOV        dword ptr [ECX + this+0x104],EAX
    //                              aiemomod.cpp:157 (10)
    //         0040cc80     MOV        dword ptr [ECX + this+0xf8],0x64
    //                              aiemomod.cpp:158 (10)
    //         0040cc8a     MOV        dword ptr [ECX + this+0x100],0x50
    //                              aiemomod.cpp:159 (6)
    //         0040cc94     MOV        dword ptr [ECX + this+0xfc],EAX
    //                              aiemomod.cpp:160 (10)
    //         0040cc9a     MOV        dword ptr [ECX + this+0x108],0x0
    //                              aiemomod.cpp:187 (3)
    //         0040cca4     RET        0x4
    //                               switchD_0040cbed::caseD_3                                    XREF[2]:     0040cbed(j), 0040cd6c(*)  
    //                              aiemomod.cpp:164 (21)
    //         0040cca7     MOV        EAX,0x32
    //         0040ccac     MOV        dword ptr [ECX + this->stateValue[0]],0xa
    //         0040ccb6     MOV        dword ptr [ECX + this+0x104],EAX
    //                              aiemomod.cpp:165 (10)
    //         0040ccbc     MOV        dword ptr [ECX + this+0xf8],0x46
    //                              aiemomod.cpp:166 (10)
    //         0040ccc6     MOV        dword ptr [ECX + this+0x100],0x64
    //                              aiemomod.cpp:167 (6)
    //         0040ccd0     MOV        dword ptr [ECX + this+0xfc],EAX
    //                              aiemomod.cpp:168 (10)
    //         0040ccd6     MOV        dword ptr [ECX + this+0x108],0x14
    //                              aiemomod.cpp:187 (3)
    //         0040cce0     RET        0x4
    //                               switchD_0040cbed::caseD_2                                    XREF[2]:     0040cbed(j), 0040cd68(*)  
    //                              aiemomod.cpp:173 (31)
    //         0040cce3     MOV        EAX,0x32
    //         0040cce8     MOV        dword ptr [ECX + this->stateValue[0]],0x14
    //         0040ccf2     MOV        dword ptr [ECX + this+0x104],0x3c
    //         0040ccfc     MOV        dword ptr [ECX + this+0xf8],EAX
    //                              aiemomod.cpp:174 (6)
    //         0040cd02     MOV        dword ptr [ECX + this+0x100],EAX
    //                              aiemomod.cpp:175 (10)
    //         0040cd08     MOV        dword ptr [ECX + this+0xfc],0x64
    //                              aiemomod.cpp:176 (10)
    //         0040cd12     MOV        dword ptr [ECX + this+0x108],0xa
    //                              aiemomod.cpp:187 (3)
    //         0040cd1c     RET        0x4
    //                               switchD_0040cbed::caseD_5                                    XREF[2]:     0040cbed(j), 0040cd74(*)  
    //                              aiemomod.cpp:179 (10)
    //         0040cd1f     MOV        dword ptr [ECX + this->stateValue[0]],0x5a
    //                              aiemomod.cpp:180 (10)
    //         0040cd29     MOV        dword ptr [ECX + this+0x104],0xa
    //                              aiemomod.cpp:181 (10)
    //         0040cd33     MOV        dword ptr [ECX + this+0xf8],0x0
    //                              aiemomod.cpp:182 (10)
    //         0040cd3d     MOV        dword ptr [ECX + this+0x100],0x1e
    //                              aiemomod.cpp:183 (10)
    //         0040cd47     MOV        dword ptr [ECX + this+0xfc],0x32
    //                              aiemomod.cpp:184 (10)
    //         0040cd51     MOV        dword ptr [ECX + this+0x108],0x64
    //                               switchD_0040cbed::default                                    XREF[1]:     0040cbe7(j)  
    //                              aiemomod.cpp:187 (29)
    //         0040cd5b     RET        0x4
}

// Offset: 0x0040CD5E
undefined FUN_0040cd5e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0040cd5e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0040cd5e
    //         0040cd5e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0040cbed::switchdataD_0040cd60                       XREF[1]:     setOverallState:0040cbed(*)  
}

// Offset: 0x0040CD80
int defaultState(EmotionalAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall EmotionalAIModule::defaultState(void)const                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall defaultState(EmotionalAIModule * this)
    //              int               EAX:4          <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //                               ?defaultState@EmotionalAIModule@@QBEHXZ
    //                               EmotionalAIModule::defaultState
    //                              aiemomod.cpp:192 (5)
    //         0040cd80     MOV        EAX,0x4
    //                              aiemomod.cpp:194 (1)
    //         0040cd85     RET
}

