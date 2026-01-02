#include "../common.h"
#include "RGE_TSLC.h"

RGE_TimeSinceLastCall::RGE_TimeSinceLastCall() {
    /* TODO: Stub */
//                              undefined __thiscall RGE_TimeSinceLastCall(RGE_TimeSinceLastCall * t
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ??0RGE_TimeSinceLastCall@@QAE@XZ                             XREF[2]:     RGE_Communications_Speed:00432717(
//                               RGE_TimeSinceLastCall::RGE_TimeSinceLastCall                              RGE_Communications_Speed:0043274d(
//                              RGE_TSLC.cpp:8 (4)
//         00480390     PUSH       ESI
//         00480391     PUSH       EDI
//         00480392     MOV        ESI,this
//                              RGE_TSLC.cpp:10 (2)
//         00480394     XOR        EAX,EAX
//                              RGE_TSLC.cpp:13 (46)
//         00480396     PUSH       0xd
//         00480398     PUSH       s_C:\msdev\work\age1_x1\RGE_TSLC.c               = "C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp"
//         0048039d     MOV        dword ptr [ESI + 0x100],0x1869f
//         004803a7     MOV        dword ptr [ESI + 0x104],EAX
//         004803ad     MOV        dword ptr [ESI + 0x2a0],EAX
//         004803b3     MOV        dword ptr [ESI + 0x2b0],EAX
//         004803b9     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004803be     MOV        dword ptr [ESI + 0x2a8],EAX
//                              RGE_TSLC.cpp:14 (6)
//         004803c4     MOV        dword ptr [ESI + 0x2ac],EAX
//                              RGE_TSLC.cpp:15 (12)
//         004803ca     MOV        dword ptr [ESI + 0x2a4],EAX
//         004803d0     LEA        EDI,[ESI + 0x10c]
//                              RGE_TSLC.cpp:18 (12)
//         004803d6     MOV        this,0x65
//         004803db     XOR        EAX,EAX
//         004803dd     ADD        ESP,0x8
//         004803e0     STOSD.REP  ES:EDI
//                              RGE_TSLC.cpp:19 (5)
//         004803e2     MOV        EAX,ESI
//         004803e4     POP        EDI
//         004803e5     POP        ESI
//         004803e6     RET
//         004803e7     ??         90h
//         004803e8     NOP
//         004803e9     NOP
//         004803ea     NOP
//         004803eb     NOP
//         004803ec     NOP
//         004803ed     NOP
//         004803ee     NOP
//         004803ef     NOP
}

RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_TimeSinceLastCall(RGE_TimeSinceLastCall * this)
//              void              <VOID>         <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ??1RGE_TimeSinceLastCall@@QAE@XZ                             XREF[2]:     ~RGE_Communications_Speed:00432790
//                               RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall                             ~RGE_Communications_Speed:004327aa
//                              RGE_TSLC.cpp:22 (1)
//         004803f0     RET
//         004803f1     ??         90h
//         004803f2     NOP
//         004803f3     NOP
//         004803f4     NOP
//         004803f5     NOP
//         004803f6     NOP
//         004803f7     NOP
//         004803f8     NOP
//         004803f9     NOP
//         004803fa     NOP
//         004803fb     NOP
//         004803fc     NOP
//         004803fd     NOP
//         004803fe     NOP
//         004803ff     NOP
}

