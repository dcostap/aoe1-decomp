#include "common.h"
#include "rmm_clif.h"

uchar RGE_RMM_Cliffs_Generator::generate() {
    /* TODO: Stub */
    //                              uchar __thiscall generate(RGE_RMM_Cliffs_Generator * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Cliffs    ECX:4 (auto)   this
    //                               ?generate@RGE_RMM_Cliffs_Generator@@UAEEXZ                   XREF[1]:     00571e64(*)  
    //                               RGE_RMM_Cliffs_Generator::generate
    //                              rmm_clif.cpp:41 (4)
    //         004819c0     PUSH       ESI
    //         004819c1     PUSH       EDI
    //         004819c2     MOV        ESI,this
    //                              rmm_clif.cpp:46 (5)
    //         004819c4     CALL       RGE_RMM_Cliffs_Generator::setup_cliff_maps       void setup_cliff_maps(RGE_RMM_Cliffs_Generato
    //                              rmm_clif.cpp:51 (12)
    //         004819c9     PUSH       0x32
    //         004819cb     PUSH       s_C:\msdev\work\age1_x1\rmm_clif.c               = "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp"
    //         004819d0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //                              rmm_clif.cpp:52 (12)
    //         004819d5     MOV        EAX,dword ptr [ESI + 0x30]
    //         004819d8     ADD        ESP,0x8
    //         004819db     XOR        EDI,EDI
    //         004819dd     TEST       EAX,EAX
    //         004819df     JLE        LAB_004819f0
    //                               LAB_004819e1                                                 XREF[1]:     004819ee(j)  
    //                              rmm_clif.cpp:53 (15)
    //         004819e1     MOV        this,ESI
    //         004819e3     CALL       RGE_RMM_Cliffs_Generator::generate_cliff         void generate_cliff(RGE_RMM_Cliffs_Generator 
    //         004819e8     MOV        EAX,dword ptr [ESI + 0x30]
    //         004819eb     INC        EDI
    //         004819ec     CMP        EDI,EAX
    //         004819ee     JL         LAB_004819e1
    //                               LAB_004819f0                                                 XREF[1]:     004819df(j)  
    //                              rmm_clif.cpp:56 (5)
    //         004819f0     POP        EDI
    //         004819f1     MOV        AL,0x1
    //         004819f3     POP        ESI
    //         004819f4     RET
    //         004819f5     ??         90h
    //         004819f6     NOP
    //         004819f7     NOP
    //         004819f8     NOP
    //         004819f9     NOP
    //         004819fa     NOP
    //         004819fb     NOP
    //         004819fc     NOP
    //         004819fd     NOP
    //         004819fe     NOP
    //         004819ff     NOP
    return 0;
}

