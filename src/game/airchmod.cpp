#include "../common.h"
#include "airchmod.h"

ResearchAIModule::ResearchAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall ResearchAIModule(ResearchAIModule * this, int p
//              undefined         <UNASSIGNED>   <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041175b(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004117ac(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     00411785(W), 004117a2(W), 0041188a(W), 004118a2(W),
//                                                                                     004118e6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00411923(R)
//              char[257]         Stack[-0x114   name                      XREF[0,2]:   00411825(*), 004118cc(*)
//              ResourceItem      Stack[-0x184   newRCost                  XREF[0,3]:   0041187c(*), 004118af(*), 004118fd(*)
//              int[4]            Stack[-0x194   rc                        XREF[1,3]:   004118b8(W), 00411853(*), 00411870(*), 00411878(*)
//              undefined4        Stack[-0x198   local_198                 XREF[1]:     00411776(W)
//              undefined4        Stack[-0x19c   local_19c                 XREF[1]:     0041189c(W)
//              undefined4        Stack[-0x1a0   local_1a0                 XREF[2]:     0041183b(*), 004118c5(R)
//              int               Stack[-0x1a4   typeID                    XREF[3]:     004117f7(W), 0041190c(R), 00411919(W)
//              int               Stack[-0x1a8   i                         XREF[8]:     004117ce(*), 004117db(R), 004117f0(R), 00411811(*),
//                                                                                     0041181e(R), 00411834(R), 0041185c(*), 00411869(R)
//              int               Stack[-0x1ac   tempInt
//                               ??0ResearchAIModule@@QAE@HH@Z
//                               ResearchAIModule::ResearchAIModule
//                              airchmod.cpp:38 (95)
//         00411740     PUSH       -0x1
//         00411742     PUSH       FUN_0055c7a5
//         00411747     MOV        EAX,FS:[0x0]
//         0041174d     PUSH       EAX
//         0041174e     MOV        dword ptr FS:[0x0],ESP
//         00411755     SUB        ESP,0x19c
//         0041175b     MOV        EAX,dword ptr [ESP + param_1]
//         00411762     PUSH       EBX
//         00411763     PUSH       EBP
//         00411764     PUSH       ESI
//         00411765     XOR        EBP,EBP
//         00411767     PUSH       EDI
//         00411768     PUSH       EBP
//         00411769     PUSH       EAX
//         0041176a     MOV        ESI,this
//         0041176c     PUSH       0x3ee
//         00411771     PUSH       s_Research_AI                                    = "Research AI"
//         00411776     MOV        dword ptr [ESP + local_198],ESI
//         0041177a     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
//         0041177f     LEA        EDI,[ESI + 0xf4]
//         00411785     MOV        dword ptr [ESP + local_4],EBP
//         0041178c     MOV        this,EDI
//         0041178e     MOV        dword ptr [ESI + 0xf0],EBP
//         00411794     CALL       TechnologyItem::TechnologyItem                   undefined TechnologyItem(TechnologyItem * this)
//         00411799     LEA        EBX,[ESI + 0x148]
//                              airchmod.cpp:42 (47)
//         0041179f     PUSH       0x4
//         004117a1     PUSH       EBX
//         004117a2     MOV        byte ptr [ESP + local_4],0x1
//         004117aa     MOV        dword ptr [EBX],EBP
//         004117ac     MOV        EBP,dword ptr [ESP + param_2]
//         004117b3     PUSH       EBP
//         004117b4     MOV        dword ptr [ESI],ResearchAIModule::`vftable'      = 00411720
//         004117ba     MOV        dword ptr [ESI + 0xf8],EDI
//         004117c0     MOV        dword ptr [ESI + 0xfc],EDI
//         004117c6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004117cb     ADD        ESP,0xc
//                              airchmod.cpp:45 (13)
//         004117ce     LEA        this=>i,[ESP + 0x10]
//         004117d2     PUSH       0x4
//         004117d4     PUSH       this
//         004117d5     PUSH       EBP
//         004117d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:46 (21)
//         004117db     MOV        EDX,dword ptr [ESP + i]
//         004117df     ADD        ESP,0xc
//         004117e2     LEA        EAX,[ESI + 0x14c]
//         004117e8     PUSH       EDX
//         004117e9     PUSH       EAX
//         004117ea     PUSH       EBP
//         004117eb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:47 (7)
//         004117f0     MOV        this,dword ptr [ESP + i]
//         004117f4     ADD        ESP,0xc
//                              airchmod.cpp:50 (26)
//         004117f7     MOV        dword ptr [ESP + typeID],0x0
//         004117ff     MOV        byte ptr [ECX + ESI*0x1 + this->techTreeNameVa
//         00411807     MOV        EAX,dword ptr [EBX]
//         00411809     TEST       EAX,EAX
//         0041180b     JLE        LAB_00411923
//                               LAB_00411811                                                 XREF[1]:     0041191d(j)
//                              airchmod.cpp:53 (13)
//         00411811     LEA        EDX=>i,[ESP + 0x10]
//         00411815     PUSH       0x4
//         00411817     PUSH       EDX
//         00411818     PUSH       EBP
//         00411819     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:54 (22)
//         0041181e     MOV        EAX,dword ptr [ESP + i]
//         00411822     ADD        ESP,0xc
//         00411825     LEA        this=>name[4],[ESP + 0xa8]
//         0041182c     PUSH       EAX
//         0041182d     PUSH       this
//         0041182e     PUSH       EBP
//         0041182f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:55 (7)
//         00411834     MOV        EDX,dword ptr [ESP + i]
//         00411838     ADD        ESP,0xc
//                              airchmod.cpp:57 (33)
//         0041183b     LEA        EAX=>local_1a0,[ESP + 0x18]
//         0041183f     PUSH       0x4
//         00411841     PUSH       EAX
//         00411842     PUSH       EBP
//         00411843     MOV        byte ptr [ESP + EDX*0x1 + 0xb4],0x0
//         0041184b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00411850     ADD        ESP,0xc
//         00411853     LEA        EDI=>rc[1],[ESP + 0x28]
//         00411857     MOV        EBX,0x4
//                               LAB_0041185c                                                 XREF[1]:     00411876(j)
//                              airchmod.cpp:62 (13)
//         0041185c     LEA        this=>i,[ESP + 0x10]
//         00411860     PUSH       0x4
//         00411862     PUSH       this
//         00411863     PUSH       EBP
//         00411864     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:63 (15)
//         00411869     MOV        EDX,dword ptr [ESP + i]
//         0041186d     ADD        ESP,0xc
//         00411870     MOV        dword ptr [EDI]=>rc[1],EDX
//         00411872     ADD        EDI,0x4
//         00411875     DEC        EBX
//         00411876     JNZ        LAB_0041185c
//                              airchmod.cpp:65 (16)
//         00411878     LEA        EAX=>rc[1],[ESP + 0x28]
//         0041187c     LEA        this=>newRCost.next,[ESP + 0x38]
//         00411880     PUSH       EAX
//         00411881     PUSH       0x4
//         00411883     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
//                              airchmod.cpp:67 (88)
//         00411888     PUSH       0x54
//         0041188a     MOV        byte ptr [ESP + local_4],0x2
//         00411892     CALL       operator_new                                     void * operator_new(uint param_1)
//         00411897     MOV        EDI,EAX
//         00411899     ADD        ESP,0x4
//         0041189c     MOV        dword ptr [ESP + local_19c],EDI
//         004118a0     TEST       EDI,EDI
//         004118a2     MOV        byte ptr [ESP + local_4],0x3
//         004118aa     JZ         LAB_004118de
//         004118ac     SUB        ESP,0x70
//         004118af     LEA        EDX=>newRCost.next,[ESP + 0xa8]
//         004118b6     MOV        this,ESP
//         004118b8     MOV        dword ptr [ESP + rc[0]],ESP
//         004118bf     PUSH       EDX
//         004118c0     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, R
//         004118c5     MOV        this,dword ptr [ESP + local_1a0]
//         004118cc     LEA        EAX=>name[4],[ESP + 0x118]
//         004118d3     PUSH       EAX
//         004118d4     PUSH       this
//         004118d5     MOV        this,EDI
//         004118d7     CALL       TechnologyItem::TechnologyItem                   undefined TechnologyItem(TechnologyItem * thi
//         004118dc     JMP        LAB_004118e0
//                               LAB_004118de                                                 XREF[1]:     004118aa(j)
//         004118de     XOR        EAX,EAX
//                               LAB_004118e0                                                 XREF[1]:     004118dc(j)
//                              airchmod.cpp:70 (6)
//         004118e0     LEA        this,[ESI + 0xf4]
//                              airchmod.cpp:74 (61)
//         004118e6     MOV        byte ptr [ESP + local_4],0x1
//         004118ee     MOV        dword ptr [EAX + 0x4],this
//         004118f1     MOV        this,dword ptr [ESI + 0xfc]
//         004118f7     MOV        dword ptr [EAX + 0x8],this
//         004118fa     MOV        dword ptr [ECX + this->_padding_],EAX
//         004118fd     LEA        this=>newRCost.next,[ESP + 0x38]
//         00411901     MOV        dword ptr [ESI + 0xfc],EAX
//         00411907     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
//         0041190c     MOV        EAX,dword ptr [ESP + typeID]
//         00411910     MOV        this,dword ptr [ESI + 0x148]
//         00411916     INC        EAX
//         00411917     CMP        EAX,this
//         00411919     MOV        dword ptr [ESP + typeID],EAX
//         0041191d     JL         LAB_00411811
//                               LAB_00411923                                                 XREF[1]:     0041180b(j)
//                              airchmod.cpp:75 (29)
//         00411923     MOV        this,dword ptr [ESP + local_c]
//         0041192a     MOV        EAX,ESI
//         0041192c     POP        EDI
//         0041192d     POP        ESI
//         0041192e     POP        EBP
//         0041192f     MOV        dword ptr FS:[0x0],this
//         00411936     POP        EBX
//         00411937     ADD        ESP,0x1a8
//         0041193d     RET        0x8
}

