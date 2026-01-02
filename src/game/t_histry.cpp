#include "../common.h"
#include "t_histry.h"

TRIBE_History_Info::TRIBE_History_Info(int param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_History_Info(TRIBE_History_Info * this, i
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004cc733(R)
//                               ??0TRIBE_History_Info@@QAE@H@Z                               XREF[3]:     TRIBE_Player:00511ce2(c),
//                               TRIBE_History_Info::TRIBE_History_Info                                    TRIBE_Player:00511d0a(c),
//                                                                                                         TRIBE_Player:00512075(c)
//                              t_histry.cpp:27 (3)
//         004cc730     PUSH       ESI
//         004cc731     MOV        ESI,this
//                              t_histry.cpp:33 (24)
//         004cc733     MOV        this,dword ptr [ESP + param_1]
//         004cc737     XOR        EAX,EAX
//         004cc739     CMP        this,EAX
//         004cc73b     MOV        dword ptr [ESI],EAX
//         004cc73d     MOV        dword ptr [ESI + 0x4],EAX
//         004cc740     MOV        dword ptr [ESI + 0xc],EAX
//         004cc743     MOV        dword ptr [ESI + 0x8],EAX
//         004cc746     MOV        dword ptr [ESI + 0x10],EAX
//         004cc749     JL         LAB_004cc753
//                              t_histry.cpp:34 (8)
//         004cc74b     PUSH       this
//         004cc74c     MOV        this,ESI
//         004cc74e     CALL       TRIBE_History_Info::load                         void load(TRIBE_History_Info * this, int para
//                               LAB_004cc753                                                 XREF[1]:     004cc749(j)
//                              t_histry.cpp:35 (6)
//         004cc753     MOV        EAX,ESI
//         004cc755     POP        ESI
//         004cc756     RET        0x4
//         004cc759     ??         90h
//         004cc75a     NOP
//         004cc75b     NOP
//         004cc75c     NOP
//         004cc75d     NOP
//         004cc75e     NOP
//         004cc75f     NOP
}

TRIBE_History_Info::~TRIBE_History_Info() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_History_Info(TRIBE_History_Info * this)
//              void              <VOID>         <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//                               ??1TRIBE_History_Info@@QAE@XZ                                XREF[1]:     ~TRIBE_Player:0051215d(c)
//                               TRIBE_History_Info::~TRIBE_History_Info
//                              t_histry.cpp:41 (3)
//         004cc760     PUSH       ESI
//         004cc761     MOV        ESI,this
//                              t_histry.cpp:44 (6)
//         004cc763     MOV        EAX,dword ptr [ESI]
//         004cc765     TEST       EAX,EAX
//         004cc767     JZ         LAB_004cc772
//                              t_histry.cpp:45 (9)
//         004cc769     PUSH       EAX
//         004cc76a     CALL       free                                             undefined free()
//         004cc76f     ADD        ESP,0x4
//                               LAB_004cc772                                                 XREF[1]:     004cc767(j)
//                              t_histry.cpp:47 (7)
//         004cc772     MOV        EAX,dword ptr [ESI + 0x4]
//         004cc775     TEST       EAX,EAX
//         004cc777     JZ         LAB_004cc78f
//                               LAB_004cc779                                                 XREF[1]:     004cc78d(j)
//                              t_histry.cpp:49 (3)
//         004cc779     MOV        this,dword ptr [EAX + 0xc]
//                              t_histry.cpp:50 (19)
//         004cc77c     PUSH       EAX
//         004cc77d     MOV        dword ptr [ESI + 0x4],this
//         004cc780     CALL       free                                             undefined free()
//         004cc785     MOV        EAX,dword ptr [ESI + 0x4]
//         004cc788     ADD        ESP,0x4
//         004cc78b     TEST       EAX,EAX
//         004cc78d     JNZ        LAB_004cc779
//                               LAB_004cc78f                                                 XREF[1]:     004cc777(j)
//                              t_histry.cpp:52 (2)
//         004cc78f     POP        ESI
//         004cc790     RET
//         004cc791     ??         90h
//         004cc792     NOP
//         004cc793     NOP
//         004cc794     NOP
//         004cc795     NOP
//         004cc796     NOP
//         004cc797     NOP
//         004cc798     NOP
//         004cc799     NOP
//         004cc79a     NOP
//         004cc79b     NOP
//         004cc79c     NOP
//         004cc79d     NOP
//         004cc79e     NOP
//         004cc79f     NOP
}

