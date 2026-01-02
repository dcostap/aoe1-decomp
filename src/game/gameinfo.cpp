#include "../common.h"
#include "gameinfo.h"

RGE_Campaign_Info::RGE_Campaign_Info(int param_1, RGE_Campaign** param_2, long param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Campaign_Info(RGE_Campaign_Info * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              RGE_Campaign *    Stack[0x4]:4   param_1                   XREF[1]:     0044c783(R)
//                               ??0RGE_Campaign_Info@@QAE@PAVRGE_Campaign@@@Z                XREF[1]:     set_current_campaign:0044cff1(c)
//                               RGE_Campaign_Info::RGE_Campaign_Info
//                              gameinfo.cpp:84 (3)
//         0044c780     PUSH       EBX
//         0044c781     MOV        EBX,this
//                              gameinfo.cpp:87 (17)
//         0044c783     MOV        this,dword ptr [ESP + param_1]
//         0044c787     PUSH       EBP
//         0044c788     XOR        EBP,EBP
//         0044c78a     PUSH       ESI
//         0044c78b     CMP        this,EBP
//         0044c78d     PUSH       EDI
//         0044c78e     JZ         LAB_0044c81a
//                              gameinfo.cpp:90 (6)
//         0044c794     MOV        dword ptr [EBX + 0x110],this
//                              gameinfo.cpp:91 (36)
//         0044c79a     CALL       RGE_Campaign::get_name                           char * get_name(RGE_Campaign * this)
//         0044c79f     MOV        EDI,EAX
//         0044c7a1     OR         this,0xffffffff
//         0044c7a4     XOR        EAX,EAX
//         0044c7a6     SCASB.RE   ES:EDI
//         0044c7a8     NOT        this
//         0044c7aa     SUB        EDI,this
//         0044c7ac     MOV        EAX,this
//         0044c7ae     MOV        ESI,EDI
//         0044c7b0     MOV        EDI,EBX
//         0044c7b2     SHR        this,0x2
//         0044c7b5     MOVSD.REP  ES:EDI,ESI
//         0044c7b7     MOV        this,EAX
//         0044c7b9     AND        this,0x3
//         0044c7bc     MOVSB.REP  ES:EDI,ESI
//                              gameinfo.cpp:92 (11)
//         0044c7be     MOV        this,dword ptr [EBX + 0x110]
//         0044c7c4     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//                              gameinfo.cpp:93 (10)
//         0044c7c9     CMP        EAX,EBP
//         0044c7cb     MOV        dword ptr [EBX + 0x104],EAX
//         0044c7d1     JLE        LAB_0044c7fc
//                              gameinfo.cpp:97 (26)
//         0044c7d3     PUSH       0x1
//         0044c7d5     PUSH       EAX
//         0044c7d6     MOV        dword ptr [EBX + 0x100],EBP
//         0044c7dc     MOV        dword ptr [EBX + 0x10c],EBP
//         0044c7e2     CALL       calloc                                           undefined calloc()
//         0044c7e7     MOV        dword ptr [EBX + 0x108],EAX
//                              gameinfo.cpp:98 (6)
//         0044c7ed     MOV        byte ptr [EAX],0x2
//         0044c7f0     ADD        ESP,0x8
//                              gameinfo.cpp:126 (9)
//         0044c7f3     MOV        EAX,EBX
//         0044c7f5     POP        EDI
//         0044c7f6     POP        ESI
//         0044c7f7     POP        EBP
//         0044c7f8     POP        EBX
//         0044c7f9     RET        0x4
//                               LAB_0044c7fc                                                 XREF[1]:     0044c7d1(j)
//                              gameinfo.cpp:111 (3)
//         0044c7fc     OR         EAX,0xffffffff
//                              gameinfo.cpp:124 (18)
//         0044c7ff     MOV        dword ptr [EBX + 0x108],EBP
//         0044c805     MOV        dword ptr [EBX + 0x100],EAX
//         0044c80b     MOV        dword ptr [EBX + 0x10c],EAX
//                              gameinfo.cpp:126 (9)
//         0044c811     MOV        EAX,EBX
//         0044c813     POP        EDI
//         0044c814     POP        ESI
//         0044c815     POP        EBP
//         0044c816     POP        EBX
//         0044c817     RET        0x4
//                               LAB_0044c81a                                                 XREF[1]:     0044c78e(j)
//                              gameinfo.cpp:120 (22)
//         0044c81a     MOV        EDI,s_                                           = ""
//         0044c81f     OR         this,0xffffffff
//         0044c822     XOR        EAX,EAX
//         0044c824     MOV        dword ptr [EBX + 0x110],EBP
//         0044c82a     SCASB.RE   ES:EDI=>s_                                       = ""
//         0044c82c     NOT        this
//         0044c82e     SUB        EDI,this
//                              gameinfo.cpp:126 (51)
//         0044c830     MOV        EAX,EBX
//         0044c832     MOV        EDX,this
//         0044c834     MOV        ESI,EDI
//         0044c836     MOV        EDI,EBX
//         0044c838     SHR        this,0x2
//         0044c83b     MOVSD.REP  ES:EDI,ESI
//         0044c83d     MOV        this,EDX
//         0044c83f     AND        this,0x3
//         0044c842     MOVSB.REP  ES:EDI,ESI
//         0044c844     POP        EDI
//         0044c845     MOV        dword ptr [EBX + 0x100],EBP
//         0044c84b     MOV        dword ptr [EBX + 0x10c],EBP
//         0044c851     MOV        dword ptr [EBX + 0x104],EBP
//         0044c857     MOV        dword ptr [EBX + 0x108],EBP
//         0044c85d     POP        ESI
//         0044c85e     POP        EBP
//         0044c85f     POP        EBX
//         0044c860     RET        0x4
//         0044c863     ??         90h
//         0044c864     NOP
//         0044c865     NOP
//         0044c866     NOP
//         0044c867     NOP
//         0044c868     NOP
//         0044c869     NOP
//         0044c86a     NOP
//         0044c86b     NOP
//         0044c86c     NOP
//         0044c86d     NOP
//         0044c86e     NOP
//         0044c86f     NOP
}

RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Campaign_Info(RGE_Campaign_Info * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              RGE_Campaign *    Stack[0x4]:4   param_1                   XREF[1]:     0044c783(R)
//                               ??0RGE_Campaign_Info@@QAE@PAVRGE_Campaign@@@Z                XREF[1]:     set_current_campaign:0044cff1(c)
//                               RGE_Campaign_Info::RGE_Campaign_Info
//                              gameinfo.cpp:84 (3)
//         0044c780     PUSH       EBX
//         0044c781     MOV        EBX,this
//                              gameinfo.cpp:87 (17)
//         0044c783     MOV        this,dword ptr [ESP + param_1]
//         0044c787     PUSH       EBP
//         0044c788     XOR        EBP,EBP
//         0044c78a     PUSH       ESI
//         0044c78b     CMP        this,EBP
//         0044c78d     PUSH       EDI
//         0044c78e     JZ         LAB_0044c81a
//                              gameinfo.cpp:90 (6)
//         0044c794     MOV        dword ptr [EBX + 0x110],this
//                              gameinfo.cpp:91 (36)
//         0044c79a     CALL       RGE_Campaign::get_name                           char * get_name(RGE_Campaign * this)
//         0044c79f     MOV        EDI,EAX
//         0044c7a1     OR         this,0xffffffff
//         0044c7a4     XOR        EAX,EAX
//         0044c7a6     SCASB.RE   ES:EDI
//         0044c7a8     NOT        this
//         0044c7aa     SUB        EDI,this
//         0044c7ac     MOV        EAX,this
//         0044c7ae     MOV        ESI,EDI
//         0044c7b0     MOV        EDI,EBX
//         0044c7b2     SHR        this,0x2
//         0044c7b5     MOVSD.REP  ES:EDI,ESI
//         0044c7b7     MOV        this,EAX
//         0044c7b9     AND        this,0x3
//         0044c7bc     MOVSB.REP  ES:EDI,ESI
//                              gameinfo.cpp:92 (11)
//         0044c7be     MOV        this,dword ptr [EBX + 0x110]
//         0044c7c4     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//                              gameinfo.cpp:93 (10)
//         0044c7c9     CMP        EAX,EBP
//         0044c7cb     MOV        dword ptr [EBX + 0x104],EAX
//         0044c7d1     JLE        LAB_0044c7fc
//                              gameinfo.cpp:97 (26)
//         0044c7d3     PUSH       0x1
//         0044c7d5     PUSH       EAX
//         0044c7d6     MOV        dword ptr [EBX + 0x100],EBP
//         0044c7dc     MOV        dword ptr [EBX + 0x10c],EBP
//         0044c7e2     CALL       calloc                                           undefined calloc()
//         0044c7e7     MOV        dword ptr [EBX + 0x108],EAX
//                              gameinfo.cpp:98 (6)
//         0044c7ed     MOV        byte ptr [EAX],0x2
//         0044c7f0     ADD        ESP,0x8
//                              gameinfo.cpp:126 (9)
//         0044c7f3     MOV        EAX,EBX
//         0044c7f5     POP        EDI
//         0044c7f6     POP        ESI
//         0044c7f7     POP        EBP
//         0044c7f8     POP        EBX
//         0044c7f9     RET        0x4
//                               LAB_0044c7fc                                                 XREF[1]:     0044c7d1(j)
//                              gameinfo.cpp:111 (3)
//         0044c7fc     OR         EAX,0xffffffff
//                              gameinfo.cpp:124 (18)
//         0044c7ff     MOV        dword ptr [EBX + 0x108],EBP
//         0044c805     MOV        dword ptr [EBX + 0x100],EAX
//         0044c80b     MOV        dword ptr [EBX + 0x10c],EAX
//                              gameinfo.cpp:126 (9)
//         0044c811     MOV        EAX,EBX
//         0044c813     POP        EDI
//         0044c814     POP        ESI
//         0044c815     POP        EBP
//         0044c816     POP        EBX
//         0044c817     RET        0x4
//                               LAB_0044c81a                                                 XREF[1]:     0044c78e(j)
//                              gameinfo.cpp:120 (22)
//         0044c81a     MOV        EDI,s_                                           = ""
//         0044c81f     OR         this,0xffffffff
//         0044c822     XOR        EAX,EAX
//         0044c824     MOV        dword ptr [EBX + 0x110],EBP
//         0044c82a     SCASB.RE   ES:EDI=>s_                                       = ""
//         0044c82c     NOT        this
//         0044c82e     SUB        EDI,this
//                              gameinfo.cpp:126 (51)
//         0044c830     MOV        EAX,EBX
//         0044c832     MOV        EDX,this
//         0044c834     MOV        ESI,EDI
//         0044c836     MOV        EDI,EBX
//         0044c838     SHR        this,0x2
//         0044c83b     MOVSD.REP  ES:EDI,ESI
//         0044c83d     MOV        this,EDX
//         0044c83f     AND        this,0x3
//         0044c842     MOVSB.REP  ES:EDI,ESI
//         0044c844     POP        EDI
//         0044c845     MOV        dword ptr [EBX + 0x100],EBP
//         0044c84b     MOV        dword ptr [EBX + 0x10c],EBP
//         0044c851     MOV        dword ptr [EBX + 0x104],EBP
//         0044c857     MOV        dword ptr [EBX + 0x108],EBP
//         0044c85d     POP        ESI
//         0044c85e     POP        EBP
//         0044c85f     POP        EBX
//         0044c860     RET        0x4
//         0044c863     ??         90h
//         0044c864     NOP
//         0044c865     NOP
//         0044c866     NOP
//         0044c867     NOP
//         0044c868     NOP
//         0044c869     NOP
//         0044c86a     NOP
//         0044c86b     NOP
//         0044c86c     NOP
//         0044c86d     NOP
//         0044c86e     NOP
//         0044c86f     NOP
}

RGE_Campaign_Info::~RGE_Campaign_Info() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Campaign_Info(RGE_Campaign_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//                               ??1RGE_Campaign_Info@@QAE@XZ                                 XREF[1]:     ~RGE_Person_Info:0044cdca(c)
//                               RGE_Campaign_Info::~RGE_Campaign_Info
//                              gameinfo.cpp:131 (3)
//         0044c870     PUSH       ESI
//         0044c871     MOV        ESI,this
//                              gameinfo.cpp:132 (10)
//         0044c873     MOV        EAX,dword ptr [ESI + 0x108]
//         0044c879     TEST       EAX,EAX
//         0044c87b     JZ         LAB_0044c890
//                              gameinfo.cpp:134 (9)
//         0044c87d     PUSH       EAX
//         0044c87e     CALL       free                                             undefined free()
//         0044c883     ADD        ESP,0x4
//                              gameinfo.cpp:135 (10)
//         0044c886     MOV        dword ptr [ESI + 0x108],0x0
//                               LAB_0044c890                                                 XREF[1]:     0044c87b(j)
//                              gameinfo.cpp:137 (2)
//         0044c890     POP        ESI
//         0044c891     RET
//         0044c892     ??         90h
//         0044c893     NOP
//         0044c894     NOP
//         0044c895     NOP
//         0044c896     NOP
//         0044c897     NOP
//         0044c898     NOP
//         0044c899     NOP
//         0044c89a     NOP
//         0044c89b     NOP
//         0044c89c     NOP
//         0044c89d     NOP
//         0044c89e     NOP
//         0044c89f     NOP
}

void RGE_Campaign_Info::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Campaign_Info * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c8c5(R)
//                               ?save@RGE_Campaign_Info@@QAEXH@Z                             XREF[1]:     save:0044ce74(c)
//                               RGE_Campaign_Info::save
//                              gameinfo.cpp:142 (5)
//         0044c8a0     PUSH       EBX
//         0044c8a1     PUSH       EBP
//         0044c8a2     PUSH       ESI
//         0044c8a3     MOV        ESI,this
//                              gameinfo.cpp:143 (32)
//         0044c8a5     MOV        this,dword ptr [L]                               = 00000000
//         0044c8ab     PUSH       EDI
//         0044c8ac     MOV        EAX,dword ptr [ESI + 0x10c]
//         0044c8b2     LEA        EBX,[ESI + 0x10c]
//         0044c8b8     PUSH       ESI
//         0044c8b9     PUSH       EAX
//         0044c8ba     PUSH       s___(PIF)Saving_campaign_-_(%d)_%s               = "  (PIF)Saving campaign - (%d) %s"
//         0044c8bf     PUSH       this
//         0044c8c0     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              gameinfo.cpp:145 (22)
//         0044c8c5     MOV        EDI,dword ptr [ESP + param_1]
//         0044c8c9     ADD        ESP,0x10
//         0044c8cc     PUSH       0xff
//         0044c8d1     PUSH       ESI
//         0044c8d2     PUSH       EDI
//         0044c8d3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044c8d8     ADD        ESP,0xc
//                              gameinfo.cpp:146 (18)
//         0044c8db     LEA        EDX,[ESI + 0x100]
//         0044c8e1     PUSH       0x4
//         0044c8e3     PUSH       EDX
//         0044c8e4     PUSH       EDI
//         0044c8e5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044c8ea     ADD        ESP,0xc
//                              gameinfo.cpp:147 (18)
//         0044c8ed     LEA        EBP,[ESI + 0x104]
//         0044c8f3     PUSH       0x4
//         0044c8f5     PUSH       EBP
//         0044c8f6     PUSH       EDI
//         0044c8f7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044c8fc     ADD        ESP,0xc
//                              gameinfo.cpp:148 (9)
//         0044c8ff     PUSH       0x4
//         0044c901     PUSH       EBX
//         0044c902     PUSH       EDI
//         0044c903     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              gameinfo.cpp:150 (10)
//         0044c908     MOV        EBP,dword ptr [EBP]
//         0044c90b     ADD        ESP,0xc
//         0044c90e     TEST       EBP,EBP
//         0044c910     JLE        LAB_0044c923
//                              gameinfo.cpp:151 (17)
//         0044c912     MOV        EAX,dword ptr [ESI + 0x108]
//         0044c918     PUSH       EBP
//         0044c919     PUSH       EAX
//         0044c91a     PUSH       EDI
//         0044c91b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044c920     ADD        ESP,0xc
//                               LAB_0044c923                                                 XREF[1]:     0044c910(j)
//                              gameinfo.cpp:152 (7)
//         0044c923     POP        EDI
//         0044c924     POP        ESI
//         0044c925     POP        EBP
//         0044c926     POP        EBX
//         0044c927     RET        0x4
//         0044c92a     ??         90h
//         0044c92b     NOP
//         0044c92c     NOP
//         0044c92d     NOP
//         0044c92e     NOP
//         0044c92f     NOP
    return;
}