ResearchAIModule::ResearchAIModule(int param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall ResearchAIModule(ResearchAIModule * this, int p
//              undefined         <UNASSIGNED>   <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041175b(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004117ac(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     00411785(W), 004117a2(W), 0041188a(W), 004118a2(W),
//                                                                                     004118e6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00411923(R)
//              char[257]         Stack[-0x114   name                      XREF[0,2]:   00411825(*), 004118cc(*)
//              ResourceItem      Stack[-0x184   newRCost                  XREF[0,3]:   0041187c(*), 004118af(*), 004118fd(*)
//              int[4]            Stack[-0x194   rc                        XREF[1,3]:   004118b8(W), 00411853(*), 00411870(*), 00411878(*)
//              undefined4        Stack[-0x198   local_198                 XREF[1]:     00411776(W)
//              undefined4        Stack[-0x19c   local_19c                 XREF[1]:     0041189c(W)
//              undefined4        Stack[-0x1a0   local_1a0                 XREF[2]:     0041183b(*), 004118c5(R)
//              int               Stack[-0x1a4   typeID                    XREF[3]:     004117f7(W), 0041190c(R), 00411919(W)
//              int               Stack[-0x1a8   i                         XREF[8]:     004117ce(*), 004117db(R), 004117f0(R), 00411811(*),
//                                                                                     0041181e(R), 00411834(R), 0041185c(*), 00411869(R)
//              int               Stack[-0x1ac   tempInt
//                               ??0ResearchAIModule@@QAE@HH@Z
//                               ResearchAIModule::ResearchAIModule
//                              airchmod.cpp:38 (95)
//         00411740     PUSH       -0x1
//         00411742     PUSH       FUN_0055c7a5
//         00411747     MOV        EAX,FS:[0x0]
//         0041174d     PUSH       EAX
//         0041174e     MOV        dword ptr FS:[0x0],ESP
//         00411755     SUB        ESP,0x19c
//         0041175b     MOV        EAX,dword ptr [ESP + param_1]
//         00411762     PUSH       EBX
//         00411763     PUSH       EBP
//         00411764     PUSH       ESI
//         00411765     XOR        EBP,EBP
//         00411767     PUSH       EDI
//         00411768     PUSH       EBP
//         00411769     PUSH       EAX
//         0041176a     MOV        ESI,this
//         0041176c     PUSH       0x3ee
//         00411771     PUSH       s_Research_AI                                    = "Research AI"
//         00411776     MOV        dword ptr [ESP + local_198],ESI
//         0041177a     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
//         0041177f     LEA        EDI,[ESI + 0xf4]
//         00411785     MOV        dword ptr [ESP + local_4],EBP
//         0041178c     MOV        this,EDI
//         0041178e     MOV        dword ptr [ESI + 0xf0],EBP
//         00411794     CALL       TechnologyItem::TechnologyItem                   undefined TechnologyItem(TechnologyItem * this)
//         00411799     LEA        EBX,[ESI + 0x148]
//                              airchmod.cpp:42 (47)
//         0041179f     PUSH       0x4
//         004117a1     PUSH       EBX
//         004117a2     MOV        byte ptr [ESP + local_4],0x1
//         004117aa     MOV        dword ptr [EBX],EBP
//         004117ac     MOV        EBP,dword ptr [ESP + param_2]
//         004117b3     PUSH       EBP
//         004117b4     MOV        dword ptr [ESI],ResearchAIModule::`vftable'      = 00411720
//         004117ba     MOV        dword ptr [ESI + 0xf8],EDI
//         004117c0     MOV        dword ptr [ESI + 0xfc],EDI
//         004117c6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004117cb     ADD        ESP,0xc
//                              airchmod.cpp:45 (13)
//         004117ce     LEA        this=>i,[ESP + 0x10]
//         004117d2     PUSH       0x4
//         004117d4     PUSH       this
//         004117d5     PUSH       EBP
//         004117d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:46 (21)
//         004117db     MOV        EDX,dword ptr [ESP + i]
//         004117df     ADD        ESP,0xc
//         004117e2     LEA        EAX,[ESI + 0x14c]
//         004117e8     PUSH       EDX
//         004117e9     PUSH       EAX
//         004117ea     PUSH       EBP
//         004117eb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:47 (7)
//         004117f0     MOV        this,dword ptr [ESP + i]
//         004117f4     ADD        ESP,0xc
//                              airchmod.cpp:50 (26)
//         004117f7     MOV        dword ptr [ESP + typeID],0x0
//         004117ff     MOV        byte ptr [ECX + ESI*0x1 + this->techTreeNameVa
//         00411807     MOV        EAX,dword ptr [EBX]
//         00411809     TEST       EAX,EAX
//         0041180b     JLE        LAB_00411923
//                               LAB_00411811                                                 XREF[1]:     0041191d(j)
//                              airchmod.cpp:53 (13)
//         00411811     LEA        EDX=>i,[ESP + 0x10]
//         00411815     PUSH       0x4
//         00411817     PUSH       EDX
//         00411818     PUSH       EBP
//         00411819     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:54 (22)
//         0041181e     MOV        EAX,dword ptr [ESP + i]
//         00411822     ADD        ESP,0xc
//         00411825     LEA        this=>name[4],[ESP + 0xa8]
//         0041182c     PUSH       EAX
//         0041182d     PUSH       this
//         0041182e     PUSH       EBP
//         0041182f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:55 (7)
//         00411834     MOV        EDX,dword ptr [ESP + i]
//         00411838     ADD        ESP,0xc
//                              airchmod.cpp:57 (33)
//         0041183b     LEA        EAX=>local_1a0,[ESP + 0x18]
//         0041183f     PUSH       0x4
//         00411841     PUSH       EAX
//         00411842     PUSH       EBP
//         00411843     MOV        byte ptr [ESP + EDX*0x1 + 0xb4],0x0
//         0041184b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00411850     ADD        ESP,0xc
//         00411853     LEA        EDI=>rc[1],[ESP + 0x28]
//         00411857     MOV        EBX,0x4
//                               LAB_0041185c                                                 XREF[1]:     00411876(j)
//                              airchmod.cpp:62 (13)
//         0041185c     LEA        this=>i,[ESP + 0x10]
//         00411860     PUSH       0x4
//         00411862     PUSH       this
//         00411863     PUSH       EBP
//         00411864     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              airchmod.cpp:63 (15)
//         00411869     MOV        EDX,dword ptr [ESP + i]
//         0041186d     ADD        ESP,0xc
//         00411870     MOV        dword ptr [EDI]=>rc[1],EDX
//         00411872     ADD        EDI,0x4
//         00411875     DEC        EBX
//         00411876     JNZ        LAB_0041185c
//                              airchmod.cpp:65 (16)
//         00411878     LEA        EAX=>rc[1],[ESP + 0x28]
//         0041187c     LEA        this=>newRCost.next,[ESP + 0x38]
//         00411880     PUSH       EAX
//         00411881     PUSH       0x4
//         00411883     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
//                              airchmod.cpp:67 (88)
//         00411888     PUSH       0x54
//         0041188a     MOV        byte ptr [ESP + local_4],0x2
//         00411892     CALL       operator_new                                     void * operator_new(uint param_1)
//         00411897     MOV        EDI,EAX
//         00411899     ADD        ESP,0x4
//         0041189c     MOV        dword ptr [ESP + local_19c],EDI
//         004118a0     TEST       EDI,EDI
//         004118a2     MOV        byte ptr [ESP + local_4],0x3
//         004118aa     JZ         LAB_004118de
//         004118ac     SUB        ESP,0x70
//         004118af     LEA        EDX=>newRCost.next,[ESP + 0xa8]
//         004118b6     MOV        this,ESP
//         004118b8     MOV        dword ptr [ESP + rc[0]],ESP
//         004118bf     PUSH       EDX
//         004118c0     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, R
//         004118c5     MOV        this,dword ptr [ESP + local_1a0]
//         004118cc     LEA        EAX=>name[4],[ESP + 0x118]
//         004118d3     PUSH       EAX
//         004118d4     PUSH       this
//         004118d5     MOV        this,EDI
//         004118d7     CALL       TechnologyItem::TechnologyItem                   undefined TechnologyItem(TechnologyItem * thi
//         004118dc     JMP        LAB_004118e0
//                               LAB_004118de                                                 XREF[1]:     004118aa(j)
//         004118de     XOR        EAX,EAX
//                               LAB_004118e0                                                 XREF[1]:     004118dc(j)
//                              airchmod.cpp:70 (6)
//         004118e0     LEA        this,[ESI + 0xf4]
//                              airchmod.cpp:74 (61)
//         004118e6     MOV        byte ptr [ESP + local_4],0x1
//         004118ee     MOV        dword ptr [EAX + 0x4],this
//         004118f1     MOV        this,dword ptr [ESI + 0xfc]
//         004118f7     MOV        dword ptr [EAX + 0x8],this
//         004118fa     MOV        dword ptr [ECX + this->_padding_],EAX
//         004118fd     LEA        this=>newRCost.next,[ESP + 0x38]
//         00411901     MOV        dword ptr [ESI + 0xfc],EAX
//         00411907     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
//         0041190c     MOV        EAX,dword ptr [ESP + typeID]
//         00411910     MOV        this,dword ptr [ESI + 0x148]
//         00411916     INC        EAX
//         00411917     CMP        EAX,this
//         00411919     MOV        dword ptr [ESP + typeID],EAX
//         0041191d     JL         LAB_00411811
//                               LAB_00411923                                                 XREF[1]:     0041180b(j)
//                              airchmod.cpp:75 (29)
//         00411923     MOV        this,dword ptr [ESP + local_c]
//         0041192a     MOV        EAX,ESI
//         0041192c     POP        EDI
//         0041192d     POP        ESI
//         0041192e     POP        EBP
//         0041192f     MOV        dword ptr FS:[0x0],this
//         00411936     POP        EBX
//         00411937     ADD        ESP,0x1a8
//         0041193d     RET        0x8
}

ResearchAIModule::~ResearchAIModule() {
    /* TODO: Stub */
//                              void __thiscall ~ResearchAIModule(ResearchAIModule * this)
//              void              <VOID>         <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00411969(W), 00411980(W), 0041198c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00411999(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00411959(W)
//                               ??1ResearchAIModule@@UAE@XZ                                  XREF[1]:     `scalar_deleting_destructor':00411
//                               ResearchAIModule::~ResearchAIModule
//                              airchmod.cpp:80 (35)
//         00411940     PUSH       -0x1
//         00411942     PUSH       FUN_0055c7c6
//         00411947     MOV        EAX,FS:[0x0]
//         0041194d     PUSH       EAX
//         0041194e     MOV        dword ptr FS:[0x0],ESP
//         00411955     PUSH       this
//         00411956     PUSH       ESI
//         00411957     MOV        ESI,this
//         00411959     MOV        dword ptr [ESP + local_10],ESI
//         0041195d     MOV        dword ptr [ESI],ResearchAIModule::`vftable'      = 00411720
//                              airchmod.cpp:81 (18)
//         00411963     MOV        EAX,dword ptr [ESI + 0x148]
//         00411969     MOV        dword ptr [ESP + local_4],0x1
//         00411971     TEST       EAX,EAX
//         00411973     JLE        LAB_0041197a
//                              airchmod.cpp:82 (11)
//         00411975     CALL       ResearchAIModule::removeOldTechTree              void removeOldTechTree(ResearchAIModule * this)
//                               LAB_0041197a                                                 XREF[1]:     00411973(j)
//         0041197a     LEA        this,[ESI + 0xf4]
//                              airchmod.cpp:83 (41)
//         00411980     MOV        byte ptr [ESP + local_4],0x0
//         00411985     CALL       TechnologyItem::~TechnologyItem                  void ~TechnologyItem(TechnologyItem * this)
//         0041198a     MOV        this,ESI
//         0041198c     MOV        dword ptr [ESP + local_4],0xffffffff
//         00411994     CALL       AIModule::~AIModule                              void ~AIModule(AIModule * this)
//         00411999     MOV        this,dword ptr [ESP + local_c]
//         0041199d     POP        ESI
//         0041199e     MOV        dword ptr FS:[0x0],this
//         004119a5     ADD        ESP,0x10
//         004119a8     RET
//         004119a9     ??         90h
//         004119aa     NOP
//         004119ab     NOP
//         004119ac     NOP
//         004119ad     NOP
//         004119ae     NOP
//         004119af     NOP
}

void ResearchAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    /* TODO: Stub */
//                              void __thiscall setMainDecisionAI(ResearchAIModule * this, MainDecis
//              void              <VOID>         <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              MainDecisionAI    Stack[0x4]:4   param_1                   XREF[1]:     004119b0(R)
//                               ?setMainDecisionAI@ResearchAIModule@@QAEXPAVMainDecisionAIM
//                               ResearchAIModule::setMainDecisionAI
//                              airchmod.cpp:88 (10)
//         004119b0     MOV        EAX,dword ptr [ESP + param_1]
//         004119b4     MOV        dword ptr [ECX + this->md],EAX
//                              airchmod.cpp:90 (3)
//         004119ba     RET        0x4
//         004119bd     ??         90h
//         004119be     NOP
//         004119bf     NOP
    return;
}

