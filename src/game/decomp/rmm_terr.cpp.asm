// Auto-generated scaffold unit: rmm_terr.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/rmm_terr.cpp
#include "../include/common.h"

// Offset: 0x004888E0
undefined RGE_RMM_Terrain_Generator(RGE_RMM_Terrain_Generator* this_, RGE_Map* param_2, RGE_Random_Map_Module* param_3, RGE_Terrain_Info* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(class RGE_Map *,class RGE_... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_RMM_Terrain_Generator(RGE_RMM_Terrain_Gener
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     004888e8(R)  
    //              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     004888e0(R)  
    //              RGE_Terrain_In    Stack[0xc]:4   param_3                   XREF[1]:     004888f8(R)  
    //                               ??0RGE_RMM_Terrain_Generator@@QAE@PAVRGE_Map@@PAVRGE_Random  XREF[2]:     add_terrain_module:00482864(c), 
    //                               RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator                      generate:00483475(c)  
    //                              rmm_terr.cpp:24 (24)
    //         004888e0     MOV        EAX,dword ptr [ESP + param_2]
    //         004888e4     PUSH       EBX
    //         004888e5     PUSH       ESI
    //         004888e6     MOV        EBX,this
    //         004888e8     MOV        this,dword ptr [ESP + param_1]
    //         004888ec     PUSH       EDI
    //         004888ed     PUSH       0x1
    //         004888ef     PUSH       EAX
    //         004888f0     PUSH       this
    //         004888f1     MOV        this,EBX
    //         004888f3     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
    //                              rmm_terr.cpp:25 (20)
    //         004888f8     MOV        ESI,dword ptr [ESP + param_3]
    //         004888fc     MOV        this,0x4a6
    //         00488901     LEA        EDI,[EBX + 0x30]
    //         00488904     MOV        dword ptr [EBX],RGE_RMM_Terrain_Generator::`vf   = 00488920
    //         0048890a     MOVSD.REP  ES:EDI,ESI
    //                              rmm_terr.cpp:28 (15)
    //         0048890c     POP        EDI
    //         0048890d     MOV        dword ptr [EBX + 0x1c],0x40000000
    //         00488914     MOV        EAX,EBX
    //         00488916     POP        ESI
    //         00488917     POP        EBX
    //         00488918     RET        0xc
}

// Offset: 0x00488920
uchar RGE_RMM_Terrain_Generator::generate() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_RMM_Terrain_Generator::generate(void)                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall generate(RGE_RMM_Terrain_Generator * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              float[99]         Stack[-0x190   terrain_table             XREF[7,3]:   00488937(W), 0048893b(R), 00488946(W), 00488988(W), 
    //                                                                                     0048898c(R), 004889a3(R), 004889b3(W), 00488933(*), 
    //                                                                                     0048894a(W), 00488952(*)  
    //              long              Stack[-0x194   index
    //                               ?generate@RGE_RMM_Terrain_Generator@@UAEEXZ                  XREF[1]:     00571f58(*)  
    //                               RGE_RMM_Terrain_Generator::generate
    //                              rmm_terr.cpp:32 (12)
    //         00488920     SUB        ESP,0x190
    //         00488926     PUSH       EBX
    //         00488927     PUSH       EBP
    //         00488928     PUSH       ESI
    //         00488929     PUSH       EDI
    //         0048892a     MOV        EBX,this
    //                              rmm_terr.cpp:38 (5)
    //         0048892c     CALL       RGE_RMM_Terrain_Generator::generate_modifiers    void generate_modifiers(RGE_RMM_Terrain_Gener
    //                              rmm_terr.cpp:41 (10)
    //         00488931     XOR        EAX,EAX
    //         00488933     LEA        this=>terrain_table[1],[ESP + 0x14]
    //         00488937     MOV        dword ptr [ESP + terrain_table[0]],EAX
    //                               LAB_0048893b                                                 XREF[1]:     0048894d(j)  
    //                              rmm_terr.cpp:42 (20)
    //         0048893b     FILD       dword ptr [ESP + terrain_table[0]]
    //         0048893f     INC        EAX
    //         00488940     ADD        this,0x4
    //         00488943     CMP        EAX,0x63
    //         00488946     MOV        dword ptr [ESP + terrain_table[0]],EAX
    //         0048894a     FSTP       float ptr [ECX + terrain_table[1]]
    //         0048894d     JL         LAB_0048893b
    //                              rmm_terr.cpp:43 (42)
    //         0048894f     MOV        this,dword ptr [EBX + 0xc]
    //         00488952     LEA        EAX=>terrain_table[1],[ESP + 0x14]
    //         00488956     PUSH       0x63
    //         00488958     PUSH       EAX
    //         00488959     MOV        this,dword ptr [this->_padding_ + 0x8dc4]
    //         0048895f     CALL       RGE_Zone_Map_List::create_zone_map               long create_zone_map(RGE_Zone_Map_List * this
    //         00488964     MOV        EDX,dword ptr [EBX + 0xc]
    //         00488967     PUSH       EAX
    //         00488968     MOV        this,dword ptr [EDX + 0x8dc4]
    //         0048896e     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
    //         00488973     MOV        dword ptr [EBX + 0x12c8],EAX
    //                              rmm_terr.cpp:46 (12)
    //         00488979     MOV        EAX,dword ptr [EBX + 0xc90]
    //         0048897f     XOR        EBP,EBP
    //         00488981     TEST       EAX,EAX
    //         00488983     JLE        LAB_004889b9
    //                              rmm_terr.cpp:54 (52)
    //         00488985     LEA        EAX,[EBX + 0x30]
    //         00488988     MOV        dword ptr [ESP + terrain_table[0]],EAX
    //                               LAB_0048898c                                                 XREF[1]:     004889b7(j)  
    //         0048898c     MOV        ESI,dword ptr [ESP + terrain_table[0]]
    //         00488990     SUB        ESP,0x20
    //         00488993     MOV        this,0x8
    //         00488998     MOV        EDI,ESP
    //         0048899a     MOVSD.REP  ES:EDI,ESI
    //         0048899c     MOV        this,EBX
    //         0048899e     CALL       RGE_RMM_Terrain_Generator::base_terrain_generate uchar base_terrain_generate(RGE_RMM_Terrain_G
    //         004889a3     MOV        this,dword ptr [ESP + terrain_table[0]]
    //         004889a7     MOV        EAX,dword ptr [EBX + 0xc90]
    //         004889ad     INC        EBP
    //         004889ae     ADD        this,0x20
    //         004889b1     CMP        EBP,EAX
    //         004889b3     MOV        dword ptr [ESP + terrain_table[0]],this
    //         004889b7     JL         LAB_0048898c
    //                               LAB_004889b9                                                 XREF[1]:     00488983(j)  
    //                              rmm_terr.cpp:49 (7)
    //         004889b9     MOV        this,EBX
    //         004889bb     CALL       RGE_RMM_Terrain_Generator::check_borders         void check_borders(RGE_RMM_Terrain_Generator 
    //                              rmm_terr.cpp:54 (13)
    //         004889c0     POP        EDI
    //         004889c1     POP        ESI
    //         004889c2     POP        EBP
    //         004889c3     MOV        AL,0x1
    //         004889c5     POP        EBX
    //         004889c6     ADD        ESP,0x190
    //         004889cc     RET
}

// Offset: 0x004889D0
uchar water(RGE_RMM_Terrain_Generator* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_RMM_Terrain_Generator::water(unsigned char)                   *
    //                              *********************************************************************************************************
    //                              uchar __thiscall water(RGE_RMM_Terrain_Generator * this, uchar param
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004889d0(R)  
    //                               ?water@RGE_RMM_Terrain_Generator@@IAEEE@Z                    XREF[9]:     check_borders:00488a35(c), 
    //                               RGE_RMM_Terrain_Generator::water                                          check_borders:00488a59(c), 
    //                                                                                                         check_borders:00488a79(c), 
    //                                                                                                         check_borders:00488a98(c), 
    //                                                                                                         check_borders:00488ab6(c), 
    //                                                                                                         check_borders:00488ad6(c), 
    //                                                                                                         check_borders:00488afc(c), 
    //                                                                                                         check_borders:00488b19(c), 
    //                                                                                                         check_borders:00488b38(c)  
    //                              rmm_terr.cpp:62 (8)
    //         004889d0     MOV        AL,byte ptr [ESP + param_1]
    //         004889d4     CMP        AL,0x1
    //         004889d6     JNZ        LAB_004889db
    //                              rmm_terr.cpp:70 (3)
    //         004889d8     RET        0x4
    //                               LAB_004889db                                                 XREF[1]:     004889d6(j)  
    //                              rmm_terr.cpp:65 (4)
    //         004889db     CMP        AL,0x4
    //         004889dd     JNZ        LAB_004889e4
    //                              rmm_terr.cpp:66 (2)
    //         004889df     MOV        AL,0x1
    //                              rmm_terr.cpp:70 (3)
    //         004889e1     RET        0x4
    //                               LAB_004889e4                                                 XREF[1]:     004889dd(j)  
    //                              rmm_terr.cpp:67 (5)
    //         004889e4     CMP        AL,0x16
    //         004889e6     SETZ       AL
    //                              rmm_terr.cpp:70 (3)
    //         004889e9     RET        0x4
}

// Offset: 0x004889F0
void check_borders(RGE_RMM_Terrain_Generator* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_RMM_Terrain_Generator::check_borders(void)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall check_borders(RGE_RMM_Terrain_Generator * this)
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00488a0b(W), 00488ae1(R)  
    //              long              Stack[-0x8]:4  max_x                     XREF[4]:     00488a1b(W), 00488ae5(R), 00488b5e(R), 00488b6b(W)  
    //              long              Stack[-0xc]:4  x                         XREF[4]:     00488a01(W), 00488a62(R), 00488abf(R), 00488b22(R)  
    //              long              Stack[-0x10]:4 max_y
    //                               ?check_borders@RGE_RMM_Terrain_Generator@@IAEXXZ             XREF[1]:     generate:004889bb(c)  
    //                               RGE_RMM_Terrain_Generator::check_borders
    //                              rmm_terr.cpp:76 (7)
    //         004889f0     SUB        ESP,0xc
    //         004889f3     PUSH       EBP
    //         004889f4     PUSH       ESI
    //         004889f5     MOV        ESI,this
    //                              rmm_terr.cpp:86 (32)
    //         004889f7     XOR        EBP,EBP
    //         004889f9     MOV        this,dword ptr [ESI + 0x18]
    //         004889fc     TEST       this,this
    //         004889fe     LEA        EAX,[this->_padding_ + -0x1]
    //         00488a01     MOV        dword ptr [ESP + x],EAX
    //         00488a05     MOV        EAX,dword ptr [ESI + 0x14]
    //         00488a08     LEA        EDX,[EAX + -0x1]
    //         00488a0b     MOV        dword ptr [ESP + local_4],EDX
    //         00488a0f     JLE        LAB_00488b83
    //         00488a15     PUSH       EDI
    //         00488a16     PUSH       EBX
    //                               LAB_00488a17                                                 XREF[1]:     00488b7b(j)  
    //                              rmm_terr.cpp:87 (14)
    //         00488a17     XOR        EDI,EDI
    //         00488a19     CMP        EAX,EDI
    //         00488a1b     MOV        dword ptr [ESP + max_x],EDI
    //         00488a1f     JLE        LAB_00488b75
    //                               LAB_00488a25                                                 XREF[1]:     00488b6f(j)  
    //                              rmm_terr.cpp:88 (29)
    //         00488a25     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488a28     MOV        this,dword ptr [EAX + EBP*0x4]
    //         00488a2b     MOV        DL,byte ptr [ECX + EDI*0x1 + this+0x5]
    //         00488a2f     MOV        this,ESI
    //         00488a31     AND        DL,0x1f
    //         00488a34     PUSH       EDX
    //         00488a35     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488a3a     TEST       AL,AL
    //         00488a3c     JNZ        LAB_00488b5e
    //                              rmm_terr.cpp:90 (2)
    //         00488a42     XOR        BL,BL
    //                              rmm_terr.cpp:93 (62)
    //         00488a44     TEST       EBP,EBP
    //         00488a46     JLE        LAB_00488a62
    //         00488a48     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488a4b     MOV        this,dword ptr [EAX + EBP*0x4 + -0x4]
    //         00488a4f     MOV        DL,byte ptr [ECX + EDI*0x1 + this+0x5]
    //         00488a53     MOV        this,ESI
    //         00488a55     AND        DL,0x1f
    //         00488a58     PUSH       EDX
    //         00488a59     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488a5e     TEST       AL,AL
    //         00488a60     JNZ        LAB_00488a82
    //                               LAB_00488a62                                                 XREF[1]:     00488a46(j)  
    //         00488a62     CMP        EBP,dword ptr [ESP + x]
    //         00488a66     JGE        LAB_00488a84
    //         00488a68     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488a6b     MOV        this,dword ptr [EAX + EBP*0x4 + 0x4]
    //         00488a6f     MOV        DL,byte ptr [ECX + EDI*0x1 + this+0x5]
    //         00488a73     MOV        this,ESI
    //         00488a75     AND        DL,0x1f
    //         00488a78     PUSH       EDX
    //         00488a79     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488a7e     TEST       AL,AL
    //         00488a80     JZ         LAB_00488a84
    //                               LAB_00488a82                                                 XREF[1]:     00488a60(j)  
    //                              rmm_terr.cpp:94 (2)
    //         00488a82     MOV        BL,0x1
    //                               LAB_00488a84                                                 XREF[2]:     00488a66(j), 00488a80(j)  
    //                              rmm_terr.cpp:96 (4)
    //         00488a84     TEST       EDI,EDI
    //         00488a86     JLE        LAB_00488ae1
    //                              rmm_terr.cpp:100 (87)
    //         00488a88     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488a8b     MOV        this,dword ptr [EAX + EBP*0x4]
    //         00488a8e     MOV        DL,byte ptr [this->_padding_ + EDI*0x1 + -0x13]
    //         00488a92     MOV        this,ESI
    //         00488a94     AND        DL,0x1f
    //         00488a97     PUSH       EDX
    //         00488a98     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488a9d     TEST       AL,AL
    //         00488a9f     JNZ        LAB_00488adf
    //         00488aa1     TEST       EBP,EBP
    //         00488aa3     JLE        LAB_00488abf
    //         00488aa5     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488aa8     MOV        this,dword ptr [EAX + EBP*0x4 + -0x4]
    //         00488aac     MOV        DL,byte ptr [this->_padding_ + EDI*0x1 + -0x13]
    //         00488ab0     MOV        this,ESI
    //         00488ab2     AND        DL,0x1f
    //         00488ab5     PUSH       EDX
    //         00488ab6     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488abb     TEST       AL,AL
    //         00488abd     JNZ        LAB_00488adf
    //                               LAB_00488abf                                                 XREF[1]:     00488aa3(j)  
    //         00488abf     CMP        EBP,dword ptr [ESP + x]
    //         00488ac3     JGE        LAB_00488ae1
    //         00488ac5     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488ac8     MOV        this,dword ptr [EAX + EBP*0x4 + 0x4]
    //         00488acc     MOV        DL,byte ptr [this->_padding_ + EDI*0x1 + -0x13]
    //         00488ad0     MOV        this,ESI
    //         00488ad2     AND        DL,0x1f
    //         00488ad5     PUSH       EDX
    //         00488ad6     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488adb     TEST       AL,AL
    //         00488add     JZ         LAB_00488ae1
    //                               LAB_00488adf                                                 XREF[2]:     00488a9f(j), 00488abd(j)  
    //                              rmm_terr.cpp:101 (2)
    //         00488adf     MOV        BL,0x1
    //                               LAB_00488ae1                                                 XREF[3]:     00488a86(j), 00488ac3(j), 
    //                                                                                                         00488add(j)  
    //                              rmm_terr.cpp:103 (12)
    //         00488ae1     MOV        EAX,dword ptr [ESP + local_4]
    //         00488ae5     MOV        this,dword ptr [ESP + max_x]
    //         00488ae9     CMP        this,EAX
    //         00488aeb     JGE        LAB_00488b43
    //                              rmm_terr.cpp:107 (84)
    //         00488aed     MOV        this,dword ptr [ESI + 0x10]
    //         00488af0     MOV        EDX,dword ptr [this->_padding_ + EBP*0x4]
    //         00488af3     MOV        this,ESI
    //         00488af5     MOV        AL,byte ptr [EDX + EDI*0x1 + 0x1d]
    //         00488af9     AND        AL,0x1f
    //         00488afb     PUSH       EAX
    //         00488afc     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488b01     TEST       AL,AL
    //         00488b03     JNZ        LAB_00488b41
    //         00488b05     TEST       EBP,EBP
    //         00488b07     JLE        LAB_00488b22
    //         00488b09     MOV        this,dword ptr [ESI + 0x10]
    //         00488b0c     MOV        EDX,dword ptr [this->_padding_ + EBP*0x4 + -0x4]
    //         00488b10     MOV        this,ESI
    //         00488b12     MOV        AL,byte ptr [EDX + EDI*0x1 + 0x1d]
    //         00488b16     AND        AL,0x1f
    //         00488b18     PUSH       EAX
    //         00488b19     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488b1e     TEST       AL,AL
    //         00488b20     JNZ        LAB_00488b41
    //                               LAB_00488b22                                                 XREF[1]:     00488b07(j)  
    //         00488b22     CMP        EBP,dword ptr [ESP + x]
    //         00488b26     JGE        LAB_00488b43
    //         00488b28     MOV        this,dword ptr [ESI + 0x10]
    //         00488b2b     MOV        EDX,dword ptr [ECX + EBP*this->_padding_ + 0x4]
    //         00488b2f     MOV        this,ESI
    //         00488b31     MOV        AL,byte ptr [EDX + EDI*0x1 + 0x1d]
    //         00488b35     AND        AL,0x1f
    //         00488b37     PUSH       EAX
    //         00488b38     CALL       RGE_RMM_Terrain_Generator::water                 uchar water(RGE_RMM_Terrain_Generator * this,
    //         00488b3d     TEST       AL,AL
    //         00488b3f     JZ         LAB_00488b43
    //                               LAB_00488b41                                                 XREF[2]:     00488b03(j), 00488b20(j)  
    //                              rmm_terr.cpp:108 (2)
    //         00488b41     MOV        BL,0x1
    //                               LAB_00488b43                                                 XREF[3]:     00488aeb(j), 00488b26(j), 
    //                                                                                                         00488b3f(j)  
    //                              rmm_terr.cpp:111 (5)
    //         00488b43     CMP        BL,0x1
    //         00488b46     JNZ        LAB_00488b5e
    //                              rmm_terr.cpp:112 (45)
    //         00488b48     MOV        this,dword ptr [ESI + 0x10]
    //         00488b4b     MOV        EDX,dword ptr [this->_padding_ + EBP*0x4]
    //         00488b4e     MOV        this,byte ptr [EDX + EDI*0x1 + 0x5]
    //         00488b52     AND        this,0xe2
    //         00488b55     LEA        EAX,[EDX + EDI*0x1 + 0x5]
    //         00488b59     OR         this,0x2
    //         00488b5c     MOV        byte ptr [EAX],this
    //                               LAB_00488b5e                                                 XREF[2]:     00488a3c(j), 00488b46(j)  
    //         00488b5e     MOV        this,dword ptr [ESP + max_x]
    //         00488b62     MOV        EAX,dword ptr [ESI + 0x14]
    //         00488b65     INC        this
    //         00488b66     ADD        EDI,0x18
    //         00488b69     CMP        this,EAX
    //         00488b6b     MOV        dword ptr [ESP + max_x],this
    //         00488b6f     JL         LAB_00488a25
    //                               LAB_00488b75                                                 XREF[1]:     00488a1f(j)  
    //                              rmm_terr.cpp:86 (14)
    //         00488b75     MOV        this,dword ptr [ESI + 0x18]
    //         00488b78     INC        EBP
    //         00488b79     CMP        EBP,this
    //         00488b7b     JL         LAB_00488a17
    //         00488b81     POP        EBX
    //         00488b82     POP        EDI
    //                               LAB_00488b83                                                 XREF[1]:     00488a0f(j)  
    //                              rmm_terr.cpp:116 (6)
    //         00488b83     POP        ESI
    //         00488b84     POP        EBP
    //         00488b85     ADD        ESP,0xc
    //         00488b88     RET
}

// Offset: 0x00488B90
uchar check_terrain(RGE_RMM_Terrain_Generator* this_, uchar param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_RMM_Terrain_Generator::check_terrain(unsigned char,long,lo... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_terrain(RGE_RMM_Terrain_Generator * this, uch
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[2]:     00488c5a(R), 00488d09(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     00488bd3(R), 00488ca2(R), 00488cf7(W), 00488d25(R), 
    //                                                                                     00488d31(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     00488bd7(R), 00488ca6(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[5]:     00488bc3(R), 00488be9(W), 00488c09(W), 00488c1d(R), 
    //                                                                                     00488c84(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[5]:     00488b96(R), 00488c42(R), 00488cb8(W), 00488cd0(W), 
    //                                                                                     00488d1e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00488c25(W), 00488c68(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00488bc9(W), 00488c4f(R)  
    //              long              Stack[-0xc]:4  i_base_terrain            XREF[3]:     00488c33(W), 00488c70(R), 00488c7d(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00488c29(W), 00488c74(R), 00488c8a(W)  
    //              long              Stack[-0x14]:4 index1                    XREF[3]:     00488bae(W), 00488d14(RW), 00488d37(R)  
    //              long              Stack[-0x18]:4 count                     XREF[4]:     00488baa(W), 00488c2f(R), 00488c6c(R), 00488c9e(R)  
    //                               ?check_terrain@RGE_RMM_Terrain_Generator@@IAEEEJJJE@Z        XREF[3]:     base_terrain_generate:00489177(c), 
    //                               RGE_RMM_Terrain_Generator::check_terrain                                  base_terrain_generate:0048933f(c), 
    //                                                                                                         base_terrain_generate:00489557(c)  
    //                              rmm_terr.cpp:121 (6)
    //         00488b90     SUB        ESP,0x18
    //         00488b93     PUSH       EBX
    //         00488b94     PUSH       EBP
    //         00488b95     PUSH       ESI
    //                              rmm_terr.cpp:130 (45)
    //         00488b96     MOV        ESI,dword ptr [ESP + param_5]
    //         00488b9a     AND        ESI,0xff
    //         00488ba0     XOR        EBX,EBX
    //         00488ba2     MOV        EDX,ESI
    //         00488ba4     PUSH       EDI
    //         00488ba5     SHL        EDX,0x4
    //         00488ba8     ADD        EDX,ESI
    //         00488baa     MOV        dword ptr [ESP + count],this
    //         00488bae     MOV        dword ptr [ESP + index1],0x1
    //         00488bb6     LEA        EAX,[EDX + EDX*0x2]
    //         00488bb9     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00488bbc     MOV        BL,byte ptr [EDX + EAX*0x8 + 0xba]
    //                              rmm_terr.cpp:133 (16)
    //         00488bc3     MOV        EDX,dword ptr [ESP + param_4]
    //         00488bc7     TEST       EDX,EDX
    //         00488bc9     MOV        dword ptr [ESP + local_8],EBX
    //         00488bcd     JLE        LAB_00488ca2
    //                              rmm_terr.cpp:138 (20)
    //         00488bd3     MOV        EAX,dword ptr [ESP + param_2]
    //         00488bd7     MOV        EDI,dword ptr [ESP + param_3]
    //         00488bdb     MOV        EBP,EAX
    //         00488bdd     MOV        ESI,EDI
    //         00488bdf     SUB        EBP,EDX
    //         00488be1     SUB        ESI,EDX
    //         00488be3     ADD        EAX,EDX
    //         00488be5     ADD        EDI,EDX
    //                              rmm_terr.cpp:140 (10)
    //         00488be7     TEST       EBP,EBP
    //         00488be9     MOV        dword ptr [ESP + param_4],EDI
    //         00488bed     JGE        LAB_00488bf1
    //         00488bef     XOR        EBP,EBP
    //                               LAB_00488bf1                                                 XREF[1]:     00488bed(j)  
    //                              rmm_terr.cpp:141 (6)
    //         00488bf1     TEST       ESI,ESI
    //         00488bf3     JGE        LAB_00488bf7
    //         00488bf5     XOR        ESI,ESI
    //                               LAB_00488bf7                                                 XREF[1]:     00488bf3(j)  
    //                              rmm_terr.cpp:142 (10)
    //         00488bf7     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00488bfa     CMP        EAX,EDX
    //         00488bfc     JL         LAB_00488c01
    //         00488bfe     LEA        EAX,[EDX + -0x1]
    //                               LAB_00488c01                                                 XREF[1]:     00488bfc(j)  
    //                              rmm_terr.cpp:143 (12)
    //         00488c01     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00488c04     CMP        EDI,EDX
    //         00488c06     JL         LAB_00488c0d
    //         00488c08     DEC        EDX
    //         00488c09     MOV        dword ptr [ESP + param_4],EDX
    //                               LAB_00488c0d                                                 XREF[1]:     00488c06(j)  
    //                              rmm_terr.cpp:145 (16)
    //         00488c0d     MOV        this,dword ptr [ECX + this->_padding_]
    //         00488c10     LEA        EBX,[EBP + EBP*0x2]
    //         00488c14     SHL        EBX,0x3
    //         00488c17     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         00488c1a     LEA        EDI,[this->_padding_ + ESI*0x4]
    //                              rmm_terr.cpp:147 (26)
    //         00488c1d     MOV        this,dword ptr [ESP + param_4]
    //         00488c21     ADD        EDX,EBX
    //         00488c23     CMP        ESI,this
    //         00488c25     MOV        dword ptr [ESP + local_4],EBX
    //         00488c29     MOV        dword ptr [ESP + local_10],ESI
    //         00488c2d     JG         LAB_00488c9e
    //         00488c2f     MOV        this,dword ptr [ESP + count]
    //         00488c33     MOV        dword ptr [ESP + i_base_terrain],EDI
    //                               LAB_00488c37                                                 XREF[1]:     00488c8e(j)  
    //                              rmm_terr.cpp:148 (9)
    //         00488c37     CMP        EBP,EAX
    //         00488c39     MOV        EDI,EBP
    //         00488c3b     JG         LAB_00488c70
    //         00488c3d     LEA        ESI,[EDX + 0x5]
    //                               LAB_00488c40                                                 XREF[1]:     00488c66(j)  
    //                              rmm_terr.cpp:149 (32)
    //         00488c40     MOV        DL,byte ptr [ESI]
    //         00488c42     MOV        this,byte ptr [ESP + param_5]
    //         00488c46     MOV        BL,DL
    //         00488c48     AND        BL,0x1f
    //         00488c4b     CMP        BL,this
    //         00488c4d     JZ         LAB_00488c60
    //         00488c4f     MOV        this,dword ptr [ESP + local_8]
    //         00488c53     AND        EDX,0x1f
    //         00488c56     CMP        EDX,this
    //         00488c58     JZ         LAB_00488c60
    //         00488c5a     CMP        BL,byte ptr [ESP + param_1]
    //         00488c5e     JNZ        LAB_00488c92
    //                               LAB_00488c60                                                 XREF[2]:     00488c4d(j), 00488c58(j)  
    //                              rmm_terr.cpp:148 (50)
    //         00488c60     INC        EDI
    //         00488c61     ADD        ESI,0x18
    //         00488c64     CMP        EDI,EAX
    //         00488c66     JLE        LAB_00488c40
    //         00488c68     MOV        EBX,dword ptr [ESP + local_4]
    //         00488c6c     MOV        this,dword ptr [ESP + count]
    //                               LAB_00488c70                                                 XREF[1]:     00488c3b(j)  
    //         00488c70     MOV        EDI,dword ptr [ESP + i_base_terrain]
    //         00488c74     MOV        ESI,dword ptr [ESP + local_10]
    //         00488c78     ADD        EDI,0x4
    //         00488c7b     MOV        EDX,EBX
    //         00488c7d     MOV        dword ptr [ESP + i_base_terrain],EDI
    //         00488c81     INC        ESI
    //         00488c82     ADD        EDX,dword ptr [EDI]
    //         00488c84     MOV        EDI,dword ptr [ESP + param_4]
    //         00488c88     CMP        ESI,EDI
    //         00488c8a     MOV        dword ptr [ESP + local_10],ESI
    //         00488c8e     JLE        LAB_00488c37
    //         00488c90     JMP        LAB_00488ca2
    //                               LAB_00488c92                                                 XREF[1]:     00488c5e(j)  
    //                              rmm_terr.cpp:150 (2)
    //         00488c92     XOR        AL,AL
    //                              rmm_terr.cpp:173 (10)
    //         00488c94     POP        EDI
    //         00488c95     POP        ESI
    //         00488c96     POP        EBP
    //         00488c97     POP        EBX
    //         00488c98     ADD        ESP,0x18
    //         00488c9b     RET        0x14
    //                               LAB_00488c9e                                                 XREF[1]:     00488c2d(j)  
    //                              rmm_terr.cpp:147 (4)
    //         00488c9e     MOV        this,dword ptr [ESP + count]
    //                               LAB_00488ca2                                                 XREF[2]:     00488bcd(j), 00488c90(j)  
    //                              rmm_terr.cpp:157 (20)
    //         00488ca2     MOV        EAX,dword ptr [ESP + param_2]
    //         00488ca6     MOV        EDX,dword ptr [ESP + param_3]
    //         00488caa     LEA        EBP,[EAX + -0x2]
    //         00488cad     LEA        ESI,[EDX + -0x2]
    //         00488cb0     ADD        EAX,0x2
    //         00488cb3     ADD        EDX,0x2
    //                              rmm_terr.cpp:159 (10)
    //         00488cb6     TEST       EBP,EBP
    //         00488cb8     MOV        dword ptr [ESP + param_5],EAX
    //         00488cbc     JGE        LAB_00488cc0
    //         00488cbe     XOR        EBP,EBP
    //                               LAB_00488cc0                                                 XREF[1]:     00488cbc(j)  
    //                              rmm_terr.cpp:160 (6)
    //         00488cc0     TEST       ESI,ESI
    //         00488cc2     JGE        LAB_00488cc6
    //         00488cc4     XOR        ESI,ESI
    //                               LAB_00488cc6                                                 XREF[1]:     00488cc2(j)  
    //                              rmm_terr.cpp:161 (14)
    //         00488cc6     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         00488cc9     CMP        EAX,EDI
    //         00488ccb     JL         LAB_00488cd4
    //         00488ccd     LEA        EAX,[EDI + -0x1]
    //         00488cd0     MOV        dword ptr [ESP + param_5],EAX
    //                               LAB_00488cd4                                                 XREF[1]:     00488ccb(j)  
    //                              rmm_terr.cpp:162 (10)
    //         00488cd4     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         00488cd7     CMP        EDX,EDI
    //         00488cd9     JL         LAB_00488cde
    //         00488cdb     LEA        EDX,[EDI + -0x1]
    //                               LAB_00488cde                                                 XREF[1]:     00488cd9(j)  
    //                              rmm_terr.cpp:164 (18)
    //         00488cde     MOV        this,dword ptr [ECX + this->_padding_]
    //         00488ce1     LEA        EBX,[EBP + EBP*0x2]
    //         00488ce5     SHL        EBX,0x3
    //         00488ce8     LEA        EDI,[this->_padding_ + ESI*0x4]
    //         00488ceb     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
    //         00488cee     ADD        this,EBX
    //                              rmm_terr.cpp:166 (11)
    //         00488cf0     CMP        ESI,EDX
    //         00488cf2     JG         LAB_00488d37
    //         00488cf4     SUB        EDX,ESI
    //         00488cf6     INC        EDX
    //         00488cf7     MOV        dword ptr [ESP + param_2],EDX
    //                               LAB_00488cfb                                                 XREF[1]:     00488d35(j)  
    //                              rmm_terr.cpp:167 (12)
    //         00488cfb     CMP        EBP,EAX
    //         00488cfd     JG         LAB_00488d22
    //         00488cff     LEA        ESI,[ECX + this+0x5]
    //         00488d02     MOV        this,EAX
    //         00488d04     SUB        this,EBP
    //         00488d06     INC        this
    //                               LAB_00488d07                                                 XREF[1]:     00488d1c(j)  
    //                              rmm_terr.cpp:168 (13)
    //         00488d07     MOV        DL,byte ptr [ESI]
    //         00488d09     MOV        AL,byte ptr [ESP + param_1]
    //         00488d0d     AND        DL,0x1f
    //         00488d10     CMP        DL,AL
    //         00488d12     JNZ        LAB_00488d18
    //                              rmm_terr.cpp:169 (10)
    //         00488d14     INC        dword ptr [ESP + index1]
    //                               LAB_00488d18                                                 XREF[1]:     00488d12(j)  
    //         00488d18     ADD        ESI,0x18
    //         00488d1b     DEC        this
    //         00488d1c     JNZ        LAB_00488d07
    //                              rmm_terr.cpp:167 (4)
    //         00488d1e     MOV        EAX,dword ptr [ESP + param_5]
    //                               LAB_00488d22                                                 XREF[1]:     00488cfd(j)  
    //                              rmm_terr.cpp:166 (21)
    //         00488d22     MOV        ESI,dword ptr [EDI + 0x4]
    //         00488d25     MOV        EDX,dword ptr [ESP + param_2]
    //         00488d29     ADD        EDI,0x4
    //         00488d2c     MOV        this,EBX
    //         00488d2e     ADD        this,ESI
    //         00488d30     DEC        EDX
    //         00488d31     MOV        dword ptr [ESP + param_2],EDX
    //         00488d35     JNZ        LAB_00488cfb
    //                               LAB_00488d37                                                 XREF[1]:     00488cf2(j)  
    //                              rmm_terr.cpp:172 (4)
    //         00488d37     MOV        AL,byte ptr [ESP + index1]
    //                              rmm_terr.cpp:173 (10)
    //         00488d3b     POP        EDI
    //         00488d3c     POP        ESI
    //         00488d3d     POP        EBP
    //         00488d3e     POP        EBX
    //         00488d3f     ADD        ESP,0x18
    //         00488d42     RET        0x14
}

// Offset: 0x00488D50
void generate_modifiers(RGE_RMM_Terrain_Generator* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_RMM_Terrain_Generator::generate_modifiers(void)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall generate_modifiers(RGE_RMM_Terrain_Generator * this)
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00488dcc(W), 00488dd0(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00488da3(W), 00488df4(R), 00488dfc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     00488d97(W), 00488de7(R), 00488df0(W), 00488e02(R)  
    //              long              Stack[-0x10]:4 modifier
    //                               ?generate_modifiers@RGE_RMM_Terrain_Generator@@IAEXXZ        XREF[1]:     generate:0048892c(c)  
    //                               RGE_RMM_Terrain_Generator::generate_modifiers
    //                              rmm_terr.cpp:179 (3)
    //         00488d50     SUB        ESP,0xc
    //                              rmm_terr.cpp:189 (19)
    //         00488d53     XOR        EAX,EAX
    //         00488d55     PUSH       EBX
    //         00488d56     MOV        EBX,this
    //         00488d58     PUSH       EBP
    //         00488d59     PUSH       EDI
    //         00488d5a     MOV        this,dword ptr [EBX + 0x14]
    //         00488d5d     MOV        EDI,dword ptr [EBX + 0x20]
    //         00488d60     IMUL       this,dword ptr [EBX + 0x18]
    //         00488d64     MOV        EDX,this
    //                              rmm_terr.cpp:191 (25)
    //         00488d66     XOR        EBP,EBP
    //         00488d68     SHR        this,0x2
    //         00488d6b     STOSD.REP  ES:EDI
    //         00488d6d     MOV        this,EDX
    //         00488d6f     AND        this,0x3
    //         00488d72     STOSB.REP  ES:EDI
    //         00488d74     MOV        EAX,dword ptr [EBX + 0x18]
    //         00488d77     TEST       EAX,EAX
    //         00488d79     JLE        LAB_00488e39
    //                              rmm_terr.cpp:179 (1)
    //         00488d7f     PUSH       ESI
    //                               LAB_00488d80                                                 XREF[1]:     00488e32(j)  
    //                              rmm_terr.cpp:192 (13)
    //         00488d80     MOV        EAX,dword ptr [EBX + 0x14]
    //         00488d83     XOR        EDI,EDI
    //         00488d85     TEST       EAX,EAX
    //         00488d87     JLE        LAB_00488e2c
    //                               LAB_00488d8d                                                 XREF[1]:     00488e26(j)  
    //                              rmm_terr.cpp:195 (39)
    //         00488d8d     MOV        EAX,dword ptr [EBX + 0x12c4]
    //         00488d93     XOR        this,this
    //         00488d95     TEST       EAX,EAX
    //         00488d97     MOV        dword ptr [ESP + local_c],this
    //         00488d9b     JLE        LAB_00488e06
    //         00488d9d     LEA        ESI,[EBX + 0xc98]
    //         00488da3     MOV        dword ptr [ESP + local_8],EAX
    //                               LAB_00488da7                                                 XREF[1]:     00488e00(j)  
    //         00488da7     MOV        this,dword ptr [ESI + -0x4]
    //         00488daa     MOV        EDX,dword ptr [ESI]
    //         00488dac     MOV        EAX,EDI
    //         00488dae     SUB        EAX,this
    //         00488db0     MOV        this,EBP
    //         00488db2     SUB        this,EDX
    //                              rmm_terr.cpp:199 (6)
    //         00488db4     TEST       EAX,EAX
    //         00488db6     JGE        LAB_00488dba
    //         00488db8     NEG        EAX
    //                               LAB_00488dba                                                 XREF[1]:     00488db6(j)  
    //                              rmm_terr.cpp:200 (6)
    //         00488dba     TEST       this,this
    //         00488dbc     JGE        LAB_00488dc0
    //         00488dbe     NEG        this
    //                               LAB_00488dc0                                                 XREF[1]:     00488dbc(j)  
    //                              rmm_terr.cpp:203 (32)
    //         00488dc0     MOV        EDX,EAX
    //         00488dc2     IMUL       EDX,EAX
    //         00488dc5     MOV        EAX,this
    //         00488dc7     IMUL       EAX,this
    //         00488dca     ADD        EDX,EAX
    //         00488dcc     MOV        dword ptr [ESP + local_4],EDX
    //         00488dd0     FILD       dword ptr [ESP + local_4]
    //         00488dd4     FSQRT
    //         00488dd6     CALL       __ftol                                           undefined __ftol()
    //         00488ddb     MOV        this,dword ptr [ESI + 0x4]
    //         00488dde     SUB        this,EAX
    //                              rmm_terr.cpp:204 (4)
    //         00488de0     TEST       this,this
    //         00488de2     JLE        LAB_00488df4
    //                              rmm_terr.cpp:205 (30)
    //         00488de4     MOV        EDX,dword ptr [ESI + 0x8]
    //         00488de7     MOV        EAX,dword ptr [ESP + local_c]
    //         00488deb     IMUL       EDX,this
    //         00488dee     ADD        EAX,EDX
    //         00488df0     MOV        dword ptr [ESP + local_c],EAX
    //                               LAB_00488df4                                                 XREF[1]:     00488de2(j)  
    //         00488df4     MOV        EAX,dword ptr [ESP + local_8]
    //         00488df8     ADD        ESI,0x10
    //         00488dfb     DEC        EAX
    //         00488dfc     MOV        dword ptr [ESP + local_8],EAX
    //         00488e00     JNZ        LAB_00488da7
    //                              rmm_terr.cpp:195 (4)
    //         00488e02     MOV        this,dword ptr [ESP + local_c]
    //                               LAB_00488e06                                                 XREF[1]:     00488d9b(j)  
    //                              rmm_terr.cpp:208 (5)
    //         00488e06     CMP        this,0x64
    //         00488e09     JLE        LAB_00488e17
    //                              rmm_terr.cpp:209 (10)
    //         00488e0b     MOV        EAX,dword ptr [EBX + 0x24]
    //         00488e0e     MOV        this,dword ptr [EAX + EBP*0x4]
    //         00488e11     MOV        byte ptr [this->_padding_ + EDI*0x1],0x65
    //                              rmm_terr.cpp:210 (2)
    //         00488e15     JMP        LAB_00488e20
    //                               LAB_00488e17                                                 XREF[1]:     00488e09(j)  
    //                              rmm_terr.cpp:211 (21)
    //         00488e17     MOV        EDX,dword ptr [EBX + 0x24]
    //         00488e1a     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //         00488e1d     MOV        byte ptr [EAX + EDI*0x1],this
    //                               LAB_00488e20                                                 XREF[1]:     00488e15(j)  
    //         00488e20     MOV        EAX,dword ptr [EBX + 0x14]
    //         00488e23     INC        EDI
    //         00488e24     CMP        EDI,EAX
    //         00488e26     JL         LAB_00488d8d
    //                               LAB_00488e2c                                                 XREF[1]:     00488d87(j)  
    //                              rmm_terr.cpp:191 (12)
    //         00488e2c     MOV        EAX,dword ptr [EBX + 0x18]
    //         00488e2f     INC        EBP
    //         00488e30     CMP        EBP,EAX
    //         00488e32     JL         LAB_00488d80
    //                              rmm_terr.cpp:179 (1)
    //         00488e38     POP        ESI
    //                               LAB_00488e39                                                 XREF[1]:     00488d79(j)  
    //                              rmm_terr.cpp:213 (7)
    //         00488e39     POP        EDI
    //         00488e3a     POP        EBP
    //         00488e3b     POP        EBX
    //         00488e3c     ADD        ESP,0xc
    //         00488e3f     RET
}

// Offset: 0x00488E40
float fig_chance(RGE_RMM_Terrain_Generator* this_, long param_2, long param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: float __thiscall RGE_RMM_Terrain_Generator::fig_chance(long,long,long,long)                *
    //                              *********************************************************************************************************
    //                              float __thiscall fig_chance(RGE_RMM_Terrain_Generator * this, long p
    //              float             ST0:10         <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00488e49(R)  
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00488e40(R), 00488e50(W), 00488e54(R)  
    //                               ?fig_chance@RGE_RMM_Terrain_Generator@@IAEMJJJJ@Z            XREF[1]:     base_terrain_generate:00489593(c)  
    //                               RGE_RMM_Terrain_Generator::fig_chance
    //                              rmm_terr.cpp:218 (24)
    //         00488e40     MOV        EAX,dword ptr [ESP + param_4]
    //         00488e44     MOV        this,0xfa
    //         00488e49     IMUL       EAX,dword ptr [ESP + param_1]
    //         00488e4e     SUB        this,EAX
    //         00488e50     MOV        dword ptr [ESP + param_4],this
    //         00488e54     FILD       dword ptr [ESP + param_4]
    //                              rmm_terr.cpp:225 (3)
    //         00488e58     RET        0x10
}

// Offset: 0x00488E60
long count_map_tiles(RGE_RMM_Terrain_Generator* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: long __thiscall RGE_RMM_Terrain_Generator::count_map_tiles(unsigned char)                  *
    //                              *********************************************************************************************************
    //                              long __thiscall count_map_tiles(RGE_RMM_Terrain_Generator * this, uc
    //              long              EAX:4          <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00488e7a(R)  
    //                               ?count_map_tiles@RGE_RMM_Terrain_Generator@@IAEJE@Z
    //                               RGE_RMM_Terrain_Generator::count_map_tiles
    //                              rmm_terr.cpp:231 (5)
    //         00488e60     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00488e63     PUSH       ESI
    //         00488e64     PUSH       EDI
    //                              rmm_terr.cpp:234 (17)
    //         00488e65     XOR        EDI,EDI
    //         00488e67     MOV        EDX,dword ptr [EAX]
    //         00488e69     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00488e6c     IMUL       EAX,dword ptr [ECX + this->_padding_]
    //         00488e70     LEA        this,[EAX + EAX*0x2]
    //         00488e73     LEA        ESI,[EDX + this->_padding_*0x8]
    //                              rmm_terr.cpp:236 (8)
    //         00488e76     CMP        EDX,ESI
    //         00488e78     JNC        LAB_00488e8f
    //         00488e7a     MOV        this,byte ptr [ESP + param_1]
    //                               LAB_00488e7e                                                 XREF[1]:     00488e8d(j)  
    //                              rmm_terr.cpp:237 (9)
    //         00488e7e     MOV        AL,byte ptr [EDX + 0x5]
    //         00488e81     AND        AL,0x1f
    //         00488e83     CMP        AL,this
    //         00488e85     JNZ        LAB_00488e88
    //                              rmm_terr.cpp:238 (1)
    //         00488e87     INC        EDI
    //                               LAB_00488e88                                                 XREF[1]:     00488e85(j)  
    //                              rmm_terr.cpp:236 (7)
    //         00488e88     ADD        EDX,0x18
    //         00488e8b     CMP        EDX,ESI
    //         00488e8d     JC         LAB_00488e7e
    //                               LAB_00488e8f                                                 XREF[1]:     00488e78(j)  
    //                              rmm_terr.cpp:240 (2)
    //         00488e8f     MOV        EAX,EDI
    //                              rmm_terr.cpp:241 (5)
    //         00488e91     POP        EDI
    //         00488e92     POP        ESI
    //         00488e93     RET        0x4
}

// Offset: 0x00488EA0
void link_stack_randomly(RGE_RMM_Terrain_Generator* this_, Map_Stack* param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_RMM_Terrain_Generator::link_stack_randomly(struct Map_Stack *,unsig... *
    //                              *********************************************************************************************************
    //                              void __thiscall link_stack_randomly(RGE_RMM_Terrain_Generator * this
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              Map_Stack *       Stack[0x4]:4   param_1                   XREF[4]:     00488ea7(R), 00488f0b(W), 00488f7c(R), 00488f81(W)  
    //              uchar             Stack[0x8]:1   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00488eb7(W), 00488f51(R)  
    //              long              Stack[-0x8]:4  max_y
    //                               ?link_stack_randomly@RGE_RMM_Terrain_Generator@@IAEXPAUMap_  XREF[1]:     base_terrain_generate:004890cf(c)  
    //                               RGE_RMM_Terrain_Generator::link_stack_randomly
    //                              rmm_terr.cpp:245 (7)
    //         00488ea0     PUSH       this
    //         00488ea1     PUSH       EBX
    //         00488ea2     PUSH       EBP
    //         00488ea3     PUSH       ESI
    //         00488ea4     PUSH       EDI
    //         00488ea5     MOV        EDI,this
    //                              rmm_terr.cpp:257 (42)
    //         00488ea7     MOV        EBX,dword ptr [ESP + param_1]
    //         00488eab     MOV        EAX,dword ptr [EDI + 0x18]
    //         00488eae     MOV        EDX,dword ptr [EDI + 0x14]
    //         00488eb1     LEA        this,[EAX + -0x1]
    //         00488eb4     IMUL       EAX,EDX
    //         00488eb7     MOV        dword ptr [ESP + local_4],this
    //         00488ebb     MOV        this,dword ptr [EDI + 0x28]
    //         00488ebe     LEA        EBP,[EDX + -0x1]
    //         00488ec1     LEA        EDX,[EAX + EAX*0x2]
    //         00488ec4     LEA        EAX,[ECX + this->_padding_]
    //         00488ec7     MOV        dword ptr [ECX + this->_padding_],EBX
    //         00488eca     LEA        EDX,[this->_padding_ + EDX*0x8 + -0x18]
    //         00488ece     MOV        dword ptr [ECX + this->_padding_],EAX
    //                              rmm_terr.cpp:258 (3)
    //         00488ed1     MOV        dword ptr [EBX + 0x10],this
    //                              rmm_terr.cpp:262 (20)
    //         00488ed4     CMP        EAX,EDX
    //         00488ed6     LEA        this,[EDX + -0x18]
    //         00488ed9     MOV        dword ptr [EDX + 0x10],0x0
    //         00488ee0     MOV        dword ptr [EDX + 0x14],this
    //         00488ee3     JNC        LAB_00488ef7
    //                               LAB_00488ee5                                                 XREF[1]:     00488ef5(j)  
    //         00488ee5     LEA        this,[EAX + 0x18]
    //                              rmm_terr.cpp:265 (15)
    //         00488ee8     LEA        ESI,[EAX + -0x18]
    //         00488eeb     MOV        dword ptr [EAX + 0x10],this
    //         00488eee     MOV        dword ptr [EAX + 0x14],ESI
    //         00488ef1     MOV        EAX,this
    //         00488ef3     CMP        EAX,EDX
    //         00488ef5     JC         LAB_00488ee5
    //                               LAB_00488ef7                                                 XREF[1]:     00488ee3(j)  
    //                              rmm_terr.cpp:268 (16)
    //         00488ef7     MOV        EAX,dword ptr [EDI + 0x18]
    //         00488efa     IMUL       EAX,dword ptr [EDI + 0x14]
    //         00488efe     CDQ
    //         00488eff     AND        EDX,0x7
    //         00488f02     ADD        EAX,EDX
    //         00488f04     SAR        EAX,0x3
    //                              rmm_terr.cpp:269 (4)
    //         00488f07     TEST       EAX,EAX
    //         00488f09     JLE        LAB_00488f87
    //                              rmm_terr.cpp:268 (4)
    //         00488f0b     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_00488f0f                                                 XREF[1]:     00488f85(j)  
    //                              rmm_terr.cpp:271 (37)
    //         00488f0f     PUSH       0x10f
    //         00488f14     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         00488f19     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00488f1e     MOV        this,EAX
    //         00488f20     MOV        EAX,0x80010003
    //         00488f25     IMUL       this,EBP
    //         00488f28     IMUL       this
    //         00488f2a     ADD        EDX,this
    //         00488f2c     ADD        ESP,0x8
    //         00488f2f     SAR        EDX,0xe
    //         00488f32     MOV        EAX,EDX
    //                              rmm_terr.cpp:272 (38)
    //         00488f34     PUSH       0x110
    //         00488f39     SHR        EAX,0x1f
    //         00488f3c     ADD        EDX,EAX
    //         00488f3e     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         00488f43     MOV        ESI,EDX
    //         00488f45     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00488f4a     MOV        this,EAX
    //         00488f4c     MOV        EAX,0x80010003
    //         00488f51     IMUL       this,dword ptr [ESP + local_4]
    //         00488f56     IMUL       this
    //         00488f58     ADD        EDX,this
    //                              rmm_terr.cpp:273 (45)
    //         00488f5a     MOV        EAX,dword ptr [EDI + 0x2c]
    //         00488f5d     SAR        EDX,0xe
    //         00488f60     MOV        this,EDX
    //         00488f62     ADD        ESP,0x8
    //         00488f65     SHR        this,0x1f
    //         00488f68     ADD        EDX,this
    //         00488f6a     LEA        this,[ESI + ESI*0x2]
    //         00488f6d     MOV        EDX,dword ptr [EAX + EDX*0x4]
    //         00488f70     LEA        EAX,[EDX + this->_padding_*0x8]
    //         00488f73     MOV        this,EDI
    //         00488f75     PUSH       EAX
    //         00488f76     PUSH       EBX
    //         00488f77     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
    //         00488f7c     MOV        EAX,dword ptr [ESP + param_1]
    //         00488f80     DEC        EAX
    //         00488f81     MOV        dword ptr [ESP + param_1],EAX
    //         00488f85     JNZ        LAB_00488f0f
    //                               LAB_00488f87                                                 XREF[1]:     00488f09(j)  
    //                              rmm_terr.cpp:275 (8)
    //         00488f87     POP        EDI
    //         00488f88     POP        ESI
    //         00488f89     POP        EBP
    //         00488f8a     POP        EBX
    //         00488f8b     POP        this
    //         00488f8c     RET        0x8
}

// Offset: 0x00488F90
void remove_area_from_lists(RGE_RMM_Terrain_Generator* this_, long param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_RMM_Terrain_Generator::remove_area_from_lists(long,long,long)          *
    //                              *********************************************************************************************************
    //                              void __thiscall remove_area_from_lists(RGE_RMM_Terrain_Generator * t
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     00488f90(R), 00488fb5(W), 00488fd9(W), 0048900e(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     00488f9b(R), 00488fe1(W), 00488ff7(R), 00489016(R), 
    //                                                                                     0048901d(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     00488f94(R), 00488fb1(W), 00488fcb(W), 00489012(R)  
    //                               ?remove_area_from_lists@RGE_RMM_Terrain_Generator@@IAEXJJJ@Z XREF[2]:     base_terrain_generate:004891a9(c), 
    //                               RGE_RMM_Terrain_Generator::remove_area_from_lists                         base_terrain_generate:004893b9(c)  
    //                              rmm_terr.cpp:279 (31)
    //         00488f90     MOV        EDX,dword ptr [ESP + param_1]
    //         00488f94     MOV        EAX,dword ptr [ESP + param_3]
    //         00488f98     PUSH       EBX
    //         00488f99     PUSH       EBP
    //         00488f9a     PUSH       ESI
    //         00488f9b     MOV        ESI,dword ptr [ESP + param_2]
    //         00488f9f     MOV        EBP,this
    //         00488fa1     MOV        EBX,EDX
    //         00488fa3     MOV        this,ESI
    //         00488fa5     PUSH       EDI
    //         00488fa6     SUB        EBX,EAX
    //         00488fa8     SUB        this,EAX
    //         00488faa     LEA        EDI,[EAX + EDX*0x1]
    //         00488fad     ADD        EAX,ESI
    //                              rmm_terr.cpp:292 (14)
    //         00488faf     TEST       EBX,EBX
    //         00488fb1     MOV        dword ptr [ESP + param_3],EDI
    //         00488fb5     MOV        dword ptr [ESP + param_1],EAX
    //         00488fb9     JGE        LAB_00488fbd
    //         00488fbb     XOR        EBX,EBX
    //                               LAB_00488fbd                                                 XREF[1]:     00488fb9(j)  
    //                              rmm_terr.cpp:293 (6)
    //         00488fbd     TEST       this,this
    //         00488fbf     JGE        LAB_00488fc3
    //         00488fc1     XOR        this,this
    //                               LAB_00488fc3                                                 XREF[1]:     00488fbf(j)  
    //                              rmm_terr.cpp:294 (14)
    //         00488fc3     MOV        EDX,dword ptr [EBP + 0x14]
    //         00488fc6     CMP        EDI,EDX
    //         00488fc8     JL         LAB_00488fd1
    //         00488fca     DEC        EDX
    //         00488fcb     MOV        dword ptr [ESP + param_3],EDX
    //         00488fcf     MOV        EDI,EDX
    //                               LAB_00488fd1                                                 XREF[1]:     00488fc8(j)  
    //                              rmm_terr.cpp:295 (14)
    //         00488fd1     MOV        EDX,dword ptr [EBP + 0x18]
    //         00488fd4     CMP        EAX,EDX
    //         00488fd6     JL         LAB_00488fdf
    //         00488fd8     DEC        EDX
    //         00488fd9     MOV        dword ptr [ESP + param_1],EDX
    //         00488fdd     MOV        EAX,EDX
    //                               LAB_00488fdf                                                 XREF[1]:     00488fd6(j)  
    //                              rmm_terr.cpp:297 (8)
    //         00488fdf     CMP        this,EAX
    //         00488fe1     MOV        dword ptr [ESP + param_2],this
    //         00488fe5     JG         LAB_00489023
    //                               LAB_00488fe7                                                 XREF[1]:     00489021(j)  
    //                              rmm_terr.cpp:298 (13)
    //         00488fe7     CMP        EBX,EDI
    //         00488fe9     JG         LAB_00489016
    //         00488feb     LEA        ESI,[EBX + EBX*0x2]
    //         00488fee     SUB        EDI,EBX
    //         00488ff0     SHL        ESI,0x3
    //         00488ff3     INC        EDI
    //                               LAB_00488ff4                                                 XREF[1]:     0048900c(j)  
    //                              rmm_terr.cpp:299 (47)
    //         00488ff4     MOV        EAX,dword ptr [EBP + 0x2c]
    //         00488ff7     MOV        this,dword ptr [ESP + param_2]
    //         00488ffb     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
    //         00488ffe     MOV        this,EBP
    //         00489000     ADD        EDX,ESI
    //         00489002     PUSH       EDX
    //         00489003     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module 
    //         00489008     ADD        ESI,0x18
    //         0048900b     DEC        EDI
    //         0048900c     JNZ        LAB_00488ff4
    //         0048900e     MOV        EAX,dword ptr [ESP + param_1]
    //         00489012     MOV        EDI,dword ptr [ESP + param_3]
    //                               LAB_00489016                                                 XREF[1]:     00488fe9(j)  
    //         00489016     MOV        this,dword ptr [ESP + param_2]
    //         0048901a     INC        this
    //         0048901b     CMP        this,EAX
    //         0048901d     MOV        dword ptr [ESP + param_2],this
    //         00489021     JLE        LAB_00488fe7
    //                               LAB_00489023                                                 XREF[1]:     00488fe5(j)  
    //                              rmm_terr.cpp:300 (7)
    //         00489023     POP        EDI
    //         00489024     POP        ESI
    //         00489025     POP        EBP
    //         00489026     POP        EBX
    //         00489027     RET        0xc
}

// Offset: 0x00489030
uchar base_terrain_generate(RGE_RMM_Terrain_Generator* this_, RGE_Terrain_Info_Line param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_RMM_Terrain_Generator::base_terrain_generate(struct RGE_Te... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall base_terrain_generate(RGE_RMM_Terrain_Generator * t
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              RGE_Terrain_In    Stack[0x4]:32  param_1                   XREF[2,24]:  004890d4(R), 0048949d(R), 00489162(R), 0048932a(R), 
    //                                                                                     0048954d(R), 004895cd(R), 00489814(R), 00489833(R), 
    //                                                                                     004890db(R), 004890fc(R), 004892a6(R), 004897c0(R), 
    //                                                                                     0048916a(R), 00489332(R), 00489542(R), 004890b6(R), 
    //                                                                                     0048914e(R), 00489316(R), 0048953b(R), 0048955f(R)  
    //              Map_Stack[99]     Stack[-0x94c   stack                     XREF[0,5]:   0048909c(*), 0048910f(*), 0048948e(*), 004897cf(*), 
    //                                                                                     004898a3(*)  
    //              uchar[99]         Stack[-0x9b0   terrain_fairness_zones    XREF[0,2]:   00489283(*), 0048937d(*)  
    //              uchar[99]         Stack[-0xa14   terrain_fairness_zones_v  XREF[1,4]:   004890cb(W), 0048928c(*), 00489293(*), 00489386(*), 
    //                                                                                     004893a3(*)  
    //              Map_Stack         Stack[-0xa2c   loc_stack                 XREF[3,4]:   0048904d(W), 00489657(R), 00489822(R), 004890bd(*), 
    //                                                                                     00489124(*), 004892ec(*), 004890c7(W)  
    //              long              Stack[-0xa30   max_x                     XREF[3]:     00489058(W), 00489732(R), 00489855(R)  
    //              long              Stack[-0xa34   max_y                     XREF[5]:     00489116(*), 004892de(*), 004894ac(*), 004897da(*), 
    //                                                                                     00489872(*)  
    //              float             Stack[-0xa38   in_zone                   XREF[7]:     00489049(W), 0048924c(R), 0048925e(W), 00489454(R), 
    //                                                                                     0048945e(W), 00489499(R), 0048979e(RW)  
    //              long              Stack[-0xa3c   clump_size                XREF[8]:     00489103(W), 00489250(R), 00489262(W), 004892a2(R), 
    //                                                                                     004892d0(R), 00489458(R), 00489462(W), 0048947b(R)  
    //              long              Stack[-0xa40   index1                    XREF[10]:    004895ba(W), 004895be(R), 0048962a(W), 00489632(R), 
    //                                                                                     0048969c(W), 004896a4(R), 0048970f(W), 00489717(R), 
    //                                                                                     0048977f(W), 00489787(R)  
    //              undefined4        Stack[-0xa44   local_a44                 XREF[10]:    004890ee(W), 004890f4(W), 004891a0(R), 0048939e(R), 
    //                                                                                     00489495(W), 004897a2(R), 004897aa(W), 004897d6(W), 
    //                                                                                     00489891(R), 00489899(W)  
    //              long              Stack[-0xa48   base_area                 XREF[0,3]:   0048947f(W), 004894d2(W), 004897b4(R)  
    //              uchar             Stack[-0xa49   done
    //              float             Stack[-0xa50   chance                    XREF[32]:    0048911f(*), 0048913c(R), 00489188(R), 004891ae(R), 
    //                                                                                     004891d0(R), 004891eb(R), 0048920a(R), 00489229(R), 
    //                                                                                     00489248(R), 004892e7(*), 00489304(R), 00489356(R), 
    //                                                                                     004893b0(R), 004893be(R), 004893e0(R), 004893fb(R), 
    //                                                                                     0048941a(R), 00489439(R), 004894b5(*), 00489513(R)  
    //              long              Stack[-0xa54   x                         XREF[32]:    0048911a(*), 00489140(R), 00489184(R), 004891b8(R), 
    //                                                                                     004891d8(R), 004891ef(R), 00489206(R), 00489225(R), 
    //                                                                                     00489244(R), 004892e2(*), 00489308(R), 0048934f(R), 
    //                                                                                     004893a8(R), 004893c8(R), 004893e8(R), 004893ff(R), 
    //                                                                                     00489416(R), 00489435(R), 004894b0(*), 004894ed(R)  
    //              long              Stack[-0xa58   y
    //              undefined4        Stack[-0xa68   local_a68                 XREF[4]:     0048963d(*), 004896ad(*), 0048971f(*), 0048978f(*)  
    //                               ?base_terrain_generate@RGE_RMM_Terrain_Generator@@IAEEURGE_  XREF[1]:     generate:0048899e(c)  
    //                               RGE_RMM_Terrain_Generator::base_terrain_generate
    //                              rmm_terr.cpp:305 (11)
    //         00489030     SUB        ESP,0xa54
    //         00489036     PUSH       EBX
    //         00489037     PUSH       EBP
    //         00489038     PUSH       ESI
    //         00489039     MOV        ESI,this
    //                              rmm_terr.cpp:330 (39)
    //         0048903b     MOV        EBP,dword ptr [ESP + param_1.avoid_hot_spots]
    //         00489042     PUSH       EDI
    //         00489043     MOV        EAX,dword ptr [ESI + 0x14]
    //         00489046     XOR        EDI,EDI
    //         00489048     DEC        EAX
    //         00489049     MOV        dword ptr [ESP + in_zone],EDI
    //         0048904d     MOV        dword ptr [ESP + loc_stack.x],EAX
    //         00489051     MOV        EAX,dword ptr [ESI + 0x18]
    //         00489054     DEC        EAX
    //         00489055     CMP        EBP,0x2
    //         00489058     MOV        dword ptr [ESP + max_x],EAX
    //         0048905c     MOV        dword ptr [ESP + Stack[-0xa4c]],EDI
    //         00489060     JNZ        LAB_0048909c
    //                              rmm_terr.cpp:331 (8)
    //         00489062     CMP        dword ptr [ESI + 0x12c4],EDI
    //         00489068     JLE        LAB_0048909c
    //                              rmm_terr.cpp:504 (6)
    //         0048906a     LEA        EBX,[ESI + 0xc94]
    //                               LAB_00489070                                                 XREF[1]:     0048909a(j)  
    //                              rmm_terr.cpp:333 (31)
    //         00489070     MOV        EAX,dword ptr [EBX + 0x4]
    //         00489073     MOV        this,dword ptr [EBX]
    //         00489075     PUSH       EAX
    //         00489076     PUSH       this
    //         00489077     MOV        this,dword ptr [ESI + 0x12c8]
    //         0048907d     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
    //         00489082     MOV        byte ptr [ESP + EDI*0x1 + 0xb8],AL
    //         00489089     MOV        EAX,dword ptr [ESI + 0x12c4]
    //                              rmm_terr.cpp:334 (13)
    //         0048908f     MOV        byte ptr [ESP + EDI*0x1 + 0x54],0x0
    //         00489094     INC        EDI
    //         00489095     ADD        EBX,0x10
    //         00489098     CMP        EDI,EAX
    //         0048909a     JL         LAB_00489070
    //                               LAB_0048909c                                                 XREF[2]:     00489060(j), 00489068(j)  
    //                              rmm_terr.cpp:338 (12)
    //         0048909c     LEA        EDI=>stack[0].y,[ESP + 0x11c]
    //         004890a3     MOV        EBX,0x63
    //                               LAB_004890a8                                                 XREF[1]:     004890b4(j)  
    //                              rmm_terr.cpp:339 (14)
    //         004890a8     PUSH       EDI
    //         004890a9     MOV        this,ESI
    //         004890ab     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
    //         004890b0     ADD        EDI,0x18
    //         004890b3     DEC        EBX
    //         004890b4     JNZ        LAB_004890a8
    //                              rmm_terr.cpp:345 (30)
    //         004890b6     MOV        EDX,dword ptr [ESP + param_1.base_terrain_type]
    //         004890bd     LEA        EAX=>loc_stack.y,[ESP + 0x3c]
    //         004890c1     XOR        EDI,EDI
    //         004890c3     PUSH       EDX
    //         004890c4     PUSH       EAX
    //         004890c5     MOV        this,ESI
    //         004890c7     MOV        dword ptr [ESP + loc_stack.prev],EDI
    //         004890cb     MOV        dword ptr [ESP + terrain_fairness_zones_visite
    //         004890cf     CALL       RGE_RMM_Terrain_Generator::link_stack_randomly   void link_stack_randomly(RGE_RMM_Terrain_Gene
    //                              rmm_terr.cpp:348 (23)
    //         004890d4     FILD       dword ptr [ESP + param_1.terrain_size]
    //         004890db     FIDIV      dword ptr [ESP + param_1.clumps]
    //         004890e2     FSQRT
    //         004890e4     CALL       __ftol                                           undefined __ftol()
    //         004890e9     SHL        EAX,0x1
    //                              rmm_terr.cpp:349 (9)
    //         004890eb     CMP        EAX,0x2
    //         004890ee     MOV        dword ptr [ESP + local_a44],EAX
    //         004890f2     JGE        LAB_004890fc
    //                              rmm_terr.cpp:350 (8)
    //         004890f4     MOV        dword ptr [ESP + local_a44],0x2
    //                               LAB_004890fc                                                 XREF[1]:     004890f2(j)  
    //                              rmm_terr.cpp:353 (19)
    //         004890fc     MOV        EAX,dword ptr [ESP + param_1.clumps]
    //         00489103     MOV        dword ptr [ESP + clump_size],EDI
    //         00489107     CMP        EAX,EDI
    //         00489109     JLE        LAB_004892b5
    //                              rmm_terr.cpp:352 (7)
    //         0048910f     LEA        EDI=>stack[0].y,[ESP + 0x11c]
    //                               LAB_00489116                                                 XREF[1]:     004892af(j)  
    //                              rmm_terr.cpp:354 (35)
    //         00489116     LEA        this=>max_y,[ESP + 0x30]
    //         0048911a     LEA        EDX=>x,[ESP + 0x10]
    //         0048911e     PUSH       this
    //         0048911f     LEA        EAX=>chance,[ESP + 0x18]
    //         00489123     PUSH       EDX
    //         00489124     LEA        this=>loc_stack.y,[ESP + 0x44]
    //         00489128     PUSH       EAX
    //         00489129     PUSH       this
    //         0048912a     MOV        this,ESI
    //         0048912c     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         00489131     TEST       EAX,EAX
    //         00489133     JZ         LAB_004892b5
    //                              rmm_terr.cpp:358 (103)
    //         00489139     MOV        EDX,dword ptr [ESI + 0x10]
    //         0048913c     MOV        EAX,dword ptr [ESP + chance]
    //         00489140     MOV        this,dword ptr [ESP + x]
    //         00489144     LEA        EBX,[EAX + EAX*0x2]
    //         00489147     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
    //         0048914a     MOV        DL,byte ptr [EDX + EBX*0x8 + 0x5]
    //         0048914e     MOV        EBX,dword ptr [ESP + param_1.base_terrain_type]
    //         00489155     AND        EDX,0x1f
    //         00489158     CMP        EDX,EBX
    //         0048915a     JNZ        LAB_004892a2
    //         00489160     MOV        EDX,EBX
    //         00489162     MOV        EBX,dword ptr [ESP + param_1.terrain_type]
    //         00489169     PUSH       EDX
    //         0048916a     MOV        EDX,dword ptr [ESP + param_1.spacing]
    //         00489171     PUSH       EDX
    //         00489172     PUSH       this
    //         00489173     PUSH       EAX
    //         00489174     PUSH       EBX
    //         00489175     MOV        this,ESI
    //         00489177     CALL       RGE_RMM_Terrain_Generator::check_terrain         uchar check_terrain(RGE_RMM_Terrain_Generator
    //         0048917c     TEST       AL,AL
    //         0048917e     JBE        LAB_004892a2
    //         00489184     MOV        EAX,dword ptr [ESP + x]
    //         00489188     MOV        this,dword ptr [ESP + chance]
    //         0048918c     TEST       EBP,EBP
    //         0048918e     JZ         LAB_004891a0
    //         00489190     MOV        EDX,dword ptr [ESI + 0x24]
    //         00489193     MOV        EDX,dword ptr [EDX + EAX*0x4]
    //         00489196     CMP        byte ptr [EDX + this->_padding_*0x1],0x0
    //         0048919a     JNZ        LAB_004892a2
    //                               LAB_004891a0                                                 XREF[1]:     0048918e(j)  
    //                              rmm_terr.cpp:361 (14)
    //         004891a0     MOV        EDX,dword ptr [ESP + local_a44]
    //         004891a4     PUSH       EDX
    //         004891a5     PUSH       EAX
    //         004891a6     PUSH       this
    //         004891a7     MOV        this,ESI
    //         004891a9     CALL       RGE_RMM_Terrain_Generator::remove_area_from_li   void remove_area_from_lists(RGE_RMM_Terrain_G
    //                              rmm_terr.cpp:364 (34)
    //         004891ae     MOV        EAX,dword ptr [ESP + chance]
    //         004891b2     MOV        this,dword ptr [ESI + 0x10]
    //         004891b5     LEA        EDX,[EAX + EAX*0x2]
    //         004891b8     MOV        EAX,dword ptr [ESP + x]
    //         004891bc     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         004891bf     LEA        EAX,[ECX + EDX*0x8 + this+0x5]
    //         004891c3     MOV        this,byte ptr [ECX + EDX*0x8 + this+0x5]
    //         004891c7     XOR        BL,this
    //         004891c9     AND        BL,0x1f
    //         004891cc     XOR        BL,this
    //         004891ce     MOV        byte ptr [EAX],BL
    //                              rmm_terr.cpp:365 (8)
    //         004891d0     MOV        EAX,dword ptr [ESP + chance]
    //         004891d4     TEST       EAX,EAX
    //         004891d6     JLE        LAB_004891ef
    //                              rmm_terr.cpp:366 (23)
    //         004891d8     MOV        EDX,dword ptr [ESP + x]
    //         004891dc     PUSH       0x0
    //         004891de     PUSH       0x0
    //         004891e0     DEC        EAX
    //         004891e1     PUSH       EDX
    //         004891e2     PUSH       EAX
    //         004891e3     PUSH       EDI
    //         004891e4     MOV        this,ESI
    //         004891e6     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         004891eb     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_004891ef                                                 XREF[1]:     004891d6(j)  
    //                              rmm_terr.cpp:368 (8)
    //         004891ef     MOV        this,dword ptr [ESP + x]
    //         004891f3     TEST       this,this
    //         004891f5     JLE        LAB_0048920e
    //                              rmm_terr.cpp:369 (23)
    //         004891f7     PUSH       0x0
    //         004891f9     DEC        this
    //         004891fa     PUSH       0x0
    //         004891fc     PUSH       this
    //         004891fd     PUSH       EAX
    //         004891fe     PUSH       EDI
    //         004891ff     MOV        this,ESI
    //         00489201     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00489206     MOV        this,dword ptr [ESP + x]
    //         0048920a     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_0048920e                                                 XREF[1]:     004891f5(j)  
    //                              rmm_terr.cpp:371 (8)
    //         0048920e     MOV        EDX,dword ptr [ESI + 0x14]
    //         00489211     DEC        EDX
    //         00489212     CMP        EAX,EDX
    //         00489214     JGE        LAB_0048922d
    //                              rmm_terr.cpp:372 (23)
    //         00489216     PUSH       0x0
    //         00489218     PUSH       0x0
    //         0048921a     INC        EAX
    //         0048921b     PUSH       this
    //         0048921c     PUSH       EAX
    //         0048921d     PUSH       EDI
    //         0048921e     MOV        this,ESI
    //         00489220     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00489225     MOV        this,dword ptr [ESP + x]
    //         00489229     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_0048922d                                                 XREF[1]:     00489214(j)  
    //                              rmm_terr.cpp:374 (8)
    //         0048922d     MOV        EDX,dword ptr [ESI + 0x18]
    //         00489230     DEC        EDX
    //         00489231     CMP        this,EDX
    //         00489233     JGE        LAB_0048924c
    //                              rmm_terr.cpp:375 (23)
    //         00489235     PUSH       0x0
    //         00489237     INC        this
    //         00489238     PUSH       0x0
    //         0048923a     PUSH       this
    //         0048923b     PUSH       EAX
    //         0048923c     PUSH       EDI
    //         0048923d     MOV        this,ESI
    //         0048923f     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00489244     MOV        this,dword ptr [ESP + x]
    //         00489248     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_0048924c                                                 XREF[1]:     00489233(j)  
    //                              rmm_terr.cpp:377 (4)
    //         0048924c     MOV        EDX,dword ptr [ESP + in_zone]
    //                              rmm_terr.cpp:378 (6)
    //         00489250     MOV        EBX,dword ptr [ESP + clump_size]
    //         00489254     INC        EDX
    //         00489255     INC        EBX
    //                              rmm_terr.cpp:382 (24)
    //         00489256     PUSH       this
    //         00489257     MOV        this,dword ptr [ESI + 0x12c8]
    //         0048925d     PUSH       EAX
    //         0048925e     MOV        dword ptr [ESP + in_zone],EDX
    //         00489262     MOV        dword ptr [ESP + clump_size],EBX
    //         00489266     ADD        EDI,0x18
    //         00489269     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
    //                              rmm_terr.cpp:383 (5)
    //         0048926e     CMP        EBP,0x2
    //         00489271     JNZ        LAB_004892a2
    //                              rmm_terr.cpp:384 (16)
    //         00489273     MOV        EDX,dword ptr [ESI + 0x12c4]
    //         00489279     XOR        this,this
    //         0048927b     TEST       EDX,EDX
    //         0048927d     JLE        LAB_004892a2
    //         0048927f     MOV        EBX,dword ptr [ESP + Stack[-0xa4c]]
    //                               LAB_00489283                                                 XREF[1]:     0048929c(j)  
    //                              rmm_terr.cpp:385 (16)
    //         00489283     CMP        byte ptr [ESP + this->_padding_*0x1 + terrain_
    //         0048928a     JNZ        LAB_00489299
    //         0048928c     CMP        byte ptr [ESP + this->_padding_*0x1 + terrain_
    //         00489291     JNZ        LAB_00489299
    //                              rmm_terr.cpp:387 (5)
    //         00489293     MOV        byte ptr [ESP + this->_padding_*0x1 + terrain_
    //                              rmm_terr.cpp:388 (10)
    //         00489298     INC        EBX
    //                               LAB_00489299                                                 XREF[2]:     0048928a(j), 00489291(j)  
    //         00489299     INC        this
    //         0048929a     CMP        this,EDX
    //         0048929c     JL         LAB_00489283
    //         0048929e     MOV        dword ptr [ESP + Stack[-0xa4c]],EBX
    //                               LAB_004892a2                                                 XREF[5]:     0048915a(j), 0048917e(j), 
    //                                                                                                         0048919a(j), 00489271(j), 
    //                                                                                                         0048927d(j)  
    //                              rmm_terr.cpp:353 (19)
    //         004892a2     MOV        EAX,dword ptr [ESP + clump_size]
    //         004892a6     MOV        this,dword ptr [ESP + param_1.clumps]
    //         004892ad     CMP        EAX,this
    //         004892af     JL         LAB_00489116
    //                               LAB_004892b5                                                 XREF[2]:     00489109(j), 00489133(j)  
    //                              rmm_terr.cpp:398 (9)
    //         004892b5     CMP        EBP,0x2
    //         004892b8     JNZ        LAB_0048947b
    //                              rmm_terr.cpp:399 (18)
    //         004892be     MOV        this,dword ptr [ESP + Stack[-0xa4c]]
    //         004892c2     MOV        EAX,dword ptr [ESI + 0x12c4]
    //         004892c8     CMP        this,EAX
    //         004892ca     JGE        LAB_0048947b
    //                              rmm_terr.cpp:504 (173)
    //         004892d0     MOV        EAX,dword ptr [ESP + clump_size]
    //         004892d4     LEA        EDX,[EAX + EAX*0x2]
    //         004892d7     LEA        EDI,[ESP + EDX*0x8 + 0x11c]
    //                               LAB_004892de                                                 XREF[1]:     00489475(j)  
    //         004892de     LEA        EAX=>max_y,[ESP + 0x30]
    //         004892e2     LEA        this=>x,[ESP + 0x10]
    //         004892e6     PUSH       EAX
    //         004892e7     LEA        EDX=>chance,[ESP + 0x18]
    //         004892eb     PUSH       this
    //         004892ec     LEA        EAX=>loc_stack.y,[ESP + 0x44]
    //         004892f0     PUSH       EDX
    //         004892f1     PUSH       EAX
    //         004892f2     MOV        this,ESI
    //         004892f4     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         004892f9     TEST       EAX,EAX
    //         004892fb     JZ         LAB_0048947b
    //         00489301     MOV        EDX,dword ptr [ESI + 0x10]
    //         00489304     MOV        EAX,dword ptr [ESP + chance]
    //         00489308     MOV        this,dword ptr [ESP + x]
    //         0048930c     LEA        EBX,[EAX + EAX*0x2]
    //         0048930f     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
    //         00489312     MOV        DL,byte ptr [EDX + EBX*0x8 + 0x5]
    //         00489316     MOV        EBX,dword ptr [ESP + param_1.base_terrain_type]
    //         0048931d     AND        EDX,0x1f
    //         00489320     CMP        EDX,EBX
    //         00489322     JNZ        LAB_00489469
    //         00489328     MOV        EDX,EBX
    //         0048932a     MOV        EBX,dword ptr [ESP + param_1.terrain_type]
    //         00489331     PUSH       EDX
    //         00489332     MOV        EDX,dword ptr [ESP + param_1.spacing]
    //         00489339     PUSH       EDX
    //         0048933a     PUSH       this
    //         0048933b     PUSH       EAX
    //         0048933c     PUSH       EBX
    //         0048933d     MOV        this,ESI
    //         0048933f     CALL       RGE_RMM_Terrain_Generator::check_terrain         uchar check_terrain(RGE_RMM_Terrain_Generator
    //         00489344     TEST       AL,AL
    //         00489346     JBE        LAB_00489469
    //         0048934c     MOV        this,dword ptr [ESI + 0x24]
    //         0048934f     MOV        EAX,dword ptr [ESP + x]
    //         00489353     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         00489356     MOV        this,dword ptr [ESP + chance]
    //         0048935a     CMP        byte ptr [EDX + this->_padding_*0x1],0x1e
    //         0048935e     JNC        LAB_00489469
    //         00489364     PUSH       EAX
    //         00489365     PUSH       this
    //         00489366     MOV        this,dword ptr [ESI + 0x12c8]
    //         0048936c     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
    //         00489371     MOV        EDX,dword ptr [ESI + 0x12c4]
    //         00489377     XOR        this,this
    //         00489379     TEST       EDX,EDX
    //         0048937b     JLE        LAB_00489392
    //                               LAB_0048937d                                                 XREF[1]:     00489390(j)  
    //                              rmm_terr.cpp:410 (16)
    //         0048937d     CMP        byte ptr [ESP + this->_padding_*0x1 + terrain_
    //         00489384     JNZ        LAB_0048938d
    //         00489386     CMP        byte ptr [ESP + this->_padding_*0x1 + terrain_
    //         0048938b     JZ         LAB_00489392
    //                               LAB_0048938d                                                 XREF[1]:     00489384(j)  
    //                              rmm_terr.cpp:409 (5)
    //         0048938d     INC        this
    //         0048938e     CMP        this,EDX
    //         00489390     JL         LAB_0048937d
    //                               LAB_00489392                                                 XREF[2]:     0048937b(j), 0048938b(j)  
    //                              rmm_terr.cpp:413 (8)
    //         00489392     CMP        this,EDX
    //         00489394     JZ         LAB_00489469
    //                              rmm_terr.cpp:417 (4)
    //         0048939a     MOV        EDX,dword ptr [ESP + Stack[-0xa4c]]
    //                              rmm_terr.cpp:420 (32)
    //         0048939e     MOV        EAX,dword ptr [ESP + local_a44]
    //         004893a2     INC        EDX
    //         004893a3     MOV        byte ptr [ESP + this->_padding_*0x1 + terrain_
    //         004893a8     MOV        this,dword ptr [ESP + x]
    //         004893ac     MOV        dword ptr [ESP + Stack[-0xa4c]],EDX
    //         004893b0     MOV        EDX,dword ptr [ESP + chance]
    //         004893b4     PUSH       EAX
    //         004893b5     PUSH       this
    //         004893b6     PUSH       EDX
    //         004893b7     MOV        this,ESI
    //         004893b9     CALL       RGE_RMM_Terrain_Generator::remove_area_from_li   void remove_area_from_lists(RGE_RMM_Terrain_G
    //                              rmm_terr.cpp:423 (34)
    //         004893be     MOV        EAX,dword ptr [ESP + chance]
    //         004893c2     MOV        this,dword ptr [ESI + 0x10]
    //         004893c5     LEA        EDX,[EAX + EAX*0x2]
    //         004893c8     MOV        EAX,dword ptr [ESP + x]
    //         004893cc     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         004893cf     LEA        EAX,[ECX + EDX*0x8 + this+0x5]
    //         004893d3     MOV        this,byte ptr [ECX + EDX*0x8 + this+0x5]
    //         004893d7     XOR        BL,this
    //         004893d9     AND        BL,0x1f
    //         004893dc     XOR        BL,this
    //         004893de     MOV        byte ptr [EAX],BL
    //                              rmm_terr.cpp:424 (8)
    //         004893e0     MOV        EAX,dword ptr [ESP + chance]
    //         004893e4     TEST       EAX,EAX
    //         004893e6     JLE        LAB_004893ff
    //                              rmm_terr.cpp:425 (23)
    //         004893e8     MOV        EDX,dword ptr [ESP + x]
    //         004893ec     PUSH       0x0
    //         004893ee     PUSH       0x0
    //         004893f0     DEC        EAX
    //         004893f1     PUSH       EDX
    //         004893f2     PUSH       EAX
    //         004893f3     PUSH       EDI
    //         004893f4     MOV        this,ESI
    //         004893f6     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         004893fb     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_004893ff                                                 XREF[1]:     004893e6(j)  
    //                              rmm_terr.cpp:427 (8)
    //         004893ff     MOV        this,dword ptr [ESP + x]
    //         00489403     TEST       this,this
    //         00489405     JLE        LAB_0048941e
    //                              rmm_terr.cpp:428 (23)
    //         00489407     PUSH       0x0
    //         00489409     DEC        this
    //         0048940a     PUSH       0x0
    //         0048940c     PUSH       this
    //         0048940d     PUSH       EAX
    //         0048940e     PUSH       EDI
    //         0048940f     MOV        this,ESI
    //         00489411     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00489416     MOV        this,dword ptr [ESP + x]
    //         0048941a     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_0048941e                                                 XREF[1]:     00489405(j)  
    //                              rmm_terr.cpp:430 (8)
    //         0048941e     MOV        EDX,dword ptr [ESI + 0x14]
    //         00489421     DEC        EDX
    //         00489422     CMP        EAX,EDX
    //         00489424     JGE        LAB_0048943d
    //                              rmm_terr.cpp:431 (23)
    //         00489426     PUSH       0x0
    //         00489428     PUSH       0x0
    //         0048942a     INC        EAX
    //         0048942b     PUSH       this
    //         0048942c     PUSH       EAX
    //         0048942d     PUSH       EDI
    //         0048942e     MOV        this,ESI
    //         00489430     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         00489435     MOV        this,dword ptr [ESP + x]
    //         00489439     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_0048943d                                                 XREF[1]:     00489424(j)  
    //                              rmm_terr.cpp:433 (8)
    //         0048943d     MOV        EDX,dword ptr [ESI + 0x18]
    //         00489440     DEC        EDX
    //         00489441     CMP        this,EDX
    //         00489443     JGE        LAB_00489454
    //                              rmm_terr.cpp:434 (15)
    //         00489445     PUSH       0x0
    //         00489447     INC        this
    //         00489448     PUSH       0x0
    //         0048944a     PUSH       this
    //         0048944b     PUSH       EAX
    //         0048944c     PUSH       EDI
    //         0048944d     MOV        this,ESI
    //         0048944f     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_00489454                                                 XREF[1]:     00489443(j)  
    //                              rmm_terr.cpp:436 (4)
    //         00489454     MOV        EDX,dword ptr [ESP + in_zone]
    //                              rmm_terr.cpp:437 (35)
    //         00489458     MOV        this,dword ptr [ESP + clump_size]
    //         0048945c     INC        EDX
    //         0048945d     INC        this
    //         0048945e     MOV        dword ptr [ESP + in_zone],EDX
    //         00489462     MOV        dword ptr [ESP + clump_size],this
    //         00489466     ADD        EDI,0x18
    //                               LAB_00489469                                                 XREF[4]:     00489322(j), 00489346(j), 
    //                                                                                                         0048935e(j), 00489394(j)  
    //         00489469     MOV        EAX,dword ptr [ESP + Stack[-0xa4c]]
    //         0048946d     MOV        this,dword ptr [ESI + 0x12c4]
    //         00489473     CMP        EAX,this
    //         00489475     JL         LAB_004892de
    //                               LAB_0048947b                                                 XREF[4]:     004892b8(j), 004892ca(j), 
    //                                                                                                         004892fb(j), 004897ba(j)  
    //                              rmm_terr.cpp:449 (30)
    //         0048947b     MOV        EAX,dword ptr [ESP + clump_size]
    //         0048947f     MOV        byte ptr [ESP + base_area+0x3],0x1
    //         00489484     TEST       EAX,EAX
    //         00489486     JLE        LAB_004897b4
    //         0048948c     MOV        this,EAX
    //         0048948e     LEA        EBX=>stack[0].y,[ESP + 0x11c]
    //         00489495     MOV        dword ptr [ESP + local_a44],this
    //                               LAB_00489499                                                 XREF[1]:     004897ae(j)  
    //                              rmm_terr.cpp:450 (19)
    //         00489499     MOV        EDX,dword ptr [ESP + in_zone]
    //         0048949d     MOV        EAX,dword ptr [ESP + param_1.terrain_size]
    //         004894a4     CMP        EDX,EAX
    //         004894a6     JGE        LAB_004897a2
    //                              rmm_terr.cpp:451 (31)
    //         004894ac     LEA        EAX=>max_y,[ESP + 0x30]
    //         004894b0     LEA        this=>x,[ESP + 0x10]
    //         004894b4     PUSH       EAX
    //         004894b5     LEA        EDX=>chance,[ESP + 0x18]
    //         004894b9     PUSH       this
    //         004894ba     PUSH       EDX
    //         004894bb     PUSH       EBX
    //         004894bc     MOV        this,ESI
    //         004894be     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         004894c3     TEST       EAX,EAX
    //         004894c5     JZ         LAB_004897a2
    //                              rmm_terr.cpp:454 (100)
    //         004894cb     MOV        EAX,dword ptr [ESP + param_1.avoid_hot_spots]
    //         004894d2     MOV        byte ptr [ESP + base_area+0x3],0x0
    //         004894d7     TEST       EAX,EAX
    //         004894d9     JZ         LAB_00489527
    //         004894db     PUSH       0x1c6
    //         004894e0     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         004894e5     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004894ea     LEA        EAX,[EAX + EAX*0x4]
    //         004894ed     MOV        EDI,dword ptr [ESP + x]
    //         004894f1     ADD        ESP,0x8
    //         004894f4     LEA        this,[EAX + EAX*0x4]
    //         004894f7     MOV        EAX,0x80010003
    //         004894fc     SHL        this,0x2
    //         004894ff     IMUL       this
    //         00489501     ADD        EDX,this
    //         00489503     MOV        this,dword ptr [ESI + 0x24]
    //         00489506     SAR        EDX,0xe
    //         00489509     MOV        EBP,dword ptr [this->_padding_ + EDI*0x4]
    //         0048950c     MOV        EAX,EDX
    //         0048950e     SHR        EAX,0x1f
    //         00489511     ADD        EDX,EAX
    //         00489513     MOV        EAX,dword ptr [ESP + chance]
    //         00489517     XOR        this,this
    //         00489519     MOV        this,byte ptr [EBP + EAX*0x1]
    //         0048951d     CMP        this,EDX
    //         0048951f     JG         LAB_004897a2
    //         00489525     JMP        LAB_0048952f
    //                               LAB_00489527                                                 XREF[1]:     004894d9(j)  
    //         00489527     MOV        EDI,dword ptr [ESP + x]
    //         0048952b     MOV        EAX,dword ptr [ESP + chance]
    //                               LAB_0048952f                                                 XREF[1]:     00489525(j)  
    //                              rmm_terr.cpp:456 (12)
    //         0048952f     MOV        EDX,dword ptr [ESI + 0x10]
    //         00489532     LEA        this,[EAX + EAX*0x2]
    //         00489535     MOV        EDX,dword ptr [EDX + EDI*0x4]
    //         00489538     LEA        EBP,[EDX + this->_padding_*0x8]
    //                              rmm_terr.cpp:457 (33)
    //         0048953b     MOV        this,dword ptr [ESP + param_1.base_terrain_type]
    //         00489542     MOV        EDX,dword ptr [ESP + param_1.spacing]
    //         00489549     PUSH       this
    //         0048954a     PUSH       EDX
    //         0048954b     PUSH       EDI
    //         0048954c     PUSH       EAX
    //         0048954d     MOV        EAX,dword ptr [ESP + param_1.terrain_type]
    //         00489554     PUSH       EAX
    //         00489555     MOV        this,ESI
    //         00489557     CALL       RGE_RMM_Terrain_Generator::check_terrain         uchar check_terrain(RGE_RMM_Terrain_Generator
    //                              rmm_terr.cpp:459 (34)
    //         0048955c     MOV        this,byte ptr [EBP + 0x5]
    //         0048955f     MOV        EDX,dword ptr [ESP + param_1.base_terrain_type]
    //         00489566     AND        this,0x1f
    //         00489569     AND        EAX,0xff
    //         0048956e     CMP        this,EDX
    //         00489570     JNZ        LAB_004897a2
    //         00489576     TEST       EAX,EAX
    //         00489578     JLE        LAB_004897a2
    //                              rmm_terr.cpp:461 (26)
    //         0048957e     MOV        EDX,dword ptr [ESP + param_1.clumpiness_factor]
    //         00489585     MOV        this,dword ptr [ESP + x]
    //         00489589     PUSH       EDX
    //         0048958a     MOV        EDX,dword ptr [ESP + chance]
    //         0048958e     PUSH       this
    //         0048958f     PUSH       EDX
    //         00489590     PUSH       EAX
    //         00489591     MOV        this,ESI
    //         00489593     CALL       RGE_RMM_Terrain_Generator::fig_chance            float fig_chance(RGE_RMM_Terrain_Generator * 
    //                              rmm_terr.cpp:462 (15)
    //         00489598     MOV        EAX,dword ptr [ESP + param_1.avoid_hot_spots]
    //         0048959f     FSTP       float ptr [ESP + Stack[-0xa4c]]
    //         004895a3     TEST       EAX,EAX
    //         004895a5     JZ         LAB_004895ca
    //                              rmm_terr.cpp:463 (35)
    //         004895a7     MOV        EAX,dword ptr [ESI + 0x24]
    //         004895aa     MOV        this,dword ptr [ESP + x]
    //         004895ae     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
    //         004895b1     MOV        this,dword ptr [ESP + chance]
    //         004895b5     XOR        EAX,EAX
    //         004895b7     MOV        AL,byte ptr [EDX + this->_padding_*0x1]
    //         004895ba     MOV        dword ptr [ESP + index1],EAX
    //         004895be     FILD       dword ptr [ESP + index1]
    //         004895c2     FADD       float ptr [ESP + Stack[-0xa4c]]
    //         004895c6     FSTP       float ptr [ESP + Stack[-0xa4c]]
    //                               LAB_004895ca                                                 XREF[1]:     004895a5(j)  
    //                              rmm_terr.cpp:465 (20)
    //         004895ca     MOV        AL,byte ptr [EBP + 0x5]
    //         004895cd     MOV        DL,byte ptr [ESP + param_1.terrain_type]
    //         004895d4     XOR        DL,AL
    //         004895d6     AND        DL,0x1f
    //         004895d9     XOR        DL,AL
    //         004895db     MOV        byte ptr [EBP + 0x5],DL
    //                              rmm_terr.cpp:468 (25)
    //         004895de     MOV        EAX,dword ptr [ESP + chance]
    //         004895e2     TEST       EAX,EAX
    //         004895e4     JLE        LAB_0048964c
    //         004895e6     MOV        AL,byte ptr [EBP + -0x13]
    //         004895e9     MOV        EDI,dword ptr [ESP + param_1.base_terrain_type]
    //         004895f0     AND        EAX,0x1f
    //         004895f3     CMP        EAX,EDI
    //         004895f5     JNZ        LAB_00489653
    //                              rmm_terr.cpp:469 (92)
    //         004895f7     PUSH       0x1d5
    //         004895fc     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         00489601     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00489606     LEA        EAX,[EAX + EAX*0x4]
    //         00489609     ADD        ESP,0x8
    //         0048960c     LEA        this,[EAX + EAX*0x4]
    //         0048960f     MOV        EAX,0x80010003
    //         00489614     SHL        this,0x2
    //         00489617     IMUL       this
    //         00489619     ADD        EDX,this
    //         0048961b     MOV        EAX,dword ptr [ESP + chance]
    //         0048961f     SAR        EDX,0xe
    //         00489622     MOV        this,EDX
    //         00489624     SHR        this,0x1f
    //         00489627     ADD        EDX,this
    //         00489629     PUSH       this
    //         0048962a     MOV        dword ptr [ESP + index1],EDX
    //         0048962e     MOV        EDX,dword ptr [ESP + x]
    //         00489632     FILD       dword ptr [ESP + index1]
    //         00489636     DEC        EAX
    //         00489637     MOV        this,ESI
    //         00489639     FADD       float ptr [ESP + Stack[-0xa4c]]
    //         0048963d     FSTP       float ptr [ESP]=>local_a68
    //         00489640     PUSH       0x0
    //         00489642     PUSH       EDX
    //         00489643     PUSH       EAX
    //         00489644     PUSH       EBX
    //         00489645     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //         0048964a     JMP        LAB_00489653
    //                               LAB_0048964c                                                 XREF[1]:     004895e4(j)  
    //         0048964c     MOV        EDI,dword ptr [ESP + param_1.base_terrain_type]
    //                               LAB_00489653                                                 XREF[2]:     004895f5(j), 0048964a(j)  
    //                              rmm_terr.cpp:470 (22)
    //         00489653     MOV        this,dword ptr [ESP + chance]
    //         00489657     MOV        EAX,dword ptr [ESP + loc_stack.x]
    //         0048965b     CMP        this,EAX
    //         0048965d     JGE        LAB_004896bc
    //         0048965f     MOV        DL,byte ptr [EBP + 0x1d]
    //         00489662     AND        EDX,0x1f
    //         00489665     CMP        EDX,EDI
    //         00489667     JNZ        LAB_004896bc
    //                              rmm_terr.cpp:471 (83)
    //         00489669     PUSH       0x1d7
    //         0048966e     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         00489673     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00489678     LEA        EAX,[EAX + EAX*0x4]
    //         0048967b     ADD        ESP,0x8
    //         0048967e     LEA        this,[EAX + EAX*0x4]
    //         00489681     MOV        EAX,0x80010003
    //         00489686     SHL        this,0x2
    //         00489689     IMUL       this
    //         0048968b     ADD        EDX,this
    //         0048968d     PUSH       this
    //         0048968e     SAR        EDX,0xe
    //         00489691     MOV        EAX,EDX
    //         00489693     MOV        this,dword ptr [ESP + x]
    //         00489697     SHR        EAX,0x1f
    //         0048969a     ADD        EDX,EAX
    //         0048969c     MOV        dword ptr [ESP + index1],EDX
    //         004896a0     MOV        EDX,dword ptr [ESP + chance]
    //         004896a4     FILD       dword ptr [ESP + index1]
    //         004896a8     INC        EDX
    //         004896a9     FADD       float ptr [ESP + Stack[-0xa4c]]
    //         004896ad     FSTP       float ptr [ESP]=>local_a68
    //         004896b0     PUSH       0x0
    //         004896b2     PUSH       this
    //         004896b3     PUSH       EDX
    //         004896b4     PUSH       EBX
    //         004896b5     MOV        this,ESI
    //         004896b7     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_004896bc                                                 XREF[2]:     0048965d(j), 00489667(j)  
    //                              rmm_terr.cpp:472 (31)
    //         004896bc     MOV        EAX,dword ptr [ESP + x]
    //         004896c0     TEST       EAX,EAX
    //         004896c2     JLE        LAB_0048972e
    //         004896c4     MOV        EAX,dword ptr [ESI + 0x14]
    //         004896c7     MOV        this,EBP
    //         004896c9     LEA        EAX,[EAX + EAX*0x2]
    //         004896cc     SHL        EAX,0x3
    //         004896cf     SUB        this,EAX
    //         004896d1     MOV        DL,byte ptr [ECX + this+0x5]
    //         004896d4     AND        EDX,0x1f
    //         004896d7     CMP        EDX,EDI
    //         004896d9     JNZ        LAB_0048972e
    //                              rmm_terr.cpp:473 (83)
    //         004896db     PUSH       0x1d9
    //         004896e0     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         004896e5     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004896ea     LEA        EAX,[EAX + EAX*0x4]
    //         004896ed     ADD        ESP,0x8
    //         004896f0     LEA        this,[EAX + EAX*0x4]
    //         004896f3     MOV        EAX,0x80010003
    //         004896f8     SHL        this,0x2
    //         004896fb     IMUL       this
    //         004896fd     ADD        EDX,this
    //         004896ff     PUSH       this
    //         00489700     SAR        EDX,0xe
    //         00489703     MOV        EAX,EDX
    //         00489705     MOV        this,dword ptr [ESP + x]
    //         00489709     SHR        EAX,0x1f
    //         0048970c     ADD        EDX,EAX
    //         0048970e     DEC        this
    //         0048970f     MOV        dword ptr [ESP + index1],EDX
    //         00489713     MOV        EDX,dword ptr [ESP + chance]
    //         00489717     FILD       dword ptr [ESP + index1]
    //         0048971b     FADD       float ptr [ESP + Stack[-0xa4c]]
    //         0048971f     FSTP       float ptr [ESP]=>local_a68
    //         00489722     PUSH       0x0
    //         00489724     PUSH       this
    //         00489725     PUSH       EDX
    //         00489726     PUSH       EBX
    //         00489727     MOV        this,ESI
    //         00489729     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_0048972e                                                 XREF[2]:     004896c2(j), 004896d9(j)  
    //                              rmm_terr.cpp:474 (29)
    //         0048972e     MOV        EAX,dword ptr [ESP + x]
    //         00489732     MOV        this,dword ptr [ESP + max_x]
    //         00489736     CMP        EAX,this
    //         00489738     JGE        LAB_0048979e
    //         0048973a     MOV        EAX,dword ptr [ESI + 0x14]
    //         0048973d     LEA        this,[EAX + EAX*0x2]
    //         00489740     MOV        DL,byte ptr [EBP + this->_padding_*0x8 + 0x5]
    //         00489744     AND        EDX,0x1f
    //         00489747     CMP        EDX,EDI
    //         00489749     JNZ        LAB_0048979e
    //                              rmm_terr.cpp:475 (83)
    //         0048974b     PUSH       0x1db
    //         00489750     PUSH       s_C:\msdev\work\age1_x1\rmm_terr.c               = "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp"
    //         00489755     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0048975a     LEA        EAX,[EAX + EAX*0x4]
    //         0048975d     ADD        ESP,0x8
    //         00489760     LEA        this,[EAX + EAX*0x4]
    //         00489763     MOV        EAX,0x80010003
    //         00489768     SHL        this,0x2
    //         0048976b     IMUL       this
    //         0048976d     ADD        EDX,this
    //         0048976f     PUSH       this
    //         00489770     SAR        EDX,0xe
    //         00489773     MOV        EAX,EDX
    //         00489775     MOV        this,dword ptr [ESP + x]
    //         00489779     SHR        EAX,0x1f
    //         0048977c     ADD        EDX,EAX
    //         0048977e     INC        this
    //         0048977f     MOV        dword ptr [ESP + index1],EDX
    //         00489783     MOV        EDX,dword ptr [ESP + chance]
    //         00489787     FILD       dword ptr [ESP + index1]
    //         0048978b     FADD       float ptr [ESP + Stack[-0xa4c]]
    //         0048978f     FSTP       float ptr [ESP]=>local_a68
    //         00489792     PUSH       0x0
    //         00489794     PUSH       this
    //         00489795     PUSH       EDX
    //         00489796     PUSH       EBX
    //         00489797     MOV        this,ESI
    //         00489799     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                               LAB_0048979e                                                 XREF[2]:     00489738(j), 00489749(j)  
    //                              rmm_terr.cpp:476 (22)
    //         0048979e     INC        dword ptr [ESP + in_zone]
    //                               LAB_004897a2                                                 XREF[5]:     004894a6(j), 004894c5(j), 
    //                                                                                                         0048951f(j), 00489570(j), 
    //                                                                                                         00489578(j)  
    //         004897a2     MOV        EAX,dword ptr [ESP + local_a44]
    //         004897a6     ADD        EBX,0x18
    //         004897a9     DEC        EAX
    //         004897aa     MOV        dword ptr [ESP + local_a44],EAX
    //         004897ae     JNZ        LAB_00489499
    //                               LAB_004897b4                                                 XREF[1]:     00489486(j)  
    //                              rmm_terr.cpp:446 (12)
    //         004897b4     MOV        AL,byte ptr [ESP + base_area+0x3]
    //         004897b8     TEST       AL,AL
    //         004897ba     JZ         LAB_0048947b
    //                              rmm_terr.cpp:488 (15)
    //         004897c0     MOV        EAX,dword ptr [ESP + param_1.clumps]
    //         004897c7     TEST       EAX,EAX
    //         004897c9     JLE        LAB_004898a3
    //                              rmm_terr.cpp:504 (42)
    //         004897cf     LEA        EBX=>stack[0].y,[ESP + 0x11c]
    //         004897d6     MOV        dword ptr [ESP + local_a44],EAX
    //                               LAB_004897da                                                 XREF[1]:     0048989d(j)  
    //         004897da     LEA        EAX=>max_y,[ESP + 0x30]
    //         004897de     LEA        this=>x,[ESP + 0x10]
    //         004897e2     PUSH       EAX
    //         004897e3     LEA        EDX=>chance,[ESP + 0x18]
    //         004897e7     PUSH       this
    //         004897e8     PUSH       EDX
    //         004897e9     PUSH       EBX
    //         004897ea     MOV        this,ESI
    //         004897ec     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         004897f1     TEST       EAX,EAX
    //         004897f3     JZ         LAB_00489891
    //                               LAB_004897f9                                                 XREF[1]:     0048988b(j)  
    //                              rmm_terr.cpp:491 (17)
    //         004897f9     MOV        this,dword ptr [ESI + 0x10]
    //         004897fc     MOV        EAX,dword ptr [ESP + chance]
    //         00489800     MOV        EBP,dword ptr [ESP + x]
    //         00489804     LEA        EDX,[EAX + EAX*0x2]
    //         00489807     MOV        this,dword ptr [this->_padding_ + EBP*0x4]
    //                              rmm_terr.cpp:496 (91)
    //         0048980a     TEST       EAX,EAX
    //         0048980c     LEA        EDI,[this->_padding_ + EDX*0x8]
    //         0048980f     JLE        LAB_00489833
    //         00489811     MOV        DL,byte ptr [EDI + -0x13]
    //         00489814     MOV        this,byte ptr [ESP + param_1.terrain_type]
    //         0048981b     AND        DL,0x1f
    //         0048981e     CMP        DL,this
    //         00489820     JNZ        LAB_0048983a
    //         00489822     CMP        EAX,dword ptr [ESP + loc_stack.x]
    //         00489826     JGE        LAB_0048983a
    //         00489828     MOV        AL,byte ptr [EDI + 0x1d]
    //         0048982b     AND        AL,0x1f
    //         0048982d     CMP        AL,this
    //         0048982f     JZ         LAB_00489865
    //         00489831     JMP        LAB_0048983a
    //                               LAB_00489833                                                 XREF[1]:     0048980f(j)  
    //         00489833     MOV        this,byte ptr [ESP + param_1.terrain_type]
    //                               LAB_0048983a                                                 XREF[3]:     00489820(j), 00489826(j), 
    //                                                                                                         00489831(j)  
    //         0048983a     TEST       EBP,EBP
    //         0048983c     JLE        LAB_00489872
    //         0048983e     MOV        EAX,dword ptr [ESI + 0x14]
    //         00489841     MOV        EDX,EDI
    //         00489843     LEA        EAX,[EAX + EAX*0x2]
    //         00489846     SHL        EAX,0x3
    //         00489849     SUB        EDX,EAX
    //         0048984b     MOV        DL,byte ptr [EDX + 0x5]
    //         0048984e     AND        DL,0x1f
    //         00489851     CMP        DL,this
    //         00489853     JNZ        LAB_00489872
    //         00489855     CMP        EBP,dword ptr [ESP + max_x]
    //         00489859     JLE        LAB_00489872
    //         0048985b     MOV        AL,byte ptr [EDI + EAX*0x1 + 0x5]
    //         0048985f     AND        AL,0x1f
    //         00489861     CMP        AL,this
    //         00489863     JNZ        LAB_00489872
    //                               LAB_00489865                                                 XREF[1]:     0048982f(j)  
    //                              rmm_terr.cpp:497 (44)
    //         00489865     MOV        AL,byte ptr [EDI + 0x5]
    //         00489868     XOR        this,AL
    //         0048986a     AND        this,0x1f
    //         0048986d     XOR        this,AL
    //         0048986f     MOV        byte ptr [EDI + 0x5],this
    //                               LAB_00489872                                                 XREF[4]:     0048983c(j), 00489853(j), 
    //                                                                                                         00489859(j), 00489863(j)  
    //         00489872     LEA        this=>max_y,[ESP + 0x30]
    //         00489876     LEA        EDX=>x,[ESP + 0x10]
    //         0048987a     PUSH       this
    //         0048987b     LEA        EAX=>chance,[ESP + 0x18]
    //         0048987f     PUSH       EDX
    //         00489880     PUSH       EAX
    //         00489881     PUSH       EBX
    //         00489882     MOV        this,ESI
    //         00489884     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //         00489889     TEST       EAX,EAX
    //         0048988b     JNZ        LAB_004897f9
    //                               LAB_00489891                                                 XREF[1]:     004897f3(j)  
    //                              rmm_terr.cpp:488 (18)
    //         00489891     MOV        EAX,dword ptr [ESP + local_a44]
    //         00489895     ADD        EBX,0x18
    //         00489898     DEC        EAX
    //         00489899     MOV        dword ptr [ESP + local_a44],EAX
    //         0048989d     JNZ        LAB_004897da
    //                               LAB_004898a3                                                 XREF[1]:     004897c9(j)  
    //                              rmm_terr.cpp:500 (12)
    //         004898a3     LEA        EDI=>stack[0].y,[ESP + 0x11c]
    //         004898aa     MOV        EBX,0x63
    //                               LAB_004898af                                                 XREF[1]:     004898bb(j)  
    //                              rmm_terr.cpp:501 (14)
    //         004898af     PUSH       EDI
    //         004898b0     MOV        this,ESI
    //         004898b2     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
    //         004898b7     ADD        EDI,0x18
    //         004898ba     DEC        EBX
    //         004898bb     JNZ        LAB_004898af
    //                              rmm_terr.cpp:504 (15)
    //         004898bd     POP        EDI
    //         004898be     POP        ESI
    //         004898bf     POP        EBP
    //         004898c0     MOV        AL,0x1
    //         004898c2     POP        EBX
    //         004898c3     ADD        ESP,0xa54
    //         004898c9     RET        0x20
}

