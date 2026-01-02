#include "../common.h"
#include "tpnl_txl.h"

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* param_1, TPanel* param_2, void* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Panel_Text_Line(TRIBE_Panel_Text_Line * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Panel_Te    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00520dbd(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00520d96(R)
//              void *            Stack[0xc]:4   param_3                   XREF[1]:     00520d92(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00520da6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00520dde(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00520d89(W)
//                               ??0TRIBE_Panel_Text_Line@@QAE@PAVTDrawArea@@PAVTPanel@@PAX@Z
//                               TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line
//                              tpnl_txl.cpp:23 (34)
//         00520d70     PUSH       -0x1
//         00520d72     PUSH       FUN_00561548
//         00520d77     MOV        EAX,FS:[0x0]
//         00520d7d     PUSH       EAX
//         00520d7e     MOV        dword ptr FS:[0x0],ESP
//         00520d85     PUSH       this
//         00520d86     PUSH       ESI
//         00520d87     MOV        ESI,this
//         00520d89     MOV        dword ptr [ESP + local_10],ESI
//         00520d8d     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
//                              tpnl_txl.cpp:24 (4)
//         00520d92     MOV        this,dword ptr [ESP + param_3]
//                              tpnl_txl.cpp:29 (62)
//         00520d96     MOV        EDX,dword ptr [ESP + param_2]
//         00520d9a     XOR        EAX,EAX
//         00520d9c     MOV        dword ptr [ESI + 0xf4],this
//         00520da2     PUSH       EAX
//         00520da3     PUSH       EAX
//         00520da4     PUSH       EAX
//         00520da5     PUSH       EAX
//         00520da6     MOV        dword ptr [ESP + local_4],EAX
//         00520daa     MOV        byte ptr [ESI + 0xf8],AL
//         00520db0     MOV        byte ptr [ESI + 0xf9],AL
//         00520db6     MOV        dword ptr [ESI + 0x1c4],EAX
//         00520dbc     PUSH       EAX
//         00520dbd     MOV        EAX,dword ptr [ESP + param_1]
//         00520dc1     PUSH       EDX
//         00520dc2     PUSH       EAX
//         00520dc3     MOV        this,ESI
//         00520dc5     MOV        dword ptr [ESI],TRIBE_Panel_Text_Line::`vftable' = 00520e00
//         00520dcb     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
//         00520dd0     TEST       EAX,EAX
//         00520dd2     JNZ        LAB_00520dde
//                              tpnl_txl.cpp:31 (10)
//         00520dd4     MOV        dword ptr [ESI + 0xd8],0x1
//                               LAB_00520dde                                                 XREF[1]:     00520dd2(j)
//                              tpnl_txl.cpp:34 (20)
//         00520dde     MOV        this,dword ptr [ESP + local_c]
//         00520de2     MOV        EAX,ESI
//         00520de4     MOV        dword ptr FS:[0x0],this
//         00520deb     POP        ESI
//         00520dec     ADD        ESP,0x10
//         00520def     RET        0xc
//         00520df2     ??         90h
//         00520df3     NOP
//         00520df4     NOP
//         00520df5     NOP
//         00520df6     NOP
//         00520df7     NOP
//         00520df8     NOP
//         00520df9     NOP
//         00520dfa     NOP
//         00520dfb     NOP
//         00520dfc     NOP
//         00520dfd     NOP
//         00520dfe     NOP
//         00520dff     NOP
}

void TRIBE_Panel_Text_Line::set_info(uchar param_1, char* param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall set_info(TRIBE_Panel_Text_Line * this, uchar param_1
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Te    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00520e30(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     00520e40(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     00520e7d(R), 00520eb9(R)
//                               ?set_info@TRIBE_Panel_Text_Line@@QAEXEPADJ@Z
//                               TRIBE_Panel_Text_Line::set_info
//                              tpnl_txl.cpp:40 (91)
//         00520e30     MOV        DL,byte ptr [ESP + param_1]
//         00520e34     PUSH       EBX
//         00520e35     PUSH       EBP
//         00520e36     MOV        EBP,this
//         00520e38     PUSH       ESI
//         00520e39     PUSH       EDI
//         00520e3a     MOV        AL,byte ptr [EBP + 0xf8]
//         00520e40     MOV        EDI,dword ptr [ESP + param_2]
//         00520e44     CMP        DL,AL
//         00520e46     JNZ        LAB_00520e8b
//         00520e48     LEA        ESI,[EBP + 0xf9]
//         00520e4e     MOV        EAX,EDI
//                               LAB_00520e50                                                 XREF[1]:     00520e6e(j)
//         00520e50     MOV        BL,byte ptr [EAX]
//         00520e52     MOV        this,BL
//         00520e54     CMP        BL,byte ptr [ESI]
//         00520e56     JNZ        LAB_00520e74
//         00520e58     TEST       this,this
//         00520e5a     JZ         LAB_00520e70
//         00520e5c     MOV        BL,byte ptr [EAX + 0x1]
//         00520e5f     MOV        this,BL
//         00520e61     CMP        BL,byte ptr [ESI + 0x1]
//         00520e64     JNZ        LAB_00520e74
//         00520e66     ADD        EAX,0x2
//         00520e69     ADD        ESI,0x2
//         00520e6c     TEST       this,this
//         00520e6e     JNZ        LAB_00520e50
//                               LAB_00520e70                                                 XREF[1]:     00520e5a(j)
//         00520e70     XOR        EAX,EAX
//         00520e72     JMP        LAB_00520e79
//                               LAB_00520e74                                                 XREF[2]:     00520e56(j), 00520e64(j)
//         00520e74     SBB        EAX,EAX
//         00520e76     SBB        EAX,-0x1
//                               LAB_00520e79                                                 XREF[1]:     00520e72(j)
//         00520e79     TEST       EAX,EAX
//         00520e7b     JNZ        LAB_00520e8b
//         00520e7d     MOV        EAX,dword ptr [ESP + param_3]
//         00520e81     MOV        this,dword ptr [EBP + 0x1c4]
//         00520e87     CMP        EAX,this
//         00520e89     JZ         LAB_00520ec8
//                               LAB_00520e8b                                                 XREF[2]:     00520e46(j), 00520e7b(j)
//                              tpnl_txl.cpp:44 (23)
//         00520e8b     OR         this,0xffffffff
//         00520e8e     XOR        EAX,EAX
//         00520e90     MOV        byte ptr [EBP + 0xf8],DL
//         00520e96     LEA        EDX,[EBP + 0xf9]
//         00520e9c     SCASB.RE   ES:EDI
//         00520e9e     NOT        this
//         00520ea0     SUB        EDI,this
//                              tpnl_txl.cpp:46 (38)
//         00520ea2     PUSH       0x1
//         00520ea4     MOV        EAX,this
//         00520ea6     MOV        ESI,EDI
//         00520ea8     MOV        EDI,EDX
//         00520eaa     MOV        EDX,dword ptr [EBP]
//         00520ead     SHR        this,0x2
//         00520eb0     MOVSD.REP  ES:EDI,ESI
//         00520eb2     MOV        this,EAX
//         00520eb4     AND        this,0x3
//         00520eb7     MOVSB.REP  ES:EDI,ESI
//         00520eb9     MOV        this,dword ptr [ESP + param_3]
//         00520ebd     MOV        dword ptr [EBP + 0x1c4],this
//         00520ec3     MOV        this,EBP
//         00520ec5     CALL       dword ptr [EDX + 0x20]
//                               LAB_00520ec8                                                 XREF[1]:     00520e89(j)
//                              tpnl_txl.cpp:47 (7)
//         00520ec8     POP        EDI
//         00520ec9     POP        ESI
//         00520eca     POP        EBP
//         00520ecb     POP        EBX
//         00520ecc     RET        0xc
//         00520ecf     ??         90h
    return;
}

void TRIBE_Panel_Text_Line::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TRIBE_Panel_Text_Line * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Te    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00520f0e(W)
//                               ?draw@TRIBE_Panel_Text_Line@@UAEXXZ                          XREF[1]:     005770f8(*)
//                               TRIBE_Panel_Text_Line::draw
//                              tpnl_txl.cpp:53 (4)
//         00520ed0     PUSH       this
//         00520ed1     PUSH       ESI
//         00520ed2     MOV        ESI,this
//                              tpnl_txl.cpp:56 (33)
//         00520ed4     MOV        EAX,dword ptr [ESI + 0x20]
//         00520ed7     TEST       EAX,EAX
//         00520ed9     JZ         LAB_00520fb6
//         00520edf     MOV        EAX,dword ptr [ESI + 0x70]
//         00520ee2     TEST       EAX,EAX
//         00520ee4     JZ         LAB_00520fb6
//         00520eea     MOV        EAX,dword ptr [ESI + 0x6c]
//         00520eed     TEST       EAX,EAX
//         00520eef     JZ         LAB_00520fb6
//                              tpnl_txl.cpp:59 (10)
//         00520ef5     MOV        this,dword ptr [ESI + 0x40]
//         00520ef8     PUSH       EDI
//         00520ef9     PUSH       EBP
//         00520efa     PUSH       EBX
//         00520efb     TEST       this,this
//         00520efd     JZ         LAB_00520f08
//                              tpnl_txl.cpp:60 (9)
//         00520eff     MOV        EAX,dword ptr [this->_padding_]
//         00520f01     LEA        EDX,[ESI + 0x24]
//         00520f04     PUSH       EDX
//         00520f05     CALL       dword ptr [EAX + 0x34]
//                               LAB_00520f08                                                 XREF[1]:     00520efd(j)
//                              tpnl_txl.cpp:62 (13)
//         00520f08     MOV        EDI,dword ptr [ESI]
//         00520f0a     PUSH       0x0
//         00520f0c     MOV        this,ESI
//         00520f0e     MOV        dword ptr [ESP + local_4],EDI
//         00520f12     CALL       dword ptr [EDI + 0x28]
//                              tpnl_txl.cpp:64 (21)
//         00520f15     MOV        this,dword ptr [ESI + 0x20]
//         00520f18     PUSH       s_tpnl_txl::draw                                 = "tpnl_txl::draw"
//         00520f1d     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         00520f22     TEST       EAX,EAX
//         00520f24     JZ         LAB_00520fae
//                              tpnl_txl.cpp:66 (24)
//         00520f2a     MOV        this,dword ptr [ESI + 0x20]
//         00520f2d     MOV        EAX,dword ptr [ESI + 0xf4]
//         00520f33     MOV        EBX,dword ptr [->GDI32.DLL::SelectObject]        = 0048b192
//         00520f39     PUSH       EAX
//         00520f3a     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520f3d     PUSH       EDX=>DAT_fffffff8
//         00520f3e     CALL       EBX=>GDI32.DLL::SelectObject
//         00520f40     MOV        EBP,EAX
//                              tpnl_txl.cpp:67 (15)
//         00520f42     MOV        EAX,dword ptr [ESI + 0x20]
//         00520f45     PUSH       0x1
//         00520f47     MOV        this,dword ptr [EAX + 0x38]
//         00520f4a     PUSH       this=>DAT_fffffff8
//         00520f4b     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_txl.cpp:68 (15)
//         00520f51     MOV        EDX,dword ptr [ESI + 0x20]
//         00520f54     PUSH       0x0
//         00520f56     MOV        EAX,dword ptr [EDX + 0x38]
//         00520f59     PUSH       EAX=>DAT_fffffff8
//         00520f5a     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_txl.cpp:70 (16)
//         00520f60     MOV        AL,byte ptr [ESI + 0xf9]
//         00520f66     LEA        EDX,[ESI + 0xf9]
//         00520f6c     TEST       AL,AL
//         00520f6e     JZ         LAB_00520f97
//                              tpnl_txl.cpp:71 (39)
//         00520f70     MOV        EDI,EDX
//         00520f72     OR         this,0xffffffff
//         00520f75     XOR        EAX,EAX
//         00520f77     SCASB.RE   ES:EDI
//         00520f79     MOV        EAX,dword ptr [ESI + 0x20]
//         00520f7c     NOT        this
//         00520f7e     DEC        this
//         00520f7f     PUSH       this
//         00520f80     MOV        this,dword ptr [ESI + 0x10]
//         00520f83     PUSH       EDX=>DAT_fffffff8
//         00520f84     MOV        EDX,dword ptr [ESI + 0xc]
//         00520f87     PUSH       this=>DAT_fffffff4
//         00520f88     MOV        this,dword ptr [EAX + 0x38]
//         00520f8b     PUSH       EDX=>DAT_fffffff0
//         00520f8c     PUSH       this
//         00520f8d     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//         00520f93     MOV        EDI,dword ptr [ESP + 0x10]
//                               LAB_00520f97                                                 XREF[1]:     00520f6e(j)
//                              tpnl_txl.cpp:73 (10)
//         00520f97     MOV        EDX,dword ptr [ESI + 0x20]
//         00520f9a     PUSH       EBP
//         00520f9b     MOV        EAX,dword ptr [EDX + 0x38]
//         00520f9e     PUSH       EAX=>DAT_fffffff8
//         00520f9f     CALL       EBX=>GDI32.DLL::SelectObject
//                              tpnl_txl.cpp:75 (13)
//         00520fa1     MOV        this,dword ptr [ESI + 0x20]
//         00520fa4     PUSH       s_tpnl_txl::draw                                 = "tpnl_txl::draw"
//         00520fa9     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                               LAB_00520fae                                                 XREF[1]:     00520f24(j)
//                              tpnl_txl.cpp:78 (8)
//         00520fae     MOV        this,ESI
//         00520fb0     CALL       dword ptr [EDI + 0x2c]
//         00520fb3     POP        EBX
//         00520fb4     POP        EBP
//         00520fb5     POP        EDI
//                               LAB_00520fb6                                                 XREF[3]:     00520ed9(j), 00520ee4(j),
//                                                                                                         00520eef(j)
//                              tpnl_txl.cpp:79 (3)
//         00520fb6     POP        ESI
//         00520fb7     POP        this
//         00520fb8     RET
//         00520fb9     ??         90h
//         00520fba     NOP
//         00520fbb     NOP
//         00520fbc     NOP
//         00520fbd     NOP
//         00520fbe     NOP
//         00520fbf     NOP
    return;
}

TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Panel_Text_Line(TRIBE_Panel_Text_Line * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Te    ECX:4 (auto)   this
//                               ??1TRIBE_Panel_Text_Line@@UAE@XZ                             XREF[1]:     `scalar_deleting_destructor':00520
//                               TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line
//         00520e20     JMP        TPanel::~TPanel
//         00520e25     ??         90h
//         00520e26     NOP
//         00520e27     NOP
//         00520e28     NOP
//         00520e29     NOP
//         00520e2a     NOP
//         00520e2b     NOP
//         00520e2c     NOP
//         00520e2d     NOP
//         00520e2e     NOP
//         00520e2f     NOP
}