int ResearchAIModule::save(int param_1) {
    /* TODO: Stub */
//                              int __thiscall save(ResearchAIModule * this, int param_1)
//              int               EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004119c7(R)
//              char[257]         Stack[-0x108   tempString                XREF[4,7]:   004119dd(W), 00411a4c(R), 00411a60(W), 00411b1c(R),
//                                                                                     004119fa(*), 00411a14(*), 00411a2f(*), 00411a40(*),
//                                                                                     00411a80(*), 00411aa0(*), 00411ac2(*)
//              undefined4        Stack[-0x10c   local_10c                 XREF[9]:     00411a20(W), 00411a24(*), 00411aac(W), 00411ab0(*),
//                                                                                     00411abb(R), 00411ad8(*), 00411ae0(W), 00411aff(*),
//                                                                                     00411b07(W)
//              int               Stack[-0x110   tempInt
//                               ?save@ResearchAIModule@@UAEHH@Z                              XREF[1]:     0056e9c4(*)
//                               ResearchAIModule::save
//                              airchmod.cpp:95 (7)
//         004119c0     SUB        ESP,0x10c
//         004119c6     PUSH       EBX
//                              airchmod.cpp:100 (31)
//         004119c7     MOV        EBX,dword ptr [ESP + param_1]
//         004119ce     PUSH       EBP
//         004119cf     MOV        EBP,this
//         004119d1     PUSH       ESI
//         004119d2     PUSH       EDI
//         004119d3     LEA        EAX,[EBP + 0x148]
//         004119d9     PUSH       0x4
//         004119db     PUSH       EAX
//         004119dc     PUSH       EBX
//         004119dd     MOV        dword ptr [ESP + tempString[0]],EBP
//         004119e1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              airchmod.cpp:103 (30)
//         004119e6     LEA        EDI,[EBP + 0x14c]
//         004119ec     OR         this,0xffffffff
//         004119ef     XOR        EAX,EAX
//         004119f1     ADD        ESP,0xc
//         004119f4     SCASB.RE   ES:EDI
//         004119f6     NOT        this
//         004119f8     SUB        EDI,this
//         004119fa     LEA        EDX=>tempString[4],[ESP + 0x18]
//         004119fe     MOV        EAX,this
//         00411a00     MOV        ESI,EDI
//         00411a02     MOV        EDI,EDX
//                              airchmod.cpp:105 (43)
//         00411a04     PUSH       0x4
//         00411a06     SHR        this,0x2
//         00411a09     MOVSD.REP  ES:EDI,ESI
//         00411a0b     MOV        this,EAX
//         00411a0d     XOR        EAX,EAX
//         00411a0f     AND        this,0x3
//         00411a12     MOVSB.REP  ES:EDI,ESI
//         00411a14     LEA        EDI=>tempString[4],[ESP + 0x1c]
//         00411a18     OR         this,0xffffffff
//         00411a1b     SCASB.RE   ES:EDI
//         00411a1d     NOT        this
//         00411a1f     DEC        this
//         00411a20     MOV        dword ptr [ESP + local_10c],this
//         00411a24     LEA        this=>local_10c,[ESP + 0x14]
//         00411a28     PUSH       this
//         00411a29     PUSH       EBX
//         00411a2a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              airchmod.cpp:106 (29)
//         00411a2f     LEA        EDI=>tempString[4],[ESP + 0x24]
//         00411a33     OR         this,0xffffffff
//         00411a36     XOR        EAX,EAX
//         00411a38     ADD        ESP,0xc
//         00411a3b     SCASB.RE   ES:EDI
//         00411a3d     NOT        this
//         00411a3f     DEC        this
//         00411a40     LEA        EDX=>tempString[4],[ESP + 0x18]
//         00411a44     PUSH       this
//         00411a45     PUSH       EDX
//         00411a46     PUSH       EBX
//         00411a47     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              airchmod.cpp:109 (38)
//         00411a4c     MOV        EAX,dword ptr [ESP + tempString[0]]
//         00411a50     MOV        EBP,dword ptr [EBP + 0xf8]
//         00411a56     ADD        EAX,0xf4
//         00411a5b     ADD        ESP,0xc
//         00411a5e     CMP        EBP,EAX
//         00411a60     MOV        dword ptr [ESP + tempString[0]],EAX
//         00411a64     JZ         LAB_00411b28
//                               LAB_00411a6a                                                 XREF[1]:     00411b22(j)
//         00411a6a     TEST       EBP,EBP
//         00411a6c     JZ         LAB_00411b28
//                              airchmod.cpp:111 (24)
//         00411a72     MOV        this,EBP
//         00411a74     CALL       TechnologyItem::name                             char * name(TechnologyItem * this)
//         00411a79     MOV        EDI,EAX
//         00411a7b     OR         this,0xffffffff
//         00411a7e     XOR        EAX,EAX
//         00411a80     LEA        EDX=>tempString[4],[ESP + 0x18]
//         00411a84     SCASB.RE   ES:EDI
//         00411a86     NOT        this
//         00411a88     SUB        EDI,this
//                              airchmod.cpp:113 (49)
//         00411a8a     PUSH       0x4
//         00411a8c     MOV        EAX,this
//         00411a8e     MOV        ESI,EDI
//         00411a90     MOV        EDI,EDX
//         00411a92     SHR        this,0x2
//         00411a95     MOVSD.REP  ES:EDI,ESI
//         00411a97     MOV        this,EAX
//         00411a99     XOR        EAX,EAX
//         00411a9b     AND        this,0x3
//         00411a9e     MOVSB.REP  ES:EDI,ESI
//         00411aa0     LEA        EDI=>tempString[4],[ESP + 0x1c]
//         00411aa4     OR         this,0xffffffff
//         00411aa7     SCASB.RE   ES:EDI
//         00411aa9     NOT        this
//         00411aab     DEC        this
//         00411aac     MOV        dword ptr [ESP + local_10c],this
//         00411ab0     LEA        this=>local_10c,[ESP + 0x14]
//         00411ab4     PUSH       this
//         00411ab5     PUSH       EBX
//         00411ab6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              airchmod.cpp:114 (22)
//         00411abb     MOV        EDX,dword ptr [ESP + local_10c]
//         00411abf     ADD        ESP,0xc
//         00411ac2     LEA        EAX=>tempString[4],[ESP + 0x18]
//         00411ac6     PUSH       EDX
//         00411ac7     PUSH       EAX
//         00411ac8     PUSH       EBX
//         00411ac9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00411ace     ADD        ESP,0xc
//                              airchmod.cpp:115 (7)
//         00411ad1     MOV        this,EBP
//         00411ad3     CALL       TechnologyItem::id                               int id(TechnologyItem * this)
//                              airchmod.cpp:116 (20)
//         00411ad8     LEA        this=>local_10c,[ESP + 0x10]
//         00411adc     PUSH       0x4
//         00411ade     PUSH       this
//         00411adf     PUSH       EBX
//         00411ae0     MOV        dword ptr [ESP + local_10c],EAX
//         00411ae4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00411ae9     ADD        ESP,0xc
//                              airchmod.cpp:119 (9)
//         00411aec     MOV        this,EBP
//         00411aee     CALL       TechnologyItem::resourceCost                     ResourceItem * resourceCost(TechnologyItem *
//         00411af3     MOV        EDI,EAX
//                              airchmod.cpp:120 (2)
//         00411af5     XOR        ESI,ESI
//                               LAB_00411af7                                                 XREF[1]:     00411b17(j)
//                              airchmod.cpp:121 (8)
//         00411af7     PUSH       ESI
//         00411af8     MOV        this,EDI
//         00411afa     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
//                              airchmod.cpp:122 (26)
//         00411aff     LEA        EDX=>local_10c,[ESP + 0x10]
//         00411b03     PUSH       0x4
//         00411b05     PUSH       EDX
//         00411b06     PUSH       EBX
//         00411b07     MOV        dword ptr [ESP + local_10c],EAX
//         00411b0b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00411b10     ADD        ESP,0xc
//         00411b13     INC        ESI
//         00411b14     CMP        ESI,0x4
//         00411b17     JL         LAB_00411af7
//                              airchmod.cpp:126 (15)
//         00411b19     MOV        EBP,dword ptr [EBP + 0x4]
//         00411b1c     MOV        EAX,dword ptr [ESP + tempString[0]]
//         00411b20     CMP        EBP,EAX
//         00411b22     JNZ        LAB_00411a6a
//                               LAB_00411b28                                                 XREF[2]:     00411a64(j), 00411a6c(j)
//                              airchmod.cpp:129 (18)
//         00411b28     POP        EDI
//         00411b29     POP        ESI
//         00411b2a     POP        EBP
//         00411b2b     MOV        EAX,0x1
//         00411b30     POP        EBX
//         00411b31     ADD        ESP,0x10c
//         00411b37     RET        0x4
//         00411b3a     ??         90h
//         00411b3b     NOP
//         00411b3c     NOP
//         00411b3d     NOP
//         00411b3e     NOP
//         00411b3f     NOP
    return 0;
}

