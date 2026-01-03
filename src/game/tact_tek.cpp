#include "../common.h"
#include "tact_tek.h"

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech *
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d21cc(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004d21c6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d21e6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d220e(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d21d6(W)
//                               ??0TRIBE_Action_Make_Tech@@QAE@HPAVRGE_Action_Object@@@Z     XREF[1]:     create_action:004d0253(c)
//                               TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
//                              tact_tek.cpp:29 (47)
//         004d21b0     PUSH       -0x1
//         004d21b2     PUSH       FUN_00560148
//         004d21b7     MOV        EAX,FS:[0x0]
//         004d21bd     PUSH       EAX
//         004d21be     MOV        dword ptr FS:[0x0],ESP
//         004d21c5     PUSH       this
//         004d21c6     MOV        EAX,dword ptr [ESP + param_2]
//         004d21ca     PUSH       ESI
//         004d21cb     PUSH       EDI
//         004d21cc     MOV        EDI,dword ptr [ESP + param_1]
//         004d21d0     PUSH       0x1
//         004d21d2     MOV        ESI,this
//         004d21d4     PUSH       EAX
//         004d21d5     PUSH       EDI
//         004d21d6     MOV        dword ptr [ESP + local_10],ESI
//         004d21da     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              tact_tek.cpp:32 (35)
//         004d21df     LEA        this,[ESI + 0x40]
//         004d21e2     PUSH       0x2
//         004d21e4     PUSH       this
//         004d21e5     PUSH       EDI
//         004d21e6     MOV        dword ptr [ESP + local_4],0x0
//         004d21ee     MOV        dword ptr [ESI],TRIBE_Action_Make_Tech::`vftab   = 004d2230
//                              language.dll match for 0x67: "Comic Sans MS"
//         004d21f4     MOV        word ptr [ESI + 0x4],0x67
//         004d21fa     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004d21ff     ADD        ESP,0xc
//                              tact_tek.cpp:33 (12)
//         004d2202     LEA        EDX,[ESI + 0x44]
//         004d2205     PUSH       0x4
//         004d2207     PUSH       EDX
//         004d2208     PUSH       EDI
//         004d2209     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tact_tek.cpp:34 (24)
//         004d220e     MOV        this,dword ptr [ESP + local_c]
//         004d2212     ADD        ESP,0xc
//         004d2215     MOV        EAX,ESI
//         004d2217     MOV        dword ptr FS:[0x0],this
//         004d221e     POP        EDI
//         004d221f     POP        ESI
//         004d2220     ADD        ESP,0x10
//         004d2223     RET        0x8
//         004d2226     ??         90h
//         004d2227     NOP
//         004d2228     NOP
//         004d2229     NOP
//         004d222a     NOP
//         004d222b     NOP
//         004d222c     NOP
//         004d222d     NOP
//         004d222e     NOP
//         004d222f     NOP
}

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* param_1, short param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech *
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d2250(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     004d2263(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004d225f(R)
//                               ??0TRIBE_Action_Make_Tech@@QAE@PAVRGE_Action_Object@@FH@Z    XREF[1]:     do_command_research:00509b8f(c)
//                               TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
//                              tact_tek.cpp:41 (19)
//         004d2250     MOV        EAX,dword ptr [ESP + param_1]
//         004d2254     PUSH       ESI
//         004d2255     PUSH       0x1
//         004d2257     MOV        ESI,this
//         004d2259     PUSH       EAX
//         004d225a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//         004d225f     MOV        this,dword ptr [ESP + param_3]
//                              tact_tek.cpp:44 (24)
//         004d2263     MOV        DX,word ptr [ESP + param_2]
//         004d2268     MOV        dword ptr [ESI + 0x44],this
//         004d226b     MOV        dword ptr [ESI],TRIBE_Action_Make_Tech::`vftab   = 004d2230
//         004d2271     MOV        word ptr [ESI + 0x4],0x67
//         004d2277     MOV        word ptr [ESI + 0x40],DX
//                              tact_tek.cpp:45 (6)
//         004d227b     MOV        EAX,ESI
//         004d227d     POP        ESI
//         004d227e     RET        0xc
//         004d2281     ??         90h
//         004d2282     NOP
//         004d2283     NOP
//         004d2284     NOP
//         004d2285     NOP
//         004d2286     NOP
//         004d2287     NOP
//         004d2288     NOP
//         004d2289     NOP
//         004d228a     NOP
//         004d228b     NOP
//         004d228c     NOP
//         004d228d     NOP
//         004d228e     NOP
//         004d228f     NOP
}

TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d22b6(W), 004d234b(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d22a9(W)
//                               ??1TRIBE_Action_Make_Tech@@UAE@XZ                            XREF[1]:     `vector_deleting_destructor':004d2
//                               TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech
//                              tact_tek.cpp:49 (35)
//         004d2290     PUSH       -0x1
//         004d2292     PUSH       FUN_00560168
//         004d2297     MOV        EAX,FS:[0x0]
//         004d229d     PUSH       EAX
//         004d229e     MOV        dword ptr FS:[0x0],ESP
//         004d22a5     PUSH       this
//         004d22a6     PUSH       ESI
//         004d22a7     MOV        ESI,this
//         004d22a9     MOV        dword ptr [ESP + local_10],ESI
//         004d22ad     MOV        dword ptr [ESI],TRIBE_Action_Make_Tech::`vftab   = 004d2230
//                              tact_tek.cpp:52 (19)
//         004d22b3     MOV        AL,byte ptr [ESI + 0xc]
//         004d22b6     MOV        dword ptr [ESP + local_4],0x0
//         004d22be     CMP        AL,0x1
//         004d22c0     JZ         LAB_004d2349
//                              tact_tek.cpp:54 (24)
//         004d22c6     MOV        this,dword ptr [ESI + 0x8]
//         004d22c9     MOV        AX,word ptr [ESI + 0x40]
//         004d22cd     PUSH       0x0
//         004d22cf     PUSH       EAX
//         004d22d0     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d22d3     MOV        this,dword ptr [EDX + 0x220]
//         004d22d9     CALL       TRIBE_Player_Tech::cancel_research               uchar cancel_research(TRIBE_Player_Tech * thi
//                              tact_tek.cpp:55 (19)
//         004d22de     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d22e4     MOV        EAX,dword ptr [this->_padding_ + 0x3f4]
//         004d22ea     MOV        DL,byte ptr [EAX + 0x1d]
//         004d22ed     TEST       DL,DL
//         004d22ef     JNZ        LAB_004d2349
//                              tact_tek.cpp:57 (28)
//         004d22f1     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d22f5     PUSH       EDI
//         004d22f6     PUSH       0x0
//         004d22f8     PUSH       0x0
//         004d22fa     PUSH       EAX
//         004d22fb     MOV        EAX,dword ptr [ESI + 0x8]
//         004d22fe     MOV        EDX,dword ptr [this->_padding_]
//         004d2300     MOV        EAX,dword ptr [EAX + 0xc]
//         004d2303     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004d2307     PUSH       EAX
//                              language.dll match for 0x65: "1"
//         004d2308     PUSH       0x65
//         004d230a     CALL       dword ptr [EDX + 0x40]
//                              tact_tek.cpp:59 (29)
//         004d230d     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2310     MOV        EDI,dword ptr [ESI + 0x44]
//         004d2313     PUSH       EDI
//         004d2314     PUSH       offset DAT_fffffff8
//         004d2316     MOV        this,dword ptr [EAX + 0xc]
//         004d2319     MOV        EAX,dword ptr [EAX + 0x4]
//         004d231c     PUSH       EAX=>DAT_fffffff4
//         004d231d     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d2321     MOV        EDX,dword ptr [this->_padding_]
//         004d2323     PUSH       EAX=>DAT_fffffff0
//         004d2324     CALL       dword ptr [EDX + 0x118]
//                              tact_tek.cpp:60 (33)
//         004d232a     MOV        this,dword ptr [ESI + 0x8]
//         004d232d     PUSH       0x0
//         004d232f     PUSH       0x0=>DAT_fffffff8
//         004d2331     PUSH       offset DAT_fffffff4
//         004d2336     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2339     MOV        EDX,dword ptr [this->_padding_]
//         004d233b     PUSH       offset DAT_fffffff0
//         004d2340     PUSH       EAX
//         004d2341     PUSH       EAX
//         004d2342     CALL       dword ptr [EDX + 0x148]
//         004d2348     POP        EDI
//                               LAB_004d2349                                                 XREF[2]:     004d22c0(j), 004d22ef(j)
//         004d2349     MOV        this,ESI
//                              tact_tek.cpp:64 (29)
//         004d234b     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d2353     CALL       RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
//         004d2358     MOV        this,dword ptr [ESP + 0x8]
//         004d235c     POP        ESI
//         004d235d     MOV        dword ptr FS:[0x0],this
//         004d2364     ADD        ESP,0x10
//         004d2367     RET
//         004d2368     ??         90h
//         004d2369     NOP
//         004d236a     NOP
//         004d236b     NOP
//         004d236c     NOP
//         004d236d     NOP
//         004d236e     NOP
//         004d236f     NOP
}

void TRIBE_Action_Make_Tech::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Action_Make_Tech * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d2372(R)
//                               ?save@TRIBE_Action_Make_Tech@@UAEXH@Z                        XREF[1]:     00575294(*)
//                               TRIBE_Action_Make_Tech::save
//                              tact_tek.cpp:68 (2)
//         004d2370     PUSH       ESI
//         004d2371     PUSH       EDI
//                              tact_tek.cpp:69 (12)
//         004d2372     MOV        EDI,dword ptr [ESP + param_1]
//         004d2376     MOV        ESI,this
//         004d2378     PUSH       EDI
//         004d2379     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              tact_tek.cpp:71 (15)
//         004d237e     LEA        EAX,[ESI + 0x40]
//         004d2381     PUSH       0x2
//         004d2383     PUSH       EAX
//         004d2384     PUSH       EDI
//         004d2385     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d238a     ADD        ESP,0xc
//                              tact_tek.cpp:72 (15)
//         004d238d     ADD        ESI,0x44
//         004d2390     PUSH       0x4
//         004d2392     PUSH       ESI
//         004d2393     PUSH       EDI
//         004d2394     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d2399     ADD        ESP,0xc
//                              tact_tek.cpp:73 (5)
//         004d239c     POP        EDI
//         004d239d     POP        ESI
//         004d239e     RET        0x4
//         004d23a1     ??         90h
//         004d23a2     NOP
//         004d23a3     NOP
//         004d23a4     NOP
//         004d23a5     NOP
//         004d23a6     NOP
//         004d23a7     NOP
//         004d23a8     NOP
//         004d23a9     NOP
//         004d23aa     NOP
//         004d23ab     NOP
//         004d23ac     NOP
//         004d23ad     NOP
//         004d23ae     NOP
//         004d23af     NOP
    return;
}

void TRIBE_Action_Make_Tech::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Make_Tech * this, uchar
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004d23b0(R), 004d23c8(*), 004d2405(R)
//                               ?first_in_stack@TRIBE_Action_Make_Tech@@UAEXE@Z              XREF[1]:     0057529c(*)
//                               TRIBE_Action_Make_Tech::first_in_stack
//                              tact_tek.cpp:76 (12)
//         004d23b0     MOV        AL,byte ptr [ESP + param_1]
//         004d23b4     PUSH       ESI
//         004d23b5     TEST       AL,AL
//         004d23b7     PUSH       EDI
//         004d23b8     MOV        ESI,this
//         004d23ba     JZ         LAB_004d2438
//                              tact_tek.cpp:80 (9)
//         004d23bc     MOV        AX,word ptr [ESI + 0x40]
//         004d23c0     TEST       AX,AX
//         004d23c3     JL         LAB_004d2438
//                              tact_tek.cpp:84 (29)
//         004d23c5     MOV        EDX,dword ptr [ESI + 0x8]
//         004d23c8     LEA        this=>param_1,[ESP + 0xc]
//         004d23cc     PUSH       this
//         004d23cd     PUSH       0x1
//         004d23cf     PUSH       EAX
//         004d23d0     MOV        EAX,dword ptr [EDX + 0xc]
//         004d23d3     MOV        this,dword ptr [EAX + 0x220]
//         004d23d9     CALL       TRIBE_Player_Tech::start_research                uchar start_research(TRIBE_Player_Tech * this
//         004d23de     CMP        AL,0x1
//         004d23e0     JNZ        LAB_004d23f0
//                              tact_tek.cpp:85 (9)
//         004d23e2     MOV        EDX,dword ptr [ESI]
//         004d23e4     PUSH       0x6
//         004d23e6     MOV        this,ESI
//         004d23e8     CALL       dword ptr [EDX + 0x5c]
//                              tact_tek.cpp:98 (5)
//         004d23eb     POP        EDI
//         004d23ec     POP        ESI
//         004d23ed     RET        0x4
//                               LAB_004d23f0                                                 XREF[1]:     004d23e0(j)
//                              tact_tek.cpp:93 (33)
//         004d23f0     MOV        EAX,dword ptr [ESI + 0x8]
//         004d23f3     MOV        EDI,dword ptr [ESI + 0x44]
//         004d23f6     PUSH       EDI
//         004d23f7     MOV        this,dword ptr [EAX + 0xc]
//         004d23fa     MOV        EAX,dword ptr [EAX + 0x4]
//         004d23fd     PUSH       EAX
//         004d23fe     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d2402     MOV        EDX,dword ptr [this->_padding_]
//         004d2404     PUSH       EAX
//         004d2405     MOVSX      EAX,word ptr [ESP + param_1]
//         004d240a     PUSH       EAX
//         004d240b     CALL       dword ptr [EDX + 0x118]
//                              tact_tek.cpp:94 (30)
//         004d2411     MOV        this,dword ptr [ESI + 0x8]
//         004d2414     PUSH       0x0
//         004d2416     PUSH       0x0=>DAT_fffffff8
//         004d2418     PUSH       offset DAT_fffffff4
//         004d241d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2420     MOV        EDX,dword ptr [this->_padding_]
//         004d2422     PUSH       offset DAT_fffffff0
//         004d2427     PUSH       EAX
//         004d2428     PUSH       EAX
//         004d2429     CALL       dword ptr [EDX + 0x148]
//                              tact_tek.cpp:95 (9)
//         004d242f     MOV        EAX,dword ptr [ESI]
//         004d2431     PUSH       0x1
//         004d2433     MOV        this,ESI
//         004d2435     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004d2438                                                 XREF[2]:     004d23ba(j), 004d23c3(j)
//                              tact_tek.cpp:98 (5)
//         004d2438     POP        EDI
//         004d2439     POP        ESI
//         004d243a     RET        0x4
//         004d243d     ??         90h
//         004d243e     NOP
//         004d243f     NOP
    return;
}