void TRIBE_History_Info::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_History_Info * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     004cc7a5(R), 004cc7ea(W), 004cc7f4(R), 004cc7f9(W),
//                                                                                     004cc804(*)
//                               ?save@TRIBE_History_Info@@QAEXH@Z                            XREF[1]:     save:005122f8(c)
//                               TRIBE_History_Info::save
//                              t_histry.cpp:59 (5)
//         004cc7a0     PUSH       EBX
//         004cc7a1     PUSH       ESI
//         004cc7a2     MOV        ESI,this
//         004cc7a4     PUSH       EDI
//                              t_histry.cpp:63 (19)
//         004cc7a5     MOV        EDI,dword ptr [ESP + param_1]
//         004cc7a9     PUSH       0x4
//         004cc7ab     LEA        EAX,[ESI + 0xc]
//         004cc7ae     PUSH       EAX
//         004cc7af     PUSH       EDI
//         004cc7b0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004cc7b5     ADD        ESP,0xc
//                              t_histry.cpp:64 (15)
//         004cc7b8     LEA        this,[ESI + 0x8]
//         004cc7bb     PUSH       0x4
//         004cc7bd     PUSH       this
//         004cc7be     PUSH       EDI
//         004cc7bf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004cc7c4     ADD        ESP,0xc
//                              t_histry.cpp:65 (12)
//         004cc7c7     LEA        EBX,[ESI + 0x10]
//         004cc7ca     PUSH       0x4
//         004cc7cc     PUSH       EBX
//         004cc7cd     PUSH       EDI
//         004cc7ce     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              t_histry.cpp:67 (15)
//         004cc7d3     MOV        EDX,dword ptr [EBX]
//         004cc7d5     MOV        EAX,dword ptr [ESI]
//         004cc7d7     ADD        ESP,0xc
//         004cc7da     PUSH       EDX
//         004cc7db     PUSH       EAX
//         004cc7dc     PUSH       EDI
//         004cc7dd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              t_histry.cpp:69 (18)
//         004cc7e2     MOV        EAX,dword ptr [ESI + 0x4]
//         004cc7e5     ADD        ESP,0xc
//         004cc7e8     TEST       EAX,EAX
//         004cc7ea     MOV        dword ptr [ESP + param_1],0x0
//         004cc7f2     JZ         LAB_004cc804
//                               LAB_004cc7f4                                                 XREF[1]:     004cc802(j)
//                              t_histry.cpp:70 (16)
//         004cc7f4     MOV        EDX,dword ptr [ESP + param_1]
//         004cc7f8     INC        EDX
//         004cc7f9     MOV        dword ptr [ESP + param_1],EDX
//         004cc7fd     MOV        EAX,dword ptr [EAX + 0xc]
//         004cc800     TEST       EAX,EAX
//         004cc802     JNZ        LAB_004cc7f4
//                               LAB_004cc804                                                 XREF[1]:     004cc7f2(j)
//                              t_histry.cpp:72 (13)
//         004cc804     LEA        this=>param_1,[ESP + 0x10]
//         004cc808     PUSH       0x4
//         004cc80a     PUSH       this
//         004cc80b     PUSH       EDI
//         004cc80c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              t_histry.cpp:73 (10)
//         004cc811     MOV        ESI,dword ptr [ESI + 0x4]
//         004cc814     ADD        ESP,0xc
//         004cc817     TEST       ESI,ESI
//         004cc819     JZ         LAB_004cc82e
//                               LAB_004cc81b                                                 XREF[1]:     004cc82c(j)
//                              t_histry.cpp:74 (19)
//         004cc81b     PUSH       0x10
//         004cc81d     PUSH       ESI
//         004cc81e     PUSH       EDI
//         004cc81f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004cc824     MOV        ESI,dword ptr [ESI + 0xc]
//         004cc827     ADD        ESP,0xc
//         004cc82a     TEST       ESI,ESI
//         004cc82c     JNZ        LAB_004cc81b
//                               LAB_004cc82e                                                 XREF[1]:     004cc819(j)
//                              t_histry.cpp:75 (6)
//         004cc82e     POP        EDI
//         004cc82f     POP        ESI
//         004cc830     POP        EBX
//         004cc831     RET        0x4
//         004cc834     ??         90h
//         004cc835     NOP
//         004cc836     NOP
//         004cc837     NOP
//         004cc838     NOP
//         004cc839     NOP
//         004cc83a     NOP
//         004cc83b     NOP
//         004cc83c     NOP
//         004cc83d     NOP
//         004cc83e     NOP
//         004cc83f     NOP
    return;
}

