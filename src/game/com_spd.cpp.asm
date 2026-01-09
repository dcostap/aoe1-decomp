#include "common.h"
#include "com_spd.h"

RGE_Communications_Speed::~RGE_Communications_Speed() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Communications_Speed(RGE_Communications_Speed *
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ??1RGE_Communications_Speed@@QAE@XZ                          XREF[3]:     ~TCommunications_Handler:00426306(
    //                               RGE_Communications_Speed::~RGE_Communications_Speed                       UnlinkCurrentLevel:0042c1d2(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c36b(c)  
    //                              com_spd.cpp:63 (4)
    //         00432780     PUSH       ESI
    //         00432781     MOV        ESI,this
    //         00432783     PUSH       EDI
    //                              com_spd.cpp:65 (26)
    //         00432784     MOV        EDI,dword ptr [ESI + 0x104]
    //         0043278a     TEST       EDI,EDI
    //         0043278c     JZ         LAB_0043279e
    //         0043278e     MOV        this,EDI
    //         00432790     CALL       RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall    void ~RGE_TimeSinceLastCall(RGE_TimeSinceLast
    //         00432795     PUSH       EDI
    //         00432796     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043279b     ADD        ESP,0x4
    //                               LAB_0043279e                                                 XREF[1]:     0043278c(j)  
    //                              com_spd.cpp:66 (26)
    //         0043279e     MOV        ESI,dword ptr [ESI + 0x100]
    //         004327a4     TEST       ESI,ESI
    //         004327a6     JZ         LAB_004327b8
    //         004327a8     MOV        this,ESI
    //         004327aa     CALL       RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall    void ~RGE_TimeSinceLastCall(RGE_TimeSinceLast
    //         004327af     PUSH       ESI
    //         004327b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004327b5     ADD        ESP,0x4
    //                               LAB_004327b8                                                 XREF[1]:     004327a6(j)  
    //                              com_spd.cpp:67 (3)
    //         004327b8     POP        EDI
    //         004327b9     POP        ESI
    //         004327ba     RET
    //         004327bb     ??         90h
    //         004327bc     NOP
    //         004327bd     NOP
    //         004327be     NOP
    //         004327bf     NOP
    //                              * public: void __thiscall RGE_Communications_Speed::SetPlayerTurnSpeed(unsigned int,unsigned char,un... *
    //                              void __thiscall SetPlayerTurnSpeed(RGE_Communications_Speed * this, 
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004327c0(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004327ce(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004327de(R)  
    //                               ?SetPlayerTurnSpeed@RGE_Communications_Speed@@QAEXIEE@Z      XREF[4]:     DoCycle:00426809(c), 
    //                               RGE_Communications_Speed::SetPlayerTurnSpeed                              PreprocessMessages:00427b1b(c), 
    //                                                                                                         PreprocessMessages:00427e1f(c), 
    //                                                                                                         EvaluatePlayerMessage:00428312(c)  
    //                              com_spd.cpp:70 (14)
    //         004327c0     MOV        EDX,dword ptr [ESP + param_1]
    //         004327c4     CMP        EDX,0x1
    //         004327c7     JC         LAB_004327f3
    //         004327c9     CMP        EDX,0x9
    //         004327cc     JA         LAB_004327f3
    //                              com_spd.cpp:73 (16)
    //         004327ce     MOV        EAX,dword ptr [ESP + param_2]
    //         004327d2     AND        EAX,0xff
    //         004327d7     MOV        dword ptr [ECX + EDX*0x4 + this->PlayerAvgFram
    //                              com_spd.cpp:74 (21)
    //         004327de     MOV        EAX,dword ptr [ESP + param_3]
    //         004327e2     AND        EAX,0xff
    //         004327e7     LEA        EAX,[EAX + EAX*0x4]
    //         004327ea     SHL        EAX,0x1
    //         004327ec     MOV        dword ptr [ECX + EDX*0x4 + this->PlayerHighLat
    //                               LAB_004327f3                                                 XREF[2]:     004327c7(j), 004327cc(j)  
    //                              com_spd.cpp:80 (3)
    //         004327f3     RET        0xc
    //         004327f6     ??         90h
    //         004327f7     NOP
    //         004327f8     NOP
    //         004327f9     NOP
    //         004327fa     NOP
    //         004327fb     NOP
    //         004327fc     NOP
    //         004327fd     NOP
    //         004327fe     NOP
    //         004327ff     NOP
}

void RGE_Communications_Speed::SetActualLatency(uint param_1, ulong param_2) {
    /* TODO: Stub */
    //                              void __thiscall SetActualLatency(RGE_Communications_Speed * this, ui
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00432800(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0043280e(R)  
    //                               ?SetActualLatency@RGE_Communications_Speed@@QAEXIK@Z         XREF[1]:     PreprocessMessages:00427e76(c)  
    //                               RGE_Communications_Speed::SetActualLatency
    //                              com_spd.cpp:83 (14)
    //         00432800     MOV        EDX,dword ptr [ESP + param_1]
    //         00432804     CMP        EDX,0x1
    //         00432807     JC         LAB_0043282f
    //         00432809     CMP        EDX,0x9
    //         0043280c     JA         LAB_0043282f
    //                              com_spd.cpp:88 (9)
    //         0043280e     MOV        EAX,dword ptr [ESP + param_2]
    //         00432812     CMP        EAX,0x1e
    //         00432815     JNC        LAB_0043281c
    //                              com_spd.cpp:89 (5)
    //         00432817     MOV        EAX,0x1e
    //                               LAB_0043281c                                                 XREF[1]:     00432815(j)  
    //                              com_spd.cpp:91 (7)
    //         0043281c     CMP        EAX,0x1770
    //         00432821     JBE        LAB_00432828
    //                              com_spd.cpp:92 (5)
    //         00432823     MOV        EAX,0x1770
    //                               LAB_00432828                                                 XREF[1]:     00432821(j)  
    //                              com_spd.cpp:94 (7)
    //         00432828     MOV        dword ptr [ECX + EDX*0x4 + this->ActualLatency
    //                               LAB_0043282f                                                 XREF[2]:     00432807(j), 0043280c(j)  
    //                              com_spd.cpp:95 (3)
    //         0043282f     RET        0x8
    //         00432832     ??         90h
    //         00432833     NOP
    //         00432834     NOP
    //         00432835     NOP
    //         00432836     NOP
    //         00432837     NOP
    //         00432838     NOP
    //         00432839     NOP
    //         0043283a     NOP
    //         0043283b     NOP
    //         0043283c     NOP
    //         0043283d     NOP
    //         0043283e     NOP
    //         0043283f     NOP
    //                              * public: void __thiscall RGE_Communications_Speed::SetFutureSpeedChange(unsigned int,unsigned int,u... *
    //                              void __thiscall SetFutureSpeedChange(RGE_Communications_Speed * this
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043284a(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     0043284e(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00432858(R)  
    //                               ?SetFutureSpeedChange@RGE_Communications_Speed@@QAEXIIK@Z    XREF[2]:     EvaluatePlayerMessage:00428425(c), 
    //                               RGE_Communications_Speed::SetFutureSpeedChange                            AnalyzeGameSpeed:00432f86(c)  
    //                              com_spd.cpp:98 (10)
    //         00432840     MOV        EAX,dword ptr [ECX + this->NextLatencyChangeTu
    //         00432846     TEST       EAX,EAX
    //         00432848     JNZ        LAB_00432868
    //                              com_spd.cpp:108 (4)
    //         0043284a     MOV        EAX,dword ptr [ESP + param_1]
    //                              com_spd.cpp:109 (10)
    //         0043284e     MOV        EDX,dword ptr [ESP + param_2]
    //         00432852     MOV        dword ptr [ECX + this->FutureBufferFrames],EAX
    //                              com_spd.cpp:110 (16)
    //         00432858     MOV        EAX,dword ptr [ESP + param_3]
    //         0043285c     MOV        dword ptr [ECX + this->FutureBufferGranularity
    //         00432862     MOV        dword ptr [ECX + this->NextLatencyChangeTurn],
    //                               LAB_00432868                                                 XREF[1]:     00432848(j)  
    //                              com_spd.cpp:112 (3)
    //         00432868     RET        0xc
    //         0043286b     ??         90h
    //         0043286c     NOP
    //         0043286d     NOP
    //         0043286e     NOP
    //         0043286f     NOP
    return;
}

void RGE_Communications_Speed::EnableSpeedControl(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall EnableSpeedControl(RGE_Communications_Speed * this, 
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00432870(R)  
    //                               ?EnableSpeedControl@RGE_Communications_Speed@@QAEXH@Z        XREF[1]:     SetSpeedControl:0042597b(c)  
    //                               RGE_Communications_Speed::EnableSpeedControl
    //                              com_spd.cpp:115 (10)
    //         00432870     MOV        EAX,dword ptr [ESP + param_1]
    //         00432874     MOV        dword ptr [ECX + this->SpeedControlEnabled],EAX
    //                              com_spd.cpp:121 (3)
    //         0043287a     RET        0x4
    //         0043287d     ??         90h
    //         0043287e     NOP
    //         0043287f     NOP
    return;
}

uint RGE_Communications_Speed::GetBufferGranularity() {
    /* TODO: Stub */
    //                              uint __thiscall GetBufferGranularity(RGE_Communications_Speed * this)
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetBufferGranularity@RGE_Communications_Speed@@QAEIXZ
    //                               RGE_Communications_Speed::GetBufferGranularity
    //                              com_spd.cpp:124 (6)
    //         00432880     MOV        EAX,dword ptr [ECX + this->CurrentBufferGranul
    //                              com_spd.cpp:126 (1)
    //         00432886     RET
    //         00432887     ??         90h
    //         00432888     NOP
    //         00432889     NOP
    //         0043288a     NOP
    //         0043288b     NOP
    //         0043288c     NOP
    //         0043288d     NOP
    //         0043288e     NOP
    //         0043288f     NOP
    return 0;
}

ulong RGE_Communications_Speed::GetAdjustmentCount() {
    /* TODO: Stub */
    //                              ulong __thiscall GetAdjustmentCount(RGE_Communications_Speed * this)
    //              ulong             EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetAdjustmentCount@RGE_Communications_Speed@@QAEKXZ         XREF[1]:     GetCommInfo:0042cebc(c)  
    //                               RGE_Communications_Speed::GetAdjustmentCount
    //                              com_spd.cpp:129 (6)
    //         00432890     MOV        EAX,dword ptr [ECX + this->AdjustmentCount]
    //                              com_spd.cpp:131 (1)
    //         00432896     RET
    //         00432897     ??         90h
    //         00432898     NOP
    //         00432899     NOP
    //         0043289a     NOP
    //         0043289b     NOP
    //         0043289c     NOP
    //         0043289d     NOP
    //         0043289e     NOP
    //         0043289f     NOP
    return 0;
}

uint RGE_Communications_Speed::GetBufferGranularityAdjusted() {
    /* TODO: Stub */
    //                              uint __thiscall GetBufferGranularityAdjusted(RGE_Communications_Spee
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetBufferGranularityAdjusted@RGE_Communications_Speed@@QAE  XREF[1]:     DoCycle:00426d20(c)  
    //                               RGE_Communications_Speed::GetBufferGranularityAdjusted
    //                              com_spd.cpp:135 (16)
    //         004328a0     MOV        EAX,dword ptr [ECX + this->CurrentBufferGranul
    //         004328a6     MOV        dword ptr [ECX + this->LastFrameHadTime],0x1
    //                              com_spd.cpp:141 (1)
    //         004328b0     RET
    //         004328b1     ??         90h
    //         004328b2     NOP
    //         004328b3     NOP
    //         004328b4     NOP
    //         004328b5     NOP
    //         004328b6     NOP
    //         004328b7     NOP
    //         004328b8     NOP
    //         004328b9     NOP
    //         004328ba     NOP
    //         004328bb     NOP
    //         004328bc     NOP
    //         004328bd     NOP
    //         004328be     NOP
    //         004328bf     NOP
    return 0;
}

uint RGE_Communications_Speed::BufferFramesRemaining() {
    /* TODO: Stub */
    //                              uint __thiscall BufferFramesRemaining(RGE_Communications_Speed * this)
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?BufferFramesRemaining@RGE_Communications_Speed@@QAEIXZ      XREF[1]:     DoCycle:004268c9(c)  
    //                               RGE_Communications_Speed::BufferFramesRemaining
    //                              com_spd.cpp:145 (6)
    //         004328c0     MOV        EAX,dword ptr [ECX + this->TotalBufferFramesRe
    //                              com_spd.cpp:148 (1)
    //         004328c6     RET
    //         004328c7     ??         90h
    //         004328c8     NOP
    //         004328c9     NOP
    //         004328ca     NOP
    //         004328cb     NOP
    //         004328cc     NOP
    //         004328cd     NOP
    //         004328ce     NOP
    //         004328cf     NOP
    return 0;
}

uint RGE_Communications_Speed::WaitingOnAcknowledgement() {
    /* TODO: Stub */
    //                              uint __thiscall WaitingOnAcknowledgement(RGE_Communications_Speed * 
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?WaitingOnAcknowledgement@RGE_Communications_Speed@@QAEIXZ   XREF[1]:     DoCycle:0042692a(c)  
    //                               RGE_Communications_Speed::WaitingOnAcknowledgement
    //                              com_spd.cpp:151 (13)
    //         004328d0     MOV        EAX,dword ptr [ECX + this->SkipFrames]
    //         004328d6     INC        EAX
    //         004328d7     MOV        dword ptr [ECX + this->SkipFrames],EAX
    //                              com_spd.cpp:154 (1)
    //         004328dd     RET
    //         004328de     ??         90h
    //         004328df     NOP
    return 0;
}

void RGE_Communications_Speed::AdjustLocalSpeed() {
    /* TODO: Stub */
    //                              void __thiscall AdjustLocalSpeed(RGE_Communications_Speed * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?AdjustLocalSpeed@RGE_Communications_Speed@@IAEXXZ           XREF[1]:     ReloadBufferFrames:0043295a(c)  
    //                               RGE_Communications_Speed::AdjustLocalSpeed
    //                              com_spd.cpp:159 (13)
    //         004328e0     MOV        EAX,dword ptr [ECX + this->NextLatencyChangeTu
    //         004328e6     XOR        EDX,EDX
    //         004328e8     PUSH       ESI
    //         004328e9     CMP        EAX,EDX
    //         004328eb     JZ         LAB_00432938
    //                              com_spd.cpp:170 (20)
    //         004328ed     MOV        ESI,dword ptr [ECX + this->Comm]
    //         004328f3     MOV        dword ptr [ECX + this->LastAdjusted],EDX
    //         004328f9     CMP        dword ptr [ESI + 0x10c8],EAX
    //         004328ff     JC         LAB_00432938
    //                              com_spd.cpp:187 (6)
    //         00432901     MOV        EAX,dword ptr [ECX + this->AdjustmentCount]
    //                              com_spd.cpp:204 (37)
    //         00432907     MOV        dword ptr [ECX + this->NextLatencyChangeTurn],
    //         0043290d     INC        EAX
    //         0043290e     MOV        dword ptr [ECX + this->AdjustmentCount],EAX
    //         00432914     MOV        EAX,dword ptr [ECX + this->FutureBufferFrames]
    //         0043291a     MOV        dword ptr [ECX + this->CurrentBufferFrames],EAX
    //         00432920     MOV        EAX,dword ptr [ECX + this->FutureBufferGranula
    //         00432926     MOV        dword ptr [ECX + this->CurrentBufferGranularit
    //                              com_spd.cpp:205 (6)
    //         0043292c     MOV        dword ptr [ECX + this->FutureBufferFrames],EDX
    //                              com_spd.cpp:206 (6)
    //         00432932     MOV        dword ptr [ECX + this->FutureBufferGranularity
    //                               LAB_00432938                                                 XREF[2]:     004328eb(j), 004328ff(j)  
    //                              com_spd.cpp:207 (2)
    //         00432938     POP        ESI
    //         00432939     RET
    //         0043293a     ??         90h
    //         0043293b     NOP
    //         0043293c     NOP
    //         0043293d     NOP
    //         0043293e     NOP
    //         0043293f     NOP
    return;
}

void RGE_Communications_Speed::ReloadBufferFrames() {
    /* TODO: Stub */
    //                              void __thiscall ReloadBufferFrames(RGE_Communications_Speed * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?ReloadBufferFrames@RGE_Communications_Speed@@QAEXXZ         XREF[1]:     DoCycle:00426cb0(c)  
    //                               RGE_Communications_Speed::ReloadBufferFrames
    //                              com_spd.cpp:210 (3)
    //         00432940     PUSH       ESI
    //         00432941     MOV        ESI,this
    //                              com_spd.cpp:212 (11)
    //         00432943     MOV        this,dword ptr [ESI + 0x100]
    //         00432949     CALL       RGE_TimeSinceLastCall::Set                       ulong Set(RGE_TimeSinceLastCall * this)
    //                              com_spd.cpp:218 (17)
    //         0043294e     MOV        this,ESI
    //         00432950     MOV        dword ptr [ESI + 0x234],0x0
    //         0043295a     CALL       RGE_Communications_Speed::AdjustLocalSpeed       void AdjustLocalSpeed(RGE_Communications_Spee
    //                              com_spd.cpp:221 (12)
    //         0043295f     MOV        EAX,dword ptr [ESI + 0x11c]
    //         00432965     MOV        dword ptr [ESI + 0x124],EAX
    //                              com_spd.cpp:225 (2)
    //         0043296b     POP        ESI
    //         0043296c     RET
    //         0043296d     ??         90h
    //         0043296e     NOP
    //         0043296f     NOP
    return;
}

uint RGE_Communications_Speed::BufferTimeToUse(ulong param_1) {
    /* TODO: Stub */
    //                              uint __thiscall BufferTimeToUse(RGE_Communications_Speed * this, ulo
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00432a1a(R)  
    //                               ?BufferTimeToUse@RGE_Communications_Speed@@QAEIK@Z           XREF[1]:     DoCycle:004268e4(c)  
    //                               RGE_Communications_Speed::BufferTimeToUse
    //                              com_spd.cpp:228 (5)
    //         00432970     PUSH       EBX
    //         00432971     PUSH       EBP
    //         00432972     PUSH       ESI
    //         00432973     MOV        ESI,this
    //                              com_spd.cpp:229 (6)
    //         00432975     MOV        EAX,dword ptr [ESI + 0x23c]
    //                              com_spd.cpp:230 (15)
    //         0043297b     MOV        this,dword ptr [ESI + 0x104]
    //         00432981     TEST       EAX,EAX
    //         00432983     JZ         LAB_0043298c
    //         00432985     CALL       RGE_TimeSinceLastCall::Set                       ulong Set(RGE_TimeSinceLastCall * this)
    //                              com_spd.cpp:231 (2)
    //         0043298a     JMP        LAB_00432991
    //                               LAB_0043298c                                                 XREF[1]:     00432983(j)  
    //                              com_spd.cpp:232 (5)
    //         0043298c     CALL       RGE_TimeSinceLastCall::Skip                      void Skip(RGE_TimeSinceLastCall * this)
    //                               LAB_00432991                                                 XREF[1]:     0043298a(j)  
    //                              com_spd.cpp:237 (20)
    //         00432991     MOV        EAX,dword ptr [ESI + 0x124]
    //         00432997     MOV        dword ptr [ESI + 0x23c],0x0
    //         004329a1     TEST       EAX,EAX
    //         004329a3     JA         LAB_004329b7
    //                              com_spd.cpp:239 (10)
    //         004329a5     MOV        dword ptr [ESI + 0x23c],0x0
    //                              com_spd.cpp:240 (2)
    //         004329af     XOR        EAX,EAX
    //                              com_spd.cpp:282 (6)
    //         004329b1     POP        ESI
    //         004329b2     POP        EBP
    //         004329b3     POP        EBX
    //         004329b4     RET        0x4
    //                               LAB_004329b7                                                 XREF[1]:     004329a3(j)  
    //                              com_spd.cpp:245 (11)
    //         004329b7     MOV        this,dword ptr [ESI + 0x100]
    //         004329bd     CALL       RGE_TimeSinceLastCall::Get                       ulong Get(RGE_TimeSinceLastCall * this)
    //                              com_spd.cpp:249 (21)
    //         004329c2     MOV        this,dword ptr [ESI + 0x108]
    //         004329c8     MOV        dword ptr [ESI + 0x228],EAX
    //         004329ce     CALL       TCommunications_Handler::AllPlayersAcknowledged  int AllPlayersAcknowledged(TCommunications_Ha
    //         004329d3     TEST       EAX,EAX
    //         004329d5     JZ         LAB_004329eb
    //                              com_spd.cpp:251 (20)
    //         004329d7     MOV        EAX,dword ptr [ESI + 0x124]
    //         004329dd     MOV        this,dword ptr [ESI + 0x220]
    //         004329e3     ADD        this,EAX
    //         004329e5     MOV        dword ptr [ESI + 0x220],this
    //                               LAB_004329eb                                                 XREF[1]:     004329d5(j)  
    //                              com_spd.cpp:256 (20)
    //         004329eb     MOV        EDX,dword ptr [ESI + 0x124]
    //         004329f1     MOV        this,dword ptr [ESI + 0x11c]
    //         004329f7     MOV        EAX,dword ptr [ESI + 0x12c]
    //         004329fd     SUB        this,EDX
    //                              com_spd.cpp:262 (27)
    //         004329ff     MOV        EBX,dword ptr [ESI + 0x134]
    //         00432a05     MOV        EBP,dword ptr [ESI + 0x228]
    //         00432a0b     IMUL       this,EAX
    //         00432a0e     ADD        EBX,EBP
    //         00432a10     MOV        dword ptr [ESI + 0x22c],this
    //         00432a16     CMP        EBX,this
    //         00432a18     JNC        LAB_00432a4d
    //                              com_spd.cpp:264 (7)
    //         00432a1a     CMP        dword ptr [ESP + param_1],0x6
    //         00432a1f     JBE        LAB_00432a3b
    //                              com_spd.cpp:266 (6)
    //         00432a21     MOV        this,dword ptr [ESI + 0x230]
    //                              com_spd.cpp:267 (20)
    //         00432a27     MOV        EAX,dword ptr [ESI + 0x234]
    //         00432a2d     INC        this
    //         00432a2e     INC        EAX
    //         00432a2f     MOV        dword ptr [ESI + 0x230],this
    //         00432a35     MOV        dword ptr [ESI + 0x234],EAX
    //                               LAB_00432a3b                                                 XREF[1]:     00432a1f(j)  
    //                              com_spd.cpp:269 (10)
    //         00432a3b     MOV        dword ptr [ESI + 0x23c],0x0
    //                              com_spd.cpp:270 (2)
    //         00432a45     XOR        EAX,EAX
    //                              com_spd.cpp:282 (6)
    //         00432a47     POP        ESI
    //         00432a48     POP        EBP
    //         00432a49     POP        EBX
    //         00432a4a     RET        0x4
    //                               LAB_00432a4d                                                 XREF[1]:     00432a18(j)  
    //                              com_spd.cpp:274 (1)
    //         00432a4d     DEC        EDX
    //                              com_spd.cpp:280 (16)
    //         00432a4e     MOV        dword ptr [ESI + 0x23c],0x1
    //         00432a58     MOV        dword ptr [ESI + 0x124],EDX
    //                              com_spd.cpp:282 (6)
    //         00432a5e     POP        ESI
    //         00432a5f     POP        EBP
    //         00432a60     POP        EBX
    //         00432a61     RET        0x4
    //         00432a64     ??         90h
    //         00432a65     NOP
    //         00432a66     NOP
    //         00432a67     NOP
    //         00432a68     NOP
    //         00432a69     NOP
    //         00432a6a     NOP
    //         00432a6b     NOP
    //         00432a6c     NOP
    //         00432a6d     NOP
    //         00432a6e     NOP
    //         00432a6f     NOP
    return 0;
}

void RGE_Communications_Speed::Skip() {
    /* TODO: Stub */
    //                              void __thiscall Skip(RGE_Communications_Speed * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?Skip@RGE_Communications_Speed@@QAEXXZ                       XREF[1]:     DoCycle:00426c83(c)  
    //                               RGE_Communications_Speed::Skip
    //                              com_spd.cpp:285 (3)
    //         00432a70     PUSH       ESI
    //         00432a71     MOV        ESI,this
    //                              com_spd.cpp:287 (11)
    //         00432a73     MOV        this,dword ptr [ESI + 0x104]
    //         00432a79     CALL       RGE_TimeSinceLastCall::Skip                      void Skip(RGE_TimeSinceLastCall * this)
    //                              com_spd.cpp:288 (10)
    //         00432a7e     MOV        dword ptr [ESI + 0x23c],0x0
    //                              com_spd.cpp:289 (2)
    //         00432a88     POP        ESI
    //         00432a89     RET
    //         00432a8a     ??         90h
    //         00432a8b     NOP
    //         00432a8c     NOP
    //         00432a8d     NOP
    //         00432a8e     NOP
    //         00432a8f     NOP
    return;
}

uchar RGE_Communications_Speed::GetHighLatencyCenti() {
    /* TODO: Stub */
    //                              uchar __thiscall GetHighLatencyCenti(RGE_Communications_Speed * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetHighLatencyCenti@RGE_Communications_Speed@@QAEEXZ        XREF[4]:     DoCycle:004267da(c), 
    //                               RGE_Communications_Speed::GetHighLatencyCenti                             PreprocessMessages:00427aec(c), 
    //                                                                                                         PreprocessMessages:00427df0(c), 
    //                                                                                                         SendIResignMsg:00429ae8(c)  
    //                              com_spd.cpp:293 (6)
    //         00432a90     PUSH       EBX
    //         00432a91     PUSH       EBP
    //         00432a92     MOV        EBP,this
    //         00432a94     PUSH       ESI
    //         00432a95     PUSH       EDI
    //                              com_spd.cpp:294 (2)
    //         00432a96     XOR        EBX,EBX
    //                              com_spd.cpp:297 (11)
    //         00432a98     MOV        ESI,0x1
    //         00432a9d     LEA        EDI,[EBP + 0x148]
    //                               LAB_00432aa3                                                 XREF[1]:     00432ac2(j)  
    //                              com_spd.cpp:298 (16)
    //         00432aa3     MOV        this,dword ptr [EBP + 0x108]
    //         00432aa9     PUSH       ESI
    //         00432aaa     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
    //         00432aaf     TEST       EAX,EAX
    //         00432ab1     JZ         LAB_00432abb
    //                              com_spd.cpp:300 (8)
    //         00432ab3     MOV        EAX,dword ptr [EDI]
    //         00432ab5     CMP        EBX,EAX
    //         00432ab7     JA         LAB_00432abb
    //         00432ab9     MOV        EBX,EAX
    //                               LAB_00432abb                                                 XREF[2]:     00432ab1(j), 00432ab7(j)  
    //                              com_spd.cpp:297 (9)
    //         00432abb     INC        ESI
    //         00432abc     ADD        EDI,0x4
    //         00432abf     CMP        ESI,0x9
    //         00432ac2     JBE        LAB_00432aa3
    //                              com_spd.cpp:303 (6)
    //         00432ac4     MOV        dword ptr [EBP + 0x20c],EBX
    //                              com_spd.cpp:305 (15)
    //         00432aca     ADD        EBX,0x5
    //         00432acd     MOV        EAX,0xcccccccd
    //         00432ad2     MUL        EBX
    //         00432ad4     MOV        EAX,EDX
    //         00432ad6     SHR        EAX,0x3
    //                              com_spd.cpp:307 (10)
    //         00432ad9     CMP        EAX,0x1
    //         00432adc     JA         LAB_00432ae3
    //         00432ade     MOV        EAX,0x1
    //                               LAB_00432ae3                                                 XREF[1]:     00432adc(j)  
    //                              com_spd.cpp:308 (12)
    //         00432ae3     CMP        EAX,0xff
    //         00432ae8     JC         LAB_00432aef
    //         00432aea     MOV        EAX,0xff
    //                               LAB_00432aef                                                 XREF[1]:     00432ae8(j)  
    //                              com_spd.cpp:316 (5)
    //         00432aef     POP        EDI
    //         00432af0     POP        ESI
    //         00432af1     POP        EBP
    //         00432af2     POP        EBX
    //         00432af3     RET
    //         00432af4     ??         90h
    //         00432af5     NOP
    //         00432af6     NOP
    //         00432af7     NOP
    //         00432af8     NOP
    //         00432af9     NOP
    //         00432afa     NOP
    //         00432afb     NOP
    //         00432afc     NOP
    //         00432afd     NOP
    //         00432afe     NOP
    //         00432aff     NOP
    return 0;
}

ulong RGE_Communications_Speed::GetPlayerLatency(uint param_1) {
    /* TODO: Stub */
    //                              ulong __thiscall GetPlayerLatency(RGE_Communications_Speed * this, u
    //              ulong             EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00432b00(R)  
    //                               ?GetPlayerLatency@RGE_Communications_Speed@@QAEKI@Z          XREF[1]:     reset_score_display:0049b481(c)  
    //                               RGE_Communications_Speed::GetPlayerLatency
    //                              com_spd.cpp:320 (14)
    //         00432b00     MOV        EAX,dword ptr [ESP + param_1]
    //         00432b04     CMP        EAX,0x1
    //         00432b07     JC         LAB_00432b18
    //         00432b09     CMP        EAX,0x9
    //         00432b0c     JA         LAB_00432b18
    //                              com_spd.cpp:324 (7)
    //         00432b0e     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->ActualLat
    //                              com_spd.cpp:325 (3)
    //         00432b15     RET        0x4
    //                               LAB_00432b18                                                 XREF[2]:     00432b07(j), 00432b0c(j)  
    //                              com_spd.cpp:322 (2)
    //         00432b18     XOR        EAX,EAX
    //                              com_spd.cpp:325 (3)
    //         00432b1a     RET        0x4
    //         00432b1d     ??         90h
    //         00432b1e     NOP
    //         00432b1f     NOP
    return 0;
}

char* RGE_Communications_Speed::GetLatencyInfo() {
    /* TODO: Stub */
    //                              char * __thiscall GetLatencyInfo(RGE_Communications_Speed * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              char[24]          Stack[-0x1c]   buf                       XREF[4,2]:   00432b39(W), 00432b5c(R), 00432b98(R), 00432bbb(R), 
    //                                                                                     00432b73(*), 00432b84(*)  
    //                               ?GetLatencyInfo@RGE_Communications_Speed@@QAEPADXZ           XREF[1]:     GetCommInfo:0042ce9e(c)  
    //                               RGE_Communications_Speed::GetLatencyInfo
    //                              com_spd.cpp:328 (9)
    //         00432b20     SUB        ESP,0x1c
    //         00432b23     PUSH       EBX
    //         00432b24     PUSH       EBP
    //         00432b25     PUSH       ESI
    //         00432b26     MOV        EDX,this
    //         00432b28     PUSH       EDI
    //                              com_spd.cpp:331 (26)
    //         00432b29     MOV        EDI,s_Latency>_                                  = 4Ch
    //         00432b2e     OR         this,0xffffffff
    //         00432b31     XOR        EAX,EAX
    //         00432b33     SCASB.RE   ES:EDI=>s_Latency>_                              = 4Ch
    //                                                                                  = "atency> "
    //         00432b35     NOT        this
    //         00432b37     SUB        EDI,this
    //         00432b39     MOV        dword ptr [ESP + buf[0]],EDX
    //         00432b3d     MOV        EAX,this
    //         00432b3f     MOV        ESI,EDI
    //         00432b41     MOV        EDI,EDX
    //                              com_spd.cpp:333 (25)
    //         00432b43     MOV        EBX,0x1
    //         00432b48     SHR        this,0x2
    //         00432b4b     MOVSD.REP  ES:EDI,ESI
    //         00432b4d     MOV        this,EAX
    //         00432b4f     LEA        EBP,[EDX + 0x148]
    //         00432b55     AND        this,0x3
    //         00432b58     MOVSB.REP  ES:EDI,ESI
    //         00432b5a     JMP        LAB_00432b60
    //                               LAB_00432b5c                                                 XREF[1]:     00432bb9(j)  
    //                              com_spd.cpp:331 (4)
    //         00432b5c     MOV        EDX,dword ptr [ESP + buf[0]]
    //                               LAB_00432b60                                                 XREF[1]:     00432b5a(j)  
    //                              com_spd.cpp:334 (16)
    //         00432b60     MOV        this,dword ptr [EDX + 0x108]
    //         00432b66     PUSH       EBX
    //         00432b67     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
    //         00432b6c     TEST       EAX,EAX
    //         00432b6e     JZ         LAB_00432bb2
    //                              com_spd.cpp:338 (20)
    //         00432b70     MOV        this,dword ptr [EBP]
    //         00432b73     LEA        EDX=>buf[4],[ESP + 0x14]
    //         00432b77     PUSH       this
    //         00432b78     PUSH       EBX
    //         00432b79     PUSH       s_P%d=%d_                                        = "P%d=%d "
    //         00432b7e     PUSH       EDX
    //         00432b7f     CALL       sprintf                                          undefined sprintf()
    //                              com_spd.cpp:339 (55)
    //         00432b84     LEA        EDI=>buf[4],[ESP + 0x24]
    //         00432b88     OR         this,0xffffffff
    //         00432b8b     XOR        EAX,EAX
    //         00432b8d     ADD        ESP,0x10
    //         00432b90     SCASB.RE   ES:EDI
    //         00432b92     NOT        this
    //         00432b94     SUB        EDI,this
    //         00432b96     MOV        ESI,EDI
    //         00432b98     MOV        EDI,dword ptr [ESP + buf[0]]
    //         00432b9c     MOV        EDX,this
    //         00432b9e     OR         this,0xffffffff
    //         00432ba1     SCASB.RE   ES:EDI
    //         00432ba3     MOV        this,EDX
    //         00432ba5     DEC        EDI
    //         00432ba6     SHR        this,0x2
    //         00432ba9     MOVSD.REP  ES:EDI,ESI
    //         00432bab     MOV        this,EDX
    //         00432bad     AND        this,0x3
    //         00432bb0     MOVSB.REP  ES:EDI,ESI
    //                               LAB_00432bb2                                                 XREF[1]:     00432b6e(j)  
    //         00432bb2     INC        EBX
    //         00432bb3     ADD        EBP,0x4
    //         00432bb6     CMP        EBX,0x9
    //         00432bb9     JBE        LAB_00432b5c
    //                              com_spd.cpp:342 (4)
    //         00432bbb     MOV        EAX,dword ptr [ESP + buf[0]]
    //                              com_spd.cpp:343 (8)
    //         00432bbf     POP        EDI
    //         00432bc0     POP        ESI
    //         00432bc1     POP        EBP
    //         00432bc2     POP        EBX
    //         00432bc3     ADD        ESP,0x1c
    //         00432bc6     RET
    //         00432bc7     ??         90h
    //         00432bc8     NOP
    //         00432bc9     NOP
    //         00432bca     NOP
    //         00432bcb     NOP
    //         00432bcc     NOP
    //         00432bcd     NOP
    //         00432bce     NOP
    //         00432bcf     NOP
    return 0;
}

char* RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr() {
    /* TODO: Stub */
    //                              char * __thiscall GetSelfPlayerOptimalSpeedStr(RGE_Communications_Sp
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetSelfPlayerOptimalSpeedStr@RGE_Communications_Speed@@QAE  XREF[1]:     GetCommInfo:0042cf06(c)  
    //                               RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr
    //                              com_spd.cpp:346 (4)
    //         00432bd0     PUSH       ESI
    //         00432bd1     PUSH       EDI
    //         00432bd2     MOV        ESI,this
    //                              com_spd.cpp:349 (5)
    //         00432bd4     CALL       RGE_Communications_Speed::GetRecommendedBuffer   uint GetRecommendedBufferFrames(RGE_Communica
    //                              com_spd.cpp:350 (11)
    //         00432bd9     MOV        this,ESI
    //         00432bdb     MOV        EDI,EAX
    //         00432bdd     CALL       RGE_Communications_Speed::GetRecommendedBuffer   uint GetRecommendedBufferGranularity(RGE_Comm
    //         00432be2     MOV        this,EAX
    //                              com_spd.cpp:353 (33)
    //         00432be4     IMUL       EAX,EDI
    //         00432be7     PUSH       EAX
    //         00432be8     MOV        EAX,0x3e8
    //         00432bed     CDQ
    //         00432bee     IDIV       this
    //         00432bf0     PUSH       EAX
    //         00432bf1     PUSH       this
    //         00432bf2     PUSH       EDI
    //         00432bf3     PUSH       s_MeOptimal:_Buf=%3d_Gran=%3d__Tar               = "MeOptimal: Buf=%3d Gran=%3d  Target FPS=%3
    //         00432bf8     PUSH       null_0062d170                                    = align(152)
    //         00432bfd     CALL       sprintf                                          undefined sprintf()
    //         00432c02     ADD        ESP,0x18
    //                              com_spd.cpp:354 (5)
    //         00432c05     MOV        EAX,null_0062d170                                = align(152)
    //                              com_spd.cpp:355 (3)
    //         00432c0a     POP        EDI
    //         00432c0b     POP        ESI
    //         00432c0c     RET
    //         00432c0d     ??         90h
    //         00432c0e     NOP
    //         00432c0f     NOP
    return 0;
}

char* RGE_Communications_Speed::GetPlayerSpeedStatusStr(int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall GetPlayerSpeedStatusStr(RGE_Communications_Speed *
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00432c10(R)  
    //                               ?GetPlayerSpeedStatusStr@RGE_Communications_Speed@@QAEPADH@Z XREF[1]:     GetCommInfo:0042cf25(c)  
    //                               RGE_Communications_Speed::GetPlayerSpeedStatusStr
    //                              com_spd.cpp:358 (18)
    //         00432c10     MOV        EAX,dword ptr [ESP + param_1]
    //         00432c14     PUSH       EBX
    //         00432c15     PUSH       ESI
    //         00432c16     PUSH       EDI
    //         00432c17     TEST       EAX,EAX
    //         00432c19     MOV        ESI,this
    //         00432c1b     JL         LAB_00432c68
    //         00432c1d     CMP        EAX,0x9
    //         00432c20     JG         LAB_00432c68
    //                              com_spd.cpp:371 (59)
    //         00432c22     MOV        this,dword ptr [ESI + 0x104]
    //         00432c28     MOV        EDI,dword ptr [ESI + 0x12c]
    //         00432c2e     MOV        EBX,dword ptr [ESI + 0x11c]
    //         00432c34     PUSH       0x32
    //         00432c36     CALL       RGE_TimeSinceLastCall::GetHiLoInfo               char * GetHiLoInfo(RGE_TimeSinceLastCall * th
    //         00432c3b     PUSH       EAX
    //         00432c3c     MOV        EAX,EBX
    //         00432c3e     IMUL       EAX,EDI
    //         00432c41     MOV        this,dword ptr [ESI + 0x124]
    //         00432c47     PUSH       EAX
    //         00432c48     PUSH       EDI
    //         00432c49     PUSH       EBX
    //         00432c4a     PUSH       this
    //         00432c4b     PUSH       s_Buf=%3d_/_%3d_*_Gran=%3dms_=_tur               = "Buf=%3d / %3d * Gran=%3dms = turn %4dms   
    //         00432c50     PUSH       DAT_0062cf70                                     = align(256)
    //         00432c55     CALL       sprintf                                          undefined sprintf()
    //         00432c5a     ADD        ESP,0x1c
    //                              com_spd.cpp:373 (5)
    //         00432c5d     MOV        EAX,DAT_0062cf70                                 = align(256)
    //                              com_spd.cpp:374 (14)
    //         00432c62     POP        EDI
    //         00432c63     POP        ESI
    //         00432c64     POP        EBX
    //         00432c65     RET        0x4
    //                               LAB_00432c68                                                 XREF[2]:     00432c1b(j), 00432c20(j)  
    //         00432c68     POP        EDI
    //         00432c69     POP        ESI
    //         00432c6a     XOR        EAX,EAX
    //         00432c6c     POP        EBX
    //         00432c6d     RET        0x4
    return 0;
}

char* RGE_Communications_Speed::GetMachineSpeedInfo() {
    /* TODO: Stub */
    //                              char * __thiscall GetMachineSpeedInfo(RGE_Communications_Speed * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              char[24]          Stack[-0x1c]   buf                       XREF[2,2]:   00432c89(W), 00432caf(R), 00432ccc(*), 00432cdb(*)  
    //                               ?GetMachineSpeedInfo@RGE_Communications_Speed@@QAEPADXZ      XREF[1]:     GetCommInfo:0042cec8(c)  
    //                               RGE_Communications_Speed::GetMachineSpeedInfo
    //                              com_spd.cpp:377 (9)
    //         00432c70     SUB        ESP,0x1c
    //         00432c73     PUSH       EBX
    //         00432c74     PUSH       EBP
    //         00432c75     PUSH       ESI
    //         00432c76     MOV        EDX,this
    //         00432c78     PUSH       EDI
    //                              com_spd.cpp:381 (29)
    //         00432c79     MOV        EDI,s_PlrSpeed>_                                 = 50h    P
    //         00432c7e     OR         this,0xffffffff
    //         00432c81     XOR        EAX,EAX
    //         00432c83     SCASB.RE   ES:EDI=>s_PlrSpeed>_                             = 50h    P
    //                                                                                  = "lrSpeed> "
    //         00432c85     NOT        this
    //         00432c87     SUB        EDI,this
    //         00432c89     MOV        dword ptr [ESP + buf[0]],EDX
    //         00432c8d     MOV        EAX,this
    //         00432c8f     MOV        ESI,EDI
    //         00432c91     MOV        EDI,DAT_0062d070
    //                              com_spd.cpp:383 (25)
    //         00432c96     MOV        EBX,0x1
    //         00432c9b     SHR        this,0x2
    //         00432c9e     MOVSD.REP  ES:EDI=>DAT_0062d070,ESI
    //         00432ca0     MOV        this,EAX
    //         00432ca2     LEA        EBP,[EDX + 0x1c0]
    //         00432ca8     AND        this,0x3
    //         00432cab     MOVSB.REP  ES:EDI=>DAT_0062d074,ESI
    //         00432cad     JMP        LAB_00432cb3
    //                               LAB_00432caf                                                 XREF[1]:     00432d11(j)  
    //                              com_spd.cpp:381 (4)
    //         00432caf     MOV        EDX,dword ptr [ESP + buf[0]]
    //                               LAB_00432cb3                                                 XREF[1]:     00432cad(j)  
    //                              com_spd.cpp:384 (16)
    //         00432cb3     MOV        this,dword ptr [EDX + 0x108]
    //         00432cb9     PUSH       EBX
    //         00432cba     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
    //         00432cbf     TEST       EAX,EAX
    //         00432cc1     JZ         LAB_00432d0a
    //                              com_spd.cpp:390 (24)
    //         00432cc3     MOV        this,dword ptr [EBP + 0x28]
    //         00432cc6     MOV        EDX,dword ptr [EBP]
    //         00432cc9     PUSH       this
    //         00432cca     PUSH       EDX
    //         00432ccb     PUSH       EBX
    //         00432ccc     LEA        EAX=>buf[4],[ESP + 0x20]
    //         00432cd0     PUSH       s_P#%1d(fr%d_lat%d)_                             = "P#%1d(fr%d lat%d) "
    //         00432cd5     PUSH       EAX
    //         00432cd6     CALL       sprintf                                          undefined sprintf()
    //                              com_spd.cpp:391 (56)
    //         00432cdb     LEA        EDI=>buf[4],[ESP + 0x28]
    //         00432cdf     OR         this,0xffffffff
    //         00432ce2     XOR        EAX,EAX
    //         00432ce4     ADD        ESP,0x14
    //         00432ce7     SCASB.RE   ES:EDI
    //         00432ce9     NOT        this
    //         00432ceb     SUB        EDI,this
    //         00432ced     MOV        ESI,EDI
    //         00432cef     MOV        EDX,this
    //         00432cf1     MOV        EDI,DAT_0062d070
    //         00432cf6     OR         this,0xffffffff
    //         00432cf9     SCASB.RE   ES:EDI=>DAT_0062d070
    //         00432cfb     MOV        this,EDX
    //         00432cfd     DEC        EDI
    //         00432cfe     SHR        this,0x2
    //         00432d01     MOVSD.REP  ES:EDI=>DAT_0062d070,ESI
    //         00432d03     MOV        this,EDX
    //         00432d05     AND        this,0x3
    //         00432d08     MOVSB.REP  ES:EDI=>DAT_0062d074,ESI
    //                               LAB_00432d0a                                                 XREF[1]:     00432cc1(j)  
    //         00432d0a     INC        EBX
    //         00432d0b     ADD        EBP,0x4
    //         00432d0e     CMP        EBX,0x9
    //         00432d11     JLE        LAB_00432caf
    //                              com_spd.cpp:395 (13)
    //         00432d13     POP        EDI
    //         00432d14     POP        ESI
    //         00432d15     POP        EBP
    //         00432d16     MOV        EAX,DAT_0062d070
    //         00432d1b     POP        EBX
    //         00432d1c     ADD        ESP,0x1c
    //         00432d1f     RET
    return 0;
}

uint RGE_Communications_Speed::GetRecommendedBufferFrames() {
    /* TODO: Stub */
    //                              uint __thiscall GetRecommendedBufferFrames(RGE_Communications_Speed 
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetRecommendedBufferFrames@RGE_Communications_Speed@@QAEIXZ XREF[1]:     GetSelfPlayerOptimalSpeedStr:00432
    //                               RGE_Communications_Speed::GetRecommendedBufferFrames
    //                              com_spd.cpp:398 (6)
    //         00432d20     PUSH       EBX
    //         00432d21     PUSH       EBP
    //         00432d22     MOV        EBP,this
    //         00432d24     PUSH       ESI
    //         00432d25     PUSH       EDI
    //                              com_spd.cpp:402 (2)
    //         00432d26     XOR        EBX,EBX
    //                              com_spd.cpp:404 (11)
    //         00432d28     MOV        ESI,0x1
    //         00432d2d     LEA        EDI,[EBP + 0x148]
    //                               LAB_00432d33                                                 XREF[1]:     00432d52(j)  
    //                              com_spd.cpp:406 (16)
    //         00432d33     MOV        this,dword ptr [EBP + 0x108]
    //         00432d39     PUSH       ESI
    //         00432d3a     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
    //         00432d3f     TEST       EAX,EAX
    //         00432d41     JZ         LAB_00432d4b
    //                              com_spd.cpp:407 (8)
    //         00432d43     MOV        EAX,dword ptr [EDI]
    //         00432d45     CMP        EBX,EAX
    //         00432d47     JA         LAB_00432d4b
    //         00432d49     MOV        EBX,EAX
    //                               LAB_00432d4b                                                 XREF[2]:     00432d41(j), 00432d47(j)  
    //                              com_spd.cpp:404 (9)
    //         00432d4b     INC        ESI
    //         00432d4c     ADD        EDI,0x4
    //         00432d4f     CMP        ESI,0x9
    //         00432d52     JLE        LAB_00432d33
    //                              com_spd.cpp:410 (10)
    //         00432d54     MOV        EAX,EBX
    //         00432d56     XOR        EDX,EDX
    //         00432d58     DIV        dword ptr [EBP + 0x12c]
    //                              com_spd.cpp:415 (16)
    //         00432d5e     CMP        EAX,0x14
    //         00432d61     MOV        dword ptr [EBP + 0x214],EAX
    //         00432d67     JC         LAB_00432d6e
    //         00432d69     MOV        EAX,0x14
    //                               LAB_00432d6e                                                 XREF[1]:     00432d67(j)  
    //                              com_spd.cpp:416 (16)
    //         00432d6e     CMP        EAX,0x4
    //         00432d71     MOV        dword ptr [EBP + 0x214],EAX
    //         00432d77     JA         LAB_00432d7e
    //         00432d79     MOV        EAX,0x4
    //                               LAB_00432d7e                                                 XREF[1]:     00432d77(j)  
    //                              com_spd.cpp:419 (1)
    //         00432d7e     INC        EAX
    //                              com_spd.cpp:422 (11)
    //         00432d7f     POP        EDI
    //         00432d80     MOV        dword ptr [EBP + 0x214],EAX
    //         00432d86     POP        ESI
    //         00432d87     POP        EBP
    //         00432d88     POP        EBX
    //         00432d89     RET
    //         00432d8a     ??         90h
    //         00432d8b     NOP
    //         00432d8c     NOP
    //         00432d8d     NOP
    //         00432d8e     NOP
    //         00432d8f     NOP
    return 0;
}

uint RGE_Communications_Speed::GetAvgFrameRate() {
    /* TODO: Stub */
    //                              uint __thiscall GetAvgFrameRate(RGE_Communications_Speed * this)
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetAvgFrameRate@RGE_Communications_Speed@@QAEIXZ            XREF[4]:     DoCycle:004267e9(c), 
    //                               RGE_Communications_Speed::GetAvgFrameRate                                 PreprocessMessages:00427afb(c), 
    //                                                                                                         PreprocessMessages:00427dff(c), 
    //                                                                                                         SendIResignMsg:00429af7(c)  
    //                              com_spd.cpp:425 (13)
    //         00432d90     MOV        this,dword ptr [ECX + this->FrameTSLC]
    //         00432d96     PUSH       0x32
    //         00432d98     CALL       RGE_TimeSinceLastCall::GetAvg                    ulong GetAvg(RGE_TimeSinceLastCall * this, in
    //                              com_spd.cpp:427 (1)
    //         00432d9d     RET
    //         00432d9e     ??         90h
    //         00432d9f     NOP
    return 0;
}

uint RGE_Communications_Speed::GetRecommendedBufferGranularity() {
    /* TODO: Stub */
    //                              uint __thiscall GetRecommendedBufferGranularity(RGE_Communications_S
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetRecommendedBufferGranularity@RGE_Communications_Speed@@  XREF[1]:     GetSelfPlayerOptimalSpeedStr:00432
    //                               RGE_Communications_Speed::GetRecommendedBufferGranularity
    //                              com_spd.cpp:431 (3)
    //         00432da0     PUSH       ESI
    //         00432da1     MOV        ESI,this
    //                              com_spd.cpp:439 (13)
    //         00432da3     PUSH       0x32
    //         00432da5     MOV        this,dword ptr [ESI + 0x104]
    //         00432dab     CALL       RGE_TimeSinceLastCall::GetAvg                    ulong GetAvg(RGE_TimeSinceLastCall * this, in
    //                              com_spd.cpp:442 (18)
    //         00432db0     CMP        EAX,0x96
    //         00432db5     MOV        dword ptr [ESI + 0x218],EAX
    //         00432dbb     JBE        LAB_00432dc2
    //         00432dbd     MOV        EAX,0x96
    //                               LAB_00432dc2                                                 XREF[1]:     00432dbb(j)  
    //                              com_spd.cpp:445 (22)
    //         00432dc2     CMP        EAX,0xa
    //         00432dc5     MOV        dword ptr [ESI + 0x218],EAX
    //         00432dcb     JNC        LAB_00432dd2
    //         00432dcd     MOV        EAX,0xa
    //                               LAB_00432dd2                                                 XREF[1]:     00432dcb(j)  
    //         00432dd2     MOV        dword ptr [ESI + 0x218],EAX
    //                              com_spd.cpp:448 (2)
    //         00432dd8     POP        ESI
    //         00432dd9     RET
    //         00432dda     ??         90h
    //         00432ddb     NOP
    //         00432ddc     NOP
    //         00432ddd     NOP
    //         00432dde     NOP
    //         00432ddf     NOP
    return 0;
}

int RGE_Communications_Speed::AnalyzeGameSpeed(uint* param_1, uint* param_2, int param_3) {
    /* TODO: Stub */
    //                              int __thiscall AnalyzeGameSpeed(RGE_Communications_Speed * this, uin
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint *            Stack[0x4]:4   param_1                   XREF[1]:     00432f5b(R)  
    //              uint *            Stack[0x8]:4   param_2                   XREF[1]:     00432f5f(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00432f63(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00432e35(W), 00432f7d(R)  
    //              ulong             Stack[-0x8]:4  SyncTurn                  XREF[2]:     00432ed7(W), 00432f2d(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     00432de9(W), 00432e7c(R), 00432ec9(R), 00432f6f(R)  
    //                               ?AnalyzeGameSpeed@RGE_Communications_Speed@@QAEHPAI0H@Z      XREF[1]:     DoCycle:00426cd8(c)  
    //                               RGE_Communications_Speed::AnalyzeGameSpeed
    //                              com_spd.cpp:451 (13)
    //         00432de0     SUB        ESP,0xc
    //         00432de3     PUSH       EBX
    //         00432de4     PUSH       EBP
    //         00432de5     PUSH       ESI
    //         00432de6     MOV        ESI,this
    //         00432de8     PUSH       EDI
    //         00432de9     MOV        dword ptr [ESP + local_c],ESI
    //                              com_spd.cpp:453 (15)
    //         00432ded     MOV        this,dword ptr [ESI + 0x108]
    //         00432df3     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
    //         00432df8     TEST       EAX,EAX
    //         00432dfa     JNZ        LAB_00432e06
    //                              com_spd.cpp:577 (10)
    //         00432dfc     POP        EDI
    //         00432dfd     POP        ESI
    //         00432dfe     POP        EBP
    //         00432dff     POP        EBX
    //         00432e00     ADD        ESP,0xc
    //         00432e03     RET        0xc
    //                               LAB_00432e06                                                 XREF[1]:     00432dfa(j)  
    //                              com_spd.cpp:457 (10)
    //         00432e06     MOV        EAX,dword ptr [ESI + 0x140]
    //         00432e0c     TEST       EAX,EAX
    //         00432e0e     JZ         LAB_00432e1c
    //                              com_spd.cpp:458 (2)
    //         00432e10     XOR        EAX,EAX
    //                              com_spd.cpp:577 (10)
    //         00432e12     POP        EDI
    //         00432e13     POP        ESI
    //         00432e14     POP        EBP
    //         00432e15     POP        EBX
    //         00432e16     ADD        ESP,0xc
    //         00432e19     RET        0xc
    //                               LAB_00432e1c                                                 XREF[1]:     00432e0e(j)  
    //                              com_spd.cpp:461 (22)
    //         00432e1c     MOV        EAX,dword ptr [ESI + 0x108]
    //         00432e22     XOR        this,this
    //         00432e24     MOV        this,byte ptr [EAX + 0x1590]
    //         00432e2a     MOV        EAX,dword ptr [EAX + 0x10c8]
    //         00432e30     ADD        EAX,this
    //                              com_spd.cpp:463 (9)
    //         00432e32     CMP        EAX,0x14
    //         00432e35     MOV        dword ptr [ESP + local_4],EAX
    //         00432e39     JNC        LAB_00432e47
    //                              com_spd.cpp:464 (2)
    //         00432e3b     XOR        EAX,EAX
    //                              com_spd.cpp:577 (10)
    //         00432e3d     POP        EDI
    //         00432e3e     POP        ESI
    //         00432e3f     POP        EBP
    //         00432e40     POP        EBX
    //         00432e41     ADD        ESP,0xc
    //         00432e44     RET        0xc
    //                               LAB_00432e47                                                 XREF[1]:     00432e39(j)  
    //                              com_spd.cpp:467 (7)
    //         00432e47     MOV        this,dword ptr [ESI + 0x224]
    //         00432e4d     INC        this
    //                              com_spd.cpp:469 (13)
    //         00432e4e     MOV        EAX,this
    //         00432e50     MOV        dword ptr [ESI + 0x224],this
    //         00432e56     CMP        EAX,0x5
    //         00432e59     JNC        LAB_00432e67
    //                              com_spd.cpp:470 (2)
    //         00432e5b     XOR        EAX,EAX
    //                              com_spd.cpp:577 (10)
    //         00432e5d     POP        EDI
    //         00432e5e     POP        ESI
    //         00432e5f     POP        EBP
    //         00432e60     POP        EBX
    //         00432e61     ADD        ESP,0xc
    //         00432e64     RET        0xc
    //                               LAB_00432e67                                                 XREF[1]:     00432e59(j)  
    //                              com_spd.cpp:473 (5)
    //         00432e67     MOV        EBX,0xa
    //                              com_spd.cpp:474 (5)
    //         00432e6c     MOV        EBP,0x1e
    //                              com_spd.cpp:481 (5)
    //         00432e71     MOV        EDI,0x1
    //                              com_spd.cpp:577 (33)
    //         00432e76     ADD        ESI,0x1e8
    //                               LAB_00432e7c                                                 XREF[1]:     00432ea8(j)  
    //         00432e7c     MOV        EDX,dword ptr [ESP + local_c]
    //         00432e80     PUSH       EDI
    //         00432e81     MOV        this,dword ptr [EDX + 0x108]
    //         00432e87     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
    //         00432e8c     TEST       EAX,EAX
    //         00432e8e     JZ         LAB_00432ea1
    //         00432e90     MOV        EAX,dword ptr [ESI + -0x28]
    //         00432e93     CMP        EBX,EAX
    //         00432e95     JA         LAB_00432e99
    //                              com_spd.cpp:485 (2)
    //         00432e97     MOV        EBX,EAX
    //                               LAB_00432e99                                                 XREF[1]:     00432e95(j)  
    //                              com_spd.cpp:487 (8)
    //         00432e99     MOV        EAX,dword ptr [ESI]
    //         00432e9b     CMP        EBP,EAX
    //         00432e9d     JA         LAB_00432ea1
    //         00432e9f     MOV        EBP,EAX
    //                               LAB_00432ea1                                                 XREF[2]:     00432e8e(j), 00432e9d(j)  
    //                              com_spd.cpp:481 (9)
    //         00432ea1     INC        EDI
    //         00432ea2     ADD        ESI,0x4
    //         00432ea5     CMP        EDI,0x9
    //         00432ea8     JLE        LAB_00432e7c
    //                              com_spd.cpp:492 (18)
    //         00432eaa     ADD        EBX,0x5
    //         00432ead     MOV        EAX,0xcccccccd
    //         00432eb2     MUL        EBX
    //         00432eb4     SHR        EDX,0x3
    //         00432eb7     LEA        EDI,[EDX + EDX*0x4]
    //         00432eba     SHL        EDI,0x1
    //                              com_spd.cpp:495 (13)
    //         00432ebc     CMP        EDI,0x96
    //         00432ec2     JBE        LAB_00432ec9
    //         00432ec4     MOV        EDI,0x96
    //                               LAB_00432ec9                                                 XREF[1]:     00432ec2(j)  
    //                              com_spd.cpp:501 (28)
    //         00432ec9     MOV        EBX,dword ptr [ESP + local_c]
    //         00432ecd     MOV        EAX,EDI
    //         00432ecf     MOV        this,dword ptr [EBX + 0x12c]
    //         00432ed5     SUB        EAX,this
    //         00432ed7     MOV        dword ptr [ESP + SyncTurn],this
    //         00432edb     CDQ
    //         00432edc     XOR        EAX,EDX
    //         00432ede     SUB        EAX,EDX
    //         00432ee0     CMP        EAX,0xa
    //         00432ee3     JNC        LAB_00432ee7
    //                              com_spd.cpp:506 (2)
    //         00432ee5     MOV        EDI,this
    //                               LAB_00432ee7                                                 XREF[1]:     00432ee3(j)  
    //                              com_spd.cpp:513 (11)
    //         00432ee7     MOV        EAX,EBP
    //         00432ee9     XOR        EDX,EDX
    //         00432eeb     DIV        EDI
    //         00432eed     MOV        ESI,EAX
    //         00432eef     ADD        ESI,0x2
    //                              com_spd.cpp:516 (10)
    //         00432ef2     CMP        ESI,0x14
    //         00432ef5     JC         LAB_00432efc
    //         00432ef7     MOV        ESI,0x14
    //                               LAB_00432efc                                                 XREF[1]:     00432ef5(j)  
    //                              com_spd.cpp:519 (10)
    //         00432efc     CMP        ESI,0x4
    //         00432eff     JA         LAB_00432f06
    //         00432f01     MOV        ESI,0x4
    //                               LAB_00432f06                                                 XREF[1]:     00432eff(j)  
    //                              com_spd.cpp:522 (12)
    //         00432f06     MOV        EAX,EDI
    //         00432f08     IMUL       EAX,ESI
    //         00432f0b     CMP        EAX,0xfa
    //         00432f10     JNC        LAB_00432f1e
    //                              com_spd.cpp:523 (12)
    //         00432f12     MOV        EAX,0xfa
    //         00432f17     XOR        EDX,EDX
    //         00432f19     DIV        EDI
    //         00432f1b     MOV        ESI,EAX
    //         00432f1d     INC        ESI
    //                               LAB_00432f1e                                                 XREF[1]:     00432f10(j)  
    //                              com_spd.cpp:526 (13)
    //         00432f1e     MOV        EBP,dword ptr [EBX + 0x11c]
    //         00432f24     MOV        this,EDI
    //         00432f26     IMUL       this,ESI
    //         00432f29     MOV        EBX,EBP
    //                              com_spd.cpp:527 (14)
    //         00432f2b     MOV        EAX,this
    //         00432f2d     IMUL       EBX,dword ptr [ESP + SyncTurn]
    //         00432f32     SUB        EAX,EBX
    //         00432f34     CDQ
    //         00432f35     XOR        EAX,EDX
    //         00432f37     SUB        EAX,EDX
    //                              com_spd.cpp:536 (5)
    //         00432f39     CMP        EAX,0xa
    //         00432f3c     JA         LAB_00432f4a
    //                              com_spd.cpp:539 (2)
    //         00432f3e     XOR        EAX,EAX
    //                              com_spd.cpp:577 (10)
    //         00432f40     POP        EDI
    //         00432f41     POP        ESI
    //         00432f42     POP        EBP
    //         00432f43     POP        EBX
    //         00432f44     ADD        ESP,0xc
    //         00432f47     RET        0xc
    //                               LAB_00432f4a                                                 XREF[1]:     00432f3c(j)  
    //                              com_spd.cpp:543 (4)
    //         00432f4a     CMP        this,EBX
    //         00432f4c     JNC        LAB_00432f5b
    //                              com_spd.cpp:547 (5)
    //         00432f4e     CMP        EAX,0x64
    //         00432f51     JBE        LAB_00432f5b
    //                              com_spd.cpp:552 (5)
    //         00432f53     CMP        EBP,0x4
    //         00432f56     JBE        LAB_00432f5b
    //                              com_spd.cpp:553 (3)
    //         00432f58     LEA        ESI,[EBP + -0x1]
    //                               LAB_00432f5b                                                 XREF[3]:     00432f4c(j), 00432f51(j), 
    //                                                                                                         00432f56(j)  
    //                              com_spd.cpp:563 (4)
    //         00432f5b     MOV        this,dword ptr [ESP + param_1]
    //                              com_spd.cpp:564 (4)
    //         00432f5f     MOV        EDX,dword ptr [ESP + param_2]
    //                              com_spd.cpp:566 (26)
    //         00432f63     MOV        EAX,dword ptr [ESP + param_3]
    //         00432f67     MOV        dword ptr [this->TBuff[0]],EDI
    //         00432f69     MOV        dword ptr [EDX],ESI
    //         00432f6b     TEST       EAX,EAX
    //         00432f6d     JZ         LAB_00432f98
    //         00432f6f     MOV        EBX,dword ptr [ESP + local_c]
    //         00432f73     MOV        EAX,dword ptr [EBX + 0x118]
    //         00432f79     TEST       EAX,EAX
    //         00432f7b     JZ         LAB_00432f98
    //                              com_spd.cpp:572 (14)
    //         00432f7d     MOV        EAX,dword ptr [ESP + local_4]
    //         00432f81     MOV        this,EBX
    //         00432f83     PUSH       EAX
    //         00432f84     PUSH       EDI
    //         00432f85     PUSH       ESI
    //         00432f86     CALL       RGE_Communications_Speed::SetFutureSpeedChange   void SetFutureSpeedChange(RGE_Communications_
    //                              com_spd.cpp:573 (13)
    //         00432f8b     MOV        this,dword ptr [EBX + 0x108]
    //         00432f91     PUSH       EDI
    //         00432f92     PUSH       ESI
    //         00432f93     CALL       TCommunications_Handler::SendSpeedChange         void SendSpeedChange(TCommunications_Handler 
    //                               LAB_00432f98                                                 XREF[2]:     00432f6d(j), 00432f7b(j)  
    //                              com_spd.cpp:577 (15)
    //         00432f98     POP        EDI
    //         00432f99     POP        ESI
    //         00432f9a     POP        EBP
    //         00432f9b     MOV        EAX,0x1
    //         00432fa0     POP        EBX
    //         00432fa1     ADD        ESP,0xc
    //         00432fa4     RET        0xc
    //         00432fa7     ??         90h
    //         00432fa8     NOP
    //         00432fa9     NOP
    //         00432faa     NOP
    //         00432fab     NOP
    //         00432fac     NOP
    //         00432fad     NOP
    //         00432fae     NOP
    //         00432faf     NOP
    return 0;
}

void RGE_Communications_Speed::SetV1(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetV1(RGE_Communications_Speed * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00432fb0(R)  
    //                               ?SetV1@RGE_Communications_Speed@@QAEXK@Z                     XREF[1]:     SetSpeedV1:0042f23b(c)  
    //                               RGE_Communications_Speed::SetV1
    //                              com_spd.cpp:580 (25)
    //         00432fb0     MOV        EAX,dword ptr [ESP + param_1]
    //         00432fb4     MOV        this,dword ptr [L]                               = 00000000
    //         00432fba     PUSH       EAX
    //         00432fbb     PUSH       s_Speed_set_V1=%d                                = "Speed set V1=%d"
    //         00432fc0     PUSH       this
    //         00432fc1     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00432fc6     ADD        ESP,0xc
    //                              com_spd.cpp:582 (3)
    //         00432fc9     RET        0x4
    //         00432fcc     ??         90h
    //         00432fcd     NOP
    //         00432fce     NOP
    //         00432fcf     NOP
    return;
}

void RGE_Communications_Speed::SetV2(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetV2(RGE_Communications_Speed * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00432fd0(R)  
    //                               ?SetV2@RGE_Communications_Speed@@QAEXK@Z                     XREF[1]:     SetSpeedV2:0042f25b(c)  
    //                               RGE_Communications_Speed::SetV2
    //                              com_spd.cpp:585 (25)
    //         00432fd0     MOV        EAX,dword ptr [ESP + param_1]
    //         00432fd4     MOV        this,dword ptr [L]                               = 00000000
    //         00432fda     PUSH       EAX
    //         00432fdb     PUSH       s_Speed_set_V2=%d                                = "Speed set V2=%d"
    //         00432fe0     PUSH       this
    //         00432fe1     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00432fe6     ADD        ESP,0xc
    //                              com_spd.cpp:587 (3)
    //         00432fe9     RET        0x4
    //         00432fec     ??         90h
    //         00432fed     NOP
    //         00432fee     NOP
    //         00432fef     NOP
    //                              * public: __thiscall RGE_Communications_Synchronize::RGE_Communications_Synchronize(class TCommunica... *
    //                              undefined __thiscall RGE_Communications_Synchronize(RGE_Communicatio
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              TCommunication    Stack[0x4]:4   param_1                   XREF[1]:     00432ff0(R)  
    //                               ??0RGE_Communications_Synchronize@@QAE@PAVTCommunications_H  XREF[3]:     TCommunications_Handler:00425e59(c
    //                               RGE_Communications_Synchronize::RGE_Communications_Synchron               UnlinkCurrentLevel:0042c24c(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c3e5(c)  
    //                              com_sync.cpp:23 (7)
    //         00432ff0     MOV        EAX,dword ptr [ESP + param_1]
    //         00432ff4     PUSH       ESI
    //         00432ff5     MOV        ESI,this
    //                              com_sync.cpp:25 (80)
    //         00432ff7     PUSH       0xa
    //         00432ff9     PUSH       s_Check_turn_=_%d                                = "Check turn = %d"
    //         00432ffe     MOV        dword ptr [ESI],EAX
    //         00433000     MOV        dword ptr [ESI + 0x4],0x3e8
    //         00433007     MOV        dword ptr [ESI + 0x8],0xa
    //         0043300e     MOV        this,dword ptr [L]                               = 00000000
    //         00433014     PUSH       this
    //         00433015     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0043301a     ADD        ESP,0xc
    //         0043301d     MOV        EAX,0x1
    //         00433022     XOR        this,this
    //         00433024     MOV        dword ptr [ESI + 0xc],EAX
    //         00433027     MOV        dword ptr [ESI + 0x24],EAX
    //         0043302a     MOV        dword ptr [ESI + 0x1c],EAX
    //         0043302d     MOV        dword ptr [ESI + 0x18],this
    //         00433030     MOV        dword ptr [ESI + 0x20],this
    //         00433033     MOV        dword ptr [ESI + 0x28],this
    //         00433036     MOV        dword ptr [ESI + 0x2c],this
    //         00433039     MOV        dword ptr [ESI + 0x14],this
    //         0043303c     MOV        dword ptr [ESI + 0x10],this
    //         0043303f     LEA        EAX,[ESI + 0x38]
    //         00433042     MOV        EDX,0x37
    //                               LAB_00433047                                                 XREF[1]:     00433065(j)  
    //                              com_sync.cpp:26 (32)
    //         00433047     MOV        dword ptr [EAX + -0x4],this
    //         0043304a     MOV        dword ptr [EAX],this
    //         0043304c     MOV        dword ptr [EAX + 0x4],this
    //         0043304f     MOV        dword ptr [EAX + 0x8],this
    //         00433052     MOV        dword ptr [EAX + 0xc],this
    //         00433055     MOV        dword ptr [EAX + 0x10],this
    //         00433058     MOV        dword ptr [EAX + 0x14],this
    //         0043305b     MOV        dword ptr [EAX + 0x18],this
    //         0043305e     MOV        dword ptr [EAX + -0x8],this
    //         00433061     ADD        EAX,0x24
    //         00433064     DEC        EDX
    //         00433065     JNZ        LAB_00433047
    //                              com_sync.cpp:27 (6)
    //         00433067     MOV        EAX,ESI
    //         00433069     POP        ESI
    //         0043306a     RET        0x4
    //         0043306d     ??         90h
    //         0043306e     NOP
    //         0043306f     NOP
    return;
}

RGE_Communications_Speed::RGE_Communications_Speed(TCommunications_Handler* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

void RGE_Communications_Speed::SetPlayerTurnSpeed(uint param_1, uchar param_2, uchar param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Communications_Speed::SetFutureSpeedChange(uint param_1, uint param_2, ulong param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

