// Auto-generated scaffold unit: rmm_land.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/rmm_land.cpp
#include "../include/common.h"

// Offset: 0x00485200
undefined RGE_RMM_Land_Generator(RGE_RMM_Land_Generator* this_, RGE_Map* param_2, RGE_Random_Map_Module* param_3, RGE_Land_Info* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(class RGE_Map *,class RGE_Random... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_RMM_Land_Generator(RGE_RMM_Land_Generator *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_RMM_Land_G    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00485208(R)  
    //              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     00485200(R)  
    //              RGE_Land_Info *   Stack[0xc]:4   param_3                   XREF[1]:     00485218(R)  
    //                               ??0RGE_RMM_Land_Generator@@QAE@PAVRGE_Map@@PAVRGE_Random_Ma  XREF[2]:     add_land_module:00482698(c), 
    //                               RGE_RMM_Land_Generator::RGE_RMM_Land_Generator                            generate:004834a9(c)  
    //                              rmm_land.cpp:25 (24)
    //         00485200     MOV        EAX,dword ptr [ESP + param_2]
    //         00485204     PUSH       EBX
    //         00485205     PUSH       ESI
    //         00485206     MOV        EBX,this
    //         00485208     MOV        this,dword ptr [ESP + param_1]
    //         0048520c     PUSH       EDI
    //         0048520d     PUSH       0x1
    //         0048520f     PUSH       EAX
    //         00485210     PUSH       this
    //         00485211     MOV        this,EBX
    //         00485213     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
    //                              rmm_land.cpp:28 (25)
    //         00485218     MOV        ESI,dword ptr [ESP + param_3]
    //         0048521c     MOV        this,0x50e
    //         00485221     LEA        EDI,[EBX + 0x30]
    //         00485224     MOV        dword ptr [EBX],RGE_RMM_Land_Generator::`vftab   = 00485240
    //         0048522a     MOV        dword ptr [EBX + 0x1c],0x3f800000
    //                              rmm_land.cpp:29 (10)
    //         00485231     MOV        EAX,EBX
    //         00485233     MOVSD.REP  ES:EDI,ESI
    //         00485235     POP        EDI
    //         00485236     POP        ESI
    //         00485237     POP        EBX
    //         00485238     RET        0xc
}

// Offset: 0x00485240
uchar RGE_RMM_Land_Generator::generate() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_RMM_Land_Generator::generate(void)                       *
    //                              *********************************************************************************************************
    //                              uchar __thiscall generate(RGE_RMM_Land_Generator * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Land_G    ECX:4 (auto)   this
    //                               ?generate@RGE_RMM_Land_Generator@@UAEEXZ                     XREF[1]:     00571ec8(*)  
    //                               RGE_RMM_Land_Generator::generate
    //                              rmm_land.cpp:33 (5)
    //         00485240     PUSH       EBX
    //         00485241     PUSH       ESI
    //         00485242     PUSH       EDI
    //         00485243     MOV        ESI,this
    //                              rmm_land.cpp:37 (5)
    //         00485245     CALL       RGE_Random_Map_Module::clear_stack               void clear_stack(RGE_Random_Map_Module * this)
    //                              rmm_land.cpp:38 (24)
    //         0048524a     MOV        this,dword ptr [ESI + 0x14]
    //         0048524d     MOV        AL,byte ptr [ESI + 0x144c]
    //         00485253     IMUL       this,dword ptr [ESI + 0x18]
    //         00485257     MOV        EDI,dword ptr [ESI + 0x20]
    //         0048525a     MOV        BL,AL
    //         0048525c     MOV        BH,BL
    //         0048525e     MOV        EDX,this
    //         00485260     MOV        EAX,EBX
    //                              rmm_land.cpp:41 (59)
    //         00485262     PUSH       0x0
    //         00485264     SHL        EAX,0x10
    //         00485267     MOV        AX,BX
    //         0048526a     PUSH       0x1
    //         0048526c     SHR        this,0x2
    //         0048526f     STOSD.REP  ES:EDI
    //         00485271     MOV        this,EDX
    //         00485273     AND        this,0x3
    //         00485276     STOSB.REP  ES:EDI
    //         00485278     MOV        this,word ptr [ESI + 0x18]
    //         0048527c     MOV        AL,byte ptr [ESI + 0x1450]
    //         00485282     MOV        DX,word ptr [ESI + 0x14]
    //         00485286     DEC        this
    //         00485288     PUSH       EAX
    //         00485289     DEC        DX
    //         0048528b     PUSH       this
    //         0048528c     MOV        this,dword ptr [ESI + 0xc]
    //         0048528f     PUSH       EDX
    //         00485290     PUSH       0x0
    //         00485292     PUSH       0x0
    //         00485294     PUSH       0x0
    //         00485296     PUSH       0x0
    //         00485298     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Player *
    //                              rmm_land.cpp:44 (7)
    //         0048529d     MOV        this,ESI
    //         0048529f     CALL       RGE_RMM_Land_Generator::base_land_generate       uchar base_land_generate(RGE_RMM_Land_Generat
    //                              rmm_land.cpp:47 (27)
    //         004852a4     MOV        AL,byte ptr [ESI + 0x1450]
    //         004852aa     MOV        this,dword ptr [ESI + 0x18]
    //         004852ad     MOV        EDX,dword ptr [ESI + 0x14]
    //         004852b0     PUSH       EAX
    //         004852b1     PUSH       this
    //         004852b2     MOV        this,dword ptr [ESI + 0xc]
    //         004852b5     PUSH       EDX
    //         004852b6     PUSH       0x0
    //         004852b8     PUSH       0x0
    //         004852ba     CALL       RGE_Map::clean_terrain                           void clean_terrain(RGE_Map * this, long param
    //                              rmm_land.cpp:51 (6)
    //         004852bf     POP        EDI
    //         004852c0     POP        ESI
    //         004852c1     MOV        AL,0x1
    //         004852c3     POP        EBX
    //         004852c4     RET
}

// Offset: 0x004852D0
uchar check_terrain_and_zone(RGE_RMM_Land_Generator* this_, uchar param_2, uchar param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_RMM_Land_Generator::check_terrain_and_zone(unsigned char,u... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_terrain_and_zone(RGE_RMM_Land_Generator * thi
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Land_G    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              uchar             Stack[0x8]:1   param_2                   XREF[5]:     004852d3(R), 00485304(W), 0048530a(R), 00485350(W), 
    //                                                                                     0048539d(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     004852e7(R), 00485337(W), 004853ad(R), 00485404(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[4]:     004852df(R), 00485348(W), 004853c2(R), 0048540a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00485320(W), 004853d2(R)  
    //              long              Stack[-0x8]:4  x1                        XREF[2]:     0048530e(W), 004853ce(R)  
    //              long              Stack[-0xc]:4  x0                        XREF[3]:     00485324(W), 0048538f(R), 00485439(R)  
    //              long              Stack[-0x10]:4 y1                        XREF[3]:     00485341(W), 004853ef(R), 00485416(R)  
    //              long              Stack[-0x14]:4 cx1                       XREF[3]:     00485333(W), 004853de(R), 00485410(R)  
    //              long              Stack[-0x18]:4 cx0                       XREF[5]:     004852eb(W), 0048534c(R), 0048535f(R), 00485387(W), 
    //                                                                                     0048538b(W)  
    //              long              Stack[-0x1c]:4 octogon_y1                XREF[8]:     004852f4(W), 004853b7(RW), 004853c8(RW), 004853e4(RW), 
    //                                                                                     004853f5(RW), 0048541c(RW), 00485449(R), 00485463(R)  
    //              long              Stack[-0x20]:4 count
    //                               ?check_terrain_and_zone@RGE_RMM_Land_Generator@@IAEEEEJJ@Z   XREF[1]:     base_land_generate:0048584e(c)  
    //                               RGE_RMM_Land_Generator::check_terrain_and_zone
    //                              rmm_land.cpp:57 (3)
    //         004852d0     SUB        ESP,0x1c
    //                              rmm_land.cpp:61 (12)
    //         004852d3     MOV        EAX,dword ptr [ESP + param_2]
    //         004852d7     PUSH       EBX
    //         004852d8     AND        EAX,0xff
    //         004852dd     PUSH       EBP
    //         004852de     PUSH       ESI
    //                              rmm_land.cpp:62 (43)
    //         004852df     MOV        ESI,dword ptr [ESP + param_4]
    //         004852e3     LEA        EDX,[EAX + EAX*0x2]
    //         004852e6     PUSH       EDI
    //         004852e7     MOV        EDI,dword ptr [ESP + param_3]
    //         004852eb     MOV        dword ptr [ESP + cx0],this
    //         004852ef     LEA        EAX,[EAX + EDX*0x4]
    //         004852f2     MOV        EBP,ESI
    //         004852f4     MOV        dword ptr [ESP + octogon_y1],0x0
    //         004852fc     LEA        EBX,[this->_padding_ + EAX*0x4]
    //         004852ff     MOV        this,EDI
    //         00485301     MOV        EAX,dword ptr [EBX + 0x44]
    //         00485304     MOV        dword ptr [ESP + param_2],EAX
    //         00485308     SUB        this,EAX
    //                              rmm_land.cpp:69 (35)
    //         0048530a     FILD       dword ptr [ESP + param_2]
    //         0048530e     MOV        dword ptr [ESP + x1],this
    //         00485312     LEA        this,[EDI + EAX*0x1]
    //         00485315     LEA        EDX,[ESI + EAX*0x1]
    //         00485318     SUB        EBP,EAX
    //         0048531a     FMUL       double ptr [DAT_00571ed0]                        = 46h    F
    //         00485320     MOV        dword ptr [ESP + local_4],this
    //         00485324     MOV        dword ptr [ESP + x0],EDX
    //         00485328     CALL       __ftol                                           undefined __ftol()
    //                              rmm_land.cpp:70 (3)
    //         0048532d     LEA        this,[EDI + -0x2]
    //                              rmm_land.cpp:71 (11)
    //         00485330     LEA        EDX,[ESI + -0x2]
    //         00485333     MOV        dword ptr [ESP + cx1],this
    //         00485337     MOV        dword ptr [ESP + param_3],EDX
    //                              rmm_land.cpp:72 (3)
    //         0048533b     LEA        this,[EDI + 0x2]
    //                              rmm_land.cpp:73 (7)
    //         0048533e     LEA        EDX,[ESI + 0x2]
    //         00485341     MOV        dword ptr [ESP + y1],this
    //                              rmm_land.cpp:74 (7)
    //         00485345     MOV        this,byte ptr [EBX + 0x48]
    //         00485348     MOV        dword ptr [ESP + param_4],EDX
    //                              rmm_land.cpp:76 (31)
    //         0048534c     MOV        EDX,dword ptr [ESP + cx0]
    //         00485350     MOV        byte ptr [ESP + param_2],this
    //         00485354     XOR        EBX,EBX
    //         00485356     MOV        this,dword ptr [EDX + 0x24]
    //         00485359     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         0048535c     MOV        BL,byte ptr [EDX + EDI*0x1]
    //         0048535f     MOV        EDI,dword ptr [ESP + cx0]
    //         00485363     CMP        EBX,dword ptr [EDI + 0x144c]
    //         00485369     JZ         LAB_00485377
    //                              rmm_land.cpp:77 (2)
    //         0048536b     XOR        AL,AL
    //                              rmm_land.cpp:140 (10)
    //         0048536d     POP        EDI
    //         0048536e     POP        ESI
    //         0048536f     POP        EBP
    //         00485370     POP        EBX
    //         00485371     ADD        ESP,0x1c
    //         00485374     RET        0x10
    //                               LAB_00485377                                                 XREF[1]:     00485369(j)  
    //                              rmm_land.cpp:79 (5)
    //         00485377     CMP        EAX,0x2
    //         0048537a     JGE        LAB_00485381
    //                              rmm_land.cpp:80 (5)
    //         0048537c     MOV        EAX,0x2
    //                               LAB_00485381                                                 XREF[1]:     0048537a(j)  
    //                              rmm_land.cpp:81 (4)
    //         00485381     MOV        EDX,ESI
    //         00485383     SUB        EDX,EAX
    //                              rmm_land.cpp:82 (10)
    //         00485385     ADD        EAX,ESI
    //         00485387     MOV        dword ptr [ESP + cx0],EDX
    //         0048538b     MOV        dword ptr [ESP + cx0],EAX
    //                              rmm_land.cpp:86 (26)
    //         0048538f     MOV        EAX,dword ptr [ESP + x0]
    //         00485393     MOV        ESI,EBP
    //         00485395     CMP        EBP,EAX
    //         00485397     JG         LAB_00485463
    //         0048539d     MOV        BL,byte ptr [ESP + param_2]
    //         004853a1     LEA        EDX,[this->_padding_ + EBP*0x4]
    //         004853a4     MOV        EAX,0x5
    //                               LAB_004853a9                                                 XREF[1]:     00485443(j)  
    //                              rmm_land.cpp:88 (4)
    //         004853a9     TEST       ESI,ESI
    //         004853ab     JGE        LAB_004853bd
    //                              rmm_land.cpp:90 (10)
    //         004853ad     CMP        ESI,dword ptr [ESP + param_3]
    //         004853b1     JLE        LAB_00485439
    //                              rmm_land.cpp:91 (4)
    //         004853b7     ADD        dword ptr [ESP + octogon_y1],EAX
    //                              rmm_land.cpp:93 (7)
    //         004853bb     JMP        LAB_00485439
    //                               LAB_004853bd                                                 XREF[1]:     004853ab(j)  
    //         004853bd     CMP        ESI,dword ptr [EDI + 0x18]
    //         004853c0     JL         LAB_004853ce
    //                              rmm_land.cpp:95 (6)
    //         004853c2     CMP        ESI,dword ptr [ESP + param_4]
    //         004853c6     JGE        LAB_00485439
    //                              rmm_land.cpp:96 (4)
    //         004853c8     ADD        dword ptr [ESP + octogon_y1],EAX
    //                              rmm_land.cpp:98 (2)
    //         004853cc     JMP        LAB_00485439
    //                               LAB_004853ce                                                 XREF[1]:     004853c0(j)  
    //                              rmm_land.cpp:100 (12)
    //         004853ce     MOV        this,dword ptr [ESP + x1]
    //         004853d2     MOV        EBP,dword ptr [ESP + local_4]
    //         004853d6     CMP        this,EBP
    //         004853d8     JG         LAB_00485439
    //                               LAB_004853da                                                 XREF[1]:     00485432(j)  
    //                              rmm_land.cpp:102 (4)
    //         004853da     TEST       this,this
    //         004853dc     JGE        LAB_004853ea
    //                              rmm_land.cpp:104 (6)
    //         004853de     CMP        this,dword ptr [ESP + cx1]
    //         004853e2     JLE        LAB_0048542f
    //                              rmm_land.cpp:105 (4)
    //         004853e4     INC        dword ptr [ESP + octogon_y1]
    //                              rmm_land.cpp:107 (7)
    //         004853e8     JMP        LAB_0048542f
    //                               LAB_004853ea                                                 XREF[1]:     004853dc(j)  
    //         004853ea     CMP        this,dword ptr [EDI + 0x14]
    //         004853ed     JL         LAB_004853fb
    //                              rmm_land.cpp:109 (6)
    //         004853ef     CMP        this,dword ptr [ESP + y1]
    //         004853f3     JGE        LAB_0048542f
    //                              rmm_land.cpp:110 (4)
    //         004853f5     INC        dword ptr [ESP + octogon_y1]
    //                              rmm_land.cpp:112 (2)
    //         004853f9     JMP        LAB_0048542f
    //                               LAB_004853fb                                                 XREF[1]:     004853ed(j)  
    //                              rmm_land.cpp:114 (9)
    //         004853fb     MOV        EAX,dword ptr [EDX]
    //         004853fd     MOV        AL,byte ptr [this->_padding_ + EAX*0x1]
    //         00485400     CMP        AL,BL
    //         00485402     JNZ        LAB_00485422
    //                              rmm_land.cpp:116 (24)
    //         00485404     CMP        ESI,dword ptr [ESP + param_3]
    //         00485408     JL         LAB_0048542f
    //         0048540a     CMP        ESI,dword ptr [ESP + param_4]
    //         0048540e     JG         LAB_0048542f
    //         00485410     CMP        this,dword ptr [ESP + cx1]
    //         00485414     JL         LAB_0048542f
    //         00485416     CMP        this,dword ptr [ESP + y1]
    //         0048541a     JG         LAB_0048542f
    //                              rmm_land.cpp:117 (4)
    //         0048541c     INC        dword ptr [ESP + octogon_y1]
    //                              rmm_land.cpp:119 (2)
    //         00485420     JMP        LAB_0048542f
    //                               LAB_00485422                                                 XREF[1]:     00485402(j)  
    //                              rmm_land.cpp:120 (13)
    //         00485422     AND        EAX,0xff
    //         00485427     CMP        EAX,dword ptr [EDI + 0x144c]
    //         0048542d     JL         LAB_00485457
    //                               LAB_0048542f                                                 XREF[9]:     004853e2(j), 004853e8(j), 
    //                                                                                                         004853f3(j), 004853f9(j), 
    //                                                                                                         00485408(j), 0048540e(j), 
    //                                                                                                         00485414(j), 0048541a(j), 
    //                                                                                                         00485420(j)  
    //                              rmm_land.cpp:100 (10)
    //         0048542f     INC        this
    //         00485430     CMP        this,EBP
    //         00485432     JLE        LAB_004853da
    //         00485434     MOV        EAX,0x5
    //                               LAB_00485439                                                 XREF[5]:     004853b1(j), 004853bb(j), 
    //                                                                                                         004853c6(j), 004853cc(j), 
    //                                                                                                         004853d8(j)  
    //                              rmm_land.cpp:86 (16)
    //         00485439     MOV        this,dword ptr [ESP + x0]
    //         0048543d     INC        ESI
    //         0048543e     ADD        EDX,0x4
    //         00485441     CMP        ESI,this
    //         00485443     JLE        LAB_004853a9
    //                              rmm_land.cpp:139 (4)
    //         00485449     MOV        AL,byte ptr [ESP + octogon_y1]
    //                              rmm_land.cpp:140 (10)
    //         0048544d     POP        EDI
    //         0048544e     POP        ESI
    //         0048544f     POP        EBP
    //         00485450     POP        EBX
    //         00485451     ADD        ESP,0x1c
    //         00485454     RET        0x10
    //                               LAB_00485457                                                 XREF[1]:     0048542d(j)  
    //                              rmm_land.cpp:121 (2)
    //         00485457     XOR        AL,AL
    //                              rmm_land.cpp:140 (10)
    //         00485459     POP        EDI
    //         0048545a     POP        ESI
    //         0048545b     POP        EBP
    //         0048545c     POP        EBX
    //         0048545d     ADD        ESP,0x1c
    //         00485460     RET        0x10
    //                               LAB_00485463                                                 XREF[1]:     00485397(j)  
    //                              rmm_land.cpp:139 (4)
    //         00485463     MOV        AL,byte ptr [ESP + octogon_y1]
    //                              rmm_land.cpp:140 (10)
    //         00485467     POP        EDI
    //         00485468     POP        ESI
    //         00485469     POP        EBP
    //         0048546a     POP        EBX
    //         0048546b     ADD        ESP,0x1c
    //         0048546e     RET        0x10
}

// Offset: 0x00485480
uchar chance(RGE_RMM_Land_Generator* this_, long param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_RMM_Land_Generator::chance(long,long,long)                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall chance(RGE_RMM_Land_Generator * this, long param_1,
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Land_G    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004854a0(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004854ce(R), 004854dc(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     00485480(R), 00485497(W), 004854f9(R)  
    //                               ?chance@RGE_RMM_Land_Generator@@IAEEJJJ@Z                    XREF[1]:     base_land_generate:004857e3(c)  
    //                               RGE_RMM_Land_Generator::chance
    //                              rmm_land.cpp:146 (29)
    //         00485480     MOV        EAX,dword ptr [ESP + param_3]
    //         00485484     PUSH       EBX
    //         00485485     PUSH       EBP
    //         00485486     PUSH       ESI
    //         00485487     LEA        EDX,[EAX + EAX*0x2]
    //         0048548a     PUSH       EDI
    //         0048548b     LEA        EAX,[EAX + EDX*0x4]
    //         0048548e     LEA        EDX,[this->_padding_ + EAX*0x4]
    //         00485491     MOV        AL,byte ptr [ECX + EAX*0x4 + this+0x60]
    //         00485495     TEST       AL,AL
    //         00485497     MOV        byte ptr [ESP + param_3],AL
    //         0048549b     JBE        LAB_00485516
    //                              rmm_land.cpp:159 (7)
    //         0048549d     MOV        EDI,dword ptr [EDX + 0x50]
    //         004854a0     MOV        ESI,dword ptr [ESP + param_1]
    //                              rmm_land.cpp:160 (9)
    //         004854a4     MOV        EBP,dword ptr [EDX + 0x58]
    //         004854a7     MOV        EAX,EDI
    //         004854a9     SUB        EAX,ESI
    //         004854ab     SUB        ESI,EBP
    //                              rmm_land.cpp:161 (8)
    //         004854ad     CMP        EAX,ESI
    //         004854af     MOV        EBX,EAX
    //         004854b1     JG         LAB_004854b5
    //         004854b3     MOV        EBX,ESI
    //                               LAB_004854b5                                                 XREF[1]:     004854b1(j)  
    //                              rmm_land.cpp:166 (9)
    //         004854b5     MOV        this,dword ptr [ECX + this->_padding_]
    //         004854b8     ADD        EAX,EDI
    //         004854ba     SUB        this,EBP
    //         004854bc     ADD        ESI,this
    //                              rmm_land.cpp:168 (6)
    //         004854be     CMP        EAX,ESI
    //         004854c0     JG         LAB_004854c4
    //         004854c2     MOV        EAX,ESI
    //                               LAB_004854c4                                                 XREF[1]:     004854c0(j)  
    //                              rmm_land.cpp:172 (7)
    //         004854c4     MOV        this,dword ptr [EDX + 0x54]
    //         004854c7     TEST       EAX,EAX
    //         004854c9     JLE        LAB_004854dc
    //                              rmm_land.cpp:173 (15)
    //         004854cb     MOV        EDI,dword ptr [EDX + 0x5c]
    //         004854ce     MOV        ESI,dword ptr [ESP + param_2]
    //         004854d2     ADD        this,EAX
    //         004854d4     SUB        EAX,EDI
    //         004854d6     SUB        this,ESI
    //         004854d8     ADD        EAX,ESI
    //                              rmm_land.cpp:175 (2)
    //         004854da     JMP        LAB_004854e7
    //                               LAB_004854dc                                                 XREF[1]:     004854c9(j)  
    //                              rmm_land.cpp:177 (4)
    //         004854dc     MOV        EAX,dword ptr [ESP + param_2]
    //                              rmm_land.cpp:178 (7)
    //         004854e0     MOV        ESI,dword ptr [EDX + 0x5c]
    //         004854e3     SUB        this,EAX
    //         004854e5     SUB        EAX,ESI
    //                               LAB_004854e7                                                 XREF[1]:     004854da(j)  
    //                              rmm_land.cpp:181 (6)
    //         004854e7     CMP        this,EAX
    //         004854e9     JLE        LAB_004854ed
    //         004854eb     MOV        EAX,this
    //                               LAB_004854ed                                                 XREF[1]:     004854e9(j)  
    //                              rmm_land.cpp:183 (6)
    //         004854ed     TEST       EBX,EBX
    //         004854ef     JGE        LAB_004854f3
    //         004854f1     XOR        EBX,EBX
    //                               LAB_004854f3                                                 XREF[1]:     004854ef(j)  
    //                              rmm_land.cpp:184 (6)
    //         004854f3     TEST       EAX,EAX
    //         004854f5     JGE        LAB_004854f9
    //         004854f7     XOR        EAX,EAX
    //                               LAB_004854f9                                                 XREF[1]:     004854f5(j)  
    //                              rmm_land.cpp:199 (15)
    //         004854f9     MOV        this,dword ptr [ESP + param_3]
    //         004854fd     ADD        EAX,EBX
    //         004854ff     AND        this,0xff
    //         00485505     IMUL       EAX,this
    //                              rmm_land.cpp:201 (5)
    //         00485508     CMP        EAX,0x64
    //         0048550b     JL         LAB_00485518
    //                              rmm_land.cpp:202 (2)
    //         0048550d     MOV        AL,0x65
    //                              rmm_land.cpp:208 (7)
    //         0048550f     POP        EDI
    //         00485510     POP        ESI
    //         00485511     POP        EBP
    //         00485512     POP        EBX
    //         00485513     RET        0xc
    //                               LAB_00485516                                                 XREF[1]:     0048549b(j)  
    //                              rmm_land.cpp:207 (2)
    //         00485516     XOR        AL,AL
    //                               LAB_00485518                                                 XREF[1]:     0048550b(j)  
    //                              rmm_land.cpp:208 (7)
    //         00485518     POP        EDI
    //         00485519     POP        ESI
    //         0048551a     POP        EBP
    //         0048551b     POP        EBX
    //         0048551c     RET        0xc
}

// Offset: 0x00485520
uchar base_land_generate(RGE_RMM_Land_Generator* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_RMM_Land_Generator::base_land_generate(void)                  *
    //                              *********************************************************************************************************
    //                              uchar __thiscall base_land_generate(RGE_RMM_Land_Generator * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Land_G    ECX:4 (auto)   this
    //              Map_Stack[99]     Stack[-0x94c   stack                     XREF[0,4]:   00485552(*), 00485787(*), 00485b13(*), 00485c08(*)  
    //              long[99]          Stack[-0xad8   land_size                 XREF[3,5]:   004857ae(*), 00485b2a(*), 00485bb4(*), 00485559(*), 
    //                                                                                     0048558a(*), 00485783(*), 004857a0(*), 00485abf(*)  
    //              float             Stack[-0xadc   in_zone                   XREF[3]:     00485538(W), 00485939(R), 00485b73(R)  
    //              long              Stack[-0xae0   max_x                     XREF[3]:     00485540(W), 00485a3d(R), 00485b90(R)  
    //              long              Stack[-0xae4   max_y                     XREF[8]:     00485564(W), 0048557e(R), 00485736(R), 00485758(W), 
    //                                                                                     00485841(W), 00485849(R), 00485b2e(W), 00485ba2(R)  
    //              uchar             Stack[-0xae8   terrain                   XREF[8]:     0048559c(W), 004855a4(W), 004855ac(R), 004855ea(R), 
    //                                                                                     00485633(R), 00485687(R), 004856c8(R), 004856fd(R)  
    //              long              Stack[-0xaec   x1                        XREF[8]:     0048564a(W), 00485661(R), 0048567a(R), 00485681(W), 
    //                                                                                     00485691(W), 004856a3(R), 004856bb(R), 004856c2(W)  
    //              long              Stack[-0xaf0   index2                    XREF[8]:     004855f7(W), 00485606(R), 00485627(R), 004857a4(W), 
    //                                                                                     00485ab6(R), 00485b21(W), 00485bd3(R), 00485bee(W)  
    //              undefined1        Stack[-0xaf1   local_af1                 XREF[3]:     00485774(W), 004857de(W), 00485af1(R)  
    //              uchar             Stack[-0xaf4   zone
    //              uchar             Stack[-0xaf5   done
    //              RGE_Tile *        Stack[-0xafc   tile                      XREF[12]:    004855ee(W), 0048561f(R), 00485637(R), 0048563e(W), 
    //                                                                                     00485659(W), 0048565d(R), 0048569b(W), 0048569f(R), 
    //                                                                                     004856dc(W), 004856e0(R), 00485714(W), 00485718(R)  
    //              long              Stack[-0xb00   index3                    XREF[13]:    0048552c(W), 00485650(R), 00485697(R), 004856d8(R), 
    //                                                                                     0048570f(R), 00485732(R), 00485754(W), 00485779(W), 
    //                                                                                     00485ac1(R), 00485adf(W), 00485b03(W), 00485bd7(R), 
    //                                                                                     00485bea(W)  
    //              long              Stack[-0xb04   index1                    XREF[14]:    00485568(W), 0048556e(R), 004855ca(R), 004855e6(R), 
    //                                                                                     0048573a(R), 0048575c(W), 0048578e(W), 00485799(R), 
    //                                                                                     00485aba(R), 00485ac9(R), 00485ae7(W), 00485b1d(W), 
    //                                                                                     00485bb0(R), 00485bf2(W)  
    //              undefined4        Stack[-0xb08   local_b08                 XREF[14]:    00485560(W), 00485572(R), 0048566c(R), 004856ae(R), 
    //                                                                                     004856ec(R), 0048571c(R), 0048573e(R), 00485760(W), 
    //                                                                                     00485792(W), 004857b7(R), 004858e3(R), 00485935(R), 
    //                                                                                     00485ac5(R), 00485ae3(W)  
    //              undefined4        Stack[-0xb0c   local_b0c                 XREF[17]:    004857bb(*), 004857d5(R), 00485828(R), 00485864(R), 
    //                                                                                     0048589e(R), 004858a8(R), 00485907(R), 0048592f(R), 
    //                                                                                     0048598e(R), 004859b6(R), 00485a0d(R), 00485a35(R), 
    //                                                                                     00485a9f(R), 00485b37(*), 00485b54(R), 00485bbd(*), 
    //                                                                                     00485c3c(R)  
    //              long              Stack[-0xb10   x                         XREF[17]:    004857b2(*), 004857d1(R), 0048582c(R), 00485856(R), 
    //                                                                                     00485897(R), 004858b7(R), 0048591a(R), 00485942(R), 
    //                                                                                     004859a1(R), 004859ba(R), 00485a1f(R), 00485a39(R), 
    //                                                                                     00485a89(R), 00485b32(*), 00485b4d(R), 00485bb8(*), 
    //                                                                                     00485c35(R)  
    //              long              Stack[-0xb14   y
    //              undefined4        Stack[-0xb24   local_b24                 XREF[4]:     00485922(*), 004859a9(*), 00485a28(*), 00485aa7(*)  
    //                               ?base_land_generate@RGE_RMM_Land_Generator@@IAEEXZ           XREF[1]:     generate:0048529f(c)  
    //                               RGE_RMM_Land_Generator::base_land_generate
    //                              rmm_land.cpp:213 (12)
    //         00485520     SUB        ESP,0xb10
    //         00485526     PUSH       EBX
    //         00485527     PUSH       EBP
    //         00485528     PUSH       ESI
    //         00485529     MOV        ESI,this
    //         0048552b     PUSH       EDI
    //                              rmm_land.cpp:237 (66)
    //         0048552c     MOV        dword ptr [ESP + index3],0x0
    //         00485534     MOV        EAX,dword ptr [ESI + 0x14]
    //         00485537     DEC        EAX
    //         00485538     MOV        dword ptr [ESP + in_zone],EAX
    //         0048553c     MOV        EAX,dword ptr [ESI + 0x18]
    //         0048553f     DEC        EAX
    //         00485540     MOV        dword ptr [ESP + max_x],EAX
    //         00485544     MOV        EAX,dword ptr [ESI + 0x144c]
    //         0048554a     TEST       EAX,EAX
    //         0048554c     JLE        LAB_0048576a
    //         00485552     LEA        EAX=>stack[0].y,[ESP + 0x1d8]
    //         00485559     LEA        this=>land_size[1],[ESP + 0x4c]
    //         0048555d     LEA        EBX,[ESI + 0x40]
    //         00485560     MOV        dword ptr [ESP + local_b08],EAX
    //         00485564     MOV        dword ptr [ESP + max_y],this
    //         00485568     MOV        dword ptr [ESP + index1],EBX
    //         0048556c     JMP        LAB_00485572
    //                               LAB_0048556e                                                 XREF[1]:     00485764(j)  
    //                              rmm_land.cpp:217 (4)
    //         0048556e     MOV        EBX,dword ptr [ESP + index1]
    //                               LAB_00485572                                                 XREF[1]:     0048556c(j)  
    //                              rmm_land.cpp:240 (12)
    //         00485572     MOV        EDX,dword ptr [ESP + local_b08]
    //         00485576     MOV        this,ESI
    //         00485578     PUSH       EDX
    //         00485579     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
    //                              rmm_land.cpp:241 (4)
    //         0048557e     MOV        EAX,dword ptr [ESP + max_y]
    //                              rmm_land.cpp:244 (3)
    //         00485582     MOV        EDI,dword ptr [EBX + -0x8]
    //                              rmm_land.cpp:245 (19)
    //         00485585     MOV        EBP,dword ptr [EBX + -0x4]
    //         00485588     MOV        this,EDI
    //         0048558a     MOV        dword ptr [EAX]=>land_size[1],0x0
    //         00485590     MOV        EAX,dword ptr [EBX]
    //         00485592     MOV        EBX,EBP
    //         00485594     SUB        this,EAX
    //         00485596     SUB        EBX,EAX
    //                              rmm_land.cpp:246 (2)
    //         00485598     ADD        EDI,EAX
    //                              rmm_land.cpp:247 (6)
    //         0048559a     ADD        EBP,EAX
    //         0048559c     MOV        dword ptr [ESP + terrain],this
    //                              rmm_land.cpp:249 (4)
    //         004855a0     TEST       this,this
    //         004855a2     JGE        LAB_004855b0
    //                              rmm_land.cpp:250 (12)
    //         004855a4     MOV        dword ptr [ESP + terrain],0x0
    //         004855ac     MOV        this,dword ptr [ESP + terrain]
    //                               LAB_004855b0                                                 XREF[1]:     004855a2(j)  
    //                              rmm_land.cpp:251 (4)
    //         004855b0     TEST       EBX,EBX
    //         004855b2     JGE        LAB_004855b6
    //                              rmm_land.cpp:252 (2)
    //         004855b4     XOR        EBX,EBX
    //                               LAB_004855b6                                                 XREF[1]:     004855b2(j)  
    //                              rmm_land.cpp:253 (7)
    //         004855b6     MOV        EAX,dword ptr [ESI + 0x14]
    //         004855b9     CMP        EDI,EAX
    //         004855bb     JL         LAB_004855c0
    //                              rmm_land.cpp:254 (3)
    //         004855bd     LEA        EDI,[EAX + -0x1]
    //                               LAB_004855c0                                                 XREF[1]:     004855bb(j)  
    //                              rmm_land.cpp:255 (7)
    //         004855c0     MOV        EAX,dword ptr [ESI + 0x18]
    //         004855c3     CMP        EBP,EAX
    //         004855c5     JL         LAB_004855ca
    //                              rmm_land.cpp:256 (3)
    //         004855c7     LEA        EBP,[EAX + -0x1]
    //                               LAB_004855ca                                                 XREF[1]:     004855c5(j)  
    //                              rmm_land.cpp:259 (28)
    //         004855ca     MOV        EDX,dword ptr [ESP + index1]
    //         004855ce     PUSH       0x0
    //         004855d0     PUSH       0x1
    //         004855d2     MOV        AL,byte ptr [EDX + -0xc]
    //         004855d5     PUSH       EAX
    //         004855d6     PUSH       EBP
    //         004855d7     PUSH       EDI
    //         004855d8     PUSH       EBX
    //         004855d9     PUSH       this
    //         004855da     MOV        this,dword ptr [ESI + 0xc]
    //         004855dd     PUSH       0x0
    //         004855df     PUSH       0x0
    //         004855e1     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Player *
    //                              rmm_land.cpp:261 (4)
    //         004855e6     MOV        this,dword ptr [ESP + index1]
    //                              rmm_land.cpp:262 (4)
    //         004855ea     MOV        EAX,dword ptr [ESP + terrain]
    //                              rmm_land.cpp:265 (42)
    //         004855ee     MOV        dword ptr [ESP + tile],EBX
    //         004855f2     MOV        DL,byte ptr [ECX + this->_padding_]
    //         004855f5     MOV        this,EDI
    //         004855f7     MOV        byte ptr [ESP + index2],DL
    //         004855fb     MOV        EDX,EBP
    //         004855fd     SUB        this,EAX
    //         004855ff     SUB        EDX,EBX
    //         00485601     INC        this
    //         00485602     INC        EDX
    //         00485603     IMUL       this,EDX
    //         00485606     MOV        EDX,dword ptr [ESP + index2]
    //         0048560a     AND        EDX,0xff
    //         00485610     CMP        EBX,EBP
    //         00485612     MOV        dword ptr [ESP + EDX*0x4 + 0x4c],this
    //         00485616     JG         LAB_00485644
    //                               LAB_00485618                                                 XREF[1]:     00485642(j)  
    //                              rmm_land.cpp:266 (4)
    //         00485618     CMP        EAX,EDI
    //         0048561a     JG         LAB_00485637
    //                               LAB_0048561c                                                 XREF[1]:     00485631(j)  
    //                              rmm_land.cpp:267 (23)
    //         0048561c     MOV        this,dword ptr [ESI + 0x24]
    //         0048561f     MOV        EDX,dword ptr [ESP + tile]
    //         00485623     INC        EAX
    //         00485624     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00485627     MOV        DL,byte ptr [ESP + index2]
    //         0048562b     CMP        EAX,EDI
    //         0048562d     MOV        byte ptr [this->_padding_ + EAX*0x1 + -0x1],DL
    //         00485631     JLE        LAB_0048561c
    //                              rmm_land.cpp:266 (4)
    //         00485633     MOV        EAX,dword ptr [ESP + terrain]
    //                               LAB_00485637                                                 XREF[1]:     0048561a(j)  
    //                              rmm_land.cpp:265 (13)
    //         00485637     MOV        this,dword ptr [ESP + tile]
    //         0048563b     INC        this
    //         0048563c     CMP        this,EBP
    //         0048563e     MOV        dword ptr [ESP + tile],this
    //         00485642     JLE        LAB_00485618
    //                               LAB_00485644                                                 XREF[1]:     00485616(j)  
    //                              rmm_land.cpp:270 (4)
    //         00485644     TEST       EAX,EAX
    //         00485646     JLE        LAB_0048568b
    //                              rmm_land.cpp:271 (8)
    //         00485648     CMP        EBX,EBP
    //         0048564a     MOV        dword ptr [ESP + x1],EBX
    //         0048564e     JG         LAB_0048568b
    //                              rmm_land.cpp:272 (55)
    //         00485650     FILD       dword ptr [ESP + index3]
    //         00485654     DEC        EAX
    //         00485655     MOV        dword ptr [ESP + Stack[-0xaf8]],EAX
    //         00485659     FSTP       float ptr [ESP + tile]
    //                               LAB_0048565d                                                 XREF[1]:     00485685(j)  
    //         0048565d     MOV        EAX,dword ptr [ESP + tile]
    //         00485661     MOV        this,dword ptr [ESP + x1]
    //         00485665     MOV        EDX,dword ptr [ESP + Stack[-0xaf8]]
    //         00485669     PUSH       0x0
    //         0048566b     PUSH       EAX
    //         0048566c     MOV        EAX,dword ptr [ESP + local_b08]
    //         00485670     PUSH       this
    //         00485671     PUSH       EDX
    //         00485672     PUSH       EAX
    //         00485673     MOV        this,ESI
    //         00485675     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         0048567a     MOV        EAX,dword ptr [ESP + x1]
    //         0048567e     INC        EAX
    //         0048567f     CMP        EAX,EBP
    //         00485681     MOV        dword ptr [ESP + x1],EAX
    //         00485685     JLE        LAB_0048565d
    //                              rmm_land.cpp:271 (4)
    //         00485687     MOV        EAX,dword ptr [ESP + terrain]
    //                               LAB_0048568b                                                 XREF[2]:     00485646(j), 0048564e(j)  
    //                              rmm_land.cpp:274 (4)
    //         0048568b     TEST       EBX,EBX
    //         0048568d     JLE        LAB_004856cc
    //                              rmm_land.cpp:275 (8)
    //         0048568f     CMP        EAX,EDI
    //         00485691     MOV        dword ptr [ESP + x1],EAX
    //         00485695     JG         LAB_004856cc
    //                              rmm_land.cpp:276 (49)
    //         00485697     FILD       dword ptr [ESP + index3]
    //         0048569b     FSTP       float ptr [ESP + tile]
    //                               LAB_0048569f                                                 XREF[1]:     004856c6(j)  
    //         0048569f     MOV        this,dword ptr [ESP + tile]
    //         004856a3     MOV        EDX,dword ptr [ESP + x1]
    //         004856a7     PUSH       0x0
    //         004856a9     LEA        EAX,[EBX + -0x1]
    //         004856ac     PUSH       this
    //         004856ad     PUSH       EAX
    //         004856ae     MOV        EAX,dword ptr [ESP + local_b08]
    //         004856b2     PUSH       EDX
    //         004856b3     PUSH       EAX
    //         004856b4     MOV        this,ESI
    //         004856b6     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         004856bb     MOV        EAX,dword ptr [ESP + x1]
    //         004856bf     INC        EAX
    //         004856c0     CMP        EAX,EDI
    //         004856c2     MOV        dword ptr [ESP + x1],EAX
    //         004856c6     JLE        LAB_0048569f
    //                              rmm_land.cpp:275 (4)
    //         004856c8     MOV        EAX,dword ptr [ESP + terrain]
    //                               LAB_004856cc                                                 XREF[2]:     0048568d(j), 00485695(j)  
    //                              rmm_land.cpp:278 (8)
    //         004856cc     MOV        this,dword ptr [ESI + 0x14]
    //         004856cf     DEC        this
    //         004856d0     CMP        EDI,this
    //         004856d2     JGE        LAB_00485701
    //                              rmm_land.cpp:279 (4)
    //         004856d4     CMP        EBX,EBP
    //         004856d6     JG         LAB_00485701
    //                              rmm_land.cpp:280 (37)
    //         004856d8     FILD       dword ptr [ESP + index3]
    //         004856dc     FSTP       float ptr [ESP + tile]
    //                               LAB_004856e0                                                 XREF[1]:     004856fb(j)  
    //         004856e0     MOV        EDX,dword ptr [ESP + tile]
    //         004856e4     PUSH       0x0
    //         004856e6     PUSH       EDX
    //         004856e7     LEA        EAX,[EDI + 0x1]
    //         004856ea     PUSH       EBX
    //         004856eb     PUSH       EAX
    //         004856ec     MOV        EAX,dword ptr [ESP + local_b08]
    //         004856f0     MOV        this,ESI
    //         004856f2     PUSH       EAX
    //         004856f3     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         004856f8     INC        EBX
    //         004856f9     CMP        EBX,EBP
    //         004856fb     JLE        LAB_004856e0
    //                              rmm_land.cpp:279 (4)
    //         004856fd     MOV        EAX,dword ptr [ESP + terrain]
    //                               LAB_00485701                                                 XREF[2]:     004856d2(j), 004856d6(j)  
    //                              rmm_land.cpp:282 (8)
    //         00485701     MOV        this,dword ptr [ESI + 0x18]
    //         00485704     DEC        this
    //         00485705     CMP        EBP,this
    //         00485707     JGE        LAB_00485732
    //                              rmm_land.cpp:283 (6)
    //         00485709     CMP        EAX,EDI
    //         0048570b     MOV        EBX,EAX
    //         0048570d     JG         LAB_00485732
    //                              rmm_land.cpp:284 (35)
    //         0048570f     FILD       dword ptr [ESP + index3]
    //         00485713     INC        EBP
    //         00485714     FSTP       float ptr [ESP + tile]
    //                               LAB_00485718                                                 XREF[1]:     00485730(j)  
    //         00485718     MOV        EDX,dword ptr [ESP + tile]
    //         0048571c     MOV        EAX,dword ptr [ESP + local_b08]
    //         00485720     PUSH       0x0
    //         00485722     PUSH       EDX
    //         00485723     PUSH       EBP
    //         00485724     PUSH       EBX
    //         00485725     PUSH       EAX
    //         00485726     MOV        this,ESI
    //         00485728     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         0048572d     INC        EBX
    //         0048572e     CMP        EBX,EDI
    //         00485730     JLE        LAB_00485718
    //                               LAB_00485732                                                 XREF[2]:     00485707(j), 0048570d(j)  
    //                              rmm_land.cpp:237 (56)
    //         00485732     MOV        EAX,dword ptr [ESP + index3]
    //         00485736     MOV        EBX,dword ptr [ESP + max_y]
    //         0048573a     MOV        EDI,dword ptr [ESP + index1]
    //         0048573e     MOV        EDX,dword ptr [ESP + local_b08]
    //         00485742     MOV        this,dword ptr [ESI + 0x144c]
    //         00485748     INC        EAX
    //         00485749     ADD        EBX,0x4
    //         0048574c     ADD        EDI,0x34
    //         0048574f     ADD        EDX,0x18
    //         00485752     CMP        EAX,this
    //         00485754     MOV        dword ptr [ESP + index3],EAX
    //         00485758     MOV        dword ptr [ESP + max_y],EBX
    //         0048575c     MOV        dword ptr [ESP + index1],EDI
    //         00485760     MOV        dword ptr [ESP + local_b08],EDX
    //         00485764     JL         LAB_0048556e
    //                               LAB_0048576a                                                 XREF[2]:     0048554c(j), 00485af7(j)  
    //                              rmm_land.cpp:293 (47)
    //         0048576a     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485770     XOR        EDI,EDI
    //         00485772     TEST       EAX,EAX
    //         00485774     MOV        byte ptr [ESP + local_af1],0x1
    //         00485779     MOV        dword ptr [ESP + index3],EDI
    //         0048577d     JLE        LAB_00485af1
    //         00485783     LEA        this=>land_size[1],[ESP + 0x4c]
    //         00485787     LEA        EDX=>stack[0].y,[ESP + 0x1d8]
    //         0048578e     MOV        dword ptr [ESP + index1],this
    //         00485792     MOV        dword ptr [ESP + local_b08],EDX
    //         00485796     LEA        EBP,[ESI + 0x4c]
    //                               LAB_00485799                                                 XREF[1]:     00485aeb(j)  
    //                              rmm_land.cpp:294 (21)
    //         00485799     MOV        EAX,dword ptr [ESP + index1]
    //         0048579d     MOV        this,dword ptr [EBP + -0x1c]
    //         004857a0     MOV        EAX=>land_size[1],dword ptr [EAX]
    //         004857a2     CMP        EAX,this
    //         004857a4     MOV        dword ptr [ESP + index2],EAX
    //         004857a8     JGE        LAB_00485ac5
    //                              rmm_land.cpp:295 (35)
    //         004857ae     LEA        this=>land_size,[ESP + 0x48]
    //         004857b2     LEA        EDX=>x,[ESP + 0x10]
    //         004857b6     PUSH       this
    //         004857b7     MOV        this,dword ptr [ESP + local_b08]
    //         004857bb     LEA        EAX=>local_b0c,[ESP + 0x18]
    //         004857bf     PUSH       EDX
    //         004857c0     PUSH       EAX
    //         004857c1     PUSH       this
    //         004857c2     MOV        this,ESI
    //         004857c4     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         004857c9     TEST       EAX,EAX
    //         004857cb     JZ         LAB_00485ac5
    //                              rmm_land.cpp:298 (28)
    //         004857d1     MOV        EDX,dword ptr [ESP + x]
    //         004857d5     MOV        EAX,dword ptr [ESP + local_b0c]
    //         004857d9     PUSH       EDI
    //         004857da     PUSH       EDX
    //         004857db     PUSH       EAX
    //         004857dc     MOV        this,ESI
    //         004857de     MOV        byte ptr [ESP + local_af1],0x0
    //         004857e3     CALL       RGE_RMM_Land_Generator::chance                   uchar chance(RGE_RMM_Land_Generator * this, l
    //         004857e8     AND        EAX,0xff
    //                              rmm_land.cpp:299 (48)
    //         004857ed     PUSH       0x12b
    //         004857f2     PUSH       s_C:\msdev\work\age1_x1\rmm_land.c               = "C:\\msdev\\work\\age1_x1\\rmm_land.cpp"
    //         004857f7     MOV        EBX,EAX
    //         004857f9     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004857fe     LEA        this,[EAX + EAX*0x4]
    //         00485801     MOV        EAX,0x80010003
    //         00485806     ADD        ESP,0x8
    //         00485809     LEA        this,[ECX + ECX*0x4]
    //         0048580c     SHL        this,0x2
    //         0048580f     IMUL       this
    //         00485811     ADD        EDX,this
    //         00485813     SAR        EDX,0xe
    //         00485816     MOV        this,EDX
    //         00485818     SHR        this,0x1f
    //         0048581b     ADD        EDX,this
    //                              rmm_land.cpp:300 (8)
    //         0048581d     CMP        EBX,EDX
    //         0048581f     JG         LAB_00485c32
    //                              rmm_land.cpp:302 (14)
    //         00485825     MOV        EDX,dword ptr [ESI + 0x10]
    //         00485828     MOV        EAX,dword ptr [ESP + local_b0c]
    //         0048582c     MOV        this,dword ptr [ESP + x]
    //         00485830     LEA        EBX,[EAX + EAX*0x2]
    //                              rmm_land.cpp:304 (32)
    //         00485833     PUSH       this
    //         00485834     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
    //         00485837     PUSH       EAX
    //         00485838     PUSH       EDI
    //         00485839     MOV        this,ESI
    //         0048583b     LEA        EDX,[EDX + EBX*0x8]
    //         0048583e     MOV        BL,byte ptr [EBP + -0x18]
    //         00485841     MOV        byte ptr [ESP + max_y],BL
    //         00485845     MOV        dword ptr [ESP + Stack[-0xaf8]],EDX
    //         00485849     MOV        EAX,dword ptr [ESP + max_y]
    //         0048584d     PUSH       EAX
    //         0048584e     CALL       RGE_RMM_Land_Generator::check_terrain_and_zone   uchar check_terrain_and_zone(RGE_RMM_Land_Gen
    //                              rmm_land.cpp:306 (48)
    //         00485853     MOV        this,dword ptr [ESI + 0x24]
    //         00485856     MOV        EDX,dword ptr [ESP + x]
    //         0048585a     AND        EAX,0xff
    //         0048585f     MOV        EDI,EAX
    //         00485861     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00485864     MOV        EDX,dword ptr [ESP + local_b0c]
    //         00485868     XOR        this,this
    //         0048586a     MOV        this,byte ptr [EAX + EDX*0x1]
    //         0048586d     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485873     CMP        this,EAX
    //         00485875     JNZ        LAB_00485ac1
    //         0048587b     TEST       EDI,EDI
    //         0048587d     JLE        LAB_00485ac1
    //                              rmm_land.cpp:308 (17)
    //         00485883     MOV        this,dword ptr [ESP + Stack[-0xaf8]]
    //         00485887     MOV        AL,byte ptr [ECX + this+0x5]
    //         0048588a     XOR        BL,AL
    //         0048588c     AND        BL,0x1f
    //         0048588f     XOR        BL,AL
    //         00485891     MOV        byte ptr [ECX + this+0x5],BL
    //                              rmm_land.cpp:309 (20)
    //         00485894     MOV        EAX,dword ptr [ESI + 0x24]
    //         00485897     MOV        this,dword ptr [ESP + x]
    //         0048589b     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
    //         0048589e     MOV        this,dword ptr [ESP + local_b0c]
    //         004858a2     MOV        AL,byte ptr [EBP + -0x4]
    //         004858a5     MOV        byte ptr [EDX + this->_padding_*0x1],AL
    //                              rmm_land.cpp:311 (38)
    //         004858a8     MOV        EAX,dword ptr [ESP + local_b0c]
    //         004858ac     TEST       EAX,EAX
    //         004858ae     JLE        LAB_00485935
    //         004858b4     MOV        EDX,dword ptr [ESI + 0x24]
    //         004858b7     MOV        this,dword ptr [ESP + x]
    //         004858bb     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
    //         004858be     XOR        this,this
    //         004858c0     MOV        this,byte ptr [EDX + EAX*0x1 + -0x1]
    //         004858c4     MOV        EDX,dword ptr [ESI + 0x144c]
    //         004858ca     CMP        this,EDX
    //         004858cc     JNZ        LAB_00485935
    //                              rmm_land.cpp:312 (107)
    //         004858ce     PUSH       0x138
    //         004858d3     PUSH       s_C:\msdev\work\age1_x1\rmm_land.c               = "C:\\msdev\\work\\age1_x1\\rmm_land.cpp"
    //         004858d8     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004858dd     LEA        EAX,[EAX + EAX*0x4]
    //         004858e0     ADD        ESP,0x8
    //         004858e3     MOV        EBX,dword ptr [ESP + local_b08]
    //         004858e7     LEA        this,[EAX + EAX*0x4]
    //         004858ea     MOV        EAX,0x80010003
    //         004858ef     SHL        this,0x2
    //         004858f2     IMUL       this
    //         004858f4     ADD        EDX,this
    //         004858f6     MOV        this,EDI
    //         004858f8     IMUL       this,dword ptr [EBP]
    //         004858fc     SAR        EDX,0xe
    //         004858ff     MOV        EAX,EDX
    //         00485901     PUSH       this
    //         00485902     SHR        EAX,0x1f
    //         00485905     ADD        EDX,EAX
    //         00485907     MOV        EAX,dword ptr [ESP + local_b0c]
    //         0048590b     SUB        EDX,this
    //         0048590d     MOV        this,ESI
    //         0048590f     ADD        EDX,0xfa
    //         00485915     DEC        EAX
    //         00485916     MOV        dword ptr [ESP + Stack[-0xaf8]],EDX
    //         0048591a     MOV        EDX,dword ptr [ESP + x]
    //         0048591e     FILD       dword ptr [ESP + Stack[-0xaf8]]
    //         00485922     FSTP       float ptr [ESP]=>local_b24
    //         00485925     PUSH       0x0
    //         00485927     PUSH       EDX
    //         00485928     PUSH       EAX
    //         00485929     PUSH       EBX
    //         0048592a     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         0048592f     MOV        EAX,dword ptr [ESP + local_b0c]
    //         00485933     JMP        LAB_00485939
    //                               LAB_00485935                                                 XREF[2]:     004858ae(j), 004858cc(j)  
    //         00485935     MOV        EBX,dword ptr [ESP + local_b08]
    //                               LAB_00485939                                                 XREF[1]:     00485933(j)  
    //                              rmm_land.cpp:314 (32)
    //         00485939     CMP        EAX,dword ptr [ESP + in_zone]
    //         0048593d     JGE        LAB_004859ba
    //         0048593f     MOV        this,dword ptr [ESI + 0x24]
    //         00485942     MOV        EDX,dword ptr [ESP + x]
    //         00485946     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00485949     XOR        EDX,EDX
    //         0048594b     MOV        DL,byte ptr [ECX + EAX*this+0x1 + 0x1]
    //         0048594f     MOV        this,dword ptr [ESI + 0x144c]
    //         00485955     CMP        EDX,this
    //         00485957     JNZ        LAB_004859ba
    //                              rmm_land.cpp:315 (97)
    //         00485959     PUSH       0x13b
    //         0048595e     PUSH       s_C:\msdev\work\age1_x1\rmm_land.c               = "C:\\msdev\\work\\age1_x1\\rmm_land.cpp"
    //         00485963     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00485968     LEA        EAX,[EAX + EAX*0x4]
    //         0048596b     ADD        ESP,0x8
    //         0048596e     LEA        this,[EAX + EAX*0x4]
    //         00485971     MOV        EAX,0x80010003
    //         00485976     SHL        this,0x2
    //         00485979     IMUL       this
    //         0048597b     ADD        EDX,this
    //         0048597d     MOV        this,EDI
    //         0048597f     IMUL       this,dword ptr [EBP]
    //         00485983     SAR        EDX,0xe
    //         00485986     MOV        EAX,EDX
    //         00485988     PUSH       this
    //         00485989     SHR        EAX,0x1f
    //         0048598c     ADD        EDX,EAX
    //         0048598e     MOV        EAX,dword ptr [ESP + local_b0c]
    //         00485992     SUB        EDX,this
    //         00485994     MOV        this,ESI
    //         00485996     ADD        EDX,0xfa
    //         0048599c     INC        EAX
    //         0048599d     MOV        dword ptr [ESP + Stack[-0xaf8]],EDX
    //         004859a1     MOV        EDX,dword ptr [ESP + x]
    //         004859a5     FILD       dword ptr [ESP + Stack[-0xaf8]]
    //         004859a9     FSTP       float ptr [ESP]=>local_b24
    //         004859ac     PUSH       0x0
    //         004859ae     PUSH       EDX
    //         004859af     PUSH       EAX
    //         004859b0     PUSH       EBX
    //         004859b1     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         004859b6     MOV        EAX,dword ptr [ESP + local_b0c]
    //                               LAB_004859ba                                                 XREF[2]:     0048593d(j), 00485957(j)  
    //                              rmm_land.cpp:317 (30)
    //         004859ba     MOV        this,dword ptr [ESP + x]
    //         004859be     TEST       this,this
    //         004859c0     JLE        LAB_00485a39
    //         004859c2     MOV        EDX,dword ptr [ESI + 0x24]
    //         004859c5     MOV        this,dword ptr [EDX + this->_padding_*0x4 + -0
    //         004859c9     XOR        EDX,EDX
    //         004859cb     MOV        DL,byte ptr [this->_padding_ + EAX*0x1]
    //         004859ce     MOV        this,dword ptr [ESI + 0x144c]
    //         004859d4     CMP        EDX,this
    //         004859d6     JNZ        LAB_00485a39
    //                              rmm_land.cpp:318 (97)
    //         004859d8     PUSH       0x13e
    //         004859dd     PUSH       s_C:\msdev\work\age1_x1\rmm_land.c               = "C:\\msdev\\work\\age1_x1\\rmm_land.cpp"
    //         004859e2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004859e7     LEA        EAX,[EAX + EAX*0x4]
    //         004859ea     ADD        ESP,0x8
    //         004859ed     LEA        this,[EAX + EAX*0x4]
    //         004859f0     MOV        EAX,0x80010003
    //         004859f5     SHL        this,0x2
    //         004859f8     IMUL       this
    //         004859fa     ADD        EDX,this
    //         004859fc     MOV        this,EDI
    //         004859fe     IMUL       this,dword ptr [EBP]
    //         00485a02     SAR        EDX,0xe
    //         00485a05     MOV        EAX,EDX
    //         00485a07     PUSH       this
    //         00485a08     SHR        EAX,0x1f
    //         00485a0b     ADD        EDX,EAX
    //         00485a0d     MOV        EAX,dword ptr [ESP + local_b0c]
    //         00485a11     SUB        EDX,this
    //         00485a13     MOV        this,ESI
    //         00485a15     ADD        EDX,0xfa
    //         00485a1b     MOV        dword ptr [ESP + Stack[-0xaf8]],EDX
    //         00485a1f     MOV        EDX,dword ptr [ESP + x]
    //         00485a23     FILD       dword ptr [ESP + Stack[-0xaf8]]
    //         00485a27     DEC        EDX
    //         00485a28     FSTP       float ptr [ESP]=>local_b24
    //         00485a2b     PUSH       0x0
    //         00485a2d     PUSH       EDX
    //         00485a2e     PUSH       EAX
    //         00485a2f     PUSH       EBX
    //         00485a30     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00485a35     MOV        EAX,dword ptr [ESP + local_b0c]
    //                               LAB_00485a39                                                 XREF[2]:     004859c0(j), 004859d6(j)  
    //                              rmm_land.cpp:320 (34)
    //         00485a39     MOV        this,dword ptr [ESP + x]
    //         00485a3d     MOV        EDX,dword ptr [ESP + max_x]
    //         00485a41     CMP        this,EDX
    //         00485a43     JGE        LAB_00485ab6
    //         00485a45     MOV        EDX,dword ptr [ESI + 0x24]
    //         00485a48     MOV        this,dword ptr [EDX + this->_padding_*0x4 + 0x4]
    //         00485a4c     XOR        EDX,EDX
    //         00485a4e     MOV        DL,byte ptr [this->_padding_ + EAX*0x1]
    //         00485a51     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485a57     CMP        EDX,EAX
    //         00485a59     JNZ        LAB_00485ab6
    //                              rmm_land.cpp:321 (91)
    //         00485a5b     PUSH       0x141
    //         00485a60     PUSH       s_C:\msdev\work\age1_x1\rmm_land.c               = "C:\\msdev\\work\\age1_x1\\rmm_land.cpp"
    //         00485a65     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00485a6a     IMUL       EDI,dword ptr [EBP]
    //         00485a6e     LEA        this,[EAX + EAX*0x4]
    //         00485a71     MOV        EAX,0x80010003
    //         00485a76     ADD        ESP,0x8
    //         00485a79     LEA        this,[ECX + ECX*0x4]
    //         00485a7c     SHL        this,0x2
    //         00485a7f     IMUL       this
    //         00485a81     ADD        EDX,this
    //         00485a83     PUSH       this
    //         00485a84     SAR        EDX,0xe
    //         00485a87     MOV        EAX,EDX
    //         00485a89     MOV        this,dword ptr [ESP + x]
    //         00485a8d     SHR        EAX,0x1f
    //         00485a90     ADD        EDX,EAX
    //         00485a92     SUB        EDX,EDI
    //         00485a94     ADD        EDX,0xfa
    //         00485a9a     INC        this
    //         00485a9b     MOV        dword ptr [ESP + Stack[-0xaf8]],EDX
    //         00485a9f     MOV        EDX,dword ptr [ESP + local_b0c]
    //         00485aa3     FILD       dword ptr [ESP + Stack[-0xaf8]]
    //         00485aa7     FSTP       float ptr [ESP]=>local_b24
    //         00485aaa     PUSH       0x0
    //         00485aac     PUSH       this
    //         00485aad     PUSH       EDX
    //         00485aae     PUSH       EBX
    //         00485aaf     MOV        this,ESI
    //         00485ab1     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_00485ab6                                                 XREF[2]:     00485a43(j), 00485a59(j)  
    //                              rmm_land.cpp:323 (11)
    //         00485ab6     MOV        EAX,dword ptr [ESP + index2]
    //         00485aba     MOV        this,dword ptr [ESP + index1]
    //         00485abe     INC        EAX
    //         00485abf     MOV        dword ptr [this->_padding_]=>land_size[1],EAX
    //                               LAB_00485ac1                                                 XREF[2]:     00485875(j), 0048587d(j)  
    //                              rmm_land.cpp:326 (4)
    //         00485ac1     MOV        EDI,dword ptr [ESP + index3]
    //                               LAB_00485ac5                                                 XREF[3]:     004857a8(j), 004857cb(j), 
    //                                                                                                         00485c44(j)  
    //                              rmm_land.cpp:293 (44)
    //         00485ac5     MOV        EDX,dword ptr [ESP + local_b08]
    //         00485ac9     MOV        this,dword ptr [ESP + index1]
    //         00485acd     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485ad3     INC        EDI
    //         00485ad4     ADD        EBP,0x34
    //         00485ad7     ADD        EDX,0x18
    //         00485ada     ADD        this,0x4
    //         00485add     CMP        EDI,EAX
    //         00485adf     MOV        dword ptr [ESP + index3],EDI
    //         00485ae3     MOV        dword ptr [ESP + local_b08],EDX
    //         00485ae7     MOV        dword ptr [ESP + index1],this
    //         00485aeb     JL         LAB_00485799
    //                               LAB_00485af1                                                 XREF[1]:     0048577d(j)  
    //                              rmm_land.cpp:290 (12)
    //         00485af1     MOV        AL,byte ptr [ESP + local_af1]
    //         00485af5     TEST       AL,AL
    //         00485af7     JZ         LAB_0048576a
    //                              rmm_land.cpp:333 (22)
    //         00485afd     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485b03     MOV        dword ptr [ESP + index3],0x0
    //         00485b0b     TEST       EAX,EAX
    //         00485b0d     JLE        LAB_00485bfc
    //                              rmm_land.cpp:353 (58)
    //         00485b13     LEA        EBP=>stack[0].y,[ESP + 0x1d8]
    //         00485b1a     LEA        EDI,[ESI + 0x48]
    //         00485b1d     MOV        dword ptr [ESP + index1],EBP
    //         00485b21     MOV        dword ptr [ESP + index2],EDI
    //                               LAB_00485b25                                                 XREF[1]:     00485bf6(j)  
    //         00485b25     MOV        AL,byte ptr [EDI + -0x14]
    //         00485b28     MOV        BL,byte ptr [EDI]
    //         00485b2a     LEA        this=>land_size,[ESP + 0x48]
    //         00485b2e     MOV        byte ptr [ESP + max_y],AL
    //         00485b32     LEA        EDX=>x,[ESP + 0x10]
    //         00485b36     PUSH       this
    //         00485b37     LEA        EAX=>local_b0c,[ESP + 0x18]
    //         00485b3b     PUSH       EDX
    //         00485b3c     PUSH       EAX
    //         00485b3d     PUSH       EBP
    //         00485b3e     MOV        this,ESI
    //         00485b40     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         00485b45     TEST       EAX,EAX
    //         00485b47     JZ         LAB_00485bd7
    //                               LAB_00485b4d                                                 XREF[1]:     00485bcd(j)  
    //                              rmm_land.cpp:339 (14)
    //         00485b4d     MOV        EDX,dword ptr [ESP + x]
    //         00485b51     MOV        this,dword ptr [ESI + 0x10]
    //         00485b54     MOV        EAX,dword ptr [ESP + local_b0c]
    //         00485b58     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //                              rmm_land.cpp:344 (68)
    //         00485b5b     CMP        EAX,0x1
    //         00485b5e     LEA        EDI,[EAX + EAX*0x2]
    //         00485b61     LEA        EDI,[this->_padding_ + EDI*0x8]
    //         00485b64     JL         LAB_00485b7e
    //         00485b66     MOV        this,dword ptr [ESI + 0x24]
    //         00485b69     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00485b6c     ADD        this,EAX
    //         00485b6e     CMP        byte ptr [this->_padding_ + -0x1],BL
    //         00485b71     JNZ        LAB_00485b7e
    //         00485b73     CMP        EAX,dword ptr [ESP + in_zone]
    //         00485b77     JGE        LAB_00485b7e
    //         00485b79     CMP        byte ptr [ECX + this+0x1],BL
    //         00485b7c     JZ         LAB_00485b9f
    //                               LAB_00485b7e                                                 XREF[3]:     00485b64(j), 00485b71(j), 
    //                                                                                                         00485b77(j)  
    //         00485b7e     CMP        EDX,0x1
    //         00485b81     JL         LAB_00485bb0
    //         00485b83     MOV        this,dword ptr [ESI + 0x24]
    //         00485b86     MOV        EBP,dword ptr [this->_padding_ + EDX*0x4 + -0x4]
    //         00485b8a     CMP        byte ptr [EBP + EAX*0x1],BL
    //         00485b8e     JNZ        LAB_00485bb0
    //         00485b90     CMP        EDX,dword ptr [ESP + max_x]
    //         00485b94     JGE        LAB_00485bb0
    //         00485b96     MOV        EDX,dword ptr [ECX + EDX*this->_padding_ + 0x4]
    //         00485b9a     CMP        byte ptr [EDX + EAX*0x1],BL
    //         00485b9d     JNZ        LAB_00485bb0
    //                               LAB_00485b9f                                                 XREF[1]:     00485b7c(j)  
    //                              rmm_land.cpp:345 (52)
    //         00485b9f     MOV        AL,byte ptr [EDI + 0x5]
    //         00485ba2     MOV        this,byte ptr [ESP + max_y]
    //         00485ba6     XOR        this,AL
    //         00485ba8     AND        this,0x1f
    //         00485bab     XOR        this,AL
    //         00485bad     MOV        byte ptr [EDI + 0x5],this
    //                               LAB_00485bb0                                                 XREF[4]:     00485b81(j), 00485b8e(j), 
    //                                                                                                         00485b94(j), 00485b9d(j)  
    //         00485bb0     MOV        EBP,dword ptr [ESP + index1]
    //         00485bb4     LEA        EDX=>land_size,[ESP + 0x48]
    //         00485bb8     LEA        EAX=>x,[ESP + 0x10]
    //         00485bbc     PUSH       EDX
    //         00485bbd     LEA        this=>local_b0c,[ESP + 0x18]
    //         00485bc1     PUSH       EAX
    //         00485bc2     PUSH       this
    //         00485bc3     PUSH       EBP
    //         00485bc4     MOV        this,ESI
    //         00485bc6     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         00485bcb     TEST       EAX,EAX
    //         00485bcd     JNZ        LAB_00485b4d
    //                              rmm_land.cpp:337 (4)
    //         00485bd3     MOV        EDI,dword ptr [ESP + index2]
    //                               LAB_00485bd7                                                 XREF[1]:     00485b47(j)  
    //                              rmm_land.cpp:333 (37)
    //         00485bd7     MOV        EAX,dword ptr [ESP + index3]
    //         00485bdb     MOV        this,dword ptr [ESI + 0x144c]
    //         00485be1     INC        EAX
    //         00485be2     ADD        EDI,0x34
    //         00485be5     ADD        EBP,0x18
    //         00485be8     CMP        EAX,this
    //         00485bea     MOV        dword ptr [ESP + index3],EAX
    //         00485bee     MOV        dword ptr [ESP + index2],EDI
    //         00485bf2     MOV        dword ptr [ESP + index1],EBP
    //         00485bf6     JL         LAB_00485b25
    //                               LAB_00485bfc                                                 XREF[1]:     00485b0d(j)  
    //                              rmm_land.cpp:349 (19)
    //         00485bfc     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485c02     XOR        EDI,EDI
    //         00485c04     TEST       EAX,EAX
    //         00485c06     JLE        LAB_00485c25
    //         00485c08     LEA        EBX=>stack[0].y,[ESP + 0x1d8]
    //                               LAB_00485c0f                                                 XREF[1]:     00485c23(j)  
    //                              rmm_land.cpp:350 (22)
    //         00485c0f     PUSH       EBX
    //         00485c10     MOV        this,ESI
    //         00485c12     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
    //         00485c17     MOV        EAX,dword ptr [ESI + 0x144c]
    //         00485c1d     INC        EDI
    //         00485c1e     ADD        EBX,0x18
    //         00485c21     CMP        EDI,EAX
    //         00485c23     JL         LAB_00485c0f
    //                               LAB_00485c25                                                 XREF[1]:     00485c06(j)  
    //                              rmm_land.cpp:353 (13)
    //         00485c25     POP        EDI
    //         00485c26     POP        ESI
    //         00485c27     POP        EBP
    //         00485c28     MOV        AL,0x1
    //         00485c2a     POP        EBX
    //         00485c2b     ADD        ESP,0xb10
    //         00485c31     RET
    //                               LAB_00485c32                                                 XREF[1]:     0048581f(j)  
    //                              rmm_land.cpp:327 (23)
    //         00485c32     MOV        EDX,dword ptr [ESI + 0x24]
    //         00485c35     MOV        EAX,dword ptr [ESP + x]
    //         00485c39     MOV        this,dword ptr [EDX + EAX*0x4]
    //         00485c3c     MOV        EDX,dword ptr [ESP + local_b0c]
    //         00485c40     MOV        byte ptr [this->_padding_ + EDX*0x1],0xff
    //         00485c44     JMP        LAB_00485ac5
}

