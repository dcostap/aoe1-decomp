#include "../common.h"
#include "zone_map.h"

uchar zone_pop(Zone_Queue** param_1, Zone_Queue** param_2, long* param_3, long* param_4) {
    /* TODO: Stub */
//                              uchar __cdecl zone_pop(Zone_Queue * * param_1, Zone_Queue * * param_
//              uchar             AL:1           <RETURN>
//              Zone_Queue * *    Stack[0x4]:4   param_1                   XREF[1]:     00546721(R)
//              Zone_Queue * *    Stack[0x8]:4   param_2                   XREF[1]:     00546754(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     0054672f(R)
//              long *            Stack[0x10]:4  param_4                   XREF[1]:     00546738(R)
//                               ?zone_pop@@YAEPAPAUZone_Queue@@0AAJ1@Z                       XREF[1]:     do_zone_map_area:00546e2a(c)
//                               zone_pop
//                              zone_map.cpp:32 (1)
//         00546720     PUSH       ESI
//                              zone_map.cpp:35 (10)
//         00546721     MOV        ESI,dword ptr [ESP + param_1]
//         00546725     MOV        EAX,dword ptr [ESI]
//         00546727     TEST       EAX,EAX
//         00546729     JNZ        LAB_0054672f
//                              zone_map.cpp:36 (2)
//         0054672b     XOR        AL,AL
//                              zone_map.cpp:48 (2)
//         0054672d     POP        ESI
//         0054672e     RET
//                               LAB_0054672f                                                 XREF[1]:     00546729(j)
//                              zone_map.cpp:39 (6)
//         0054672f     MOV        EDX,dword ptr [ESP + param_3]
//         00546733     MOV        ECX,dword ptr [EAX]
//                              zone_map.cpp:43 (22)
//         00546735     PUSH       EAX
//         00546736     MOV        dword ptr [EDX],ECX
//         00546738     MOV        EDX,dword ptr [ESP + param_4]
//         0054673c     MOV        ECX,dword ptr [EAX + 0x4]
//         0054673f     MOV        dword ptr [EDX],ECX
//         00546741     MOV        ECX,dword ptr [EAX + 0x8]
//         00546744     MOV        dword ptr [ESI],ECX
//         00546746     CALL       free                                             undefined free()
//                              zone_map.cpp:45 (9)
//         0054674b     MOV        EAX,dword ptr [ESI]
//         0054674d     ADD        ESP,0x4
//         00546750     TEST       EAX,EAX
//         00546752     JNZ        LAB_0054675e
//                              zone_map.cpp:46 (10)
//         00546754     MOV        EDX,dword ptr [ESP + param_2]
//         00546758     MOV        dword ptr [EDX],0x0
//                               LAB_0054675e                                                 XREF[1]:     00546752(j)
//                              zone_map.cpp:47 (2)
//         0054675e     MOV        AL,0x1
//                              zone_map.cpp:48 (2)
//         00546760     POP        ESI
//         00546761     RET
//         00546762     ??         90h
//         00546763     NOP
//         00546764     NOP
//         00546765     NOP
//         00546766     NOP
//         00546767     NOP
//         00546768     NOP
//         00546769     NOP
//         0054676a     NOP
//         0054676b     NOP
//         0054676c     NOP
//         0054676d     NOP
//         0054676e     NOP
//         0054676f     NOP
    return 0;
}