void RGE_RMM_Cliffs_Generator::setup_cliff_maps() {
    /* TODO: Stub */
    //                              void __thiscall setup_cliff_maps(RGE_RMM_Cliffs_Generator * this)
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Cliffs    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00481a3c(W), 00481c77(R)  
    //              long              Stack[-0x8]:4  cliff_width2              XREF[2]:     00481a43(W), 00481c67(R)  
    //              long              Stack[-0xc]:4  cliff_height2             XREF[3]:     00481ab0(W), 00481b1f(R), 00481b27(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00481abe(W), 00481b11(R), 00481b19(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00481af0(W), 00481af6(R), 00481b02(R)  
    //              uchar             Stack[-0x18]:1 terrain_height            XREF[4]:     00481a38(W), 00481bad(R), 00481c28(R), 00481ca3(R)  
    //              long              Stack[-0x1c]:4 cliff_height              XREF[4]:     00481a85(W), 00481a9d(R), 00481bb7(R), 00481bc5(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[4]:     00481a99(W), 00481aba(R), 00481b91(R), 00481ba3(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[4]:     00481a28(W), 00481b95(R), 00481c32(R), 00481c97(R)  
    //              long              Stack[-0x28]:4 cliff_width               XREF[6]:     00481a7b(W), 00481b34(R), 00481b6b(R), 00481b80(R), 
    //                                                                                     00481bb3(R), 00481bc1(W)  
    //              long              Stack[-0x2c]:4 cliff_y                   XREF[5]:     00481a8f(W), 00481b38(R), 00481b6f(R), 00481b87(R), 
    //                                                                                     00481b9f(W)  
    //              long              Stack[-0x30]:4 cliff_x                   XREF[0,3]:   00481aa9(W), 00481ae4(W), 00481b60(R)  
    //              uchar             Stack[-0x31]:1 water_area
    //                               ?setup_cliff_maps@RGE_RMM_Cliffs_Generator@@IAEXXZ           XREF[1]:     generate:004819c4(c)  
    //                               RGE_RMM_Cliffs_Generator::setup_cliff_maps
    //                              rmm_clif.cpp:60 (7)
    //         00481a00     SUB        ESP,0x30
    //         00481a03     PUSH       EBX
    //         00481a04     PUSH       EBP
    //         00481a05     MOV        EBP,this
    //                              rmm_clif.cpp:61 (12)
    //         00481a07     MOV        EAX,0x55555556
    //         00481a0c     PUSH       ESI
    //         00481a0d     PUSH       EDI
    //         00481a0e     MOV        this,dword ptr [EBP + 0x14]
    //         00481a11     IMUL       this
    //                              rmm_clif.cpp:62 (30)
    //         00481a13     MOV        this,dword ptr [EBP + 0x18]
    //         00481a16     MOV        EAX,EDX
    //         00481a18     SHR        EAX,0x1f
    //         00481a1b     ADD        EDX,EAX
    //         00481a1d     MOV        EAX,0x55555556
    //         00481a22     MOV        EBX,EDX
    //         00481a24     IMUL       this
    //         00481a26     MOV        this,EDX
    //         00481a28     MOV        dword ptr [ESP + local_24],EBX
    //         00481a2c     SHR        this,0x1f
    //         00481a2f     ADD        EDX,this
    //                              rmm_clif.cpp:77 (27)
    //         00481a31     MOV        this,EBP
    //         00481a33     MOV        ESI,EDX
    //         00481a35     LEA        EDX,[EBX + -0x1]
    //         00481a38     MOV        dword ptr [ESP + terrain_height],ESI
    //         00481a3c     MOV        dword ptr [ESP + local_4],EDX
    //         00481a40     LEA        EAX,[ESI + -0x1]
    //         00481a43     MOV        dword ptr [ESP + cliff_width2],EAX
    //         00481a47     CALL       RGE_Random_Map_Module::clear_stack               void clear_stack(RGE_Random_Map_Module * this)
    //                              rmm_clif.cpp:78 (14)
    //         00481a4c     LEA        EAX,[EBP + 0x4f0]
    //         00481a52     MOV        this,EBP
    //         00481a54     PUSH       EAX
    //         00481a55     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
    //                              rmm_clif.cpp:79 (29)
    //         00481a5a     MOV        this,dword ptr [EBP + 0x18]
    //         00481a5d     MOV        EDI,dword ptr [EBP + 0x20]
    //         00481a60     IMUL       this,dword ptr [EBP + 0x14]
    //         00481a64     MOV        EDX,this
    //         00481a66     MOV        EAX,0x1010101
    //         00481a6b     SHR        this,0x2
    //         00481a6e     STOSD.REP  ES:EDI
    //         00481a70     MOV        this,EDX
    //         00481a72     AND        this,0x3
    //         00481a75     STOSB.REP  ES:EDI
    //                              rmm_clif.cpp:82 (14)
    //         00481a77     XOR        EDI,EDI
    //         00481a79     CMP        ESI,EDI
    //         00481a7b     MOV        dword ptr [ESP + cliff_width],EDI
    //         00481a7f     JLE        LAB_00481bd1
    //                              rmm_clif.cpp:61 (8)
    //         00481a85     MOV        dword ptr [ESP + cliff_height],EDI
    //         00481a89     JMP        LAB_00481a8d
    //                               LAB_00481a8b                                                 XREF[1]:     00481bc9(j)  
    //         00481a8b     XOR        EDI,EDI
    //                               LAB_00481a8d                                                 XREF[1]:     00481a89(j)  
    //                              rmm_clif.cpp:83 (16)
    //         00481a8d     CMP        EBX,EDI
    //         00481a8f     MOV        dword ptr [ESP + cliff_y],EDI
    //         00481a93     JLE        LAB_00481bb3
    //         00481a99     MOV        dword ptr [ESP + local_20],EDI
    //                               LAB_00481a9d                                                 XREF[1]:     00481ba7(j)  
    //                              rmm_clif.cpp:86 (7)
    //         00481a9d     MOV        EDI,dword ptr [ESP + cliff_height]
    //         00481aa1     MOV        EAX,dword ptr [EBP + 0x10]
    //                              rmm_clif.cpp:88 (20)
    //         00481aa4     OR         EDX,0xffffffff
    //         00481aa7     MOV        BL,0x1
    //         00481aa9     MOV        byte ptr [ESP + cliff_x+0x3],0x0
    //         00481aae     ADD        EDI,EAX
    //         00481ab0     MOV        dword ptr [ESP + cliff_height2],0x3
    //                               LAB_00481ab8                                                 XREF[1]:     00481b2b(j)  
    //                              rmm_clif.cpp:90 (18)
    //         00481ab8     MOV        EAX,dword ptr [EDI]
    //         00481aba     MOV        this,dword ptr [ESP + local_20]
    //         00481abe     MOV        dword ptr [ESP + local_10],0x3
    //         00481ac6     LEA        ESI,[EAX + this->_padding_*0x1 + 0x5]
    //                               LAB_00481aca                                                 XREF[1]:     00481b1d(j)  
    //                              rmm_clif.cpp:94 (6)
    //         00481aca     MOV        this,byte ptr [ESI]
    //         00481acc     MOV        AL,this
    //         00481ace     AND        AL,0x1f
    //                              rmm_clif.cpp:95 (6)
    //         00481ad0     JZ         LAB_00481aeb
    //         00481ad2     CMP        AL,0x6
    //         00481ad4     JZ         LAB_00481aeb
    //                              rmm_clif.cpp:106 (2)
    //         00481ad6     XOR        BL,BL
    //                              rmm_clif.cpp:107 (12)
    //         00481ad8     CMP        AL,0x1
    //         00481ada     JZ         LAB_00481ae4
    //         00481adc     CMP        AL,0x4
    //         00481ade     JZ         LAB_00481ae4
    //         00481ae0     CMP        AL,0x16
    //         00481ae2     JNZ        LAB_00481b11
    //                               LAB_00481ae4                                                 XREF[2]:     00481ada(j), 00481ade(j)  
    //                              rmm_clif.cpp:108 (7)
    //         00481ae4     MOV        byte ptr [ESP + cliff_x+0x3],0x1
    //         00481ae9     JMP        LAB_00481b11
    //                               LAB_00481aeb                                                 XREF[2]:     00481ad0(j), 00481ad4(j)  
    //                              rmm_clif.cpp:97 (3)
    //         00481aeb     SHR        this,0x5
    //                              rmm_clif.cpp:98 (8)
    //         00481aee     TEST       EDX,EDX
    //         00481af0     MOV        byte ptr [ESP + local_14],this
    //         00481af4     JGE        LAB_00481b02
    //                              rmm_clif.cpp:99 (10)
    //         00481af6     MOV        EDX,dword ptr [ESP + local_14]
    //         00481afa     AND        EDX,0xff
    //                              rmm_clif.cpp:100 (2)
    //         00481b00     JMP        LAB_00481b11
    //                               LAB_00481b02                                                 XREF[1]:     00481af4(j)  
    //                              rmm_clif.cpp:101 (13)
    //         00481b02     MOV        EAX,dword ptr [ESP + local_14]
    //         00481b06     AND        EAX,0xff
    //         00481b0b     CMP        EDX,EAX
    //         00481b0d     JZ         LAB_00481b11
    //                              rmm_clif.cpp:102 (2)
    //         00481b0f     XOR        BL,BL
    //                               LAB_00481b11                                                 XREF[4]:     00481ae2(j), 00481ae9(j), 
    //                                                                                                         00481b00(j), 00481b0d(j)  
    //                              rmm_clif.cpp:90 (28)
    //         00481b11     MOV        EAX,dword ptr [ESP + local_10]
    //         00481b15     ADD        ESI,0x18
    //         00481b18     DEC        EAX
    //         00481b19     MOV        dword ptr [ESP + local_10],EAX
    //         00481b1d     JNZ        LAB_00481aca
    //         00481b1f     MOV        EAX,dword ptr [ESP + cliff_height2]
    //         00481b23     ADD        EDI,0x4
    //         00481b26     DEC        EAX
    //         00481b27     MOV        dword ptr [ESP + cliff_height2],EAX
    //         00481b2b     JNZ        LAB_00481ab8
    //                              rmm_clif.cpp:112 (4)
    //         00481b2d     TEST       BL,BL
    //         00481b2f     JZ         LAB_00481b60
    //                              rmm_clif.cpp:114 (21)
    //         00481b31     MOV        EAX,dword ptr [EBP + 0x24]
    //         00481b34     MOV        this,dword ptr [ESP + cliff_width]
    //         00481b38     MOV        ESI,dword ptr [ESP + cliff_y]
    //         00481b3c     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
    //         00481b3f     ADD        EAX,ESI
    //         00481b41     CMP        byte ptr [EAX],0x0
    //         00481b44     JZ         LAB_00481b91
    //                              rmm_clif.cpp:116 (2)
    //         00481b46     INC        DL
    //                              rmm_clif.cpp:117 (22)
    //         00481b48     PUSH       0x0
    //         00481b4a     MOV        byte ptr [EAX],DL
    //         00481b4c     PUSH       0x0
    //         00481b4e     PUSH       this
    //         00481b4f     LEA        EAX,[EBP + 0x4f0]
    //         00481b55     PUSH       ESI
    //         00481b56     PUSH       EAX
    //         00481b57     MOV        this,EBP
    //         00481b59     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                              rmm_clif.cpp:120 (2)
    //         00481b5e     JMP        LAB_00481b91
    //                               LAB_00481b60                                                 XREF[1]:     00481b2f(j)  
    //                              rmm_clif.cpp:122 (8)
    //         00481b60     MOV        AL,byte ptr [ESP + cliff_x+0x3]
    //         00481b64     TEST       AL,AL
    //         00481b66     JZ         LAB_00481b7d
    //                              rmm_clif.cpp:123 (21)
    //         00481b68     MOV        this,dword ptr [EBP + 0x40]
    //         00481b6b     MOV        EDX,dword ptr [ESP + cliff_width]
    //         00481b6f     MOV        EAX,dword ptr [ESP + cliff_y]
    //         00481b73     PUSH       this
    //         00481b74     PUSH       EDX
    //         00481b75     PUSH       EAX
    //         00481b76     MOV        this,EBP
    //         00481b78     CALL       RGE_RMM_Cliffs_Generator::invalidate_cliff_area  void invalidate_cliff_area(RGE_RMM_Cliffs_Gen
    //                               LAB_00481b7d                                                 XREF[1]:     00481b66(j)  
    //                              rmm_clif.cpp:124 (82)
    //         00481b7d     MOV        this,dword ptr [EBP + 0x24]
    //         00481b80     MOV        EDX,dword ptr [ESP + cliff_width]
    //         00481b84     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00481b87     MOV        this,dword ptr [ESP + cliff_y]
    //         00481b8b     MOV        ESI,this
    //         00481b8d     MOV        byte ptr [EAX + this->_padding_*0x1],0x0
    //                               LAB_00481b91                                                 XREF[2]:     00481b44(j), 00481b5e(j)  
    //         00481b91     MOV        this,dword ptr [ESP + local_20]
    //         00481b95     MOV        EAX,dword ptr [ESP + local_24]
    //         00481b99     INC        ESI
    //         00481b9a     ADD        this,0x48
    //         00481b9d     CMP        ESI,EAX
    //         00481b9f     MOV        dword ptr [ESP + cliff_y],ESI
    //         00481ba3     MOV        dword ptr [ESP + local_20],this
    //         00481ba7     JL         LAB_00481a9d
    //         00481bad     MOV        ESI,dword ptr [ESP + terrain_height]
    //         00481bb1     MOV        EBX,EAX
    //                               LAB_00481bb3                                                 XREF[1]:     00481a93(j)  
    //         00481bb3     MOV        EAX,dword ptr [ESP + cliff_width]
    //         00481bb7     MOV        EDX,dword ptr [ESP + cliff_height]
    //         00481bbb     INC        EAX
    //         00481bbc     ADD        EDX,0xc
    //         00481bbf     CMP        EAX,ESI
    //         00481bc1     MOV        dword ptr [ESP + cliff_width],EAX
    //         00481bc5     MOV        dword ptr [ESP + cliff_height],EDX
    //         00481bc9     JL         LAB_00481a8b
    //                              rmm_clif.cpp:82 (2)
    //         00481bcf     XOR        EDI,EDI
    //                               LAB_00481bd1                                                 XREF[1]:     00481a7f(j)  
    //                              rmm_clif.cpp:129 (11)
    //         00481bd1     CMP        dword ptr [EBP + 0x4ec],EDI
    //         00481bd7     JLE        LAB_00481c28
    //         00481bd9     LEA        ESI,[EBP + 0x4c]
    //                               LAB_00481bdc                                                 XREF[1]:     00481c26(j)  
    //                              rmm_clif.cpp:132 (76)
    //         00481bdc     MOV        this,dword ptr [ESI + 0x4]
    //         00481bdf     MOV        EAX,0x55555556
    //         00481be4     IMUL       this
    //         00481be6     MOV        EAX,EDX
    //         00481be8     SHR        EAX,0x1f
    //         00481beb     LEA        this,[EDX + EAX*0x1 + 0x2]
    //         00481bef     MOV        EAX,0x55555556
    //         00481bf4     PUSH       this
    //         00481bf5     MOV        this,dword ptr [ESI]
    //         00481bf7     IMUL       this
    //         00481bf9     MOV        this,dword ptr [ESI + -0x4]
    //         00481bfc     MOV        EAX,EDX
    //         00481bfe     SHR        EAX,0x1f
    //         00481c01     ADD        EDX,EAX
    //         00481c03     MOV        EAX,0x55555556
    //         00481c08     PUSH       EDX
    //         00481c09     IMUL       this
    //         00481c0b     MOV        this,EDX
    //         00481c0d     SHR        this,0x1f
    //         00481c10     ADD        EDX,this
    //         00481c12     MOV        this,EBP
    //         00481c14     PUSH       EDX
    //         00481c15     CALL       RGE_RMM_Cliffs_Generator::invalidate_cliff_area  void invalidate_cliff_area(RGE_RMM_Cliffs_Gen
    //         00481c1a     MOV        EAX,dword ptr [EBP + 0x4ec]
    //         00481c20     INC        EDI
    //         00481c21     ADD        ESI,0xc
    //         00481c24     CMP        EDI,EAX
    //         00481c26     JL         LAB_00481bdc
    //                               LAB_00481c28                                                 XREF[1]:     00481bd7(j)  
    //                              rmm_clif.cpp:155 (10)
    //         00481c28     MOV        EAX,dword ptr [ESP + terrain_height]
    //         00481c2c     XOR        EBX,EBX
    //         00481c2e     TEST       EAX,EAX
    //         00481c30     JLE        LAB_00481cac
    //                               LAB_00481c32                                                 XREF[1]:     00481caa(j)  
    //                              rmm_clif.cpp:156 (12)
    //         00481c32     MOV        EAX,dword ptr [ESP + local_24]
    //         00481c36     XOR        ESI,ESI
    //         00481c38     TEST       EAX,EAX
    //         00481c3a     JLE        LAB_00481ca3
    //         00481c3c     XOR        EDI,EDI
    //                               LAB_00481c3e                                                 XREF[1]:     00481ca1(j)  
    //                              rmm_clif.cpp:157 (16)
    //         00481c3e     MOV        EAX,dword ptr [EBP + 0x24]
    //         00481c41     MOV        EDX,dword ptr [EAX + EBX*0x4]
    //         00481c44     LEA        this,[ESI + EDX*0x1]
    //         00481c47     MOV        DL,byte ptr [ESI + EDX*0x1]
    //         00481c4a     TEST       DL,DL
    //         00481c4c     JZ         LAB_00481c97
    //                              rmm_clif.cpp:159 (14)
    //         00481c4e     TEST       EBX,EBX
    //         00481c50     JLE        LAB_00481c5c
    //         00481c52     MOV        EDX,dword ptr [EAX + EBX*0x4 + -0x4]
    //         00481c56     CMP        byte ptr [EDX + ESI*0x1],0x0
    //         00481c5a     JNZ        LAB_00481c97
    //                               LAB_00481c5c                                                 XREF[1]:     00481c50(j)  
    //                              rmm_clif.cpp:161 (11)
    //         00481c5c     TEST       EDI,EDI
    //         00481c5e     JLE        LAB_00481c67
    //         00481c60     MOV        DL,byte ptr [this->_padding_ + -0x1]
    //         00481c63     TEST       DL,DL
    //         00481c65     JNZ        LAB_00481c97
    //                               LAB_00481c67                                                 XREF[1]:     00481c5e(j)  
    //                              rmm_clif.cpp:163 (16)
    //         00481c67     CMP        EBX,dword ptr [ESP + cliff_width2]
    //         00481c6b     JGE        LAB_00481c77
    //         00481c6d     MOV        EAX,dword ptr [EAX + EBX*0x4 + 0x4]
    //         00481c71     CMP        byte ptr [EAX + ESI*0x1],0x0
    //         00481c75     JNZ        LAB_00481c97
    //                               LAB_00481c77                                                 XREF[1]:     00481c6b(j)  
    //                              rmm_clif.cpp:165 (13)
    //         00481c77     CMP        ESI,dword ptr [ESP + local_4]
    //         00481c7b     JGE        LAB_00481c84
    //         00481c7d     MOV        AL,byte ptr [ECX + this+0x1]
    //         00481c80     TEST       AL,AL
    //         00481c82     JNZ        LAB_00481c97
    //                               LAB_00481c84                                                 XREF[1]:     00481c7b(j)  
    //                              rmm_clif.cpp:167 (3)
    //         00481c84     MOV        byte ptr [this->_padding_],0x0
    //                              rmm_clif.cpp:168 (28)
    //         00481c87     MOV        this,dword ptr [EBP + 0x2c]
    //         00481c8a     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         00481c8d     MOV        this,EBP
    //         00481c8f     ADD        EDX,EDI
    //         00481c91     PUSH       EDX
    //         00481c92     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module 
    //                               LAB_00481c97                                                 XREF[5]:     00481c4c(j), 00481c5a(j), 
    //                                                                                                         00481c65(j), 00481c75(j), 
    //                                                                                                         00481c82(j)  
    //         00481c97     MOV        EAX,dword ptr [ESP + local_24]
    //         00481c9b     INC        ESI
    //         00481c9c     ADD        EDI,0x18
    //         00481c9f     CMP        ESI,EAX
    //         00481ca1     JL         LAB_00481c3e
    //                               LAB_00481ca3                                                 XREF[1]:     00481c3a(j)  
    //                              rmm_clif.cpp:155 (9)
    //         00481ca3     MOV        EAX,dword ptr [ESP + terrain_height]
    //         00481ca7     INC        EBX
    //         00481ca8     CMP        EBX,EAX
    //         00481caa     JL         LAB_00481c32
    //                               LAB_00481cac                                                 XREF[1]:     00481c30(j)  
    //                              rmm_clif.cpp:172 (14)
    //         00481cac     LEA        EAX,[EBP + 0x4f0]
    //         00481cb2     MOV        this,EBP
    //         00481cb4     PUSH       EAX
    //         00481cb5     CALL       RGE_Random_Map_Module::randomize_stack           void randomize_stack(RGE_Random_Map_Module * 
    //                              rmm_clif.cpp:173 (8)
    //         00481cba     POP        EDI
    //         00481cbb     POP        ESI
    //         00481cbc     POP        EBP
    //         00481cbd     POP        EBX
    //         00481cbe     ADD        ESP,0x30
    //         00481cc1     RET
    //         00481cc2     ??         90h
    //         00481cc3     NOP
    //         00481cc4     NOP
    //         00481cc5     NOP
    //         00481cc6     NOP
    //         00481cc7     NOP
    //         00481cc8     NOP
    //         00481cc9     NOP
    //         00481cca     NOP
    //         00481ccb     NOP
    //         00481ccc     NOP
    //         00481ccd     NOP
    //         00481cce     NOP
    //         00481ccf     NOP
    return;
}