void TRIBE_Action_Make_Tech::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Make_Tech * this, uchar param
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d2440(R)
//                               ?set_state@TRIBE_Action_Make_Tech@@MAEXE@Z                   XREF[1]:     005752dc(*)
//                               TRIBE_Action_Make_Tech::set_state
//                              tact_tek.cpp:102 (7)
//         004d2440     MOV        AL,byte ptr [ESP + param_1]
//         004d2444     MOV        byte ptr [ECX + this->_padding_],AL
//                              tact_tek.cpp:106 (3)
//         004d2447     RET        0x4
//         004d244a     ??         90h
//         004d244b     NOP
//         004d244c     NOP
//         004d244d     NOP
//         004d244e     NOP
//         004d244f     NOP
    return;
}

uchar TRIBE_Action_Make_Tech::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Make_Tech * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004d247b(W), 004d249d(W), 004d24a1(R)
//              float             Stack[-0x8]:4  work
//                               ?update@TRIBE_Action_Make_Tech@@UAEEXZ                       XREF[1]:     005752a8(*)
//                               TRIBE_Action_Make_Tech::update
//                              tact_tek.cpp:109 (6)
//         004d2450     PUSH       this
//         004d2451     PUSH       EBX
//         004d2452     PUSH       EBP
//         004d2453     PUSH       ESI
//         004d2454     MOV        ESI,this
//                              tact_tek.cpp:112 (22)
//         004d2456     XOR        EAX,EAX
//         004d2458     PUSH       EDI
//         004d2459     MOV        AL,byte ptr [ESI + 0xc]
//         004d245c     DEC        EAX
//         004d245d     JZ         LAB_004d2543
//         004d2463     SUB        EAX,0x5
//         004d2466     JNZ        LAB_004d253b
//                              tact_tek.cpp:114 (15)
//         004d246c     MOV        EAX,[rge_base_game]                              = 00000000
//         004d2471     MOV        this,dword ptr [EAX + 0x9a8]
//         004d2477     TEST       this,this
//         004d2479     JZ         LAB_004d2485
//                              tact_tek.cpp:115 (8)
//         004d247b     MOV        dword ptr [ESP + local_4],0x447a0000
//                              tact_tek.cpp:116 (2)
//         004d2483     JMP        LAB_004d24a1
//                               LAB_004d2485                                                 XREF[1]:     004d2479(j)
//                              tact_tek.cpp:117 (28)
//         004d2485     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2488     MOV        this,dword ptr [EAX + 0xc]
//         004d248b     MOV        EAX,dword ptr [EAX + 0x8]
//         004d248e     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d2491     FLD        float ptr [EDX + 0x84]
//         004d2497     FMUL       float ptr [EAX + 0xe4]
//         004d249d     FSTP       float ptr [ESP + local_4]
//                               LAB_004d24a1                                                 XREF[1]:     004d2483(j)
//                              tact_tek.cpp:118 (31)
//         004d24a1     MOV        this,dword ptr [ESP + local_4]
//         004d24a5     MOV        EAX,dword ptr [ESI + 0x8]
//         004d24a8     MOV        DX,word ptr [ESI + 0x40]
//         004d24ac     PUSH       this
//         004d24ad     MOV        this,dword ptr [EAX + 0xc]
//         004d24b0     PUSH       EDX
//         004d24b1     MOV        this,dword ptr [this->_padding_ + 0x220]
//         004d24b7     CALL       TRIBE_Player_Tech::research                      uchar research(TRIBE_Player_Tech * this, shor
//         004d24bc     TEST       AL,AL
//         004d24be     JNZ        LAB_004d253b
//                              tact_tek.cpp:119 (9)
//         004d24c0     MOV        EDX,dword ptr [ESI]
//         004d24c2     PUSH       0x1
//         004d24c4     MOV        this,ESI
//         004d24c6     CALL       dword ptr [EDX + 0x5c]
//                              tact_tek.cpp:120 (49)
//         004d24c9     MOV        EDI,dword ptr [ESI + 0x8]
//         004d24cc     MOV        EBX,dword ptr [rge_base_game]                    = 00000000
//         004d24d2     FLD        float ptr [EDI + 0x3c]
//         004d24d5     MOV        EBP,dword ptr [EBX]
//         004d24d7     CALL       __ftol                                           undefined __ftol()
//         004d24dc     FLD        float ptr [EDI + 0x38]
//         004d24df     PUSH       EAX
//         004d24e0     CALL       __ftol                                           undefined __ftol()
//         004d24e5     MOV        this,dword ptr [EDI + 0xc]
//         004d24e8     PUSH       EAX=>DAT_fffffff8
//         004d24e9     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d24ed     MOVSX      EDX,word ptr [this->_padding_ + 0x4a]
//         004d24f1     PUSH       EAX=>DAT_fffffff4
//         004d24f2     PUSH       EDX=>DAT_fffffff0
//         004d24f3     PUSH       0x64
//         004d24f5     MOV        this,EBX
//         004d24f7     CALL       dword ptr [EBP + 0x40]
//                              tact_tek.cpp:123 (27)
//         004d24fa     MOV        EAX,dword ptr [ESI + 0x8]
//         004d24fd     MOV        EDI,dword ptr [ESI + 0x44]
//         004d2500     PUSH       EDI
//         004d2501     MOV        this,dword ptr [EAX + 0xc]
//         004d2504     MOV        EAX,dword ptr [EAX + 0x4]
//         004d2507     PUSH       EAX=>DAT_fffffff8
//         004d2508     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d250c     MOV        EDX,dword ptr [this->_padding_]
//         004d250e     PUSH       EAX=>DAT_fffffff4
//         004d250f     CALL       dword ptr [EDX + 0x11c]
//                              tact_tek.cpp:124 (30)
//         004d2515     MOV        this,dword ptr [ESI + 0x8]
//         004d2518     PUSH       0x0
//         004d251a     PUSH       0x0=>DAT_fffffff8
//         004d251c     PUSH       offset DAT_fffffff4
//         004d2521     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2524     MOV        EDX,dword ptr [this->_padding_]
//         004d2526     PUSH       offset DAT_fffffff0
//         004d252b     PUSH       EAX
//         004d252c     PUSH       EAX
//         004d252d     CALL       dword ptr [EDX + 0x148]
//                              tact_tek.cpp:130 (2)
//         004d2533     MOV        AL,0x1
//                              tact_tek.cpp:134 (6)
//         004d2535     POP        EDI
//         004d2536     POP        ESI
//         004d2537     POP        EBP
//         004d2538     POP        EBX
//         004d2539     POP        this
//         004d253a     RET
//                               LAB_004d253b                                                 XREF[2]:     004d2466(j), 004d24be(j)
//                              tact_tek.cpp:133 (2)
//         004d253b     XOR        AL,AL
//                              tact_tek.cpp:134 (14)
//         004d253d     POP        EDI
//         004d253e     POP        ESI
//         004d253f     POP        EBP
//         004d2540     POP        EBX
//         004d2541     POP        this
//         004d2542     RET
//                               LAB_004d2543                                                 XREF[1]:     004d245d(j)
//         004d2543     POP        EDI
//         004d2544     POP        ESI
//         004d2545     POP        EBP
//         004d2546     MOV        AL,0x1
//         004d2548     POP        EBX
//         004d2549     POP        this
//         004d254a     RET
//         004d254b     ??         90h
//         004d254c     NOP
//         004d254d     NOP
//         004d254e     NOP
//         004d254f     NOP
    return 0;
}

