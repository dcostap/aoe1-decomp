#include "common.h"
#include "tpnl_inv.h"

void TRIBE_Panel_Inven::set_text_color(ulong param_1, ulong param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_text_color(TRIBE_Panel_Inven * this, ulong param
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     0051a6b0(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0051a6b4(R)  
    //                               ?set_text_color@TRIBE_Panel_Inven@@QAEXKK@Z                  XREF[2]:     player_changed:004991a6(c), 
    //                               TRIBE_Panel_Inven::set_text_color                                         player_changed:00499223(c)  
    //                              tpnl_inv.cpp:67 (4)
    //         0051a6b0     MOV        EAX,dword ptr [ESP + param_1]
    //                              tpnl_inv.cpp:69 (10)
    //         0051a6b4     MOV        EDX,dword ptr [ESP + param_2]
    //         0051a6b8     MOV        dword ptr [ECX + this->font_color],EAX
    //                              tpnl_inv.cpp:70 (13)
    //         0051a6be     MOV        EAX,dword ptr [this->_padding_]
    //         0051a6c0     PUSH       0x1
    //         0051a6c2     MOV        dword ptr [ECX + this->back_color],EDX
    //         0051a6c8     CALL       dword ptr [EAX + 0x20]
    //                              tpnl_inv.cpp:71 (3)
    //         0051a6cb     RET        0x8
    //         0051a6ce     ??         90h
    //         0051a6cf     NOP
    return;
}

TRIBE_Panel_Inven::~TRIBE_Panel_Inven() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Panel_Inven(TRIBE_Panel_Inven * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051a6fa(W), 0051a746(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051a753(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051a6ea(W)  
    //                               ??1TRIBE_Panel_Inven@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':0051a
    //                               TRIBE_Panel_Inven::~TRIBE_Panel_Inven
    //                              tpnl_inv.cpp:77 (36)
    //         0051a6d0     PUSH       -0x1
    //         0051a6d2     PUSH       FUN_00561338
    //         0051a6d7     MOV        EAX,FS:[0x0]
    //         0051a6dd     PUSH       EAX
    //         0051a6de     MOV        dword ptr FS:[0x0],ESP
    //         0051a6e5     PUSH       this
    //         0051a6e6     PUSH       ESI
    //         0051a6e7     MOV        ESI,this
    //         0051a6e9     PUSH       EDI
    //         0051a6ea     MOV        dword ptr [ESP + local_10],ESI
    //         0051a6ee     MOV        dword ptr [ESI],TRIBE_Panel_Inven::`vftable'     = 0051a690
    //                              tpnl_inv.cpp:78 (18)
    //         0051a6f4     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051a6fa     MOV        dword ptr [ESP + local_4],0x0
    //         0051a702     TEST       EAX,EAX
    //         0051a704     JZ         LAB_0051a719
    //                              tpnl_inv.cpp:80 (9)
    //         0051a706     PUSH       EAX
    //         0051a707     CALL       free                                             undefined free()
    //         0051a70c     ADD        ESP,0x4
    //                              tpnl_inv.cpp:81 (10)
    //         0051a70f     MOV        dword ptr [ESI + 0x100],0x0
    //                               LAB_0051a719                                                 XREF[1]:     0051a704(j)  
    //                              tpnl_inv.cpp:84 (10)
    //         0051a719     MOV        EDI,dword ptr [ESI + 0xf4]
    //         0051a71f     TEST       EDI,EDI
    //         0051a721     JZ         LAB_0051a73d
    //                              tpnl_inv.cpp:86 (16)
    //         0051a723     MOV        this,EDI
    //         0051a725     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051a72a     PUSH       EDI
    //         0051a72b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051a730     ADD        ESP,0x4
    //                              tpnl_inv.cpp:87 (10)
    //         0051a733     MOV        dword ptr [ESI + 0xf4],0x0
    //                               LAB_0051a73d                                                 XREF[1]:     0051a721(j)  
    //                              tpnl_inv.cpp:90 (9)
    //         0051a73d     MOV        this,ESI
    //         0051a73f     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         0051a744     MOV        this,ESI
    //                              tpnl_inv.cpp:91 (30)
    //         0051a746     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0051a74e     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         0051a753     MOV        this,dword ptr [ESP + local_c]
    //         0051a757     POP        EDI
    //         0051a758     MOV        dword ptr FS:[0x0],this
    //         0051a75f     POP        ESI
    //         0051a760     ADD        ESP,0x10
    //         0051a763     RET
    //         0051a764     ??         90h
    //         0051a765     NOP
    //         0051a766     NOP
    //         0051a767     NOP
    //         0051a768     NOP
    //         0051a769     NOP
    //         0051a76a     NOP
    //         0051a76b     NOP
    //         0051a76c     NOP
    //         0051a76d     NOP
    //         0051a76e     NOP
    //         0051a76f     NOP
}

void TRIBE_Panel_Inven::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TRIBE_Panel_Inven * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              char[20]          Stack[-0x18]   str                       XREF[1]:     0051a7b7(W)  
    //              void *            Stack[-0x20]:4 old_font
    //              long              Stack[-0x28]:4 x
    //                               ?draw@TRIBE_Panel_Inven@@UAEXXZ                              XREF[1]:     00576be8(*)  
    //                               TRIBE_Panel_Inven::draw
    //                              tpnl_inv.cpp:97 (8)
    //         0051a770     SUB        ESP,0x24
    //         0051a773     PUSH       EBX
    //         0051a774     PUSH       EBP
    //         0051a775     PUSH       ESI
    //         0051a776     MOV        ESI,this
    //                              tpnl_inv.cpp:102 (30)
    //         0051a778     XOR        EBX,EBX
    //         0051a77a     PUSH       EDI
    //         0051a77b     CMP        dword ptr [ESI + 0x20],EBX
    //         0051a77e     JZ         LAB_0051aac0
    //         0051a784     CMP        dword ptr [ESI + 0x70],EBX
    //         0051a787     JZ         LAB_0051aac0
    //         0051a78d     CMP        dword ptr [ESI + 0x6c],EBX
    //         0051a790     JZ         LAB_0051aac0
    //                              tpnl_inv.cpp:108 (7)
    //         0051a796     MOV        this,dword ptr [ESI + 0x40]
    //         0051a799     CMP        this,EBX
    //         0051a79b     JZ         LAB_0051a7a6
    //                              tpnl_inv.cpp:109 (9)
    //         0051a79d     MOV        EAX,dword ptr [this->_padding_]
    //         0051a79f     LEA        EDX,[ESI + 0x24]
    //         0051a7a2     PUSH       EDX
    //         0051a7a3     CALL       dword ptr [EAX + 0x34]
    //                               LAB_0051a7a6                                                 XREF[1]:     0051a79b(j)  
    //                              tpnl_inv.cpp:111 (6)
    //         0051a7a6     CMP        dword ptr [ESI + 0xf8],EBX
    //                              tpnl_inv.cpp:114 (6)
    //         0051a7ac     JZ         LAB_0051aac0
    //                              tpnl_inv.cpp:117 (12)
    //         0051a7b2     MOV        EDI,dword ptr [ESI]
    //         0051a7b4     PUSH       EBX
    //         0051a7b5     MOV        this,ESI
    //         0051a7b7     MOV        dword ptr [ESP + str[0]],EDI
    //         0051a7bb     CALL       dword ptr [EDI + 0x28]
    //                              tpnl_inv.cpp:119 (21)
    //         0051a7be     MOV        this,dword ptr [ESI + 0x20]
    //         0051a7c1     PUSH       s_tpnl_inv::draw                                 = "tpnl_inv::draw"
    //         0051a7c6     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0051a7cb     TEST       EAX,EAX
    //         0051a7cd     JZ         LAB_0051aab3
    //                              tpnl_inv.cpp:121 (24)
    //         0051a7d3     MOV        this,dword ptr [ESI + 0x20]
    //         0051a7d6     MOV        EAX,dword ptr [ESI + 0x10c]
    //         0051a7dc     PUSH       EAX
    //         0051a7dd     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051a7e0     PUSH       EDX=>DAT_fffffff8
    //         0051a7e1     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //         0051a7e7     MOV        dword ptr [ESP + 0x18],EAX
    //                              tpnl_inv.cpp:122 (15)
    //         0051a7eb     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a7ee     PUSH       0x1
    //         0051a7f0     MOV        this,dword ptr [EAX + 0x38]
    //         0051a7f3     PUSH       this=>DAT_fffffff8
    //         0051a7f4     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_inv.cpp:124 (3)
    //         0051a7fa     MOV        EAX,dword ptr [ESI + 0xc]
    //                              tpnl_inv.cpp:126 (46)
    //         0051a7fd     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051a803     MOV        EBX,dword ptr [ESI + 0x10]
    //         0051a806     ADD        EAX,0x20
    //         0051a809     MOV        dword ptr [ESP + 0x10],EAX
    //         0051a80d     MOV        EAX,dword ptr [EDX + 0x50]
    //         0051a810     ADD        EBX,0x2
    //         0051a813     FLD        float ptr [EAX + 0x4]
    //         0051a816     CALL       __ftol                                           undefined __ftol()
    //         0051a81b     PUSH       EAX
    //         0051a81c     LEA        this,[ESP + 0x24]
    //         0051a820     PUSH       s_%ld                                            = "%ld"
    //         0051a825     PUSH       this=>DAT_fffffff4
    //         0051a826     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:127 (25)
    //         0051a82b     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a82e     MOV        EDX,dword ptr [ESI + 0x114]
    //         0051a834     MOV        EBP,dword ptr [->GDI32.DLL::SetTextColor]        = 0048b318
    //         0051a83a     ADD        ESP,0xc
    //         0051a83d     MOV        this,dword ptr [EAX + 0x38]
    //         0051a840     PUSH       EDX
    //         0051a841     PUSH       this=>DAT_fffffff8
    //         0051a842     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:128 (47)
    //         0051a844     LEA        EDI,[ESP + 0x20]
    //         0051a848     OR         this,0xffffffff
    //         0051a84b     XOR        EAX,EAX
    //         0051a84d     LEA        EDX,[EBX + 0x1]
    //         0051a850     SCASB.RE   ES:EDI
    //         0051a852     NOT        this
    //         0051a854     DEC        this
    //         0051a855     LEA        EAX,[ESP + 0x20]
    //         0051a859     PUSH       this
    //         0051a85a     MOV        this,dword ptr [ESP + 0x14]
    //         0051a85e     PUSH       EAX=>DAT_fffffff8
    //         0051a85f     MOV        dword ptr [ESP + 0x1c],EDX
    //         0051a863     PUSH       EDX=>DAT_fffffff4
    //         0051a864     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051a867     DEC        this
    //         0051a868     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051a86b     PUSH       this=>DAT_fffffff0
    //         0051a86c     PUSH       EAX
    //         0051a86d     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:129 (16)
    //         0051a873     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051a876     MOV        this,dword ptr [ESI + 0x110]
    //         0051a87c     PUSH       this
    //         0051a87d     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051a880     PUSH       EAX=>DAT_fffffff8
    //         0051a881     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:130 (39)
    //         0051a883     LEA        EDI,[ESP + 0x20]
    //         0051a887     OR         this,0xffffffff
    //         0051a88a     XOR        EAX,EAX
    //         0051a88c     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051a890     SCASB.RE   ES:EDI
    //         0051a892     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a895     NOT        this
    //         0051a897     DEC        this
    //         0051a898     PUSH       this
    //         0051a899     LEA        this,[ESP + 0x24]
    //         0051a89d     PUSH       this=>DAT_fffffff8
    //         0051a89e     MOV        this,dword ptr [EAX + 0x38]
    //         0051a8a1     PUSH       EBX=>DAT_fffffff4
    //         0051a8a2     PUSH       EDX=>DAT_fffffff0
    //         0051a8a3     PUSH       this
    //         0051a8a4     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:132 (3)
    //         0051a8aa     MOV        EAX,dword ptr [ESI + 0xc]
    //                              tpnl_inv.cpp:133 (39)
    //         0051a8ad     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051a8b3     ADD        EAX,0x63
    //         0051a8b6     MOV        dword ptr [ESP + 0x10],EAX
    //         0051a8ba     MOV        EAX,dword ptr [EDX + 0x50]
    //         0051a8bd     FLD        float ptr [EAX]
    //         0051a8bf     CALL       __ftol                                           undefined __ftol()
    //         0051a8c4     PUSH       EAX
    //         0051a8c5     LEA        this,[ESP + 0x24]
    //         0051a8c9     PUSH       s_%ld                                            = "%ld"
    //         0051a8ce     PUSH       this=>DAT_fffffff4
    //         0051a8cf     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:134 (19)
    //         0051a8d4     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a8d7     MOV        EDX,dword ptr [ESI + 0x114]
    //         0051a8dd     ADD        ESP,0xc
    //         0051a8e0     MOV        this,dword ptr [EAX + 0x38]
    //         0051a8e3     PUSH       EDX
    //         0051a8e4     PUSH       this=>DAT_fffffff8
    //         0051a8e5     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:135 (44)
    //         0051a8e7     LEA        EDI,[ESP + 0x20]
    //         0051a8eb     OR         this,0xffffffff
    //         0051a8ee     XOR        EAX,EAX
    //         0051a8f0     LEA        EDX,[ESP + 0x20]
    //         0051a8f4     SCASB.RE   ES:EDI
    //         0051a8f6     MOV        EAX,dword ptr [ESP + 0x14]
    //         0051a8fa     NOT        this
    //         0051a8fc     DEC        this
    //         0051a8fd     PUSH       this
    //         0051a8fe     MOV        this,dword ptr [ESP + 0x14]
    //         0051a902     PUSH       EDX=>DAT_fffffff8
    //         0051a903     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051a906     PUSH       EAX=>DAT_fffffff4
    //         0051a907     DEC        this
    //         0051a908     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051a90b     PUSH       this=>DAT_fffffff0
    //         0051a90c     PUSH       EAX
    //         0051a90d     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:136 (16)
    //         0051a913     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051a916     MOV        this,dword ptr [ESI + 0x110]
    //         0051a91c     PUSH       this
    //         0051a91d     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051a920     PUSH       EAX=>DAT_fffffff8
    //         0051a921     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:137 (39)
    //         0051a923     LEA        EDI,[ESP + 0x20]
    //         0051a927     OR         this,0xffffffff
    //         0051a92a     XOR        EAX,EAX
    //         0051a92c     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051a930     SCASB.RE   ES:EDI
    //         0051a932     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a935     NOT        this
    //         0051a937     DEC        this
    //         0051a938     PUSH       this
    //         0051a939     LEA        this,[ESP + 0x24]
    //         0051a93d     PUSH       this=>DAT_fffffff8
    //         0051a93e     MOV        this,dword ptr [EAX + 0x38]
    //         0051a941     PUSH       EBX=>DAT_fffffff4
    //         0051a942     PUSH       EDX=>DAT_fffffff0
    //         0051a943     PUSH       this
    //         0051a944     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:139 (3)
    //         0051a94a     MOV        EAX,dword ptr [ESI + 0xc]
    //                              tpnl_inv.cpp:140 (42)
    //         0051a94d     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051a953     ADD        EAX,0xa6
    //         0051a958     MOV        dword ptr [ESP + 0x10],EAX
    //         0051a95c     MOV        EAX,dword ptr [EDX + 0x50]
    //         0051a95f     FLD        float ptr [EAX + 0xc]
    //         0051a962     CALL       __ftol                                           undefined __ftol()
    //         0051a967     PUSH       EAX
    //         0051a968     LEA        this,[ESP + 0x24]
    //         0051a96c     PUSH       s_%ld                                            = "%ld"
    //         0051a971     PUSH       this=>DAT_fffffff4
    //         0051a972     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:141 (19)
    //         0051a977     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a97a     MOV        EDX,dword ptr [ESI + 0x114]
    //         0051a980     ADD        ESP,0xc
    //         0051a983     MOV        this,dword ptr [EAX + 0x38]
    //         0051a986     PUSH       EDX
    //         0051a987     PUSH       this=>DAT_fffffff8
    //         0051a988     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:142 (44)
    //         0051a98a     LEA        EDI,[ESP + 0x20]
    //         0051a98e     OR         this,0xffffffff
    //         0051a991     XOR        EAX,EAX
    //         0051a993     LEA        EDX,[ESP + 0x20]
    //         0051a997     SCASB.RE   ES:EDI
    //         0051a999     NOT        this
    //         0051a99b     DEC        this
    //         0051a99c     PUSH       this
    //         0051a99d     PUSH       EDX=>DAT_fffffff8
    //         0051a99e     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0051a9a2     MOV        this,dword ptr [ESP + 0x18]
    //         0051a9a6     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051a9a9     PUSH       EAX=>DAT_fffffff4
    //         0051a9aa     DEC        this
    //         0051a9ab     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051a9ae     PUSH       this=>DAT_fffffff0
    //         0051a9af     PUSH       EAX
    //         0051a9b0     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:143 (16)
    //         0051a9b6     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051a9b9     MOV        this,dword ptr [ESI + 0x110]
    //         0051a9bf     PUSH       this
    //         0051a9c0     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051a9c3     PUSH       EAX=>DAT_fffffff8
    //         0051a9c4     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:144 (39)
    //         0051a9c6     LEA        EDI,[ESP + 0x20]
    //         0051a9ca     OR         this,0xffffffff
    //         0051a9cd     XOR        EAX,EAX
    //         0051a9cf     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051a9d3     SCASB.RE   ES:EDI
    //         0051a9d5     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051a9d8     NOT        this
    //         0051a9da     DEC        this
    //         0051a9db     PUSH       this
    //         0051a9dc     LEA        this,[ESP + 0x24]
    //         0051a9e0     PUSH       this=>DAT_fffffff8
    //         0051a9e1     MOV        this,dword ptr [EAX + 0x38]
    //         0051a9e4     PUSH       EBX=>DAT_fffffff4
    //         0051a9e5     PUSH       EDX=>DAT_fffffff0
    //         0051a9e6     PUSH       this
    //         0051a9e7     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:146 (3)
    //         0051a9ed     MOV        EAX,dword ptr [ESI + 0xc]
    //                              tpnl_inv.cpp:147 (42)
    //         0051a9f0     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051a9f6     ADD        EAX,0xe9
    //         0051a9fb     MOV        dword ptr [ESP + 0x10],EAX
    //         0051a9ff     MOV        EAX,dword ptr [EDX + 0x50]
    //         0051aa02     FLD        float ptr [EAX + 0x8]
    //         0051aa05     CALL       __ftol                                           undefined __ftol()
    //         0051aa0a     PUSH       EAX
    //         0051aa0b     LEA        this,[ESP + 0x24]
    //         0051aa0f     PUSH       s_%ld                                            = "%ld"
    //         0051aa14     PUSH       this=>DAT_fffffff4
    //         0051aa15     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:148 (19)
    //         0051aa1a     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051aa1d     MOV        EDX,dword ptr [ESI + 0x114]
    //         0051aa23     ADD        ESP,0xc
    //         0051aa26     MOV        this,dword ptr [EAX + 0x38]
    //         0051aa29     PUSH       EDX
    //         0051aa2a     PUSH       this=>DAT_fffffff8
    //         0051aa2b     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:149 (44)
    //         0051aa2d     LEA        EDI,[ESP + 0x20]
    //         0051aa31     OR         this,0xffffffff
    //         0051aa34     XOR        EAX,EAX
    //         0051aa36     LEA        EDX,[ESP + 0x20]
    //         0051aa3a     SCASB.RE   ES:EDI
    //         0051aa3c     MOV        EAX,dword ptr [ESP + 0x14]
    //         0051aa40     NOT        this
    //         0051aa42     DEC        this
    //         0051aa43     PUSH       this
    //         0051aa44     MOV        this,dword ptr [ESP + 0x14]
    //         0051aa48     PUSH       EDX=>DAT_fffffff8
    //         0051aa49     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051aa4c     PUSH       EAX=>DAT_fffffff4
    //         0051aa4d     DEC        this
    //         0051aa4e     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051aa51     PUSH       this=>DAT_fffffff0
    //         0051aa52     PUSH       EAX
    //         0051aa53     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:150 (16)
    //         0051aa59     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051aa5c     MOV        this,dword ptr [ESI + 0x110]
    //         0051aa62     PUSH       this
    //         0051aa63     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051aa66     PUSH       EAX=>DAT_fffffff8
    //         0051aa67     CALL       EBP=>GDI32.DLL::SetTextColor
    //                              tpnl_inv.cpp:151 (39)
    //         0051aa69     LEA        EDI,[ESP + 0x20]
    //         0051aa6d     OR         this,0xffffffff
    //         0051aa70     XOR        EAX,EAX
    //         0051aa72     SCASB.RE   ES:EDI
    //         0051aa74     NOT        this
    //         0051aa76     DEC        this
    //         0051aa77     PUSH       this
    //         0051aa78     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051aa7b     MOV        EDX,dword ptr [ESP + 0x14]
    //         0051aa7f     LEA        this,[ESP + 0x24]
    //         0051aa83     PUSH       this=>DAT_fffffff8
    //         0051aa84     MOV        this,dword ptr [EAX + 0x38]
    //         0051aa87     PUSH       EBX=>DAT_fffffff4
    //         0051aa88     PUSH       EDX=>DAT_fffffff0
    //         0051aa89     PUSH       this
    //         0051aa8a     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_inv.cpp:153 (18)
    //         0051aa90     MOV        EAX,dword ptr [ESI + 0x20]
    //         0051aa93     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051aa97     PUSH       EDX
    //         0051aa98     MOV        this,dword ptr [EAX + 0x38]
    //         0051aa9b     PUSH       this=>DAT_fffffff8
    //         0051aa9c     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_inv.cpp:154 (17)
    //         0051aaa2     MOV        this,dword ptr [ESI + 0x20]
    //         0051aaa5     PUSH       s_tpnl_inv::draw                                 = "tpnl_inv::draw"
    //         0051aaaa     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         0051aaaf     MOV        EDI,dword ptr [ESP + 0x1c]
    //                               LAB_0051aab3                                                 XREF[1]:     0051a7cd(j)  
    //                              tpnl_inv.cpp:157 (5)
    //         0051aab3     MOV        this,ESI
    //         0051aab5     CALL       dword ptr [EDI + 0x2c]
    //                              tpnl_inv.cpp:158 (8)
    //         0051aab8     POP        EDI
    //         0051aab9     POP        ESI
    //         0051aaba     POP        EBP
    //         0051aabb     POP        EBX
    //         0051aabc     ADD        ESP,0x24
    //         0051aabf     RET
    //                               LAB_0051aac0                                                 XREF[4]:     0051a77e(j), 0051a787(j), 
    //                                                                                                         0051a790(j), 0051a7ac(j)  
    //                              tpnl_inv.cpp:104 (3)
    //         0051aac0     MOV        dword ptr [ESI + 0x38],EBX
    //                              tpnl_inv.cpp:158 (8)
    //         0051aac3     POP        EDI
    //         0051aac4     POP        ESI
    //         0051aac5     POP        EBP
    //         0051aac6     POP        EBX
    //         0051aac7     ADD        ESP,0x24
    //         0051aaca     RET
    //         0051aacb     ??         90h
    //         0051aacc     NOP
    //         0051aacd     NOP
    //         0051aace     NOP
    //         0051aacf     NOP
    return;
}

long TRIBE_Panel_Inven::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TRIBE_Panel_Inven * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051ab5b(W), 0051ab5f(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0051ab46(W), 0051ab81(W), 0051ab89(R)  
    //              int               Stack[-0xc]:4  changed
    //                               ?handle_idle@TRIBE_Panel_Inven@@UAEJXZ                       XREF[1]:     00576c04(*)  
    //                               TRIBE_Panel_Inven::handle_idle
    //                              tpnl_inv.cpp:164 (9)
    //         0051aad0     SUB        ESP,0x8
    //         0051aad3     PUSH       EBX
    //         0051aad4     PUSH       EBP
    //         0051aad5     PUSH       ESI
    //         0051aad6     PUSH       EDI
    //         0051aad7     MOV        EBX,this
    //                              tpnl_inv.cpp:168 (5)
    //         0051aad9     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              tpnl_inv.cpp:170 (29)
    //         0051aade     MOV        EAX,[rge_base_game]                              = 00000000
    //         0051aae3     MOV        EAX,dword ptr [EAX + 0x1b0]
    //         0051aae9     CMP        EAX,0x4
    //         0051aaec     JZ         LAB_0051ab01
    //         0051aaee     CMP        EAX,0x6
    //         0051aaf1     JZ         LAB_0051ab01
    //         0051aaf3     CMP        EAX,0x7
    //         0051aaf6     JZ         LAB_0051ab01
    //         0051aaf8     CMP        EAX,0x5
    //                              tpnl_inv.cpp:171 (6)
    //         0051aafb     JNZ        LAB_0051abdb
    //                               LAB_0051ab01                                                 XREF[3]:     0051aaec(j), 0051aaf1(j), 
    //                                                                                                         0051aaf6(j)  
    //                              tpnl_inv.cpp:173 (34)
    //         0051ab01     PUSH       0xad
    //         0051ab06     PUSH       s_C:\msdev\work\age1_x1\tpnl_inv.c               = "C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp"
    //         0051ab0b     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0051ab10     MOV        EDX,dword ptr [EBX + 0x104]
    //         0051ab16     MOV        this,dword ptr [EBX + 0x108]
    //         0051ab1c     SUB        EAX,EDX
    //         0051ab1e     ADD        ESP,0x8
    //         0051ab21     CMP        EAX,this
    //                              tpnl_inv.cpp:174 (6)
    //         0051ab23     JC         LAB_0051abdb
    //                              tpnl_inv.cpp:176 (17)
    //         0051ab29     PUSH       0x5
    //         0051ab2b     PUSH       0xba
    //         0051ab30     PUSH       0xba
    //         0051ab35     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              tpnl_inv.cpp:178 (5)
    //         0051ab3a     XOR        EDI,EDI
    //         0051ab3c     ADD        ESP,0xc
    //                              tpnl_inv.cpp:179 (13)
    //         0051ab3f     CMP        word ptr [EBX + 0xfc],DI
    //         0051ab46     MOV        dword ptr [ESP + local_8],EDI
    //         0051ab4a     JLE        LAB_0051ab89
    //                              tpnl_inv.cpp:181 (53)
    //         0051ab4c     MOV        this,dword ptr [EBX + 0xf8]
    //         0051ab52     MOV        EBP,dword ptr [EBX + 0x100]
    //         0051ab58     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051ab5b     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_0051ab5f                                                 XREF[1]:     0051ab7d(j)  
    //         0051ab5f     MOV        EAX,dword ptr [ESP + local_4]
    //         0051ab63     MOVSX      ESI,DI
    //         0051ab66     FLD        float ptr [EAX + ESI*0x4]
    //         0051ab69     CALL       __ftol                                           undefined __ftol()
    //         0051ab6e     CMP        AX,word ptr [EBP + ESI*0x2]
    //         0051ab73     JNZ        LAB_0051ab81
    //         0051ab75     INC        EDI
    //         0051ab76     CMP        DI,word ptr [EBX + 0xfc]
    //         0051ab7d     JL         LAB_0051ab5f
    //         0051ab7f     JMP        LAB_0051ab89
    //                               LAB_0051ab81                                                 XREF[1]:     0051ab73(j)  
    //                              tpnl_inv.cpp:183 (8)
    //         0051ab81     MOV        dword ptr [ESP + local_8],0x1
    //                               LAB_0051ab89                                                 XREF[2]:     0051ab4a(j), 0051ab7f(j)  
    //                              tpnl_inv.cpp:187 (8)
    //         0051ab89     MOV        EAX,dword ptr [ESP + local_8]
    //         0051ab8d     TEST       EAX,EAX
    //         0051ab8f     JZ         LAB_0051abb2
    //                              tpnl_inv.cpp:189 (17)
    //         0051ab91     PUSH       0x5
    //         0051ab93     PUSH       0x16
    //         0051ab95     PUSH       0xba
    //         0051ab9a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //         0051ab9f     ADD        ESP,0xc
    //                              tpnl_inv.cpp:190 (7)
    //         0051aba2     MOV        this,EBX
    //         0051aba4     CALL       TRIBE_Panel_Inven::save_info                     void save_info(TRIBE_Panel_Inven * this)
    //                              tpnl_inv.cpp:191 (9)
    //         0051aba9     MOV        EDX,dword ptr [EBX]
    //         0051abab     PUSH       0x1
    //         0051abad     MOV        this,EBX
    //         0051abaf     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0051abb2                                                 XREF[1]:     0051ab8f(j)  
    //                              tpnl_inv.cpp:194 (24)
    //         0051abb2     PUSH       0xc2
    //         0051abb7     PUSH       s_C:\msdev\work\age1_x1\tpnl_inv.c               = "C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp"
    //         0051abbc     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0051abc1     ADD        ESP,0x8
    //         0051abc4     MOV        dword ptr [EBX + 0x104],EAX
    //                              tpnl_inv.cpp:195 (17)
    //         0051abca     PUSH       0x5
    //         0051abcc     PUSH       offset DAT_fffffff8
    //         0051abce     PUSH       offset DAT_fffffff4
    //         0051abd3     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //         0051abd8     ADD        ESP,0xc
    //                               LAB_0051abdb                                                 XREF[2]:     0051aafb(j), 0051ab23(j)  
    //                              tpnl_inv.cpp:198 (10)
    //         0051abdb     POP        EDI
    //         0051abdc     POP        ESI
    //         0051abdd     POP        EBP
    //         0051abde     XOR        EAX,EAX
    //         0051abe0     POP        EBX
    //         0051abe1     ADD        ESP,0x8
    //         0051abe4     RET
    //         0051abe5     ??         90h
    //         0051abe6     NOP
    //         0051abe7     NOP
    //         0051abe8     NOP
    //         0051abe9     NOP
    //         0051abea     NOP
    //         0051abeb     NOP
    //         0051abec     NOP
    //         0051abed     NOP
    //         0051abee     NOP
    //         0051abef     NOP
    return 0;
}

void TRIBE_Panel_Inven::set_player(TRIBE_Player* param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_player(TRIBE_Panel_Inven * this, TRIBE_Player * 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              TRIBE_Player *    Stack[0x4]:4   param_1                   XREF[1]:     0051abf0(R)  
    //                               ?set_player@TRIBE_Panel_Inven@@QAEXPAVTRIBE_Player@@@Z       XREF[2]:     player_changed:00498a9d(c), 
    //                               TRIBE_Panel_Inven::set_player                                             TRIBE_Panel_Inven:0051a670(c)  
    //                              tpnl_inv.cpp:204 (13)
    //         0051abf0     MOV        EAX,dword ptr [ESP + param_1]
    //         0051abf4     PUSH       ESI
    //         0051abf5     MOV        ESI,this
    //         0051abf7     MOV        dword ptr [ESI + 0xf8],EAX
    //                              tpnl_inv.cpp:206 (5)
    //         0051abfd     CALL       TRIBE_Panel_Inven::save_info                     void save_info(TRIBE_Panel_Inven * this)
    //                              tpnl_inv.cpp:207 (9)
    //         0051ac02     MOV        EDX,dword ptr [ESI]
    //         0051ac04     PUSH       0x1
    //         0051ac06     MOV        this,ESI
    //         0051ac08     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_inv.cpp:208 (4)
    //         0051ac0b     POP        ESI
    //         0051ac0c     RET        0x4
    //         0051ac0f     ??         90h
    return;
}

void TRIBE_Panel_Inven::save_info() {
    /* TODO: Stub */
    //                              void __thiscall save_info(TRIBE_Panel_Inven * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //                               ?save_info@TRIBE_Panel_Inven@@IAEXXZ                         XREF[2]:     handle_idle:0051aba4(c), 
    //                               TRIBE_Panel_Inven::save_info                                              set_player:0051abfd(c)  
    //                              tpnl_inv.cpp:214 (4)
    //         0051ac10     PUSH       ESI
    //         0051ac11     MOV        ESI,this
    //         0051ac13     PUSH       EDI
    //                              tpnl_inv.cpp:217 (31)
    //         0051ac14     XOR        EDI,EDI
    //         0051ac16     MOV        EAX,dword ptr [ESI + 0x100]
    //         0051ac1c     CMP        EAX,EDI
    //         0051ac1e     JZ         LAB_0051ac46
    //         0051ac20     MOV        this,dword ptr [ESI + 0xf8]
    //         0051ac26     MOV        DX,word ptr [ESI + 0xfc]
    //         0051ac2d     CMP        DX,word ptr [ECX + this->_padding_]
    //         0051ac31     JZ         LAB_0051ac6b
    //                              tpnl_inv.cpp:219 (4)
    //         0051ac33     CMP        EAX,EDI
    //         0051ac35     JZ         LAB_0051ac46
    //                              tpnl_inv.cpp:221 (9)
    //         0051ac37     PUSH       EAX
    //         0051ac38     CALL       free                                             undefined free()
    //         0051ac3d     ADD        ESP,0x4
    //                              tpnl_inv.cpp:222 (6)
    //         0051ac40     MOV        dword ptr [ESI + 0x100],EDI
    //                               LAB_0051ac46                                                 XREF[2]:     0051ac1e(j), 0051ac35(j)  
    //                              tpnl_inv.cpp:224 (6)
    //         0051ac46     MOV        EAX,dword ptr [ESI + 0xf8]
    //                              tpnl_inv.cpp:225 (31)
    //         0051ac4c     PUSH       0x2
    //         0051ac4e     MOV        AX,word ptr [EAX + 0x4c]
    //         0051ac52     MOVSX      this,AX
    //         0051ac55     PUSH       this
    //         0051ac56     MOV        word ptr [ESI + 0xfc],AX
    //         0051ac5d     CALL       calloc                                           undefined calloc()
    //         0051ac62     ADD        ESP,0x8
    //         0051ac65     MOV        dword ptr [ESI + 0x100],EAX
    //                               LAB_0051ac6b                                                 XREF[1]:     0051ac31(j)  
    //                              tpnl_inv.cpp:228 (9)
    //         0051ac6b     CMP        word ptr [ESI + 0xfc],DI
    //         0051ac72     JLE        LAB_0051ac9c
    //                               LAB_0051ac74                                                 XREF[1]:     0051ac9a(j)  
    //                              tpnl_inv.cpp:229 (40)
    //         0051ac74     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051ac7a     MOV        EAX,dword ptr [EDX + 0x50]
    //         0051ac7d     FLD        float ptr [EAX + EDI*0x4]
    //         0051ac80     CALL       __ftol                                           undefined __ftol()
    //         0051ac85     MOV        this,dword ptr [ESI + 0x100]
    //         0051ac8b     INC        EDI
    //         0051ac8c     MOV        word ptr [this->_padding_ + EDI*0x2 + -0x2],AX
    //         0051ac91     MOVSX      EDX,word ptr [ESI + 0xfc]
    //         0051ac98     CMP        EDI,EDX
    //         0051ac9a     JL         LAB_0051ac74
    //                               LAB_0051ac9c                                                 XREF[1]:     0051ac72(j)  
    //                              tpnl_inv.cpp:230 (3)
    //         0051ac9c     POP        EDI
    //         0051ac9d     POP        ESI
    //         0051ac9e     RET
    //         0051ac9f     ??         90h
    return;
}

uchar TRIBE_Panel_Inven::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    /* TODO: Stub */
    //                              uchar __thiscall get_help_info(TRIBE_Panel_Inven * this, char * * pa
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              char * *          Stack[0x4]:4   param_1
    //              long *            Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0051acb6(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0051acb2(R)  
    //                               ?get_help_info@TRIBE_Panel_Inven@@UAEEAAPADAAJJJ@Z           XREF[1]:     00576c84(*)  
    //                               TRIBE_Panel_Inven::get_help_info
    //                              tpnl_inv.cpp:236 (4)
    //         0051aca0     PUSH       ESI
    //         0051aca1     MOV        ESI,this
    //         0051aca3     PUSH       EDI
    //                              tpnl_inv.cpp:237 (7)
    //         0051aca4     MOV        EAX,dword ptr [ESI + 0x6c]
    //         0051aca7     TEST       EAX,EAX
    //         0051aca9     JNZ        LAB_0051acb2
    //                              tpnl_inv.cpp:238 (2)
    //         0051acab     XOR        AL,AL
    //                              tpnl_inv.cpp:265 (5)
    //         0051acad     POP        EDI
    //         0051acae     POP        ESI
    //         0051acaf     RET        0x10
    //                               LAB_0051acb2                                                 XREF[1]:     0051aca9(j)  
    //                              tpnl_inv.cpp:240 (24)
    //         0051acb2     MOV        this,dword ptr [ESP + param_4]
    //         0051acb6     MOV        EDI,dword ptr [ESP + param_3]
    //         0051acba     MOV        EAX,dword ptr [ESI]
    //         0051acbc     PUSH       this
    //         0051acbd     PUSH       EDI
    //         0051acbe     MOV        this,ESI
    //         0051acc0     CALL       dword ptr [EAX + 0xbc]
    //         0051acc6     TEST       EAX,EAX
    //         0051acc8     JNZ        LAB_0051acd1
    //                              tpnl_inv.cpp:241 (2)
    //         0051acca     XOR        AL,AL
    //                              tpnl_inv.cpp:265 (5)
    //         0051accc     POP        EDI
    //         0051accd     POP        ESI
    //         0051acce     RET        0x10
    //                               LAB_0051acd1                                                 XREF[1]:     0051acc8(j)  
    //                              tpnl_inv.cpp:243 (10)
    //         0051acd1     MOV        EAX,dword ptr [ESI + 0xc]
    //         0051acd4     LEA        EDX,[EAX + 0x37]
    //         0051acd7     CMP        EDI,EDX
    //         0051acd9     JGE        LAB_0051ad1a
    //                              tpnl_inv.cpp:245 (43)
    //         0051acdb     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0051ace1     MOV        this,dword ptr [EAX + 0x50]
    //         0051ace4     FLD        float ptr [ECX + this->_padding_]
    //         0051ace7     CALL       __ftol                                           undefined __ftol()
    //         0051acec     PUSH       EAX
    //         0051aced     PUSH       offset DAT_fffffff8
    //         0051acf2     MOV        this,ESI
    //         0051acf4     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051acf9     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051acfd     PUSH       EAX=>DAT_fffffff8
    //         0051acfe     MOV        EAX,dword ptr [EDX]
    //         0051ad00     PUSH       EAX=>DAT_fffffff4
    //         0051ad01     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:246 (7)
    //         0051ad06     MOV        this,dword ptr [ESP + 0x1c]
    //         0051ad0a     ADD        ESP,0xc
    //                              tpnl_inv.cpp:264 (8)
    //         0051ad0d     MOV        AL,0x1
    //         0051ad0f     MOV        dword ptr [this->_padding_],0xffffffff
    //                              tpnl_inv.cpp:265 (5)
    //         0051ad15     POP        EDI
    //         0051ad16     POP        ESI
    //         0051ad17     RET        0x10
    //                               LAB_0051ad1a                                                 XREF[1]:     0051acd9(j)  
    //                              tpnl_inv.cpp:248 (7)
    //         0051ad1a     LEA        EDX,[EAX + 0x6e]
    //         0051ad1d     CMP        EDI,EDX
    //         0051ad1f     JGE        LAB_0051ad5f
    //                              tpnl_inv.cpp:250 (42)
    //         0051ad21     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0051ad27     MOV        this,dword ptr [EAX + 0x50]
    //         0051ad2a     FLD        float ptr [this->_padding_]
    //         0051ad2c     CALL       __ftol                                           undefined __ftol()
    //         0051ad31     PUSH       EAX
    //         0051ad32     PUSH       offset DAT_fffffff8
    //         0051ad37     MOV        this,ESI
    //         0051ad39     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051ad3e     MOV        EDX,dword ptr [ESP + 0x10]
    //         0051ad42     PUSH       EAX=>DAT_fffffff8
    //         0051ad43     MOV        EAX,dword ptr [EDX]
    //         0051ad45     PUSH       EAX=>DAT_fffffff4
    //         0051ad46     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:251 (7)
    //         0051ad4b     MOV        this,dword ptr [ESP + 0x1c]
    //         0051ad4f     ADD        ESP,0xc
    //                              tpnl_inv.cpp:264 (8)
    //         0051ad52     MOV        AL,0x1
    //         0051ad54     MOV        dword ptr [this->_padding_],0xffffffff
    //                              tpnl_inv.cpp:265 (5)
    //         0051ad5a     POP        EDI
    //         0051ad5b     POP        ESI
    //         0051ad5c     RET        0x10
    //                               LAB_0051ad5f                                                 XREF[1]:     0051ad1f(j)  
    //                              tpnl_inv.cpp:253 (9)
    //         0051ad5f     ADD        EAX,0xa5
    //         0051ad64     CMP        EDI,EAX
    //         0051ad66     JGE        LAB_0051ada7
    //                              tpnl_inv.cpp:255 (43)
    //         0051ad68     MOV        EDX,dword ptr [ESI + 0xf8]
    //         0051ad6e     MOV        EAX,dword ptr [EDX + 0x50]
    //         0051ad71     FLD        float ptr [EAX + 0xc]
    //         0051ad74     CALL       __ftol                                           undefined __ftol()
    //         0051ad79     PUSH       EAX
    //         0051ad7a     PUSH       offset DAT_fffffff8
    //         0051ad7f     MOV        this,ESI
    //         0051ad81     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051ad86     MOV        this,dword ptr [ESP + 0x10]
    //         0051ad8a     PUSH       EAX=>DAT_fffffff8
    //         0051ad8b     MOV        EDX,dword ptr [this->_padding_]
    //         0051ad8d     PUSH       EDX=>DAT_fffffff4
    //         0051ad8e     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:256 (13)
    //         0051ad93     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0051ad97     ADD        ESP,0xc
    //         0051ad9a     MOV        dword ptr [EAX],0xffffffff
    //                              tpnl_inv.cpp:264 (2)
    //         0051ada0     MOV        AL,0x1
    //                              tpnl_inv.cpp:265 (5)
    //         0051ada2     POP        EDI
    //         0051ada3     POP        ESI
    //         0051ada4     RET        0x10
    //                               LAB_0051ada7                                                 XREF[1]:     0051ad66(j)  
    //                              tpnl_inv.cpp:260 (43)
    //         0051ada7     MOV        this,dword ptr [ESI + 0xf8]
    //         0051adad     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051adb0     FLD        float ptr [EDX + 0x8]
    //         0051adb3     CALL       __ftol                                           undefined __ftol()
    //         0051adb8     PUSH       EAX
    //         0051adb9     PUSH       offset DAT_fffffff8
    //         0051adbe     MOV        this,ESI
    //         0051adc0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0051adc5     PUSH       EAX=>DAT_fffffff8
    //         0051adc6     MOV        EAX,dword ptr [ESP + 0x14]
    //         0051adca     MOV        this,dword ptr [EAX]
    //         0051adcc     PUSH       this=>DAT_fffffff4
    //         0051adcd     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_inv.cpp:261 (7)
    //         0051add2     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051add6     ADD        ESP,0xc
    //                              tpnl_inv.cpp:264 (2)
    //         0051add9     MOV        AL,0x1
    //                              tpnl_inv.cpp:265 (11)
    //         0051addb     POP        EDI
    //         0051addc     MOV        dword ptr [EDX],0xffffffff
    //         0051ade2     POP        ESI
    //         0051ade3     RET        0x10
    //         0051ade6     ??         90h
    //         0051ade7     NOP
    //         0051ade8     NOP
    //         0051ade9     NOP
    //         0051adea     NOP
    //         0051adeb     NOP
    //         0051adec     NOP
    //         0051aded     NOP
    //         0051adee     NOP
    //         0051adef     NOP
    //                              * public: __thiscall TRIBE_Panel_Object::TRIBE_Panel_Object(class TDrawArea *,class TPanel *,void *,... *
    //                              undefined __thiscall TRIBE_Panel_Object(TRIBE_Panel_Object * this, T
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0051af33(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0051ae42(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[3]:     0051ae14(R), 0051af6e(W), 0051afd3(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0051ae18(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0051ae1c(R)  
    //              TShape *          Stack[0x18]:4  param_6                   XREF[1]:     0051ae2c(R)  
    //              TShape * *        Stack[0x1c]:4  param_7                   XREF[1]:     0051ae38(R)  
    //              TRIBE_Player *    Stack[0x20]:4  param_8                   XREF[1]:     0051af58(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0051af3c(W), 0051af74(W), 0051af92(W), 0051afd9(W), 
    //                                                                                     0051aff7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051b02e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051ae0b(W)  
    //                               ??0TRIBE_Panel_Object@@QAE@PAVTDrawArea@@PAVTPanel@@PAXJJPA  XREF[2]:     TRIBE_Screen_Game:004944cc(c), 
    //                               TRIBE_Panel_Object::TRIBE_Panel_Object                                    TRIBE_Scenario_Editor_Panel_Object
    //                              tpnl_obj.cpp:49 (36)
    //         0051adf0     PUSH       -0x1
    //         0051adf2     PUSH       FUN_0056136e
    //         0051adf7     MOV        EAX,FS:[0x0]
    //         0051adfd     PUSH       EAX
    //         0051adfe     MOV        dword ptr FS:[0x0],ESP
    //         0051ae05     PUSH       this
    //         0051ae06     PUSH       EBX
    //         0051ae07     PUSH       ESI
    //         0051ae08     MOV        ESI,this
    //         0051ae0a     PUSH       EDI
    //         0051ae0b     MOV        dword ptr [ESP + local_10],ESI
    //         0051ae0f     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //                              tpnl_obj.cpp:50 (4)
    //         0051ae14     MOV        EAX,dword ptr [ESP + param_3]
    //                              tpnl_obj.cpp:51 (4)
    //         0051ae18     MOV        this,dword ptr [ESP + param_4]
    //                              tpnl_obj.cpp:52 (16)
    //         0051ae1c     MOV        EDX,dword ptr [ESP + param_5]
    //         0051ae20     MOV        dword ptr [ESI],TRIBE_Panel_Object::`vftable'    = 0051b050
    //         0051ae26     MOV        dword ptr [ESI + 0xf4],EAX
    //                              tpnl_obj.cpp:56 (12)
    //         0051ae2c     MOV        EAX,dword ptr [ESP + param_6]
    //         0051ae30     XOR        EBX,EBX
    //         0051ae32     MOV        dword ptr [ESI + 0xf8],this
    //                              tpnl_obj.cpp:57 (10)
    //         0051ae38     MOV        this,dword ptr [ESP + param_7]
    //         0051ae3c     MOV        dword ptr [ESI + 0xfc],EDX
    //                              tpnl_obj.cpp:95 (263)
    //         0051ae42     MOV        EDX,dword ptr [ESP + param_2]
    //         0051ae46     MOV        dword ptr [ESI + 0x100],EBX
    //         0051ae4c     MOV        dword ptr [ESI + 0x104],EBX
    //         0051ae52     MOV        dword ptr [ESI + 0x108],EAX
    //         0051ae58     MOV        dword ptr [ESI + 0x10c],this
    //         0051ae5e     PUSH       EBX
    //         0051ae5f     LEA        EDI,[ESI + 0x1ec]
    //         0051ae65     MOV        this,0x9
    //         0051ae6a     XOR        EAX,EAX
    //         0051ae6c     PUSH       EBX
    //         0051ae6d     MOV        dword ptr [ESI + 0x110],EBX
    //         0051ae73     MOV        dword ptr [ESI + 0x114],EBX
    //         0051ae79     MOV        dword ptr [ESI + 0x118],EBX
    //         0051ae7f     MOV        dword ptr [ESI + 0x11c],0x1f4
    //         0051ae89     MOV        byte ptr [ESI + 0x120],0x1
    //         0051ae90     MOV        dword ptr [ESI + 0x124],EBX
    //         0051ae96     MOV        word ptr [ESI + 0x12c],0xffff
    //         0051ae9f     MOV        dword ptr [ESI + 0x130],EBX
    //         0051aea5     MOV        byte ptr [ESI + 0x134],BL
    //         0051aeab     MOV        dword ptr [ESI + 0x138],EBX
    //         0051aeb1     MOV        dword ptr [ESI + 0x13c],EBX
    //         0051aeb7     MOV        dword ptr [ESI + 0x14c],EBX
    //         0051aebd     MOV        word ptr [ESI + 0x150],BX
    //         0051aec4     MOV        word ptr [ESI + 0x152],BX
    //         0051aecb     MOV        word ptr [ESI + 0x154],BX
    //         0051aed2     MOV        dword ptr [ESI + 0x158],EBX
    //         0051aed8     MOV        dword ptr [ESI + 0x15c],EBX
    //         0051aede     MOV        word ptr [ESI + 0x160],BX
    //         0051aee5     MOV        word ptr [ESI + 0x162],BX
    //         0051aeec     MOV        word ptr [ESI + 0x164],BX
    //         0051aef3     MOV        byte ptr [ESI + 0x166],BL
    //         0051aef9     MOV        byte ptr [ESI + 0x1ca],BL
    //         0051aeff     MOV        dword ptr [ESI + 0x1cc],EBX
    //         0051af05     MOV        dword ptr [ESI + 0x1d0],EBX
    //         0051af0b     MOV        dword ptr [ESI + 0x1d4],EBX
    //         0051af11     MOV        dword ptr [ESI + 0x1d8],EBX
    //         0051af17     MOV        byte ptr [ESI + 0x1dc],BL
    //         0051af1d     MOV        dword ptr [ESI + 0x1e0],EBX
    //         0051af23     MOV        byte ptr [ESI + 0x1e8],BL
    //         0051af29     MOV        dword ptr [ESI + 0x210],EBX
    //         0051af2f     PUSH       EBX
    //         0051af30     PUSH       EBX
    //         0051af31     STOSD.REP  ES:EDI
    //         0051af33     MOV        EAX,dword ptr [ESP + param_1]
    //         0051af37     PUSH       EBX
    //         0051af38     PUSH       EDX
    //         0051af39     PUSH       EAX
    //         0051af3a     MOV        this,ESI
    //         0051af3c     MOV        dword ptr [ESP + local_4],EBX
    //         0051af40     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //         0051af45     TEST       EAX,EAX
    //         0051af47     JNZ        LAB_0051af58
    //                              tpnl_obj.cpp:97 (10)
    //         0051af49     MOV        dword ptr [ESI + 0xd8],0x1
    //                              tpnl_obj.cpp:98 (5)
    //         0051af53     JMP        LAB_0051b02e
    //                               LAB_0051af58                                                 XREF[1]:     0051af47(j)  
    //                              tpnl_obj.cpp:101 (12)
    //         0051af58     MOV        this,dword ptr [ESP + param_8]
    //         0051af5c     PUSH       this
    //         0051af5d     MOV        this,ESI
    //         0051af5f     CALL       TRIBE_Panel_Object::set_player                   void set_player(TRIBE_Panel_Object * this, TR
    //                              tpnl_obj.cpp:103 (44)
    //         0051af64     PUSH       0x20
    //         0051af66     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0051af6b     ADD        ESP,0x4
    //         0051af6e     MOV        dword ptr [ESP + param_3],EAX
    //         0051af72     CMP        EAX,EBX
    //         0051af74     MOV        byte ptr [ESP + local_4],0x1
    //         0051af79     JZ         LAB_0051af8e
    //         0051af7b     PUSH       0xc639
    //         0051af80     PUSH       s_health.shp                                     = "health.shp"
    //         0051af85     MOV        this,EAX
    //         0051af87     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0051af8c     JMP        LAB_0051af90
    //                               LAB_0051af8e                                                 XREF[1]:     0051af79(j)  
    //         0051af8e     XOR        EAX,EAX
    //                               LAB_0051af90                                                 XREF[1]:     0051af8c(j)  
    //                              tpnl_obj.cpp:104 (25)
    //         0051af90     CMP        EAX,EBX
    //         0051af92     MOV        byte ptr [ESP + local_4],BL
    //         0051af96     MOV        dword ptr [ESI + 0x100],EAX
    //         0051af9c     JZ         LAB_0051afc9
    //         0051af9e     MOV        this,EAX
    //         0051afa0     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0051afa5     TEST       EAX,EAX
    //         0051afa7     JNZ        LAB_0051afc9
    //                              tpnl_obj.cpp:106 (26)
    //         0051afa9     MOV        EDI,dword ptr [ESI + 0x100]
    //         0051afaf     CMP        EDI,EBX
    //         0051afb1     JZ         LAB_0051afc3
    //         0051afb3     MOV        this,EDI
    //         0051afb5     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051afba     PUSH       EDI
    //         0051afbb     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051afc0     ADD        ESP,0x4
    //                               LAB_0051afc3                                                 XREF[1]:     0051afb1(j)  
    //                              tpnl_obj.cpp:107 (6)
    //         0051afc3     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0051afc9                                                 XREF[2]:     0051af9c(j), 0051afa7(j)  
    //                              tpnl_obj.cpp:110 (44)
    //         0051afc9     PUSH       0x20
    //         0051afcb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0051afd0     ADD        ESP,0x4
    //         0051afd3     MOV        dword ptr [ESP + param_3],EAX
    //         0051afd7     CMP        EAX,EBX
    //         0051afd9     MOV        byte ptr [ESP + local_4],0x2
    //         0051afde     JZ         LAB_0051aff3
    //         0051afe0     PUSH       0xc62b
    //         0051afe5     PUSH       s_itemicon.shp                                   = "itemicon.shp"
    //         0051afea     MOV        this,EAX
    //         0051afec     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0051aff1     JMP        LAB_0051aff5
    //                               LAB_0051aff3                                                 XREF[1]:     0051afde(j)  
    //         0051aff3     XOR        EAX,EAX
    //                               LAB_0051aff5                                                 XREF[1]:     0051aff1(j)  
    //                              tpnl_obj.cpp:111 (25)
    //         0051aff5     CMP        EAX,EBX
    //         0051aff7     MOV        byte ptr [ESP + local_4],BL
    //         0051affb     MOV        dword ptr [ESI + 0x104],EAX
    //         0051b001     JZ         LAB_0051b02e
    //         0051b003     MOV        this,EAX
    //         0051b005     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0051b00a     TEST       EAX,EAX
    //         0051b00c     JNZ        LAB_0051b02e
    //                              tpnl_obj.cpp:113 (26)
    //         0051b00e     MOV        EDI,dword ptr [ESI + 0x104]
    //         0051b014     CMP        EDI,EBX
    //         0051b016     JZ         LAB_0051b028
    //         0051b018     MOV        this,EDI
    //         0051b01a     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051b01f     PUSH       EDI
    //         0051b020     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051b025     ADD        ESP,0x4
    //                               LAB_0051b028                                                 XREF[1]:     0051b016(j)  
    //                              tpnl_obj.cpp:114 (6)
    //         0051b028     MOV        dword ptr [ESI + 0x104],EBX
    //                               LAB_0051b02e                                                 XREF[3]:     0051af53(j), 0051b001(j), 
    //                                                                                                         0051b00c(j)  
    //                              tpnl_obj.cpp:116 (22)
    //         0051b02e     MOV        this,dword ptr [ESP + local_c]
    //         0051b032     MOV        EAX,ESI
    //         0051b034     POP        EDI
    //         0051b035     POP        ESI
    //         0051b036     MOV        dword ptr FS:[0x0],this
    //         0051b03d     POP        EBX
    //         0051b03e     ADD        ESP,0x10
    //         0051b041     RET        0x20
    //         0051b044     ??         90h
    //         0051b045     NOP
    //         0051b046     NOP
    //         0051b047     NOP
    //         0051b048     NOP
    //         0051b049     NOP
    //         0051b04a     NOP
    //         0051b04b     NOP
    //         0051b04c     NOP
    //         0051b04d     NOP
    //         0051b04e     NOP
    //         0051b04f     NOP
    return 0;
}

TRIBE_Panel_Inven::TRIBE_Panel_Inven(TDrawArea* param_1, TPanel* param_2, void* param_3, TRIBE_Player* param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