void RGE_RMM_Cliffs_Generator::generate_cliff() {
    /* TODO: Stub */
    //                              void __thiscall generate_cliff(RGE_RMM_Cliffs_Generator * this)
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Cliffs    ECX:4 (auto)   this
    //              Map_Stack         Stack[-0x1c]   cliff                     XREF[2,5]:   00481d47(*), 00481f26(*), 00481d35(*), 00481d8f(*), 
    //                                                                                     00481ee6(*), 00481f34(*), 00481f1a(R)  
    //              float             Stack[-0x20]:4 cost                      XREF[3]:     00481d22(W), 00481de7(R), 00481f09(R)  
    //              long              Stack[-0x24]:4 this_cliff_size           XREF[3]:     00481dda(W), 00481f01(R), 00481f10(W)  
    //              long              Stack[-0x28]:4 index                     XREF[5]:     00481d9a(W), 00481e4a(R), 00481e65(R), 00481e83(R), 
    //                                                                                     00481ea9(R)  
    //              long              Stack[-0x2c]:4 valid_height              XREF[11]:    00481d4b(*), 00481d61(R), 00481da6(R), 00481e4e(*), 
    //                                                                                     00481e69(*), 00481e87(*), 00481ead(*), 00481ed9(R), 
    //                                                                                     00481ef6(R), 00481f2a(*), 00481f41(R)  
    //              long              Stack[-0x30]:4 y                         XREF[11]:    00481d50(*), 00481d65(R), 00481db7(R), 00481e53(*), 
    //                                                                                     00481e6e(*), 00481e8c(*), 00481eb2(*), 00481edd(R), 
    //                                                                                     00481efd(R), 00481f2f(*), 00481f45(R)  
    //              long              Stack[-0x34]:4 x                         XREF[0,6]:   00481dff(W), 00481ec7(W), 00481ecc(R), 00481d09(W), 
    //                                                                                     00481ea1(R), 00481ed0(W)  
    //              uchar             Stack[-0x35]:1 first_cliff
    //              uchar             Stack[-0x36]:1 cliff_end_found
    //                               ?generate_cliff@RGE_RMM_Cliffs_Generator@@IAEXXZ             XREF[1]:     generate:004819e3(c)  
    //                               RGE_RMM_Cliffs_Generator::generate_cliff
    //                              rmm_clif.cpp:177 (9)
    //         00481cd0     SUB        ESP,0x34
    //         00481cd3     PUSH       EBX
    //         00481cd4     PUSH       EBP
    //         00481cd5     PUSH       ESI
    //         00481cd6     PUSH       EDI
    //         00481cd7     MOV        ESI,this
    //                              rmm_clif.cpp:197 (48)
    //         00481cd9     PUSH       0xc4
    //         00481cde     PUSH       s_C:\msdev\work\age1_x1\rmm_clif.c               = "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp"
    //         00481ce3     OR         EBP,0xffffffff
    //         00481ce6     MOV        EBX,dword ptr [ESI + 0x3c]
    //         00481ce9     OR         EDI,0xffffffff
    //         00481cec     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00481cf1     MOV        this,EAX
    //         00481cf3     MOV        EAX,0x80010003
    //         00481cf8     IMUL       this,EBX
    //         00481cfb     SHL        this,0x1
    //         00481cfd     IMUL       this
    //         00481cff     ADD        EDX,this
    //         00481d01     ADD        ESP,0x8
    //         00481d04     SAR        EDX,0xe
    //         00481d07     MOV        EAX,EDX
    //                              rmm_clif.cpp:200 (15)
    //         00481d09     MOV        byte ptr [ESP + x+0x3],0x1
    //         00481d0e     SHR        EAX,0x1f
    //         00481d11     ADD        EDX,EAX
    //         00481d13     MOV        EAX,dword ptr [ESI + 0x38]
    //         00481d16     ADD        EDX,EAX
    //                              rmm_clif.cpp:203 (29)
    //         00481d18     MOV        EAX,dword ptr [ESI + 0x500]
    //         00481d1e     SUB        EDX,EBX
    //         00481d20     TEST       EAX,EAX
    //         00481d22     MOV        dword ptr [ESP + cost],EDX
    //         00481d26     JZ         LAB_00481fb7
    //         00481d2c     CMP        EDX,0x3
    //         00481d2f     JL         LAB_00481fb7
    //                              rmm_clif.cpp:207 (12)
    //         00481d35     LEA        this=>cliff.y,[ESP + 0x2c]
    //         00481d39     PUSH       this
    //         00481d3a     MOV        this,ESI
    //         00481d3c     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
    //                              rmm_clif.cpp:210 (29)
    //         00481d41     LEA        EBX,[ESI + 0x4f0]
    //                               LAB_00481d47                                                 XREF[1]:     00481d80(j)  
    //         00481d47     LEA        EDX=>cliff,[ESP + 0x28]
    //         00481d4b     LEA        EAX=>valid_height,[ESP + 0x18]
    //         00481d4f     PUSH       EDX
    //         00481d50     LEA        this=>y,[ESP + 0x18]
    //         00481d54     PUSH       EAX
    //         00481d55     PUSH       this
    //         00481d56     PUSH       EBX
    //         00481d57     MOV        this,ESI
    //         00481d59     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //                              rmm_clif.cpp:211 (20)
    //         00481d5e     MOV        EDX,dword ptr [ESI + 0x24]
    //         00481d61     MOV        EAX,dword ptr [ESP + valid_height]
    //         00481d65     MOV        this,dword ptr [ESP + y]
    //         00481d69     MOV        EDX,dword ptr [EDX + EAX*0x4]
    //         00481d6c     CMP        byte ptr [EDX + this->_padding_*0x1],0x0
    //         00481d70     JNZ        LAB_00481d82
    //                              rmm_clif.cpp:214 (14)
    //         00481d72     MOV        EAX,dword ptr [ESI + 0x500]
    //         00481d78     TEST       EAX,EAX
    //         00481d7a     JZ         LAB_00481fb7
    //                              rmm_clif.cpp:208 (2)
    //         00481d80     JMP        LAB_00481d47
    //                               LAB_00481d82                                                 XREF[1]:     00481d70(j)  
    //                              rmm_clif.cpp:218 (3)
    //         00481d82     MOV        EDX,dword ptr [ESI + 0x24]
    //                              rmm_clif.cpp:219 (30)
    //         00481d85     PUSH       0x0
    //         00481d87     PUSH       0x0
    //         00481d89     XOR        EBX,EBX
    //         00481d8b     MOV        EDX,dword ptr [EDX + EAX*0x4]
    //         00481d8e     PUSH       EAX
    //         00481d8f     LEA        EAX=>cliff.y,[ESP + 0x38]
    //         00481d93     PUSH       this
    //         00481d94     MOV        BL,byte ptr [EDX + this->_padding_*0x1]
    //         00481d97     PUSH       EAX
    //         00481d98     MOV        this,ESI
    //         00481d9a     MOV        dword ptr [ESP + index],EBX
    //         00481d9e     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                              rmm_clif.cpp:220 (7)
    //         00481da3     MOV        this,dword ptr [ESI + 0x24]
    //         00481da6     MOV        EDX,dword ptr [ESP + valid_height]
    //                              rmm_clif.cpp:221 (48)
    //         00481daa     PUSH       0xdd
    //         00481daf     PUSH       s_C:\msdev\work\age1_x1\rmm_clif.c               = "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp"
    //         00481db4     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00481db7     MOV        this,dword ptr [ESP + y]
    //         00481dbb     MOV        byte ptr [EAX + this->_padding_*0x1],0x0
    //         00481dbf     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00481dc4     MOV        this,EAX
    //         00481dc6     MOV        EAX,0x80010003
    //         00481dcb     SHL        this,0x2
    //         00481dce     IMUL       this
    //         00481dd0     ADD        EDX,this
    //         00481dd2     ADD        ESP,0x8
    //         00481dd5     SAR        EDX,0xe
    //         00481dd8     MOV        EAX,EDX
    //                              rmm_clif.cpp:223 (27)
    //         00481dda     MOV        dword ptr [ESP + this_cliff_size],0x0
    //         00481de2     SHR        EAX,0x1f
    //         00481de5     ADD        EDX,EAX
    //         00481de7     MOV        EAX,dword ptr [ESP + cost]
    //         00481deb     TEST       EAX,EAX
    //         00481ded     MOV        EBX,EDX
    //         00481def     JLE        LAB_00481f1a
    //                               LAB_00481df5                                                 XREF[1]:     00481f14(j)  
    //                              rmm_clif.cpp:227 (51)
    //         00481df5     PUSH       0xe3
    //         00481dfa     PUSH       s_C:\msdev\work\age1_x1\rmm_clif.c               = "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp"
    //         00481dff     MOV        byte ptr [ESP + x+0x2],0x0
    //         00481e04     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00481e09     LEA        this,[EAX + EAX*0x4]
    //         00481e0c     MOV        EAX,0x80010003
    //         00481e11     ADD        ESP,0x8
    //         00481e14     LEA        this,[ECX + ECX*0x4]
    //         00481e17     SHL        this,0x2
    //         00481e1a     IMUL       this
    //         00481e1c     ADD        EDX,this
    //         00481e1e     SAR        EDX,0xe
    //         00481e21     MOV        this,EDX
    //         00481e23     SHR        this,0x1f
    //         00481e26     ADD        EDX,this
    //                              rmm_clif.cpp:228 (5)
    //         00481e28     CMP        EDX,0x12
    //         00481e2b     JGE        LAB_00481e3b
    //                              rmm_clif.cpp:230 (12)
    //         00481e2d     TEST       EBX,EBX
    //         00481e2f     JG         LAB_00481e38
    //         00481e31     MOV        EBX,0x3
    //         00481e36     JMP        LAB_00481e4a
    //                               LAB_00481e38                                                 XREF[1]:     00481e2f(j)  
    //         00481e38     DEC        EBX
    //                              rmm_clif.cpp:231 (7)
    //         00481e39     JMP        LAB_00481e4a
    //                               LAB_00481e3b                                                 XREF[1]:     00481e2b(j)  
    //         00481e3b     CMP        EDX,0x24
    //         00481e3e     JGE        LAB_00481e4a
    //                              rmm_clif.cpp:233 (10)
    //         00481e40     CMP        EBX,0x3
    //         00481e43     JL         LAB_00481e49
    //         00481e45     XOR        EBX,EBX
    //         00481e47     JMP        LAB_00481e4a
    //                               LAB_00481e49                                                 XREF[1]:     00481e43(j)  
    //         00481e49     INC        EBX
    //                               LAB_00481e4a                                                 XREF[4]:     00481e36(j), 00481e39(j), 
    //                                                                                                         00481e3e(j), 00481e47(j)  
    //                              rmm_clif.cpp:235 (27)
    //         00481e4a     MOV        EDX,dword ptr [ESP + index]
    //         00481e4e     LEA        EAX=>valid_height,[ESP + 0x18]
    //         00481e52     PUSH       EDX
    //         00481e53     LEA        this=>y,[ESP + 0x18]
    //         00481e57     PUSH       EAX
    //         00481e58     PUSH       this
    //         00481e59     PUSH       EBX
    //         00481e5a     MOV        this,ESI
    //         00481e5c     CALL       RGE_RMM_Cliffs_Generator::check_for_valid_clif   uchar check_for_valid_cliff_site(RGE_RMM_Clif
    //         00481e61     TEST       AL,AL
    //         00481e63     JNZ        LAB_00481ecc
    //                              rmm_clif.cpp:236 (30)
    //         00481e65     MOV        EDX,dword ptr [ESP + index]
    //         00481e69     LEA        EAX=>valid_height,[ESP + 0x18]
    //         00481e6d     PUSH       EDX
    //         00481e6e     LEA        this=>y,[ESP + 0x18]
    //         00481e72     PUSH       EAX
    //         00481e73     LEA        EDX,[EBX + 0x1]
    //         00481e76     PUSH       this
    //         00481e77     PUSH       EDX
    //         00481e78     MOV        this,ESI
    //         00481e7a     CALL       RGE_RMM_Cliffs_Generator::check_for_valid_clif   uchar check_for_valid_cliff_site(RGE_RMM_Clif
    //         00481e7f     TEST       AL,AL
    //         00481e81     JNZ        LAB_00481ecc
    //                              rmm_clif.cpp:237 (30)
    //         00481e83     MOV        EAX,dword ptr [ESP + index]
    //         00481e87     LEA        this=>valid_height,[ESP + 0x18]
    //         00481e8b     PUSH       EAX
    //         00481e8c     LEA        EDX=>y,[ESP + 0x18]
    //         00481e90     PUSH       this
    //         00481e91     LEA        EAX,[EBX + -0x1]
    //         00481e94     PUSH       EDX
    //         00481e95     PUSH       EAX
    //         00481e96     MOV        this,ESI
    //         00481e98     CALL       RGE_RMM_Cliffs_Generator::check_for_valid_clif   uchar check_for_valid_cliff_site(RGE_RMM_Clif
    //         00481e9d     TEST       AL,AL
    //         00481e9f     JNZ        LAB_00481ecc
    //                              rmm_clif.cpp:240 (8)
    //         00481ea1     MOV        AL,byte ptr [ESP + x+0x3]
    //         00481ea5     TEST       AL,AL
    //         00481ea7     JZ         LAB_00481ec7
    //                              rmm_clif.cpp:242 (30)
    //         00481ea9     MOV        this,dword ptr [ESP + index]
    //         00481ead     LEA        EDX=>valid_height,[ESP + 0x18]
    //         00481eb1     PUSH       this
    //         00481eb2     LEA        EAX=>y,[ESP + 0x18]
    //         00481eb6     PUSH       EDX
    //         00481eb7     LEA        this,[EBX + -0x2]
    //         00481eba     PUSH       EAX
    //         00481ebb     PUSH       this
    //         00481ebc     MOV        this,ESI
    //         00481ebe     CALL       RGE_RMM_Cliffs_Generator::check_for_valid_clif   uchar check_for_valid_cliff_site(RGE_RMM_Clif
    //         00481ec3     TEST       AL,AL
    //         00481ec5     JNZ        LAB_00481ecc
    //                               LAB_00481ec7                                                 XREF[1]:     00481ea7(j)  
    //                              rmm_clif.cpp:246 (5)
    //         00481ec7     MOV        byte ptr [ESP + x+0x2],0x1
    //                               LAB_00481ecc                                                 XREF[4]:     00481e63(j), 00481e81(j), 
    //                                                                                                         00481e9f(j), 00481ec5(j)  
    //                              rmm_clif.cpp:251 (13)
    //         00481ecc     MOV        AL,byte ptr [ESP + x+0x2]
    //         00481ed0     MOV        byte ptr [ESP + x+0x3],0x0
    //         00481ed5     TEST       AL,AL
    //         00481ed7     JNZ        LAB_00481f1a
    //                              rmm_clif.cpp:253 (26)
    //         00481ed9     MOV        EDX,dword ptr [ESP + valid_height]
    //         00481edd     MOV        EAX,dword ptr [ESP + y]
    //         00481ee1     PUSH       0x0
    //         00481ee3     PUSH       0x0
    //         00481ee5     PUSH       EDX
    //         00481ee6     LEA        this=>cliff.y,[ESP + 0x38]
    //         00481eea     PUSH       EAX
    //         00481eeb     PUSH       this
    //         00481eec     MOV        this,ESI
    //         00481eee     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
    //                              rmm_clif.cpp:254 (39)
    //         00481ef3     MOV        EDX,dword ptr [ESI + 0x24]
    //         00481ef6     MOV        EAX,dword ptr [ESP + valid_height]
    //         00481efa     MOV        this,dword ptr [EDX + EAX*0x4]
    //         00481efd     MOV        EDX,dword ptr [ESP + y]
    //         00481f01     MOV        EAX,dword ptr [ESP + this_cliff_size]
    //         00481f05     MOV        byte ptr [this->_padding_ + EDX*0x1],0x0
    //         00481f09     MOV        this,dword ptr [ESP + cost]
    //         00481f0d     INC        EAX
    //         00481f0e     CMP        EAX,this
    //         00481f10     MOV        dword ptr [ESP + this_cliff_size],EAX
    //         00481f14     JL         LAB_00481df5
    //                               LAB_00481f1a                                                 XREF[2]:     00481def(j), 00481ed7(j)  
    //                              rmm_clif.cpp:260 (12)
    //         00481f1a     MOV        EAX,dword ptr [ESP + cliff.prev]
    //         00481f1e     TEST       EAX,EAX
    //         00481f20     JZ         LAB_00481fb7
    //                               LAB_00481f26                                                 XREF[1]:     00481fb1(j)  
    //                              rmm_clif.cpp:263 (27)
    //         00481f26     LEA        EAX=>cliff,[ESP + 0x28]
    //         00481f2a     LEA        this=>valid_height,[ESP + 0x18]
    //         00481f2e     PUSH       EAX
    //         00481f2f     LEA        EDX=>y,[ESP + 0x18]
    //         00481f33     PUSH       this=>DAT_fffffff8
    //         00481f34     LEA        EAX=>cliff.y,[ESP + 0x34]
    //         00481f38     PUSH       EDX=>DAT_fffffff4
    //         00481f39     PUSH       EAX=>DAT_fffffff0
    //         00481f3a     MOV        this,ESI
    //         00481f3c     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
    //                              rmm_clif.cpp:264 (13)
    //         00481f41     MOV        EAX,dword ptr [ESP + valid_height]
    //         00481f45     MOV        EDX,dword ptr [ESP + y]
    //         00481f49     CMP        EBP,-0x1
    //         00481f4c     JNZ        LAB_00481f52
    //                              rmm_clif.cpp:266 (2)
    //         00481f4e     MOV        EBP,EDX
    //                              rmm_clif.cpp:267 (2)
    //         00481f50     MOV        EDI,EAX
    //                               LAB_00481f52                                                 XREF[1]:     00481f4c(j)  
    //                              rmm_clif.cpp:269 (32)
    //         00481f52     MOV        this,dword ptr [ESI + 0xc]
    //         00481f55     PUSH       0x10
    //         00481f57     LEA        EAX,[EAX + EAX*0x2 + 0x1]
    //         00481f5b     PUSH       0x1
    //         00481f5d     LEA        EDX,[EDX + EDX*0x2 + 0x1]
    //         00481f61     LEA        EDI,[EDI + EDI*0x2 + 0x1]
    //         00481f65     PUSH       EAX
    //         00481f66     LEA        EBX,[EBP + EBP*0x2 + 0x1]
    //         00481f6a     MOV        EBP,dword ptr [this->_padding_]
    //         00481f6c     PUSH       EDX
    //         00481f6d     PUSH       EDI
    //         00481f6e     PUSH       EBX
    //         00481f6f     CALL       dword ptr [EBP + 0x10]
    //                              rmm_clif.cpp:270 (32)
    //         00481f72     MOV        EAX,dword ptr [ESP + 0x18]
    //         00481f76     MOV        this,dword ptr [ESI + 0xc]
    //         00481f79     PUSH       0x0
    //         00481f7b     PUSH       0x0=>DAT_fffffff8
    //         00481f7d     LEA        EAX,[EAX + EAX*0x2 + 0x1]
    //         00481f81     MOV        EDX,dword ptr [this->_padding_]
    //         00481f83     PUSH       EAX=>DAT_fffffff4
    //         00481f84     MOV        EAX,dword ptr [ESP + 0x20]
    //         00481f88     LEA        EAX,[EAX + EAX*0x2 + 0x1]
    //         00481f8c     PUSH       EAX=>DAT_fffffff0
    //         00481f8d     PUSH       EDI
    //         00481f8e     PUSH       EBX
    //         00481f8f     CALL       dword ptr [EDX + 0x20]
    //                              rmm_clif.cpp:275 (37)
    //         00481f92     MOV        EDX,dword ptr [ESI + 0x44]
    //         00481f95     MOV        this,dword ptr [ESP + 0x18]
    //         00481f99     MOV        EAX,dword ptr [ESP + 0x14]
    //         00481f9d     PUSH       EDX
    //         00481f9e     MOV        EDI,this
    //         00481fa0     PUSH       this=>DAT_fffffff8
    //         00481fa1     PUSH       EAX=>DAT_fffffff4
    //         00481fa2     MOV        this,ESI
    //         00481fa4     MOV        EBP,EAX
    //         00481fa6     CALL       RGE_RMM_Cliffs_Generator::invalidate_cliff_area  void invalidate_cliff_area(RGE_RMM_Cliffs_Gen
    //         00481fab     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00481faf     TEST       EAX,EAX
    //         00481fb1     JNZ        LAB_00481f26
    //                               LAB_00481fb7                                                 XREF[4]:     00481d26(j), 00481d2f(j), 
    //                                                                                                         00481d7a(j), 00481f20(j)  
    //                              rmm_clif.cpp:294 (8)
    //         00481fb7     POP        EDI
    //         00481fb8     POP        ESI
    //         00481fb9     POP        EBP
    //         00481fba     POP        EBX
    //         00481fbb     ADD        ESP,0x34
    //         00481fbe     RET
    //         00481fbf     ??         90h
    //                              * protected: unsigned char __thiscall RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(long,long... *
    //                              uchar __thiscall check_for_valid_cliff_site(RGE_RMM_Cliffs_Generator
    //              uchar             AL:1           <RETURN>
    //              RGE_RMM_Cliffs    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00481fcd(R)  
    //              long *            Stack[0x8]:4   param_2                   XREF[1]:     00481fc6(R)  
    //              long *            Stack[0xc]:4   param_3                   XREF[2]:     00481fc0(R), 00482066(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0048205b(R)  
    //                               ?check_for_valid_cliff_site@RGE_RMM_Cliffs_Generator@@IAEEJ  XREF[4]:     generate_cliff:00481e5c(c), 
    //                               RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site                      generate_cliff:00481e7a(c), 
    //                                                                                                         generate_cliff:00481e98(c), 
    //                                                                                                         generate_cliff:00481ebe(c)  
    //                              rmm_clif.cpp:298 (13)
    //         00481fc0     MOV        EAX,dword ptr [ESP + param_3]
    //         00481fc4     PUSH       EBX
    //         00481fc5     PUSH       EBP
    //         00481fc6     MOV        EBP,dword ptr [ESP + param_2]
    //         00481fca     MOV        EBX,dword ptr [EAX]
    //         00481fcc     PUSH       ESI
    //                              rmm_clif.cpp:302 (25)
    //         00481fcd     MOV        ESI,dword ptr [ESP + param_1]
    //         00481fd1     PUSH       EDI
    //         00481fd2     MOV        EDI,dword ptr [EBP]
    //         00481fd5     CMP        ESI,0x3
    //         00481fd8     JLE        LAB_00481fec
    //         00481fda     LEA        EDX,[ESI + -0x1]
    //         00481fdd     MOV        EAX,0xaaaaaaab
    //         00481fe2     MUL        EDX
    //         00481fe4     SHR        EDX,0x1
    //                               LAB_00481fe6                                                 XREF[1]:     00481fea(j)  
    //                              rmm_clif.cpp:303 (6)
    //         00481fe6     SUB        ESI,0x3
    //         00481fe9     DEC        EDX
    //         00481fea     JNZ        LAB_00481fe6
    //                               LAB_00481fec                                                 XREF[1]:     00481fd8(j)  
    //                              rmm_clif.cpp:305 (27)
    //         00481fec     TEST       ESI,ESI
    //         00481fee     JGE        LAB_00482007
    //         00481ff0     MOV        EDX,0x2
    //         00481ff5     MOV        EAX,0xaaaaaaab
    //         00481ffa     SUB        EDX,ESI
    //         00481ffc     MUL        EDX
    //         00481ffe     SHR        EDX,0x1
    //         00482000     MOV        EAX,EDX
    //         00482002     ADD        EAX,ESI
    //         00482004     LEA        ESI,[EAX + EDX*0x2]
    //                               LAB_00482007                                                 XREF[1]:     00481fee(j)  
    //                              rmm_clif.cpp:308 (12)
    //         00482007     CMP        ESI,0x3
    //         0048200a     JA         switchD_0048200c::default
    //                               switchD_0048200c::switchD
    //         0048200c     JMP        dword ptr [ESI*0x4 + switchD_0048200c::switchd   = 00482013
    //                               switchD_0048200c::caseD_0                                    XREF[2]:     0048200c(j), 00482084(*)  
    //                              rmm_clif.cpp:311 (4)
    //         00482013     TEST       EBX,EBX
    //         00482015     JLE        LAB_00482078
    //                              rmm_clif.cpp:312 (1)
    //         00482017     DEC        EBX
    //                              rmm_clif.cpp:315 (2)
    //         00482018     JMP        switchD_0048200c::default
    //                               switchD_0048200c::caseD_1                                    XREF[2]:     0048200c(j), 00482088(*)  
    //                              rmm_clif.cpp:317 (23)
    //         0048201a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048201d     MOV        EAX,0x55555556
    //         00482022     IMUL       EDX
    //         00482024     MOV        EAX,EDX
    //         00482026     SHR        EAX,0x1f
    //         00482029     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         0048202d     CMP        EDI,EDX
    //         0048202f     JGE        LAB_00482078
    //                              rmm_clif.cpp:318 (1)
    //         00482031     INC        EDI
    //                              rmm_clif.cpp:321 (2)
    //         00482032     JMP        switchD_0048200c::default
    //                               switchD_0048200c::caseD_2                                    XREF[2]:     0048200c(j), 0048208c(*)  
    //                              rmm_clif.cpp:323 (23)
    //         00482034     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00482037     MOV        EAX,0x55555556
    //         0048203c     IMUL       EDX
    //         0048203e     MOV        EAX,EDX
    //         00482040     SHR        EAX,0x1f
    //         00482043     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         00482047     CMP        EBX,EDX
    //         00482049     JGE        LAB_00482078
    //                              rmm_clif.cpp:324 (1)
    //         0048204b     INC        EBX
    //                              rmm_clif.cpp:327 (2)
    //         0048204c     JMP        switchD_0048200c::default
    //                               switchD_0048200c::caseD_3                                    XREF[2]:     0048200c(j), 00482090(*)  
    //                              rmm_clif.cpp:329 (4)
    //         0048204e     TEST       EDI,EDI
    //         00482050     JLE        LAB_00482078
    //                              rmm_clif.cpp:330 (1)
    //         00482052     DEC        EDI
    //                               switchD_0048200c::default                                    XREF[4]:     0048200a(j), 00482018(j), 
    //                                                                                                         00482032(j), 0048204c(j)  
    //                              rmm_clif.cpp:336 (19)
    //         00482053     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00482056     XOR        EDX,EDX
    //         00482058     MOV        this,dword ptr [EAX + EBX*0x4]
    //         0048205b     MOV        EAX,dword ptr [ESP + param_4]
    //         0048205f     MOV        DL,byte ptr [this->_padding_ + EDI*0x1]
    //         00482062     CMP        EDX,EAX
    //         00482064     JNZ        LAB_00482078
    //                              rmm_clif.cpp:339 (9)
    //         00482066     MOV        EAX,dword ptr [ESP + param_3]
    //         0048206a     MOV        dword ptr [EBP],EDI
    //         0048206d     MOV        dword ptr [EAX],EBX
    //                              rmm_clif.cpp:340 (2)
    //         0048206f     MOV        AL,0x1
    //                              rmm_clif.cpp:344 (35)
    //         00482071     POP        EDI
    //         00482072     POP        ESI
    //         00482073     POP        EBP
    //         00482074     POP        EBX
    //         00482075     RET        0x10
    //                               LAB_00482078                                                 XREF[5]:     00482015(j), 0048202f(j), 
    //                                                                                                         00482049(j), 00482050(j), 
    //                                                                                                         00482064(j)  
    //         00482078     POP        EDI
    //         00482079     POP        ESI
    //         0048207a     POP        EBP
    //         0048207b     XOR        AL,AL
    //         0048207d     POP        EBX
    //         0048207e     RET        0x10
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00482081()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00482081
    //         00482081     NOP
    //         00482082     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048200c::switchdataD_00482084                       XREF[1]:     check_for_valid_cliff_site:0048200
    //         00482084     addr       switchD_0048200c::caseD_0
    //         00482088     addr       switchD_0048200c::caseD_1
    //         0048208c     addr       switchD_0048200c::caseD_2
    //         00482090     addr       switchD_0048200c::caseD_3
    //         00482094     ??         90h
    //         00482095     ??         90h
    //         00482096     ??         90h
    //         00482097     ??         90h
    //         00482098     ??         90h
    //         00482099     ??         90h
    //         0048209a     ??         90h
    //         0048209b     ??         90h
    //         0048209c     ??         90h
    //         0048209d     ??         90h
    //         0048209e     ??         90h
    //         0048209f     ??         90h
    return;
}