void zone_push(Zone_Queue** param_1, Zone_Queue** param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __cdecl zone_push(Zone_Queue * * param_1, Zone_Queue * * param_
//              void              <VOID>         <RETURN>
//              Zone_Queue * *    Stack[0x4]:4   param_1                   XREF[1]:     00546796(R)
//              Zone_Queue * *    Stack[0x8]:4   param_2                   XREF[1]:     00546779(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00546789(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0054678f(R)
//                               ?zone_push@@YAXPAPAUZone_Queue@@0JJ@Z                        XREF[4]:     do_zone_map_area:00546c63(c),
//                               zone_push                                                                 do_zone_map_area:00546cf0(c),
//                                                                                                         do_zone_map_area:00546d82(c),
//                                                                                                         do_zone_map_area:00546e0e(c)
//                              zone_map.cpp:53 (9)
//         00546770     PUSH       0xc
//         00546772     PUSH       0x1
//         00546774     CALL       calloc                                           undefined calloc()
//                              zone_map.cpp:58 (13)
//         00546779     MOV        EDX,dword ptr [ESP + param_2]
//         0054677d     ADD        ESP,0x8
//         00546780     MOV        ECX,dword ptr [EDX]
//         00546782     TEST       ECX,ECX
//         00546784     JZ         LAB_00546789
//                              zone_map.cpp:59 (3)
//         00546786     MOV        dword ptr [ECX + 0x8],EAX
//                               LAB_00546789                                                 XREF[1]:     00546784(j)
//                              zone_map.cpp:60 (6)
//         00546789     MOV        ECX,dword ptr [ESP + param_3]
//         0054678d     MOV        dword ptr [EAX],ECX
//                              zone_map.cpp:61 (7)
//         0054678f     MOV        ECX,dword ptr [ESP + param_4]
//         00546793     MOV        dword ptr [EAX + 0x4],ECX
//                              zone_map.cpp:64 (11)
//         00546796     MOV        ECX,dword ptr [ESP + param_1]
//         0054679a     MOV        dword ptr [EDX],EAX
//         0054679c     CMP        dword ptr [ECX],0x0
//         0054679f     JNZ        LAB_005467a3
//                              zone_map.cpp:65 (2)
//         005467a1     MOV        dword ptr [ECX],EAX
//                               LAB_005467a3                                                 XREF[1]:     0054679f(j)
//                              zone_map.cpp:66 (1)
//         005467a3     RET
//         005467a4     ??         90h
//         005467a5     NOP
//         005467a6     NOP
//         005467a7     NOP
//         005467a8     NOP
//         005467a9     NOP
//         005467aa     NOP
//         005467ab     NOP
//         005467ac     NOP
//         005467ad     NOP
//         005467ae     NOP
//         005467af     NOP
    return;
}

RGE_Zone_Map::RGE_Zone_Map(int param_1, RGE_Map* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Zone_Map(RGE_Zone_Map * this, RGE_Map * par
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     005468c0(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     00546989(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00546971(R)
//                               ??0RGE_Zone_Map@@QAE@PAVRGE_Map@@PAMJ@Z                      XREF[2]:     create_zone_map:0054735f(c),
//                               RGE_Zone_Map::RGE_Zone_Map                                                get_zone_map:0054745e(c)
//                              zone_map.cpp:117 (9)
//         005468c0     MOV        EAX,dword ptr [ESP + param_1]
//         005468c4     PUSH       EBX
//         005468c5     MOV        EBX,this
//         005468c7     PUSH       ESI
//         005468c8     PUSH       EDI
//                              zone_map.cpp:123 (23)
//         005468c9     PUSH       0x1
//         005468cb     MOV        dword ptr [EBX + 0x518],EAX
//         005468d1     MOV        this,dword ptr [EAX + 0xc]
//         005468d4     IMUL       this,dword ptr [EAX + 0x8]
//         005468d8     PUSH       this
//         005468d9     CALL       calloc                                           undefined calloc()
//         005468de     MOV        EDI,EAX
//                              zone_map.cpp:124 (34)
//         005468e0     MOV        EAX,dword ptr [EBX + 0x518]
//         005468e6     MOV        dword ptr [EBX + 0x404],EDI
//         005468ec     ADD        ESP,0x8
//         005468ef     MOV        this,dword ptr [EAX + 0xc]
//         005468f2     IMUL       this,dword ptr [EAX + 0x8]
//         005468f6     MOV        EDX,this
//         005468f8     OR         EAX,0xffffffff
//         005468fb     SHR        this,0x2
//         005468fe     STOSD.REP  ES:EDI
//         00546900     MOV        this,EDX
//                              zone_map.cpp:127 (22)
//         00546902     PUSH       0x4
//         00546904     AND        this,0x3
//         00546907     STOSB.REP  ES:EDI
//         00546909     MOV        EAX,dword ptr [EBX + 0x518]
//         0054690f     MOV        this,dword ptr [EAX + 0xc]
//         00546912     PUSH       this
//         00546913     CALL       calloc                                           undefined calloc()
//                              zone_map.cpp:128 (24)
//         00546918     MOV        this,dword ptr [EBX + 0x518]
//         0054691e     MOV        dword ptr [EBX + 0x408],EAX
//         00546924     ADD        ESP,0x8
//         00546927     XOR        EAX,EAX
//         00546929     MOV        EDX,dword ptr [ECX + this+0xc]
//         0054692c     TEST       EDX,EDX
//         0054692e     JLE        LAB_00546953
//                               LAB_00546930                                                 XREF[1]:     00546951(j)
//                              zone_map.cpp:129 (35)
//         00546930     MOV        EDX,dword ptr [ECX + this+0x8]
//         00546933     MOV        EDI,dword ptr [EBX + 0x404]
//         00546939     IMUL       EDX,EAX
//         0054693c     MOV        this,dword ptr [EBX + 0x408]
//         00546942     ADD        EDX,EDI
//         00546944     MOV        dword ptr [this->numberTilesInZoneValue[0] + E
//         00546947     MOV        this,dword ptr [EBX + 0x518]
//         0054694d     INC        EAX
//         0054694e     CMP        EAX,dword ptr [ECX + this+0xc]
//         00546951     JL         LAB_00546930
//                               LAB_00546953                                                 XREF[1]:     0054692e(j)
//                              zone_map.cpp:132 (9)
//         00546953     XOR        EAX,EAX
//         00546955     MOV        this,EBX
//         00546957     MOV        EDX,0xff
//                               LAB_0054695c                                                 XREF[1]:     0054696f(j)
//                              zone_map.cpp:134 (7)
//         0054695c     MOV        byte ptr [EAX + EBX*0x1 + 0x40c],DL
//                              zone_map.cpp:135 (14)
//         00546963     MOV        dword ptr [this->numberTilesInZoneValue[0]],0x0
//         00546969     INC        EAX
//         0054696a     ADD        this,0x4
//         0054696d     CMP        EAX,EDX
//         0054696f     JL         LAB_0054695c
//                              zone_map.cpp:139 (4)
//         00546971     MOV        EAX,dword ptr [ESP + param_3]
//                              zone_map.cpp:140 (14)
//         00546975     PUSH       0x4
//         00546977     PUSH       EAX
//         00546978     MOV        dword ptr [EBX + 0x514],EAX
//         0054697e     CALL       calloc                                           undefined calloc()
//                              zone_map.cpp:141 (38)
//         00546983     MOV        this,dword ptr [EBX + 0x514]
//         00546989     MOV        ESI,dword ptr [ESP + param_2]
//         0054698d     SHL        this,0x2
//         00546990     MOV        EDX,this
//         00546992     MOV        EDI,EAX
//         00546994     SHR        this,0x2
//         00546997     MOV        dword ptr [EBX + 0x510],EAX
//         0054699d     ADD        ESP,0x8
//         005469a0     MOVSD.REP  ES:EDI,ESI
//         005469a2     MOV        this,EDX
//         005469a4     AND        this,0x3
//         005469a7     MOVSB.REP  ES:EDI,ESI
//                              zone_map.cpp:143 (7)
//         005469a9     MOV        this,EBX
//         005469ab     CALL       RGE_Zone_Map::do_zone_map                        uchar do_zone_map(RGE_Zone_Map * this)
//                              zone_map.cpp:144 (8)
//         005469b0     POP        EDI
//         005469b1     MOV        EAX,EBX
//         005469b3     POP        ESI
//         005469b4     POP        EBX
//         005469b5     RET        0xc
//         005469b8     ??         90h
//         005469b9     NOP
//         005469ba     NOP
//         005469bb     NOP
//         005469bc     NOP
//         005469bd     NOP
//         005469be     NOP
//         005469bf     NOP
}

RGE_Zone_Map::RGE_Zone_Map(RGE_Map* param_1, float* param_2, long param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Zone_Map(RGE_Zone_Map * this, RGE_Map * par
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     005468c0(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     00546989(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00546971(R)
//                               ??0RGE_Zone_Map@@QAE@PAVRGE_Map@@PAMJ@Z                      XREF[2]:     create_zone_map:0054735f(c),
//                               RGE_Zone_Map::RGE_Zone_Map                                                get_zone_map:0054745e(c)
//                              zone_map.cpp:117 (9)
//         005468c0     MOV        EAX,dword ptr [ESP + param_1]
//         005468c4     PUSH       EBX
//         005468c5     MOV        EBX,this
//         005468c7     PUSH       ESI
//         005468c8     PUSH       EDI
//                              zone_map.cpp:123 (23)
//         005468c9     PUSH       0x1
//         005468cb     MOV        dword ptr [EBX + 0x518],EAX
//         005468d1     MOV        this,dword ptr [EAX + 0xc]
//         005468d4     IMUL       this,dword ptr [EAX + 0x8]
//         005468d8     PUSH       this
//         005468d9     CALL       calloc                                           undefined calloc()
//         005468de     MOV        EDI,EAX
//                              zone_map.cpp:124 (34)
//         005468e0     MOV        EAX,dword ptr [EBX + 0x518]
//         005468e6     MOV        dword ptr [EBX + 0x404],EDI
//         005468ec     ADD        ESP,0x8
//         005468ef     MOV        this,dword ptr [EAX + 0xc]
//         005468f2     IMUL       this,dword ptr [EAX + 0x8]
//         005468f6     MOV        EDX,this
//         005468f8     OR         EAX,0xffffffff
//         005468fb     SHR        this,0x2
//         005468fe     STOSD.REP  ES:EDI
//         00546900     MOV        this,EDX
//                              zone_map.cpp:127 (22)
//         00546902     PUSH       0x4
//         00546904     AND        this,0x3
//         00546907     STOSB.REP  ES:EDI
//         00546909     MOV        EAX,dword ptr [EBX + 0x518]
//         0054690f     MOV        this,dword ptr [EAX + 0xc]
//         00546912     PUSH       this
//         00546913     CALL       calloc                                           undefined calloc()
//                              zone_map.cpp:128 (24)
//         00546918     MOV        this,dword ptr [EBX + 0x518]
//         0054691e     MOV        dword ptr [EBX + 0x408],EAX
//         00546924     ADD        ESP,0x8
//         00546927     XOR        EAX,EAX
//         00546929     MOV        EDX,dword ptr [ECX + this+0xc]
//         0054692c     TEST       EDX,EDX
//         0054692e     JLE        LAB_00546953
//                               LAB_00546930                                                 XREF[1]:     00546951(j)
//                              zone_map.cpp:129 (35)
//         00546930     MOV        EDX,dword ptr [ECX + this+0x8]
//         00546933     MOV        EDI,dword ptr [EBX + 0x404]
//         00546939     IMUL       EDX,EAX
//         0054693c     MOV        this,dword ptr [EBX + 0x408]
//         00546942     ADD        EDX,EDI
//         00546944     MOV        dword ptr [this->numberTilesInZoneValue[0] + E
//         00546947     MOV        this,dword ptr [EBX + 0x518]
//         0054694d     INC        EAX
//         0054694e     CMP        EAX,dword ptr [ECX + this+0xc]
//         00546951     JL         LAB_00546930
//                               LAB_00546953                                                 XREF[1]:     0054692e(j)
//                              zone_map.cpp:132 (9)
//         00546953     XOR        EAX,EAX
//         00546955     MOV        this,EBX
//         00546957     MOV        EDX,0xff
//                               LAB_0054695c                                                 XREF[1]:     0054696f(j)
//                              zone_map.cpp:134 (7)
//         0054695c     MOV        byte ptr [EAX + EBX*0x1 + 0x40c],DL
//                              zone_map.cpp:135 (14)
//         00546963     MOV        dword ptr [this->numberTilesInZoneValue[0]],0x0
//         00546969     INC        EAX
//         0054696a     ADD        this,0x4
//         0054696d     CMP        EAX,EDX
//         0054696f     JL         LAB_0054695c
//                              zone_map.cpp:139 (4)
//         00546971     MOV        EAX,dword ptr [ESP + param_3]
//                              zone_map.cpp:140 (14)
//         00546975     PUSH       0x4
//         00546977     PUSH       EAX
//         00546978     MOV        dword ptr [EBX + 0x514],EAX
//         0054697e     CALL       calloc                                           undefined calloc()
//                              zone_map.cpp:141 (38)
//         00546983     MOV        this,dword ptr [EBX + 0x514]
//         00546989     MOV        ESI,dword ptr [ESP + param_2]
//         0054698d     SHL        this,0x2
//         00546990     MOV        EDX,this
//         00546992     MOV        EDI,EAX
//         00546994     SHR        this,0x2
//         00546997     MOV        dword ptr [EBX + 0x510],EAX
//         0054699d     ADD        ESP,0x8
//         005469a0     MOVSD.REP  ES:EDI,ESI
//         005469a2     MOV        this,EDX
//         005469a4     AND        this,0x3
//         005469a7     MOVSB.REP  ES:EDI,ESI
//                              zone_map.cpp:143 (7)
//         005469a9     MOV        this,EBX
//         005469ab     CALL       RGE_Zone_Map::do_zone_map                        uchar do_zone_map(RGE_Zone_Map * this)
//                              zone_map.cpp:144 (8)
//         005469b0     POP        EDI
//         005469b1     MOV        EAX,EBX
//         005469b3     POP        ESI
//         005469b4     POP        EBX
//         005469b5     RET        0xc
//         005469b8     ??         90h
//         005469b9     NOP
//         005469ba     NOP
//         005469bb     NOP
//         005469bc     NOP
//         005469bd     NOP
//         005469be     NOP
//         005469bf     NOP
}

RGE_Zone_Map::~RGE_Zone_Map() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Zone_Map(RGE_Zone_Map * this)
//              void              <VOID>         <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//                               ??1RGE_Zone_Map@@QAE@XZ                                      XREF[1]:     delete_zone_maps:005474f2(c)
//                               RGE_Zone_Map::~RGE_Zone_Map
//                              zone_map.cpp:149 (3)
//         005469c0     PUSH       ESI
//         005469c1     MOV        ESI,this
//                              zone_map.cpp:150 (12)
//         005469c3     MOV        EAX,dword ptr [ESI + 0x404]
//         005469c9     PUSH       EAX
//         005469ca     CALL       free                                             undefined free()
//                              zone_map.cpp:151 (15)
//         005469cf     MOV        this,dword ptr [ESI + 0x408]
//         005469d5     ADD        ESP,0x4
//         005469d8     PUSH       this
//         005469d9     CALL       free                                             undefined free()
//                              zone_map.cpp:152 (18)
//         005469de     MOV        EDX,dword ptr [ESI + 0x510]
//         005469e4     ADD        ESP,0x4
//         005469e7     PUSH       EDX
//         005469e8     CALL       free                                             undefined free()
//         005469ed     ADD        ESP,0x4
//                              zone_map.cpp:153 (2)
//         005469f0     POP        ESI
//         005469f1     RET
//         005469f2     ??         90h
//         005469f3     NOP
//         005469f4     NOP
//         005469f5     NOP
//         005469f6     NOP
//         005469f7     NOP
//         005469f8     NOP
//         005469f9     NOP
//         005469fa     NOP
//         005469fb     NOP
//         005469fc     NOP
//         005469fd     NOP
//         005469fe     NOP
//         005469ff     NOP
}

void RGE_Zone_Map::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Zone_Map * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00546a05(R)
//                               ?save@RGE_Zone_Map@@QAEXH@Z                                  XREF[1]:     save:0054729b(c)
//                               RGE_Zone_Map::save
//                              zone_map.cpp:158 (5)
//         00546a00     PUSH       EBX
//         00546a01     PUSH       ESI
//         00546a02     MOV        ESI,this
//         00546a04     PUSH       EDI
//                              zone_map.cpp:159 (25)
//         00546a05     MOV        EDI,dword ptr [ESP + param_1]
//         00546a09     PUSH       0xff
//         00546a0e     LEA        EAX,[ESI + 0x40c]
//         00546a14     PUSH       EAX
//         00546a15     PUSH       EDI
//         00546a16     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00546a1b     ADD        ESP,0xc
//                              zone_map.cpp:160 (12)
//         00546a1e     PUSH       0x3fc
//         00546a23     PUSH       ESI
//         00546a24     PUSH       EDI
//         00546a25     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              zone_map.cpp:161 (33)
//         00546a2a     MOV        EAX,dword ptr [ESI + 0x518]
//         00546a30     MOV        EDX,dword ptr [ESI + 0x404]
//         00546a36     ADD        ESP,0xc
//         00546a39     MOV        this,dword ptr [EAX + 0xc]
//         00546a3c     IMUL       this,dword ptr [EAX + 0x8]
//         00546a40     PUSH       this
//         00546a41     PUSH       EDX
//         00546a42     PUSH       EDI
//         00546a43     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00546a48     ADD        ESP,0xc
//                              zone_map.cpp:162 (15)
//         00546a4b     LEA        EBX,[ESI + 0x514]
//         00546a51     PUSH       0x4
//         00546a53     PUSH       EBX
//         00546a54     PUSH       EDI
//         00546a55     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              zone_map.cpp:163 (9)
//         00546a5a     MOV        EBX,dword ptr [EBX]
//         00546a5c     ADD        ESP,0xc
//         00546a5f     TEST       EBX,EBX
//         00546a61     JLE        LAB_00546a7b
//                              zone_map.cpp:164 (24)
//         00546a63     MOV        this,dword ptr [ESI + 0x510]
//         00546a69     LEA        EAX,[EBX*0x4 + 0x0]
//         00546a70     PUSH       EAX
//         00546a71     PUSH       this
//         00546a72     PUSH       EDI
//         00546a73     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00546a78     ADD        ESP,0xc
//                               LAB_00546a7b                                                 XREF[1]:     00546a61(j)
//                              zone_map.cpp:167 (6)
//         00546a7b     POP        EDI
//         00546a7c     POP        ESI
//         00546a7d     POP        EBX
//         00546a7e     RET        0x4
//         00546a81     ??         90h
//         00546a82     NOP
//         00546a83     NOP
//         00546a84     NOP
//         00546a85     NOP
//         00546a86     NOP
//         00546a87     NOP
//         00546a88     NOP
//         00546a89     NOP
//         00546a8a     NOP
//         00546a8b     NOP
//         00546a8c     NOP
//         00546a8d     NOP
//         00546a8e     NOP
//         00546a8f     NOP
    return;
}

uchar RGE_Zone_Map::do_zone_map() {
    /* TODO: Stub */
//                              uchar __thiscall do_zone_map(RGE_Zone_Map * this)
//              uchar             AL:1           <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00546abf(W), 00546b74(R)
//              long              Stack[-0x8]:4  map_height                XREF[3]:     00546ab5(W), 00546ae1(R), 00546b91(R)
//              long              Stack[-0xc]:4  map_width                 XREF[3]:     00546b28(W), 00546b57(W), 00546b5e(R)
//              uchar             Stack[-0x10]:1 group                     XREF[4]:     00546aee(W), 00546b62(R), 00546b8d(R), 00546b9b(W)
//              long              Stack[-0x14]:4 y                         XREF[4]:     00546b02(W), 00546b36(R), 00546b79(R), 00546b83(W)
//                               ?do_zone_map@RGE_Zone_Map@@QAEEXZ                            XREF[2]:     RGE_Zone_Map:005469ab(c),
//                               RGE_Zone_Map::do_zone_map                                                 create_zone_map:00547396(c)
//                              zone_map.cpp:172 (9)
//         00546a90     SUB        ESP,0x14
//         00546a93     PUSH       EBX
//         00546a94     PUSH       EBP
//         00546a95     MOV        EBP,this
//         00546a97     PUSH       ESI
//         00546a98     PUSH       EDI
//                              zone_map.cpp:181 (17)
//         00546a99     MOV        this,0x3f
//         00546a9e     MOV        EAX,dword ptr [EBP + 0x518]
//         00546aa4     LEA        EDI,[EBP + 0x40c]
//                              zone_map.cpp:183 (19)
//         00546aaa     XOR        EBX,EBX
//         00546aac     MOV        ESI,dword ptr [EAX + 0x8]
//         00546aaf     MOV        EDX,dword ptr [EAX + 0xc]
//         00546ab2     OR         EAX,0xffffffff
//         00546ab5     MOV        dword ptr [ESP + map_height],ESI
//         00546ab9     STOSD.REP  ES:EDI
//         00546abb     STOSW      ES:EDI
//                              zone_map.cpp:186 (11)
//         00546abd     XOR        this,this
//         00546abf     MOV        dword ptr [ESP + local_4],EDX
//         00546ac3     TEST       ESI,ESI
//         00546ac5     STOSB      ES:EDI
//         00546ac6     JLE        LAB_00546aea
//                               LAB_00546ac8                                                 XREF[1]:     00546ae8(j)
//                              zone_map.cpp:187 (6)
//         00546ac8     XOR        EAX,EAX
//         00546aca     TEST       EDX,EDX
//         00546acc     JLE        LAB_00546ae5
//                               LAB_00546ace                                                 XREF[1]:     00546adf(j)
//                              zone_map.cpp:188 (19)
//         00546ace     MOV        ESI,dword ptr [EBP + 0x408]
//         00546ad4     INC        EAX
//         00546ad5     CMP        EAX,EDX
//         00546ad7     MOV        ESI,dword ptr [ESI + this->numberTilesInZoneVa
//         00546ada     MOV        byte ptr [ESI + EAX*0x1 + -0x1],0xff
//         00546adf     JL         LAB_00546ace
//                              zone_map.cpp:187 (4)
//         00546ae1     MOV        ESI,dword ptr [ESP + map_height]
//                               LAB_00546ae5                                                 XREF[1]:     00546acc(j)
//                              zone_map.cpp:186 (5)
//         00546ae5     INC        this
//         00546ae6     CMP        this,ESI
//         00546ae8     JL         LAB_00546ac8
//                               LAB_00546aea                                                 XREF[1]:     00546ac6(j)
//                              zone_map.cpp:191 (14)
//         00546aea     XOR        EDI,EDI
//         00546aec     CMP        ESI,EDI
//         00546aee     MOV        dword ptr [ESP + group],EDI
//         00546af2     JLE        LAB_00546ba5
//                               LAB_00546af8                                                 XREF[1]:     00546b9f(j)
//                              zone_map.cpp:192 (14)
//         00546af8     XOR        ESI,ESI
//         00546afa     CMP        EDX,ESI
//         00546afc     JLE        LAB_00546b8d
//         00546b02     MOV        dword ptr [ESP + y],ESI
//                               LAB_00546b06                                                 XREF[1]:     00546b87(j)
//                              zone_map.cpp:194 (18)
//         00546b06     MOV        EAX,dword ptr [EBP + 0x408]
//         00546b0c     LEA        this,[EAX + EDI*0x1]
//         00546b0f     MOV        EAX,dword ptr [EAX + EDI*0x1]
//         00546b12     CMP        byte ptr [ESI + EAX*0x1],0xff
//         00546b16     JNZ        LAB_00546b79
//                              zone_map.cpp:196 (8)
//         00546b18     CMP        EBX,0xff
//         00546b1e     JL         LAB_00546b22
//                              zone_map.cpp:197 (2)
//         00546b20     XOR        EBX,EBX
//                               LAB_00546b22                                                 XREF[1]:     00546b1e(j)
//                              zone_map.cpp:199 (58)
//         00546b22     MOV        EDX,dword ptr [EBP + 0x518]
//         00546b28     MOV        byte ptr [ESP + map_width],0x1
//         00546b2d     MOV        EAX,dword ptr [EDX + 0x8d8c]
//         00546b33     MOV        EDX,dword ptr [EAX + EDI*0x1]
//         00546b36     MOV        EAX,dword ptr [ESP + y]
//         00546b3a     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x5]
//         00546b3e     MOV        EAX,dword ptr [EBP + 0x510]
//         00546b44     AND        EDX,0x1f
//         00546b47     FLD        float ptr [EAX + EDX*0x4]
//         00546b4a     FCOMP      double ptr [DAT_00577a20]
//         00546b50     FNSTSW     AX
//         00546b52     TEST       AH,0x41
//         00546b55     JZ         LAB_00546b5c
//         00546b57     MOV        byte ptr [ESP + map_width],0x0
//                               LAB_00546b5c                                                 XREF[1]:     00546b55(j)
//                              zone_map.cpp:201 (2)
//         00546b5c     MOV        this,dword ptr [this->numberTilesInZoneValue[0]]
//                              zone_map.cpp:202 (22)
//         00546b5e     MOV        EDX,dword ptr [ESP + map_width]
//         00546b62     MOV        EAX,dword ptr [ESP + group]
//         00546b66     PUSH       EBX
//         00546b67     PUSH       EDX
//         00546b68     MOV        byte ptr [ESI + this->numberTilesInZoneValue[0
//         00546b6b     PUSH       EAX
//         00546b6c     PUSH       ESI
//         00546b6d     MOV        this,EBP
//         00546b6f     CALL       RGE_Zone_Map::do_zone_map_area                   void do_zone_map_area(RGE_Zone_Map * this, lo
//                              zone_map.cpp:203 (25)
//         00546b74     MOV        EDX,dword ptr [ESP + local_4]
//         00546b78     INC        EBX
//                               LAB_00546b79                                                 XREF[1]:     00546b16(j)
//         00546b79     MOV        this,dword ptr [ESP + y]
//         00546b7d     INC        ESI
//         00546b7e     ADD        this,0x18
//         00546b81     CMP        ESI,EDX
//         00546b83     MOV        dword ptr [ESP + y],this
//         00546b87     JL         LAB_00546b06
//                               LAB_00546b8d                                                 XREF[1]:     00546afc(j)
//                              zone_map.cpp:191 (24)
//         00546b8d     MOV        EAX,dword ptr [ESP + group]
//         00546b91     MOV        this,dword ptr [ESP + map_height]
//         00546b95     INC        EAX
//         00546b96     ADD        EDI,0x4
//         00546b99     CMP        EAX,this
//         00546b9b     MOV        dword ptr [ESP + group],EAX
//         00546b9f     JL         LAB_00546af8
//                               LAB_00546ba5                                                 XREF[1]:     00546af2(j)
//                              zone_map.cpp:208 (10)
//         00546ba5     POP        EDI
//         00546ba6     POP        ESI
//         00546ba7     POP        EBP
//         00546ba8     MOV        AL,0x1
//         00546baa     POP        EBX
//         00546bab     ADD        ESP,0x14
//         00546bae     RET
//         00546baf     ??         90h
    return 0;
}

void RGE_Zone_Map::do_zone_map_area(long param_1, long param_2, uchar param_3, uchar param_4) {
    /* TODO: Stub */
//                              void __thiscall do_zone_map_area(RGE_Zone_Map * this, long param_1,
//              void              <VOID>         <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[9]:     00546bdd(R), 00546c4e(R), 00546c6c(R), 00546cdf(R),
//                                                                                     00546cf9(R), 00546d6d(R), 00546d8b(R), 00546dfd(R),
//                                                                                     00546e1a(*)
//              long              Stack[0x8]:4   param_2                   XREF[9]:     00546be1(R), 00546c52(R), 00546c68(R), 00546cdb(R),
//                                                                                     00546cf5(R), 00546d71(R), 00546d87(R), 00546df9(R),
//                                                                                     00546e16(*)
//              uchar             Stack[0xc]:1   param_3                   XREF[4]:     00546c3e(R), 00546ccb(R), 00546d5d(R), 00546de9(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00546bba(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00546bd9(W), 00546d92(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00546bd5(W), 00546d00(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[6]:     00546bbe(W), 00546c5d(*), 00546cea(*), 00546d7c(*),
//                                                                                     00546e08(*), 00546e24(*)
//              Zone_Queue *      Stack[-0x10]:4 zone_queue                XREF[6]:     00546bc2(W), 00546c58(*), 00546ce5(*), 00546d77(*),
//                                                                                     00546e03(*), 00546e1f(*)
//              Zone_Queue *      Stack[-0x14]:4 zone_end
//                               ?do_zone_map_area@RGE_Zone_Map@@AAEXJJEE@Z                   XREF[1]:     do_zone_map:00546b6f(c)
//                               RGE_Zone_Map::do_zone_map_area
//                              zone_map.cpp:213 (8)
//         00546bb0     SUB        ESP,0x10
//         00546bb3     PUSH       EBX
//         00546bb4     PUSH       EBP
//         00546bb5     PUSH       ESI
//         00546bb6     MOV        ESI,this
//                              zone_map.cpp:215 (2)
//         00546bb8     XOR        EAX,EAX
//                              zone_map.cpp:255 (123)
//         00546bba     MOV        BL,byte ptr [ESP + param_4]
//         00546bbe     MOV        dword ptr [ESP + local_c],EAX
//         00546bc2     MOV        dword ptr [ESP + zone_queue],EAX
//         00546bc6     MOV        EAX,dword ptr [ESI + 0x518]
//         00546bcc     PUSH       EDI
//         00546bcd     MOV        this,dword ptr [EAX + 0x8]
//         00546bd0     MOV        EAX,dword ptr [EAX + 0xc]
//         00546bd3     DEC        this
//         00546bd4     DEC        EAX
//         00546bd5     MOV        dword ptr [ESP + local_8],this
//         00546bd9     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_00546bdd                                                 XREF[1]:     00546e34(j)
//         00546bdd     MOV        this,dword ptr [ESP + param_1]
//         00546be1     MOV        EDX,dword ptr [ESP + param_2]
//         00546be5     TEST       this,this
//         00546be7     JLE        LAB_00546c73
//         00546bed     MOV        EAX,dword ptr [ESI + 0x518]
//         00546bf3     LEA        EDI,[ECX + ECX*0x2]
//         00546bf6     MOV        EAX,dword ptr [EAX + 0x8d8c]
//         00546bfc     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00546bff     LEA        EBP,[EAX + EDI*0x8 + -0x18]
//         00546c03     MOV        EAX,dword ptr [ESI + 0x408]
//         00546c09     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00546c0c     LEA        EDI,[EAX + this->numberTilesInZoneValue[0]*0x1
//         00546c10     MOV        AL,byte ptr [EAX + this->numberTilesInZoneValu
//         00546c14     CMP        AL,0xff
//         00546c16     JNZ        LAB_00546c73
//         00546c18     MOV        AL,byte ptr [EBP + 0x5]
//         00546c1b     MOV        EBP,dword ptr [ESI + 0x510]
//         00546c21     AND        EAX,0x1f
//         00546c24     FLD        float ptr [EBP + EAX*0x4]
//         00546c28     FCOMP      double ptr [DAT_00577a20]
//         00546c2e     FNSTSW     AX
//         00546c30     TEST       AH,0x41
//         00546c33     JNZ        LAB_00546c3c
//                              zone_map.cpp:226 (23)
//         00546c35     MOV        EAX,0x1
//         00546c3a     JMP        LAB_00546c3e
//                               LAB_00546c3c                                                 XREF[1]:     00546c33(j)
//         00546c3c     XOR        EAX,EAX
//                               LAB_00546c3e                                                 XREF[1]:     00546c3a(j)
//         00546c3e     MOV        EBP,dword ptr [ESP + param_3]
//         00546c42     AND        EBP,0xff
//         00546c48     CMP        EAX,EBP
//         00546c4a     JNZ        LAB_00546c73
//                              zone_map.cpp:228 (2)
//         00546c4c     MOV        byte ptr [EDI],BL
//                              zone_map.cpp:229 (37)
//         00546c4e     MOV        EDX,dword ptr [ESP + param_1]
//         00546c52     MOV        this,dword ptr [ESP + param_2]
//         00546c56     DEC        EDX
//         00546c57     PUSH       this
//         00546c58     LEA        EAX=>zone_queue,[ESP + 0x14]
//         00546c5c     PUSH       EDX
//         00546c5d     LEA        this=>local_c,[ESP + 0x1c]
//         00546c61     PUSH       EAX
//         00546c62     PUSH       this
//         00546c63     CALL       zone_push                                        void zone_push(Zone_Queue * * param_1, Zone_Q
//         00546c68     MOV        EDX,dword ptr [ESP + param_2]
//         00546c6c     MOV        this,dword ptr [ESP + param_1]
//         00546c70     ADD        ESP,0x10
//                               LAB_00546c73                                                 XREF[3]:     00546be7(j), 00546c16(j),
//                                                                                                         00546c4a(j)
//                              zone_map.cpp:233 (8)
//         00546c73     TEST       EDX,EDX
//         00546c75     JLE        LAB_00546d00
//                              zone_map.cpp:235 (22)
//         00546c7b     MOV        EAX,dword ptr [ESI + 0x518]
//         00546c81     LEA        EDI,[ECX + ECX*0x2]
//         00546c84     MOV        EAX,dword ptr [EAX + 0x8d8c]
//         00546c8a     MOV        EAX,dword ptr [EAX + EDX*0x4 + -0x4]
//         00546c8e     LEA        EBP,[EAX + EDI*0x8]
//                              zone_map.cpp:237 (72)
//         00546c91     MOV        EAX,dword ptr [ESI + 0x408]
//         00546c97     MOV        EAX,dword ptr [EAX + EDX*0x4 + -0x4]
//         00546c9b     LEA        EDI,[EAX + this->numberTilesInZoneValue[0]*0x1]
//         00546c9e     MOV        AL,byte ptr [EAX + this->numberTilesInZoneValu
//         00546ca1     CMP        AL,0xff
//         00546ca3     JNZ        LAB_00546d00
//         00546ca5     MOV        AL,byte ptr [EBP + 0x5]
//         00546ca8     MOV        EBP,dword ptr [ESI + 0x510]
//         00546cae     AND        EAX,0x1f
//         00546cb1     FLD        float ptr [EBP + EAX*0x4]
//         00546cb5     FCOMP      double ptr [DAT_00577a20]
//         00546cbb     FNSTSW     AX
//         00546cbd     TEST       AH,0x41
//         00546cc0     JNZ        LAB_00546cc9
//         00546cc2     MOV        EAX,0x1
//         00546cc7     JMP        LAB_00546ccb
//                               LAB_00546cc9                                                 XREF[1]:     00546cc0(j)
//         00546cc9     XOR        EAX,EAX
//                               LAB_00546ccb                                                 XREF[1]:     00546cc7(j)
//         00546ccb     MOV        EBP,dword ptr [ESP + param_3]
//         00546ccf     AND        EBP,0xff
//         00546cd5     CMP        EAX,EBP
//         00546cd7     JNZ        LAB_00546d00
//                              zone_map.cpp:239 (2)
//         00546cd9     MOV        byte ptr [EDI],BL
//                              zone_map.cpp:240 (37)
//         00546cdb     MOV        this,dword ptr [ESP + param_2]
//         00546cdf     MOV        EDX,dword ptr [ESP + param_1]
//         00546ce3     DEC        this
//         00546ce4     PUSH       this
//         00546ce5     LEA        EAX=>zone_queue,[ESP + 0x14]
//         00546ce9     PUSH       EDX
//         00546cea     LEA        this=>local_c,[ESP + 0x1c]
//         00546cee     PUSH       EAX
//         00546cef     PUSH       this
//         00546cf0     CALL       zone_push                                        void zone_push(Zone_Queue * * param_1, Zone_Q
//         00546cf5     MOV        EDX,dword ptr [ESP + param_2]
//         00546cf9     MOV        this,dword ptr [ESP + param_1]
//         00546cfd     ADD        ESP,0x10
//                               LAB_00546d00                                                 XREF[3]:     00546c75(j), 00546ca3(j),
//                                                                                                         00546cd7(j)
//                              zone_map.cpp:244 (10)
//         00546d00     CMP        this,dword ptr [ESP + local_8]
//         00546d04     JGE        LAB_00546d92
//                              zone_map.cpp:246 (24)
//         00546d0a     MOV        EAX,dword ptr [ESI + 0x518]
//         00546d10     MOV        EDI,dword ptr [EAX + 0x8d8c]
//         00546d16     LEA        EAX,[ECX + this+0x1]
//         00546d19     MOV        EDI,dword ptr [EDI + EDX*0x4]
//         00546d1c     LEA        EAX,[EAX + EAX*0x2]
//         00546d1f     LEA        EBP,[EDI + EAX*0x8]
//                              zone_map.cpp:248 (73)
//         00546d22     MOV        EAX,dword ptr [ESI + 0x408]
//         00546d28     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00546d2b     LEA        EDI,[EAX + this->numberTilesInZoneValue[0]*0x1
//         00546d2f     MOV        AL,byte ptr [EAX + this->numberTilesInZoneValu
//         00546d33     CMP        AL,0xff
//         00546d35     JNZ        LAB_00546d92
//         00546d37     MOV        AL,byte ptr [EBP + 0x5]
//         00546d3a     MOV        EBP,dword ptr [ESI + 0x510]
//         00546d40     AND        EAX,0x1f
//         00546d43     FLD        float ptr [EBP + EAX*0x4]
//         00546d47     FCOMP      double ptr [DAT_00577a20]
//         00546d4d     FNSTSW     AX
//         00546d4f     TEST       AH,0x41
//         00546d52     JNZ        LAB_00546d5b
//         00546d54     MOV        EAX,0x1
//         00546d59     JMP        LAB_00546d5d
//                               LAB_00546d5b                                                 XREF[1]:     00546d52(j)
//         00546d5b     XOR        EAX,EAX
//                               LAB_00546d5d                                                 XREF[1]:     00546d59(j)
//         00546d5d     MOV        EBP,dword ptr [ESP + param_3]
//         00546d61     AND        EBP,0xff
//         00546d67     CMP        EAX,EBP
//         00546d69     JNZ        LAB_00546d92
//                              zone_map.cpp:250 (2)
//         00546d6b     MOV        byte ptr [EDI],BL
//                              zone_map.cpp:251 (37)
//         00546d6d     MOV        EDX,dword ptr [ESP + param_1]
//         00546d71     MOV        this,dword ptr [ESP + param_2]
//         00546d75     INC        EDX
//         00546d76     PUSH       this
//         00546d77     LEA        EAX=>zone_queue,[ESP + 0x14]
//         00546d7b     PUSH       EDX
//         00546d7c     LEA        this=>local_c,[ESP + 0x1c]
//         00546d80     PUSH       EAX
//         00546d81     PUSH       this
//         00546d82     CALL       zone_push                                        void zone_push(Zone_Queue * * param_1, Zone_Q
//         00546d87     MOV        EDX,dword ptr [ESP + param_2]
//         00546d8b     MOV        this,dword ptr [ESP + param_1]
//         00546d8f     ADD        ESP,0x10
//                               LAB_00546d92                                                 XREF[3]:     00546d04(j), 00546d35(j),
//                                                                                                         00546d69(j)
//                              zone_map.cpp:255 (6)
//         00546d92     CMP        EDX,dword ptr [ESP + local_4]
//         00546d96     JGE        LAB_00546e16
//                              zone_map.cpp:257 (28)
//         00546d98     LEA        EAX,[EDX*0x4 + 0x4]
//         00546d9f     MOV        EDX,dword ptr [ESI + 0x518]
//         00546da5     LEA        EDI,[ECX + ECX*0x2]
//         00546da8     MOV        EDX,dword ptr [EDX + 0x8d8c]
//         00546dae     MOV        EDX,dword ptr [EDX + EAX*0x1]
//         00546db1     LEA        EDX,[EDX + EDI*0x8]
//                              zone_map.cpp:259 (67)
//         00546db4     MOV        EDI,dword ptr [ESI + 0x408]
//         00546dba     MOV        EAX,dword ptr [EDI + EAX*0x1]
//         00546dbd     ADD        this,EAX
//         00546dbf     CMP        byte ptr [this->numberTilesInZoneValue[0]],0xff
//         00546dc2     JNZ        LAB_00546e16
//         00546dc4     MOV        DL,byte ptr [EDX + 0x5]
//         00546dc7     MOV        EAX,dword ptr [ESI + 0x510]
//         00546dcd     AND        EDX,0x1f
//         00546dd0     FLD        float ptr [EAX + EDX*0x4]
//         00546dd3     FCOMP      double ptr [DAT_00577a20]
//         00546dd9     FNSTSW     AX
//         00546ddb     TEST       AH,0x41
//         00546dde     JNZ        LAB_00546de7
//         00546de0     MOV        EAX,0x1
//         00546de5     JMP        LAB_00546de9
//                               LAB_00546de7                                                 XREF[1]:     00546dde(j)
//         00546de7     XOR        EAX,EAX
//                               LAB_00546de9                                                 XREF[1]:     00546de5(j)
//         00546de9     MOV        EDX,dword ptr [ESP + param_3]
//         00546ded     AND        EDX,0xff
//         00546df3     CMP        EAX,EDX
//         00546df5     JNZ        LAB_00546e16
//                              zone_map.cpp:261 (2)
//         00546df7     MOV        byte ptr [this->numberTilesInZoneValue[0]],BL
//                              zone_map.cpp:262 (29)
//         00546df9     MOV        EAX,dword ptr [ESP + param_2]
//         00546dfd     MOV        this,dword ptr [ESP + param_1]
//         00546e01     INC        EAX
//         00546e02     PUSH       EAX
//         00546e03     LEA        EDX=>zone_queue,[ESP + 0x14]
//         00546e07     PUSH       this
//         00546e08     LEA        EAX=>local_c,[ESP + 0x1c]
//         00546e0c     PUSH       EDX
//         00546e0d     PUSH       EAX
//         00546e0e     CALL       zone_push                                        void zone_push(Zone_Queue * * param_1, Zone_Q
//         00546e13     ADD        ESP,0x10
//                               LAB_00546e16                                                 XREF[3]:     00546d96(j), 00546dc2(j),
//                                                                                                         00546df5(j)
//                              zone_map.cpp:266 (36)
//         00546e16     LEA        this=>param_2,[ESP + 0x28]
//         00546e1a     LEA        EDX=>param_1,[ESP + 0x24]
//         00546e1e     PUSH       this
//         00546e1f     LEA        EAX=>zone_queue,[ESP + 0x14]
//         00546e23     PUSH       EDX
//         00546e24     LEA        this=>local_c,[ESP + 0x1c]
//         00546e28     PUSH       EAX
//         00546e29     PUSH       this
//         00546e2a     CALL       zone_pop                                         uchar zone_pop(Zone_Queue * * param_1, Zone_Q
//         00546e2f     ADD        ESP,0x10
//         00546e32     TEST       AL,AL
//         00546e34     JNZ        LAB_00546bdd
//                              zone_map.cpp:267 (10)
//         00546e3a     POP        EDI
//         00546e3b     POP        ESI
//         00546e3c     POP        EBP
//         00546e3d     POP        EBX
//         00546e3e     ADD        ESP,0x10
//         00546e41     RET        0x10
//         00546e44     ??         90h
//         00546e45     NOP
//         00546e46     NOP
//         00546e47     NOP
//         00546e48     NOP
//         00546e49     NOP
//         00546e4a     NOP
//         00546e4b     NOP
//         00546e4c     NOP
//         00546e4d     NOP
//         00546e4e     NOP
//         00546e4f     NOP
    return;
}

RGE_Zone_Map* RGE_Zone_Map::check_info(float* param_1, long param_2) {
    /* TODO: Stub */
//                              RGE_Zone_Map * __thiscall check_info(RGE_Zone_Map * this, float * pa
//              RGE_Zone_Map *    EAX:4          <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[1]:     00546e66(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00546e50(R)
//                               ?check_info@RGE_Zone_Map@@QAEPAV1@PAMJ@Z                     XREF[2]:     create_zone_map:005472e3(c),
//                               RGE_Zone_Map::check_info                                                  get_zone_map:005473e4(c)
//                              zone_map.cpp:272 (16)
//         00546e50     MOV        EAX,dword ptr [ESP + param_2]
//         00546e54     PUSH       ESI
//         00546e55     MOV        ESI,dword ptr [ECX + this->terrain_passability
//         00546e5b     PUSH       EDI
//         00546e5c     CMP        EAX,ESI
//         00546e5e     JNZ        LAB_00546ea3
//                              zone_map.cpp:277 (10)
//         00546e60     XOR        EDX,EDX
//         00546e62     TEST       ESI,ESI
//         00546e64     JLE        LAB_00546e9c
//         00546e66     MOV        EDI,dword ptr [ESP + param_1]
//                               LAB_00546e6a                                                 XREF[1]:     00546e9a(j)
//                              zone_map.cpp:279 (14)
//         00546e6a     FLD        float ptr [EDI + EDX*0x4]
//         00546e6d     FCOMP      double ptr [DAT_00577a20]
//         00546e73     FNSTSW     AX
//         00546e75     TEST       AH,0x41
//                              zone_map.cpp:281 (24)
//         00546e78     MOV        EAX,dword ptr [ECX + this->terrain_passability
//         00546e7e     FLD        float ptr [EAX + EDX*0x4]
//         00546e81     FCOMP      double ptr [DAT_00577a20]
//         00546e87     FNSTSW     AX
//         00546e89     JZ         LAB_00546e92
//         00546e8b     TEST       AH,0x41
//         00546e8e     JZ         LAB_00546ea3
//                              zone_map.cpp:284 (2)
//         00546e90     JMP        LAB_00546e97
//                               LAB_00546e92                                                 XREF[1]:     00546e89(j)
//                              zone_map.cpp:286 (5)
//         00546e92     TEST       AH,0x41
//         00546e95     JNZ        LAB_00546ea3
//                               LAB_00546e97                                                 XREF[1]:     00546e90(j)
//                              zone_map.cpp:277 (5)
//         00546e97     INC        EDX
//         00546e98     CMP        EDX,ESI
//         00546e9a     JL         LAB_00546e6a
//                               LAB_00546e9c                                                 XREF[1]:     00546e64(j)
//                              zone_map.cpp:290 (2)
//         00546e9c     MOV        EAX,this
//                              zone_map.cpp:294 (12)
//         00546e9e     POP        EDI
//         00546e9f     POP        ESI
//         00546ea0     RET        0x8
//                               LAB_00546ea3                                                 XREF[3]:     00546e5e(j), 00546e8e(j),
//                                                                                                         00546e95(j)
//         00546ea3     POP        EDI
//         00546ea4     XOR        EAX,EAX
//         00546ea6     POP        ESI
//         00546ea7     RET        0x8
//         00546eaa     ??         90h
//         00546eab     NOP
//         00546eac     NOP
//         00546ead     NOP
//         00546eae     NOP
//         00546eaf     NOP
    return 0;
}

uchar RGE_Zone_Map::get_zone_info(long param_1, long param_2) {
    /* TODO: Stub */
//                              uchar __thiscall get_zone_info(RGE_Zone_Map * this, long param_1, lo
//              uchar             AL:1           <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00546ebd(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00546eb6(R)
//                               ?get_zone_info@RGE_Zone_Map@@QAEEJJ@Z                        XREF[20]:    canPath:0045f8b8(c),
//                               RGE_Zone_Map::get_zone_info                                               canPath:0045f8ca(c),
//                                                                                                         canPath:0045fa67(c),
//                                                                                                         canPath:0045fa87(c),
//                                                                                                         canBidirectionPath:0045fc6a(c),
//                                                                                                         canBidirectionPath:0045fc8c(c),
//                                                                                                         canPathWithObstructions:0045ff67(c
//                                                                                                         canPathWithObstructions:0045ff87(c
//                                                                                                         findAvoidancePath:00460c66(c),
//                                                                                                         findAvoidancePath:00460c7f(c),
//                                                                                                         place_land_objects:0048683a(c),
//                                                                                                         place_land_objects:00486887(c),
//                                                                                                         base_terrain_generate:0048907d(c),
//                                                                                                         base_terrain_generate:00489269(c),
//                                                                                                         base_terrain_generate:0048936c(c),
//                                                                                                         lookupZone:004c7494(c),
//                                                                                                         lookupZone:004c7514(c),
//                                                                                                         currentZone:004c7598(c),
//                                                                                                         placeDock:004d9c75(c),
//                                                                                                         numberDocksInZone:004d9f7e(c)
//                              zone_map.cpp:299 (20)
//         00546eb0     MOV        EAX,dword ptr [ECX + this->zone_map_rows]
//         00546eb6     MOV        this,dword ptr [ESP + param_2]
//         00546eba     MOV        EDX,dword ptr [EAX + this->numberTilesInZoneVa
//         00546ebd     MOV        EAX,dword ptr [ESP + param_1]
//         00546ec1     MOV        AL,byte ptr [EDX + EAX*0x1]
//                              zone_map.cpp:301 (3)
//         00546ec4     RET        0x8
//         00546ec7     ??         90h
//         00546ec8     NOP
//         00546ec9     NOP
//         00546eca     NOP
//         00546ecb     NOP
//         00546ecc     NOP
//         00546ecd     NOP
//         00546ece     NOP
//         00546ecf     NOP
    return 0;
}

int RGE_Zone_Map::withinRange(XYPoint param_1, XYPoint param_2, float param_3) {
    /* TODO: Stub */
//                              int __thiscall withinRange(RGE_Zone_Map * this, uchar param_1, XYPoi
//              int               EAX:4          <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00546fa2(R)
//              XYPoint           Stack[0x8]:8   param_2                   XREF[1,2]:   00546f16(R), 00546f1a(R), 00546f79(R)
//              float             Stack[0x10]:4  param_3                   XREF[2]:     00546f03(R), 00546f93(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00546f45(W), 00546f5f(W), 00546fb4(R)
//              XYPoint           Stack[-0xc]:8  max                       XREF[2,5]:   00546f0d(W), 00546f9e(R), 00546f3d(W), 00546f41(R),
//                                                                                     00546f51(W), 00546f63(R), 00546fc2(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00546f89(W), 00546f8d(R)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00546f6f(W), 00546fbe(R), 00546fca(W)
//                               ?withinRange@RGE_Zone_Map@@QAEHEUXYPoint@@M@Z                XREF[3]:     withinRangeOfZoneAtPoint:004c7615(
//                               RGE_Zone_Map::withinRange                                                 withinRangeOfZone:004c76a4(c),
//                                                                                                         withinRange:00546ef4(c)
//                              zone_map.cpp:318 (3)
//         00546f00     SUB        ESP,0x14
//                              zone_map.cpp:328 (23)
//         00546f03     FLD        float ptr [ESP + param_3]
//         00546f07     PUSH       EBX
//         00546f08     PUSH       EBP
//         00546f09     PUSH       ESI
//         00546f0a     PUSH       EDI
//         00546f0b     MOV        EDI,this
//         00546f0d     MOV        dword ptr [ESP + max.x],EDI
//         00546f11     CALL       __ftol                                           undefined __ftol()
//         00546f16     MOV        ESI,dword ptr [ESP + param_2.x]
//                              zone_map.cpp:329 (12)
//         00546f1a     MOV        EBX,dword ptr [ESP + param_2.y]
//         00546f1e     MOV        this,ESI
//         00546f20     MOV        EBP,EBX
//         00546f22     SUB        this,EAX
//         00546f24     SUB        EBP,EAX
//                              zone_map.cpp:330 (4)
//         00546f26     TEST       this,this
//         00546f28     JGE        LAB_00546f2c
//                              zone_map.cpp:331 (2)
//         00546f2a     XOR        this,this
//                               LAB_00546f2c                                                 XREF[1]:     00546f28(j)
//                              zone_map.cpp:332 (4)
//         00546f2c     TEST       EBP,EBP
//         00546f2e     JGE        LAB_00546f32
//                              zone_map.cpp:333 (2)
//         00546f30     XOR        EBP,EBP
//                               LAB_00546f32                                                 XREF[1]:     00546f2e(j)
//                              zone_map.cpp:335 (3)
//         00546f32     LEA        EDX,[ESI + EAX*0x1]
//                              zone_map.cpp:336 (2)
//         00546f35     ADD        EBX,EAX
//                              zone_map.cpp:337 (26)
//         00546f37     MOV        EAX,dword ptr [EDI + 0x518]
//         00546f3d     MOV        dword ptr [ESP + max.y],EDX
//         00546f41     MOV        EDI,dword ptr [ESP + max.y]
//         00546f45     MOV        dword ptr [ESP + local_4],EBX
//         00546f49     MOV        EDX,dword ptr [EAX + 0x8]
//         00546f4c     DEC        EDX
//         00546f4d     CMP        EDI,EDX
//         00546f4f     JLE        LAB_00546f55
//                              zone_map.cpp:338 (4)
//         00546f51     MOV        dword ptr [ESP + max.y],EDX
//                               LAB_00546f55                                                 XREF[1]:     00546f4f(j)
//                              zone_map.cpp:339 (8)
//         00546f55     MOV        EAX,dword ptr [EAX + 0xc]
//         00546f58     DEC        EAX
//         00546f59     CMP        EBX,EAX
//         00546f5b     JLE        LAB_00546f63
//                              zone_map.cpp:340 (6)
//         00546f5d     MOV        EBX,EAX
//         00546f5f     MOV        dword ptr [ESP + local_4],EBX
//                               LAB_00546f63                                                 XREF[1]:     00546f5b(j)
//                              zone_map.cpp:342 (16)
//         00546f63     MOV        EAX,dword ptr [ESP + max.y]
//         00546f67     MOV        EDI,this
//         00546f69     CMP        this,EAX
//         00546f6b     JG         LAB_00546feb
//         00546f6d     SUB        ESI,this
//         00546f6f     MOV        dword ptr [ESP + local_14],ESI
//                               LAB_00546f73                                                 XREF[1]:     00546fce(j)
//                              zone_map.cpp:343 (10)
//         00546f73     CMP        EBP,EBX
//         00546f75     MOV        EDX,EBP
//         00546f77     JG         LAB_00546fc2
//         00546f79     MOV        this,dword ptr [ESP + param_2.y]
//                              zone_map.cpp:348 (33)
//         00546f7d     IMUL       ESI,ESI
//         00546f80     SUB        this,EBP
//                               LAB_00546f82                                                 XREF[1]:     00546fbc(j)
//         00546f82     MOV        EAX,this
//         00546f84     IMUL       EAX,this
//         00546f87     ADD        EAX,ESI
//         00546f89     MOV        dword ptr [ESP + local_10],EAX
//         00546f8d     FILD       dword ptr [ESP + local_10]
//         00546f91     FSQRT
//         00546f93     FCOMP      float ptr [ESP + param_3]
//         00546f97     FNSTSW     AX
//         00546f99     TEST       AH,0x41
//         00546f9c     JZ         LAB_00546fb8
//                              zone_map.cpp:354 (26)
//         00546f9e     MOV        EAX,dword ptr [ESP + max.x]
//         00546fa2     MOV        BL,byte ptr [ESP + param_1]
//         00546fa6     MOV        EAX,dword ptr [EAX + 0x408]
//         00546fac     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00546faf     CMP        byte ptr [EAX + EDI*0x1],BL
//         00546fb2     JZ         LAB_00546fdc
//         00546fb4     MOV        EBX,dword ptr [ESP + local_4]
//                               LAB_00546fb8                                                 XREF[1]:     00546f9c(j)
//                              zone_map.cpp:343 (10)
//         00546fb8     INC        EDX
//         00546fb9     DEC        this
//         00546fba     CMP        EDX,EBX
//         00546fbc     JLE        LAB_00546f82
//         00546fbe     MOV        ESI,dword ptr [ESP + local_14]
//                               LAB_00546fc2                                                 XREF[1]:     00546f77(j)
//                              zone_map.cpp:342 (14)
//         00546fc2     MOV        EAX,dword ptr [ESP + max.y]
//         00546fc6     INC        EDI
//         00546fc7     DEC        ESI
//         00546fc8     CMP        EDI,EAX
//         00546fca     MOV        dword ptr [ESP + local_14],ESI
//         00546fce     JLE        LAB_00546f73
//                              zone_map.cpp:359 (2)
//         00546fd0     XOR        EAX,EAX
//                              zone_map.cpp:360 (10)
//         00546fd2     POP        EDI
//         00546fd3     POP        ESI
//         00546fd4     POP        EBP
//         00546fd5     POP        EBX
//         00546fd6     ADD        ESP,0x14
//         00546fd9     RET        0x10
//                               LAB_00546fdc                                                 XREF[1]:     00546fb2(j)
//                              zone_map.cpp:355 (5)
//         00546fdc     MOV        EAX,0x1
//                              zone_map.cpp:360 (22)
//         00546fe1     POP        EDI
//         00546fe2     POP        ESI
//         00546fe3     POP        EBP
//         00546fe4     POP        EBX
//         00546fe5     ADD        ESP,0x14
//         00546fe8     RET        0x10
//                               LAB_00546feb                                                 XREF[1]:     00546f6b(j)
//         00546feb     POP        EDI
//         00546fec     POP        ESI
//         00546fed     POP        EBP
//         00546fee     XOR        EAX,EAX
//         00546ff0     POP        EBX
//         00546ff1     ADD        ESP,0x14
//         00546ff4     RET        0x10
//         00546ff7     ??         90h
//         00546ff8     NOP
//         00546ff9     NOP
//         00546ffa     NOP
//         00546ffb     NOP
//         00546ffc     NOP
//         00546ffd     NOP
//         00546ffe     NOP
//         00546fff     NOP
    return 0;
}

int RGE_Zone_Map::withinRange(uchar param_1, XYPoint param_2, float param_3) {
    /* TODO: Stub */
//                              int __thiscall withinRange(RGE_Zone_Map * this, uchar param_1, XYPoi
//              int               EAX:4          <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00546fa2(R)
//              XYPoint           Stack[0x8]:8   param_2                   XREF[1,2]:   00546f16(R), 00546f1a(R), 00546f79(R)
//              float             Stack[0x10]:4  param_3                   XREF[2]:     00546f03(R), 00546f93(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00546f45(W), 00546f5f(W), 00546fb4(R)
//              XYPoint           Stack[-0xc]:8  max                       XREF[2,5]:   00546f0d(W), 00546f9e(R), 00546f3d(W), 00546f41(R),
//                                                                                     00546f51(W), 00546f63(R), 00546fc2(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00546f89(W), 00546f8d(R)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00546f6f(W), 00546fbe(R), 00546fca(W)
//                               ?withinRange@RGE_Zone_Map@@QAEHEUXYPoint@@M@Z                XREF[3]:     withinRangeOfZoneAtPoint:004c7615(
//                               RGE_Zone_Map::withinRange                                                 withinRangeOfZone:004c76a4(c),
//                                                                                                         withinRange:00546ef4(c)
//                              zone_map.cpp:318 (3)
//         00546f00     SUB        ESP,0x14
//                              zone_map.cpp:328 (23)
//         00546f03     FLD        float ptr [ESP + param_3]
//         00546f07     PUSH       EBX
//         00546f08     PUSH       EBP
//         00546f09     PUSH       ESI
//         00546f0a     PUSH       EDI
//         00546f0b     MOV        EDI,this
//         00546f0d     MOV        dword ptr [ESP + max.x],EDI
//         00546f11     CALL       __ftol                                           undefined __ftol()
//         00546f16     MOV        ESI,dword ptr [ESP + param_2.x]
//                              zone_map.cpp:329 (12)
//         00546f1a     MOV        EBX,dword ptr [ESP + param_2.y]
//         00546f1e     MOV        this,ESI
//         00546f20     MOV        EBP,EBX
//         00546f22     SUB        this,EAX
//         00546f24     SUB        EBP,EAX
//                              zone_map.cpp:330 (4)
//         00546f26     TEST       this,this
//         00546f28     JGE        LAB_00546f2c
//                              zone_map.cpp:331 (2)
//         00546f2a     XOR        this,this
//                               LAB_00546f2c                                                 XREF[1]:     00546f28(j)
//                              zone_map.cpp:332 (4)
//         00546f2c     TEST       EBP,EBP
//         00546f2e     JGE        LAB_00546f32
//                              zone_map.cpp:333 (2)
//         00546f30     XOR        EBP,EBP
//                               LAB_00546f32                                                 XREF[1]:     00546f2e(j)
//                              zone_map.cpp:335 (3)
//         00546f32     LEA        EDX,[ESI + EAX*0x1]
//                              zone_map.cpp:336 (2)
//         00546f35     ADD        EBX,EAX
//                              zone_map.cpp:337 (26)
//         00546f37     MOV        EAX,dword ptr [EDI + 0x518]
//         00546f3d     MOV        dword ptr [ESP + max.y],EDX
//         00546f41     MOV        EDI,dword ptr [ESP + max.y]
//         00546f45     MOV        dword ptr [ESP + local_4],EBX
//         00546f49     MOV        EDX,dword ptr [EAX + 0x8]
//         00546f4c     DEC        EDX
//         00546f4d     CMP        EDI,EDX
//         00546f4f     JLE        LAB_00546f55
//                              zone_map.cpp:338 (4)
//         00546f51     MOV        dword ptr [ESP + max.y],EDX
//                               LAB_00546f55                                                 XREF[1]:     00546f4f(j)
//                              zone_map.cpp:339 (8)
//         00546f55     MOV        EAX,dword ptr [EAX + 0xc]
//         00546f58     DEC        EAX
//         00546f59     CMP        EBX,EAX
//         00546f5b     JLE        LAB_00546f63
//                              zone_map.cpp:340 (6)
//         00546f5d     MOV        EBX,EAX
//         00546f5f     MOV        dword ptr [ESP + local_4],EBX
//                               LAB_00546f63                                                 XREF[1]:     00546f5b(j)
//                              zone_map.cpp:342 (16)
//         00546f63     MOV        EAX,dword ptr [ESP + max.y]
//         00546f67     MOV        EDI,this
//         00546f69     CMP        this,EAX
//         00546f6b     JG         LAB_00546feb
//         00546f6d     SUB        ESI,this
//         00546f6f     MOV        dword ptr [ESP + local_14],ESI
//                               LAB_00546f73                                                 XREF[1]:     00546fce(j)
//                              zone_map.cpp:343 (10)
//         00546f73     CMP        EBP,EBX
//         00546f75     MOV        EDX,EBP
//         00546f77     JG         LAB_00546fc2
//         00546f79     MOV        this,dword ptr [ESP + param_2.y]
//                              zone_map.cpp:348 (33)
//         00546f7d     IMUL       ESI,ESI
//         00546f80     SUB        this,EBP
//                               LAB_00546f82                                                 XREF[1]:     00546fbc(j)
//         00546f82     MOV        EAX,this
//         00546f84     IMUL       EAX,this
//         00546f87     ADD        EAX,ESI
//         00546f89     MOV        dword ptr [ESP + local_10],EAX
//         00546f8d     FILD       dword ptr [ESP + local_10]
//         00546f91     FSQRT
//         00546f93     FCOMP      float ptr [ESP + param_3]
//         00546f97     FNSTSW     AX
//         00546f99     TEST       AH,0x41
//         00546f9c     JZ         LAB_00546fb8
//                              zone_map.cpp:354 (26)
//         00546f9e     MOV        EAX,dword ptr [ESP + max.x]
//         00546fa2     MOV        BL,byte ptr [ESP + param_1]
//         00546fa6     MOV        EAX,dword ptr [EAX + 0x408]
//         00546fac     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00546faf     CMP        byte ptr [EAX + EDI*0x1],BL
//         00546fb2     JZ         LAB_00546fdc
//         00546fb4     MOV        EBX,dword ptr [ESP + local_4]
//                               LAB_00546fb8                                                 XREF[1]:     00546f9c(j)
//                              zone_map.cpp:343 (10)
//         00546fb8     INC        EDX
//         00546fb9     DEC        this
//         00546fba     CMP        EDX,EBX
//         00546fbc     JLE        LAB_00546f82
//         00546fbe     MOV        ESI,dword ptr [ESP + local_14]
//                               LAB_00546fc2                                                 XREF[1]:     00546f77(j)
//                              zone_map.cpp:342 (14)
//         00546fc2     MOV        EAX,dword ptr [ESP + max.y]
//         00546fc6     INC        EDI
//         00546fc7     DEC        ESI
//         00546fc8     CMP        EDI,EAX
//         00546fca     MOV        dword ptr [ESP + local_14],ESI
//         00546fce     JLE        LAB_00546f73
//                              zone_map.cpp:359 (2)
//         00546fd0     XOR        EAX,EAX
//                              zone_map.cpp:360 (10)
//         00546fd2     POP        EDI
//         00546fd3     POP        ESI
//         00546fd4     POP        EBP
//         00546fd5     POP        EBX
//         00546fd6     ADD        ESP,0x14
//         00546fd9     RET        0x10
//                               LAB_00546fdc                                                 XREF[1]:     00546fb2(j)
//                              zone_map.cpp:355 (5)
//         00546fdc     MOV        EAX,0x1
//                              zone_map.cpp:360 (22)
//         00546fe1     POP        EDI
//         00546fe2     POP        ESI
//         00546fe3     POP        EBP
//         00546fe4     POP        EBX
//         00546fe5     ADD        ESP,0x14
//         00546fe8     RET        0x10
//                               LAB_00546feb                                                 XREF[1]:     00546f6b(j)
//         00546feb     POP        EDI
//         00546fec     POP        ESI
//         00546fed     POP        EBP
//         00546fee     XOR        EAX,EAX
//         00546ff0     POP        EBX
//         00546ff1     ADD        ESP,0x14
//         00546ff4     RET        0x10
//         00546ff7     ??         90h
//         00546ff8     NOP
//         00546ff9     NOP
//         00546ffa     NOP
//         00546ffb     NOP
//         00546ffc     NOP
//         00546ffd     NOP
//         00546ffe     NOP
//         00546fff     NOP
    return 0;
}

int RGE_Zone_Map::numberTilesInZone(uchar param_1) {
    /* TODO: Stub */
//                              int __thiscall numberTilesInZone(RGE_Zone_Map * this, uchar param_1)
//              int               EAX:4          <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[4]:     00547004(R), 00547038(W), 00547051(RW), 00547064(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00547017(W), 00547068(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00547034(W), 0054705b(R)
//              int               Stack[-0xc]:4  mapWidth
//                               ?numberTilesInZone@RGE_Zone_Map@@QAEHE@Z                     XREF[1]:     placeDock:004d9c87(c)
//                               RGE_Zone_Map::numberTilesInZone
//                              zone_map.cpp:366 (4)
//         00547000     SUB        ESP,0x8
//         00547003     PUSH       EBX
//                              zone_map.cpp:368 (27)
//         00547004     MOV        EBX,dword ptr [ESP + param_1]
//         00547008     MOV        EAX,EBX
//         0054700a     PUSH       EBP
//         0054700b     MOV        EBP,this
//         0054700d     AND        EAX,0xff
//         00547012     PUSH       ESI
//         00547013     LEA        ESI,[EBP + EAX*0x4]
//         00547017     MOV        dword ptr [ESP + local_4],ESI
//         0054701b     MOV        EAX,dword ptr [ESI]
//         0054701d     TEST       EAX,EAX
//                              zone_map.cpp:369 (2)
//         0054701f     JG         LAB_00547071
//                              zone_map.cpp:371 (7)
//         00547021     MOV        EAX,dword ptr [EBP + 0x518]
//         00547027     PUSH       EDI
//                              zone_map.cpp:373 (2)
//         00547028     XOR        EDX,EDX
//                              zone_map.cpp:374 (20)
//         0054702a     XOR        EDI,EDI
//         0054702c     MOV        this,dword ptr [EAX + 0x8]
//         0054702f     MOV        EAX,dword ptr [EAX + 0xc]
//         00547032     TEST       this,this
//         00547034     MOV        dword ptr [ESP + local_8],this
//         00547038     MOV        dword ptr [ESP + param_1],EDX
//         0054703c     JLE        LAB_0054706c
//                               LAB_0054703e                                                 XREF[1]:     00547062(j)
//                              zone_map.cpp:376 (12)
//         0054703e     TEST       EAX,EAX
//         00547040     JLE        LAB_0054705f
//         00547042     MOV        EDX,dword ptr [EBP + 0x408]
//         00547048     MOV        ESI,EAX
//                               LAB_0054704a                                                 XREF[1]:     00547059(j)
//                              zone_map.cpp:378 (7)
//         0054704a     MOV        this,dword ptr [EDX]
//         0054704c     CMP        byte ptr [EDI + this->numberTilesInZoneValue[0
//         0054704f     JNZ        LAB_00547055
//                              zone_map.cpp:379 (10)
//         00547051     INC        dword ptr [ESP + param_1]
//                               LAB_00547055                                                 XREF[1]:     0054704f(j)
//         00547055     ADD        EDX,0x4
//         00547058     DEC        ESI
//         00547059     JNZ        LAB_0054704a
//                              zone_map.cpp:376 (4)
//         0054705b     MOV        this,dword ptr [ESP + local_8]
//                               LAB_0054705f                                                 XREF[1]:     00547040(j)
//                              zone_map.cpp:374 (13)
//         0054705f     INC        EDI
//         00547060     CMP        EDI,this
//         00547062     JL         LAB_0054703e
//         00547064     MOV        EDX,dword ptr [ESP + param_1]
//         00547068     MOV        ESI,dword ptr [ESP + local_4]
//                               LAB_0054706c                                                 XREF[1]:     0054703c(j)
//                              zone_map.cpp:382 (2)
//         0054706c     MOV        dword ptr [ESI],EDX
//                              zone_map.cpp:383 (3)
//         0054706e     MOV        EAX,EDX
//         00547070     POP        EDI
//                               LAB_00547071                                                 XREF[1]:     0054701f(j)
//                              zone_map.cpp:384 (9)
//         00547071     POP        ESI
//         00547072     POP        EBP
//         00547073     POP        EBX
//         00547074     ADD        ESP,0x8
//         00547077     RET        0x4
//         0054707a     ??         90h
//         0054707b     NOP
//         0054707c     NOP
//         0054707d     NOP
//         0054707e     NOP
//         0054707f     NOP
    return 0;
}

int RGE_Zone_Map::findClosestPointInTerrainType(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall findClosestPointInTerrainType(RGE_Zone_Map * this, XY
//              int               EAX:4          <RETURN>
//              RGE_Zone_Map *    ECX:4 (auto)   this
//              XYPoint           Stack[0x4]:8   param_1                   XREF[1,2]:   0054708f(R), 00547089(R), 005470fb(R)
//              XYPoint *         Stack[0xc]:4   param_2                   XREF[1]:     0054713e(R)
//              int               Stack[0x10]:4  param_3                   XREF[1]:     00547112(R)
//              int               Stack[0x14]:4  param_4                   XREF[1]:     0054711f(R)
//              int               Stack[0x18]:4  param_5                   XREF[5]:     00547083(R), 005470f1(W), 00547125(R), 00547159(R),
//                                                                                     00547161(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     005470a3(W), 005470af(W), 005470b7(R), 00547151(R)
//              XYPoint           Stack[-0xc]:8  min                       XREF[4]:     005470ca(W), 005470e4(W), 005470f5(R), 00547147(R)
//              XYPoint           Stack[-0x14]:8 max                       XREF[2,3]:   0054709f(W), 00547101(R), 005470c6(W), 005470d6(W),
//                                                                                     00547155(R)
//                               ?findClosestPointInTerrainType@RGE_Zone_Map@@QAEHUXYPoint@@  XREF[1]:     findClosestPointInTerrainType:004c
//                               RGE_Zone_Map::findClosestPointInTerrainType
//                              zone_map.cpp:390 (3)
//         00547080     SUB        ESP,0x14
//                              zone_map.cpp:399 (6)
//         00547083     MOV        EAX,dword ptr [ESP + param_5]
//         00547087     PUSH       EBX
//         00547088     PUSH       EBP
//                              zone_map.cpp:400 (20)
//         00547089     MOV        EBP,dword ptr [ESP + param_1.y]
//         0054708d     PUSH       ESI
//         0054708e     PUSH       EDI
//         0054708f     MOV        EDI,dword ptr [ESP + param_1.x]
//         00547093     MOV        ESI,EBP
//         00547095     MOV        EBX,EDI
//         00547097     MOV        EDX,this
//         00547099     SUB        EBX,EAX
//         0054709b     SUB        ESI,EAX
//                              zone_map.cpp:401 (12)
//         0054709d     TEST       EBX,EBX
//         0054709f     MOV        dword ptr [ESP + max.x],EDX
//         005470a3     MOV        dword ptr [ESP + local_4],ESI
//         005470a7     JGE        LAB_005470ab
//                              zone_map.cpp:402 (2)
//         005470a9     XOR        EBX,EBX
//                               LAB_005470ab                                                 XREF[1]:     005470a7(j)
//                              zone_map.cpp:403 (4)
//         005470ab     TEST       ESI,ESI
//         005470ad     JGE        LAB_005470bb
//                              zone_map.cpp:404 (12)
//         005470af     MOV        dword ptr [ESP + local_4],0x0
//         005470b7     MOV        ESI,dword ptr [ESP + local_4]
//                               LAB_005470bb                                                 XREF[1]:     005470ad(j)
//                              zone_map.cpp:406 (3)
//         005470bb     LEA        this,[EAX + EDI*0x1]
//                              zone_map.cpp:407 (2)
//         005470be     ADD        EBP,EAX
//                              zone_map.cpp:408 (22)
//         005470c0     MOV        EAX,dword ptr [EDX + 0x518]
//         005470c6     MOV        dword ptr [ESP + max.y],this
//         005470ca     MOV        dword ptr [ESP + min.x],EBP
//         005470ce     MOV        EDX,dword ptr [EAX + 0x8]
//         005470d1     DEC        EDX
//         005470d2     CMP        this,EDX
//         005470d4     JLE        LAB_005470dc
//                              zone_map.cpp:409 (6)
//         005470d6     MOV        dword ptr [ESP + max.y],EDX
//         005470da     MOV        this,EDX
//                               LAB_005470dc                                                 XREF[1]:     005470d4(j)
//                              zone_map.cpp:410 (8)
//         005470dc     MOV        EAX,dword ptr [EAX + 0xc]
//         005470df     DEC        EAX
//         005470e0     CMP        EBP,EAX
//         005470e2     JLE        LAB_005470e8
//                              zone_map.cpp:411 (4)
//         005470e4     MOV        dword ptr [ESP + min.x],EAX
//                               LAB_005470e8                                                 XREF[1]:     005470e2(j)
//                              zone_map.cpp:413 (3)
//         005470e8     OR         EBP,0xffffffff
//                              zone_map.cpp:414 (10)
//         005470eb     CMP        EBX,this
//         005470ed     JG         LAB_00547167
//         005470ef     SUB        EDI,EBX
//         005470f1     MOV        dword ptr [ESP + param_5],EDI
//                               LAB_005470f5                                                 XREF[1]:     00547165(j)
//                              zone_map.cpp:415 (12)
//         005470f5     CMP        ESI,dword ptr [ESP + min.x]
//         005470f9     JG         LAB_00547159
//         005470fb     MOV        EDI,dword ptr [ESP + param_1.y]
//         005470ff     SUB        EDI,ESI
//                               LAB_00547101                                                 XREF[1]:     0054714f(j)
//                              zone_map.cpp:417 (17)
//         00547101     MOV        EAX,dword ptr [ESP + max.x]
//         00547105     PUSH       ESI
//         00547106     PUSH       EBX
//         00547107     MOV        this,dword ptr [EAX + 0x518]
//         0054710d     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
//                              zone_map.cpp:418 (19)
//         00547112     MOV        this,dword ptr [ESP + param_3]
//         00547116     AND        EAX,0xff
//         0054711b     CMP        EAX,this
//         0054711d     JZ         LAB_00547125
//         0054711f     CMP        EAX,dword ptr [ESP + param_4]
//         00547123     JNZ        LAB_00547147
//                               LAB_00547125                                                 XREF[1]:     0054711d(j)
//                              zone_map.cpp:423 (14)
//         00547125     MOV        EAX,dword ptr [ESP + param_5]
//         00547129     MOV        this,EDI
//         0054712b     IMUL       EAX,EAX
//         0054712e     IMUL       this,EDI
//         00547131     ADD        EAX,this
//                              zone_map.cpp:425 (9)
//         00547133     CMP        EBP,-0x1
//         00547136     JZ         LAB_0054713c
//         00547138     CMP        EBP,EAX
//         0054713a     JLE        LAB_00547147
//                               LAB_0054713c                                                 XREF[1]:     00547136(j)
//                              zone_map.cpp:426 (2)
//         0054713c     MOV        EBP,EAX
//                              zone_map.cpp:427 (6)
//         0054713e     MOV        EAX,dword ptr [ESP + param_2]
//         00547142     MOV        dword ptr [EAX],EBX
//                              zone_map.cpp:428 (35)
//         00547144     MOV        dword ptr [EAX + 0x4],ESI
//                               LAB_00547147                                                 XREF[2]:     00547123(j), 0054713a(j)
//         00547147     MOV        EAX,dword ptr [ESP + min.x]
//         0054714b     INC        ESI
//         0054714c     DEC        EDI
//         0054714d     CMP        ESI,EAX
//         0054714f     JLE        LAB_00547101
//         00547151     MOV        ESI,dword ptr [ESP + local_4]
//         00547155     MOV        this,dword ptr [ESP + max.y]
//                               LAB_00547159                                                 XREF[1]:     005470f9(j)
//         00547159     MOV        EDX,dword ptr [ESP + param_5]
//         0054715d     INC        EBX
//         0054715e     DEC        EDX
//         0054715f     CMP        EBX,this
//         00547161     MOV        dword ptr [ESP + param_5],EDX
//         00547165     JLE        LAB_005470f5
//                               LAB_00547167                                                 XREF[1]:     005470ed(j)
//                              zone_map.cpp:433 (2)
//         00547167     XOR        EAX,EAX
//                              zone_map.cpp:436 (16)
//         00547169     POP        EDI
//         0054716a     CMP        EBP,-0x1
//         0054716d     POP        ESI
//         0054716e     POP        EBP
//         0054716f     POP        EBX
//         00547170     SETNZ      AL
//         00547173     ADD        ESP,0x14
//         00547176     RET        0x18
//         00547179     ??         90h
//         0054717a     NOP
//         0054717b     NOP
//         0054717c     NOP
//         0054717d     NOP
//         0054717e     NOP
//         0054717f     NOP
    return 0;
}

RGE_Zone_Map_List::RGE_Zone_Map_List(int param_1, RGE_Map* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Zone_Map_List(RGE_Zone_Map_List * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00547242(R)
//                               ??0RGE_Zone_Map_List@@QAE@PAVRGE_Map@@@Z                     XREF[1]:     new_map:00455b4f(c)
//                               RGE_Zone_Map_List::RGE_Zone_Map_List
//                              zone_map.cpp:465 (2)
//         00547240     MOV        EAX,this
//                              zone_map.cpp:466 (7)
//         00547242     MOV        this,dword ptr [ESP + param_1]
//         00547246     MOV        dword ptr [EAX + 0x8],this
//                              zone_map.cpp:467 (6)
//         00547249     MOV        dword ptr [EAX],0x0
//                              zone_map.cpp:468 (7)
//         0054724f     MOV        dword ptr [EAX + 0x4],0x0
//                              zone_map.cpp:469 (3)
//         00547256     RET        0x4
}

RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Map* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Zone_Map_List(RGE_Zone_Map_List * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00547242(R)
//                               ??0RGE_Zone_Map_List@@QAE@PAVRGE_Map@@@Z                     XREF[1]:     new_map:00455b4f(c)
//                               RGE_Zone_Map_List::RGE_Zone_Map_List
//                              zone_map.cpp:465 (2)
//         00547240     MOV        EAX,this
//                              zone_map.cpp:466 (7)
//         00547242     MOV        this,dword ptr [ESP + param_1]
//         00547246     MOV        dword ptr [EAX + 0x8],this
//                              zone_map.cpp:467 (6)
//         00547249     MOV        dword ptr [EAX],0x0
//                              zone_map.cpp:468 (7)
//         0054724f     MOV        dword ptr [EAX + 0x4],0x0
//                              zone_map.cpp:469 (3)
//         00547256     RET        0x4
}

RGE_Zone_Map_List::~RGE_Zone_Map_List() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Zone_Map_List(RGE_Zone_Map_List * this)
//              void              <VOID>         <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//                               ??1RGE_Zone_Map_List@@QAE@XZ                                 XREF[3]:     ~RGE_Map:0045544b(c),
//                               RGE_Zone_Map_List::~RGE_Zone_Map_List                                     new_map:00455b24(c),
//                                                                                                         load_map:00457a21(c)
//                              zone_map.cpp:474 (5)
//         00547260     JMP        RGE_Zone_Map_List::delete_zone_maps
//         00547265     ??         90h
//         00547266     NOP
//         00547267     NOP
//         00547268     NOP
//         00547269     NOP
//         0054726a     NOP
//         0054726b     NOP
//         0054726c     NOP
//         0054726d     NOP
//         0054726e     NOP
//         0054726f     NOP
}

void RGE_Zone_Map_List::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Zone_Map_List * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00547272(R)
//                               ?save@RGE_Zone_Map_List@@QAEXH@Z                             XREF[1]:     save_map:00457c8e(c)
//                               RGE_Zone_Map_List::save
//                              zone_map.cpp:481 (2)
//         00547270     PUSH       EBX
//         00547271     PUSH       EBP
//                              zone_map.cpp:484 (20)
//         00547272     MOV        EBP,dword ptr [ESP + param_1]
//         00547276     MOV        EBX,this
//         00547278     PUSH       ESI
//         00547279     PUSH       EDI
//         0054727a     LEA        EDI,[EBX + 0x4]
//         0054727d     PUSH       0x4
//         0054727f     PUSH       EDI
//         00547280     PUSH       EBP
//         00547281     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              zone_map.cpp:485 (9)
//         00547286     MOV        EAX,dword ptr [EDI]
//         00547288     ADD        ESP,0xc
//         0054728b     TEST       EAX,EAX
//         0054728d     JLE        LAB_005472a7
//                              zone_map.cpp:487 (6)
//         0054728f     XOR        ESI,ESI
//         00547291     TEST       EAX,EAX
//         00547293     JLE        LAB_005472a7
//                               LAB_00547295                                                 XREF[1]:     005472a5(j)
//                              zone_map.cpp:488 (18)
//         00547295     MOV        EAX,dword ptr [EBX]
//         00547297     PUSH       EBP
//         00547298     MOV        this,dword ptr [EAX + ESI*0x4]
//         0054729b     CALL       RGE_Zone_Map::save                               void save(RGE_Zone_Map * this, int param_1)
//         005472a0     MOV        EAX,dword ptr [EDI]
//         005472a2     INC        ESI
//         005472a3     CMP        ESI,EAX
//         005472a5     JL         LAB_00547295
//                               LAB_005472a7                                                 XREF[2]:     0054728d(j), 00547293(j)
//                              zone_map.cpp:490 (7)
//         005472a7     POP        EDI
//         005472a8     POP        ESI
//         005472a9     POP        EBP
//         005472aa     POP        EBX
//         005472ab     RET        0x4
//         005472ae     ??         90h
//         005472af     NOP
    return;
}

long RGE_Zone_Map_List::create_zone_map(float* param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall create_zone_map(RGE_Zone_Map_List * this, float * pa
//              long              EAX:4          <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[2]:     005472da(R), 00547353(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     005472c9(R), 0054730d(W), 0054732f(R), 00547343(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00547349(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0054737c(R)
//                               ?create_zone_map@RGE_Zone_Map_List@@QAEJPAMJ@Z               XREF[1]:     generate:0048895f(c)
//                               RGE_Zone_Map_List::create_zone_map
//                              zone_map.cpp:495 (25)
//         005472b0     MOV        EAX,FS:[0x0]
//         005472b6     PUSH       -0x1
//         005472b8     PUSH       FUN_00561eab
//         005472bd     PUSH       EAX
//         005472be     MOV        dword ptr FS:[0x0],ESP
//         005472c5     PUSH       EBX
//         005472c6     MOV        EBX,this
//         005472c8     PUSH       EBP
//                              zone_map.cpp:500 (15)
//         005472c9     MOV        EBP,dword ptr [ESP + param_2]
//         005472cd     PUSH       ESI
//         005472ce     MOV        EAX,dword ptr [EBX + 0x4]
//         005472d1     XOR        ESI,ESI
//         005472d3     TEST       EAX,EAX
//         005472d5     PUSH       EDI
//         005472d6     JLE        LAB_005472f8
//                               LAB_005472d8                                                 XREF[1]:     005472f6(j)
//                              zone_map.cpp:501 (32)
//         005472d8     MOV        this,dword ptr [EBX]
//         005472da     MOV        EAX,dword ptr [ESP + param_1]
//         005472de     PUSH       EBP
//         005472df     PUSH       EAX
//         005472e0     MOV        this,dword ptr [this->zone_maps + ESI*0x4]
//         005472e3     CALL       RGE_Zone_Map::check_info                         RGE_Zone_Map * check_info(RGE_Zone_Map * this
//         005472e8     TEST       EAX,EAX
//         005472ea     JNZ        LAB_00547391
//         005472f0     MOV        EAX,dword ptr [EBX + 0x4]
//         005472f3     INC        ESI
//         005472f4     CMP        ESI,EAX
//         005472f6     JL         LAB_005472d8
//                               LAB_005472f8                                                 XREF[1]:     005472d6(j)
//                              zone_map.cpp:510 (12)
//         005472f8     MOV        EAX,dword ptr [EBX + 0x4]
//         005472fb     PUSH       0x4
//         005472fd     INC        EAX
//         005472fe     PUSH       EAX
//         005472ff     CALL       calloc                                           undefined calloc()
//                              zone_map.cpp:512 (15)
//         00547304     MOV        ESI,dword ptr [EBX]
//         00547306     ADD        ESP,0x8
//         00547309     MOV        EDI,EAX
//         0054730b     TEST       ESI,ESI
//         0054730d     MOV        dword ptr [ESP + param_2],EDI
//         00547311     JZ         LAB_00547336
//                              zone_map.cpp:514 (20)
//         00547313     MOV        this,dword ptr [EBX + 0x4]
//         00547316     SHL        this,0x2
//         00547319     MOV        EDX,this
//         0054731b     SHR        this,0x2
//         0054731e     MOVSD.REP  ES:EDI,ESI
//         00547320     MOV        this,EDX
//         00547322     AND        this,0x3
//         00547325     MOVSB.REP  ES:EDI,ESI
//                              zone_map.cpp:515 (15)
//         00547327     MOV        EAX,dword ptr [EBX]
//         00547329     PUSH       EAX
//         0054732a     CALL       free                                             undefined free()
//         0054732f     MOV        EDI,dword ptr [ESP + param_2]
//         00547333     ADD        ESP,0x4
//                               LAB_00547336                                                 XREF[1]:     00547311(j)
//                              zone_map.cpp:518 (56)
//         00547336     PUSH       0x51c
//         0054733b     CALL       operator_new                                     void * operator_new(uint param_1)
//         00547340     ADD        ESP,0x4
//         00547343     MOV        dword ptr [ESP + param_2],EAX
//         00547347     TEST       EAX,EAX
//         00547349     MOV        dword ptr [ESP + local_4],0x0
//         00547351     JZ         LAB_00547366
//         00547353     MOV        this,dword ptr [ESP + param_1]
//         00547357     MOV        EDX,dword ptr [EBX + 0x8]
//         0054735a     PUSH       EBP
//         0054735b     PUSH       this
//         0054735c     PUSH       EDX
//         0054735d     MOV        this,EAX
//         0054735f     CALL       RGE_Zone_Map::RGE_Zone_Map                       undefined RGE_Zone_Map(RGE_Zone_Map * this, R
//         00547364     JMP        LAB_00547368
//                               LAB_00547366                                                 XREF[1]:     00547351(j)
//         00547366     XOR        EAX,EAX
//                               LAB_00547368                                                 XREF[1]:     00547364(j)
//         00547368     MOV        this,dword ptr [EBX + 0x4]
//         0054736b     MOV        dword ptr [EDI + this->zone_maps*0x4],EAX
//                              zone_map.cpp:520 (11)
//         0054736e     MOV        EAX,dword ptr [EBX + 0x4]
//         00547371     INC        EAX
//         00547372     MOV        dword ptr [EBX],EDI
//         00547374     MOV        dword ptr [EBX + 0x4],EAX
//         00547377     MOV        EBX,EAX
//                              zone_map.cpp:522 (3)
//         00547379     LEA        EAX,[EBX + -0x1]
//                               LAB_0054737c                                                 XREF[2]:     005473a1(j), 005473a6(j)
//                              zone_map.cpp:523 (21)
//         0054737c     MOV        this,dword ptr [ESP + local_c]
//         00547380     POP        EDI
//         00547381     POP        ESI
//         00547382     POP        EBP
//         00547383     MOV        dword ptr FS:[0x0],this
//         0054738a     POP        EBX
//         0054738b     ADD        ESP,0xc
//         0054738e     RET        0x8
//                               LAB_00547391                                                 XREF[1]:     005472ea(j)
//                              zone_map.cpp:503 (14)
//         00547391     MOV        EDX,dword ptr [EBX]
//         00547393     MOV        this,dword ptr [EDX + ESI*0x4]
//         00547396     CALL       RGE_Zone_Map::do_zone_map                        uchar do_zone_map(RGE_Zone_Map * this)
//         0054739b     TEST       AL,AL
//         0054739d     JZ         LAB_005473a3
//                              zone_map.cpp:504 (4)
//         0054739f     MOV        EAX,ESI
//         005473a1     JMP        LAB_0054737c
//                               LAB_005473a3                                                 XREF[1]:     0054739d(j)
//                              zone_map.cpp:506 (5)
//         005473a3     OR         EAX,0xffffffff
//         005473a6     JMP        LAB_0054737c
//         005473a8     ??         90h
//         005473a9     NOP
//         005473aa     NOP
//         005473ab     NOP
//         005473ac     NOP
//         005473ad     NOP
//         005473ae     NOP
//         005473af     NOP
    return 0;
}

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(float* param_1, long param_2, int* param_3) {
    /* TODO: Stub */
//                              RGE_Zone_Map * __thiscall get_zone_map(RGE_Zone_Map_List * this, lon
//              RGE_Zone_Map *    EAX:4          <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     005474b0(R)
//                               ?get_zone_map@RGE_Zone_Map_List@@QAEPAVRGE_Zone_Map@@J@Z     XREF[12]:    canPath:0045f895(c),
//                               RGE_Zone_Map_List::get_zone_map                                           canPath:0045fa3e(c),
//                                                                                                         canBidirectionPath:0045fc43(c),
//                                                                                                         canPathWithObstructions:0045ff3e(c
//                                                                                                         findAvoidancePath:00460c4b(c),
//                                                                                                         generate:0048896e(c),
//                                                                                                         lookupZone:004c7487(c),
//                                                                                                         lookupZone:004c7507(c),
//                                                                                                         currentZone:004c7579(c),
//                                                                                                         withinRangeOfZoneAtPoint:004c75f5(
//                                                                                                         withinRangeOfZone:004c768d(c),
//                                                                                                         findClosestPointInTerrainType:004c
//                              zone_map.cpp:562 (15)
//         005474b0     MOV        EAX,dword ptr [ESP + param_1]
//         005474b4     MOV        EDX,dword ptr [ECX + this->zone_map_num]
//         005474b7     CMP        EAX,EDX
//         005474b9     JGE        LAB_005474c7
//         005474bb     TEST       EAX,EAX
//         005474bd     JL         LAB_005474c7
//                              zone_map.cpp:566 (5)
//         005474bf     MOV        this,dword ptr [this->zone_maps]
//         005474c1     MOV        EAX,dword ptr [this->zone_maps + EAX*0x4]
//                              zone_map.cpp:567 (3)
//         005474c4     RET        0x4
//                               LAB_005474c7                                                 XREF[2]:     005474b9(j), 005474bd(j)
//                              zone_map.cpp:564 (2)
//         005474c7     XOR        EAX,EAX
//                              zone_map.cpp:567 (3)
//         005474c9     RET        0x4
//         005474cc     ??         90h
//         005474cd     NOP
//         005474ce     NOP
//         005474cf     NOP
    return 0;
}

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(long param_1) {
    /* TODO: Stub */
//                              RGE_Zone_Map * __thiscall get_zone_map(RGE_Zone_Map_List * this, lon
//              RGE_Zone_Map *    EAX:4          <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     005474b0(R)
//                               ?get_zone_map@RGE_Zone_Map_List@@QAEPAVRGE_Zone_Map@@J@Z     XREF[12]:    canPath:0045f895(c),
//                               RGE_Zone_Map_List::get_zone_map                                           canPath:0045fa3e(c),
//                                                                                                         canBidirectionPath:0045fc43(c),
//                                                                                                         canPathWithObstructions:0045ff3e(c
//                                                                                                         findAvoidancePath:00460c4b(c),
//                                                                                                         generate:0048896e(c),
//                                                                                                         lookupZone:004c7487(c),
//                                                                                                         lookupZone:004c7507(c),
//                                                                                                         currentZone:004c7579(c),
//                                                                                                         withinRangeOfZoneAtPoint:004c75f5(
//                                                                                                         withinRangeOfZone:004c768d(c),
//                                                                                                         findClosestPointInTerrainType:004c
//                              zone_map.cpp:562 (15)
//         005474b0     MOV        EAX,dword ptr [ESP + param_1]
//         005474b4     MOV        EDX,dword ptr [ECX + this->zone_map_num]
//         005474b7     CMP        EAX,EDX
//         005474b9     JGE        LAB_005474c7
//         005474bb     TEST       EAX,EAX
//         005474bd     JL         LAB_005474c7
//                              zone_map.cpp:566 (5)
//         005474bf     MOV        this,dword ptr [this->zone_maps]
//         005474c1     MOV        EAX,dword ptr [this->zone_maps + EAX*0x4]
//                              zone_map.cpp:567 (3)
//         005474c4     RET        0x4
//                               LAB_005474c7                                                 XREF[2]:     005474b9(j), 005474bd(j)
//                              zone_map.cpp:564 (2)
//         005474c7     XOR        EAX,EAX
//                              zone_map.cpp:567 (3)
//         005474c9     RET        0x4
//         005474cc     ??         90h
//         005474cd     NOP
//         005474ce     NOP
//         005474cf     NOP
    return 0;
}

void RGE_Zone_Map_List::delete_zone_maps() {
    /* TODO: Stub */
//                              void __thiscall delete_zone_maps(RGE_Zone_Map_List * this)
//              void              <VOID>         <RETURN>
//              RGE_Zone_Map_L    ECX:4 (auto)   this
//                               ?delete_zone_maps@RGE_Zone_Map_List@@QAEXXZ                  XREF[2]:     generate:00485e3d(c),
//                               RGE_Zone_Map_List::delete_zone_maps                                       delete_zone_maps:00547259(T),
//                                                                                                         ~RGE_Zone_Map_List:00547260(j)
//                              zone_map.cpp:571 (3)
//         005474d0     PUSH       EDI
//         005474d1     MOV        EDI,this
//                              zone_map.cpp:574 (13)
//         005474d3     CMP        dword ptr [EDI],0x0
//         005474d6     JZ         LAB_00547522
//         005474d8     MOV        EAX,dword ptr [EDI + 0x4]
//         005474db     TEST       EAX,EAX
//         005474dd     JLE        LAB_00547522
//         005474df     PUSH       EBX
//                              zone_map.cpp:576 (6)
//         005474e0     XOR        EBX,EBX
//         005474e2     TEST       EAX,EAX
//         005474e4     JLE        LAB_00547509
//                              zone_map.cpp:571 (1)
//         005474e6     PUSH       ESI
//                               LAB_005474e7                                                 XREF[1]:     00547506(j)
//                              zone_map.cpp:577 (33)
//         005474e7     MOV        EAX,dword ptr [EDI]
//         005474e9     MOV        ESI,dword ptr [EAX + EBX*0x4]
//         005474ec     TEST       ESI,ESI
//         005474ee     JZ         LAB_00547500
//         005474f0     MOV        this,ESI
//         005474f2     CALL       RGE_Zone_Map::~RGE_Zone_Map                      void ~RGE_Zone_Map(RGE_Zone_Map * this)
//         005474f7     PUSH       ESI
//         005474f8     CALL       operator_delete                                  void operator_delete(void * param_1)
//         005474fd     ADD        ESP,0x4
//                               LAB_00547500                                                 XREF[1]:     005474ee(j)
//         00547500     MOV        EAX,dword ptr [EDI + 0x4]
//         00547503     INC        EBX
//         00547504     CMP        EBX,EAX
//         00547506     JL         LAB_005474e7
//                              zone_map.cpp:571 (1)
//         00547508     POP        ESI
//                               LAB_00547509                                                 XREF[1]:     005474e4(j)
//                              zone_map.cpp:579 (11)
//         00547509     MOV        this,dword ptr [EDI]
//         0054750b     PUSH       this
//         0054750c     CALL       free                                             undefined free()
//         00547511     ADD        ESP,0x4
//                              zone_map.cpp:580 (6)
//         00547514     MOV        dword ptr [EDI],0x0
//                              zone_map.cpp:581 (8)
//         0054751a     MOV        dword ptr [EDI + 0x4],0x0
//         00547521     POP        EBX
//                               LAB_00547522                                                 XREF[2]:     005474d6(j), 005474dd(j)
//                              zone_map.cpp:583 (2)
//         00547522     POP        EDI
//         00547523     RET
//         00547524     ??         90h
//         00547525     NOP
//         00547526     NOP
//         00547527     NOP
//         00547528     NOP
//         00547529     NOP
//         0054752a     NOP
//         0054752b     NOP
//         0054752c     NOP
//         0054752d     NOP
//         0054752e     NOP
//         0054752f     NOP
    return;
}