ulong RGE_TimeSinceLastCall::GetAvg(int param_1) {
    /* TODO: Stub */
//                              ulong __thiscall GetAvg(RGE_TimeSinceLastCall * this, int param_1)
//              ulong             EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00480402(R)
//                               ?GetAvg@RGE_TimeSinceLastCall@@QAEKH@Z                       XREF[4]:     GetAvgFrameRate:00432d98(c),
//                               RGE_TimeSinceLastCall::GetAvg                                             GetRecommendedBufferGranularity:00
//                                                                                                         GetAvgInfo:00480549(c),
//                                                                                                         CPS:004806af(c)
//                              RGE_TSLC.cpp:59 (2)
//         00480400     PUSH       ESI
//         00480401     PUSH       EDI
//                              RGE_TSLC.cpp:64 (16)
//         00480402     MOV        EDI,dword ptr [ESP + param_1]
//         00480406     XOR        EAX,EAX
//         00480408     CMP        EDI,0x1
//         0048040b     JL         LAB_0048044a
//         0048040d     CMP        EDI,0x64
//         00480410     JG         LAB_0048044a
//                              RGE_TSLC.cpp:67 (6)
//         00480412     MOV        EDX,dword ptr [ECX + this->Offset]
//                              RGE_TSLC.cpp:69 (6)
//         00480418     XOR        ESI,ESI
//         0048041a     TEST       EDI,EDI
//         0048041c     JLE        LAB_00480441
//                               LAB_0048041e                                                 XREF[1]:     0048043f(j)
//                              RGE_TSLC.cpp:71 (1)
//         0048041e     DEC        EDX
//                              RGE_TSLC.cpp:72 (4)
//         0048041f     TEST       EDX,EDX
//         00480421     JG         LAB_00480428
//                              RGE_TSLC.cpp:73 (5)
//         00480423     MOV        EDX,0x64
//                               LAB_00480428                                                 XREF[1]:     00480421(j)
//                              RGE_TSLC.cpp:75 (7)
//         00480428     ADD        EAX,dword ptr [ECX + EDX*0x4 + this->aTSLC[0]]
//                              RGE_TSLC.cpp:77 (7)
//         0048042f     CMP        EAX,0x3e8
//         00480434     JC         LAB_0048043c
//                              RGE_TSLC.cpp:78 (6)
//         00480436     MOV        dword ptr [ECX + this->cps],ESI
//                               LAB_0048043c                                                 XREF[1]:     00480434(j)
//                              RGE_TSLC.cpp:69 (5)
//         0048043c     INC        ESI
//         0048043d     CMP        ESI,EDI
//         0048043f     JL         LAB_0048041e
//                               LAB_00480441                                                 XREF[1]:     0048041c(j)
//                              RGE_TSLC.cpp:81 (4)
//         00480441     XOR        EDX,EDX
//         00480443     DIV        EDI
//                              RGE_TSLC.cpp:82 (12)
//         00480445     POP        EDI
//         00480446     POP        ESI
//         00480447     RET        0x4
//                               LAB_0048044a                                                 XREF[2]:     0048040b(j), 00480410(j)
//         0048044a     POP        EDI
//         0048044b     POP        ESI
//         0048044c     XOR        EAX,EAX
//         0048044e     RET        0x4
//         00480451     ??         90h
//         00480452     NOP
//         00480453     NOP
//         00480454     NOP
//         00480455     NOP
//         00480456     NOP
//         00480457     NOP
//         00480458     NOP
//         00480459     NOP
//         0048045a     NOP
//         0048045b     NOP
//         0048045c     NOP
//         0048045d     NOP
//         0048045e     NOP
//         0048045f     NOP
    return 0;
}

ulong RGE_TimeSinceLastCall::Get() {
    /* TODO: Stub */
//                              ulong __thiscall Get(RGE_TimeSinceLastCall * this)
//              ulong             EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?Get@RGE_TimeSinceLastCall@@QAEKXZ                           XREF[1]:     BufferTimeToUse:004329bd(c)
//                               RGE_TimeSinceLastCall::Get
//                              RGE_TSLC.cpp:85 (1)
//         00480460     PUSH       ESI
//                              RGE_TSLC.cpp:86 (25)
//         00480461     PUSH       0x56
//         00480463     MOV        ESI,this
//         00480465     PUSH       s_C:\msdev\work\age1_x1\RGE_TSLC.c               = "C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp"
//         0048046a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0048046f     MOV        this,dword ptr [ESI + 0x2a4]
//         00480475     ADD        ESP,0x8
//         00480478     SUB        EAX,this
//                              RGE_TSLC.cpp:87 (2)
//         0048047a     POP        ESI
//         0048047b     RET
//         0048047c     ??         90h
//         0048047d     NOP
//         0048047e     NOP
//         0048047f     NOP
    return 0;
}