ResourceItem* ResearchAIModule::resourceCost(int param_1) {
    /* TODO: Stub */
//                              ResourceItem * __thiscall resourceCost(ResearchAIModule * this, int
//              ResourceItem *    EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00411b40(R)
//                               ?resourceCost@ResearchAIModule@@QAEPAVResourceItem@@H@Z
//                               ResearchAIModule::resourceCost
//                              airchmod.cpp:134 (10)
//         00411b40     MOV        EAX,dword ptr [ESP + param_1]
//         00411b44     PUSH       EAX
//         00411b45     CALL       ResearchAIModule::item                           TechnologyItem * item(ResearchAIModule * this
//                              airchmod.cpp:136 (4)
//         00411b4a     TEST       EAX,EAX
//         00411b4c     JNZ        LAB_00411b51
//                              airchmod.cpp:139 (3)
//         00411b4e     RET        0x4
//                               LAB_00411b51                                                 XREF[1]:     00411b4c(j)
//                              airchmod.cpp:138 (7)
//         00411b51     MOV        this,EAX
//         00411b53     CALL       TechnologyItem::resourceCost                     ResourceItem * resourceCost(TechnologyItem *
//                              airchmod.cpp:139 (3)
//         00411b58     RET        0x4
//         00411b5b     ??         90h
//         00411b5c     NOP
//         00411b5d     NOP
//         00411b5e     NOP
//         00411b5f     NOP
    return 0;
}