int TRIBE_Action_Make_Tech::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Make_Tech * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Make_Tech@@UAEHXZ                         XREF[1]:     005752ac(*)
//                               TRIBE_Action_Make_Tech::stop
//                              tact_tek.cpp:138 (4)
//         004d2550     PUSH       ESI
//         004d2551     MOV        ESI,this
//         004d2553     PUSH       EDI
//                              tact_tek.cpp:140 (7)
//         004d2554     PUSH       0x1
//         004d2556     MOV        EAX,dword ptr [ESI]
//         004d2558     CALL       dword ptr [EAX + 0x5c]
//                              tact_tek.cpp:141 (24)
//         004d255b     MOV        EDX,dword ptr [ESI + 0x8]
//         004d255e     MOV        this,word ptr [ESI + 0x40]
//         004d2562     PUSH       0x1
//         004d2564     PUSH       this=>DAT_fffffff8
//         004d2565     MOV        EAX,dword ptr [EDX + 0xc]
//         004d2568     MOV        this,dword ptr [EAX + 0x220]
//         004d256e     CALL       TRIBE_Player_Tech::cancel_research               uchar cancel_research(TRIBE_Player_Tech * thi
//                              tact_tek.cpp:142 (33)
//         004d2573     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d2577     PUSH       0x0
//         004d2579     PUSH       0x0=>DAT_fffffff8
//         004d257b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d2581     PUSH       EAX=>DAT_fffffff4
//         004d2582     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2585     MOV        EDX,dword ptr [this->_padding_]
//         004d2587     MOV        EAX,dword ptr [EAX + 0xc]
//         004d258a     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004d258e     PUSH       EAX=>DAT_fffffff0
//                              language.dll match for 0x65: "1"
//         004d258f     PUSH       0x65
//         004d2591     CALL       dword ptr [EDX + 0x40]
//                              tact_tek.cpp:144 (29)
//         004d2594     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2597     MOV        EDI,dword ptr [ESI + 0x44]
//         004d259a     PUSH       EDI
//         004d259b     PUSH       offset DAT_fffffff8
//         004d259d     MOV        this,dword ptr [EAX + 0xc]
//         004d25a0     MOV        EAX,dword ptr [EAX + 0x4]
//         004d25a3     PUSH       EAX=>DAT_fffffff4
//         004d25a4     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d25a8     MOV        EDX,dword ptr [this->_padding_]
//         004d25aa     PUSH       EAX=>DAT_fffffff0
//         004d25ab     CALL       dword ptr [EDX + 0x118]
//                              tact_tek.cpp:145 (30)
//         004d25b1     MOV        this,dword ptr [ESI + 0x8]
//         004d25b4     PUSH       0x0
//         004d25b6     PUSH       0x0=>DAT_fffffff8
//         004d25b8     PUSH       offset DAT_fffffff4
//         004d25bd     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d25c0     MOV        EDX,dword ptr [this->_padding_]
//         004d25c2     PUSH       offset DAT_fffffff0
//         004d25c7     PUSH       EAX
//         004d25c8     PUSH       EAX
//         004d25c9     CALL       dword ptr [EDX + 0x148]
//                              tact_tek.cpp:147 (8)
//         004d25cf     POP        EDI
//         004d25d0     MOV        EAX,0x1
//         004d25d5     POP        ESI
//         004d25d6     RET
//         004d25d7     ??         90h
//         004d25d8     NOP
//         004d25d9     NOP
//         004d25da     NOP
//         004d25db     NOP
//         004d25dc     NOP
//         004d25dd     NOP
//         004d25de     NOP
//         004d25df     NOP
    return 0;
}