ulong RGE_TimeSinceLastCall::Set() {
    /* TODO: Stub */
//                              ulong __thiscall Set(RGE_TimeSinceLastCall * this)
//              ulong             EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?Set@RGE_TimeSinceLastCall@@QAEKXZ                           XREF[2]:     ReloadBufferFrames:00432949(c),
//                               RGE_TimeSinceLastCall::Set                                                BufferTimeToUse:00432985(c)
//                              RGE_TSLC.cpp:90 (1)
//         00480480     PUSH       ESI
//                              RGE_TSLC.cpp:93 (14)
//         00480481     PUSH       0x5d
//         00480483     MOV        ESI,this
//         00480485     PUSH       s_C:\msdev\work\age1_x1\RGE_TSLC.c               = "C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp"
//         0048048a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              RGE_TSLC.cpp:97 (13)
//         0048048f     MOV        this,dword ptr [ESI + 0x2a4]
//         00480495     ADD        ESP,0x8
//         00480498     CMP        this,EAX
//         0048049a     JNZ        LAB_004804a0
//                              RGE_TSLC.cpp:98 (2)
//         0048049c     XOR        EAX,EAX
//                              RGE_TSLC.cpp:113 (2)
//         0048049e     POP        ESI
//         0048049f     RET
//                               LAB_004804a0                                                 XREF[1]:     0048049a(j)
//                              RGE_TSLC.cpp:100 (2)
//         004804a0     MOV        EDX,EAX
//                              RGE_TSLC.cpp:102 (8)
//         004804a2     MOV        dword ptr [ESI + 0x2a4],EAX
//         004804a8     SUB        EDX,this
//                              RGE_TSLC.cpp:104 (13)
//         004804aa     MOV        this,dword ptr [ESI + 0x2a0]
//         004804b0     INC        this
//         004804b1     MOV        dword ptr [ESI + 0x108],EDX
//                              RGE_TSLC.cpp:105 (13)
//         004804b7     MOV        EAX,this
//         004804b9     MOV        dword ptr [ESI + 0x2a0],this
//         004804bf     CMP        EAX,0x64
//         004804c2     JLE        LAB_004804ce
//                              RGE_TSLC.cpp:106 (10)
//         004804c4     MOV        dword ptr [ESI + 0x2a0],0x0
//                               LAB_004804ce                                                 XREF[1]:     004804c2(j)
//                              RGE_TSLC.cpp:108 (19)
//         004804ce     MOV        EAX,dword ptr [ESI + 0x2a0]
//         004804d4     MOV        this,dword ptr [ESI + 0x108]
//         004804da     MOV        dword ptr [ESI + EAX*0x4 + 0x10c],this
//                              RGE_TSLC.cpp:109 (24)
//         004804e1     MOV        EAX,dword ptr [ESI + 0x108]
//         004804e7     MOV        this,dword ptr [ESI + 0x100]
//         004804ed     CMP        EAX,this
//         004804ef     JNC        LAB_004804f3
//         004804f1     MOV        this,EAX
//                               LAB_004804f3                                                 XREF[1]:     004804ef(j)
//         004804f3     MOV        dword ptr [ESI + 0x100],this
//                              RGE_TSLC.cpp:110 (18)
//         004804f9     MOV        this,dword ptr [ESI + 0x104]
//         004804ff     CMP        EAX,this
//         00480501     JBE        LAB_00480505
//         00480503     MOV        this,EAX
//                               LAB_00480505                                                 XREF[1]:     00480501(j)
//         00480505     MOV        dword ptr [ESI + 0x104],this
//                              RGE_TSLC.cpp:113 (2)
//         0048050b     POP        ESI
//         0048050c     RET
//         0048050d     ??         90h
//         0048050e     NOP
//         0048050f     NOP
    return 0;
}