void RGE_RMM_Cliffs_Generator::invalidate_cliff_area(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
    //                              void __thiscall invalidate_cliff_area(RGE_RMM_Cliffs_Generator * thi
    //              void              <VOID>         <RETURN>
    //              RGE_RMM_Cliffs    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     004820ae(R), 004820f6(W), 00482116(W), 0048216d(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004820b2(R), 00482134(W), 0048217b(R), 00482183(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004820db(R), 004820f0(W), 004820fc(W), 00482104(R), 
    //                                                                                     00482169(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004820df(W), 0048211c(R)  
    //              long              Stack[-0x8]:4  cliff_height2             XREF[2]:     004820c9(W), 0048210e(R)  
    //              long              Stack[-0xc]:4  cliff_width2
    //                               ?invalidate_cliff_area@RGE_RMM_Cliffs_Generator@@IAEXJJJ@Z   XREF[3]:     setup_cliff_maps:00481b78(c), 
    //                               RGE_RMM_Cliffs_Generator::invalidate_cliff_area                           setup_cliff_maps:00481c15(c), 
    //                                                                                                         generate_cliff:00481fa6(c)  
    //                              rmm_clif.cpp:348 (9)
    //         004820a0     SUB        ESP,0x8
    //         004820a3     PUSH       EBX
    //         004820a4     PUSH       EBP
    //         004820a5     PUSH       ESI
    //         004820a6     PUSH       EDI
    //         004820a7     MOV        EDI,this
    //                              rmm_clif.cpp:349 (5)
    //         004820a9     MOV        EAX,0x55555556
    //                              rmm_clif.cpp:358 (4)
    //         004820ae     MOV        ESI,dword ptr [ESP + param_1]
    //                              rmm_clif.cpp:359 (57)
    //         004820b2     MOV        EBP,dword ptr [ESP + param_2]
    //         004820b6     MOV        this,dword ptr [EDI + 0x14]
    //         004820b9     IMUL       this
    //         004820bb     MOV        EAX,EDX
    //         004820bd     SHR        EAX,0x1f
    //         004820c0     LEA        this,[EDX + EAX*0x1 + -0x1]
    //         004820c4     MOV        EAX,0x55555556
    //         004820c9     MOV        dword ptr [ESP + cliff_height2],this
    //         004820cd     MOV        this,dword ptr [EDI + 0x18]
    //         004820d0     IMUL       this
    //         004820d2     MOV        EAX,EDX
    //         004820d4     SHR        EAX,0x1f
    //         004820d7     LEA        this,[EDX + EAX*0x1 + -0x1]
    //         004820db     MOV        EAX,dword ptr [ESP + param_3]
    //         004820df     MOV        dword ptr [ESP + local_4],this
    //         004820e3     MOV        this,ESI
    //         004820e5     MOV        EDX,EBP
    //         004820e7     SUB        this,EAX
    //         004820e9     SUB        EDX,EAX
    //                              rmm_clif.cpp:360 (3)
    //         004820eb     LEA        EBX,[EAX + ESI*0x1]
    //                              rmm_clif.cpp:361 (6)
    //         004820ee     ADD        EAX,EBP
    //         004820f0     MOV        dword ptr [ESP + param_3],this
    //                              rmm_clif.cpp:363 (20)
    //         004820f4     TEST       this,this
    //         004820f6     MOV        dword ptr [ESP + param_1],EBX
    //         004820fa     JGE        LAB_00482108
    //         004820fc     MOV        dword ptr [ESP + param_3],0x0
    //         00482104     MOV        this,dword ptr [ESP + param_3]
    //                               LAB_00482108                                                 XREF[1]:     004820fa(j)  
    //                              rmm_clif.cpp:364 (6)
    //         00482108     TEST       EDX,EDX
    //         0048210a     JGE        LAB_0048210e
    //         0048210c     XOR        EDX,EDX
    //                               LAB_0048210e                                                 XREF[1]:     0048210a(j)  
    //                              rmm_clif.cpp:365 (14)
    //         0048210e     MOV        ESI,dword ptr [ESP + cliff_height2]
    //         00482112     CMP        EBX,ESI
    //         00482114     JLE        LAB_0048211c
    //         00482116     MOV        dword ptr [ESP + param_1],ESI
    //         0048211a     MOV        EBX,ESI
    //                               LAB_0048211c                                                 XREF[1]:     00482114(j)  
    //                              rmm_clif.cpp:366 (10)
    //         0048211c     MOV        ESI,dword ptr [ESP + local_4]
    //         00482120     CMP        EBX,ESI
    //         00482122     JLE        LAB_00482126
    //         00482124     MOV        EAX,ESI
    //                               LAB_00482126                                                 XREF[1]:     00482122(j)  
    //                              rmm_clif.cpp:368 (18)
    //         00482126     CMP        EDX,EAX
    //         00482128     JG         LAB_00482189
    //         0048212a     SUB        EAX,EDX
    //         0048212c     LEA        EBP,[EDX*0x4 + 0x0]
    //         00482133     INC        EAX
    //         00482134     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_00482138                                                 XREF[1]:     00482187(j)  
    //                              rmm_clif.cpp:369 (12)
    //         00482138     CMP        this,EBX
    //         0048213a     MOV        ESI,this
    //         0048213c     JG         LAB_0048217b
    //         0048213e     LEA        EBX,[ECX + ECX*0x2]
    //         00482141     SHL        EBX,0x3
    //                               LAB_00482144                                                 XREF[1]:     00482177(j)  
    //                              rmm_clif.cpp:370 (15)
    //         00482144     MOV        EDX,dword ptr [EDI + 0x24]
    //         00482147     LEA        EAX,[EDX + EBP*0x1]
    //         0048214a     MOV        EDX,dword ptr [EDX + EBP*0x1]
    //         0048214d     CMP        byte ptr [ESI + EDX*0x1],0x0
    //         00482151     JZ         LAB_0048216d
    //                              rmm_clif.cpp:372 (6)
    //         00482153     MOV        EAX,EDX
    //         00482155     MOV        byte ptr [ESI + EAX*0x1],0x0
    //                              rmm_clif.cpp:373 (32)
    //         00482159     MOV        this,dword ptr [EDI + 0x2c]
    //         0048215c     MOV        EDX,dword ptr [this->_padding_ + EBP*0x1]
    //         0048215f     MOV        this,EDI
    //         00482161     ADD        EDX,EBX
    //         00482163     PUSH       EDX
    //         00482164     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module 
    //         00482169     MOV        this,dword ptr [ESP + param_3]
    //                               LAB_0048216d                                                 XREF[1]:     00482151(j)  
    //         0048216d     MOV        EAX,dword ptr [ESP + param_1]
    //         00482171     INC        ESI
    //         00482172     ADD        EBX,0x18
    //         00482175     CMP        ESI,EAX
    //         00482177     JLE        LAB_00482144
    //                              rmm_clif.cpp:369 (2)
    //         00482179     MOV        EBX,EAX
    //                               LAB_0048217b                                                 XREF[1]:     0048213c(j)  
    //                              rmm_clif.cpp:368 (14)
    //         0048217b     MOV        EAX,dword ptr [ESP + param_2]
    //         0048217f     ADD        EBP,0x4
    //         00482182     DEC        EAX
    //         00482183     MOV        dword ptr [ESP + param_2],EAX
    //         00482187     JNZ        LAB_00482138
    //                               LAB_00482189                                                 XREF[1]:     00482128(j)  
    //                              rmm_clif.cpp:375 (10)
    //         00482189     POP        EDI
    //         0048218a     POP        ESI
    //         0048218b     POP        EBP
    //         0048218c     POP        EBX
    //         0048218d     ADD        ESP,0x8
    //         00482190     RET        0xc
    //         00482193     ??         90h
    //         00482194     NOP
    //         00482195     NOP
    //         00482196     NOP
    //         00482197     NOP
    //         00482198     NOP
    //         00482199     NOP
    //         0048219a     NOP
    //         0048219b     NOP
    //         0048219c     NOP
    //         0048219d     NOP
    //         0048219e     NOP
    //         0048219f     NOP
    //                              * public: __thiscall RGE_RMM_Controller::RGE_RMM_Controller(class RGE_Map *,class RGE_Game_World *,u... *
    //                              undefined __thiscall RGE_RMM_Controller(RGE_RMM_Controller * this, R
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_RMM_Contro    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     004821bf(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00482223(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004821d8(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004821df(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004821f8(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048223a(R)  
    //              RGE_Land_Info     Stack[-0x144   land_info                 XREF[0,3]:   004821ed(*), 0048220e(*), 0048222a(*)  
    //              RGE_Terrain_In    Stack[-0x26e   terrain_info              XREF[1,1]:   004821cf(W), 00482216(*)  
    //                               ??0RGE_RMM_Controller@@QAE@PAVRGE_Map@@PAVRGE_Game_World@@E
    //                               RGE_RMM_Controller::RGE_RMM_Controller
    //                              rmm_cntr.cpp:42 (56)
    //         004821a0     MOV        EAX,FS:[0x0]
    //         004821a6     PUSH       -0x1
    //         004821a8     PUSH       FUN_0055e5db
    //         004821ad     PUSH       EAX
    //         004821ae     MOV        EAX,0x26d4
    //         004821b3     MOV        dword ptr FS:[0x0],ESP
    //         004821ba     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         004821bf     MOV        EAX,dword ptr [ESP + param_1]
    //         004821c6     PUSH       ESI
    //         004821c7     PUSH       EDI
    //         004821c8     PUSH       0x1
    //         004821ca     MOV        ESI,this
    //         004821cc     PUSH       0x0
    //         004821ce     PUSH       EAX
    //         004821cf     MOV        dword ptr [ESP + terrain_info.terrain[0].terra
    //         004821d3     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
    //                              rmm_cntr.cpp:46 (54)
    //         004821d8     MOV        EDI,dword ptr [ESP + param_3]
    //         004821df     MOV        this,dword ptr [ESP + param_4]
    //         004821e6     AND        EDI,0xff
    //         004821ec     PUSH       this
    //         004821ed     LEA        EDX=>land_info+0x4,[ESP + 0x12a8]
    //         004821f4     PUSH       EDI
    //         004821f5     PUSH       EDX
    //         004821f6     MOV        this,ESI
    //         004821f8     MOV        dword ptr [ESP + local_4],0x0
    //         00482203     MOV        dword ptr [ESI],RGE_RMM_Controller::`vftable'    = 00482260
    //         00482209     CALL       RGE_RMM_Controller::add_land_module              void add_land_module(RGE_RMM_Controller * thi
    //                              rmm_cntr.cpp:47 (21)
    //         0048220e     LEA        EAX=>land_info+0x4,[ESP + 0x12a4]
    //         00482215     PUSH       EDI
    //         00482216     LEA        this=>terrain_info+0x4,[ESP + 0x10]
    //         0048221a     PUSH       EAX
    //         0048221b     PUSH       this
    //         0048221c     MOV        this,ESI
    //         0048221e     CALL       RGE_RMM_Controller::add_terrain_module           void add_terrain_module(RGE_RMM_Controller * 
    //                              rmm_cntr.cpp:48 (23)
    //         00482223     MOV        EAX,dword ptr [ESP + param_2]
    //         0048222a     LEA        EDX=>land_info+0x4,[ESP + 0x12a4]
    //         00482231     PUSH       EDX
    //         00482232     PUSH       EAX
    //         00482233     MOV        this,ESI
    //         00482235     CALL       RGE_RMM_Controller::add_object_module            void add_object_module(RGE_RMM_Controller * t
    //                              rmm_cntr.cpp:49 (27)
    //         0048223a     MOV        this,dword ptr [ESP + local_c]
    //         00482241     MOV        EAX,ESI
    //         00482243     POP        EDI
    //         00482244     MOV        dword ptr FS:[0x0],this
    //         0048224b     POP        ESI
    //         0048224c     ADD        ESP,0x26e0
    //         00482252     RET        0x10
    //         00482255     ??         90h
    //         00482256     NOP
    //         00482257     NOP
    //         00482258     NOP
    //         00482259     NOP
    //         0048225a     NOP
    //         0048225b     NOP
    //         0048225c     NOP
    //         0048225d     NOP
    //         0048225e     NOP
    //         0048225f     NOP
    return;
}

RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Cliffs_Info param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

uchar RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(long param_1, long* param_2, long* param_3, long param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