void TRIBE_Action_Make_Tech::get_info(short* param_1, short* param_2, char* param_3, short param_4) {
    /* TODO: Stub */
//                              void __thiscall get_info(TRIBE_Action_Make_Tech * this, short * para
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     004d25e5(R)
//              short *           Stack[0x8]:4   param_2                   XREF[2]:     004d25f7(R), 004d2618(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     004d261f(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     004d262e(R)
//                               ?get_info@TRIBE_Action_Make_Tech@@QAEXAAF0PADF@Z             XREF[1]:     work_status:004c9688(c)
//                               TRIBE_Action_Make_Tech::get_info
//                              tact_tek.cpp:151 (5)
//         004d25e0     PUSH       EBX
//         004d25e1     PUSH       ESI
//         004d25e2     PUSH       EDI
//         004d25e3     MOV        EDI,this
//                              tact_tek.cpp:152 (11)
//         004d25e5     MOV        this,dword ptr [ESP + param_1]
//         004d25e9     MOV        AX,word ptr [EDI + 0x40]
//         004d25ed     MOV        word ptr [this->_padding_],AX
//                              tact_tek.cpp:154 (7)
//         004d25f0     MOV        AL,byte ptr [EDI + 0xc]
//         004d25f3     CMP        AL,0x1
//         004d25f5     JNZ        LAB_004d2602
//                              tact_tek.cpp:155 (9)
//         004d25f7     MOV        EDX,dword ptr [ESP + param_2]
//         004d25fb     MOV        word ptr [EDX],0x64
//                              tact_tek.cpp:156 (2)
//         004d2600     JMP        LAB_004d261f
//                               LAB_004d2602                                                 XREF[1]:     004d25f5(j)
//                              tact_tek.cpp:157 (29)
//         004d2602     MOV        this,dword ptr [EDI + 0x8]
//         004d2605     MOV        AX,word ptr [EDI + 0x40]
//         004d2609     PUSH       EAX
//         004d260a     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d260d     MOV        this,dword ptr [EDX + 0x220]
//         004d2613     CALL       TRIBE_Player_Tech::get_progress                  short get_progress(TRIBE_Player_Tech * this,
//         004d2618     MOV        this,dword ptr [ESP + param_2]
//         004d261c     MOV        word ptr [this->_padding_],AX
//                               LAB_004d261f                                                 XREF[1]:     004d2600(j)
//                              tact_tek.cpp:159 (8)
//         004d261f     MOV        EBX,dword ptr [ESP + param_3]
//         004d2623     TEST       EBX,EBX
//         004d2625     JZ         LAB_004d2652
//                              tact_tek.cpp:161 (38)
//         004d2627     MOV        EAX,dword ptr [EDI + 0x8]
//         004d262a     MOV        DX,word ptr [EDI + 0x40]
//         004d262e     MOVSX      ESI,word ptr [ESP + param_4]
//         004d2633     MOV        this,dword ptr [EAX + 0xc]
//         004d2636     PUSH       ESI
//         004d2637     PUSH       EDX
//         004d2638     MOV        this,dword ptr [this->_padding_ + 0x220]
//         004d263e     CALL       TRIBE_Player_Tech::get_name                      char * get_name(TRIBE_Player_Tech * this, sho
//         004d2643     PUSH       EAX
//         004d2644     PUSH       EBX
//         004d2645     CALL       strncpy                                          undefined strncpy()
//         004d264a     ADD        ESP,0xc
//                              tact_tek.cpp:162 (5)
//         004d264d     MOV        byte ptr [EBX + ESI*0x1 + -0x1],0x0
//                               LAB_004d2652                                                 XREF[1]:     004d2625(j)
//                              tact_tek.cpp:164 (6)
//         004d2652     POP        EDI
//         004d2653     POP        ESI
//         004d2654     POP        EBX
//         004d2655     RET        0x10
//         004d2658     ??         90h
//         004d2659     NOP
//         004d265a     NOP
//         004d265b     NOP
//         004d265c     NOP
//         004d265d     NOP
//         004d265e     NOP
//         004d265f     NOP
    return;
}

