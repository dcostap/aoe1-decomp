// Auto-generated scaffold unit: map.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/map.cpp
#include "../include/common.h"

// Offset: 0x00455000
undefined RGE_Map(RGE_Map* this_, int param_2, RGE_Sound** param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Map::RGE_Map(int,class RGE_Sound * *,unsigned char)                            *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Map(RGE_Map * this, int param_1, RGE_Sound 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00455002(R)  
    //              RGE_Sound * *     Stack[0x8]:4   param_2                   XREF[1]:     00455029(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00455068(R)  
    //                               ??0RGE_Map@@QAE@HPAPAVRGE_Sound@@E@Z                         XREF[2]:     TRIBE_Map:0050f43c(c), 
    //                               RGE_Map::RGE_Map                                                          map_init:00541c63(c)  
    //                              map.cpp:39 (2)
    //         00455000     PUSH       EBX
    //         00455001     PUSH       EBP
    //                              map.cpp:42 (34)
    //         00455002     MOV        EBP,dword ptr [ESP + param_1]
    //         00455006     PUSH       ESI
    //         00455007     PUSH       EDI
    //         00455008     MOV        ESI,this
    //         0045500a     PUSH       0x8dd0
    //         0045500f     XOR        EBX,EBX
    //         00455011     PUSH       ESI
    //         00455012     PUSH       EBP
    //         00455013     MOV        dword ptr [ESI],RGE_Map::`vftable'               = 00455080
    //         00455019     MOV        dword ptr [ESI + 0x8dc4],EBX
    //         0045501f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              map.cpp:44 (5)
    //         00455024     MOV        EAX,[rge_base_game]                              = 00000000
    //                              map.cpp:51 (48)
    //         00455029     MOV        EDI,dword ptr [ESP + param_2]
    //         0045502d     ADD        ESP,0xc
    //         00455030     MOV        this,dword ptr [EAX + 0x3f4]
    //         00455036     MOV        dword ptr [ESI + 0x4],EBX
    //         00455039     MOV        dword ptr [ESI + 0x8dc0],this
    //         0045503f     PUSH       EDI
    //         00455040     MOV        this,ESI
    //         00455042     MOV        dword ptr [ESI + 0x8db0],EBX
    //         00455048     MOV        dword ptr [ESI + 0x8d8c],EBX
    //         0045504e     MOV        dword ptr [ESI + 0x8db4],EBX
    //         00455054     CALL       RGE_Map::load_terrain_types                      void load_terrain_types(RGE_Map * this, RGE_S
    //                              map.cpp:52 (8)
    //         00455059     PUSH       EDI
    //         0045505a     MOV        this,ESI
    //         0045505c     CALL       RGE_Map::load_border_types                       void load_border_types(RGE_Map * this, RGE_So
    //                              map.cpp:53 (7)
    //         00455061     MOV        this,ESI
    //         00455063     CALL       RGE_Map::init_tile_sizes                         void init_tile_sizes(RGE_Map * this)
    //                              map.cpp:55 (6)
    //         00455068     CMP        byte ptr [ESP + param_3],BL
    //         0045506c     JZ         LAB_00455076
    //                              map.cpp:57 (8)
    //         0045506e     PUSH       EBP
    //         0045506f     MOV        this,ESI
    //         00455071     CALL       RGE_Map::data_load_random_map                    void data_load_random_map(RGE_Map * this, int
    //                               LAB_00455076                                                 XREF[1]:     0045506c(j)  
    //                              map.cpp:61 (9)
    //         00455076     MOV        EAX,ESI
    //         00455078     POP        EDI
    //         00455079     POP        ESI
    //         0045507a     POP        EBP
    //         0045507b     POP        EBX
    //         0045507c     RET        0xc
}

// Offset: 0x004550A0
undefined RGE_Map(RGE_Map* this_, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Map::RGE_Map(char *,char *,char *,short,short,short,class RGE_Sound * *)       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Map(RGE_Map * this, char * param_1, char * 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004553ef(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     004553e2(R)  
    //              char *            Stack[0xc]:4   param_3
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     004550d1(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[1]:     004550bf(R)  
    //              short             Stack[0x18]:2  param_6                   XREF[1]:     004550f2(R)  
    //              RGE_Sound * *     Stack[0x1c]:4  param_7                   XREF[1]:     004553de(R)  
    //                               ??0RGE_Map@@QAE@PAD00FFFPAPAVRGE_Sound@@@Z                   XREF[2]:     TRIBE_Map:0050f788(c), 
    //                               RGE_Map::RGE_Map                                                          data_load_map:0054155b(c)  
    //                              map.cpp:67 (5)
    //         004550a0     PUSH       EBX
    //         004550a1     PUSH       EBP
    //         004550a2     PUSH       ESI
    //         004550a3     MOV        ESI,this
    //                              map.cpp:72 (15)
    //         004550a5     XOR        EBX,EBX
    //         004550a7     PUSH       EDI
    //         004550a8     MOV        dword ptr [ESI],RGE_Map::`vftable'               = 00455080
    //         004550ae     MOV        dword ptr [ESI + 0x8dc4],EBX
    //                              map.cpp:73 (6)
    //         004550b4     MOV        dword ptr [ESI + 0x8dbc],EBX
    //                              map.cpp:75 (5)
    //         004550ba     MOV        EAX,[rge_base_game]                              = 00000000
    //                              map.cpp:79 (4)
    //         004550bf     MOV        EDI,dword ptr [ESP + param_5]
    //                              map.cpp:91 (95)
    //         004550c3     PUSH       EBX
    //         004550c4     MOV        this,dword ptr [EAX + 0x3f4]
    //         004550ca     PUSH       EDI
    //         004550cb     MOV        dword ptr [ESI + 0x8dc0],this
    //         004550d1     MOV        this,dword ptr [ESP + param_4]
    //         004550d5     MOVSX      EAX,this
    //         004550d8     CDQ
    //         004550d9     SUB        EAX,EDX
    //         004550db     MOV        word ptr [ESI + 0x8d96],this
    //         004550e2     SAR        EAX,0x1
    //         004550e4     MOV        word ptr [ESI + 0x8d9c],AX
    //         004550eb     PUSH       this
    //         004550ec     MOVSX      EAX,DI
    //         004550ef     CDQ
    //         004550f0     SUB        EAX,EDX
    //         004550f2     MOV        DX,word ptr [ESP + param_6]
    //         004550f7     SAR        EAX,0x1
    //         004550f9     PUSH       EBX
    //         004550fa     MOV        this,ESI
    //         004550fc     MOV        word ptr [ESI + 0x8d98],DI
    //         00455103     MOV        word ptr [ESI + 0x8d9a],AX
    //         0045510a     MOV        word ptr [ESI + 0x8d9e],DX
    //         00455111     MOV        dword ptr [ESI + 0x8],EBX
    //         00455114     MOV        dword ptr [ESI + 0xc],EBX
    //         00455117     MOV        dword ptr [ESI + 0x10],EBX
    //         0045511a     MOV        dword ptr [ESI + 0x14],EBX
    //         0045511d     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:92 (27)
    //         00455122     MOV        AX,word ptr [ESI + 0x8d9e]
    //         00455129     MOV        this,word ptr [ESI + 0x8d96]
    //         00455130     PUSH       -0x64
    //         00455132     PUSH       EAX
    //         00455133     PUSH       this
    //         00455134     PUSH       0x1
    //         00455136     MOV        this,ESI
    //         00455138     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:93 (34)
    //         0045513d     MOV        DX,word ptr [ESI + 0x8d9e]
    //         00455144     MOV        AX,word ptr [ESI + 0x8d96]
    //         0045514b     ADD        DX,word ptr [ESI + 0x8d98]
    //         00455152     PUSH       0x64
    //         00455154     MOV        this,ESI
    //         00455156     PUSH       EDX
    //         00455157     PUSH       EAX
    //         00455158     PUSH       0x2
    //         0045515a     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:94 (27)
    //         0045515f     MOV        this,word ptr [ESI + 0x8d98]
    //         00455166     MOV        DX,word ptr [ESI + 0x8d96]
    //         0045516d     PUSH       -0x64
    //         0045516f     PUSH       this
    //         00455170     PUSH       EDX
    //         00455171     PUSH       0x3
    //         00455173     MOV        this,ESI
    //         00455175     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:95 (27)
    //         0045517a     MOV        AX,word ptr [ESI + 0x8d98]
    //         00455181     MOV        this,word ptr [ESI + 0x8d96]
    //         00455188     PUSH       -0x64
    //         0045518a     PUSH       EAX
    //         0045518b     PUSH       this
    //         0045518c     PUSH       0x4
    //         0045518e     MOV        this,ESI
    //         00455190     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:96 (27)
    //         00455195     MOV        DX,word ptr [ESI + 0x8d9e]
    //         0045519c     MOV        AX,word ptr [ESI + 0x8d96]
    //         004551a3     PUSH       -0x64
    //         004551a5     PUSH       EDX
    //         004551a6     PUSH       EAX
    //         004551a7     PUSH       0x5
    //         004551a9     MOV        this,ESI
    //         004551ab     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:97 (34)
    //         004551b0     MOV        this,word ptr [ESI + 0x8d9e]
    //         004551b7     PUSH       0x64
    //         004551b9     ADD        this,word ptr [ESI + 0x8d98]
    //         004551c0     MOV        DX,word ptr [ESI + 0x8d96]
    //         004551c7     PUSH       this
    //         004551c8     PUSH       EDX
    //         004551c9     PUSH       0x6
    //         004551cb     MOV        this,ESI
    //         004551cd     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:98 (27)
    //         004551d2     MOV        AX,word ptr [ESI + 0x8d9e]
    //         004551d9     MOV        this,word ptr [ESI + 0x8d96]
    //         004551e0     PUSH       -0x64
    //         004551e2     PUSH       EAX
    //         004551e3     PUSH       this
    //         004551e4     PUSH       0x7
    //         004551e6     MOV        this,ESI
    //         004551e8     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:99 (34)
    //         004551ed     MOV        DX,word ptr [ESI + 0x8d9e]
    //         004551f4     MOV        AX,word ptr [ESI + 0x8d96]
    //         004551fb     ADD        DX,word ptr [ESI + 0x8d98]
    //         00455202     PUSH       0x64
    //         00455204     MOV        this,ESI
    //         00455206     PUSH       EDX
    //         00455207     PUSH       EAX
    //         00455208     PUSH       0x8
    //         0045520a     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:100 (27)
    //         0045520f     MOV        this,word ptr [ESI + 0x8d9e]
    //         00455216     MOV        DX,word ptr [ESI + 0x8d96]
    //         0045521d     PUSH       -0x64
    //         0045521f     PUSH       this
    //         00455220     PUSH       EDX
    //         00455221     PUSH       0x9
    //         00455223     MOV        this,ESI
    //         00455225     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:101 (34)
    //         0045522a     MOV        AX,word ptr [ESI + 0x8d9e]
    //         00455231     MOV        this,word ptr [ESI + 0x8d96]
    //         00455238     ADD        AX,word ptr [ESI + 0x8d98]
    //         0045523f     PUSH       0x64
    //         00455241     PUSH       EAX
    //         00455242     PUSH       this
    //         00455243     PUSH       0xa
    //         00455245     MOV        this,ESI
    //         00455247     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:102 (27)
    //         0045524c     MOV        DX,word ptr [ESI + 0x8d98]
    //         00455253     MOV        AX,word ptr [ESI + 0x8d96]
    //         0045525a     PUSH       -0x64
    //         0045525c     PUSH       EDX
    //         0045525d     PUSH       EAX
    //         0045525e     PUSH       0xb
    //         00455260     MOV        this,ESI
    //         00455262     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:103 (27)
    //         00455267     MOV        this,word ptr [ESI + 0x8d98]
    //         0045526e     MOV        DX,word ptr [ESI + 0x8d96]
    //         00455275     PUSH       -0x64
    //         00455277     PUSH       this
    //         00455278     PUSH       EDX
    //         00455279     PUSH       0xc
    //         0045527b     MOV        this,ESI
    //         0045527d     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:104 (27)
    //         00455282     MOV        AX,word ptr [ESI + 0x8d9e]
    //         00455289     MOV        this,word ptr [ESI + 0x8d96]
    //         00455290     PUSH       -0x64
    //         00455292     PUSH       EAX
    //         00455293     PUSH       this
    //         00455294     PUSH       0xd
    //         00455296     MOV        this,ESI
    //         00455298     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:105 (34)
    //         0045529d     MOV        DX,word ptr [ESI + 0x8d9e]
    //         004552a4     MOV        AX,word ptr [ESI + 0x8d96]
    //         004552ab     ADD        DX,word ptr [ESI + 0x8d98]
    //         004552b2     PUSH       0x64
    //         004552b4     MOV        this,ESI
    //         004552b6     PUSH       EDX
    //         004552b7     PUSH       EAX
    //         004552b8     PUSH       0xe
    //         004552ba     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:106 (27)
    //         004552bf     MOV        this,word ptr [ESI + 0x8d98]
    //         004552c6     MOV        DX,word ptr [ESI + 0x8d96]
    //         004552cd     PUSH       0x64
    //         004552cf     PUSH       this
    //         004552d0     PUSH       EDX
    //         004552d1     PUSH       0xf
    //         004552d3     MOV        this,ESI
    //         004552d5     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:107 (27)
    //         004552da     MOV        AX,word ptr [ESI + 0x8d98]
    //         004552e1     MOV        this,word ptr [ESI + 0x8d96]
    //         004552e8     PUSH       0x64
    //         004552ea     PUSH       EAX
    //         004552eb     PUSH       this
    //         004552ec     PUSH       0x10
    //         004552ee     MOV        this,ESI
    //         004552f0     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:108 (26)
    //         004552f5     MOV        DX,word ptr [ESI + 0x8d98]
    //         004552fc     MOV        AX,word ptr [ESI + 0x8d9c]
    //         00455303     PUSH       EBX
    //         00455304     PUSH       EDX
    //         00455305     PUSH       EAX
    //         00455306     PUSH       0x11
    //         00455308     MOV        this,ESI
    //         0045530a     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:109 (26)
    //         0045530f     MOV        this,word ptr [ESI + 0x8d98]
    //         00455316     MOV        DX,word ptr [ESI + 0x8d9c]
    //         0045531d     PUSH       EBX
    //         0045531e     PUSH       this
    //         0045531f     PUSH       EDX
    //         00455320     PUSH       0x12
    //         00455322     MOV        this,ESI
    //         00455324     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:111 (7)
    //         00455329     MOV        word ptr [ESI + 0x8da0],BX
    //                              map.cpp:112 (7)
    //         00455330     MOV        word ptr [ESI + 0x8da2],BX
    //                              map.cpp:114 (7)
    //         00455337     MOV        word ptr [ESI + 0x8d90],BX
    //                              map.cpp:115 (7)
    //         0045533e     MOV        word ptr [ESI + 0x8d94],BX
    //                              map.cpp:116 (7)
    //         00455345     MOV        word ptr [ESI + 0x8da4],BX
    //                              map.cpp:117 (7)
    //         0045534c     MOV        word ptr [ESI + 0x8da6],BX
    //                              map.cpp:118 (7)
    //         00455353     MOV        word ptr [ESI + 0x8da8],BX
    //                              map.cpp:119 (7)
    //         0045535a     MOV        word ptr [ESI + 0x8daa],BX
    //                              map.cpp:120 (6)
    //         00455361     MOV        byte ptr [ESI + 0x8dac],BL
    //                              map.cpp:122 (6)
    //         00455367     MOV        byte ptr [ESI + 0x8db8],BL
    //                              map.cpp:123 (18)
    //         0045536d     MOV        byte ptr [ESI + 0x8db9],0x1
    //         00455374     LEA        EDX,[ESI + 0x146]
    //         0045537a     MOV        EBP,0x20
    //                               LAB_0045537f                                                 XREF[1]:     004553c4(j)  
    //                              map.cpp:129 (7)
    //         0045537f     MOV        word ptr [EDX + 0xda],BX
    //                              map.cpp:130 (3)
    //         00455386     MOV        word ptr [EDX],BX
    //                              map.cpp:131 (15)
    //         00455389     MOV        word ptr [EDX + 0x2],BX
    //         0045538d     LEA        EAX,[EDX + 0x80]
    //         00455393     MOV        this,0x1e
    //                               LAB_00455398                                                 XREF[1]:     004553a3(j)  
    //                              map.cpp:134 (4)
    //         00455398     MOV        word ptr [EAX + -0x3c],BX
    //                              map.cpp:135 (9)
    //         0045539c     MOV        word ptr [EAX],BX
    //         0045539f     ADD        EAX,0x2
    //         004553a2     DEC        this
    //         004553a3     JNZ        LAB_00455398
    //                              map.cpp:138 (18)
    //         004553a5     MOV        this,0x10
    //         004553aa     XOR        EAX,EAX
    //         004553ac     LEA        EDI,[EDX + 0x4]
    //         004553af     ADD        EDX,0x198
    //         004553b5     STOSD.REP  ES:EDI
    //                              map.cpp:139 (6)
    //         004553b7     MOV        dword ptr [EDX + 0xfffffdce],EBX
    //                              map.cpp:140 (9)
    //         004553bd     MOV        dword ptr [EDX + 0xfffffdd2],EBX
    //         004553c3     DEC        EBP
    //         004553c4     JNZ        LAB_0045537f
    //                              map.cpp:164 (96)
    //         004553c6     LEA        EAX,[ESI + 0x8810]
    //         004553cc     MOV        this,0x10
    //                               LAB_004553d1                                                 XREF[1]:     004553dc(j)  
    //         004553d1     MOV        dword ptr [EAX + -0x4],EBX
    //         004553d4     MOV        dword ptr [EAX],EBX
    //         004553d6     SUB        EAX,0x5a0
    //         004553db     DEC        this
    //         004553dc     JNZ        LAB_004553d1
    //         004553de     MOV        EDI,dword ptr [ESP + param_7]
    //         004553e2     MOV        EAX,dword ptr [ESP + param_2]
    //         004553e6     PUSH       EDI
    //         004553e7     PUSH       EAX
    //         004553e8     MOV        this,ESI
    //         004553ea     CALL       RGE_Map::load_terrain_types                      void load_terrain_types(RGE_Map * this, char 
    //         004553ef     MOV        this,dword ptr [ESP + param_1]
    //         004553f3     PUSH       EDI
    //         004553f4     PUSH       this
    //         004553f5     MOV        this,ESI
    //         004553f7     CALL       RGE_Map::load_border_types                       void load_border_types(RGE_Map * this, char *
    //         004553fc     MOV        dword ptr [ESI + 0x4],EBX
    //         004553ff     MOV        dword ptr [ESI + 0x8db0],EBX
    //         00455405     MOV        dword ptr [ESI + 0x8d8c],EBX
    //         0045540b     MOV        dword ptr [ESI + 0x8db4],EBX
    //         00455411     MOV        dword ptr [ESI + 0x8dc8],EBX
    //         00455417     MOV        dword ptr [ESI + 0x8dcc],EBX
    //         0045541d     MOV        EAX,ESI
    //         0045541f     POP        EDI
    //         00455420     POP        ESI
    //         00455421     POP        EBP
    //         00455422     POP        EBX
    //         00455423     RET        0x1c
}

// Offset: 0x00455430
void RGE_Map(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Map::~RGE_Map(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Map(RGE_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ??1RGE_Map@@UAE@XZ                                           XREF[2]:     `vector_deleting_destructor':00455
    //                               RGE_Map::~RGE_Map                                                         ~TRIBE_Map:0050f7a6(c)  
    //                              map.cpp:169 (6)
    //         00455430     PUSH       EBX
    //         00455431     PUSH       EBP
    //         00455432     MOV        EBP,this
    //         00455434     PUSH       ESI
    //         00455435     PUSH       EDI
    //                              map.cpp:172 (19)
    //         00455436     XOR        EDI,EDI
    //         00455438     MOV        ESI,dword ptr [EBP + 0x8dc4]
    //         0045543e     MOV        dword ptr [EBP],RGE_Map::`vftable'               = 00455080
    //         00455445     CMP        ESI,EDI
    //         00455447     JZ         LAB_0045545f
    //                              map.cpp:174 (16)
    //         00455449     MOV        this,ESI
    //         0045544b     CALL       RGE_Zone_Map_List::~RGE_Zone_Map_List            void ~RGE_Zone_Map_List(RGE_Zone_Map_List * t
    //         00455450     PUSH       ESI
    //         00455451     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455456     ADD        ESP,0x4
    //                              map.cpp:175 (6)
    //         00455459     MOV        dword ptr [EBP + 0x8dc4],EDI
    //                               LAB_0045545f                                                 XREF[1]:     00455447(j)  
    //                              map.cpp:178 (10)
    //         0045545f     MOV        ESI,dword ptr [EBP + 0x8dbc]
    //         00455465     CMP        ESI,EDI
    //         00455467     JZ         LAB_0045547f
    //                              map.cpp:180 (16)
    //         00455469     MOV        this,ESI
    //         0045546b     CALL       RGE_RMM_Database_Controller::~RGE_RMM_Database   void ~RGE_RMM_Database_Controller(RGE_RMM_Dat
    //         00455470     PUSH       ESI
    //         00455471     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455476     ADD        ESP,0x4
    //                              map.cpp:181 (6)
    //         00455479     MOV        dword ptr [EBP + 0x8dbc],EDI
    //                               LAB_0045547f                                                 XREF[1]:     00455467(j)  
    //                              map.cpp:184 (7)
    //         0045547f     MOV        EAX,dword ptr [EBP + 0x4]
    //         00455482     CMP        EAX,EDI
    //         00455484     JZ         LAB_0045548f
    //                              map.cpp:185 (9)
    //         00455486     PUSH       EAX
    //         00455487     CALL       free                                             undefined free()
    //         0045548c     ADD        ESP,0x4
    //                               LAB_0045548f                                                 XREF[1]:     00455484(j)  
    //                              map.cpp:187 (10)
    //         0045548f     MOV        EAX,dword ptr [EBP + 0x8db0]
    //         00455495     CMP        EAX,EDI
    //         00455497     JZ         LAB_004554a2
    //                              map.cpp:188 (9)
    //         00455499     PUSH       EAX
    //         0045549a     CALL       free                                             undefined free()
    //         0045549f     ADD        ESP,0x4
    //                               LAB_004554a2                                                 XREF[1]:     00455497(j)  
    //                              map.cpp:190 (10)
    //         004554a2     MOV        EAX,dword ptr [EBP + 0x8d8c]
    //         004554a8     CMP        EAX,EDI
    //         004554aa     JZ         LAB_004554b5
    //                              map.cpp:191 (9)
    //         004554ac     PUSH       EAX
    //         004554ad     CALL       free                                             undefined free()
    //         004554b2     ADD        ESP,0x4
    //                               LAB_004554b5                                                 XREF[1]:     004554aa(j)  
    //                              map.cpp:193 (10)
    //         004554b5     MOV        EAX,dword ptr [EBP + 0x8db4]
    //         004554bb     CMP        EAX,EDI
    //         004554bd     JZ         LAB_004554c8
    //                              map.cpp:194 (9)
    //         004554bf     PUSH       EAX
    //         004554c0     CALL       free                                             undefined free()
    //         004554c5     ADD        ESP,0x4
    //                               LAB_004554c8                                                 XREF[1]:     004554bd(j)  
    //                              map.cpp:197 (11)
    //         004554c8     LEA        EDI,[EBP + 0x3214]
    //         004554ce     MOV        EBX,0x20
    //                               LAB_004554d3                                                 XREF[1]:     004554f6(j)  
    //                              map.cpp:198 (6)
    //         004554d3     MOV        ESI,dword ptr [EDI]
    //         004554d5     TEST       ESI,ESI
    //         004554d7     JZ         LAB_004554ef
    //                              map.cpp:200 (16)
    //         004554d9     MOV        this,ESI
    //         004554db     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         004554e0     PUSH       ESI
    //         004554e1     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004554e6     ADD        ESP,0x4
    //                              map.cpp:201 (15)
    //         004554e9     MOV        dword ptr [EDI],0x0
    //                               LAB_004554ef                                                 XREF[1]:     004554d7(j)  
    //         004554ef     SUB        EDI,0x198
    //         004554f5     DEC        EBX
    //         004554f6     JNZ        LAB_004554d3
    //                              map.cpp:215 (105)
    //         004554f8     LEA        EDI,[EBP + 0x880c]
    //         004554fe     MOV        EBX,0x10
    //                               LAB_00455503                                                 XREF[1]:     00455526(j)  
    //         00455503     MOV        ESI,dword ptr [EDI]
    //         00455505     TEST       ESI,ESI
    //         00455507     JZ         LAB_0045551f
    //         00455509     MOV        this,ESI
    //         0045550b     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00455510     PUSH       ESI
    //         00455511     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455516     ADD        ESP,0x4
    //         00455519     MOV        dword ptr [EDI],0x0
    //                               LAB_0045551f                                                 XREF[1]:     00455507(j)  
    //         0045551f     SUB        EDI,0x5a0
    //         00455525     DEC        EBX
    //         00455526     JNZ        LAB_00455503
    //         00455528     MOV        ESI,dword ptr [EBP + 0x8dc8]
    //         0045552e     TEST       ESI,ESI
    //         00455530     JZ         LAB_00455542
    //         00455532     MOV        this,ESI
    //         00455534     CALL       RGE_Unified_Visible_Map::~RGE_Unified_Visible_   void ~RGE_Unified_Visible_Map(RGE_Unified_Vis
    //         00455539     PUSH       ESI
    //         0045553a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045553f     ADD        ESP,0x4
    //                               LAB_00455542                                                 XREF[1]:     00455530(j)  
    //         00455542     MOV        ESI,dword ptr [EBP + 0x8dcc]
    //         00455548     TEST       ESI,ESI
    //         0045554a     JZ         LAB_0045555c
    //         0045554c     MOV        this,ESI
    //         0045554e     CALL       Visible_Unit_Manager::~Visible_Unit_Manager      void ~Visible_Unit_Manager(Visible_Unit_Manag
    //         00455553     PUSH       ESI
    //         00455554     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455559     ADD        ESP,0x4
    //                               LAB_0045555c                                                 XREF[1]:     0045554a(j)  
    //         0045555c     POP        EDI
    //         0045555d     POP        ESI
    //         0045555e     POP        EBP
    //         0045555f     POP        EBX
    //         00455560     RET
}

// Offset: 0x00455570
void init_tile_sizes(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::init_tile_sizes(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall init_tile_sizes(RGE_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ?init_tile_sizes@RGE_Map@@QAEXXZ                             XREF[1]:     RGE_Map:00455063(c)  
    //                               RGE_Map::init_tile_sizes
    //                              map.cpp:220 (1)
    //         00455570     PUSH       ESI
    //                              map.cpp:224 (5)
    //         00455571     MOV        EAX,0x20
    //                              map.cpp:231 (55)
    //         00455576     PUSH       0x0
    //         00455578     MOV        ESI,this
    //         0045557a     PUSH       EAX
    //         0045557b     PUSH       0x40
    //         0045557d     PUSH       0x0
    //         0045557f     MOV        word ptr [ESI + 0x8d96],0x40
    //         00455588     MOV        word ptr [ESI + 0x8d98],AX
    //         0045558f     MOV        word ptr [ESI + 0x8d9c],AX
    //         00455596     MOV        word ptr [ESI + 0x8d9a],0x10
    //         0045559f     MOV        word ptr [ESI + 0x8d9e],0x10
    //         004555a8     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:232 (27)
    //         004555ad     MOV        AX,word ptr [ESI + 0x8d9e]
    //         004555b4     MOV        this,word ptr [ESI + 0x8d96]
    //         004555bb     PUSH       DAT_fffffff8
    //         004555bd     PUSH       EAX
    //         004555be     PUSH       this
    //         004555bf     PUSH       0x1
    //         004555c1     MOV        this,ESI
    //         004555c3     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:233 (34)
    //         004555c8     MOV        DX,word ptr [ESI + 0x8d9e]
    //         004555cf     MOV        AX,word ptr [ESI + 0x8d96]
    //         004555d6     ADD        DX,word ptr [ESI + 0x8d98]
    //         004555dd     PUSH       0x8
    //         004555df     MOV        this,ESI
    //         004555e1     PUSH       EDX
    //         004555e2     PUSH       EAX
    //         004555e3     PUSH       0x2
    //         004555e5     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:234 (27)
    //         004555ea     MOV        this,word ptr [ESI + 0x8d98]
    //         004555f1     MOV        DX,word ptr [ESI + 0x8d96]
    //         004555f8     PUSH       DAT_fffffff8
    //         004555fa     PUSH       this
    //         004555fb     PUSH       EDX
    //         004555fc     PUSH       0x3
    //         004555fe     MOV        this,ESI
    //         00455600     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:235 (27)
    //         00455605     MOV        AX,word ptr [ESI + 0x8d98]
    //         0045560c     MOV        this,word ptr [ESI + 0x8d96]
    //         00455613     PUSH       DAT_fffffff8
    //         00455615     PUSH       EAX
    //         00455616     PUSH       this
    //         00455617     PUSH       0x4
    //         00455619     MOV        this,ESI
    //         0045561b     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:236 (27)
    //         00455620     MOV        DX,word ptr [ESI + 0x8d9e]
    //         00455627     MOV        AX,word ptr [ESI + 0x8d96]
    //         0045562e     PUSH       DAT_fffffff8
    //         00455630     PUSH       EDX
    //         00455631     PUSH       EAX
    //         00455632     PUSH       0x5
    //         00455634     MOV        this,ESI
    //         00455636     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:237 (34)
    //         0045563b     MOV        this,word ptr [ESI + 0x8d9e]
    //         00455642     MOV        DX,word ptr [ESI + 0x8d96]
    //         00455649     ADD        this,word ptr [ESI + 0x8d98]
    //         00455650     PUSH       0x8
    //         00455652     PUSH       this
    //         00455653     PUSH       EDX
    //         00455654     PUSH       0x6
    //         00455656     MOV        this,ESI
    //         00455658     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:238 (27)
    //         0045565d     MOV        AX,word ptr [ESI + 0x8d9e]
    //         00455664     MOV        this,word ptr [ESI + 0x8d96]
    //         0045566b     PUSH       DAT_fffffff8
    //         0045566d     PUSH       EAX
    //         0045566e     PUSH       this
    //         0045566f     PUSH       0x7
    //         00455671     MOV        this,ESI
    //         00455673     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:239 (34)
    //         00455678     MOV        DX,word ptr [ESI + 0x8d9e]
    //         0045567f     MOV        AX,word ptr [ESI + 0x8d96]
    //         00455686     ADD        DX,word ptr [ESI + 0x8d98]
    //         0045568d     PUSH       0x8
    //         0045568f     MOV        this,ESI
    //         00455691     PUSH       EDX
    //         00455692     PUSH       EAX
    //         00455693     PUSH       0x8
    //         00455695     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:240 (27)
    //         0045569a     PUSH       DAT_fffffff8
    //         0045569c     MOV        this,word ptr [ESI + 0x8d9e]
    //         004556a3     MOV        DX,word ptr [ESI + 0x8d96]
    //         004556aa     PUSH       this
    //         004556ab     PUSH       EDX
    //         004556ac     PUSH       0x9
    //         004556ae     MOV        this,ESI
    //         004556b0     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:241 (34)
    //         004556b5     MOV        AX,word ptr [ESI + 0x8d9e]
    //         004556bc     MOV        this,word ptr [ESI + 0x8d96]
    //         004556c3     ADD        AX,word ptr [ESI + 0x8d98]
    //         004556ca     PUSH       0x8
    //         004556cc     PUSH       EAX
    //         004556cd     PUSH       this
    //         004556ce     PUSH       0xa
    //         004556d0     MOV        this,ESI
    //         004556d2     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:242 (27)
    //         004556d7     MOV        DX,word ptr [ESI + 0x8d98]
    //         004556de     MOV        AX,word ptr [ESI + 0x8d96]
    //         004556e5     PUSH       DAT_fffffff8
    //         004556e7     PUSH       EDX
    //         004556e8     PUSH       EAX
    //         004556e9     PUSH       0xb
    //         004556eb     MOV        this,ESI
    //         004556ed     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:243 (27)
    //         004556f2     MOV        this,word ptr [ESI + 0x8d98]
    //         004556f9     MOV        DX,word ptr [ESI + 0x8d96]
    //         00455700     PUSH       DAT_fffffff8
    //         00455702     PUSH       this
    //         00455703     PUSH       EDX
    //         00455704     PUSH       0xc
    //         00455706     MOV        this,ESI
    //         00455708     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:244 (27)
    //         0045570d     MOV        AX,word ptr [ESI + 0x8d9e]
    //         00455714     MOV        this,word ptr [ESI + 0x8d96]
    //         0045571b     PUSH       DAT_fffffff8
    //         0045571d     PUSH       EAX
    //         0045571e     PUSH       this
    //         0045571f     PUSH       0xd
    //         00455721     MOV        this,ESI
    //         00455723     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:245 (34)
    //         00455728     MOV        DX,word ptr [ESI + 0x8d9e]
    //         0045572f     MOV        AX,word ptr [ESI + 0x8d96]
    //         00455736     ADD        DX,word ptr [ESI + 0x8d98]
    //         0045573d     PUSH       0x8
    //         0045573f     MOV        this,ESI
    //         00455741     PUSH       EDX
    //         00455742     PUSH       EAX
    //         00455743     PUSH       0xe
    //         00455745     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:246 (27)
    //         0045574a     MOV        this,word ptr [ESI + 0x8d98]
    //         00455751     MOV        DX,word ptr [ESI + 0x8d96]
    //         00455758     PUSH       0x8
    //         0045575a     PUSH       this
    //         0045575b     PUSH       EDX
    //         0045575c     PUSH       0xf
    //         0045575e     MOV        this,ESI
    //         00455760     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:247 (27)
    //         00455765     MOV        AX,word ptr [ESI + 0x8d98]
    //         0045576c     MOV        this,word ptr [ESI + 0x8d96]
    //         00455773     PUSH       0x8
    //         00455775     PUSH       EAX
    //         00455776     PUSH       this
    //         00455777     PUSH       0x10
    //         00455779     MOV        this,ESI
    //         0045577b     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:248 (27)
    //         00455780     MOV        DX,word ptr [ESI + 0x8d98]
    //         00455787     MOV        AX,word ptr [ESI + 0x8d9c]
    //         0045578e     PUSH       0x0
    //         00455790     PUSH       EDX
    //         00455791     PUSH       EAX
    //         00455792     PUSH       0x11
    //         00455794     MOV        this,ESI
    //         00455796     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:249 (27)
    //         0045579b     MOV        this,word ptr [ESI + 0x8d98]
    //         004557a2     MOV        DX,word ptr [ESI + 0x8d9c]
    //         004557a9     PUSH       0x0
    //         004557ab     PUSH       this
    //         004557ac     PUSH       EDX
    //         004557ad     PUSH       0x12
    //         004557af     MOV        this,ESI
    //         004557b1     CALL       RGE_Map::set_tile_size                           void set_tile_size(RGE_Map * this, uchar para
    //                              map.cpp:251 (2)
    //         004557b6     POP        ESI
    //         004557b7     RET
}

// Offset: 0x004557C0
void RGE_Map::data_load_random_map(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Map::data_load_random_map(int)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall data_load_random_map(RGE_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004557f6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004557ec(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00455806(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004557e6(W)  
    //                               ?data_load_random_map@RGE_Map@@UAEXH@Z                       XREF[2]:     RGE_Map:00455071(c), 0057067c(*)  
    //                               RGE_Map::data_load_random_map
    //                              map.cpp:256 (25)
    //         004557c0     PUSH       -0x1
    //         004557c2     PUSH       FUN_0055da9b
    //         004557c7     MOV        EAX,FS:[0x0]
    //         004557cd     PUSH       EAX
    //         004557ce     MOV        dword ptr FS:[0x0],ESP
    //         004557d5     PUSH       this
    //         004557d6     PUSH       ESI
    //         004557d7     MOV        ESI,this
    //                              map.cpp:257 (45)
    //         004557d9     PUSH       0x4f5c
    //         004557de     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004557e3     ADD        ESP,0x4
    //         004557e6     MOV        dword ptr [ESP + local_10],EAX
    //         004557ea     TEST       EAX,EAX
    //         004557ec     MOV        dword ptr [ESP + local_4],0x0
    //         004557f4     JZ         LAB_00455804
    //         004557f6     MOV        this,dword ptr [ESP + param_1]
    //         004557fa     PUSH       this
    //         004557fb     MOV        this,EAX
    //         004557fd     CALL       RGE_RMM_Database_Controller::RGE_RMM_Database_   undefined RGE_RMM_Database_Controller(RGE_RMM
    //         00455802     JMP        LAB_00455806
    //                               LAB_00455804                                                 XREF[1]:     004557f4(j)  
    //         00455804     XOR        EAX,EAX
    //                               LAB_00455806                                                 XREF[1]:     00455802(j)  
    //                              map.cpp:258 (24)
    //         00455806     MOV        this,dword ptr [ESP + local_c]
    //         0045580a     MOV        dword ptr [ESI + 0x8dbc],EAX
    //         00455810     MOV        dword ptr FS:[0x0],this
    //         00455817     POP        ESI
    //         00455818     ADD        ESP,0x10
    //         0045581b     RET        0x4
}

// Offset: 0x00455820
void RGE_Map::load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Map::load_random_map(char *,char *,char *,char *)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall load_random_map(RGE_Map * this, char * param_1, char
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00455856(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00455864(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     0045585f(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[1]:     0045585a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045584c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00455875(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00455846(W)  
    //                               ?load_random_map@RGE_Map@@UAEXPAD000@Z                       XREF[1]:     00570680(*)  
    //                               RGE_Map::load_random_map
    //                              map.cpp:262 (25)
    //         00455820     PUSH       -0x1
    //         00455822     PUSH       FUN_0055dabb
    //         00455827     MOV        EAX,FS:[0x0]
    //         0045582d     PUSH       EAX
    //         0045582e     MOV        dword ptr FS:[0x0],ESP
    //         00455835     PUSH       this
    //         00455836     PUSH       ESI
    //         00455837     MOV        ESI,this
    //                              map.cpp:263 (60)
    //         00455839     PUSH       0x4f5c
    //         0045583e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00455843     ADD        ESP,0x4
    //         00455846     MOV        dword ptr [ESP + local_10],EAX
    //         0045584a     TEST       EAX,EAX
    //         0045584c     MOV        dword ptr [ESP + local_4],0x0
    //         00455854     JZ         LAB_00455873
    //         00455856     MOV        this,dword ptr [ESP + param_1]
    //         0045585a     MOV        EDX,dword ptr [ESP + param_4]
    //         0045585e     PUSH       this
    //         0045585f     MOV        this,dword ptr [ESP + param_3]
    //         00455863     PUSH       EDX
    //         00455864     MOV        EDX,dword ptr [ESP + param_2]
    //         00455868     PUSH       this
    //         00455869     PUSH       EDX
    //         0045586a     MOV        this,EAX
    //         0045586c     CALL       RGE_RMM_Database_Controller::RGE_RMM_Database_   undefined RGE_RMM_Database_Controller(RGE_RMM
    //         00455871     JMP        LAB_00455875
    //                               LAB_00455873                                                 XREF[1]:     00455854(j)  
    //         00455873     XOR        EAX,EAX
    //                               LAB_00455875                                                 XREF[1]:     00455871(j)  
    //                              map.cpp:264 (24)
    //         00455875     MOV        this,dword ptr [ESP + local_c]
    //         00455879     MOV        dword ptr [ESI + 0x8dbc],EAX
    //         0045587f     MOV        dword ptr FS:[0x0],this
    //         00455886     POP        ESI
    //         00455887     ADD        ESP,0x10
    //         0045588a     RET        0x10
}

// Offset: 0x00455890
void set_map_visible(RGE_Map* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_map_visible(unsigned char)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_map_visible(RGE_Map * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00455890(R)  
    //                               ?set_map_visible@RGE_Map@@QAEXE@Z                            XREF[2]:     TRIBE_Screen_Sed:004a8708(c), 
    //                               RGE_Map::set_map_visible                                                  set_map_visible:00540d6c(c)  
    //                              map.cpp:268 (10)
    //         00455890     MOV        AL,byte ptr [ESP + param_1]
    //         00455894     MOV        byte ptr [ECX + this->map_visible_flag],AL
    //                              map.cpp:270 (3)
    //         0045589a     RET        0x4
}

// Offset: 0x004558A0
void set_map_fog(RGE_Map* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_map_fog(unsigned char)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_map_fog(RGE_Map * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004558a0(R)  
    //                               ?set_map_fog@RGE_Map@@QAEXE@Z                                XREF[2]:     TRIBE_Screen_Sed:004a8717(c), 
    //                               RGE_Map::set_map_fog                                                      set_map_fog:00540d8c(c)  
    //                              map.cpp:274 (10)
    //         004558a0     MOV        AL,byte ptr [ESP + param_1]
    //         004558a4     MOV        byte ptr [ECX + this->fog_flag],AL
    //                              map.cpp:276 (3)
    //         004558aa     RET        0x4
}

// Offset: 0x004558B0
void clear_map(RGE_Map* this_, RGE_Player* param_2, RGE_Game_World* param_3, uchar param_4, long param_5, long param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::clear_map(class RGE_Player *,class RGE_Game_World *,unsigned char... *
    //                              *********************************************************************************************************
    //                              void __thiscall clear_map(RGE_Map * this, RGE_Player * param_1, RGE_
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     004558d8(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004558c5(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004558d4(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004558b6(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004558b1(R)  
    //                               ?clear_map@RGE_Map@@QAEXPAVRGE_Player@@PAVRGE_Game_World@@E  XREF[10]:    map_generate2:0045792a(c), 
    //                               RGE_Map::clear_map                                                        action:004ac5e0(c), 
    //                                                                                                         action:004ac5fe(c), 
    //                                                                                                         action:004ac61c(c), 
    //                                                                                                         action:004ac63a(c), 
    //                                                                                                         action:004ac658(c), 
    //                                                                                                         action:004ac676(c), 
    //                                                                                                         action:004ac694(c), 
    //                                                                                                         action:004ac6b2(c), 
    //                                                                                                         action:004ac6d0(c)  
    //                              map.cpp:280 (1)
    //         004558b0     PUSH       EBX
    //                              map.cpp:281 (20)
    //         004558b1     MOV        EBX,dword ptr [ESP + param_5]
    //         004558b5     PUSH       EBP
    //         004558b6     MOV        EBP,dword ptr [ESP + param_4]
    //         004558ba     PUSH       ESI
    //         004558bb     PUSH       EDI
    //         004558bc     PUSH       EBX
    //         004558bd     MOV        EDI,this
    //         004558bf     PUSH       EBP
    //         004558c0     CALL       RGE_Map::new_map                                 void new_map(RGE_Map * this, long param_1, lo
    //                              map.cpp:283 (8)
    //         004558c5     MOV        ESI,dword ptr [ESP + param_2]
    //         004558c9     TEST       ESI,ESI
    //         004558cb     JZ         LAB_004558d4
    //                              map.cpp:284 (7)
    //         004558cd     MOV        this,ESI
    //         004558cf     CALL       RGE_Game_World::reset_object_count               void reset_object_count(RGE_Game_World * this)
    //                               LAB_004558d4                                                 XREF[1]:     004558cb(j)  
    //                              map.cpp:286 (30)
    //         004558d4     MOV        EAX,dword ptr [ESP + param_3]
    //         004558d8     MOV        this,dword ptr [ESP + param_1]
    //         004558dc     PUSH       0x0
    //         004558de     PUSH       0x1
    //         004558e0     DEC        EBX
    //         004558e1     PUSH       EAX
    //         004558e2     DEC        EBP
    //         004558e3     PUSH       EBX
    //         004558e4     PUSH       EBP
    //         004558e5     PUSH       0x0
    //         004558e7     PUSH       0x0
    //         004558e9     PUSH       ESI
    //         004558ea     PUSH       this
    //         004558eb     MOV        this,EDI
    //         004558ed     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Player *
    //                              map.cpp:288 (4)
    //         004558f2     TEST       ESI,ESI
    //         004558f4     JZ         LAB_004558fd
    //                              map.cpp:289 (7)
    //         004558f6     MOV        this,ESI
    //         004558f8     CALL       RGE_Game_World::reset_player_visible_maps        void reset_player_visible_maps(RGE_Game_World
    //                               LAB_004558fd                                                 XREF[1]:     004558f4(j)  
    //                              map.cpp:290 (7)
    //         004558fd     POP        EDI
    //         004558fe     POP        ESI
    //         004558ff     POP        EBP
    //         00455900     POP        EBX
    //         00455901     RET        0x14
}

// Offset: 0x00455910
void new_map(RGE_Map* this_, long param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::new_map(long,long)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall new_map(RGE_Map * this, long param_1, long param_2)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     00455929(R), 004559a8(R), 00455b9d(R), 00455bdc(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00455937(R), 00455b99(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     00455b42(W), 00455b63(W), 00455b8f(W), 00455bb4(W), 
    //                                                                                     00455be2(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00455c0b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00455b3c(W), 00455b89(W)  
    //                               ?new_map@RGE_Map@@QAEXJJ@Z                                   XREF[5]:     clear_map:004558c0(c), 
    //                               RGE_Map::new_map                                                          scenario_load:00456027(c), 
    //                                                                                                         load_map:00457a0e(c), 
    //                                                                                                         new_game:00542869(c), 
    //                                                                                                         new_scenario:00542c4c(c)  
    //                              map.cpp:295 (25)
    //         00455910     PUSH       -0x1
    //         00455912     PUSH       FUN_0055daf1
    //         00455917     MOV        EAX,FS:[0x0]
    //         0045591d     PUSH       EAX
    //         0045591e     MOV        dword ptr FS:[0x0],ESP
    //         00455925     PUSH       this
    //         00455926     PUSH       EBP
    //         00455927     PUSH       ESI
    //         00455928     PUSH       EDI
    //                              map.cpp:301 (26)
    //         00455929     MOV        EDI,dword ptr [ESP + param_1]
    //         0045592d     TEST       EDI,EDI
    //         0045592f     MOV        ESI,this
    //         00455931     JLE        LAB_00455c0b
    //         00455937     MOV        EBP,dword ptr [ESP + param_2]
    //         0045593b     TEST       EBP,EBP
    //         0045593d     JLE        LAB_00455c0b
    //                              map.cpp:304 (8)
    //         00455943     MOV        EAX,dword ptr [ESI + 0x4]
    //         00455946     PUSH       EBX
    //         00455947     TEST       EAX,EAX
    //         00455949     JZ         LAB_004559b8
    //                              map.cpp:306 (10)
    //         0045594b     MOV        EAX,dword ptr [ESI + 0x8dc0]
    //         00455951     TEST       EAX,EAX
    //         00455953     JZ         LAB_004559ac
    //                              map.cpp:308 (4)
    //         00455955     MOVSX      EBX,word ptr [EAX + 0x3c]
    //                              map.cpp:309 (6)
    //         00455959     XOR        EDI,EDI
    //         0045595b     TEST       EBX,EBX
    //         0045595d     JLE        LAB_004559a8
    //                               LAB_0045595f                                                 XREF[1]:     004559a6(j)  
    //                              map.cpp:310 (13)
    //         0045595f     MOV        EAX,dword ptr [ESI + 0x8dc0]
    //         00455965     MOV        EAX,dword ptr [EAX + 0x40]
    //         00455968     TEST       EAX,EAX
    //         0045596a     JZ         LAB_004559a3
    //                              map.cpp:311 (7)
    //         0045596c     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         0045596f     TEST       EAX,EAX
    //         00455971     JZ         LAB_004559a3
    //                              map.cpp:313 (8)
    //         00455973     MOV        this,dword ptr [EAX + 0x28]
    //         00455976     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              map.cpp:314 (20)
    //         0045597b     MOV        this,dword ptr [ESI + 0x8dc0]
    //         00455981     MOV        EDX,dword ptr [ECX + this+0x40]
    //         00455984     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         00455987     MOV        this,dword ptr [EAX + 0x2c]
    //         0045598a     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                              map.cpp:315 (25)
    //         0045598f     MOV        this,dword ptr [ESI + 0x8dc0]
    //         00455995     MOV        EDX,dword ptr [ECX + this+0x40]
    //         00455998     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         0045599b     MOV        this,dword ptr [EAX + 0x30]
    //         0045599e     CALL       RGE_Object_List::removeAllObjects                void removeAllObjects(RGE_Object_List * this)
    //                               LAB_004559a3                                                 XREF[2]:     0045596a(j), 00455971(j)  
    //         004559a3     INC        EDI
    //         004559a4     CMP        EDI,EBX
    //         004559a6     JL         LAB_0045595f
    //                               LAB_004559a8                                                 XREF[1]:     0045595d(j)  
    //                              map.cpp:309 (4)
    //         004559a8     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_004559ac                                                 XREF[1]:     00455953(j)  
    //                              map.cpp:327 (12)
    //         004559ac     MOV        this,dword ptr [ESI + 0x4]
    //         004559af     PUSH       this
    //         004559b0     CALL       free                                             undefined free()
    //         004559b5     ADD        ESP,0x4
    //                               LAB_004559b8                                                 XREF[1]:     00455949(j)  
    //                              map.cpp:330 (10)
    //         004559b8     MOV        EAX,dword ptr [ESI + 0x8db0]
    //         004559be     TEST       EAX,EAX
    //         004559c0     JZ         LAB_004559cb
    //                              map.cpp:331 (9)
    //         004559c2     PUSH       EAX
    //         004559c3     CALL       free                                             undefined free()
    //         004559c8     ADD        ESP,0x4
    //                               LAB_004559cb                                                 XREF[1]:     004559c0(j)  
    //                              map.cpp:333 (10)
    //         004559cb     MOV        EAX,dword ptr [ESI + 0x8d8c]
    //         004559d1     TEST       EAX,EAX
    //         004559d3     JZ         LAB_004559de
    //                              map.cpp:334 (9)
    //         004559d5     PUSH       EAX
    //         004559d6     CALL       free                                             undefined free()
    //         004559db     ADD        ESP,0x4
    //                               LAB_004559de                                                 XREF[1]:     004559d3(j)  
    //                              map.cpp:336 (10)
    //         004559de     MOV        EAX,dword ptr [ESI + 0x8db4]
    //         004559e4     TEST       EAX,EAX
    //         004559e6     JZ         LAB_004559f1
    //                              map.cpp:337 (9)
    //         004559e8     PUSH       EAX
    //         004559e9     CALL       free                                             undefined free()
    //         004559ee     ADD        ESP,0x4
    //                               LAB_004559f1                                                 XREF[1]:     004559e6(j)  
    //                              map.cpp:342 (20)
    //         004559f1     MOVSX      EAX,word ptr [ESI + 0x8d98]
    //         004559f8     MOVSX      EDX,word ptr [ESI + 0x8d96]
    //         004559ff     IMUL       EAX,EBP
    //         00455a02     MOV        dword ptr [ESI + 0xc],EBP
    //                              map.cpp:343 (23)
    //         00455a05     IMUL       EBP,EDI
    //         00455a08     IMUL       EDX,EDI
    //         00455a0b     PUSH       0x18
    //         00455a0d     PUSH       EBP
    //         00455a0e     MOV        dword ptr [ESI + 0x8],EDI
    //         00455a11     MOV        dword ptr [ESI + 0x10],EDX
    //         00455a14     MOV        dword ptr [ESI + 0x14],EAX
    //         00455a17     CALL       calloc                                           undefined calloc()
    //                              map.cpp:344 (21)
    //         00455a1c     MOV        this,dword ptr [ESI + 0xc]
    //         00455a1f     ADD        ESP,0x8
    //         00455a22     IMUL       this,dword ptr [ESI + 0x8]
    //         00455a26     PUSH       0x1
    //         00455a28     PUSH       this
    //         00455a29     MOV        dword ptr [ESI + 0x4],EAX
    //         00455a2c     CALL       calloc                                           undefined calloc()
    //                              map.cpp:346 (27)
    //         00455a31     MOV        EDX,dword ptr [ESI + 0xc]
    //         00455a34     ADD        ESP,0x8
    //         00455a37     INC        EDX
    //         00455a38     MOV        dword ptr [ESI + 0x8db0],EAX
    //         00455a3e     PUSH       0x4
    //         00455a40     PUSH       EDX
    //         00455a41     CALL       calloc                                           undefined calloc()
    //         00455a46     MOV        dword ptr [ESI + 0x8d8c],EAX
    //                              map.cpp:347 (15)
    //         00455a4c     MOV        EAX,dword ptr [ESI + 0xc]
    //         00455a4f     ADD        ESP,0x8
    //         00455a52     INC        EAX
    //         00455a53     PUSH       0x4
    //         00455a55     PUSH       EAX
    //         00455a56     CALL       calloc                                           undefined calloc()
    //                              map.cpp:349 (18)
    //         00455a5b     MOV        this,dword ptr [ESI + 0xc]
    //         00455a5e     MOV        dword ptr [ESI + 0x8db4],EAX
    //         00455a64     ADD        ESP,0x8
    //         00455a67     XOR        EAX,EAX
    //         00455a69     TEST       this,this
    //         00455a6b     JLE        LAB_00455aa4
    //                               LAB_00455a6d                                                 XREF[1]:     00455aa2(j)  
    //                              map.cpp:351 (24)
    //         00455a6d     MOV        this,EAX
    //         00455a6f     MOV        EDX,dword ptr [ESI + 0x4]
    //         00455a72     IMUL       this,dword ptr [ESI + 0x8]
    //         00455a76     LEA        this,[ECX + ECX*0x2]
    //         00455a79     LEA        this,[EDX + this->_padding_*0x8]
    //         00455a7c     MOV        EDX,dword ptr [ESI + 0x8d8c]
    //         00455a82     MOV        dword ptr [EDX + EAX*0x4],this
    //                              map.cpp:352 (31)
    //         00455a85     MOV        this,EAX
    //         00455a87     IMUL       this,dword ptr [ESI + 0x8]
    //         00455a8b     MOV        EDI,dword ptr [ESI + 0x8db0]
    //         00455a91     MOV        EDX,dword ptr [ESI + 0x8db4]
    //         00455a97     ADD        this,EDI
    //         00455a99     MOV        dword ptr [EDX + EAX*0x4],this
    //         00455a9c     MOV        this,dword ptr [ESI + 0xc]
    //         00455a9f     INC        EAX
    //         00455aa0     CMP        EAX,this
    //         00455aa2     JL         LAB_00455a6d
    //                               LAB_00455aa4                                                 XREF[1]:     00455a6b(j)  
    //                              map.cpp:355 (12)
    //         00455aa4     MOV        EAX,dword ptr [ESI + 0xc]
    //         00455aa7     MOV        this,dword ptr [ESI + 0x8d8c]
    //         00455aad     MOV        EDX,dword ptr [ESI + 0x4]
    //                              map.cpp:358 (30)
    //         00455ab0     XOR        EBP,EBP
    //         00455ab2     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //         00455ab5     MOV        EAX,dword ptr [ESI + 0xc]
    //         00455ab8     MOV        this,dword ptr [ESI + 0x8db4]
    //         00455abe     MOV        EDX,dword ptr [ESI + 0x8db0]
    //         00455ac4     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //         00455ac7     MOV        EAX,dword ptr [ESI + 0xc]
    //         00455aca     TEST       EAX,EAX
    //         00455acc     JLE        LAB_00455b03
    //                               LAB_00455ace                                                 XREF[1]:     00455b01(j)  
    //                              map.cpp:359 (11)
    //         00455ace     MOV        EAX,dword ptr [ESI + 0x8]
    //         00455ad1     XOR        EDI,EDI
    //         00455ad3     TEST       EAX,EAX
    //         00455ad5     JLE        LAB_00455afb
    //         00455ad7     XOR        this,this
    //                               LAB_00455ad9                                                 XREF[1]:     00455af9(j)  
    //                              map.cpp:361 (14)
    //         00455ad9     MOV        EAX,dword ptr [ESI + 0x8d8c]
    //         00455adf     MOV        EAX,dword ptr [EAX + EBP*0x4]
    //         00455ae2     ADD        EAX,this
    //         00455ae4     ADD        this,0x18
    //                              map.cpp:362 (20)
    //         00455ae7     MOV        DL,byte ptr [EAX + 0x5]
    //         00455aea     AND        DL,0x1f
    //         00455aed     OR         DL,0x20
    //         00455af0     INC        EDI
    //         00455af1     MOV        byte ptr [EAX + 0x5],DL
    //         00455af4     MOV        EAX,dword ptr [ESI + 0x8]
    //         00455af7     CMP        EDI,EAX
    //         00455af9     JL         LAB_00455ad9
    //                               LAB_00455afb                                                 XREF[1]:     00455ad5(j)  
    //                              map.cpp:358 (8)
    //         00455afb     MOV        EAX,dword ptr [ESI + 0xc]
    //         00455afe     INC        EBP
    //         00455aff     CMP        EBP,EAX
    //         00455b01     JL         LAB_00455ace
    //                               LAB_00455b03                                                 XREF[1]:     00455acc(j)  
    //                              map.cpp:365 (21)
    //         00455b03     MOV        EAX,dword ptr [ESI + 0xc]
    //         00455b06     MOV        this,dword ptr [ESI + 0x8]
    //         00455b09     DEC        EAX
    //         00455b0a     DEC        this
    //         00455b0b     PUSH       EAX
    //         00455b0c     PUSH       this
    //         00455b0d     PUSH       0x0
    //         00455b0f     PUSH       0x0
    //         00455b11     MOV        this,ESI
    //         00455b13     CALL       RGE_Map::set_map_screen_pos                      void set_map_screen_pos(RGE_Map * this, int p
    //                              map.cpp:367 (10)
    //         00455b18     MOV        EDI,dword ptr [ESI + 0x8dc4]
    //         00455b1e     TEST       EDI,EDI
    //         00455b20     JZ         LAB_00455b32
    //                              map.cpp:368 (16)
    //         00455b22     MOV        this,EDI
    //         00455b24     CALL       RGE_Zone_Map_List::~RGE_Zone_Map_List            void ~RGE_Zone_Map_List(RGE_Zone_Map_List * t
    //         00455b29     PUSH       EDI
    //         00455b2a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455b2f     ADD        ESP,0x4
    //                               LAB_00455b32                                                 XREF[1]:     00455b20(j)  
    //                              map.cpp:369 (38)
    //         00455b32     PUSH       0xc
    //         00455b34     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00455b39     ADD        ESP,0x4
    //         00455b3c     MOV        dword ptr [ESP + local_10],EAX
    //         00455b40     TEST       EAX,EAX
    //         00455b42     MOV        dword ptr [ESP + local_4],0x0
    //         00455b4a     JZ         LAB_00455b56
    //         00455b4c     PUSH       ESI
    //         00455b4d     MOV        this,EAX
    //         00455b4f     CALL       RGE_Zone_Map_List::RGE_Zone_Map_List             undefined RGE_Zone_Map_List(RGE_Zone_Map_List
    //         00455b54     JMP        LAB_00455b58
    //                               LAB_00455b56                                                 XREF[1]:     00455b4a(j)  
    //         00455b56     XOR        EAX,EAX
    //                               LAB_00455b58                                                 XREF[1]:     00455b54(j)  
    //                              map.cpp:371 (39)
    //         00455b58     MOV        EDI,dword ptr [ESI + 0x8dc8]
    //         00455b5e     OR         EBX,0xffffffff
    //         00455b61     TEST       EDI,EDI
    //         00455b63     MOV        dword ptr [ESP + local_4],EBX
    //         00455b67     MOV        dword ptr [ESI + 0x8dc4],EAX
    //         00455b6d     JZ         LAB_00455b7f
    //         00455b6f     MOV        this,EDI
    //         00455b71     CALL       RGE_Unified_Visible_Map::~RGE_Unified_Visible_   void ~RGE_Unified_Visible_Map(RGE_Unified_Vis
    //         00455b76     PUSH       EDI
    //         00455b77     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455b7c     ADD        ESP,0x4
    //                               LAB_00455b7f                                                 XREF[1]:     00455b6d(j)  
    //                              map.cpp:372 (47)
    //         00455b7f     PUSH       0xc
    //         00455b81     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00455b86     ADD        ESP,0x4
    //         00455b89     MOV        dword ptr [ESP + local_10],EAX
    //         00455b8d     TEST       EAX,EAX
    //         00455b8f     MOV        dword ptr [ESP + local_4],0x1
    //         00455b97     JZ         LAB_00455bac
    //         00455b99     MOV        EDX,dword ptr [ESP + param_2]
    //         00455b9d     MOV        this,dword ptr [ESP + param_1]
    //         00455ba1     PUSH       EDX
    //         00455ba2     PUSH       this
    //         00455ba3     MOV        this,EAX
    //         00455ba5     CALL       RGE_Unified_Visible_Map::RGE_Unified_Visible_Map undefined RGE_Unified_Visible_Map(RGE_Unified
    //         00455baa     JMP        LAB_00455bae
    //                               LAB_00455bac                                                 XREF[1]:     00455b97(j)  
    //         00455bac     XOR        EAX,EAX
    //                               LAB_00455bae                                                 XREF[1]:     00455baa(j)  
    //                              map.cpp:374 (36)
    //         00455bae     MOV        EDI,dword ptr [ESI + 0x8dcc]
    //         00455bb4     MOV        dword ptr [ESP + local_4],EBX
    //         00455bb8     TEST       EDI,EDI
    //         00455bba     MOV        dword ptr [ESI + 0x8dc8],EAX
    //         00455bc0     JZ         LAB_00455bd2
    //         00455bc2     MOV        this,EDI
    //         00455bc4     CALL       Visible_Unit_Manager::~Visible_Unit_Manager      void ~Visible_Unit_Manager(Visible_Unit_Manag
    //         00455bc9     PUSH       EDI
    //         00455bca     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455bcf     ADD        ESP,0x4
    //                               LAB_00455bd2                                                 XREF[1]:     00455bc0(j)  
    //                              map.cpp:375 (57)
    //         00455bd2     PUSH       0x24
    //         00455bd4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00455bd9     ADD        ESP,0x4
    //         00455bdc     MOV        dword ptr [ESP + param_1],EAX
    //         00455be0     TEST       EAX,EAX
    //         00455be2     MOV        dword ptr [ESP + local_4],0x2
    //         00455bea     JZ         LAB_00455c02
    //         00455bec     MOV        EDX,dword ptr [ESI + 0x8dc0]
    //         00455bf2     PUSH       0x40
    //         00455bf4     MOVSX      this,word ptr [EDX + 0x3c]
    //         00455bf8     PUSH       this
    //         00455bf9     MOV        this,EAX
    //         00455bfb     CALL       Visible_Unit_Manager::Visible_Unit_Manager       undefined Visible_Unit_Manager(Visible_Unit_M
    //         00455c00     JMP        LAB_00455c04
    //                               LAB_00455c02                                                 XREF[1]:     00455bea(j)  
    //         00455c02     XOR        EAX,EAX
    //                               LAB_00455c04                                                 XREF[1]:     00455c00(j)  
    //         00455c04     MOV        dword ptr [ESI + 0x8dcc],EAX
    //         00455c0a     POP        EBX
    //                               LAB_00455c0b                                                 XREF[2]:     00455931(j), 0045593d(j)  
    //                              map.cpp:377 (20)
    //         00455c0b     MOV        this,dword ptr [ESP + local_c]
    //         00455c0f     POP        EDI
    //         00455c10     POP        ESI
    //         00455c11     MOV        dword ptr FS:[0x0],this
    //         00455c18     POP        EBP
    //         00455c19     ADD        ESP,0x10
    //         00455c1c     RET        0x8
}

// Offset: 0x00455C20
void clear_map(RGE_Map* this_, uchar param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::clear_map(unsigned char,unsigned char)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall clear_map(RGE_Map * this, uchar param_1, uchar param
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00455c53(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00455c42(R)  
    //              undefined1        Stack[-0x1]:1  local_1                   XREF[1]:     00455c4f(W)  
    //                               ?clear_map@RGE_Map@@QAEXEE@Z                                 XREF[1]:     new_scenario:00542c5f(c)  
    //                               RGE_Map::clear_map
    //                              map.cpp:382 (5)
    //         00455c20     PUSH       this
    //         00455c21     PUSH       EBP
    //         00455c22     PUSH       EDI
    //         00455c23     MOV        EDI,this
    //                              map.cpp:387 (11)
    //         00455c25     XOR        EBP,EBP
    //         00455c27     XOR        this,this
    //         00455c29     CMP        dword ptr [EDI + 0xc],this
    //         00455c2c     JLE        LAB_00455c8f
    //         00455c2e     PUSH       ESI
    //         00455c2f     PUSH       EBX
    //                               LAB_00455c30                                                 XREF[1]:     00455c8b(j)  
    //                              map.cpp:389 (6)
    //         00455c30     MOV        EAX,dword ptr [EDI + 0x8d8c]
    //                              map.cpp:390 (12)
    //         00455c36     MOV        EDX,dword ptr [EDI + 0x8]
    //         00455c39     XOR        ESI,ESI
    //         00455c3b     CMP        EDX,this
    //         00455c3d     MOV        EAX,dword ptr [EAX + EBP*0x4]
    //         00455c40     JLE        LAB_00455c85
    //                              map.cpp:394 (24)
    //         00455c42     MOV        DL,byte ptr [ESP + param_2]
    //         00455c46     SHL        DL,0x5
    //                               LAB_00455c49                                                 XREF[1]:     00455c83(j)  
    //         00455c49     MOV        BL,byte ptr [EAX + 0x5]
    //         00455c4c     MOV        byte ptr [EAX + 0x4],this
    //         00455c4f     MOV        byte ptr [ESP + local_1],BL
    //         00455c53     MOV        BL,byte ptr [ESP + param_1]
    //         00455c57     AND        BL,0x1f
    //                              map.cpp:396 (5)
    //         00455c5a     MOV        byte ptr [EAX + 0x6],this
    //         00455c5d     OR         BL,DL
    //                              map.cpp:397 (6)
    //         00455c5f     MOV        word ptr [EAX],this
    //         00455c62     MOV        byte ptr [EAX + 0x5],BL
    //                              map.cpp:400 (12)
    //         00455c65     MOV        BL,0xff
    //         00455c67     MOV        word ptr [EAX + 0x2],this
    //         00455c6b     MOV        byte ptr [EAX + 0x7],this
    //         00455c6e     MOV        byte ptr [EAX + 0x8],BL
    //                              map.cpp:401 (3)
    //         00455c71     MOV        byte ptr [EAX + 0x9],this
    //                              map.cpp:402 (3)
    //         00455c74     MOV        byte ptr [EAX + 0xa],this
    //                              map.cpp:403 (6)
    //         00455c77     MOV        byte ptr [EAX + 0xb],BL
    //         00455c7a     MOV        EBX,dword ptr [EDI + 0x8]
    //                              map.cpp:405 (8)
    //         00455c7d     ADD        EAX,0x18
    //         00455c80     INC        ESI
    //         00455c81     CMP        ESI,EBX
    //         00455c83     JL         LAB_00455c49
    //                               LAB_00455c85                                                 XREF[1]:     00455c40(j)  
    //                              map.cpp:387 (10)
    //         00455c85     MOV        EAX,dword ptr [EDI + 0xc]
    //         00455c88     INC        EBP
    //         00455c89     CMP        EBP,EAX
    //         00455c8b     JL         LAB_00455c30
    //         00455c8d     POP        EBX
    //         00455c8e     POP        ESI
    //                               LAB_00455c8f                                                 XREF[1]:     00455c2c(j)  
    //                              map.cpp:409 (19)
    //         00455c8f     MOV        EDX,dword ptr [EDI + 0xc]
    //         00455c92     MOV        EAX,dword ptr [EDI + 0x8]
    //         00455c95     DEC        EDX
    //         00455c96     DEC        EAX
    //         00455c97     PUSH       EDX
    //         00455c98     PUSH       EAX
    //         00455c99     PUSH       this
    //         00455c9a     PUSH       this
    //         00455c9b     MOV        this,EDI
    //         00455c9d     CALL       RGE_Map::set_map_screen_pos                      void set_map_screen_pos(RGE_Map * this, int p
    //                              map.cpp:410 (6)
    //         00455ca2     POP        EDI
    //         00455ca3     POP        EBP
    //         00455ca4     POP        this
    //         00455ca5     RET        0x8
}

// Offset: 0x00455CB0
void request_redraw(RGE_Map* this_, int param_2, int param_3, int param_4, int param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::request_redraw(int,int,int,int,unsigned char)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall request_redraw(RGE_Map * this, int param_1, int para
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00455cb4(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00455ccd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00455cb9(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[4]:     00455cd1(R), 00455cdd(W), 00455d11(W), 00455d4e(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00455d1d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00455cc1(W), 00455d27(R)  
    //                               ?request_redraw@RGE_Map@@QAEXHHHHE@Z                         XREF[7]:     set_elev:004598e9(c), 
    //                               RGE_Map::request_redraw                                                   set_terrain:0045997f(c), 
    //                                                                                                         set_terrain:00459d0a(c), 
    //                                                                                                         remove_shadows:004c7ea1(c), 
    //                                                                                                         set_object_state:004c8930(c), 
    //                                                                                                         set_selection_area:0053456c(c), 
    //                                                                                                         set_selection_area:005345b8(c)  
    //                              map.cpp:414 (4)
    //         00455cb0     PUSH       this
    //         00455cb1     PUSH       EBX
    //         00455cb2     PUSH       EBP
    //         00455cb3     PUSH       ESI
    //                              map.cpp:418 (25)
    //         00455cb4     MOV        ESI,dword ptr [ESP + param_1]
    //         00455cb8     PUSH       EDI
    //         00455cb9     MOV        EDI,dword ptr [ESP + param_3]
    //         00455cbd     MOV        EBX,this
    //         00455cbf     CMP        ESI,EDI
    //         00455cc1     MOV        dword ptr [ESP + local_4],EBX
    //         00455cc5     JLE        LAB_00455ccd
    //         00455cc7     MOV        EAX,ESI
    //         00455cc9     MOV        ESI,EDI
    //         00455ccb     MOV        EDI,EAX
    //                               LAB_00455ccd                                                 XREF[1]:     00455cc5(j)  
    //                              map.cpp:419 (22)
    //         00455ccd     MOV        EAX,dword ptr [ESP + param_2]
    //         00455cd1     MOV        this,dword ptr [ESP + param_4]
    //         00455cd5     CMP        EAX,this
    //         00455cd7     JLE        LAB_00455ce3
    //         00455cd9     MOV        EDX,EAX
    //         00455cdb     MOV        EAX,this
    //         00455cdd     MOV        dword ptr [ESP + param_4],EDX
    //         00455ce1     MOV        this,EDX
    //                               LAB_00455ce3                                                 XREF[1]:     00455cd7(j)  
    //                              map.cpp:421 (22)
    //         00455ce3     TEST       EDI,EDI
    //         00455ce5     JL         LAB_00455d57
    //         00455ce7     TEST       this,this
    //         00455ce9     JL         LAB_00455d57
    //         00455ceb     MOV        EDX,dword ptr [EBX + 0x8]
    //         00455cee     CMP        ESI,EDX
    //         00455cf0     JGE        LAB_00455d57
    //         00455cf2     MOV        EBX,dword ptr [EBX + 0xc]
    //         00455cf5     CMP        EAX,EBX
    //         00455cf7     JGE        LAB_00455d57
    //                              map.cpp:423 (6)
    //         00455cf9     TEST       ESI,ESI
    //         00455cfb     JGE        LAB_00455cff
    //         00455cfd     XOR        ESI,ESI
    //                               LAB_00455cff                                                 XREF[1]:     00455cfb(j)  
    //                              map.cpp:424 (6)
    //         00455cff     TEST       EAX,EAX
    //         00455d01     JGE        LAB_00455d05
    //         00455d03     XOR        EAX,EAX
    //                               LAB_00455d05                                                 XREF[1]:     00455d01(j)  
    //                              map.cpp:425 (7)
    //         00455d05     CMP        EDI,EDX
    //         00455d07     JL         LAB_00455d0c
    //         00455d09     LEA        EDI,[EDX + -0x1]
    //                               LAB_00455d0c                                                 XREF[1]:     00455d07(j)  
    //                              map.cpp:426 (11)
    //         00455d0c     CMP        this,EBX
    //         00455d0e     JL         LAB_00455d17
    //         00455d10     DEC        EBX
    //         00455d11     MOV        dword ptr [ESP + param_4],EBX
    //         00455d15     MOV        this,EBX
    //                               LAB_00455d17                                                 XREF[1]:     00455d0e(j)  
    //                              map.cpp:428 (6)
    //         00455d17     CMP        EAX,this
    //         00455d19     MOV        EBP,EAX
    //         00455d1b     JG         LAB_00455d57
    //                              map.cpp:430 (25)
    //         00455d1d     MOV        BL,byte ptr [ESP + param_5]
    //         00455d21     LEA        this,[ESI + ESI*0x2]
    //         00455d24     SHL        this,0x3
    //                               LAB_00455d27                                                 XREF[1]:     00455d55(j)  
    //         00455d27     MOV        EAX,dword ptr [ESP + local_4]
    //         00455d2b     MOV        EDX,dword ptr [EAX + 0x8d8c]
    //         00455d31     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //         00455d34     ADD        EAX,this
    //                              map.cpp:431 (12)
    //         00455d36     CMP        ESI,EDI
    //         00455d38     JG         LAB_00455d4e
    //         00455d3a     MOV        EDX,EDI
    //         00455d3c     ADD        EAX,0xa
    //         00455d3f     SUB        EDX,ESI
    //         00455d41     INC        EDX
    //                               LAB_00455d42                                                 XREF[1]:     00455d4c(j)  
    //                              map.cpp:433 (4)
    //         00455d42     MOV        byte ptr [EAX + -0x3],0xcc
    //                              map.cpp:434 (2)
    //         00455d46     MOV        byte ptr [EAX],BL
    //                              map.cpp:435 (6)
    //         00455d48     ADD        EAX,0x18
    //         00455d4b     DEC        EDX
    //         00455d4c     JNZ        LAB_00455d42
    //                               LAB_00455d4e                                                 XREF[1]:     00455d38(j)  
    //                              map.cpp:428 (9)
    //         00455d4e     MOV        EAX,dword ptr [ESP + param_4]
    //         00455d52     INC        EBP
    //         00455d53     CMP        EBP,EAX
    //         00455d55     JLE        LAB_00455d27
    //                               LAB_00455d57                                                 XREF[5]:     00455ce5(j), 00455ce9(j), 
    //                                                                                                         00455cf0(j), 00455cf7(j), 
    //                                                                                                         00455d1b(j)  
    //                              map.cpp:439 (8)
    //         00455d57     POP        EDI
    //         00455d58     POP        ESI
    //         00455d59     POP        EBP
    //         00455d5a     POP        EBX
    //         00455d5b     POP        this
    //         00455d5c     RET        0x14
}

// Offset: 0x00455D60
void clear_map_view_info(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::clear_map_view_info(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall clear_map_view_info(RGE_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ?clear_map_view_info@RGE_Map@@QAEXXZ                         XREF[1]:     set_player:00420172(c)  
    //                               RGE_Map::clear_map_view_info
    //                              map.cpp:444 (13)
    //         00455d60     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00455d63     PUSH       EBX
    //         00455d64     PUSH       ESI
    //         00455d65     XOR        EBX,EBX
    //         00455d67     XOR        ESI,ESI
    //         00455d69     CMP        EAX,EBX
    //         00455d6b     JLE        LAB_00455da7
    //                              map.cpp:444 (1)
    //         00455d6d     PUSH       EDI
    //                               LAB_00455d6e                                                 XREF[1]:     00455da4(j)  
    //                              map.cpp:450 (6)
    //         00455d6e     MOV        EAX,dword ptr [ECX + this->map_row_offset]
    //                              map.cpp:451 (12)
    //         00455d74     MOV        EDI,dword ptr [ECX + this->map_width]
    //         00455d77     XOR        EDX,EDX
    //         00455d79     CMP        EDI,EBX
    //         00455d7b     MOV        EAX,dword ptr [EAX + ESI*0x4]
    //         00455d7e     JLE        LAB_00455d9e
    //                              map.cpp:450 (3)
    //         00455d80     ADD        EAX,0x8
    //                               LAB_00455d83                                                 XREF[1]:     00455d9c(j)  
    //                              map.cpp:453 (3)
    //         00455d83     MOV        byte ptr [EAX + -0x1],BL
    //                              map.cpp:454 (3)
    //         00455d86     MOV        byte ptr [EAX],0xff
    //                              map.cpp:455 (3)
    //         00455d89     MOV        byte ptr [EAX + 0x1],BL
    //                              map.cpp:456 (3)
    //         00455d8c     MOV        byte ptr [EAX + 0x2],BL
    //                              map.cpp:457 (7)
    //         00455d8f     MOV        byte ptr [EAX + 0x3],0xff
    //         00455d93     MOV        EDI,dword ptr [ECX + this->map_width]
    //                              map.cpp:458 (8)
    //         00455d96     ADD        EAX,0x18
    //         00455d99     INC        EDX
    //         00455d9a     CMP        EDX,EDI
    //         00455d9c     JL         LAB_00455d83
    //                               LAB_00455d9e                                                 XREF[1]:     00455d7e(j)  
    //                              map.cpp:448 (8)
    //         00455d9e     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00455da1     INC        ESI
    //         00455da2     CMP        ESI,EAX
    //         00455da4     JL         LAB_00455d6e
    //                              map.cpp:444 (1)
    //         00455da6     POP        EDI
    //                               LAB_00455da7                                                 XREF[1]:     00455d6b(j)  
    //                              map.cpp:461 (3)
    //         00455da7     POP        ESI
    //         00455da8     POP        EBX
    //         00455da9     RET
}

// Offset: 0x00455DB0
void coordinate_map(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::coordinate_map(void)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall coordinate_map(RGE_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ?coordinate_map@RGE_Map@@QAEXXZ                              XREF[1]:     set_world:0053445c(c)  
    //                               RGE_Map::coordinate_map
    //                              map.cpp:466 (19)
    //         00455db0     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00455db3     MOV        EDX,dword ptr [ECX + this->map_width]
    //         00455db6     DEC        EAX
    //         00455db7     DEC        EDX
    //         00455db8     PUSH       EAX
    //         00455db9     PUSH       EDX
    //         00455dba     PUSH       0x0
    //         00455dbc     PUSH       0x0
    //         00455dbe     CALL       RGE_Map::set_map_screen_pos                      void set_map_screen_pos(RGE_Map * this, int p
    //                              map.cpp:468 (1)
    //         00455dc3     RET
}

// Offset: 0x00455DD0
void set_map_screen_pos(RGE_Map* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_map_screen_pos(int,int,int,int)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_map_screen_pos(RGE_Map * this, int param_1, int 
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     00455dd3(R), 00455dde(W), 00455dec(W), 00455df0(R), 
    //                                                                                     00455ebe(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     00455df4(R), 00455e4a(W), 00455ec2(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00455e0a(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[5]:     00455e20(R), 00455e28(W), 00455e36(W), 00455e3a(R), 
    //                                                                                     00455ec6(R)  
    //                               ?set_map_screen_pos@RGE_Map@@QAEXHHHH@Z                      XREF[4]:     new_map:00455b13(c), 
    //                               RGE_Map::set_map_screen_pos                                               clear_map:00455c9d(c), 
    //                                                                                                         coordinate_map:00455dbe(c), 
    //                                                                                                         set_elev:004598d8(c)  
    //                              map.cpp:473 (3)
    //         00455dd0     PUSH       EBX
    //         00455dd1     PUSH       EBP
    //         00455dd2     PUSH       ESI
    //                              map.cpp:477 (11)
    //         00455dd3     MOV        ESI,dword ptr [ESP + param_1]
    //         00455dd7     XOR        EDX,EDX
    //         00455dd9     PUSH       EDI
    //         00455dda     CMP        ESI,EDX
    //         00455ddc     JGE        LAB_00455de4
    //                              map.cpp:478 (4)
    //         00455dde     MOV        dword ptr [ESP + param_1],EDX
    //                              map.cpp:479 (10)
    //         00455de2     JMP        LAB_00455df0
    //                               LAB_00455de4                                                 XREF[1]:     00455ddc(j)  
    //         00455de4     MOV        EAX,dword ptr [ECX + this->map_width]
    //         00455de7     DEC        EAX
    //         00455de8     CMP        ESI,EAX
    //         00455dea     JLE        LAB_00455df4
    //                              map.cpp:480 (8)
    //         00455dec     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_00455df0                                                 XREF[1]:     00455de2(j)  
    //         00455df0     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_00455df4                                                 XREF[1]:     00455dea(j)  
    //                              map.cpp:482 (8)
    //         00455df4     MOV        EDI,dword ptr [ESP + param_2]
    //         00455df8     CMP        EDI,EDX
    //         00455dfa     JGE        LAB_00455e00
    //                              map.cpp:483 (2)
    //         00455dfc     XOR        EDI,EDI
    //                              map.cpp:484 (10)
    //         00455dfe     JMP        LAB_00455e0a
    //                               LAB_00455e00                                                 XREF[1]:     00455dfa(j)  
    //         00455e00     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00455e03     DEC        EAX
    //         00455e04     CMP        EDI,EAX
    //         00455e06     JLE        LAB_00455e0a
    //                              map.cpp:485 (2)
    //         00455e08     MOV        EDI,EAX
    //                               LAB_00455e0a                                                 XREF[2]:     00455dfe(j), 00455e06(j)  
    //                              map.cpp:487 (8)
    //         00455e0a     MOV        EBX,dword ptr [ESP + param_3]
    //         00455e0e     CMP        EBX,EDX
    //         00455e10     JGE        LAB_00455e16
    //                              map.cpp:488 (2)
    //         00455e12     XOR        EBX,EBX
    //                              map.cpp:489 (10)
    //         00455e14     JMP        LAB_00455e20
    //                               LAB_00455e16                                                 XREF[1]:     00455e10(j)  
    //         00455e16     MOV        EAX,dword ptr [ECX + this->map_width]
    //         00455e19     DEC        EAX
    //         00455e1a     CMP        EBX,EAX
    //         00455e1c     JLE        LAB_00455e20
    //                              map.cpp:490 (2)
    //         00455e1e     MOV        EBX,EAX
    //                               LAB_00455e20                                                 XREF[2]:     00455e14(j), 00455e1c(j)  
    //                              map.cpp:492 (8)
    //         00455e20     MOV        EBP,dword ptr [ESP + param_4]
    //         00455e24     CMP        EBP,EDX
    //         00455e26     JGE        LAB_00455e2e
    //                              map.cpp:493 (4)
    //         00455e28     MOV        dword ptr [ESP + param_4],EDX
    //                              map.cpp:494 (10)
    //         00455e2c     JMP        LAB_00455e3a
    //                               LAB_00455e2e                                                 XREF[1]:     00455e26(j)  
    //         00455e2e     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00455e31     DEC        EAX
    //         00455e32     CMP        EBP,EAX
    //         00455e34     JLE        LAB_00455e3a
    //                              map.cpp:495 (4)
    //         00455e36     MOV        dword ptr [ESP + param_4],EAX
    //                               LAB_00455e3a                                                 XREF[2]:     00455e2c(j), 00455e34(j)  
    //                              map.cpp:497 (10)
    //         00455e3a     CMP        EDI,dword ptr [ESP + param_4]
    //         00455e3e     JG         LAB_00455ed3
    //                              map.cpp:499 (21)
    //         00455e44     LEA        EDX,[ESI + ESI*0x2]
    //         00455e47     SHL        EDX,0x3
    //         00455e4a     MOV        dword ptr [ESP + param_2],EDX
    //                               LAB_00455e4e                                                 XREF[1]:     00455ecd(j)  
    //         00455e4e     MOV        EAX,dword ptr [ECX + this->map_row_offset]
    //         00455e54     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         00455e57     ADD        EAX,EDX
    //                              map.cpp:501 (4)
    //         00455e59     CMP        ESI,EBX
    //         00455e5b     JG         LAB_00455ec6
    //                               LAB_00455e5d                                                 XREF[1]:     00455ebc(j)  
    //                              map.cpp:503 (16)
    //         00455e5d     LEA        EDX,[EDI + ESI*0x1]
    //         00455e60     MOV        EBP,EDI
    //         00455e62     IMUL       DX,word ptr [ECX + this->tile_half_width]
    //         00455e6a     MOV        word ptr [EAX],DX
    //                              map.cpp:504 (30)
    //         00455e6d     MOV        DL,byte ptr [EAX + 0x5]
    //         00455e70     SHR        DL,0x5
    //         00455e73     MOVZX      DX,DL
    //         00455e77     IMUL       DX,word ptr [ECX + this->elev_height]
    //         00455e7f     SUB        EBP,ESI
    //         00455e81     IMUL       BP,word ptr [ECX + this->tile_half_height]
    //         00455e89     SUB        EBP,EDX
    //                              map.cpp:506 (32)
    //         00455e8b     XOR        EDX,EDX
    //         00455e8d     MOV        DL,byte ptr [EAX + 0x4]
    //         00455e90     MOV        word ptr [EAX + 0x2],BP
    //         00455e94     LEA        EBP,[EDX + -0x2]
    //         00455e97     CMP        EBP,0xe
    //         00455e9a     JA         switchD_00455ea4::caseD_3
    //         00455e9c     XOR        EDX,EDX
    //         00455e9e     MOV        DL,byte ptr [EBP + 0x455ef4]=>PTR_caseD_3_0045
    //                               switchD_00455ea4::switchD
    //         00455ea4     JMP        dword ptr [EDX*0x4 + switchD_00455ea4::switchd   = 00455eab
    //                               switchD_00455ea4::caseD_6                                    XREF[6]:     00455ea4(j), 00455edc(*), 
    //                               switchD_00455ea4::caseD_8                                                 00455ee0(*), 00455ee4(*), 
    //                               switchD_00455ea4::caseD_a                                                 00455ee8(*), 00455eec(*)  
    //                               switchD_00455ea4::caseD_e
    //                               switchD_00455ea4::caseD_f
    //                               switchD_00455ea4::caseD_10
    //                               switchD_00455ea4::caseD_2
    //                              map.cpp:515 (11)
    //         00455eab     MOV        DX,word ptr [ECX + this->elev_height]
    //         00455eb2     SUB        word ptr [EAX + 0x2],DX
    //                               switchD_00455ea4::caseD_4                                    XREF[3]:     00455e9a(j), 00455ea4(j), 
    //                               switchD_00455ea4::caseD_5                                                 00455ef0(*)  
    //                               switchD_00455ea4::caseD_7
    //                               switchD_00455ea4::caseD_9
    //                               switchD_00455ea4::caseD_b
    //                               switchD_00455ea4::caseD_c
    //                               switchD_00455ea4::caseD_d
    //                               switchD_00455ea4::caseD_3
    //                              map.cpp:519 (29)
    //         00455eb6     ADD        EAX,0x18
    //         00455eb9     INC        ESI
    //         00455eba     CMP        ESI,EBX
    //         00455ebc     JLE        LAB_00455e5d
    //         00455ebe     MOV        ESI,dword ptr [ESP + param_1]
    //         00455ec2     MOV        EDX,dword ptr [ESP + param_2]
    //                               LAB_00455ec6                                                 XREF[1]:     00455e5b(j)  
    //         00455ec6     MOV        EAX,dword ptr [ESP + param_4]
    //         00455eca     INC        EDI
    //         00455ecb     CMP        EDI,EAX
    //         00455ecd     JLE        LAB_00455e4e
    //                               LAB_00455ed3                                                 XREF[1]:     00455e3e(j)  
    //                              map.cpp:522 (48)
    //         00455ed3     POP        EDI
    //         00455ed4     POP        ESI
    //         00455ed5     POP        EBP
    //         00455ed6     POP        EBX
    //         00455ed7     RET        0x10
}

// Offset: 0x00455EDA
undefined FUN_00455eda() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00455eda()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00455eda
    //         00455eda     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00455ea4::switchdataD_00455edc                       XREF[1]:     set_map_screen_pos:00455ea4(*)  
}

// Offset: 0x00455F10
void scenario_save(RGE_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::scenario_save(int)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall scenario_save(RGE_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     00455f17(R), 00455f7c(W), 00455f86(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00455f22(W), 00455f5d(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00455f43(W), 00455fca(R), 00455fd6(W)  
    //              undefined1        Stack[-0x9]:1  local_9                   XREF[2]:     00455f93(W), 00455fb0(*)  
    //              undefined1        Stack[-0xa]:1  local_a                   XREF[2]:     00455f8f(W), 00455fa0(*)  
    //              short             Stack[-0xc]:2  y
    //              uchar             Stack[-0xd]:1  overlay_info
    //              uchar             Stack[-0xe]:1  height_info
    //                               ?scenario_save@RGE_Map@@QAEXH@Z                              XREF[1]:     save_scenario:00543b15(c)  
    //                               RGE_Map::scenario_save
    //                              map.cpp:526 (7)
    //         00455f10     SUB        ESP,0xc
    //         00455f13     PUSH       EBX
    //         00455f14     MOV        EBX,this
    //         00455f16     PUSH       ESI
    //                              map.cpp:533 (23)
    //         00455f17     MOV        ESI,dword ptr [ESP + param_1]
    //         00455f1b     LEA        EAX,[EBX + 0x8]
    //         00455f1e     PUSH       0x4
    //         00455f20     PUSH       EAX
    //         00455f21     PUSH       ESI
    //         00455f22     MOV        dword ptr [ESP + local_4],EBX
    //         00455f26     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00455f2b     ADD        ESP,0xc
    //                              map.cpp:534 (12)
    //         00455f2e     ADD        EBX,0xc
    //         00455f31     PUSH       0x4
    //         00455f33     PUSH       EBX
    //         00455f34     PUSH       ESI
    //         00455f35     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:536 (21)
    //         00455f3a     MOV        EAX,dword ptr [EBX]
    //         00455f3c     ADD        ESP,0xc
    //         00455f3f     XOR        this,this
    //         00455f41     TEST       EAX,EAX
    //         00455f43     MOV        dword ptr [ESP + local_8],this
    //         00455f47     JLE        LAB_00455fe2
    //         00455f4d     PUSH       EDI
    //         00455f4e     PUSH       EBP
    //                               LAB_00455f4f                                                 XREF[1]:     00455fda(j)  
    //                              map.cpp:537 (6)
    //         00455f4f     XOR        EDI,EDI
    //         00455f51     TEST       EAX,EAX
    //         00455f53     JLE        LAB_00455fce
    //                              map.cpp:540 (24)
    //         00455f55     MOVSX      EBP,this
    //         00455f58     SHL        EBP,0x2
    //         00455f5b     XOR        EAX,EAX
    //                               LAB_00455f5d                                                 XREF[1]:     00455fc8(j)  
    //         00455f5d     MOV        this,dword ptr [ESP + local_4]
    //         00455f61     LEA        EAX,[EAX + EAX*0x2]
    //         00455f64     SHL        EAX,0x3
    //         00455f67     MOV        EDX,dword ptr [ECX + this->map_row_offset]
    //                              map.cpp:542 (51)
    //         00455f6d     PUSH       0x1
    //         00455f6f     LEA        this,[EDX + EBP*0x1]
    //         00455f72     MOV        EDX,dword ptr [EDX + EBP*0x1]
    //         00455f75     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x5]
    //         00455f79     AND        DL,0x1f
    //         00455f7c     MOV        byte ptr [ESP + param_1],DL
    //         00455f80     MOV        this,dword ptr [this->_padding_]
    //         00455f82     MOV        DL,byte ptr [ECX + EAX*0x1 + this+0x5]
    //         00455f86     LEA        EAX=>param_1,[ESP + 0x24]
    //         00455f8a     SHR        DL,0x5
    //         00455f8d     PUSH       EAX
    //         00455f8e     PUSH       ESI
    //         00455f8f     MOV        byte ptr [ESP + local_a],DL
    //         00455f93     MOV        byte ptr [ESP + local_9],0x0
    //         00455f98     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00455f9d     ADD        ESP,0xc
    //                              map.cpp:543 (16)
    //         00455fa0     LEA        this=>local_a,[ESP + 0x12]
    //         00455fa4     PUSH       0x1
    //         00455fa6     PUSH       this
    //         00455fa7     PUSH       ESI
    //         00455fa8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00455fad     ADD        ESP,0xc
    //                              map.cpp:544 (26)
    //         00455fb0     LEA        EDX=>local_9,[ESP + 0x13]
    //         00455fb4     PUSH       0x1
    //         00455fb6     PUSH       EDX
    //         00455fb7     PUSH       ESI
    //         00455fb8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00455fbd     MOV        this,dword ptr [EBX]
    //         00455fbf     ADD        ESP,0xc
    //         00455fc2     INC        EDI
    //         00455fc3     MOVSX      EAX,DI
    //         00455fc6     CMP        EAX,this
    //         00455fc8     JL         LAB_00455f5d
    //                              map.cpp:537 (4)
    //         00455fca     MOV        this,dword ptr [ESP + local_8]
    //                               LAB_00455fce                                                 XREF[1]:     00455f53(j)  
    //                              map.cpp:536 (20)
    //         00455fce     MOV        EAX,dword ptr [EBX]
    //         00455fd0     INC        this
    //         00455fd1     MOVSX      EDX,this
    //         00455fd4     CMP        EDX,EAX
    //         00455fd6     MOV        dword ptr [ESP + local_8],this
    //         00455fda     JL         LAB_00455f4f
    //         00455fe0     POP        EBP
    //         00455fe1     POP        EDI
    //                               LAB_00455fe2                                                 XREF[1]:     00455f47(j)  
    //                              map.cpp:546 (8)
    //         00455fe2     POP        ESI
    //         00455fe3     POP        EBX
    //         00455fe4     ADD        ESP,0xc
    //         00455fe7     RET        0x4
}

// Offset: 0x00455FF0
void scenario_load(RGE_Map* this_, int param_2, uchar* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::scenario_load(int,unsigned char *)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall scenario_load(RGE_Map * this, int param_1, uchar * p
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     00455ff4(R), 00456053(*), 0045609a(R)  
    //              uchar *           Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00455ff9(*), 0045601c(R)  
    //              long              Stack[-0x8]:4  w                         XREF[2]:     0045600b(*), 00456018(R)  
    //              long              Stack[-0xc]:4  h                         XREF[3]:     00456033(W), 004560db(R), 004560e8(W)  
    //              short             Stack[-0x10]:2 y                         XREF[3]:     00456043(W), 004560c4(R), 004560cc(W)  
    //              undefined         Stack[-0x11]:1 local_11                  XREF[1]:     00456073(*)  
    //              undefined         Stack[-0x12]:1 local_12                  XREF[2]:     00456063(*), 004560b0(R)  
    //              short             Stack[-0x14]:2 x
    //              uchar             Stack[-0x15]:1 overlay_info
    //              uchar             Stack[-0x16]:1 height_info
    //                               ?scenario_load@RGE_Map@@QAEXHPAE@Z                           XREF[1]:     scenario_make_map:005442ea(c)  
    //                               RGE_Map::scenario_load
    //                              map.cpp:550 (4)
    //         00455ff0     SUB        ESP,0x14
    //         00455ff3     PUSH       EBP
    //                              map.cpp:559 (23)
    //         00455ff4     MOV        EBP,dword ptr [ESP + param_1]
    //         00455ff8     PUSH       EDI
    //         00455ff9     LEA        EAX=>local_4,[ESP + 0x18]
    //         00455ffd     PUSH       0x4
    //         00455fff     PUSH       EAX
    //         00456000     MOV        EDI,this
    //         00456002     PUSH       EBP
    //         00456003     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00456008     ADD        ESP,0xc
    //                              map.cpp:560 (13)
    //         0045600b     LEA        this=>w,[ESP + 0x14]
    //         0045600f     PUSH       0x4
    //         00456011     PUSH       this
    //         00456012     PUSH       EBP
    //         00456013     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              map.cpp:562 (20)
    //         00456018     MOV        EDX,dword ptr [ESP + w]
    //         0045601c     MOV        EAX,dword ptr [ESP + local_4]
    //         00456020     ADD        ESP,0xc
    //         00456023     MOV        this,EDI
    //         00456025     PUSH       EDX
    //         00456026     PUSH       EAX
    //         00456027     CALL       RGE_Map::new_map                                 void new_map(RGE_Map * this, long param_1, lo
    //                              map.cpp:564 (19)
    //         0045602c     MOV        EAX,dword ptr [EDI + 0xc]
    //         0045602f     XOR        this,this
    //         00456031     TEST       EAX,EAX
    //         00456033     MOV        dword ptr [ESP + h],this
    //         00456037     JLE        LAB_004560f4
    //         0045603d     PUSH       ESI
    //         0045603e     PUSH       EBX
    //                               LAB_0045603f                                                 XREF[1]:     004560ec(j)  
    //                              map.cpp:565 (14)
    //         0045603f     XOR        ESI,ESI
    //         00456041     CMP        EAX,ESI
    //         00456043     MOV        dword ptr [ESP + y],ESI
    //         00456047     JLE        LAB_004560df
    //                              map.cpp:571 (142)
    //         0045604d     MOVSX      EBX,this
    //         00456050     SHL        EBX,0x2
    //                               LAB_00456053                                                 XREF[1]:     004560d5(j)  
    //         00456053     LEA        this=>param_1,[ESP + 0x28]
    //         00456057     PUSH       0x1
    //         00456059     PUSH       this
    //         0045605a     PUSH       EBP
    //         0045605b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00456060     ADD        ESP,0xc
    //         00456063     LEA        EDX=>local_12,[ESP + 0x12]
    //         00456067     PUSH       0x1
    //         00456069     PUSH       EDX
    //         0045606a     PUSH       EBP
    //         0045606b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00456070     ADD        ESP,0xc
    //         00456073     LEA        EAX=>local_11,[ESP + 0x13]
    //         00456077     PUSH       0x1
    //         00456079     PUSH       EAX
    //         0045607a     PUSH       EBP
    //         0045607b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00456080     MOV        this,dword ptr [EDI + 0x8d8c]
    //         00456086     LEA        EAX,[ESI + ESI*0x2]
    //         00456089     SHL        EAX,0x3
    //         0045608c     MOV        EDX,dword ptr [EBX + this->_padding_*0x1]
    //         0045608f     ADD        ESP,0xc
    //         00456092     MOV        this,byte ptr [EDX + EAX*0x1 + 0x5]
    //         00456096     LEA        ESI,[EDX + EAX*0x1 + 0x5]
    //         0045609a     MOV        DL,byte ptr [ESP + param_1]
    //         0045609e     XOR        DL,this
    //         004560a0     AND        DL,0x1f
    //         004560a3     XOR        DL,this
    //         004560a5     MOV        byte ptr [ESI],DL
    //         004560a7     MOV        this,dword ptr [EDI + 0x8d8c]
    //         004560ad     MOV        EDX,dword ptr [EBX + this->_padding_*0x1]
    //         004560b0     MOV        this,byte ptr [ESP + local_12]
    //         004560b4     SHL        this,0x5
    //         004560b7     LEA        EAX,[EDX + EAX*0x1 + 0x5]
    //         004560bb     MOV        DL,byte ptr [EAX]
    //         004560bd     AND        DL,0x1f
    //         004560c0     OR         this,DL
    //         004560c2     MOV        byte ptr [EAX],this
    //         004560c4     MOV        EAX,dword ptr [ESP + y]
    //         004560c8     INC        EAX
    //         004560c9     MOVSX      ESI,AX
    //         004560cc     MOV        dword ptr [ESP + y],EAX
    //         004560d0     MOV        EAX,dword ptr [EDI + 0xc]
    //         004560d3     CMP        ESI,EAX
    //         004560d5     JL         LAB_00456053
    //                              map.cpp:565 (4)
    //         004560db     MOV        this,dword ptr [ESP + h]
    //                               LAB_004560df                                                 XREF[1]:     00456047(j)  
    //                              map.cpp:564 (21)
    //         004560df     MOV        EAX,dword ptr [EDI + 0xc]
    //         004560e2     INC        this
    //         004560e3     MOVSX      EDX,this
    //         004560e6     CMP        EDX,EAX
    //         004560e8     MOV        dword ptr [ESP + h],this
    //         004560ec     JL         LAB_0045603f
    //         004560f2     POP        EBX
    //         004560f3     POP        ESI
    //                               LAB_004560f4                                                 XREF[1]:     00456037(j)  
    //                              map.cpp:575 (31)
    //         004560f4     MOV        AX,word ptr [EDI + 0xc]
    //         004560f8     MOV        this,word ptr [EDI + 0x8]
    //         004560fc     PUSH       0x0
    //         004560fe     PUSH       0x0
    //         00456100     DEC        AX
    //         00456102     PUSH       0x0
    //         00456104     DEC        this
    //         00456106     PUSH       EAX
    //         00456107     PUSH       this
    //         00456108     PUSH       0x0
    //         0045610a     PUSH       0x0
    //         0045610c     MOV        this,EDI
    //         0045610e     CALL       RGE_Map::set_elev                                void set_elev(RGE_Map * this, short param_1, 
    //                              map.cpp:576 (35)
    //         00456113     MOV        DX,word ptr [EDI + 0xc]
    //         00456117     MOV        AX,word ptr [EDI + 0x8]
    //         0045611b     PUSH       0x0
    //         0045611d     PUSH       0x0
    //         0045611f     DEC        DX
    //         00456121     PUSH       0x0
    //         00456123     DEC        AX
    //         00456125     PUSH       EDX
    //         00456126     PUSH       EAX
    //         00456127     PUSH       0x0
    //         00456129     PUSH       0x0
    //         0045612b     PUSH       0x0
    //         0045612d     PUSH       0x0
    //         0045612f     MOV        this,EDI
    //         00456131     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Player *
    //                              map.cpp:581 (8)
    //         00456136     POP        EDI
    //         00456137     POP        EBP
    //         00456138     ADD        ESP,0x14
    //         0045613b     RET        0x8
}

// Offset: 0x00456140
RGE_Tile** give_up_map_offsets(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Tile * * __thiscall RGE_Map::give_up_map_offsets(void)                             *
    //                              *********************************************************************************************************
    //                              RGE_Tile * * __thiscall give_up_map_offsets(RGE_Map * this)
    //              RGE_Tile * *      EAX:4          <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ?give_up_map_offsets@RGE_Map@@QAEPAPAURGE_Tile@@XZ           XREF[2]:     RGE_Random_Map_Module:004807b0(c), 
    //                               RGE_Map::give_up_map_offsets                                              update_map_info:00480c40(c)  
    //                              map.cpp:587 (6)
    //         00456140     MOV        EAX,dword ptr [ECX + this->map_row_offset]
    //                              map.cpp:589 (1)
    //         00456146     RET
}

// Offset: 0x00456150
long get_map_width(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Map::get_map_width(void)                                                  *
    //                              *********************************************************************************************************
    //                              long __thiscall get_map_width(RGE_Map * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ?get_map_width@RGE_Map@@QAEJXZ                               XREF[2]:     RGE_Random_Map_Module:004807bb(c), 
    //                               RGE_Map::get_map_width                                                    update_map_info:00480c4b(c)  
    //                              map.cpp:593 (3)
    //         00456150     MOV        EAX,dword ptr [ECX + this->map_width]
    //                              map.cpp:595 (1)
    //         00456153     RET
}

// Offset: 0x00456160
long get_map_height(RGE_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Map::get_map_height(void)                                                 *
    //                              *********************************************************************************************************
    //                              long __thiscall get_map_height(RGE_Map * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //                               ?get_map_height@RGE_Map@@QAEJXZ                              XREF[2]:     RGE_Random_Map_Module:004807c6(c), 
    //                               RGE_Map::get_map_height                                                   update_map_info:00480c56(c)  
    //                              map.cpp:599 (3)
    //         00456160     MOV        EAX,dword ptr [ECX + this->map_height]
    //                              map.cpp:601 (1)
    //         00456163     RET
}

// Offset: 0x00456170
uchar postclean_elevation(RGE_Map* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Map::postclean_elevation(long,long,long,long,unsigned char)      *
    //                              *********************************************************************************************************
    //                              uchar __thiscall postclean_elevation(RGE_Map * this, long param_1, l
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     0045618f(R), 004561ad(W), 004564b9(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     004561b1(R), 0045622b(W), 00456482(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     004561bd(R), 004561c7(W), 00456499(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     004561ce(R), 004561d8(W), 004564c1(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0045620b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004561f0(W), 004564ad(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0045619d(W), 0045621d(R), 004564b1(R)  
    //              short             Stack[-0xc]:2  offset2                   XREF[3]:     004561a1(W), 004562ec(R), 00456416(R)  
    //              short             Stack[-0x10]:2 offset3                   XREF[3]:     0045617d(W), 004562cc(R), 004563f6(R)  
    //              short             Stack[-0x14]:2 offset1                   XREF[6]:     00456199(W), 0045625c(R), 0045629d(R), 00456386(R), 
    //                                                                                     004563c7(R), 004564bd(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[7]:     00456187(W), 0045626a(R), 00456318(R), 0045633f(R), 
    //                                                                                     00456394(R), 0045643e(R), 00456461(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[8]:     004561e0(W), 00456221(R), 004562bc(R), 00456306(R), 
    //                                                                                     004563e6(R), 00456430(R), 004564b5(R), 004564c8(W)  
    //              long              Stack[-0x20]:4 index1                    XREF[13]:    004561fa(W), 00456284(R), 004562c4(R), 004562e6(R), 
    //                                                                                     00456310(R), 00456335(R), 004563ae(R), 004563ee(R), 
    //                                                                                     00456410(R), 00456436(R), 0045645b(R), 00456495(R), 
    //                                                                                     004564a3(W)  
    //              long              Stack[-0x24]:4 index2                    XREF[0,5]:   004561a5(W), 00456486(W), 004564d2(R), 00456211(W), 
    //                                                                                     00456218(R)  
    //              uchar             Stack[-0x27]:1 was_bad
    //                               ?postclean_elevation@RGE_Map@@QAEEJJJJE@Z                    XREF[1]:     clean_elevation:00456e4f(c)  
    //                               RGE_Map::postclean_elevation
    //                              map.cpp:605 (3)
    //         00456170     SUB        ESP,0x24
    //                              map.cpp:608 (14)
    //         00456173     MOV        AX,word ptr [ECX + this->map_width]
    //         00456177     OR         EDX,0xffffffff
    //         0045617a     SUB        EDX,EAX
    //         0045617c     PUSH       EBX
    //         0045617d     MOV        dword ptr [ESP + offset3],EDX
    //                              map.cpp:610 (14)
    //         00456181     MOV        EDX,0x1
    //         00456186     PUSH       EBP
    //         00456187     MOV        dword ptr [ESP + local_18],EAX
    //         0045618b     MOV        EBP,EAX
    //         0045618d     SUB        EDX,EAX
    //                              map.cpp:625 (29)
    //         0045618f     MOV        EAX,dword ptr [ESP + param_1]
    //         00456193     PUSH       ESI
    //         00456194     NEG        EBP
    //         00456196     TEST       EAX,EAX
    //         00456198     PUSH       EDI
    //         00456199     MOV        dword ptr [ESP + offset1],this
    //         0045619d     MOV        dword ptr [ESP + local_8],EBP
    //         004561a1     MOV        dword ptr [ESP + offset2],EDX
    //         004561a5     MOV        byte ptr [ESP + index2+0x1],0x0
    //         004561aa     JLE        LAB_004561b1
    //                              map.cpp:626 (5)
    //         004561ac     DEC        EAX
    //         004561ad     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_004561b1                                                 XREF[1]:     004561aa(j)  
    //                              map.cpp:627 (8)
    //         004561b1     MOV        EDX,dword ptr [ESP + param_2]
    //         004561b5     TEST       EDX,EDX
    //         004561b7     JLE        LAB_004561ba
    //                              map.cpp:628 (1)
    //         004561b9     DEC        EDX
    //                               LAB_004561ba                                                 XREF[1]:     004561b7(j)  
    //                              map.cpp:629 (12)
    //         004561ba     MOV        ESI,dword ptr [ECX + this->map_width]
    //         004561bd     MOV        EDI,dword ptr [ESP + param_3]
    //         004561c1     DEC        ESI
    //         004561c2     CMP        EDI,ESI
    //         004561c4     JGE        LAB_004561cb
    //                              map.cpp:630 (5)
    //         004561c6     INC        EDI
    //         004561c7     MOV        dword ptr [ESP + param_3],EDI
    //                               LAB_004561cb                                                 XREF[1]:     004561c4(j)  
    //                              map.cpp:631 (12)
    //         004561cb     MOV        EBX,dword ptr [ECX + this->map_height]
    //         004561ce     MOV        ESI,dword ptr [ESP + param_4]
    //         004561d2     DEC        EBX
    //         004561d3     CMP        ESI,EBX
    //         004561d5     JGE        LAB_004561dc
    //                              map.cpp:632 (5)
    //         004561d7     INC        ESI
    //         004561d8     MOV        dword ptr [ESP + param_4],ESI
    //                               LAB_004561dc                                                 XREF[1]:     004561d5(j)  
    //                              map.cpp:635 (14)
    //         004561dc     MOV        EBX,EDX
    //         004561de     CMP        EDX,ESI
    //         004561e0     MOV        dword ptr [ESP + local_1c],EBX
    //         004561e4     JG         LAB_004564d2
    //                              map.cpp:637 (16)
    //         004561ea     LEA        EDX,[EAX + EAX*0x2]
    //         004561ed     SHL        EDX,0x3
    //         004561f0     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_004561f4                                                 XREF[1]:     004564cc(j)  
    //         004561f4     MOV        ESI,dword ptr [ECX + this->map_row_offset]
    //                              map.cpp:638 (17)
    //         004561fa     MOV        dword ptr [ESP + index1],EAX
    //         004561fe     MOV        ESI,dword ptr [ESI + EBX*0x4]
    //         00456201     ADD        ESI,EDX
    //         00456203     CMP        EAX,EDI
    //         00456205     JG         LAB_004564c1
    //                              map.cpp:642 (52)
    //         0045620b     MOVZX      DI,byte ptr [ESP + param_5]
    //         00456211     MOV        word ptr [ESP + index2+0x2],DI
    //         00456216     JMP        LAB_00456225
    //                               LAB_00456218                                                 XREF[1]:     004564a7(j)  
    //         00456218     MOV        DI,word ptr [ESP + index2+0x2]
    //         0045621d     MOV        EBP,dword ptr [ESP + local_8]
    //         00456221     MOV        EBX,dword ptr [ESP + local_1c]
    //                               LAB_00456225                                                 XREF[1]:     00456216(j)  
    //         00456225     MOV        this,byte ptr [ESI + 0x5]
    //         00456228     XOR        DX,DX
    //         0045622b     MOV        byte ptr [ESP + param_2],this
    //         0045622f     XOR        AL,AL
    //         00456231     SHR        this,0x5
    //         00456234     MOV        DL,this
    //         00456236     CMP        DX,DI
    //         00456239     JGE        LAB_00456363
    //                              map.cpp:644 (1)
    //         0045623f     INC        EDX
    //                              map.cpp:645 (4)
    //         00456240     TEST       EBX,EBX
    //         00456242     JLE        LAB_0045625c
    //                              map.cpp:646 (22)
    //         00456244     MOVSX      EDI,BP
    //         00456247     LEA        this,[EDI + EDI*0x2]
    //         0045624a     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         0045624e     SHR        this,0x5
    //         00456251     MOVZX      this,this
    //         00456255     CMP        this,DX
    //         00456258     JLE        LAB_0045625c
    //                              map.cpp:647 (2)
    //         0045625a     MOV        AL,0x1
    //                               LAB_0045625c                                                 XREF[2]:     00456242(j), 00456258(j)  
    //                              map.cpp:649 (14)
    //         0045625c     MOV        this,dword ptr [ESP + offset1]
    //         00456260     MOV        EDI,dword ptr [ECX + this->map_height]
    //         00456263     LEA        EBP,[EDI + -0x1]
    //         00456266     CMP        EBX,EBP
    //         00456268     JGE        LAB_00456284
    //                              map.cpp:650 (24)
    //         0045626a     MOVSX      EDI,word ptr [ESP + local_18]
    //         0045626f     LEA        this,[EDI + EDI*0x2]
    //         00456272     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456276     SHR        this,0x5
    //         00456279     MOVZX      this,this
    //         0045627d     CMP        this,DX
    //         00456280     JLE        LAB_00456284
    //                              map.cpp:651 (2)
    //         00456282     MOV        AL,0x1
    //                               LAB_00456284                                                 XREF[2]:     00456268(j), 00456280(j)  
    //                              map.cpp:653 (8)
    //         00456284     MOV        this,dword ptr [ESP + index1]
    //         00456288     TEST       this,this
    //         0045628a     JLE        LAB_0045629d
    //                              map.cpp:654 (15)
    //         0045628c     MOV        BL,byte ptr [ESI + -0x13]
    //         0045628f     SHR        BL,0x5
    //         00456292     MOVZX      DI,BL
    //         00456296     CMP        DI,DX
    //         00456299     JLE        LAB_0045629d
    //                              map.cpp:655 (2)
    //         0045629b     MOV        AL,0x1
    //                               LAB_0045629d                                                 XREF[2]:     0045628a(j), 00456299(j)  
    //                              map.cpp:657 (14)
    //         0045629d     MOV        EDI,dword ptr [ESP + offset1]
    //         004562a1     MOV        EDI,dword ptr [EDI + 0x8]
    //         004562a4     LEA        EBX,[EDI + -0x1]
    //         004562a7     CMP        this,EBX
    //         004562a9     JGE        LAB_004562bc
    //                              map.cpp:658 (15)
    //         004562ab     MOV        this,byte ptr [ESI + 0x1d]
    //         004562ae     SHR        this,0x5
    //         004562b1     MOVZX      this,this
    //         004562b5     CMP        this,DX
    //         004562b8     JLE        LAB_004562bc
    //                              map.cpp:659 (2)
    //         004562ba     MOV        AL,0x1
    //                               LAB_004562bc                                                 XREF[2]:     004562a9(j), 004562b8(j)  
    //                              map.cpp:661 (8)
    //         004562bc     MOV        this,dword ptr [ESP + local_1c]
    //         004562c0     TEST       this,this
    //         004562c2     JLE        LAB_00456306
    //                              map.cpp:663 (8)
    //         004562c4     MOV        this,dword ptr [ESP + index1]
    //         004562c8     TEST       this,this
    //         004562ca     JLE        LAB_004562e6
    //                              map.cpp:664 (24)
    //         004562cc     MOVSX      EDI,word ptr [ESP + offset3]
    //         004562d1     LEA        this,[EDI + EDI*0x2]
    //         004562d4     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         004562d8     SHR        this,0x5
    //         004562db     MOVZX      this,this
    //         004562df     CMP        this,DX
    //         004562e2     JLE        LAB_004562e6
    //                              map.cpp:665 (2)
    //         004562e4     MOV        AL,0x1
    //                               LAB_004562e6                                                 XREF[2]:     004562ca(j), 004562e2(j)  
    //                              map.cpp:667 (6)
    //         004562e6     CMP        dword ptr [ESP + index1],EBX
    //         004562ea     JGE        LAB_00456306
    //                              map.cpp:668 (24)
    //         004562ec     MOVSX      EDI,word ptr [ESP + offset2]
    //         004562f1     LEA        this,[EDI + EDI*0x2]
    //         004562f4     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         004562f8     SHR        this,0x5
    //         004562fb     MOVZX      this,this
    //         004562ff     CMP        this,DX
    //         00456302     JLE        LAB_00456306
    //                              map.cpp:669 (2)
    //         00456304     MOV        AL,0x1
    //                               LAB_00456306                                                 XREF[3]:     004562c2(j), 004562ea(j), 
    //                                                                                                         00456302(j)  
    //                              map.cpp:672 (10)
    //         00456306     CMP        dword ptr [ESP + local_1c],EBP
    //         0045630a     JGE        LAB_0045647e
    //                              map.cpp:674 (8)
    //         00456310     MOV        this,dword ptr [ESP + index1]
    //         00456314     TEST       this,this
    //         00456316     JLE        LAB_00456335
    //                              map.cpp:675 (27)
    //         00456318     MOV        this,dword ptr [ESP + local_18]
    //         0045631c     DEC        this
    //         0045631d     MOVSX      EDI,this
    //         00456320     LEA        this,[EDI + EDI*0x2]
    //         00456323     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456327     SHR        this,0x5
    //         0045632a     MOVZX      this,this
    //         0045632e     CMP        this,DX
    //         00456331     JLE        LAB_00456335
    //                              map.cpp:676 (2)
    //         00456333     MOV        AL,0x1
    //                               LAB_00456335                                                 XREF[2]:     00456316(j), 00456331(j)  
    //                              map.cpp:678 (10)
    //         00456335     CMP        dword ptr [ESP + index1],EBX
    //         00456339     JGE        LAB_0045647e
    //                              map.cpp:679 (31)
    //         0045633f     MOV        this,dword ptr [ESP + local_18]
    //         00456343     INC        this
    //         00456344     MOVSX      EDI,this
    //         00456347     LEA        this,[EDI + EDI*0x2]
    //         0045634a     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         0045634e     SHR        this,0x5
    //         00456351     MOVZX      this,this
    //         00456355     CMP        this,DX
    //         00456358     JLE        LAB_0045647e
    //                              map.cpp:683 (11)
    //         0045635e     JMP        LAB_0045647c
    //                               LAB_00456363                                                 XREF[1]:     00456239(j)  
    //         00456363     JLE        LAB_0045647e
    //                              map.cpp:685 (1)
    //         00456369     DEC        EDX
    //                              map.cpp:686 (4)
    //         0045636a     TEST       EBX,EBX
    //         0045636c     JLE        LAB_00456386
    //                              map.cpp:687 (22)
    //         0045636e     MOVSX      EDI,BP
    //         00456371     LEA        this,[EDI + EDI*0x2]
    //         00456374     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456378     SHR        this,0x5
    //         0045637b     MOVZX      this,this
    //         0045637f     CMP        this,DX
    //         00456382     JGE        LAB_00456386
    //                              map.cpp:688 (2)
    //         00456384     MOV        AL,0x1
    //                               LAB_00456386                                                 XREF[2]:     0045636c(j), 00456382(j)  
    //                              map.cpp:690 (14)
    //         00456386     MOV        this,dword ptr [ESP + offset1]
    //         0045638a     MOV        EDI,dword ptr [ECX + this->map_height]
    //         0045638d     LEA        EBP,[EDI + -0x1]
    //         00456390     CMP        EBX,EBP
    //         00456392     JGE        LAB_004563ae
    //                              map.cpp:691 (24)
    //         00456394     MOVSX      EDI,word ptr [ESP + local_18]
    //         00456399     LEA        this,[EDI + EDI*0x2]
    //         0045639c     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         004563a0     SHR        this,0x5
    //         004563a3     MOVZX      this,this
    //         004563a7     CMP        this,DX
    //         004563aa     JGE        LAB_004563ae
    //                              map.cpp:692 (2)
    //         004563ac     MOV        AL,0x1
    //                               LAB_004563ae                                                 XREF[2]:     00456392(j), 004563aa(j)  
    //                              map.cpp:694 (8)
    //         004563ae     MOV        this,dword ptr [ESP + index1]
    //         004563b2     TEST       this,this
    //         004563b4     JLE        LAB_004563c7
    //                              map.cpp:695 (15)
    //         004563b6     MOV        BL,byte ptr [ESI + -0x13]
    //         004563b9     SHR        BL,0x5
    //         004563bc     MOVZX      DI,BL
    //         004563c0     CMP        DI,DX
    //         004563c3     JGE        LAB_004563c7
    //                              map.cpp:696 (2)
    //         004563c5     MOV        AL,0x1
    //                               LAB_004563c7                                                 XREF[2]:     004563b4(j), 004563c3(j)  
    //                              map.cpp:698 (14)
    //         004563c7     MOV        EDI,dword ptr [ESP + offset1]
    //         004563cb     MOV        EDI,dword ptr [EDI + 0x8]
    //         004563ce     LEA        EBX,[EDI + -0x1]
    //         004563d1     CMP        this,EBX
    //         004563d3     JGE        LAB_004563e6
    //                              map.cpp:699 (15)
    //         004563d5     MOV        this,byte ptr [ESI + 0x1d]
    //         004563d8     SHR        this,0x5
    //         004563db     MOVZX      this,this
    //         004563df     CMP        this,DX
    //         004563e2     JGE        LAB_004563e6
    //                              map.cpp:700 (2)
    //         004563e4     MOV        AL,0x1
    //                               LAB_004563e6                                                 XREF[2]:     004563d3(j), 004563e2(j)  
    //                              map.cpp:702 (8)
    //         004563e6     MOV        this,dword ptr [ESP + local_1c]
    //         004563ea     TEST       this,this
    //         004563ec     JLE        LAB_00456430
    //                              map.cpp:704 (8)
    //         004563ee     MOV        this,dword ptr [ESP + index1]
    //         004563f2     TEST       this,this
    //         004563f4     JLE        LAB_00456410
    //                              map.cpp:705 (24)
    //         004563f6     MOVSX      EDI,word ptr [ESP + offset3]
    //         004563fb     LEA        this,[EDI + EDI*0x2]
    //         004563fe     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456402     SHR        this,0x5
    //         00456405     MOVZX      this,this
    //         00456409     CMP        this,DX
    //         0045640c     JGE        LAB_00456410
    //                              map.cpp:706 (2)
    //         0045640e     MOV        AL,0x1
    //                               LAB_00456410                                                 XREF[2]:     004563f4(j), 0045640c(j)  
    //                              map.cpp:708 (6)
    //         00456410     CMP        dword ptr [ESP + index1],EBX
    //         00456414     JGE        LAB_00456430
    //                              map.cpp:709 (24)
    //         00456416     MOVSX      EDI,word ptr [ESP + offset2]
    //         0045641b     LEA        this,[EDI + EDI*0x2]
    //         0045641e     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456422     SHR        this,0x5
    //         00456425     MOVZX      this,this
    //         00456429     CMP        this,DX
    //         0045642c     JGE        LAB_00456430
    //                              map.cpp:710 (2)
    //         0045642e     MOV        AL,0x1
    //                               LAB_00456430                                                 XREF[3]:     004563ec(j), 00456414(j), 
    //                                                                                                         0045642c(j)  
    //                              map.cpp:713 (6)
    //         00456430     CMP        dword ptr [ESP + local_1c],EBP
    //         00456434     JGE        LAB_0045647e
    //                              map.cpp:715 (8)
    //         00456436     MOV        this,dword ptr [ESP + index1]
    //         0045643a     TEST       this,this
    //         0045643c     JLE        LAB_0045645b
    //                              map.cpp:716 (27)
    //         0045643e     MOV        this,dword ptr [ESP + local_18]
    //         00456442     DEC        this
    //         00456443     MOVSX      EDI,this
    //         00456446     LEA        this,[EDI + EDI*0x2]
    //         00456449     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         0045644d     SHR        this,0x5
    //         00456450     MOVZX      this,this
    //         00456454     CMP        this,DX
    //         00456457     JGE        LAB_0045645b
    //                              map.cpp:717 (2)
    //         00456459     MOV        AL,0x1
    //                               LAB_0045645b                                                 XREF[2]:     0045643c(j), 00456457(j)  
    //                              map.cpp:719 (6)
    //         0045645b     CMP        dword ptr [ESP + index1],EBX
    //         0045645f     JGE        LAB_0045647e
    //                              map.cpp:720 (27)
    //         00456461     MOV        this,dword ptr [ESP + local_18]
    //         00456465     INC        this
    //         00456466     MOVSX      EDI,this
    //         00456469     LEA        this,[EDI + EDI*0x2]
    //         0045646c     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456470     SHR        this,0x5
    //         00456473     MOVZX      this,this
    //         00456477     CMP        this,DX
    //         0045647a     JGE        LAB_0045647e
    //                               LAB_0045647c                                                 XREF[1]:     0045635e(j)  
    //                              map.cpp:721 (2)
    //         0045647c     MOV        AL,0x1
    //                               LAB_0045647e                                                 XREF[7]:     0045630a(j), 00456339(j), 
    //                                                                                                         00456358(j), 00456363(j), 
    //                                                                                                         00456434(j), 0045645f(j), 
    //                                                                                                         0045647a(j)  
    //                              map.cpp:725 (4)
    //         0045647e     TEST       AL,AL
    //         00456480     JZ         LAB_00456495
    //                              map.cpp:727 (4)
    //         00456482     MOV        AL,byte ptr [ESP + param_2]
    //                              map.cpp:728 (76)
    //         00456486     MOV        byte ptr [ESP + index2+0x1],0x1
    //         0045648b     SHL        DL,0x5
    //         0045648e     AND        AL,0x1f
    //         00456490     OR         DL,AL
    //         00456492     MOV        byte ptr [ESI + 0x5],DL
    //                               LAB_00456495                                                 XREF[1]:     00456480(j)  
    //         00456495     MOV        EAX,dword ptr [ESP + index1]
    //         00456499     MOV        EDI,dword ptr [ESP + param_3]
    //         0045649d     ADD        ESI,0x18
    //         004564a0     INC        EAX
    //         004564a1     CMP        EAX,EDI
    //         004564a3     MOV        dword ptr [ESP + index1],EAX
    //         004564a7     JLE        LAB_00456218
    //         004564ad     MOV        EDX,dword ptr [ESP + local_4]
    //         004564b1     MOV        EBP,dword ptr [ESP + local_8]
    //         004564b5     MOV        EBX,dword ptr [ESP + local_1c]
    //         004564b9     MOV        EAX,dword ptr [ESP + param_1]
    //         004564bd     MOV        this,dword ptr [ESP + offset1]
    //                               LAB_004564c1                                                 XREF[1]:     00456205(j)  
    //         004564c1     MOV        ESI,dword ptr [ESP + param_4]
    //         004564c5     INC        EBX
    //         004564c6     CMP        EBX,ESI
    //         004564c8     MOV        dword ptr [ESP + local_1c],EBX
    //         004564cc     JLE        LAB_004561f4
    //                               LAB_004564d2                                                 XREF[1]:     004561e4(j)  
    //                              map.cpp:735 (4)
    //         004564d2     MOV        AL,byte ptr [ESP + index2+0x1]
    //                              map.cpp:736 (10)
    //         004564d6     POP        EDI
    //         004564d7     POP        ESI
    //         004564d8     POP        EBP
    //         004564d9     POP        EBX
    //         004564da     ADD        ESP,0x24
    //         004564dd     RET        0x14
}

// Offset: 0x004564E0
void preclean_elevation(RGE_Map* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::preclean_elevation(long,long,long,long,unsigned char)                *
    //                              *********************************************************************************************************
    //                              void __thiscall preclean_elevation(RGE_Map * this, long param_1, lon
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     0045651d(R), 0045653a(W), 00456884(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00456542(R), 0045654b(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     00456552(R), 0045655e(W), 00456589(R), 0045686c(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00456565(R), 0045656f(W), 00456880(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00456742(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00456527(W), 0045653e(W), 00456888(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00456519(W), 004566d1(R), 00456822(R)  
    //              short             Stack[-0xc]:2  offset7                   XREF[4]:     0045657f(W), 004565c6(W), 004566e9(W), 0045681a(R)  
    //              short             Stack[-0x10]:2 place7                    XREF[3]:     004564f6(W), 00456605(R), 004567fe(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00456515(W), 004566f7(R), 004567da(R)  
    //              short             Stack[-0x18]:2 offset5                   XREF[3]:     004565be(W), 0045670f(W), 004567d2(R)  
    //              short             Stack[-0x1c]:2 place5                    XREF[3]:     0045650d(W), 004566a3(R), 0045679e(R)  
    //              short             Stack[-0x20]:2 offset3                   XREF[3]:     004565b6(W), 004566bb(W), 00456796(R)  
    //              short             Stack[-0x24]:2 place3                    XREF[3]:     00456502(W), 004565d4(R), 0045677a(R)  
    //              short             Stack[-0x28]:2 offset2                   XREF[3]:     004564fa(W), 0045667d(R), 00456759(R)  
    //              short             Stack[-0x2c]:2 offset1                   XREF[3]:     004565ad(W), 00456695(W), 00456751(R)  
    //              short             Stack[-0x30]:2 place1                    XREF[4]:     004565ca(W), 0045663c(W), 00456730(R), 0045683e(R)  
    //              short             Stack[-0x34]:2 place8                    XREF[4]:     004565c2(W), 0045661d(W), 0045671e(R), 004567f6(R)  
    //              short             Stack[-0x38]:2 place6                    XREF[4]:     004565ba(W), 00456665(W), 00456728(R), 004567ba(R)  
    //              short             Stack[-0x3c]:2 place4                    XREF[4]:     004564f0(W), 004565f3(R), 00456644(R), 00456892(R)  
    //              undefined4        Stack[-0x40]:4 local_40                  XREF[7]:     00456575(W), 004565a0(R), 004565fd(R), 0045666d(R), 
    //                                                                                     004566c3(R), 0045688c(R), 00456899(W)  
    //              long              Stack[-0x44]:4 index1                    XREF[9]:     0045658d(W), 00456627(R), 0045664e(R), 00456675(R), 
    //                                                                                     0045669d(R), 004566c9(R), 004566f1(R), 00456868(R), 
    //                                                                                     00456876(W)  
    //              long              Stack[-0x48]:4 index2                    XREF[0,3]:   0045652d(W), 00456863(W), 004568a3(R)  
    //              uchar             Stack[-0x49]:1 change_flag
    //                               ?preclean_elevation@RGE_Map@@QAEXJJJJE@Z                     XREF[1]:     clean_elevation:0045698f(c)  
    //                               RGE_Map::preclean_elevation
    //                              map.cpp:740 (8)
    //         004564e0     SUB        ESP,0x48
    //         004564e3     PUSH       EBX
    //         004564e4     PUSH       EBP
    //         004564e5     PUSH       ESI
    //         004564e6     MOV        ESI,this
    //                              map.cpp:751 (22)
    //         004564e8     OR         this,0xffffffff
    //         004564eb     PUSH       EDI
    //         004564ec     MOV        AX,word ptr [ESI + 0x8]
    //         004564f0     MOV        dword ptr [ESP + place4],ESI
    //         004564f4     SUB        this,EAX
    //         004564f6     MOV        dword ptr [ESP + place7],EAX
    //         004564fa     MOV        dword ptr [ESP + offset2],this
    //                              map.cpp:752 (8)
    //         004564fe     MOV        this,EAX
    //         00456500     NEG        this
    //         00456502     MOV        dword ptr [ESP + place3],this
    //                              map.cpp:753 (11)
    //         00456506     MOV        this,0x1
    //         0045650b     SUB        this,EAX
    //         0045650d     MOV        dword ptr [ESP + place5],this
    //                              map.cpp:755 (3)
    //         00456511     LEA        this,[EAX + 0x1]
    //                              map.cpp:757 (23)
    //         00456514     DEC        EAX
    //         00456515     MOV        dword ptr [ESP + local_14],this
    //         00456519     MOV        dword ptr [ESP + local_8],EAX
    //         0045651d     MOV        EAX,dword ptr [ESP + param_1]
    //         00456521     LEA        this,[EAX + EAX*0x2]
    //         00456524     SHL        this,0x3
    //         00456527     MOV        dword ptr [ESP + local_4],this
    //                               LAB_0045652b                                                 XREF[1]:     004568a9(j)  
    //                              map.cpp:768 (11)
    //         0045652b     XOR        EDI,EDI
    //         0045652d     MOV        byte ptr [ESP + index2+0x3],0x0
    //         00456532     CMP        EAX,EDI
    //         00456534     JLE        LAB_00456542
    //                              map.cpp:769 (12)
    //         00456536     DEC        EAX
    //         00456537     SUB        this,0x18
    //         0045653a     MOV        dword ptr [ESP + param_1],EAX
    //         0045653e     MOV        dword ptr [ESP + local_4],this
    //                               LAB_00456542                                                 XREF[1]:     00456534(j)  
    //                              map.cpp:770 (8)
    //         00456542     MOV        EBP,dword ptr [ESP + param_2]
    //         00456546     CMP        EBP,EDI
    //         00456548     JLE        LAB_0045654f
    //                              map.cpp:771 (5)
    //         0045654a     DEC        EBP
    //         0045654b     MOV        dword ptr [ESP + param_2],EBP
    //                               LAB_0045654f                                                 XREF[1]:     00456548(j)  
    //                              map.cpp:772 (12)
    //         0045654f     MOV        EDX,dword ptr [ESI + 0x8]
    //         00456552     MOV        EBX,dword ptr [ESP + param_3]
    //         00456556     DEC        EDX
    //         00456557     CMP        EBX,EDX
    //         00456559     JGE        LAB_00456562
    //                              map.cpp:773 (7)
    //         0045655b     MOV        EDX,EBX
    //         0045655d     INC        EDX
    //         0045655e     MOV        dword ptr [ESP + param_3],EDX
    //                               LAB_00456562                                                 XREF[1]:     00456559(j)  
    //                              map.cpp:774 (12)
    //         00456562     MOV        EBX,dword ptr [ESI + 0xc]
    //         00456565     MOV        EDX,dword ptr [ESP + param_4]
    //         00456569     DEC        EBX
    //         0045656a     CMP        EDX,EBX
    //         0045656c     JGE        LAB_00456573
    //                              map.cpp:775 (5)
    //         0045656e     INC        EDX
    //         0045656f     MOV        dword ptr [ESP + param_4],EDX
    //                               LAB_00456573                                                 XREF[1]:     0045656c(j)  
    //                              map.cpp:778 (12)
    //         00456573     CMP        EBP,EDX
    //         00456575     MOV        dword ptr [ESP + local_40],EBP
    //         00456579     JG         LAB_004568a3
    //                              map.cpp:780 (10)
    //         0045657f     MOV        dword ptr [ESP + offset7],this
    //                               LAB_00456583                                                 XREF[1]:     0045689d(j)  
    //         00456583     MOV        ESI,dword ptr [ESI + 0x8d8c]
    //                              map.cpp:781 (29)
    //         00456589     MOV        EBX,dword ptr [ESP + param_3]
    //         0045658d     MOV        dword ptr [ESP + index1],EAX
    //         00456591     MOV        ESI,dword ptr [ESI + EBP*0x4]
    //         00456594     ADD        ESI,this
    //         00456596     CMP        EAX,EBX
    //         00456598     JG         LAB_00456892
    //         0045659e     JMP        LAB_004565a6
    //                               LAB_004565a0                                                 XREF[1]:     0045687a(j)  
    //         004565a0     MOV        EBP,dword ptr [ESP + local_40]
    //         004565a4     XOR        EDI,EDI
    //                               LAB_004565a6                                                 XREF[1]:     0045659e(j)  
    //                              map.cpp:791 (14)
    //         004565a6     MOV        BL,byte ptr [ESI + 0x5]
    //         004565a9     XOR        this,this
    //         004565ab     MOV        AL,BL
    //         004565ad     MOV        dword ptr [ESP + offset1],EDI
    //         004565b1     SHR        AL,0x5
    //                              map.cpp:793 (56)
    //         004565b4     CMP        EBP,EDI
    //         004565b6     MOV        dword ptr [ESP + offset3],EDI
    //         004565ba     MOV        dword ptr [ESP + place6],EDI
    //         004565be     MOV        dword ptr [ESP + offset5],EDI
    //         004565c2     MOV        dword ptr [ESP + place8],EDI
    //         004565c6     MOV        dword ptr [ESP + offset7],EDI
    //         004565ca     MOV        dword ptr [ESP + place1],EDI
    //         004565ce     MOVZX      AX,AL
    //         004565d2     JLE        LAB_004565f3
    //         004565d4     MOVSX      EDX,word ptr [ESP + place3]
    //         004565d9     LEA        EDX,[EDX + EDX*0x2]
    //         004565dc     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         004565e0     SHR        DL,0x5
    //         004565e3     MOVZX      DX,DL
    //         004565e7     CMP        DX,AX
    //         004565ea     JLE        LAB_004565f1
    //                              map.cpp:794 (7)
    //         004565ec     MOV        this,0x1
    //                               LAB_004565f1                                                 XREF[1]:     004565ea(j)  
    //         004565f1     XOR        EDI,EDI
    //                               LAB_004565f3                                                 XREF[1]:     004565d2(j)  
    //                              map.cpp:796 (42)
    //         004565f3     MOV        EDX,dword ptr [ESP + place4]
    //         004565f7     MOV        EDX,dword ptr [EDX + 0xc]
    //         004565fa     LEA        EBP,[EDX + -0x1]
    //         004565fd     MOV        EDX,dword ptr [ESP + local_40]
    //         00456601     CMP        EDX,EBP
    //         00456603     JGE        LAB_00456627
    //         00456605     MOVSX      EDX,word ptr [ESP + place7]
    //         0045660a     LEA        EDX,[EDX + EDX*0x2]
    //         0045660d     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456611     SHR        DL,0x5
    //         00456614     MOVZX      DX,DL
    //         00456618     CMP        DX,AX
    //         0045661b     JLE        LAB_00456625
    //                              map.cpp:797 (10)
    //         0045661d     MOV        dword ptr [ESP + place8],0x1
    //                               LAB_00456625                                                 XREF[1]:     0045661b(j)  
    //         00456625     XOR        EDI,EDI
    //                               LAB_00456627                                                 XREF[1]:     00456603(j)  
    //                              map.cpp:799 (21)
    //         00456627     CMP        dword ptr [ESP + index1],EDI
    //         0045662b     JLE        LAB_00456644
    //         0045662d     MOV        DL,byte ptr [ESI + -0x13]
    //         00456630     SHR        DL,0x5
    //         00456633     MOVZX      DX,DL
    //         00456637     CMP        DX,AX
    //         0045663a     JLE        LAB_00456644
    //                              map.cpp:800 (8)
    //         0045663c     MOV        dword ptr [ESP + place1],0x1
    //                               LAB_00456644                                                 XREF[2]:     0045662b(j), 0045663a(j)  
    //                              map.cpp:802 (33)
    //         00456644     MOV        EDX,dword ptr [ESP + place4]
    //         00456648     MOV        EDX,dword ptr [EDX + 0x8]
    //         0045664b     LEA        EDI,[EDX + -0x1]
    //         0045664e     MOV        EDX,dword ptr [ESP + index1]
    //         00456652     CMP        EDX,EDI
    //         00456654     JGE        LAB_0045666d
    //         00456656     MOV        DL,byte ptr [ESI + 0x1d]
    //         00456659     SHR        DL,0x5
    //         0045665c     MOVZX      DX,DL
    //         00456660     CMP        DX,AX
    //         00456663     JLE        LAB_0045666d
    //                              map.cpp:803 (8)
    //         00456665     MOV        dword ptr [ESP + place6],0x1
    //                               LAB_0045666d                                                 XREF[2]:     00456654(j), 00456663(j)  
    //                              map.cpp:805 (8)
    //         0045666d     MOV        EDX,dword ptr [ESP + local_40]
    //         00456671     TEST       EDX,EDX
    //         00456673     JLE        LAB_004566c3
    //                              map.cpp:807 (32)
    //         00456675     MOV        EDX,dword ptr [ESP + index1]
    //         00456679     TEST       EDX,EDX
    //         0045667b     JLE        LAB_0045669d
    //         0045667d     MOVSX      EDX,word ptr [ESP + offset2]
    //         00456682     LEA        EDX,[EDX + EDX*0x2]
    //         00456685     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456689     SHR        DL,0x5
    //         0045668c     MOVZX      DX,DL
    //         00456690     CMP        DX,AX
    //         00456693     JLE        LAB_0045669d
    //                              map.cpp:808 (8)
    //         00456695     MOV        dword ptr [ESP + offset1],0x1
    //                               LAB_0045669d                                                 XREF[2]:     0045667b(j), 00456693(j)  
    //                              map.cpp:810 (30)
    //         0045669d     CMP        dword ptr [ESP + index1],EDI
    //         004566a1     JGE        LAB_004566c3
    //         004566a3     MOVSX      EDX,word ptr [ESP + place5]
    //         004566a8     LEA        EDX,[EDX + EDX*0x2]
    //         004566ab     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         004566af     SHR        DL,0x5
    //         004566b2     MOVZX      DX,DL
    //         004566b6     CMP        DX,AX
    //         004566b9     JLE        LAB_004566c3
    //                              map.cpp:811 (8)
    //         004566bb     MOV        dword ptr [ESP + offset3],0x1
    //                               LAB_004566c3                                                 XREF[3]:     00456673(j), 004566a1(j), 
    //                                                                                                         004566b9(j)  
    //                              map.cpp:814 (6)
    //         004566c3     CMP        dword ptr [ESP + local_40],EBP
    //         004566c7     JGE        LAB_00456717
    //                              map.cpp:816 (32)
    //         004566c9     MOV        EDX,dword ptr [ESP + index1]
    //         004566cd     TEST       EDX,EDX
    //         004566cf     JLE        LAB_004566f1
    //         004566d1     MOVSX      EDX,word ptr [ESP + local_8]
    //         004566d6     LEA        EDX,[EDX + EDX*0x2]
    //         004566d9     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         004566dd     SHR        DL,0x5
    //         004566e0     MOVZX      DX,DL
    //         004566e4     CMP        DX,AX
    //         004566e7     JLE        LAB_004566f1
    //                              map.cpp:817 (8)
    //         004566e9     MOV        dword ptr [ESP + offset7],0x1
    //                               LAB_004566f1                                                 XREF[2]:     004566cf(j), 004566e7(j)  
    //                              map.cpp:819 (30)
    //         004566f1     CMP        dword ptr [ESP + index1],EDI
    //         004566f5     JGE        LAB_00456717
    //         004566f7     MOVSX      EDX,word ptr [ESP + local_14]
    //         004566fc     LEA        EDX,[EDX + EDX*0x2]
    //         004566ff     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456703     SHR        DL,0x5
    //         00456706     MOVZX      DX,DL
    //         0045670a     CMP        DX,AX
    //         0045670d     JLE        LAB_00456717
    //                              map.cpp:820 (8)
    //         0045670f     MOV        dword ptr [ESP + offset5],0x1
    //                               LAB_00456717                                                 XREF[3]:     004566c7(j), 004566f5(j), 
    //                                                                                                         0045670d(j)  
    //                              map.cpp:823 (2)
    //         00456717     XOR        DL,DL
    //                              map.cpp:824 (15)
    //         00456719     TEST       this,this
    //         0045671c     JZ         LAB_00456728
    //         0045671e     CMP        word ptr [ESP + place8],0x0
    //         00456724     JZ         LAB_00456728
    //         00456726     MOV        DL,0x1
    //                               LAB_00456728                                                 XREF[2]:     0045671c(j), 00456724(j)  
    //                              map.cpp:825 (18)
    //         00456728     CMP        word ptr [ESP + place6],0x0
    //         0045672e     JZ         LAB_0045673a
    //         00456730     CMP        word ptr [ESP + place1],0x0
    //         00456736     JZ         LAB_0045673a
    //         00456738     MOV        DL,0x1
    //                               LAB_0045673a                                                 XREF[2]:     0045672e(j), 00456736(j)  
    //                              map.cpp:828 (8)
    //         0045673a     TEST       DL,DL
    //         0045673c     JZ         LAB_00456868
    //                              map.cpp:830 (15)
    //         00456742     MOVZX      DX,byte ptr [ESP + param_5]
    //         00456748     CMP        AX,DX
    //         0045674b     JL         LAB_00456856
    //                              map.cpp:832 (36)
    //         00456751     CMP        word ptr [ESP + offset1],0x0
    //         00456757     JZ         LAB_00456775
    //         00456759     MOVSX      EDX,word ptr [ESP + offset2]
    //         0045675e     LEA        EDX,[EDX + EDX*0x2]
    //         00456761     MOV        BL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456765     LEA        EDI,[ESI + EDX*0x8 + 0x5]
    //         00456769     MOV        DL,AL
    //         0045676b     AND        BL,0x1f
    //         0045676e     SHL        DL,0x5
    //         00456771     OR         DL,BL
    //         00456773     MOV        byte ptr [EDI],DL
    //                               LAB_00456775                                                 XREF[1]:     00456757(j)  
    //                              map.cpp:833 (33)
    //         00456775     TEST       this,this
    //         00456778     JZ         LAB_00456796
    //         0045677a     MOVSX      EDX,word ptr [ESP + place3]
    //         0045677f     LEA        this,[EDX + EDX*0x2]
    //         00456782     MOV        DL,AL
    //         00456784     SHL        DL,0x5
    //         00456787     LEA        EDI,[ESI + this->_padding_*0x8 + 0x5]
    //         0045678b     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         0045678f     AND        this,0x1f
    //         00456792     OR         DL,this
    //         00456794     MOV        byte ptr [EDI],DL
    //                               LAB_00456796                                                 XREF[1]:     00456778(j)  
    //                              map.cpp:834 (36)
    //         00456796     CMP        word ptr [ESP + offset3],0x0
    //         0045679c     JZ         LAB_004567ba
    //         0045679e     MOVSX      EDX,word ptr [ESP + place5]
    //         004567a3     MOV        this,AL
    //         004567a5     LEA        EDX,[EDX + EDX*0x2]
    //         004567a8     SHL        this,0x5
    //         004567ab     LEA        EDI,[ESI + EDX*0x8 + 0x5]
    //         004567af     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         004567b3     AND        DL,0x1f
    //         004567b6     OR         this,DL
    //         004567b8     MOV        byte ptr [EDI],this
    //                               LAB_004567ba                                                 XREF[1]:     0045679c(j)  
    //                              map.cpp:835 (24)
    //         004567ba     CMP        word ptr [ESP + place6],0x0
    //         004567c0     JZ         LAB_004567d2
    //         004567c2     MOV        DL,byte ptr [ESI + 0x1d]
    //         004567c5     MOV        this,AL
    //         004567c7     SHL        this,0x5
    //         004567ca     AND        DL,0x1f
    //         004567cd     OR         this,DL
    //         004567cf     MOV        byte ptr [ESI + 0x1d],this
    //                               LAB_004567d2                                                 XREF[1]:     004567c0(j)  
    //                              map.cpp:836 (36)
    //         004567d2     CMP        word ptr [ESP + offset5],0x0
    //         004567d8     JZ         LAB_004567f6
    //         004567da     MOVSX      EDX,word ptr [ESP + local_14]
    //         004567df     LEA        this,[EDX + EDX*0x2]
    //         004567e2     MOV        DL,AL
    //         004567e4     SHL        DL,0x5
    //         004567e7     LEA        EDI,[ESI + this->_padding_*0x8 + 0x5]
    //         004567eb     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         004567ef     AND        this,0x1f
    //         004567f2     OR         DL,this
    //         004567f4     MOV        byte ptr [EDI],DL
    //                               LAB_004567f6                                                 XREF[1]:     004567d8(j)  
    //                              map.cpp:837 (36)
    //         004567f6     CMP        word ptr [ESP + place8],0x0
    //         004567fc     JZ         LAB_0045681a
    //         004567fe     MOVSX      EDX,word ptr [ESP + place7]
    //         00456803     MOV        this,AL
    //         00456805     LEA        EDX,[EDX + EDX*0x2]
    //         00456808     SHL        this,0x5
    //         0045680b     LEA        EDI,[ESI + EDX*0x8 + 0x5]
    //         0045680f     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456813     AND        DL,0x1f
    //         00456816     OR         this,DL
    //         00456818     MOV        byte ptr [EDI],this
    //                               LAB_0045681a                                                 XREF[1]:     004567fc(j)  
    //                              map.cpp:838 (36)
    //         0045681a     CMP        word ptr [ESP + offset7],0x0
    //         00456820     JZ         LAB_0045683e
    //         00456822     MOVSX      EDX,word ptr [ESP + local_8]
    //         00456827     LEA        this,[EDX + EDX*0x2]
    //         0045682a     MOV        DL,AL
    //         0045682c     SHL        DL,0x5
    //         0045682f     LEA        EDI,[ESI + this->_padding_*0x8 + 0x5]
    //         00456833     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456837     AND        this,0x1f
    //         0045683a     OR         DL,this
    //         0045683c     MOV        byte ptr [EDI],DL
    //                               LAB_0045683e                                                 XREF[1]:     00456820(j)  
    //                              map.cpp:839 (22)
    //         0045683e     CMP        word ptr [ESP + place1],0x0
    //         00456844     JZ         LAB_00456863
    //         00456846     MOV        DL,byte ptr [ESI + -0x13]
    //         00456849     SHL        AL,0x5
    //         0045684c     AND        DL,0x1f
    //         0045684f     OR         AL,DL
    //         00456851     MOV        byte ptr [ESI + -0x13],AL
    //                              map.cpp:841 (2)
    //         00456854     JMP        LAB_00456863
    //                               LAB_00456856                                                 XREF[1]:     0045674b(j)  
    //                              map.cpp:842 (13)
    //         00456856     INC        AL
    //         00456858     AND        BL,0x1f
    //         0045685b     SHL        AL,0x5
    //         0045685e     XOR        AL,BL
    //         00456860     MOV        byte ptr [ESI + 0x5],AL
    //                               LAB_00456863                                                 XREF[2]:     00456844(j), 00456854(j)  
    //                              map.cpp:844 (5)
    //         00456863     MOV        byte ptr [ESP + index2+0x3],0x1
    //                               LAB_00456868                                                 XREF[1]:     0045673c(j)  
    //                              map.cpp:781 (59)
    //         00456868     MOV        EAX,dword ptr [ESP + index1]
    //         0045686c     MOV        this,dword ptr [ESP + param_3]
    //         00456870     ADD        ESI,0x18
    //         00456873     INC        EAX
    //         00456874     CMP        EAX,this
    //         00456876     MOV        dword ptr [ESP + index1],EAX
    //         0045687a     JLE        LAB_004565a0
    //         00456880     MOV        EDX,dword ptr [ESP + param_4]
    //         00456884     MOV        EAX,dword ptr [ESP + param_1]
    //         00456888     MOV        this,dword ptr [ESP + local_4]
    //         0045688c     MOV        EBP,dword ptr [ESP + local_40]
    //         00456890     XOR        EDI,EDI
    //                               LAB_00456892                                                 XREF[1]:     00456598(j)  
    //         00456892     MOV        ESI,dword ptr [ESP + place4]
    //         00456896     INC        EBP
    //         00456897     CMP        EBP,EDX
    //         00456899     MOV        dword ptr [ESP + local_40],EBP
    //         0045689d     JLE        LAB_00456583
    //                               LAB_004568a3                                                 XREF[1]:     00456579(j)  
    //                              map.cpp:849 (12)
    //         004568a3     MOV        DL,byte ptr [ESP + index2+0x3]
    //         004568a7     TEST       DL,DL
    //         004568a9     JNZ        LAB_0045652b
    //                              map.cpp:850 (10)
    //         004568af     POP        EDI
    //         004568b0     POP        ESI
    //         004568b1     POP        EBP
    //         004568b2     POP        EBX
    //         004568b3     ADD        ESP,0x48
    //         004568b6     RET        0x14
}

// Offset: 0x004568C0
void clean_elevation(RGE_Map* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::clean_elevation(long,long,long,long,unsigned char)                   *
    //                              *********************************************************************************************************
    //                              void __thiscall clean_elevation(RGE_Map * this, long param_1, long p
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[5]:     004568e3(R), 00456944(W), 00456958(W), 004569ac(R), 
    //                                                                                     00456e34(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     00456905(R), 00456948(W), 00456962(W), 00456e38(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     00456912(R), 0045694c(W), 00456970(W), 004569b0(R), 
    //                                                                                     00456e0b(R), 00456e3c(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[4]:     00456920(R), 00456950(W), 0045697e(W), 00456e23(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[3]:     00456982(R), 00456cd8(R), 00456e42(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004569a6(W), 004569b4(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     004568fd(W), 00456b08(R), 00456dc1(R)  
    //              short             Stack[-0xc]:2  offset7                   XREF[3]:     004568eb(W), 00456a3d(R), 00456d9d(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     004568f9(W), 00456b2e(R), 00456d79(R)  
    //              short             Stack[-0x14]:2 offset5                   XREF[3]:     004568e7(W), 00456ada(R), 00456d3c(R)  
    //              short             Stack[-0x18]:2 offset3                   XREF[3]:     004568d5(W), 00456a0a(R), 00456d14(R)  
    //              short             Stack[-0x1c]:2 offset2                   XREF[3]:     004568cd(W), 00456ab7(R), 00456cec(R)  
    //              short             Stack[-0x20]:2 offset1                   XREF[8]:     004568f3(W), 0045692d(R), 00456986(R), 004569b8(R), 
    //                                                                                     00456a2b(R), 00456a7e(R), 00456e46(R), 00456e69(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[8]:     00456996(W), 004569c6(R), 004569da(R), 00456a35(R), 
    //                                                                                     00456aa7(R), 00456afa(R), 00456e1f(R), 00456e2a(W)  
    //              long              Stack[-0x28]:4 index1                    XREF[8]:     004569f2(W), 00456a9f(W), 00456b67(R), 00456bae(R), 
    //                                                                                     00456bb6(R), 00456d06(R), 00456d30(R), 00456d56(R)  
    //              short             Stack[-0x2c]:2 place4                    XREF[8]:     004569ee(W), 00456af2(W), 00456b56(R), 00456bba(R), 
    //                                                                                     00456c43(R), 00456c58(R), 00456cba(R), 00456d34(R)  
    //              short             Stack[-0x30]:2 place3                    XREF[9]:     004569bc(W), 00456a5e(R), 00456a88(R), 00456aaf(R), 
    //                                                                                     00456ad4(R), 00456b00(R), 00456b28(R), 00456e07(R), 
    //                                                                                     00456e15(W)  
    //              long              Stack[-0x34]:4 index2                    XREF[9]:     00456a02(W), 00456a76(W), 00456b7d(R), 00456bf0(R), 
    //                                                                                     00456c05(R), 00456c33(R), 00456c6d(R), 00456c88(R), 
    //                                                                                     00456ddd(R)  
    //              short             Stack[-0x38]:2 place8                    XREF[9]:     004569fe(W), 00456b20(W), 00456b75(R), 00456b8d(R), 
    //                                                                                     00456bfd(R), 00456c23(R), 00456c3b(R), 00456c77(R), 
    //                                                                                     00456db9(R)  
    //              short             Stack[-0x3c]:2 place7                    XREF[9]:     004569fa(W), 00456a56(W), 00456b85(R), 00456b9d(R), 
    //                                                                                     00456bd3(R), 00456c0d(R), 00456c2b(R), 00456ca5(R), 
    //                                                                                     00456d95(R)  
    //              short             Stack[-0x40]:2 place6                    XREF[9]:     004569f6(W), 00456b47(W), 00456b95(R), 00456bc6(R), 
    //                                                                                     00456bdb(R), 00456c17(R), 00456c9d(R), 00456cb2(R), 
    //                                                                                     00456d71(R)  
    //              short             Stack[-0x44]:2 place5                    XREF[9]:     004569ea(W), 00456a23(W), 00456b5f(R), 00456be8(R), 
    //                                                                                     00456c50(R), 00456c65(R), 00456c90(R), 00456cc7(R), 
    //                                                                                     00456d0c(R)  
    //              undefined1        Stack[-0x45]:1 local_45                  XREF[4]:     0045693f(W), 00456e02(W), 00456e58(W), 00456e5d(R)  
    //              short             Stack[-0x48]:2 place2
    //              uchar             Stack[-0x49]:1 change_flag
    //                               ?clean_elevation@RGE_Map@@QAEXJJJJE@Z                        XREF[3]:     do_elevation_brush_stroke:0045773b
    //                               RGE_Map::clean_elevation                                                  generate:0048479c(c), 
    //                                                                                                         key_down_action:0048a4e1(c)  
    //                              map.cpp:854 (3)
    //         004568c0     SUB        ESP,0x48
    //                              map.cpp:865 (14)
    //         004568c3     MOV        AX,word ptr [ECX + this->map_width]
    //         004568c7     OR         EDX,0xffffffff
    //         004568ca     SUB        EDX,EAX
    //         004568cc     PUSH       EBX
    //         004568cd     MOV        dword ptr [ESP + offset2],EDX
    //                              map.cpp:866 (8)
    //         004568d1     MOV        EDX,EAX
    //         004568d3     NEG        EDX
    //         004568d5     MOV        dword ptr [ESP + offset3],EDX
    //                              map.cpp:867 (10)
    //         004568d9     MOV        EDX,0x1
    //         004568de     PUSH       EBP
    //         004568df     SUB        EDX,EAX
    //         004568e1     PUSH       ESI
    //         004568e2     PUSH       EDI
    //                              map.cpp:878 (32)
    //         004568e3     MOV        EDI,dword ptr [ESP + param_1]
    //         004568e7     MOV        dword ptr [ESP + offset5],EDX
    //         004568eb     MOV        dword ptr [ESP + offset7],EAX
    //         004568ef     LEA        EDX,[EAX + 0x1]
    //         004568f2     DEC        EAX
    //         004568f3     MOV        dword ptr [ESP + offset1],this
    //         004568f7     TEST       EDI,EDI
    //         004568f9     MOV        dword ptr [ESP + local_10],EDX
    //         004568fd     MOV        dword ptr [ESP + local_8],EAX
    //         00456901     JGE        LAB_00456905
    //                              map.cpp:879 (2)
    //         00456903     XOR        EDI,EDI
    //                               LAB_00456905                                                 XREF[1]:     00456901(j)  
    //                              map.cpp:880 (8)
    //         00456905     MOV        ESI,dword ptr [ESP + param_2]
    //         00456909     TEST       ESI,ESI
    //         0045690b     JGE        LAB_0045690f
    //                              map.cpp:881 (2)
    //         0045690d     XOR        ESI,ESI
    //                               LAB_0045690f                                                 XREF[1]:     0045690b(j)  
    //                              map.cpp:882 (11)
    //         0045690f     MOV        EAX,dword ptr [ECX + this->map_width]
    //         00456912     MOV        EBX,dword ptr [ESP + param_3]
    //         00456916     CMP        EBX,EAX
    //         00456918     JL         LAB_0045691d
    //                              map.cpp:883 (3)
    //         0045691a     LEA        EBX,[EAX + -0x1]
    //                               LAB_0045691d                                                 XREF[1]:     00456918(j)  
    //                              map.cpp:884 (11)
    //         0045691d     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00456920     MOV        EBP,dword ptr [ESP + param_4]
    //         00456924     CMP        EBP,EAX
    //         00456926     JL         LAB_00456931
    //                              map.cpp:885 (9)
    //         00456928     LEA        EBP,[EAX + -0x1]
    //         0045692b     JMP        LAB_00456931
    //                               LAB_0045692d                                                 XREF[1]:     00456e63(j)  
    //         0045692d     MOV        this,dword ptr [ESP + offset1]
    //                               LAB_00456931                                                 XREF[2]:     00456926(j), 0045692b(j)  
    //                              map.cpp:891 (3)
    //         00456931     SUB        EDI,0x2
    //                              map.cpp:892 (3)
    //         00456934     SUB        ESI,0x2
    //                              map.cpp:893 (3)
    //         00456937     ADD        EBX,0x2
    //                              map.cpp:894 (3)
    //         0045693a     ADD        EBP,0x2
    //                              map.cpp:896 (25)
    //         0045693d     TEST       EDI,EDI
    //         0045693f     MOV        byte ptr [ESP + local_45],0x0
    //         00456944     MOV        dword ptr [ESP + param_1],EDI
    //         00456948     MOV        dword ptr [ESP + param_2],ESI
    //         0045694c     MOV        dword ptr [ESP + param_3],EBX
    //         00456950     MOV        dword ptr [ESP + param_4],EBP
    //         00456954     JGE        LAB_0045695c
    //                              map.cpp:897 (6)
    //         00456956     XOR        EDI,EDI
    //         00456958     MOV        dword ptr [ESP + param_1],EDI
    //                               LAB_0045695c                                                 XREF[1]:     00456954(j)  
    //                              map.cpp:899 (4)
    //         0045695c     TEST       ESI,ESI
    //         0045695e     JGE        LAB_00456966
    //                              map.cpp:900 (6)
    //         00456960     XOR        ESI,ESI
    //         00456962     MOV        dword ptr [ESP + param_2],ESI
    //                               LAB_00456966                                                 XREF[1]:     0045695e(j)  
    //                              map.cpp:902 (7)
    //         00456966     MOV        EAX,dword ptr [ECX + this->map_width]
    //         00456969     CMP        EBX,EAX
    //         0045696b     JL         LAB_00456974
    //                              map.cpp:903 (7)
    //         0045696d     LEA        EBX,[EAX + -0x1]
    //         00456970     MOV        dword ptr [ESP + param_3],EBX
    //                               LAB_00456974                                                 XREF[1]:     0045696b(j)  
    //                              map.cpp:905 (7)
    //         00456974     MOV        EAX,dword ptr [ECX + this->map_height]
    //         00456977     CMP        EBP,EAX
    //         00456979     JL         LAB_00456982
    //                              map.cpp:906 (7)
    //         0045697b     LEA        EBP,[EAX + -0x1]
    //         0045697e     MOV        dword ptr [ESP + param_4],EBP
    //                               LAB_00456982                                                 XREF[1]:     00456979(j)  
    //                              map.cpp:908 (18)
    //         00456982     MOV        EAX,dword ptr [ESP + param_5]
    //         00456986     MOV        this,dword ptr [ESP + offset1]
    //         0045698a     PUSH       EAX
    //         0045698b     PUSH       EBP
    //         0045698c     PUSH       EBX
    //         0045698d     PUSH       ESI
    //         0045698e     PUSH       EDI
    //         0045698f     CALL       RGE_Map::preclean_elevation                      void preclean_elevation(RGE_Map * this, long 
    //                              map.cpp:911 (12)
    //         00456994     CMP        ESI,EBP
    //         00456996     MOV        dword ptr [ESP + local_24],ESI
    //         0045699a     JG         LAB_00456e42
    //                              map.cpp:913 (28)
    //         004569a0     LEA        EAX,[EDI + EDI*0x2]
    //         004569a3     SHL        EAX,0x3
    //         004569a6     MOV        dword ptr [ESP + local_4],EAX
    //         004569aa     JMP        LAB_004569b8
    //                               LAB_004569ac                                                 XREF[1]:     00456e2e(j)  
    //         004569ac     MOV        EDI,dword ptr [ESP + param_1]
    //         004569b0     MOV        EBX,dword ptr [ESP + param_3]
    //         004569b4     MOV        EAX,dword ptr [ESP + local_4]
    //                               LAB_004569b8                                                 XREF[1]:     004569aa(j)  
    //         004569b8     MOV        this,dword ptr [ESP + offset1]
    //                              map.cpp:914 (27)
    //         004569bc     MOV        dword ptr [ESP + place3],EDI
    //         004569c0     MOV        EDX,dword ptr [ECX + this->map_row_offset]
    //         004569c6     MOV        this,dword ptr [ESP + local_24]
    //         004569ca     MOV        ESI,dword ptr [EDX + this->_padding_*0x4]
    //         004569cd     ADD        ESI,EAX
    //         004569cf     CMP        EDI,EBX
    //         004569d1     JG         LAB_00456e1f
    //                               LAB_004569d7                                                 XREF[1]:     00456e19(j)  
    //                              map.cpp:924 (3)
    //         004569d7     MOV        BL,byte ptr [ESI + 0x5]
    //                              map.cpp:926 (73)
    //         004569da     MOV        this,dword ptr [ESP + local_24]
    //         004569de     MOV        DL,BL
    //         004569e0     XOR        EBP,EBP
    //         004569e2     SHR        DL,0x5
    //         004569e5     XOR        AX,AX
    //         004569e8     CMP        this,EBP
    //         004569ea     MOV        dword ptr [ESP + place5],EBP
    //         004569ee     MOV        dword ptr [ESP + place4],EBP
    //         004569f2     MOV        dword ptr [ESP + index1],EBP
    //         004569f6     MOV        dword ptr [ESP + place6],EBP
    //         004569fa     MOV        dword ptr [ESP + place7],EBP
    //         004569fe     MOV        dword ptr [ESP + place8],EBP
    //         00456a02     MOV        dword ptr [ESP + index2],EBP
    //         00456a06     MOV        AL,DL
    //         00456a08     JLE        LAB_00456a2b
    //         00456a0a     MOVSX      this,word ptr [ESP + offset3]
    //         00456a0f     LEA        this,[ECX + ECX*0x2]
    //         00456a12     MOV        DL,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456a16     XOR        this,this
    //         00456a19     SHR        DL,0x5
    //         00456a1c     MOV        this,DL
    //         00456a1e     CMP        this,AX
    //         00456a21     JLE        LAB_00456a2b
    //                              map.cpp:927 (8)
    //         00456a23     MOV        dword ptr [ESP + place5],0x1
    //                               LAB_00456a2b                                                 XREF[2]:     00456a08(j), 00456a21(j)  
    //                              map.cpp:929 (43)
    //         00456a2b     MOV        EDX,dword ptr [ESP + offset1]
    //         00456a2f     MOV        this,dword ptr [EDX + 0xc]
    //         00456a32     LEA        EDI,[this->_padding_ + -0x1]
    //         00456a35     MOV        this,dword ptr [ESP + local_24]
    //         00456a39     CMP        this,EDI
    //         00456a3b     JGE        LAB_00456a5e
    //         00456a3d     MOVSX      this,word ptr [ESP + offset7]
    //         00456a42     LEA        this,[ECX + ECX*0x2]
    //         00456a45     MOV        DL,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456a49     XOR        this,this
    //         00456a4c     SHR        DL,0x5
    //         00456a4f     MOV        this,DL
    //         00456a51     CMP        this,AX
    //         00456a54     JLE        LAB_00456a5e
    //                              map.cpp:930 (8)
    //         00456a56     MOV        dword ptr [ESP + place7],0x1
    //                               LAB_00456a5e                                                 XREF[2]:     00456a3b(j), 00456a54(j)  
    //                              map.cpp:932 (24)
    //         00456a5e     MOV        this,dword ptr [ESP + place3]
    //         00456a62     TEST       this,this
    //         00456a64     JLE        LAB_00456a7e
    //         00456a66     MOV        DL,byte ptr [ESI + -0x13]
    //         00456a69     XOR        this,this
    //         00456a6c     SHR        DL,0x5
    //         00456a6f     MOV        this,DL
    //         00456a71     CMP        this,AX
    //         00456a74     JLE        LAB_00456a7e
    //                              map.cpp:933 (8)
    //         00456a76     MOV        dword ptr [ESP + index2],0x1
    //                               LAB_00456a7e                                                 XREF[2]:     00456a64(j), 00456a74(j)  
    //                              map.cpp:935 (33)
    //         00456a7e     MOV        EDX,dword ptr [ESP + offset1]
    //         00456a82     MOV        this,dword ptr [EDX + 0x8]
    //         00456a85     LEA        EDX,[this->_padding_ + -0x1]
    //         00456a88     MOV        this,dword ptr [ESP + place3]
    //         00456a8c     CMP        this,EDX
    //         00456a8e     JGE        LAB_00456aa7
    //         00456a90     MOV        this,byte ptr [ESI + 0x1d]
    //         00456a93     SHR        this,0x5
    //         00456a96     MOVZX      this,this
    //         00456a9a     CMP        this,AX
    //         00456a9d     JLE        LAB_00456aa7
    //                              map.cpp:936 (8)
    //         00456a9f     MOV        dword ptr [ESP + index1],0x1
    //                               LAB_00456aa7                                                 XREF[2]:     00456a8e(j), 00456a9d(j)  
    //                              map.cpp:938 (8)
    //         00456aa7     MOV        this,dword ptr [ESP + local_24]
    //         00456aab     TEST       this,this
    //         00456aad     JLE        LAB_00456afa
    //                              map.cpp:940 (32)
    //         00456aaf     MOV        this,dword ptr [ESP + place3]
    //         00456ab3     TEST       this,this
    //         00456ab5     JLE        LAB_00456ad4
    //         00456ab7     MOVSX      this,word ptr [ESP + offset2]
    //         00456abc     LEA        this,[ECX + ECX*0x2]
    //         00456abf     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456ac3     SHR        this,0x5
    //         00456ac6     MOVZX      this,this
    //         00456aca     CMP        this,AX
    //         00456acd     JLE        LAB_00456ad4
    //                              map.cpp:941 (5)
    //         00456acf     MOV        EBP,0x1
    //                               LAB_00456ad4                                                 XREF[2]:     00456ab5(j), 00456acd(j)  
    //                              map.cpp:943 (30)
    //         00456ad4     CMP        dword ptr [ESP + place3],EDX
    //         00456ad8     JGE        LAB_00456afa
    //         00456ada     MOVSX      this,word ptr [ESP + offset5]
    //         00456adf     LEA        this,[ECX + ECX*0x2]
    //         00456ae2     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456ae6     SHR        this,0x5
    //         00456ae9     MOVZX      this,this
    //         00456aed     CMP        this,AX
    //         00456af0     JLE        LAB_00456afa
    //                              map.cpp:944 (8)
    //         00456af2     MOV        dword ptr [ESP + place4],0x1
    //                               LAB_00456afa                                                 XREF[3]:     00456aad(j), 00456ad8(j), 
    //                                                                                                         00456af0(j)  
    //                              map.cpp:947 (6)
    //         00456afa     CMP        dword ptr [ESP + local_24],EDI
    //         00456afe     JGE        LAB_00456b4f
    //                              map.cpp:949 (32)
    //         00456b00     MOV        this,dword ptr [ESP + place3]
    //         00456b04     TEST       this,this
    //         00456b06     JLE        LAB_00456b28
    //         00456b08     MOVSX      this,word ptr [ESP + local_8]
    //         00456b0d     LEA        this,[ECX + ECX*0x2]
    //         00456b10     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456b14     SHR        this,0x5
    //         00456b17     MOVZX      this,this
    //         00456b1b     CMP        this,AX
    //         00456b1e     JLE        LAB_00456b28
    //                              map.cpp:950 (8)
    //         00456b20     MOV        dword ptr [ESP + place8],0x1
    //                               LAB_00456b28                                                 XREF[2]:     00456b06(j), 00456b1e(j)  
    //                              map.cpp:952 (31)
    //         00456b28     CMP        dword ptr [ESP + place3],EDX
    //         00456b2c     JGE        LAB_00456b4f
    //         00456b2e     MOVSX      this,word ptr [ESP + local_10]
    //         00456b33     LEA        EDX,[ECX + ECX*0x2]
    //         00456b36     MOV        this,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456b3a     XOR        DX,DX
    //         00456b3d     SHR        this,0x5
    //         00456b40     MOV        DL,this
    //         00456b42     CMP        DX,AX
    //         00456b45     JLE        LAB_00456b4f
    //                              map.cpp:953 (8)
    //         00456b47     MOV        dword ptr [ESP + place6],0x1
    //                               LAB_00456b4f                                                 XREF[3]:     00456afe(j), 00456b2c(j), 
    //                                                                                                         00456b45(j)  
    //                              map.cpp:956 (2)
    //         00456b4f     XOR        this,this
    //                              map.cpp:958 (5)
    //         00456b51     TEST       BP,BP
    //         00456b54     JZ         LAB_00456bb6
    //                              map.cpp:964 (84)
    //         00456b56     MOV        EDI,dword ptr [ESP + place4]
    //         00456b5a     TEST       DI,DI
    //         00456b5d     JZ         LAB_00456b67
    //         00456b5f     CMP        word ptr [ESP + place5],0x0
    //         00456b65     JZ         LAB_00456bae
    //                               LAB_00456b67                                                 XREF[1]:     00456b5d(j)  
    //         00456b67     MOV        EDX,dword ptr [ESP + index1]
    //         00456b6b     TEST       DX,DX
    //         00456b6e     JZ         LAB_00456b75
    //         00456b70     TEST       DI,DI
    //         00456b73     JZ         LAB_00456bb2
    //                               LAB_00456b75                                                 XREF[1]:     00456b6e(j)  
    //         00456b75     CMP        word ptr [ESP + place8],0x0
    //         00456b7b     JZ         LAB_00456b85
    //         00456b7d     CMP        word ptr [ESP + index2],0x0
    //         00456b83     JZ         LAB_00456bb2
    //                               LAB_00456b85                                                 XREF[1]:     00456b7b(j)  
    //         00456b85     CMP        word ptr [ESP + place7],0x0
    //         00456b8b     JZ         LAB_00456b95
    //         00456b8d     CMP        word ptr [ESP + place8],0x0
    //         00456b93     JZ         LAB_00456bb2
    //                               LAB_00456b95                                                 XREF[1]:     00456b8b(j)  
    //         00456b95     CMP        word ptr [ESP + place6],0x0
    //         00456b9b     JZ         LAB_00456bba
    //         00456b9d     CMP        word ptr [ESP + place7],0x0
    //         00456ba3     JNZ        LAB_00456bba
    //         00456ba5     TEST       DX,DX
    //         00456ba8     JNZ        LAB_00456bba
    //                              map.cpp:965 (4)
    //         00456baa     MOV        this,0x1
    //         00456bac     JMP        LAB_00456bba
    //                               LAB_00456bae                                                 XREF[1]:     00456b65(j)  
    //                              map.cpp:964 (4)
    //         00456bae     MOV        EDX,dword ptr [ESP + index1]
    //                               LAB_00456bb2                                                 XREF[3]:     00456b73(j), 00456b83(j), 
    //                                                                                                         00456b93(j)  
    //                              map.cpp:965 (8)
    //         00456bb2     MOV        this,0x1
    //         00456bb4     JMP        LAB_00456bba
    //                               LAB_00456bb6                                                 XREF[1]:     00456b54(j)  
    //         00456bb6     MOV        EDX,dword ptr [ESP + index1]
    //                               LAB_00456bba                                                 XREF[5]:     00456b9b(j), 00456ba3(j), 
    //                                                                                                         00456ba8(j), 00456bac(j), 
    //                                                                                                         00456bb4(j)  
    //                              map.cpp:968 (12)
    //         00456bba     CMP        word ptr [ESP + place4],0x0
    //         00456bc0     JZ         LAB_00456c17
    //         00456bc2     TEST       this,this
    //         00456bc4     JNZ        LAB_00456c17
    //                              map.cpp:974 (79)
    //         00456bc6     CMP        word ptr [ESP + place6],0x0
    //         00456bcc     JZ         LAB_00456bd3
    //         00456bce     TEST       DX,DX
    //         00456bd1     JZ         LAB_00456c15
    //                               LAB_00456bd3                                                 XREF[1]:     00456bcc(j)  
    //         00456bd3     CMP        word ptr [ESP + place7],0x0
    //         00456bd9     JZ         LAB_00456be3
    //         00456bdb     CMP        word ptr [ESP + place6],0x0
    //         00456be1     JZ         LAB_00456c15
    //                               LAB_00456be3                                                 XREF[1]:     00456bd9(j)  
    //         00456be3     TEST       BP,BP
    //         00456be6     JZ         LAB_00456bf0
    //         00456be8     CMP        word ptr [ESP + place5],0x0
    //         00456bee     JZ         LAB_00456c15
    //                               LAB_00456bf0                                                 XREF[1]:     00456be6(j)  
    //         00456bf0     CMP        word ptr [ESP + index2],0x0
    //         00456bf6     JZ         LAB_00456bfd
    //         00456bf8     TEST       BP,BP
    //         00456bfb     JZ         LAB_00456c15
    //                               LAB_00456bfd                                                 XREF[1]:     00456bf6(j)  
    //         00456bfd     CMP        word ptr [ESP + place8],0x0
    //         00456c03     JZ         LAB_00456c17
    //         00456c05     CMP        word ptr [ESP + index2],0x0
    //         00456c0b     JNZ        LAB_00456c17
    //         00456c0d     CMP        word ptr [ESP + place7],0x0
    //         00456c13     JNZ        LAB_00456c17
    //                               LAB_00456c15                                                 XREF[4]:     00456bd1(j), 00456be1(j), 
    //                                                                                                         00456bee(j), 00456bfb(j)  
    //                              map.cpp:975 (2)
    //         00456c15     MOV        this,0x1
    //                               LAB_00456c17                                                 XREF[5]:     00456bc0(j), 00456bc4(j), 
    //                                                                                                         00456c03(j), 00456c0b(j), 
    //                                                                                                         00456c13(j)  
    //                              map.cpp:978 (12)
    //         00456c17     CMP        word ptr [ESP + place6],0x0
    //         00456c1d     JZ         LAB_00456c77
    //         00456c1f     TEST       this,this
    //         00456c21     JNZ        LAB_00456c77
    //                              map.cpp:984 (82)
    //         00456c23     CMP        word ptr [ESP + place8],0x0
    //         00456c29     JZ         LAB_00456c33
    //         00456c2b     CMP        word ptr [ESP + place7],0x0
    //         00456c31     JZ         LAB_00456c75
    //                               LAB_00456c33                                                 XREF[1]:     00456c29(j)  
    //         00456c33     CMP        word ptr [ESP + index2],0x0
    //         00456c39     JZ         LAB_00456c43
    //         00456c3b     CMP        word ptr [ESP + place8],0x0
    //         00456c41     JZ         LAB_00456c75
    //                               LAB_00456c43                                                 XREF[1]:     00456c39(j)  
    //         00456c43     CMP        word ptr [ESP + place4],0x0
    //         00456c49     JZ         LAB_00456c50
    //         00456c4b     TEST       DX,DX
    //         00456c4e     JZ         LAB_00456c75
    //                               LAB_00456c50                                                 XREF[1]:     00456c49(j)  
    //         00456c50     CMP        word ptr [ESP + place5],0x0
    //         00456c56     JZ         LAB_00456c60
    //         00456c58     CMP        word ptr [ESP + place4],0x0
    //         00456c5e     JZ         LAB_00456c75
    //                               LAB_00456c60                                                 XREF[1]:     00456c56(j)  
    //         00456c60     TEST       BP,BP
    //         00456c63     JZ         LAB_00456c77
    //         00456c65     CMP        word ptr [ESP + place5],0x0
    //         00456c6b     JNZ        LAB_00456c77
    //         00456c6d     CMP        word ptr [ESP + index2],0x0
    //         00456c73     JNZ        LAB_00456c77
    //                               LAB_00456c75                                                 XREF[4]:     00456c31(j), 00456c41(j), 
    //                                                                                                         00456c4e(j), 00456c5e(j)  
    //                              map.cpp:985 (2)
    //         00456c75     MOV        this,0x1
    //                               LAB_00456c77                                                 XREF[5]:     00456c1d(j), 00456c21(j), 
    //                                                                                                         00456c63(j), 00456c6b(j), 
    //                                                                                                         00456c73(j)  
    //                              map.cpp:988 (12)
    //         00456c77     CMP        word ptr [ESP + place8],0x0
    //         00456c7d     JZ         LAB_00456cd0
    //         00456c7f     TEST       this,this
    //         00456c81     JNZ        LAB_00456cd8
    //                              map.cpp:994 (75)
    //         00456c83     TEST       BP,BP
    //         00456c86     JZ         LAB_00456c90
    //         00456c88     CMP        word ptr [ESP + index2],0x0
    //         00456c8e     JZ         LAB_00456cce
    //                               LAB_00456c90                                                 XREF[1]:     00456c86(j)  
    //         00456c90     CMP        word ptr [ESP + place5],0x0
    //         00456c96     JZ         LAB_00456c9d
    //         00456c98     TEST       BP,BP
    //         00456c9b     JZ         LAB_00456cce
    //                               LAB_00456c9d                                                 XREF[1]:     00456c96(j)  
    //         00456c9d     CMP        word ptr [ESP + place6],0x0
    //         00456ca3     JZ         LAB_00456cad
    //         00456ca5     CMP        word ptr [ESP + place7],0x0
    //         00456cab     JZ         LAB_00456cce
    //                               LAB_00456cad                                                 XREF[1]:     00456ca3(j)  
    //         00456cad     TEST       DX,DX
    //         00456cb0     JZ         LAB_00456cba
    //         00456cb2     CMP        word ptr [ESP + place6],0x0
    //         00456cb8     JZ         LAB_00456cce
    //                               LAB_00456cba                                                 XREF[1]:     00456cb0(j)  
    //         00456cba     CMP        word ptr [ESP + place4],0x0
    //         00456cc0     JZ         LAB_00456cd0
    //         00456cc2     TEST       DX,DX
    //         00456cc5     JNZ        LAB_00456cd0
    //         00456cc7     CMP        word ptr [ESP + place5],DX
    //         00456ccc     JNZ        LAB_00456cd0
    //                               LAB_00456cce                                                 XREF[4]:     00456c8e(j), 00456c9b(j), 
    //                                                                                                         00456cab(j), 00456cb8(j)  
    //                              map.cpp:995 (2)
    //         00456cce     MOV        this,0x1
    //                               LAB_00456cd0                                                 XREF[4]:     00456c7d(j), 00456cc0(j), 
    //                                                                                                         00456cc5(j), 00456ccc(j)  
    //                              map.cpp:998 (8)
    //         00456cd0     TEST       this,this
    //         00456cd2     JZ         LAB_00456e07
    //                               LAB_00456cd8                                                 XREF[1]:     00456c81(j)  
    //                              map.cpp:1000 (15)
    //         00456cd8     MOVZX      this,byte ptr [ESP + param_5]
    //         00456cde     CMP        AX,this
    //         00456ce1     JL         LAB_00456df5
    //                              map.cpp:1002 (37)
    //         00456ce7     TEST       BP,BP
    //         00456cea     JZ         LAB_00456d0c
    //         00456cec     MOVSX      this,word ptr [ESP + offset2]
    //         00456cf1     LEA        EDX,[ECX + ECX*0x2]
    //         00456cf4     MOV        this,AL
    //         00456cf6     SHL        this,0x5
    //         00456cf9     LEA        EDI,[ESI + EDX*0x8 + 0x5]
    //         00456cfd     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456d01     AND        DL,0x1f
    //         00456d04     OR         this,DL
    //         00456d06     MOV        EDX,dword ptr [ESP + index1]
    //         00456d0a     MOV        byte ptr [EDI],this
    //                               LAB_00456d0c                                                 XREF[1]:     00456cea(j)  
    //                              map.cpp:1003 (40)
    //         00456d0c     CMP        word ptr [ESP + place5],0x0
    //         00456d12     JZ         LAB_00456d34
    //         00456d14     MOVSX      this,word ptr [ESP + offset3]
    //         00456d19     MOV        DL,AL
    //         00456d1b     LEA        this,[ECX + ECX*0x2]
    //         00456d1e     SHL        DL,0x5
    //         00456d21     LEA        EDI,[ESI + this->_padding_*0x8 + 0x5]
    //         00456d25     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456d29     AND        this,0x1f
    //         00456d2c     OR         DL,this
    //         00456d2e     MOV        byte ptr [EDI],DL
    //         00456d30     MOV        EDX,dword ptr [ESP + index1]
    //                               LAB_00456d34                                                 XREF[1]:     00456d12(j)  
    //                              map.cpp:1004 (40)
    //         00456d34     CMP        word ptr [ESP + place4],0x0
    //         00456d3a     JZ         LAB_00456d5c
    //         00456d3c     MOVSX      this,word ptr [ESP + offset5]
    //         00456d41     LEA        EDX,[ECX + ECX*0x2]
    //         00456d44     MOV        this,AL
    //         00456d46     SHL        this,0x5
    //         00456d49     LEA        EDI,[ESI + EDX*0x8 + 0x5]
    //         00456d4d     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456d51     AND        DL,0x1f
    //         00456d54     OR         this,DL
    //         00456d56     MOV        EDX,dword ptr [ESP + index1]
    //         00456d5a     MOV        byte ptr [EDI],this
    //                               LAB_00456d5c                                                 XREF[1]:     00456d3a(j)  
    //                              map.cpp:1005 (21)
    //         00456d5c     TEST       DX,DX
    //         00456d5f     JZ         LAB_00456d71
    //         00456d61     MOV        DL,byte ptr [ESI + 0x1d]
    //         00456d64     MOV        this,AL
    //         00456d66     SHL        this,0x5
    //         00456d69     AND        DL,0x1f
    //         00456d6c     OR         this,DL
    //         00456d6e     MOV        byte ptr [ESI + 0x1d],this
    //                               LAB_00456d71                                                 XREF[1]:     00456d5f(j)  
    //                              map.cpp:1006 (36)
    //         00456d71     CMP        word ptr [ESP + place6],0x0
    //         00456d77     JZ         LAB_00456d95
    //         00456d79     MOVSX      this,word ptr [ESP + local_10]
    //         00456d7e     MOV        DL,AL
    //         00456d80     LEA        this,[ECX + ECX*0x2]
    //         00456d83     SHL        DL,0x5
    //         00456d86     LEA        EDI,[ESI + this->_padding_*0x8 + 0x5]
    //         00456d8a     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456d8e     AND        this,0x1f
    //         00456d91     OR         DL,this
    //         00456d93     MOV        byte ptr [EDI],DL
    //                               LAB_00456d95                                                 XREF[1]:     00456d77(j)  
    //                              map.cpp:1007 (36)
    //         00456d95     CMP        word ptr [ESP + place7],0x0
    //         00456d9b     JZ         LAB_00456db9
    //         00456d9d     MOVSX      this,word ptr [ESP + offset7]
    //         00456da2     LEA        EDX,[ECX + ECX*0x2]
    //         00456da5     MOV        this,AL
    //         00456da7     SHL        this,0x5
    //         00456daa     LEA        EDI,[ESI + EDX*0x8 + 0x5]
    //         00456dae     MOV        DL,byte ptr [ESI + EDX*0x8 + 0x5]
    //         00456db2     AND        DL,0x1f
    //         00456db5     OR         this,DL
    //         00456db7     MOV        byte ptr [EDI],this
    //                               LAB_00456db9                                                 XREF[1]:     00456d9b(j)  
    //                              map.cpp:1008 (36)
    //         00456db9     CMP        word ptr [ESP + place8],0x0
    //         00456dbf     JZ         LAB_00456ddd
    //         00456dc1     MOVSX      this,word ptr [ESP + local_8]
    //         00456dc6     MOV        DL,AL
    //         00456dc8     LEA        this,[ECX + ECX*0x2]
    //         00456dcb     SHL        DL,0x5
    //         00456dce     LEA        EDI,[ESI + this->_padding_*0x8 + 0x5]
    //         00456dd2     MOV        this,byte ptr [ESI + this->_padding_*0x8 + 0x5]
    //         00456dd6     AND        this,0x1f
    //         00456dd9     OR         DL,this
    //         00456ddb     MOV        byte ptr [EDI],DL
    //                               LAB_00456ddd                                                 XREF[1]:     00456dbf(j)  
    //                              map.cpp:1009 (22)
    //         00456ddd     CMP        word ptr [ESP + index2],0x0
    //         00456de3     JZ         LAB_00456e02
    //         00456de5     MOV        DL,byte ptr [ESI + -0x13]
    //         00456de8     SHL        AL,0x5
    //         00456deb     AND        DL,0x1f
    //         00456dee     OR         AL,DL
    //         00456df0     MOV        byte ptr [ESI + -0x13],AL
    //                              map.cpp:1011 (2)
    //         00456df3     JMP        LAB_00456e02
    //                               LAB_00456df5                                                 XREF[1]:     00456ce1(j)  
    //                              map.cpp:1012 (13)
    //         00456df5     INC        AL
    //         00456df7     AND        BL,0x1f
    //         00456dfa     SHL        AL,0x5
    //         00456dfd     XOR        AL,BL
    //         00456dff     MOV        byte ptr [ESI + 0x5],AL
    //                               LAB_00456e02                                                 XREF[2]:     00456de3(j), 00456df3(j)  
    //                              map.cpp:1013 (5)
    //         00456e02     MOV        byte ptr [ESP + local_45],0x1
    //                               LAB_00456e07                                                 XREF[1]:     00456cd2(j)  
    //                              map.cpp:914 (24)
    //         00456e07     MOV        EAX,dword ptr [ESP + place3]
    //         00456e0b     MOV        this,dword ptr [ESP + param_3]
    //         00456e0f     ADD        ESI,0x18
    //         00456e12     INC        EAX
    //         00456e13     CMP        EAX,this
    //         00456e15     MOV        dword ptr [ESP + place3],EAX
    //         00456e19     JLE        LAB_004569d7
    //                               LAB_00456e1f                                                 XREF[1]:     004569d1(j)  
    //                              map.cpp:911 (35)
    //         00456e1f     MOV        EAX,dword ptr [ESP + local_24]
    //         00456e23     MOV        this,dword ptr [ESP + param_4]
    //         00456e27     INC        EAX
    //         00456e28     CMP        EAX,this
    //         00456e2a     MOV        dword ptr [ESP + local_24],EAX
    //         00456e2e     JLE        LAB_004569ac
    //         00456e34     MOV        EDI,dword ptr [ESP + param_1]
    //         00456e38     MOV        ESI,dword ptr [ESP + param_2]
    //         00456e3c     MOV        EBX,dword ptr [ESP + param_3]
    //         00456e40     MOV        EBP,this
    //                               LAB_00456e42                                                 XREF[1]:     0045699a(j)  
    //                              map.cpp:1018 (22)
    //         00456e42     MOV        EAX,dword ptr [ESP + param_5]
    //         00456e46     MOV        this,dword ptr [ESP + offset1]
    //         00456e4a     PUSH       EAX
    //         00456e4b     PUSH       EBP
    //         00456e4c     PUSH       EBX
    //         00456e4d     PUSH       ESI
    //         00456e4e     PUSH       EDI
    //         00456e4f     CALL       RGE_Map::postclean_elevation                     uchar postclean_elevation(RGE_Map * this, lon
    //         00456e54     TEST       AL,AL
    //         00456e56     JZ         LAB_00456e5d
    //                              map.cpp:1019 (5)
    //         00456e58     MOV        byte ptr [ESP + local_45],0x1
    //                               LAB_00456e5d                                                 XREF[1]:     00456e56(j)  
    //                              map.cpp:1021 (12)
    //         00456e5d     MOV        AL,byte ptr [ESP + local_45]
    //         00456e61     TEST       AL,AL
    //         00456e63     JNZ        LAB_0045692d
    //                              map.cpp:1022 (19)
    //         00456e69     MOV        this,dword ptr [ESP + offset1]
    //         00456e6d     PUSH       0x0
    //         00456e6f     PUSH       0x0
    //         00456e71     PUSH       0x0
    //         00456e73     PUSH       EBP
    //         00456e74     PUSH       EBX
    //         00456e75     PUSH       ESI
    //         00456e76     PUSH       EDI
    //         00456e77     CALL       RGE_Map::set_elev                                void set_elev(RGE_Map * this, short param_1, 
    //                              map.cpp:1024 (10)
    //         00456e7c     POP        EDI
    //         00456e7d     POP        ESI
    //         00456e7e     POP        EBP
    //         00456e7f     POP        EBX
    //         00456e80     ADD        ESP,0x48
    //         00456e83     RET        0x14
}

// Offset: 0x00456E90
void clean_terrain(RGE_Map* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::clean_terrain(long,long,long,long,unsigned char)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall clean_terrain(RGE_Map * this, long param_1, long par
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     00456e97(R), 00456ed7(W), 00456f1b(W), 004572aa(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     00456edb(R), 00456ee3(W), 00456f1f(R), 00456f28(W), 
    //                                                                                     004572cb(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     00456eee(R), 00456ef7(W), 00456f2f(R), 00456f3b(W), 
    //                                                                                     00456f79(R), 00457296(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[4]:     00456efe(R), 00456f09(W), 00456f48(W), 004572ae(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[4]:     00456f0d(R), 00456f13(W), 0045728d(W), 004572e1(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00456f66(W), 004572ba(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00456ec9(W), 004570b6(R)  
    //              short             Stack[-0xc]:2  offset5                   XREF[2]:     00456ecf(W), 00457099(R)  
    //              short             Stack[-0x10]:2 offset7                   XREF[2]:     00456ec1(W), 00457071(R)  
    //              short             Stack[-0x14]:2 offset3                   XREF[2]:     00456eaa(W), 00457051(R)  
    //              short             Stack[-0x18]:2 offset1                   XREF[2]:     00456ea6(W), 00456fe2(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     00456eb2(W), 00456fb5(R)  
    //              short             Stack[-0x20]:2 offset2                   XREF[5]:     00456f4c(W), 00457036(R), 004570d0(R), 004572cf(R), 
    //                                                                                     004572d7(W)  
    //              long              Stack[-0x24]:4 pass_index                XREF[5]:     00456ebd(W), 00456fd0(R), 00457013(R), 0045727c(R), 
    //                                                                                     004572b2(R)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[7]:     00456fa3(W), 00457083(W), 00457110(R), 0045716b(R), 
    //                                                                                     004571c9(R), 004571e1(R), 00457256(R)  
    //              short             Stack[-0x2c]:2 place3                    XREF[7]:     00456faf(W), 00456ff4(W), 004570e2(R), 00457138(R), 
    //                                                                                     004571a1(R), 004571ee(R), 00457240(R)  
    //              short             Stack[-0x30]:2 place6                    XREF[7]:     00456f9b(W), 00457063(W), 00457108(R), 00457177(R), 
    //                                                                                     0045718c(R), 00457200(R), 0045721f(R)  
    //              short             Stack[-0x34]:2 place1                    XREF[5]:     00456fab(W), 004570c8(W), 00457146(R), 0045715f(R), 
    //                                                                                     00457167(R)  
    //              short             Stack[-0x38]:2 place5                    XREF[8]:     00456f56(W), 00456f91(R), 00456fda(R), 00457041(R), 
    //                                                                                     0045708b(R), 0045726e(R), 004572b6(R), 004572c1(W)  
    //              long              Stack[-0x3c]:4 index1                    XREF[8]:     00456fa7(W), 0045702e(W), 004570ee(R), 00457121(R), 
    //                                                                                     00457154(R), 00457199(R), 004571d1(R), 00457248(R)  
    //              short             Stack[-0x40]:2 place4                    XREF[8]:     00456f9f(W), 00456fc8(W), 004570da(R), 00457119(R), 
    //                                                                                     0045717f(R), 004571d9(R), 0045720d(R), 0045722d(R)  
    //              short             Stack[-0x44]:2 place2                    XREF[10]:    00456f70(W), 00456ffc(R), 0045701d(R), 00457049(R), 
    //                                                                                     0045706b(R), 00457091(R), 004570b0(R), 00457272(R), 
    //                                                                                     00457292(R), 004572a0(W)  
    //              long              Stack[-0x48]:4 index2
    //                               ?clean_terrain@RGE_Map@@QAEXJJJJE@Z                          XREF[1]:     generate:004852ba(c)  
    //                               RGE_Map::clean_terrain
    //                              map.cpp:1028 (7)
    //         00456e90     SUB        ESP,0x44
    //         00456e93     PUSH       EBX
    //         00456e94     PUSH       EBP
    //         00456e95     MOV        EBP,this
    //                              map.cpp:1053 (62)
    //         00456e97     MOV        EDX,dword ptr [ESP + param_1]
    //         00456e9b     OR         this,0xffffffff
    //         00456e9e     PUSH       ESI
    //         00456e9f     MOV        AX,word ptr [EBP + 0x8]
    //         00456ea3     PUSH       EDI
    //         00456ea4     SUB        this,EAX
    //         00456ea6     MOV        dword ptr [ESP + offset1],EAX
    //         00456eaa     MOV        dword ptr [ESP + offset3],this
    //         00456eae     MOV        this,EAX
    //         00456eb0     NEG        this
    //         00456eb2     MOV        dword ptr [ESP + local_1c],this
    //         00456eb6     MOV        this,0x1
    //         00456ebb     SUB        this,EAX
    //         00456ebd     MOV        dword ptr [ESP + pass_index],EBP
    //         00456ec1     MOV        dword ptr [ESP + offset7],this
    //         00456ec5     LEA        this,[EAX + 0x1]
    //         00456ec8     DEC        EAX
    //         00456ec9     MOV        dword ptr [ESP + local_8],this
    //         00456ecd     TEST       EDX,EDX
    //         00456ecf     MOV        dword ptr [ESP + offset5],EAX
    //         00456ed3     JGE        LAB_00456edb
    //                              map.cpp:1054 (6)
    //         00456ed5     XOR        EDX,EDX
    //         00456ed7     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00456edb                                                 XREF[1]:     00456ed3(j)  
    //                              map.cpp:1055 (8)
    //         00456edb     MOV        EAX,dword ptr [ESP + param_2]
    //         00456edf     TEST       EAX,EAX
    //         00456ee1     JGE        LAB_00456eeb
    //                              map.cpp:1056 (8)
    //         00456ee3     MOV        dword ptr [ESP + param_2],0x0
    //                               LAB_00456eeb                                                 XREF[1]:     00456ee1(j)  
    //                              map.cpp:1057 (11)
    //         00456eeb     MOV        EAX,dword ptr [EBP + 0x8]
    //         00456eee     MOV        this,dword ptr [ESP + param_3]
    //         00456ef2     CMP        this,EAX
    //         00456ef4     JL         LAB_00456efb
    //                              map.cpp:1058 (5)
    //         00456ef6     DEC        EAX
    //         00456ef7     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_00456efb                                                 XREF[1]:     00456ef4(j)  
    //                              map.cpp:1059 (11)
    //         00456efb     MOV        EAX,dword ptr [EBP + 0xc]
    //         00456efe     MOV        this,dword ptr [ESP + param_4]
    //         00456f02     CMP        this,EAX
    //         00456f04     JL         LAB_00456f0d
    //                              map.cpp:1060 (11)
    //         00456f06     LEA        this,[EAX + -0x1]
    //         00456f09     MOV        dword ptr [ESP + param_4],this
    //                               LAB_00456f0d                                                 XREF[1]:     00456f04(j)  
    //         00456f0d     MOV        EBX,dword ptr [ESP + param_5]
    //                               LAB_00456f11                                                 XREF[1]:     004572e7(j)  
    //                              map.cpp:1066 (9)
    //         00456f11     TEST       EDX,EDX
    //         00456f13     MOV        byte ptr [ESP + param_5],0x0
    //         00456f18     JLE        LAB_00456f1f
    //                              map.cpp:1067 (5)
    //         00456f1a     DEC        EDX
    //         00456f1b     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_00456f1f                                                 XREF[1]:     00456f18(j)  
    //                              map.cpp:1068 (8)
    //         00456f1f     MOV        EAX,dword ptr [ESP + param_2]
    //         00456f23     TEST       EAX,EAX
    //         00456f25     JLE        LAB_00456f2c
    //                              map.cpp:1069 (5)
    //         00456f27     DEC        EAX
    //         00456f28     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_00456f2c                                                 XREF[1]:     00456f25(j)  
    //                              map.cpp:1070 (12)
    //         00456f2c     MOV        ESI,dword ptr [EBP + 0x8]
    //         00456f2f     MOV        EDI,dword ptr [ESP + param_3]
    //         00456f33     DEC        ESI
    //         00456f34     CMP        EDI,ESI
    //         00456f36     JGE        LAB_00456f3f
    //                              map.cpp:1071 (7)
    //         00456f38     MOV        ESI,EDI
    //         00456f3a     INC        ESI
    //         00456f3b     MOV        dword ptr [ESP + param_3],ESI
    //                               LAB_00456f3f                                                 XREF[1]:     00456f36(j)  
    //                              map.cpp:1072 (8)
    //         00456f3f     MOV        ESI,dword ptr [EBP + 0xc]
    //         00456f42     DEC        ESI
    //         00456f43     CMP        this,ESI
    //         00456f45     JGE        LAB_00456f4c
    //                              map.cpp:1073 (5)
    //         00456f47     INC        this
    //         00456f48     MOV        dword ptr [ESP + param_4],this
    //                               LAB_00456f4c                                                 XREF[1]:     00456f45(j)  
    //                              map.cpp:1076 (8)
    //         00456f4c     MOV        dword ptr [ESP + offset2],0x0
    //                               LAB_00456f54                                                 XREF[1]:     004572db(j)  
    //                              map.cpp:1077 (12)
    //         00456f54     CMP        EAX,this
    //         00456f56     MOV        dword ptr [ESP + place5],EAX
    //         00456f5a     JG         LAB_004572cf
    //                              map.cpp:1079 (16)
    //         00456f60     LEA        ESI,[EDX + EDX*0x2]
    //         00456f63     SHL        ESI,0x3
    //         00456f66     MOV        dword ptr [ESP + local_4],ESI
    //                               LAB_00456f6a                                                 XREF[1]:     004572c5(j)  
    //         00456f6a     MOV        EDI,dword ptr [EBP + 0x8d8c]
    //                              map.cpp:1080 (19)
    //         00456f70     MOV        dword ptr [ESP + place2],EDX
    //         00456f74     MOV        EDI,dword ptr [EDI + EAX*0x4]
    //         00456f77     ADD        EDI,ESI
    //         00456f79     CMP        EDX,dword ptr [ESP + param_3]
    //         00456f7d     JG         LAB_004572be
    //                               LAB_00456f83                                                 XREF[1]:     004572a4(j)  
    //                              map.cpp:1084 (14)
    //         00456f83     MOV        DL,byte ptr [EDI + 0x5]
    //         00456f86     AND        DL,0x1f
    //         00456f89     CMP        DL,BL
    //         00456f8b     JZ         LAB_00457292
    //                              map.cpp:1096 (55)
    //         00456f91     MOV        EAX,dword ptr [ESP + place5]
    //         00456f95     XOR        EDX,EDX
    //         00456f97     XOR        EBP,EBP
    //         00456f99     CMP        EAX,EDX
    //         00456f9b     MOV        dword ptr [ESP + place6],EDX
    //         00456f9f     MOV        dword ptr [ESP + place4],EDX
    //         00456fa3     MOV        dword ptr [ESP + local_28],EDX
    //         00456fa7     MOV        dword ptr [ESP + index1],EDX
    //         00456fab     MOV        dword ptr [ESP + place1],EDX
    //         00456faf     MOV        dword ptr [ESP + place3],EDX
    //         00456fb3     JLE        LAB_00456fd0
    //         00456fb5     MOVSX      EAX,word ptr [ESP + local_1c]
    //         00456fba     LEA        EAX,[EAX + EAX*0x2]
    //         00456fbd     MOV        this,byte ptr [EDI + EAX*0x8 + 0x5]
    //         00456fc1     AND        this,0x1f
    //         00456fc4     CMP        this,BL
    //         00456fc6     JNZ        LAB_00456fd0
    //                              map.cpp:1097 (8)
    //         00456fc8     MOV        dword ptr [ESP + place4],0x1
    //                               LAB_00456fd0                                                 XREF[2]:     00456fb3(j), 00456fc6(j)  
    //                              map.cpp:1099 (36)
    //         00456fd0     MOV        EAX,dword ptr [ESP + pass_index]
    //         00456fd4     MOV        EAX,dword ptr [EAX + 0xc]
    //         00456fd7     LEA        ESI,[EAX + -0x1]
    //         00456fda     MOV        EAX,dword ptr [ESP + place5]
    //         00456fde     CMP        EAX,ESI
    //         00456fe0     JGE        LAB_00456ffc
    //         00456fe2     MOVSX      EAX,word ptr [ESP + offset1]
    //         00456fe7     LEA        this,[EAX + EAX*0x2]
    //         00456fea     MOV        AL,byte ptr [EDI + this->_padding_*0x8 + 0x5]
    //         00456fee     AND        AL,0x1f
    //         00456ff0     CMP        AL,BL
    //         00456ff2     JNZ        LAB_00456ffc
    //                              map.cpp:1100 (8)
    //         00456ff4     MOV        dword ptr [ESP + place3],0x1
    //                               LAB_00456ffc                                                 XREF[2]:     00456fe0(j), 00456ff2(j)  
    //                              map.cpp:1102 (18)
    //         00456ffc     MOV        EAX,dword ptr [ESP + place2]
    //         00457000     TEST       EAX,EAX
    //         00457002     JLE        LAB_00457013
    //         00457004     MOV        this,byte ptr [EDI + -0x13]
    //         00457007     AND        this,0x1f
    //         0045700a     CMP        this,BL
    //         0045700c     JNZ        LAB_00457013
    //                              map.cpp:1103 (5)
    //         0045700e     MOV        EDX,0x1
    //                               LAB_00457013                                                 XREF[2]:     00457002(j), 0045700c(j)  
    //                              map.cpp:1105 (27)
    //         00457013     MOV        EAX,dword ptr [ESP + pass_index]
    //         00457017     MOV        EAX,dword ptr [EAX + 0x8]
    //         0045701a     LEA        this,[EAX + -0x1]
    //         0045701d     MOV        EAX,dword ptr [ESP + place2]
    //         00457021     CMP        EAX,this
    //         00457023     JGE        LAB_00457036
    //         00457025     MOV        AL,byte ptr [EDI + 0x1d]
    //         00457028     AND        AL,0x1f
    //         0045702a     CMP        AL,BL
    //         0045702c     JNZ        LAB_00457036
    //                              map.cpp:1106 (8)
    //         0045702e     MOV        dword ptr [ESP + index1],0x1
    //                               LAB_00457036                                                 XREF[2]:     00457023(j), 0045702c(j)  
    //                              map.cpp:1108 (11)
    //         00457036     CMP        dword ptr [ESP + offset2],0x1
    //         0045703b     JNZ        LAB_004570d0
    //                              map.cpp:1110 (8)
    //         00457041     MOV        EAX,dword ptr [ESP + place5]
    //         00457045     TEST       EAX,EAX
    //         00457047     JLE        LAB_0045708b
    //                              map.cpp:1112 (26)
    //         00457049     MOV        EAX,dword ptr [ESP + place2]
    //         0045704d     TEST       EAX,EAX
    //         0045704f     JLE        LAB_0045706b
    //         00457051     MOVSX      EAX,word ptr [ESP + offset3]
    //         00457056     LEA        EAX,[EAX + EAX*0x2]
    //         00457059     MOV        AL,byte ptr [EDI + EAX*0x8 + 0x5]
    //         0045705d     AND        AL,0x1f
    //         0045705f     CMP        AL,BL
    //         00457061     JNZ        LAB_0045706b
    //                              map.cpp:1113 (8)
    //         00457063     MOV        dword ptr [ESP + place6],0x1
    //                               LAB_0045706b                                                 XREF[2]:     0045704f(j), 00457061(j)  
    //                              map.cpp:1115 (24)
    //         0045706b     CMP        dword ptr [ESP + place2],this
    //         0045706f     JGE        LAB_0045708b
    //         00457071     MOVSX      EAX,word ptr [ESP + offset7]
    //         00457076     LEA        EAX,[EAX + EAX*0x2]
    //         00457079     MOV        AL,byte ptr [EDI + EAX*0x8 + 0x5]
    //         0045707d     AND        AL,0x1f
    //         0045707f     CMP        AL,BL
    //         00457081     JNZ        LAB_0045708b
    //                              map.cpp:1116 (8)
    //         00457083     MOV        dword ptr [ESP + local_28],0x1
    //                               LAB_0045708b                                                 XREF[3]:     00457047(j), 0045706f(j), 
    //                                                                                                         00457081(j)  
    //                              map.cpp:1119 (6)
    //         0045708b     CMP        dword ptr [ESP + place5],ESI
    //         0045708f     JGE        LAB_004570d0
    //                              map.cpp:1121 (26)
    //         00457091     MOV        EAX,dword ptr [ESP + place2]
    //         00457095     TEST       EAX,EAX
    //         00457097     JLE        LAB_004570b0
    //         00457099     MOVSX      EAX,word ptr [ESP + offset5]
    //         0045709e     LEA        EAX,[EAX + EAX*0x2]
    //         004570a1     MOV        AL,byte ptr [EDI + EAX*0x8 + 0x5]
    //         004570a5     AND        AL,0x1f
    //         004570a7     CMP        AL,BL
    //         004570a9     JNZ        LAB_004570b0
    //                              map.cpp:1122 (5)
    //         004570ab     MOV        EBP,0x1
    //                               LAB_004570b0                                                 XREF[2]:     00457097(j), 004570a9(j)  
    //                              map.cpp:1124 (24)
    //         004570b0     CMP        dword ptr [ESP + place2],this
    //         004570b4     JGE        LAB_004570d0
    //         004570b6     MOVSX      EAX,word ptr [ESP + local_8]
    //         004570bb     LEA        this,[EAX + EAX*0x2]
    //         004570be     MOV        AL,byte ptr [EDI + this->_padding_*0x8 + 0x5]
    //         004570c2     AND        AL,0x1f
    //         004570c4     CMP        AL,BL
    //         004570c6     JNZ        LAB_004570d0
    //                              map.cpp:1125 (8)
    //         004570c8     MOV        dword ptr [ESP + place1],0x1
    //                               LAB_004570d0                                                 XREF[4]:     0045703b(j), 0045708f(j), 
    //                                                                                                         004570b4(j), 004570c6(j)  
    //                              map.cpp:1131 (10)
    //         004570d0     MOV        this,dword ptr [ESP + offset2]
    //         004570d4     XOR        AL,AL
    //         004570d6     TEST       this,this
    //         004570d8     JNZ        LAB_00457108
    //                              map.cpp:1133 (41)
    //         004570da     CMP        word ptr [ESP + place4],0x0
    //         004570e0     JZ         LAB_004570ee
    //         004570e2     CMP        word ptr [ESP + place3],0x0
    //         004570e8     JNZ        LAB_00457268
    //                               LAB_004570ee                                                 XREF[1]:     004570e0(j)  
    //         004570ee     CMP        word ptr [ESP + index1],0x0
    //         004570f4     JZ         LAB_0045726a
    //         004570fa     TEST       DX,DX
    //         004570fd     JZ         LAB_0045726a
    //                              map.cpp:1136 (5)
    //         00457103     JMP        LAB_00457268
    //                               LAB_00457108                                                 XREF[1]:     004570d8(j)  
    //                              map.cpp:1138 (8)
    //         00457108     CMP        word ptr [ESP + place6],0x0
    //         0045710e     JZ         LAB_00457167
    //                              map.cpp:1144 (75)
    //         00457110     MOV        this,dword ptr [ESP + local_28]
    //         00457114     TEST       this,this
    //         00457117     JZ         LAB_00457121
    //         00457119     CMP        word ptr [ESP + place4],0x0
    //         0045711f     JZ         LAB_0045715f
    //                               LAB_00457121                                                 XREF[1]:     00457117(j)  
    //         00457121     CMP        word ptr [ESP + index1],0x0
    //         00457127     JZ         LAB_0045712e
    //         00457129     TEST       this,this
    //         0045712c     JZ         LAB_0045715f
    //                               LAB_0045712e                                                 XREF[1]:     00457127(j)  
    //         0045712e     TEST       BP,BP
    //         00457131     JZ         LAB_00457138
    //         00457133     TEST       DX,DX
    //         00457136     JZ         LAB_0045715f
    //                               LAB_00457138                                                 XREF[1]:     00457131(j)  
    //         00457138     MOV        ESI,dword ptr [ESP + place3]
    //         0045713c     TEST       SI,SI
    //         0045713f     JZ         LAB_00457146
    //         00457141     TEST       BP,BP
    //         00457144     JZ         LAB_0045715f
    //                               LAB_00457146                                                 XREF[1]:     0045713f(j)  
    //         00457146     MOV        this,dword ptr [ESP + place1]
    //         0045714a     TEST       this,this
    //         0045714d     JZ         LAB_0045716b
    //         0045714f     TEST       SI,SI
    //         00457152     JNZ        LAB_0045716b
    //         00457154     CMP        word ptr [ESP + index1],SI
    //         00457159     JNZ        LAB_0045716b
    //                              map.cpp:1145 (4)
    //         0045715b     MOV        AL,0x1
    //         0045715d     JMP        LAB_0045716b
    //                               LAB_0045715f                                                 XREF[4]:     0045711f(j), 0045712c(j), 
    //                                                                                                         00457136(j), 00457144(j)  
    //                              map.cpp:1144 (4)
    //         0045715f     MOV        this,dword ptr [ESP + place1]
    //                              map.cpp:1145 (8)
    //         00457163     MOV        AL,0x1
    //         00457165     JMP        LAB_0045716b
    //                               LAB_00457167                                                 XREF[1]:     0045710e(j)  
    //         00457167     MOV        this,dword ptr [ESP + place1]
    //                               LAB_0045716b                                                 XREF[5]:     0045714d(j), 00457152(j), 
    //                                                                                                         00457159(j), 0045715d(j), 
    //                                                                                                         00457165(j)  
    //                              map.cpp:1148 (12)
    //         0045716b     CMP        word ptr [ESP + local_28],0x0
    //         00457171     JZ         LAB_004571c0
    //         00457173     TEST       AL,AL
    //         00457175     JNZ        LAB_004571c0
    //                              map.cpp:1154 (71)
    //         00457177     CMP        word ptr [ESP + place6],0x0
    //         0045717d     JZ         LAB_00457187
    //         0045717f     CMP        word ptr [ESP + place4],0x0
    //         00457185     JZ         LAB_004571be
    //                               LAB_00457187                                                 XREF[1]:     0045717d(j)  
    //         00457187     TEST       DX,DX
    //         0045718a     JZ         LAB_00457194
    //         0045718c     CMP        word ptr [ESP + place6],0x0
    //         00457192     JZ         LAB_004571be
    //                               LAB_00457194                                                 XREF[1]:     0045718a(j)  
    //         00457194     TEST       this,this
    //         00457197     JZ         LAB_004571a1
    //         00457199     CMP        word ptr [ESP + index1],0x0
    //         0045719f     JZ         LAB_004571be
    //                               LAB_004571a1                                                 XREF[1]:     00457197(j)  
    //         004571a1     MOV        ESI,dword ptr [ESP + place3]
    //         004571a5     TEST       SI,SI
    //         004571a8     JZ         LAB_004571af
    //         004571aa     TEST       this,this
    //         004571ad     JZ         LAB_004571be
    //                               LAB_004571af                                                 XREF[1]:     004571a8(j)  
    //         004571af     TEST       BP,BP
    //         004571b2     JZ         LAB_004571c0
    //         004571b4     TEST       DX,DX
    //         004571b7     JNZ        LAB_004571c0
    //         004571b9     TEST       SI,SI
    //         004571bc     JNZ        LAB_004571c0
    //                               LAB_004571be                                                 XREF[4]:     00457185(j), 00457192(j), 
    //                                                                                                         0045719f(j), 004571ad(j)  
    //                              map.cpp:1155 (2)
    //         004571be     MOV        AL,0x1
    //                               LAB_004571c0                                                 XREF[5]:     00457171(j), 00457175(j), 
    //                                                                                                         004571b2(j), 004571b7(j), 
    //                                                                                                         004571bc(j)  
    //                              map.cpp:1158 (9)
    //         004571c0     TEST       this,this
    //         004571c3     JZ         LAB_00457216
    //         004571c5     TEST       AL,AL
    //         004571c7     JNZ        LAB_00457216
    //                              map.cpp:1164 (75)
    //         004571c9     CMP        word ptr [ESP + local_28],0x0
    //         004571cf     JZ         LAB_004571d9
    //         004571d1     CMP        word ptr [ESP + index1],0x0
    //         004571d7     JZ         LAB_00457214
    //                               LAB_004571d9                                                 XREF[1]:     004571cf(j)  
    //         004571d9     CMP        word ptr [ESP + place4],0x0
    //         004571df     JZ         LAB_004571e9
    //         004571e1     CMP        word ptr [ESP + local_28],0x0
    //         004571e7     JZ         LAB_00457214
    //                               LAB_004571e9                                                 XREF[1]:     004571df(j)  
    //         004571e9     TEST       BP,BP
    //         004571ec     JZ         LAB_004571f6
    //         004571ee     CMP        word ptr [ESP + place3],0x0
    //         004571f4     JZ         LAB_00457214
    //                               LAB_004571f6                                                 XREF[1]:     004571ec(j)  
    //         004571f6     TEST       DX,DX
    //         004571f9     JZ         LAB_00457200
    //         004571fb     TEST       BP,BP
    //         004571fe     JZ         LAB_00457214
    //                               LAB_00457200                                                 XREF[1]:     004571f9(j)  
    //         00457200     CMP        word ptr [ESP + place6],0x0
    //         00457206     JZ         LAB_00457216
    //         00457208     TEST       DX,DX
    //         0045720b     JNZ        LAB_00457216
    //         0045720d     CMP        word ptr [ESP + place4],DX
    //         00457212     JNZ        LAB_00457216
    //                               LAB_00457214                                                 XREF[4]:     004571d7(j), 004571e7(j), 
    //                                                                                                         004571f4(j), 004571fe(j)  
    //                              map.cpp:1165 (2)
    //         00457214     MOV        AL,0x1
    //                               LAB_00457216                                                 XREF[5]:     004571c3(j), 004571c7(j), 
    //                                                                                                         00457206(j), 0045720b(j), 
    //                                                                                                         00457212(j)  
    //                              map.cpp:1168 (9)
    //         00457216     TEST       BP,BP
    //         00457219     JZ         LAB_0045726a
    //         0045721b     TEST       AL,AL
    //         0045721d     JNZ        LAB_0045726e
    //                              map.cpp:1174 (73)
    //         0045721f     MOV        ESI,dword ptr [ESP + place6]
    //         00457223     TEST       SI,SI
    //         00457226     JZ         LAB_0045722d
    //         00457228     TEST       DX,DX
    //         0045722b     JZ         LAB_00457268
    //                               LAB_0045722d                                                 XREF[1]:     00457226(j)  
    //         0045722d     MOV        EBP,dword ptr [ESP + place4]
    //         00457231     TEST       BP,BP
    //         00457234     JZ         LAB_0045723b
    //         00457236     TEST       SI,SI
    //         00457239     JZ         LAB_00457268
    //                               LAB_0045723b                                                 XREF[1]:     00457234(j)  
    //         0045723b     TEST       this,this
    //         0045723e     JZ         LAB_00457248
    //         00457240     CMP        word ptr [ESP + place3],0x0
    //         00457246     JZ         LAB_00457268
    //                               LAB_00457248                                                 XREF[1]:     0045723e(j)  
    //         00457248     MOV        EDX,dword ptr [ESP + index1]
    //         0045724c     TEST       DX,DX
    //         0045724f     JZ         LAB_00457256
    //         00457251     TEST       this,this
    //         00457254     JZ         LAB_00457268
    //                               LAB_00457256                                                 XREF[1]:     0045724f(j)  
    //         00457256     CMP        word ptr [ESP + local_28],0x0
    //         0045725c     JZ         LAB_0045726a
    //         0045725e     TEST       DX,DX
    //         00457261     JNZ        LAB_0045726a
    //         00457263     TEST       BP,BP
    //         00457266     JNZ        LAB_0045726a
    //                               LAB_00457268                                                 XREF[6]:     004570e8(j), 00457103(j), 
    //                                                                                                         0045722b(j), 00457239(j), 
    //                                                                                                         00457246(j), 00457254(j)  
    //                              map.cpp:1175 (2)
    //         00457268     MOV        AL,0x1
    //                               LAB_0045726a                                                 XREF[6]:     004570f4(j), 004570fd(j), 
    //                                                                                                         00457219(j), 0045725c(j), 
    //                                                                                                         00457261(j), 00457266(j)  
    //                              map.cpp:1179 (4)
    //         0045726a     TEST       AL,AL
    //         0045726c     JZ         LAB_00457292
    //                               LAB_0045726e                                                 XREF[1]:     0045721d(j)  
    //                              map.cpp:1182 (31)
    //         0045726e     MOV        this,dword ptr [ESP + place5]
    //         00457272     MOV        EDX,dword ptr [ESP + place2]
    //         00457276     PUSH       0x0
    //         00457278     PUSH       0x0
    //         0045727a     PUSH       EBX
    //         0045727b     PUSH       this
    //         0045727c     MOV        this,dword ptr [ESP + pass_index]
    //         00457280     PUSH       EDX
    //         00457281     MOV        EAX,dword ptr [ECX + this->game_world]
    //         00457287     PUSH       EAX
    //         00457288     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Game_Wor
    //                              map.cpp:1183 (62)
    //         0045728d     MOV        byte ptr [ESP + param_5],0x1
    //                               LAB_00457292                                                 XREF[2]:     00456f8b(j), 0045726c(j)  
    //         00457292     MOV        EAX,dword ptr [ESP + place2]
    //         00457296     MOV        this,dword ptr [ESP + param_3]
    //         0045729a     ADD        EDI,0x18
    //         0045729d     INC        EAX
    //         0045729e     CMP        EAX,this
    //         004572a0     MOV        dword ptr [ESP + place2],EAX
    //         004572a4     JLE        LAB_00456f83
    //         004572aa     MOV        EDX,dword ptr [ESP + param_1]
    //         004572ae     MOV        this,dword ptr [ESP + param_4]
    //         004572b2     MOV        EBP,dword ptr [ESP + pass_index]
    //         004572b6     MOV        EAX,dword ptr [ESP + place5]
    //         004572ba     MOV        ESI,dword ptr [ESP + local_4]
    //                               LAB_004572be                                                 XREF[1]:     00456f7d(j)  
    //         004572be     INC        EAX
    //         004572bf     CMP        EAX,this
    //         004572c1     MOV        dword ptr [ESP + place5],EAX
    //         004572c5     JLE        LAB_00456f6a
    //                              map.cpp:1077 (4)
    //         004572cb     MOV        EAX,dword ptr [ESP + param_2]
    //                               LAB_004572cf                                                 XREF[1]:     00456f5a(j)  
    //                              map.cpp:1076 (18)
    //         004572cf     MOV        ESI,dword ptr [ESP + offset2]
    //         004572d3     INC        ESI
    //         004572d4     CMP        ESI,0x2
    //         004572d7     MOV        dword ptr [ESP + offset2],ESI
    //         004572db     JL         LAB_00456f54
    //                              map.cpp:1189 (12)
    //         004572e1     MOV        AL,byte ptr [ESP + param_5]
    //         004572e5     TEST       AL,AL
    //         004572e7     JNZ        LAB_00456f11
    //                              map.cpp:1190 (10)
    //         004572ed     POP        EDI
    //         004572ee     POP        ESI
    //         004572ef     POP        EBP
    //         004572f0     POP        EBX
    //         004572f1     ADD        ESP,0x44
    //         004572f4     RET        0x14
}

// Offset: 0x00457300
void clean_borders(RGE_Map* this_, long param_2, long param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::clean_borders(long,long,long,long)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall clean_borders(RGE_Map * this, long param_1, long par
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              long              Stack[0x10]:4  param_4
    //                               ?clean_borders@RGE_Map@@QAEXJJJJ@Z
    //                               RGE_Map::clean_borders
    //                              map.cpp:1194 (3)
    //         00457300     RET        0x10
}

// Offset: 0x00457310
long clean_border_tile(RGE_Map* this_, long param_2, long param_3, long* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Map::clean_border_tile(long,long,long (* const)[32])                      *
    //                              *********************************************************************************************************
    //                              long __thiscall clean_border_tile(RGE_Map * this, long param_1, long
    //              long              EAX:4          <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              long *            Stack[0xc]:4   param_3
    //                               ?clean_border_tile@RGE_Map@@QAEJJJQAY0CA@J@Z
    //                               RGE_Map::clean_border_tile
    //                              map.cpp:1199 (3)
    //         00457310     OR         EAX,0xffffffff
    //                              map.cpp:1201 (3)
    //         00457313     RET        0xc
}

// Offset: 0x00457320
uchar RGE_Map::do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Map::do_terrain_brush(long,long,long,unsigned char)      *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_terrain_brush(RGE_Map * this, long param_1, long
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[5]:     0045732a(R), 00457341(W), 0045734b(W), 00457353(R), 
    //                                                                                     0045739b(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00457333(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     00457320(R), 00457345(W), 0045736f(W), 0045739f(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0045737d(R)  
    //                               ?do_terrain_brush@RGE_Map@@UAEEJJJE@Z                        XREF[1]:     00570684(*)  
    //                               RGE_Map::do_terrain_brush
    //                              map.cpp:1205 (16)
    //         00457320     MOV        EAX,dword ptr [ESP + param_3]
    //         00457324     PUSH       EBX
    //         00457325     PUSH       EBP
    //         00457326     PUSH       ESI
    //         00457327     PUSH       EDI
    //         00457328     MOV        EDI,this
    //         0045732a     MOV        this,dword ptr [ESP + param_1]
    //         0045732e     MOV        ESI,this
    //                              map.cpp:1207 (3)
    //         00457330     LEA        EBX,[EAX + this->_padding_*0x1]
    //                              map.cpp:1208 (10)
    //         00457333     MOV        this,dword ptr [ESP + param_2]
    //         00457337     MOV        EBP,this
    //         00457339     SUB        ESI,EAX
    //         0045733b     SUB        EBP,EAX
    //                              map.cpp:1209 (2)
    //         0045733d     ADD        EAX,this
    //                              map.cpp:1213 (12)
    //         0045733f     TEST       ESI,ESI
    //         00457341     MOV        dword ptr [ESP + param_1],ESI
    //         00457345     MOV        dword ptr [ESP + param_3],EAX
    //         00457349     JGE        LAB_00457357
    //                              map.cpp:1214 (12)
    //         0045734b     MOV        dword ptr [ESP + param_1],0x0
    //         00457353     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_00457357                                                 XREF[1]:     00457349(j)  
    //                              map.cpp:1216 (7)
    //         00457357     MOV        this,dword ptr [EDI + 0x8]
    //         0045735a     CMP        EBX,this
    //         0045735c     JL         LAB_00457361
    //                              map.cpp:1217 (3)
    //         0045735e     LEA        EBX,[this->_padding_ + -0x1]
    //                               LAB_00457361                                                 XREF[1]:     0045735c(j)  
    //                              map.cpp:1219 (4)
    //         00457361     TEST       EBP,EBP
    //         00457363     JGE        LAB_00457367
    //                              map.cpp:1220 (2)
    //         00457365     XOR        EBP,EBP
    //                               LAB_00457367                                                 XREF[1]:     00457363(j)  
    //                              map.cpp:1222 (7)
    //         00457367     MOV        this,dword ptr [EDI + 0xc]
    //         0045736a     CMP        EAX,this
    //         0045736c     JL         LAB_00457375
    //                              map.cpp:1223 (7)
    //         0045736e     DEC        this
    //         0045736f     MOV        dword ptr [ESP + param_3],this
    //         00457373     MOV        EAX,this
    //                               LAB_00457375                                                 XREF[1]:     0045736c(j)  
    //                              map.cpp:1225 (4)
    //         00457375     CMP        EBP,EAX
    //         00457377     JG         LAB_004573a8
    //                               LAB_00457379                                                 XREF[1]:     004573a6(j)  
    //                              map.cpp:1226 (4)
    //         00457379     CMP        ESI,EBX
    //         0045737b     JG         LAB_004573a3
    //                               LAB_0045737d                                                 XREF[1]:     00457399(j)  
    //                              map.cpp:1227 (43)
    //         0045737d     MOV        EAX,dword ptr [ESP + param_4]
    //         00457381     MOV        this,dword ptr [EDI + 0x8dc0]
    //         00457387     PUSH       0x0
    //         00457389     PUSH       0x0
    //         0045738b     PUSH       EAX
    //         0045738c     PUSH       EBP
    //         0045738d     PUSH       ESI
    //         0045738e     PUSH       this
    //         0045738f     MOV        this,EDI
    //         00457391     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Game_Wor
    //         00457396     INC        ESI
    //         00457397     CMP        ESI,EBX
    //         00457399     JLE        LAB_0045737d
    //         0045739b     MOV        ESI,dword ptr [ESP + param_1]
    //         0045739f     MOV        EAX,dword ptr [ESP + param_3]
    //                               LAB_004573a3                                                 XREF[1]:     0045737b(j)  
    //         004573a3     INC        EBP
    //         004573a4     CMP        EBP,EAX
    //         004573a6     JLE        LAB_00457379
    //                               LAB_004573a8                                                 XREF[1]:     00457377(j)  
    //                              map.cpp:1230 (9)
    //         004573a8     POP        EDI
    //         004573a9     POP        ESI
    //         004573aa     POP        EBP
    //         004573ab     MOV        AL,0x1
    //         004573ad     POP        EBX
    //         004573ae     RET        0x10
}

// Offset: 0x004573C0
uchar RGE_Map::do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Map::do_terrain_brush_stroke(long,long,long,long,long... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_terrain_brush_stroke(RGE_Map * this, long param_
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[5]:     004573cb(R), 004573df(W), 00457409(R), 00457457(R), 
    //                                                                                     00457462(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     004573f0(R), 004573f5(W), 0045740f(R), 00457454(R), 
    //                                                                                     00457465(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004573e5(R), 004573ed(W), 00457406(R), 004574cc(R), 
    //                                                                                     004574ee(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[5]:     004573fb(R), 00457403(W), 0045740c(R), 004574da(R), 
    //                                                                                     004574eb(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[5]:     004573d0(R), 004573d6(W), 0045744e(R), 00457494(R), 
    //                                                                                     004574e8(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0045744b(R)  
    //              double            Stack[-0xc]:8  dy
    //              double            Stack[-0x14]:8 dx                        XREF[0,1]:   00457470(W)  
    //              double            Stack[-0x1c]:8 y                         XREF[0,1]:   0045746a(W)  
    //              double            Stack[-0x24]:8 x                         XREF[0,1]:   00457478(W)  
    //              long              Stack[-0x28]:4 index                     XREF[3]:     0045741a(W), 00457422(R), 00457474(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[4]:     00457416(W), 0045741e(R), 0045743b(W), 00457441(R)  
    //                               ?do_terrain_brush_stroke@RGE_Map@@UAEEJJJJJE@Z               XREF[2]:     do_terrain_brush_stroke:0050fd67(c
    //                               RGE_Map::do_terrain_brush_stroke                                          00570688(*)  
    //                              map.cpp:1234 (11)
    //         004573c0     PUSH       EBP
    //         004573c1     MOV        EBP,ESP
    //         004573c3     AND        ESP,0xfffffff8
    //         004573c6     SUB        ESP,0x24
    //         004573c9     PUSH       EBX
    //         004573ca     PUSH       ESI
    //                              map.cpp:1245 (20)
    //         004573cb     MOV        EAX,dword ptr [EBP + param_1]
    //         004573ce     MOV        ESI,this
    //         004573d0     MOV        this,dword ptr [EBP + param_5]
    //         004573d3     PUSH       EDI
    //         004573d4     SAR        this,0x1
    //         004573d6     MOV        dword ptr [EBP + param_5],this
    //         004573d9     XOR        this,this
    //         004573db     CMP        EAX,this
    //         004573dd     JGE        LAB_004573e2
    //                              map.cpp:1246 (3)
    //         004573df     MOV        dword ptr [EBP + param_1],this
    //                               LAB_004573e2                                                 XREF[1]:     004573dd(j)  
    //                              map.cpp:1248 (10)
    //         004573e2     MOV        EAX,dword ptr [ESI + 0x8]
    //         004573e5     MOV        EDX,dword ptr [EBP + param_3]
    //         004573e8     CMP        EDX,EAX
    //         004573ea     JL         LAB_004573f0
    //                              map.cpp:1249 (4)
    //         004573ec     DEC        EAX
    //         004573ed     MOV        dword ptr [EBP + param_3],EAX
    //                               LAB_004573f0                                                 XREF[1]:     004573ea(j)  
    //                              map.cpp:1251 (5)
    //         004573f0     CMP        dword ptr [EBP + param_2],this
    //         004573f3     JGE        LAB_004573f8
    //                              map.cpp:1252 (3)
    //         004573f5     MOV        dword ptr [EBP + param_2],this
    //                               LAB_004573f8                                                 XREF[1]:     004573f3(j)  
    //                              map.cpp:1254 (10)
    //         004573f8     MOV        EAX,dword ptr [ESI + 0xc]
    //         004573fb     MOV        this,dword ptr [EBP + param_4]
    //         004573fe     CMP        this,EAX
    //         00457400     JL         LAB_00457406
    //                              map.cpp:1255 (4)
    //         00457402     DEC        EAX
    //         00457403     MOV        dword ptr [EBP + param_4],EAX
    //                               LAB_00457406                                                 XREF[1]:     00457400(j)  
    //                              map.cpp:1257 (3)
    //         00457406     MOV        EAX,dword ptr [EBP + param_3]
    //                              map.cpp:1258 (29)
    //         00457409     MOV        EBX,dword ptr [EBP + param_1]
    //         0045740c     MOV        this,dword ptr [EBP + param_4]
    //         0045740f     MOV        EDI,dword ptr [EBP + param_2]
    //         00457412     SUB        EAX,EBX
    //         00457414     SUB        this,EDI
    //         00457416     MOV        dword ptr [ESP + local_2c],EAX
    //         0045741a     MOV        dword ptr [ESP + index],this
    //         0045741e     FILD       dword ptr [ESP + local_2c]
    //         00457422     FILD       dword ptr [ESP + index]
    //                              map.cpp:1262 (25)
    //         00457426     FLD        ST1
    //         00457428     FLD        ST1
    //         0045742a     FXCH
    //         0045742c     FMUL       ST3
    //         0045742e     FXCH
    //         00457430     FMUL       ST2
    //         00457432     FADDP
    //         00457434     FSQRT
    //         00457436     CALL       __ftol                                           undefined __ftol()
    //         0045743b     MOV        dword ptr [ESP + local_2c],EAX
    //                              map.cpp:1268 (65)
    //         0045743f     MOV        EDX,dword ptr [ESI]
    //         00457441     FILD       dword ptr [ESP + local_2c]
    //         00457445     FXCH       ST2
    //         00457447     FDIV       ST0,ST2
    //         00457449     FXCH
    //         0045744b     MOV        EBX,dword ptr [EBP + param_6]
    //         0045744e     MOV        EAX,dword ptr [EBP + param_5]
    //         00457451     MOV        EDI,dword ptr [EDX + 0xc]
    //         00457454     MOV        this,dword ptr [EBP + param_2]
    //         00457457     MOV        EDX,dword ptr [EBP + param_1]
    //         0045745a     PUSH       EBX
    //         0045745b     PUSH       EAX
    //         0045745c     PUSH       this
    //         0045745d     PUSH       EDX
    //         0045745e     MOV        this,ESI
    //         00457460     FDIV       ST0,ST2
    //         00457462     FILD       dword ptr [EBP + param_1]
    //         00457465     FILD       dword ptr [EBP + param_2]
    //         00457468     FXCH       ST3
    //         0045746a     FSTP       double ptr [ESP + y+0x4]
    //         0045746e     FXCH
    //         00457470     FSTP       double ptr [ESP + dx+0x4]
    //         00457474     FSTP       double ptr [ESP + index]
    //         00457478     FSTP       double ptr [ESP + x+0x4]
    //         0045747c     FSTP       ST0
    //         0045747e     CALL       EDI
    //                              map.cpp:1269 (8)
    //         00457480     MOV        EAX,dword ptr [ESP + 0xc]
    //         00457484     TEST       EAX,EAX
    //         00457486     JLE        LAB_004574cc
    //                              map.cpp:1257 (4)
    //         00457488     MOV        dword ptr [ESP + 0xc],EAX
    //                               LAB_0045748c                                                 XREF[1]:     004574ca(j)  
    //                              map.cpp:1271 (8)
    //         0045748c     FLD        double ptr [ESP + 0x10]
    //         00457490     FADD       double ptr [ESP + 0x20]
    //                              map.cpp:1273 (56)
    //         00457494     MOV        EAX,dword ptr [EBP + param_5]
    //         00457497     PUSH       EBX
    //         00457498     PUSH       EAX=>DAT_fffffff8
    //         00457499     FSTP       double ptr [ESP + 0x18]
    //         0045749d     FLD        double ptr [ESP + 0x20]
    //         004574a1     FADD       double ptr [ESP + 0x30]
    //         004574a5     FSTP       double ptr [ESP + 0x20]
    //         004574a9     FLD        double ptr [ESP + 0x20]
    //         004574ad     CALL       __ftol                                           undefined __ftol()
    //         004574b2     FLD        double ptr [ESP + 0x18]
    //         004574b6     PUSH       EAX=>DAT_fffffff4
    //         004574b7     CALL       __ftol                                           undefined __ftol()
    //         004574bc     PUSH       EAX=>DAT_fffffff0
    //         004574bd     MOV        this,ESI
    //         004574bf     CALL       EDI
    //         004574c1     MOV        EAX,dword ptr [ESP + 0xc]
    //         004574c5     DEC        EAX
    //         004574c6     MOV        dword ptr [ESP + 0xc],EAX
    //         004574ca     JNZ        LAB_0045748c
    //                               LAB_004574cc                                                 XREF[1]:     00457486(j)  
    //                              map.cpp:1276 (28)
    //         004574cc     FILD       dword ptr [EBP + param_3]
    //         004574cf     FCOMP      double ptr [ESP + 0x10]
    //         004574d3     FNSTSW     AX
    //         004574d5     TEST       AH,0x40
    //         004574d8     JZ         LAB_004574e8
    //         004574da     FILD       dword ptr [EBP + param_4]
    //         004574dd     FCOMP      double ptr [ESP + 0x18]
    //         004574e1     FNSTSW     AX
    //         004574e3     TEST       AH,0x40
    //         004574e6     JNZ        LAB_004574f9
    //                               LAB_004574e8                                                 XREF[1]:     004574d8(j)  
    //                              map.cpp:1277 (17)
    //         004574e8     MOV        this,dword ptr [EBP + param_5]
    //         004574eb     MOV        EDX,dword ptr [EBP + param_4]
    //         004574ee     MOV        EAX,dword ptr [EBP + param_3]
    //         004574f1     PUSH       EBX
    //         004574f2     PUSH       this=>DAT_fffffff8
    //         004574f3     PUSH       EDX=>DAT_fffffff4
    //         004574f4     PUSH       EAX=>DAT_fffffff0
    //         004574f5     MOV        this,ESI
    //         004574f7     CALL       EDI
    //                               LAB_004574f9                                                 XREF[1]:     004574e6(j)  
    //                              map.cpp:1280 (11)
    //         004574f9     POP        EDI
    //         004574fa     POP        ESI
    //         004574fb     MOV        AL,0x1
    //         004574fd     POP        EBX
    //         004574fe     MOV        ESP,EBP
    //         00457500     POP        EBP
    //         00457501     RET        0x18
}

// Offset: 0x00457510
uchar RGE_Map::do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Map::do_elevation_brush(long,long,long,unsigned char)    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_elevation_brush(RGE_Map * this, long param_1, lo
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[5]:     00457511(R), 00457560(W), 00457581(R), 004575a4(R), 
    //                                                                                     004575ab(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0045751c(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     00457515(R), 00457534(W), 0045755a(W), 0045759c(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0045756a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0045752e(W), 00457546(W), 004575a0(R)  
    //              long              Stack[-0x8]:4  x2
    //                               ?do_elevation_brush@RGE_Map@@UAEEJJJE@Z                      XREF[2]:     0057068c(*), 005767dc(*)  
    //                               RGE_Map::do_elevation_brush
    //                              map.cpp:1284 (1)
    //         00457510     PUSH       this
    //                              map.cpp:1285 (11)
    //         00457511     MOV        EDX,dword ptr [ESP + param_1]
    //         00457515     MOV        EAX,dword ptr [ESP + param_3]
    //         00457519     PUSH       EBX
    //         0045751a     PUSH       EBP
    //         0045751b     PUSH       ESI
    //                              map.cpp:1287 (16)
    //         0045751c     MOV        ESI,dword ptr [ESP + param_2]
    //         00457520     PUSH       EDI
    //         00457521     MOV        EBP,EDX
    //         00457523     LEA        EDI,[EAX + EDX*0x1]
    //         00457526     MOV        EDX,ESI
    //         00457528     SUB        EBP,EAX
    //         0045752a     SUB        EDX,EAX
    //                              map.cpp:1288 (6)
    //         0045752c     ADD        EAX,ESI
    //         0045752e     MOV        dword ptr [ESP + local_4],EDI
    //                              map.cpp:1293 (8)
    //         00457532     TEST       EBP,EBP
    //         00457534     MOV        dword ptr [ESP + param_3],EAX
    //         00457538     JGE        LAB_0045753c
    //                              map.cpp:1294 (2)
    //         0045753a     XOR        EBP,EBP
    //                               LAB_0045753c                                                 XREF[1]:     00457538(j)  
    //                              map.cpp:1296 (7)
    //         0045753c     MOV        ESI,dword ptr [ECX + this->map_width]
    //         0045753f     CMP        EDI,ESI
    //         00457541     JL         LAB_0045754a
    //                              map.cpp:1297 (7)
    //         00457543     LEA        EDI,[ESI + -0x1]
    //         00457546     MOV        dword ptr [ESP + local_4],EDI
    //                               LAB_0045754a                                                 XREF[1]:     00457541(j)  
    //                              map.cpp:1299 (4)
    //         0045754a     TEST       EDX,EDX
    //         0045754c     JGE        LAB_00457550
    //                              map.cpp:1300 (2)
    //         0045754e     XOR        EDX,EDX
    //                               LAB_00457550                                                 XREF[1]:     0045754c(j)  
    //                              map.cpp:1302 (7)
    //         00457550     MOV        ESI,dword ptr [ECX + this->map_height]
    //         00457553     CMP        EAX,ESI
    //         00457555     JL         LAB_0045755e
    //                              map.cpp:1303 (7)
    //         00457557     LEA        EAX,[ESI + -0x1]
    //         0045755a     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_0045755e                                                 XREF[1]:     00457555(j)  
    //                              map.cpp:1306 (8)
    //         0045755e     CMP        EDX,EAX
    //         00457560     MOV        dword ptr [ESP + param_1],EDX
    //         00457564     JG         LAB_004575b1
    //                               LAB_00457566                                                 XREF[1]:     004575af(j)  
    //                              map.cpp:1307 (4)
    //         00457566     CMP        EBP,EDI
    //         00457568     JG         LAB_004575a4
    //                              map.cpp:1310 (71)
    //         0045756a     MOV        DL,byte ptr [ESP + param_4]
    //         0045756e     LEA        ESI,[EBP + EBP*0x2]
    //         00457572     SUB        EDI,EBP
    //         00457574     SHL        DL,0x5
    //         00457577     SHL        ESI,0x3
    //         0045757a     INC        EDI
    //                               LAB_0045757b                                                 XREF[1]:     0045759a(j)  
    //         0045757b     MOV        EAX,dword ptr [ECX + this->map_row_offset]
    //         00457581     MOV        EBX,dword ptr [ESP + param_1]
    //         00457585     MOV        EAX,dword ptr [EAX + EBX*0x4]
    //         00457588     MOV        BL,byte ptr [EAX + ESI*0x1 + 0x5]
    //         0045758c     ADD        EAX,ESI
    //         0045758e     AND        BL,0x1f
    //         00457591     OR         BL,DL
    //         00457593     ADD        ESI,0x18
    //         00457596     DEC        EDI
    //         00457597     MOV        byte ptr [EAX + 0x5],BL
    //         0045759a     JNZ        LAB_0045757b
    //         0045759c     MOV        EAX,dword ptr [ESP + param_3]
    //         004575a0     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_004575a4                                                 XREF[1]:     00457568(j)  
    //         004575a4     MOV        EDX,dword ptr [ESP + param_1]
    //         004575a8     INC        EDX
    //         004575a9     CMP        EDX,EAX
    //         004575ab     MOV        dword ptr [ESP + param_1],EDX
    //         004575af     JLE        LAB_00457566
    //                               LAB_004575b1                                                 XREF[1]:     00457564(j)  
    //                              map.cpp:1314 (10)
    //         004575b1     POP        EDI
    //         004575b2     POP        ESI
    //         004575b3     POP        EBP
    //         004575b4     MOV        AL,0x1
    //         004575b6     POP        EBX
    //         004575b7     POP        this
    //         004575b8     RET        0x10
}

// Offset: 0x004575C0
uchar RGE_Map::do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Map::do_elevation_brush_stroke(long,long,long,long,lo... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_elevation_brush_stroke(RGE_Map * this, long para
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[8]:     004575c9(R), 004575dc(W), 00457606(R), 00457651(R), 
    //                                                                                     0045765c(R), 004576f3(R), 00457707(W), 0045770f(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[8]:     004575ed(R), 004575f2(W), 0045760c(R), 0045764e(R), 
    //                                                                                     0045765f(R), 00457712(R), 00457726(W), 0045772e(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[7]:     004575e2(R), 004575ea(W), 00457603(R), 004576c6(R), 
    //                                                                                     004576e8(R), 004576f6(R), 0045770a(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[7]:     004575f8(R), 00457600(W), 00457609(R), 004576d4(R), 
    //                                                                                     004576e5(R), 00457715(R), 00457729(W)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004575ce(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[4]:     00457648(R), 0045768e(R), 004576e2(R), 00457731(R)  
    //              double            Stack[-0xc]:8  dy
    //              double            Stack[-0x14]:8 dx                        XREF[0,1]:   0045766a(W)  
    //              double            Stack[-0x1c]:8 y                         XREF[0,1]:   00457664(W)  
    //              double            Stack[-0x24]:8 x                         XREF[0,1]:   00457672(W)  
    //              long              Stack[-0x28]:4 index                     XREF[3]:     00457617(W), 0045761f(R), 0045766e(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[4]:     00457613(W), 0045761b(R), 00457638(W), 0045763e(R)  
    //                               ?do_elevation_brush_stroke@RGE_Map@@UAEEJJJJJE@Z             XREF[2]:     do_elevation_brush_stroke:0050fdf7
    //                               RGE_Map::do_elevation_brush_stroke                                        00570690(*)  
    //                              map.cpp:1318 (9)
    //         004575c0     PUSH       EBP
    //         004575c1     MOV        EBP,ESP
    //         004575c3     AND        ESP,0xfffffff8
    //         004575c6     SUB        ESP,0x24
    //                              map.cpp:1330 (19)
    //         004575c9     MOV        EAX,dword ptr [EBP + param_1]
    //         004575cc     PUSH       EBX
    //         004575cd     PUSH       ESI
    //         004575ce     MOV        ESI,dword ptr [EBP + param_5]
    //         004575d1     PUSH       EDI
    //         004575d2     MOV        EDI,this
    //         004575d4     XOR        this,this
    //         004575d6     SAR        ESI,0x1
    //         004575d8     CMP        EAX,this
    //         004575da     JGE        LAB_004575df
    //                              map.cpp:1331 (3)
    //         004575dc     MOV        dword ptr [EBP + param_1],this
    //                               LAB_004575df                                                 XREF[1]:     004575da(j)  
    //                              map.cpp:1333 (10)
    //         004575df     MOV        EAX,dword ptr [EDI + 0x8]
    //         004575e2     MOV        EDX,dword ptr [EBP + param_3]
    //         004575e5     CMP        EDX,EAX
    //         004575e7     JL         LAB_004575ed
    //                              map.cpp:1334 (4)
    //         004575e9     DEC        EAX
    //         004575ea     MOV        dword ptr [EBP + param_3],EAX
    //                               LAB_004575ed                                                 XREF[1]:     004575e7(j)  
    //                              map.cpp:1336 (5)
    //         004575ed     CMP        dword ptr [EBP + param_2],this
    //         004575f0     JGE        LAB_004575f5
    //                              map.cpp:1337 (3)
    //         004575f2     MOV        dword ptr [EBP + param_2],this
    //                               LAB_004575f5                                                 XREF[1]:     004575f0(j)  
    //                              map.cpp:1339 (10)
    //         004575f5     MOV        EAX,dword ptr [EDI + 0xc]
    //         004575f8     MOV        this,dword ptr [EBP + param_4]
    //         004575fb     CMP        this,EAX
    //         004575fd     JL         LAB_00457603
    //                              map.cpp:1340 (4)
    //         004575ff     DEC        EAX
    //         00457600     MOV        dword ptr [EBP + param_4],EAX
    //                               LAB_00457603                                                 XREF[1]:     004575fd(j)  
    //                              map.cpp:1342 (3)
    //         00457603     MOV        EAX,dword ptr [EBP + param_3]
    //                              map.cpp:1343 (29)
    //         00457606     MOV        EBX,dword ptr [EBP + param_1]
    //         00457609     MOV        this,dword ptr [EBP + param_4]
    //         0045760c     MOV        EDX,dword ptr [EBP + param_2]
    //         0045760f     SUB        EAX,EBX
    //         00457611     SUB        this,EDX
    //         00457613     MOV        dword ptr [ESP + local_2c],EAX
    //         00457617     MOV        dword ptr [ESP + index],this
    //         0045761b     FILD       dword ptr [ESP + local_2c]
    //         0045761f     FILD       dword ptr [ESP + index]
    //                              map.cpp:1347 (25)
    //         00457623     FLD        ST1
    //         00457625     FLD        ST1
    //         00457627     FXCH
    //         00457629     FMUL       ST3
    //         0045762b     FXCH
    //         0045762d     FMUL       ST2
    //         0045762f     FADDP
    //         00457631     FSQRT
    //         00457633     CALL       __ftol                                           undefined __ftol()
    //         00457638     MOV        dword ptr [ESP + local_2c],EAX
    //                              map.cpp:1353 (62)
    //         0045763c     MOV        EDX,dword ptr [EDI]
    //         0045763e     FILD       dword ptr [ESP + local_2c]
    //         00457642     FXCH       ST2
    //         00457644     FDIV       ST0,ST2
    //         00457646     FXCH
    //         00457648     MOV        EAX,dword ptr [EBP + param_6]
    //         0045764b     MOV        EBX,dword ptr [EDX + 0x14]
    //         0045764e     MOV        this,dword ptr [EBP + param_2]
    //         00457651     MOV        EDX,dword ptr [EBP + param_1]
    //         00457654     PUSH       EAX
    //         00457655     PUSH       ESI
    //         00457656     PUSH       this
    //         00457657     PUSH       EDX
    //         00457658     MOV        this,EDI
    //         0045765a     FDIV       ST0,ST2
    //         0045765c     FILD       dword ptr [EBP + param_1]
    //         0045765f     FILD       dword ptr [EBP + param_2]
    //         00457662     FXCH       ST3
    //         00457664     FSTP       double ptr [ESP + y+0x4]
    //         00457668     FXCH
    //         0045766a     FSTP       double ptr [ESP + dx+0x4]
    //         0045766e     FSTP       double ptr [ESP + index]
    //         00457672     FSTP       double ptr [ESP + x+0x4]
    //         00457676     FSTP       ST0
    //         00457678     CALL       EBX
    //                              map.cpp:1354 (8)
    //         0045767a     MOV        EAX,dword ptr [ESP + 0xc]
    //         0045767e     TEST       EAX,EAX
    //         00457680     JLE        LAB_004576c6
    //                              map.cpp:1342 (4)
    //         00457682     MOV        dword ptr [ESP + 0xc],EAX
    //                               LAB_00457686                                                 XREF[1]:     004576c4(j)  
    //                              map.cpp:1356 (8)
    //         00457686     FLD        double ptr [ESP + 0x10]
    //         0045768a     FADD       double ptr [ESP + 0x20]
    //                              map.cpp:1358 (56)
    //         0045768e     MOV        EAX,dword ptr [EBP + param_6]
    //         00457691     PUSH       EAX
    //         00457692     PUSH       ESI=>DAT_fffffff8
    //         00457693     FSTP       double ptr [ESP + 0x18]
    //         00457697     FLD        double ptr [ESP + 0x20]
    //         0045769b     FADD       double ptr [ESP + 0x30]
    //         0045769f     FSTP       double ptr [ESP + 0x20]
    //         004576a3     FLD        double ptr [ESP + 0x20]
    //         004576a7     CALL       __ftol                                           undefined __ftol()
    //         004576ac     FLD        double ptr [ESP + 0x18]
    //         004576b0     PUSH       EAX=>DAT_fffffff4
    //         004576b1     CALL       __ftol                                           undefined __ftol()
    //         004576b6     PUSH       EAX=>DAT_fffffff0
    //         004576b7     MOV        this,EDI
    //         004576b9     CALL       EBX
    //         004576bb     MOV        EAX,dword ptr [ESP + 0xc]
    //         004576bf     DEC        EAX
    //         004576c0     MOV        dword ptr [ESP + 0xc],EAX
    //         004576c4     JNZ        LAB_00457686
    //                               LAB_004576c6                                                 XREF[1]:     00457680(j)  
    //                              map.cpp:1361 (28)
    //         004576c6     FILD       dword ptr [EBP + param_3]
    //         004576c9     FCOMP      double ptr [ESP + 0x10]
    //         004576cd     FNSTSW     AX
    //         004576cf     TEST       AH,0x40
    //         004576d2     JZ         LAB_004576e2
    //         004576d4     FILD       dword ptr [EBP + param_4]
    //         004576d7     FCOMP      double ptr [ESP + 0x18]
    //         004576db     FNSTSW     AX
    //         004576dd     TEST       AH,0x40
    //         004576e0     JNZ        LAB_004576f3
    //                               LAB_004576e2                                                 XREF[1]:     004576d2(j)  
    //                              map.cpp:1362 (17)
    //         004576e2     MOV        this,dword ptr [EBP + param_6]
    //         004576e5     MOV        EDX,dword ptr [EBP + param_4]
    //         004576e8     MOV        EAX,dword ptr [EBP + param_3]
    //         004576eb     PUSH       this
    //         004576ec     PUSH       ESI=>DAT_fffffff8
    //         004576ed     PUSH       EDX=>DAT_fffffff4
    //         004576ee     PUSH       EAX=>DAT_fffffff0
    //         004576ef     MOV        this,EDI
    //         004576f1     CALL       EBX
    //                               LAB_004576f3                                                 XREF[1]:     004576e0(j)  
    //                              map.cpp:1364 (10)
    //         004576f3     MOV        EDX,dword ptr [EBP + param_1]
    //         004576f6     MOV        EBX,dword ptr [EBP + param_3]
    //         004576f9     CMP        EDX,EBX
    //         004576fb     JGE        LAB_00457703
    //                              map.cpp:1366 (2)
    //         004576fd     SUB        EDX,ESI
    //                              map.cpp:1367 (2)
    //         004576ff     ADD        EBX,ESI
    //                              map.cpp:1369 (2)
    //         00457701     JMP        LAB_00457712
    //                               LAB_00457703                                                 XREF[1]:     004576fb(j)  
    //                              map.cpp:1372 (2)
    //         00457703     SUB        EBX,ESI
    //                              map.cpp:1373 (13)
    //         00457705     ADD        EDX,ESI
    //         00457707     MOV        dword ptr [EBP + param_1],EBX
    //         0045770a     MOV        dword ptr [EBP + param_3],EDX
    //         0045770d     MOV        EBX,EDX
    //         0045770f     MOV        EDX,dword ptr [EBP + param_1]
    //                               LAB_00457712                                                 XREF[1]:     00457701(j)  
    //                              map.cpp:1376 (10)
    //         00457712     MOV        EAX,dword ptr [EBP + param_2]
    //         00457715     MOV        this,dword ptr [EBP + param_4]
    //         00457718     CMP        EAX,this
    //         0045771a     JGE        LAB_00457722
    //                              map.cpp:1378 (2)
    //         0045771c     SUB        EAX,ESI
    //                              map.cpp:1379 (2)
    //         0045771e     ADD        this,ESI
    //                              map.cpp:1381 (2)
    //         00457720     JMP        LAB_00457731
    //                               LAB_00457722                                                 XREF[1]:     0045771a(j)  
    //                              map.cpp:1384 (2)
    //         00457722     SUB        this,ESI
    //                              map.cpp:1385 (13)
    //         00457724     ADD        EAX,ESI
    //         00457726     MOV        dword ptr [EBP + param_2],this
    //         00457729     MOV        dword ptr [EBP + param_4],EAX
    //         0045772c     MOV        this,EAX
    //         0045772e     MOV        EAX,dword ptr [EBP + param_2]
    //                               LAB_00457731                                                 XREF[1]:     00457720(j)  
    //                              map.cpp:1388 (15)
    //         00457731     MOV        ESI,dword ptr [EBP + param_6]
    //         00457734     PUSH       ESI
    //         00457735     PUSH       this=>DAT_fffffff8
    //         00457736     PUSH       EBX=>DAT_fffffff4
    //         00457737     PUSH       EAX=>DAT_fffffff0
    //         00457738     PUSH       EDX
    //         00457739     MOV        this,EDI
    //         0045773b     CALL       RGE_Map::clean_elevation                         void clean_elevation(RGE_Map * this, long par
    //                              map.cpp:1391 (11)
    //         00457740     POP        EDI
    //         00457741     POP        ESI
    //         00457742     MOV        AL,0x1
    //         00457744     POP        EBX
    //         00457745     MOV        ESP,EBP
    //         00457747     POP        EBP
    //         00457748     RET        0x18
}

// Offset: 0x00457750
uchar RGE_Map::do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Map::do_cliff_brush(long,long,unsigned char,unsigned ... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_cliff_brush(RGE_Map * this, long param_1, long p
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              uchar             Stack[0xc]:1   param_3
    //              uchar             Stack[0x10]:1  param_4
    //                               ?do_cliff_brush@RGE_Map@@UAEEJJEE@Z                          XREF[2]:     do_cliff_brush:00510a8c(c), 
    //                               RGE_Map::do_cliff_brush                                                   00570694(*)  
    //                              map.cpp:1395 (2)
    //         00457750     XOR        AL,AL
    //                              map.cpp:1397 (3)
    //         00457752     RET        0x10
}

// Offset: 0x00457760
uchar RGE_Map::do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Map::do_cliff_brush_stroke(long,long,long,long,unsign... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall do_cliff_brush_stroke(RGE_Map * this, long param_1,
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[5]:     00457769(R), 00457777(W), 004577a1(R), 004577ef(R), 
    //                                                                                     004577fa(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     00457788(R), 0045778d(W), 004577a7(R), 004577ec(R), 
    //                                                                                     004577fd(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     0045777d(R), 00457785(W), 0045779e(R), 00457864(R), 
    //                                                                                     00457886(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[5]:     00457793(R), 0045779b(W), 004577a4(R), 00457872(R), 
    //                                                                                     00457883(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[3]:     004577e6(R), 0045782c(R), 00457880(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     004577e3(R)  
    //              double            Stack[-0xc]:8  dy
    //              double            Stack[-0x14]:8 dx                        XREF[0,1]:   00457808(W)  
    //              double            Stack[-0x1c]:8 y                         XREF[0,1]:   00457802(W)  
    //              double            Stack[-0x24]:8 x                         XREF[0,1]:   00457810(W)  
    //              long              Stack[-0x28]:4 index                     XREF[3]:     004577b2(W), 004577ba(R), 0045780c(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[4]:     004577ae(W), 004577b6(R), 004577d3(W), 004577d9(R)  
    //                               ?do_cliff_brush_stroke@RGE_Map@@UAEEJJJJEE@Z                 XREF[2]:     do_cliff_brush_stroke:00510c81(c), 
    //                               RGE_Map::do_cliff_brush_stroke                                            00570698(*)  
    //                              map.cpp:1401 (9)
    //         00457760     PUSH       EBP
    //         00457761     MOV        EBP,ESP
    //         00457763     AND        ESP,0xfffffff8
    //         00457766     SUB        ESP,0x24
    //                              map.cpp:1410 (14)
    //         00457769     MOV        EAX,dword ptr [EBP + param_1]
    //         0045776c     PUSH       EBX
    //         0045776d     PUSH       ESI
    //         0045776e     MOV        ESI,this
    //         00457770     XOR        this,this
    //         00457772     PUSH       EDI
    //         00457773     CMP        EAX,this
    //         00457775     JGE        LAB_0045777a
    //                              map.cpp:1411 (3)
    //         00457777     MOV        dword ptr [EBP + param_1],this
    //                               LAB_0045777a                                                 XREF[1]:     00457775(j)  
    //                              map.cpp:1413 (10)
    //         0045777a     MOV        EAX,dword ptr [ESI + 0x8]
    //         0045777d     MOV        EDX,dword ptr [EBP + param_3]
    //         00457780     CMP        EDX,EAX
    //         00457782     JL         LAB_00457788
    //                              map.cpp:1414 (4)
    //         00457784     DEC        EAX
    //         00457785     MOV        dword ptr [EBP + param_3],EAX
    //                               LAB_00457788                                                 XREF[1]:     00457782(j)  
    //                              map.cpp:1416 (5)
    //         00457788     CMP        dword ptr [EBP + param_2],this
    //         0045778b     JGE        LAB_00457790
    //                              map.cpp:1417 (3)
    //         0045778d     MOV        dword ptr [EBP + param_2],this
    //                               LAB_00457790                                                 XREF[1]:     0045778b(j)  
    //                              map.cpp:1419 (10)
    //         00457790     MOV        EAX,dword ptr [ESI + 0xc]
    //         00457793     MOV        this,dword ptr [EBP + param_4]
    //         00457796     CMP        this,EAX
    //         00457798     JL         LAB_0045779e
    //                              map.cpp:1420 (4)
    //         0045779a     DEC        EAX
    //         0045779b     MOV        dword ptr [EBP + param_4],EAX
    //                               LAB_0045779e                                                 XREF[1]:     00457798(j)  
    //                              map.cpp:1422 (3)
    //         0045779e     MOV        EAX,dword ptr [EBP + param_3]
    //                              map.cpp:1423 (29)
    //         004577a1     MOV        EBX,dword ptr [EBP + param_1]
    //         004577a4     MOV        this,dword ptr [EBP + param_4]
    //         004577a7     MOV        EDI,dword ptr [EBP + param_2]
    //         004577aa     SUB        EAX,EBX
    //         004577ac     SUB        this,EDI
    //         004577ae     MOV        dword ptr [ESP + local_2c],EAX
    //         004577b2     MOV        dword ptr [ESP + index],this
    //         004577b6     FILD       dword ptr [ESP + local_2c]
    //         004577ba     FILD       dword ptr [ESP + index]
    //                              map.cpp:1427 (25)
    //         004577be     FLD        ST1
    //         004577c0     FLD        ST1
    //         004577c2     FXCH
    //         004577c4     FMUL       ST3
    //         004577c6     FXCH
    //         004577c8     FMUL       ST2
    //         004577ca     FADDP
    //         004577cc     FSQRT
    //         004577ce     CALL       __ftol                                           undefined __ftol()
    //         004577d3     MOV        dword ptr [ESP + local_2c],EAX
    //                              map.cpp:1433 (65)
    //         004577d7     MOV        EDX,dword ptr [ESI]
    //         004577d9     FILD       dword ptr [ESP + local_2c]
    //         004577dd     FXCH       ST2
    //         004577df     FDIV       ST0,ST2
    //         004577e1     FXCH
    //         004577e3     MOV        EBX,dword ptr [EBP + param_6]
    //         004577e6     MOV        EAX,dword ptr [EBP + param_5]
    //         004577e9     MOV        EDI,dword ptr [EDX + 0x1c]
    //         004577ec     MOV        this,dword ptr [EBP + param_2]
    //         004577ef     MOV        EDX,dword ptr [EBP + param_1]
    //         004577f2     PUSH       EBX
    //         004577f3     PUSH       EAX
    //         004577f4     PUSH       this
    //         004577f5     PUSH       EDX
    //         004577f6     MOV        this,ESI
    //         004577f8     FDIV       ST0,ST2
    //         004577fa     FILD       dword ptr [EBP + param_1]
    //         004577fd     FILD       dword ptr [EBP + param_2]
    //         00457800     FXCH       ST3
    //         00457802     FSTP       double ptr [ESP + y+0x4]
    //         00457806     FXCH
    //         00457808     FSTP       double ptr [ESP + dx+0x4]
    //         0045780c     FSTP       double ptr [ESP + index]
    //         00457810     FSTP       double ptr [ESP + x+0x4]
    //         00457814     FSTP       ST0
    //         00457816     CALL       EDI
    //                              map.cpp:1434 (8)
    //         00457818     MOV        EAX,dword ptr [ESP + 0xc]
    //         0045781c     TEST       EAX,EAX
    //         0045781e     JLE        LAB_00457864
    //                              map.cpp:1422 (4)
    //         00457820     MOV        dword ptr [ESP + 0xc],EAX
    //                               LAB_00457824                                                 XREF[1]:     00457862(j)  
    //                              map.cpp:1436 (8)
    //         00457824     FLD        double ptr [ESP + 0x10]
    //         00457828     FADD       double ptr [ESP + 0x20]
    //                              map.cpp:1438 (56)
    //         0045782c     MOV        EAX,dword ptr [EBP + param_5]
    //         0045782f     PUSH       EBX
    //         00457830     PUSH       EAX=>DAT_fffffff8
    //         00457831     FSTP       double ptr [ESP + 0x18]
    //         00457835     FLD        double ptr [ESP + 0x20]
    //         00457839     FADD       double ptr [ESP + 0x30]
    //         0045783d     FSTP       double ptr [ESP + 0x20]
    //         00457841     FLD        double ptr [ESP + 0x20]
    //         00457845     CALL       __ftol                                           undefined __ftol()
    //         0045784a     FLD        double ptr [ESP + 0x18]
    //         0045784e     PUSH       EAX=>DAT_fffffff4
    //         0045784f     CALL       __ftol                                           undefined __ftol()
    //         00457854     PUSH       EAX=>DAT_fffffff0
    //         00457855     MOV        this,ESI
    //         00457857     CALL       EDI
    //         00457859     MOV        EAX,dword ptr [ESP + 0xc]
    //         0045785d     DEC        EAX
    //         0045785e     MOV        dword ptr [ESP + 0xc],EAX
    //         00457862     JNZ        LAB_00457824
    //                               LAB_00457864                                                 XREF[1]:     0045781e(j)  
    //                              map.cpp:1441 (28)
    //         00457864     FILD       dword ptr [EBP + param_3]
    //         00457867     FCOMP      double ptr [ESP + 0x10]
    //         0045786b     FNSTSW     AX
    //         0045786d     TEST       AH,0x40
    //         00457870     JZ         LAB_00457880
    //         00457872     FILD       dword ptr [EBP + param_4]
    //         00457875     FCOMP      double ptr [ESP + 0x18]
    //         00457879     FNSTSW     AX
    //         0045787b     TEST       AH,0x40
    //         0045787e     JNZ        LAB_00457891
    //                               LAB_00457880                                                 XREF[1]:     00457870(j)  
    //                              map.cpp:1442 (17)
    //         00457880     MOV        this,dword ptr [EBP + param_5]
    //         00457883     MOV        EDX,dword ptr [EBP + param_4]
    //         00457886     MOV        EAX,dword ptr [EBP + param_3]
    //         00457889     PUSH       EBX
    //         0045788a     PUSH       this=>DAT_fffffff8
    //         0045788b     PUSH       EDX=>DAT_fffffff4
    //         0045788c     PUSH       EAX=>DAT_fffffff0
    //         0045788d     MOV        this,ESI
    //         0045788f     CALL       EDI
    //                               LAB_00457891                                                 XREF[1]:     0045787e(j)  
    //                              map.cpp:1445 (11)
    //         00457891     POP        EDI
    //         00457892     POP        ESI
    //         00457893     MOV        AL,0x1
    //         00457895     POP        EBX
    //         00457896     MOV        ESP,EBP
    //         00457898     POP        EBP
    //         00457899     RET        0x18
}

// Offset: 0x004578A0
void RGE_Map::map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Map::map_generate(class RGE_Player *,class RGE_Game_World *,st... *
    //                              *********************************************************************************************************
    //                              void __thiscall map_generate(RGE_Map * this, RGE_Player * param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1
    //              RGE_Game_World    Stack[0x8]:4   param_2
    //              RGE_Player_Inf    Stack[0xc]:4   param_3
    //              uchar *           Stack[0x10]:4  param_4
    //                               ?map_generate@RGE_Map@@UAEXPAVRGE_Player@@PAVRGE_Game_World  XREF[1]:     0057069c(*)  
    //                               RGE_Map::map_generate
    //                              map.cpp:1450 (3)
    //         004578a0     RET        0x10
}

// Offset: 0x004578B0
void RGE_Map::map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Map::map_generate2(class RGE_Game_World *,long,long,unsigned c... *
    //                              *********************************************************************************************************
    //                              void __thiscall map_generate2(RGE_Map * this, RGE_Game_World * param
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     0045791a(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00457916(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00457912(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00457951(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0045793f(R)  
    //                               ?map_generate2@RGE_Map@@UAEXPAVRGE_Game_World@@JJEJ@Z        XREF[2]:     005706a0(*), 005767f0(*)  
    //                               RGE_Map::map_generate2
    //                              map.cpp:1478 (6)
    //         004578b0     PUSH       EBX
    //         004578b1     PUSH       EBP
    //         004578b2     PUSH       ESI
    //         004578b3     MOV        ESI,this
    //         004578b5     PUSH       EDI
    //                              map.cpp:1480 (9)
    //         004578b6     MOV        EAX,dword ptr [ESI + 0x8dc0]
    //         004578bc     MOV        BL,byte ptr [EAX + 0x1d]
    //                              map.cpp:1482 (4)
    //         004578bf     MOV        byte ptr [EAX + 0x1d],0x3
    //                              map.cpp:1484 (8)
    //         004578c3     MOV        EAX,[rge_base_game]                              = 00000000
    //         004578c8     MOV        EDI,dword ptr [EAX + 0x2c]
    //                              map.cpp:1485 (5)
    //         004578cb     CMP        EDI,-0x1
    //         004578ce     JNZ        LAB_004578e4
    //                              map.cpp:1486 (20)
    //         004578d0     PUSH       0x5ce
    //         004578d5     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         004578da     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004578df     ADD        ESP,0x8
    //         004578e2     MOV        EDI,EAX
    //                               LAB_004578e4                                                 XREF[1]:     004578ce(j)  
    //                              map.cpp:1488 (6)
    //         004578e4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              map.cpp:1490 (24)
    //         004578ea     PUSH       EDI
    //         004578eb     PUSH       s_Random_Map_Seed_=_%d                           = "Random Map Seed = %d"
    //         004578f0     MOV        dword ptr [ECX + this+0x34],EDI
    //         004578f3     MOV        EDX,dword ptr [L]                                = 00000000
    //         004578f9     PUSH       EDX
    //         004578fa     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004578ff     ADD        ESP,0xc
    //                              map.cpp:1498 (16)
    //         00457902     PUSH       EDI
    //         00457903     PUSH       0x5da
    //         00457908     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         0045790d     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              map.cpp:1499 (29)
    //         00457912     MOV        EAX,dword ptr [ESP + param_3]
    //         00457916     MOV        this,dword ptr [ESP + param_2]
    //         0045791a     MOV        EBP,dword ptr [ESP + param_1]
    //         0045791e     ADD        ESP,0xc
    //         00457921     PUSH       EAX
    //         00457922     PUSH       this
    //         00457923     PUSH       0x0
    //         00457925     PUSH       EBP
    //         00457926     PUSH       0x0
    //         00457928     MOV        this,ESI
    //         0045792a     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              map.cpp:1501 (16)
    //         0045792f     PUSH       EDI
    //         00457930     PUSH       0x5dd
    //         00457935     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         0045793a     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              map.cpp:1502 (28)
    //         0045793f     MOV        EAX,dword ptr [ESP + param_5]
    //         00457943     MOV        this,dword ptr [ESI + 0x8dbc]
    //         00457949     ADD        ESP,0xc
    //         0045794c     MOV        EDX,dword ptr [this->_padding_]
    //         0045794e     PUSH       0x1
    //         00457950     PUSH       EAX
    //         00457951     MOV        EAX,dword ptr [ESP + param_4]
    //         00457955     PUSH       EAX
    //         00457956     PUSH       EBP
    //         00457957     PUSH       ESI
    //         00457958     CALL       dword ptr [EDX + 0x14]
    //                              map.cpp:1504 (16)
    //         0045795b     PUSH       EDI
    //         0045795c     PUSH       offset DAT_fffffff8
    //         00457961     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00457966     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              map.cpp:1505 (13)
    //         0045796b     MOV        this,dword ptr [ESI + 0x8dbc]
    //         00457971     ADD        ESP,0xc
    //         00457974     MOV        EDX,dword ptr [this->_padding_]
    //         00457976     CALL       dword ptr [EDX]
    //                              map.cpp:1507 (11)
    //         00457978     MOV        this,dword ptr [ESI + 0x8dbc]
    //         0045797e     MOV        EAX,dword ptr [this->_padding_]
    //         00457980     CALL       dword ptr [EAX + 0x18]
    //                              map.cpp:1509 (36)
    //         00457983     PUSH       0x5e5
    //         00457988     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         0045798d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00457992     MOV        this,dword ptr [L]                               = 00000000
    //         00457998     ADD        ESP,0x8
    //         0045799b     PUSH       EAX
    //         0045799c     PUSH       s_After_Random_Map_Generation_rand               = "After Random Map Generation random number 
    //         004579a1     PUSH       this=>DAT_fffffff4
    //         004579a2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              map.cpp:1510 (9)
    //         004579a7     MOV        EDX,dword ptr [ESI + 0x8dc0]
    //         004579ad     ADD        ESP,0xc
    //                              map.cpp:1511 (10)
    //         004579b0     POP        EDI
    //         004579b1     POP        ESI
    //         004579b2     MOV        byte ptr [EDX + 0x1d],BL
    //         004579b5     POP        EBP
    //         004579b6     POP        EBX
    //         004579b7     RET        0x14
}

// Offset: 0x004579C0
void load_map(RGE_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::load_map(int)                                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall load_map(RGE_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[9]:     004579e0(R), 00457aee(*), 00457afe(R), 00457b0a(*), 
    //                                                                                     00457b1c(R), 00457b2c(*), 00457b41(R), 00457b4d(*), 
    //                                                                                     00457b5f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00457a3f(W), 00457a5c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00457c2e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004579d8(*), 00457a03(R)  
    //              long              Stack[-0x14]:4 w                         XREF[2]:     004579f2(*), 004579ff(R)  
    //              long              Stack[-0x18]:4 h                         XREF[7]:     00457a39(W), 00457aa2(W), 00457ba8(R), 00457bb4(W), 
    //                                                                                     00457be2(W), 00457c12(R), 00457c1c(W)  
    //              int               Stack[-0x1c]:4 y                         XREF[3]:     00457ab2(W), 00457b82(R), 00457b9e(W)  
    //              int               Stack[-0x20]:4 x
    //                               ?load_map@RGE_Map@@QAEXH@Z                                   XREF[1]:     load_world:00542245(c)  
    //                               RGE_Map::load_map
    //                              map.cpp:1516 (24)
    //         004579c0     MOV        EAX,FS:[0x0]
    //         004579c6     PUSH       -0x1
    //         004579c8     PUSH       FUN_0055db0b
    //         004579cd     PUSH       EAX
    //         004579ce     MOV        dword ptr FS:[0x0],ESP
    //         004579d5     SUB        ESP,0x10
    //                              map.cpp:1524 (26)
    //         004579d8     LEA        EAX=>local_10,[ESP + 0xc]
    //         004579dc     PUSH       EBX
    //         004579dd     PUSH       EBP
    //         004579de     PUSH       ESI
    //         004579df     PUSH       EDI
    //         004579e0     MOV        EDI,dword ptr [ESP + param_1]
    //         004579e4     PUSH       0x4
    //         004579e6     PUSH       EAX
    //         004579e7     MOV        EBX,this
    //         004579e9     PUSH       EDI
    //         004579ea     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004579ef     ADD        ESP,0xc
    //                              map.cpp:1525 (13)
    //         004579f2     LEA        this=>w,[ESP + 0x18]
    //         004579f6     PUSH       0x4
    //         004579f8     PUSH       this
    //         004579f9     PUSH       EDI
    //         004579fa     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              map.cpp:1527 (20)
    //         004579ff     MOV        EDX,dword ptr [ESP + w]
    //         00457a03     MOV        EAX,dword ptr [ESP + local_10]
    //         00457a07     ADD        ESP,0xc
    //         00457a0a     MOV        this,EBX
    //         00457a0c     PUSH       EDX
    //         00457a0d     PUSH       EAX
    //         00457a0e     CALL       RGE_Map::new_map                                 void new_map(RGE_Map * this, long param_1, lo
    //                              map.cpp:1529 (12)
    //         00457a13     MOV        ESI,dword ptr [EBX + 0x8dc4]
    //         00457a19     XOR        EBP,EBP
    //         00457a1b     CMP        ESI,EBP
    //         00457a1d     JZ         LAB_00457a2f
    //                              map.cpp:1530 (16)
    //         00457a1f     MOV        this,ESI
    //         00457a21     CALL       RGE_Zone_Map_List::~RGE_Zone_Map_List            void ~RGE_Zone_Map_List(RGE_Zone_Map_List * t
    //         00457a26     PUSH       ESI
    //         00457a27     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00457a2c     ADD        ESP,0x4
    //                               LAB_00457a2f                                                 XREF[1]:     00457a1d(j)  
    //                              map.cpp:1531 (35)
    //         00457a2f     PUSH       0xc
    //         00457a31     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00457a36     ADD        ESP,0x4
    //         00457a39     MOV        dword ptr [ESP + h],EAX
    //         00457a3d     CMP        EAX,EBP
    //         00457a3f     MOV        dword ptr [ESP + local_4],EBP
    //         00457a43     JZ         LAB_00457a50
    //         00457a45     PUSH       EBX
    //         00457a46     PUSH       EDI
    //         00457a47     MOV        this,EAX
    //         00457a49     CALL       RGE_Zone_Map_List::RGE_Zone_Map_List             undefined RGE_Zone_Map_List(RGE_Zone_Map_List
    //         00457a4e     JMP        LAB_00457a52
    //                               LAB_00457a50                                                 XREF[1]:     00457a43(j)  
    //         00457a50     XOR        EAX,EAX
    //                               LAB_00457a52                                                 XREF[1]:     00457a4e(j)  
    //                              map.cpp:1533 (32)
    //         00457a52     LEA        this,[EBX + 0x8db8]
    //         00457a58     PUSH       0x1
    //         00457a5a     PUSH       this
    //         00457a5b     PUSH       EDI
    //         00457a5c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00457a64     MOV        dword ptr [EBX + 0x8dc4],EAX
    //         00457a6a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457a6f     ADD        ESP,0xc
    //                              map.cpp:1534 (15)
    //         00457a72     LEA        EDX,[EBX + 0x8db9]
    //         00457a78     PUSH       0x1
    //         00457a7a     PUSH       EDX
    //         00457a7b     PUSH       EDI
    //         00457a7c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              map.cpp:1536 (26)
    //         00457a81     FLD        float ptr [save_game_version]                    = 7.23
    //         00457a87     FCOMP      float ptr [DAT_005706a8]                         = align(2)
    //         00457a8d     ADD        ESP,0xc
    //         00457a90     FNSTSW     AX
    //         00457a92     TEST       AH,0x1
    //         00457a95     JNZ        LAB_00457bc0
    //                              map.cpp:1538 (17)
    //         00457a9b     MOV        this,dword ptr [EBX + 0xc]
    //         00457a9e     XOR        EAX,EAX
    //         00457aa0     CMP        this,EBP
    //         00457aa2     MOV        dword ptr [ESP + h],EAX
    //         00457aa6     JLE        LAB_00457c22
    //                               LAB_00457aac                                                 XREF[1]:     00457bb8(j)  
    //                              map.cpp:1540 (6)
    //         00457aac     MOV        this,dword ptr [EBX + 0x8d8c]
    //                              map.cpp:1541 (18)
    //         00457ab2     MOV        dword ptr [ESP + y],EBP
    //         00457ab6     MOV        ESI,dword ptr [this->_padding_ + EAX*0x4]
    //         00457ab9     MOV        this,dword ptr [EBX + 0x8]
    //         00457abc     CMP        this,EBP
    //         00457abe     JLE        LAB_00457bae
    //                               LAB_00457ac4                                                 XREF[1]:     00457ba2(j)  
    //                              map.cpp:1543 (18)
    //         00457ac4     PUSH       0x2
    //         00457ac6     PUSH       ESI
    //         00457ac7     PUSH       EDI
    //         00457ac8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457acd     LEA        EBP,[ESI + 0x4]
    //         00457ad0     ADD        ESP,0xc
    //         00457ad3     LEA        EDX,[EBP + -0x2]
    //                              map.cpp:1544 (12)
    //         00457ad6     PUSH       0x2
    //         00457ad8     PUSH       EDX
    //         00457ad9     PUSH       EDI
    //         00457ada     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457adf     ADD        ESP,0xc
    //                              map.cpp:1545 (12)
    //         00457ae2     PUSH       0x1
    //         00457ae4     PUSH       EBP
    //         00457ae5     PUSH       EDI
    //         00457ae6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457aeb     ADD        ESP,0xc
    //                              map.cpp:1546 (28)
    //         00457aee     LEA        EAX=>param_1,[ESP + 0x30]
    //         00457af2     PUSH       0x1
    //         00457af4     PUSH       EAX
    //         00457af5     PUSH       EDI
    //         00457af6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457afb     MOV        AL,byte ptr [ESI + 0x5]
    //         00457afe     MOV        this,byte ptr [ESP + param_1]
    //         00457b02     ADD        ESP,0xc
    //         00457b05     XOR        this,AL
    //         00457b07     AND        this,0x1f
    //                              map.cpp:1547 (34)
    //         00457b0a     LEA        EDX=>param_1,[ESP + 0x30]
    //         00457b0e     PUSH       0x1
    //         00457b10     XOR        this,AL
    //         00457b12     PUSH       EDX
    //         00457b13     PUSH       EDI
    //         00457b14     MOV        byte ptr [ESI + 0x5],this
    //         00457b17     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457b1c     MOV        AL,byte ptr [ESP + param_1]
    //         00457b20     MOV        this,byte ptr [ESI + 0x5]
    //         00457b23     ADD        ESP,0xc
    //         00457b26     AND        this,0x1f
    //         00457b29     SHL        AL,0x5
    //                              map.cpp:1548 (33)
    //         00457b2c     LEA        EDX=>param_1,[ESP + 0x30]
    //         00457b30     PUSH       0x1
    //         00457b32     OR         AL,this
    //         00457b34     PUSH       EDX
    //         00457b35     PUSH       EDI
    //         00457b36     MOV        byte ptr [ESI + 0x5],AL
    //         00457b39     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457b3e     MOV        AL,byte ptr [ESI + 0x6]
    //         00457b41     MOV        this,byte ptr [ESP + param_1]
    //         00457b45     ADD        ESP,0xc
    //         00457b48     XOR        this,AL
    //         00457b4a     AND        this,0xf
    //                              map.cpp:1549 (31)
    //         00457b4d     LEA        EDX=>param_1,[ESP + 0x30]
    //         00457b51     PUSH       0x1
    //         00457b53     XOR        this,AL
    //         00457b55     PUSH       EDX
    //         00457b56     PUSH       EDI
    //         00457b57     MOV        byte ptr [ESI + 0x6],this
    //         00457b5a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00457b5f     MOV        AL,byte ptr [ESP + param_1]
    //         00457b63     MOV        this,byte ptr [ESI + 0x6]
    //         00457b66     SHL        AL,0x4
    //         00457b69     AND        this,0xf
    //                              map.cpp:1551 (6)
    //         00457b6c     MOV        byte ptr [ESI + 0x7],0x0
    //         00457b70     OR         AL,this
    //                              map.cpp:1552 (7)
    //         00457b72     MOV        byte ptr [ESI + 0x8],0xff
    //         00457b76     MOV        byte ptr [ESI + 0x6],AL
    //                              map.cpp:1557 (5)
    //         00457b79     XOR        EAX,EAX
    //         00457b7b     MOV        dword ptr [ESI + 0x10],EAX
    //                              map.cpp:1558 (26)
    //         00457b7e     MOV        word ptr [ESI + 0x14],AX
    //         00457b82     MOV        EAX,dword ptr [ESP + y]
    //         00457b86     MOV        byte ptr [ESI + 0x9],0x0
    //         00457b8a     MOV        byte ptr [ESI + 0xa],0x0
    //         00457b8e     MOV        byte ptr [ESI + 0xb],0xff
    //         00457b92     MOV        this,dword ptr [EBX + 0x8]
    //         00457b95     ADD        ESP,0xc
    //                              map.cpp:1560 (38)
    //         00457b98     ADD        ESI,0x18
    //         00457b9b     INC        EAX
    //         00457b9c     CMP        EAX,this
    //         00457b9e     MOV        dword ptr [ESP + y],EAX
    //         00457ba2     JL         LAB_00457ac4
    //         00457ba8     MOV        EAX,dword ptr [ESP + h]
    //         00457bac     XOR        EBP,EBP
    //                               LAB_00457bae                                                 XREF[1]:     00457abe(j)  
    //         00457bae     MOV        this,dword ptr [EBX + 0xc]
    //         00457bb1     INC        EAX
    //         00457bb2     CMP        EAX,this
    //         00457bb4     MOV        dword ptr [ESP + h],EAX
    //         00457bb8     JL         LAB_00457aac
    //                              map.cpp:1564 (2)
    //         00457bbe     JMP        LAB_00457c22
    //                               LAB_00457bc0                                                 XREF[1]:     00457a95(j)  
    //                              map.cpp:1566 (24)
    //         00457bc0     MOV        EAX,dword ptr [EBX + 0x8]
    //         00457bc3     IMUL       EAX,dword ptr [EBX + 0xc]
    //         00457bc7     LEA        EDX,[EAX + EAX*0x2]
    //         00457bca     MOV        EAX,dword ptr [EBX + 0x4]
    //         00457bcd     SHL        EDX,0x3
    //         00457bd0     PUSH       EDX
    //         00457bd1     PUSH       EAX
    //         00457bd2     PUSH       EDI
    //         00457bd3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              map.cpp:1568 (16)
    //         00457bd8     MOV        this,dword ptr [EBX + 0xc]
    //         00457bdb     ADD        ESP,0xc
    //         00457bde     XOR        EAX,EAX
    //         00457be0     CMP        this,EBP
    //         00457be2     MOV        dword ptr [ESP + h],EAX
    //         00457be6     JLE        LAB_00457c22
    //                               LAB_00457be8                                                 XREF[1]:     00457c20(j)  
    //                              map.cpp:1569 (18)
    //         00457be8     MOV        EDX,dword ptr [EBX + 0x8]
    //         00457beb     XOR        this,this
    //         00457bed     CMP        EDX,EBP
    //         00457bef     JLE        LAB_00457c16
    //         00457bf1     LEA        EDX,[EAX*0x4 + 0x0]
    //         00457bf8     XOR        EAX,EAX
    //                               LAB_00457bfa                                                 XREF[1]:     00457c10(j)  
    //                              map.cpp:1571 (24)
    //         00457bfa     MOV        ESI,dword ptr [EBX + 0x8d8c]
    //         00457c00     INC        this
    //         00457c01     ADD        EAX,0x18
    //         00457c04     MOV        ESI,dword ptr [EDX + ESI*0x1]
    //         00457c07     MOV        dword ptr [ESI + EAX*0x1 + -0x8],EBP
    //         00457c0b     MOV        ESI,dword ptr [EBX + 0x8]
    //         00457c0e     CMP        this,ESI
    //         00457c10     JL         LAB_00457bfa
    //                              map.cpp:1569 (4)
    //         00457c12     MOV        EAX,dword ptr [ESP + h]
    //                               LAB_00457c16                                                 XREF[1]:     00457bef(j)  
    //                              map.cpp:1568 (12)
    //         00457c16     MOV        this,dword ptr [EBX + 0xc]
    //         00457c19     INC        EAX
    //         00457c1a     CMP        EAX,this
    //         00457c1c     MOV        dword ptr [ESP + h],EAX
    //         00457c20     JL         LAB_00457be8
    //                               LAB_00457c22                                                 XREF[3]:     00457aa6(j), 00457bbe(j), 
    //                                                                                                         00457be6(j)  
    //                              map.cpp:1576 (12)
    //         00457c22     MOV        this,dword ptr [EBX + 0x8dc8]
    //         00457c28     PUSH       EDI
    //         00457c29     CALL       RGE_Unified_Visible_Map::load                    void load(RGE_Unified_Visible_Map * this, int
    //                              map.cpp:1580 (21)
    //         00457c2e     MOV        this,dword ptr [ESP + local_c]
    //         00457c32     POP        EDI
    //         00457c33     POP        ESI
    //         00457c34     POP        EBP
    //         00457c35     MOV        dword ptr FS:[0x0],this
    //         00457c3c     POP        EBX
    //         00457c3d     ADD        ESP,0x1c
    //         00457c40     RET        0x4
}

// Offset: 0x00457C50
void save_map(RGE_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::save_map(int)                                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall save_map(RGE_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[9]:     00457c59(R), 00457d24(*), 00457d2e(W), 00457d3d(*), 
    //                                                                                     00457d48(W), 00457d57(*), 00457d62(W), 00457d71(*), 
    //                                                                                     00457d7c(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00457c77(W), 00457da0(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00457c64(W), 00457d9c(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00457cd4(W), 00457d98(R), 00457da5(W)  
    //              int               Stack[-0x10]:4 y                         XREF[3]:     00457c68(W), 00457ce4(R), 00457d85(R)  
    //                               ?save_map@RGE_Map@@QAEXH@Z                                   XREF[1]:     save:0054369c(c)  
    //                               RGE_Map::save_map
    //                              map.cpp:1585 (9)
    //         00457c50     SUB        ESP,0x10
    //         00457c53     PUSH       EBX
    //         00457c54     MOV        EBX,this
    //         00457c56     PUSH       EBP
    //         00457c57     PUSH       ESI
    //         00457c58     PUSH       EDI
    //                              map.cpp:1590 (27)
    //         00457c59     MOV        EDI,dword ptr [ESP + param_1]
    //         00457c5d     LEA        EBP,[EBX + 0x8]
    //         00457c60     PUSH       0x4
    //         00457c62     PUSH       EBP
    //         00457c63     PUSH       EDI
    //         00457c64     MOV        dword ptr [ESP + local_8],EBX
    //         00457c68     MOV        dword ptr [ESP + y],EBP
    //         00457c6c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00457c71     ADD        ESP,0xc
    //                              map.cpp:1591 (16)
    //         00457c74     LEA        ESI,[EBX + 0xc]
    //         00457c77     MOV        dword ptr [ESP + local_4],ESI
    //         00457c7b     PUSH       0x4
    //         00457c7d     PUSH       ESI
    //         00457c7e     PUSH       EDI
    //         00457c7f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1592 (15)
    //         00457c84     MOV        this,dword ptr [EBX + 0x8dc4]
    //         00457c8a     ADD        ESP,0xc
    //         00457c8d     PUSH       EDI
    //         00457c8e     CALL       RGE_Zone_Map_List::save                          void save(RGE_Zone_Map_List * this, int param
    //                              map.cpp:1593 (18)
    //         00457c93     LEA        EAX,[EBX + 0x8db8]
    //         00457c99     PUSH       0x1
    //         00457c9b     PUSH       EAX
    //         00457c9c     PUSH       EDI
    //         00457c9d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00457ca2     ADD        ESP,0xc
    //                              map.cpp:1594 (15)
    //         00457ca5     LEA        this,[EBX + 0x8db9]
    //         00457cab     PUSH       0x1
    //         00457cad     PUSH       this
    //         00457cae     PUSH       EDI
    //         00457caf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1596 (26)
    //         00457cb4     FLD        float ptr [save_game_version]                    = 7.23
    //         00457cba     FCOMP      float ptr [DAT_005706a8]                         = align(2)
    //         00457cc0     ADD        ESP,0xc
    //         00457cc3     FNSTSW     AX
    //         00457cc5     TEST       AH,0x1
    //         00457cc8     JNZ        LAB_00457db3
    //                              map.cpp:1598 (16)
    //         00457cce     MOV        this,dword ptr [ESI]
    //         00457cd0     XOR        EAX,EAX
    //         00457cd2     TEST       this,this
    //         00457cd4     MOV        dword ptr [ESP + local_c],EAX
    //         00457cd8     JLE        LAB_00457dcd
    //                               LAB_00457cde                                                 XREF[1]:     00457dab(j)  
    //                              map.cpp:1600 (6)
    //         00457cde     MOV        EDX,dword ptr [EBX + 0x8d8c]
    //                              map.cpp:1601 (19)
    //         00457ce4     MOV        this,dword ptr [ESP + y]
    //         00457ce8     XOR        EBP,EBP
    //         00457cea     MOV        ESI,dword ptr [EDX + EAX*0x4]
    //         00457ced     MOV        EDX,dword ptr [this->_padding_]
    //         00457cef     TEST       EDX,EDX
    //         00457cf1     JLE        LAB_00457da0
    //                               LAB_00457cf7                                                 XREF[1]:     00457d92(j)  
    //                              map.cpp:1603 (18)
    //         00457cf7     PUSH       0x2
    //         00457cf9     PUSH       ESI
    //         00457cfa     PUSH       EDI
    //         00457cfb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00457d00     LEA        EBX,[ESI + 0x4]
    //         00457d03     ADD        ESP,0xc
    //         00457d06     LEA        EDX,[EBX + -0x2]
    //                              map.cpp:1604 (12)
    //         00457d09     PUSH       0x2
    //         00457d0b     PUSH       EDX
    //         00457d0c     PUSH       EDI
    //         00457d0d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00457d12     ADD        ESP,0xc
    //                              map.cpp:1605 (9)
    //         00457d15     PUSH       0x1
    //         00457d17     PUSH       EBX
    //         00457d18     PUSH       EDI
    //         00457d19     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1606 (25)
    //         00457d1e     MOV        AL,byte ptr [ESI + 0x5]
    //         00457d21     ADD        ESP,0xc
    //         00457d24     LEA        this=>param_1,[ESP + 0x24]
    //         00457d28     AND        AL,0x1f
    //         00457d2a     PUSH       0x1
    //         00457d2c     PUSH       this
    //         00457d2d     PUSH       EDI
    //         00457d2e     MOV        byte ptr [ESP + param_1],AL
    //         00457d32     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1607 (26)
    //         00457d37     MOV        DL,byte ptr [ESI + 0x5]
    //         00457d3a     ADD        ESP,0xc
    //         00457d3d     LEA        EAX=>param_1,[ESP + 0x24]
    //         00457d41     PUSH       0x1
    //         00457d43     PUSH       EAX
    //         00457d44     SHR        DL,0x5
    //         00457d47     PUSH       EDI
    //         00457d48     MOV        byte ptr [ESP + param_1],DL
    //         00457d4c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1608 (26)
    //         00457d51     MOV        this,byte ptr [ESI + 0x6]
    //         00457d54     ADD        ESP,0xc
    //         00457d57     LEA        EDX=>param_1,[ESP + 0x24]
    //         00457d5b     AND        this,0xf
    //         00457d5e     PUSH       0x1
    //         00457d60     PUSH       EDX
    //         00457d61     PUSH       EDI
    //         00457d62     MOV        byte ptr [ESP + param_1],this
    //         00457d66     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1609 (33)
    //         00457d6b     MOV        AL,byte ptr [ESI + 0x6]
    //         00457d6e     ADD        ESP,0xc
    //         00457d71     LEA        this=>param_1,[ESP + 0x24]
    //         00457d75     PUSH       0x1
    //         00457d77     PUSH       this
    //         00457d78     SHR        AL,0x4
    //         00457d7b     PUSH       EDI
    //         00457d7c     MOV        byte ptr [ESP + param_1],AL
    //         00457d80     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00457d85     MOV        EDX,dword ptr [ESP + y]
    //         00457d89     ADD        ESP,0xc
    //                              map.cpp:1610 (37)
    //         00457d8c     ADD        ESI,0x18
    //         00457d8f     INC        EBP
    //         00457d90     CMP        EBP,dword ptr [EDX]
    //         00457d92     JL         LAB_00457cf7
    //         00457d98     MOV        EAX,dword ptr [ESP + local_c]
    //         00457d9c     MOV        EBX,dword ptr [ESP + local_8]
    //                               LAB_00457da0                                                 XREF[1]:     00457cf1(j)  
    //         00457da0     MOV        this,dword ptr [ESP + local_4]
    //         00457da4     INC        EAX
    //         00457da5     MOV        dword ptr [ESP + local_c],EAX
    //         00457da9     CMP        EAX,dword ptr [this->_padding_]
    //         00457dab     JL         LAB_00457cde
    //                              map.cpp:1614 (2)
    //         00457db1     JMP        LAB_00457dcd
    //                               LAB_00457db3                                                 XREF[1]:     00457cc8(j)  
    //                              map.cpp:1616 (26)
    //         00457db3     MOV        EAX,dword ptr [ESI]
    //         00457db5     IMUL       EAX,dword ptr [EBP]
    //         00457db9     LEA        EDX,[EAX + EAX*0x2]
    //         00457dbc     MOV        EAX,dword ptr [EBX + 0x4]
    //         00457dbf     SHL        EDX,0x3
    //         00457dc2     PUSH       EDX
    //         00457dc3     PUSH       EAX
    //         00457dc4     PUSH       EDI
    //         00457dc5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00457dca     ADD        ESP,0xc
    //                               LAB_00457dcd                                                 XREF[2]:     00457cd8(j), 00457db1(j)  
    //                              map.cpp:1621 (12)
    //         00457dcd     MOV        this,dword ptr [EBX + 0x8dc8]
    //         00457dd3     PUSH       EDI
    //         00457dd4     CALL       RGE_Unified_Visible_Map::save                    void save(RGE_Unified_Visible_Map * this, int
    //                              map.cpp:1622 (10)
    //         00457dd9     POP        EDI
    //         00457dda     POP        ESI
    //         00457ddb     POP        EBP
    //         00457ddc     POP        EBX
    //         00457ddd     ADD        ESP,0x10
    //         00457de0     RET        0x4
}

// Offset: 0x00457DF0
void RGE_Map::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Map::save(int)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00457e75(R)  
    //                               ?save@RGE_Map@@UAEXH@Z                                       XREF[2]:     save:0050f7b5(c), 005706a4(*)  
    //                               RGE_Map::save
    //                              map.cpp:1627 (4)
    //         00457df0     PUSH       EBX
    //         00457df1     PUSH       EBP
    //         00457df2     PUSH       ESI
    //         00457df3     PUSH       EDI
    //                              map.cpp:1631 (16)
    //         00457df4     PUSH       0x8dd0
    //         00457df9     MOV        EBX,this
    //         00457dfb     PUSH       0x1
    //         00457dfd     CALL       calloc                                           undefined calloc()
    //         00457e02     MOV        EBP,EAX
    //                              map.cpp:1632 (11)
    //         00457e04     MOV        this,0x2374
    //         00457e09     MOV        ESI,EBX
    //         00457e0b     MOV        EDI,EBP
    //         00457e0d     MOVSD.REP  ES:EDI,ESI
    //                              map.cpp:1640 (47)
    //         00457e0f     MOV        EDX,EBP
    //         00457e11     ADD        ESP,0x8
    //         00457e14     LEA        EAX,[EBX + 0xb0]
    //         00457e1a     SUB        EDX,EBX
    //         00457e1c     MOV        ESI,0x20
    //                               LAB_00457e21                                                 XREF[1]:     00457e44(j)  
    //         00457e21     MOV        this,byte ptr [EAX + -0x24]
    //         00457e24     TEST       this,this
    //         00457e26     JZ         LAB_00457e3e
    //         00457e28     MOV        this,dword ptr [EAX]
    //         00457e2a     TEST       this,this
    //         00457e2c     JZ         LAB_00457e37
    //         00457e2e     MOVSX      this,word ptr [ECX + this->map_height]
    //         00457e32     MOV        dword ptr [EDX + EAX*0x1],this
    //         00457e35     JMP        LAB_00457e3e
    //                               LAB_00457e37                                                 XREF[1]:     00457e2c(j)  
    //         00457e37     MOV        dword ptr [EDX + EAX*0x1],0xffffffff
    //                               LAB_00457e3e                                                 XREF[2]:     00457e26(j), 00457e35(j)  
    //                              map.cpp:1635 (8)
    //         00457e3e     ADD        EAX,0x198
    //         00457e43     DEC        ESI
    //         00457e44     JNZ        LAB_00457e21
    //                              map.cpp:1654 (17)
    //         00457e46     LEA        EAX,[EBX + 0x33b0]
    //         00457e4c     MOV        ESI,0x10
    //                               LAB_00457e51                                                 XREF[1]:     00457e73(j)  
    //         00457e51     MOV        this,dword ptr [EAX]
    //         00457e53     TEST       this,this
    //         00457e55     JZ         LAB_00457e66
    //                              map.cpp:1644 (6)
    //         00457e57     CMP        byte ptr [EAX + -0x24],0x0
    //         00457e5b     JZ         LAB_00457e66
    //                              map.cpp:1645 (7)
    //         00457e5d     MOVSX      this,word ptr [ECX + this->map_height]
    //         00457e61     MOV        dword ptr [EAX + EDX*0x1],this
    //                              map.cpp:1646 (2)
    //         00457e64     JMP        LAB_00457e6d
    //                               LAB_00457e66                                                 XREF[2]:     00457e55(j), 00457e5b(j)  
    //                              map.cpp:1647 (7)
    //         00457e66     MOV        dword ptr [EAX + EDX*0x1],0xffffffff
    //                               LAB_00457e6d                                                 XREF[1]:     00457e64(j)  
    //                              map.cpp:1643 (8)
    //         00457e6d     ADD        EAX,0x5a0
    //         00457e72     DEC        ESI
    //         00457e73     JNZ        LAB_00457e51
    //                              map.cpp:1649 (16)
    //         00457e75     MOV        ESI,dword ptr [ESP + param_1]
    //         00457e79     PUSH       0x8dd0
    //         00457e7e     PUSH       EBP
    //         00457e7f     PUSH       ESI
    //         00457e80     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              map.cpp:1650 (15)
    //         00457e85     MOV        this,dword ptr [EBX + 0x8dbc]
    //         00457e8b     ADD        ESP,0xc
    //         00457e8e     PUSH       ESI
    //         00457e8f     CALL       RGE_RMM_Database_Controller::save                uchar save(RGE_RMM_Database_Controller * this
    //                              map.cpp:1653 (9)
    //         00457e94     PUSH       EBP
    //         00457e95     CALL       free                                             undefined free()
    //         00457e9a     ADD        ESP,0x4
    //                              map.cpp:1654 (7)
    //         00457e9d     POP        EDI
    //         00457e9e     POP        ESI
    //         00457e9f     POP        EBP
    //         00457ea0     POP        EBX
    //         00457ea1     RET        0x4
}

// Offset: 0x00457EB0
void load_terrain_types(RGE_Map* this_, RGE_Sound** param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::load_terrain_types(class RGE_Sound * *)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall load_terrain_types(RGE_Map * this, RGE_Sound * * par
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Sound * *     Stack[0x4]:4   param_1                   XREF[2]:     00457ecc(R), 00457f04(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00457f0a(W), 00457f25(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00457f68(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     00457ed0(W), 00457eec(*), 00457f12(R), 00457f57(R)  
    //              char *            Stack[-0x14]:4 filename2
    //                               ?load_terrain_types@RGE_Map@@QAEXPAPAVRGE_Sound@@@Z          XREF[1]:     RGE_Map:00455054(c)  
    //                               RGE_Map::load_terrain_types
    //                              map.cpp:1659 (25)
    //         00457eb0     PUSH       -0x1
    //         00457eb2     PUSH       FUN_0055db2b
    //         00457eb7     MOV        EAX,FS:[0x0]
    //         00457ebd     PUSH       EAX
    //         00457ebe     MOV        dword ptr FS:[0x0],ESP
    //         00457ec5     PUSH       this
    //         00457ec6     PUSH       EBX
    //         00457ec7     PUSH       EBP
    //         00457ec8     PUSH       ESI
    //                              map.cpp:1660 (22)
    //         00457ec9     XOR        EBX,EBX
    //         00457ecb     PUSH       EDI
    //         00457ecc     MOV        EDI,dword ptr [ESP + param_1]
    //         00457ed0     MOV        dword ptr [ESP + local_10],EBX
    //         00457ed4     LEA        ESI,[ECX + this+0x3210]
    //         00457eda     MOV        EBP,0x20
    //                               LAB_00457edf                                                 XREF[1]:     00457f55(j)  
    //                              map.cpp:1664 (5)
    //         00457edf     CMP        byte ptr [ESI + -0x1c],BL
    //         00457ee2     JZ         LAB_00457f4e
    //                              map.cpp:1669 (61)
    //         00457ee4     LEA        EAX,[ESI + -0xd]
    //         00457ee7     PUSH       s_.shp                                           = ".shp"
    //         00457eec     LEA        this=>local_10,[ESP + 0x14]
    //         00457ef0     PUSH       EAX
    //         00457ef1     PUSH       this
    //         00457ef2     CALL       addstring                                        void addstring(char * * param_1, char * param
    //         00457ef7     ADD        ESP,0xc
    //         00457efa     PUSH       0x20
    //         00457efc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00457f01     ADD        ESP,0x4
    //         00457f04     MOV        dword ptr [ESP + param_1],EAX
    //         00457f08     CMP        EAX,EBX
    //         00457f0a     MOV        dword ptr [ESP + local_4],EBX
    //         00457f0e     JZ         LAB_00457f21
    //         00457f10     MOV        EDX,dword ptr [ESI]
    //         00457f12     MOV        this,dword ptr [ESP + local_10]
    //         00457f16     PUSH       EDX
    //         00457f17     PUSH       this
    //         00457f18     MOV        this,EAX
    //         00457f1a     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00457f1f     JMP        LAB_00457f23
    //                               LAB_00457f21                                                 XREF[1]:     00457f0e(j)  
    //                              map.cpp:1667 (2)
    //         00457f21     XOR        EAX,EAX
    //                               LAB_00457f23                                                 XREF[1]:     00457f1f(j)  
    //                              map.cpp:1668 (22)
    //         00457f23     MOV        this,EAX
    //         00457f25     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00457f2d     MOV        dword ptr [ESI + 0x4],EAX
    //         00457f30     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         00457f35     TEST       EAX,EAX
    //         00457f37     JNZ        LAB_00457f3c
    //                              map.cpp:1669 (3)
    //         00457f39     MOV        byte ptr [ESI + -0x1c],BL
    //                               LAB_00457f3c                                                 XREF[1]:     00457f37(j)  
    //                              map.cpp:1671 (7)
    //         00457f3c     MOV        EAX,dword ptr [ESI + 0x8]
    //         00457f3f     CMP        EAX,EBX
    //         00457f41     JL         LAB_00457f4b
    //                              map.cpp:1672 (6)
    //         00457f43     MOV        EDX,dword ptr [EDI + EAX*0x4]
    //         00457f46     MOV        dword ptr [ESI + 0x8],EDX
    //                              map.cpp:1673 (2)
    //         00457f49     JMP        LAB_00457f4e
    //                               LAB_00457f4b                                                 XREF[1]:     00457f41(j)  
    //                              map.cpp:1674 (3)
    //         00457f4b     MOV        dword ptr [ESI + 0x8],EBX
    //                               LAB_00457f4e                                                 XREF[2]:     00457ee2(j), 00457f49(j)  
    //                              map.cpp:1663 (9)
    //         00457f4e     SUB        ESI,0x198
    //         00457f54     DEC        EBP
    //         00457f55     JNZ        LAB_00457edf
    //                              map.cpp:1677 (17)
    //         00457f57     MOV        EAX,dword ptr [ESP + local_10]
    //         00457f5b     CMP        EAX,EBX
    //         00457f5d     JZ         LAB_00457f68
    //         00457f5f     PUSH       EAX
    //         00457f60     CALL       free                                             undefined free()
    //         00457f65     ADD        ESP,0x4
    //                               LAB_00457f68                                                 XREF[1]:     00457f5d(j)  
    //                              map.cpp:1678 (21)
    //         00457f68     MOV        this,dword ptr [ESP + local_c]
    //         00457f6c     POP        EDI
    //         00457f6d     POP        ESI
    //         00457f6e     POP        EBP
    //         00457f6f     MOV        dword ptr FS:[0x0],this
    //         00457f76     POP        EBX
    //         00457f77     ADD        ESP,0x10
    //         00457f7a     RET        0x4
}

// Offset: 0x00457F80
void load_terrain_types(RGE_Map* this_, char* param_2, RGE_Sound** param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::load_terrain_types(char *,class RGE_Sound * *)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall load_terrain_types(RGE_Map * this, char * param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[5]:     00457fa3(R), 0045805a(*), 0045807c(R), 004580f8(*), 
    //                                                                                     00458109(R)  
    //              RGE_Sound * *     Stack[0x8]:4   param_2                   XREF[1]:     00458133(R)  
    //              char[13]          Stack[-0x14]   pict_name                 XREF[0,2]:   0045804a(*), 004581ab(*)  
    //              char[13]          Stack[-0x24]   name                      XREF[2,3]:   00457f89(W), 00458254(R), 00458052(*), 00458172(*), 
    //                                                                                     0045817f(*)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[2]:     00458042(*), 004581ca(R)  
    //              long              Stack[-0x2c]:4 resource_id               XREF[3]:     00457fea(W), 00458258(R), 0045825d(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[3]:     00458015(*), 00458215(R), 00458231(R)  
    //              float             Stack[-0x34]:4 pause_between_loops       XREF[3]:     00458099(W), 004580d4(R), 004580df(W)  
    //              undefined4        Stack[-0x38]:4 local_38                  XREF[4]:     00457fb9(W), 004580b3(R), 004580f0(R), 0045822a(R)  
    //              _iobuf *          Stack[-0x3c]:4 infile                    XREF[4]:     0045801a(*), 00458200(R), 00458219(R), 00458226(R)  
    //              float             Stack[-0x40]:4 interval                  XREF[2,1]:   00458010(*), 00458248(R), 0045803d(*)  
    //              short             Stack[-0x42]:2 random                    XREF[2]:     0045801f(*), 004581f7(R)  
    //              short             Stack[-0x44]:2 terrain_to_draw           XREF[2]:     00458024(*), 004581f0(R)  
    //              short             Stack[-0x46]:2 animation_frames          XREF[2]:     00458006(*), 004581e4(R)  
    //              short             Stack[-0x48]:2 is_animated               XREF[2]:     0045800b(*), 004581d8(R)  
    //              short             Stack[-0x4a]:2 col                       XREF[2]:     00457ff2(*), 0045816e(R)  
    //              short             Stack[-0x4c]:2 row                       XREF[2]:     00457ff7(*), 00458167(R)  
    //              short             Stack[-0x4e]:2 passable_terrain          XREF[2]:     00457ffc(*), 00458160(R)  
    //              short             Stack[-0x50]:2 impassable_terrain        XREF[2]:     00458001(*), 00458159(R)  
    //              short             Stack[-0x52]:2 rt_cliff_color            XREF[2]:     00458033(*), 00458152(R)  
    //              short             Stack[-0x54]:2 lt_cliff_color            XREF[2]:     00458038(*), 0045814b(R)  
    //              short             Stack[-0x56]:2 hi_color                  XREF[2]:     0045802e(*), 00458144(R)  
    //              short             Stack[-0x58]:2 med_color                 XREF[2]:     00458029(*), 00458129(R)  
    //              short             Stack[-0x5a]:2 low_color                 XREF[2]:     004580f4(*), 00458111(R)  
    //              short             Stack[-0x5c]:2 sound_id                  XREF[3]:     00457fee(*), 004580e9(R), 00458122(R)  
    //              short             Stack[-0x5e]:2 border
    //              short             Stack[-0x60]:2 border_num
    //                               ?load_terrain_types@RGE_Map@@QAEXPADPAPAVRGE_Sound@@@Z       XREF[1]:     RGE_Map:004553ea(c)  
    //                               RGE_Map::load_terrain_types
    //                              map.cpp:1683 (13)
    //         00457f80     SUB        ESP,0x5c
    //         00457f83     PUSH       EBX
    //         00457f84     PUSH       EBP
    //         00457f85     MOV        EBP,this
    //         00457f87     PUSH       ESI
    //         00457f88     PUSH       EDI
    //         00457f89     MOV        dword ptr [ESP + name[0]],EBP
    //                              map.cpp:1713 (11)
    //         00457f8d     LEA        EAX,[EBP + 0x31f4]
    //         00457f93     MOV        this,0x20
    //                               LAB_00457f98                                                 XREF[1]:     00457fa1(j)  
    //                              map.cpp:1714 (11)
    //         00457f98     MOV        byte ptr [EAX],0x0
    //         00457f9b     SUB        EAX,0x198
    //         00457fa0     DEC        this
    //         00457fa1     JNZ        LAB_00457f98
    //                              map.cpp:1717 (20)
    //         00457fa3     MOV        EAX,dword ptr [ESP + param_1]
    //         00457fa7     PUSH       s_r                                              = "r"
    //         00457fac     PUSH       EAX
    //         00457fad     CALL       fopen                                            undefined fopen()
    //         00457fb2     MOV        EDI,EAX
    //         00457fb4     ADD        ESP,0x8
    //                              map.cpp:1718 (12)
    //         00457fb7     TEST       EDI,EDI
    //         00457fb9     MOV        dword ptr [ESP + local_38],EDI
    //         00457fbd     JZ         LAB_00458267
    //                              map.cpp:1720 (18)
    //         00457fc3     LEA        ESI,[EBP + 0x8d90]
    //         00457fc9     PUSH       ESI
    //         00457fca     PUSH       s_%hd                                            = "%hd"
    //         00457fcf     PUSH       EDI
    //         00457fd0     CALL       fscanf                                           undefined fscanf()
    //                              map.cpp:1721 (17)
    //         00457fd5     MOV        AX,word ptr [ESI]
    //         00457fd8     ADD        ESP,0xc
    //         00457fdb     DEC        AX
    //         00457fdd     TEST       AX,AX
    //         00457fe0     JL         LAB_00458267
    //                              map.cpp:1796 (165)
    //         00457fe6     MOVSX      EAX,AX
    //         00457fe9     INC        EAX
    //         00457fea     MOV        dword ptr [ESP + resource_id],EAX
    //                               LAB_00457fee                                                 XREF[1]:     00458261(j)  
    //         00457fee     LEA        this=>sound_id,[ESP + 0x10]
    //         00457ff2     LEA        EDX=>col,[ESP + 0x22]
    //         00457ff6     PUSH       this
    //         00457ff7     LEA        EAX=>row,[ESP + 0x24]
    //         00457ffb     PUSH       EDX
    //         00457ffc     LEA        this=>passable_terrain,[ESP + 0x26]
    //         00458000     PUSH       EAX
    //         00458001     LEA        EDX=>impassable_terrain,[ESP + 0x28]
    //         00458005     PUSH       this
    //         00458006     LEA        EAX=>animation_frames,[ESP + 0x36]
    //         0045800a     PUSH       EDX
    //         0045800b     LEA        this=>is_animated,[ESP + 0x38]
    //         0045800f     PUSH       EAX
    //         00458010     LEA        EDX=>interval,[ESP + 0x44]
    //         00458014     PUSH       this
    //         00458015     LEA        EAX=>local_30,[ESP + 0x58]
    //         00458019     PUSH       EDX
    //         0045801a     LEA        this=>infile,[ESP + 0x50]
    //         0045801e     PUSH       EAX
    //         0045801f     LEA        EDX=>random,[ESP + 0x4e]
    //         00458023     PUSH       this
    //         00458024     LEA        EAX=>terrain_to_draw,[ESP + 0x50]
    //         00458028     PUSH       EDX
    //         00458029     LEA        this=>med_color,[ESP + 0x40]
    //         0045802d     PUSH       EAX
    //         0045802e     LEA        EDX=>hi_color,[ESP + 0x46]
    //         00458032     PUSH       this
    //         00458033     LEA        EAX=>rt_cliff_color,[ESP + 0x4e]
    //         00458037     PUSH       EDX
    //         00458038     LEA        this=>lt_cliff_color,[ESP + 0x50]
    //         0045803c     PUSH       EAX
    //         0045803d     LEA        EDX=>interval+0x2,[ESP + 0x6a]
    //         00458041     PUSH       this
    //         00458042     LEA        EAX=>local_28,[ESP + 0x84]
    //         00458049     PUSH       EDX
    //         0045804a     LEA        this=>pict_name[4],[ESP + 0xa0]
    //         00458051     PUSH       EAX
    //         00458052     LEA        EDX=>name[4],[ESP + 0x94]
    //         00458059     PUSH       this
    //         0045805a     LEA        EAX=>param_1,[ESP + 0xbc]
    //         00458061     PUSH       EDX
    //         00458062     PUSH       EAX
    //         00458063     PUSH       s_%hd_%s_%s_%d_%hd_%hd_%hd_%hd_%hd               = "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %
    //         00458068     PUSH       EDI
    //         00458069     XOR        EBX,EBX
    //         0045806b     CALL       fscanf                                           undefined fscanf()
    //         00458070     ADD        ESP,0x5c
    //         00458073     CMP        EAX,-0x1
    //         00458076     JZ         LAB_00458258
    //         0045807c     MOV        AX,word ptr [ESP + param_1]
    //         00458081     CMP        AX,0x20
    //         00458085     JGE        LAB_00458258
    //                              map.cpp:1746 (9)
    //         0045808b     TEST       AX,AX
    //         0045808e     JL         LAB_00458258
    //                              map.cpp:1749 (5)
    //         00458094     MOVSX      this,AX
    //         00458097     MOV        EAX,this
    //                              map.cpp:1796 (87)
    //         00458099     MOV        dword ptr [ESP + pause_between_loops],0x13
    //         004580a1     SHL        EAX,0x4
    //         004580a4     ADD        EAX,this
    //         004580a6     LEA        this,[EAX + EAX*0x2]
    //         004580a9     LEA        EBP,[EBP + this->_padding_*0x8 + 0x8c]
    //         004580b0     LEA        ESI,[EBP + 0x46]
    //                               LAB_004580b3                                                 XREF[1]:     004580e3(j)  
    //         004580b3     MOV        EDX,dword ptr [ESP + local_38]
    //         004580b7     LEA        EDI,[ESI + 0x2]
    //         004580ba     PUSH       EDI
    //         004580bb     PUSH       ESI
    //         004580bc     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         004580c1     PUSH       EDX
    //         004580c2     CALL       fscanf                                           undefined fscanf()
    //         004580c7     MOV        word ptr [ESI + 0x4],BX
    //         004580cb     MOV        AX,word ptr [ESI]
    //         004580ce     IMUL       AX,word ptr [EDI]
    //         004580d2     ADD        EBX,EAX
    //         004580d4     MOV        EAX,dword ptr [ESP + pause_between_loops]
    //         004580d8     ADD        ESP,0x10
    //         004580db     ADD        ESI,0x6
    //         004580de     DEC        EAX
    //         004580df     MOV        dword ptr [ESP + pause_between_loops],EAX
    //         004580e3     JNZ        LAB_004580b3
    //         004580e5     XOR        EBX,EBX
    //         004580e7     XOR        ESI,ESI
    //         004580e9     CMP        word ptr [ESP + sound_id],BX
    //         004580ee     JLE        LAB_00458129
    //                               LAB_004580f0                                                 XREF[1]:     00458127(j)  
    //                              map.cpp:1759 (25)
    //         004580f0     MOV        EAX,dword ptr [ESP + local_38]
    //         004580f4     LEA        this=>low_color,[ESP + 0x12]
    //         004580f8     LEA        EDX=>param_1,[ESP + 0x70]
    //         004580fc     PUSH       this
    //         004580fd     PUSH       EDX
    //         004580fe     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00458103     PUSH       EAX
    //         00458104     CALL       fscanf                                           undefined fscanf()
    //                              map.cpp:1760 (32)
    //         00458109     MOVSX      this,word ptr [ESP + param_1]
    //         00458111     MOV        DX,word ptr [ESP + low_color]
    //         00458116     ADD        ESP,0x10
    //         00458119     INC        ESI
    //         0045811a     MOV        word ptr [EBP + this->_padding_*0x2 + 0xbe],DX
    //         00458122     CMP        SI,word ptr [ESP + sound_id]
    //         00458127     JL         LAB_004580f0
    //                               LAB_00458129                                                 XREF[1]:     004580ee(j)  
    //                              map.cpp:1764 (27)
    //         00458129     MOV        AX,word ptr [ESP + med_color]
    //         0045812e     CMP        AX,BX
    //         00458131     JL         LAB_0045813f
    //         00458133     MOV        this,dword ptr [ESP + param_2]
    //         00458137     MOVSX      EAX,AX
    //         0045813a     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         0045813d     JMP        LAB_00458141
    //                               LAB_0045813f                                                 XREF[1]:     00458131(j)  
    //         0045813f     XOR        EAX,EAX
    //                               LAB_00458141                                                 XREF[1]:     0045813d(j)  
    //         00458141     MOV        dword ptr [EBP + 0x24],EAX
    //                              map.cpp:1765 (7)
    //         00458144     MOV        DL,byte ptr [ESP + hi_color]
    //         00458148     MOV        byte ptr [EBP + 0x2a],DL
    //                              map.cpp:1766 (7)
    //         0045814b     MOV        AL,byte ptr [ESP + lt_cliff_color]
    //         0045814f     MOV        byte ptr [EBP + 0x29],AL
    //                              map.cpp:1767 (7)
    //         00458152     MOV        this,byte ptr [ESP + rt_cliff_color]
    //         00458156     MOV        byte ptr [EBP + 0x28],this
    //                              map.cpp:1768 (7)
    //         00458159     MOV        DL,byte ptr [ESP + impassable_terrain]
    //         0045815d     MOV        byte ptr [EBP + 0x2b],DL
    //                              map.cpp:1769 (7)
    //         00458160     MOV        AL,byte ptr [ESP + passable_terrain]
    //         00458164     MOV        byte ptr [EBP + 0x2c],AL
    //                              map.cpp:1770 (7)
    //         00458167     MOV        this,byte ptr [ESP + row]
    //         0045816b     MOV        byte ptr [EBP + 0x2e],this
    //                              map.cpp:1771 (4)
    //         0045816e     MOV        DL,byte ptr [ESP + col]
    //                              map.cpp:1772 (13)
    //         00458172     LEA        EAX=>name[4],[ESP + 0x4c]
    //         00458176     MOV        byte ptr [EBP + 0x2d],DL
    //         00458179     PUSH       EAX
    //         0045817a     CALL       convert_us                                       void convert_us(char * param_1)
    //                              map.cpp:1773 (27)
    //         0045817f     LEA        EDI=>name[4],[ESP + 0x50]
    //         00458183     OR         this,0xffffffff
    //         00458186     XOR        EAX,EAX
    //         00458188     ADD        ESP,0x4
    //         0045818b     SCASB.RE   ES:EDI
    //         0045818d     NOT        this
    //         0045818f     SUB        EDI,this
    //         00458191     LEA        EDX,[EBP + 0x2]
    //         00458194     MOV        EAX,this
    //         00458196     MOV        ESI,EDI
    //         00458198     MOV        EDI,EDX
    //                              map.cpp:1774 (48)
    //         0045819a     LEA        EDX,[EBP + 0xf]
    //         0045819d     SHR        this,0x2
    //         004581a0     MOVSD.REP  ES:EDI,ESI
    //         004581a2     MOV        this,EAX
    //         004581a4     XOR        EAX,EAX
    //         004581a6     AND        this,0x3
    //         004581a9     MOVSB.REP  ES:EDI,ESI
    //         004581ab     LEA        EDI=>pict_name[4],[ESP + 0x5c]
    //         004581af     OR         this,0xffffffff
    //         004581b2     SCASB.RE   ES:EDI
    //         004581b4     NOT        this
    //         004581b6     SUB        EDI,this
    //         004581b8     MOV        EAX,this
    //         004581ba     MOV        ESI,EDI
    //         004581bc     MOV        EDI,EDX
    //         004581be     SHR        this,0x2
    //         004581c1     MOVSD.REP  ES:EDI,ESI
    //         004581c3     MOV        this,EAX
    //         004581c5     AND        this,0x3
    //         004581c8     MOVSB.REP  ES:EDI,ESI
    //                              map.cpp:1775 (4)
    //         004581ca     MOV        this,dword ptr [ESP + local_28]
    //                              map.cpp:1776 (6)
    //         004581ce     MOV        dword ptr [EBP + 0x40],EBX
    //         004581d1     MOV        dword ptr [EBP + 0x1c],this
    //                              map.cpp:1777 (4)
    //         004581d4     MOV        byte ptr [EBP],0x1
    //                              map.cpp:1778 (12)
    //         004581d8     MOV        DX,word ptr [ESP + is_animated]
    //         004581dd     MOV        word ptr [EBP + 0xba],DX
    //                              map.cpp:1779 (12)
    //         004581e4     MOV        AX,word ptr [ESP + animation_frames]
    //         004581e9     MOV        word ptr [EBP + 0xbc],AX
    //                              map.cpp:1780 (7)
    //         004581f0     MOV        this,byte ptr [ESP + terrain_to_draw]
    //         004581f4     MOV        byte ptr [EBP + 0x2f],this
    //                              map.cpp:1781 (9)
    //         004581f7     MOV        DX,word ptr [ESP + random]
    //         004581fc     MOV        word ptr [EBP + 0x30],DX
    //                              map.cpp:1782 (38)
    //         00458200     FLD        float ptr [ESP + infile]
    //         00458204     FCOMP      float ptr [DAT_005706ac]
    //         0045820a     FNSTSW     AX
    //         0045820c     TEST       AH,0x40
    //         0045820f     JZ         LAB_00458215
    //         00458211     XOR        EAX,EAX
    //         00458213     JMP        LAB_00458222
    //                               LAB_00458215                                                 XREF[1]:     0045820f(j)  
    //         00458215     FLD        float ptr [ESP + local_30]
    //         00458219     FDIV       float ptr [ESP + infile]
    //         0045821d     CALL       __ftol                                           undefined __ftol()
    //                               LAB_00458222                                                 XREF[1]:     00458213(j)  
    //         00458222     MOV        word ptr [EBP + 0x32],AX
    //                              map.cpp:1783 (4)
    //         00458226     MOV        EAX,dword ptr [ESP + infile]
    //                              map.cpp:1789 (61)
    //         0045822a     MOV        EDI,dword ptr [ESP + local_38]
    //         0045822e     MOV        dword ptr [EBP + 0x34],EAX
    //         00458231     MOV        this,dword ptr [ESP + local_30]
    //         00458235     MOV        word ptr [EBP + 0x3c],BX
    //         00458239     MOV        dword ptr [EBP + 0x38],this
    //         0045823c     MOV        word ptr [EBP + 0x3e],BX
    //         00458240     MOV        byte ptr [EBP + 0x44],0x0
    //         00458244     MOV        byte ptr [EBP + 0x45],0x0
    //         00458248     MOV        DX,word ptr [ESP + interval]
    //         0045824d     MOV        word ptr [EBP + 0xb8],DX
    //         00458254     MOV        EBP,dword ptr [ESP + name[0]]
    //                               LAB_00458258                                                 XREF[3]:     00458076(j), 00458085(j), 
    //                                                                                                         0045808e(j)  
    //         00458258     MOV        EAX,dword ptr [ESP + resource_id]
    //         0045825c     DEC        EAX
    //         0045825d     MOV        dword ptr [ESP + resource_id],EAX
    //         00458261     JNZ        LAB_00457fee
    //                               LAB_00458267                                                 XREF[2]:     00457fbd(j), 00457fe0(j)  
    //                              map.cpp:1795 (9)
    //         00458267     PUSH       EDI
    //         00458268     CALL       fclose                                           undefined fclose()
    //         0045826d     ADD        ESP,0x4
    //                              map.cpp:1796 (10)
    //         00458270     POP        EDI
    //         00458271     POP        ESI
    //         00458272     POP        EBP
    //         00458273     POP        EBX
    //         00458274     ADD        ESP,0x5c
    //         00458277     RET        0x8
}

// Offset: 0x00458280
void load_border_types(RGE_Map* this_, RGE_Sound** param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::load_border_types(class RGE_Sound * *)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall load_border_types(RGE_Map * this, RGE_Sound * * para
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Sound * *     Stack[0x4]:4   param_1                   XREF[2]:     0045829c(R), 004582d4(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004582da(W), 004582f5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00458338(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     004582a0(W), 004582bc(*), 004582e2(R), 00458327(R)  
    //              char *            Stack[-0x14]:4 filename2
    //                               ?load_border_types@RGE_Map@@QAEXPAPAVRGE_Sound@@@Z           XREF[1]:     RGE_Map:0045505c(c)  
    //                               RGE_Map::load_border_types
    //                              map.cpp:1802 (25)
    //         00458280     PUSH       -0x1
    //         00458282     PUSH       FUN_0055db4b
    //         00458287     MOV        EAX,FS:[0x0]
    //         0045828d     PUSH       EAX
    //         0045828e     MOV        dword ptr FS:[0x0],ESP
    //         00458295     PUSH       this
    //         00458296     PUSH       EBX
    //         00458297     PUSH       EBP
    //         00458298     PUSH       ESI
    //                              map.cpp:1803 (22)
    //         00458299     XOR        EBX,EBX
    //         0045829b     PUSH       EDI
    //         0045829c     MOV        EDI,dword ptr [ESP + param_1]
    //         004582a0     MOV        dword ptr [ESP + local_10],EBX
    //         004582a4     LEA        ESI,[ECX + this+0x8808]
    //         004582aa     MOV        EBP,0x10
    //                               LAB_004582af                                                 XREF[1]:     00458325(j)  
    //                              map.cpp:1808 (5)
    //         004582af     CMP        byte ptr [ESI + -0x1c],BL
    //         004582b2     JZ         LAB_0045831e
    //                              map.cpp:1813 (61)
    //         004582b4     LEA        EAX,[ESI + -0xd]
    //         004582b7     PUSH       s_.shp                                           = ".shp"
    //         004582bc     LEA        this=>local_10,[ESP + 0x14]
    //         004582c0     PUSH       EAX
    //         004582c1     PUSH       this
    //         004582c2     CALL       addstring                                        void addstring(char * * param_1, char * param
    //         004582c7     ADD        ESP,0xc
    //         004582ca     PUSH       0x20
    //         004582cc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004582d1     ADD        ESP,0x4
    //         004582d4     MOV        dword ptr [ESP + param_1],EAX
    //         004582d8     CMP        EAX,EBX
    //         004582da     MOV        dword ptr [ESP + local_4],EBX
    //         004582de     JZ         LAB_004582f1
    //         004582e0     MOV        EDX,dword ptr [ESI]
    //         004582e2     MOV        this,dword ptr [ESP + local_10]
    //         004582e6     PUSH       EDX
    //         004582e7     PUSH       this
    //         004582e8     MOV        this,EAX
    //         004582ea     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         004582ef     JMP        LAB_004582f3
    //                               LAB_004582f1                                                 XREF[1]:     004582de(j)  
    //                              map.cpp:1811 (2)
    //         004582f1     XOR        EAX,EAX
    //                               LAB_004582f3                                                 XREF[1]:     004582ef(j)  
    //                              map.cpp:1812 (22)
    //         004582f3     MOV        this,EAX
    //         004582f5     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004582fd     MOV        dword ptr [ESI + 0x4],EAX
    //         00458300     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         00458305     TEST       EAX,EAX
    //         00458307     JNZ        LAB_0045830c
    //                              map.cpp:1813 (3)
    //         00458309     MOV        byte ptr [ESI + -0x1c],BL
    //                               LAB_0045830c                                                 XREF[1]:     00458307(j)  
    //                              map.cpp:1815 (7)
    //         0045830c     MOV        EAX,dword ptr [ESI + 0x8]
    //         0045830f     CMP        EAX,EBX
    //         00458311     JL         LAB_0045831b
    //                              map.cpp:1816 (6)
    //         00458313     MOV        EDX,dword ptr [EDI + EAX*0x4]
    //         00458316     MOV        dword ptr [ESI + 0x8],EDX
    //                              map.cpp:1817 (2)
    //         00458319     JMP        LAB_0045831e
    //                               LAB_0045831b                                                 XREF[1]:     00458311(j)  
    //                              map.cpp:1818 (3)
    //         0045831b     MOV        dword ptr [ESI + 0x8],EBX
    //                               LAB_0045831e                                                 XREF[2]:     004582b2(j), 00458319(j)  
    //                              map.cpp:1807 (9)
    //         0045831e     SUB        ESI,0x5a0
    //         00458324     DEC        EBP
    //         00458325     JNZ        LAB_004582af
    //                              map.cpp:1821 (17)
    //         00458327     MOV        EAX,dword ptr [ESP + local_10]
    //         0045832b     CMP        EAX,EBX
    //         0045832d     JZ         LAB_00458338
    //         0045832f     PUSH       EAX
    //         00458330     CALL       free                                             undefined free()
    //         00458335     ADD        ESP,0x4
    //                               LAB_00458338                                                 XREF[1]:     0045832d(j)  
    //                              map.cpp:1822 (21)
    //         00458338     MOV        this,dword ptr [ESP + local_c]
    //         0045833c     POP        EDI
    //         0045833d     POP        ESI
    //         0045833e     POP        EBP
    //         0045833f     MOV        dword ptr FS:[0x0],this
    //         00458346     POP        EBX
    //         00458347     ADD        ESP,0x10
    //         0045834a     RET        0x4
}

// Offset: 0x00458350
void load_border_types(RGE_Map* this_, char* param_2, RGE_Sound** param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::load_border_types(char *,class RGE_Sound * *)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall load_border_types(RGE_Map * this, char * param_1, RG
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[3]:     00458373(R), 0045840b(*), 0045842d(R)  
    //              RGE_Sound * *     Stack[0x8]:4   param_2                   XREF[1]:     004584d1(R)  
    //              char[13]          Stack[-0x14]   pict_name                 XREF[0,2]:   004583fe(*), 0045852a(*)  
    //              char[13]          Stack[-0x24]   name                      XREF[2,3]:   00458359(W), 004585af(R), 00458406(*), 004584f1(*), 
    //                                                                                     004584fe(*)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[2]:     004583f9(*), 00458549(R)  
    //              long              Stack[-0x2c]:4 resource_id               XREF[3]:     004583ba(W), 004585d5(R), 004585da(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[3]:     00458389(W), 0045847a(R), 004585d1(R)  
    //              _iobuf *          Stack[-0x34]:4 infile                    XREF[3]:     004583cc(*), 00458579(R), 00458591(R)  
    //              float             Stack[-0x38]:4 pause_between_loops       XREF[3]:     00458448(W), 004584b0(R), 004584bc(W)  
    //              undefined4        Stack[-0x3c]:4 local_3c                  XREF[3]:     00458472(W), 0045848e(R), 004584a6(W)  
    //              undefined4        Stack[-0x40]:4 local_40                  XREF[4]:     004583d1(*), 00458564(R), 0045857d(R), 0045858a(R)  
    //              float             Stack[-0x44]:4 interval                  XREF[4]:     00458463(W), 00458469(R), 004584ac(R), 004584b8(W)  
    //              undefined         Stack[-0x46]:1 local_46                  XREF[1]:     004583f4(*)  
    //              undefined2        Stack[-0x48]:2 local_48                  XREF[2]:     004583be(*), 004585c5(R)  
    //              short             Stack[-0x4a]:2 random                    XREF[2]:     004583c2(*), 004585b9(R)  
    //              short             Stack[-0x4c]:2 border_style              XREF[2]:     004583c7(*), 004585ab(R)  
    //              short             Stack[-0x4e]:2 underlay_terrain          XREF[2]:     004583d6(*), 0045855b(R)  
    //              short             Stack[-0x50]:2 tile_flag                 XREF[2]:     004583db(*), 00458554(R)  
    //              short             Stack[-0x52]:2 animation_frames          XREF[2]:     004583ea(*), 004584ed(R)  
    //              short             Stack[-0x54]:2 is_animated               XREF[2]:     004583ef(*), 004584e6(R)  
    //              short             Stack[-0x56]:2 hi_color                  XREF[2]:     004583e5(*), 004584df(R)  
    //              short             Stack[-0x58]:2 med_color                 XREF[2]:     004583e0(*), 004584c2(R)  
    //              short             Stack[-0x5a]:2 low_color
    //              short             Stack[-0x5c]:2 sound_id
    //                               ?load_border_types@RGE_Map@@QAEXPADPAPAVRGE_Sound@@@Z        XREF[1]:     RGE_Map:004553f7(c)  
    //                               RGE_Map::load_border_types
    //                              map.cpp:1827 (13)
    //         00458350     SUB        ESP,0x58
    //         00458353     PUSH       EBX
    //         00458354     PUSH       EBP
    //         00458355     PUSH       ESI
    //         00458356     PUSH       EDI
    //         00458357     MOV        EDI,this
    //         00458359     MOV        dword ptr [ESP + name[0]],EDI
    //                              map.cpp:1853 (11)
    //         0045835d     MOV        this,0x10
    //         00458362     LEA        EAX,[EDI + 0x87ec]
    //                               LAB_00458368                                                 XREF[1]:     00458371(j)  
    //                              map.cpp:1854 (11)
    //         00458368     MOV        byte ptr [EAX],0x0
    //         0045836b     SUB        EAX,0x5a0
    //         00458370     DEC        this
    //         00458371     JNZ        LAB_00458368
    //                              map.cpp:1857 (20)
    //         00458373     MOV        EAX,dword ptr [ESP + param_1]
    //         00458377     PUSH       s_r                                              = "r"
    //         0045837c     PUSH       EAX
    //         0045837d     CALL       fopen                                            undefined fopen()
    //         00458382     MOV        EBP,EAX
    //         00458384     ADD        ESP,0x8
    //                              map.cpp:1858 (12)
    //         00458387     TEST       EBP,EBP
    //         00458389     MOV        dword ptr [ESP + local_30],EBP
    //         0045838d     JZ         LAB_004585e4
    //                              map.cpp:1860 (18)
    //         00458393     LEA        ESI,[EDI + 0x8d92]
    //         00458399     PUSH       ESI
    //         0045839a     PUSH       s_%hd                                            = "%hd"
    //         0045839f     PUSH       EBP
    //         004583a0     CALL       fscanf                                           undefined fscanf()
    //                              map.cpp:1861 (17)
    //         004583a5     MOV        AX,word ptr [ESI]
    //         004583a8     ADD        ESP,0xc
    //         004583ab     DEC        AX
    //         004583ad     TEST       AX,AX
    //         004583b0     JL         LAB_004585e4
    //                              map.cpp:1911 (134)
    //         004583b6     MOVSX      EAX,AX
    //         004583b9     INC        EAX
    //         004583ba     MOV        dword ptr [ESP + resource_id],EAX
    //                               LAB_004583be                                                 XREF[1]:     004585de(j)  
    //         004583be     LEA        this=>local_48,[ESP + 0x20]
    //         004583c2     LEA        EDX=>random,[ESP + 0x1e]
    //         004583c6     PUSH       this
    //         004583c7     LEA        EAX=>border_style,[ESP + 0x20]
    //         004583cb     PUSH       EDX
    //         004583cc     LEA        this=>infile,[ESP + 0x3c]
    //         004583d0     PUSH       EAX
    //         004583d1     LEA        EDX=>local_40,[ESP + 0x34]
    //         004583d5     PUSH       this
    //         004583d6     LEA        EAX=>underlay_terrain,[ESP + 0x2a]
    //         004583da     PUSH       EDX
    //         004583db     LEA        this=>tile_flag,[ESP + 0x2c]
    //         004583df     PUSH       EAX
    //         004583e0     LEA        EDX=>med_color,[ESP + 0x28]
    //         004583e4     PUSH       this
    //         004583e5     LEA        EAX=>hi_color,[ESP + 0x2e]
    //         004583e9     PUSH       EDX
    //         004583ea     LEA        this=>animation_frames,[ESP + 0x36]
    //         004583ee     PUSH       EAX
    //         004583ef     LEA        EDX=>is_animated,[ESP + 0x38]
    //         004583f3     PUSH       this
    //         004583f4     LEA        EAX=>local_46,[ESP + 0x4a]
    //         004583f8     PUSH       EDX
    //         004583f9     LEA        this=>local_28,[ESP + 0x6c]
    //         004583fd     PUSH       EAX
    //         004583fe     LEA        EDX=>pict_name[4],[ESP + 0x88]
    //         00458405     PUSH       this
    //         00458406     LEA        EAX=>name[4],[ESP + 0x7c]
    //         0045840a     PUSH       EDX
    //         0045840b     LEA        this=>param_1,[ESP + 0xa4]
    //         00458412     PUSH       EAX
    //         00458413     PUSH       this
    //         00458414     PUSH       s_%hd_%s_%s_%d_%hd_%hd_%hd_%hd_%hd               = "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %
    //         00458419     PUSH       EBP
    //         0045841a     XOR        EBX,EBX
    //         0045841c     CALL       fscanf                                           undefined fscanf()
    //         00458421     ADD        ESP,0x48
    //         00458424     CMP        EAX,-0x1
    //         00458427     JZ         LAB_004585d5
    //         0045842d     MOV        AX,word ptr [ESP + param_1]
    //         00458432     CMP        AX,0x10
    //         00458436     JGE        LAB_004585d5
    //                              map.cpp:1866 (9)
    //         0045843c     TEST       AX,AX
    //         0045843f     JL         LAB_004585d5
    //                              map.cpp:1869 (3)
    //         00458445     MOVSX      EAX,AX
    //                              map.cpp:1911 (37)
    //         00458448     MOV        dword ptr [ESP + pause_between_loops],0x13
    //         00458450     LEA        EAX,[EAX + EAX*0x4]
    //         00458453     LEA        EDX,[EAX + EAX*0x8]
    //         00458456     SHL        EDX,0x5
    //         00458459     LEA        EBP,[EDX + EDI*0x1 + 0x338c]
    //         00458460     LEA        ESI,[EBP + 0x42]
    //         00458463     MOV        dword ptr [ESP + interval],ESI
    //         00458467     JMP        LAB_0045846d
    //                               LAB_00458469                                                 XREF[1]:     004584c0(j)  
    //         00458469     MOV        ESI,dword ptr [ESP + interval]
    //                               LAB_0045846d                                                 XREF[1]:     00458467(j)  
    //                              map.cpp:1872 (13)
    //         0045846d     MOV        EDI,ESI
    //         0045846f     ADD        ESI,0x2
    //         00458472     MOV        dword ptr [ESP + local_3c],0xc
    //                               LAB_0045847a                                                 XREF[1]:     004584aa(j)  
    //                              map.cpp:1875 (17)
    //         0045847a     MOV        EAX,dword ptr [ESP + local_30]
    //         0045847e     PUSH       ESI
    //         0045847f     PUSH       EDI
    //         00458480     PUSH       s_%hd_%hd                                        = "%hd %hd"
    //         00458485     PUSH       EAX
    //         00458486     CALL       fscanf                                           undefined fscanf()
    //                              map.cpp:1877 (20)
    //         0045848b     MOV        this,word ptr [EDI]
    //         0045848e     MOV        EAX,dword ptr [ESP + local_3c]
    //         00458492     IMUL       this,word ptr [ESI]
    //         00458496     MOV        word ptr [ESI + 0x2],BX
    //         0045849a     ADD        ESP,0x10
    //         0045849d     ADD        EBX,this
    //                              map.cpp:1878 (35)
    //         0045849f     ADD        EDI,0x6
    //         004584a2     ADD        ESI,0x6
    //         004584a5     DEC        EAX
    //         004584a6     MOV        dword ptr [ESP + local_3c],EAX
    //         004584aa     JNZ        LAB_0045847a
    //         004584ac     MOV        this,dword ptr [ESP + interval]
    //         004584b0     MOV        EAX,dword ptr [ESP + pause_between_loops]
    //         004584b4     ADD        this,0x48
    //         004584b7     DEC        EAX
    //         004584b8     MOV        dword ptr [ESP + interval],this
    //         004584bc     MOV        dword ptr [ESP + pause_between_loops],EAX
    //         004584c0     JNZ        LAB_00458469
    //                              map.cpp:1883 (29)
    //         004584c2     MOV        AX,word ptr [ESP + med_color]
    //         004584c7     XOR        EBX,EBX
    //         004584c9     CMP        AX,BX
    //         004584cc     JL         LAB_004584da
    //         004584ce     MOVSX      EDX,AX
    //         004584d1     MOV        EAX,dword ptr [ESP + param_2]
    //         004584d5     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //         004584d8     JMP        LAB_004584dc
    //                               LAB_004584da                                                 XREF[1]:     004584cc(j)  
    //         004584da     XOR        EAX,EAX
    //                               LAB_004584dc                                                 XREF[1]:     004584d8(j)  
    //         004584dc     MOV        dword ptr [EBP + 0x24],EAX
    //                              map.cpp:1884 (7)
    //         004584df     MOV        this,byte ptr [ESP + hi_color]
    //         004584e3     MOV        byte ptr [EBP + 0x2a],this
    //                              map.cpp:1885 (7)
    //         004584e6     MOV        DL,byte ptr [ESP + is_animated]
    //         004584ea     MOV        byte ptr [EBP + 0x29],DL
    //                              map.cpp:1886 (4)
    //         004584ed     MOV        AL,byte ptr [ESP + animation_frames]
    //                              map.cpp:1887 (13)
    //         004584f1     LEA        this=>name[4],[ESP + 0x48]
    //         004584f5     MOV        byte ptr [EBP + 0x28],AL
    //         004584f8     PUSH       this
    //         004584f9     CALL       convert_us                                       void convert_us(char * param_1)
    //                              map.cpp:1888 (27)
    //         004584fe     LEA        EDI=>name[4],[ESP + 0x4c]
    //         00458502     OR         this,0xffffffff
    //         00458505     XOR        EAX,EAX
    //         00458507     ADD        ESP,0x4
    //         0045850a     SCASB.RE   ES:EDI
    //         0045850c     NOT        this
    //         0045850e     SUB        EDI,this
    //         00458510     LEA        EDX,[EBP + 0x2]
    //         00458513     MOV        EAX,this
    //         00458515     MOV        ESI,EDI
    //         00458517     MOV        EDI,EDX
    //                              map.cpp:1889 (48)
    //         00458519     LEA        EDX,[EBP + 0xf]
    //         0045851c     SHR        this,0x2
    //         0045851f     MOVSD.REP  ES:EDI,ESI
    //         00458521     MOV        this,EAX
    //         00458523     XOR        EAX,EAX
    //         00458525     AND        this,0x3
    //         00458528     MOVSB.REP  ES:EDI,ESI
    //         0045852a     LEA        EDI=>pict_name[4],[ESP + 0x58]
    //         0045852e     OR         this,0xffffffff
    //         00458531     SCASB.RE   ES:EDI
    //         00458533     NOT        this
    //         00458535     SUB        EDI,this
    //         00458537     MOV        EAX,this
    //         00458539     MOV        ESI,EDI
    //         0045853b     MOV        EDI,EDX
    //         0045853d     SHR        this,0x2
    //         00458540     MOVSD.REP  ES:EDI,ESI
    //         00458542     MOV        this,EAX
    //         00458544     AND        this,0x3
    //         00458547     MOVSB.REP  ES:EDI,ESI
    //                              map.cpp:1890 (4)
    //         00458549     MOV        this,dword ptr [ESP + local_28]
    //                              map.cpp:1891 (7)
    //         0045854d     MOV        byte ptr [EBP],0x1
    //         00458551     MOV        dword ptr [EBP + 0x1c],this
    //                              map.cpp:1892 (7)
    //         00458554     MOV        DL,byte ptr [ESP + tile_flag]
    //         00458558     MOV        byte ptr [EBP + 0x2b],DL
    //                              map.cpp:1893 (9)
    //         0045855b     MOV        AX,word ptr [ESP + underlay_terrain]
    //         00458560     MOV        word ptr [EBP + 0x2c],AX
    //                              map.cpp:1894 (38)
    //         00458564     FLD        float ptr [ESP + local_40]
    //         00458568     FCOMP      float ptr [DAT_005706ac]
    //         0045856e     FNSTSW     AX
    //         00458570     TEST       AH,0x40
    //         00458573     JZ         LAB_00458579
    //         00458575     XOR        EAX,EAX
    //         00458577     JMP        LAB_00458586
    //                               LAB_00458579                                                 XREF[1]:     00458573(j)  
    //         00458579     FLD        float ptr [ESP + infile]
    //         0045857d     FDIV       float ptr [ESP + local_40]
    //         00458581     CALL       __ftol                                           undefined __ftol()
    //                               LAB_00458586                                                 XREF[1]:     00458577(j)  
    //         00458586     MOV        word ptr [EBP + 0x2e],AX
    //                              map.cpp:1895 (7)
    //         0045858a     MOV        this,dword ptr [ESP + local_40]
    //         0045858e     MOV        dword ptr [EBP + 0x30],this
    //                              map.cpp:1896 (7)
    //         00458591     MOV        EDX,dword ptr [ESP + infile]
    //         00458595     MOV        dword ptr [EBP + 0x34],EDX
    //                              map.cpp:1897 (4)
    //         00458598     MOV        word ptr [EBP + 0x38],BX
    //                              map.cpp:1898 (4)
    //         0045859c     MOV        word ptr [EBP + 0x3a],BX
    //                              map.cpp:1899 (3)
    //         004585a0     MOV        dword ptr [EBP + 0x3c],EBX
    //                              map.cpp:1900 (4)
    //         004585a3     MOV        byte ptr [EBP + 0x40],0x0
    //                              map.cpp:1901 (4)
    //         004585a7     MOV        byte ptr [EBP + 0x41],0x0
    //                              map.cpp:1902 (4)
    //         004585ab     MOV        AL,byte ptr [ESP + border_style]
    //                              map.cpp:1904 (53)
    //         004585af     MOV        EDI,dword ptr [ESP + name[0]]
    //         004585b3     MOV        byte ptr [EBP + 0x59a],AL
    //         004585b9     MOV        this,word ptr [ESP + random]
    //         004585be     MOV        word ptr [EBP + 0x59c],this
    //         004585c5     MOV        DX,word ptr [ESP + local_48]
    //         004585ca     MOV        word ptr [EBP + 0x59e],DX
    //         004585d1     MOV        EBP,dword ptr [ESP + local_30]
    //                               LAB_004585d5                                                 XREF[3]:     00458427(j), 00458436(j), 
    //                                                                                                         0045843f(j)  
    //         004585d5     MOV        EAX,dword ptr [ESP + resource_id]
    //         004585d9     DEC        EAX
    //         004585da     MOV        dword ptr [ESP + resource_id],EAX
    //         004585de     JNZ        LAB_004583be
    //                               LAB_004585e4                                                 XREF[2]:     0045838d(j), 004583b0(j)  
    //                              map.cpp:1910 (9)
    //         004585e4     PUSH       EBP
    //         004585e5     CALL       fclose                                           undefined fclose()
    //         004585ea     ADD        ESP,0x4
    //                              map.cpp:1911 (10)
    //         004585ed     POP        EDI
    //         004585ee     POP        ESI
    //         004585ef     POP        EBP
    //         004585f0     POP        EBX
    //         004585f1     ADD        ESP,0x58
    //         004585f4     RET        0x8
}

// Offset: 0x00458600
void load_terrain_obj_types(RGE_Map* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::load_terrain_obj_types(char *)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall load_terrain_obj_types(RGE_Map * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[7]:     00458600(R), 00458644(*), 00458661(R), 004586b4(R), 
    //                                                                                     004586da(R), 004586fb(R), 00458727(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00458623(*), 00458695(W), 004586c3(R), 004586e6(R)  
    //              undefined2        Stack[-0x6]:2  local_6                   XREF[3]:     0045863e(*), 004586a7(R), 00458722(*)  
    //              short             Stack[-0x8]:2  num                       XREF[3]:     0045863a(*), 004586cb(R), 0045871d(*)  
    //              short             Stack[-0xa]:2  obj_id                    XREF[3]:     00458636(*), 004586f0(R), 00458719(*)  
    //              short             Stack[-0xc]:2  density
    //              short             Stack[-0xe]:2  flag
    //                               ?load_terrain_obj_types@RGE_Map@@QAEXPAD@Z                   XREF[2]:     data_load_map:0052e32b(c), 
    //                               RGE_Map::load_terrain_obj_types                                           data_load_map:00541576(c)  
    //                              map.cpp:1916 (27)
    //         00458600     MOV        EAX,dword ptr [ESP + param_1]
    //         00458604     SUB        ESP,0xc
    //         00458607     PUSH       ESI
    //         00458608     PUSH       EDI
    //         00458609     PUSH       s_r                                              = "r"
    //         0045860e     MOV        ESI,this
    //         00458610     PUSH       EAX
    //         00458611     CALL       fopen                                            undefined fopen()
    //         00458616     MOV        EDI,EAX
    //         00458618     ADD        ESP,0x8
    //                              map.cpp:1926 (8)
    //         0045861b     TEST       EDI,EDI
    //         0045861d     JZ         LAB_00458744
    //                              map.cpp:1928 (19)
    //         00458623     LEA        this=>local_4,[ESP + 0x10]
    //         00458627     PUSH       this
    //         00458628     PUSH       s_%hd                                            = "%hd"
    //         0045862d     PUSH       EDI
    //         0045862e     CALL       fscanf                                           undefined fscanf()
    //         00458633     ADD        ESP,0xc
    //                              map.cpp:1929 (43)
    //         00458636     LEA        EDX=>obj_id,[ESP + 0xa]
    //         0045863a     LEA        EAX=>num,[ESP + 0xc]
    //         0045863e     LEA        this=>local_6,[ESP + 0xe]
    //         00458642     PUSH       EDX
    //         00458643     PUSH       EAX
    //         00458644     LEA        EDX=>param_1,[ESP + 0x20]
    //         00458648     PUSH       this
    //         00458649     PUSH       EDX
    //         0045864a     PUSH       s_%hd_%hd_%hd_%hd                                = "%hd %hd %hd %hd"
    //         0045864f     PUSH       EDI
    //         00458650     CALL       fscanf                                           undefined fscanf()
    //         00458655     ADD        ESP,0x18
    //         00458658     CMP        EAX,-0x1
    //         0045865b     JZ         LAB_00458744
    //                               LAB_00458661                                                 XREF[1]:     0045873e(j)  
    //                              map.cpp:1931 (50)
    //         00458661     MOVSX      this,word ptr [ESP + param_1]
    //         00458666     MOV        EAX,this
    //         00458668     SHL        EAX,0x4
    //         0045866b     ADD        EAX,this
    //         0045866d     LEA        EAX,[EAX + EAX*0x2]
    //         00458670     MOV        DL,byte ptr [ESI + EAX*0x8 + 0x8c]
    //         00458677     LEA        EAX,[ESI + EAX*0x8]
    //         0045867a     TEST       DL,DL
    //         0045867c     JZ         LAB_00458719
    //         00458682     MOV        DX,word ptr [EAX + 0x220]
    //         00458689     CMP        DX,0x1e
    //         0045868d     JGE        LAB_00458719
    //                              map.cpp:1934 (33)
    //         00458693     MOV        EAX,this
    //         00458695     MOV        dword ptr [ESP + local_4],EDX
    //         00458699     SHL        EAX,0x4
    //         0045869c     ADD        EAX,this
    //         0045869e     MOVSX      EDX,DX
    //         004586a1     LEA        this,[EAX + EAX*0x2]
    //         004586a4     LEA        EAX,[EDX + this->_padding_*0x4]
    //         004586a7     MOV        this,word ptr [ESP + local_6]
    //         004586ac     MOV        word ptr [ESI + EAX*0x2 + 0x18a],this
    //                              map.cpp:1935 (36)
    //         004586b4     MOVSX      this,word ptr [ESP + param_1]
    //         004586b9     MOV        EAX,this
    //         004586bb     SHL        EAX,0x4
    //         004586be     ADD        EAX,this
    //         004586c0     LEA        EDX,[EAX + EAX*0x2]
    //         004586c3     MOVSX      EAX,word ptr [ESP + local_4]
    //         004586c8     LEA        this,[EAX + EDX*0x4]
    //         004586cb     MOV        DX,word ptr [ESP + num]
    //         004586d0     MOV        word ptr [ESI + this->_padding_*0x2 + 0x1c6],DX
    //                              map.cpp:1936 (35)
    //         004586d8     MOV        EDX,ESI
    //         004586da     MOVSX      this,word ptr [ESP + param_1]
    //         004586df     MOV        EAX,this
    //         004586e1     SHL        EAX,0x4
    //         004586e4     ADD        EAX,this
    //         004586e6     MOVSX      this,word ptr [ESP + local_4]
    //         004586eb     LEA        EAX,[EAX + EAX*0x2]
    //         004586ee     ADD        EDX,this
    //         004586f0     MOV        this,byte ptr [ESP + obj_id]
    //         004586f4     MOV        byte ptr [EDX + EAX*0x8 + 0x202],this
    //                              map.cpp:1937 (73)
    //         004586fb     MOVSX      this,word ptr [ESP + param_1]
    //         00458700     MOV        EAX,this
    //         00458702     SHL        EAX,0x4
    //         00458705     ADD        EAX,this
    //         00458707     LEA        EDX,[EAX + EAX*0x2]
    //         0045870a     INC        word ptr [ESI + EDX*0x8 + 0x220]
    //         00458712     LEA        EAX,[ESI + EDX*0x8 + 0x220]
    //                               LAB_00458719                                                 XREF[2]:     0045867c(j), 0045868d(j)  
    //         00458719     LEA        EAX=>obj_id,[ESP + 0xa]
    //         0045871d     LEA        this=>num,[ESP + 0xc]
    //         00458721     PUSH       EAX
    //         00458722     LEA        EDX=>local_6,[ESP + 0x12]
    //         00458726     PUSH       this
    //         00458727     LEA        EAX=>param_1,[ESP + 0x20]
    //         0045872b     PUSH       EDX
    //         0045872c     PUSH       EAX
    //         0045872d     PUSH       s_%hd_%hd_%hd_%hd                                = "%hd %hd %hd %hd"
    //         00458732     PUSH       EDI
    //         00458733     CALL       fscanf                                           undefined fscanf()
    //         00458738     ADD        ESP,0x18
    //         0045873b     CMP        EAX,-0x1
    //         0045873e     JNZ        LAB_00458661
    //                               LAB_00458744                                                 XREF[2]:     0045861d(j), 0045865b(j)  
    //                              map.cpp:1941 (9)
    //         00458744     PUSH       EDI
    //         00458745     CALL       fclose                                           undefined fclose()
    //         0045874a     ADD        ESP,0x4
    //                              map.cpp:1942 (8)
    //         0045874d     POP        EDI
    //         0045874e     POP        ESI
    //         0045874f     ADD        ESP,0xc
    //         00458752     RET        0x4
}

// Offset: 0x00458760
void delete_objects_on_tile(RGE_Map* this_, RGE_Player* param_2, RGE_Game_World* param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::delete_objects_on_tile(class RGE_Player *,class RGE_Game_World *,... *
    //                              *********************************************************************************************************
    //                              void __thiscall delete_objects_on_tile(RGE_Map * this, RGE_Player * 
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     00458790(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00458760(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0045876e(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00458795(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0045879a(R)  
    //                               ?delete_objects_on_tile@RGE_Map@@QAEXPAVRGE_Player@@PAVRGE_
    //                               RGE_Map::delete_objects_on_tile
    //                              map.cpp:1947 (14)
    //         00458760     MOV        EAX,dword ptr [ESP + param_3]
    //         00458764     PUSH       ESI
    //         00458765     TEST       EAX,EAX
    //         00458767     JL         LAB_004587ca
    //         00458769     CMP        EAX,dword ptr [ECX + this->map_width]
    //         0045876c     JGE        LAB_004587ca
    //                              map.cpp:1949 (13)
    //         0045876e     MOV        EDX,dword ptr [ESP + param_4]
    //         00458772     TEST       EDX,EDX
    //         00458774     JL         LAB_004587ca
    //         00458776     CMP        EDX,dword ptr [ECX + this->map_height]
    //         00458779     JGE        LAB_004587ca
    //                              map.cpp:1950 (16)
    //         0045877b     MOV        this,dword ptr [ECX + this->map_row_offset]
    //         00458781     LEA        EAX,[EAX + EAX*0x2]
    //         00458784     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00458787     MOV        EAX,dword ptr [ECX + EAX*0x8 + this->world_wid
    //                              map.cpp:1953 (19)
    //         0045878b     TEST       EAX,EAX
    //         0045878d     JZ         LAB_004587ca
    //         0045878f     PUSH       EDI
    //         00458790     MOV        EDI,dword ptr [ESP + param_1]
    //         00458794     PUSH       EBP
    //         00458795     MOV        EBP,dword ptr [ESP + param_5]
    //         00458799     PUSH       EBX
    //         0045879a     MOV        EBX,dword ptr [ESP + param_6]
    //                               LAB_0045879e                                                 XREF[1]:     004587c5(j)  
    //                              map.cpp:1958 (12)
    //         0045879e     MOV        this,dword ptr [EAX]
    //         004587a0     MOV        ESI,dword ptr [EAX + 0x4]
    //         004587a3     MOV        EDX,dword ptr [ECX + this->map_width]
    //         004587a6     MOVSX      EAX,word ptr [EDX + 0x10]
    //                              map.cpp:1959 (13)
    //         004587aa     CMP        dword ptr [ECX + this->map_height],EDI
    //         004587ad     JNZ        LAB_004587c1
    //         004587af     CMP        EAX,EBP
    //         004587b1     JL         LAB_004587b7
    //         004587b3     CMP        EAX,EBX
    //         004587b5     JLE        LAB_004587c1
    //                               LAB_004587b7                                                 XREF[1]:     004587b1(j)  
    //                              map.cpp:1961 (19)
    //         004587b7     TEST       this,this
    //         004587b9     JZ         LAB_004587c1
    //         004587bb     MOV        EAX,dword ptr [this->_padding_]
    //         004587bd     PUSH       0x1
    //         004587bf     CALL       dword ptr [EAX]
    //                               LAB_004587c1                                                 XREF[3]:     004587ad(j), 004587b5(j), 
    //                                                                                                         004587b9(j)  
    //         004587c1     TEST       ESI,ESI
    //         004587c3     MOV        EAX,ESI
    //         004587c5     JNZ        LAB_0045879e
    //         004587c7     POP        EBX
    //         004587c8     POP        EBP
    //         004587c9     POP        EDI
    //                               LAB_004587ca                                                 XREF[5]:     00458767(j), 0045876c(j), 
    //                                                                                                         00458774(j), 00458779(j), 
    //                                                                                                         0045878d(j)  
    //                              map.cpp:1964 (4)
    //         004587ca     POP        ESI
    //         004587cb     RET        0x18
}

// Offset: 0x004587D0
void delete_all_objects_on_tile(RGE_Map* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::delete_all_objects_on_tile(int,int)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall delete_all_objects_on_tile(RGE_Map * this, int param
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004587d0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004587de(R)  
    //                               ?delete_all_objects_on_tile@RGE_Map@@QAEXHH@Z
    //                               RGE_Map::delete_all_objects_on_tile
    //                              map.cpp:1970 (14)
    //         004587d0     MOV        EAX,dword ptr [ESP + param_1]
    //         004587d4     PUSH       ESI
    //         004587d5     TEST       EAX,EAX
    //         004587d7     JL         LAB_00458816
    //         004587d9     CMP        EAX,dword ptr [ECX + this->map_width]
    //         004587dc     JGE        LAB_00458816
    //                              map.cpp:1972 (13)
    //         004587de     MOV        EDX,dword ptr [ESP + param_2]
    //         004587e2     TEST       EDX,EDX
    //         004587e4     JL         LAB_00458816
    //         004587e6     CMP        EDX,dword ptr [ECX + this->map_height]
    //         004587e9     JGE        LAB_00458816
    //                              map.cpp:1973 (16)
    //         004587eb     MOV        this,dword ptr [ECX + this->map_row_offset]
    //         004587f1     LEA        EAX,[EAX + EAX*0x2]
    //         004587f4     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         004587f7     MOV        EAX,dword ptr [ECX + EAX*0x8 + this->world_wid
    //                              map.cpp:1976 (4)
    //         004587fb     TEST       EAX,EAX
    //         004587fd     JZ         LAB_00458816
    //                               LAB_004587ff                                                 XREF[1]:     00458814(j)  
    //                              map.cpp:1980 (3)
    //         004587ff     MOV        ESI,dword ptr [EAX + 0x4]
    //                              map.cpp:1981 (20)
    //         00458802     MOV        EAX,dword ptr [EAX]
    //         00458804     TEST       EAX,EAX
    //         00458806     JZ         LAB_00458810
    //         00458808     MOV        EDX,dword ptr [EAX]
    //         0045880a     PUSH       0x1
    //         0045880c     MOV        this,EAX
    //         0045880e     CALL       dword ptr [EDX]
    //                               LAB_00458810                                                 XREF[1]:     00458806(j)  
    //         00458810     TEST       ESI,ESI
    //         00458812     MOV        EAX,ESI
    //         00458814     JNZ        LAB_004587ff
    //                               LAB_00458816                                                 XREF[5]:     004587d7(j), 004587dc(j), 
    //                                                                                                         004587e4(j), 004587e9(j), 
    //                                                                                                         004587fd(j)  
    //                              map.cpp:1983 (4)
    //         00458816     POP        ESI
    //         00458817     RET        0x8
}

// Offset: 0x00458820
void create_terrain_object(RGE_Map* this_, RGE_Player* param_2, RGE_Game_World* param_3, short param_4, short param_5, short param_6, int param_7, int param_8, int param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::create_terrain_object(class RGE_Player *,class RGE_Game_World *,s... *
    //                              *********************************************************************************************************
    //                              void __thiscall create_terrain_object(RGE_Map * this, RGE_Player * p
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     00458896(R), 00458981(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     00458826(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0045882b(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[3]:     004588be(R), 00458967(W), 00458991(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[2]:     004588c8(R), 0045896b(W)  
    //              int               Stack[0x1c]:4  param_7                   XREF[2]:     004588b2(R), 0045896f(W)  
    //              int               Stack[0x20]:4  param_8                   XREF[1]:     004588b8(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045886b(W)  
    //              short             Stack[-0x8]:2  end_i                     XREF[1]:     00458867(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00458833(W)  
    //              float             Stack[-0x10]:4 x                         XREF[1]:     0045883b(W)  
    //              float             Stack[-0x14]:4 y
    //                               ?create_terrain_object@RGE_Map@@QAEXPAVRGE_Player@@PAVRGE_G  XREF[2]:     create_terrain_objects:00458ffe(c)
    //                               RGE_Map::create_terrain_object                                            set_terrain:00459c39(c)  
    //                              map.cpp:1989 (6)
    //         00458820     SUB        ESP,0x10
    //         00458823     PUSH       EBX
    //         00458824     PUSH       EBP
    //         00458825     PUSH       ESI
    //                              map.cpp:2005 (38)
    //         00458826     MOV        ESI,dword ptr [ESP + param_3]
    //         0045882a     PUSH       EDI
    //         0045882b     MOV        EDI,dword ptr [ESP + param_4]
    //         0045882f     PUSH       ESI
    //         00458830     MOV        EBX,this
    //         00458832     PUSH       EDI
    //         00458833     MOV        dword ptr [ESP + local_c],0x0
    //         0045883b     MOV        dword ptr [ESP + x],0x0
    //         00458843     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //         00458848     MOVZX      AX,AL
    //                              map.cpp:2007 (24)
    //         0045884c     MOVSX      this,AX
    //         0045884f     MOV        EAX,this
    //         00458851     SHL        EAX,0x4
    //         00458854     ADD        EAX,this
    //         00458856     LEA        EAX,[EAX + EAX*0x2]
    //         00458859     MOV        DX,word ptr [EBX + EAX*0x8 + 0x220]
    //         00458861     LEA        this,[EBX + EAX*0x8]
    //                              map.cpp:2011 (17)
    //         00458864     TEST       DX,DX
    //         00458867     MOV        dword ptr [ESP + end_i],this
    //         0045886b     MOV        dword ptr [ESP + local_4],EDX
    //         0045886f     JLE        LAB_00458b30
    //                              map.cpp:2012 (31)
    //         00458875     MOV        EBP,dword ptr [EBX + 0x8d8c]
    //         0045887b     MOVSX      ESI,SI
    //         0045887e     MOVSX      EAX,DI
    //         00458881     MOV        ESI,dword ptr [EBP + ESI*0x4]
    //         00458885     LEA        EAX,[EAX + EAX*0x2]
    //         00458888     MOV        EAX,dword ptr [ESI + EAX*0x8 + 0x10]
    //         0045888c     TEST       EAX,EAX
    //         0045888e     JZ         LAB_0045894f
    //                               LAB_00458894                                                 XREF[1]:     00458941(j)  
    //                              map.cpp:2016 (2)
    //         00458894     MOV        this,dword ptr [EAX]
    //                              map.cpp:2018 (40)
    //         00458896     MOV        ESI,dword ptr [ESP + param_1]
    //         0045889a     MOV        EBP,dword ptr [EAX + 0x4]
    //         0045889d     MOV        EDX,dword ptr [ECX + this->map_width]
    //         004588a0     MOV        DI,word ptr [EDX + 0x10]
    //         004588a4     MOV        EDX,dword ptr [ECX + this->map_height]
    //         004588a7     CMP        EDX,ESI
    //         004588a9     MOVSX      EAX,DI
    //         004588ac     JNZ        LAB_0045893d
    //         004588b2     CMP        EAX,dword ptr [ESP + param_7]
    //         004588b6     JL         LAB_004588be
    //         004588b8     CMP        EAX,dword ptr [ESP + param_8]
    //         004588bc     JLE        LAB_0045893d
    //                               LAB_004588be                                                 XREF[1]:     004588b6(j)  
    //                              map.cpp:2020 (10)
    //         004588be     MOV        AX,word ptr [ESP + param_5]
    //         004588c3     TEST       AX,AX
    //         004588c6     JGE        LAB_004588e3
    //                              map.cpp:2022 (8)
    //         004588c8     MOV        EAX,dword ptr [ESP + param_6]
    //         004588cc     TEST       EAX,EAX
    //         004588ce     JZ         LAB_004588dc
    //                              map.cpp:2023 (10)
    //         004588d0     TEST       this,this
    //         004588d2     JZ         LAB_0045893d
    //         004588d4     MOV        EAX,dword ptr [this->_padding_]
    //         004588d6     PUSH       0x1
    //         004588d8     CALL       dword ptr [EAX]
    //                              map.cpp:2024 (2)
    //         004588da     JMP        LAB_0045893d
    //                               LAB_004588dc                                                 XREF[1]:     004588ce(j)  
    //                              map.cpp:2025 (5)
    //         004588dc     MOV        EDX,dword ptr [this->_padding_]
    //         004588de     CALL       dword ptr [EDX + 0x68]
    //                              map.cpp:2027 (2)
    //         004588e1     JMP        LAB_0045893d
    //                               LAB_004588e3                                                 XREF[1]:     004588c6(j)  
    //                              map.cpp:2032 (26)
    //         004588e3     MOVSX      EDX,AX
    //         004588e6     MOV        EAX,EDX
    //         004588e8     SHL        EAX,0x4
    //         004588eb     ADD        EAX,EDX
    //         004588ed     LEA        EAX,[EAX + EAX*0x2]
    //         004588f0     MOV        AX,word ptr [EBX + EAX*0x8 + 0x220]
    //         004588f8     TEST       AX,AX
    //         004588fb     JL         LAB_0045893d
    //                              map.cpp:2033 (34)
    //         004588fd     MOV        ESI,EDX
    //         004588ff     SHL        ESI,0x4
    //         00458902     ADD        ESI,EDX
    //         00458904     LEA        EDX,[ESI + ESI*0x2]
    //         00458907     SHL        EDX,0x2
    //                               LAB_0045890a                                                 XREF[1]:     0045891d(j)  
    //         0045890a     MOVSX      ESI,AX
    //         0045890d     ADD        ESI,EDX
    //         0045890f     CMP        word ptr [EBX + ESI*0x2 + 0x18a],DI
    //         00458917     JZ         LAB_0045891f
    //         00458919     DEC        EAX
    //         0045891a     TEST       AX,AX
    //         0045891d     JGE        LAB_0045890a
    //                               LAB_0045891f                                                 XREF[1]:     00458917(j)  
    //                              map.cpp:2037 (5)
    //         0045891f     TEST       AX,AX
    //         00458922     JL         LAB_0045893d
    //                              map.cpp:2039 (8)
    //         00458924     MOV        EAX,dword ptr [ESP + 0x38]
    //         00458928     TEST       EAX,EAX
    //         0045892a     JZ         LAB_00458938
    //                              map.cpp:2040 (10)
    //         0045892c     TEST       this,this
    //         0045892e     JZ         LAB_0045893d
    //         00458930     MOV        EDX,dword ptr [this->_padding_]
    //         00458932     PUSH       0x1
    //         00458934     CALL       dword ptr [EDX]
    //                              map.cpp:2041 (2)
    //         00458936     JMP        LAB_0045893d
    //                               LAB_00458938                                                 XREF[1]:     0045892a(j)  
    //                              map.cpp:2042 (23)
    //         00458938     MOV        EAX,dword ptr [this->_padding_]
    //         0045893a     CALL       dword ptr [EAX + 0x68]
    //                               LAB_0045893d                                                 XREF[9]:     004588ac(j), 004588bc(j), 
    //                                                                                                         004588d2(j), 004588da(j), 
    //                                                                                                         004588e1(j), 004588fb(j), 
    //                                                                                                         00458922(j), 0045892e(j), 
    //                                                                                                         00458936(j)  
    //         0045893d     TEST       EBP,EBP
    //         0045893f     MOV        EAX,EBP
    //         00458941     JNZ        LAB_00458894
    //         00458947     MOV        this,dword ptr [ESP + 0x18]
    //         0045894b     MOV        EDX,dword ptr [ESP + 0x1c]
    //                               LAB_0045894f                                                 XREF[1]:     0045888e(j)  
    //                              map.cpp:2049 (36)
    //         0045894f     TEST       DX,DX
    //         00458952     JLE        LAB_00458b30
    //         00458958     MOVSX      EDX,DX
    //         0045895b     LEA        EAX,[ECX + this+0x202]
    //         00458961     ADD        this,0x1c6
    //         00458967     MOV        dword ptr [ESP + param_5],EAX
    //         0045896b     MOV        dword ptr [ESP + param_6],this
    //         0045896f     MOV        dword ptr [ESP + param_7],EDX
    //                               LAB_00458973                                                 XREF[1]:     00458b2a(j)  
    //                              map.cpp:2051 (4)
    //         00458973     MOV        AX,word ptr [this->_padding_ + -0x3c]
    //                              map.cpp:2052 (10)
    //         00458977     CMP        AX,0xffff
    //         0045897b     JZ         LAB_00458b11
    //                              map.cpp:2054 (4)
    //         00458981     MOV        EDX,dword ptr [ESP + param_1]
    //                              map.cpp:2055 (12)
    //         00458985     MOV        BP,word ptr [this->_padding_]
    //         00458988     MOVSX      EAX,AX
    //         0045898b     MOV        EDX,dword ptr [EDX + 0x24]
    //         0045898e     MOV        EDI,dword ptr [EDX + EAX*0x4]
    //                              map.cpp:2056 (4)
    //         00458991     MOV        EAX,dword ptr [ESP + param_5]
    //                              map.cpp:2059 (14)
    //         00458995     TEST       EDI,EDI
    //         00458997     MOV        DL,byte ptr [EAX]
    //         00458999     MOV        byte ptr [ESP + 0x40],DL
    //         0045899d     JZ         LAB_00458b11
    //                              map.cpp:2061 (9)
    //         004589a3     TEST       BP,BP
    //         004589a6     JLE        LAB_00458b11
    //                              map.cpp:2064 (13)
    //         004589ac     MOV        EAX,dword ptr [ESP + 0x40]
    //         004589b0     AND        EAX,0xff
    //         004589b5     MOV        dword ptr [ESP + 0x1c],EAX
    //                              map.cpp:2092 (9)
    //         004589b9     MOVSX      EBX,BP
    //         004589bc     JMP        LAB_004589c2
    //                               LAB_004589be                                                 XREF[1]:     00458b07(j)  
    //         004589be     MOV        EAX,dword ptr [ESP + 0x1c]
    //                               LAB_004589c2                                                 XREF[1]:     004589bc(j)  
    //                              map.cpp:2064 (12)
    //         004589c2     SUB        EAX,0x0
    //         004589c5     JZ         LAB_004589fe
    //         004589c7     DEC        EAX
    //         004589c8     JNZ        LAB_00458a70
    //                              map.cpp:2072 (46)
    //         004589ce     MOVSX      this,word ptr [ESP + 0x2c]
    //         004589d3     MOVSX      EAX,word ptr [ESP + 0x30]
    //         004589d8     MOV        dword ptr [ESP + 0x14],this
    //         004589dc     MOV        dword ptr [ESP + 0x18],EAX
    //         004589e0     FILD       dword ptr [ESP + 0x14]
    //         004589e4     FILD       dword ptr [ESP + 0x18]
    //         004589e8     FSUB       float ptr [DAT_005706b0]
    //         004589ee     FXCH
    //         004589f0     FSUB       float ptr [DAT_005706b0]
    //         004589f6     FXCH
    //         004589f8     FSTP       float ptr [ESP + 0x14]
    //                              map.cpp:2073 (2)
    //         004589fc     JMP        LAB_00458a6c
    //                               LAB_004589fe                                                 XREF[1]:     004589c5(j)  
    //                              map.cpp:2067 (43)
    //         004589fe     MOVSX      EDX,word ptr [ESP + 0x30]
    //         00458a03     MOV        dword ptr [ESP + 0x18],EDX
    //         00458a07     PUSH       0x813
    //         00458a0c     FILD       dword ptr [ESP + 0x1c]
    //         00458a10     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458a15     FSTP       float ptr [ESP + 0x1c]
    //         00458a19     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458a1e     MOV        dword ptr [ESP + 0x20],EAX
    //         00458a22     ADD        ESP,0x8
    //         00458a25     FILD       dword ptr [ESP + 0x18]
    //                              map.cpp:2068 (71)
    //         00458a29     MOVSX      EAX,word ptr [ESP + 0x2c]
    //         00458a2e     FMUL       float ptr [DAT_005706b4]
    //         00458a34     MOV        dword ptr [ESP + 0x18],EAX
    //         00458a38     PUSH       0x814
    //         00458a3d     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458a42     FSUBR      float ptr [ESP + 0x1c]
    //         00458a46     FSTP       float ptr [ESP + 0x1c]
    //         00458a4a     FILD       dword ptr [ESP + 0x20]
    //         00458a4e     FSTP       float ptr [ESP + 0x18]
    //         00458a52     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458a57     MOV        dword ptr [ESP + 0x20],EAX
    //         00458a5b     ADD        ESP,0x8
    //         00458a5e     FILD       dword ptr [ESP + 0x18]
    //         00458a62     FMUL       float ptr [DAT_005706b4]
    //         00458a68     FSUBR      float ptr [ESP + 0x10]
    //                               LAB_00458a6c                                                 XREF[1]:     004589fc(j)  
    //         00458a6c     FSTP       float ptr [ESP + 0x10]
    //                               LAB_00458a70                                                 XREF[1]:     004589c8(j)  
    //                              map.cpp:2077 (7)
    //         00458a70     CMP        BP,0x3e8
    //         00458a75     JL         LAB_00458a7e
    //                              map.cpp:2078 (5)
    //         00458a77     MOV        EAX,0x1
    //                              map.cpp:2079 (2)
    //         00458a7c     JMP        LAB_00458ab6
    //                               LAB_00458a7e                                                 XREF[1]:     00458a75(j)  
    //                              map.cpp:2080 (56)
    //         00458a7e     PUSH       0x820
    //         00458a83     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458a88     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458a8d     LEA        this,[EAX + EAX*0x2]
    //         00458a90     ADD        ESP,0x8
    //         00458a93     LEA        EAX,[EAX + this->_padding_*0x8]
    //         00458a96     LEA        this,[EAX + EAX*0x4]
    //         00458a99     MOV        EAX,0x80010003
    //         00458a9e     SHL        this,0x3
    //         00458aa1     IMUL       this
    //         00458aa3     ADD        EDX,this
    //         00458aa5     SAR        EDX,0xe
    //         00458aa8     MOV        EAX,EDX
    //         00458aaa     SHR        EAX,0x1f
    //         00458aad     ADD        EDX,EAX
    //         00458aaf     XOR        EAX,EAX
    //         00458ab1     CMP        EDX,EBX
    //         00458ab3     SETL       AL
    //                               LAB_00458ab6                                                 XREF[1]:     00458a7c(j)  
    //                              map.cpp:2082 (44)
    //         00458ab6     TEST       EAX,EAX
    //         00458ab8     JZ         LAB_00458af8
    //         00458aba     MOV        this,dword ptr [ESP + 0x10]
    //         00458abe     MOV        EDX,dword ptr [ESP + 0x14]
    //         00458ac2     MOV        EAX,dword ptr [ESP + 0x24]
    //         00458ac6     MOV        ESI,dword ptr [EDI]
    //         00458ac8     PUSH       0x1
    //         00458aca     PUSH       0x0=>DAT_fffffff8
    //         00458acc     PUSH       offset DAT_fffffff4
    //         00458ace     PUSH       0x0=>DAT_fffffff0
    //         00458ad0     PUSH       0x1
    //         00458ad2     PUSH       0x0
    //         00458ad4     PUSH       0x0
    //         00458ad6     PUSH       this
    //         00458ad7     PUSH       EDX
    //         00458ad8     PUSH       EAX
    //         00458ad9     MOV        this,EDI
    //         00458adb     CALL       dword ptr [ESI + 0x20]
    //         00458ade     TEST       AL,AL
    //         00458ae0     JNZ        LAB_00458af8
    //                              map.cpp:2084 (22)
    //         00458ae2     MOV        this,dword ptr [ESP + 0x10]
    //         00458ae6     MOV        EDX,dword ptr [ESP + 0x14]
    //         00458aea     MOV        EAX,dword ptr [ESP + 0x24]
    //         00458aee     PUSH       0x0
    //         00458af0     PUSH       this=>DAT_fffffff8
    //         00458af1     PUSH       EDX=>DAT_fffffff4
    //         00458af2     PUSH       EAX=>DAT_fffffff0
    //         00458af3     MOV        this,EDI
    //         00458af5     CALL       dword ptr [ESI + 0x18]
    //                               LAB_00458af8                                                 XREF[2]:     00458ab8(j), 00458ae0(j)  
    //                              map.cpp:2087 (21)
    //         00458af8     SUB        EBP,0x3e8
    //         00458afe     SUB        EBX,0x3e8
    //         00458b04     TEST       BP,BP
    //         00458b07     JG         LAB_004589be
    //                              map.cpp:2061 (4)
    //         00458b0d     MOV        this,dword ptr [ESP + 0x38]
    //                               LAB_00458b11                                                 XREF[3]:     0045897b(j), 0045899d(j), 
    //                                                                                                         004589a6(j)  
    //                              map.cpp:2049 (31)
    //         00458b11     MOV        EDX,dword ptr [ESP + 0x34]
    //         00458b15     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00458b19     ADD        this,0x2
    //         00458b1c     INC        EDX
    //         00458b1d     DEC        EAX
    //         00458b1e     MOV        dword ptr [ESP + 0x38],this
    //         00458b22     MOV        dword ptr [ESP + 0x34],EDX
    //         00458b26     MOV        dword ptr [ESP + 0x3c],EAX
    //         00458b2a     JNZ        LAB_00458973
    //                               LAB_00458b30                                                 XREF[2]:     0045886f(j), 00458952(j)  
    //                              map.cpp:2092 (10)
    //         00458b30     POP        EDI
    //         00458b31     POP        ESI
    //         00458b32     POP        EBP
    //         00458b33     POP        EBX
    //         00458b34     ADD        ESP,0x10
    //         00458b37     RET        0x20
}

// Offset: 0x00458B40
int clear_terrain_object(RGE_Map* this_, RGE_Game_World* param_2, short param_3, short param_4, short param_5, int param_6, int param_7, int param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Map::clear_terrain_object(class RGE_Game_World *,short,short,short,int,... *
    //                              *********************************************************************************************************
    //                              int __thiscall clear_terrain_object(RGE_Map * this, RGE_Game_World *
    //              int               EAX:4          <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     00458b43(R), 00458b70(W)  
    //              short             Stack[0xc]:2   param_3                   XREF[2]:     00458b48(R), 00458b7f(W)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     00458b9d(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00458ba5(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00458b8d(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00458b93(R)  
    //                               ?clear_terrain_object@RGE_Map@@QAEHPAVRGE_Game_World@@FFFHH  XREF[2]:     set_terrain:004599ba(c), 
    //                               RGE_Map::clear_terrain_object                                             set_terrain_absolute:00459a5e(c)  
    //                              map.cpp:2096 (3)
    //         00458b40     PUSH       EBX
    //         00458b41     PUSH       EBP
    //         00458b42     PUSH       ESI
    //                              map.cpp:2107 (21)
    //         00458b43     MOV        ESI,dword ptr [ESP + param_2]
    //         00458b47     PUSH       EDI
    //         00458b48     MOV        EDI,dword ptr [ESP + param_3]
    //         00458b4c     PUSH       ESI
    //         00458b4d     MOV        EBX,this
    //         00458b4f     PUSH       EDI
    //         00458b50     OR         EBP,0xffffffff
    //         00458b53     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //                              map.cpp:2114 (34)
    //         00458b58     MOV        EDX,dword ptr [EBX + 0x8d8c]
    //         00458b5e     MOVSX      this,SI
    //         00458b61     MOVSX      EAX,DI
    //         00458b64     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00458b67     LEA        EAX,[EAX + EAX*0x2]
    //         00458b6a     MOV        ESI,dword ptr [ECX + EAX*0x8 + this->world_wid
    //         00458b6e     TEST       ESI,ESI
    //         00458b70     MOV        dword ptr [ESP + param_2],ESI
    //         00458b74     JZ         LAB_00458c77
    //                               LAB_00458b7a                                                 XREF[1]:     00458c71(j)  
    //                              map.cpp:2118 (19)
    //         00458b7a     MOV        this,dword ptr [ESI]
    //         00458b7c     MOV        EDX,dword ptr [ESI + 0x4]
    //         00458b7f     MOV        dword ptr [ESP + param_3],EDX
    //         00458b83     MOV        EDI,dword ptr [ECX + this->map_width]
    //         00458b86     MOV        AX,word ptr [EDI + 0x10]
    //         00458b8a     MOVSX      EDX,AX
    //                              map.cpp:2120 (16)
    //         00458b8d     CMP        EDX,dword ptr [ESP + param_6]
    //         00458b91     JL         LAB_00458b9d
    //         00458b93     CMP        EDX,dword ptr [ESP + param_7]
    //         00458b97     JLE        LAB_00458c67
    //                               LAB_00458b9d                                                 XREF[1]:     00458b91(j)  
    //                              map.cpp:2122 (8)
    //         00458b9d     CMP        word ptr [ESP + param_4],0x0
    //         00458ba3     JGE        LAB_00458bca
    //                              map.cpp:2124 (8)
    //         00458ba5     MOV        EAX,dword ptr [ESP + param_5]
    //         00458ba9     TEST       EAX,EAX
    //         00458bab     JZ         LAB_00458bc0
    //                              map.cpp:2125 (14)
    //         00458bad     TEST       this,this
    //         00458baf     JZ         LAB_00458c67
    //         00458bb5     MOV        EAX,dword ptr [this->_padding_]
    //         00458bb7     PUSH       0x1
    //         00458bb9     CALL       dword ptr [EAX]
    //                              map.cpp:2126 (5)
    //         00458bbb     JMP        LAB_00458c67
    //                               LAB_00458bc0                                                 XREF[1]:     00458bab(j)  
    //                              map.cpp:2127 (5)
    //         00458bc0     MOV        EDX,dword ptr [this->_padding_]
    //         00458bc2     CALL       dword ptr [EDX + 0x68]
    //                              map.cpp:2129 (5)
    //         00458bc5     JMP        LAB_00458c67
    //                               LAB_00458bca                                                 XREF[1]:     00458ba3(j)  
    //                              map.cpp:2134 (30)
    //         00458bca     MOVSX      EDX,word ptr [ESP + 0x20]
    //         00458bcf     MOV        EBP,EAX
    //         00458bd1     MOV        EAX,EDX
    //         00458bd3     SHL        EAX,0x4
    //         00458bd6     ADD        EAX,EDX
    //         00458bd8     LEA        EAX,[EAX + EAX*0x2]
    //         00458bdb     MOV        AX,word ptr [EBX + EAX*0x8 + 0x220]
    //         00458be3     TEST       AX,AX
    //         00458be6     JL         LAB_00458c27
    //                              map.cpp:2135 (34)
    //         00458be8     MOV        ESI,EDX
    //         00458bea     SHL        ESI,0x4
    //         00458bed     ADD        ESI,EDX
    //         00458bef     LEA        EDX,[ESI + ESI*0x2]
    //         00458bf2     SHL        EDX,0x2
    //                               LAB_00458bf5                                                 XREF[1]:     00458c08(j)  
    //         00458bf5     MOVSX      ESI,AX
    //         00458bf8     ADD        ESI,EDX
    //         00458bfa     CMP        word ptr [EBX + ESI*0x2 + 0x18a],BP
    //         00458c02     JZ         LAB_00458c0a
    //         00458c04     DEC        EAX
    //         00458c05     TEST       AX,AX
    //         00458c08     JGE        LAB_00458bf5
    //                               LAB_00458c0a                                                 XREF[1]:     00458c02(j)  
    //                              map.cpp:2134 (4)
    //         00458c0a     MOV        ESI,dword ptr [ESP + 0x18]
    //                              map.cpp:2139 (5)
    //         00458c0e     TEST       AX,AX
    //         00458c11     JL         LAB_00458c27
    //                              map.cpp:2141 (8)
    //         00458c13     MOV        EAX,dword ptr [ESP + 0x24]
    //         00458c17     TEST       EAX,EAX
    //         00458c19     JZ         LAB_00458c62
    //                              map.cpp:2142 (10)
    //         00458c1b     TEST       this,this
    //         00458c1d     JZ         LAB_00458c67
    //         00458c1f     MOV        EDX,dword ptr [this->_padding_]
    //         00458c21     PUSH       0x1
    //         00458c23     CALL       dword ptr [EDX]
    //                              map.cpp:2143 (2)
    //         00458c25     JMP        LAB_00458c67
    //                               LAB_00458c27                                                 XREF[2]:     00458be6(j), 00458c11(j)  
    //                              map.cpp:2149 (37)
    //         00458c27     MOV        EAX,dword ptr [ECX + this+0x3c]
    //         00458c2a     PUSH       0x0
    //         00458c2c     PUSH       0x0=>DAT_fffffff8
    //         00458c2e     PUSH       offset DAT_fffffff4
    //         00458c30     MOV        EDX,dword ptr [EDI]
    //         00458c32     PUSH       offset DAT_fffffff0
    //         00458c34     PUSH       0x1
    //         00458c36     PUSH       0x0
    //         00458c38     PUSH       0x0
    //         00458c3a     PUSH       EAX
    //         00458c3b     MOV        EAX,dword ptr [ECX + this+0x38]
    //         00458c3e     MOV        this,dword ptr [ECX + this->map_height]
    //         00458c41     PUSH       EAX
    //         00458c42     PUSH       this
    //         00458c43     MOV        this,EDI
    //         00458c45     CALL       dword ptr [EDX + 0x20]
    //         00458c48     TEST       AL,AL
    //         00458c4a     JZ         LAB_00458c67
    //                              map.cpp:2151 (4)
    //         00458c4c     MOV        EAX,dword ptr [ESP + 0x24]
    //                              map.cpp:2152 (16)
    //         00458c50     MOV        this,dword ptr [ESI]
    //         00458c52     TEST       EAX,EAX
    //         00458c54     JZ         LAB_00458c62
    //         00458c56     TEST       this,this
    //         00458c58     JZ         LAB_00458c67
    //         00458c5a     MOV        EDX,dword ptr [this->_padding_]
    //         00458c5c     PUSH       0x1
    //         00458c5e     CALL       dword ptr [EDX]
    //                              map.cpp:2153 (2)
    //         00458c60     JMP        LAB_00458c67
    //                               LAB_00458c62                                                 XREF[2]:     00458c19(j), 00458c54(j)  
    //                              map.cpp:2154 (21)
    //         00458c62     MOV        EAX,dword ptr [this->_padding_]
    //         00458c64     CALL       dword ptr [EAX + 0x68]
    //                               LAB_00458c67                                                 XREF[9]:     00458b97(j), 00458baf(j), 
    //                                                                                                         00458bbb(j), 00458bc5(j), 
    //                                                                                                         00458c1d(j), 00458c25(j), 
    //                                                                                                         00458c4a(j), 00458c58(j), 
    //                                                                                                         00458c60(j)  
    //         00458c67     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00458c6b     TEST       ESI,ESI
    //         00458c6d     MOV        dword ptr [ESP + 0x18],ESI
    //         00458c71     JNZ        LAB_00458b7a
    //                               LAB_00458c77                                                 XREF[1]:     00458b74(j)  
    //                              map.cpp:2162 (10)
    //         00458c77     POP        EDI
    //         00458c78     POP        ESI
    //         00458c79     MOVSX      EAX,BP
    //         00458c7c     POP        EBP
    //         00458c7d     POP        EBX
    //         00458c7e     RET        0x1c
}

// Offset: 0x00458C90
void place_terrain_object(RGE_Map* this_, RGE_Player* param_2, RGE_Game_World* param_3, short param_4, short param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::place_terrain_object(class RGE_Player *,class RGE_Game_World *,sh... *
    //                              *********************************************************************************************************
    //                              void __thiscall place_terrain_object(RGE_Map * this, RGE_Player * pa
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     00458d03(R), 00458e57(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     00458c99(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[4]:     00458c93(R), 00458d63(R), 00458eca(R), 00458ef8(R)  
    //              int               Stack[0x14]:4  param_5
    //              int               Stack[0x18]:4  param_6                   XREF[2]:     00458d3d(R), 00458ebb(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00458cd2(W), 00458f98(R)  
    //              int               Stack[-0x8]:4  end_i                     XREF[10]:    00458ed6(W), 00458ede(R), 00458efd(W), 00458f06(R), 
    //                                                                                     00458f18(W), 00458f1f(R), 00458f2c(W), 00458f42(R), 
    //                                                                                     00458f4f(W), 00458f56(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00458cce(W), 00458d1c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00458ca3(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     00458cb8(W)  
    //              int               Stack[-0x18]:4 terrain                   XREF[3]:     00458cd6(W), 00458f90(R), 00458fa2(W)  
    //              int               Stack[-0x1c]:4 i                         XREF[4]:     00458ce5(W), 00458cf3(R), 00458f94(R), 00458fa6(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[7]:     00458d55(W), 00458ed2(W), 00458eda(R), 00458f0f(W), 
    //                                                                                     00458f3a(R), 00458f46(W), 00458f60(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00458d2f(W)  
    //              short             Stack[-0x28]:2 obj_density               XREF[7]:     00458d6f(W), 00458d77(R), 00458d8b(W), 00458e53(R), 
    //                                                                                     00458ef2(W), 00458f3e(W), 00458f6c(R)  
    //              float             Stack[-0x2c]:4 x                         XREF[6]:     00458d6b(W), 00458d73(R), 00458dfd(W), 00458e4f(R), 
    //                                                                                     00458f64(W), 00458f68(R)  
    //              float             Stack[-0x30]:4 y                         XREF[0,1]:   00458d33(W)  
    //              uchar             Stack[-0x31]:1 obj_flag
    //                               ?place_terrain_object@RGE_Map@@QAEXPAVRGE_Player@@PAVRGE_Ga  XREF[2]:     set_terrain:004599cc(c), 
    //                               RGE_Map::place_terrain_object                                             set_terrain_absolute:00459a74(c)  
    //                              map.cpp:2166 (3)
    //         00458c90     SUB        ESP,0x30
    //                              map.cpp:2176 (32)
    //         00458c93     MOV        EAX,dword ptr [ESP + param_4]
    //         00458c97     PUSH       EBX
    //         00458c98     PUSH       EBP
    //         00458c99     MOV        EBP,dword ptr [ESP + param_3]
    //         00458c9d     PUSH       ESI
    //         00458c9e     PUSH       EDI
    //         00458c9f     MOV        EDI,this
    //         00458ca1     PUSH       EBP
    //         00458ca2     PUSH       EAX
    //         00458ca3     MOV        dword ptr [ESP + local_10],EDI
    //         00458ca7     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
    //         00458cac     AND        EAX,0xff
    //         00458cb1     MOV        this,EAX
    //                              map.cpp:2177 (23)
    //         00458cb3     SHL        EAX,0x4
    //         00458cb6     ADD        EAX,this
    //         00458cb8     MOV        dword ptr [ESP + local_14],this
    //         00458cbc     LEA        EDX,[EAX + EAX*0x2]
    //         00458cbf     MOVSX      ESI,word ptr [EDI + EDX*0x8 + 0x220]
    //         00458cc7     LEA        EAX,[EDI + EDX*0x8]
    //                              map.cpp:2179 (33)
    //         00458cca     XOR        EDX,EDX
    //         00458ccc     TEST       ESI,ESI
    //         00458cce     MOV        dword ptr [ESP + local_c],EAX
    //         00458cd2     MOV        dword ptr [ESP + local_4],ESI
    //         00458cd6     MOV        dword ptr [ESP + terrain],EDX
    //         00458cda     JLE        LAB_00458fc6
    //         00458ce0     ADD        EAX,0x18a
    //         00458ce5     MOV        dword ptr [ESP + i],EAX
    //         00458ce9     JMP        LAB_00458cf3
    //                               LAB_00458ceb                                                 XREF[1]:     00458faa(j)  
    //                              map.cpp:2176 (8)
    //         00458ceb     MOV        this,dword ptr [ESP + 0x2c]
    //         00458cef     MOV        EDI,dword ptr [ESP + 0x30]
    //                               LAB_00458cf3                                                 XREF[1]:     00458ce9(j)  
    //                              map.cpp:2181 (7)
    //         00458cf3     MOV        EAX,dword ptr [ESP + i]
    //         00458cf7     MOVSX      EAX,word ptr [EAX]
    //                              map.cpp:2182 (9)
    //         00458cfa     CMP        EAX,-0x1
    //         00458cfd     JZ         LAB_00458f90
    //                              map.cpp:2184 (10)
    //         00458d03     MOV        EBX,dword ptr [ESP + param_1]
    //         00458d07     MOV        ESI,dword ptr [EBX + 0x24]
    //         00458d0a     MOV        ESI,dword ptr [ESI + EAX*0x4]
    //                              map.cpp:2185 (7)
    //         00458d0d     MOV        EAX,this
    //         00458d0f     SHL        EAX,0x4
    //         00458d12     ADD        EAX,this
    //                              map.cpp:2188 (53)
    //         00458d14     TEST       ESI,ESI
    //         00458d16     LEA        this,[EAX + EAX*0x2]
    //         00458d19     LEA        EAX,[EDX + this->_padding_*0x4]
    //         00458d1c     MOV        this,dword ptr [ESP + local_c]
    //         00458d20     MOV        DI,word ptr [EDI + EAX*0x2 + 0x1c6]
    //         00458d28     MOV        DL,byte ptr [EDX + this->_padding_*0x1 + 0x202]
    //         00458d2f     MOV        dword ptr [ESP + local_24],EDI
    //         00458d33     MOV        byte ptr [ESP + y+0x3],DL
    //         00458d37     JZ         LAB_00458f90
    //         00458d3d     MOV        EAX,dword ptr [ESP + param_6]
    //         00458d41     TEST       EAX,EAX
    //         00458d43     JNZ        LAB_00458eb3
    //                              map.cpp:2190 (9)
    //         00458d49     TEST       DI,DI
    //         00458d4c     JLE        LAB_00458f90
    //                              map.cpp:2244 (13)
    //         00458d52     MOVSX      EAX,DI
    //         00458d55     MOV        dword ptr [ESP + local_20],EAX
    //         00458d59     JMP        LAB_00458d5f
    //                               LAB_00458d5b                                                 XREF[1]:     00458ea8(j)  
    //         00458d5b     MOV        DL,byte ptr [ESP + 0x13]
    //                               LAB_00458d5f                                                 XREF[1]:     00458d59(j)  
    //                              map.cpp:2193 (4)
    //         00458d5f     TEST       DL,DL
    //         00458d61     JZ         LAB_00458d91
    //                              map.cpp:2201 (5)
    //         00458d63     MOVSX      this,word ptr [ESP + param_4]
    //                              map.cpp:2202 (39)
    //         00458d68     MOVSX      EDX,BP
    //         00458d6b     MOV        dword ptr [ESP + x],EDX
    //         00458d6f     MOV        dword ptr [ESP + obj_density],this
    //         00458d73     FILD       dword ptr [ESP + x]
    //         00458d77     FILD       dword ptr [ESP + obj_density]
    //         00458d7b     FSUB       float ptr [DAT_005706b0]
    //         00458d81     FXCH
    //         00458d83     FSUB       float ptr [DAT_005706b0]
    //         00458d89     FXCH
    //         00458d8b     FSTP       float ptr [ESP + obj_density]
    //                              map.cpp:2203 (2)
    //         00458d8f     JMP        LAB_00458dfd
    //                               LAB_00458d91                                                 XREF[1]:     00458d61(j)  
    //                              map.cpp:2196 (43)
    //         00458d91     MOVSX      EAX,word ptr [ESP + 0x50]
    //         00458d96     MOV        dword ptr [ESP + 0x18],EAX
    //         00458d9a     PUSH       0x894
    //         00458d9f     FILD       dword ptr [ESP + 0x1c]
    //         00458da3     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458da8     FSTP       float ptr [ESP + 0x1c]
    //         00458dac     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458db1     MOV        dword ptr [ESP + 0x20],EAX
    //         00458db5     ADD        ESP,0x8
    //         00458db8     FILD       dword ptr [ESP + 0x18]
    //                              map.cpp:2197 (69)
    //         00458dbc     MOVSX      this,BP
    //         00458dbf     FMUL       float ptr [DAT_005706b4]
    //         00458dc5     PUSH       0x895
    //         00458dca     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458dcf     FSUBR      float ptr [ESP + 0x1c]
    //         00458dd3     MOV        dword ptr [ESP + 0x1c],this
    //         00458dd7     FSTP       float ptr [ESP + 0x20]
    //         00458ddb     FILD       dword ptr [ESP + 0x1c]
    //         00458ddf     FSTP       float ptr [ESP + 0x40]
    //         00458de3     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458de8     MOV        dword ptr [ESP + 0x1c],EAX
    //         00458dec     ADD        ESP,0x8
    //         00458def     FILD       dword ptr [ESP + 0x14]
    //         00458df3     FMUL       float ptr [DAT_005706b4]
    //         00458df9     FSUBR      float ptr [ESP + 0x38]
    //                               LAB_00458dfd                                                 XREF[1]:     00458d8f(j)  
    //         00458dfd     FSTP       float ptr [ESP + x]
    //                              map.cpp:2207 (7)
    //         00458e01     CMP        DI,0x3e8
    //         00458e06     JL         LAB_00458e0f
    //                              map.cpp:2208 (5)
    //         00458e08     MOV        EAX,0x1
    //                              map.cpp:2209 (2)
    //         00458e0d     JMP        LAB_00458e4b
    //                               LAB_00458e0f                                                 XREF[1]:     00458e06(j)  
    //                              map.cpp:2210 (60)
    //         00458e0f     PUSH       0x8a2
    //         00458e14     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458e19     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458e1e     LEA        EDX,[EAX + EAX*0x2]
    //         00458e21     ADD        ESP,0x8
    //         00458e24     LEA        EAX,[EAX + EDX*0x8]
    //         00458e27     LEA        this,[EAX + EAX*0x4]
    //         00458e2a     MOV        EAX,0x80010003
    //         00458e2f     SHL        this,0x3
    //         00458e32     IMUL       this
    //         00458e34     ADD        EDX,this
    //         00458e36     MOV        this,dword ptr [ESP + 0x20]
    //         00458e3a     SAR        EDX,0xe
    //         00458e3d     MOV        EAX,EDX
    //         00458e3f     SHR        EAX,0x1f
    //         00458e42     ADD        EDX,EAX
    //         00458e44     XOR        EAX,EAX
    //         00458e46     CMP        EDX,this
    //         00458e48     SETL       AL
    //                               LAB_00458e4b                                                 XREF[1]:     00458e0d(j)  
    //                              map.cpp:2212 (44)
    //         00458e4b     TEST       EAX,EAX
    //         00458e4d     JZ         LAB_00458e8d
    //         00458e4f     MOV        EBP,dword ptr [ESP + x]
    //         00458e53     MOV        EBX,dword ptr [ESP + obj_density]
    //         00458e57     MOV        this,dword ptr [ESP + param_1]
    //         00458e5b     PUSH       0x1
    //         00458e5d     MOV        EDI,dword ptr [ESI]
    //         00458e5f     PUSH       0x0=>DAT_fffffff8
    //         00458e61     PUSH       offset DAT_fffffff4
    //         00458e63     PUSH       0x0=>DAT_fffffff0
    //         00458e65     PUSH       0x1
    //         00458e67     PUSH       0x0
    //         00458e69     PUSH       0x0
    //         00458e6b     PUSH       EBP
    //         00458e6c     PUSH       EBX
    //         00458e6d     PUSH       this
    //         00458e6e     MOV        this,ESI
    //         00458e70     CALL       dword ptr [EDI + 0x20]
    //         00458e73     TEST       AL,AL
    //         00458e75     JNZ        LAB_00458e85
    //                              map.cpp:2213 (22)
    //         00458e77     MOV        EDX,dword ptr [ESP + 0x44]
    //         00458e7b     PUSH       0x0
    //         00458e7d     PUSH       EBP=>DAT_fffffff8
    //         00458e7e     PUSH       EBX=>DAT_fffffff4
    //         00458e7f     PUSH       EDX=>DAT_fffffff0
    //         00458e80     MOV        this,ESI
    //         00458e82     CALL       dword ptr [EDI + 0x18]
    //                               LAB_00458e85                                                 XREF[1]:     00458e75(j)  
    //         00458e85     MOV        EDI,dword ptr [ESP + 0x1c]
    //         00458e89     MOV        EBP,dword ptr [ESP + 0x4c]
    //                               LAB_00458e8d                                                 XREF[1]:     00458e4d(j)  
    //                              map.cpp:2215 (33)
    //         00458e8d     MOV        this,dword ptr [ESP + 0x20]
    //         00458e91     SUB        EDI,0x3e8
    //         00458e97     SUB        this,0x3e8
    //         00458e9d     MOV        dword ptr [ESP + 0x1c],EDI
    //         00458ea1     TEST       DI,DI
    //         00458ea4     MOV        dword ptr [ESP + 0x20],this
    //         00458ea8     JG         LAB_00458d5b
    //                              map.cpp:2218 (24)
    //         00458eae     JMP        LAB_00458f90
    //                               LAB_00458eb3                                                 XREF[1]:     00458d43(j)  
    //         00458eb3     TEST       ESI,ESI
    //         00458eb5     JZ         LAB_00458f90
    //         00458ebb     CMP        dword ptr [ESP + param_6],0x1
    //         00458ec0     JNZ        LAB_00458f90
    //                              map.cpp:2220 (4)
    //         00458ec6     TEST       DL,DL
    //         00458ec8     JZ         LAB_00458ef8
    //                              map.cpp:2228 (5)
    //         00458eca     MOVSX      EAX,word ptr [ESP + param_4]
    //                              map.cpp:2229 (39)
    //         00458ecf     MOVSX      this,BP
    //         00458ed2     MOV        dword ptr [ESP + local_20],this
    //         00458ed6     MOV        dword ptr [ESP + end_i],EAX
    //         00458eda     FILD       dword ptr [ESP + local_20]
    //         00458ede     FILD       dword ptr [ESP + end_i]
    //         00458ee2     FSUB       float ptr [DAT_005706b0]
    //         00458ee8     FXCH
    //         00458eea     FSUB       float ptr [DAT_005706b0]
    //         00458ef0     FXCH
    //         00458ef2     FSTP       float ptr [ESP + obj_density]
    //                              map.cpp:2230 (2)
    //         00458ef6     JMP        LAB_00458f64
    //                               LAB_00458ef8                                                 XREF[1]:     00458ec8(j)  
    //                              map.cpp:2223 (43)
    //         00458ef8     MOVSX      EDX,word ptr [ESP + param_4]
    //         00458efd     MOV        dword ptr [ESP + end_i],EDX
    //         00458f01     PUSH       0x8af
    //         00458f06     FILD       dword ptr [ESP + end_i]
    //         00458f0a     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458f0f     FSTP       float ptr [ESP + local_20]
    //         00458f13     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458f18     MOV        dword ptr [ESP + end_i],EAX
    //         00458f1c     ADD        ESP,0x8
    //         00458f1f     FILD       dword ptr [ESP + end_i]
    //                              map.cpp:2224 (69)
    //         00458f23     MOVSX      EAX,BP
    //         00458f26     FMUL       float ptr [DAT_005706b4]
    //         00458f2c     MOV        dword ptr [ESP + end_i],EAX
    //         00458f30     PUSH       0x8b0
    //         00458f35     PUSH       s_C:\msdev\work\age1_x1\map.cpp                  = "C:\\msdev\\work\\age1_x1\\map.cpp"
    //         00458f3a     FSUBR      float ptr [ESP + local_20]
    //         00458f3e     FSTP       float ptr [ESP + obj_density]
    //         00458f42     FILD       dword ptr [ESP + end_i]
    //         00458f46     FSTP       float ptr [ESP + local_20]
    //         00458f4a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00458f4f     MOV        dword ptr [ESP + end_i],EAX
    //         00458f53     ADD        ESP,0x8
    //         00458f56     FILD       dword ptr [ESP + end_i]
    //         00458f5a     FMUL       float ptr [DAT_005706b4]
    //         00458f60     FSUBR      float ptr [ESP + local_20]
    //                               LAB_00458f64                                                 XREF[1]:     00458ef6(j)  
    //         00458f64     FSTP       float ptr [ESP + x]
    //                              map.cpp:2236 (40)
    //         00458f68     MOV        EDI,dword ptr [ESP + x]
    //         00458f6c     MOV        EBP,dword ptr [ESP + obj_density]
    //         00458f70     MOV        EDX,dword ptr [ESI]
    //         00458f72     PUSH       0x1
    //         00458f74     PUSH       0x0
    //         00458f76     PUSH       0x1
    //         00458f78     PUSH       0x0
    //         00458f7a     PUSH       0x1
    //         00458f7c     PUSH       0x0
    //         00458f7e     PUSH       0x0
    //         00458f80     PUSH       EDI
    //         00458f81     PUSH       EBP
    //         00458f82     PUSH       EBX
    //         00458f83     MOV        this,ESI
    //         00458f85     CALL       dword ptr [EDX + 0x20]
    //         00458f88     TEST       AL,AL
    //         00458f8a     JZ         LAB_00458fba
    //         00458f8c     MOV        EBP,dword ptr [ESP + 0x4c]
    //                               LAB_00458f90                                                 XREF[6]:     00458cfd(j), 00458d37(j), 
    //                                                                                                         00458d4c(j), 00458eae(j), 
    //                                                                                                         00458eb5(j), 00458ec0(j)  
    //                              map.cpp:2179 (32)
    //         00458f90     MOV        EDX,dword ptr [ESP + terrain]
    //         00458f94     MOV        this,dword ptr [ESP + i]
    //         00458f98     MOV        EAX,dword ptr [ESP + local_4]
    //         00458f9c     INC        EDX
    //         00458f9d     ADD        this,0x2
    //         00458fa0     CMP        EDX,EAX
    //         00458fa2     MOV        dword ptr [ESP + terrain],EDX
    //         00458fa6     MOV        dword ptr [ESP + i],this
    //         00458faa     JL         LAB_00458ceb
    //                              map.cpp:2244 (10)
    //         00458fb0     POP        EDI
    //         00458fb1     POP        ESI
    //         00458fb2     POP        EBP
    //         00458fb3     POP        EBX
    //         00458fb4     ADD        ESP,0x30
    //         00458fb7     RET        0x18
    //                               LAB_00458fba                                                 XREF[1]:     00458f8a(j)  
    //                              map.cpp:2238 (12)
    //         00458fba     MOV        EAX,dword ptr [ESI]
    //         00458fbc     PUSH       0x0
    //         00458fbe     PUSH       EDI=>DAT_fffffff8
    //         00458fbf     PUSH       EBP=>DAT_fffffff4
    //         00458fc0     PUSH       EBX=>DAT_fffffff0
    //         00458fc1     MOV        this,ESI
    //         00458fc3     CALL       dword ptr [EAX + 0x18]
    //                               LAB_00458fc6                                                 XREF[1]:     00458cda(j)  
    //                              map.cpp:2244 (10)
    //         00458fc6     POP        EDI
    //         00458fc7     POP        ESI
    //         00458fc8     POP        EBP
    //         00458fc9     POP        EBX
    //         00458fca     ADD        ESP,0x30
    //         00458fcd     RET        0x18
}

// Offset: 0x00458FD0
void create_terrain_objects(RGE_Map* this_, RGE_Player* param_2, RGE_Game_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::create_terrain_objects(class RGE_Player *,class RGE_Game_World *)    *
    //                              *********************************************************************************************************
    //                              void __thiscall create_terrain_objects(RGE_Map * this, RGE_Player * 
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     00458fec(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00458fdf(R)  
    //                               ?create_terrain_objects@RGE_Map@@QAEXPAVRGE_Player@@PAVRGE_
    //                               RGE_Map::create_terrain_objects
    //                              map.cpp:2249 (4)
    //         00458fd0     PUSH       EBX
    //         00458fd1     PUSH       EDI
    //         00458fd2     MOV        EDI,this
    //                              map.cpp:2253 (11)
    //         00458fd4     XOR        EBX,EBX
    //         00458fd6     MOV        EAX,dword ptr [EDI + 0xc]
    //         00458fd9     TEST       EAX,EAX
    //         00458fdb     JLE        LAB_0045901b
    //         00458fdd     PUSH       ESI
    //         00458fde     PUSH       EBP
    //                              map.cpp:2254 (13)
    //         00458fdf     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_00458fe3                                                 XREF[1]:     00459017(j)  
    //         00458fe3     MOV        EAX,dword ptr [EDI + 0x8]
    //         00458fe6     XOR        ESI,ESI
    //         00458fe8     TEST       EAX,EAX
    //         00458fea     JLE        LAB_0045900e
    //                               LAB_00458fec                                                 XREF[1]:     0045900c(j)  
    //                              map.cpp:2255 (34)
    //         00458fec     MOV        EAX,dword ptr [ESP + param_1]
    //         00458ff0     PUSH       -0x1
    //         00458ff2     PUSH       -0x1
    //         00458ff4     PUSH       0x0
    //         00458ff6     PUSH       -0x1
    //         00458ff8     PUSH       ESI
    //         00458ff9     PUSH       EBX
    //         00458ffa     PUSH       EBP
    //         00458ffb     PUSH       EAX
    //         00458ffc     MOV        this,EDI
    //         00458ffe     CALL       RGE_Map::create_terrain_object                   void create_terrain_object(RGE_Map * this, RG
    //         00459003     MOV        EAX,dword ptr [EDI + 0x8]
    //         00459006     INC        ESI
    //         00459007     MOVSX      this,SI
    //         0045900a     CMP        this,EAX
    //         0045900c     JL         LAB_00458fec
    //                               LAB_0045900e                                                 XREF[1]:     00458fea(j)  
    //                              map.cpp:2253 (13)
    //         0045900e     MOV        EAX,dword ptr [EDI + 0xc]
    //         00459011     INC        EBX
    //         00459012     MOVSX      EDX,BX
    //         00459015     CMP        EDX,EAX
    //         00459017     JL         LAB_00458fe3
    //         00459019     POP        EBP
    //         0045901a     POP        ESI
    //                               LAB_0045901b                                                 XREF[1]:     00458fdb(j)  
    //                              map.cpp:2256 (5)
    //         0045901b     POP        EDI
    //         0045901c     POP        EBX
    //         0045901d     RET        0x8
}

// Offset: 0x00459020
void set_tile_size(RGE_Map* this_, uchar param_2, short param_3, short param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_tile_size(unsigned char,short,short,short)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_tile_size(RGE_Map * this, uchar param_1, short p
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00459020(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     00459025(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     0045903f(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     00459044(R)  
    //                               ?set_tile_size@RGE_Map@@QAEXEFFF@Z                           XREF[38]:    RGE_Map:0045511d(c), 
    //                               RGE_Map::set_tile_size                                                    RGE_Map:00455138(c), 
    //                                                                                                         RGE_Map:0045515a(c), 
    //                                                                                                         RGE_Map:00455175(c), 
    //                                                                                                         RGE_Map:00455190(c), 
    //                                                                                                         RGE_Map:004551ab(c), 
    //                                                                                                         RGE_Map:004551cd(c), 
    //                                                                                                         RGE_Map:004551e8(c), 
    //                                                                                                         RGE_Map:0045520a(c), 
    //                                                                                                         RGE_Map:00455225(c), 
    //                                                                                                         RGE_Map:00455247(c), 
    //                                                                                                         RGE_Map:00455262(c), 
    //                                                                                                         RGE_Map:0045527d(c), 
    //                                                                                                         RGE_Map:00455298(c), 
    //                                                                                                         RGE_Map:004552ba(c), 
    //                                                                                                         RGE_Map:004552d5(c), 
    //                                                                                                         RGE_Map:004552f0(c), 
    //                                                                                                         RGE_Map:0045530a(c), 
    //                                                                                                         RGE_Map:00455324(c), 
    //                                                                                                         init_tile_sizes:004555a8(c), [more]
    //                              map.cpp:2261 (18)
    //         00459020     MOV        EAX,dword ptr [ESP + param_1]
    //         00459024     PUSH       ESI
    //         00459025     MOV        SI,word ptr [ESP + param_2]
    //         0045902a     AND        EAX,0xff
    //         0045902f     LEA        EDX,[EAX + 0x4]
    //                              map.cpp:2263 (18)
    //         00459032     LEA        EAX,[EAX + EAX*0x2]
    //         00459035     LEA        EDX,[EDX + EDX*0x2]
    //         00459038     LEA        EAX,[this->_padding_ + EAX*0x2]
    //         0045903b     MOV        word ptr [this->_padding_ + EDX*0x2],SI
    //         0045903f     MOV        this,word ptr [ESP + param_3]
    //                              map.cpp:2264 (13)
    //         00459044     MOV        DX,word ptr [ESP + param_4]
    //         00459049     MOV        word ptr [EAX + 0x1a],this
    //         0045904d     MOV        word ptr [EAX + 0x1c],DX
    //                              map.cpp:2265 (4)
    //         00459051     POP        ESI
    //         00459052     RET        0x10
}

// Offset: 0x00459060
void tile_map_coords(RGE_Map* this_, short param_2, short param_3, RGE_Tile* param_4, float* param_5, float* param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::tile_map_coords(short,short,struct RGE_Tile *,float *,float *)       *
    //                              *********************************************************************************************************
    //                              void __thiscall tile_map_coords(RGE_Map * this, short param_1, short
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[9]:     00459063(R), 0045906f(W), 0045907b(R), 00459084(W), 
    //                                                                                     0045908c(R), 00459099(W), 004590ad(R), 004590b1(W), 
    //                                                                                     004590b9(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0045907f(R)  
    //              RGE_Tile *        Stack[0xc]:4   param_3                   XREF[1]:     00459088(R)  
    //              float *           Stack[0x10]:4  param_4                   XREF[1]:     00459330(R)  
    //              float *           Stack[0x14]:4  param_5                   XREF[1]:     0045932c(R)  
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[6]:     004590b5(W), 004590bd(R), 00459143(R), 0045918e(R), 
    //                                                                                     00459280(R), 004592cf(R)  
    //              double            Stack[-0x14]:8 z                         XREF[0,5]:   00459073(*), 004591d0(*), 00459221(*), 0045931a(*), 
    //                                                                                     00459336(*)  
    //                               ?tile_map_coords@RGE_Map@@QAEXFFPAURGE_Tile@@PAM1@Z          XREF[1]:     view_function:00536578(c)  
    //                               RGE_Map::tile_map_coords
    //                              map.cpp:2269 (3)
    //         00459060     SUB        ESP,0x10
    //                              map.cpp:2270 (16)
    //         00459063     MOVSX      EAX,word ptr [ESP + param_1]
    //         00459068     MOVSX      EDX,word ptr [ECX + this->tile_width]
    //         0045906f     MOV        dword ptr [ESP + param_1],EAX
    //                              map.cpp:2272 (21)
    //         00459073     MOV        dword ptr [ESP]=>z+0x4,0x0
    //         0045907b     FILD       dword ptr [ESP + param_1]
    //         0045907f     MOVSX      EAX,word ptr [ESP + param_2]
    //         00459084     MOV        dword ptr [ESP + param_1],EDX
    //                              map.cpp:2274 (70)
    //         00459088     MOV        EDX,dword ptr [ESP + param_3]
    //         0045908c     FILD       dword ptr [ESP + param_1]
    //         00459090     MOVSX      this,word ptr [ECX + this->tile_height]
    //         00459097     FDIVP
    //         00459099     MOV        dword ptr [ESP + param_1],EAX
    //         0045909d     XOR        EAX,EAX
    //         0045909f     MOV        AL,byte ptr [EDX + 0x4]
    //         004590a2     MOV        dword ptr [ESP + Stack[-0xc]],0x0
    //         004590aa     CMP        EAX,0x10
    //         004590ad     FILD       dword ptr [ESP + param_1]
    //         004590b1     MOV        dword ptr [ESP + param_1],this
    //         004590b5     FSTP       double ptr [ESP + local_8]
    //         004590b9     FILD       dword ptr [ESP + param_1]
    //         004590bd     FDIVR      double ptr [ESP + local_8]
    //         004590c1     JA         switchD_004590c7::default
    //                               switchD_004590c7::switchD
    //         004590c7     JMP        dword ptr [EAX*0x4 + switchD_004590c7::switchd   = 00459221
    //                               switchD_004590c7::caseD_1                                    XREF[2]:     004590c7(j), 00459358(*)  
    //                              map.cpp:2280 (15)
    //         004590ce     FLD        ST1
    //         004590d0     FCOMP      double ptr [DAT_005706c0]
    //         004590d6     FNSTSW     AX
    //         004590d8     TEST       AH,0x41
    //         004590db     JNZ        LAB_004590f4
    //                              map.cpp:2281 (18)
    //         004590dd     FLD        ST1
    //         004590df     FSUB       double ptr [DAT_005706c0]
    //         004590e5     FLD        ST1
    //         004590e7     FADD       ST0,ST0
    //         004590e9     FXCH
    //         004590eb     FADD       ST0,ST0
    //         004590ed     FSUBP
    //                              map.cpp:2282 (5)
    //         004590ef     JMP        LAB_0045931a
    //                               LAB_004590f4                                                 XREF[1]:     004590db(j)  
    //                              map.cpp:2283 (18)
    //         004590f4     FLD        double ptr [DAT_005706c0]
    //         004590fa     FSUB       ST0,ST2
    //         004590fc     FLD        ST1
    //         004590fe     FADD       ST0,ST0
    //         00459100     FXCH
    //         00459102     FADD       ST0,ST0
    //         00459104     FSUBP
    //                              map.cpp:2284 (5)
    //         00459106     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_2                                    XREF[2]:     004590c7(j), 0045935c(*)  
    //                              map.cpp:2286 (19)
    //         0045910b     FLD        ST1
    //         0045910d     FCOMP      double ptr [DAT_005706c0]
    //         00459113     FNSTSW     AX
    //         00459115     TEST       AH,0x41
    //         00459118     JNZ        switchD_004590c7::caseD_8
    //                              map.cpp:2287 (24)
    //         0045911e     FLD        ST0
    //         00459120     FLD        ST2
    //         00459122     FXCH
    //         00459124     FSUB       double ptr [DAT_005706c0]
    //         0045912a     FXCH
    //         0045912c     FMUL       double ptr [DAT_005706d0]
    //         00459132     FXCH
    //         00459134     FSUBP
    //                              map.cpp:2288 (5)
    //         00459136     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_3                                    XREF[2]:     004590c7(j), 00459360(*)  
    //                              map.cpp:2292 (12)
    //         0045913b     FLD        ST1
    //         0045913d     FMUL       double ptr [DAT_005706c0]
    //         00459143     FCOMP      double ptr [ESP + local_8]
    //                              map.cpp:2293 (35)
    //         00459147     FLD        double ptr [DAT_005706d8]
    //         0045914d     FSUB       ST0,ST2
    //         0045914f     FLD        ST1
    //         00459151     FNSTSW     AX
    //         00459153     TEST       AH,0x1
    //         00459156     JZ         LAB_0045916f
    //         00459158     FSUB       double ptr [DAT_005706c0]
    //         0045915e     FXCH
    //         00459160     FMUL       double ptr [DAT_005706c0]
    //         00459166     FXCH
    //         00459168     FSUBP
    //                              map.cpp:2294 (5)
    //         0045916a     JMP        LAB_0045931a
    //                               LAB_0045916f                                                 XREF[1]:     00459156(j)  
    //                              map.cpp:2295 (12)
    //         0045916f     FADD       ST0,ST0
    //         00459171     FXCH
    //         00459173     FADD       ST0,ST0
    //         00459175     FSUB       double ptr [DAT_005706d8]
    //                              map.cpp:2296 (5)
    //         0045917b     JMP        LAB_00459318
    //                               switchD_004590c7::caseD_4                                    XREF[2]:     004590c7(j), 00459364(*)  
    //                              map.cpp:2298 (29)
    //         00459180     FLD        double ptr [DAT_005706d8]
    //         00459186     FSUB       ST0,ST2
    //         00459188     FMUL       double ptr [DAT_005706c0]
    //         0045918e     FCOMP      double ptr [ESP + local_8]
    //         00459192     FNSTSW     AX
    //         00459194     TEST       AH,0x1
    //         00459197     JZ         switchD_004590c7::caseD_7
    //                              map.cpp:2299 (22)
    //         0045919d     FLD        ST0
    //         0045919f     FLD        ST2
    //         004591a1     FXCH
    //         004591a3     FSUB       double ptr [DAT_005706c0]
    //         004591a9     FXCH
    //         004591ab     FMUL       double ptr [DAT_005706c0]
    //         004591b1     FXCH
    //                              map.cpp:2356 (2)
    //         004591b3     FSUBP
    //                              map.cpp:2357 (5)
    //         004591b5     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_a                                    XREF[2]:     004590c7(j), 0045937c(*)  
    //                              map.cpp:2319 (13)
    //         004591ba     FCOM       double ptr [DAT_005706d8]
    //         004591c0     FNSTSW     AX
    //         004591c2     TEST       AH,0x1
    //         004591c5     JZ         LAB_004591d0
    //                              map.cpp:2320 (4)
    //         004591c7     FLD        ST0
    //         004591c9     FCHS
    //                              map.cpp:2321 (5)
    //         004591cb     JMP        LAB_0045931a
    //                               LAB_004591d0                                                 XREF[1]:     004591c5(j)  
    //                              map.cpp:2322 (16)
    //         004591d0     MOV        dword ptr [ESP]=>z+0x4,0x0
    //         004591d8     MOV        dword ptr [ESP + Stack[-0xc]],0xbff00000
    //                              map.cpp:2323 (5)
    //         004591e0     JMP        switchD_004590c7::default
    //                               switchD_004590c7::caseD_b                                    XREF[2]:     004590c7(j), 00459380(*)  
    //                              map.cpp:2325 (13)
    //         004591e5     FLD        ST1
    //         004591e7     FCOMP      double ptr [DAT_005706c0]
    //         004591ed     FNSTSW     AX
    //         004591ef     TEST       AH,0x41
    //                              map.cpp:2327 (2)
    //         004591f2     JZ         switchD_004590c7::caseD_0
    //                              map.cpp:2328 (10)
    //         004591f4     FLD        double ptr [DAT_005706c0]
    //         004591fa     FSUB       ST0,ST2
    //         004591fc     FADD       ST0,ST0
    //                              map.cpp:2329 (5)
    //         004591fe     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_c                                    XREF[2]:     004590c7(j), 00459384(*)  
    //                              map.cpp:2331 (15)
    //         00459203     FLD        ST1
    //         00459205     FCOMP      double ptr [DAT_005706c0]
    //         0045920b     FNSTSW     AX
    //         0045920d     TEST       AH,0x41
    //         00459210     JNZ        switchD_004590c7::caseD_0
    //                              map.cpp:2332 (10)
    //         00459212     FLD        ST1
    //         00459214     FSUB       double ptr [DAT_005706c0]
    //         0045921a     FADD       ST0,ST0
    //                              map.cpp:2333 (5)
    //         0045921c     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_9                                    XREF[5]:     004590c7(j), 004591f2(j), 
    //                               switchD_004590c7::caseD_0                                                 00459210(j), 00459354(*), 
    //                                                                                                         00459378(*)  
    //                              map.cpp:2334 (16)
    //         00459221     MOV        dword ptr [ESP]=>z+0x4,0x0
    //         00459229     MOV        dword ptr [ESP + Stack[-0xc]],0x0
    //                              map.cpp:2335 (5)
    //         00459231     JMP        switchD_004590c7::default
    //                               switchD_004590c7::caseD_d                                    XREF[2]:     004590c7(j), 00459388(*)  
    //                              map.cpp:2337 (15)
    //         00459236     FLD        ST1
    //         00459238     FCOMP      double ptr [DAT_005706c0]
    //         0045923e     FNSTSW     AX
    //         00459240     TEST       AH,0x41
    //         00459243     JNZ        LAB_00459256
    //                              map.cpp:2338 (12)
    //         00459245     FLD        ST1
    //         00459247     FSUB       double ptr [DAT_005706c0]
    //         0045924d     FADD       ST0,ST1
    //         0045924f     FADD       ST0,ST0
    //                              map.cpp:2339 (5)
    //         00459251     JMP        LAB_0045931a
    //                               LAB_00459256                                                 XREF[1]:     00459243(j)  
    //                              map.cpp:2340 (12)
    //         00459256     FLD        double ptr [DAT_005706c0]
    //         0045925c     FSUB       ST0,ST2
    //         0045925e     FADD       ST0,ST1
    //         00459260     FADD       ST0,ST0
    //                              map.cpp:2341 (5)
    //         00459262     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_e                                    XREF[2]:     004590c7(j), 0045938c(*)  
    //                              map.cpp:2343 (15)
    //         00459267     FLD        ST1
    //         00459269     FCOMP      double ptr [DAT_005706c0]
    //         0045926f     FNSTSW     AX
    //         00459271     TEST       AH,0x41
    //         00459274     JNZ        switchD_004590c7::caseD_6
    //                              map.cpp:2345 (2)
    //         00459276     JMP        switchD_004590c7::caseD_8
    //                               switchD_004590c7::caseD_f                                    XREF[2]:     004590c7(j), 00459390(*)  
    //                              map.cpp:2349 (31)
    //         00459278     FLD        ST1
    //         0045927a     FMUL       double ptr [DAT_005706c0]
    //         00459280     FLD        double ptr [ESP + local_8]
    //         00459284     FXCH
    //         00459286     FSUBR      double ptr [DAT_005706d8]
    //         0045928c     FXCH
    //         0045928e     FCOMPP
    //         00459290     FNSTSW     AX
    //         00459292     TEST       AH,0x41
    //         00459295     JNZ        switchD_004590c7::caseD_7
    //                               switchD_004590c7::caseD_8                                    XREF[4]:     004590c7(j), 00459118(j), 
    //                                                                                                         00459276(j), 00459374(*)  
    //                              map.cpp:2350 (28)
    //         00459297     FLD        double ptr [DAT_005706d8]
    //         0045929d     FSUB       ST0,ST2
    //         0045929f     FLD        ST1
    //         004592a1     FSUB       double ptr [DAT_005706c0]
    //         004592a7     FXCH
    //         004592a9     FMUL       double ptr [DAT_005706d0]
    //         004592af     FXCH
    //         004592b1     FSUBP
    //                              map.cpp:2351 (2)
    //         004592b3     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_7                                    XREF[4]:     004590c7(j), 00459197(j), 
    //                                                                                                         00459295(j), 00459370(*)  
    //                              map.cpp:2352 (16)
    //         004592b5     FLD        ST1
    //         004592b7     FADD       ST0,ST0
    //         004592b9     FLD        ST1
    //         004592bb     FADD       ST0,ST0
    //         004592bd     FXCH
    //         004592bf     FSUB       double ptr [DAT_005706d8]
    //                              map.cpp:2353 (2)
    //         004592c5     JMP        LAB_00459318
    //                               switchD_004590c7::caseD_10                                   XREF[2]:     004590c7(j), 00459394(*)  
    //                              map.cpp:2355 (37)
    //         004592c7     FLD        double ptr [DAT_005706d8]
    //         004592cd     FSUB       ST0,ST2
    //         004592cf     FLD        double ptr [ESP + local_8]
    //         004592d3     FXCH
    //         004592d5     FMUL       double ptr [DAT_005706c0]
    //         004592db     FSUBR      double ptr [DAT_005706d8]
    //         004592e1     FXCH
    //         004592e3     FCOMPP
    //         004592e5     FNSTSW     AX
    //         004592e7     TEST       AH,0x41
    //         004592ea     JNZ        switchD_004590c7::caseD_5
    //                               switchD_004590c7::caseD_6                                    XREF[3]:     004590c7(j), 00459274(j), 
    //                                                                                                         0045936c(*)  
    //                              map.cpp:2356 (24)
    //         004592ec     FLD        ST0
    //         004592ee     FLD        ST2
    //         004592f0     FXCH
    //         004592f2     FSUB       double ptr [DAT_005706c0]
    //         004592f8     FXCH
    //         004592fa     FMUL       double ptr [DAT_005706d0]
    //         00459300     FXCH
    //         00459302     FSUBP
    //                              map.cpp:2357 (2)
    //         00459304     JMP        LAB_0045931a
    //                               switchD_004590c7::caseD_5                                    XREF[3]:     004590c7(j), 004592ea(j), 
    //                                                                                                         00459368(*)  
    //                              map.cpp:2358 (24)
    //         00459306     FLD        ST1
    //         00459308     FADD       ST0,ST0
    //         0045930a     FLD        ST1
    //         0045930c     FADD       ST0,ST0
    //         0045930e     FXCH
    //         00459310     FSUBR      double ptr [DAT_005706d8]
    //         00459316     FXCH
    //                               LAB_00459318                                                 XREF[2]:     0045917b(j), 004592c5(j)  
    //         00459318     FADDP
    //                               LAB_0045931a                                                 XREF[12]:    004590ef(j), 00459106(j), 
    //                                                                                                         00459136(j), 0045916a(j), 
    //                                                                                                         004591b5(j), 004591cb(j), 
    //                                                                                                         004591fe(j), 0045921c(j), 
    //                                                                                                         00459251(j), 00459262(j), 
    //                                                                                                         004592b3(j), 00459304(j)  
    //         0045931a     FSTP       double ptr [ESP]=>z+0x4
    //                               switchD_004590c7::default                                    XREF[3]:     004590c1(j), 004591e0(j), 
    //                                                                                                         00459231(j)  
    //                              map.cpp:2362 (14)
    //         0045931e     FADD       ST0,ST0
    //         00459320     FXCH
    //         00459322     FADD       ST0,ST0
    //         00459324     FXCH
    //         00459326     FSUBR      double ptr [DAT_005706d8]
    //                              map.cpp:2363 (32)
    //         0045932c     MOV        EAX,dword ptr [ESP + param_5]
    //         00459330     MOV        this,dword ptr [ESP + param_4]
    //         00459334     FSUBR      ST0,ST1
    //         00459336     FADD       double ptr [ESP]=>z+0x4
    //         0045933a     FMUL       double ptr [DAT_005706c0]
    //         00459340     FLD        ST0
    //         00459342     FSUBR      ST0,ST2
    //         00459344     FXCH
    //         00459346     FSTP       float ptr [EAX]
    //         00459348     FSTP       float ptr [this->_padding_]
    //         0045934a     FSTP       ST0
    //                              map.cpp:2364 (76)
    //         0045934c     ADD        ESP,0x10
    //         0045934f     RET        0x14
}

// Offset: 0x00459352
undefined FUN_00459352() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00459352()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00459352
    //         00459352     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004590c7::switchdataD_00459354                       XREF[1]:     tile_map_coords:004590c7(*)  
}

// Offset: 0x004593A0
uchar check_map_coords(RGE_Map* this_, short param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Map::check_map_coords(short,short)                               *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_map_coords(RGE_Map * this, short param_1, sho
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004593a0(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     004593b4(R)  
    //                               ?check_map_coords@RGE_Map@@QAEEFF@Z
    //                               RGE_Map::check_map_coords
    //                              map.cpp:2368 (38)
    //         004593a0     MOV        AX,word ptr [ESP + param_1]
    //         004593a5     TEST       AX,AX
    //         004593a8     JL         LAB_004593cb
    //         004593aa     MOV        EDX,dword ptr [ECX + this->map_width]
    //         004593ad     MOVSX      EAX,AX
    //         004593b0     CMP        EAX,EDX
    //         004593b2     JGE        LAB_004593cb
    //         004593b4     MOV        AX,word ptr [ESP + param_2]
    //         004593b9     TEST       AX,AX
    //         004593bc     JL         LAB_004593cb
    //         004593be     MOVSX      EDX,AX
    //         004593c1     CMP        EDX,dword ptr [ECX + this->map_height]
    //         004593c4     JGE        LAB_004593cb
    //                              map.cpp:2370 (2)
    //         004593c6     MOV        AL,0x1
    //                              map.cpp:2373 (3)
    //         004593c8     RET        0x8
    //                               LAB_004593cb                                                 XREF[4]:     004593a8(j), 004593b2(j), 
    //                                                                                                         004593bc(j), 004593c4(j)  
    //                              map.cpp:2372 (2)
    //         004593cb     XOR        AL,AL
    //                              map.cpp:2373 (3)
    //         004593cd     RET        0x8
}

// Offset: 0x004593D0
uchar get_elev(RGE_Map* this_, short param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Map::get_elev(short,short)                                       *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_elev(RGE_Map * this, short param_1, short param
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004593d5(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     004593d0(R)  
    //                               ?get_elev@RGE_Map@@QAEEFF@Z
    //                               RGE_Map::get_elev
    //                              map.cpp:2377 (29)
    //         004593d0     MOVSX      EDX,word ptr [ESP + param_2]
    //         004593d5     MOVSX      EAX,word ptr [ESP + param_1]
    //         004593da     MOV        this,dword ptr [ECX + this->map_row_offset]
    //         004593e0     LEA        EAX,[EAX + EAX*0x2]
    //         004593e3     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         004593e6     MOV        AL,byte ptr [ECX + EAX*0x8 + this+0x5]
    //         004593ea     SHR        AL,0x5
    //                              map.cpp:2381 (4)
    //         004593ed     CMP        AL,0x8
    //         004593ef     JBE        LAB_004593f3
    //                              map.cpp:2382 (2)
    //         004593f1     XOR        AL,AL
    //                               LAB_004593f3                                                 XREF[1]:     004593ef(j)  
    //                              map.cpp:2385 (3)
    //         004593f3     RET        0x8
}

// Offset: 0x00459400
uchar get_terrain(RGE_Map* this_, short param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Map::get_terrain(short,short)                                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_terrain(RGE_Map * this, short param_1, short pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00459405(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00459400(R), 0045941f(W), 00459425(R)  
    //                               ?get_terrain@RGE_Map@@QAEEFF@Z                               XREF[15]:    update:004070a3(c), 
    //                               RGE_Map::get_terrain                                                      update:004070c0(c), 
    //                                                                                                         next_to_drop_off_terrain:004073d2(
    //                                                                                                         next_to_drop_off_terrain:004073df(
    //                                                                                                         create_terrain_object:00458843(c), 
    //                                                                                                         clear_terrain_object:00458b53(c), 
    //                                                                                                         place_terrain_object:00458ca7(c), 
    //                                                                                                         firstTileAlongLine:00460840(c), 
    //                                                                                                         reposition_artifact:004cad8f(c), 
    //                                                                                                         reposition_artifact:004cade8(c), 
    //                                                                                                         reposition_artifact:004cae7e(c), 
    //                                                                                                         reposition_artifact:004caed7(c), 
    //                                                                                                         setupInfluenceMap:004dfa78(c), 
    //                                                                                                         get_target_task:00509296(c), 
    //                                                                                                         findClosestPointInTerrainType:0054
    //                              map.cpp:2389 (29)
    //         00459400     MOVSX      EDX,word ptr [ESP + param_2]
    //         00459405     MOVSX      EAX,word ptr [ESP + param_1]
    //         0045940a     PUSH       ESI
    //         0045940b     MOV        ESI,dword ptr [ECX + this->map_row_offset]
    //         00459411     LEA        EAX,[EAX + EAX*0x2]
    //         00459414     MOV        EDX,dword ptr [ESI + EDX*0x4]
    //         00459417     MOV        AL,byte ptr [EDX + EAX*0x8 + 0x5]
    //         0045941b     AND        AL,0x1f
    //                              map.cpp:2393 (6)
    //         0045941d     CMP        AL,0x20
    //         0045941f     MOV        byte ptr [ESP + param_2],AL
    //                              map.cpp:2395 (2)
    //         00459423     JA         LAB_00459450
    //                              map.cpp:2396 (43)
    //         00459425     MOV        ESI,dword ptr [ESP + param_2]
    //         00459429     AND        ESI,0xff
    //         0045942f     MOV        EDX,ESI
    //         00459431     SHL        EDX,0x4
    //         00459434     ADD        EDX,ESI
    //         00459436     LEA        EDX,[EDX + EDX*0x2]
    //         00459439     LEA        this,[this->_padding_ + EDX*0x8]
    //         0045943c     MOV        DL,byte ptr [ECX + this->terrain_types[0].load
    //         00459442     TEST       DL,DL
    //         00459444     JNZ        LAB_00459452
    //         00459446     CMP        word ptr [ECX + this+0x144],0x0
    //         0045944e     JGE        LAB_00459452
    //                               LAB_00459450                                                 XREF[1]:     00459423(j)  
    //                              map.cpp:2397 (2)
    //         00459450     XOR        AL,AL
    //                               LAB_00459452                                                 XREF[2]:     00459444(j), 0045944e(j)  
    //                              map.cpp:2400 (4)
    //         00459452     POP        ESI
    //         00459453     RET        0x8
}

// Offset: 0x00459460
uchar get_border(RGE_Map* this_, short param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Map::get_border(short,short)                                     *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_border(RGE_Map * this, short param_1, short par
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00459465(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00459460(R), 00459480(W), 00459486(R)  
    //                               ?get_border@RGE_Map@@QAEEFF@Z
    //                               RGE_Map::get_border
    //                              map.cpp:2405 (30)
    //         00459460     MOVSX      EDX,word ptr [ESP + param_2]
    //         00459465     MOVSX      EAX,word ptr [ESP + param_1]
    //         0045946a     PUSH       EBX
    //         0045946b     PUSH       ESI
    //         0045946c     MOV        ESI,dword ptr [ECX + this->map_row_offset]
    //         00459472     LEA        EAX,[EAX + EAX*0x2]
    //         00459475     MOV        EDX,dword ptr [ESI + EDX*0x4]
    //         00459478     MOV        AL,byte ptr [EDX + EAX*0x8 + 0x6]
    //         0045947c     AND        AL,0xf
    //                              map.cpp:2409 (6)
    //         0045947e     CMP        AL,0x10
    //         00459480     MOV        byte ptr [ESP + param_2],AL
    //                              map.cpp:2411 (2)
    //         00459484     JA         LAB_004594a4
    //                              map.cpp:2412 (30)
    //         00459486     MOV        EDX,dword ptr [ESP + param_2]
    //         0045948a     AND        EDX,0xff
    //         00459490     LEA        EDX,[EDX + EDX*0x4]
    //         00459493     LEA        EDX,[EDX + EDX*0x8]
    //         00459496     SHL        EDX,0x5
    //         00459499     MOV        BL,byte ptr [EDX + this->_padding_*0x1 + 0x338c]
    //         004594a0     TEST       BL,BL
    //         004594a2     JNZ        LAB_004594a6
    //                               LAB_004594a4                                                 XREF[1]:     00459484(j)  
    //                              map.cpp:2413 (2)
    //         004594a4     XOR        AL,AL
    //                               LAB_004594a6                                                 XREF[1]:     004594a2(j)  
    //                              map.cpp:2416 (5)
    //         004594a6     POP        ESI
    //         004594a7     POP        EBX
    //         004594a8     RET        0x8
}

// Offset: 0x004594B0
void set_terrain_passablity(RGE_Map* this_, short param_2, short param_3, short param_4, short param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_terrain_passablity(short,short,short,short,unsigned char)        *
    //                              *********************************************************************************************************
    //                              void __thiscall set_terrain_passablity(RGE_Map * this, short param_1
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[4]:     004594ca(R), 004594e1(W), 00459503(W), 004595b5(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[5]:     004594b8(R), 00459534(W), 0045955a(R), 004595bd(R), 
    //                                                                                     004595c9(W)  
    //              short             Stack[0xc]:2   param_3                   XREF[4]:     004594ce(R), 004594dd(W), 00459517(W), 004595b9(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[4]:     004594b1(R), 00459550(W), 004595aa(R), 004595af(W)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00459570(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00459538(W), 004595c1(R), 004595cd(W)  
    //                               ?set_terrain_passablity@RGE_Map@@QAEXFFFFE@Z
    //                               RGE_Map::set_terrain_passablity
    //                              map.cpp:2420 (1)
    //         004594b0     PUSH       this
    //                              map.cpp:2427 (19)
    //         004594b1     MOV        EDX,dword ptr [ESP + param_4]
    //         004594b5     PUSH       EBX
    //         004594b6     PUSH       EBP
    //         004594b7     PUSH       ESI
    //         004594b8     MOV        ESI,dword ptr [ESP + param_2]
    //         004594bc     PUSH       EDI
    //         004594bd     CMP        SI,DX
    //         004594c0     MOV        EBP,this
    //         004594c2     JLE        LAB_004594ca
    //                              map.cpp:2429 (2)
    //         004594c4     MOV        EAX,EDX
    //                              map.cpp:2430 (2)
    //         004594c6     MOV        EDX,ESI
    //                              map.cpp:2431 (2)
    //         004594c8     MOV        ESI,EAX
    //                               LAB_004594ca                                                 XREF[1]:     004594c2(j)  
    //                              map.cpp:2434 (13)
    //         004594ca     MOV        this,dword ptr [ESP + param_1]
    //         004594ce     MOV        EAX,dword ptr [ESP + param_3]
    //         004594d2     CMP        this,AX
    //         004594d5     JLE        LAB_004594e5
    //                              map.cpp:2436 (2)
    //         004594d7     MOV        EDI,EAX
    //                              map.cpp:2437 (2)
    //         004594d9     MOV        EAX,this
    //                              map.cpp:2438 (10)
    //         004594db     MOV        this,EDI
    //         004594dd     MOV        dword ptr [ESP + param_3],EAX
    //         004594e1     MOV        dword ptr [ESP + param_1],this
    //                               LAB_004594e5                                                 XREF[1]:     004594d5(j)  
    //                              map.cpp:2442 (5)
    //         004594e5     TEST       SI,SI
    //         004594e8     JGE        LAB_004594ec
    //                              map.cpp:2443 (2)
    //         004594ea     XOR        ESI,ESI
    //                               LAB_004594ec                                                 XREF[1]:     004594e8(j)  
    //                              map.cpp:2444 (10)
    //         004594ec     MOV        EBX,dword ptr [EBP + 0xc]
    //         004594ef     MOVSX      EDI,DX
    //         004594f2     CMP        EDI,EBX
    //         004594f4     JL         LAB_004594fc
    //                              map.cpp:2445 (6)
    //         004594f6     MOV        DX,word ptr [EBP + 0xc]
    //         004594fa     DEC        DX
    //                               LAB_004594fc                                                 XREF[1]:     004594f4(j)  
    //                              map.cpp:2446 (5)
    //         004594fc     TEST       this,this
    //         004594ff     JGE        LAB_00459507
    //                              map.cpp:2447 (6)
    //         00459501     XOR        this,this
    //         00459503     MOV        dword ptr [ESP + param_1],this
    //                               LAB_00459507                                                 XREF[1]:     004594ff(j)  
    //                              map.cpp:2448 (10)
    //         00459507     MOV        EBX,dword ptr [EBP + 0x8]
    //         0045950a     MOVSX      EDI,AX
    //         0045950d     CMP        EDI,EBX
    //         0045950f     JL         LAB_0045951b
    //                              map.cpp:2449 (10)
    //         00459511     MOV        AX,word ptr [EBP + 0x8]
    //         00459515     DEC        AX
    //         00459517     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_0045951b                                                 XREF[1]:     0045950f(j)  
    //                              map.cpp:2451 (33)
    //         0045951b     CMP        SI,DX
    //         0045951e     JG         LAB_004595d7
    //         00459524     MOVSX      ESI,SI
    //         00459527     MOVSX      EDX,DX
    //         0045952a     SUB        EDX,ESI
    //         0045952c     LEA        EDI,[ESI*0x4 + 0x0]
    //         00459533     INC        EDX
    //         00459534     MOV        dword ptr [ESP + param_2],EDI
    //         00459538     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_0045953c                                                 XREF[1]:     004595d1(j)  
    //                              map.cpp:2452 (24)
    //         0045953c     CMP        this,AX
    //         0045953f     JG         LAB_004595bd
    //         00459541     MOVSX      EDX,this
    //         00459544     MOVSX      EAX,AX
    //         00459547     LEA        this,[EDX + EDX*0x2]
    //         0045954a     SUB        EAX,EDX
    //         0045954c     SHL        this,0x3
    //         0045954f     INC        EAX
    //         00459550     MOV        dword ptr [ESP + param_4],EAX
    //                               LAB_00459554                                                 XREF[1]:     004595b3(j)  
    //                              map.cpp:2454 (13)
    //         00459554     MOV        EAX,dword ptr [EBP + 0x8d8c]
    //         0045955a     MOV        EDX,dword ptr [ESP + param_2]
    //         0045955e     MOV        EAX,dword ptr [EAX + EDX*0x1]
    //                              map.cpp:2455 (15)
    //         00459561     MOV        DL,byte ptr [EAX + this->_padding_*0x1 + 0x5]
    //         00459565     ADD        EAX,this
    //         00459567     MOV        BL,DL
    //         00459569     AND        BL,0x1f
    //         0045956c     MOVZX      SI,BL
    //                              map.cpp:2457 (4)
    //         00459570     MOV        BL,byte ptr [ESP + param_5]
    //                              map.cpp:2458 (24)
    //         00459574     MOVSX      EDI,SI
    //         00459577     TEST       BL,BL
    //         00459579     MOV        ESI,EDI
    //         0045957b     JZ         LAB_0045958e
    //         0045957d     SHL        ESI,0x4
    //         00459580     ADD        ESI,EDI
    //         00459582     LEA        ESI,[ESI + ESI*0x2]
    //         00459585     MOV        BL,byte ptr [EBP + ESI*0x8 + 0xb9]
    //                              map.cpp:2459 (2)
    //         0045958c     JMP        LAB_0045959d
    //                               LAB_0045958e                                                 XREF[1]:     0045957b(j)  
    //                              map.cpp:2460 (73)
    //         0045958e     SHL        ESI,0x4
    //         00459591     ADD        ESI,EDI
    //         00459593     LEA        ESI,[ESI + ESI*0x2]
    //         00459596     MOV        BL,byte ptr [EBP + ESI*0x8 + 0xba]
    //                               LAB_0045959d                                                 XREF[1]:     0045958c(j)  
    //         0045959d     XOR        BL,DL
    //         0045959f     ADD        this,0x18
    //         004595a2     AND        BL,0x1f
    //         004595a5     XOR        BL,DL
    //         004595a7     MOV        byte ptr [EAX + 0x5],BL
    //         004595aa     MOV        EAX,dword ptr [ESP + param_4]
    //         004595ae     DEC        EAX
    //         004595af     MOV        dword ptr [ESP + param_4],EAX
    //         004595b3     JNZ        LAB_00459554
    //         004595b5     MOV        this,dword ptr [ESP + param_1]
    //         004595b9     MOV        EAX,dword ptr [ESP + param_3]
    //                               LAB_004595bd                                                 XREF[1]:     0045953f(j)  
    //         004595bd     MOV        ESI,dword ptr [ESP + param_2]
    //         004595c1     MOV        EDX,dword ptr [ESP + local_4]
    //         004595c5     ADD        ESI,0x4
    //         004595c8     DEC        EDX
    //         004595c9     MOV        dword ptr [ESP + param_2],ESI
    //         004595cd     MOV        dword ptr [ESP + local_4],EDX
    //         004595d1     JNZ        LAB_0045953c
    //                               LAB_004595d7                                                 XREF[1]:     0045951e(j)  
    //                              map.cpp:2462 (8)
    //         004595d7     POP        EDI
    //         004595d8     POP        ESI
    //         004595d9     POP        EBP
    //         004595da     POP        EBX
    //         004595db     POP        this
    //         004595dc     RET        0x14
}

// Offset: 0x004595E0
void set_elev(RGE_Map* this_, short param_2, short param_3, short param_4, short param_5, uchar param_6, short param_7, uchar param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_elev(short,short,short,short,unsigned char,short,unsigned char)  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_elev(RGE_Map * this, short param_1, short param_
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[7]:     00459612(R), 0045961f(W), 00459629(R), 00459653(W), 
    //                                                                                     00459717(R), 00459796(R), 004597d0(W)  
    //              short             Stack[0x8]:2   param_2                   XREF[8]:     004595f9(R), 0045960e(W), 0045962f(R), 00459636(W), 
    //                                                                                     00459686(R), 00459739(R), 004597a8(R), 004597b6(W)  
    //              short             Stack[0xc]:2   param_3                   XREF[6]:     00459616(R), 00459623(W), 00459669(W), 00459713(R), 
    //                                                                                     00459792(R), 004597e0(W)  
    //              short             Stack[0x10]:2  param_4                   XREF[8]:     00459601(R), 0045960a(W), 0045963a(R), 0045964a(W), 
    //                                                                                     0045968a(R), 0045973d(R), 004597ac(R), 004597c6(W)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[9]:     004596a7(W), 0045971b(R), 00459723(W), 0045972b(R), 
    //                                                                                     00459735(W), 0045975f(R), 0045980b(W), 00459866(R), 
    //                                                                                     004598d4(W)  
    //              short             Stack[0x18]:2  param_6                   XREF[4]:     0045967b(R), 004596d6(R), 004597f4(W), 00459862(R)  
    //              uchar             Stack[0x1c]:1  param_7                   XREF[6]:     0045966f(R), 00459756(W), 0045979a(R), 004597a2(W), 
    //                                                                                     004597e7(W), 00459820(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004595fd(W), 0045986a(R)  
    //              RGE_Player *      Stack[-0x8]:4  cur_player                XREF[2]:     004597fb(W), 0045981c(R)  
    //                               ?set_elev@RGE_Map@@QAEXFFFFEFE@Z                             XREF[4]:     scenario_load:0045610e(c), 
    //                               RGE_Map::set_elev                                                         clean_elevation:00456e77(c), 
    //                                                                                                         key_down_action:0048a436(c), 
    //                                                                                                         key_down_action:0048a4b8(c)  
    //                              map.cpp:2466 (8)
    //         004595e0     SUB        ESP,0x8
    //         004595e3     PUSH       EBX
    //         004595e4     MOV        EBX,this
    //         004595e6     PUSH       EBP
    //         004595e7     PUSH       ESI
    //                              map.cpp:2472 (17)
    //         004595e8     MOV        EAX,dword ptr [EBX + 0x8dc0]
    //         004595ee     PUSH       EDI
    //         004595ef     MOVSX      this,word ptr [EAX + 0x7c]
    //         004595f3     MOV        EDX,dword ptr [EAX + 0x40]
    //         004595f6     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
    //                              map.cpp:2475 (17)
    //         004595f9     MOV        this,dword ptr [ESP + param_2]
    //         004595fd     MOV        dword ptr [ESP + local_4],EAX
    //         00459601     MOV        EAX,dword ptr [ESP + param_4]
    //         00459605     CMP        this,AX
    //         00459608     JLE        LAB_00459612
    //                              map.cpp:2478 (4)
    //         0045960a     MOV        dword ptr [ESP + param_4],this
    //                              map.cpp:2479 (4)
    //         0045960e     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_00459612                                                 XREF[1]:     00459608(j)  
    //                              map.cpp:2482 (13)
    //         00459612     MOV        EDI,dword ptr [ESP + param_1]
    //         00459616     MOV        EDX,dword ptr [ESP + param_3]
    //         0045961a     CMP        DI,DX
    //         0045961d     JLE        LAB_0045962d
    //                              map.cpp:2486 (14)
    //         0045961f     MOV        dword ptr [ESP + param_1],EDX
    //         00459623     MOV        dword ptr [ESP + param_3],EDI
    //         00459627     MOV        EDX,EDI
    //         00459629     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_0045962d                                                 XREF[1]:     0045961d(j)  
    //                              map.cpp:2490 (9)
    //         0045962d     XOR        this,this
    //         0045962f     CMP        word ptr [ESP + param_2],this
    //         00459634     JGE        LAB_0045963a
    //                              map.cpp:2491 (4)
    //         00459636     MOV        dword ptr [ESP + param_2],this
    //                               LAB_0045963a                                                 XREF[1]:     00459634(j)  
    //                              map.cpp:2492 (10)
    //         0045963a     MOVSX      EAX,word ptr [ESP + param_4]
    //         0045963f     CMP        EAX,dword ptr [EBX + 0xc]
    //         00459642     JL         LAB_0045964e
    //                              map.cpp:2493 (10)
    //         00459644     MOV        AX,word ptr [EBX + 0xc]
    //         00459648     DEC        AX
    //         0045964a     MOV        dword ptr [ESP + param_4],EAX
    //                               LAB_0045964e                                                 XREF[1]:     00459642(j)  
    //                              map.cpp:2494 (5)
    //         0045964e     CMP        DI,this
    //         00459651     JGE        LAB_00459659
    //                              map.cpp:2495 (6)
    //         00459653     MOV        dword ptr [ESP + param_1],this
    //         00459657     MOV        EDI,this
    //                               LAB_00459659                                                 XREF[1]:     00459651(j)  
    //                              map.cpp:2496 (10)
    //         00459659     MOV        ESI,dword ptr [EBX + 0x8]
    //         0045965c     MOVSX      EAX,DX
    //         0045965f     CMP        EAX,ESI
    //         00459661     JL         LAB_0045966f
    //                              map.cpp:2497 (12)
    //         00459663     MOV        AX,word ptr [EBX + 0x8]
    //         00459667     DEC        AX
    //         00459669     MOV        dword ptr [ESP + param_3],EAX
    //         0045966d     MOV        EDX,EAX
    //                               LAB_0045966f                                                 XREF[1]:     00459661(j)  
    //                              map.cpp:2500 (12)
    //         0045966f     MOV        AL,byte ptr [ESP + param_7]
    //         00459673     TEST       AL,AL
    //         00459675     JZ         LAB_004597a8
    //                              map.cpp:2502 (11)
    //         0045967b     CMP        word ptr [ESP + param_6],this
    //         00459680     JZ         LAB_0045972b
    //                              map.cpp:2503 (17)
    //         00459686     MOV        EAX,dword ptr [ESP + param_2]
    //         0045968a     MOV        this,dword ptr [ESP + param_4]
    //         0045968e     CMP        AX,this
    //         00459691     JG         LAB_004597b0
    //                              map.cpp:2557 (20)
    //         00459697     MOVSX      EAX,AX
    //         0045969a     MOVSX      this,this
    //         0045969d     SUB        this,EAX
    //         0045969f     LEA        EBP,[EAX*0x4 + 0x0]
    //         004596a6     INC        this
    //         004596a7     MOV        dword ptr [ESP + param_5],this
    //                               LAB_004596ab                                                 XREF[1]:     00459727(j)  
    //                              map.cpp:2504 (20)
    //         004596ab     CMP        DI,DX
    //         004596ae     JG         LAB_0045971b
    //         004596b0     MOVSX      EAX,DI
    //         004596b3     MOVSX      EDI,DX
    //         004596b6     LEA        ESI,[EAX + EAX*0x2]
    //         004596b9     SUB        EDI,EAX
    //         004596bb     SHL        ESI,0x3
    //         004596be     INC        EDI
    //                               LAB_004596bf                                                 XREF[1]:     00459711(j)  
    //                              map.cpp:2506 (6)
    //         004596bf     MOV        this,dword ptr [EBX + 0x8d8c]
    //                              map.cpp:2507 (23)
    //         004596c5     XOR        AX,AX
    //         004596c8     MOV        this,dword ptr [EBP + this->_padding_*0x1]
    //         004596cc     ADD        this,ESI
    //         004596ce     MOV        DL,byte ptr [ECX + this+0x5]
    //         004596d1     SHR        DL,0x5
    //         004596d4     MOV        AL,DL
    //         004596d6     MOV        EDX,dword ptr [ESP + param_6]
    //         004596da     ADD        EAX,EDX
    //                              map.cpp:2508 (5)
    //         004596dc     TEST       AX,AX
    //         004596df     JGE        LAB_004596e5
    //                              map.cpp:2509 (2)
    //         004596e1     XOR        EAX,EAX
    //                              map.cpp:2510 (8)
    //         004596e3     JMP        LAB_004596f0
    //                               LAB_004596e5                                                 XREF[1]:     004596df(j)  
    //         004596e5     CMP        AX,0xff
    //         004596e9     JLE        LAB_004596f0
    //                              map.cpp:2511 (5)
    //         004596eb     MOV        EAX,0xff
    //                               LAB_004596f0                                                 XREF[2]:     004596e3(j), 004596e9(j)  
    //                              map.cpp:2512 (11)
    //         004596f0     MOV        DL,byte ptr [ECX + this+0x5]
    //         004596f3     SHL        AL,0x5
    //         004596f6     AND        DL,0x1f
    //         004596f9     OR         AL,DL
    //                              map.cpp:2513 (13)
    //         004596fb     MOV        DL,AL
    //         004596fd     MOV        byte ptr [ECX + this+0x5],AL
    //         00459700     SHR        DL,0x5
    //         00459703     CMP        DL,0x8
    //         00459706     JBE        LAB_0045970d
    //                              map.cpp:2514 (33)
    //         00459708     AND        AL,0x1f
    //         0045970a     MOV        byte ptr [ECX + this+0x5],AL
    //                               LAB_0045970d                                                 XREF[1]:     00459706(j)  
    //         0045970d     ADD        ESI,0x18
    //         00459710     DEC        EDI
    //         00459711     JNZ        LAB_004596bf
    //         00459713     MOV        EDX,dword ptr [ESP + param_3]
    //         00459717     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_0045971b                                                 XREF[1]:     004596ae(j)  
    //         0045971b     MOV        EAX,dword ptr [ESP + param_5]
    //         0045971f     ADD        EBP,0x4
    //         00459722     DEC        EAX
    //         00459723     MOV        dword ptr [ESP + param_5],EAX
    //         00459727     JNZ        LAB_004596ab
    //                              map.cpp:2518 (2)
    //         00459729     JMP        LAB_004597a8
    //                               LAB_0045972b                                                 XREF[1]:     00459680(j)  
    //                              map.cpp:2520 (10)
    //         0045972b     MOV        this,byte ptr [ESP + param_5]
    //         0045972f     MOV        AL,0x8
    //         00459731     CMP        this,AL
    //         00459733     JBE        LAB_00459739
    //                              map.cpp:2521 (4)
    //         00459735     MOV        byte ptr [ESP + param_5],AL
    //                               LAB_00459739                                                 XREF[1]:     00459733(j)  
    //                              map.cpp:2524 (33)
    //         00459739     MOV        EAX,dword ptr [ESP + param_2]
    //         0045973d     MOV        this,dword ptr [ESP + param_4]
    //         00459741     CMP        AX,this
    //         00459744     JG         LAB_004597b0
    //         00459746     MOVSX      EAX,AX
    //         00459749     MOVSX      this,this
    //         0045974c     SUB        this,EAX
    //         0045974e     LEA        EBP,[EAX*0x4 + 0x0]
    //         00459755     INC        this
    //         00459756     MOV        dword ptr [ESP + param_7],this
    //                               LAB_0045975a                                                 XREF[1]:     004597a6(j)  
    //                              map.cpp:2525 (5)
    //         0045975a     CMP        DI,DX
    //         0045975d     JG         LAB_0045979a
    //                              map.cpp:2528 (73)
    //         0045975f     MOV        this,byte ptr [ESP + param_5]
    //         00459763     MOVSX      EAX,DI
    //         00459766     MOVSX      EDI,DX
    //         00459769     LEA        ESI,[EAX + EAX*0x2]
    //         0045976c     SUB        EDI,EAX
    //         0045976e     SHL        this,0x5
    //         00459771     SHL        ESI,0x3
    //         00459774     INC        EDI
    //                               LAB_00459775                                                 XREF[1]:     00459790(j)  
    //         00459775     MOV        EAX,dword ptr [EBX + 0x8d8c]
    //         0045977b     MOV        EAX,dword ptr [EBP + EAX*0x1]
    //         0045977f     ADD        EAX,ESI
    //         00459781     ADD        ESI,0x18
    //         00459784     MOV        DL,byte ptr [EAX + 0x5]
    //         00459787     AND        DL,0x1f
    //         0045978a     OR         DL,this
    //         0045978c     DEC        EDI
    //         0045978d     MOV        byte ptr [EAX + 0x5],DL
    //         00459790     JNZ        LAB_00459775
    //         00459792     MOV        EDX,dword ptr [ESP + param_3]
    //         00459796     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_0045979a                                                 XREF[1]:     0045975d(j)  
    //         0045979a     MOV        EAX,dword ptr [ESP + param_7]
    //         0045979e     ADD        EBP,0x4
    //         004597a1     DEC        EAX
    //         004597a2     MOV        dword ptr [ESP + param_7],EAX
    //         004597a6     JNZ        LAB_0045975a
    //                               LAB_004597a8                                                 XREF[2]:     00459675(j), 00459729(j)  
    //                              map.cpp:2518 (8)
    //         004597a8     MOV        EAX,dword ptr [ESP + param_2]
    //         004597ac     MOV        this,dword ptr [ESP + param_4]
    //                               LAB_004597b0                                                 XREF[2]:     00459691(j), 00459744(j)  
    //                              map.cpp:2534 (5)
    //         004597b0     TEST       AX,AX
    //         004597b3     JLE        LAB_004597ba
    //                              map.cpp:2535 (5)
    //         004597b5     DEC        EAX
    //         004597b6     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_004597ba                                                 XREF[1]:     004597b3(j)  
    //                              map.cpp:2536 (11)
    //         004597ba     MOV        ESI,dword ptr [EBX + 0xc]
    //         004597bd     MOVSX      EBP,this
    //         004597c0     DEC        ESI
    //         004597c1     CMP        EBP,ESI
    //         004597c3     JGE        LAB_004597ca
    //                              map.cpp:2537 (5)
    //         004597c5     INC        this
    //         004597c6     MOV        dword ptr [ESP + param_4],this
    //                               LAB_004597ca                                                 XREF[1]:     004597c3(j)  
    //                              map.cpp:2538 (5)
    //         004597ca     TEST       DI,DI
    //         004597cd     JLE        LAB_004597d4
    //                              map.cpp:2539 (5)
    //         004597cf     DEC        EDI
    //         004597d0     MOV        dword ptr [ESP + param_1],EDI
    //                               LAB_004597d4                                                 XREF[1]:     004597cd(j)  
    //                              map.cpp:2540 (11)
    //         004597d4     MOV        ESI,dword ptr [EBX + 0x8]
    //         004597d7     MOVSX      EBP,DX
    //         004597da     DEC        ESI
    //         004597db     CMP        EBP,ESI
    //         004597dd     JGE        LAB_004597e4
    //                              map.cpp:2541 (5)
    //         004597df     INC        EDX
    //         004597e0     MOV        dword ptr [ESP + param_3],EDX
    //                               LAB_004597e4                                                 XREF[1]:     004597dd(j)  
    //                              map.cpp:2542 (27)
    //         004597e4     CMP        AX,this
    //         004597e7     MOV        dword ptr [ESP + param_7],EAX
    //         004597eb     JG         LAB_004598c2
    //         004597f1     MOVSX      EAX,AX
    //         004597f4     MOV        dword ptr [ESP + param_6],EAX
    //         004597f8     SHL        EAX,0x2
    //         004597fb     MOV        dword ptr [ESP + cur_player],EAX
    //                               LAB_004597ff                                                 XREF[1]:     004598b8(j)  
    //                              map.cpp:2543 (23)
    //         004597ff     CMP        DI,DX
    //         00459802     JG         LAB_00459894
    //         00459808     MOVSX      EBP,DI
    //         0045980b     MOV        dword ptr [ESP + param_5],EBP
    //         0045980f     LEA        EBP,[EBP + EBP*0x2]
    //         00459813     SHL        EBP,0x3
    //                               LAB_00459816                                                 XREF[1]:     0045988a(j)  
    //                              map.cpp:2545 (10)
    //         00459816     MOV        this,dword ptr [EBX + 0x8d8c]
    //         0045981c     MOV        EDX,dword ptr [ESP + cur_player]
    //                              map.cpp:2546 (21)
    //         00459820     MOV        EAX,dword ptr [ESP + param_7]
    //         00459824     MOV        ESI,dword ptr [EDX + this->_padding_*0x1]
    //         00459827     PUSH       EAX
    //         00459828     PUSH       EDI=>DAT_fffffff8
    //         00459829     MOV        this,EBX
    //         0045982b     ADD        ESI,EBP
    //         0045982d     CALL       RGE_Map::get_tile_type                           uchar get_tile_type(RGE_Map * this, short par
    //         00459832     MOV        byte ptr [ESI + 0x4],AL
    //                              map.cpp:2547 (7)
    //         00459835     MOV        ESI,dword ptr [ESI + 0x10]
    //         00459838     TEST       ESI,ESI
    //         0045983a     JZ         LAB_00459856
    //                               LAB_0045983c                                                 XREF[1]:     00459854(j)  
    //                              map.cpp:2548 (26)
    //         0045983c     MOV        this,dword ptr [ESI]
    //         0045983e     PUSH       0x0
    //         00459840     MOV        EAX,dword ptr [ECX + this+0x3c]
    //         00459843     MOV        EDX,dword ptr [this->_padding_]
    //         00459845     PUSH       EAX=>DAT_fffffff8
    //         00459846     MOV        EAX,dword ptr [ECX + this+0x38]
    //         00459849     PUSH       EAX=>DAT_fffffff4
    //         0045984a     CALL       dword ptr [EDX + 0x34]
    //         0045984d     MOV        ESI,dword ptr [ESI + 0x4]
    //         00459850     TEST       ESI,ESI
    //         00459852     FSTP       ST0
    //         00459854     JNZ        LAB_0045983c
    //                               LAB_00459856                                                 XREF[1]:     0045983a(j)  
    //                              map.cpp:2549 (12)
    //         00459856     MOV        this,dword ptr [EBX + 0x8dc0]
    //         0045985c     CMP        byte ptr [ECX + this+0x1d],0x3
    //         00459860     JZ         LAB_00459878
    //                              map.cpp:2550 (92)
    //         00459862     MOV        EDX,dword ptr [ESP + param_6]
    //         00459866     MOV        EAX,dword ptr [ESP + param_5]
    //         0045986a     MOV        this,dword ptr [ESP + local_4]
    //         0045986e     PUSH       EDX
    //         0045986f     PUSH       EAX=>DAT_fffffff8
    //         00459870     ADD        this,0x6c
    //         00459873     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                               LAB_00459878                                                 XREF[1]:     00459860(j)  
    //         00459878     MOV        EDX,dword ptr [ESP + 0x2c]
    //         0045987c     INC        EDI
    //         0045987d     INC        EDX
    //         0045987e     ADD        EBP,0x18
    //         00459881     CMP        DI,word ptr [ESP + 0x24]
    //         00459886     MOV        dword ptr [ESP + 0x2c],EDX
    //         0045988a     JLE        LAB_00459816
    //         0045988c     MOV        EDX,dword ptr [ESP + 0x24]
    //         00459890     MOV        EDI,dword ptr [ESP + 0x1c]
    //                               LAB_00459894                                                 XREF[1]:     00459802(j)  
    //         00459894     MOV        EAX,dword ptr [ESP + 0x34]
    //         00459898     MOV        this,dword ptr [ESP + 0x30]
    //         0045989c     MOV        EBP,dword ptr [ESP + 0x10]
    //         004598a0     INC        EAX
    //         004598a1     INC        this
    //         004598a2     ADD        EBP,0x4
    //         004598a5     MOV        dword ptr [ESP + 0x30],this
    //         004598a9     MOV        this,dword ptr [ESP + 0x28]
    //         004598ad     CMP        AX,this
    //         004598b0     MOV        dword ptr [ESP + 0x34],EAX
    //         004598b4     MOV        dword ptr [ESP + 0x10],EBP
    //         004598b8     JLE        LAB_004597ff
    //                              map.cpp:2542 (4)
    //         004598be     MOV        EAX,dword ptr [ESP + 0x20]
    //                               LAB_004598c2                                                 XREF[1]:     004597eb(j)  
    //                              map.cpp:2554 (27)
    //         004598c2     MOVSX      ESI,this
    //         004598c5     MOVSX      EBP,DX
    //         004598c8     MOVSX      EAX,AX
    //         004598cb     MOVSX      EDI,DI
    //         004598ce     PUSH       ESI
    //         004598cf     PUSH       EBP=>DAT_fffffff8
    //         004598d0     PUSH       EAX=>DAT_fffffff4
    //         004598d1     PUSH       EDI=>DAT_fffffff0
    //         004598d2     MOV        this,EBX
    //         004598d4     MOV        dword ptr [ESP + param_5],EAX
    //         004598d8     CALL       RGE_Map::set_map_screen_pos                      void set_map_screen_pos(RGE_Map * this, int p
    //                              map.cpp:2556 (17)
    //         004598dd     MOV        EDX,dword ptr [ESP + 0x2c]
    //         004598e1     PUSH       0x0
    //         004598e3     PUSH       ESI=>DAT_fffffff8
    //         004598e4     PUSH       EBP=>DAT_fffffff4
    //         004598e5     PUSH       EDX=>DAT_fffffff0
    //         004598e6     PUSH       EDI
    //         004598e7     MOV        this,EBX
    //         004598e9     CALL       RGE_Map::request_redraw                          void request_redraw(RGE_Map * this, int param
    //                              map.cpp:2557 (10)
    //         004598ee     POP        EDI
    //         004598ef     POP        ESI
    //         004598f0     POP        EBP
    //         004598f1     POP        EBX
    //         004598f2     ADD        ESP,0x8
    //         004598f5     RET        0x1c
}

// Offset: 0x00459900
void set_terrain(RGE_Map* this_, RGE_Game_World* param_2, short param_3, short param_4, uchar param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_terrain(class RGE_Game_World *,short,short,unsigned char,int,... *
    //                              *********************************************************************************************************
    //                              void __thiscall set_terrain(RGE_Map * this, RGE_Game_World * param_1
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[2]:     00459903(R), 00459984(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00459921(R), 004599a8(R), 004599e8(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[3]:     0045991c(R), 004599ac(R), 004599e4(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00459959(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004599a0(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0045999c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00459936(W), 0045998e(R)  
    //              RGE_Player *      Stack[-0x8]:4  cur_player                XREF[3]:     00459926(W), 0045996f(R), 004599bf(R)  
    //              RGE_Player *      Stack[-0xc]:4  obj_owner                 XREF[3]:     00459954(W), 0045995f(R), 004599a4(R)  
    //              short             Stack[-0x10]:2 old_terrain
    //                               ?set_terrain@RGE_Map@@QAEXPAVRGE_Game_World@@FFEHH@Z         XREF[15]:    clean_terrain:00457288(c), 
    //                               RGE_Map::set_terrain                                                      do_terrain_brush:00457391(c), 
    //                                                                                                         do_terrain_brush:0050fcdc(c), 
    //                                                                                                         do_terrain_brush:0050fd1c(c), 
    //                                                                                                         clean_borders:00510e75(c), 
    //                                                                                                         clean_borders:00510fc0(c), 
    //                                                                                                         tribe_clean_elevation:00511170(c), 
    //                                                                                                         tribe_clean_terrain:0051161d(c), 
    //                                                                                                         tribe_clean_terrain:00511641(c), 
    //                                                                                                         tribe_clean_terrain:00511668(c), 
    //                                                                                                         tribe_clean_terrain:0051168c(c), 
    //                                                                                                         tribe_clean_terrain:005116b3(c), 
    //                                                                                                         tribe_clean_terrain:005116d7(c), 
    //                                                                                                         tribe_clean_terrain:005116fe(c), 
    //                                                                                                         tribe_clean_terrain:00511722(c)  
    //                              map.cpp:2563 (3)
    //         00459900     SUB        ESP,0xc
    //                              map.cpp:2568 (13)
    //         00459903     MOV        EAX,dword ptr [ESP + param_1]
    //         00459907     PUSH       EBX
    //         00459908     PUSH       EBP
    //         00459909     PUSH       ESI
    //         0045990a     MOV        ESI,this
    //         0045990c     PUSH       EDI
    //         0045990d     MOV        this,dword ptr [EAX + 0x40]
    //                              map.cpp:2570 (12)
    //         00459910     MOV        EAX,dword ptr [ESI + 0x8dc0]
    //         00459916     MOV        EDX,dword ptr [this->_padding_]
    //         00459918     MOVSX      this,word ptr [EAX + 0x7c]
    //                              map.cpp:2575 (36)
    //         0045991c     MOVSX      EBX,word ptr [ESP + param_3]
    //         00459921     MOVSX      EDI,word ptr [ESP + param_2]
    //         00459926     MOV        dword ptr [ESP + cur_player],EDX
    //         0045992a     MOV        EDX,dword ptr [EAX + 0x40]
    //         0045992d     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
    //         00459930     MOV        this,dword ptr [ESI + 0x8d8c]
    //         00459936     MOV        dword ptr [ESP + local_4],EAX
    //         0045993a     LEA        EDX,[EDI + EDI*0x2]
    //         0045993d     MOV        EAX,dword ptr [this->_padding_ + EBX*0x4]
    //                              map.cpp:2576 (17)
    //         00459940     MOV        this,byte ptr [EAX + EDX*0x8 + 0x5]
    //         00459944     LEA        EBP,[EAX + EDX*0x8]
    //         00459947     MOV        DL,this
    //         00459949     AND        DL,0x1f
    //         0045994c     XOR        AX,AX
    //         0045994f     MOV        AL,DL
    //                              map.cpp:2577 (21)
    //         00459951     XOR        DX,DX
    //         00459954     MOV        word ptr [ESP + obj_owner],AX
    //         00459959     MOV        AL,byte ptr [ESP + param_4]
    //         0045995d     MOV        DL,AL
    //         0045995f     CMP        word ptr [ESP + obj_owner],DX
    //         00459964     JZ         LAB_004599e4
    //                              map.cpp:2580 (9)
    //         00459966     XOR        AL,this
    //         00459968     AND        AL,0x1f
    //         0045996a     XOR        AL,this
    //         0045996c     MOV        byte ptr [EBP + 0x5],AL
    //                              map.cpp:2582 (8)
    //         0045996f     MOV        EAX,dword ptr [ESP + cur_player]
    //         00459973     TEST       EAX,EAX
    //         00459975     JZ         LAB_004599e4
    //                              map.cpp:2585 (13)
    //         00459977     PUSH       0x0
    //         00459979     PUSH       EBX
    //         0045997a     PUSH       EDI
    //         0045997b     PUSH       EBX
    //         0045997c     PUSH       EDI
    //         0045997d     MOV        this,ESI
    //         0045997f     CALL       RGE_Map::request_redraw                          void request_redraw(RGE_Map * this, int param
    //                              map.cpp:2587 (10)
    //         00459984     MOV        EBP,dword ptr [ESP + param_1]
    //         00459988     CMP        byte ptr [EBP + 0x1d],0x3
    //         0045998c     JZ         LAB_0045999c
    //                              map.cpp:2588 (14)
    //         0045998e     MOV        EAX,dword ptr [ESP + local_4]
    //         00459992     PUSH       EBX
    //         00459993     PUSH       EDI
    //         00459994     LEA        this,[EAX + 0x6c]
    //         00459997     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                               LAB_0045999c                                                 XREF[1]:     0045998c(j)  
    //                              map.cpp:2590 (35)
    //         0045999c     MOV        this,dword ptr [ESP + param_6]
    //         004599a0     MOV        EDX,dword ptr [ESP + param_5]
    //         004599a4     MOV        EAX,dword ptr [ESP + obj_owner]
    //         004599a8     MOV        EBX,dword ptr [ESP + param_2]
    //         004599ac     MOV        EDI,dword ptr [ESP + param_3]
    //         004599b0     PUSH       this
    //         004599b1     PUSH       EDX
    //         004599b2     PUSH       0x1
    //         004599b4     PUSH       EAX
    //         004599b5     PUSH       EBX
    //         004599b6     PUSH       EDI
    //         004599b7     PUSH       EBP
    //         004599b8     MOV        this,ESI
    //         004599ba     CALL       RGE_Map::clear_terrain_object                    int clear_terrain_object(RGE_Map * this, RGE_
    //                              map.cpp:2592 (18)
    //         004599bf     MOV        this,dword ptr [ESP + cur_player]
    //         004599c3     PUSH       0x0
    //         004599c5     PUSH       EAX
    //         004599c6     PUSH       EBX
    //         004599c7     PUSH       EDI
    //         004599c8     PUSH       EBP
    //         004599c9     PUSH       this
    //         004599ca     MOV        this,ESI
    //         004599cc     CALL       RGE_Map::place_terrain_object                    void place_terrain_object(RGE_Map * this, RGE
    //                              map.cpp:2596 (9)
    //         004599d1     PUSH       EDI
    //         004599d2     PUSH       EBX
    //         004599d3     MOV        this,ESI
    //         004599d5     CALL       RGE_Map::get_border_type                         void get_border_type(RGE_Map * this, short pa
    //                              map.cpp:2597 (10)
    //         004599da     POP        EDI
    //         004599db     POP        ESI
    //         004599dc     POP        EBP
    //         004599dd     POP        EBX
    //         004599de     ADD        ESP,0xc
    //         004599e1     RET        0x18
    //                               LAB_004599e4                                                 XREF[2]:     00459964(j), 00459975(j)  
    //                              map.cpp:2592 (8)
    //         004599e4     MOV        EDI,dword ptr [ESP + param_3]
    //         004599e8     MOV        EBX,dword ptr [ESP + param_2]
    //                              map.cpp:2596 (9)
    //         004599ec     PUSH       EDI
    //         004599ed     PUSH       EBX
    //         004599ee     MOV        this,ESI
    //         004599f0     CALL       RGE_Map::get_border_type                         void get_border_type(RGE_Map * this, short pa
    //                              map.cpp:2597 (10)
    //         004599f5     POP        EDI
    //         004599f6     POP        ESI
    //         004599f7     POP        EBP
    //         004599f8     POP        EBX
    //         004599f9     ADD        ESP,0xc
    //         004599fc     RET        0x18
}

// Offset: 0x00459A00
void set_terrain_absolute(RGE_Map* this_, RGE_Game_World* param_2, short param_3, short param_4, uchar param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_terrain_absolute(class RGE_Game_World *,short,short,unsigned ... *
    //                              *********************************************************************************************************
    //                              void __thiscall set_terrain_absolute(RGE_Map * this, RGE_Game_World 
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[3]:     00459a01(R), 00459a4f(R), 00459a6a(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     00459a06(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     00459a0d(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00459a32(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00459a4b(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00459a47(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00459a2b(W), 00459a63(R)  
    //              RGE_Player *      Stack[-0x8]:4  obj_owner
    //                               ?set_terrain_absolute@RGE_Map@@QAEXPAVRGE_Game_World@@FFEHH@Z
    //                               RGE_Map::set_terrain_absolute
    //                              map.cpp:2603 (1)
    //         00459a00     PUSH       this
    //                              map.cpp:2607 (5)
    //         00459a01     MOV        EAX,dword ptr [ESP + param_1]
    //         00459a05     PUSH       EBX
    //                              map.cpp:2612 (44)
    //         00459a06     MOV        EBX,dword ptr [ESP + param_2]
    //         00459a0a     PUSH       EBP
    //         00459a0b     PUSH       ESI
    //         00459a0c     PUSH       EDI
    //         00459a0d     MOV        EDI,dword ptr [ESP + param_3]
    //         00459a11     MOV        ESI,this
    //         00459a13     MOV        this,dword ptr [EAX + 0x40]
    //         00459a16     MOV        EBP,dword ptr [ESI + 0x8d8c]
    //         00459a1c     MOVSX      EDX,DI
    //         00459a1f     MOVSX      EAX,BX
    //         00459a22     MOV        EDX,dword ptr [EBP + EDX*0x4]
    //         00459a26     MOV        this,dword ptr [this->_padding_]
    //         00459a28     LEA        EAX,[EAX + EAX*0x2]
    //         00459a2b     MOV        dword ptr [ESP + local_4],this
    //         00459a2f     LEA        EBP,[EDX + EAX*0x8]
    //                              map.cpp:2617 (14)
    //         00459a32     MOV        DL,byte ptr [ESP + param_4]
    //         00459a36     MOV        AL,byte ptr [EBP + 0x5]
    //         00459a39     XOR        DL,AL
    //         00459a3b     AND        DL,0x1f
    //         00459a3e     XOR        DL,AL
    //                              map.cpp:2619 (7)
    //         00459a40     TEST       this,this
    //         00459a42     MOV        byte ptr [EBP + 0x5],DL
    //         00459a45     JZ         LAB_00459a79
    //                              map.cpp:2622 (28)
    //         00459a47     MOV        EAX,dword ptr [ESP + param_6]
    //         00459a4b     MOV        this,dword ptr [ESP + param_5]
    //         00459a4f     MOV        EDX,dword ptr [ESP + param_1]
    //         00459a53     PUSH       EAX
    //         00459a54     PUSH       this
    //         00459a55     PUSH       0x1
    //         00459a57     PUSH       -0x1
    //         00459a59     PUSH       EBX
    //         00459a5a     PUSH       EDI
    //         00459a5b     PUSH       EDX
    //         00459a5c     MOV        this,ESI
    //         00459a5e     CALL       RGE_Map::clear_terrain_object                    int clear_terrain_object(RGE_Map * this, RGE_
    //                              map.cpp:2624 (22)
    //         00459a63     MOV        this,dword ptr [ESP + local_4]
    //         00459a67     PUSH       0x1
    //         00459a69     PUSH       EAX
    //         00459a6a     MOV        EAX,dword ptr [ESP + param_1]
    //         00459a6e     PUSH       EBX
    //         00459a6f     PUSH       EDI
    //         00459a70     PUSH       EAX
    //         00459a71     PUSH       this
    //         00459a72     MOV        this,ESI
    //         00459a74     CALL       RGE_Map::place_terrain_object                    void place_terrain_object(RGE_Map * this, RGE
    //                               LAB_00459a79                                                 XREF[1]:     00459a45(j)  
    //                              map.cpp:2628 (9)
    //         00459a79     PUSH       EDI
    //         00459a7a     PUSH       EBX
    //         00459a7b     MOV        this,ESI
    //         00459a7d     CALL       RGE_Map::get_border_type                         void get_border_type(RGE_Map * this, short pa
    //                              map.cpp:2629 (8)
    //         00459a82     POP        EDI
    //         00459a83     POP        ESI
    //         00459a84     POP        EBP
    //         00459a85     POP        EBX
    //         00459a86     POP        this
    //         00459a87     RET        0x18
}

// Offset: 0x00459A90
void set_terrain(RGE_Map* this_, RGE_Player* param_2, RGE_Game_World* param_3, short param_4, short param_5, short param_6, short param_7, uchar param_8, uchar param_9, int param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::set_terrain(class RGE_Player *,class RGE_Game_World *,short,short... *
    //                              *********************************************************************************************************
    //                              void __thiscall set_terrain(RGE_Map * this, RGE_Player * param_1, RG
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[3]:     00459b76(R), 00459c15(R), 00459c2a(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00459c21(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[9]:     00459b19(R), 00459b2a(W), 00459b4f(R), 00459b56(W), 
    //                                                                                     00459b84(R), 00459c53(R), 00459c7f(R), 00459cac(W), 
    //                                                                                     00459ce2(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[9]:     00459b04(R), 00459b15(W), 00459b30(R), 00459b37(W), 
    //                                                                                     00459b80(R), 00459c87(R), 00459c91(W), 00459cc0(R), 
    //                                                                                     00459cfd(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[11]:    00459b1d(R), 00459b26(W), 00459b5a(R), 00459b6a(W), 
    //                                                                                     00459b9a(R), 00459c3e(R), 00459c79(R), 00459c83(R), 
    //                                                                                     00459cbc(W), 00459cdb(R), 00459ce6(R)  
    //              short             Stack[0x18]:2  param_6                   XREF[11]:    00459b08(R), 00459b11(W), 00459b3b(R), 00459b4b(W), 
    //                                                                                     00459b88(R), 00459c5b(R), 00459c98(R), 00459ca2(RW), 
    //                                                                                     00459cc5(R), 00459ceb(R), 00459cf2(R)  
    //              uchar             Stack[0x1c]:1  param_7                   XREF[2]:     00459a93(R), 00459c08(R)  
    //              uchar             Stack[0x20]:1  param_8                   XREF[2]:     00459b6e(R), 00459c00(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     00459c1d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00459baa(W), 00459c4f(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00459bae(W), 00459c4b(R), 00459c68(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00459abe(W), 00459bc8(R), 00459bcc(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[5]:     00459b8d(W), 00459c2f(R), 00459c57(R), 00459c64(W), 
    //                                                                                     00459c6c(R)  
    //              undefined2        Stack[-0x12]:2 local_12                  XREF[2]:     00459aa9(W), 00459bf9(R)  
    //              short             Stack[-0x14]:2 maprow
    //                               ?set_terrain@RGE_Map@@QAEXPAVRGE_Player@@PAVRGE_Game_World@  XREF[7]:     clear_map:004558ed(c), 
    //                               RGE_Map::set_terrain                                                      scenario_load:00456131(c), 
    //                                                                                                         generate:00485298(c), 
    //                                                                                                         base_land_generate:004855e1(c), 
    //                                                                                                         generate:00485df4(c), 
    //                                                                                                         set_object_state:004c88d1(c), 
    //                                                                                                         tribe_clean_terrain:005117ab(c)  
    //                              map.cpp:2636 (3)
    //         00459a90     SUB        ESP,0x14
    //                              map.cpp:2642 (33)
    //         00459a93     MOV        EAX,dword ptr [ESP + param_7]
    //         00459a97     PUSH       EBX
    //         00459a98     PUSH       EBP
    //         00459a99     PUSH       ESI
    //         00459a9a     PUSH       EDI
    //         00459a9b     MOV        EDI,this
    //         00459a9d     XOR        this,this
    //         00459aa0     MOV        this,AL
    //         00459aa2     CMP        this,word ptr [EDI + 0x8d90]
    //         00459aa9     MOV        word ptr [ESP + local_12],this
    //         00459aae     JGE        LAB_00459d0f
    //                              map.cpp:2644 (74)
    //         00459ab4     MOV        this,EAX
    //         00459ab6     AND        this,0xff
    //         00459abc     MOV        EAX,this
    //         00459abe     MOV        dword ptr [ESP + local_c],this
    //         00459ac2     SHL        EAX,0x4
    //         00459ac5     ADD        EAX,this
    //         00459ac7     LEA        EAX,[EAX + EAX*0x2]
    //         00459aca     MOV        this,byte ptr [EDI + EAX*0x8 + 0x8c]
    //         00459ad1     LEA        EAX,[EDI + EAX*0x8]
    //         00459ad4     TEST       this,this
    //         00459ad6     JNZ        LAB_00459b04
    //         00459ad8     MOV        AX,word ptr [EAX + 0x144]
    //         00459adf     CMP        AX,0xffff
    //         00459ae3     JLE        LAB_00459d0f
    //         00459ae9     MOVSX      this,AX
    //         00459aec     MOV        EAX,this
    //         00459aee     SHL        EAX,0x4
    //         00459af1     ADD        EAX,this
    //         00459af3     LEA        this,[EAX + EAX*0x2]
    //         00459af6     CMP        byte ptr [EDI + this->_padding_*0x8 + 0x8c],0x1
    //                              map.cpp:2645 (6)
    //         00459afe     JNZ        LAB_00459d0f
    //                               LAB_00459b04                                                 XREF[1]:     00459ad6(j)  
    //                              map.cpp:2648 (13)
    //         00459b04     MOV        this,dword ptr [ESP + param_4]
    //         00459b08     MOV        EAX,dword ptr [ESP + param_6]
    //         00459b0c     CMP        this,AX
    //         00459b0f     JLE        LAB_00459b19
    //                              map.cpp:2651 (4)
    //         00459b11     MOV        dword ptr [ESP + param_6],this
    //                              map.cpp:2652 (4)
    //         00459b15     MOV        dword ptr [ESP + param_4],EAX
    //                               LAB_00459b19                                                 XREF[1]:     00459b0f(j)  
    //                              map.cpp:2655 (13)
    //         00459b19     MOV        this,dword ptr [ESP + param_3]
    //         00459b1d     MOV        EAX,dword ptr [ESP + param_5]
    //         00459b21     CMP        this,AX
    //         00459b24     JLE        LAB_00459b2e
    //                              map.cpp:2658 (4)
    //         00459b26     MOV        dword ptr [ESP + param_5],this
    //                              map.cpp:2659 (4)
    //         00459b2a     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_00459b2e                                                 XREF[1]:     00459b24(j)  
    //                              map.cpp:2663 (9)
    //         00459b2e     XOR        this,this
    //         00459b30     CMP        word ptr [ESP + param_4],this
    //         00459b35     JGE        LAB_00459b3b
    //                              map.cpp:2664 (4)
    //         00459b37     MOV        dword ptr [ESP + param_4],this
    //                               LAB_00459b3b                                                 XREF[1]:     00459b35(j)  
    //                              map.cpp:2665 (10)
    //         00459b3b     MOVSX      EDX,word ptr [ESP + param_6]
    //         00459b40     CMP        EDX,dword ptr [EDI + 0xc]
    //         00459b43     JL         LAB_00459b4f
    //                              map.cpp:2666 (10)
    //         00459b45     MOV        AX,word ptr [EDI + 0xc]
    //         00459b49     DEC        AX
    //         00459b4b     MOV        dword ptr [ESP + param_6],EAX
    //                               LAB_00459b4f                                                 XREF[1]:     00459b43(j)  
    //                              map.cpp:2667 (7)
    //         00459b4f     CMP        word ptr [ESP + param_3],this
    //         00459b54     JGE        LAB_00459b5a
    //                              map.cpp:2668 (4)
    //         00459b56     MOV        dword ptr [ESP + param_3],this
    //                               LAB_00459b5a                                                 XREF[1]:     00459b54(j)  
    //                              map.cpp:2669 (10)
    //         00459b5a     MOVSX      EAX,word ptr [ESP + param_5]
    //         00459b5f     CMP        EAX,dword ptr [EDI + 0x8]
    //         00459b62     JL         LAB_00459b6e
    //                              map.cpp:2670 (10)
    //         00459b64     MOV        AX,word ptr [EDI + 0x8]
    //         00459b68     DEC        AX
    //         00459b6a     MOV        dword ptr [ESP + param_5],EAX
    //                               LAB_00459b6e                                                 XREF[1]:     00459b62(j)  
    //                              map.cpp:2674 (18)
    //         00459b6e     MOV        AL,byte ptr [ESP + param_8]
    //         00459b72     TEST       AL,AL
    //         00459b74     JNZ        LAB_00459b80
    //         00459b76     CMP        dword ptr [ESP + param_1],this
    //         00459b7a     JZ         LAB_00459c7f
    //                               LAB_00459b80                                                 XREF[1]:     00459b74(j)  
    //                              map.cpp:2675 (4)
    //         00459b80     MOV        EBP,dword ptr [ESP + param_4]
    //                              map.cpp:2677 (52)
    //         00459b84     MOV        ESI,dword ptr [ESP + param_3]
    //         00459b88     CMP        BP,word ptr [ESP + param_6]
    //         00459b8d     MOV        dword ptr [ESP + local_10],EBP
    //         00459b91     JG         LAB_00459c79
    //         00459b97     MOVSX      EAX,SI
    //         00459b9a     MOV        EDX,dword ptr [ESP + param_5]
    //         00459b9e     MOVSX      this,BP
    //         00459ba1     LEA        EBX,[EAX + EAX*0x2]
    //         00459ba4     SHL        EBX,0x3
    //         00459ba7     SHL        this,0x2
    //         00459baa     MOV        dword ptr [ESP + local_4],EBX
    //         00459bae     MOV        dword ptr [ESP + local_8],this
    //                               LAB_00459bb2                                                 XREF[1]:     00459c71(j)  
    //         00459bb2     MOV        EAX,dword ptr [EDI + 0x8d8c]
    //                              map.cpp:2678 (16)
    //         00459bb8     MOV        EBP,ESI
    //         00459bba     MOV        EAX,dword ptr [this->_padding_ + EAX*0x1]
    //         00459bbd     ADD        EAX,EBX
    //         00459bbf     CMP        SI,DX
    //         00459bc2     JG         LAB_00459c57
    //                              map.cpp:2679 (38)
    //         00459bc8     MOV        EBX,dword ptr [ESP + local_c]
    //         00459bcc     MOV        EDX,dword ptr [ESP + local_c]
    //         00459bd0     SHL        EBX,0x4
    //         00459bd3     ADD        EBX,EDX
    //         00459bd5     LEA        ESI,[EAX + 0x5]
    //         00459bd8     SHL        EBX,0x2
    //                               LAB_00459bdb                                                 XREF[1]:     00459c49(j)  
    //         00459bdb     XOR        this,this
    //         00459bdd     MOV        this,byte ptr [ESI + -0x1]
    //         00459be0     LEA        EAX,[ECX + EBX*0x1 + this+0x23]
    //         00459be4     LEA        EDX,[EAX + EAX*0x2]
    //         00459be7     CMP        word ptr [EDI + EDX*0x2],0x0
    //         00459bec     JLE        LAB_00459c3e
    //                              map.cpp:2681 (11)
    //         00459bee     MOV        AL,byte ptr [ESI]
    //         00459bf0     MOV        this,AL
    //         00459bf2     AND        this,0x1f
    //         00459bf5     MOVZX      this,this
    //                              map.cpp:2683 (15)
    //         00459bf9     CMP        this,word ptr [ESP + local_12]
    //         00459bfe     JZ         LAB_00459c15
    //         00459c00     MOV        DL,byte ptr [ESP + param_8]
    //         00459c04     TEST       DL,DL
    //         00459c06     JZ         LAB_00459c15
    //                              map.cpp:2684 (13)
    //         00459c08     MOV        DL,byte ptr [ESP + param_7]
    //         00459c0c     XOR        DL,AL
    //         00459c0e     AND        DL,0x1f
    //         00459c11     XOR        DL,AL
    //         00459c13     MOV        byte ptr [ESI],DL
    //                               LAB_00459c15                                                 XREF[2]:     00459bfe(j), 00459c06(j)  
    //                              map.cpp:2686 (8)
    //         00459c15     MOV        EAX,dword ptr [ESP + param_1]
    //         00459c19     TEST       EAX,EAX
    //         00459c1b     JZ         LAB_00459c3e
    //                              map.cpp:2687 (90)
    //         00459c1d     MOV        EAX,dword ptr [ESP + param_9]
    //         00459c21     MOV        EDX,dword ptr [ESP + param_2]
    //         00459c25     PUSH       -0x1
    //         00459c27     PUSH       -0x1
    //         00459c29     PUSH       EAX
    //         00459c2a     MOV        EAX,dword ptr [ESP + param_1]
    //         00459c2e     PUSH       this
    //         00459c2f     MOV        this,dword ptr [ESP + local_10]
    //         00459c33     PUSH       EBP
    //         00459c34     PUSH       this
    //         00459c35     PUSH       EDX
    //         00459c36     PUSH       EAX
    //         00459c37     MOV        this,EDI
    //         00459c39     CALL       RGE_Map::create_terrain_object                   void create_terrain_object(RGE_Map * this, RG
    //                               LAB_00459c3e                                                 XREF[2]:     00459bec(j), 00459c1b(j)  
    //         00459c3e     MOV        EDX,dword ptr [ESP + param_5]
    //         00459c42     INC        EBP
    //         00459c43     ADD        ESI,0x18
    //         00459c46     CMP        BP,DX
    //         00459c49     JLE        LAB_00459bdb
    //         00459c4b     MOV        this,dword ptr [ESP + local_8]
    //         00459c4f     MOV        EBX,dword ptr [ESP + local_4]
    //         00459c53     MOV        ESI,dword ptr [ESP + param_3]
    //                               LAB_00459c57                                                 XREF[1]:     00459bc2(j)  
    //         00459c57     MOV        EBP,dword ptr [ESP + local_10]
    //         00459c5b     MOV        AX,word ptr [ESP + param_6]
    //         00459c60     INC        EBP
    //         00459c61     ADD        this,0x4
    //         00459c64     MOV        dword ptr [ESP + local_10],EBP
    //         00459c68     MOV        dword ptr [ESP + local_8],this
    //         00459c6c     CMP        word ptr [ESP + local_10],AX
    //         00459c71     JLE        LAB_00459bb2
    //                              map.cpp:2675 (20)
    //         00459c77     JMP        LAB_00459c87
    //                               LAB_00459c79                                                 XREF[1]:     00459b91(j)  
    //         00459c79     MOV        EDX,dword ptr [ESP + param_5]
    //         00459c7d     JMP        LAB_00459c8b
    //                               LAB_00459c7f                                                 XREF[1]:     00459b7a(j)  
    //         00459c7f     MOV        ESI,dword ptr [ESP + param_3]
    //         00459c83     MOV        EDX,dword ptr [ESP + param_5]
    //                               LAB_00459c87                                                 XREF[1]:     00459c77(j)  
    //         00459c87     MOV        EBP,dword ptr [ESP + param_4]
    //                               LAB_00459c8b                                                 XREF[1]:     00459c7d(j)  
    //                              map.cpp:2692 (5)
    //         00459c8b     TEST       BP,BP
    //         00459c8e     JLE        LAB_00459c95
    //                              map.cpp:2693 (5)
    //         00459c90     DEC        EBP
    //         00459c91     MOV        dword ptr [ESP + param_4],EBP
    //                               LAB_00459c95                                                 XREF[1]:     00459c8e(j)  
    //                              map.cpp:2694 (13)
    //         00459c95     MOV        this,dword ptr [EDI + 0xc]
    //         00459c98     MOVSX      EAX,word ptr [ESP + param_6]
    //         00459c9d     DEC        this
    //         00459c9e     CMP        EAX,this
    //         00459ca0     JGE        LAB_00459ca6
    //                              map.cpp:2695 (4)
    //         00459ca2     INC        dword ptr [ESP + param_6]
    //                               LAB_00459ca6                                                 XREF[1]:     00459ca0(j)  
    //                              map.cpp:2696 (5)
    //         00459ca6     TEST       SI,SI
    //         00459ca9     JLE        LAB_00459cb0
    //                              map.cpp:2697 (5)
    //         00459cab     DEC        ESI
    //         00459cac     MOV        dword ptr [ESP + param_3],ESI
    //                               LAB_00459cb0                                                 XREF[1]:     00459ca9(j)  
    //                              map.cpp:2698 (11)
    //         00459cb0     MOV        this,dword ptr [EDI + 0x8]
    //         00459cb3     MOVSX      EAX,DX
    //         00459cb6     DEC        this
    //         00459cb7     CMP        EAX,this
    //         00459cb9     JGE        LAB_00459cc0
    //                              map.cpp:2699 (5)
    //         00459cbb     INC        EDX
    //         00459cbc     MOV        dword ptr [ESP + param_5],EDX
    //                               LAB_00459cc0                                                 XREF[1]:     00459cb9(j)  
    //                              map.cpp:2700 (12)
    //         00459cc0     MOV        this,word ptr [ESP + param_4]
    //         00459cc5     CMP        this,word ptr [ESP + param_6]
    //         00459cca     JG         LAB_00459cf2
    //                               LAB_00459ccc                                                 XREF[1]:     00459cf0(j)  
    //                              map.cpp:2701 (5)
    //         00459ccc     CMP        SI,DX
    //         00459ccf     JG         LAB_00459ce2
    //                               LAB_00459cd1                                                 XREF[1]:     00459ce0(j)  
    //                              map.cpp:2702 (17)
    //         00459cd1     PUSH       EBP
    //         00459cd2     PUSH       ESI
    //         00459cd3     MOV        this,EDI
    //         00459cd5     CALL       RGE_Map::get_border_type                         void get_border_type(RGE_Map * this, short pa
    //         00459cda     INC        ESI
    //         00459cdb     CMP        SI,word ptr [ESP + param_5]
    //         00459ce0     JLE        LAB_00459cd1
    //                               LAB_00459ce2                                                 XREF[1]:     00459ccf(j)  
    //                              map.cpp:2700 (16)
    //         00459ce2     MOV        ESI,dword ptr [ESP + param_3]
    //         00459ce6     MOV        EDX,dword ptr [ESP + param_5]
    //         00459cea     INC        EBP
    //         00459ceb     CMP        BP,word ptr [ESP + param_6]
    //         00459cf0     JLE        LAB_00459ccc
    //                               LAB_00459cf2                                                 XREF[1]:     00459cca(j)  
    //                              map.cpp:2704 (29)
    //         00459cf2     MOVSX      EAX,word ptr [ESP + param_6]
    //         00459cf7     PUSH       0x0
    //         00459cf9     PUSH       EAX
    //         00459cfa     MOVSX      this,DX
    //         00459cfd     MOVSX      EDX,word ptr [ESP + param_4]
    //         00459d02     MOVSX      EAX,SI
    //         00459d05     PUSH       this
    //         00459d06     PUSH       EDX
    //         00459d07     PUSH       EAX
    //         00459d08     MOV        this,EDI
    //         00459d0a     CALL       RGE_Map::request_redraw                          void request_redraw(RGE_Map * this, int param
    //                               LAB_00459d0f                                                 XREF[3]:     00459aae(j), 00459ae3(j), 
    //                                                                                                         00459afe(j)  
    //                              map.cpp:2705 (10)
    //         00459d0f     POP        EDI
    //         00459d10     POP        ESI
    //         00459d11     POP        EBP
    //         00459d12     POP        EBX
    //         00459d13     ADD        ESP,0x14
    //         00459d16     RET        0x24
}

// Offset: 0x00459D20
uchar get_tile_type(RGE_Map* this_, short param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Map::get_tile_type(short,short)                                  *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_tile_type(RGE_Map * this, short param_1, short 
    //              uchar             AL:1           <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[5]:     00459d20(R), 00459e11(R), 00459e4d(W), 00459e54(W), 
    //                                                                                     00459ede(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[7]:     00459d4b(R), 00459dac(R), 00459dc3(R), 00459e76(R), 
    //                                                                                     00459e92(W), 00459e99(W), 00459fc2(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00459d8e(W), 00459ec0(R)  
    //              short             Stack[-0x8]:2  ech                       XREF[2]:     00459df6(W), 00459ea1(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00459e33(W), 00459e3a(W), 00459f95(R)  
    //              short             Stack[-0x10]:2 eb                        XREF[3]:     00459dbc(W), 00459dc8(W), 00459f68(R)  
    //              short             Stack[-0x14]:2 et                        XREF[3]:     00459de0(W), 00459de7(W), 00459ebc(R)  
    //              short             Stack[-0x18]:2 etl                       XREF[3]:     00459d61(W), 00459e1b(R), 00459e58(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[6]:     00459d41(W), 00459d9b(R), 00459deb(R), 00459e06(W), 
    //                                                                                     00459e0d(W), 00459ec4(R)  
    //              short             Stack[-0x20]:2 etr                       XREF[4]:     00459d3d(W), 00459d9f(R), 00459def(R), 00459ea5(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[5]:     00459d95(W), 00459f6f(R), 00459f9c(R), 00459fc9(R), 
    //                                                                                     00459ff4(R)  
    //              short             Stack[-0x28]:2 ecl
    //                               ?get_tile_type@RGE_Map@@QAEEFF@Z                             XREF[1]:     set_elev:0045982d(c)  
    //                               RGE_Map::get_tile_type
    //                              map.cpp:2709 (75)
    //         00459d20     MOV        AX,word ptr [ESP + param_1]
    //         00459d25     SUB        ESP,0x24
    //         00459d28     TEST       AX,AX
    //         00459d2b     PUSH       EBX
    //         00459d2c     PUSH       EBP
    //         00459d2d     PUSH       ESI
    //         00459d2e     PUSH       EDI
    //         00459d2f     JL         LAB_0045a01a
    //         00459d35     MOV        EDX,dword ptr [ECX + this->map_width]
    //         00459d38     MOVSX      EAX,AX
    //         00459d3b     CMP        EAX,EDX
    //         00459d3d     MOV        dword ptr [ESP + etr],EAX
    //         00459d41     MOV        dword ptr [ESP + local_1c],EDX
    //         00459d45     JGE        LAB_0045a01a
    //         00459d4b     MOV        BX,word ptr [ESP + param_2]
    //         00459d50     TEST       BX,BX
    //         00459d53     JL         LAB_0045a01a
    //         00459d59     MOV        ESI,dword ptr [ECX + this->map_height]
    //         00459d5c     MOVSX      EDX,BX
    //         00459d5f     CMP        EDX,ESI
    //         00459d61     MOV        dword ptr [ESP + etl],ESI
    //         00459d65     JGE        LAB_0045a01a
    //                              map.cpp:2729 (29)
    //         00459d6b     MOV        ESI,dword ptr [ECX + this->map_row_offset]
    //         00459d71     LEA        EAX,[EAX + EAX*0x2]
    //         00459d74     SHL        EAX,0x3
    //         00459d77     MOV        this,dword ptr [ESI + EDX*0x4]
    //         00459d7a     LEA        EBP,[EAX + this->_padding_*0x1]
    //         00459d7d     MOV        this,byte ptr [EAX + this->_padding_*0x1 + 0x5]
    //         00459d81     SHR        this,0x5
    //         00459d84     MOVZX      DI,this
    //                              map.cpp:2734 (32)
    //         00459d88     TEST       BX,BX
    //         00459d8b     LEA        this,[EDI + 0x1]
    //         00459d8e     MOV        dword ptr [ESP + local_4],this
    //         00459d92     LEA        this,[EDI + -0x1]
    //         00459d95     MOV        dword ptr [ESP + local_24],this
    //         00459d99     JLE        LAB_00459dc8
    //         00459d9b     MOV        this,dword ptr [ESP + local_1c]
    //         00459d9f     MOV        EBX,dword ptr [ESP + etr]
    //         00459da3     DEC        this
    //         00459da4     CMP        EBX,this
    //         00459da6     JGE        LAB_00459dc3
    //                              map.cpp:2735 (4)
    //         00459da8     MOV        this,dword ptr [ESI + EDX*0x4 + -0x4]
    //                              map.cpp:2736 (28)
    //         00459dac     MOV        BX,word ptr [ESP + param_2]
    //         00459db1     MOV        this,byte ptr [ECX + EAX*0x1 + this+0x1d]
    //         00459db5     SHR        this,0x5
    //         00459db8     MOVZX      this,this
    //         00459dbc     MOV        word ptr [ESP + eb],this
    //         00459dc1     JMP        LAB_00459dcc
    //                               LAB_00459dc3                                                 XREF[1]:     00459da6(j)  
    //         00459dc3     MOV        BX,word ptr [ESP + param_2]
    //                               LAB_00459dc8                                                 XREF[1]:     00459d99(j)  
    //                              map.cpp:2737 (4)
    //         00459dc8     MOV        dword ptr [ESP + eb],EDI
    //                               LAB_00459dcc                                                 XREF[1]:     00459dc1(j)  
    //                              map.cpp:2739 (5)
    //         00459dcc     TEST       BX,BX
    //         00459dcf     JLE        LAB_00459de7
    //                              map.cpp:2740 (20)
    //         00459dd1     MOV        this,dword ptr [ESI + EDX*0x4 + -0x4]
    //         00459dd5     MOV        this,byte ptr [ECX + EAX*0x1 + this+0x5]
    //         00459dd9     SHR        this,0x5
    //         00459ddc     MOVZX      this,this
    //         00459de0     MOV        word ptr [ESP + et],this
    //                              map.cpp:2741 (2)
    //         00459de5     JMP        LAB_00459deb
    //                               LAB_00459de7                                                 XREF[1]:     00459dcf(j)  
    //                              map.cpp:2742 (4)
    //         00459de7     MOV        dword ptr [ESP + et],EDI
    //                               LAB_00459deb                                                 XREF[1]:     00459de5(j)  
    //                              map.cpp:2744 (17)
    //         00459deb     MOV        this,dword ptr [ESP + local_1c]
    //         00459def     MOV        EBX,dword ptr [ESP + etr]
    //         00459df3     DEC        this
    //         00459df4     CMP        EBX,this
    //         00459df6     MOV        dword ptr [ESP + ech],this
    //         00459dfa     JGE        LAB_00459e0d
    //                              map.cpp:2745 (15)
    //         00459dfc     MOV        this,byte ptr [EBP + 0x1d]
    //         00459dff     SHR        this,0x5
    //         00459e02     MOVZX      this,this
    //         00459e06     MOV        word ptr [ESP + local_1c],this
    //                              map.cpp:2746 (2)
    //         00459e0b     JMP        LAB_00459e11
    //                               LAB_00459e0d                                                 XREF[1]:     00459dfa(j)  
    //                              map.cpp:2747 (4)
    //         00459e0d     MOV        dword ptr [ESP + local_1c],EDI
    //                               LAB_00459e11                                                 XREF[1]:     00459e0b(j)  
    //                              map.cpp:2750 (19)
    //         00459e11     MOV        this,word ptr [ESP + param_1]
    //         00459e16     TEST       this,this
    //         00459e19     JLE        LAB_00459e3a
    //         00459e1b     MOV        EBX,dword ptr [ESP + etl]
    //         00459e1f     DEC        EBX
    //         00459e20     CMP        EDX,EBX
    //         00459e22     JGE        LAB_00459e3a
    //                              map.cpp:2751 (20)
    //         00459e24     MOV        EBX,dword ptr [ESI + EDX*0x4 + 0x4]
    //         00459e28     MOV        BL,byte ptr [EBX + EAX*0x1 + -0x13]
    //         00459e2c     SHR        BL,0x5
    //         00459e2f     MOVZX      BX,BL
    //         00459e33     MOV        word ptr [ESP + local_c],BX
    //                              map.cpp:2752 (2)
    //         00459e38     JMP        LAB_00459e3e
    //                               LAB_00459e3a                                                 XREF[2]:     00459e19(j), 00459e22(j)  
    //                              map.cpp:2753 (4)
    //         00459e3a     MOV        dword ptr [ESP + local_c],EDI
    //                               LAB_00459e3e                                                 XREF[1]:     00459e38(j)  
    //                              map.cpp:2755 (5)
    //         00459e3e     TEST       this,this
    //         00459e41     JLE        LAB_00459e54
    //                              map.cpp:2756 (15)
    //         00459e43     MOV        BL,byte ptr [EBP + -0x13]
    //         00459e46     SHR        BL,0x5
    //         00459e49     MOVZX      BX,BL
    //         00459e4d     MOV        word ptr [ESP + param_1],BX
    //                              map.cpp:2757 (2)
    //         00459e52     JMP        LAB_00459e58
    //                               LAB_00459e54                                                 XREF[1]:     00459e41(j)  
    //                              map.cpp:2758 (4)
    //         00459e54     MOV        dword ptr [ESP + param_1],EDI
    //                               LAB_00459e58                                                 XREF[1]:     00459e52(j)  
    //                              map.cpp:2760 (11)
    //         00459e58     MOV        EBX,dword ptr [ESP + etl]
    //         00459e5c     LEA        EBP,[EBX + -0x1]
    //         00459e5f     CMP        EDX,EBP
    //         00459e61     JGE        LAB_00459e74
    //                              map.cpp:2761 (15)
    //         00459e63     MOV        EBX,dword ptr [ESI + EDX*0x4 + 0x4]
    //         00459e67     MOV        BL,byte ptr [EBX + EAX*0x1 + 0x5]
    //         00459e6b     SHR        BL,0x5
    //         00459e6e     MOVZX      BX,BL
    //                              map.cpp:2762 (2)
    //         00459e72     JMP        LAB_00459e76
    //                               LAB_00459e74                                                 XREF[1]:     00459e61(j)  
    //                              map.cpp:2763 (2)
    //         00459e74     MOV        EBX,EDI
    //                               LAB_00459e76                                                 XREF[1]:     00459e72(j)  
    //                              map.cpp:2766 (13)
    //         00459e76     CMP        word ptr [ESP + param_2],0x0
    //         00459e7c     JLE        LAB_00459e99
    //         00459e7e     TEST       this,this
    //         00459e81     JLE        LAB_00459e99
    //                              map.cpp:2767 (20)
    //         00459e83     MOV        this,dword ptr [ESI + EDX*0x4 + -0x4]
    //         00459e87     MOV        this,byte ptr [this->_padding_ + EAX*0x1 + -0x
    //         00459e8b     SHR        this,0x5
    //         00459e8e     MOVZX      this,this
    //         00459e92     MOV        word ptr [ESP + param_2],this
    //                              map.cpp:2768 (2)
    //         00459e97     JMP        LAB_00459e9d
    //                               LAB_00459e99                                                 XREF[2]:     00459e7c(j), 00459e81(j)  
    //                              map.cpp:2769 (4)
    //         00459e99     MOV        dword ptr [ESP + param_2],EDI
    //                               LAB_00459e9d                                                 XREF[1]:     00459e97(j)  
    //                              map.cpp:2772 (16)
    //         00459e9d     CMP        EDX,EBP
    //         00459e9f     JGE        LAB_00459ebc
    //         00459ea1     MOV        this,dword ptr [ESP + ech]
    //         00459ea5     MOV        EBP,dword ptr [ESP + etr]
    //         00459ea9     CMP        EBP,this
    //         00459eab     JGE        LAB_00459ebc
    //                              map.cpp:2773 (15)
    //         00459ead     MOV        EDX,dword ptr [ESI + EDX*0x4 + 0x4]
    //         00459eb1     MOV        AL,byte ptr [EDX + EAX*0x1 + 0x1d]
    //         00459eb5     SHR        AL,0x5
    //         00459eb8     MOVZX      DI,AL
    //                               LAB_00459ebc                                                 XREF[2]:     00459e9f(j), 00459eab(j)  
    //                              map.cpp:2781 (22)
    //         00459ebc     MOV        this,dword ptr [ESP + et]
    //         00459ec0     MOV        EAX,dword ptr [ESP + local_4]
    //         00459ec4     MOV        ESI,dword ptr [ESP + local_1c]
    //         00459ec8     CMP        this,AX
    //         00459ecb     JNZ        LAB_00459ede
    //         00459ecd     CMP        SI,AX
    //         00459ed0     JNZ        LAB_00459ede
    //                              map.cpp:2782 (2)
    //         00459ed2     MOV        AL,0xe
    //                              map.cpp:2841 (10)
    //         00459ed4     POP        EDI
    //         00459ed5     POP        ESI
    //         00459ed6     POP        EBP
    //         00459ed7     POP        EBX
    //         00459ed8     ADD        ESP,0x24
    //         00459edb     RET        0x8
    //                               LAB_00459ede                                                 XREF[2]:     00459ecb(j), 00459ed0(j)  
    //                              map.cpp:2784 (14)
    //         00459ede     MOV        EDX,dword ptr [ESP + param_1]
    //         00459ee2     CMP        DX,AX
    //         00459ee5     JNZ        LAB_00459ef8
    //         00459ee7     CMP        BX,AX
    //         00459eea     JNZ        LAB_00459ef8
    //                              map.cpp:2785 (2)
    //         00459eec     MOV        AL,0xd
    //                              map.cpp:2841 (10)
    //         00459eee     POP        EDI
    //         00459eef     POP        ESI
    //         00459ef0     POP        EBP
    //         00459ef1     POP        EBX
    //         00459ef2     ADD        ESP,0x24
    //         00459ef5     RET        0x8
    //                               LAB_00459ef8                                                 XREF[2]:     00459ee5(j), 00459eea(j)  
    //                              map.cpp:2788 (10)
    //         00459ef8     CMP        this,AX
    //         00459efb     JNZ        LAB_00459f0e
    //         00459efd     CMP        DX,AX
    //         00459f00     JNZ        LAB_00459f0e
    //                              map.cpp:2789 (2)
    //         00459f02     MOV        AL,0x10
    //                              map.cpp:2841 (10)
    //         00459f04     POP        EDI
    //         00459f05     POP        ESI
    //         00459f06     POP        EBP
    //         00459f07     POP        EBX
    //         00459f08     ADD        ESP,0x24
    //         00459f0b     RET        0x8
    //                               LAB_00459f0e                                                 XREF[2]:     00459efb(j), 00459f00(j)  
    //                              map.cpp:2791 (10)
    //         00459f0e     CMP        SI,AX
    //         00459f11     JNZ        LAB_00459f24
    //         00459f13     CMP        BX,AX
    //         00459f16     JNZ        LAB_00459f24
    //                              map.cpp:2792 (2)
    //         00459f18     MOV        AL,0xf
    //                              map.cpp:2841 (10)
    //         00459f1a     POP        EDI
    //         00459f1b     POP        ESI
    //         00459f1c     POP        EBP
    //         00459f1d     POP        EBX
    //         00459f1e     ADD        ESP,0x24
    //         00459f21     RET        0x8
    //                               LAB_00459f24                                                 XREF[2]:     00459f11(j), 00459f16(j)  
    //                              map.cpp:2795 (5)
    //         00459f24     CMP        this,AX
    //         00459f27     JNZ        LAB_00459f35
    //                              map.cpp:2796 (2)
    //         00459f29     MOV        AL,0x6
    //                              map.cpp:2841 (10)
    //         00459f2b     POP        EDI
    //         00459f2c     POP        ESI
    //         00459f2d     POP        EBP
    //         00459f2e     POP        EBX
    //         00459f2f     ADD        ESP,0x24
    //         00459f32     RET        0x8
    //                               LAB_00459f35                                                 XREF[1]:     00459f27(j)  
    //                              map.cpp:2798 (5)
    //         00459f35     CMP        SI,AX
    //         00459f38     JNZ        LAB_00459f46
    //                              map.cpp:2799 (2)
    //         00459f3a     MOV        AL,0x8
    //                              map.cpp:2841 (10)
    //         00459f3c     POP        EDI
    //         00459f3d     POP        ESI
    //         00459f3e     POP        EBP
    //         00459f3f     POP        EBX
    //         00459f40     ADD        ESP,0x24
    //         00459f43     RET        0x8
    //                               LAB_00459f46                                                 XREF[1]:     00459f38(j)  
    //                              map.cpp:2801 (5)
    //         00459f46     CMP        DX,AX
    //         00459f49     JNZ        LAB_00459f57
    //                              map.cpp:2802 (2)
    //         00459f4b     MOV        AL,0x5
    //                              map.cpp:2841 (10)
    //         00459f4d     POP        EDI
    //         00459f4e     POP        ESI
    //         00459f4f     POP        EBP
    //         00459f50     POP        EBX
    //         00459f51     ADD        ESP,0x24
    //         00459f54     RET        0x8
    //                               LAB_00459f57                                                 XREF[1]:     00459f49(j)  
    //                              map.cpp:2804 (5)
    //         00459f57     CMP        BX,AX
    //         00459f5a     JNZ        LAB_00459f68
    //                              map.cpp:2805 (2)
    //         00459f5c     MOV        AL,0x7
    //                              map.cpp:2841 (10)
    //         00459f5e     POP        EDI
    //         00459f5f     POP        ESI
    //         00459f60     POP        EBP
    //         00459f61     POP        EBX
    //         00459f62     ADD        ESP,0x24
    //         00459f65     RET        0x8
    //                               LAB_00459f68                                                 XREF[1]:     00459f5a(j)  
    //                              map.cpp:2807 (7)
    //         00459f68     CMP        word ptr [ESP + eb],AX
    //         00459f6d     JNZ        LAB_00459f95
    //                              map.cpp:2809 (14)
    //         00459f6f     MOV        EAX,dword ptr [ESP + local_24]
    //         00459f73     CMP        DX,AX
    //         00459f76     JNZ        LAB_00459f89
    //         00459f78     CMP        BX,AX
    //         00459f7b     JNZ        LAB_00459f89
    //                              map.cpp:2810 (2)
    //         00459f7d     MOV        AL,0x2
    //                              map.cpp:2841 (10)
    //         00459f7f     POP        EDI
    //         00459f80     POP        ESI
    //         00459f81     POP        EBP
    //         00459f82     POP        EBX
    //         00459f83     ADD        ESP,0x24
    //         00459f86     RET        0x8
    //                               LAB_00459f89                                                 XREF[2]:     00459f76(j), 00459f7b(j)  
    //                              map.cpp:2812 (2)
    //         00459f89     MOV        AL,0xa
    //                              map.cpp:2841 (10)
    //         00459f8b     POP        EDI
    //         00459f8c     POP        ESI
    //         00459f8d     POP        EBP
    //         00459f8e     POP        EBX
    //         00459f8f     ADD        ESP,0x24
    //         00459f92     RET        0x8
    //                               LAB_00459f95                                                 XREF[1]:     00459f6d(j)  
    //                              map.cpp:2815 (7)
    //         00459f95     CMP        word ptr [ESP + local_c],AX
    //         00459f9a     JNZ        LAB_00459fc2
    //                              map.cpp:2817 (14)
    //         00459f9c     MOV        EAX,dword ptr [ESP + local_24]
    //         00459fa0     CMP        this,AX
    //         00459fa3     JNZ        LAB_00459fb6
    //         00459fa5     CMP        SI,AX
    //         00459fa8     JNZ        LAB_00459fb6
    //                              map.cpp:2818 (2)
    //         00459faa     MOV        AL,0x1
    //                              map.cpp:2841 (10)
    //         00459fac     POP        EDI
    //         00459fad     POP        ESI
    //         00459fae     POP        EBP
    //         00459faf     POP        EBX
    //         00459fb0     ADD        ESP,0x24
    //         00459fb3     RET        0x8
    //                               LAB_00459fb6                                                 XREF[2]:     00459fa3(j), 00459fa8(j)  
    //                              map.cpp:2820 (2)
    //         00459fb6     MOV        AL,0x9
    //                              map.cpp:2841 (10)
    //         00459fb8     POP        EDI
    //         00459fb9     POP        ESI
    //         00459fba     POP        EBP
    //         00459fbb     POP        EBX
    //         00459fbc     ADD        ESP,0x24
    //         00459fbf     RET        0x8
    //                               LAB_00459fc2                                                 XREF[1]:     00459f9a(j)  
    //                              map.cpp:2823 (7)
    //         00459fc2     CMP        word ptr [ESP + param_2],AX
    //         00459fc7     JNZ        LAB_00459fef
    //                              map.cpp:2825 (14)
    //         00459fc9     MOV        EAX,dword ptr [ESP + local_24]
    //         00459fcd     CMP        SI,AX
    //         00459fd0     JNZ        LAB_00459fe3
    //         00459fd2     CMP        BX,AX
    //         00459fd5     JNZ        LAB_00459fe3
    //                              map.cpp:2826 (2)
    //         00459fd7     MOV        AL,0x3
    //                              map.cpp:2841 (10)
    //         00459fd9     POP        EDI
    //         00459fda     POP        ESI
    //         00459fdb     POP        EBP
    //         00459fdc     POP        EBX
    //         00459fdd     ADD        ESP,0x24
    //         00459fe0     RET        0x8
    //                               LAB_00459fe3                                                 XREF[2]:     00459fd0(j), 00459fd5(j)  
    //                              map.cpp:2828 (2)
    //         00459fe3     MOV        AL,0xb
    //                              map.cpp:2841 (10)
    //         00459fe5     POP        EDI
    //         00459fe6     POP        ESI
    //         00459fe7     POP        EBP
    //         00459fe8     POP        EBX
    //         00459fe9     ADD        ESP,0x24
    //         00459fec     RET        0x8
    //                               LAB_00459fef                                                 XREF[1]:     00459fc7(j)  
    //                              map.cpp:2831 (5)
    //         00459fef     CMP        DI,AX
    //         00459ff2     JNZ        LAB_0045a01a
    //                              map.cpp:2833 (14)
    //         00459ff4     MOV        EAX,dword ptr [ESP + local_24]
    //         00459ff8     CMP        this,AX
    //         00459ffb     JNZ        LAB_0045a00e
    //         00459ffd     CMP        DX,AX
    //         0045a000     JNZ        LAB_0045a00e
    //                              map.cpp:2834 (2)
    //         0045a002     MOV        AL,0x4
    //                              map.cpp:2841 (10)
    //         0045a004     POP        EDI
    //         0045a005     POP        ESI
    //         0045a006     POP        EBP
    //         0045a007     POP        EBX
    //         0045a008     ADD        ESP,0x24
    //         0045a00b     RET        0x8
    //                               LAB_0045a00e                                                 XREF[2]:     00459ffb(j), 0045a000(j)  
    //                              map.cpp:2836 (2)
    //         0045a00e     MOV        AL,0xc
    //                              map.cpp:2841 (22)
    //         0045a010     POP        EDI
    //         0045a011     POP        ESI
    //         0045a012     POP        EBP
    //         0045a013     POP        EBX
    //         0045a014     ADD        ESP,0x24
    //         0045a017     RET        0x8
    //                               LAB_0045a01a                                                 XREF[5]:     00459d2f(j), 00459d45(j), 
    //                                                                                                         00459d53(j), 00459d65(j), 
    //                                                                                                         00459ff2(j)  
    //         0045a01a     POP        EDI
    //         0045a01b     POP        ESI
    //         0045a01c     POP        EBP
    //         0045a01d     XOR        AL,AL
    //         0045a01f     POP        EBX
    //         0045a020     ADD        ESP,0x24
    //         0045a023     RET        0x8
}

// Offset: 0x0045A030
void get_border_type(RGE_Map* this_, short param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::get_border_type(short,short)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall get_border_type(RGE_Map * this, short param_1, short
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[8]:     0045a030(R), 0045a0cf(R), 0045a119(R), 0045a161(R), 
    //                                                                                     0045a259(W), 0045a267(R), 0045a319(W), 0045a444(W)  
    //              short             Stack[0x8]:2   param_2                   XREF[8]:     0045a059(R), 0045a111(R), 0045a136(R), 0045a14f(W), 
    //                                                                                     0045a155(W), 0045a1e8(*), 0045a237(R), 0045a3fc(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045a093(W), 0045a1a3(R)  
    //              uchar             Stack[-0x8]:1  ter_cur                   XREF[2]:     0045a0f7(W), 0045a182(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[9]:     0045a04f(W), 0045a0f1(R), 0045a13e(R), 0045a186(R), 
    //                                                                                     0045a199(W), 0045a19f(W), 0045a202(*), 0045a247(R), 
    //                                                                                     0045a424(R)  
    //              uchar             Stack[-0x10]:1 ter_bot_rgt               XREF[7]:     0045a0b4(W), 0045a159(R), 0045a174(W), 0045a17a(W), 
    //                                                                                     0045a1f5(*), 0045a23f(R), 0045a410(R)  
    //              uchar             Stack[-0x14]:1 ter_bot_lft               XREF[5]:     0045a12c(W), 0045a132(W), 0045a1db(*), 0045a22f(R), 
    //                                                                                     0045a3e8(R)  
    //              uchar             Stack[-0x18]:1 ter_top_lft               XREF[6]:     0045a086(W), 0045a30b(R), 0045a436(R), 0045a455(R), 
    //                                                                                     0045a467(R), 0045a479(R)  
    //              RGE_Tile *        Stack[-0x1c]:4 tile                      XREF[6]:     0045a0c5(W), 0045a0cb(W), 0045a1b4(*), 0045a217(R), 
    //                                                                                     0045a2d2(R), 0045a374(R)  
    //              uchar             Stack[-0x20]:1 ter_bot                   XREF[6]:     0045a107(W), 0045a10d(W), 0045a1ce(*), 0045a227(R), 
    //                                                                                     0045a2f8(R), 0045a356(R)  
    //              uchar             Stack[-0x24]:1 ter_rgt                   XREF[6]:     0045a0e1(W), 0045a0e7(W), 0045a1c1(*), 0045a21f(R), 
    //                                                                                     0045a2e5(R), 0045a32e(R)  
    //              uchar             Stack[-0x28]:1 ter_lft                   XREF[6]:     0045a0a4(W), 0045a0aa(W), 0045a1a7(*), 0045a20f(R), 
    //                                                                                     0045a2be(R), 0045a32a(R)  
    //              uchar             Stack[-0x2c]:1 ter_top
    //                               ?get_border_type@RGE_Map@@QAEXFF@Z                           XREF[5]:     set_terrain:004599d5(c), 
    //                               RGE_Map::get_border_type                                                  set_terrain:004599f0(c), 
    //                                                                                                         set_terrain_absolute:00459a7d(c), 
    //                                                                                                         set_terrain:00459cd5(c), 
    //                                                                                                         change_terrain:0050fbb1(c)  
    //                              map.cpp:2845 (69)
    //         0045a030     MOV        AX,word ptr [ESP + param_1]
    //         0045a035     SUB        ESP,0x28
    //         0045a038     TEST       AX,AX
    //         0045a03b     PUSH       EBX
    //         0045a03c     PUSH       EBP
    //         0045a03d     PUSH       ESI
    //         0045a03e     PUSH       EDI
    //         0045a03f     MOV        EDI,this
    //         0045a041     JL         LAB_0045a481
    //         0045a047     MOV        this,dword ptr [EDI + 0x8]
    //         0045a04a     MOVSX      EAX,AX
    //         0045a04d     CMP        EAX,this
    //         0045a04f     MOV        dword ptr [ESP + local_c],EAX
    //         0045a053     JGE        LAB_0045a481
    //         0045a059     MOV        BP,word ptr [ESP + param_2]
    //         0045a05e     TEST       BP,BP
    //         0045a061     JL         LAB_0045a481
    //         0045a067     MOV        EDX,dword ptr [EDI + 0xc]
    //         0045a06a     MOVSX      this,BP
    //         0045a06d     CMP        this,EDX
    //         0045a06f     JGE        LAB_0045a481
    //                              map.cpp:2858 (21)
    //         0045a075     MOV        ESI,dword ptr [EDI + 0x8d8c]
    //         0045a07b     LEA        EAX,[EAX + EAX*0x2]
    //         0045a07e     SHL        EAX,0x3
    //         0045a081     MOV        EDX,dword ptr [ESI + this->_padding_*0x4]
    //         0045a084     ADD        EDX,EAX
    //         0045a086     MOV        dword ptr [ESP + ter_top_lft],EDX
    //                              map.cpp:2859 (6)
    //         0045a08a     MOV        BL,byte ptr [EDX + 0x5]
    //         0045a08d     AND        BL,0x1f
    //                              map.cpp:2862 (9)
    //         0045a090     TEST       BP,BP
    //         0045a093     MOV        byte ptr [ESP + local_4],BL
    //         0045a097     JLE        LAB_0045a0aa
    //                              map.cpp:2863 (15)
    //         0045a099     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + -0x4]
    //         0045a09d     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x5]
    //         0045a0a1     AND        DL,0x1f
    //         0045a0a4     MOV        byte ptr [ESP + ter_lft],DL
    //                              map.cpp:2864 (2)
    //         0045a0a8     JMP        LAB_0045a0ae
    //                               LAB_0045a0aa                                                 XREF[1]:     0045a097(j)  
    //                              map.cpp:2865 (4)
    //         0045a0aa     MOV        byte ptr [ESP + ter_lft],BL
    //                               LAB_0045a0ae                                                 XREF[1]:     0045a0a8(j)  
    //                              map.cpp:2868 (12)
    //         0045a0ae     MOV        EDX,dword ptr [EDI + 0xc]
    //         0045a0b1     DEC        EDX
    //         0045a0b2     CMP        this,EDX
    //         0045a0b4     MOV        dword ptr [ESP + ter_bot_rgt],EDX
    //         0045a0b8     JGE        LAB_0045a0cb
    //                              map.cpp:2869 (15)
    //         0045a0ba     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x4]
    //         0045a0be     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x5]
    //         0045a0c2     AND        DL,0x1f
    //         0045a0c5     MOV        byte ptr [ESP + tile],DL
    //                              map.cpp:2870 (2)
    //         0045a0c9     JMP        LAB_0045a0cf
    //                               LAB_0045a0cb                                                 XREF[1]:     0045a0b8(j)  
    //                              map.cpp:2871 (4)
    //         0045a0cb     MOV        byte ptr [ESP + tile],BL
    //                               LAB_0045a0cf                                                 XREF[1]:     0045a0c9(j)  
    //                              map.cpp:2874 (8)
    //         0045a0cf     CMP        word ptr [ESP + param_1],0x0
    //         0045a0d5     JLE        LAB_0045a0e7
    //                              map.cpp:2875 (14)
    //         0045a0d7     MOV        EDX,dword ptr [ESI + this->_padding_*0x4]
    //         0045a0da     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x13]
    //         0045a0de     AND        DL,0x1f
    //         0045a0e1     MOV        byte ptr [ESP + ter_rgt],DL
    //                              map.cpp:2876 (2)
    //         0045a0e5     JMP        LAB_0045a0eb
    //                               LAB_0045a0e7                                                 XREF[1]:     0045a0d5(j)  
    //                              map.cpp:2877 (4)
    //         0045a0e7     MOV        byte ptr [ESP + ter_rgt],BL
    //                               LAB_0045a0eb                                                 XREF[1]:     0045a0e5(j)  
    //                              map.cpp:2880 (18)
    //         0045a0eb     MOV        EDX,dword ptr [EDI + 0x8]
    //         0045a0ee     LEA        EBP,[EDX + -0x1]
    //         0045a0f1     MOV        EDX,dword ptr [ESP + local_c]
    //         0045a0f5     CMP        EDX,EBP
    //         0045a0f7     MOV        dword ptr [ESP + ter_cur],EBP
    //         0045a0fb     JGE        LAB_0045a10d
    //                              map.cpp:2881 (14)
    //         0045a0fd     MOV        EDX,dword ptr [ESI + this->_padding_*0x4]
    //         0045a100     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x1d]
    //         0045a104     AND        DL,0x1f
    //         0045a107     MOV        byte ptr [ESP + ter_bot],DL
    //                              map.cpp:2882 (2)
    //         0045a10b     JMP        LAB_0045a111
    //                               LAB_0045a10d                                                 XREF[1]:     0045a0fb(j)  
    //                              map.cpp:2883 (4)
    //         0045a10d     MOV        byte ptr [ESP + ter_bot],BL
    //                               LAB_0045a111                                                 XREF[1]:     0045a10b(j)  
    //                              map.cpp:2886 (16)
    //         0045a111     CMP        word ptr [ESP + param_2],0x0
    //         0045a117     JLE        LAB_0045a132
    //         0045a119     CMP        word ptr [ESP + param_1],0x0
    //         0045a11f     JLE        LAB_0045a132
    //                              map.cpp:2887 (15)
    //         0045a121     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + -0x4]
    //         0045a125     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x13]
    //         0045a129     AND        DL,0x1f
    //         0045a12c     MOV        byte ptr [ESP + ter_bot_lft],DL
    //                              map.cpp:2888 (2)
    //         0045a130     JMP        LAB_0045a136
    //                               LAB_0045a132                                                 XREF[2]:     0045a117(j), 0045a11f(j)  
    //                              map.cpp:2889 (4)
    //         0045a132     MOV        byte ptr [ESP + ter_bot_lft],BL
    //                               LAB_0045a136                                                 XREF[1]:     0045a130(j)  
    //                              map.cpp:2892 (14)
    //         0045a136     CMP        word ptr [ESP + param_2],0x0
    //         0045a13c     JLE        LAB_0045a155
    //         0045a13e     CMP        dword ptr [ESP + local_c],EBP
    //         0045a142     JGE        LAB_0045a155
    //                              map.cpp:2893 (15)
    //         0045a144     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + -0x4]
    //         0045a148     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x1d]
    //         0045a14c     AND        DL,0x1f
    //         0045a14f     MOV        byte ptr [ESP + param_2],DL
    //                              map.cpp:2894 (2)
    //         0045a153     JMP        LAB_0045a159
    //                               LAB_0045a155                                                 XREF[2]:     0045a13c(j), 0045a142(j)  
    //                              map.cpp:2895 (4)
    //         0045a155     MOV        byte ptr [ESP + param_2],BL
    //                               LAB_0045a159                                                 XREF[1]:     0045a153(j)  
    //                              map.cpp:2898 (16)
    //         0045a159     MOV        EBP,dword ptr [ESP + ter_bot_rgt]
    //         0045a15d     CMP        this,EBP
    //         0045a15f     JGE        LAB_0045a17a
    //         0045a161     CMP        word ptr [ESP + param_1],0x0
    //         0045a167     JLE        LAB_0045a17a
    //                              map.cpp:2899 (15)
    //         0045a169     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x4]
    //         0045a16d     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x13]
    //         0045a171     AND        DL,0x1f
    //         0045a174     MOV        byte ptr [ESP + ter_bot_rgt],DL
    //                              map.cpp:2900 (2)
    //         0045a178     JMP        LAB_0045a17e
    //                               LAB_0045a17a                                                 XREF[2]:     0045a15f(j), 0045a167(j)  
    //                              map.cpp:2901 (4)
    //         0045a17a     MOV        byte ptr [ESP + ter_bot_rgt],BL
    //                               LAB_0045a17e                                                 XREF[1]:     0045a178(j)  
    //                              map.cpp:2904 (16)
    //         0045a17e     CMP        this,EBP
    //         0045a180     JGE        LAB_0045a19f
    //         0045a182     MOV        EDX,dword ptr [ESP + ter_cur]
    //         0045a186     MOV        EBP,dword ptr [ESP + local_c]
    //         0045a18a     CMP        EBP,EDX
    //         0045a18c     JGE        LAB_0045a19f
    //                              map.cpp:2905 (15)
    //         0045a18e     MOV        this,dword ptr [ESI + this->_padding_*0x4 + 0x4]
    //         0045a192     MOV        DL,byte ptr [ECX + EAX*0x1 + this+0x1d]
    //         0045a196     AND        DL,0x1f
    //         0045a199     MOV        byte ptr [ESP + local_c],DL
    //                              map.cpp:2906 (2)
    //         0045a19d     JMP        LAB_0045a1a3
    //                               LAB_0045a19f                                                 XREF[2]:     0045a180(j), 0045a18c(j)  
    //                              map.cpp:2907 (4)
    //         0045a19f     MOV        byte ptr [ESP + local_c],BL
    //                               LAB_0045a1a3                                                 XREF[1]:     0045a19d(j)  
    //                              map.cpp:2912 (17)
    //         0045a1a3     MOV        ESI,dword ptr [ESP + local_4]
    //         0045a1a7     LEA        EAX=>ter_lft,[ESP + 0x10]
    //         0045a1ab     PUSH       EAX
    //         0045a1ac     PUSH       ESI
    //         0045a1ad     MOV        this,EDI
    //         0045a1af     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2913 (13)
    //         0045a1b4     LEA        this=>tile,[ESP + 0x1c]
    //         0045a1b8     PUSH       this
    //         0045a1b9     PUSH       ESI
    //         0045a1ba     MOV        this,EDI
    //         0045a1bc     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2914 (13)
    //         0045a1c1     LEA        EDX=>ter_rgt,[ESP + 0x14]
    //         0045a1c5     MOV        this,EDI
    //         0045a1c7     PUSH       EDX
    //         0045a1c8     PUSH       ESI
    //         0045a1c9     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2915 (13)
    //         0045a1ce     LEA        EAX=>ter_bot,[ESP + 0x18]
    //         0045a1d2     MOV        this,EDI
    //         0045a1d4     PUSH       EAX
    //         0045a1d5     PUSH       ESI
    //         0045a1d6     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2916 (13)
    //         0045a1db     LEA        this=>ter_bot_lft,[ESP + 0x24]
    //         0045a1df     PUSH       this
    //         0045a1e0     PUSH       ESI
    //         0045a1e1     MOV        this,EDI
    //         0045a1e3     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2917 (13)
    //         0045a1e8     LEA        EDX=>param_2,[ESP + 0x40]
    //         0045a1ec     MOV        this,EDI
    //         0045a1ee     PUSH       EDX
    //         0045a1ef     PUSH       ESI
    //         0045a1f0     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2918 (13)
    //         0045a1f5     LEA        EAX=>ter_bot_rgt,[ESP + 0x28]
    //         0045a1f9     MOV        this,EDI
    //         0045a1fb     PUSH       EAX
    //         0045a1fc     PUSH       ESI
    //         0045a1fd     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2919 (13)
    //         0045a202     LEA        this=>local_c,[ESP + 0x2c]
    //         0045a206     PUSH       this
    //         0045a207     PUSH       ESI
    //         0045a208     MOV        this,EDI
    //         0045a20a     CALL       RGE_Map::check_for_border                        void check_for_border(RGE_Map * this, uchar p
    //                              map.cpp:2922 (6)
    //         0045a20f     MOV        AL,byte ptr [ESP + ter_lft]
    //         0045a213     CMP        AL,BL
    //                              map.cpp:2924 (8)
    //         0045a215     JNZ        LAB_0045a253
    //         0045a217     MOV        AL,byte ptr [ESP + tile]
    //         0045a21b     CMP        AL,BL
    //                              map.cpp:2926 (8)
    //         0045a21d     JNZ        LAB_0045a253
    //         0045a21f     MOV        AL,byte ptr [ESP + ter_rgt]
    //         0045a223     CMP        AL,BL
    //                              map.cpp:2928 (8)
    //         0045a225     JNZ        LAB_0045a253
    //         0045a227     MOV        AL,byte ptr [ESP + ter_bot]
    //         0045a22b     CMP        AL,BL
    //                              map.cpp:2930 (8)
    //         0045a22d     JNZ        LAB_0045a253
    //         0045a22f     MOV        AL,byte ptr [ESP + ter_bot_lft]
    //         0045a233     CMP        AL,BL
    //                              map.cpp:2932 (8)
    //         0045a235     JNZ        LAB_0045a253
    //         0045a237     MOV        AL,byte ptr [ESP + param_2]
    //         0045a23b     CMP        AL,BL
    //                              map.cpp:2934 (8)
    //         0045a23d     JNZ        LAB_0045a253
    //         0045a23f     MOV        AL,byte ptr [ESP + ter_bot_rgt]
    //         0045a243     CMP        AL,BL
    //                              map.cpp:2936 (14)
    //         0045a245     JNZ        LAB_0045a253
    //         0045a247     MOV        AL,byte ptr [ESP + local_c]
    //         0045a24b     CMP        AL,BL
    //         0045a24d     JZ         LAB_0045a479
    //                               LAB_0045a253                                                 XREF[7]:     0045a215(j), 0045a21d(j), 
    //                                                                                                         0045a225(j), 0045a22d(j), 
    //                                                                                                         0045a235(j), 0045a23d(j), 
    //                                                                                                         0045a245(j)  
    //                              map.cpp:2945 (20)
    //         0045a253     AND        ESI,0xff
    //         0045a259     MOV        byte ptr [ESP + param_1],AL
    //         0045a25d     MOV        EAX,ESI
    //         0045a25f     SHL        EAX,0x4
    //         0045a262     ADD        EAX,ESI
    //         0045a264     LEA        EDX,[EAX + EAX*0x2]
    //                              map.cpp:2947 (20)
    //         0045a267     MOV        EAX,dword ptr [ESP + param_1]
    //         0045a26b     AND        EAX,0xff
    //         0045a270     LEA        this,[EDI + EDX*0x8 + 0x14a]
    //         0045a277     MOV        AX,word ptr [this->_padding_ + EAX*0x2]
    //                              map.cpp:2948 (57)
    //         0045a27b     CMP        AX,0xffff
    //         0045a27f     JZ         LAB_0045a467
    //         0045a285     TEST       AX,AX
    //         0045a288     JL         LAB_0045a467
    //         0045a28e     CMP        AX,0x10
    //         0045a292     JGE        LAB_0045a467
    //         0045a298     MOVSX      EDX,AX
    //         0045a29b     LEA        EDX,[EDX + EDX*0x4]
    //         0045a29e     LEA        EDX,[EDX + EDX*0x8]
    //         0045a2a1     SHL        EDX,0x5
    //         0045a2a4     ADD        EDX,EDI
    //         0045a2a6     MOV        BL,byte ptr [EDX + 0x338c]
    //         0045a2ac     TEST       BL,BL
    //         0045a2ae     JZ         LAB_0045a467
    //                              map.cpp:2956 (10)
    //         0045a2b4     CMP        word ptr [EDX + 0x392a],0x1
    //         0045a2bc     JNZ        LAB_0045a32a
    //                              map.cpp:2960 (18)
    //         0045a2be     MOV        ESI,dword ptr [ESP + ter_lft]
    //         0045a2c2     XOR        DL,DL
    //         0045a2c4     AND        ESI,0xff
    //         0045a2ca     CMP        word ptr [this->_padding_ + ESI*0x2],AX
    //         0045a2ce     JNZ        LAB_0045a2d2
    //                              map.cpp:2961 (2)
    //         0045a2d0     MOV        DL,0x1
    //                               LAB_0045a2d2                                                 XREF[1]:     0045a2ce(j)  
    //                              map.cpp:2962 (16)
    //         0045a2d2     MOV        ESI,dword ptr [ESP + tile]
    //         0045a2d6     AND        ESI,0xff
    //         0045a2dc     CMP        word ptr [this->_padding_ + ESI*0x2],AX
    //         0045a2e0     JNZ        LAB_0045a2e5
    //                              map.cpp:2963 (3)
    //         0045a2e2     ADD        DL,0x2
    //                               LAB_0045a2e5                                                 XREF[1]:     0045a2e0(j)  
    //                              map.cpp:2964 (16)
    //         0045a2e5     MOV        ESI,dword ptr [ESP + ter_rgt]
    //         0045a2e9     AND        ESI,0xff
    //         0045a2ef     CMP        word ptr [this->_padding_ + ESI*0x2],AX
    //         0045a2f3     JNZ        LAB_0045a2f8
    //                              map.cpp:2965 (3)
    //         0045a2f5     ADD        DL,0x4
    //                               LAB_0045a2f8                                                 XREF[1]:     0045a2f3(j)  
    //                              map.cpp:2966 (16)
    //         0045a2f8     MOV        ESI,dword ptr [ESP + ter_bot]
    //         0045a2fc     AND        ESI,0xff
    //         0045a302     CMP        word ptr [this->_padding_ + ESI*0x2],AX
    //         0045a306     JNZ        LAB_0045a30b
    //                              map.cpp:2967 (3)
    //         0045a308     ADD        DL,0x8
    //                               LAB_0045a30b                                                 XREF[1]:     0045a306(j)  
    //                              map.cpp:2969 (4)
    //         0045a30b     MOV        ESI,dword ptr [ESP + ter_top_lft]
    //                              map.cpp:2970 (17)
    //         0045a30f     AND        AL,0xf
    //         0045a311     SHL        DL,0x4
    //         0045a314     MOV        this,byte ptr [ESI + 0x6]
    //         0045a317     OR         AL,DL
    //         0045a319     MOV        byte ptr [ESP + param_1],this
    //         0045a31d     MOV        byte ptr [ESI + 0x6],AL
    //                              map.cpp:3012 (10)
    //         0045a320     POP        EDI
    //         0045a321     POP        ESI
    //         0045a322     POP        EBP
    //         0045a323     POP        EBX
    //         0045a324     ADD        ESP,0x28
    //         0045a327     RET        0x8
    //                               LAB_0045a32a                                                 XREF[1]:     0045a2bc(j)  
    //                              map.cpp:2979 (37)
    //         0045a32a     MOV        EDX,dword ptr [ESP + ter_lft]
    //         0045a32e     MOV        ESI,dword ptr [ESP + ter_rgt]
    //         0045a332     AND        EDX,0xff
    //         0045a338     MOV        BX,word ptr [this->_padding_ + EDX*0x2]
    //         0045a33c     CMP        BX,AX
    //         0045a33f     JNZ        LAB_0045a356
    //         0045a341     MOV        EDX,ESI
    //         0045a343     AND        EDX,0xff
    //         0045a349     CMP        word ptr [this->_padding_ + EDX*0x2],AX
    //         0045a34d     JNZ        LAB_0045a356
    //                              map.cpp:2980 (2)
    //         0045a34f     MOV        this,0x1
    //                              map.cpp:2981 (28)
    //         0045a351     JMP        LAB_0045a436
    //                               LAB_0045a356                                                 XREF[2]:     0045a33f(j), 0045a34d(j)  
    //         0045a356     MOV        EDX,dword ptr [ESP + ter_bot]
    //         0045a35a     CMP        BX,AX
    //         0045a35d     JNZ        LAB_0045a374
    //         0045a35f     MOV        EDI,EDX
    //         0045a361     AND        EDI,0xff
    //         0045a367     CMP        word ptr [this->_padding_ + EDI*0x2],AX
    //         0045a36b     JNZ        LAB_0045a374
    //                              map.cpp:2982 (2)
    //         0045a36d     MOV        this,0x2
    //                              map.cpp:2983 (38)
    //         0045a36f     JMP        LAB_0045a436
    //                               LAB_0045a374                                                 XREF[2]:     0045a35d(j), 0045a36b(j)  
    //         0045a374     MOV        EDI,dword ptr [ESP + tile]
    //         0045a378     AND        EDI,0xff
    //         0045a37e     MOV        DI,word ptr [this->_padding_ + EDI*0x2]
    //         0045a382     CMP        DI,AX
    //         0045a385     JNZ        LAB_0045a3b6
    //         0045a387     MOV        EBP,ESI
    //         0045a389     AND        EBP,0xff
    //         0045a38f     CMP        word ptr [this->_padding_ + EBP*0x2],AX
    //         0045a393     JNZ        LAB_0045a39c
    //                              map.cpp:2984 (2)
    //         0045a395     MOV        this,0x3
    //                              map.cpp:2985 (24)
    //         0045a397     JMP        LAB_0045a436
    //                               LAB_0045a39c                                                 XREF[1]:     0045a393(j)  
    //         0045a39c     CMP        DI,AX
    //         0045a39f     JNZ        LAB_0045a3b6
    //         0045a3a1     MOV        EBP,EDX
    //         0045a3a3     AND        EBP,0xff
    //         0045a3a9     CMP        word ptr [this->_padding_ + EBP*0x2],AX
    //         0045a3ad     JNZ        LAB_0045a3b6
    //                              map.cpp:2986 (2)
    //         0045a3af     MOV        this,0x4
    //                              map.cpp:2987 (10)
    //         0045a3b1     JMP        LAB_0045a436
    //                               LAB_0045a3b6                                                 XREF[3]:     0045a385(j), 0045a39f(j), 
    //                                                                                                         0045a3ad(j)  
    //         0045a3b6     CMP        BX,AX
    //         0045a3b9     JNZ        LAB_0045a3bf
    //                              map.cpp:2988 (2)
    //         0045a3bb     MOV        this,0x9
    //                              map.cpp:2989 (7)
    //         0045a3bd     JMP        LAB_0045a436
    //                               LAB_0045a3bf                                                 XREF[1]:     0045a3b9(j)  
    //         0045a3bf     CMP        DI,AX
    //         0045a3c2     JNZ        LAB_0045a3c8
    //                              map.cpp:2990 (2)
    //         0045a3c4     MOV        this,0xa
    //                              map.cpp:2991 (14)
    //         0045a3c6     JMP        LAB_0045a436
    //                               LAB_0045a3c8                                                 XREF[1]:     0045a3c2(j)  
    //         0045a3c8     AND        ESI,0xff
    //         0045a3ce     CMP        word ptr [this->_padding_ + ESI*0x2],AX
    //         0045a3d2     JNZ        LAB_0045a3d8
    //                              map.cpp:2992 (2)
    //         0045a3d4     MOV        this,0xb
    //                              map.cpp:2993 (14)
    //         0045a3d6     JMP        LAB_0045a436
    //                               LAB_0045a3d8                                                 XREF[1]:     0045a3d2(j)  
    //         0045a3d8     AND        EDX,0xff
    //         0045a3de     CMP        word ptr [this->_padding_ + EDX*0x2],AX
    //         0045a3e2     JNZ        LAB_0045a3e8
    //                              map.cpp:2994 (2)
    //         0045a3e4     MOV        this,0xc
    //                              map.cpp:2995 (18)
    //         0045a3e6     JMP        LAB_0045a436
    //                               LAB_0045a3e8                                                 XREF[1]:     0045a3e2(j)  
    //         0045a3e8     MOV        EDX,dword ptr [ESP + ter_bot_lft]
    //         0045a3ec     AND        EDX,0xff
    //         0045a3f2     CMP        word ptr [this->_padding_ + EDX*0x2],AX
    //         0045a3f6     JNZ        LAB_0045a3fc
    //                              map.cpp:2996 (2)
    //         0045a3f8     MOV        this,0x5
    //                              map.cpp:2997 (18)
    //         0045a3fa     JMP        LAB_0045a436
    //                               LAB_0045a3fc                                                 XREF[1]:     0045a3f6(j)  
    //         0045a3fc     MOV        EDX,dword ptr [ESP + param_2]
    //         0045a400     AND        EDX,0xff
    //         0045a406     CMP        word ptr [this->_padding_ + EDX*0x2],AX
    //         0045a40a     JNZ        LAB_0045a410
    //                              map.cpp:2998 (2)
    //         0045a40c     MOV        this,0x6
    //                              map.cpp:2999 (18)
    //         0045a40e     JMP        LAB_0045a436
    //                               LAB_0045a410                                                 XREF[1]:     0045a40a(j)  
    //         0045a410     MOV        EDX,dword ptr [ESP + ter_bot_rgt]
    //         0045a414     AND        EDX,0xff
    //         0045a41a     CMP        word ptr [this->_padding_ + EDX*0x2],AX
    //         0045a41e     JNZ        LAB_0045a424
    //                              map.cpp:3000 (2)
    //         0045a420     MOV        this,0x7
    //                              map.cpp:3001 (18)
    //         0045a422     JMP        LAB_0045a436
    //                               LAB_0045a424                                                 XREF[1]:     0045a41e(j)  
    //         0045a424     MOV        EDX,dword ptr [ESP + local_c]
    //         0045a428     AND        EDX,0xff
    //         0045a42e     CMP        word ptr [this->_padding_ + EDX*0x2],AX
    //         0045a432     JNZ        LAB_0045a455
    //                              map.cpp:3002 (2)
    //         0045a434     MOV        this,0x8
    //                               LAB_0045a436                                                 XREF[11]:    0045a351(j), 0045a36f(j), 
    //                                                                                                         0045a397(j), 0045a3b1(j), 
    //                                                                                                         0045a3bd(j), 0045a3c6(j), 
    //                                                                                                         0045a3d6(j), 0045a3e6(j), 
    //                                                                                                         0045a3fa(j), 0045a40e(j), 
    //                                                                                                         0045a422(j)  
    //                              map.cpp:3010 (4)
    //         0045a436     MOV        ESI,dword ptr [ESP + ter_top_lft]
    //                              map.cpp:3011 (17)
    //         0045a43a     AND        AL,0xf
    //         0045a43c     SHL        this,0x4
    //         0045a43f     MOV        DL,byte ptr [ESI + 0x6]
    //         0045a442     OR         AL,this
    //         0045a444     MOV        byte ptr [ESP + param_1],DL
    //         0045a448     MOV        byte ptr [ESI + 0x6],AL
    //                              map.cpp:3012 (10)
    //         0045a44b     POP        EDI
    //         0045a44c     POP        ESI
    //         0045a44d     POP        EBP
    //         0045a44e     POP        EBX
    //         0045a44f     ADD        ESP,0x28
    //         0045a452     RET        0x8
    //                               LAB_0045a455                                                 XREF[1]:     0045a432(j)  
    //                              map.cpp:3006 (8)
    //         0045a455     MOV        EAX,dword ptr [ESP + ter_top_lft]
    //         0045a459     MOV        byte ptr [EAX + 0x6],0x0
    //                              map.cpp:3012 (10)
    //         0045a45d     POP        EDI
    //         0045a45e     POP        ESI
    //         0045a45f     POP        EBP
    //         0045a460     POP        EBX
    //         0045a461     ADD        ESP,0x28
    //         0045a464     RET        0x8
    //                               LAB_0045a467                                                 XREF[4]:     0045a27f(j), 0045a288(j), 
    //                                                                                                         0045a292(j), 0045a2ae(j)  
    //                              map.cpp:2951 (8)
    //         0045a467     MOV        this,dword ptr [ESP + ter_top_lft]
    //         0045a46b     MOV        byte ptr [ECX + this+0x6],0x0
    //                              map.cpp:3012 (10)
    //         0045a46f     POP        EDI
    //         0045a470     POP        ESI
    //         0045a471     POP        EBP
    //         0045a472     POP        EBX
    //         0045a473     ADD        ESP,0x28
    //         0045a476     RET        0x8
    //                               LAB_0045a479                                                 XREF[1]:     0045a24d(j)  
    //                              map.cpp:2941 (8)
    //         0045a479     MOV        EDX,dword ptr [ESP + ter_top_lft]
    //         0045a47d     MOV        byte ptr [EDX + 0x6],0x0
    //                               LAB_0045a481                                                 XREF[4]:     0045a041(j), 0045a053(j), 
    //                                                                                                         0045a061(j), 0045a06f(j)  
    //                              map.cpp:3012 (10)
    //         0045a481     POP        EDI
    //         0045a482     POP        ESI
    //         0045a483     POP        EBP
    //         0045a484     POP        EBX
    //         0045a485     ADD        ESP,0x28
    //         0045a488     RET        0x8
}

// Offset: 0x0045A490
void check_for_border(RGE_Map* this_, uchar param_2, uchar* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::check_for_border(unsigned char,unsigned char &)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall check_for_border(RGE_Map * this, uchar param_1, ucha
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0045a49b(R)  
    //              uchar *           Stack[0x8]:4   param_2                   XREF[1]:     0045a493(R)  
    //                               ?check_for_border@RGE_Map@@QAEXEAAE@Z                        XREF[8]:     get_border_type:0045a1af(c), 
    //                               RGE_Map::check_for_border                                                 get_border_type:0045a1bc(c), 
    //                                                                                                         get_border_type:0045a1c9(c), 
    //                                                                                                         get_border_type:0045a1d6(c), 
    //                                                                                                         get_border_type:0045a1e3(c), 
    //                                                                                                         get_border_type:0045a1f0(c), 
    //                                                                                                         get_border_type:0045a1fd(c), 
    //                                                                                                         get_border_type:0045a20a(c)  
    //                              map.cpp:3018 (3)
    //         0045a490     PUSH       EBX
    //         0045a491     PUSH       ESI
    //         0045a492     PUSH       EDI
    //                              map.cpp:3021 (16)
    //         0045a493     MOV        EDI,dword ptr [ESP + param_2]
    //         0045a497     MOV        ESI,this
    //         0045a499     MOV        BL,byte ptr [EDI]
    //         0045a49b     MOV        this,dword ptr [ESP + param_1]
    //         0045a49f     CMP        BL,this
    //         0045a4a1     JZ         LAB_0045a4f0
    //                              map.cpp:3024 (35)
    //         0045a4a3     MOV        EDX,this
    //         0045a4a5     AND        EBX,0xff
    //         0045a4ab     AND        EDX,0xff
    //         0045a4b1     MOV        EAX,EDX
    //         0045a4b3     SHL        EAX,0x4
    //         0045a4b6     ADD        EAX,EDX
    //         0045a4b8     LEA        EAX,[EAX + EAX*0x2]
    //         0045a4bb     LEA        EDX,[EBX + EAX*0x4]
    //         0045a4be     MOV        AX,word ptr [ESI + EDX*0x2 + 0x14a]
    //                              map.cpp:3026 (40)
    //         0045a4c6     CMP        AX,0xffff
    //         0045a4ca     JZ         LAB_0045a4ee
    //         0045a4cc     TEST       AX,AX
    //         0045a4cf     JL         LAB_0045a4ee
    //         0045a4d1     CMP        AX,0x10
    //         0045a4d5     JGE        LAB_0045a4ee
    //         0045a4d7     MOVSX      EAX,AX
    //         0045a4da     LEA        EAX,[EAX + EAX*0x4]
    //         0045a4dd     LEA        EAX,[EAX + EAX*0x8]
    //         0045a4e0     SHL        EAX,0x5
    //         0045a4e3     MOV        DL,byte ptr [EAX + ESI*0x1 + 0x338c]
    //         0045a4ea     TEST       DL,DL
    //         0045a4ec     JNZ        LAB_0045a4f0
    //                               LAB_0045a4ee                                                 XREF[3]:     0045a4ca(j), 0045a4cf(j), 
    //                                                                                                         0045a4d5(j)  
    //                              map.cpp:3029 (2)
    //         0045a4ee     MOV        byte ptr [EDI],this
    //                               LAB_0045a4f0                                                 XREF[2]:     0045a4a1(j), 0045a4ec(j)  
    //                              map.cpp:3030 (6)
    //         0045a4f0     POP        EDI
    //         0045a4f1     POP        ESI
    //         0045a4f2     POP        EBX
    //         0045a4f3     RET        0x8
}

// Offset: 0x0045A500
void update(RGE_Map* this_, ulong param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::update(unsigned long)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall update(RGE_Map * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[2]:     0045a500(R), 0045a6bb(R)  
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[6,1]:   0045a520(W), 0045a52f(R), 0045a5c9(W), 0045a5d1(R), 
    //                                                                                     0045a68b(W), 0045a693(R), 0045a524(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0045a53f(W), 0045a568(R), 0045a5da(R), 0045a62a(R), 
    //                                                                                     0045a69c(R)  
    //              float             Stack[-0x10]:4 cur_time                  XREF[6]:     0045a535(W), 0045a5cd(R), 0045a5ef(W), 0045a602(W), 
    //                                                                                     0045a68f(R), 0045a6b1(W)  
    //              short             Stack[-0x14]:2 i
    //                               ?update@RGE_Map@@QAEXK@Z
    //                               RGE_Map::update
    //                              map.cpp:3039 (30)
    //         0045a500     MOV        EAX,dword ptr [ESP + param_1]
    //         0045a504     SUB        ESP,0x10
    //         0045a507     PUSH       EBP
    //         0045a508     MOV        EBP,this
    //         0045a50a     PUSH       ESI
    //         0045a50b     MOV        ESI,dword ptr [DAT_0062e65c]
    //         0045a511     MOV        this,EAX
    //         0045a513     SUB        this,ESI
    //         0045a515     CMP        this,0x64
    //         0045a518     JC         LAB_0045a6c6
    //                              map.cpp:3050 (10)
    //         0045a51e     XOR        EDX,EDX
    //         0045a520     MOV        dword ptr [ESP + local_8],EAX
    //         0045a524     MOV        dword ptr [ESP + local_8+0x4],EDX
    //                              map.cpp:3053 (33)
    //         0045a528     CMP        word ptr [EBP + 0x8d90],DX
    //         0045a52f     FILD       qword ptr [ESP + local_8]
    //         0045a533     PUSH       EDI
    //         0045a534     PUSH       EBX
    //         0045a535     MOV        dword ptr [ESP + cur_time],EDX
    //         0045a539     FMUL       float ptr [DAT_005706e8]                         = 6Fh    o
    //         0045a53f     FSTP       float ptr [ESP + local_c]
    //         0045a543     JLE        LAB_0045a5f9
    //                               LAB_0045a549                                                 XREF[1]:     0045a5f3(j)  
    //                              map.cpp:3055 (20)
    //         0045a549     MOVSX      this,DX
    //         0045a54c     MOV        EAX,this
    //         0045a54e     SHL        EAX,0x4
    //         0045a551     ADD        EAX,this
    //         0045a553     LEA        EAX,[EAX + EAX*0x2]
    //         0045a556     LEA        ESI,[EBP + EAX*0x8 + 0x8c]
    //                              map.cpp:3056 (11)
    //         0045a55d     MOV        AL,byte ptr [EBP + EAX*0x8 + 0xbb]
    //         0045a564     TEST       AL,AL
    //         0045a566     JZ         LAB_0045a5e7
    //                              map.cpp:3058 (4)
    //         0045a568     FLD        float ptr [ESP + local_c]
    //                              map.cpp:3059 (13)
    //         0045a56c     FSUB       float ptr [ESI + 0x40]
    //         0045a56f     FCOM       float ptr [ESI + 0x34]
    //         0045a572     FNSTSW     AX
    //         0045a574     TEST       AH,0x1
    //         0045a577     JNZ        LAB_0045a5e5
    //                              map.cpp:3062 (10)
    //         0045a579     FLD        ST0
    //         0045a57b     FDIV       float ptr [ESI + 0x34]
    //         0045a57e     CALL       __ftol                                           undefined __ftol()
    //                              map.cpp:3064 (20)
    //         0045a583     MOV        DI,word ptr [ESI + 0x30]
    //         0045a587     MOV        this,word ptr [ESI + 0x32]
    //         0045a58b     MOV        EBX,EAX
    //         0045a58d     ADD        this,DI
    //         0045a590     MOV        DX,BX
    //         0045a593     ADD        DX,word ptr [ESI + 0x3c]
    //                              map.cpp:3065 (5)
    //         0045a597     CMP        DX,this
    //         0045a59a     JL         LAB_0045a5a5
    //                              map.cpp:3066 (9)
    //         0045a59c     MOVSX      EAX,DX
    //         0045a59f     MOVSX      this,this
    //         0045a5a2     CDQ
    //         0045a5a3     IDIV       this
    //                               LAB_0045a5a5                                                 XREF[1]:     0045a59a(j)  
    //                              map.cpp:3070 (9)
    //         0045a5a5     CMP        DX,DI
    //         0045a5a8     MOV        word ptr [ESI + 0x3c],DX
    //         0045a5ac     JL         LAB_0045a5b1
    //                              map.cpp:3071 (3)
    //         0045a5ae     LEA        EDX,[EDI + -0x1]
    //                               LAB_0045a5b1                                                 XREF[1]:     0045a5ac(j)  
    //                              map.cpp:3074 (6)
    //         0045a5b1     CMP        word ptr [ESI + 0x3e],DX
    //         0045a5b5     JZ         LAB_0045a5c6
    //                              map.cpp:3076 (4)
    //         0045a5b7     MOV        word ptr [ESI + 0x3e],DX
    //                              map.cpp:3077 (4)
    //         0045a5bb     MOV        byte ptr [ESI + 0x44],0x1
    //                              map.cpp:3078 (7)
    //         0045a5bf     MOV        byte ptr [EBP + 0x8dac],0x1
    //                               LAB_0045a5c6                                                 XREF[1]:     0045a5b5(j)  
    //                              map.cpp:3082 (31)
    //         0045a5c6     MOVSX      EDX,BX
    //         0045a5c9     MOV        dword ptr [ESP + local_8],EDX
    //         0045a5cd     MOV        EDX,dword ptr [ESP + cur_time]
    //         0045a5d1     FILD       dword ptr [ESP + local_8]
    //         0045a5d5     FMUL       float ptr [ESI + 0x34]
    //         0045a5d8     FSUBR      ST0,ST1
    //         0045a5da     FSUBR      float ptr [ESP + local_c]
    //         0045a5de     FSTP       float ptr [ESI + 0x40]
    //         0045a5e1     FSTP       ST0
    //         0045a5e3     JMP        LAB_0045a5e7
    //                               LAB_0045a5e5                                                 XREF[1]:     0045a577(j)  
    //                              map.cpp:3059 (2)
    //         0045a5e5     FSTP       ST0
    //                               LAB_0045a5e7                                                 XREF[2]:     0045a566(j), 0045a5e3(j)  
    //                              map.cpp:3082 (18)
    //         0045a5e7     INC        EDX
    //         0045a5e8     CMP        DX,word ptr [EBP + 0x8d90]
    //         0045a5ef     MOV        dword ptr [ESP + cur_time],EDX
    //         0045a5f3     JL         LAB_0045a549
    //                               LAB_0045a5f9                                                 XREF[1]:     0045a543(j)  
    //                              map.cpp:3089 (19)
    //         0045a5f9     XOR        this,this
    //         0045a5fb     CMP        word ptr [EBP + 0x8d92],this
    //         0045a602     MOV        dword ptr [ESP + cur_time],this
    //         0045a606     JLE        LAB_0045a6bb
    //                               LAB_0045a60c                                                 XREF[1]:     0045a6b5(j)  
    //                              map.cpp:3091 (19)
    //         0045a60c     MOVSX      EAX,this
    //         0045a60f     LEA        EAX,[EAX + EAX*0x4]
    //         0045a612     LEA        EAX,[EAX + EAX*0x8]
    //         0045a615     SHL        EAX,0x5
    //         0045a618     LEA        ESI,[EAX + EBP*0x1 + 0x338c]
    //                              map.cpp:3092 (11)
    //         0045a61f     MOV        AL,byte ptr [EAX + EBP*0x1 + 0x33b7]
    //         0045a626     TEST       AL,AL
    //         0045a628     JZ         LAB_0045a6a9
    //                              map.cpp:3094 (4)
    //         0045a62a     FLD        float ptr [ESP + local_c]
    //                              map.cpp:3095 (13)
    //         0045a62e     FSUB       float ptr [ESI + 0x3c]
    //         0045a631     FCOM       float ptr [ESI + 0x30]
    //         0045a634     FNSTSW     AX
    //         0045a636     TEST       AH,0x1
    //         0045a639     JNZ        LAB_0045a6a7
    //                              map.cpp:3098 (10)
    //         0045a63b     FLD        ST0
    //         0045a63d     FDIV       float ptr [ESI + 0x30]
    //         0045a640     CALL       __ftol                                           undefined __ftol()
    //                              map.cpp:3100 (20)
    //         0045a645     MOV        DI,word ptr [ESI + 0x2c]
    //         0045a649     MOV        this,word ptr [ESI + 0x2e]
    //         0045a64d     MOV        EBX,EAX
    //         0045a64f     ADD        this,DI
    //         0045a652     MOV        DX,BX
    //         0045a655     ADD        DX,word ptr [ESI + 0x38]
    //                              map.cpp:3101 (5)
    //         0045a659     CMP        DX,this
    //         0045a65c     JL         LAB_0045a667
    //                              map.cpp:3102 (9)
    //         0045a65e     MOVSX      EAX,DX
    //         0045a661     MOVSX      this,this
    //         0045a664     CDQ
    //         0045a665     IDIV       this
    //                               LAB_0045a667                                                 XREF[1]:     0045a65c(j)  
    //                              map.cpp:3106 (9)
    //         0045a667     CMP        DX,DI
    //         0045a66a     MOV        word ptr [ESI + 0x38],DX
    //         0045a66e     JL         LAB_0045a673
    //                              map.cpp:3107 (3)
    //         0045a670     LEA        EDX,[EDI + -0x1]
    //                               LAB_0045a673                                                 XREF[1]:     0045a66e(j)  
    //                              map.cpp:3110 (6)
    //         0045a673     CMP        word ptr [ESI + 0x3a],DX
    //         0045a677     JZ         LAB_0045a688
    //                              map.cpp:3112 (4)
    //         0045a679     MOV        word ptr [ESI + 0x3a],DX
    //                              map.cpp:3113 (4)
    //         0045a67d     MOV        byte ptr [ESI + 0x40],0x1
    //                              map.cpp:3114 (7)
    //         0045a681     MOV        byte ptr [EBP + 0x8dac],0x1
    //                               LAB_0045a688                                                 XREF[1]:     0045a677(j)  
    //                              map.cpp:3118 (31)
    //         0045a688     MOVSX      EDX,BX
    //         0045a68b     MOV        dword ptr [ESP + local_8],EDX
    //         0045a68f     MOV        this,dword ptr [ESP + cur_time]
    //         0045a693     FILD       dword ptr [ESP + local_8]
    //         0045a697     FMUL       float ptr [ESI + 0x30]
    //         0045a69a     FSUBR      ST0,ST1
    //         0045a69c     FSUBR      float ptr [ESP + local_c]
    //         0045a6a0     FSTP       float ptr [ESI + 0x3c]
    //         0045a6a3     FSTP       ST0
    //         0045a6a5     JMP        LAB_0045a6a9
    //                               LAB_0045a6a7                                                 XREF[1]:     0045a639(j)  
    //                              map.cpp:3095 (2)
    //         0045a6a7     FSTP       ST0
    //                               LAB_0045a6a9                                                 XREF[2]:     0045a628(j), 0045a6a5(j)  
    //                              map.cpp:3118 (18)
    //         0045a6a9     INC        this
    //         0045a6aa     CMP        this,word ptr [EBP + 0x8d92]
    //         0045a6b1     MOV        dword ptr [ESP + cur_time],this
    //         0045a6b5     JL         LAB_0045a60c
    //                               LAB_0045a6bb                                                 XREF[1]:     0045a606(j)  
    //                              map.cpp:3124 (11)
    //         0045a6bb     MOV        EAX,dword ptr [ESP + param_1]
    //         0045a6bf     POP        EBX
    //         0045a6c0     MOV        [DAT_0062e65c],EAX
    //         0045a6c5     POP        EDI
    //                               LAB_0045a6c6                                                 XREF[1]:     0045a518(j)  
    //                              map.cpp:3125 (8)
    //         0045a6c6     POP        ESI
    //         0045a6c7     POP        EBP
    //         0045a6c8     ADD        ESP,0x10
    //         0045a6cb     RET        0x4
}

// Offset: 0x0045A6D0
void get_point(RGE_Map* this_, short* param_2, short* param_3, float param_4, float param_5, float param_6, short param_7, short param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Map::get_point(short &,short &,float,float,float,short,short)             *
    //                              *********************************************************************************************************
    //                              void __thiscall get_point(RGE_Map * this, short * param_1, short * p
    //              void              <VOID>         <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              short *           Stack[0x4]:4   param_1                   XREF[1]:     0045a700(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[1]:     0045a72c(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     0045a6d8(R), 0045a704(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[4]:     0045a6d1(R), 0045a6f4(R), 0045a716(W), 0045a71a(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0045a712(R)  
    //              short             Stack[0x18]:2  param_6                   XREF[1]:     0045a6f0(R)  
    //              short             Stack[0x1c]:2  param_7                   XREF[1]:     0045a723(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045a6e3(W), 0045a6e7(R)  
    //                               ?get_point@RGE_Map@@QAEXAAF0MMMFF@Z                          XREF[71]:    capture_frame_3d_square:004c24ff(c
    //                               RGE_Map::get_point                                                        capture_frame_3d_square:004c2521(c
    //                                                                                                         capture_frame_3d_square:004c254a(c
    //                                                                                                         capture_frame_3d_square:004c2569(c
    //                                                                                                         capture_frame_3d_square:004c2688(c
    //                                                                                                         draw_frame_3d_square_back:004c2a54
    //                                                                                                         draw_frame_3d_square_back:004c2a73
    //                                                                                                         draw_frame_3d_square_back:004c2ac0
    //                                                                                                         draw_frame_3d_square_back:004c2ae4
    //                                                                                                         draw_frame_3d_square_front:004c2c4
    //                                                                                                         draw_frame_3d_square_front:004c2c6
    //                                                                                                         draw_frame_3d_square_front:004c2cb
    //                                                                                                         draw_frame_3d_square_front:004c2cd
    //                                                                                                         draw_frame_3d_square_front:004c2d6
    //                                                                                                         draw_frame_3d_cube_back:004c2f22(c
    //                                                                                                         draw_frame_3d_cube_back:004c2f44(c
    //                                                                                                         draw_frame_3d_cube_back:004c2f94(c
    //                                                                                                         draw_frame_3d_cube_back:004c2fb6(c
    //                                                                                                         draw_frame_3d_cube_back:004c3003(c
    //                                                                                                         draw_frame_3d_cube_back:004c3022(c
    //                                                                                                         [more]
    //                              map.cpp:3129 (1)
    //         0045a6d0     PUSH       this
    //                              map.cpp:3130 (35)
    //         0045a6d1     FLD        float ptr [ESP + param_4]
    //         0045a6d5     PUSH       ESI
    //         0045a6d6     MOV        ESI,this
    //         0045a6d8     FADD       float ptr [ESP + param_3]
    //         0045a6dc     MOVSX      EAX,word ptr [ESI + 0x8d9c]
    //         0045a6e3     MOV        dword ptr [ESP + local_4],EAX
    //         0045a6e7     FIMUL      dword ptr [ESP + local_4]
    //         0045a6eb     CALL       __ftol                                           undefined __ftol()
    //         0045a6f0     MOV        this,dword ptr [ESP + param_6]
    //                              map.cpp:3131 (51)
    //         0045a6f4     FLD        float ptr [ESP + param_4]
    //         0045a6f8     FSUB       float ptr [DAT_005706ec]
    //         0045a6fe     ADD        EAX,this
    //         0045a700     MOV        this,dword ptr [ESP + param_1]
    //         0045a704     FSUB       float ptr [ESP + param_3]
    //         0045a708     MOV        word ptr [this->_padding_],AX
    //         0045a70b     MOVSX      EDX,word ptr [ESI + 0x8d9a]
    //         0045a712     FSUB       float ptr [ESP + param_5]
    //         0045a716     MOV        dword ptr [ESP + param_4],EDX
    //         0045a71a     FIMUL      dword ptr [ESP + param_4]
    //         0045a71e     CALL       __ftol                                           undefined __ftol()
    //         0045a723     MOV        this,dword ptr [ESP + param_7]
    //                              map.cpp:3132 (16)
    //         0045a727     POP        ESI
    //         0045a728     LEA        EDX,[EAX + this->_padding_*0x1 + -0x10]
    //         0045a72c     MOV        EAX,dword ptr [ESP + param_2]
    //         0045a730     MOV        word ptr [EAX],DX
    //         0045a733     POP        this
    //         0045a734     RET        0x1c
}