void TRIBE_History_Info::load(int param_1) {
    /* TODO: Stub */
//                              void __thiscall load(TRIBE_History_Info * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     004cc845(R), 004cc892(*), 004cc8a2(R), 004cc8c6(R),
//                                                                                     004cc8d3(W)
//                               ?load@TRIBE_History_Info@@QAEXH@Z                            XREF[1]:     TRIBE_History_Info:004cc74e(c)
//                               TRIBE_History_Info::load
//                              t_histry.cpp:82 (5)
//         004cc840     PUSH       EBX
//         004cc841     PUSH       ESI
//         004cc842     MOV        ESI,this
//         004cc844     PUSH       EDI
//                              t_histry.cpp:87 (19)
//         004cc845     MOV        EDI,dword ptr [ESP + param_1]
//         004cc849     PUSH       0x4
//         004cc84b     LEA        EAX,[ESI + 0xc]
//         004cc84e     PUSH       EAX
//         004cc84f     PUSH       EDI
//         004cc850     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004cc855     ADD        ESP,0xc
//                              t_histry.cpp:88 (15)
//         004cc858     LEA        this,[ESI + 0x8]
//         004cc85b     PUSH       0x4
//         004cc85d     PUSH       this
//         004cc85e     PUSH       EDI
//         004cc85f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004cc864     ADD        ESP,0xc
//                              t_histry.cpp:89 (12)
//         004cc867     LEA        EBX,[ESI + 0x10]
//         004cc86a     PUSH       0x4
//         004cc86c     PUSH       EBX
//         004cc86d     PUSH       EDI
//         004cc86e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              t_histry.cpp:91 (13)
//         004cc873     MOV        EDX,dword ptr [EBX]
//         004cc875     ADD        ESP,0xc
//         004cc878     PUSH       0x1
//         004cc87a     PUSH       EDX
//         004cc87b     CALL       calloc                                           undefined calloc()
//                              t_histry.cpp:92 (18)
//         004cc880     MOV        this,dword ptr [EBX]
//         004cc882     ADD        ESP,0x8
//         004cc885     MOV        dword ptr [ESI],EAX
//         004cc887     PUSH       this
//         004cc888     PUSH       EAX
//         004cc889     PUSH       EDI
//         004cc88a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004cc88f     ADD        ESP,0xc
//                              t_histry.cpp:95 (16)
//         004cc892     LEA        EDX=>param_1,[ESP + 0x10]
//         004cc896     LEA        EBX,[ESI + 0x4]
//         004cc899     PUSH       0x4
//         004cc89b     PUSH       EDX
//         004cc89c     PUSH       EDI
//         004cc89d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              t_histry.cpp:96 (11)
//         004cc8a2     MOV        EAX,dword ptr [ESP + param_1]
//         004cc8a6     ADD        ESP,0xc
//         004cc8a9     TEST       EAX,EAX
//         004cc8ab     JLE        LAB_004cc8d9
//                               LAB_004cc8ad                                                 XREF[1]:     004cc8d7(j)
//                              t_histry.cpp:98 (14)
//         004cc8ad     PUSH       0x10
//         004cc8af     PUSH       0x1
//         004cc8b1     CALL       calloc                                           undefined calloc()
//         004cc8b6     ADD        ESP,0x8
//         004cc8b9     MOV        ESI,EAX
//                              t_histry.cpp:99 (9)
//         004cc8bb     PUSH       0x10
//         004cc8bd     PUSH       ESI
//         004cc8be     PUSH       EDI
//         004cc8bf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              t_histry.cpp:100 (12)
//         004cc8c4     MOV        dword ptr [EBX],ESI
//         004cc8c6     MOV        EAX,dword ptr [ESP + param_1]
//         004cc8ca     ADD        ESP,0xc
//         004cc8cd     DEC        EAX
//         004cc8ce     TEST       EAX,EAX
//                              t_histry.cpp:101 (9)
//         004cc8d0     LEA        EBX,[ESI + 0xc]
//         004cc8d3     MOV        dword ptr [ESP + param_1],EAX
//         004cc8d7     JG         LAB_004cc8ad
//                               LAB_004cc8d9                                                 XREF[1]:     004cc8ab(j)
//                              t_histry.cpp:103 (6)
//         004cc8d9     POP        EDI
//         004cc8da     POP        ESI
//         004cc8db     POP        EBX
//         004cc8dc     RET        0x4
//         004cc8df     ??         90h
    return;
}