void RGE_TimeSinceLastCall::Skip() {
    /* TODO: Stub */
//                              void __thiscall Skip(RGE_TimeSinceLastCall * this)
//              void              <VOID>         <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?Skip@RGE_TimeSinceLastCall@@QAEXXZ                          XREF[2]:     BufferTimeToUse:0043298c(c),
//                               RGE_TimeSinceLastCall::Skip                                               Skip:00432a79(c)
//                              RGE_TSLC.cpp:117 (1)
//         00480510     PUSH       ESI
//                              language.dll match for 0x78: "10"
//                              RGE_TSLC.cpp:120 (17)
//         00480511     PUSH       0x78
//         00480513     MOV        ESI,this
//         00480515     PUSH       s_C:\msdev\work\age1_x1\RGE_TSLC.c               = "C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp"
//         0048051a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0048051f     ADD        ESP,0x8
//                              language.dll match for 0x79: "N"
//                              RGE_TSLC.cpp:121 (21)
//         00480522     PUSH       0x79
//         00480524     PUSH       s_C:\msdev\work\age1_x1\RGE_TSLC.c               = "C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp"
//         00480529     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0048052e     ADD        ESP,0x8
//         00480531     MOV        dword ptr [ESI + 0x2a4],EAX
//                              RGE_TSLC.cpp:122 (2)
//         00480537     POP        ESI
//         00480538     RET
//         00480539     ??         90h
//         0048053a     NOP
//         0048053b     NOP
//         0048053c     NOP
//         0048053d     NOP
//         0048053e     NOP
//         0048053f     NOP
    return;
}