int ResearchAIModule::buildable(BuildItem* param_1) {
    /* TODO: Stub */
//                              int __thiscall buildable(ResearchAIModule * this, BuildItem * param_1)
//              int               EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1
//                               ?buildable@ResearchAIModule@@UAEHPAVBuildItem@@@Z            XREF[1]:     0056e9c8(*)
//                               ResearchAIModule::buildable
//                              airchmod.cpp:144 (5)
//         00411b60     MOV        EAX,0x1
//                              airchmod.cpp:147 (3)
//         00411b65     RET        0x4
//         00411b68     ??         90h
//         00411b69     NOP
//         00411b6a     NOP
//         00411b6b     NOP
//         00411b6c     NOP
//         00411b6d     NOP
//         00411b6e     NOP
//         00411b6f     NOP
    return 0;
}

void ResearchAIModule::research(BuildItem* param_1) {
    /* TODO: Stub */
//                              void __thiscall research(ResearchAIModule * this, BuildItem * param_1)
//              void              <VOID>         <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              BuildItem *       Stack[0x4]:4   param_1
//                               ?research@ResearchAIModule@@UAEXPAVBuildItem@@@Z             XREF[1]:     0056e9cc(*)
//                               ResearchAIModule::research
//                              airchmod.cpp:152 (3)
//         00411b70     RET        0x4
//         00411b73     ??         90h
//         00411b74     NOP
//         00411b75     NOP
//         00411b76     NOP
//         00411b77     NOP
//         00411b78     NOP
//         00411b79     NOP
//         00411b7a     NOP
//         00411b7b     NOP
//         00411b7c     NOP
//         00411b7d     NOP
//         00411b7e     NOP
//         00411b7f     NOP
    return;
}