void TRIBE_History_Info::add_history_entry(uchar param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall add_history_entry(TRIBE_History_Info * this, uchar p
//              void              <VOID>         <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004cc928(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004cc935(R)
//                               ?add_history_entry@TRIBE_History_Info@@QAEXEE@Z              XREF[3]:     update:0051243d(c),
//                               TRIBE_History_Info::add_history_entry                                     add_population_entry:00513ff0(c),
//                                                                                                         add_population_entry:00514008(c)
//                              t_histry.cpp:110 (5)
//         004cc8e0     PUSH       EBX
//         004cc8e1     MOV        EBX,this
//         004cc8e3     PUSH       EBP
//         004cc8e4     PUSH       ESI
//                              t_histry.cpp:115 (11)
//         004cc8e5     MOV        ESI,dword ptr [EBX + 0x10]
//         004cc8e8     MOV        EAX,dword ptr [EBX + 0xc]
//         004cc8eb     CMP        EAX,ESI
//         004cc8ed     PUSH       EDI
//         004cc8ee     JL         LAB_004cc928
//                              t_histry.cpp:118 (3)
//         004cc8f0     LEA        EAX,[ESI + 0x3c]
//                              t_histry.cpp:120 (16)
//         004cc8f3     PUSH       0x1
//         004cc8f5     PUSH       EAX
//         004cc8f6     MOV        dword ptr [EBX + 0x10],EAX
//         004cc8f9     CALL       calloc                                           undefined calloc()
//         004cc8fe     ADD        ESP,0x8
//         004cc901     MOV        EBP,EAX
//                              t_histry.cpp:121 (4)
//         004cc903     TEST       ESI,ESI
//         004cc905     JLE        LAB_004cc926
//                              t_histry.cpp:123 (20)
//         004cc907     MOV        this,ESI
//         004cc909     MOV        ESI,dword ptr [EBX]
//         004cc90b     MOV        EAX,this
//         004cc90d     MOV        EDI,EBP
//         004cc90f     SHR        this,0x2
//         004cc912     MOVSD.REP  ES:EDI,ESI
//         004cc914     MOV        this,EAX
//         004cc916     AND        this,0x3
//         004cc919     MOVSB.REP  ES:EDI,ESI
//                              t_histry.cpp:124 (11)
//         004cc91b     MOV        this,dword ptr [EBX]
//         004cc91d     PUSH       this
//         004cc91e     CALL       free                                             undefined free()
//         004cc923     ADD        ESP,0x4
//                               LAB_004cc926                                                 XREF[1]:     004cc905(j)
//                              t_histry.cpp:126 (2)
//         004cc926     MOV        dword ptr [EBX],EBP
//                               LAB_004cc928                                                 XREF[1]:     004cc8ee(j)
//                              t_histry.cpp:130 (8)
//         004cc928     MOV        AL,byte ptr [ESP + param_1]
//         004cc92c     TEST       AL,AL
//         004cc92e     JNZ        LAB_004cc93c
//                              t_histry.cpp:133 (12)
//         004cc930     MOV        EDX,dword ptr [EBX]
//         004cc932     MOV        EAX,dword ptr [EBX + 0xc]
//         004cc935     MOV        this,byte ptr [ESP + param_2]
//         004cc939     MOV        byte ptr [EDX + EAX*0x1],this
//                               LAB_004cc93c                                                 XREF[1]:     004cc92e(j)
//                              t_histry.cpp:136 (3)
//         004cc93c     MOV        EAX,dword ptr [EBX + 0xc]
//                              t_histry.cpp:137 (11)
//         004cc93f     POP        EDI
//         004cc940     INC        EAX
//         004cc941     POP        ESI
//         004cc942     MOV        dword ptr [EBX + 0xc],EAX
//         004cc945     POP        EBP
//         004cc946     POP        EBX
//         004cc947     RET        0x8
//         004cc94a     ??         90h
//         004cc94b     NOP
//         004cc94c     NOP
//         004cc94d     NOP
//         004cc94e     NOP
//         004cc94f     NOP
    return;
}

long TRIBE_History_Info::get_history_entry_num() {
    /* TODO: Stub */
//                              long __thiscall get_history_entry_num(TRIBE_History_Info * this)
//              long              EAX:4          <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//                               ?get_history_entry_num@TRIBE_History_Info@@QAEJXZ            XREF[1]:     init_timeline:0051f345(c)
//                               TRIBE_History_Info::get_history_entry_num
//                              t_histry.cpp:144 (3)
//         004cc950     MOV        EAX,dword ptr [ECX + this->number_of_entries]
//                              t_histry.cpp:146 (1)
//         004cc953     RET
//         004cc954     ??         90h
//         004cc955     NOP
//         004cc956     NOP
//         004cc957     NOP
//         004cc958     NOP
//         004cc959     NOP
//         004cc95a     NOP
//         004cc95b     NOP
//         004cc95c     NOP
//         004cc95d     NOP
//         004cc95e     NOP
//         004cc95f     NOP
    return 0;
}

uchar TRIBE_History_Info::get_history_entry(uchar param_1, long param_2) {
    /* TODO: Stub */
//                              uchar __thiscall get_history_entry(TRIBE_History_Info * this, uchar
//              uchar             AL:1           <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004cc96f(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004cc960(R)
//                               ?get_history_entry@TRIBE_History_Info@@QAEEEJ@Z              XREF[6]:     draw_civilization_names:005202b9(c
//                               TRIBE_History_Info::get_history_entry                                     draw_civilization_names:00520348(c
//                                                                                                         draw_timeline:00520553(c),
//                                                                                                         draw_timeline:005206a4(c),
//                                                                                                         draw_timeline:00520851(c),
//                                                                                                         draw_timeline:005208eb(c)
//                              t_histry.cpp:153 (15)
//         004cc960     MOV        EAX,dword ptr [ESP + param_2]
//         004cc964     MOV        EDX,dword ptr [ECX + this->number_of_entries]
//         004cc967     CMP        EAX,EDX
//         004cc969     JGE        LAB_004cc97f
//         004cc96b     TEST       EAX,EAX
//         004cc96d     JL         LAB_004cc97f
//                              t_histry.cpp:155 (8)
//         004cc96f     MOV        DL,byte ptr [ESP + param_1]
//         004cc973     TEST       DL,DL
//         004cc975     JNZ        LAB_004cc97f
//                              t_histry.cpp:158 (5)
//         004cc977     MOV        this,dword ptr [this->history]
//         004cc979     MOV        AL,byte ptr [this->history + EAX*0x1]
//                              t_histry.cpp:162 (3)
//         004cc97c     RET        0x8
//                               LAB_004cc97f                                                 XREF[3]:     004cc969(j), 004cc96d(j),
//                                                                                                         004cc975(j)
//                              t_histry.cpp:161 (2)
//         004cc97f     XOR        AL,AL
//                              t_histry.cpp:162 (3)
//         004cc981     RET        0x8
//         004cc984     ??         90h
//         004cc985     NOP
//         004cc986     NOP
//         004cc987     NOP
//         004cc988     NOP
//         004cc989     NOP
//         004cc98a     NOP
//         004cc98b     NOP
//         004cc98c     NOP
//         004cc98d     NOP
//         004cc98e     NOP
//         004cc98f     NOP
    return 0;
}

void TRIBE_History_Info::add_history_event(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall add_history_event(TRIBE_History_Info * this, uchar p
//              void              <VOID>         <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004cc9c1(R)
//                               ?add_history_event@TRIBE_History_Info@@QAEXE@Z               XREF[3]:     do_tech:0050c660(c),
//                               TRIBE_History_Info::add_history_event                                     do_tech:0050c67e(c),
//                                                                                                         do_tech:0050c69c(c)
//                              t_histry.cpp:169 (3)
//         004cc990     PUSH       ESI
//         004cc991     MOV        ESI,this
//                              t_histry.cpp:173 (7)
//         004cc993     MOV        EAX,dword ptr [ESI + 0xc]
//         004cc996     TEST       EAX,EAX
//         004cc998     JLE        LAB_004cc9cd
//                              t_histry.cpp:176 (9)
//         004cc99a     PUSH       0x10
//         004cc99c     PUSH       0x1
//         004cc99e     CALL       calloc                                           undefined calloc()
//                              t_histry.cpp:177 (9)
//         004cc9a3     MOV        this,dword ptr [ESI + 0x4]
//         004cc9a6     ADD        ESP,0x8
//         004cc9a9     MOV        dword ptr [EAX + 0xc],this
//                              t_histry.cpp:178 (6)
//         004cc9ac     MOV        EDX,dword ptr [ESI + 0xc]
//         004cc9af     MOV        dword ptr [EAX + 0x4],EDX
//                              t_histry.cpp:179 (15)
//         004cc9b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cc9b8     MOV        EDX,dword ptr [this->history + 0x3f4]
//         004cc9be     MOV        this,dword ptr [EDX + 0x4]
//                              t_histry.cpp:180 (9)
//         004cc9c1     MOV        DL,byte ptr [ESP + param_1]
//         004cc9c5     MOV        dword ptr [EAX + 0x8],this
//         004cc9c8     MOV        byte ptr [EAX],DL
//                              t_histry.cpp:181 (3)
//         004cc9ca     MOV        dword ptr [ESI + 0x4],EAX
//                               LAB_004cc9cd                                                 XREF[1]:     004cc998(j)
//                              t_histry.cpp:182 (4)
//         004cc9cd     POP        ESI
//         004cc9ce     RET        0x4
//         004cc9d1     ??         90h
//         004cc9d2     NOP
//         004cc9d3     NOP
//         004cc9d4     NOP
//         004cc9d5     NOP
//         004cc9d6     NOP
//         004cc9d7     NOP
//         004cc9d8     NOP
//         004cc9d9     NOP
//         004cc9da     NOP
//         004cc9db     NOP
//         004cc9dc     NOP
//         004cc9dd     NOP
//         004cc9de     NOP
//         004cc9df     NOP
    return;
}

long TRIBE_History_Info::get_history_event_num() {
    /* TODO: Stub */
//                              long __thiscall get_history_event_num(TRIBE_History_Info * this)
//              long              EAX:4          <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//                               ?get_history_event_num@TRIBE_History_Info@@QAEJXZ
//                               TRIBE_History_Info::get_history_event_num
//                              t_histry.cpp:189 (3)
//         004cc9e0     MOV        EAX,dword ptr [ECX + this->number_of_events]
//                              t_histry.cpp:191 (1)
//         004cc9e3     RET
//         004cc9e4     ??         90h
//         004cc9e5     NOP
//         004cc9e6     NOP
//         004cc9e7     NOP
//         004cc9e8     NOP
//         004cc9e9     NOP
//         004cc9ea     NOP
//         004cc9eb     NOP
//         004cc9ec     NOP
//         004cc9ed     NOP
//         004cc9ee     NOP
//         004cc9ef     NOP
    return 0;
}

uchar TRIBE_History_Info::get_history_event(long param_1, uchar* param_2, long* param_3) {
    /* TODO: Stub */
//                              uchar __thiscall get_history_event(TRIBE_History_Info * this, long p
//              uchar             AL:1           <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004cca37(R)
//              uchar *           Stack[0x8]:4   param_2                   XREF[1]:     004cca4c(R)
//                               ?get_history_event@TRIBE_History_Info@@QAEEJAAE@Z            XREF[2]:     record_special_event:0051f572(c),
//                               TRIBE_History_Info::get_history_event                                     draw_timeline:00520587(c)
//                              t_histry.cpp:218 (11)
//         004cca30     MOV        EAX,dword ptr [ECX + this->events]
//         004cca33     TEST       EAX,EAX
//         004cca35     JZ         LAB_004cca59
//         004cca37     MOV        this,dword ptr [ESP + param_1]
//                               LAB_004cca3b                                                 XREF[1]:     004cca45(j)
//                              t_histry.cpp:222 (12)
//         004cca3b     CMP        dword ptr [EAX + 0x4],this
//         004cca3e     JZ         LAB_004cca4c
//         004cca40     MOV        EAX,dword ptr [EAX + 0xc]
//         004cca43     TEST       EAX,EAX
//         004cca45     JNZ        LAB_004cca3b
//                              t_histry.cpp:228 (2)
//         004cca47     XOR        AL,AL
//                              t_histry.cpp:229 (3)
//         004cca49     RET        0x8
//                               LAB_004cca4c                                                 XREF[1]:     004cca3e(j)
//                              t_histry.cpp:224 (8)
//         004cca4c     MOV        this,dword ptr [ESP + param_2]
//         004cca50     MOV        AL,byte ptr [EAX]
//         004cca52     MOV        byte ptr [this->history],AL
//                              t_histry.cpp:225 (2)
//         004cca54     MOV        AL,0x1
//                              t_histry.cpp:229 (3)
//         004cca56     RET        0x8
//                               LAB_004cca59                                                 XREF[1]:     004cca35(j)
//                              t_histry.cpp:228 (2)
//         004cca59     XOR        AL,AL
//                              t_histry.cpp:229 (3)
//         004cca5b     RET        0x8
//         004cca5e     ??         90h
//         004cca5f     NOP
    return 0;
}

uchar TRIBE_History_Info::get_history_event(long param_1, uchar* param_2) {
    /* TODO: Stub */
//                              uchar __thiscall get_history_event(TRIBE_History_Info * this, long p
//              uchar             AL:1           <RETURN>
//              TRIBE_History_    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004cca37(R)
//              uchar *           Stack[0x8]:4   param_2                   XREF[1]:     004cca4c(R)
//                               ?get_history_event@TRIBE_History_Info@@QAEEJAAE@Z            XREF[2]:     record_special_event:0051f572(c),
//                               TRIBE_History_Info::get_history_event                                     draw_timeline:00520587(c)
//                              t_histry.cpp:218 (11)
//         004cca30     MOV        EAX,dword ptr [ECX + this->events]
//         004cca33     TEST       EAX,EAX
//         004cca35     JZ         LAB_004cca59
//         004cca37     MOV        this,dword ptr [ESP + param_1]
//                               LAB_004cca3b                                                 XREF[1]:     004cca45(j)
//                              t_histry.cpp:222 (12)
//         004cca3b     CMP        dword ptr [EAX + 0x4],this
//         004cca3e     JZ         LAB_004cca4c
//         004cca40     MOV        EAX,dword ptr [EAX + 0xc]
//         004cca43     TEST       EAX,EAX
//         004cca45     JNZ        LAB_004cca3b
//                              t_histry.cpp:228 (2)
//         004cca47     XOR        AL,AL
//                              t_histry.cpp:229 (3)
//         004cca49     RET        0x8
//                               LAB_004cca4c                                                 XREF[1]:     004cca3e(j)
//                              t_histry.cpp:224 (8)
//         004cca4c     MOV        this,dword ptr [ESP + param_2]
//         004cca50     MOV        AL,byte ptr [EAX]
//         004cca52     MOV        byte ptr [this->history],AL
//                              t_histry.cpp:225 (2)
//         004cca54     MOV        AL,0x1
//                              t_histry.cpp:229 (3)
//         004cca56     RET        0x8
//                               LAB_004cca59                                                 XREF[1]:     004cca35(j)
//                              t_histry.cpp:228 (2)
//         004cca59     XOR        AL,AL
//                              t_histry.cpp:229 (3)
//         004cca5b     RET        0x8
//         004cca5e     ??         90h
//         004cca5f     NOP
    return 0;
}

