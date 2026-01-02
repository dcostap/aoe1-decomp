#include "../common.h"
#include "rpnl_tbx.h"

RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, TDigital* param_10, TScreenPanel* param_11, RGE_View* param_12, RGE_Diamond_Map* param_13) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Panel_Tool_Box(RGE_Panel_Tool_Box * this, T
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Panel_Tool    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0048992f(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0048992a(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00489925(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0048991f(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00489915(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0048990b(R)
//              void *            Stack[0x1c]:4  param_7                   XREF[5]:     004899fb(R), 00489a86(R), 00489b11(R), 00489b9f(R),
//                                                                                     00489c2d(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     004899f7(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     004899f3(R)
//              TDigital *        Stack[0x28]:4  param_10                  XREF[1]:     004899da(R)
//              TScreenPanel *    Stack[0x2c]:4  param_11                  XREF[6]:     004898f7(R), 004899a6(W), 00489a35(W), 00489ac0(W),
//                                                                                     00489b4b(W), 00489bd9(W)
//              RGE_View *        Stack[0x30]:4  param_12                  XREF[1]:     004898fb(R)
//              RGE_Diamond_Ma    Stack[0x34]:4  param_13                  XREF[1]:     004898ff(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[11]:    00489938(W), 004899ac(W), 004899c0(W), 00489a3b(W),
//                                                                                     00489a4f(W), 00489ac6(W), 00489ada(W), 00489b51(W),
//                                                                                     00489b65(W), 00489bdf(W), 00489bf3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00489e50(R)
//              TButtonPanel *    Stack[-0x28]   mode_buttons              XREF[1]:     004898ee(W)
//                               ??0RGE_Panel_Tool_Box@@QAE@PAVTDrawArea@@PAVTPanel@@JJJJPAX  XREF[1]:     TRIBE_Screen_Game:004951f2(c)
//                               RGE_Panel_Tool_Box::RGE_Panel_Tool_Box
//                              rpnl_tbx.cpp:39 (39)
//         004898d0     PUSH       -0x1
//         004898d2     PUSH       FUN_0055e745
//         004898d7     MOV        EAX,FS:[0x0]
//         004898dd     PUSH       EAX
//         004898de     MOV        dword ptr FS:[0x0],ESP
//         004898e5     SUB        ESP,0x1c
//         004898e8     PUSH       EBX
//         004898e9     PUSH       EBP
//         004898ea     PUSH       ESI
//         004898eb     MOV        ESI,this
//         004898ed     PUSH       EDI
//         004898ee     MOV        dword ptr [ESP + mode_buttons[0]],ESI
//         004898f2     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
//                              rpnl_tbx.cpp:40 (4)
//         004898f7     MOV        EAX,dword ptr [ESP + param_11]
//                              rpnl_tbx.cpp:41 (4)
//         004898fb     MOV        this,dword ptr [ESP + param_12]
//                              rpnl_tbx.cpp:42 (12)
//         004898ff     MOV        EDX,dword ptr [ESP + param_13]
//         00489903     XOR        EBX,EBX
//         00489905     MOV        dword ptr [ESI + 0xf4],EAX
//                              rpnl_tbx.cpp:55 (110)
//         0048990b     MOV        EAX,dword ptr [ESP + param_6]
//         0048990f     MOV        dword ptr [ESI + 0xf8],this
//         00489915     MOV        this,dword ptr [ESP + param_5]
//         00489919     MOV        dword ptr [ESI + 0xfc],EDX
//         0048991f     MOV        EDX,dword ptr [ESP + param_4]
//         00489923     PUSH       EBX
//         00489924     PUSH       EAX
//         00489925     MOV        EAX,dword ptr [ESP + param_3]
//         00489929     PUSH       this
//         0048992a     MOV        this,dword ptr [ESP + param_2]
//         0048992e     PUSH       EDX
//         0048992f     MOV        EDX,dword ptr [ESP + param_1]
//         00489933     PUSH       EAX
//         00489934     PUSH       this
//         00489935     PUSH       EDX
//         00489936     MOV        this,ESI
//         00489938     MOV        dword ptr [ESP + local_4],EBX
//         0048993c     MOV        dword ptr [ESI],RGE_Panel_Tool_Box::`vftable'    = 00489e70
//         00489942     MOV        dword ptr [ESI + 0x100],EBX
//         00489948     MOV        dword ptr [ESI + 0x104],EBX
//         0048994e     MOV        dword ptr [ESI + 0x108],EBX
//         00489954     MOV        dword ptr [ESI + 0x10c],EBX
//         0048995a     MOV        dword ptr [ESI + 0x110],EBX
//         00489960     MOV        dword ptr [ESI + 0x114],EBX
//         00489966     MOV        dword ptr [ESI + 0x118],EBX
//         0048996c     MOV        dword ptr [ESI + 0x11c],EBX
//         00489972     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
//         00489977     TEST       EAX,EAX
//                              rpnl_tbx.cpp:56 (13)
//         00489979     MOV        EDI,0x1
//         0048997e     JNZ        LAB_00489986
//         00489980     MOV        dword ptr [ESI + 0xd8],EDI
//                               LAB_00489986                                                 XREF[1]:     0048997e(j)
//                              rpnl_tbx.cpp:58 (8)
//         00489986     CMP        dword ptr [ESI + 0xf8],EBX
//         0048998c     JNZ        LAB_00489999
//                              rpnl_tbx.cpp:60 (6)
//         0048998e     MOV        dword ptr [ESI + 0xd8],EDI
//                              rpnl_tbx.cpp:61 (5)
//         00489994     JMP        LAB_00489e50
//                               LAB_00489999                                                 XREF[1]:     0048998c(j)
//                              rpnl_tbx.cpp:65 (37)
//         00489999     PUSH       0x2b8
//         0048999e     CALL       operator_new                                     void * operator_new(uint param_1)
//         004899a3     ADD        ESP,0x4
//         004899a6     MOV        dword ptr [ESP + param_11],EAX
//         004899aa     CMP        EAX,EBX
//         004899ac     MOV        byte ptr [ESP + local_4],0x1
//         004899b1     JZ         LAB_004899bc
//         004899b3     MOV        this,EAX
//         004899b5     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         004899ba     JMP        LAB_004899be
//                               LAB_004899bc                                                 XREF[1]:     004899b1(j)
//         004899bc     XOR        EAX,EAX
//                               LAB_004899be                                                 XREF[1]:     004899ba(j)
//                              rpnl_tbx.cpp:66 (15)
//         004899be     CMP        EAX,EBX
//         004899c0     MOV        byte ptr [ESP + local_4],0x0
//         004899c5     MOV        dword ptr [ESI + 0x100],EAX
//         004899cb     JNZ        LAB_004899d8
//                              rpnl_tbx.cpp:68 (6)
//         004899cd     MOV        dword ptr [ESI + 0xd8],EDI
//                              rpnl_tbx.cpp:69 (5)
//         004899d3     JMP        LAB_00489e50
//                               LAB_004899d8                                                 XREF[1]:     004899cb(j)
//                              rpnl_tbx.cpp:71 (27)
//         004899d8     PUSH       EBX
//         004899d9     PUSH       EDI
//         004899da     MOV        EDI,dword ptr [ESP + param_10]
//         004899de     MOV        this,dword ptr [ESI + 0x20]
//         004899e1     PUSH       EDI
//         004899e2     PUSH       0x3
//         004899e4     PUSH       0x1e
//         004899e6     PUSH       0x32
//         004899e8     PUSH       EBX
//         004899e9     PUSH       EBX
//         004899ea     PUSH       ESI
//         004899eb     PUSH       this
//         004899ec     MOV        this,EAX
//         004899ee     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:72 (35)
//         004899f3     MOV        EBP,dword ptr [ESP + param_9]
//         004899f7     MOV        EBX,dword ptr [ESP + param_8]
//         004899fb     MOV        EDX,dword ptr [ESP + param_7]
//         004899ff     MOV        this,dword ptr [ESI + 0x100]
//         00489a05     PUSH       -0x1
//         00489a07     PUSH       -0x1
//         00489a09     PUSH       EBP
//         00489a0a     PUSH       EBX
//         00489a0b     PUSH       EDX
//         00489a0c     PUSH       s_Game                                           = "Game"
//         00489a11     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:73 (18)
//         00489a16     MOV        this,dword ptr [ESI + 0x100]
//         00489a1c     PUSH       s_<Game>                                         = "<Game>"
//         00489a21     PUSH       0x1
//         00489a23     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:76 (37)
//         00489a28     PUSH       0x2b8
//         00489a2d     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489a32     ADD        ESP,0x4
//         00489a35     MOV        dword ptr [ESP + param_11],EAX
//         00489a39     TEST       EAX,EAX
//         00489a3b     MOV        byte ptr [ESP + local_4],0x2
//         00489a40     JZ         LAB_00489a4b
//         00489a42     MOV        this,EAX
//         00489a44     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         00489a49     JMP        LAB_00489a4d
//                               LAB_00489a4b                                                 XREF[1]:     00489a40(j)
//         00489a4b     XOR        EAX,EAX
//                               LAB_00489a4d                                                 XREF[1]:     00489a49(j)
//                              rpnl_tbx.cpp:77 (15)
//         00489a4d     TEST       EAX,EAX
//         00489a4f     MOV        byte ptr [ESP + local_4],0x0
//         00489a54     MOV        dword ptr [ESI + 0x104],EAX
//         00489a5a     JNZ        LAB_00489a6b
//                              rpnl_tbx.cpp:79 (10)
//         00489a5c     MOV        dword ptr [ESI + 0xd8],0x1
//                              rpnl_tbx.cpp:80 (5)
//         00489a66     JMP        LAB_00489e50
//                               LAB_00489a6b                                                 XREF[1]:     00489a5a(j)
//                              rpnl_tbx.cpp:82 (27)
//         00489a6b     MOV        this,dword ptr [ESI + 0x20]
//         00489a6e     PUSH       0x0
//         00489a70     PUSH       0x1
//         00489a72     PUSH       EDI
//         00489a73     PUSH       0x3
//         00489a75     PUSH       0x1e
//         00489a77     PUSH       0x32
//         00489a79     PUSH       0x0
//         00489a7b     PUSH       0x34
//         00489a7d     PUSH       ESI
//         00489a7e     PUSH       this
//         00489a7f     MOV        this,EAX
//         00489a81     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:83 (27)
//         00489a86     MOV        EDX,dword ptr [ESP + param_7]
//         00489a8a     MOV        this,dword ptr [ESI + 0x104]
//         00489a90     PUSH       -0x1
//         00489a92     PUSH       -0x1
//         00489a94     PUSH       EBP
//         00489a95     PUSH       EBX
//         00489a96     PUSH       EDX
//         00489a97     PUSH       s_Obj                                            = "Obj"
//         00489a9c     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:84 (18)
//         00489aa1     MOV        this,dword ptr [ESI + 0x104]
//         00489aa7     PUSH       s_<Obj>                                          = "<Obj>"
//         00489aac     PUSH       0x1
//         00489aae     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:87 (37)
//         00489ab3     PUSH       0x2b8
//         00489ab8     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489abd     ADD        ESP,0x4
//         00489ac0     MOV        dword ptr [ESP + param_11],EAX
//         00489ac4     TEST       EAX,EAX
//         00489ac6     MOV        byte ptr [ESP + local_4],0x3
//         00489acb     JZ         LAB_00489ad6
//         00489acd     MOV        this,EAX
//         00489acf     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         00489ad4     JMP        LAB_00489ad8
//                               LAB_00489ad6                                                 XREF[1]:     00489acb(j)
//         00489ad6     XOR        EAX,EAX
//                               LAB_00489ad8                                                 XREF[1]:     00489ad4(j)
//                              rpnl_tbx.cpp:88 (15)
//         00489ad8     TEST       EAX,EAX
//         00489ada     MOV        byte ptr [ESP + local_4],0x0
//         00489adf     MOV        dword ptr [ESI + 0x10c],EAX
//         00489ae5     JNZ        LAB_00489af6
//                              rpnl_tbx.cpp:90 (10)
//         00489ae7     MOV        dword ptr [ESI + 0xd8],0x1
//                              rpnl_tbx.cpp:91 (5)
//         00489af1     JMP        LAB_00489e50
//                               LAB_00489af6                                                 XREF[1]:     00489ae5(j)
//                              rpnl_tbx.cpp:93 (27)
//         00489af6     MOV        this,dword ptr [ESI + 0x20]
//         00489af9     PUSH       0x0
//         00489afb     PUSH       0x1
//         00489afd     PUSH       EDI
//         00489afe     PUSH       0x3
//         00489b00     PUSH       0x1e
//         00489b02     PUSH       0x32
//         00489b04     PUSH       0x0
//                              language.dll match for 0x68: "Arial"
//         00489b06     PUSH       0x68
//         00489b08     PUSH       ESI
//         00489b09     PUSH       this
//         00489b0a     MOV        this,EAX
//         00489b0c     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:94 (27)
//         00489b11     MOV        EDX,dword ptr [ESP + param_7]
//         00489b15     MOV        this,dword ptr [ESI + 0x10c]
//         00489b1b     PUSH       -0x1
//         00489b1d     PUSH       -0x1
//         00489b1f     PUSH       EBP
//         00489b20     PUSH       EBX
//         00489b21     PUSH       EDX
//         00489b22     PUSH       s_Move                                           = 4Dh
//         00489b27     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:95 (18)
//         00489b2c     MOV        this,dword ptr [ESI + 0x10c]
//         00489b32     PUSH       s_<Move>                                         = "<Move>"
//         00489b37     PUSH       0x1
//         00489b39     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:98 (37)
//         00489b3e     PUSH       0x2b8
//         00489b43     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489b48     ADD        ESP,0x4
//         00489b4b     MOV        dword ptr [ESP + param_11],EAX
//         00489b4f     TEST       EAX,EAX
//         00489b51     MOV        byte ptr [ESP + local_4],0x4
//         00489b56     JZ         LAB_00489b61
//         00489b58     MOV        this,EAX
//         00489b5a     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         00489b5f     JMP        LAB_00489b63
//                               LAB_00489b61                                                 XREF[1]:     00489b56(j)
//         00489b61     XOR        EAX,EAX
//                               LAB_00489b63                                                 XREF[1]:     00489b5f(j)
//                              rpnl_tbx.cpp:99 (15)
//         00489b63     TEST       EAX,EAX
//         00489b65     MOV        byte ptr [ESP + local_4],0x0
//         00489b6a     MOV        dword ptr [ESI + 0x108],EAX
//         00489b70     JNZ        LAB_00489b81
//                              rpnl_tbx.cpp:101 (10)
//         00489b72     MOV        dword ptr [ESI + 0xd8],0x1
//                              rpnl_tbx.cpp:102 (5)
//         00489b7c     JMP        LAB_00489e50
//                               LAB_00489b81                                                 XREF[1]:     00489b70(j)
//                              rpnl_tbx.cpp:104 (30)
//         00489b81     MOV        this,dword ptr [ESI + 0x20]
//         00489b84     PUSH       0x0
//         00489b86     PUSH       0x1
//         00489b88     PUSH       EDI
//         00489b89     PUSH       0x3
//         00489b8b     PUSH       0x1e
//         00489b8d     PUSH       0x32
//         00489b8f     PUSH       0x0
//         00489b91     PUSH       0x9c
//         00489b96     PUSH       ESI
//         00489b97     PUSH       this
//         00489b98     MOV        this,EAX
//         00489b9a     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:105 (27)
//         00489b9f     MOV        EDX,dword ptr [ESP + param_7]
//         00489ba3     MOV        this,dword ptr [ESI + 0x108]
//         00489ba9     PUSH       -0x1
//         00489bab     PUSH       -0x1
//         00489bad     PUSH       EBP
//         00489bae     PUSH       EBX
//         00489baf     PUSH       EDX
//         00489bb0     PUSH       s_Del                                            = "Del"
//         00489bb5     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:106 (18)
//         00489bba     MOV        this,dword ptr [ESI + 0x108]
//         00489bc0     PUSH       s_<Del>                                          = "<Del>"
//         00489bc5     PUSH       0x1
//         00489bc7     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:109 (37)
//         00489bcc     PUSH       0x2b8
//         00489bd1     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489bd6     ADD        ESP,0x4
//         00489bd9     MOV        dword ptr [ESP + param_11],EAX
//         00489bdd     TEST       EAX,EAX
//         00489bdf     MOV        byte ptr [ESP + local_4],0x5
//         00489be4     JZ         LAB_00489bef
//         00489be6     MOV        this,EAX
//         00489be8     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         00489bed     JMP        LAB_00489bf1
//                               LAB_00489bef                                                 XREF[1]:     00489be4(j)
//         00489bef     XOR        EAX,EAX
//                               LAB_00489bf1                                                 XREF[1]:     00489bed(j)
//                              rpnl_tbx.cpp:110 (15)
//         00489bf1     TEST       EAX,EAX
//         00489bf3     MOV        byte ptr [ESP + local_4],0x0
//         00489bf8     MOV        dword ptr [ESI + 0x110],EAX
//         00489bfe     JNZ        LAB_00489c0f
//                              rpnl_tbx.cpp:112 (10)
//         00489c00     MOV        dword ptr [ESI + 0xd8],0x1
//                              rpnl_tbx.cpp:113 (5)
//         00489c0a     JMP        LAB_00489e50
//                               LAB_00489c0f                                                 XREF[1]:     00489bfe(j)
//                              rpnl_tbx.cpp:115 (30)
//         00489c0f     MOV        this,dword ptr [ESI + 0x20]
//         00489c12     PUSH       0x0
//         00489c14     PUSH       0x1
//         00489c16     PUSH       EDI
//         00489c17     PUSH       0x3
//         00489c19     PUSH       0x1e
//         00489c1b     PUSH       0x32
//         00489c1d     PUSH       0x0
//         00489c1f     PUSH       0xd0
//         00489c24     PUSH       ESI
//         00489c25     PUSH       this
//         00489c26     MOV        this,EAX
//         00489c28     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:116 (27)
//         00489c2d     MOV        EDX,dword ptr [ESP + param_7]
//         00489c31     MOV        this,dword ptr [ESI + 0x110]
//         00489c37     PUSH       -0x1
//         00489c39     PUSH       -0x1
//         00489c3b     PUSH       EBP
//         00489c3c     PUSH       EBX
//         00489c3d     PUSH       EDX
//         00489c3e     PUSH       s_Terr                                           = "Terr"
//         00489c43     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:117 (18)
//         00489c48     MOV        this,dword ptr [ESI + 0x110]
//         00489c4e     PUSH       s_<Terr>                                         = "<Terr>"
//         00489c53     PUSH       0x1
//         00489c55     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:118 (13)
//         00489c5a     MOV        this,dword ptr [ESI + 0x110]
//         00489c60     PUSH       0x0
//         00489c62     MOV        EAX,dword ptr [this->_padding_]
//         00489c64     CALL       dword ptr [EAX + 0x14]
//                              rpnl_tbx.cpp:121 (37)
//         00489c67     PUSH       0x2b8
//         00489c6c     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489c71     ADD        ESP,0x4
//         00489c74     MOV        dword ptr [ESP + 0x64],EAX
//         00489c78     TEST       EAX,EAX
//         00489c7a     MOV        byte ptr [ESP + 0x34],0x6
//         00489c7f     JZ         LAB_00489c8a
//         00489c81     MOV        this,EAX
//         00489c83     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         00489c88     JMP        LAB_00489c8c
//                               LAB_00489c8a                                                 XREF[1]:     00489c7f(j)
//         00489c8a     XOR        EAX,EAX
//                               LAB_00489c8c                                                 XREF[1]:     00489c88(j)
//                              rpnl_tbx.cpp:122 (15)
//         00489c8c     TEST       EAX,EAX
//         00489c8e     MOV        byte ptr [ESP + 0x34],0x0
//         00489c93     MOV        dword ptr [ESI + 0x114],EAX
//         00489c99     JNZ        LAB_00489caa
//                              rpnl_tbx.cpp:124 (10)
//         00489c9b     MOV        dword ptr [ESI + 0xd8],0x1
//                              rpnl_tbx.cpp:125 (5)
//         00489ca5     JMP        LAB_00489e50
//                               LAB_00489caa                                                 XREF[1]:     00489c99(j)
//                              rpnl_tbx.cpp:127 (30)
//         00489caa     MOV        this,dword ptr [ESI + 0x20]
//         00489cad     PUSH       0x0
//         00489caf     PUSH       offset DAT_fffffff8
//         00489cb1     PUSH       EDI=>DAT_fffffff4
//         00489cb2     PUSH       offset DAT_fffffff0
//         00489cb4     PUSH       0x1e
//         00489cb6     PUSH       0x32
//         00489cb8     PUSH       0x0
//         00489cba     PUSH       0x104
//         00489cbf     PUSH       ESI
//         00489cc0     PUSH       this
//         00489cc1     MOV        this,EAX
//         00489cc3     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:128 (27)
//         00489cc8     MOV        EDX,dword ptr [ESP + 0x54]
//         00489ccc     MOV        this,dword ptr [ESI + 0x114]
//         00489cd2     PUSH       -0x1
//         00489cd4     PUSH       offset DAT_fffffff8
//         00489cd6     PUSH       EBP=>DAT_fffffff4
//         00489cd7     PUSH       EBX=>DAT_fffffff0
//         00489cd8     PUSH       EDX
//         00489cd9     PUSH       s_Elev                                           = "Elev"
//         00489cde     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:129 (18)
//         00489ce3     MOV        this,dword ptr [ESI + 0x114]
//         00489ce9     PUSH       s_<Elev>                                         = "<Elev>"
//         00489cee     PUSH       offset DAT_fffffff8
//         00489cf0     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:130 (13)
//         00489cf5     MOV        this,dword ptr [ESI + 0x114]
//         00489cfb     PUSH       0x0
//         00489cfd     MOV        EAX,dword ptr [this->_padding_]
//         00489cff     CALL       dword ptr [EAX + 0x14]
//                              rpnl_tbx.cpp:136 (22)
//         00489d02     MOV        EAX,dword ptr [ESI + 0x10c]
//         00489d08     MOV        EDX,dword ptr [ESI + 0x104]
//         00489d0e     MOV        this,dword ptr [ESI + 0x100]
//         00489d14     MOV        dword ptr [ESP + 0x1c],EAX
//                              rpnl_tbx.cpp:138 (24)
//         00489d18     MOV        EAX,dword ptr [ESI + 0x110]
//         00489d1e     MOV        dword ptr [ESP + 0x18],EDX
//         00489d22     MOV        EDX,dword ptr [ESI + 0x108]
//         00489d28     MOV        dword ptr [ESP + 0x24],EAX
//         00489d2c     MOV        dword ptr [ESP + 0x20],EDX
//                              rpnl_tbx.cpp:139 (6)
//         00489d30     MOV        EDX,dword ptr [ESI + 0x114]
//                              rpnl_tbx.cpp:140 (20)
//         00489d36     LEA        EAX,[ESP + 0x14]
//         00489d3a     PUSH       0x6
//         00489d3c     PUSH       EAX=>DAT_fffffff8
//         00489d3d     MOV        dword ptr [ESP + 0x1c],this
//         00489d41     MOV        dword ptr [ESP + 0x30],EDX
//         00489d45     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              rpnl_tbx.cpp:141 (18)
//         00489d4a     LEA        this,[ESP + 0x14]
//         00489d4e     PUSH       0x6
//         00489d50     PUSH       this=>DAT_fffffff8
//         00489d51     MOV        this,dword ptr [ESI + 0x104]
//         00489d57     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              rpnl_tbx.cpp:142 (18)
//         00489d5c     MOV        this,dword ptr [ESI + 0x10c]
//         00489d62     LEA        EDX,[ESP + 0x14]
//         00489d66     PUSH       0x6
//         00489d68     PUSH       EDX=>DAT_fffffff8
//         00489d69     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              rpnl_tbx.cpp:143 (18)
//         00489d6e     MOV        this,dword ptr [ESI + 0x108]
//         00489d74     LEA        EAX,[ESP + 0x14]
//         00489d78     PUSH       0x6
//         00489d7a     PUSH       EAX=>DAT_fffffff8
//         00489d7b     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              rpnl_tbx.cpp:144 (18)
//         00489d80     LEA        this,[ESP + 0x14]
//         00489d84     PUSH       0x6
//         00489d86     PUSH       this=>DAT_fffffff8
//         00489d87     MOV        this,dword ptr [ESI + 0x110]
//         00489d8d     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              rpnl_tbx.cpp:145 (18)
//         00489d92     MOV        this,dword ptr [ESI + 0x114]
//         00489d98     LEA        EDX,[ESP + 0x14]
//         00489d9c     PUSH       0x6
//         00489d9e     PUSH       EDX=>DAT_fffffff8
//         00489d9f     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//                              rpnl_tbx.cpp:148 (37)
//         00489da4     PUSH       0x2b8
//         00489da9     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489dae     ADD        ESP,0x4
//         00489db1     MOV        dword ptr [ESP + 0x64],EAX
//         00489db5     TEST       EAX,EAX
//         00489db7     MOV        byte ptr [ESP + 0x34],0x7
//         00489dbc     JZ         LAB_00489dc7
//         00489dbe     MOV        this,EAX
//         00489dc0     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//         00489dc5     JMP        LAB_00489dc9
//                               LAB_00489dc7                                                 XREF[1]:     00489dbc(j)
//         00489dc7     XOR        EAX,EAX
//                               LAB_00489dc9                                                 XREF[1]:     00489dc5(j)
//                              rpnl_tbx.cpp:149 (15)
//         00489dc9     TEST       EAX,EAX
//         00489dcb     MOV        byte ptr [ESP + 0x34],0x0
//         00489dd0     MOV        dword ptr [ESI + 0x118],EAX
//         00489dd6     JNZ        LAB_00489de4
//                              rpnl_tbx.cpp:151 (10)
//         00489dd8     MOV        dword ptr [ESI + 0xd8],0x1
//                              rpnl_tbx.cpp:152 (2)
//         00489de2     JMP        LAB_00489e50
//                               LAB_00489de4                                                 XREF[1]:     00489dd6(j)
//                              rpnl_tbx.cpp:154 (30)
//         00489de4     MOV        this,dword ptr [ESI + 0x20]
//         00489de7     PUSH       0x0
//         00489de9     PUSH       offset DAT_fffffff8
//         00489deb     PUSH       EDI=>DAT_fffffff4
//         00489dec     PUSH       offset DAT_fffffff0
//         00489dee     PUSH       0x1e
//         00489df0     PUSH       0x32
//         00489df2     PUSH       0x0
//         00489df4     PUSH       0x13a
//         00489df9     PUSH       ESI
//         00489dfa     PUSH       this
//         00489dfb     MOV        this,EAX
//         00489dfd     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//                              rpnl_tbx.cpp:155 (27)
//         00489e02     MOV        EDX,dword ptr [ESP + 0x54]
//         00489e06     MOV        this,dword ptr [ESI + 0x118]
//         00489e0c     PUSH       -0x1
//         00489e0e     PUSH       offset DAT_fffffff8
//         00489e10     PUSH       EBP=>DAT_fffffff4
//         00489e11     PUSH       EBX=>DAT_fffffff0
//         00489e12     PUSH       EDX
//         00489e13     PUSH       s_Cmd                                            = "Cmd"
//         00489e18     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char
//                              rpnl_tbx.cpp:156 (18)
//         00489e1d     MOV        this,dword ptr [ESI + 0x118]
//         00489e23     PUSH       s_<Cmd>                                          = "<Cmd>"
//         00489e28     PUSH       offset DAT_fffffff8
//         00489e2a     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              rpnl_tbx.cpp:157 (13)
//         00489e2f     MOV        this,dword ptr [ESI + 0x118]
//         00489e35     PUSH       0x2
//         00489e37     CALL       TButtonPanel::set_state_info                     void set_state_info(TButtonPanel * this, shor
//                              rpnl_tbx.cpp:160 (20)
//         00489e3c     MOV        EAX,[rge_base_game]                              = 00000000
//         00489e41     MOV        this,ESI
//         00489e43     MOV        EAX,dword ptr [EAX + 0x1b4]
//         00489e49     PUSH       EAX
//         00489e4a     PUSH       EAX=>DAT_fffffff8
//         00489e4b     CALL       RGE_Panel_Tool_Box::game_mode_changed            void game_mode_changed(RGE_Panel_Tool_Box * t
//                               LAB_00489e50                                                 XREF[8]:     00489994(j), 004899d3(j),
//                                                                                                         00489a66(j), 00489af1(j),
//                                                                                                         00489b7c(j), 00489c0a(j),
//                                                                                                         00489ca5(j), 00489de2(j)
//                              rpnl_tbx.cpp:161 (23)
//         00489e50     MOV        this,dword ptr [ESP + local_c]
//         00489e54     MOV        EAX,ESI
//         00489e56     POP        EDI
//         00489e57     POP        ESI
//         00489e58     POP        EBP
//         00489e59     MOV        dword ptr FS:[0x0],this
//         00489e60     POP        EBX
//         00489e61     ADD        ESP,0x28
//         00489e64     RET        0x34
//         00489e67     ??         90h
//         00489e68     NOP
//         00489e69     NOP
//         00489e6a     NOP
//         00489e6b     NOP
//         00489e6c     NOP
//         00489e6d     NOP
//         00489e6e     NOP
//         00489e6f     NOP
}

RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Panel_Tool_Box(RGE_Panel_Tool_Box * this)
//              void              <VOID>         <RETURN>
//              RGE_Panel_Tool    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00489eb9(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00489ea9(W)
//                               ??1RGE_Panel_Tool_Box@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':00489
//                               RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box
//                              rpnl_tbx.cpp:166 (35)
//         00489e90     PUSH       -0x1
//         00489e92     PUSH       FUN_0055e758
//         00489e97     MOV        EAX,FS:[0x0]
//         00489e9d     PUSH       EAX
//         00489e9e     MOV        dword ptr FS:[0x0],ESP
//         00489ea5     PUSH       this
//         00489ea6     PUSH       ESI
//         00489ea7     MOV        ESI,this
//         00489ea9     MOV        dword ptr [ESP + local_10],ESI
//         00489ead     MOV        dword ptr [ESI],RGE_Panel_Tool_Box::`vftable'    = 00489e70
//                              rpnl_tbx.cpp:167 (24)
//         00489eb3     MOV        this,dword ptr [ESI + 0x100]
//         00489eb9     MOV        dword ptr [ESP + local_4],0x0
//         00489ec1     TEST       this,this
//         00489ec3     JZ         LAB_00489ecb
//         00489ec5     MOV        EAX,dword ptr [this->_padding_]
//         00489ec7     PUSH       0x1
//         00489ec9     CALL       dword ptr [EAX]
//                               LAB_00489ecb                                                 XREF[1]:     00489ec3(j)
//                              rpnl_tbx.cpp:168 (16)
//         00489ecb     MOV        this,dword ptr [ESI + 0x104]
//         00489ed1     TEST       this,this
//         00489ed3     JZ         LAB_00489edb
//         00489ed5     MOV        EDX,dword ptr [this->_padding_]
//         00489ed7     PUSH       0x1
//         00489ed9     CALL       dword ptr [EDX]
//                               LAB_00489edb                                                 XREF[1]:     00489ed3(j)
//                              rpnl_tbx.cpp:169 (16)
//         00489edb     MOV        this,dword ptr [ESI + 0x10c]
//         00489ee1     TEST       this,this
//         00489ee3     JZ         LAB_00489eeb
//         00489ee5     MOV        EAX,dword ptr [this->_padding_]
//         00489ee7     PUSH       0x1
//         00489ee9     CALL       dword ptr [EAX]
//                               LAB_00489eeb                                                 XREF[1]:     00489ee3(j)
//                              rpnl_tbx.cpp:170 (16)
//         00489eeb     MOV        this,dword ptr [ESI + 0x108]
//         00489ef1     TEST       this,this
//         00489ef3     JZ         LAB_00489efb
//         00489ef5     MOV        EDX,dword ptr [this->_padding_]
//         00489ef7     PUSH       0x1
//         00489ef9     CALL       dword ptr [EDX]
//                               LAB_00489efb                                                 XREF[1]:     00489ef3(j)
//                              rpnl_tbx.cpp:171 (16)
//         00489efb     MOV        this,dword ptr [ESI + 0x110]
//         00489f01     TEST       this,this
//         00489f03     JZ         LAB_00489f0b
//         00489f05     MOV        EAX,dword ptr [this->_padding_]
//         00489f07     PUSH       0x1
//         00489f09     CALL       dword ptr [EAX]
//                               LAB_00489f0b                                                 XREF[1]:     00489f03(j)
//                              rpnl_tbx.cpp:172 (16)
//         00489f0b     MOV        this,dword ptr [ESI + 0x114]
//         00489f11     TEST       this,this
//         00489f13     JZ         LAB_00489f1b
//         00489f15     MOV        EDX,dword ptr [this->_padding_]
//         00489f17     PUSH       0x1
//         00489f19     CALL       dword ptr [EDX]
//                               LAB_00489f1b                                                 XREF[1]:     00489f13(j)
//                              rpnl_tbx.cpp:173 (18)
//         00489f1b     MOV        this,dword ptr [ESI + 0x118]
//         00489f21     TEST       this,this
//         00489f23     JZ         LAB_00489f2b
//         00489f25     MOV        EAX,dword ptr [this->_padding_]
//         00489f27     PUSH       0x1
//         00489f29     CALL       dword ptr [EAX]
//                               LAB_00489f2b                                                 XREF[1]:     00489f23(j)
//         00489f2b     MOV        this,ESI
//                              rpnl_tbx.cpp:174 (29)
//         00489f2d     MOV        dword ptr [ESP + 0x10],0xffffffff
//         00489f35     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
//         00489f3a     MOV        this,dword ptr [ESP + 0x8]
//         00489f3e     POP        ESI
//         00489f3f     MOV        dword ptr FS:[0x0],this
//         00489f46     ADD        ESP,0x10
//         00489f49     RET
//         00489f4a     ??         90h
//         00489f4b     NOP
//         00489f4c     NOP
//         00489f4d     NOP
//         00489f4e     NOP
//         00489f4f     NOP
}

long RGE_Panel_Tool_Box::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(RGE_Panel_Tool_Box * this, TPanel * param_1,
//              long              EAX:4          <RETURN>
//              RGE_Panel_Tool    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00489f5e(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     00489f7e(R), 00489fd3(W), 0048a1d2(R), 0048a275(R)
//              ulong             Stack[0xc]:4   param_3
//              ulong             Stack[0x10]:4  param_4
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00489fd9(W), 00489ff5(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0048a069(R), 0048a2f3(R), 0048a307(R)
//                               ?action@RGE_Panel_Tool_Box@@UAEJPAVTPanel@@JKK@Z             XREF[1]:     00572014(*)
//                               RGE_Panel_Tool_Box::action
//                              rpnl_tbx.cpp:180 (14)
//         00489f50     MOV        EAX,FS:[0x0]
//         00489f56     PUSH       -0x1
//         00489f58     PUSH       FUN_0055e77b
//         00489f5d     PUSH       EAX
//                              rpnl_tbx.cpp:181 (18)
//         00489f5e     MOV        EAX,dword ptr [ESP + param_1]
//         00489f62     MOV        dword ptr FS:[0x0],ESP
//         00489f69     PUSH       EBP
//         00489f6a     PUSH       ESI
//         00489f6b     TEST       EAX,EAX
//         00489f6d     PUSH       EDI
//         00489f6e     MOV        EBP,this
//                              rpnl_tbx.cpp:182 (6)
//         00489f70     JZ         LAB_0048a307
//                              rpnl_tbx.cpp:187 (19)
//         00489f76     MOV        this,dword ptr [EBP + 0x100]
//         00489f7c     CMP        EAX,this
//         00489f7e     MOV        this,dword ptr [ESP + param_2]
//         00489f82     JNZ        LAB_00489fb1
//         00489f84     CMP        this,0x1
//         00489f87     JNZ        LAB_00489fb1
//                              rpnl_tbx.cpp:189 (15)
//         00489f89     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00489f8f     PUSH       0x0
//         00489f91     PUSH       0x0
//         00489f93     MOV        EAX,dword ptr [this->_padding_]
//         00489f95     CALL       dword ptr [EAX + 0x10]
//                              rpnl_tbx.cpp:190 (5)
//         00489f98     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         00489f9d     MOV        this,dword ptr [ESP + 0xc]
//         00489fa1     MOV        dword ptr FS:[0x0],this
//         00489fa8     POP        EDI
//         00489fa9     POP        ESI
//         00489faa     POP        EBP
//         00489fab     ADD        ESP,0xc
//         00489fae     RET        0x10
//                               LAB_00489fb1                                                 XREF[2]:     00489f82(j), 00489f87(j)
//                              rpnl_tbx.cpp:196 (21)
//         00489fb1     CMP        EAX,dword ptr [EBP + 0x104]
//         00489fb7     JNZ        LAB_0048a07d
//         00489fbd     CMP        this,0x1
//         00489fc0     JNZ        LAB_0048a07d
//                              language.dll match for 0x4bc: "Intentional drop of Ser#%d  Cm
//                              rpnl_tbx.cpp:198 (45)
//         00489fc6     PUSH       0x4bc
//         00489fcb     CALL       operator_new                                     void * operator_new(uint param_1)
//         00489fd0     ADD        ESP,0x4
//         00489fd3     MOV        dword ptr [ESP + param_2],EAX
//         00489fd7     TEST       EAX,EAX
//         00489fd9     MOV        dword ptr [ESP + local_4],0x0
//         00489fe1     JZ         LAB_00489ff1
//         00489fe3     PUSH       s_Object_List_Dialog                             = 4Fh
//         00489fe8     MOV        this,EAX
//         00489fea     CALL       RGE_Dialog_List::RGE_Dialog_List                 undefined RGE_Dialog_List(RGE_Dialog_List * t
//         00489fef     JMP        LAB_00489ff3
//                               LAB_00489ff1                                                 XREF[1]:     00489fe1(j)
//         00489ff1     XOR        EAX,EAX
//                               LAB_00489ff3                                                 XREF[1]:     00489fef(j)
//                              rpnl_tbx.cpp:199 (87)
//         00489ff3     TEST       EAX,EAX
//         00489ff5     MOV        dword ptr [ESP + local_4],0xffffffff
//         00489ffd     MOV        dword ptr [EBP + 0x11c],EAX
//         0048a003     JZ         LAB_0048a2ee
//                              language.dll match for 0x232a: "Select Object"
//         0048a009     PUSH       0x232a
//         0048a00e     MOV        this,EBP
//         0048a010     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0048a015     MOV        this,dword ptr [EBP + 0xf4]
//         0048a01b     PUSH       EAX
//         0048a01c     PUSH       0x1
//         0048a01e     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
//         0048a023     MOV        this,dword ptr [EBP + 0xf4]
//         0048a029     PUSH       EAX
//         0048a02a     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
//         0048a02f     MOV        this,dword ptr [EBP + 0xf4]
//         0048a035     PUSH       EAX
//         0048a036     PUSH       this
//         0048a037     MOV        this,dword ptr [EBP + 0x11c]
//         0048a03d     CALL       RGE_Dialog_List::setup                           int setup(RGE_Dialog_List * this, TScreenPane
//         0048a042     TEST       EAX,EAX
//         0048a044     JNZ        LAB_0048a2ee
//                              rpnl_tbx.cpp:201 (16)
//         0048a04a     MOV        this,dword ptr [EBP + 0x11c]
//         0048a050     TEST       this,this
//         0048a052     JZ         LAB_0048a05a
//         0048a054     MOV        EDX,dword ptr [this->_padding_]
//         0048a056     PUSH       0x1
//         0048a058     CALL       dword ptr [EDX]
//                               LAB_0048a05a                                                 XREF[1]:     0048a052(j)
//                              rpnl_tbx.cpp:202 (10)
//         0048a05a     MOV        dword ptr [EBP + 0x11c],0x0
//                              rpnl_tbx.cpp:204 (5)
//         0048a064     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a069     MOV        this,dword ptr [ESP + local_c]
//         0048a06d     MOV        dword ptr FS:[0x0],this
//         0048a074     POP        EDI
//         0048a075     POP        ESI
//         0048a076     POP        EBP
//         0048a077     ADD        ESP,0xc
//         0048a07a     RET        0x10
//                               LAB_0048a07d                                                 XREF[2]:     00489fb7(j), 00489fc0(j)
//                              rpnl_tbx.cpp:210 (13)
//         0048a07d     CMP        EAX,dword ptr [EBP + 0x10c]
//         0048a083     JNZ        LAB_0048a0b2
//         0048a085     CMP        this,0x1
//         0048a088     JNZ        LAB_0048a0b2
//                              rpnl_tbx.cpp:212 (15)
//         0048a08a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a090     PUSH       0x0
//         0048a092     PUSH       0x12
//         0048a094     MOV        EAX,dword ptr [this->_padding_]
//         0048a096     CALL       dword ptr [EAX + 0x10]
//                              rpnl_tbx.cpp:213 (5)
//         0048a099     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a09e     MOV        this,dword ptr [ESP + 0xc]
//         0048a0a2     MOV        dword ptr FS:[0x0],this
//         0048a0a9     POP        EDI
//         0048a0aa     POP        ESI
//         0048a0ab     POP        EBP
//         0048a0ac     ADD        ESP,0xc
//         0048a0af     RET        0x10
//                               LAB_0048a0b2                                                 XREF[2]:     0048a083(j), 0048a088(j)
//                              rpnl_tbx.cpp:219 (13)
//         0048a0b2     CMP        EAX,dword ptr [EBP + 0x108]
//         0048a0b8     JNZ        LAB_0048a0e7
//         0048a0ba     CMP        this,0x1
//         0048a0bd     JNZ        LAB_0048a0e7
//                              rpnl_tbx.cpp:221 (15)
//         0048a0bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a0c5     PUSH       0x0
//         0048a0c7     PUSH       0xe
//         0048a0c9     MOV        EDX,dword ptr [this->_padding_]
//         0048a0cb     CALL       dword ptr [EDX + 0x10]
//                              rpnl_tbx.cpp:222 (5)
//         0048a0ce     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a0d3     MOV        this,dword ptr [ESP + 0xc]
//         0048a0d7     MOV        dword ptr FS:[0x0],this
//         0048a0de     POP        EDI
//         0048a0df     POP        ESI
//         0048a0e0     POP        EBP
//         0048a0e1     ADD        ESP,0xc
//         0048a0e4     RET        0x10
//                               LAB_0048a0e7                                                 XREF[2]:     0048a0b8(j), 0048a0bd(j)
//                              rpnl_tbx.cpp:242 (13)
//         0048a0e7     CMP        EAX,dword ptr [EBP + 0x114]
//         0048a0ed     JNZ        LAB_0048a11c
//         0048a0ef     CMP        this,0x1
//         0048a0f2     JNZ        LAB_0048a11c
//                              rpnl_tbx.cpp:244 (15)
//         0048a0f4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a0fa     PUSH       0x0
//         0048a0fc     PUSH       0x3
//         0048a0fe     MOV        EAX,dword ptr [this->_padding_]
//         0048a100     CALL       dword ptr [EAX + 0x10]
//                              rpnl_tbx.cpp:245 (5)
//         0048a103     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a108     MOV        this,dword ptr [ESP + 0xc]
//         0048a10c     MOV        dword ptr FS:[0x0],this
//         0048a113     POP        EDI
//         0048a114     POP        ESI
//         0048a115     POP        EBP
//         0048a116     ADD        ESP,0xc
//         0048a119     RET        0x10
//                               LAB_0048a11c                                                 XREF[2]:     0048a0ed(j), 0048a0f2(j)
//                              rpnl_tbx.cpp:251 (13)
//         0048a11c     CMP        EAX,dword ptr [EBP + 0x118]
//         0048a122     JNZ        LAB_0048a187
//         0048a124     CMP        this,0x1
//         0048a127     JNZ        LAB_0048a187
//                              rpnl_tbx.cpp:253 (12)
//         0048a129     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a12f     MOV        EAX,dword ptr [this->_padding_ + 0x1b0]
//                              rpnl_tbx.cpp:255 (12)
//         0048a135     MOV        EDX,dword ptr [this->_padding_]
//         0048a137     CMP        EAX,0x4
//         0048a13a     JNZ        LAB_0048a169
//         0048a13c     PUSH       0x6
//         0048a13e     CALL       dword ptr [EDX + 0xc]
//                              rpnl_tbx.cpp:256 (11)
//         0048a141     MOV        EAX,[rge_base_game]                              = 00000000
//         0048a146     MOV        this,dword ptr [EAX + 0x3f4]
//                              rpnl_tbx.cpp:302 (9)
//         0048a14c     MOV        EAX,0x1
//         0048a151     MOV        byte ptr [ECX + this->_padding_],0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a155     MOV        this,dword ptr [ESP + 0xc]
//         0048a159     MOV        dword ptr FS:[0x0],this
//         0048a160     POP        EDI
//         0048a161     POP        ESI
//         0048a162     POP        EBP
//         0048a163     ADD        ESP,0xc
//         0048a166     RET        0x10
//                               LAB_0048a169                                                 XREF[1]:     0048a13a(j)
//                              rpnl_tbx.cpp:259 (5)
//         0048a169     PUSH       0x4
//         0048a16b     CALL       dword ptr [EDX + 0xc]
//                              rpnl_tbx.cpp:260 (5)
//         0048a16e     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a173     MOV        this,dword ptr [ESP + 0xc]
//         0048a177     MOV        dword ptr FS:[0x0],this
//         0048a17e     POP        EDI
//         0048a17f     POP        ESI
//         0048a180     POP        EBP
//         0048a181     ADD        ESP,0xc
//         0048a184     RET        0x10
//                               LAB_0048a187                                                 XREF[2]:     0048a122(j), 0048a127(j)
//                              rpnl_tbx.cpp:263 (20)
//         0048a187     MOV        this,dword ptr [EBP + 0x11c]
//         0048a18d     LEA        EDI,[EBP + 0x11c]
//         0048a193     CMP        EAX,this
//         0048a195     JNZ        LAB_0048a307
//                              rpnl_tbx.cpp:268 (55)
//         0048a19b     MOV        ESI,s_Object_List_Dialog                         = 4Fh
//         0048a1a0     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_0048a1a5                                                 XREF[1]:     0048a1c3(j)
//         0048a1a5     MOV        DL,byte ptr [EAX]
//         0048a1a7     MOV        this,DL
//         0048a1a9     CMP        DL,byte ptr [ESI]=>s_Object_List_Dialog          = 4Fh
//                                                                                  = 6Ah
//         0048a1ab     JNZ        LAB_0048a1c9
//         0048a1ad     TEST       this,this
//         0048a1af     JZ         LAB_0048a1c5
//         0048a1b1     MOV        DL,byte ptr [EAX + 0x1]
//         0048a1b4     MOV        this,DL
//         0048a1b6     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00585f99            = 62h
//                                                                                  = "ect List Dialog"
//         0048a1b9     JNZ        LAB_0048a1c9
//         0048a1bb     ADD        EAX,0x2
//         0048a1be     ADD        ESI,0x2
//         0048a1c1     TEST       this,this
//         0048a1c3     JNZ        LAB_0048a1a5
//                               LAB_0048a1c5                                                 XREF[1]:     0048a1af(j)
//         0048a1c5     XOR        EAX,EAX
//         0048a1c7     JMP        LAB_0048a1ce
//                               LAB_0048a1c9                                                 XREF[2]:     0048a1ab(j), 0048a1b9(j)
//         0048a1c9     SBB        EAX,EAX
//         0048a1cb     SBB        EAX,-0x1
//                               LAB_0048a1ce                                                 XREF[1]:     0048a1c7(j)
//         0048a1ce     TEST       EAX,EAX
//         0048a1d0     JNZ        LAB_0048a23c
//                              rpnl_tbx.cpp:270 (13)
//         0048a1d2     MOV        EAX,dword ptr [ESP + param_2]
//         0048a1d6     CMP        EAX,0x1
//         0048a1d9     JNZ        LAB_0048a2c9
//                              rpnl_tbx.cpp:272 (16)
//         0048a1df     MOV        this,dword ptr [EDI]
//         0048a1e1     MOV        EAX,dword ptr [this->_padding_]
//         0048a1e3     CALL       dword ptr [EAX + 0x130]
//         0048a1e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              rpnl_tbx.cpp:273 (19)
//         0048a1ef     PUSH       EDI
//         0048a1f0     MOV        word ptr [this->_padding_ + 0x3fc],AX
//         0048a1f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a1fd     CALL       RGE_Base_Game::delete_dialog                     void delete_dialog(RGE_Base_Game * this, TPan
//                              rpnl_tbx.cpp:274 (15)
//         0048a202     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a208     PUSH       0x0
//         0048a20a     PUSH       offset DAT_fffffff8
//         0048a20c     MOV        EDX,dword ptr [this->_padding_]
//         0048a20e     CALL       dword ptr [EDX + 0x10]
//                              rpnl_tbx.cpp:275 (18)
//         0048a211     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a217     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0048a21c     MOV        this,EAX
//         0048a21e     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              rpnl_tbx.cpp:302 (5)
//         0048a223     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a228     MOV        this,dword ptr [ESP + 0xc]
//         0048a22c     MOV        dword ptr FS:[0x0],this
//         0048a233     POP        EDI
//         0048a234     POP        ESI
//         0048a235     POP        EBP
//         0048a236     ADD        ESP,0xc
//         0048a239     RET        0x10
//                               LAB_0048a23c                                                 XREF[1]:     0048a1d0(j)
//                              rpnl_tbx.cpp:288 (57)
//         0048a23c     MOV        this,dword ptr [EDI]
//         0048a23e     MOV        ESI,s_Terrain_List_Dialog                        = 54h
//         0048a243     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_0048a248                                                 XREF[1]:     0048a266(j)
//         0048a248     MOV        DL,byte ptr [EAX]
//         0048a24a     MOV        this,DL
//         0048a24c     CMP        DL,byte ptr [ESI]=>s_Terrain_List_Dialog         = 54h
//                                                                                  = 72h
//         0048a24e     JNZ        LAB_0048a26c
//         0048a250     TEST       this,this
//         0048a252     JZ         LAB_0048a268
//         0048a254     MOV        DL,byte ptr [EAX + 0x1]
//         0048a257     MOV        this,DL
//         0048a259     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00585f85            = 65h
//                                                                                  = "rain List Dialog"
//         0048a25c     JNZ        LAB_0048a26c
//         0048a25e     ADD        EAX,0x2
//         0048a261     ADD        ESI,0x2
//         0048a264     TEST       this,this
//         0048a266     JNZ        LAB_0048a248
//                               LAB_0048a268                                                 XREF[1]:     0048a252(j)
//         0048a268     XOR        EAX,EAX
//         0048a26a     JMP        LAB_0048a271
//                               LAB_0048a26c                                                 XREF[2]:     0048a24e(j), 0048a25c(j)
//         0048a26c     SBB        EAX,EAX
//         0048a26e     SBB        EAX,-0x1
//                               LAB_0048a271                                                 XREF[1]:     0048a26a(j)
//         0048a271     TEST       EAX,EAX
//         0048a273     JNZ        LAB_0048a2ee
//                              rpnl_tbx.cpp:290 (9)
//         0048a275     MOV        EAX,dword ptr [ESP + param_2]
//         0048a279     CMP        EAX,0x1
//         0048a27c     JNZ        LAB_0048a2c9
//                              rpnl_tbx.cpp:292 (16)
//         0048a27e     MOV        this,dword ptr [EDI]
//         0048a280     MOV        EAX,dword ptr [this->_padding_]
//         0048a282     CALL       dword ptr [EAX + 0x130]
//         0048a288     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              rpnl_tbx.cpp:293 (19)
//         0048a28e     PUSH       EDI
//         0048a28f     MOV        word ptr [this->_padding_ + 0x3fe],AX
//         0048a296     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a29c     CALL       RGE_Base_Game::delete_dialog                     void delete_dialog(RGE_Base_Game * this, TPan
//                              rpnl_tbx.cpp:294 (15)
//         0048a2a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a2a7     PUSH       0x0
//         0048a2a9     PUSH       offset DAT_fffffff8
//         0048a2ab     MOV        EDX,dword ptr [this->_padding_]
//         0048a2ad     CALL       dword ptr [EDX + 0x10]
//                              rpnl_tbx.cpp:302 (5)
//         0048a2b0     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (20)
//         0048a2b5     MOV        this,dword ptr [ESP + 0xc]
//         0048a2b9     MOV        dword ptr FS:[0x0],this
//         0048a2c0     POP        EDI
//         0048a2c1     POP        ESI
//         0048a2c2     POP        EBP
//         0048a2c3     ADD        ESP,0xc
//         0048a2c6     RET        0x10
//                               LAB_0048a2c9                                                 XREF[2]:     0048a1d9(j), 0048a27c(j)
//                              rpnl_tbx.cpp:296 (5)
//         0048a2c9     CMP        EAX,0x2
//         0048a2cc     JNZ        LAB_0048a2ee
//                              rpnl_tbx.cpp:298 (12)
//         0048a2ce     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a2d4     PUSH       EDI
//         0048a2d5     CALL       RGE_Base_Game::delete_dialog                     void delete_dialog(RGE_Base_Game * this, TPan
//                              rpnl_tbx.cpp:299 (20)
//         0048a2da     MOV        EAX,[rge_base_game]                              = 00000000
//         0048a2df     MOV        this,EBP
//         0048a2e1     MOV        EAX,dword ptr [EAX + 0x1b4]
//         0048a2e7     PUSH       EAX
//         0048a2e8     PUSH       EAX
//         0048a2e9     CALL       RGE_Panel_Tool_Box::game_mode_changed            void game_mode_changed(RGE_Panel_Tool_Box * t
//                               LAB_0048a2ee                                                 XREF[4]:     0048a003(j), 0048a044(j),
//                                                                                                         0048a273(j), 0048a2cc(j)
//                              rpnl_tbx.cpp:302 (5)
//         0048a2ee     MOV        EAX,0x1
//                              rpnl_tbx.cpp:306 (42)
//         0048a2f3     MOV        this,dword ptr [ESP + local_c]
//         0048a2f7     MOV        dword ptr FS:[0x0],this
//         0048a2fe     POP        EDI
//         0048a2ff     POP        ESI
//         0048a300     POP        EBP
//         0048a301     ADD        ESP,0xc
//         0048a304     RET        0x10
//                               LAB_0048a307                                                 XREF[2]:     00489f70(j), 0048a195(j)
//         0048a307     MOV        this,dword ptr [ESP + local_c]
//         0048a30b     POP        EDI
//         0048a30c     POP        ESI
//         0048a30d     XOR        EAX,EAX
//         0048a30f     MOV        dword ptr FS:[0x0],this
//         0048a316     POP        EBP
//         0048a317     ADD        ESP,0xc
//         0048a31a     RET        0x10
//         0048a31d     ??         90h
//         0048a31e     NOP
//         0048a31f     NOP
    return 0;
}

long RGE_Panel_Tool_Box::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(RGE_Panel_Tool_Box * this, long para
//              long              EAX:4          <RETURN>
//              RGE_Panel_Tool    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0048a35a(R)
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0048a402(*), 0048a420(R), 0048a44a(R), 0048a47f(*),
//                                                                                     0048a4a3(R), 0048a4cc(R)
//              long              Stack[-0x8]:4  x1                        XREF[6]:     0048a3f7(*), 0048a415(R), 0048a443(R), 0048a47a(*),
//                                                                                     0048a498(R), 0048a4c5(R)
//              long              Stack[-0xc]:4  y1                        XREF[6]:     0048a3f2(*), 0048a411(R), 0048a43f(R), 0048a475(*),
//                                                                                     0048a494(R), 0048a4c1(R)
//              long              Stack[-0x10]:4 x2                        XREF[6]:     0048a3ec(*), 0048a40d(R), 0048a43b(R), 0048a46f(*),
//                                                                                     0048a490(R), 0048a4bd(R)
//              long              Stack[-0x14]:4 y2
//                               ?key_down_action@RGE_Panel_Tool_Box@@UAEJJFHHH@Z             XREF[1]:     0057200c(*)
//                               RGE_Panel_Tool_Box::key_down_action
//                              rpnl_tbx.cpp:312 (8)
//         0048a320     SUB        ESP,0x10
//         0048a323     PUSH       EBX
//         0048a324     PUSH       ESI
//         0048a325     MOV        ESI,this
//         0048a327     PUSH       EDI
//                              rpnl_tbx.cpp:317 (50)
//         0048a328     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a32e     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0048a333     TEST       EAX,EAX
//         0048a335     JNZ        LAB_0048a512
//         0048a33b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a341     MOV        EAX,dword ptr [this->_padding_ + 0x1b0]
//         0048a347     CMP        EAX,0x4
//         0048a34a     JZ         LAB_0048a35a
//         0048a34c     CMP        EAX,0x6
//         0048a34f     JZ         LAB_0048a35a
//         0048a351     CMP        EAX,0x7
//         0048a354     JNZ        LAB_0048a512
//                               LAB_0048a35a                                                 XREF[2]:     0048a34a(j), 0048a34f(j)
//                              rpnl_tbx.cpp:320 (25)
//         0048a35a     MOV        EAX,dword ptr [ESP + param_1]
//         0048a35e     SUB        EAX,0x21
//         0048a361     JZ         LAB_0048a462
//         0048a367     DEC        EAX
//         0048a368     JZ         LAB_0048a3df
//         0048a36a     SUB        EAX,0xc
//         0048a36d     JNZ        LAB_0048a512
//                              rpnl_tbx.cpp:323 (13)
//         0048a373     CMP        dword ptr [this->_padding_ + 0x1b4],0x12
//         0048a37a     JNZ        LAB_0048a512
//                              rpnl_tbx.cpp:325 (11)
//         0048a380     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0048a385     MOV        EDI,dword ptr [EAX + 0x130]
//                              rpnl_tbx.cpp:326 (8)
//         0048a38b     TEST       EDI,EDI
//         0048a38d     JZ         LAB_0048a504
//                              rpnl_tbx.cpp:328 (7)
//         0048a393     MOV        this,dword ptr [EDI + 0x18]
//         0048a396     TEST       this,this
//         0048a398     JZ         LAB_0048a3a3
//                              rpnl_tbx.cpp:329 (7)
//         0048a39a     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
//         0048a39f     MOV        BL,AL
//                              rpnl_tbx.cpp:330 (9)
//         0048a3a1     JMP        LAB_0048a3b5
//                               LAB_0048a3a3                                                 XREF[1]:     0048a398(j)
//         0048a3a3     MOV        this,dword ptr [EDI + 0x10]
//         0048a3a6     TEST       this,this
//         0048a3a8     JZ         LAB_0048a3b3
//                              rpnl_tbx.cpp:331 (7)
//         0048a3aa     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
//         0048a3af     MOV        BL,AL
//                              rpnl_tbx.cpp:332 (2)
//         0048a3b1     JMP        LAB_0048a3b5
//                               LAB_0048a3b3                                                 XREF[1]:     0048a3a8(j)
//                              rpnl_tbx.cpp:333 (2)
//         0048a3b3     MOV        BL,0x14
//                               LAB_0048a3b5                                                 XREF[2]:     0048a3a1(j), 0048a3b1(j)
//                              rpnl_tbx.cpp:335 (7)
//         0048a3b5     MOV        EAX,dword ptr [EDI]
//         0048a3b7     MOV        this,EDI
//         0048a3b9     CALL       dword ptr [EAX + 0x68]
//                              rpnl_tbx.cpp:337 (8)
//         0048a3bc     TEST       BL,BL
//         0048a3be     JNZ        LAB_0048a504
//                              rpnl_tbx.cpp:338 (13)
//         0048a3c4     MOV        this,dword ptr [ESI + 0xf8]
//         0048a3ca     PUSH       0x2
//         0048a3cc     MOV        EDX,dword ptr [this->_padding_]
//         0048a3ce     CALL       dword ptr [EDX + 0x20]
//                              rpnl_tbx.cpp:340 (5)
//         0048a3d1     MOV        EAX,0x1
//                              rpnl_tbx.cpp:372 (9)
//         0048a3d6     POP        EDI
//         0048a3d7     POP        ESI
//         0048a3d8     POP        EBX
//         0048a3d9     ADD        ESP,0x10
//         0048a3dc     RET        0x14
//                               LAB_0048a3df                                                 XREF[1]:     0048a368(j)
//                              rpnl_tbx.cpp:358 (13)
//         0048a3df     CMP        dword ptr [this->_padding_ + 0x1b4],0x3
//         0048a3e6     JNZ        LAB_0048a512
//                              rpnl_tbx.cpp:360 (33)
//         0048a3ec     LEA        EAX=>x2,[ESP + 0xc]
//         0048a3f0     PUSH       0x1
//         0048a3f2     LEA        this=>y1,[ESP + 0x14]
//         0048a3f6     PUSH       EAX
//         0048a3f7     LEA        EDX=>x1,[ESP + 0x1c]
//         0048a3fb     PUSH       this
//         0048a3fc     MOV        this,dword ptr [ESI + 0xf8]
//         0048a402     LEA        EAX=>local_4,[ESP + 0x24]
//         0048a406     PUSH       EDX
//         0048a407     PUSH       EAX
//         0048a408     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long
//                              rpnl_tbx.cpp:361 (46)
//         0048a40d     MOV        this,dword ptr [ESP + x2]
//         0048a411     MOV        EDX,dword ptr [ESP + y1]
//         0048a415     MOV        EAX,dword ptr [ESP + x1]
//         0048a419     PUSH       0x1
//         0048a41b     PUSH       -0x1
//         0048a41d     PUSH       0x0
//         0048a41f     PUSH       this
//         0048a420     MOV        this,dword ptr [ESP + local_4]
//         0048a424     PUSH       EDX
//         0048a425     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0048a42b     PUSH       EAX
//         0048a42c     PUSH       this
//         0048a42d     MOV        EAX,dword ptr [EDX + 0x3f4]
//         0048a433     MOV        this,dword ptr [EAX + 0x28]
//         0048a436     CALL       RGE_Map::set_elev                                void set_elev(RGE_Map * this, short param_1,
//                              rpnl_tbx.cpp:362 (37)
//         0048a43b     MOV        this,dword ptr [ESP + x2]
//         0048a43f     MOV        EDX,dword ptr [ESP + y1]
//         0048a443     MOV        EAX,dword ptr [ESP + x1]
//         0048a447     PUSH       0x8
//         0048a449     PUSH       this
//         0048a44a     MOV        this,dword ptr [ESP + local_4]
//         0048a44e     PUSH       EDX
//         0048a44f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0048a455     PUSH       EAX
//         0048a456     PUSH       this
//         0048a457     MOV        EAX,dword ptr [EDX + 0x3f4]
//         0048a45d     MOV        this,dword ptr [EAX + 0x28]
//                              rpnl_tbx.cpp:366 (2)
//         0048a460     JMP        LAB_0048a4e1
//                               LAB_0048a462                                                 XREF[1]:     0048a361(j)
//                              rpnl_tbx.cpp:345 (13)
//         0048a462     CMP        dword ptr [this->_padding_ + 0x1b4],0x3
//         0048a469     JNZ        LAB_0048a512
//                              rpnl_tbx.cpp:347 (33)
//         0048a46f     LEA        this=>x2,[ESP + 0xc]
//         0048a473     PUSH       0x1
//         0048a475     LEA        EDX=>y1,[ESP + 0x14]
//         0048a479     PUSH       this
//         0048a47a     LEA        EAX=>x1,[ESP + 0x1c]
//         0048a47e     PUSH       EDX
//         0048a47f     LEA        this=>local_4,[ESP + 0x24]
//         0048a483     PUSH       EAX
//         0048a484     PUSH       this
//         0048a485     MOV        this,dword ptr [ESI + 0xf8]
//         0048a48b     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long
//                              rpnl_tbx.cpp:348 (45)
//         0048a490     MOV        EDX,dword ptr [ESP + x2]
//         0048a494     MOV        EAX,dword ptr [ESP + y1]
//         0048a498     MOV        this,dword ptr [ESP + x1]
//         0048a49c     PUSH       0x1
//         0048a49e     PUSH       0x1
//         0048a4a0     PUSH       0x0
//         0048a4a2     PUSH       EDX
//         0048a4a3     MOV        EDX,dword ptr [ESP + local_4]
//         0048a4a7     PUSH       EAX
//         0048a4a8     MOV        EAX,[rge_base_game]                              = 00000000
//         0048a4ad     PUSH       this
//         0048a4ae     PUSH       EDX
//         0048a4af     MOV        this,dword ptr [EAX + 0x3f4]
//         0048a4b5     MOV        this,dword ptr [ECX + this->_padding_]
//         0048a4b8     CALL       RGE_Map::set_elev                                void set_elev(RGE_Map * this, short param_1,
//                              rpnl_tbx.cpp:349 (41)
//         0048a4bd     MOV        EDX,dword ptr [ESP + x2]
//         0048a4c1     MOV        EAX,dword ptr [ESP + y1]
//         0048a4c5     MOV        this,dword ptr [ESP + x1]
//         0048a4c9     PUSH       0x8
//         0048a4cb     PUSH       EDX
//         0048a4cc     MOV        EDX,dword ptr [ESP + local_4]
//         0048a4d0     PUSH       EAX
//         0048a4d1     MOV        EAX,[rge_base_game]                              = 00000000
//         0048a4d6     PUSH       this
//         0048a4d7     PUSH       EDX
//         0048a4d8     MOV        this,dword ptr [EAX + 0x3f4]
//         0048a4de     MOV        this,dword ptr [ECX + this->_padding_]
//                               LAB_0048a4e1                                                 XREF[1]:     0048a460(j)
//         0048a4e1     CALL       RGE_Map::clean_elevation                         void clean_elevation(RGE_Map * this, long par
//                              rpnl_tbx.cpp:350 (13)
//         0048a4e6     MOV        this,dword ptr [ESI + 0xf8]
//         0048a4ec     PUSH       0x2
//         0048a4ee     MOV        EDX,dword ptr [this->_padding_]
//         0048a4f0     CALL       dword ptr [EDX + 0x20]
//                              rpnl_tbx.cpp:351 (10)
//         0048a4f3     MOV        this,dword ptr [ESI + 0xfc]
//         0048a4f9     TEST       this,this
//         0048a4fb     JZ         LAB_0048a504
//                              rpnl_tbx.cpp:352 (7)
//         0048a4fd     MOV        EAX,dword ptr [this->_padding_]
//         0048a4ff     PUSH       0x2
//         0048a501     CALL       dword ptr [EAX + 0x20]
//                               LAB_0048a504                                                 XREF[3]:     0048a38d(j), 0048a3be(j),
//                                                                                                         0048a4fb(j)
//                              rpnl_tbx.cpp:353 (5)
//         0048a504     MOV        EAX,0x1
//                              rpnl_tbx.cpp:372 (20)
//         0048a509     POP        EDI
//         0048a50a     POP        ESI
//         0048a50b     POP        EBX
//         0048a50c     ADD        ESP,0x10
//         0048a50f     RET        0x14
//                               LAB_0048a512                                                 XREF[6]:     0048a335(j), 0048a354(j),
//                                                                                                         0048a36d(j), 0048a37a(j),
//                                                                                                         0048a3e6(j), 0048a469(j)
//         0048a512     POP        EDI
//         0048a513     POP        ESI
//         0048a514     XOR        EAX,EAX
//         0048a516     POP        EBX
//         0048a517     ADD        ESP,0x10
//         0048a51a     RET        0x14
//         0048a51d     ??         90h
//         0048a51e     NOP
//         0048a51f     NOP
    return 0;
}

void RGE_Panel_Tool_Box::game_mode_changed(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall game_mode_changed(RGE_Panel_Tool_Box * this, int par
//              void              <VOID>         <RETURN>
//              RGE_Panel_Tool    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0048a520(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0048a563(R)
//                               ?game_mode_changed@RGE_Panel_Tool_Box@@QAEXHH@Z              XREF[3]:     RGE_Panel_Tool_Box:00489e4b(c),
//                               RGE_Panel_Tool_Box::game_mode_changed                                     action:0048a2e9(c),
//                                                                                                         game_mode_changed:00498a27(c)
//                              rpnl_tbx.cpp:380 (28)
//         0048a520     MOV        EAX,dword ptr [ESP + param_1]
//         0048a524     PUSH       ESI
//         0048a525     DEC        EAX
//         0048a526     MOV        ESI,this
//         0048a528     CMP        EAX,0x11
//         0048a52b     JA         switchD_0048a535::caseD_4
//         0048a52d     XOR        this,this
//         0048a52f     MOV        this,byte ptr [EAX + 0x48a5f4]=>PTR_caseD_4_00
//                               switchD_0048a535::switchD
//         0048a535     JMP        dword ptr [this->_padding_*0x4 + switchD_0048a   = 0048a53c
//                               switchD_0048a535::caseD_12                                   XREF[3]:     0048a535(j), 0048a5e4(*),
//                               switchD_0048a535::caseD_1                                                 0048a5ec(*)
//                              rpnl_tbx.cpp:385 (18)
//         0048a53c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a542     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0048a547     MOV        this,EAX
//         0048a549     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              rpnl_tbx.cpp:386 (2)
//         0048a54e     JMP        switchD_0048a535::caseD_4
//                               switchD_0048a535::caseD_3                                    XREF[2]:     0048a535(j), 0048a5e8(*)
//                               switchD_0048a535::caseD_2
//                              rpnl_tbx.cpp:390 (19)
//         0048a550     MOV        this,dword ptr [ESI + 0xf8]
//         0048a556     PUSH       -0x1
//         0048a558     PUSH       -0x1
//         0048a55a     PUSH       -0x1
//         0048a55c     PUSH       -0x1
//         0048a55e     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                               switchD_0048a535::caseD_5                                    XREF[4]:     0048a52b(j), 0048a535(j),
//                               switchD_0048a535::caseD_6                                                 0048a54e(j), 0048a5f0(*)
//                               switchD_0048a535::caseD_7
//                               switchD_0048a535::caseD_8
//                               switchD_0048a535::caseD_9
//                               switchD_0048a535::caseD_a
//                               switchD_0048a535::caseD_b
//                               switchD_0048a535::caseD_c
//                               switchD_0048a535::caseD_d
//                               switchD_0048a535::caseD_e
//                               switchD_0048a535::caseD_f
//                               switchD_0048a535::caseD_10
//                               switchD_0048a535::caseD_11
//                               switchD_0048a535::caseD_4
//                              rpnl_tbx.cpp:394 (27)
//         0048a563     MOV        EDX,dword ptr [ESP + param_2]
//         0048a567     LEA        EAX,[EDX + -0x1]
//         0048a56a     CMP        EAX,0x11
//         0048a56d     JA         switchD_0048a577::caseD_4
//         0048a56f     XOR        this,this
//         0048a571     MOV        this,byte ptr [EAX + 0x48a620]=>PTR_caseD_4_00
//                               switchD_0048a577::switchD
//         0048a577     JMP        dword ptr [this->_padding_*0x4 + switchD_0048a   = 0048a57e
//                               switchD_0048a577::caseD_1                                    XREF[2]:     0048a577(j), 0048a608(*)
//                              rpnl_tbx.cpp:397 (6)
//         0048a57e     MOV        this,dword ptr [ESI + 0x104]
//                              rpnl_tbx.cpp:419 (5)
//         0048a584     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              rpnl_tbx.cpp:422 (4)
//         0048a589     POP        ESI
//         0048a58a     RET        0x8
//                               switchD_0048a577::caseD_12                                   XREF[2]:     0048a577(j), 0048a618(*)
//                              rpnl_tbx.cpp:401 (6)
//         0048a58d     MOV        this,dword ptr [ESI + 0x10c]
//                              rpnl_tbx.cpp:419 (5)
//         0048a593     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              rpnl_tbx.cpp:422 (4)
//         0048a598     POP        ESI
//         0048a599     RET        0x8
//                               switchD_0048a577::caseD_e                                    XREF[2]:     0048a577(j), 0048a614(*)
//                              rpnl_tbx.cpp:405 (6)
//         0048a59c     MOV        this,dword ptr [ESI + 0x108]
//                              rpnl_tbx.cpp:419 (5)
//         0048a5a2     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              rpnl_tbx.cpp:422 (4)
//         0048a5a7     POP        ESI
//         0048a5a8     RET        0x8
//                               switchD_0048a577::caseD_2                                    XREF[2]:     0048a577(j), 0048a60c(*)
//                              rpnl_tbx.cpp:409 (6)
//         0048a5ab     MOV        this,dword ptr [ESI + 0x110]
//                              rpnl_tbx.cpp:411 (2)
//         0048a5b1     JMP        LAB_0048a5b9
//                               switchD_0048a577::caseD_3                                    XREF[2]:     0048a577(j), 0048a610(*)
//                              rpnl_tbx.cpp:414 (11)
//         0048a5b3     MOV        this,dword ptr [ESI + 0x114]
//                               LAB_0048a5b9                                                 XREF[1]:     0048a5b1(j)
//         0048a5b9     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              rpnl_tbx.cpp:415 (18)
//         0048a5be     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048a5c4     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0048a5c9     MOV        this,EAX
//         0048a5cb     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              rpnl_tbx.cpp:422 (4)
//         0048a5d0     POP        ESI
//         0048a5d1     RET        0x8
//                               switchD_0048a577::caseD_5                                    XREF[3]:     0048a56d(j), 0048a577(j),
//                               switchD_0048a577::caseD_6                                                 0048a61c(*)
//                               switchD_0048a577::caseD_7
//                               switchD_0048a577::caseD_8
//                               switchD_0048a577::caseD_9
//                               switchD_0048a577::caseD_a
//                               switchD_0048a577::caseD_b
//                               switchD_0048a577::caseD_c
//                               switchD_0048a577::caseD_d
//                               switchD_0048a577::caseD_f
//                               switchD_0048a577::caseD_10
//                               switchD_0048a577::caseD_11
//                               switchD_0048a577::caseD_4
//                              rpnl_tbx.cpp:419 (11)
//         0048a5d4     MOV        this,dword ptr [ESI + 0x100]
//         0048a5da     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              rpnl_tbx.cpp:422 (83)
//         0048a5df     POP        ESI
//         0048a5e0     RET        0x8
//         0048a5e3     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0048a535::switchdataD_0048a5e4                       XREF[1]:     game_mode_changed:0048a535(*)
//         0048a5e4     addr       switchD_0048a535::caseD_1
//         0048a5e8     addr       switchD_0048a535::caseD_2
//         0048a5ec     addr       switchD_0048a535::caseD_1
//                               PTR_caseD_4_0048a5f0+3                                       XREF[0,1]:   game_mode_changed:0048a52f(*)
//         0048a5f0     addr       switchD_0048a535::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0048a535::switchdataD_0048a5f4
//         0048a5f4     db         0h
//         0048a5f5     db         1h
//         0048a5f6     db         1h
//         0048a5f7     db         3h
//         0048a5f8     db         3h
//         0048a5f9     db         3h
//         0048a5fa     db         3h
//         0048a5fb     db         3h
//         0048a5fc     db         3h
//         0048a5fd     db         3h
//         0048a5fe     db         3h
//         0048a5ff     db         3h
//         0048a600     db         3h
//         0048a601     db         3h
//         0048a602     db         3h
//         0048a603     db         3h
//         0048a604     db         3h
//         0048a605     db         2h
//         0048a606     ??         8Bh
//         0048a607     ??         FFh
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0048a577::switchdataD_0048a608                       XREF[1]:     game_mode_changed:0048a577(*)
//         0048a608     addr       switchD_0048a577::caseD_1
//         0048a60c     addr       switchD_0048a577::caseD_2
//         0048a610     addr       switchD_0048a577::caseD_3
//         0048a614     addr       switchD_0048a577::caseD_e
//         0048a618     addr       switchD_0048a577::caseD_12
//                               PTR_caseD_4_0048a61c+3                                       XREF[0,1]:   game_mode_changed:0048a571(*)
//         0048a61c     addr       switchD_0048a577::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0048a577::switchdataD_0048a620
//         0048a620     db         0h
//         0048a621     db         1h
//         0048a622     db         2h
//         0048a623     db         5h
//         0048a624     db         5h
//         0048a625     db         5h
//         0048a626     db         5h
//         0048a627     db         5h
//         0048a628     db         5h
//         0048a629     db         5h
//         0048a62a     db         5h
//         0048a62b     db         5h
//         0048a62c     db         5h
//         0048a62d     db         3h
//         0048a62e     db         5h
//         0048a62f     db         5h
//         0048a630     db         5h
//         0048a631     db         4h
//         0048a632     ??         90h
//         0048a633     ??         90h
//         0048a634     ??         90h
//         0048a635     ??         90h
//         0048a636     ??         90h
//         0048a637     ??         90h
//         0048a638     ??         90h
//         0048a639     ??         90h
//         0048a63a     ??         90h
//         0048a63b     ??         90h
//         0048a63c     ??         90h
//         0048a63d     ??         90h
//         0048a63e     ??         90h
//         0048a63f     ??         90h
    return;
}

void RGE_Panel_Tool_Box::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(RGE_Panel_Tool_Box * this)
//              void              <VOID>         <RETURN>
//              RGE_Panel_Tool    ECX:4 (auto)   this
//                               ?draw@RGE_Panel_Tool_Box@@UAEXXZ                             XREF[1]:     00571f90(*)
//                               RGE_Panel_Tool_Box::draw
//                              rpnl_tbx.cpp:428 (3)
//         0048a640     PUSH       ESI
//         0048a641     MOV        ESI,this
//                              rpnl_tbx.cpp:429 (22)
//         0048a643     MOV        EAX,dword ptr [ESI + 0x20]
//         0048a646     TEST       EAX,EAX
//         0048a648     JZ         LAB_0048a674
//         0048a64a     MOV        EAX,dword ptr [ESI + 0x70]
//         0048a64d     TEST       EAX,EAX
//         0048a64f     JZ         LAB_0048a674
//         0048a651     MOV        EAX,dword ptr [ESI + 0x6c]
//         0048a654     TEST       EAX,EAX
//         0048a656     JZ         LAB_0048a674
//         0048a658     PUSH       EDI
//                              rpnl_tbx.cpp:432 (7)
//         0048a659     MOV        EDI,dword ptr [ESI]
//         0048a65b     PUSH       0x0
//         0048a65d     CALL       dword ptr [EDI + 0x28]
//                              rpnl_tbx.cpp:434 (14)
//         0048a660     MOV        this,dword ptr [ESI + 0x20]
//         0048a663     LEA        EAX,[ESI + 0x24]
//         0048a666     PUSH       0x0
//         0048a668     PUSH       EAX
//         0048a669     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                              rpnl_tbx.cpp:436 (6)
//         0048a66e     MOV        this,ESI
//         0048a670     CALL       dword ptr [EDI + 0x2c]
//         0048a673     POP        EDI
//                               LAB_0048a674                                                 XREF[3]:     0048a648(j), 0048a64f(j),
//                                                                                                         0048a656(j)
//                              rpnl_tbx.cpp:437 (2)
//         0048a674     POP        ESI
//         0048a675     RET
//         0048a676     ??         90h
//         0048a677     NOP
//         0048a678     NOP
//         0048a679     NOP
//         0048a67a     NOP
//         0048a67b     NOP
//         0048a67c     NOP
//         0048a67d     NOP
//         0048a67e     NOP
//         0048a67f     NOP
    return;
}