int ResearchAIModule::loadTechnologyTree(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall loadTechnologyTree(ResearchAIModule * this, char * pa
//              int               EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[2]:     00411bb0(R), 00411c1e(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00411cd2(W), 00411ced(W), 00411d37(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00411de2(R)
//              char[256]         Stack[-0x110   temp                      XREF[0,5]:   00411c34(*), 00411c4a(*), 00411c6a(*), 00411cab(*),
//                                                                                     00411d62(*)
//              ResourceItem      Stack[-0x180   newRCost                  XREF[0,3]:   00411cc4(*), 00411cfa(*), 00411d4c(*)
//              char[64]          Stack[-0x1c0   name                      XREF[1,2]:   00411ce7(W), 00411ca0(*), 00411d17(*)
//              undefined4        Stack[-0x1c4   local_1c4                 XREF[1]:     00411d03(W)
//              undefined         Stack[-0x1c8   local_1c8                 XREF[1]:     00411c8d(*)
//              int[4]            Stack[-0x1d8   rc                        XREF[2,4]:   00411ca5(*), 00411d10(R), 00411c9b(*), 00411cc0(*),
//                                                                                     00411c96(*), 00411c91(*)
//              int               Stack[-0x1dc   id                        XREF[2]:     00411bc8(W), 00411d7f(R)
//                               ?loadTechnologyTree@ResearchAIModule@@QAEHPAD@Z
//                               ResearchAIModule::loadTechnologyTree
//                              airchmod.cpp:159 (33)
//         00411b80     MOV        EAX,FS:[0x0]
//         00411b86     PUSH       -0x1
//         00411b88     PUSH       FUN_0055c7e9
//         00411b8d     PUSH       EAX
//         00411b8e     MOV        dword ptr FS:[0x0],ESP
//         00411b95     SUB        ESP,0x1d0
//         00411b9b     PUSH       EBX
//         00411b9c     PUSH       EBP
//         00411b9d     MOV        EBP,this
//         00411b9f     PUSH       ESI
//         00411ba0     PUSH       EDI
//                              airchmod.cpp:161 (10)
//         00411ba1     MOV        EAX,dword ptr [EBP + 0x148]
//         00411ba7     TEST       EAX,EAX
//         00411ba9     JLE        LAB_00411bb0
//                              airchmod.cpp:162 (5)
//         00411bab     CALL       ResearchAIModule::removeOldTechTree              void removeOldTechTree(ResearchAIModule * this)
//                               LAB_00411bb0                                                 XREF[1]:     00411ba9(j)
//                              airchmod.cpp:165 (41)
//         00411bb0     MOV        EDI,dword ptr [ESP + param_1]
//         00411bb7     OR         this,0xffffffff
//         00411bba     XOR        EAX,EAX
//         00411bbc     LEA        EBX,[EBP + 0x14c]
//         00411bc2     SCASB.RE   ES:EDI
//         00411bc4     NOT        this
//         00411bc6     SUB        EDI,this
//         00411bc8     MOV        dword ptr [ESP + id],EBX
//         00411bcc     MOV        EAX,this
//         00411bce     MOV        ESI,EDI
//         00411bd0     MOV        EDI,EBX
//         00411bd2     SHR        this,0x2
//         00411bd5     MOVSD.REP  ES:EDI,ESI
//         00411bd7     MOV        this,EAX
//                              airchmod.cpp:167 (69)
//         00411bd9     MOV        EAX,EBX
//         00411bdb     AND        this,0x3
//         00411bde     MOVSB.REP  ES:EDI,ESI
//         00411be0     MOV        ESI,s_NONE                                       = 4Eh
//                               LAB_00411be5                                                 XREF[1]:     00411c03(j)
//         00411be5     MOV        DL,byte ptr [EAX]
//         00411be7     MOV        this,DL
//         00411be9     CMP        DL,byte ptr [ESI]=>s_NONE                        = 4Eh
//         00411beb     JNZ        LAB_00411c09
//         00411bed     TEST       this,this
//         00411bef     JZ         LAB_00411c05
//         00411bf1     MOV        DL,byte ptr [EAX + 0x1]
//         00411bf4     MOV        this,DL
//         00411bf6     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0057f351            = 4Fh
//                                                                                  = 45h
//         00411bf9     JNZ        LAB_00411c09
//         00411bfb     ADD        EAX,0x2
//         00411bfe     ADD        ESI,0x2
//         00411c01     TEST       this,this
//         00411c03     JNZ        LAB_00411be5
//                               LAB_00411c05                                                 XREF[1]:     00411bef(j)
//         00411c05     XOR        EAX,EAX
//         00411c07     JMP        LAB_00411c0e
//                               LAB_00411c09                                                 XREF[2]:     00411beb(j), 00411bf9(j)
//         00411c09     SBB        EAX,EAX
//         00411c0b     SBB        EAX,-0x1
//                               LAB_00411c0e                                                 XREF[1]:     00411c07(j)
//         00411c0e     TEST       EAX,EAX
//         00411c10     JZ         LAB_00411da9
//         00411c16     TEST       EBX,EBX
//         00411c18     JZ         LAB_00411dad
//                              airchmod.cpp:173 (22)
//         00411c1e     MOV        EAX,dword ptr [ESP + param_1]
//         00411c25     PUSH       EAX
//         00411c26     PUSH       s_Loading_tech_tree_in_file_'%s'.                = "Loading tech tree in file '%s'."
//         00411c2b     PUSH       EBP
//         00411c2c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         00411c31     ADD        ESP,0xc
//                              airchmod.cpp:175 (22)
//         00411c34     LEA        this=>temp[4],[ESP + 0xe0]
//         00411c3b     PUSH       EBX
//         00411c3c     PUSH       s_%s                                             = "%s"
//         00411c41     PUSH       this
//         00411c42     CALL       sprintf                                          undefined sprintf()
//         00411c47     ADD        ESP,0xc
//                              airchmod.cpp:176 (23)
//         00411c4a     LEA        EDX=>temp[4],[ESP + 0xe0]
//         00411c51     PUSH       s_r                                              = "r"
//         00411c56     PUSH       EDX
//         00411c57     CALL       fopen                                            undefined fopen()
//         00411c5c     MOV        EDI,EAX
//         00411c5e     ADD        ESP,0x8
//                              airchmod.cpp:177 (8)
//         00411c61     TEST       EDI,EDI
//         00411c63     JZ         LAB_00411de2
//                              airchmod.cpp:179 (30)
//         00411c69     PUSH       EDI
//         00411c6a     LEA        EAX=>temp[4],[ESP + 0xe4]
//         00411c71     PUSH       0x100
//         00411c76     PUSH       EAX
//         00411c77     CALL       fgets                                            undefined fgets()
//         00411c7c     ADD        ESP,0xc
//         00411c7f     TEST       EAX,EAX
//         00411c81     JZ         LAB_00411d83
//                              airchmod.cpp:195 (6)
//         00411c87     LEA        EBX,[EBP + 0xf4]
//                               LAB_00411c8d                                                 XREF[1]:     00411d79(j)
//                              airchmod.cpp:187 (51)
//         00411c8d     LEA        this=>local_1c8,[ESP + 0x24]
//         00411c91     LEA        EDX=>rc[3],[ESP + 0x20]
//         00411c95     PUSH       this
//         00411c96     LEA        EAX=>rc[2],[ESP + 0x20]
//         00411c9a     PUSH       EDX
//         00411c9b     LEA        this=>rc[1],[ESP + 0x20]
//         00411c9f     PUSH       EAX
//         00411ca0     LEA        EDX=>name[4],[ESP + 0x3c]
//         00411ca4     PUSH       this
//         00411ca5     LEA        EAX=>rc,[ESP + 0x24]
//         00411ca9     PUSH       EDX
//         00411caa     PUSH       EAX
//         00411cab     LEA        this=>temp[4],[ESP + 0xf8]
//         00411cb2     PUSH       s_%*c%d_%s_%*d_%*d_%d_%d_%d_%d_%*d               = "%*c%d %s %*d %*d %d %d %d %d %*d %*d %*d %
//         00411cb7     PUSH       this
//         00411cb8     CALL       sscanf                                           undefined sscanf()
//         00411cbd     ADD        ESP,0x20
//                              airchmod.cpp:188 (16)
//         00411cc0     LEA        EDX=>rc[1],[ESP + 0x18]
//         00411cc4     LEA        this=>newRCost.next,[ESP + 0x70]
//         00411cc8     PUSH       EDX
//         00411cc9     PUSH       0x4
//         00411ccb     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, i
//                              airchmod.cpp:189 (91)
//         00411cd0     PUSH       0x54
//         00411cd2     MOV        dword ptr [ESP + local_4],0x0
//         00411cdd     CALL       operator_new                                     void * operator_new(uint param_1)
//         00411ce2     MOV        ESI,EAX
//         00411ce4     ADD        ESP,0x4
//         00411ce7     MOV        dword ptr [ESP + name[0]],ESI
//         00411ceb     TEST       ESI,ESI
//         00411ced     MOV        byte ptr [ESP + local_4],0x1
//         00411cf5     JZ         LAB_00411d29
//         00411cf7     SUB        ESP,0x70
//         00411cfa     LEA        EAX=>newRCost.next,[ESP + 0xe0]
//         00411d01     MOV        this,ESP
//         00411d03     MOV        dword ptr [ESP + local_1c4],ESP
//         00411d0a     PUSH       EAX
//         00411d0b     CALL       ResourceItem::ResourceItem                       undefined ResourceItem(ResourceItem * this, R
//         00411d10     MOV        EDX,dword ptr [ESP + rc[0]]
//         00411d17     LEA        this=>name[4],[ESP + 0xa0]
//         00411d1e     PUSH       this
//         00411d1f     PUSH       EDX
//         00411d20     MOV        this,ESI
//         00411d22     CALL       TechnologyItem::TechnologyItem                   undefined TechnologyItem(TechnologyItem * thi
//         00411d27     JMP        LAB_00411d2b
//                               LAB_00411d29                                                 XREF[1]:     00411cf5(j)
//         00411d29     XOR        EAX,EAX
//                               LAB_00411d2b                                                 XREF[1]:     00411d27(j)
//                              airchmod.cpp:195 (3)
//         00411d2b     MOV        dword ptr [EAX + 0x4],EBX
//                              airchmod.cpp:196 (9)
//         00411d2e     MOV        this,dword ptr [EBP + 0xfc]
//         00411d34     MOV        dword ptr [EAX + 0x8],this
//                              airchmod.cpp:200 (72)
//         00411d37     MOV        dword ptr [ESP + local_4],0xffffffff
//         00411d42     MOV        dword ptr [ECX + this->_padding_],EAX
//         00411d45     MOV        EDX,dword ptr [EBP + 0x148]
//         00411d4b     INC        EDX
//         00411d4c     LEA        this=>newRCost.next,[ESP + 0x70]
//         00411d50     MOV        dword ptr [EBP + 0xfc],EAX
//         00411d56     MOV        dword ptr [EBP + 0x148],EDX
//         00411d5c     CALL       ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
//         00411d61     PUSH       EDI
//         00411d62     LEA        EAX=>temp[4],[ESP + 0xe4]
//         00411d69     PUSH       0x100
//         00411d6e     PUSH       EAX
//         00411d6f     CALL       fgets                                            undefined fgets()
//         00411d74     ADD        ESP,0xc
//         00411d77     TEST       EAX,EAX
//         00411d79     JNZ        LAB_00411c8d
//                              airchmod.cpp:179 (4)
//         00411d7f     MOV        EBX,dword ptr [ESP + id]
//                               LAB_00411d83                                                 XREF[1]:     00411c81(j)
//                              airchmod.cpp:201 (9)
//         00411d83     PUSH       EDI
//         00411d84     CALL       fclose                                           undefined fclose()
//         00411d89     ADD        ESP,0x4
//                              airchmod.cpp:203 (18)
//         00411d8c     PUSH       s_.tmp                                           = ".tmp"
//         00411d91     PUSH       EBX
//         00411d92     CALL       strstr                                           undefined strstr()
//         00411d97     ADD        ESP,0x8
//         00411d9a     TEST       EAX,EAX
//         00411d9c     JZ         LAB_00411ddd
//                              airchmod.cpp:204 (9)
//         00411d9e     PUSH       EBX
//         00411d9f     CALL       __unlink                                         undefined __unlink()
//         00411da4     ADD        ESP,0x4
//                              airchmod.cpp:205 (2)
//         00411da7     JMP        LAB_00411ddd
//                               LAB_00411da9                                                 XREF[1]:     00411c10(j)
//                              airchmod.cpp:168 (4)
//         00411da9     TEST       EBX,EBX
//         00411dab     JNZ        LAB_00411dcf
//                               LAB_00411dad                                                 XREF[1]:     00411c18(j)
//                              airchmod.cpp:169 (34)
//         00411dad     MOV        EDI,s_NULL                                       = 4Eh
//         00411db2     OR         this,0xffffffff
//         00411db5     XOR        EAX,EAX
//         00411db7     SCASB.RE   ES:EDI=>s_NULL                                   = 4Eh
//                                                                                  = 55h
//         00411db9     NOT        this
//         00411dbb     SUB        EDI,this
//         00411dbd     MOV        EDX,this
//         00411dbf     MOV        ESI,EDI
//         00411dc1     XOR        EDI,EDI
//         00411dc3     SHR        this,0x2
//         00411dc6     MOVSD.REP  ES:EDI,ESI
//         00411dc8     MOV        this,EDX
//         00411dca     AND        this,0x3
//         00411dcd     MOVSB.REP  ES:EDI,ESI
//                               LAB_00411dcf                                                 XREF[1]:     00411dab(j)
//                              airchmod.cpp:170 (14)
//         00411dcf     PUSH       s_There_is_no_tech_tree_to_load.                 = "There is no tech tree to load."
//         00411dd4     PUSH       EBP
//         00411dd5     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         00411dda     ADD        ESP,0x8
//                               LAB_00411ddd                                                 XREF[2]:     00411d9c(j), 00411da7(j)
//                              airchmod.cpp:171 (5)
//         00411ddd     MOV        EAX,0x1
//                               LAB_00411de2                                                 XREF[1]:     00411c63(j)
//                              airchmod.cpp:206 (27)
//         00411de2     MOV        this,dword ptr [ESP + local_c]
//         00411de9     POP        EDI
//         00411dea     POP        ESI
//         00411deb     POP        EBP
//         00411dec     MOV        dword ptr FS:[0x0],this
//         00411df3     POP        EBX
//         00411df4     ADD        ESP,0x1dc
//         00411dfa     RET        0x4
//         00411dfd     ??         90h
//         00411dfe     NOP
//         00411dff     NOP
    return 0;
}

int ResearchAIModule::numberTechnologyItems() {
    /* TODO: Stub */
//                              int __thiscall numberTechnologyItems(ResearchAIModule * this)
//              int               EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//                               ?numberTechnologyItems@ResearchAIModule@@QBEHXZ
//                               ResearchAIModule::numberTechnologyItems
//                              airchmod.cpp:211 (6)
//         00411e00     MOV        EAX,dword ptr [ECX + this->techTreeLengthValue]
//                              airchmod.cpp:213 (1)
//         00411e06     RET
//         00411e07     ??         90h
//         00411e08     NOP
//         00411e09     NOP
//         00411e0a     NOP
//         00411e0b     NOP
//         00411e0c     NOP
//         00411e0d     NOP
//         00411e0e     NOP
//         00411e0f     NOP
    return 0;
}

char* ResearchAIModule::technologyTreeName() {
    /* TODO: Stub */
//                              char * __thiscall technologyTreeName(ResearchAIModule * this)
//              char *            EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//                               ?technologyTreeName@ResearchAIModule@@QAEPADXZ
//                               ResearchAIModule::technologyTreeName
//                              airchmod.cpp:218 (6)
//         00411e10     LEA        EAX,[ECX + this->techTreeNameValue[0]]
//                              airchmod.cpp:220 (1)
//         00411e16     RET
//         00411e17     ??         90h
//         00411e18     NOP
//         00411e19     NOP
//         00411e1a     NOP
//         00411e1b     NOP
//         00411e1c     NOP
//         00411e1d     NOP
//         00411e1e     NOP
//         00411e1f     NOP
    return 0;
}

void ResearchAIModule::removeOldTechTree() {
    /* TODO: Stub */
//                              void __thiscall removeOldTechTree(ResearchAIModule * this)
//              void              <VOID>         <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//                               ?removeOldTechTree@ResearchAIModule@@IAEXXZ                  XREF[2]:     ~ResearchAIModule:00411975(c),
//                               ResearchAIModule::removeOldTechTree                                       loadTechnologyTree:00411bab(c)
//                              airchmod.cpp:225 (5)
//         00411e20     PUSH       EBX
//         00411e21     MOV        EBX,this
//         00411e23     PUSH       ESI
//         00411e24     PUSH       EDI
//                              airchmod.cpp:226 (6)
//         00411e25     MOV        this,dword ptr [EBX + 0xf8]
//                              airchmod.cpp:228 (14)
//         00411e2b     LEA        EDI,[EBX + 0xf4]
//         00411e31     CMP        this,EDI
//         00411e33     JZ         LAB_00411e48
//                               LAB_00411e35                                                 XREF[1]:     00411e46(j)
//         00411e35     TEST       this,this
//         00411e37     JZ         LAB_00411e48
//                              airchmod.cpp:230 (11)
//         00411e39     MOV        EAX,dword ptr [this->_padding_]
//         00411e3b     MOV        ESI,dword ptr [ECX + this->_padding_]
//         00411e3e     PUSH       0x1
//         00411e40     CALL       dword ptr [EAX]
//         00411e42     CMP        ESI,EDI
//                              airchmod.cpp:231 (4)
//         00411e44     MOV        this,ESI
//         00411e46     JNZ        LAB_00411e35
//                               LAB_00411e48                                                 XREF[2]:     00411e33(j), 00411e37(j)
//                              airchmod.cpp:233 (6)
//         00411e48     MOV        dword ptr [EBX + 0xf8],EDI
//                              airchmod.cpp:234 (6)
//         00411e4e     MOV        dword ptr [EBX + 0xfc],EDI
//                              airchmod.cpp:236 (14)
//         00411e54     POP        EDI
//         00411e55     MOV        dword ptr [EBX + 0x148],0x0
//         00411e5f     POP        ESI
//         00411e60     POP        EBX
//         00411e61     RET
//         00411e62     ??         90h
//         00411e63     NOP
//         00411e64     NOP
//         00411e65     NOP
//         00411e66     NOP
//         00411e67     NOP
//         00411e68     NOP
//         00411e69     NOP
//         00411e6a     NOP
//         00411e6b     NOP
//         00411e6c     NOP
//         00411e6d     NOP
//         00411e6e     NOP
//         00411e6f     NOP
    return;
}

TechnologyItem* ResearchAIModule::item(int param_1) {
    /* TODO: Stub */
//                              TechnologyItem * __thiscall item(ResearchAIModule * this, int param_1)
//              TechnologyItem    EAX:4          <RETURN>
//              ResearchAIModu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00411e83(R)
//                               ?item@ResearchAIModule@@IAEPAVTechnologyItem@@H@Z            XREF[1]:     resourceCost:00411b45(c)
//                               ResearchAIModule::item
//                              airchmod.cpp:241 (2)
//         00411e70     PUSH       EBX
//         00411e71     PUSH       ESI
//                              airchmod.cpp:244 (7)
//         00411e72     MOV        ESI,dword ptr [ECX + this+0xf8]
//         00411e78     PUSH       EDI
//                              airchmod.cpp:245 (18)
//         00411e79     LEA        EDI,[ECX + this->techTree._padding_]
//         00411e7f     CMP        ESI,EDI
//         00411e81     JZ         LAB_00411ead
//         00411e83     MOV        EBX,dword ptr [ESP + param_1]
//                               LAB_00411e87                                                 XREF[1]:     00411e9b(j)
//         00411e87     TEST       ESI,ESI
//         00411e89     JZ         LAB_00411ead
//                              airchmod.cpp:246 (11)
//         00411e8b     MOV        this,ESI
//         00411e8d     CALL       TechnologyItem::id                               int id(TechnologyItem * this)
//         00411e92     CMP        EAX,EBX
//         00411e94     JZ         LAB_00411ea5
//                              airchmod.cpp:248 (7)
//         00411e96     MOV        ESI,dword ptr [ESI + 0x4]
//         00411e99     CMP        ESI,EDI
//         00411e9b     JNZ        LAB_00411e87
//                              airchmod.cpp:250 (2)
//         00411e9d     XOR        EAX,EAX
//                              airchmod.cpp:251 (6)
//         00411e9f     POP        EDI
//         00411ea0     POP        ESI
//         00411ea1     POP        EBX
//         00411ea2     RET        0x4
//                               LAB_00411ea5                                                 XREF[1]:     00411e94(j)
//                              airchmod.cpp:247 (2)
//         00411ea5     MOV        EAX,ESI
//                              airchmod.cpp:251 (14)
//         00411ea7     POP        EDI
//         00411ea8     POP        ESI
//         00411ea9     POP        EBX
//         00411eaa     RET        0x4
//                               LAB_00411ead                                                 XREF[2]:     00411e81(j), 00411e89(j)
//         00411ead     POP        EDI
//         00411eae     POP        ESI
//         00411eaf     XOR        EAX,EAX
//         00411eb1     POP        EBX
//         00411eb2     RET        0x4
//         00411eb5     ??         90h
//         00411eb6     NOP
//         00411eb7     NOP
//         00411eb8     NOP
//         00411eb9     NOP
//         00411eba     NOP
//         00411ebb     NOP
//         00411ebc     NOP
//         00411ebd     NOP
//         00411ebe     NOP
//         00411ebf     NOP
    return 0;
}