char* RGE_TimeSinceLastCall::GetAvgInfo(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall GetAvgInfo(RGE_TimeSinceLastCall * this, int param
//              char *            EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00480542(R)
//                               ?GetAvgInfo@RGE_TimeSinceLastCall@@QAEPADH@Z
//                               RGE_TimeSinceLastCall::GetAvgInfo
//                              RGE_TSLC.cpp:126 (2)
//         00480540     PUSH       ESI
//         00480541     PUSH       EDI
//                              RGE_TSLC.cpp:131 (12)
//         00480542     MOV        EDI,dword ptr [ESP + param_1]
//         00480546     MOV        ESI,this
//         00480548     PUSH       EDI
//         00480549     CALL       RGE_TimeSinceLastCall::GetAvg                    ulong GetAvg(RGE_TimeSinceLastCall * this, in
//                              RGE_TSLC.cpp:133 (16)
//         0048054e     PUSH       EDI
//         0048054f     PUSH       EAX
//         00480550     PUSH       s_Avg_%d_/_%d                                    = "Avg %d / %d"
//         00480555     PUSH       ESI
//         00480556     CALL       sprintf                                          undefined sprintf()
//         0048055b     ADD        ESP,0x10
//                              RGE_TSLC.cpp:135 (2)
//         0048055e     MOV        EAX,ESI
//                              RGE_TSLC.cpp:136 (5)
//         00480560     POP        EDI
//         00480561     POP        ESI
//         00480562     RET        0x4
//         00480565     ??         90h
//         00480566     NOP
//         00480567     NOP
//         00480568     NOP
//         00480569     NOP
//         0048056a     NOP
//         0048056b     NOP
//         0048056c     NOP
//         0048056d     NOP
//         0048056e     NOP
//         0048056f     NOP
    return 0;
}

char* RGE_TimeSinceLastCall::GetHiLoMaxInfo(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall GetHiLoMaxInfo(RGE_TimeSinceLastCall * this, int p
//              char *            EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[7]:     00480572(R), 00480597(W), 004805ba(R), 004805bf(W),
//                                                                                     004805cd(R), 004805d1(R), 004805d5(R)
//                               ?GetHiLoMaxInfo@RGE_TimeSinceLastCall@@QAEPADH@Z
//                               RGE_TimeSinceLastCall::GetHiLoMaxInfo
//                              RGE_TSLC.cpp:139 (2)
//         00480570     PUSH       EBX
//         00480571     PUSH       EBP
//                              RGE_TSLC.cpp:143 (37)
//         00480572     MOV        EBP,dword ptr [ESP + param_1]
//         00480576     PUSH       ESI
//         00480577     XOR        EAX,EAX
//         00480579     XOR        EBX,EBX
//         0048057b     PUSH       EDI
//         0048057c     CMP        EBP,0x1
//         0048057f     MOV        ESI,this
//         00480581     MOV        EDI,0xf423f
//         00480586     JL         LAB_004805cd
//         00480588     CMP        EBP,0x64
//         0048058b     JG         LAB_004805cd
//         0048058d     MOV        EDX,dword ptr [ESI + 0x2a0]
//         00480593     TEST       EBP,EBP
//         00480595     JLE        LAB_004805c5
//                              RGE_TSLC.cpp:148 (4)
//         00480597     MOV        dword ptr [ESP + param_1],EBP
//                               LAB_0048059b                                                 XREF[1]:     004805c3(j)
//                              RGE_TSLC.cpp:143 (62)
//         0048059b     DEC        EDX
//         0048059c     TEST       EDX,EDX
//         0048059e     JG         LAB_004805a5
//         004805a0     MOV        EDX,0x64
//                               LAB_004805a5                                                 XREF[1]:     0048059e(j)
//         004805a5     MOV        this,dword ptr [ESI + EDX*0x4 + 0x10c]
//         004805ac     ADD        EAX,this
//         004805ae     CMP        this,EDI
//         004805b0     JNC        LAB_004805b4
//         004805b2     MOV        EDI,this
//                               LAB_004805b4                                                 XREF[1]:     004805b0(j)
//         004805b4     CMP        this,EBX
//         004805b6     JBE        LAB_004805ba
//         004805b8     MOV        EBX,this
//                               LAB_004805ba                                                 XREF[1]:     004805b6(j)
//         004805ba     MOV        this,dword ptr [ESP + param_1]
//         004805be     DEC        this
//         004805bf     MOV        dword ptr [ESP + param_1],this
//         004805c3     JNZ        LAB_0048059b
//                               LAB_004805c5                                                 XREF[1]:     00480595(j)
//         004805c5     XOR        EDX,EDX
//         004805c7     MOV        this,EBX
//         004805c9     DIV        EBP
//         004805cb     JMP        LAB_004805d9
//                               LAB_004805cd                                                 XREF[2]:     00480586(j), 0048058b(j)
//         004805cd     MOV        EAX,dword ptr [ESP + param_1]
//         004805d1     MOV        EDI,dword ptr [ESP + param_1]
//         004805d5     MOV        this,dword ptr [ESP + param_1]
//                               LAB_004805d9                                                 XREF[1]:     004805cb(j)
//                              RGE_TSLC.cpp:145 (32)
//         004805d9     MOV        EDX,dword ptr [ESI + 0x104]
//         004805df     PUSH       EDX
//         004805e0     PUSH       this
//         004805e1     PUSH       EBP
//         004805e2     PUSH       EAX
//         004805e3     MOV        EAX,dword ptr [ESI + 0x100]
//         004805e9     PUSH       EDI
//         004805ea     PUSH       EAX
//         004805eb     PUSH       s_(LoLo_%d)_Lo=%d_<>_                            = "(LoLo %d) Lo=%d < Avg=%d / %d > Hi=%d  (Hi
//         004805f0     PUSH       ESI
//         004805f1     CALL       sprintf                                          undefined sprintf()
//         004805f6     ADD        ESP,0x20
//                              RGE_TSLC.cpp:147 (2)
//         004805f9     MOV        EAX,ESI
//                              RGE_TSLC.cpp:148 (7)
//         004805fb     POP        EDI
//         004805fc     POP        ESI
//         004805fd     POP        EBP
//         004805fe     POP        EBX
//         004805ff     RET        0x4
//         00480602     ??         90h
//         00480603     NOP
//         00480604     NOP
//         00480605     NOP
//         00480606     NOP
//         00480607     NOP
//         00480608     NOP
//         00480609     NOP
//         0048060a     NOP
//         0048060b     NOP
//         0048060c     NOP
//         0048060d     NOP
//         0048060e     NOP
//         0048060f     NOP
    return 0;
}

char* RGE_TimeSinceLastCall::GetHiLoInfo(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall GetHiLoInfo(RGE_TimeSinceLastCall * this, int para
//              char *            EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[7]:     00480612(R), 00480637(W), 0048065a(R), 0048065f(W),
//                                                                                     0048066d(R), 00480671(R), 00480675(R)
//                               ?GetHiLoInfo@RGE_TimeSinceLastCall@@QAEPADH@Z                XREF[1]:     GetPlayerSpeedStatusStr:00432c36(c
//                               RGE_TimeSinceLastCall::GetHiLoInfo
//                              RGE_TSLC.cpp:152 (2)
//         00480610     PUSH       EBX
//         00480611     PUSH       EBP
//                              RGE_TSLC.cpp:156 (37)
//         00480612     MOV        EBP,dword ptr [ESP + param_1]
//         00480616     PUSH       ESI
//         00480617     XOR        EAX,EAX
//         00480619     XOR        EBX,EBX
//         0048061b     PUSH       EDI
//         0048061c     CMP        EBP,0x1
//         0048061f     MOV        EDI,this
//         00480621     MOV        ESI,0xf423f
//         00480626     JL         LAB_0048066d
//         00480628     CMP        EBP,0x64
//         0048062b     JG         LAB_0048066d
//         0048062d     MOV        EDX,dword ptr [EDI + 0x2a0]
//         00480633     TEST       EBP,EBP
//         00480635     JLE        LAB_00480665
//                              RGE_TSLC.cpp:161 (4)
//         00480637     MOV        dword ptr [ESP + param_1],EBP
//                               LAB_0048063b                                                 XREF[1]:     00480663(j)
//                              RGE_TSLC.cpp:156 (62)
//         0048063b     DEC        EDX
//         0048063c     TEST       EDX,EDX
//         0048063e     JG         LAB_00480645
//         00480640     MOV        EDX,0x64
//                               LAB_00480645                                                 XREF[1]:     0048063e(j)
//         00480645     MOV        this,dword ptr [EDI + EDX*0x4 + 0x10c]
//         0048064c     ADD        EAX,this
//         0048064e     CMP        this,ESI
//         00480650     JNC        LAB_00480654
//         00480652     MOV        ESI,this
//                               LAB_00480654                                                 XREF[1]:     00480650(j)
//         00480654     CMP        this,EBX
//         00480656     JBE        LAB_0048065a
//         00480658     MOV        EBX,this
//                               LAB_0048065a                                                 XREF[1]:     00480656(j)
//         0048065a     MOV        this,dword ptr [ESP + param_1]
//         0048065e     DEC        this
//         0048065f     MOV        dword ptr [ESP + param_1],this
//         00480663     JNZ        LAB_0048063b
//                               LAB_00480665                                                 XREF[1]:     00480635(j)
//         00480665     XOR        EDX,EDX
//         00480667     MOV        this,EBX
//         00480669     DIV        EBP
//         0048066b     JMP        LAB_00480679
//                               LAB_0048066d                                                 XREF[2]:     00480626(j), 0048062b(j)
//         0048066d     MOV        EAX,dword ptr [ESP + param_1]
//         00480671     MOV        ESI,dword ptr [ESP + param_1]
//         00480675     MOV        this,dword ptr [ESP + param_1]
//                               LAB_00480679                                                 XREF[1]:     0048066b(j)
//                              RGE_TSLC.cpp:158 (18)
//         00480679     PUSH       EBP
//         0048067a     PUSH       this
//         0048067b     PUSH       EAX
//         0048067c     PUSH       ESI
//         0048067d     PUSH       s_Lo=%d_<_Avg=%d_>_Hi=%d_of_%d                   = "Lo=%d < Avg=%d > Hi=%d of %d"
//         00480682     PUSH       EDI
//         00480683     CALL       sprintf                                          undefined sprintf()
//         00480688     ADD        ESP,0x18
//                              RGE_TSLC.cpp:160 (2)
//         0048068b     MOV        EAX,EDI
//                              RGE_TSLC.cpp:161 (7)
//         0048068d     POP        EDI
//         0048068e     POP        ESI
//         0048068f     POP        EBP
//         00480690     POP        EBX
//         00480691     RET        0x4
//         00480694     ??         90h
//         00480695     NOP
//         00480696     NOP
//         00480697     NOP
//         00480698     NOP
//         00480699     NOP
//         0048069a     NOP
//         0048069b     NOP
//         0048069c     NOP
//         0048069d     NOP
//         0048069e     NOP
//         0048069f     NOP
    return 0;
}

ulong RGE_TimeSinceLastCall::CPS() {
    /* TODO: Stub */
//                              ulong __thiscall CPS(RGE_TimeSinceLastCall * this)
//              ulong             EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?CPS@RGE_TimeSinceLastCall@@QAEKXZ
//                               RGE_TimeSinceLastCall::CPS
//                              RGE_TSLC.cpp:164 (3)
//         004806a0     PUSH       ESI
//         004806a1     MOV        ESI,this
//                              RGE_TSLC.cpp:167 (17)
//         004806a3     PUSH       0x64
//         004806a5     MOV        dword ptr [ESI + 0x2b0],0x0
//         004806af     CALL       RGE_TimeSinceLastCall::GetAvg                    ulong GetAvg(RGE_TimeSinceLastCall * this, in
//                              RGE_TSLC.cpp:168 (6)
//         004806b4     MOV        EAX,dword ptr [ESI + 0x2b0]
//                              RGE_TSLC.cpp:169 (2)
//         004806ba     POP        ESI
//         004806bb     RET
//         004806bc     ??         90h
//         004806bd     NOP
//         004806be     NOP
//         004806bf     NOP
    return 0;
}

ulong RGE_TimeSinceLastCall::GetFirstCall() {
    /* TODO: Stub */
//                              ulong __thiscall GetFirstCall(RGE_TimeSinceLastCall * this)
//              ulong             EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?GetFirstCall@RGE_TimeSinceLastCall@@QAEKXZ
//                               RGE_TimeSinceLastCall::GetFirstCall
//                              RGE_TSLC.cpp:173 (6)
//         004806c0     MOV        EAX,dword ptr [ECX + this->FirstCall]
//                              RGE_TSLC.cpp:175 (1)
//         004806c6     RET
//         004806c7     ??         90h
//         004806c8     NOP
//         004806c9     NOP
//         004806ca     NOP
//         004806cb     NOP
//         004806cc     NOP
//         004806cd     NOP
//         004806ce     NOP
//         004806cf     NOP
    return 0;
}

char* RGE_TimeSinceLastCall::GetElapsedFirstCall() {
    /* TODO: Stub */
//                              char * __thiscall GetElapsedFirstCall(RGE_TimeSinceLastCall * this)
//              char *            EAX:4          <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?GetElapsedFirstCall@RGE_TimeSinceLastCall@@QAEPADXZ
//                               RGE_TimeSinceLastCall::GetElapsedFirstCall
//                              RGE_TSLC.cpp:178 (3)
//         004806d0     PUSH       EBX
//         004806d1     PUSH       ESI
//         004806d2     PUSH       EDI
//                              RGE_TSLC.cpp:181 (23)
//         004806d3     PUSH       0xb5
//         004806d8     MOV        EDI,this
//         004806da     PUSH       s_C:\msdev\work\age1_x1\RGE_TSLC.c               = "C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp"
//         004806df     XOR        EBX,EBX
//         004806e1     XOR        ESI,ESI
//         004806e3     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004806e8     MOV        this,EAX
//                              RGE_TSLC.cpp:182 (29)
//         004806ea     MOV        EAX,dword ptr [EDI + 0x2a8]
//         004806f0     MOV        dword ptr [EDI + 0x2ac],this
//         004806f6     SUB        this,EAX
//         004806f8     MOV        EAX,0x10624dd3
//         004806fd     ADD        ESP,0x8
//         00480700     MUL        this
//         00480702     MOV        this,EDX
//         00480704     SHR        this,0x6
//                              RGE_TSLC.cpp:184 (5)
//         00480707     CMP        this,0x3b
//         0048070a     JLE        LAB_0048074f
//                              RGE_TSLC.cpp:186 (21)
//         0048070c     MOV        EAX,0x88888889
//         00480711     IMUL       this
//         00480713     ADD        EDX,this
//         00480715     SAR        EDX,0x5
//         00480718     MOV        EAX,EDX
//         0048071a     SHR        EAX,0x1f
//         0048071d     ADD        EDX,EAX
//         0048071f     MOV        ESI,EDX
//                              RGE_TSLC.cpp:187 (7)
//         00480721     SHL        EDX,0x4
//         00480724     SUB        EDX,ESI
//         00480726     NEG        EDX
//                              RGE_TSLC.cpp:188 (8)
//         00480728     CMP        ESI,0x3b
//         0048072b     LEA        this,[this->TBuff[0] + EDX*0x4]
//         0048072e     JLE        LAB_0048074f
//                              RGE_TSLC.cpp:190 (21)
//         00480730     MOV        EAX,0x88888889
//         00480735     IMUL       ESI
//         00480737     ADD        EDX,ESI
//         00480739     SAR        EDX,0x5
//         0048073c     MOV        EAX,EDX
//         0048073e     SHR        EAX,0x1f
//         00480741     ADD        EDX,EAX
//         00480743     MOV        EBX,EDX
//                              RGE_TSLC.cpp:191 (10)
//         00480745     SHL        EDX,0x4
//         00480748     SUB        EDX,EBX
//         0048074a     NEG        EDX
//         0048074c     LEA        ESI,[ESI + EDX*0x4]
//                               LAB_0048074f                                                 XREF[2]:     0048070a(j), 0048072e(j)
//                              RGE_TSLC.cpp:194 (17)
//         0048074f     PUSH       this
//         00480750     PUSH       ESI
//         00480751     PUSH       EBX
//         00480752     PUSH       s_%02ld:%02ld:%02ld                              = "%02ld:%02ld:%02ld"
//         00480757     PUSH       EDI
//         00480758     CALL       sprintf                                          undefined sprintf()
//         0048075d     ADD        ESP,0x14
//                              RGE_TSLC.cpp:196 (2)
//         00480760     MOV        EAX,EDI
//                              RGE_TSLC.cpp:197 (4)
//         00480762     POP        EDI
//         00480763     POP        ESI
//         00480764     POP        EBX
//         00480765     RET
//         00480766     ??         90h
//         00480767     NOP
//         00480768     NOP
//         00480769     NOP
//         0048076a     NOP
//         0048076b     NOP
//         0048076c     NOP
//         0048076d     NOP
//         0048076e     NOP
//         0048076f     NOP
    return 0;
}

void RGE_TimeSinceLastCall::Test() {
    /* TODO: Stub */
//                              void __thiscall Test(RGE_TimeSinceLastCall * this)
//              void              <VOID>         <RETURN>
//              RGE_TimeSinceL    ECX:4 (auto)   this
//                               ?Test@RGE_TimeSinceLastCall@@QAEXXZ
//                               RGE_TimeSinceLastCall::Test
//                              RGE_TSLC.cpp:202 (1)
//         00480770     PUSH       EDI
//                              RGE_TSLC.cpp:203 (6)
//         00480771     LEA        EDI,[ECX + this->aTSLC[0]]
//                              RGE_TSLC.cpp:204 (12)
//         00480777     MOV        this,0x64
//         0048077c     MOV        EAX,0xa
//         00480781     STOSD.REP  ES:EDI
//                              RGE_TSLC.cpp:205 (2)
//         00480783     POP        EDI
//         00480784     RET
//         00480785     ??         90h
//         00480786     NOP
//         00480787     NOP
//         00480788     NOP
//         00480789     NOP
//         0048078a     NOP
//         0048078b     NOP
//         0048078c     NOP
//         0048078d     NOP
//         0048078e     NOP
//         0048078f     NOP
    return;
}