void RGE_Campaign_Info::rehook_campaigns(RGE_Campaign** param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall rehook_campaigns(RGE_Campaign_Info * this, RGE_Campa
//              void              <VOID>         <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              RGE_Campaign *    Stack[0x4]:4   param_1                   XREF[4]:     0044c94c(R), 0044c954(W), 0044ca65(R), 0044ca71(W)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     0044c930(R), 0044c950(W), 0044ca26(R), 0044ca6d(W)
//                               ?rehook_campaigns@RGE_Campaign_Info@@QAEXPAPAVRGE_Campaign@  XREF[1]:     rehook_campaigns:0044cecb(c)
//                               RGE_Campaign_Info::rehook_campaigns
//                              gameinfo.cpp:156 (40)
//         0044c930     MOV        EAX,dword ptr [ESP + param_2]
//         0044c934     PUSH       EBX
//         0044c935     MOV        EBX,this
//         0044c937     TEST       EAX,EAX
//         0044c939     MOV        dword ptr [EBX + 0x110],0x0
//         0044c943     JLE        LAB_0044ca7e
//         0044c949     PUSH       EDI
//         0044c94a     PUSH       ESI
//         0044c94b     PUSH       EBP
//         0044c94c     MOV        EBP,dword ptr [ESP + param_1]
//         0044c950     MOV        dword ptr [ESP + param_2],EBP
//         0044c954     MOV        dword ptr [ESP + param_1],EAX
//                               LAB_0044c958                                                 XREF[1]:     0044ca75(j)
//                              gameinfo.cpp:163 (65)
//         0044c958     MOV        this,dword ptr [EBP]
//         0044c95b     MOV        EDI,EBX
//         0044c95d     CALL       RGE_Campaign::get_name                           char * get_name(RGE_Campaign * this)
//         0044c962     MOV        ESI,EAX
//                               LAB_0044c964                                                 XREF[1]:     0044c986(j)
//         0044c964     MOV        this,byte ptr [ESI]
//         0044c966     MOV        DL,byte ptr [EDI]
//         0044c968     MOV        AL,this
//         0044c96a     CMP        this,DL
//         0044c96c     JNZ        LAB_0044c98c
//         0044c96e     TEST       AL,AL
//         0044c970     JZ         LAB_0044c988
//         0044c972     MOV        DL,byte ptr [ESI + 0x1]
//         0044c975     MOV        this,byte ptr [EDI + 0x1]
//         0044c978     MOV        AL,DL
//         0044c97a     CMP        DL,this
//         0044c97c     JNZ        LAB_0044c98c
//         0044c97e     ADD        ESI,0x2
//         0044c981     ADD        EDI,0x2
//         0044c984     TEST       AL,AL
//         0044c986     JNZ        LAB_0044c964
//                               LAB_0044c988                                                 XREF[1]:     0044c970(j)
//         0044c988     XOR        EAX,EAX
//         0044c98a     JMP        LAB_0044c991
//                               LAB_0044c98c                                                 XREF[2]:     0044c96c(j), 0044c97c(j)
//         0044c98c     SBB        EAX,EAX
//         0044c98e     SBB        EAX,-0x1
//                               LAB_0044c991                                                 XREF[1]:     0044c98a(j)
//         0044c991     TEST       EAX,EAX
//         0044c993     JNZ        LAB_0044ca65
//                              gameinfo.cpp:165 (9)
//         0044c999     MOV        this,dword ptr [EBP]
//         0044c99c     MOV        dword ptr [EBX + 0x110],this
//                              gameinfo.cpp:166 (13)
//         0044c9a2     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//         0044c9a7     CMP        dword ptr [EBX + 0x104],EAX
//         0044c9ad     JZ         LAB_0044ca2d
//                              gameinfo.cpp:169 (19)
//         0044c9af     MOV        this,dword ptr [EBX + 0x110]
//         0044c9b5     PUSH       0x1
//         0044c9b7     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//         0044c9bc     PUSH       EAX
//         0044c9bd     CALL       calloc                                           undefined calloc()
//                              gameinfo.cpp:171 (26)
//         0044c9c2     MOV        this,dword ptr [EBX + 0x110]
//         0044c9c8     MOV        ESI,dword ptr [EBX + 0x104]
//         0044c9ce     ADD        ESP,0x8
//         0044c9d1     MOV        EBP,EAX
//         0044c9d3     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//         0044c9d8     CMP        ESI,EAX
//         0044c9da     JGE        LAB_0044c9f1
//                              gameinfo.cpp:172 (19)
//         0044c9dc     MOV        this,ESI
//         0044c9de     MOV        ESI,dword ptr [EBX + 0x108]
//         0044c9e4     MOV        EAX,this
//         0044c9e6     MOV        EDI,EBP
//         0044c9e8     SHR        this,0x2
//         0044c9eb     MOVSD.REP  ES:EDI,ESI
//         0044c9ed     MOV        this,EAX
//                              gameinfo.cpp:173 (2)
//         0044c9ef     JMP        LAB_0044ca0f
//                               LAB_0044c9f1                                                 XREF[1]:     0044c9da(j)
//                              gameinfo.cpp:174 (35)
//         0044c9f1     MOV        this,dword ptr [EBX + 0x110]
//         0044c9f7     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//         0044c9fc     MOV        ESI,dword ptr [EBX + 0x108]
//         0044ca02     MOV        this,EAX
//         0044ca04     MOV        EDX,this
//         0044ca06     MOV        EDI,EBP
//         0044ca08     SHR        this,0x2
//         0044ca0b     MOVSD.REP  ES:EDI,ESI
//         0044ca0d     MOV        this,EDX
//                               LAB_0044ca0f                                                 XREF[1]:     0044c9ef(j)
//         0044ca0f     AND        this,0x3
//         0044ca12     MOVSB.REP  ES:EDI,ESI
//                              gameinfo.cpp:175 (12)
//         0044ca14     MOV        EAX,dword ptr [EBX + 0x108]
//         0044ca1a     PUSH       EAX
//         0044ca1b     CALL       free                                             undefined free()
//                              gameinfo.cpp:176 (13)
//         0044ca20     MOV        dword ptr [EBX + 0x108],EBP
//         0044ca26     MOV        EBP,dword ptr [ESP + param_2]
//         0044ca2a     ADD        ESP,0x4
//                               LAB_0044ca2d                                                 XREF[1]:     0044c9ad(j)
//                              gameinfo.cpp:179 (11)
//         0044ca2d     MOV        this,dword ptr [EBX + 0x110]
//         0044ca33     CALL       RGE_Campaign::scenario_number                    long scenario_number(RGE_Campaign * this)
//                              gameinfo.cpp:181 (16)
//         0044ca38     MOV        this,dword ptr [EBX + 0x10c]
//         0044ca3e     MOV        dword ptr [EBX + 0x104],EAX
//         0044ca44     CMP        this,EAX
//         0044ca46     JL         LAB_0044ca4f
//                              gameinfo.cpp:182 (7)
//         0044ca48     DEC        EAX
//         0044ca49     MOV        dword ptr [EBX + 0x10c],EAX
//                               LAB_0044ca4f                                                 XREF[1]:     0044ca46(j)
//                              gameinfo.cpp:184 (16)
//         0044ca4f     MOV        EAX,dword ptr [EBX + 0x10c]
//         0044ca55     MOV        this,dword ptr [EBX + 0x100]
//         0044ca5b     CMP        this,EAX
//         0044ca5d     JLE        LAB_0044ca65
//                              gameinfo.cpp:185 (6)
//         0044ca5f     MOV        dword ptr [EBX + 0x100],EAX
//                               LAB_0044ca65                                                 XREF[2]:     0044c993(j), 0044ca5d(j)
//                              gameinfo.cpp:162 (25)
//         0044ca65     MOV        EAX,dword ptr [ESP + param_1]
//         0044ca69     ADD        EBP,0x4
//         0044ca6c     DEC        EAX
//         0044ca6d     MOV        dword ptr [ESP + param_2],EBP
//         0044ca71     MOV        dword ptr [ESP + param_1],EAX
//         0044ca75     JNZ        LAB_0044c958
//         0044ca7b     POP        EBP
//         0044ca7c     POP        ESI
//         0044ca7d     POP        EDI
//                               LAB_0044ca7e                                                 XREF[1]:     0044c943(j)
//                              gameinfo.cpp:187 (4)
//         0044ca7e     POP        EBX
//         0044ca7f     RET        0x8
//         0044ca82     ??         90h
//         0044ca83     NOP
//         0044ca84     NOP
//         0044ca85     NOP
//         0044ca86     NOP
//         0044ca87     NOP
//         0044ca88     NOP
//         0044ca89     NOP
//         0044ca8a     NOP
//         0044ca8b     NOP
//         0044ca8c     NOP
//         0044ca8d     NOP
//         0044ca8e     NOP
//         0044ca8f     NOP
    return;
}

uchar RGE_Campaign_Info::set_current_scenario(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall set_current_scenario(RGE_Campaign_Info * this, long
//              uchar             AL:1           <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0044ca90(R)
//                               ?set_current_scenario@RGE_Campaign_Info@@QAEEJ@Z             XREF[2]:     notify_of_scenario_complete:0044cb
//                               RGE_Campaign_Info::set_current_scenario                                   set_current_scenario:0044d118(c)
//                              gameinfo.cpp:192 (26)
//         0044ca90     MOV        EAX,dword ptr [ESP + param_1]
//         0044ca94     MOV        EDX,dword ptr [ECX + this->scenario_num]
//         0044ca9a     CMP        EAX,EDX
//         0044ca9c     JGE        LAB_0044caca
//         0044ca9e     MOV        EDX,dword ptr [ECX + this->scenario_info]
//         0044caa4     CMP        byte ptr [EDX + EAX*0x1],0x0
//         0044caa8     JZ         LAB_0044caca
//                              gameinfo.cpp:195 (10)
//         0044caaa     MOV        EDX,dword ptr [ECX + this->last_scenario]
//         0044cab0     CMP        EAX,EDX
//         0044cab2     JLE        LAB_0044cabf
//                              gameinfo.cpp:196 (6)
//         0044cab4     MOV        dword ptr [ECX + this->current_scenario],EDX
//                              gameinfo.cpp:199 (2)
//         0044caba     MOV        AL,0x1
//                              gameinfo.cpp:202 (3)
//         0044cabc     RET        0x4
//                               LAB_0044cabf                                                 XREF[1]:     0044cab2(j)
//                              gameinfo.cpp:198 (6)
//         0044cabf     MOV        dword ptr [ECX + this->current_scenario],EAX
//                              gameinfo.cpp:199 (2)
//         0044cac5     MOV        AL,0x1
//                              gameinfo.cpp:202 (3)
//         0044cac7     RET        0x4
//                               LAB_0044caca                                                 XREF[2]:     0044ca9c(j), 0044caa8(j)
//                              gameinfo.cpp:201 (2)
//         0044caca     XOR        AL,AL
//                              gameinfo.cpp:202 (3)
//         0044cacc     RET        0x4
//         0044cacf     ??         90h
    return 0;
}

uchar RGE_Campaign_Info::verify_campaign_name(char* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall verify_campaign_name(RGE_Campaign_Info * this, char
//              uchar             AL:1           <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0044cad2(R)
//                               ?verify_campaign_name@RGE_Campaign_Info@@QAEEPAD@Z           XREF[2]:     set_current_campaign:0044cf5e(c),
//                               RGE_Campaign_Info::verify_campaign_name                                   get_current_campaign:0044d090(c)
//                              gameinfo.cpp:208 (2)
//         0044cad0     PUSH       EBX
//         0044cad1     PUSH       ESI
//                              gameinfo.cpp:209 (49)
//         0044cad2     MOV        ESI,dword ptr [ESP + param_1]
//         0044cad6     MOV        EAX,this
//                               LAB_0044cad8                                                 XREF[1]:     0044cafa(j)
//         0044cad8     MOV        DL,byte ptr [EAX]
//         0044cada     MOV        BL,byte ptr [ESI]
//         0044cadc     MOV        this,DL
//         0044cade     CMP        DL,BL
//         0044cae0     JNZ        LAB_0044cb08
//         0044cae2     TEST       this,this
//         0044cae4     JZ         LAB_0044cafc
//         0044cae6     MOV        DL,byte ptr [EAX + 0x1]
//         0044cae9     MOV        BL,byte ptr [ESI + 0x1]
//         0044caec     MOV        this,DL
//         0044caee     CMP        DL,BL
//         0044caf0     JNZ        LAB_0044cb08
//         0044caf2     ADD        EAX,0x2
//         0044caf5     ADD        ESI,0x2
//         0044caf8     TEST       this,this
//         0044cafa     JNZ        LAB_0044cad8
//                               LAB_0044cafc                                                 XREF[1]:     0044cae4(j)
//         0044cafc     XOR        EAX,EAX
//         0044cafe     TEST       EAX,EAX
//         0044cb00     SETZ       AL
//                              gameinfo.cpp:213 (5)
//         0044cb03     POP        ESI
//         0044cb04     POP        EBX
//         0044cb05     RET        0x4
//                               LAB_0044cb08                                                 XREF[2]:     0044cae0(j), 0044caf0(j)
//                              gameinfo.cpp:209 (2)
//         0044cb08     SBB        EAX,EAX
//                              gameinfo.cpp:213 (13)
//         0044cb0a     POP        ESI
//         0044cb0b     SBB        EAX,-0x1
//         0044cb0e     POP        EBX
//         0044cb0f     TEST       EAX,EAX
//         0044cb11     SETZ       AL
//         0044cb14     RET        0x4
//         0044cb17     ??         90h
//         0044cb18     NOP
//         0044cb19     NOP
//         0044cb1a     NOP
//         0044cb1b     NOP
//         0044cb1c     NOP
//         0044cb1d     NOP
//         0044cb1e     NOP
//         0044cb1f     NOP
    return 0;
}

long RGE_Campaign_Info::get_scenario_list(char*** param_1, long* param_2) {
    /* TODO: Stub */
//                              long __thiscall get_scenario_list(RGE_Campaign_Info * this, char * *
//              long              EAX:4          <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//              char * * *        Stack[0x4]:4   param_1                   XREF[1]:     0044cb3e(R)
//              long *            Stack[0x8]:4   param_2                   XREF[2]:     0044cb79(R), 0044cb92(R)
//                               ?get_scenario_list@RGE_Campaign_Info@@QAEJPAPAPADAAJ@Z       XREF[1]:     get_scenario_list:0044d14e(c)
//                               RGE_Campaign_Info::get_scenario_list
//                              gameinfo.cpp:218 (3)
//         0044cb20     PUSH       EDI
//         0044cb21     MOV        EDI,this
//                              gameinfo.cpp:221 (10)
//         0044cb23     MOV        EAX,dword ptr [EDI + 0x110]
//         0044cb29     TEST       EAX,EAX
//         0044cb2b     JZ         LAB_0044cb92
//                              gameinfo.cpp:223 (24)
//         0044cb2d     MOV        EAX,dword ptr [EDI + 0x10c]
//         0044cb33     PUSH       ESI
//         0044cb34     PUSH       EBX
//         0044cb35     INC        EAX
//         0044cb36     PUSH       0x4
//         0044cb38     PUSH       EAX
//         0044cb39     CALL       calloc                                           undefined calloc()
//         0044cb3e     MOV        EBX,dword ptr [ESP + param_1]
//         0044cb42     ADD        ESP,0x8
//                              gameinfo.cpp:224 (14)
//         0044cb45     XOR        ESI,ESI
//         0044cb47     MOV        dword ptr [EBX],EAX
//         0044cb49     MOV        EAX,dword ptr [EDI + 0x10c]
//         0044cb4f     TEST       EAX,EAX
//         0044cb51     JL         LAB_0044cb79
//                               LAB_0044cb53                                                 XREF[1]:     0044cb77(j)
//                              gameinfo.cpp:225 (38)
//         0044cb53     MOV        this,dword ptr [EDI + 0x110]
//         0044cb59     PUSH       ESI
//         0044cb5a     CALL       RGE_Campaign::get_scenario_name                  char * get_scenario_name(RGE_Campaign * this,
//         0044cb5f     MOV        this,dword ptr [EBX]
//         0044cb61     PUSH       EAX
//         0044cb62     LEA        EDX,[this->campaign_name[0] + ESI*0x4]
//         0044cb65     PUSH       EDX
//         0044cb66     CALL       getstring                                        void getstring(char * * param_1, char * param
//         0044cb6b     MOV        EAX,dword ptr [EDI + 0x10c]
//         0044cb71     ADD        ESP,0x8
//         0044cb74     INC        ESI
//         0044cb75     CMP        ESI,EAX
//         0044cb77     JLE        LAB_0044cb53
//                               LAB_0044cb79                                                 XREF[1]:     0044cb51(j)
//                              gameinfo.cpp:227 (14)
//         0044cb79     MOV        this,dword ptr [ESP + param_2]
//         0044cb7d     MOV        EAX,dword ptr [EDI + 0x100]
//         0044cb83     POP        EBX
//         0044cb84     POP        ESI
//         0044cb85     MOV        dword ptr [this->campaign_name[0]],EAX
//                              gameinfo.cpp:228 (7)
//         0044cb87     MOV        EAX,dword ptr [EDI + 0x10c]
//         0044cb8d     INC        EAX
//                              gameinfo.cpp:232 (4)
//         0044cb8e     POP        EDI
//         0044cb8f     RET        0x8
//                               LAB_0044cb92                                                 XREF[1]:     0044cb2b(j)
//                              gameinfo.cpp:230 (4)
//         0044cb92     MOV        EDX,dword ptr [ESP + param_2]
//                              gameinfo.cpp:231 (3)
//         0044cb96     OR         EAX,0xffffffff
//                              gameinfo.cpp:232 (10)
//         0044cb99     POP        EDI
//         0044cb9a     MOV        dword ptr [EDX],0xffffffff
//         0044cba0     RET        0x8
//         0044cba3     ??         90h
//         0044cba4     NOP
//         0044cba5     NOP
//         0044cba6     NOP
//         0044cba7     NOP
//         0044cba8     NOP
//         0044cba9     NOP
//         0044cbaa     NOP
//         0044cbab     NOP
//         0044cbac     NOP
//         0044cbad     NOP
//         0044cbae     NOP
//         0044cbaf     NOP
    return 0;
}

long RGE_Campaign_Info::get_current_scenario() {
    /* TODO: Stub */
//                              long __thiscall get_current_scenario(RGE_Campaign_Info * this)
//              long              EAX:4          <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//                               ?get_current_scenario@RGE_Campaign_Info@@QAEJXZ              XREF[1]:     get_current_scenario:0044d0e3(c)
//                               RGE_Campaign_Info::get_current_scenario
//                              gameinfo.cpp:236 (6)
//         0044cbb0     MOV        EAX,dword ptr [ECX + this->current_scenario]
//                              gameinfo.cpp:238 (1)
//         0044cbb6     RET
//         0044cbb7     ??         90h
//         0044cbb8     NOP
//         0044cbb9     NOP
//         0044cbba     NOP
//         0044cbbb     NOP
//         0044cbbc     NOP
//         0044cbbd     NOP
//         0044cbbe     NOP
//         0044cbbf     NOP
    return 0;
}

void RGE_Campaign_Info::notify_of_scenario_complete() {
    /* TODO: Stub */
//                              void __thiscall notify_of_scenario_complete(RGE_Campaign_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//                               ?notify_of_scenario_complete@RGE_Campaign_Info@@QAEXXZ       XREF[1]:     notify_of_scenario_complete:0044d1
//                               RGE_Campaign_Info::notify_of_scenario_complete
//                              gameinfo.cpp:242 (3)
//         0044cbc0     PUSH       ESI
//         0044cbc1     MOV        ESI,this
//                              gameinfo.cpp:243 (11)
//         0044cbc3     MOV        EAX,dword ptr [ESI + 0x100]
//         0044cbc9     CMP        EAX,-0x1
//         0044cbcc     JLE        LAB_0044cc1c
//                              gameinfo.cpp:245 (10)
//         0044cbce     MOV        this,dword ptr [ESI + 0x108]
//         0044cbd4     MOV        byte ptr [this->campaign_name[0] + EAX*0x1],0x1
//                              gameinfo.cpp:246 (14)
//         0044cbd8     MOV        EAX,dword ptr [ESI + 0x100]
//         0044cbde     CMP        dword ptr [ESI + 0x10c],EAX
//         0044cbe4     JG         LAB_0044cbf5
//                              gameinfo.cpp:248 (1)
//         0044cbe6     INC        EAX
//                              gameinfo.cpp:249 (14)
//         0044cbe7     MOV        this,ESI
//         0044cbe9     PUSH       EAX
//         0044cbea     MOV        dword ptr [ESI + 0x10c],EAX
//         0044cbf0     CALL       RGE_Campaign_Info::set_current_scenario          uchar set_current_scenario(RGE_Campaign_Info
//                               LAB_0044cbf5                                                 XREF[1]:     0044cbe4(j)
//                              gameinfo.cpp:252 (16)
//         0044cbf5     MOV        EAX,dword ptr [ESI + 0x104]
//         0044cbfb     MOV        this,dword ptr [ESI + 0x10c]
//         0044cc01     CMP        this,EAX
//         0044cc03     JL         LAB_0044cc0c
//                              gameinfo.cpp:253 (7)
//         0044cc05     DEC        EAX
//         0044cc06     MOV        dword ptr [ESI + 0x10c],EAX
//                               LAB_0044cc0c                                                 XREF[1]:     0044cc03(j)
//                              gameinfo.cpp:255 (16)
//         0044cc0c     MOV        EDX,dword ptr [ESI + 0x10c]
//         0044cc12     MOV        EAX,dword ptr [ESI + 0x108]
//         0044cc18     MOV        byte ptr [EDX + EAX*0x1],0x2
//                               LAB_0044cc1c                                                 XREF[1]:     0044cbcc(j)
//                              gameinfo.cpp:257 (2)
//         0044cc1c     POP        ESI
//         0044cc1d     RET
//         0044cc1e     ??         90h
//         0044cc1f     NOP
    return;
}

int RGE_Campaign_Info::open_scenario() {
    /* TODO: Stub */
//                              int __thiscall open_scenario(RGE_Campaign_Info * this)
//              int               EAX:4          <RETURN>
//              RGE_Campaign_I    ECX:4 (auto)   this
//                               ?open_scenario@RGE_Campaign_Info@@QAEHXZ                     XREF[1]:     open_scenario:0044d194(c)
//                               RGE_Campaign_Info::open_scenario
//                              gameinfo.cpp:261 (11)
//         0044cc20     MOV        EAX,dword ptr [ECX + this->current_scenario]
//         0044cc26     CMP        EAX,-0x1
//         0044cc29     JLE        LAB_0044cc38
//                              gameinfo.cpp:263 (12)
//         0044cc2b     MOV        this,dword ptr [ECX + this->campaign]
//         0044cc31     PUSH       EAX
//         0044cc32     CALL       RGE_Campaign::open_scenario                      int open_scenario(RGE_Campaign * this, long p
//                              gameinfo.cpp:265 (1)
//         0044cc37     RET
//                               LAB_0044cc38                                                 XREF[1]:     0044cc29(j)
//                              gameinfo.cpp:264 (3)
//         0044cc38     OR         EAX,0xffffffff
//                              gameinfo.cpp:265 (1)
//         0044cc3b     RET
//         0044cc3c     ??         90h
//         0044cc3d     NOP
//         0044cc3e     NOP
//         0044cc3f     NOP
    return 0;
}

RGE_Person_Info::RGE_Person_Info(int param_1, RGE_Campaign** param_2, long param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Person_Info(RGE_Person_Info * this, char *
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0044cd44(R)
//              RGE_Campaign *    Stack[0x8]:4   param_2                   XREF[1]:     0044cd77(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0044cd67(R)
//                               ??0RGE_Person_Info@@QAE@PADPAPAVRGE_Campaign@@J@Z            XREF[1]:     add_new_person:0044d791(c)
//                               RGE_Person_Info::RGE_Person_Info
//                              gameinfo.cpp:301 (4)
//         0044cd40     PUSH       ESI
//         0044cd41     MOV        EDX,this
//         0044cd43     PUSH       EDI
//                              gameinfo.cpp:302 (28)
//         0044cd44     MOV        EDI,dword ptr [ESP + param_1]
//         0044cd48     OR         this,0xffffffff
//         0044cd4b     XOR        EAX,EAX
//         0044cd4d     SCASB.RE   ES:EDI
//         0044cd4f     NOT        this
//         0044cd51     SUB        EDI,this
//         0044cd53     MOV        EAX,this
//         0044cd55     MOV        ESI,EDI
//         0044cd57     MOV        EDI,EDX
//         0044cd59     SHR        this,0x2
//         0044cd5c     MOVSD.REP  ES:EDI,ESI
//         0044cd5e     MOV        this,EAX
//                              gameinfo.cpp:304 (7)
//         0044cd60     XOR        EAX,EAX
//         0044cd62     AND        this,0x3
//         0044cd65     MOVSB.REP  ES:EDI,ESI
//                              gameinfo.cpp:306 (16)
//         0044cd67     MOV        this,dword ptr [ESP + param_3]
//         0044cd6b     MOV        dword ptr [EDX + 0x104],EAX
//         0044cd71     MOV        dword ptr [EDX + 0x108],EAX
//                              gameinfo.cpp:307 (10)
//         0044cd77     MOV        EAX,dword ptr [ESP + param_2]
//         0044cd7b     MOV        dword ptr [EDX + 0x110],EAX
//                              gameinfo.cpp:308 (23)
//         0044cd81     POP        EDI
//         0044cd82     MOV        dword ptr [EDX + 0x100],0xffffffff
//         0044cd8c     MOV        dword ptr [EDX + 0x10c],this
//         0044cd92     MOV        EAX,EDX
//         0044cd94     POP        ESI
//         0044cd95     RET        0xc
//         0044cd98     ??         90h
//         0044cd99     NOP
//         0044cd9a     NOP
//         0044cd9b     NOP
//         0044cd9c     NOP
//         0044cd9d     NOP
//         0044cd9e     NOP
//         0044cd9f     NOP
}

RGE_Person_Info::RGE_Person_Info(char* param_1, RGE_Campaign** param_2, long param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Person_Info(RGE_Person_Info * this, char *
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0044cd44(R)
//              RGE_Campaign *    Stack[0x8]:4   param_2                   XREF[1]:     0044cd77(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0044cd67(R)
//                               ??0RGE_Person_Info@@QAE@PADPAPAVRGE_Campaign@@J@Z            XREF[1]:     add_new_person:0044d791(c)
//                               RGE_Person_Info::RGE_Person_Info
//                              gameinfo.cpp:301 (4)
//         0044cd40     PUSH       ESI
//         0044cd41     MOV        EDX,this
//         0044cd43     PUSH       EDI
//                              gameinfo.cpp:302 (28)
//         0044cd44     MOV        EDI,dword ptr [ESP + param_1]
//         0044cd48     OR         this,0xffffffff
//         0044cd4b     XOR        EAX,EAX
//         0044cd4d     SCASB.RE   ES:EDI
//         0044cd4f     NOT        this
//         0044cd51     SUB        EDI,this
//         0044cd53     MOV        EAX,this
//         0044cd55     MOV        ESI,EDI
//         0044cd57     MOV        EDI,EDX
//         0044cd59     SHR        this,0x2
//         0044cd5c     MOVSD.REP  ES:EDI,ESI
//         0044cd5e     MOV        this,EAX
//                              gameinfo.cpp:304 (7)
//         0044cd60     XOR        EAX,EAX
//         0044cd62     AND        this,0x3
//         0044cd65     MOVSB.REP  ES:EDI,ESI
//                              gameinfo.cpp:306 (16)
//         0044cd67     MOV        this,dword ptr [ESP + param_3]
//         0044cd6b     MOV        dword ptr [EDX + 0x104],EAX
//         0044cd71     MOV        dword ptr [EDX + 0x108],EAX
//                              gameinfo.cpp:307 (10)
//         0044cd77     MOV        EAX,dword ptr [ESP + param_2]
//         0044cd7b     MOV        dword ptr [EDX + 0x110],EAX
//                              gameinfo.cpp:308 (23)
//         0044cd81     POP        EDI
//         0044cd82     MOV        dword ptr [EDX + 0x100],0xffffffff
//         0044cd8c     MOV        dword ptr [EDX + 0x10c],this
//         0044cd92     MOV        EAX,EDX
//         0044cd94     POP        ESI
//         0044cd95     RET        0xc
//         0044cd98     ??         90h
//         0044cd99     NOP
//         0044cd9a     NOP
//         0044cd9b     NOP
//         0044cd9c     NOP
//         0044cd9d     NOP
//         0044cd9e     NOP
//         0044cd9f     NOP
}

RGE_Person_Info::~RGE_Person_Info() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Person_Info(RGE_Person_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//                               ??1RGE_Person_Info@@QAE@XZ                                   XREF[2]:     ~RGE_Game_Info:0044d378(c),
//                               RGE_Person_Info::~RGE_Person_Info                                         remove_player:0044da6e(c)
//                              gameinfo.cpp:313 (3)
//         0044cda0     PUSH       EDI
//         0044cda1     MOV        EDI,this
//                              gameinfo.cpp:316 (10)
//         0044cda3     MOV        EAX,dword ptr [EDI + 0x108]
//         0044cda9     TEST       EAX,EAX
//         0044cdab     JZ         LAB_0044ce08
//                              gameinfo.cpp:318 (13)
//         0044cdad     MOV        EAX,dword ptr [EDI + 0x104]
//         0044cdb3     PUSH       EBX
//         0044cdb4     XOR        EBX,EBX
//         0044cdb6     TEST       EAX,EAX
//         0044cdb8     JLE        LAB_0044cde4
//                              gameinfo.cpp:313 (1)
//         0044cdba     PUSH       ESI
//                               LAB_0044cdbb                                                 XREF[1]:     0044cde1(j)
//                              gameinfo.cpp:319 (40)
//         0044cdbb     MOV        EAX,dword ptr [EDI + 0x108]
//         0044cdc1     MOV        ESI,dword ptr [EAX + EBX*0x4]
//         0044cdc4     TEST       ESI,ESI
//         0044cdc6     JZ         LAB_0044cdd8
//         0044cdc8     MOV        this,ESI
//         0044cdca     CALL       RGE_Campaign_Info::~RGE_Campaign_Info            void ~RGE_Campaign_Info(RGE_Campaign_Info * t
//         0044cdcf     PUSH       ESI
//         0044cdd0     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0044cdd5     ADD        ESP,0x4
//                               LAB_0044cdd8                                                 XREF[1]:     0044cdc6(j)
//         0044cdd8     MOV        EAX,dword ptr [EDI + 0x104]
//         0044cdde     INC        EBX
//         0044cddf     CMP        EBX,EAX
//         0044cde1     JL         LAB_0044cdbb
//                              gameinfo.cpp:313 (1)
//         0044cde3     POP        ESI
//                               LAB_0044cde4                                                 XREF[1]:     0044cdb8(j)
//                              gameinfo.cpp:320 (15)
//         0044cde4     MOV        this,dword ptr [EDI + 0x108]
//         0044cdea     PUSH       this
//         0044cdeb     CALL       free                                             undefined free()
//         0044cdf0     ADD        ESP,0x4
//                              gameinfo.cpp:321 (10)
//         0044cdf3     MOV        dword ptr [EDI + 0x108],0x0
//                              gameinfo.cpp:322 (11)
//         0044cdfd     MOV        dword ptr [EDI + 0x104],0x0
//         0044ce07     POP        EBX
//                               LAB_0044ce08                                                 XREF[1]:     0044cdab(j)
//                              gameinfo.cpp:324 (2)
//         0044ce08     POP        EDI
//         0044ce09     RET
//         0044ce0a     ??         90h
//         0044ce0b     NOP
//         0044ce0c     NOP
//         0044ce0d     NOP
//         0044ce0e     NOP
//         0044ce0f     NOP
}

void RGE_Person_Info::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Person_Info * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044ce27(R)
//                               ?save@RGE_Person_Info@@QAEXH@Z                               XREF[1]:     save:0044d448(c)
//                               RGE_Person_Info::save
//                              gameinfo.cpp:329 (23)
//         0044ce10     MOV        EAX,[L]                                          = 00000000
//         0044ce15     PUSH       EBX
//         0044ce16     PUSH       EBP
//         0044ce17     PUSH       ESI
//         0044ce18     PUSH       EDI
//         0044ce19     MOV        EDI,this
//         0044ce1b     PUSH       EDI
//         0044ce1c     PUSH       s_(PIF)Saving_player_-_%s                        = "(PIF)Saving player - %s"
//         0044ce21     PUSH       EAX
//         0044ce22     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              gameinfo.cpp:334 (22)
//         0044ce27     MOV        EBX,dword ptr [ESP + param_1]
//         0044ce2b     ADD        ESP,0xc
//         0044ce2e     PUSH       0xff
//         0044ce33     PUSH       EDI
//         0044ce34     PUSH       EBX
//         0044ce35     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044ce3a     ADD        ESP,0xc
//                              gameinfo.cpp:335 (18)
//         0044ce3d     LEA        this,[EDI + 0x100]
//         0044ce43     PUSH       0x4
//         0044ce45     PUSH       this
//         0044ce46     PUSH       EBX
//         0044ce47     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044ce4c     ADD        ESP,0xc
//                              gameinfo.cpp:336 (15)
//         0044ce4f     LEA        EBP,[EDI + 0x104]
//         0044ce55     PUSH       0x4
//         0044ce57     PUSH       EBP
//         0044ce58     PUSH       EBX
//         0044ce59     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              gameinfo.cpp:338 (12)
//         0044ce5e     MOV        EAX,dword ptr [EBP]
//         0044ce61     ADD        ESP,0xc
//         0044ce64     XOR        ESI,ESI
//         0044ce66     TEST       EAX,EAX
//         0044ce68     JLE        LAB_0044ce81
//                               LAB_0044ce6a                                                 XREF[1]:     0044ce7f(j)
//                              gameinfo.cpp:339 (23)
//         0044ce6a     MOV        EDX,dword ptr [EDI + 0x108]
//         0044ce70     PUSH       EBX
//         0044ce71     MOV        this,dword ptr [EDX + ESI*0x4]
//         0044ce74     CALL       RGE_Campaign_Info::save                          void save(RGE_Campaign_Info * this, int param
//         0044ce79     MOV        EAX,dword ptr [EBP]
//         0044ce7c     INC        ESI
//         0044ce7d     CMP        ESI,EAX
//         0044ce7f     JL         LAB_0044ce6a
//                               LAB_0044ce81                                                 XREF[1]:     0044ce68(j)
//                              gameinfo.cpp:340 (7)
//         0044ce81     POP        EDI
//         0044ce82     POP        ESI
//         0044ce83     POP        EBP
//         0044ce84     POP        EBX
//         0044ce85     RET        0x4
//         0044ce88     ??         90h
//         0044ce89     NOP
//         0044ce8a     NOP
//         0044ce8b     NOP
//         0044ce8c     NOP
//         0044ce8d     NOP
//         0044ce8e     NOP
//         0044ce8f     NOP
    return;
}

void RGE_Person_Info::rehook_campaigns(RGE_Campaign** param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall rehook_campaigns(RGE_Person_Info * this, RGE_Campaig
//              void              <VOID>         <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              RGE_Campaign *    Stack[0x4]:4   param_1                   XREF[1]:     0044ce98(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0044ce90(R)
//                               ?rehook_campaigns@RGE_Person_Info@@QAEXPAPAVRGE_Campaign@@J@Z XREF[1]:     find_campaigns:0044d6e9(c)
//                               RGE_Person_Info::rehook_campaigns
//                              gameinfo.cpp:344 (8)
//         0044ce90     MOV        EAX,dword ptr [ESP + param_2]
//         0044ce94     PUSH       ESI
//         0044ce95     MOV        ESI,this
//         0044ce97     PUSH       EDI
//                              gameinfo.cpp:348 (4)
//         0044ce98     MOV        this,dword ptr [ESP + param_1]
//                              gameinfo.cpp:350 (24)
//         0044ce9c     XOR        EDI,EDI
//         0044ce9e     MOV        dword ptr [ESI + 0x10c],EAX
//         0044cea4     MOV        EAX,dword ptr [ESI + 0x104]
//         0044ceaa     TEST       EAX,EAX
//         0044ceac     MOV        dword ptr [ESI + 0x110],this
//         0044ceb2     JLE        LAB_0044cedb
//                               LAB_0044ceb4                                                 XREF[1]:     0044ced9(j)
//                              gameinfo.cpp:351 (39)
//         0044ceb4     MOV        EDX,dword ptr [ESI + 0x10c]
//         0044ceba     MOV        this,dword ptr [ESI + 0x108]
//         0044cec0     MOV        EAX,dword ptr [ESI + 0x110]
//         0044cec6     PUSH       EDX
//         0044cec7     MOV        this,dword ptr [this->name[0] + EDI*0x4]
//         0044ceca     PUSH       EAX
//         0044cecb     CALL       RGE_Campaign_Info::rehook_campaigns              void rehook_campaigns(RGE_Campaign_Info * thi
//         0044ced0     MOV        EAX,dword ptr [ESI + 0x104]
//         0044ced6     INC        EDI
//         0044ced7     CMP        EDI,EAX
//         0044ced9     JL         LAB_0044ceb4
//                               LAB_0044cedb                                                 XREF[1]:     0044ceb2(j)
//                              gameinfo.cpp:352 (5)
//         0044cedb     POP        EDI
//         0044cedc     POP        ESI
//         0044cedd     RET        0x8
    return;
}

char* RGE_Person_Info::get_name() {
    /* TODO: Stub */
//                              char * __thiscall get_name(RGE_Person_Info * this)
//              char *            EAX:4          <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//                               ?get_name@RGE_Person_Info@@QAEPADXZ                          XREF[2]:     get_people_list:0044d885(c),
//                               RGE_Person_Info::get_name                                                 get_current_player_name:0044d9ef(c
//                              gameinfo.cpp:356 (2)
//         0044cee0     MOV        EAX,this
//                              gameinfo.cpp:358 (1)
//         0044cee2     RET
//         0044cee3     ??         90h
//         0044cee4     NOP
//         0044cee5     NOP
//         0044cee6     NOP
//         0044cee7     NOP
//         0044cee8     NOP
//         0044cee9     NOP
//         0044ceea     NOP
//         0044ceeb     NOP
//         0044ceec     NOP
//         0044ceed     NOP
//         0044ceee     NOP
//         0044ceef     NOP
    return 0;
}

uchar RGE_Person_Info::set_current_campaign(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall set_current_campaign(RGE_Person_Info * this, long p
//              uchar             AL:1           <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[4]:     0044cefe(R), 0044cf90(W), 0044cfbb(R), 0044cfd5(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044cfdb(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044d022(R)
//                               ?set_current_campaign@RGE_Person_Info@@QAEEJ@Z               XREF[1]:     set_current_campaign:0044d808(c)
//                               RGE_Person_Info::set_current_campaign
//                              gameinfo.cpp:365 (14)
//         0044cef0     MOV        EAX,FS:[0x0]
//         0044cef6     PUSH       -0x1
//         0044cef8     PUSH       FUN_0055d5ab
//         0044cefd     PUSH       EAX
//                              gameinfo.cpp:369 (60)
//         0044cefe     MOV        EAX,dword ptr [ESP + param_1]
//         0044cf02     MOV        dword ptr FS:[0x0],ESP
//         0044cf09     PUSH       EBX
//         0044cf0a     PUSH       EBP
//         0044cf0b     PUSH       ESI
//         0044cf0c     PUSH       EDI
//         0044cf0d     TEST       EAX,EAX
//         0044cf0f     MOV        EBX,this
//         0044cf11     JL         LAB_0044d020
//         0044cf17     CMP        EAX,dword ptr [EBX + 0x10c]
//         0044cf1d     JGE        LAB_0044d020
//         0044cf23     LEA        EBP,[EAX*0x4 + 0x0]
//         0044cf2a     MOV        EAX,dword ptr [EBX + 0x110]
//         0044cf30     CMP        dword ptr [EAX + EBP*0x1],0x0
//         0044cf34     JZ         LAB_0044d020
//                              gameinfo.cpp:372 (12)
//         0044cf3a     MOV        EAX,dword ptr [EBX + 0x104]
//         0044cf40     XOR        ESI,ESI
//         0044cf42     TEST       EAX,EAX
//         0044cf44     JLE        LAB_0044cf76
//                               LAB_0044cf46                                                 XREF[1]:     0044cf74(j)
//                              gameinfo.cpp:373 (48)
//         0044cf46     MOV        this,dword ptr [EBX + 0x110]
//         0044cf4c     MOV        this,dword ptr [this->name[0] + EBP*0x1]
//         0044cf4f     CALL       RGE_Campaign::get_name                           char * get_name(RGE_Campaign * this)
//         0044cf54     MOV        EDX,dword ptr [EBX + 0x108]
//         0044cf5a     PUSH       EAX
//         0044cf5b     MOV        this,dword ptr [EDX + ESI*0x4]
//         0044cf5e     CALL       RGE_Campaign_Info::verify_campaign_name          uchar verify_campaign_name(RGE_Campaign_Info
//         0044cf63     TEST       AL,AL
//         0044cf65     JNZ        LAB_0044d037
//         0044cf6b     MOV        EAX,dword ptr [EBX + 0x104]
//         0044cf71     INC        ESI
//         0044cf72     CMP        ESI,EAX
//         0044cf74     JL         LAB_0044cf46
//                               LAB_0044cf76                                                 XREF[1]:     0044cf44(j)
//                              gameinfo.cpp:380 (15)
//         0044cf76     MOV        EAX,dword ptr [EBX + 0x104]
//         0044cf7c     PUSH       0x4
//         0044cf7e     INC        EAX
//         0044cf7f     PUSH       EAX
//         0044cf80     CALL       calloc                                           undefined calloc()
//                              gameinfo.cpp:382 (17)
//         0044cf85     MOV        ESI,dword ptr [EBX + 0x108]
//         0044cf8b     ADD        ESP,0x8
//         0044cf8e     TEST       ESI,ESI
//         0044cf90     MOV        dword ptr [ESP + param_1],EAX
//         0044cf94     JZ         LAB_0044cfaf
//                              gameinfo.cpp:383 (25)
//         0044cf96     MOV        this,dword ptr [EBX + 0x104]
//         0044cf9c     MOV        EDI,EAX
//         0044cf9e     SHL        this,0x2
//         0044cfa1     MOV        EDX,this
//         0044cfa3     SHR        this,0x2
//         0044cfa6     MOVSD.REP  ES:EDI,ESI
//         0044cfa8     MOV        this,EDX
//         0044cfaa     AND        this,0x3
//         0044cfad     MOVSB.REP  ES:EDI,ESI
//                               LAB_0044cfaf                                                 XREF[1]:     0044cf94(j)
//                              gameinfo.cpp:385 (12)
//         0044cfaf     MOV        EAX,dword ptr [EBX + 0x108]
//         0044cfb5     PUSH       EAX
//         0044cfb6     CALL       free                                             undefined free()
//                              gameinfo.cpp:386 (13)
//         0044cfbb     MOV        this,dword ptr [ESP + param_1]
//         0044cfbf     ADD        ESP,0x4
//         0044cfc2     MOV        dword ptr [EBX + 0x108],this
//                              gameinfo.cpp:388 (65)
//         0044cfc8     PUSH       0x114
//         0044cfcd     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044cfd2     ADD        ESP,0x4
//         0044cfd5     MOV        dword ptr [ESP + param_1],EAX
//         0044cfd9     TEST       EAX,EAX
//         0044cfdb     MOV        dword ptr [ESP + local_4],0x0
//         0044cfe3     JZ         LAB_0044cff8
//         0044cfe5     MOV        EDX,dword ptr [EBX + 0x110]
//         0044cfeb     MOV        this,dword ptr [EDX + EBP*0x1]
//         0044cfee     PUSH       this
//         0044cfef     MOV        this,EAX
//         0044cff1     CALL       RGE_Campaign_Info::RGE_Campaign_Info             undefined RGE_Campaign_Info(RGE_Campaign_Info
//         0044cff6     JMP        LAB_0044cffa
//                               LAB_0044cff8                                                 XREF[1]:     0044cfe3(j)
//         0044cff8     XOR        EAX,EAX
//                               LAB_0044cffa                                                 XREF[1]:     0044cff6(j)
//         0044cffa     MOV        EDX,dword ptr [EBX + 0x104]
//         0044d000     MOV        this,dword ptr [EBX + 0x108]
//         0044d006     MOV        dword ptr [this->name[0] + EDX*0x4],EAX
//                              gameinfo.cpp:389 (12)
//         0044d009     MOV        EAX,dword ptr [EBX + 0x104]
//         0044d00f     MOV        dword ptr [EBX + 0x100],EAX
//                              gameinfo.cpp:391 (7)
//         0044d015     INC        EAX
//         0044d016     MOV        dword ptr [EBX + 0x104],EAX
//                              gameinfo.cpp:393 (4)
//         0044d01c     MOV        AL,0x1
//         0044d01e     JMP        LAB_0044d022
//                               LAB_0044d020                                                 XREF[3]:     0044cf11(j), 0044cf1d(j),
//                                                                                                         0044cf34(j)
//                              gameinfo.cpp:395 (2)
//         0044d020     XOR        AL,AL
//                               LAB_0044d022                                                 XREF[2]:     0044d01e(j), 0044d03f(j)
//                              gameinfo.cpp:396 (21)
//         0044d022     MOV        this,dword ptr [ESP + local_c]
//         0044d026     POP        EDI
//         0044d027     POP        ESI
//         0044d028     POP        EBP
//         0044d029     MOV        dword ptr FS:[0x0],this
//         0044d030     POP        EBX
//         0044d031     ADD        ESP,0xc
//         0044d034     RET        0x4
//                               LAB_0044d037                                                 XREF[1]:     0044cf65(j)
//                              gameinfo.cpp:375 (6)
//         0044d037     MOV        dword ptr [EBX + 0x100],ESI
//                              gameinfo.cpp:376 (4)
//         0044d03d     MOV        AL,0x1
//         0044d03f     JMP        LAB_0044d022
//         0044d041     ??         90h
//         0044d042     NOP
//         0044d043     NOP
//         0044d044     NOP
//         0044d045     NOP
//         0044d046     NOP
//         0044d047     NOP
//         0044d048     NOP
//         0044d049     NOP
//         0044d04a     NOP
//         0044d04b     NOP
//         0044d04c     NOP
//         0044d04d     NOP
//         0044d04e     NOP
//         0044d04f     NOP
    return 0;
}

long RGE_Person_Info::get_current_campaign() {
    /* TODO: Stub */
//                              long __thiscall get_current_campaign(RGE_Person_Info * this)
//              long              EAX:4          <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//                               ?get_current_campaign@RGE_Person_Info@@QAEJXZ                XREF[2]:     get_campaign_list:0044d924(c),
//                               RGE_Person_Info::get_current_campaign                                     get_current_campaign:0044d9c3(c)
//                              gameinfo.cpp:400 (4)
//         0044d050     PUSH       ESI
//         0044d051     MOV        ESI,this
//         0044d053     PUSH       EDI
//                              gameinfo.cpp:404 (18)
//         0044d054     MOV        EAX,dword ptr [ESI + 0x100]
//         0044d05a     TEST       EAX,EAX
//         0044d05c     JL         LAB_0044d0af
//         0044d05e     CMP        EAX,dword ptr [ESI + 0x104]
//         0044d064     JGE        LAB_0044d0af
//                              gameinfo.cpp:405 (12)
//         0044d066     MOV        EAX,dword ptr [ESI + 0x10c]
//         0044d06c     XOR        EDI,EDI
//         0044d06e     TEST       EAX,EAX
//         0044d070     JLE        LAB_0044d0af
//                               LAB_0044d072                                                 XREF[1]:     0044d0a2(j)
//                              gameinfo.cpp:406 (50)
//         0044d072     MOV        EAX,dword ptr [ESI + 0x110]
//         0044d078     MOV        this,dword ptr [EAX + EDI*0x4]
//         0044d07b     CALL       RGE_Campaign::get_name                           char * get_name(RGE_Campaign * this)
//         0044d080     MOV        this,dword ptr [ESI + 0x100]
//         0044d086     MOV        EDX,dword ptr [ESI + 0x108]
//         0044d08c     PUSH       EAX
//         0044d08d     MOV        this,dword ptr [EDX + this->name[0]*0x4]
//         0044d090     CALL       RGE_Campaign_Info::verify_campaign_name          uchar verify_campaign_name(RGE_Campaign_Info
//         0044d095     TEST       AL,AL
//         0044d097     JNZ        LAB_0044d0aa
//         0044d099     MOV        EAX,dword ptr [ESI + 0x10c]
//         0044d09f     INC        EDI
//         0044d0a0     CMP        EDI,EAX
//         0044d0a2     JL         LAB_0044d072
//                              gameinfo.cpp:409 (3)
//         0044d0a4     OR         EAX,0xffffffff
//                              gameinfo.cpp:410 (3)
//         0044d0a7     POP        EDI
//         0044d0a8     POP        ESI
//         0044d0a9     RET
//                               LAB_0044d0aa                                                 XREF[1]:     0044d097(j)
//                              gameinfo.cpp:407 (2)
//         0044d0aa     MOV        EAX,EDI
//                              gameinfo.cpp:410 (9)
//         0044d0ac     POP        EDI
//         0044d0ad     POP        ESI
//         0044d0ae     RET
//                               LAB_0044d0af                                                 XREF[3]:     0044d05c(j), 0044d064(j),
//                                                                                                         0044d070(j)
//         0044d0af     POP        EDI
//         0044d0b0     OR         EAX,0xffffffff
//         0044d0b3     POP        ESI
//         0044d0b4     RET
//         0044d0b5     ??         90h
//         0044d0b6     NOP
//         0044d0b7     NOP
//         0044d0b8     NOP
//         0044d0b9     NOP
//         0044d0ba     NOP
//         0044d0bb     NOP
//         0044d0bc     NOP
//         0044d0bd     NOP
//         0044d0be     NOP
//         0044d0bf     NOP
    return 0;
}

long RGE_Person_Info::get_current_scenario() {
    /* TODO: Stub */
//                              long __thiscall get_current_scenario(RGE_Person_Info * this)
//              long              EAX:4          <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//                               ?get_current_scenario@RGE_Person_Info@@QAEJXZ                XREF[2]:     get_scenario_list:0044d956(c),
//                               RGE_Person_Info::get_current_scenario                                     get_current_scenario:0044d9a3(c)
//                              gameinfo.cpp:414 (26)
//         0044d0c0     MOV        EAX,dword ptr [ECX + this->current_campaign]
//         0044d0c6     CMP        EAX,-0x1
//         0044d0c9     JLE        LAB_0044d0e9
//         0044d0cb     MOV        EDX,dword ptr [ECX + this->campaigns]
//         0044d0d1     SHL        EAX,0x2
//         0044d0d4     CMP        dword ptr [EDX + EAX*0x1],0x0
//         0044d0d8     JZ         LAB_0044d0e9
//                              gameinfo.cpp:416 (14)
//         0044d0da     MOV        this,dword ptr [ECX + this->campaign_info]
//         0044d0e0     MOV        this,dword ptr [this->name[0] + EAX*0x1]
//         0044d0e3     CALL       RGE_Campaign_Info::get_current_scenario          long get_current_scenario(RGE_Campaign_Info *
//                              gameinfo.cpp:418 (1)
//         0044d0e8     RET
//                               LAB_0044d0e9                                                 XREF[2]:     0044d0c9(j), 0044d0d8(j)
//                              gameinfo.cpp:417 (3)
//         0044d0e9     OR         EAX,0xffffffff
//                              gameinfo.cpp:418 (1)
//         0044d0ec     RET
//         0044d0ed     ??         90h
//         0044d0ee     NOP
//         0044d0ef     NOP
    return 0;
}

uchar RGE_Person_Info::set_current_scenario(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall set_current_scenario(RGE_Person_Info * this, long p
//              uchar             AL:1           <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0044d110(R)
//                               ?set_current_scenario@RGE_Person_Info@@QAEEJ@Z               XREF[1]:     set_current_scenario:0044d836(c)
//                               RGE_Person_Info::set_current_scenario
//                              gameinfo.cpp:423 (26)
//         0044d0f0     MOV        EAX,dword ptr [ECX + this->current_campaign]
//         0044d0f6     CMP        EAX,-0x1
//         0044d0f9     JLE        LAB_0044d120
//         0044d0fb     MOV        EDX,dword ptr [ECX + this->campaigns]
//         0044d101     SHL        EAX,0x2
//         0044d104     CMP        dword ptr [EDX + EAX*0x1],0x0
//         0044d108     JZ         LAB_0044d120
//                              gameinfo.cpp:425 (19)
//         0044d10a     MOV        this,dword ptr [ECX + this->campaign_info]
//         0044d110     MOV        EDX,dword ptr [ESP + param_1]
//         0044d114     PUSH       EDX
//         0044d115     MOV        this,dword ptr [this->name[0] + EAX*0x1]
//         0044d118     CALL       RGE_Campaign_Info::set_current_scenario          uchar set_current_scenario(RGE_Campaign_Info
//                              gameinfo.cpp:427 (3)
//         0044d11d     RET        0x4
//                               LAB_0044d120                                                 XREF[2]:     0044d0f9(j), 0044d108(j)
//                              gameinfo.cpp:426 (2)
//         0044d120     XOR        AL,AL
//                              gameinfo.cpp:427 (3)
//         0044d122     RET        0x4
//         0044d125     ??         90h
//         0044d126     NOP
//         0044d127     NOP
//         0044d128     NOP
//         0044d129     NOP
//         0044d12a     NOP
//         0044d12b     NOP
//         0044d12c     NOP
//         0044d12d     NOP
//         0044d12e     NOP
//         0044d12f     NOP
    return 0;
}

long RGE_Person_Info::get_scenario_list(char*** param_1, long* param_2) {
    /* TODO: Stub */
//                              long __thiscall get_scenario_list(RGE_Person_Info * this, char * * *
//              long              EAX:4          <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//              char * * *        Stack[0x4]:4   param_1                   XREF[1]:     0044d146(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     0044d13b(R)
//                               ?get_scenario_list@RGE_Person_Info@@QAEJPAPAPADAAJ@Z         XREF[1]:     get_scenario_list:0044d96f(c)
//                               RGE_Person_Info::get_scenario_list
//                              gameinfo.cpp:432 (11)
//         0044d130     MOV        EAX,dword ptr [ECX + this->current_campaign]
//         0044d136     CMP        EAX,-0x1
//         0044d139     JLE        LAB_0044d156
//                              gameinfo.cpp:434 (24)
//         0044d13b     MOV        EDX,dword ptr [ESP + param_2]
//         0044d13f     MOV        this,dword ptr [ECX + this->campaign_info]
//         0044d145     PUSH       EDX
//         0044d146     MOV        EDX,dword ptr [ESP + param_1]
//         0044d14a     MOV        this,dword ptr [this->name[0] + EAX*0x4]
//         0044d14d     PUSH       EDX
//         0044d14e     CALL       RGE_Campaign_Info::get_scenario_list             long get_scenario_list(RGE_Campaign_Info * th
//                              gameinfo.cpp:436 (3)
//         0044d153     RET        0x8
//                               LAB_0044d156                                                 XREF[1]:     0044d139(j)
//                              gameinfo.cpp:435 (2)
//         0044d156     XOR        EAX,EAX
//                              gameinfo.cpp:436 (3)
//         0044d158     RET        0x8
//         0044d15b     ??         90h
//         0044d15c     NOP
//         0044d15d     NOP
//         0044d15e     NOP
//         0044d15f     NOP
    return 0;
}

void RGE_Person_Info::notify_of_scenario_complete() {
    /* TODO: Stub */
//                              void __thiscall notify_of_scenario_complete(RGE_Person_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//                               ?notify_of_scenario_complete@RGE_Person_Info@@QAEXXZ         XREF[1]:     notify_of_scenario_complete:0044da
//                               RGE_Person_Info::notify_of_scenario_complete
//                              gameinfo.cpp:440 (11)
//         0044d160     MOV        EAX,dword ptr [ECX + this->current_campaign]
//         0044d166     CMP        EAX,-0x1
//         0044d169     JLE        LAB_0044d179
//                              gameinfo.cpp:442 (14)
//         0044d16b     MOV        this,dword ptr [ECX + this->campaign_info]
//         0044d171     MOV        this,dword ptr [this->name[0] + EAX*0x4]
//         0044d174     JMP        RGE_Campaign_Info::notify_of_scenario_complete   void notify_of_scenario_complete(RGE_Campaign
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0044d179                                                 XREF[1]:     0044d169(j)
//                              gameinfo.cpp:443 (1)
//         0044d179     RET
//         0044d17a     ??         90h
//         0044d17b     NOP
//         0044d17c     NOP
//         0044d17d     NOP
//         0044d17e     NOP
//         0044d17f     NOP
    return;
}

int RGE_Person_Info::open_scenario() {
    /* TODO: Stub */
//                              int __thiscall open_scenario(RGE_Person_Info * this)
//              int               EAX:4          <RETURN>
//              RGE_Person_Inf    ECX:4 (auto)   this
//                               ?open_scenario@RGE_Person_Info@@QAEHXZ                       XREF[1]:     open_scenario:0044da43(c)
//                               RGE_Person_Info::open_scenario
//                              gameinfo.cpp:447 (11)
//         0044d180     MOV        EAX,dword ptr [ECX + this->current_campaign]
//         0044d186     CMP        EAX,-0x1
//         0044d189     JLE        LAB_0044d199
//                              gameinfo.cpp:449 (14)
//         0044d18b     MOV        this,dword ptr [ECX + this->campaign_info]
//         0044d191     MOV        this,dword ptr [this->name[0] + EAX*0x4]
//         0044d194     JMP        RGE_Campaign_Info::open_scenario                 int open_scenario(RGE_Campaign_Info * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0044d199                                                 XREF[1]:     0044d189(j)
//                              gameinfo.cpp:450 (3)
//         0044d199     OR         EAX,0xffffffff
//                              gameinfo.cpp:451 (1)
//         0044d19c     RET
//         0044d19d     ??         90h
//         0044d19e     NOP
//         0044d19f     NOP
    return 0;
}

RGE_Game_Info::RGE_Game_Info(char* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Game_Info(RGE_Game_Info * this, char * para
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[4]:     0044d1d2(R), 0044d1e8(W), 0044d1ee(R), 0044d27b(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044d281(W), 0044d2a3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044d2e3(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0044d217(*), 0044d224(R)
//              long              Stack[-0x14]:4 version
//                               ??0RGE_Game_Info@@QAE@PAD@Z                                  XREF[2]:     setup:0041c054(c),
//                               RGE_Game_Info::RGE_Game_Info                                              setup:0041c0ce(c)
//                              gameinfo.cpp:467 (27)
//         0044d1a0     PUSH       -0x1
//         0044d1a2     PUSH       FUN_0055d5cb
//         0044d1a7     MOV        EAX,FS:[0x0]
//         0044d1ad     PUSH       EAX
//         0044d1ae     MOV        dword ptr FS:[0x0],ESP
//         0044d1b5     PUSH       this
//         0044d1b6     PUSH       EBX
//         0044d1b7     MOV        EBX,this
//         0044d1b9     PUSH       EBP
//         0044d1ba     PUSH       ESI
//                              gameinfo.cpp:472 (6)
//         0044d1bb     LEA        EBP,[EBX + 0x4]
//         0044d1be     XOR        EAX,EAX
//         0044d1c0     PUSH       EDI
//                              gameinfo.cpp:473 (6)
//         0044d1c1     MOV        dword ptr [EBX + 0x8],EAX
//         0044d1c4     MOV        dword ptr [EBP],EAX
//                              gameinfo.cpp:474 (3)
//         0044d1c7     MOV        dword ptr [EBX + 0xc],EAX
//                              gameinfo.cpp:475 (3)
//         0044d1ca     MOV        dword ptr [EBX + 0x10],EAX
//                              gameinfo.cpp:478 (5)
//         0044d1cd     CALL       RGE_Game_Info::find_campaigns                    void find_campaigns(RGE_Game_Info * this)
//                              gameinfo.cpp:481 (39)
//         0044d1d2     MOV        EDX,dword ptr [ESP + param_1]
//         0044d1d6     OR         this,0xffffffff
//         0044d1d9     MOV        EDI,EDX
//         0044d1db     XOR        EAX,EAX
//         0044d1dd     SCASB.RE   ES:EDI
//         0044d1df     NOT        this
//         0044d1e1     LEA        ESI,[EBX + 0x14]
//         0044d1e4     SUB        EDI,this
//         0044d1e6     MOV        EAX,this
//         0044d1e8     MOV        dword ptr [ESP + param_1],ESI
//         0044d1ec     MOV        ESI,EDI
//         0044d1ee     MOV        EDI,dword ptr [ESP + param_1]
//         0044d1f2     SHR        this,0x2
//         0044d1f5     MOVSD.REP  ES:EDI,ESI
//         0044d1f7     MOV        this,EAX
//                              gameinfo.cpp:482 (21)
//         0044d1f9     PUSH       0x8000
//         0044d1fe     AND        this,0x3
//         0044d201     PUSH       EDX
//         0044d202     MOVSB.REP  ES:EDI,ESI
//         0044d204     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
//         0044d209     MOV        EDI,EAX
//         0044d20b     ADD        ESP,0x8
//                              gameinfo.cpp:483 (9)
//         0044d20e     CMP        EDI,-0x1
//         0044d211     JLE        LAB_0044d2cf
//                              gameinfo.cpp:485 (13)
//         0044d217     LEA        this=>local_10,[ESP + 0x10]
//         0044d21b     PUSH       0x4
//         0044d21d     PUSH       this
//         0044d21e     PUSH       EDI
//         0044d21f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              gameinfo.cpp:486 (20)
//         0044d224     MOV        EDX,dword ptr [ESP + local_10]
//         0044d228     MOV        EAX,[s_1.00]                                     = "1.00"
//         0044d22d     ADD        ESP,0xc
//         0044d230     CMP        EDX,EAX
//         0044d232     JNZ        LAB_0044d2cf
//                              gameinfo.cpp:488 (12)
//         0044d238     PUSH       0x4
//         0044d23a     PUSH       EBX
//         0044d23b     PUSH       EDI
//         0044d23c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044d241     ADD        ESP,0xc
//                              gameinfo.cpp:489 (9)
//         0044d244     PUSH       0x4
//         0044d246     PUSH       EBP
//         0044d247     PUSH       EDI
//         0044d248     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              gameinfo.cpp:490 (12)
//         0044d24d     MOV        EAX,dword ptr [EBP]
//         0044d250     XOR        ESI,ESI
//         0044d252     ADD        ESP,0xc
//         0044d255     CMP        EAX,ESI
//         0044d257     JLE        LAB_0044d2c1
//                              gameinfo.cpp:492 (11)
//         0044d259     PUSH       0x4
//         0044d25b     PUSH       EAX
//         0044d25c     CALL       calloc                                           undefined calloc()
//         0044d261     MOV        dword ptr [EBX + 0x8],EAX
//                              gameinfo.cpp:493 (10)
//         0044d264     MOV        EAX,dword ptr [EBP]
//         0044d267     ADD        ESP,0x8
//         0044d26a     TEST       EAX,EAX
//         0044d26c     JLE        LAB_0044d2c4
//                               LAB_0044d26e                                                 XREF[1]:     0044d2b4(j)
//                              gameinfo.cpp:494 (72)
//         0044d26e     PUSH       0x114
//         0044d273     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044d278     ADD        ESP,0x4
//         0044d27b     MOV        dword ptr [ESP + param_1],EAX
//         0044d27f     TEST       EAX,EAX
//         0044d281     MOV        dword ptr [ESP + local_4],0x0
//         0044d289     JZ         LAB_0044d29d
//         0044d28b     MOV        this,dword ptr [EBX + 0xc]
//         0044d28e     MOV        EDX,dword ptr [EBX + 0x10]
//         0044d291     PUSH       this
//         0044d292     PUSH       EDX
//         0044d293     PUSH       EDI
//         0044d294     MOV        this,EAX
//         0044d296     CALL       RGE_Person_Info::RGE_Person_Info                 undefined RGE_Person_Info(RGE_Person_Info * t
//         0044d29b     JMP        LAB_0044d29f
//                               LAB_0044d29d                                                 XREF[1]:     0044d289(j)
//         0044d29d     XOR        EAX,EAX
//                               LAB_0044d29f                                                 XREF[1]:     0044d29b(j)
//         0044d29f     MOV        this,dword ptr [EBX + 0x8]
//         0044d2a2     INC        ESI
//         0044d2a3     MOV        dword ptr [ESP + local_4],0xffffffff
//         0044d2ab     MOV        dword ptr [this->current_person + ESI*0x4 + -0
//         0044d2af     MOV        EAX,dword ptr [EBP]
//         0044d2b2     CMP        ESI,EAX
//         0044d2b4     JL         LAB_0044d26e
//                              gameinfo.cpp:499 (9)
//         0044d2b6     PUSH       EDI
//         0044d2b7     CALL       rge_close                                        int rge_close(int param_1)
//         0044d2bc     ADD        ESP,0x4
//                              gameinfo.cpp:500 (2)
//         0044d2bf     JMP        LAB_0044d2e3
//                               LAB_0044d2c1                                                 XREF[1]:     0044d257(j)
//                              gameinfo.cpp:497 (3)
//         0044d2c1     MOV        dword ptr [EBX + 0x8],ESI
//                               LAB_0044d2c4                                                 XREF[1]:     0044d26c(j)
//                              gameinfo.cpp:499 (9)
//         0044d2c4     PUSH       EDI
//         0044d2c5     CALL       rge_close                                        int rge_close(int param_1)
//         0044d2ca     ADD        ESP,0x4
//                              gameinfo.cpp:500 (2)
//         0044d2cd     JMP        LAB_0044d2e3
//                               LAB_0044d2cf                                                 XREF[2]:     0044d211(j), 0044d232(j)
//                              gameinfo.cpp:504 (6)
//         0044d2cf     MOV        dword ptr [EBX],0xffffffff
//                              gameinfo.cpp:505 (7)
//         0044d2d5     MOV        dword ptr [EBP],0x0
//                              gameinfo.cpp:506 (7)
//         0044d2dc     MOV        dword ptr [EBX + 0x8],0x0
//                               LAB_0044d2e3                                                 XREF[2]:     0044d2bf(j), 0044d2cd(j)
//                              gameinfo.cpp:507 (23)
//         0044d2e3     MOV        this,dword ptr [ESP + local_c]
//         0044d2e7     POP        EDI
//         0044d2e8     POP        ESI
//         0044d2e9     MOV        EAX,EBX
//         0044d2eb     POP        EBP
//         0044d2ec     MOV        dword ptr FS:[0x0],this
//         0044d2f3     POP        EBX
//         0044d2f4     ADD        ESP,0x10
//         0044d2f7     RET        0x4
//         0044d2fa     ??         90h
//         0044d2fb     NOP
//         0044d2fc     NOP
//         0044d2fd     NOP
//         0044d2fe     NOP
//         0044d2ff     NOP
}

RGE_Game_Info::~RGE_Game_Info() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Game_Info(RGE_Game_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ??1RGE_Game_Info@@QAE@XZ                                     XREF[1]:     ~RGE_Base_Game:0041c450(c)
//                               RGE_Game_Info::~RGE_Game_Info
//                              gameinfo.cpp:512 (5)
//         0044d300     PUSH       EBP
//         0044d301     PUSH       ESI
//         0044d302     MOV        ESI,this
//         0044d304     PUSH       EDI
//                              gameinfo.cpp:515 (10)
//         0044d305     MOV        this,byte ptr [ESI + 0x14]
//         0044d308     LEA        EAX,[ESI + 0x14]
//         0044d30b     TEST       this,this
//         0044d30d     JZ         LAB_0044d317
//                              gameinfo.cpp:516 (8)
//         0044d30f     PUSH       EAX
//         0044d310     MOV        this,ESI
//         0044d312     CALL       RGE_Game_Info::save                              void save(RGE_Game_Info * this, char * param_1)
//                               LAB_0044d317                                                 XREF[1]:     0044d30d(j)
//                              gameinfo.cpp:518 (7)
//         0044d317     MOV        EAX,dword ptr [ESI + 0x10]
//         0044d31a     TEST       EAX,EAX
//         0044d31c     JZ         LAB_0044d35c
//                              gameinfo.cpp:520 (9)
//         0044d31e     MOV        EAX,dword ptr [ESI + 0xc]
//         0044d321     XOR        EBP,EBP
//         0044d323     TEST       EAX,EAX
//         0044d325     JLE        LAB_0044d349
//                               LAB_0044d327                                                 XREF[1]:     0044d347(j)
//                              gameinfo.cpp:521 (34)
//         0044d327     MOV        EAX,dword ptr [ESI + 0x10]
//         0044d32a     MOV        EDI,dword ptr [EAX + EBP*0x4]
//         0044d32d     TEST       EDI,EDI
//         0044d32f     JZ         LAB_0044d341
//         0044d331     MOV        this,EDI
//         0044d333     CALL       RGE_Campaign::~RGE_Campaign                      void ~RGE_Campaign(RGE_Campaign * this)
//         0044d338     PUSH       EDI
//         0044d339     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0044d33e     ADD        ESP,0x4
//                               LAB_0044d341                                                 XREF[1]:     0044d32f(j)
//         0044d341     MOV        EAX,dword ptr [ESI + 0xc]
//         0044d344     INC        EBP
//         0044d345     CMP        EBP,EAX
//         0044d347     JL         LAB_0044d327
//                               LAB_0044d349                                                 XREF[1]:     0044d325(j)
//                              gameinfo.cpp:522 (12)
//         0044d349     MOV        this,dword ptr [ESI + 0x10]
//         0044d34c     PUSH       this
//         0044d34d     CALL       free                                             undefined free()
//         0044d352     ADD        ESP,0x4
//                              gameinfo.cpp:523 (7)
//         0044d355     MOV        dword ptr [ESI + 0x10],0x0
//                               LAB_0044d35c                                                 XREF[1]:     0044d31c(j)
//                              gameinfo.cpp:526 (7)
//         0044d35c     MOV        EAX,dword ptr [ESI + 0x8]
//         0044d35f     TEST       EAX,EAX
//         0044d361     JZ         LAB_0044d3a1
//                              gameinfo.cpp:528 (9)
//         0044d363     MOV        EAX,dword ptr [ESI + 0x4]
//         0044d366     XOR        EBP,EBP
//         0044d368     TEST       EAX,EAX
//         0044d36a     JLE        LAB_0044d38e
//                               LAB_0044d36c                                                 XREF[1]:     0044d38c(j)
//                              gameinfo.cpp:529 (34)
//         0044d36c     MOV        EDX,dword ptr [ESI + 0x8]
//         0044d36f     MOV        EDI,dword ptr [EDX + EBP*0x4]
//         0044d372     TEST       EDI,EDI
//         0044d374     JZ         LAB_0044d386
//         0044d376     MOV        this,EDI
//         0044d378     CALL       RGE_Person_Info::~RGE_Person_Info                void ~RGE_Person_Info(RGE_Person_Info * this)
//         0044d37d     PUSH       EDI
//         0044d37e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0044d383     ADD        ESP,0x4
//                               LAB_0044d386                                                 XREF[1]:     0044d374(j)
//         0044d386     MOV        EAX,dword ptr [ESI + 0x4]
//         0044d389     INC        EBP
//         0044d38a     CMP        EBP,EAX
//         0044d38c     JL         LAB_0044d36c
//                               LAB_0044d38e                                                 XREF[1]:     0044d36a(j)
//                              gameinfo.cpp:530 (12)
//         0044d38e     MOV        EAX,dword ptr [ESI + 0x8]
//         0044d391     PUSH       EAX
//         0044d392     CALL       free                                             undefined free()
//         0044d397     ADD        ESP,0x4
//                              gameinfo.cpp:531 (7)
//         0044d39a     MOV        dword ptr [ESI + 0x8],0x0
//                               LAB_0044d3a1                                                 XREF[1]:     0044d361(j)
//                              gameinfo.cpp:533 (4)
//         0044d3a1     POP        EDI
//         0044d3a2     POP        ESI
//         0044d3a3     POP        EBP
//         0044d3a4     RET
//         0044d3a5     ??         90h
//         0044d3a6     NOP
//         0044d3a7     NOP
//         0044d3a8     NOP
//         0044d3a9     NOP
//         0044d3aa     NOP
//         0044d3ab     NOP
//         0044d3ac     NOP
//         0044d3ad     NOP
//         0044d3ae     NOP
//         0044d3af     NOP
}

void RGE_Game_Info::save(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Game_Info * this, char * param_1)
//              void              <VOID>         <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0044d3c6(R)
//                               ?save@RGE_Game_Info@@QAEXPAD@Z                               XREF[3]:     ~RGE_Base_Game:0041c442(c),
//                               RGE_Game_Info::save                                                       ~RGE_Game_Info:0044d312(c),
//                                                                                                         notify_of_scenario_complete:0044da
//                              gameinfo.cpp:538 (22)
//         0044d3b0     MOV        EAX,[L]                                          = 00000000
//         0044d3b5     PUSH       EBX
//         0044d3b6     PUSH       EBP
//         0044d3b7     PUSH       ESI
//         0044d3b8     PUSH       EDI
//         0044d3b9     PUSH       s_(PIF)Creating_Player_Info_File                 = "(PIF)Creating Player Info File"
//         0044d3be     MOV        EBX,this
//         0044d3c0     PUSH       EAX
//         0044d3c1     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              gameinfo.cpp:544 (23)
//         0044d3c6     MOV        EDX,dword ptr [ESP + param_1]
//         0044d3ca     OR         this,0xffffffff
//         0044d3cd     MOV        EDI,EDX
//         0044d3cf     XOR        EAX,EAX
//         0044d3d1     ADD        ESP,0x8
//         0044d3d4     LEA        EBP,[EBX + 0x14]
//         0044d3d7     SCASB.RE   ES:EDI
//         0044d3d9     NOT        this
//         0044d3db     SUB        EDI,this
//                              gameinfo.cpp:545 (44)
//         0044d3dd     PUSH       0x180
//         0044d3e2     MOV        EAX,this
//         0044d3e4     MOV        ESI,EDI
//         0044d3e6     MOV        EDI,EBP
//         0044d3e8     PUSH       0x8309
//         0044d3ed     SHR        this,0x2
//         0044d3f0     MOVSD.REP  ES:EDI,ESI
//         0044d3f2     MOV        this,EAX
//         0044d3f4     PUSH       EDX
//         0044d3f5     AND        this,0x3
//         0044d3f8     MOVSB.REP  ES:EDI,ESI
//         0044d3fa     CALL       rge_open                                         int rge_open(char * param_1, int param_2, int
//         0044d3ff     MOV        EDI,EAX
//         0044d401     ADD        ESP,0xc
//         0044d404     CMP        EDI,-0x1
//         0044d407     JZ         LAB_0044d45e
//                              gameinfo.cpp:547 (16)
//         0044d409     PUSH       0x4
//         0044d40b     PUSH       s_1.00                                           = "1.00"
//         0044d410     PUSH       EDI
//         0044d411     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044d416     ADD        ESP,0xc
//                              gameinfo.cpp:549 (12)
//         0044d419     PUSH       0x4
//         0044d41b     PUSH       EBX
//         0044d41c     PUSH       EDI
//         0044d41d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044d422     ADD        ESP,0xc
//                              gameinfo.cpp:550 (12)
//         0044d425     LEA        EBP,[EBX + 0x4]
//         0044d428     PUSH       0x4
//         0044d42a     PUSH       EBP
//         0044d42b     PUSH       EDI
//         0044d42c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              gameinfo.cpp:551 (10)
//         0044d431     MOV        EAX,dword ptr [EBP]
//         0044d434     ADD        ESP,0xc
//         0044d437     TEST       EAX,EAX
//         0044d439     JLE        LAB_0044d455
//                              gameinfo.cpp:552 (6)
//         0044d43b     XOR        ESI,ESI
//         0044d43d     TEST       EAX,EAX
//         0044d43f     JLE        LAB_0044d455
//                               LAB_0044d441                                                 XREF[1]:     0044d453(j)
//                              gameinfo.cpp:553 (20)
//         0044d441     MOV        this,dword ptr [EBX + 0x8]
//         0044d444     PUSH       EDI
//         0044d445     MOV        this,dword ptr [this->current_person + ESI*0x4]
//         0044d448     CALL       RGE_Person_Info::save                            void save(RGE_Person_Info * this, int param_1)
//         0044d44d     MOV        EAX,dword ptr [EBP]
//         0044d450     INC        ESI
//         0044d451     CMP        ESI,EAX
//         0044d453     JL         LAB_0044d441
//                               LAB_0044d455                                                 XREF[2]:     0044d439(j), 0044d43f(j)
//                              gameinfo.cpp:554 (9)
//         0044d455     PUSH       EDI
//         0044d456     CALL       rge_close                                        int rge_close(int param_1)
//         0044d45b     ADD        ESP,0x4
//                               LAB_0044d45e                                                 XREF[1]:     0044d407(j)
//                              gameinfo.cpp:556 (7)
//         0044d45e     POP        EDI
//         0044d45f     POP        ESI
//         0044d460     POP        EBP
//         0044d461     POP        EBX
//         0044d462     RET        0x4
//         0044d465     ??         90h
//         0044d466     NOP
//         0044d467     NOP
//         0044d468     NOP
//         0044d469     NOP
//         0044d46a     NOP
//         0044d46b     NOP
//         0044d46c     NOP
//         0044d46d     NOP
//         0044d46e     NOP
//         0044d46f     NOP
    return;
}

void RGE_Game_Info::find_campaigns() {
    /* TODO: Stub */
//                              void __thiscall find_campaigns(RGE_Game_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0044d5f5(W), 0044d615(W), 0044d68d(W), 0044d6a9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044d6f6(R)
//              char[260]         Stack[-0x114   file_name                 XREF[0,8]:   0044d4d8(*), 0044d4fa(*), 0044d536(*), 0044d558(*),
//                                                                                     0044d5a9(*), 0044d5cb(*), 0044d638(*), 0044d65b(*)
//              _finddata_t       Stack[-0x22c   file_info                 XREF[2,10]:  0044d5ef(W), 0044d687(W), 0044d4f6(*), 0044d51e(*),
//                                                                                     0044d554(*), 0044d576(*), 0044d5c7(*), 0044d61f(*),
//                                                                                     0044d657(*), 0044d6b7(*), 0044d602(*), 0044d696(*)
//                               ?find_campaigns@RGE_Game_Info@@QAEXXZ                        XREF[2]:     find_campaigns:004226a3(c),
//                               RGE_Game_Info::find_campaigns                                             RGE_Game_Info:0044d1cd(c)
//                              gameinfo.cpp:561 (32)
//         0044d470     MOV        EAX,FS:[0x0]
//         0044d476     PUSH       -0x1
//         0044d478     PUSH       FUN_0055d5fc
//         0044d47d     PUSH       EAX
//         0044d47e     MOV        dword ptr FS:[0x0],ESP
//         0044d485     SUB        ESP,0x220
//         0044d48b     PUSH       EBX
//         0044d48c     PUSH       EBP
//         0044d48d     PUSH       ESI
//         0044d48e     MOV        ESI,this
//                              gameinfo.cpp:568 (8)
//         0044d490     XOR        EBP,EBP
//         0044d492     PUSH       EDI
//         0044d493     CMP        dword ptr [ESI + 0x10],EBP
//         0044d496     JZ         LAB_0044d4d2
//                              gameinfo.cpp:570 (9)
//         0044d498     MOV        EAX,dword ptr [ESI + 0xc]
//         0044d49b     XOR        EBX,EBX
//         0044d49d     CMP        EAX,EBP
//         0044d49f     JLE        LAB_0044d4c3
//                               LAB_0044d4a1                                                 XREF[1]:     0044d4c1(j)
//                              gameinfo.cpp:571 (34)
//         0044d4a1     MOV        EAX,dword ptr [ESI + 0x10]
//         0044d4a4     MOV        EDI,dword ptr [EAX + EBX*0x4]
//         0044d4a7     CMP        EDI,EBP
//         0044d4a9     JZ         LAB_0044d4bb
//         0044d4ab     MOV        this,EDI
//         0044d4ad     CALL       RGE_Campaign::~RGE_Campaign                      void ~RGE_Campaign(RGE_Campaign * this)
//         0044d4b2     PUSH       EDI
//         0044d4b3     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0044d4b8     ADD        ESP,0x4
//                               LAB_0044d4bb                                                 XREF[1]:     0044d4a9(j)
//         0044d4bb     MOV        EAX,dword ptr [ESI + 0xc]
//         0044d4be     INC        EBX
//         0044d4bf     CMP        EBX,EAX
//         0044d4c1     JL         LAB_0044d4a1
//                               LAB_0044d4c3                                                 XREF[1]:     0044d49f(j)
//                              gameinfo.cpp:572 (12)
//         0044d4c3     MOV        this,dword ptr [ESI + 0x10]
//         0044d4c6     PUSH       this
//         0044d4c7     CALL       free                                             undefined free()
//         0044d4cc     ADD        ESP,0x4
//                              gameinfo.cpp:573 (3)
//         0044d4cf     MOV        dword ptr [ESI + 0x10],EBP
//                               LAB_0044d4d2                                                 XREF[1]:     0044d496(j)
//                              gameinfo.cpp:577 (36)
//         0044d4d2     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0044d4d8     LEA        this=>file_name[4],[ESP + 0x12c]
//         0044d4df     MOV        EAX,dword ptr [EDX + 0xc]
//         0044d4e2     ADD        EAX,0xd1c
//         0044d4e7     PUSH       EAX
//         0044d4e8     PUSH       s_%s*.cpn                                        = "%s*.cpn"
//         0044d4ed     PUSH       this
//         0044d4ee     CALL       sprintf                                          undefined sprintf()
//         0044d4f3     ADD        ESP,0xc
//                              gameinfo.cpp:578 (18)
//         0044d4f6     LEA        EDX=>file_info.time_create,[ESP + 0x14]
//         0044d4fa     LEA        EAX=>file_name[4],[ESP + 0x12c]
//         0044d501     PUSH       EDX
//         0044d502     PUSH       EAX
//         0044d503     CALL       __findfirst                                      undefined __findfirst()
//                              gameinfo.cpp:579 (5)
//         0044d508     MOV        dword ptr [ESI + 0xc],EBP
//         0044d50b     MOV        EDI,EAX
//                              gameinfo.cpp:580 (10)
//         0044d50d     OR         EBP,0xffffffff
//         0044d510     ADD        ESP,0x8
//         0044d513     CMP        EDI,EBP
//         0044d515     JZ         LAB_0044d530
//                               LAB_0044d517                                                 XREF[1]:     0044d52e(j)
//                              gameinfo.cpp:582 (7)
//         0044d517     MOV        this,dword ptr [ESI + 0xc]
//         0044d51a     INC        this
//         0044d51b     MOV        dword ptr [ESI + 0xc],this
//                              gameinfo.cpp:583 (18)
//         0044d51e     LEA        this=>file_info.time_create,[ESP + 0x14]
//         0044d522     PUSH       this
//         0044d523     PUSH       EDI
//         0044d524     CALL       __findnext                                       undefined __findnext()
//         0044d529     ADD        ESP,0x8
//         0044d52c     CMP        EAX,EBP
//         0044d52e     JNZ        LAB_0044d517
//                               LAB_0044d530                                                 XREF[1]:     0044d515(j)
//                              gameinfo.cpp:588 (36)
//         0044d530     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0044d536     LEA        this=>file_name[4],[ESP + 0x12c]
//         0044d53d     MOV        EAX,dword ptr [EDX + 0xc]
//         0044d540     ADD        EAX,0xd1c
//         0044d545     PUSH       EAX
//         0044d546     PUSH       s_%s*.cpx                                        = "%s*.cpx"
//         0044d54b     PUSH       this
//         0044d54c     CALL       sprintf                                          undefined sprintf()
//         0044d551     ADD        ESP,0xc
//                              gameinfo.cpp:589 (23)
//         0044d554     LEA        EDX=>file_info.time_create,[ESP + 0x14]
//         0044d558     LEA        EAX=>file_name[4],[ESP + 0x12c]
//         0044d55f     PUSH       EDX
//         0044d560     PUSH       EAX
//         0044d561     CALL       __findfirst                                      undefined __findfirst()
//         0044d566     MOV        EDI,EAX
//         0044d568     ADD        ESP,0x8
//                              gameinfo.cpp:590 (4)
//         0044d56b     CMP        EDI,EBP
//         0044d56d     JZ         LAB_0044d588
//                               LAB_0044d56f                                                 XREF[1]:     0044d586(j)
//                              gameinfo.cpp:592 (7)
//         0044d56f     MOV        this,dword ptr [ESI + 0xc]
//         0044d572     INC        this
//         0044d573     MOV        dword ptr [ESI + 0xc],this
//                              gameinfo.cpp:593 (18)
//         0044d576     LEA        this=>file_info.time_create,[ESP + 0x14]
//         0044d57a     PUSH       this
//         0044d57b     PUSH       EDI
//         0044d57c     CALL       __findnext                                       undefined __findnext()
//         0044d581     ADD        ESP,0x8
//         0044d584     CMP        EAX,EBP
//         0044d586     JNZ        LAB_0044d56f
//                               LAB_0044d588                                                 XREF[1]:     0044d56d(j)
//                              gameinfo.cpp:598 (13)
//         0044d588     MOV        EAX,dword ptr [ESI + 0xc]
//         0044d58b     XOR        EDI,EDI
//         0044d58d     CMP        EAX,EDI
//         0044d58f     JLE        LAB_0044d6cf
//                              gameinfo.cpp:600 (11)
//         0044d595     PUSH       0x4
//         0044d597     PUSH       EAX
//         0044d598     CALL       calloc                                           undefined calloc()
//         0044d59d     MOV        dword ptr [ESI + 0x10],EAX
//                              gameinfo.cpp:603 (39)
//         0044d5a0     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0044d5a6     ADD        ESP,0x8
//         0044d5a9     LEA        this=>file_name[4],[ESP + 0x12c]
//         0044d5b0     MOV        EAX,dword ptr [EDX + 0xc]
//         0044d5b3     ADD        EAX,0xd1c
//         0044d5b8     PUSH       EAX
//         0044d5b9     PUSH       s_%s*.cpn                                        = "%s*.cpn"
//         0044d5be     PUSH       this
//         0044d5bf     CALL       sprintf                                          undefined sprintf()
//         0044d5c4     ADD        ESP,0xc
//                              gameinfo.cpp:604 (23)
//         0044d5c7     LEA        EDX=>file_info.time_create,[ESP + 0x14]
//         0044d5cb     LEA        EAX=>file_name[4],[ESP + 0x12c]
//         0044d5d2     PUSH       EDX
//         0044d5d3     PUSH       EAX
//         0044d5d4     CALL       __findfirst                                      undefined __findfirst()
//         0044d5d9     MOV        EBX,EAX
//         0044d5db     ADD        ESP,0x8
//                              gameinfo.cpp:606 (4)
//         0044d5de     CMP        EBX,EBP
//         0044d5e0     JZ         LAB_0044d632
//                               LAB_0044d5e2                                                 XREF[1]:     0044d630(j)
//                              gameinfo.cpp:608 (61)
//         0044d5e2     PUSH       0x20c
//         0044d5e7     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044d5ec     ADD        ESP,0x4
//         0044d5ef     MOV        dword ptr [ESP + file_info.attrib],EAX
//         0044d5f3     TEST       EAX,EAX
//         0044d5f5     MOV        dword ptr [ESP + local_4],0x0
//         0044d600     JZ         LAB_0044d610
//         0044d602     LEA        this=>file_info+0x18,[ESP + 0x28]
//         0044d606     PUSH       this
//         0044d607     MOV        this,EAX
//         0044d609     CALL       RGE_Campaign::RGE_Campaign                       undefined RGE_Campaign(RGE_Campaign * this, c
//         0044d60e     JMP        LAB_0044d612
//                               LAB_0044d610                                                 XREF[1]:     0044d600(j)
//         0044d610     XOR        EAX,EAX
//                               LAB_0044d612                                                 XREF[1]:     0044d60e(j)
//         0044d612     MOV        EDX,dword ptr [ESI + 0x10]
//         0044d615     MOV        dword ptr [ESP + local_4],EBP
//         0044d61c     MOV        dword ptr [EDX + EDI*0x4],EAX
//                              gameinfo.cpp:611 (19)
//         0044d61f     LEA        EAX=>file_info.time_create,[ESP + 0x14]
//         0044d623     PUSH       EAX
//         0044d624     PUSH       EBX
//         0044d625     INC        EDI
//         0044d626     CALL       __findnext                                       undefined __findnext()
//         0044d62b     ADD        ESP,0x8
//         0044d62e     CMP        EAX,EBP
//         0044d630     JNZ        LAB_0044d5e2
//                               LAB_0044d632                                                 XREF[1]:     0044d5e0(j)
//                              gameinfo.cpp:616 (37)
//         0044d632     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0044d638     LEA        EAX=>file_name[4],[ESP + 0x12c]
//         0044d63f     MOV        EDX,dword ptr [ECX + this->campaign_num]
//         0044d642     ADD        EDX,0xd1c
//         0044d648     PUSH       EDX
//         0044d649     PUSH       s_%s*.cpx                                        = "%s*.cpx"
//         0044d64e     PUSH       EAX
//         0044d64f     CALL       sprintf                                          undefined sprintf()
//         0044d654     ADD        ESP,0xc
//                              gameinfo.cpp:617 (23)
//         0044d657     LEA        this=>file_info.time_create,[ESP + 0x14]
//         0044d65b     LEA        EDX=>file_name[4],[ESP + 0x12c]
//         0044d662     PUSH       this
//         0044d663     PUSH       EDX
//         0044d664     CALL       __findfirst                                      undefined __findfirst()
//         0044d669     MOV        EBX,EAX
//         0044d66b     ADD        ESP,0x8
//                              gameinfo.cpp:618 (12)
//         0044d66e     CMP        EBX,EBP
//         0044d670     JZ         LAB_0044d6d2
//         0044d672     SHL        EDI,0x2
//         0044d675     MOV        EBP,0x1
//                               LAB_0044d67a                                                 XREF[1]:     0044d6cd(j)
//                              gameinfo.cpp:620 (61)
//         0044d67a     PUSH       0x20c
//         0044d67f     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044d684     ADD        ESP,0x4
//         0044d687     MOV        dword ptr [ESP + file_info.attrib],EAX
//         0044d68b     TEST       EAX,EAX
//         0044d68d     MOV        dword ptr [ESP + local_4],EBP
//         0044d694     JZ         LAB_0044d6a4
//         0044d696     LEA        this=>file_info+0x18,[ESP + 0x28]
//         0044d69a     PUSH       this
//         0044d69b     MOV        this,EAX
//         0044d69d     CALL       RGE_Campaign::RGE_Campaign                       undefined RGE_Campaign(RGE_Campaign * this, c
//         0044d6a2     JMP        LAB_0044d6a6
//                               LAB_0044d6a4                                                 XREF[1]:     0044d694(j)
//         0044d6a4     XOR        EAX,EAX
//                               LAB_0044d6a6                                                 XREF[1]:     0044d6a2(j)
//         0044d6a6     MOV        EDX,dword ptr [ESI + 0x10]
//         0044d6a9     MOV        dword ptr [ESP + local_4],0xffffffff
//         0044d6b4     MOV        dword ptr [EDI + EDX*0x1],EAX
//                              gameinfo.cpp:622 (19)
//         0044d6b7     LEA        EAX=>file_info.time_create,[ESP + 0x14]
//         0044d6bb     PUSH       EAX
//         0044d6bc     PUSH       EBX
//         0044d6bd     CALL       __findnext                                       undefined __findnext()
//         0044d6c2     ADD        ESP,0x8
//         0044d6c5     CMP        EAX,-0x1
//         0044d6c8     JZ         LAB_0044d6d2
//                              gameinfo.cpp:624 (3)
//         0044d6ca     ADD        EDI,0x4
//                              gameinfo.cpp:618 (2)
//         0044d6cd     JMP        LAB_0044d67a
//                               LAB_0044d6cf                                                 XREF[1]:     0044d58f(j)
//                              gameinfo.cpp:628 (3)
//         0044d6cf     MOV        dword ptr [ESI + 0x10],EDI
//                               LAB_0044d6d2                                                 XREF[2]:     0044d670(j), 0044d6c8(j)
//                              gameinfo.cpp:631 (9)
//         0044d6d2     MOV        EAX,dword ptr [ESI + 0x4]
//         0044d6d5     XOR        EDI,EDI
//         0044d6d7     TEST       EAX,EAX
//         0044d6d9     JLE        LAB_0044d6f6
//                               LAB_0044d6db                                                 XREF[1]:     0044d6f4(j)
//                              gameinfo.cpp:632 (27)
//         0044d6db     MOV        this,dword ptr [ESI + 0xc]
//         0044d6de     MOV        EAX,dword ptr [ESI + 0x8]
//         0044d6e1     MOV        EDX,dword ptr [ESI + 0x10]
//         0044d6e4     PUSH       this
//         0044d6e5     MOV        this,dword ptr [EAX + EDI*0x4]
//         0044d6e8     PUSH       EDX
//         0044d6e9     CALL       RGE_Person_Info::rehook_campaigns                void rehook_campaigns(RGE_Person_Info * this,
//         0044d6ee     MOV        EAX,dword ptr [ESI + 0x4]
//         0044d6f1     INC        EDI
//         0044d6f2     CMP        EDI,EAX
//         0044d6f4     JL         LAB_0044d6db
//                               LAB_0044d6f6                                                 XREF[1]:     0044d6d9(j)
//                              gameinfo.cpp:633 (25)
//         0044d6f6     MOV        this,dword ptr [ESP + local_c]
//         0044d6fd     POP        EDI
//         0044d6fe     POP        ESI
//         0044d6ff     POP        EBP
//         0044d700     MOV        dword ptr FS:[0x0],this
//         0044d707     POP        EBX
//         0044d708     ADD        ESP,0x22c
//         0044d70e     RET
//         0044d70f     ??         90h
    return;
}

uchar RGE_Game_Info::add_new_person(char* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall add_new_person(RGE_Game_Info * this, char * param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0044d789(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044d778(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044d7a8(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044d772(W)
//                               ?add_new_person@RGE_Game_Info@@QAEEPAD@Z                     XREF[1]:     action:004a7089(c)
//                               RGE_Game_Info::add_new_person
//                              gameinfo.cpp:638 (27)
//         0044d710     PUSH       -0x1
//         0044d712     PUSH       FUN_0055d61b
//         0044d717     MOV        EAX,FS:[0x0]
//         0044d71d     PUSH       EAX
//         0044d71e     MOV        dword ptr FS:[0x0],ESP
//         0044d725     PUSH       this
//         0044d726     PUSH       EBX
//         0044d727     MOV        EBX,this
//         0044d729     PUSH       EBP
//         0044d72a     PUSH       ESI
//                              gameinfo.cpp:641 (13)
//         0044d72b     MOV        EAX,dword ptr [EBX + 0x4]
//         0044d72e     PUSH       EDI
//         0044d72f     INC        EAX
//         0044d730     PUSH       0x4
//         0044d732     PUSH       EAX
//         0044d733     CALL       calloc                                           undefined calloc()
//                              gameinfo.cpp:643 (30)
//         0044d738     MOV        this,dword ptr [EBX + 0x4]
//         0044d73b     MOV        ESI,dword ptr [EBX + 0x8]
//         0044d73e     SHL        this,0x2
//         0044d741     MOV        EBP,EAX
//         0044d743     MOV        EDX,this
//         0044d745     MOV        EDI,EBP
//         0044d747     ADD        ESP,0x8
//         0044d74a     SHR        this,0x2
//         0044d74d     MOVSD.REP  ES:EDI,ESI
//         0044d74f     MOV        this,EDX
//         0044d751     AND        this,0x3
//         0044d754     MOVSB.REP  ES:EDI,ESI
//                              gameinfo.cpp:645 (12)
//         0044d756     MOV        EAX,dword ptr [EBX + 0x8]
//         0044d759     PUSH       EAX
//         0044d75a     CALL       free                                             undefined free()
//         0044d75f     ADD        ESP,0x4
//                              gameinfo.cpp:646 (3)
//         0044d762     MOV        dword ptr [EBX + 0x8],EBP
//                              gameinfo.cpp:647 (59)
//         0044d765     PUSH       0x114
//         0044d76a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044d76f     ADD        ESP,0x4
//         0044d772     MOV        dword ptr [ESP + local_10],EAX
//         0044d776     TEST       EAX,EAX
//         0044d778     MOV        dword ptr [ESP + local_4],0x0
//         0044d780     JZ         LAB_0044d798
//         0044d782     MOV        this,dword ptr [EBX + 0xc]
//         0044d785     MOV        EDX,dword ptr [EBX + 0x10]
//         0044d788     PUSH       this
//         0044d789     MOV        this,dword ptr [ESP + param_1]
//         0044d78d     PUSH       EDX
//         0044d78e     PUSH       this
//         0044d78f     MOV        this,EAX
//         0044d791     CALL       RGE_Person_Info::RGE_Person_Info                 undefined RGE_Person_Info(RGE_Person_Info * t
//         0044d796     JMP        LAB_0044d79a
//                               LAB_0044d798                                                 XREF[1]:     0044d780(j)
//         0044d798     XOR        EAX,EAX
//                               LAB_0044d79a                                                 XREF[1]:     0044d796(j)
//         0044d79a     MOV        EDX,dword ptr [EBX + 0x4]
//         0044d79d     MOV        this,dword ptr [EBX + 0x8]
//                              gameinfo.cpp:653 (35)
//         0044d7a0     POP        EDI
//         0044d7a1     POP        ESI
//         0044d7a2     MOV        dword ptr [this->current_person + EDX*0x4],EAX
//         0044d7a5     MOV        EAX,dword ptr [EBX + 0x4]
//         0044d7a8     MOV        this,dword ptr [ESP + local_c]
//         0044d7ac     MOV        dword ptr [EBX],EAX
//         0044d7ae     INC        EAX
//         0044d7af     POP        EBP
//         0044d7b0     MOV        dword ptr [EBX + 0x4],EAX
//         0044d7b3     MOV        AL,0x1
//         0044d7b5     MOV        dword ptr FS:[0x0],this
//         0044d7bc     POP        EBX
//         0044d7bd     ADD        ESP,0x10
//         0044d7c0     RET        0x4
//         0044d7c3     ??         90h
//         0044d7c4     NOP
//         0044d7c5     NOP
//         0044d7c6     NOP
//         0044d7c7     NOP
//         0044d7c8     NOP
//         0044d7c9     NOP
//         0044d7ca     NOP
//         0044d7cb     NOP
//         0044d7cc     NOP
//         0044d7cd     NOP
//         0044d7ce     NOP
//         0044d7cf     NOP
    return 0;
}

uchar RGE_Game_Info::set_current_person(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall set_current_person(RGE_Game_Info * this, long param
//              uchar             AL:1           <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0044d7d0(R)
//                               ?set_current_person@RGE_Game_Info@@QAEEJ@Z                   XREF[3]:     set_campaign_info:0041cf8c(c),
//                               RGE_Game_Info::set_current_person                                         action:004a6a36(c),
//                                                                                                         quit_game:005241dd(c)
//                              gameinfo.cpp:657 (11)
//         0044d7d0     MOV        EAX,dword ptr [ESP + param_1]
//         0044d7d4     MOV        EDX,dword ptr [ECX + this->people_num]
//         0044d7d7     CMP        EAX,EDX
//         0044d7d9     JGE        LAB_0044d7e2
//                              gameinfo.cpp:660 (2)
//         0044d7db     MOV        dword ptr [this->current_person],EAX
//                              gameinfo.cpp:661 (2)
//         0044d7dd     MOV        AL,0x1
//                              gameinfo.cpp:665 (3)
//         0044d7df     RET        0x4
//                               LAB_0044d7e2                                                 XREF[1]:     0044d7d9(j)
//                              gameinfo.cpp:663 (6)
//         0044d7e2     MOV        dword ptr [this->current_person],0xffffffff
//                              gameinfo.cpp:664 (2)
//         0044d7e8     XOR        AL,AL
//                              gameinfo.cpp:665 (3)
//         0044d7ea     RET        0x4
//         0044d7ed     ??         90h
//         0044d7ee     NOP
//         0044d7ef     NOP
    return 0;
}

uchar RGE_Game_Info::set_current_campaign(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall set_current_campaign(RGE_Game_Info * this, long par
//              uchar             AL:1           <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0044d800(R)
//                               ?set_current_campaign@RGE_Game_Info@@QAEEJ@Z                 XREF[4]:     set_campaign_info:0041cf7b(c),
//                               RGE_Game_Info::set_current_campaign                                       action:00491120(c),
//                                                                                                         fillCampaigns:00491276(c),
//                                                                                                         quit_game:005241f6(c)
//                              gameinfo.cpp:669 (13)
//         0044d7f0     MOV        EAX,dword ptr [this->current_person]
//         0044d7f2     MOV        EDX,dword ptr [ECX + this->people_num]
//         0044d7f5     CMP        EAX,EDX
//         0044d7f7     JGE        LAB_0044d810
//         0044d7f9     TEST       EAX,EAX
//         0044d7fb     JL         LAB_0044d810
//                              gameinfo.cpp:671 (16)
//         0044d7fd     MOV        this,dword ptr [ECX + this->people_info]
//         0044d800     MOV        EDX,dword ptr [ESP + param_1]
//         0044d804     PUSH       EDX
//         0044d805     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d808     CALL       RGE_Person_Info::set_current_campaign            uchar set_current_campaign(RGE_Person_Info *
//                              gameinfo.cpp:673 (3)
//         0044d80d     RET        0x4
//                               LAB_0044d810                                                 XREF[2]:     0044d7f7(j), 0044d7fb(j)
//                              gameinfo.cpp:672 (2)
//         0044d810     XOR        AL,AL
//                              gameinfo.cpp:673 (3)
//         0044d812     RET        0x4
//         0044d815     ??         90h
//         0044d816     NOP
//         0044d817     NOP
//         0044d818     NOP
//         0044d819     NOP
//         0044d81a     NOP
//         0044d81b     NOP
//         0044d81c     NOP
//         0044d81d     NOP
//         0044d81e     NOP
//         0044d81f     NOP
    return 0;
}

uchar RGE_Game_Info::set_current_scenario(long param_1) {
    /* TODO: Stub */
//                              uchar __thiscall set_current_scenario(RGE_Game_Info * this, long par
//              uchar             AL:1           <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0044d82e(R)
//                               ?set_current_scenario@RGE_Game_Info@@QAEEJ@Z                 XREF[2]:     set_campaign_info:0041cf9d(c),
//                               RGE_Game_Info::set_current_scenario                                       startGame:00491387(c)
//                              gameinfo.cpp:677 (11)
//         0044d820     MOV        EAX,dword ptr [this->current_person]
//         0044d822     TEST       EAX,EAX
//         0044d824     JL         LAB_0044d83e
//         0044d826     CMP        EAX,dword ptr [ECX + this->people_num]
//         0044d829     JGE        LAB_0044d83e
//                              gameinfo.cpp:679 (16)
//         0044d82b     MOV        this,dword ptr [ECX + this->people_info]
//         0044d82e     MOV        EDX,dword ptr [ESP + param_1]
//         0044d832     PUSH       EDX
//         0044d833     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d836     CALL       RGE_Person_Info::set_current_scenario            uchar set_current_scenario(RGE_Person_Info *
//                              gameinfo.cpp:681 (3)
//         0044d83b     RET        0x4
//                               LAB_0044d83e                                                 XREF[2]:     0044d824(j), 0044d829(j)
//                              gameinfo.cpp:680 (2)
//         0044d83e     XOR        AL,AL
//                              gameinfo.cpp:681 (3)
//         0044d840     RET        0x4
//         0044d843     ??         90h
//         0044d844     NOP
//         0044d845     NOP
//         0044d846     NOP
//         0044d847     NOP
//         0044d848     NOP
//         0044d849     NOP
//         0044d84a     NOP
//         0044d84b     NOP
//         0044d84c     NOP
//         0044d84d     NOP
//         0044d84e     NOP
//         0044d84f     NOP
    return 0;
}

long RGE_Game_Info::get_people_list(char*** param_1, long* param_2) {
    /* TODO: Stub */
//                              long __thiscall get_people_list(RGE_Game_Info * this, char * * * par
//              long              EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              char * * *        Stack[0x4]:4   param_1                   XREF[1]:     0044d864(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     0044d8a2(R)
//                               ?get_people_list@RGE_Game_Info@@QAEJPAPAPADAAJ@Z             XREF[2]:     get_player_names:004a682c(c),
//                               RGE_Game_Info::get_people_list                                            action:004b6f85(c)
//                              gameinfo.cpp:685 (3)
//         0044d850     PUSH       EBX
//         0044d851     MOV        EBX,this
//                              gameinfo.cpp:688 (9)
//         0044d853     MOV        EAX,dword ptr [EBX + 0x4]
//         0044d856     TEST       EAX,EAX
//         0044d858     JLE        LAB_0044d8ac
//         0044d85a     PUSH       ESI
//         0044d85b     PUSH       EBP
//                              gameinfo.cpp:690 (15)
//         0044d85c     PUSH       0x4
//         0044d85e     PUSH       EAX
//         0044d85f     CALL       calloc                                           undefined calloc()
//         0044d864     MOV        EBP,dword ptr [ESP + param_1]
//         0044d868     ADD        ESP,0x8
//                              gameinfo.cpp:691 (12)
//         0044d86b     XOR        ESI,ESI
//         0044d86d     MOV        dword ptr [EBP],EAX
//         0044d870     MOV        EAX,dword ptr [EBX + 0x4]
//         0044d873     TEST       EAX,EAX
//         0044d875     JLE        LAB_0044d8a2
//                              gameinfo.cpp:685 (1)
//         0044d877     PUSH       EDI
//                               LAB_0044d878                                                 XREF[1]:     0044d89f(j)
//                              gameinfo.cpp:692 (41)
//         0044d878     MOV        EAX,dword ptr [EBX + 0x8]
//         0044d87b     LEA        EDI,[ESI*0x4 + 0x0]
//         0044d882     MOV        this,dword ptr [EAX + EDI*0x1]
//         0044d885     CALL       RGE_Person_Info::get_name                        char * get_name(RGE_Person_Info * this)
//         0044d88a     MOV        this,dword ptr [EBP]
//         0044d88d     PUSH       EAX
//         0044d88e     ADD        this,EDI
//         0044d890     PUSH       this
//         0044d891     CALL       getstring                                        void getstring(char * * param_1, char * param
//         0044d896     MOV        EAX,dword ptr [EBX + 0x4]
//         0044d899     ADD        ESP,0x8
//         0044d89c     INC        ESI
//         0044d89d     CMP        ESI,EAX
//         0044d89f     JL         LAB_0044d878
//                              gameinfo.cpp:685 (1)
//         0044d8a1     POP        EDI
//                               LAB_0044d8a2                                                 XREF[1]:     0044d875(j)
//                              gameinfo.cpp:693 (10)
//         0044d8a2     MOV        EAX,dword ptr [ESP + param_2]
//         0044d8a6     MOV        EDX,dword ptr [EBX]
//         0044d8a8     POP        EBP
//         0044d8a9     POP        ESI
//         0044d8aa     MOV        dword ptr [EAX],EDX
//                               LAB_0044d8ac                                                 XREF[1]:     0044d858(j)
//                              gameinfo.cpp:695 (3)
//         0044d8ac     MOV        EAX,dword ptr [EBX + 0x4]
//                              gameinfo.cpp:696 (4)
//         0044d8af     POP        EBX
//         0044d8b0     RET        0x8
//         0044d8b3     ??         90h
//         0044d8b4     NOP
//         0044d8b5     NOP
//         0044d8b6     NOP
//         0044d8b7     NOP
//         0044d8b8     NOP
//         0044d8b9     NOP
//         0044d8ba     NOP
//         0044d8bb     NOP
//         0044d8bc     NOP
//         0044d8bd     NOP
//         0044d8be     NOP
//         0044d8bf     NOP
    return 0;
}

long RGE_Game_Info::get_campaign_list(char*** param_1, long* param_2) {
    /* TODO: Stub */
//                              long __thiscall get_campaign_list(RGE_Game_Info * this, char * * * p
//              long              EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              char * * *        Stack[0x4]:4   param_1                   XREF[1]:     0044d8d5(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     0044d929(R)
//                               ?get_campaign_list@RGE_Game_Info@@QAEJPAPAPADAAJ@Z           XREF[1]:     fillCampaigns:004911cd(c)
//                               RGE_Game_Info::get_campaign_list
//                              gameinfo.cpp:700 (6)
//         0044d8c0     PUSH       EBX
//         0044d8c1     PUSH       EBP
//         0044d8c2     PUSH       ESI
//         0044d8c3     PUSH       EDI
//         0044d8c4     MOV        EDI,this
//                              gameinfo.cpp:703 (7)
//         0044d8c6     MOV        EAX,dword ptr [EDI + 0xc]
//         0044d8c9     TEST       EAX,EAX
//         0044d8cb     JLE        LAB_0044d92f
//                              gameinfo.cpp:705 (15)
//         0044d8cd     PUSH       0x4
//         0044d8cf     PUSH       EAX
//         0044d8d0     CALL       calloc                                           undefined calloc()
//         0044d8d5     MOV        EBP,dword ptr [ESP + param_1]
//         0044d8d9     ADD        ESP,0x8
//                              gameinfo.cpp:706 (12)
//         0044d8dc     XOR        ESI,ESI
//         0044d8de     MOV        dword ptr [EBP],EAX
//         0044d8e1     MOV        EAX,dword ptr [EDI + 0xc]
//         0044d8e4     TEST       EAX,EAX
//         0044d8e6     JLE        LAB_0044d911
//                               LAB_0044d8e8                                                 XREF[1]:     0044d90f(j)
//                              gameinfo.cpp:707 (41)
//         0044d8e8     MOV        EAX,dword ptr [EDI + 0x10]
//         0044d8eb     LEA        EBX,[ESI*0x4 + 0x0]
//         0044d8f2     MOV        this,dword ptr [EAX + EBX*0x1]
//         0044d8f5     CALL       RGE_Campaign::get_name                           char * get_name(RGE_Campaign * this)
//         0044d8fa     MOV        this,dword ptr [EBP]
//         0044d8fd     PUSH       EAX
//         0044d8fe     ADD        this,EBX
//         0044d900     PUSH       this
//         0044d901     CALL       getstring                                        void getstring(char * * param_1, char * param
//         0044d906     MOV        EAX,dword ptr [EDI + 0xc]
//         0044d909     ADD        ESP,0x8
//         0044d90c     INC        ESI
//         0044d90d     CMP        ESI,EAX
//         0044d90f     JL         LAB_0044d8e8
//                               LAB_0044d911                                                 XREF[1]:     0044d8e6(j)
//                              gameinfo.cpp:709 (13)
//         0044d911     MOV        EAX,dword ptr [EDI]
//         0044d913     MOV        this,dword ptr [EDI + 0x4]
//         0044d916     CMP        EAX,this
//         0044d918     JGE        LAB_0044d92f
//         0044d91a     TEST       EAX,EAX
//         0044d91c     JL         LAB_0044d92f
//                              gameinfo.cpp:710 (17)
//         0044d91e     MOV        EDX,dword ptr [EDI + 0x8]
//         0044d921     MOV        this,dword ptr [EDX + EAX*0x4]
//         0044d924     CALL       RGE_Person_Info::get_current_campaign            long get_current_campaign(RGE_Person_Info * t
//         0044d929     MOV        this,dword ptr [ESP + param_2]
//         0044d92d     MOV        dword ptr [this->current_person],EAX
//                               LAB_0044d92f                                                 XREF[3]:     0044d8cb(j), 0044d918(j),
//                                                                                                         0044d91c(j)
//                              gameinfo.cpp:712 (3)
//         0044d92f     MOV        EAX,dword ptr [EDI + 0xc]
//                              gameinfo.cpp:713 (7)
//         0044d932     POP        EDI
//         0044d933     POP        ESI
//         0044d934     POP        EBP
//         0044d935     POP        EBX
//         0044d936     RET        0x8
//         0044d939     ??         90h
//         0044d93a     NOP
//         0044d93b     NOP
//         0044d93c     NOP
//         0044d93d     NOP
//         0044d93e     NOP
//         0044d93f     NOP
    return 0;
}

long RGE_Game_Info::get_scenario_list(char*** param_1, long* param_2) {
    /* TODO: Stub */
//                              long __thiscall get_scenario_list(RGE_Game_Info * this, char * * * p
//              long              EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              char * * *        Stack[0x4]:4   param_1                   XREF[1]:     0044d95f(R)
//              long *            Stack[0x8]:4   param_2                   XREF[2]:     0044d95b(R), 0044d978(R)
//                               ?get_scenario_list@RGE_Game_Info@@QAEJPAPAPADAAJ@Z           XREF[1]:     fillScenarios:004912bc(c)
//                               RGE_Game_Info::get_scenario_list
//                              gameinfo.cpp:717 (3)
//         0044d940     PUSH       ESI
//         0044d941     MOV        ESI,this
//                              gameinfo.cpp:718 (13)
//         0044d943     MOV        EAX,dword ptr [ESI]
//         0044d945     MOV        this,dword ptr [ESI + 0x4]
//         0044d948     CMP        EAX,this
//         0044d94a     JGE        LAB_0044d978
//         0044d94c     TEST       EAX,EAX
//         0044d94e     JL         LAB_0044d978
//                              gameinfo.cpp:720 (15)
//         0044d950     MOV        this,dword ptr [ESI + 0x8]
//         0044d953     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d956     CALL       RGE_Person_Info::get_current_scenario            long get_current_scenario(RGE_Person_Info * t
//         0044d95b     MOV        this,dword ptr [ESP + param_2]
//                              gameinfo.cpp:721 (21)
//         0044d95f     MOV        EDX,dword ptr [ESP + param_1]
//         0044d963     PUSH       this
//         0044d964     PUSH       EDX
//         0044d965     MOV        dword ptr [this->current_person],EAX
//         0044d967     MOV        EAX,dword ptr [ESI]
//         0044d969     MOV        this,dword ptr [ESI + 0x8]
//         0044d96c     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d96f     CALL       RGE_Person_Info::get_scenario_list               long get_scenario_list(RGE_Person_Info * this
//                              gameinfo.cpp:726 (4)
//         0044d974     POP        ESI
//         0044d975     RET        0x8
//                               LAB_0044d978                                                 XREF[2]:     0044d94a(j), 0044d94e(j)
//                              gameinfo.cpp:724 (4)
//         0044d978     MOV        EDX,dword ptr [ESP + param_2]
//                              gameinfo.cpp:725 (3)
//         0044d97c     OR         EAX,0xffffffff
//                              gameinfo.cpp:726 (10)
//         0044d97f     POP        ESI
//         0044d980     MOV        dword ptr [EDX],0xffffffff
//         0044d986     RET        0x8
//         0044d989     ??         90h
//         0044d98a     NOP
//         0044d98b     NOP
//         0044d98c     NOP
//         0044d98d     NOP
//         0044d98e     NOP
//         0044d98f     NOP
    return 0;
}

long RGE_Game_Info::get_current_scenario() {
    /* TODO: Stub */
//                              long __thiscall get_current_scenario(RGE_Game_Info * this)
//              long              EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ?get_current_scenario@RGE_Game_Info@@QAEJXZ                  XREF[1]:     get_campaign_info:0041cf52(c)
//                               RGE_Game_Info::get_current_scenario
//                              gameinfo.cpp:730 (13)
//         0044d990     MOV        EAX,dword ptr [this->current_person]
//         0044d992     MOV        EDX,dword ptr [ECX + this->people_num]
//         0044d995     CMP        EAX,EDX
//         0044d997     JGE        LAB_0044d9a8
//         0044d999     TEST       EAX,EAX
//         0044d99b     JL         LAB_0044d9a8
//                              gameinfo.cpp:732 (11)
//         0044d99d     MOV        this,dword ptr [ECX + this->people_info]
//         0044d9a0     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d9a3     JMP        RGE_Person_Info::get_current_scenario            long get_current_scenario(RGE_Person_Info * t
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0044d9a8                                                 XREF[2]:     0044d997(j), 0044d99b(j)
//                              gameinfo.cpp:733 (3)
//         0044d9a8     OR         EAX,0xffffffff
//                              gameinfo.cpp:734 (1)
//         0044d9ab     RET
//         0044d9ac     ??         90h
//         0044d9ad     NOP
//         0044d9ae     NOP
//         0044d9af     NOP
    return 0;
}

long RGE_Game_Info::get_current_campaign() {
    /* TODO: Stub */
//                              long __thiscall get_current_campaign(RGE_Game_Info * this)
//              long              EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ?get_current_campaign@RGE_Game_Info@@QAEJXZ                  XREF[1]:     get_campaign_info:0041cf36(c)
//                               RGE_Game_Info::get_current_campaign
//                              gameinfo.cpp:738 (13)
//         0044d9b0     MOV        EAX,dword ptr [this->current_person]
//         0044d9b2     MOV        EDX,dword ptr [ECX + this->people_num]
//         0044d9b5     CMP        EAX,EDX
//         0044d9b7     JGE        LAB_0044d9c8
//         0044d9b9     TEST       EAX,EAX
//         0044d9bb     JL         LAB_0044d9c8
//                              gameinfo.cpp:740 (11)
//         0044d9bd     MOV        this,dword ptr [ECX + this->people_info]
//         0044d9c0     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d9c3     JMP        RGE_Person_Info::get_current_campaign            long get_current_campaign(RGE_Person_Info * t
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0044d9c8                                                 XREF[2]:     0044d9b7(j), 0044d9bb(j)
//                              gameinfo.cpp:741 (3)
//         0044d9c8     OR         EAX,0xffffffff
//                              gameinfo.cpp:742 (1)
//         0044d9cb     RET
//         0044d9cc     ??         90h
//         0044d9cd     NOP
//         0044d9ce     NOP
//         0044d9cf     NOP
    return 0;
}

long RGE_Game_Info::get_current_player() {
    /* TODO: Stub */
//                              long __thiscall get_current_player(RGE_Game_Info * this)
//              long              EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ?get_current_player@RGE_Game_Info@@QAEJXZ                    XREF[1]:     get_campaign_info:0041cf44(c)
//                               RGE_Game_Info::get_current_player
//                              gameinfo.cpp:746 (2)
//         0044d9d0     MOV        EAX,dword ptr [this->current_person]
//                              gameinfo.cpp:748 (1)
//         0044d9d2     RET
//         0044d9d3     ??         90h
//         0044d9d4     NOP
//         0044d9d5     NOP
//         0044d9d6     NOP
//         0044d9d7     NOP
//         0044d9d8     NOP
//         0044d9d9     NOP
//         0044d9da     NOP
//         0044d9db     NOP
//         0044d9dc     NOP
//         0044d9dd     NOP
//         0044d9de     NOP
//         0044d9df     NOP
    return 0;
}

char* RGE_Game_Info::get_current_player_name() {
    /* TODO: Stub */
//                              char * __thiscall get_current_player_name(RGE_Game_Info * this)
//              char *            EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ?get_current_player_name@RGE_Game_Info@@QAEPADXZ             XREF[6]:     initialize:004d82a2(c),
//                               RGE_Game_Info::get_current_player_name                                    initialize:004d82ad(c),
//                                                                                                         loadLearnInfo:004e12a0(c),
//                                                                                                         loadUnitHistory:004e4517(c),
//                                                                                                         create_game:00527543(c),
//                                                                                                         update:005431dd(c)
//                              gameinfo.cpp:752 (6)
//         0044d9e0     MOV        EAX,dword ptr [this->current_person]
//         0044d9e2     TEST       EAX,EAX
//         0044d9e4     JGE        LAB_0044d9e9
//                              gameinfo.cpp:754 (2)
//         0044d9e6     XOR        EAX,EAX
//                              gameinfo.cpp:757 (12)
//         0044d9e8     RET
//                               LAB_0044d9e9                                                 XREF[1]:     0044d9e4(j)
//         0044d9e9     MOV        this,dword ptr [ECX + this->people_info]
//         0044d9ec     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044d9ef     JMP        RGE_Person_Info::get_name                        char * get_name(RGE_Person_Info * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0044d9f4     ??         90h
//         0044d9f5     NOP
//         0044d9f6     NOP
//         0044d9f7     NOP
//         0044d9f8     NOP
//         0044d9f9     NOP
//         0044d9fa     NOP
//         0044d9fb     NOP
//         0044d9fc     NOP
//         0044d9fd     NOP
//         0044d9fe     NOP
//         0044d9ff     NOP
    return 0;
}

void RGE_Game_Info::notify_of_scenario_complete() {
    /* TODO: Stub */
//                              void __thiscall notify_of_scenario_complete(RGE_Game_Info * this)
//              void              <VOID>         <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ?notify_of_scenario_complete@RGE_Game_Info@@QAEXXZ           XREF[1]:     set_campaign_win:0041cfc3(c)
//                               RGE_Game_Info::notify_of_scenario_complete
//                              gameinfo.cpp:761 (3)
//         0044da00     PUSH       ESI
//         0044da01     MOV        ESI,this
//                              gameinfo.cpp:762 (13)
//         0044da03     MOV        EAX,dword ptr [ESI]
//         0044da05     MOV        this,dword ptr [ESI + 0x4]
//         0044da08     CMP        EAX,this
//         0044da0a     JGE        LAB_0044da1b
//         0044da0c     TEST       EAX,EAX
//         0044da0e     JL         LAB_0044da1b
//                              gameinfo.cpp:763 (11)
//         0044da10     MOV        this,dword ptr [ESI + 0x8]
//         0044da13     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044da16     CALL       RGE_Person_Info::notify_of_scenario_complete     void notify_of_scenario_complete(RGE_Person_I
//                               LAB_0044da1b                                                 XREF[2]:     0044da0a(j), 0044da0e(j)
//                              gameinfo.cpp:764 (11)
//         0044da1b     LEA        EDX,[ESI + 0x14]
//         0044da1e     MOV        this,ESI
//         0044da20     PUSH       EDX
//         0044da21     CALL       RGE_Game_Info::save                              void save(RGE_Game_Info * this, char * param_1)
//                              gameinfo.cpp:765 (2)
//         0044da26     POP        ESI
//         0044da27     RET
//         0044da28     ??         90h
//         0044da29     NOP
//         0044da2a     NOP
//         0044da2b     NOP
//         0044da2c     NOP
//         0044da2d     NOP
//         0044da2e     NOP
//         0044da2f     NOP
    return;
}

int RGE_Game_Info::open_scenario() {
    /* TODO: Stub */
//                              int __thiscall open_scenario(RGE_Game_Info * this)
//              int               EAX:4          <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//                               ?open_scenario@RGE_Game_Info@@QAEHXZ                         XREF[3]:     get_scenario_info:0041cbbc(c),
//                               RGE_Game_Info::open_scenario                                              get_scenario_header:0041ccdc(c),
//                                                                                                         campaign_open_scenario:00422913(c)
//                              gameinfo.cpp:769 (13)
//         0044da30     MOV        EAX,dword ptr [this->current_person]
//         0044da32     MOV        EDX,dword ptr [ECX + this->people_num]
//         0044da35     CMP        EAX,EDX
//         0044da37     JGE        LAB_0044da48
//         0044da39     TEST       EAX,EAX
//         0044da3b     JL         LAB_0044da48
//                              gameinfo.cpp:771 (11)
//         0044da3d     MOV        this,dword ptr [ECX + this->people_info]
//         0044da40     MOV        this,dword ptr [this->current_person + EAX*0x4]
//         0044da43     JMP        RGE_Person_Info::open_scenario                   int open_scenario(RGE_Person_Info * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0044da48                                                 XREF[2]:     0044da37(j), 0044da3b(j)
//                              gameinfo.cpp:772 (3)
//         0044da48     OR         EAX,0xffffffff
//                              gameinfo.cpp:773 (1)
//         0044da4b     RET
//         0044da4c     ??         90h
//         0044da4d     NOP
//         0044da4e     NOP
//         0044da4f     NOP
    return 0;
}

void RGE_Game_Info::remove_player(long param_1) {
    /* TODO: Stub */
//                              void __thiscall remove_player(RGE_Game_Info * this, long param_1)
//              void              <VOID>         <RETURN>
//              RGE_Game_Info *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0044da53(R)
//                               ?remove_player@RGE_Game_Info@@QAEXJ@Z                        XREF[1]:     action:004a6ce5(c)
//                               RGE_Game_Info::remove_player
//                              gameinfo.cpp:777 (3)
//         0044da50     PUSH       EBX
//         0044da51     PUSH       ESI
//         0044da52     PUSH       EDI
//                              gameinfo.cpp:780 (15)
//         0044da53     MOV        EDI,dword ptr [ESP + param_1]
//         0044da57     TEST       EDI,EDI
//         0044da59     MOV        ESI,this
//         0044da5b     JL         LAB_0044daab
//         0044da5d     CMP        EDI,dword ptr [ESI + 0x4]
//         0044da60     JGE        LAB_0044daab
//                              gameinfo.cpp:783 (26)
//         0044da62     MOV        EAX,dword ptr [ESI + 0x8]
//         0044da65     MOV        EBX,dword ptr [EAX + EDI*0x4]
//         0044da68     TEST       EBX,EBX
//         0044da6a     JZ         LAB_0044da7c
//         0044da6c     MOV        this,EBX
//         0044da6e     CALL       RGE_Person_Info::~RGE_Person_Info                void ~RGE_Person_Info(RGE_Person_Info * this)
//         0044da73     PUSH       EBX
//         0044da74     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0044da79     ADD        ESP,0x4
//                               LAB_0044da7c                                                 XREF[1]:     0044da6a(j)
//                              gameinfo.cpp:785 (10)
//         0044da7c     MOV        this,dword ptr [ESI + 0x4]
//         0044da7f     MOV        EAX,EDI
//         0044da81     DEC        this
//         0044da82     CMP        EDI,this
//         0044da84     JGE        LAB_0044da99
//                               LAB_0044da86                                                 XREF[1]:     0044da97(j)
//                              gameinfo.cpp:786 (19)
//         0044da86     MOV        this,dword ptr [ESI + 0x8]
//         0044da89     INC        EAX
//         0044da8a     MOV        EDX,dword ptr [this->current_person + EAX*0x4]
//         0044da8d     MOV        dword ptr [this->current_person + EAX*0x4 + -0
//         0044da91     MOV        this,dword ptr [ESI + 0x4]
//         0044da94     DEC        this
//         0044da95     CMP        EAX,this
//         0044da97     JL         LAB_0044da86
//                               LAB_0044da99                                                 XREF[1]:     0044da84(j)
//                              gameinfo.cpp:788 (3)
//         0044da99     MOV        EDX,dword ptr [ESI + 0x4]
//                              gameinfo.cpp:790 (12)
//         0044da9c     MOV        this,dword ptr [ESI]
//         0044da9e     DEC        EDX
//         0044da9f     MOV        EAX,EDX
//         0044daa1     MOV        dword ptr [ESI + 0x4],EDX
//         0044daa4     CMP        this,EAX
//         0044daa6     JNZ        LAB_0044daab
//                              gameinfo.cpp:791 (3)
//         0044daa8     DEC        EAX
//         0044daa9     MOV        dword ptr [ESI],EAX
//                               LAB_0044daab                                                 XREF[3]:     0044da5b(j), 0044da60(j),
//                                                                                                         0044daa6(j)
//                              gameinfo.cpp:792 (6)
//         0044daab     POP        EDI
//         0044daac     POP        ESI
//         0044daad     POP        EBX
//         0044daae     RET        0x4
//         0044dab1     ??         90h
//         0044dab2     NOP
//         0044dab3     NOP
//         0044dab4     NOP
//         0044dab5     NOP
//         0044dab6     NOP
//         0044dab7     NOP
//         0044dab8     NOP
//         0044dab9     NOP
//         0044daba     NOP
//         0044dabb     NOP
//         0044dabc     NOP
//         0044dabd     NOP
//         0044dabe     NOP
//         0044dabf     NOP
    return;
}

